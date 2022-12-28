/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF552.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF552.H"
#include "FHCANF552_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_552(void)
{
	ISCAN_u32N20F552P255 = 0;
	ISCAN_u16N12F552P256 = 0;
	ISCAN_u8N8F552P257 = 0;
	ISCAN_u32N32F552P325 = 42949672930;
	ISCAN_u8N8F552P326 = 253;

	VEMS_vidSET(Ext_ctSecCAN, 0);
	VEMS_vidSET(Ext_ctDayCAN, 0);
	VEMS_vidSET(Ext_ctYrCAN, 0);
	VEMS_vidSET(Ext_tiCurVehTmr, 4294967293);
	VEMS_vidSET(Ext_bNotAvl_tiCurVehTmr, AVAILABLE);
	VEMS_vidSET(Ext_CtRstCurVehTmr, 253);
	VEMS_vidSET(Ext_bNotAvl_CtRstCurVehTmr, AVAILABLE);

	Ext_bMonRunMissF552 = FHCAN_DISABLE;
	Ext_bMonRunShoF552 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF552P255 = FHCAN_DISABLE;
	Ext_bMonRunInvldF552P255 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF552P256 = FHCAN_DISABLE;
	Ext_bMonRunInvldF552P256 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF552P257 = FHCAN_DISABLE;
	Ext_bMonRunInvldF552P257 = FHCAN_DISABLE;
	Ext_bMonRunInvldF552P325 = FHCAN_DISABLE;
	Ext_bMonRunInvldF552P015 = FHCAN_DISABLE;
	Ext_bMonRunInvldF552P326 = FHCAN_DISABLE;

	Ext_bDgoMissF552 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF552 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF552P255 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF552P255 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF552P256 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF552P256 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF552P257 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF552P257 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF552P325 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF552P015 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF552P326 = FHCAN_NOT_DETECTED;
}

void FHCAN_BSI_552_vidFrameReceived(void)
{
	boolean Local_bCtrl_BSI_552;
	boolean Local_bCtrl_ctSecCAN;
	boolean Local_bCtrl_ctDayCAN;
	boolean Local_bCtrl_ctYrCAN;

	VEMS_vidGET(Ctrl_BSI_552, Local_bCtrl_BSI_552);
	if (ACTIVATED == Local_bCtrl_BSI_552)
	{
		ISCAN_EveRxn_BSI_552();
		FHCAN552_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF552)
      {
         Ext_bDgoMissF552 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF552,
                  Ext_bDgoMissF552,
                  Ext_bMonRunMissF552,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_ctSecCAN, Local_bCtrl_ctSecCAN);
      Com_ReceiveSignal(Com_CMM552DATA1_BSI_552, (void*) &iscan_u8552Data1);
      Com_ReceiveSignal(Com_CMM552DATA2_BSI_552, (void*) &iscan_u8552Data2);
      Com_ReceiveSignal(Com_CMM552DATA3_BSI_552, (void*) &iscan_u8552Data3);
		if (ACTIVATED == Local_bCtrl_ctSecCAN)
		{
			FHCAN552_vidCalcMonFP255Window();
         ISCAN_u32N20F552P255    = (uint32)(    ((iscan_u8552Data1) << 12)   | (iscan_u8552Data2 << 4)   | (iscan_u8552Data3 >> 4));
			FHCAN552_vidMonInvldP255Update();
			FHCAN552_vidMonFrbdP255Update();

			FHCANF552_vidUpdateSignalP255();
		}
		else
		{
			VEMS_vidSET(Ext_ctSecCAN, 0);

			Ext_bMonRunFrbdF552P255 = FHCAN_DISABLE;
			Ext_bMonRunInvldF552P255 = FHCAN_DISABLE;
			Ext_bDgoFrbdF552P255 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF552P255 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_ctDayCAN, Local_bCtrl_ctDayCAN);
      Com_ReceiveSignal(Com_CMM552DATA3_BSI_552, (void*) &iscan_u8552Data3);
      Com_ReceiveSignal(Com_CMM552DATA4_BSI_552, (void*) &iscan_u8552Data4);
		if (ACTIVATED == Local_bCtrl_ctDayCAN)
		{
			FHCAN552_vidCalcMonFP256Window();
         ISCAN_u16N12F552P256 = (uint16)(    ((iscan_u8552Data3 & 15) << 8)   | (iscan_u8552Data4));
			FHCAN552_vidMonInvldP256Update();
			FHCAN552_vidMonFrbdP256Update();

			FHCANF552_vidUpdateSignalP256();
		}
		else
		{
			VEMS_vidSET(Ext_ctDayCAN, 0);

			Ext_bMonRunFrbdF552P256 = FHCAN_DISABLE;
			Ext_bMonRunInvldF552P256 = FHCAN_DISABLE;
			Ext_bDgoFrbdF552P256 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF552P256 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_ctYrCAN, Local_bCtrl_ctYrCAN);
      Com_ReceiveSignal(Com_CMM552DATA5_BSI_552, (void*) &iscan_u8552Data5);
		if (ACTIVATED == Local_bCtrl_ctYrCAN)
		{
			FHCAN552_vidCalcMonFP257Window();
         ISCAN_u8N8F552P257    = (uint8)(   (iscan_u8552Data5));
			FHCAN552_vidMonInvldP257Update();
			FHCAN552_vidMonFrbdP257Update();

			FHCANF552_vidUpdateSignalP257();
		}
		else
		{
			VEMS_vidSET(Ext_ctYrCAN, 0);

			Ext_bMonRunFrbdF552P257 = FHCAN_DISABLE;
			Ext_bMonRunInvldF552P257 = FHCAN_DISABLE;
			Ext_bDgoFrbdF552P257 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF552P257 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF552 = FHCAN_DISABLE;
		Ext_bMonRunShoF552 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF552P255 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P255 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF552P256 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P256 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF552P257 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P257 = FHCAN_DISABLE;

		Ext_bDgoMissF552 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF552 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF552P255 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P255 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF552P256 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P256 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF552P257 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P257 = FHCAN_NOT_DETECTED;
	}
}


void FHCAN_V2_BSI_552_vidFrameReceived(void)
{
	boolean Local_bCtrl_V2_BSI_552;
	boolean Local_bCtrl_tiCurVehTmr;
	boolean Local_bCtrl_bAcv_dstVehTotMesIS552;
	boolean Local_bCtrl_CtRstCurVehTmr;

	VEMS_vidGET(Ctrl_V2_BSI_552, Local_bCtrl_V2_BSI_552);
	if (ACTIVATED == Local_bCtrl_V2_BSI_552)
	{
		ISCAN_EveRxn_V2_BSI_552();
		FHCAN552_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF552)
      {
         Ext_bDgoMissF552 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF552,
                  Ext_bDgoMissF552,
                  Ext_bMonRunMissF552,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_tiCurVehTmr, Local_bCtrl_tiCurVehTmr);
      Com_ReceiveSignal(Com_CMM552DATA1_V2_BSI_552, (void*) &iscan_u8552Data1);
      Com_ReceiveSignal(Com_CMM552DATA2_V2_BSI_552, (void*) &iscan_u8552Data2);
      Com_ReceiveSignal(Com_CMM552DATA3_V2_BSI_552, (void*) &iscan_u8552Data3);
      Com_ReceiveSignal(Com_CMM552DATA4_V2_BSI_552, (void*) &iscan_u8552Data4);
		if (ACTIVATED == Local_bCtrl_tiCurVehTmr)
		{
			FHCAN552_vidCalcMonFP325Window();
         ISCAN_u32N32F552P325    = (uint32)(    ((iscan_u8552Data1) << 24)   | (iscan_u8552Data2 << 16)   | (iscan_u8552Data3 << 8)   | (iscan_u8552Data4));
			FHCAN552_vidMonInvldP325Update();

			FHCANF552_vidUpdateSignalP325();
		}
		else
		{
			VEMS_vidSET(Ext_tiCurVehTmr, 4294967293);
			VEMS_vidSET(Ext_bNotAvl_tiCurVehTmr, AVAILABLE);
			Ext_bMonRunInvldF552P325 = FHCAN_DISABLE;
			Ext_bDgoInvldF552P325 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bAcv_dstVehTotMesIS552, Local_bCtrl_bAcv_dstVehTotMesIS552);
      Com_ReceiveSignal(Com_CMM552DATA5_V2_BSI_552, (void*) &iscan_u8552Data5);
      Com_ReceiveSignal(Com_CMM552DATA6_V2_BSI_552, (void*) &iscan_u8552Data6);
      Com_ReceiveSignal(Com_CMM552DATA7_V2_BSI_552, (void*) &iscan_u8552Data7);
		if (ACTIVATED == Local_bCtrl_bAcv_dstVehTotMesIS552)
		{
			FHCAN552_vidCalcMonFP015Window();
         ISCAN_u32N24F552P015    = (uint32)(    ((iscan_u8552Data5) << 16)   | (iscan_u8552Data6 << 8)   | (iscan_u8552Data7));
			FHCAN552_vidMonInvldP015Update();

			FHCANF552_vidUpdateSignalP015();
		}
		else
		{

			Ext_bMonRunInvldF552P015 = FHCAN_DISABLE;
			Ext_bDgoInvldF552P015 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_CtRstCurVehTmr, Local_bCtrl_CtRstCurVehTmr);
      Com_ReceiveSignal(Com_CMM552DATA8_V2_BSI_552, (void*) &iscan_u8552Data8);
		if (ACTIVATED == Local_bCtrl_CtRstCurVehTmr)
		{
			FHCAN552_vidCalcMonFP326Window();
         ISCAN_u8N8F552P326    = (uint8)(   (iscan_u8552Data8));
			FHCAN552_vidMonInvldP326Update();

			FHCANF552_vidUpdateSignalP326();
		}
		else
		{
			VEMS_vidSET(Ext_CtRstCurVehTmr, 253);
			VEMS_vidSET(Ext_bNotAvl_CtRstCurVehTmr, AVAILABLE);
			Ext_bMonRunInvldF552P326 = FHCAN_DISABLE;
			Ext_bDgoInvldF552P326 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF552 = FHCAN_DISABLE;
		Ext_bMonRunShoF552 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P325 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P015 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P326 = FHCAN_DISABLE;

		Ext_bDgoMissF552 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF552 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P325 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P015 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P326 = FHCAN_NOT_DETECTED;
	}
}



void FHCAN_BSI_552_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF552P255_in;
	boolean FRM_bAcvRcvF552P256_in;
	boolean FRM_bAcvRcvF552P257_in;
	boolean FRM_bAcvRcvF552_in;
	boolean Local_bCtrl_BSI_552;
	boolean Local_bCtrl_ctSecCAN;
	boolean Local_bCtrl_ctDayCAN;
	boolean Local_bCtrl_ctYrCAN;
	uint32 Local_Ext_ctSecCAN;
	uint16 Local_Ext_ctDayCAN;
	uint8 Local_Ext_ctYrCAN;


	VEMS_vidGET(Ctrl_BSI_552, Local_bCtrl_BSI_552);
	if (ACTIVATED == Local_bCtrl_BSI_552)
	{
		FHCAN552_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF552)
      {
         Ext_bDgoMissF552 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF552,
                  Ext_bDgoMissF552,
                  Ext_bMonRunMissF552,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_ctSecCAN, 0);
		   VEMS_vidSET(Ext_ctDayCAN, 0);
		   VEMS_vidSET(Ext_ctYrCAN, 0);
      }

		FRM_bAcvRcvF552P255_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P255);
		FRM_bAcvRcvF552P256_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P256);
		FRM_bAcvRcvF552P257_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P257);
		FRM_bAcvRcvF552_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552);

		VEMS_vidGET(Ctrl_ctSecCAN, Local_bCtrl_ctSecCAN);
		if (ACTIVATED == Local_bCtrl_ctSecCAN)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF552P255_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
			{
		      VEMS_vidGET(Ext_ctSecCAN, Local_Ext_ctSecCAN);
		      VEMS_vidSET(Ext_ctSecCAN, Local_Ext_ctSecCAN);
			}
		}
		VEMS_vidGET(Ctrl_ctDayCAN, Local_bCtrl_ctDayCAN);
		if (ACTIVATED == Local_bCtrl_ctDayCAN)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF552P256_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
			{
		      VEMS_vidGET(Ext_ctDayCAN, Local_Ext_ctDayCAN);
		      VEMS_vidSET(Ext_ctDayCAN, Local_Ext_ctDayCAN);
			}
		}
		VEMS_vidGET(Ctrl_ctYrCAN, Local_bCtrl_ctYrCAN);
		if (ACTIVATED == Local_bCtrl_ctYrCAN)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF552P257_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
			{
		      VEMS_vidGET(Ext_ctYrCAN, Local_Ext_ctYrCAN);
		      VEMS_vidSET(Ext_ctYrCAN, Local_Ext_ctYrCAN);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF552 = FHCAN_DISABLE;
		Ext_bMonRunShoF552 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF552P255 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P255 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF552P256 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P256 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF552P257 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P257 = FHCAN_DISABLE;

		Ext_bDgoMissF552 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF552 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF552P255 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P255 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF552P256 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P256 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF552P257 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P257 = FHCAN_NOT_DETECTED;
	}
}

void FHCAN_V2_BSI_552_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF552P325_in;
	boolean FRM_bAcvRcvF552P015_in;
	boolean FRM_bAcvRcvF552P326_in;
	boolean FRM_bAcvRcvF552_in;
	boolean Local_bCtrl_V2_BSI_552;
	boolean Local_bCtrl_tiCurVehTmr;
	boolean Local_bCtrl_bAcv_dstVehTotMesIS552;
	boolean Local_bCtrl_CtRstCurVehTmr;
	uint32 Local_Ext_tiCurVehTmr;
	uint32 Local_Km_vehicle_mux_552h;


	VEMS_vidGET(Ctrl_V2_BSI_552, Local_bCtrl_V2_BSI_552);
	if (ACTIVATED == Local_bCtrl_V2_BSI_552)
	{
		FHCAN552_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF552)
      {
         Ext_bDgoMissF552 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF552,
                  Ext_bDgoMissF552,
                  Ext_bMonRunMissF552,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_tiCurVehTmr, 4294967293);
		   VEMS_vidSET(Ext_bNotAvl_tiCurVehTmr, AVAILABLE);
		   VEMS_vidSET(Ext_CtRstCurVehTmr, 253);
		   VEMS_vidSET(Ext_bNotAvl_CtRstCurVehTmr, AVAILABLE);
      }

		FRM_bAcvRcvF552P325_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P325);
		FRM_bAcvRcvF552P015_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P015);
		FRM_bAcvRcvF552P326_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P326);
		FRM_bAcvRcvF552_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552);

		VEMS_vidGET(Ctrl_tiCurVehTmr, Local_bCtrl_tiCurVehTmr);
		if (ACTIVATED == Local_bCtrl_tiCurVehTmr)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF552P325_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
			{
		      VEMS_vidGET(Ext_tiCurVehTmr, Local_Ext_tiCurVehTmr);
		      VEMS_vidSET(Ext_tiCurVehTmr, Local_Ext_tiCurVehTmr);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_dstVehTotMesIS552, Local_bCtrl_bAcv_dstVehTotMesIS552);
		if (ACTIVATED == Local_bCtrl_bAcv_dstVehTotMesIS552)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF552P015_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
			{
		      VEMS_vidGET(Km_vehicle_mux_552h, Local_Km_vehicle_mux_552h);
		      VEMS_vidSET(Km_vehicle_mux_552h, Local_Km_vehicle_mux_552h);
			}
		}
		VEMS_vidGET(Ctrl_CtRstCurVehTmr, Local_bCtrl_CtRstCurVehTmr);
		if (ACTIVATED == Local_bCtrl_CtRstCurVehTmr)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF552P326_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
			{
		      VEMS_vidSET(Ext_CtRstCurVehTmr, Ext_CtRstCurVehTmrRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF552 = FHCAN_DISABLE;
		Ext_bMonRunShoF552 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P325 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P015 = FHCAN_DISABLE;
		Ext_bMonRunInvldF552P326 = FHCAN_DISABLE;

		Ext_bDgoMissF552 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF552 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P325 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P015 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF552P326 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF552_vidUpdateSignalP255(void)
{
	boolean FRM_bAcvRcvF552P255_in;
	boolean FRM_bAcvRcvF552_in;
   uint32 u32LocalExt_ctSecCAN;

	uint32 Local_Ext_ctSecCAN;

	FRM_bAcvRcvF552P255_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P255);
	FRM_bAcvRcvF552_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF552P255_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF552_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF552P255)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF552P255)
	   && (FHCAN_DETECTED != Ext_bDgoShoF552)
	   )
	{
      u32LocalExt_ctSecCAN = (uint32)(MATHSRV_udtMIN(ISCAN_u32N20F552P255,
                                             586639));
      VEMS_vidSET(Ext_ctSecCAN,
                  u32LocalExt_ctSecCAN);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF552P255_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
      {
			VEMS_vidGET(Ext_ctSecCAN, Local_Ext_ctSecCAN);
			VEMS_vidSET(Ext_ctSecCAN, Local_Ext_ctSecCAN);
		}
	}
}

void FHCANF552_vidUpdateSignalP256(void)
{
	boolean FRM_bAcvRcvF552P256_in;
	boolean FRM_bAcvRcvF552_in;
   uint16 u16LocalExt_ctDayCAN;

	uint16 Local_Ext_ctDayCAN;

	FRM_bAcvRcvF552P256_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P256);
	FRM_bAcvRcvF552_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF552P256_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF552_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF552P256)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF552P256)
	   && (FHCAN_DETECTED != Ext_bDgoShoF552)
	   )
	{
      u16LocalExt_ctDayCAN = (uint16)(MATHSRV_udtMIN(ISCAN_u16N12F552P256,
                                             365));
      VEMS_vidSET(Ext_ctDayCAN,
                  u16LocalExt_ctDayCAN);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF552P256_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
      {
			VEMS_vidGET(Ext_ctDayCAN, Local_Ext_ctDayCAN);
			VEMS_vidSET(Ext_ctDayCAN, Local_Ext_ctDayCAN);
		}
	}
}

void FHCANF552_vidUpdateSignalP257(void)
{
	boolean FRM_bAcvRcvF552P257_in;
	boolean FRM_bAcvRcvF552_in;
   uint8 u8LocalExt_ctYrCAN;

	uint8 Local_Ext_ctYrCAN;

	FRM_bAcvRcvF552P257_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P257);
	FRM_bAcvRcvF552_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF552P257_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF552_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF552P257)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF552P257)
	   && (FHCAN_DETECTED != Ext_bDgoShoF552)
	   )
	{
      u8LocalExt_ctYrCAN = (uint8)(MATHSRV_udtMIN(ISCAN_u8N8F552P257,
                                             100));
      VEMS_vidSET(Ext_ctYrCAN,
                  u8LocalExt_ctYrCAN);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF552P257_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
      {
			VEMS_vidGET(Ext_ctYrCAN, Local_Ext_ctYrCAN);
			VEMS_vidSET(Ext_ctYrCAN, Local_Ext_ctYrCAN);
		}
	}
}

void FHCANF552_vidUpdateSignalP325(void)
{
	boolean FRM_bAcvRcvF552P325_in;
	boolean FRM_bAcvRcvF552_in;
   uint32 u32LocalIscanV2_BSI_552;
   uint32 u32LocalExt_tiCurVehTmr;

	uint32 Local_Ext_tiCurVehTmr;

   if (ISCAN_u32N32F552P325 == 4294967294)
	{
		VEMS_vidSET(Ext_bNotAvl_tiCurVehTmr, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_tiCurVehTmr, AVAILABLE);
	}

	FRM_bAcvRcvF552P325_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P325);
	FRM_bAcvRcvF552_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF552P325_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF552_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF552P325)
	   && (FHCAN_DETECTED != Ext_bDgoShoF552)
	   )
	{
   
      if((UINT32_MAX / 1) < ISCAN_u32N32F552P325)
      {
         u32LocalIscanV2_BSI_552 = (uint32)(((ISCAN_u32N32F552P325) / (10/UINT16_MAX)));
      }
      else
      {
         u32LocalIscanV2_BSI_552 = (uint32)(((ISCAN_u32N32F552P325) / 10));
      }
   
      u32LocalExt_tiCurVehTmr = (uint32)(MATHSRV_udtMIN(u32LocalIscanV2_BSI_552,
                                             4294967293));
      VEMS_vidSET(Ext_tiCurVehTmr,
                  u32LocalExt_tiCurVehTmr);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF552P325_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
      {
			VEMS_vidGET(Ext_tiCurVehTmr, Local_Ext_tiCurVehTmr);
			VEMS_vidSET(Ext_tiCurVehTmr, Local_Ext_tiCurVehTmr);
		}
	}
}

void FHCANF552_vidUpdateSignalP015(void)
{
	boolean FRM_bAcvRcvF552P015_in;
	boolean FRM_bAcvRcvF552_in;
   uint32 u32LocalKm_vehicle_mux_552h;

	uint32 Local_Km_vehicle_mux_552h;

	FRM_bAcvRcvF552P015_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P015);
	FRM_bAcvRcvF552_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF552P015_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF552_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF552P015)
	   && (FHCAN_DETECTED != Ext_bDgoShoF552)
	   )
	{
      u32LocalKm_vehicle_mux_552h = (uint32)(MATHSRV_udtMIN(ISCAN_u32N24F552P015,
                                             16777214));
      VEMS_vidSET(Km_vehicle_mux_552h,
                  u32LocalKm_vehicle_mux_552h);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF552P015_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
      {
			VEMS_vidGET(Km_vehicle_mux_552h, Local_Km_vehicle_mux_552h);
			VEMS_vidSET(Km_vehicle_mux_552h, Local_Km_vehicle_mux_552h);
		}
	}
}

void FHCANF552_vidUpdateSignalP326(void)
{
	boolean FRM_bAcvRcvF552P326_in;
	boolean FRM_bAcvRcvF552_in;
   uint8 u8LocalExt_CtRstCurVehTmr;

   if (ISCAN_u8N8F552P326 == 254)
	{
		VEMS_vidSET(Ext_bNotAvl_CtRstCurVehTmr, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_CtRstCurVehTmr, AVAILABLE);
	}

	FRM_bAcvRcvF552P326_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552P326);
	FRM_bAcvRcvF552_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF552);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF552P326_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF552_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF552P326)
	   && (FHCAN_DETECTED != Ext_bDgoShoF552)
	   )
	{
      u8LocalExt_CtRstCurVehTmr = (uint8)(MATHSRV_udtMIN(ISCAN_u8N8F552P326,
                                             253));
      VEMS_vidSET(Ext_CtRstCurVehTmr,
                  u8LocalExt_CtRstCurVehTmr);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF552P326_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF552_in))
      {
			VEMS_vidSET(Ext_CtRstCurVehTmr, Ext_CtRstCurVehTmrRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

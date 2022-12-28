/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF7F2.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF7F2.H"
#include "FHCANF7F2_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_7F2(void)
{
	ISCAN_u8N8F7F2P849 = 0;
	ISCAN_u8N8F7F2P146 = 120;
	ISCAN_u8N8F7F2P301 = 0;

	VEMS_vidSET(Ext_noDiag, 0);
	VEMS_vidSET(Ext_tAirSideMirrMes_7F2h, 40);
	VEMS_vidSET(Ext_bNotAvl_tAirExtMes, AVAILABLE);
	VEMS_vidSET(CoRegVeh_stDftOBD, 0);

	Ext_bMonRunMissF7F2 = FHCAN_DISABLE;
	Ext_bMonRunShoF7F2 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF7F2P849 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF7F2P146 = FHCAN_DISABLE;
	Ext_bMonRunInvldF7F2P146 = FHCAN_DISABLE;
	Ext_bMonRunInvldF7F2P015 = FHCAN_DISABLE;

	Ext_bDgoMissF7F2 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF7F2 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF7F2P849 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF7F2P146 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF7F2P146 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF7F2P015 = FHCAN_NOT_DETECTED;
}

void FHCANF7F2_vidFrameReceived(void)
{
	boolean Local_bCtrl_CONTEXTE_1_7F2;
	boolean Local_bCtrl_noDiag;
	boolean Local_bCtrl_tAirExtMes;
	boolean Local_bCtrl_bAcv_dstVehTotMesIS7F2;
	boolean Local_bCtrl_bAcv_stDftOBDIS7F2;

	VEMS_vidGET(Ctrl_CONTEXTE_1_7F2, Local_bCtrl_CONTEXTE_1_7F2);
	if (ACTIVATED == Local_bCtrl_CONTEXTE_1_7F2)
	{
		ISCAN_EveRxn_7F2();
		FHCAN7F2_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF7F2)
      {
         Ext_bDgoMissF7F2 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF7F2,
                  Ext_bDgoMissF7F2,
                  Ext_bMonRunMissF7F2,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_noDiag, Local_bCtrl_noDiag);
		if (ACTIVATED == Local_bCtrl_noDiag)
		{
			FHCAN7F2_vidCalcMonFP849Window();
			Com_ReceiveSignal(Com_CODE_DIAGNOSTIC_CONTEXTE_1_7F2, (void*) &ISCAN_u8N8F7F2P849);

			FHCAN7F2_vidMonFrbdP849Update();

			FHCANF7F2_vidUpdateSignalP849();
		}
		else
		{
			VEMS_vidSET(Ext_noDiag, 0);

			Ext_bMonRunFrbdF7F2P849 = FHCAN_DISABLE;
			Ext_bDgoFrbdF7F2P849 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_tAirExtMes, Local_bCtrl_tAirExtMes);
      Com_ReceiveSignal(Com_CMM7F2DATA4_CONTEXTE_1_7F2, (void*) &iscan_u87F2Data4);
		if (ACTIVATED == Local_bCtrl_tAirExtMes)
		{
			if (ISCAN_u8N8F7F2P849 == 0x8D)
         {
   			FHCAN7F2_vidCalcMonFP146Window();
            ISCAN_u8N8F7F2P146    = (uint8)(   (iscan_u87F2Data4));
   			FHCAN7F2_vidMonInvldP146Update();
   			FHCAN7F2_vidMonFrbdP146Update();

   			FHCANF7F2_vidUpdateSignalP146();
         }
		}
		else
		{
			VEMS_vidSET(Ext_tAirSideMirrMes_7F2h, 40);
			VEMS_vidSET(Ext_bNotAvl_tAirExtMes, AVAILABLE);
			Ext_bMonRunFrbdF7F2P146 = FHCAN_DISABLE;
			Ext_bMonRunInvldF7F2P146 = FHCAN_DISABLE;
			Ext_bDgoFrbdF7F2P146 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF7F2P146 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bAcv_dstVehTotMesIS7F2, Local_bCtrl_bAcv_dstVehTotMesIS7F2);
      Com_ReceiveSignal(Com_CMM7F2DATA4_CONTEXTE_1_7F2, (void*) &iscan_u87F2Data4);
      Com_ReceiveSignal(Com_CMM7F2DATA5_CONTEXTE_1_7F2, (void*) &iscan_u87F2Data5);
      Com_ReceiveSignal(Com_CMM7F2DATA6_CONTEXTE_1_7F2, (void*) &iscan_u87F2Data6);
		if (ACTIVATED == Local_bCtrl_bAcv_dstVehTotMesIS7F2)
		{
			if (ISCAN_u8N8F7F2P849 == 0x8F)
         {
   			FHCAN7F2_vidCalcMonFP015Window();
            ISCAN_u32N24F7F2P015    = (uint32)(    ((iscan_u87F2Data4) << 16)   | (iscan_u87F2Data5 << 8)   | (iscan_u87F2Data6));
   			FHCAN7F2_vidMonInvldP015Update();

   			FHCANF7F2_vidUpdateSignalP015();
         }
		}
		else
		{

			Ext_bMonRunInvldF7F2P015 = FHCAN_DISABLE;
			Ext_bDgoInvldF7F2P015 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bAcv_stDftOBDIS7F2, Local_bCtrl_bAcv_stDftOBDIS7F2);
		if (ACTIVATED == Local_bCtrl_bAcv_stDftOBDIS7F2)
		{
			if (ISCAN_u8N8F7F2P849 == 0x8E)
         {
   			Com_ReceiveSignal(Com_ETAT_INFO_EOBD_BSI_CONTEXTE_1_7F2, (void*) &ISCAN_u8N8F7F2P301);


   			FHCANF7F2_vidUpdateSignalP301();
         }
		}
		else
		{
			VEMS_vidSET(CoRegVeh_stDftOBD, 0);

		}
	}
	else
	{
		Ext_bMonRunMissF7F2 = FHCAN_DISABLE;
		Ext_bMonRunShoF7F2 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF7F2P849 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF7F2P146 = FHCAN_DISABLE;
		Ext_bMonRunInvldF7F2P146 = FHCAN_DISABLE;
		Ext_bMonRunInvldF7F2P015 = FHCAN_DISABLE;

		Ext_bDgoMissF7F2 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF7F2 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF7F2P849 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF7F2P146 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF7F2P146 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF7F2P015 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF7F2_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF7F2P849_in;
	boolean FRM_bAcvRcvF7F2P146_in;
	boolean FRM_bAcvRcvF7F2P015_in;
	boolean FRM_bAcvRcvF7F2_in;
	boolean Local_bCtrl_CONTEXTE_1_7F2;
	boolean Local_bCtrl_noDiag;
	boolean Local_bCtrl_tAirExtMes;
	boolean Local_bCtrl_bAcv_dstVehTotMesIS7F2;
	boolean Local_bCtrl_bAcv_stDftOBDIS7F2;
	uint8 Local_Ext_noDiag;
	uint32 Local_Km_vehicle_mux_7F2h;
	uint8 Local_CoRegVeh_stDftOBD;


	VEMS_vidGET(Ctrl_CONTEXTE_1_7F2, Local_bCtrl_CONTEXTE_1_7F2);
	if (ACTIVATED == Local_bCtrl_CONTEXTE_1_7F2)
	{
		FHCAN7F2_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF7F2)
      {
         Ext_bDgoMissF7F2 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF7F2,
                  Ext_bDgoMissF7F2,
                  Ext_bMonRunMissF7F2,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_noDiag, 0);
		   VEMS_vidSET(Ext_tAirSideMirrMes_7F2h, 40);
		   VEMS_vidSET(Ext_bNotAvl_tAirExtMes, AVAILABLE);
		   VEMS_vidSET(CoRegVeh_stDftOBD, 0);
      }

		FRM_bAcvRcvF7F2P849_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF7F2P849);
		FRM_bAcvRcvF7F2P146_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF7F2P146);
		FRM_bAcvRcvF7F2P015_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF7F2P015);
		FRM_bAcvRcvF7F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF7F2);

		VEMS_vidGET(Ctrl_noDiag, Local_bCtrl_noDiag);
		if (ACTIVATED == Local_bCtrl_noDiag)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF7F2P849_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF7F2_in))
			{
		      VEMS_vidGET(Ext_noDiag, Local_Ext_noDiag);
		      VEMS_vidSET(Ext_noDiag, Local_Ext_noDiag);
			}
		}
		VEMS_vidGET(Ctrl_tAirExtMes, Local_bCtrl_tAirExtMes);
		if (ACTIVATED == Local_bCtrl_tAirExtMes)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF7F2P146_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF7F2_in))
			{
		      VEMS_vidSET(Ext_tAirSideMirrMes_7F2h, Ext_tAirExtMesRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_dstVehTotMesIS7F2, Local_bCtrl_bAcv_dstVehTotMesIS7F2);
		if (ACTIVATED == Local_bCtrl_bAcv_dstVehTotMesIS7F2)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF7F2P015_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF7F2_in))
			{
		      VEMS_vidGET(Km_vehicle_mux_7F2h, Local_Km_vehicle_mux_7F2h);
		      VEMS_vidSET(Km_vehicle_mux_7F2h, Local_Km_vehicle_mux_7F2h);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_stDftOBDIS7F2, Local_bCtrl_bAcv_stDftOBDIS7F2);
		if (ACTIVATED == Local_bCtrl_bAcv_stDftOBDIS7F2)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF7F2_in)
			{
		      VEMS_vidGET(CoRegVeh_stDftOBD, Local_CoRegVeh_stDftOBD);
		      VEMS_vidSET(CoRegVeh_stDftOBD, Local_CoRegVeh_stDftOBD);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF7F2 = FHCAN_DISABLE;
		Ext_bMonRunShoF7F2 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF7F2P849 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF7F2P146 = FHCAN_DISABLE;
		Ext_bMonRunInvldF7F2P146 = FHCAN_DISABLE;
		Ext_bMonRunInvldF7F2P015 = FHCAN_DISABLE;

		Ext_bDgoMissF7F2 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF7F2 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF7F2P849 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF7F2P146 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF7F2P146 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF7F2P015 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF7F2_vidUpdateSignalP849(void)
{
	boolean FRM_bAcvRcvF7F2P849_in;
	boolean FRM_bAcvRcvF7F2_in;
   uint8 u8LocalExt_noDiag;

	uint8 Local_Ext_noDiag;

	FRM_bAcvRcvF7F2P849_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF7F2P849);
	FRM_bAcvRcvF7F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF7F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF7F2P849_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF7F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF7F2P849)
	   && (FHCAN_DETECTED != Ext_bDgoShoF7F2)
	   && (FHCAN_DETECTED != Ext_bDgoLIDF7F2)
	   )
	{
      u8LocalExt_noDiag = ISCAN_u8N8F7F2P849;
      VEMS_vidSET(Ext_noDiag,
                  u8LocalExt_noDiag);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF7F2P849_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF7F2_in))
      {
			VEMS_vidGET(Ext_noDiag, Local_Ext_noDiag);
			VEMS_vidSET(Ext_noDiag, Local_Ext_noDiag);
		}
	}
}

void FHCANF7F2_vidUpdateSignalP146(void)
{
	boolean FRM_bAcvRcvF7F2P146_in;
	boolean FRM_bAcvRcvF7F2_in;
   sint16 s16LocalIscanCONTEXTE_1_7F2;
   sint16 s16LocalExt_tAirSideMirrMes_7F2h;

   if ((ISCAN_u8N8F7F2P146 == 252) || (ISCAN_u8N8F7F2P146 == 253))

	{
		VEMS_vidSET(Ext_bNotAvl_tAirExtMes, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_tAirExtMes, AVAILABLE);
	}

	FRM_bAcvRcvF7F2P146_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF7F2P146);
	FRM_bAcvRcvF7F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF7F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF7F2P146_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF7F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF7F2P146)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF7F2P146)
	   && (FHCAN_DETECTED != Ext_bDgoShoF7F2)
	   && (FHCAN_DETECTED != Ext_bDgoLIDF7F2)
	   )
	{
      s16LocalIscanCONTEXTE_1_7F2 = (sint16)((ISCAN_u8N8F7F2P146) - 80);
      s16LocalExt_tAirSideMirrMes_7F2h = (sint16)(MATHSRV_udtCLAMP(s16LocalIscanCONTEXTE_1_7F2,
                                               -80,
                                               174));
      VEMS_vidSET(Ext_tAirSideMirrMes_7F2h,
                  s16LocalExt_tAirSideMirrMes_7F2h);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF7F2P146_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF7F2_in))
      {
			VEMS_vidSET(Ext_tAirSideMirrMes_7F2h, Ext_tAirExtMesRcf_C);
		}
	}
}

void FHCANF7F2_vidUpdateSignalP015(void)
{
	boolean FRM_bAcvRcvF7F2P015_in;
	boolean FRM_bAcvRcvF7F2_in;
   uint32 u32LocalKm_vehicle_mux_7F2h;

	uint32 Local_Km_vehicle_mux_7F2h;

	FRM_bAcvRcvF7F2P015_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF7F2P015);
	FRM_bAcvRcvF7F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF7F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF7F2P015_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF7F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF7F2P015)
	   && (FHCAN_DETECTED != Ext_bDgoShoF7F2)
	   && (FHCAN_DETECTED != Ext_bDgoLIDF7F2)
	   )
	{
      u32LocalKm_vehicle_mux_7F2h = (uint32)(MATHSRV_udtMIN(ISCAN_u32N24F7F2P015,
                                             16777214));
      VEMS_vidSET(Km_vehicle_mux_7F2h,
                  u32LocalKm_vehicle_mux_7F2h);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF7F2P015_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF7F2_in))
      {
			VEMS_vidGET(Km_vehicle_mux_7F2h, Local_Km_vehicle_mux_7F2h);
			VEMS_vidSET(Km_vehicle_mux_7F2h, Local_Km_vehicle_mux_7F2h);
		}
	}
}

void FHCANF7F2_vidUpdateSignalP301(void)
{
	boolean FRM_bAcvRcvF7F2_in;
   uint8 u8LocalCoRegVeh_stDftOBD;

	uint8 Local_CoRegVeh_stDftOBD;

	FRM_bAcvRcvF7F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF7F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF7F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF7F2)
	   && (FHCAN_DETECTED != Ext_bDgoLIDF7F2)
	   )
	{
      u8LocalCoRegVeh_stDftOBD = ISCAN_u8N8F7F2P301;
      VEMS_vidSET(CoRegVeh_stDftOBD,
                  u8LocalCoRegVeh_stDftOBD);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF7F2_in)
      {
			VEMS_vidGET(CoRegVeh_stDftOBD, Local_CoRegVeh_stDftOBD);
			VEMS_vidSET(CoRegVeh_stDftOBD, Local_CoRegVeh_stDftOBD);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

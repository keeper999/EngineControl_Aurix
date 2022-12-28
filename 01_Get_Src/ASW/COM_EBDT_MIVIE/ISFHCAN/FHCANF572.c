/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF572.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF572.H"
#include "FHCANF572_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_572(void)
{
	ISCAN_bF572PM1359 = 0;
	ISCAN_bF572PM1357 = 0;
	ISCAN_bF572PM1358 = 0;
	ISCAN_bF572PM1446 = 0;
	ISCAN_u16N11F572PM1360 = 0;
	ISCAN_u8N8F572PM1377 = 0;
	ISCAN_u8N8F572PM1378 = 0;
	ISCAN_u8N8F572PM1379 = 0;

	VEMS_vidSET(Ext_bDgo_iBattMes, 0);
	VEMS_vidSET(Ext_bDgo_tBattMes, 0);
	VEMS_vidSET(Ext_bDgo_uBattClc, 0);
	VEMS_vidSET(Ext_bAuthWupElMgt, 0);
	VEMS_vidSET(Ext_uBattRstrt, 0);
	VEMS_vidSET(Ext_bNotAvl_uBattRstrt, AVAILABLE);
	VEMS_vidSET(Ext_bfAcvConstElMgt1, 0);
	VEMS_vidSET(Ext_bfAcvConstElMgt2, 0);
	VEMS_vidSET(Ext_bfAcvConstElMgt3, 0);

	Ext_bMonRunMissF572 = FHCAN_DISABLE;
	Ext_bMonRunShoF572 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF572PM1360 = FHCAN_DISABLE;
	Ext_bMonRunInvldF572PM1360 = FHCAN_DISABLE;

	Ext_bDgoMissF572 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF572 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF572PM1360 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF572PM1360 = FHCAN_NOT_DETECTED;
}

void FHCANF572_vidFrameReceived(void)
{
	boolean Local_bCtrl_BSI_572;
	boolean Local_bCtrl_bDgo_iBattMes;
	boolean Local_bCtrl_bDgo_tBattMes;
	boolean Local_bCtrl_bDgo_uBattClc;
	boolean Local_bCtrl_bAuthWupElMgt;
	boolean Local_bCtrl_uBattRstrt;
	boolean Local_bCtrl_bfAcvConstElMgt1;
	boolean Local_bCtrl_bfAcvConstElMgt2;
	boolean Local_bCtrl_bfAcvConstElMgt3;

	VEMS_vidGET(Ctrl_BSI_572, Local_bCtrl_BSI_572);
	if (ACTIVATED == Local_bCtrl_BSI_572)
	{
		ISCAN_EveRxn_572();
		FHCAN572_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF572)
      {
         Ext_bDgoMissF572 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF572,
                  Ext_bDgoMissF572,
                  Ext_bMonRunMissF572,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_bDgo_iBattMes, Local_bCtrl_bDgo_iBattMes);
		if (ACTIVATED == Local_bCtrl_bDgo_iBattMes)
		{
			Com_ReceiveSignal(Com_BAT_DEFAUT_I_BIN_BSI_572, (void*) &ISCAN_bF572PM1359);


			FHCANF572_vidUpdateSignalPM1359();
		}
		else
		{
			VEMS_vidSET(Ext_bDgo_iBattMes, 0);

		}
		VEMS_vidGET(Ctrl_bDgo_tBattMes, Local_bCtrl_bDgo_tBattMes);
		if (ACTIVATED == Local_bCtrl_bDgo_tBattMes)
		{
			Com_ReceiveSignal(Com_BAT_DEFAUT_T_BIN_BSI_572, (void*) &ISCAN_bF572PM1357);


			FHCANF572_vidUpdateSignalPM1357();
		}
		else
		{
			VEMS_vidSET(Ext_bDgo_tBattMes, 0);

		}
		VEMS_vidGET(Ctrl_bDgo_uBattClc, Local_bCtrl_bDgo_uBattClc);
		if (ACTIVATED == Local_bCtrl_bDgo_uBattClc)
		{
			Com_ReceiveSignal(Com_BAT_DEFAUT_U_BIN_BSI_572, (void*) &ISCAN_bF572PM1358);


			FHCANF572_vidUpdateSignalPM1358();
		}
		else
		{
			VEMS_vidSET(Ext_bDgo_uBattClc, 0);

		}
		VEMS_vidGET(Ctrl_bAuthWupElMgt, Local_bCtrl_bAuthWupElMgt);
		if (ACTIVATED == Local_bCtrl_bAuthWupElMgt)
		{
			Com_ReceiveSignal(Com_AUT_WARM_UP_GEI_BSI_572, (void*) &ISCAN_bF572PM1446);


			FHCANF572_vidUpdateSignalPM1446();
		}
		else
		{
			VEMS_vidSET(Ext_bAuthWupElMgt, 0);

		}
		VEMS_vidGET(Ctrl_uBattRstrt, Local_bCtrl_uBattRstrt);
		if (ACTIVATED == Local_bCtrl_uBattRstrt)
		{
			FHCAN572_vidCalcMonFPM1360Window();
			Com_ReceiveSignal(Com_BAT_U_PRED_REDEM_BSI_572, (void*) &ISCAN_u16N11F572PM1360);

			FHCAN572_vidMonInvldPM1360Update();
			FHCAN572_vidMonFrbdPM1360Update();

			FHCANF572_vidUpdateSignalPM1360();
		}
		else
		{
			VEMS_vidSET(Ext_uBattRstrt, 0);
			VEMS_vidSET(Ext_bNotAvl_uBattRstrt, AVAILABLE);
			Ext_bMonRunFrbdF572PM1360 = FHCAN_DISABLE;
			Ext_bMonRunInvldF572PM1360 = FHCAN_DISABLE;
			Ext_bDgoFrbdF572PM1360 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF572PM1360 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bfAcvConstElMgt1, Local_bCtrl_bfAcvConstElMgt1);
		if (ACTIVATED == Local_bCtrl_bfAcvConstElMgt1)
		{
			Com_ReceiveSignal(Com_BESOINS_GEI_CDB_1_BSI_572, (void*) &ISCAN_u8N8F572PM1377);


			FHCANF572_vidUpdateSignalPM1377();
		}
		else
		{
			VEMS_vidSET(Ext_bfAcvConstElMgt1, 0);

		}
		VEMS_vidGET(Ctrl_bfAcvConstElMgt2, Local_bCtrl_bfAcvConstElMgt2);
		if (ACTIVATED == Local_bCtrl_bfAcvConstElMgt2)
		{
			Com_ReceiveSignal(Com_BESOINS_GEI_CDB_2_BSI_572, (void*) &ISCAN_u8N8F572PM1378);


			FHCANF572_vidUpdateSignalPM1378();
		}
		else
		{
			VEMS_vidSET(Ext_bfAcvConstElMgt2, 0);

		}
		VEMS_vidGET(Ctrl_bfAcvConstElMgt3, Local_bCtrl_bfAcvConstElMgt3);
		if (ACTIVATED == Local_bCtrl_bfAcvConstElMgt3)
		{
			Com_ReceiveSignal(Com_BESOINS_GEI_CDB_3_BSI_572, (void*) &ISCAN_u8N8F572PM1379);


			FHCANF572_vidUpdateSignalPM1379();
		}
		else
		{
			VEMS_vidSET(Ext_bfAcvConstElMgt3, 0);

		}
	}
	else
	{
		Ext_bMonRunMissF572 = FHCAN_DISABLE;
		Ext_bMonRunShoF572 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF572PM1360 = FHCAN_DISABLE;
		Ext_bMonRunInvldF572PM1360 = FHCAN_DISABLE;

		Ext_bDgoMissF572 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF572 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF572PM1360 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF572PM1360 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF572_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF572PM1360_in;
	boolean FRM_bAcvRcvF572_in;
	boolean Local_bCtrl_BSI_572;
	boolean Local_bCtrl_bDgo_iBattMes;
	boolean Local_bCtrl_bDgo_tBattMes;
	boolean Local_bCtrl_bDgo_uBattClc;
	boolean Local_bCtrl_bAuthWupElMgt;
	boolean Local_bCtrl_uBattRstrt;
	boolean Local_bCtrl_bfAcvConstElMgt1;
	boolean Local_bCtrl_bfAcvConstElMgt2;
	boolean Local_bCtrl_bfAcvConstElMgt3;


	VEMS_vidGET(Ctrl_BSI_572, Local_bCtrl_BSI_572);
	if (ACTIVATED == Local_bCtrl_BSI_572)
	{
		FHCAN572_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF572)
      {
         Ext_bDgoMissF572 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF572,
                  Ext_bDgoMissF572,
                  Ext_bMonRunMissF572,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_bDgo_iBattMes, 0);
		   VEMS_vidSET(Ext_bDgo_tBattMes, 0);
		   VEMS_vidSET(Ext_bDgo_uBattClc, 0);
		   VEMS_vidSET(Ext_bAuthWupElMgt, 0);
		   VEMS_vidSET(Ext_uBattRstrt, 0);
		   VEMS_vidSET(Ext_bNotAvl_uBattRstrt, AVAILABLE);
		   VEMS_vidSET(Ext_bfAcvConstElMgt1, 0);
		   VEMS_vidSET(Ext_bfAcvConstElMgt2, 0);
		   VEMS_vidSET(Ext_bfAcvConstElMgt3, 0);
      }

		FRM_bAcvRcvF572PM1360_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF572PM1360);
		FRM_bAcvRcvF572_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF572);

		VEMS_vidGET(Ctrl_bDgo_iBattMes, Local_bCtrl_bDgo_iBattMes);
		if (ACTIVATED == Local_bCtrl_bDgo_iBattMes)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF572_in)
			{
		      VEMS_vidSET(Ext_bDgo_iBattMes, Ext_bDgo_iBattMesRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bDgo_tBattMes, Local_bCtrl_bDgo_tBattMes);
		if (ACTIVATED == Local_bCtrl_bDgo_tBattMes)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF572_in)
			{
		      VEMS_vidSET(Ext_bDgo_tBattMes, Ext_bDgo_tBattMesRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bDgo_uBattClc, Local_bCtrl_bDgo_uBattClc);
		if (ACTIVATED == Local_bCtrl_bDgo_uBattClc)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF572_in)
			{
		      VEMS_vidSET(Ext_bDgo_uBattClc, Ext_bDgo_uBattClcRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bAuthWupElMgt, Local_bCtrl_bAuthWupElMgt);
		if (ACTIVATED == Local_bCtrl_bAuthWupElMgt)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF572_in)
			{
		      VEMS_vidSET(Ext_bAuthWupElMgt, Ext_bAuthWupElMgtRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_uBattRstrt, Local_bCtrl_uBattRstrt);
		if (ACTIVATED == Local_bCtrl_uBattRstrt)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF572PM1360_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF572_in))
			{
		      VEMS_vidSET(Ext_uBattRstrt, Ext_uBattRstrtRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bfAcvConstElMgt1, Local_bCtrl_bfAcvConstElMgt1);
		if (ACTIVATED == Local_bCtrl_bfAcvConstElMgt1)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF572_in)
			{
		      VEMS_vidSET(Ext_bfAcvConstElMgt1, Ext_bfAcvConstElMgt1Rcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bfAcvConstElMgt2, Local_bCtrl_bfAcvConstElMgt2);
		if (ACTIVATED == Local_bCtrl_bfAcvConstElMgt2)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF572_in)
			{
		      VEMS_vidSET(Ext_bfAcvConstElMgt2, Ext_bfAcvConstElMgt2Rcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bfAcvConstElMgt3, Local_bCtrl_bfAcvConstElMgt3);
		if (ACTIVATED == Local_bCtrl_bfAcvConstElMgt3)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF572_in)
			{
		      VEMS_vidSET(Ext_bfAcvConstElMgt3, Ext_bfAcvConstElMgt3Rcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF572 = FHCAN_DISABLE;
		Ext_bMonRunShoF572 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF572PM1360 = FHCAN_DISABLE;
		Ext_bMonRunInvldF572PM1360 = FHCAN_DISABLE;

		Ext_bDgoMissF572 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF572 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF572PM1360 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF572PM1360 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF572_vidUpdateSignalPM1359(void)
{
	boolean FRM_bAcvRcvF572_in;

	FRM_bAcvRcvF572_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF572);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF572_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF572)
	   )
	{
      VEMS_vidSET(Ext_bDgo_iBattMes,
                  ISCAN_bF572PM1359);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF572_in)
      {
			VEMS_vidSET(Ext_bDgo_iBattMes, Ext_bDgo_iBattMesRcf_C);
		}
	}
}

void FHCANF572_vidUpdateSignalPM1357(void)
{
	boolean FRM_bAcvRcvF572_in;

	FRM_bAcvRcvF572_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF572);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF572_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF572)
	   )
	{
      VEMS_vidSET(Ext_bDgo_tBattMes,
                  ISCAN_bF572PM1357);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF572_in)
      {
			VEMS_vidSET(Ext_bDgo_tBattMes, Ext_bDgo_tBattMesRcf_C);
		}
	}
}

void FHCANF572_vidUpdateSignalPM1358(void)
{
	boolean FRM_bAcvRcvF572_in;

	FRM_bAcvRcvF572_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF572);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF572_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF572)
	   )
	{
      VEMS_vidSET(Ext_bDgo_uBattClc,
                  ISCAN_bF572PM1358);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF572_in)
      {
			VEMS_vidSET(Ext_bDgo_uBattClc, Ext_bDgo_uBattClcRcf_C);
		}
	}
}

void FHCANF572_vidUpdateSignalPM1446(void)
{
	boolean FRM_bAcvRcvF572_in;

	FRM_bAcvRcvF572_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF572);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF572_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF572)
	   )
	{
      VEMS_vidSET(Ext_bAuthWupElMgt,
                  ISCAN_bF572PM1446);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF572_in)
      {
			VEMS_vidSET(Ext_bAuthWupElMgt, Ext_bAuthWupElMgtRcf_C);
		}
	}
}

void FHCANF572_vidUpdateSignalPM1360(void)
{
	boolean FRM_bAcvRcvF572PM1360_in;
	boolean FRM_bAcvRcvF572_in;
   uint32 u32LocalIscanBSI_572;
   uint16 u16LocalExt_uBattRstrt;

   if (ISCAN_u16N11F572PM1360 == 2046)
	{
		VEMS_vidSET(Ext_bNotAvl_uBattRstrt, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_uBattRstrt, AVAILABLE);
	}

	FRM_bAcvRcvF572PM1360_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF572PM1360);
	FRM_bAcvRcvF572_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF572);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF572PM1360_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF572_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF572PM1360)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF572PM1360)
	   && (FHCAN_DETECTED != Ext_bDgoShoF572)
	   )
	{
      u32LocalIscanBSI_572 = (uint32)(((32 * ISCAN_u16N11F572PM1360) / 25));
      u16LocalExt_uBattRstrt = (uint16)(MATHSRV_udtMIN(u32LocalIscanBSI_572,
                                             1664));
      VEMS_vidSET(Ext_uBattRstrt,
                  u16LocalExt_uBattRstrt);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF572PM1360_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF572_in))
      {
			VEMS_vidSET(Ext_uBattRstrt, Ext_uBattRstrtRcf_C);
		}
	}
}

void FHCANF572_vidUpdateSignalPM1377(void)
{
	boolean FRM_bAcvRcvF572_in;
   uint8 u8LocalExt_bfAcvConstElMgt1;

	FRM_bAcvRcvF572_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF572);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF572_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF572)
	   )
	{
      u8LocalExt_bfAcvConstElMgt1 = ISCAN_u8N8F572PM1377;
      VEMS_vidSET(Ext_bfAcvConstElMgt1,
                  u8LocalExt_bfAcvConstElMgt1);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF572_in)
      {
			VEMS_vidSET(Ext_bfAcvConstElMgt1, Ext_bfAcvConstElMgt1Rcf_C);
		}
	}
}

void FHCANF572_vidUpdateSignalPM1378(void)
{
	boolean FRM_bAcvRcvF572_in;
   uint8 u8LocalExt_bfAcvConstElMgt2;

	FRM_bAcvRcvF572_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF572);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF572_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF572)
	   )
	{
      u8LocalExt_bfAcvConstElMgt2 = ISCAN_u8N8F572PM1378;
      VEMS_vidSET(Ext_bfAcvConstElMgt2,
                  u8LocalExt_bfAcvConstElMgt2);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF572_in)
      {
			VEMS_vidSET(Ext_bfAcvConstElMgt2, Ext_bfAcvConstElMgt2Rcf_C);
		}
	}
}

void FHCANF572_vidUpdateSignalPM1379(void)
{
	boolean FRM_bAcvRcvF572_in;
   uint8 u8LocalExt_bfAcvConstElMgt3;

	FRM_bAcvRcvF572_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF572);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF572_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF572)
	   )
	{
      u8LocalExt_bfAcvConstElMgt3 = ISCAN_u8N8F572PM1379;
      VEMS_vidSET(Ext_bfAcvConstElMgt3,
                  u8LocalExt_bfAcvConstElMgt3);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF572_in)
      {
			VEMS_vidSET(Ext_bfAcvConstElMgt3, Ext_bfAcvConstElMgt3Rcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

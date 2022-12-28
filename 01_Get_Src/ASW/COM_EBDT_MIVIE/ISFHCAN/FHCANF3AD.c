/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3AD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF3AD.H"
#include "FHCANF3AD_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_3AD(void)
{
	ISCAN_bF3ADP299 = 0;
	ISCAN_bF3ADP599 = 0;
	ISCAN_u8N3F3ADP337 = 0;
	ISCAN_u8N4F3ADFP0604 = 0;
	ISCAN_u8N4F3ADFP0603 = 0;

	VEMS_vidSET(Cha_bInhVSCtl, 0);
	VEMS_vidSET(Ext_bDftFctEM, 0);
	VEMS_vidSET(Cha_stEPB, 0);
	VEMS_vidSET(Ext_bPrkBrk, 0);
	VEMS_vidSET(Ext_bEPB, 0);
	VEMS_vidSET(Ext_ctClcProc3AD, 0);
	VEMS_vidSET(Ext_noCks3AD, 0);

	Ext_bMonRunMissF3AD = FHCAN_DISABLE;
	Ext_bMonRunShoF3AD = FHCAN_DISABLE;
	Ext_bMonRunChkF3AD = FHCAN_DISABLE;
	Ext_bMonRunFrbdF3ADP337 = FHCAN_DISABLE;

	Ext_bDgoMissF3AD = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF3AD = FHCAN_NOT_DETECTED;
	Ext_bDgoChkF3AD = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF3ADP337 = FHCAN_NOT_DETECTED;
}

void FHCANF3AD_vidFrameReceived(void)
{
	boolean Local_bCtrl_EASY_MOVE_3AD;
	boolean Local_bCtrl_bInhVSCtl;
	boolean Local_bCtrl_bAcv_bDftFctEM;
	boolean Local_bCtrl_stEPB;
	boolean Local_bCtrl_ctClcProc3AD;
	boolean Local_bCtrl_noCks3AD;

	VEMS_vidGET(Ctrl_EASY_MOVE_3AD, Local_bCtrl_EASY_MOVE_3AD);
	if (ACTIVATED == Local_bCtrl_EASY_MOVE_3AD)
	{
		ISCAN_EveRxn_3AD();
		FHCAN3AD_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF3AD)
      {
         Ext_bDgoMissF3AD = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF3AD,
                  Ext_bDgoMissF3AD,
                  Ext_bMonRunMissF3AD,
                  DIAG_DISPO);
      }
            
		if (FHCAN_ENABLE == Ext_bMonRunCntF3AD)
      {
         Ext_bDgoCntF3AD = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF3AD,
                  Ext_bDgoCntF3AD,
                  Ext_bMonRunCntF3AD,
                  DIAG_DISPO);
      }

		VEMS_vidGET(Ctrl_bInhVSCtl, Local_bCtrl_bInhVSCtl);
		if (ACTIVATED == Local_bCtrl_bInhVSCtl)
		{
			Com_ReceiveSignal(Com_DDE_INHI_FNCT_RVV_EASY_MOVE_3AD, (void*) &ISCAN_bF3ADP299);


			FHCANF3AD_vidUpdateSignalP299();
		}
		else
		{
			VEMS_vidSET(Cha_bInhVSCtl, 0);

		}
		VEMS_vidGET(Ctrl_bAcv_bDftFctEM, Local_bCtrl_bAcv_bDftFctEM);
		if (ACTIVATED == Local_bCtrl_bAcv_bDftFctEM)
		{
			Com_ReceiveSignal(Com_DEFAUT_FNCT_EASY_MOVE_EASY_MOVE_3AD, (void*) &ISCAN_bF3ADP599);


			FHCANF3AD_vidUpdateSignalP599();
		}
		else
		{
			VEMS_vidSET(Ext_bDftFctEM, 0);

		}
		VEMS_vidGET(Ctrl_stEPB, Local_bCtrl_stEPB);
		if (ACTIVATED == Local_bCtrl_stEPB)
		{
			FHCAN3AD_vidCalcMonFP337Window();
			Com_ReceiveSignal(Com_ETAT_FNCT_FREIN_STATION_EASY_MOVE_3AD, (void*) &ISCAN_u8N3F3ADP337);

			FHCAN3AD_vidMonFrbdP337Update();

			FHCANF3AD_vidUpdateSignalP337();
		}
		else
		{
			VEMS_vidSET(Cha_stEPB, 0);
			VEMS_vidSET(Ext_bPrkBrk, 0);
			VEMS_vidSET(Ext_bEPB, 0);

			Ext_bMonRunFrbdF3ADP337 = FHCAN_DISABLE;
			Ext_bDgoFrbdF3ADP337 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_ctClcProc3AD, Local_bCtrl_ctClcProc3AD);
		if (ACTIVATED == Local_bCtrl_ctClcProc3AD)
		{
			Com_ReceiveSignal(Com_CPT_PROCESS_4B_EASY_MOVE_ESP_EASY_MOVE_3AD, (void*) &ISCAN_u8N4F3ADFP0604);


			FHCANF3AD_vidUpdateSignalFP0604();
		}
		else
		{
			VEMS_vidSET(Ext_ctClcProc3AD, 0);

		}
		VEMS_vidGET(Ctrl_noCks3AD, Local_bCtrl_noCks3AD);
		if (ACTIVATED == Local_bCtrl_noCks3AD)
		{
			Com_ReceiveSignal(Com_CHKSUM_TRME_DYN_EASY_MOVE_ESP_EASY_MOVE_3AD, (void*) &ISCAN_u8N4F3ADFP0603);


			FHCANF3AD_vidUpdateSignalFP0603();
		}
		else
		{
			VEMS_vidSET(Ext_noCks3AD, 0);

		}
	}
	else
	{
		Ext_bMonRunMissF3AD = FHCAN_DISABLE;
		Ext_bMonRunShoF3AD = FHCAN_DISABLE;
		Ext_bMonRunChkF3AD = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3ADP337 = FHCAN_DISABLE;

		Ext_bDgoMissF3AD = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF3AD = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF3AD = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3ADP337 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF3AD_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF3ADP337_in;
	boolean FRM_bAcvRcvF3AD_in;
	boolean Local_bCtrl_EASY_MOVE_3AD;
	boolean Local_bCtrl_bInhVSCtl;
	boolean Local_bCtrl_bAcv_bDftFctEM;
	boolean Local_bCtrl_stEPB;
	boolean Local_bCtrl_ctClcProc3AD;
	boolean Local_bCtrl_noCks3AD;
	uint8 Local_Ext_ctClcProc3AD;
	uint8 Local_Ext_noCks3AD;


	VEMS_vidGET(Ctrl_EASY_MOVE_3AD, Local_bCtrl_EASY_MOVE_3AD);
	if (ACTIVATED == Local_bCtrl_EASY_MOVE_3AD)
	{
		FHCAN3AD_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF3AD)
      {
         Ext_bDgoMissF3AD = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF3AD,
                  Ext_bDgoMissF3AD,
                  Ext_bMonRunMissF3AD,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Cha_bInhVSCtl, 0);
		   VEMS_vidSET(Ext_bDftFctEM, 0);
		   VEMS_vidSET(Cha_stEPB, 0);
		   VEMS_vidSET(Ext_bPrkBrk, 0);
		   VEMS_vidSET(Ext_bEPB, 0);
		   VEMS_vidSET(Ext_ctClcProc3AD, 0);
		   VEMS_vidSET(Ext_noCks3AD, 0);
      }

		FRM_bAcvRcvF3ADP337_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3ADP337);
		FRM_bAcvRcvF3AD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3AD);

		VEMS_vidGET(Ctrl_bInhVSCtl, Local_bCtrl_bInhVSCtl);
		if (ACTIVATED == Local_bCtrl_bInhVSCtl)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF3AD_in)
			{
		      VEMS_vidSET(Cha_bInhVSCtl, Cha_bInhVSCtlRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_bDftFctEM, Local_bCtrl_bAcv_bDftFctEM);
		if (ACTIVATED == Local_bCtrl_bAcv_bDftFctEM)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF3AD_in)
			{
		      VEMS_vidSET(Ext_bDftFctEM, Ext_bDftFctEMRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stEPB, Local_bCtrl_stEPB);
		if (ACTIVATED == Local_bCtrl_stEPB)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF3ADP337_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF3AD_in))
			{
		      VEMS_vidSET(Cha_stEPB, Cha_stEPBRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_ctClcProc3AD, Local_bCtrl_ctClcProc3AD);
		if (ACTIVATED == Local_bCtrl_ctClcProc3AD)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF3AD_in)
			{
		      VEMS_vidGET(Ext_ctClcProc3AD, Local_Ext_ctClcProc3AD);
		      VEMS_vidSET(Ext_ctClcProc3AD, Local_Ext_ctClcProc3AD);
			}
		}
		VEMS_vidGET(Ctrl_noCks3AD, Local_bCtrl_noCks3AD);
		if (ACTIVATED == Local_bCtrl_noCks3AD)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF3AD_in)
			{
		      VEMS_vidGET(Ext_noCks3AD, Local_Ext_noCks3AD);
		      VEMS_vidSET(Ext_noCks3AD, Local_Ext_noCks3AD);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF3AD = FHCAN_DISABLE;
		Ext_bMonRunShoF3AD = FHCAN_DISABLE;
		Ext_bMonRunChkF3AD = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3ADP337 = FHCAN_DISABLE;

		Ext_bDgoMissF3AD = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF3AD = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF3AD = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3ADP337 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF3AD_vidUpdateSignalP299(void)
{
	boolean FRM_bAcvRcvF3AD_in;

	FRM_bAcvRcvF3AD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3AD);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3AD_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3AD)
	   )
	{
      VEMS_vidSET(Cha_bInhVSCtl,
                  ISCAN_bF3ADP299);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF3AD_in)
      {
			VEMS_vidSET(Cha_bInhVSCtl, Cha_bInhVSCtlRcf_C);
		}
	}
}

void FHCANF3AD_vidUpdateSignalP599(void)
{
	boolean FRM_bAcvRcvF3AD_in;

	FRM_bAcvRcvF3AD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3AD);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3AD_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3AD)
	   )
	{
      VEMS_vidSET(Ext_bDftFctEM,
                  ISCAN_bF3ADP599);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF3AD_in)
      {
			VEMS_vidSET(Ext_bDftFctEM, Ext_bDftFctEMRcf_C);
		}
	}
}

void FHCANF3AD_vidUpdateSignalP337(void)
{
	boolean FRM_bAcvRcvF3ADP337_in;
	boolean FRM_bAcvRcvF3AD_in;
   uint8 u8LocalCha_stEPB;

	FRM_bAcvRcvF3ADP337_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3ADP337);
	FRM_bAcvRcvF3AD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3AD);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3ADP337_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF3AD_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF3ADP337)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3AD)
	   )
	{
      u8LocalCha_stEPB = (uint8)(MATHSRV_udtMIN(ISCAN_u8N3F3ADP337,
                                             7));
      VEMS_vidSET(Cha_stEPB,
                  u8LocalCha_stEPB);
		if (ISCAN_u8N3F3ADP337 == 0)
		{
         VEMS_vidSET(Ext_bPrkBrk, 0);
         VEMS_vidSET(Ext_bEPB, 0);
		}
		else
		{
         VEMS_vidSET(Ext_bEPB, 1);
			if (ISCAN_u8N3F3ADP337 == 3)
			{
            VEMS_vidSET(Ext_bPrkBrk, 0);
			}
			else
			{
            VEMS_vidSET(Ext_bPrkBrk, 1);
			}
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF3ADP337_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF3AD_in))
      {
			VEMS_vidSET(Cha_stEPB, Cha_stEPBRcf_C);
		}
	}
}

void FHCANF3AD_vidUpdateSignalFP0604(void)
{
	boolean FRM_bAcvRcvF3AD_in;
   uint8 u8LocalExt_ctClcProc3AD;

	uint8 Local_Ext_ctClcProc3AD;

	FRM_bAcvRcvF3AD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3AD);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3AD_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3AD)
	   )
	{
      u8LocalExt_ctClcProc3AD = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F3ADFP0604,
                                             15));
      VEMS_vidSET(Ext_ctClcProc3AD,
                  u8LocalExt_ctClcProc3AD);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF3AD_in)
      {
			VEMS_vidGET(Ext_ctClcProc3AD, Local_Ext_ctClcProc3AD);
			VEMS_vidSET(Ext_ctClcProc3AD, Local_Ext_ctClcProc3AD);
		}
	}
}

void FHCANF3AD_vidUpdateSignalFP0603(void)
{
	boolean FRM_bAcvRcvF3AD_in;
   uint8 u8LocalExt_noCks3AD;

	uint8 Local_Ext_noCks3AD;

	FRM_bAcvRcvF3AD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3AD);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3AD_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3AD)
	   )
	{
      u8LocalExt_noCks3AD = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F3ADFP0603,
                                             15));
      VEMS_vidSET(Ext_noCks3AD,
                  u8LocalExt_noCks3AD);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF3AD_in)
      {
			VEMS_vidGET(Ext_noCks3AD, Local_Ext_noCks3AD);
			VEMS_vidSET(Ext_noCks3AD, Local_Ext_noCks3AD);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

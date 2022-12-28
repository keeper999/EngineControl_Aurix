/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF329.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF329.H"
#include "FHCANF329_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_329(void)
{
	ISCAN_u8N4F329PM2851 = 0;
	ISCAN_u8N4F329PM2839 = 0;
	ISCAN_bF329P442 = 0;
	ISCAN_bF329P443 = 0;
	ISCAN_bF329P444 = 0;
	ISCAN_bF329P441 = 1;
	ISCAN_u8N8F329P445 = 200;
	ISCAN_u8N2F329P397 = 3;

	VEMS_vidSET(Ext_noCks329, 0);
	VEMS_vidSET(Ext_ctClcProc329, 0);
	VEMS_vidSET(CoReqAMT_stEngStopAuth, 0);
	VEMS_vidSET(CoReqAMT_bEngRStrtReq, 0);
	VEMS_vidSET(Tra_bSTTDft, 0);
	VEMS_vidSET(Ext_bRStrtAuthTra, 1);
	VEMS_vidSET(Tra_tqCnsATRStrt, 200);
	VEMS_vidSET(Ext_stPosATLevPNCAN, 3);

	Ext_bMonRunMissF329 = FHCAN_DISABLE;
	Ext_bMonRunShoF329 = FHCAN_DISABLE;
	Ext_bMonRunChkF329 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF329P445 = FHCAN_DISABLE;
	Ext_bMonRunInvldF329P445 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF329P397 = FHCAN_DISABLE;

	Ext_bDgoMissF329 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF329 = FHCAN_NOT_DETECTED;
	Ext_bDgoChkF329 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF329P445 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF329P445 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF329P397 = FHCAN_NOT_DETECTED;
}

void FHCANF329_vidFrameReceived(void)
{
	boolean Local_bCtrl_STT_BV_329;
	boolean Local_bCtrl_noCks329;
	boolean Local_bCtrl_ctClcProc329;
	boolean Local_bCtrl_bEngStopAuthGBx;
	boolean Local_bCtrl_bEngRStrtReqGBx;
	boolean Local_bCtrl_bSTTDft;
	boolean Local_bCtrl_bRStrtAuthTra;
	boolean Local_bCtrl_tqCnsATRStrt;
	boolean Local_bCtrl_stPosATLevPNCAN;

	VEMS_vidGET(Ctrl_STT_BV_329, Local_bCtrl_STT_BV_329);
	if (ACTIVATED == Local_bCtrl_STT_BV_329)
	{
		ISCAN_EveRxn_329();
		FHCAN329_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF329)
      {
         Ext_bDgoMissF329 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF329,
                  Ext_bDgoMissF329,
                  Ext_bMonRunMissF329,
                  DIAG_DISPO);
      }
            
		if (FHCAN_ENABLE == Ext_bMonRunCntF329)
      {
         Ext_bDgoCntF329 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF329,
                  Ext_bDgoCntF329,
                  Ext_bMonRunCntF329,
                  DIAG_DISPO);
      }

		VEMS_vidGET(Ctrl_noCks329, Local_bCtrl_noCks329);
		if (ACTIVATED == Local_bCtrl_noCks329)
		{
			Com_ReceiveSignal(Com_CHKSUM_TRME_DYN_BV_329_STT_BV_329, (void*) &ISCAN_u8N4F329PM2851);


			FHCANF329_vidUpdateSignalPM2851();
		}
		else
		{
			VEMS_vidSET(Ext_noCks329, 0);

		}
		VEMS_vidGET(Ctrl_ctClcProc329, Local_bCtrl_ctClcProc329);
		if (ACTIVATED == Local_bCtrl_ctClcProc329)
		{
			Com_ReceiveSignal(Com_CPT_PROCESS_4B_BV_329_STT_BV_329, (void*) &ISCAN_u8N4F329PM2839);


			FHCANF329_vidUpdateSignalPM2839();
		}
		else
		{
			VEMS_vidSET(Ext_ctClcProc329, 0);

		}
		VEMS_vidGET(Ctrl_bEngStopAuthGBx, Local_bCtrl_bEngStopAuthGBx);
		if (ACTIVATED == Local_bCtrl_bEngStopAuthGBx)
		{
			Com_ReceiveSignal(Com_AUTOR_STOP_BV_STT_BV_329, (void*) &ISCAN_bF329P442);


			FHCANF329_vidUpdateSignalP442();
		}
		else
		{
			VEMS_vidSET(CoReqAMT_stEngStopAuth, 0);

		}
		VEMS_vidGET(Ctrl_bEngRStrtReqGBx, Local_bCtrl_bEngRStrtReqGBx);
		if (ACTIVATED == Local_bCtrl_bEngRStrtReqGBx)
		{
			Com_ReceiveSignal(Com_DMD_REDEM_BV_STT_BV_329, (void*) &ISCAN_bF329P443);


			FHCANF329_vidUpdateSignalP443();
		}
		else
		{
			VEMS_vidSET(CoReqAMT_bEngRStrtReq, 0);

		}
		VEMS_vidGET(Ctrl_bSTTDft, Local_bCtrl_bSTTDft);
		if (ACTIVATED == Local_bCtrl_bSTTDft)
		{
			Com_ReceiveSignal(Com_DEFAUT_STT_BV_STT_BV_329, (void*) &ISCAN_bF329P444);


			FHCANF329_vidUpdateSignalP444();
		}
		else
		{
			VEMS_vidSET(Tra_bSTTDft, 0);

		}
		VEMS_vidGET(Ctrl_bRStrtAuthTra, Local_bCtrl_bRStrtAuthTra);
		if (ACTIVATED == Local_bCtrl_bRStrtAuthTra)
		{
			Com_ReceiveSignal(Com_AUTOR_REDEM_BV_STT_BV_329, (void*) &ISCAN_bF329P441);


			FHCANF329_vidUpdateSignalP441();
		}
		else
		{
			VEMS_vidSET(Ext_bRStrtAuthTra, 1);

		}
		VEMS_vidGET(Ctrl_tqCnsATRStrt, Local_bCtrl_tqCnsATRStrt);
		if (ACTIVATED == Local_bCtrl_tqCnsATRStrt)
		{
			FHCAN329_vidCalcMonFP445Window();
			Com_ReceiveSignal(Com_CPLE_RESIST_PREDIT_STT_BV_329, (void*) &ISCAN_u8N8F329P445);

			FHCAN329_vidMonInvldP445Update();
			FHCAN329_vidMonFrbdP445Update();

			FHCANF329_vidUpdateSignalP445();
		}
		else
		{
			VEMS_vidSET(Tra_tqCnsATRStrt, 200);

			Ext_bMonRunFrbdF329P445 = FHCAN_DISABLE;
			Ext_bMonRunInvldF329P445 = FHCAN_DISABLE;
			Ext_bDgoFrbdF329P445 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF329P445 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stPosATLevPNCAN, Local_bCtrl_stPosATLevPNCAN);
		if (ACTIVATED == Local_bCtrl_stPosATLevPNCAN)
		{
			FHCAN329_vidCalcMonFP397Window();
			Com_ReceiveSignal(Com_POS_LEVIER_P_N_STT_BV_329, (void*) &ISCAN_u8N2F329P397);

			FHCAN329_vidMonFrbdP397Update();

			FHCANF329_vidUpdateSignalP397();
		}
		else
		{
			VEMS_vidSET(Ext_stPosATLevPNCAN, 3);

			Ext_bMonRunFrbdF329P397 = FHCAN_DISABLE;
			Ext_bDgoFrbdF329P397 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF329 = FHCAN_DISABLE;
		Ext_bMonRunShoF329 = FHCAN_DISABLE;
		Ext_bMonRunChkF329 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF329P445 = FHCAN_DISABLE;
		Ext_bMonRunInvldF329P445 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF329P397 = FHCAN_DISABLE;

		Ext_bDgoMissF329 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF329 = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF329 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF329P445 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF329P445 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF329P397 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF329_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF329P445_in;
	boolean FRM_bAcvRcvF329P397_in;
	boolean FRM_bAcvRcvF329_in;
	boolean Local_bCtrl_STT_BV_329;
	boolean Local_bCtrl_noCks329;
	boolean Local_bCtrl_ctClcProc329;
	boolean Local_bCtrl_bEngStopAuthGBx;
	boolean Local_bCtrl_bEngRStrtReqGBx;
	boolean Local_bCtrl_bSTTDft;
	boolean Local_bCtrl_bRStrtAuthTra;
	boolean Local_bCtrl_tqCnsATRStrt;
	boolean Local_bCtrl_stPosATLevPNCAN;
	uint8 Local_Ext_noCks329;
	uint8 Local_Ext_ctClcProc329;


	VEMS_vidGET(Ctrl_STT_BV_329, Local_bCtrl_STT_BV_329);
	if (ACTIVATED == Local_bCtrl_STT_BV_329)
	{
		FHCAN329_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF329)
      {
         Ext_bDgoMissF329 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF329,
                  Ext_bDgoMissF329,
                  Ext_bMonRunMissF329,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_noCks329, 0);
		   VEMS_vidSET(Ext_ctClcProc329, 0);
		   VEMS_vidSET(CoReqAMT_stEngStopAuth, 0);
		   VEMS_vidSET(CoReqAMT_bEngRStrtReq, 0);
		   VEMS_vidSET(Tra_bSTTDft, 0);
		   VEMS_vidSET(Ext_bRStrtAuthTra, 1);
		   VEMS_vidSET(Tra_tqCnsATRStrt, 200);
		   VEMS_vidSET(Ext_stPosATLevPNCAN, 3);
      }

		FRM_bAcvRcvF329P445_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329P445);
		FRM_bAcvRcvF329P397_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329P397);
		FRM_bAcvRcvF329_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329);

		VEMS_vidGET(Ctrl_noCks329, Local_bCtrl_noCks329);
		if (ACTIVATED == Local_bCtrl_noCks329)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF329_in)
			{
		      VEMS_vidGET(Ext_noCks329, Local_Ext_noCks329);
		      VEMS_vidSET(Ext_noCks329, Local_Ext_noCks329);
			}
		}
		VEMS_vidGET(Ctrl_ctClcProc329, Local_bCtrl_ctClcProc329);
		if (ACTIVATED == Local_bCtrl_ctClcProc329)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF329_in)
			{
		      VEMS_vidGET(Ext_ctClcProc329, Local_Ext_ctClcProc329);
		      VEMS_vidSET(Ext_ctClcProc329, Local_Ext_ctClcProc329);
			}
		}
		VEMS_vidGET(Ctrl_bEngStopAuthGBx, Local_bCtrl_bEngStopAuthGBx);
		if (ACTIVATED == Local_bCtrl_bEngStopAuthGBx)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF329_in)
			{
		      VEMS_vidSET(CoReqAMT_stEngStopAuth, CoReqAMT_bEngStopAuthRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bEngRStrtReqGBx, Local_bCtrl_bEngRStrtReqGBx);
		if (ACTIVATED == Local_bCtrl_bEngRStrtReqGBx)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF329_in)
			{
		      VEMS_vidSET(CoReqAMT_bEngRStrtReq, CoReqAMT_bEngRStrtReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bSTTDft, Local_bCtrl_bSTTDft);
		if (ACTIVATED == Local_bCtrl_bSTTDft)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF329_in)
			{
		      VEMS_vidSET(Tra_bSTTDft, Tra_bSTTDftRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bRStrtAuthTra, Local_bCtrl_bRStrtAuthTra);
		if (ACTIVATED == Local_bCtrl_bRStrtAuthTra)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF329_in)
			{
		      VEMS_vidSET(Ext_bRStrtAuthTra, Ext_bRStrtAuthTraRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_tqCnsATRStrt, Local_bCtrl_tqCnsATRStrt);
		if (ACTIVATED == Local_bCtrl_tqCnsATRStrt)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF329P445_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF329_in))
			{
		      VEMS_vidSET(Tra_tqCnsATRStrt, Tra_tqCnsATRStrtRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stPosATLevPNCAN, Local_bCtrl_stPosATLevPNCAN);
		if (ACTIVATED == Local_bCtrl_stPosATLevPNCAN)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF329P397_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF329_in))
			{
		      VEMS_vidSET(Ext_stPosATLevPNCAN, Ext_stPosATLevPNCANRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF329 = FHCAN_DISABLE;
		Ext_bMonRunShoF329 = FHCAN_DISABLE;
		Ext_bMonRunChkF329 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF329P445 = FHCAN_DISABLE;
		Ext_bMonRunInvldF329P445 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF329P397 = FHCAN_DISABLE;

		Ext_bDgoMissF329 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF329 = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF329 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF329P445 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF329P445 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF329P397 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF329_vidUpdateSignalPM2851(void)
{
	boolean FRM_bAcvRcvF329_in;
   uint8 u8LocalExt_noCks329;

	uint8 Local_Ext_noCks329;

	FRM_bAcvRcvF329_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF329_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF329)
	   )
	{
      u8LocalExt_noCks329 = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F329PM2851,
                                             15));
      VEMS_vidSET(Ext_noCks329,
                  u8LocalExt_noCks329);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF329_in)
      {
			VEMS_vidGET(Ext_noCks329, Local_Ext_noCks329);
			VEMS_vidSET(Ext_noCks329, Local_Ext_noCks329);
		}
	}
}

void FHCANF329_vidUpdateSignalPM2839(void)
{
	boolean FRM_bAcvRcvF329_in;
   uint8 u8LocalExt_ctClcProc329;

	uint8 Local_Ext_ctClcProc329;

	FRM_bAcvRcvF329_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF329_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF329)
	   )
	{
      u8LocalExt_ctClcProc329 = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F329PM2839,
                                             15));
      VEMS_vidSET(Ext_ctClcProc329,
                  u8LocalExt_ctClcProc329);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF329_in)
      {
			VEMS_vidGET(Ext_ctClcProc329, Local_Ext_ctClcProc329);
			VEMS_vidSET(Ext_ctClcProc329, Local_Ext_ctClcProc329);
		}
	}
}

void FHCANF329_vidUpdateSignalP442(void)
{
	boolean FRM_bAcvRcvF329_in;
   uint8 u8LocalCoReqAMT_stEngStopAuth;

	FRM_bAcvRcvF329_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF329_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF329)
	   )
	{
      u8LocalCoReqAMT_stEngStopAuth = (uint8)(MATHSRV_udtMIN(ISCAN_bF329P442,
                                             3));
      VEMS_vidSET(CoReqAMT_stEngStopAuth,
                  u8LocalCoReqAMT_stEngStopAuth);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF329_in)
      {
			VEMS_vidSET(CoReqAMT_stEngStopAuth, CoReqAMT_bEngStopAuthRcf_C);
		}
	}
}

void FHCANF329_vidUpdateSignalP443(void)
{
	boolean FRM_bAcvRcvF329_in;

	FRM_bAcvRcvF329_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF329_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF329)
	   )
	{
      VEMS_vidSET(CoReqAMT_bEngRStrtReq,
                  ISCAN_bF329P443);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF329_in)
      {
			VEMS_vidSET(CoReqAMT_bEngRStrtReq, CoReqAMT_bEngRStrtReqRcf_C);
		}
	}
}

void FHCANF329_vidUpdateSignalP444(void)
{
	boolean FRM_bAcvRcvF329_in;

	FRM_bAcvRcvF329_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF329_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF329)
	   )
	{
      VEMS_vidSET(Tra_bSTTDft,
                  ISCAN_bF329P444);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF329_in)
      {
			VEMS_vidSET(Tra_bSTTDft, Tra_bSTTDftRcf_C);
		}
	}
}

void FHCANF329_vidUpdateSignalP441(void)
{
	boolean FRM_bAcvRcvF329_in;

	FRM_bAcvRcvF329_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF329_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF329)
	   )
	{
      VEMS_vidSET(Ext_bRStrtAuthTra,
                  ISCAN_bF329P441);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF329_in)
      {
			VEMS_vidSET(Ext_bRStrtAuthTra, Ext_bRStrtAuthTraRcf_C);
		}
	}
}

void FHCANF329_vidUpdateSignalP445(void)
{
	boolean FRM_bAcvRcvF329P445_in;
	boolean FRM_bAcvRcvF329_in;
   uint8 u8LocalTra_tqCnsATRStrt;

	FRM_bAcvRcvF329P445_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329P445);
	FRM_bAcvRcvF329_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF329P445_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF329_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF329P445)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF329P445)
	   && (FHCAN_DETECTED != Ext_bDgoShoF329)
	   )
	{
      u8LocalTra_tqCnsATRStrt = (uint8)(MATHSRV_udtMIN(ISCAN_u8N8F329P445,
                                             200));
      VEMS_vidSET(Tra_tqCnsATRStrt,
                  u8LocalTra_tqCnsATRStrt);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF329P445_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF329_in))
      {
			VEMS_vidSET(Tra_tqCnsATRStrt, Tra_tqCnsATRStrtRcf_C);
		}
	}
}

void FHCANF329_vidUpdateSignalP397(void)
{
	boolean FRM_bAcvRcvF329P397_in;
	boolean FRM_bAcvRcvF329_in;
   uint8 u8LocalExt_stPosATLevPNCAN;

	FRM_bAcvRcvF329P397_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329P397);
	FRM_bAcvRcvF329_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF329);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF329P397_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF329_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF329P397)
	   && (FHCAN_DETECTED != Ext_bDgoShoF329)
	   )
	{
      u8LocalExt_stPosATLevPNCAN = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F329P397,
                                             3));
      VEMS_vidSET(Ext_stPosATLevPNCAN,
                  u8LocalExt_stPosATLevPNCAN);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF329P397_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF329_in))
      {
			VEMS_vidSET(Ext_stPosATLevPNCAN, Ext_stPosATLevPNCANRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

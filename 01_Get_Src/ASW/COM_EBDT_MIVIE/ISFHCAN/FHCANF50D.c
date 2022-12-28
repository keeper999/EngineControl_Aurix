/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF50D.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF50D.H"
#include "FHCANF50D_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_50D(void)
{
	ISCAN_bF50DP351 = 0;
	ISCAN_u8N2F50DP415 = 0;
	ISCAN_u8N4F50DPM2850 = 0;
	ISCAN_u8N4F50DPM2857 = 0;

	VEMS_vidSET(Ext_bABSReg50D, 0);
	VEMS_vidSET(Cha_bABSReg, 0);
	VEMS_vidSET(CoReqCha_bEngRStrtReq, 0);
	VEMS_vidSET(CoReqCha_stEngStopAuth, 0);
	VEMS_vidSET(CoReqCha_bEngStopAuth, 0);
	VEMS_vidSET(Ext_ctClcProc50D, 0);
	VEMS_vidSET(Ext_noCks50D, 0);

	Ext_bMonRunMissF50D = FHCAN_DISABLE;
	Ext_bMonRunShoF50D = FHCAN_DISABLE;
	Ext_bMonRunChkF50D = FHCAN_DISABLE;

	Ext_bDgoMissF50D = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF50D = FHCAN_NOT_DETECTED;
	Ext_bDgoChkF50D = FHCAN_NOT_DETECTED;
}

void FHCANF50D_vidFrameReceived(void)
{
	boolean Local_bCtrl_ABR_50D;
	boolean Local_bCtrl_bABSReg;
	boolean Local_bCtrl_bEngRStrtReqSTT;
	boolean Local_bCtrl_ctClcProc50D;
	boolean Local_bCtrl_noCks50D;

	VEMS_vidGET(Ctrl_ABR_50D, Local_bCtrl_ABR_50D);
	if (ACTIVATED == Local_bCtrl_ABR_50D)
	{
		ISCAN_EveRxn_50D();
		FHCAN50D_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF50D)
      {
         Ext_bDgoMissF50D = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF50D,
                  Ext_bDgoMissF50D,
                  Ext_bMonRunMissF50D,
                  DIAG_DISPO);
      }
            
		if (FHCAN_ENABLE == Ext_bMonRunCntF50D)
      {
         Ext_bDgoCntF50D = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF50D,
                  Ext_bDgoCntF50D,
                  Ext_bMonRunCntF50D,
                  DIAG_DISPO);
      }

		VEMS_vidGET(Ctrl_bABSReg, Local_bCtrl_bABSReg);
		if (ACTIVATED == Local_bCtrl_bABSReg)
		{
			Com_ReceiveSignal(Com_REGUL_ABR_ABR_50D, (void*) &ISCAN_bF50DP351);


			FHCANF50D_vidUpdateSignalP351();
		}
		else
		{
			VEMS_vidSET(Ext_bABSReg50D, 0);
			VEMS_vidSET(Cha_bABSReg, 0);

		}
		VEMS_vidGET(Ctrl_bEngRStrtReqSTT, Local_bCtrl_bEngRStrtReqSTT);
		if (ACTIVATED == Local_bCtrl_bEngRStrtReqSTT)
		{
			Com_ReceiveSignal(Com_BES_FREIN_STT_ABR_50D, (void*) &ISCAN_u8N2F50DP415);


			FHCANF50D_vidUpdateSignalP415();
		}
		else
		{
			VEMS_vidSET(CoReqCha_bEngRStrtReq, 0);
			VEMS_vidSET(CoReqCha_stEngStopAuth, 0);
			VEMS_vidSET(CoReqCha_bEngStopAuth, 0);

		}
		VEMS_vidGET(Ctrl_ctClcProc50D, Local_bCtrl_ctClcProc50D);
		if (ACTIVATED == Local_bCtrl_ctClcProc50D)
		{
			Com_ReceiveSignal(Com_CPT_PROCESS_4B_50D_ABR_50D, (void*) &ISCAN_u8N4F50DPM2850);


			FHCANF50D_vidUpdateSignalPM2850();
		}
		else
		{
			VEMS_vidSET(Ext_ctClcProc50D, 0);

		}
		VEMS_vidGET(Ctrl_noCks50D, Local_bCtrl_noCks50D);
		if (ACTIVATED == Local_bCtrl_noCks50D)
		{
			Com_ReceiveSignal(Com_CHKSUM_TRME_DAT_UC_FREIN_ABR_50D, (void*) &ISCAN_u8N4F50DPM2857);


			FHCANF50D_vidUpdateSignalPM2857();
		}
		else
		{
			VEMS_vidSET(Ext_noCks50D, 0);

		}
	}
	else
	{
		Ext_bMonRunMissF50D = FHCAN_DISABLE;
		Ext_bMonRunShoF50D = FHCAN_DISABLE;
		Ext_bMonRunChkF50D = FHCAN_DISABLE;

		Ext_bDgoMissF50D = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF50D = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF50D = FHCAN_NOT_DETECTED;
	}
}



void FHCANF50D_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF50D_in;
	boolean Local_bCtrl_ABR_50D;
	boolean Local_bCtrl_bABSReg;
	boolean Local_bCtrl_bEngRStrtReqSTT;
	boolean Local_bCtrl_ctClcProc50D;
	boolean Local_bCtrl_noCks50D;
	uint8 Local_Ext_ctClcProc50D;
	uint8 Local_Ext_noCks50D;


	VEMS_vidGET(Ctrl_ABR_50D, Local_bCtrl_ABR_50D);
	if (ACTIVATED == Local_bCtrl_ABR_50D)
	{
		FHCAN50D_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF50D)
      {
         Ext_bDgoMissF50D = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF50D,
                  Ext_bDgoMissF50D,
                  Ext_bMonRunMissF50D,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_bABSReg50D, 0);
		   VEMS_vidSET(Cha_bABSReg, 0);
		   VEMS_vidSET(CoReqCha_bEngRStrtReq, 0);
		   VEMS_vidSET(CoReqCha_stEngStopAuth, 0);
		   VEMS_vidSET(CoReqCha_bEngStopAuth, 0);
		   VEMS_vidSET(Ext_ctClcProc50D, 0);
		   VEMS_vidSET(Ext_noCks50D, 0);
      }

		FRM_bAcvRcvF50D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50D);

		VEMS_vidGET(Ctrl_bABSReg, Local_bCtrl_bABSReg);
		if (ACTIVATED == Local_bCtrl_bABSReg)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50D_in)
			{
		      VEMS_vidSET(Ext_bABSReg50D, Ext_bABSRegRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bEngRStrtReqSTT, Local_bCtrl_bEngRStrtReqSTT);
		if (ACTIVATED == Local_bCtrl_bEngRStrtReqSTT)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50D_in)
			{
		      VEMS_vidSET(CoReqCha_bEngRStrtReq, CoReqCha_bEngRStrtReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_ctClcProc50D, Local_bCtrl_ctClcProc50D);
		if (ACTIVATED == Local_bCtrl_ctClcProc50D)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50D_in)
			{
		      VEMS_vidGET(Ext_ctClcProc50D, Local_Ext_ctClcProc50D);
		      VEMS_vidSET(Ext_ctClcProc50D, Local_Ext_ctClcProc50D);
			}
		}
		VEMS_vidGET(Ctrl_noCks50D, Local_bCtrl_noCks50D);
		if (ACTIVATED == Local_bCtrl_noCks50D)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50D_in)
			{
		      VEMS_vidGET(Ext_noCks50D, Local_Ext_noCks50D);
		      VEMS_vidSET(Ext_noCks50D, Local_Ext_noCks50D);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF50D = FHCAN_DISABLE;
		Ext_bMonRunShoF50D = FHCAN_DISABLE;
		Ext_bMonRunChkF50D = FHCAN_DISABLE;

		Ext_bDgoMissF50D = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF50D = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF50D = FHCAN_NOT_DETECTED;
	}
}

void FHCANF50D_vidUpdateSignalP351(void)
{
	boolean FRM_bAcvRcvF50D_in;

	FRM_bAcvRcvF50D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50D)
	   )
	{
      VEMS_vidSET(Ext_bABSReg50D,
                  ISCAN_bF50DP351);
      VEMS_vidSET(Cha_bABSReg,
                  ISCAN_bF50DP351);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50D_in)
      {
			VEMS_vidSET(Ext_bABSReg50D, Ext_bABSRegRcf_C);
		}
	}
}

void FHCANF50D_vidUpdateSignalP415(void)
{
	boolean FRM_bAcvRcvF50D_in;

	FRM_bAcvRcvF50D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50D)
	   )
	{
		if (ISCAN_u8N2F50DP415 == 0)
		{
         VEMS_vidSET(CoReqCha_stEngStopAuth, 1);
         VEMS_vidSET(CoReqCha_bEngStopAuth, 1);
		}
		else
		{
         VEMS_vidSET(CoReqCha_stEngStopAuth, 0);
         VEMS_vidSET(CoReqCha_bEngStopAuth, 0);
		}	
		if (ISCAN_u8N2F50DP415 == 2)
		{
            VEMS_vidSET(CoReqCha_bEngRStrtReq, 1);
		}
		else
		{
            VEMS_vidSET(CoReqCha_bEngRStrtReq, 0);
		}
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50D_in)
      {
			VEMS_vidSET(CoReqCha_bEngRStrtReq, CoReqCha_bEngRStrtReqRcf_C);
		}
	}
}

void FHCANF50D_vidUpdateSignalPM2850(void)
{
	boolean FRM_bAcvRcvF50D_in;
   uint8 u8LocalExt_ctClcProc50D;

	uint8 Local_Ext_ctClcProc50D;

	FRM_bAcvRcvF50D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50D)
	   )
	{
      u8LocalExt_ctClcProc50D = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F50DPM2850,
                                             15));
      VEMS_vidSET(Ext_ctClcProc50D,
                  u8LocalExt_ctClcProc50D);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50D_in)
      {
			VEMS_vidGET(Ext_ctClcProc50D, Local_Ext_ctClcProc50D);
			VEMS_vidSET(Ext_ctClcProc50D, Local_Ext_ctClcProc50D);
		}
	}
}

void FHCANF50D_vidUpdateSignalPM2857(void)
{
	boolean FRM_bAcvRcvF50D_in;
   uint8 u8LocalExt_noCks50D;

	uint8 Local_Ext_noCks50D;

	FRM_bAcvRcvF50D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50D)
	   )
	{
      u8LocalExt_noCks50D = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F50DPM2857,
                                             15));
      VEMS_vidSET(Ext_noCks50D,
                  u8LocalExt_noCks50D);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50D_in)
      {
			VEMS_vidGET(Ext_noCks50D, Local_Ext_noCks50D);
			VEMS_vidSET(Ext_noCks50D, Local_Ext_noCks50D);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

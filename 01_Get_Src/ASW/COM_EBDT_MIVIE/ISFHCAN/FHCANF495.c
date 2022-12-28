/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF495.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF495.H"
#include "FHCANF495_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_495(void)
{
	ISCAN_bF495P447 = 0;
	ISCAN_bF495P448 = 0;

	VEMS_vidSET(CoReqStg_bEngRStrtReq, 0);
	VEMS_vidSET(CoReqStg_bEngStopAuth, 0);
	Ext_bMonRunUC_DIRAAbsent = FHCAN_DISABLE;
	Ext_bDgoUC_DIRAAbsent = FHCAN_NOT_DETECTED;

	Ext_bMonRunMissF495 = FHCAN_DISABLE;
	Ext_bMonRunShoF495 = FHCAN_DISABLE;

	Ext_bDgoMissF495 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF495 = FHCAN_NOT_DETECTED;
}

void FHCANF495_vidFrameReceived(void)
{
	boolean Local_bCtrl_DIRA_495;
	boolean Local_bCtrl_bEngRStrtReqAsiDir;
	boolean Local_bCtrl_bEngStopAuthAsiDir;

	VEMS_vidGET(Ctrl_DIRA_495, Local_bCtrl_DIRA_495);
	if (ACTIVATED == Local_bCtrl_DIRA_495)
	{
		ISCAN_EveRxn_495();
		FHCAN495_vidCalcMonUC_DIRAWindow();
		FHCAN495_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunUC_DIRAAbsent)
		{
			Ext_bDgoUC_DIRAAbsent = FHCAN_NOT_DETECTED;
			GDGAR_vidGdu(GD_DFT_UC_DIRAABSENT,
						Ext_bDgoUC_DIRAAbsent,
						Ext_bMonRunUC_DIRAAbsent,
						DIAG_DISPO);
		}
	  	if (FHCAN_ENABLE == Ext_bMonRunMissF495)
      {
         Ext_bDgoMissF495 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF495,
                  Ext_bDgoMissF495,
                  Ext_bMonRunMissF495,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_bEngRStrtReqAsiDir, Local_bCtrl_bEngRStrtReqAsiDir);
		if (ACTIVATED == Local_bCtrl_bEngRStrtReqAsiDir)
		{
			Com_ReceiveSignal(Com_DDE_REDEM_DA_DIRA_495, (void*) &ISCAN_bF495P447);


			FHCANF495_vidUpdateSignalP447();
		}
		else
		{
			VEMS_vidSET(CoReqStg_bEngRStrtReq, 0);

		}
		VEMS_vidGET(Ctrl_bEngStopAuthAsiDir, Local_bCtrl_bEngStopAuthAsiDir);
		if (ACTIVATED == Local_bCtrl_bEngStopAuthAsiDir)
		{
			Com_ReceiveSignal(Com_AUTOR_ARRET_MOT_DA_DIRA_495, (void*) &ISCAN_bF495P448);


			FHCANF495_vidUpdateSignalP448();
		}
		else
		{
			VEMS_vidSET(CoReqStg_bEngStopAuth, 0);

		}
	}
	else
	{
		Ext_bMonRunUC_DIRAAbsent = FHCAN_DISABLE;
		Ext_bDgoUC_DIRAAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF495 = FHCAN_DISABLE;
		Ext_bMonRunShoF495 = FHCAN_DISABLE;

		Ext_bDgoMissF495 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF495 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF495_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF495_in;
	boolean Local_bCtrl_DIRA_495;
	boolean Local_bCtrl_bEngRStrtReqAsiDir;
	boolean Local_bCtrl_bEngStopAuthAsiDir;


	VEMS_vidGET(Ctrl_DIRA_495, Local_bCtrl_DIRA_495);
	if (ACTIVATED == Local_bCtrl_DIRA_495)
	{
		FHCAN495_vidCalcMonUC_DIRAWindow();
		FHCAN495_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunUC_DIRAAbsent)
		{
			Ext_bDgoUC_DIRAAbsent = FHCAN_DETECTED;
			GDGAR_vidGdu(GD_DFT_UC_DIRAABSENT,
						Ext_bDgoUC_DIRAAbsent,
						Ext_bMonRunUC_DIRAAbsent,
						DIAG_DISPO);
		}
      if (FHCAN_ENABLE == Ext_bMonRunMissF495)
      {
         Ext_bDgoMissF495 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF495,
                  Ext_bDgoMissF495,
                  Ext_bMonRunMissF495,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(CoReqStg_bEngRStrtReq, 0);
		   VEMS_vidSET(CoReqStg_bEngStopAuth, 0);
      }

		FRM_bAcvRcvF495_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF495);

		VEMS_vidGET(Ctrl_bEngRStrtReqAsiDir, Local_bCtrl_bEngRStrtReqAsiDir);
		if (ACTIVATED == Local_bCtrl_bEngRStrtReqAsiDir)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF495_in)
			{
		      VEMS_vidSET(CoReqStg_bEngRStrtReq, CoReqStg_bEngRStrtReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bEngStopAuthAsiDir, Local_bCtrl_bEngStopAuthAsiDir);
		if (ACTIVATED == Local_bCtrl_bEngStopAuthAsiDir)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF495_in)
			{
		      VEMS_vidSET(CoReqStg_bEngStopAuth, CoReqStg_bEngStopAuthRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunUC_DIRAAbsent = FHCAN_DISABLE;
		Ext_bDgoUC_DIRAAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF495 = FHCAN_DISABLE;
		Ext_bMonRunShoF495 = FHCAN_DISABLE;

		Ext_bDgoMissF495 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF495 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF495_vidUpdateSignalP447(void)
{
	boolean FRM_bAcvRcvF495_in;

	FRM_bAcvRcvF495_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF495);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF495_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF495)
	   )
	{
      VEMS_vidSET(CoReqStg_bEngRStrtReq,
                  ISCAN_bF495P447);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF495_in)
      {
			VEMS_vidSET(CoReqStg_bEngRStrtReq, CoReqStg_bEngRStrtReqRcf_C);
		}
	}
}

void FHCANF495_vidUpdateSignalP448(void)
{
	boolean FRM_bAcvRcvF495_in;

	FRM_bAcvRcvF495_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF495);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF495_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF495)
	   )
	{
      VEMS_vidSET(CoReqStg_bEngStopAuth,
                  ISCAN_bF495P448);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF495_in)
      {
			VEMS_vidSET(CoReqStg_bEngStopAuth, CoReqStg_bEngStopAuthRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

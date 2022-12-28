/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF432.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF432.H"
#include "FHCANF432_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_432(void)
{
	ISCAN_bF432P276 = 0;
	ISCAN_u8N2F432P214 = 0;
	ISCAN_bF432P216 = 0;
	ISCAN_u8N2F432P249 = 0;
	ISCAN_u8N2F432P251 = 0;
	ISCAN_u8N2F432P402 = 0;
	ISCAN_bF432P289 = 0;
	ISCAN_bF432P350 = 0;
	ISCAN_bF432P403 = 0;
	ISCAN_u8N6F432P367 = 0;
	ISCAN_u8N2F432P368 = 0;
	ISCAN_u8N4F432P369 = 0;
	ISCAN_u8N2F432PM1424 = 0;

	VEMS_vidSET(Ext_bOilWkuReq, 0);
	VEMS_vidSET(CoReqVeh_bOilWkuReq, 0);
	VEMS_vidSET(CoReqVeh_stWkuMain, 0);
	VEMS_vidSET(Ext_stMainWkuReq, 0);
	VEMS_vidSET(Ext_bImmoUnlockWkuReq, 0);
	VEMS_vidSET(Ext_bEngStopReq, 0);
	VEMS_vidSET(Ext_bEngStrtReq, 0);
	VEMS_vidSET(Ext_bAcvSta, 0);
	VEMS_vidSET(Ext_bPrepIgEngWkuReq, 0);
	VEMS_vidSET(Ext_bStopEngCoWkuReq, 0);
	VEMS_vidSET(Ext_bTypStrt, 0);
	VEMS_vidSET(Ext_noJDD, 0);
	VEMS_vidSET(CoReqVeh_stWkuMainSEV, 0);
	VEMS_vidSET(CoReqVeh_stNetwEl, 0);
	VEMS_vidSET(CoReqVeh_bEngStrtReq, 0);

	Ext_bMonRunMissF432 = FHCAN_DISABLE;
	Ext_bMonRunShoF432 = FHCAN_DISABLE;
	Ext_bMonRunInvldF432P214 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF432P249 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF432P251 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF432P402 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF432P368 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF432P369 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF432PM1424 = FHCAN_DISABLE;

	Ext_bDgoMissF432 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF432 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF432P214 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF432P249 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF432P251 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF432P402 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF432P368 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF432P369 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF432PM1424 = FHCAN_NOT_DETECTED;
}

void FHCANF432_vidFrameReceived(void)
{
	boolean Local_bCtrl_BSI_432;
	boolean Local_bCtrl_bOilWkuReq;
	boolean Local_bCtrl_stWkuMain;
	boolean Local_bCtrl_bImmoUnlockWkuReq;
	boolean Local_bCtrl_bEngStopReq;
	boolean Local_bCtrl_bEngStrtReq2;
	boolean Local_bCtrl_bAcvSta;
	boolean Local_bCtrl_bPrepIgEngWkuReq;
	boolean Local_bCtrl_bStopEngCoWkuReq;
	boolean Local_bCtrl_bTypStrt;
	boolean Local_bCtrl_noJDD;
	boolean Local_bCtrl_bWkuMainSev;
	boolean Local_bCtrl_stNetwEl;
	boolean Local_bCtrl_bEngStrtReq;

	VEMS_vidGET(Ctrl_BSI_432, Local_bCtrl_BSI_432);
	if (ACTIVATED == Local_bCtrl_BSI_432)
	{
		ISCAN_EveRxn_432();
		FHCAN432_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF432)
      {
         Ext_bDgoMissF432 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF432,
                  Ext_bDgoMissF432,
                  Ext_bMonRunMissF432,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_bOilWkuReq, Local_bCtrl_bOilWkuReq);
		if (ACTIVATED == Local_bCtrl_bOilWkuReq)
		{
			Com_ReceiveSignal(Com_REVEIL_MES_HUILE_MOT_BSI_432, (void*) &ISCAN_bF432P276);


			FHCANF432_vidUpdateSignalP276();
		}
		else
		{
			VEMS_vidSET(Ext_bOilWkuReq, 0);
			VEMS_vidSET(CoReqVeh_bOilWkuReq, 0);

		}
		VEMS_vidGET(Ctrl_stWkuMain, Local_bCtrl_stWkuMain);
		if (ACTIVATED == Local_bCtrl_stWkuMain)
		{
			FHCAN432_vidCalcMonFP214Window();
			Com_ReceiveSignal(Com_REVEIL_PRINCIPAL_BSI_432, (void*) &ISCAN_u8N2F432P214);

			FHCAN432_vidMonInvldP214Update();

			FHCANF432_vidUpdateSignalP214();
		}
		else
		{
			VEMS_vidSET(CoReqVeh_stWkuMain, 0);
			VEMS_vidSET(Ext_stMainWkuReq, 0);

			Ext_bMonRunInvldF432P214 = FHCAN_DISABLE;
			Ext_bDgoInvldF432P214 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bImmoUnlockWkuReq, Local_bCtrl_bImmoUnlockWkuReq);
		if (ACTIVATED == Local_bCtrl_bImmoUnlockWkuReq)
		{
			Com_ReceiveSignal(Com_REVEIL_ANTICIPATION_ADC_BSI_432, (void*) &ISCAN_bF432P216);


			FHCANF432_vidUpdateSignalP216();
		}
		else
		{
			VEMS_vidSET(Ext_bImmoUnlockWkuReq, 0);

		}
		VEMS_vidGET(Ctrl_bEngStopReq, Local_bCtrl_bEngStopReq);
		if (ACTIVATED == Local_bCtrl_bEngStopReq)
		{
			FHCAN432_vidCalcMonFP249Window();
			Com_ReceiveSignal(Com_DDE_COUP_MT_BSI_432, (void*) &ISCAN_u8N2F432P249);

			FHCAN432_vidMonFrbdP249Update();

			FHCANF432_vidUpdateSignalP249();
		}
		else
		{
			VEMS_vidSET(Ext_bEngStopReq, 0);

			Ext_bMonRunFrbdF432P249 = FHCAN_DISABLE;
			Ext_bDgoFrbdF432P249 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bEngStrtReq2, Local_bCtrl_bEngStrtReq2);
		if (ACTIVATED == Local_bCtrl_bEngStrtReq2)
		{
			FHCAN432_vidCalcMonFP251Window();
			Com_ReceiveSignal(Com_DDE_DEM_MAINTENU_2_BSI_432, (void*) &ISCAN_u8N2F432P251);

			FHCAN432_vidMonFrbdP251Update();

			FHCANF432_vidUpdateSignalP251();
		}
		else
		{
			VEMS_vidSET(Ext_bEngStrtReq, 0);

			Ext_bMonRunFrbdF432P251 = FHCAN_DISABLE;
			Ext_bDgoFrbdF432P251 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bAcvSta, Local_bCtrl_bAcvSta);
		if (ACTIVATED == Local_bCtrl_bAcvSta)
		{
			FHCAN432_vidCalcMonFP402Window();
			Com_ReceiveSignal(Com_SEV_DEM_BSI_432, (void*) &ISCAN_u8N2F432P402);

			FHCAN432_vidMonFrbdP402Update();

			FHCANF432_vidUpdateSignalP402();
		}
		else
		{
			VEMS_vidSET(Ext_bAcvSta, 0);

			Ext_bMonRunFrbdF432P402 = FHCAN_DISABLE;
			Ext_bDgoFrbdF432P402 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bPrepIgEngWkuReq, Local_bCtrl_bPrepIgEngWkuReq);
		if (ACTIVATED == Local_bCtrl_bPrepIgEngWkuReq)
		{
			Com_ReceiveSignal(Com_REVEIL_PREPA_DEM_MOT_BSI_432, (void*) &ISCAN_bF432P289);


			FHCANF432_vidUpdateSignalP289();
		}
		else
		{
			VEMS_vidSET(Ext_bPrepIgEngWkuReq, 0);

		}
		VEMS_vidGET(Ctrl_bStopEngCoWkuReq, Local_bCtrl_bStopEngCoWkuReq);
		if (ACTIVATED == Local_bCtrl_bStopEngCoWkuReq)
		{
			Com_ReceiveSignal(Com_REVEIL_POST_VENTIL_MOT_BSI_432, (void*) &ISCAN_bF432P350);


			FHCANF432_vidUpdateSignalP350();
		}
		else
		{
			VEMS_vidSET(Ext_bStopEngCoWkuReq, 0);

		}
		VEMS_vidGET(Ctrl_bTypStrt, Local_bCtrl_bTypStrt);
		if (ACTIVATED == Local_bCtrl_bTypStrt)
		{
			Com_ReceiveSignal(Com_STATUT_DMD_DEM_BSI_432, (void*) &ISCAN_bF432P403);


			FHCANF432_vidUpdateSignalP403();
		}
		else
		{
			VEMS_vidSET(Ext_bTypStrt, 0);

		}
		VEMS_vidGET(Ctrl_noJDD, Local_bCtrl_noJDD);
		if (ACTIVATED == Local_bCtrl_noJDD)
		{
			Com_ReceiveSignal(Com_CTX_JDD_BSI_432, (void*) &ISCAN_u8N6F432P367);


			FHCANF432_vidUpdateSignalP367();
		}
		else
		{
			VEMS_vidSET(Ext_noJDD, 0);

		}
		VEMS_vidGET(Ctrl_bWkuMainSev, Local_bCtrl_bWkuMainSev);
		if (ACTIVATED == Local_bCtrl_bWkuMainSev)
		{
			FHCAN432_vidCalcMonFP368Window();
			Com_ReceiveSignal(Com_ETAT_PRINCIP_SEV_BSI_432, (void*) &ISCAN_u8N2F432P368);

			FHCAN432_vidMonFrbdP368Update();

			FHCANF432_vidUpdateSignalP368();
		}
		else
		{
			VEMS_vidSET(CoReqVeh_stWkuMainSEV, 0);

			Ext_bMonRunFrbdF432P368 = FHCAN_DISABLE;
			Ext_bDgoFrbdF432P368 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stNetwEl, Local_bCtrl_stNetwEl);
		if (ACTIVATED == Local_bCtrl_stNetwEl)
		{
			FHCAN432_vidCalcMonFP369Window();
			Com_ReceiveSignal(Com_ETAT_RESEAU_ELEC_BSI_432, (void*) &ISCAN_u8N4F432P369);

			FHCAN432_vidMonFrbdP369Update();

			FHCANF432_vidUpdateSignalP369();
		}
		else
		{
			VEMS_vidSET(CoReqVeh_stNetwEl, 0);

			Ext_bMonRunFrbdF432P369 = FHCAN_DISABLE;
			Ext_bDgoFrbdF432P369 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bEngStrtReq, Local_bCtrl_bEngStrtReq);
		if (ACTIVATED == Local_bCtrl_bEngStrtReq)
		{
			FHCAN432_vidCalcMonFPM1424Window();
			Com_ReceiveSignal(Com_VOLONTE_DEM_GENE_BSI_432, (void*) &ISCAN_u8N2F432PM1424);

			FHCAN432_vidMonFrbdPM1424Update();

			FHCANF432_vidUpdateSignalPM1424();
		}
		else
		{
			VEMS_vidSET(CoReqVeh_bEngStrtReq, 0);

			Ext_bMonRunFrbdF432PM1424 = FHCAN_DISABLE;
			Ext_bDgoFrbdF432PM1424 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF432 = FHCAN_DISABLE;
		Ext_bMonRunShoF432 = FHCAN_DISABLE;
		Ext_bMonRunInvldF432P214 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432P249 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432P251 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432P402 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432P368 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432P369 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432PM1424 = FHCAN_DISABLE;

		Ext_bDgoMissF432 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF432 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF432P214 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432P249 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432P251 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432P402 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432P368 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432P369 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432PM1424 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF432_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF432P214_in;
	boolean FRM_bAcvRcvF432P249_in;
	boolean FRM_bAcvRcvF432P251_in;
	boolean FRM_bAcvRcvF432P402_in;
	boolean FRM_bAcvRcvF432P368_in;
	boolean FRM_bAcvRcvF432P369_in;
	boolean FRM_bAcvRcvF432PM1424_in;
	boolean FRM_bAcvRcvF432_in;
	boolean Local_bCtrl_BSI_432;
	boolean Local_bCtrl_bOilWkuReq;
	boolean Local_bCtrl_stWkuMain;
	boolean Local_bCtrl_bImmoUnlockWkuReq;
	boolean Local_bCtrl_bEngStopReq;
	boolean Local_bCtrl_bEngStrtReq2;
	boolean Local_bCtrl_bAcvSta;
	boolean Local_bCtrl_bPrepIgEngWkuReq;
	boolean Local_bCtrl_bStopEngCoWkuReq;
	boolean Local_bCtrl_bTypStrt;
	boolean Local_bCtrl_noJDD;
	boolean Local_bCtrl_bWkuMainSev;
	boolean Local_bCtrl_stNetwEl;
	boolean Local_bCtrl_bEngStrtReq;


	VEMS_vidGET(Ctrl_BSI_432, Local_bCtrl_BSI_432);
	if (ACTIVATED == Local_bCtrl_BSI_432)
	{
		FHCAN432_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF432)
      {
         Ext_bDgoMissF432 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF432,
                  Ext_bDgoMissF432,
                  Ext_bMonRunMissF432,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_bOilWkuReq, 0);
		   VEMS_vidSET(CoReqVeh_bOilWkuReq, 0);
		   VEMS_vidSET(CoReqVeh_stWkuMain, 0);
		   VEMS_vidSET(Ext_stMainWkuReq, 0);
		   VEMS_vidSET(Ext_bImmoUnlockWkuReq, 0);
		   VEMS_vidSET(Ext_bEngStopReq, 0);
		   VEMS_vidSET(Ext_bEngStrtReq, 0);
		   VEMS_vidSET(Ext_bAcvSta, 0);
		   VEMS_vidSET(Ext_bPrepIgEngWkuReq, 0);
		   VEMS_vidSET(Ext_bStopEngCoWkuReq, 0);
		   VEMS_vidSET(Ext_bTypStrt, 0);
		   VEMS_vidSET(Ext_noJDD, 0);
		   VEMS_vidSET(CoReqVeh_stWkuMainSEV, 0);
		   VEMS_vidSET(CoReqVeh_stNetwEl, 0);
		   VEMS_vidSET(CoReqVeh_bEngStrtReq, 0);
      }

		FRM_bAcvRcvF432P214_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P214);
		FRM_bAcvRcvF432P249_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P249);
		FRM_bAcvRcvF432P251_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P251);
		FRM_bAcvRcvF432P402_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P402);
		FRM_bAcvRcvF432P368_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P368);
		FRM_bAcvRcvF432P369_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P369);
		FRM_bAcvRcvF432PM1424_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432PM1424);
		FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);

		VEMS_vidGET(Ctrl_bOilWkuReq, Local_bCtrl_bOilWkuReq);
		if (ACTIVATED == Local_bCtrl_bOilWkuReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF432_in)
			{
		      VEMS_vidSET(Ext_bOilWkuReq, Ext_bOilWkuReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stWkuMain, Local_bCtrl_stWkuMain);
		if (ACTIVATED == Local_bCtrl_stWkuMain)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF432P214_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
			{
		      VEMS_vidSET(CoReqVeh_stWkuMain, CoReqVeh_stWkuMainRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bImmoUnlockWkuReq, Local_bCtrl_bImmoUnlockWkuReq);
		if (ACTIVATED == Local_bCtrl_bImmoUnlockWkuReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF432_in)
			{
		      VEMS_vidSET(Ext_bImmoUnlockWkuReq, Ext_bImmoUnlockWkuReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bEngStopReq, Local_bCtrl_bEngStopReq);
		if (ACTIVATED == Local_bCtrl_bEngStopReq)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF432P249_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
			{
		      VEMS_vidSET(Ext_bEngStopReq, Ext_bEngStopReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bEngStrtReq2, Local_bCtrl_bEngStrtReq2);
		if (ACTIVATED == Local_bCtrl_bEngStrtReq2)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF432P251_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
			{
		      VEMS_vidSET(Ext_bEngStrtReq, Ext_bEngStrtReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bAcvSta, Local_bCtrl_bAcvSta);
		if (ACTIVATED == Local_bCtrl_bAcvSta)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF432P402_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
			{
		      VEMS_vidSET(Ext_bAcvSta, Ext_bAcvStaRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bPrepIgEngWkuReq, Local_bCtrl_bPrepIgEngWkuReq);
		if (ACTIVATED == Local_bCtrl_bPrepIgEngWkuReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF432_in)
			{
		      VEMS_vidSET(Ext_bPrepIgEngWkuReq, 0);
			}
		}
		VEMS_vidGET(Ctrl_bStopEngCoWkuReq, Local_bCtrl_bStopEngCoWkuReq);
		if (ACTIVATED == Local_bCtrl_bStopEngCoWkuReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF432_in)
			{
		      VEMS_vidSET(Ext_bStopEngCoWkuReq, 0);
			}
		}
		VEMS_vidGET(Ctrl_bTypStrt, Local_bCtrl_bTypStrt);
		if (ACTIVATED == Local_bCtrl_bTypStrt)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF432_in)
			{
		      VEMS_vidSET(Ext_bTypStrt, Ext_bTypStrtRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_noJDD, Local_bCtrl_noJDD);
		if (ACTIVATED == Local_bCtrl_noJDD)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF432_in)
			{
		      VEMS_vidSET(Ext_noJDD, 0);
			}
		}
		VEMS_vidGET(Ctrl_bWkuMainSev, Local_bCtrl_bWkuMainSev);
		if (ACTIVATED == Local_bCtrl_bWkuMainSev)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF432P368_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
			{
		      VEMS_vidSET(CoReqVeh_stWkuMainSEV, 0);
			}
		}
		VEMS_vidGET(Ctrl_stNetwEl, Local_bCtrl_stNetwEl);
		if (ACTIVATED == Local_bCtrl_stNetwEl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF432P369_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
			{
		      VEMS_vidSET(CoReqVeh_stNetwEl, 0);
			}
		}
		VEMS_vidGET(Ctrl_bEngStrtReq, Local_bCtrl_bEngStrtReq);
		if (ACTIVATED == Local_bCtrl_bEngStrtReq)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF432PM1424_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
			{
		      VEMS_vidSET(CoReqVeh_bEngStrtReq, CoReqVeh_bEngStrtReqRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF432 = FHCAN_DISABLE;
		Ext_bMonRunShoF432 = FHCAN_DISABLE;
		Ext_bMonRunInvldF432P214 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432P249 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432P251 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432P402 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432P368 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432P369 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF432PM1424 = FHCAN_DISABLE;

		Ext_bDgoMissF432 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF432 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF432P214 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432P249 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432P251 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432P402 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432P368 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432P369 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF432PM1424 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF432_vidUpdateSignalP276(void)
{
	boolean FRM_bAcvRcvF432_in;

	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
      VEMS_vidSET(Ext_bOilWkuReq,
                  ISCAN_bF432P276);
      VEMS_vidSET(CoReqVeh_bOilWkuReq,
                  ISCAN_bF432P276);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF432_in)
      {
			VEMS_vidSET(Ext_bOilWkuReq, Ext_bOilWkuReqRcf_C);
		}
	}
}

void FHCANF432_vidUpdateSignalP214(void)
{
	boolean FRM_bAcvRcvF432P214_in;
	boolean FRM_bAcvRcvF432_in;
   uint8 u8LocalCoReqVeh_stWkuMain;

	FRM_bAcvRcvF432P214_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P214);
	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432P214_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF432P214)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
      u8LocalCoReqVeh_stWkuMain = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F432P214,
                                             2));
      VEMS_vidSET(CoReqVeh_stWkuMain,
                  u8LocalCoReqVeh_stWkuMain);
		if (ISCAN_u8N2F432P214 == 1)
		{
         VEMS_vidSET(Ext_stMainWkuReq, 1);
		}
		else
		{
			if (ISCAN_u8N2F432P214 == 2)
			{
            VEMS_vidSET(Ext_stMainWkuReq, 2);
			}
			else
			{
            VEMS_vidSET(Ext_stMainWkuReq, 0);
			}
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF432P214_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
      {
			VEMS_vidSET(CoReqVeh_stWkuMain, CoReqVeh_stWkuMainRcf_C);
		}
	}
}

void FHCANF432_vidUpdateSignalP216(void)
{
	boolean FRM_bAcvRcvF432_in;

	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
      VEMS_vidSET(Ext_bImmoUnlockWkuReq,
                  ISCAN_bF432P216);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF432_in)
      {
			VEMS_vidSET(Ext_bImmoUnlockWkuReq, Ext_bImmoUnlockWkuReqRcf_C);
		}
	}
}

void FHCANF432_vidUpdateSignalP249(void)
{
	boolean FRM_bAcvRcvF432P249_in;
	boolean FRM_bAcvRcvF432_in;

	FRM_bAcvRcvF432P249_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P249);
	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432P249_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF432P249)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
		if (ISCAN_u8N2F432P249 == 1)
		{
         VEMS_vidSET(Ext_bEngStopReq, 0);
		}
		else
		{
			if (ISCAN_u8N2F432P249 == 2)
			{
            VEMS_vidSET(Ext_bEngStopReq, 1);
			}
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF432P249_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
      {
			VEMS_vidSET(Ext_bEngStopReq, Ext_bEngStopReqRcf_C);
		}
	}
}

void FHCANF432_vidUpdateSignalP251(void)
{
	boolean FRM_bAcvRcvF432P251_in;
	boolean FRM_bAcvRcvF432_in;

	FRM_bAcvRcvF432P251_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P251);
	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432P251_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF432P251)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
		if (ISCAN_u8N2F432P251 == 1)
		{
         VEMS_vidSET(Ext_bEngStrtReq, 0);
		}
		else
		{
			if (ISCAN_u8N2F432P251 == 2)
			{
            VEMS_vidSET(Ext_bEngStrtReq, 1);
			}
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF432P251_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
      {
			VEMS_vidSET(Ext_bEngStrtReq, Ext_bEngStrtReqRcf_C);
		}
	}
}

void FHCANF432_vidUpdateSignalP402(void)
{
	boolean FRM_bAcvRcvF432P402_in;
	boolean FRM_bAcvRcvF432_in;

	FRM_bAcvRcvF432P402_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P402);
	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432P402_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF432P402)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
		if (ISCAN_u8N2F432P402 == 1)
		{
         VEMS_vidSET(Ext_bAcvSta, 0);
		}
		else
		{
			if (ISCAN_u8N2F432P402 == 2)
			{
            VEMS_vidSET(Ext_bAcvSta, 1);
			}
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF432P402_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
      {
			VEMS_vidSET(Ext_bAcvSta, Ext_bAcvStaRcf_C);
		}
	}
}

void FHCANF432_vidUpdateSignalP289(void)
{
	boolean FRM_bAcvRcvF432_in;

	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
      VEMS_vidSET(Ext_bPrepIgEngWkuReq,
                  ISCAN_bF432P289);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF432_in)
      {
			VEMS_vidSET(Ext_bPrepIgEngWkuReq, 0);
		}
	}
}

void FHCANF432_vidUpdateSignalP350(void)
{
	boolean FRM_bAcvRcvF432_in;

	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
      VEMS_vidSET(Ext_bStopEngCoWkuReq,
                  ISCAN_bF432P350);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF432_in)
      {
			VEMS_vidSET(Ext_bStopEngCoWkuReq, 0);
		}
	}
}

void FHCANF432_vidUpdateSignalP403(void)
{
	boolean FRM_bAcvRcvF432_in;

	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
      VEMS_vidSET(Ext_bTypStrt,
                  ISCAN_bF432P403);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF432_in)
      {
			VEMS_vidSET(Ext_bTypStrt, Ext_bTypStrtRcf_C);
		}
	}
}

void FHCANF432_vidUpdateSignalP367(void)
{
	boolean FRM_bAcvRcvF432_in;
   uint8 u8LocalExt_noJDD;

	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
      u8LocalExt_noJDD = (uint8)(MATHSRV_udtMIN(ISCAN_u8N6F432P367,
                                             7));
      VEMS_vidSET(Ext_noJDD,
                  u8LocalExt_noJDD);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF432_in)
      {
			VEMS_vidSET(Ext_noJDD, 0);
		}
	}
}

void FHCANF432_vidUpdateSignalP368(void)
{
	boolean FRM_bAcvRcvF432P368_in;
	boolean FRM_bAcvRcvF432_in;
   uint8 u8LocalCoReqVeh_stWkuMainSEV;

	FRM_bAcvRcvF432P368_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P368);
	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432P368_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF432P368)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
      u8LocalCoReqVeh_stWkuMainSEV = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F432P368,
                                             3));
      VEMS_vidSET(CoReqVeh_stWkuMainSEV,
                  u8LocalCoReqVeh_stWkuMainSEV);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF432P368_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
      {
			VEMS_vidSET(CoReqVeh_stWkuMainSEV, 0);
		}
	}
}

void FHCANF432_vidUpdateSignalP369(void)
{
	boolean FRM_bAcvRcvF432P369_in;
	boolean FRM_bAcvRcvF432_in;
   uint8 u8LocalCoReqVeh_stNetwEl;

	FRM_bAcvRcvF432P369_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432P369);
	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432P369_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF432P369)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
      u8LocalCoReqVeh_stNetwEl = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F432P369,
                                             15));
      VEMS_vidSET(CoReqVeh_stNetwEl,
                  u8LocalCoReqVeh_stNetwEl);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF432P369_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
      {
			VEMS_vidSET(CoReqVeh_stNetwEl, 0);
		}
	}
}

void FHCANF432_vidUpdateSignalPM1424(void)
{
	boolean FRM_bAcvRcvF432PM1424_in;
	boolean FRM_bAcvRcvF432_in;

	FRM_bAcvRcvF432PM1424_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432PM1424);
	FRM_bAcvRcvF432_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF432);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF432PM1424_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF432_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF432PM1424)
	   && (FHCAN_DETECTED != Ext_bDgoShoF432)
	   )
	{
		if (ISCAN_u8N2F432PM1424 == 1)
		{
         VEMS_vidSET(CoReqVeh_bEngStrtReq, 1);
		}
		else
		{
			if (ISCAN_u8N2F432PM1424 == 2)
			{
            VEMS_vidSET(CoReqVeh_bEngStrtReq, 0);
			}
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF432PM1424_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF432_in))
      {
			VEMS_vidSET(CoReqVeh_bEngStrtReq, CoReqVeh_bEngStrtReqRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

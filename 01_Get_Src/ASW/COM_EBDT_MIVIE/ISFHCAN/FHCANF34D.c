/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF34D.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF34D.H"
#include "FHCANF34D_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_34D(void)
{
	ISCAN_bF34DP147 = 0;
	ISCAN_u8N3F34DP047 = 0;
	ISCAN_u8N8F34DP043 = 250;
	ISCAN_u8N8F34DP044 = 250;
	ISCAN_u8N8F34DP045 = 0;
	ISCAN_u8N2F34DFP0593 = 0;
	ISCAN_u8N4F34DP157 = 0;
	ISCAN_bF34DP624 = 0;
	ISCAN_bF34DP353 = 0;
	ISCAN_bF34DP352 = 0;
	ISCAN_u8N6F34DPM1413 = 60;

	VEMS_vidSET(Cha_tqRevAcv, 0);
	VEMS_vidSET(Ext_stTqReq, 0);
	VEMS_vidSET(Ext_tqAirASRReq, 250);
	VEMS_vidSET(Ext_tqDynASRReq, 250);
	VEMS_vidSET(Ext_tqMSRReq, 0);
	VEMS_vidSET(Ext_stHillAsi, 0);
	VEMS_vidSET(Cha_stHillAsi, 0);
	VEMS_vidSET(Ext_ctClcProc34D, 0);
	VEMS_vidSET(Ext_bLiRegESPASR, 0);
	VEMS_vidSET(Ext_bESPRegFirst, 0);
	VEMS_vidSET(Ext_bESPReg, 0);
	VEMS_vidSET(Ext_bASRRegFirst, 0);
	VEMS_vidSET(Ext_bASRReg, 0);
	VEMS_vidSET(CoReqCha_rSlopStab, 30);
	VEMS_vidSET(CoReqCha_bUncrtSlopStab, 30);
	VEMS_vidSET(Ext_bNotAvl_rSlopStab, AVAILABLE);

	Ext_bMonRunMissF34D = FHCAN_DISABLE;
	Ext_bMonRunShoF34D = FHCAN_DISABLE;
	Ext_bMonRunFrbdF34DP047 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF34DP043 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF34DP044 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF34DP045 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF34DFP0593 = FHCAN_DISABLE;
	Ext_bMonRunInvldF34DFP0593 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF34DPM1413 = FHCAN_DISABLE;
	Ext_bMonRunInvldF34DPM1413 = FHCAN_DISABLE;

	Ext_bDgoMissF34D = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF34D = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF34DP047 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF34DP043 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF34DP044 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF34DP045 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF34DFP0593 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF34DFP0593 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF34DPM1413 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF34DPM1413 = FHCAN_NOT_DETECTED;
}

void FHCANF34D_vidFrameReceived(void)
{
	boolean Local_bCtrl_CDS_34D;
	boolean Local_bCtrl_tqRevAcv;
	boolean Local_bCtrl_bAcv_stTqReq;
	boolean Local_bCtrl_tqAirASRReq;
	boolean Local_bCtrl_tqDynASRReq;
	boolean Local_bCtrl_tqMSRReq;
	boolean Local_bCtrl_stHillAsi;
	boolean Local_bCtrl_ctClcProc34D;
	boolean Local_bCtrl_bAcv_bLiRegESPASR;
	boolean Local_bCtrl_bESPRegFirst;
	boolean Local_bCtrl_bASRRegFirst;
	boolean Local_bCtrl_rSlopStab;

	VEMS_vidGET(Ctrl_CDS_34D, Local_bCtrl_CDS_34D);
	if (ACTIVATED == Local_bCtrl_CDS_34D)
	{
		ISCAN_EveRxn_34D();
		FHCAN34D_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF34D)
      {
         Ext_bDgoMissF34D = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF34D,
                  Ext_bDgoMissF34D,
                  Ext_bMonRunMissF34D,
                  DIAG_DISPO);
      }
            
		if (FHCAN_ENABLE == Ext_bMonRunCntF34D)
      {
         Ext_bDgoCntF34D = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF34D,
                  Ext_bDgoCntF34D,
                  Ext_bMonRunCntF34D,
                  DIAG_DISPO);
      }

		VEMS_vidGET(Ctrl_tqRevAcv, Local_bCtrl_tqRevAcv);
		if (ACTIVATED == Local_bCtrl_tqRevAcv)
		{
			Com_ReceiveSignal(Com_REGUL_ESP_CDS_34D, (void*) &ISCAN_bF34DP147);


			FHCANF34D_vidUpdateSignalP147();
		}
		else
		{
			VEMS_vidSET(Cha_tqRevAcv, 0);

		}
		VEMS_vidGET(Ctrl_bAcv_stTqReq, Local_bCtrl_bAcv_stTqReq);
		if (ACTIVATED == Local_bCtrl_bAcv_stTqReq)
		{
			FHCAN34D_vidCalcMonFP047Window();
			Com_ReceiveSignal(Com_TYPE_PIL_CPLE_ESP_CDS_34D, (void*) &ISCAN_u8N3F34DP047);

			FHCAN34D_vidMonFrbdP047Update();

			FHCANF34D_vidUpdateSignalP047();
		}
		else
		{
			VEMS_vidSET(Ext_stTqReq, 0);

			Ext_bMonRunFrbdF34DP047 = FHCAN_DISABLE;
			Ext_bDgoFrbdF34DP047 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_tqAirASRReq, Local_bCtrl_tqAirASRReq);
		if (ACTIVATED == Local_bCtrl_tqAirASRReq)
		{
			FHCAN34D_vidCalcMonFP043Window();
			Com_ReceiveSignal(Com_CNS_CPLE_STAT_ASR_CDS_34D, (void*) &ISCAN_u8N8F34DP043);

			FHCAN34D_vidMonFrbdP043Update();

			FHCANF34D_vidUpdateSignalP043();
		}
		else
		{
			VEMS_vidSET(Ext_tqAirASRReq, 250);

			Ext_bMonRunFrbdF34DP043 = FHCAN_DISABLE;
			Ext_bDgoFrbdF34DP043 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_tqDynASRReq, Local_bCtrl_tqDynASRReq);
		if (ACTIVATED == Local_bCtrl_tqDynASRReq)
		{
			FHCAN34D_vidCalcMonFP044Window();
			Com_ReceiveSignal(Com_CNS_CPLE_DYN_ASR_CDS_34D, (void*) &ISCAN_u8N8F34DP044);

			FHCAN34D_vidMonFrbdP044Update();

			FHCANF34D_vidUpdateSignalP044();
		}
		else
		{
			VEMS_vidSET(Ext_tqDynASRReq, 250);

			Ext_bMonRunFrbdF34DP044 = FHCAN_DISABLE;
			Ext_bDgoFrbdF34DP044 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_tqMSRReq, Local_bCtrl_tqMSRReq);
		if (ACTIVATED == Local_bCtrl_tqMSRReq)
		{
			FHCAN34D_vidCalcMonFP045Window();
			Com_ReceiveSignal(Com_CNS_CPLE_MSR_CDS_34D, (void*) &ISCAN_u8N8F34DP045);

			FHCAN34D_vidMonFrbdP045Update();

			FHCANF34D_vidUpdateSignalP045();
		}
		else
		{
			VEMS_vidSET(Ext_tqMSRReq, 0);

			Ext_bMonRunFrbdF34DP045 = FHCAN_DISABLE;
			Ext_bDgoFrbdF34DP045 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stHillAsi, Local_bCtrl_stHillAsi);
		if (ACTIVATED == Local_bCtrl_stHillAsi)
		{
			FHCAN34D_vidCalcMonFFP0593Window();
			Com_ReceiveSignal(Com_ETAT_FNCT_HILL_ASSIST_CDS_34D, (void*) &ISCAN_u8N2F34DFP0593);

			FHCAN34D_vidMonInvldFP0593Update();
			FHCAN34D_vidMonFrbdFP0593Update();

			FHCANF34D_vidUpdateSignalFP0593();
		}
		else
		{
			VEMS_vidSET(Ext_stHillAsi, 0);
			VEMS_vidSET(Cha_stHillAsi, 0);

			Ext_bMonRunFrbdF34DFP0593 = FHCAN_DISABLE;
			Ext_bMonRunInvldF34DFP0593 = FHCAN_DISABLE;
			Ext_bDgoFrbdF34DFP0593 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF34DFP0593 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_ctClcProc34D, Local_bCtrl_ctClcProc34D);
		if (ACTIVATED == Local_bCtrl_ctClcProc34D)
		{
			Com_ReceiveSignal(Com_CPT_PROCESS_4B_ESP_CDS_34D, (void*) &ISCAN_u8N4F34DP157);


			FHCANF34D_vidUpdateSignalP157();
		}
		else
		{
			VEMS_vidSET(Ext_ctClcProc34D, 0);

		}
		VEMS_vidGET(Ctrl_bAcv_bLiRegESPASR, Local_bCtrl_bAcv_bLiRegESPASR);
		if (ACTIVATED == Local_bCtrl_bAcv_bLiRegESPASR)
		{
			Com_ReceiveSignal(Com_REQ_LAMPE_REGUL_ASR_ESP_CDS_34D, (void*) &ISCAN_bF34DP624);


			FHCANF34D_vidUpdateSignalP624();
		}
		else
		{
			VEMS_vidSET(Ext_bLiRegESPASR, 0);

		}
		VEMS_vidGET(Ctrl_bESPRegFirst, Local_bCtrl_bESPRegFirst);
		if (ACTIVATED == Local_bCtrl_bESPRegFirst)
		{
			Com_ReceiveSignal(Com_REGUL_ESP_SEUL_CDS_34D, (void*) &ISCAN_bF34DP353);


			FHCANF34D_vidUpdateSignalP353();
		}
		else
		{
			VEMS_vidSET(Ext_bESPRegFirst, 0);
			VEMS_vidSET(Ext_bESPReg, 0);

		}
		VEMS_vidGET(Ctrl_bASRRegFirst, Local_bCtrl_bASRRegFirst);
		if (ACTIVATED == Local_bCtrl_bASRRegFirst)
		{
			Com_ReceiveSignal(Com_REGUL_ASR_CDS_34D, (void*) &ISCAN_bF34DP352);


			FHCANF34D_vidUpdateSignalP352();
		}
		else
		{
			VEMS_vidSET(Ext_bASRRegFirst, 0);
			VEMS_vidSET(Ext_bASRReg, 0);

		}
		VEMS_vidGET(Ctrl_rSlopStab, Local_bCtrl_rSlopStab);
		if (ACTIVATED == Local_bCtrl_rSlopStab)
		{
			FHCAN34D_vidCalcMonFPM1413Window();
			Com_ReceiveSignal(Com_PENTE_STATIQUE_CDS_34D, (void*) &ISCAN_u8N6F34DPM1413);

			FHCAN34D_vidMonInvldPM1413Update();
			FHCAN34D_vidMonFrbdPM1413Update();

			FHCANF34D_vidUpdateSignalPM1413();
		}
		else
		{
			VEMS_vidSET(CoReqCha_rSlopStab, 30);
			VEMS_vidSET(CoReqCha_bUncrtSlopStab, 30);
			VEMS_vidSET(Ext_bNotAvl_rSlopStab, AVAILABLE);
			Ext_bMonRunFrbdF34DPM1413 = FHCAN_DISABLE;
			Ext_bMonRunInvldF34DPM1413 = FHCAN_DISABLE;
			Ext_bDgoFrbdF34DPM1413 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF34DPM1413 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF34D = FHCAN_DISABLE;
		Ext_bMonRunShoF34D = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DP047 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DP043 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DP044 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DP045 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DFP0593 = FHCAN_DISABLE;
		Ext_bMonRunInvldF34DFP0593 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DPM1413 = FHCAN_DISABLE;
		Ext_bMonRunInvldF34DPM1413 = FHCAN_DISABLE;

		Ext_bDgoMissF34D = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF34D = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DP047 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DP043 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DP044 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DP045 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DFP0593 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF34DFP0593 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DPM1413 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF34DPM1413 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF34D_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF34DP047_in;
	boolean FRM_bAcvRcvF34DP043_in;
	boolean FRM_bAcvRcvF34DP044_in;
	boolean FRM_bAcvRcvF34DP045_in;
	boolean FRM_bAcvRcvF34DFP0593_in;
	boolean FRM_bAcvRcvF34DPM1413_in;
	boolean FRM_bAcvRcvF34D_in;
	boolean Local_bCtrl_CDS_34D;
	boolean Local_bCtrl_tqRevAcv;
	boolean Local_bCtrl_bAcv_stTqReq;
	boolean Local_bCtrl_tqAirASRReq;
	boolean Local_bCtrl_tqDynASRReq;
	boolean Local_bCtrl_tqMSRReq;
	boolean Local_bCtrl_stHillAsi;
	boolean Local_bCtrl_ctClcProc34D;
	boolean Local_bCtrl_bAcv_bLiRegESPASR;
	boolean Local_bCtrl_bESPRegFirst;
	boolean Local_bCtrl_bASRRegFirst;
	boolean Local_bCtrl_rSlopStab;
	uint8 Local_Ext_ctClcProc34D;
	boolean Local_Ext_bLiRegESPASR;


	VEMS_vidGET(Ctrl_CDS_34D, Local_bCtrl_CDS_34D);
	if (ACTIVATED == Local_bCtrl_CDS_34D)
	{
		FHCAN34D_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF34D)
      {
         Ext_bDgoMissF34D = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF34D,
                  Ext_bDgoMissF34D,
                  Ext_bMonRunMissF34D,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Cha_tqRevAcv, 0);
		   VEMS_vidSET(Ext_stTqReq, 0);
		   VEMS_vidSET(Ext_tqAirASRReq, 250);
		   VEMS_vidSET(Ext_tqDynASRReq, 250);
		   VEMS_vidSET(Ext_tqMSRReq, 0);
		   VEMS_vidSET(Ext_stHillAsi, 0);
		   VEMS_vidSET(Cha_stHillAsi, 0);
		   VEMS_vidSET(Ext_ctClcProc34D, 0);
		   VEMS_vidSET(Ext_bLiRegESPASR, 0);
		   VEMS_vidSET(Ext_bESPRegFirst, 0);
		   VEMS_vidSET(Ext_bESPReg, 0);
		   VEMS_vidSET(Ext_bASRRegFirst, 0);
		   VEMS_vidSET(Ext_bASRReg, 0);
		   VEMS_vidSET(CoReqCha_rSlopStab, 30);
		   VEMS_vidSET(CoReqCha_bUncrtSlopStab, 30);
		   VEMS_vidSET(Ext_bNotAvl_rSlopStab, AVAILABLE);
      }

		FRM_bAcvRcvF34DP047_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DP047);
		FRM_bAcvRcvF34DP043_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DP043);
		FRM_bAcvRcvF34DP044_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DP044);
		FRM_bAcvRcvF34DP045_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DP045);
		FRM_bAcvRcvF34DFP0593_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DFP0593);
		FRM_bAcvRcvF34DPM1413_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DPM1413);
		FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);

		VEMS_vidGET(Ctrl_tqRevAcv, Local_bCtrl_tqRevAcv);
		if (ACTIVATED == Local_bCtrl_tqRevAcv)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF34D_in)
			{
		      VEMS_vidSET(Cha_tqRevAcv, Cha_tqRevAcvRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_stTqReq, Local_bCtrl_bAcv_stTqReq);
		if (ACTIVATED == Local_bCtrl_bAcv_stTqReq)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF34DP047_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
			{
		      VEMS_vidSET(Ext_stTqReq, Ext_stTqReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_tqAirASRReq, Local_bCtrl_tqAirASRReq);
		if (ACTIVATED == Local_bCtrl_tqAirASRReq)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF34DP043_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
			{
		      VEMS_vidSET(Ext_tqAirASRReq, Ext_tqAirASRReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_tqDynASRReq, Local_bCtrl_tqDynASRReq);
		if (ACTIVATED == Local_bCtrl_tqDynASRReq)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF34DP044_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
			{
		      VEMS_vidSET(Ext_tqDynASRReq, Ext_tqDynASRReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_tqMSRReq, Local_bCtrl_tqMSRReq);
		if (ACTIVATED == Local_bCtrl_tqMSRReq)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF34DP045_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
			{
		      VEMS_vidSET(Ext_tqMSRReq, Ext_tqMSRReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stHillAsi, Local_bCtrl_stHillAsi);
		if (ACTIVATED == Local_bCtrl_stHillAsi)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF34DFP0593_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
			{
		      VEMS_vidSET(Ext_stHillAsi, Ext_stHillAsiRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_ctClcProc34D, Local_bCtrl_ctClcProc34D);
		if (ACTIVATED == Local_bCtrl_ctClcProc34D)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF34D_in)
			{
		      VEMS_vidGET(Ext_ctClcProc34D, Local_Ext_ctClcProc34D);
		      VEMS_vidSET(Ext_ctClcProc34D, Local_Ext_ctClcProc34D);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_bLiRegESPASR, Local_bCtrl_bAcv_bLiRegESPASR);
		if (ACTIVATED == Local_bCtrl_bAcv_bLiRegESPASR)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF34D_in)
			{
		      VEMS_vidGET(Ext_bLiRegESPASR, Local_Ext_bLiRegESPASR);
		      VEMS_vidSET(Ext_bLiRegESPASR, Local_Ext_bLiRegESPASR);
			}
		}
		VEMS_vidGET(Ctrl_bESPRegFirst, Local_bCtrl_bESPRegFirst);
		if (ACTIVATED == Local_bCtrl_bESPRegFirst)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF34D_in)
			{
		      VEMS_vidSET(Ext_bESPRegFirst, Ext_bESPRegFirstRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bASRRegFirst, Local_bCtrl_bASRRegFirst);
		if (ACTIVATED == Local_bCtrl_bASRRegFirst)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF34D_in)
			{
		      VEMS_vidSET(Ext_bASRRegFirst, Ext_bASRRegFirstRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_rSlopStab, Local_bCtrl_rSlopStab);
		if (ACTIVATED == Local_bCtrl_rSlopStab)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF34DPM1413_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
			{
		      VEMS_vidSET(CoReqCha_rSlopStab, CoReqCha_rSlopStabRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF34D = FHCAN_DISABLE;
		Ext_bMonRunShoF34D = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DP047 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DP043 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DP044 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DP045 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DFP0593 = FHCAN_DISABLE;
		Ext_bMonRunInvldF34DFP0593 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF34DPM1413 = FHCAN_DISABLE;
		Ext_bMonRunInvldF34DPM1413 = FHCAN_DISABLE;

		Ext_bDgoMissF34D = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF34D = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DP047 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DP043 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DP044 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DP045 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DFP0593 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF34DFP0593 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF34DPM1413 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF34DPM1413 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF34D_vidUpdateSignalP147(void)
{
	boolean FRM_bAcvRcvF34D_in;

	FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF34D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF34D)
	   )
	{
      VEMS_vidSET(Cha_tqRevAcv,
                  ISCAN_bF34DP147);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF34D_in)
      {
			VEMS_vidSET(Cha_tqRevAcv, Cha_tqRevAcvRcf_C);
		}
	}
}

void FHCANF34D_vidUpdateSignalP047(void)
{
	boolean FRM_bAcvRcvF34DP047_in;
	boolean FRM_bAcvRcvF34D_in;
   uint8 u8LocalExt_stTqReq;

	FRM_bAcvRcvF34DP047_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DP047);
	FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF34DP047_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF34D_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF34DP047)
	   && (FHCAN_DETECTED != Ext_bDgoShoF34D)
	   )
	{
      u8LocalExt_stTqReq = (uint8)(MATHSRV_udtMIN(ISCAN_u8N3F34DP047,
                                             7));
      VEMS_vidSET(Ext_stTqReq,
                  u8LocalExt_stTqReq);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF34DP047_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
      {
			VEMS_vidSET(Ext_stTqReq, Ext_stTqReqRcf_C);
		}
	}
}

void FHCANF34D_vidUpdateSignalP043(void)
{
	boolean FRM_bAcvRcvF34DP043_in;
	boolean FRM_bAcvRcvF34D_in;
   uint8 u8LocalExt_tqAirASRReq;

	FRM_bAcvRcvF34DP043_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DP043);
	FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF34DP043_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF34D_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF34DP043)
	   && (FHCAN_DETECTED != Ext_bDgoShoF34D)
	   )
	{
      u8LocalExt_tqAirASRReq = (uint8)(MATHSRV_udtMIN(ISCAN_u8N8F34DP043,
                                             250));
      VEMS_vidSET(Ext_tqAirASRReq,
                  u8LocalExt_tqAirASRReq);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF34DP043_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
      {
			VEMS_vidSET(Ext_tqAirASRReq, Ext_tqAirASRReqRcf_C);
		}
	}
}

void FHCANF34D_vidUpdateSignalP044(void)
{
	boolean FRM_bAcvRcvF34DP044_in;
	boolean FRM_bAcvRcvF34D_in;
   uint8 u8LocalExt_tqDynASRReq;

	FRM_bAcvRcvF34DP044_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DP044);
	FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF34DP044_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF34D_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF34DP044)
	   && (FHCAN_DETECTED != Ext_bDgoShoF34D)
	   )
	{
      u8LocalExt_tqDynASRReq = (uint8)(MATHSRV_udtMIN(ISCAN_u8N8F34DP044,
                                             250));
      VEMS_vidSET(Ext_tqDynASRReq,
                  u8LocalExt_tqDynASRReq);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF34DP044_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
      {
			VEMS_vidSET(Ext_tqDynASRReq, Ext_tqDynASRReqRcf_C);
		}
	}
}

void FHCANF34D_vidUpdateSignalP045(void)
{
	boolean FRM_bAcvRcvF34DP045_in;
	boolean FRM_bAcvRcvF34D_in;
   uint8 u8LocalExt_tqMSRReq;

	FRM_bAcvRcvF34DP045_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DP045);
	FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF34DP045_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF34D_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF34DP045)
	   && (FHCAN_DETECTED != Ext_bDgoShoF34D)
	   )
	{
      u8LocalExt_tqMSRReq = (uint8)(MATHSRV_udtMIN(ISCAN_u8N8F34DP045,
                                             250));
      VEMS_vidSET(Ext_tqMSRReq,
                  u8LocalExt_tqMSRReq);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF34DP045_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
      {
			VEMS_vidSET(Ext_tqMSRReq, Ext_tqMSRReqRcf_C);
		}
	}
}

void FHCANF34D_vidUpdateSignalFP0593(void)
{
	boolean FRM_bAcvRcvF34DFP0593_in;
	boolean FRM_bAcvRcvF34D_in;
   uint8 u8LocalExt_stHillAsi;

	FRM_bAcvRcvF34DFP0593_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DFP0593);
	FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF34DFP0593_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF34D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF34DFP0593)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF34DFP0593)
	   && (FHCAN_DETECTED != Ext_bDgoShoF34D)
	   )
	{
      u8LocalExt_stHillAsi = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F34DFP0593,
                                             3));
      VEMS_vidSET(Ext_stHillAsi,
                  u8LocalExt_stHillAsi);
		switch (ISCAN_u8N2F34DFP0593)
		{
		case 0:
      VEMS_vidSET(Cha_stHillAsi, 1);
         break;

		case 1:
      VEMS_vidSET(Cha_stHillAsi, 0);
         break;

		case 3:
      VEMS_vidSET(Cha_stHillAsi, 2);
         break;

		default:
         
        break;
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF34DFP0593_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
      {
			VEMS_vidSET(Ext_stHillAsi, Ext_stHillAsiRcf_C);
		}
	}
}

void FHCANF34D_vidUpdateSignalP157(void)
{
	boolean FRM_bAcvRcvF34D_in;
   uint8 u8LocalExt_ctClcProc34D;

	uint8 Local_Ext_ctClcProc34D;

	FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF34D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF34D)
	   )
	{
      u8LocalExt_ctClcProc34D = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F34DP157,
                                             15));
      VEMS_vidSET(Ext_ctClcProc34D,
                  u8LocalExt_ctClcProc34D);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF34D_in)
      {
			VEMS_vidGET(Ext_ctClcProc34D, Local_Ext_ctClcProc34D);
			VEMS_vidSET(Ext_ctClcProc34D, Local_Ext_ctClcProc34D);
		}
	}
}

void FHCANF34D_vidUpdateSignalP624(void)
{
	boolean FRM_bAcvRcvF34D_in;

	boolean Local_Ext_bLiRegESPASR;

	FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF34D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF34D)
	   )
	{
      VEMS_vidSET(Ext_bLiRegESPASR,
                  ISCAN_bF34DP624);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF34D_in)
      {
			VEMS_vidGET(Ext_bLiRegESPASR, Local_Ext_bLiRegESPASR);
			VEMS_vidSET(Ext_bLiRegESPASR, Local_Ext_bLiRegESPASR);
		}
	}
}

void FHCANF34D_vidUpdateSignalP353(void)
{
	boolean FRM_bAcvRcvF34D_in;

	FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF34D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF34D)
	   )
	{
      VEMS_vidSET(Ext_bESPRegFirst,
                  ISCAN_bF34DP353);
      VEMS_vidSET(Ext_bESPReg,
                  ISCAN_bF34DP353);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF34D_in)
      {
			VEMS_vidSET(Ext_bESPRegFirst, Ext_bESPRegFirstRcf_C);
		}
	}
}

void FHCANF34D_vidUpdateSignalP352(void)
{
	boolean FRM_bAcvRcvF34D_in;

	FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF34D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF34D)
	   )
	{
      VEMS_vidSET(Ext_bASRRegFirst,
                  ISCAN_bF34DP352);
      VEMS_vidSET(Ext_bASRReg,
                  ISCAN_bF34DP352);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF34D_in)
      {
			VEMS_vidSET(Ext_bASRRegFirst, Ext_bASRRegFirstRcf_C);
		}
	}
}

void FHCANF34D_vidUpdateSignalPM1413(void)
{
	boolean FRM_bAcvRcvF34DPM1413_in;
	boolean FRM_bAcvRcvF34D_in;
   sint16 s16LocalIscanCDS_34D;
   sint8 s8LocalCoReqCha_rSlopStab;

   if (ISCAN_u8N6F34DPM1413 == 62)
	{
		VEMS_vidSET(Ext_bNotAvl_rSlopStab, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_rSlopStab, AVAILABLE);
	}

	FRM_bAcvRcvF34DPM1413_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34DPM1413);
	FRM_bAcvRcvF34D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF34D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF34DPM1413_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF34D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF34DPM1413)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF34DPM1413)
	   && (FHCAN_DETECTED != Ext_bDgoShoF34D)
	   )
	{
      s16LocalIscanCDS_34D = (sint16)((ISCAN_u8N6F34DPM1413) - 30);
      s8LocalCoReqCha_rSlopStab = (sint8)(MATHSRV_udtCLAMP(s16LocalIscanCDS_34D,
                                               -30,
                                               30));
      VEMS_vidSET(CoReqCha_rSlopStab,
                  s8LocalCoReqCha_rSlopStab);
		if (ISCAN_u8N6F34DPM1413 == 0x3E) 
        {
         VEMS_vidSET(CoReqCha_bUncrtSlopStab, 1);
		}
		else
		{
         VEMS_vidSET(CoReqCha_bUncrtSlopStab, 0);
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF34DPM1413_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF34D_in))
      {
			VEMS_vidSET(CoReqCha_rSlopStab, CoReqCha_rSlopStabRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

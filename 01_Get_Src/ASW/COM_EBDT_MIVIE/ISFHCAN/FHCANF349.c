/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF349.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF349.H"
#include "FHCANF349_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_349(void)
{
	ISCAN_bF349PM1433 = 0;
	ISCAN_u8N3F349P360 = 3;
	ISCAN_u8N2F349P030 = 3;
	ISCAN_u8N8F349P057 = 50;
	ISCAN_bF349P361 = 0;
	ISCAN_bF349P167 = 0;
	ISCAN_bF349P085 = 0;
	ISCAN_u8N2F349P087 = 3;
	ISCAN_bF349P362 = 0;
	ISCAN_bF349P009 = 0;
	ISCAN_u8N4F349P008 = 0;
	ISCAN_u8N4F349P007 = 15;
	ISCAN_u8N8F349P055 = 50;
	ISCAN_u8N4F349P287 = 15;
	ISCAN_u8N2F349PM1434 = 0;
	ISCAN_u8N2F349PM1435 = 0;
	ISCAN_u8N4F349PM2853 = 0;
	ISCAN_u8N4F349PM2842 = 0;
	ISCAN_u8N8F349P166 = 0;

	VEMS_vidSET(Can_bTqTx, 0);
	VEMS_vidSET(Can_stGSTyp, 3);
	VEMS_vidSET(CoPt_stSIPTyp, 3);
	VEMS_vidSET(Can_stDragRed, 3);
	VEMS_vidSET(Can_tqReqGBx, 0);
	VEMS_vidSET(Can_stNRegTyp, 0);
	VEMS_vidSET(Can_bNRegReq, 0);
	VEMS_vidSET(Can_bFrzAC, 0);
	VEMS_vidSET(Can_stCnvClu, 3);
	VEMS_vidSET(Can_bSIPPrep, 0);
	VEMS_vidSET(Can_bSIP, 0);
	VEMS_vidSET(Can_noTarGear, 0);
	VEMS_vidSET(Ext_noGearTar, 0);
	VEMS_vidSET(Can_posnATLev, 15);
	VEMS_vidSET(Can_stPosATLevExtdCAN, 15);
	VEMS_vidSET(Can_tqMaxGBx, 0);
	VEMS_vidSET(Can_noEgdGear, 15);
	VEMS_vidSET(Can_stGearRat, 0);
	VEMS_vidSET(Can_stCpl, 0);
	VEMS_vidSET(Ext_noCks349, 0);
	VEMS_vidSET(Ext_ctClcProc349, 0);
	VEMS_vidSET(Can_nTar, 3000);
	VEMS_vidSET(Ext_bNotAvl_nTar, AVAILABLE);

	Ext_bMonRunMissF349 = FHCAN_DISABLE;
	Ext_bMonRunShoF349 = FHCAN_DISABLE;
	Ext_bMonRunChkF349 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF349P360 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF349P057 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF349P008 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF349P007 = FHCAN_DISABLE;
	Ext_bMonRunInvldF349P007 = FHCAN_DISABLE;
	Ext_bMonRunInvldF349P055 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF349P287 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF349PM1434 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF349P166 = FHCAN_DISABLE;

	Ext_bDgoMissF349 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF349 = FHCAN_NOT_DETECTED;
	Ext_bDgoChkF349 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF349P360 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF349P057 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF349P008 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF349P007 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF349P007 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF349P055 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF349P287 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF349PM1434 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF349P166 = FHCAN_NOT_DETECTED;
}

void FHCANF349_vidFrameReceived(void)
{
	boolean Local_bCtrl_V2_BVA_349;
	boolean Local_bCtrl_bTqTx;
	boolean Local_bCtrl_stGSTyp ;
	boolean Local_bCtrl_stDragRed;
	boolean Local_bCtrl_tqReqGBx;
	boolean Local_bCtrl_stNRegTyp;
	boolean Local_bCtrl_bNRegReq;
	boolean Local_bCtrl_bFrzAC;
	boolean Local_bCtrl_stCnvClu;
	boolean Local_bCtrl_bSIPPrep;
	boolean Local_bCtrl_bSIP;
	boolean Local_bCtrl_noTarGear;
	boolean Local_bCtrl_posnATLev;
	boolean Local_bCtrl_tqMaxGBx;
	boolean Local_bCtrl_noEgdGear;
	boolean Local_bCtrl_stGearRat;
	boolean Local_bCtrl_stCpl;
	boolean Local_bCtrl_noCks349;
	boolean Local_bCtrl_ctClcProc349;
	boolean Local_bCtrl_nTar;

	VEMS_vidGET(Ctrl_V2_BVA_349, Local_bCtrl_V2_BVA_349);
	if (ACTIVATED == Local_bCtrl_V2_BVA_349)
	{
		ISCAN_EveRxn_349();
		FHCAN349_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF349)
      {
         Ext_bDgoMissF349 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF349,
                  Ext_bDgoMissF349,
                  Ext_bMonRunMissF349,
                  DIAG_DISPO);
      }
            
		if (FHCAN_ENABLE == Ext_bMonRunCntF349)
      {
         Ext_bDgoCntF349 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF349,
                  Ext_bDgoCntF349,
                  Ext_bMonRunCntF349,
                  DIAG_DISPO);
      }

		VEMS_vidGET(Ctrl_bTqTx, Local_bCtrl_bTqTx);
		if (ACTIVATED == Local_bCtrl_bTqTx)
		{
			Com_ReceiveSignal(Com_ETAT_TRANS_CPLE_V2_BVA_349, (void*) &ISCAN_bF349PM1433);


			FHCANF349_vidUpdateSignalPM1433();
		}
		else
		{
			VEMS_vidSET(Can_bTqTx, 0);

		}
		VEMS_vidGET(Ctrl_stGSTyp , Local_bCtrl_stGSTyp );
		if (ACTIVATED == Local_bCtrl_stGSTyp )
		{
			FHCAN349_vidCalcMonFP360Window();
			Com_ReceiveSignal(Com_TYPE_SIP_V2_BVA_349, (void*) &ISCAN_u8N3F349P360);

			FHCAN349_vidMonFrbdP360Update();

			FHCANF349_vidUpdateSignalP360();
		}
		else
		{
			VEMS_vidSET(Can_stGSTyp, 3);
			VEMS_vidSET(CoPt_stSIPTyp, 3);

			Ext_bMonRunFrbdF349P360 = FHCAN_DISABLE;
			Ext_bDgoFrbdF349P360 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stDragRed, Local_bCtrl_stDragRed);
		if (ACTIVATED == Local_bCtrl_stDragRed)
		{
			Com_ReceiveSignal(Com_ETAT_TRAINEE_BVA_V2_BVA_349, (void*) &ISCAN_u8N2F349P030);


			FHCANF349_vidUpdateSignalP030();
		}
		else
		{
			VEMS_vidSET(Can_stDragRed, 3);

		}
		VEMS_vidGET(Ctrl_tqReqGBx, Local_bCtrl_tqReqGBx);
		if (ACTIVATED == Local_bCtrl_tqReqGBx)
		{
			FHCAN349_vidCalcMonFP057Window();
			Com_ReceiveSignal(Com_CNS_CPLE_REQ_BV_V2_BVA_349, (void*) &ISCAN_u8N8F349P057);

			FHCAN349_vidMonFrbdP057Update();

			FHCANF349_vidUpdateSignalP057();
		}
		else
		{
			VEMS_vidSET(Can_tqReqGBx, 0);

			Ext_bMonRunFrbdF349P057 = FHCAN_DISABLE;
			Ext_bDgoFrbdF349P057 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stNRegTyp, Local_bCtrl_stNRegTyp);
		if (ACTIVATED == Local_bCtrl_stNRegTyp)
		{
			Com_ReceiveSignal(Com_TYPE_RELANCE_REGIME_V2_BVA_349, (void*) &ISCAN_bF349P361);


			FHCANF349_vidUpdateSignalP361();
		}
		else
		{
			VEMS_vidSET(Can_stNRegTyp, 0);

		}
		VEMS_vidGET(Ctrl_bNRegReq, Local_bCtrl_bNRegReq);
		if (ACTIVATED == Local_bCtrl_bNRegReq)
		{
			Com_ReceiveSignal(Com_REGUL_REGIM_DEMAND_V2_BVA_349, (void*) &ISCAN_bF349P167);


			FHCANF349_vidUpdateSignalP167();
		}
		else
		{
			VEMS_vidSET(Can_bNRegReq, 0);

		}
		VEMS_vidGET(Ctrl_bFrzAC, Local_bCtrl_bFrzAC);
		if (ACTIVATED == Local_bCtrl_bFrzAC)
		{
			Com_ReceiveSignal(Com_INH_CHGT_CPR_CLIM_V2_BVA_349, (void*) &ISCAN_bF349P085);


			FHCANF349_vidUpdateSignalP085();
		}
		else
		{
			VEMS_vidSET(Can_bFrzAC, 0);

		}
		VEMS_vidGET(Ctrl_stCnvClu, Local_bCtrl_stCnvClu);
		if (ACTIVATED == Local_bCtrl_stCnvClu)
		{
			Com_ReceiveSignal(Com_ETAT_CONVERT_BVA_V2_BVA_349, (void*) &ISCAN_u8N2F349P087);


			FHCANF349_vidUpdateSignalP087();
		}
		else
		{
			VEMS_vidSET(Can_stCnvClu, 3);

		}
		VEMS_vidGET(Ctrl_bSIPPrep, Local_bCtrl_bSIPPrep);
		if (ACTIVATED == Local_bCtrl_bSIPPrep)
		{
			Com_ReceiveSignal(Com_PHASE_CHGT_ETAT_CDT_V2_BVA_349, (void*) &ISCAN_bF349P362);


			FHCANF349_vidUpdateSignalP362();
		}
		else
		{
			VEMS_vidSET(Can_bSIPPrep, 0);

		}
		VEMS_vidGET(Ctrl_bSIP, Local_bCtrl_bSIP);
		if (ACTIVATED == Local_bCtrl_bSIP)
		{
			Com_ReceiveSignal(Com_CHGT_RAP_EN_COURS_V2_BVA_349, (void*) &ISCAN_bF349P009);


			FHCANF349_vidUpdateSignalP009();
		}
		else
		{
			VEMS_vidSET(Can_bSIP, 0);

		}
		VEMS_vidGET(Ctrl_noTarGear, Local_bCtrl_noTarGear);
		if (ACTIVATED == Local_bCtrl_noTarGear)
		{
			FHCAN349_vidCalcMonFP008Window();
			Com_ReceiveSignal(Com_RAP_CIBLE_BVA_V2_BVA_349, (void*) &ISCAN_u8N4F349P008);

			FHCAN349_vidMonFrbdP008Update();

			FHCANF349_vidUpdateSignalP008();
		}
		else
		{
			VEMS_vidSET(Can_noTarGear, 0);
			VEMS_vidSET(Ext_noGearTar, 0);

			Ext_bMonRunFrbdF349P008 = FHCAN_DISABLE;
			Ext_bDgoFrbdF349P008 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_posnATLev, Local_bCtrl_posnATLev);
		if (ACTIVATED == Local_bCtrl_posnATLev)
		{
			FHCAN349_vidCalcMonFP007Window();
			Com_ReceiveSignal(Com_POS_LEVIER_BV_V2_BVA_349, (void*) &ISCAN_u8N4F349P007);

			FHCAN349_vidMonInvldP007Update();
			FHCAN349_vidMonFrbdP007Update();

			FHCANF349_vidUpdateSignalP007();
		}
		else
		{
			VEMS_vidSET(Can_posnATLev, 15);
			VEMS_vidSET(Can_stPosATLevExtdCAN, 15);

			Ext_bMonRunFrbdF349P007 = FHCAN_DISABLE;
			Ext_bMonRunInvldF349P007 = FHCAN_DISABLE;
			Ext_bDgoFrbdF349P007 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF349P007 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_tqMaxGBx, Local_bCtrl_tqMaxGBx);
		if (ACTIVATED == Local_bCtrl_tqMaxGBx)
		{
			FHCAN349_vidCalcMonFP055Window();
			Com_ReceiveSignal(Com_CPLE_MAX_ADM_BV_V2_BVA_349, (void*) &ISCAN_u8N8F349P055);

			FHCAN349_vidMonInvldP055Update();

			FHCANF349_vidUpdateSignalP055();
		}
		else
		{
			VEMS_vidSET(Can_tqMaxGBx, 0);

			Ext_bMonRunInvldF349P055 = FHCAN_DISABLE;
			Ext_bDgoInvldF349P055 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_noEgdGear, Local_bCtrl_noEgdGear);
		if (ACTIVATED == Local_bCtrl_noEgdGear)
		{
			FHCAN349_vidCalcMonFP287Window();
			Com_ReceiveSignal(Com_RAP_BV_ENGAGE_MECA_V2_BVA_349, (void*) &ISCAN_u8N4F349P287);

			FHCAN349_vidMonFrbdP287Update();

			FHCANF349_vidUpdateSignalP287();
		}
		else
		{
			VEMS_vidSET(Can_noEgdGear, 15);

			Ext_bMonRunFrbdF349P287 = FHCAN_DISABLE;
			Ext_bDgoFrbdF349P287 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stGearRat, Local_bCtrl_stGearRat);
		if (ACTIVATED == Local_bCtrl_stGearRat)
		{
			FHCAN349_vidCalcMonFPM1434Window();
			Com_ReceiveSignal(Com_ETAT_DEMUL_V2_BVA_349, (void*) &ISCAN_u8N2F349PM1434);

			FHCAN349_vidMonFrbdPM1434Update();

			FHCANF349_vidUpdateSignalPM1434();
		}
		else
		{
			VEMS_vidSET(Can_stGearRat, 0);

			Ext_bMonRunFrbdF349PM1434 = FHCAN_DISABLE;
			Ext_bDgoFrbdF349PM1434 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stCpl, Local_bCtrl_stCpl);
		if (ACTIVATED == Local_bCtrl_stCpl)
		{
			Com_ReceiveSignal(Com_ETAT_COUPLAGE_V2_BVA_349, (void*) &ISCAN_u8N2F349PM1435);


			FHCANF349_vidUpdateSignalPM1435();
		}
		else
		{
			VEMS_vidSET(Can_stCpl, 0);

		}
		VEMS_vidGET(Ctrl_noCks349, Local_bCtrl_noCks349);
		if (ACTIVATED == Local_bCtrl_noCks349)
		{
			Com_ReceiveSignal(Com_CHKSUM_TRME_DYN_V2_349_V2_BVA_349, (void*) &ISCAN_u8N4F349PM2853);


			FHCANF349_vidUpdateSignalPM2853();
		}
		else
		{
			VEMS_vidSET(Ext_noCks349, 0);

		}
		VEMS_vidGET(Ctrl_ctClcProc349, Local_bCtrl_ctClcProc349);
		if (ACTIVATED == Local_bCtrl_ctClcProc349)
		{
			Com_ReceiveSignal(Com_CPT_PROCESS_4B_V2_349_V2_BVA_349, (void*) &ISCAN_u8N4F349PM2842);


			FHCANF349_vidUpdateSignalPM2842();
		}
		else
		{
			VEMS_vidSET(Ext_ctClcProc349, 0);

		}
		VEMS_vidGET(Ctrl_nTar, Local_bCtrl_nTar);
		if (ACTIVATED == Local_bCtrl_nTar)
		{
			FHCAN349_vidCalcMonFP166Window();
			Com_ReceiveSignal(Com_CNS_REGUL_REGIM_V2_BVA_349, (void*) &ISCAN_u8N8F349P166);

			FHCAN349_vidMonFrbdP166Update();

			FHCANF349_vidUpdateSignalP166();
		}
		else
		{
			VEMS_vidSET(Can_nTar, 3000);
			VEMS_vidSET(Ext_bNotAvl_nTar, AVAILABLE);
			Ext_bMonRunFrbdF349P166 = FHCAN_DISABLE;
			Ext_bDgoFrbdF349P166 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF349 = FHCAN_DISABLE;
		Ext_bMonRunShoF349 = FHCAN_DISABLE;
		Ext_bMonRunChkF349 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P360 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P057 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P008 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P007 = FHCAN_DISABLE;
		Ext_bMonRunInvldF349P007 = FHCAN_DISABLE;
		Ext_bMonRunInvldF349P055 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P287 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349PM1434 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P166 = FHCAN_DISABLE;

		Ext_bDgoMissF349 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF349 = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF349 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P360 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P057 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P008 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P007 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF349P007 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF349P055 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P287 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349PM1434 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P166 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF349_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF349P360_in;
	boolean FRM_bAcvRcvF349P057_in;
	boolean FRM_bAcvRcvF349P008_in;
	boolean FRM_bAcvRcvF349P007_in;
	boolean FRM_bAcvRcvF349P055_in;
	boolean FRM_bAcvRcvF349P287_in;
	boolean FRM_bAcvRcvF349PM1434_in;
	boolean FRM_bAcvRcvF349P166_in;
	boolean FRM_bAcvRcvF349_in;
	boolean Local_bCtrl_V2_BVA_349;
	boolean Local_bCtrl_bTqTx;
	boolean Local_bCtrl_stGSTyp ;
	boolean Local_bCtrl_stDragRed;
	boolean Local_bCtrl_tqReqGBx;
	boolean Local_bCtrl_stNRegTyp;
	boolean Local_bCtrl_bNRegReq;
	boolean Local_bCtrl_bFrzAC;
	boolean Local_bCtrl_stCnvClu;
	boolean Local_bCtrl_bSIPPrep;
	boolean Local_bCtrl_bSIP;
	boolean Local_bCtrl_noTarGear;
	boolean Local_bCtrl_posnATLev;
	boolean Local_bCtrl_tqMaxGBx;
	boolean Local_bCtrl_noEgdGear;
	boolean Local_bCtrl_stGearRat;
	boolean Local_bCtrl_stCpl;
	boolean Local_bCtrl_noCks349;
	boolean Local_bCtrl_ctClcProc349;
	boolean Local_bCtrl_nTar;
	uint8 Local_Ext_noCks349;
	uint8 Local_Ext_ctClcProc349;
	uint16 Local_Can_nTar;


	VEMS_vidGET(Ctrl_V2_BVA_349, Local_bCtrl_V2_BVA_349);
	if (ACTIVATED == Local_bCtrl_V2_BVA_349)
	{
		FHCAN349_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF349)
      {
         Ext_bDgoMissF349 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF349,
                  Ext_bDgoMissF349,
                  Ext_bMonRunMissF349,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Can_bTqTx, 0);
		   VEMS_vidSET(Can_stGSTyp, 3);
		   VEMS_vidSET(CoPt_stSIPTyp, 3);
		   VEMS_vidSET(Can_stDragRed, 3);
		   VEMS_vidSET(Can_tqReqGBx, 0);
		   VEMS_vidSET(Can_stNRegTyp, 0);
		   VEMS_vidSET(Can_bNRegReq, 0);
		   VEMS_vidSET(Can_bFrzAC, 0);
		   VEMS_vidSET(Can_stCnvClu, 3);
		   VEMS_vidSET(Can_bSIPPrep, 0);
		   VEMS_vidSET(Can_bSIP, 0);
		   VEMS_vidSET(Can_noTarGear, 0);
		   VEMS_vidSET(Ext_noGearTar, 0);
		   VEMS_vidSET(Can_posnATLev, 15);
		   VEMS_vidSET(Can_stPosATLevExtdCAN, 15);
		   VEMS_vidSET(Can_tqMaxGBx, 0);
		   VEMS_vidSET(Can_noEgdGear, 15);
		   VEMS_vidSET(Can_stGearRat, 0);
		   VEMS_vidSET(Can_stCpl, 0);
		   VEMS_vidSET(Ext_noCks349, 0);
		   VEMS_vidSET(Ext_ctClcProc349, 0);
		   VEMS_vidSET(Can_nTar, 3000);
		   VEMS_vidSET(Ext_bNotAvl_nTar, AVAILABLE);
      }

		FRM_bAcvRcvF349P360_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P360);
		FRM_bAcvRcvF349P057_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P057);
		FRM_bAcvRcvF349P008_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P008);
		FRM_bAcvRcvF349P007_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P007);
		FRM_bAcvRcvF349P055_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P055);
		FRM_bAcvRcvF349P287_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P287);
		FRM_bAcvRcvF349PM1434_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349PM1434);
		FRM_bAcvRcvF349P166_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P166);
		FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);

		VEMS_vidGET(Ctrl_bTqTx, Local_bCtrl_bTqTx);
		if (ACTIVATED == Local_bCtrl_bTqTx)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF349_in)
			{
		      VEMS_vidSET(Can_bTqTx, Tra_bTqTxRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stGSTyp , Local_bCtrl_stGSTyp );
		if (ACTIVATED == Local_bCtrl_stGSTyp )
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF349P360_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
			{
		      VEMS_vidSET(Can_stGSTyp, Tra_stGSTypRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stDragRed, Local_bCtrl_stDragRed);
		if (ACTIVATED == Local_bCtrl_stDragRed)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF349_in)
			{
		      VEMS_vidSET(Can_stDragRed, Tra_stDragRedRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_tqReqGBx, Local_bCtrl_tqReqGBx);
		if (ACTIVATED == Local_bCtrl_tqReqGBx)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF349P057_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
			{
		      VEMS_vidSET(Can_tqReqGBx, Tra_tqReqGBxRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stNRegTyp, Local_bCtrl_stNRegTyp);
		if (ACTIVATED == Local_bCtrl_stNRegTyp)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF349_in)
			{
		      VEMS_vidSET(Can_stNRegTyp, Tra_stNRegTypRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bNRegReq, Local_bCtrl_bNRegReq);
		if (ACTIVATED == Local_bCtrl_bNRegReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF349_in)
			{
		      VEMS_vidSET(Can_bNRegReq, Tra_bNRegReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bFrzAC, Local_bCtrl_bFrzAC);
		if (ACTIVATED == Local_bCtrl_bFrzAC)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF349_in)
			{
		      VEMS_vidSET(Can_bFrzAC, Tra_bFrzACRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stCnvClu, Local_bCtrl_stCnvClu);
		if (ACTIVATED == Local_bCtrl_stCnvClu)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF349_in)
			{
		      VEMS_vidSET(Can_stCnvClu, Tra_stCnvCluRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bSIPPrep, Local_bCtrl_bSIPPrep);
		if (ACTIVATED == Local_bCtrl_bSIPPrep)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF349_in)
			{
		      VEMS_vidSET(Can_bSIPPrep, Tra_bSIPPrepRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bSIP, Local_bCtrl_bSIP);
		if (ACTIVATED == Local_bCtrl_bSIP)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF349_in)
			{
		      VEMS_vidSET(Can_bSIP, Tra_bSIPRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_noTarGear, Local_bCtrl_noTarGear);
		if (ACTIVATED == Local_bCtrl_noTarGear)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF349P008_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
			{
		      VEMS_vidSET(Can_noTarGear, Tra_noTarGearRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_posnATLev, Local_bCtrl_posnATLev);
		if (ACTIVATED == Local_bCtrl_posnATLev)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF349P007_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
			{
		      VEMS_vidSET(Can_posnATLev, Ext_posnATLevRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_tqMaxGBx, Local_bCtrl_tqMaxGBx);
		if (ACTIVATED == Local_bCtrl_tqMaxGBx)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF349P055_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
			{
		      VEMS_vidSET(Can_tqMaxGBx, Tra_tqMaxGBxRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_noEgdGear, Local_bCtrl_noEgdGear);
		if (ACTIVATED == Local_bCtrl_noEgdGear)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF349P287_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
			{
		      VEMS_vidSET(Can_noEgdGear, Tra_noEgdGearRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stGearRat, Local_bCtrl_stGearRat);
		if (ACTIVATED == Local_bCtrl_stGearRat)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF349PM1434_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
			{
		      VEMS_vidSET(Can_stGearRat, Tra_stGearRatRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stCpl, Local_bCtrl_stCpl);
		if (ACTIVATED == Local_bCtrl_stCpl)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF349_in)
			{
		      VEMS_vidSET(Can_stCpl, Tra_stCplRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_noCks349, Local_bCtrl_noCks349);
		if (ACTIVATED == Local_bCtrl_noCks349)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF349_in)
			{
		      VEMS_vidGET(Ext_noCks349, Local_Ext_noCks349);
		      VEMS_vidSET(Ext_noCks349, Local_Ext_noCks349);
			}
		}
		VEMS_vidGET(Ctrl_ctClcProc349, Local_bCtrl_ctClcProc349);
		if (ACTIVATED == Local_bCtrl_ctClcProc349)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF349_in)
			{
		      VEMS_vidGET(Ext_ctClcProc349, Local_Ext_ctClcProc349);
		      VEMS_vidSET(Ext_ctClcProc349, Local_Ext_ctClcProc349);
			}
		}
		VEMS_vidGET(Ctrl_nTar, Local_bCtrl_nTar);
		if (ACTIVATED == Local_bCtrl_nTar)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF349P166_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
			{
		      VEMS_vidGET(Can_nTar, Local_Can_nTar);
		      VEMS_vidSET(Can_nTar, Local_Can_nTar);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF349 = FHCAN_DISABLE;
		Ext_bMonRunShoF349 = FHCAN_DISABLE;
		Ext_bMonRunChkF349 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P360 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P057 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P008 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P007 = FHCAN_DISABLE;
		Ext_bMonRunInvldF349P007 = FHCAN_DISABLE;
		Ext_bMonRunInvldF349P055 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P287 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349PM1434 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF349P166 = FHCAN_DISABLE;

		Ext_bDgoMissF349 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF349 = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF349 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P360 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P057 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P008 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P007 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF349P007 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF349P055 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P287 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349PM1434 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF349P166 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF349_vidUpdateSignalPM1433(void)
{
	boolean FRM_bAcvRcvF349_in;

	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      VEMS_vidSET(Can_bTqTx,
                  ISCAN_bF349PM1433);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF349_in)
      {
			VEMS_vidSET(Can_bTqTx, Tra_bTqTxRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP360(void)
{
	boolean FRM_bAcvRcvF349P360_in;
	boolean FRM_bAcvRcvF349_in;
   uint8 u8LocalCan_stGSTyp;

	FRM_bAcvRcvF349P360_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P360);
	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349P360_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF349P360)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      u8LocalCan_stGSTyp = ISCAN_u8N3F349P360;
      VEMS_vidSET(Can_stGSTyp,
                  u8LocalCan_stGSTyp);
		switch(ISCAN_u8N3F349P360)
		{
		case 0:
      VEMS_vidSET(CoPt_stSIPTyp, 0x00);
        break;

		case 1:
      VEMS_vidSET(CoPt_stSIPTyp, 0x01);
         break;

		case 3:
      VEMS_vidSET(CoPt_stSIPTyp, 0x04);
         break;

		case 4:
      VEMS_vidSET(CoPt_stSIPTyp, 0x02);
         break;

		case 5:
      VEMS_vidSET(CoPt_stSIPTyp, 0x03);
         break;

		default:
      VEMS_vidSET(CoPt_stSIPTyp, 0x04);
         break;
         }
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF349P360_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
      {
			VEMS_vidSET(Can_stGSTyp, Tra_stGSTypRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP030(void)
{
	boolean FRM_bAcvRcvF349_in;
   uint8 u8LocalCan_stDragRed;

	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      u8LocalCan_stDragRed = ISCAN_u8N2F349P030;
      VEMS_vidSET(Can_stDragRed,
                  u8LocalCan_stDragRed);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF349_in)
      {
			VEMS_vidSET(Can_stDragRed, Tra_stDragRedRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP057(void)
{
	boolean FRM_bAcvRcvF349P057_in;
	boolean FRM_bAcvRcvF349_in;
   sint16 s16LocalIscanV2_BVA_349;
   sint16 s16LocalCan_tqReqGBx;

	FRM_bAcvRcvF349P057_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P057);
	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349P057_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF349P057)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      s16LocalIscanV2_BVA_349 = (sint16)((32 * ISCAN_u8N8F349P057) - 1600);
      s16LocalCan_tqReqGBx = (sint16)(MATHSRV_udtCLAMP(s16LocalIscanV2_BVA_349,
                                               -32000,
                                               32000));
      VEMS_vidSET(Can_tqReqGBx,
                  s16LocalCan_tqReqGBx);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF349P057_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
      {
			VEMS_vidSET(Can_tqReqGBx, Tra_tqReqGBxRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP361(void)
{
	boolean FRM_bAcvRcvF349_in;
   uint8 u8LocalCan_stNRegTyp;

	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      u8LocalCan_stNRegTyp = (uint8)(MATHSRV_udtMIN(ISCAN_bF349P361,
                                             255));
      VEMS_vidSET(Can_stNRegTyp,
                  u8LocalCan_stNRegTyp);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF349_in)
      {
			VEMS_vidSET(Can_stNRegTyp, Tra_stNRegTypRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP167(void)
{
	boolean FRM_bAcvRcvF349_in;

	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      VEMS_vidSET(Can_bNRegReq,
                  ISCAN_bF349P167);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF349_in)
      {
			VEMS_vidSET(Can_bNRegReq, Tra_bNRegReqRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP085(void)
{
	boolean FRM_bAcvRcvF349_in;

	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      VEMS_vidSET(Can_bFrzAC,
                  ISCAN_bF349P085);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF349_in)
      {
			VEMS_vidSET(Can_bFrzAC, Tra_bFrzACRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP087(void)
{
	boolean FRM_bAcvRcvF349_in;
   uint8 u8LocalCan_stCnvClu;

	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      u8LocalCan_stCnvClu = ISCAN_u8N2F349P087;
      VEMS_vidSET(Can_stCnvClu,
                  u8LocalCan_stCnvClu);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF349_in)
      {
			VEMS_vidSET(Can_stCnvClu, Tra_stCnvCluRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP362(void)
{
	boolean FRM_bAcvRcvF349_in;

	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      VEMS_vidSET(Can_bSIPPrep,
                  ISCAN_bF349P362);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF349_in)
      {
			VEMS_vidSET(Can_bSIPPrep, Tra_bSIPPrepRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP009(void)
{
	boolean FRM_bAcvRcvF349_in;

	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      VEMS_vidSET(Can_bSIP,
                  ISCAN_bF349P009);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF349_in)
      {
			VEMS_vidSET(Can_bSIP, Tra_bSIPRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP008(void)
{
	boolean FRM_bAcvRcvF349P008_in;
	boolean FRM_bAcvRcvF349_in;

	FRM_bAcvRcvF349P008_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P008);
	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349P008_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF349P008)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
		switch (ISCAN_u8N4F349P008)
		{
		case 0:
      VEMS_vidSET(Ext_noGearTar, 0);
      VEMS_vidSET(Can_noTarGear, 0);
		break;

		case 1:
      VEMS_vidSET(Ext_noGearTar, 1);
      VEMS_vidSET(Can_noTarGear, 1);
		break;

		case 2:
      VEMS_vidSET(Ext_noGearTar, 2);
      VEMS_vidSET(Can_noTarGear, 2);
		break;

		case 3:
      VEMS_vidSET(Ext_noGearTar, 3);
      VEMS_vidSET(Can_noTarGear, 3);
		break;

		case 4:
      VEMS_vidSET(Ext_noGearTar, 4);
      VEMS_vidSET(Can_noTarGear, 4);
		break;

		case 5:
      VEMS_vidSET(Ext_noGearTar, 5);
      VEMS_vidSET(Can_noTarGear, 5);
		break;

		case 6:
      VEMS_vidSET(Ext_noGearTar, 6);
      VEMS_vidSET(Can_noTarGear, 6);
		break;

		case 7:
      VEMS_vidSET(Ext_noGearTar, 8);
      VEMS_vidSET(Can_noTarGear, 7);
		break;

		case 8:
      VEMS_vidSET(Ext_noGearTar, 8);
      VEMS_vidSET(Can_noTarGear, 8);
		break;

		case 9:
      VEMS_vidSET(Ext_noGearTar, 8);
      VEMS_vidSET(Can_noTarGear, -1);
		break;

		case 10:
      VEMS_vidSET(Ext_noGearTar, 0);
      VEMS_vidSET(Can_noTarGear, 0);
		break;

		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
      VEMS_vidSET(Ext_noGearTar, 8);
      VEMS_vidSET(Can_noTarGear, 9);
		break;

		default:
		break;
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF349P008_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
      {
			VEMS_vidSET(Can_noTarGear, Tra_noTarGearRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP007(void)
{
	boolean FRM_bAcvRcvF349P007_in;
	boolean FRM_bAcvRcvF349_in;
   uint8 u8LocalCan_posnATLev;
   uint8 u8LocalCan_stPosATLevExtdCAN;

	FRM_bAcvRcvF349P007_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P007);
	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349P007_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF349P007)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF349P007)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      u8LocalCan_posnATLev = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F349P007,
                                             15));
      VEMS_vidSET(Can_posnATLev,
                  u8LocalCan_posnATLev);
      u8LocalCan_stPosATLevExtdCAN = ISCAN_u8N4F349P007;
      VEMS_vidSET(Can_stPosATLevExtdCAN,
                  u8LocalCan_stPosATLevExtdCAN);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF349P007_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
      {
			VEMS_vidSET(Can_posnATLev, Ext_posnATLevRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP055(void)
{
	boolean FRM_bAcvRcvF349P055_in;
	boolean FRM_bAcvRcvF349_in;
   sint16 s16LocalIscanV2_BVA_349;
   sint16 s16LocalCan_tqMaxGBx;

	FRM_bAcvRcvF349P055_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P055);
	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349P055_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF349P055)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      s16LocalIscanV2_BVA_349 = (sint16)((32 * ISCAN_u8N8F349P055) - 1600);
      s16LocalCan_tqMaxGBx = (sint16)(MATHSRV_udtCLAMP(s16LocalIscanV2_BVA_349,
                                               -32000,
                                               32000));
      VEMS_vidSET(Can_tqMaxGBx,
                  s16LocalCan_tqMaxGBx);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF349P055_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
      {
			VEMS_vidSET(Can_tqMaxGBx, Tra_tqMaxGBxRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalP287(void)
{
	boolean FRM_bAcvRcvF349P287_in;
	boolean FRM_bAcvRcvF349_in;

	FRM_bAcvRcvF349P287_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P287);
	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349P287_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF349P287)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
		switch (ISCAN_u8N4F349P287)
		{
		case 0:
      VEMS_vidSET(Can_noEgdGear, 9);
		break;
		case 1:
      VEMS_vidSET(Can_noEgdGear, 1);
		break;

		case 2:
      VEMS_vidSET(Can_noEgdGear, 2);
		break;

		case 3:
      VEMS_vidSET(Can_noEgdGear, 3);
		break;

		case 4:
      VEMS_vidSET(Can_noEgdGear, 4);
		break;

		case 5:
      VEMS_vidSET(Can_noEgdGear, 5);
		break;

		case 6:
      VEMS_vidSET(Can_noEgdGear, 6);
		break;

		case 7:
      VEMS_vidSET(Can_noEgdGear, 7);
		break;

		case 8:
      VEMS_vidSET(Can_noEgdGear, 8);
		break;

		case 9:
      VEMS_vidSET(Can_noEgdGear, -1);
		break;

		case 10:
      VEMS_vidSET(Can_noEgdGear, 0);
		break;

		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
      VEMS_vidSET(Can_noEgdGear, 9);
		break;

		default:
         
		break;
         }
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF349P287_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
      {
			VEMS_vidSET(Can_noEgdGear, Tra_noEgdGearRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalPM1434(void)
{
	boolean FRM_bAcvRcvF349PM1434_in;
	boolean FRM_bAcvRcvF349_in;
   uint8 u8LocalCan_stGearRat;

	FRM_bAcvRcvF349PM1434_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349PM1434);
	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349PM1434_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF349PM1434)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      u8LocalCan_stGearRat = ISCAN_u8N2F349PM1434;
      VEMS_vidSET(Can_stGearRat,
                  u8LocalCan_stGearRat);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF349PM1434_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
      {
			VEMS_vidSET(Can_stGearRat, Tra_stGearRatRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalPM1435(void)
{
	boolean FRM_bAcvRcvF349_in;
   uint8 u8LocalCan_stCpl;

	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      u8LocalCan_stCpl = ISCAN_u8N2F349PM1435;
      VEMS_vidSET(Can_stCpl,
                  u8LocalCan_stCpl);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF349_in)
      {
			VEMS_vidSET(Can_stCpl, Tra_stCplRcf_C);
		}
	}
}

void FHCANF349_vidUpdateSignalPM2853(void)
{
	boolean FRM_bAcvRcvF349_in;
   uint8 u8LocalExt_noCks349;

	uint8 Local_Ext_noCks349;

	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      u8LocalExt_noCks349 = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F349PM2853,
                                             15));
      VEMS_vidSET(Ext_noCks349,
                  u8LocalExt_noCks349);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF349_in)
      {
			VEMS_vidGET(Ext_noCks349, Local_Ext_noCks349);
			VEMS_vidSET(Ext_noCks349, Local_Ext_noCks349);
		}
	}
}

void FHCANF349_vidUpdateSignalPM2842(void)
{
	boolean FRM_bAcvRcvF349_in;
   uint8 u8LocalExt_ctClcProc349;

	uint8 Local_Ext_ctClcProc349;

	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      u8LocalExt_ctClcProc349 = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F349PM2842,
                                             15));
      VEMS_vidSET(Ext_ctClcProc349,
                  u8LocalExt_ctClcProc349);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF349_in)
      {
			VEMS_vidGET(Ext_ctClcProc349, Local_Ext_ctClcProc349);
			VEMS_vidSET(Ext_ctClcProc349, Local_Ext_ctClcProc349);
		}
	}
}

void FHCANF349_vidUpdateSignalP166(void)
{
	boolean FRM_bAcvRcvF349P166_in;
	boolean FRM_bAcvRcvF349_in;
   uint16 u16LocalIscanV2_BVA_349;
   uint16 u16LocalCan_nTar;

	uint16 Local_Can_nTar;

   if (ISCAN_u8N8F349P166 == 254)
	{
		VEMS_vidSET(Ext_bNotAvl_nTar, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_nTar, AVAILABLE);
	}

	FRM_bAcvRcvF349P166_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349P166);
	FRM_bAcvRcvF349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF349);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF349P166_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF349_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF349P166)
	   && (FHCAN_DETECTED != Ext_bDgoShoF349)
	   )
	{
      u16LocalIscanV2_BVA_349 = (uint16)((100 * ISCAN_u8N8F349P166) + 3000);
      u16LocalCan_nTar = (uint16)(MATHSRV_udtMIN(u16LocalIscanV2_BVA_349,
                                             32000));
      VEMS_vidSET(Can_nTar,
                  u16LocalCan_nTar);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF349P166_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF349_in))
      {
			VEMS_vidGET(Can_nTar, Local_Can_nTar);
			VEMS_vidSET(Can_nTar, Local_Can_nTar);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

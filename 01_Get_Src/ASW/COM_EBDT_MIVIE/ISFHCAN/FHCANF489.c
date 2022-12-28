/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF489.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF489.H"
#include "FHCANF489_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_489(void)
{
	ISCAN_u8N4F489P282 = 0;
	ISCAN_u8N2F489P029 = 0;
	ISCAN_bF489P374 = 1;
	ISCAN_bF489P048 = 0;
	ISCAN_bF489P285  = 0;
	ISCAN_bF489P376 = 0;
	ISCAN_bF489PM1423 = 0;
	ISCAN_bF489P375 = 0;
	ISCAN_u8N8F489P102 = 60;
	ISCAN_u16N12F489P254 = 0;
	ISCAN_u8N8F489P218 = 0;

	VEMS_vidSET(Tra_stGBxDft, 0);
	VEMS_vidSET(Tra_stGBxMod, 0);
	VEMS_vidSET(Tra_bLevMod, 0);
	VEMS_vidSET(Tra_bGBxRdy, 1);
	VEMS_vidSET(GBx_bSpdFanGBxReq, 0);
	VEMS_vidSET(Ext_bInhStrtAMT, 0);
	VEMS_vidSET(Ext_bDgoSenPN, 0);
	VEMS_vidSET(Tra_bCntMILRst, 0);
	VEMS_vidSET(Tra_bLiMILReqGUS, 0);
	VEMS_vidSET(Tra_bLiMILReq, 0);
	VEMS_vidSET(Ext_tOilGBx, 20);
	VEMS_vidSET(Tra_tqCnvExtd, 0);
	VEMS_vidSET(Tra_idxPtSpt, 0);
	Ext_bMonRunBVAbsent = FHCAN_DISABLE;
	Ext_bDgoBVAbsent = FHCAN_NOT_DETECTED;

	Ext_bMonRunMissF489 = FHCAN_DISABLE;
	Ext_bMonRunShoF489 = FHCAN_DISABLE;
	Ext_bMonRunInvldF489P102 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF489P254 = FHCAN_DISABLE;
	Ext_bMonRunInvldF489P254 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF489P218 = FHCAN_DISABLE;
	Ext_bMonRunInvldF489P218 = FHCAN_DISABLE;

	Ext_bDgoMissF489 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF489 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF489P102 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF489P254 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF489P254 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF489P218 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF489P218 = FHCAN_NOT_DETECTED;
}

void FHCANF489_vidFrameReceived(void)
{
	boolean Local_bCtrl_V2_BV_489;
	boolean Local_bCtrl_stGBxDft;
	boolean Local_bCtrl_bLevMod;
	boolean Local_bCtrl_bGBxRdy;
	boolean Local_bCtrl_bSpdFanGBxReq;
	boolean Local_bCtrl_bInhStrtAMT;
	boolean Local_bCtrl_bCntMILRst;
	boolean Local_bCtrl_bLiMILReqGUS;
	boolean Local_bCtrl_bLiMILReq;
	boolean Local_bCtrl_tOilGBx;
	boolean Local_bCtrl_tqCnvExtd;
	boolean Local_bCtrl_idxPtSpt;

	VEMS_vidGET(Ctrl_V2_BV_489, Local_bCtrl_V2_BV_489);
	if (ACTIVATED == Local_bCtrl_V2_BV_489)
	{
		ISCAN_EveRxn_489();
		FHCAN489_vidCalcMonBVWindow();
		FHCAN489_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunBVAbsent)
		{
			Ext_bDgoBVAbsent = FHCAN_NOT_DETECTED;
			GDGAR_vidGdu(GD_DFT_BVABSENT,
						Ext_bDgoBVAbsent,
						Ext_bMonRunBVAbsent,
						DIAG_DISPO);
		}
	  	if (FHCAN_ENABLE == Ext_bMonRunMissF489)
      {
         Ext_bDgoMissF489 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF489,
                  Ext_bDgoMissF489,
                  Ext_bMonRunMissF489,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_stGBxDft, Local_bCtrl_stGBxDft);
		if (ACTIVATED == Local_bCtrl_stGBxDft)
		{
			Com_ReceiveSignal(Com_DEFAUT_ETAT_BV_V2_BV_489, (void*) &ISCAN_u8N4F489P282);


			FHCANF489_vidUpdateSignalP282();
		}
		else
		{
			VEMS_vidSET(Tra_stGBxDft, 0);

		}
		VEMS_vidGET(Ctrl_bLevMod, Local_bCtrl_bLevMod);
		if (ACTIVATED == Local_bCtrl_bLevMod)
		{
			Com_ReceiveSignal(Com_PROG_BV_SELECT_V2_BV_489, (void*) &ISCAN_u8N2F489P029);


			FHCANF489_vidUpdateSignalP029();
		}
		else
		{
			VEMS_vidSET(Tra_stGBxMod, 0);
			VEMS_vidSET(Tra_bLevMod, 0);

		}
		VEMS_vidGET(Ctrl_bGBxRdy, Local_bCtrl_bGBxRdy);
		if (ACTIVATED == Local_bCtrl_bGBxRdy)
		{
			Com_ReceiveSignal(Com_RC01_PERMANENT_SYNTHESE_BV_V2_BV_489, (void*) &ISCAN_bF489P374);


			FHCANF489_vidUpdateSignalP374();
		}
		else
		{
			VEMS_vidSET(Tra_bGBxRdy, 1);

		}
		VEMS_vidGET(Ctrl_bSpdFanGBxReq, Local_bCtrl_bSpdFanGBxReq);
		if (ACTIVATED == Local_bCtrl_bSpdFanGBxReq)
		{
			Com_ReceiveSignal(Com_REQ_GMV_BV_V2_BV_489, (void*) &ISCAN_bF489P048);


			FHCANF489_vidUpdateSignalP048();
		}
		else
		{
			VEMS_vidSET(GBx_bSpdFanGBxReq, 0);

		}
		VEMS_vidGET(Ctrl_bInhStrtAMT, Local_bCtrl_bInhStrtAMT);
		if (ACTIVATED == Local_bCtrl_bInhStrtAMT)
		{
			Com_ReceiveSignal(Com_INTERDICTION_DEMA_V2_BV_489, (void*) &ISCAN_bF489P285 );


			FHCANF489_vidUpdateSignalP285();
		}
		else
		{
			VEMS_vidSET(Ext_bInhStrtAMT, 0);
			VEMS_vidSET(Ext_bDgoSenPN, 0);

		}
		VEMS_vidGET(Ctrl_bCntMILRst, Local_bCtrl_bCntMILRst);
		if (ACTIVATED == Local_bCtrl_bCntMILRst)
		{
			Com_ReceiveSignal(Com_CMD_RESET_MIL_ON_BV_V2_BV_489, (void*) &ISCAN_bF489P376);


			FHCANF489_vidUpdateSignalP376();
		}
		else
		{
			VEMS_vidSET(Tra_bCntMILRst, 0);

		}
		VEMS_vidGET(Ctrl_bLiMILReqGUS, Local_bCtrl_bLiMILReqGUS);
		if (ACTIVATED == Local_bCtrl_bLiMILReqGUS)
		{
			Com_ReceiveSignal(Com_DMD_ALLUM_MIL_GUS_BV_V2_BV_489, (void*) &ISCAN_bF489PM1423);


			FHCANF489_vidUpdateSignalPM1423();
		}
		else
		{
			VEMS_vidSET(Tra_bLiMILReqGUS, 0);

		}
		VEMS_vidGET(Ctrl_bLiMILReq, Local_bCtrl_bLiMILReq);
		if (ACTIVATED == Local_bCtrl_bLiMILReq)
		{
			Com_ReceiveSignal(Com_DMD_ALLUMAGE_MIL_DEFAUTS_BV_V2_BV_489, (void*) &ISCAN_bF489P375);


			FHCANF489_vidUpdateSignalP375();
		}
		else
		{
			VEMS_vidSET(Tra_bLiMILReq, 0);

		}
		VEMS_vidGET(Ctrl_tOilGBx, Local_bCtrl_tOilGBx);
		if (ACTIVATED == Local_bCtrl_tOilGBx)
		{
			FHCAN489_vidCalcMonFP102Window();
			Com_ReceiveSignal(Com_TEMP_HUILE_BV_V2_BV_489, (void*) &ISCAN_u8N8F489P102);

			FHCAN489_vidMonInvldP102Update();

			FHCANF489_vidUpdateSignalP102();
		}
		else
		{
			VEMS_vidSET(Ext_tOilGBx, 20);

			Ext_bMonRunInvldF489P102 = FHCAN_DISABLE;
			Ext_bDgoInvldF489P102 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_tqCnvExtd, Local_bCtrl_tqCnvExtd);
		if (ACTIVATED == Local_bCtrl_tqCnvExtd)
		{
			FHCAN489_vidCalcMonFP254Window();
			Com_ReceiveSignal(Com_TAUX_CONV_CPLE_ETENDU_V2_BV_489, (void*) &ISCAN_u16N12F489P254);

			FHCAN489_vidMonInvldP254Update();
			FHCAN489_vidMonFrbdP254Update();

			FHCANF489_vidUpdateSignalP254();
		}
		else
		{
			VEMS_vidSET(Tra_tqCnvExtd, 0);

			Ext_bMonRunFrbdF489P254 = FHCAN_DISABLE;
			Ext_bMonRunInvldF489P254 = FHCAN_DISABLE;
			Ext_bDgoFrbdF489P254 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF489P254 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_idxPtSpt, Local_bCtrl_idxPtSpt);
		if (ACTIVATED == Local_bCtrl_idxPtSpt)
		{
			FHCAN489_vidCalcMonFP218Window();
			Com_ReceiveSignal(Com_IND_SPORT_GMP_PRCT_V2_BV_489, (void*) &ISCAN_u8N8F489P218);

			FHCAN489_vidMonInvldP218Update();
			FHCAN489_vidMonFrbdP218Update();

			FHCANF489_vidUpdateSignalP218();
		}
		else
		{
			VEMS_vidSET(Tra_idxPtSpt, 0);

			Ext_bMonRunFrbdF489P218 = FHCAN_DISABLE;
			Ext_bMonRunInvldF489P218 = FHCAN_DISABLE;
			Ext_bDgoFrbdF489P218 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF489P218 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunBVAbsent = FHCAN_DISABLE;
		Ext_bDgoBVAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF489 = FHCAN_DISABLE;
		Ext_bMonRunShoF489 = FHCAN_DISABLE;
		Ext_bMonRunInvldF489P102 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF489P254 = FHCAN_DISABLE;
		Ext_bMonRunInvldF489P254 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF489P218 = FHCAN_DISABLE;
		Ext_bMonRunInvldF489P218 = FHCAN_DISABLE;

		Ext_bDgoMissF489 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF489 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF489P102 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF489P254 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF489P254 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF489P218 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF489P218 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF489_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF489P102_in;
	boolean FRM_bAcvRcvF489P254_in;
	boolean FRM_bAcvRcvF489P218_in;
	boolean FRM_bAcvRcvF489_in;
	boolean Local_bCtrl_V2_BV_489;
	boolean Local_bCtrl_stGBxDft;
	boolean Local_bCtrl_bLevMod;
	boolean Local_bCtrl_bGBxRdy;
	boolean Local_bCtrl_bSpdFanGBxReq;
	boolean Local_bCtrl_bInhStrtAMT;
	boolean Local_bCtrl_bCntMILRst;
	boolean Local_bCtrl_bLiMILReqGUS;
	boolean Local_bCtrl_bLiMILReq;
	boolean Local_bCtrl_tOilGBx;
	boolean Local_bCtrl_tqCnvExtd;
	boolean Local_bCtrl_idxPtSpt;
	uint8 Local_Tra_stGBxDft;
	boolean Local_Tra_bGBxRdy;
	boolean Local_Tra_bCntMILRst;
	boolean Local_Tra_bLiMILReqGUS;
	boolean Local_Tra_bLiMILReq;


	VEMS_vidGET(Ctrl_V2_BV_489, Local_bCtrl_V2_BV_489);
	if (ACTIVATED == Local_bCtrl_V2_BV_489)
	{
		FHCAN489_vidCalcMonBVWindow();
		FHCAN489_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunBVAbsent)
		{
			Ext_bDgoBVAbsent = FHCAN_DETECTED;
			GDGAR_vidGdu(GD_DFT_BVABSENT,
						Ext_bDgoBVAbsent,
						Ext_bMonRunBVAbsent,
						DIAG_DISPO);
		}
      if (FHCAN_ENABLE == Ext_bMonRunMissF489)
      {
         Ext_bDgoMissF489 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF489,
                  Ext_bDgoMissF489,
                  Ext_bMonRunMissF489,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Tra_stGBxDft, 0);
		   VEMS_vidSET(Tra_stGBxMod, 0);
		   VEMS_vidSET(Tra_bLevMod, 0);
		   VEMS_vidSET(Tra_bGBxRdy, 1);
		   VEMS_vidSET(GBx_bSpdFanGBxReq, 0);
		   VEMS_vidSET(Ext_bInhStrtAMT, 0);
		   VEMS_vidSET(Ext_bDgoSenPN, 0);
		   VEMS_vidSET(Tra_bCntMILRst, 0);
		   VEMS_vidSET(Tra_bLiMILReqGUS, 0);
		   VEMS_vidSET(Tra_bLiMILReq, 0);
		   VEMS_vidSET(Ext_tOilGBx, 20);
		   VEMS_vidSET(Tra_tqCnvExtd, 0);
		   VEMS_vidSET(Tra_idxPtSpt, 0);
      }

		FRM_bAcvRcvF489P102_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489P102);
		FRM_bAcvRcvF489P254_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489P254);
		FRM_bAcvRcvF489P218_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489P218);
		FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);

		VEMS_vidGET(Ctrl_stGBxDft, Local_bCtrl_stGBxDft);
		if (ACTIVATED == Local_bCtrl_stGBxDft)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF489_in)
			{
		      VEMS_vidGET(Tra_stGBxDft, Local_Tra_stGBxDft);
		      VEMS_vidSET(Tra_stGBxDft, Local_Tra_stGBxDft);
			}
		}
		VEMS_vidGET(Ctrl_bLevMod, Local_bCtrl_bLevMod);
		if (ACTIVATED == Local_bCtrl_bLevMod)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF489_in)
			{
		      VEMS_vidSET(Tra_stGBxMod, Tra_stGBxModRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bGBxRdy, Local_bCtrl_bGBxRdy);
		if (ACTIVATED == Local_bCtrl_bGBxRdy)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF489_in)
			{
		      VEMS_vidGET(Tra_bGBxRdy, Local_Tra_bGBxRdy);
		      VEMS_vidSET(Tra_bGBxRdy, Local_Tra_bGBxRdy);
			}
		}
		VEMS_vidGET(Ctrl_bSpdFanGBxReq, Local_bCtrl_bSpdFanGBxReq);
		if (ACTIVATED == Local_bCtrl_bSpdFanGBxReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF489_in)
			{
		      VEMS_vidSET(GBx_bSpdFanGBxReq, GBx_bSpdFanGBxReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bInhStrtAMT, Local_bCtrl_bInhStrtAMT);
		if (ACTIVATED == Local_bCtrl_bInhStrtAMT)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF489_in)
			{
		      VEMS_vidSET(Ext_bInhStrtAMT, Ext_bInhStrtAMTRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bCntMILRst, Local_bCtrl_bCntMILRst);
		if (ACTIVATED == Local_bCtrl_bCntMILRst)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF489_in)
			{
		      VEMS_vidGET(Tra_bCntMILRst, Local_Tra_bCntMILRst);
		      VEMS_vidSET(Tra_bCntMILRst, Local_Tra_bCntMILRst);
			}
		}
		VEMS_vidGET(Ctrl_bLiMILReqGUS, Local_bCtrl_bLiMILReqGUS);
		if (ACTIVATED == Local_bCtrl_bLiMILReqGUS)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF489_in)
			{
		      VEMS_vidGET(Tra_bLiMILReqGUS, Local_Tra_bLiMILReqGUS);
		      VEMS_vidSET(Tra_bLiMILReqGUS, Local_Tra_bLiMILReqGUS);
			}
		}
		VEMS_vidGET(Ctrl_bLiMILReq, Local_bCtrl_bLiMILReq);
		if (ACTIVATED == Local_bCtrl_bLiMILReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF489_in)
			{
		      VEMS_vidGET(Tra_bLiMILReq, Local_Tra_bLiMILReq);
		      VEMS_vidSET(Tra_bLiMILReq, Local_Tra_bLiMILReq);
			}
		}
		VEMS_vidGET(Ctrl_tOilGBx, Local_bCtrl_tOilGBx);
		if (ACTIVATED == Local_bCtrl_tOilGBx)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF489P102_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF489_in))
			{
		      VEMS_vidSET(Ext_tOilGBx, Ext_tOilGBxRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_tqCnvExtd, Local_bCtrl_tqCnvExtd);
		if (ACTIVATED == Local_bCtrl_tqCnvExtd)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF489P254_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF489_in))
			{
		      VEMS_vidSET(Tra_tqCnvExtd, Tra_tqCnvExtdRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_idxPtSpt, Local_bCtrl_idxPtSpt);
		if (ACTIVATED == Local_bCtrl_idxPtSpt)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF489P218_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF489_in))
			{
		      VEMS_vidSET(Tra_idxPtSpt, Tra_idxPtSptRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunBVAbsent = FHCAN_DISABLE;
		Ext_bDgoBVAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF489 = FHCAN_DISABLE;
		Ext_bMonRunShoF489 = FHCAN_DISABLE;
		Ext_bMonRunInvldF489P102 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF489P254 = FHCAN_DISABLE;
		Ext_bMonRunInvldF489P254 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF489P218 = FHCAN_DISABLE;
		Ext_bMonRunInvldF489P218 = FHCAN_DISABLE;

		Ext_bDgoMissF489 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF489 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF489P102 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF489P254 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF489P254 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF489P218 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF489P218 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF489_vidUpdateSignalP282(void)
{
	boolean FRM_bAcvRcvF489_in;
   uint8 u8LocalTra_stGBxDft;

	uint8 Local_Tra_stGBxDft;

	FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF489_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF489)
	   )
	{
      u8LocalTra_stGBxDft = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F489P282,
                                             15));
      VEMS_vidSET(Tra_stGBxDft,
                  u8LocalTra_stGBxDft);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF489_in)
      {
			VEMS_vidGET(Tra_stGBxDft, Local_Tra_stGBxDft);
			VEMS_vidSET(Tra_stGBxDft, Local_Tra_stGBxDft);
		}
	}
}

void FHCANF489_vidUpdateSignalP029(void)
{
	boolean FRM_bAcvRcvF489_in;
   uint8 u8LocalTra_stGBxMod;

	FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF489_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF489)
	   )
	{
      u8LocalTra_stGBxMod = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F489P029,
                                             3));
      VEMS_vidSET(Tra_stGBxMod,
                  u8LocalTra_stGBxMod);
		if (ISCAN_u8N2F489P029 == 2)
		{
         VEMS_vidSET(Tra_bLevMod, 1);
		}
		else
		{
         VEMS_vidSET(Tra_bLevMod, 0);
		}
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF489_in)
      {
			VEMS_vidSET(Tra_stGBxMod, Tra_stGBxModRcf_C);
		}
	}
}

void FHCANF489_vidUpdateSignalP374(void)
{
	boolean FRM_bAcvRcvF489_in;

	boolean Local_Tra_bGBxRdy;

	FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF489_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF489)
	   )
	{
      VEMS_vidSET(Tra_bGBxRdy,
                  ISCAN_bF489P374);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF489_in)
      {
			VEMS_vidGET(Tra_bGBxRdy, Local_Tra_bGBxRdy);
			VEMS_vidSET(Tra_bGBxRdy, Local_Tra_bGBxRdy);
		}
	}
}

void FHCANF489_vidUpdateSignalP048(void)
{
	boolean FRM_bAcvRcvF489_in;

	FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF489_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF489)
	   )
	{
      VEMS_vidSET(GBx_bSpdFanGBxReq,
                  ISCAN_bF489P048);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF489_in)
      {
			VEMS_vidSET(GBx_bSpdFanGBxReq, GBx_bSpdFanGBxReqRcf_C);
		}
	}
}

void FHCANF489_vidUpdateSignalP285(void)
{
	boolean FRM_bAcvRcvF489_in;

	FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF489_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF489)
	   )
	{
      VEMS_vidSET(Ext_bInhStrtAMT,
                  ISCAN_bF489P285 );
      VEMS_vidSET(Ext_bDgoSenPN,
                  ISCAN_bF489P285 );
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF489_in)
      {
			VEMS_vidSET(Ext_bInhStrtAMT, Ext_bInhStrtAMTRcf_C);
		}
	}
}

void FHCANF489_vidUpdateSignalP376(void)
{
	boolean FRM_bAcvRcvF489_in;

	boolean Local_Tra_bCntMILRst;

	FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF489_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF489)
	   )
	{
      VEMS_vidSET(Tra_bCntMILRst,
                  ISCAN_bF489P376);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF489_in)
      {
			VEMS_vidGET(Tra_bCntMILRst, Local_Tra_bCntMILRst);
			VEMS_vidSET(Tra_bCntMILRst, Local_Tra_bCntMILRst);
		}
	}
}

void FHCANF489_vidUpdateSignalPM1423(void)
{
	boolean FRM_bAcvRcvF489_in;

	boolean Local_Tra_bLiMILReqGUS;

	FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF489_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF489)
	   )
	{
      VEMS_vidSET(Tra_bLiMILReqGUS,
                  ISCAN_bF489PM1423);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF489_in)
      {
			VEMS_vidGET(Tra_bLiMILReqGUS, Local_Tra_bLiMILReqGUS);
			VEMS_vidSET(Tra_bLiMILReqGUS, Local_Tra_bLiMILReqGUS);
		}
	}
}

void FHCANF489_vidUpdateSignalP375(void)
{
	boolean FRM_bAcvRcvF489_in;

	boolean Local_Tra_bLiMILReq;

	FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF489_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF489)
	   )
	{
      VEMS_vidSET(Tra_bLiMILReq,
                  ISCAN_bF489P375);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF489_in)
      {
			VEMS_vidGET(Tra_bLiMILReq, Local_Tra_bLiMILReq);
			VEMS_vidSET(Tra_bLiMILReq, Local_Tra_bLiMILReq);
		}
	}
}

void FHCANF489_vidUpdateSignalP102(void)
{
	boolean FRM_bAcvRcvF489P102_in;
	boolean FRM_bAcvRcvF489_in;
   sint16 s16LocalIscanV2_BV_489;
   sint16 s16LocalExt_tOilGBx;

	FRM_bAcvRcvF489P102_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489P102);
	FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF489P102_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF489_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF489P102)
	   && (FHCAN_DETECTED != Ext_bDgoShoF489)
	   )
	{
      s16LocalIscanV2_BV_489 = (sint16)((ISCAN_u8N8F489P102) - 40);
      s16LocalExt_tOilGBx = (sint16)(MATHSRV_udtCLAMP(s16LocalIscanV2_BV_489,
                                               -40,
                                               250));
      VEMS_vidSET(Ext_tOilGBx,
                  s16LocalExt_tOilGBx);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF489P102_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF489_in))
      {
			VEMS_vidSET(Ext_tOilGBx, Ext_tOilGBxRcf_C);
		}
	}
}

void FHCANF489_vidUpdateSignalP254(void)
{
	boolean FRM_bAcvRcvF489P254_in;
	boolean FRM_bAcvRcvF489_in;
   uint16 u16LocalTra_tqCnvExtd;

	FRM_bAcvRcvF489P254_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489P254);
	FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF489P254_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF489_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF489P254)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF489P254)
	   && (FHCAN_DETECTED != Ext_bDgoShoF489)
	   )
	{
      u16LocalTra_tqCnvExtd = (uint16)(MATHSRV_udtMIN(ISCAN_u16N12F489P254,
                                             3900));
      VEMS_vidSET(Tra_tqCnvExtd,
                  u16LocalTra_tqCnvExtd);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF489P254_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF489_in))
      {
			VEMS_vidSET(Tra_tqCnvExtd, Tra_tqCnvExtdRcf_C);
		}
	}
}

void FHCANF489_vidUpdateSignalP218(void)
{
	boolean FRM_bAcvRcvF489P218_in;
	boolean FRM_bAcvRcvF489_in;
   uint8 u8LocalTra_idxPtSpt;

	FRM_bAcvRcvF489P218_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489P218);
	FRM_bAcvRcvF489_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF489);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF489P218_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF489_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF489P218)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF489P218)
	   && (FHCAN_DETECTED != Ext_bDgoShoF489)
	   )
	{
      u8LocalTra_idxPtSpt = (uint8)(MATHSRV_udtMIN(ISCAN_u8N8F489P218,
                                             100));
      VEMS_vidSET(Tra_idxPtSpt,
                  u8LocalTra_idxPtSpt);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF489P218_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF489_in))
      {
			VEMS_vidSET(Tra_idxPtSpt, Tra_idxPtSptRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

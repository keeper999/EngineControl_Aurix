/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3C9.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF3C9.H"
#include "FHCANF3C9_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_3C9(void)
{
	ISCAN_u8N8F3C9P363 = 50;
	ISCAN_u8N3F3C9P481 = 0;
	ISCAN_u8N4F3C9PM2854 = 0;
	ISCAN_u8N4F3C9PM2843 = 0;
	ISCAN_u16N12F3C9P364 = 0;
	ISCAN_u8N6F3C9P482 = 0;
	ISCAN_u16N10F3C9P483 = 0;

	VEMS_vidSET(Ext_tqCkCAN, 0);
	VEMS_vidSET(Tra_stGearCtlFirst, 0);
	VEMS_vidSET(Ext_noCks3C9, 0);
	VEMS_vidSET(Ext_ctClcProc3C9, 0);
	VEMS_vidSET(Tra_nTrb, 0);
	VEMS_vidSET(Tra_nPrimShaft, 0);
	VEMS_vidSET(Tra_tqLoss, 0);
	VEMS_vidSET(Tra_rCnvTq, 0);
	VEMS_vidSET(Tra_rConvTra, 0);

	Ext_bMonRunMissF3C9 = FHCAN_DISABLE;
	Ext_bMonRunShoF3C9 = FHCAN_DISABLE;
	Ext_bMonRunChkF3C9 = FHCAN_DISABLE;
	Ext_bMonRunInvldF3C9P363 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF3C9P481 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF3C9P364 = FHCAN_DISABLE;
	Ext_bMonRunInvldF3C9P364 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF3C9P482 = FHCAN_DISABLE;
	Ext_bMonRunInvldF3C9P482 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF3C9P483 = FHCAN_DISABLE;
	Ext_bMonRunInvldF3C9P483 = FHCAN_DISABLE;

	Ext_bDgoMissF3C9 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF3C9 = FHCAN_NOT_DETECTED;
	Ext_bDgoChkF3C9 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF3C9P363 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF3C9P481 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF3C9P364 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF3C9P364 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF3C9P482 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF3C9P482 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF3C9P483 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF3C9P483 = FHCAN_NOT_DETECTED;
}

void FHCANF3C9_vidFrameReceived(void)
{
	boolean Local_bCtrl_V2_BV_3C9;
	boolean Local_bCtrl_tqCkCAN;
	boolean Local_bCtrl_bGearCtlFirst;
	boolean Local_bCtrl_noCks3C9;
	boolean Local_bCtrl_ctClcProc3C9;
	boolean Local_bCtrl_nTrb;
	boolean Local_bCtrl_tqLoss;
	boolean Local_bCtrl_rCnvTq;

	VEMS_vidGET(Ctrl_V2_BV_3C9, Local_bCtrl_V2_BV_3C9);
	if (ACTIVATED == Local_bCtrl_V2_BV_3C9)
	{
		ISCAN_EveRxn_3C9();
		FHCAN3C9_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF3C9)
      {
         Ext_bDgoMissF3C9 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF3C9,
                  Ext_bDgoMissF3C9,
                  Ext_bMonRunMissF3C9,
                  DIAG_DISPO);
      }
            
		if (FHCAN_ENABLE == Ext_bMonRunCntF3C9)
      {
         Ext_bDgoCntF3C9 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF3C9,
                  Ext_bDgoCntF3C9,
                  Ext_bMonRunCntF3C9,
                  DIAG_DISPO);
      }

		VEMS_vidGET(Ctrl_tqCkCAN, Local_bCtrl_tqCkCAN);
		if (ACTIVATED == Local_bCtrl_tqCkCAN)
		{
			FHCAN3C9_vidCalcMonFP363Window();
			Com_ReceiveSignal(Com_C2000_V2_BV_3C9, (void*) &ISCAN_u8N8F3C9P363);

			FHCAN3C9_vidMonInvldP363Update();

			FHCANF3C9_vidUpdateSignalP363();
		}
		else
		{
			VEMS_vidSET(Ext_tqCkCAN, 0);

			Ext_bMonRunInvldF3C9P363 = FHCAN_DISABLE;
			Ext_bDgoInvldF3C9P363 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bGearCtlFirst, Local_bCtrl_bGearCtlFirst);
		if (ACTIVATED == Local_bCtrl_bGearCtlFirst)
		{
			FHCAN3C9_vidCalcMonFP481Window();
			Com_ReceiveSignal(Com_GMP_TRANS_STS_V2_BV_3C9, (void*) &ISCAN_u8N3F3C9P481);

			FHCAN3C9_vidMonFrbdP481Update();

			FHCANF3C9_vidUpdateSignalP481();
		}
		else
		{
			VEMS_vidSET(Tra_stGearCtlFirst, 0);

			Ext_bMonRunFrbdF3C9P481 = FHCAN_DISABLE;
			Ext_bDgoFrbdF3C9P481 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_noCks3C9, Local_bCtrl_noCks3C9);
		if (ACTIVATED == Local_bCtrl_noCks3C9)
		{
			Com_ReceiveSignal(Com_CHKSUM_TRME_DYN_V2_3C9_V2_BV_3C9, (void*) &ISCAN_u8N4F3C9PM2854);


			FHCANF3C9_vidUpdateSignalPM2854();
		}
		else
		{
			VEMS_vidSET(Ext_noCks3C9, 0);

		}
		VEMS_vidGET(Ctrl_ctClcProc3C9, Local_bCtrl_ctClcProc3C9);
		if (ACTIVATED == Local_bCtrl_ctClcProc3C9)
		{
			Com_ReceiveSignal(Com_CPT_PROCESS_4B_V2_3C9_V2_BV_3C9, (void*) &ISCAN_u8N4F3C9PM2843);


			FHCANF3C9_vidUpdateSignalPM2843();
		}
		else
		{
			VEMS_vidSET(Ext_ctClcProc3C9, 0);

		}
		VEMS_vidGET(Ctrl_nTrb, Local_bCtrl_nTrb);
		if (ACTIVATED == Local_bCtrl_nTrb)
		{
			FHCAN3C9_vidCalcMonFP364Window();
			Com_ReceiveSignal(Com_REGIME_ENT_BOITE_ETENDU_V2_BV_3C9, (void*) &ISCAN_u16N12F3C9P364);

			FHCAN3C9_vidMonInvldP364Update();
			FHCAN3C9_vidMonFrbdP364Update();

			FHCANF3C9_vidUpdateSignalP364();
		}
		else
		{
			VEMS_vidSET(Tra_nTrb, 0);
			VEMS_vidSET(Tra_nPrimShaft, 0);

			Ext_bMonRunFrbdF3C9P364 = FHCAN_DISABLE;
			Ext_bMonRunInvldF3C9P364 = FHCAN_DISABLE;
			Ext_bDgoFrbdF3C9P364 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF3C9P364 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_tqLoss, Local_bCtrl_tqLoss);
		if (ACTIVATED == Local_bCtrl_tqLoss)
		{
			FHCAN3C9_vidCalcMonFP482Window();
			Com_ReceiveSignal(Com_CPLE_PERTE_BVA_V2_BV_3C9, (void*) &ISCAN_u8N6F3C9P482);

			FHCAN3C9_vidMonInvldP482Update();
			FHCAN3C9_vidMonFrbdP482Update();

			FHCANF3C9_vidUpdateSignalP482();
		}
		else
		{
			VEMS_vidSET(Tra_tqLoss, 0);

			Ext_bMonRunFrbdF3C9P482 = FHCAN_DISABLE;
			Ext_bMonRunInvldF3C9P482 = FHCAN_DISABLE;
			Ext_bDgoFrbdF3C9P482 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF3C9P482 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_rCnvTq, Local_bCtrl_rCnvTq);
		if (ACTIVATED == Local_bCtrl_rCnvTq)
		{
			FHCAN3C9_vidCalcMonFP483Window();
			Com_ReceiveSignal(Com_TAUX_CONV_CPLE_GMP_V2_BV_3C9, (void*) &ISCAN_u16N10F3C9P483);

			FHCAN3C9_vidMonInvldP483Update();
			FHCAN3C9_vidMonFrbdP483Update();

			FHCANF3C9_vidUpdateSignalP483();
		}
		else
		{
			VEMS_vidSET(Tra_rCnvTq, 0);
			VEMS_vidSET(Tra_rConvTra, 0);

			Ext_bMonRunFrbdF3C9P483 = FHCAN_DISABLE;
			Ext_bMonRunInvldF3C9P483 = FHCAN_DISABLE;
			Ext_bDgoFrbdF3C9P483 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF3C9P483 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF3C9 = FHCAN_DISABLE;
		Ext_bMonRunShoF3C9 = FHCAN_DISABLE;
		Ext_bMonRunChkF3C9 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3C9P363 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3C9P481 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3C9P364 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3C9P364 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3C9P482 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3C9P482 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3C9P483 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3C9P483 = FHCAN_DISABLE;

		Ext_bDgoMissF3C9 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF3C9 = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF3C9 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3C9P363 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3C9P481 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3C9P364 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3C9P364 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3C9P482 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3C9P482 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3C9P483 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3C9P483 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF3C9_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF3C9P363_in;
	boolean FRM_bAcvRcvF3C9P481_in;
	boolean FRM_bAcvRcvF3C9P364_in;
	boolean FRM_bAcvRcvF3C9P482_in;
	boolean FRM_bAcvRcvF3C9P483_in;
	boolean FRM_bAcvRcvF3C9_in;
	boolean Local_bCtrl_V2_BV_3C9;
	boolean Local_bCtrl_tqCkCAN;
	boolean Local_bCtrl_bGearCtlFirst;
	boolean Local_bCtrl_noCks3C9;
	boolean Local_bCtrl_ctClcProc3C9;
	boolean Local_bCtrl_nTrb;
	boolean Local_bCtrl_tqLoss;
	boolean Local_bCtrl_rCnvTq;
	uint8 Local_Ext_noCks3C9;
	uint8 Local_Ext_ctClcProc3C9;


	VEMS_vidGET(Ctrl_V2_BV_3C9, Local_bCtrl_V2_BV_3C9);
	if (ACTIVATED == Local_bCtrl_V2_BV_3C9)
	{
		FHCAN3C9_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF3C9)
      {
         Ext_bDgoMissF3C9 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF3C9,
                  Ext_bDgoMissF3C9,
                  Ext_bMonRunMissF3C9,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_tqCkCAN, 0);
		   VEMS_vidSET(Tra_stGearCtlFirst, 0);
		   VEMS_vidSET(Ext_noCks3C9, 0);
		   VEMS_vidSET(Ext_ctClcProc3C9, 0);
		   VEMS_vidSET(Tra_nTrb, 0);
		   VEMS_vidSET(Tra_nPrimShaft, 0);
		   VEMS_vidSET(Tra_tqLoss, 0);
		   VEMS_vidSET(Tra_rCnvTq, 0);
		   VEMS_vidSET(Tra_rConvTra, 0);
      }

		FRM_bAcvRcvF3C9P363_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9P363);
		FRM_bAcvRcvF3C9P481_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9P481);
		FRM_bAcvRcvF3C9P364_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9P364);
		FRM_bAcvRcvF3C9P482_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9P482);
		FRM_bAcvRcvF3C9P483_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9P483);
		FRM_bAcvRcvF3C9_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9);

		VEMS_vidGET(Ctrl_tqCkCAN, Local_bCtrl_tqCkCAN);
		if (ACTIVATED == Local_bCtrl_tqCkCAN)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF3C9P363_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF3C9_in))
			{
		      VEMS_vidSET(Ext_tqCkCAN, Ext_tqCkCANRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bGearCtlFirst, Local_bCtrl_bGearCtlFirst);
		if (ACTIVATED == Local_bCtrl_bGearCtlFirst)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF3C9P481_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF3C9_in))
			{
		      VEMS_vidSET(Tra_stGearCtlFirst, Tra_stGearCtlFirstRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_noCks3C9, Local_bCtrl_noCks3C9);
		if (ACTIVATED == Local_bCtrl_noCks3C9)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF3C9_in)
			{
		      VEMS_vidGET(Ext_noCks3C9, Local_Ext_noCks3C9);
		      VEMS_vidSET(Ext_noCks3C9, Local_Ext_noCks3C9);
			}
		}
		VEMS_vidGET(Ctrl_ctClcProc3C9, Local_bCtrl_ctClcProc3C9);
		if (ACTIVATED == Local_bCtrl_ctClcProc3C9)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF3C9_in)
			{
		      VEMS_vidGET(Ext_ctClcProc3C9, Local_Ext_ctClcProc3C9);
		      VEMS_vidSET(Ext_ctClcProc3C9, Local_Ext_ctClcProc3C9);
			}
		}
		VEMS_vidGET(Ctrl_nTrb, Local_bCtrl_nTrb);
		if (ACTIVATED == Local_bCtrl_nTrb)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF3C9P364_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF3C9_in))
			{
		      VEMS_vidSET(Tra_nTrb, 500);
			}
		}
		VEMS_vidGET(Ctrl_tqLoss, Local_bCtrl_tqLoss);
		if (ACTIVATED == Local_bCtrl_tqLoss)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF3C9P482_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF3C9_in))
			{
		      VEMS_vidSET(Tra_tqLoss, Tra_tqLossRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_rCnvTq, Local_bCtrl_rCnvTq);
		if (ACTIVATED == Local_bCtrl_rCnvTq)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF3C9P483_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF3C9_in))
			{
		      VEMS_vidSET(Tra_rCnvTq, Tra_rCnvTqRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF3C9 = FHCAN_DISABLE;
		Ext_bMonRunShoF3C9 = FHCAN_DISABLE;
		Ext_bMonRunChkF3C9 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3C9P363 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3C9P481 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3C9P364 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3C9P364 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3C9P482 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3C9P482 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3C9P483 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3C9P483 = FHCAN_DISABLE;

		Ext_bDgoMissF3C9 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF3C9 = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF3C9 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3C9P363 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3C9P481 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3C9P364 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3C9P364 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3C9P482 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3C9P482 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3C9P483 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3C9P483 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF3C9_vidUpdateSignalP363(void)
{
	boolean FRM_bAcvRcvF3C9P363_in;
	boolean FRM_bAcvRcvF3C9_in;
   sint16 s16LocalIscanV2_BV_3C9;
   sint16 s16LocalExt_tqCkCAN;

	FRM_bAcvRcvF3C9P363_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9P363);
	FRM_bAcvRcvF3C9_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9P363_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF3C9P363)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3C9)
	   )
	{
      s16LocalIscanV2_BV_3C9 = (sint16)((ISCAN_u8N8F3C9P363) - 50);
      s16LocalExt_tqCkCAN = (sint16)(MATHSRV_udtCLAMP(s16LocalIscanV2_BV_3C9,
                                               -50,
                                               204));
      VEMS_vidSET(Ext_tqCkCAN,
                  s16LocalExt_tqCkCAN);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF3C9P363_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF3C9_in))
      {
			VEMS_vidSET(Ext_tqCkCAN, Ext_tqCkCANRcf_C);
		}
	}
}

void FHCANF3C9_vidUpdateSignalP481(void)
{
	boolean FRM_bAcvRcvF3C9P481_in;
	boolean FRM_bAcvRcvF3C9_in;
   uint8 u8LocalTra_stGearCtlFirst;

	FRM_bAcvRcvF3C9P481_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9P481);
	FRM_bAcvRcvF3C9_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9P481_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF3C9P481)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3C9)
	   )
	{
      u8LocalTra_stGearCtlFirst = (uint8)(MATHSRV_udtMIN(ISCAN_u8N3F3C9P481,
                                             7));
      VEMS_vidSET(Tra_stGearCtlFirst,
                  u8LocalTra_stGearCtlFirst);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF3C9P481_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF3C9_in))
      {
			VEMS_vidSET(Tra_stGearCtlFirst, Tra_stGearCtlFirstRcf_C);
		}
	}
}

void FHCANF3C9_vidUpdateSignalPM2854(void)
{
	boolean FRM_bAcvRcvF3C9_in;
   uint8 u8LocalExt_noCks3C9;

	uint8 Local_Ext_noCks3C9;

	FRM_bAcvRcvF3C9_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3C9)
	   )
	{
      u8LocalExt_noCks3C9 = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F3C9PM2854,
                                             15));
      VEMS_vidSET(Ext_noCks3C9,
                  u8LocalExt_noCks3C9);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF3C9_in)
      {
			VEMS_vidGET(Ext_noCks3C9, Local_Ext_noCks3C9);
			VEMS_vidSET(Ext_noCks3C9, Local_Ext_noCks3C9);
		}
	}
}

void FHCANF3C9_vidUpdateSignalPM2843(void)
{
	boolean FRM_bAcvRcvF3C9_in;
   uint8 u8LocalExt_ctClcProc3C9;

	uint8 Local_Ext_ctClcProc3C9;

	FRM_bAcvRcvF3C9_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3C9)
	   )
	{
      u8LocalExt_ctClcProc3C9 = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F3C9PM2843,
                                             15));
      VEMS_vidSET(Ext_ctClcProc3C9,
                  u8LocalExt_ctClcProc3C9);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF3C9_in)
      {
			VEMS_vidGET(Ext_ctClcProc3C9, Local_Ext_ctClcProc3C9);
			VEMS_vidSET(Ext_ctClcProc3C9, Local_Ext_ctClcProc3C9);
		}
	}
}

void FHCANF3C9_vidUpdateSignalP364(void)
{
	boolean FRM_bAcvRcvF3C9P364_in;
	boolean FRM_bAcvRcvF3C9_in;
   uint16 u16LocalTra_nTrb;
   uint32 u32LocalIscanV2_BV_3C9;
   uint16 u16LocalTra_nPrimShaft;

	FRM_bAcvRcvF3C9P364_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9P364);
	FRM_bAcvRcvF3C9_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9P364_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF3C9P364)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF3C9P364)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3C9)
	   )
	{
      u16LocalTra_nTrb = (uint16)(MATHSRV_udtMIN(ISCAN_u16N12F3C9P364,
                                             4000));
      VEMS_vidSET(Tra_nTrb,
                  u16LocalTra_nTrb);
      u32LocalIscanV2_BV_3C9 = (uint32)(8 * ISCAN_u16N12F3C9P364);
      u16LocalTra_nPrimShaft = (uint16)(MATHSRV_udtMIN(u32LocalIscanV2_BV_3C9,
                                             32000));
      VEMS_vidSET(Tra_nPrimShaft,
                  u16LocalTra_nPrimShaft);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF3C9P364_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF3C9_in))
      {
			VEMS_vidSET(Tra_nTrb, 500);
		}
	}
}

void FHCANF3C9_vidUpdateSignalP482(void)
{
	boolean FRM_bAcvRcvF3C9P482_in;
	boolean FRM_bAcvRcvF3C9_in;
   uint16 u16LocalIscanV2_BV_3C9;
   sint16 s16LocalTra_tqLoss;

	FRM_bAcvRcvF3C9P482_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9P482);
	FRM_bAcvRcvF3C9_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9P482_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF3C9P482)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF3C9P482)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3C9)
	   )
	{
      u16LocalIscanV2_BV_3C9 = (uint16)(32 * ISCAN_u8N6F3C9P482);
      s16LocalTra_tqLoss = (sint16)(MATHSRV_udtCLAMP(u16LocalIscanV2_BV_3C9,
                                               -32000,
                                               32000));
      VEMS_vidSET(Tra_tqLoss,
                  s16LocalTra_tqLoss);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF3C9P482_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF3C9_in))
      {
			VEMS_vidSET(Tra_tqLoss, Tra_tqLossRcf_C);
		}
	}
}

void FHCANF3C9_vidUpdateSignalP483(void)
{
	boolean FRM_bAcvRcvF3C9P483_in;
	boolean FRM_bAcvRcvF3C9_in;
   uint32 u32LocalIscanV2_BV_3C9;
   uint16 u16LocalTra_rCnvTq;
   uint16 u16LocalTra_rConvTra;

	FRM_bAcvRcvF3C9P483_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9P483);
	FRM_bAcvRcvF3C9_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3C9);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9P483_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF3C9_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF3C9P483)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF3C9P483)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3C9)
	   )
	{
      u32LocalIscanV2_BV_3C9 = (uint32)(((96 * ISCAN_u16N10F3C9P483) / 25));
      u16LocalTra_rCnvTq = (uint16)(MATHSRV_udtMIN(u32LocalIscanV2_BV_3C9,
                                             2560));
      VEMS_vidSET(Tra_rCnvTq,
                  u16LocalTra_rCnvTq);
      u32LocalIscanV2_BV_3C9 = (uint32)(((96 * ISCAN_u16N10F3C9P483) / 25));
      u16LocalTra_rConvTra = (uint16)(MATHSRV_udtMIN(u32LocalIscanV2_BV_3C9,
                                             5120));
      VEMS_vidSET(Tra_rConvTra,
                  u16LocalTra_rConvTra);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF3C9P483_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF3C9_in))
      {
			VEMS_vidSET(Tra_rCnvTq, Tra_rCnvTqRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

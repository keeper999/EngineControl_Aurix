/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF4F2.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF4F2.H"
#include "FHCANF4F2_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_4F2(void)
{
	ISCAN_u16N10F4F2P434 = 1000;
	ISCAN_u16N10F4F2P438 = 1000;
	ISCAN_u8N2F4F2P429 = 3;
	ISCAN_u8N2F4F2P703 = 0;
	ISCAN_u16N9F4F2P437 = 300;
	ISCAN_u8N6F4F2P490 = 0;
	ISCAN_u8N2F4F2P493 = 2;
	ISCAN_u8N6F4F2P491 = 44;
	ISCAN_u8N2F4F2P494 = 2;
	ISCAN_u8N7F4F2P492 = 5;
	ISCAN_bF4F2P702 = 0;

	VEMS_vidSET(Ext_rBattSoC, 1600);
	VEMS_vidSET(Ext_bNotAvl_rBattSoC, AVAILABLE);
	VEMS_vidSET(Ext_resBattIt, 1280);
	VEMS_vidSET(Ext_bNotAvl_resBattIt, AVAILABLE);
	VEMS_vidSET(Ext_stBattSoC, 3);
	VEMS_vidSET(ShdFlap_stPosn, 0);
	VEMS_vidSET(Ext_uBattOc, 1792);
	VEMS_vidSET(Ext_bNotAvl_uBattOc, AVAILABLE);
	VEMS_vidSET(ElecMgt_uReqProdMin, 169.6);
	VEMS_vidSET(ElecMgt_stPrioVoltMin, 2);
	VEMS_vidSET(ElecMgt_uReqProdMax, 240);
	VEMS_vidSET(ElecMgt_stPrioVoltMax, 2);
	VEMS_vidSET(ElecMgt_uReqProdSlope, 8);
	VEMS_vidSET(AC_bOpFSFReq, 0);

	Ext_bMonRunMissF4F2 = FHCAN_DISABLE;
	Ext_bMonRunShoF4F2 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF4F2P434 = FHCAN_DISABLE;
	Ext_bMonRunInvldF4F2P434 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF4F2P438 = FHCAN_DISABLE;
	Ext_bMonRunInvldF4F2P438 = FHCAN_DISABLE;
	Ext_bMonRunInvldF4F2P429 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF4F2P437 = FHCAN_DISABLE;
	Ext_bMonRunInvldF4F2P437 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF4F2P490 = FHCAN_DISABLE;
	Ext_bMonRunInvldF4F2P490 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF4F2P493 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF4F2P491 = FHCAN_DISABLE;
	Ext_bMonRunInvldF4F2P491 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF4F2P494 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF4F2P492 = FHCAN_DISABLE;
	Ext_bMonRunInvldF4F2P492 = FHCAN_DISABLE;

	Ext_bDgoMissF4F2 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF4F2 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF4F2P434 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF4F2P434 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF4F2P438 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF4F2P438 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF4F2P429 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF4F2P437 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF4F2P437 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF4F2P490 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF4F2P490 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF4F2P493 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF4F2P491 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF4F2P491 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF4F2P494 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF4F2P492 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF4F2P492 = FHCAN_NOT_DETECTED;
}

void FHCANF4F2_vidFrameReceived(void)
{
	boolean Local_bCtrl_BSI_4F2;
	boolean Local_bCtrl_rBattSoC;
	boolean Local_bCtrl_resBattIt;
	boolean Local_bCtrl_stBattSoC;
	boolean Local_bCtrl_stPosn;
	boolean Local_bCtrl_uBattOc;
	boolean Local_bCtrl_uReqProdMin;
	boolean Local_bCtrl_stPrioVoltMin;
	boolean Local_bCtrl_uReqProdMax;
	boolean Local_bCtrl_stPrioVoltMax;
	boolean Local_bCtrl_uReqProdSlope;
	boolean Local_bCtrl_bOpFSFReq;

	VEMS_vidGET(Ctrl_BSI_4F2, Local_bCtrl_BSI_4F2);
	if (ACTIVATED == Local_bCtrl_BSI_4F2)
	{
		ISCAN_EveRxn_4F2();
		FHCAN4F2_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF4F2)
      {
         Ext_bDgoMissF4F2 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF4F2,
                  Ext_bDgoMissF4F2,
                  Ext_bMonRunMissF4F2,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_rBattSoC, Local_bCtrl_rBattSoC);
		if (ACTIVATED == Local_bCtrl_rBattSoC)
		{
			FHCAN4F2_vidCalcMonFP434Window();
			Com_ReceiveSignal(Com_VALEUR_SOC_ETENDUE_BSI_4F2, (void*) &ISCAN_u16N10F4F2P434);

			FHCAN4F2_vidMonInvldP434Update();
			FHCAN4F2_vidMonFrbdP434Update();

			FHCANF4F2_vidUpdateSignalP434();
		}
		else
		{
			VEMS_vidSET(Ext_rBattSoC, 1600);
			VEMS_vidSET(Ext_bNotAvl_rBattSoC, AVAILABLE);
			Ext_bMonRunFrbdF4F2P434 = FHCAN_DISABLE;
			Ext_bMonRunInvldF4F2P434 = FHCAN_DISABLE;
			Ext_bDgoFrbdF4F2P434 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF4F2P434 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_resBattIt, Local_bCtrl_resBattIt);
		if (ACTIVATED == Local_bCtrl_resBattIt)
		{
			FHCAN4F2_vidCalcMonFP438Window();
			Com_ReceiveSignal(Com_BAT_RES_INT_ESTIM_BSI_4F2, (void*) &ISCAN_u16N10F4F2P438);

			FHCAN4F2_vidMonInvldP438Update();
			FHCAN4F2_vidMonFrbdP438Update();

			FHCANF4F2_vidUpdateSignalP438();
		}
		else
		{
			VEMS_vidSET(Ext_resBattIt, 1280);
			VEMS_vidSET(Ext_bNotAvl_resBattIt, AVAILABLE);
			Ext_bMonRunFrbdF4F2P438 = FHCAN_DISABLE;
			Ext_bMonRunInvldF4F2P438 = FHCAN_DISABLE;
			Ext_bDgoFrbdF4F2P438 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF4F2P438 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stBattSoC, Local_bCtrl_stBattSoC);
		if (ACTIVATED == Local_bCtrl_stBattSoC)
		{
			FHCAN4F2_vidCalcMonFP429Window();
			Com_ReceiveSignal(Com_STATUS_SOC_BSI_4F2, (void*) &ISCAN_u8N2F4F2P429);

			FHCAN4F2_vidMonInvldP429Update();

			FHCANF4F2_vidUpdateSignalP429();
		}
		else
		{
			VEMS_vidSET(Ext_stBattSoC, 3);

			Ext_bMonRunInvldF4F2P429 = FHCAN_DISABLE;
			Ext_bDgoInvldF4F2P429 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stPosn, Local_bCtrl_stPosn);
		if (ACTIVATED == Local_bCtrl_stPosn)
		{
			Com_ReceiveSignal(Com_POS_MEAP_ACT_BSI_4F2, (void*) &ISCAN_u8N2F4F2P703);


			FHCANF4F2_vidUpdateSignalP703();
		}
		else
		{
			VEMS_vidSET(ShdFlap_stPosn, 0);

		}
		VEMS_vidGET(Ctrl_uBattOc, Local_bCtrl_uBattOc);
		if (ACTIVATED == Local_bCtrl_uBattOc)
		{
			FHCAN4F2_vidCalcMonFP437Window();
			Com_ReceiveSignal(Com_BAT_UBATT_CO_ESTIM_BSI_4F2, (void*) &ISCAN_u16N9F4F2P437);

			FHCAN4F2_vidMonInvldP437Update();
			FHCAN4F2_vidMonFrbdP437Update();

			FHCANF4F2_vidUpdateSignalP437();
		}
		else
		{
			VEMS_vidSET(Ext_uBattOc, 1792);
			VEMS_vidSET(Ext_bNotAvl_uBattOc, AVAILABLE);
			Ext_bMonRunFrbdF4F2P437 = FHCAN_DISABLE;
			Ext_bMonRunInvldF4F2P437 = FHCAN_DISABLE;
			Ext_bDgoFrbdF4F2P437 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF4F2P437 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_uReqProdMin, Local_bCtrl_uReqProdMin);
		if (ACTIVATED == Local_bCtrl_uReqProdMin)
		{
			FHCAN4F2_vidCalcMonFP490Window();
			Com_ReceiveSignal(Com_TENSION_MIN_PROD_EE_BSI_4F2, (void*) &ISCAN_u8N6F4F2P490);

			FHCAN4F2_vidMonInvldP490Update();
			FHCAN4F2_vidMonFrbdP490Update();

			FHCANF4F2_vidUpdateSignalP490();
		}
		else
		{
			VEMS_vidSET(ElecMgt_uReqProdMin, 169.6);

			Ext_bMonRunFrbdF4F2P490 = FHCAN_DISABLE;
			Ext_bMonRunInvldF4F2P490 = FHCAN_DISABLE;
			Ext_bDgoFrbdF4F2P490 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF4F2P490 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stPrioVoltMin, Local_bCtrl_stPrioVoltMin);
		if (ACTIVATED == Local_bCtrl_stPrioVoltMin)
		{
			FHCAN4F2_vidCalcMonFP493Window();
			Com_ReceiveSignal(Com_GRAV_ER_TENSION_MIN_BSI_4F2, (void*) &ISCAN_u8N2F4F2P493);

			FHCAN4F2_vidMonFrbdP493Update();

			FHCANF4F2_vidUpdateSignalP493();
		}
		else
		{
			VEMS_vidSET(ElecMgt_stPrioVoltMin, 2);

			Ext_bMonRunFrbdF4F2P493 = FHCAN_DISABLE;
			Ext_bDgoFrbdF4F2P493 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_uReqProdMax, Local_bCtrl_uReqProdMax);
		if (ACTIVATED == Local_bCtrl_uReqProdMax)
		{
			FHCAN4F2_vidCalcMonFP491Window();
			Com_ReceiveSignal(Com_TENSION_MAX_PROD_EE_BSI_4F2, (void*) &ISCAN_u8N6F4F2P491);

			FHCAN4F2_vidMonInvldP491Update();
			FHCAN4F2_vidMonFrbdP491Update();

			FHCANF4F2_vidUpdateSignalP491();
		}
		else
		{
			VEMS_vidSET(ElecMgt_uReqProdMax, 240);

			Ext_bMonRunFrbdF4F2P491 = FHCAN_DISABLE;
			Ext_bMonRunInvldF4F2P491 = FHCAN_DISABLE;
			Ext_bDgoFrbdF4F2P491 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF4F2P491 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stPrioVoltMax, Local_bCtrl_stPrioVoltMax);
		if (ACTIVATED == Local_bCtrl_stPrioVoltMax)
		{
			FHCAN4F2_vidCalcMonFP494Window();
			Com_ReceiveSignal(Com_GRAV_ER_TENSION_MAX_BSI_4F2, (void*) &ISCAN_u8N2F4F2P494);

			FHCAN4F2_vidMonFrbdP494Update();

			FHCANF4F2_vidUpdateSignalP494();
		}
		else
		{
			VEMS_vidSET(ElecMgt_stPrioVoltMax, 2);

			Ext_bMonRunFrbdF4F2P494 = FHCAN_DISABLE;
			Ext_bDgoFrbdF4F2P494 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_uReqProdSlope, Local_bCtrl_uReqProdSlope);
		if (ACTIVATED == Local_bCtrl_uReqProdSlope)
		{
			FHCAN4F2_vidCalcMonFP492Window();
			Com_ReceiveSignal(Com_VAR_TENSION_PROD_EE_BSI_4F2, (void*) &ISCAN_u8N7F4F2P492);

			FHCAN4F2_vidMonInvldP492Update();
			FHCAN4F2_vidMonFrbdP492Update();

			FHCANF4F2_vidUpdateSignalP492();
		}
		else
		{
			VEMS_vidSET(ElecMgt_uReqProdSlope, 8);

			Ext_bMonRunFrbdF4F2P492 = FHCAN_DISABLE;
			Ext_bMonRunInvldF4F2P492 = FHCAN_DISABLE;
			Ext_bDgoFrbdF4F2P492 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF4F2P492 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bOpFSFReq, Local_bCtrl_bOpFSFReq);
		if (ACTIVATED == Local_bCtrl_bOpFSFReq)
		{
			Com_ReceiveSignal(Com_DMD_MEAP_CLIM_BSI_4F2, (void*) &ISCAN_bF4F2P702);


			FHCANF4F2_vidUpdateSignalP702();
		}
		else
		{
			VEMS_vidSET(AC_bOpFSFReq, 0);

		}
	}
	else
	{
		Ext_bMonRunMissF4F2 = FHCAN_DISABLE;
		Ext_bMonRunShoF4F2 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P434 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P434 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P438 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P438 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P429 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P437 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P437 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P490 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P490 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P493 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P491 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P491 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P494 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P492 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P492 = FHCAN_DISABLE;

		Ext_bDgoMissF4F2 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF4F2 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P434 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P434 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P438 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P438 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P429 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P437 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P437 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P490 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P490 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P493 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P491 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P491 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P494 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P492 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P492 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF4F2_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF4F2P434_in;
	boolean FRM_bAcvRcvF4F2P438_in;
	boolean FRM_bAcvRcvF4F2P429_in;
	boolean FRM_bAcvRcvF4F2P437_in;
	boolean FRM_bAcvRcvF4F2P490_in;
	boolean FRM_bAcvRcvF4F2P493_in;
	boolean FRM_bAcvRcvF4F2P491_in;
	boolean FRM_bAcvRcvF4F2P494_in;
	boolean FRM_bAcvRcvF4F2P492_in;
	boolean FRM_bAcvRcvF4F2_in;
	boolean Local_bCtrl_BSI_4F2;
	boolean Local_bCtrl_rBattSoC;
	boolean Local_bCtrl_resBattIt;
	boolean Local_bCtrl_stBattSoC;
	boolean Local_bCtrl_stPosn;
	boolean Local_bCtrl_uBattOc;
	boolean Local_bCtrl_uReqProdMin;
	boolean Local_bCtrl_stPrioVoltMin;
	boolean Local_bCtrl_uReqProdMax;
	boolean Local_bCtrl_stPrioVoltMax;
	boolean Local_bCtrl_uReqProdSlope;
	boolean Local_bCtrl_bOpFSFReq;


	VEMS_vidGET(Ctrl_BSI_4F2, Local_bCtrl_BSI_4F2);
	if (ACTIVATED == Local_bCtrl_BSI_4F2)
	{
		FHCAN4F2_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF4F2)
      {
         Ext_bDgoMissF4F2 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF4F2,
                  Ext_bDgoMissF4F2,
                  Ext_bMonRunMissF4F2,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_rBattSoC, 1600);
		   VEMS_vidSET(Ext_bNotAvl_rBattSoC, AVAILABLE);
		   VEMS_vidSET(Ext_resBattIt, 1280);
		   VEMS_vidSET(Ext_bNotAvl_resBattIt, AVAILABLE);
		   VEMS_vidSET(Ext_stBattSoC, 3);
		   VEMS_vidSET(ShdFlap_stPosn, 0);
		   VEMS_vidSET(Ext_uBattOc, 1792);
		   VEMS_vidSET(Ext_bNotAvl_uBattOc, AVAILABLE);
		   VEMS_vidSET(ElecMgt_uReqProdMin, 169.6);
		   VEMS_vidSET(ElecMgt_stPrioVoltMin, 2);
		   VEMS_vidSET(ElecMgt_uReqProdMax, 240);
		   VEMS_vidSET(ElecMgt_stPrioVoltMax, 2);
		   VEMS_vidSET(ElecMgt_uReqProdSlope, 8);
		   VEMS_vidSET(AC_bOpFSFReq, 0);
      }

		FRM_bAcvRcvF4F2P434_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P434);
		FRM_bAcvRcvF4F2P438_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P438);
		FRM_bAcvRcvF4F2P429_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P429);
		FRM_bAcvRcvF4F2P437_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P437);
		FRM_bAcvRcvF4F2P490_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P490);
		FRM_bAcvRcvF4F2P493_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P493);
		FRM_bAcvRcvF4F2P491_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P491);
		FRM_bAcvRcvF4F2P494_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P494);
		FRM_bAcvRcvF4F2P492_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P492);
		FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);

		VEMS_vidGET(Ctrl_rBattSoC, Local_bCtrl_rBattSoC);
		if (ACTIVATED == Local_bCtrl_rBattSoC)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P434_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
			{
		      VEMS_vidSET(Ext_rBattSoC, Ext_rBattSoCRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_resBattIt, Local_bCtrl_resBattIt);
		if (ACTIVATED == Local_bCtrl_resBattIt)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P438_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
			{
		      VEMS_vidSET(Ext_resBattIt, Ext_resBattItRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stBattSoC, Local_bCtrl_stBattSoC);
		if (ACTIVATED == Local_bCtrl_stBattSoC)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P429_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
			{
		      VEMS_vidSET(Ext_stBattSoC, Ext_stBattSoCRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stPosn, Local_bCtrl_stPosn);
		if (ACTIVATED == Local_bCtrl_stPosn)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4F2_in)
			{
		      VEMS_vidSET(ShdFlap_stPosn, ShdFlap_stPosnRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_uBattOc, Local_bCtrl_uBattOc);
		if (ACTIVATED == Local_bCtrl_uBattOc)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P437_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
			{
		      VEMS_vidSET(Ext_uBattOc, Ext_uBattOcRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_uReqProdMin, Local_bCtrl_uReqProdMin);
		if (ACTIVATED == Local_bCtrl_uReqProdMin)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P490_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
			{
		      VEMS_vidSET(ElecMgt_uReqProdMin, ElecMgt_uReqProdMinRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stPrioVoltMin, Local_bCtrl_stPrioVoltMin);
		if (ACTIVATED == Local_bCtrl_stPrioVoltMin)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P493_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
			{
		      VEMS_vidSET(ElecMgt_stPrioVoltMin, ElecMgt_stPrioVoltMinRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_uReqProdMax, Local_bCtrl_uReqProdMax);
		if (ACTIVATED == Local_bCtrl_uReqProdMax)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P491_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
			{
		      VEMS_vidSET(ElecMgt_uReqProdMax, ElecMgt_uReqProdMaxRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stPrioVoltMax, Local_bCtrl_stPrioVoltMax);
		if (ACTIVATED == Local_bCtrl_stPrioVoltMax)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P494_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
			{
		      VEMS_vidSET(ElecMgt_stPrioVoltMax, ElecMgt_stPrioVoltMaxRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_uReqProdSlope, Local_bCtrl_uReqProdSlope);
		if (ACTIVATED == Local_bCtrl_uReqProdSlope)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P492_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
			{
		      VEMS_vidSET(ElecMgt_uReqProdSlope, ElecMgt_uReqProdSlopeRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bOpFSFReq, Local_bCtrl_bOpFSFReq);
		if (ACTIVATED == Local_bCtrl_bOpFSFReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4F2_in)
			{
		      VEMS_vidSET(AC_bOpFSFReq, AC_bOpFSFReqRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF4F2 = FHCAN_DISABLE;
		Ext_bMonRunShoF4F2 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P434 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P434 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P438 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P438 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P429 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P437 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P437 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P490 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P490 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P493 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P491 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P491 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P494 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF4F2P492 = FHCAN_DISABLE;
		Ext_bMonRunInvldF4F2P492 = FHCAN_DISABLE;

		Ext_bDgoMissF4F2 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF4F2 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P434 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P434 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P438 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P438 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P429 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P437 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P437 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P490 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P490 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P493 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P491 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P491 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P494 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF4F2P492 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF4F2P492 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF4F2_vidUpdateSignalP434(void)
{
	boolean FRM_bAcvRcvF4F2P434_in;
	boolean FRM_bAcvRcvF4F2_in;
   uint32 u32LocalIscanBSI_4F2;
   uint16 u16LocalExt_rBattSoC;

   if (ISCAN_u16N10F4F2P434 == 1022)
	{
		VEMS_vidSET(Ext_bNotAvl_rBattSoC, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_rBattSoC, AVAILABLE);
	}

	FRM_bAcvRcvF4F2P434_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P434);
	FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2P434_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF4F2P434)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF4F2P434)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4F2)
	   )
	{
      u32LocalIscanBSI_4F2 = (uint32)(((8 * ISCAN_u16N10F4F2P434) / 5));
      u16LocalExt_rBattSoC = (uint16)(MATHSRV_udtMIN(u32LocalIscanBSI_4F2,
                                             1600));
      VEMS_vidSET(Ext_rBattSoC,
                  u16LocalExt_rBattSoC);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P434_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
      {
			VEMS_vidSET(Ext_rBattSoC, Ext_rBattSoCRcf_C);
		}
	}
}

void FHCANF4F2_vidUpdateSignalP438(void)
{
	boolean FRM_bAcvRcvF4F2P438_in;
	boolean FRM_bAcvRcvF4F2_in;
   uint32 u32LocalIscanBSI_4F2;
   uint16 u16LocalExt_resBattIt;

   if (ISCAN_u16N10F4F2P438 == 1022)
	{
		VEMS_vidSET(Ext_bNotAvl_resBattIt, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_resBattIt, AVAILABLE);
	}

	FRM_bAcvRcvF4F2P438_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P438);
	FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2P438_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF4F2P438)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF4F2P438)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4F2)
	   )
	{
      u32LocalIscanBSI_4F2 = (uint32)(((32 * ISCAN_u16N10F4F2P438) / 25));
      u16LocalExt_resBattIt = (uint16)(MATHSRV_udtMIN(u32LocalIscanBSI_4F2,
                                             1280));
      VEMS_vidSET(Ext_resBattIt,
                  u16LocalExt_resBattIt);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P438_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
      {
			VEMS_vidSET(Ext_resBattIt, Ext_resBattItRcf_C);
		}
	}
}

void FHCANF4F2_vidUpdateSignalP429(void)
{
	boolean FRM_bAcvRcvF4F2P429_in;
	boolean FRM_bAcvRcvF4F2_in;
   uint8 u8LocalExt_stBattSoC;

	FRM_bAcvRcvF4F2P429_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P429);
	FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2P429_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF4F2P429)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4F2)
	   )
	{
      u8LocalExt_stBattSoC = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F4F2P429,
                                             3));
      VEMS_vidSET(Ext_stBattSoC,
                  u8LocalExt_stBattSoC);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P429_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
      {
			VEMS_vidSET(Ext_stBattSoC, Ext_stBattSoCRcf_C);
		}
	}
}

void FHCANF4F2_vidUpdateSignalP703(void)
{
	boolean FRM_bAcvRcvF4F2_in;
   uint8 u8LocalShdFlap_stPosn;

	FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4F2)
	   )
	{
		if (ISCAN_u8N2F4F2P703 == 0)
		{
         VEMS_vidSET(ShdFlap_stPosn, 2);
		}
		else
		{
			if (ISCAN_u8N2F4F2P703 == 2)
			{
            VEMS_vidSET(ShdFlap_stPosn, 0);
			}
		    else
			{
            u8LocalShdFlap_stPosn = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F4F2P703,
                                                   3));
            VEMS_vidSET(ShdFlap_stPosn,
                        u8LocalShdFlap_stPosn);
			}
		}
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4F2_in)
      {
			VEMS_vidSET(ShdFlap_stPosn, ShdFlap_stPosnRcf_C);
		}
	}
}

void FHCANF4F2_vidUpdateSignalP437(void)
{
	boolean FRM_bAcvRcvF4F2P437_in;
	boolean FRM_bAcvRcvF4F2_in;
   uint32 u32LocalIscanBSI_4F2;
   uint16 u16LocalExt_uBattOc;

   if (ISCAN_u16N9F4F2P437 == 510)
	{
		VEMS_vidSET(Ext_bNotAvl_uBattOc, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_uBattOc, AVAILABLE);
	}

	FRM_bAcvRcvF4F2P437_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P437);
	FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2P437_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF4F2P437)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF4F2P437)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4F2)
	   )
	{
      u32LocalIscanBSI_4F2 = (uint32)(((32 * ISCAN_u16N9F4F2P437) / 25) + 1408);
      u16LocalExt_uBattOc = (uint16)(MATHSRV_udtCLAMP(u32LocalIscanBSI_4F2,
                                               1408,
                                               1792));
      VEMS_vidSET(Ext_uBattOc,
                  u16LocalExt_uBattOc);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P437_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
      {
			VEMS_vidSET(Ext_uBattOc, Ext_uBattOcRcf_C);
		}
	}
}

void FHCANF4F2_vidUpdateSignalP490(void)
{
	boolean FRM_bAcvRcvF4F2P490_in;
	boolean FRM_bAcvRcvF4F2_in;
   uint16 u16LocalIscanBSI_4F2;
   uint16 u16LocalElecMgt_uReqProdMin;

	FRM_bAcvRcvF4F2P490_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P490);
	FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2P490_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF4F2P490)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF4F2P490)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4F2)
	   )
	{
      u16LocalIscanBSI_4F2 = (uint16)(((8 * ISCAN_u8N6F4F2P490) / 5) + (848/5));
      u16LocalElecMgt_uReqProdMin = (uint16)(MATHSRV_udtCLAMP(u16LocalIscanBSI_4F2,
                                               170,
                                               256));
      VEMS_vidSET(ElecMgt_uReqProdMin,
                  u16LocalElecMgt_uReqProdMin);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P490_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
      {
			VEMS_vidSET(ElecMgt_uReqProdMin, ElecMgt_uReqProdMinRcf_C);
		}
	}
}

void FHCANF4F2_vidUpdateSignalP493(void)
{
	boolean FRM_bAcvRcvF4F2P493_in;
	boolean FRM_bAcvRcvF4F2_in;

	FRM_bAcvRcvF4F2P493_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P493);
	FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2P493_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF4F2P493)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4F2)
	   )
	{
		if (ISCAN_u8N2F4F2P493 == 0)
		{
         VEMS_vidSET(ElecMgt_stPrioVoltMin, 2);
		}
		else
		{
			if (ISCAN_u8N2F4F2P493 == 1)
			{
            VEMS_vidSET(ElecMgt_stPrioVoltMin, 3);
			}
		    else
			{
            VEMS_vidSET(ElecMgt_stPrioVoltMin, 4);
			}
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P493_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
      {
			VEMS_vidSET(ElecMgt_stPrioVoltMin, ElecMgt_stPrioVoltMinRcf_C);
		}
	}
}

void FHCANF4F2_vidUpdateSignalP491(void)
{
	boolean FRM_bAcvRcvF4F2P491_in;
	boolean FRM_bAcvRcvF4F2_in;
   uint16 u16LocalIscanBSI_4F2;
   uint16 u16LocalElecMgt_uReqProdMax;

	FRM_bAcvRcvF4F2P491_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P491);
	FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2P491_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF4F2P491)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF4F2P491)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4F2)
	   )
	{
      u16LocalIscanBSI_4F2 = (uint16)(((8 * ISCAN_u8N6F4F2P491) / 5) + (848/5));
      u16LocalElecMgt_uReqProdMax = (uint16)(MATHSRV_udtCLAMP(u16LocalIscanBSI_4F2,
                                               170,
                                               256));
      VEMS_vidSET(ElecMgt_uReqProdMax,
                  u16LocalElecMgt_uReqProdMax);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P491_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
      {
			VEMS_vidSET(ElecMgt_uReqProdMax, ElecMgt_uReqProdMaxRcf_C);
		}
	}
}

void FHCANF4F2_vidUpdateSignalP494(void)
{
	boolean FRM_bAcvRcvF4F2P494_in;
	boolean FRM_bAcvRcvF4F2_in;

	FRM_bAcvRcvF4F2P494_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P494);
	FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2P494_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF4F2P494)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4F2)
	   )
	{
		if (ISCAN_u8N2F4F2P494 == 0)
		{
         VEMS_vidSET(ElecMgt_stPrioVoltMax, 2);
		}
		else
		{
			if (ISCAN_u8N2F4F2P494 == 1)
			{
            VEMS_vidSET(ElecMgt_stPrioVoltMax, 3);
			}
		    else
			{
            VEMS_vidSET(ElecMgt_stPrioVoltMax, 4);
			}
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P494_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
      {
			VEMS_vidSET(ElecMgt_stPrioVoltMax, ElecMgt_stPrioVoltMaxRcf_C);
		}
	}
}

void FHCANF4F2_vidUpdateSignalP492(void)
{
	boolean FRM_bAcvRcvF4F2P492_in;
	boolean FRM_bAcvRcvF4F2_in;
   uint16 u16LocalIscanBSI_4F2;
   uint8 u8LocalElecMgt_uReqProdSlope;

	FRM_bAcvRcvF4F2P492_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2P492);
	FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2P492_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF4F2P492)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF4F2P492)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4F2)
	   )
	{
      u16LocalIscanBSI_4F2 = (uint16)(((8 * ISCAN_u8N7F4F2P492) / 5));
      u8LocalElecMgt_uReqProdSlope = (uint8)(MATHSRV_udtCLAMP(u16LocalIscanBSI_4F2,
                                               1,
                                               160));
      VEMS_vidSET(ElecMgt_uReqProdSlope,
                  u8LocalElecMgt_uReqProdSlope);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF4F2P492_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF4F2_in))
      {
			VEMS_vidSET(ElecMgt_uReqProdSlope, ElecMgt_uReqProdSlopeRcf_C);
		}
	}
}

void FHCANF4F2_vidUpdateSignalP702(void)
{
	boolean FRM_bAcvRcvF4F2_in;

	FRM_bAcvRcvF4F2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4F2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4F2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4F2)
	   )
	{
      VEMS_vidSET(AC_bOpFSFReq,
                  ISCAN_bF4F2P702);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4F2_in)
      {
			VEMS_vidSET(AC_bOpFSFReq, AC_bOpFSFReqRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

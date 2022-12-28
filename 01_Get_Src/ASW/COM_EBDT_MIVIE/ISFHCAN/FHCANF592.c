/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF592.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF592.H"
#include "FHCANF592_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_592(void)
{
	ISCAN_u8N8F592P272 = 100;
	ISCAN_u8N8F592P273 = 230;
	ISCAN_u8N3F592P349 = 1;
	ISCAN_u16N11F592P418 = 1300;
	ISCAN_u8N2F592P419 = 0;
	ISCAN_u8N2F592P420 = 3;
	ISCAN_u16N16F592P421 = 0;

	VEMS_vidSET(Ext_rBattSoCLoResl, 100);
	VEMS_vidSET(Ext_bNotAvl_rBattSoCLoResl, AVAILABLE);
	VEMS_vidSET(Ext_tBattMes, 170);
	VEMS_vidSET(Ext_bNotAvl_tBattMes, AVAILABLE);
	VEMS_vidSET(ElecMgt_stProdMgtTyp, 1);
	VEMS_vidSET(Ext_bNotAvl_stProdMgtTyp, AVAILABLE);
	VEMS_vidSET(Ext_uBattClc, 2304);
	VEMS_vidSET(Ext_bNotAvl_uBattClc, AVAILABLE);
	VEMS_vidSET(Ext_bPush, 0);
	VEMS_vidSET(CAN_noCalCurBattMes, 3);
	VEMS_vidSET(CAN_noIncCurBattMes, 0);
	VEMS_vidSET(Ext_bNotAvl_noIncCurBattMes, AVAILABLE);

	Ext_bMonRunMissF592 = FHCAN_DISABLE;
	Ext_bMonRunShoF592 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF592P272 = FHCAN_DISABLE;
	Ext_bMonRunInvldF592P272 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF592P273 = FHCAN_DISABLE;
	Ext_bMonRunInvldF592P273 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF592P349 = FHCAN_DISABLE;
	Ext_bMonRunInvldF592P349 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF592P418 = FHCAN_DISABLE;
	Ext_bMonRunInvldF592P418 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF592P419 = FHCAN_DISABLE;
	Ext_bMonRunInvldF592P419 = FHCAN_DISABLE;
	Ext_bMonRunInvldF592P420 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF592P421 = FHCAN_DISABLE;
	Ext_bMonRunInvldF592P421 = FHCAN_DISABLE;

	Ext_bDgoMissF592 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF592 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF592P272 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF592P272 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF592P273 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF592P273 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF592P349 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF592P349 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF592P418 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF592P418 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF592P419 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF592P419 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF592P420 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF592P421 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF592P421 = FHCAN_NOT_DETECTED;
}

void FHCANF592_vidFrameReceived(void)
{
	boolean Local_bCtrl_BSI_592;
	boolean Local_bCtrl_rBattSoCLoResl;
	boolean Local_bCtrl_tBattMes;
	boolean Local_bCtrl_stProdMgtTyp;
	boolean Local_bCtrl_uBattClc;
	boolean Local_bCtrl_bPush;
	boolean Local_bCtrl_noCalCurBattMes;
	boolean Local_bCtrl_noIncCurBattMes;

	VEMS_vidGET(Ctrl_BSI_592, Local_bCtrl_BSI_592);
	if (ACTIVATED == Local_bCtrl_BSI_592)
	{
		ISCAN_EveRxn_592();
		FHCAN592_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF592)
      {
         Ext_bDgoMissF592 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF592,
                  Ext_bDgoMissF592,
                  Ext_bMonRunMissF592,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_rBattSoCLoResl, Local_bCtrl_rBattSoCLoResl);
		if (ACTIVATED == Local_bCtrl_rBattSoCLoResl)
		{
			FHCAN592_vidCalcMonFP272Window();
			Com_ReceiveSignal(Com_ETAT_CHARGE_BATTERIE_BSI_592, (void*) &ISCAN_u8N8F592P272);

			FHCAN592_vidMonInvldP272Update();
			FHCAN592_vidMonFrbdP272Update();

			FHCANF592_vidUpdateSignalP272();
		}
		else
		{
			VEMS_vidSET(Ext_rBattSoCLoResl, 100);
			VEMS_vidSET(Ext_bNotAvl_rBattSoCLoResl, AVAILABLE);
			Ext_bMonRunFrbdF592P272 = FHCAN_DISABLE;
			Ext_bMonRunInvldF592P272 = FHCAN_DISABLE;
			Ext_bDgoFrbdF592P272 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF592P272 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_tBattMes, Local_bCtrl_tBattMes);
		if (ACTIVATED == Local_bCtrl_tBattMes)
		{
			FHCAN592_vidCalcMonFP273Window();
			Com_ReceiveSignal(Com_TEMP_BATT_BSI_592, (void*) &ISCAN_u8N8F592P273);

			FHCAN592_vidMonInvldP273Update();
			FHCAN592_vidMonFrbdP273Update();

			FHCANF592_vidUpdateSignalP273();
		}
		else
		{
			VEMS_vidSET(Ext_tBattMes, 170);
			VEMS_vidSET(Ext_bNotAvl_tBattMes, AVAILABLE);
			Ext_bMonRunFrbdF592P273 = FHCAN_DISABLE;
			Ext_bMonRunInvldF592P273 = FHCAN_DISABLE;
			Ext_bDgoFrbdF592P273 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF592P273 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stProdMgtTyp, Local_bCtrl_stProdMgtTyp);
		if (ACTIVATED == Local_bCtrl_stProdMgtTyp)
		{
			FHCAN592_vidCalcMonFP349Window();
			Com_ReceiveSignal(Com_TYPE_PILT_ALTERN_BSI_592, (void*) &ISCAN_u8N3F592P349);

			FHCAN592_vidMonInvldP349Update();
			FHCAN592_vidMonFrbdP349Update();

			FHCANF592_vidUpdateSignalP349();
		}
		else
		{
			VEMS_vidSET(ElecMgt_stProdMgtTyp, 1);
			VEMS_vidSET(Ext_bNotAvl_stProdMgtTyp, AVAILABLE);
			Ext_bMonRunFrbdF592P349 = FHCAN_DISABLE;
			Ext_bMonRunInvldF592P349 = FHCAN_DISABLE;
			Ext_bDgoFrbdF592P349 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF592P349 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_uBattClc, Local_bCtrl_uBattClc);
		if (ACTIVATED == Local_bCtrl_uBattClc)
		{
			FHCAN592_vidCalcMonFP418Window();
			Com_ReceiveSignal(Com_U_BATT_BECB_BSI_592, (void*) &ISCAN_u16N11F592P418);

			FHCAN592_vidMonInvldP418Update();
			FHCAN592_vidMonFrbdP418Update();

			FHCANF592_vidUpdateSignalP418();
		}
		else
		{
			VEMS_vidSET(Ext_uBattClc, 2304);
			VEMS_vidSET(Ext_bNotAvl_uBattClc, AVAILABLE);
			Ext_bMonRunFrbdF592P418 = FHCAN_DISABLE;
			Ext_bMonRunInvldF592P418 = FHCAN_DISABLE;
			Ext_bDgoFrbdF592P418 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF592P418 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bPush, Local_bCtrl_bPush);
		if (ACTIVATED == Local_bCtrl_bPush)
		{
			FHCAN592_vidCalcMonFP419Window();
			Com_ReceiveSignal(Com_DMD_CHANGEMENT_ETAT_STT_BSI_592, (void*) &ISCAN_u8N2F592P419);

			FHCAN592_vidMonInvldP419Update();
			FHCAN592_vidMonFrbdP419Update();

			FHCANF592_vidUpdateSignalP419();
		}
		else
		{
			VEMS_vidSET(Ext_bPush, 0);

			Ext_bMonRunFrbdF592P419 = FHCAN_DISABLE;
			Ext_bMonRunInvldF592P419 = FHCAN_DISABLE;
			Ext_bDgoFrbdF592P419 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF592P419 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_noCalCurBattMes, Local_bCtrl_noCalCurBattMes);
		if (ACTIVATED == Local_bCtrl_noCalCurBattMes)
		{
			FHCAN592_vidCalcMonFP420Window();
			Com_ReceiveSignal(Com_CALIBRE_IBATT_BSI_592, (void*) &ISCAN_u8N2F592P420);

			FHCAN592_vidMonInvldP420Update();

			FHCANF592_vidUpdateSignalP420();
		}
		else
		{
			VEMS_vidSET(CAN_noCalCurBattMes, 3);

			Ext_bMonRunInvldF592P420 = FHCAN_DISABLE;
			Ext_bDgoInvldF592P420 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_noIncCurBattMes, Local_bCtrl_noIncCurBattMes);
		if (ACTIVATED == Local_bCtrl_noIncCurBattMes)
		{
			FHCAN592_vidCalcMonFP421Window();
			Com_ReceiveSignal(Com_IBATT_BSI_592, (void*) &ISCAN_u16N16F592P421);

			FHCAN592_vidMonInvldP421Update();
			FHCAN592_vidMonFrbdP421Update();

			FHCANF592_vidUpdateSignalP421();
		}
		else
		{
			VEMS_vidSET(CAN_noIncCurBattMes, 0);
			VEMS_vidSET(Ext_bNotAvl_noIncCurBattMes, AVAILABLE);
			Ext_bMonRunFrbdF592P421 = FHCAN_DISABLE;
			Ext_bMonRunInvldF592P421 = FHCAN_DISABLE;
			Ext_bDgoFrbdF592P421 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF592P421 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF592 = FHCAN_DISABLE;
		Ext_bMonRunShoF592 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P272 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P272 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P273 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P273 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P349 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P349 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P418 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P418 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P419 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P419 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P420 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P421 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P421 = FHCAN_DISABLE;

		Ext_bDgoMissF592 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF592 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P272 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P272 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P273 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P273 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P349 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P349 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P418 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P418 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P419 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P419 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P420 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P421 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P421 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF592_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF592P272_in;
	boolean FRM_bAcvRcvF592P273_in;
	boolean FRM_bAcvRcvF592P349_in;
	boolean FRM_bAcvRcvF592P418_in;
	boolean FRM_bAcvRcvF592P419_in;
	boolean FRM_bAcvRcvF592P420_in;
	boolean FRM_bAcvRcvF592P421_in;
	boolean FRM_bAcvRcvF592_in;
	boolean Local_bCtrl_BSI_592;
	boolean Local_bCtrl_rBattSoCLoResl;
	boolean Local_bCtrl_tBattMes;
	boolean Local_bCtrl_stProdMgtTyp;
	boolean Local_bCtrl_uBattClc;
	boolean Local_bCtrl_bPush;
	boolean Local_bCtrl_noCalCurBattMes;
	boolean Local_bCtrl_noIncCurBattMes;
	uint8 Local_Ext_rBattSoCLoResl;
	uint8 Local_CAN_noCalCurBattMes;


	VEMS_vidGET(Ctrl_BSI_592, Local_bCtrl_BSI_592);
	if (ACTIVATED == Local_bCtrl_BSI_592)
	{
		FHCAN592_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF592)
      {
         Ext_bDgoMissF592 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF592,
                  Ext_bDgoMissF592,
                  Ext_bMonRunMissF592,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_rBattSoCLoResl, 100);
		   VEMS_vidSET(Ext_bNotAvl_rBattSoCLoResl, AVAILABLE);
		   VEMS_vidSET(Ext_tBattMes, 170);
		   VEMS_vidSET(Ext_bNotAvl_tBattMes, AVAILABLE);
		   VEMS_vidSET(ElecMgt_stProdMgtTyp, 1);
		   VEMS_vidSET(Ext_bNotAvl_stProdMgtTyp, AVAILABLE);
		   VEMS_vidSET(Ext_uBattClc, 2304);
		   VEMS_vidSET(Ext_bNotAvl_uBattClc, AVAILABLE);
		   VEMS_vidSET(Ext_bPush, 0);
		   VEMS_vidSET(CAN_noCalCurBattMes, 3);
		   VEMS_vidSET(CAN_noIncCurBattMes, 0);
		   VEMS_vidSET(Ext_bNotAvl_noIncCurBattMes, AVAILABLE);
      }

		FRM_bAcvRcvF592P272_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P272);
		FRM_bAcvRcvF592P273_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P273);
		FRM_bAcvRcvF592P349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P349);
		FRM_bAcvRcvF592P418_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P418);
		FRM_bAcvRcvF592P419_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P419);
		FRM_bAcvRcvF592P420_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P420);
		FRM_bAcvRcvF592P421_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P421);
		FRM_bAcvRcvF592_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592);

		VEMS_vidGET(Ctrl_rBattSoCLoResl, Local_bCtrl_rBattSoCLoResl);
		if (ACTIVATED == Local_bCtrl_rBattSoCLoResl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF592P272_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
			{
		      VEMS_vidGET(Ext_rBattSoCLoResl, Local_Ext_rBattSoCLoResl);
		      VEMS_vidSET(Ext_rBattSoCLoResl, Local_Ext_rBattSoCLoResl);
			}
		}
		VEMS_vidGET(Ctrl_tBattMes, Local_bCtrl_tBattMes);
		if (ACTIVATED == Local_bCtrl_tBattMes)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF592P273_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
			{
		      VEMS_vidSET(Ext_tBattMes, Ext_tBattMesRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stProdMgtTyp, Local_bCtrl_stProdMgtTyp);
		if (ACTIVATED == Local_bCtrl_stProdMgtTyp)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF592P349_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
			{
		      VEMS_vidSET(ElecMgt_stProdMgtTyp, ElecMgt_stProdMgtTypRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_uBattClc, Local_bCtrl_uBattClc);
		if (ACTIVATED == Local_bCtrl_uBattClc)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF592P418_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
			{
		      VEMS_vidSET(Ext_uBattClc, Ext_uBattClcRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bPush, Local_bCtrl_bPush);
		if (ACTIVATED == Local_bCtrl_bPush)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF592P419_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
			{
		      VEMS_vidSET(Ext_bPush, Ext_bPushRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_noCalCurBattMes, Local_bCtrl_noCalCurBattMes);
		if (ACTIVATED == Local_bCtrl_noCalCurBattMes)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF592P420_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
			{
		      VEMS_vidGET(CAN_noCalCurBattMes, Local_CAN_noCalCurBattMes);
		      VEMS_vidSET(CAN_noCalCurBattMes, Local_CAN_noCalCurBattMes);
			}
		}
		VEMS_vidGET(Ctrl_noIncCurBattMes, Local_bCtrl_noIncCurBattMes);
		if (ACTIVATED == Local_bCtrl_noIncCurBattMes)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF592P421_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
			{
		      VEMS_vidSET(CAN_noIncCurBattMes, CAN_noIncCurBattMesRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF592 = FHCAN_DISABLE;
		Ext_bMonRunShoF592 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P272 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P272 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P273 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P273 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P349 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P349 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P418 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P418 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P419 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P419 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P420 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF592P421 = FHCAN_DISABLE;
		Ext_bMonRunInvldF592P421 = FHCAN_DISABLE;

		Ext_bDgoMissF592 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF592 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P272 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P272 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P273 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P273 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P349 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P349 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P418 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P418 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P419 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P419 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P420 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF592P421 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF592P421 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF592_vidUpdateSignalP272(void)
{
	boolean FRM_bAcvRcvF592P272_in;
	boolean FRM_bAcvRcvF592_in;
   uint8 u8LocalExt_rBattSoCLoResl;

	uint8 Local_Ext_rBattSoCLoResl;

   if (ISCAN_u8N8F592P272 == 254)
	{
		VEMS_vidSET(Ext_bNotAvl_rBattSoCLoResl, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_rBattSoCLoResl, AVAILABLE);
	}

	FRM_bAcvRcvF592P272_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P272);
	FRM_bAcvRcvF592_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF592P272_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF592_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF592P272)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF592P272)
	   && (FHCAN_DETECTED != Ext_bDgoShoF592)
	   )
	{
      u8LocalExt_rBattSoCLoResl = (uint8)(MATHSRV_udtMIN(ISCAN_u8N8F592P272,
                                             100));
      VEMS_vidSET(Ext_rBattSoCLoResl,
                  u8LocalExt_rBattSoCLoResl);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF592P272_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
      {
			VEMS_vidGET(Ext_rBattSoCLoResl, Local_Ext_rBattSoCLoResl);
			VEMS_vidSET(Ext_rBattSoCLoResl, Local_Ext_rBattSoCLoResl);
		}
	}
}

void FHCANF592_vidUpdateSignalP273(void)
{
	boolean FRM_bAcvRcvF592P273_in;
	boolean FRM_bAcvRcvF592_in;
   sint16 s16LocalIscanBSI_592;
   sint16 s16LocalExt_tBattMes;

   if (ISCAN_u8N8F592P273 == 254)
	{
		VEMS_vidSET(Ext_bNotAvl_tBattMes, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_tBattMes, AVAILABLE);
	}

	FRM_bAcvRcvF592P273_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P273);
	FRM_bAcvRcvF592_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF592P273_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF592_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF592P273)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF592P273)
	   && (FHCAN_DETECTED != Ext_bDgoShoF592)
	   )
	{
      s16LocalIscanBSI_592 = (sint16)((ISCAN_u8N8F592P273) - 60);
      s16LocalExt_tBattMes = (sint16)(MATHSRV_udtCLAMP(s16LocalIscanBSI_592,
                                               -60,
                                               170));
      VEMS_vidSET(Ext_tBattMes,
                  s16LocalExt_tBattMes);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF592P273_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
      {
			VEMS_vidSET(Ext_tBattMes, Ext_tBattMesRcf_C);
		}
	}
}

void FHCANF592_vidUpdateSignalP349(void)
{
	boolean FRM_bAcvRcvF592P349_in;
	boolean FRM_bAcvRcvF592_in;
   uint8 u8LocalElecMgt_stProdMgtTyp;

   if (ISCAN_u8N3F592P349 == 6)
	{
		VEMS_vidSET(Ext_bNotAvl_stProdMgtTyp, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_stProdMgtTyp, AVAILABLE);
	}

	FRM_bAcvRcvF592P349_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P349);
	FRM_bAcvRcvF592_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF592P349_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF592_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF592P349)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF592P349)
	   && (FHCAN_DETECTED != Ext_bDgoShoF592)
	   )
	{
      u8LocalElecMgt_stProdMgtTyp = (uint8)(MATHSRV_udtMIN(ISCAN_u8N3F592P349,
                                             7));
      VEMS_vidSET(ElecMgt_stProdMgtTyp,
                  u8LocalElecMgt_stProdMgtTyp);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF592P349_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
      {
			VEMS_vidSET(ElecMgt_stProdMgtTyp, ElecMgt_stProdMgtTypRcf_C);
		}
	}
}

void FHCANF592_vidUpdateSignalP418(void)
{
	boolean FRM_bAcvRcvF592P418_in;
	boolean FRM_bAcvRcvF592_in;
   uint32 u32LocalIscanBSI_592;
   uint16 u16LocalExt_uBattClc;

   if (ISCAN_u16N11F592P418 == 2046)
	{
		VEMS_vidSET(Ext_bNotAvl_uBattClc, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_uBattClc, AVAILABLE);
	}

	FRM_bAcvRcvF592P418_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P418);
	FRM_bAcvRcvF592_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF592P418_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF592_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF592P418)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF592P418)
	   && (FHCAN_DETECTED != Ext_bDgoShoF592)
	   )
	{
      u32LocalIscanBSI_592 = (uint32)(((32 * ISCAN_u16N11F592P418) / 25) + 640);
      u16LocalExt_uBattClc = (uint16)(MATHSRV_udtCLAMP(u32LocalIscanBSI_592,
                                               640,
                                               2304));
      VEMS_vidSET(Ext_uBattClc,
                  u16LocalExt_uBattClc);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF592P418_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
      {
			VEMS_vidSET(Ext_uBattClc, Ext_uBattClcRcf_C);
		}
	}
}

void FHCANF592_vidUpdateSignalP419(void)
{
	boolean FRM_bAcvRcvF592P419_in;
	boolean FRM_bAcvRcvF592_in;

	FRM_bAcvRcvF592P419_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P419);
	FRM_bAcvRcvF592_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF592P419_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF592_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF592P419)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF592P419)
	   && (FHCAN_DETECTED != Ext_bDgoShoF592)
	   )
	{
		if (ISCAN_u8N2F592P419 == 1)
		{
         VEMS_vidSET(Ext_bPush, 0);
		}
		else
		{
         VEMS_vidSET(Ext_bPush, 1);
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF592P419_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
      {
			VEMS_vidSET(Ext_bPush, Ext_bPushRcf_C);
		}
	}
}

void FHCANF592_vidUpdateSignalP420(void)
{
	boolean FRM_bAcvRcvF592P420_in;
	boolean FRM_bAcvRcvF592_in;
   uint8 u8LocalCAN_noCalCurBattMes;

	uint8 Local_CAN_noCalCurBattMes;

	FRM_bAcvRcvF592P420_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P420);
	FRM_bAcvRcvF592_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF592P420_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF592_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF592P420)
	   && (FHCAN_DETECTED != Ext_bDgoShoF592)
	   )
	{
      u8LocalCAN_noCalCurBattMes = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F592P420,
                                             3));
      VEMS_vidSET(CAN_noCalCurBattMes,
                  u8LocalCAN_noCalCurBattMes);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF592P420_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
      {
			VEMS_vidGET(CAN_noCalCurBattMes, Local_CAN_noCalCurBattMes);
			VEMS_vidSET(CAN_noCalCurBattMes, Local_CAN_noCalCurBattMes);
		}
	}
}

void FHCANF592_vidUpdateSignalP421(void)
{
	boolean FRM_bAcvRcvF592P421_in;
	boolean FRM_bAcvRcvF592_in;
   uint16 u16LocalCAN_noIncCurBattMes;

   if (ISCAN_u16N16F592P421 == 65534)
	{
		VEMS_vidSET(Ext_bNotAvl_noIncCurBattMes, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_noIncCurBattMes, AVAILABLE);
	}

	FRM_bAcvRcvF592P421_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592P421);
	FRM_bAcvRcvF592_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF592);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF592P421_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF592_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF592P421)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF592P421)
	   && (FHCAN_DETECTED != Ext_bDgoShoF592)
	   )
	{
      u16LocalCAN_noIncCurBattMes = (uint16)(MATHSRV_udtMIN(ISCAN_u16N16F592P421,
                                             40000));
      VEMS_vidSET(CAN_noIncCurBattMes,
                  u16LocalCAN_noIncCurBattMes);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF592P421_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF592_in))
      {
			VEMS_vidSET(CAN_noIncCurBattMes, CAN_noIncCurBattMesRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

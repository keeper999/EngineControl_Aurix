/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3CD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF3CD.H"
#include "FHCANF3CD_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_3CD(void)
{
	ISCAN_bF3CDP224 = 0;
	ISCAN_bF3CDP225 = 0;
	ISCAN_u8N3F3CDPM1387 = 0;
	ISCAN_u16N12F3CDP515 = 550;
	ISCAN_u8N2F3CDP226 = 0;
	ISCAN_u8N8F3CDP319 = 0;

	VEMS_vidSET(Cha_bMainBrkPedPrssMes, 0);
	VEMS_vidSET(MonBrk_bMainBrkPedPrssHS, 0);
	VEMS_vidSET(CoReqCha_stEngRStrtInh, 0);
	VEMS_vidSET(Ext_pBrkMCT, 0);
	VEMS_vidSET(Ext_stBrkIp, 0);
	VEMS_vidSET(Ext_rCluPCAN, 0);
	VEMS_vidSET(Ext_bNotAvl_rCluPCAN, AVAILABLE);

	Ext_bMonRunMissF3CD = FHCAN_DISABLE;
	Ext_bMonRunShoF3CD = FHCAN_DISABLE;
	Ext_bMonRunInvldF3CDP225 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF3CDPM1387 = FHCAN_DISABLE;
	Ext_bMonRunInvldF3CDP515 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF3CDP319 = FHCAN_DISABLE;
	Ext_bMonRunInvldF3CDP319 = FHCAN_DISABLE;

	Ext_bDgoMissF3CD = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF3CD = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF3CDP225 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF3CDPM1387 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF3CDP515 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF3CDP319 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF3CDP319 = FHCAN_NOT_DETECTED;
}

void FHCANF3CD_vidFrameReceived(void)
{
	boolean Local_bCtrl_FRE_3CD;
	boolean Local_bCtrl_bMainBrkPedPrssMes;
	boolean Local_bCtrl_bMainBrkPedPrssHSCha;
	boolean Local_bCtrl_stEngRStrtInh;
	boolean Local_bCtrl_pBrkMCT;
	boolean Local_bCtrl_stBrkIp;
	boolean Local_bCtrl_rCluPCAN;

	VEMS_vidGET(Ctrl_FRE_3CD, Local_bCtrl_FRE_3CD);
	if (ACTIVATED == Local_bCtrl_FRE_3CD)
	{
		ISCAN_EveRxn_3CD();
		FHCAN3CD_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF3CD)
      {
         Ext_bDgoMissF3CD = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF3CD,
                  Ext_bDgoMissF3CD,
                  Ext_bMonRunMissF3CD,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_bMainBrkPedPrssMes, Local_bCtrl_bMainBrkPedPrssMes);
		if (ACTIVATED == Local_bCtrl_bMainBrkPedPrssMes)
		{
			Com_ReceiveSignal(Com_CONTACT_FREIN3_FRE_3CD, (void*) &ISCAN_bF3CDP224);


			FHCANF3CD_vidUpdateSignalP224();
		}
		else
		{
			VEMS_vidSET(Cha_bMainBrkPedPrssMes, 0);

		}
		VEMS_vidGET(Ctrl_bMainBrkPedPrssHSCha, Local_bCtrl_bMainBrkPedPrssHSCha);
		if (ACTIVATED == Local_bCtrl_bMainBrkPedPrssHSCha)
		{
			FHCAN3CD_vidCalcMonFP225Window();
			Com_ReceiveSignal(Com_CONTACT_FREIN3_HS_FRE_3CD, (void*) &ISCAN_bF3CDP225);

			FHCAN3CD_vidMonInvldP225Update();

			FHCANF3CD_vidUpdateSignalP225();
		}
		else
		{
			VEMS_vidSET(MonBrk_bMainBrkPedPrssHS, 0);

			Ext_bMonRunInvldF3CDP225 = FHCAN_DISABLE;
			Ext_bDgoInvldF3CDP225 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stEngRStrtInh, Local_bCtrl_stEngRStrtInh);
		if (ACTIVATED == Local_bCtrl_stEngRStrtInh)
		{
			FHCAN3CD_vidCalcMonFPM1387Window();
			Com_ReceiveSignal(Com_INHIB_REDEM_EMOVE_FRE_3CD, (void*) &ISCAN_u8N3F3CDPM1387);

			FHCAN3CD_vidMonFrbdPM1387Update();

			FHCANF3CD_vidUpdateSignalPM1387();
		}
		else
		{
			VEMS_vidSET(CoReqCha_stEngRStrtInh, 0);

			Ext_bMonRunFrbdF3CDPM1387 = FHCAN_DISABLE;
			Ext_bDgoFrbdF3CDPM1387 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_pBrkMCT, Local_bCtrl_pBrkMCT);
		if (ACTIVATED == Local_bCtrl_pBrkMCT)
		{
			FHCAN3CD_vidCalcMonFP515Window();
			Com_ReceiveSignal(Com_PRESSION_MAITRE_CYL_FRE_3CD, (void*) &ISCAN_u16N12F3CDP515);

			FHCAN3CD_vidMonInvldP515Update();

			FHCANF3CD_vidUpdateSignalP515();
		}
		else
		{
			VEMS_vidSET(Ext_pBrkMCT, 0);

			Ext_bMonRunInvldF3CDP515 = FHCAN_DISABLE;
			Ext_bDgoInvldF3CDP515 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stBrkIp, Local_bCtrl_stBrkIp);
		if (ACTIVATED == Local_bCtrl_stBrkIp)
		{
			Com_ReceiveSignal(Com_FREINAGE_EN_COURS_FRE_3CD, (void*) &ISCAN_u8N2F3CDP226);


			FHCANF3CD_vidUpdateSignalP226();
		}
		else
		{
			VEMS_vidSET(Ext_stBrkIp, 0);

		}
		VEMS_vidGET(Ctrl_rCluPCAN, Local_bCtrl_rCluPCAN);
		if (ACTIVATED == Local_bCtrl_rCluPCAN)
		{
			FHCAN3CD_vidCalcMonFP319Window();
			Com_ReceiveSignal(Com_POS_PED_EMBR_FRE_3CD, (void*) &ISCAN_u8N8F3CDP319);

			FHCAN3CD_vidMonInvldP319Update();
			FHCAN3CD_vidMonFrbdP319Update();

			FHCANF3CD_vidUpdateSignalP319();
		}
		else
		{
			VEMS_vidSET(Ext_rCluPCAN, 0);
			VEMS_vidSET(Ext_bNotAvl_rCluPCAN, AVAILABLE);
			Ext_bMonRunFrbdF3CDP319 = FHCAN_DISABLE;
			Ext_bMonRunInvldF3CDP319 = FHCAN_DISABLE;
			Ext_bDgoFrbdF3CDP319 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF3CDP319 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF3CD = FHCAN_DISABLE;
		Ext_bMonRunShoF3CD = FHCAN_DISABLE;
		Ext_bMonRunInvldF3CDP225 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3CDPM1387 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3CDP515 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3CDP319 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3CDP319 = FHCAN_DISABLE;

		Ext_bDgoMissF3CD = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF3CD = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3CDP225 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3CDPM1387 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3CDP515 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3CDP319 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3CDP319 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF3CD_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF3CDP225_in;
	boolean FRM_bAcvRcvF3CDPM1387_in;
	boolean FRM_bAcvRcvF3CDP515_in;
	boolean FRM_bAcvRcvF3CDP319_in;
	boolean FRM_bAcvRcvF3CD_in;
	boolean Local_bCtrl_FRE_3CD;
	boolean Local_bCtrl_bMainBrkPedPrssMes;
	boolean Local_bCtrl_bMainBrkPedPrssHSCha;
	boolean Local_bCtrl_stEngRStrtInh;
	boolean Local_bCtrl_pBrkMCT;
	boolean Local_bCtrl_stBrkIp;
	boolean Local_bCtrl_rCluPCAN;
	boolean Local_MonBrk_bMainBrkPedPrssHS;
	uint16 Local_Ext_pBrkMCT;


	VEMS_vidGET(Ctrl_FRE_3CD, Local_bCtrl_FRE_3CD);
	if (ACTIVATED == Local_bCtrl_FRE_3CD)
	{
		FHCAN3CD_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF3CD)
      {
         Ext_bDgoMissF3CD = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF3CD,
                  Ext_bDgoMissF3CD,
                  Ext_bMonRunMissF3CD,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Cha_bMainBrkPedPrssMes, 0);
		   VEMS_vidSET(MonBrk_bMainBrkPedPrssHS, 0);
		   VEMS_vidSET(CoReqCha_stEngRStrtInh, 0);
		   VEMS_vidSET(Ext_pBrkMCT, 0);
		   VEMS_vidSET(Ext_stBrkIp, 0);
		   VEMS_vidSET(Ext_rCluPCAN, 0);
		   VEMS_vidSET(Ext_bNotAvl_rCluPCAN, AVAILABLE);
      }

		FRM_bAcvRcvF3CDP225_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CDP225);
		FRM_bAcvRcvF3CDPM1387_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CDPM1387);
		FRM_bAcvRcvF3CDP515_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CDP515);
		FRM_bAcvRcvF3CDP319_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CDP319);
		FRM_bAcvRcvF3CD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CD);

		VEMS_vidGET(Ctrl_bMainBrkPedPrssMes, Local_bCtrl_bMainBrkPedPrssMes);
		if (ACTIVATED == Local_bCtrl_bMainBrkPedPrssMes)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF3CD_in)
			{
		      VEMS_vidSET(Cha_bMainBrkPedPrssMes, Cha_bMainBrkPedPrssMesRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bMainBrkPedPrssHSCha, Local_bCtrl_bMainBrkPedPrssHSCha);
		if (ACTIVATED == Local_bCtrl_bMainBrkPedPrssHSCha)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF3CDP225_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF3CD_in))
			{
		      VEMS_vidGET(MonBrk_bMainBrkPedPrssHS, Local_MonBrk_bMainBrkPedPrssHS);
		      VEMS_vidSET(MonBrk_bMainBrkPedPrssHS, Local_MonBrk_bMainBrkPedPrssHS);
			}
		}
		VEMS_vidGET(Ctrl_stEngRStrtInh, Local_bCtrl_stEngRStrtInh);
		if (ACTIVATED == Local_bCtrl_stEngRStrtInh)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF3CDPM1387_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF3CD_in))
			{
		      VEMS_vidSET(CoReqCha_stEngRStrtInh, CoReqCha_stEngRStrtInhRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_pBrkMCT, Local_bCtrl_pBrkMCT);
		if (ACTIVATED == Local_bCtrl_pBrkMCT)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF3CDP515_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF3CD_in))
			{
		      VEMS_vidGET(Ext_pBrkMCT, Local_Ext_pBrkMCT);
		      VEMS_vidSET(Ext_pBrkMCT, Local_Ext_pBrkMCT);
			}
		}
		VEMS_vidGET(Ctrl_stBrkIp, Local_bCtrl_stBrkIp);
		if (ACTIVATED == Local_bCtrl_stBrkIp)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF3CD_in)
			{
		      VEMS_vidSET(Ext_stBrkIp, Ext_stBrkIpRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_rCluPCAN, Local_bCtrl_rCluPCAN);
		if (ACTIVATED == Local_bCtrl_rCluPCAN)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF3CDP319_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF3CD_in))
			{
		      VEMS_vidSET(Ext_rCluPCAN, Ext_rCluPCANRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF3CD = FHCAN_DISABLE;
		Ext_bMonRunShoF3CD = FHCAN_DISABLE;
		Ext_bMonRunInvldF3CDP225 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3CDPM1387 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3CDP515 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF3CDP319 = FHCAN_DISABLE;
		Ext_bMonRunInvldF3CDP319 = FHCAN_DISABLE;

		Ext_bDgoMissF3CD = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF3CD = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3CDP225 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3CDPM1387 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3CDP515 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF3CDP319 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF3CDP319 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF3CD_vidUpdateSignalP224(void)
{
	boolean FRM_bAcvRcvF3CD_in;

	FRM_bAcvRcvF3CD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CD);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3CD_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3CD)
	   )
	{
      VEMS_vidSET(Cha_bMainBrkPedPrssMes,
                  ISCAN_bF3CDP224);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF3CD_in)
      {
			VEMS_vidSET(Cha_bMainBrkPedPrssMes, Cha_bMainBrkPedPrssMesRcf_C);
		}
	}
}

void FHCANF3CD_vidUpdateSignalP225(void)
{
	boolean FRM_bAcvRcvF3CDP225_in;
	boolean FRM_bAcvRcvF3CD_in;

	boolean Local_MonBrk_bMainBrkPedPrssHS;

	FRM_bAcvRcvF3CDP225_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CDP225);
	FRM_bAcvRcvF3CD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CD);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3CDP225_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF3CD_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF3CDP225)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3CD)
	   )
	{
      VEMS_vidSET(MonBrk_bMainBrkPedPrssHS,
                  ISCAN_bF3CDP225);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF3CDP225_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF3CD_in))
      {
			VEMS_vidGET(MonBrk_bMainBrkPedPrssHS, Local_MonBrk_bMainBrkPedPrssHS);
			VEMS_vidSET(MonBrk_bMainBrkPedPrssHS, Local_MonBrk_bMainBrkPedPrssHS);
		}
	}
}

void FHCANF3CD_vidUpdateSignalPM1387(void)
{
	boolean FRM_bAcvRcvF3CDPM1387_in;
	boolean FRM_bAcvRcvF3CD_in;

	FRM_bAcvRcvF3CDPM1387_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CDPM1387);
	FRM_bAcvRcvF3CD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CD);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3CDPM1387_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF3CD_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF3CDPM1387)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3CD)
	   )
	{
		if (ISCAN_u8N3F3CDPM1387 == 3)
		{
         VEMS_vidSET(CoReqCha_stEngRStrtInh, 0);
		}
		else
		{
			if (ISCAN_u8N3F3CDPM1387 == 5)
			{
            VEMS_vidSET(CoReqCha_stEngRStrtInh, 1);
			}
			else
			{
				if (ISCAN_u8N3F3CDPM1387 == 6)
				{
               VEMS_vidSET(CoReqCha_stEngRStrtInh, 2);
				}
				
			}
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF3CDPM1387_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF3CD_in))
      {
			VEMS_vidSET(CoReqCha_stEngRStrtInh, CoReqCha_stEngRStrtInhRcf_C);
		}
	}
}

void FHCANF3CD_vidUpdateSignalP515(void)
{
	boolean FRM_bAcvRcvF3CDP515_in;
	boolean FRM_bAcvRcvF3CD_in;
   sint32 s32LocalIscanFRE_3CD;
   uint16 u16LocalExt_pBrkMCT;

	uint16 Local_Ext_pBrkMCT;

	FRM_bAcvRcvF3CDP515_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CDP515);
	FRM_bAcvRcvF3CD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CD);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3CDP515_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF3CD_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF3CDP515)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3CD)
	   )
	{
		if (ISCAN_u16N12F3CDP515 < 0)
		{
         VEMS_vidSET(Ext_pBrkMCT, 0);
		}
		else
		{
         s32LocalIscanFRE_3CD = (sint32)(((64 * ISCAN_u16N12F3CDP515) / 5) - 7040);
         u16LocalExt_pBrkMCT = (uint16)(MATHSRV_udtCLAMP(s32LocalIscanFRE_3CD,
                                                  0,
                                                  64000));
         VEMS_vidSET(Ext_pBrkMCT,
                     u16LocalExt_pBrkMCT);
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF3CDP515_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF3CD_in))
      {
			VEMS_vidGET(Ext_pBrkMCT, Local_Ext_pBrkMCT);
			VEMS_vidSET(Ext_pBrkMCT, Local_Ext_pBrkMCT);
		}
	}
}

void FHCANF3CD_vidUpdateSignalP226(void)
{
	boolean FRM_bAcvRcvF3CD_in;
   uint8 u8LocalExt_stBrkIp;

	FRM_bAcvRcvF3CD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CD);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3CD_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3CD)
	   )
	{
      u8LocalExt_stBrkIp = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F3CDP226,
                                             3));
      VEMS_vidSET(Ext_stBrkIp,
                  u8LocalExt_stBrkIp);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF3CD_in)
      {
			VEMS_vidSET(Ext_stBrkIp, Ext_stBrkIpRcf_C);
		}
	}
}

void FHCANF3CD_vidUpdateSignalP319(void)
{
	boolean FRM_bAcvRcvF3CDP319_in;
	boolean FRM_bAcvRcvF3CD_in;
   uint16 u16LocalIscanFRE_3CD;
   uint16 u16LocalExt_rCluPCAN;

   if (ISCAN_u8N8F3CDP319 == 254)
	{
		VEMS_vidSET(Ext_bNotAvl_rCluPCAN, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_rCluPCAN, AVAILABLE);
	}

	FRM_bAcvRcvF3CDP319_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CDP319);
	FRM_bAcvRcvF3CD_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF3CD);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF3CDP319_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF3CD_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF3CDP319)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF3CDP319)
	   && (FHCAN_DETECTED != Ext_bDgoShoF3CD)
	   )
	{
      u16LocalIscanFRE_3CD = (uint16)(((128 * ISCAN_u8N8F3CDP319) / 25));
      u16LocalExt_rCluPCAN = (uint16)(MATHSRV_udtMIN(u16LocalIscanFRE_3CD,
                                             1023));
      VEMS_vidSET(Ext_rCluPCAN,
                  u16LocalExt_rCluPCAN);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF3CDP319_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF3CD_in))
      {
			VEMS_vidSET(Ext_rCluPCAN, Ext_rCluPCANRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

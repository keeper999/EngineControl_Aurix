/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF532.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF532.H"
#include "FHCANF532_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_532(void)
{
	ISCAN_u16N10F532PM1414 = 900;
	ISCAN_u8N6F532PM1415 = 60;
	ISCAN_u8N7F532PM1416 = 50;

	VEMS_vidSET(Ext_uBattMinCkg, 1536);
	VEMS_vidSET(Ext_bNotAvl_uBattMinCkg, AVAILABLE);
	VEMS_vidSET(Ext_iBattMaxCkg, -18.75);
	VEMS_vidSET(Ext_bNotAvl_iBattMaxCkg, AVAILABLE);
	VEMS_vidSET(Ext_resBattItNorm, 80);
	VEMS_vidSET(Ext_bNotAvl_resBattItNorm, AVAILABLE);

	Ext_bMonRunMissF532 = FHCAN_DISABLE;
	Ext_bMonRunShoF532 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF532PM1414 = FHCAN_DISABLE;
	Ext_bMonRunInvldF532PM1414 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF532PM1415 = FHCAN_DISABLE;
	Ext_bMonRunInvldF532PM1415 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF532PM1416 = FHCAN_DISABLE;
	Ext_bMonRunInvldF532PM1416 = FHCAN_DISABLE;

	Ext_bDgoMissF532 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF532 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF532PM1414 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF532PM1414 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF532PM1415 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF532PM1415 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF532PM1416 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF532PM1416 = FHCAN_NOT_DETECTED;
}

void FHCANF532_vidFrameReceived(void)
{
	boolean Local_bCtrl_DAT_BSI_532;
	boolean Local_bCtrl_uBattMinCkg;
	boolean Local_bCtrl_iBattMaxCkg;
	boolean Local_bCtrl_resBattItNorm;

	VEMS_vidGET(Ctrl_DAT_BSI_532, Local_bCtrl_DAT_BSI_532);
	if (ACTIVATED == Local_bCtrl_DAT_BSI_532)
	{
		ISCAN_EveRxn_532();
		FHCAN532_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF532)
      {
         Ext_bDgoMissF532 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF532,
                  Ext_bDgoMissF532,
                  Ext_bMonRunMissF532,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_uBattMinCkg, Local_bCtrl_uBattMinCkg);
		if (ACTIVATED == Local_bCtrl_uBattMinCkg)
		{
			FHCAN532_vidCalcMonFPM1414Window();
			Com_ReceiveSignal(Com_BAT_U_MIN_TRAITE_DAT_BSI_532, (void*) &ISCAN_u16N10F532PM1414);

			FHCAN532_vidMonInvldPM1414Update();
			FHCAN532_vidMonFrbdPM1414Update();

			FHCANF532_vidUpdateSignalPM1414();
		}
		else
		{
			VEMS_vidSET(Ext_uBattMinCkg, 1536);
			VEMS_vidSET(Ext_bNotAvl_uBattMinCkg, AVAILABLE);
			Ext_bMonRunFrbdF532PM1414 = FHCAN_DISABLE;
			Ext_bMonRunInvldF532PM1414 = FHCAN_DISABLE;
			Ext_bDgoFrbdF532PM1414 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF532PM1414 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_iBattMaxCkg, Local_bCtrl_iBattMaxCkg);
		if (ACTIVATED == Local_bCtrl_iBattMaxCkg)
		{
			FHCAN532_vidCalcMonFPM1415Window();
			Com_ReceiveSignal(Com_BAT_I_MAX_TRAITE_DAT_BSI_532, (void*) &ISCAN_u8N6F532PM1415);

			FHCAN532_vidMonInvldPM1415Update();
			FHCAN532_vidMonFrbdPM1415Update();

			FHCANF532_vidUpdateSignalPM1415();
		}
		else
		{
			VEMS_vidSET(Ext_iBattMaxCkg, -18.75);
			VEMS_vidSET(Ext_bNotAvl_iBattMaxCkg, AVAILABLE);
			Ext_bMonRunFrbdF532PM1415 = FHCAN_DISABLE;
			Ext_bMonRunInvldF532PM1415 = FHCAN_DISABLE;
			Ext_bDgoFrbdF532PM1415 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF532PM1415 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_resBattItNorm, Local_bCtrl_resBattItNorm);
		if (ACTIVATED == Local_bCtrl_resBattItNorm)
		{
			FHCAN532_vidCalcMonFPM1416Window();
			Com_ReceiveSignal(Com_BAT_RINT_NORM_TRAITE_DAT_BSI_532, (void*) &ISCAN_u8N7F532PM1416);

			FHCAN532_vidMonInvldPM1416Update();
			FHCAN532_vidMonFrbdPM1416Update();

			FHCANF532_vidUpdateSignalPM1416();
		}
		else
		{
			VEMS_vidSET(Ext_resBattItNorm, 80);
			VEMS_vidSET(Ext_bNotAvl_resBattItNorm, AVAILABLE);
			Ext_bMonRunFrbdF532PM1416 = FHCAN_DISABLE;
			Ext_bMonRunInvldF532PM1416 = FHCAN_DISABLE;
			Ext_bDgoFrbdF532PM1416 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF532PM1416 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF532 = FHCAN_DISABLE;
		Ext_bMonRunShoF532 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF532PM1414 = FHCAN_DISABLE;
		Ext_bMonRunInvldF532PM1414 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF532PM1415 = FHCAN_DISABLE;
		Ext_bMonRunInvldF532PM1415 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF532PM1416 = FHCAN_DISABLE;
		Ext_bMonRunInvldF532PM1416 = FHCAN_DISABLE;

		Ext_bDgoMissF532 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF532 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF532PM1414 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF532PM1414 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF532PM1415 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF532PM1415 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF532PM1416 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF532PM1416 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF532_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF532PM1414_in;
	boolean FRM_bAcvRcvF532PM1415_in;
	boolean FRM_bAcvRcvF532PM1416_in;
	boolean FRM_bAcvRcvF532_in;
	boolean Local_bCtrl_DAT_BSI_532;
	boolean Local_bCtrl_uBattMinCkg;
	boolean Local_bCtrl_iBattMaxCkg;
	boolean Local_bCtrl_resBattItNorm;


	VEMS_vidGET(Ctrl_DAT_BSI_532, Local_bCtrl_DAT_BSI_532);
	if (ACTIVATED == Local_bCtrl_DAT_BSI_532)
	{
		FHCAN532_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF532)
      {
         Ext_bDgoMissF532 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF532,
                  Ext_bDgoMissF532,
                  Ext_bMonRunMissF532,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_uBattMinCkg, 1536);
		   VEMS_vidSET(Ext_bNotAvl_uBattMinCkg, AVAILABLE);
		   VEMS_vidSET(Ext_iBattMaxCkg, -18.75);
		   VEMS_vidSET(Ext_bNotAvl_iBattMaxCkg, AVAILABLE);
		   VEMS_vidSET(Ext_resBattItNorm, 80);
		   VEMS_vidSET(Ext_bNotAvl_resBattItNorm, AVAILABLE);
      }

		FRM_bAcvRcvF532PM1414_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF532PM1414);
		FRM_bAcvRcvF532PM1415_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF532PM1415);
		FRM_bAcvRcvF532PM1416_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF532PM1416);
		FRM_bAcvRcvF532_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF532);

		VEMS_vidGET(Ctrl_uBattMinCkg, Local_bCtrl_uBattMinCkg);
		if (ACTIVATED == Local_bCtrl_uBattMinCkg)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF532PM1414_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF532_in))
			{
		      VEMS_vidSET(Ext_uBattMinCkg, Ext_uBattMinCkgRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_iBattMaxCkg, Local_bCtrl_iBattMaxCkg);
		if (ACTIVATED == Local_bCtrl_iBattMaxCkg)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF532PM1415_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF532_in))
			{
		      VEMS_vidSET(Ext_iBattMaxCkg, Ext_iBattMaxCkgRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_resBattItNorm, Local_bCtrl_resBattItNorm);
		if (ACTIVATED == Local_bCtrl_resBattItNorm)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF532PM1416_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF532_in))
			{
		      VEMS_vidSET(Ext_resBattItNorm, Ext_resBattItNormRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF532 = FHCAN_DISABLE;
		Ext_bMonRunShoF532 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF532PM1414 = FHCAN_DISABLE;
		Ext_bMonRunInvldF532PM1414 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF532PM1415 = FHCAN_DISABLE;
		Ext_bMonRunInvldF532PM1415 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF532PM1416 = FHCAN_DISABLE;
		Ext_bMonRunInvldF532PM1416 = FHCAN_DISABLE;

		Ext_bDgoMissF532 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF532 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF532PM1414 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF532PM1414 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF532PM1415 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF532PM1415 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF532PM1416 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF532PM1416 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF532_vidUpdateSignalPM1414(void)
{
	boolean FRM_bAcvRcvF532PM1414_in;
	boolean FRM_bAcvRcvF532_in;
   uint32 u32LocalIscanDAT_BSI_532;
   uint16 u16LocalExt_uBattMinCkg;

   if (ISCAN_u16N10F532PM1414 == 1022)
	{
		VEMS_vidSET(Ext_bNotAvl_uBattMinCkg, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_uBattMinCkg, AVAILABLE);
	}

	FRM_bAcvRcvF532PM1414_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF532PM1414);
	FRM_bAcvRcvF532_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF532);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF532PM1414_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF532_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF532PM1414)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF532PM1414)
	   && (FHCAN_DETECTED != Ext_bDgoShoF532)
	   )
	{
      u32LocalIscanDAT_BSI_532 = (uint32)(((32 * ISCAN_u16N10F532PM1414) / 25) + 384);
      u16LocalExt_uBattMinCkg = (uint16)(MATHSRV_udtCLAMP(u32LocalIscanDAT_BSI_532,
                                               384,
                                               1664));
      VEMS_vidSET(Ext_uBattMinCkg,
                  u16LocalExt_uBattMinCkg);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF532PM1414_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF532_in))
      {
			VEMS_vidSET(Ext_uBattMinCkg, Ext_uBattMinCkgRcf_C);
		}
	}
}

void FHCANF532_vidUpdateSignalPM1415(void)
{
	boolean FRM_bAcvRcvF532PM1415_in;
	boolean FRM_bAcvRcvF532_in;
   sint16 s16LocalIscanDAT_BSI_532;
   sint8 s8LocalExt_iBattMaxCkg;

   if (ISCAN_u8N6F532PM1415 == 62)
	{
		VEMS_vidSET(Ext_bNotAvl_iBattMaxCkg, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_iBattMaxCkg, AVAILABLE);
	}

	FRM_bAcvRcvF532PM1415_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF532PM1415);
	FRM_bAcvRcvF532_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF532);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF532PM1415_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF532_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF532PM1415)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF532PM1415)
	   && (FHCAN_DETECTED != Ext_bDgoShoF532)
	   )
	{
      s16LocalIscanDAT_BSI_532 = (sint16)(((5 * ISCAN_u8N6F532PM1415) / 4) - (375/4));
      s8LocalExt_iBattMaxCkg = (sint8)(MATHSRV_udtCLAMP(s16LocalIscanDAT_BSI_532,
                                               -94,
                                               -18));
      VEMS_vidSET(Ext_iBattMaxCkg,
                  s8LocalExt_iBattMaxCkg);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF532PM1415_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF532_in))
      {
			VEMS_vidSET(Ext_iBattMaxCkg, Ext_iBattMaxCkgRcf_C);
		}
	}
}

void FHCANF532_vidUpdateSignalPM1416(void)
{
	boolean FRM_bAcvRcvF532PM1416_in;
	boolean FRM_bAcvRcvF532_in;
   uint16 u16LocalIscanDAT_BSI_532;
   uint8 u8LocalExt_resBattItNorm;

   if (ISCAN_u8N7F532PM1416 == 126)
	{
		VEMS_vidSET(Ext_bNotAvl_resBattItNorm, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_resBattItNorm, AVAILABLE);
	}

	FRM_bAcvRcvF532PM1416_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF532PM1416);
	FRM_bAcvRcvF532_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF532);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF532PM1416_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF532_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF532PM1416)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF532PM1416)
	   && (FHCAN_DETECTED != Ext_bDgoShoF532)
	   )
	{
      u16LocalIscanDAT_BSI_532 = (uint16)(((8 * ISCAN_u8N7F532PM1416) / 5));
      u8LocalExt_resBattItNorm = (uint8)(MATHSRV_udtMIN(u16LocalIscanDAT_BSI_532,
                                             160));
      VEMS_vidSET(Ext_resBattItNorm,
                  u8LocalExt_resBattItNorm);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF532PM1416_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF532_in))
      {
			VEMS_vidSET(Ext_resBattItNorm, Ext_resBattItNormRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

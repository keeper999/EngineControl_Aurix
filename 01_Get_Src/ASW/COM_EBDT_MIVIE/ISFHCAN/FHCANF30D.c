/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF30D.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF30D.H"
#include "FHCANF30D_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_30D(void)
{
	ISCAN_u16N16F30DP263 = 0;
	ISCAN_u16N16F30DP264 = 0;
	ISCAN_u16N16F30DP265 = 0;
	ISCAN_u16N16F30DP266 = 0;

	VEMS_vidSET(Ext_spdLeFrntWhl, 0);
	VEMS_vidSET(Ext_bNotAvl_spdLeFrntWhl, AVAILABLE);
	VEMS_vidSET(Ext_spdRiFrntWhl, 0);
	VEMS_vidSET(Ext_bNotAvl_spdRiFrntWhl, AVAILABLE);
	VEMS_vidSET(Ext_spdLeReWhl, 0);
	VEMS_vidSET(Ext_bNotAvl_spdLeReWhl, AVAILABLE);
	VEMS_vidSET(Ext_spdRiReWhl, 0);
	VEMS_vidSET(Ext_bNotAvl_spdRiReWhl, AVAILABLE);

	Ext_bMonRunMissF30D = FHCAN_DISABLE;
	Ext_bMonRunShoF30D = FHCAN_DISABLE;
	Ext_bMonRunInvldF30DP263 = FHCAN_DISABLE;
	Ext_bMonRunInvldF30DP264 = FHCAN_DISABLE;
	Ext_bMonRunInvldF30DP265 = FHCAN_DISABLE;
	Ext_bMonRunInvldF30DP266 = FHCAN_DISABLE;

	Ext_bDgoMissF30D = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF30D = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF30DP263 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF30DP264 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF30DP265 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF30DP266 = FHCAN_NOT_DETECTED;
}

void FHCANF30D_vidFrameReceived(void)
{
	boolean Local_bCtrl_FRE_30D;
	boolean Local_bCtrl_spdLeFrntWhl;
	boolean Local_bCtrl_spdRiFrntWhl;
	boolean Local_bCtrl_spdLeReWhl;
	boolean Local_bCtrl_spdRiReWhl;

	VEMS_vidGET(Ctrl_FRE_30D, Local_bCtrl_FRE_30D);
	if (ACTIVATED == Local_bCtrl_FRE_30D)
	{
		ISCAN_EveRxn_30D();
		FHCAN30D_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF30D)
      {
         Ext_bDgoMissF30D = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF30D,
                  Ext_bDgoMissF30D,
                  Ext_bMonRunMissF30D,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_spdLeFrntWhl, Local_bCtrl_spdLeFrntWhl);
		if (ACTIVATED == Local_bCtrl_spdLeFrntWhl)
		{
			FHCAN30D_vidCalcMonFP263Window();
			Com_ReceiveSignal(Com_VITESSE_ROUE_AVG_NF_FRE_30D, (void*) &ISCAN_u16N16F30DP263);

			FHCAN30D_vidMonInvldP263Update();

			FHCANF30D_vidUpdateSignalP263();
		}
		else
		{
			VEMS_vidSET(Ext_spdLeFrntWhl, 0);
			VEMS_vidSET(Ext_bNotAvl_spdLeFrntWhl, AVAILABLE);
			Ext_bMonRunInvldF30DP263 = FHCAN_DISABLE;
			Ext_bDgoInvldF30DP263 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_spdRiFrntWhl, Local_bCtrl_spdRiFrntWhl);
		if (ACTIVATED == Local_bCtrl_spdRiFrntWhl)
		{
			FHCAN30D_vidCalcMonFP264Window();
			Com_ReceiveSignal(Com_VITESSE_ROUE_AVD_NF_FRE_30D, (void*) &ISCAN_u16N16F30DP264);

			FHCAN30D_vidMonInvldP264Update();

			FHCANF30D_vidUpdateSignalP264();
		}
		else
		{
			VEMS_vidSET(Ext_spdRiFrntWhl, 0);
			VEMS_vidSET(Ext_bNotAvl_spdRiFrntWhl, AVAILABLE);
			Ext_bMonRunInvldF30DP264 = FHCAN_DISABLE;
			Ext_bDgoInvldF30DP264 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_spdLeReWhl, Local_bCtrl_spdLeReWhl);
		if (ACTIVATED == Local_bCtrl_spdLeReWhl)
		{
			FHCAN30D_vidCalcMonFP265Window();
			Com_ReceiveSignal(Com_VITESSE_ROUE_ARG_NF_FRE_30D, (void*) &ISCAN_u16N16F30DP265);

			FHCAN30D_vidMonInvldP265Update();

			FHCANF30D_vidUpdateSignalP265();
		}
		else
		{
			VEMS_vidSET(Ext_spdLeReWhl, 0);
			VEMS_vidSET(Ext_bNotAvl_spdLeReWhl, AVAILABLE);
			Ext_bMonRunInvldF30DP265 = FHCAN_DISABLE;
			Ext_bDgoInvldF30DP265 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_spdRiReWhl, Local_bCtrl_spdRiReWhl);
		if (ACTIVATED == Local_bCtrl_spdRiReWhl)
		{
			FHCAN30D_vidCalcMonFP266Window();
			Com_ReceiveSignal(Com_VITESSE_ROUE_ARD_NF_FRE_30D, (void*) &ISCAN_u16N16F30DP266);

			FHCAN30D_vidMonInvldP266Update();

			FHCANF30D_vidUpdateSignalP266();
		}
		else
		{
			VEMS_vidSET(Ext_spdRiReWhl, 0);
			VEMS_vidSET(Ext_bNotAvl_spdRiReWhl, AVAILABLE);
			Ext_bMonRunInvldF30DP266 = FHCAN_DISABLE;
			Ext_bDgoInvldF30DP266 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF30D = FHCAN_DISABLE;
		Ext_bMonRunShoF30D = FHCAN_DISABLE;
		Ext_bMonRunInvldF30DP263 = FHCAN_DISABLE;
		Ext_bMonRunInvldF30DP264 = FHCAN_DISABLE;
		Ext_bMonRunInvldF30DP265 = FHCAN_DISABLE;
		Ext_bMonRunInvldF30DP266 = FHCAN_DISABLE;

		Ext_bDgoMissF30D = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF30D = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF30DP263 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF30DP264 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF30DP265 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF30DP266 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF30D_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF30DP263_in;
	boolean FRM_bAcvRcvF30DP264_in;
	boolean FRM_bAcvRcvF30DP265_in;
	boolean FRM_bAcvRcvF30DP266_in;
	boolean FRM_bAcvRcvF30D_in;
	boolean Local_bCtrl_FRE_30D;
	boolean Local_bCtrl_spdLeFrntWhl;
	boolean Local_bCtrl_spdRiFrntWhl;
	boolean Local_bCtrl_spdLeReWhl;
	boolean Local_bCtrl_spdRiReWhl;


	VEMS_vidGET(Ctrl_FRE_30D, Local_bCtrl_FRE_30D);
	if (ACTIVATED == Local_bCtrl_FRE_30D)
	{
		FHCAN30D_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF30D)
      {
         Ext_bDgoMissF30D = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF30D,
                  Ext_bDgoMissF30D,
                  Ext_bMonRunMissF30D,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_spdLeFrntWhl, 0);
		   VEMS_vidSET(Ext_bNotAvl_spdLeFrntWhl, AVAILABLE);
		   VEMS_vidSET(Ext_spdRiFrntWhl, 0);
		   VEMS_vidSET(Ext_bNotAvl_spdRiFrntWhl, AVAILABLE);
		   VEMS_vidSET(Ext_spdLeReWhl, 0);
		   VEMS_vidSET(Ext_bNotAvl_spdLeReWhl, AVAILABLE);
		   VEMS_vidSET(Ext_spdRiReWhl, 0);
		   VEMS_vidSET(Ext_bNotAvl_spdRiReWhl, AVAILABLE);
      }

		FRM_bAcvRcvF30DP263_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30DP263);
		FRM_bAcvRcvF30DP264_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30DP264);
		FRM_bAcvRcvF30DP265_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30DP265);
		FRM_bAcvRcvF30DP266_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30DP266);
		FRM_bAcvRcvF30D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30D);

		VEMS_vidGET(Ctrl_spdLeFrntWhl, Local_bCtrl_spdLeFrntWhl);
		if (ACTIVATED == Local_bCtrl_spdLeFrntWhl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF30DP263_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF30D_in))
			{
		      VEMS_vidSET(Ext_spdLeFrntWhl, Ext_spdLeFrntWhlRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_spdRiFrntWhl, Local_bCtrl_spdRiFrntWhl);
		if (ACTIVATED == Local_bCtrl_spdRiFrntWhl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF30DP264_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF30D_in))
			{
		      VEMS_vidSET(Ext_spdRiFrntWhl, Ext_spdRiFrntWhlRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_spdLeReWhl, Local_bCtrl_spdLeReWhl);
		if (ACTIVATED == Local_bCtrl_spdLeReWhl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF30DP265_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF30D_in))
			{
		      VEMS_vidSET(Ext_spdLeReWhl, Ext_spdLeReWhlRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_spdRiReWhl, Local_bCtrl_spdRiReWhl);
		if (ACTIVATED == Local_bCtrl_spdRiReWhl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF30DP266_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF30D_in))
			{
		      VEMS_vidSET(Ext_spdRiReWhl, Ext_spdRiReWhlRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF30D = FHCAN_DISABLE;
		Ext_bMonRunShoF30D = FHCAN_DISABLE;
		Ext_bMonRunInvldF30DP263 = FHCAN_DISABLE;
		Ext_bMonRunInvldF30DP264 = FHCAN_DISABLE;
		Ext_bMonRunInvldF30DP265 = FHCAN_DISABLE;
		Ext_bMonRunInvldF30DP266 = FHCAN_DISABLE;

		Ext_bDgoMissF30D = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF30D = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF30DP263 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF30DP264 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF30DP265 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF30DP266 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF30D_vidUpdateSignalP263(void)
{
	boolean FRM_bAcvRcvF30DP263_in;
	boolean FRM_bAcvRcvF30D_in;
   uint16 u16LocalExt_spdLeFrntWhl;

   if (ISCAN_u16N16F30DP263 == 65534)
	{
		VEMS_vidSET(Ext_bNotAvl_spdLeFrntWhl, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_spdLeFrntWhl, AVAILABLE);
	}

	FRM_bAcvRcvF30DP263_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30DP263);
	FRM_bAcvRcvF30D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF30DP263_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF30D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF30DP263)
	   && (FHCAN_DETECTED != Ext_bDgoShoF30D)
	   )
	{
      u16LocalExt_spdLeFrntWhl = (uint16)(MATHSRV_udtMIN(ISCAN_u16N16F30DP263,
                                             65533));
      VEMS_vidSET(Ext_spdLeFrntWhl,
                  u16LocalExt_spdLeFrntWhl);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF30DP263_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF30D_in))
      {
			VEMS_vidSET(Ext_spdLeFrntWhl, Ext_spdLeFrntWhlRcf_C);
		}
	}
}

void FHCANF30D_vidUpdateSignalP264(void)
{
	boolean FRM_bAcvRcvF30DP264_in;
	boolean FRM_bAcvRcvF30D_in;
   uint16 u16LocalExt_spdRiFrntWhl;

   if (ISCAN_u16N16F30DP264 == 65534)
	{
		VEMS_vidSET(Ext_bNotAvl_spdRiFrntWhl, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_spdRiFrntWhl, AVAILABLE);
	}

	FRM_bAcvRcvF30DP264_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30DP264);
	FRM_bAcvRcvF30D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF30DP264_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF30D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF30DP264)
	   && (FHCAN_DETECTED != Ext_bDgoShoF30D)
	   )
	{
      u16LocalExt_spdRiFrntWhl = (uint16)(MATHSRV_udtMIN(ISCAN_u16N16F30DP264,
                                             65533));
      VEMS_vidSET(Ext_spdRiFrntWhl,
                  u16LocalExt_spdRiFrntWhl);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF30DP264_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF30D_in))
      {
			VEMS_vidSET(Ext_spdRiFrntWhl, Ext_spdRiFrntWhlRcf_C);
		}
	}
}

void FHCANF30D_vidUpdateSignalP265(void)
{
	boolean FRM_bAcvRcvF30DP265_in;
	boolean FRM_bAcvRcvF30D_in;
   uint16 u16LocalExt_spdLeReWhl;

   if (ISCAN_u16N16F30DP265 == 65534)
	{
		VEMS_vidSET(Ext_bNotAvl_spdLeReWhl, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_spdLeReWhl, AVAILABLE);
	}

	FRM_bAcvRcvF30DP265_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30DP265);
	FRM_bAcvRcvF30D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF30DP265_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF30D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF30DP265)
	   && (FHCAN_DETECTED != Ext_bDgoShoF30D)
	   )
	{
      u16LocalExt_spdLeReWhl = (uint16)(MATHSRV_udtMIN(ISCAN_u16N16F30DP265,
                                             65533));
      VEMS_vidSET(Ext_spdLeReWhl,
                  u16LocalExt_spdLeReWhl);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF30DP265_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF30D_in))
      {
			VEMS_vidSET(Ext_spdLeReWhl, Ext_spdLeReWhlRcf_C);
		}
	}
}

void FHCANF30D_vidUpdateSignalP266(void)
{
	boolean FRM_bAcvRcvF30DP266_in;
	boolean FRM_bAcvRcvF30D_in;
   uint16 u16LocalExt_spdRiReWhl;

   if (ISCAN_u16N16F30DP266 == 65534)
	{
		VEMS_vidSET(Ext_bNotAvl_spdRiReWhl, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_spdRiReWhl, AVAILABLE);
	}

	FRM_bAcvRcvF30DP266_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30DP266);
	FRM_bAcvRcvF30D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF30D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF30DP266_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF30D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF30DP266)
	   && (FHCAN_DETECTED != Ext_bDgoShoF30D)
	   )
	{
      u16LocalExt_spdRiReWhl = (uint16)(MATHSRV_udtMIN(ISCAN_u16N16F30DP266,
                                             65533));
      VEMS_vidSET(Ext_spdRiReWhl,
                  u16LocalExt_spdRiReWhl);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF30DP266_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF30D_in))
      {
			VEMS_vidSET(Ext_spdRiReWhl, Ext_spdRiReWhlRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

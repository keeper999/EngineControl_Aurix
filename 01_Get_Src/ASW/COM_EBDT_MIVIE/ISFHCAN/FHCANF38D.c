/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF38D.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF38D.H"
#include "FHCANF38D_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_38D(void)
{
	ISCAN_u16N16F38DP010 = 0;
	ISCAN_u8N8F38DP052 = 175;
	ISCAN_u8N4F38DPM2849 = 0;
	ISCAN_u8N4F38DP607 = 0;
	ISCAN_bF38DP688 = 1;

	VEMS_vidSET(Ext_spdEspVeh, 0);
	VEMS_vidSET(Ext_aVeh, 0);
	VEMS_vidSET(Ext_ctClcProc38D, 0);
	VEMS_vidSET(Ext_noCks38D, 0);
	VEMS_vidSET(CoReqCha_bHillAsiRdyEngStop, 1);
	Ext_bMonRunUC_FREINAbsent = FHCAN_DISABLE;
	Ext_bDgoUC_FREINAbsent = FHCAN_NOT_DETECTED;

	Ext_bMonRunMissF38D = FHCAN_DISABLE;
	Ext_bMonRunShoF38D = FHCAN_DISABLE;
	Ext_bMonRunChkF38D = FHCAN_DISABLE;
	Ext_bMonRunInvldF38DP010 = FHCAN_DISABLE;
	Ext_bMonRunInvldF38DP052 = FHCAN_DISABLE;

	Ext_bDgoMissF38D = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF38D = FHCAN_NOT_DETECTED;
	Ext_bDgoChkF38D = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF38DP010 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF38DP052 = FHCAN_NOT_DETECTED;
}

void FHCANF38D_vidFrameReceived(void)
{
	boolean Local_bCtrl_ABR_38D;
	boolean Local_bCtrl_spdEspVeh;
	boolean Local_bCtrl_aVeh;
	boolean Local_bCtrl_ctClcProc38D;
	boolean Local_bCtrl_noCks38D;
	boolean Local_bCtrl_bHillAsiRdyEngStop;

	VEMS_vidGET(Ctrl_ABR_38D, Local_bCtrl_ABR_38D);
	if (ACTIVATED == Local_bCtrl_ABR_38D)
	{
		ISCAN_EveRxn_38D();
		FHCAN38D_vidCalcMonUC_FREINWindow();
		FHCAN38D_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunUC_FREINAbsent)
		{
			Ext_bDgoUC_FREINAbsent = FHCAN_NOT_DETECTED;
			GDGAR_vidGdu(GD_DFT_UC_FREINABSENT,
						Ext_bDgoUC_FREINAbsent,
						Ext_bMonRunUC_FREINAbsent,
						DIAG_DISPO);
		}
	  	if (FHCAN_ENABLE == Ext_bMonRunMissF38D)
      {
         Ext_bDgoMissF38D = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF38D,
                  Ext_bDgoMissF38D,
                  Ext_bMonRunMissF38D,
                  DIAG_DISPO);
      }
            
		if (FHCAN_ENABLE == Ext_bMonRunCntF38D)
      {
         Ext_bDgoCntF38D = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF38D,
                  Ext_bDgoCntF38D,
                  Ext_bMonRunCntF38D,
                  DIAG_DISPO);
      }

		VEMS_vidGET(Ctrl_spdEspVeh, Local_bCtrl_spdEspVeh);
		if (ACTIVATED == Local_bCtrl_spdEspVeh)
		{
			FHCAN38D_vidCalcMonFP010Window();
			Com_ReceiveSignal(Com_VITESSE_VEHICULE_ROUES_ABR_38D, (void*) &ISCAN_u16N16F38DP010);

			FHCAN38D_vidMonInvldP010Update();

			FHCANF38D_vidUpdateSignalP010();
		}
		else
		{
			VEMS_vidSET(Ext_spdEspVeh, 0);

			Ext_bMonRunInvldF38DP010 = FHCAN_DISABLE;
			Ext_bDgoInvldF38DP010 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_aVeh, Local_bCtrl_aVeh);
		if (ACTIVATED == Local_bCtrl_aVeh)
		{
			FHCAN38D_vidCalcMonFP052Window();
			Com_ReceiveSignal(Com_ACCEL_LONGI_ROUES_ABR_38D, (void*) &ISCAN_u8N8F38DP052);

			FHCAN38D_vidMonInvldP052Update();

			FHCANF38D_vidUpdateSignalP052();
		}
		else
		{
			VEMS_vidSET(Ext_aVeh, 0);

			Ext_bMonRunInvldF38DP052 = FHCAN_DISABLE;
			Ext_bDgoInvldF38DP052 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_ctClcProc38D, Local_bCtrl_ctClcProc38D);
		if (ACTIVATED == Local_bCtrl_ctClcProc38D)
		{
			Com_ReceiveSignal(Com_CPT_PROCESS_4B_38D_ABR_38D, (void*) &ISCAN_u8N4F38DPM2849);


			FHCANF38D_vidUpdateSignalPM2849();
		}
		else
		{
			VEMS_vidSET(Ext_ctClcProc38D, 0);

		}
		VEMS_vidGET(Ctrl_noCks38D, Local_bCtrl_noCks38D);
		if (ACTIVATED == Local_bCtrl_noCks38D)
		{
			Com_ReceiveSignal(Com_CHKSUM_TRME_DYN_UC_FREIN_ABR_38D, (void*) &ISCAN_u8N4F38DP607);


			FHCANF38D_vidUpdateSignalP607();
		}
		else
		{
			VEMS_vidSET(Ext_noCks38D, 0);

		}
		VEMS_vidGET(Ctrl_bHillAsiRdyEngStop, Local_bCtrl_bHillAsiRdyEngStop);
		if (ACTIVATED == Local_bCtrl_bHillAsiRdyEngStop)
		{
			Com_ReceiveSignal(Com_AUTOR_ARRET_HILL_STT_ABR_38D, (void*) &ISCAN_bF38DP688);


			FHCANF38D_vidUpdateSignalP688();
		}
		else
		{
			VEMS_vidSET(CoReqCha_bHillAsiRdyEngStop, 1);

		}
	}
	else
	{
		Ext_bMonRunUC_FREINAbsent = FHCAN_DISABLE;
		Ext_bDgoUC_FREINAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF38D = FHCAN_DISABLE;
		Ext_bMonRunShoF38D = FHCAN_DISABLE;
		Ext_bMonRunChkF38D = FHCAN_DISABLE;
		Ext_bMonRunInvldF38DP010 = FHCAN_DISABLE;
		Ext_bMonRunInvldF38DP052 = FHCAN_DISABLE;

		Ext_bDgoMissF38D = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF38D = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF38D = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF38DP010 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF38DP052 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF38D_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF38DP010_in;
	boolean FRM_bAcvRcvF38DP052_in;
	boolean FRM_bAcvRcvF38D_in;
	boolean Local_bCtrl_ABR_38D;
	boolean Local_bCtrl_spdEspVeh;
	boolean Local_bCtrl_aVeh;
	boolean Local_bCtrl_ctClcProc38D;
	boolean Local_bCtrl_noCks38D;
	boolean Local_bCtrl_bHillAsiRdyEngStop;
	uint8 Local_Ext_ctClcProc38D;
	uint8 Local_Ext_noCks38D;
	boolean Local_CoReqCha_bHillAsiRdyEngStop;


	VEMS_vidGET(Ctrl_ABR_38D, Local_bCtrl_ABR_38D);
	if (ACTIVATED == Local_bCtrl_ABR_38D)
	{
		FHCAN38D_vidCalcMonUC_FREINWindow();
		FHCAN38D_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunUC_FREINAbsent)
		{
			Ext_bDgoUC_FREINAbsent = FHCAN_DETECTED;
			GDGAR_vidGdu(GD_DFT_UC_FREINABSENT,
						Ext_bDgoUC_FREINAbsent,
						Ext_bMonRunUC_FREINAbsent,
						DIAG_DISPO);
		}
      if (FHCAN_ENABLE == Ext_bMonRunMissF38D)
      {
         Ext_bDgoMissF38D = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF38D,
                  Ext_bDgoMissF38D,
                  Ext_bMonRunMissF38D,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_spdEspVeh, 0);
		   VEMS_vidSET(Ext_aVeh, 0);
		   VEMS_vidSET(Ext_ctClcProc38D, 0);
		   VEMS_vidSET(Ext_noCks38D, 0);
		   VEMS_vidSET(CoReqCha_bHillAsiRdyEngStop, 1);
      }

		FRM_bAcvRcvF38DP010_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF38DP010);
		FRM_bAcvRcvF38DP052_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF38DP052);
		FRM_bAcvRcvF38D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF38D);

		VEMS_vidGET(Ctrl_spdEspVeh, Local_bCtrl_spdEspVeh);
		if (ACTIVATED == Local_bCtrl_spdEspVeh)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF38DP010_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF38D_in))
			{
		      VEMS_vidSET(Ext_spdEspVeh, Ext_spdEspVehRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_aVeh, Local_bCtrl_aVeh);
		if (ACTIVATED == Local_bCtrl_aVeh)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF38DP052_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF38D_in))
			{
		      VEMS_vidSET(Ext_aVeh, Ext_aVehRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_ctClcProc38D, Local_bCtrl_ctClcProc38D);
		if (ACTIVATED == Local_bCtrl_ctClcProc38D)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF38D_in)
			{
		      VEMS_vidGET(Ext_ctClcProc38D, Local_Ext_ctClcProc38D);
		      VEMS_vidSET(Ext_ctClcProc38D, Local_Ext_ctClcProc38D);
			}
		}
		VEMS_vidGET(Ctrl_noCks38D, Local_bCtrl_noCks38D);
		if (ACTIVATED == Local_bCtrl_noCks38D)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF38D_in)
			{
		      VEMS_vidGET(Ext_noCks38D, Local_Ext_noCks38D);
		      VEMS_vidSET(Ext_noCks38D, Local_Ext_noCks38D);
			}
		}
		VEMS_vidGET(Ctrl_bHillAsiRdyEngStop, Local_bCtrl_bHillAsiRdyEngStop);
		if (ACTIVATED == Local_bCtrl_bHillAsiRdyEngStop)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF38D_in)
			{
		      VEMS_vidGET(CoReqCha_bHillAsiRdyEngStop, Local_CoReqCha_bHillAsiRdyEngStop);
		      VEMS_vidSET(CoReqCha_bHillAsiRdyEngStop, Local_CoReqCha_bHillAsiRdyEngStop);
			}
		}
	}
	else
	{
		Ext_bMonRunUC_FREINAbsent = FHCAN_DISABLE;
		Ext_bDgoUC_FREINAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF38D = FHCAN_DISABLE;
		Ext_bMonRunShoF38D = FHCAN_DISABLE;
		Ext_bMonRunChkF38D = FHCAN_DISABLE;
		Ext_bMonRunInvldF38DP010 = FHCAN_DISABLE;
		Ext_bMonRunInvldF38DP052 = FHCAN_DISABLE;

		Ext_bDgoMissF38D = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF38D = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF38D = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF38DP010 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF38DP052 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF38D_vidUpdateSignalP010(void)
{
	boolean FRM_bAcvRcvF38DP010_in;
	boolean FRM_bAcvRcvF38D_in;
   uint16 u16LocalExt_spdEspVeh;

	FRM_bAcvRcvF38DP010_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF38DP010);
	FRM_bAcvRcvF38D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF38D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF38DP010_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF38D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF38DP010)
	   && (FHCAN_DETECTED != Ext_bDgoShoF38D)
	   )
	{
      u16LocalExt_spdEspVeh = (uint16)(MATHSRV_udtMIN(ISCAN_u16N16F38DP010,
                                             65534));
      VEMS_vidSET(Ext_spdEspVeh,
                  u16LocalExt_spdEspVeh);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF38DP010_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF38D_in))
      {
			VEMS_vidSET(Ext_spdEspVeh, Ext_spdEspVehRcf_C);
		}
	}
}

void FHCANF38D_vidUpdateSignalP052(void)
{
	boolean FRM_bAcvRcvF38DP052_in;
	boolean FRM_bAcvRcvF38D_in;
   sint16 s16LocalIscanABR_38D;
   sint16 s16LocalExt_aVeh;

	FRM_bAcvRcvF38DP052_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF38DP052);
	FRM_bAcvRcvF38D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF38D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF38DP052_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF38D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF38DP052)
	   && (FHCAN_DETECTED != Ext_bDgoShoF38D)
	   )
	{
      s16LocalIscanABR_38D = (sint16)((ISCAN_u8N8F38DP052) - 175);
      s16LocalExt_aVeh = (sint16)(MATHSRV_udtCLAMP(s16LocalIscanABR_38D,
                                               -175,
                                               79));
      VEMS_vidSET(Ext_aVeh,
                  s16LocalExt_aVeh);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF38DP052_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF38D_in))
      {
			VEMS_vidSET(Ext_aVeh, Ext_aVehRcf_C);
		}
	}
}

void FHCANF38D_vidUpdateSignalPM2849(void)
{
	boolean FRM_bAcvRcvF38D_in;
   uint8 u8LocalExt_ctClcProc38D;

	uint8 Local_Ext_ctClcProc38D;

	FRM_bAcvRcvF38D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF38D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF38D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF38D)
	   )
	{
      u8LocalExt_ctClcProc38D = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F38DPM2849,
                                             15));
      VEMS_vidSET(Ext_ctClcProc38D,
                  u8LocalExt_ctClcProc38D);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF38D_in)
      {
			VEMS_vidGET(Ext_ctClcProc38D, Local_Ext_ctClcProc38D);
			VEMS_vidSET(Ext_ctClcProc38D, Local_Ext_ctClcProc38D);
		}
	}
}

void FHCANF38D_vidUpdateSignalP607(void)
{
	boolean FRM_bAcvRcvF38D_in;
   uint8 u8LocalExt_noCks38D;

	uint8 Local_Ext_noCks38D;

	FRM_bAcvRcvF38D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF38D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF38D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF38D)
	   )
	{
      u8LocalExt_noCks38D = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F38DP607,
                                             15));
      VEMS_vidSET(Ext_noCks38D,
                  u8LocalExt_noCks38D);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF38D_in)
      {
			VEMS_vidGET(Ext_noCks38D, Local_Ext_noCks38D);
			VEMS_vidSET(Ext_noCks38D, Local_Ext_noCks38D);
		}
	}
}

void FHCANF38D_vidUpdateSignalP688(void)
{
	boolean FRM_bAcvRcvF38D_in;

	boolean Local_CoReqCha_bHillAsiRdyEngStop;

	FRM_bAcvRcvF38D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF38D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF38D_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF38D)
	   )
	{
      VEMS_vidSET(CoReqCha_bHillAsiRdyEngStop,
                  ISCAN_bF38DP688);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF38D_in)
      {
			VEMS_vidGET(CoReqCha_bHillAsiRdyEngStop, Local_CoReqCha_bHillAsiRdyEngStop);
			VEMS_vidSET(CoReqCha_bHillAsiRdyEngStop, Local_CoReqCha_bHillAsiRdyEngStop);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

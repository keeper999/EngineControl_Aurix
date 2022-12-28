/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF305.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF305.H"
#include "FHCANF305_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_305(void)
{
	ISCAN_s16N16F305P537 = 0;
	ISCAN_u8N8F305P538 = 0;
	ISCAN_u8N4F305P846 = 0;
	ISCAN_u8N4F305P871 = 0;

	VEMS_vidSET(Stg_agStrWhl, 0);
	VEMS_vidSET(Stg_agvStrWhl, 0);
	VEMS_vidSET(Ext_noCks305, 0);
	VEMS_vidSET(Ext_ctClcProc305, 0);
	Ext_bMonRunCAPT_VOLAbsent = FHCAN_DISABLE;
	Ext_bDgoCAPT_VOLAbsent = FHCAN_NOT_DETECTED;

	Ext_bMonRunMissF305 = FHCAN_DISABLE;
	Ext_bMonRunShoF305 = FHCAN_DISABLE;
	Ext_bMonRunChkF305 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF305P537 = FHCAN_DISABLE;
	Ext_bMonRunInvldF305P537 = FHCAN_DISABLE;
	Ext_bMonRunInvldF305P538 = FHCAN_DISABLE;

	Ext_bDgoMissF305 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF305 = FHCAN_NOT_DETECTED;
	Ext_bDgoChkF305 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF305P537 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF305P537 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF305P538 = FHCAN_NOT_DETECTED;
}

void FHCANF305_vidFrameReceived(void)
{
	boolean Local_bCtrl_VOL_305;
	boolean Local_bCtrl_bagStrWhl;
	boolean Local_bCtrl_bagvStrWhl;
	boolean Local_bCtrl_bnoCks305;
	boolean Local_bCtrl_bctClcProc305;

	VEMS_vidGET(Ctrl_VOL_305, Local_bCtrl_VOL_305);
	if (ACTIVATED == Local_bCtrl_VOL_305)
	{
		ISCAN_EveRxn_305();
		FHCAN305_vidCalcMonCAPT_VOLWindow();
		FHCAN305_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunCAPT_VOLAbsent)
		{
			Ext_bDgoCAPT_VOLAbsent = FHCAN_NOT_DETECTED;
			GDGAR_vidGdu(GD_DFT_CAPT_VOLABSENT,
						Ext_bDgoCAPT_VOLAbsent,
						Ext_bMonRunCAPT_VOLAbsent,
						DIAG_DISPO);
		}
	  	if (FHCAN_ENABLE == Ext_bMonRunMissF305)
      {
         Ext_bDgoMissF305 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF305,
                  Ext_bDgoMissF305,
                  Ext_bMonRunMissF305,
                  DIAG_DISPO);
      }
            
		if (FHCAN_ENABLE == Ext_bMonRunCntF305)
      {
         Ext_bDgoCntF305 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF305,
                  Ext_bDgoCntF305,
                  Ext_bMonRunCntF305,
                  DIAG_DISPO);
      }

		VEMS_vidGET(Ctrl_bagStrWhl, Local_bCtrl_bagStrWhl);
		if (ACTIVATED == Local_bCtrl_bagStrWhl)
		{
			FHCAN305_vidCalcMonFP537Window();
			Com_ReceiveSignal(Com_ANGLE_VOLANT_VOL_305, (void*) &ISCAN_s16N16F305P537);

			FHCAN305_vidMonInvldP537Update();
			FHCAN305_vidMonFrbdP537Update();

			FHCANF305_vidUpdateSignalP537();
		}
		else
		{
			VEMS_vidSET(Stg_agStrWhl, 0);

			Ext_bMonRunFrbdF305P537 = FHCAN_DISABLE;
			Ext_bMonRunInvldF305P537 = FHCAN_DISABLE;
			Ext_bDgoFrbdF305P537 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF305P537 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bagvStrWhl, Local_bCtrl_bagvStrWhl);
		if (ACTIVATED == Local_bCtrl_bagvStrWhl)
		{
			FHCAN305_vidCalcMonFP538Window();
			Com_ReceiveSignal(Com_VITESSE_ROT_VOL_VOL_305, (void*) &ISCAN_u8N8F305P538);

			FHCAN305_vidMonInvldP538Update();

			FHCANF305_vidUpdateSignalP538();
		}
		else
		{
			VEMS_vidSET(Stg_agvStrWhl, 0);

			Ext_bMonRunInvldF305P538 = FHCAN_DISABLE;
			Ext_bDgoInvldF305P538 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bnoCks305, Local_bCtrl_bnoCks305);
		if (ACTIVATED == Local_bCtrl_bnoCks305)
		{
			Com_ReceiveSignal(Com_CHKSUM_VOL_VOL_305, (void*) &ISCAN_u8N4F305P846);


			FHCANF305_vidUpdateSignalP846();
		}
		else
		{
			VEMS_vidSET(Ext_noCks305, 0);

		}
		VEMS_vidGET(Ctrl_bctClcProc305, Local_bCtrl_bctClcProc305);
		if (ACTIVATED == Local_bCtrl_bctClcProc305)
		{
			Com_ReceiveSignal(Com_CPT_PROCESS_4B_A_VOL_VOL_305, (void*) &ISCAN_u8N4F305P871);


			FHCANF305_vidUpdateSignalP871();
		}
		else
		{
			VEMS_vidSET(Ext_ctClcProc305, 0);

		}
	}
	else
	{
		Ext_bMonRunCAPT_VOLAbsent = FHCAN_DISABLE;
		Ext_bDgoCAPT_VOLAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF305 = FHCAN_DISABLE;
		Ext_bMonRunShoF305 = FHCAN_DISABLE;
		Ext_bMonRunChkF305 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF305P537 = FHCAN_DISABLE;
		Ext_bMonRunInvldF305P537 = FHCAN_DISABLE;
		Ext_bMonRunInvldF305P538 = FHCAN_DISABLE;

		Ext_bDgoMissF305 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF305 = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF305 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF305P537 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF305P537 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF305P538 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF305_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF305P537_in;
	boolean FRM_bAcvRcvF305P538_in;
	boolean FRM_bAcvRcvF305_in;
	boolean Local_bCtrl_VOL_305;
	boolean Local_bCtrl_bagStrWhl;
	boolean Local_bCtrl_bagvStrWhl;
	boolean Local_bCtrl_bnoCks305;
	boolean Local_bCtrl_bctClcProc305;
	uint8 Local_Ext_noCks305;
	uint8 Local_Ext_ctClcProc305;


	VEMS_vidGET(Ctrl_VOL_305, Local_bCtrl_VOL_305);
	if (ACTIVATED == Local_bCtrl_VOL_305)
	{
		FHCAN305_vidCalcMonCAPT_VOLWindow();
		FHCAN305_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunCAPT_VOLAbsent)
		{
			Ext_bDgoCAPT_VOLAbsent = FHCAN_DETECTED;
			GDGAR_vidGdu(GD_DFT_CAPT_VOLABSENT,
						Ext_bDgoCAPT_VOLAbsent,
						Ext_bMonRunCAPT_VOLAbsent,
						DIAG_DISPO);
		}
      if (FHCAN_ENABLE == Ext_bMonRunMissF305)
      {
         Ext_bDgoMissF305 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF305,
                  Ext_bDgoMissF305,
                  Ext_bMonRunMissF305,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Stg_agStrWhl, 0);
		   VEMS_vidSET(Stg_agvStrWhl, 0);
		   VEMS_vidSET(Ext_noCks305, 0);
		   VEMS_vidSET(Ext_ctClcProc305, 0);
      }

		FRM_bAcvRcvF305P537_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF305P537);
		FRM_bAcvRcvF305P538_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF305P538);
		FRM_bAcvRcvF305_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF305);

		VEMS_vidGET(Ctrl_bagStrWhl, Local_bCtrl_bagStrWhl);
		if (ACTIVATED == Local_bCtrl_bagStrWhl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF305P537_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF305_in))
			{
		      VEMS_vidSET(Stg_agStrWhl, Stg_agStrWhlRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bagvStrWhl, Local_bCtrl_bagvStrWhl);
		if (ACTIVATED == Local_bCtrl_bagvStrWhl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF305P538_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF305_in))
			{
		      VEMS_vidSET(Stg_agvStrWhl, Stg_agvStrWhlRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bnoCks305, Local_bCtrl_bnoCks305);
		if (ACTIVATED == Local_bCtrl_bnoCks305)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF305_in)
			{
		      VEMS_vidGET(Ext_noCks305, Local_Ext_noCks305);
		      VEMS_vidSET(Ext_noCks305, Local_Ext_noCks305);
			}
		}
		VEMS_vidGET(Ctrl_bctClcProc305, Local_bCtrl_bctClcProc305);
		if (ACTIVATED == Local_bCtrl_bctClcProc305)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF305_in)
			{
		      VEMS_vidGET(Ext_ctClcProc305, Local_Ext_ctClcProc305);
		      VEMS_vidSET(Ext_ctClcProc305, Local_Ext_ctClcProc305);
			}
		}
	}
	else
	{
		Ext_bMonRunCAPT_VOLAbsent = FHCAN_DISABLE;
		Ext_bDgoCAPT_VOLAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF305 = FHCAN_DISABLE;
		Ext_bMonRunShoF305 = FHCAN_DISABLE;
		Ext_bMonRunChkF305 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF305P537 = FHCAN_DISABLE;
		Ext_bMonRunInvldF305P537 = FHCAN_DISABLE;
		Ext_bMonRunInvldF305P538 = FHCAN_DISABLE;

		Ext_bDgoMissF305 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF305 = FHCAN_NOT_DETECTED;
		Ext_bDgoChkF305 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF305P537 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF305P537 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF305P538 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF305_vidUpdateSignalP537(void)
{
	boolean FRM_bAcvRcvF305P537_in;
	boolean FRM_bAcvRcvF305_in;
   sint16 s16LocalStg_agStrWhl;

	FRM_bAcvRcvF305P537_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF305P537);
	FRM_bAcvRcvF305_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF305);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF305P537_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF305_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF305P537)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF305P537)
	   && (FHCAN_DETECTED != Ext_bDgoShoF305)
	   )
	{
      s16LocalStg_agStrWhl = (sint16)(MATHSRV_udtCLAMP(ISCAN_s16N16F305P537,
                                               -7800,
                                               7800));
      VEMS_vidSET(Stg_agStrWhl,
                  s16LocalStg_agStrWhl);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF305P537_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF305_in))
      {
			VEMS_vidSET(Stg_agStrWhl, Stg_agStrWhlRcf_C);
		}
	}
}

void FHCANF305_vidUpdateSignalP538(void)
{
	boolean FRM_bAcvRcvF305P538_in;
	boolean FRM_bAcvRcvF305_in;
   uint16 u16LocalStg_agvStrWhl;

	FRM_bAcvRcvF305P538_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF305P538);
	FRM_bAcvRcvF305_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF305);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF305P538_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF305_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF305P538)
	   && (FHCAN_DETECTED != Ext_bDgoShoF305)
	   )
	{
      u16LocalStg_agvStrWhl = (uint16)(MATHSRV_udtMIN(ISCAN_u8N8F305P538,
                                             265));
      VEMS_vidSET(Stg_agvStrWhl,
                  u16LocalStg_agvStrWhl);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF305P538_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF305_in))
      {
			VEMS_vidSET(Stg_agvStrWhl, Stg_agvStrWhlRcf_C);
		}
	}
}

void FHCANF305_vidUpdateSignalP846(void)
{
	boolean FRM_bAcvRcvF305_in;
   uint8 u8LocalExt_noCks305;

	uint8 Local_Ext_noCks305;

	FRM_bAcvRcvF305_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF305);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF305_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF305)
	   )
	{
      u8LocalExt_noCks305 = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F305P846,
                                             15));
      VEMS_vidSET(Ext_noCks305,
                  u8LocalExt_noCks305);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF305_in)
      {
			VEMS_vidGET(Ext_noCks305, Local_Ext_noCks305);
			VEMS_vidSET(Ext_noCks305, Local_Ext_noCks305);
		}
	}
}

void FHCANF305_vidUpdateSignalP871(void)
{
	boolean FRM_bAcvRcvF305_in;
   uint8 u8LocalExt_ctClcProc305;

	uint8 Local_Ext_ctClcProc305;

	FRM_bAcvRcvF305_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF305);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF305_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF305)
	   )
	{
      u8LocalExt_ctClcProc305 = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F305P871,
                                             15));
      VEMS_vidSET(Ext_ctClcProc305,
                  u8LocalExt_ctClcProc305);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF305_in)
      {
			VEMS_vidGET(Ext_ctClcProc305, Local_Ext_ctClcProc305);
			VEMS_vidSET(Ext_ctClcProc305, Local_Ext_ctClcProc305);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

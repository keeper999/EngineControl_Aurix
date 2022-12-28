/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF612.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF612.H"
#include "FHCANF612_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_612(void)
{
	ISCAN_u8N2F612P927 = 2;
	ISCAN_u8N8F612P260 = 0;
	ISCAN_u16N11F612P436 = 1300;
	ISCAN_u8N3F612P705 = 4;

	VEMS_vidSET(Ext_stCtlModFSF, 2);
	VEMS_vidSET( ShwRm_bAcvFSF, 2);
	VEMS_vidSET(Ext_rFuTnkPerc, 0);
	VEMS_vidSET(Ext_uBattStrt, 1664);
	VEMS_vidSET(Ext_bNotAvl_uBattStrt, AVAILABLE);
	VEMS_vidSET(Ext_stVehCf, 4);

	Ext_bMonRunMissF612 = FHCAN_DISABLE;
	Ext_bMonRunShoF612 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF612P927 = FHCAN_DISABLE;
	Ext_bMonRunInvldF612P260 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF612P436 = FHCAN_DISABLE;
	Ext_bMonRunInvldF612P436 = FHCAN_DISABLE;
	Ext_bMonRunInvldF612P705 = FHCAN_DISABLE;

	Ext_bDgoMissF612 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF612 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF612P927 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF612P260 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF612P436 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF612P436 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF612P705 = FHCAN_NOT_DETECTED;
}

void FHCANF612_vidFrameReceived(void)
{
	boolean Local_bCtrl_BSI_612;
	boolean Local_bCtrl_stCtlModFSF;
	boolean Local_bCtrl_rFuTnkPerc;
	boolean Local_bCtrl_uBattStrt;
	boolean Local_bCtrl_bAcv_stVehCf;

	VEMS_vidGET(Ctrl_BSI_612, Local_bCtrl_BSI_612);
	if (ACTIVATED == Local_bCtrl_BSI_612)
	{
		ISCAN_EveRxn_612();
		FHCAN612_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF612)
      {
         Ext_bDgoMissF612 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF612,
                  Ext_bDgoMissF612,
                  Ext_bMonRunMissF612,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_stCtlModFSF, Local_bCtrl_stCtlModFSF);
		if (ACTIVATED == Local_bCtrl_stCtlModFSF)
		{
			FHCAN612_vidCalcMonFP927Window();
			Com_ReceiveSignal(Com_MODE_CONF_VEH_BSI_612, (void*) &ISCAN_u8N2F612P927);

			FHCAN612_vidMonFrbdP927Update();

			FHCANF612_vidUpdateSignalP927();
		}
		else
		{
			VEMS_vidSET(Ext_stCtlModFSF, 2);
			VEMS_vidSET( ShwRm_bAcvFSF, 2);

			Ext_bMonRunFrbdF612P927 = FHCAN_DISABLE;
			Ext_bDgoFrbdF612P927 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_rFuTnkPerc, Local_bCtrl_rFuTnkPerc);
		if (ACTIVATED == Local_bCtrl_rFuTnkPerc)
		{
			FHCAN612_vidCalcMonFP260Window();
			Com_ReceiveSignal(Com_INFO_NIV_CARB_BSI_612, (void*) &ISCAN_u8N8F612P260);

			FHCAN612_vidMonInvldP260Update();

			FHCANF612_vidUpdateSignalP260();
		}
		else
		{
			VEMS_vidSET(Ext_rFuTnkPerc, 0);

			Ext_bMonRunInvldF612P260 = FHCAN_DISABLE;
			Ext_bDgoInvldF612P260 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_uBattStrt, Local_bCtrl_uBattStrt);
		if (ACTIVATED == Local_bCtrl_uBattStrt)
		{
			FHCAN612_vidCalcMonFP436Window();
			Com_ReceiveSignal(Com_U_PRED_DEMARRAGE_BSI_612, (void*) &ISCAN_u16N11F612P436);

			FHCAN612_vidMonInvldP436Update();
			FHCAN612_vidMonFrbdP436Update();

			FHCANF612_vidUpdateSignalP436();
		}
		else
		{
			VEMS_vidSET(Ext_uBattStrt, 1664);
			VEMS_vidSET(Ext_bNotAvl_uBattStrt, AVAILABLE);
			Ext_bMonRunFrbdF612P436 = FHCAN_DISABLE;
			Ext_bMonRunInvldF612P436 = FHCAN_DISABLE;
			Ext_bDgoFrbdF612P436 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF612P436 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bAcv_stVehCf, Local_bCtrl_bAcv_stVehCf);
		if (ACTIVATED == Local_bCtrl_bAcv_stVehCf)
		{
			FHCAN612_vidCalcMonFP705Window();
			Com_ReceiveSignal(Com_CONFIG_VHL_BSI_612, (void*) &ISCAN_u8N3F612P705);

			FHCAN612_vidMonInvldP705Update();

			FHCANF612_vidUpdateSignalP705();
		}
		else
		{
			VEMS_vidSET(Ext_stVehCf, 4);

			Ext_bMonRunInvldF612P705 = FHCAN_DISABLE;
			Ext_bDgoInvldF612P705 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF612 = FHCAN_DISABLE;
		Ext_bMonRunShoF612 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF612P927 = FHCAN_DISABLE;
		Ext_bMonRunInvldF612P260 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF612P436 = FHCAN_DISABLE;
		Ext_bMonRunInvldF612P436 = FHCAN_DISABLE;
		Ext_bMonRunInvldF612P705 = FHCAN_DISABLE;

		Ext_bDgoMissF612 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF612 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF612P927 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF612P260 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF612P436 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF612P436 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF612P705 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF612_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF612P927_in;
	boolean FRM_bAcvRcvF612P260_in;
	boolean FRM_bAcvRcvF612P436_in;
	boolean FRM_bAcvRcvF612P705_in;
	boolean FRM_bAcvRcvF612_in;
	boolean Local_bCtrl_BSI_612;
	boolean Local_bCtrl_stCtlModFSF;
	boolean Local_bCtrl_rFuTnkPerc;
	boolean Local_bCtrl_uBattStrt;
	boolean Local_bCtrl_bAcv_stVehCf;
	uint16 Local_Ext_uBattStrt;


	VEMS_vidGET(Ctrl_BSI_612, Local_bCtrl_BSI_612);
	if (ACTIVATED == Local_bCtrl_BSI_612)
	{
		FHCAN612_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF612)
      {
         Ext_bDgoMissF612 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF612,
                  Ext_bDgoMissF612,
                  Ext_bMonRunMissF612,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_stCtlModFSF, 2);
		   VEMS_vidSET( ShwRm_bAcvFSF, 2);
		   VEMS_vidSET(Ext_rFuTnkPerc, 0);
		   VEMS_vidSET(Ext_uBattStrt, 1664);
		   VEMS_vidSET(Ext_bNotAvl_uBattStrt, AVAILABLE);
		   VEMS_vidSET(Ext_stVehCf, 4);
      }

		FRM_bAcvRcvF612P927_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612P927);
		FRM_bAcvRcvF612P260_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612P260);
		FRM_bAcvRcvF612P436_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612P436);
		FRM_bAcvRcvF612P705_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612P705);
		FRM_bAcvRcvF612_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612);

		VEMS_vidGET(Ctrl_stCtlModFSF, Local_bCtrl_stCtlModFSF);
		if (ACTIVATED == Local_bCtrl_stCtlModFSF)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF612P927_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF612_in))
			{
		      VEMS_vidSET(Ext_stCtlModFSF, Ext_stCtlModFSFRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_rFuTnkPerc, Local_bCtrl_rFuTnkPerc);
		if (ACTIVATED == Local_bCtrl_rFuTnkPerc)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF612P260_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF612_in))
			{
		      VEMS_vidSET(Ext_rFuTnkPerc, Ext_rFuTnkPercRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_uBattStrt, Local_bCtrl_uBattStrt);
		if (ACTIVATED == Local_bCtrl_uBattStrt)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF612P436_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF612_in))
			{
		      VEMS_vidGET(Ext_uBattStrt, Local_Ext_uBattStrt);
		      VEMS_vidSET(Ext_uBattStrt, Local_Ext_uBattStrt);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_stVehCf, Local_bCtrl_bAcv_stVehCf);
		if (ACTIVATED == Local_bCtrl_bAcv_stVehCf)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF612P705_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF612_in))
			{
		      VEMS_vidSET(Ext_stVehCf, Ext_stVehCfRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF612 = FHCAN_DISABLE;
		Ext_bMonRunShoF612 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF612P927 = FHCAN_DISABLE;
		Ext_bMonRunInvldF612P260 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF612P436 = FHCAN_DISABLE;
		Ext_bMonRunInvldF612P436 = FHCAN_DISABLE;
		Ext_bMonRunInvldF612P705 = FHCAN_DISABLE;

		Ext_bDgoMissF612 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF612 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF612P927 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF612P260 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF612P436 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF612P436 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF612P705 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF612_vidUpdateSignalP927(void)
{
	boolean FRM_bAcvRcvF612P927_in;
	boolean FRM_bAcvRcvF612_in;
   uint8 u8LocalExt_stCtlModFSF;

	FRM_bAcvRcvF612P927_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612P927);
	FRM_bAcvRcvF612_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF612P927_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF612_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF612P927)
	   && (FHCAN_DETECTED != Ext_bDgoShoF612)
	   )
	{
      u8LocalExt_stCtlModFSF = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F612P927,
                                             2));
      VEMS_vidSET(Ext_stCtlModFSF,
                  u8LocalExt_stCtlModFSF);
      if (ISCAN_u8N2F612P927 >= 1)
      {
         VEMS_vidSET( ShwRm_bAcvFSF, 1);
      }
      else
      {
         VEMS_vidSET( ShwRm_bAcvFSF, 0);
      }
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF612P927_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF612_in))
      {
			VEMS_vidSET(Ext_stCtlModFSF, Ext_stCtlModFSFRcf_C);
		}
	}
}

void FHCANF612_vidUpdateSignalP260(void)
{
	boolean FRM_bAcvRcvF612P260_in;
	boolean FRM_bAcvRcvF612_in;
   uint8 u8LocalExt_rFuTnkPerc;

	FRM_bAcvRcvF612P260_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612P260);
	FRM_bAcvRcvF612_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF612P260_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF612_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF612P260)
	   && (FHCAN_DETECTED != Ext_bDgoShoF612)
	   )
	{
      u8LocalExt_rFuTnkPerc = ISCAN_u8N8F612P260;
      VEMS_vidSET(Ext_rFuTnkPerc,
                  u8LocalExt_rFuTnkPerc);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF612P260_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF612_in))
      {
			VEMS_vidSET(Ext_rFuTnkPerc, Ext_rFuTnkPercRcf_C);
		}
	}
}

void FHCANF612_vidUpdateSignalP436(void)
{
	boolean FRM_bAcvRcvF612P436_in;
	boolean FRM_bAcvRcvF612_in;
   uint32 u32LocalIscanBSI_612;
   uint16 u16LocalExt_uBattStrt;

	uint16 Local_Ext_uBattStrt;

   if (ISCAN_u16N11F612P436 == 2046)
	{
		VEMS_vidSET(Ext_bNotAvl_uBattStrt, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_uBattStrt, AVAILABLE);
	}

	FRM_bAcvRcvF612P436_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612P436);
	FRM_bAcvRcvF612_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF612P436_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF612_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF612P436)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF612P436)
	   && (FHCAN_DETECTED != Ext_bDgoShoF612)
	   )
	{
      u32LocalIscanBSI_612 = (uint32)(((32 * ISCAN_u16N11F612P436) / 25));
      u16LocalExt_uBattStrt = (uint16)(MATHSRV_udtMIN(u32LocalIscanBSI_612,
                                             1664));
      VEMS_vidSET(Ext_uBattStrt,
                  u16LocalExt_uBattStrt);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF612P436_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF612_in))
      {
			VEMS_vidGET(Ext_uBattStrt, Local_Ext_uBattStrt);
			VEMS_vidSET(Ext_uBattStrt, Local_Ext_uBattStrt);
		}
	}
}

void FHCANF612_vidUpdateSignalP705(void)
{
	boolean FRM_bAcvRcvF612P705_in;
	boolean FRM_bAcvRcvF612_in;
   uint8 u8LocalExt_stVehCf;

	FRM_bAcvRcvF612P705_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612P705);
	FRM_bAcvRcvF612_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF612);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF612P705_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF612_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF612P705)
	   && (FHCAN_DETECTED != Ext_bDgoShoF612)
	   )
	{
      u8LocalExt_stVehCf = (uint8)(MATHSRV_udtMIN(ISCAN_u8N3F612P705,
                                             7));
      VEMS_vidSET(Ext_stVehCf,
                  u8LocalExt_stVehCf);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF612P705_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF612_in))
      {
			VEMS_vidSET(Ext_stVehCf, Ext_stVehCfRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF5B2.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF5B2.H"
#include "FHCANF5B2_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_5B2(void)
{
	ISCAN_u8N8F5B2P146 = 252;
	ISCAN_u8N8F5B2P301 = 0;

	VEMS_vidSET(Ext_tAirSideMirrMes_5B2h, 172);
	VEMS_vidSET(Ext_bNotAvl_tAirExtMes, AVAILABLE);
	VEMS_vidSET(CoRegVeh_stDftOBD, 0);

	Ext_bMonRunMissF5B2 = FHCAN_DISABLE;
	Ext_bMonRunShoF5B2 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF5B2P146 = FHCAN_DISABLE;
	Ext_bMonRunInvldF5B2P146 = FHCAN_DISABLE;

	Ext_bDgoMissF5B2 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF5B2 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF5B2P146 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF5B2P146 = FHCAN_NOT_DETECTED;
}

void FHCANF5B2_vidFrameReceived(void)
{
	boolean Local_bCtrl_CONTEXTE_1_5B2;
	boolean Local_bCtrl_tAirExtMes5B2;
	boolean Local_bCtrl_bAcv_stDftOBDIS5B2;

	VEMS_vidGET(Ctrl_CONTEXTE_1_5B2, Local_bCtrl_CONTEXTE_1_5B2);
	if (ACTIVATED == Local_bCtrl_CONTEXTE_1_5B2)
	{
		ISCAN_EveRxn_5B2();
		FHCAN5B2_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF5B2)
      {
         Ext_bDgoMissF5B2 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF5B2,
                  Ext_bDgoMissF5B2,
                  Ext_bMonRunMissF5B2,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_tAirExtMes5B2, Local_bCtrl_tAirExtMes5B2);
		if (ACTIVATED == Local_bCtrl_tAirExtMes5B2)
		{
			FHCAN5B2_vidCalcMonFP146Window();
			Com_ReceiveSignal(Com_TEMP_AIR_EXT_CONTEXTE_1_5B2, (void*) &ISCAN_u8N8F5B2P146);

			FHCAN5B2_vidMonInvldP146Update();
			FHCAN5B2_vidMonFrbdP146Update();

			FHCANF5B2_vidUpdateSignalP146();
		}
		else
		{
			VEMS_vidSET(Ext_tAirSideMirrMes_5B2h, 172);
			VEMS_vidSET(Ext_bNotAvl_tAirExtMes, AVAILABLE);
			Ext_bMonRunFrbdF5B2P146 = FHCAN_DISABLE;
			Ext_bMonRunInvldF5B2P146 = FHCAN_DISABLE;
			Ext_bDgoFrbdF5B2P146 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF5B2P146 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bAcv_stDftOBDIS5B2, Local_bCtrl_bAcv_stDftOBDIS5B2);
		if (ACTIVATED == Local_bCtrl_bAcv_stDftOBDIS5B2)
		{
			Com_ReceiveSignal(Com_ETAT_INFO_EOBD_BSI_CONTEXTE_1_5B2, (void*) &ISCAN_u8N8F5B2P301);


			FHCANF5B2_vidUpdateSignalP301();
		}
		else
		{
			VEMS_vidSET(CoRegVeh_stDftOBD, 0);

		}
	}
	else
	{
		Ext_bMonRunMissF5B2 = FHCAN_DISABLE;
		Ext_bMonRunShoF5B2 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF5B2P146 = FHCAN_DISABLE;
		Ext_bMonRunInvldF5B2P146 = FHCAN_DISABLE;

		Ext_bDgoMissF5B2 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF5B2 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF5B2P146 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF5B2P146 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF5B2_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF5B2P146_in;
	boolean FRM_bAcvRcvF5B2_in;
	boolean Local_bCtrl_CONTEXTE_1_5B2;
	boolean Local_bCtrl_tAirExtMes5B2;
	boolean Local_bCtrl_bAcv_stDftOBDIS5B2;
	uint8 Local_CoRegVeh_stDftOBD;


	VEMS_vidGET(Ctrl_CONTEXTE_1_5B2, Local_bCtrl_CONTEXTE_1_5B2);
	if (ACTIVATED == Local_bCtrl_CONTEXTE_1_5B2)
	{
		FHCAN5B2_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF5B2)
      {
         Ext_bDgoMissF5B2 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF5B2,
                  Ext_bDgoMissF5B2,
                  Ext_bMonRunMissF5B2,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_tAirSideMirrMes_5B2h, 172);
		   VEMS_vidSET(Ext_bNotAvl_tAirExtMes, AVAILABLE);
		   VEMS_vidSET(CoRegVeh_stDftOBD, 0);
      }

		FRM_bAcvRcvF5B2P146_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF5B2P146);
		FRM_bAcvRcvF5B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF5B2);

		VEMS_vidGET(Ctrl_tAirExtMes5B2, Local_bCtrl_tAirExtMes5B2);
		if (ACTIVATED == Local_bCtrl_tAirExtMes5B2)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF5B2P146_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF5B2_in))
			{
		      VEMS_vidSET(Ext_tAirSideMirrMes_5B2h, Ext_tAirExtMesRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_stDftOBDIS5B2, Local_bCtrl_bAcv_stDftOBDIS5B2);
		if (ACTIVATED == Local_bCtrl_bAcv_stDftOBDIS5B2)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF5B2_in)
			{
		      VEMS_vidGET(CoRegVeh_stDftOBD, Local_CoRegVeh_stDftOBD);
		      VEMS_vidSET(CoRegVeh_stDftOBD, Local_CoRegVeh_stDftOBD);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF5B2 = FHCAN_DISABLE;
		Ext_bMonRunShoF5B2 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF5B2P146 = FHCAN_DISABLE;
		Ext_bMonRunInvldF5B2P146 = FHCAN_DISABLE;

		Ext_bDgoMissF5B2 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF5B2 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF5B2P146 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF5B2P146 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF5B2_vidUpdateSignalP146(void)
{
	boolean FRM_bAcvRcvF5B2P146_in;
	boolean FRM_bAcvRcvF5B2_in;
   sint16 s16LocalIscanCONTEXTE_1_5B2;
   sint16 s16LocalExt_tAirSideMirrMes_5B2h;

   if ((ISCAN_u8N8F5B2P146 == 252) || (ISCAN_u8N8F5B2P146 == 253))

	{
		VEMS_vidSET(Ext_bNotAvl_tAirExtMes, NOT_AVAILABLE);
	}
	else
	{
		VEMS_vidSET(Ext_bNotAvl_tAirExtMes, AVAILABLE);
	}

	FRM_bAcvRcvF5B2P146_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF5B2P146);
	FRM_bAcvRcvF5B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF5B2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF5B2P146_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF5B2_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF5B2P146)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF5B2P146)
	   && (FHCAN_DETECTED != Ext_bDgoShoF5B2)
	   )
	{
      s16LocalIscanCONTEXTE_1_5B2 = (sint16)((ISCAN_u8N8F5B2P146) - 80);
      s16LocalExt_tAirSideMirrMes_5B2h = (sint16)(MATHSRV_udtCLAMP(s16LocalIscanCONTEXTE_1_5B2,
                                               -80,
                                               174));
      VEMS_vidSET(Ext_tAirSideMirrMes_5B2h,
                  s16LocalExt_tAirSideMirrMes_5B2h);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF5B2P146_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF5B2_in))
      {
			VEMS_vidSET(Ext_tAirSideMirrMes_5B2h, Ext_tAirExtMesRcf_C);
		}
	}
}

void FHCANF5B2_vidUpdateSignalP301(void)
{
	boolean FRM_bAcvRcvF5B2_in;
   uint8 u8LocalCoRegVeh_stDftOBD;

	uint8 Local_CoRegVeh_stDftOBD;

	FRM_bAcvRcvF5B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF5B2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF5B2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF5B2)
	   )
	{
      u8LocalCoRegVeh_stDftOBD = ISCAN_u8N8F5B2P301;
      VEMS_vidSET(CoRegVeh_stDftOBD,
                  u8LocalCoRegVeh_stDftOBD);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF5B2_in)
      {
			VEMS_vidGET(CoRegVeh_stDftOBD, Local_CoRegVeh_stDftOBD);
			VEMS_vidSET(CoRegVeh_stDftOBD, Local_CoRegVeh_stDftOBD);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

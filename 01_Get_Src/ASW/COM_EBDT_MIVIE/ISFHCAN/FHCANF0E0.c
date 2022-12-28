/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF0E0.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF0E0.H"
#include "FHCANF0E0_PRIVATE.H"
#include "CTRLCFG.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_0E0(void)
{
	ISCAN_u8N8F0E0P822 = 0;
	ISCAN_u8N8F0E0PM1426 = 0;
	ISCAN_u8N8F0E0PM1427 = 0;
	ISCAN_u8N8F0E0PM1428 = 0;
	ISCAN_u8N8F0E0PM1429 = 0;

	VEMS_vidSET(ISCAN_u8F0E0Pos1, 0);
	VEMS_vidSET(ISCAN_u8F0E0Pos2, 0);
	VEMS_vidSET(ISCAN_u8F0E0Pos3, 0);
	VEMS_vidSET(ISCAN_u8F0E0Pos4, 0);
	VEMS_vidSET(ISCAN_u8F0E0Pos5, 0);
}

void FHCANF0E0_vidFrameReceived(void)
{
	boolean Local_bCtrl_UCC_CMM_0E0;
	boolean Local_bCtrl_stUnBlockAuthImmo;
	boolean Local_bCtrl_stUCCKeyImmo;

	VEMS_vidGET(Ctrl_UCC_CMM_0E0, Local_bCtrl_UCC_CMM_0E0);
	if (ACTIVATED == Local_bCtrl_UCC_CMM_0E0)
	{
		ISCAN_EveRxn_0E0();
		VEMS_vidGET(Ctrl_stUnBlockAuthImmo, Local_bCtrl_stUnBlockAuthImmo);
		if (ACTIVATED == Local_bCtrl_stUnBlockAuthImmo)
		{
			Com_ReceiveSignal(Com_AUTORIS_DVRRLLGE_UCC_CMM_0E0, (void*) &ISCAN_u8N8F0E0P822);


			FHCANF0E0_vidUpdateSignalP822();
		}
		else
		{
			VEMS_vidSET(ISCAN_u8F0E0Pos1, 0);

		}
		VEMS_vidGET(Ctrl_stUCCKeyImmo, Local_bCtrl_stUCCKeyImmo);
		if (ACTIVATED == Local_bCtrl_stUCCKeyImmo)
		{
			Com_ReceiveSignal(Com_CLF_UC_CLIENT_PDS_PLS_FRT_UCC_CMM_0E0, (void*) &ISCAN_u8N8F0E0PM1426);


			FHCANF0E0_vidUpdateSignalPM1426();
		}
		else
		{
			VEMS_vidSET(ISCAN_u8F0E0Pos2, 0);

		}
		VEMS_vidGET(Ctrl_stUCCKeyImmo, Local_bCtrl_stUCCKeyImmo);
		if (ACTIVATED == Local_bCtrl_stUCCKeyImmo)
		{
			Com_ReceiveSignal(Com_CLF_UC_CLIENT_PDS_FRT_UCC_CMM_0E0, (void*) &ISCAN_u8N8F0E0PM1427);


			FHCANF0E0_vidUpdateSignalPM1427();
		}
		else
		{
			VEMS_vidSET(ISCAN_u8F0E0Pos3, 0);

		}
		VEMS_vidGET(Ctrl_stUCCKeyImmo, Local_bCtrl_stUCCKeyImmo);
		if (ACTIVATED == Local_bCtrl_stUCCKeyImmo)
		{
			Com_ReceiveSignal(Com_CLF_UC_CLIENT_PDS_FBLE_UCC_CMM_0E0, (void*) &ISCAN_u8N8F0E0PM1428);


			FHCANF0E0_vidUpdateSignalPM1428();
		}
		else
		{
			VEMS_vidSET(ISCAN_u8F0E0Pos4, 0);

		}
		VEMS_vidGET(Ctrl_stUCCKeyImmo, Local_bCtrl_stUCCKeyImmo);
		if (ACTIVATED == Local_bCtrl_stUCCKeyImmo)
		{
			Com_ReceiveSignal(Com_CLF_UC_CLIENT_PDS_PLS_FBLE_UCC_CMM_0E0, (void*) &ISCAN_u8N8F0E0PM1429);


			FHCANF0E0_vidUpdateSignalPM1429();
		}
		else
		{
			VEMS_vidSET(ISCAN_u8F0E0Pos5, 0);

		}
	}
}



void FHCANF0E0_vidFrameNotReceived(void)
{
	boolean Local_bCtrl_UCC_CMM_0E0;
	uint8 Local_ISCAN_u8F0E0Pos1;
	uint8 Local_ISCAN_u8F0E0Pos2;
	uint8 Local_ISCAN_u8F0E0Pos3;
	uint8 Local_ISCAN_u8F0E0Pos4;
	uint8 Local_ISCAN_u8F0E0Pos5;


	VEMS_vidGET(Ctrl_UCC_CMM_0E0, Local_bCtrl_UCC_CMM_0E0);
	if (ACTIVATED == Local_bCtrl_UCC_CMM_0E0)
	{
		VEMS_vidGET(ISCAN_u8F0E0Pos1, Local_ISCAN_u8F0E0Pos1);
		VEMS_vidSET(ISCAN_u8F0E0Pos1, Local_ISCAN_u8F0E0Pos1);
		VEMS_vidGET(ISCAN_u8F0E0Pos2, Local_ISCAN_u8F0E0Pos2);
		VEMS_vidSET(ISCAN_u8F0E0Pos2, Local_ISCAN_u8F0E0Pos2);
		VEMS_vidGET(ISCAN_u8F0E0Pos3, Local_ISCAN_u8F0E0Pos3);
		VEMS_vidSET(ISCAN_u8F0E0Pos3, Local_ISCAN_u8F0E0Pos3);
		VEMS_vidGET(ISCAN_u8F0E0Pos4, Local_ISCAN_u8F0E0Pos4);
		VEMS_vidSET(ISCAN_u8F0E0Pos4, Local_ISCAN_u8F0E0Pos4);
		VEMS_vidGET(ISCAN_u8F0E0Pos5, Local_ISCAN_u8F0E0Pos5);
		VEMS_vidSET(ISCAN_u8F0E0Pos5, Local_ISCAN_u8F0E0Pos5);
	}
}

void FHCANF0E0_vidUpdateSignalP822(void)
{
   uint8 u8LocalISCAN_u8F0E0Pos1;

   u8LocalISCAN_u8F0E0Pos1 = ISCAN_u8N8F0E0P822;
   VEMS_vidSET(ISCAN_u8F0E0Pos1,
               u8LocalISCAN_u8F0E0Pos1);
}

void FHCANF0E0_vidUpdateSignalPM1426(void)
{
   uint8 u8LocalISCAN_u8F0E0Pos2;

   u8LocalISCAN_u8F0E0Pos2 = ISCAN_u8N8F0E0PM1426;
   VEMS_vidSET(ISCAN_u8F0E0Pos2,
               u8LocalISCAN_u8F0E0Pos2);
}

void FHCANF0E0_vidUpdateSignalPM1427(void)
{
   uint8 u8LocalISCAN_u8F0E0Pos3;

   u8LocalISCAN_u8F0E0Pos3 = ISCAN_u8N8F0E0PM1427;
   VEMS_vidSET(ISCAN_u8F0E0Pos3,
               u8LocalISCAN_u8F0E0Pos3);
}

void FHCANF0E0_vidUpdateSignalPM1428(void)
{
   uint8 u8LocalISCAN_u8F0E0Pos4;

   u8LocalISCAN_u8F0E0Pos4 = ISCAN_u8N8F0E0PM1428;
   VEMS_vidSET(ISCAN_u8F0E0Pos4,
               u8LocalISCAN_u8F0E0Pos4);
}

void FHCANF0E0_vidUpdateSignalPM1429(void)
{
   uint8 u8LocalISCAN_u8F0E0Pos5;

   u8LocalISCAN_u8F0E0Pos5 = ISCAN_u8N8F0E0PM1429;
   VEMS_vidSET(ISCAN_u8F0E0Pos5,
               u8LocalISCAN_u8F0E0Pos5);
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

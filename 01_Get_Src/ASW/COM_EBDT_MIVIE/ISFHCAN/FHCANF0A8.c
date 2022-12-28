/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF0A8.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF0A8.H"
#include "FHCANF0A8_PRIVATE.H"
#include "CTRLCFG.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_0A8(void)
{
	ISCAN_u8N8F0A8P822 = 0;
	ISCAN_u8N8F0A8P823 = 0;
	ISCAN_u8N8F0A8P824 = 0;
	ISCAN_u8N8F0A8P825 = 0;
	ISCAN_u8N8F0A8P826 = 0;

	VEMS_vidSET(ISCAN_u8F0A8Pos1, 0);
	VEMS_vidSET(ISCAN_u8F0A8Pos2, 0);
	VEMS_vidSET(ISCAN_u8F0A8Pos3, 0);
	VEMS_vidSET(ISCAN_u8F0A8Pos4, 0);
	VEMS_vidSET(ISCAN_u8F0A8Pos5, 0);
}

void FHCANF0A8_vidFrameReceived(void)
{
	boolean Local_bCtrl_BSI_CMM_0A8;
	boolean Local_bCtrl_stUnBlockAuthImmo;
	boolean Local_bCtrl_stBSIKeyImmo;

	VEMS_vidGET(Ctrl_BSI_CMM_0A8, Local_bCtrl_BSI_CMM_0A8);
	if (ACTIVATED == Local_bCtrl_BSI_CMM_0A8)
	{
		ISCAN_EveRxn_0A8();
		VEMS_vidGET(Ctrl_stUnBlockAuthImmo, Local_bCtrl_stUnBlockAuthImmo);
		if (ACTIVATED == Local_bCtrl_stUnBlockAuthImmo)
		{
			Com_ReceiveSignal(Com_AUTORIS_DVRRLLGE_BSI_CMM_0A8, (void*) &ISCAN_u8N8F0A8P822);


			FHCANF0A8_vidUpdateSignalP822();
		}
		else
		{
			VEMS_vidSET(ISCAN_u8F0A8Pos1, 0);

		}
		VEMS_vidGET(Ctrl_stBSIKeyImmo, Local_bCtrl_stBSIKeyImmo);
		if (ACTIVATED == Local_bCtrl_stBSIKeyImmo)
		{
			Com_ReceiveSignal(Com_CLF_BSI_PDS_PLS_FRT_BSI_CMM_0A8, (void*) &ISCAN_u8N8F0A8P823);


			FHCANF0A8_vidUpdateSignalP823();
		}
		else
		{
			VEMS_vidSET(ISCAN_u8F0A8Pos2, 0);

		}
		VEMS_vidGET(Ctrl_stBSIKeyImmo, Local_bCtrl_stBSIKeyImmo);
		if (ACTIVATED == Local_bCtrl_stBSIKeyImmo)
		{
			Com_ReceiveSignal(Com_CLF_BSI_PDS_FRT_BSI_CMM_0A8, (void*) &ISCAN_u8N8F0A8P824);


			FHCANF0A8_vidUpdateSignalP824();
		}
		else
		{
			VEMS_vidSET(ISCAN_u8F0A8Pos3, 0);

		}
		VEMS_vidGET(Ctrl_stBSIKeyImmo, Local_bCtrl_stBSIKeyImmo);
		if (ACTIVATED == Local_bCtrl_stBSIKeyImmo)
		{
			Com_ReceiveSignal(Com_CLF_BSI_PDS_FBLE_BSI_CMM_0A8, (void*) &ISCAN_u8N8F0A8P825);


			FHCANF0A8_vidUpdateSignalP825();
		}
		else
		{
			VEMS_vidSET(ISCAN_u8F0A8Pos4, 0);

		}
		VEMS_vidGET(Ctrl_stBSIKeyImmo, Local_bCtrl_stBSIKeyImmo);
		if (ACTIVATED == Local_bCtrl_stBSIKeyImmo)
		{
			Com_ReceiveSignal(Com_CLF_BSI_PDS_PLS_FBLE_BSI_CMM_0A8, (void*) &ISCAN_u8N8F0A8P826);


			FHCANF0A8_vidUpdateSignalP826();
		}
		else
		{
			VEMS_vidSET(ISCAN_u8F0A8Pos5, 0);

		}
	}
}



void FHCANF0A8_vidFrameNotReceived(void)
{
	boolean Local_bCtrl_BSI_CMM_0A8;
	uint8 Local_ISCAN_u8F0A8Pos1;
	uint8 Local_ISCAN_u8F0A8Pos2;
	uint8 Local_ISCAN_u8F0A8Pos3;
	uint8 Local_ISCAN_u8F0A8Pos4;
	uint8 Local_ISCAN_u8F0A8Pos5;


	VEMS_vidGET(Ctrl_BSI_CMM_0A8, Local_bCtrl_BSI_CMM_0A8);
	if (ACTIVATED == Local_bCtrl_BSI_CMM_0A8)
	{
		VEMS_vidGET(ISCAN_u8F0A8Pos1, Local_ISCAN_u8F0A8Pos1);
		VEMS_vidSET(ISCAN_u8F0A8Pos1, Local_ISCAN_u8F0A8Pos1);
		VEMS_vidGET(ISCAN_u8F0A8Pos2, Local_ISCAN_u8F0A8Pos2);
		VEMS_vidSET(ISCAN_u8F0A8Pos2, Local_ISCAN_u8F0A8Pos2);
		VEMS_vidGET(ISCAN_u8F0A8Pos3, Local_ISCAN_u8F0A8Pos3);
		VEMS_vidSET(ISCAN_u8F0A8Pos3, Local_ISCAN_u8F0A8Pos3);
		VEMS_vidGET(ISCAN_u8F0A8Pos4, Local_ISCAN_u8F0A8Pos4);
		VEMS_vidSET(ISCAN_u8F0A8Pos4, Local_ISCAN_u8F0A8Pos4);
		VEMS_vidGET(ISCAN_u8F0A8Pos5, Local_ISCAN_u8F0A8Pos5);
		VEMS_vidSET(ISCAN_u8F0A8Pos5, Local_ISCAN_u8F0A8Pos5);
	}
}

void FHCANF0A8_vidUpdateSignalP822(void)
{
   uint8 u8LocalISCAN_u8F0A8Pos1;

   u8LocalISCAN_u8F0A8Pos1 = ISCAN_u8N8F0A8P822;
   VEMS_vidSET(ISCAN_u8F0A8Pos1,
               u8LocalISCAN_u8F0A8Pos1);
}

void FHCANF0A8_vidUpdateSignalP823(void)
{
   uint8 u8LocalISCAN_u8F0A8Pos2;

   u8LocalISCAN_u8F0A8Pos2 = ISCAN_u8N8F0A8P823;
   VEMS_vidSET(ISCAN_u8F0A8Pos2,
               u8LocalISCAN_u8F0A8Pos2);
}

void FHCANF0A8_vidUpdateSignalP824(void)
{
   uint8 u8LocalISCAN_u8F0A8Pos3;

   u8LocalISCAN_u8F0A8Pos3 = ISCAN_u8N8F0A8P824;
   VEMS_vidSET(ISCAN_u8F0A8Pos3,
               u8LocalISCAN_u8F0A8Pos3);
}

void FHCANF0A8_vidUpdateSignalP825(void)
{
   uint8 u8LocalISCAN_u8F0A8Pos4;

   u8LocalISCAN_u8F0A8Pos4 = ISCAN_u8N8F0A8P825;
   VEMS_vidSET(ISCAN_u8F0A8Pos4,
               u8LocalISCAN_u8F0A8Pos4);
}

void FHCANF0A8_vidUpdateSignalP826(void)
{
   uint8 u8LocalISCAN_u8F0A8Pos5;

   u8LocalISCAN_u8F0A8Pos5 = ISCAN_u8N8F0A8P826;
   VEMS_vidSET(ISCAN_u8F0A8Pos5,
               u8LocalISCAN_u8F0A8Pos5);
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

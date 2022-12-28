/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 08/10/2014 15:03:49 */
/* File: ISCANF3B8.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF3B8.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_3B8(void)
{
	ISCAN_u16N16F3B8PM1493 = 0;
	ISCAN_u8N8F3B8PM1494 = 205;
	ISCAN_u8N8F3B8PM1495 = 255;
	ISCAN_u8N8F3B8PM1496 = 205;
	ISCAN_u8N8F3B8PM1497 = 205;
	ISCAN_u8N4F3B8PM1779 = 0;
	ISCAN_PBkind8N4F3B8FreOrStub1 = 0;
}


void ISCAN_vidEve_Tx_3B8(void)
{
	boolean Local_bCtrl_CMM_3B8;
	boolean Local_bCtrl_bAcv_noNEngCplm;
	boolean Local_bCtrl_bAcv_noTqCkEngRealCplm;
	boolean Local_bCtrl_bAcv_noRatDrvReqCplm;
	boolean Local_bCtrl_bAcv_noTqAirDrvFilCplm;
	boolean Local_bCtrl_bAcv_noTqDrvFilCplm;
	boolean Local_bCtrl_bAcv_ctClcProc3B8;
	boolean FRM_bInhF3B8PM1493_in;
	boolean FRM_bInhF3B8PM1494_in;
	boolean FRM_bInhF3B8PM1495_in;
	boolean FRM_bInhF3B8PM1496_in;
	boolean FRM_bInhF3B8PM1497_in;
   uint16 u16LocalN16F3B8PM1493;

   uint8 u8LocalN8F3B8PM1494;
   uint8 u8LocalN8F3B8PM1495;
   uint8 u8LocalN8F3B8PM1496;
   uint8 u8LocalN8F3B8PM1497;

	VEMS_vidGET(Ctrl_CMM_3B8, Local_bCtrl_CMM_3B8);
	if (ACTIVATED == Local_bCtrl_CMM_3B8)
	{
		VEMS_vidGET(Ctrl_bAcv_noNEngCplm, Local_bCtrl_bAcv_noNEngCplm);
		if (ACTIVATED == Local_bCtrl_bAcv_noNEngCplm)
		{
			FRM_bInhF3B8PM1493_in = GDGAR_bGetFRM(FRM_FRM_INHF3B8PM1493);
			if (FRM_bInhF3B8PM1493_in == FALSE)
			{
            u16LocalN16F3B8PM1493 = (uint16)(0xFFFF - ISCAN_u16N16F208P000);
            ISCAN_u16N16F3B8PM1493 = (uint16)MATHSRV_udtMAX(u16LocalN16F3B8PM1493, 1);    
			}
			else
			{
				ISCAN_u16N16F3B8PM1493 = 0;
			}
			Com_SendSignal(Com_CPLMT1_REGIME_MOTEUR_CMM_3B8, (void*) &ISCAN_u16N16F3B8PM1493);
      }

		VEMS_vidGET(Ctrl_bAcv_noTqCkEngRealCplm, Local_bCtrl_bAcv_noTqCkEngRealCplm);
		if (ACTIVATED == Local_bCtrl_bAcv_noTqCkEngRealCplm)
		{
			FRM_bInhF3B8PM1494_in = GDGAR_bGetFRM(FRM_FRM_INHF3B8PM1494);
			if (FRM_bInhF3B8PM1494_in == FALSE)
			{
            u8LocalN8F3B8PM1494 = (uint8)(0xFF - ISCAN_u8N8F208P003);
            ISCAN_u8N8F3B8PM1494 = (uint8)MATHSRV_udtMAX(u8LocalN8F3B8PM1494, 1);     
			}
			else
			{
				ISCAN_u8N8F3B8PM1494 = 0;
			}
			Com_SendSignal(Com_CPLMT1_COUPLE_REEL_CMM_3B8, (void*) &ISCAN_u8N8F3B8PM1494);
      }

		VEMS_vidGET(Ctrl_bAcv_noRatDrvReqCplm, Local_bCtrl_bAcv_noRatDrvReqCplm);
		if (ACTIVATED == Local_bCtrl_bAcv_noRatDrvReqCplm)
		{
			FRM_bInhF3B8PM1495_in = GDGAR_bGetFRM(FRM_FRM_INHF3B8PM1495);
			if (FRM_bInhF3B8PM1495_in == FALSE)
			{
            u8LocalN8F3B8PM1495 = (uint8)(0xFF - ISCAN_u8N8F208P002);
            ISCAN_u8N8F3B8PM1495 = (uint8)MATHSRV_udtMAX(u8LocalN8F3B8PM1495, 55);
			}
			else
			{
				ISCAN_u8N8F3B8PM1495 = 0;
			}
			Com_SendSignal(Com_CPLMT1_VOLONTE_COND_CMM_3B8, (void*) &ISCAN_u8N8F3B8PM1495);
      }

		VEMS_vidGET(Ctrl_bAcv_noTqAirDrvFilCplm, Local_bCtrl_bAcv_noTqAirDrvFilCplm);
		if (ACTIVATED == Local_bCtrl_bAcv_noTqAirDrvFilCplm)
		{
			FRM_bInhF3B8PM1496_in = GDGAR_bGetFRM(FRM_FRM_INHF3B8PM1496);
			if (FRM_bInhF3B8PM1496_in == FALSE)
			{
            u8LocalN8F3B8PM1496 = (uint8)(0xFF - ISCAN_u8N8F208P262);
            ISCAN_u8N8F3B8PM1496 = (uint8)MATHSRV_udtMAX(u8LocalN8F3B8PM1496, 1);
			}
			else
			{
				ISCAN_u8N8F3B8PM1496 = 0;
			}
			Com_SendSignal(Com_CPLMT1_CPL_POT_AP_TR_CMM_3B8, (void*) &ISCAN_u8N8F3B8PM1496);
      }

		VEMS_vidGET(Ctrl_bAcv_noTqDrvFilCplm, Local_bCtrl_bAcv_noTqDrvFilCplm);
		if (ACTIVATED == Local_bCtrl_bAcv_noTqDrvFilCplm)
		{
			FRM_bInhF3B8PM1497_in = GDGAR_bGetFRM(FRM_FRM_INHF3B8PM1497);
			if (FRM_bInhF3B8PM1497_in == FALSE)
			{
            u8LocalN8F3B8PM1497 = (uint8)(0xFF - ISCAN_u8N8F208P198);
            ISCAN_u8N8F3B8PM1497 = (uint8)MATHSRV_udtMAX(u8LocalN8F3B8PM1497, 1);
			}
			else
			{
				ISCAN_u8N8F3B8PM1497 = 0;
			}
			Com_SendSignal(Com_CPLMT1_CPL_CND_AP_TR_CMM_3B8, (void*) &ISCAN_u8N8F3B8PM1497);
      }

		VEMS_vidGET(Ctrl_CMM_3B8, Local_bCtrl_CMM_3B8);
		if (ACTIVATED == Local_bCtrl_CMM_3B8)
		{
				ISCAN_PBkind8N4F3B8FreOrStub1 = 0;
			Com_SendSignal(Com_LIBRE_4_CMM_3B8, (void*) &ISCAN_PBkind8N4F3B8FreOrStub1);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

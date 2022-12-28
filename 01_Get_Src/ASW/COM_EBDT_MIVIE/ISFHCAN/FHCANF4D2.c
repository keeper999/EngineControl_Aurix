/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF4D2.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF4D2.H"
#include "FHCANF4D2_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_4D2(void)
{
	ISCAN_u8N8F4D2PM1472 = 255;
	ISCAN_u8N8F4D2PM1473 = 255;
	ISCAN_u8N8F4D2PM1474 = 255;

	VEMS_vidSET(Ext_noWMI1, 255);
	VEMS_vidSET(Ext_noWMI2, 255);
	VEMS_vidSET(Ext_noWMI3, 255);

	Ext_bMonRunMissF4D2 = FHCAN_DISABLE;
	Ext_bMonRunShoF4D2 = FHCAN_DISABLE;

	Ext_bDgoMissF4D2 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF4D2 = FHCAN_NOT_DETECTED;
}

void FHCANF4D2_vidFrameReceived(void)
{
	boolean Local_bCtrl_WMI_BSI_4D2;
	boolean Local_bCtrl_bAcv_noWMI1;
	boolean Local_bCtrl_bAcv_noWMI2;
	boolean Local_bCtrl_bAcv_noWMI3;

	VEMS_vidGET(Ctrl_WMI_BSI_4D2, Local_bCtrl_WMI_BSI_4D2);
	if (ACTIVATED == Local_bCtrl_WMI_BSI_4D2)
	{
		ISCAN_EveRxn_4D2();
		FHCAN4D2_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF4D2)
      {
         Ext_bDgoMissF4D2 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF4D2,
                  Ext_bDgoMissF4D2,
                  Ext_bMonRunMissF4D2,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_bAcv_noWMI1, Local_bCtrl_bAcv_noWMI1);
		if (ACTIVATED == Local_bCtrl_bAcv_noWMI1)
		{
			Com_ReceiveSignal(Com_WMI_1_WMI_BSI_4D2, (void*) &ISCAN_u8N8F4D2PM1472);


			FHCANF4D2_vidUpdateSignalPM1472();
		}
		else
		{
			VEMS_vidSET(Ext_noWMI1, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noWMI2, Local_bCtrl_bAcv_noWMI2);
		if (ACTIVATED == Local_bCtrl_bAcv_noWMI2)
		{
			Com_ReceiveSignal(Com_WMI_2_WMI_BSI_4D2, (void*) &ISCAN_u8N8F4D2PM1473);


			FHCANF4D2_vidUpdateSignalPM1473();
		}
		else
		{
			VEMS_vidSET(Ext_noWMI2, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noWMI3, Local_bCtrl_bAcv_noWMI3);
		if (ACTIVATED == Local_bCtrl_bAcv_noWMI3)
		{
			Com_ReceiveSignal(Com_WMI_3_WMI_BSI_4D2, (void*) &ISCAN_u8N8F4D2PM1474);


			FHCANF4D2_vidUpdateSignalPM1474();
		}
		else
		{
			VEMS_vidSET(Ext_noWMI3, 255);

		}
	}
	else
	{
		Ext_bMonRunMissF4D2 = FHCAN_DISABLE;
		Ext_bMonRunShoF4D2 = FHCAN_DISABLE;

		Ext_bDgoMissF4D2 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF4D2 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF4D2_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF4D2_in;
	boolean Local_bCtrl_WMI_BSI_4D2;
	boolean Local_bCtrl_bAcv_noWMI1;
	boolean Local_bCtrl_bAcv_noWMI2;
	boolean Local_bCtrl_bAcv_noWMI3;
	uint8 Local_Ext_noWMI1;
	uint8 Local_Ext_noWMI2;
	uint8 Local_Ext_noWMI3;


	VEMS_vidGET(Ctrl_WMI_BSI_4D2, Local_bCtrl_WMI_BSI_4D2);
	if (ACTIVATED == Local_bCtrl_WMI_BSI_4D2)
	{
		FHCAN4D2_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF4D2)
      {
         Ext_bDgoMissF4D2 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF4D2,
                  Ext_bDgoMissF4D2,
                  Ext_bMonRunMissF4D2,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_noWMI1, 255);
		   VEMS_vidSET(Ext_noWMI2, 255);
		   VEMS_vidSET(Ext_noWMI3, 255);
      }

		FRM_bAcvRcvF4D2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4D2);

		VEMS_vidGET(Ctrl_bAcv_noWMI1, Local_bCtrl_bAcv_noWMI1);
		if (ACTIVATED == Local_bCtrl_bAcv_noWMI1)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4D2_in)
			{
		      VEMS_vidGET(Ext_noWMI1, Local_Ext_noWMI1);
		      VEMS_vidSET(Ext_noWMI1, Local_Ext_noWMI1);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noWMI2, Local_bCtrl_bAcv_noWMI2);
		if (ACTIVATED == Local_bCtrl_bAcv_noWMI2)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4D2_in)
			{
		      VEMS_vidGET(Ext_noWMI2, Local_Ext_noWMI2);
		      VEMS_vidSET(Ext_noWMI2, Local_Ext_noWMI2);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noWMI3, Local_bCtrl_bAcv_noWMI3);
		if (ACTIVATED == Local_bCtrl_bAcv_noWMI3)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4D2_in)
			{
		      VEMS_vidGET(Ext_noWMI3, Local_Ext_noWMI3);
		      VEMS_vidSET(Ext_noWMI3, Local_Ext_noWMI3);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF4D2 = FHCAN_DISABLE;
		Ext_bMonRunShoF4D2 = FHCAN_DISABLE;

		Ext_bDgoMissF4D2 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF4D2 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF4D2_vidUpdateSignalPM1472(void)
{
	boolean FRM_bAcvRcvF4D2_in;
   uint8 u8LocalExt_noWMI1;

	uint8 Local_Ext_noWMI1;

	FRM_bAcvRcvF4D2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4D2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4D2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4D2)
	   )
	{
      u8LocalExt_noWMI1 = ISCAN_u8N8F4D2PM1472;
      VEMS_vidSET(Ext_noWMI1,
                  u8LocalExt_noWMI1);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4D2_in)
      {
			VEMS_vidGET(Ext_noWMI1, Local_Ext_noWMI1);
			VEMS_vidSET(Ext_noWMI1, Local_Ext_noWMI1);
		}
	}
}

void FHCANF4D2_vidUpdateSignalPM1473(void)
{
	boolean FRM_bAcvRcvF4D2_in;
   uint8 u8LocalExt_noWMI2;

	uint8 Local_Ext_noWMI2;

	FRM_bAcvRcvF4D2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4D2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4D2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4D2)
	   )
	{
      u8LocalExt_noWMI2 = ISCAN_u8N8F4D2PM1473;
      VEMS_vidSET(Ext_noWMI2,
                  u8LocalExt_noWMI2);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4D2_in)
      {
			VEMS_vidGET(Ext_noWMI2, Local_Ext_noWMI2);
			VEMS_vidSET(Ext_noWMI2, Local_Ext_noWMI2);
		}
	}
}

void FHCANF4D2_vidUpdateSignalPM1474(void)
{
	boolean FRM_bAcvRcvF4D2_in;
   uint8 u8LocalExt_noWMI3;

	uint8 Local_Ext_noWMI3;

	FRM_bAcvRcvF4D2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4D2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4D2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4D2)
	   )
	{
      u8LocalExt_noWMI3 = ISCAN_u8N8F4D2PM1474;
      VEMS_vidSET(Ext_noWMI3,
                  u8LocalExt_noWMI3);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4D2_in)
      {
			VEMS_vidGET(Ext_noWMI3, Local_Ext_noWMI3);
			VEMS_vidSET(Ext_noWMI3, Local_Ext_noWMI3);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

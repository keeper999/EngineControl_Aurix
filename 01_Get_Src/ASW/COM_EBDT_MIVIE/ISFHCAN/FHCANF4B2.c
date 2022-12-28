/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF4B2.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF4B2.H"
#include "FHCANF4B2_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_4B2(void)
{
	ISCAN_u8N8F4B2PM1481 = 255;
	ISCAN_u8N8F4B2PM1482 = 255;
	ISCAN_u8N8F4B2PM1483 = 255;
	ISCAN_u8N8F4B2PM1484 = 255;
	ISCAN_u8N8F4B2PM1485 = 255;
	ISCAN_u8N8F4B2PM1486 = 255;
	ISCAN_u8N8F4B2PM1487 = 255;
	ISCAN_u8N8F4B2PM1488 = 255;

	VEMS_vidSET(Ext_noVIS1, 255);
	VEMS_vidSET(Ext_noVIS2, 255);
	VEMS_vidSET(Ext_noVIS3, 255);
	VEMS_vidSET(Ext_noVIS4, 255);
	VEMS_vidSET(Ext_noVIS5, 255);
	VEMS_vidSET(Ext_noVIS6, 255);
	VEMS_vidSET(Ext_noVIS7, 255);
	VEMS_vidSET(Ext_noVIS8, 255);

	Ext_bMonRunMissF4B2 = FHCAN_DISABLE;
	Ext_bMonRunShoF4B2 = FHCAN_DISABLE;

	Ext_bDgoMissF4B2 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF4B2 = FHCAN_NOT_DETECTED;
}

void FHCANF4B2_vidFrameReceived(void)
{
	boolean Local_bCtrl_VIS_BSI_4B2;
	boolean Local_bCtrl_bAcv_noVIS1;
	boolean Local_bCtrl_bAcv_noVIS2;
	boolean Local_bCtrl_bAcv_noVIS3;
	boolean Local_bCtrl_bAcv_noVIS4;
	boolean Local_bCtrl_bAcv_noVIS5;
	boolean Local_bCtrl_bAcv_noVIS6;
	boolean Local_bCtrl_bAcv_noVIS7;
	boolean Local_bCtrl_bAcv_noVIS8;

	VEMS_vidGET(Ctrl_VIS_BSI_4B2, Local_bCtrl_VIS_BSI_4B2);
	if (ACTIVATED == Local_bCtrl_VIS_BSI_4B2)
	{
		ISCAN_EveRxn_4B2();
		FHCAN4B2_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF4B2)
      {
         Ext_bDgoMissF4B2 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF4B2,
                  Ext_bDgoMissF4B2,
                  Ext_bMonRunMissF4B2,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_bAcv_noVIS1, Local_bCtrl_bAcv_noVIS1);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS1)
		{
			Com_ReceiveSignal(Com_VIS_1_VIS_BSI_4B2, (void*) &ISCAN_u8N8F4B2PM1481);


			FHCANF4B2_vidUpdateSignalPM1481();
		}
		else
		{
			VEMS_vidSET(Ext_noVIS1, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVIS2, Local_bCtrl_bAcv_noVIS2);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS2)
		{
			Com_ReceiveSignal(Com_VIS_2_VIS_BSI_4B2, (void*) &ISCAN_u8N8F4B2PM1482);


			FHCANF4B2_vidUpdateSignalPM1482();
		}
		else
		{
			VEMS_vidSET(Ext_noVIS2, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVIS3, Local_bCtrl_bAcv_noVIS3);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS3)
		{
			Com_ReceiveSignal(Com_VIS_3_VIS_BSI_4B2, (void*) &ISCAN_u8N8F4B2PM1483);


			FHCANF4B2_vidUpdateSignalPM1483();
		}
		else
		{
			VEMS_vidSET(Ext_noVIS3, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVIS4, Local_bCtrl_bAcv_noVIS4);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS4)
		{
			Com_ReceiveSignal(Com_VIS_4_VIS_BSI_4B2, (void*) &ISCAN_u8N8F4B2PM1484);


			FHCANF4B2_vidUpdateSignalPM1484();
		}
		else
		{
			VEMS_vidSET(Ext_noVIS4, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVIS5, Local_bCtrl_bAcv_noVIS5);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS5)
		{
			Com_ReceiveSignal(Com_VIS_5_VIS_BSI_4B2, (void*) &ISCAN_u8N8F4B2PM1485);


			FHCANF4B2_vidUpdateSignalPM1485();
		}
		else
		{
			VEMS_vidSET(Ext_noVIS5, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVIS6, Local_bCtrl_bAcv_noVIS6);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS6)
		{
			Com_ReceiveSignal(Com_VIS_6_VIS_BSI_4B2, (void*) &ISCAN_u8N8F4B2PM1486);


			FHCANF4B2_vidUpdateSignalPM1486();
		}
		else
		{
			VEMS_vidSET(Ext_noVIS6, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVIS7, Local_bCtrl_bAcv_noVIS7);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS7)
		{
			Com_ReceiveSignal(Com_VIS_7_VIS_BSI_4B2, (void*) &ISCAN_u8N8F4B2PM1487);


			FHCANF4B2_vidUpdateSignalPM1487();
		}
		else
		{
			VEMS_vidSET(Ext_noVIS7, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVIS8, Local_bCtrl_bAcv_noVIS8);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS8)
		{
			Com_ReceiveSignal(Com_VIS_8_VIS_BSI_4B2, (void*) &ISCAN_u8N8F4B2PM1488);


			FHCANF4B2_vidUpdateSignalPM1488();
		}
		else
		{
			VEMS_vidSET(Ext_noVIS8, 255);

		}
	}
	else
	{
		Ext_bMonRunMissF4B2 = FHCAN_DISABLE;
		Ext_bMonRunShoF4B2 = FHCAN_DISABLE;

		Ext_bDgoMissF4B2 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF4B2 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF4B2_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF4B2_in;
	boolean Local_bCtrl_VIS_BSI_4B2;
	boolean Local_bCtrl_bAcv_noVIS1;
	boolean Local_bCtrl_bAcv_noVIS2;
	boolean Local_bCtrl_bAcv_noVIS3;
	boolean Local_bCtrl_bAcv_noVIS4;
	boolean Local_bCtrl_bAcv_noVIS5;
	boolean Local_bCtrl_bAcv_noVIS6;
	boolean Local_bCtrl_bAcv_noVIS7;
	boolean Local_bCtrl_bAcv_noVIS8;
	uint8 Local_Ext_noVIS1;
	uint8 Local_Ext_noVIS2;
	uint8 Local_Ext_noVIS3;
	uint8 Local_Ext_noVIS4;
	uint8 Local_Ext_noVIS5;
	uint8 Local_Ext_noVIS6;
	uint8 Local_Ext_noVIS7;
	uint8 Local_Ext_noVIS8;


	VEMS_vidGET(Ctrl_VIS_BSI_4B2, Local_bCtrl_VIS_BSI_4B2);
	if (ACTIVATED == Local_bCtrl_VIS_BSI_4B2)
	{
		FHCAN4B2_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF4B2)
      {
         Ext_bDgoMissF4B2 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF4B2,
                  Ext_bDgoMissF4B2,
                  Ext_bMonRunMissF4B2,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_noVIS1, 255);
		   VEMS_vidSET(Ext_noVIS2, 255);
		   VEMS_vidSET(Ext_noVIS3, 255);
		   VEMS_vidSET(Ext_noVIS4, 255);
		   VEMS_vidSET(Ext_noVIS5, 255);
		   VEMS_vidSET(Ext_noVIS6, 255);
		   VEMS_vidSET(Ext_noVIS7, 255);
		   VEMS_vidSET(Ext_noVIS8, 255);
      }

		FRM_bAcvRcvF4B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4B2);

		VEMS_vidGET(Ctrl_bAcv_noVIS1, Local_bCtrl_bAcv_noVIS1);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS1)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
			{
		      VEMS_vidGET(Ext_noVIS1, Local_Ext_noVIS1);
		      VEMS_vidSET(Ext_noVIS1, Local_Ext_noVIS1);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVIS2, Local_bCtrl_bAcv_noVIS2);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS2)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
			{
		      VEMS_vidGET(Ext_noVIS2, Local_Ext_noVIS2);
		      VEMS_vidSET(Ext_noVIS2, Local_Ext_noVIS2);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVIS3, Local_bCtrl_bAcv_noVIS3);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS3)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
			{
		      VEMS_vidGET(Ext_noVIS3, Local_Ext_noVIS3);
		      VEMS_vidSET(Ext_noVIS3, Local_Ext_noVIS3);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVIS4, Local_bCtrl_bAcv_noVIS4);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS4)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
			{
		      VEMS_vidGET(Ext_noVIS4, Local_Ext_noVIS4);
		      VEMS_vidSET(Ext_noVIS4, Local_Ext_noVIS4);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVIS5, Local_bCtrl_bAcv_noVIS5);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS5)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
			{
		      VEMS_vidGET(Ext_noVIS5, Local_Ext_noVIS5);
		      VEMS_vidSET(Ext_noVIS5, Local_Ext_noVIS5);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVIS6, Local_bCtrl_bAcv_noVIS6);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS6)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
			{
		      VEMS_vidGET(Ext_noVIS6, Local_Ext_noVIS6);
		      VEMS_vidSET(Ext_noVIS6, Local_Ext_noVIS6);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVIS7, Local_bCtrl_bAcv_noVIS7);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS7)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
			{
		      VEMS_vidGET(Ext_noVIS7, Local_Ext_noVIS7);
		      VEMS_vidSET(Ext_noVIS7, Local_Ext_noVIS7);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVIS8, Local_bCtrl_bAcv_noVIS8);
		if (ACTIVATED == Local_bCtrl_bAcv_noVIS8)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
			{
		      VEMS_vidGET(Ext_noVIS8, Local_Ext_noVIS8);
		      VEMS_vidSET(Ext_noVIS8, Local_Ext_noVIS8);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF4B2 = FHCAN_DISABLE;
		Ext_bMonRunShoF4B2 = FHCAN_DISABLE;

		Ext_bDgoMissF4B2 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF4B2 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF4B2_vidUpdateSignalPM1481(void)
{
	boolean FRM_bAcvRcvF4B2_in;
   uint8 u8LocalExt_noVIS1;

	uint8 Local_Ext_noVIS1;

	FRM_bAcvRcvF4B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4B2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4B2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4B2)
	   )
	{
      u8LocalExt_noVIS1 = ISCAN_u8N8F4B2PM1481;
      VEMS_vidSET(Ext_noVIS1,
                  u8LocalExt_noVIS1);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
      {
			VEMS_vidGET(Ext_noVIS1, Local_Ext_noVIS1);
			VEMS_vidSET(Ext_noVIS1, Local_Ext_noVIS1);
		}
	}
}

void FHCANF4B2_vidUpdateSignalPM1482(void)
{
	boolean FRM_bAcvRcvF4B2_in;
   uint8 u8LocalExt_noVIS2;

	uint8 Local_Ext_noVIS2;

	FRM_bAcvRcvF4B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4B2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4B2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4B2)
	   )
	{
      u8LocalExt_noVIS2 = ISCAN_u8N8F4B2PM1482;
      VEMS_vidSET(Ext_noVIS2,
                  u8LocalExt_noVIS2);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
      {
			VEMS_vidGET(Ext_noVIS2, Local_Ext_noVIS2);
			VEMS_vidSET(Ext_noVIS2, Local_Ext_noVIS2);
		}
	}
}

void FHCANF4B2_vidUpdateSignalPM1483(void)
{
	boolean FRM_bAcvRcvF4B2_in;
   uint8 u8LocalExt_noVIS3;

	uint8 Local_Ext_noVIS3;

	FRM_bAcvRcvF4B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4B2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4B2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4B2)
	   )
	{
      u8LocalExt_noVIS3 = ISCAN_u8N8F4B2PM1483;
      VEMS_vidSET(Ext_noVIS3,
                  u8LocalExt_noVIS3);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
      {
			VEMS_vidGET(Ext_noVIS3, Local_Ext_noVIS3);
			VEMS_vidSET(Ext_noVIS3, Local_Ext_noVIS3);
		}
	}
}

void FHCANF4B2_vidUpdateSignalPM1484(void)
{
	boolean FRM_bAcvRcvF4B2_in;
   uint8 u8LocalExt_noVIS4;

	uint8 Local_Ext_noVIS4;

	FRM_bAcvRcvF4B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4B2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4B2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4B2)
	   )
	{
      u8LocalExt_noVIS4 = ISCAN_u8N8F4B2PM1484;
      VEMS_vidSET(Ext_noVIS4,
                  u8LocalExt_noVIS4);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
      {
			VEMS_vidGET(Ext_noVIS4, Local_Ext_noVIS4);
			VEMS_vidSET(Ext_noVIS4, Local_Ext_noVIS4);
		}
	}
}

void FHCANF4B2_vidUpdateSignalPM1485(void)
{
	boolean FRM_bAcvRcvF4B2_in;
   uint8 u8LocalExt_noVIS5;

	uint8 Local_Ext_noVIS5;

	FRM_bAcvRcvF4B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4B2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4B2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4B2)
	   )
	{
      u8LocalExt_noVIS5 = ISCAN_u8N8F4B2PM1485;
      VEMS_vidSET(Ext_noVIS5,
                  u8LocalExt_noVIS5);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
      {
			VEMS_vidGET(Ext_noVIS5, Local_Ext_noVIS5);
			VEMS_vidSET(Ext_noVIS5, Local_Ext_noVIS5);
		}
	}
}

void FHCANF4B2_vidUpdateSignalPM1486(void)
{
	boolean FRM_bAcvRcvF4B2_in;
   uint8 u8LocalExt_noVIS6;

	uint8 Local_Ext_noVIS6;

	FRM_bAcvRcvF4B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4B2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4B2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4B2)
	   )
	{
      u8LocalExt_noVIS6 = ISCAN_u8N8F4B2PM1486;
      VEMS_vidSET(Ext_noVIS6,
                  u8LocalExt_noVIS6);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
      {
			VEMS_vidGET(Ext_noVIS6, Local_Ext_noVIS6);
			VEMS_vidSET(Ext_noVIS6, Local_Ext_noVIS6);
		}
	}
}

void FHCANF4B2_vidUpdateSignalPM1487(void)
{
	boolean FRM_bAcvRcvF4B2_in;
   uint8 u8LocalExt_noVIS7;

	uint8 Local_Ext_noVIS7;

	FRM_bAcvRcvF4B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4B2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4B2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4B2)
	   )
	{
      u8LocalExt_noVIS7 = ISCAN_u8N8F4B2PM1487;
      VEMS_vidSET(Ext_noVIS7,
                  u8LocalExt_noVIS7);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
      {
			VEMS_vidGET(Ext_noVIS7, Local_Ext_noVIS7);
			VEMS_vidSET(Ext_noVIS7, Local_Ext_noVIS7);
		}
	}
}

void FHCANF4B2_vidUpdateSignalPM1488(void)
{
	boolean FRM_bAcvRcvF4B2_in;
   uint8 u8LocalExt_noVIS8;

	uint8 Local_Ext_noVIS8;

	FRM_bAcvRcvF4B2_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF4B2);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF4B2_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF4B2)
	   )
	{
      u8LocalExt_noVIS8 = ISCAN_u8N8F4B2PM1488;
      VEMS_vidSET(Ext_noVIS8,
                  u8LocalExt_noVIS8);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF4B2_in)
      {
			VEMS_vidGET(Ext_noVIS8, Local_Ext_noVIS8);
			VEMS_vidSET(Ext_noVIS8, Local_Ext_noVIS8);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

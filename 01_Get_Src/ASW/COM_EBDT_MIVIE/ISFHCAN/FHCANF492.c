/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF492.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF492.H"
#include "FHCANF492_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_492(void)
{
	ISCAN_u8N8F492PM1475 = 255;
	ISCAN_u8N8F492PM1476 = 255;
	ISCAN_u8N8F492PM1477 = 255;
	ISCAN_u8N8F492PM1478 = 255;
	ISCAN_u8N8F492PM1479 = 255;
	ISCAN_u8N8F492PM1480 = 255;

	VEMS_vidSET(Ext_noVDS1, 255);
	VEMS_vidSET(Ext_noVDS2, 255);
	VEMS_vidSET(Ext_noVDS3, 255);
	VEMS_vidSET(Ext_noVDS4, 255);
	VEMS_vidSET(Ext_noVDS5, 255);
	VEMS_vidSET(Ext_noVDS6, 255);

	Ext_bMonRunMissF492 = FHCAN_DISABLE;
	Ext_bMonRunShoF492 = FHCAN_DISABLE;

	Ext_bDgoMissF492 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF492 = FHCAN_NOT_DETECTED;
}

void FHCANF492_vidFrameReceived(void)
{
	boolean Local_bCtrl_VDS_BSI_492;
	boolean Local_bCtrl_bAcv_noVDS1;
	boolean Local_bCtrl_bAcv_noVDS2;
	boolean Local_bCtrl_bAcv_noVDS3;
	boolean Local_bCtrl_bAcv_noVDS4;
	boolean Local_bCtrl_bAcv_noVDS5;
	boolean Local_bCtrl_bAcv_noVDS6;

	VEMS_vidGET(Ctrl_VDS_BSI_492, Local_bCtrl_VDS_BSI_492);
	if (ACTIVATED == Local_bCtrl_VDS_BSI_492)
	{
		ISCAN_EveRxn_492();
		FHCAN492_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF492)
      {
         Ext_bDgoMissF492 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF492,
                  Ext_bDgoMissF492,
                  Ext_bMonRunMissF492,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_bAcv_noVDS1, Local_bCtrl_bAcv_noVDS1);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS1)
		{
			Com_ReceiveSignal(Com_VDS_1_VDS_BSI_492, (void*) &ISCAN_u8N8F492PM1475);


			FHCANF492_vidUpdateSignalPM1475();
		}
		else
		{
			VEMS_vidSET(Ext_noVDS1, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVDS2, Local_bCtrl_bAcv_noVDS2);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS2)
		{
			Com_ReceiveSignal(Com_VDS_2_VDS_BSI_492, (void*) &ISCAN_u8N8F492PM1476);


			FHCANF492_vidUpdateSignalPM1476();
		}
		else
		{
			VEMS_vidSET(Ext_noVDS2, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVDS3, Local_bCtrl_bAcv_noVDS3);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS3)
		{
			Com_ReceiveSignal(Com_VDS_3_VDS_BSI_492, (void*) &ISCAN_u8N8F492PM1477);


			FHCANF492_vidUpdateSignalPM1477();
		}
		else
		{
			VEMS_vidSET(Ext_noVDS3, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVDS4, Local_bCtrl_bAcv_noVDS4);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS4)
		{
			Com_ReceiveSignal(Com_VDS_4_VDS_BSI_492, (void*) &ISCAN_u8N8F492PM1478);


			FHCANF492_vidUpdateSignalPM1478();
		}
		else
		{
			VEMS_vidSET(Ext_noVDS4, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVDS5, Local_bCtrl_bAcv_noVDS5);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS5)
		{
			Com_ReceiveSignal(Com_VDS_5_VDS_BSI_492, (void*) &ISCAN_u8N8F492PM1479);


			FHCANF492_vidUpdateSignalPM1479();
		}
		else
		{
			VEMS_vidSET(Ext_noVDS5, 255);

		}
		VEMS_vidGET(Ctrl_bAcv_noVDS6, Local_bCtrl_bAcv_noVDS6);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS6)
		{
			Com_ReceiveSignal(Com_VDS_6_VDS_BSI_492, (void*) &ISCAN_u8N8F492PM1480);


			FHCANF492_vidUpdateSignalPM1480();
		}
		else
		{
			VEMS_vidSET(Ext_noVDS6, 255);

		}
	}
	else
	{
		Ext_bMonRunMissF492 = FHCAN_DISABLE;
		Ext_bMonRunShoF492 = FHCAN_DISABLE;

		Ext_bDgoMissF492 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF492 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF492_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF492_in;
	boolean Local_bCtrl_VDS_BSI_492;
	boolean Local_bCtrl_bAcv_noVDS1;
	boolean Local_bCtrl_bAcv_noVDS2;
	boolean Local_bCtrl_bAcv_noVDS3;
	boolean Local_bCtrl_bAcv_noVDS4;
	boolean Local_bCtrl_bAcv_noVDS5;
	boolean Local_bCtrl_bAcv_noVDS6;
	uint8 Local_Ext_noVDS1;
	uint8 Local_Ext_noVDS2;
	uint8 Local_Ext_noVDS3;
	uint8 Local_Ext_noVDS4;
	uint8 Local_Ext_noVDS5;
	uint8 Local_Ext_noVDS6;


	VEMS_vidGET(Ctrl_VDS_BSI_492, Local_bCtrl_VDS_BSI_492);
	if (ACTIVATED == Local_bCtrl_VDS_BSI_492)
	{
		FHCAN492_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF492)
      {
         Ext_bDgoMissF492 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF492,
                  Ext_bDgoMissF492,
                  Ext_bMonRunMissF492,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_noVDS1, 255);
		   VEMS_vidSET(Ext_noVDS2, 255);
		   VEMS_vidSET(Ext_noVDS3, 255);
		   VEMS_vidSET(Ext_noVDS4, 255);
		   VEMS_vidSET(Ext_noVDS5, 255);
		   VEMS_vidSET(Ext_noVDS6, 255);
      }

		FRM_bAcvRcvF492_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF492);

		VEMS_vidGET(Ctrl_bAcv_noVDS1, Local_bCtrl_bAcv_noVDS1);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS1)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF492_in)
			{
		      VEMS_vidGET(Ext_noVDS1, Local_Ext_noVDS1);
		      VEMS_vidSET(Ext_noVDS1, Local_Ext_noVDS1);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVDS2, Local_bCtrl_bAcv_noVDS2);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS2)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF492_in)
			{
		      VEMS_vidGET(Ext_noVDS2, Local_Ext_noVDS2);
		      VEMS_vidSET(Ext_noVDS2, Local_Ext_noVDS2);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVDS3, Local_bCtrl_bAcv_noVDS3);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS3)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF492_in)
			{
		      VEMS_vidGET(Ext_noVDS3, Local_Ext_noVDS3);
		      VEMS_vidSET(Ext_noVDS3, Local_Ext_noVDS3);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVDS4, Local_bCtrl_bAcv_noVDS4);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS4)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF492_in)
			{
		      VEMS_vidGET(Ext_noVDS4, Local_Ext_noVDS4);
		      VEMS_vidSET(Ext_noVDS4, Local_Ext_noVDS4);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVDS5, Local_bCtrl_bAcv_noVDS5);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS5)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF492_in)
			{
		      VEMS_vidGET(Ext_noVDS5, Local_Ext_noVDS5);
		      VEMS_vidSET(Ext_noVDS5, Local_Ext_noVDS5);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_noVDS6, Local_bCtrl_bAcv_noVDS6);
		if (ACTIVATED == Local_bCtrl_bAcv_noVDS6)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF492_in)
			{
		      VEMS_vidGET(Ext_noVDS6, Local_Ext_noVDS6);
		      VEMS_vidSET(Ext_noVDS6, Local_Ext_noVDS6);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF492 = FHCAN_DISABLE;
		Ext_bMonRunShoF492 = FHCAN_DISABLE;

		Ext_bDgoMissF492 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF492 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF492_vidUpdateSignalPM1475(void)
{
	boolean FRM_bAcvRcvF492_in;
   uint8 u8LocalExt_noVDS1;

	uint8 Local_Ext_noVDS1;

	FRM_bAcvRcvF492_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF492);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF492_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF492)
	   )
	{
      u8LocalExt_noVDS1 = ISCAN_u8N8F492PM1475;
      VEMS_vidSET(Ext_noVDS1,
                  u8LocalExt_noVDS1);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF492_in)
      {
			VEMS_vidGET(Ext_noVDS1, Local_Ext_noVDS1);
			VEMS_vidSET(Ext_noVDS1, Local_Ext_noVDS1);
		}
	}
}

void FHCANF492_vidUpdateSignalPM1476(void)
{
	boolean FRM_bAcvRcvF492_in;
   uint8 u8LocalExt_noVDS2;

	uint8 Local_Ext_noVDS2;

	FRM_bAcvRcvF492_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF492);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF492_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF492)
	   )
	{
      u8LocalExt_noVDS2 = ISCAN_u8N8F492PM1476;
      VEMS_vidSET(Ext_noVDS2,
                  u8LocalExt_noVDS2);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF492_in)
      {
			VEMS_vidGET(Ext_noVDS2, Local_Ext_noVDS2);
			VEMS_vidSET(Ext_noVDS2, Local_Ext_noVDS2);
		}
	}
}

void FHCANF492_vidUpdateSignalPM1477(void)
{
	boolean FRM_bAcvRcvF492_in;
   uint8 u8LocalExt_noVDS3;

	uint8 Local_Ext_noVDS3;

	FRM_bAcvRcvF492_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF492);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF492_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF492)
	   )
	{
      u8LocalExt_noVDS3 = ISCAN_u8N8F492PM1477;
      VEMS_vidSET(Ext_noVDS3,
                  u8LocalExt_noVDS3);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF492_in)
      {
			VEMS_vidGET(Ext_noVDS3, Local_Ext_noVDS3);
			VEMS_vidSET(Ext_noVDS3, Local_Ext_noVDS3);
		}
	}
}

void FHCANF492_vidUpdateSignalPM1478(void)
{
	boolean FRM_bAcvRcvF492_in;
   uint8 u8LocalExt_noVDS4;

	uint8 Local_Ext_noVDS4;

	FRM_bAcvRcvF492_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF492);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF492_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF492)
	   )
	{
      u8LocalExt_noVDS4 = ISCAN_u8N8F492PM1478;
      VEMS_vidSET(Ext_noVDS4,
                  u8LocalExt_noVDS4);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF492_in)
      {
			VEMS_vidGET(Ext_noVDS4, Local_Ext_noVDS4);
			VEMS_vidSET(Ext_noVDS4, Local_Ext_noVDS4);
		}
	}
}

void FHCANF492_vidUpdateSignalPM1479(void)
{
	boolean FRM_bAcvRcvF492_in;
   uint8 u8LocalExt_noVDS5;

	uint8 Local_Ext_noVDS5;

	FRM_bAcvRcvF492_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF492);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF492_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF492)
	   )
	{
      u8LocalExt_noVDS5 = ISCAN_u8N8F492PM1479;
      VEMS_vidSET(Ext_noVDS5,
                  u8LocalExt_noVDS5);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF492_in)
      {
			VEMS_vidGET(Ext_noVDS5, Local_Ext_noVDS5);
			VEMS_vidSET(Ext_noVDS5, Local_Ext_noVDS5);
		}
	}
}

void FHCANF492_vidUpdateSignalPM1480(void)
{
	boolean FRM_bAcvRcvF492_in;
   uint8 u8LocalExt_noVDS6;

	uint8 Local_Ext_noVDS6;

	FRM_bAcvRcvF492_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF492);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF492_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF492)
	   )
	{
      u8LocalExt_noVDS6 = ISCAN_u8N8F492PM1480;
      VEMS_vidSET(Ext_noVDS6,
                  u8LocalExt_noVDS6);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF492_in)
      {
			VEMS_vidGET(Ext_noVDS6, Local_Ext_noVDS6);
			VEMS_vidSET(Ext_noVDS6, Local_Ext_noVDS6);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

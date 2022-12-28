/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF792.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF792.H"
#include "FHCANF792_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_792(void)
{
	ISCAN_bF792PM1448 = 1;

	VEMS_vidSET(Ext_bRCDLineSec, 1);

	Ext_bMonRunMissF792 = FHCAN_DISABLE;
	Ext_bMonRunShoF792 = FHCAN_DISABLE;

	Ext_bDgoMissF792 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF792 = FHCAN_NOT_DETECTED;
}

void FHCANF792_vidFrameReceived(void)
{
	boolean Local_bCtrl_BSI_792;
	boolean Local_bCtrl_bAcv_bRCDLine;

	VEMS_vidGET(Ctrl_BSI_792, Local_bCtrl_BSI_792);
	if (ACTIVATED == Local_bCtrl_BSI_792)
	{
		ISCAN_EveRxn_792();
		FHCAN792_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF792)
      {
         Ext_bDgoMissF792 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF792,
                  Ext_bDgoMissF792,
                  Ext_bMonRunMissF792,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_bAcv_bRCDLine, Local_bCtrl_bAcv_bRCDLine);
		if (ACTIVATED == Local_bCtrl_bAcv_bRCDLine)
		{
			Com_ReceiveSignal(Com_ETAT_LIGNE_RCD_BSI_792, (void*) &ISCAN_bF792PM1448);


			FHCANF792_vidUpdateSignalPM1448();
		}
		else
		{
			VEMS_vidSET(Ext_bRCDLineSec, 1);

		}
	}
	else
	{
		Ext_bMonRunMissF792 = FHCAN_DISABLE;
		Ext_bMonRunShoF792 = FHCAN_DISABLE;

		Ext_bDgoMissF792 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF792 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF792_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF792_in;
	boolean Local_bCtrl_BSI_792;
	boolean Local_bCtrl_bAcv_bRCDLine;
	boolean Local_Ext_bRCDLineSec;


	VEMS_vidGET(Ctrl_BSI_792, Local_bCtrl_BSI_792);
	if (ACTIVATED == Local_bCtrl_BSI_792)
	{
		FHCAN792_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF792)
      {
         Ext_bDgoMissF792 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF792,
                  Ext_bDgoMissF792,
                  Ext_bMonRunMissF792,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_bRCDLineSec, 1);
      }

		FRM_bAcvRcvF792_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF792);

		VEMS_vidGET(Ctrl_bAcv_bRCDLine, Local_bCtrl_bAcv_bRCDLine);
		if (ACTIVATED == Local_bCtrl_bAcv_bRCDLine)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF792_in)
			{
		      VEMS_vidGET(Ext_bRCDLineSec, Local_Ext_bRCDLineSec);
		      VEMS_vidSET(Ext_bRCDLineSec, Local_Ext_bRCDLineSec);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF792 = FHCAN_DISABLE;
		Ext_bMonRunShoF792 = FHCAN_DISABLE;

		Ext_bDgoMissF792 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF792 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF792_vidUpdateSignalPM1448(void)
{
	boolean FRM_bAcvRcvF792_in;

	boolean Local_Ext_bRCDLineSec;

	FRM_bAcvRcvF792_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF792);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF792_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF792)
	   )
	{
      VEMS_vidSET(Ext_bRCDLineSec,
                  ISCAN_bF792PM1448);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF792_in)
      {
			VEMS_vidGET(Ext_bRCDLineSec, Local_Ext_bRCDLineSec);
			VEMS_vidSET(Ext_bRCDLineSec, Local_Ext_bRCDLineSec);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

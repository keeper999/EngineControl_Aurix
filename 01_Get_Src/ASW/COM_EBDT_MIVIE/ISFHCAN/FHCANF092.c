/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF092.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF092.H"
#include "FHCANF092_PRIVATE.H"
#include "CTRLCFG.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_092(void)
{
	ISCAN_bF092P895 = 0;
	ISCAN_bF092P928 = 0;
	ISCAN_bF092P896 = 0;

	VEMS_vidSET(Ext_bElIntgDiag, 0);
	VEMS_vidSET(Ext_bElIntgDiagMod, 0);
	VEMS_vidSET(Ext_bDelDftReq, 0);
}

void FHCANF092_vidFrameReceived(void)
{
	boolean Local_bCtrl_ELECTRON_BSI_092;
	boolean Local_bCtrl_bElIntgDiag;
	boolean Local_bCtrl_bElIntgDiagMod;
	boolean Local_bCtrl_bDelDftReq;

	VEMS_vidGET(Ctrl_ELECTRON_BSI_092, Local_bCtrl_ELECTRON_BSI_092);
	if (ACTIVATED == Local_bCtrl_ELECTRON_BSI_092)
	{
		ISCAN_EveRxn_092();
		VEMS_vidGET(Ctrl_bElIntgDiag, Local_bCtrl_bElIntgDiag);
		if (ACTIVATED == Local_bCtrl_bElIntgDiag)
		{
			Com_ReceiveSignal(Com_DIAG_INTEGRA_ELEC_ELECTRON_BSI_092, (void*) &ISCAN_bF092P895);


			FHCANF092_vidUpdateSignalP895();
		}
		else
		{
			VEMS_vidSET(Ext_bElIntgDiag, 0);

		}
		VEMS_vidGET(Ctrl_bElIntgDiagMod, Local_bCtrl_bElIntgDiagMod);
		if (ACTIVATED == Local_bCtrl_bElIntgDiagMod)
		{
			Com_ReceiveSignal(Com_MODE_DIAG_ELECTRON_BSI_092, (void*) &ISCAN_bF092P928);


			FHCANF092_vidUpdateSignalP928();
		}
		else
		{
			VEMS_vidSET(Ext_bElIntgDiagMod, 0);

		}
		VEMS_vidGET(Ctrl_bDelDftReq, Local_bCtrl_bDelDftReq);
		if (ACTIVATED == Local_bCtrl_bDelDftReq)
		{
			Com_ReceiveSignal(Com_EFFAC_DEFAUT_DIAG_ELECTRON_BSI_092, (void*) &ISCAN_bF092P896);


			FHCANF092_vidUpdateSignalP896();
		}
		else
		{
			VEMS_vidSET(Ext_bDelDftReq, 0);

		}
	}
}



void FHCANF092_vidFrameNotReceived(void)
{
	boolean Local_bCtrl_ELECTRON_BSI_092;
	boolean Local_Ext_bElIntgDiag;
	boolean Local_Ext_bElIntgDiagMod;
	boolean Local_Ext_bDelDftReq;


	VEMS_vidGET(Ctrl_ELECTRON_BSI_092, Local_bCtrl_ELECTRON_BSI_092);
	if (ACTIVATED == Local_bCtrl_ELECTRON_BSI_092)
	{
		VEMS_vidGET(Ext_bElIntgDiag, Local_Ext_bElIntgDiag);
		VEMS_vidSET(Ext_bElIntgDiag, Local_Ext_bElIntgDiag);
		VEMS_vidGET(Ext_bElIntgDiagMod, Local_Ext_bElIntgDiagMod);
		VEMS_vidSET(Ext_bElIntgDiagMod, Local_Ext_bElIntgDiagMod);
		VEMS_vidGET(Ext_bDelDftReq, Local_Ext_bDelDftReq);
		VEMS_vidSET(Ext_bDelDftReq, Local_Ext_bDelDftReq);
	}
}

void FHCANF092_vidUpdateSignalP895(void)
{

   VEMS_vidSET(Ext_bElIntgDiag,
               ISCAN_bF092P895);
}

void FHCANF092_vidUpdateSignalP928(void)
{

   VEMS_vidSET(Ext_bElIntgDiagMod,
               ISCAN_bF092P928);
}

void FHCANF092_vidUpdateSignalP896(void)
{

   VEMS_vidSET(Ext_bDelDftReq,
               ISCAN_bF092P896);
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

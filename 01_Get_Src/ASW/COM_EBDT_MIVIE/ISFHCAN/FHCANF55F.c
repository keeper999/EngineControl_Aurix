/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF55F.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF55F.H"
#include "FHCANF55F_PRIVATE.H"
#include "CTRLCFG.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_55F(void)
{
	ISCAN_u8N8F55FP876 = 0;

	VEMS_vidSET(Ext_stJDD2Answ, 0);
}

void FHCANF55F_vidFrameReceived(void)
{
	boolean Local_bCtrl_NEW_JDD_55F;
	boolean Local_bCtrl_stJDD2Answ;

	VEMS_vidGET(Ctrl_NEW_JDD_55F, Local_bCtrl_NEW_JDD_55F);
	if (ACTIVATED == Local_bCtrl_NEW_JDD_55F)
	{
		ISCAN_EveRxn_55F();
		VEMS_vidGET(Ctrl_stJDD2Answ, Local_bCtrl_stJDD2Answ);
		if (ACTIVATED == Local_bCtrl_stJDD2Answ)
		{
			Com_ReceiveSignal(Com_DATA_ACQ_JDD_BSI_2_NEW_JDD_55F, (void*) &ISCAN_u8N8F55FP876);


			FHCANF55F_vidUpdateSignalP876();
		}
		else
		{
			VEMS_vidSET(Ext_stJDD2Answ, 0);

		}
	}
}



void FHCANF55F_vidFrameNotReceived(void)
{
	boolean Local_bCtrl_NEW_JDD_55F;
	uint8 Local_Ext_stJDD2Answ;


	VEMS_vidGET(Ctrl_NEW_JDD_55F, Local_bCtrl_NEW_JDD_55F);
	if (ACTIVATED == Local_bCtrl_NEW_JDD_55F)
	{
		VEMS_vidGET(Ext_stJDD2Answ, Local_Ext_stJDD2Answ);
		VEMS_vidSET(Ext_stJDD2Answ, Local_Ext_stJDD2Answ);
	}
}

void FHCANF55F_vidUpdateSignalP876(void)
{
   uint8 u8LocalExt_stJDD2Answ;

   u8LocalExt_stJDD2Answ = ISCAN_u8N8F55FP876;
   VEMS_vidSET(Ext_stJDD2Answ,
               u8LocalExt_stJDD2Answ);
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

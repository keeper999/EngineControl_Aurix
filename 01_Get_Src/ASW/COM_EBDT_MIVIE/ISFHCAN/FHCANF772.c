/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF772.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF772.H"
#include "FHCANF772_PRIVATE.H"
#include "CTRLCFG.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_772(void)
{
	ISCAN_u8N8F772P998 = 0;

	VEMS_vidSET(Ext_stJDDAnsw, 0);
}

void FHCANF772_vidFrameReceived(void)
{
	boolean Local_bCtrl_JDD_CAN_BSI_772;
	boolean Local_bCtrl_stJDDAnsw;

	VEMS_vidGET(Ctrl_JDD_CAN_BSI_772, Local_bCtrl_JDD_CAN_BSI_772);
	if (ACTIVATED == Local_bCtrl_JDD_CAN_BSI_772)
	{
		ISCAN_EveRxn_772();
		VEMS_vidGET(Ctrl_stJDDAnsw, Local_bCtrl_stJDDAnsw);
		if (ACTIVATED == Local_bCtrl_stJDDAnsw)
		{
			Com_ReceiveSignal(Com_DATA_ACQ_JDD_BSI_JDD_CAN_BSI_772, (void*) &ISCAN_u8N8F772P998);


			FHCANF772_vidUpdateSignalP998();
		}
		else
		{
			VEMS_vidSET(Ext_stJDDAnsw, 0);

		}
	}
}



void FHCANF772_vidFrameNotReceived(void)
{
	boolean Local_bCtrl_JDD_CAN_BSI_772;
	uint8 Local_Ext_stJDDAnsw;


	VEMS_vidGET(Ctrl_JDD_CAN_BSI_772, Local_bCtrl_JDD_CAN_BSI_772);
	if (ACTIVATED == Local_bCtrl_JDD_CAN_BSI_772)
	{
		VEMS_vidGET(Ext_stJDDAnsw, Local_Ext_stJDDAnsw);
		VEMS_vidSET(Ext_stJDDAnsw, Local_Ext_stJDDAnsw);
	}
}

void FHCANF772_vidUpdateSignalP998(void)
{
   uint8 u8LocalExt_stJDDAnsw;

   u8LocalExt_stJDDAnsw = ISCAN_u8N8F772P998;
   VEMS_vidSET(Ext_stJDDAnsw,
               u8LocalExt_stJDDAnsw);
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

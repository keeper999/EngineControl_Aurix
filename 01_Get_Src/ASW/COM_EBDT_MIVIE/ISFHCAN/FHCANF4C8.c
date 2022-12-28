/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF4C8.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF4C8.H"
#include "FHCANF4C8_PRIVATE.H"
#include "CTRLCFG.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_4C8(void)
{
	ISCAN_bF4C8P223 = 0;

	VEMS_vidSET(Ext_bVehCollWarn, 0);
}

void FHCANF4C8_vidFrameReceived(void)
{
	boolean Local_bCtrl_CRASH_4C8;
	boolean Local_bCtrl_bVehCollWarn;

	VEMS_vidGET(Ctrl_CRASH_4C8, Local_bCtrl_CRASH_4C8);
	if (ACTIVATED == Local_bCtrl_CRASH_4C8)
	{
		ISCAN_EveRxn_4C8();
		VEMS_vidGET(Ctrl_bVehCollWarn, Local_bCtrl_bVehCollWarn);
		if (ACTIVATED == Local_bCtrl_bVehCollWarn)
		{
			Com_ReceiveSignal(Com_INFO_CRASH_CRASH_4C8, (void*) &ISCAN_bF4C8P223);


			FHCANF4C8_vidUpdateSignalP223();
		}
		else
		{
			VEMS_vidSET(Ext_bVehCollWarn, 0);

		}
	}
}



void FHCANF4C8_vidFrameNotReceived(void)
{
	boolean Local_bCtrl_CRASH_4C8;
	boolean Local_Ext_bVehCollWarn;


	VEMS_vidGET(Ctrl_CRASH_4C8, Local_bCtrl_CRASH_4C8);
	if (ACTIVATED == Local_bCtrl_CRASH_4C8)
	{
		VEMS_vidGET(Ext_bVehCollWarn, Local_Ext_bVehCollWarn);
		VEMS_vidSET(Ext_bVehCollWarn, Local_Ext_bVehCollWarn);
	}
}

void FHCANF4C8_vidUpdateSignalP223(void)
{

   VEMS_vidSET(Ext_bVehCollWarn,
               ISCAN_bF4C8P223);
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

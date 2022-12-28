/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF5F8.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF5F8.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_5F8(void)
{
	ISCAN_u8N8F5F8PM1380 = 0;
	ISCAN_u8N8F5F8PM1381 = 0;
	ISCAN_u8N8F5F8PM1382 = 0;
	ISCAN_u8N8F5F8PM1383 = 0;
	ISCAN_u8N8F5F8PM1384 = 0;
}


void ISCAN_vidEve_Tx_5F8(void)
{
	boolean Local_bCtrl_CMM_5F8;
	boolean Local_bCtrl_bfAcvConstFrntTra1;
	boolean Local_bCtrl_bfAcvConstReTra1;
	boolean Local_bCtrl_bfAcvConstEm1;
	boolean Local_bCtrl_bfAcvConstEm2;
	boolean Local_bCtrl_bfAcvConstEng1;
   uint8 u8LocalTqLimUH_bfAcvConstFrntTra1;
   uint8 u8LocalExt_bfAcvConstReTra1;
   uint8 u8LocalCoOptmEl_bfAcvConstEm1;
   uint8 u8LocalCoOptmEl_bfAcvConstEm2;
   uint8 u8LocalExt_bfAcvConstEng1;

	VEMS_vidGET(Ctrl_CMM_5F8, Local_bCtrl_CMM_5F8);
	if (ACTIVATED == Local_bCtrl_CMM_5F8)
	{
		VEMS_vidGET(Ctrl_bfAcvConstFrntTra1, Local_bCtrl_bfAcvConstFrntTra1);
		if (ACTIVATED == Local_bCtrl_bfAcvConstFrntTra1)
		{
               VEMS_vidGET(TqLimUH_bfAcvConstFrntTra1,
                           u8LocalTqLimUH_bfAcvConstFrntTra1);
               ISCAN_u8N8F5F8PM1380 = u8LocalTqLimUH_bfAcvConstFrntTra1;
			Com_SendSignal(Com_BESOINS_TAV_CDB_1_CMM_5F8, (void*) &ISCAN_u8N8F5F8PM1380);
      }

		VEMS_vidGET(Ctrl_bfAcvConstReTra1, Local_bCtrl_bfAcvConstReTra1);
		if (ACTIVATED == Local_bCtrl_bfAcvConstReTra1)
		{
               VEMS_vidGET(Ext_bfAcvConstReTra1,
                           u8LocalExt_bfAcvConstReTra1);
               ISCAN_u8N8F5F8PM1381 = u8LocalExt_bfAcvConstReTra1;
			Com_SendSignal(Com_BESOINS_TAR_CDB_1_CMM_5F8, (void*) &ISCAN_u8N8F5F8PM1381);
      }

		VEMS_vidGET(Ctrl_bfAcvConstEm1, Local_bCtrl_bfAcvConstEm1);
		if (ACTIVATED == Local_bCtrl_bfAcvConstEm1)
		{
               VEMS_vidGET(CoOptmEl_bfAcvConstEm1,
                           u8LocalCoOptmEl_bfAcvConstEm1);
               ISCAN_u8N8F5F8PM1382 = u8LocalCoOptmEl_bfAcvConstEm1;
			Com_SendSignal(Com_BESOINS_SEEM_CDB_1_CMM_5F8, (void*) &ISCAN_u8N8F5F8PM1382);
      }

		VEMS_vidGET(Ctrl_bfAcvConstEm2, Local_bCtrl_bfAcvConstEm2);
		if (ACTIVATED == Local_bCtrl_bfAcvConstEm2)
		{
               VEMS_vidGET(CoOptmEl_bfAcvConstEm2,
                           u8LocalCoOptmEl_bfAcvConstEm2);
               ISCAN_u8N8F5F8PM1383 = u8LocalCoOptmEl_bfAcvConstEm2;
			Com_SendSignal(Com_BESOINS_SEEM_CDB_2_CMM_5F8, (void*) &ISCAN_u8N8F5F8PM1383);
      }

		VEMS_vidGET(Ctrl_bfAcvConstEng1, Local_bCtrl_bfAcvConstEng1);
		if (ACTIVATED == Local_bCtrl_bfAcvConstEng1)
		{
               VEMS_vidGET(Ext_bfAcvConstEng1,
                           u8LocalExt_bfAcvConstEng1);
               ISCAN_u8N8F5F8PM1384 = u8LocalExt_bfAcvConstEng1;
			Com_SendSignal(Com_BESOINS_MTH_CDB_1_CMM_5F8, (void*) &ISCAN_u8N8F5F8PM1384);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

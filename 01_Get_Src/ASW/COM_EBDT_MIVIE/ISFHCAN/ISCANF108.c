/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF108.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF108.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_108(void)
{
	ISCAN_u8N8F108P076 = 0;
	ISCAN_u8N8F108P077 = 0;
	ISCAN_u8N8F108P078 = 0;
	ISCAN_u8N8F108P079 = 0;
	ISCAN_u8N8F108P080 = 0;
	ISCAN_u8N8F108P081 = 0;
	ISCAN_u8N8F108P082 = 0;
	ISCAN_u8N8F108P083 = 0;
}


void ISCAN_vidEve_Tx_108(void)
{
	boolean Local_bCtrl_CMM_108;
	boolean Local_bCtrl_noVersSys;
	boolean Local_bCtrl_noVerSysDay;
	boolean Local_bCtrl_noVersSysMnth;
	boolean Local_bCtrl_noVersSysYr;
	boolean Local_bCtrl_noVersAdp;
	boolean Local_bCtrl_noVersSw;
	boolean Local_bCtrl_noEditSw;
	boolean Local_bCtrl_noEditCal;
   uint8 u8LocalExt_noVersSys;
   uint8 u8LocalExt_noVerSysDay;
   uint8 u8LocalExt_noVersSysMnth;
   uint8 u8LocalExt_noVersSysYr;
   uint8 u8LocalExt_noVersAdp;
   uint8 u8LocalExt_noVersSw;
   uint8 u8LocalExt_noEditSw;
   uint8 u8LocalExt_noEditCal;

	VEMS_vidGET(Ctrl_CMM_108, Local_bCtrl_CMM_108);
	if (ACTIVATED == Local_bCtrl_CMM_108)
	{
		VEMS_vidGET(Ctrl_noVersSys, Local_bCtrl_noVersSys);
		if (ACTIVATED == Local_bCtrl_noVersSys)
		{
               VEMS_vidGET(Ext_noVersSys,
                           u8LocalExt_noVersSys);
               ISCAN_u8N8F108P076 = u8LocalExt_noVersSys;
			Com_SendSignal(Com_VERSION_SYSTEME_CMM_108, (void*) &ISCAN_u8N8F108P076);
      }

		VEMS_vidGET(Ctrl_noVerSysDay, Local_bCtrl_noVerSysDay);
		if (ACTIVATED == Local_bCtrl_noVerSysDay)
		{
               VEMS_vidGET(Ext_noVerSysDay,
                           u8LocalExt_noVerSysDay);
               ISCAN_u8N8F108P077 = (uint8)(MATHSRV_udtMIN(u8LocalExt_noVerSysDay,
                                                      31));
			Com_SendSignal(Com_VERS_DATE2_JOUR_CMM_108, (void*) &ISCAN_u8N8F108P077);
      }

		VEMS_vidGET(Ctrl_noVersSysMnth, Local_bCtrl_noVersSysMnth);
		if (ACTIVATED == Local_bCtrl_noVersSysMnth)
		{
               VEMS_vidGET(Ext_noVersSysMnth,
                           u8LocalExt_noVersSysMnth);
               ISCAN_u8N8F108P078 = (uint8)(MATHSRV_udtMIN(u8LocalExt_noVersSysMnth,
                                                      12));
			Com_SendSignal(Com_VERS_DATE2_MOIS_CMM_108, (void*) &ISCAN_u8N8F108P078);
      }

		VEMS_vidGET(Ctrl_noVersSysYr, Local_bCtrl_noVersSysYr);
		if (ACTIVATED == Local_bCtrl_noVersSysYr)
		{
               VEMS_vidGET(Ext_noVersSysYr,
                           u8LocalExt_noVersSysYr);
               ISCAN_u8N8F108P079 = (uint8)(MATHSRV_udtMIN(u8LocalExt_noVersSysYr,
                                                      99));
			Com_SendSignal(Com_VERS_DATE2_ANNEE_CMM_108, (void*) &ISCAN_u8N8F108P079);
      }

		VEMS_vidGET(Ctrl_noVersAdp, Local_bCtrl_noVersAdp);
		if (ACTIVATED == Local_bCtrl_noVersAdp)
		{
               VEMS_vidGET(Ext_noVersAdp,
                           u8LocalExt_noVersAdp);
               ISCAN_u8N8F108P080 = u8LocalExt_noVersAdp;
			Com_SendSignal(Com_VERSION_APPLI_CMM_108, (void*) &ISCAN_u8N8F108P080);
      }

		VEMS_vidGET(Ctrl_noVersSw, Local_bCtrl_noVersSw);
		if (ACTIVATED == Local_bCtrl_noVersSw)
		{
               VEMS_vidGET(Ext_noVersSw,
                           u8LocalExt_noVersSw);
               ISCAN_u8N8F108P081 = u8LocalExt_noVersSw;
			Com_SendSignal(Com_VERSION_SOFT_CMM_108, (void*) &ISCAN_u8N8F108P081);
      }

		VEMS_vidGET(Ctrl_noEditSw, Local_bCtrl_noEditSw);
		if (ACTIVATED == Local_bCtrl_noEditSw)
		{
               VEMS_vidGET(Ext_noEditSw,
                           u8LocalExt_noEditSw);
               ISCAN_u8N8F108P082 = u8LocalExt_noEditSw;
			Com_SendSignal(Com_EDITION_SOFT_CMM_108, (void*) &ISCAN_u8N8F108P082);
      }

		VEMS_vidGET(Ctrl_noEditCal, Local_bCtrl_noEditCal);
		if (ACTIVATED == Local_bCtrl_noEditCal)
		{
               VEMS_vidGET(Ext_noEditCal,
                           u8LocalExt_noEditCal);
               ISCAN_u8N8F108P083 = u8LocalExt_noEditCal;
			Com_SendSignal(Com_EDITION_CALIB_CMM_108, (void*) &ISCAN_u8N8F108P083);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

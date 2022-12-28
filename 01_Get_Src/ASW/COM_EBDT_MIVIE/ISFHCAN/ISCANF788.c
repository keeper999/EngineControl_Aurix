/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF788.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF788.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_788(void)
{
	ISCAN_u8N8F788P073 = 0;
	ISCAN_u32N32F788P071 = 0;
	ISCAN_u8N4F788P242 = 6;
	ISCAN_u16N16F788P284 = 0;
	ISCAN_PBkind8N4F788FreOrStub1 = 0;
}


void ISCAN_vidEve_Tx_788(void)
{
	boolean Local_bCtrl_CMM_788;
	boolean Local_bCtrl_noSupvDTC;
	boolean Local_bCtrl_stECUMiss;
	boolean Local_bCtrl_stSt;
	boolean Local_bCtrl_bfSlavePtlWkuSt;
   uint8 u8LocalExt_noSupvDTC;
   uint32 u32LocalExt_stECUMiss;
   uint8 u8LocalExt_stSt;
   uint16 u16LocalExt_bfSlavePtlWkuSt;

	VEMS_vidGET(Ctrl_CMM_788, Local_bCtrl_CMM_788);
	if (ACTIVATED == Local_bCtrl_CMM_788)
	{
		VEMS_vidGET(Ctrl_noSupvDTC, Local_bCtrl_noSupvDTC);
		if (ACTIVATED == Local_bCtrl_noSupvDTC)
		{
               VEMS_vidGET(Ext_noSupvDTC,
                           u8LocalExt_noSupvDTC);
               ISCAN_u8N8F788P073 = u8LocalExt_noSupvDTC;
			Com_SendSignal(Com_CODE_DEFAUT_CMM_788, (void*) &ISCAN_u8N8F788P073);
      }

		VEMS_vidGET(Ctrl_stECUMiss, Local_bCtrl_stECUMiss);
		if (ACTIVATED == Local_bCtrl_stECUMiss)
		{
               VEMS_vidGET(Ext_stECUMiss,
                           u32LocalExt_stECUMiss);
               ISCAN_u32N32F788P071 = u32LocalExt_stECUMiss;
			Com_SendSignal(Com_STATUS_CONFABSENT_CMM_788, (void*) &ISCAN_u32N32F788P071);
      }

		VEMS_vidGET(Ctrl_stSt, Local_bCtrl_stSt);
		if (ACTIVATED == Local_bCtrl_stSt)
		{
               VEMS_vidGET(Ext_stSt,
                           u8LocalExt_stSt);
               ISCAN_u8N4F788P242 = (uint8)(MATHSRV_udtMIN(u8LocalExt_stSt,
                                                      15));
			Com_SendSignal(Com_ETAT_ELECTR_UCE_CMM_788, (void*) &ISCAN_u8N4F788P242);
      }

		VEMS_vidGET(Ctrl_bfSlavePtlWkuSt, Local_bCtrl_bfSlavePtlWkuSt);
		if (ACTIVATED == Local_bCtrl_bfSlavePtlWkuSt)
		{
               VEMS_vidGET(Ext_bfSlavePtlWkuSt,
                           u16LocalExt_bfSlavePtlWkuSt);
               ISCAN_u16N16F788P284 = u16LocalExt_bfSlavePtlWkuSt;
			Com_SendSignal(Com_STATUS_REVEIL_PARTIEL_GMP_CMM_788, (void*) &ISCAN_u16N16F788P284);
      }

		VEMS_vidGET(Ctrl_CMM_788, Local_bCtrl_CMM_788);
		if (ACTIVATED == Local_bCtrl_CMM_788)
		{
				ISCAN_PBkind8N4F788FreOrStub1 = 0;
			Com_SendSignal(Com_LIBRE_4_CMM_788, (void*) &ISCAN_PBkind8N4F788FreOrStub1);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

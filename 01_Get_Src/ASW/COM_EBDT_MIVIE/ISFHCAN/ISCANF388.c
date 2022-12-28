/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF388.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF388.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_388(void)
{
	ISCAN_u16N16F388P060 = 65535;
	ISCAN_u16N16F388P062 = 0;
	ISCAN_u8N8F388P066 = 255;
	ISCAN_u16N16F388P206 = 65535;
}


void ISCAN_vidEve_Tx_388(void)
{
	boolean Local_bCtrl_CMM_388;
	boolean Local_bCtrl_spdFilGearSen;
	boolean Local_bCtrl_dstCntGearSen;
	boolean Local_bCtrl_aLgtGearSen;
	boolean Local_bCtrl_spdRawGearSen;
	boolean FRM_bInhF388P060_in;
	boolean FRM_bInhF388P066_in;
	boolean FRM_bInhF388P206_in;
   uint16 u16LocalEng_spdVeh;
   uint32 u32LocalIscanCMM_388;
   uint16 u16LocalDistance_parcourue;
   uint8 u8LocalAcceleration_vehicule;
   uint16 u16LocalVitesse_vehicule_fil_precise;

	VEMS_vidGET(Ctrl_CMM_388, Local_bCtrl_CMM_388);
	if (ACTIVATED == Local_bCtrl_CMM_388)
	{
		VEMS_vidGET(Ctrl_spdFilGearSen, Local_bCtrl_spdFilGearSen);
		if (ACTIVATED == Local_bCtrl_spdFilGearSen)
		{
			FRM_bInhF388P060_in = GDGAR_bGetFRM(FRM_FRM_INHF388P060);
			if (FRM_bInhF388P060_in == FALSE)
			{
               VEMS_vidGET(Eng_spdVeh,
                           u16LocalEng_spdVeh);
               u32LocalIscanCMM_388 = (uint32)(((25 * u16LocalEng_spdVeh) / 32));
               ISCAN_u16N16F388P060 = (uint16)(MATHSRV_udtMIN(u32LocalIscanCMM_388,
                                                      65534));
			}
			else
			{
				ISCAN_u16N16F388P060 = 65535;
			}
			Com_SendSignal(Com_VITESSE_VEHICULE_BV_CMM_388, (void*) &ISCAN_u16N16F388P060);
      }

		VEMS_vidGET(Ctrl_dstCntGearSen, Local_bCtrl_dstCntGearSen);
		if (ACTIVATED == Local_bCtrl_dstCntGearSen)
		{
               VEMS_vidGET(Distance_parcourue,
                           u16LocalDistance_parcourue);
               ISCAN_u16N16F388P062 = u16LocalDistance_parcourue;
			Com_SendSignal(Com_DISTANCE_BV_CMM_388, (void*) &ISCAN_u16N16F388P062);
      }

		VEMS_vidGET(Ctrl_aLgtGearSen, Local_bCtrl_aLgtGearSen);
		if (ACTIVATED == Local_bCtrl_aLgtGearSen)
		{
			FRM_bInhF388P066_in = GDGAR_bGetFRM(FRM_FRM_INHF388P066);
			if (FRM_bInhF388P066_in == FALSE)
			{
               VEMS_vidGET(Acceleration_vehicule,
                           u8LocalAcceleration_vehicule);
               ISCAN_u8N8F388P066 = (uint8)(MATHSRV_udtMIN(u8LocalAcceleration_vehicule,
                                                      254));
			}
			else
			{
				ISCAN_u8N8F388P066 = 255;
			}
			Com_SendSignal(Com_ACCEL_LONGI_BV_CMM_388, (void*) &ISCAN_u8N8F388P066);
      }

		VEMS_vidGET(Ctrl_spdRawGearSen, Local_bCtrl_spdRawGearSen);
		if (ACTIVATED == Local_bCtrl_spdRawGearSen)
		{
			FRM_bInhF388P206_in = GDGAR_bGetFRM(FRM_FRM_INHF388P206);
			if (FRM_bInhF388P206_in == FALSE)
			{
               VEMS_vidGET(Vitesse_vehicule_fil_precise,
                           u16LocalVitesse_vehicule_fil_precise);
               u32LocalIscanCMM_388 = (uint32)(((25 * u16LocalVitesse_vehicule_fil_precise) / 64));
               ISCAN_u16N16F388P206 = (uint16)(MATHSRV_udtMIN(u32LocalIscanCMM_388,
                                                      65534));
			}
			else
			{
				ISCAN_u16N16F388P206 = 65535;
			}
			Com_SendSignal(Com_VITESSE_VEHICULE_BV_NF_CMM_388, (void*) &ISCAN_u16N16F388P206);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

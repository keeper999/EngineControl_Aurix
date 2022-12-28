/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF588.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF588.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_588(void)
{
	ISCAN_u8N8F588P275 = 254;
	ISCAN_PBkind8N8F588FreOrStub1 = 0;
	ISCAN_bF588P423 = 0;
	ISCAN_bF588P424 = 0;
	ISCAN_bF588FreOrStub2 = 0;
	ISCAN_bF588FreOrStub3 = 0;
	ISCAN_bF588FreOrStub4 = 0;
	ISCAN_bF588FreOrStub5 = 0;
	ISCAN_bF588FreOrStub6 = 0;
	ISCAN_bF588P278 = 0;
	ISCAN_PBkind8N8F588FreOrStub7 = 0;
	ISCAN_u8N8F588P373 = 0;
	ISCAN_bF588P288 = 0;
	ISCAN_u8N5F588P338 = 30;
	ISCAN_u8N2F588P414 = 1;
	ISCAN_bF588FreOrStub8 = 0;
	ISCAN_bF588P422 = 0;
	ISCAN_bF588FreOrStub9 = 0;
	ISCAN_bF588FreOrStub10 = 0;
	ISCAN_u8N4F588P366 = 0;
	ISCAN_u8N3F588P357 = 0;
	ISCAN_u8N2F588P358 = 0;
	ISCAN_u8N3F588P359 = 0;
}


void ISCAN_vidEve_Tx_588(void)
{
	boolean Local_bCtrl_CMM_588;
	boolean Local_bCtrl_uEngOilLvl;
	boolean Local_bCtrl_bInfoRdy;
	boolean Local_bCtrl_bInfoAcvCluPed;
	boolean Local_bCtrl_bPresOilWarn;
	boolean Local_bCtrl_rtqOBD;
	boolean Local_bCtrl_bAcv_bAcvSftyWarn;
	boolean Local_bCtrl_pAirExtMes;
	boolean Local_bCtrl_stSTTLightAcv;
	boolean Local_bCtrl_bRecNotStop;
	boolean Local_bCtrl_stEngOpm;
	boolean Local_bCtrl_noTarGear;
	boolean Local_bCtrl_stGearShiftReq;
	boolean Local_bCtrl_stGSIEna;
	boolean FRM_bInhF588P275_in;
	boolean FRM_bInhF588P338_in;
   uint16 u16LocalExt_uEngOilLvl;
   uint32 u32LocalIscanCMM_588;
   boolean bLocalCoPtUH_bInfoRdy;
   boolean bLocalCoPtUH_bInfoAcvCluPed;
   boolean bLocalExt_bPresOilWarn;
   uint8 u8LocalSrv_Engine_load_Pid04;
   boolean bLocalECU_bAcvSftyWarn;
   uint16 u16LocalExt_pAirExtMes;
   sint32 s32LocalIscanCMM_588;
   uint8 u8LocalCoPtUH_stSTTLightAcv;
   boolean bLocalCoPtUH_bRecNotStop;
   uint8 u8LocalREOM_stEngOpm;
   uint8 u8LocalGSI3_noTarGear;
   uint8 u8LocalGSI3_stGearShiftReq;
   boolean bLocalGSI3_stGSIEna;

	VEMS_vidGET(Ctrl_CMM_588, Local_bCtrl_CMM_588);
	if (ACTIVATED == Local_bCtrl_CMM_588)
	{
		VEMS_vidGET(Ctrl_uEngOilLvl, Local_bCtrl_uEngOilLvl);
		if (ACTIVATED == Local_bCtrl_uEngOilLvl)
		{
			FRM_bInhF588P275_in = GDGAR_bGetFRM(FRM_FRM_INHF588P275);
			if (FRM_bInhF588P275_in == FALSE)
			{
               VEMS_vidGET(Ext_uEngOilLvl,
                           u16LocalExt_uEngOilLvl);
               u32LocalIscanCMM_588 = (uint32)(((625 * u16LocalExt_uEngOilLvl) / 1536));
               ISCAN_u8N8F588P275 = (uint8)(MATHSRV_udtMIN(u32LocalIscanCMM_588,
                                                      250));
			}
			else
			{
				ISCAN_u8N8F588P275 = 255;
			}
			Com_SendSignal(Com_NIV_HUILE_MOT_CMM_588, (void*) &ISCAN_u8N8F588P275);
      }

		VEMS_vidGET(Ctrl_CMM_588, Local_bCtrl_CMM_588);
		if (ACTIVATED == Local_bCtrl_CMM_588)
		{
				ISCAN_PBkind8N8F588FreOrStub1 = 255;
			Com_SendSignal(Com_VOL_ADDITIF_A_AJOUTER_CMM_588, (void*) &ISCAN_PBkind8N8F588FreOrStub1);
      }

		VEMS_vidGET(Ctrl_bInfoRdy, Local_bCtrl_bInfoRdy);
		if (ACTIVATED == Local_bCtrl_bInfoRdy)
		{
               VEMS_vidGET(CoPtUH_bInfoRdy,
                           bLocalCoPtUH_bInfoRdy);
               ISCAN_bF588P423 = bLocalCoPtUH_bInfoRdy;
			Com_SendSignal(Com_IHM_CLIGNO_ECO_CMM_588, (void*) &ISCAN_bF588P423);
      }

		VEMS_vidGET(Ctrl_bInfoAcvCluPed, Local_bCtrl_bInfoAcvCluPed);
		if (ACTIVATED == Local_bCtrl_bInfoAcvCluPed)
		{
               VEMS_vidGET(CoPtUH_bInfoAcvCluPed,
                           bLocalCoPtUH_bInfoAcvCluPed);
               ISCAN_bF588P424 = bLocalCoPtUH_bInfoAcvCluPed;
			Com_SendSignal(Com_IHM_DMD_DEBRAYAGE_CMM_588, (void*) &ISCAN_bF588P424);
      }

		VEMS_vidGET(Ctrl_CMM_588, Local_bCtrl_CMM_588);
		if (ACTIVATED == Local_bCtrl_CMM_588)
		{
				ISCAN_bF588FreOrStub2 = 0;
			Com_SendSignal(Com_DDE_ALLUM_LED_ORANGE_CMM_588, (void*) &ISCAN_bF588FreOrStub2);
      }

		VEMS_vidGET(Ctrl_CMM_588, Local_bCtrl_CMM_588);
		if (ACTIVATED == Local_bCtrl_CMM_588)
		{
				ISCAN_bF588FreOrStub3 = 0;
			Com_SendSignal(Com_DDE_ALLUM_LED_ROUGE_CMM_588, (void*) &ISCAN_bF588FreOrStub3);
      }

		VEMS_vidGET(Ctrl_CMM_588, Local_bCtrl_CMM_588);
		if (ACTIVATED == Local_bCtrl_CMM_588)
		{
				ISCAN_bF588FreOrStub4 = 0;
			Com_SendSignal(Com_ETAT_CMDE_POMPE_EAU_CMM_588, (void*) &ISCAN_bF588FreOrStub4);
      }

		VEMS_vidGET(Ctrl_CMM_588, Local_bCtrl_CMM_588);
		if (ACTIVATED == Local_bCtrl_CMM_588)
		{
				ISCAN_bF588FreOrStub5 = 0;
			Com_SendSignal(Com_CDE_PUISS_VVT_CMM_588, (void*) &ISCAN_bF588FreOrStub5);
      }

		VEMS_vidGET(Ctrl_CMM_588, Local_bCtrl_CMM_588);
		if (ACTIVATED == Local_bCtrl_CMM_588)
		{
				ISCAN_bF588FreOrStub6 = 0;
			Com_SendSignal(Com_DMD_NEUTRE_GSI_CMM_588, (void*) &ISCAN_bF588FreOrStub6);
      }

		VEMS_vidGET(Ctrl_bPresOilWarn, Local_bCtrl_bPresOilWarn);
		if (ACTIVATED == Local_bCtrl_bPresOilWarn)
		{
               VEMS_vidGET(Ext_bPresOilWarn,
                           bLocalExt_bPresOilWarn);
               ISCAN_bF588P278 = bLocalExt_bPresOilWarn;
			Com_SendSignal(Com_ALRT_PRESS_HUILE_CMM_588, (void*) &ISCAN_bF588P278);
      }

		VEMS_vidGET(Ctrl_CMM_588, Local_bCtrl_CMM_588);
		if (ACTIVATED == Local_bCtrl_CMM_588)
		{
				ISCAN_PBkind8N8F588FreOrStub7 = 0;
			Com_SendSignal(Com_PSEUDO_CONSO_CARBURANT_CMM_588, (void*) &ISCAN_PBkind8N8F588FreOrStub7);
      }

		VEMS_vidGET(Ctrl_rtqOBD, Local_bCtrl_rtqOBD);
		if (ACTIVATED == Local_bCtrl_rtqOBD)
		{
               VEMS_vidGET(Srv_Engine_load_Pid04,
                           u8LocalSrv_Engine_load_Pid04);
               ISCAN_u8N8F588P373 = u8LocalSrv_Engine_load_Pid04;
			Com_SendSignal(Com_VALEUR_CHARGE_CALCULEE_CMM_588, (void*) &ISCAN_u8N8F588P373);
      }

		VEMS_vidGET(Ctrl_bAcv_bAcvSftyWarn, Local_bCtrl_bAcv_bAcvSftyWarn);
		if (ACTIVATED == Local_bCtrl_bAcv_bAcvSftyWarn)
		{
               VEMS_vidGET(ECU_bAcvSftyWarn,
                           bLocalECU_bAcvSftyWarn);
               ISCAN_bF588P288 = bLocalECU_bAcvSftyWarn;
			Com_SendSignal(Com_DEFAUT_ECM_SFT_CMM_588, (void*) &ISCAN_bF588P288);
      }

		VEMS_vidGET(Ctrl_pAirExtMes, Local_bCtrl_pAirExtMes);
		if (ACTIVATED == Local_bCtrl_pAirExtMes)
		{
			FRM_bInhF588P338_in = GDGAR_bGetFRM(FRM_FRM_INHF588P338);
			if (FRM_bInhF588P338_in == FALSE)
			{
               VEMS_vidGET(Ext_pAirExtMes,
                           u16LocalExt_pAirExtMes);
               s32LocalIscanCMM_588 = (sint32)(((u16LocalExt_pAirExtMes) / 15) - (137/3));
               ISCAN_u8N5F588P338 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_588,
                                                        0,
                                                        29));
			}
			else
			{
				ISCAN_u8N5F588P338 = 31;
			}
			Com_SendSignal(Com_PRESSION_ATMO_CMM_588, (void*) &ISCAN_u8N5F588P338);
      }

		VEMS_vidGET(Ctrl_stSTTLightAcv, Local_bCtrl_stSTTLightAcv);
		if (ACTIVATED == Local_bCtrl_stSTTLightAcv)
		{
               VEMS_vidGET(CoPtUH_stSTTLightAcv,
                           u8LocalCoPtUH_stSTTLightAcv);
               ISCAN_u8N2F588P414 = (uint8)(MATHSRV_udtMIN(u8LocalCoPtUH_stSTTLightAcv,
                                                      3));
			Com_SendSignal(Com_ETAT_FONCTION_STT_CMM_588, (void*) &ISCAN_u8N2F588P414);
      }

		VEMS_vidGET(Ctrl_CMM_588, Local_bCtrl_CMM_588);
		if (ACTIVATED == Local_bCtrl_CMM_588)
		{
				ISCAN_bF588FreOrStub8 = 0;
			Com_SendSignal(Com_ETAT_READ_CODE_CMM_CMM_588, (void*) &ISCAN_bF588FreOrStub8);
      }

		VEMS_vidGET(Ctrl_bRecNotStop, Local_bCtrl_bRecNotStop);
		if (ACTIVATED == Local_bCtrl_bRecNotStop)
		{
               VEMS_vidGET(CoPtUH_bRecNotStop,
                           bLocalCoPtUH_bRecNotStop);
               ISCAN_bF588P422 = bLocalCoPtUH_bRecNotStop;
			Com_SendSignal(Com_SYNCHRO_STOP_DIFF_CMM_588, (void*) &ISCAN_bF588P422);
      }

		VEMS_vidGET(Ctrl_CMM_588, Local_bCtrl_CMM_588);
		if (ACTIVATED == Local_bCtrl_CMM_588)
		{
				ISCAN_bF588FreOrStub9 = 0;
			Com_SendSignal(Com_SOC_DMTC_CMM_588, (void*) &ISCAN_bF588FreOrStub9);
      }

		VEMS_vidGET(Ctrl_CMM_588, Local_bCtrl_CMM_588);
		if (ACTIVATED == Local_bCtrl_CMM_588)
		{
				ISCAN_bF588FreOrStub10 = 0;
			Com_SendSignal(Com_AUTOR_PILT_POMPE_ADD_CMM_588, (void*) &ISCAN_bF588FreOrStub10);
      }

		VEMS_vidGET(Ctrl_stEngOpm, Local_bCtrl_stEngOpm);
		if (ACTIVATED == Local_bCtrl_stEngOpm)
		{
               VEMS_vidGET(REOM_stEngOpm,
                           u8LocalREOM_stEngOpm);
               ISCAN_u8N4F588P366 = (uint8)(MATHSRV_udtMIN(u8LocalREOM_stEngOpm,
                                                      15));
			Com_SendSignal(Com_MODE_FONC_MOT_CMM_588, (void*) &ISCAN_u8N4F588P366);
      }

		VEMS_vidGET(Ctrl_noTarGear, Local_bCtrl_noTarGear);
		if (ACTIVATED == Local_bCtrl_noTarGear)
		{
               VEMS_vidGET(GSI3_noTarGear,
                           u8LocalGSI3_noTarGear);
               ISCAN_u8N3F588P357 = (uint8)(MATHSRV_udtMIN(u8LocalGSI3_noTarGear,
                                                      7));
			Com_SendSignal(Com_RAP_CIBLE_TRANSMIS_CMM_588, (void*) &ISCAN_u8N3F588P357);
      }

		VEMS_vidGET(Ctrl_stGearShiftReq, Local_bCtrl_stGearShiftReq);
		if (ACTIVATED == Local_bCtrl_stGearShiftReq)
		{
               VEMS_vidGET(GSI3_stGearShiftReq,
                           u8LocalGSI3_stGearShiftReq);
               ISCAN_u8N2F588P358 = (uint8)(MATHSRV_udtMIN(u8LocalGSI3_stGearShiftReq,
                                                      3));
			Com_SendSignal(Com_SENS_CHGMT_RAP_CMM_588, (void*) &ISCAN_u8N2F588P358);
      }

		VEMS_vidGET(Ctrl_stGSIEna, Local_bCtrl_stGSIEna);
		if (ACTIVATED == Local_bCtrl_stGSIEna)
		{
               VEMS_vidGET(GSI3_stGSIEna,
                           bLocalGSI3_stGSIEna);
               ISCAN_u8N3F588P359 = (uint8)(MATHSRV_udtMIN(bLocalGSI3_stGSIEna,
                                                      7));
			Com_SendSignal(Com_SITUATION_VIE_CMM_588, (void*) &ISCAN_u8N3F588P359);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

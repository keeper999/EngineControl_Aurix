/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 08/10/2014 15:03:49 */
/* File: ISCANF608.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF608.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_608(void)
{
	ISCAN_u8N8F608P861 = 0;
	ISCAN_u8N8F608P874 = 0;
	ISCAN_u8N8F608P952 = 0;
	ISCAN_u8N8F608P943 = 0;
	ISCAN_u8N8F608P877 = 0;
	ISCAN_u8N8F608P864 = 0;
	ISCAN_u8N8F608P944 = 0;
	ISCAN_u8N8F608P875 = 0;
	ISCAN_u8N8F608P862 = 0;
	ISCAN_u8N8F608P958 = 0;
	ISCAN_PBkind8N8F608FreOrStub1 = 0;
	ISCAN_PBkind8N8F608FreOrStub2 = 0;
	ISCAN_u8N8F608P885 = 0;
	ISCAN_u8N8F608P912 = 0;
	ISCAN_PBkind8N8F608FreOrStub3 = 0;
	ISCAN_u8N8F608P886 = 0;
	ISCAN_PBkind8N8F608FreOrStub4 = 0;
	ISCAN_u8N8F608P926 = 0;
	ISCAN_u8N8F608P937 = 0;
	ISCAN_u8N8F608P373 = 0;
	ISCAN_u8N8F608P936 = 0;
	ISCAN_u8N8F608P938 = 0;
}


void ISCAN_vidEve_Tx_608(void)
{
	boolean Local_bCtrl_CMM_608;
	boolean Local_bCtrl_tCoMes;
	boolean Local_bCtrl_nEngAvr;
	boolean Local_bCtrl_stFuSpdCorbank1;
	boolean Local_bCtrl_stFuSlowCorbank1;
	boolean Local_bCtrl_spdVeh;
	boolean Local_bCtrl_mfAirMes;
	boolean Local_bCtrl_bAcv_stPwrSys2;
	boolean Local_bCtrl_bFuTnkEmp;
	boolean Local_bCtrl_rtqOBD;
	boolean Local_bCtrl_pDsEGRVlvMes;
	boolean FRM_bInhF608P958_in;
   sint16 s16LocalExt_tCoMes;
   uint16 u16LocalExt_nEngAvr;
   uint16 u16LocalIscanCMM_608;
   uint8 u8LocalSrv_Lfbk_Pid06;
   sint16 s16LocalIscanCMM_608;
   uint8 u8LocalSrv_Diag_trim_Pid07;
   uint8 u8LocalExt_spdVeh;
   uint8 u8LocalExt_mfAirMes;
   uint8 u8LocalSrv_Fuel_System_Pid03;
   boolean bLocalExt_bFuTnkEmp;
   uint16 u16LocalExt_pFuMes;
   uint8 u8LocalSrv_Engine_load_Pid04;
   sint16 s16LocalExt_pDsThrMes;

	VEMS_vidGET(Ctrl_CMM_608, Local_bCtrl_CMM_608);
	if (ACTIVATED == Local_bCtrl_CMM_608)
	{
		if (ISCAN_u8N8F608P861 < 3)
      {
         ISCAN_u8N8F608P861 = (uint8)(ISCAN_u8N8F608P861 + 1);
      }
      else
      {
         ISCAN_u8N8F608P861 = 1;
      }
      Com_SendSignal(Com_CODE_LID_CMM_608, (void*) &ISCAN_u8N8F608P861);
      
      VEMS_vidGET(Ctrl_CMM_608, Local_bCtrl_CMM_608);
		if (ACTIVATED == Local_bCtrl_CMM_608)
		{
			if (ISCAN_u8N8F608P861 == 0x01)
         {
   			Com_SendSignal(Com_DATA_A_EOBD_PID_00_CMM_608, (void*) &ISCAN_u8N8F608P874);
         }
      }

		VEMS_vidGET(Ctrl_tCoMes, Local_bCtrl_tCoMes);
		if (ACTIVATED == Local_bCtrl_tCoMes)
		{
			if (ISCAN_u8N8F608P861 == 0x02)
         {
               VEMS_vidGET(Ext_tCoMes,
                           s16LocalExt_tCoMes);
               ISCAN_u8N8F608P952 = (uint8)(MATHSRV_udtCLAMP(s16LocalExt_tCoMes,
                                                        0,
                                                        255));
   			Com_SendSignal(Com_TEMP_LIQUIDE_REFROI_CMM_608, (void*) &ISCAN_u8N8F608P952);
         }
      }

		VEMS_vidGET(Ctrl_nEngAvr, Local_bCtrl_nEngAvr);
		if (ACTIVATED == Local_bCtrl_nEngAvr)
		{
			if (ISCAN_u8N8F608P861 == 0x03)
         {
               VEMS_vidGET(Ext_nEngAvr,
                           u16LocalExt_nEngAvr);
               u16LocalIscanCMM_608 = (uint16)(((u16LocalExt_nEngAvr) / 4));
               ISCAN_u8N8F608P943 = (uint8)(MATHSRV_udtMIN(u16LocalIscanCMM_608,
                                                      255));
   			Com_SendSignal(Com_REGIME_MOTEUR_POIDS_FAIBLE_CMM_608, (void*) &ISCAN_u8N8F608P943);
         }
      }

		VEMS_vidGET(Ctrl_CMM_608, Local_bCtrl_CMM_608);
		if (ACTIVATED == Local_bCtrl_CMM_608)
		{
			if (ISCAN_u8N8F608P861 == 0x01)
         {
   			Com_SendSignal(Com_DATA_B_EOBD_CMM_CMM_608, (void*) &ISCAN_u8N8F608P877);
         }
      }

		VEMS_vidGET(Ctrl_stFuSpdCorbank1, Local_bCtrl_stFuSpdCorbank1);
		if (ACTIVATED == Local_bCtrl_stFuSpdCorbank1)
		{
			if (ISCAN_u8N8F608P861 == 0x02)
         {
               VEMS_vidGET(Srv_Lfbk_Pid06,
                           u8LocalSrv_Lfbk_Pid06);
               s16LocalIscanCMM_608 = (sint16)(((25 * u8LocalSrv_Lfbk_Pid06) / 32) - 100);
               ISCAN_u8N8F608P864 = (uint8)(MATHSRV_udtCLAMP(s16LocalIscanCMM_608,
                                                        0,
                                                        255));
   			Com_SendSignal(Com_CORREC_RAP_CARBUR_RANG_1_CMM_608, (void*) &ISCAN_u8N8F608P864);
         }
      }

		VEMS_vidGET(Ctrl_nEngAvr, Local_bCtrl_nEngAvr);
		if (ACTIVATED == Local_bCtrl_nEngAvr)
		{
			if (ISCAN_u8N8F608P861 == 0x03)
         {
               VEMS_vidGET(Ext_nEngAvr,
                           u16LocalExt_nEngAvr);
               u16LocalIscanCMM_608 = (uint16)(((u16LocalExt_nEngAvr) / 4));
               ISCAN_u8N8F608P944 = (uint8)(MATHSRV_udtMIN(u16LocalIscanCMM_608,
                                                      255));
   			Com_SendSignal(Com_REGIME_MOTEUR_POIDS_FORT_CMM_608, (void*) &ISCAN_u8N8F608P944);
         }
      }

		VEMS_vidGET(Ctrl_CMM_608, Local_bCtrl_CMM_608);
		if (ACTIVATED == Local_bCtrl_CMM_608)
		{
			if (ISCAN_u8N8F608P861 == 0x01)
         {
   			Com_SendSignal(Com_DATA_A_EOBD_PID_20_CMM_608, (void*) &ISCAN_u8N8F608P875);
         }
      }

		VEMS_vidGET(Ctrl_stFuSlowCorbank1, Local_bCtrl_stFuSlowCorbank1);
		if (ACTIVATED == Local_bCtrl_stFuSlowCorbank1)
		{
			if (ISCAN_u8N8F608P861 == 0x02)
         {
               VEMS_vidGET(Srv_Diag_trim_Pid07,
                           u8LocalSrv_Diag_trim_Pid07);
               s16LocalIscanCMM_608 = (sint16)(((25 * u8LocalSrv_Diag_trim_Pid07) / 32) - 100);
               ISCAN_u8N8F608P862 = (uint8)(MATHSRV_udtCLAMP(s16LocalIscanCMM_608,
                                                        0,
                                                        255));
   			Com_SendSignal(Com_CORREC_LENTE_CARBUR_RANG_1_CMM_608, (void*) &ISCAN_u8N8F608P862);
         }
      }

		VEMS_vidGET(Ctrl_spdVeh, Local_bCtrl_spdVeh);
		if (ACTIVATED == Local_bCtrl_spdVeh)
		{
			if (ISCAN_u8N8F608P861 == 0x03)
         {
   			FRM_bInhF608P958_in = GDGAR_bGetFRM(FRM_FRM_INHF608P958);
   			if (FRM_bInhF608P958_in == FALSE)
   			{
               VEMS_vidGET(Ext_spdVeh,
                           u8LocalExt_spdVeh);
               ISCAN_u8N8F608P958 = (uint8)(MATHSRV_udtMIN(u8LocalExt_spdVeh,
                                                      254));
   			}
   			else
   			{
   				ISCAN_u8N8F608P958 = 255;
   			}
   			Com_SendSignal(Com_VITESSE_VEH_CMM_608, (void*) &ISCAN_u8N8F608P958);
         }
      }

		VEMS_vidGET(Ctrl_CMM_608, Local_bCtrl_CMM_608);
		if (ACTIVATED == Local_bCtrl_CMM_608)
		{
			if (ISCAN_u8N8F608P861 == 0x01)
         {
   				ISCAN_PBkind8N8F608FreOrStub1 = 255;
   			Com_SendSignal(Com_RESERVE_8_CMM_608, (void*) &ISCAN_PBkind8N8F608FreOrStub1);
         }
      }

		VEMS_vidGET(Ctrl_CMM_608, Local_bCtrl_CMM_608);
		if (ACTIVATED == Local_bCtrl_CMM_608)
		{
			if (ISCAN_u8N8F608P861 == 0x02)
         {
   				ISCAN_PBkind8N8F608FreOrStub2 = 255;
   			Com_SendSignal(Com_CORREC_RAP_CARBUR_RANG_2_CMM_608, (void*) &ISCAN_PBkind8N8F608FreOrStub2);
         }
      }

		VEMS_vidGET(Ctrl_mfAirMes, Local_bCtrl_mfAirMes);
		if (ACTIVATED == Local_bCtrl_mfAirMes)
		{
			if (ISCAN_u8N8F608P861 == 0x03)
         {
               VEMS_vidGET(Ext_mfAirMes,
                           u8LocalExt_mfAirMes);
               ISCAN_u8N8F608P885 = u8LocalExt_mfAirMes;
   			Com_SendSignal(Com_DEBIT_AIR_POIDS_FAIBLE_CMM_608, (void*) &ISCAN_u8N8F608P885);
         }
      }

		VEMS_vidGET(Ctrl_bAcv_stPwrSys2, Local_bCtrl_bAcv_stPwrSys2);
		if (ACTIVATED == Local_bCtrl_bAcv_stPwrSys2)
		{
			if (ISCAN_u8N8F608P861 == 0x01)
         {
               VEMS_vidGET(Srv_Fuel_System_Pid03,
                           u8LocalSrv_Fuel_System_Pid03);
               ISCAN_u8N8F608P912 = u8LocalSrv_Fuel_System_Pid03;
   			Com_SendSignal(Com_ETAT_SYST_ALIM_1_CMM_608, (void*) &ISCAN_u8N8F608P912);
         }
      }

		VEMS_vidGET(Ctrl_CMM_608, Local_bCtrl_CMM_608);
		if (ACTIVATED == Local_bCtrl_CMM_608)
		{
			if (ISCAN_u8N8F608P861 == 0x02)
         {
   				ISCAN_PBkind8N8F608FreOrStub3 = 255;
   			Com_SendSignal(Com_CORREC_LENTE_CARBUR_RANG_2_CMM_608, (void*) &ISCAN_PBkind8N8F608FreOrStub3);
         }
      }

		VEMS_vidGET(Ctrl_mfAirMes, Local_bCtrl_mfAirMes);
		if (ACTIVATED == Local_bCtrl_mfAirMes)
		{
			if (ISCAN_u8N8F608P861 == 0x03)
         {
               VEMS_vidGET(Ext_mfAirMes,
                           u8LocalExt_mfAirMes);
               ISCAN_u8N8F608P886 = u8LocalExt_mfAirMes;
   			Com_SendSignal(Com_DEBIT_AIR_POIDS_FORT_CMM_608, (void*) &ISCAN_u8N8F608P886);
         }
      }

		VEMS_vidGET(Ctrl_CMM_608, Local_bCtrl_CMM_608);
		if (ACTIVATED == Local_bCtrl_CMM_608)
		{
			if (ISCAN_u8N8F608P861 == 0x01)
         {
   				ISCAN_PBkind8N8F608FreOrStub4 = 255;
   			Com_SendSignal(Com_ETAT_SYST_ALIM_2_CMM_608, (void*) &ISCAN_PBkind8N8F608FreOrStub4);
         }
      }

		VEMS_vidGET(Ctrl_bFuTnkEmp, Local_bCtrl_bFuTnkEmp);
		if (ACTIVATED == Local_bCtrl_bFuTnkEmp)
		{
			if (ISCAN_u8N8F608P861 == 0x02)
         {
               VEMS_vidGET(Ext_bFuTnkEmp,
                           bLocalExt_bFuTnkEmp);
               ISCAN_u8N8F608P926 = (uint8)(MATHSRV_udtMIN(bLocalExt_bFuTnkEmp,
                                                      255));
   			Com_SendSignal(Com_MANO_CARBURANT_CMM_608, (void*) &ISCAN_u8N8F608P926);
         }
      }

		VEMS_vidGET(Ctrl_CMM_608, Local_bCtrl_CMM_608);
		if (ACTIVATED == Local_bCtrl_CMM_608)
		{
			if (ISCAN_u8N8F608P861 == 0x03)
         {
   				ISCAN_u8N8F608P937 = 0;
   			Com_SendSignal(Com_PRESSION_GAS_OIL_POIDS_FAIBLE_CMM_608, (void*) &ISCAN_u8N8F608P937);
         }
      }

		VEMS_vidGET(Ctrl_rtqOBD, Local_bCtrl_rtqOBD);
		if (ACTIVATED == Local_bCtrl_rtqOBD)
		{
			if (ISCAN_u8N8F608P861 == 0x01)
         {
               VEMS_vidGET(Srv_Engine_load_Pid04,
                           u8LocalSrv_Engine_load_Pid04);
               ISCAN_u8N8F608P373 = u8LocalSrv_Engine_load_Pid04;
   			Com_SendSignal(Com_VALEUR_CHARGE_CALCULEE_CMM_608, (void*) &ISCAN_u8N8F608P373);
         }
      }

		VEMS_vidGET(Ctrl_pDsEGRVlvMes, Local_bCtrl_pDsEGRVlvMes);
		if (ACTIVATED == Local_bCtrl_pDsEGRVlvMes)
		{
			if (ISCAN_u8N8F608P861 == 0x02)
         {
               VEMS_vidGET(Ext_pDsThrMes,
                           s16LocalExt_pDsThrMes);
               ISCAN_u8N8F608P936 = (uint8)(MATHSRV_udtCLAMP(s16LocalExt_pDsThrMes,
                                                        0,
                                                        255));
   			Com_SendSignal(Com_PRESSION_ABS_TUB_ADMI_CMM_608, (void*) &ISCAN_u8N8F608P936);
         }
      }

		VEMS_vidGET(Ctrl_CMM_608, Local_bCtrl_CMM_608);
		if (ACTIVATED == Local_bCtrl_CMM_608)
		{
			if (ISCAN_u8N8F608P861 == 0x03)
         {
   				ISCAN_u8N8F608P938 = 0;
   			Com_SendSignal(Com_PRESSION_GAS_OIL_POIDS_FORT_CMM_608, (void*) &ISCAN_u8N8F608P938);
         }
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF488.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF488.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_488(void)
{
	ISCAN_u8N8F488P005 = 60;
	ISCAN_u8N8F488P021 = 0;
	ISCAN_u8N8F488P022 = 254;
	ISCAN_bF488FreOrStub1 = 0;
	ISCAN_bF488P063 = 0;
	ISCAN_bF488P296 = 0;
	ISCAN_bF488FreOrStub2 = 0;
	ISCAN_bF488P105 = 0;
	ISCAN_bF488FreOrStub3 = 0;
	ISCAN_bF488FreOrStub4 = 0;
	ISCAN_bF488P032 = 0;
	ISCAN_bF488FreOrStub5 = 0;
	ISCAN_bF488FreOrStub6 = 0;
	ISCAN_bF488FreOrStub7 = 0;
	ISCAN_PBkind8N2F488FreOrStub8 = 0;
	ISCAN_PBkind8N2F488FreOrStub9 = 0;
	ISCAN_bF488FreOrStub10 = 0;
	ISCAN_u8N8F488P011 = 60;
	ISCAN_PBkind8N8F488FreOrStub11 = 0;
	ISCAN_u8N8F488P158 = 60;
}


void ISCAN_vidEve_Tx_488(void)
{
	boolean Local_bCtrl_CMM_488;
	boolean Local_bCtrl_tCoMesFineResl;
	boolean Local_bCtrl_volFuCnsTot;
	boolean Local_bCtrl_nTarIdl;
	boolean Local_bCtrl_bVSCtlDft;
	boolean Local_bCtrl_bEHRWaPmpReqRTE;
	boolean Local_bCtrl_bWarn_tCo;
	boolean Local_bCtrl_bEngStrtReq;
	boolean Local_bCtrl_tOilEstim;
	boolean Local_bCtrl_tDsThrMes;
	boolean FRM_bInhF488P005_in;
	boolean FRM_bInhF488P022_in;
	boolean FRM_bInhF488P011_in;
	boolean FRM_bInhF488P158_in;
   sint16 s16LocalExt_tCoMesFineResl;
   sint32 s32LocalIscanCMM_488;
   uint8 u8LocalFuCns_volFuCnsTot;
   uint16 u16LocalTqSys_nTarIdl;
   uint16 u16LocalIscanCMM_488;
   boolean bLocalVSCtl_bVSCtlDft;
   boolean bLocalThMgt_bEHRWaPmpReq;
   boolean bLocalThMgt_bTCoWarnReq;
   boolean bLocalTqCmp_bEngStrtReq;
   sint16 s16LocalEng_tOilEstim;
   sint16 s16LocalExt_tDsThrMes;

	VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
	if (ACTIVATED == Local_bCtrl_CMM_488)
	{
		VEMS_vidGET(Ctrl_tCoMesFineResl, Local_bCtrl_tCoMesFineResl);
		if (ACTIVATED == Local_bCtrl_tCoMesFineResl)
		{
			FRM_bInhF488P005_in = GDGAR_bGetFRM(FRM_FRM_INHF488P005);
			if (FRM_bInhF488P005_in == FALSE)
			{
               VEMS_vidGET(Ext_tCoMesFineResl,
                           s16LocalExt_tCoMesFineResl);
               s32LocalIscanCMM_488 = (sint32)(((s16LocalExt_tCoMesFineResl) / 4) + 40);
               ISCAN_u8N8F488P005 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_488,
                                                        0,
                                                        254));
			}
			else
			{
				ISCAN_u8N8F488P005 = 255;
			}
			Com_SendSignal(Com_TEMP_EAU_MOT_CMM_488, (void*) &ISCAN_u8N8F488P005);
      }

		VEMS_vidGET(Ctrl_volFuCnsTot, Local_bCtrl_volFuCnsTot);
		if (ACTIVATED == Local_bCtrl_volFuCnsTot)
		{
               VEMS_vidGET(FuCns_volFuCnsTot,
                           u8LocalFuCns_volFuCnsTot);
               ISCAN_u8N8F488P021 = u8LocalFuCns_volFuCnsTot;
			Com_SendSignal(Com_CONSO_CARBURANT_CMM_488, (void*) &ISCAN_u8N8F488P021);
      }

		VEMS_vidGET(Ctrl_nTarIdl, Local_bCtrl_nTarIdl);
		if (ACTIVATED == Local_bCtrl_nTarIdl)
		{
			FRM_bInhF488P022_in = GDGAR_bGetFRM(FRM_FRM_INHF488P022);
			if (FRM_bInhF488P022_in == FALSE)
			{
               VEMS_vidGET(TqSys_nTarIdl,
                           u16LocalTqSys_nTarIdl);
               u16LocalIscanCMM_488 = (uint16)(((u16LocalTqSys_nTarIdl) / 32));
               ISCAN_u8N8F488P022 = (uint8)(MATHSRV_udtMIN(u16LocalIscanCMM_488,
                                                      253));
			}
			else
			{
				ISCAN_u8N8F488P022 = 255;
			}
			Com_SendSignal(Com_CNS_REGUL_RALENTI_CMM_488, (void*) &ISCAN_u8N8F488P022);
      }

		VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
		if (ACTIVATED == Local_bCtrl_CMM_488)
		{
				ISCAN_bF488FreOrStub1 = 1;
			Com_SendSignal(Com_RATES_COMBUSTION_CMM_488, (void*) &ISCAN_bF488FreOrStub1);
      }

		VEMS_vidGET(Ctrl_bVSCtlDft, Local_bCtrl_bVSCtlDft);
		if (ACTIVATED == Local_bCtrl_bVSCtlDft)
		{
               VEMS_vidGET(VSCtl_bVSCtlDft,
                           bLocalVSCtl_bVSCtlDft);
               ISCAN_bF488P063 = bLocalVSCtl_bVSCtlDft;
			Com_SendSignal(Com_DEFAUT_RVV_LVV_CMM_488, (void*) &ISCAN_bF488P063);
      }

		VEMS_vidGET(Ctrl_bEHRWaPmpReqRTE, Local_bCtrl_bEHRWaPmpReqRTE);
		if (ACTIVATED == Local_bCtrl_bEHRWaPmpReqRTE)
		{
               VEMS_vidGET(ThMgt_bEHRWaPmpReq,
                           bLocalThMgt_bEHRWaPmpReq);
               ISCAN_bF488P296 = bLocalThMgt_bEHRWaPmpReq;
			Com_SendSignal(Com_CNS_POMPE_EAU_RTE_CMM_488, (void*) &ISCAN_bF488P296);
      }

		VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
		if (ACTIVATED == Local_bCtrl_CMM_488)
		{
				ISCAN_bF488FreOrStub2 = 0;
			Com_SendSignal(Com_DDE_ALLUM_VOY_MLGE_PVRE_CMM_488, (void*) &ISCAN_bF488FreOrStub2);
      }

		VEMS_vidGET(Ctrl_bWarn_tCo, Local_bCtrl_bWarn_tCo);
		if (ACTIVATED == Local_bCtrl_bWarn_tCo)
		{
               VEMS_vidGET(ThMgt_bTCoWarnReq,
                           bLocalThMgt_bTCoWarnReq);
               ISCAN_bF488P105 = bLocalThMgt_bTCoWarnReq;
			Com_SendSignal(Com_ALRT_TEMP_EAU_CMM_488, (void*) &ISCAN_bF488P105);
      }

		VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
		if (ACTIVATED == Local_bCtrl_CMM_488)
		{
				ISCAN_bF488FreOrStub3 = 1;
			Com_SendSignal(Com_REQ_LAMPE_MIL_CMM_488, (void*) &ISCAN_bF488FreOrStub3);
      }

		VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
		if (ACTIVATED == Local_bCtrl_CMM_488)
		{
				ISCAN_bF488FreOrStub4 = 0;
			Com_SendSignal(Com_REQ_LAMPE_PRECH_CMM_488, (void*) &ISCAN_bF488FreOrStub4);
      }

		VEMS_vidGET(Ctrl_bEngStrtReq, Local_bCtrl_bEngStrtReq);
		if (ACTIVATED == Local_bCtrl_bEngStrtReq)
		{
               VEMS_vidGET(TqCmp_bEngStrtReq,
                           bLocalTqCmp_bEngStrtReq);
               ISCAN_bF488P032 = bLocalTqCmp_bEngStrtReq;
			Com_SendSignal(Com_DEM_EN_COURS_CMM_488, (void*) &ISCAN_bF488P032);
      }

		VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
		if (ACTIVATED == Local_bCtrl_CMM_488)
		{
				ISCAN_bF488FreOrStub5 = 0;
			Com_SendSignal(Com_FORCAGE_PRESSION_BVA_CMM_488, (void*) &ISCAN_bF488FreOrStub5);
      }

		VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
		if (ACTIVATED == Local_bCtrl_CMM_488)
		{
				ISCAN_bF488FreOrStub6 = 0;
			Com_SendSignal(Com_RISQUE_COLMATAGE_FAP_CMM_488, (void*) &ISCAN_bF488FreOrStub6);
      }

		VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
		if (ACTIVATED == Local_bCtrl_CMM_488)
		{
				ISCAN_bF488FreOrStub7 = 0;
			Com_SendSignal(Com_TYPE_INFO_CONSO_CARB_CMM_488, (void*) &ISCAN_bF488FreOrStub7);
      }

		VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
		if (ACTIVATED == Local_bCtrl_CMM_488)
		{
				ISCAN_PBkind8N2F488FreOrStub8 = 3;
			Com_SendSignal(Com_DMD_GMP_CLIGNO_STOP_SVCE_CMM_488, (void*) &ISCAN_PBkind8N2F488FreOrStub8);
      }

		VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
		if (ACTIVATED == Local_bCtrl_CMM_488)
		{
				ISCAN_PBkind8N2F488FreOrStub9 = 3;
			Com_SendSignal(Com_ETAT_GESTION_CLIM_CMM_488, (void*) &ISCAN_PBkind8N2F488FreOrStub9);
      }

		VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
		if (ACTIVATED == Local_bCtrl_CMM_488)
		{
				ISCAN_bF488FreOrStub10 = 0;
			Com_SendSignal(Com_COUP_CLIM_SECU_CMM_488, (void*) &ISCAN_bF488FreOrStub10);
      }

		VEMS_vidGET(Ctrl_tOilEstim, Local_bCtrl_tOilEstim);
		if (ACTIVATED == Local_bCtrl_tOilEstim)
		{
			FRM_bInhF488P011_in = GDGAR_bGetFRM(FRM_FRM_INHF488P011);
			if (FRM_bInhF488P011_in == FALSE)
			{
               VEMS_vidGET(Eng_tOilEstim,
                           s16LocalEng_tOilEstim);
               s32LocalIscanCMM_488 = (sint32)(((s16LocalEng_tOilEstim) / 4) + 40);
               ISCAN_u8N8F488P011 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_488,
                                                        0,
                                                        254));
			}
			else
			{
				ISCAN_u8N8F488P011 = 255;
			}
			Com_SendSignal(Com_TEMP_HUILE_MOT_CMM_488, (void*) &ISCAN_u8N8F488P011);
      }

		VEMS_vidGET(Ctrl_CMM_488, Local_bCtrl_CMM_488);
		if (ACTIVATED == Local_bCtrl_CMM_488)
		{
				ISCAN_PBkind8N8F488FreOrStub11 = 255;
			Com_SendSignal(Com_PRESSION_REFRI_CMM_488, (void*) &ISCAN_PBkind8N8F488FreOrStub11);
      }

		VEMS_vidGET(Ctrl_tDsThrMes, Local_bCtrl_tDsThrMes);
		if (ACTIVATED == Local_bCtrl_tDsThrMes)
		{
			FRM_bInhF488P158_in = GDGAR_bGetFRM(FRM_FRM_INHF488P158);
			if (FRM_bInhF488P158_in == FALSE)
			{
               VEMS_vidGET(Ext_tDsThrMes,
                           s16LocalExt_tDsThrMes);
               s32LocalIscanCMM_488 = (sint32)((s16LocalExt_tDsThrMes) + 40);
               ISCAN_u8N8F488P158 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_488,
                                                        0,
                                                        254));
			}
			else
			{
				ISCAN_u8N8F488P158 = 255;
			}
			Com_SendSignal(Com_TEMP_AIR_MOT_CMM_488, (void*) &ISCAN_u8N8F488P158);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

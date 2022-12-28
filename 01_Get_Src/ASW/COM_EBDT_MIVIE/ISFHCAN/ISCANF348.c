/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF348.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF348.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_348(void)
{
	ISCAN_u8N4F348P152 = 14;
	ISCAN_u8N2F348PM1432 = 0;
	ISCAN_bF348FreOrStub1 = 0;
	ISCAN_bF348FreOrStub2 = 0;
	ISCAN_u8N8F348P019 = 50;
	ISCAN_u8N8F348P211 = 255;
	ISCAN_u8N8F348P017 = 50;
	ISCAN_u8N3F348P212 = 6;
	ISCAN_u8N2F348P091 = 2;
	ISCAN_u8N2F348P025 = 0;
	ISCAN_bF348P026 = 1;
	ISCAN_PBkind8N2F348FreOrStub3 = 0;
	ISCAN_PBkind8N2F348FreOrStub4 = 0;
	ISCAN_u8N4F348P134 = 1;
	ISCAN_bF348FreOrStub5 = 0;
	ISCAN_bF348P372 = 0;
	ISCAN_bF348P371 = 0;
	ISCAN_bF348P370 = 0;
	ISCAN_bF348P345 = 0;
	ISCAN_bF348P344 = 0;
	ISCAN_bF348P343 = 0;
	ISCAN_bF348FreOrStub6 = 0;
	ISCAN_bF348P258 = 0;
	ISCAN_bF348P269 = 0;
	ISCAN_u8N6F348P207 = 62;
}


void ISCAN_vidEve_Tx_348(void)
{
	boolean Local_bCtrl_CMM_348;
	boolean Local_bCtrl_noEgdGearCord;
	boolean Local_bCtrl_bAcv_stModSpt;
	boolean Local_bCtrl_tqEfcLim;
	boolean Local_bCtrl_pAC;
	boolean Local_bCtrl_tqSumLossCmp;
	boolean Local_bCtrl_stReq;
	boolean Local_bCtrl_bCluPedPrss;
	boolean Local_bCtrl_stDiagESPReq;
	boolean Local_bCtrl_bInhAcqESCFrnt;
	boolean Local_bCtrl_bAcv_stEngCordThm;
	boolean Local_bCtrl_bKeyON;
	boolean Local_bCtrl_bDrvCyGlbl;
	boolean Local_bCtrl_bWUC;
	boolean Local_bCtrl_bFlashLiMIL;
	boolean Local_bCtrl_bLiIMIL;
	boolean Local_bCtrl_bOBDDftOnMIL;
	boolean Local_bCtrl_bAcvWupMod;
	boolean Local_bCtrl_bTraTqAuthRaw;
	boolean Local_bCtrl_rSpdFanAct;
	boolean FRM_bInhF348P019_in;
	boolean FRM_bInhF348P211_in;
	boolean FRM_bInhF348P017_in;
	boolean FRM_bInhF348P091_in;
	boolean FRM_bInhF348P134_in;
	boolean FRM_bInhF348P207_in;
   uint8 u8LocalExt_noEgdGearCord;
   uint8 u8LocalTqSys_stModSpt;
   sint16 s16LocalCoCha_tqEfcLim;
   sint32 s32LocalIscanCMM_348;
   uint16 u16LocalExt_pAC;
   sint16 s16LocalTqCmp_tqSumLossCmp;
   uint8 u8LocalACCmd_stReq;

   boolean bLocalExt_bCluPedPrss;
   uint8 u8LocalTqDiag_stDiagESPReq;
   boolean bLocalExt_bInhAcqESCFrnt;
   uint8 u8LocalCoPTSt_stEng;
   boolean bLocalExt_bKeyOn;
   boolean bLocalExt_bDrvCyGlbl;
   boolean bLocalWUC_bWupSt;
   boolean bLocalGMIL_bMilBlink;
   boolean bLocalGMIL_bMilOn;
   boolean bLocalGMIL_bMilDftPres;
   boolean bLocalCoPt_bAcvWupMod;
   boolean bLocalCoTqRStrt_bTraCoplAuth;
   uint8 u8LocalExt_rSpdFanAct;

	VEMS_vidGET(Ctrl_CMM_348, Local_bCtrl_CMM_348);
	if (ACTIVATED == Local_bCtrl_CMM_348)
	{
		VEMS_vidGET(Ctrl_noEgdGearCord, Local_bCtrl_noEgdGearCord);
		if (ACTIVATED == Local_bCtrl_noEgdGearCord)
		{
            VEMS_vidGET(Ext_noEgdGearCord, u8LocalExt_noEgdGearCord);
   
      
      			if (u8LocalExt_noEgdGearCord == 7) 
      	        {
      				ISCAN_u8N4F348P152 = 9;
      			}
      			else
      			{
                  ISCAN_u8N4F348P152 = (uint8)(MATHSRV_udtMIN(u8LocalExt_noEgdGearCord,
                                                         15));
   
      			}
			Com_SendSignal(Com_RAP_ENGAGE_CALCULE_CMM_348, (void*) &ISCAN_u8N4F348P152);
      }

		VEMS_vidGET(Ctrl_bAcv_stModSpt, Local_bCtrl_bAcv_stModSpt);
		if (ACTIVATED == Local_bCtrl_bAcv_stModSpt)
		{
               VEMS_vidGET(TqSys_stModSpt,
                           u8LocalTqSys_stModSpt);
               ISCAN_u8N2F348PM1432 = (uint8)(MATHSRV_udtMIN(u8LocalTqSys_stModSpt,
                                                      3));
			Com_SendSignal(Com_ETAT_CMM_DYN_CMM_348, (void*) &ISCAN_u8N2F348PM1432);
      }

		VEMS_vidGET(Ctrl_CMM_348, Local_bCtrl_CMM_348);
		if (ACTIVATED == Local_bCtrl_CMM_348)
		{
				ISCAN_bF348FreOrStub1 = 0;
			Com_SendSignal(Com_SOUTIEN_GENE_ELECT_CMM_348, (void*) &ISCAN_bF348FreOrStub1);
      }

		VEMS_vidGET(Ctrl_CMM_348, Local_bCtrl_CMM_348);
		if (ACTIVATED == Local_bCtrl_CMM_348)
		{
				ISCAN_bF348FreOrStub2 = 0;
			Com_SendSignal(Com_EAU_GAZOLE_CMM_348, (void*) &ISCAN_bF348FreOrStub2);
      }

		VEMS_vidGET(Ctrl_tqEfcLim, Local_bCtrl_tqEfcLim);
		if (ACTIVATED == Local_bCtrl_tqEfcLim)
		{
			FRM_bInhF348P019_in = GDGAR_bGetFRM(FRM_FRM_INHF348P019);
			if (FRM_bInhF348P019_in == FALSE)
			{
               VEMS_vidGET(CoCha_tqEfcLim,
                           s16LocalCoCha_tqEfcLim);
               s32LocalIscanCMM_348 = (sint32)(((s16LocalCoCha_tqEfcLim) / 32) + 50);
               ISCAN_u8N8F348P019 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_348,
                                                        0,
                                                        254));
			}
			else
			{
				ISCAN_u8N8F348P019 = 255;
			}
			Com_SendSignal(Com_CPLE_COND_AVT_TRT_CMM_348, (void*) &ISCAN_u8N8F348P019);
      }

		VEMS_vidGET(Ctrl_pAC, Local_bCtrl_pAC);
		if (ACTIVATED == Local_bCtrl_pAC)
		{
			FRM_bInhF348P211_in = GDGAR_bGetFRM(FRM_FRM_INHF348P211);
			if (FRM_bInhF348P211_in == FALSE)
			{
               VEMS_vidGET(Ext_pAC,
                           u16LocalExt_pAC);
               s32LocalIscanCMM_348 = (sint32)(((u16LocalExt_pAC) / 11) - 10);
               ISCAN_u8N8F348P211 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_348,
                                                        0,
                                                        254));
			}
			else
			{
				ISCAN_u8N8F348P211 = 255;
			}
			Com_SendSignal(Com_PRESSION_REFRI_2_CMM_348, (void*) &ISCAN_u8N8F348P211);
      }

		VEMS_vidGET(Ctrl_tqSumLossCmp, Local_bCtrl_tqSumLossCmp);
		if (ACTIVATED == Local_bCtrl_tqSumLossCmp)
		{
			FRM_bInhF348P017_in = GDGAR_bGetFRM(FRM_FRM_INHF348P017);
			if (FRM_bInhF348P017_in == FALSE)
			{
               VEMS_vidGET(TqCmp_tqSumLossCmp,
                           s16LocalTqCmp_tqSumLossCmp);
               s32LocalIscanCMM_348 = (sint32)(((s16LocalTqCmp_tqSumLossCmp) / 32) + 50);
               ISCAN_u8N8F348P017 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_348,
                                                        0,
                                                        254));
			}
			else
			{
				ISCAN_u8N8F348P017 = 255;
			}
			Com_SendSignal(Com_COUPLE_RESISTANT_CMM_348, (void*) &ISCAN_u8N8F348P017);
      }

		VEMS_vidGET(Ctrl_stReq, Local_bCtrl_stReq);
		if (ACTIVATED == Local_bCtrl_stReq)
		{
            VEMS_vidGET(ACCmd_stReq, u8LocalACCmd_stReq);
   
      	
      			switch(u8LocalACCmd_stReq)
      			{
      			case 0:
      	        ISCAN_u8N3F348P212 = 0x02;
      	        break;
      
      	        case 1:
      	        ISCAN_u8N3F348P212 = 0x00;
      	        break;
      
      	        case 2:
      	        ISCAN_u8N3F348P212 = 0x06;
      	        break;
      
      	        case 3:
      	        ISCAN_u8N3F348P212 = 0x01;
      	        break;
      
      	        case 4:
      	        ISCAN_u8N3F348P212 = 0x04;
      	        break;
      
      	        default:
      	        ISCAN_u8N3F348P212 = 0x06;
      	        break;
      	      }
			Com_SendSignal(Com_CONS_SOUL_PUIS_COMP_CMM_348, (void*) &ISCAN_u8N3F348P212);
      }

		VEMS_vidGET(Ctrl_bCluPedPrss, Local_bCtrl_bCluPedPrss);
		if (ACTIVATED == Local_bCtrl_bCluPedPrss)
		{
			FRM_bInhF348P091_in = GDGAR_bGetFRM(FRM_FRM_INHF348P091);
			if (FRM_bInhF348P091_in == FALSE)
			{
               VEMS_vidGET(Ext_bCluPedPrss,
                           bLocalExt_bCluPedPrss);
               ISCAN_u8N2F348P091 = (uint8)(MATHSRV_udtMIN(bLocalExt_bCluPedPrss,
                                                      3));
			}
			else
			{
				ISCAN_u8N2F348P091 = 3;
			}
			Com_SendSignal(Com_CONT_EMBR_CMM_CMM_348, (void*) &ISCAN_u8N2F348P091);
      }

		VEMS_vidGET(Ctrl_stDiagESPReq, Local_bCtrl_stDiagESPReq);
		if (ACTIVATED == Local_bCtrl_stDiagESPReq)
		{
               VEMS_vidGET(TqDiag_stDiagESPReq,
                           u8LocalTqDiag_stDiagESPReq);
               ISCAN_u8N2F348P025 = (uint8)(MATHSRV_udtMIN(u8LocalTqDiag_stDiagESPReq,
                                                      3));
			Com_SendSignal(Com_ETAT_CNS_ASR_MSR_CMM_348, (void*) &ISCAN_u8N2F348P025);
      }

		VEMS_vidGET(Ctrl_bInhAcqESCFrnt, Local_bCtrl_bInhAcqESCFrnt);
		if (ACTIVATED == Local_bCtrl_bInhAcqESCFrnt)
		{
               VEMS_vidGET(Ext_bInhAcqESCFrnt,
                           bLocalExt_bInhAcqESCFrnt);
               ISCAN_bF348P026 = bLocalExt_bInhAcqESCFrnt;
			Com_SendSignal(Com_ACQ_ASR_MSR_CMM_348, (void*) &ISCAN_bF348P026);
      }

		VEMS_vidGET(Ctrl_CMM_348, Local_bCtrl_CMM_348);
		if (ACTIVATED == Local_bCtrl_CMM_348)
		{
				ISCAN_PBkind8N2F348FreOrStub3 = 0;
			Com_SendSignal(Com_MODES_DEGRADES_MT_CMM_348, (void*) &ISCAN_PBkind8N2F348FreOrStub3);
      }

		VEMS_vidGET(Ctrl_CMM_348, Local_bCtrl_CMM_348);
		if (ACTIVATED == Local_bCtrl_CMM_348)
		{
				ISCAN_PBkind8N2F348FreOrStub4 = 0;
			Com_SendSignal(Com_LIBRE_CMM_348, (void*) &ISCAN_PBkind8N2F348FreOrStub4);
      }

		VEMS_vidGET(Ctrl_bAcv_stEngCordThm, Local_bCtrl_bAcv_stEngCordThm);
		if (ACTIVATED == Local_bCtrl_bAcv_stEngCordThm)
		{
			FRM_bInhF348P134_in = GDGAR_bGetFRM(FRM_FRM_INHF348P134);
			if (FRM_bInhF348P134_in == FALSE)
			{
            VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   
      
      			switch(u8LocalCoPTSt_stEng)
      			{
      			case 1:
      				ISCAN_u8N4F348P134 = 0x01;    
      	        break;
      
      			case 2:
      	         ISCAN_u8N4F348P134 = 0x07;    
      	         break;
      
      			case 3:
      	         ISCAN_u8N4F348P134 = 0x02;    
      	         break;
      
      			case 4:
      	         ISCAN_u8N4F348P134 = 0x0A;
      	         break;
      
      			case 5:
      	         ISCAN_u8N4F348P134 = 0x03;
      	         break;
      
      			case 6:
      	         ISCAN_u8N4F348P134 = 0x04;
      	         break;
      
      			case 7:
      	         ISCAN_u8N4F348P134 = 0x05;
      	         break;
      
      			case 8:
      	         ISCAN_u8N4F348P134 = 0x0D;
      	         break;
      
      			default:
      	         ISCAN_u8N4F348P134 = 0x0F;
      	         break;
      			}
			}
			else
			{
				ISCAN_u8N4F348P134 = 15;
			}
			Com_SendSignal(Com_ETAT_MT_CMM_348, (void*) &ISCAN_u8N4F348P134);
      }

		VEMS_vidGET(Ctrl_CMM_348, Local_bCtrl_CMM_348);
		if (ACTIVATED == Local_bCtrl_CMM_348)
		{
				ISCAN_bF348FreOrStub5 = 0;
			Com_SendSignal(Com_DELEST_SECU_MOT_NIV2_CMM_348, (void*) &ISCAN_bF348FreOrStub5);
      }

		VEMS_vidGET(Ctrl_bKeyON, Local_bCtrl_bKeyON);
		if (ACTIVATED == Local_bCtrl_bKeyON)
		{
               VEMS_vidGET(Ext_bKeyOn,
                           bLocalExt_bKeyOn);
               ISCAN_bF348P372 = bLocalExt_bKeyOn;
			Com_SendSignal(Com_CONTACT_OBD_CMM_348, (void*) &ISCAN_bF348P372);
      }

		VEMS_vidGET(Ctrl_bDrvCyGlbl, Local_bCtrl_bDrvCyGlbl);
		if (ACTIVATED == Local_bCtrl_bDrvCyGlbl)
		{
               VEMS_vidGET(Ext_bDrvCyGlbl,
                           bLocalExt_bDrvCyGlbl);
               ISCAN_bF348P371 = bLocalExt_bDrvCyGlbl;
			Com_SendSignal(Com_SYNCHRO_DC_GLOBAL_CMM_348, (void*) &ISCAN_bF348P371);
      }

		VEMS_vidGET(Ctrl_bWUC, Local_bCtrl_bWUC);
		if (ACTIVATED == Local_bCtrl_bWUC)
		{
               VEMS_vidGET(WUC_bWupSt,
                           bLocalWUC_bWupSt);
               ISCAN_bF348P370 = bLocalWUC_bWupSt;
			Com_SendSignal(Com_ETAT_REALISATION_WUC_CMM_348, (void*) &ISCAN_bF348P370);
      }

		VEMS_vidGET(Ctrl_bFlashLiMIL, Local_bCtrl_bFlashLiMIL);
		if (ACTIVATED == Local_bCtrl_bFlashLiMIL)
		{
               VEMS_vidGET(GMIL_bMilBlink,
                           bLocalGMIL_bMilBlink);
               ISCAN_bF348P345 = bLocalGMIL_bMilBlink;
			Com_SendSignal(Com_REQ_MIL_CLNGNT_CMM_348, (void*) &ISCAN_bF348P345);
      }

		VEMS_vidGET(Ctrl_bLiIMIL, Local_bCtrl_bLiIMIL);
		if (ACTIVATED == Local_bCtrl_bLiIMIL)
		{
               VEMS_vidGET(GMIL_bMilOn,
                           bLocalGMIL_bMilOn);
               ISCAN_bF348P344 = bLocalGMIL_bMilOn;
			Com_SendSignal(Com_REQ_MIL_FIXE_CMM_348, (void*) &ISCAN_bF348P344);
      }

		VEMS_vidGET(Ctrl_bOBDDftOnMIL, Local_bCtrl_bOBDDftOnMIL);
		if (ACTIVATED == Local_bCtrl_bOBDDftOnMIL)
		{
               VEMS_vidGET(GMIL_bMilDftPres,
                           bLocalGMIL_bMilDftPres);
               ISCAN_bF348P343 = bLocalGMIL_bMilDftPres;
			Com_SendSignal(Com_PRES_DEF_OBD_SIGNALE_SUR_MIL_CMM_348, (void*) &ISCAN_bF348P343);
      }

		VEMS_vidGET(Ctrl_CMM_348, Local_bCtrl_CMM_348);
		if (ACTIVATED == Local_bCtrl_CMM_348)
		{
				ISCAN_bF348FreOrStub6 = 0;
			Com_SendSignal(Com_BES_PREP_MOT_CMM_348, (void*) &ISCAN_bF348FreOrStub6);
      }

		VEMS_vidGET(Ctrl_bAcvWupMod, Local_bCtrl_bAcvWupMod);
		if (ACTIVATED == Local_bCtrl_bAcvWupMod)
		{
               VEMS_vidGET(CoPt_bAcvWupMod,
                           bLocalCoPt_bAcvWupMod);
               ISCAN_bF348P258 = bLocalCoPt_bAcvWupMod;
			Com_SendSignal(Com_DDE_MODE_BV_MET_CMM_348, (void*) &ISCAN_bF348P258);
      }

		VEMS_vidGET(Ctrl_bTraTqAuthRaw, Local_bCtrl_bTraTqAuthRaw);
		if (ACTIVATED == Local_bCtrl_bTraTqAuthRaw)
		{
               VEMS_vidGET(CoTqRStrt_bTraCoplAuth,
                           bLocalCoTqRStrt_bTraCoplAuth);
               ISCAN_bF348P269 = bLocalCoTqRStrt_bTraCoplAuth;
			Com_SendSignal(Com_AUTORIS_DECOL_BV_CMM_348, (void*) &ISCAN_bF348P269);
      }

		VEMS_vidGET(Ctrl_rSpdFanAct, Local_bCtrl_rSpdFanAct);
		if (ACTIVATED == Local_bCtrl_rSpdFanAct)
		{
			FRM_bInhF348P207_in = GDGAR_bGetFRM(FRM_FRM_INHF348P207);
			if (FRM_bInhF348P207_in == FALSE)
			{
               VEMS_vidGET(Ext_rSpdFanAct,
                           u8LocalExt_rSpdFanAct);
               ISCAN_u8N6F348P207 = (uint8)(MATHSRV_udtMIN(u8LocalExt_rSpdFanAct,
                                                      55));
			}
			else
			{
				ISCAN_u8N6F348P207 = 63;
			}
			Com_SendSignal(Com_ETAT_CONS_APPL_GMV_CMM_348, (void*) &ISCAN_u8N6F348P207);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

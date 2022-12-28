/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF468.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF468.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_468(void)
{
	ISCAN_bF468P244 = 0;
	ISCAN_bF468P245 = 0;
	ISCAN_bF468P246 = 0;
	ISCAN_PBkind8N2F468FreOrStub1 = 0;
	ISCAN_PBkind8N2F468FreOrStub2 = 0;
	ISCAN_bF468FreOrStub3 = 0;
	ISCAN_PBkind8N2F468FreOrStub4 = 0;
	ISCAN_u8N2F468P234 = 3;
	ISCAN_u8N2F468P401 = 0;
	ISCAN_u8N2F468P400 = 0;
	ISCAN_u8N2F468PM1455 = 1;
	ISCAN_u8N5F468PM1440 = 0;
	ISCAN_bF468FreOrStub5 = 0;
	ISCAN_PBkind8N3F468FreOrStub6 = 0;
	ISCAN_u8N3F468P346 = 6;
	ISCAN_u8N6F468P347 = 0;
	ISCAN_bF468FreOrStub7 = 0;
	ISCAN_bF468FreOrStub8 = 0;
	ISCAN_bF468FreOrStub9 = 0;
	ISCAN_bF468FreOrStub10 = 0;
	ISCAN_bF468PM1322 = 0;
	ISCAN_PBkind8N2F468FreOrStub11 = 0;
	ISCAN_bF468PM1442 = 0;
	ISCAN_u8N4F468PM1443 = 1;
	ISCAN_bF468FreOrStub12 = 0;
	ISCAN_bF468FreOrStub13 = 0;
	ISCAN_u8N2F468PM1417 = 0;
	ISCAN_bF468FreOrStub14 = 0;
	ISCAN_bF468FreOrStub15 = 0;
	ISCAN_bF468FreOrStub16 = 0;
	ISCAN_bF468FreOrStub17 = 0;
}


void ISCAN_vidEve_Tx_468(void)
{
	boolean Local_bCtrl_CMM_468;
	boolean Local_bCtrl_bAcvStaReq;
	boolean Local_bCtrl_bDft_bBrkPedPrss;
	boolean Local_bCtrl_bStaProt;
	boolean Local_bCtrl_stAcvWarn;
	boolean Local_bCtrl_stStaAuth;
	boolean Local_bCtrl_stPwt;
	boolean Local_bCtrl_bAcv_bAcvElCnsReq;
	boolean Local_bCtrl_stElLvlProd;
	boolean Local_bCtrl_uReqProdElec;
	boolean Local_bCtrl_bAuthCrawl;
	boolean Local_bCtrl_bWupAcv;
	boolean Local_bCtrl_stElEProv;
	boolean Local_bCtrl_stReqBlsVoltCtl;
	boolean FRM_bInhF468PM1440_in;
	boolean FRM_bInhF468P346_in;
	boolean FRM_bInhF468P347_in;
   boolean bLocalStaCtl_bAcvStaReq;
   boolean bLocalFRM_bDft_bBrkPedPrss;
   boolean bLocalStaCtl_bStaProt;
   uint8 u8LocalECU_stAcvWarn;
   uint8 u8LocalStaCtl_stStaAuth;

   uint8 u8LocalExt_stPwt;
   boolean bLocalCoOptmEl_bAcvElCnsReq;
   uint16 u16LocalTqSys_pBoostSndModSpt;
   uint16 u16LocalIscanCMM_468;
   uint8 u8LocalCoOptmEl_stElLvlProd;
   uint16 u16LocalElProdMgt_uElProdSp;
   sint32 s32LocalIscanCMM_468;
   boolean bLocalCoPt_bAuthCrawl;
   boolean bLocalCoOptmEl_bWupAcv;
   uint8 u8LocalCoOptmEl_stElEProv;
   uint8 u8LocalTqLimUH_stReqBlsVoltCtl;

	VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
	if (ACTIVATED == Local_bCtrl_CMM_468)
	{
		VEMS_vidGET(Ctrl_bAcvStaReq, Local_bCtrl_bAcvStaReq);
		if (ACTIVATED == Local_bCtrl_bAcvStaReq)
		{
               VEMS_vidGET(StaCtl_bAcvStaReq,
                           bLocalStaCtl_bAcvStaReq);
               ISCAN_bF468P244 = bLocalStaCtl_bAcvStaReq;
			Com_SendSignal(Com_ETAT_DEMARREUR_CMM_468, (void*) &ISCAN_bF468P244);
      }

		VEMS_vidGET(Ctrl_bDft_bBrkPedPrss, Local_bCtrl_bDft_bBrkPedPrss);
		if (ACTIVATED == Local_bCtrl_bDft_bBrkPedPrss)
		{
               bLocalFRM_bDft_bBrkPedPrss = GDGAR_bGetFRM(FRM_FRM_DFT_BBRKPEDPRSS);
               ISCAN_bF468P245 = bLocalFRM_bDft_bBrkPedPrss;
			Com_SendSignal(Com_CONTACT_FREIN2_INC_CMM_468, (void*) &ISCAN_bF468P245);
      }

		VEMS_vidGET(Ctrl_bStaProt, Local_bCtrl_bStaProt);
		if (ACTIVATED == Local_bCtrl_bStaProt)
		{
               VEMS_vidGET(StaCtl_bStaProt,
                           bLocalStaCtl_bStaProt);
               ISCAN_bF468P246 = bLocalStaCtl_bStaProt;
			Com_SendSignal(Com_PROTECTION_DEMARREUR_CMM_468, (void*) &ISCAN_bF468P246);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_PBkind8N2F468FreOrStub1 = 0;
			Com_SendSignal(Com_ETAT_DAMP_CMM_CMM_468, (void*) &ISCAN_PBkind8N2F468FreOrStub1);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_PBkind8N2F468FreOrStub2 = 0;
			Com_SendSignal(Com_ETAT_GAP_CMM_468, (void*) &ISCAN_PBkind8N2F468FreOrStub2);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub3 = 0;
			Com_SendSignal(Com_BESOIN_NIVEAU_CARB_CMM_468, (void*) &ISCAN_bF468FreOrStub3);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_PBkind8N2F468FreOrStub4 = 0;
			Com_SendSignal(Com_TRANSIT_TURBO_CRS_CMM_468, (void*) &ISCAN_PBkind8N2F468FreOrStub4);
      }

		VEMS_vidGET(Ctrl_stAcvWarn, Local_bCtrl_stAcvWarn);
		if (ACTIVATED == Local_bCtrl_stAcvWarn)
		{
               VEMS_vidGET(ECU_stAcvWarn,
                           u8LocalECU_stAcvWarn);
               ISCAN_u8N2F468P234 = (uint8)(MATHSRV_udtMIN(u8LocalECU_stAcvWarn,
                                                      3));
			Com_SendSignal(Com_DEFAUT_CMM_CMM_468, (void*) &ISCAN_u8N2F468P234);
      }

		VEMS_vidGET(Ctrl_stStaAuth, Local_bCtrl_stStaAuth);
		if (ACTIVATED == Local_bCtrl_stStaAuth)
		{
            VEMS_vidGET(StaCtl_stStaAuth, u8LocalStaCtl_stStaAuth);
   
      
      			if (u8LocalStaCtl_stStaAuth == 0)
      			{
      				ISCAN_u8N2F468P401 = 2;
      			}
      			else
      			{
      				if (u8LocalStaCtl_stStaAuth == 1)
      				{
      					ISCAN_u8N2F468P401 = 1;
      				}
      			    else
      				{
      					if (u8LocalStaCtl_stStaAuth == 2)
      					{
      						ISCAN_u8N2F468P401 = 0;
      					}
      				}
      			}
			Com_SendSignal(Com_ETAT_AUTORISATION_DEM_CMM_468, (void*) &ISCAN_u8N2F468P401);
      }

		VEMS_vidGET(Ctrl_stPwt, Local_bCtrl_stPwt);
		if (ACTIVATED == Local_bCtrl_stPwt)
		{
               VEMS_vidGET(Ext_stPwt,
                           u8LocalExt_stPwt);
               ISCAN_u8N2F468P400 = (uint8)(MATHSRV_udtMIN(u8LocalExt_stPwt,
                                                      3));
			Com_SendSignal(Com_ETAT_CDT_VHL_CMM_468, (void*) &ISCAN_u8N2F468P400);
      }

		VEMS_vidGET(Ctrl_bAcv_bAcvElCnsReq, Local_bCtrl_bAcv_bAcvElCnsReq);
		if (ACTIVATED == Local_bCtrl_bAcv_bAcvElCnsReq)
		{
            VEMS_vidGET(CoOptmEl_bAcvElCnsReq, bLocalCoOptmEl_bAcvElCnsReq);
   
      
      			if ( bLocalCoOptmEl_bAcvElCnsReq == 0)
      			{
      				ISCAN_u8N2F468PM1455 = 1;
      			}
      			else
      			{
      				ISCAN_u8N2F468PM1455 = 2;
      			}
			Com_SendSignal(Com_DMD_ACT_CONS_SEEM_CMM_468, (void*) &ISCAN_u8N2F468PM1455);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_u8N5F468PM1440 = 0;
			Com_SendSignal(Com_PRESSION_SURAL_CMM_468, (void*) &ISCAN_u8N5F468PM1440);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub5 = 0;
			Com_SendSignal(Com_LIBRE_1_CMM_468, (void*) &ISCAN_bF468FreOrStub5);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_PBkind8N3F468FreOrStub6 = 6;
			Com_SendSignal(Com_ETAT_PROD_CMM_468, (void*) &ISCAN_PBkind8N3F468FreOrStub6);
      }

		VEMS_vidGET(Ctrl_stElLvlProd, Local_bCtrl_stElLvlProd);
		if (ACTIVATED == Local_bCtrl_stElLvlProd)
		{
			FRM_bInhF468P346_in = GDGAR_bGetFRM(FRM_FRM_INHF468P346);
			if (FRM_bInhF468P346_in == FALSE)
			{
               VEMS_vidGET(CoOptmEl_stElLvlProd,
                           u8LocalCoOptmEl_stElLvlProd);
               ISCAN_u8N3F468P346 = (uint8)(MATHSRV_udtMIN(u8LocalCoOptmEl_stElLvlProd,
                                                      7));
			}
			else
			{
				ISCAN_u8N3F468P346 = 7;
			}
			Com_SendSignal(Com_NIV_PROD_GEN_CMM_468, (void*) &ISCAN_u8N3F468P346);
      }

		VEMS_vidGET(Ctrl_uReqProdElec, Local_bCtrl_uReqProdElec);
		if (ACTIVATED == Local_bCtrl_uReqProdElec)
		{
			FRM_bInhF468P347_in = GDGAR_bGetFRM(FRM_FRM_INHF468P347);
			if (FRM_bInhF468P347_in == FALSE)
			{
               VEMS_vidGET(ElProdMgt_uElProdSp,
                           u16LocalElProdMgt_uElProdSp);
               s32LocalIscanCMM_468 = (sint32)(((5 * u16LocalElProdMgt_uElProdSp) / 64) - 106);
               ISCAN_u8N6F468P347 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_468,
                                                        0,
                                                        54));
			}
			else
			{
				ISCAN_u8N6F468P347 = 63;
			}
			Com_SendSignal(Com_CNS_U_REG_ALTERN_CMM_468, (void*) &ISCAN_u8N6F468P347);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub7 = 0;
			Com_SendSignal(Com_DEFAUT_PROD_CMM_468, (void*) &ISCAN_bF468FreOrStub7);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub8 = 0;
			Com_SendSignal(Com_DMD_REL_R1_CMM_468, (void*) &ISCAN_bF468FreOrStub8);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub9 = 0;
			Com_SendSignal(Com_DMD_REL_R2_CMM_468, (void*) &ISCAN_bF468FreOrStub9);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub10 = 0;
			Com_SendSignal(Com_DMD_REL_R3_CMM_468, (void*) &ISCAN_bF468FreOrStub10);
      }

		VEMS_vidGET(Ctrl_bAuthCrawl, Local_bCtrl_bAuthCrawl);
		if (ACTIVATED == Local_bCtrl_bAuthCrawl)
		{
               VEMS_vidGET(CoPt_bAuthCrawl,
                           bLocalCoPt_bAuthCrawl);
               ISCAN_bF468PM1322 = bLocalCoPt_bAuthCrawl;
			Com_SendSignal(Com_AUTORISATION_RAMPAGE_CMM_468, (void*) &ISCAN_bF468PM1322);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_PBkind8N2F468FreOrStub11 = 0;
			Com_SendSignal(Com_AUTOR_CMM_DAE_CMM_468, (void*) &ISCAN_PBkind8N2F468FreOrStub11);
      }

		VEMS_vidGET(Ctrl_bWupAcv, Local_bCtrl_bWupAcv);
		if (ACTIVATED == Local_bCtrl_bWupAcv)
		{
               VEMS_vidGET(CoOptmEl_bWupAcv,
                           bLocalCoOptmEl_bWupAcv);
               ISCAN_bF468PM1442 = bLocalCoOptmEl_bWupAcv;
			Com_SendSignal(Com_ETAT_ACTIV_WARMUP_CMM_468, (void*) &ISCAN_bF468PM1442);
      }

		VEMS_vidGET(Ctrl_stElEProv, Local_bCtrl_stElEProv);
		if (ACTIVATED == Local_bCtrl_stElEProv)
		{
               VEMS_vidGET(CoOptmEl_stElEProv,
                           u8LocalCoOptmEl_stElEProv);
               ISCAN_u8N4F468PM1443 = (uint8)(MATHSRV_udtMIN(u8LocalCoOptmEl_stElEProv,
                                                      15));
			Com_SendSignal(Com_ETAT_FEE_CMM_468, (void*) &ISCAN_u8N4F468PM1443);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub12 = 0;
			Com_SendSignal(Com_DELEST_SECU_MOT_NIV1_CMM_468, (void*) &ISCAN_bF468FreOrStub12);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub13 = 0;
			Com_SendSignal(Com_LIBRE_1_CMM_468, (void*) &ISCAN_bF468FreOrStub13);
      }

		VEMS_vidGET(Ctrl_stReqBlsVoltCtl, Local_bCtrl_stReqBlsVoltCtl);
		if (ACTIVATED == Local_bCtrl_stReqBlsVoltCtl)
		{
               VEMS_vidGET(TqLimUH_stReqBlsVoltCtl,
                           u8LocalTqLimUH_stReqBlsVoltCtl);
               ISCAN_u8N2F468PM1417 = (uint8)(MATHSRV_udtMIN(u8LocalTqLimUH_stReqBlsVoltCtl,
                                                      3));
			Com_SendSignal(Com_DMD_LEST_PROD_EE_CMM_468, (void*) &ISCAN_u8N2F468PM1417);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub14 = 0;
			Com_SendSignal(Com_REQ_LAMPE_DEF_VIDE_CMM_468, (void*) &ISCAN_bF468FreOrStub14);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub15 = 0;
			Com_SendSignal(Com_DDE_DELEST_STTA_CMM_468, (void*) &ISCAN_bF468FreOrStub15);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub16 = 0;
			Com_SendSignal(Com_IMMINENCE_STOP_MTH_CMM_468, (void*) &ISCAN_bF468FreOrStub16);
      }

		VEMS_vidGET(Ctrl_CMM_468, Local_bCtrl_CMM_468);
		if (ACTIVATED == Local_bCtrl_CMM_468)
		{
				ISCAN_bF468FreOrStub17 = 0;
			Com_SendSignal(Com_LIBRE_1_CMM_468, (void*) &ISCAN_bF468FreOrStub17);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

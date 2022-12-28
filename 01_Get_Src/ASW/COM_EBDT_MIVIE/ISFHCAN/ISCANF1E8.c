/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF1E8.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF1E8.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_1E8(void)
{
	ISCAN_u8N2F1E8P413 = 1;
	ISCAN_u8N2F1E8P700 = 0;
	ISCAN_bF1E8P701 = 1;
	ISCAN_u8N2F1E8PM1390 = 0;
	ISCAN_bF1E8FreOrStub1 = 0;
	ISCAN_u8N2F1E8P234 = 3;
	ISCAN_bF1E8FreOrStub2 = 0;
	ISCAN_u8N2F1E8PM1430 = 3;
	ISCAN_bF1E8FreOrStub3 = 0;
	ISCAN_bF1E8FreOrStub4 = 0;
	ISCAN_bF1E8FreOrStub5 = 0;
	ISCAN_PBkind8N8F1E8FreOrStub6 = 0;
	ISCAN_u8N7F1E8PM1356 = 70;
	ISCAN_bF1E8FreOrStub7 = 0;
	ISCAN_u8N6F1E8PM1389 = 0;
	ISCAN_PBkind8N2F1E8FreOrStub8 = 0;
	ISCAN_PBkind8N8F1E8FreOrStub9 = 0;
}


void ISCAN_vidEve_Tx_1E8(void)
{
	boolean Local_bCtrl_CMM_1E8;
	boolean Local_bCtrl_bRStrtAnt;
	boolean Local_bCtrl_stPosnFSFReq;
	boolean Local_bCtrl_bPosnFSF;
	boolean Local_bCtrl_stTypEmPredRstrt;
	boolean Local_bCtrl_bAcv_ctStaAcv;
	boolean Local_bCtrl_stAcvWarn;
	boolean Local_bCtrl_stPosnCoVlvEstim;
	boolean Local_bCtrl_uEmPredRstrt;
	boolean Local_bCtrl_facSen_uEmPredRstrt;
	boolean FRM_bInhF1E8PM1390_in;
	boolean FRM_bInhF1E8PM1430_in;
	boolean FRM_bInhF1E8PM1356_in;
	boolean FRM_bInhF1E8PM1389_in;
   boolean bLocalCoPtUH_bRStrtAnt;

   uint8 u8LocalThMgt_stPosnFSF;
   boolean bLocalThMgt_bPosnFSF;
   uint8 u8LocalCoEmSTT_stTypEmPredRstrt;
   uint32 u32LocalAraMth_ctStaAcv;
   uint32 u32LocalIscanCMM_1E8;
   uint8 u8LocalECU_stAcvWarn;
   uint8 u8LocalThMgt_stPosnCoVlvEstim;
   uint8 u8LocalCoEmSTT_uEmPredRstrt;
   sint16 s16LocalIscanCMM_1E8;
   uint8 u8LocalCoEmSTT_facSen_uEmPredRstrt;
   uint16 u16LocalIscanCMM_1E8;

	VEMS_vidGET(Ctrl_CMM_1E8, Local_bCtrl_CMM_1E8);
	if (ACTIVATED == Local_bCtrl_CMM_1E8)
	{
		VEMS_vidGET(Ctrl_bRStrtAnt, Local_bCtrl_bRStrtAnt);
		if (ACTIVATED == Local_bCtrl_bRStrtAnt)
		{
            VEMS_vidGET(CoPtUH_bRStrtAnt, bLocalCoPtUH_bRStrtAnt);
   
      
      			if (bLocalCoPtUH_bRStrtAnt != 0) 
      	        {
      				ISCAN_u8N2F1E8P413 = 2;
      			}
      			else
      			{
      				ISCAN_u8N2F1E8P413 = 1;
      			}
			Com_SendSignal(Com_PREPA_AR_EN_COURS_CMM_1E8, (void*) &ISCAN_u8N2F1E8P413);
      }

		VEMS_vidGET(Ctrl_stPosnFSFReq, Local_bCtrl_stPosnFSFReq);
		if (ACTIVATED == Local_bCtrl_stPosnFSFReq)
		{
               VEMS_vidGET(ThMgt_stPosnFSF,
                           u8LocalThMgt_stPosnFSF);
               ISCAN_u8N2F1E8P700 = (uint8)(MATHSRV_udtMIN(u8LocalThMgt_stPosnFSF,
                                                      3));
			Com_SendSignal(Com_CMD_MEAP_CMM_1E8, (void*) &ISCAN_u8N2F1E8P700);
      }

		VEMS_vidGET(Ctrl_bPosnFSF, Local_bCtrl_bPosnFSF);
		if (ACTIVATED == Local_bCtrl_bPosnFSF)
		{
            VEMS_vidGET(ThMgt_bPosnFSF, bLocalThMgt_bPosnFSF);
   
      
      			if (bLocalThMgt_bPosnFSF != 0) 
      	        {
      				ISCAN_bF1E8P701 = 0;
      			}
      			else
      			{
      				ISCAN_bF1E8P701 = 1;
      			}
			Com_SendSignal(Com_POS_MEAP_SOFT_CMM_1E8, (void*) &ISCAN_bF1E8P701);
      }

		VEMS_vidGET(Ctrl_stTypEmPredRstrt, Local_bCtrl_stTypEmPredRstrt);
		if (ACTIVATED == Local_bCtrl_stTypEmPredRstrt)
		{
			FRM_bInhF1E8PM1390_in = GDGAR_bGetFRM(FRM_FRM_INHF1E8PM1390);
			if (FRM_bInhF1E8PM1390_in == FALSE)
			{
               VEMS_vidGET(CoEmSTT_stTypEmPredRstrt,
                           u8LocalCoEmSTT_stTypEmPredRstrt);
               ISCAN_u8N2F1E8PM1390 = (uint8)(MATHSRV_udtMIN(u8LocalCoEmSTT_stTypEmPredRstrt,
                                                      3));
			}
			else
			{
				ISCAN_u8N2F1E8PM1390 = 3;
			}
			Com_SendSignal(Com_TYPAGE_U_SEEM_CMM_1E8, (void*) &ISCAN_u8N2F1E8PM1390);
      }

		VEMS_vidGET(Ctrl_CMM_1E8, Local_bCtrl_CMM_1E8);
		if (ACTIVATED == Local_bCtrl_CMM_1E8)
		{
				ISCAN_bF1E8FreOrStub1 = 0;
			Com_SendSignal(Com_CONS_SOUL_THERM_COMP_CMM_1E8, (void*) &ISCAN_bF1E8FreOrStub1);
      }

		VEMS_vidGET(Ctrl_bAcv_ctStaAcv, Local_bCtrl_bAcv_ctStaAcv);
		if (ACTIVATED == Local_bCtrl_bAcv_ctStaAcv)
		{
               VEMS_vidGET(AraMth_ctStaAcv,
                           u32LocalAraMth_ctStaAcv);
            
               if((UINT32_MAX / 1) < u32LocalAraMth_ctStaAcv)
               {
                  u32LocalIscanCMM_1E8 = (uint32)(((u32LocalAraMth_ctStaAcv) / (50/UINT16_MAX)));
               }
               else
               {
                  u32LocalIscanCMM_1E8 = (uint32)(((u32LocalAraMth_ctStaAcv) / 50));
               }
            
               ISCAN_u16N16F1E8P426 = (uint16)(MATHSRV_udtMIN(u32LocalIscanCMM_1E8,
                                                      65535));
			Com_SendSignal(Com_CPT_NBR_REDEM_CMM_1E8, (void*) &ISCAN_u16N16F1E8P426);
      }

		VEMS_vidGET(Ctrl_stAcvWarn, Local_bCtrl_stAcvWarn);
		if (ACTIVATED == Local_bCtrl_stAcvWarn)
		{
               VEMS_vidGET(ECU_stAcvWarn,
                           u8LocalECU_stAcvWarn);
               ISCAN_u8N2F1E8P234 = (uint8)(MATHSRV_udtMIN(u8LocalECU_stAcvWarn,
                                                      3));
			Com_SendSignal(Com_DEFAUT_CMM_CMM_1E8, (void*) &ISCAN_u8N2F1E8P234);
      }

		VEMS_vidGET(Ctrl_CMM_1E8, Local_bCtrl_CMM_1E8);
		if (ACTIVATED == Local_bCtrl_CMM_1E8)
		{
				ISCAN_bF1E8FreOrStub2 = 0;
			Com_SendSignal(Com_REQ_CHARGE_MOT_CMM_1E8, (void*) &ISCAN_bF1E8FreOrStub2);
      }

		VEMS_vidGET(Ctrl_stPosnCoVlvEstim, Local_bCtrl_stPosnCoVlvEstim);
		if (ACTIVATED == Local_bCtrl_stPosnCoVlvEstim)
		{
			FRM_bInhF1E8PM1430_in = GDGAR_bGetFRM(FRM_FRM_INHF1E8PM1430);
			if (FRM_bInhF1E8PM1430_in == FALSE)
			{
               VEMS_vidGET(ThMgt_stPosnCoVlvEstim,
                           u8LocalThMgt_stPosnCoVlvEstim);
               ISCAN_u8N2F1E8PM1430 = (uint8)(MATHSRV_udtMIN(u8LocalThMgt_stPosnCoVlvEstim,
                                                      3));
			}
			else
			{
				ISCAN_u8N2F1E8PM1430 = 3;
			}
			Com_SendSignal(Com_ETAT_DEBIT_AERO_CMM_1E8, (void*) &ISCAN_u8N2F1E8PM1430);
      }

		VEMS_vidGET(Ctrl_CMM_1E8, Local_bCtrl_CMM_1E8);
		if (ACTIVATED == Local_bCtrl_CMM_1E8)
		{
				ISCAN_bF1E8FreOrStub3 = 1;
			Com_SendSignal(Com_DDE_BOOST_SCR_DEGEL_CMM_1E8, (void*) &ISCAN_bF1E8FreOrStub3);
      }

		VEMS_vidGET(Ctrl_CMM_1E8, Local_bCtrl_CMM_1E8);
		if (ACTIVATED == Local_bCtrl_CMM_1E8)
		{
				ISCAN_bF1E8FreOrStub4 = 0;
			Com_SendSignal(Com_DDE_BOOST_SCR_INJ_CMM_1E8, (void*) &ISCAN_bF1E8FreOrStub4);
      }

		VEMS_vidGET(Ctrl_CMM_1E8, Local_bCtrl_CMM_1E8);
		if (ACTIVATED == Local_bCtrl_CMM_1E8)
		{
				ISCAN_bF1E8FreOrStub5 = 0;
			Com_SendSignal(Com_DDE_TENS_MIN_GMV_CMM_1E8, (void*) &ISCAN_bF1E8FreOrStub5);
      }

		VEMS_vidGET(Ctrl_CMM_1E8, Local_bCtrl_CMM_1E8);
		if (ACTIVATED == Local_bCtrl_CMM_1E8)
		{
				ISCAN_PBkind8N8F1E8FreOrStub6 = 60;
			Com_SendSignal(Com_TEMP_CARB_CMM_1E8, (void*) &ISCAN_PBkind8N8F1E8FreOrStub6);
      }

		VEMS_vidGET(Ctrl_uEmPredRstrt, Local_bCtrl_uEmPredRstrt);
		if (ACTIVATED == Local_bCtrl_uEmPredRstrt)
		{
			FRM_bInhF1E8PM1356_in = GDGAR_bGetFRM(FRM_FRM_INHF1E8PM1356);
			if (FRM_bInhF1E8PM1356_in == FALSE)
			{
               VEMS_vidGET(CoEmSTT_uEmPredRstrt,
                           u8LocalCoEmSTT_uEmPredRstrt);
               s16LocalIscanCMM_1E8 = (sint16)(((5 * u8LocalCoEmSTT_uEmPredRstrt) / 8) - 50);
               ISCAN_u8N7F1E8PM1356 = (uint8)(MATHSRV_udtCLAMP(s16LocalIscanCMM_1E8,
                                                        0,
                                                        110));
			}
			else
			{
				ISCAN_u8N7F1E8PM1356 = 127;
			}
			Com_SendSignal(Com_U_SEEM_REF_CMM_1E8, (void*) &ISCAN_u8N7F1E8PM1356);
      }

		VEMS_vidGET(Ctrl_CMM_1E8, Local_bCtrl_CMM_1E8);
		if (ACTIVATED == Local_bCtrl_CMM_1E8)
		{
				ISCAN_bF1E8FreOrStub7 = 0;
			Com_SendSignal(Com_LIBRE_1_CMM_1E8, (void*) &ISCAN_bF1E8FreOrStub7);
      }

		VEMS_vidGET(Ctrl_facSen_uEmPredRstrt, Local_bCtrl_facSen_uEmPredRstrt);
		if (ACTIVATED == Local_bCtrl_facSen_uEmPredRstrt)
		{
			FRM_bInhF1E8PM1389_in = GDGAR_bGetFRM(FRM_FRM_INHF1E8PM1389);
			if (FRM_bInhF1E8PM1389_in == FALSE)
			{
               VEMS_vidGET(CoEmSTT_facSen_uEmPredRstrt,
                           u8LocalCoEmSTT_facSen_uEmPredRstrt);
               u16LocalIscanCMM_1E8 = (uint16)(((5 * u8LocalCoEmSTT_facSen_uEmPredRstrt) / 6));
               ISCAN_u8N6F1E8PM1389 = (uint8)(MATHSRV_udtMIN(u16LocalIscanCMM_1E8,
                                                      60));
			}
			else
			{
				ISCAN_u8N6F1E8PM1389 = 63;
			}
			Com_SendSignal(Com_K_U_SEEM_CMM_1E8, (void*) &ISCAN_u8N6F1E8PM1389);
      }

		VEMS_vidGET(Ctrl_CMM_1E8, Local_bCtrl_CMM_1E8);
		if (ACTIVATED == Local_bCtrl_CMM_1E8)
		{
				ISCAN_PBkind8N2F1E8FreOrStub8 = 0;
			Com_SendSignal(Com_LIBRE_2_CMM_1E8, (void*) &ISCAN_PBkind8N2F1E8FreOrStub8);
      }

		VEMS_vidGET(Ctrl_CMM_1E8, Local_bCtrl_CMM_1E8);
		if (ACTIVATED == Local_bCtrl_CMM_1E8)
		{
				ISCAN_PBkind8N8F1E8FreOrStub9 = 145;
			Com_SendSignal(Com_TEMP_REGUL_EAU_MOT_CMM_1E8, (void*) &ISCAN_PBkind8N8F1E8FreOrStub9);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

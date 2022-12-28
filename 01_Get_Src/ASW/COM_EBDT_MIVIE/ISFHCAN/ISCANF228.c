/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF228.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF228.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_228(void)
{
	ISCAN_u8N8F228P320 = 50;
	ISCAN_u8N2F228P321 = 0;
	ISCAN_bF228P410 = 0;
	ISCAN_bF228P411 = 0;
	ISCAN_bF228FreOrStub1 = 0;
	ISCAN_PBkind8N3F228FreOrStub2 = 0;
	ISCAN_u8N8F228P334 = 0;
	ISCAN_u8N4F228PM2843 = 0;
	ISCAN_u8N4F228P336 = 0;
	ISCAN_u8N8F228P388 = 254;
	ISCAN_u8N8F228P795 = 254;
	ISCAN_PBkind8N2F228FreOrStub3 = 0;
	ISCAN_bF228FreOrStub4 = 0;
	ISCAN_PBkind8N5F228FreOrStub5 = 0;
	ISCAN_PBkind8N8F228FreOrStub6 = 0;
}

boolean ISCAN_EveTxF228_Callout
(
	PduIdType PduId,
	PduInfoType* PduInfoPtr
)
{
	boolean Local_bCtrl_CMM_228;
	boolean Local_bCtrl_noCks228;
   uint8 u8LocalExt_noCks228;

	CanSecuCalcChecksum(Ext_noCks228IniCks_C,
                        PduInfoPtr->SduDataPtr,
                        (uint8)PduInfoPtr->SduLength,
                        &ISCAN_u8N4F228P336);

	VEMS_vidGET(Ctrl_CMM_228, Local_bCtrl_CMM_228);
	if (ACTIVATED == Local_bCtrl_CMM_228)
	{
		VEMS_vidGET(Ctrl_noCks228, Local_bCtrl_noCks228);
		if (ACTIVATED == Local_bCtrl_noCks228)
		{
         u8LocalExt_noCks228 = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F228P336,
                                                15));
         VEMS_vidSET(Ext_noCks228,
                     u8LocalExt_noCks228);
			Com_SendSignal(Com_CHKSUM_TRME_DYN5_CMM_CMM_228, (void*) &ISCAN_u8N4F228P336);
		}

	}
	return TRUE;
}

void ISCAN_vidEve_Tx_228(void)
{
	boolean Local_bCtrl_CMM_228;
	boolean Local_bCtrl_tqEM;
	boolean Local_bCtrl_bUncrt_tqEM;
	boolean Local_bCtrl_bChaTqCrt;
	boolean Local_bCtrl_bChaTqAvl;
	boolean Local_bCtrl_rAccP;
	boolean Local_bCtrl_ctClcProc228;
	boolean Local_bCtrl_noCks228;
	boolean Local_bCtrl_rCluP;
	boolean Local_bCtrl_pBrkAsi;
	boolean FRM_bInhF228P320_in;
	boolean FRM_bInhF228P334_in;
	boolean FRM_bInhF228P388_in;
	boolean FRM_bInhF228P795_in;
   sint16 s16LocalTqEM_tqEM;
   sint32 s32LocalIscanCMM_228;
   boolean bLocalTqDiag_bUncrt_tqEM;
   boolean bLocalCoTqRStrt_bChaTqCrt;
   boolean bLocalCoTqRStrt_bChaTqAvl;
   uint8 u8LocalAccPEM_rAccP;
   uint8 u8LocalExt_ctClcProc228;
   uint8 u8LocalExt_noCks228;
   uint8 u8LocalExt_rCluP;
   uint16 u16LocalExt_pBrkAsi;
   uint16 u16LocalIscanCMM_228;

	VEMS_vidGET(Ctrl_CMM_228, Local_bCtrl_CMM_228);
	if (ACTIVATED == Local_bCtrl_CMM_228)
	{
		VEMS_vidGET(Ctrl_tqEM, Local_bCtrl_tqEM);
		if (ACTIVATED == Local_bCtrl_tqEM)
		{
			FRM_bInhF228P320_in = GDGAR_bGetFRM(FRM_FRM_INHF228P320);
			if (FRM_bInhF228P320_in == FALSE)
			{
               VEMS_vidGET(TqEM_tqEM,
                           s16LocalTqEM_tqEM);
               s32LocalIscanCMM_228 = (sint32)(((s16LocalTqEM_tqEM) / 32) + 50);
               ISCAN_u8N8F228P320 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_228,
                                                        0,
                                                        254));
			}
			else
			{
				ISCAN_u8N8F228P320 = 255;
			}
			Com_SendSignal(Com_INFO_CPLE_EASY_MOVE_CMM_228, (void*) &ISCAN_u8N8F228P320);
      }

		VEMS_vidGET(Ctrl_bUncrt_tqEM, Local_bCtrl_bUncrt_tqEM);
		if (ACTIVATED == Local_bCtrl_bUncrt_tqEM)
		{
               VEMS_vidGET(TqDiag_bUncrt_tqEM,
                           bLocalTqDiag_bUncrt_tqEM);
               ISCAN_u8N2F228P321 = (uint8)(MATHSRV_udtMIN(bLocalTqDiag_bUncrt_tqEM,
                                                      255));
			Com_SendSignal(Com_CPLE_EM_INCERTAIN_CMM_228, (void*) &ISCAN_u8N2F228P321);
      }

		VEMS_vidGET(Ctrl_bChaTqCrt, Local_bCtrl_bChaTqCrt);
		if (ACTIVATED == Local_bCtrl_bChaTqCrt)
		{
               VEMS_vidGET(CoTqRStrt_bChaTqCrt,
                           bLocalCoTqRStrt_bChaTqCrt);
               ISCAN_bF228P410 = bLocalCoTqRStrt_bChaTqCrt;
			Com_SendSignal(Com_CPLE_MOT_PRECIS_CMM_228, (void*) &ISCAN_bF228P410);
      }

		VEMS_vidGET(Ctrl_bChaTqAvl, Local_bCtrl_bChaTqAvl);
		if (ACTIVATED == Local_bCtrl_bChaTqAvl)
		{
               VEMS_vidGET(CoTqRStrt_bChaTqAvl,
                           bLocalCoTqRStrt_bChaTqAvl);
               ISCAN_bF228P411 = bLocalCoTqRStrt_bChaTqAvl;
			Com_SendSignal(Com_CPLE_DISPO_HILL_ASSIST_CMM_228, (void*) &ISCAN_bF228P411);
      }

		VEMS_vidGET(Ctrl_CMM_228, Local_bCtrl_CMM_228);
		if (ACTIVATED == Local_bCtrl_CMM_228)
		{
				ISCAN_bF228FreOrStub1 = 0;
			Com_SendSignal(Com_POINT_DUR_SECU_CMM_228, (void*) &ISCAN_bF228FreOrStub1);
      }

		VEMS_vidGET(Ctrl_CMM_228, Local_bCtrl_CMM_228);
		if (ACTIVATED == Local_bCtrl_CMM_228)
		{
				ISCAN_PBkind8N3F228FreOrStub2 = 0;
			Com_SendSignal(Com_LIBRE_3_CMM_228, (void*) &ISCAN_PBkind8N3F228FreOrStub2);
      }

		VEMS_vidGET(Ctrl_rAccP, Local_bCtrl_rAccP);
		if (ACTIVATED == Local_bCtrl_rAccP)
		{
			FRM_bInhF228P334_in = GDGAR_bGetFRM(FRM_FRM_INHF228P334);
			if (FRM_bInhF228P334_in == FALSE)
			{
               VEMS_vidGET(AccPEM_rAccP,
                           u8LocalAccPEM_rAccP);
               ISCAN_u8N8F228P334 = (uint8)(MATHSRV_udtMIN(u8LocalAccPEM_rAccP,
                                                      200));
			}
			else
			{
				ISCAN_u8N8F228P334 = 255;
			}
			Com_SendSignal(Com_EFCMNT_PDLE_ACCEL_CMM_228, (void*) &ISCAN_u8N8F228P334);
      }

		VEMS_vidGET(Ctrl_noCks228, Local_bCtrl_noCks228);
		if (ACTIVATED == Local_bCtrl_noCks228)
		{
               VEMS_vidGET(Ext_noCks228,
                           u8LocalExt_noCks228);
               ISCAN_u8N4F228P336 = (uint8)(MATHSRV_udtMIN(u8LocalExt_noCks228,
                                                      15));
			Com_SendSignal(Com_CHKSUM_TRME_DYN5_CMM_CMM_228, (void*) &ISCAN_u8N4F228P336);
      }

		VEMS_vidGET(Ctrl_rCluP, Local_bCtrl_rCluP);
		if (ACTIVATED == Local_bCtrl_rCluP)
		{
			FRM_bInhF228P388_in = GDGAR_bGetFRM(FRM_FRM_INHF228P388);
			if (FRM_bInhF228P388_in == FALSE)
			{
               VEMS_vidGET(Ext_rCluP,
                           u8LocalExt_rCluP);
               ISCAN_u8N8F228P388 = (uint8)(MATHSRV_udtMIN(u8LocalExt_rCluP,
                                                      200));
			}
			else
			{
				ISCAN_u8N8F228P388 = 255;
			}
			Com_SendSignal(Com_POS_PDLE_EMBR_CMM_CMM_228, (void*) &ISCAN_u8N8F228P388);
      }

		VEMS_vidGET(Ctrl_pBrkAsi, Local_bCtrl_pBrkAsi);
		if (ACTIVATED == Local_bCtrl_pBrkAsi)
		{
			FRM_bInhF228P795_in = GDGAR_bGetFRM(FRM_FRM_INHF228P795);
			if (FRM_bInhF228P795_in == FALSE)
			{
               VEMS_vidGET(Ext_pBrkAsi,
                           u16LocalExt_pBrkAsi);
               u16LocalIscanCMM_228 = (uint16)(((u16LocalExt_pBrkAsi) / 5));
               ISCAN_u8N8F228P795 = (uint8)(MATHSRV_udtMIN(u16LocalIscanCMM_228,
                                                      240));
			}
			else
			{
				ISCAN_u8N8F228P795 = 255;
			}
			Com_SendSignal(Com_PRESS_MASTERV_2_HYB_CMM_228, (void*) &ISCAN_u8N8F228P795);
      }

		VEMS_vidGET(Ctrl_CMM_228, Local_bCtrl_CMM_228);
		if (ACTIVATED == Local_bCtrl_CMM_228)
		{
				ISCAN_PBkind8N2F228FreOrStub3 = 0;
			Com_SendSignal(Com_FREEWHEELING_REQ_CMM_228, (void*) &ISCAN_PBkind8N2F228FreOrStub3);
      }

		VEMS_vidGET(Ctrl_CMM_228, Local_bCtrl_CMM_228);
		if (ACTIVATED == Local_bCtrl_CMM_228)
		{
				ISCAN_bF228FreOrStub4 = 1;
			Com_SendSignal(Com_AUTORISATION_RDT_CMM_228, (void*) &ISCAN_bF228FreOrStub4);
      }

		VEMS_vidGET(Ctrl_CMM_228, Local_bCtrl_CMM_228);
		if (ACTIVATED == Local_bCtrl_CMM_228)
		{
				ISCAN_PBkind8N5F228FreOrStub5 = 0;
			Com_SendSignal(Com_LIBRE_5_CMM_228, (void*) &ISCAN_PBkind8N5F228FreOrStub5);
      }

		VEMS_vidGET(Ctrl_CMM_228, Local_bCtrl_CMM_228);
		if (ACTIVATED == Local_bCtrl_CMM_228)
		{
				ISCAN_PBkind8N8F228FreOrStub6 = 50;
			Com_SendSignal(Com_CPLE_POT_MAX_INST_CMM_228, (void*) &ISCAN_PBkind8N8F228FreOrStub6);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF208.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF208.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_208(void)
{
	ISCAN_u16N16F208P000 = 65535;
	ISCAN_u8N8F208P003 = 50;
	ISCAN_u8N8F208P002 = 0;
	ISCAN_bF208FreOrStub1 = 0;
	ISCAN_bF208P042 = 0;
	ISCAN_bF208FreOrStub2 = 0;
	ISCAN_bF208P153 = 0;
	ISCAN_u8N2F208P037 = 3;
	ISCAN_bF208P014 = 0;
	ISCAN_bF208FreOrStub3 = 0;
	ISCAN_u8N8F208P262 = 50;
	ISCAN_PBkind8N8F208FreOrStub4 = 0;
	ISCAN_u8N8F208P198 = 50;
}


void ISCAN_vidEve_Tx_208(void)
{
	boolean Local_bCtrl_CMM_208;
	boolean Local_bCtrl_nEng;
	boolean Local_bCtrl_tqCkEngReal;
	boolean Local_bCtrl_rDrvReq;
	boolean Local_bCtrl_bDiagMuxOn;
	boolean Local_bCtrl_bUncrt_tqCkEngReal;
	boolean Local_bCtrl_stVSCtl;
	boolean Local_bCtrl_bSecBrkPedPrssMes;
	boolean Local_bCtrl_tqAirDrvFil;
	boolean Local_bCtrl_tqDrvFil;
	boolean FRM_bInhF208P000_in;
	boolean FRM_bInhF208P003_in;
	boolean FRM_bInhF208P002_in;
	boolean FRM_bInhF208P262_in;
	boolean FRM_bInhF208P198_in;
   uint16 u16LocalExt_nEng;
   uint32 u32LocalIscanCMM_208;
   sint16 s16LocalTqSys_tqCkEngReal;
   sint32 s32LocalIscanCMM_208;
   uint8 u8LocalAccP_rDrvReq;
   boolean bLocalExt_bDiagMuxOn;
   boolean bLocalTqDiag_bUncrt_tqCkEngReal;
   uint8 u8LocalVSCtl_stVSCtl;
   boolean bLocalExt_bSecBrkPedPrssMes;
   sint16 s16LocalCoPt_tqAirDrvFil;
   sint16 s16LocalCoPt_tqDrvFil;

	VEMS_vidGET(Ctrl_CMM_208, Local_bCtrl_CMM_208);
	if (ACTIVATED == Local_bCtrl_CMM_208)
	{
		VEMS_vidGET(Ctrl_nEng, Local_bCtrl_nEng);
		if (ACTIVATED == Local_bCtrl_nEng)
		{
			FRM_bInhF208P000_in = GDGAR_bGetFRM(FRM_FRM_INHF208P000);
			if (FRM_bInhF208P000_in == FALSE)
			{
               VEMS_vidGET(Ext_nEng,
                           u16LocalExt_nEng);
               u32LocalIscanCMM_208 = (uint32)(8 * u16LocalExt_nEng);
               ISCAN_u16N16F208P000 = (uint16)(MATHSRV_udtMIN(u32LocalIscanCMM_208,
                                                      65534));
			}
			else
			{
				ISCAN_u16N16F208P000 = 65535;
			}
			Com_SendSignal(Com_REGIME_MOTEUR_CMM_208, (void*) &ISCAN_u16N16F208P000);
      }

		VEMS_vidGET(Ctrl_tqCkEngReal, Local_bCtrl_tqCkEngReal);
		if (ACTIVATED == Local_bCtrl_tqCkEngReal)
		{
			FRM_bInhF208P003_in = GDGAR_bGetFRM(FRM_FRM_INHF208P003);
			if (FRM_bInhF208P003_in == FALSE)
			{
               VEMS_vidGET(TqSys_tqCkEngReal,
                           s16LocalTqSys_tqCkEngReal);
               s32LocalIscanCMM_208 = (sint32)(((s16LocalTqSys_tqCkEngReal) / 32) + 50);
               ISCAN_u8N8F208P003 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_208,
                                                        0,
                                                        254));
			}
			else
			{
				ISCAN_u8N8F208P003 = 255;
			}
			Com_SendSignal(Com_COUPLE_REEL_CMM_208, (void*) &ISCAN_u8N8F208P003);
      }

		VEMS_vidGET(Ctrl_rDrvReq, Local_bCtrl_rDrvReq);
		if (ACTIVATED == Local_bCtrl_rDrvReq)
		{
			FRM_bInhF208P002_in = GDGAR_bGetFRM(FRM_FRM_INHF208P002);
			if (FRM_bInhF208P002_in == FALSE)
			{
               VEMS_vidGET(AccP_rDrvReq,
                           u8LocalAccP_rDrvReq);
               ISCAN_u8N8F208P002 = (uint8)(MATHSRV_udtMIN(u8LocalAccP_rDrvReq,
                                                      200));
			}
			else
			{
				ISCAN_u8N8F208P002 = 255;
			}
			Com_SendSignal(Com_VOLONTE_COND_CMM_208, (void*) &ISCAN_u8N8F208P002);
      }

		VEMS_vidGET(Ctrl_CMM_208, Local_bCtrl_CMM_208);
		if (ACTIVATED == Local_bCtrl_CMM_208)
		{
				ISCAN_bF208FreOrStub1 = 0;
			Com_SendSignal(Com_REQ_CHARGE_MOT_CMM_208, (void*) &ISCAN_bF208FreOrStub1);
      }

		VEMS_vidGET(Ctrl_bDiagMuxOn, Local_bCtrl_bDiagMuxOn);
		if (ACTIVATED == Local_bCtrl_bDiagMuxOn)
		{
               VEMS_vidGET(Ext_bDiagMuxOn,
                           bLocalExt_bDiagMuxOn);
               ISCAN_bF208P042 = bLocalExt_bDiagMuxOn;
			Com_SendSignal(Com_DIAG_MUX_ON_CMM_208, (void*) &ISCAN_bF208P042);
      }

		VEMS_vidGET(Ctrl_CMM_208, Local_bCtrl_CMM_208);
		if (ACTIVATED == Local_bCtrl_CMM_208)
		{
				ISCAN_bF208FreOrStub2 = 0;
			Com_SendSignal(Com_FIGEAGE_PERTURB_CPLE_CMM_208, (void*) &ISCAN_bF208FreOrStub2);
      }

		VEMS_vidGET(Ctrl_bUncrt_tqCkEngReal, Local_bCtrl_bUncrt_tqCkEngReal);
		if (ACTIVATED == Local_bCtrl_bUncrt_tqCkEngReal)
		{
               VEMS_vidGET(TqDiag_bUncrt_tqCkEngReal,
                           bLocalTqDiag_bUncrt_tqCkEngReal);
               ISCAN_bF208P153 = bLocalTqDiag_bUncrt_tqCkEngReal;
			Com_SendSignal(Com_CPLE_MT_INCERTAINS_CMM_208, (void*) &ISCAN_bF208P153);
      }

		VEMS_vidGET(Ctrl_stVSCtl, Local_bCtrl_stVSCtl);
		if (ACTIVATED == Local_bCtrl_stVSCtl)
		{
               VEMS_vidGET(VSCtl_stVSCtl,
                           u8LocalVSCtl_stVSCtl);
               ISCAN_u8N2F208P037 = (uint8)(MATHSRV_udtMIN(u8LocalVSCtl_stVSCtl,
                                                      3));
			Com_SendSignal(Com_ETAT_RVV_LVV_CMM_208, (void*) &ISCAN_u8N2F208P037);
      }

		VEMS_vidGET(Ctrl_bSecBrkPedPrssMes, Local_bCtrl_bSecBrkPedPrssMes);
		if (ACTIVATED == Local_bCtrl_bSecBrkPedPrssMes)
		{
               VEMS_vidGET(Ext_bSecBrkPedPrssMes,
                           bLocalExt_bSecBrkPedPrssMes);
               ISCAN_bF208P014 = bLocalExt_bSecBrkPedPrssMes;
			Com_SendSignal(Com_CONTACT_FREIN2_CMM_208, (void*) &ISCAN_bF208P014);
      }

		VEMS_vidGET(Ctrl_CMM_208, Local_bCtrl_CMM_208);
		if (ACTIVATED == Local_bCtrl_CMM_208)
		{
				ISCAN_bF208FreOrStub3 = 0;
			Com_SendSignal(Com_AC_OUT_CMM_208, (void*) &ISCAN_bF208FreOrStub3);
      }

		VEMS_vidGET(Ctrl_tqAirDrvFil, Local_bCtrl_tqAirDrvFil);
		if (ACTIVATED == Local_bCtrl_tqAirDrvFil)
		{
			FRM_bInhF208P262_in = GDGAR_bGetFRM(FRM_FRM_INHF208P262);
			if (FRM_bInhF208P262_in == FALSE)
			{
               VEMS_vidGET(CoPt_tqAirDrvFil,
                           s16LocalCoPt_tqAirDrvFil);
               s32LocalIscanCMM_208 = (sint32)(((s16LocalCoPt_tqAirDrvFil) / 32) + 50);
               ISCAN_u8N8F208P262 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_208,
                                                        0,
                                                        254));
			}
			else
			{
				ISCAN_u8N8F208P262 = 255;
			}
			Com_SendSignal(Com_CPLE_POT_APR_TRT_CMM_208, (void*) &ISCAN_u8N8F208P262);
      }

		VEMS_vidGET(Ctrl_CMM_208, Local_bCtrl_CMM_208);
		if (ACTIVATED == Local_bCtrl_CMM_208)
		{
				ISCAN_PBkind8N8F208FreOrStub4 = 50;
			Com_SendSignal(Com_CPLE_ANTICIPE_CMM_208, (void*) &ISCAN_PBkind8N8F208FreOrStub4);
      }

		VEMS_vidGET(Ctrl_tqDrvFil, Local_bCtrl_tqDrvFil);
		if (ACTIVATED == Local_bCtrl_tqDrvFil)
		{
			FRM_bInhF208P198_in = GDGAR_bGetFRM(FRM_FRM_INHF208P198);
			if (FRM_bInhF208P198_in == FALSE)
			{
               VEMS_vidGET(CoPt_tqDrvFil,
                           s16LocalCoPt_tqDrvFil);
               s32LocalIscanCMM_208 = (sint32)(((s16LocalCoPt_tqDrvFil) / 32) + 50);
               ISCAN_u8N8F208P198 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_208,
                                                        0,
                                                        254));
			}
			else
			{
				ISCAN_u8N8F208P198 = 255;
			}
			Com_SendSignal(Com_CPLE_COND_APR_TRT_CMM_208, (void*) &ISCAN_u8N8F208P198);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

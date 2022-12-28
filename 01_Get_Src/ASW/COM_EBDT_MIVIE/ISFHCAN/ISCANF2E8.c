/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF2E8.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF2E8.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_2E8(void)
{
	ISCAN_u8N8F2E8P462 = 50;
	ISCAN_u8N8F2E8P463 = 0;
	ISCAN_u8N4F2E8P464 = 15;
	ISCAN_u8N4F2E8P465 = 0;
	ISCAN_u8N2F2E8P466 = 0;
	ISCAN_bF2E8P467 = 0;
	ISCAN_PBkind8N5F2E8FreOrStub1 = 0;
}


void ISCAN_vidEve_Tx_2E8(void)
{
	boolean Local_bCtrl_CMM_BV_2E8;
	boolean Local_bCtrl_tqWhlPTPotReq;
	boolean Local_bCtrl_bAccPTra;
	boolean Local_bCtrl_noGearReqMax;
	boolean Local_bCtrl_noGearReqMin;
	boolean Local_bCtrl_stGearCtlReq;
	boolean Local_bCtrl_bCtlEfc_tqWhlPt;
	boolean FRM_bInhF2E8P462_in;
	boolean FRM_bInhF2E8P463_in;
   sint16 s16LocalVSCtl_tqWhlPTPotReq;
   sint32 s32LocalIscanCMM_BV_2E8;
   uint16 u16LocalAccP_rAccP;
   uint16 u16LocalIscanCMM_BV_2E8;
   uint8 u8LocalVSCtl_noGearReqMax;
   uint8 u8LocalVSCtl_noGearReqMin;
   uint8 u8LocalVSCtl_stGearCtlReq;
   boolean bLocalVSCtl_bCtlEfc_tqWhlPt;

	VEMS_vidGET(Ctrl_CMM_BV_2E8, Local_bCtrl_CMM_BV_2E8);
	if (ACTIVATED == Local_bCtrl_CMM_BV_2E8)
	{
		VEMS_vidGET(Ctrl_tqWhlPTPotReq, Local_bCtrl_tqWhlPTPotReq);
		if (ACTIVATED == Local_bCtrl_tqWhlPTPotReq)
		{
			FRM_bInhF2E8P462_in = GDGAR_bGetFRM(FRM_FRM_INHF2E8P462);
			if (FRM_bInhF2E8P462_in == FALSE)
			{
               VEMS_vidGET(VSCtl_tqWhlPTPotReq,
                           s16LocalVSCtl_tqWhlPTPotReq);
               s32LocalIscanCMM_BV_2E8 = (sint32)(((s16LocalVSCtl_tqWhlPTPotReq) / 40) + 50);
               ISCAN_u8N8F2E8P462 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_BV_2E8,
                                                        0,
                                                        250));
			}
			else
			{
				ISCAN_u8N8F2E8P462 = 255;
			}
			Com_SendSignal(Com_CNS_POT_CPLE_ROUE_GMP_ABS_CMM_BV_2E8, (void*) &ISCAN_u8N8F2E8P462);
      }

		VEMS_vidGET(Ctrl_bAccPTra, Local_bCtrl_bAccPTra);
		if (ACTIVATED == Local_bCtrl_bAccPTra)
		{
			FRM_bInhF2E8P463_in = GDGAR_bGetFRM(FRM_FRM_INHF2E8P463);
			if (FRM_bInhF2E8P463_in == FALSE)
			{
               VEMS_vidGET(AccP_rAccP,
                           u16LocalAccP_rAccP);
               u16LocalIscanCMM_BV_2E8 = (uint16)(((u16LocalAccP_rAccP) / 64));
               ISCAN_u8N8F2E8P463 = (uint8)(MATHSRV_udtMIN(u16LocalIscanCMM_BV_2E8,
                                                      200));
			}
			else
			{
				ISCAN_u8N8F2E8P463 = 255;
			}
			Com_SendSignal(Com_POS_ACCEL_COND_GMP_CMM_BV_2E8, (void*) &ISCAN_u8N8F2E8P463);
      }

		VEMS_vidGET(Ctrl_noGearReqMax, Local_bCtrl_noGearReqMax);
		if (ACTIVATED == Local_bCtrl_noGearReqMax)
		{
               VEMS_vidGET(VSCtl_noGearReqMax,
                           u8LocalVSCtl_noGearReqMax);
               ISCAN_u8N4F2E8P464 = (uint8)(MATHSRV_udtMIN(u8LocalVSCtl_noGearReqMax,
                                                      15));
			Com_SendSignal(Com_CNS_RAP_GMP_MAX_CMM_BV_2E8, (void*) &ISCAN_u8N4F2E8P464);
      }

		VEMS_vidGET(Ctrl_noGearReqMin, Local_bCtrl_noGearReqMin);
		if (ACTIVATED == Local_bCtrl_noGearReqMin)
		{
               VEMS_vidGET(VSCtl_noGearReqMin,
                           u8LocalVSCtl_noGearReqMin);
               ISCAN_u8N4F2E8P465 = (uint8)(MATHSRV_udtMIN(u8LocalVSCtl_noGearReqMin,
                                                      15));
			Com_SendSignal(Com_CNS_RAP_GMP_MIN_CMM_BV_2E8, (void*) &ISCAN_u8N4F2E8P465);
      }

		VEMS_vidGET(Ctrl_stGearCtlReq, Local_bCtrl_stGearCtlReq);
		if (ACTIVATED == Local_bCtrl_stGearCtlReq)
		{
               VEMS_vidGET(VSCtl_stGearCtlReq,
                           u8LocalVSCtl_stGearCtlReq);
               ISCAN_u8N2F2E8P466 = (uint8)(MATHSRV_udtMIN(u8LocalVSCtl_stGearCtlReq,
                                                      3));
			Com_SendSignal(Com_STS_PIL_TRANS_GMP_CMM_BV_2E8, (void*) &ISCAN_u8N2F2E8P466);
      }

		VEMS_vidGET(Ctrl_bCtlEfc_tqWhlPt, Local_bCtrl_bCtlEfc_tqWhlPt);
		if (ACTIVATED == Local_bCtrl_bCtlEfc_tqWhlPt)
		{
               VEMS_vidGET(VSCtl_bCtlEfc_tqWhlPt,
                           bLocalVSCtl_bCtlEfc_tqWhlPt);
               ISCAN_bF2E8P467 = bLocalVSCtl_bCtlEfc_tqWhlPt;
			Com_SendSignal(Com_CTRL_CPLE_GMP_ACT_CMM_BV_2E8, (void*) &ISCAN_bF2E8P467);
      }

		VEMS_vidGET(Ctrl_CMM_BV_2E8, Local_bCtrl_CMM_BV_2E8);
		if (ACTIVATED == Local_bCtrl_CMM_BV_2E8)
		{
				ISCAN_PBkind8N5F2E8FreOrStub1 = 0;
			Com_SendSignal(Com_LIBRE_5_CMM_BV_2E8, (void*) &ISCAN_PBkind8N5F2E8FreOrStub1);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

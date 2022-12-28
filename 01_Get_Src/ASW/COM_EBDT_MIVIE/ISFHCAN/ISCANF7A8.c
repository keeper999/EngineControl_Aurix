/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF7A8.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF7A8.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_7A8(void)
{
	ISCAN_u8N6F7A8PM1451 = 46;
	ISCAN_u8N6F7A8PM1452 = 16;
	ISCAN_u8N7F7A8PM1453 = 9;
	ISCAN_u8N7F7A8PM1454 = 9;
	ISCAN_PBkind8N6F7A8FreOrStub1 = 0;
}


void ISCAN_vidEve_Tx_7A8(void)
{
	boolean Local_bCtrl_CMM_7A8;
	boolean Local_bCtrl_bAcv_uMax;
	boolean Local_bCtrl_bAcv_uMinInc;
	boolean Local_bCtrl_bAcv_grdNegSlop;
	boolean Local_bCtrl_bAcv_grdPosSlop;
   uint16 u16LocalCoOptmEl_uMax;
   sint32 s32LocalIscanCMM_7A8;
   uint16 u16LocalCoOptmEl_uMinInc;
   uint8 u8LocalCoOptmEl_grdNegSlop;
   sint16 s16LocalIscanCMM_7A8;
   uint8 u8LocalCoOptmEl_grdPosSlop;

	VEMS_vidGET(Ctrl_CMM_7A8, Local_bCtrl_CMM_7A8);
	if (ACTIVATED == Local_bCtrl_CMM_7A8)
	{
		VEMS_vidGET(Ctrl_bAcv_uMax, Local_bCtrl_bAcv_uMax);
		if (ACTIVATED == Local_bCtrl_bAcv_uMax)
		{
               VEMS_vidGET(CoOptmEl_uMax,
                           u16LocalCoOptmEl_uMax);
               s32LocalIscanCMM_7A8 = (sint32)(((5 * u16LocalCoOptmEl_uMax) / 64) - 106);
               ISCAN_u8N6F7A8PM1451 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_7A8,
                                                        0,
                                                        54));
			Com_SendSignal(Com_U_MAX_CNS_CMM_7A8, (void*) &ISCAN_u8N6F7A8PM1451);
      }

		VEMS_vidGET(Ctrl_bAcv_uMinInc, Local_bCtrl_bAcv_uMinInc);
		if (ACTIVATED == Local_bCtrl_bAcv_uMinInc)
		{
               VEMS_vidGET(CoOptmEl_uMinInc,
                           u16LocalCoOptmEl_uMinInc);
               s32LocalIscanCMM_7A8 = (sint32)(((5 * u16LocalCoOptmEl_uMinInc) / 64) - 106);
               ISCAN_u8N6F7A8PM1452 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_7A8,
                                                        0,
                                                        54));
			Com_SendSignal(Com_U_MIN_CNS_CMM_7A8, (void*) &ISCAN_u8N6F7A8PM1452);
      }

		VEMS_vidGET(Ctrl_bAcv_grdNegSlop, Local_bCtrl_bAcv_grdNegSlop);
		if (ACTIVATED == Local_bCtrl_bAcv_grdNegSlop)
		{
               VEMS_vidGET(CoOptmEl_grdNegSlop,
                           u8LocalCoOptmEl_grdNegSlop);
               s16LocalIscanCMM_7A8 = (sint16)(((5 * u8LocalCoOptmEl_grdNegSlop) / 8));
               ISCAN_u8N7F7A8PM1453 = (uint8)(MATHSRV_udtCLAMP(s16LocalIscanCMM_7A8,
                                                        0,
                                                        99));
			Com_SendSignal(Com_VAR_NEG_MAX_CNS_CMM_7A8, (void*) &ISCAN_u8N7F7A8PM1453);
      }

		VEMS_vidGET(Ctrl_bAcv_grdPosSlop, Local_bCtrl_bAcv_grdPosSlop);
		if (ACTIVATED == Local_bCtrl_bAcv_grdPosSlop)
		{
               VEMS_vidGET(CoOptmEl_grdPosSlop,
                           u8LocalCoOptmEl_grdPosSlop);
               s16LocalIscanCMM_7A8 = (sint16)(((5 * u8LocalCoOptmEl_grdPosSlop) / 8));
               ISCAN_u8N7F7A8PM1454 = (uint8)(MATHSRV_udtCLAMP(s16LocalIscanCMM_7A8,
                                                        0,
                                                        99));
			Com_SendSignal(Com_VAR_POS_MAX_CNS_CMM_7A8, (void*) &ISCAN_u8N7F7A8PM1454);
      }

		VEMS_vidGET(Ctrl_CMM_7A8, Local_bCtrl_CMM_7A8);
		if (ACTIVATED == Local_bCtrl_CMM_7A8)
		{
				ISCAN_PBkind8N6F7A8FreOrStub1 = 0;
			Com_SendSignal(Com_LIBRE_6_CMM_7A8, (void*) &ISCAN_PBkind8N6F7A8FreOrStub1);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

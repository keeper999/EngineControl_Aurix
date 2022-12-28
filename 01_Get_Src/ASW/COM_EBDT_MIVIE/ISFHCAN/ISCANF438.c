/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF438.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF438.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_438(void)
{
	ISCAN_u8N8F438PM1438 = 0;
	ISCAN_u16N10F438PM1439 = 500;
	ISCAN_u8N7F438PM1422 = 100;
	ISCAN_u8N7F438PM1456 = 0;
	ISCAN_u16N9F438PM1457 = 0;
	ISCAN_u8N7F438PM1458 = 0;
	ISCAN_u16N9F438PM1459 = 0;
	ISCAN_u8N7F438PM1460 = 0;
}


void ISCAN_vidEve_Tx_438(void)
{
	boolean Local_bCtrl_CMM_438;
	boolean Local_bCtrl_tqMinGBxMsg;
	boolean Local_bCtrl_nEngSpdMaxTq;
	boolean Local_bCtrl_idxPrfGBxMsg;
	boolean Local_bCtrl_bAcv_pwrEngSndModSpt;
	boolean Local_bCtrl_bAcv_rPwrEngSndModSpt;
	boolean Local_bCtrl_bAcv_tqEfcSndModSpt;
	boolean Local_bCtrl_bAcv_rTqEfcSndModSpt;
	boolean FRM_bInhF438PM1438_in;
	boolean FRM_bInhF438PM1439_in;
	boolean FRM_bInhF438PM1456_in;
	boolean FRM_bInhF438PM1457_in;
	boolean FRM_bInhF438PM1458_in;
	boolean FRM_bInhF438PM1459_in;
	boolean FRM_bInhF438PM1460_in;
   sint16 s16LocalCoPt_tqMinGBxMsg;
   sint32 s32LocalIscanCMM_438;
   uint16 u16LocalCoPt_nEngSpdMaxTq;
   uint8 u8LocalCoPt_idxPrfGBxMsg;
   uint16 u16LocalIscanCMM_438;
   uint8 u8LocalTqSys_rBoostPresSndModSpt;
   uint8 u8LocalIscanCMM_438;
   uint16 u16LocalTqSys_pwrEngSndModSpt;
   uint8 u8LocalTqSys_rPwrEngSndModSpt;
   uint16 u16LocalTqSys_tqEfcSndModSpt;
   uint8 u8LocalTqSys_rTqEfcSndModSpt;

	VEMS_vidGET(Ctrl_CMM_438, Local_bCtrl_CMM_438);
	if (ACTIVATED == Local_bCtrl_CMM_438)
	{
		VEMS_vidGET(Ctrl_tqMinGBxMsg, Local_bCtrl_tqMinGBxMsg);
		if (ACTIVATED == Local_bCtrl_tqMinGBxMsg)
		{
			FRM_bInhF438PM1438_in = GDGAR_bGetFRM(FRM_FRM_INHF438PM1438);
			if (FRM_bInhF438PM1438_in == FALSE)
			{
               VEMS_vidGET(CoPt_tqMinGBxMsg,
                           s16LocalCoPt_tqMinGBxMsg);
               s32LocalIscanCMM_438 = (sint32)(((s16LocalCoPt_tqMinGBxMsg) / 32) + 50);
               ISCAN_u8N8F438PM1438 = (uint8)(MATHSRV_udtCLAMP(s32LocalIscanCMM_438,
                                                        0,
                                                        254));
			}
			else
			{
				ISCAN_u8N8F438PM1438 = 255;
			}
			Com_SendSignal(Com_CPLE_MINI_CMM_438, (void*) &ISCAN_u8N8F438PM1438);
      }

		VEMS_vidGET(Ctrl_nEngSpdMaxTq, Local_bCtrl_nEngSpdMaxTq);
		if (ACTIVATED == Local_bCtrl_nEngSpdMaxTq)
		{
			FRM_bInhF438PM1439_in = GDGAR_bGetFRM(FRM_FRM_INHF438PM1439);
			if (FRM_bInhF438PM1439_in == FALSE)
			{
               VEMS_vidGET(CoPt_nEngSpdMaxTq,
                           u16LocalCoPt_nEngSpdMaxTq);
               ISCAN_u16N10F438PM1439 = (uint16)(MATHSRV_udtMIN(u16LocalCoPt_nEngSpdMaxTq,
                                                      600));
			}
			else
			{
				ISCAN_u16N10F438PM1439 = 1023;
			}
			Com_SendSignal(Com_REGIME_CPLE_MAX_CMM_438, (void*) &ISCAN_u16N10F438PM1439);
      }

		VEMS_vidGET(Ctrl_idxPrfGBxMsg, Local_bCtrl_idxPrfGBxMsg);
		if (ACTIVATED == Local_bCtrl_idxPrfGBxMsg)
		{
               VEMS_vidGET(CoPt_idxPrfGBxMsg,
                           u8LocalCoPt_idxPrfGBxMsg);
               u16LocalIscanCMM_438 = (uint16)(((25 * u8LocalCoPt_idxPrfGBxMsg) / 32));
               ISCAN_u8N7F438PM1422 = (uint8)(MATHSRV_udtMIN(u16LocalIscanCMM_438,
                                                      100));
			Com_SendSignal(Com_INDICE_PERFO_CMM_438, (void*) &ISCAN_u8N7F438PM1422);
      }

		VEMS_vidGET(Ctrl_CMM_438, Local_bCtrl_CMM_438);
		if (ACTIVATED == Local_bCtrl_CMM_438)
		{
				ISCAN_u8N7F438PM1456 = 0;
			Com_SendSignal(Com_PRCT_PRESSION_SURAL_CMM_438, (void*) &ISCAN_u8N7F438PM1456);
      }

		VEMS_vidGET(Ctrl_bAcv_pwrEngSndModSpt, Local_bCtrl_bAcv_pwrEngSndModSpt);
		if (ACTIVATED == Local_bCtrl_bAcv_pwrEngSndModSpt)
		{
			FRM_bInhF438PM1457_in = GDGAR_bGetFRM(FRM_FRM_INHF438PM1457);
			if (FRM_bInhF438PM1457_in == FALSE)
			{
               VEMS_vidGET(TqSys_pwrEngSndModSpt,
                           u16LocalTqSys_pwrEngSndModSpt);
               u16LocalIscanCMM_438 = (uint16)(((u16LocalTqSys_pwrEngSndModSpt) / 2));
               ISCAN_u16N9F438PM1457 = (uint16)(MATHSRV_udtMIN(u16LocalIscanCMM_438,
                                                      400));
			}
			else
			{
				ISCAN_u16N9F438PM1457 = 511;
			}
			Com_SendSignal(Com_PUISS_AFF_DYN_CMM_438, (void*) &ISCAN_u16N9F438PM1457);
      }

		VEMS_vidGET(Ctrl_bAcv_rPwrEngSndModSpt, Local_bCtrl_bAcv_rPwrEngSndModSpt);
		if (ACTIVATED == Local_bCtrl_bAcv_rPwrEngSndModSpt)
		{
			FRM_bInhF438PM1458_in = GDGAR_bGetFRM(FRM_FRM_INHF438PM1458);
			if (FRM_bInhF438PM1458_in == FALSE)
			{
               VEMS_vidGET(TqSys_rPwrEngSndModSpt,
                           u8LocalTqSys_rPwrEngSndModSpt);
               u8LocalIscanCMM_438 = (uint8)(((u8LocalTqSys_rPwrEngSndModSpt) / 2));
               ISCAN_u8N7F438PM1458 = (uint8)(MATHSRV_udtMIN(u8LocalIscanCMM_438,
                                                      100));
			}
			else
			{
				ISCAN_u8N7F438PM1458 = 127;
			}
			Com_SendSignal(Com_PRCT_PUISS_AFF_DYN_CMM_438, (void*) &ISCAN_u8N7F438PM1458);
      }

		VEMS_vidGET(Ctrl_bAcv_tqEfcSndModSpt, Local_bCtrl_bAcv_tqEfcSndModSpt);
		if (ACTIVATED == Local_bCtrl_bAcv_tqEfcSndModSpt)
		{
			FRM_bInhF438PM1459_in = GDGAR_bGetFRM(FRM_FRM_INHF438PM1459);
			if (FRM_bInhF438PM1459_in == FALSE)
			{
               VEMS_vidGET(TqSys_tqEfcSndModSpt,
                           u16LocalTqSys_tqEfcSndModSpt);
               ISCAN_u16N9F438PM1459 = (uint16)(MATHSRV_udtMIN(u16LocalTqSys_tqEfcSndModSpt,
                                                      500));
			}
			else
			{
				ISCAN_u16N9F438PM1459 = 511;
			}
			Com_SendSignal(Com_CPLE_AFF_DYN_CMM_438, (void*) &ISCAN_u16N9F438PM1459);
      }

		VEMS_vidGET(Ctrl_bAcv_rTqEfcSndModSpt, Local_bCtrl_bAcv_rTqEfcSndModSpt);
		if (ACTIVATED == Local_bCtrl_bAcv_rTqEfcSndModSpt)
		{
			FRM_bInhF438PM1460_in = GDGAR_bGetFRM(FRM_FRM_INHF438PM1460);
			if (FRM_bInhF438PM1460_in == FALSE)
			{
               VEMS_vidGET(TqSys_rTqEfcSndModSpt,
                           u8LocalTqSys_rTqEfcSndModSpt);
               u8LocalIscanCMM_438 = (uint8)(((u8LocalTqSys_rTqEfcSndModSpt) / 2));
               ISCAN_u8N7F438PM1460 = (uint8)(MATHSRV_udtMIN(u8LocalIscanCMM_438,
                                                      100));
			}
			else
			{
				ISCAN_u8N7F438PM1460 = 127;
			}
			Com_SendSignal(Com_PRCT_CPLE_AFF_DYN_CMM_438, (void*) &ISCAN_u8N7F438PM1460);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

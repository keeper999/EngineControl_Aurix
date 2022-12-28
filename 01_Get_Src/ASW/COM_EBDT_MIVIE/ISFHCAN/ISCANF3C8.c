/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF3C8.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF3C8.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_3C8(void)
{
	ISCAN_u8N2F3C8P428 = 0;
	ISCAN_bF3C8P430 = 1;
	ISCAN_bF3C8P431 = 0;
	ISCAN_u8N2F3C8P412 = 1;
	ISCAN_PBkind16N10F3C8FreOrStub1 = 0;
}


void ISCAN_vidEve_Tx_3C8(void)
{
	boolean Local_bCtrl_STT_CMM_3C8;
	boolean Local_bCtrl_bOpDrvTraReq;
	boolean Local_bCtrl_bRstrtTypAT;
	boolean Local_bCtrl_bStopIp;
	boolean Local_bCtrl_bNeut;
	boolean FRM_bInhF3C8P412_in;
   boolean bLocalCoPtUH_bOpDrvTraReq;
   boolean bLocalCoPtUH_bRStrtTypAT;
   boolean bLocalCoPtSynt_bStopIp;
   boolean bLocalExt_bNeut;

	VEMS_vidGET(Ctrl_STT_CMM_3C8, Local_bCtrl_STT_CMM_3C8);
	if (ACTIVATED == Local_bCtrl_STT_CMM_3C8)
	{
		VEMS_vidGET(Ctrl_bOpDrvTraReq, Local_bCtrl_bOpDrvTraReq);
		if (ACTIVATED == Local_bCtrl_bOpDrvTraReq)
		{
               VEMS_vidGET(CoPtUH_bOpDrvTraReq,
                           bLocalCoPtUH_bOpDrvTraReq);
               ISCAN_u8N2F3C8P428 = (uint8)(MATHSRV_udtMIN(bLocalCoPtUH_bOpDrvTraReq,
                                                      3));
			Com_SendSignal(Com_DDE_OUV_CDT_STT_CMM_3C8, (void*) &ISCAN_u8N2F3C8P428);
      }

		VEMS_vidGET(Ctrl_bRstrtTypAT, Local_bCtrl_bRstrtTypAT);
		if (ACTIVATED == Local_bCtrl_bRstrtTypAT)
		{
               VEMS_vidGET(CoPtUH_bRStrtTypAT,
                           bLocalCoPtUH_bRStrtTypAT);
               ISCAN_bF3C8P430 = bLocalCoPtUH_bRStrtTypAT;
			Com_SendSignal(Com_TYPE_REDEM_STT_CMM_3C8, (void*) &ISCAN_bF3C8P430);
      }

		VEMS_vidGET(Ctrl_bStopIp, Local_bCtrl_bStopIp);
		if (ACTIVATED == Local_bCtrl_bStopIp)
		{
               VEMS_vidGET(CoPtSynt_bStopIp,
                           bLocalCoPtSynt_bStopIp);
               ISCAN_bF3C8P431 = bLocalCoPtSynt_bStopIp;
			Com_SendSignal(Com_ARRET_MOT_EN_COURS_STT_CMM_3C8, (void*) &ISCAN_bF3C8P431);
      }

		VEMS_vidGET(Ctrl_bNeut, Local_bCtrl_bNeut);
		if (ACTIVATED == Local_bCtrl_bNeut)
		{
			FRM_bInhF3C8P412_in = GDGAR_bGetFRM(FRM_FRM_INHF3C8P412);
			if (FRM_bInhF3C8P412_in == FALSE)
			{
            VEMS_vidGET(Ext_bNeut, bLocalExt_bNeut);
   
      
      			if (bLocalExt_bNeut != 0)
      			{
      				ISCAN_u8N2F3C8P412 = 2;
      			}
      			else
      			{
      				ISCAN_u8N2F3C8P412 = 1;
      			}
			}
			else
			{
				ISCAN_u8N2F3C8P412 = 3;
			}
			Com_SendSignal(Com_ETAT_POINT_MORT_STT_CMM_3C8, (void*) &ISCAN_u8N2F3C8P412);
      }

		VEMS_vidGET(Ctrl_STT_CMM_3C8, Local_bCtrl_STT_CMM_3C8);
		if (ACTIVATED == Local_bCtrl_STT_CMM_3C8)
		{
				ISCAN_PBkind16N10F3C8FreOrStub1 = 0;
			Com_SendSignal(Com_LIBRE_STT_CMM_3C8, (void*) &ISCAN_PBkind16N10F3C8FreOrStub1);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

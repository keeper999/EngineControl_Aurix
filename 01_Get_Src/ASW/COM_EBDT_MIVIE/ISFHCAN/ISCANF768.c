/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF768.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF768.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_768(void)
{
   uint8 u8LocalIndex;


	for (u8LocalIndex = 0; u8LocalIndex < 8; u8LocalIndex++)
	{
	   ISCAN_u64N64F768P999[u8LocalIndex] = 0;
	}
	ISCAN_u8N2F768PM1128 = 2;
	ISCAN_u8N2F768PM1127 = 0;
	ISCAN_bF768PM1126 = 0;
	ISCAN_bF768FreOrStub1 = 0;
	ISCAN_u8N2F768PM1125 = 0;
	ISCAN_u32N24F768PM1129 = 0;
	ISCAN_u32N24F768PM1130 = 0;
	ISCAN_u32N32F768PM1132 = 4294967294;
	ISCAN_u32N24F768PM1131 = 0;
	ISCAN_PBkind8N8F768FreOrStub2 = 0;
}


void ISCAN_vidEve_Tx_JDD_CAN_CMM_768(void)
{
	boolean Local_bCtrl_JDD_CAN_CMM_768;
	boolean Local_bCtrl_stJDDEmi;

	VEMS_vidGET(Ctrl_JDD_CAN_CMM_768, Local_bCtrl_JDD_CAN_CMM_768);
	if (ACTIVATED == Local_bCtrl_JDD_CAN_CMM_768)
	{
		VEMS_vidGET(Ctrl_stJDDEmi, Local_bCtrl_stJDDEmi);
		if (ACTIVATED == Local_bCtrl_stJDDEmi)
		{
               VEMS_vidGET1DArray(Ext_stJDDEmi, 8, ISCAN_u64N64F768P999);
			Com_SendSignal(Com_DATA_EMIS_JDD_JDD_CAN_CMM_768, (void*) &ISCAN_u64N64F768P999[0]);
      }

	}
}

void ISCAN_vidEve_Tx_NEW_JDD_CMM_768(void)
{
	boolean Local_bCtrl_NEW_JDD_CMM_768;
	boolean Local_bCtrl_bAcv_stNbFrame;
	boolean Local_bCtrl_bAcv_noIdFrame;
	boolean Local_bCtrl_bDft;
	boolean Local_bCtrl_bTypMsg;
	boolean Local_bCtrl_stDftCod;
	boolean Local_bCtrl_bAcv_noJDDKm;
	boolean Local_bCtrl_tiVehCnt;
	boolean Local_bCtrl_bAcv_stLifeJDD;
	boolean FRM_bInhF768PM1130_in;
	boolean FRM_bInhF768PM1132_in;
   uint8 u8LocalJbsi_nombre_trame;
   uint8 u8LocalJbsi_numero_trame;
   boolean bLocalExt_bDft;
   uint8 u8LocalJbsi_type_message;
   uint32 u32LocalJbsi_code_defaut;
   uint32 u32LocalJbsi_kilometrage;
   uint32 u32LocalJbsi_ref_horaire;
   uint32 u32LocalExt_stLifeJDD;

	VEMS_vidGET(Ctrl_NEW_JDD_CMM_768, Local_bCtrl_NEW_JDD_CMM_768);
	if (ACTIVATED == Local_bCtrl_NEW_JDD_CMM_768)
	{
		VEMS_vidGET(Ctrl_bAcv_stNbFrame, Local_bCtrl_bAcv_stNbFrame);
		if (ACTIVATED == Local_bCtrl_bAcv_stNbFrame)
		{
               VEMS_vidGET(Jbsi_nombre_trame,
                           u8LocalJbsi_nombre_trame);
               ISCAN_u8N2F768PM1128 = (uint8)(MATHSRV_udtMIN(u8LocalJbsi_nombre_trame,
                                                      3));
			Com_SendSignal(Com_NOMBRE_TRAMES_NEW_JDD_CMM_768, (void*) &ISCAN_u8N2F768PM1128);
      }

		VEMS_vidGET(Ctrl_bDft, Local_bCtrl_bDft);
		if (ACTIVATED == Local_bCtrl_bDft)
		{
               VEMS_vidGET(Ext_bDft,
                           bLocalExt_bDft);
               ISCAN_bF768PM1126 = bLocalExt_bDft;
			Com_SendSignal(Com_ETAT_DTC_NEW_JDD_CMM_768, (void*) &ISCAN_bF768PM1126);
      }

		VEMS_vidGET(Ctrl_NEW_JDD_CMM_768, Local_bCtrl_NEW_JDD_CMM_768);
		if (ACTIVATED == Local_bCtrl_NEW_JDD_CMM_768)
		{
				ISCAN_bF768FreOrStub1 = 0;
			Com_SendSignal(Com_RESERVE_1_NEW_JDD_CMM_768, (void*) &ISCAN_bF768FreOrStub1);
      }

		VEMS_vidGET(Ctrl_bTypMsg, Local_bCtrl_bTypMsg);
		if (ACTIVATED == Local_bCtrl_bTypMsg)
		{
               VEMS_vidGET(Jbsi_type_message,
                           u8LocalJbsi_type_message);
               ISCAN_u8N2F768PM1125 = (uint8)(MATHSRV_udtMIN(u8LocalJbsi_type_message,
                                                      3));
			Com_SendSignal(Com_TYPE_MESSAGE_NEW_JDD_CMM_768, (void*) &ISCAN_u8N2F768PM1125);
      }

		VEMS_vidGET(Ctrl_stDftCod, Local_bCtrl_stDftCod);
		if (ACTIVATED == Local_bCtrl_stDftCod)
		{
			if (ISCAN_u8N2F768PM1127 == 0x01)
         {
               VEMS_vidGET(Jbsi_code_defaut,
                           u32LocalJbsi_code_defaut);
               ISCAN_u32N24F768PM1129 = (uint32)(MATHSRV_udtMIN(u32LocalJbsi_code_defaut,
                                                      16777215));
   			Com_SendSignal(Com_CODES_DEFAUT_NEW_JDD_CMM_768, (void*) &ISCAN_u32N24F768PM1129);
         }
      }

		VEMS_vidGET(Ctrl_bAcv_noJDDKm, Local_bCtrl_bAcv_noJDDKm);
		if (ACTIVATED == Local_bCtrl_bAcv_noJDDKm)
		{
			if (ISCAN_u8N2F768PM1127 == 0x02)
         {
   			FRM_bInhF768PM1130_in = GDGAR_bGetFRM(FRM_FRM_INHF768PM1130);
   			if (FRM_bInhF768PM1130_in == FALSE)
   			{
               VEMS_vidGET(Jbsi_kilometrage,
                           u32LocalJbsi_kilometrage);
               ISCAN_u32N24F768PM1130 = (uint32)(MATHSRV_udtMIN(u32LocalJbsi_kilometrage,
                                                      16777214));
   			}
   			else
   			{
   				ISCAN_u32N24F768PM1130 = 16777215;
   			}
   			Com_SendSignal(Com_KILOMETRAGE_JDD_NEW_JDD_CMM_768, (void*) &ISCAN_u32N24F768PM1130);
         }
      }

		VEMS_vidGET(Ctrl_tiVehCnt, Local_bCtrl_tiVehCnt);
		if (ACTIVATED == Local_bCtrl_tiVehCnt)
		{
			if (ISCAN_u8N2F768PM1127 == 0x01)
         {
   			FRM_bInhF768PM1132_in = GDGAR_bGetFRM(FRM_FRM_INHF768PM1132);
   			if (FRM_bInhF768PM1132_in == FALSE)
   			{
               VEMS_vidGET(Jbsi_ref_horaire,
                           u32LocalJbsi_ref_horaire);
               ISCAN_u32N32F768PM1132 = (uint32)(MATHSRV_udtMIN(u32LocalJbsi_ref_horaire,
                                                      4294967293));
   			}
   			else
   			{
   				ISCAN_u32N32F768PM1132 = 4294967295;
   			}
            ISCAN_u8F768PM1132_5 = (uint8)((ISCAN_u32N32F768PM1132) >> 24);
            ISCAN_u8F768PM1132_6 = (uint8)(ISCAN_u32N32F768PM1132 >> 16);
            ISCAN_u8F768PM1132_7 = (uint8)(ISCAN_u32N32F768PM1132 >> 8);
            ISCAN_u8F768PM1132_8 = (uint8)(ISCAN_u32N32F768PM1132);

            Com_SendSignal(Com_DATA_BYTE5_CMM_768, (void*) &ISCAN_u8F768PM1132_5);
            Com_SendSignal(Com_DATA_BYTE6_CMM_768, (void*) &ISCAN_u8F768PM1132_6);
            Com_SendSignal(Com_DATA_BYTE7_CMM_768, (void*) &ISCAN_u8F768PM1132_7);
            Com_SendSignal(Com_DATA_BYTE8_CMM_768, (void*) &ISCAN_u8F768PM1132_8);
         }
      }

		VEMS_vidGET(Ctrl_bAcv_stLifeJDD, Local_bCtrl_bAcv_stLifeJDD);
		if (ACTIVATED == Local_bCtrl_bAcv_stLifeJDD)
		{
			if (ISCAN_u8N2F768PM1127 == 0x02)
         {
               VEMS_vidGET(Ext_stLifeJDD,
                           u32LocalExt_stLifeJDD);
               ISCAN_u32N24F768PM1131 = (uint32)(MATHSRV_udtMIN(u32LocalExt_stLifeJDD,
                                                      16777215));
            ISCAN_u8F768PM1131_5 = (uint8)((ISCAN_u32N24F768PM1131) >> 16);
            ISCAN_u8F768PM1131_6 = (uint8)(ISCAN_u32N24F768PM1131 >> 8);
            ISCAN_u8F768PM1131_7 = (uint8)(ISCAN_u32N24F768PM1131);

            Com_SendSignal(Com_DATA_BYTE5_CMM_768, (void*) &ISCAN_u8F768PM1131_5);
            Com_SendSignal(Com_DATA_BYTE6_CMM_768, (void*) &ISCAN_u8F768PM1131_6);
            Com_SendSignal(Com_DATA_BYTE7_CMM_768, (void*) &ISCAN_u8F768PM1131_7);
         }
      }

		VEMS_vidGET(Ctrl_NEW_JDD_CMM_768, Local_bCtrl_NEW_JDD_CMM_768);
		if (ACTIVATED == Local_bCtrl_NEW_JDD_CMM_768)
		{
			if (ISCAN_u8N2F768PM1127 == 0x02)
         {
   				ISCAN_PBkind8N8F768FreOrStub2 = 255;
            Com_SendSignal(Com_DATA_BYTE8_CMM_768, (void*) &ISCAN_PBkind8N8F768FreOrStub2);
         }
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

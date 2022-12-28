/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF0E8.c */
#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "ISCANF0E8.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.H"
#include "VEMS.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.H"

void ISCAN_vidInit_Tx_0E8(void)
{
	ISCAN_u8N8F0E8P841 = 0;
	ISCAN_u8N8F0E8P842 = 0;
	ISCAN_PBkind8N8F0E8FreOrStub1 = 0;
	ISCAN_PBkind8N8F0E8FreOrStub2 = 0;
	ISCAN_PBkind8N8F0E8FreOrStub3 = 0;
	ISCAN_u8N8F0E8P827 = 0;
	ISCAN_u8N8F0E8P839 = 0;
	ISCAN_u8N8F0E8P829 = 0;
	ISCAN_u8N8F0E8P828 = 0;
	ISCAN_u8N8F0E8P838 = 0;
}


void ISCAN_vidEve_Tx_EAC_CMM_UCC_0E8(void)
{
	boolean Local_bCtrl_EAC_CMM_UCC_0E8;
	boolean Local_bCtrl_stCMMStImmoSnd;
	boolean Local_bCtrl_stCMMStImmoReq;
   uint8 u8LocalSAIMMO_IscanBufferPos1;
   uint8 u8LocalSAIMMO_IscanBufferPos2;

	VEMS_vidGET(Ctrl_EAC_CMM_UCC_0E8, Local_bCtrl_EAC_CMM_UCC_0E8);
	if (ACTIVATED == Local_bCtrl_EAC_CMM_UCC_0E8)
	{
		VEMS_vidGET(Ctrl_stCMMStImmoSnd, Local_bCtrl_stCMMStImmoSnd);
		if (ACTIVATED == Local_bCtrl_stCMMStImmoSnd)
		{
               VEMS_vidGET(SAIMMO_IscanBufferPos1,
                           u8LocalSAIMMO_IscanBufferPos1);
               ISCAN_u8N8F0E8P841 = u8LocalSAIMMO_IscanBufferPos1;
			Com_SendSignal(Com_ENVOI_ETAT_CALCULATR_EAC_CMM_UCC_0E8, (void*) &ISCAN_u8N8F0E8P841);
      }

		VEMS_vidGET(Ctrl_stCMMStImmoReq, Local_bCtrl_stCMMStImmoReq);
		if (ACTIVATED == Local_bCtrl_stCMMStImmoReq)
		{
               VEMS_vidGET(SAIMMO_IscanBufferPos2,
                           u8LocalSAIMMO_IscanBufferPos2);
               ISCAN_u8N8F0E8P842 = u8LocalSAIMMO_IscanBufferPos2;
			Com_SendSignal(Com_ETAT_CALCULATR_EAC_CMM_UCC_0E8, (void*) &ISCAN_u8N8F0E8P842);
      }

		VEMS_vidGET(Ctrl_EAC_CMM_UCC_0E8, Local_bCtrl_EAC_CMM_UCC_0E8);
		if (ACTIVATED == Local_bCtrl_EAC_CMM_UCC_0E8)
		{
				ISCAN_PBkind8N8F0E8FreOrStub1 = 0;
			Com_SendSignal(Com_RESERVE_8_EAC_CMM_UCC_0E8, (void*) &ISCAN_PBkind8N8F0E8FreOrStub1);
      }

		VEMS_vidGET(Ctrl_EAC_CMM_UCC_0E8, Local_bCtrl_EAC_CMM_UCC_0E8);
		if (ACTIVATED == Local_bCtrl_EAC_CMM_UCC_0E8)
		{
				ISCAN_PBkind8N8F0E8FreOrStub2 = 0;
			Com_SendSignal(Com_RESERVE_8_EAC_CMM_UCC_0E8, (void*) &ISCAN_PBkind8N8F0E8FreOrStub2);
      }

		VEMS_vidGET(Ctrl_EAC_CMM_UCC_0E8, Local_bCtrl_EAC_CMM_UCC_0E8);
		if (ACTIVATED == Local_bCtrl_EAC_CMM_UCC_0E8)
		{
				ISCAN_PBkind8N8F0E8FreOrStub3 = 0;
			Com_SendSignal(Com_RESERVE_8_EAC_CMM_UCC_0E8, (void*) &ISCAN_PBkind8N8F0E8FreOrStub3);
      }

	}
}

void ISCAN_vidEve_Tx_RQD_CMM_UCC_0E8(void)
{
	boolean Local_bCtrl_RQD_CMM_UCC_0E8;
	boolean Local_bCtrl_stUnBlockReq;
	boolean Local_bCtrl_noCMMSeedImmo;
   uint8 u8LocalSAIMMO_IscanBufferPos1;
   uint8 u8LocalSAIMMO_IscanBufferPos2;
   uint8 u8LocalSAIMMO_IscanBufferPos3;
   uint8 u8LocalSAIMMO_IscanBufferPos4;
   uint8 u8LocalSAIMMO_IscanBufferPos5;

	VEMS_vidGET(Ctrl_RQD_CMM_UCC_0E8, Local_bCtrl_RQD_CMM_UCC_0E8);
	if (ACTIVATED == Local_bCtrl_RQD_CMM_UCC_0E8)
	{
		VEMS_vidGET(Ctrl_stUnBlockReq, Local_bCtrl_stUnBlockReq);
		if (ACTIVATED == Local_bCtrl_stUnBlockReq)
		{
               VEMS_vidGET(SAIMMO_IscanBufferPos1,
                           u8LocalSAIMMO_IscanBufferPos1);
               ISCAN_u8N8F0E8P827 = u8LocalSAIMMO_IscanBufferPos1;
			Com_SendSignal(Com_DDE_DVRRLLGE_RQD_CMM_UCC_0E8, (void*) &ISCAN_u8N8F0E8P827);
      }

		VEMS_vidGET(Ctrl_noCMMSeedImmo, Local_bCtrl_noCMMSeedImmo);
		if (ACTIVATED == Local_bCtrl_noCMMSeedImmo)
		{
               VEMS_vidGET(SAIMMO_IscanBufferPos2,
                           u8LocalSAIMMO_IscanBufferPos2);
               ISCAN_u8N8F0E8P839 = u8LocalSAIMMO_IscanBufferPos2;
			Com_SendSignal(Com_SEED_PDS_PLS_FORT_RQD_CMM_UCC_0E8, (void*) &ISCAN_u8N8F0E8P839);
      }

		VEMS_vidGET(Ctrl_noCMMSeedImmo, Local_bCtrl_noCMMSeedImmo);
		if (ACTIVATED == Local_bCtrl_noCMMSeedImmo)
		{
               VEMS_vidGET(SAIMMO_IscanBufferPos3,
                           u8LocalSAIMMO_IscanBufferPos3);
               ISCAN_u8N8F0E8P829 = u8LocalSAIMMO_IscanBufferPos3;
			Com_SendSignal(Com_SEED_PDS_FRT_RQD_CMM_UCC_0E8, (void*) &ISCAN_u8N8F0E8P829);
      }

		VEMS_vidGET(Ctrl_noCMMSeedImmo, Local_bCtrl_noCMMSeedImmo);
		if (ACTIVATED == Local_bCtrl_noCMMSeedImmo)
		{
               VEMS_vidGET(SAIMMO_IscanBufferPos4,
                           u8LocalSAIMMO_IscanBufferPos4);
               ISCAN_u8N8F0E8P828 = u8LocalSAIMMO_IscanBufferPos4;
			Com_SendSignal(Com_SEED_PDS_FBLE_RQD_CMM_UCC_0E8, (void*) &ISCAN_u8N8F0E8P828);
      }

		VEMS_vidGET(Ctrl_noCMMSeedImmo, Local_bCtrl_noCMMSeedImmo);
		if (ACTIVATED == Local_bCtrl_noCMMSeedImmo)
		{
               VEMS_vidGET(SAIMMO_IscanBufferPos5,
                           u8LocalSAIMMO_IscanBufferPos5);
               ISCAN_u8N8F0E8P838 = u8LocalSAIMMO_IscanBufferPos5;
			Com_SendSignal(Com_SEED_PDS_PLS_FBLE_RQD_CMM_UCC_0E8, (void*) &ISCAN_u8N8F0E8P838);
      }

	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCPUSR                                                                                          */
/* !Description     : User functions declaration                                                                      */
/*                                                                                                                    */
/* !File            : CCPUSR_CanIf_Cfg.c                                                                              */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
/*                                                                                                                    */
/* !Target          : All                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT 2009 VALEO                                                                                               */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* PVCS Information                                                                                                   */
/* $Archive::   P:/VE_S97/LOG/60_ComponentArchive/Archives/COMP_SWC_BSW_MCAL_MPC5676/Mcal.c_v                        $*/
/* $Revision::   1.7                                                                                                 $*/
/* $Author::   vbecquet                               $$Date::   14 Jun 2012 13:43:52                                $*/
/**********************************************************************************************************************/

#include "Std_Types.h"
#include "CanIf.h"
#include "Ccp.h"
#include "Ccpusr_CanIf_Cfg.h"
#include "CCPUSR.h"
#include "CCPUSR_Cfg.h"


/**********************************************************************************************************************/
/* DATA DEFINITION                                                                                                    */
/**********************************************************************************************************************/
#define CCP_START_SEC_VAR_UNSPECIFIED
#include "Ccp_MemMap.h"

boolean CCPUSR_bSenderIsDevaid;
uint8   CCPUSR_au8RxMessageData[8];

#define CCP_STOP_SEC_VAR_UNSPECIFIED
#include "Ccp_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DEFINITION                                                                                               */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "Ccp_MemMap.h"

/**********************************************************************************************************************/
/* !Description: Send a frame to CanIf                                                                                */
/**********************************************************************************************************************/
LOCAL_INLINE void CCPUSR_vidSendMessage(PduIdType CanTxPduId, const uint8 * pu8DataToSend)
{
   PduInfoType strLocPduInfo;


   strLocPduInfo.SduDataPtr = (uint8 *)pu8DataToSend;
   strLocPduInfo.SduLength  = 8;
   CanIf_Transmit(CanTxPduId, &strLocPduInfo);
}

/**********************************************************************************************************************/
/* !Description: Send DTO answer Frame                                                                                */
/**********************************************************************************************************************/
void CCP_vidUsrTxCmdResp(const uint8 aku8Data[8])
{
   PduIdType udtLocCanTxPduId;


   /* When we will handle two CCP, we have to choose the right LocCanTxPduId value */
   if (CCPUSR_bSenderIsDevaid == TRUE)
   {
      udtLocCanTxPduId = CCPUSR_CANIF_DEVAID_DTO_TX_ID;
   }
   else
   {
      udtLocCanTxPduId = CCPUSR_CANIF_DTO_TX_ID;
   }
   CCPUSR_vidSendMessage(udtLocCanTxPduId, &aku8Data[0]);
}

/**********************************************************************************************************************/
/* !Description: Send DAQ Frame                                                                                       */
/**********************************************************************************************************************/
void CCPUSR_vidSendDaqMessage(uint8 u8DaqId, const uint8 aku8Data[8])
{
   PduIdType udtLocCanTxPduId;


   /* When we will handle two CCP, we have to choose the right LocCanTxPduId value */
   if (CCPUSR_bSenderIsDevaid == TRUE)
   {
      udtLocCanTxPduId = CCPUSR_kaudtDevaidDaqMsgID[u8DaqId];
   }
   else
   {
      udtLocCanTxPduId = CCPUSR_kaudtDaqMsgID[u8DaqId];
   }
   /* When we will handle two CCP, we have to choose the right CanTxPduId value */
   CCPUSR_vidSendMessage(udtLocCanTxPduId, &aku8Data[0]);
}

/**********************************************************************************************************************/
/* !Description: Called by CanIf on Daq list tx confirmation                                                          */
/* CanIf is Configured, automatically by OIL, to pass in argument the DAQ list number.                                */ 
/**********************************************************************************************************************/
void CCPUSR_vidDaqListTxConf(PduIdType CanTxPduId)
{
   CCP_vidDaqListTxMgr((uint8)CanTxPduId);
}

/**********************************************************************************************************************/
/* !Description: Called by Ccp to recover last received data                                                          */
/**********************************************************************************************************************/
void CCP_vidUsrRxCmd(uint8 au8Data[8])
{
   uint8_least u8LocByteIndex;


   for (u8LocByteIndex = 0; u8LocByteIndex < 8; u8LocByteIndex++)
   {
      au8Data[u8LocByteIndex] = CCPUSR_au8RxMessageData[u8LocByteIndex];
   }
}

/**********************************************************************************************************************/
/* !Description: Called by CanIf on CCP frame reception                                                               */
/**********************************************************************************************************************/
STATIC void CCPUSR_vidRxIndication_CRO(PduIdType RxPduId, PduInfoType *PduInfoPtr)
{
   uint8_least u8LocCounter;


   COMPILER_UNUSED_PARAMETER(RxPduId);

   /* Store received data */
   for (u8LocCounter = 0; u8LocCounter < 8; u8LocCounter++)
   {
      CCPUSR_au8RxMessageData[u8LocCounter] = PduInfoPtr->SduDataPtr[u8LocCounter];
   }
   /* Do the action by calling Ccp */
   CCP_vidMonr();
}

void CCP_UsrRxInd_Devaid_CRO(PduIdType RxPduId, PduInfoType *PduInfoPtr)
{
   CCPUSR_bSenderIsDevaid = TRUE;
   CCPUSR_vidRxIndication_CRO(RxPduId, PduInfoPtr);
}

void CCP_UsrRxInd_CRO(PduIdType RxPduId, PduInfoType *PduInfoPtr)
{
   CCPUSR_bSenderIsDevaid = FALSE;
   CCPUSR_vidRxIndication_CRO(RxPduId, PduInfoPtr);
}

/**********************************************************************************************************************/
/* !Description: Called by CanIf on CCP frame transmission                                                            */
/**********************************************************************************************************************/
STATIC void CCPUSR_vidTxConfirmation_DTO(PduIdType CanTxPduId)
{
   COMPILER_UNUSED_PARAMETER(CanTxPduId);
   if (CCPUSR_enuCalStoreStatus == CCPUSR_CAL_STORE_REQUESTED)
   {
      CCPUSR_enuCalStoreStatus = CCPUSR_CAL_STORE_WAIT_CONDITION;
   }
}

void CCP_UsrTxConf_Devaid_DTO (PduIdType CanTxPduId)
{
   CCPUSR_vidTxConfirmation_DTO(CanTxPduId);
} /* DTO frame to remove the notification in CanIf configuration */

void CCP_UsrTxConf_DTO (PduIdType CanTxPduId)
{
   CCPUSR_vidTxConfirmation_DTO(CanTxPduId);
} /* DTO frame to remove the notification in CanIf configuration */

#define CCP_STOP_SEC_CODE
#include "Ccp_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/

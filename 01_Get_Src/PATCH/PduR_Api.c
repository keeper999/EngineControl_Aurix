/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : COM STACK                                               */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PDU Router                                              */
/*                                                                            */
/* !Module          : PduR_Api                                                */
/* !Description     : API of the PduR Component                               */
/*                                                                            */
/* !File            : PduR_Api.c                                              */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : ALL                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEES                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* 1 / PduR_COMINLTransmit                                                    */
/* 2 / PduR_DcmTransmit                                                       */
/* 3 / PduR_DcmCancelTransmitRequest                                          */
/* 4 / PduR_DcmCancelReceiveRequest                                           */
/* 5 / PduR_CanTpCopyRxData                                                   */
/* 6 / PduR_CanTpCopyTxData                                                   */
/* 7 / PduR_CanTpRxIndication                                                 */
/* 8 / PduR_CanTpStartOfReception                                             */
/* 9 / PduR_CanTpTxConfirmation                                               */
/* 10 / PduR_bGetDcmPduId                                                     */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/PduR_Api.c_v                $*/
/* $Revision::   1.1      $$Author::   croche2        $$Date::   01 Sep 2014 $*/
/******************************************************************************/

#include "STD_TYPES.h"
//#include "ComStack_Types.h"
//#include "CanTp.h"
#include "osek_com.h"
#include "PduR.h"
//#include "PduR_Types.h"
//#include "PduR_Cfg.h"

// #define PDUR_START_SEC_CODE
// #include "MemMap.h"

/******************************************************************************/
/* Check that Conditionnal Compilation define are defined                     */
/******************************************************************************/
//#ifndef PDUR_coDCM_INTERFACE
//   #error "Define PDUR_coDCM_INTERFACE is undefined"
//#endif
//
//#ifndef PDUR_coDCM_ENABLED
//   #error "Define PDUR_coDCM_ENABLED is undefined"
//#endif
//
//#ifndef PDUR_coCOMINL_INTERFACE
//   #error "Define PDUR_coCOMINL_INTERFACE is undefined"
//#endif
//
//#ifndef PDUR_coCOMINL_ENABLED
//   #error "Define PDUR_coCOMINL_ENABLED is undefined"
//#endif




//#if (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED)
///*************************** <AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !FuncName    : PduR_COMINLTransmit                                         */
///*                                                                            */
///* !Description :                                                             */
///* !Number      : 0x00                                                        */
///* !Reference   : NONE /                                                      */
///*                                                                            */
///*                                                                            */
///******************************************************************************/
///*                                                                            */
///*                                                                            */
///*                                                                            */
///*                                                                            */
///************************** </AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !LastAuthor  :  Mohamed Mohi                                               */
///************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
//PduR_ReturnType PduR_COMINLTransmit
//(
//   PduIdType udtTxPduId,
//   PduInfoType* pstrPduInfoPointer
//)
//{
//   // PduR_ReturnType udtReturnStatus;
//   // uint8           udtLocalNwlId;
//
//   // udtLocalNwlId = OSEK_COM_udtMsgNwlIdRead(udtTxPduId);
//   // udtReturnStatus = CanTp_Transmit(udtLocalNwlId,pstrPduInfoPointer);
//   return(udtReturnStatus);
//}
//
//
//#endif   /* (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED) */
//
//
//
//
//#if (PDUR_coDCM_INTERFACE == PDUR_coDCM_ENABLED)
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !FuncName    : PduR_DcmTransmit                                            */
/*                                                                            */
/* !Description :                                                             */
/* !Number      : 0x01                                                        */
/* !Reference   : NONE /                                                      */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
PduR_ReturnType PduR_DcmTransmit
(
   PduIdType udtTxPduId,
   PduInfoType* pstrPduInfoPointer
)
{
   PduR_ReturnType udtReturnStatus;
   uint8           udtLocalNwlId;
   uint8           u8LocalDcmConnection;

   udtReturnStatus = E_NOT_OK;
   // for(u8LocalDcmConnection = 0;
       // u8LocalDcmConnection < PDUR_u8NB_OF_DCM_CONNECTIONS;
       // u8LocalDcmConnection++)
   // {
      // if(  udtTxPduId
        // == PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].udtDcmRefTx)
      // {
         // udtLocalNwlId =
            // PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].udtNwlId;
         // udtReturnStatus = CanTp_Transmit(udtLocalNwlId,pstrPduInfoPointer);
      // }
   // }
   return(udtReturnStatus);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !FuncName    : PduR_DcmCancelTransmitRequest                               */
/*                                                                            */
/* !Description :                                                             */
/* !Number      : 0x02                                                        */
/* !Reference   : NONE /                                                      */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
PduR_ReturnType PduR_DcmCancelTransmitRequest
(
   PduIdType udtTxPduId
)
{
   PduR_ReturnType udtReturnStatus;
   uint8           udtLocalNwlId;
   uint8           u8LocalDcmConnection;

   udtReturnStatus = E_NOT_OK;
   // for(u8LocalDcmConnection = 0;
       // u8LocalDcmConnection < PDUR_u8NB_OF_DCM_CONNECTIONS;
       // u8LocalDcmConnection++)
   // {
      // if(  udtTxPduId
        // == PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].udtDcmRefTx)
      // {
         // udtLocalNwlId =
            // PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].udtNwlId;
         // udtReturnStatus = CanTp_CancelTransmitRequest(udtLocalNwlId);
      // }
   // }
   return(udtReturnStatus);
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !FuncName    : PduR_DcmCancelReceiveRequest                                */
/*                                                                            */
/* !Description :                                                             */
/* !Number      : 0x03                                                        */
/* !Reference   : NONE /                                                      */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
PduR_ReturnType PduR_DcmCancelReceiveRequest
(
   PduIdType udtRxPduId
)
{
   PduR_ReturnType udtReturnStatus;
   uint8           udtLocalNwlId;
   uint8           u8LocalDcmConnection;

   udtReturnStatus = E_NOT_OK;
   // for(u8LocalDcmConnection = 0;
       // u8LocalDcmConnection < PDUR_u8NB_OF_DCM_CONNECTIONS;
       // u8LocalDcmConnection++)
   // {
      // if(  udtRxPduId
        // == PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].udtDcmRefRxPhys)
      // {
         // udtLocalNwlId =
            // PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].udtNwlId;
         // udtReturnStatus = CanTp_CancelReceiveRequest(udtLocalNwlId);
      // }
   // }
   return(udtReturnStatus);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !FuncName    : PduR_CanTpCopyRxData                                        */
/*                                                                            */
/* !Description :                                                             */
/* !Number      : 0x04                                                        */
/* !Reference   : NONE /                                                      */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  PduR_bGetDcmPduId(argin PduIdType udtPduId, argin    */
/*  PduIdType *pudtDcmPduId);                                                 */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
//BufReq_ReturnType PduR_CanTpCopyRxData
//(
//   PduIdType udtRxPduId,
//   PduInfoType* pstrPduInfoPointer,
//   PduLengthType* pudtRxBufferSizePtr
//)
//{
//
//   PduIdType         udtLocalDcmRxPduId;
//   BufReq_ReturnType udtReturnBufReqStatus;
//   boolean           bLocalResult;
//
//   udtReturnBufReqStatus = BUFREQ_E_NOT_OK;
//   // bLocalResult = PduR_bGetDcmPduId(udtRxPduId, &udtLocalDcmRxPduId);
//   // if(bLocalResult != FALSE)
//   // {
//      // udtReturnBufReqStatus = Dcm_CopyRxData(
//                                 // udtLocalDcmRxPduId,
//                                 // pstrPduInfoPointer,
//                                 // pudtRxBufferSizePtr);
//   // }
//   // else
//   // {
//// #if (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED)
//      // udtReturnBufReqStatus = COMINL_CopyRxData(
//                                 // udtRxPduId,
//                                 // pstrPduInfoPointer,
//                                 // pudtRxBufferSizePtr);
//// #endif /* (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED) */
//   // }
//
//   return(udtReturnBufReqStatus);
//
//}
//
//
///*************************** <AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !FuncName    : PduR_CanTpCopyTxData                                        */
///*                                                                            */
///* !Description :                                                             */
///* !Number      : 0x05                                                        */
///* !Reference   : NONE /                                                      */
///*                                                                            */
///*                                                                            */
///******************************************************************************/
///*                                                                            */
///*  extf argret boolean  PduR_bGetDcmPduId(argin PduIdType udtPduId, argin    */
///*  PduIdType *pudtDcmPduId);                                                 */
///*                                                                            */
///*                                                                            */
///*                                                                            */
///************************** </AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !LastAuthor  :  Mohamed Mohi                                               */
///************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
//BufReq_ReturnType PduR_CanTpCopyTxData
//(
//   PduIdType udtTxPduId,
//   PduInfoType* pstrPduInfoPointer,
//   RetryInfoType* pstrRetryInfo,
//   PduLengthType* pudtTxDataCntPtr
//)
//{
//
//   PduIdType         udtLocalDcmTxPduId;
//   BufReq_ReturnType udtReturnBufReqStatus;
//   boolean           bLocalResult;
//
//   udtReturnBufReqStatus = BUFREQ_E_NOT_OK;
//   // bLocalResult = PduR_bGetDcmPduId(udtTxPduId, &udtLocalDcmTxPduId);
//   // if(bLocalResult != FALSE)
//   // {
//      // udtReturnBufReqStatus = Dcm_CopyTxData(
//                                 // udtLocalDcmTxPduId,
//                                 // pstrPduInfoPointer,
//                                 // pstrRetryInfo,
//                                 // pudtTxDataCntPtr);
//   // }
//   // else
//   // {
//// #if (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED)
//      // udtReturnBufReqStatus = COMINL_CopyTxData(
//                                 // udtTxPduId,
//                                 // pstrPduInfoPointer,
//                                 // pstrRetryInfo,
//                                 // pudtTxDataCntPtr);
//// #endif /* (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED) */
//   // }
//
//   return(udtReturnBufReqStatus);
//}
//
//
//
///*************************** <AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !FuncName    : PduR_CanTpRxIndication                                      */
///*                                                                            */
///* !Description :                                                             */
///* !Number      : 0x06                                                        */
///* !Reference   : NONE /                                                      */
///*                                                                            */
///*                                                                            */
///******************************************************************************/
///*                                                                            */
///*  extf argret boolean  PduR_bGetDcmPduId(argin PduIdType udtPduId, argin    */
///*  PduIdType *pudtDcmPduId);                                                 */
///*                                                                            */
///*                                                                            */
///*                                                                            */
///************************** </AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !LastAuthor  :  Mohamed Mohi                                               */
///************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
//void PduR_CanTpRxIndication
//(
//   PduIdType udtRxPduId,
//   NotifResultType udtResult
//)
//{
//
//   PduIdType  udtLocalDcmRxPduId;
//   boolean    bLocalResult;
//
//   // bLocalResult = PduR_bGetDcmPduId(udtRxPduId, &udtLocalDcmRxPduId);
//   // if(bLocalResult != FALSE)
//   // {
//      // Dcm_TpRxIndication(udtLocalDcmRxPduId, udtResult);
//   // }
//   // else
//   // {
//// #if (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED)
//      // COMINL_TpRxIndication(udtRxPduId, udtResult);
//// #endif /* (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED) */
//   // }
//}
//
//
//
///*************************** <AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !FuncName    : PduR_CanTpStartOfReception                                  */
///*                                                                            */
///* !Description :                                                             */
///* !Number      : 0x07                                                        */
///* !Reference   : NONE /                                                      */
///*                                                                            */
///*                                                                            */
///******************************************************************************/
///*                                                                            */
///*  extf argret boolean  PduR_bGetDcmPduId(argin PduIdType udtPduId, argin    */
///*  PduIdType *pudtDcmPduId);                                                 */
///*                                                                            */
///*                                                                            */
///*                                                                            */
///************************** </AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !LastAuthor  :  Mohamed Mohi                                               */
///************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
//BufReq_ReturnType PduR_CanTpStartOfReception
//(
//   PduIdType udtRxPduId,
//   PduLengthType udtSduLength,
//   PduLengthType* pudtLength
//)
//{
//
//   PduIdType         udtLocalDcmRxPduId;
//   BufReq_ReturnType udtReturnBufReqStatus;
//   boolean           bLocalResult;
//
//   // udtReturnBufReqStatus = BUFREQ_E_NOT_OK;
//   // bLocalResult = PduR_bGetDcmPduId(udtRxPduId, &udtLocalDcmRxPduId);
//   // if(bLocalResult != FALSE)
//   // {
//      // udtReturnBufReqStatus =
//         // Dcm_StartOfReception(udtLocalDcmRxPduId, udtSduLength, pudtLength);
//   // }
//   // else
//   // {
//// #if (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED)
//      // udtReturnBufReqStatus =
//         // COMINL_StartOfReception(udtRxPduId, udtSduLength, pudtLength);
//// #endif /* (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED) */
//   // }
//
//   return(udtReturnBufReqStatus);
//
//}
//
///*************************** <AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !FuncName    : PduR_CanTpTxConfirmation                                    */
///*                                                                            */
///* !Description :                                                             */
///* !Number      : 0x08                                                        */
///* !Reference   : NONE /                                                      */
///*                                                                            */
///*                                                                            */
///******************************************************************************/
///*                                                                            */
///*  extf argret boolean  PduR_bGetDcmPduId(argin PduIdType udtPduId, argin    */
///*  PduIdType *pudtDcmPduId);                                                 */
///*                                                                            */
///*                                                                            */
///*                                                                            */
///************************** </AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !LastAuthor  :  Mohamed Mohi                                               */
///************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
//void PduR_CanTpTxConfirmation
//(
//   PduIdType udtTxPduId,
//   NotifResultType udtUsdtResult
//)
//{
//
//   // PduIdType     udtLocalDcmTxPduId;
//   // boolean       bLocalResult;
//
//   // bLocalResult = PduR_bGetDcmPduId(udtTxPduId, &udtLocalDcmTxPduId);
//   // if(bLocalResult != FALSE)
//   // {
//      // Dcm_TpTxConfirmation(udtLocalDcmTxPduId, udtUsdtResult);
//   // }
//   // else
//   // {
//// #if (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED)
//      // COMINL_TpTxConfirmation(udtTxPduId, udtUsdtResult);
//// #endif /* (PDUR_coCOMINL_INTERFACE == PDUR_coCOMINL_ENABLED) */
//   // }
//
//}
//
//
//
///*************************** <AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !FuncName    : PduR_bGetDcmPduId                                           */
///*                                                                            */
///* !Description :                                                             */
///* !Number      : 0x09                                                        */
///* !Reference   : NONE /                                                      */
///*                                                                            */
///*                                                                            */
///******************************************************************************/
///*                                                                            */
///*                                                                            */
///*                                                                            */
///*                                                                            */
///************************** </AUTO_FUNCTION_HEADER> ***************************/
///*                                                                            */
///* !LastAuthor  :  Mohamed Mohi                                               */
///************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
//boolean PduR_bGetDcmPduId
//(
//   PduIdType udtPduId,
//   PduIdType* pudtDcmPduId
//)
//{
//   uint8   udtLocalNwlId;
//   uint8   u8LocalDcmConnection;
//   boolean bLocalResult;
//
//   bLocalResult = FALSE;
//   // udtLocalNwlId = OSEK_COM_udtMsgNwlIdRead(udtPduId);
//   // for(u8LocalDcmConnection = 0;
//       // (  (u8LocalDcmConnection < PDUR_u8NB_OF_DCM_CONNECTIONS)
//       // && (bLocalResult == FALSE) );
//       // u8LocalDcmConnection++)
//   // {
//      // if(  udtLocalNwlId
//        // == PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].udtNwlId)
//      // {
//         // bLocalResult = TRUE;
//
//         // if(  udtPduId == PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].
//                             // udtTransmitAddressID)
//         // {
//            // *pudtDcmPduId =
//               // PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].udtDcmRefTx;
//         // }
//         // else if(udtPduId == PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].
//                                // udtReceiveAddressID)
//
//         // {
//            // *pudtDcmPduId = PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].
//                               // udtDcmRefRxPhys;
//         // }
//         // else
//         // {
//            // *pudtDcmPduId = PduR_kastrDcmCanTpInterface[u8LocalDcmConnection].
//                               // udtDcmRefRxFunc;
//         // }
//      // }
//   // }
//   return(bLocalResult);
//
//}
//
//#endif   /* (PDUR_coDCM_INTERFACE == PDUR_coDCM_ENABLED) */





// #define PDUR_STOP_SEC_CODE
// #include "MemMap.h"

/*------------------------------ end of file -------------------------------*/

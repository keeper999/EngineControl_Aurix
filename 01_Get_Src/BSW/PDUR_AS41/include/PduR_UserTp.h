/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !File            : PduR_UserTp.h                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/02_PduR/02$*/
/* $Revision::   1.9      $$Author::   sedrees        $$Date::   Mar 24 2014 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#ifndef PDUR_USERTP_H
#define PDUR_USERTP_H

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include "Std_Types.h"

#include "PduR_LocalTypes.h"
#include "PduR_Types.h"

#include "Compiler.h"
#include "Compiler_Cfg.h"

#include "ComStack_Cfg.h"
#include "PduR_Cfg.h"

#if (PduR_bZERO_COST_OPERATION == STD_OFF)

#if(PduR_bTPLO_ENABLED == STD_ON)

/******************************************************************************/
/* EXTERNED DATA                                                              */
/******************************************************************************/


/******************************************************************************/
/* SYMBOLIC DEFINES                                                           */
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS DECLARATIONS                                                     */
/******************************************************************************/

#define PDUR_START_SEC_CODE
#include "Memmap.h"

/* Helper Functions */
/********************/

extern FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8TpRxStatusChecker(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    P2VAR(PduR_tu8RoutingType, AUTOMATIC, AUTOMATIC)            pu8RtngType,
    P2CONST(PduR_tstrTpRxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf);

extern FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8TpTxStatusChecker(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    P2VAR(PduR_tu8RoutingType, AUTOMATIC, AUTOMATIC)            pu8RtngType,
    P2CONST(PduR_tstrTpTxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf);

/* TP Normal Operations */
/************************/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuLoTpStartOfRx(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    VAR(PduLengthType, AUTOMATIC)                               udtTpSduLen,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)             pudtBuffSize,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                         u8RtngType,
    P2CONST(PduR_tstrTpRxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuLoTpCopyRxData(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)               pstrInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)             pudtBuffSize,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                         u8RtngType,
    P2CONST(PduR_tstrTpRxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf);

extern FUNC(void, PDUR_CODE) PduR_vidLoTpRxIndication(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    VAR(NotifResultType, AUTOMATIC)                             u8Result,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                         u8RtngType,
    P2CONST(PduR_tstrTpRxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuLoTpCopyTxData(
    VAR(PduIdType, AUTOMATIC)                                   udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)               pstrInfo,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA)             pstrRetry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)             pudtAvData,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                         u8RtngType,
    P2CONST(PduR_tstrTpTxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf);

extern FUNC(void, PDUR_CODE) PduR_vidLoTpTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    VAR(NotifResultType, AUTOMATIC)                             u8Result,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                         u8RtngType,
    P2CONST(PduR_tstrTpTxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf);

/* Rx Gateway Operations */
/*************************/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuGateTpStartOfRx(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)    pstrPduInfo,
    VAR(PduLengthType, AUTOMATIC)                   udtSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) pudtAvBuffSize);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuGateTpCopyRxData(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   pstrPduInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) pudtAvBuffSize);

extern FUNC(void, PDUR_CODE) PduR_vidGateTpRxIndication(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    VAR(NotifResultType, AUTOMATIC)                 u8Result);

/* Tx Gateway Operations */
/*************************/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuGateTpCopyTxData(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   pstrPduInfo,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) pstrRetryInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) pudtAvBuffSize);

extern FUNC(void, PDUR_CODE) PduR_vidGateTpTxConfirm(
    VAR(PduIdType, AUTOMATIC)                       udtId,
    VAR(NotifResultType, AUTOMATIC)                 u8Result);


/* Tx Multicast Operations */
/***************************/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuMultiTpCopyTxData(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   pstrPduInfo,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) pstrRetryInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) pudtAvBuffSize);

extern FUNC(void, PDUR_CODE) PduR_vidMultiTpTxConfirm(
    VAR(PduIdType, AUTOMATIC)                       udtId,
    VAR(NotifResultType, AUTOMATIC)                 u8Result);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if(PduR_bTPLO_ENABLED == STD_ON) */

#endif /* #if (PduR_bZERO_COST_OPERATION == STD_OFF) */

#endif /* PDUR_USERTP_H */

/*------------------------------- end of file --------------------------------*/

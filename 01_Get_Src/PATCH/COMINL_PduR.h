/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : INL                                                     */
/*                                                                            */
/* !Component       : COMINL                                                  */
/* !Description     : COMINL Interface                                        */
/*                                                                            */
/* !Module          : COMINL                                                  */
/* !Description     : Glue from COMINL Component                              */
/*                                                                            */
/* !File            : COMINL.h                                                */
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
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/COMINL_PduR.h_v             $*/
/* $Revision::   1.0      $$Author::   croche2        $$Date::   11 Mar 2014 $*/
/******************************************************************************/


#ifndef COMINL_PDUR_H
#define COMINL_PDUR_H


#include "STD_TYPES.h"

#include "COMINL.h"
#include "COMINL_L.h"
#include "COMINL_c.h"
#include "ComStack_Types.h"
#include "PduR_Types.h"

typedef enum
{
   TP_NORETRY,
   TP_DATACONF,
   TP_DATARETRY,
   TP_CONFPENDING
} TpDataStateType;

typedef struct
{
   TpDataStateType TpDataState;
   PduLengthType   TxTpDataCnt;
} RetryInfoType;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

extern PduR_ReturnType COMINL_UsdtTransmit
   (PduIdType udtTxPduId,
    const PduInfoType* pstrPduInfoPointer);

extern BufReq_ReturnType COMINL_StartOfReception
   (PduIdType      udtRxPduId,
    PduLengthType  udtSduLength,
    PduLengthType* pudtLength );

extern BufReq_ReturnType COMINL_CopyRxData
   (PduIdType      udtRxPduId,
    PduInfoType*   pstrPduInfoPointer,
    PduLengthType* pudtRxBufferSizePtr );

extern void COMINL_TpRxIndication
   (PduIdType udtRxPduId,
    NotifResultType udtResult );

extern BufReq_ReturnType COMINL_CopyTxData
   (PduIdType      udtTxPduId,
    PduInfoType*   pstrPduInfoPointer,
    RetryInfoType* pstrRetryInfo,
    PduLengthType* pudtTxDataCntPtr );

extern void COMINL_TpTxConfirmation
   (PduIdType udtMessageId,
    NotifResultType udtUsdtResult);


#endif  /*  COMINL_PDUR_H */

/*------------------------------ end of file -------------------------------*/

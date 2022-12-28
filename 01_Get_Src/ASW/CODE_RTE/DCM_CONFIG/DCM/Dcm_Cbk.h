/******************************************************************************/
/*                                                                            */
/* !Layer           : Service Layer                                           */
/*                                                                            */
/* !Component       : Dcm                                                     */
/* !Description     : Diagnostic Communication Manager                        */
/*                                                                            */
/* !Module          : Dcm                                                     */
/* !Description     : Diagnostic Communication Manager                        */
/*                                                                            */
/* !File            : Dcm_Cbk.h                                               */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   I:/PROJETS/LIBEMB/LOG/COM/DCM/LOG/Dcm_Cbk.h_v                $*/
/* $Revision::   1.6      $$Author::   lvoilmy        $$Date::   22 Nov 2011 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef DCM_CBK_H
#define DCM_CBK_H

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void,DCM_CODE) Dcm_ComM_FullComModeEntered(uint8 NetworkId);
extern FUNC(void,DCM_CODE) Dcm_ComM_SilentComModeEntered(uint8 NetworkId);
extern FUNC(void,DCM_CODE) Dcm_ComM_NoComModeEntered(uint8 NetworkId);
extern FUNC(void,DCM_CODE) Dcm_TpTxConfirmation(
  PduIdType DcmTxPduId,
  NotifResultType Result);


extern BufReq_ReturnType Dcm_CopyTxData(
  PduIdType DcmTxPduId,
  P2VAR(PduInfoType,AUTOMATIC,DCM_APPL_DATA) PduInfoPtr,
  P2VAR(RetryInfoType,AUTOMATIC,DCM_APPL_DATA) RetryInfoPtr,
  P2VAR(PduLengthType,AUTOMATIC,DCM_APPL_DATA) TxDataCntPtr);

extern FUNC(void,DCM_CODE) Dcm_TpRxIndication(
  PduIdType DcmRxPduId,
  NotifResultType Result);

extern FUNC(BufReq_ReturnType,DCM_CODE) Dcm_CopyRxData(
  PduIdType DcmRxPduId,
  P2VAR(PduInfoType,AUTOMATIC,DCM_APPL_DATA) PduInfoPointer,
  P2VAR(PduLengthType,AUTOMATIC,DCM_APPL_DATA) RxBufferSizePtr);

extern FUNC(BufReq_ReturnType,DCM_CODE) Dcm_StartOfReception(
  PduIdType DcmRxPduId,
  PduLengthType TpSduLength,
  P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) RxBufferSizePtr);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_CBK_H */

/*-------------------------------- end of file -------------------------------*/

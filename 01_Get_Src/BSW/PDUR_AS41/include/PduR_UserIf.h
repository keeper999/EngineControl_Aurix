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
/* !File            : PduR_UserIf.h                                           */
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
/* $Revision::   1.8     $$Author::   aalaa          $$Date::   Oct 02 2013 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#ifndef PDUR_USERIF_H
#define PDUR_USERIF_H

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

#if(PduR_bIFLO_ENABLED == STD_ON)
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

/* Interface Normal Operations */
/*******************************/
extern FUNC(void, PDUR_CODE) PduR_vidLoIfRxIndication(
    VAR(PduIdType, AUTOMATIC)                                   udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)               pstrPduInfo,
    P2CONST(PduR_tstrIfRxRefType, AUTOMATIC, AUTOMATIC)         pkstrTblsRf);

#if(PduR_bIFUP_ENABLED == STD_ON)
extern FUNC(void, PDUR_CODE) PduR_vidMultiUpRxIndication(
    VAR(PduIdType, AUTOMATIC)                                   udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)               pstrPduInfo);
#endif

extern FUNC(void, PDUR_CODE) PduR_vidLoIfTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                                   udtPduId,
    P2CONST(PduR_tstrIfTxRefType, AUTOMATIC, AUTOMATIC)         pkstrTblsRf);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_u8LoIfTriggerTransmit(
    VAR(PduIdType, AUTOMATIC)                                   udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)               pstrPduInfo,
    P2CONST(PduR_tstrIfTxRefType, AUTOMATIC, AUTOMATIC)         pkstrTblsRf);

/* Gateway Operations */
/**********************/
#if(PduR_bGATEWAYING_IF == STD_ON)

extern FUNC(void, PDUR_CODE) PduR_vidGateRxIndication(
    VAR(PduIdType, AUTOMATIC)                           udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)       pstrPduInfo);

extern FUNC(void, PDUR_CODE) PduR_vidGateTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                       udtPduId);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_u8GateTriggerTransmit(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   pstrPduInfo);

#endif

/* Mutlcast Operations */
/***********************/
#if(PduR_bMULTICASTING_IF == STD_ON)

extern FUNC(void, PDUR_CODE) PduR_vidMultiTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                       udtPduId);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_u8MultiTriggerTransmit(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   pstrPduInfo);

#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if(PduR_bIFLO_ENABLED == STD_ON) */

#endif /* #if (PduR_bZERO_COST_OPERATION == STD_OFF) */

#endif /* PDUR_USERIF_H */

/*------------------------------- end of file --------------------------------*/

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
/* !File            : PduR_UserUp.h                                           */
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
/* $Revision::   1.7      $$Author::   sedrees        $$Date::   Apr 01 2014 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#ifndef PDUR_USERUP_H
#define PDUR_USERUP_H

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

#if ((PduR_bIFUP_ENABLED == STD_ON ) || (PduR_bTPUP_ENABLED == STD_ON))

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

/* Helper functions */
/* **************** */
extern FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8FindRevRoutingId(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf,
    P2VAR(PduR_tu8RoutingType, AUTOMATIC, AUTOMATIC)        pu8RtngType,
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)                  pudtTablesId);

extern FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8UpStatusChecker(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    P2VAR(PduR_tu8RoutingType, AUTOMATIC, AUTOMATIC)        pu8RtngType,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf);

/* Upper Layer Normal Operations */
/*********************************/
extern FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8UpTransmit(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)         pkstrInfo,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf);

#if(PduR_bCANCEL_TX_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_u8UpCancelTransmit(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf);
#endif /* #if(PduR_bCANCEL_TX_ENABLED == STD_ON) */

#if(PduR_bCANCEL_RX_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_u8UpCancelRxRequest(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf);
#endif /* #if(PduR_bCANCEL_RX_ENABLED == STD_ON) */

#if(PduR_bCHANGE_PARAM_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_u8UpChangeParamRequest(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    VAR(TPParameterType, AUTOMATIC)                         enuParameter,
    VAR(uint16, AUTOMATIC)                                  u16Value,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf);
#endif /* #if(PduR_bCHANGE_PARAM_ENABLED == STD_ON) */
    
/* Multicasting Operations */
/***************************/
#if(PduR_bMULTICASTING_IF == STD_ON)
extern FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8MultiIfTransmit(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)         pkstrInfo);
#endif

#if(PduR_bMULTICASTING_TP == STD_ON)
extern FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8MultiTpTransmit(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)         pkstrInfo);
#endif

#if((PduR_bMULTICASTING_IF == STD_ON) && (PduR_bCANCEL_TX_ENABLED == STD_ON))
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_u8MultiCancelTransmit(
    VAR(PduIdType, AUTOMATIC)                               udtId);
#endif

#if((PduR_bMULTICASTING_TP == STD_ON) && (PduR_bCANCEL_TX_ENABLED == STD_ON))
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_u8MultiCancelTxRequest(
    VAR(PduIdType, AUTOMATIC)                               udtId);
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if ((PduR_bIFUP_ENABLED == STD_ON ) || (PduR_bTPUP_ENABLED == STD_ON)) */

#endif /* #if (PduR_bZERO_COST_OPERATION == STD_OFF) */

#endif /* PDUR_USERUP_H */

/*------------------------------- end of file --------------------------------*/

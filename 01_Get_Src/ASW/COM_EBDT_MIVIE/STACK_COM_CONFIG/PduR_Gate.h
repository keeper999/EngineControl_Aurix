
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
/* !File            : PduR_Gate.h                                             */
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
/* $Revision::   1.7      $$Author::   sedrees        $$Date::   Jan 23 2013 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#ifndef PDUR_GATE_H
#define PDUR_GATE_H

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include "Std_Types.h"
#include "PduR_Types.h"

#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "PduR_Cfg.h"

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


#if(PduR_bCOM_PRESENT == STD_ON && PduR_bGATEWAYING_IF == STD_ON)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_u8GtComRxInd(
    VAR(PduIdType, AUTOMATIC)                           udtPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)     pkstrPduInfo);
#endif

#if(PduR_bCOM_PRESENT == STD_ON && PduR_bGATEWAYING_TP == STD_ON)
extern FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8GtComTpRxInd(
    VAR(PduIdType, AUTOMATIC)                           udtPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)     pkstrPduInfo);
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* PDUR_GATE_H */

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */

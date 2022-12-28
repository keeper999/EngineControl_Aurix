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
/* !File            : PduR_Main.h                                             */
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
/* $Revision::   1.6      $$Author::   aalaa          $$Date::   Oct 02 2013 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#ifndef PDUR_MAIN_H
#define PDUR_MAIN_H

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

extern FUNC(void, PDUR_CODE) PduR_vidTxBuffClear(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST) pkstrTxBuff);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* PDUR_MAIN_H */

#endif /* #if (PduR_bZERO_COST_OPERATION == STD_OFF) */

/*------------------------------- end of file --------------------------------*/

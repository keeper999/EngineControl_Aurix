
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
/* !File            : PduR_Callout.h                                          */
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
/* $Revision::   1.1      $$Author::   sedrees        $$Date::   Feb 20 2013 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#ifndef PDUR_CALLOUT_H
#define PDUR_CALLOUT_H

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include "Std_Types.h"
#include "PduR_Types.h"

#include "Compiler.h"
#include "Compiler_Cfg.h"

#include "ComStack_Cfg.h"
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

#define PDUR_START_SEC_CALLOUT_CODE
#include "Memmap.h"

#if(PduR_bCALLOUT_SUPPORTED == STD_ON)



#endif


#define PDUR_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

#endif /* PDUR_CALLOUT_H */

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */

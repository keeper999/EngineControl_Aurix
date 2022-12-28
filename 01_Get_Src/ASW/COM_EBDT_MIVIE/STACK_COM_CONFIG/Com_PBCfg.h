
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : Autosar Com module                                      */
/*                                                                            */
/* !Module          : Com                                                     */
/* !Description     : Autosar Com module                                      */
/*                                                                            */
/* !File            : Com_PBCfg.h                                             */
/*                                                                            */
/* !Scope           : Private                                                 */
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
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/03-Com/02_$*/
/* $Revision::   1.3      $$Author::   ngalal         $$Date::   Dec 04 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/  
#ifndef COM_PBCFG_H
#define COM_PBCFG_H



/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
  

#define    ComConfig    Com_kstrePBConfig0

#define COM_START_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"
extern CONST(Com_ConfigType,COM_CALIB_CONST) Com_kstrePBConfig0;
#define COM_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"

/* PRQA S 0850 --                                                             */

  

  
#endif /* COM_PBCFG_H  */

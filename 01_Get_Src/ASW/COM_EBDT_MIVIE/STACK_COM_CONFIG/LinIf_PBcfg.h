   
/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR component                     */
/*                                                                            */
/*!Module          : LinIf_PBCfg                                             */
/*!Description     : The Post-Build time configuration parameters export      */
/*                                                                            */
/*!\File             LinIf_PBCfg.h                                           */
/* \par              The Post-Build time configuration parameters export     */
/*!Scope           : Private                                                 */
/*                                                                            */
/*!Target          : All                                                     */
/*                                                                            */
/*!Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/20_LinIf/0$*/
/* $Revision::   1.3      $$Author::   mnabil         $$Date::   Oct 20 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
 
#ifndef LINIF_PBCFG_H
#define LINIF_PBCFG_H

#include "Std_Types.h"
#include "Compiler.h"
#include "LinIf_Types.h"
#include "LinIf_Cfg.h"



/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define LINIF_START_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"
extern CONST(LinIf_ConfigType, LINIF_CALIB_CONST) LinIf_kstrePBConfig;

#if(LinIf_u8TP_SUPPORTED == STD_ON)

extern CONST(LinTp_ConfigType, LINIF_CALIB_CONST) LinIf_kstreLinTpConfig;
#endif

#define LINIF_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"

#endif /* LINIF_PBCFG_H */

/*-------------------------------- end of file -------------------------------*/
   

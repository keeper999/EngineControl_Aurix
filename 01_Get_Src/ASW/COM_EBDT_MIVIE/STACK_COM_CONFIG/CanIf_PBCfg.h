
/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_PbCfg                                             */
/*!\file            : CanIf_PbCfg.h                                           \n
    \Description    :Responsible for PostBuild Configurations                 */
/*                                                                            */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/17_CanIf/0$*/
/* $Revision::   1.3      $$Author::   amansour       $$Date::   Oct 18 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef CANIF_PBCFG_H
#define CANIF_PBCFG_H

#define CanIf_u8NUM_OF_PB_CFGS      0x01

#define CANIF_START_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/
/*!  \Description array of pointers to
                  configuration sets, used for post build parameters 
*******************************************************************************/
extern CONST (CanIf_ConfigType, CANIF_CALIB_CONST) akstrConfig[CanIf_u8NUM_OF_PB_CFGS];
#define CANIF_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"

#define CanIfInitCfg akstrConfig[0]

/*-------------------------------------EOF------------------------------------*/
#endif/*CANIF_PBCFG_H*/
          

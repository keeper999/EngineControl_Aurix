
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : CanTp                                                   */
/* !Description     : CanTp is the component between the PDU Router and the   */
/*                    CAN Interface module. The main purpose of the CanTp     */
/*                    component is to segment and reassemble CAN I-PDUs longer*/
/*                    than 8 bytes                                            */
/*                                                                            */
/* !File            : CanTp_PBCfg.h                                           */
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
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/19_CanTp/0$*/
/* $Revision::   1.0      $$Author::   madel          $$Date::   Nov 22 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp_PBCfg.h
*
* \par
*   This file exports an array of pointers to CanTp post-build configuration
    structures                                                                */
/******************************************************************************/
#ifndef CANTP_PBCFG_H
#define CANTP_PBCFG_H


#include "CanTp_Types.h"


#define CanTp_u8NUM_OF_CONFIG_SETS  1



#define CANTP_START_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONSTP2CONST(CanTp_ConfigType, CANTP_CALIB_CONST, CANTP_CALIB_CONST)
                        CanTp_akpkstreCanTpConfig[CanTp_u8NUM_OF_CONFIG_SETS];


#define CANTP_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"

#endif /* CANTP_PBCFG_H */

/*-------------------------------- end of file -------------------------------*/
  
  

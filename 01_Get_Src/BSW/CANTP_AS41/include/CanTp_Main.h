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
/* !File            : CanTp_Main.h                                            */
/*                                                                            */
/* !Scope           : PrivateComponent                                        */
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
/* $Revision::   1.1      $$Author::   mamroussy      $$Date::   Jan 28 2013 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp_Main.h
*
* \par
*   This file contains the data exported by the Main sub-component, to be used
    by the Reception and Transmission sub-components                          */
/******************************************************************************/

#ifndef CANTP_MAIN_H
#define CANTP_MAIN_H

#include "CanTp_Types.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Pointer to post-build configuration structure             \n
*******************************************************************************/

#define CANTP_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

extern P2CONST(CanTp_ConfigType, CANTP_VAR, CANTP_APPL_CONST) 
                                                       CanTp_pkstreGlobalConfig;

#define CANTP_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

#endif /* CANTP_MAIN_H */

/*-------------------------------- end of file -------------------------------*/
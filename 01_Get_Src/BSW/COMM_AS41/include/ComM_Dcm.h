/* !Deviation: [0288] Violates MISRA Rule 5: "Only those characters and escape
    sequences which are defined in the ISO C standard shall be used."
    PVCS needs this, and this is within a commented area so no harm shall be
    done.
 */
/* PRQA S 0288 ++*/
/*
$Header::
*/
/* PRQA S 0288 --*/
/* PRQA S 8014, 8114, 8314, 8414, 8614 ++*/
/* !Deviation: [8014] [8114] [8314] [8614] Violates VNR on file naming rules
    because file names are imposed by AutOSAR requirements */
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : ComM                                                    */
/* !Description     : Communication Manager Module                            */
/*                                                                            */
/* !Module          : ComM                                                    */
/*                                                                            */
/* !File            : ComM_Dcm.h                                              */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : ALL                                                     */
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
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/04-ComM/02$*/
/* $Revision::   1.9      $$Author::   AELSOHBY       $$Date::   Apr 02 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/******************************************************************************/
/* !VnrOff : Names imposed by AUTOSAR Specification                           */
/******************************************************************************/

#ifndef COMM_DCM_H
#define COMM_DCM_H
#include "ComM_Cfg.h"

#if (ComM_bCOMM_DCM_ENABLED == TRUE)
#include "ComM_Types.h"

#define COMM_START_SEC_CODE
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to indicate an active diagnostic session on a certain
                 channel.                                                     \n
    \param[in]   Channel The Channel on which the active diagnostic session is
                         indicated.                                           \n
                 \Range 0..(ComM_u8NO_OF_CHANNELS-1)                          \n
                 \Unit NetworkHandleType
*******************************************************************************/
extern FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic(
                                                     NetworkHandleType Channel);
/* PRQA S 0850 --                                                             */


/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description Function to indicate the end of an active diagnostic session on
                 a certain channel.                                           \n
    \param[in]   Channel The Channel on which the end of the active diagnostic
                         session is indicated.                                \n
                 \Range 0..(ComM_u8NO_OF_CHANNELS-1)                          \n
                 \Unit NetworkHandleType
*******************************************************************************/
extern FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic(
                                                     NetworkHandleType Channel);
/* PRQA S 0850 --                                                             */

#define COMM_STOP_SEC_CODE
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/

#endif /* ComM_bCOMM_DCM_ENABLED */

#endif /* COMM_DCM_H */

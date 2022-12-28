/* PRQA S 8014, 8114, 8314, 8414, 8614 EOF*/
/* !Deviation: [8014] [8114] [8314] [8614] Violates VNR on file naming rules
    because file names are imposed by AUTOSAR requirements */
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : BswM                                                    */
/* !Description     : Basic Software Mode Manager Module                      */
/*                                                                            */
/* !Module          : BswM                                                    */
/*                                                                            */
/* !File            : BswM_CanSM.h                                            */
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
/* $Archive::   P:/EBx_V46/LDA/REF/modules/STACK_COM_STUB/BswM_CanSM.h_v     $*/
/* $Revision::   1.2      $$Author::   hmelloul       $$Date::   08 Oct 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file BswM.h
*
* \par
*   Externals of the module BswM.
*   This file contains the externals of the module BswM. */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup module BswM
* This is the grouping of the BswM module members.
* \{
*/
/******************************************************************************/
/******************************************************************************/
/* !VnrOff : Names imposed by AUTOSAR Specification                           */
/******************************************************************************/
#ifndef BSWM_CANSM_H
#define BSWM_CANSM_H

#include "Std_Types.h"

//GEEDS Modifcations YSWE
 #include "CanSM_BswM.h" 
//GEEDS Modifcations YSWE
#define CANSM_START_SEC_CODE
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/
/******************************************************************************/
/*! \Description Function called by CanSM to indicate the current state of
                 a certain Network                                            \n
    \param[in]   Network The Network needed to indicate its state             \n
                 \Range 0..(NetworkHandleType max)                            \n
                 \Unit NetworkHandleType
    \param[in]   CurrentState The Network current state                       \n
                 \Range 0..(CanSM_BswMCurrentStateType max)                   \n
                 \Unit CanSM_BswMCurrentStateType                             \n
*******************************************************************************/

/* TO BE DEFINED: que faire ici ??? */
LOCAL_INLINE FUNC(void,BSWM_CODE) BswM_CanSM_CurrentState(
                                       NetworkHandleType Network,
                                       CanSM_BswMCurrentStateType CurrentState)
{
   COMPILER_UNUSED_PARAMETER(Network);
   COMPILER_UNUSED_PARAMETER(CurrentState);
}

#define CANSM_STOP_SEC_CODE
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/

#endif /* BSWM_CANSM_H */
/** \} */ /* end of BswM module group */

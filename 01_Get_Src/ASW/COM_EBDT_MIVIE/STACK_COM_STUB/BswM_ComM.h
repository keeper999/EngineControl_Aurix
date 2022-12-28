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
/* !File            : BswM_ComM.h                                             */
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
/* $Archive::   P:/EBx_V46/LDA/REF/modules/STACK_COM_STUB/BswM_ComM.h_v      $*/
/* $Revision::   1.1      $$Author::   hmelloul       $$Date::   15 Sep 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file BswM.h
*
* \par
*   Externals of the module BswM.
*   This file contains the externals of the module BswM. */
/******************************************************************************/


#ifndef BSWM_COMM_H
#define BSWM_COMM_H
#include "Std_Types.h"

#define COMM_START_SEC_CODE
#include "COMM_MemMap.h"

LOCAL_INLINE FUNC(void,BSWM_CODE) BswM_ComM_CurrentMode(NetworkHandleType Network,
                                                  ComM_ModeType RequestedMode)
{
   COMPILER_UNUSED_PARAMETER(Network);
   COMPILER_UNUSED_PARAMETER(RequestedMode);
}


LOCAL_INLINE FUNC(void,BSWM_CODE) BswM_ComM_CurrentPNCMode(PNCHandleType PNC,
                                                ComM_PncModeType RequestedMode)
{
   COMPILER_UNUSED_PARAMETER(PNC);
   COMPILER_UNUSED_PARAMETER(RequestedMode);
}



#define COMM_STOP_SEC_CODE
#include "COMM_MemMap.h"

#endif /* BSWM_COMM_H */

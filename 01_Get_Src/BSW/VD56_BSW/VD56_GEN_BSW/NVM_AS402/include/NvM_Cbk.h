/******************************************************************************/
/*                                                                            */
/* !Layer           :  Services Layer                                         */
/*                                                                            */
/* !Component       :  NvM                                                    */
/* !Description     :  Non Volatile RAM Manager                               */
/*                                                                            */
/* !Module          :  NvM                                                    */
/* !Description     :  Non Volatile RAM Manager                               */
/*                                                                            */
/* !File            :  NvM_Cbk.h                                              */
/*                                                                            */
/* !Scope           :  Public                                                 */
/*                                                                            */
/* !Target          :  Any                                                    */
/*                                                                            */
/* !Vendor          :  Valeo                                                  */
/*                                                                            */
/* Coding language  :  C                                                      */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by           */
/*              configuration management tool (PVCS)                          */
/* PRQA S 0288 ++                                                             */
/*                                                                            */
/* $Header:   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/12_NVM/02_Development/02_Source_Code/03_Header_Files/NvM_Cbk.h-arc   1.1   Jul 21 2011 18:01:54   mashmawy  $/Data/pvcs65/CEE-SW/B01H01067-GroupSwStdDev/archives/02-R&D/02-Project/01-Modules/02-Services/04-NvM/02-Dev/01-SRC_NvM/NvM_Cbk.h-arc   1.7   Aug 11 2008 22:25:40   abazaraa  $
                                                                              */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.1    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.El-Ashmawy                               Date : 21/07/11    */
/* Description: - Fixed Bug 39944 by adding coverage to GSCSW-NVM-SDD-001-0618*/
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.0    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.El-Ashmawy                               Date : 26/06/11    */
/* Description: - Initial Revision                                            */
/******************************************************************************/

#ifndef NVM_CBK_H
#define NVM_CBK_H


#if (NVM_POLLING_MODE == STD_OFF)

/******************************************************************************/
/* !Comment: Start of memory mapping for NvM code segment                     */
/******************************************************************************/


/* !Deviation : inhibit MISRA rule [750]: because local non referenced macro  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [760]: because redundant macro defined is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [961]: because multiple use of #define is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [537]: because repeated include for Memmap */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [960]: because use of #undef is according  */
/*              to AUTOSAR specifications                                     */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v */
#define NVM_START_SEC_CODE
#include "MemMap.h"
/*lint -restore */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/* !Trace_To: GSCSW-NVM-SDD-001-0618                                          */

/* !Trace_To: GSCSW-NVM-SDD-001-0440                                          */
/******************************************************************************/
/* !Description : Function to be used by the underlying memory abstraction to 
signal end of job without error                             */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_JobEndNotification(void);

/******************************************************************************/
/* !Description : Function to be used by the underlying memory abstraction to 
signal end of job with error.                               */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_JobErrorNotification(void);

/* PRQA S 0850 --                                                             */

/******************************************************************************/
/* !Comment: End of memory mapping for NvM code segment                       */
/******************************************************************************/
/* !Deviation : inhibit MISRA rule [750]: because local non referenced macro  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [760]: because redundant macro defined is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [961]: because multiple use of #define is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [537]: because repeated include for Memmap */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [960]: because use of #undef is according  */
/*              to AUTOSAR specifications                                     */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v */
#define NVM_STOP_SEC_CODE
#include "MemMap.h"
/*lint -restore */

#endif /* NVM_POLLING_MODE == STD_OFF */

#endif /* NVM_CBK_H */


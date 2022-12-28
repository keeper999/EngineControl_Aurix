/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2009)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : EcuM_Cbk.h                                                    **
**                                                                            **
**  VERSION   : 0.0.3                                                         **
**                                                                            **
**  DATE      : 2008.12.12                                                    **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Infineon Audo                                                 **
**                                                                            **
**  COMPILER  : Independant                                                   **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file provides ECUM callback/callout declarations      **
**                 This file is for Evaluation Purpose Only                   **
**                                                                            **
**  SPECIFICATION(S) : ECUM State Manager, V220                               **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: NO                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** BM          Basheer Mohaideen                                              ** 
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*                             
   * V0.0.3: 2009.06.17, HM : Changed header 
   * V0.0.2: 2008.12.12, BM : AS3.0 added.
   * V0.0.1: 2008.04.04, BM : Initial version
*/
 
#ifndef ECUMCBK_H
#define ECUMCBK_H

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* Used in Gpt, Icu Modules */
typedef uint32 EcuM_WakeupSourceType;

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define ECUM_START_SEC_CODE
#include "ECUM_MemMap.h"

/* Wake Up Related APIs. Used in Gpt,Icu, Can Drivers */

extern void EcuM_SetWakeupEvent
(
      EcuM_WakeupSourceType events
);

extern void EcuM_ValidateWakeupEvent
(
      EcuM_WakeupSourceType events
);

extern void EcuM_CheckWakeup
(
      EcuM_WakeupSourceType wakeupSource
);

#define ECUM_STOP_SEC_CODE
#include "ECUM_MemMap.h"

#endif /* #ifndef ECUMCBK_H  */

/*-------------------------------- end of file -------------------------------*/

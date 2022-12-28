/******************************************************************************/
/* !Layer           : SRV                                                      */
/* !Component       : SchM                                                     */
/* !Description     : AutoSAR BASIS SchM Module                                */
/*                                                                             */
/* !File            : SchM_CanIf.h                                             */
/* !Description     : Scheduler module configuration to manage CanIf Component */
/*                                                                             */
/* !Reference       :                                                          */
/*                                                                             */
/* Coding language  : C                                                        */
/*                                                                             */
/* COPYRIGHT VALEO all rights reserved                                         */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A189015.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SchM_LINIF_H
#define SchM_LINIF_H

#include "Os.h"


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define SchM_Enter_LinIf_BuffSchTab_000_000 SuspendAllInterrupts
#define SchM_Exit_LinIf_BuffSchTab_000_000  ResumeAllInterrupts

#define SchM_Enter_LinIf_BuffSchTab_001_000 SuspendAllInterrupts
#define SchM_Exit_LinIf_BuffSchTab_001_000  ResumeAllInterrupts

#define SchM_Enter_LinIf_GotoSleep_000_000 SuspendAllInterrupts
#define SchM_Exit_LinIf_GotoSleep_000_000  ResumeAllInterrupts

#define SchM_Enter_LinIf_GotoSleep_001_000 SuspendAllInterrupts
#define SchM_Exit_LinIf_GotoSleep_001_000  ResumeAllInterrupts

#define SchM_Enter_LinIf_GotoSleep_002_000 SuspendAllInterrupts
#define SchM_Exit_LinIf_GotoSleep_002_000  ResumeAllInterrupts

#define SchM_Enter_LinIf_GotoSleep_003_000 SuspendAllInterrupts
#define SchM_Exit_LinIf_GotoSleep_003_000  ResumeAllInterrupts

#define SchM_Enter_LinIf_SendWakeup_000_000 SuspendAllInterrupts
#define SchM_Exit_LinIf_SendWakeup_000_000  ResumeAllInterrupts

#define SchM_Enter_LinIf_SendWakeup_001_000 SuspendAllInterrupts
#define SchM_Exit_LinIf_SendWakeup_001_000  ResumeAllInterrupts

#define SchM_Enter_LinIf_SendWakeup_002_000 SuspendAllInterrupts
#define SchM_Exit_LinIf_SendWakeup_002_000  ResumeAllInterrupts





#endif /* SchM_LINIF_H */


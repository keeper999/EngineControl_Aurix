/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_Wdg_17_Scu.h                                       */
/* !Description     : SchM configuration of the Wdg_17_scu component          */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192475.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_WDG_17_SCU_H
#define SCHM_WDG_17_SCU_H

#include "KRN.h"
#include "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define SchM_Enter_Wdg_17_Scu_TimerHandling() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_Wdg_17_Scu_Trigger() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_Wdg_17_Scu_ChangeMode() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_Wdg_17_Scu_TimerHandling() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_Wdg_17_Scu_Trigger() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_Wdg_17_Scu_ChangeMode() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#endif /* SCHM_WDG_17_SCU_H */

/*-------------------------------- end of file -------------------------------*/


/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_INJHAL.h                                           */
/* !Description     : SchM configuration of the INJHAL component              */
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
 * %PID: P2017_BSW:0A192513.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_INJHAL_H
#define SCHM_INJHAL_H

#include "KRN.h"
#include "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define SchM_Enter_INJHAL_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_INJHAL_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_INJHAL_ACCESS_002() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_INJHAL_ACCESS_002() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_INJHAL_ACCESS_003() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_INJHAL_ACCESS_003() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_INJHAL_ACCESS_004() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_INJHAL_ACCESS_004() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_INJHAL_ACCESS_005() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_INJHAL_ACCESS_005() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_INJHAL_ACCESS_006() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_INJHAL_ACCESS_006() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_INJHAL_ACCESS_007() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_INJHAL_ACCESS_007() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#endif /* SCHM_INJHAL_H */

/*-------------------------------- end of file -------------------------------*/

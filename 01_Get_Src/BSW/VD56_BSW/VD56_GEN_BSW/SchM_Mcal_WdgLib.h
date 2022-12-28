/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_Mcal_WdgLib.h                                      */
/* !Description     : SchM configuration of the MCAL_WDGLIB component         */
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
 * %PID: P2017_BSW:0A192501.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_MCAL_WDGLIB_H
#define SCHM_MCAL_WDGLIB_H

#include "DEVHAL.h"
#include "KRN.h"
#include "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/* CPU_ENDINIT */
#define SchM_Enter_Mcal_WdgLib_CPU_ENDINIT() \
do \
{ \
   if ((DEVHAL_bIsErasing() == FALSE) && (KRN_bReadOsAccessAuthorized() != FALSE)) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)


#define SchM_Exit_Mcal_WdgLib_CPU_ENDINIT() \
do \
{ \
   if ((DEVHAL_bIsErasing() == FALSE) && (KRN_bReadOsAccessAuthorized() != FALSE)) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

/* RESET_ENDINIT */
#define SchM_Enter_Mcal_WdgLib_RESET_ENDINIT() \
do \
{ \
   if ((DEVHAL_bIsErasing() == FALSE) && (KRN_bReadOsAccessAuthorized() != FALSE)) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)


#define SchM_Exit_Mcal_WdgLib_RESET_ENDINIT() \
do \
{ \
   if ((DEVHAL_bIsErasing() == FALSE) && (KRN_bReadOsAccessAuthorized() != FALSE)) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

/* RESET_SAFETY_ENDINIT */
#define SchM_Enter_Mcal_WdgLib_RESET_SAFETY_ENDINIT() \
do \
{ \
   if ((DEVHAL_bIsErasing() == FALSE) && (KRN_bReadOsAccessAuthorized() != FALSE)) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)


#define SchM_Exit_Mcal_WdgLib_RESET_SAFETY_ENDINIT() \
do \
{ \
   if ((DEVHAL_bIsErasing() == FALSE) && (KRN_bReadOsAccessAuthorized() != FALSE)) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

/* SET_ENDINIT */
#define SchM_Enter_Mcal_WdgLib_SET_ENDINIT() \
do \
{ \
   if ((DEVHAL_bIsErasing() == FALSE) && (KRN_bReadOsAccessAuthorized() != FALSE)) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)


#define SchM_Exit_Mcal_WdgLib_SET_ENDINIT() \
do \
{ \
   if ((DEVHAL_bIsErasing() == FALSE) && (KRN_bReadOsAccessAuthorized() != FALSE)) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

/* SET_SAFETY_ENDINIT */
#define SchM_Enter_Mcal_WdgLib_SET_SAFETY_ENDINIT() \
do \
{ \
   if ((DEVHAL_bIsErasing() == FALSE) && (KRN_bReadOsAccessAuthorized() != FALSE)) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)


#define SchM_Exit_Mcal_WdgLib_SET_SAFETY_ENDINIT() \
do \
{ \
   if ((DEVHAL_bIsErasing() == FALSE) && (KRN_bReadOsAccessAuthorized() != FALSE)) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#endif /* SCHM_MCAL_WDGLIB_H */

/*-------------------------------- end of file -------------------------------*/

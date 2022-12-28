/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_L9781.h                                            */
/* !Description     : SchM configuration of the L9781 component               */
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
 * %PID: %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_L9781_H
#define SCHM_L9781_H

#include "Std_Types.h"

#include "KRN.h"
#include "Os.h"


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/* L9781_udtEnable */
#define SchM_Enter_L9781_udtEnable() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0u)

#define SchM_Exit_L9781_udtEnable() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0u)

/* L9781_vidDisable */
#define SchM_Enter_L9781_vidDisable() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0u)

#define SchM_Exit_L9781_vidDisable() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0u)

/* L9781_udtLoadInjectorProfile */
#define SchM_Enter_L9781_udtLoadInjProf() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0u)

#define SchM_Exit_L9781_udtLoadInjProf() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0u)

/* L9781_udtLoadPumpProfile */
#define SchM_Enter_L9781_udtLoadPmpProf() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0u)

#define SchM_Exit_L9781_udtLoadPmpProf() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0u)

/* L9781_vidDiagManager */
#define SchM_Enter_L9781_vidDiagManager() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0u)

#define SchM_Exit_L9781_vidDiagManager() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0u)

/* L9781_vidUnlockSequence */
#define SchM_Enter_L9781_vidUnlockSeq() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0u)

#define SchM_Exit_L9781_vidUnlockSeq() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0u)

/* L9781_vidEnterStopMode */
#define SchM_Enter_L9781_vidEnterStopMod() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0u)

#define SchM_Exit_L9781_vidEnterStopMod() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0u)

/* L9781_vidCLEAR_SPI_REQUEST */
#define SchM_Enter_L9781_vidCLR_SPI_REQ() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0u)

#define SchM_Exit_L9781_vidCLR_SPI_REQ() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0u)

/* L9781_vidPROG_CAPCOM_DELAY_STARTUP_SEQ */
#define SchM_Enter_L9781_DELAY_STARTUP() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0u)

#define SchM_Exit_L9781_DELAY_STARTUP() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0u)

#endif /* SCHM_L9781_H */

/*-------------------------------- end of file -------------------------------*/
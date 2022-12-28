/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_MOS.h                                              */
/* !Description     : SchM configuration of the MOS component                 */
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

#ifndef SCHM_MOS_H
#define SCHM_MOS_H

#include "Os.h"
#include "KRN.h"


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/* ------------ Atomic section of MOS_vidDioWrite function ------------------ */
/* These two macro shall be fulfilled only if the edge diagnosis can be       */
/* pre-empted by scheduled diagnosis. Otherwise they shall be empty.          */
#define SchM_Enter_MOS_EdgeDiagPreemptEna()
#define SchM_Exit_MOS_EdgeDiagPreemptEna()

// These two macro shall be fulfilled only if the edge diagnosis cannot be
// pre-empted by scheduled diagnosis. Otherwise they shall be empty.
#define SchM_Enter_MOS_EdgeDiagPreemptDis() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_MOS_EdgeDiagPreemptDis() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

/* ------------ Atomic section of MOS_vidMainFunction function -------------- */
/* These two macro shall be fulfilled only if the scheduled diagnosis can be  */
/* pre-empted by edge diagnosis. Otherwise they shall be empty.               */
#define SchM_Enter_MOS_SdlDiagPreemptEna() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_MOS_SdlDiagPreemptEna() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

/* These two macro shall be fulfilled only if the scheduled diagnosis cannot  */
/* be pre-empted by edge diagnosis. Otherwise they shall be empty.            */
#define SchM_Enter_MOS_SdlDiagPreemptDis()
#define SchM_Exit_MOS_SdlDiagPreemptDis()

/* ------- Atomic section of MOS_vidDioDiagByDigitalReadBack function ------- */
/* These two macro shall be fulfilled if one of the diag (edge or scheduled)  */
/* can pre-empt the other. Otherwise they shall be empty.                     */
#define SchM_Enter_MOS_DiagPreemptEna() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)


#define SchM_Exit_MOS_DiagPreemptEna() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#endif /* SCHM_MOS_H */

/*-------------------------------- end of file -------------------------------*/
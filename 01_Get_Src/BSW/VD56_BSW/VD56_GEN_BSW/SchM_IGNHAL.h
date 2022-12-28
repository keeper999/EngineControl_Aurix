/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_IGNHAL.h                                           */
/* !Description     : SchM configuration of the IGNHAL component              */
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
 * %PID: P2017_BSW:0A192446.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_IGNHAL_H
#define SCHM_IGNHAL_H

#include "KRN.h"
#include "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define SchM_Enter_IGNHAL_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_IGNHAL_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#endif /* SCHM_IGNHAL_H */

/*-------------------------------- end of file -------------------------------*/

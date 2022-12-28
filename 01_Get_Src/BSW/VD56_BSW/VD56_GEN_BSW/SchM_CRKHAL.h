/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : CRKHAL Module                                           */
/*                                                                            */
/* !File            : SchM_CRKHAL.h                                           */
/* !Description     : SchM configuration of the CRKHAL component              */
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
 * %PID: P2017_BSW:0A192493.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_CRKHAL_H
#define SCHM_CRKHAL_H

#include "KRN.h"
#include "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define SchM_Enter_CRKHAL_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE)\
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_CRKHAL_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_CRKHAL_ACCESS_002() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE)\
   { \
      SuspendAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_CRKHAL_ACCESS_002() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE) \
   { \
      ResumeAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_CRKHAL_ACCESS_003() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE)\
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_CRKHAL_ACCESS_003() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_CRKHAL_ACCESS_004() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE)\
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_CRKHAL_ACCESS_004() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)

#endif /* SCHM_CRKHAL_H */

/*-------------------------------- end of file -------------------------------*/

/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_PMPHAL.h                                           */
/* !Description     : SchM configuration of the NvM component                 */
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

#ifndef SCHM_PMPHAL_H
#define SCHM_PMPHAL_H

#include "KRN.h"
#include "OS_API.h"


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define SchM_Enter_PMPHAL_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE)\
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_PMPHAL_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)


#define SchM_Enter_PMPHAL_ACCESS_002() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE)\
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_PMPHAL_ACCESS_002() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_PMPHAL_ACCESS_003() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE)\
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_PMPHAL_ACCESS_003() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)

#endif /* SCHM_PMPHAL_H */


/*-------------------------------- end of file -------------------------------*/
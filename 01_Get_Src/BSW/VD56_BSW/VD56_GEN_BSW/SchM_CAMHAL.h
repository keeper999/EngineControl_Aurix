/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_CAMHAL.h                                           */
/* !Description     : SchM configuration of the CAMHAL component              */
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
 * %PID: P2017_BSW:0A192462.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_CAMHAL_H
#define SCHM_CAMHAL_H

#include "KRN.h"
#include "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define SchM_Enter_CAMHAL_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE)\
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_CAMHAL_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)


#define SchM_Enter_CAMHAL_ACCESS_002() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE)\
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_CAMHAL_ACCESS_002() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != (boolean)FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)


#endif /* SCHM_CAMHAL_H */

/*-------------------------------- end of file -------------------------------*/


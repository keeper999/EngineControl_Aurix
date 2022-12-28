/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_Can_17_MCanP.h                                     */
/* !Description     : SchM configuration of the CAN component                 */
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
 * %PID: P2017_BSW:0A192476.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_CAN_17_MCANP_H
#define SCHM_CAN_17_MCANP_H

#include "KRN.h"
#include "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define SchM_Enter_Can_17_MCanP_CanDisInt() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_Can_17_MCanP_CanDisInt() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_Can_17_MCanP_CanWrMO() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_Can_17_MCanP_CanWrMO() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Enter_Can_17_MCanP_CanEnInt() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)

#define SchM_Exit_Can_17_MCanP_CanEnInt() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)

#endif /* SCHM_CAN_17_MCANP_H */

/*-------------------------------- end of file -------------------------------*/

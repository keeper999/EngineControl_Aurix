/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_DGOHAL.h                                           */
/* !Description     : SchM configuration of the DGOHAL component              */
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
 * %PID: P2017_BSW:0A192481.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_DGOHAL_H
#define SCHM_DGOHAL_H

#include "Std_Types.h"
#include "KRN.h"
#include "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

LOCAL_INLINE void SchM_Enter_DGOHAL_ACCESS_001(void)
{
   if (KRN_bReadOsAccessAuthorized() != FALSE)
   {
      /* UncheckedGetSpinlock Suspend All ISRs (LOCK_ALL_INTERRUPT) */
      UncheckedGetSpinlock(DGOHAL_Spinlock);
   }
}

LOCAL_INLINE void SchM_Exit_DGOHAL_ACCESS_001(void)
{
   if (KRN_bReadOsAccessAuthorized() != FALSE)
   {
      UncheckedReleaseSpinlock(DGOHAL_Spinlock);
      /* UncheckedReleaseSpinlock Resume ISRs (LOCK_ALL_INTERRUPT) */
   }
}
#define SchM_Enter_DGOHAL_ACCESS_002 SchM_Enter_DGOHAL_ACCESS_001
#define SchM_Exit_DGOHAL_ACCESS_002  SchM_Exit_DGOHAL_ACCESS_001



LOCAL_INLINE void SchM_Enter_DGOHAL_ACCESS_003(void)
{
   if (KRN_bReadOsAccessAuthorized() != FALSE)
   {
      DisableAllInterrupts();
   }
}

LOCAL_INLINE void SchM_Exit_DGOHAL_ACCESS_003(void)
{
   if (KRN_bReadOsAccessAuthorized() != FALSE)
   {
      EnableAllInterrupts();
   }
}

#define SchM_Enter_DGOHAL_ACCESS_004 SchM_Enter_DGOHAL_ACCESS_003
#define SchM_Exit_DGOHAL_ACCESS_004  SchM_Exit_DGOHAL_ACCESS_003

#endif /* SCHM_DGOHAL_H */


/*-------------------------------- end of file -------------------------------*/

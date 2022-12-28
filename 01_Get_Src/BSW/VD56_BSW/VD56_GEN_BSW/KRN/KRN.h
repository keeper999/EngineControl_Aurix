/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN.h                                                   */
/* !Description     : Public Declaration of KRN Component                     */
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
 * %PID: P2017_BSW:0A192521.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef KRN_H
#define KRN_H

#include "Std_Types.h"
#include "KRN_Types.h"
#include "SWFAIL.h"

/******************************************************************************/
/* PUBLIC FUNCTIONS                                                           */
/******************************************************************************/

#define KRN_START_SEC_CODE
#include "KRN_MemMap.h"

extern void KRN_vidInitChecksumCheck(void);
extern void KRN_vidInit(void);
extern void KRN_vidOsLaunch(void);
extern void KRN_vidSaveManualResetContext(void);
extern void KRN_vidSchedulerInit(void);
extern void KRN_vidStartup(void);

#define KRN_STOP_SEC_CODE
#include "KRN_MemMap.h"


/******************************************************************************/
/* EXTERNAL CALLBACK FUNCTIONS                                                */
/******************************************************************************/
#define KRN_START_SEC_CODE
#include "KRN_MemMap.h"

void KRN_vidCrkDwnModeEntry(void);
void KRN_vidCrkNormalModeEntry(void);
void KRN_vidExCamDwnModeEntry(void);
void KRN_vidExCamNormalModeEntry(void);
void KRN_vidInCamDwnModeEntry(void);
void KRN_vidInCamNormalModeEntry(void);
void KRN_vidSyncFoundEntry(void);
void KRN_vidSyncLossEntry(void);
void KRN_vidWaitForOsInitEnd(void);

#define KRN_STOP_SEC_CODE
#include "KRN_MemMap.h"


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : KRN_bReadOsAccessAuthorized                                 */
/* !Description : Check if OS access (ActivateTask, SuspendAllInterrupts, ..) */
/*                are authorized                                              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define KRN_bReadOsAccessAuthorized() \
   (KRN_bOsAccessAuthorized)


/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

#define KRN_START_SEC_CONST_UNSPECIFIED
#include "KRN_MemMap.h"

extern const KRN_tstrExceptionRegs KRN_kstrExceptionRegs;

#define KRN_STOP_SEC_CONST_UNSPECIFIED
#include "KRN_MemMap.h"


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define KRN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "KRN_MemMap.h"

extern KRN_tstrExceptionRegs KRN_strExceptionRegs;

#define KRN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "KRN_MemMap.h"

#define KRN_START_SEC_VAR_CLEARED_BOOLEAN
#include "KRN_MemMap.h"

extern volatile boolean KRN_bOsAccessAuthorized;

#define KRN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "KRN_MemMap.h"


#endif /* KRN_H */

/*-------------------------------- end of file -------------------------------*/

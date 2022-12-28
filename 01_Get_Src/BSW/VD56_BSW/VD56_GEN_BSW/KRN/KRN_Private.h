/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_Private.h                                           */
/* !Description     : Private Declaration of KRN Component                    */
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
 * %PID: P2017_BSW:0A192560.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef KRN_PRIVATE_H
#define KRN_PRIVATE_H

#include "Std_Types.h"
#include "Os.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* !Comment: MASK on MSB of registers of STM Counters                         */
#define MSB_16BITS_REGISTER_MASK     0x00008000
#define MSB_20BITS_REGISTER_MASK     0x00080000
#define MSB_24BITS_REGISTER_MASK     0x00800000
#define MSB_32BITS_REGISTER_MASK     0x80000000

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

#define KRN_START_SEC_CONST_32BIT
#include "KRN_MemMap.h"

// extern const uint32 RAM_BGN, RAM_END; // dbg : to be implmented next 
// extern const uint32 D_ROM, D_BGN, D_END; // dbg
// extern const uint32 STACK_BGN, STACK_END; // dbg
// extern const uint32 UNCLEARED_RAM_BGN, UNCLEARED_RAM_END; // dbg
// extern const uint32 RAM_DEVAID_BGN, RAM_DEVAID_END; // dbg

#define KRN_STOP_SEC_CONST_32BIT
#include "KRN_MemMap.h"


#define KRN_START_SEC_KRN_CKS_LOG
#include "KRN_MemMap.h"

extern const uint16 KRN_ku16SoftChecksum;

#define KRN_STOP_SEC_KRN_CKS_LOG
#include "KRN_MemMap.h"


#define KRN_START_SEC_KRN_CKS_CAL
#include "KRN_MemMap.h"

extern const uint16 KRN_ku16CalibChecksum;

#define KRN_STOP_SEC_KRN_CKS_CAL
#include "KRN_MemMap.h"


#define KRN_START_SEC_KRN_TAILLE_CAL
#include "KRN_MemMap.h"

extern const uint32 Taille_calib;

#define KRN_STOP_SEC_KRN_TAILLE_CAL
#include "KRN_MemMap.h"


#define KRN_START_SEC_KRN_VER_LDB
#include "KRN_MemMap.h"

extern const uint32 Version_ldb;

#define KRN_STOP_SEC_KRN_VER_LDB
#include "KRN_MemMap.h"


#define KRN_START_SEC_KRN_CKS_TMS_LOG
#include "KRN_MemMap.h"

extern const uint16 KRN_ku16TmsSoftChecksum;

#define KRN_STOP_SEC_KRN_CKS_TMS_LOG
#include "KRN_MemMap.h"


#define KRN_START_SEC_KRN_CKS_TMS_CAL
#include "KRN_MemMap.h"

extern const uint16 KRN_ku16TmsCalibChecksum;

#define KRN_STOP_SEC_KRN_CKS_TMS_CAL
#include "KRN_MemMap.h"

/******************************************************************************/
/* MACROS DECLARATION                                                         */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : KRN_vid60000msTaskFrom4000msInit                            */
/* !Description : Initialize the 60000ms task modulo                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define KRN_vid60000msTaskFrom4000msInit() \
   do \
   { \
      KRN_u8Modulo60000ms = 14; \
   } \
   while(0)


/******************************************************************************/
/* !FuncName    : KRN_vid60000msTaskFrom4000ms                                */
/* !Description : Activates the 60000ms task after 15 4000ms                  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define KRN_vid60000msTaskFrom4000ms() \
   do \
   { \
      KRN_u8Modulo60000ms++; \
      if (KRN_u8Modulo60000ms >= 15)\
      { \
         KRN_u8Modulo60000ms = 0; \
         (void)ActivateTask(OSTSK_C_60000MS); \
      } \
   } \
   while(0)


/******************************************************************************/
/* !FuncName    : KRN_vidEnableOsAccess                                       */
/* !Description : Enable OS access (ActivateTask, SuspendAllInterrupts, ..)   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define KRN_vidEnableOsAccess() \
   (KRN_bOsAccessAuthorized = 1)


/******************************************************************************/
/* !FuncName    : KRN_vidDisableOsAccess                                      */
/* !Description : Disable OS access (ActivateTask, SuspendAllInterrupts, ..)  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define KRN_vidDisableOsAccess() \
   (KRN_bOsAccessAuthorized = 0)


/******************************************************************************/
/* !FuncName    : KRN_vidStackMetric                                          */
/* !Description : Get the used stack size in u32                              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define KRN_vidStackMetric() \
do \
{ \
   /* OsMetricStacks(); stubbed for mockup */ \
   /*(void)OsGetUsedStack(OS_BASIC_TASKS, (StackRefType)&KRN_u32StackUsed); stubbed for mockup */ \
} \
while(0)

/******************************************************************************/
/* VARIABLES                                                                  */
/******************************************************************************/

#define KRN_START_SEC_VAR_CLEARED_BOOLEAN
#include "KRN_MemMap.h"
extern boolean KRN_bFirstCalibChecksumDone;
extern boolean KRN_bFirstSoftChecksumDone;
extern volatile boolean KRN_vbFirstTmsCalibChecksumDone;
extern volatile boolean KRN_vbFirstTmsSoftChecksumDone;
extern boolean KRN_bInitTmsChecksumOK;
extern volatile boolean KRN_bPowerOnCopyPerformed;
#define KRN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "KRN_MemMap.h"

#define KRN_START_SEC_VAR_CLEARED_16BIT
#include "KRN_MemMap.h"
extern uint16 KRN_u16CalibChecksum;
extern uint16 KRN_u16InitTmsCalibChecksum;
extern uint16 KRN_u16InitTmsSoftChecksum;
extern uint16 KRN_u16SchedulerOverrunCnt;
extern uint16 KRN_u16SoftChecksum;
extern uint16 KRN_u16TmsCalibChecksum;
extern uint16 KRN_u16TmsSoftChecksum;
extern uint16 Type_de_defaut_eep;
extern uint16 Compteur_defaut_except_eep;
extern uint16 Compteur_defaut_pile_eep;
#define KRN_STOP_SEC_VAR_CLEARED_16BIT
#include "KRN_MemMap.h"

#define KRN_START_SEC_VAR_CLEARED_32BIT
#include "KRN_MemMap.h"
extern uint32 KRN_u32CompareValue;
extern uint32 KRN_u32StackUsed;
extern uint32 ErrorAddress_eep;
#define KRN_STOP_SEC_VAR_CLEARED_32BIT
#include "KRN_MemMap.h"

#define KRN_START_SEC_VAR_CLEARED_8BIT
#include "KRN_MemMap.h"
extern uint8 KRN_u8Modulo60000ms;
#define KRN_STOP_SEC_VAR_CLEARED_8BIT
#include "KRN_MemMap.h"


#endif /* KRN_PRIVATE_H */

/*-------------------------------- end of file -------------------------------*/

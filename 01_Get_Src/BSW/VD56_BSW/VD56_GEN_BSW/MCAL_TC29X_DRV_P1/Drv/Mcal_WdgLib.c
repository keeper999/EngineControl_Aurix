/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Mcal_WdgLib.c $                                            **
**                                                                            **
**   $CC VERSION : \main\24 $                                                 **
**                                                                            **
**   $DATE       : 2014-01-28 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains Mcal Wdg library routines               **
**                                                                            **
**   SPECIFICATION(S) :    NA                                                 **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"
#include "IfxSrc_reg.h"
/* Own header file */
#include "Mcal.h"
#include "Mcal_TcLib.h"
#include "Mcal_Options.h"
#if (IFX_MCAL_USED == STD_ON)
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#endif
#ifdef VALEO_PATCH_MCAL_DRV_USE_SCHM
/* Include services for suspend/resume interrupts */
#include "SchM_17_McalCfg.h"
#include SCHM_MCAL_WDGLIB_HEADER
#endif /* VALEO_PATCH_MCAL_DRV_USE_SCHM */

/*******************************************************************************
**                      File Inclusion Check                                  **
*******************************************************************************/
#ifndef MCAL_SW_MAJOR_VERSION
#error "MCAL_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef MCAL_SW_MINOR_VERSION
  #error "MCAL_SW_MINOR_VERSION is not defined. "
#endif

#ifndef MCAL_SW_PATCH_VERSION
#error "MCAL_SW_PATCH_VERSION is not defined. "
#endif

#if ( MCAL_SW_MAJOR_VERSION != 1 )
  #error "MCAL_SW_MAJOR_VERSION does not match. "
#endif

#if ( MCAL_SW_MINOR_VERSION != 0 )
  #error "MCAL_SW_MINOR_VERSION does not match. "
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* max number of watch dogs (Safety, CPU0, CPU1 CPU2) */
#if ( MCAL_NO_OF_CORES == 3U )

#define MCAL_WDT_MAX_CPUWDT           ( 4u )

#else

#define MCAL_WDT_MAX_CPUWDT           ( 3u )

#endif

/* mask for password Bits 2-7 */
#define MCAL_WDT_PASSWORD_LOWER_MASK  ( 0x000000FCu )

/* mask for password Bits 8-15 */
#define MCAL_WDT_PASSWORD_UPPER_MASK  ( 0x0000FF00u )

/* mask for password bits */
#define MCAL_WDT_PASSWORD_MASK        ( MCAL_WDT_PASSWORD_LOWER_MASK | \
                                            MCAL_WDT_PASSWORD_UPPER_MASK)
/* mask for reload bits */
#define MCAL_WDT_RELOAD_MASK          ( 0xFFFF0000u )

/* mask for LCK and ENDINIT status bits */
#define MCAL_WDT_STATUS_MASK          ( 0x00000003u )

/* Reload value for watch dog in timeout mode */
#define SDWT_TIMEOUT_MODE_RELOAD      ( 0xFFFC0000u )

/** \\brief  F0, Safety WDT Control Register 0 */
#define MCAL_SCU_WDTS_CON0 /* lint --e(923)*/ \
                    (*(volatile Ifx_SCU_WDTCPU_CON0*)0xF00360F0u)
/** \\brief  F8, Safety WDT Status Register */
#define MCAL_SCU_WDTS_SR /* lint --e(923)*/ \
                          (*(volatile Ifx_SCU_WDTCPU_SR*)0xF00360F8u)
#define MCAL_CORE_ID_MASK   (0x7U)
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/* list element for generic watchdog access */
typedef struct ScuWdtPtrType
{
  /* pointer to WDTCON0 of this watch dog */
  volatile Ifx_SCU_WDTCPU_CON0*   Wdtcon0Ptr;
  /* pointer to WDTSSR  of this watch dog */
  volatile Ifx_SCU_WDTCPU_SR*     WdtssrPtr;
  /* Pointer to saved timer reload during timeout mode */
  uint32*                 WdtSaveValuePtr;
} ScuWdtPtrType;

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*
 * To be used for all global or static variables
 * that are never  initialized.
 */
#if (IFX_MCAL_USED == STD_ON)
#define MCAL_WDGLIB_START_SEC_VAR_INIT_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_WDGLIB_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif

/* used for nesting ENDINIT management */
#if ( MCAL_NO_OF_CORES == 3U )
static volatile uint32 Mcal_ResetEndInitCounter[MCAL_NO_OF_CORES] = {0U, 0U,0U};
#else
static volatile uint32 Mcal_ResetEndInitCounter[MCAL_NO_OF_CORES] = {0U, 0U};
#endif
/* used as temporarily variables for each watch dog, no external change
 * required! */
/* will hold the current timer value when switching to Timeout-Mode
 * (Reset/SetEndinit Sequence) this value will be used to restore as next reload
 * value, assuming that the original reload value will be setup again with the
 * expected modify access to service the watch dog regularly
 */
#if (IFX_MCAL_USED == STD_ON)
#define MCAL_WDGLIB_STOP_SEC_VAR_INIT_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_WDGLIB_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif

#if (IFX_MCAL_USED == STD_ON)
#define MCAL_WDGLIB_START_SEC_VAR_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_WDGLIB_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif

static uint32 Swdt_TimValue;
static uint32 Wdt0_TimValue;
static uint32 Wdt1_TimValue;
#if ( MCAL_NO_OF_CORES == 3U )
static uint32 Wdt2_TimValue;
#endif /* ( MCAL_NO_OF_CORES == 3U ) */

static uint32 Mcal_SafetyResetEndInitCounter;
/* Safety Endinit Semaphore */
uint32 Mcal_WdgSafetyEndInitSem;

#if (IFX_MCAL_USED == STD_ON)
#define MCAL_WDGLIB_STOP_SEC_VAR_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_WDGLIB_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif

#if (IFX_MCAL_USED == STD_ON)
#define MCAL_WDGLIB_START_SEC_CONST_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_WDGLIB_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif

/* access table for watch dog and local timer variables */
#if ( MCAL_NO_OF_CORES == 3U )
static const ScuWdtPtrType ScuWdtPtrList[MCAL_WDT_MAX_CPUWDT] =
{
  {
    &MCAL_SCU_WDTS_CON0,
    &MCAL_SCU_WDTS_SR,
    &Swdt_TimValue
  },
  {&SCU_WDTCPU0_CON0, &SCU_WDTCPU0_SR, &Wdt0_TimValue},
  {&SCU_WDTCPU1_CON0, &SCU_WDTCPU1_SR, &Wdt1_TimValue},
  {&SCU_WDTCPU2_CON0, &SCU_WDTCPU2_SR, &Wdt2_TimValue}
};
#else
static const ScuWdtPtrType ScuWdtPtrList[MCAL_WDT_MAX_CPUWDT] =
{
  {
    &MCAL_SCU_WDTS_CON0,
    &MCAL_SCU_WDTS_SR,
    &Swdt_TimValue
  },
  {&SCU_WDTCPU0_CON0, &SCU_WDTCPU0_SR, &Wdt0_TimValue},
  {&SCU_WDTCPU1_CON0, &SCU_WDTCPU1_SR, &Wdt1_TimValue}
};
#endif /* ( MCAL_NO_OF_CORES == 3U ) */

#if (IFX_MCAL_USED == STD_ON)
#define MCAL_WDGLIB_STOP_SEC_CONST_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_WDGLIB_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static uint32  Mcal_lCpuPwSequence
(
const sint8 wdt,
const uint32 Password
);

static uint32 Mcal_lCpuRelValue
(
const sint8 wdt,
const uint32 TimReload
);

static void Mcal_lResetCpuENDINIT
(
const sint8 wdt
);

static void Mcal_lSetCpuENDINIT
(
const sint8 wdt
);

static void Mcal_lCpuModifyAccess
(
const sint8 wdt,
const uint32 NewPassword,
const uint32 NewReload
);

static void Mcal_lCpuCheckAccess
(
const sint8 wdt,
const uint32 CheckPassword,
const uint32 CheckTimer
);

#if (IFX_MCAL_USED == STD_ON)
/*Memory Map of the Code*/
#define MCAL_WDGLIB_START_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#include "MemMap.h"
#else
#define IFX_MCAL_WDGLIB_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif

/*******************************************************************************
**                       Private Function Definitions                         **
*******************************************************************************/

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Mcal_CpuPwSequence (const sint8 wdt,                    **
**                      const uint32 Password)                                **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :  create expected password reload                        **
**                                                                            **
*******************************************************************************/
static uint32  Mcal_lCpuPwSequence (const sint8 wdt, const uint32 Password)
{
  uint32 Result = Password & MCAL_WDT_PASSWORD_MASK;

  volatile Ifx_SCU_WDTCPU_SR* ScuSsrPtr = ScuWdtPtrList[wdt+1].WdtssrPtr;

  /* first generate proper password write value
     (include PW Bit8-15 and inverted PW Bit 2-7) */
  Result = ( Result & MCAL_WDT_PASSWORD_UPPER_MASK) |
             ((~(Result & MCAL_WDT_PASSWORD_LOWER_MASK)) 
             & MCAL_WDT_PASSWORD_LOWER_MASK );

  /* additionally auto sequence password enabled ? */
  if (ScuSsrPtr->B.PAS != 0u)
  {
     /*  modify password with expected password by calculating new 14-bit LFSR
      *  with characteristic polynomial x14+x13+x12+x2+1.
      */
    uint32 lfsr = Result;
    uint32 bit  = ( (lfsr>>1) ^ (lfsr>>11) ^ (lfsr>>12) ^ (lfsr>>13) ) 
                    & 0x0004u;
    Result      = (((lfsr << 1) | bit ) & MCAL_WDT_PASSWORD_MASK);
  }
  return (Result);
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Mcal_lCpuRelValue (const sint8 wdt,                     **
**                      const uint32 TimReload)                               **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : create expected timer reload value                      **
**                                                                            **
*******************************************************************************/
static uint32 Mcal_lCpuRelValue(const sint8 wdt, const uint32 TimReload)
{
  uint32 Result = TimReload & MCAL_WDT_RELOAD_MASK;

  volatile Ifx_SCU_WDTCPU_SR* ScuSsrPtr = ScuWdtPtrList[wdt+1].WdtssrPtr;

  /* timer check enabled ? */
  if (ScuSsrPtr->B.TCS != 0u)
  {
      Result = ((uint32)~(uint32)ScuSsrPtr->B.TIM) << 16u;
  }
  return (Result);
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void Mcal_ResetCpuENDINIT(const sint8 wdt)       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :                                                         **
**                                                                            **
*******************************************************************************/
static void Mcal_lResetCpuENDINIT(const sint8 wdt)
{
  uint32 NewValCon0;
  uint32 NewPw;                   /* next password to be used */
  uint32 NewRel;                  /* next reload value to be used */
  uint32 Temp;
  volatile uint32 dummy;          /* ensure readback */

  volatile Ifx_SCU_WDTCPU_CON0* ScuWdtcon0Ptr 
                              = ScuWdtPtrList[wdt+1].Wdtcon0Ptr;
  volatile Ifx_SCU_WDTCPU_SR*   ScuSsrPtr     
                              = ScuWdtPtrList[wdt+1].WdtssrPtr;
  uint32* WdtTimPwSavePtr     = ScuWdtPtrList[wdt+1].WdtSaveValuePtr;

  /* Interrupts shall be disabled to avoid potential reentrant call and
   * unexpected delay during WDT timeout mode  */
#ifdef VALEO_PATCH_MCAL_DRV_USE_SCHM
   SchM_Enter_Mcal_WdgLib_CPU_ENDINIT();
#else
  Mcal_SuspendAllInterrupts();
#endif /* VALEO_PATCH_MCAL_DRV_USE_SCHM */

  /* save old value */
  NewValCon0  = ScuWdtcon0Ptr->U;

  /* get valid next password */
  NewPw  = Mcal_lCpuPwSequence(wdt, NewValCon0);

  /* get valid next timer reload */
  NewRel = Mcal_lCpuRelValue(wdt, NewValCon0);

  /* build required password WDTCON0 value */
  NewValCon0 =  ( (NewRel) |              /* new reload value  */
                  (NewPw)  |              /* new Password */
                  (1u) );                 /* Clear LCK, keep ENDINIT set */

  /* Read and save current timer and password to be restored with SetENDINIT*/
  Temp = (uint32)ScuWdtcon0Ptr->U & (uint32)MCAL_WDT_PASSWORD_MASK;
  Temp |= (uint32)ScuSsrPtr->U & (uint32)MCAL_WDT_RELOAD_MASK;
  *WdtTimPwSavePtr = Temp;

  ScuWdtcon0Ptr->U  = NewValCon0;        /* password access to unlock */

  NewValCon0 &= ~MCAL_WDT_STATUS_MASK;   /* clear ENDINIT and LCK Bit */
  NewValCon0 |= 0x2u;                    /* set LCK Bit */

  ScuWdtcon0Ptr->U = NewValCon0; /* write access and lock for Timeout mode */

  /* read back to ensure protection release is executed */
  dummy = ScuWdtcon0Ptr->U;
  UNUSED_PARAMETER(dummy)
}


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void Mcal_SetCpuENDINIT(const sint8 wdt)         **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :                                                         **
**                                                                            **
*******************************************************************************/
static void Mcal_lSetCpuENDINIT(const sint8 wdt)
{
  uint32 NewValCon0;
  uint32 NewPw;                   /* next password to be used */
  uint32 NewRel;                  /* next timer reload to be used */
  volatile uint32 dummy;          /* ensure readback */

  volatile Ifx_SCU_WDTCPU_CON0* ScuWdtcon0Ptr 
                                  = ScuWdtPtrList[wdt+1].Wdtcon0Ptr;
  volatile Ifx_SCU_WDTCPU_SR*   ScuSsrPtr     
                                  = ScuWdtPtrList[wdt+1].WdtssrPtr;
  uint32* WdtTimPwSavePtr         = ScuWdtPtrList[wdt+1].WdtSaveValuePtr;

  /* save old value */
  NewValCon0  = ScuWdtcon0Ptr->U;

  /* get valid next password */
  NewPw  = Mcal_lCpuPwSequence(wdt, NewValCon0);

  /* get valid next timer reload */
  NewRel = Mcal_lCpuRelValue(wdt, NewValCon0);

  /* build required password WDTCON0 value */
  NewValCon0  =  ( (NewRel) |             /* new reload value  */
                  (NewPw)   |             /* new Password */
                  (1u) );                 /* Clear LCK, keep ENDINIT set */

  ScuWdtcon0Ptr->U  = NewValCon0;         /*  unlock with password access */

  /* clear timer reload and restore saved and corrected reload value */
  NewValCon0 &= ~MCAL_WDT_RELOAD_MASK;

  /* set timer value back to prior value and add ticks during timeout mode */
  NewValCon0 |= ( *WdtTimPwSavePtr +
                  (((uint32)ScuSsrPtr->U & MCAL_WDT_RELOAD_MASK) -
                    SDWT_TIMEOUT_MODE_RELOAD)
                );

  /* prepare old password to be restored with modify access*/
  NewValCon0 &= ~MCAL_WDT_PASSWORD_MASK;
  NewValCon0 |= (*WdtTimPwSavePtr & MCAL_WDT_PASSWORD_UPPER_MASK) |
                ((~(*WdtTimPwSavePtr & MCAL_WDT_PASSWORD_LOWER_MASK)) 
                 & MCAL_WDT_PASSWORD_LOWER_MASK);

  /* prepare modify & lock access */
  NewValCon0 |= 3u;                      /* set LCK and ENDINIT Bit */
  ScuWdtcon0Ptr->U = NewValCon0;         /* write modify access and lock */

  /* read back to ensure protection release is executed */
  dummy = ScuWdtcon0Ptr->U;
  UNUSED_PARAMETER(dummy)

  /*  Interrupts allowed again */
#ifdef VALEO_PATCH_MCAL_DRV_USE_SCHM
   SchM_Exit_Mcal_WdgLib_CPU_ENDINIT();
#else
  Mcal_ResumeAllInterrupts();
#endif /* VALEO_PATCH_MCAL_DRV_USE_SCHM */
}


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void Mcal_CpuModifyAccess(const sint8 wdt, const **
**                      uint32 NewPassword, const uint32 NewReload)           **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :                                                         **
**                                                                            **
*******************************************************************************/
static void Mcal_lCpuModifyAccess
(
const sint8 wdt,
const uint32 NewPassword,
const uint32 NewReload
)
{
  uint32 NewValCon0;
  uint32 NewPw;               /* next password to be used */
  uint32 NewRel;              /* next timer reload to be used */
  uint32 NewTimer;            /* new timer to be setup */
  uint32 NewPwd;             /* new password to be setup */
  uint32 CurrState;           /* current state of LCK, ENDINIT */
  volatile uint32 dummy;      /* ensure readback */

  volatile Ifx_SCU_WDTCPU_CON0* ScuWdtcon0Ptr 
                                    = ScuWdtPtrList[wdt+1].Wdtcon0Ptr;

  /* Interrupts shall be disabled to avoid any other software using unlocked
   * watch dog / modify with different values */
  Mcal_SuspendAllInterrupts();

  NewValCon0 = ScuWdtcon0Ptr->U;                   /* save old value */
  CurrState  = NewValCon0 & MCAL_WDT_STATUS_MASK; /* save get current state */
  NewTimer   = NewValCon0 & MCAL_WDT_RELOAD_MASK; /* save current value */
  NewPwd     = NewValCon0 & MCAL_WDT_PASSWORD_MASK;/* save current pwd value*/

  /* get valid next password */
  NewPw  = Mcal_lCpuPwSequence(wdt, NewValCon0);

  /* get valid next timer reload */
  NewRel = Mcal_lCpuRelValue(wdt, NewValCon0);

  /* build required new WDTCON0 value */
  NewValCon0 =  ( (NewRel) |              /* new reload value  */
                  (NewPw)  |              /* new Password */
                  (1u) );                 /* Clear LCK, keep ENDINIT set */

  ScuWdtcon0Ptr->U  = NewValCon0;           /* unlock access */

  /* modify reload value requested? */
  if (NewReload <= MCAL_WDT_RELOAD_MAX)
  {
      NewTimer = NewReload << 16u;          /* yes, use new value */
  }

  /* modify password requested? */
  if (NewPassword <= MCAL_WDT_PASSWORD_MAX)
  {
      NewPwd = NewPassword;
  }

  /* clear timer reload and restore saved value or setup new values */
  NewValCon0 &= ~MCAL_WDT_RELOAD_MASK;
  NewValCon0 |= NewTimer;     /* set (new) timer value */


  /* clear password and restore saved value or setup new values */
  NewValCon0 &= ~MCAL_WDT_PASSWORD_MASK;   /* clear old bits */
  /* adjust to valid bits only and prepare write value */
  NewValCon0 |= (NewPwd & MCAL_WDT_PASSWORD_UPPER_MASK) |
                ((~(NewPwd & MCAL_WDT_PASSWORD_LOWER_MASK)) 
                & MCAL_WDT_PASSWORD_LOWER_MASK);

  /* restore LCK and ENDINIT settings */
  NewValCon0 &= ~MCAL_WDT_STATUS_MASK;         /* clear LCK and ENDINIT */
  NewValCon0 |= CurrState;

  /* modify write access and restore lock state */
  ScuWdtcon0Ptr->U = NewValCon0;               

  /* read back to ensure protection release is executed */
  dummy = ScuWdtcon0Ptr->U;
  UNUSED_PARAMETER(dummy)    

  /*  Interrupts allowed again */
  Mcal_ResumeAllInterrupts();
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void Mcal_CpuCheckAccess(const sint8 wdt, const  **
**                      uint32 CheckPassword, const uint32 CheckTimer)        **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :                                                         **
**                                                                            **
*******************************************************************************/
static void Mcal_lCpuCheckAccess
(
 const sint8 wdt,
 const uint32 CheckPassword,
 const uint32 CheckTimer
)
{
  uint32  NewValCon0;

  volatile Ifx_SCU_WDTCPU_CON0* ScuWdtcon0Ptr 
                          = ScuWdtPtrList[wdt+1].Wdtcon0Ptr;

  /* save old value (without ENDINIT/LOCK) */
  NewValCon0  = (uint32)ScuWdtcon0Ptr->U & ~(uint32)MCAL_WDT_STATUS_MASK;

  /* password check always requested */
  NewValCon0 &= ~MCAL_WDT_PASSWORD_MASK; /* clear out old password */

  /* password must match exactly the expected range! */
  NewValCon0 |= CheckPassword;

  /* timer check additionally requested? */
  if (CheckTimer <= MCAL_WDT_RELOAD_MAX)
  {
    NewValCon0 &= ~MCAL_WDT_RELOAD_MASK;
    NewValCon0 |= CheckTimer << 16u;      /* set timer value to be checked */
  }

  NewValCon0 |= 3u;       /* set LCK and ENDINIT Bit for check access */

  /* check access functionality not available with A-Step */
  ScuWdtcon0Ptr->U = NewValCon0;             /* check access, no modify */

}

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/



/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR122_10 ]        [/cover]
**                                                                            **
** Syntax           : void Mcal_ResetENDINIT(void)                            **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Clears the ENDINIT bit in the appropriate CPU           **
**                    available for CPU0, CPU1 and CPU2 watchdogs             **
**                    Proper password is calculated and restored on           **
**                    modify access disables interrupts and save current Wdt  **
**                    timer reload value                                      **
**                                                                            **
*******************************************************************************/
void Mcal_ResetENDINIT( void )
{
  uint32 CoreID = ((uint32)MFCR(CPU_CORE_ID) & MCAL_CORE_ID_MASK);
  
  if (Mcal_ResetEndInitCounter[CoreID] == 0U)
  {
    Mcal_lResetCpuENDINIT((sint8)CoreID);
  }
#ifdef VALEO_PATCH_MCAL_DRV_USE_SCHM
   SchM_Enter_Mcal_WdgLib_RESET_ENDINIT();
#else
  Mcal_SuspendAllInterrupts();
#endif /* VALEO_PATCH_MCAL_DRV_USE_SCHM */
  Mcal_ResetEndInitCounter[CoreID]++;
#ifdef VALEO_PATCH_MCAL_DRV_USE_SCHM
   SchM_Exit_Mcal_WdgLib_RESET_ENDINIT();
#else
  Mcal_ResumeAllInterrupts();
#endif /* VALEO_PATCH_MCAL_DRV_USE_SCHM */
}

/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR122_12 ]        [/cover]
**                                                                            **
** Syntax           : Std_ReturnType Mcal_ResetSafetyENDINIT(void)            **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                                                                            **
** Description      : Clears the ENDINIT bit in the appropriate CPU           **
**                    available for  CPU0, CPU1 and CPU2                      **
**                    watchdogs Proper password is calculated and restored on **
**                    modify access disables interrupts and save current Wdt  **
**                    timer reload value                                      **
**                                                                            **
*******************************************************************************/
void Mcal_ResetSafetyENDINIT( void )
{
  if (Mcal_SafetyResetEndInitCounter == 0U)
  {
    Mcal_lResetCpuENDINIT( -1 );
  }

#ifdef VALEO_PATCH_MCAL_DRV_USE_SCHM
   SchM_Enter_Mcal_WdgLib_RESET_SAFETY_ENDINIT();
#else
  Mcal_SuspendAllInterrupts();
#endif /* VALEO_PATCH_MCAL_DRV_USE_SCHM */
  Mcal_SafetyResetEndInitCounter++;
#ifdef VALEO_PATCH_MCAL_DRV_USE_SCHM
   SchM_Exit_Mcal_WdgLib_RESET_SAFETY_ENDINIT();
#else
  Mcal_ResumeAllInterrupts();
#endif /* VALEO_PATCH_MCAL_DRV_USE_SCHM */
}



/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR122_9 ]        [/cover]
**                                                                            **
** Syntax           : void Mcal_SetENDINIT(void)                              **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Sets the ENDINIT bit in the appropriate CPU             **
**                    available for global safety                             **
**                    watchdogs Proper password is calculated and restored on **
**                    modify access Enables interrupts and restores timer     **
**                    reload value                                            **
**                                                                            **
*******************************************************************************/
void Mcal_SetENDINIT( void )
{
  uint32 CoreID = ((uint32)MFCR(CPU_CORE_ID) & MCAL_CORE_ID_MASK);
  
#ifdef VALEO_PATCH_MCAL_DRV_USE_SCHM
   SchM_Enter_Mcal_WdgLib_SET_ENDINIT();
#else
  Mcal_SuspendAllInterrupts();
#endif /* VALEO_PATCH_MCAL_DRV_USE_SCHM */
  if (Mcal_ResetEndInitCounter[CoreID] > 0U)
  {
      Mcal_ResetEndInitCounter[CoreID]--;
  }
#ifdef VALEO_PATCH_MCAL_DRV_USE_SCHM
   SchM_Exit_Mcal_WdgLib_SET_ENDINIT();
#else
  Mcal_ResumeAllInterrupts();
#endif /* VALEO_PATCH_MCAL_DRV_USE_SCHM */

  if (Mcal_ResetEndInitCounter[CoreID] == 0U)
  {
      Mcal_lSetCpuENDINIT( (sint8)CoreID );
  }
}


/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR122_11 ]        [/cover]
**                                                                            **
** Syntax           : Std_ReturnType Mcal_SetSafetyENDINIT(void)              **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                                                                            **
** Description      : Sets the ENDINIT bit in the appropriate CPU             **
**                    available for global safety                             **
**                    watchdogs Proper password is calculated and restored on **
**                    modify access Enables interrupts and restores timer     **
**                    reload value                                            **
**                                                                            **
*******************************************************************************/
void Mcal_SetSafetyENDINIT( void )
{
#ifdef VALEO_PATCH_MCAL_DRV_USE_SCHM
   SchM_Enter_Mcal_WdgLib_SET_SAFETY_ENDINIT();
#else
  Mcal_SuspendAllInterrupts();
#endif /* VALEO_PATCH_MCAL_DRV_USE_SCHM */
  if (Mcal_SafetyResetEndInitCounter > 0U)
  {
      Mcal_SafetyResetEndInitCounter--;
  }
#ifdef VALEO_PATCH_MCAL_DRV_USE_SCHM
   SchM_Exit_Mcal_WdgLib_SET_SAFETY_ENDINIT();
#else
  Mcal_ResumeAllInterrupts();
#endif /* VALEO_PATCH_MCAL_DRV_USE_SCHM */

  if (Mcal_SafetyResetEndInitCounter == 0U)
  {
      Mcal_lSetCpuENDINIT( -1 );
  }
}


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Mcal_xxxModifyAccess                               **
**                    (const uint32 NewPassword, const uint32 NewReload)      **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : NewPassword: new password to be set                     **
**                      if value > MCAL_WDT_PASSWORD_MAX                      **
**                      this value is ignored and the                         **
**                      old password will be restored                         **
**                    NewReload: New timer reload value to be used            **
**                      if value > MCAL_WDT_RELOAD_MAX this value             **
**                      will be ignored and the old timer value               **
**                      will be restored                                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Sets the new values for Password and/or timer reload    **
**                    value available for CPU0, CPU1 and CPU2 and global      **
**                    safety watchdogs Proper password is calculated, new     **
**                    values restored on modify access.                       **
**                    Disable interrupts during unlocked phase                **
**                                                                            **
*******************************************************************************/
void Mcal_SafetyModifyAccess(const uint32 NewPassword,const uint32 NewReload )
{
  Mcal_lCpuModifyAccess( -1, NewPassword, NewReload );
}


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Mcal_xxxModifyAccess                               **
**                    (const uint32 NewPassword, const uint32 NewReload)      **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : NewPassword: new password to be set                     **
**                      if value > MCAL_WDT_PASSWORD_MAX                      **
**                      this value is ignored and the                         **
**                      old password will be restored                         **
**                    NewReload: New timer reload value to be used            **
**                      if value > MCAL_WDT_RELOAD_MAX this value             **
**                      will be ignored and the old timer value               **
**                      will be restored                                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Sets the new values for Password and/or timer reload    **
**                    value available for CPU0, CPU1 and CPU2 and global      **
**                    safety watchdogs Proper password is calculated, new     **
**                    values restored on modify access.                       **
**                    Disable interrupts during unlocked phase                **
**                                                                            **
*******************************************************************************/
void Mcal_CpuWdtModifyAccess(const uint32 NewPassword,const uint32 NewReload)
{
  uint8 CoreId = ((uint8)MFCR(CPU_CORE_ID)) & (uint8)MCAL_CORE_ID_MASK;
  Mcal_lCpuModifyAccess( (sint8)(CoreId), NewPassword, NewReload );
}


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Mcal_xxxCheckAccess                                **
**                    (const uint32 CheckPassword, const uint32 CheckTimer)   **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : CheckPassword: Password to be used for check access     **
**                      this value will be checked always and must match the  **
**                      required password                                     **
**                    CheckTimer :Timer value to be checked                   **
**                      if value > MCAL_WDT_RELOAD_MAX this value will be     **
**                      not be used for timer check.                          **
**                      the old timer value will be used for check access     **
**                                                                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : executes check access to verify password/timer          **
**                    (optional) available for CPU0, CPU1 and CPU2 and global **
**                    safety watchdogs Given password and timer are used on   **
**                    check access                                            **
**                                                                            **
*******************************************************************************/
void Mcal_SafetyCheckAccess(const uint32 CheckPassword,const uint32 CheckTimer)
{
    Mcal_lCpuCheckAccess( -1, CheckPassword, CheckTimer );
}


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Mcal_xxxCheckAccess                                **
**                    (const uint32 CheckPassword, const uint32 CheckTimer)   **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : CheckPassword: Password to be used for check access     **
**                      this value will be checked always and must match the  **
**                      required password                                     **
**                    CheckTimer: Timer value to be checked                   **
**                      if value > MCAL_WDT_RELOAD_MAX this value will be     **
**                      not be used for timer check.                          **
**                      the old timer value will be used for check access     **
**                                                                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : executes check access to verify password/timer          **
**                    (optional) available for CPU0, CPU1 and CPU2 and global **
**                    safety watchdogs Given password and timer are used on   **
**                    check access                                            **
**                                                                            **
*******************************************************************************/
void Mcal_CpuWdtCheckAccess(const uint32 CheckPassword,const uint32 CheckTimer)
{
  uint8 CoreId = ((uint8)MFCR(CPU_CORE_ID)) & (uint8)MCAL_CORE_ID_MASK;
  Mcal_lCpuCheckAccess( (sint8)CoreId, CheckPassword, CheckTimer );
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : uint32 Mcal_xxxxPwSequence (const uint32 Password)      **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : Password: start password to be used for calculation of  **
**                              resulting password value                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : valid password according to password mode               **
**                                                                            **
** Description      : calculates the expected next password                   **
**                                                                            **
*******************************************************************************/
uint32 Mcal_SafetyPwSequence( const uint32 Password )
{
    return (Mcal_lCpuPwSequence( -1, Password) );
}


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : uint32 Mcal_xxxxPwSequence (const uint32 Password)      **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : Password: start password to be used for calculation of  **
**                              resulting password value                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : valid password according to password mode               **
**                                                                            **
** Description      : calculates the expected next password                   **
**                                                                            **
*******************************************************************************/
uint32 Mcal_CpuWdtPwSequence( const uint32 Password )
{
  uint8 CoreId = ((uint8)MFCR(CPU_CORE_ID)) & (uint8)MCAL_CORE_ID_MASK;
  return (Mcal_lCpuPwSequence((sint8)CoreId, Password));
}
#if (IFX_MCAL_USED == STD_ON)
/*Memory Map of the Code*/
#define MCAL_WDGLIB_STOP_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#include "MemMap.h"
#else
#define IFX_MCAL_WDGLIB_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif

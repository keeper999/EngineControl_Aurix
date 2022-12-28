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
**   $FILENAME   : Mcal_WdgLib.h $                                            **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2014-01-31 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This header file exports Mcal Wdg library                  **
                   type definitions and functions                             **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                            **
*******************************************************************************/
#ifndef MCAL_WDGLIB_H 
#define MCAL_WDGLIB_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Mcal_Compiler.h"
#ifdef VALEO_PATCH_MCAL_DRV_INCLUDE_MCAL_OPTIONS_H
#include "Mcal_Options.h"
#endif /* VALEO_PATCH_MCAL_DRV_INCLUDE_MCAL_OPTIONS_H */

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Fix part of password  */
#define MCAL_WDT_PW_FIXPART_READ      ( 0x000Cu )

/* max. value for password (as used in lower 16Bits of WDTCON0) */
#define MCAL_WDT_PASSWORD_MAX  ( 0xFFFFu )

/* max. value for reload */
#define MCAL_WDT_RELOAD_MAX  ( 0xFFFFu )



/* ignore value on password modify */
#define MCAL_WDT_PASSWORD_IGNORE  ( 0xFFFFFFFFu )

/* ignore value on timer reload modify */
#define MCAL_WDT_RELOAD_IGNORE  ( 0xFFFFFFFFu )

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#ifdef VALEO_PATCH_MCAL_DRV_MEMMAP_SEC
#if (IFX_MCAL_USED == STD_ON)
#define MCAL_WDGLIB_START_SEC_VAR_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_WDGLIB_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif
#endif /* VALEO_PATCH_MCAL_DRV_MEMMAP_SEC */

extern uint32 Mcal_WdgSafetyEndInitSem;

#ifdef VALEO_PATCH_MCAL_DRV_MEMMAP_SEC
#if (IFX_MCAL_USED == STD_ON)
#define MCAL_WDGLIB_STOP_SEC_VAR_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_WDGLIB_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif
#endif /* VALEO_PATCH_MCAL_DRV_MEMMAP_SEC */

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#ifdef VALEO_PATCH_MCAL_DRV_MEMMAP_SEC
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
#endif /* VALEO_PATCH_MCAL_DRV_MEMMAP_SEC */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
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
extern void Mcal_ResetSafetyENDINIT(void);
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
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
extern void Mcal_ResetENDINIT(void);


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
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
extern void Mcal_SetENDINIT( void );
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
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
extern void Mcal_SetSafetyENDINIT(void);

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
extern void Mcal_SafetyModifyAccess
(
const uint32 NewPassword,
const uint32 NewReload
);

extern void Mcal_CpuWdtModifyAccess
(
const uint32 NewPassword,
const uint32 NewReload
);



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
extern void Mcal_SafetyCheckAccess
(
const uint32 CheckPassword,
const uint32 CheckTimer
);

extern void Mcal_CpuWdtCheckAccess
(
const uint32 CheckPassword,
const uint32 CheckTimer
);



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
extern uint32 Mcal_SafetyPwSequence
(
const uint32 Password
);

extern uint32 Mcal_CpuWdtPwSequence
(
const uint32 Password
);



/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Mcal_ResetSafetyENDINIT_Timed(uint32 Count)
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Count: Count of no of times to try for SafetyEndInit    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function calls the Mcal_ResetSafetyENDINIT in 
                      a loop (with some delay between calls) till it is 
                      successful or max no of times given by count            **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Mcal_ResetSafetyENDINIT_Timed(uint32 TimeOut)
{
  Std_ReturnType RetVal;
  RetVal = Mcal_GetSpinLock(&Mcal_WdgSafetyEndInitSem, TimeOut);
  Mcal_ResetSafetyENDINIT();
  UNUSED_PARAMETER(RetVal)
} 

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Mcal_SetSafetyENDINIT_Timed(void)
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Count: Count of no of times to try for SafetyEndInit    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function calls the Mcal_SetSafetyENDINIT in 
                      a loop (with some delay between calls) till it is 
                      successful or max no of times given by count            **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Mcal_SetSafetyENDINIT_Timed(void)
{
    Mcal_SetSafetyENDINIT();
    Mcal_ReleaseSpinLock(&Mcal_WdgSafetyEndInitSem);
} 

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : uint16 Mcal_WdtCalcSeqPassword(uint16 SeqPassword)      **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : SeqPassword: Previous password used to unlock WDTCON0   **
**                    SeqPassword shall be 14 bit value                       **
**                     maximum 16383 to minimum 1                             **
**                  Note: CoU - It is assumed that user shall not read        **
**                      SeqPassword value from the WDTCON0 register           **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : returns next sequence password                          **
**                                                                            **
** Description      : To calculate password using14-bit LFSR (Linear Feedback **
**                    Shift Register) with characteristic                     **
**                       polynomial x14+x13+x12+x2+1.                         **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint16 Mcal_WdtCalcSeqPassword(uint16 SeqPassword)
{
  uint16 InterPasswordl;  
  uint16 Expected_Passl;
  /* calculate 2nd bit position value */
  InterPasswordl = ((SeqPassword >> 15U)^(SeqPassword >> 14U)^
                       (SeqPassword >> 13U)^(SeqPassword >> 3U)) & 1U;
  /*shift each each bit by 1 towards left */  
  Expected_Passl = ((SeqPassword << 1U)|(InterPasswordl << 2U)) & 0x0000FFFFU;
  /* return the calculated next sequence password value */
  return(Expected_Passl);
}

#ifdef VALEO_PATCH_MCAL_DRV_MEMMAP_SEC
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
#endif /* VALEO_PATCH_MCAL_DRV_MEMMAP_SEC */

#endif /* MCAL_WDGLIB_H  */


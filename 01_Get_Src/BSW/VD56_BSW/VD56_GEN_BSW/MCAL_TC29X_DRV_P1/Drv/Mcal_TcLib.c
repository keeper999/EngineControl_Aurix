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
**   $FILENAME   : Mcal_TcLib.c $                                             **
**                                                                            **
**   $CC VERSION : \main\20 $                                                 **
**                                                                            **
**   $DATE       : 2014-02-04 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains Mcal Tricore library routines           **
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
#include "IfxCpu_reg.h"
#include "IfxSrc_reg.h"
/* Own header file */
#include "Mcal.h"
#include "Mcal_Options.h"

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
#define MCAL_DBGST_HALT  (0U)
#define MCAL_DBGST_RUN   (1U)
#define MCAL_PMST_NORMAL (1U)
#define MCAL_PMST_IDLE   (3U)


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#if (IFX_MCAL_USED == STD_ON)
#define MCAL_TCLIB_START_SEC_VAR_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_TCLIB_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif
/* used for nesting enable/disable management */
static uint32 Mcal_SavedIntSate[MCAL_NO_OF_CORES];
static uint32 Mcal_IntDisableCounter[MCAL_NO_OF_CORES];

#if (IFX_MCAL_USED == STD_ON)
#define MCAL_TCLIB_STOP_SEC_VAR_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_TCLIB_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif
/*
 * To be used for all global or static variables
 * that are never  initialized.
 */
#if (IFX_MCAL_USED == STD_ON)
#define MCAL_TCLIB_START_SEC_CONST_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_TCLIB_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif

#if ( MCAL_NO_OF_CORES == 3U )   
static Ifx_CPU* const Mcal_CpuAddressMap[MCAL_NO_OF_CORES] =
{
  &MODULE_CPU0,
  &MODULE_CPU1,
  &MODULE_CPU2
};
#else
static Ifx_CPU* const Mcal_CpuAddressMap[MCAL_NO_OF_CORES] =
{
  &MODULE_CPU0,
  &MODULE_CPU1
};
#endif /* ( MCAL_NO_OF_CORES == 3U ) */ 

#if (IFX_MCAL_USED == STD_ON)
#define MCAL_TCLIB_STOP_SEC_CONST_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_TCLIB_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif


#if (IFX_MCAL_USED == STD_ON)
/*Memory Map of the Code*/
#define MCAL_TCLIB_START_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#include "MemMap.h"
#else
#define IFX_MCAL_TCLIB_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static Ifx_CPU* Mcal_GetCpuAddress(uint8 CpuId);

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR122_13 ]        [/cover]
** Syntax : uint32 Mcal_GetCoreId(void)                                       **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Core ID                                                 **
**                                                                            **
** Description : This function returns the core ID of the core on which       **
              it is executing.                                                **
*******************************************************************************/
uint8 Mcal_GetCoreId(void)
{
  uint8 RetVal;

  RetVal = (uint8)MFCR(CPU_CORE_ID) ;
  return RetVal;
}

/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR122_14 ]        [/cover]
** Syntax : uint32 Mcal_GetDsprReMapAddress(uint32 Address)                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Remapped DSPR address                                   **
**                                                                            **
** Description : This function maps the DSPR address to the global address    **
              which can be used by other cores or Dma                         **
*******************************************************************************/
uint32 Mcal_GetDsprReMapAddress(uint32 Address)
{
  uint32 RetAddress;
  uint8  CoreId;

  if ((Address & 0xF0000000U) == 0xD0000000U)
  {
    CoreId = Mcal_GetCoreId();
  
    #if defined MCALLIB_DEBUG1
    #if (MCALLIB_DEBUG1 == STD_ON)
    CoreId = 1U;
    #endif
    #elif defined MCALLIB_DEBUG2
    #if (MCALLIB_DEBUG2 == STD_ON)
    CoreId = 2U;
    #endif
    #endif
  
    switch(CoreId)
    {
      case 0:
        RetAddress = ((Address & 0x0000FFFFU) | 0x70000000U);
        break;
      case 1:
        RetAddress = ((Address & 0x0000FFFFU) | 0x60000000U);
        break;
      default:
        /* CPU2 is cosidered as default */
        #if ( MCAL_NO_OF_CORES == 3U )
        RetAddress = ((Address & 0x0000FFFFU) | 0x50000000U);
    #else
    RetAddress = Address;
        #endif
        break;
    }
  }
  else
  {
    RetAddress = Address;
  }
  return RetAddress;
}

/*******************************************************************************
** Syntax : Ifx_CPU* Mcal_GetCpuAddress(uint8 CpuId)                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  CPU base address                                        **
**                                                                            **
** Description : This function get the CPU base address of the provided CPU ID**
*******************************************************************************/
static Ifx_CPU* Mcal_GetCpuAddress(uint8 CpuId)
{
    Ifx_CPU* module;

    /* Get the base address of the CPU from the structure */
    module = Mcal_CpuAddressMap[CpuId];

    return(module);
}

/*******************************************************************************
** Syntax : void Mcal_SetCpuPC (uint8 CpuNo, uint32 ProgramCounter)           **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  CpuNo - CPU index                                       **
**                    ProgramCounter - Address to be updated in PC register   **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : This function updates the PC register of the corresponding   **
**               CPU with the provided address                                **
*******************************************************************************/
void Mcal_SetCpuPC (uint8 CpuNo, uint32 ProgramCounter)
{
  Ifx_CPU* CpuBase;

  if( CpuNo < MCAL_NO_OF_CORES )
  {
    /* Get the base address of the CPU */
    CpuBase = Mcal_GetCpuAddress(CpuNo);
    /* Set the PC */
    CpuBase->PC.U = ProgramCounter;
  }
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
** Syntax : void Mcal_StartCore (uint8 CpuNo, uint32 Pcval)                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  CpuNo - CPU index                                       **
**                    Pcval - Address to be updated in PC register            **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : This function updates the PC register of the corresponding   **
**               CPU with the provided address and puts the CPU to run mode   **
*******************************************************************************/
void Mcal_StartCore (uint8 CpuNo, uint32 Pcval)
{
    Ifx_CPU* CpuBase;
    volatile Ifx_CPU_DBGSR DbgsrValue;

    if( CpuNo < MCAL_NO_OF_CORES )
    {
      CpuBase = Mcal_GetCpuAddress(CpuNo);

      /* Set the PC for the Core*/
      Mcal_SetCpuPC (CpuNo, Pcval);

      /* Set the CPU to run mode */
      DbgsrValue.U = CpuBase->DBGSR.U;
      DbgsrValue.B.HALT = 0x2U;
      CpuBase->DBGSR.U = DbgsrValue.U;
    }

}

/*******************************************************************************
** Syntax : uint32 Mcal_lLockResource(uint32 *ResourcePtr)                    **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  ResourcePtr - Pointer to variable representing the      **
**                    resource                                                **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value     : MCAL_RESOURCE_BUSY-If Resource was already locked       **
**                    MCAL_RESOURCE_FREE-If Resource is free for use          **
**                                                                            **
** Description      : This function is a implementation of a binary semaphore **
**                    using the "CmpAndswap" instruction of tricore.          **
**                    If a resource is free, the semaphore is taken and       **
**                    status MCAL_RESOURCE_FREE is returned.                  **
**                    If the resource was already taken,                      **
**                    a busy status (MCAL_RESOURCE_BUSY) is returned.         **
*******************************************************************************/
uint32 Mcal_lLockResource(uint32 *ResourcePtr)
{
  /*
  Sets semaphore at address res_status automatically to MCAL_RESOURCE_BUSY = 1
  and returns the previous semaphore state.
  */
  uint32 RetVal;

  RetVal = (uint32)MCAL_RESOURCE_BUSY;

  if( ResourcePtr != NULL_PTR )
  {
    RetVal = (uint32)
       Mcal_CmpAndSwap((uint32_t*)ResourcePtr,RetVal,MCAL_RESOURCE_FREE);
  }

  return (RetVal);
}

/*******************************************************************************
** Syntax : void  Mcal_lUnlockResource(uint32* ResourcePtr)                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  ResourcePtr - Pointer to variable representing the      **
**                    resource                                                **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description      : This function Frees the Resource already locked .       **
*******************************************************************************/
void  Mcal_lUnlockResource(uint32* ResourcePtr)
{
  if( ResourcePtr != NULL_PTR )
  {
    /*
    Sets semaphore at address res_status atomically to MCAL_RESOURCE_FREE = 0.
    */
    *ResourcePtr = (uint32)MCAL_RESOURCE_FREE;
  }
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Mcal_GetSpinLock                         **
**                    (                                                       **
**                      uint32* SpinLckPtr,uint32 Timeout                     **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : SpinLckPtr: Spinlock to be acquired                     **
**                    Timeout: Wait duration for acquisition of SpinLock      **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :                                                         **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcal_GetSpinLock(uint32* SpinLckPtr,uint32 Timeout)
{
  Std_ReturnType RetVal;
  uint32 SpinLockVal;

  RetVal = E_NOT_OK;

  if( SpinLckPtr != NULL_PTR )
  {
    do
    {

      SpinLockVal = 1UL;
      SpinLockVal = (uint32)
          Mcal_CmpAndSwap((uint32_t *)SpinLckPtr,SpinLockVal,0U);

      /* Check if the SpinLock WAS set before the attempt to acquire spinlock */
      if(SpinLockVal == 0U)
      {
        RetVal = E_OK;
      }
      else
      {
        Timeout-- ;

      }
    } while((RetVal == E_NOT_OK) && (Timeout > 0U));
  }

  return(RetVal);
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Mcal_ReleaseSpinLock                               **
**                    (                                                       **
**                      uint32* SpinLckPtr                                    **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : SpinLckPtr: Spinlock to be released                     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :                                                         **
**                                                                            **
*******************************************************************************/
void Mcal_ReleaseSpinLock(uint32* SpinLckPtr)
{
  if( SpinLckPtr != NULL_PTR )
  {
    /*Reset the SpinLock*/
    *SpinLckPtr = 0U;
  }
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Mcal_SuspendAllInterrupts(void)                    **
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
** Description      : Mcal_SuspendAllInterrupts, disables all interrupts      **
**                    Nesting disable/enable supported                        **
** Caution          : shall not be called prior to C-init                     **
*******************************************************************************/
void Mcal_SuspendAllInterrupts(void)
{
  uint32 CoreID = ((uint32)MFCR(CPU_CORE_ID) & 0x7u);
  if (Mcal_IntDisableCounter[CoreID] == 0U)
  {
    ISYNC();
    Mcal_SavedIntSate[CoreID] = (uint32)MFCR(CPU_ICR);
    /* disable interrupts */
    Mcal_DisableAllInterrupts();
  }

  Mcal_IntDisableCounter[CoreID]++;
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Mcal_ResumeAllInterrupts( void )                   **
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
** Description      : Mcal_ResumeAllInterrupts, re-enables interrupts         **
**                    Nesting disable/enable supported                        **
** Caution          : shall not be called prior to C-init                     **
*******************************************************************************/
void Mcal_ResumeAllInterrupts(void)
{
  uint32 CoreID = ((uint32)MFCR(CPU_CORE_ID) & 0x7u);
  if (Mcal_IntDisableCounter[CoreID] > 0U)
    {
        Mcal_IntDisableCounter[CoreID]--;
    }

    if(Mcal_IntDisableCounter[CoreID] == 0U)
    {
        if ((Mcal_SavedIntSate[CoreID] & ((uint32)1U << 15U)) != 0U)
        {
            /* interrupts were enabled, enable again */
            Mcal_EnableAllInterrupts();
        }
    }
}

#if (IFX_MCAL_USED == STD_ON)
/*Memory Map of the Code*/
#define MCAL_TCLIB_STOP_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#include "MemMap.h"
#else
#define IFX_MCAL_TCLIB_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif

/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Fls_17_Pmu_ac.c $                                          **
**                                                                           **
**  $CC VERSION : \main\25 $                                                 **
**                                                                           **
**  $DATE       : 2013-09-02 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains command sequences of Flash driver      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
   Traceability   :
                    [cover parentID=DS_AS_FLS137]
                    [/cover]
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Tasking sfr file */
#include "IfxFlash_reg.h"

/* Inclusion of Flash header file */
#include "Fls_17_Pmu.h"

/* Include Flash Module access code File */
#include "Fls_17_Pmu_ac.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* size of data loaded into page buffer at a time - 8bytes */
#define FLS_LOAD_PAGE_SIZE   (8U)

/* For internal debugging */
#ifdef IFX_FLS_DEBUG01
#define VALUE_51  (((uint32)(0x00000051U)))
#endif

#ifdef IFX_FLS_DEBUG02
#define VALUE_A1  (((uint32)(0x000000A1U)))
#endif

#ifdef IFX_FLS_DEBUG05
extern volatile uint32 TestFls_DebugMask05;
#endif
#ifdef IFX_FLS_DEBUG06
extern volatile uint32 TestFls_DebugMask06;
#endif

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

static _INLINE_ boolean Fls_lCmdCycleTimeout05(uint32 InnerCount);

static _INLINE_ boolean Fls_lCmdCycleTimeout06(uint32 InnerCount);

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
** Syntax : void Fls_WriteCmdCycles( volatile uint32 StartAddress,            **
**                                   uint32 PageAddress,                      **
**                                   const Fls_AddressType* ProgramDataPtr    **
**                                )                                           **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StartAddress,PageAddress and ProgramDataPtr              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine contains flash write command cycles             **
*******************************************************************************/
#define FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN
#include "MemMap.h"
void Fls_WriteCmdCycles( volatile uint32 StartAddress,
                         uint32 PageAddress, 
                         const Fls_AddressType* ProgramDataPtr,
                         uint8 WriteMode
                       )
{
  uint32 InnerCount;
  const FLASH_DATA *pdata;
  Fls_17_Pmu_StateType* StatePtr;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  StatePtr->FlsTimeoutErr = 0U;
  
  pdata = (const FLASH_DATA *)(void*)ProgramDataPtr;
   
  /* Enter the Page Mode */
  EnterPageMode(StartAddress, VALUE_5D);

  InnerCount = 0U;
  
  while((FLASH0_FSR.B.DFPAGE != 1U) && (InnerCount < FLS_CMDCYCLE_TIMEOUT))
  {
    InnerCount++;
  }
  

  /* Check for command cycle Timeout */
  if ((boolean)TRUE == Fls_lCmdCycleTimeout05(InnerCount))
  {
    StatePtr->FlsTimeoutErr = FLS_WRITE;
  }
  else
  /* Check DFPAGE bit was SET */
  {
    if(WriteMode == BURST_WRITE)
    {
      InnerCount = (FLS_BURST_PAGE_SIZE / FLS_LOAD_PAGE_SIZE);
    }
    else
    {
      InnerCount = (FLS_PAGE_SIZE / FLS_LOAD_PAGE_SIZE) ;
    }
    while(InnerCount != 0U)
    {
       /*  Load the data; */
       LoadPage(StartAddress, (*pdata));
       pdata++;
       InnerCount--;
     /*  Load Page register gets incremented automatically. */
    }   
          
    /* cycle 1 */
    CycleAA50(StartAddress, PageAddress);
    /* cycle 2 */
    CycleAA58(StartAddress, VALUE_00);
 
   #ifdef IFX_FLS_DEBUG02
   /* cycle 3 */
    CycleAAA8(StartAddress, VALUE_A1);
   #else
   /* cycle 3 */
    CycleAAA8(StartAddress, VALUE_A0);
   #endif   
    /* cycle 4 */
    if(WriteMode == BURST_WRITE)
    {
      CycleAAA8(StartAddress, VALUE_7A);
    }
    else
    {
      CycleAAA8(StartAddress, VALUE_AA);
    }
     
    InnerCount = 0U;

    while((FLASH0_FSR.B.PROG != 1U) && (InnerCount < FLS_CMDCYCLE_TIMEOUT))
    {
      InnerCount++;
    }
    
    if ((boolean)TRUE == Fls_lCmdCycleTimeout06(InnerCount))
    {
      StatePtr->FlsTimeoutErr = FLS_WRITE;
    }
  }  
}
#define FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN
#include "MemMap.h"


/*******************************************************************************
** Syntax : void Fls_EraseCmdCycles(volatile uint32 StartAddress)             **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StartAddress                                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine contains flash Erase command cycles             **
*******************************************************************************/
#define FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN
#include "MemMap.h"
void Fls_EraseCmdCycles(volatile uint32 StartAddress)
{ 
  uint32 InnerCount;
  Fls_17_Pmu_StateType* StatePtr;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  StatePtr->FlsTimeoutErr = 0U;
  /* cycle 1 */

  if( StartAddress == DFLASH_BANK0_PHYSICAL )
  {
    CycleAA50(StartAddress, (uint32)DFLASH_BANK0_PHYSICAL);
  }
  else
  {
    CycleAA50(StartAddress, (uint32)DFLASH_BANK1_PHYSICAL);
  }
  
  /* cycle 2 */
  CycleAA58(StartAddress, FLS_ERASE_SECTORS);
  /* cycle 3 */
  CycleAAA8(StartAddress, VALUE_80);

  #ifdef IFX_FLS_DEBUG01
  /* cycle 4 */
  CycleAAA8(StartAddress, VALUE_51);
  #else  
  /* cycle 4 */
  CycleAAA8(StartAddress, VALUE_50);
  #endif
  
  InnerCount = 0U;

  while((FLASH0_FSR.B.ERASE != 1U) && (InnerCount < FLS_CMDCYCLE_TIMEOUT))
  {
    InnerCount++;
  }
  
  /*return Error there is a Timeout has happened */
  if ((boolean)TRUE == Fls_lCmdCycleTimeout05(InnerCount))
  {
    StatePtr->FlsTimeoutErr = FLS_ERASE;
  }
}
#define FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN
#include "MemMap.h"


#define FLS_17_PMU_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Syntax : void Fls_CallEraseCommand(volatile uint32 PhysicalAddress)        **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : PhysicalAddress                                          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine calls flash Erase command cycles                **
*******************************************************************************/
void Fls_CallEraseCommand(volatile uint32 PhysicalAddress)
{
  (Fls_ConfigPtr->FlsAccessCodeErasePtr)(PhysicalAddress);
  
}

/*******************************************************************************
** Syntax : void Fls_CallWriteCommand(volatile uint32 PhysicalAddress, 
                          const Fls_17_Pmu_StateType *s_ptr,
                          uint8 WriteMode)                                    **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : PhysicalAddress, s_ptr, WriteMode                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine calls flash write command cycles                **
*******************************************************************************/
void Fls_CallWriteCommand(volatile uint32 PhysicalAddress, 
                          const Fls_17_Pmu_StateType *s_ptr,
                          uint8 WriteMode)
{
  (Fls_ConfigPtr->FlsAccessCodeWritePtr)(PhysicalAddress,
                s_ptr->FlsWriteAddress,
                (const Fls_AddressType*)(void *)s_ptr->FlsWriteBufferPtr,
                WriteMode);
}

/*******************************************************************************
** Syntax : void Fls_ResetReadCmdCycle(void)                                  **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine contains flash Reset command cycles             **
*******************************************************************************/
void Fls_ResetReadCmdCycle(void)
{ 
  Cycle5554(FLS_BASE_ADDRESS, VALUE_F0);
}

/*******************************************************************************
** Syntax : void Fls_ClearStatusCmdCycle(void)                                **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine contains flash clear status command cycles      **
*******************************************************************************/
void Fls_ClearStatusCmdCycle(void)
{ 
  Cycle5554(FLS_BASE_ADDRESS, VALUE_FA);

  #ifdef FLS_RAM_EMULATION_TEST
  #if (FLS_RAM_EMULATION_TEST == 1U)
  FlsEmulation_ClearStatusCmdCycle();
  #endif
  #endif
}

/*******************************************************************************
** Syntax : void Fls_ResumeEraseCmdCycle(uint32 StartAddress)                 **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StartAddress                                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine contains flash resume erase command cycles      **
*******************************************************************************/
void Fls_ResumeEraseCmdCycle(volatile uint32 StartAddress)
{ 
  /* cycle 1 */

  if( StartAddress == DFLASH_BANK0_PHYSICAL )
  {
    CycleAA50(StartAddress, DFLASH_BANK0_PHYSICAL);
  }
  else
  {
    CycleAA50(StartAddress, DFLASH_BANK1_PHYSICAL);
  }
  
  /* cycle 2 */
  CycleAA58(StartAddress, FLS_ERASE_SECTORS);
  /* cycle 3 */
  CycleAAA8(StartAddress, VALUE_70);
  /* cycle 4 */
  CycleAAA8(StartAddress, VALUE_CC);
  
}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
** Syntax: static _INLINE_ boolean Fls_lCmdCycleTimeout05(uint32 InnerCount)  **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : InnerCount - Delay count                                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : boolean                                                  **
**                                                                            **
** Description : This routine checks if command cycle timeout occured         **
*******************************************************************************/
static _INLINE_ boolean Fls_lCmdCycleTimeout05(uint32 InnerCount)
{
  boolean RetVal;
  
  #ifdef IFX_FLS_DEBUG05
  if ((InnerCount >= (uint32)FLS_CMDCYCLE_TIMEOUT) || (TestFls_DebugMask05))
  #else
  if (InnerCount >= (uint32)FLS_CMDCYCLE_TIMEOUT)
  #endif
  {
    RetVal = (boolean)TRUE; 
  }
  else
  {
    RetVal = (boolean)FALSE; 
  }
  return (RetVal);
}

/*******************************************************************************
** Syntax: static _INLINE_ boolean Fls_lCmdCycleTimeout06(uint32 InnerCount)  **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : InnerCount - Delay count                                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : boolean                                                  **
**                                                                            **
** Description : This routine checks if command cycle timeout occured         **
*******************************************************************************/
static _INLINE_ boolean Fls_lCmdCycleTimeout06(uint32 InnerCount)
{
  boolean RetVal;
  
  #ifdef IFX_FLS_DEBUG06
  if ((InnerCount >= FLS_CMDCYCLE_TIMEOUT) || (TestFls_DebugMask06))
  #else
  if (InnerCount >= FLS_CMDCYCLE_TIMEOUT)
  #endif
  {
    RetVal = (boolean)TRUE; 
  }
  else
  {
    RetVal = (boolean)FALSE; 
  }
  return (RetVal);
}

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

#define FLS_17_PMU_STOP_SEC_CODE
#include "MemMap.h"


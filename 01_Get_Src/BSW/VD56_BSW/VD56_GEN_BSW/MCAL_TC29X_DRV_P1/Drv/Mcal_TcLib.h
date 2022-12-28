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
**   $FILENAME   : Mcal_TcLib.h $                                             **
**                                                                            **
**   $CC VERSION : \main\15 $                                                 **
**                                                                            **
**   $DATE       : 2014-01-28 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This header file exports Mcal Tricore library              **
                   type definitions and functions                             **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                            **
*******************************************************************************/

#ifndef MCAL_TCLIB_H 
#define MCAL_TCLIB_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*
  File version information
*/
#define MCAL_SW_MAJOR_VERSION  (1)
#define MCAL_SW_MINOR_VERSION  (0)
#define MCAL_SW_PATCH_VERSION  (4)

#define TC27x  (1U)
#define TC26x  (2U)
#define TC29x  (3U)

#define AS40    (4U)
#define AS321   (321U)
#define AS402   (402U)
#define AS403   (403U)

#ifndef STD_ON
#define STD_ON     (1U)
#endif

#ifndef STD_OFF
#define STD_OFF    (0U)
#endif

#ifndef DISABLE_DEM_REPORT
#define DISABLE_DEM_REPORT    (0U)
#endif

#ifndef ENABLE_DEM_REPORT
#define ENABLE_DEM_REPORT    (1U)
#endif

/* Macro for Unused parameters*/
#define UNUSED_PARAMETER(VariableName)          if((VariableName) != 0U)\
                                                {/* Do Nothing */}
/* defines for Semaphore/s */
#define MCAL_RESOURCE_BUSY (1U)
#define MCAL_RESOURCE_FREE (0U)

#define MCAL_NO_OF_CORES   (3U) 



/*
The following type definitions are compiler specific.
These type definitions are used
for tasking intrinsic function
to be used in bit field structures.
This helps in avoding two MISRA complaints.
Rule 13 and Rule 111
*/

typedef signed int signed_int;

typedef unsigned int unsigned_int;


typedef enum
{
    MCAL_HALT,
    MCAL_RUN,
    MCAL_IDLE,
    MCAL_SLEEP,
    MCAL_STBY,
    MCAL_INVALID
} Mcal_CoreMode;



/*******************************************************************************
** Macro Syntax : Mcal_EnableAllInterrupts()                                  **
**                                                                            **
** Parameters (in) :  None                                                    **
** Parameters (out):  None                                                    **
**                                                                            **
** Description    : Call to Enable All Interrupts                             **
**                                                                            **
*******************************************************************************/
#define Mcal_EnableAllInterrupts()    ENABLE()

/*******************************************************************************
** Macro Syntax : Mcal_DisableAllInterrupts()                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
** Parameters (out):  None                                                    **
**                                                                            **
** Description    : Call to Disable All Interrupts                            **
**                                                                            **
*******************************************************************************/
#define Mcal_DisableAllInterrupts()    DISABLE()

/*******************************************************************************
** Macro Syntax : Mcal_SetAtomic(Address, Value, Offset, Bits)                **
**                                                                            **
** Parameters (in) :  Address: Address of the Variable to be Modified         **
**                    Value  : Value to be written                            **
**                    Offset : Bit Offset from LSB                            **
**                    Bits   : No of Bits Modified                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Description    : Mcal_SetAtomic is used to write atomic instructions in    **
**                  code.The function writes the number of bits of an integer **
**                  value at a certain address location in memory with a ...  **
**                  bitoffset. The number of bits must be a constant value... **
**                  Note that the Address must be Word Aligned                **
**                                                                            **
*******************************************************************************/
#define Mcal_SetAtomic(Address, Value, Offset, Bits) \
            IMASKLDMST((Address),(Value),(Offset),(Bits)) 

/*******************************************************************************
** Macro Syntax : Mcal_Extract(Address, Value, Offset, Bits)                  **
**                                                                            **
** Parameters (in) :  Address: Address of the Variable to be Modified         **
**                    Value  : Value to be written                            **
**                    Offset : Bit Offset from LSB                            **
**                    Bits   : No of Bits Modified                            **
** Parameters (out):  None                                                    **
** Return          : returns the extracted specifed value                     **
** Description    : EXTRACT is used to read value from a required position    **
**                  for the desired number of bits.                           **
**                  Reads the values in a single instruction when compared    **
**                  mask and loading the same                                 **
**                                                                            **
*******************************************************************************/
#define Mcal_Extract(Value,Pos,Width) \
            (EXTRACT((Value),(Pos),(Width))) 
                                       
/******************************************************************************/

/******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/


/*******************************************************************************
** Syntax : uint8 Mcal_GetCoreId(void)                                        **
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
extern uint8 Mcal_GetCoreId(void);

/*******************************************************************************
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
extern uint32 Mcal_GetDsprReMapAddress(uint32 Address);

/*******************************************************************************
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
extern void Mcal_StartCore (uint8 CpuNo, uint32 Pcval);
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
extern void Mcal_SetCpuPC (uint8 CpuNo, uint32 ProgramCounter);

/*******************************************************************************
** Syntax : uint32 Mcal_lLockResource(uint32 *ResourceStatusPtr)              **
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
extern uint32 Mcal_lLockResource(uint32 *ResourcePtr);
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
extern void  Mcal_lUnlockResource(uint32* ResourcePtr);

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
extern Std_ReturnType Mcal_GetSpinLock(uint32* SpinLckPtr,uint32 Timeout) ;

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
extern void Mcal_ReleaseSpinLock(uint32* SpinLckPtr) ;

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Mcal_SuspendAllInterrupts(void)                    **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Suspend all interrupts                                  **
**                                                                            **
*******************************************************************************/
extern void Mcal_SuspendAllInterrupts(void);

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Mcal_ResumeAllInterrupts(void)                     **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Resume all interrupts                                   **
**                                                                            **
*******************************************************************************/
extern void Mcal_ResumeAllInterrupts(void);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif /* MCAL_TCLIB_H  */

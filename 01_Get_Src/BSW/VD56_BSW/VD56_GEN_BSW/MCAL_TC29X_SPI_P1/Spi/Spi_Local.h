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
**  $FILENAME   : Spi_Local.h $                                              **
**                                                                           **
**  $CC VERSION : \main\17 $                                                 **
**                                                                           **
**  $DATE       : 2014-08-07 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains local functionality of Spi driver.      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef SPI_LOCAL_H
#define SPI_LOCAL_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Spi.h"

#if (SPI_SLAVE_ENABLE == STD_ON)
#include "SpiSlave.h"
#endif
/*******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
/* This macro to find the index for Job in the array Spi_JobResult. */
#define SPI_JOB_INDEX   ((uint8)4)
/*
  This macro represents the number of bits required to hold the staus of jobs
*/
#define SPI_JOB_STATUS_BITS  ((uint8)2U)
/*
  This macro extracts the status of the job from two bits
*/
#define SPI_JOB_STATUS_EXTRACT  (3U)

/*
  This macro represents the number of bits required to hold the staus of seq
*/
#define SPI_SEQUENCE_STATUS_BITS  (2U)
/*
This macro is used to find the position of the Job in the array Spi_JobResult
*/
#define SPI_JOB_BIT_POSITION  ((uint8)15)

#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_START_SEC_VAR_8BIT
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

/* Variable Stores the Number of IB Channels in the Configuration */
extern uint8 Spi_NoOfIBChannels;

#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_STOP_SEC_VAR_8BIT
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_START_SEC_ASIL0_VAR_32BIT
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

#if (SPI_SAFETY_ENABLE == STD_ON)
  /* Variable to Hold Job Result. */
  extern uint32 Spi_AsilJobResult[SPI_JOB_ASIL_ARRAY_INDEX];
#endif
/*(SPI_SAFETY_ENABLE == STD_ON) */

#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_STOP_SEC_ASIL0_VAR_32BIT
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_START_SEC_VAR_32BIT
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

/* Global QM Variables  */
/* Variable to Hold Job Result. */
#if (SPI_QM_MASTER_MODULES_USED != 0U)
extern uint32 Spi_QmJobResult[SPI_JOB_QM_ARRAY_INDEX];
#endif

#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_STOP_SEC_VAR_32BIT
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

/*******************************************************************************
**                              Function Declarations                         **
*******************************************************************************/
#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_START_SEC_CODE
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

extern Spi_JobResultType Spi_lGetJobStatus(Spi_JobType Job);

/* Function to Know if Module/job/sequence is of ASIL/QM kind */
#if (SPI_SAFETY_ENABLE == STD_ON)
/* AI00237167: Windriver compiler bug workaround. INLINE removed */
extern uint8 Spi_lGetModuleKind(uint8 Module);
extern Spi_SafetyJobType Spi_lGetJobKind (Spi_JobType JobId );
extern Spi_SafetySeqType Spi_lGetSequenceKind (Spi_SequenceType SequenceId );
#endif
/*(SPI_SAFETY_ENABLE == STD_ON)*/

#if (SPI_SLAVE_ENABLE == STD_ON)

/* The Slave Bus Handler should be called from Isr of
 DMA RX when received data count is equal to DmaReceiveCount */
extern void Spi_lSlaveBusHandler(uint32 Module);

/* The Slave Error Handler should be called from Isr of
 DMA RX when received data count is equal to
 DmaReceiveCount and error occured*/
extern void Spi_lSlaveErrorHandler(uint32 Module, uint32 DemError);


#if ( SPI_INITCHECK_API == STD_ON )
extern Std_ReturnType Spi_lSlaveInitCheck(const Spi_ConfigType* ConfigPtr);
#endif
/*******************************************************************************
** Syntax           :  Spi_JobResultType Spi_lSlaveGetJobStatus               **
** (                                                                          **
**   Spi_JobType Job                                                          **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Job - Job Id                                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Job result.                                             **
**                                                                            **
** Description      : Get the Job Result                                      **
**                                                                            **
** Traceability : [cover parentID=DS_AS403_SPI038]                 [/cover]   **
*******************************************************************************/
extern Spi_JobResultType Spi_lSlaveGetJobStatus(Spi_JobType Job);

/*******************************************************************************
** Traceability :                                                             **
** Syntax : void Spi_lSlaveInit(const Spi_ConfigType* ConfigPtr)              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to configuration set                **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :Initialization Service for SPI SLAVE .                        **
** The Initialization service initializes all SPI SLAVE relevant              **
** registers and global variables with the values of the structure            **
** referenced by the parameter ConfigPtr.                                     **
*******************************************************************************/
extern void Spi_lSlaveInit
(
  const Spi_ConfigType* ConfigPtr
);

/*******************************************************************************
** Syntax : Std_ReturnType Spi_lSlaveDeInit (void)                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  1                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: de-initialisation command has been accepted.       **
**                   E_NOT_OK: de-initialisation command has not been accepted**
**                                                                            **
** Description : Service For SPI SLAVE Deinitialization                       **
**                                                                            **
*******************************************************************************/
extern void Spi_lSlaveDeInit(void);
#endif



#if ((SPI_LEVEL_DELIVERED == 1U)||(SPI_LEVEL_DELIVERED == 2U)) 
#if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
/*******************************************************************************
** Syntax : static void Spi_lIntSeqAsyncTransmit(Spi_SequenceType Sequence)   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Sequence : Sequence number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This function will populate the Queue depending upon the     **
**               priority of jobs. updating the jobs also depends on the      **
**               previously loaded sequences are interruptible or not.        **
**                                                                            **
*******************************************************************************/
extern void Spi_lIntSeqAsyncTransmit
(
Spi_SequenceType Sequence,
Spi_JobAndSeqAccessType   *JobSeqDataPtr
);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) \
                                 || (SPI_SLAVE_ENABLE == STD_ON)) 
/*******************************************************************************
** Syntax : static Std_ReturnType Spi_lIsQueueAvailable                       **
** (                                                                          **
**    uint16 Jobs,                                                            **
**    Spi_JobAndSeqAccessType *JobSeqDataPtr                                  **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant (for different channel Ids)                        **
**                                                                            **
** Parameters (in) :   uint16 Jobs                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
**                                                                            **
** Description :  This will increment the queue index and wrap around when    **
**                Queue length reached(if the jobs already in the Q finished  **
*******************************************************************************/
extern Std_ReturnType Spi_lIsQueueAvailable
(
  uint16 Jobs,
  const Spi_JobAndSeqAccessType *JobSeqDataPtr
);

/*******************************************************************************
** Syntax : _IFXEXTERN_ INLINE uint16 Spi_lIncrementAndRoundIndex           **
** (                                                                          **
**   uint16 SatIndex                                                          **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant (for different channel Ids)                        **
**                                                                            **
** Parameters (in) :   uint16 SatIndex                                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
**                                                                            **
** Description :  This will increment the queue index and wrap around when    **
**                Queue length reached(if the jobs already in the Queue       **
                  finished).                                                  **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint16 Spi_lIncrementAndRoundIndex(uint16 SatIndex)
{
  SatIndex++;
  if (SatIndex == (SPI_MAX_JOB_TRIG_Q_LENGTH))
  {
    SatIndex = 0U;
  }
  return SatIndex;
}
/*******************************************************************************
** Syntax : extern  void Spi_lHwDisableQspiErrIntr                            **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Module - Hw module no.                                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
** Description :  Function to Disable Spi Hw error    Interrupt               **
*******************************************************************************/
extern void  Spi_lHwDisableQspiErrIntr(uint32 Module);

#endif
/* ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) \
                                 || (SPI_SLAVE_ENABLE == STD_ON))  */
/*******************************************************************************
**                              Variable Declarations                         **
*******************************************************************************/
#if (SPI_SLAVE_ENABLE == STD_ON)

extern Spi_SlaveChnlAccessType Spi_SlaveChnlAccess[SPI_NUM_ASIL_SLAVE_MODULES];


#endif

#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_STOP_SEC_CODE
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

#endif /* End of SPI_LOCAL_H */

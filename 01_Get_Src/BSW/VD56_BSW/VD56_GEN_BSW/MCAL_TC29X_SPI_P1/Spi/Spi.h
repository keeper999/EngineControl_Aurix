/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Spi.h $                                                    **
**                                                                            **
**   $CC VERSION : \main\65 $                                                 **
**                                                                            **
**   $DATE       : 2014-08-20 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - functionality of SPI Handler driver.                     **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**  TRACEABILITY : [cover parentID= DS_NAS_SPI_PR746,SAS_NAS_ALL_PR748] 
                                                                        [/cover]
*******************************************************************************/

#ifndef SPI_H
#define SPI_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h  */
#include "Std_Types.h"

#include "Mcal.h"
#include "Mcal_DmaLib.h"

/* Pre-compile/static configuration parameters for SPI  */
#include "Spi_Cfg.h"

/* Conditional Inclusion of Developement Error Tracer File */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define SPI_INSTANCE_ID       ((uint8)0U)

#define SPI_VENDOR_ID         (17U)
#define SPI_MODULE_ID         (83U)

/*
   The Macro SPI_PB_FIXEDADDR is selected to STD_OFF, if fixed address feature
   not selected
*/
#ifndef SPI_PB_FIXEDADDR
#define SPI_PB_FIXEDADDR    (STD_OFF)
#endif

/*
  The Macro SPI_DMA_ADDRESS_ACCESS is selected to STD_ON, only for Tricore V1.6
*/
#ifndef SPI_DMA_ADDRESS_ACCESS
#define SPI_DMA_ADDRESS_ACCESS   (STD_ON)
#endif

#if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
/*
Development error and Safety error values
*/
/*API Service called with wrong parameter.Config is a null pointer */
#define SPI_E_PARAM_CONFIG  ((uint8)0x0F)

/*API Service called with wrong parameter.*/
#define SPI_E_PARAM_CHANNEL ((uint8)0x0A)

/*API Service called with wrong parameter.*/
#define SPI_E_PARAM_JOB     ((uint8)0x0B)

/*API Service called with wrong parameter.*/
#define SPI_E_PARAM_SEQ     ((uint8)0x0C)

/*API Service called with wrong parameter.*/
#define SPI_E_PARAM_LENGTH  ((uint8)0x0D)

/*API Service called with wrong parameter.*/
#define SPI_E_PARAM_UNIT    ((uint8)0x0E)

/*API Service called with NULL parameter.*/
#define SPI_E_PARAM_POINTER ((uint8)0x10)

/*API Service used without initialization */
#define SPI_E_UNINIT        ((uint8)0x1A)

/*Services called in wrong sequence.*/
#define SPI_E_SEQ_PENDING   ((uint8)0x2A)

/*Synchronous transmission service called at wrong parameter.*/
#define SPI_E_SEQ_IN_PROCESS  ((uint8)0x3A)

/* Non availability of enough space in the Queue when a new sequence arrives */
#define SPI_E_QUEUE_FULL      ((uint8)0x5A)

#define SPI_E_ALREADY_INITIALIZED  ((uint8)0x4A)

/*Buffer Pointers not aligned for DMA usage*/
#define SPI_E_DMA_ADR_ALIGN_ERROR ((uint8)0x51)

#if (SPI_SAFETY_ENABLE == STD_ON)
/*Services called in source pointer without channel marker.*/
#define SPI_E_PARAM_SRC_POINTER   ((uint8)0xB1)

/*Services called in dest pointer without channel marker.*/
#define SPI_E_PARAM_DEST_POINTER  ((uint8)0xB2)

/*Services called in wrong mode. */
#define SPI_E_PARAM_MODE          ((uint8)0xB3)

/*ISR Services called in wrong QSPI module. */
#define SPI_E_PARAM_MODULE        ((uint8)0xB4)
#endif
/* (SPI_SAFETY_ENABLE == STD_ON) */


/* API Service ID's */
/* API Service ID for Spi_Init() */
#define SPI_SID_INIT                  ((uint8)0x00)
/* API Service ID for Spi_DeInit() */
#define SPI_SID_DEINIT                ((uint8)0x01)
/* API Service ID for Spi_WriteIB() */
#define SPI_SID_WRITEIB               ((uint8)0x02)
/* API Service ID for Spi_AsyncTransmit() */
#define SPI_SID_ASYNCTRANSMIT         ((uint8)0x03)
/* API Service ID for Spi_ReadIB() */
#define SPI_SID_READIB                ((uint8)0x04)
/* API Service ID for Spi_SetupEB() */
#define SPI_SID_SETUPEB               ((uint8)0x05)
/* API Service ID for Spi_GetStatus() */
#define SPI_SID_GETSTATUS             ((uint8)0x06)
/* API Service ID for Spi_GetJobResult() */
#define SPI_SID_GETJOBRESULT          ((uint8)0x07)
/* API Service ID for Spi_GetSequenceResult() */
#define SPI_SID_GETSEQUENCERESULT     ((uint8)0x08)
/* API Service ID for Spi_GetVersionInfo() */
#define SPI_SID_GETVERSIONINFO        ((uint8)0x09)
/* API Service ID for Spi_SyncTransmit() */
#define SPI_SID_SYNCTRANSMIT          ((uint8)0x0A)
/* API Service ID for Spi_GetHWUnitStatus() */
#define SPI_SID_GETHWUNIITSTATUS      ((uint8)0x0B)
/* API Service ID for Spi_Cancel() */
#define SPI_SID_CANCEL                ((uint8)0x0C)
/* API Service ID for Spi_SetAyncMode() */
#define SPI_SID_SETAYNCMODE           ((uint8)0x0D)
/* API Service ID for Spi_MainFunction_Handling() */
#define SPI_SID_MAINFUNCTION          ((uint8)0x10)
/* API Service ID for all interrupt handlers */
#define SPI_SID_ISRHANDLERS           ((uint8)0x31)

#endif
/*( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) ) */

/* Options of Spi_AsyncModeType */
/*The asynchronous mechanism is ensured by polling*/
#define  SPI_ASYNC_MODE_POLLING    (0U)

/*The asynchronous mechanism is ensured by interrupt*/
#define  SPI_ASYNC_MODE_INTERRUPT   (1U)

/* Type of QSPI Master */
#if (SPI_SAFETY_ENABLE == STD_ON)
#define  SPI_QM_MASTER      (0U)
#define  SPI_ASIL_MASTER    (1U)
#endif

/* Bitmap of all the QM master modules configured */
#if (SPI_SAFETY_ENABLE == STD_ON)
#define SPI_QM_MASTER_MODULES_USED ( SPI_ASIL_MASTER_MODULE_USED ^ \
                                     SPI_MASTER_MODULES_USED )
#else
#define SPI_QM_MASTER_MODULES_USED ( SPI_MASTER_MODULES_USED )
#endif

/* Job Priority 0 */
#define SPI_JOB_PRIORITY_0 ((uint8)0)
/* Job Priority 1 */
#define SPI_JOB_PRIORITY_1 ((uint8)1)
/* Job Priority 2 */
#define SPI_JOB_PRIORITY_2 ((uint8)2)
/* Job Priority 3 */
#define SPI_JOB_PRIORITY_3 ((uint8)3)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* [cover parentID=DS_AS_SPI061_SPI161_SPI163_SPI283_SPI_PR4525,
DS_AS_SPI011, DS_NAS_SPI_PR643_1,DS_AS403_SPI364_SPI365]
*/
/*
Type : Spi_StatusType
This type defines a range of specific status for SPI Handler/Driver.
It informs about the SPI Handler/Driver status and can be obtained
calling the API service Spi_GetStatus.
*/
typedef enum
{
  SPI_UNINIT, /* The SPI Driver is not initialized or not usable.*/
  SPI_IDLE, /*The SPI Driver is not currently transmitting any Jobs. */
  SPI_BUSY /* The SPI Driver is performing a SPI Job (transmit).*/
}Spi_StatusType;
/* [/cover] */

/* [cover parentID=DS_AS_SPI062,DS_AS4XX_SPI_PR8384, DS_NAS_SPI_PR643_2]*/
/*
Type : Spi_JobResultType
This type defines a range of specific Jobs status for SPI
Handler/Driver.It informs about a SPI Handler/Driver Job status and can be
obtained calling the API service Spi_GetJobResult with the Job ID.
*/
typedef enum
{
  SPI_JOB_OK, /*The last transmission of the Job is successful.*/
  SPI_JOB_PENDING, /*The SPI Driver is performing a SPI Job transfer.*/
  SPI_JOB_FAILED, /*The last transmission of the Job has failed.*/
  SPI_JOB_QUEUED
}Spi_JobResultType;
/* [/cover] */

/* [cover parentID=DS_AS_SPI019_SPI251_SPI_PR4523,DS_NAS_SPI_PR643_3] */
/*
Type : Spi_SeqResultType
This type defines a range of specific Sequences status for SPI
Handler/Driver.It informs about a SPI Handler/Driver Sequence status and can be
obtained calling the API service Spi_GetSequenceResult with the Sequence ID.
*/
typedef enum
{
  SPI_SEQ_OK, /*The last transmission of the Sequence is successful.*/
  SPI_SEQ_PENDING, /*The SPI Driver is performing a SEQ transfer.*/
  SPI_SEQ_FAILED, /*The last transmission of the Sequence has failed.*/
  SPI_SEQ_CANCELED /*The last transmission of the Seq is cancelled by user */
}Spi_SeqResultType;
/* [/cover] */

/* [cover parentID=DS_AS_SPI149_SPI289_SPI290_SPI_PR4518_SPI164_SPI355] */
/*
Type : Spi_DataType
Type of application data buffer elements.
In order to always get the same user interface, the SPI Handler/Driver
shall handle these differences using the following proposed rules:
• Spi_DataType 8/16/32 bits, data width 8/16/32 bits. Straightforward send and
receive.
• Spi_DataType superior to data width. Send the lower part, ignore the upper
part. Receive the lower part, extend with zero.
• Spi_DataType inferior to data width. According to the memory alignement use
prior both rules.
*/
typedef uint8 Spi_DataType;
/* [/cover] */

/* [cover parentID=DS_AS_SPI165_SPI_PR4522] */
/*
Type : Spi_NumberOfDataType
Type for defining the number of data elements of the type Spi_DataType to
send and / or receive by Channel
*/
typedef uint16 Spi_NumberOfDataType;
/* [/cover] */

/* [cover parentID=DS_AS_SPI166_SPI356_SPI_PR4517] */
/*
Type : Spi_ChannelType
Specifies the identification (ID) for a Channel.
*/
typedef uint8 Spi_ChannelType;
/* [/cover] */

/* [cover parentID=DS_AS_SPI167_SPI357_SPI_PR4521] */
/*
Type : Spi_JobType
Specifies the identification (ID) for a Job.
*/
typedef uint16 Spi_JobType;
/* [/cover] */

/* [cover parentID=DS_AS_SPI168_SPI358_SPI_PR4524] */
/*
Type : Spi_SequenceType
Specifies the identification (ID) for a Sequence.
*/
typedef uint8 Spi_SequenceType;
/* [/cover] */

/* [cover parentID=DS_AS_SPI150_SPI170_SPI360_SPI_PR4515,
DS_NAS_SPI_PR643_4] */
/*
Type : Spi_AsyncModeType
Specifies the Asynchronous mechanism mode for Spi Handler/Driver
i.e Polling Mode and Interrupt Mode.
This type is available or not accordind to the pre compile
time parameter:SPI_LEVEL_DELIVERED. This is only relevant for LEVEL 2.
*/
#if (SPI_LEVEL_DELIVERED == 2U)
typedef enum
{
  SPI_POLLING_MODE = 0U,
  SPI_INTERRUPT_MODE = 1U
}Spi_AsyncModeType;
#endif /* SPI_LEVEL_DELIVERED == 2U */
/* [/cover] */

/*
Type : Spi_SafetySeqType
Denotes if the sequence is of QM or ASIL type.
*/
typedef enum
{
  SPI_QM_SEQUENCE,   /* Sequence is associated with QM master               */
  SPI_ASIL_SEQUENCE, /* Sequence is associated with ASIL master             */
}Spi_SafetySeqType;

/*
Type : Spi_SafetySeqType
Denotes if the job is of QM or ASIL type.
*/
typedef enum
{
  SPI_QM_JOB,   /* Job is associated with QM master               */
  SPI_ASIL_JOB, /* Job is associated with ASIL master             */
}Spi_SafetyJobType;

/*
Type: Spi_NotifFunctionPtrType
To provide Job and Sequence Notification the following type will be used.
*/
typedef void(*Spi_NotifFunctionPtrType)(void);

/* [cover parentID=DS_AS_SPI063] */
/*
Type: Spi_ChannelConfigType
The contents of the SPI Channel Configuration Parameters.
A constant variable to this structure is defined in Spi_PBCfg.c based on
user configuration.
*/
typedef struct Spi_ChannelConfig
{
  /*Symbolic Identification of Channel: Identified by Array Index*/
  /* Default data : The data Type is independent of Spi_DataType
   to support 32bit data.*/
  uint32  DefaultData;

  /*Packed variable for:
   Data Width : 2 to 32,
   Data Transfer Start Control : LSB/MSB First */
  uint16   DataConfig;

  /* Number of IB Buffers for an IB Channel
   Or Max EB Buffer Size for an EB Channel */
  Spi_NumberOfDataType NoOfBuffers;

  /*Type Of Channel: EB/IB . This variable is needed only if both Channel
    Buffer Types are configurable*/
  uint8   ChannelBufferType;

  #if (SPI_SAFETY_ENABLE == STD_ON)
  /* Safety Buffer Marker */
  uint8   ChnlBufferMarker;
  #endif

} Spi_ChannelConfigType;
/* [/cover] */

/*
Type: Spi_DelayConfigType
Configuration Structure for CS Delay and and Timer Type used.
This type is referenced in Spi_JobConfigType.
*/
  /* Packed variable for Delay Time Configuration params
   bit 0 : Reserved
   bit 1-3: IPRE
   bit 4-6: IDLE
   bit 7-9: LPRE
   bit 10-12: LEAD
   bit 13-15: TPRE
   bit 16-18: TRAIL
   bit 19-31: Reserved
  */
typedef uint32 Spi_DelayConfigType;

/* [cover parentID=DS_AS_SPI169_SPI359_SPI_PR4519]
*/
/*
Type: Spi_HWUnitType
Configuration Structure for HwModule and Hw Channel no.
*/
typedef uint8 Spi_HWUnitType;
/* [/cover] */

/* [cover parentID=DS_AS_SPI009, DS_AS_SPI192_SPI044_1_SPI048_1,
DS_AS_SPI010_SPI294]
*/
/*
Type: Spi_JobConfigType
The contents of the SPI Job Configuration Parameters
Mapping to different SPI HW Units and Devices.
A constant variable to this structure is defined in Spi_Cfg.c based on
user configuration.
*/
typedef struct Spi_JobConfig
{
  /* Symbolic Identification of Job: Identified by Array Index*/

  #if ( (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) )
  /*  Job notification callback */
  Spi_NotifFunctionPtrType JobEndNotification;
  #endif /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

  /* Pointer to a list of linked channels */
  const Spi_ChannelType *ChannelLinkPtr;

  /* Packed variable for Baud Rate Configuration Parameters TQ, Q, A, B, C
    bit 0-7: TQ
    bit 8-13 : Q
    bit 16-17 : A
    bit 18-19 : B
    bit 20-21 : C
  */
  uint32 BaudRateConfig;

  /* Packed variable for Delay Time Configuration params
   bit 0 : Reserved
   bit 1-3: IPRE
   bit 4-6: IDLE
   bit 7-9: LPRE
   bit 10-12: LEAD
   bit 13-15: TPRE
   bit 16-18: TRAIL
   bit 19-31: Reserved
  */
  Spi_DelayConfigType  TimeDelayConfig;

  /* CS Configuration : CS Pin Selection.*/
  uint16 CSPin;

  /* Chip select polarity : Active Level Polarity */
  uint8 CSPolarity;

  /* Packed Variable For:
  Clock polarity(Shift Clock Polarity,
  Clock Phase (Data Shift Edge) */
  uint8  ShiftClkConfig;

  /* Job priority */
  uint8  JobPriority;

  /* Assigned SPI peripheral  */
  Spi_HWUnitType  HwUnit;

  /*Channel based Chip Select */
  uint8   ChannelBasedChipSelect;

}Spi_JobConfigType;
/* [/cover] */


/* [cover parentID=DS_AS_SPI064, DS_AS_SPI044_2_SPI048_2_SPI193]
*/
/*
Type: Spi_SequenceConfigType
The contents of the SPI Sequence Configuration Parameters.
A constant variable to this structure is defined in Spi_Cfg.c based on
user configuration.
*/
typedef struct Spi_SequenceConfig
{
  /* Symbolic Identification of Sequence: Identified by Array Index*/

  /* Sequence Interruptible/Not Interruptible */
  /* A Non Interruptible Sequence must contain jobs belonging to the same */
  /* HW Unit */
  #if ( (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) )
  /* :Sequence notification callback */
  Spi_NotifFunctionPtrType SeqEndNotification;
  #endif /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

  /* Pointer to a list of linked jobs */
  const uint16 *JobLinkPtr;
  #if ( (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U)|| \
               (SPI_SLAVE_ENABLE == STD_ON) )
  /* List of Sequences that share job with this sequence including the
     current Sequence*/
  /* Pointer to List of Sequences that share job with this sequence including
     the  current Sequence */
  const uint8 *SeqSharingJobs;
  #endif
  /* This holds the total number of jobs linked to this sequence */
  uint16 JobsInParamSeq;
  #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
  uint8 InterruptibleSequence;
  #endif /* (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON) */

#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
  /* Holds the Hw modules used by the sequence. Applicable for Level Delivered
  0 and 2 In Level delivered 2, it's applicable for Sync sequences only. */
  uint8 HwModuleUsed;
#endif
}Spi_SequenceConfigType;
/* [/cover] */

/*
Type: Spi_DmaConfigType
Dma Configuration
*/
typedef struct Spi_DmaConfigType
{
  Dma_ChannelType TxDmaChannel;
  Dma_ChannelType RxDmaChannel;
}Spi_DmaConfigType;


/*
Type: Spi_ModuleConfigType
SPI HW Peripheral Configuration
*/
typedef struct Spi_HWModuleConfig
{
  /* SPI HW Module Clock Setting */
  const uint32  HWClkSetting; /* CLC Reg Setting */

  /* SPI HW Module MISO,MOSI,SCLK Pin Selection Setting (PISEL Regsiter) */
  const uint32 HWPinSetting;


  const Spi_DmaConfigType *SpiDmaConfigPtr;


}Spi_HWModuleConfigType;

#if (SPI_SAFETY_ENABLE == STD_ON)
typedef struct Spi_MapConfigType
{
  /* ASIL jobs and QM jobs are separately indexed and the index values
    are stored in the array.
    Eg: Consider ASIL Jobs (J0,J3,J5,J6,J7) and QM jobs(J1,J2,J4)
    Then the generated index would be as following:
    JobIndex[] = {0,0,1,1,2,2,3,4} */
  Spi_JobType       JobIndex[SPI_MAXIMUM_JOB];

  /* ASIL sequences and QM sequences are separately indexed and the index
    values are stored in the array.
    Eg: Consider ASIL sequences (S0,S3,S5,S6,S7) and QM sequences(S1,S2,S4)
    Then the generated index would be as following:
    SeqIndex[] = {0,0,1,1,2,2,3,4} */
  Spi_SequenceType  SeqIndex[SPI_MAXIMUM_SEQUENCE];
}Spi_MapConfigType;
#endif

/* [cover parentID=DS_AS_SPI244]
Configuration of PLL clock shall be handled within MCU module.
[/cover] */

/* [cover parentID=DS_AS_SPI008_SPI344_SPI_PR4516]
*/
/*
Type: Spi_ConfigType
Run Time Configuration Parameters.
Contains MCU dependant properties, definition of Channels, Jobs and
        sequences
*/
typedef struct Spi_ConfigType
{
  /* Safety Marker */
  #if (SPI_SAFETY_ENABLE == STD_ON)
  uint32 SafetyMarker;
  #endif

  /* Ptr to SPI Channel Config */
  const Spi_ChannelConfigType*  SpiChannelConfigPtr;

  /* Ptr to SPI Job Config */
  const Spi_JobConfigType*      SpiJobConfigPtr;

  /* Ptr to SPI Sequence Config */
  const Spi_SequenceConfigType* SpiSequenceConfigPtr;

  /* Ptrs to SPIx (QSPIx) Module (HW Peripheral) Configuration */
  const Spi_HWModuleConfigType* HWModuleConfigPtr[SPI_MAX_HW_UNIT];

  /* Variable index for ASIL or QM variables */
  #if (SPI_SAFETY_ENABLE == STD_ON)
  const Spi_MapConfigType* SpiMapConfigPtr;
  #endif

  /* No of Channels Configured */
  Spi_ChannelType         NoOfChannels;

  /* No of Jobs Configured */
  Spi_JobType             NoOfJobs;

  /* No of Sequences Configured */
  Spi_SequenceType        NoOfSequences;

  #if ( SPI_LEVEL_DELIVERED == 2U)
  /* No Of Sync Sequences configured in Level 2 */
  Spi_SequenceType NoOfSyncSequences;
  #endif
} Spi_ConfigType;
/* [/cover] */

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))

typedef struct Spi_LastChannelDataType
{
  uint32 *LastDataPtr;
  uint16 DataWidth;
}Spi_LastChannelDataType;

#endif
/*((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))*/

/*
Type: Spi_JobAndSeqAccessType
This structure contains the variables containing information regarding the
Jobs and sequences.
*/

typedef struct Spi_JobAndSeqAccessType
{
  Spi_JobType StartIndexExtractJobId;

  Spi_JobType EndIndex;

  /*
  This variable holds the job id's of all the sequences. The Job's are fetched
  from this Queue and next SPI transmission started.
  */
  Spi_JobType JobQueue[SPI_MAX_JOB_TRIG_Q_LENGTH];

  #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
    /* Current Job Index on each of the Sequence is stored here */
    Spi_JobType CurrentJobIndex[SPI_MAXIMUM_SEQUENCE];

    Spi_JobType JobQueueRearrange[SPI_MAX_JOB_TRIG_Q_LENGTH];

    Spi_SequenceType JobLinkedSequenceRearrange[SPI_MAX_JOB_TRIG_Q_LENGTH];

  #else
   /* If interruptible sequences are not allowed the configuration limits
   all the jobs of a sequence to belong to the same Spi bus. So the variable
   to know the Current running job on the sequence is needed only for each bus
   and not based on each sequence as above */

   Spi_JobType CurrentJobIndex;

  #endif
  /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)*/

  /* This variable holds the sequence id of the job that is currently been used
  for transmission. */
  Spi_SequenceType JobLinkedSeq[SPI_MAX_JOB_TRIG_Q_LENGTH];

}Spi_JobAndSeqAccessType;



/*
Type: Spi_JobAndSeqAccessType
This structure gives info about the channel data and  DMA channel
associated with QSPI module.
*/
typedef struct Spi_ChnlAccessType
{
  #if (SPI_LEVEL_DELIVERED != 0U)

    Spi_DmaConfigType DmaChannelIdx;

    Spi_LastChannelDataType LastChannelData;

  /* Dummy Transmit Address if source pointer of the EB channel is NULL */
  #if ((SPI_CHANNEL_BUFFERS_ALLOWED == 1U) ||\
                                            (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
    uint32 DMATXDummy;
  #endif
  #endif
  /*(SPI_LEVEL_DELIVERED != 0U)*/

  /* Variable to save / restore Gpio CS pin */
  uint16 GpioPortPin;

  #if (SPI_LEVEL_DELIVERED != 0U)
    /* Current Channel Index on the Async Bus */
    uint8  CurrentChannelIndex;
  #endif
  /*(SPI_LEVEL_DELIVERED != 0U)*/
}Spi_ChnlAccessType;

/*
Type: Spi_AsilSeqStatusType
This structure gives info about ASIL sequence status.
*/
#if (SPI_SAFETY_ENABLE == STD_ON)
typedef struct Spi_AsilSeqStatusType
{

  uint32 AsilSeqStatus;

  /* Variable to hold the sequences that are Cancelled*/
  #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
  uint32 AsilSeqCancelStatus;
  #endif

}Spi_AsilSeqStatusType;
#endif


/*
Type: Spi_AsilSeqStatusType
This structure gives info about QM sequence status.
*/
typedef struct Spi_QmSeqStatusType
{

  uint32 QmSeqStatus;

  /* Variable to hold the sequences that are Cancelled*/
  #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
  uint32 QmSeqCancelStatus;
  #endif

}Spi_QmSeqStatusType;

/*
Type: Spi_IBBufferAccessType
This structure gives info Internal buffer parameters and channels write lock.
*/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
typedef struct Spi_IBBufferAccessType
{

/* The IB Buffer Provided by Software. The Size of the buffer is determined
based on the buffer size of the IB Buffer Channels configured by the user.
The size is multiplied by 2 so that the buffer is sufficient for transmitted and
received data.
For the IB Channels the Handler/Driver shall provide the buffering,
but it is not able to take care of the consistency of the data in the buffer
during transmission.The size of the Channel buffer is fixed.*/
  Spi_DataType IBBuffer[2U * SPI_MAXIMUM_IB_BUFFER_SIZE];


  /* The Channel poistion Offset w.r.to the IB Buffer Space is Stored */
  /* [cover parentID=DS_AS_SPI049_SPI051] */
  uint16 IBBufferOffset[SPI_MAXIMUM_IB_CHANNELS];
  /* [/cover] */

/* Variable to Lock a Channel before IB Write. This makes the function
   Spi_WriteIB re-entrant even when called with the same channel. Note the
   mechanism of thread safety is used*/
  uint8 ChannelWriteLock[SPI_WRITELOCK_INDEX];

}Spi_IBBufferAccessType;
#endif


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define SPI_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* Declaration of Spi Post Build Configuration */
extern const Spi_ConfigType Spi_ConfigRoot[SPI_CONFIG_COUNT];
#define SPI_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_START_SEC_VAR_32BIT
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

#if (SPI_PB_FIXEDADDR == STD_OFF)
/* Variable Holds the Configuration Pointer given in Spi_Init */
extern const Spi_ConfigType* Spi_kConfigPtr;
#endif /*(SPI_PB_FIXEDADDR == STD_OFF)*/

#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_STOP_SEC_VAR_32BIT
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_START_SEC_CONST_32BIT
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

#if (SPI_PB_FIXEDADDR == STD_ON)
/* Variable Holds the Configuration Pointer given in Spi_Init */
extern const Spi_ConfigType* const Spi_kConfigPtr;
#endif /*(SPI_PB_FIXEDADDR == STD_ON)*/

#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_STOP_SEC_CONST_32BIT
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

/* variable for debugging purpose only  */
#if (IFX_SPI_DEBUG_TX == STD_ON)||(IFX_SPI_DEBUG_ERR == STD_ON)
extern uint32 Spi_IfxDebugStatus;
#endif
/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*Memory Map of the SPI Code*/
#define SPI_START_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#include "MemMap.h"
/*******************************************************************************
Syntax : void Spi_Init(const Spi_ConfigType* ConfigPtr)                       **
**                                                                            **
** Service ID:  0x00                                                          **
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
** Description : Driver Module Initialization function                        **
** Service for SPI initialization. The Initialization function shall          **
** initialize all SPI relevant registers with the values of the structure     **
** referenced by the parameter ConfigPtr.                                     **
** For Level2 this Function shall set the Handler/Driver Asynchronous         **
** Mechanism Mode in POLLING MODE and all the interrupts may be disabled      **
*******************************************************************************/
extern void Spi_Init(const Spi_ConfigType* ConfigPtr);

/*******************************************************************************
Syntax : Std_ReturnType Spi_InitCheck(const Spi_ConfigType* ConfigPtr)        **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to configuration set                **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Std_ReturnType                                          **
**                                                                            **
** Description      : This function checks is the initialization of the       **
**                    SPI hardware unit and driver done according to the      **
**                    configuration set referenced by ConfigPtr.              **
*******************************************************************************/
extern Std_ReturnType Spi_InitCheck(const Spi_ConfigType* ConfigPtr);

/*******************************************************************************
** Syntax : Std_ReturnType Spi_DeInit (void)                                  **
**                                                                            **
** Service ID:  0x01                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: de-initialization command has been accepted.       **
**                   E_NOT_OK: de-initialization command has not been accepted**
**                                                                            **
** Description : Service For SPI Deinitialization                             **
*******************************************************************************/
extern Std_ReturnType Spi_DeInit(void);

/*******************************************************************************
** Syntax : Std_ReturnType Spi_WriteIB                                        **
** (                                                                          **
**   Spi_ChannelType Channel,                                                 **
**   const Spi_DataType* DataBufferPtr                                        **
** )                                                                          **
**                                                                            **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Channel - Channel ID.                                    **
**                   DataBufferPtr - Pointer to source data buffer            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Write command has been accepted.                  **
**                   E_NOT_OK - Write command has not been accepted.          **
**                                                                            **
** Description : Service for writing one or more data to an IB                **
** SPI Handler/Driver Channel specified by parameter.                         **
** In case of 16bit Channel Data Width the DataBufferPtr must be 16bit aligned**
** This function is pre compile time configurable by the parameter:           **
** SPI_CHANNEL_BUFFERS_ALLOWED.This service is only relevant for Channels with**
** IB.                                                                        **
** Different Jobs, consequently also Sequences, can have in common            **
** Channels. But, the use of those shared Channels is restricted. Read and    **
** Write functions can not guarantee the data integrity while Channel data is **
** being transmitted. User must ensure that Read and/or Write functions are   **
** not called during transmission.                                            **
*******************************************************************************/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0U)||(SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
extern Std_ReturnType Spi_WriteIB
(
  Spi_ChannelType Channel,
  const Spi_DataType *DataBufferPtr
);
#else
#define Spi_WriteIB(Channel,  DataBufferPtr) \
                                      (ERROR_Spi_WriteIB_NOT_SELECTED)
#endif /*SPI_CHANNEL_BUFFERS_ALLOWED == 0||SPI_CHANNEL_BUFFERS_ALLOWED == 2U*/

/*******************************************************************************
** Syntax : Std_ReturnType Spi_AsyncTransmit                                  **
** (                                                                          **
**   Spi_SequenceType Sequence                                                **
** )                                                                          **
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Sequence - Sequnece ID.                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Transmission command has been accepted.           **
**                   E_NOT_OK - Transmission command has been accepted.       **
**                                                                            **
** Description : AsyncService to transmit data on the SPI bus.                **
** This service shall take over the given parameter, initiate a transmission, **
** and set the SPI Handler/Driver status to SPI_BUSY, set the sequence result **
** to SPI_SEQ_PENDING, set the first job result to SPI_JOB_PENDING and return.**
** This function is pre compile time selectable by the configuration          **
** parameter:SPI_LEVEL_DELIVERED. This function is only relevant for          **
** LEVEL 1 and LEVEL 2.                                                       **
** The function allows transmitting more than one Sequence at the             **
** same time. That means during a Sequence on-going transmission, all requests**
** to transmit another Sequence shall be evaluated, using the                 **
** lead Job, for an acceptance if different SPI buses or for set to           **
** pending state for transmission later.                                      **
** This method shall be called after a Spi_SetupEB method for EB Channels or  **
** Spi_WriteIB method for IB Channels but before the Spi_ReadIB method.       **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
extern Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence);
#else
#define Spi_AsyncTransmit(Sequence) \
                                      (ERROR_Spi_AsyncTransmit_NOT_SELECTED)
#endif /* SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U */

/*******************************************************************************
Syntax : Std_ReturnType Spi_ReadIB(                                           **
**                                    Spi_ChannelType Channel,                **
**                                    Spi_DataType *DataBufferPtr             **
**                                 )                                          **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Channel - Channel ID.                                    **
**                   DataBufferPtr - Pointer to destination data buffer in RAM**
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Read command has been accepted.                   **
**                   E_NOT_OK - Read command has not been accepted.           **
**                                                                            **
** Description : Service for reading synchronously one or more                **
** data from an IB SPI Handler/Driver Channel specified by parameter.         **
** In case of 16bit Channel Data Width the DataBufferPtr must be 16bit aligned**
** Different Jobs, consequently also Sequences, can have in common            **
** Channels. But, the use of those shared Channels is restricted. Read and    **
** Write functions can not guarantee the data integrity while Channel data is **
** being transmitted. User must ensure that Read and/or Write functions are   **
** not called during transmission.                                            **
** This method shall be called after one Transmit method call to have         **
** relevant data within IB Channel.                                           **
*******************************************************************************/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0U)||(SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
extern Std_ReturnType Spi_ReadIB
(
  Spi_ChannelType Channel,
  Spi_DataType  *DataBufferPtr
);
#else
#define Spi_ReadIB(Channel,  DataBufferPtr) \
                                      (ERROR_Spi_ReadIB_NOT_SELECTED)

#endif /* SPI_CHANNEL_BUFFERS_ALLOWED == 0
||SPI_CHANNEL_BUFFERS_ALLOWED == 2U */

/*******************************************************************************
** Syntax : Std_ReturnType Spi_SetupEB                                        **
** (                                                                          **
** Spi_ChannelType Channel,                                                   **
** const Spi_DataType* SrcDataBufferPtr,                                      **
** Spi_DataType* DesDataBufferPtr,                                            **
** Spi_NumberOfDataType Length                                                **
** )                                                                          **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Channel - Channel ID.                                    **
**                   SrcDataBufferPtr - Pointer to Source data buffer         **
**                   DesDataBufferPtr - Pointer to Destination data buffer    **
**                   Length - Length of the data to be transmitted from       **
**                   SrcdataBufferPtr and/or received from DesDataBufferPtr   **
**                   Min.: 1                                                  **
**                   Max.: Max of data specified at configuration for         **
**                   this channel                                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Setup command has been accepted.                  **
**                   E_NOT_OK - Setup command has not been accepted.          **
**                                                                            **
** Description : Service to setup the buffers and the length of data          **
** for the EB SPI Handler/Driver Channel specified.                           **
** This service shall update the buffer pointers and lengh attributes         **
** of the specified Channel with the provided values. As these attributes are **
** persistent,they will be used for all succeeding calls to one Transmit      **
** method (for the specified Channel).                                        **
** To transmit a variable number of data, it is mandatory to call             **
** Spi_SetupBuffers function to store new parameters within SPI Handler/Driver**
** before each Spi_Transmit function calls.                                   **
** To transmit a constant number of data, it is only mandatory to call        **
** Spi_SetupBuffers function to store parameters within SPI Handler/Driver    **
** before the first Spi_Transmit function call.                               **
** For EB Channels the application shall provide the buffering,               **
** and shall take care of the consistency of the data in the buffer during    **
** transmission. The size of the Channel buffer is either fixed or variable.  **
** A maximum size for the Channel buffer is fixed by configuration,           **
** but the size of the buffer provided by the User can change.                **
** In case of 16 bit Channel Data Width, The SrcDataBufferPtr and             **
** DesDataBufferPtr must be 16bit aligned.                                    **
** Different Jobs, consequently also Sequences, can have in common            **
** Channels. But, the use of those shared Channels is restricted. Read and    **
** Write functions can not guarantee the data integrity while Channel data is **
** being transmitted. User must ensure that Read and/or Write functions are   **
** not called during transmission.                                            **
** This method shall be called one time for all Channels with EB              **
** declared before to call a Transmit method for them.                        **
**                                                                            **
*******************************************************************************/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 1U)||(SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
extern Std_ReturnType Spi_SetupEB
(
  Spi_ChannelType Channel,
  const Spi_DataType* SrcDataBufferPtr,
  Spi_DataType* DesDataBufferPtr,
  Spi_NumberOfDataType Length
);
#else
#define Spi_SetupEB(Channel, SrcDataBufferPtr, DesDataBufferPtr, Length) \
                                  (ERROR_Spi_SetupEB_NOT_SELECTED)
#endif /* SPI_CHANNEL_BUFFERS_ALLOWED == 1U
          ||SPI_CHANNEL_BUFFERS_ALLOWED == 2U */

/*******************************************************************************
** Syntax : Spi_StatusType Spi_GetStatus(void)                                **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Spi_StatusType                                           **
**                                                                            **
** Description : This service shall return the                                **
** SPI Handler/Driver status.                                                 **
**                                                                            **
*******************************************************************************/
extern Spi_StatusType Spi_GetStatus(void);

/*******************************************************************************
** Syntax : Spi_JobResultType Spi_GetJobResult(Spi_JobType Job)               **
**                                                                            **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Job - Job ID. An invalid job ID will                     **
**                   return an undefined result.                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Spi_JobResultType                                        **
**                                                                            **
** Description : This service shall return the last transmission result       **
** of the specified Job.                                                      **
** The user shall call Spi_GetJobResult() method to know if the Job           **
** transmission succeeded (SPI_JOB_OK) or failed (SPI_JOB_FAILED)             **
**                                                                            **
**                                                                            **
*******************************************************************************/
extern Spi_JobResultType Spi_GetJobResult(Spi_JobType Job);

/*******************************************************************************
** Syntax : Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence)**
**                                                                            **
** Service ID:  0x08                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Sequence - Sequence ID. An invalid sequence ID will      **
**                   return an undefined result.                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Spi_SeqResultType                                        **
**                                                                            **
** Description : This service shall return the last transmission result       **
** of the specified Sequence                                                  **
** The user shall call Spi_GetSequenceResult() method to know if the          **
** full Sequence transmission succeeded (SPI_SEQ_OK) or failed.               **
**                                                                            **
**                                                                            **
*******************************************************************************/
extern Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence);

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI184 ,                              **
DS_AS_SPI046_9_SPI242_9, DS_NAS_SPI_PR128, DS_AS_SPI325                       **
DS_AS_SPI256_9 ,DS_AS403_SPI101_SPI371,DS_AS_SPI196_SPI278_SPI326]            **
** Syntax           : void  Spi_GetVersionInfo                                **
**                    (                                                       **
**                      Std_VersionInfoType *VersionInfoPtr                   **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x09                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : versioninfo - Pointer to where to store the             **
**                    version information of this module.                     **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - This function returns the version information of this module           **
**     The version information include : Module ID, Vendor ID,                **
**     Vendor specific version numbers                                        **
**   - This function is available if the SPI_VERSION_INFO_API is              **
**     set STD_ON                                                             **
**                                                                            **
*******************************************************************************/
#if (SPI_VERSION_INFO_API == STD_ON) && \
  (SPI_DEV_ERROR_DETECT == STD_ON)
#define  Spi_GetVersionInfo(VersionInfoPtr)                             \
{                                                                       \
  if ((VersionInfoPtr) == (NULL_PTR))                                   \
  {                                                                     \
    Det_ReportError(                                                    \
                     (uint16)SPI_MODULE_ID,                             \
                     SPI_INSTANCE_ID,                                   \
                     SPI_SID_GETVERSIONINFO,                            \
                     SPI_E_PARAM_POINTER                                \
                   );/* Report to  DET */                               \
  }                                                                     \
  else                                                                  \
  {                                                                     \
  /* Note that versioninfo pointer is not checked for NULL as the user  \
     is supposed to send the memory allocated pointer */                \
  /* SPI Module ID */                                                   \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = SPI_MODULE_ID;   \
  /* SPI vendor ID */                                                   \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = SPI_VENDOR_ID;   \
  /* major version of SPI */                                            \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =          \
                                     (uint8)SPI_SW_MAJOR_VERSION;       \
  /* minor version of SPI */                                            \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =          \
                                     (uint8)SPI_SW_MINOR_VERSION;       \
  /* patch version of SPI */                                            \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =          \
                                     (uint8)SPI_SW_PATCH_VERSION;       \
  }                                                                     \
}
#elif (SPI_VERSION_INFO_API == STD_ON) && (SPI_DEV_ERROR_DETECT == STD_OFF)
#define  Spi_GetVersionInfo(VersionInfoPtr)                             \
{                                                                       \
  if ((VersionInfoPtr) != (NULL_PTR))                                       \
  {                                                                     \
  /* Note that versioninfo pointer is not checked for NULL as the user  \
     is supposed to send the memory allocated pointer */                \
  /* SPI Module ID */                                                   \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = SPI_MODULE_ID;   \
  /* SPI vendor ID */                                                   \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = SPI_VENDOR_ID;   \
  /* major version of SPI */                                            \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =          \
                                     (uint8)SPI_SW_MAJOR_VERSION;       \
  /* minor version of SPI */                                            \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =          \
                                     (uint8)SPI_SW_MINOR_VERSION;       \
  /* patch version of SPI */                                            \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =          \
                                     (uint8)SPI_SW_PATCH_VERSION;       \
  }                                                                     \
}
#else
#define Spi_GetVersionInfo(VersionInfoPtr)  \
                                      (ERROR_Spi_VersionInfo_NOT_SELECTED)
#endif /* SPI_VERSION_INFO_API == STD_ON */


/*******************************************************************************
** Syntax : Std_ReturnType Spi_SyncTransmit                                   **
**                        (                                                   **
**                           Spi_SequenceType Sequence                        **
**                         )                                                  **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Sequence - Sequnece ID.                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Transmission command has been accepted.           **
**                   E_NOT_OK - Transmission command has been accepted.       **
**                                                                            **
** Description : Sync Service to transmit data on the SPI bus .               **
** This service shall take over the given parameter, initiate a transmission, **
** and set the SPI Handler/Driver status to SPI_BUSY, set the sequence result **
** to SPI_SEQ_PENDING, set the first job result to SPI_JOB_PENDING and return.**
** The LEVEL 0 SPI Handler/Driver shall offer a synchronous transfer          **
** service for SPI busses. When there is no on-going Sequence transmission,   **
** the SPI Handler/Driver shall be in idle state (SPI_IDLE).                  **
** Hence, the LEVEL 0 SPI Handler/Driver shall not allow transmitting         **
** more than one Sequence at the same time. That means during a Sequence      **
** on-going transmission, all requests to transmit another Sequence shall be  **
** rejected.                                                                  **
** The LEVEL 2 SPI Handler/Driver shall offer a synchronous transfer          **
** service for a dedicated SPI bus and it shall also offer an asynchronous    **
** transfer service for others SPI busses. When there is no on-going Sequence **
** transmission, the SPI Handler/Driver shall be in idle state (SPI_IDLE).    **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
extern Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence);
#else
#define Spi_SyncTransmit(Sequence) \
                          (ERROR_Spi_SyncTransmit_NOT_SELECTED)

#endif /* ((SPI_LEVEL_DELIVERED == 0) || (SPI_LEVEL_DELIVERED == 2U)) */

/*******************************************************************************
** Syntax:          Spi_StatusType Spi_GetHWUnitStatus                        **
**                  (                                                         **
**                     Spi_HWUnitType        HWUnit                           **
**                   )                                                        **
** Service ID:       0x0B                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  HWUnit- SPI Bus identifier                               **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :This service shall return the status of the specified         **
** SPI Hardware microcontroller peripheral. The user shall call               **
** Spi_GetHWUnitStatus()  method to know if the specified SPI Hardware        **
** microcontroller peripheral is SPI_IDLE or SPI_BUSY.                        **
** This function is pre compile time configurable                             **
** On / Off by the configuration parameter: SPI_HW_STATUS_API.                **
** Note that the HW Bus is busy only if a Job is running on it.If the HW Bus  **
** is Idle it can be assumed that no job is running on it currently but a job **
** could be pending and can be scheduled to run on the bus later              **
*******************************************************************************/
#if (SPI_HW_STATUS_API == STD_ON)
extern Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit);
#else
#define Spi_GetHWUnitStatus(HWUnit) \
                                (ERROR_Spi_GetHWUnitStatus_NOT_SELECTED)
#endif /*(SPI_HW_STATUS_API == STD_ON) */

/*******************************************************************************
** Syntax:           void Spi_Cancel                                          **
**                   (                                                        **
**                     Spi_SequenceType        Sequence                       **
**                   )                                                        **
**                                                                            **
**                                                                            **
** Service ID:       0x0C                                                     **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  Sequence                                                 **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : This service shall cancel the specified on-going             **
** sequence transmission without cancelling any Job transmission and the SPI  **
** Handler/Driver will set the sequence result to SPI_SEQ_CANCELED.           **
** The SPI Handler/Driver is not responsible on external devices damages or   **
** undefined state due to cancelling a sequence transmission. It is up to the **
** user to be aware of what user is doing!                                    **
*******************************************************************************/
#if (SPI_CANCEL_API == STD_ON)
extern void Spi_Cancel(Spi_SequenceType Sequence);
#else
#define Spi_Cancel(Sequence)   \
                       (ERROR_Spi_Cancel_NOT_SELECTED)
#endif /* SPI_CANCEL_API = STD_ON */

/*******************************************************************************
** Syntax:          Std_ReturnType Spi_SetAsyncMode                           **
**                  (                                                         **
**                    Spi_AsyncModeType        Mode                           **
**                  )                                                         **
**                                                                            **
**                                                                            **
** Service ID:       0x0D                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Non reentrant                                            **
**                                                                            **
** Parameters (in):  Mode                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     E_OK -     command has been accepted.                    **
**                   E_NOT_OK - command has not been accepted.                **
**                                                                            **
** Description :This function is pre compile time selectable by the           **
** configuration parameter: SPI_LEVEL_DELIVERED. This function is only        **
** relevant for LEVEL 2.                                                      **
** This function is pre compile time selectable by the configuration          **
** parameter: SPI_LEVEL_DELIVERED. This function is only relevant for LEVEL 2.**
** The SPI Handler/Driver LEVEL 2 shall implemented one                       **
** polling mechanism mode and one interrupt mechanism mode for SPI busses     **
** handled asynchronously. Both mechanisms are selectable during              **
** execution time                                                             **
*******************************************************************************/
#if (SPI_LEVEL_DELIVERED == 2U)
extern Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode);
#else
#define Spi_SetAsyncMode(Mode) \
                       (ERROR_Spi_SetAsyncMode_NOT_SELECTED)
#endif /* SPI_LEVEL_DELIVERED == 2U */

/*******************************************************************************
**                      Global Function Declarations:                         **
**             Functions to be Called From Interrupt/Scheduler Context        **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED != 0U) || (SPI_SLAVE_ENABLE == STD_ON) )
/*******************************************************************************
** Syntax : void Spi_IsrQspiError(uint32 Module)                              **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : Module : Hardware unit used                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the Error Interrupt of      **
** QSPIx Module.                                                              **
** This interrupt occurs in case of Receive / Phase Errors.                   **
** This interrupt is mapped to the node: QSPIx_ESRC                           **
** This function calls the                                                    **
** DEM with Error Code  - SPI_E_RECEIVE_ERROR                                 **
** Additionally it sets the Job and Sequence Status to SPI_JOB_FAILED,        **
** SPI_SEQUENCE_FAILED respectively. Also it calls the Job end and sequence   **
** end notification if configured.CS is also Disabled.                        **
*******************************************************************************/
extern void Spi_IsrQspiError(uint32 Module);
#endif

#if ((SPI_LEVEL_DELIVERED == 1U)||(SPI_LEVEL_DELIVERED == 2U))
/*******************************************************************************
** Syntax : void extern void Spi_IsrDmaQspiRx(uint32 Module)                  **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : Module : Hardware unit passed.                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the Rx-DMA Channel          **
** (Transaction complete / Error) Interrupt of QSPIx Module when              **
**  no Dma Error has occured.                                                 **
** This function does the following activities:                               **
** 1. Sets up a new DMA transaction for the next channels in the Channel Link.**
** 2. If the channel transmitted is the last channel in a job link, and the   **
**    Sequences is not interruptible, the next job in the Job link is setup   **
**    If the Sequence is interrupible, the scheduler to schedule              **
**    the next job based on priority is called.                               **
** 3. At the end of the job if configured, a job end notification is called.  **
** 4. At the end of the Sequence, if configured, a seq end notification       **
**    is called.                                                              **
*******************************************************************************/
extern void Spi_IsrDmaQspiRx(uint32 Module);

/*******************************************************************************
** Syntax : void Spi_IsrDmaQspiTx(uint32 Module)                              **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Module : Hardware unit used (QSPIx)                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the TX-Dma Channel          **
** (Transaction complete / Error) Interrupt of QSPIx Module when              **
**  no Dma Error has occured.                                                 **
** This function  disables the Tx-Dma Channel interrupt and                   **
** also the Qspi Tx interrupt. Then it sets the BACON.LAST to 1               **
** and updates the last word to be transmitted on Qspix Hw. This transfers    **
** [i.e TX] the last word of Last Channel of job and puts the Chipselect to   **
** inactive state                                                             **
*******************************************************************************/
extern void Spi_IsrDmaQspiTx(uint32 Module);
extern void Spi_IsrQspiPt(uint32 Module) ;
extern void Spi_IsrQspiUsr(uint32 Module) ;

/*******************************************************************************
** Syntax : void Spi_IsrDmaError(uint32 Module)                               **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : Module                                                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the TX/Rx Dma Channel       **
** (Transaction complete / Error) Interrupt of QSPIx Module when              **
**  a Dma Error has occured.                                                  **
** This interrupt occurs in case of DMA Error, when a trigger request is lost.**
** This function calls the                                                    **
** DEM with Error Code  - SPI_E_DMA_TRANSFER.                                 **
** Additionally it sets the Job and Sequence Status to SPI_JOB_FAILED,        **
** SPI_SEQUENCE_FAILED respectively. Also it calls the Job end and sequence   **
** end notification if configured. CS is also Disabled. It also disables the  **
** Qspi Tx interrupt in case if it's enabled.                                 **
*******************************************************************************/
extern void Spi_IsrDmaError(uint32 Module);

/*******************************************************************************
** Syntax : void Spi_IsrCheckDmaError(uint32 Module)                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : Module                                                   **
**                                                                            **
** Parameters (out): Error status                                             **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the TX/Rx Dma Channel       **
** (Transaction complete / Error) Interrupt of QSPIx Module .                 **
** This interrupt checks if there is an error in Dma  interrupt               **
** It also clears the error flags and returns the Error status                **
*******************************************************************************/
extern uint32 Spi_IsrCheckDmaError(uint32 Module);

/*******************************************************************************
** Syntax           : void  Spi_MainFunction_Handling                         **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x10                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Timing           : Fixed Cyclic                                            **
**                    The user has to determine the cycle rate depending upon **
**                    the baud rate of the transmission and frequency of the  **
**                    job scheduling required.                                **
**                                                                            **
** Description      : This function replaces the interrupt mechanism used     **
** to handle jobs on the bus. The function polls for the completion of a      **
** channel transmission (a DMA Tansaction) and calls the                      **
** function:SpilBusHandler. In addition this function also checks for errors  **
** (production) on the SPI bus and performs the needed error handling (calls  **
** Spi_lErrorHandler)                                                         **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 2U) || ((SPI_LEVEL_DELIVERED == 1U)&&\
(SPI_ASYNC_MODE_LEVEL1 == SPI_ASYNC_MODE_POLLING)))
extern void Spi_MainFunction_Handling(void);
#else
#define Spi_MainFunction_Handling() \
                  (ERROR_Spi_MainFunction_Handling_NOT_SELECTED)

#endif /* ((SPI_LEVEL_DELIVERED == 2U) || ((SPI_LEVEL_DELIVERED == 1U)&&
         (SPI_ASYNC_MODE_LEVEL1 == SPI_ASYNC_MODE_POLLING)))*/

#endif /* (SPI_LEVEL_DELIVERED == 1U)||(SPI_LEVEL_DELIVERED == 2U) */

#if ((SPI_LEVEL_DELIVERED == 0U) && (SPI_SLAVE_ENABLE == STD_ON))
/* Rx interrupt required in case of sync transmit and slave
   read back */
extern void Spi_IsrDmaQspiRx(uint32 Module);
extern void Spi_IsrDmaError(uint32 Module);
extern uint32 Spi_IsrCheckDmaError(uint32 Module);
#endif

#if(SPI_SAFETY_ENABLE == STD_ON)
#if(SPI_SLAVE_ENABLE == STD_ON)
/*******************************************************************************
** Syntax : Std_ReturnType Spi_SlaveSetupEB                                   **
** (                                                                          **
**   Spi_ChannelType SlaveChannel,                                            **
**   Spi_DataType* SlaveDesDataBufferPtr,                                     **
**   Spi_NumberOfDataType SlaveDataLength                                     **
** )                                                                          **
** [/cover]                                                                   **
** Service ID:  0x11                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : SlaveChannel - Slave Channel ID.                         **
**                   SlaveDesDataBufferPtr - Pointer to Destination data      **
**                   buffer to store recieved data from SPI Master            **
**                   SlaveDataLength - Length of the data to be recieved      **
**                   on this channel                                          **
**                   Min.: 1                                                  **
**                   Max.: Max of data specified at configuration for         **
**                   this channel                                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Setup command has been accepted.                  **
**                   E_NOT_OK - Setup command has not been accepted.          **
**                                                                            **
** Description : Service to setup the buffers and the length of data          **
** for the External Buffer of SPI SLAVE Channel.                              **
** This service shall update the buffer pointers and lengh attributes         **
*******************************************************************************/
extern Std_ReturnType Spi_SlaveSetupEB
(
  Spi_ChannelType Channel,
  Spi_DataType* DesDataBufferPtr,
  Spi_NumberOfDataType DataLength
);

/*******************************************************************************
** Syntax : extern Std_ReturnType Spi_SlaveReadPrepare                        **
**                 (Spi_SequenceType Sequence);                               **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x12                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Sequence - Sequnece ID.                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Transmission command has been accepted.           **
**                   E_NOT_OK - Transmission command has been accepted.       **
**                                                                            **
** Description : Spi_SlaveReadPrepare to read data on the SPI bus.            **
** This service take over the given parameter, initiate a transmission,       **
** and set the SPI Handler/Driver status to SPI_BUSY, set the sequence result **
** to SPI_SEQ_PENDING, set the first job result to SPI_JOB_PENDING and return.**
** This function is pre compile time selectable by the configuration          **
** parameter:SPI_LEVEL_DELIVERED. This function is only relevant for          **
** LEVEL 1 and LEVEL 2.                                                       **
** The function allows transmitting more than one Sequence at the             **
** same time. That means during a Sequence on-going transmission, all requests**
** to transmit another Sequence shall be evaluated, using the                 **
** lead Job, for an acceptance if different SPI buses or for set to           **
** pending state for transmission later.                                      **
** This method shall be called after a Spi_SetupEB method for EB Channels or  **
** Spi_WriteIB method for IB Channels but before the Spi_ReadIB method.       **
*******************************************************************************/
extern Std_ReturnType Spi_SlaveReadPrepare(Spi_SequenceType Sequence);



#endif
#endif

/*Memory Map of the SPI Code*/
#define SPI_STOP_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif /* SPI_H */


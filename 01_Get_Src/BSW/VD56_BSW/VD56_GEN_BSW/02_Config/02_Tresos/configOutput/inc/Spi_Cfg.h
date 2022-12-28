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
**  FILENAME  : Spi_Cfg.h                                                     **
**                                                                            **
**  $CC VERSION : \main\64 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-11-07, 12:35:26                                          **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SPI configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SPI_CFG_H
#define SPI_CFG_H
/*Section to Generate Autosar Specific Version Information*/


#define SPI_AR_RELEASE_MAJOR_VERSION  (4U)
#define SPI_AR_RELEASE_MINOR_VERSION  (0U)
#define SPI_AR_RELEASE_REVISION_VERSION  (3U)

/*Section to Generate Vendor Specific Version Information*/
/* Vendor specific implementation version information */
#define SPI_SW_MAJOR_VERSION   (4U)
#define SPI_SW_MINOR_VERSION   (2U)
#define SPI_SW_PATCH_VERSION   (2U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
  /* Configuration: Total number of Config Root */
#define SPI_CONFIG_COUNT  (1U)

/*
         Container : SpiGeneralConfiguration
*/

/*
Configuration: SPI_DEV_ERROR_DETECT
- if STD_ON, DET is Enabled
- if STD_OFF,DET is Disabled
SPI005: The detection of all development errors is configurable (On / Off)
at precompile time. The switch SPI_DEV_ERROR_DETECT (see chapter 10) shall
activate or deactivate the detection of all development errors.

SPI029:If the switch SPI_DEV_ERROR_DETECT is enabled API parameter checking
is also enabled.
*/
#define SPI_DEV_ERROR_DETECT  (STD_ON)


/*
Configuration: SPI_VERSION_INFO_API
- if STD_ON, Function Spi_GetVersionInfo is available
- if STD_OFF,Function Spi_GetVersionInfo is not available
*/
#define SPI_VERSION_INFO_API  (STD_OFF)


/*
Configuration: SPI_LEVEL_DELIVERED
Configure the Spi Handler/driver level of scalablity
0:The LEVEL 0 Simple Synchronous SPI Handler/Driver functionalities are
  selected.
1:The LEVEL 1 Basic Asynchronous SPI Handler/Driver functionalities are
  selected.
2:The LEVEL 2 Enhanced SPI Handler/Driver functionalities are selected.
SPI109: The SPI Handler/Driver level of scalable functionality shall be always
statically configurable, that means configured at pre-compile time, to allow the
best source code optimisation.
SPI110: In order to select the SPI Handler/Driver level of scalable
functionality, the SPI_LEVEL_DELIVERED parameter shall be configured with
one of the 3 authorized values according to the described levels: 0, 1 or 2.
*/
#define SPI_LEVEL_DELIVERED  (1U)

/*
Configuration: SPI_CHANNEL_BUFFERS_ALLOWED
Configure the Spi Handler/driver buffer usage
0:The Usage 0, only Internal Buffers are selected in Handler/Driver.
1:The Usage 1, only External Buffers are selected in Handler/Driver.
2:The Usage 2, both Internal and External Buffers are selected in
Handler/Driver.
SPI111: In order to select which Channel Buffers the SPI Handler/Driver manages,
the SPI_CHANNEL_BUFFERS_ALLOWED parameter shall be configured with one of
the 3 authorized values according to the described usage: 0, 1 or 2.
SPI115,SPI117.
*/
#define SPI_CHANNEL_BUFFERS_ALLOWED  (0U)

/*
Configuration: SPI_INTERRUPTABLE_SEQUENCE_ALLOWED
- if STD_ON, configuration of interruptible sequences is allowed
- if STD_OFF,configuration of interruptible sequences is not allowed
SPI121, SPI122
*/
#define SPI_INTERRUPTABLE_SEQUENCE_ALLOWED  (STD_OFF)


/*
Configuration: SPI_HW_STATUS_API
- if STD_ON, Function Spi_GetHWUnitStatus is available
- if STD_OFF,Function Spi_GetHWUnitStatus is not available
*/
#define SPI_HW_STATUS_API  (STD_OFF)


/*
Configuration: SPI_HW_STATUS_API
- if STD_ON, Function Spi_Cancel is available
- if STD_OFF,Function Spi_Cancel is not available
*/
#define SPI_CANCEL_API  (STD_OFF)


/*
Configuration: SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT
- if STD_ON, concurrent Spi_SyncTransmit() calls for different se-quences on
    different buses allowed
- if STD_OFF, concurrent Spi_SyncTransmit() calls for different se-quences on
   different buses Not allowed
*/
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT  (STD_OFF)

/*
Configuration: SPI_MAX_JOB_TRIG_Q_LENGTH
Configure the total SPI Job Queue length.
*/
#define SPI_MAX_JOB_TRIG_Q_LENGTH  (200U)

/*
Configuration: SPI_PB_FIXEDADDR
- if STD_ON, Fixed Address feature is Enabled
- if STD_OFF,Fixed Address feature is Disabled
*/
#define SPI_PB_FIXEDADDR  (STD_OFF)


/*
Configuration: SPI_SYNCTRANSMIT_TIMEOUT_COUNTER
 Timeout loop counter while waiting for data transmission/reception
 of 1 data element
*/
#define SPI_SYNCTRANSMIT_TIMEOUT_COUNTER  (1048575U)


/*
                 Container : SpiDriverConfiguration
*/

/*
Configuration : SPI_MAXIMUM_SEQUENCE
It is the maximum among the total number of sequences configured in each
Spi configuration.
For example if there are two post build configurations with 2 and 3 sequences
repectively, SPI_MAXIMUM_SEQUENCE must be configured as 3.
*/
#define SPI_MAXIMUM_SEQUENCE (7U)

/*
Configuration : SPI_MAXIMUM_IB_BUFFER_SIZE(Vendor Specific)
It is the maximum among the total number of IB buffer size configured in each
Spi configuration.
For example if there are two post build configurations, one having 3 IB channels
with total buffer size 30 and another having 2 IB channels with total buffer
size 40, SPI_MAXIMUM_IB_BUFFER_SIZE must be configured as 40.
The IB Buffer is realized by software implementation.
This parameter provides the buffer size to be used based on the number of
IB Channels configured and their buffer size.
*/

#define SPI_MAXIMUM_IB_BUFFER_SIZE  (20U)
/*
Configuration : SPI_MAXIMUM_EB_CHANNELS(Vendor Specific)
It is the maximum among the total number of EB channels configured in each
Spi configuration.
For example if there are two post build configurations, one having 5 EB channels
and another having 2 EB channels, SPI_MAXIMUM_EB_CHANNELS must be
configured as 5.
*/
#define SPI_MAXIMUM_EB_CHANNELS  (0U)

/*
Configuration: SPI_MAXIMUM_IB_CHANNELS(Vendor Specific)
It is the maximum among the total number of IB channels configured in each
Spi configuration.
For example if there are two post build configurations, one having 3 IB channels
and another having 6 IB channels, SPI_MAXIMUM_IB_CHANNELS must be
configured as 6.
*/
#define SPI_MAXIMUM_IB_CHANNELS  (7U)

/*
Configuration: SPI_MAXIMUM_CHANNEL
It is the maximum among the total number of channels configured in each
Spi configuration.
*/
#define SPI_MAXIMUM_CHANNEL  (7U)

/*
Configuration: SPI_MAXIMUM_JOB
It is the maximum among the total number of Jobs configured in each
Spi configuration.
*/
#define SPI_MAXIMUM_JOB  (7U)

/*
Configuration: SPI_WRITELOCK_INDEX
This is the array index valve to define the total number of IB channels
configured to be used in Spi_WriteIB API to lock the channels using
variable Spi_ChannelWriteLock
*/
#define SPI_WRITELOCK_INDEX (1U)

/*
Configuration: SPI_SAFETY_ENABLE
This determines if the safety features of SPI is enabled or not.
*/
#define SPI_SAFETY_ENABLE (STD_OFF)

/*
Configuration: SPI_SLAVE_ENABLE
This determines if the Slave has been configured or not
*/
#define SPI_SLAVE_ENABLE (STD_OFF)



/*
                    Container : SpiChannelConfiguration
*/
/*
Configuration: SPI_CHANNEL_NAME
SPI Driver Channel Symbolic Names. For Each Channel a unique Id is created.
The Symbolic Name is Equivalent to the Channel Container Name
*/

#define SpiConf_SpiChannel_L9781_ASIC_1_CH ((Spi_ChannelType)0)
#define SpiConf_SpiChannel_L9781_ASIC_2_CH ((Spi_ChannelType)1)
#define SpiConf_SpiChannel_CJ135_U2450_SPI_CHANNEL ((Spi_ChannelType)2)
#define SpiConf_SpiChannel_TLF35584_CH ((Spi_ChannelType)3)
#define SpiConf_SpiChannel_L9960_U2000_CH ((Spi_ChannelType)4)
#define SpiConf_SpiChannel_L9960_U2001_CH ((Spi_ChannelType)5)
#define SpiConf_SpiChannel_L9960_U2002_CH ((Spi_ChannelType)6)


/*
Configuration Options:
Selection of Channel Buffer Type
*/
/* EB Buffer Channel Type */
#define SPI_EB_BUFFER   (0U)

/* IB Buffer Channel Type */
#define SPI_IB_BUFFER   (1U)

/*
Configuration Options:
SPI Data Order Options
*/
/* Least Significant Bit is transferred first */
#define SPI_DATA_LSB_FIRST   (0U)

/* Most Significant Bit is transferred first */
#define SPI_DATA_MSB_FIRST   (1U)

/*
Macro: CHANNEL_LINK_DELIMITER
Identifier for Channel Link End Delimiter.
This parameter is used internally in the driver code to determine end
of Channel Link.
*/
#define SPI_CHANNEL_LINK_DELIMITER ((Spi_ChannelType)0xFF)

/*
                   Container : SpiJobConfiguration
*/

/*
Configuration: Job Name
SPI Driver Job Symbolic Names. For Each Job a unique Id is created.
The Symbolic Name is Equivalent to the Job Container Name.
This name is referenced to build the Job Link within a sequence.
*/
#define SpiConf_SpiJob_CJ135_U2450_SPI_JOB ((Spi_JobType)0)
#define SpiConf_SpiJob_TLF35584_JOB ((Spi_JobType)1)
#define SpiConf_SpiJob_L9960_U2000_SPI_JOB ((Spi_JobType)2)
#define SpiConf_SpiJob_L9960_U2001_SPI_JOB ((Spi_JobType)3)
#define SpiConf_SpiJob_L9960_U2002_SPI_JOB ((Spi_JobType)4)
#define SpiConf_SpiJob_L9781_ASIC_1_JOB ((Spi_JobType)5)
#define SpiConf_SpiJob_L9781_ASIC_2_JOB ((Spi_JobType)6)
/*
Configuration Options:
SPI Shift Clock Idle Levels
*/
/* Idle Level : Low Voltage Level */
#define SPI_CLK_IDLE_LOW       (0U)
/* Idle Level : High Voltage Level */
#define SPI_CLK_IDLE_HIGH      (1U)

/*
Configuration Options:
SPI Data Shift Edge Options
*/
#define SPI_DATA_SHIFT_LEAD    ((uint8)1U)
#define SPI_DATA_SHIFT_TRAIL   ((uint8)0U)

/*
Configuration Options:
SPI CS Polarity Levels (The Active Level)
*/
/* Polarity : Low Voltage Level */
#define SPI_CS_POLARITY_LOW    (0U)
/* Polarity : High Voltage Level */
#define SPI_CS_POLARITY_HIGH   (1U)

/*
Configuration Options:
SPI CS Pins
*/
/* The  CS Pins are configured in the Module Port */
/* The following define is used if no Pins are referenced */
#define SPI_CS_NONE ((uint16)0xFFFF)

#define SPI_CS_HW   ((uint16)0xEFFF)


/*
Macro:JOB_LINK_DELIMITER
Job Link End Delimiter.
This parameter is used internally in the driver code to determine end
of Job Link.
*/
#define SPI_JOB_LINK_DELIMITER ((Spi_JobType)0xFFFF)

/*
Macro:SPI_SHARED_JOBS_DELIMITER
Sequences sharing jobs end Delimiter.
This parameter is used internally in the driver code to determine end
of sequences sharing the Job Link.
*/
#define SPI_SHARED_JOBS_DELIMITER ((uint8)0xFF)


/*
            Container : SpiSequenceConfiguration
*/

/*
Configuration Options:
SPI Sequence Interruptible Options
*/
#define SPI_SEQ_INT_FALSE     ((uint8)0)
#define SPI_SEQ_INT_TRUE      ((uint8)1)

/*
Configuration: SPI_SEQUENCE_NAME
SPI Driver Sequence Symbolic Names. For Each Sequence a unique Id is created.
The Symbolic Name is Equivalent to the Sequence Container Name*/
#define SpiConf_SpiSequence_CJ135_U2450_SPI_SEQ ((Spi_SequenceType)0)
#define SpiConf_SpiSequence_TLF35584_SEQ ((Spi_SequenceType)1)
#define SpiConf_SpiSequence_L9960_U2000_SPI_SEQ ((Spi_SequenceType)2)
#define SpiConf_SpiSequence_L9960_U2001_SPI_SEQ ((Spi_SequenceType)3)
#define SpiConf_SpiSequence_L9960_U2002_SPI_SEQ ((Spi_SequenceType)4)
#define SpiConf_SpiSequence_L9781_ASIC_1_SEQ ((Spi_SequenceType)5)
#define SpiConf_SpiSequence_L9781_ASIC_2_SEQ ((Spi_SequenceType)6)


/*
              Container : SpiHardwareConfiguration
*/

/*
Configuration Options:
Spi HW Units supported. This parameter is used internally
by the other configurations. The user should not alter this.
*/
#define SPI_0 ((uint8)0)
#define SPI_1 ((uint8)1)
#define SPI_2 ((uint8)2)
#define SPI_3 ((uint8)3)
#define SPI_4 ((uint8)4)
#define SPI_5 ((uint8)5)

#define SPI_QSPI_CHANNEL0 ((uint8)0)
#define SPI_QSPI_CHANNEL1 ((uint8)1)
#define SPI_QSPI_CHANNEL2 ((uint8)2)
#define SPI_QSPI_CHANNEL3 ((uint8)3)
#define SPI_QSPI_CHANNEL4 ((uint8)4)
#define SPI_QSPI_CHANNEL5 ((uint8)5)
#define SPI_QSPI_CHANNEL6 ((uint8)6)
#define SPI_QSPI_CHANNEL7 ((uint8)7)
#define SPI_QSPI_CHANNEL8 ((uint8)8)
#define SPI_QSPI_CHANNEL9 ((uint8)9)
#define SPI_QSPI_CHANNEL10 ((uint8)10)
#define SPI_QSPI_CHANNEL11 ((uint8)11)
#define SPI_QSPI_CHANNEL12 ((uint8)12)
#define SPI_QSPI_CHANNEL13 ((uint8)13)
#define SPI_QSPI_CHANNEL14 ((uint8)14)
#define SPI_QSPI_CHANNEL15 ((uint8)15)

/*
Configuration Options:
configuration options to check whether HW modules QSPIx are configured
*/
#define SPI_0_NOT_CONFIGURED   (255U)
#define SPI_1_NOT_CONFIGURED   (255U)
#define SPI_2_NOT_CONFIGURED   (255U)
#define SPI_3_NOT_CONFIGURED   (255U)
#define SPI_4_NOT_CONFIGURED   (255U)
#define SPI_5_NOT_CONFIGURED   (255U)
/*
Configuration Options:
QSPI Module Sleep Settings
*/
/* SPI Module is enabled.Module Does not enter Sleep Mode upon Sleep Request.*/
#define SPI_CLK_SLEEP_DISABLE   (0x00000008U)

/* SPI Module is Enabled.Module Enters Sleep Mode upon Sleep Request.*/
#define SPI_CLK_SLEEP_ENABLE    (0x00000000U)

/*
  Transmit and Receive Dma Channel IRQ Priorities.
*/
#define IRQ_QSPI0_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL1_SR_PRIO)
#define IRQ_QSPI0_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL0_SR_PRIO)
#define IRQ_QSPI1_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL3_SR_PRIO)
#define IRQ_QSPI1_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL2_SR_PRIO)
#define IRQ_QSPI2_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL5_SR_PRIO)
#define IRQ_QSPI2_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL4_SR_PRIO)
#define IRQ_QSPI3_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL7_SR_PRIO)
#define IRQ_QSPI3_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL6_SR_PRIO)
#define IRQ_QSPI4_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL9_SR_PRIO)
#define IRQ_QSPI4_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL8_SR_PRIO)
/*
  Transmit and Receive Dma Channel IRQ CAT.
*/
#define IRQ_QSPI0_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL1_SR_CAT)
#define IRQ_QSPI0_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL0_SR_CAT)
#define IRQ_QSPI1_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL3_SR_CAT)
#define IRQ_QSPI1_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL2_SR_CAT)
#define IRQ_QSPI2_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL5_SR_CAT)
#define IRQ_QSPI2_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL4_SR_CAT)
#define IRQ_QSPI3_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL7_SR_CAT)
#define IRQ_QSPI3_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL6_SR_CAT)
#define IRQ_QSPI4_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL9_SR_CAT)
#define IRQ_QSPI4_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL8_SR_CAT)

/*
Master receive pin input selection
MRSTxA : 0
MRSTxB : 1
*/
#define SPI_QSPI0_MRIS_SEL (2U)
#define SPI_QSPI1_MRIS_SEL (0U)
#define SPI_QSPI2_MRIS_SEL (0U)
#define SPI_QSPI3_MRIS_SEL (0U)
#define SPI_QSPI4_MRIS_SEL (0U)

/*
Configuration: SPI_QSPI0_USED
- if STD_ON, QSPI0 is used
- if STD_OFF,QSPI0 is not used
*/
#define SPI_QSPI0_USED  (STD_ON)
/* Index For QSPI0 Module */
#define SPI_QSPI0_INDEX (0U)

/*
Configuration: SPI_QSPI1_USED
- if STD_ON, QSPI1 is used
- if STD_OFF,QSPI1 is not used
*/
#define SPI_QSPI1_USED (STD_OFF)

/*
Configuration: SPI_QSPI2_USED
- if STD_ON, QSPI2 is used
- if STD_OFF,QSPI2 is not used
*/
#define SPI_QSPI2_USED (STD_ON)
/* Index For QSPI2 Module */
#define SPI_QSPI2_INDEX (2U)

/*
Configuration: SPI_QSPI3_USED
- if STD_ON, QSPI3 is used
- if STD_OFF,QSPI3 is not used
*/
#define SPI_QSPI3_USED (STD_OFF)

/*
Configuration: SPI_QSPI4_USED
- if STD_ON, QSPI4 is used
- if STD_OFF,QSPI4 is not used
*/
#define SPI_QSPI4_USED (STD_ON)
/* Index For QSPI4 Module */
#define SPI_QSPI4_INDEX (4U)

/*
Configuration: SPI_QSPI5_USED
- if STD_ON, QSPI5 is used
- if STD_OFF,QSPI5 is not used
*/
#define SPI_QSPI5_USED (STD_OFF)

/* SPI Master Used Modules */
#define SPI_MASTER_MODULES_USED      (0x0015U)


/*
Configuration: SPI_SEQUENCE_QM_ARRAY_INDEX
This is the array index valve to define the total number of non-safety
sequences configured to be used in Spi_SeqStatus, SpiSeqCancel variables.
*/
#define SPI_SEQUENCE_QM_ARRAY_INDEX (1U)

/*
Configuration: SPI_JOB_QM_ARRAY_INDEX
This is the array index valve to define the total number of non-safety jobs
configured to be used in Spi_JobResult variables.
*/
#define SPI_JOB_QM_ARRAY_INDEX (1U)

/*
Configuration: Aync Mode for Level 1
By default the Mode is Interrupt mechanism. However the Mode can be switched
to Polling Manually by setting this configuration to SPI_POLLING_MODE.
In this case the interrupts QSPI0_ESRC, DMA_SRC00 are not required
*/
#define SPI_ASYNC_MODE_LEVEL1 (SPI_ASYNC_MODE_INTERRUPT)

#define SPI_DMA_ADDR_SIZE_ALIGN_CHECK   (STD_OFF)

/* Switch to globally enable / disable Seq end notification */
#define SPI_SEQ_END_NOTIF_REQ   (STD_ON)
/* Switch to globally enable / disable Job end notification */
#define SPI_JOB_END_NOTIF_REQ   (STD_OFF)

/*
 Number of HW SPI Modules:
*/
/*SPI108: The LEVEL 2 SPI Handler/Driver is specified for microcontrollers
that have to provide, at least, two SPI busses using separated hardware units.
Otherwise,using this level of functionality makes no sense.*/
#define SPI_MAX_HW_UNIT   (5U)

#define SPI_DMA_ADDRESS_ACCESS   (STD_ON)

#define SYNC_BUS (0)
#define ASYNC_BUS (1)

/* QSPI HW Type */
#define SPI_QSPI0_HWTYPE  (ASYNC_BUS)
#define SPI_QSPI2_HWTYPE  (ASYNC_BUS)
#define SPI_QSPI4_HWTYPE  (ASYNC_BUS)


/* SPI ASYNC Modules */
#define SPI_ASYNC_MODULES   (0x0015U)

#define SPI_ASIL_MASTER_ASYNC_USED (STD_OFF)

#define SPI_LOOPCNTR_MAX (0xFFFFFFFEU)

#define IFX_SPI_DEBUG_TX (STD_OFF)

#define IFX_SPI_DEBUG_ERR (STD_OFF)


/* SPI Number of QM Async masters configured */
#define SPI_NUM_QM_ASYNC_MASTERS    (3U)

/* Module Debug Support */
#define SPI_DEBUG_SUPPORT  (STD_OFF)

/* SpiAsyncParallelTransmit Support */
#define SPI_ASYNC_PARALLEL_TRANSMIT  (STD_OFF)

/* Dem reporting  macros */
#define DEM_REPORT_DISABLED (0U)
#define DEM_REPORT_ENABLED (1U)

#define SPI_DMA_ERROR_DEM_REPORT    (DISABLE_DEM_REPORT)

#define SPI_HW_ERROR_DEM_REPORT    (DISABLE_DEM_REPORT)

/*
Function Like Macro:Spi_DataConfig
Data Width, Data Order
*/
#define Spi_DataConfig(DataWidth,Heading) ((uint16)(((DataWidth) - (1U))\
                                                |(((uint32)(Heading)) << (8U))))

/*
Function Like Macro:Spi_ShiftClkConfig
Configuration of Shift Clock according to Register setting:
Clock Polarity and Clock Phase/Data Shift Edge
*/
#define Spi_ShiftClkConfig(ClkPolarity,DataShiftEdge) ((uint8)\
((uint8) ( ((uint8)(ClkPolarity)) << (1U)) | ((uint8)(DataShiftEdge)) ))

/*
Function Like Macro: Spi_BaudRateParams
Spi baud rate parameters GLOBALCON.TQ, ECON.Q, A, B, C
bit 0-7: TQ
bit 8-13 : Q
bit 16-17 : A
bit 18-19 : B
bit 20-21 : C
*/
#define Spi_BaudRateParams(TQ, Q, A, B, C) ((uint32)((((uint32)(TQ)) )|  \
                        (((uint32)(Q)) << ( 8U))| (((uint32)(A)) << (16U))| \
                        (((uint32)(B)) << (18U))| (((uint32)(C)) << (20U))))


/*
Function Like Macro: Spi_CsGpioPortPin
Bit 0 - 3 : Pin no
Bit 4 - 9 : Port no
*/
#define Spi_CsGpioPortPin(Port,Pin) ((uint16)( ((Port) << (4U)) | ((Pin) )))

/*
Function Like Macro: Spi_DelayParams
Spi delay parameters according to register setting (BACON)
   bit 0 : Reserved
   bit 1-3: IPRE
   bit 4-6: IDLE
   bit 7-9: LPRE
   bit 10-12: LEAD
   bit 13-15: TPRE
   bit 16-18: TRAIL
   bit 19-31: Reserved

*/
#define Spi_DelayParams(IPRE,IDLE,LPRE,LEAD,TPRE,TRAIL) \
((uint32)(\
(((uint32)(IPRE) & (0x7U)) << ( 1U)) | (((uint32)(IDLE)  & (0x7U)) << ( 4U))| \
(((uint32)(LPRE) & (0x7U)) << ( 7U)) | (((uint32)(LEAD)  & (0x7U)) << (10U))| \
(((uint32)(TPRE) & (0x7U)) << (13U)) | (((uint32)(TRAIL) & (0x7U)) << (16U))  \
))

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
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* SPI_CFG_H */


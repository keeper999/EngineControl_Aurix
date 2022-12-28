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
**  $FILENAME   : Icu_17_GtmCcu6_Local.h $                                   **
**                                                                           **
**  $CC VERSION : \main\29 $                                                 **
**                                                                           **
**  $DATE       : 2014-01-14 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION :  This file contains                                        **
**                 - functionality of ICU driver.                            **                 
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                     **
**                                                                           **
******************************************************************************/

#ifndef ICU_17_GTMCCU6_LOCAL_H
#define ICU_17_GTMCCU6_LOCAL_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
#ifdef VALEO_PATCH_MCAL_ICU_MOVE_DECLARATION

#define ICU_17_GTMCCU6_START_SEC_VAR_32BIT
#include "MemMap.h"


#if (ICU_PB_FIXEDADDR == STD_OFF)
/* To store the ICU driver configuration pointer */
extern const Icu_17_GtmCcu6_ConfigType *Icu_kConfigPtr;
#endif
/*(ICU_PB_FIXEDADDR == STD_OFF)*/

#define ICU_17_GTMCCU6_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#define ICU_17_GTMCCU6_START_SEC_CONST_32BIT

#include "MemMap.h"

#if (ICU_PB_FIXEDADDR == STD_ON)
/* Variable Holds the Configuration Pointer given in Icu_17_GtmCcu6_Init */
extern const Icu_17_GtmCcu6_ConfigType* const Icu_kConfigPtr;
#endif
/*(ICU_PB_FIXEDADDR == STD_ON)*/


#define ICU_17_GTMCCU6_STOP_SEC_CONST_32BIT
#include "MemMap.h" 

#endif  /* VALEO_PATCH_MCAL_ICU_MOVE_DECLARATION */

/*
The following derivations just give an option 
in C file implementation to know whether the resource is ever used or not.
This helps in further optimization of code.
*/
#if ((ICU_TIM_SIGMEAS_USED == STD_ON)||(ICU_TIM_SIGEDGE_USED == STD_ON)  \
    ||(ICU_TIM_EDGECNT_USED == STD_ON)||(ICU_TIM_TIMSTMP_USED == STD_ON))
#define ICU_GTM_TIM_USED         (STD_ON)
#else
#define ICU_GTM_TIM_USED         (STD_OFF)
#endif

#if ((ICU_QM_TIM_SIGMEAS_USED == STD_ON)||(ICU_QM_TIM_SIGEDGE_USED == STD_ON) \
   ||(ICU_QM_TIM_EDGECNT_USED == STD_ON)||(ICU_QM_TIM_TIMESTAMP_USED == STD_ON))
#define ICU_QM_GTM_TIM_USED         (STD_ON)
#else
#define ICU_QM_GTM_TIM_USED         (STD_OFF)
#endif

#if (ICU_ERU_SIGEDGE_USED == STD_ON)
#define ICU_ERU_USED             (STD_ON)
#else
#define ICU_ERU_USED             (STD_OFF)
#endif
   

#if ((ICU_TIM_SIGEDGE_USED == STD_ON) || (ICU_ERU_USED == STD_ON) || \
     (ICU_CCU6_SIGEDGE_USED == STD_ON))  
#define ICU_EDGE_DETECTION_USED (STD_ON)
#else
#define ICU_EDGE_DETECTION_USED (STD_OFF)
#endif

/* Set Activation condition function is needed only in case Edge Detection, 
   Timestamp measurement or Edge counting mode is configured */
#if ((ICU_TIM_SIGEDGE_USED == STD_ON) || (ICU_TIM_EDGECNT_USED == STD_ON) || \
     (ICU_TIM_TIMSTMP_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON)   \
     || (ICU_ERU_USED == STD_ON))
#define ICU_SET_ACTIVATION_REQD (STD_ON)
#else
#define ICU_SET_ACTIVATION_REQD (STD_OFF)
#endif


#if ((ICU_ERU_USED == STD_ON) || (ICU_TIM_SIGEDGE_USED == STD_ON) || \
     (ICU_CCU6_SIGEDGE_USED == STD_ON))
#define ICU_EDGE_NOTIF_USED    (STD_ON)
#else
#define ICU_EDGE_NOTIF_USED    (STD_OFF)
#endif


/* General Requirements:
ICU085: All timer units will be of ticks. This is mainly applicable in
        Icu_17_GtmCcu6_GetTimeElapsed , Icu_17_GtmCcu6_GetDutyCycleValues.
ICU117: NA (no DEM)
ICU112: All API's parameter checking is enabled by ICU_DEV_ERROR_DETECT
ICU113: NA (no DEM)
ICU003: NA (no DEM)
ICU004: no specific error implementation
ICU119: resetting interrupt flag handled by GPTA Driver.
ICU131: Other required modules are MCU, PORT , IRQ and GPTA.
ICU115: NA (File structure)
ICU116: NA (DEM)
*/

/******************************************************************************
**                      Private Macro Definitions                            **
******************************************************************************/
#define ICU_GTM_ASIL_CHANNEL 0U

#define ICU_CCU6_ASIL_CHANNEL 1U

#define ICU_GTM_QM_CHANNEL 2U

#define ICU_CCU6_QM_CHANNEL 3U

#define ICU_ERU_QM_CHANNEL 4U 

#define ICU_QM_CHANNEL 5U 

/* To indicate an error */
#define ICU_ERROR_FOUND                (1U)

#define ICU_ERROR_NOT_FOUND            (0U)

/* For CLRR position in SRC registers */
#define ICU_CLRR_POSITION              (25U)
/* To assert CLRR */
#define ICU_CLRR_ASSERT                (1UL)
/* To enable the notification */
#define ICU_ENABLE_NOTIFICATION        (1)

/* To assert EIEN for ERU line */
#define ICU_ASSERT_EIEN                ((Icu_17_GtmCcu6_ActivationType)(8))

/* Number of bits to setup edge */
#define ICU_ERU_EDGE_BITS              (2)

/* Number of bits to setup edge and enable REN */
#define ICU_ERU_EDGEREN_BITS           (4)

/* Bit Positions in Icu_GlbIndexStatus */
/*Position 0 
  Used to provide information on channel status when 
  Icu_17_GtmCcu6_GetInputState() called
*/
#define ICU_CHNL_STATUS_POS            (0U)
/* ICU_CHNL_STATUS_POS bit length */
#define ICU_CHNL_STATUS_BIT_LENGTH     (1U)
/*Position 1 */
#define ICU_CHNL_WAKEUP_CAPABLE_POS    (1U)

/* ICU_CHNL_WAKEUP_CAPABLE_POS bit length */
#define ICU_CHNL_WAKEUP_BIT_LENGTH     (1U)
/*Position 2
  Used to store the Activation asked for which kind of edges 
  RISING_EDGE/FALLING_EDGE/BOTH_EDGES. 
  No of bits :2
*/
#define ICU_CHNL_EDGE_POS              (2U)

/*
  Used to store the number of bits required for ICU_CHNL_EDGE_POS 
*/
#define ICU_CHNL_EDGE_BIT_LENGTH       (2U)
/* 
   Position 4
   Used to keep track on to know whether notification required or not.
*/
#define ICU_CHNL_NOTIF_PRESENCE_POS    (4U)
/* ICU_CHNL_NOTIF_PRESENCE_POS bit length */
#define ICU_CHNL_NOTIF_BIT_LENGTH      (1U)
/*
  Position 5
  Used for Edge Counting and Time Stamp, Signal measurement
*/
#define ICU_CHNL_ACTIVITY_STARTED_POS  (5U)

/* ICU_CHNL_ACTIVITY_STARTED_POS bit length */

#define ICU_CHNL_ACTIVITY_BIT_LENGTH   (1U)
/* bit 6 and bit 7 reserved */
/*
  Position 8
  Index Storage for run time channel index 
  No of bits: 8
*/
#define ICU_CHNL_INDEX_STORE_POS       (8U)

/*
  Index Storage length 
  No of bits: 8
*/
#define ICU_CHNL_INDEX_BIT_LENGTH      (8)
/*
  Position 16
  Indicates if Notification is cleared for an Edge Detection Channel 
  No of bits: 1
*/
#define ICU_CHNL_NOTIF_STATUS_POS       (16UL)

/*
  Indicates if Notification is cleared for an Edge Detection Channel 
  No of bits: 1
*/
#define ICU_CHNL_NOTIF_STATUS_BIT_LENGTH      (1)

/*
  Position 17
  Indicates if an edge detection Channel has been disabled 
  No of bits: 8
*/
#define ICU_CHNL_DISABLE_STAT_POS       (17UL)

/*
  Indicates if an edge detection Channel has been disabled 
  No of bits: 1
*/
#define ICU_CHNL_DISABLE_STAT_BIT_LENGTH      (1U)


/* To denote Activity has started */
#define ICU_ACTIVITY_STARTED           (1U)
/* ERU INTFx clear position */
#define ICU_ERU_FCSTART                ((uint32)16)
/* Maximum number of ICU Channels */
#define ICU_MAX_USAGE                  (0x7fU) /* 127 */
/* Status to indicate that ICU is initialized */
#define ICU_INITIALIZED                ((uint8)1)
/* Status to indicate that ICU is de-initailized */
#define ICU_DEINITIALIZED              ((uint8)0)

/* Number of edges required for Signal Measurement */
#define ICU_SIGNALMEASUREMENT_COUNTER  ((uint8)2)

/* Number of bits to clear to disable a ERU Line */

#define ICU_ERU_DISABLE_BIT_LENGTH     (12)

/* Total number of ERU lines */
#define ICU_ERU_LINES                  (8U)

/* Eru Exis Bit Length  */
#define ICU_ERU_EXIS_BIT_LENGTH        (3)

/* Bit length of IGP bit of IGCR  */
#define ICU_ERU_IGP_BIT_LENGTH        (2)
#define ICU_ERU_IGP_BIT_MASK        (3UL)

/* Bit length of IGP bit of IGCR  */
#define ICU_ERU_IGP_BIT_VALUE        (1)

/* Eru Fen Bit Length  */
#define ICU_ERU_FEN_BIT_LENGTH         (2)

/* Max Signal measurement channels position in MaxChannels array */
#define ICU_MAX_SIGNALMEASUREMENT_POS  (3U)   

/* Max Edge count channels position in MaxChannels array */

#define ICU_MAX_EDGECOUNTCHNL_POS      (2U)

/* TIM Modes */
#if (ICU_TIM_SIGMEAS_USED == STD_ON)
#define ICU_GTM_TIM_MODE_TIPM  3UL
#endif
/* #if (ICU_TIM_SIGMEAS_USED == STD_ON) */
#define ICU_GTM_TIM_MODE_TIEM  2UL

#define ICU_GTM_TIM_CLOCKDIV_POS  24U

/*
Macro:ICU_GETMAXSIGMEASQMCHANNELS
Macro that returns the Signal Measurement channels
used in configuration.
Input Parameters:
None
*/
#define ICU_GETMAXSIGMEASQMCHANNELS \
                 ((Icu_17_GtmCcu6_ChannelType) \
                 Icu_kConfigPtr->MaxQmChannels[ICU_MAX_SIGNALMEASUREMENT_POS])
                 
#define ICU_GETMAXSIGMEASASILCHANNELS \
                  (((Icu_17_GtmCcu6_ChannelType) \
                 Icu_kConfigPtr->MaxAsilGtmChannels[ICU_MAX_SIGNALMEASUREMENT_POS]) + \
                 ((Icu_17_GtmCcu6_ChannelType) \
                 Icu_kConfigPtr->MaxAsilCcu6Channels[ICU_MAX_SIGNALMEASUREMENT_POS]))
                 
#define ICU_GETMAXSIGMEASASILGTMCHANNELS \
                 ((Icu_17_GtmCcu6_ChannelType) \
                 Icu_kConfigPtr->MaxAsilGtmChannels[ICU_MAX_SIGNALMEASUREMENT_POS])   

#define ICU_GETMAXSIGMEASASILCCU6CHANNELS \
                 ((Icu_17_GtmCcu6_ChannelType) \
                 Icu_kConfigPtr->MaxAsilCcu6Channels[ICU_MAX_SIGNALMEASUREMENT_POS])                   
/*
Macro:ICU_GETMAXTIMSTMPQMCHANNELS
Macro that returns the time Stamp channels
used in configuration.
Input Parameters:
None
*/
#define ICU_GETMAXTIMSTMPQMCHANNELS \
                 ((Icu_17_GtmCcu6_ChannelType)Icu_kConfigPtr->MaxQmChannels[1])

#define ICU_GETMAXTIMSTMPASILGTMCHANNELS \
                  (((Icu_17_GtmCcu6_ChannelType) \
                 Icu_kConfigPtr->MaxAsilGtmChannels[1]))
/*
Macro:ICU_GETMAXEDGECNTQMCHANNELS
Macro that returns the count of EdgeCount channels
used in configuration.
Input Parameters:
None
*/
#define ICU_GETMAXEDGECNTQMCHANNELS ((Icu_17_GtmCcu6_ChannelType)     \
                Icu_kConfigPtr->MaxQmChannels[ICU_MAX_EDGECOUNTCHNL_POS])
        
#define ICU_GETMAXEDGECNTASILGTMCHANNELS ((Icu_17_GtmCcu6_ChannelType)     \
                  Icu_kConfigPtr->MaxAsilGtmChannels[ICU_MAX_EDGECOUNTCHNL_POS])


                 
                
              
/*
Macro:ICU_GETMAXSIGEDGEQMCHANNELS
Macro that returns the count of SigEdge channels
used in configuration.
Input Parameters:
None
*/
#define ICU_GETMAXSIGEDGEQMCHANNELS                           \
            ((Icu_17_GtmCcu6_ChannelType)Icu_kConfigPtr->MaxQmChannels[0])

#define ICU_GETMAXSIGEDGEASILCHANNELS                           \
                  (((Icu_17_GtmCcu6_ChannelType) \
                 Icu_kConfigPtr->MaxAsilGtmChannels[0]) + \
                 ((Icu_17_GtmCcu6_ChannelType) \
                 Icu_kConfigPtr->MaxAsilCcu6Channels[0]))                 

/* TIM Interrupt Flag */
#define ICU_GTM_TIM_NEWVAL_IRQ  (0U)

/* TIM Enable */
#define ICU_GTM_TIM_ENABLE_CHANNEL ((uint32_t)1UL)

/* FEN bit position in EICR register */
#define ICU_ERU_FEN_0_POS (8UL)
#define ICU_ERU_FEN_1_POS (24UL)

/* Position of Mode information in Irq Variable */
#define ICU_GTM_MODE_MASK  (0xC0U)
#define ICU_GTM_MODE_TO_LSB (6)

/* EXIS0 Position in EICR register */
#define ICU_ERU_EXIS0_POS  (4UL)
#define ICU_ERU_EXIS1_POS  (20UL)

/* IGPx Position in IGCR register */
#define ICU_ERU_IGP0_POS  (14UL)

#define ICU_THREE_U  (3U)
#define ICU_TWO_U    (2U)
#define ICU_TWO_UL (2UL)
#define ICU_THREE_UL  (3UL)

#define ICU_SET_BIT (1UL)
#define ICU_SRC_SRE_POS (10U)
#define ICU_TIM_CTRL_DSL_POS (13)

#if (ICU_TIM_SIGMEAS_USED == STD_ON)
#define ICU_TIM_CTRL_GPR0SELBIT1_POS (9)
#define ICU_TIM_CTRL_GPR0SEL_POS  (8)
#define ICU_TIM_CTRL_GPR1SEL_POS  (10)
#define ICU_TIM_IRQ_ECNT_MASK (2UL)
#define ICU_TIM_GET_LOWER_16BITS (0x0000FFFFUL)
#define ICU_TIM_GET_LOWER_NIBBLE_U   (0x0FU)
#define ICU_TIM_GET_UPPER_NIBBLE_U   (0xF0U)
#define ICU_TIM_GET_LOWER_NIBBLE_UL  (0x0FUL)
#define ICU_TIM_EDGE_COUNT_INFO (0xFF000000UL)
/* amount of Shift needed to bring 1 byte info of a 32 bit number to LSB */
#define ICU_BRING_TO_LSB_32     (24U)
#define ICU_BIT_4_MASK (0x10U)
#define ICU_BITS_PER_CHANNEL (2U)

#endif


/* For GTM lower layer functions */
#define ICU_GTM_BITS_IN_U32 (32U) 





/* Write 1 to the Notify bits to clear the Interrupts */
#define ICU_GTM_CLEAR_INTERRUPTS (0x3fUL)

/* To get CCU kernal and channel number */
#define ICU_CCU_GET_LOWER_NIBBLE (0x0FU)
#define ICU_CCU_GET_UPPER_NIBBLE (0xF0U)

/* Defines for CCU handling */
#define ICU_CCU_INP_BITS_PER_CHANNEL (2U)
#define ICU_CCU_CAPTURE_MODE1 (4UL)
#define ICU_CCU_CAPTURE_MODE2 (5UL)
#define ICU_CCU_CAPTURE_MODE3 (6UL)
#define ICU_CCU_MSEL_BITS_PER_CHANNEL (4U)
#define ICU_CCU_PISEL_BITS_PER_CHANNEL (2U)
#define ICU_CCU_MSEL_RESET_VAL (0xFUL)
#define ICU_CCU_TCTR0_RESET_VAL (~(0xFUL))
#define ICU_CCU_CLEAR_INTERRUPT (3UL)
#define ICU_CCU_IS_BITS_PER_CHANNEL (2U)
#define ICU_CCU_RISING_EDGE (1U)
#define ICU_CCU_FALLING_EDGE (2U)
#define ICU_CCU_BOTH_EDGES (3U)
#define ICU_CCU_INTERRUPT_FLAG (3UL)
#define ICU_BRING_TO_BIT_0 (4U)
#define ICU_CCU6_MAX_T12_TIMER_VAL (0xFFFFUL)
#define ICU_LOWER_NIBBLE (0xFU)
#define ICU_CCU_T12_MAX_VAL (0xFFFFUL)
#define ICU_CC_NOT_USED (0xFFU)
#define ICU_CCU_SLEEP_REQD (1UL << 4)
#define ICU_CCU_PISEL_RESET_VAL (3UL)
#define ICU_CCU_INP_SR0 (3UL)

/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/

/* #if ((ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) && \
     (ICU_TIM_SIGMEAS_USED == STD_ON)) */
 
/* [cover parentID=DS_MCAL_SWSC_ICU_0003] */ 
/* --------------------------------------------------------------
  Icu_17_GtmCcu6_AsilGtmType
   -------------------------------------------------------------- */
#if (ICU_SAFETY_ENABLE == STD_ON)
 #if(ICU_MAX_ASIL_GTM_CHANNELS != 0U)
typedef struct Icu_17_GtmCcu6_AsilGtmType
{
  uint32 GlbIndexStatus[ICU_MAX_ASIL_GTM_CHANNELS];

#if ((ICU_ASIL_TIM_SIGMEAS_USED == STD_ON) && \
     (ICU_GET_INPUT_STATE_API == STD_ON))
  uint16 GtmEdgeCountForInputState[GTM_NO_OF_TIM_MODULES]; 
#endif

#if ((ICU_ASIL_TIM_SIGMEAS_USED == STD_ON) && \
     (ICU_GET_TIME_ELAPSED_API == STD_ON))
  uint16 GtmEdgeCountForTimeElapsed[GTM_NO_OF_TIM_MODULES];
#endif

 #if (ICU_TIMESTAMP_API == STD_ON)
 #if (ICU_MAX_TIMESTAMP_ASIL_CHANNELS != 0U) 
  Icu_TimeCaptureParasType TimeStampParas[ICU_MAX_TIMESTAMP_ASIL_CHANNELS];
#endif
#endif

#if ((ICU_EDGE_COUNT_API == STD_ON))
 #if (ICU_MAX_EDGE_COUNT_ASIL_CHANNELS != 0U) 
  uint32 EdgeCountValuePtr[ICU_MAX_EDGE_COUNT_ASIL_CHANNELS]; 
#endif
#endif

 #if (ICU_MAX_SIGNAL_MEASURE_ASIL_GTM_CHANNELS != 0U)  
#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) || \
     (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))   
  Icu_SigMeasurementParasType 
     MeasurementParas[ICU_MAX_SIGNAL_MEASURE_ASIL_GTM_CHANNELS];
#endif


#if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)
#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) || \
     (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))  
  uint8 InfoPtr[ICU_MAX_SIGNAL_MEASURE_ASIL_GTM_CHANNELS];
#endif
#if (ICU_GET_TIME_ELAPSED_API == STD_ON) 
  uint8 InfoPtrForTimeElapsed[ICU_MAX_SIGNAL_MEASURE_ASIL_GTM_CHANNELS];  
#endif
#endif
#endif

}Icu_17_GtmCcu6_AsilGtmType;
#endif  
/* [/cover]  */

/* [cover parentID=DS_MCAL_SWSC_ICU_0004] */ 
/* --------------------------------------------------------------
  Icu_17_GtmCcu6_AsilCcu6Type
   -------------------------------------------------------------- */
 #if(ICU_MAX_ASIL_CCU6_CHANNELS != 0U)   
typedef struct Icu_17_GtmCcu6_AsilCcu6Type
{
  uint32 GlbIndexStatus[ICU_MAX_ASIL_CCU6_CHANNELS];

#if (ICU_MAX_SIGNAL_MEASURE_ASIL_CCU6_CHANNELS != 0U)   
#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) || \
     (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))   
  Icu_SigMeasurementParasType 
        MeasurementParas[ICU_MAX_SIGNAL_MEASURE_ASIL_CCU6_CHANNELS];
#endif
#endif

#if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)  
  Icu_17_GtmCcu6_ValueType 
      CcuActiveTime[ICU_NO_OF_CCU6_MODULES][ICU_NO_OF_CCU6_CHANNELS];
  Icu_17_GtmCcu6_ValueType 
       CcuPeriodTime[ICU_NO_OF_CCU6_MODULES][ICU_NO_OF_CCU6_CHANNELS];
  uint16 CcuRRegVal[ICU_NO_OF_CCU6_MODULES][ICU_NO_OF_CCU6_CHANNELS];
  uint16 CcuSrRegVal[ICU_NO_OF_CCU6_MODULES][ICU_NO_OF_CCU6_CHANNELS];
#endif  
}Icu_17_GtmCcu6_AsilCcu6Type;
#endif  
#endif
/* [/cover]  */


/* [cover parentID=DS_MCAL_SWSC_ICU_0002] */ 
/* --------------------------------------------------------------
  Icu_17_GtmCcu6_QmType
   -------------------------------------------------------------- */
 #if(ICU_MAX_QM_CHANNELS != 0U)   
typedef struct Icu_17_GtmCcu6_QmType
{
  uint32 GlbIndexStatus[ICU_MAX_QM_CHANNELS];

#if (ICU_MAX_SIGNAL_MEASURE_QM_CHANNELS != 0U) 

#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) || \
     (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)) 
  Icu_SigMeasurementParasType 
        MeasurementParas[ICU_MAX_SIGNAL_MEASURE_QM_CHANNELS]; 
#endif

#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) || \
     (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))  
  uint8 InfoPtr[ICU_MAX_SIGNAL_MEASURE_QM_CHANNELS];
#endif
#if (ICU_GET_TIME_ELAPSED_API == STD_ON) 
  uint8 InfoPtrForTimeElapsed[ICU_MAX_SIGNAL_MEASURE_QM_CHANNELS];  
#endif

#endif

 #if (ICU_TIMESTAMP_API == STD_ON)
 #if(ICU_MAX_TIMESTAMP_QM_CHANNELS != 0U)
  Icu_TimeCaptureParasType TimeStampParas[ICU_MAX_TIMESTAMP_QM_CHANNELS];
#endif
#endif

#if ((ICU_EDGE_COUNT_API == STD_ON))
 #if(ICU_MAX_EDGE_COUNT_QM_CHANNELS != 0U)
  uint32 EdgeCountValuePtr[ICU_MAX_EDGE_COUNT_QM_CHANNELS]; 
#endif
#endif


#if (ICU_QM_TIM_SIGMEAS_USED == STD_ON) && (ICU_GET_TIME_ELAPSED_API == STD_ON)
  uint16 GtmEdgeCountForTimeElapsed[GTM_NO_OF_TIM_MODULES];
#endif

#if (ICU_QM_TIM_SIGMEAS_USED == STD_ON) && (ICU_GET_INPUT_STATE_API == STD_ON)
  uint16 GtmEdgeCountForInputState[GTM_NO_OF_TIM_MODULES]; 
#endif

#if (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)  
  Icu_17_GtmCcu6_ValueType 
            CcuActiveTime[ICU_NO_OF_CCU6_MODULES][ICU_NO_OF_CCU6_CHANNELS];
  Icu_17_GtmCcu6_ValueType 
            CcuPeriodTime[ICU_NO_OF_CCU6_MODULES][ICU_NO_OF_CCU6_CHANNELS];
  uint16 CcuRRegVal[ICU_NO_OF_CCU6_MODULES][ICU_NO_OF_CCU6_CHANNELS];
  uint16 CcuSrRegVal[ICU_NO_OF_CCU6_MODULES][ICU_NO_OF_CCU6_CHANNELS];
#endif  

}Icu_17_GtmCcu6_QmType;
#endif 
/* [/cover]  */

#if ( ICU_SAFETY_ENABLE == STD_ON) 

#if (ICU_MAX_ASIL_GTM_CHANNELS != 0U) 
extern Icu_17_GtmCcu6_AsilGtmType Icu_17_GtmCcu6_AsilGtmVarlist;
#endif
#if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U) 
extern  Icu_17_GtmCcu6_AsilCcu6Type Icu_17_GtmCcu6_AsilCcu6Varlist;
 #endif 
#if (ICU_MAX_QM_CHANNELS != 0U) 
extern Icu_17_GtmCcu6_QmType Icu_17_GtmCcu6_QmVarlist;
#endif
                                   
#else
extern Icu_17_GtmCcu6_QmType Icu_17_GtmCcu6_QmVarlist;

#endif


#if (ICU_CCU6_USED == STD_ON)
extern Icu_17_GtmCcu6_ChannelType 
       Icu_17_CcuChannelMap[ICU_NO_OF_CCU6_MODULES][ICU_NO_OF_CCU6_CHANNELS];
#endif


/* [cover parentID=DS_MCAL_SWSC_ICU_0005] */
/* To store the information on Mode of ICU */
extern Icu_17_GtmCcu6_ModeType Icu_17_GtmCcu6_GlobMode; 
/* [/cover]  */
/* Init Status Variable. It has to be initialized to "0" 
                  after every reset as 0 represents the initialized state */
extern uint8 Icu_17_GtmCcu6_InitStatus;

/*End of #if (ICU_DEBUG_SUPPORT == STD_ON)*/



#ifndef VALEO_PATCH_MCAL_ICU_MOVE_DECLARATION

#define ICU_17_GTMCCU6_START_SEC_VAR_32BIT
#include "MemMap.h"


#if (ICU_PB_FIXEDADDR == STD_OFF)
/* To store the ICU driver configuration pointer */
extern const Icu_17_GtmCcu6_ConfigType *Icu_kConfigPtr;
#endif
/*(ICU_PB_FIXEDADDR == STD_OFF)*/

#define ICU_17_GTMCCU6_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#define ICU_17_GTMCCU6_START_SEC_CONST_32BIT

#include "MemMap.h"

#if (ICU_PB_FIXEDADDR == STD_ON)
/* Variable Holds the Configuration Pointer given in Icu_17_GtmCcu6_Init */
extern const Icu_17_GtmCcu6_ConfigType* const Icu_kConfigPtr;
#endif
/*(ICU_PB_FIXEDADDR == STD_ON)*/


#define ICU_17_GTMCCU6_STOP_SEC_CONST_32BIT
#include "MemMap.h" 

#endif  /* VALEO_PATCH_MCAL_ICU_MOVE_DECLARATION */

#define ICU_17_GTMCCU6_START_SEC_CODE
#include "MemMap.h"
extern Icu_17_GtmCcu6_ChannelType Icu_lGetEruEicr(  \
                                          Icu_17_GtmCcu6_ChannelType CellUsed);

extern Icu_17_GtmCcu6_ChannelType Icu_lGetEruEicrChannel(  \
                                      Icu_17_GtmCcu6_ChannelType CellUsed);
                                      
/* Used for ERU Cells */
extern void Icu_lSetEruEdgeEien(
  Icu_17_GtmCcu6_ActivationType Edge, 
  Icu_17_GtmCcu6_ChannelType EruEicrUsed,
  Icu_17_GtmCcu6_ChannelType EruEicrChannel);
  
extern void Icu_lSetEruIgp( Icu_17_GtmCcu6_ChannelType EruIgcrUsed);                                      


_IFXEXTERN_ _INLINE_ Icu_17_GtmCcu6_ChannelType Icu_lGetEruInputLineUsed(
                                      Icu_17_GtmCcu6_ChannelType CellUsed); 

_IFXEXTERN_ _INLINE_ uint32 Icu_lGetEruExisPos(uint32 EruEicrChannel);

_IFXEXTERN_ _INLINE_ void Icu_lSetEruExis(
                               Icu_17_GtmCcu6_ChannelType EruInputLineUsed, 
                               Icu_17_GtmCcu6_ChannelType EruEicrUsed, 
                               Icu_17_GtmCcu6_ChannelType EruEicrChannel);
                                 
_IFXEXTERN_ _INLINE_ uint32 Icu_lGetErulinePos(uint32 LineNum);                         

_IFXEXTERN_ _INLINE_ volatile uint32_t* Icu_lGetEruAddress(
                                   Icu_17_GtmCcu6_ChannelType EicrNumber);
                                  
#ifdef VALEO_PATCH_MCAL_ICU_FIX_ETXERN_INLINE
LOCAL_INLINE uint8 Icu_17_lGlbIndexStatusExtract 
               (Icu_17_GtmCcu6_ChannelType Channel, uint8 ChlIndex, 
               uint8 ChlLength);
#else
_IFXEXTERN_ _INLINE_ uint8 Icu_17_lGlbIndexStatusExtract 
               (Icu_17_GtmCcu6_ChannelType Channel, uint8 ChlIndex, 
               uint8 ChlLength);
#endif /* VALEO_PATCH_MCAL_ICU_FIX_ETXERN_INLINE */

_IFXEXTERN_ _INLINE_ uint8 Icu_lGtmGetIrqMode8(uint8 Word);

#if (ICU_INITCHECK_API == STD_ON)
#if ((ICU_TIM_SIGEDGE_USED == STD_ON) &&(ICU_EDGE_DETECT_API == STD_ON))
 _IFXEXTERN_ _INLINE_ uint32 Icu_lGtmStartEdgeDetectCheck(
            Icu_17_GlobalChannelNumberType GlobalChannelNumber, 
            uint8 ActiveEdge);      
#endif
#endif

/* Used to extract Irq Mode information from the configuration */
_IFXEXTERN_ _INLINE_ uint8 Icu_lGtmGetIrqMode8(uint8 Word)
{
  return((uint8)((Word & ICU_GTM_MODE_MASK) >> ICU_GTM_MODE_TO_LSB));
}

_IFXEXTERN_ _INLINE_ uint8 Icu_lGetGtmModuleNo
                     (Icu_17_GtmCcu6_ChannelIdentifierType ChannelId);

_IFXEXTERN_  _INLINE_ uint8 Icu_lCcu6GetActiveEdge
                        (Icu_17_GtmCcu6_ActivationType ActiveEdge);

_IFXEXTERN_ _INLINE_ uint8 Icu_lGetChannelType
                                (Icu_17_GtmCcu6_ChannelType Channel);
                                
#if (ICU_CCU6_USED == STD_ON)
_IFXEXTERN_ _INLINE_ Ifx_CCU6* Icu_lCcuGetBaseAddress(uint8 CellUsed);
#endif

#if (ICU_CCU6_USED == STD_ON)
/*******************************************************************************
** Syntax : _IFXEXTERN_ Ifx_CCU6* Icu_lCcuGetBaseAddress(uint8 CellUsed)      **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CellUsed - Provides the CCU6 kernal and channel info     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     Ccu6RegPtr - Base address for the kernal                 **
**                                                                            **
** Description :     Function to get the base address of CCU6x kernal         **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ Ifx_CCU6* Icu_lCcuGetBaseAddress(uint8 CellUsed)
{
  volatile Ifx_CCU6 *Ccu6BaseRegPtr;/* Variable to hold the CCU6 base address */
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  uint8 CcuKernalNumber;    /* To hold CCU Kernal Number */


  /* Assign the base address to CCU60 base address */
  Ccu6BaseRegPtr = &MODULE_CCU60;

  /* Lower Nibble of AssignedHwUnitNumber holds the Kernal Number */
  CcuKernalNumber = CellUsed & ICU_CCU_GET_LOWER_NIBBLE;

  /* Get the base address of the Kernal */
  Ccu6RegPtr = Ccu6BaseRegPtr + CcuKernalNumber;

  /* return the base address */
  return(Ccu6RegPtr);
  
}
#endif

/*******************************************************************************
** Syntax : _IFXEXTERN_ uint8 Icu_lCcu6GetActiveEdge(                         **
**                                   Icu_17_GtmCcu6_ActivationType ActiveEdge)**
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ActiveEdge - Configured Activation edge for the channel  **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     RetVal - Activation Edge corresponding to CCU6x Hardware **
**                                                                            **
** Description :     Function to get the Active Edge equivalent for CCU6x     **
**                   hardware                                                 **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint8 Icu_lCcu6GetActiveEdge
                                     (Icu_17_GtmCcu6_ActivationType ActiveEdge)
{
  uint8 RetVal;  /* Equivalent edge value in CCU6 convention */
  
  switch(ActiveEdge)
  {
    /* Convert the Activation edge in the form suited for CCU */
    case ICU_RISING_EDGE:
      RetVal = ICU_CCU_RISING_EDGE;
      break;
    case ICU_FALLING_EDGE:
      RetVal = ICU_CCU_FALLING_EDGE;
      break;
    default: /*Default case Edge Type ICU_BOTH_EDGES */
      RetVal = ICU_CCU_BOTH_EDGES;
  }
  return (RetVal);

}

#if (ICU_GTM_TIM_USED == STD_ON)
Icu_17_GtmCcu6_ChannelIdentifierType 
    Icu_lGtmChannelIdentifier(Gtm_GlobalChannelNumberType GlobalChannelNumber);
#endif  

#if ((ICU_TIM_SIGEDGE_USED == STD_ON) &&(ICU_EDGE_DETECT_API == STD_ON))
/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU365]
** Syntax : _IFXEXTERN_ void Icu_lGtmStartEdgeDetect(                         **
**                           Gtm_GlobalChannelNumberType GlobalChannelNumber, **
**                           uint8 ActiveEdge)                                **
**                                                                            **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   ActiveEdge - Edge that need to be detected               **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to configure TIM Channel given by               **
**                   GlobalChannelNumber to scan the input for the Active edge**
**                   given by the input parameter "ActiveEdge". This function **
**                   should be called with a disabled TIM Channel             **
**                                                                            **
*******************************************************************************/
 _IFXEXTERN_ _INLINE_ uint32 Icu_lGtmStartEdgeDetectCheck
                               (Icu_17_GlobalChannelNumberType GlobalChannelNumber,
                                uint8 ActiveEdge)
{
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; /* Structure to get Module info  */
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  volatile uint32 CompareFlag;
  CompareFlag = 0xFFFFFFFFU;

  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  /* Get the pointer to TIM Channel Register Structure */
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).CH_TIM[ModuleNo]
                     .CH[GlobalChannelId.ChannelNo]);
  
  /* Clear all Pending Interrupts */
 /* TempFlag = (uint32)TimChannelRegPtr->CH_IRQ_NOTIFY.U;
  CompareFlag &= (TempFlag ^ ~(uint32)ICU_GTM_CLEAR_INTERRUPTS); */

  /* Clear the previous Edge Value */
 /* TempFlag = ~(uint32)TimChannelRegPtr->CH_CTRL.U;
  TempFlag1 = ICU_GTM_TIM_ENABLE_CHANNEL | (ActiveEdge << ICU_TIM_CTRL_DSL_POS);
  CompareFlag &= (TempFlag ^ TempFlag1); */
 UNUSED_PARAMETER(ActiveEdge)
 
  if (TimChannelRegPtr->CH_CTRL.B.TIM_EN != ICU_GTM_TIM_ENABLE_CHANNEL)
  {
    CompareFlag = 0U;
  }
  else
  {
   CompareFlag = 0xFFFFFFFFU;  
  }
  return(CompareFlag);
}
#endif


#if (ICU_GTM_TIM_USED == STD_ON)
/******************************************************************************
** Syntax :          _INLINE_ _INLINE_ uint8 Icu_lGetGtmModuleNo             **
**                                (                                          **
**                       Icu_17_GtmCcu6_ChannelIdentifierType ChannelId      **
**                                )                                          **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ChannelId : GTM Global Channel Number                  **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :To derive the TIM Module number        **
**                                                                           **
*****************************************************************************/
_IFXEXTERN_ _INLINE_ uint8 
      Icu_lGetGtmModuleNo(Icu_17_GtmCcu6_ChannelIdentifierType ChannelId)
{
  return((ChannelId.ModuleId & GTM_MODULE_NO_MSK) >> GTM_MODULE_NO_POS);
}
#endif


/******************************************************************************
** Syntax :                  _INLINE_ uint8 Icu_17_lGlbIndexStatusExtract    **
**                                (Icu_17_GtmCcu6_ChannelType   Channel      **
**                                 uint8 ChlIndex, uint8 ChlLength           **
**                                )                                          **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   none                                                   **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :To extract the GlbIndexStatus value    **
**                                                                           **
*****************************************************************************/
#ifdef VALEO_PATCH_MCAL_ICU_FIX_ETXERN_INLINE
LOCAL_INLINE uint8 Icu_17_lGlbIndexStatusExtract (Icu_17_GtmCcu6_ChannelType 
                             Channel, uint8 ChlIndex, uint8 ChlLength)
#else
_IFXEXTERN_ _INLINE_ uint8 Icu_17_lGlbIndexStatusExtract 
         (Icu_17_GtmCcu6_ChannelType Channel, uint8 ChlIndex, uint8 ChlLength)
#endif /* VALEO_PATCH_MCAL_ICU_FIX_ETXERN_INLINE */
{
   uint8 ChIndexValue; 
   const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; 
   uint32 Hwused; 
   uint8 PhyChannelIndex;
  /* Get the channel config pointer */
    const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;
  #if ((ICU_MAX_ASIL_GTM_CHANNELS != 0U) || (ICU_MAX_ASIL_CCU6_CHANNELS != 0U) \
      || (ICU_MAX_QM_CHANNELS != 0U))    
  uint32 *Ptr = NULL_PTR; 
  #endif      
    LocalIcuMapPtr =   (Icu_kConfigPtr->MappingIndexPtr) + Channel;
    PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap;
   /* Ptr = NULL_PTR; */

    /* ChIndexValue = 0U; */
    LocalIcuChanPtr = Icu_kConfigPtr->ChannelConfigPtr + Channel; 
    Hwused = (uint32)LocalIcuChanPtr->IcuProperties.AssignedHwUnit;


  if((LocalIcuChanPtr->IcuProperties.SignalType == ICU_ASIL_SIGNAL)&& 
      (Hwused == ICU_GTM_OPTION)) 
  {  
     #if (ICU_MAX_ASIL_GTM_CHANNELS != 0U)     
      Ptr = &Icu_17_GtmCcu6_AsilGtmVarlist.GlbIndexStatus[PhyChannelIndex];
    #endif   
    }
   else if((LocalIcuChanPtr->IcuProperties.SignalType == ICU_ASIL_SIGNAL)&& 
           (Hwused == ICU_CCU_OPTION)) 
  {  
      #if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)   
      Ptr = &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[PhyChannelIndex];      
     #endif                  
    }
   else       
  {  
      #if (ICU_MAX_QM_CHANNELS != 0U)    
      Ptr = &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex]; 
      #endif            
    }
    
    switch (ChlLength)
    {
        case 2:
  #if ((ICU_MAX_ASIL_GTM_CHANNELS != 0U) || (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)\
      || (ICU_MAX_QM_CHANNELS != 0U))          
          ChIndexValue  =  (uint8)Mcal_Extract( *Ptr,
                                   ChlIndex,
                                   2U); 
  #endif                                     
          break;
        default: 
  #if ((ICU_MAX_ASIL_GTM_CHANNELS != 0U) || (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)\
      || (ICU_MAX_QM_CHANNELS != 0U))         
         ChIndexValue  =  (uint8)Mcal_Extract( *Ptr,
                                   ChlIndex,
                                   1U);         
          break;
  #endif             
     }          
  return(ChIndexValue);
}


/******************************************************************************
** Syntax :     _IFXEXTERN_  _INLINE_ uint8 Icu_lGetChannelType              **
**                                (Icu_17_GtmCcu6_ChannelType   Channel)     **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   none                                                   **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :To derive the ICU channel type         **
**                                                                           **
*****************************************************************************/
_IFXEXTERN_ _INLINE_ uint8 Icu_lGetChannelType
                                (Icu_17_GtmCcu6_ChannelType Channel)
{
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr;
  uint32 Hwused;
  uint8 ReturnValue;
  /* Get the channel config pointer */
  LocalIcuChanPtr = Icu_kConfigPtr->ChannelConfigPtr + Channel; 
  Hwused = (uint32)LocalIcuChanPtr->IcuProperties.AssignedHwUnit; 
  ReturnValue = ICU_ERU_QM_CHANNEL;

  if(LocalIcuChanPtr->IcuProperties.SignalType == ICU_ASIL_SIGNAL)
  {
    /* signal is ASIL */
    if(Hwused == ICU_GTM_OPTION)
    {
      ReturnValue = ICU_GTM_ASIL_CHANNEL;
    }
    else
    {
      ReturnValue = ICU_CCU6_ASIL_CHANNEL;
    }
  }
  else   
  {
    /* signal is QM */
    if (Hwused == ICU_GTM_OPTION)
    {
      ReturnValue = ICU_GTM_QM_CHANNEL;
    }
    else if (Hwused == ICU_CCU_OPTION)
    {
      ReturnValue = ICU_CCU6_QM_CHANNEL;
    }
    else
    {
    }
  }
  return (ReturnValue);
}

#define ICU_17_GTMCCU6_STOP_SEC_CODE
#include "MemMap.h"

#endif

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
**  $FILENAME   : Icu_17_GtmCcu6.c $                                         **
**                                                                           **
**  $CC VERSION : \main\132 $                                                **
**                                                                           **
**  $DATE       : 2014-02-04 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                 - functionality of ICU driver.                            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                     **
**                                                                           **
******************************************************************************/
/******************************************************************************
**                      Includes                                              *
******************************************************************************/
/*  TRACEABILITY: [cover parentID= DS_AS_ICU213_1,DS_NAS_PR228,
    DS_NAS_PR912_1,DS_NAS_PR912_2,DS_NAS_PR912_3,
    DS_NAS_PR624_PR759_PR760_PR761,DS_AS40X_ICU005,DS_AS_ICU060,
    SAS_AS_ICU219_ICU245_ICU247_ICU251_ICU254_ICU256_ICU115,DS_AS_ICU218]     
                   [/cover]                                                  */
/* Inclusion of sfr file */
#include "IfxSrc_reg.h"
#include "IfxScu_reg.h"
#include "IfxCcu6_reg.h"

/* Icu Module header file */

#include "Icu_17_GtmCcu6.h"
#include "Icu_17_GtmCcu6_Ver.h" 
#include "Icu_17_GtmCcu6_Local.h" 
/* Include SchM to import the critical section functions */
#include "SchM_17_McalCfg.h"
#include SCHM_ICU_17_GTMCCU6_HEADER

#if (ICU_SAFETY_ENABLE == STD_ON)
#include "SafetyReport.h"
#endif
/* Coding Guideline Violation */
/* 
Brackets are not used in case of Mcal_SetAtomic.
This is mainly due to the usage of inline assembly statement
for ldmst. Also the last parameter will not have U subscript
or any specific typecast, as the generated assembly statement
would not compile.
*/

/* MISRA Rule Violation 19.1,19.15,17.4,3.4: 
   a) Declaration before #include. Because of Memmap.h inclusion, this cannot
      be avoided.
   b) Header file 'MemMap.h' repeatedly included but does not have a standard 
      include guard. Memmap.h file is prepared according to Autosar rules and
      this cannot be avoided.
   c) pointer arithmetic other than array indexing used. this cannot be avoided.
   d) Unrecognized pragma 'section' will be ignored. Linker specific keywords.
   e) Unrecognized pragma 'align' will be ignored. Linker specific keywords.
*/


/******************************************************************************
**                      Imported Compiler Switch Check                        *
******************************************************************************/

/******************************************************************************
**                      Private Macro like functions                         **
******************************************************************************/

/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/

/******************************************************************************
**                      Private Function Declarations                        **
******************************************************************************/

static _INLINE_ void Icu_17_lGlbIndexStatusSet(Icu_17_GtmCcu6_ChannelType
                              Channel,uint8 Value, uint8 Offset, uint8 Bits);
                              
#if ((ICU_SAFETY_ENABLE == STD_ON) && (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON))
static void Icu_lSafeCheckMode(const Icu_17_GtmCcu6_ChannelConfigType* 
                                                 const IcuChannelPtr);
#endif

#if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
/* To check DET errors in Icu_17_GtmCcu6_DeInit API */
static _INLINE_ uint32 Icu_lDeInitDetCheck
(
  void
);
/* To verify Init has been called or not */
static _INLINE_ uint32 Icu_lInitCallVerify
(
  uint8 ServiceId
);
/* To verify passed channel number is correct or not */
static _INLINE_ uint32 Icu_lChannelVerify
(
  uint8 ServiceId, 
  Icu_17_GtmCcu6_ChannelType Channel
);
/* To verify passed channel is configured in the required mode */
static _INLINE_ uint32 Icu_lChannelCheckMode
( 
  uint8 ServiceId, 
  Icu_17_GtmCcu6_ChannelType Channel, 
  Icu_17_GtmCcu6_MeasurementModeType Mode
);

#if ((ICU_DISABLE_WAKEUP_API == STD_ON) || (ICU_ENABLE_WAKEUP_API == STD_ON))
/* To check DET errors in Icu_17_GtmCcu6_DisableWakeup API Or 
   Icu_17_GtmCcu6_EnableWakeup API*/
static uint32 Icu_lWakeupDetCheck
( 
  Icu_17_GtmCcu6_ChannelType Channel,
  uint8   ServiceId 

);
#endif

/* #if ((ICU_DISABLE_WAKEUP_API == STD_ON) || \
(ICU_ENABLE_WAKEUP_API == STD_ON)) */

/* Common service to check the DET check for Notification API's */
static uint32 Icu_lEnDisNotificationDetCheck
(
  Icu_17_GtmCcu6_ChannelType Channel,
  uint8 ServiceId 
);

#if ( (ICU_TIMESTAMP_API == STD_ON) || (ICU_EDGE_COUNT_API == STD_ON) ||\
    (ICU_SIGNAL_MEASUREMENT_API == STD_ON) || \
    (ICU_GET_TIME_ELAPSED_API == STD_ON) ||   \
    (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) || \
    (ICU_DISABLE_WAKEUP_API == STD_ON) ||\
    (ICU_ENABLE_WAKEUP_API == STD_ON) )
/* To check DET errors in Channels that are configured for one mode API */
static uint32 Icu_lNotifiDetCheck
( 
  Icu_17_GtmCcu6_ChannelType Channel, 
  uint8 ServiceId, 
  Icu_17_GtmCcu6_MeasurementModeType Mode
);
#endif


#if (ICU_GET_INPUT_STATE_API == STD_ON)
/* To check DET errors in Icu_17_GtmCcu6_GetInputState API */
static uint32 Icu_lGetInputStateDetCheck
(
  Icu_17_GtmCcu6_ChannelType Channel
);
#endif
/* For #if (ICU_GET_INPUT_STATE_API == STD_ON)*/
#endif
/*#if (ICU_DEV_ERROR_DETECT == STD_ON) */

static _INLINE_ void Icu_lChannelInit(void);


#if (ICU_ERU_USED == STD_ON)
/* To extract the Eru Line */
static _INLINE_ Icu_17_GtmCcu6_ChannelType Icu_lGetEruLine
(
  Icu_17_GtmCcu6_ChannelType CellUsed
);
/* Sets the edges on a ERU */
static _INLINE_ void Icu_lSetEruEdge
(
  Icu_17_GtmCcu6_ActivationType Edge, 
  Icu_17_GtmCcu6_ChannelType EruEicrUsed,
  Icu_17_GtmCcu6_ChannelType EruEicrChannel
);

/* Used while Deinitializing ERU cells */
static _INLINE_ void Icu_lDeInitEru
(
  Icu_17_GtmCcu6_ChannelType EruEicrUsed,
  Icu_17_GtmCcu6_ChannelType EruEicrChannel
);
#endif
/* #if (ICU_ERU_USED == STD_ON) */

#if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON) 
/* Service to check Icu_17_GtmCcu6_Init Det's */
static _INLINE_ uint32 Icu_lInitDetCheck
(
  const Icu_17_GtmCcu6_ConfigType *TempIcuConfigPtr
);
#endif


#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON) 
/* Process wakeup information */
static void Icu_lWakeup_Isr
(
  uint32 ChIndex  
);

#endif
/* #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */

#if (ICU_EDGE_NOTIF_USED == STD_ON)
/* Signal Edge Notification is handled within this sub routine */
static _INLINE_ void Icu_lSignalEdgeNotification_Isr
(
  uint32 ChIndex,
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr, 
  volatile uint32 *LocalGlobChanPtr 
);
#endif
/* #if (ICU_EDGE_NOTIF_USED == STD_ON) */

#if (ICU_SET_MODE_API == STD_ON) 
#if ((ICU_TIM_SIGEDGE_USED == STD_ON) || \
     (ICU_ERU_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON))
   
/* Service that Disable No wakeup capable channels */
static void Icu_lDisableForWakeup
(
  void
);
/* Service that bring back the channels to Normal after sleep */
static void Icu_lSetNormal
(
  void
);


/*
Deactivates the edges 
called from Icu_17_GtmCcu6_SetMode , 
Icu_17_GtmCcu6_StopTimestamp , Icu_17_GtmCcu6_DisableEdgeCount
*/
   
static void Icu_lDeactivateEdge
(
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr
);
#endif
#endif


/* #if ((ICU_SET_MODE_API == STD_ON) && ((ICU_TIM_SIGEDGE_USED == STD_ON) || \
     (ICU_ERU_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON))) */

/*
Resets all the required global variables 
called from Icu_17_GtmCcu6_Init
*/
static void Icu_lResetGlobalVariables
(
  void
);

#if (ICU_EDGE_DETECT_API == STD_ON) 
#if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
static uint32 Icu_lEnDisEdgeDetectDetCheck
(
  Icu_17_GtmCcu6_ChannelType Channel,
  uint8 ServiceId                                               
);
#endif
#endif

#if ((ICU_TIM_SIGMEAS_USED == STD_ON) || (ICU_CCU6_SIGMEAS_USED == STD_ON))
static _INLINE_ void Icu_lSigMesInit
(
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr,
  Icu_17_GtmCcu6_ChannelType Channel,
  uint32 DutyIndex
);
#endif


#if (ICU_TIM_TIMSTMP_USED == STD_ON)
static void Icu_lTimeStampBufferLimitCheck(
                     Icu_17_GtmCcu6_TimestampBufferType MeasureKind, 
                     Icu_17_GtmCcu6_ChannelType CellNum,
                     uint32 ChIndex,uint8 ChlType);


#endif

#if (ICU_ERU_USED == STD_ON)
/*Icu_lGetEruAddress
To extract EICR0/EICR1/EICR2 or EICR3 address depending on ERU line used 
EICR0_type Input Parameters:
EicrNumber: Eru Line
*/
/*Misra Violation: Misra rule 11.4 cast from pointer to pointer
  typecasting is done to make it compatiable with API return type*/
 _INLINE_ volatile uint32_t* Icu_lGetEruAddress(
                                   Icu_17_GtmCcu6_ChannelType EicrNumber)
{
  return(&(MODULE_SCU.EICR[EicrNumber].U));
}

/*Icu_lGetEruIgcrAddress
To extract IGCR0/IGCR1/IGCR2 or IGCR3 address depending on ERU line used 
EICR0_type Input Parameters:
IgcrNumber: Eru Line
*/
/*Misra Violation: Misra rule 11.4 cast from pointer to pointer
  typecasting is done to make it compatiable with API return type*/
static _INLINE_ volatile uint32_t* Icu_lGetEruIgcrAddress(
                                        Icu_17_GtmCcu6_ChannelType IgcrNumber)
{
  return(&(MODULE_SCU.IGCR[IgcrNumber].U));
}

/*
Icu_lGetEruFenPos
To extract position of FEN0 or FEN1 depending on ERU line used
Input Parameters:
LineNum: Eru Line
FEN bit Position is 8 for ERU Line 0 & 2 ,24 for 1 & 3 Lines.
*/ 
static _INLINE_ uint32 Icu_lGetEruFenPos(Icu_17_GtmCcu6_ChannelType LineNum)
{
  return((LineNum == 0U ) ? ICU_ERU_FEN_0_POS : ICU_ERU_FEN_1_POS );
}

/*
Icu_lDisableEruLine

To Disable an ERU Channel. This is done by making FEN and REN as 0 i.e. 
no edge detection.

Input Parameters:
EruEicrUsed: Used Eicr register
EruEicrChannel - EICR channel used
*/ 
static _INLINE_ void Icu_lDisableEruLine(
                                     Icu_17_GtmCcu6_ChannelType EruEicrUsed, 
                                     Icu_17_GtmCcu6_ChannelType EruEicrChannel)
{                                                            
 volatile uint32_t* Ptr;
 uint32 EruFenPos;
 
 Ptr = Icu_lGetEruAddress(EruEicrUsed);
 EruFenPos = Icu_lGetEruFenPos(EruEicrChannel);
 
 Mcal_SetAtomic( (sint32 *)(void *)Ptr,
                 (uint32)0U,
                 (sint32)EruFenPos,
                 (ICU_ERU_FEN_BIT_LENGTH)
                 );                                          
}/* end of function Icu_lDisableEruLine */
#endif

#if((ICU_GET_INPUT_STATE_API == STD_ON) && (ICU_EDGE_DETECT_API == STD_ON) && \
     (ICU_TIM_SIGEDGE_USED == STD_ON))
static Icu_17_GtmCcu6_InputStateType Icu_lGtmGetInputStateEdgeDetect(
                                     Icu_17_GtmCcu6_ChannelType CellUsed,
                                     Icu_17_GtmCcu6_ChannelType PhyChannelIndex,
                                     uint8 ChlType);
#endif
/*#if((ICU_GET_INPUT_STATE_API == STD_ON) && (ICU_EDGE_DETECT_API == STD_ON) &&\
     (ICU_TIM_SIGEDGE_USED == STD_ON))*/



#if (ICU_GTM_TIM_USED == STD_ON)

static _INLINE_ void Icu_lGtmIrqModify(
         Gtm_GlobalChannelNumberType GlobalChannelNumber, uint8 InterruptFlag);

#if ((ICU_TIM_SIGEDGE_USED == STD_ON) && (ICU_EDGE_DETECT_API == STD_ON))
static _INLINE_ void Icu_lGtmStartEdgeDetect(
            Gtm_GlobalChannelNumberType GlobalChannelNumber, uint8 ActiveEdge);

static _INLINE_ void Icu_lGtmStopEdgeDetect(
                               Gtm_GlobalChannelNumberType GlobalChannelNumber);

static _INLINE_ void Icu_lGtmEdgeDetectModeInit(
                       const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr,
                                   Icu_17_GtmCcu6_ChannelType CellUsed);

#endif


static _INLINE_ void Icu_lGtmChangeActiveEdge(
            Gtm_GlobalChannelNumberType GlobalChannelNumber, uint8 ActiveEdge);

static void Icu_lGtmChannelInit(void);


static _INLINE_ void Icu_lGtmClearIrqNotify(
                             Gtm_GlobalChannelNumberType GlobalChannelNumber);



#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) && (ICU_TIM_SIGMEAS_USED == STD_ON))
static Icu_17_GtmCcu6_ValueType Icu_lGtmGetTimeElapsed
                       (Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                       Icu_17_GtmCcu6_SignalMeasurementPropertyType SignalMode,
                       uint8 *InfoPtr,uint8 ChlType);


static uint8 Icu_lGtmGetTimeElapsedHighTime(uint32 CntsVal, 
                                            const uint8 *InfoPtr, 
                                            uint8 ModuleNo, 
                                            uint8 ChannelNo,uint8 ChlType);


static uint8 Icu_lGtmGetTimeElapsedLowTime(uint32 CntsVal, 
                                           const uint8 *InfoPtr, 
                                           uint8 ModuleNo, 
                                           uint8 ChannelNo,uint8 ChlType);


static uint32 Icu_lGtmGetTimeElapsedResult(uint32 CntsVal, uint8 CheckStatus);

#endif

/* #if ((ICU_GET_TIME_ELAPSED_API == STD_ON) && \
(ICU_TIM_SIGMEAS_USED == STD_ON)) */

#if ((ICU_TIM_SIGMEAS_USED == STD_ON) &&                   \
         ((ICU_GET_INPUT_STATE_API == STD_ON)||            \
         (ICU_GET_TIME_ELAPSED_API == STD_ON)))
static _INLINE_ void Icu_lGtmEdgeOvrflw(uint8 ChannelNumber, uint8 ModuleNo,
                                        uint8 ChlType);
#endif
      /*#if ((ICU_TIM_SIGMEAS_USED == STD_ON) && \
         ((ICU_GET_INPUT_STATE_API == STD_ON)|| \
         (ICU_GET_TIME_ELAPSED_API == STD_ON)))*/

#endif
/* #if (ICU_GTM_TIM_USED == STD_ON) */

#if (ICU_ERU_USED == STD_ON)

/* Inline function to clear the ERU Service request */
static _INLINE_ uint32_t Icu_lClearEruServiceRequest(                   \
                                      Icu_17_GtmCcu6_ChannelType LineNum)
{
  return(((uint32_t)1UL) << (LineNum + ICU_ERU_FCSTART));
}


/* To extract position of Esis depending on ERU line used 
EXIS bit Position is 4 for ERU Line 0 & 2 ,20 for 1 & 3 Lines.*/
_INLINE_ uint32 Icu_lGetEruExisPos(uint32 EruEicrChannel)
{
  return((EruEicrChannel == 0UL ) ? ICU_ERU_EXIS0_POS : ICU_ERU_EXIS1_POS);
}

/* To set EXIS bit for pin selection */
_INLINE_ void Icu_lSetEruExis(
                               Icu_17_GtmCcu6_ChannelType EruInputLineUsed, 
                               Icu_17_GtmCcu6_ChannelType EruEicrUsed, 
                               Icu_17_GtmCcu6_ChannelType EruEicrChannel)
{
  volatile uint32_t* Ptr;
  uint32 EruExisPos;
  
  Ptr = Icu_lGetEruAddress(EruEicrUsed);
  EruExisPos = Icu_lGetEruExisPos((uint32)EruEicrChannel);
  
  Mcal_SetAtomic( (sint32*)(void *)Ptr,                
                  (uint32)(EruInputLineUsed),                                
                  (sint32)(EruExisPos),        
                  ICU_ERU_EXIS_BIT_LENGTH);                    

}
/* To set IGPx bit of IGCRx register*/
void Icu_lSetEruIgp( Icu_17_GtmCcu6_ChannelType EruIgcrUsed)
{
  volatile uint32_t* Ptr;
  
  Ptr = Icu_lGetEruIgcrAddress(EruIgcrUsed);
  
  Mcal_SetAtomic( (sint32*)(void *)Ptr,                
                  (uint32)(ICU_ERU_IGP_BIT_VALUE),                              
                  (sint32)(ICU_ERU_IGP0_POS),        
                  ICU_ERU_IGP_BIT_LENGTH);                    

}


/* To know which ERU line used and retrieves bit position
ERU line bit Position is 4 for ERU Line 0 & 2 ,20 for 1 & 3 Lines.*/
_INLINE_ uint32 Icu_lGetErulinePos(uint32 LineNum)
{
  return((LineNum  == 0UL) ? ICU_ERU_EXIS0_POS : ICU_ERU_EXIS1_POS );
}



/* To know which EICR is used */
Icu_17_GtmCcu6_ChannelType Icu_lGetEruEicr(                 \
                                          Icu_17_GtmCcu6_ChannelType CellUsed)
{
  return((Icu_17_GtmCcu6_ChannelType)(CellUsed >> ICU_THREE_U));
}

/* To know which EICR is used */
Icu_17_GtmCcu6_ChannelType Icu_lGetEruEicrChannel(         \
                                      Icu_17_GtmCcu6_ChannelType CellUsed)
{
  return((Icu_17_GtmCcu6_ChannelType)((CellUsed >> ICU_TWO_U) & 1U));
}

/* Inline Function to know which EICR is used */
_INLINE_ Icu_17_GtmCcu6_ChannelType Icu_lGetEruInputLineUsed(
                                      Icu_17_GtmCcu6_ChannelType CellUsed)
{
  return((Icu_17_GtmCcu6_ChannelType)(CellUsed & ICU_THREE_U));
}


/* Inline function to know which EICR is used */
static _INLINE_ Icu_17_GtmCcu6_ChannelType Icu_lGetEruChannel(
                                       Icu_17_GtmCcu6_ChannelType CellUsed)
{
  return(CellUsed >> ICU_TWO_U);
}

#endif
/* #if (ICU_ERU_USED == STD_ON) */

#if ((ICU_ERU_USED == STD_ON) || (ICU_CCU6_USED == STD_ON))
/*
Icu_lSetInputStateActive
Set the input status of a channel to ICU_ACTIVE
Input Parameters:
ptr: pointer of RAM location
*/ 
/*
Set the Input State to Active
*/
/* MISRA Rule Violation 16.7:Pointer parameter 'ptr' could be declared
    as pointing to const. As Misra doesn't understand the functionlaity of 
    Mcal_SetAtomic(), 'ptr' can not be declared as pointing to const.
*/
static _INLINE_ void Icu_lSetInputStateActive(volatile uint32* ptr)
{
  Mcal_SetAtomic((sint32*)(void *)(ptr),
                 (uint32)ICU_ACTIVE,
                  ICU_CHNL_STATUS_POS,
                  1);
}

#endif
/* #if ((ICU_ERU_USED == STD_ON) || (ICU_CCU_USED == STD_ON)) */
 



/*
Icu_lSetInputStateIdle
Set the input status of a channel to ICU_IDLE
Input Parameters:
ptr: pointer of RAM location
*/
/* MISRA Rule Violation 16.7:Pointer parameter 'ptr' could be declared
    as pointing to const. As Misra doesn't understand the functionlaity of 
    Mcal_SetAtomic(), 'ptr' can not be declared as pointing to const.
*/
static _INLINE_ void Icu_lSetInputStateIdle(uint32* ptr)
{
  Mcal_SetAtomic((sint32*)(void *)(ptr),
                 (uint32)ICU_IDLE,
                  ICU_CHNL_STATUS_POS,
                  1);
}
 
#if (ICU_GTM_TIM_USED == STD_ON)

#if ((ICU_TIMESTAMP_API == STD_ON) || \
((ICU_TIM_SIGEDGE_USED == STD_ON) && (ICU_SET_MODE_API == STD_ON)))

static void Icu_lGtmDisableChannel(
                              Gtm_GlobalChannelNumberType GlobalChannelNumber
                                   );
#endif

/* #if ((ICU_TIMESTAMP_API == STD_ON) || \
((ICU_TIM_SIGEDGE_USED == STD_ON) && (ICU_SET_MODE_API == STD_ON)))
 */

#if (ICU_TIMESTAMP_API == STD_ON)
static void Icu_lGtmStartTimeStamp(
                           Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                           uint8 ActiveEdge);
static void Icu_lGtmStopTimeStamp(
                             Gtm_GlobalChannelNumberType GlobalChannelNumber);

static uint32 Icu_lGtmGetTimeStamp(
                             Gtm_GlobalChannelNumberType GlobalChannelNumber);

#endif
/* #if (ICU_TIMESTAMP_API == STD_ON) */

#if (ICU_EDGE_COUNT_API == STD_ON)
static void Icu_lGtmResetEdgeCount(
                           Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                           uint32 *EdgeCountValuePtr);

static void Icu_lGtmEnableEdgeCount(
                            Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                            uint8 ActiveEdge, 
                            uint32* EdgeCountValuePtr);

static void Icu_lGtmDisableEdgeCount(
                               Gtm_GlobalChannelNumberType GlobalChannelNumber);

static Icu_17_GtmCcu6_EdgeNumberType Icu_lGtmGetEdgeNumbers(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber,
                                const uint32* EdgeCountValuePtr);
/*
static _INLINE_ uint32 Icu_lGtmEdgeCountModeInit(
                    const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr,
                    uint32 EdgeCountIndex,
                    Icu_17_GtmCcu6_ChannelType Channel, uint8 ChlType);
*/

#endif
/* #if (ICU_EDGE_COUNT_API == STD_ON) */

#if ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) && (ICU_TIM_SIGMEAS_USED == STD_ON))
static void Icu_lGtmStartSignalMeasurement(
                      Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                      Icu_17_GtmCcu6_SignalMeasurementPropertyType SignalMode);

static void Icu_lGtmStopSignalMeasurement(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber
                                 );



#if (ICU_GET_INPUT_STATE_API == STD_ON)
static Icu_17_GtmCcu6_InputStateType Icu_lGtmGetInputState
                      (Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                      Icu_17_GtmCcu6_SignalMeasurementPropertyType SignalMode, 
                      uint8* InfoPtr,uint8 ChlType);

#if ((ICU_GET_INPUT_STATE_API == STD_ON) && (ICU_TIM_SIGMEAS_USED == STD_ON) &&\
  (ICU_SIGNAL_MEASUREMENT_API == STD_ON))

static Icu_17_GtmCcu6_InputStateType Icu_lGtmGetInputStateSigMeas(
                                      Icu_17_GtmCcu6_ChannelType CellUsed,
                                      Icu_17_GtmCcu6_ChannelType Channel,
                    uint8 ChlType);
#endif

/* #if ((ICU_GET_INPUT_STATE_API == STD_ON) && (ICU_TIM_SIGMEAS_USED == STD_ON)\
&& (ICU_SIGNAL_MEASUREMENT_API == STD_ON)) */

static uint8 Icu_lGtmGetInputStateHighTime(uint32 CntsVal, 
                                           const uint8* InfoPtr,
                                           uint8 ModuleNo,
                                           uint8 ChannelNo,uint8 ChlType);

static uint8 Icu_lGtmGetInputStateLowTime(uint32 CntsVal, 
                                           const uint8* InfoPtr,
                                           uint8 ModuleNo,
                                           uint8 ChannelNo,uint8 ChlType);

static uint8 Icu_lGtmGetInputStateResult(uint32 CntsVal, 
                                          uint8 CheckStatus);

#endif
/* #if (ICU_GET_INPUT_STATE_API == STD_ON) */
#endif

/* #if ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) && \
        (ICU_TIM_SIGMEAS_USED == STD_ON)) */



#if ((ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) && \
(ICU_TIM_SIGMEAS_USED == STD_ON))
/* Function to get the duty cycle */
static Icu_17_GtmCcu6_DutyCycleType Icu_lGtmGetDutyCycleValues(
                            Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                            uint8 *InfoPtr);
#endif

/* #if ((ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) && \
        (ICU_TIM_SIGMEAS_USED == STD_ON)) */

#if (ICU_DE_INIT_API == STD_ON)
static void Icu_lGtmResetChannels(void);
#endif
/* #if (ICU_DE_INIT_API == STD_ON) */

static uint8 Icu_lGtmGetIrqNotify(                                            \
                              Gtm_GlobalChannelNumberType GlobalChannelNumber);

#endif



#if (ICU_CCU6_USED == STD_ON)

#if (ICU_DE_INIT_API == STD_ON)
static _INLINE_ void Icu_lCcu6T12DeInit(void);
#endif
/* #if (ICU_DE_INIT_API == STD_ON) */

static _INLINE_ void Icu_lCcu6T12Initialization(void);

static _INLINE_ void Icu_lCcu6ChannelInit(Icu_17_GtmCcu6_ChannelType Channel,
       const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr);

static _INLINE_ void Icu_lCcu6PortInit(
                     const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr);

#endif /* end of #if (ICU_CCU6_USED == STD_ON) */

#if (ICU_CCU6_SIGEDGE_USED == STD_ON)

static _INLINE_ void Icu_lCcu6SetActivationCondition(uint8 CellUsed, 
                                    Icu_17_GtmCcu6_ActivationType ActiveEdge);

#endif
/*   #if (ICU_CCU6_SIGEDGE_USED == STD_ON) */


#if (((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON)) \
     && (ICU_CCU6_SIGEDGE_USED == STD_ON))
static _INLINE_ void Icu_lCcuDisableChannel(uint8 CellUsed);
static _INLINE_ void Icu_lCcuEnableChannel(uint8 CellUsed);

#endif

/* #if ((ICU_SET_MODE_API == STD_ON) && (ICU_CCU6_SIGEDGE_USED == STD_ON)) */


#if ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) && \
(ICU_CCU6_SIGMEAS_USED == STD_ON)) 

static _INLINE_ void Icu_lCcuSignalMeasHandler(uint32 IcuOption, 
                           Icu_17_GtmCcu6_ChannelType CellUsed, 
                           Icu_17_GtmCcu6_SignalMeasurementPropertyType SigKind,
                           Icu_17_GtmCcu6_ActivationType CfgEdge);

static _INLINE_ void Icu_lCcuStopSignalMeas(
                                   Icu_17_GtmCcu6_ChannelType CellUsed);


#endif

#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) && \
  (ICU_CCU6_SIGMEAS_USED == STD_ON))
static _INLINE_ Icu_17_GtmCcu6_ValueType Icu_lCcuGetTimeElapsed(uint8 CellUsed, 
                         Icu_17_GtmCcu6_SignalMeasurementPropertyType SigMode,
                         uint8 ChlType);

#endif

#if ((ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) && \
  (ICU_CCU6_SIGMEAS_USED == STD_ON))
static _INLINE_ void Icu_lCcuGetDutyCycle(uint32 CellUsed, 
                                Icu_17_GtmCcu6_DutyCycleType *DutyCyclePtr,
                                uint8 ChlType);

#endif

#if(ICU_CCU6_SIGMEAS_USED == STD_ON)
static _INLINE_ void Icu_lCcuSignalMeasIntHandler(
                                  uint8 CcuKernalNumber, 
                                  uint8 ChannelCount,
                                  Icu_17_GtmCcu6_ChannelType IcuChannel,
                                  uint32 IsValue,uint8 ChlType);
static Icu_17_GtmCcu6_ValueType Icu_lCcuSubtractWithOverflow(
                                         Icu_17_GtmCcu6_ValueType SecondVal, 
                                         Icu_17_GtmCcu6_ValueType FirstVal);

static _INLINE_ void Icu_lCcuPeriodMeasInt(
                                  Icu_17_GtmCcu6_ChannelType IcuChannel, 
                                  uint8 CcuKernalNumber, 
                                  uint8 ChannelCount,
                                  volatile Ifx_CCU6_CC60R const *CcuRRegPtr,
                                  uint8 ChlType);

#endif
/* #if(ICU_CCU6_SIGMEAS_USED == STD_ON) */



/******************************************************************************
**                      Global Constant Definitions                          **
******************************************************************************/
/******************************************************************************
**                      Global Variable Definitions                          **
******************************************************************************/
#define ICU_17_GTMCCU6_START_SEC_VAR_8BIT
#include "MemMap.h"

/* To store the information on Mode of ICU */
Icu_17_GtmCcu6_ModeType Icu_17_GtmCcu6_GlobMode; 
/* Init Status Variable. It has to be initialized to "0" 
                  after every reset as 0 represents the initialized state */
uint8 Icu_17_GtmCcu6_InitStatus;
 

#if (ICU_CCU6_USED == STD_ON)
Icu_17_GtmCcu6_ChannelType 
       Icu_17_CcuChannelMap[ICU_NO_OF_CCU6_MODULES][ICU_NO_OF_CCU6_CHANNELS];
#endif

#ifdef IFX_ICU_DEBUG
extern volatile Gtm_GlobalChannelNumberType TestIcu_DebugGlobChNo;
#endif

#define ICU_17_GTMCCU6_STOP_SEC_VAR_8BIT
#include "MemMap.h"


#if ( ICU_SAFETY_ENABLE == STD_ON) 

#define ICU_17_GTMCCU6_START_SEC_ASIL0_VAR_UNSPECIFIED
#include "MemMap.h"
#if (ICU_MAX_ASIL_GTM_CHANNELS != 0U) 
Icu_17_GtmCcu6_AsilGtmType Icu_17_GtmCcu6_AsilGtmVarlist;
#endif
#define ICU_17_GTMCCU6_STOP_SEC_ASIL0_VAR_UNSPECIFIED
#include "MemMap.h"


#define ICU_17_GTMCCU6_START_SEC_ASIL1_VAR_UNSPECIFIED
#include "MemMap.h"
#if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U) 
Icu_17_GtmCcu6_AsilCcu6Type Icu_17_GtmCcu6_AsilCcu6Varlist;
 #endif 
#define ICU_17_GTMCCU6_STOP_SEC_ASIL1_VAR_UNSPECIFIED
#include "MemMap.h"

#endif

#define ICU_17_GTMCCU6_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#if (ICU_MAX_QM_CHANNELS != 0U) 
Icu_17_GtmCcu6_QmType Icu_17_GtmCcu6_QmVarlist;
#endif
#define ICU_17_GTMCCU6_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"



 /* Variable to store the channel wakeup info due to which ICU wakeup */
#if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) && \
                                   (ICU_REPORT_WAKEUP_SOURCE == STD_ON))
 static EcuM_WakeupSourceType Icu_WakeupChannelInfo;
#endif

/******************************************************************************
**                      Private Constant Definitions                         **
******************************************************************************/

/******************************************************************************
**                      Private Variable Definitions                         **
******************************************************************************/


/*End of #if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
                                      && (ICU_REPORT_WAKEUP_SOURCE == STD_ON))*/

/*#if (ICU_CCU6_SIGMEAS_USED == STD_ON)*/


#define ICU_17_GTMCCU6_START_SEC_VAR_32BIT
#include "MemMap.h"

#if (ICU_PB_FIXEDADDR == STD_OFF)
/* To store the ICU driver configuration pointer */
const Icu_17_GtmCcu6_ConfigType *Icu_kConfigPtr;
#endif
/*(ICU_PB_FIXEDADDR == STD_OFF)*/

#define ICU_17_GTMCCU6_STOP_SEC_VAR_32BIT
#include "MemMap.h"


#define ICU_17_GTMCCU6_START_SEC_CONST_32BIT
#include "MemMap.h"

#if (ICU_PB_FIXEDADDR == STD_ON)
/* Variable Holds the Configuration Pointer given in Icu_17_GtmCcu6_Init */
const Icu_17_GtmCcu6_ConfigType* const Icu_kConfigPtr =         \
                                                    &Icu_ConfigRoot[0];
#endif
/*(ICU_PB_FIXEDADDR == STD_ON)*/


#define ICU_17_GTMCCU6_STOP_SEC_CONST_32BIT
#include "MemMap.h" 

#define ICU_17_GTMCCU6_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************
**                      Global Function Definitions                          **
******************************************************************************/
/* ICU006: Service for driver initialization */
/******************************************************************************
** Traceability : [cover parentID=DS_AS_ICU191_ICU138,DS_AS_ICU050_1_ICU297,
   DS_AS_ICU023,DS_AS_ICU220,DS_AS_ICU243_1_ICU112_1_ICU048_1,
   DS_AS40X_ICU298,DS_AS_ICU006,DS_AS_ICU061_ICU121,DS_AS_ICU040,
   DS_AS_ICU054_1,DS_NAS_PR734_1,DS_AS_ICU051_ICU052_ICU053]
** Syntax : void Icu_17_GtmCcu6_Init(const Icu_17_GtmCcu6_ConfigType         **
**                                                            *ConfigPtr )   **
** [/cover]                                                                  **
**                                                                           **
** Service ID:      0                                                        **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      ICU050: non reentrant                                    **
**                                                                           **
** Parameters (in): Config - Pointer to configuration set                    **
**                                                                           **
** Parameters (out):none                                                     **
**                                                                           **
** Return value:    none                                                     **
**                                                                           **
** Description : Driver Module Initialization                                **
**               1.This function will initialize all relevant registers of   **
**               configured hardware (AssignedHWUnit) with the values of     **
**               structure referenced by the parameter ConfigPtr.            **
**               2. This service will disable all notifications.             **
**               3. Resources that are not configured in the configuration   **
**                  file will not be changed.                                **
**               4. All ICU channel status is set to ICU_IDLE                **
**               5. All used registers used by configuration will be         **
**                  initialized if Reset and Deinit API will not reset the   **
**                  registers                                                **
**               6. Clearing of pending interrupt flags not done in this     **
**                  function.                                                **
**               7. After initialization the mode is set to ICU_MODE_NORMAL  **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_Init 
(
  const Icu_17_GtmCcu6_ConfigType *ConfigPtr
)
{
  /*ICU138: parameter for Icu_17_GtmCcu6_Init */
  /*ICU053: GTM initializes all common parameters for Drivers that use
               GTM peripheral.
       Gtm_Init should be called prior to calling Icu_17_GtmCcu6_Init*/
  /*ICU052: Port initialization should be done before ICU init */
  /*ICU128, ICU129: taken care by startup */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)|| (ICU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag;

  /* Check for Det */  
  ErrorFlag = Icu_lInitDetCheck (ConfigPtr);
   #if (ICU_SAFETY_ENABLE == STD_ON)
  if ((ErrorFlag != ICU_ERROR_FOUND) &&
      (ConfigPtr->Marker!= ((uint32)ICU_17_GTMCCU6_MODULE_ID << 16U)))
  {
 
    ErrorFlag = ICU_ERROR_FOUND;
    SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ICU_SID_INIT,ICU_E_PARAM_CONFIG);
    
  } 
  #endif /*End Of ICU_SAFETY_ENABLE*/ 
  
  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif


  {

    /* As per bugzilla 11490 Icu_17_GtmCcu6_Init should not be called 
        during a running
        operation. This is purely application design task.
        Driver takes no responsibility on calling the same. 
        by the way it is also mentioned in the caveats */


    #if (ICU_PB_FIXEDADDR == STD_OFF)
    /* Store Config pointer */
    Icu_kConfigPtr = ConfigPtr; 
    #else
    UNUSED_PARAMETER(ConfigPtr)
    #endif
    


    /* Reset all used global variables  */
    /* This function is primarily written to take care of 
       variable that are directly used without assignment.
       In other words the variables that required to have a value
       of zero before Initialization. The variable that
       are assigned a value in Init are ignored in this function.
    */
    /* This function will reset all the required global variables
      that needs a zero input */
    Icu_lResetGlobalVariables();

    #if (ICU_GTM_TIM_USED == STD_ON)
    /* Initialize all the channels configured for GTM */
    Icu_lGtmChannelInit();
    #endif


    #if (ICU_CCU6_USED == STD_ON)
    /* T12 Kernal initialization */
    Icu_lCcu6T12Initialization();
    #endif
/* #if (ICU_CCU6_USED == STD_ON) */
        
    #if (ICU_ERU_USED == STD_ON)
    /* Enable Interrupt (SRE) of SRC register used for ERU Interrupts */
    MODULE_SRC.SCU.SCU.ERU[0].U |= (uint32_t)(ICU_SET_BIT << ICU_SRC_SRE_POS);
   /* _Ifx_SRC_GSCU */
    #endif


    /* Verify for the configured channels */
    Icu_lChannelInit();

    /* ICU060: After initialization the mode will be ICU_MODE_NORMAL */
    /* Make Icu Mode to Normal */
    Icu_17_GtmCcu6_GlobMode = ICU_MODE_NORMAL;
    
    /* Set Status to indicate that initialization is done */
    Icu_17_GtmCcu6_InitStatus = ICU_INITIALIZED;
  }
  return;
  
}/* End of Icu_17_GtmCcu6_Init() function */


/* [cover parentID=DS_AS_ICU092_ICU301] */
#if (ICU_DE_INIT_API == STD_ON)
/* [/cover] */
/* ICU035: Service for ICU De-Initialization */
/******************************************************************************
** Traceability : [cover parentID=DS_AS_ICU193,DS_AS_ICU050_2_ICU299,
   DS_AS_ICU022_1,DS_AS_ICU243_2_ICU112_2_ICU048_2,DS_AS_ICU035_ICU037,
   DS_AS_ICU036_ICU091,DS_AS_ICU300,DS_AS_ICU152,DS_AS_ICU221,
   DS_NAS_PR734_2]
** Syntax : void Icu_17_GtmCcu6_DeInit(void)                                 **
** [/cover]                                                                  **
** Service ID:       1                                                       **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       ICU050: non reentrant                                   **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for ICU De-Initialization                           **
**               1.After the call of this service, the state of the used     **
**                 peripherals/registers will set to power on reset state.   **
**               2. This service will disable all used interrupts and        **
**                  notifications.                                           **
**               3. This service clear all pending interrupt flags           **
**               4. All global variables will set to reset value             **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_DeInit(void)
{
  /* Local variables */
  #if ((ICU_ERU_USED == STD_ON) || (ICU_CCU6_USED == STD_ON))
  Icu_17_GtmCcu6_ChannelType CellUsed;
  uint32 IcuOption;
  Icu_17_GtmCcu6_ChannelType Channel;
  Icu_17_GtmCcu6_ChannelType MaxChannels;
  /* Local pointers */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  uint8 PhyChannelIndex;  
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;  
  #endif
  
  #if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)  || (ICU_MAX_QM_CCU6_CHANNELS != 0U)  
  uint8 ChlType;  
  #endif
  
  #if (ICU_ERU_USED == STD_ON)
  Icu_17_GtmCcu6_ChannelType EruEicrUsed;
  Icu_17_GtmCcu6_ChannelType EruEicrChannel;  
  Icu_17_GtmCcu6_ChannelType EruChannel;  
  #endif

  #if (ICU_CCU6_USED == STD_ON)
  volatile Ifx_CCU6 *Ccu6BaseRegPtr;/* Variable to hold the CCU6 base address */
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  volatile Ifx_CCU6_CC60SR *CcuSrRegPtr; /* Pointer to SR registers of CCU */
  uint8 CcuKernalNumber;    /* To hold CCU Kernal Number */
  uint8 CcChannelNumber;    /* To hold the CC channel number */
  #endif

  
  #if (ICU_DEV_ERROR_DETECT == STD_ON)
  /* Verify any error is there for DET */  
  uint32 ErrorFlag;
  
  ErrorFlag = Icu_lDeInitDetCheck();

  if (ICU_ERROR_FOUND != ErrorFlag)  
  #endif
  {
    #if (ICU_GTM_TIM_USED == STD_ON)
    Icu_lGtmResetChannels();
    #endif
    
    #if ((ICU_ERU_USED == STD_ON) || (ICU_CCU6_USED == STD_ON))
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = Icu_kConfigPtr->ChannelConfigPtr ;  
    /* Initialize Global channel RAM pointer */
    /* Get the maximum number of channels */
  /* Get the maximum number of channels */
  MaxChannels = ICU_GETMAXSIGEDGEQMCHANNELS +
                ICU_GETMAXEDGECNTQMCHANNELS +
                ICU_GETMAXTIMSTMPQMCHANNELS +
                ICU_GETMAXSIGMEASQMCHANNELS;
                
  #if (ICU_SAFETY_ENABLE == STD_ON)   
  MaxChannels += ICU_GETMAXSIGEDGEASILCHANNELS +
                ICU_GETMAXEDGECNTASILGTMCHANNELS +
                ICU_GETMAXTIMSTMPASILGTMCHANNELS +
                ICU_GETMAXSIGMEASASILCHANNELS;
  #endif  
    /*
     1. Reset associated registers for each kind of resource used.
     2. Clear pending interrupts.
     3. FPC Registers are also cleared if they are used.
    */
    /* ICU036: Deinit the configured channels, registers , variables etc */
    
    for (Channel=(Icu_17_GtmCcu6_ChannelType)0;Channel < MaxChannels;Channel++)
    {
      /* ICU 037 service shall disable all notifications */
      LocalIcuMapPtr =   (Icu_kConfigPtr->MappingIndexPtr) + Channel;
      PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap;
       
       #if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)  || (ICU_MAX_QM_CCU6_CHANNELS != 0U)
        ChlType = Icu_lGetChannelType(Channel);
       #endif
       /* Depending on ICU option take action */
      IcuOption = (uint32)LocalIcuChanPtr->IcuProperties.AssignedHwUnit;

      #if (ICU_ERU_USED == STD_ON)
      if(IcuOption == ICU_ERU_OPTION)
      {
        Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex] = 0U;

        /* Extract the actual cell number */
        CellUsed = (uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
        
        /* Extract proper Eru Line */
        EruEicrUsed    = Icu_lGetEruEicr(CellUsed);
        EruEicrChannel = Icu_lGetEruEicrChannel(CellUsed);
        /* Deinit control register depending on ERU line used */
        Icu_lDeInitEru(EruEicrUsed, EruEicrChannel);
          
        EruChannel = Icu_lGetEruChannel(CellUsed);
        /* ICU061: This service will disable notifications */
        /* ICU037: Clear pending interrupt flag */
        MODULE_SCU.FMR.U = Icu_lClearEruServiceRequest(EruChannel);
           
        /* ICU037:Disable SRC register */
           
        /* Disable Interrupts and  Clear service requests */
        /* Clear service requests: SRE=0, CLRR=1, Mask SRPN 
           and others with zero */
        MODULE_SRC.SCU.SCU.ERU[0].U = 
           (uint32_t)((ICU_CLRR_ASSERT << ICU_CLRR_POSITION)
                    | (MODULE_SRC.SCU.SCU.ERU[0].B.SRPN)
                    );
        
      }
      #endif
/* #if (ICU_ERU_USED == STD_ON) */
      #if (ICU_CCU6_USED == STD_ON)
      if(IcuOption == ICU_CCU_OPTION)
      {
    #if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)    
      if(ChlType == ICU_CCU6_ASIL_CHANNEL)
      {
        Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[PhyChannelIndex] = 0U;
      }
    #endif 
     #if (ICU_MAX_QM_CCU6_CHANNELS != 0U) 
       if(ChlType == ICU_CCU6_QM_CHANNEL)
       {
         Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex] = 0U;
       }
     #endif 
        /* Assign the base address to CCU60 base address */
        Ccu6BaseRegPtr = &MODULE_CCU60;
        
        /* Extract the actual cell number */
        CellUsed = (uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
        
        /* Lower Nibble of AssignedHwUnitNumber holds the Kernal Number */
        CcuKernalNumber = CellUsed & ICU_CCU_GET_LOWER_NIBBLE;
        /* Upper Nibble of AssignedHwUnitNumber holds the Channel Number */
        CcChannelNumber = (CellUsed & ICU_CCU_GET_UPPER_NIBBLE) \
                                                          >> ICU_BRING_TO_BIT_0;
        /* Get the base address of the Kernal */
        Ccu6RegPtr = Ccu6BaseRegPtr + CcuKernalNumber;

        /* Assign SR and R register base addresses */
        CcuSrRegPtr = &(Ccu6RegPtr->CC60SR);
        
        /* Channel mode is reset to its initial value */
        Ccu6RegPtr->T12MSEL.U &= (uint32_t)~(ICU_CCU_MSEL_RESET_VAL << \
                             (CcChannelNumber * ICU_CCU_MSEL_BITS_PER_CHANNEL));

        /* Port connections initialized to its reset value */
        Ccu6RegPtr->PISEL0.U &= (uint32_t)~(ICU_CCU_PISEL_RESET_VAL << \
                            (CcChannelNumber * ICU_CCU_PISEL_BITS_PER_CHANNEL));

        /* Clear the IEN register */
        Ccu6RegPtr->IEN.U &= (uint32_t)~(ICU_CCU_CLEAR_INTERRUPT << \
                               (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));

        /* SR and R registers are cleared */
        CcuSrRegPtr[CcChannelNumber].U = 0UL;

        /* Clear any pending interrupt */
        Ccu6RegPtr->ISR.U |= (uint32_t)(ICU_CCU_CLEAR_INTERRUPT << \
                               (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));
                             
        /* Clear the ICU channel Map details */
        Icu_17_CcuChannelMap[CcuKernalNumber][CcChannelNumber] = 0U;
   }
      #endif
/* #if (ICU_CCU6_USED == STD_ON) */
                            
      /* Increment the channel pointers */
      LocalIcuChanPtr++;

    }/* End of for loop within Icu_17_GtmCcu6_DeInit() function */

    #if (ICU_CCU6_USED == STD_ON)
    /* Deinitializing T12 timer if initialization is performed by ICU */
    Icu_lCcu6T12DeInit();
    #endif
/* #if (ICU_CCU6_USED == STD_ON) */
    #endif
/* #if ((ICU_ERU_USED == STD_ON) || (ICU_CCU6_USED == STD_ON)) */
    
    #if (ICU_PB_FIXEDADDR == STD_OFF)
    /* Reset the global config pointer to 0 */
    Icu_kConfigPtr = NULL_PTR;
    #endif
      
    /* Clear the Status to indicate that Deinitialization is done */
    Icu_17_GtmCcu6_InitStatus = ICU_DEINITIALIZED;
  }  
  return;
  
}/* End of Icu_17_GtmCcu6_DeInit() function */
#endif
/*ICU095: Precompile switch with ICU_SET_MODE_API */
/* [cover parentID=DS_AS_ICU303_ICU095] */
#if (ICU_SET_MODE_API == STD_ON)
/* [/cover] */
/* [cover parentID=DS_MCAL_SWSC_ICU_0007] */ 
/* ICU008: Service for ICU mode selection.*/
/******************************************************************************
** Traceability : [cover parentID=DS_AS_ICU194,DS_AS_ICU050_3_ICU302,
   DS_AS_ICU022_2,DS_AS_ICU243_3_ICU112_3_ICU048_3,DS_AS_ICU125,
   DS_AS_ICU260_ICU261,DS_AS_ICU008,DS_AS_ICU133,DS_NAS_PR734_3]
**                                                                           **
** Syntax : void Icu_17_GtmCcu6_SetMode(Icu_17_GtmCcu6_ModeType Mode)        **
**                                                                           **
** [/cover]                                                                  **
** Service ID:       2                                                       **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       ICU050: non reentrant                                   **
**                                                                           **
** Parameters (in):  Mode : ICU_MODE_NORMAL or ICU_MODE_SLEEP                **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for ICU mode selection                              **
**               1.This service will set the operation mode to the given mode**
**                  parameter.                                               **
**               2.In ICU_MODE_NORMAL mode all notifications are available as**
**         configured and selected by the Icu_17_GtmCcu6_DisableNotification **
**         and Icu_17_GtmCcu6_EnableNotification services before or after the**
**         call of Icu_17_GtmCcu6_SetMode.                                   **
**               3.In ICU_MODE_SLEEP mode only those notifications are       **
**                 available which are configured as wake-up capable and that**
**         are not disabled via service Icu_17_GtmCcu6_DisableWakeup.All     ** 
**                 other interrupts are disabled                             **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_SetMode(Icu_17_GtmCcu6_ModeType Mode)
{
  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  /* Verify any error is there for DET */  
  uint32 ErrorFlag;
  Icu_17_GtmCcu6_ChannelType Channel;
  Icu_17_GtmCcu6_ChannelType MaxChannels;
  #endif
  #if ( ICU_DEV_ERROR_DETECT == STD_OFF ) && ( ICU_SAFETY_ENABLE == STD_ON )   
  ErrorFlag = ICU_ERROR_NOT_FOUND;
  #endif 
  #if (ICU_DEV_ERROR_DETECT == STD_ON)   
  /* Initialize Global channel RAM pointer */
  ErrorFlag = Icu_lInitCallVerify(ICU_SID_SETMODE);
  if (ErrorFlag != ICU_ERROR_FOUND)
  #endif
  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)      
  {
    if ( !((Mode == ICU_MODE_NORMAL) || (Mode == ICU_MODE_SLEEP)))
    {
     #if (ICU_DEV_ERROR_DETECT == STD_ON) 
      /*ICU125 :check for invalid mode*/
      Det_ReportError( ICU_17_GTMCCU6_MODULE_ID,
                       ICU_17_GTMCCU6_INSTANCE_ID,
                       ICU_SID_SETMODE,
                       ICU_E_PARAM_MODE);
     #endif
     #if (ICU_SAFETY_ENABLE == STD_ON)
       /* Report an error */
       SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                     ICU_17_GTMCCU6_INSTANCE_ID,
                                     ICU_SID_SETMODE,ICU_E_PARAM_MODE);
     #endif   
      ErrorFlag = ICU_ERROR_FOUND;
    }
    else
    {
  /* Get the maximum number of channels */
  MaxChannels = ICU_GETMAXSIGEDGEQMCHANNELS +
                ICU_GETMAXEDGECNTQMCHANNELS +
                ICU_GETMAXTIMSTMPQMCHANNELS +
                ICU_GETMAXSIGMEASQMCHANNELS;
                
  #if (ICU_SAFETY_ENABLE == STD_ON)   
  MaxChannels += ICU_GETMAXSIGEDGEASILCHANNELS +
                ICU_GETMAXEDGECNTASILGTMCHANNELS +
                ICU_GETMAXTIMSTMPASILGTMCHANNELS +
                ICU_GETMAXSIGMEASASILCHANNELS;
  #endif  
      for (  Channel = (Icu_17_GtmCcu6_ChannelType)0; 
            Channel < (MaxChannels) ;
            Channel++ 
          )
  
      {
        if (ErrorFlag != ICU_ERROR_FOUND)
        {

          /* ICU133 the running operations shall be maintained */
          /* Running operation : as per ICU SWS2.0, signal measurement channel 
             cannot be stopped. Its not possible to put in sleep mode with 
             DET enabled and a configuration set 
             containing Signal Measurement channel.
          */
          if (((uint32)Icu_17_lGlbIndexStatusExtract(Channel,
                                ICU_CHNL_ACTIVITY_STARTED_POS, 
                                ICU_CHNL_ACTIVITY_BIT_LENGTH) ==
                                ICU_ACTIVITY_STARTED))
          {
            ErrorFlag = ICU_ERROR_FOUND;
     #if (ICU_DEV_ERROR_DETECT == STD_ON) 
            /* ICU 133 */
            Det_ReportError( ICU_17_GTMCCU6_MODULE_ID,
                             ICU_17_GTMCCU6_INSTANCE_ID,
                             ICU_SID_SETMODE,
                             ICU_E_BUSY_OPERATION);  
    #endif
          }
        }
      }
    }
  }

  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
/* #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Verify whether asked for sleep mode */
    if (Mode == ICU_MODE_SLEEP)
    {
      /* Make Icu Mode to Wakeup */
      Icu_17_GtmCcu6_GlobMode = ICU_MODE_SLEEP;

      #if (ICU_EDGE_DETECTION_USED == STD_ON)
       
      /*ICU012:Disable the cell or lines which are not wakeup capable channels*/
      Icu_lDisableForWakeup();
    
      #endif

      /* #if (ICU_EDGE_DETECTION_USED == STD_ON) */
      
    }/* End of wakeup mode setting */
    else
    {
      /* Make Icu Mode to Normal */
      Icu_17_GtmCcu6_GlobMode = ICU_MODE_NORMAL;

      #if (ICU_EDGE_DETECTION_USED == STD_ON)   
      /* ICU011: Set Mode to Normal */
      Icu_lSetNormal();
      #endif
      /* #if (ICU_EDGE_DETECTION_USED == STD_ON) */    
    }
  }
} /* End of function Icu_17_GtmCcu6_SetMode */
#endif
  /* end of #if (ICU_SET_MODE_API == STD_ON) */

/* [/cover]  */

/* ICU096: Configuration for Disable Wakeup*/
/* [cover parentID=DS_AS_ICU306_ICU096] */
#if (ICU_DISABLE_WAKEUP_API == STD_ON)
/* [/cover] */
/******************************************************************************
** Traceability : [cover parentID=DS_AS_ICU195,DS_AS_ICU050_4_ICU304,
   DS_AS_ICU022_3,DS_AS_ICU024,DS_AS_ICU059,
   DS_AS_ICU243_4_ICU112_4_ICU048_4,DS_AS_ICU013,DS_AS_ICU305,DS_NAS_PR734_4]

** Syntax : void Icu_17_GtmCcu6_DisableWakeup(                               **
**                                  Icu_17_GtmCcu6_ChannelType Channel)      **
** [/cover]                                                                  **
**                                                                           **
** Service ID:       3                                                       **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1 This service will disable the wake-up capability of single**
**                 ICU channel for the following ICU mode selection(s).      **
**               2.This service is only feasible for ICU channels configured **
**                 as wake-up capable true.                                  **
**       3.From the call of Icu_17_GtmCcu6_Init()channel which was configured**
**                 as wakeup capable by using this service user can disable  **
**                 the wakeup capability.                                    **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_DisableWakeup(Icu_17_GtmCcu6_ChannelType Channel)
{
  #if (ICU_GTM_TIM_USED == STD_ON)
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr;
  uint8 NotifStatus;
  uint8 HwUnit;  
  #endif
 

  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag;
  /* Verify any error is there for DET */  
  ErrorFlag = Icu_lWakeupDetCheck(Channel,ICU_SID_DISABLEWAKEUP);

  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
  {
   /* ICU013: Don’t Make Channel as Wakeup capable */
   Icu_17_lGlbIndexStatusSet(Channel,0U, ICU_CHNL_WAKEUP_CAPABLE_POS,1U);

    #if (ICU_GTM_TIM_USED == STD_ON)
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr =  (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;

    if((uint32)(LocalIcuChanPtr->IcuProperties.AssignedHwUnit)== ICU_GTM_OPTION)
    {
       NotifStatus = (uint8)Icu_17_lGlbIndexStatusExtract(Channel,
                   ICU_CHNL_NOTIF_PRESENCE_POS,ICU_CHNL_NOTIF_BIT_LENGTH);

        if(NotifStatus == 0U)
        {
          HwUnit = (uint8)(LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber);
          Icu_lGtmIrqModify(HwUnit, 0U);
        }
    }
    #endif
    
  }
}/* End of function Icu_17_GtmCcu6_DisableWakeup */
#endif
/* End of #if (ICU_DISABLE_WAKEUP_API == STD_ON) */

/* ICU097 : Configuration of Icu_17_GtmCcu6_EnableWakeup API */
/* [cover parentID=DS_AS_ICU308_ICU097] */
#if  (ICU_ENABLE_WAKEUP_API == STD_ON)
/* [/cover] */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU196,DS_AS_ICU050_5_ICU307,
   DS_AS_ICU022_4,DS_AS_ICU155,DS_AS_ICU156,DS_AS_ICU243_5_ICU112_5_ICU048_5,
   DS_AS_ICU012_ICU014,DS_NAS_PR734_5]
** Syntax :          void Icu_17_GtmCcu6_EnableWakeup(                       **
**                                 Icu_17_GtmCcu6_ChannelType Channel)       **
** [/cover]                                                                  **
**                                                                           **
** Service ID:       4                                                       **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel number                  **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1 This service will re-enable /enable the wake-up capability**
**                 of ICU channel.                                           **
**               2.This service is only feasible for ICU channels configured **
**                 as wake-up capable true. The signal measurement mode      **
**                 should be ICU_MODE_SIGNAL_EDGE_DETECT.                    **
**       3.From the call of Icu_17_GtmCcu6_Init() the channel which was      **
**                 configured as wakeup capable and the same capability was  **
**         disabled by using service Icu_17_GtmCcu6_DisableWakeup().         **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_EnableWakeup(Icu_17_GtmCcu6_ChannelType Channel)
{
  #if (ICU_GTM_TIM_USED == STD_ON)  
  uint8 HwUnit;
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr;
  uint8 IrqValue;
  #endif

  #if  (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  /* Verify any error is there for DET */  
  uint32 ErrorFlag;

  /* ICU059 , ICU024 is taken care inside the function */
  ErrorFlag = Icu_lWakeupDetCheck(Channel,ICU_SID_ENABLEWAKEUP);

  if (ICU_ERROR_FOUND != ErrorFlag)  
  #endif
/* #if  (ICU_DEV_ERROR_DETECT == STD_ON) */

  {
     /* ICU014: Make Channel as Wakeup capable */
  Icu_17_lGlbIndexStatusSet(Channel,1U, ICU_CHNL_WAKEUP_CAPABLE_POS,1U);

    #if (ICU_GTM_TIM_USED == STD_ON)

    LocalIcuChanPtr =  (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;
    if((uint32)(LocalIcuChanPtr->IcuProperties.AssignedHwUnit)== ICU_GTM_OPTION)
    { 
      /* Initialize ICU configured channel ROM pointer */
      HwUnit = (uint8)(LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber);

      SchM_Enter_Icu_17_GtmCcu6_EnableWakeup();
      IrqValue = Icu_lGtmGetIrqNotify(HwUnit);
      if((IrqValue & 1U) == 1U)
      {
        /* Since the Interrupt Notify information is used by other API's too,
           this information has to be backed up before it is modified */

      Icu_17_lGlbIndexStatusSet(Channel,1U, (uint8)ICU_CHNL_NOTIF_STATUS_POS,1U);           
   
      }

      
      Icu_lGtmClearIrqNotify(HwUnit);
      Icu_lGtmIrqModify(HwUnit, 1U);

      SchM_Exit_Icu_17_GtmCcu6_EnableWakeup();
    }
    #endif
/* #if (ICU_GTM_TIM_USED == STD_ON) */
  }
} /* End of function Icu_17_GtmCcu6_EnableWakeup */
#endif
/* End of #if  (ICU_ENABLE_WAKEUP_API == STD_ON) */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU197,DS_AS_ICU050_6_ICU309,
   DS_AS_ICU022_5,DS_AS_ICU043,DS_AS_ICU159,DS_AS_ICU048_6,
   DS_AS_ICU243_6_ICU112_6_ICU090_1,DS_AS_ICU011,DS_AS_ICU090_2,DS_AS_ICU139,
   DS_NAS_PR734_6]
** Syntax : void Icu_17_GtmCcu6_SetActivationCondition(                      **
**                               Icu_17_GtmCcu6_ChannelType Channel          **
**                               Icu_17_GtmCcu6_ActivationType Activation)   **
**                                                                           **
** [/cover]                                                                  **
** Service ID:  5                                                            **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
** Parameters (in):  Activation : ICU_RISING_EDGE,ICU_FALLING_EDGE,          **
**                                ICU_BOTH_EDGES                             **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:    none                                                     **
**                                                                           **
** Description : 1 This service will set the required configured edge.       **
**               2.This service is only feasible for ICU channels configured **
**                 as EdgeDetection,TimeStamp and EdgeCounter.               **
**               3.For Signal Measurement Only DefaultStartEdge to be Used   **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_SetActivationCondition
(
  Icu_17_GtmCcu6_ChannelType   Channel, 
  Icu_17_GtmCcu6_ActivationType  Activation
)
{
  /* This function is applicable for channels configured for all modes 
     except Signal Measurement. Hence apart from the DET check, rest of the 
     function is not needed for the case where the configuration only has 
     signal measurement channels */
  #if (ICU_SET_ACTIVATION_REQD == STD_ON)
  Icu_17_GtmCcu6_ChannelType CellUsed;
  uint8 IcuOption;
  #endif
  /* #if (ICU_SET_ACTIVATION_REQD == STD_ON) */
       
 #if((ICU_SET_ACTIVATION_REQD == STD_ON) || (ICU_DEV_ERROR_DETECT == STD_ON) \
     || (ICU_SAFETY_ENABLE == STD_ON))
  /* Local pointers */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  #else
  UNUSED_PARAMETER(Channel)
  UNUSED_PARAMETER(Activation)
  #endif
  /*  #if ((ICU_SET_ACTIVATION_REQD == STD_ON) || \
     (ICU_DEV_ERROR_DETECT == STD_ON)) */
  
  #if (ICU_ERU_USED == STD_ON)
  Icu_17_GtmCcu6_ChannelType EruChannel;
  Icu_17_GtmCcu6_ChannelType EruEicrUsed;
  Icu_17_GtmCcu6_ChannelType EruEicrChannel;
  #endif
   #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  /* Verify any error is there for DET */  
  uint32 ErrorFlag;
  #endif  
 
  #if(ICU_CCU6_SIGEDGE_USED == STD_ON) || (ICU_ERU_USED == STD_ON)
  uint8 PhyChannelIndex;
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;  
  #endif
 
  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON) 
  /* ICU022 : Check whether Init has been earlier called or not */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)     
  ErrorFlag = Icu_lInitCallVerify(ICU_SID_SETACTIVATIONCONDITION);
  if (ErrorFlag != ICU_ERROR_FOUND)
  #endif  
  {
    /*ICU024 : Check for valid channel */
    ErrorFlag = Icu_lChannelVerify(ICU_SID_SETACTIVATIONCONDITION,
                                        Channel);
    if (ErrorFlag != ICU_ERROR_FOUND)
    {
      /*ICU043 : Check for valid activation parameter */
      if (Activation > ICU_BOTH_EDGES)
      {
        ErrorFlag = ICU_ERROR_FOUND;
      #if (ICU_DEV_ERROR_DETECT == STD_ON) 
        Det_ReportError(ICU_17_GTMCCU6_MODULE_ID,
                        ICU_17_GTMCCU6_INSTANCE_ID,
                        ICU_SID_SETACTIVATIONCONDITION,
                        ICU_E_PARAM_ACTIVATION );
      #endif
      #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                               ICU_SID_SETACTIVATIONCONDITION,
                                      ICU_E_PARAM_ACTIVATION);
      #endif
      }
    } 
  }
  if (ErrorFlag != ICU_ERROR_FOUND)
  {
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;  
    if (LocalIcuChanPtr->IcuProperties.MeasurementMode == \
                                                ICU_MODE_SIGNAL_MEASUREMENT)
    {
      /* ICU090 This service shall support channels which are configured 
         for the following IcuProperties.MeasurementMode:
         ICU_MODE_SIGNAL_EDGE_DETECT
         ICU_MODE_TIMESTAMP
         ICU_MODE_EDGE_COUNTER */
      ErrorFlag = ICU_ERROR_FOUND;
      #if (ICU_DEV_ERROR_DETECT == STD_ON)   
      Det_ReportError(ICU_17_GTMCCU6_MODULE_ID,
                      ICU_17_GTMCCU6_INSTANCE_ID,
                      ICU_SID_SETACTIVATIONCONDITION,
                      ICU_E_PARAM_CHANNEL );   
      #endif
      #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                               ICU_SID_SETACTIVATIONCONDITION,
                                      ICU_E_PARAM_CHANNEL);
      #endif  
    }
  }

  if (ICU_ERROR_FOUND != ErrorFlag) 
  #endif
/* #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(ICU_CCU6_SIGEDGE_USED == STD_ON) || (ICU_ERU_USED == STD_ON)
    LocalIcuMapPtr =   (Icu_kConfigPtr->MappingIndexPtr) + Channel;
    PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap;  
    #endif  
    #if (ICU_SET_ACTIVATION_REQD == STD_ON)
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;
    if (LocalIcuChanPtr->IcuProperties.MeasurementMode 
         != ICU_MODE_SIGNAL_MEASUREMENT)
    {
      /* Depending on ICU option take action */
      IcuOption = Icu_lGetChannelType(Channel);
      /* Extract the actual cell number */

      CellUsed =                                                             \
              (Icu_17_GtmCcu6_ChannelType)LocalIcuChanPtr->IcuProperties.
                                                         AssignedHwUnitNumber;
     
      /* Set the edge in register only for Signal edge detection channels */
      /* For other channels, EnableEdgeCount Or StartTimestamp will
        take care of the same */
    
      switch(IcuOption)
      {
        #if (ICU_GTM_TIM_USED == STD_ON)
        case ICU_GTM_ASIL_CHANNEL:
        case ICU_GTM_QM_CHANNEL:
          Icu_17_lGlbIndexStatusSet(Channel,(uint8)Activation,
                   ICU_CHNL_EDGE_POS,ICU_CHNL_EDGE_BIT_LENGTH);
        /* Clear Service Request Flag */
        /* ICU010: Enable the cell for notification */
        Icu_lGtmChangeActiveEdge(CellUsed,Activation);
        Icu_17_lGlbIndexStatusSet(Channel,0U,(uint8)ICU_CHNL_NOTIF_STATUS_POS,
                                  1U);   
        break;
        #endif
         

        #if(ICU_CCU6_SIGEDGE_USED == STD_ON)
        case ICU_CCU6_ASIL_CHANNEL:
        case ICU_CCU6_QM_CHANNEL:
        Icu_17_lGlbIndexStatusSet(Channel,(uint8)Activation,
                  ICU_CHNL_EDGE_POS,ICU_CHNL_EDGE_BIT_LENGTH);        
        Icu_lCcu6SetActivationCondition(CellUsed,Activation);
         #if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)
       /*  #if (ICU_MAX_QM_CCU6_CHANNELS != 0U) */
        if(IcuOption == ICU_CCU6_ASIL_CHANNEL) /* Make Input state as Idle */
       /* #endif */
        {
          Icu_lSetInputStateIdle(&Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus
                                  [PhyChannelIndex]);
        } 
        #endif
        #if (ICU_MAX_QM_CCU6_CHANNELS != 0U)
        /* #if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U) */
        if(IcuOption == ICU_CCU6_QM_CHANNEL) /* Make Input state as Idle */
        /*#endif */
        {
          Icu_lSetInputStateIdle(&Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus
                                 [PhyChannelIndex]); 
        } 
        #endif  
        break;
        #endif
/* #if(ICU_CCU6_SIGEDGE_USED == STD_ON) */

        default : /* ICU_ERU_OPTION */       
        #if (ICU_ERU_USED == STD_ON)
        Mcal_SetAtomic((sint32*)(void*)
        &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex],
        (uint32)Activation,ICU_CHNL_EDGE_POS,2);  
        
        /* Extract proper Eru Line */
        EruChannel = Icu_lGetEruChannel(CellUsed);
        /* Clear Service Request if any was in pending */
        MODULE_SCU.FMR.U = Icu_lClearEruServiceRequest(EruChannel);
        EruEicrUsed    = Icu_lGetEruEicr(CellUsed);
        EruEicrChannel = Icu_lGetEruEicrChannel(CellUsed);
        /* ICU010: Enable the cell for notification */
        Icu_lSetEruEdge(Activation, EruEicrUsed, EruEicrChannel);
        /* the status is put to IDLE */
        Icu_lSetInputStateIdle(&Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex]);
        #endif
        break;
      }/* End of switch condition */
    }
    #endif
    /* #if (ICU_SET_ACTIVATION_REQD == STD_ON) */
    
  }
}/* End of function Icu_17_GtmCcu6_SetActivationCondition */

/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU198,DS_AS_ICU050_7_ICU310,
   DS_AS_ICU022_6,DS_AS_ICU160,DS_AS_ICU243_7_ICU112_7_ICU048_7,
   DS_AS_ICU259_ICU009,DS_NAS_PR734_7]

** Syntax : void Icu_17_GtmCcu6_DisableNotification(                         **
**                               Icu_17_GtmCcu6_ChannelType Channel)         **
**                                                                           **
** [/cover]                                                                  **
** Service ID:       6                                                       **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : This service will disable  ICU signal notifications of      **
**               this channel.                                               **
**               This API affects both ICU_MODE_SIGNAL_EDGE_DETECT and       **
**               ICU_MODE_TIMESTAMP Channels.                                **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_DisableNotification
(
  Icu_17_GtmCcu6_ChannelType Channel 
)
{
  #if (ICU_GTM_TIM_USED == STD_ON)
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr;
  uint8 HwUnit;
#if (ICU_GTM_TIM_USED == STD_ON)
  uint8 WakeupStatus;
 #endif
  #endif
/*     #if (ICU_GTM_TIM_USED == STD_ON) */
  #if  (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  /* Verify any error is there for DET */  
  uint32 ErrorFlag;

  ErrorFlag = Icu_lEnDisNotificationDetCheck(
                                             Channel,
                                             ICU_SID_DISABLENOTIFICATION);
  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
/* #if  (ICU_DEV_ERROR_DETECT == STD_ON) */

  {
    /*ICU009: Disable Notification of the channel */
    Icu_17_lGlbIndexStatusSet(Channel,0U,ICU_CHNL_NOTIF_PRESENCE_POS,1U);


    #if (ICU_GTM_TIM_USED == STD_ON)
    LocalIcuChanPtr =  (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;
    if((uint32)(LocalIcuChanPtr->IcuProperties.AssignedHwUnit)== ICU_GTM_OPTION)
    {
      /* Initialize ICU configured channel ROM pointer */
      if (LocalIcuChanPtr->IcuProperties.MeasurementMode != ICU_MODE_TIMESTAMP)
      {
        WakeupStatus = (uint8)Icu_17_lGlbIndexStatusExtract(Channel,
            ICU_CHNL_WAKEUP_CAPABLE_POS,ICU_CHNL_WAKEUP_BIT_LENGTH);
 
    if(WakeupStatus == 0U)
    {
          HwUnit = (uint8)(LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber);
          Icu_lGtmIrqModify(HwUnit, 0U);
     }
   }
    } 
    #endif
}
 }/* End of function Icu_17_GtmCcu6_DisableNotification */

/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU199,DS_AS_ICU050_8_ICU311,
   DS_AS_ICU022_7,DS_AS_ICU161,DS_AS_ICU243_8_ICU112_8_ICU048_8,
   DS_AS_ICU259_ICU010,DS_NAS_PR734_8]

** Syntax : void Icu_17_GtmCcu6_EnableNotification(                          **
**                                      Icu_17_GtmCcu6_ChannelType Channel   **
**                                     )                                     **
** [/cover]                                                                  **
** Service ID:       7                                                       **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : This service will enable the ICU signal notification,       **
**               activation edge depends on either DefaultStartEdge          **
**               Or activation by Icu_17_GtmCcu6_SetActivationCondition API. **
**               This API affects both ICU_MODE_SIGNAL_EDGE_DETECT and       **
**               ICU_MODE_TIMESTAMP Channels.                                **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_EnableNotification
(
  Icu_17_GtmCcu6_ChannelType Channel
)
{
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  #if (ICU_GTM_TIM_USED == STD_ON)
  uint8 HwUnit;
  uint8 IrqValue;
  #endif

  #if  (ICU_DEV_ERROR_DETECT == STD_ON)|| (ICU_SAFETY_ENABLE == STD_ON)
  /* Verify any error is there for DET */  
  uint32 ErrorFlag;

  ErrorFlag = Icu_lEnDisNotificationDetCheck(
                                            Channel,
                                            ICU_SID_ENABLENOTIFICATION);
  if (ICU_ERROR_FOUND != ErrorFlag) 
  #endif
/* #if  (ICU_DEV_ERROR_DETECT == STD_ON) */

  {
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;
    /* ICU127 : cancel the pending interrupts */
    /* Bugzilla 19273 : ICU127 doesn't make sense;
       no cancelling of interrupts */
    /* ICU010 :Enable Notification for the corresponding channel if the pointer
      is not NULL */
    /* As per bugzilla 11480 the notification flag
      shall be enabled in Icu_17_GtmCcu6_EnableNotification API */
    /*ICU020: No call should be executed if the function pointer is NULL */
    if (LocalIcuChanPtr->NotificationPointer != NULL_PTR )
    {
      Icu_17_lGlbIndexStatusSet(Channel,1U,ICU_CHNL_NOTIF_PRESENCE_POS,1U);
    }

    #if (ICU_GTM_TIM_USED == STD_ON)
    
    if((uint32)(LocalIcuChanPtr->IcuProperties.AssignedHwUnit)== ICU_GTM_OPTION)
    {

      /* Initialize ICU configured channel ROM pointer */
      HwUnit = (uint8)(LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber);
      
      SchM_Enter_Icu_17_GtmCcu6_EnableNotification();
      IrqValue = Icu_lGtmGetIrqNotify(HwUnit);
      if((IrqValue & 1U) == 1U)
      {
        /* Since the Interrupt Notify information is used by other API's too,
           this information has to be backed up before it is modified */
        Icu_17_lGlbIndexStatusSet(Channel,1U,(uint8)ICU_CHNL_NOTIF_STATUS_POS,
                                  1U);
      }
      Icu_lGtmClearIrqNotify(HwUnit);
      Icu_lGtmIrqModify(HwUnit, 1U);

      SchM_Exit_Icu_17_GtmCcu6_EnableNotification();
    }
    #endif
  }
}/* End of Icu_17_GtmCcu6_EnableNotification() function */

/* precompile switch ICU_EDGE_DETECT_API */
/* [cover parentID=DS_AS_ICU367_ICU369_ICU370_ICU374_ICU375]  */
#if (ICU_EDGE_DETECT_API == STD_ON)
/* [/cover] */
/*This API is applicable to Autosar Version 3.2.1 also, based on Bugzila 29022*/
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU364,DS_AS_ICU050_23_ICU368,
   DS_AS_ICU371,DS_AS_ICU243_23_ICU112_23_ICU048_23,DS_AS_ICU366_ICU367,
   DS_AS_ICU022_21,DS_NAS_PR734_23,DS_NAS_PR123_2]

** Syntax : void Icu_17_GtmCcu6_EnableEdgeDetection(                         **
**                                      Icu_17_GtmCcu6_ChannelType Channel   **
**                                     )                                     **
** [/cover]                                                                  **
** Service ID:       22                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : This service will Re enables the ICU signal edge detection  **
**             channel, activation edge depends on either DefaultStartEdge   **
**               Or activation by Icu_17_GtmCcu6_SetActivationCondition API. **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_EnableEdgeDetection(Icu_17_GtmCcu6_ChannelType Channel)
{
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  #if ((ICU_ERU_USED == STD_ON) || (ICU_TIM_SIGEDGE_USED == STD_ON))
  Icu_17_GtmCcu6_ActivationType Edge;
  #endif
  /*   #if ((ICU_ERU_USED == STD_ON) || (ICU_TIM_SIGEDGE_USED == STD_ON)) */
  Icu_17_GtmCcu6_ChannelType CellUsed;
  uint32 ModUsed;
  #if (ICU_ERU_USED == STD_ON)
  Icu_17_GtmCcu6_ChannelType EruEicrChannel;
  Icu_17_GtmCcu6_ChannelType EruLineUsed;
  Icu_17_GtmCcu6_ChannelType EruEicrUsed;
  #endif
 #if  (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag;
#endif  
  #if ((ICU_ERU_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON))
  uint8 PhyChannelIndex; 
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;
  #endif

 #if  (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  /* Verify any error is there for DET */  
  ErrorFlag = Icu_lEnDisEdgeDetectDetCheck(Channel,ICU_SID_ENABLEEDGEDETECTION);

  if (ICU_ERROR_FOUND != ErrorFlag)  
  #endif

  /*   #if  (ICU_DEV_ERROR_DETECT == STD_ON)  */

  {
    #if ((ICU_ERU_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON))  
    LocalIcuMapPtr =   (Icu_kConfigPtr->MappingIndexPtr) + Channel;
    PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap; 
    #endif  
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;

    if (LocalIcuChanPtr->IcuProperties.MeasurementMode 
         == ICU_MODE_SIGNAL_EDGE_DETECT)
    {
      #if ((ICU_ERU_USED == STD_ON) || (ICU_TIM_SIGEDGE_USED == STD_ON))
      /* Configure the Hardware resource as per the configured edges */
      Edge = (Icu_17_GtmCcu6_ActivationType)Icu_17_lGlbIndexStatusExtract(
                                                    Channel,
                                                    ICU_CHNL_EDGE_POS, 
                                              ICU_CHNL_EDGE_BIT_LENGTH);

      #endif
      /*   #if ((ICU_ERU_USED == STD_ON) || (ICU_TIM_SIGEDGE_USED == STD_ON)) */
     Icu_17_lGlbIndexStatusSet(Channel,0U, (uint8)ICU_CHNL_DISABLE_STAT_POS,1U);       

      CellUsed = 
                (Icu_17_GtmCcu6_ChannelType)LocalIcuChanPtr->IcuProperties.
                                                          AssignedHwUnitNumber;

      ModUsed = Icu_lGetChannelType(Channel);
#if ((ICU_MAX_ASIL_GTM_CHANNELS != 0U) || (ICU_MAX_QM_GTM_CHANNELS != 0U))  
      if((ModUsed == ICU_GTM_ASIL_CHANNEL) || (ModUsed == ICU_GTM_QM_CHANNEL))
      {
        #if (ICU_TIM_SIGEDGE_USED == STD_ON)
        /* Stored status of Interrupt Notify bit is cleared */
        Icu_17_lGlbIndexStatusSet(Channel,0U,(uint8)ICU_CHNL_NOTIF_STATUS_POS,1U);
        Icu_lGtmStartEdgeDetect(CellUsed,Edge);
       #endif 
      }
#endif     
      #if (ICU_ASIL_CCU6_SIGEDGE_USED == STD_ON)
      if (ModUsed == ICU_CCU6_ASIL_CHANNEL)
      {
        Icu_lCcuEnableChannel(CellUsed);

        /* the status is put to IDLE */
        Icu_lSetInputStateIdle(
        &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[PhyChannelIndex]); 

      }
      #endif
#if (ICU_QM_CCU6_SIGEDGE_USED == STD_ON)
      if (ModUsed == ICU_CCU6_QM_CHANNEL)
      {
        Icu_lCcuEnableChannel(CellUsed);

        /* the status is put to IDLE */
        Icu_lSetInputStateIdle(
        &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex]); 

      }
#endif
 
/* #if (ICU_CCU6_SIGEDGE_USED == STD_ON) */
      if (ModUsed == ICU_ERU_QM_CHANNEL)
      {
        #if (ICU_ERU_USED == STD_ON)
        EruLineUsed = Icu_lGetEruLine(CellUsed);
        EruEicrUsed = Icu_lGetEruEicr(CellUsed);
        /* Clear Service Request if any was in pending */
        MODULE_SCU.FMR.U = Icu_lClearEruServiceRequest(EruLineUsed);
        EruEicrChannel = Icu_lGetEruEicrChannel(CellUsed);
        /* ICU010: Enable the cell for notification */
        Icu_lSetEruEdge( Edge, EruEicrUsed,EruEicrChannel );
        /* the status is put to IDLE */
        Icu_lSetInputStateIdle(
        &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex]); 
        #endif
      }
      
    }/* End of if condition */    
  }
}/* End of Icu_17_GtmCcu6_EnableEdgeDetection() function */
/*This API is applicable to Autosar Version 3.2.1 also, based on Bugzila 29022*/
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU377,DS_AS_ICU050_22_ICU373,
   DS_AS_ICU376,DS_AS_ICU243_22_ICU112_22_ICU048_22,
   DS_AS_ICU372,DS_NAS_PR734_22,DS_NAS_PR123_1]
** Syntax : void Icu_17_GtmCcu6_DisableEdgeDetection(                        **
**                                      Icu_17_GtmCcu6_ChannelType Channel   **
**                                     )                                     **
**                                                                           **
** [/cover]                                                                  **
** Service ID:       23                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : This service will disable the ICU signal edge detection     **
**               channel.                                                    **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_DisableEdgeDetection(Icu_17_GtmCcu6_ChannelType Channel)
{
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  Icu_17_GtmCcu6_ChannelType CellUsed; 
  uint32 ModUsed; 
  #if (ICU_ERU_USED == STD_ON) 
  Icu_17_GtmCcu6_ChannelType EruEicrChannel;
  Icu_17_GtmCcu6_ChannelType EruLineUsed;
  Icu_17_GtmCcu6_ChannelType EruEicrUsed;
  #endif
  #if  (ICU_DEV_ERROR_DETECT == STD_ON)|| (ICU_SAFETY_ENABLE == STD_ON)
  /* Verify any error is there for DET */  
  uint32 ErrorFlag;

  ErrorFlag =Icu_lEnDisEdgeDetectDetCheck(Channel,ICU_SID_DISABLEEDGEDETECTION);


  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
  {
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;

    if (LocalIcuChanPtr->IcuProperties.MeasurementMode 
         == ICU_MODE_SIGNAL_EDGE_DETECT)
    {

     Icu_17_lGlbIndexStatusSet(Channel,1U, (uint8)ICU_CHNL_DISABLE_STAT_POS,1U);   

      CellUsed =                                                               \
             (Icu_17_GtmCcu6_ChannelType)LocalIcuChanPtr->IcuProperties.
                                                          AssignedHwUnitNumber;

      ModUsed = LocalIcuChanPtr->IcuProperties.AssignedHwUnit;

      if(ModUsed ==  ICU_GTM_OPTION)
      {
        #if (ICU_TIM_SIGEDGE_USED == STD_ON)    
        Icu_lGtmStopEdgeDetect(CellUsed);
        #endif
      }
      #if (ICU_CCU6_SIGEDGE_USED == STD_ON)
      else if (ModUsed == ICU_CCU_OPTION)
      {
        Icu_lCcuDisableChannel(CellUsed);

      }
      #endif
/* #if (ICU_CCU6_SIGEDGE_USED == STD_ON) */      
      else
      {
        #if (ICU_ERU_USED == STD_ON)    
        /* Extract proper Eru Line */
        EruLineUsed = Icu_lGetEruLine(CellUsed);
        EruEicrUsed    = Icu_lGetEruEicr(CellUsed);
        EruEicrChannel = Icu_lGetEruEicrChannel(CellUsed);
        /* Clear Service Request if any was in pending */
        MODULE_SCU.FMR.U = Icu_lClearEruServiceRequest(EruLineUsed);
        Icu_lSetEruEdge( (Icu_17_GtmCcu6_ActivationType)ICU_NO_EDGE, 
                          EruEicrUsed, EruEicrChannel);

        #endif
      }
        
    }/* End of if condition */          
  }
}/* End of Icu_17_GtmCcu6_DisableEdgeDetection() function */
#endif
/* #if (ICU_EDGE_DETECT_API == STD_ON) */

/*ICU122 : precompile switch ICU_GET_INPUT_STATE_API */
/* [cover parentID=DS_AS_ICU315_ICU122] */
#if (ICU_GET_INPUT_STATE_API == STD_ON)
/* [/cover] */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU200,DS_AS_ICU050_9_ICU312,
   DS_AS_ICU022_8,DS_AS_ICU162,DS_AS_ICU243_9_ICU112_9_ICU048_9,DS_AS_ICU313,
   DS_AS_ICU030,DS_AS_ICU031_1_ICU032_1,DS_AS_ICU049,DS_NAS_PR734_9]

** Syntax :Icu_17_GtmCcu6_InputStateType Icu_17_GtmCcu6_GetInputState        **
**                                     (Icu_17_GtmCcu6_ChannelType Channel)  **
** [/cover]                                                                  **
**                                                                           **
** Service ID:       0x8                                                     **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     Status (Icu_17_GtmCcu6_InputStateType) -                **
**                   Returns the state of                                    **
**                   Channel                                                 **
**                                                                           **
** Description : 1. This service returns the status of the ICU input.        **
**               2. If an activation edge has been detected this service will**
**                  return ICU_ACTIVE.                                       **
**               3. Once the service has returned the status ICU_ACTIVE the  **
**                  stored status will be set to ICU_IDLE until the next     **
**                  edge is detected.                                        **
**               4. If no  edge has been detected this service will          **
**                  return ICU_IDLE.                                         **
**               5. If development error detection is enabled and an error is**
**                  detected the service returns ICU_IDLE.                   **
**               6. Signal edge detection channels                           **
**                  channels status is changed here.                         **
**               7. For a signal measurement channel only the status         **
**                  is returned and its not put to IDLE. A successful read   **
**                  of Icu_17_GtmCcu6_GetTimeElapsed or                      **
**                  Icu_17_GtmCcu6_GetDutyCycleValues                        **
**                  will set the state to ICU_IDLE                           **
**                                                                           **
*****************************************************************************/
Icu_17_GtmCcu6_InputStateType Icu_17_GtmCcu6_GetInputState                   \
                        (Icu_17_GtmCcu6_ChannelType Channel)
{
  Icu_17_GtmCcu6_InputStateType Status;
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr;
  uint32 AssignedHwUnit;
  uint8 ChlType;
  #if (ICU_GTM_TIM_USED == STD_ON)
  Icu_17_GtmCcu6_ChannelType CellUsed;
  #endif
  uint8 PhyChannelIndex;
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr; 

  #if  (ICU_DEV_ERROR_DETECT ==  STD_ON)|| (ICU_SAFETY_ENABLE == STD_ON)
  /* Verify any error is there for DET */  
  uint32 ErrorFlag;
  #endif  
  
  #if ((ICU_MAX_ASIL_GTM_CHANNELS != 0U) || (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)\
      || (ICU_MAX_QM_CHANNELS != 0U))     
  uint32 *Ptr = NULL_PTR;
#endif 


  #if  (ICU_DEV_ERROR_DETECT ==  STD_ON)|| (ICU_SAFETY_ENABLE == STD_ON)
  ErrorFlag = Icu_lGetInputStateDetCheck( Channel );
  #endif
  Status = ICU_IDLE;
  #if  (ICU_DEV_ERROR_DETECT ==  STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  if (ICU_ERROR_FOUND != ErrorFlag)  
  #endif
  /*   #if  (ICU_DEV_ERROR_DETECT ==  STD_ON) */
  {

    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;
    AssignedHwUnit = (uint32)LocalIcuChanPtr->IcuProperties.AssignedHwUnit;
    ChlType = Icu_lGetChannelType(Channel);
    LocalIcuMapPtr =   (Icu_kConfigPtr->MappingIndexPtr) + Channel;
    PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap;

    
    #if (ICU_GTM_TIM_USED == STD_ON)    
    /* Extract the actual cell number */
    CellUsed = (uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
    #endif

    switch (ChlType)
    { 
      case ICU_GTM_ASIL_CHANNEL:  
      #if (ICU_MAX_ASIL_GTM_CHANNELS != 0U)         
      Ptr = &Icu_17_GtmCcu6_AsilGtmVarlist.GlbIndexStatus[PhyChannelIndex];
      #endif 
      break;
      case ICU_CCU6_ASIL_CHANNEL:
      #if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)       
      Ptr = &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[PhyChannelIndex];
      #endif
      break;
      default:
      #if (ICU_MAX_QM_CHANNELS != 0U)
      Ptr = &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex];
      #endif
      break;       
    }
    #if ((ICU_MAX_ASIL_GTM_CHANNELS != 0U) || (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)\
      || (ICU_MAX_QM_CHANNELS != 0U))       
    if(Mcal_Extract(*Ptr, 
                        ICU_CHNL_STATUS_POS,
                        ICU_CHNL_STATUS_BIT_LENGTH))
    {
       /* ICU032: Make Channel Status IDLE */    
       Icu_lSetInputStateIdle(Ptr);
       Status = ICU_ACTIVE;
    }
    #endif    
    if(AssignedHwUnit == ICU_GTM_OPTION)
    {
    #if (ICU_GTM_TIM_USED == STD_ON)    
      if (LocalIcuChanPtr->IcuProperties.MeasurementMode 
                                                == ICU_MODE_SIGNAL_EDGE_DETECT)
      {
        #if((ICU_EDGE_DETECT_API == STD_ON) && (ICU_TIM_SIGEDGE_USED == STD_ON))
        Status = Icu_lGtmGetInputStateEdgeDetect(
                             CellUsed,
                             PhyChannelIndex,
                             ChlType);
        
        #endif
      }
      #if (ICU_TIM_SIGMEAS_USED == STD_ON)
      else
      {
        Status = Icu_lGtmGetInputStateSigMeas(
                             CellUsed, 
                             Channel,ChlType);
      }
      #endif
    #endif      
/* #if (ICU_TIM_SIGMEAS_USED == STD_ON) */
    }
/* #if ((ICU_GTM_TIM_USED == STD_ON) */
  }
  /*#if ((ICU_GTM_TIM_USED == STD_ON)&&(ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/
  
  /* ICU030: ICU033: This service returns the status of the ICU input*/
  return (Status);
}/* End of function Icu_17_GtmCcu6_GetInputState */
#endif

/* ICU098, ICU066 check for the configuration API */ 
/* ICU099 configuration check for Icu_17_GtmCcu6_StopTimestamp API */
/* ICU100 configuration check for Icu_17_GtmCcu6_GetTimestampIndex API */
/* [cover parentID=DS_AS_ICU066_ICU165_ICU170][/cover] */
#if (ICU_TIMESTAMP_API == STD_ON)
/* [/cover] */
/* [cover parentID=DS_AS_ICU099_ICU323_ICU100_ICU325_ICU098_ICU321] 
 [/cover] */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU201,DS_AS_ICU050_10_ICU316,
   DS_AS_ICU022_9,DS_AS_ICU163,DS_AS_ICU120,DS_AS_ICU108,DS_AS40X_ICU354,
   DS_AS_ICU243_10_ICU112_10_ICU048_10,DS_NAS_PR734_10]

** Syntax :void Icu_17_GtmCcu6_StartTimestamp( 
**                                  Icu_17_GtmCcu6_ChannelType Channel ,     **
**                                  Icu_17_GtmCcu6_ValueType *BufferPtr,     **
**                                  uint16         BufferSize,               **
**                                             uint16 NotifyInterval )       **
** [/cover]                                                                  **
**                                                                           **
** Service ID:       0x09                                                    **
**                                                                           **
** Sync/Async:       Asynchronous                                            **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                   BufferSize    : Size of the Buffer                      **
**                   NotifyInterval: Interval for Timestamp Notifications    **
**                                                                           **
** Parameters (out):                                                         **
**                   BufferPtr     : Starting address of Buffer, that will   **
**                                   hold the timer capture values           **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1. This service will start the TimeStamp Capture.           **
**               2. This service will also set the Notification Flag, if     **
**                  NotifyInterval is greater than zero.                     **
**               3. The Notifications is  done in ISR Only.                  **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_StartTimestamp(
                            Icu_17_GtmCcu6_ChannelType Channel, 
                            Icu_17_GtmCcu6_ValueType *BufferPtr, 
                            uint16 BufferSize, 
                            uint16 NotifyInterval
                          )
{
  /*ICU063: Service to capture Timestamp values */
  /*ICU134: Notify interval should be greater than zero to enable notification
            as per bugzilla Icu_EnableNotificaiton should also be called */
  uint32 ChIndex; /* Local Ram Index */
   #if((ICU_ASIL_TIM_TIMESTAMP_USED == STD_ON) ||  \
     (ICU_QM_TIM_TIMESTAMP_USED == STD_ON))  
  Icu_TimeCaptureParasType *TimePtr;
  #endif
  Icu_17_GtmCcu6_ActivationType Edge;
  /* Local pointers */
  Icu_17_GtmCcu6_ChannelType CellUsed;
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr; 
#if ((ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON))
   uint32 ErrorFlag;
 #endif
#if (ICU_SAFETY_ENABLE == STD_ON)  
  uint8 ChlType;
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanBufPtr; /* ROM pointer */ 
#endif 
    
  #if ((ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON))
  /* Verify any error is there for DET */    
  ErrorFlag = Icu_lNotifiDetCheck(Channel,
                                 ICU_SID_STARTTIMESTAMP,
                                 ICU_MODE_TIMESTAMP);
  if (ICU_ERROR_FOUND != ErrorFlag)
  {
    /* ICU120 , check for invalid pointer */
    if (BufferPtr == (Icu_17_GtmCcu6_ValueType*)0)
    {
      ErrorFlag = ICU_ERROR_FOUND;
     #if (ICU_DEV_ERROR_DETECT == STD_ON)  
      Det_ReportError( 
                     ICU_17_GTMCCU6_MODULE_ID,
                     ICU_17_GTMCCU6_INSTANCE_ID,
                     ICU_SID_STARTTIMESTAMP,
                     ICU_E_PARAM_BUFFER_PTR
                   ); /* Report to  DET */
     #endif
      #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ICU_SID_STARTTIMESTAMP,ICU_E_PARAM_BUFFER_PTR);
      #endif    
    }
    /* ICU108, check for invalid size */
    else if (BufferSize == 0U)
    {
      ErrorFlag = ICU_ERROR_FOUND;
     #if (ICU_DEV_ERROR_DETECT == STD_ON)  
      Det_ReportError( 
                     ICU_17_GTMCCU6_MODULE_ID,
                     ICU_17_GTMCCU6_INSTANCE_ID,
                     ICU_SID_STARTTIMESTAMP,
                     ICU_E_PARAM_BUFFER_SIZE
                   ); /* Report to  DET */
      #endif
      #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ICU_SID_STARTTIMESTAMP,ICU_E_PARAM_BUFFER_SIZE);
      #endif 
    }    
    /* ICU354, check for invalid NotifyInterval */
    else if (NotifyInterval == 0U)
    {
      ErrorFlag = ICU_ERROR_FOUND;
     #if (ICU_DEV_ERROR_DETECT == STD_ON)  
      Det_ReportError( 
                     ICU_17_GTMCCU6_MODULE_ID,
                     ICU_17_GTMCCU6_INSTANCE_ID,
                     ICU_SID_STARTTIMESTAMP,
                     ICU_E_PARAM_NOTIFY_INTERVAL
                   ); /* Report to  DET */
    #endif
      #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                           ICU_SID_STARTTIMESTAMP,ICU_E_PARAM_NOTIFY_INTERVAL);
      #endif   
    }
    else
    {
      /*Do Nothing*/
    }   
  }

 #if (ICU_SAFETY_ENABLE == STD_ON)
  if (ICU_ERROR_FOUND != ErrorFlag)
  {
    ChlType = Icu_lGetChannelType(Channel);  
    LocalIcuChanBufPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;      
    if(ChlType ==  ICU_GTM_ASIL_CHANNEL)
    {
      /* ICU120 , check for invalid pointer */
      if (BufferPtr[0] != LocalIcuChanBufPtr->IcuProperties.BufferMarker)
      {
        ErrorFlag = ICU_ERROR_FOUND;
        /* Report an error */
        SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ICU_SID_STARTTIMESTAMP,ICU_E_PARAM_BUFFER_PTR);

      }
    }  
    /* ICU354, check for invalid NotifyInterval */
    if ((NotifyInterval > BufferSize))
    {
      ErrorFlag = ICU_ERROR_FOUND;
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ICU_SID_STARTTIMESTAMP,ICU_E_PARAM_NOTIFY_INTERVAL);

    }
  }   
  #endif
  
  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
  {
    /* Retrieve the Index stored in IndexStore */
    LocalIcuMapPtr = (Icu_kConfigPtr->MappingIndexPtr) + Channel;      
    ChIndex = LocalIcuMapPtr->ChannelIndexMap;
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;     
#if (ICU_SAFETY_ENABLE == STD_ON) 
   ChlType = Icu_lGetChannelType(Channel); 
   if(ChlType ==  ICU_GTM_ASIL_CHANNEL)
   {
#if (ICU_ASIL_TIM_TIMESTAMP_USED == STD_ON)   
    /* Store the address in a pointer variable */
    TimePtr = &Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex];
#endif 
   }
   else
#endif
   {
    #if(ICU_QM_TIM_TIMESTAMP_USED == STD_ON)
    /* Store the address in a pointer variable */
    TimePtr = &Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex];
    #else
    TimePtr = NULL_PTR;
   #endif 
   } 
   
    #if((ICU_ASIL_TIM_TIMESTAMP_USED == STD_ON) || \
     (ICU_QM_TIM_TIMESTAMP_USED == STD_ON))
    /* ICU109 pointer to Buffer Pointer where values to be stored */
    TimePtr->Address = BufferPtr;
    /* Initialize the counter to zero */
    TimePtr->Counter = (uint16)0U;
    /* Initialize the Buffer size */
    TimePtr->Size = BufferSize;
    /* As per bugzilla 11480 the notification flag
      shall be enabled in Icu_17_GtmCcu6_EnableNotification API */
    /* Initialize the Notify Interval to the structure member Notify */
    TimePtr->Notify = NotifyInterval;
    /* Notify Counter is also initialized with NotifyInterval,This value will be
      changed to monitor the no of counters in order to fire the Notifications*/
    TimePtr->NotifyCounter = NotifyInterval;
    #endif
    /* Set the ICU_ACTIVITY_STARTED flag */
    Icu_17_lGlbIndexStatusSet(Channel,ICU_ACTIVITY_STARTED,
            ICU_CHNL_ACTIVITY_STARTED_POS,1U);
    /* Configure the Hardware resource as per the configured edges */
    Edge = (Icu_17_GtmCcu6_ActivationType)Icu_17_lGlbIndexStatusExtract(
                                            Channel,
                                            ICU_CHNL_EDGE_POS,
                                            ICU_CHNL_EDGE_BIT_LENGTH);

    /* Extract the actual cell number */
    CellUsed = 
           (Icu_17_GtmCcu6_ChannelType)LocalIcuChanPtr->IcuProperties.
                                                          AssignedHwUnitNumber;
    /* Start the TIM Channel */
    Icu_lGtmStartTimeStamp(CellUsed,Edge);
  }
}/* End of function Icu_17_GtmCcu6_StartTimestamp */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU202,DS_AS_ICU050_11_ICU322,
   DS_AS_ICU022_10,DS_AS_ICU166,DS_AS_ICU164,DS_AS_ICU168,
   DS_AS_ICU243_11_ICU112_11_ICU048_11,DS_NAS_PR734_11]

** Syntax :           void Icu_17_GtmCcu6_StopTimestamp(                     **
**                                    Icu_17_GtmCcu6_ChannelType Channel )   **
**                                                                           **
** [/cover]                                                                  **
** Service ID:       0x0A                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out):                                                         **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1. This service will stop the TimeStamp Capture.            **
**               2. This service will also deactivate the interrupt flags.   **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_StopTimestamp(
                          Icu_17_GtmCcu6_ChannelType Channel
                         )
{
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  Icu_17_GtmCcu6_ChannelType CellUsed;

  /* ICU067 : Service to stop the Timestamp Measurement */
#if ((ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON))
  uint32 ErrorFlag = 0U;

  /* Verify any error is there for DET */  
  ErrorFlag = Icu_lNotifiDetCheck(Channel,
                                 ICU_SID_STOPTIMESTAMP,
                                 ICU_MODE_TIMESTAMP);
  if (ICU_ERROR_FOUND != ErrorFlag)
  {
    /* ICU132 : TO check for active channels */
    if (((uint8)(Icu_17_lGlbIndexStatusExtract(Channel,
                 ICU_CHNL_ACTIVITY_STARTED_POS,ICU_CHNL_ACTIVITY_BIT_LENGTH))
                 != ICU_ACTIVITY_STARTED))
    {
      ErrorFlag = ICU_ERROR_FOUND;
      #if (ICU_DEV_ERROR_DETECT == STD_ON)    
      Det_ReportError( 
                     ICU_17_GTMCCU6_MODULE_ID,
                     ICU_17_GTMCCU6_INSTANCE_ID,
                     ICU_SID_STOPTIMESTAMP,
                     ICU_E_NOT_STARTED
                   ); /* Report to  DET */
      #endif    
    }

  }

  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif

  {
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;
    /* Extract the actual cell number */
    CellUsed = 
          (Icu_17_GtmCcu6_ChannelType)LocalIcuChanPtr->IcuProperties.
                                                         AssignedHwUnitNumber;
    /* Deactivate the edges */
    Icu_lGtmStopTimeStamp(CellUsed);
    /* Activity Start flag is set to zero */
#if ((ICU_ASIL_TIM_TIMESTAMP_USED == STD_ON) || \
              (ICU_QM_TIM_TIMESTAMP_USED == STD_ON))
    Icu_17_lGlbIndexStatusSet(Channel,0U,ICU_CHNL_ACTIVITY_STARTED_POS,1U);

#endif
   }  
}/* End of function Icu_17_GtmCcu6_StopTimestamp */
#if (ICU_TIM_TIMSTMP_USED == STD_ON)
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU203,DS_AS_ICU050_12_ICU324,
   DS_AS_ICU022_11,DS_AS_ICU169,DS_AS_ICU243_12_ICU112_12_ICU048_12,
   DS_AS_ICU071,DS_AS_ICU107,DS_AS_ICU135,DS_NAS_PR734_12]

** Syntax :Icu_17_GtmCcu6_IndexType Icu_17_GtmCcu6_GetTimestampIndex(        **
**                                        Icu_17_GtmCcu6_ChannelType Channel **
**                                                      )                    **
** [/cover]                                                                  **
** Service ID:       0x0B                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out):                                                         **
**                                                                           **
** Return value:     Icu_17_GtmCcu6_IndexType                                **
**                                                                           **
** Description : 1. This service will return the next index of the           **
**                  Buffer that will be written by the ISR.                  **
**               2. In case of a liner buffer and the buffer is filled the   **
**                  service will returns buffer size.                        **
**                                                                           **
*****************************************************************************/
Icu_17_GtmCcu6_IndexType Icu_17_GtmCcu6_GetTimestampIndex(
                                         Icu_17_GtmCcu6_ChannelType Channel)
{
  uint32 ChIndex;
  Icu_17_GtmCcu6_IndexType RetVal = 0U;
#if (ICU_SAFETY_ENABLE == STD_ON)  
  uint8 ChlType;
#endif  
 const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;
 
  #if (ICU_DEV_ERROR_DETECT == STD_ON)|| (ICU_SAFETY_ENABLE == STD_ON) 
  uint32 ErrorFlag;

  /* Verify any error is there for DET */  
  ErrorFlag = Icu_lNotifiDetCheck(Channel,
                                  ICU_SID_GETTIMESTAMPINDEX,
                                  ICU_MODE_TIMESTAMP);
  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
  /* #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    LocalIcuMapPtr = (Icu_kConfigPtr->MappingIndexPtr) + Channel;      
    ChIndex = LocalIcuMapPtr->ChannelIndexMap;  
#if (ICU_SAFETY_ENABLE == STD_ON) 
    ChlType = Icu_lGetChannelType(Channel); 
    if(ChlType ==  ICU_GTM_ASIL_CHANNEL)
    {
#if (ICU_ASIL_TIM_TIMESTAMP_USED == STD_ON) 
    RetVal = ((Icu_17_GtmCcu6_IndexType)
               Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].Counter);
#endif 
    }
    else
#endif 
    {
#if (ICU_QM_TIM_TIMESTAMP_USED == STD_ON) 
    RetVal = ((Icu_17_GtmCcu6_IndexType)
               Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].Counter);
#endif
    } 
  /* ICU100 : API under configuration ICU_TIMESTAMP_API */
  /* ICU071 : to return the next index to be written */
  /* The counter is set to zero in Icu_17_GtmCcu6_Init to take care of ICU135 */
  }

  #if (ICU_DEV_ERROR_DETECT == STD_ON)|| (ICU_SAFETY_ENABLE == STD_ON)
  else
  {
    /* ICU048: Return without executing any of functionality */
    /* ICU107: To return zero */
    RetVal = ((Icu_17_GtmCcu6_IndexType)0U);
  }
  #endif

  /* #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  
  return(RetVal);
}/* End of function Icu_17_GtmCcu6_GetTimestampIndex */
/* End of function Icu_17_GtmCcu6_GetTimestampIndex */
#endif
#endif
/* End of #if (ICU_TIMESTAMP_API == STD_ON) */

/*ICU101: configuration switch Icu_17_GtmCcu6_ResetEdgeCount */
/*ICU102: configuration switch Icu_17_GtmCcu6_EnableEdgeCount */
/*ICU103: configuration switch Icu_17_GtmCcu6_DisableEdgeCount */
/*ICU104: configuration switch Icu_17_GtmCcu6_GetEdgeNumbers */
/* [cover parentID=DS_AS_ICU101_ICU327_ICU074_ICU102_ICU329]  */
#if (ICU_EDGE_COUNT_API == STD_ON)
/* [/cover] */
/* [cover parentID=DS_AS_ICU331_ICU103_ICU104_ICU333]  
[/cover] */

/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU204,DS_AS_ICU050_13_ICU326,
   DS_AS_ICU022_12,DS_AS_ICU171,DS_AS_ICU243_13_ICU112_13_ICU048_13,
   DS_AS_ICU072,DS_NAS_PR734_13]

** Syntax :          void Icu_17_GtmCcu6_ResetEdgeCount(                     **
**                                    Icu_17_GtmCcu6_ChannelType Channel )   **
**                                                                           **
** [/cover]                                                                  **
** Service ID:       0x0C                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out):                                                         **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : This service will set the edge counter variable to zero.    **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_ResetEdgeCount(Icu_17_GtmCcu6_ChannelType Channel)
{
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  Icu_17_GtmCcu6_ChannelType CellUsed;
  uint32 ChIndex;
 const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;  


  /* Initialize Global channel RAM pointer */
  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag;

  /* ICU024: Verify any error is there for DET */  
  ErrorFlag = Icu_lNotifiDetCheck(Channel,
                                  ICU_SID_RESETEDGECOUNT,
                                  ICU_MODE_EDGE_COUNTER);
   

  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
/* #if (ICU_DEV_ERROR_DETECT == STD_ON) */

  {
    /* Channel Pointer is extracted */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;

     /* Retrieve the Channel Index */
    LocalIcuMapPtr = (Icu_kConfigPtr->MappingIndexPtr) + Channel;      
    ChIndex =LocalIcuMapPtr->ChannelIndexMap;                 
    /* Extract the actual cell number */
    CellUsed = 
           (Icu_17_GtmCcu6_ChannelType)LocalIcuChanPtr->IcuProperties.
                                                         AssignedHwUnitNumber;
    
    /* Suspend all the interrupts */
    /*ICU072 : reset the values to 0 */
    SchM_Enter_Icu_17_GtmCcu6_ResetEdgeCount();
    /* Work on depending on ICU option chosen for each channel */
#if (ICU_ASIL_TIM_EDGECNT_USED == STD_ON)
    if(LocalIcuChanPtr->IcuProperties.SignalType == ICU_ASIL_SIGNAL)
    { 
      /* Set the Hardware counter to zero */
    Icu_lGtmResetEdgeCount(CellUsed,
         &Icu_17_GtmCcu6_AsilGtmVarlist.EdgeCountValuePtr[ChIndex]);
    } 
    else
#endif 
    {
#if (ICU_QM_TIM_EDGECNT_USED == STD_ON) 
      /* Set the Hardware counter to zero */
    Icu_lGtmResetEdgeCount(CellUsed,
             &Icu_17_GtmCcu6_QmVarlist.EdgeCountValuePtr[ChIndex]);
#endif
    }        
    /* Resume all the interrupts */
    SchM_Exit_Icu_17_GtmCcu6_ResetEdgeCount();
  }

}/* End of function Icu_17_GtmCcu6_ResetEdgeCount */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU205,DS_AS_ICU050_14_ICU328,
   DS_AS_ICU022_13,DS_AS_ICU172,DS_AS_ICU243_14_ICU112_14_ICU048_14,
   DS_AS_ICU078,DS_AS_ICU073,DS_NAS_PR734_14]
** Syntax :          void Icu_17_GtmCcu6_EnableEdgeCount(                    **
**                                     Icu_17_GtmCcu6_ChannelType Channel )  **
**                                                                           **
** [/cover]                                                                  **
** Service ID:       0x0D                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out):                                                         **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1. This service shall start the edge count mode.            **
**       2. The index of the channel is initialized in Icu_17_GtmCcu6_Init.  **
**               3. Icu_ActivityStarted Flag is set to true.                 **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_EnableEdgeCount(Icu_17_GtmCcu6_ChannelType Channel)
{
  /*ICU078: service to enable edge count measurement */
  /*ICU074: service available for edge count measurement */
  /*ICU102 : API available only in configuration ICU_EDGE_COUNT_API */
  uint32 ChIndex;
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  Icu_17_GtmCcu6_ChannelType CellUsed;  
  Icu_17_GtmCcu6_ActivationType Edge;
 const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;  

  #if (ICU_DEV_ERROR_DETECT  == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag; 

  /* ICU024: Verify any error is there for DET */  
  ErrorFlag = Icu_lNotifiDetCheck(Channel,
                                  ICU_SID_ENABLEEDGECOUNT,
                                  ICU_MODE_EDGE_COUNTER);

  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
  /* #if (ICU_DEV_ERROR_DETECT  == STD_ON) */

  {
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;
    CellUsed=
           (Icu_17_GtmCcu6_ChannelType)LocalIcuChanPtr->IcuProperties.
                                                         AssignedHwUnitNumber;  
   Icu_17_lGlbIndexStatusSet(Channel,ICU_ACTIVITY_STARTED,
                           ICU_CHNL_ACTIVITY_STARTED_POS,1U);
    /*  ICU073  configured edges are available in Icu_ActivationEdge*/
    Edge = Icu_17_lGlbIndexStatusExtract(Channel,
                ICU_CHNL_EDGE_POS,ICU_CHNL_EDGE_BIT_LENGTH);
    /* Retrieve chindex */
    LocalIcuMapPtr = (Icu_kConfigPtr->MappingIndexPtr) + Channel; 
    ChIndex = LocalIcuMapPtr->ChannelIndexMap;

    if(LocalIcuChanPtr->IcuProperties.SignalType == ICU_ASIL_SIGNAL)
    {
    #if (ICU_ASIL_TIM_EDGECNT_USED == STD_ON)    
    Icu_lGtmEnableEdgeCount(CellUsed, Edge, 
       &Icu_17_GtmCcu6_AsilGtmVarlist.EdgeCountValuePtr[ChIndex]);
    #endif         
    }
    else 
    {
#if (ICU_QM_TIM_EDGECNT_USED == STD_ON) 
    Icu_lGtmEnableEdgeCount(CellUsed, Edge, 
            &Icu_17_GtmCcu6_QmVarlist.EdgeCountValuePtr[ChIndex]);
#endif
    } 
  }
}  
/* End of function Icu_17_GtmCcu6_EnableEdgeCount */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU206,DS_AS_ICU050_15_ICU330,
   DS_AS_ICU022_14,DS_AS_ICU173,DS_AS_ICU243_15_ICU112_15_ICU048_15,
   DS_NAS_PR734_15]

** Syntax :          void Icu_17_GtmCcu6_DisableEdgeCount(                   **
**                                      Icu_17_GtmCcu6_ChannelType Channel ) **
**                                                                           **
** [/cover]                                                                  **
** Service ID:       0x0E                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out):                                                         **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1. This service will stop the edge counting capability      **
**                  of a channel.                                            **
**                                                                           **
*****************************************************************************/
void Icu_17_GtmCcu6_DisableEdgeCount(Icu_17_GtmCcu6_ChannelType Channel)
{
  /*ICU079: service to disable the edge count */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  Icu_17_GtmCcu6_ChannelType CellUsed;

  #if (ICU_DEV_ERROR_DETECT == STD_ON)|| (ICU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag;

  /* ICU024: Verify any error is there for DET */  
  ErrorFlag = Icu_lNotifiDetCheck(Channel, 
                                  ICU_SID_DISABLEEDGECOUNT,
                                  ICU_MODE_EDGE_COUNTER);
   
  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
  /* #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;
    
    CellUsed=
         (Icu_17_GtmCcu6_ChannelType)LocalIcuChanPtr->
                                            IcuProperties.AssignedHwUnitNumber;
    
    /* Deactivate the edges for configured HW resource */
    Icu_lGtmDisableEdgeCount(CellUsed);
    /* Stop the activity started flag */
    /* bit 5 is activity started status */
    Icu_17_lGlbIndexStatusSet(Channel,0U,ICU_CHNL_ACTIVITY_STARTED_POS,1U);
  }
}/* End of function Icu_17_GtmCcu6_DisableEdgeCount */

/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU207,DS_AS_ICU050_16_ICU332,
   DS_AS_ICU022_15,DS_AS_ICU175,DS_AS_ICU174,
   DS_AS_ICU243_16_ICU112_16_ICU048_16,DS_NAS_PR734_16]

** Syntax :Icu_17_GtmCcu6_EdgeNumberType Icu_17_GtmCcu6_GetEdgeNumbers(      **
**                                       Icu_17_GtmCcu6_ChannelType Channel )**
**                                                                           **
** [/cover]                                                                  **
** Service ID:       0x0F                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out):                                                         **
**                                                                           **
** Return value:     Icu_17_GtmCcu6_EdgeNumberType                           **
**                                                                           **
** Description : 1. This service will return the number of edges counted     **
**                  for the channel specified.                               **
*****************************************************************************/
Icu_17_GtmCcu6_EdgeNumberType Icu_17_GtmCcu6_GetEdgeNumbers
                                          (Icu_17_GtmCcu6_ChannelType Channel)
{
  /*ICU080 Service to return the edge numbers */
  /*ICU104 Configuration ICU_EDGE_COUNT_API  */
  uint32 ChIndex;
  Icu_17_GtmCcu6_EdgeNumberType RetVal = (Icu_17_GtmCcu6_EdgeNumberType)0;
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  Gtm_GlobalChannelNumberType CellUsed;
 const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;   
  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag;
  #endif  
    
  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)  
  /* Verify any error is there for DET */     
  ErrorFlag = Icu_lNotifiDetCheck(Channel,
                                  ICU_SID_GETEDGENUMBERS,
                                  ICU_MODE_EDGE_COUNTER);
   
  
  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
  /* #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  {

    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;
    /* Extract the actual cell number */
    CellUsed= (Gtm_GlobalChannelNumberType) \
               LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
    /* Extract the channel Index */  
       /* Retrieve the Index stored in IndexStore */
    LocalIcuMapPtr = (Icu_kConfigPtr->MappingIndexPtr) + Channel;      
    ChIndex = LocalIcuMapPtr->ChannelIndexMap;    
   /* ChIndex = Icu_17_lGlbIndexStatusExtract(Channel,ICU_CHNL_INDEX_STORE_POS,
                                             ICU_CHNL_INDEX_BIT_LENGTH); */

#if (ICU_ASIL_TIM_EDGECNT_USED == STD_ON) 
    if(LocalIcuChanPtr->IcuProperties.SignalType == ICU_ASIL_SIGNAL)
    {
    /* Call function Icu_lGtmGetEdgeNumbers to get edge numbers */
    RetVal =  Icu_lGtmGetEdgeNumbers(CellUsed,
                &Icu_17_GtmCcu6_AsilGtmVarlist.EdgeCountValuePtr[ChIndex]);
    }
    else
#endif 
    {
#if (ICU_QM_TIM_EDGECNT_USED == STD_ON) 
    /* Call function Icu_lGtmGetEdgeNumbers to get edge numbers */
    RetVal =  Icu_lGtmGetEdgeNumbers(CellUsed,
                   &Icu_17_GtmCcu6_QmVarlist.EdgeCountValuePtr[ChIndex]);
#else
    RetVal = (Icu_17_GtmCcu6_EdgeNumberType)0;               
#endif
   }
  }
  #if (ICU_DEV_ERROR_DETECT == STD_ON)  
  else
  {
    /* ICU107 , ICU048: Return without executing any of functionality */
    RetVal = (Icu_17_GtmCcu6_EdgeNumberType)0;    
  }
  #endif  
  /*   #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  return (RetVal);
}/* End of function Icu_17_GtmCcu6_GetEdgeNumbers */
/* End of function Icu_17_GtmCcu6_GetEdgeNumbers */
#endif
/* End of #if (ICU_EDGE_COUNT_API == STD_ON) */

/* [cover parentID=DS_AS_ICU141_ICU144_ICU142_ICU335_ICU145_ICU337]  */
 #if (ICU_SIGNAL_MEASUREMENT_API == STD_ON) 
/* [/cover] */
/* ICU142 : Configuration of API Service */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU208,DS_AS_ICU050_17_ICU334,
   DS_AS_ICU022_16,DS_AS_ICU176,DS_AS_ICU243_17_ICU112_17_ICU048_17,
   DS_AS_ICU140_ICU141_ICU146,DS_NAS_PR734_17]

** Syntax :          void Icu_17_GtmCcu6_StartSignalMeasurement (            **
**                                       Icu_17_GtmCcu6_ChannelType Channel) **
** [/cover]                                                                  **
** Service ID:       0x13                                                    **
**                                                                           **
** Sync/Async:       Asynchronous                                            **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  None                                                    **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1. This service starts the measurement of signals beginning **
**                  with the configured default start edge which occurs first**
**                  after the call of this service.                          **
******************************************************************************/
void Icu_17_GtmCcu6_StartSignalMeasurement(Icu_17_GtmCcu6_ChannelType Channel)
{
  Icu_17_GtmCcu6_ChannelType CellUsed;
  Icu_17_GtmCcu6_ActivationType CfgEdge = 0U;
  #if(ICU_TIM_SIGMEAS_USED == STD_ON)
  Icu_17_GtmCcu6_SignalMeasurementPropertyType GtmSigKind;
  #endif
/* #if(ICU_TIM_SIGMEAS_USED == STD_ON) */
  /* Local pointers */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  Icu_17_GtmCcu6_SignalMeasurementPropertyType SigKind = 0U;
  uint32 ChlType;
 #if (ICU_TIM_SIGMEAS_USED == STD_ON) || (ICU_CCU6_SIGMEAS_USED == STD_ON)
  uint32 DutyIndex;
#endif  
#if (ICU_CCU6_SIGMEAS_USED == STD_ON)
 uint8 PhyChannelIndex;
#endif
 const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr; 

  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag;

  /* ICU022:,ICU024:,ICU048,ICU141: Verify any error is there for DET */  
  ErrorFlag = Icu_lNotifiDetCheck(Channel,
                                 ICU_SID_STARTSIGNALMEASUREMENT,
                                 ICU_MODE_SIGNAL_MEASUREMENT);

  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
  /* #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    LocalIcuMapPtr =   (Icu_kConfigPtr->MappingIndexPtr) + Channel;
#if (ICU_CCU6_SIGMEAS_USED == STD_ON)    
    PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap;
#endif    

    ChlType = Icu_lGetChannelType(Channel);
    /* ICU050: Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;
    /* Extract the actual cell number */
    CellUsed=
           (Icu_17_GtmCcu6_ChannelType)LocalIcuChanPtr->
                                IcuProperties.AssignedHwUnitNumber;
    #if (ICU_TIM_SIGMEAS_USED == STD_ON) || (ICU_CCU6_SIGMEAS_USED == STD_ON)
    /* Retrieve the Index stored in IndexStore */   
    DutyIndex = LocalIcuMapPtr->ChannelIndexMap;
    #endif                 
    #if (ICU_SAFETY_ENABLE == STD_ON)
    if(ChlType== ICU_GTM_ASIL_CHANNEL)
    {
      #if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)
      /* The signal measure property is retrieved here */
      SigKind = 
      Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].SigProp;
      CfgEdge = 
      Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].CfgEdge;
      #endif
    }
    else if(ChlType== ICU_CCU6_ASIL_CHANNEL)
    {
      #if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)   
      /* The signal measure property is retrieved here */
      SigKind = 
      Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[DutyIndex].SigProp;
      CfgEdge = 
      Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[DutyIndex].CfgEdge;
      #endif
    } 
    else
    #endif
    { 
      #if (ICU_MAX_SIGNAL_MEASURE_QM_CHANNELS != 0U) 
      /* The signal measure property is retrieved here */
      SigKind = 
      Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].SigProp;
      CfgEdge = 
      Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].CfgEdge;
      #endif
    }

   if(LocalIcuChanPtr->IcuProperties.AssignedHwUnit == ICU_GTM_OPTION)
   {
   #if(ICU_TIM_SIGMEAS_USED == STD_ON)   
      if(ICU_PERIOD_TIME == SigKind)
      { 
        if(CfgEdge == ICU_FALLING_EDGE)
        {
          GtmSigKind = ICU_PERIOD_TIME_LOW_DUTY;
        }
        else
        { 
          GtmSigKind = ICU_PERIOD_TIME_HIGH_DUTY;
        }
      }
      else if(SigKind == ICU_ACTIVE_TIME)
      { 
        if(CfgEdge == ICU_FALLING_EDGE)
        {
          GtmSigKind = ICU_ACTIVE_TIME_LOW_DUTY;
        }
        else
        { 
          GtmSigKind = ICU_ACTIVE_TIME_HIGH_DUTY;
        }
      }
      else if(SigKind == ICU_HIGH_TIME)
      {
        GtmSigKind = ICU_HIGH_TIME_GTM;
      }
      else
      {
        GtmSigKind = SigKind;
      }

      /* Start the TIM channel for Signal Measurement */
      Icu_lGtmStartSignalMeasurement(CellUsed,GtmSigKind);
      if(ChlType== ICU_GTM_ASIL_CHANNEL)
      {
        #if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)
        Icu_17_GtmCcu6_AsilGtmVarlist.InfoPtr[DutyIndex] = 0U; 
        #if (ICU_GET_TIME_ELAPSED_API == STD_ON)
        if((SigKind == ICU_HIGH_TIME) || (SigKind == ICU_LOW_TIME))
        {
          Icu_17_GtmCcu6_AsilGtmVarlist.InfoPtrForTimeElapsed[DutyIndex] = 0U;
        }
        #endif  
        #endif 
      }  
      else  
      {
        #if (ICU_QM_TIM_SIGMEAS_USED == STD_ON)   
        Icu_17_GtmCcu6_QmVarlist.InfoPtr[DutyIndex] = 0U; 
        #if (ICU_GET_TIME_ELAPSED_API == STD_ON)
        if((SigKind == ICU_HIGH_TIME) || (SigKind == ICU_LOW_TIME))
        {
          Icu_17_GtmCcu6_QmVarlist.InfoPtrForTimeElapsed[DutyIndex] = 0U;
        }
        #endif
        #endif
      }  
   #endif
   }
   /* #if (ICU_GET_TIME_ELAPSED_API == STD_ON) */
   /* #endif */
   /* #if(ICU_TIM_SIGMEAS_USED == STD_ON) */
  else 
  {
    #if (ICU_CCU6_SIGMEAS_USED == STD_ON)
    Icu_lCcuSignalMeasHandler(ChlType, CellUsed, SigKind, CfgEdge);
    #endif
    #if (ICU_SAFETY_ENABLE == STD_ON)
    if(ChlType== ICU_CCU6_ASIL_CHANNEL)
    {
      #if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)
      Icu_lSetInputStateIdle(
      &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[PhyChannelIndex]);
      #endif
    }    
    else
    #endif   
    {
      #if (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)
      Icu_lSetInputStateIdle(
      &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex]);
      #endif   
    }
    
  }    
   /* Set the ICU_ACTIVITY_STARTED flag */
   Icu_17_lGlbIndexStatusSet(Channel,
                             ICU_ACTIVITY_STARTED,
                             ICU_CHNL_ACTIVITY_STARTED_POS,
                             1U);
   /*   #if (ICU_CCU6_SIGMEAS_USED == STD_ON)   */
 }  
}
/* End of function Icu_17_GtmCcu6_StartSignalMeasurement */


/* ICU145 : Configuration of API Service */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU209,DS_AS_ICU050_18_ICU336,
   DS_AS_ICU022_17,DS_AS_ICU177,DS_AS_ICU243_18_ICU112_18_ICU048_18,
   DS_AS_ICU143_ICU144,DS_NAS_PR734_18]

** Syntax :          void Icu_17_GtmCcu6_StopSignalMeasurement (             **
**                                       Icu_17_GtmCcu6_ChannelType Channel) **
** [/cover]                                                                  **
**                                                                           **
** Service ID:       0x14                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  None                                                    **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1. This service stops the measurement of signals of the     **
**                  given channel                                            **
******************************************************************************/
void Icu_17_GtmCcu6_StopSignalMeasurement(Icu_17_GtmCcu6_ChannelType Channel)
{
  /* Local pointers */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  uint8 CellUsed;
  uint8 ChlType;    
  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag;
  /* ICU024,ICU144,ICU022,ICU048 Verify any error is there for DET */  

  ErrorFlag = Icu_lNotifiDetCheck(Channel,
                                 ICU_SID_STOPSIGNALMEASUREMENT,
                                 ICU_MODE_SIGNAL_MEASUREMENT);
  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
  {
    /* ICU050: Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel ;


    /* Extract the actual cell number */
    CellUsed = (uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
    /* Get the module used */
    ChlType = Icu_lGetChannelType(Channel);
#if (ICU_SAFETY_ENABLE == STD_ON)
    if(ChlType == ICU_GTM_ASIL_CHANNEL)
    {
    #if(ICU_ASIL_TIM_SIGMEAS_USED == STD_ON) 
      /* ICU143: Stop the Signal Measurement */
      Icu_lGtmStopSignalMeasurement(CellUsed);
    /* Activity Start flag is set to zero */
    #endif
    } 
    else if(ChlType == ICU_CCU6_ASIL_CHANNEL) 
    {  
    #if(ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)  
      Icu_lCcuStopSignalMeas(CellUsed); 
   #endif   
    }
    else
    {
     /* dummy else */
    }    
#endif   

    if(ChlType == ICU_GTM_QM_CHANNEL)
    {
    #if(ICU_QM_TIM_SIGMEAS_USED == STD_ON)  
      /* ICU143: Stop the Signal Measurement */
      Icu_lGtmStopSignalMeasurement(CellUsed);
    /* Activity Start flag is set to zero */
    #endif
    }
    else if(ChlType == ICU_CCU6_QM_CHANNEL) 
    {  
    #if(ICU_QM_CCU6_SIGMEAS_USED == STD_ON)  
   Icu_lCcuStopSignalMeas(CellUsed); 
   #endif   
    }  
    else
    {
       /* Dummy else */
       UNUSED_PARAMETER(CellUsed)
    }
    Icu_17_lGlbIndexStatusSet(Channel,0U,ICU_CHNL_ACTIVITY_STARTED_POS,1U); 

  }

 }/* End of function Icu_17_GtmCcu6_StopSignalMeasurement */
#endif 

/* #if (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

/* ICU105 : Configuration API for the function Icu_17_GtmCcu6_GetTimeElapsed */
/* [cover parentID=DS_AS_ICU105_ICU341] */
#if (ICU_GET_TIME_ELAPSED_API == STD_ON)
/* [/cover] */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU210,DS_AS_ICU050_19_ICU338,
   DS_AS_ICU022_18,DS_AS_ICU179,DS_AS_ICU178,
   DS_AS_ICU243_19_ICU112_19_ICU048_19,DS_NAS_PR734_19]

** Syntax :          Icu_17_GtmCcu6_ValueType Icu_17_GtmCcu6_GetTimeElapsed (**
**                                       Icu_17_GtmCcu6_ChannelType Channel )**
** [/cover]                                                                  **
** Service ID:       0x10                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out):                                                         **
**                                                                           **
** Return value:     Icu_17_GtmCcu6_ValueType                                **
**                                                                           **
** Description : 1. This service will return the latest time difference value**
**                  measured as per the configured type of measurement.      **
**                  The service shall measure the following measurement types**
**                  High Time, Low Time Or Period Time.                      **
**               2. The service shall return zero if there were no edges     **
**                  captured or the service has already read the same value. **
**               3. For a successful read the service sets the Channel Status**
**                  to ICU_IDLE.                                             **
*****************************************************************************/

Icu_17_GtmCcu6_ValueType Icu_17_GtmCcu6_GetTimeElapsed(
                                     Icu_17_GtmCcu6_ChannelType Channel)
{
  /*ICU081, ICU082, ICU083 API to read High Time, Low Time Or Period Time */
  Icu_17_GtmCcu6_ValueType Time = 0U;
  Icu_17_GtmCcu6_SignalMeasurementPropertyType Measure = 0U;
  uint8 ChlType;
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr;
  uint8 CellUsed;
  uint32 ChIndex;
  uint32 Hwused;
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;  

  #if(ICU_TIM_SIGMEAS_USED == STD_ON)
  uint32 CfgEdge = 0U;
  #endif
  #if(ICU_TIM_SIGMEAS_USED == STD_ON) 
  Icu_17_GtmCcu6_SignalMeasurementPropertyType GtmSigKind;
  #endif
  /* #if(ICU_TIM_SIGMEAS_USED == STD_ON) */
  
  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag;

  /* Verify any error is there for DET */  
  /*ICU024: Verify whether the channel number is valid, 
     configured for Signal Measurement */
  ErrorFlag = Icu_lNotifiDetCheck(Channel,
                                  ICU_SID_GETTIMEELAPSED,
                                  ICU_MODE_SIGNAL_MEASUREMENT);
   
  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
  /* #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  {

    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;

    ChlType = Icu_lGetChannelType(Channel);
    Hwused = (uint32)LocalIcuChanPtr->IcuProperties.AssignedHwUnit;  
   
    /* Extract the actual cell number */
    CellUsed = (uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
    /* Extract Channel number for the Index storage */
    LocalIcuMapPtr = (Icu_kConfigPtr->MappingIndexPtr) + Channel;         
    /* Channel Index from the configuration for the 
       associated signal measurement channel    */
    ChIndex =LocalIcuMapPtr->ChannelIndexMap;
    #if (ICU_SAFETY_ENABLE == STD_ON)
    if(ChlType== ICU_GTM_ASIL_CHANNEL)
    {
      #if(ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)
      /* Signal Measurement property is taken  
         bit 0, bit 1 holds the information */
      Measure = Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[ChIndex].SigProp;

      /* Elapsed time is initialized to 0 */
      Time = (Icu_17_GtmCcu6_ValueType)0;

      CfgEdge = Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[ChIndex].CfgEdge;
      #endif
    }
    else if(ChlType== ICU_CCU6_ASIL_CHANNEL)
    {
      #if(ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)    
      /* Signal Measurement property is taken  
         bit 0, bit 1 holds the information*/
     Measure = Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[ChIndex].SigProp;

     /* Elapsed time is initialized to 0 */
     Time = (Icu_17_GtmCcu6_ValueType)0;
     /*
     CfgEdge = Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[ChIndex].CfgEdge;
    */
     #endif
    }  
    else
    #endif   
    {
  #if(ICU_QM_TIM_SIGMEAS_USED == STD_ON) || (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)
    
     /* Signal Measurement property is taken  
          bit 0, bit 1 holds the information*/
     Measure = Icu_17_GtmCcu6_QmVarlist.MeasurementParas[ChIndex].SigProp;

     /* Elapsed time is initialized to 0 */
     Time = (Icu_17_GtmCcu6_ValueType)0;
   #endif
    
   #if(ICU_QM_TIM_SIGMEAS_USED == STD_ON)  
     CfgEdge = Icu_17_GtmCcu6_QmVarlist.MeasurementParas[ChIndex].CfgEdge;
   #endif
   
    }
    #if(ICU_TIM_SIGMEAS_USED == STD_ON)
    if(Hwused == ICU_GTM_OPTION)
    { 
       if(Measure == ICU_PERIOD_TIME)
       { 
        if(CfgEdge == ICU_FALLING_EDGE)
        {
          GtmSigKind = ICU_PERIOD_TIME_LOW_DUTY;
        }
        else
        { 
          GtmSigKind = ICU_PERIOD_TIME_HIGH_DUTY;
        }
       }
       else if(Measure == ICU_ACTIVE_TIME)
       { 
        if(CfgEdge == ICU_FALLING_EDGE)
        {
          GtmSigKind = ICU_ACTIVE_TIME_LOW_DUTY;
        }
        else
        { 
          GtmSigKind = ICU_ACTIVE_TIME_HIGH_DUTY;
        }
       }
       else if(Measure == ICU_HIGH_TIME)
       {
         GtmSigKind = ICU_HIGH_TIME_GTM;
       }
       else
       {
         GtmSigKind = Measure;
       }
       #if (ICU_SAFETY_ENABLE == STD_ON)
       if(ChlType== ICU_GTM_ASIL_CHANNEL)
       {
           #if(ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)     
           if((Measure == ICU_HIGH_TIME) || (Measure == ICU_LOW_TIME))
           {
             Time = Icu_lGtmGetTimeElapsed(CellUsed,GtmSigKind, 
                  &Icu_17_GtmCcu6_AsilGtmVarlist.InfoPtrForTimeElapsed[ChIndex],
                  ChlType);
           }
           else
           {
             Time = Icu_lGtmGetTimeElapsed(CellUsed, GtmSigKind,
                     &Icu_17_GtmCcu6_AsilGtmVarlist.InfoPtr[ChIndex],ChlType); 
           }
           #endif
       }
       else
       #endif 
       {
          #if(ICU_QM_TIM_SIGMEAS_USED == STD_ON)
          if((Measure == ICU_HIGH_TIME)  || (Measure == ICU_LOW_TIME))
          {
            Time = Icu_lGtmGetTimeElapsed(CellUsed,GtmSigKind, 
                      &Icu_17_GtmCcu6_QmVarlist.InfoPtrForTimeElapsed[ChIndex],
                      ChlType);
          }
          else
          {
            Time = Icu_lGtmGetTimeElapsed(CellUsed,GtmSigKind,
                     &Icu_17_GtmCcu6_QmVarlist.InfoPtr[ChIndex],
                     ChlType);   
          }
          #endif
       }
     }
     #endif
     /* #if(ICU_TIM_SIGMEAS_USED == STD_ON) */
     #if(ICU_CCU6_SIGMEAS_USED == STD_ON)
     if(Hwused == ICU_CCU_OPTION) 
     {
       Time = Icu_lCcuGetTimeElapsed(CellUsed, Measure,ChlType);
     }
     #endif
     /* #if(ICU_CCU6_SIGMEAS_USED == STD_ON) */
  }
  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  else
  {
    /* ICU048: Return without executing any of functionality */
    Time = (Icu_17_GtmCcu6_ValueType)0;
  }
  #endif

  /*   #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  
  return (Time);
}/* End of function Icu_17_GtmCcu6_GetTimeElapsed */
/* End of function Icu_17_GtmCcu6_GetTimeElapsed */
 #endif 
/* End of #if (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

/* [cover parentID=DS_AS_ICU106_ICU345] */
#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
/* [/cover] */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU211,DS_AS_ICU050_20_ICU342,
   DS_AS_ICU022_19,DS_AS_ICU180,DS_AS_ICU181,
   DS_AS_ICU243_20_ICU112_20_ICU048_20,DS_NAS_PR734_20]
** Syntax :          void Icu_17_GtmCcu6_GetDutyCycleValues (                **
**                                       Icu_17_GtmCcu6_ChannelType Channel, **
**                            Icu_17_GtmCcu6_DutyCycleType *DutyCycleValues )**
**                                                                           **
** [/cover]                                                                  **
** Service ID:       0x11                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant for different channel numbers                 **
**                                                                           **
** Parameters (in):  Channel : Numeric identifier of the ICU channel         **
**                                                                           **
** Parameters (out):  DutyCycleValues : Pointer to structure that could      **
**                                     hold high time and period time.       **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1. This service will return the latest high time            **
**                  and period time captured.                                **
**               2. The service shall write zero in the given address        **
**                  if there were no edges captured or the                   **
**                  has already read the same value.                         **
**               3. A successful read puts the status to ICU_IDLE            **
*****************************************************************************/
void Icu_17_GtmCcu6_GetDutyCycleValues(
                                Icu_17_GtmCcu6_ChannelType Channel,
                                Icu_17_GtmCcu6_DutyCycleType *DutyCycleValues
                              )
{
  /*ICU110: Pointer where the buffer values can be placed */
  /*ICU106:  API under configuration ICU_GET_DUTY_CYCLE_VALUES_API */
  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag; 
  #endif
/*   #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr;
  uint8 IcuOption;  
  uint32 ChIndex;
  Icu_17_GtmCcu6_ChannelType CellUsed;
 /* uint8 Hwused; */
 const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;  

  #if(ICU_TIM_SIGMEAS_USED == STD_ON) 
  Icu_17_GtmCcu6_DutyCycleType GtmDutyCycleValues;

  #endif
/*   #if(ICU_TIM_SIGMEAS_USED == STD_ON) */
  
  /* Hwused = (uint32)LocalIcuChanPtr->IcuProperties.AssignedHwUnit;  */

  #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
  /* Verify any error is there for DET */  
  /*ICU024: Verify whether the channel number is valid, 
    configured for Signal Measurement */
  ErrorFlag = Icu_lNotifiDetCheck(Channel,
                                 ICU_SID_GETDUTYCYCLEVALUES,
                                 ICU_MODE_SIGNAL_MEASUREMENT
                                );
  if (ICU_ERROR_FOUND != ErrorFlag)
  {
      /* ICU120: Passed parameter should not be 0 */
      if ( DutyCycleValues == 0U)
      {
        ErrorFlag = ICU_ERROR_FOUND;
      #if (ICU_DEV_ERROR_DETECT == STD_ON) 
        Det_ReportError( 
                     ICU_17_GTMCCU6_MODULE_ID,
                     ICU_17_GTMCCU6_INSTANCE_ID,
                     ICU_SID_GETDUTYCYCLEVALUES,
                     ICU_E_PARAM_BUFFER_PTR
                   ); /* Report to  DET */
      #endif
      #if (ICU_SAFETY_ENABLE == STD_ON)      
       SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                ICU_17_GTMCCU6_INSTANCE_ID,
                         ICU_SID_GETDUTYCYCLEVALUES,ICU_E_PARAM_BUFFER_PTR); 
      #endif                         
      }  
  }
  if (ICU_ERROR_FOUND != ErrorFlag)
  #endif
  /* #if (ICU_DEV_ERROR_DETECT == STD_ON) */
  {
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;      
    LocalIcuMapPtr = (Icu_kConfigPtr->MappingIndexPtr) + Channel; 
    ChIndex =LocalIcuMapPtr->ChannelIndexMap;
   /* Passed Dutycycle checked against Buffer marker */
    #if (ICU_SAFETY_ENABLE == STD_ON)
     if(DutyCycleValues->BufferMarker !=
        LocalIcuChanPtr->IcuProperties.BufferMarker)
     {
       /* Report an error */
       ErrorFlag = ICU_ERROR_FOUND;
       SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                ICU_17_GTMCCU6_INSTANCE_ID,
                         ICU_SID_GETDUTYCYCLEVALUES,ICU_E_PARAM_BUFFER_PTR);
     }
     if (ICU_ERROR_FOUND != ErrorFlag)         
    #endif 
    {
      /* Initialize all variable to zero */
      DutyCycleValues->ActiveTime = (Icu_17_GtmCcu6_ValueType)0U;
      DutyCycleValues->PeriodTime = (Icu_17_GtmCcu6_ValueType)0U;
    
      /* Depending on ICU option take action */
      IcuOption = Icu_lGetChannelType(Channel);
    
      /* Extract the actual cell number */
      CellUsed = (uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
      if(IcuOption == ICU_GTM_ASIL_CHANNEL)
      {
        #if(ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)   
         /* ICU084: API valid only for Duty Cycle measurement */
         if ( ICU_ACTIVE_TIME != (Icu_17_GtmCcu6_AsilGtmVarlist.
                             MeasurementParas[ChIndex].SigProp))
         {
           #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
           ErrorFlag = ICU_ERROR_FOUND; 
           #endif 
        #if (ICU_DEV_ERROR_DETECT == STD_ON)    
           Det_ReportError( 
                        ICU_17_GTMCCU6_MODULE_ID,
                        ICU_17_GTMCCU6_INSTANCE_ID,
                        ICU_SID_GETDUTYCYCLEVALUES,
                        ICU_E_PARAM_CHANNEL
                         ); /* Report to  DET */
       #endif
       #if (ICU_SAFETY_ENABLE == STD_ON)
        /* Report an error */
        SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                               ICU_SID_GETDUTYCYCLEVALUES,ICU_E_PARAM_CHANNEL);
        #endif   
        }
       #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
       if (ICU_ERROR_FOUND != ErrorFlag)  
       #endif   
       {     
        GtmDutyCycleValues =  \
                     Icu_lGtmGetDutyCycleValues(CellUsed,
                        &Icu_17_GtmCcu6_AsilGtmVarlist.InfoPtr[ChIndex]);

        DutyCycleValues->ActiveTime = GtmDutyCycleValues.ActiveTime;
        DutyCycleValues->PeriodTime = GtmDutyCycleValues.PeriodTime; 
       }
     #endif   
      }
      else if(IcuOption == ICU_CCU6_ASIL_CHANNEL)
     {
      #if(ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)
       /* ICU084: API valid only for Duty Cycle measurement */
       if ( ICU_ACTIVE_TIME != (Icu_17_GtmCcu6_AsilCcu6Varlist.
                              MeasurementParas[ChIndex].SigProp))
      {
        #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
        ErrorFlag = ICU_ERROR_FOUND; 
        #endif
        #if (ICU_DEV_ERROR_DETECT == STD_ON)        
        Det_ReportError( 
              ICU_17_GTMCCU6_MODULE_ID,
              ICU_17_GTMCCU6_INSTANCE_ID,
              ICU_SID_GETDUTYCYCLEVALUES,
              ICU_E_PARAM_CHANNEL
              ); /* Report to  DET */
            #endif                      
      #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
        SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ICU_SID_GETDUTYCYCLEVALUES,ICU_E_PARAM_CHANNEL); 
      #endif 
     } 
    #endif  
  }
  else 
  {
    #if(ICU_QM_TIM_SIGMEAS_USED == STD_ON) || (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)
    /* ICU084: API valid only for Duty Cycle measurement */
    if ( ICU_ACTIVE_TIME != (Icu_17_GtmCcu6_QmVarlist.
                MeasurementParas[ChIndex].SigProp))
    {
      #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
       ErrorFlag = ICU_ERROR_FOUND; 
       #endif
        #if (ICU_DEV_ERROR_DETECT == STD_ON)      
        Det_ReportError( 
            ICU_17_GTMCCU6_MODULE_ID,
            ICU_17_GTMCCU6_INSTANCE_ID,
            ICU_SID_GETDUTYCYCLEVALUES,
            ICU_E_PARAM_CHANNEL
            ); /* Report to  DET */
    #endif
      #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                           ICU_SID_GETDUTYCYCLEVALUES,ICU_E_PARAM_CHANNEL);
      #endif            
      }
     #endif
     #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
     if (ICU_ERROR_FOUND != ErrorFlag)  
     #endif  
     {     
     #if(ICU_QM_TIM_SIGMEAS_USED == STD_ON)     
      GtmDutyCycleValues =  \
                 Icu_lGtmGetDutyCycleValues(CellUsed,&Icu_17_GtmCcu6_QmVarlist.InfoPtr[ChIndex]);

        DutyCycleValues->ActiveTime = GtmDutyCycleValues.ActiveTime;
        DutyCycleValues->PeriodTime = GtmDutyCycleValues.PeriodTime;  
     #endif
     }
    }  
   
/*   #if(ICU_TIM_SIGMEAS_USED == STD_ON) */
     #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
     if (ICU_ERROR_FOUND != ErrorFlag)  
     #endif  
     {
      #if (ICU_SAFETY_ENABLE == STD_ON)
      if(IcuOption == ICU_CCU6_ASIL_CHANNEL)  
      {
      #if(ICU_CCU6_SIGMEAS_USED == STD_ON)
       Icu_lCcuGetDutyCycle((uint32)CellUsed, DutyCycleValues,IcuOption); 
      #endif  
      }
      #endif  
      if (IcuOption == ICU_CCU6_QM_CHANNEL)
      {
       #if(ICU_CCU6_SIGMEAS_USED == STD_ON)  
        Icu_lCcuGetDutyCycle((uint32)CellUsed, DutyCycleValues,IcuOption); 
       #endif      
      }
    }
/* #if(ICU_CCU6_SIGMEAS_USED == STD_ON) */
    /* Update the DutyCycle Values */
  }
 }
}
    /* End of function Icu_17_GtmCcu6_GetDutyCycleValues */

#endif
/* End of #if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) */


/* [cover parentID=DS_AS_ICU362,DS_AS_ICU360] */
#if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) && \
                                       (ICU_REPORT_WAKEUP_SOURCE == STD_ON))
/* [/cover] */
/*Applicable to Autosar V 3.2.1 based on Bugzilla 25392*/
/*******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU358,DS_AS_ICU050_24_ICU361,
   DS_AS_ICU022_22_ICU363,DS_AS_ICU359,DS_AS_ICU213_2,
   DS_AS_ICU243_24_ICU112_24_ICU048_24_ICU363,DS_AS_ICU213_3,DS_NAS_PR734_24]
** Syntax : void Icu_17_GtmCcu6_CheckWakeup                                   **
**                                 (EcuM_WakeupSourceType WakeupSource)       **
**                                                                            **
** [/cover]                                                                   **
** Service ID:  0x15                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant - ICU050                                            **
**                                                                            **
** Parameters (in): WakeupSource                                              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Checks if a wakeup capable ICU channel is the source for a   **
** wakeup event and calls the ECU state manager service EcuM_SetWakeupEvent   **
** in case of a valid ICU channel wakeup event.                               **
**                                                                            **
*******************************************************************************/
void Icu_17_GtmCcu6_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{

#if (ICU_DEV_ERROR_DETECT == STD_ON) 
  uint32 ErrorFlag;  

  /* Verify whether Init has been called */
  ErrorFlag = Icu_lInitCallVerify(ICU_SID_CHECKWAKEUP);
  /* DET check for Init not done - GPT325:*/

  if (ErrorFlag != ICU_ERROR_FOUND)
  #endif
/*(ICU_DEV_ERROR_DETECT == STD_ON)*/
  {
    /* Wakeup info stored matches with WakeupSource */
    if (Icu_WakeupChannelInfo == WakeupSource)
    {
      EcuM_SetWakeupEvent(WakeupSource);
    }
  }
}/* End of Icu_17_GtmCcu6_CheckWakeup*/
#endif

/* End of #if((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
                            &&(ICU_REPORT_WAKEUP_SOURCE == STD_ON))*/

/* [cover parentID=DS_MCAL_SWSC_ICU_0010] */
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU119_3]
** Syntax:           void Icu_17_GtmCcu6_Eru_Isr(void)                       **
**                                                                           **
** [/cover]                                                                  **
** Service ID:       none                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     This is Interrupt Routine Functions for the ERUlines    **
**                   lines. When interrupt occurs corresponding ERU line     **
**                   Service request will be invoked.                        **
*****************************************************************************/
void Icu_17_GtmCcu6_Eru_Isr(void)
{
  #if (ICU_ERU_USED == STD_ON)
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  Icu_17_GtmCcu6_ChannelType Index;
  Icu_17_GtmCcu6_ChannelType Channel;
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr; 
  uint8 PhyChannelIndex;
  Index = 0U;
    
  do
  {
    if (MODULE_SCU.EIFR.U & (uint32_t)(ICU_SET_BIT << Index))
    {
      /* Clear pending interrupt flag */
      MODULE_SCU.FMR.U = Icu_lClearEruServiceRequest(Index);
      /* Handling the ICU Interrupts */
      if (Icu_kConfigPtr->EruChannelMap[Index] <= ICU_MAX_USAGE) 
      {
        Channel = Icu_kConfigPtr->EruChannelMap[Index];
        /* Retrieve Channel Index */
        LocalIcuMapPtr = (Icu_kConfigPtr->MappingIndexPtr) + Channel;         
        PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap;
        /* Initialize ICU configured channel ROM pointer */
        LocalIcuChanPtr =  (Icu_kConfigPtr->ChannelConfigPtr) + Channel;
        Icu_lSignalEdgeNotification_Isr((uint32)Channel,
            LocalIcuChanPtr,
            &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex]);
      }
    }
    Index++;
  } while ( Index < ICU_ERU_LINES);
  #endif
 
/* end of #if ICU_ERU_USED */
}/* End of function Icu_17_GtmCcu6_Eru_Isr */
 /* [/cover]  */
 
 
/* [cover parentID=DS_MCAL_SWSC_ICU_0011] */ 
/******************************************************************************
** Syntax:           void Icu_17_GtmCcu6_Ccu_Isr(                            **
**                    uint8 CcuKernalNumber, uint8 CcuChannelNumber)         **
** Service ID:       none                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  CcuKernalNumber - CCU6x Kernal Number that has triggered**
**                   the interrupt                                           **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     This is Interrupt Routine Functions for the CCU lines   **
**                   lines. When interrupt occurs corresponding CCU line     **
**                   Service request will be invoked.                        **
*****************************************************************************/
void Icu_17_GtmCcu6_Ccu_Isr(uint8 CcuKernalNumber, uint8 CcuChannelNumber)
{
  #if (ICU_CCU6_USED == STD_ON)
  volatile Ifx_CCU6 *Ccu6BaseRegPtr;/* Variable to hold the CCU6 base address */
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  uint8 ChannelCount;       /* To maintain the channel that is evaluated */
  Icu_17_GtmCcu6_ChannelType IcuChannel;/* To hold the ICU channel Number */
#if(ICU_CCU6_SIGMEAS_USED == STD_ON)  
  uint32 IsValue;           /* Backup of Interrupt Information need for High
                               Time evaluation */
#endif                               
#if (ICU_CCU6_SIGEDGE_USED == STD_ON)
  uint8 PhyChannelIndex;
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;  
#endif  

  /* Assign the base address to CCU60 base address */
  Ccu6BaseRegPtr = &MODULE_CCU60;
      /* Channel count is initialized to 0 */
  ChannelCount = CcuChannelNumber;        

  if((CcuKernalNumber <= (uint8)ICU_NO_OF_CCU6_MODULES) &&
     (CcuChannelNumber <= (uint8)ICU_NO_OF_CCU6_CHANNELS))
  {
    SchM_Enter_Icu_17_GtmCcu6_CcuInterruptHandle(); 
    if(Icu_17_CcuChannelMap[CcuKernalNumber][ChannelCount] != ICU_CC_NOT_USED)
    {
      /* Get the base address of the Kernal */
      Ccu6RegPtr = Ccu6BaseRegPtr + CcuKernalNumber;
      /* Search through the IS register to check the channel where interrupt
      is triggered */
      #if(ICU_CCU6_SIGMEAS_USED == STD_ON)       
      IsValue = Ccu6RegPtr->IS.U;  
      #else
      UNUSED_PARAMETER(Ccu6RegPtr)  
      #endif  
        /* Get the ICU channel equivalent */
     IcuChannel = Icu_17_CcuChannelMap[CcuKernalNumber][ChannelCount];
     #if (ICU_CCU6_SIGEDGE_USED == STD_ON)        
     LocalIcuMapPtr =   (Icu_kConfigPtr->MappingIndexPtr) + IcuChannel;              
     PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap;        
     #endif
      /* Get the pointer to the Channel Configuration */
     LocalIcuChanPtr = Icu_kConfigPtr->ChannelConfigPtr + IcuChannel;

     if(LocalIcuChanPtr->IcuProperties.MeasurementMode == \
                                               ICU_MODE_SIGNAL_EDGE_DETECT)
      {
          
        if(LocalIcuChanPtr->IcuProperties.SignalType == ICU_ASIL_SIGNAL)
        {
          #if (ICU_ASIL_CCU6_SIGEDGE_USED == STD_ON)          
          Icu_lSignalEdgeNotification_Isr((uint32)IcuChannel,
             LocalIcuChanPtr,
             &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[PhyChannelIndex]);
          #endif
        }
        else
        {
         #if (ICU_QM_CCU6_SIGEDGE_USED == STD_ON)
          Icu_lSignalEdgeNotification_Isr((uint32)IcuChannel,
               LocalIcuChanPtr,
               &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex]);
        #endif                                          
         }                    

/* #if (ICU_CCU6_SIGEDGE_USED == STD_ON) */
      }
      else
      {
        #if(ICU_CCU6_SIGMEAS_USED == STD_ON)
        if(LocalIcuChanPtr->IcuProperties.SignalType == ICU_ASIL_SIGNAL)
        {
        /* Handling for Signal Measurement */
          Icu_lCcuSignalMeasIntHandler(CcuKernalNumber, 
                                       ChannelCount,
                                       IcuChannel,
                                       IsValue,
                                       ICU_CCU6_ASIL_CHANNEL);
        }
        else
        {
          /* Handling for Signal Measurement */
          Icu_lCcuSignalMeasIntHandler(CcuKernalNumber, 
                                       ChannelCount,
                                       IcuChannel,
                                       IsValue,ICU_CCU6_QM_CHANNEL);        
        }
        #endif
/* #if(ICU_CCU6_SIGMEAS_USED == STD_ON)*/
      }

    }
    SchM_Exit_Icu_17_GtmCcu6_CcuInterruptHandle();
  }
  else
  {
    #if (ICU_SAFETY_ENABLE == STD_ON)
    /* Report Safety Error */
    SafeMcal_ReportError( (uint16)ICU_17_GTMCCU6_MODULE_ID,
        ICU_17_GTMCCU6_INSTANCE_ID,ICU_SID_ISR, ICU_E_PARAM_CHANNEL);
    #endif          
  }
  #else
  UNUSED_PARAMETER(CcuKernalNumber)
  UNUSED_PARAMETER(CcuChannelNumber)
  #endif
/* #if (ICU_CCU6_USED == STD_ON) */
}/* End of function Icu_17_GtmCcu6_Eru_Isr */
 /* [/cover]  */
 
/******************************************************************************
**                      Private Function Definitions                         **
******************************************************************************/
/******************************************************************************
** Syntax :           static _INLINE_ void Icu_lChannelInit()                **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        non-reentrant                                          **
**                                                                           **
** Parameters (in):   none                                                   **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to initialize ICU channels     **
**                                                                           **
******************************************************************************/
static _INLINE_ void Icu_lChannelInit(void)
{
  /* Local pointers */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  /* Local variables */
  uint32 IcuOption;
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;
  #if (ICU_ERU_USED == STD_ON)
  volatile Icu_17_GtmCcu6_ChannelType EruEicrUsed;
  volatile Icu_17_GtmCcu6_ChannelType EruEicrChannel;
  volatile Icu_17_GtmCcu6_ChannelType EruInputLineUsed;
  #endif
  Icu_17_GtmCcu6_ChannelType Channel;
  uint8 PhyChannelIndex;
  Icu_17_GtmCcu6_ChannelType MaxChannels;  
#if ((ICU_TIM_SIGMEAS_USED == STD_ON) || (ICU_CCU6_SIGMEAS_USED == STD_ON))  
  uint8 ChIndex;   
#endif

  #if ((ICU_ERU_USED == STD_ON) ||                                         \
       ((ICU_TIM_SIGEDGE_USED == STD_ON) &&(ICU_EDGE_DETECT_API == STD_ON))) 
  Icu_17_GtmCcu6_ChannelType CellUsed;
  #endif


  /* An index mapping is done to facilitate flexible allocation of channels 
     which means say for eight channels there could be only 2 signal 
     measurement channels let the channel numbers be 5 and 7. 
     The 5th channel will have a  signal measurement index 0 and 
     7th channel will have the index 1.
     No extra variable is used for this purpose as the Global index 
     status variable is used to maintain the same.*/

  /* Get the maximum number of channels */
  MaxChannels = ICU_GETMAXSIGEDGEQMCHANNELS +
                ICU_GETMAXEDGECNTQMCHANNELS +
                ICU_GETMAXTIMSTMPQMCHANNELS +
                ICU_GETMAXSIGMEASQMCHANNELS;
                
  #if (ICU_SAFETY_ENABLE == STD_ON)   
  MaxChannels += ICU_GETMAXSIGEDGEASILCHANNELS +
                ICU_GETMAXEDGECNTASILGTMCHANNELS +
                ICU_GETMAXTIMSTMPASILGTMCHANNELS +
                ICU_GETMAXSIGMEASASILCHANNELS;
  #endif                

  for (Channel = (Icu_17_GtmCcu6_ChannelType)0; 
                                         Channel < MaxChannels; Channel++)
  {

   /* Depending on ICU option take action */
   /* IcuOption = (uint32)LocalIcuChanPtr->IcuProperties.AssignedHwUnit; */
   
   /* Get the channel config pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;
    IcuOption = Icu_lGetChannelType(Channel);
    LocalIcuMapPtr =   (Icu_kConfigPtr->MappingIndexPtr) + Channel; 
    PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap;
    #if ((ICU_TIM_SIGMEAS_USED == STD_ON) || (ICU_CCU6_SIGMEAS_USED == STD_ON))    
    ChIndex = LocalIcuMapPtr->ChannelIndexMap;
    #endif    
 
    #if ((ICU_ERU_USED == STD_ON) ||                                         \
         ((ICU_TIM_SIGEDGE_USED == STD_ON) &&(ICU_EDGE_DETECT_API == STD_ON)))
    /* Extract the actual cell number */
    CellUsed =                                                               \
    (Icu_17_GtmCcu6_ChannelType)
    LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
    #endif
    
    /* ICU054, ICU006:The Initialization function will initialize all relevant
     * registers of the configured hardware with the values of the structure 
     * referenced by the parameter ConfigPtr
    */
    /* Work on depending on ICU option chosen for each channel */
    switch(IcuOption)
    {
      #if (ICU_SAFETY_ENABLE == STD_ON)
      case ICU_GTM_ASIL_CHANNEL:    
      #if (ICU_MAX_ASIL_GTM_CHANNELS != 0U)       
      /* ICU061, ICU040, ICU121 are satisfied here */
      Icu_17_GtmCcu6_AsilGtmVarlist.GlbIndexStatus[PhyChannelIndex] = 0U;
      /* Copy the default start edge to GlbIndexStatus */
      Mcal_SetAtomic((sint32*)(void*)
               &Icu_17_GtmCcu6_AsilGtmVarlist.GlbIndexStatus[PhyChannelIndex],
               (uint32)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge),
               ICU_CHNL_EDGE_POS,
               2);
    
      /* ICU041: All used registers used by configuration
          will be initialized */
      /* ICU051:  Enable interrupt SRC */
      /* Interrupt is not required for GTM resources */      
   #if ((ICU_ASIL_TIM_SIGEDGE_USED == STD_ON)&&(ICU_EDGE_DETECT_API == STD_ON))
      Icu_lGtmEdgeDetectModeInit(LocalIcuChanPtr, CellUsed);
   #endif
     
      #if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON) 
      if ((LocalIcuChanPtr->IcuProperties.MeasurementMode == 
              ICU_MODE_SIGNAL_MEASUREMENT))
      {
        Icu_lSigMesInit(LocalIcuChanPtr, 
                              Channel, 
                              (uint32)ChIndex);
      }
      #endif      
      #endif    
      break;
      
      case ICU_CCU6_ASIL_CHANNEL:  
      #if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)    
      /* ICU061, ICU040, ICU121 are satisfied here */
      Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[PhyChannelIndex] = 0U;
      /* Copy the default start edge to GlbIndexStatus */
      Mcal_SetAtomic((sint32*)(void*)
         &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[PhyChannelIndex],
         (uint32)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge),
         ICU_CHNL_EDGE_POS,
         2);
      /* CCU Port connection initialization */
      Icu_lCcu6PortInit(LocalIcuChanPtr);
      /* Start ICU channels configured for Edge Detection */
      Icu_lCcu6ChannelInit(Channel, LocalIcuChanPtr);
      if ((LocalIcuChanPtr->IcuProperties.MeasurementMode 
                         == ICU_MODE_SIGNAL_MEASUREMENT))
      {
      #if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)
        Icu_lSigMesInit(LocalIcuChanPtr, 
                              Channel, 
                              (uint32)ChIndex);
      #endif                              
      }      
      #endif
        break;
      #endif
      #if (ICU_MAX_QM_CHANNELS != 0U)       
      #if (ICU_QM_GTM_TIM_USED == STD_ON) 
      case ICU_GTM_QM_CHANNEL:
       /* ICU041: All used registers used by configuration
          will be initialized */
       /* ICU051:  Enable interrupt SRC */
       /* Interrupt is not required for GTM resources */  
       Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex] = 0U;
       /* Copy the default start edge to GlbIndexStatus */
       Mcal_SetAtomic((sint32*)(void*)
            &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex],
            (uint32)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge),
            ICU_CHNL_EDGE_POS,
            2);
      /* Depending on ICU option take action */
      /* Extract the actual cell number */
      #if((ICU_QM_TIM_SIGEDGE_USED == STD_ON)&&(ICU_EDGE_DETECT_API == STD_ON))
      Icu_lGtmEdgeDetectModeInit(LocalIcuChanPtr, CellUsed);
      #endif
 
      #if (ICU_QM_TIM_SIGMEAS_USED == STD_ON) 
      if ((LocalIcuChanPtr->IcuProperties.MeasurementMode 
              == ICU_MODE_SIGNAL_MEASUREMENT))
      {
        Icu_lSigMesInit(LocalIcuChanPtr, 
                              Channel, 
                              (uint32)ChIndex);
      }
      #endif      
      break;
      #endif
      
      #if (ICU_CCU6_USED == STD_ON)
      case ICU_CCU6_QM_CHANNEL:
      /* ICU041: All used registers used by configuration
          will be initialized */
      /* ICU051:  Enable interrupt SRC */
      /* Interrupt is not required for GTM resources */  
      Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex] = 0U;
      /* Copy the default start edge to GlbIndexStatus */
      Mcal_SetAtomic((sint32*)(void*)
            &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex],
            (uint32)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge),
            ICU_CHNL_EDGE_POS,
            2);
      /* CCU Port connection initialization */
      Icu_lCcu6PortInit(LocalIcuChanPtr);
      /* Start ICU channels configured for Edge Detection */
      Icu_lCcu6ChannelInit(Channel, LocalIcuChanPtr);
      if ((LocalIcuChanPtr->IcuProperties.MeasurementMode
            == ICU_MODE_SIGNAL_MEASUREMENT))
      {
       #if (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)
        Icu_lSigMesInit(LocalIcuChanPtr, 
                              Channel, 
                              (uint32)ChIndex);
       #endif
      }      
      break;
      #endif
              
      default: /* ICU_ERU_OPTION: */
      /* Depending on ICU option take action */
      #if (ICU_ERU_USED == STD_ON)
      /* ICU041: All used registers used by configuration
          will be initialized */
      /* ICU051:  Enable interrupt SRC */
      /* Interrupt is not required for GTM resources */  
      Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex] = 0U;
      /* Copy the default start edge to GlbIndexStatus */
      Mcal_SetAtomic((sint32*)(void*)
             &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex],
             (uint32)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge),
             ICU_CHNL_EDGE_POS,
             2);
      /* Get the ERU Cell Number and set the Interrupt Node Pointer to 
         SCU_SRC1 for the Cell Number TempUse */
      EruEicrUsed    = Icu_lGetEruEicr(CellUsed);
      EruEicrChannel = Icu_lGetEruEicrChannel(CellUsed);
      EruInputLineUsed = Icu_lGetEruInputLineUsed(CellUsed);
      Icu_lSetEruExis(EruInputLineUsed,EruEicrUsed,EruEicrChannel);
      Icu_lSetEruEdgeEien(
          (Icu_17_GtmCcu6_ActivationType)LocalIcuChanPtr->
                                              IcuProperties.DefaultStartEdge,
          EruEicrUsed,
          EruEicrChannel  );         
      Icu_lSetEruIgp((uint8)0U);
        
      #endif
      break;
#endif    
    }     
            

    }/* End of main Switch Option */

  }/* End of for loop */


#if (ICU_ERU_USED == STD_ON)
/******************************************************************************
** Syntax :           static _INLINE_ void Icu_lDeInitEru                    **
       (Icu_17_GtmCcu6_ChannelType EruEicrUsed,
                         Icu_17_GtmCcu6_ChannelType EruEicrChannel)          **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   EruEicrUsed: EICR used                                 **
**                    EruEicrChannel:  ERU channel Configured                **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to disable the ERU line        **
**                                                                           **
******************************************************************************/
static _INLINE_ void Icu_lDeInitEru(Icu_17_GtmCcu6_ChannelType EruEicrUsed, 
                                    Icu_17_GtmCcu6_ChannelType EruEicrChannel)
{                                                            
  volatile uint32_t* EruAddress;
  volatile uint32_t* EruIgcrAddress;
  uint32 ErulinePos;
  
  EruAddress = Icu_lGetEruAddress(EruEicrUsed);
  EruIgcrAddress = Icu_lGetEruIgcrAddress(0U);
  ErulinePos = Icu_lGetErulinePos((uint32)EruEicrChannel);

  Mcal_SetAtomic( (sint32*)(void*)EruAddress,
                  (uint32)0U,
                  (sint32)ErulinePos,
                  (ICU_ERU_DISABLE_BIT_LENGTH)
                 );  
  Mcal_SetAtomic( (sint32*)(void*)EruIgcrAddress,
                  (uint32)0U,
                  (sint32)(ICU_ERU_IGP0_POS),
                  (ICU_ERU_IGP_BIT_LENGTH)
                 );                                         
}/* end of function Icu_lDeInitEru */

/******************************************************************************
** Syntax :           static _INLINE_ uint32 Icu_GetEruLine(                 **
***                                     Icu_17_GtmCcu6_ChannelType CellUsed) **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   CellUsed - Assigned hardware unit number for ERU lines **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint32                                                 **
**                                                                           **
** Description :      Local function :Service to get the proper ERU line     **
**                                                                           **
******************************************************************************/
static _INLINE_ Icu_17_GtmCcu6_ChannelType Icu_lGetEruLine(
                                         Icu_17_GtmCcu6_ChannelType CellUsed)
{
  Icu_17_GtmCcu6_ChannelType LineNumber;
  /* 
     Eru0 Pinline0, Eru0 Pinline1,Eru0 Pinline3 and Eru0 Pinline4 maps to ERU0.
     Eru1 Pinline0, Eru1 Pinline1,Eru1 Pinline3 and Eru1 Pinline4 maps to ERU1.
     Eru2 Pinline0, Eru2 Pinline1,Eru2 Pinline3 and Eru2 Pinline4 maps to ERU2.
     Eru3 Pinline0, Eru3 Pinline1,Eru3 Pinline3 and Eru3 Pinline4 maps to ERU3.
  */
    /* Divided the CellUsed by 2 to get the
       Line Number 
       0,1,2,3 -> Line 0
       4,5,6,7 -> Line 1
       8,9,10,11 -> Line 2
       12,13,14,15 -> Line 3
       16,17,18,19 -> Line 4
       20,21,22,23 -> Line 5
       24,25,26,27 -> Line 6
       28,29,30,31 -> Line 7       
    */
  LineNumber = CellUsed >> ICU_TWO_U;
  return LineNumber;
}/* end of function Icu_lGetEruLine */
#endif
/* End of #if (ICU_ERU_USED == STD_ON) */

#if (ICU_ERU_USED == STD_ON)
/******************************************************************************
** Syntax :           static _INLINE_ void Icu_lSetEruEdge                   **
**                                           (                               **
**                                  Icu_17_GtmCcu6_ActivationType Edge,      **
**                                  Icu_17_GtmCcu6_ChannelType EruEicrUsed,  **
**                                  Icu_17_GtmCcu6_ChannelType EruEicrChannel**
**                                           )                               **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Edge : To know which kind of Activation asked          **
**                    LineNum : To know the Eru Line number                  **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to setup activations edges     **
**                                   so that notification can occur when     **
**                                   programmed edge occurs on the input pin **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Icu_lSetEruEdge(Icu_17_GtmCcu6_ActivationType Edge, 
                                     Icu_17_GtmCcu6_ChannelType EruEicrUsed, 
                                     Icu_17_GtmCcu6_ChannelType EruEicrChannel)
{
  volatile uint32_t* EruAddress;
  uint32 EruFenPos;
  
  EruAddress = Icu_lGetEruAddress(EruEicrUsed);
  EruFenPos = Icu_lGetEruFenPos(EruEicrChannel);
  
  /* To calculate the value passed for FEN and REN setting */
  Edge = ((Edge <= ICU_BOTH_EDGES)?(Edge + 1U):0U);

  /* Set for Rising edge / Falling edge / Both edges */
  Mcal_SetAtomic( (sint32*)(void*)EruAddress, 
                  (uint32) (Edge),
                  (sint32) (EruFenPos),
                  (ICU_ERU_EDGE_BITS)                         
                );                                   
}/* End of Icu_lSetEruEdge*/

/******************************************************************************
** Syntax :           static _INLINE_ void Icu_lSetEruEdgeEien               **
**                                           (                               **
**                                Icu_17_GtmCcu6_ActivationType Edge,        **
**                                Icu_17_GtmCcu6_ChannelType EruEicrUsed,    **
**                                Icu_17_GtmCcu6_ChannelType EruEicrChannel  **
**                                           )                               **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Edge : To know which kind of Activation asked          **
**                    LineNum : To know the Eru Line number                  **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to setup notifications edges   **
**                                   and to enable interrupt. So that        **
**                                   notification can occur when programmed  **
**                                   edge occurs on the input pin            **
**                                                                           **
*****************************************************************************/
void Icu_lSetEruEdgeEien(Icu_17_GtmCcu6_ActivationType Edge, 
                                     Icu_17_GtmCcu6_ChannelType EruEicrUsed, 
                                     Icu_17_GtmCcu6_ChannelType EruEicrChannel)
{
  volatile uint32_t* EruAddress;
  uint32 EruFenPos;
  
  EruAddress = Icu_lGetEruAddress(EruEicrUsed);
  EruFenPos = Icu_lGetEruFenPos(EruEicrChannel);
  

  /* To invert the value passed for FEN and REN setting */
  Edge = Edge + 1U;

  /* The Passed value left shift by 2 bit to insert EIEN */
  Edge = ((Edge) | (ICU_ASSERT_EIEN));
  
  /* Set for Rising edge / Falling edge / Both edges */
  Mcal_SetAtomic( (sint32*)(void*)EruAddress, 
                  (uint32) (Edge),
                  (sint32) (EruFenPos),
                  (ICU_ERU_EDGEREN_BITS)                         
                );                                   
}/* End of Icu_lSetEruEdgeEien*/

#endif
/* #if (ICU_ERU_USED == STD_ON) */

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON) 
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU057_ICU228,
   DS_AS_ICU055,DS_AS_ICU056,DS_AS40X_ICU244,DS_AS_ICU287,
   DS_AS_ICU229]

** Syntax :           static void Icu_lWakeup_Isr                            **
**                         (                                                 **
**                           uint32 ChIndex                                  **
**                         )                                                 **
** [/cover]                                                                  **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ChIndex : Index to retrieve the wakeup Information     **
**                    LocalIcuChanPtr : Pointer to the channel               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      This routine is called from an ISR only. the service is**
**                    executed for Signal edge detection channels            **
**                                                                           **
*****************************************************************************/
static void Icu_lWakeup_Isr
(
  uint32 ChIndex  
)
{

  const Icu_ChannelWakeupType *LocalWakeupPtr;
  LocalWakeupPtr = (Icu_kConfigPtr->WakeupPtr) + ChIndex;
  /* ICU057: A wakeup event occurs on a wakeup capable ICU Channel */
  /* Wakeup event is set in Icu_17_GtmCcu6_EnableWakeup and a check is needed to
     know whether the module is in sleep mode or not */
  /* During sleep mode its not possible for a non-wakeup capable channel 
     to raise an interrupt because it is taken care in Icu_17_GtmCcu6_SetMode */
  /* However Running Channels are an exception till new API's are
     designed for Signal Measurement, still those channels does not
     have the capability to enter this routine due to its measurement mode. */
  if ( ( ICU_MODE_SLEEP == Icu_17_GtmCcu6_GlobMode )
    )
  {
    /* ICU228: EcuM_CheckWakeup shall be called within the ISR servicing the 
       ICU channel wakeup event on wakeup-capable channel.*/
   #if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
    Icu_WakeupChannelInfo = 1UL << (LocalWakeupPtr->ChannelWakeupInfo);
    EcuM_CheckWakeup(
            1UL << (LocalWakeupPtr->ChannelWakeupInfo)
                    );
   #endif
 
    /* End of #if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)*/
       
  }

} /* End of function Icu_lWakeup_Isr */

#endif

#if (ICU_EDGE_NOTIF_USED == STD_ON)
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU044,DS_AS_ICU187,
   DS_AS_ICU119_3_ICU042]

** Syntax :           static _INLINE_ void Icu_lSignalEdgeNotification_Isr   **
**                      (                                                    **
**                    uint32 ChIndex                                         **
**                    const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr**
**                    volatile uint32 *LocalGlobChanPtr                      **
**                      )                                                    **
** [/cover]                                                                  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ChIndex : Index to retrieve the wakeup Information     **
**                    LocalIcuChanPtr : To call the notification function    **
**                    LocalGlobChanPtr : To get /set the status              **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      This routine is called from an ISR only. the service is**
**                    executed for Signal edge detection / Notification      **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Icu_lSignalEdgeNotification_Isr
(
  uint32 ChIndex,
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr, 
  volatile uint32 *LocalGlobChanPtr 
)
{

  #if ((ICU_GET_INPUT_STATE_API == STD_ON) && \
     ((ICU_ERU_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON)))
  uint32 IcuOption;
  #endif

  /*ICU055: the static configuration parameter ICU_REPORT_WAKEUP_SOURCE is 
     set*/
  /*ICU056: and the module is in mode ICU_MODE_SLEEP */
  #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
  /* Verify whether Wakeup Reason Enabled ? */
  Icu_lWakeup_Isr(ChIndex);
  #else
  UNUSED_PARAMETER(ChIndex)
  #endif
  
  #if ((ICU_GET_INPUT_STATE_API == STD_ON) && \
         ((ICU_ERU_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON)))
  IcuOption = (uint32)LocalIcuChanPtr->IcuProperties.AssignedHwUnit;
  if((IcuOption == ICU_ERU_OPTION) || (IcuOption == ICU_CCU_OPTION))
  {
    /* ICU 031: Make Channel Status to Active */
    Icu_lSetInputStateActive(LocalGlobChanPtr);
  }
  #endif
  /*  #if ((ICU_GET_INPUT_STATE_API == STD_ON) && \
      ((ICU_ERU_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON)))*/

  
  /* ICU042: After a call of Icu_17_GtmCcu6_DisableNotification() notification 
             function 
            must not be called.*/
  /* Verify whether Notification required ?? */
  if ( ICU_ENABLE_NOTIFICATION == 
           Mcal_Extract(*LocalGlobChanPtr,ICU_CHNL_NOTIF_PRESENCE_POS,
                        ICU_CHNL_NOTIF_BIT_LENGTH)
     )
  {
    /* ICU044: Only these edge notifications will be provided which are 
         supported by hardware.*/
    /* ICU019: The callback notifications have no parameters and no return 
              value*/
    /* Provide Notification */
    (LocalIcuChanPtr->NotificationPointer)();
  }
}
#endif
/* #if (ICU_EDGE_NOTIF_USED == STD_ON) */

#if (ICU_DEV_ERROR_DETECT == STD_ON)|| (ICU_SAFETY_ENABLE == STD_ON) 
/******************************************************************************
** Syntax :           static _INLINE_ uint32 Icu_lInitCallVerify             **
**                                  (                                        **
**                                    uint8 ServiceId)                       **
**                                  )                                        **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ServiceId - API Service Id number                      **
**                                                                           **
** Parameters (out):   None                                                  **
**                                                                           **
** Return value:      Error - Informs whether error has found or not         **
**                                                                           **
** Description :      Local function :Service to verify whether Init has been**
**                                    called or report DET error             **
**                                                                           **
*****************************************************************************/
static _INLINE_ uint32 Icu_lInitCallVerify(uint8 ServiceId)
{
  uint32 ErrorFlag;
  ErrorFlag = (uint32)0;
  /* Verify whether Init had been called, 
                              before calling Icu_17_GtmCcu6_DeInit()function */
  if (Icu_17_GtmCcu6_InitStatus != ICU_INITIALIZED)
  {
    /* ICU022: Report to DET upon error */
   #if (ICU_DEV_ERROR_DETECT == STD_ON)     
    Det_ReportError( 
                     ICU_17_GTMCCU6_MODULE_ID,
                     ICU_17_GTMCCU6_INSTANCE_ID,
                     ServiceId, 
                     ICU_E_UNINIT
                   );/* End of report to  DET */
    ErrorFlag = (uint32)ICU_ERROR_FOUND;
   #else
   UNUSED_PARAMETER(ServiceId)
  #endif  
  }
  return (ErrorFlag);
}/* End of Icu_lInitCallVerify() function */

/******************************************************************************
** Traceability : [cover parentID=DS_AS_ICU024,DS_AS_ICU159,DS_AS_ICU160,
   DS_AS_ICU161,DS_AS_ICU163,DS_AS_ICU169,DS_AS_ICU171,
   DS_AS_ICU173,DS_AS_ICU174]

** Syntax :           static _INLINE_ uint32 Icu_lChannelVerify              **
**                                  (                                        **
**                                    uint8 ServiceId,                       **
**                                    Icu_17_GtmCcu6_ChannelType Channel     **
**                                  )                                        **
** [/cover]                                                                  **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ServiceId - API Service Id number                      **
**                    Channel - Channel number to verify                     **
**                                                                           **
** Parameters (out):  None                                                   **
**                                                                           **
** Return value:      Error - Informs whether error has found or not         **
**                                                                           **
** Description :      Local function :Service to verify whether proper       **
**                                    channel has been passed or             **
**                                    raise an error                         **
**                                                                           **
*****************************************************************************/
static _INLINE_ uint32 Icu_lChannelVerify
( 
  uint8 ServiceId,
  Icu_17_GtmCcu6_ChannelType Channel 
)
{
  uint32 ErrorFlag;
  Icu_17_GtmCcu6_ChannelType MaxChannels;
  ErrorFlag = (uint32)0;
  /* Get the maximum number of channels */
  MaxChannels = ICU_GETMAXSIGEDGEQMCHANNELS +
                ICU_GETMAXEDGECNTQMCHANNELS +
                ICU_GETMAXTIMSTMPQMCHANNELS +
                ICU_GETMAXSIGMEASQMCHANNELS;
                
  #if (ICU_SAFETY_ENABLE == STD_ON)   
  MaxChannels += ICU_GETMAXSIGEDGEASILCHANNELS +
                ICU_GETMAXEDGECNTASILGTMCHANNELS +
                ICU_GETMAXTIMSTMPASILGTMCHANNELS +
                ICU_GETMAXSIGMEASASILCHANNELS;
  #endif  
  /* Verify whether Invalid channel number has been sent */
  if ( Channel >= ( MaxChannels ) )
  {
    /* ICU024: Report to DET upon error */
    #if (ICU_DEV_ERROR_DETECT == STD_ON)  
    Det_ReportError( 
                     ICU_17_GTMCCU6_MODULE_ID,
                     ICU_17_GTMCCU6_INSTANCE_ID,
                     ServiceId, 
                     ICU_E_PARAM_CHANNEL
                   );/* End of report to  DET */
    #endif
      #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ServiceId,ICU_E_PARAM_CHANNEL);
      #endif           
    ErrorFlag = (uint32)ICU_ERROR_FOUND;
  
  }
  return (ErrorFlag);

}/* End of Icu_ChannelVerify()*/


/******************************************************************************
** Syntax :           static _INLINE_ uint32 Icu_lChannelCheckMode           **
**                               (                                           **
**                                 uint8 ServiceId,                          **
**                                 Icu_17_GtmCcu6_ChannelType Channel        **
**                                 Icu_17_GtmCcu6_MeasurementModeType Mode   **
**                               )                                           **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ServiceId - API Service Id number                      **
**                    Channel - Channel number to verify                     **
**                    Mode - Kind of Measurement that channel supports       **
**                                                                           **
** Parameters (out):  None                                                   **
**                                                                           **
** Return value:      Error - Informs whether error has found or not         **
**                                                                           **
** Description :     Local function :Service to verify whether proper channel**
**                                    has been passed or raise an error      **
**                                                                           **
*****************************************************************************/
static _INLINE_ uint32 Icu_lChannelCheckMode
( 
  uint8 ServiceId, 
  Icu_17_GtmCcu6_ChannelType Channel,
  Icu_17_GtmCcu6_MeasurementModeType Mode
)
{
  const Icu_17_GtmCcu6_ChannelConfigType *DetLocalPtr;
  uint32 ErrorFlag;
  
  ErrorFlag = 0UL;
  /* Initialize local pointer to first configured channel structure */
  DetLocalPtr = ((Icu_kConfigPtr->ChannelConfigPtr) + Channel);
  if (Mode != DetLocalPtr->IcuProperties.MeasurementMode)
  {
    #if (ICU_DEV_ERROR_DETECT == STD_ON)     
    Det_ReportError( 
                     ICU_17_GTMCCU6_MODULE_ID,
                     ICU_17_GTMCCU6_INSTANCE_ID,
                     ServiceId, 
                     ICU_E_PARAM_CHANNEL
                   );/* End of report to  DET */
  #endif         
      #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ServiceId,ICU_E_PARAM_CHANNEL);
      #endif           
    ErrorFlag = ICU_ERROR_FOUND;
  }

  return (ErrorFlag);
}/* End of Icu_ChannelCheckMode */

/* ICU001:The development errors and exceptions detectable by the ICU driver 
 * depending on its build version (development mode): 
 */
/* ICU002:The detection of all development errors will be configurable(on/off)
   with the preprocessor switch ICU_DEV_ERROR_DETECT. */

/******************************************************************************
** Syntax :           static _INLINE_ uint32 Icu_lDeInitDetCheck( void )     **
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
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service for DET check in               **
**                                   Icu_17_GtmCcu6_DeInit() function        **
**                                                                           **
*****************************************************************************/
static _INLINE_ uint32 Icu_lDeInitDetCheck( void )
{
  /* Verify whether Init called or not, 
                            before calling Icu_17_GtmCcu6_DeInit() function */
  
  return (Icu_lInitCallVerify(ICU_SID_DEINIT));
} /* End of Icu_lDeInitDetCheck() function */
#endif

#if ((ICU_TIM_SIGMEAS_USED == STD_ON) || (ICU_CCU6_SIGMEAS_USED == STD_ON))
/******************************************************************************
** Syntax :           static _INLINE_ void Icu_lSigMesInit                 **
**                          (                                                **
**                 const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr,  **
**                 Icu_17_GtmCcu6_ChannelType Channel,                       **
**                            uint32 DutyIndex                               **
**                          )                                                **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        non reentrant                                          **
**                                                                           **
** Parameters (in):   LocalIcuChanPtr :channel pointer                       **
**                    Channel         : Channel Number                       **
**                    DutyIndex       :Index for Signal Measurement channels **
**                                                                           **
** Parameters (out):  DutyIndex      :Index for Signal Measurement channels  **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to Initialize Configured       **
**                                   TIM resources for Signal measurement    **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Icu_lSigMesInit
(
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr,
  Icu_17_GtmCcu6_ChannelType Channel,
  uint32 DutyIndex
)
{
   #if (ICU_SAFETY_ENABLE == STD_ON )  
  uint8 ChlType;
  #endif  
  Icu_17_GtmCcu6_SignalMeasurementPropertyType SigKind; 
  
  SigKind = (LocalIcuChanPtr->IcuProperties.MeasurementProperty);

  #if (ICU_SAFETY_ENABLE == STD_ON )
  ChlType = Icu_lGetChannelType(Channel);  
  if(ChlType == ICU_GTM_ASIL_CHANNEL )
  {
    #if (ICU_MAX_SIGNAL_MEASURE_ASIL_GTM_CHANNELS != 0U)   
    /* fill signal property here */
    Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].SigProp = SigKind;
    Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].IntrCounter 
                       = ICU_SIGNALMEASUREMENT_COUNTER ;
                       
    if ( (ICU_ACTIVE_TIME == SigKind ) 
         || (ICU_PERIOD_TIME  == SigKind ) )
    {
      /* Assign the edge to Duty Cycle Structure.*/
      Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].CfgEdge = 
             LocalIcuChanPtr->IcuProperties.DefaultStartEdge;
    }
    else 
    {
      Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].CfgEdge = 
      Icu_lGetEdge(SigKind);
    }
      
 #endif
    }
    else if(ChlType == ICU_CCU6_ASIL_CHANNEL)
   {
 #if (ICU_MAX_SIGNAL_MEASURE_ASIL_CCU6_CHANNELS != 0U)  
    /* fill signal property here */
    Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[DutyIndex].SigProp
       = SigKind;
    Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[DutyIndex].IntrCounter 
                       = ICU_SIGNALMEASUREMENT_COUNTER ;
                       
    if ( (ICU_ACTIVE_TIME == SigKind ) 
         || (ICU_PERIOD_TIME  == SigKind ) )
    {
      /* Assign the edge to Duty Cycle Structure.*/
      Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[DutyIndex].CfgEdge = 
             LocalIcuChanPtr->IcuProperties.DefaultStartEdge;
    }
    else 
    {
      Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[DutyIndex].CfgEdge 
       = Icu_lGetEdge(SigKind);
    }
      

#endif
    }
    else
    #endif
  {
      UNUSED_PARAMETER(Channel)
 #if (ICU_MAX_QM_CHANNELS != 0U)
  /* fill signal property here */
#if (ICU_QM_TIM_SIGMEAS_USED == STD_ON) || (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)
    Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].SigProp = SigKind;
    Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].IntrCounter 
               = ICU_SIGNALMEASUREMENT_COUNTER ;
               
    if ( (ICU_ACTIVE_TIME == SigKind ) 
       || (ICU_PERIOD_TIME  == SigKind ) )
    {
      /* Assign the edge to Duty Cycle Structure.*/
      Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].CfgEdge = 
         LocalIcuChanPtr->IcuProperties.DefaultStartEdge;
    }
    else 
    {
      Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].CfgEdge =
                                   Icu_lGetEdge(SigKind);
    }
#endif      

#endif
  }
  
    return;
}
#endif




#if (ICU_DEV_ERROR_DETECT == STD_ON)|| (ICU_SAFETY_ENABLE == STD_ON)
/******************************************************************************
** Traceability : [cover parentID=DS_AS_ICU023,DS_AS_ICU220]                 **
** Syntax :           static _INLINE_ uint32 Icu_lInitDetCheck               **
**                          (                                                **
**                 const Icu_17_GtmCcu6_ConfigType *TempIcuConfigPtr         **
**                          )                                                **
** [/cover]                                                                  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        non reentrant                                          **
**                                                                           **
** Parameters (in):   TempIcuConfigPtr :Icu config pointer                   **
**                                                                           **
** Parameters (out):  ErrorFlag :status of DET                               **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to DET Check for Init          **
**                                                                           **
*****************************************************************************/
static _INLINE_ uint32 Icu_lInitDetCheck
(
  const Icu_17_GtmCcu6_ConfigType *TempIcuConfigPtr  
)
{
  uint32 ErrorFlag;
  ErrorFlag = (uint32)0;
  #if (ICU_PB_FIXEDADDR == STD_OFF)
  /* To verify whether Init has been called with wrong parameter */
  if (NULL_PTR == TempIcuConfigPtr ) /* Det Check for NULL pointer  */
  {
    /*ICU023:Additional Error :
      Report to DET upon error, Init has been called with wrong parameter 
      NULL Config Pointer 
    */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)    
    Det_ReportError( 
                     ICU_17_GTMCCU6_MODULE_ID,
                     ICU_17_GTMCCU6_INSTANCE_ID,
                     ICU_SID_INIT,
                     ICU_E_PARAM_CONFIG
                   ); /* Report to  DET */
  #endif
  #if (ICU_SAFETY_ENABLE == STD_ON)
    /* Report an error */
    SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ICU_SID_INIT,ICU_E_PARAM_CONFIG);
    #endif           
    ErrorFlag = ICU_ERROR_FOUND;
    Icu_kConfigPtr = NULL_PTR;
  }
  #else  
  /* To verify whether Init has been called with wrong parameter */
  if (Icu_kConfigPtr != TempIcuConfigPtr )
  {
    /*ICU023:Additional Error :
      Report to DET upon error, Init has been called with wrong parameter       
    */
#if (ICU_DEV_ERROR_DETECT == STD_ON)    
    Det_ReportError( 
                     ICU_17_GTMCCU6_MODULE_ID,
                     ICU_17_GTMCCU6_INSTANCE_ID,
                     ICU_SID_INIT,
                     ICU_E_PARAM_CONFIG
                   ); /* Report to  DET */
  #endif
  #if (ICU_SAFETY_ENABLE == STD_ON)
    /* Report an error */
    SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ICU_SID_INIT,ICU_E_PARAM_CONFIG);
    #endif           
    ErrorFlag = ICU_ERROR_FOUND;    
  }
  #endif
/* End of #if (ICU_PB_FIXEDADDR == STD_OFF)*/
  /* ICU220: If DET is enabled and Icu_17_GtmCcu6_Init is called when the ICU 
     driver 
     already initialized, Icu_17_GtmCcu6_Init shall raise DET 
     ICU_E_ALREADY_INITIALIZED 
     and return without any action. */
  if(ErrorFlag!=ICU_ERROR_FOUND)
  {
    if (Icu_17_GtmCcu6_InitStatus == ICU_INITIALIZED)
    { 
      #if (ICU_DEV_ERROR_DETECT == STD_ON)  
      /* Report to DET */
      Det_ReportError( ICU_17_GTMCCU6_MODULE_ID, ICU_17_GTMCCU6_INSTANCE_ID, 
                       ICU_SID_INIT, ICU_E_ALREADY_INITIALIZED );
    #endif 
      ErrorFlag = ICU_ERROR_FOUND; /* Set ErrorFlag */
    }
  }
  
  return(ErrorFlag);
}
#endif
/* End of #if (ICU_DEV_ERROR_DETECT == STD_ON) */



#if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)
#if ((ICU_DISABLE_WAKEUP_API == STD_ON) || (ICU_ENABLE_WAKEUP_API == STD_ON))
/******************************************************************************
** Traceability : [cover parentID=DS_AS_ICU156]

** Syntax : static uint32 Icu_lWakeupDetCheck                                **
**                                (                                          **
**                                  Icu_17_GtmCcu6_ChannelType Channel       **
**                                  uint8 ServiceId                          **
**                                )                                          **
** [/cover]                                                                  **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Numeric identifier of the ICU channel        **
**                    ServiceId : Icu_17_GtmCcu6_EnableWakeup /              **
**                                              Icu_17_GtmCcu6_DisableWakeup **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service for DET check in               **
**                                   Icu_17_GtmCcu6_DisableWakeup() function **
**                                                                           **
*****************************************************************************/
static uint32 Icu_lWakeupDetCheck
( 
  Icu_17_GtmCcu6_ChannelType Channel,
  uint8 ServiceId 
)
{
  uint32 ErrorFlag;
  /* Local pointer */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  
  ErrorFlag = Icu_lNotifiDetCheck(Channel,ServiceId,
                                 ICU_MODE_SIGNAL_EDGE_DETECT);
  if (ErrorFlag != ICU_ERROR_FOUND)
  {
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;
    
    /* Verify whether channel is wakeup capable? */
    if (LocalIcuChanPtr->IcuProperties.WakeupCapability != 1U)
    {
      /* ICU059: Report to DET upon error */
      #if (ICU_DEV_ERROR_DETECT == STD_ON)      
      Det_ReportError( 
                       ICU_17_GTMCCU6_MODULE_ID,
                       ICU_17_GTMCCU6_INSTANCE_ID,
                       ServiceId, 
                       ICU_E_PARAM_CHANNEL
                     );/* End of report to  DET */
    #endif
      #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ServiceId,ICU_E_PARAM_CHANNEL);
      #endif           
                     
      ErrorFlag = ICU_ERROR_FOUND; /* Set Error Flag */
    }
  }
  return ErrorFlag;
  
}/* End of Icu_lWakeupDetCheck() function */
#endif
/* ICU_DISABLE_WAKEUP_API  || ICU_ENABLE_WAKEUP_API*/

#if ( (ICU_TIMESTAMP_API == STD_ON) || (ICU_EDGE_COUNT_API == STD_ON) ||\
    (ICU_SIGNAL_MEASUREMENT_API == STD_ON) ||    \
    (ICU_GET_TIME_ELAPSED_API == STD_ON) ||      \
    (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) || \
    (ICU_DISABLE_WAKEUP_API == STD_ON) ||        \
    (ICU_ENABLE_WAKEUP_API == STD_ON) )
/******************************************************************************
** Traceability : [cover parentID=DS_AS_ICU155,DS_AS_ICU176,DS_AS_ICU177,
   DS_AS_ICU178,DS_AS_ICU180]
** Syntax : static uint32 Icu_lNotifiDetCheck                                **
**                                 (                                         **
**                                   Icu_17_GtmCcu6_ChannelType Channel,     **
**                                   uint8 ServiceId ,                       **
**                                   Icu_17_GtmCcu6_MeasurementModeType Mode **
**                                 )                                         **
** [/cover]                                                                  **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Numeric identifier of the ICU channel        **
**                    ServiceId: Id of the API                               **
**                    Mode: Measurement Mode                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service for DET check in  APIs where   **
**                    the API can be configured for only one Mode            **
**                    Used across all Timestamp and EdgeCount API's          **
**                                                                           **
*****************************************************************************/
static uint32 Icu_lNotifiDetCheck
( 
  Icu_17_GtmCcu6_ChannelType Channel, 
  uint8 ServiceId , 
  Icu_17_GtmCcu6_MeasurementModeType Mode
)
{
  uint32 ErrorFlag = 0U;
  
  /* Verify whether Init has been called */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)  
  ErrorFlag = Icu_lInitCallVerify(ServiceId);

  if (ErrorFlag != ICU_ERROR_FOUND)
  #endif    
  {
    /* if UNINIT occurred then Icu_kConfigPtr is not valid. So need not to 
       check for other DET errors */
    /* Verify whether Invalid channel number has been sent */
    ErrorFlag = Icu_lChannelVerify(ServiceId,Channel);
    if (ErrorFlag != ICU_ERROR_FOUND)
    {
      /* ICU024 */
      #if (ICU_DEV_ERROR_DETECT == STD_ON) || (ICU_SAFETY_ENABLE == STD_ON)       
      ErrorFlag = Icu_lChannelCheckMode(ServiceId,Channel,Mode);
      #endif    
    }
  }

  return ErrorFlag;
  
} /* End of Icu_lNotifiDetCheck() function */
#endif

/******************************************************************************
** Syntax : static uint32 Icu_lEnDisNotificationDetCheck                     **
**                                  (                                        **
**                                    Icu_17_GtmCcu6_ChannelType Channel     **
**                                    uint8 ServiceId                        **
**                                  )                                        **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Numeric identifier of the ICU channel        **
**                    ServiceId: Id of the API                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service for DET check in               **
**                                   Icu_17_GtmCcu6_EnableNotification()     **
**                                   Icu_17_GtmCcu6_DisableNotification()    **
**                                                                           **
*****************************************************************************/
static uint32 Icu_lEnDisNotificationDetCheck
(
  Icu_17_GtmCcu6_ChannelType Channel,
  uint8 ServiceId                                               
)
{
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  /* Verify any error is there for DET */  
  uint32 ErrorFlag;
  #if ( ICU_DEV_ERROR_DETECT == STD_ON )     
  ErrorFlag = Icu_lInitCallVerify(ServiceId);
  if (ErrorFlag != ICU_ERROR_FOUND)
  #endif    
  {
    ErrorFlag = Icu_lChannelVerify(ServiceId, Channel);
    if (ErrorFlag != ICU_ERROR_FOUND)
    {
      /* Initialize ICU configured channel ROM pointer */
      LocalIcuChanPtr = ( (Icu_kConfigPtr->ChannelConfigPtr) + Channel );
    
      /* As per Bugzilla entry 11480 , check Disable Notification
           for Timestamp measurement also */
      if ( !( (LocalIcuChanPtr->IcuProperties.MeasurementMode 
                   == ICU_MODE_SIGNAL_EDGE_DETECT) ||
            (LocalIcuChanPtr->IcuProperties.MeasurementMode 
                         == ICU_MODE_TIMESTAMP))
         )
      {
        ErrorFlag = ICU_ERROR_FOUND;
      #if (ICU_DEV_ERROR_DETECT == STD_ON)      
        Det_ReportError(ICU_17_GTMCCU6_MODULE_ID,
                        ICU_17_GTMCCU6_INSTANCE_ID,
                        ServiceId,
                        ICU_E_PARAM_CHANNEL );  
    #endif
    #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ServiceId,ICU_E_PARAM_CHANNEL);
      #endif            
      }
    }
  }
  return (ErrorFlag);
}

/* precompile switch ICU_EDGE_DETECT_API */ 
#if ((ICU_EDGE_DETECT_API == STD_ON) && ((ICU_DEV_ERROR_DETECT == STD_ON) \
     || (ICU_SAFETY_ENABLE == STD_ON)))
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU022_20]

** Syntax : static uint32 Icu_lEnDisEdgeDetectDetCheck                       **
**                                  (                                        **
**                                    Icu_17_GtmCcu6_ChannelType Channel     **
**                                    uint8 ServiceId                        **
**                                  )                                        **
** [/cover]                                                                  **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Numeric identifier of the ICU channel        **
**                    ServiceId: Id of the API                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service for DET check in               **
**                                   Icu_17_GtmCcu6_EnableEdgeDetection()    **
**                                   Icu_17_GtmCcu6_DisableEdgeDetection()   **
**                                                                           **
*****************************************************************************/
static uint32 Icu_lEnDisEdgeDetectDetCheck
(
  Icu_17_GtmCcu6_ChannelType Channel,
  uint8 ServiceId                                               
)
{
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  /* Verify any error is there for DET */  
  uint32 ErrorFlag;
  #if ( ICU_DEV_ERROR_DETECT == STD_ON )      
  ErrorFlag = Icu_lInitCallVerify(ServiceId);
  if (ErrorFlag != ICU_ERROR_FOUND)
  #endif  
  {
    ErrorFlag = Icu_lChannelVerify(ServiceId,Channel);
    if (ErrorFlag != ICU_ERROR_FOUND)
    {
      /* Initialize ICU configured channel ROM pointer */
      LocalIcuChanPtr = ( (Icu_kConfigPtr->ChannelConfigPtr) + Channel );
      if ( !(LocalIcuChanPtr->IcuProperties.MeasurementMode 
                   == ICU_MODE_SIGNAL_EDGE_DETECT) )
      {
        ErrorFlag = ICU_ERROR_FOUND;
      #if (ICU_DEV_ERROR_DETECT == STD_ON)      
        Det_ReportError(ICU_17_GTMCCU6_MODULE_ID,
                        ICU_17_GTMCCU6_INSTANCE_ID,
                        ServiceId,
                        ICU_E_PARAM_CHANNEL );   
    #endif
      #if (ICU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                             ServiceId,ICU_E_PARAM_CHANNEL);
      #endif            
      }
    }
  }
  return (ErrorFlag);
}
#endif
/* #if ((ICU_EDGE_DETECT_API == STD_ON) && (ICU_DEV_ERROR_DETECT == STD_ON)) */


#if (ICU_GET_INPUT_STATE_API == STD_ON)
/******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU162]
** Syntax : static uint32 Icu_lGetInputStateDetCheck                         **
**                                (                                          **
**                                  Icu_17_GtmCcu6_ChannelType Channel       **
**                                )                                          **
** [/cover]                                                                  **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Numeric identifier of the ICU channel        **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service for DET check in               **
**                                   Icu_17_GtmCcu6_GetInputState() function **
**                                                                           **
*****************************************************************************/
static uint32 Icu_lGetInputStateDetCheck( Icu_17_GtmCcu6_ChannelType Channel )
{
  uint32 ErrorFlag;
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  /* Verify whether Init has been called */
  #if (ICU_DEV_ERROR_DETECT == STD_ON)     
  ErrorFlag = Icu_lInitCallVerify(ICU_SID_GETINPUTSTATE);
  if (ErrorFlag != ICU_ERROR_FOUND)
  #endif    
  {
    /* if UNINIT occurred then Icu_kConfigPtr is not valid. 
       So need not to check  for other DET errors */
    /* Verify whether Invalid channel number has been sent */
    ErrorFlag = Icu_lChannelVerify(ICU_SID_GETINPUTSTATE, 
                                        Channel);
    if (ErrorFlag != ICU_ERROR_FOUND)
    {
      /* Initialize ICU configured channel ROM pointer */
      LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;
      if (!( (LocalIcuChanPtr->IcuProperties.MeasurementMode 
               == ICU_MODE_SIGNAL_MEASUREMENT) ||
            (LocalIcuChanPtr->IcuProperties.MeasurementMode 
             == ICU_MODE_SIGNAL_EDGE_DETECT)
           )
         )
      {
        ErrorFlag = (uint32)ICU_ERROR_FOUND;
      #if (ICU_DEV_ERROR_DETECT == STD_ON)    
        /* ICU024 : Icu_17_GtmCcu6_GetInputState is valid only for Signal 
            Measurement 
            and Signal Edge Detection.
        */
        Det_ReportError( 
                      ICU_17_GTMCCU6_MODULE_ID,
                      ICU_17_GTMCCU6_INSTANCE_ID,
                      ICU_SID_GETINPUTSTATE, 
                      ICU_E_PARAM_CHANNEL
                       );/* End of report to  DET */
       #endif
       #if (ICU_SAFETY_ENABLE == STD_ON)
           /* Report an error */
           SafeMcal_ReportError ((uint16)ICU_17_GTMCCU6_MODULE_ID,
                                  ICU_17_GTMCCU6_INSTANCE_ID,
                 ICU_SID_GETINPUTSTATE,ICU_E_PARAM_CHANNEL);
       #endif            
      }
    } 
  }
  return ErrorFlag;
  
}/* End of Icu_lGetInputStateDetCheck() function */
#endif
/* End of #if ICU_GET_INPUT_STATE_API */
#endif
/* End of ICU_DEV_ERROR_DETECT */



#if ((ICU_SET_MODE_API == STD_ON) && ((ICU_TIM_SIGEDGE_USED == STD_ON) || \
     (ICU_ERU_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON)))
/******************************************************************************
** Syntax :           static void Icu_lDeactivateEdge                        **
**                                (                                          **
**                       Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr   **
**                                )                                          **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   LocalIcuChanPtr : Channel Configuration pointer        **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Deactivates Edge in TIM/ERU            **
**                    Function can be called from Icu_17_GtmCcu6_SetMode     **
**    Icu_17_GtmCcu6_DisableEdgeCount Or Icu_17_GtmCcu6_StopTimestamp        **
**                                                                           **
*****************************************************************************/
static  void Icu_lDeactivateEdge(const 
                            Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr)
{
  uint32 IcuOption;
  Icu_17_GtmCcu6_ChannelType CellUsed;
  #if (ICU_ERU_USED == STD_ON)
  Icu_17_GtmCcu6_ChannelType EruEicrUsed;
  Icu_17_GtmCcu6_ChannelType EruEicrChannel;  
  #endif
  
  IcuOption = (uint32)LocalIcuChanPtr->IcuProperties.AssignedHwUnit;
  CellUsed = (uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
  
  switch(IcuOption)
  {
    #if (ICU_TIM_SIGEDGE_USED == STD_ON)
    case ICU_GTM_OPTION:/* Disable the TIM Channel */
    Icu_lGtmDisableChannel(CellUsed);
    break;
    #endif


    #if (ICU_CCU6_SIGEDGE_USED == STD_ON)
    case ICU_CCU_OPTION:
      /* Disable the CCU channel by setting the Mode to off */
      Icu_lCcuDisableChannel(CellUsed);
      
    break;
    
    #endif
/* #if (ICU_CCU6_SIGEDGE_USED == STD_ON) */
    
    default: /* ICU_ERU_OPTION */
    #if (ICU_ERU_USED == STD_ON)

    /* Extract proper Eru Line */
    EruEicrUsed    = Icu_lGetEruEicr(CellUsed);
    EruEicrChannel = Icu_lGetEruEicrChannel(CellUsed);
    /* Disable ERU line */
    /*Misra Rule 14.2 violation:
    Icu_lDisableEruLine lacks side effects since Mcal_SetAtomic used in this 
    function*/
    
    Icu_lDisableEruLine(EruEicrUsed, EruEicrChannel);
    
    #endif
    break;
  }/* End of Switch(IcuOption) */

}/* End of Icu_lDeactivateEdge */

#endif
/* #if ((ICU_SET_MODE_API == STD_ON) && ((ICU_TIM_SIGEDGE_USED == STD_ON) || \
     (ICU_ERU_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON))) */


#if ((ICU_SET_MODE_API == STD_ON) && ((ICU_TIM_SIGEDGE_USED == STD_ON) || \
     (ICU_ERU_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON)))
/******************************************************************************
** Syntax :           static void Icu_lDisableForWakeup(void)                **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        non reentrant                                          **
**                                                                           **
** Parameters (in):   none                                                   **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to disable the non             **
**                                    wakeupcapable Icu channels. This       **
**                                    service will be called                 **
**                                    from the API Icu_17_GtmCcu6_SetMode()  **
**                                                                           **
*****************************************************************************/
static void Icu_lDisableForWakeup( void )
{
  /* Local variables */
  Icu_17_GtmCcu6_ChannelType Channel;
  Icu_17_GtmCcu6_ChannelType MaxChannels;
  uint32 IsWakeup;

  /* Local pointers */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  /* Initialize ICU configured channel ROM pointer */
  LocalIcuChanPtr = Icu_kConfigPtr->ChannelConfigPtr;
  /* Get the maximum number of channels */
  MaxChannels = ICU_GETMAXSIGEDGEQMCHANNELS +
                ICU_GETMAXEDGECNTQMCHANNELS +
                ICU_GETMAXTIMSTMPQMCHANNELS +
                ICU_GETMAXSIGMEASQMCHANNELS;
                
  #if (ICU_SAFETY_ENABLE == STD_ON)   
  MaxChannels += ICU_GETMAXSIGEDGEASILCHANNELS +
                ICU_GETMAXEDGECNTASILGTMCHANNELS +
                ICU_GETMAXTIMSTMPASILGTMCHANNELS +
                ICU_GETMAXSIGMEASASILCHANNELS;
  #endif  
  for ( Channel = (Icu_17_GtmCcu6_ChannelType)0; 
       Channel < MaxChannels;
       Channel++
     )
  { 
    /* LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;  */
    /* Verify whether channel is wakeup capable? 
       if not Disable cells or ERU lines from interrupt */
    IsWakeup = (uint32)Icu_17_lGlbIndexStatusExtract(Channel,
                                                    ICU_CHNL_WAKEUP_CAPABLE_POS, 
                                              ICU_CHNL_WAKEUP_BIT_LENGTH);
    /* Assume a channel is running: it shouldn't be stopped
       If a channel is stopped,its already stopped 
     */ 
    /* ICU133 the running operations shall be maintained */
    if (IsWakeup == 0U)  
    {
      
      if ( LocalIcuChanPtr->IcuProperties.MeasurementMode 
             == ICU_MODE_SIGNAL_EDGE_DETECT)
      {
        /* Deactivate the edge */
        Icu_lDeactivateEdge(LocalIcuChanPtr);
      }
    }/* End of if !IsWakeup */
#if ((ICU_SAFETY_ENABLE == STD_ON) && (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) \
     && (ICU_TIM_SIGEDGE_USED == STD_ON))
   else 
   {
     if(LocalIcuChanPtr->IcuProperties.AssignedHwUnit == ICU_GTM_OPTION)
     {
        Icu_lSafeCheckMode(LocalIcuChanPtr);
     }
   }
 #endif
 /* Increment all channel pointers */
    LocalIcuChanPtr++;
  }/* End of for loop */

}/* End of Icu_lDisableForWakeup() function */


/******************************************************************************
** Syntax :           static void Icu_lSetNormal(void)                       **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        non reentrant                                          **
**                                                                           **
** Parameters (in):   none                                                   **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to set the mode to normal.     **
**                                   Also brings the channels to original    **
**                                   condition (that is same as before       **
**                                   entering to wakeup mode).               **
**                                   This service will be called from the API**
**                                   Icu_17_GtmCcu6_SetMode()                **
**                                                                           **
*****************************************************************************/
static void Icu_lSetNormal( void )
{
  /* Local variables */  
  uint32 IcuOption;
  Icu_17_GtmCcu6_ChannelType Channel;
  Icu_17_GtmCcu6_ChannelType MaxChannels;  
  uint32 IsWakeup;
  uint8 IsDisabled;
  #if ((ICU_TIM_SIGEDGE_USED == STD_ON) || (ICU_ERU_USED == STD_ON))
  Icu_17_GtmCcu6_ActivationType Edge;
  #endif
  /* #if ((ICU_TIM_SIGEDGE_USED == STD_ON) || (ICU_ERU_USED == STD_ON)) */
  
  #if (ICU_EDGE_DETECTION_USED == STD_ON)
  Icu_17_GtmCcu6_ChannelType CellUsed;
  #endif
  /* #if (ICU_EDGE_DETECTION_USED == STD_ON) */

  #if (ICU_ERU_USED == STD_ON)
  Icu_17_GtmCcu6_ChannelType EruChannel;
  Icu_17_GtmCcu6_ChannelType EruEicrUsed;
  Icu_17_GtmCcu6_ChannelType EruEicrChannel;
  #endif
  /* #if (ICU_ERU_USED == STD_ON) */
  
  /* Local pointers */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  /* Initialize ICU configured channel ROM pointer */
  LocalIcuChanPtr = Icu_kConfigPtr->ChannelConfigPtr;
  /* Initialize Global channel RAM pointer */
  /* Get the maximum number of channels */
  MaxChannels = ICU_GETMAXSIGEDGEQMCHANNELS +
                ICU_GETMAXEDGECNTQMCHANNELS +
                ICU_GETMAXTIMSTMPQMCHANNELS +
                ICU_GETMAXSIGMEASQMCHANNELS;
                
  #if (ICU_SAFETY_ENABLE == STD_ON)   
  MaxChannels += ICU_GETMAXSIGEDGEASILCHANNELS +
                ICU_GETMAXEDGECNTASILGTMCHANNELS +
                ICU_GETMAXTIMSTMPASILGTMCHANNELS +
                ICU_GETMAXSIGMEASASILCHANNELS;
  #endif  
  for (Channel = (Icu_17_GtmCcu6_ChannelType)0U; 
                                       Channel < MaxChannels; Channel++)
  {
    /* 
      Verify whether channel is wakeup capable and not in running condition
      prior going to sleep mode. 
      If not wakeup capable, bring the channel to original condition.
    */
    IsWakeup = (uint32)Icu_17_lGlbIndexStatusExtract(Channel,
                     ICU_CHNL_WAKEUP_CAPABLE_POS,ICU_CHNL_WAKEUP_BIT_LENGTH);


    IsDisabled = (uint8)Icu_17_lGlbIndexStatusExtract(Channel,
          (uint8)ICU_CHNL_DISABLE_STAT_POS,ICU_CHNL_DISABLE_STAT_BIT_LENGTH);


    
    /* ICU133 the running operations shall be maintained */
    if ( (IsWakeup == 0U) && (IsDisabled != 1U) &&
         (LocalIcuChanPtr->IcuProperties.MeasurementMode == 
          ICU_MODE_SIGNAL_EDGE_DETECT) 
       )  
    {
      /* Depending on ICU option take action */
      IcuOption = (uint32)LocalIcuChanPtr->IcuProperties.AssignedHwUnit;
      
      #if (ICU_EDGE_DETECTION_USED == STD_ON)      
      CellUsed = (uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
      #endif
      /* #if (ICU_EDGE_DETECTION_USED == STD_ON)      */
       
      #if ((ICU_TIM_SIGEDGE_USED == STD_ON) || (ICU_ERU_USED == STD_ON))

    Edge = (Icu_17_GtmCcu6_ActivationType)Icu_17_lGlbIndexStatusExtract(
                          Channel,ICU_CHNL_EDGE_POS,ICU_CHNL_EDGE_BIT_LENGTH);
  
      /* Extract the actual cell number */
      #endif
      /* #if ((ICU_TIM_SIGEDGE_USED == STD_ON) || (ICU_ERU_USED == STD_ON)) */
 
      switch(IcuOption)
      {
        #if ((ICU_TIM_SIGEDGE_USED == STD_ON) &&(ICU_EDGE_DETECT_API == STD_ON))
        case ICU_GTM_OPTION:
        /* Enable the Edge */
        Icu_lGtmStartEdgeDetect(CellUsed,Edge);
        break;
        #endif

        #if (ICU_CCU6_SIGEDGE_USED == STD_ON)
        case ICU_CCU_OPTION:
          /* Enable the channel back the Capture mode */
          Icu_lCcuEnableChannel(CellUsed);
        break;
        #endif
/* #if (ICU_CCU6_SIGEDGE_USED == STD_ON) */
        
        default: /* ICU_ERU_OPTION */
        #if (ICU_ERU_USED == STD_ON)
        /* Extract proper Eru Line */
        EruChannel = Icu_lGetEruChannel(CellUsed);
        EruEicrUsed    = Icu_lGetEruEicr(CellUsed);
        EruEicrChannel = Icu_lGetEruEicrChannel(CellUsed);
        /* Clear Service Request if any was in pending */
        MODULE_SCU.FMR.U = Icu_lClearEruServiceRequest(EruChannel);
        
        /*Misra Rule 14.2 violation:
        Icu_lSetEruEdge lacks side effects since Mcal_SetAtomic used in this 
        function*/
        
        Icu_lSetEruEdge(
                         Edge,
                         EruEicrUsed,
                         EruEicrChannel
                       );
         
               
        #endif
        break;
                      
      }/* End of Switch(IcuOption) */
    }/* End of if */
    
    /* Increment all channel pointers */
    LocalIcuChanPtr++;
    
  }/* End of for loop */

}/* End of Icu_lSetNormal() function */

#endif
/* #if ((ICU_SET_MODE_API == STD_ON) && ((ICU_TIM_SIGEDGE_USED == STD_ON) || \
     (ICU_ERU_USED == STD_ON) || (ICU_CCU6_SIGEDGE_USED == STD_ON))) */

/******************************************************************************
** Syntax :           static void Icu_lResetGlobalVariables(void)            **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        non reentrant                                          **
**                                                                           **
** Parameters (in):   none                                                   **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to set all the required global **
**                                   variables to zero.                      **
**                                                                           **
*****************************************************************************/
static void Icu_lResetGlobalVariables(void)
{

  #if ( (ICU_TIMESTAMP_API == STD_ON) ||             \
        (ICU_EDGE_COUNT_API == STD_ON) ||            \
        (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
  Icu_17_GtmCcu6_ChannelType Channel;
  #endif

 #if (ICU_SIGNAL_MEASUREMENT_API == STD_ON) && \
          (ICU_MAX_SIGNAL_MEASURE_QM_CHANNELS!= 0U) 
  for (Channel = (Icu_17_GtmCcu6_ChannelType)0; 
      Channel < ICU_GETMAXSIGMEASQMCHANNELS; 
      Channel++)
  {
   /* In the structure only the index variable is set
      to zero */  
    Icu_17_GtmCcu6_QmVarlist.MeasurementParas[Channel].Index = (uint8)0; 
    Icu_17_GtmCcu6_QmVarlist.InfoPtr[Channel] = (uint8)0U; 
    #if (ICU_GET_TIME_ELAPSED_API == STD_ON)
    Icu_17_GtmCcu6_QmVarlist.InfoPtrForTimeElapsed[Channel] = (uint8)0U; 
    #endif
  }
  #if (ICU_QM_TIM_SIGMEAS_USED == STD_ON)
  for(Channel = 0U; Channel < GTM_NO_OF_TIM_MODULES; Channel++)
  {
    #if(ICU_GET_INPUT_STATE_API == STD_ON) 
    Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForInputState[Channel] = (uint16)0U; 
    #endif
    #if (ICU_GET_TIME_ELAPSED_API == STD_ON)
    Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForTimeElapsed[Channel] = (uint16)0U; 
    #endif
  }
  #endif
  #endif
  
  #if (ICU_SAFETY_ENABLE == STD_ON)    
  #if (ICU_MAX_SIGNAL_MEASURE_ASIL_GTM_CHANNELS != 0U)
  for (Channel = (Icu_17_GtmCcu6_ChannelType)0; 
       Channel  < ICU_GETMAXSIGMEASASILGTMCHANNELS; 
       Channel++)
  {
    Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[Channel].Index = (uint8)0;
    Icu_17_GtmCcu6_AsilGtmVarlist.InfoPtr[Channel] = (uint8)0U; 
    #if (ICU_GET_TIME_ELAPSED_API == STD_ON)
    Icu_17_GtmCcu6_AsilGtmVarlist.InfoPtrForTimeElapsed[Channel] = (uint8)0U; 
    #endif
  } 
  
  for(Channel = 0U; Channel < GTM_NO_OF_TIM_MODULES; Channel++)
  {
    #if(ICU_GET_INPUT_STATE_API == STD_ON) 
    Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForInputState[Channel] = 
       (uint16)0U; 
    #endif
    #if (ICU_GET_TIME_ELAPSED_API == STD_ON)
    Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForTimeElapsed[Channel] = 
       (uint16)0U; 
    #endif
  }
  #endif
  
  #if (ICU_MAX_SIGNAL_MEASURE_ASIL_CCU6_CHANNELS != 0U)
  for (Channel = (Icu_17_GtmCcu6_ChannelType)0; 
            Channel  < ICU_GETMAXSIGMEASASILCCU6CHANNELS; 
            Channel++)
  {
     Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[Channel].Index = (uint8)0;       
  }
  #endif    
  /* ICU_SAFETY_ENABLE == STD_ON */
  #endif 

  
  #if (ICU_TIMESTAMP_API == STD_ON)
  /* TimeStampParas will be taken care in Icu_17_GtmCcu6_StartTimestamp 
               API */
  /* ICU135 states that the Index should be zero , if the 
               Gettimestamp index is called before Icu_17_GtmCcu6_StartTimestamp */
  #if (ICU_QM_TIM_TIMESTAMP_USED == STD_ON)                  
  for (Channel = (Icu_17_GtmCcu6_ChannelType)0; 
      Channel < ICU_GETMAXTIMSTMPQMCHANNELS;Channel++)
  {    
    Icu_17_GtmCcu6_QmVarlist.TimeStampParas[Channel].Counter = (uint16)0;         
  }
  #endif     
  #if (ICU_ASIL_TIM_TIMESTAMP_USED == STD_ON)    
  for (Channel = (Icu_17_GtmCcu6_ChannelType)0; 
           Channel  < ICU_GETMAXTIMSTMPASILGTMCHANNELS; 
           Channel++)
  {
    Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[Channel].Counter = (uint16)0; 
  }           
  #endif     
  #endif
       


  #if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) && \
                                       (ICU_REPORT_WAKEUP_SOURCE == STD_ON))
  /* Clear the Variable to store the channel wakeup info due to which ICU 
     wakeup */
  Icu_WakeupChannelInfo = 0U;
  #endif
      
  #if (ICU_EDGE_COUNT_API == STD_ON)
  #if (ICU_ASIL_TIM_EDGECNT_USED== STD_ON)
  for(Channel = 0U; Channel < ICU_GETMAXEDGECNTASILGTMCHANNELS; Channel++)
  {
    Icu_17_GtmCcu6_AsilGtmVarlist.EdgeCountValuePtr[Channel] = 0UL; 
  }
  #endif
  #if (ICU_QM_TIM_EDGECNT_USED== STD_ON)
  for(Channel = 0U; Channel < ICU_GETMAXEDGECNTQMCHANNELS; Channel++)
  {
    Icu_17_GtmCcu6_QmVarlist.EdgeCountValuePtr[Channel] = 0UL; 
  }
  #endif
  /* ICU_EDGE_COUNT_API == STD_ON */
  #endif
  
}
  /* End of Icu_lResetGlobalVariables */


#if( (ICU_MAX_ASIL_GTM_CHANNELS != 0U)  || (ICU_MAX_QM_CHANNELS != 0U)  )
#if((ICU_GET_INPUT_STATE_API == STD_ON) && (ICU_EDGE_DETECT_API == STD_ON) && \
     (ICU_TIM_SIGEDGE_USED == STD_ON))
/******************************************************************************
** Syntax : static Icu_17_GtmCcu6_InputStateType                             **
**                                    Icu_lGtmGetInputStateEdgeDetect(       **
**                                       Icu_17_GtmCcu6_ChannelType CellUsed,**
**                          Icu_17_GtmCcu6_ChannelType PhysicalChannelIndex) **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant for different channel numbers                **
**                                                                           **
** Parameters (in):   AssignedHwUnit - GTM or ERU uses the channel           **
**                    CellUsed - GTM or ERU channel Number                   **
**                    Channel - ICU Channel Number                           **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Input State value                                      **
**                                                                           **
** Description :      Local function :Service to get the Input State for     **
**                    channels configured for Edge Detection                 **
*****************************************************************************/
static Icu_17_GtmCcu6_InputStateType Icu_lGtmGetInputStateEdgeDetect
(
   Icu_17_GtmCcu6_ChannelType CellUsed,
   Icu_17_GtmCcu6_ChannelType PhyChannelIndex, 
   uint8 ChlType
)
{
  uint32 NotifStatus;
  uint8 IrqNotifyStatus;
  Icu_17_GtmCcu6_InputStateType Status;
#if(ICU_MAX_ASIL_GTM_CHANNELS != 0U)  || (ICU_MAX_QM_CHANNELS != 0U)
  uint32 *Ptr = NULL_PTR;
#endif  
  Status = ICU_IDLE;  
    /* Ptr = NULL_PTR; */
  #if(ICU_MAX_ASIL_GTM_CHANNELS != 0U)     
  if(ChlType == ICU_GTM_ASIL_CHANNEL)
  { 
    Ptr = &Icu_17_GtmCcu6_AsilGtmVarlist.GlbIndexStatus[PhyChannelIndex];
  }
  else 
  #else
  UNUSED_PARAMETER(ChlType)  
  #endif  
  {
    #if(ICU_MAX_QM_CHANNELS != 0U)   
    Ptr = &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex];
    #endif
  }
  IrqNotifyStatus = Icu_lGtmGetIrqNotify(CellUsed); 
  #if(ICU_MAX_ASIL_GTM_CHANNELS != 0U)  || (ICU_MAX_QM_CHANNELS != 0U)
  
  NotifStatus  =     (uint32)Mcal_Extract(*Ptr,
                                   ICU_CHNL_NOTIF_STATUS_POS,
                                   ICU_CHNL_NOTIF_STATUS_BIT_LENGTH);
  #endif                                  
               
  if(((IrqNotifyStatus & 1U) == 1U) || (NotifStatus > 0U))
  {
    Status = ICU_ACTIVE;
    /* Stored status of Interrupt Notify bit is cleared */ 
#if( (ICU_MAX_ASIL_GTM_CHANNELS != 0U)  || (ICU_MAX_QM_CHANNELS != 0U))      
    Mcal_SetAtomic((sint32*)(void*)Ptr,
                   0,
                   ICU_CHNL_NOTIF_STATUS_POS,
                   ICU_CHNL_NOTIF_STATUS_BIT_LENGTH);
#endif                   
    Icu_lGtmClearIrqNotify(CellUsed);   
  }
  
  return(Status);
}
#endif
#endif

/*#if((ICU_GET_INPUT_STATE_API == STD_ON) && (ICU_EDGE_DETECT_API == STD_ON) &&\
     (ICU_TIM_SIGEDGE_USED == STD_ON))*/


/* GTM Interface functions */
#if (ICU_GTM_TIM_USED == STD_ON)

/*******************************************************************************
** Traceability: [cover parentID=DS_AS_ICU054_2]
**                                                                            **
** Syntax : static void Icu_lGtmChannelInit()                                 **
**                                                                            **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non reentrant                                            **
**                                                                            **
** Parameters (in):  none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to initialize ICU Channels. This function is    **
**                   needed to initialize GTM channels used by ICU. This is   **
**                   mainly needed while changing the PB configuration of ICU **
**                   while not changing the MCU configuration.                **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmChannelInit(void)
{

const Icu_17_GtmCcu6_ChannelConfigType* LocalIcuChanPtr;
Gtm_GlobalChannelNumberType TimChannelNumber;
Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId;
Ifx_GTM_TIM_CH_TYPE *TimChannelRegPtr;


uint8 ModuleNumber;                   
uint8 ChannelNumber; 
uint8 Channel; 
Icu_17_GtmCcu6_ChannelType MaxChannels; 

  /* Get the maximum number of channels */
  MaxChannels = ICU_GETMAXSIGEDGEQMCHANNELS +
                ICU_GETMAXEDGECNTQMCHANNELS +
                ICU_GETMAXTIMSTMPQMCHANNELS +
                ICU_GETMAXSIGMEASQMCHANNELS;
                
  #if (ICU_SAFETY_ENABLE == STD_ON)   
  MaxChannels += ICU_GETMAXSIGEDGEASILCHANNELS +
                ICU_GETMAXEDGECNTASILGTMCHANNELS +
                ICU_GETMAXTIMSTMPASILGTMCHANNELS +
                ICU_GETMAXSIGMEASASILCHANNELS;
  #endif     

 for(Channel = 0U; Channel < MaxChannels; Channel++)
 {
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;
    TimChannelNumber 
     = (Gtm_GlobalChannelNumberType)
        LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
    if(LocalIcuChanPtr->IcuProperties.AssignedHwUnit == ICU_GTM_OPTION)
    {
      GlobalChannelId = Icu_lGtmChannelIdentifier(TimChannelNumber);
      ModuleNumber  = Icu_lGetGtmModuleNo(GlobalChannelId);
      ChannelNumber = GlobalChannelId.ChannelNo;
      TimChannelRegPtr = \
           &(((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
              CH_TIM[ModuleNumber]).CH[ChannelNumber]);
    /*  TimChannelRegPtr->CH_CTRL.B.CLK_SEL= 
       (LocalIcuChanPtr->IcuProperties.TimChannelClockSelect);      */             
    (TimChannelRegPtr->CH_CTRL.U) |=              
    (uint32_t)((uint32)(LocalIcuChanPtr->IcuProperties.
                TimChannelClockSelect) << ICU_GTM_TIM_CLOCKDIV_POS);         
      TimChannelRegPtr->CH_FLT_RE.U = 
       (uint32_t)(LocalIcuChanPtr->IcuProperties.TimChFilterTimeForRisingEdge);
      TimChannelRegPtr->CH_FLT_FE.U = 
       (uint32_t)(LocalIcuChanPtr->IcuProperties.TimChFilterTimeForFallingEdge);
      TimChannelRegPtr->CH_IRQ_MODE.U = 
        (uint32_t)(LocalIcuChanPtr->IcuProperties.TimInterruptMode);
      TimChannelRegPtr->CH_IRQ_NOTIFY.U = (uint32_t)ICU_GTM_CLEAR_INTERRUPTS;   
    }  
 }

}




/*******************************************************************************
** Traceability : NA                                                          **
**                                                                            **
** Syntax : Gpt_ChannelIdentifierType Gpt_lGtmChannelIdentifier               **
**                           (Gtm_GlobalChannelNumberType GlobalChannelNumber)**
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Reentrant                                                   **
**                                                                            **
** Parameters (in):    GlobalChannelNumber - Channel Number                   **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:  Structure which gives Module Number, Channel Number etc     **
**                                                                            **
** Description :  This routine converts the Global Channel Number to its      **
**                corresponding Channel Number, Module Number, TGC/AGC number.**
**                                                                            **
*******************************************************************************/
Icu_17_GtmCcu6_ChannelIdentifierType
      Icu_lGtmChannelIdentifier(Gtm_GlobalChannelNumberType GlobalChannelNumber)
{
  Icu_17_GtmCcu6_ChannelIdentifierType ChannelIdentifier;

  #ifdef IFX_ICU_DEBUG
  /* Calculate Module Id of the TIM channel */
  ChannelIdentifier.ModuleId  =
     (uint8)((GlobalChannelNumber / GTM_CHANNELS_PER_TIM_MODULE) << \
      GTM_CHAN_ID_MOD_NO_POS);
  /* Calculate Channel number of the TIM channel */
  ChannelIdentifier.ChannelNo =
                       (GlobalChannelNumber % GTM_CHANNELS_PER_TIM_MODULE);
  GlobalChannelNumber = TestIcu_DebugGlobChNo;
  #else
  ChannelIdentifier.ChannelNo = ICU_GTM_INVALID_NUMBER;
  ChannelIdentifier.ModuleId = ICU_GTM_INVALID_NUMBER;  
  #endif  

/*  #if(GTM_TIM_USED_BY_OTHER_DRIVERS == STD_ON) */
  /* Check if its a TIM channel */
  if((GlobalChannelNumber < GTM_MAX_TIM_CHANNELS))
  {
    /* Calculate Module Id of the TIM channel */
    ChannelIdentifier.ModuleId  =
     (uint8)((GlobalChannelNumber / GTM_CHANNELS_PER_TIM_MODULE) << \
     GTM_CHAN_ID_MOD_NO_POS);
    /* Calculate Channel number of the TIM channel */
    ChannelIdentifier.ChannelNo =
                            (GlobalChannelNumber % GTM_CHANNELS_PER_TIM_MODULE);  
  }
 /* #endif    #if(GTM_TIM_USED_BY_OTHER_DRIVERS == STD_ON)   */

  return (ChannelIdentifier);
}



#if ((ICU_TIM_SIGEDGE_USED == STD_ON) &&(ICU_EDGE_DETECT_API == STD_ON))
/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU365]
** Syntax : static void Icu_lGtmStartEdgeDetect(                              **
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
static void Icu_lGtmStartEdgeDetect
                               (Gtm_GlobalChannelNumberType GlobalChannelNumber,
                                uint8 ActiveEdge)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                          /* Holds the TIM module Number   */

  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);

  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  /* Get the pointer to TIM Channel Register Structure */
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                               CH_TIM[ModuleNo].CH[GlobalChannelId.ChannelNo]);

  /* Clear all Pending Interrupts */
  TimChannelRegPtr->CH_IRQ_NOTIFY.U = ICU_GTM_CLEAR_INTERRUPTS; 
  /* Clear the previous Edge Value */
  TimChannelRegPtr->CH_CTRL.U &= 
                         (uint32_t)~(ICU_THREE_UL << ICU_TIM_CTRL_DSL_POS);
  TimChannelRegPtr->CH_CTRL.U |= (uint32_t)((ICU_GTM_TIM_MODE_TIEM << 1)   |   \
                                (((uint32)ActiveEdge) << ICU_TIM_CTRL_DSL_POS));
  TimChannelRegPtr->CH_CTRL.U |= ICU_GTM_TIM_ENABLE_CHANNEL ; 
}


/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lGtmEdgeDetectModeInit(                  **
**                    const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr,**
                      Icu_17_GtmCcu6_ChannelType CellUsed)                    **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  LocalIcuChanPtr - ICU Channel config pointer             **
**                   CellUsed - TIM Channel used                              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to configure TIM Channel given by               **
**                   CellUsed to start enabling Edge detection                **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lGtmEdgeDetectModeInit(
                        const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr,
                        Icu_17_GtmCcu6_ChannelType CellUsed)
{
  uint8 GtmEdge;
  if (LocalIcuChanPtr->IcuProperties.MeasurementMode
                                                 == ICU_MODE_SIGNAL_EDGE_DETECT)
  {
    /* Cells are enabled to make Icu_17_GtmCcu6_GetInputState function  work */
    GtmEdge = (uint8)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge);
    Icu_lGtmStartEdgeDetect(CellUsed,GtmEdge);
  }
}

#endif

/* #if ((ICU_TIM_SIGEDGE_USED == STD_ON) &&(ICU_EDGE_DETECT_API == STD_ON)) */


#if (ICU_DE_INIT_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_ICU036_ICU091,DS_AS_ICU300]
** Syntax : void Icu_lGtmResetChannels()                                      **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This function loops through all the channels, check if   **
**                   the channel is configured for ICU, if yes, then it will  **
**                   set the bit corresponding to this channel in the Reset   **
**                   Register. This puts all the register values corresponding**
**                   to this channel to their Power-On Reset values           **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmResetChannels(void)
{
  const Icu_17_GtmCcu6_ChannelConfigType* LocalIcuChanPtr;
  Gtm_GlobalChannelNumberType TImChannelNumber;
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId;
    Ifx_GTM_TIM_IN_SRC_RESET_TYPE *TimInScrRegPtr;  
  
  uint8 ModuleNumber;           
  uint8 ChannelNumber; 
  uint8 Channel; 
  Icu_17_GtmCcu6_ChannelType MaxChannels; 

  /* Get the maximum number of channels */
  MaxChannels = ICU_GETMAXSIGEDGEQMCHANNELS +
                ICU_GETMAXEDGECNTQMCHANNELS +
                ICU_GETMAXTIMSTMPQMCHANNELS +
                ICU_GETMAXSIGMEASQMCHANNELS;
                
  #if (ICU_SAFETY_ENABLE == STD_ON)   
  MaxChannels += ICU_GETMAXSIGEDGEASILCHANNELS +
                ICU_GETMAXEDGECNTASILGTMCHANNELS +
                ICU_GETMAXTIMSTMPASILGTMCHANNELS +
                ICU_GETMAXSIGMEASASILCHANNELS;
  #endif 
  
   for(Channel = 0U; Channel < MaxChannels; Channel++)
   {
    LocalIcuChanPtr = ((Icu_kConfigPtr->ChannelConfigPtr) + Channel);
    TImChannelNumber = LocalIcuChanPtr->IcuProperties.AssignedHwUnit;
        if(LocalIcuChanPtr->IcuProperties.AssignedHwUnit == ICU_GTM_OPTION)        
      {
     GlobalChannelId = Icu_lGtmChannelIdentifier(TImChannelNumber);
  
     ModuleNumber = Icu_lGetGtmModuleNo(GlobalChannelId);
     ChannelNumber = GlobalChannelId.ChannelNo;
 
         TimInScrRegPtr = &(((*(Ifx_GTM_TIMx*)(void *)(MODULE_GTM.TIM)).
                                      IN_SRC_RST[ModuleNumber].IN_SRC_RESET));
    
     TimInScrRegPtr->RST.U = (uint32_t)(ICU_SET_BIT << (ChannelNumber));        
    }
   }
}
#endif



/* #if (ICU_DE_INIT_API == STD_ON) */

#if ((ICU_TIMESTAMP_API == STD_ON) || \
((ICU_TIM_SIGEDGE_USED == STD_ON) && (ICU_SET_MODE_API == STD_ON)))
/*******************************************************************************
** Syntax : static void Icu_lGtmDisableChannel(                               **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber **
**                                    )                                       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to disable ICU channel                          **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmDisableChannel(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber
                                   )
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE *TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */
    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;
  TimChannelRegPtr =  &(((*(Ifx_GTM_TIMx*)(void *)(MODULE_GTM.TIM)).
                                              CH_TIM[ModuleNo].CH[ChannelNo]));
  /* TIM Channel enable bit is cleared */
  TimChannelRegPtr->CH_CTRL.U &= (uint32_t)(~ICU_GTM_TIM_ENABLE_CHANNEL);
} 
#endif

/* #if ((ICU_TIMESTAMP_API == STD_ON) || \
((ICU_TIM_SIGEDGE_USED == STD_ON) && (ICU_SET_MODE_API == STD_ON)))
 */


/*******************************************************************************
** Syntax : void Icu_lGtmIrqModify(                                           **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint8 InterruptFlag                             **
**                               )                                            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   InterruptFlag - Interrupt Enable bits to set             **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to enable/Disable TIM Interrupts                **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmIrqModify(Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                      uint8 InterruptFlag)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;  
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                                CH_TIM[ModuleNo].CH[ChannelNo]);
  /* Enable/Disable Interrupt */
  TimChannelRegPtr->CH_IRQ_EN.U     = InterruptFlag;
}

/*******************************************************************************
** Syntax : void Icu_lGtmClearIrqNotify (                                     **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber **
**                               )                                            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to Clear TIM Interrupt Notifications            **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmClearIrqNotify(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;  
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                               CH_TIM[ModuleNo].CH[ChannelNo]);
  /* Clear all Pending Interrupts */
  TimChannelRegPtr->CH_IRQ_NOTIFY.U = ICU_GTM_CLEAR_INTERRUPTS;
}

/*******************************************************************************
** Syntax : uint8 Icu_lGtmGetIrqNotify (                                      **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber **
**                               )                                            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     Notify value                                             **
**                                                                            **
** Description :     Function to get TIM Interrupt Notifications              **
**                                                                            **
*******************************************************************************/
static uint8 Icu_lGtmGetIrqNotify(                                             \
                                Gtm_GlobalChannelNumberType GlobalChannelNumber)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;  
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                                CH_TIM[ModuleNo].CH[ChannelNo]);
  /* Clear all Pending Interrupts */
  return((uint8)(TimChannelRegPtr->CH_IRQ_NOTIFY.U & \
                                                     ICU_GTM_CLEAR_INTERRUPTS));
}

/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU090_3]
** Syntax : void Icu_lGtmChangeActiveEdge(                                    **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint8 ActiveEdge                                **
**                                      )                                     **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   ActiveEdge - Edge to be detected                         **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to change the Edge detected by the TIM Channel  **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmChangeActiveEdge(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber,
                                uint8 ActiveEdge)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint32_t TempRegVal;
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;    
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                               CH_TIM[ModuleNo].CH[ChannelNo]);
  /* Clear all Pending Interrupts */
  TimChannelRegPtr->CH_IRQ_NOTIFY.U = ICU_GTM_CLEAR_INTERRUPTS;  
  /* Clear the previous Edge Value */ 
  TempRegVal = TimChannelRegPtr->CH_CTRL.U;
  TempRegVal &= (uint32_t)~(ICU_THREE_UL << ICU_TIM_CTRL_DSL_POS); 
  TempRegVal |= (uint32_t)(((uint32)ActiveEdge) << ICU_TIM_CTRL_DSL_POS) ;
  TimChannelRegPtr->CH_CTRL.U = TempRegVal;
}

#if (ICU_TIMESTAMP_API == STD_ON)
/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU063]

** Syntax : static void Icu_lGtmStartTimeStamp(                               **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint8 ActiveEdge                                **
**                                    )                                       **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   ActiveEdge - Edge to be detected                         **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to configure a TIM Channel to start  capturing  **
**                   TBU Timestamps whenever an Edge given by "ActiveEdge" is **
**                   detected. The channel must be in the disabled state      **
**                   before calling this function                             **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmStartTimeStamp(
                           Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                           uint8 ActiveEdge)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;  

  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                                CH_TIM[ModuleNo].CH[ChannelNo]);
  /* Clear the previous Edge Value */ 
  TimChannelRegPtr->CH_CTRL.U &= \
                            (uint32_t)(~(ICU_THREE_UL << ICU_TIM_CTRL_DSL_POS));
  TimChannelRegPtr->CH_CTRL.U |= (uint32_t)((ICU_GTM_TIM_MODE_TIEM << 1) | 
                                (((uint32)ActiveEdge) << ICU_TIM_CTRL_DSL_POS));
  TimChannelRegPtr->CH_CTRL.U |= ICU_GTM_TIM_ENABLE_CHANNEL ;  
  /* Clear all Pending Interrupts */
  TimChannelRegPtr->CH_IRQ_NOTIFY.U = ICU_GTM_CLEAR_INTERRUPTS;
  TimChannelRegPtr->CH_IRQ_EN.U     = (1UL <<ICU_GTM_TIM_NEWVAL_IRQ);
}

/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU067]

** Syntax : static void Icu_lGtmStopTimeStamp(                                **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber **
**                                    )                                       **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to configure a TIM Channel to stop  capturing   **
**                   TBU Timestamps                                           **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmStopTimeStamp(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */ 
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */
    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;    
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                               CH_TIM[ModuleNo].CH[ChannelNo]);
  TimChannelRegPtr->CH_CTRL.U &= ~ICU_GTM_TIM_ENABLE_CHANNEL ;
  TimChannelRegPtr->CH_IRQ_EN.U     = 0UL;
  /* Clear all Pending Interrupts */
}



/*******************************************************************************
** Syntax : static uint32 Icu_lGtmGetTimeStamp  (                             **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber **
**                                      )                                     **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     Timestamp value                                          **
**                                                                            **
** Description :     Function to get  the timestamp value captured by the TIM **
**                   Channel                                                  **
**                                                                            **
*******************************************************************************/
static uint32 Icu_lGtmGetTimeStamp(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;    
  
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                                CH_TIM[ModuleNo].CH[ChannelNo]);
  return(TimChannelRegPtr->CH_GPR0.U & (uint32)GTM_TIMER_MASK);
}


/*******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU064,DS_AS_ICU065]
** Syntax : static void Icu_lTimeStampBufferLimitCheck  (                     **
**                          Icu_17_GtmCcu6_TimestampBufferType MeasureKind,   **
**                          Icu_17_GtmCcu6_ChannelType CellNum,               **
**                          uint32 ChIndex)                                   **
**                                                                            **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  MeasureKind - Signal Type                                **
**                   TimestampIndex - Current Timestamp Index value           **
**                   Channel - Channel Number                                 **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to check the Timestamp Buffer limit             **
**                                                                            **
*******************************************************************************/
static void Icu_lTimeStampBufferLimitCheck(
                                Icu_17_GtmCcu6_TimestampBufferType MeasureKind, 
                                Icu_17_GtmCcu6_ChannelType CellNum,
                                uint32 ChIndex, uint8 ChlType)
{
  uint16 Counter;
  uint16 Size;
#if (ICU_SAFETY_ENABLE == STD_ON)
if(ChlType == ICU_GTM_ASIL_CHANNEL)
{  
 #if(ICU_MAX_TIMESTAMP_ASIL_CHANNELS != 0U)
  Counter =  Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].Counter;
  Size =  Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].Size;

  if ( Counter == Size)
  {
    if (MeasureKind == ICU_LINEAR_BUFFER)
    {
      /* Linear Buffer the counter has reached the size */
      /* Disable the Cell */
      /* ICU065: Disable for Linear buffer */
      Icu_lGtmDisableChannel(CellNum);
    }
    else
    {
      /*ICU064: restart for circular buffer */
      /* Circular Buffer reassign the Counter to 0 */

        Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].Counter = 0U;   
        Size =  Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].Size;
        /* Bring back the address to original position */
        Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].Address -= Size;
        /* Reassign the NotifyCounter to interval */
        Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].NotifyCounter -= 
                            Size;     
    }
  }
  #endif
}
else
#endif
{
 #if(ICU_MAX_TIMESTAMP_QM_CHANNELS != 0U)
  Counter =  Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].Counter;
  Size =  Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].Size;

  if ( Counter == Size)
  {
    if (MeasureKind == ICU_LINEAR_BUFFER)
    {
      /* Linear Buffer the counter has reached the size */
      /* Disable the Cell */
      /* ICU065: Disable for Linear buffer */
      Icu_lGtmDisableChannel(CellNum);
    }
    else
    {
      /*ICU064: restart for circular buffer */
      /* Circular Buffer reassign the Counter to 0 */

        Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].Counter = 0U;   
        Size =  Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].Size;
        /* Bring back the address to original position */
        Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].Address -= Size;
        /* Reassign the NotifyCounter to interval */
        Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].NotifyCounter -= Size;     
    }
  }
#endif  
}
UNUSED_PARAMETER(ChlType)
}


#endif
/* #if (ICU_TIMESTAMP_API == STD_ON) */

#if (ICU_EDGE_COUNT_API == STD_ON)
/*******************************************************************************
** Syntax : static void Icu_lGtmResetEdgeCount  (                             **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint32 *EdgeCountValuePtr                       **
**                                    )                                       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   EdgeCountValuePtr -Stores the edge counter value at      **
**                   previous enable                                          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to reset the Edge Count value captured by the   **
**                   channel                                                  **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmResetEdgeCount(
                           Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                           uint32 *EdgeCountValuePtr)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;    
  
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                                CH_TIM[ModuleNo].CH[ChannelNo]);

  /* Reset the previous Edge Count value */
  *EdgeCountValuePtr = 0UL;

  /* The channel has to be put back to the previous state. For implementing
     this, the following is done */
  /* If Channel is Enabled */
  if((TimChannelRegPtr->CH_CTRL.U & ICU_GTM_TIM_ENABLE_CHANNEL) != 
                                                                (uint32_t)0UL) 
  {
    /* A channel enable will reset the CNT counter */
    TimChannelRegPtr->CH_CTRL.U &= ~ICU_GTM_TIM_ENABLE_CHANNEL ;
    TimChannelRegPtr->CH_CTRL.U |= ICU_GTM_TIM_ENABLE_CHANNEL ;
  }
  else /* If Channel is Disabled prior */
  {
    /* A channel enable will reset the CNT counter */
    TimChannelRegPtr->CH_CTRL.U |= ICU_GTM_TIM_ENABLE_CHANNEL ;
    TimChannelRegPtr->CH_CTRL.U &= ~ICU_GTM_TIM_ENABLE_CHANNEL ;
  }
} 

/*******************************************************************************
** Syntax : static void Icu_lGtmEnableEdgeCount  (                            **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint8 ActiveEdge,                               **
**                            uint32 *EdgeCountValuePtr                       **
**                                       )                                    **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   ActiveEdge - Edge that need to be counted                **
**                   EdgeCountValuePtr -Stores the edge counter value at      **
**                   previous enable                                          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to enable the TIM channel to start counting     **
**                   edges. The previous edge count value is updated in the   **
**                   location given by EdgeCountValuePtr. TIM channel must be **
**                   in the disabled state before calling this function.      **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmEnableEdgeCount(
                            Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                            uint8 ActiveEdge, 
                            uint32* EdgeCountValuePtr)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;    
  
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                              CH_TIM[ModuleNo].CH[ChannelNo]);

  /* Store the current Edge counter value */
  *EdgeCountValuePtr += TimChannelRegPtr->CH_CNT.U;
  /* Clear the previous Edge Value */ 
  TimChannelRegPtr->CH_CTRL.U &= 
                            (uint32_t)~(ICU_THREE_UL << ICU_TIM_CTRL_DSL_POS);
  /* Set the channel in TIEM mode and configure the Active Edge */
  TimChannelRegPtr->CH_CTRL.U |= (uint32_t)(((ICU_GTM_TIM_MODE_TIEM << 1) |
                           (((uint32)ActiveEdge) << ICU_TIM_CTRL_DSL_POS)));
  /* Enable the channel */
  TimChannelRegPtr->CH_CTRL.U |= ICU_GTM_TIM_ENABLE_CHANNEL ;  
}


/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU079]

** Syntax : static void Icu_lGtmDisableEdgeCount  (                           **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber,**
**                                        )                                   **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to disable the TIM channel from counting edges  **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmDisableEdgeCount(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;    
  
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                              CH_TIM[ModuleNo].CH[ChannelNo]);
  TimChannelRegPtr->CH_CTRL.U &= ~ICU_GTM_TIM_ENABLE_CHANNEL ;
}

/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU080]

** Syntax : void Icu_17_GtmCcu6_EdgeNumberType Icu_lGtmGetEdgeNumbers  (      **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint32 *EdgeCountValuePtr                       **
**                                      )                                     **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   EdgeCountValuePtr -Stores the edge counter value at      **
**                   previous enable                                          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to return the Edge count as scanned by the      **
**                   channel                                                  **
**                                                                            **
*******************************************************************************/
static Icu_17_GtmCcu6_EdgeNumberType Icu_lGtmGetEdgeNumbers(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber,
                                const uint32* EdgeCountValuePtr)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId;
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;    
  
  TimChannelRegPtr =&((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                               CH_TIM[ModuleNo].CH[ChannelNo]);
  return((*EdgeCountValuePtr) + (TimChannelRegPtr->CH_CNT.U));
}


#endif
/* #if (ICU_EDGE_COUNT_API == STD_ON) */

#if ((ICU_EDGE_DETECT_API == STD_ON) && (ICU_TIM_SIGEDGE_USED == STD_ON))
/*******************************************************************************
** Syntax : void Icu_lGtmStopEdgeDetect  (                                    **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber,**
**                                      )                                     **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to stop a channel from counting Edges           **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmStopEdgeDetect(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;    
  
  TimChannelRegPtr =&((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                                CH_TIM[ModuleNo].CH[ChannelNo]);

  /* Disable the Channel */
  TimChannelRegPtr->CH_CTRL.U &= ~ICU_GTM_TIM_ENABLE_CHANNEL ;
  /* Clear any pending interrupt */
}
#endif

/* #if ((ICU_EDGE_DETECT_API == STD_ON) && (ICU_GTM_TIM_USED == STD_ON)) */

#if ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) && (ICU_TIM_SIGMEAS_USED == STD_ON))
/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU140]

** Syntax : static void Icu_lGtmStartSignalMeasurement(                       **
**                 Gtm_GlobalChannelNumberType GlobalChannelNumber,           **
**                 Icu_17_GtmCcu6_SignalMeasurementPropertyType SignalMode    **
**                                            )                               **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   SignalMode - To choose the measurement mode              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to enable the channel to start measurement of   **
**                   the type given by SignalMode. TIM channel must be        **
**                   disabled before this function is called.                 **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmStartSignalMeasurement(
                        Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                        Icu_17_GtmCcu6_SignalMeasurementPropertyType SignalMode)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */
  uint32 TempRegVal;
    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;  

  TimChannelRegPtr = &(((*(Ifx_GTM_TIMx*)(void *)(MODULE_GTM.TIM)).
                                               CH_TIM[ModuleNo].CH[ChannelNo]));

  TempRegVal = (uint32)(TimChannelRegPtr->CH_CTRL.U & \
                                       ((uint32_t)~(ICU_TIM_GET_LOWER_16BITS)));
  /* In case of High Time or Low Time Measurement, CNTS need to be cleared */
  if((SignalMode & ICU_TIM_GET_LOWER_NIBBLE_U) == 0U)
  {
    /* Setting the Ctrl Register to TIPM mode to clear the CNTS value */
    TempRegVal |= ICU_GTM_TIM_MODE_TIPM << 1;
    TimChannelRegPtr->CH_CTRL.U = TempRegVal;
    TimChannelRegPtr->CH_CNTS.U = 0UL;
    TempRegVal &= (~(ICU_TIM_GET_LOWER_NIBBLE_UL));
  }
  /* Mode, SL and DSL, GPR0_SEL, GPR1_SEL*/ 
  TempRegVal |= (uint32)(((uint32)(((uint32)((uint32)SignalMode & \
     (uint32)ICU_TIM_GET_UPPER_NIBBLE_U))<< ICU_TIM_CTRL_GPR0SELBIT1_POS)) |\
     (uint32)(ICU_THREE_UL << ICU_TIM_CTRL_GPR0SEL_POS) |\
     (uint32)(ICU_THREE_UL << ICU_TIM_CTRL_GPR1SEL_POS)) ;

  TimChannelRegPtr->CH_CTRL.U = TempRegVal;

  /* Channel is enabled */
  TimChannelRegPtr->CH_CTRL.U |= ICU_GTM_TIM_ENABLE_CHANNEL ;  
  /* Clear all pending interrupts */
  TimChannelRegPtr->CH_IRQ_NOTIFY.U = ICU_GTM_CLEAR_INTERRUPTS;

  /* In case of High Time or Low Time Measurement, ECNT Overflow 
     Interrupt must be enabled */
  if((SignalMode & ICU_TIM_GET_LOWER_NIBBLE_U) == 0U)
  {
    /* Enable ECNT Overflow Interrupt */
    TimChannelRegPtr->CH_IRQ_EN.U  |= (uint32_t)ICU_TIM_IRQ_ECNT_MASK;      
  }
}

/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU143,DS_AS_ICU146]

** Syntax : static void Icu_lGtmStopSignalMeasurement(                        **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber **
**                                            )                               **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to configures the channel to stop signal        **
**                   measurement                                              **
**                                                                            **
*******************************************************************************/
static void Icu_lGtmStopSignalMeasurement(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber
                                 )
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

    
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;  

  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                              CH_TIM[ModuleNo].CH[ChannelNo]);
  /* Channel is disabled */
  TimChannelRegPtr->CH_CTRL.U &= ~ICU_GTM_TIM_ENABLE_CHANNEL ;
  /* Disable Interrupts - mainly applicable in case of HIG/LOW time
     measurement. */
  TimChannelRegPtr->CH_IRQ_EN.U     = 0UL;  
  
}



#endif

/* #if ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) && \
        (ICU_TIM_SIGMEAS_USED == STD_ON)) */

#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) && (ICU_TIM_SIGMEAS_USED == STD_ON))
/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU081_ICU082,
   DS_AS_ICU136_1_ICU339_1_ICU340_1,DS_AS_ICU083,
   DS_AS_ICU136_2_ICU339_2_ICU340_2]

** Syntax : Icu_17_GtmCcu6_ValueType Icu_lGtmGetTimeElapsed(                  **
**                 Gtm_GlobalChannelNumberType GlobalChannelNumber,           **
**                 Icu_17_GtmCcu6_SignalMeasurementPropertyType SignalMode,   **
**                 uint8 *InfoPtr                                             **
**                 uint8 ChlType                                              **
**                                      )                                     **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   SignalMode - Signal Mode for Measurement                 **
**                   InfoPtr - This pointer has multiple purpose.             **
**                             a) In case of High/Low time measurement, this  **
**                                holds the previous edge count value. This is**
**                                also updated with the present Edge count.   **
**                             b) In case of Period measurement, this acts as **
**                                a flag for knowing if NewVal notify bit is  **
**                                cleared by this function or                 **
**                                Icu_lGtmGetInputState function.             **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     High Time/Low Time or Period is returned depending on the**
**                   Signal Mode parameter                                    **
**                                                                            **
** Description :     Function to get the High/Low/Period values of a channel  **
**                   running in Signal Measurement mode                       **
**                                                                            **
*******************************************************************************/
static Icu_17_GtmCcu6_ValueType Icu_lGtmGetTimeElapsed
                        (Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                        Icu_17_GtmCcu6_SignalMeasurementPropertyType SignalMode,
                        uint8 *InfoPtr,
                        uint8 ChlType)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint32 TempReg;                            /* Holds the CNTS value          */
  uint32 RetVal;                             /* Return Value                  */
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */
  uint8 CheckStatus;                         /* Flag information              */  
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;    
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                                CH_TIM[ModuleNo].CH[ChannelNo]);
  RetVal = 0U; 
  /* High or Low Time Requested */
  if((SignalMode & ICU_TIM_GET_LOWER_NIBBLE_U) == 0x00U) 
  {
    TempReg = TimChannelRegPtr->CH_CNTS.U;

    /* High Time Requested */
    if((SignalMode & ICU_TIM_GET_UPPER_NIBBLE_U) == ICU_BIT_4_MASK)  
    {
      CheckStatus = Icu_lGtmGetTimeElapsedHighTime(TempReg, 
                                                   InfoPtr, 
                                                   ModuleNo, 
                                                   ChannelNo,
                                                   ChlType);

    }
    else /* Low Time Requested */
    {
      CheckStatus = Icu_lGtmGetTimeElapsedLowTime(TempReg, 
                                                   InfoPtr, 
                                                   ModuleNo, 
                                                   ChannelNo,ChlType);
    }

   *InfoPtr = (uint8)((TempReg &ICU_TIM_EDGE_COUNT_INFO)>>ICU_BRING_TO_LSB_32);
  
    /* Compare Edge Count */
   RetVal= Icu_lGtmGetTimeElapsedResult(TempReg, CheckStatus);   

if(ChlType == ICU_GTM_ASIL_CHANNEL)
{
#if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON) 
    if(( Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] &  \
      (uint16)(ICU_THREE_UL << (ChannelNo * ICU_BITS_PER_CHANNEL)))> (uint16)0U)
    {
      Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] &=  \
                 ~(uint16)(ICU_THREE_UL << (ChannelNo * ICU_BITS_PER_CHANNEL));
    
    }
#endif  
}
else
{
#if (ICU_QM_TIM_SIGMEAS_USED == STD_ON) 
    if(( Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] &  \
   (uint16)(ICU_THREE_UL << (ChannelNo * ICU_BITS_PER_CHANNEL)))> (uint16)0U)
    {
       Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] &=  \
      ~(uint16)(ICU_THREE_UL << (ChannelNo * ICU_BITS_PER_CHANNEL));
    
        }
#endif 

}
      
  }
  /* Period Requested */
  else if((SignalMode & ICU_TIM_GET_LOWER_NIBBLE_U) == 0x01U) 
  {
    /* Check if a new value is available */
    if(((TimChannelRegPtr->CH_IRQ_NOTIFY.U & \
                          (1UL <<ICU_GTM_TIM_NEWVAL_IRQ)) > 0UL)|| \
                          (*InfoPtr == ICU_TWO_U))
    {
      *InfoPtr = 0U;
      /* Return the GPR1 value */
      RetVal = (uint32)(TimChannelRegPtr->CH_GPR1.U & (uint32_t)GTM_TIMER_MASK);
    }
    else
    {
      RetVal = 0UL;
    }
    if(TimChannelRegPtr->CH_IRQ_NOTIFY.U & (1UL <<ICU_GTM_TIM_NEWVAL_IRQ))
    {
      /* Clear the Notify bit */
      TimChannelRegPtr->CH_IRQ_NOTIFY.U |=
                                  (uint32_t)(1UL <<ICU_GTM_TIM_NEWVAL_IRQ);
      *InfoPtr = 1U;
    }
  }
  else
  {
    /* Do nothing */  
  }
  return(RetVal); 
  
}

/*******************************************************************************
** Syntax : static uint8 Icu_lGtmGetTimeElapsedHighTime(uint32 CntsVal,       **
**                                         const uint8 *InfoPtr,              **
**                                         uint8 ModuleNo,                    **
**                                         uint8 ChannelNo)                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CntsVal - Current CNTS register value                    **
**                   InfoPtr - This pointer has multiple purpose.             **
**                             a) In case of High/Low time measurement, this  **
**                                holds the previous edge count value. This is**
**                                also updated with the present Edge count.   **
**                             b) In case of Period measurement, this acts as **
**                                a flag for knowing if NewVal notify bit is  **
**                                cleared by this function or                 **
**                                Icu_lGtmGetInputState function.             **
**                   ModuleNo - TIM Module Number                             **
**                   ChannelNo - TIM Channel Number                           **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     High Time is returned depending on the                   **
**                   Signal Mode parameter                                    **
**                                                                            **
** Description :     Function to get the High values of a channel             **
**                   running in Signal Measurement mode                       **
**                                                                            **
*******************************************************************************/
static uint8 Icu_lGtmGetTimeElapsedHighTime(uint32 CntsVal, 
                                           const uint8 *InfoPtr, 
                                           uint8 ModuleNo, 
                                           uint8 ChannelNo,
                                           uint8 ChlType)
{
  uint8 CheckStatus;                         /* Flag information */

  CheckStatus = 0U;
 
 if(ChlType == ICU_GTM_ASIL_CHANNEL)
 {
#if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)  
  if((Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] & 
     (uint16)(ICU_THREE_UL << (ChannelNo * 2U))) == (uint16)0U)
  {
    if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32) == \
                                                                       *InfoPtr)
    {
      CheckStatus = 1U;  /* This means Return value should be 0 */
    }   
    if( ((*InfoPtr) % ICU_TWO_U) ==   0U)  /* Divisible by 2 */
    {
      if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32) ==\
                                                 (uint8)((*InfoPtr) + 1U))
      {
        CheckStatus = 1U;  /* This means Return value should be 0 */
      }
    }
  }
#endif  
 }
 else
 {
  #if (ICU_QM_TIM_SIGMEAS_USED == STD_ON)  
   if((Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] & 
      (uint16)(ICU_THREE_UL << (ChannelNo * 2U))) == (uint16)0U)
    {
     if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32) == \
                                           *InfoPtr)
     {
        CheckStatus = 1U;  /* This means Return value should be 0 */
     } 
     if( ((*InfoPtr) % ICU_TWO_U) ==   0U)  /* Divisible by 2 */
     {
      if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32) ==\
                                       (uint8)((*InfoPtr) + 1U))
      {
      CheckStatus = 1U;  /* This means Return value should be 0 */
      }
    }
    }
#endif   
  }

  return(CheckStatus);
}

/*******************************************************************************
** Syntax : static uint8 Icu_lGtmGetTimeElapsedLowTime(uint32 CntsVal,        **
**                                         const uint8 *InfoPtr,              **
**                                         uint8 ModuleNo,                    **
**                                         uint8 ChannelNo)                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CntsVal - Current CNTS register value                    **
**                   InfoPtr - This pointer has multiple purpose.             **
**                             a) In case of High/Low time measurement, this  **
**                                holds the previous edge count value. This is**
**                                also updated with the present Edge count.   **
**                             b) In case of Period measurement, this acts as **
**                                a flag for knowing if NewVal notify bit is  **
**                                cleared by this function or                 **
**                                Icu_lGtmGetInputState function.             **
**                   ModuleNo - TIM Module Number                             **
**                   ChannelNo - TIM Channel Number                           **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     Low Time is returned depending on the                    **
**                   Signal Mode parameter                                    **
**                                                                            **
** Description :     Function to get the Low values of a channel              **
**                   running in Signal Measurement mode                       **
**                                                                            **
*******************************************************************************/
static uint8 Icu_lGtmGetTimeElapsedLowTime(uint32 CntsVal, 
                                           const uint8 *InfoPtr, 
                                           uint8 ModuleNo, 
                                           uint8 ChannelNo,uint8 ChlType)
{
  uint8 CheckStatus;                         /* Flag information  */

  CheckStatus = 0U;
if(ChlType == ICU_GTM_ASIL_CHANNEL)
{
#if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)    
  if(( Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] &  \
      (uint16)(ICU_THREE_UL << (ChannelNo * ICU_TWO_U)))> (uint16)0U)
  {
    CheckStatus = 0U; 
  }
  else  
  { 
    if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32) ==  \
                                                                       *InfoPtr)
    {
      CheckStatus = 1U;  /* This means Return value should be 0 */
    }   
    if( ((*InfoPtr) % ICU_TWO_U) ==   1U)  /* Divisible by 2 */
    {
      if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32) ==\
                                                 (uint8)((*InfoPtr) + 1U))
      {
        CheckStatus = 1U;  /* This means Return value should be 0 */
      }
    }
  }
  #endif  
 }
 else
 {
#if (ICU_QM_TIM_SIGMEAS_USED == STD_ON)    
  if(( Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] &  \
     (uint16)(ICU_THREE_UL << (ChannelNo * ICU_TWO_U)))> (uint16)0U)  
  {
    CheckStatus = 0U; 
  }
  else  
  { 
  if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32) ==  \
                                   *InfoPtr)
  {
    CheckStatus = 1U;  /* This means Return value should be 0 */
  } 
  if( ((*InfoPtr) % ICU_TWO_U) ==   1U)  /* Divisible by 2 */
  {
    if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32) ==\
                         (uint8)((*InfoPtr) + 1U))
    {
    CheckStatus = 1U;  /* This means Return value should be 0 */
    }
  }
  }
  #endif  
 }

  return(CheckStatus);

}


/*******************************************************************************
** Syntax : static uint32 Icu_lGtmGetTimeElapsedResult(uint32 CntsVal,        **
**                                         uint8 CheckStatus)                 **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CntsVal - Current CNTS register value                    **
**                   CheckStatus - New value available status                 **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     Low/High Time is returned depending on the               **
**                   Signal Mode parameter                                    **
**                                                                            **
** Description :     Function to get the High/Low values of a channel         **
**                   running in Signal Measurement mode                       **
**                                                                            **
*******************************************************************************/
static uint32 Icu_lGtmGetTimeElapsedResult(uint32 CntsVal, uint8 CheckStatus)
{
  uint32 RetVal;
  if(CheckStatus == 1U)
  {
  
    RetVal = 0UL;
  }
  else 
  { 
    RetVal = CntsVal & GTM_TIMER_MASK;
  }
  return(RetVal); 
}



#endif

/* #if ((ICU_GET_TIME_ELAPSED_API == STD_ON) && \
        (ICU_TIM_SIGMEAS_USED == STD_ON)) */

#if ((ICU_GET_INPUT_STATE_API == STD_ON) && (ICU_TIM_SIGMEAS_USED == STD_ON) &&\
  (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU314_ICU032_2]

** Syntax : Icu_17_GtmCcu6_InputStateType Icu_lGtmGetInputState(              **
**                 Gtm_GlobalChannelNumberType GlobalChannelNumber,           **
**                 Icu_17_GtmCcu6_SignalMeasurementPropertyType SignalMode,   **
**                 uint8 *InfoPtr                                             **
**                                    )                                       **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   SignalMode - Signal Mode for Measurement                 **
**                   InfoPtr - This pointer has multiple purpose.             **
**                             a) In case of High/Low time measurement, this  **
**                                holds the previous edge count value.        **
**                             b) In case of Period measurement, this acts as **
**                                a flag for knowing if NewVal notify bit is  **
**                                cleared by this function or                 **
**                                Icu_lGtmGetTimeElapsed function.            **
**                             c) If the value is NULL_PTR, the it would imply**
**                                that this is used for validation for Edge   **
**                                Detection                                   **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     ICU_ACTIVE - A new value is available                    **
**                   ICU_IDLE - No New value is available                     **
**                                                                            **
**                                                                            **
** Description :     Function to get the High/Low/Period values of a channel  **
**                   running in Signal Measurement mode.  Also in edge        **
**                   detection mode, this is return if a new value is         **
**                   available                                                **
**                                                                            **
*******************************************************************************/
static Icu_17_GtmCcu6_InputStateType Icu_lGtmGetInputState
                       (Gtm_GlobalChannelNumberType GlobalChannelNumber, 
                       Icu_17_GtmCcu6_SignalMeasurementPropertyType SignalMode, 
                       uint8* InfoPtr,uint8 ChlType)
{
  /* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE* TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint32 TempReg;
  uint8 RetVal;
  uint8 CheckStatus;  
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */

  
  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;    
  
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                                CH_TIM[ModuleNo].CH[ChannelNo]);
  
  /* High or Low Time Requested */
  if((SignalMode & ICU_TIM_GET_LOWER_NIBBLE_U) == 0x00U) 
  { 
    TempReg = TimChannelRegPtr->CH_CNTS.U;
    /* High Time Requested */
    if((SignalMode & ICU_TIM_GET_UPPER_NIBBLE_U) == 0x10U)  
    {
      CheckStatus = Icu_lGtmGetInputStateHighTime(TempReg, 
                                                  InfoPtr, 
                                                  ModuleNo, 
                                                  ChannelNo,ChlType);
    }
    else /* Low Time Requested */
    {
      CheckStatus = Icu_lGtmGetInputStateLowTime(TempReg, 
                                  InfoPtr, 
                                  ModuleNo, 
                                  ChannelNo,ChlType);
    }
    /* Compare Edge Count */
    RetVal = Icu_lGtmGetInputStateResult(TempReg, CheckStatus);
if(ChlType == ICU_GTM_ASIL_CHANNEL) 
{
#if(ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)
    if((Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForInputState[ModuleNo] &  \
                (uint16)(ICU_THREE_UL << (ChannelNo * ICU_TWO_U))) > (uint16)0U)
    {
      Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForInputState[ModuleNo] &=    \
                             ~(uint16)(ICU_THREE_UL << (ChannelNo * ICU_TWO_U));
    }    
#endif  
}
else
{
#if(ICU_QM_TIM_SIGMEAS_USED == STD_ON)
  if((Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForInputState[ModuleNo] &    \
                (uint16)(ICU_THREE_UL << (ChannelNo * ICU_TWO_U))) > (uint16)0U)
    {
      Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForInputState[ModuleNo] &=      \
                             ~(uint16)(ICU_THREE_UL << (ChannelNo * ICU_TWO_U));
    }   
#endif  
} 
   
    *InfoPtr = \
            (uint8)((TempReg & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32);
  } 
  /* Period Requested or  DutyCycle Requested */
  else  
  {
    if(((TimChannelRegPtr->CH_IRQ_NOTIFY.U & \
                                     (1UL <<ICU_GTM_TIM_NEWVAL_IRQ)) > 0UL)|| \
                                     (*InfoPtr == 1U))
    {
      *InfoPtr = 0U;
      RetVal = ICU_ACTIVE;
    }
    else
    {
      RetVal = ICU_IDLE;
    }
    if(TimChannelRegPtr->CH_IRQ_NOTIFY.U & (1UL <<ICU_GTM_TIM_NEWVAL_IRQ))
    {
      TimChannelRegPtr->CH_IRQ_NOTIFY.U |=
                                      (uint32_t)(1UL <<ICU_GTM_TIM_NEWVAL_IRQ);
      *InfoPtr = ICU_TWO_U;
    }
  }
      
  return(RetVal);     
}     

/*******************************************************************************
** Syntax : static uint8 Icu_lGtmGetInputStateResult(uint32 CntsVal,          **
**                                                   uint8 CheckStatus)       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CntsVal - Current CNTS Value                             **
**                   CheckStatus - New value availability status              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     ICU_ACTIVE - A new value is available                    **
**                   ICU_IDLE - No New value is available                     **
**                                                                            **
**                                                                            **
** Description :     Function to get the High/Low values of a channel         **
**                   running in Signal Measurement mode.                      **
**                                                                            **
*******************************************************************************/
static uint8 Icu_lGtmGetInputStateResult(uint32 CntsVal, 
                                          uint8 CheckStatus)
{
  uint8 RetVal;
  if((CheckStatus == 1U) || ((CntsVal & GTM_TIMER_MASK) == 0UL))
  {
    RetVal = ICU_IDLE;
  }
  else
  {
    RetVal = ICU_ACTIVE;
  }
  return(RetVal);
}



/*******************************************************************************
** Syntax : static uint8 Icu_lGtmGetInputStateLowTime(uint32 CntsVal,         **
**                                                    const uint8* InfoPtr,   **
**                                                    uint8 ModuleNo,         **
**                                                    uint8 ChannelNo)        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CntsVal - Current CNTS register value                    **
**                   InfoPtr - This pointer has multiple purpose.             **
**                             a) In case of High/Low time measurement, this  **
**                                holds the previous edge count value. This is**
**                                also updated with the present Edge count.   **
**                             b) In case of Period measurement, this acts as **
**                                a flag for knowing if NewVal notify bit is  **
**                                cleared by this function or                 **
**                                Icu_lGtmGetInputState function.             **
**                   ModuleNo - TIM Module Number                             **
**                   ChannelNo - TIM Channel Number                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     ICU_ACTIVE - A new value is available                    **
**                   ICU_IDLE - No New value is available                     **
**                                                                            **
**                                                                            **
** Description :     Function to get the Low values of a channel              **
**                   running in Signal Measurement mode.                      **
**                                                                            **
*******************************************************************************/
static uint8 Icu_lGtmGetInputStateLowTime(uint32 CntsVal, 
                                          const uint8* InfoPtr,
                                          uint8 ModuleNo,
                                          uint8 ChannelNo,uint8 ChlType)
{
  uint8 CheckStatus = 0U;
if(ChlType == ICU_GTM_ASIL_CHANNEL) 
{
#if(ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)  
  CheckStatus = 0U;  
  if((Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForInputState[ModuleNo] &  \
      (uint16)(ICU_THREE_UL << (ChannelNo * ICU_TWO_U))) > (uint16)0U)
  {
    CheckStatus = 0U; 
  }
  else
  { 
    if((CntsVal & GTM_TIMER_MASK) == 0U)
    {
      CheckStatus = 1U;  /* This means Return value should be 0 */
    }
    else if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32)\
                                                                   ==  *InfoPtr)
    {
      CheckStatus = 1U;  /* This means Return value should be 0 */
    }   
    else if( ((*InfoPtr) % ICU_TWO_U) ==   1U)  /* Divisible by 2 */
    {
      if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32)== \
                                                       (uint8)((*InfoPtr) + 1U))
      {
        CheckStatus = 1U;  /* This means Return value should be 0 */
      }
    }
    else
    {
      /* Do Nothing */
    }       
  }
 #endif
}
else
{
#if(ICU_QM_TIM_SIGMEAS_USED == STD_ON)  
    CheckStatus = 0U;  
  if((Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForInputState[ModuleNo] &    \
     (uint16)(ICU_THREE_UL << (ChannelNo * ICU_TWO_U))) > (uint16)0U)
  {
  CheckStatus = 0U; 
  }
  else
  { 
  if((CntsVal & GTM_TIMER_MASK) == 0U)
  {
    CheckStatus = 1U;  /* This means Return value should be 0 */
  }
  else if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32)\
                                   ==  *InfoPtr)
  {
    CheckStatus = 1U;  /* This means Return value should be 0 */
  } 
  else if( ((*InfoPtr) % ICU_TWO_U) ==   1U)  /* Divisible by 2 */
  {
    if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32)== \
                             (uint8)((*InfoPtr) + 1U))
    {
    CheckStatus = 1U;  /* This means Return value should be 0 */
    }
  }
  else
  {
    /* Do Nothing */
  }   
  }
 #endif

}
  return(CheckStatus);
}

/*******************************************************************************
** Syntax : static uint8 Icu_lGtmGetInputStateHighTime(uint32 CntsVal,        **
**                                                    const uint8* InfoPtr,   **
**                                                    uint8 ModuleNo,         **
**                                                    uint8 ChannelNo)        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CntsVal - Current CNTS register value                    **
**                   InfoPtr - This pointer has multiple purpose.             **
**                             a) In case of High/Low time measurement, this  **
**                                holds the previous edge count value. This is**
**                                also updated with the present Edge count.   **
**                             b) In case of Period measurement, this acts as **
**                                a flag for knowing if NewVal notify bit is  **
**                                cleared by this function or                 **
**                                Icu_lGtmGetInputState function.             **
**                   ModuleNo - TIM Module Number                             **
**                   ChannelNo - TIM Channel Number                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     ICU_ACTIVE - A new value is available                    **
**                   ICU_IDLE - No New value is available                     **
**                                                                            **
**                                                                            **
** Description :     Function to get the High values of a channel             **
**                   running in Signal Measurement mode.                      **
**                                                                            **
*******************************************************************************/
static uint8 Icu_lGtmGetInputStateHighTime(uint32 CntsVal, 
                                           const uint8* InfoPtr,
                                           uint8 ModuleNo,
                                           uint8 ChannelNo, uint8 ChlType)
{
  uint8 CheckStatus;
  
  CheckStatus = 0U; 
if(ChlType == ICU_GTM_ASIL_CHANNEL) 
{
#if(ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)
  if((Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForInputState[ModuleNo] &    \
               (uint16)(ICU_THREE_UL << (ChannelNo * ICU_TWO_U))) == (uint16)0U)
  {

    if((CntsVal & GTM_TIMER_MASK) == 0U)
    {
      CheckStatus = 1U;  /* This means Return value should be 0 */
    }
    else if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32)\
                                                                   ==  *InfoPtr)
    {
      CheckStatus = 1U;  /* This means Return value should be 0 */
    }   
    else if( ((*InfoPtr) % ICU_TWO_U) ==   0U)  /* Divisible by 2 */
    {
      if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32)== \
                                                       (uint8)((*InfoPtr) + 1U))
      {

        CheckStatus = 1U;  /* This means Return value should be 0 */
      }
    }
    else
    {
      /* Do Nothing */
    }
  }
 #endif  
}  

else
{
 #if(ICU_QM_TIM_SIGMEAS_USED == STD_ON)
  if((Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForInputState[ModuleNo] &        \
               (uint16)(ICU_THREE_UL << (ChannelNo * ICU_TWO_U))) == (uint16)0U)
  {

    if((CntsVal & GTM_TIMER_MASK) == 0U)
    {
      CheckStatus = 1U;  /* This means Return value should be 0 */
    }
    else if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32)\
                                                                   ==  *InfoPtr)
    {
      CheckStatus = 1U;  /* This means Return value should be 0 */
    }   
    else if( ((*InfoPtr) % ICU_TWO_U) ==   0U)  /* Divisible by 2 */
    {
      if((uint8)((CntsVal & ICU_TIM_EDGE_COUNT_INFO) >> ICU_BRING_TO_LSB_32)== \
                                                       (uint8)((*InfoPtr) + 1U))
      {

        CheckStatus = 1U;  /* This means Return value should be 0 */
      }
    }
    else
    {
      /* Do Nothing */
    }
  }
 #endif
 }  
  return(CheckStatus);
}

/*******************************************************************************
** Syntax : static Icu_17_GtmCcu6_InputStateType Icu_lGtmGetInputStateSigMeas(**
**                                        Icu_17_GtmCcu6_ChannelType CellUsed,**
**                                        Icu_17_GtmCcu6_ChannelType Channel) **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  AssignedHwUnit - GTM or ERU used                         **
**                   CellUsed - GTM channel used                              **
**                   Channel - ICU Channel Number                             **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     ICU_ACTIVE - A new value is available                    **
**                   ICU_IDLE - No New value is available                     **
**                                                                            **
**                                                                            **
** Description :     Function to get the availability of a new period/High/Low**
**                   values of a channel running in Signal Measurement mode.  **
**                                                                            **
*******************************************************************************/
static Icu_17_GtmCcu6_InputStateType Icu_lGtmGetInputStateSigMeas(
                                      Icu_17_GtmCcu6_ChannelType CellUsed,
                                      Icu_17_GtmCcu6_ChannelType Channel,
                                      uint8 ChlType)
{
  uint32 CfgEdge = 0U;
  uint32 DutyIndex = 0U;
  Icu_17_GtmCcu6_SignalMeasurementPropertyType GtmSigKind;
  Icu_17_GtmCcu6_SignalMeasurementPropertyType SigKind = 0U;  
  Icu_17_GtmCcu6_InputStateType Status = 0U;
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;
  LocalIcuMapPtr =   (Icu_kConfigPtr->MappingIndexPtr) + Channel;
  DutyIndex =LocalIcuMapPtr->ChannelIndexMap;
if(ChlType == ICU_GTM_ASIL_CHANNEL)
{
#if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)
  /* Retrieve the Index stored in IndexStore */
  
  /* The signal measure property is retrieved here */
  SigKind = Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].SigProp;
  CfgEdge = Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].CfgEdge;
#endif
}
else
{
#if (ICU_QM_TIM_SIGMEAS_USED == STD_ON)
    /* Retrieve the Index stored in IndexStore */
    /* The signal measure property is retrieved here */
  SigKind = Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].SigProp;
  CfgEdge = Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].CfgEdge;
#endif
}
#if ((ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)||(ICU_QM_TIM_SIGMEAS_USED == STD_ON))
  if(ICU_PERIOD_TIME == SigKind)
  { 
    if(ICU_FALLING_EDGE == CfgEdge )
    {
      GtmSigKind = ICU_PERIOD_TIME_LOW_DUTY;
    }
    else
    { 
      GtmSigKind = ICU_PERIOD_TIME_HIGH_DUTY;
    }
  }
  else if(ICU_ACTIVE_TIME == SigKind)
  { 
    if(ICU_FALLING_EDGE == CfgEdge)
    {
      GtmSigKind = ICU_ACTIVE_TIME_LOW_DUTY;
    }
    else
    { 
      GtmSigKind = ICU_ACTIVE_TIME_HIGH_DUTY;
    }
  }
  else if(ICU_HIGH_TIME == SigKind)
  {
    GtmSigKind = ICU_HIGH_TIME_GTM;
  }
  else
  {
    GtmSigKind = SigKind;
  }    
#endif  
  if(ChlType == ICU_GTM_ASIL_CHANNEL)
  {
#if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)
  Status = Icu_lGtmGetInputState(CellUsed,
                              GtmSigKind,
                              &Icu_17_GtmCcu6_AsilGtmVarlist.InfoPtr[DutyIndex],
                              ChlType);
#endif
    }
else
{
#if (ICU_QM_TIM_SIGMEAS_USED == STD_ON)
    Status = Icu_lGtmGetInputState(CellUsed,
                 GtmSigKind,
                 &Icu_17_GtmCcu6_QmVarlist.InfoPtr[DutyIndex],
                                  ChlType );
#endif

}
  
  return(Status);
}


#endif

/* 
#if ((ICU_GET_INPUT_STATE_API == STD_ON) && (ICU_GTM_TIM_USED == STD_ON) && \
  (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
*/  

#if ((ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) && \
     (ICU_TIM_SIGMEAS_USED == STD_ON))
/*******************************************************************************
** Traceability :   [cover parentID=DS_AS_ICU137_ICU343_ICU344,DS_AS_ICU084_1]
** Syntax : Icu_17_GtmCcu6_DutyCycleType Icu_lGtmGetDutyCycleValues(          **
**                            Gtm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint8 *InfoPtr                                  **
**                                                        )                   **
** [/cover]                                                                   **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel Number                     **
**                   InfoPtr - The value in this location acts as a kind of   **
**                             flag for knowing if NewVal notify bit is       **
**                             cleared by this function or                    **
**                             Icu_lGtmGetInputState function                 **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     Period and Duty cycle                                    **
**                                                                            **
**                                                                            **
** Description :     Function to get the Period and Duty Cycle value          **
**                                                                            **
*******************************************************************************/
static Icu_17_GtmCcu6_DutyCycleType Icu_lGtmGetDutyCycleValues(
                                Gtm_GlobalChannelNumberType GlobalChannelNumber,
                                uint8 *InfoPtr)
{
/* Structure to get Module info  */
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId; 
  Ifx_GTM_TIM_CH_TYPE *TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  Icu_17_GtmCcu6_DutyCycleType DutyCycleValue;
  uint8 ModuleNo;                            /* Holds the TIM module Number   */
  uint8 ChannelNo;                           /* Holds the TIM Channel Number  */


  GlobalChannelId = Icu_lGtmChannelIdentifier(GlobalChannelNumber);
  /* Extract Module Number and Channel Number */
  ModuleNo  = Icu_lGetGtmModuleNo(GlobalChannelId);
  ChannelNo = GlobalChannelId.ChannelNo;    
  
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                                               CH_TIM[ModuleNo].CH[ChannelNo]);

  /* Check if any new information is available */
  if(((TimChannelRegPtr->CH_IRQ_NOTIFY.U & \
                                     (1UL <<ICU_GTM_TIM_NEWVAL_IRQ)) > 0UL) || \
                                     (*InfoPtr == ICU_TWO_U))
  {
    *InfoPtr = 0U;
    DutyCycleValue.ActiveTime =                                              \
                            (TimChannelRegPtr->CH_GPR0.U) & 0x00FFFFFFUL;
    DutyCycleValue.PeriodTime =                                              \
                            (TimChannelRegPtr->CH_GPR1.U) & 0x00FFFFFFUL;
  }
  else
  {
    /* Return 0 if no new value is available */
    DutyCycleValue.ActiveTime = 0UL;
    DutyCycleValue.PeriodTime = 0UL;
  }
  if(TimChannelRegPtr->CH_IRQ_NOTIFY.U & (1UL <<ICU_GTM_TIM_NEWVAL_IRQ))
  {
    /* Clear the NewVal status */
    TimChannelRegPtr->CH_IRQ_NOTIFY.U |= 
                                 (uint32_t)(1UL <<ICU_GTM_TIM_NEWVAL_IRQ);
    *InfoPtr = 1U;
  }
  return(DutyCycleValue); 

}
#endif

/* #if ((ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) && \
     (ICU_TIM_SIGMEAS_USED == STD_ON)) */

#if ((ICU_TIM_SIGMEAS_USED == STD_ON) &&           \
     ((ICU_GET_INPUT_STATE_API == STD_ON)||        \
     (ICU_GET_TIME_ELAPSED_API == STD_ON)))
/*******************************************************************************
** Syntax : static void Icu_lGtmEdgeOvrflw(uint8 ChannelNumber,               **
**                                         uint8 ModuleNo)                    **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber - TIM Channel Number                       **
**                   ModuleNo - TIM Module used                               **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
**                                                                            **
** Description :     Function to update variables on information on Edge      **
**                   counter overflow                                         **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lGtmEdgeOvrflw(uint8 ChannelNumber, uint8 ModuleNo,
                                        uint8 ChlType)
{
  #if (ICU_GET_INPUT_STATE_API == STD_ON)
if(ChlType  == ICU_GTM_ASIL_CHANNEL)
{
#if(ICU_ASIL_TIM_SIGMEAS_USED == STD_ON)
  if((Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForInputState[ModuleNo] &     \
           (uint16)(ICU_THREE_UL << (ChannelNumber * ICU_TWO_U))) == (uint16)0U)
  {  
    Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForInputState[ModuleNo] |=       \
                                    (uint16)(1UL <<(ChannelNumber * ICU_TWO_U));
  }
  else  /* More than 1 Edge Overflow has happened */
  {  
    Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForInputState[ModuleNo] |=       \
                             (uint16)(ICU_TWO_UL <<(ChannelNumber * ICU_TWO_U));
  }
  #endif
/* #if ((ICU_GET_INPUT_STATE_API == STD_ON) */

}
else
{
#if(ICU_QM_TIM_SIGMEAS_USED == STD_ON)
  if((Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForInputState[ModuleNo] &     \
           (uint16)(ICU_THREE_UL << (ChannelNumber * ICU_TWO_U))) == (uint16)0U)
  {  
    Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForInputState[ModuleNo] |=        \
                                    (uint16)(1UL <<(ChannelNumber * ICU_TWO_U));
  }
  else  /* More than 1 Edge Overflow has happened */
  {  
    Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForInputState[ModuleNo] |=       \
                             (uint16)(ICU_TWO_UL <<(ChannelNumber * ICU_TWO_U));
  }
  #endif
/* #if ((ICU_GET_INPUT_STATE_API == STD_ON) */

}
#else
UNUSED_PARAMETER(ChlType)
#endif
  
/* (ICU_GET_TIME_ELAPSED_API == STD_ON) */

#if ((ICU_GET_TIME_ELAPSED_API == STD_ON)&& (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON))
if(ChlType  == ICU_GTM_ASIL_CHANNEL)
{ 
  if((Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] &    \
                   (uint16)(ICU_THREE_UL << (ChannelNumber * ICU_TWO_U))) == 0U)
  {  
    Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo]|=    \
                                    (uint16)(1UL <<(ChannelNumber * ICU_TWO_U));
  }
  else  /* More than 1 Edge Overflow has happened */
  {  
    Icu_17_GtmCcu6_AsilGtmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] |=    \
                           (uint16)(ICU_TWO_UL <<(ChannelNumber * ICU_TWO_U));
  }
}
#endif

#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) && (ICU_QM_TIM_SIGMEAS_USED == STD_ON))
if(ChlType  == ICU_GTM_QM_CHANNEL)
{
  if((Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] &     \
                   (uint16)(ICU_THREE_UL << (ChannelNumber * ICU_TWO_U))) == 0U)
  {  
    Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo]|=      \
                                    (uint16)(1UL <<(ChannelNumber * ICU_TWO_U));
  }
  else  /* More than 1 Edge Overflow has happened */
  {  
    Icu_17_GtmCcu6_QmVarlist.GtmEdgeCountForTimeElapsed[ModuleNo] |=      \
                           (uint16)(ICU_TWO_UL <<(ChannelNumber * ICU_TWO_U));
  }
}
#endif
}

#endif
 
/* #if     #if ((ICU_TIM_SIGMEAS_USED == STD_ON) &&           \
         ((ICU_GET_INPUT_STATE_API == STD_ON)||               \
         (ICU_GET_TIME_ELAPSED_API == STD_ON))) */

#endif
/* #if (ICU_GTM_TIM_USED == STD_ON) */



#if (ICU_CCU6_USED == STD_ON)
/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcu6T12Initialization(void)             **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non - reentrant                                          **
**                                                                            **
** Parameters (in):  none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to initialize the CCU6x kernal register         **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcu6T12Initialization(void)
{
  volatile Ifx_CCU6 *Ccu6BaseRegPtr;/* Variable to hold the CCU6 base address */
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  volatile uint32 ReadBack; /* Variable to read back the CLC register */ 
  uint8 KernelCount;        /* Loop count variable to count CCU6 kernals */
  uint8 ChannelCount;       /* Loop count variable to count CC Channels */ 

  /* Loop through all the available CCU6 kernals */
  for(KernelCount = 0U; KernelCount < (uint8)ICU_NO_OF_CCU6_MODULES; 
      KernelCount++)
  {
    Ccu6BaseRegPtr = &MODULE_CCU60;

    /* Enable the Kernals if not done prior by any other module */
    /* Get the base address of the Kernal */
    Ccu6RegPtr = Ccu6BaseRegPtr + KernelCount;

    /* Check if T12 initialization has to be done by ICU */
    if(Icu_kConfigPtr->T12Parameters[KernelCount] != (uint8)ICU_CCU6X_UNUSED)
    {
      /* Check if the module is already enabled */
      if( Ccu6RegPtr->CLC.B.DISS == 1U)
      {
        Mcal_ResetENDINIT(); 
        /* Enable the module */
        Ccu6RegPtr->CLC.B.DISR = 0U;

        /* Is Wakeup is desired, then EDIS is set, else it is reset */
        if((Icu_kConfigPtr->T12Parameters[KernelCount] & ICU_CCU_SLEEP_REQD) \
                                                                          > 0UL)
        {
          Ccu6RegPtr->CLC.B.EDIS = 1U;
        }
        else
        {
          Ccu6RegPtr->CLC.B.EDIS = 0U;
        }
        
        Mcal_SetENDINIT();
        
        /* Read back the CLC register */
        ReadBack = Ccu6RegPtr->CLC.U;
        UNUSED_PARAMETER(ReadBack)
        
      }

      /* Run Bit is reset to stop the timer just in case if it is 
         already started */      
      Ccu6RegPtr->TCTR4.B.T12RR = 1U;
      /* Initialize the counter to 0 */
      Ccu6RegPtr->T12.U = 0UL;
      Ccu6RegPtr->TCTR0.U = \
      (uint32_t)((uint32)(Icu_kConfigPtr->T12Parameters[KernelCount]) & \
                 (uint32)ICU_LOWER_NIBBLE);
      /* Run Bit is set to start the timer */      
      Ccu6RegPtr->TCTR4.B.T12RS = 1U;
      /* T12PR is initialized to the highest value */
      Ccu6RegPtr->T12PR.U = ICU_CCU_T12_MAX_VAL;
      /* Set the Shadow register update request */
      Ccu6RegPtr->TCTR4.B.T12STR = 1U;

      /* Enable Interrupt SR0 */
      MODULE_SRC.CCU6.CCU6[KernelCount].SR0.B.SRE = 1U;
      
    }

    /* Initialize Icu_17_CcuChannelMap array to 0xFF*/ 

    for(ChannelCount = 0U; ChannelCount < (uint8)ICU_NO_OF_CCU6_CHANNELS; \
        ChannelCount++) 
    {     
      Icu_17_CcuChannelMap[KernelCount][ChannelCount] = ICU_CC_NOT_USED;
    }
}
}
#endif

#if (ICU_DE_INIT_API == STD_ON) && (ICU_CCU6_USED == STD_ON)
/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcu6T12DeInit(void)                     **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non - reentrant                                          **
**                                                                            **
** Parameters (in):  none                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to deinitialize the CCU6x kernal register       **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcu6T12DeInit(void)
{
  volatile Ifx_CCU6 *Ccu6BaseRegPtr;/* Variable to hold the CCU6 base address */
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  uint8 KernalCount;        /* Loop count variable to count CCU6 kernals */
  volatile uint32 ReadBack;      /* To read back the CLC register */  
  
  Ccu6BaseRegPtr = &MODULE_CCU60;
  /* Loop through all the available CCU6 kernals */
  for(KernalCount = 0U; KernalCount < (uint8)ICU_NO_OF_CCU6_MODULES; 
      KernalCount++)
  {

    /* Check if T12 initialization has to be done by ICU */
    if(Icu_kConfigPtr->T12Parameters[KernalCount] != (uint8)ICU_CCU6X_UNUSED)
    {
      
      /* Get the base address of the Kernal */
      Ccu6RegPtr = Ccu6BaseRegPtr + KernalCount;
      /* Run Bit is reset to stop the timer */      
      Ccu6RegPtr->TCTR4.B.T12RR = 1U;
      /* Initialize the counter to 0 */
      Ccu6RegPtr->T12.U = 0UL;
      Ccu6RegPtr->TCTR0.U &= (uint32_t)ICU_CCU_TCTR0_RESET_VAL;        
      /* T12PR is initialized to the reset value */
      Ccu6RegPtr->T12PR.U = 0UL;
      /* Set the Shadow register update request */
      Ccu6RegPtr->TCTR4.B.T12STR = 1U;      
      /* Disable Interrupt SR0 */
      MODULE_SRC.CCU6.CCU6[KernalCount].SR0.B.SRE = 0U;


      Mcal_ResetENDINIT(); 
      /* Disable the module */
      Ccu6RegPtr->CLC.B.DISR = 1U;
      /* Clear Wakeup request if configured */
      Ccu6RegPtr->CLC.B.EDIS = 0U;
      Mcal_SetENDINIT();
  
      /* Read back the CLC register */
      ReadBack = Ccu6RegPtr->CLC.U;
  /* ReadBack is required to ensure modification of CLC register but this is 
     not used anywhere */
     UNUSED_PARAMETER(ReadBack)     
    }    
  }
}
#endif
/* #if (ICU_DE_INIT_API == STD_ON) */

#if (ICU_CCU6_USED == STD_ON)
/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcu6ChannelInit(                        **
**                  Icu_17_GtmCcu6_ChannelType Channel,                       **
**                  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr)  **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non - reentrant                                          **
**                                                                            **
** Parameters (in):  Channel - ICU Channel Number                             **
**                   LocalIcuChanPtr - Pointer to the Channel configuration   **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to initialize the CC6x registers                **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcu6ChannelInit(Icu_17_GtmCcu6_ChannelType Channel,
                        const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr)
{

  volatile Ifx_CCU6 *Ccu6BaseRegPtr;/* Variable to hold the CCU6 base address */
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  uint8 CcuKernalNumber;    /* To hold CCU Kernal Number */
  uint8 CcChannelNumber;    /* To hold the CC channel number */
  #if (ICU_CCU6_SIGEDGE_USED == STD_ON)
  Icu_17_GtmCcu6_ActivationType ActiveEdge; /* To hold the activation edge */
  uint8 CcuActiveEdge;     /* Edge value according to CCU */
  #endif
 
  /* Assign the base address to CCU60 base address */
  Ccu6BaseRegPtr = &MODULE_CCU60;

  /* Lower Nibble of AssignedHwUnitNumber holds the Kernal Number */
  CcuKernalNumber = ((uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber\
                                            & ICU_CCU_GET_LOWER_NIBBLE);
  /* Upper Nibble of AssignedHwUnitNumber holds the Channel Number */
  CcChannelNumber =((uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber \
                            & ICU_CCU_GET_UPPER_NIBBLE)>> ICU_BRING_TO_BIT_0;

  /* Get the base address of the Kernal */
  Ccu6RegPtr = Ccu6BaseRegPtr + CcuKernalNumber;

  #if (ICU_CCU6_SIGEDGE_USED == STD_ON)
  /* Check if the channel is assigned to Edge Detection */
  if (LocalIcuChanPtr->IcuProperties.MeasurementMode
                                                 == ICU_MODE_SIGNAL_EDGE_DETECT)
  {

    ActiveEdge = LocalIcuChanPtr->IcuProperties.DefaultStartEdge;

    CcuActiveEdge = Icu_lCcu6GetActiveEdge(ActiveEdge);

    /* Channel is configured to Capture Mode 1 */
    Ccu6RegPtr->T12MSEL.U |= (uint32_t)(ICU_CCU_CAPTURE_MODE1 << \
                             (CcChannelNumber * ICU_CCU_MSEL_BITS_PER_CHANNEL));

    /* Clear any pending interrupt */
    Ccu6RegPtr->ISR.U |= (uint32_t)(ICU_CCU_CLEAR_INTERRUPT << \
                               (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));

    /* Enable interrupt for the channel */
    /* Clear the interrupt bits and then set the relevant bits. 
       Schm not used here because this happens during init */
    Ccu6RegPtr->IEN.U &= (uint32_t)~(ICU_CCU_CLEAR_INTERRUPT << \
                               (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));

    Ccu6RegPtr->IEN.U |= (uint32_t)((uint32)CcuActiveEdge << \
                               (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));

    
  }
  #endif
/* #if (ICU_CCU6_SIGEDGE_USED == STD_ON) */

  /* Initialize Interrupt Node Pointer to SR0 */
  Ccu6RegPtr->INP.U &= (uint32_t)\
         ~(ICU_CCU_INP_SR0 << (CcChannelNumber * ICU_CCU_INP_BITS_PER_CHANNEL));

  /* Prepare the channel map to link the ICU channel number with the CCU channel
     details */
  Icu_17_CcuChannelMap[CcuKernalNumber][CcChannelNumber] = Channel;
}
#endif
/* #if (ICU_CCU6_USED == STD_ON) */

#if (ICU_CCU6_SIGEDGE_USED == STD_ON)
/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcu6SetActivationCondition(             **
**                                   uint8 CellUsed,                          **
**                                   Icu_17_GtmCcu6_ActivationType ActiveEdge)**
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CellUsed - CCU6x Kernal and Channel Info                 **
**                   ActiveEdge - Configured Activation edge for the channel  **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to set the IEN register according to the        **
**                   configured edge                                          **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcu6SetActivationCondition(uint8 CellUsed, 
                                       Icu_17_GtmCcu6_ActivationType ActiveEdge)
{
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  uint8 CcuActiveEdge;      /* To hold the CCU equivalent edge */
  uint8 CcChannelNumber;    /* To hold the CC channel number */
  uint32 IenRegValue;       /* For manipulation of IEN register */

  /* Get the equivalent CCU Edge */
  CcuActiveEdge = Icu_lCcu6GetActiveEdge(ActiveEdge);

  /* Upper Nibble of AssignedHwUnitNumber holds the Channel Number */
  CcChannelNumber = (CellUsed & ICU_CCU_GET_UPPER_NIBBLE)>> ICU_BRING_TO_BIT_0;

  /* Get the base address of the Kernal */
  Ccu6RegPtr = Icu_lCcuGetBaseAddress(CellUsed);
  
  /* Clear any pending interrupt */
  Ccu6RegPtr->ISR.U |= (uint32_t)(ICU_CCU_CLEAR_INTERRUPT << \
                               (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));    

  /* Enable interrupt for the channel */
  /* Clear the interrupt bits and then set the relevant bits. */
  SchM_Enter_Icu_17_GtmCcu6_Ccu6IenUpdate();  
  IenRegValue = Ccu6RegPtr->IEN.U;
  
  IenRegValue &= (uint32)~(ICU_CCU_CLEAR_INTERRUPT << \
                  (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));

  IenRegValue |= ((uint32)CcuActiveEdge << \
                           (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));
  
  Ccu6RegPtr->IEN.U = IenRegValue;

  SchM_Exit_Icu_17_GtmCcu6_Ccu6IenUpdate();  


}

#endif
/* #if (ICU_CCU6_SIGEDGE_USED == STD_ON) */
#if (ICU_CCU6_USED == STD_ON)  
/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcu6PortInit(                           **
**                  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr)  **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  LocalIcuChanPtr - Pointer to channel configuration       **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to configure port connections for CCU6x         **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcu6PortInit(
                       const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr)
{
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  uint8 CcChannelNumber;    /* To hold the CC channel number */
 
  
  /* Upper Nibble of AssignedHwUnitNumber holds the Channel Number */
  CcChannelNumber = ((uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber\
                    & ICU_CCU_GET_UPPER_NIBBLE) >> ICU_BRING_TO_BIT_0;

  /* Get the base address of the Kernal */
  Ccu6RegPtr = Icu_lCcuGetBaseAddress(
                    (uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber);
  
  /* Port connections to CCU */
  Ccu6RegPtr->PISEL0.U |= \
          (uint32_t)((uint32)LocalIcuChanPtr->IcuProperties.Ccu6Connections << \
                           (CcChannelNumber * ICU_CCU_PISEL_BITS_PER_CHANNEL));


}
#endif

#if (((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON)) \
     && (ICU_CCU6_SIGEDGE_USED == STD_ON))
/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcuDisableChannel(uint8 CellUsed)       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CellUsed - CCU6x Kernal and Channel information          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to disable a CC channel by changing the mode of **
**                   the channel                                              **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcuDisableChannel(uint8 CellUsed)
{
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  uint8 CcChannelNumber;    /* To hold the CC channel number */


  /* Upper Nibble of AssignedHwUnitNumber holds the Channel Number */
  CcChannelNumber = (CellUsed & ICU_CCU_GET_UPPER_NIBBLE) >> ICU_BRING_TO_BIT_0;

  /* Get the base address of the Kernal */
  Ccu6RegPtr = Icu_lCcuGetBaseAddress(CellUsed);

  /* Channel is configured to Capture Compare Mode Switched off */
  Ccu6RegPtr->T12MSEL.U &= (uint32_t)~(ICU_CCU_MSEL_RESET_VAL << \
                         (CcChannelNumber * ICU_CCU_MSEL_BITS_PER_CHANNEL));

}

/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcuEnableChannel(uint8 CellUsed)        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CellUsed - CCU6x Kernal and Channel information          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to enable a CC channel by changing the mode of  **
**                   the channel to Mode 1                                    **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcuEnableChannel(uint8 CellUsed)
{
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  uint8 CcChannelNumber;    /* To hold the CC channel number */


  /* Upper Nibble of AssignedHwUnitNumber holds the Channel Number */
  CcChannelNumber = (CellUsed & ICU_CCU_GET_UPPER_NIBBLE) >> ICU_BRING_TO_BIT_0;

  /* Get the base address of the Kernal */
  Ccu6RegPtr = Icu_lCcuGetBaseAddress(CellUsed);

  /* Clear any pending interrupt */
  Ccu6RegPtr->ISR.U &= (uint32_t)~(ICU_CCU_CLEAR_INTERRUPT << \
                             (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));

  /* Channel is configured to Capture Mode 0 */
  Ccu6RegPtr->T12MSEL.U |= (uint32_t)(ICU_CCU_CAPTURE_MODE1 << \
                         (CcChannelNumber * ICU_CCU_MSEL_BITS_PER_CHANNEL));

}

#endif

/* #if (((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON)) \
     && (ICU_CCU6_SIGEDGE_USED == STD_ON)) */


#if ((ICU_SIGNAL_MEASUREMENT_API == STD_ON)&& (ICU_CCU6_SIGMEAS_USED == STD_ON))
/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcuSignalMeasHandler(uint32 IcuOption,  **
**                    Icu_17_GtmCcu6_ChannelType CellUsed,                    **
**                    Icu_17_GtmCcu6_SignalMeasurementPropertyType SigKind,   **
**                    Icu_17_GtmCcu6_ActivationType CfgEdge)                  **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  IcuOption - Module that uses the ICU channel             **
**                   CellUsed - CCU6x Kernal and Channel information          **
**                   SigKind - Signal Measurement property of the channel     **
**                   CfgEdge - Configured Active Edge for the channel         **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to configure and start the channel in the       **
**                   configured signal measurement mode                       **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcuSignalMeasHandler(uint32 IcuOption, 
                           Icu_17_GtmCcu6_ChannelType CellUsed, 
                           Icu_17_GtmCcu6_SignalMeasurementPropertyType SigKind,
                           Icu_17_GtmCcu6_ActivationType CfgEdge)
{

  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  volatile Ifx_CCU6_CC60SR * CcuSrRegPtr; /* Pointer to SR registers of CCU */
  uint8 CcChannelNumber;    /* To hold the CC channel number */
  uint8 CcuKernalNumber;    /* To hold CCU Kernal Number */
  uint8 CcuActiveEdge;      /* CCU relevant Edge */



  /* Lower Nibble of AssignedHwUnitNumber holds the Kernal Number */
  CcuKernalNumber = CellUsed & ICU_CCU_GET_LOWER_NIBBLE;

  /* Upper Nibble of AssignedHwUnitNumber holds the Channel Number */
  CcChannelNumber = (CellUsed & ICU_CCU_GET_UPPER_NIBBLE) >> ICU_BRING_TO_BIT_0;

  /* Get the base address of the Kernal */
  Ccu6RegPtr = Icu_lCcuGetBaseAddress(CellUsed);

  /* Assign SR and R register base addresses */
  CcuSrRegPtr = &(Ccu6RegPtr->CC60SR);

  /* Check if the channel corresponds to a CCU channel */
  if(IcuOption == ICU_CCU6_ASIL_CHANNEL)
  {
    /* Clear Period, Active time, R, SR variables and R and SR registers of 
       the particular channel */
    #if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)
    CcuSrRegPtr[CcChannelNumber].U = 0UL;
    Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal[CcuKernalNumber][CcChannelNumber] = 0U;
    Icu_17_GtmCcu6_AsilCcu6Varlist.CcuSrRegVal[CcuKernalNumber][CcChannelNumber] = 0U; 
    Icu_17_GtmCcu6_AsilCcu6Varlist.CcuActiveTime[CcuKernalNumber][CcChannelNumber] = 0U; 
    Icu_17_GtmCcu6_AsilCcu6Varlist.CcuPeriodTime[CcuKernalNumber][CcChannelNumber] = 0U; 
    #endif
  }
  else
  {
    #if (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)  
    CcuSrRegPtr[CcChannelNumber].U = 0UL;
    Icu_17_GtmCcu6_QmVarlist.CcuRRegVal[CcuKernalNumber][CcChannelNumber] = 0U;
    Icu_17_GtmCcu6_QmVarlist.CcuSrRegVal[CcuKernalNumber][CcChannelNumber] = 0U; 
    Icu_17_GtmCcu6_QmVarlist.CcuActiveTime[CcuKernalNumber][CcChannelNumber] = 0U; 
    Icu_17_GtmCcu6_QmVarlist.CcuPeriodTime[CcuKernalNumber][CcChannelNumber] = 0U; 
    #endif
  }
    
  /* Clear any pending interrupt */
  Ccu6RegPtr->ISR.U |= (uint32_t)(ICU_CCU_CLEAR_INTERRUPT << \
                               (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));
  if(SigKind == ICU_HIGH_TIME)
  {
    CcuActiveEdge = ICU_CCU_FALLING_EDGE;
  }
  else if(SigKind == ICU_LOW_TIME)
  {
    CcuActiveEdge = ICU_CCU_RISING_EDGE;  
  }
  else
  {
      /* Enable interrupt for the channel */
    CcuActiveEdge = Icu_lCcu6GetActiveEdge(CfgEdge);
  }
  Ccu6RegPtr->IEN.U |= (uint32_t)((uint32)CcuActiveEdge << \
                               (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));

  /* Identify the signal measurement property type of the channel */
  if(SigKind == ICU_PERIOD_TIME)
  {
    if(CfgEdge == ICU_RISING_EDGE)
    {
        /* Channel is configured to Capture Mode 2 */
      Ccu6RegPtr->T12MSEL.U |= (uint32_t)(ICU_CCU_CAPTURE_MODE2 << \
                           (CcChannelNumber * ICU_CCU_MSEL_BITS_PER_CHANNEL));
    }
    else
    {
        /* Channel is configured to Capture Mode 3 */
      Ccu6RegPtr->T12MSEL.U |= (uint32_t)(ICU_CCU_CAPTURE_MODE3 << \
                             (CcChannelNumber * ICU_CCU_MSEL_BITS_PER_CHANNEL));
    }      
  }
  else
  {
      /* Channel is configured to Capture Mode 1 */
      Ccu6RegPtr->T12MSEL.U |= (uint32_t)(ICU_CCU_CAPTURE_MODE1 << \
                           (CcChannelNumber * ICU_CCU_MSEL_BITS_PER_CHANNEL));
  }

}

/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcuStopSignalMeas(                      **
**                                  Icu_17_GtmCcu6_ChannelType CellUsed)      **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CellUsed - CCU6x Kernal and Channel information          **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to disable a channel configured in signal       **
**                   measurement mode                                         **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcuStopSignalMeas(Icu_17_GtmCcu6_ChannelType CellUsed)
{
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  uint8 CcChannelNumber;    /* To hold the CC channel number */


  /* Upper Nibble of AssignedHwUnitNumber holds the Channel Number */
  CcChannelNumber = (CellUsed & ICU_CCU_GET_UPPER_NIBBLE) >> ICU_BRING_TO_BIT_0;

  /* Get the base address of the Kernal */
  Ccu6RegPtr = Icu_lCcuGetBaseAddress(CellUsed);

  /* Disable interrupt for the channel */
  Ccu6RegPtr->IEN.U &= (uint32_t)~(ICU_CCU_CLEAR_INTERRUPT << \
                             (CcChannelNumber * ICU_CCU_IS_BITS_PER_CHANNEL));

  /* Channel is configured to Capture Compare Mode Switched off */
  Ccu6RegPtr->T12MSEL.U &= (uint32_t)~(ICU_CCU_MSEL_RESET_VAL << \
                         (CcChannelNumber * ICU_CCU_MSEL_BITS_PER_CHANNEL));

}

#endif

/* #if ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) && \
        (ICU_CCU6_SIGMEAS_USED == STD_ON)) */

#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) && (ICU_CCU6_SIGMEAS_USED == STD_ON))
/*******************************************************************************
** Syntax : static _INLINE_ Icu_17_GtmCcu6_ValueType Icu_lCcuGetTimeElapsed(  **
**                uint8 CellUsed,                                             **
**                Icu_17_GtmCcu6_SignalMeasurementPropertyType SigMode)       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CellUsed - CCU6x Kernal and Channel information          **
**                   SigMode - Signal Measurement property                    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     ElapsedTime - Time Elapsed value                         **
**                                                                            **
** Description :     Function to get the Time Elapsed information of the      **
**                   signal measurement channel                               **
**                                                                            **
*******************************************************************************/
static _INLINE_ Icu_17_GtmCcu6_ValueType Icu_lCcuGetTimeElapsed(uint8 CellUsed, 
                          Icu_17_GtmCcu6_SignalMeasurementPropertyType SigMode,
                          uint8 ChlType)
{

  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  volatile Ifx_CCU6_CC60SR *CcuSrRegPtr; /* Pointer to SR registers of CCU */
  volatile Ifx_CCU6_CC60R *CcuRRegPtr;   /* Pointer to R registers of CCU */  
  Icu_17_GtmCcu6_ValueType ElapsedTime;/* Elapsed Time value */ 
  uint8 CcChannelNumber;    /* To hold the CC channel number */
  uint8 CcuKernalNumber;    /* To hold CCU Kernal Number */

  /* Elapsed time is initialized to 0 */
  ElapsedTime = 0U;

  /* Lower Nibble of AssignedHwUnitNumber holds the Kernal Number */
  CcuKernalNumber = CellUsed & ICU_CCU_GET_LOWER_NIBBLE;

  /* Upper Nibble of AssignedHwUniCcuSrRegValPtrtNumber holds the Channel Number */
  CcChannelNumber = 
                (CellUsed & ICU_CCU_GET_UPPER_NIBBLE) >> ICU_BRING_TO_BIT_0;

  /* Get the base address of the Kernal */
  Ccu6RegPtr = Icu_lCcuGetBaseAddress(CellUsed);

  /* Assign SR and R register base addresses */
  CcuSrRegPtr = &(Ccu6RegPtr->CC60SR);
  CcuRRegPtr = &(Ccu6RegPtr->CC60R);

  /* Act according to the mode chosen */
  switch(SigMode)
  {
    case ICU_PERIOD_TIME:
    {
      SchM_Enter_Icu_17_GtmCcu6_CcuVariableupdate();
      /* Availability of a new value is ascertained by checking CcuRRegVal
         to be 0 */
    if(ChlType == ICU_CCU6_ASIL_CHANNEL)
    {
#if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)
      if(Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal
         [CcuKernalNumber][CcChannelNumber] != 0U)
      {
        /* If Period mode is chosen, then period is given by the difference 
           between SR and R register in Mode 2 or Mode 3 */
        ElapsedTime = Icu_lCcuSubtractWithOverflow(
                                        (uint32)CcuSrRegPtr[CcChannelNumber].U,
                                        (uint32)CcuRRegPtr[CcChannelNumber].U);
        /* CcuRRegVal is cleared to indicate that there is no new value
           present */
        Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal
          [CcuKernalNumber][CcChannelNumber] = 0U;
      }
#endif   
    } 
  else
  {
#if (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)
    if(Icu_17_GtmCcu6_QmVarlist.CcuRRegVal
         [CcuKernalNumber][CcChannelNumber] != 0U)
    {
      /* If Period mode is chosen, then period is given by the difference 
       between SR and R register in Mode 2 or Mode 3 */
      ElapsedTime = Icu_lCcuSubtractWithOverflow(
                       (uint32)CcuSrRegPtr[CcChannelNumber].U,
                       (uint32)CcuRRegPtr[CcChannelNumber].U);
      /* CcuRRegVal is cleared to indicate that there is no new value
       present */
    Icu_17_GtmCcu6_QmVarlist.CcuRRegVal[CcuKernalNumber][CcChannelNumber] = 0U;

    }
#endif
      }
      SchM_Exit_Icu_17_GtmCcu6_CcuVariableupdate();      
    }
      break;

    case ICU_HIGH_TIME:
      {
        SchM_Enter_Icu_17_GtmCcu6_CcuVariableupdate();
        /* Availability of a new value is ascertained by checking CcuRRegVal
           to be 0 */
    if(ChlType == ICU_CCU6_ASIL_CHANNEL)
    {
#if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)           
        if(Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal
           [CcuKernalNumber][CcChannelNumber] != 0U)
        {
          /* If High time is chosen, then it is given by the difference 
             between R and SR register in Mode 1 */
             ElapsedTime = Icu_lCcuSubtractWithOverflow(
                      (uint32)CcuSrRegPtr[CcChannelNumber].U, 
            (uint32)Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal
                         [CcuKernalNumber][CcChannelNumber]);
          /* CcuRRegVal is cleared to indicate that there is no new value
             present */
          Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal
                 [CcuKernalNumber][CcChannelNumber] = 0U;
        }
#endif    
    }
  else
  {
      #if (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)           
    if(Icu_17_GtmCcu6_QmVarlist.CcuRRegVal
         [CcuKernalNumber][CcChannelNumber] != 0U)
    {
      /* If High time is chosen, then it is given by the difference 
       between R and SR register in Mode 1 */
       ElapsedTime = Icu_lCcuSubtractWithOverflow(
                   (uint32)CcuSrRegPtr[CcChannelNumber].U, 
                   (uint32)Icu_17_GtmCcu6_QmVarlist.CcuRRegVal
                          [CcuKernalNumber][CcChannelNumber]);
          /* CcuRRegVal is cleared to indicate that there is no new value
           present */
     Icu_17_GtmCcu6_QmVarlist.CcuRRegVal[CcuKernalNumber][CcChannelNumber] = 0U;
    }
     #endif   
   }

      SchM_Exit_Icu_17_GtmCcu6_CcuVariableupdate();

      }

      break;


    case ICU_LOW_TIME:
    default:
    {
      SchM_Enter_Icu_17_GtmCcu6_CcuVariableupdate();
      /* Availability of a new value is ascertained by checking CcuRRegVal
         to be 0 */
    if(ChlType == ICU_CCU6_ASIL_CHANNEL)
    {
#if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)             
      if(Icu_17_GtmCcu6_AsilCcu6Varlist.CcuSrRegVal
                 [CcuKernalNumber][CcChannelNumber] != 0U)
      {
        /* If Low time is chosen, then it is given by the difference 
           between SR and R in Mode 1 */
        ElapsedTime = Icu_lCcuSubtractWithOverflow(
                                          (uint32)CcuRRegPtr[CcChannelNumber].U,
                     (uint32)Icu_17_GtmCcu6_AsilCcu6Varlist.CcuSrRegVal
                                   [CcuKernalNumber][CcChannelNumber]);

        /* CcuSrRegVal is cleared to indicate that there is no new value
           present */
        Icu_17_GtmCcu6_AsilCcu6Varlist.CcuSrRegVal
                  [CcuKernalNumber][CcChannelNumber] = 0U;
    }
#endif
   }      
    else    
    {
        #if (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)    
    if(Icu_17_GtmCcu6_QmVarlist.CcuSrRegVal
           [CcuKernalNumber][CcChannelNumber] != 0U)
    {
      /* If Low time is chosen, then it is given by the difference 
       between SR and R in Mode 1 */
      ElapsedTime = Icu_lCcuSubtractWithOverflow(
                      (uint32)CcuRRegPtr[CcChannelNumber].U,
             (uint32)Icu_17_GtmCcu6_QmVarlist.CcuSrRegVal
                        [CcuKernalNumber][CcChannelNumber]);
    
      /* CcuSrRegVal is cleared to indicate that there is no new value
       present */
      Icu_17_GtmCcu6_QmVarlist.CcuSrRegVal
             [CcuKernalNumber][CcChannelNumber] = 0U;

    }
         #endif
    }
    SchM_Exit_Icu_17_GtmCcu6_CcuVariableupdate();
  }
  }
  return(ElapsedTime);
}
 #endif 

/* #if ((ICU_GET_TIME_ELAPSED_API == STD_ON) \
   && (ICU_CCU6_SIGMEAS_USED == STD_ON)) */

#if ((ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) \
    && (ICU_CCU6_SIGMEAS_USED == STD_ON))
/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcuGetDutyCycle(uint32 CellUsed,        **
**                               Icu_17_GtmCcu6_DutyCycleType *DutyCyclePtr)  **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  CellUsed - CCU6x Kernal and Channel information          **
**                   DutyCyclePtr - Pointer to location corresponding to the  **
**                   channel                                                  **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to get the Duty Cycle information of the        **
**                   signal measurement channel                               **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcuGetDutyCycle(uint32 CellUsed, 
                                     Icu_17_GtmCcu6_DutyCycleType *DutyCyclePtr, 
                                     uint8 ChlType)
{
  uint8 CcChannelNumber;    /* To hold the CC channel number */
  uint8 CcuKernalNumber;    /* To hold CCU Kernal Number */

  /* Lower Nibble of AssignedHwUnitNumber holds the Kernal Number */
  CcuKernalNumber = (uint8)(CellUsed & ICU_CCU_GET_LOWER_NIBBLE);

  /* Upper Nibble of AssignedHwUnitNumber holds the Channel Number */
  CcChannelNumber = (uint8)((uint32)(CellUsed & ICU_CCU_GET_UPPER_NIBBLE) >> \
                                                            ICU_BRING_TO_BIT_0);

  if(ChlType == ICU_CCU6_ASIL_CHANNEL)  
  {
#if(ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON) 
  DutyCyclePtr->ActiveTime = 
  Icu_17_GtmCcu6_AsilCcu6Varlist.CcuActiveTime[CcuKernalNumber][CcChannelNumber];
  DutyCyclePtr->PeriodTime =
  Icu_17_GtmCcu6_AsilCcu6Varlist.CcuPeriodTime[CcuKernalNumber][CcChannelNumber];

  Icu_17_GtmCcu6_AsilCcu6Varlist.CcuActiveTime[CcuKernalNumber][CcChannelNumber]
      = 0U;
  Icu_17_GtmCcu6_AsilCcu6Varlist.CcuPeriodTime[CcuKernalNumber][CcChannelNumber] 
      = 0U;
  #endif  
 }
 else
  {
 #if(ICU_QM_CCU6_SIGMEAS_USED == STD_ON)

  DutyCyclePtr->ActiveTime =
  Icu_17_GtmCcu6_QmVarlist.CcuActiveTime[CcuKernalNumber][CcChannelNumber];
  DutyCyclePtr->PeriodTime =
  Icu_17_GtmCcu6_QmVarlist.CcuPeriodTime[CcuKernalNumber][CcChannelNumber];

  Icu_17_GtmCcu6_QmVarlist.CcuActiveTime[CcuKernalNumber][CcChannelNumber] = 0U;
  Icu_17_GtmCcu6_QmVarlist.CcuPeriodTime[CcuKernalNumber][CcChannelNumber] = 0U;
#endif  
  }

}
#endif

/* 
#if ((ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) \
    && (ICU_CCU6_SIGMEAS_USED == STD_ON))
*/


#if(ICU_CCU6_SIGMEAS_USED == STD_ON)
/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcuSignalMeasIntHandler(                **
**                              uint8 CcuKernalNumber,                        **
**                              uint8 ChannelCount,                           **
**                              Icu_17_GtmCcu6_ChannelType IcuChannel,        **
**                              uint32 IsValue)                               **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  LocalIcuChanPtr - Pointer to channel configuration       **
**                   CcuKernalNumber - Kernal Number of CCU6x                 **
**                   ChannelCount - Channel Number of CCU6x                   **
**                   IcuChannel - ICU channel Number                          **
**                   IsValue - IS Register value for the channel              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to handling Signal Measurement Channel          **
**                   Interrupts                                               **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcuSignalMeasIntHandler(
                                  uint8 CcuKernalNumber, 
                                  uint8 ChannelCount,
                                  Icu_17_GtmCcu6_ChannelType IcuChannel,
                                  uint32 IsValue,uint8 ChlType)
{
  volatile Ifx_CCU6 *Ccu6BaseRegPtr;/* Variable to hold the CCU6 base address */
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  volatile Ifx_CCU6_CC60SR *CcuSrRegPtr; /* Pointer to SR registers of CCU */
  volatile Ifx_CCU6_CC60R *CcuRRegPtr;   /* Pointer to R registers of CCU */    
  Icu_17_GtmCcu6_SignalMeasurementPropertyType Measure;
  uint32 ChIndex;
  uint32 CfgEdge;
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;  

  /* Assign the base address to CCU60 base address */
  Ccu6BaseRegPtr = &MODULE_CCU60;

  /* Get the base address of the Kernal */
  Ccu6RegPtr = Ccu6BaseRegPtr + CcuKernalNumber;
  /* Extract Channel number for the Index storage */
  LocalIcuMapPtr = (Icu_kConfigPtr->MappingIndexPtr) + IcuChannel;   
  ChIndex = LocalIcuMapPtr->ChannelIndexMap;  
    
if(ChlType == ICU_CCU6_QM_CHANNEL)
{
#if (ICU_MAX_QM_CHANNELS != 0U) 
   
  /* Signal Measurement property is taken  
     bit 0, bit 1 holds the information*/
  #if (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)
  Measure = Icu_17_GtmCcu6_QmVarlist.MeasurementParas[ChIndex].SigProp ;
  CfgEdge = Icu_17_GtmCcu6_QmVarlist.MeasurementParas[ChIndex].CfgEdge;

  /* Assign SR and R register base addresses */
  CcuSrRegPtr = &(Ccu6RegPtr->CC60SR);
  CcuRRegPtr = &(Ccu6RegPtr->CC60R);
  
  switch(Measure)
  {
  case ICU_PERIOD_TIME:
   Icu_lCcuPeriodMeasInt(LocalIcuMapPtr->PhysicalChannelMap, CcuKernalNumber, 
                            ChannelCount, CcuRRegPtr,ChlType);
  break;

  case ICU_ACTIVE_TIME:
  {
   /* If the Active edge is Rising Edge */
   if(CfgEdge == ICU_RISING_EDGE)
   {
    /* Check if a new value is available */
    if(Icu_17_GtmCcu6_QmVarlist.CcuRRegVal[CcuKernalNumber][ChannelCount]!= 0U)
    {
     /* Active time is given by the SR register - CcuRRegVal */
      Icu_17_GtmCcu6_QmVarlist.CcuActiveTime[CcuKernalNumber][ChannelCount] = \
      Icu_lCcuSubtractWithOverflow((uint32)CcuSrRegPtr[ChannelCount].U, 
    (uint32)Icu_17_GtmCcu6_QmVarlist.CcuRRegVal[CcuKernalNumber][ChannelCount]);

      /* Period is given by R register - CcuRRegVal */
      Icu_17_GtmCcu6_QmVarlist.CcuPeriodTime[CcuKernalNumber][ChannelCount] = \
       Icu_lCcuSubtractWithOverflow((uint32)CcuRRegPtr[ChannelCount].U, \
   (uint32)Icu_17_GtmCcu6_QmVarlist.CcuRRegVal[CcuKernalNumber][ChannelCount]);

     /* Set Input state to active */
     Icu_lSetInputStateActive(
     &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[LocalIcuMapPtr->PhysicalChannelMap]);
     }
     /* Update CcuRRegVal with the current value of R Register */
    Icu_17_GtmCcu6_QmVarlist.CcuRRegVal[CcuKernalNumber][ChannelCount] = \
                                  (uint16)CcuRRegPtr[ChannelCount].U;
          
   }
   else
   {

    /* Check if a new value is available */
   if(Icu_17_GtmCcu6_QmVarlist.CcuSrRegVal[CcuKernalNumber][ChannelCount] != 0U)
   {
     /* Active time is given by the R register - CcuSrRegVal */
      Icu_17_GtmCcu6_QmVarlist.CcuActiveTime[CcuKernalNumber][ChannelCount] = \
      Icu_lCcuSubtractWithOverflow((uint32)CcuRRegPtr[ChannelCount].U, \
   (uint32)Icu_17_GtmCcu6_QmVarlist.CcuSrRegVal[CcuKernalNumber][ChannelCount]);
          
    /* Period is given by SR register - CcuSrRegVal */
     Icu_17_GtmCcu6_QmVarlist.CcuPeriodTime[CcuKernalNumber][ChannelCount] = \
    Icu_lCcuSubtractWithOverflow((uint32)CcuSrRegPtr[ChannelCount].U, \
   (uint32)Icu_17_GtmCcu6_QmVarlist.CcuSrRegVal[CcuKernalNumber][ChannelCount]);
          
    /* Set Input state to active */
    Icu_lSetInputStateActive(
    &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[LocalIcuMapPtr->PhysicalChannelMap]);
    
    }
    /* Update CcuSrRegVal with the current value of SR Register */
    Icu_17_GtmCcu6_QmVarlist.CcuSrRegVal[CcuKernalNumber][ChannelCount] = \
                                           (uint16)CcuSrRegPtr[ChannelCount].U;
   }
  }
  break;

  case ICU_HIGH_TIME:
  {
    /* Check if there was a new Signal available. Availability of a 
      Rising edge before Falling edge is checked to ensure that 
      a complete High time is received. This is required for the case
    where Start Signal measurement is called during a High time */
   if((IsValue & (1UL << (ChannelCount * ICU_CCU_IS_BITS_PER_CHANNEL))) > \
                                                              0UL)
   {
    /* Set Input state to active */
     Icu_lSetInputStateActive(
     &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[LocalIcuMapPtr->PhysicalChannelMap]);
     /* backup the value in RVal*/
    Icu_17_GtmCcu6_QmVarlist.CcuRRegVal[CcuKernalNumber][ChannelCount] =  \
                                        (uint16)CcuRRegPtr[ChannelCount].U;
        }
      }
   break;

  default:     /*Default case ICU_LOW_TIME */
      /* Check if there was a new Signal available. Availability of a 
         Falling edge before Rising edge is checked to ensure that 
         a complete Low time is received. This is required for the case
         where Start Signal measurement is called during a Low time */
      if((IsValue & (1UL <<\
                     ((ChannelCount * ICU_CCU_IS_BITS_PER_CHANNEL) + 1U)))\
                                                                    > 0UL)
      {
        /* Set Input state to active */
        Icu_lSetInputStateActive(
         &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[LocalIcuMapPtr->PhysicalChannelMap]);
        /* backup the value in RVal*/
        Icu_17_GtmCcu6_QmVarlist.CcuSrRegVal
         [CcuKernalNumber][ChannelCount] = (uint16)CcuSrRegPtr[ChannelCount].U;
      }
  }
#endif
#endif
}
else
{
#if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)  
  /* Extract Channel number for the Index storage */
#if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)    
  /* Signal Measurement property is taken  
     bit 0, bit 1 holds the information*/
    
  Measure = Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[ChIndex].SigProp;
  CfgEdge = Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[ChIndex].CfgEdge;


  /* Assign SR and R register base addresses */
  CcuSrRegPtr = &(Ccu6RegPtr->CC60SR);
  CcuRRegPtr = &(Ccu6RegPtr->CC60R);
  
  switch(Measure)
  {
    case ICU_PERIOD_TIME:
      Icu_lCcuPeriodMeasInt(LocalIcuMapPtr->PhysicalChannelMap, CcuKernalNumber, 
                            ChannelCount, CcuRRegPtr,ChlType);
      break;

    case ICU_ACTIVE_TIME:
      {
        /* If the Active edge is Rising Edge */
        if(CfgEdge == ICU_RISING_EDGE)
        {
          /* Check if a new value is available */
          if(Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal
                [CcuKernalNumber][ChannelCount] != 0U)
          {
            /* Active time is given by the SR register - CcuRRegVal */
            Icu_17_GtmCcu6_AsilCcu6Varlist.CcuActiveTime
                [CcuKernalNumber][ChannelCount] = \
              Icu_lCcuSubtractWithOverflow((uint32)CcuSrRegPtr[ChannelCount].U, 
                         (uint32)Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal
                                         [CcuKernalNumber][ChannelCount]);

            /* Period is given by R register - CcuRRegVal */
            Icu_17_GtmCcu6_AsilCcu6Varlist.CcuPeriodTime
              [CcuKernalNumber][ChannelCount] = \
            Icu_lCcuSubtractWithOverflow((uint32)CcuRRegPtr[ChannelCount].U, \
                         (uint32)Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal
                                           [CcuKernalNumber][ChannelCount]);

            /* Set Input state to active */
            Icu_lSetInputStateActive(
             &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[LocalIcuMapPtr->PhysicalChannelMap]);
          }
          /* Update CcuRRegVal with the current value of R Register */
          Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal
            [CcuKernalNumber][ChannelCount] = (uint16)CcuRRegPtr[ChannelCount].U;
          
        }
        else
        {

          /* Check if a new value is available */
          if(Icu_17_GtmCcu6_AsilCcu6Varlist.CcuSrRegVal
                 [CcuKernalNumber][ChannelCount] != 0U)
          {
            /* Active time is given by the R register - CcuSrRegVal */
            Icu_17_GtmCcu6_AsilCcu6Varlist.CcuActiveTime
            [CcuKernalNumber][ChannelCount] = \
            Icu_lCcuSubtractWithOverflow((uint32)CcuRRegPtr[ChannelCount].U, \
                        (uint32)Icu_17_GtmCcu6_AsilCcu6Varlist.CcuSrRegVal
                         [CcuKernalNumber][ChannelCount]);
          
            /* Period is given by SR register - CcuSrRegVal */
            Icu_17_GtmCcu6_AsilCcu6Varlist.CcuPeriodTime
            [CcuKernalNumber][ChannelCount] = \
            Icu_lCcuSubtractWithOverflow((uint32)CcuSrRegPtr[ChannelCount].U, \
                        (uint32)Icu_17_GtmCcu6_AsilCcu6Varlist.CcuSrRegVal
                          [CcuKernalNumber][ChannelCount]);
          
            /* Set Input state to active */
            Icu_lSetInputStateActive(
            &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[ LocalIcuMapPtr->PhysicalChannelMap]);
          }
          /* Update CcuSrRegVal with the current value of SR Register */
          Icu_17_GtmCcu6_AsilCcu6Varlist.CcuSrRegVal
          [CcuKernalNumber][ChannelCount] =(uint16)CcuSrRegPtr[ChannelCount].U;

        }
        
      }
      break;


    case ICU_HIGH_TIME:
      {
        /* Check if there was a new Signal available. Availability of a 
           Rising edge before Falling edge is checked to ensure that 
           a complete High time is received. This is required for the case
           where Start Signal measurement is called during a High time */
       if((IsValue & (1UL << (ChannelCount * ICU_CCU_IS_BITS_PER_CHANNEL))) > \
                                                                           0UL)
        {
          /* Set Input state to active */
          Icu_lSetInputStateActive(
          &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[LocalIcuMapPtr->PhysicalChannelMap]);
          /* backup the value in RVal*/
          Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal
          [CcuKernalNumber][ChannelCount] = (uint16)CcuRRegPtr[ChannelCount].U;
        }
      }

      break;

    default:     /*Default case ICU_LOW_TIME */
      /* Check if there was a new Signal available. Availability of a 
         Falling edge before Rising edge is checked to ensure that 
         a complete Low time is received. This is required for the case
         where Start Signal measurement is called during a Low time */
      if((IsValue & (1UL <<\
                         ((ChannelCount * ICU_CCU_IS_BITS_PER_CHANNEL) + 1U)))\
                                                                       > 0UL)
      {
        /* Set Input state to active */
        Icu_lSetInputStateActive(
        &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[LocalIcuMapPtr->PhysicalChannelMap]);
        /* backup the value in RVal*/
        Icu_17_GtmCcu6_AsilCcu6Varlist.CcuSrRegVal
        [CcuKernalNumber][ChannelCount] = (uint16)CcuSrRegPtr[ChannelCount].U;                                            
      }
  }
  #endif
  #endif  
} 
}


/*******************************************************************************
** Syntax : static _INLINE_ void Icu_lCcuPeriodMeasInt(                       **
**                                      Icu_17_GtmCcu6_ChannelType IcuChannel,**
**                                        uint8 CcuKernalNumber,              **
**                                        uint8 ChannelCount,                 **
**                                  volatile Ifx_CCU6_CC60R const *CcuRRegPtr)**
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  IcuChannel - ICU channel Number                          **
**                   CcuKernalNumber - Kernal Number of CCU6x                 **
**                   ChannelCount - Channel Number of CCU6x                   **
**                   IcuChannel - ICU channel Number                          **
**                   CcuRRegPtr - Pointer to R register of the corresponding  **
**                   CC register                                              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     Function to handling Signal Measurement Channel          **
**                   Interrupts configured for Period measurement             **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Icu_lCcuPeriodMeasInt(
                                          Icu_17_GtmCcu6_ChannelType IcuChannel,
                                          uint8 CcuKernalNumber, 
                                          uint8 ChannelCount,
                                      volatile Ifx_CCU6_CC60R const *CcuRRegPtr,
                                      uint8 ChlType)
{

  /* Check if a new value is available */
  if(CcuRRegPtr[ChannelCount].U != 0UL)
  {
    /* Set Input state to active */
if(ChlType == ICU_CCU6_ASIL_CHANNEL)
{
#if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)
    Icu_lSetInputStateActive(
    &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[IcuChannel]);
    /* backup the value in RVal*/
    Icu_17_GtmCcu6_AsilCcu6Varlist.CcuRRegVal[CcuKernalNumber][ChannelCount] = \
                                         (uint16)CcuRRegPtr[ChannelCount].U;
#endif
}
  else
    {
#if (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)
    Icu_lSetInputStateActive(
    &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[IcuChannel]);
    /* backup the value in RVal*/
    Icu_17_GtmCcu6_QmVarlist.CcuRRegVal[CcuKernalNumber][ChannelCount] =  \
                                         (uint16)CcuRRegPtr[ChannelCount].U;
#endif
}   
    }
}

/*******************************************************************************
** Syntax : static Icu_17_GtmCcu6_ValueType Icu_lCcuSubtractWithOverflow(
**                                     Icu_17_GtmCcu6_ValueType SecondVal,    **
**                                     Icu_17_GtmCcu6_ValueType FirstVal)     **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  SecondVal - Second value in Subtraction                  **
**                   FirstVal - First value in Subtraction                    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     RetVal - Subtracted value                                **
**                                                                            **
** Description :     Function to perform subtraction of the form              **
**                   SecondVal - FirstVal considering the T12 Timer overflow  **
**                                                                            **
*******************************************************************************/
static Icu_17_GtmCcu6_ValueType Icu_lCcuSubtractWithOverflow(
                                           Icu_17_GtmCcu6_ValueType SecondVal, 
                                           Icu_17_GtmCcu6_ValueType FirstVal)
{
  Icu_17_GtmCcu6_ValueType RetVal;

  /* Check if the overflow has happened */
  if(FirstVal < SecondVal)
  {
    /* If both the values are within the same cycle of T12 before overflow, 
       perform a direct subtraction */
    RetVal = SecondVal - FirstVal;
  }
  else
  {
    /* If both the values are in consecutive cycles of T12 after overflow, 
       overflow is considered during subtraction */
    RetVal = (ICU_CCU6_MAX_T12_TIMER_VAL - (FirstVal - SecondVal)) + 1UL;
  }
  return(RetVal);

}




#endif



#define ICU_17_GTMCCU6_STOP_SEC_CODE
#include "MemMap.h"

#define ICU_17_GTMCCU6_START_SEC_CALLOUT_CODE
#include "MemMap.h"

#if (ICU_GTM_TIM_USED == STD_ON)
/*******************************************************************************
** Traceability:     [cover parentID=DS_AS_ICU318,DS_AS_ICU134_1_ICU020,
   DS_AS_ICU319,DS_AS_ICU317,DS_AS_ICU064,DS_AS_ICU065,DS_AS_ICU134_2,
   DS_AS_ICU119_1_ICU021,DS_AS_ICU119_2_ICU215,DS_AS_ICU216_ICU320,
   DS_AS_ICU217]
** Syntax : void Icu_17_GtmCcu6_Isr(uint8 ModuleType, uint8 ModuleNo,         **
**                          uint8 ChannelNo, uint8 IrqSrc)                    **
**                                                                            **
** [/cover]                                                                   **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non - reentrant                                               **
**                                                                            **
** Parameters (in): ModuleType - Identify TIM Module                          **
**                  ModuleNo - TIM Module Number                              **
**                  ChannelNo - TIM Channel number                            **
**                  IrqSrc - Interrup Source CCU0/CCU1                        **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Interrupt Service Routine for ICU                            **
**                                                                            **
*******************************************************************************/
/* [cover parentID=DS_MCAL_SWSC_ICU_0009] */ 
void Icu_17_GtmCcu6_Isr (uint8 Channel)
{
  /* Local pointers */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  uint32 ChIndex;
  #if (ICU_TIM_TIMSTMP_USED == STD_ON)
  Icu_17_GtmCcu6_ChannelType CellNum;
  uint16 Counter;
  uint16 NotifyCounter;
  uint16 Notify;
  #endif
 #if (ICU_TIM_SIGMEAS_USED == STD_ON)
 #if ((ICU_GET_INPUT_STATE_API == STD_ON)|| \
     (ICU_GET_TIME_ELAPSED_API == STD_ON))  
  Gtm_GlobalChannelNumberType TimChannelNumber;
#endif  
#endif  
 
#if (ICU_EDGE_NOTIF_USED == STD_ON)  
  uint8 PhyChannelIndex;
#endif  
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;  
 #if (ICU_TIM_TIMSTMP_USED == STD_ON) || (ICU_TIM_SIGMEAS_USED == STD_ON) 
  uint8 ChlType;
#endif
  Icu_17_GtmCcu6_ChannelType MaxChannels; 
 
  /* Get the maximum number of channels */
  MaxChannels = ICU_GETMAXSIGEDGEQMCHANNELS +
                ICU_GETMAXEDGECNTQMCHANNELS +
                ICU_GETMAXTIMSTMPQMCHANNELS +
                ICU_GETMAXSIGMEASQMCHANNELS;
                
  #if (ICU_SAFETY_ENABLE == STD_ON)   
  MaxChannels += ICU_GETMAXSIGEDGEASILCHANNELS +
                ICU_GETMAXEDGECNTASILGTMCHANNELS +
                ICU_GETMAXTIMSTMPASILGTMCHANNELS +
                ICU_GETMAXSIGMEASASILCHANNELS;
  #endif 
  
  /* Proceed with the processing only if a valid channel is found */
  if(Channel < MaxChannels)
  {
    /* Initialize ICU configured channel ROM pointer */
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;
    LocalIcuMapPtr =  (Icu_kConfigPtr->MappingIndexPtr) + Channel; 
    
   #if (ICU_TIM_SIGMEAS_USED == STD_ON)
    #if ((ICU_GET_INPUT_STATE_API == STD_ON)|| \
     (ICU_GET_TIME_ELAPSED_API == STD_ON))  
    TimChannelNumber =  (Gtm_GlobalChannelNumberType)
       LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
   #endif  
   #endif  
    
#if (ICU_EDGE_NOTIF_USED == STD_ON)    
    PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap;
#endif    
    ChIndex = LocalIcuMapPtr->ChannelIndexMap;    
 #if (ICU_TIM_TIMSTMP_USED == STD_ON) || (ICU_TIM_SIGMEAS_USED == STD_ON)                   
    ChlType = Icu_lGetChannelType(Channel);   
#endif    
    
    switch (LocalIcuChanPtr->IcuProperties.MeasurementMode) 
    {
      #if (ICU_TIM_SIGEDGE_USED == STD_ON)
      #if (ICU_EDGE_NOTIF_USED == STD_ON)
      case ICU_MODE_SIGNAL_EDGE_DETECT:
        /* Since the Interrupt Notify information is used by other API's too,
           this information has to be backed up as it is modified */ 
      Icu_17_lGlbIndexStatusSet(Channel,1U,(uint8)ICU_CHNL_NOTIF_STATUS_POS,1U);
      if(LocalIcuChanPtr->IcuProperties.SignalType == ICU_ASIL_SIGNAL)
      {
       #if (ICU_MAX_ASIL_GTM_CHANNELS != 0U) 
        Icu_lSignalEdgeNotification_Isr((uint32)Channel,
            LocalIcuChanPtr,
            &Icu_17_GtmCcu6_AsilGtmVarlist.GlbIndexStatus[PhyChannelIndex]);
      #endif
      }
      else
      {  
        #if (ICU_MAX_QM_CHANNELS != 0U)   
        Icu_lSignalEdgeNotification_Isr((uint32)Channel,
            LocalIcuChanPtr,
            &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex]);
       #endif
      }   
      break;
      #endif
/* End of #if ICU_EDGE_NOTIF_USED */
      #endif
/* End of #if ICU_TIM_SIGEDGE_USED */

      #if (ICU_TIM_TIMSTMP_USED == STD_ON)
  
      case ICU_MODE_TIMESTAMP:
      {
        #if(ICU_SAFETY_ENABLE == STD_ON)
        if(ChlType == ICU_GTM_ASIL_CHANNEL)
        {
        #if (ICU_MAX_TIMESTAMP_ASIL_CHANNELS != 0U) 
        Icu_17_GtmCcu6_TimestampBufferType MeasureKind;
        MeasureKind = 
        LocalIcuChanPtr->IcuProperties.MeasurementProperty;
        if (ICU_ACTIVITY_STARTED == \
                   (uint8)Icu_17_lGlbIndexStatusExtract(Channel,
                   ICU_CHNL_ACTIVITY_STARTED_POS,ICU_CHNL_ACTIVITY_BIT_LENGTH))
        {
          CellNum =(uint8)(LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber);
  
          *(Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].Address) 
            = (uint32)Icu_lGtmGetTimeStamp(CellNum);
          Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].Address++;
          Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].Counter++;
      
          /* if notification is enabled */
          /* The Notify Counter should be updated regularly
             whether the notification is enabled or not
             For a runtime enable notification, this logic will
             help a lot.
          */ 

          Counter = Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].Counter;
          NotifyCounter = 
          Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].NotifyCounter;
          if (Counter == NotifyCounter) 
          {
            Notify = Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].Notify;
            /* The notification should occur when counter 
               reaches the next interval value */
            Icu_17_GtmCcu6_AsilGtmVarlist.TimeStampParas[ChIndex].NotifyCounter 
             += Notify;
            if ( ICU_ENABLE_NOTIFICATION == 
            Mcal_Extract(Icu_17_GtmCcu6_AsilGtmVarlist.GlbIndexStatus[LocalIcuMapPtr->PhysicalChannelMap],
                         ICU_CHNL_NOTIF_PRESENCE_POS,ICU_CHNL_NOTIF_BIT_LENGTH)
                 )
            {
              /* Call of Notification function if the 
                 Notify interval is counted */
              /*ICU068 Call of notification function for timestamp */
              /*ICU069 Notification has no parameter and no return value */
              (LocalIcuChanPtr->NotificationPointer)();
            }
          }
        Icu_lTimeStampBufferLimitCheck(MeasureKind, CellNum, ChIndex, ChlType);    
        }
        #endif
        }
        else
        #endif
        {
        #if (ICU_MAX_TIMESTAMP_QM_CHANNELS != 0U) 
        Icu_17_GtmCcu6_TimestampBufferType MeasureKind;
        MeasureKind = 
        LocalIcuChanPtr->IcuProperties.MeasurementProperty;
        if (ICU_ACTIVITY_STARTED == \
                   (uint8)Icu_17_lGlbIndexStatusExtract(Channel,
                   ICU_CHNL_ACTIVITY_STARTED_POS,ICU_CHNL_ACTIVITY_BIT_LENGTH))
        {
          CellNum =(uint8)(LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber);
  
          *(Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].Address) 
            = (uint32)Icu_lGtmGetTimeStamp(CellNum);
          Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].Address++;
          Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].Counter++;
      
          /* if notification is enabled */
          /* The Notify Counter should be updated regularly
             whether the notification is enabled or not
             For a runtime enable notification, this logic will
             help a lot.
          */ 

          Counter = Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].Counter;
          NotifyCounter = 
          Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].NotifyCounter;
          if (Counter == NotifyCounter) 
          {
            Notify = Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].Notify;
            /* The notification should occur when counter 
               reaches the next interval value */
            Icu_17_GtmCcu6_QmVarlist.TimeStampParas[ChIndex].NotifyCounter +=
            Notify;
            if ( ICU_ENABLE_NOTIFICATION == 
            Mcal_Extract(Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[LocalIcuMapPtr->PhysicalChannelMap],
                         ICU_CHNL_NOTIF_PRESENCE_POS,ICU_CHNL_NOTIF_BIT_LENGTH)
                 )
            {
              /* Call of Notification function if the 
                 Notify interval is counted */
              /*ICU068 Call of notification function for timestamp */
              /*ICU069 Notification has no parameter and no return value */
              (LocalIcuChanPtr->NotificationPointer)();
            }
          }
          Icu_lTimeStampBufferLimitCheck(MeasureKind, CellNum, ChIndex, ChlType);    
        }
        #endif
       }
      } /* End of case statement */
      break;  
      #endif
/* End of #if (ICU_TIM_TIMSTMP_USED == STD_ON) */
      default: /* Default case is ICU_MODE_SIGNAL_MEASUREMENT */
      {
      #if (ICU_TIM_SIGMEAS_USED == STD_ON)
      #if ((ICU_GET_INPUT_STATE_API == STD_ON)|| \
           (ICU_GET_TIME_ELAPSED_API == STD_ON))

        Icu_lGtmEdgeOvrflw((TimChannelNumber % GTM_CHANNELS_PER_TIM_MODULE), 
                       (TimChannelNumber/GTM_CHANNELS_PER_TIM_MODULE),ChlType);

      #endif
      /* #if ((ICU_GET_INPUT_STATE_API == STD_ON)|| \
           (ICU_GET_TIME_ELAPSED_API == STD_ON)) */
      #endif
 /* #if ((ICU_TIM_SIGMEAS_USED == STD_ON) */
      UNUSED_PARAMETER(ChIndex)
      }
      break;
    }
  }
  else
  {
    #if (ICU_SAFETY_ENABLE == STD_ON)
    /* Report Safety Error */
    SafeMcal_ReportError( (uint16)ICU_17_GTMCCU6_MODULE_ID,
        ICU_17_GTMCCU6_INSTANCE_ID,ICU_SID_ISR, ICU_E_PARAM_CHANNEL);
    #endif    
  }    
}/* end of function Icu_17_GtmCcu6_Isr */
#endif
/* #if (ICU_GTM_TIM_USED == STD_ON) */
/* [/cover]  */

#define ICU_17_GTMCCU6_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"


#define ICU_17_GTMCCU6_START_SEC_CODE
#include "MemMap.h"

/* [cover parentID=DS_MCAL_SWSC_ICU_0008] */ 
#if (ICU_GETMODE_API == STD_ON) 
/******************************************************************************
**                                                                           **
** Syntax : void Icu_17_GtmCcu6_GetMode(void)                                **
**                                                                           **
** [/cover]                                                                  **
** Service ID:                                                               **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:                                                               **
**                                                                           **
** Parameters (in):  Mode : ICU_MODE_NORMAL or ICU_MODE_SLEEP                **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service to get the ICU mode                                 **
**               This service will return the operation mode                 **
**                                                                           **
*****************************************************************************/  
Icu_17_GtmCcu6_ModeType Icu_17_GtmCcu6_GetMode(void)
{
   return Icu_17_GtmCcu6_GlobMode; 
}
#endif 
/* [/cover]  */

/******************************************************************************
**                                                                           **
** Syntax : void Icu_17_lGlbIndexStatusSet(void)                             **
**                                                                           **
** [/cover]                                                                  **
** Service ID:                                                               **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:                                                               **
**                                                                           **
** Parameters (in):  Mode : ICU_MODE_NORMAL or ICU_MODE_SLEEP                **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service to get the ICU mode                                 **
**               This service will return the operation mode                 **
**                                                                           **
*****************************************************************************/
static _INLINE_ void Icu_17_lGlbIndexStatusSet(
  Icu_17_GtmCcu6_ChannelType Channel,uint8 Value, uint8 Offset, uint8 Bits)
{
  #if (ICU_SAFETY_ENABLE== STD_ON)
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; 
  uint32 Hwused;
  #endif   
  uint8 PhyChannelIndex;
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;
  LocalIcuMapPtr =   (Icu_kConfigPtr->MappingIndexPtr) + Channel;
  PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap;

  #if (ICU_SAFETY_ENABLE== STD_ON)   
  /* Get the channel config pointer */
  LocalIcuChanPtr = Icu_kConfigPtr->ChannelConfigPtr + Channel; 
  Hwused = (uint32)LocalIcuChanPtr->IcuProperties.AssignedHwUnit;
  if((LocalIcuChanPtr->IcuProperties.SignalType == ICU_ASIL_SIGNAL) && 
     (Hwused == ICU_GTM_OPTION)) 
  {  
    #if (ICU_MAX_ASIL_GTM_CHANNELS != 0U) 
    if(Bits == 1U)
    {
       Mcal_SetAtomic((sint32*)(void*)
            &Icu_17_GtmCcu6_AsilGtmVarlist.GlbIndexStatus[PhyChannelIndex],
            (uint32)Value,(sint32)Offset,1);
    }
    else 
    {
      Mcal_SetAtomic((sint32*)(void*)
           &Icu_17_GtmCcu6_AsilGtmVarlist.GlbIndexStatus[PhyChannelIndex],
           (uint32)Value,(sint32)Offset,2);  
    }  
    #endif 
  }
  else if((LocalIcuChanPtr->IcuProperties.SignalType == ICU_ASIL_SIGNAL) &&
          (Hwused == ICU_CCU_OPTION)) 
  {  
     #if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U) 
     if(Bits == 1U)
     {
      Mcal_SetAtomic((sint32*)(void*)
           &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[PhyChannelIndex],
           (uint32)Value,(sint32)Offset,1);  
     }
     else
     {
      Mcal_SetAtomic((sint32*)(void*)
           &Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[PhyChannelIndex],
           (uint32)Value,(sint32)Offset,2);  
     } 
     #endif
  }
  else 
  #endif
  { 
     #if (ICU_MAX_QM_CHANNELS != 0U)
     if(Bits == 1U)
     {       
       Mcal_SetAtomic((sint32*)(void*)
            &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex],
            (uint32)Value,(sint32)Offset,1);
     }
     else
     {
       Mcal_SetAtomic((sint32*)(void*)
            &Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex],
            (uint32)Value,(sint32)Offset,2);  
     } 
     #endif 
  }
}



#if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
#if (ICU_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Syntax :void Icu_lSafeCheckMode(const Icu_17_GtmCcu6_ChannelConfigType*    **
**                                                      const IcuChannelPtr)  **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Non Reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description : This function is used to ensure Safe SetMode by ensuring that**
**               for any running TIM channel configured for WakeUp with       **
**               Icu_EnableWakeup the IRQ bits for the channel are enabled    **
**               before going to SLEEP                                        **
*******************************************************************************/
static void Icu_lSafeCheckMode(const Icu_17_GtmCcu6_ChannelConfigType* 
                               const IcuChannelPtr)
{
  uint8 HwUnit;
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId;
  Ifx_GTM_TIM_CH_TYPE *TimChannelRegPtr;   /* Pointer to TIM Channel Reg    */
  uint32 InterruptFlag = 0U;  
  uint8 ModuleNumber;                        /* Holds the module number */
  
  HwUnit = (uint8)IcuChannelPtr->IcuProperties.AssignedHwUnitNumber;  
  GlobalChannelId = Icu_lGtmChannelIdentifier(HwUnit);
  ModuleNumber  = Icu_lGetGtmModuleNo(GlobalChannelId);

  /* Get the pointer to TIM Channel Register Structure */
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
                        CH_TIM[ModuleNumber].CH[GlobalChannelId.ChannelNo]);

  InterruptFlag = (uint32)(TimChannelRegPtr->CH_IRQ_EN.U & 1U);  
  if( InterruptFlag != 1U)
  {
       /* Report Safety Error */
      SafeMcal_ReportError( (uint16)ICU_17_GTMCCU6_MODULE_ID ,  
                             ICU_17_GTMCCU6_INSTANCE_ID,
                             ICU_SID_SETMODE, ICU_E_NO_WAKEUP);
  }    
}
#endif  /*(GPT_SAFETY_ENABLE == STD_ON)*/
#endif   /*(GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)*/

#define ICU_17_GTMCCU6_STOP_SEC_CODE
#include "MemMap.h"

/***************** End of ICU driver module*********************************/

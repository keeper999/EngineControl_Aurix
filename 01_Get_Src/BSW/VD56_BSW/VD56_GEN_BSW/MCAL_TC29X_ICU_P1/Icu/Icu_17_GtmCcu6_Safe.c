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
**  $FILENAME   : Icu_17_GtmCcu6_Safe.c $                                    **
**                                                                           **
**  $CC VERSION : \main\33 $                                                 **
**                                                                           **
**  $DATE       : 2014-01-28 $                                               **
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
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
/* Inclusion structure */
#include "Icu_17_GtmCcu6_Safe.h"
#include "IfxSrc_reg.h"

#if (ICU_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define ICU_17_GTMCCU6_START_SEC_VAR_32BIT
#include "MemMap.h"

#if (ICU_INITCHECK_API == STD_ON)
static uint32 TempStorageVal;
#endif

#define ICU_17_GTMCCU6_STOP_SEC_VAR_32BIT
#include "MemMap.h"

  
#define ICU_17_GTMCCU6_START_SEC_CODE
#include "MemMap.h"

#if (ICU_INITCHECK_API == STD_ON)
static _INLINE_ uint8 Icu_lChannelInitCheck(void);
#endif

#if (ICU_INITCHECK_API == STD_ON)
#if ((ICU_TIM_SIGMEAS_USED == STD_ON) || (ICU_CCU6_SIGMEAS_USED == STD_ON))
static _INLINE_ uint32 Icu_lSigMesInitCheck
(
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr,
  Icu_17_GtmCcu6_ChannelType Channel,
  uint32 DutyIndex
);
#endif
#endif

#if ((ICU_GTM_TIM_USED == STD_ON) && (ICU_INITCHECK_API == STD_ON))
static Std_ReturnType Icu_lGtmChannelInitCheck(void);
#endif

#if ((ICU_CCU6_USED == STD_ON) && (ICU_INITCHECK_API == STD_ON))
static _INLINE_ uint32 Icu_lCcu6ChannelInitCheck( 
                       Icu_17_GtmCcu6_ChannelType Channel,
                       const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr);
#endif


#if (ICU_INITCHECK_API == STD_ON)
#if (ICU_CCU6_USED == STD_ON)
static _INLINE_ uint32 Icu_lCcu6PortInitCheck(
                     const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr);  
#endif  
#endif

#if (ICU_INITCHECK_API == STD_ON)
#if (ICU_CCU6_USED == STD_ON)
static Std_ReturnType Icu_lCcu6T12InitializationCheck(void);
#endif
#endif

/* [cover parentID=DS_MCAL_SWSC_ICU_0006] */
#if (ICU_SAFETY_ENABLE == STD_ON)
#if (ICU_INITCHECK_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=]                                           **
**                                                                            **
** Syntax : void Icu_17_GtmCcu6_InitCheck(                                    **
**                const Icu_17_GtmCcu6_ConfigType *ConfigPtr )               **               
**                                                                            **
** Service ID      :    None                                                  **
**                                                                            **
** Sync/Async      :    Synchronous                                           **
**                                                                            **
** Reentrancy      :    Non Reentrant                                         **
**                                                                            **
** Parameters (in) :    ConfigPtr - Pointer to ICU Driver configuration set   **
**                                                                            **
** Parameters (out):    None                                                  **
**                                                                            **
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description     : This routine verifies the initialization the ICU driver. **
**                                                                            **
*******************************************************************************/
Std_ReturnType Icu_17_GtmCcu6_InitCheck 
     (const Icu_17_GtmCcu6_ConfigType* ConfigPtr)
{
  Std_ReturnType ErrorFlag;

  ErrorFlag = E_NOT_OK; 
  
 if ((ConfigPtr != NULL_PTR) && 
     (ConfigPtr->Marker == ((uint32)ICU_17_GTMCCU6_MODULE_ID << 16U)))
 {
   volatile uint32 CompareFlag;
   
   CompareFlag = 0xFFFFFFFFU; 
   
   /* To avoid multiple if conditions, storing in CompareFlag */
   /* Comparison to be done for initialization done by Icu_17_GtmCcu6_Init() */  
   if (Icu_kConfigPtr == ConfigPtr) 
  {   
    #if ((ICU_GTM_TIM_USED == STD_ON)) 
    /* Initialize all the channels configured for GTM */
	    ErrorFlag = Icu_lGtmChannelInitCheck();    
    if (ErrorFlag == E_OK) 
    #endif
    {
      #if (ICU_CCU6_USED == STD_ON)    
      /* T12 Kernal initialization */
	        ErrorFlag = Icu_lCcu6T12InitializationCheck();
      #endif      
    }
    #if (ICU_ERU_USED == STD_ON)    
    if (ErrorFlag == E_OK) 
    {    
      if(MODULE_SRC.SCU.SCU.ERU[0].B.SRE != 1U)
      {
        /* Verify for the ERU SRE bit */
        ErrorFlag = E_NOT_OK;
      }
      else
      {
        /* dummy else condition */
      }
    } 
    #endif    
    
    if (ErrorFlag == E_OK) 
    {    
      /* Verify for the configured channels */
	        ErrorFlag = (Std_ReturnType)Icu_lChannelInitCheck();
    }

    /* ICU060: After initialization the mode will be ICU_MODE_NORMAL */
    /* Make Icu Mode to Normal */
    CompareFlag &=  ((uint32)Icu_17_GtmCcu6_GlobMode^ \
                           ~(uint32)ICU_MODE_NORMAL);    
               
    CompareFlag &=  ((uint32)Icu_17_GtmCcu6_InitStatus^ \
                           ~(uint32)ICU_INITIALIZED);      
    
   if ( (CompareFlag != 0xFFFFFFFFU) && (ErrorFlag == E_OK) )    
    {
     ErrorFlag = E_NOT_OK;
    }     
  }
 }
 return(ErrorFlag);
}/* end of Icu_17_GtmCcu6_InitCheck */
#endif
/* [/cover]  */ 

#if (ICU_INITCHECK_API == STD_ON)
/******************************************************************************
** Syntax :           static _INLINE_ void Icu_lChannelInitCheck()           **
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
static _INLINE_ uint8 Icu_lChannelInitCheck(void)
{
  /* Local pointers */
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr; /* ROM pointer */
  /* Local variables */
  uint32 IcuOption;
  const Icu_17_GtmCcu6_MapType *LocalIcuMapPtr;
  #if (ICU_ERU_USED == STD_ON)
  volatile Icu_17_GtmCcu6_ChannelType EruEicrUsed;
  volatile Icu_17_GtmCcu6_ChannelType EruEicrChannel;
  #endif
  Icu_17_GtmCcu6_ChannelType Channel;
  uint8 PhyChannelIndex;
  uint8 ChIndex = 0U;   
  uint8 ErrorFlag;
  #if ((ICU_ERU_USED == STD_ON) ||                                         \
       ((ICU_TIM_SIGEDGE_USED == STD_ON) &&(ICU_EDGE_DETECT_API == STD_ON))) 
  Icu_17_GtmCcu6_ChannelType CellUsed;
  #endif
  uint32 TempStoreReturnVal = 0U;  
  Icu_17_GtmCcu6_ChannelType MaxChannels;    
  volatile uint32 CompareFlag = 0xFFFFFFFFU;
  /* ErrorFlag = E_OK;  */
  /* Get the channel config pointer */
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
  
  for (Channel = (Icu_17_GtmCcu6_ChannelType)0U; 
                                         Channel < MaxChannels; Channel++)
  {
    TempStorageVal = 0U;
    TempStoreReturnVal = 0U;
    /* Get the channel config pointer */
    /* LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel; */
    IcuOption = Icu_lGetChannelType(Channel);
    LocalIcuMapPtr =   (Icu_kConfigPtr->MappingIndexPtr) + Channel; 
    PhyChannelIndex = LocalIcuMapPtr->PhysicalChannelMap;
    ChIndex = LocalIcuMapPtr->ChannelIndexMap;
 
    #if ((ICU_ERU_USED == STD_ON) ||                                         \
         ((ICU_TIM_SIGEDGE_USED == STD_ON) &&(ICU_EDGE_DETECT_API == STD_ON)))
    /* Extract the actual cell number */
    CellUsed =  (Icu_17_GtmCcu6_ChannelType)
       LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;
    #endif
  
    /* ICU054, ICU006:The Initialization function will initialize all relevant
     * registers of the configured hardware with the values of the structure 
     * referenced by the parameter ConfigPtr
    */
    /* Work on depending on ICU option chosen for each channel */
    switch(IcuOption)
    {
      case ICU_GTM_ASIL_CHANNEL:    
      #if (ICU_MAX_ASIL_GTM_CHANNELS != 0U)    
      TempStorageVal = 0U;      
      Mcal_SetAtomic((sint32*)(void*)&TempStorageVal,
                    (uint32)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge),
                    (sint32)ICU_CHNL_EDGE_POS,
                    2);
      CompareFlag &= 
        (Icu_17_GtmCcu6_AsilGtmVarlist.GlbIndexStatus[PhyChannelIndex] ^ 
                                                                 ~TempStorageVal);      
      /* ICU041: All used registers used by configuration
          will be initialized */
      /* ICU051:  Enable interrupt SRC */
      /* Interrupt is not required for GTM resources */      
      #if((ICU_ASIL_TIM_SIGEDGE_USED == STD_ON) \
           &&(ICU_EDGE_DETECT_API == STD_ON))
      if (LocalIcuChanPtr->IcuProperties.MeasurementMode
                                                == ICU_MODE_SIGNAL_EDGE_DETECT)
      {
        uint8 GtmEdge;
        /* Cells are enabled to make GetInputState function work */
        GtmEdge = (uint8)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge);
        TempStoreReturnVal = \
        Icu_lGtmStartEdgeDetectCheck((Icu_17_GlobalChannelNumberType)CellUsed, \
        GtmEdge);
        CompareFlag &= TempStoreReturnVal; 
      }      
      #endif
      
      #if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON) 
      if ((LocalIcuChanPtr->IcuProperties.MeasurementMode == \
           ICU_MODE_SIGNAL_MEASUREMENT))
      {
        TempStoreReturnVal = Icu_lSigMesInitCheck(LocalIcuChanPtr, 
                                            Channel,(uint32)ChIndex);
        CompareFlag &= TempStoreReturnVal;                                            
      }
      #endif      
      #endif    
      break;
      
      case ICU_CCU6_ASIL_CHANNEL:  
      #if (ICU_MAX_ASIL_CCU6_CHANNELS != 0U)  
      TempStorageVal = 0U;
     /*Mcal_Extract(&TempStorage,ICU_CHNL_EDGE_POS, ICU_CHNL_EDGE_BIT_LENGTH);*/
      Mcal_SetAtomic((sint32*)(void*)&TempStorageVal,
                    (uint32)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge),
                    ICU_CHNL_EDGE_POS,
                    2);                    
      CompareFlag &= 
        (Icu_17_GtmCcu6_AsilCcu6Varlist.GlbIndexStatus[PhyChannelIndex] ^ 
                                                                  ~TempStorageVal);
      
      /* CCU Port connection initialization */
      TempStoreReturnVal = Icu_lCcu6PortInitCheck(LocalIcuChanPtr);
      CompareFlag &= TempStoreReturnVal;      
      /* Start ICU channels configured for Edge Detection */
      TempStoreReturnVal = Icu_lCcu6ChannelInitCheck(Channel, LocalIcuChanPtr); 
      CompareFlag &= TempStoreReturnVal;   
      #if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON)
      if ((LocalIcuChanPtr->IcuProperties.MeasurementMode == \
           ICU_MODE_SIGNAL_MEASUREMENT))
      {
        TempStoreReturnVal = Icu_lSigMesInitCheck(LocalIcuChanPtr, 
                                            Channel,(uint32)ChIndex);
        CompareFlag &= TempStoreReturnVal;                                            
      }   
      #endif        
      #endif
        break;
      #if (ICU_MAX_QM_CHANNELS != 0U)       
      #if (ICU_QM_GTM_TIM_USED == STD_ON) 
      case ICU_GTM_QM_CHANNEL:
      TempStorageVal = 0U;
     /*Mcal_Extract(&TempStorage,ICU_CHNL_EDGE_POS, ICU_CHNL_EDGE_BIT_LENGTH);*/
       Mcal_SetAtomic((sint32*)(void*)&TempStorageVal,
                    (uint32)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge),
                    (sint32)ICU_CHNL_EDGE_POS,
                    2);                     
      CompareFlag &= 
        (Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex] ^ 
                                                                  ~TempStorageVal);  
                                                           
      /* Depending on ICU option take action */
      /* Extract the actual cell number */
      #if ((ICU_QM_TIM_SIGEDGE_USED == STD_ON) &&(ICU_EDGE_DETECT_API == STD_ON))
      if (LocalIcuChanPtr->IcuProperties.MeasurementMode == 
                                                  ICU_MODE_SIGNAL_EDGE_DETECT)
      {
        uint8 GtmEdge;
        /* Cells are enabled to make GetInputState function work */
        GtmEdge = (uint8)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge);
        TempStoreReturnVal = Icu_lGtmStartEdgeDetectCheck( 
                      (Icu_17_GlobalChannelNumberType)CellUsed,GtmEdge);
        CompareFlag &= TempStoreReturnVal; 
      }    
      #endif

      #if (ICU_QM_TIM_SIGMEAS_USED == STD_ON) 
      if ((LocalIcuChanPtr->IcuProperties.MeasurementMode == \
                                              ICU_MODE_SIGNAL_MEASUREMENT))
      {
        TempStoreReturnVal = Icu_lSigMesInitCheck (LocalIcuChanPtr, 
                                              Channel, 
                                              (uint32)ChIndex);
       CompareFlag &= TempStoreReturnVal;  
      }
      #endif      
      break;
       #endif   
       
      #if (ICU_MAX_QM_CCU6_CHANNELS != 0U)
      case ICU_CCU6_QM_CHANNEL:
      TempStorageVal = 0U;
     /*Mcal_Extract(&TempStorage,ICU_CHNL_EDGE_POS, ICU_CHNL_EDGE_BIT_LENGTH);*/
      Mcal_SetAtomic((sint32*)(void*)&TempStorageVal,
                    (uint32)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge),
                    ICU_CHNL_EDGE_POS,
                    2);          
      CompareFlag &= 
        Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex] ^ 
                                                                  ~TempStorageVal;        
      /* CCU Port connection initialization */
      TempStoreReturnVal = Icu_lCcu6PortInitCheck(LocalIcuChanPtr);
      CompareFlag &= TempStoreReturnVal;       
      /* Start ICU channels configured for Edge Detection */
      TempStoreReturnVal = Icu_lCcu6ChannelInitCheck(Channel, LocalIcuChanPtr);
      CompareFlag &= TempStoreReturnVal;     
      #if (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)
      if ((LocalIcuChanPtr->IcuProperties.MeasurementMode == \
           ICU_MODE_SIGNAL_MEASUREMENT))
      {
        TempStoreReturnVal = Icu_lSigMesInitCheck(LocalIcuChanPtr, 
                                            Channel,(uint32)ChIndex);
        CompareFlag &= TempStoreReturnVal;                                            
      }   
      #endif           
      break;
      #endif
              
      default: /* ICU_ERU_OPTION: */
      /* Depending on ICU option take action */
      #if (ICU_ERU_USED == STD_ON)
      TempStorageVal = 0U; 
     /*Mcal_Extract(&TempStorage,ICU_CHNL_EDGE_POS, ICU_CHNL_EDGE_BIT_LENGTH);*/
      Mcal_SetAtomic((sint32*)(void*)&TempStorageVal,
                    (uint32)(LocalIcuChanPtr->IcuProperties.DefaultStartEdge),
                    ICU_CHNL_EDGE_POS,
                    2);                    
      CompareFlag &= 
        Icu_17_GtmCcu6_QmVarlist.GlbIndexStatus[PhyChannelIndex] ^ 
                                                                  ~TempStorageVal;        
      /* Get the ERU Cell Number and set the Interrupt Node Pointer to 
         SCU_SRC1 for the Cell Number TempUse */
      EruEicrUsed    = Icu_lGetEruEicr(CellUsed);
      EruEicrChannel = Icu_lGetEruEicrChannel(CellUsed);
      Icu_lSetEruEdgeEien(
          (Icu_17_GtmCcu6_ActivationType)LocalIcuChanPtr->
                                              IcuProperties.DefaultStartEdge,
          EruEicrUsed,
          EruEicrChannel  );         
      Icu_lSetEruIgp(0U);
        
      #endif
      break;
      #endif    
    }     
            
    /* Increment the ICU configured channel ROM pointer*/
    LocalIcuChanPtr++;
  }/* End of for loop */
  UNUSED_PARAMETER(TempStoreReturnVal)  
  UNUSED_PARAMETER(ChIndex) 
  if (CompareFlag != 0xFFFFFFFFU)
  {
    ErrorFlag = E_NOT_OK;
  }
  else
  {
    ErrorFlag = E_OK;
  }  
  return(ErrorFlag);
}
#endif


#if (ICU_SAFETY_ENABLE == STD_ON)
#if ((ICU_TIM_SIGMEAS_USED == STD_ON) || (ICU_CCU6_SIGMEAS_USED == STD_ON)) 
/******************************************************************************
** Syntax :           static _INLINE_ uint32 Icu_lSigMesInit                 **
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
static _INLINE_ uint32 Icu_lSigMesInitCheck
(
  const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr,
  Icu_17_GtmCcu6_ChannelType Channel,
  uint32 DutyIndex
)
{
  uint32 TempStorage;
  uint32 TempStorageRetVal;
  volatile uint32 CompareFlag; 
  uint8 ChlType;
  Icu_17_GtmCcu6_SignalMeasurementPropertyType SigKind; 

  CompareFlag = 0xFFFFFFFFU;
  SigKind = (LocalIcuChanPtr->IcuProperties.MeasurementProperty);

  ChlType = Icu_lGetChannelType(Channel);  
  if(ChlType == ICU_GTM_ASIL_CHANNEL )
  {
    #if (ICU_MAX_SIGNAL_MEASURE_ASIL_GTM_CHANNELS != 0U)   
    TempStorage = (uint32)
           Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].SigProp;
    CompareFlag &= (TempStorage ^ ~(uint32)SigKind);  
    
    TempStorage = (uint32)
         Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].IntrCounter;
    CompareFlag &= (TempStorage ^ ~(uint32)ICU_SIGNALMEASUREMENT_COUNTER);   
  
    if ( (ICU_ACTIVE_TIME == SigKind ) 
         || (ICU_PERIOD_TIME  == SigKind ) )
    {
      TempStorage = ~(uint32)
          Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].CfgEdge;
      CompareFlag &= (TempStorage ^ 
                      (uint32)LocalIcuChanPtr->IcuProperties.DefaultStartEdge);
    }
    else 
    {
      TempStorage = ~(uint32)
        Icu_17_GtmCcu6_AsilGtmVarlist.MeasurementParas[DutyIndex].CfgEdge;
       TempStorageRetVal = (uint32)Icu_lGetEdge(SigKind);
      CompareFlag &= (TempStorage ^ TempStorageRetVal);
    }
    #endif
   }
   else if(ChlType == ICU_CCU6_ASIL_CHANNEL)
   {
    #if (ICU_MAX_SIGNAL_MEASURE_ASIL_CCU6_CHANNELS != 0U)  
    TempStorage = (uint32)
           Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[DutyIndex].SigProp;
    CompareFlag &= (TempStorage ^ ~(uint32)SigKind);  
    
    TempStorage = (uint32)
         Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[DutyIndex].IntrCounter;
    CompareFlag &= (TempStorage ^ ~(uint32)ICU_SIGNALMEASUREMENT_COUNTER);   
  
    if ( (ICU_ACTIVE_TIME == SigKind ) 
         || (ICU_PERIOD_TIME  == SigKind ) )
    {
      TempStorage = ~(uint32)
          Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[DutyIndex].CfgEdge;
      CompareFlag &= (TempStorage ^ 
                      (uint32)LocalIcuChanPtr->IcuProperties.DefaultStartEdge);
    }
    else 
    {
      TempStorage = ~(uint32)
        Icu_17_GtmCcu6_AsilCcu6Varlist.MeasurementParas[DutyIndex].CfgEdge;
       TempStorageRetVal = (uint32)Icu_lGetEdge(SigKind);        
      CompareFlag &= (TempStorage ^ TempStorageRetVal);
    }
 
   #endif
  }
    else
  {
    #if (ICU_MAX_SIGNAL_MEASURE_QM_CHANNELS != 0U)
    TempStorage = (uint32)
           Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].SigProp;
    CompareFlag &= (TempStorage ^ ~(uint32)SigKind);  
    TempStorage = (uint32)
          Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].IntrCounter;
    CompareFlag &= (TempStorage ^ ~(uint32)ICU_SIGNALMEASUREMENT_COUNTER);   
  
    if ( (ICU_ACTIVE_TIME == SigKind ) 
         || (ICU_PERIOD_TIME  == SigKind ) )
    {
      TempStorage = ~(uint32)
          Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].CfgEdge;
      CompareFlag &= (TempStorage ^ 
                      (uint32)LocalIcuChanPtr->IcuProperties.DefaultStartEdge);
    }
    else 
    {
      TempStorage = ~(uint32)
        Icu_17_GtmCcu6_QmVarlist.MeasurementParas[DutyIndex].CfgEdge;
       TempStorageRetVal = (uint32)Icu_lGetEdge(SigKind);            
      CompareFlag &= (TempStorage ^ TempStorageRetVal);
    }
    #endif
  }

  return(CompareFlag);
}
#endif
#endif


#if ((ICU_GTM_TIM_USED == STD_ON) && (ICU_INITCHECK_API == STD_ON))
/*******************************************************************************
** Traceability: [cover parentID=DS_AS_ICU054_2]
**                                                                            **
** Syntax : static Std_ReturnType Icu_lGtmChannelInit()                       **
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
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description :     Function to initialize ICU Channels. This function is    **
**                   needed to initialize GTM channels used by ICU. This is   **
**                   mainly needed while changing the PB configuration of ICU **
**                   while not changing the MCU configuration.                **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Icu_lGtmChannelInitCheck(void)
{
  const Icu_17_GtmCcu6_ChannelConfigType* LocalIcuChanPtr;
  Gtm_GlobalChannelNumberType TimChannelNumber;
  Icu_17_GtmCcu6_ChannelIdentifierType GlobalChannelId;
  Ifx_GTM_TIM_CH_TYPE *TimChannelRegPtr;

  uint8 ModuleNumber;                   
  uint8 ChannelNumber; 
  uint8 Channel; 
  Std_ReturnType ErrorFlag;
  uint32 TempFlag;  
  uint32 TempFlag2;  
  Icu_17_GtmCcu6_ChannelType MaxChannels;    
  ErrorFlag = E_NOT_OK;  
  
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
  /* LocalIcuChanPtr = ((Icu_kConfigPtr->ChannelConfigPtr) + Channel);*/
  for(Channel = 0U; Channel < MaxChannels; Channel++)
  {
    TempFlag = 0U;
    TempFlag2 = 0U;
    LocalIcuChanPtr = (Icu_kConfigPtr->ChannelConfigPtr) + Channel;
    TimChannelNumber = 
    (Gtm_GlobalChannelNumberType)  
    LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber;

    if(LocalIcuChanPtr->IcuProperties.AssignedHwUnit == ICU_GTM_OPTION)
    {
      GlobalChannelId = Icu_lGtmChannelIdentifier(TimChannelNumber);
      ModuleNumber  = Icu_lGetGtmModuleNo(GlobalChannelId);
      ChannelNumber = GlobalChannelId.ChannelNo;
      TimChannelRegPtr = \
           &(((*(Ifx_GTM_TIMx*)(void*)(MODULE_GTM.TIM)).
              CH_TIM[ModuleNumber]).CH[ChannelNumber]);

     TempFlag |= (uint32)
            ((uint32)(LocalIcuChanPtr->IcuProperties.
                TimChannelClockSelect) << ICU_GTM_TIM_CLOCKDIV_POS); 
     TempFlag2 |= (uint32)
          ((uint32_t)(TimChannelRegPtr->CH_CTRL.U) & (3UL << 24));
     
     if (TempFlag == TempFlag2)
     {
       ErrorFlag = E_OK;
     }
     else
     {
       ErrorFlag = E_NOT_OK;
     }
     
     if (TimChannelRegPtr->CH_FLT_RE.U != 
              (uint32_t) \
              (LocalIcuChanPtr->IcuProperties.TimChFilterTimeForRisingEdge)) 
     {
        ErrorFlag = E_NOT_OK;
     }
     if (TimChannelRegPtr->CH_FLT_FE.U != 
             (uint32_t) \
             (LocalIcuChanPtr->IcuProperties.TimChFilterTimeForFallingEdge)) 
     {
       ErrorFlag = E_NOT_OK;
     }  
     if (TimChannelRegPtr->CH_IRQ_MODE.U != 
             (uint32_t) \
             (LocalIcuChanPtr->IcuProperties.TimInterruptMode)) 
     {
       ErrorFlag = E_NOT_OK; 
     }
     if(ErrorFlag == E_NOT_OK)
     {
       break;
     }
    /*CH_IRQ_NOTIFY register not verified as it can be changed by hardware */
    
   }  /* end of if */
  }/* end of for */

  return (ErrorFlag);
}
#endif


#if ((ICU_CCU6_USED == STD_ON) && (ICU_INITCHECK_API == STD_ON))
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
static _INLINE_ uint32 Icu_lCcu6ChannelInitCheck(
                        Icu_17_GtmCcu6_ChannelType Channel,
                        const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr)
{
  uint8 CcuKernalNumber;    /* To hold CCU Kernal Number */
  uint8 CcChannelNumber;    /* To hold the CC channel number */

  volatile uint32 CompareFlag = 0xFFFFFFFFU;

   /* Lower Nibble of AssignedHwUnitNumber holds the Kernal Number */
  CcuKernalNumber = ((uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber\
                                            & ICU_CCU_GET_LOWER_NIBBLE);
  /* Upper Nibble of AssignedHwUnitNumber holds the Channel Number */
  CcChannelNumber =((uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber \
                            & ICU_CCU_GET_UPPER_NIBBLE)>> ICU_BRING_TO_BIT_0;

 #if (ICU_CCU6_USED == STD_ON) 
   CompareFlag &= (Icu_17_CcuChannelMap[CcuKernalNumber][CcChannelNumber] \
                    ^ ~(uint32)Channel);  
  #else
  UNUSED_PARAMETER(Channel)
  #endif
  
  return(CompareFlag);
  
}
#endif
/* #if (ICU_CCU6_USED == STD_ON) */



#if (ICU_INITCHECK_API == STD_ON)
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
static _INLINE_ uint32 Icu_lCcu6PortInitCheck(
                       const Icu_17_GtmCcu6_ChannelConfigType *LocalIcuChanPtr)
{
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  uint8 CcChannelNumber;    /* To hold the CC channel number */
  uint32 TempStorage;
  volatile uint32 CompareFlag;
  uint32 Temp;
 
  CompareFlag = 0xFFFFFFFFU;
  /* Upper Nibble of AssignedHwUnitNumber holds the Channel Number */
  CcChannelNumber = ((uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber\
                    & ICU_CCU_GET_UPPER_NIBBLE) >> ICU_BRING_TO_BIT_0;

  /* Get the base address of the Kernal */
  Ccu6RegPtr = Icu_lCcuGetBaseAddress(
                    (uint8)LocalIcuChanPtr->IcuProperties.AssignedHwUnitNumber);
  
  /* Port connections to CCU */
  TempStorage = ((uint32)LocalIcuChanPtr->IcuProperties.Ccu6Connections << \
                           (CcChannelNumber * ICU_CCU_PISEL_BITS_PER_CHANNEL));
  Temp = ~((uint32)Ccu6RegPtr->PISEL0.U &  
              (3UL << (CcChannelNumber * ICU_CCU_PISEL_BITS_PER_CHANNEL)));
  CompareFlag &= ((uint32)TempStorage ^ Temp);  
  return(CompareFlag);


}
#endif
#endif



#if (ICU_INITCHECK_API == STD_ON)
#if (ICU_CCU6_USED == STD_ON)
/*******************************************************************************
** Syntax : static Std_ReturnType Icu_lCcu6T12InitializationCheck(void)       **
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
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description :     Function to initialize the CCU6x kernal register         **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Icu_lCcu6T12InitializationCheck(void)
{
  volatile Ifx_CCU6 *Ccu6BaseRegPtr;/* Variable to hold the CCU6 base address */
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  uint8 KernalCount;        /* Loop count variable to count CCU6 kernals */
  
  volatile uint32 CompareFlag = 0xFFFFFFFFU;
  uint32 TempFlag;
  Std_ReturnType ErrorFlag;

  ErrorFlag = E_NOT_OK;
  
  /* Loop through all the available CCU6 kernals */
  for(KernalCount = 0U; KernalCount < (uint8)ICU_NO_OF_CCU6_MODULES; 
      KernalCount++)
  {
    Ccu6BaseRegPtr = &MODULE_CCU60;

    /* Enable the Kernals if not done prior by any other module */
    /* Get the base address of the Kernal */
    Ccu6RegPtr = Ccu6BaseRegPtr + KernalCount;

    /* Check if T12 initialization has to be done by ICU */
    if(Icu_kConfigPtr->T12Parameters[KernalCount] != (uint8)ICU_CCU6X_UNUSED)
    {
      TempFlag = (uint32)Ccu6RegPtr->CLC.U;

      /* Is Wakeup is desired, then EDIS is set, else it is reset */
      if((Icu_kConfigPtr->T12Parameters[KernalCount] & ICU_CCU_SLEEP_REQD) \
                                                                      > 0UL)
      {
        CompareFlag &= (TempFlag ^ ~((uint32)0x8U));
      }
      else
      {
        CompareFlag &= (TempFlag ^ 0xFFFFFFFFU);
      }
     /* In TCTR4 register, we set T12RR, T12RS and T12STR bits during 
        Icu_lCcu6T12Initialization. But the TCTR4 register bits are only 
        writable we can't read it back, so directly T12 regsiter is used 
        to validate the initialization */
     if(Ccu6RegPtr->T12.U > 0U)
     {
       ErrorFlag = E_OK;
     }
      /* Verify Enable Interrupt SR0 */
      TempFlag = (uint32)MODULE_SRC.CCU6.CCU6[KernalCount].SR0.B.SRE;
      CompareFlag &= (TempFlag ^ 0xFFFFFFFEU);      
    }
  }
   if (CompareFlag != 0xFFFFFFFFU)    
   {
     ErrorFlag = E_NOT_OK;
   }    
  return(ErrorFlag);    
}
#endif
#endif
#endif

#define ICU_17_GTMCCU6_STOP_SEC_CODE
#include "MemMap.h"
#endif

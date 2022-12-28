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
**  $FILENAME   : Dio.c $                                                    **
**                                                                           **
**  $CC VERSION : \main\51 $                                                 **
**                                                                           **
**  $DATE       : 2014-01-06 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This contains the functionality for DIO driver             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*******************************************************************************
**  TRACEABILITY : [cover parentID=DS_AS40X_DIO106,DS_AS_DIO001,
                    DS_AS_DIO005,DS_AS_DIO051_DIO055,DS_NAS_DIO_PR228,
                    DS_NAS_DIO_PR127,SAS_NAS_DIO_PR913,DS_MCAL_SWSC_DIO_0517
                    SAS_AS40X_DIO117_DIO168_DIO169_DIO170,DS_NAS_DIO_PR716,
                    SAS_AS_DIO171_DIO194,DS_MCAL_SWSC_DIO_0517,
                    DS_MCAL_SWSC_DIO_0503_0504_0508,SAS_AS321_DIO117,
                    DS_MCAL_SWSC_DIO_0509_2_0513_1,
                    DS_MCAL_SWSC_DIO_0509_3_0513_2,
                    DS_MCAL_SWSC_DIO_0509_4_0513_3,
                    DS_MCAL_SWSC_DIO_0509_5_0513_4,
                    DS_MCAL_SWSC_DIO_0509_6_0513_5,
                    DS_MCAL_SWSC_DIO_0509_7_0513_7,
                    DS_MCAL_SWSC_DIO_0513_8_0509_8]                          **
**                 [/cover]                                                  **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
/* DIO117: Inclusion structure */
#include "Dio.h"

/* Version sepcific header file */
#include "Dio_Ver.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/* Version checks */

#ifndef DIO_SW_MAJOR_VERSION
  #error "DIO_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef DIO_SW_MINOR_VERSION
  #error "DIO_SW_MINOR_VERSION is not defined. "
#endif

#ifndef DIO_SW_PATCH_VERSION
  #error "DIO_SW_PATCH_VERSION is not defined. "
#endif

/* Check for Correct inclusion of headers */
#if ( DIO_SW_MAJOR_VERSION != 3U )
  #error "DIO_SW_MAJOR_VERSION does not match. "
#endif
#if ( DIO_SW_MINOR_VERSION != 0U )
  #error "DIO_SW_MINOR_VERSION does not match. "
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))

/* Maximum Port Pin ID */
#define DIO_MAX_VALID_PORT_PIN_ID    (0x28FU)

/* 0th Bit Mask value */
#define DIO_CHANNEL_BIT_MASK  (0x01U)

/* Port numbers */
#define DIO_NUMBER_31         (31U)
#define DIO_NUMBER_32         (32U)

#endif /* DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON */

/* This macro is used to reset the Port pins */
#define DIO_CHANNEL_GROUP_RESET     ((uint32)16)

/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/



/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))

#define DIO_START_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

/* _INLINE_ Function to check if the port is
      available or not for the microcontroller*/
static _INLINE_ uint32 Dio_lIsPortAvailable31(uint32 Port);

/* _INLINE_ Function to check if the port is 
       available or not for the microcontroller*/
static _INLINE_ uint32 Dio_lIsPortAvailable40(uint32 Port);

/* _INLINE_ Function to check if the port
            is read only or it is writable*/
static _INLINE_ uint32 Dio_lIsPortAvailable(uint32 Port);

/* _INLINE_ Function to check if the 
     port is read only or it is writable */
static _INLINE_ uint32 Dio_lIsPortReadOnly31(uint32 Port);

/* _INLINE_ Function to check if the 
     port is read only or it is writable */
static _INLINE_ uint32 Dio_lIsPortReadOnly40(uint32 Port);

/* _INLINE_ Function to check if the port
          is read only or it is writable */
static _INLINE_ uint32 Dio_lIsPortReadOnly(uint32 Port);

/* _INLINE_ Function to check if the Pin
          available or not */
static _INLINE_ uint16 Dio_lIsPinAvailable(uint32 Port, uint8 Pin);

#define DIO_STOP_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON)*/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/* The following private definitions are available only if development error
   detection is enabled */
#if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))

  /* Start of memory mapping of 8 bit constant */
  #define DIO_START_SEC_CONST_8BIT
  #include "MemMap.h"

  /* Information on the most significant pin for each port */
  static const uint8 Dio_kMSPortPin[] =
  {
    DIO_PORT_0_MSPIN,
    DIO_PORT_1_MSPIN,
    DIO_PORT_2_MSPIN,
    DIO_PORT_3_MSPIN,
    DIO_PORT_4_MSPIN,
    DIO_PORT_5_MSPIN,
    DIO_PORT_6_MSPIN,
    DIO_PORT_7_MSPIN,
    DIO_PORT_8_MSPIN,
    DIO_PORT_9_MSPIN,
    DIO_PORT_10_MSPIN,
    DIO_PORT_11_MSPIN,
    DIO_PORT_12_MSPIN,
    DIO_PORT_13_MSPIN,
    DIO_PORT_14_MSPIN,
    DIO_PORT_15_MSPIN,
    DIO_PORT_16_MSPIN,
    DIO_PORT_17_MSPIN,
    DIO_PORT_18_MSPIN,
    DIO_PORT_19_MSPIN,
    DIO_PORT_20_MSPIN,
    DIO_PORT_21_MSPIN,
    DIO_PORT_22_MSPIN,
    DIO_PORT_23_MSPIN,
    DIO_PORT_24_MSPIN,
    DIO_PORT_25_MSPIN,
    DIO_PORT_26_MSPIN,
    DIO_PORT_27_MSPIN,
    DIO_PORT_28_MSPIN,
    DIO_PORT_29_MSPIN,
    DIO_PORT_30_MSPIN,
    DIO_PORT_31_MSPIN,
    DIO_PORT_32_MSPIN,
    DIO_PORT_33_MSPIN,
    DIO_PORT_34_MSPIN,
    DIO_PORT_35_MSPIN,
    DIO_PORT_36_MSPIN,
    DIO_PORT_37_MSPIN,
    DIO_PORT_38_MSPIN,
    DIO_PORT_39_MSPIN,
    DIO_PORT_40_MSPIN,
    DIO_PORT_41_MSPIN
  };

  /* End of memory mapping of 8 bit constant */
  #define DIO_STOP_SEC_CONST_8BIT
  #include "MemMap.h"

#endif /* DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON */

/* Start of memory mapping of 16 bit constant */
#define DIO_START_SEC_CONST_16BIT
#include "MemMap.h"

/* Mask values for all the ports.
   This constant is used to mask the undefined port pins within the port */
static const Dio_PortLevelType Dio_kMaskUndefinedPortPins[] =
{
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT0,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT1,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT2,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT3,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT4,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT5,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT6,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT7,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT8,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT9,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT10,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT11,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT12,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT13,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT14,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT15,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT16,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT17,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT18,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT19,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT20,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT21,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT22,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT23,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT24,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT25,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT26,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT27,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT28,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT29,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT30,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT31,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT32,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT33,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT34,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT35,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT36,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT37,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT38,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT39,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT40,
  (Dio_PortLevelType)DIO_MASK_UNDEF_PINS_PORT41
};

/* Stop of memory mapping of 16 bit constant */
#define DIO_STOP_SEC_CONST_16BIT
#include "MemMap.h"

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/* Memory Map of the DIO Code */
#define DIO_START_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/* DIO001: DIO driver does not provide the initialization interface */
/* DIO102: It is the users responsibility to initialize the PORT driver before
   using any functionality of the DIO driver */
/* DIO002: Direction change of pin is supported by the PORT driver */
/* DIO049: DIO061: The run time configuration for DIO ports and port pins is 
   handled by PORT driver */
/* DIO051: All DIO services writes or read directly the hardware registers 
   and no buffering is done */
/* DIO055: All the services of this driver are synchronous */
/* DIO101: This driver does not provide any callback notifications */

/* Enable / Disable DET check functions with DIO_DEV_ERROR_DETECT switch */
#if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))
/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_DIO074,DS_AS40X_DIO175,DS_AS_DIO179]
**                                                                            **
** Syntax           : uint8 Dio_lCheckChannelId                               **
**                    (                                                       **
**                      uint8 ApiId,                                          **
**                      Dio_ChannelType ChannelId                             **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters (in)  : ApiId - Service ID of API that calls this function      **
**                    ChannelId - that needs to be checked for validity       **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                    DIO_NO_ERROR: if no error is detected                   **
**                    DIO_ERROR: if DET error is detected                     **
**                                                                            **
** Description      : This function:                                          **
**  - DIO048: This function checks ChannelId for DET error                    **
**    DIO_E_PARAM_INVALID_CHANNEL_ID                                          **
**  - is not for the user of DIO driver                                       **
**                                                                            **
*******************************************************************************/
uint8 Dio_lCheckChannelId(uint8 ApiId, Dio_ChannelType ChannelId)
{
  uint32       PortNumber;
  uint32       Index;
  uint32       ConfigIndex;
  uint32       PortReadOnly;
  uint32       PortAvailable;
  uint32       PinAvailable;
  uint8        PinNumber;
  uint8        ErrStatus;
  
  ErrStatus = (uint8)DIO_NO_ERROR;
  ConfigIndex = 0U;

  /* If the DIO channel ID is greater than the max value of Port pin ID */
  if(ChannelId > DIO_MAX_VALID_PORT_PIN_ID)
  {
    ErrStatus = (uint8)DIO_ERROR;
  }
  else
  {
    /* Derive the port and pin number from symbolic channel ID */
    PortNumber = (uint32)Dio_lGetPortNumber(ChannelId);
    PinNumber  = (uint8)Dio_lGetPinNumber(ChannelId);
    
    PortAvailable = Dio_lIsPortAvailable(PortNumber);
    PinAvailable  = Dio_lIsPinAvailable(PortNumber,PinNumber);
    
    if( (PortAvailable == 0U) || (PinAvailable == 0U) )
    {
       ErrStatus = (uint8)DIO_ERROR;
    }
    else
    {
       for(Index = 0U;Index <= PortNumber;Index++)
       {
         if(Dio_lIsPortAvailable(Index) != 0U)
         {
           ConfigIndex++; /* to identify the Index of configuration*/
         }
       }
         /*decremented since the ConfigIndex value is 1 for Index 0*/
       ConfigIndex--;
       PortReadOnly = Dio_lIsPortReadOnly(PortNumber);

       if(
        Dio_kConfigPtr->Dio_PortChannelConfigPtr[ConfigIndex].Dio_PortIdConfig
                                                   == DIO_PORT_NOT_CONFIGURED)
       {
         ErrStatus = (uint8)DIO_ERROR;
       }

       /* Check for the validity of symbolic Channel ID */
       else if(Dio_lCheckAnalogChannel(ApiId,PortReadOnly) == DIO_ERROR)
       {
         ErrStatus = (uint8)DIO_ERROR;
       }
       else if(((Dio_kConfigPtr->
                 Dio_PortChannelConfigPtr[ConfigIndex].Dio_ChannelConfig) &
                ((uint32)0x1U << PinNumber)) == 0U
               )
       {
         ErrStatus = (uint8)DIO_ERROR;
       }
       else
       {
         /*Misra check*/
       }
     }
  }

  if(ErrStatus == (uint8)DIO_ERROR)
  {
    #if (DIO_DEV_ERROR_DETECT == STD_ON)
      /* The channel id passed to the function is invalid. Report error id.
         DIO_E_PARAM_INVALID_CHANNEL_ID to the error hook function */
      Det_ReportError( (uint16)DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        ApiId,
                        DIO_E_PARAM_INVALID_CHANNEL_ID
                      );
   #endif /*DIO_DEV_ERROR_DETECT == STD_ON */
  
   #if (DIO_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError(
                        (uint16)DIO_MODULE_ID,
                         DIO_INSTANCE_ID,
                         ApiId,
                         DIO_E_PARAM_INVALID_CHANNEL_ID
                      );
   #endif /*DIO_SAFETY_ENABLE == STD_ON */
  }

  return (ErrStatus);
}/* Dio_lCheckChannelId */

/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_DIO075,DS_AS40X_DIO177,DS_AS_DIO179]
**                                                                            **
** Syntax           : uint8 Dio_lCheckPortId                                  **
**                    (                                                       **
**                      uint8 ApiId,                                          **
**                      Dio_PortType PortId                                   **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters (in)  : ApiId  - Service ID of API that calls this function     **
**                    PortId - that needs to be checked for validity          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : uint16                                                  **
**                    DIO_NO_ERROR: if no error is detected                   **
**                    DIO_ERROR: if DET error is detected                     **
**                                                                            **
** Description      :                                                         **
** - This function checks the validity of the PortId. In case error is        **
**   detected, the error DIO_E_PARAM_INVALID_PORT_ID is reported              **
** - This function is local to the driver module and is not for the user of   **
**   DIO driver                                                               **
** - This function is available only if DET is enabled                        **
**                                                                            **
*******************************************************************************/
uint8 Dio_lCheckPortId (uint8 ApiId, Dio_PortType PortId)
{
  uint32      Index;
  uint32      ConfigIndex;
  uint32      PortReadOnly;
  uint32      PortAvailable;
  uint8       ErrStatus;
  
  ErrStatus = (uint8)DIO_NO_ERROR;
  ConfigIndex = 0U;

  PortAvailable = (uint32)Dio_lIsPortAvailable((uint32)PortId);

  /* Check for the validity of symbolic port ID */
  if( (PortAvailable == 0U) )
  {
    ErrStatus = (uint8)DIO_ERROR;
  }
  else
  {
    for(Index = 0U;Index <= PortId;Index++)
    {
      if(Dio_lIsPortAvailable(Index) != 0U)
      {
        ConfigIndex++; /* to identify the Index of configuration*/
      }
    }
  
    ConfigIndex--;/*decremented since the ConfigIndex value is 1 for Index 0*/

    PortReadOnly = Dio_lIsPortReadOnly((uint32)PortId);

    if(Dio_kConfigPtr->Dio_PortChannelConfigPtr[ConfigIndex].Dio_PortIdConfig
                                                  == DIO_PORT_NOT_CONFIGURED)
    {
       ErrStatus = (uint8)DIO_ERROR;
    }
    else if(Dio_lCheckAnalogPort(ApiId,PortReadOnly) == DIO_ERROR)
    {
       ErrStatus = (uint8)DIO_ERROR;
    }
    else
    {
      /*Misra check*/
    }
  }
  if(ErrStatus == (uint8)DIO_ERROR)
  {
    #if (DIO_DEV_ERROR_DETECT == STD_ON)
      /* The port id passed to the function is invalid. Report error id
         DIO_E_PARAM_INVALID_PORT_ID to the error hook function */
      Det_ReportError( (uint16)DIO_MODULE_ID,
                        DIO_INSTANCE_ID,
                        ApiId,
                        DIO_E_PARAM_INVALID_PORT_ID
                      );
   #endif /*DIO_DEV_ERROR_DETECT == STD_ON */
  
   #if (DIO_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError(
                        (uint16)DIO_MODULE_ID,
                         DIO_INSTANCE_ID,
                         ApiId,
                         DIO_E_PARAM_INVALID_PORT_ID
                      );
   #endif /*DIO_SAFETY_ENABLE == STD_ON */
  }
  return (ErrStatus);
}/* Dio_lCheckPortId */

/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_DIO114,DS_AS40X_DIO178,DS_AS_DIO179]
**                                                                            **
** Syntax           : static uint32 Dio_lCheckGroupId                         **
**                    (                                                       **
**                      uint8 ApiId,                                          **
**                      const Dio_ChannelGroupType *GroupIdPtr                **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters (in)  : ApiId - Service ID of API that calls this function      **
**                    GroupIdPtr - Pointer to group configuration that needs  **
**                    to be checked for any DET error                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                    DIO_NO_ERROR: if no error is detected                   **
**                    DIO_ERROR: if DET error is detected                     **
**                                                                            **
** Description      : This function:                                          **
**  - DIO048: This function checks the GroupIdPtr for DET error               **
**    DIO_E_PARAM_INVALID_GROUP_ID                                            **
**                                                                            **
*******************************************************************************/
uint8 Dio_lCheckGroupId(uint8 ApiId, const Dio_ChannelGroupType *GroupIdPtr)
{
  uint32 Index;
  uint32 PortReadOnly;
  uint32 PortAvailable;
  uint8  ErrStatus;

  /* Initialise the Error status to DIO_ERROR */
  ErrStatus = (uint8)DIO_ERROR;

  /* Check GroupIdPtr for NULL_PTR */
  if (GroupIdPtr != NULL_PTR)
  {
    for(Index = 0U;Index < (Dio_kConfigPtr->Dio_ChannelGroupConfigSize);Index++)
    {
      if (GroupIdPtr == &(Dio_kConfigPtr->Dio_ChannelGroupConfigPtr[Index]))
      {
      /*DIO114: channel group is valid within the current configuration*/
        ErrStatus = (uint8)DIO_NO_ERROR;
        break;
      }
    }
    if (ErrStatus != (uint8)DIO_ERROR)
    {
      /*Check if the port is Analog port for Write operation*/
      PortReadOnly = Dio_lIsPortReadOnly((uint32)(GroupIdPtr->port));
      PortAvailable = Dio_lIsPortAvailable((uint32)(GroupIdPtr->port));
      
      if( ((ApiId == DIO_SID_WRITECHANNELGROUP) && (PortReadOnly != 0U))
             || (PortAvailable == 0U)
         )
      {
        /* Error status = Error has occurred */
        ErrStatus = (uint8)DIO_ERROR;
      }
      /* Check if mask = 0 */
      else if( ((GroupIdPtr->mask) == 0U) )
      {
        ErrStatus = (uint8)DIO_ERROR;
      }
      /* Check if mask value is invalid, i.e., mask value contains the
         unimplemented bits */
      else if( ( (GroupIdPtr->mask) &
                 (~((uint32)Dio_kMaskUndefinedPortPins[GroupIdPtr->port]))
               ) != (Dio_PortLevelType)0U)
      {
        ErrStatus = (uint8)DIO_ERROR;
      }

      /* Check if offset is greater than the most significant pin on the port
         Note that existence of the port is checked earlier */
      else if((uint32)(GroupIdPtr->offset) > 
                                (uint32)(Dio_kMSPortPin[GroupIdPtr->port]))
      {
        ErrStatus = (uint8)DIO_ERROR;
      }
      else
      {
        /* No functionality to implement. This is to avoid MISRA violation */
      }
   }
  } /* GroupIdPtr != NULL_PTR */

  if (ErrStatus == (uint8)DIO_ERROR)
  {
    #if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* DIO114: Reporting error Invalid Channel Group for wrong
       group configuration ID */
    Det_ReportError(
                   (uint16)DIO_MODULE_ID,
                    DIO_INSTANCE_ID, 
                    ApiId,
                    DIO_E_PARAM_L_INVALID_GROUP
                    );
    #endif /*DIO_DEV_ERROR_DETECT == STD_ON */

    #if (DIO_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError(
                    (uint16)DIO_MODULE_ID,
                     DIO_INSTANCE_ID,
                     ApiId,
                     DIO_E_PARAM_L_INVALID_GROUP
                     );
    #endif /*DIO_SAFETY_ENABLE == STD_ON */
  }  
  return (ErrStatus); 

}/* Dio_lCheckGroupId */

#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON )*/


/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_DIO137,DS_AS_DIO014_DIO037,
                       DS_AS_DIO092,DS_AS_DIO093,DS_AS_DIO060_6,DS_AS_DIO012,
                       DS_AS_DIO083,DS_AS_DIO118_3]                           **
**                                                                            **
** Syntax           : Dio_PortLevelType Dio_ReadChannelGroup                  **
**                    (                                                       **
**                      const Dio_ChannelGroupType *ChannelGroupIdPtr         **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : DIO005: reentrant                                       **
**                                                                            **
** Parameters (in)  : ChannelGroupIdPtr -                                     **
                        pointer to channel group configuration                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Dio_PortLevelType                                       **
**                                                                            **
** Description      : This function:                                          **
**  - DIO014: DIO037: returns the level of specified channel group            **
**                                                                            **
*******************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup
(
  const Dio_ChannelGroupType *ChannelGroupIdPtr
)
{
  Ifx_P             *GetPortAddressPtr;
  Dio_PortLevelType  RetVal;

  #if((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))

  /* Return value should be zero for errors*/
  RetVal = (Dio_PortLevelType)STD_LOW;

  if(
    Dio_lErrorCheckChannelGroupDet(ChannelGroupIdPtr,DIO_SID_READCHANNELGROUP)
                         == DIO_NO_ERROR
    )
  #endif /*DIO_SAFETY_ENABLE == STD_ON || DIO_DEV_ERROR_DETECT == STD_ON*/
  {
     /* DIO092: The input port value is masked with the configured mask value
     GetPortAddressPtr will hold the port address of Port0 to Port11 or 
     Port12 to Port16 depending on the Port number */
     GetPortAddressPtr = Dio_lGetPortAdr(ChannelGroupIdPtr->port);
     RetVal = (Dio_PortLevelType)(GetPortAddressPtr->IN.U & \
                                   (uint32)ChannelGroupIdPtr->mask);
  
     /* DIO093: shift the level by configured offset value and then return */
     RetVal = (RetVal >> ChannelGroupIdPtr->offset);
  }
  return (RetVal);
} /* Dio_ReadChannelGroup */

/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_DIO138,DS_AS_DIO008_DIO039,
                       DS_AS_DIO040,DS_AS_DIO090,DS_AS_DIO091,DS_AS_DIO060_7,
                       DS_AS_DIO109,DS_AS_DIO064,DS_AS_DIO119_3]              **
**                                                                            **
** Syntax           : void Dio_WriteChannelGroup                              **
**                    (                                                       **
**                      const Dio_ChannelGroupType *ChannelGroupIdPtr,        **
**                      Dio_PortLevelType Level                               **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : DIO005: reentrant                                       **
**                                                                            **
** Parameters (in)  : ChannelGroupIdPtr -                                     **
                        pointer to channel group configuration                **
**                    Level - Sets level of specified channel group           **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**  - DIO039: sets the level of specified channel group                       **
**  - DIO008: The value for all the pins the channel group are set at         **
**    one shot                                                                **
**  - DIO040: Other pins of the port and pins that are configured as          **
**    input remains unchanged                                                 **
**                                                                            **
*******************************************************************************/
void Dio_WriteChannelGroup
(
  const Dio_ChannelGroupType *ChannelGroupIdPtr,
  Dio_PortLevelType Level
)
{
  /* 
    Note: volatile is used for the variable GetPortAddressPtr.
    The compiler may optimise the function call and the desired Level may not
    be written to the Channel or to the Port.
  */
  volatile Ifx_P *GetPortAddressPtr;
  uint32          PortVal;
  uint32          PortResetVal;

  #if((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))
  if(
   Dio_lErrorCheckChannelGroupDet(ChannelGroupIdPtr,DIO_SID_WRITECHANNELGROUP)
                         == DIO_NO_ERROR )
  #endif /*DIO_SAFETY_ENABLE == STD_ON || DIO_DEV_ERROR_DETECT == STD_ON*/
  {
    /* DIO090: passed Level is masked as per the configuration */
    /* DIO091: Level is shifted by the configured offset */
    /* PortVal is used to set the bits */
    PortVal = (uint32)(((uint32)Level << ChannelGroupIdPtr->offset) & \
                                               ChannelGroupIdPtr->mask);
   
    /* PortResetVal is used to reset the bits */
    PortResetVal = ((~PortVal) & ((uint32)ChannelGroupIdPtr->mask));
   
    PortVal = (PortVal | (PortResetVal << DIO_CHANNEL_GROUP_RESET));
   
    /* GetPortAddressPtr will hold the port address of Port0 to Port11 or
       Port12 to Port16 depending on the Port number */
    GetPortAddressPtr = Dio_lGetPortAdr(ChannelGroupIdPtr->port);
    GetPortAddressPtr->OMR.U = PortVal;
  }
} /* Dio_WriteChannelGroup */

/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_DIO133,DS_AS_DIO027,DS_AS_DIO011,
                       DS_AS_DIO060_1,DS_AS_DIO089,DS_AS_DIO012,DS_AS_DIO083,
                       DS_AS_DIO118_1]                                        **
**                                                                            **
** Syntax           : Dio_LevelType Dio_ReadChannel                           **
**                    (                                                       **
**                      Dio_ChannelType ChannelId                             **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ChannelId - ChannelId whose level to be read            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Dio_LevelType - The function returns value or the level **
**                  of the specified channel which is of type Dio_LevelType   **
**                                                                            **
** Description      : This function:                                          **
**      - DIO011: DIO27: returns the level of specified channel               **
**      - DIO012: The specified channel can be input or output                **
**      - DIO085: returns the physical level of the channel                   **
**                                                                            **
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
  uint32        PinPosition;
  Dio_LevelType RetVal;
  Ifx_P *GetPortAddressPtr;

  /* Return value should be zero for errors*/
  RetVal = (Dio_LevelType)STD_LOW;
  

  #if((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))
  if(Dio_lErrorCheckChannelDet(ChannelId,DIO_SID_READCHANNEL)
                         == DIO_NO_ERROR)
  #endif /*DIO_SAFETY_ENABLE == STD_ON || DIO_DEV_ERROR_DETECT == STD_ON*/
  {
    /* 
      GetPortAddressPtr will hold the port address 
    */
    GetPortAddressPtr = Dio_lGetPortAdr(Dio_lGetPortNumber(ChannelId));
      
    /* Get the Pin position */
    PinPosition = ((uint32)0x01U << Dio_lGetPinNumber(ChannelId));
  
    /* Read the Channel level and decide the return value */
    if ( (PinPosition & (GetPortAddressPtr->IN.U)) != (Dio_LevelType)STD_LOW )
    {
      RetVal = (Dio_LevelType)STD_HIGH;
    }
  }
  return RetVal;
}/* Dio_ReadChannel */

/*******************************************************************************
** Traceability   : [cover parentID=DS_AS_DIO134,DS_AS_DIO006,DS_AS_DIO028,
                     DS_AS_DIO029_DIO070,DS_AS_DIO079,DS_AS_DIO060_2,
                     DS_AS_DIO109,DS_AS_DIO089,DS_AS_DIO064,DS_AS_DIO119_1]   **
**                                                                            **
** Syntax : void Dio_WriteChannel                                             **
**          (                                                                 **
**             Dio_ChannelType ChannelId,                                     **
**             Dio_LevelType Level                                            **
**          )                                                                 **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  1                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  DIO005: DIO060: reentrant                                     **
**                                                                            **
** Parameters (in):  ChannelId - ChannelId whose level to be set              **
**                   Level - Channel level to be set                          **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : This function:                                               **
**      - DIO006: DIO028: DIO064: sets the specified level for specified      **
**        channel                                                             **
**      - DIO023: Possible levels for channel are STD_HIGH and STD_LOW        **
**      - DIO029: DIO070: DIO079: The real physical level of pin is not       **
**        modified if the specified channel is configured as input            **
**      - DIO109: For input channel this function writes into the output      **
**        register, so that pin level can be set immediately when direction   **
**        changed by PORT driver                                              **
**                                                                            **
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
  /*
    Note: volatile is used for the variable GetPortAddressPtr.
    The compiler may optimise the function call and the desired Level may not
    be written to the Channel or to the Port.
  */
  volatile Ifx_P *GetPortAddressPtr;
  uint32 OmrVal;

  OmrVal = DIO_OMR_RESET_BIT;

  #if((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))
  if(Dio_lErrorCheckChannelDet(ChannelId,DIO_SID_WRITECHANNEL)
                         == DIO_NO_ERROR)
  #endif /*DIO_SAFETY_ENABLE == STD_ON || DIO_DEV_ERROR_DETECT == STD_ON*/
  {
    #if(DIO_SAFETY_ENABLE == STD_ON)
    if( (Level == (Dio_LevelType)STD_LOW) || 
        (Level == (Dio_LevelType)STD_HIGH)   )
    #endif /* (DIO_SAFETY_ENABLE == ON) */
    {
      /* Decide the value to be written depending
          on the input parameter Level */
      if (Level != (Dio_LevelType)STD_LOW)
      {
        OmrVal = 0x01U;
      }
      /* GetPortAddressPtr will hold the port address */
      GetPortAddressPtr = Dio_lGetPortAdr(Dio_lGetPortNumber(ChannelId));
    
      /* Write to the PORT OMR register to reflect at the channel*/
      GetPortAddressPtr->OMR.U = 
                          (uint32_t)(OmrVal << Dio_lGetPinNumber(ChannelId));
    }
    #if (DIO_SAFETY_ENABLE == STD_ON)
    else
    {
       SafeMcal_ReportError(
             (uint16)DIO_MODULE_ID,
              DIO_INSTANCE_ID,
              DIO_SID_WRITECHANNEL,
              DIO_E_PARAM_INVALID_LEVEL);
    }
    #endif /*DIO_SAFETY_ENABLE == STD_ON */
  }
}/* Dio_WriteChannel */


/*******************************************************************************
** Traceability    : [cover parentID=DS_AS_DIO135,DS_AS_DIO013,DS_AS_DIO031,
                      DS_AS_DIO104,DS_AS_DIO060_4,DS_AS_DIO012,DS_AS_DIO083,
                      DS_AS_DIO118_2]                                         **
**                                                                            **
** Syntax : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)               **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  2                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  DIO005: DIO060: reentrant                                     **
**                                                                            **
** Parameters (in):  PortId - Port id whose level to be read                  **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  Dio_PortLevelType - The function returns value or the level **
**                of the specified channel which is of type Dio_PortLevelType **
**                                                                            **
** Description : This function:                                               **
**      - DIO013: DIO031: returns the level of specified port                 **
**                                                                            **
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
  Ifx_P             *GetPortAddressPtr;
  Dio_PortLevelType  RetVal;
    
  /* Check for the validity of symbolic Port ID 
     Reported DET if error detected
  */
  #if((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))

  /* Return value should be zero for errors*/
  RetVal = (Dio_PortLevelType)STD_LOW;

  if(Dio_lErrorCheckPortDet(PortId,DIO_SID_READPORT)
                         == DIO_NO_ERROR)
  #endif /*DIO_SAFETY_ENABLE == STD_ON || DIO_DEV_ERROR_DETECT == STD_ON*/
    {
      /* Return the Port IN register value
         DIO104: MSB for small port size are zero from hardware itself
         GetPortAddressPtr will hold the port address 
      */
      GetPortAddressPtr = Dio_lGetPortAdr(PortId);
      RetVal = ((Dio_PortLevelType)GetPortAddressPtr->IN.U &
                 Dio_kMaskUndefinedPortPins[PortId]
               );
    }
  return (RetVal);
}/* Dio_ReadPort */

/*******************************************************************************
** Traceability    : [cover parentID=DS_AS_DIO136,DS_AS_DIO007_DIO034,
                      DS_AS_DIO004_DIO035_DIO108,DS_AS_DIO105,DS_AS_DIO060_5,
                      DS_AS_DIO109,DS_AS_DIO064,DS_AS_DIO119_2]               **
**                                                                            **
** Syntax : void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  3                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  DIO005: DIO060: reentrant                                     **
**                                                                            **
** Parameters (in):  PortId - port id whose level to be set                   **
**                   Level - port level to be set                             **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : This function:                                               **
**      - DIO034: sets the specified level of specified port                  **
**      - DIO004: DIO035: DIO108: Hardware takes care not to change the value **
**        for the input channels while writing to complete port               **
**      - DIO007: All the port pins are written at one shot                   **
**                                                                            **
*******************************************************************************/
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
  /*
    Note: volatile is used for the variable GetPortAddressPtr.
    The compiler may optimise the function call and the desired Level may not
    be written to the Channel or to the Port.
  */
  volatile Ifx_P *GetPortAddressPtr;


  #if((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))
  if(Dio_lErrorCheckPortDet(PortId,DIO_SID_WRITEPORT)
                         == DIO_NO_ERROR)
  #endif /*DIO_SAFETY_ENABLE == STD_ON || DIO_DEV_ERROR_DETECT == STD_ON*/
    {
      /* Write the Level to the Port OUT register
         DIO105: If the port size is small, MSB's of Level are ignored
         GetPortAddressPtr will hold the port address
      */
      GetPortAddressPtr = Dio_lGetPortAdr(PortId);
      GetPortAddressPtr->OUT.U = (uint32)Level;
    }
}/* Dio_WritePort */

/*******************************************************************************
**                      Converted INLINE functions                            **
*******************************************************************************/

#if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))
/*******************************************************************************
** Syntax           : Dio_lIsPortAvailable31                                  **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is available or not      **
**   for the microcontroller.                                                 **
**   Parameter: Port number of type uint8/uint16                              **
*******************************************************************************/
static _INLINE_ uint32 Dio_lIsPortAvailable31(uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(DIO_CHANNEL_BIT_MASK) << (Port)) &
             ((uint32)DIO_PORTS_AVAILABLE_00_31) 
           );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Dio_lIsPortAvailable40                                  **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is available or not      **
**   for the microcontroller.                                                 **
**   Parameter: Port number of type uint8/uint16                              **
*******************************************************************************/
static _INLINE_ uint32 Dio_lIsPortAvailable40(uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(DIO_CHANNEL_BIT_MASK) << (Port - DIO_NUMBER_32)) & 
             ((uint32)DIO_PORTS_AVAILABLE_32_40) 
           );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Dio_lIsPortAvailable                                    **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is read only or          **
**   it is writable.                                                          **
**   Parameter: Port number of type uint8/uint16                              **
*******************************************************************************/
static _INLINE_ uint32 Dio_lIsPortAvailable(uint32 Port)
{
  uint32 RetVal;
  
  RetVal = ((Port > DIO_NUMBER_31) ? (Dio_lIsPortAvailable40(Port)) : 
                                     (Dio_lIsPortAvailable31(Port)) 
           );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Dio_lIsPortReadOnly31                                   **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is read only or          **
**   it is writable.                                                          **
**   Parameter: Port number of type uint8/uint16                              **
*******************************************************************************/
static _INLINE_ uint32 Dio_lIsPortReadOnly31(uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(DIO_CHANNEL_BIT_MASK) << (Port)) &
             ((uint32)DIO_PORTS_READONLY_00_31)
           );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Dio_lIsPortReadOnly40                                   **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is read only or          **
**   it is writable.                                                          **
**   Parameter: Port number of type uint8/uint16                              **
*******************************************************************************/
static _INLINE_ uint32 Dio_lIsPortReadOnly40(uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(DIO_CHANNEL_BIT_MASK) << (Port - DIO_NUMBER_32)) &
             ((uint32)DIO_PORTS_READONLY_32_40) 
           );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Dio_lIsPortReadOnly                                     **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is read only or          **
**   it is writable.                                                          **
**   Parameter: Port number of type uint8/uint16                              **
*******************************************************************************/
static _INLINE_ uint32 Dio_lIsPortReadOnly(uint32 Port)
{
  uint32 RetVal;
  
  RetVal = ((Port <= DIO_NUMBER_31) ? (Dio_lIsPortReadOnly31(Port)) :
                                      (Dio_lIsPortReadOnly40(Port))
           );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Dio_lIsPinAvailable                                     **
**                    (                                                       **
**                      Port,                                                 **
**                      Pin                                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port number                                      **
**                    Pin  - Pin to be validated                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the Pin is available or not.      **
**                                                                            **
**   Parameter: Port number of type uint8/uint16                              **
*******************************************************************************/
static _INLINE_ uint16 Dio_lIsPinAvailable(uint32 Port, uint8 Pin)
{
 uint16 RetVal;

 RetVal =  ( (uint16)((uint32)DIO_CHANNEL_BIT_MASK << (Pin)) &
              Dio_kMaskUndefinedPortPins[Port] );
 return RetVal;
}

#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON) */


/*******************************************************************************
** Syntax           : Dio_lGetPortNumber                                      **
**                    (                                                       **
**                      ChannelId                                             **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : ChannelId - derived the port number from ChannelId      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to identify the port number from the passed   **
**   ChannelId.                                                               **
*******************************************************************************/
Dio_PortType Dio_lGetPortNumber(Dio_ChannelType ChannelId)
{
  Dio_PortType RetVal;
  
  RetVal = (Dio_PortType)((ChannelId & 
                   (uint16)DIO_4_TO_11_MASK) >> (uint16)DIO_PORT_NUM_OFFSET
                  );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Dio_lGetPortAdr                                         **
**                    (                                                       **
**                      x                                                     **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : x - Port Number                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to extract the Address of Px_OUT              **
**   register, where x is variable. Note: x-PortNumber.                       **
*******************************************************************************/
Ifx_P *Dio_lGetPortAdr(Dio_PortType PortNumber)
{
  Ifx_P *RetVal;
  RetVal = ( ((Ifx_P * )(void *)&P00_OUT + 
             (((PortNumber / DIO_CONSTANT_10) * DIO_CONSTANT_16) + 
             (PortNumber % DIO_CONSTANT_10)))
           );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Dio_lGetPinNumber                                       **
**                    (                                                       **
**                      ChannelId                                             **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : ChannelId - derived the pin number from ChannelId       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to identify the pin number from the passed    **
**   ChannelId.                                                               **
*******************************************************************************/
uint8 Dio_lGetPinNumber(Dio_ChannelType ChannelId)
{
  uint8 RetVal;
  
  RetVal = (uint8)(ChannelId & (uint16)DIO_PIN_LOW4_MASK );
  return(RetVal);
}

/*Memory Map of the DIO Code*/
#define DIO_STOP_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

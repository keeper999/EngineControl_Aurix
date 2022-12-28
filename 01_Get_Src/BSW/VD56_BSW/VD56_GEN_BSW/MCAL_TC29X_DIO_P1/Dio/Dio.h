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
**  $FILENAME   : Dio.h $                                                    **
**                                                                           **
**  $CC VERSION : \main\40 $                                                 **
**                                                                           **
**  $DATE       : 2014-01-03 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file is the header for DIO driver                     **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*******************************************************************************
**  Traceabilty : [cover parentID=DS_AS_DIO140,DS_AS_DIO131,DS_NAS_DIO_PR912_3,
                   DS_AS40X_DIO001_PI,DS_AS40X_DIO065,
                   DS_AS40X_DIO073,DS_AS_DIO021,DS_AS_DIO022,DS_AS_DIO184,
                   DS_AS40X_DIO187,DS_AS40X_DIO164,DS_AS_DIO182,DS_AS_DIO015,
                   DS_AS_DIO183,DS_AS_DIO018,DS_AS_DIO185,DS_AS_DIO023,
                   DS_AS_DIO186,DS_AS_DIO024_DIO103,DS_NAS_DIO_PR746]        **
**                [/cover]                                                   **
******************************************************************************/

#ifndef DIO_H
#define DIO_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* DIO117: Inclusion structure */
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
/* Global functions like Set/Reset END INIT protection bit, 
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"

/* Inclusion of Tasking SFR file for inline functions */
#include "IfxPort_reg.h"

/* Pre-compile/static configuration parameters for DIO  */
#include "Dio_Cfg.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)
/* Import of DET functionality */
#include "Det.h"
#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */

#if (DIO_SAFETY_ENABLE == STD_ON)
#include "SafetyReport.h"
#endif

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* DIO Vendor ID */
#define DIO_VENDOR_ID                     (17U)  
/* DIO Module ID */
#define DIO_MODULE_ID                     (120U)

/* DIO083: DIO084: Direct Readback support of DIO driver.
  This driver while reading the output channel, reads the real channel
  level. */
#define DIO_READBACK_SUPPORT  (TRUE)

/*
  DIO065: Development error codes defined conditionally
*/

#if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))
/* Service is called with invalid parameter channel  */
#define DIO_E_PARAM_INVALID_CHANNEL_ID   ((uint8)0x0A)
/* Service is called with invalid parameter port  */
#define DIO_E_PARAM_INVALID_PORT_ID      ((uint8)0x14)

/* Service is called with invalid parameter group */
#define DIO_E_PARAM_INVALID_GROUP    ((uint8)0x1F)

/* Rename to common Macro name */
#define DIO_E_PARAM_L_INVALID_GROUP  DIO_E_PARAM_INVALID_GROUP

/* APIs other than Dio_Init() executed prior to calling Init function*/
/* DIO073: Additional errors */
#define DIO_E_UNINIT                 ((uint8)0xAA)


/* In the VariantPB selected mode, the parameter ConfigPtr is expected
not to be NULL pointer and hence PORT_E_PARAM_CONFIG DET is reported 
if service is called NULL_PTR*/
#define DIO_E_PARAM_CONFIG           ((uint8)0x10)
/* Service is called with NULL_PTR parameter */
#define DIO_E_PARAM_POINTER          ((uint8)0x20)

/* DIO073: No microcontroller specific DET for this driver */
/* DIO067: No production errors for DIO driver */

/*
  Service ID number for all DIO driver services 
*/
/* Service ID for Dio_ReadChannel */
#define DIO_SID_READCHANNEL          ((uint8)0)
/* Service ID for Dio_WriteChannel */
#define DIO_SID_WRITECHANNEL         ((uint8)1U)
/* Service ID for Dio_ReadPort */
#define DIO_SID_READPORT             ((uint8)2U)
/* Service ID for Dio_WritePort */
#define DIO_SID_WRITEPORT            ((uint8)3U)
/* Service ID for Dio_ReadChannelGroup */
#define DIO_SID_READCHANNELGROUP     ((uint8)4U)
/* Service ID for Dio_WriteChannelGroup */
#define DIO_SID_WRITECHANNELGROUP    ((uint8)5U)
/* Service ID for Dio_GetVersionInfo */
#define DIO_SID_GETVERSIONINFO       ((uint8)18U)

#define DIO_SID_INIT                 ((uint8)16U)

#if( DIO_FLIP_CHANNEL_API == STD_ON )
 /* Service ID for Dio_FlipChannel */
#define DIO_SID_FLIPCHANNEL          ((uint8)17U)
#endif /* DIO_FLIP_CHANNEL_API == STD_ON */

/* Error ststus values */
#define DIO_NO_ERROR                 (1U)
#define DIO_ERROR                    (0U)

#if (DIO_SAFETY_ENABLE == STD_ON)

/* Shift value for the ModuleID used in Marker check value */
#define DIO_MODULEID_SHIFT_VAL       (16U)

/* Error ID reported, wrt Range check failure for Pin Level */
#define DIO_E_PARAM_INVALID_LEVEL    ((uint8)0x21)

#endif /*(DIO_SAFETY_ENABLE == STD_ON) */

#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) || ((DIO_SAFETY_ENABLE == STD_ON))*/

/* DIO MODULE INSTANCE ID */
#define DIO_INSTANCE_ID              ((uint8)0)

/*Macros to inform the Dio port is configured or not*/
#define DIO_PORT_NOT_CONFIGURED      ((uint8)0)
#define DIO_PORT_CONFIGURED          ((uint8)1U)

/* This is the reset bit set for Pn_Omr register*/
#define DIO_OMR_RESET_BIT            (0x10000U)

/* Mask to get direction info from Pin control value */
#define DIO_PORT_DIR_MSK             (0x80U)

/*  Port pin input dirction value */
#define DIO_PORT_PIN_IN       ((uint16)((uint16)(DIO_PORT_PC_DIR_IN)   << \
                                                (DIO_PORT_IOCR_PC_POS))   \
                              )

/* Pad Direction Control */
#define DIO_PORT_PC_DIR_IN           ((uint16)(0x0000))
/*  Position of the bit field Pn_IOCR.PC */
#define DIO_PORT_IOCR_PC_POS         ((uint16)(4U))

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/* Type definition for register mapping of DIO hardware */
/* 
  This is a normal structure named as Dio_RegType, this depicts the port 
  registers 
  */

/* Type definition for channel level */
/* DIO089: Possible values for Dio_LevelType are STD_HIGH and STD_LOW */
/* DIO23: Possible levels of DIO channels are STD_HIGH and STD_LOW, these are 
   defined in Std_Types.h */
typedef uint8   Dio_LevelType;

/* DIO015: Type definition for numeric id for all configured channels */
/* DIO017: User of DIO drive shall use the symbolic names provided by
   configuration description */
/* DIO052: A general purpose digital IO pin represents a DIO channel */
typedef uint16  Dio_ChannelType;

/* DIO018: Type definition for numeric id for all configured ports */
/* DIO020: User of DIO drive shall use the symbolic names provided by
   configuration description */
/* DIO053: Hardware groups several DIO channels to represent a DIO port */
typedef uint8   Dio_PortType;

/* DIO24: DIO103: Type definition for the port level */
typedef uint16  Dio_PortLevelType;

/* DIO021: DIO056: Type definition for channel group configuration */
/* DIO022: User of DIO drive shall use the symbolic names provided by
   configuration description */
typedef struct Dio_ChannelGroupType
{
  /* Mask that defines the channels that forms this group */
  Dio_PortLevelType   mask;
  /* Offset of LSB of channel group from LSB of port */
  uint8               offset;
  /* Port number, wherein this channel group belongs to */
  Dio_PortType        port;  
} Dio_ChannelGroupType;

typedef struct Dio_PortChannelIdType
{
  /* Dio port is configured or not */
  uint32 Dio_PortIdConfig;
  /* configured channel info */
  uint32 Dio_ChannelConfig;
}Dio_PortChannelIdType;

typedef struct Dio_ConfigType
{
  #if(DIO_SAFETY_ENABLE == STD_ON)
  uint32 Dio_MarkerCheckValue;
  #endif /* DIO_SAFETY_ENABLE == STD_ON */
  /* Pointer to Dio port and channel configuration */
  const Dio_PortChannelIdType* Dio_PortChannelConfigPtr;
  /* Pointer to Dio channel group configuration */
  const Dio_ChannelGroupType* Dio_ChannelGroupConfigPtr;
  /* number of groups configured for the configuration */
  uint32 Dio_ChannelGroupConfigSize;
}Dio_ConfigType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/* Declaration of Dio Post Build Configuration */

#define DIO_START_SEC_POSTBUILDCFG
#include "MemMap.h"

extern const struct Dio_ConfigType Dio_ConfigRoot[];

#define DIO_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

#if (DIO_LOADABLE_USED == STD_ON)
/* In Case of loadable, the Config Ptr is exposed so as 
    to access the ChannelGroup symbolic name*/
extern const struct Dio_ConfigType *Dio_kConfigPtr;
#endif /*DIO_LOADABLE_USED == STD_ON*/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#define DIO_START_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

/*******************************************************************************
** Syntax           : void Dio_Init                                           **
**                    (                                                       **
**                      const Dio_ConfigType * const ConfigPtr                **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x10                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to DIO configuration                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - DIO166: Initializes all global variables of the Dio module             **
*******************************************************************************/
extern void Dio_Init 
( 
  const Dio_ConfigType *ConfigPtr 
);

#if (DIO_INITCHECK_API == STD_ON)
/*******************************************************************************
** Traceability     : [cover parentID=]                                       **
**                                                                            **
** Syntax           : Std_ReturnType Dio_InitCheck                            **
**                    (                                                       **
**                      const Dio_ConfigType * ConfigPtr                      **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x10                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to DIO configuration                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      : This function verifies the initialization               **
**                    done by Dio_Init                                        **
*******************************************************************************/
extern Std_ReturnType Dio_InitCheck
(
  const Dio_ConfigType *ConfigPtr
);
#else
#define Dio_InitCheck(ConfigPtr)  ERROR_Dio_InitCheck_NOT_SELECTED
#endif /* (DIO_INITCHECK_API == STD_ON) */

/*******************************************************************************
** Syntax           : Dio_LevelType Dio_ReadChannel                           **
**                    (                                                       **
**                      Dio_ChannelType ChannelId                             **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ChannelId - Channel whose level is to be read           **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Dio_LevelType                                           **
**                    STD_HIGH: The pin level is high                         **
**                    STD_LOW : The pin level is low                          **
**                    0       : Development error has occured                 **
**                                                                            **
** Description      :                                                         **
** - The level of a single DIO and ESR channel is read with this service      **
** - This service returns the value of the specified DIO and ESR channel,     **
**   i.e, STD_HIGH or STD_LOW. If development errors are enabled and an error **
**   ocurred, this service will return with the value '0'.                    **
** - This service works on both input and output channels                     **
** - For reading the value of the output channel, this service reads the pin  **
**   level contained in Pn_IN register, i.e., direct read back of the pin     **
**                                                                            **
*******************************************************************************/
extern Dio_LevelType Dio_ReadChannel
(
  Dio_ChannelType ChannelId
);

/*******************************************************************************
** Syntax           : void Dio_WriteChannel                                   **
**                    (                                                       **
**                      Dio_ChannelType  ChannelId                            **
**                      Dio_LevelType    Level                                **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ChannelId - Channel whose level is to be read           **
**                    Level     - The level to be set on the channel          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :                                                         **
** - This service is to modify the levels of output channels                  **
** - Read-modify-write sequences are not interruptible in this service        **
** - The level of a single DIO and ESR channel shall be set by this service   **
**   to STD_HIGH or STD_LOW                                                   **
** - This service works on both input and output channels.                    **
** - If the specified channel is configured as an output channel,             **
**   this API shall set the specified Level for the specified channel.        **
** - If the specified channel is configured as an input channel, this API     **
**   shall have no influence on the physical output.                          **
** - If the specified channel is configured as an input channel, this API     **
**   shall have no influence on the result of the next Read-Service.          **
** - The output data latch of an input channel can be set/cleared using this  **
**   API, so that the required level is output from the pin when the port     **
**   driver configures the pin as a DIO/ESR output pin.                       **
** - If DET is enabled and development error occurs the API functionality is  **
**   skipped                                                                  **
**                                                                            **
*******************************************************************************/
extern void Dio_WriteChannel
(
  Dio_ChannelType ChannelId,
  Dio_LevelType Level
);

/* Enable / Disable the use of the function */
#if (DIO_FLIP_CHANNEL_API == STD_ON)
/*******************************************************************************
** Syntax           : Dio_LevelType Dio_FlipChannel                           **
**                    (                                                       **
**                      Dio_ChannelType ChannelId                             **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x11                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ChannelId - ChannelId whose level to be inverted        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Dio_LevelType - The function returns value or the level **
**                  of the specified channel which is of type Dio_LevelType   **
**                                                                            **
** Description      : This function: Flip the channel level                   **
**      - DIO191: returns the inverted level of specified output channel      **
**      - DIO192: The specified channel is input, API shall have no influence **
**                           on the physical output of the channel            **
**      - DIO193: The specified channel is input, API shall have no influence **
**                      on the result of next Read service                    **
*******************************************************************************/
extern Dio_LevelType Dio_FlipChannel
(
  Dio_ChannelType ChannelId
);
#else
#define Dio_FlipChannel(ChannelId)  ERROR_Dio_FlipChannel_NOT_SELECTED
#endif /* #if (DIO_FLIP_CHANNEL_API == STD_ON) */

/*******************************************************************************
** Syntax           : Dio_PortLevelType Dio_ReadPort                          **
**                    (                                                       **
**                      Dio_PortType PortId                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : PortId - Port id whose level to be read                 **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Dio_PortLevelType                                       **
**                                                                            **
** Description      :                                                         **
** - This service reads the levels of all channels of one port and returns    **
**   this value to the calling function. A bit value '0' indicates the        **
**   corresponding channel to physical STD_LOW and  a bit value '1' indicates **
**   the corresponding channel to physical STD_HIGH.                          **
** - When reading a port which is smaller than the Dio_PortType the bits      **
**   corresponding to undefined port pins are returned as 0.                  **
** - If development errors are enabled and an error ocurred this API will     **
**   return with the value '0'.                                               **
** - This service works on both input and output channels                     **
** - For reading the level of the output pins of a port, this service reads   **
**   the pin level contained in Pn_IN register, i.e., direct read back of the **
**   pin is done.                                                             **
**                                                                            **
*******************************************************************************/
extern Dio_PortLevelType Dio_ReadPort
(
  Dio_PortType PortId
);

/*******************************************************************************
** Syntax           : void Dio_WritePort                                      **
**                    (                                                       **
**                      Dio_PortType PortId                                   **
**                      Dio_PortLevelType Level                               **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : PortId - Port id. whose level to be set                 **
**                    Level  - The level to be set on the port                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :                                                         **
** - This service is to modify the levels of output pins of the specified port**
** - All the port pins are written simultaneously. Value '0' corresponds to   **
**   STD_LOW and '1' corresponds to STD_HIGH                                  **
** - When writing a port which is smaller than the Dio_PortType the MSB shall **
**   be ignored.                                                              **
** - Read-modify-write sequences are not interruptible in this service        **
** - This service works on both input and output channels.                    **
** - This service will not affect the functionality of the input pins in the  **
**   port                                                                     **
** - The output data latch of an input channel can be set/cleared using this  **
**   API, so that the required level is output from the pin when the port     **
**   driver configures the pin as a DIO output pin.                           **
** - If DET is enabled and development error occurs the API functionality is  **
**   skipped                                                                  **
**                                                                            **
*******************************************************************************/
extern void Dio_WritePort
(
  Dio_PortType PortId,
  Dio_PortLevelType Level
);
/*******************************************************************************
** Syntax           : Dio_PortLevelType Dio_ReadChannelGroup                  **
**                    (                                                       **
**                      const Dio_ChannelGroupType *ChannelGroupIdPtr         **
**                    )                                                       **
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
** Return value     : Dio_PortLevelType - The function returns value or the   **
**                    level of the specified channel group which is of type   **
**                    Dio_PortLevelType                                       **
**                                                                            **
** Description      : This function:                                          **
**  - DIO014: DIO037: returns the level of specified channel group            **
**                                                                            **
*******************************************************************************/
extern Dio_PortLevelType Dio_ReadChannelGroup
(
  const Dio_ChannelGroupType *ChannelGroupIdPtr
);



/*******************************************************************************
** Syntax           : void Dio_WriteChannelGroup                              **
**                    (                                                       **
**                      const Dio_ChannelGroupType *ChannelGroupIdPtr,        **
**                      Dio_PortLevelType Level                               **
**                    )                                                       **
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
extern void Dio_WriteChannelGroup
(
  const Dio_ChannelGroupType *ChannelGroupIdPtr,
  Dio_PortLevelType Level
);

/*******************************************************************************
** Traceabilty      : [cover parentID=DS_AS_DIO139,DS_AS_DIO123,DS_AS_DIO124,
                       DS_AS_DIO126,DS_AS_DIO188_DIO189]                      **
**                                                                            **
** Syntax           : void Dio_GetVersionInfo                                 **
**                    (                                                       **
**                      Std_VersionInfoType *versioninfo                      **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x12                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : versioninfo - Pointer to where to store the             **
**                    version information of this module.                     **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - DIO123: This function returns the version information of this module   **
**     The version information include : Module ID, Vendor ID,                **
**     Vendor specific version numbers                                        **
**   - DIO124: This function is available if the DIO_GET_VERSION_INFO_API     **
**     is set ON                                                              **
**                                                                            **
*******************************************************************************/
#if ( (DIO_VERSION_INFO_API == STD_ON) && (DIO_DEV_ERROR_DETECT == STD_ON) )
#define Dio_GetVersionInfo(VersionInfoPtr)                                     \
{                                                                              \
    /* Check for DET: DIO_E_PARAM_POINTER */                                   \
    if ((VersionInfoPtr) == NULL_PTR)                                          \
    {                                                                          \
        /* Report DIO_E_PARAM_POINTER DET if service called with               \
             NULL_PTR                                                          \
        */                                                                     \
        Det_ReportError(                                                       \
            (uint16)DIO_MODULE_ID,                                             \
            DIO_INSTANCE_ID,                                                   \
            DIO_SID_GETVERSIONINFO,                                            \
            DIO_E_PARAM_POINTER);                                              \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        /* Vendor ID information */                                            \
        ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = DIO_VENDOR_ID;    \
        /*DIO module ID information */                                         \
        ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = DIO_MODULE_ID;    \
        /*DIO Instance ID information */                                       \
        /* DIO module Software major version information */                    \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =           \
                                           (uint8)DIO_SW_MAJOR_VERSION;        \
        /* DIO module Software minor version information */                    \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =           \
                                           (uint8)DIO_SW_MINOR_VERSION;        \
        /* DIO module Software patch version information */                    \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =           \
                                           (uint8)DIO_SW_PATCH_VERSION;        \
    }                                                                          \
}
#elif ( (DIO_VERSION_INFO_API == STD_ON) && (DIO_DEV_ERROR_DETECT == STD_OFF) )
#define Dio_GetVersionInfo(VersionInfoPtr)                                     \
{                                                                              \
    /* Vendor ID information */                                                \
    ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = DIO_VENDOR_ID;        \
    /*DIO module ID information */                                             \
    ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = DIO_MODULE_ID;        \
    /*DIO Instance ID information */                                           \
    /* DIO module Software major version information */                        \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =               \
                                       (uint8)DIO_SW_MAJOR_VERSION;            \
    /* DIO module Software minor version information */                        \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =               \
                                       (uint8)DIO_SW_MINOR_VERSION;            \
    /* DIO module Software patch version information */                        \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =               \
                                       (uint8)DIO_SW_PATCH_VERSION;            \
}
#else
#define Dio_GetVersionInfo(VersionInfoPtr)                                     \
                                      ERROR_Dio_VersionInfo_NOT_SELECTED
#endif /* #if (DIO_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#define DIO_STOP_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

#endif /* DIO_H */

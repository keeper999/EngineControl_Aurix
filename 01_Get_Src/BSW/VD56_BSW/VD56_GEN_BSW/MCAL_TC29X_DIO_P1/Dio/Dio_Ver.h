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
**  $FILENAME   : Dio_Ver.h $                                                **
**                                                                           **
**  $CC VERSION : \main\3 $                                                  **
**                                                                           **
**  $DATE       : 2013-08-26 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file is the header for DIO driver                     **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef DIO_VER_H
#define DIO_VER_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
/* DIO117: Inclusion structure */
#include "Dio.h"


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define DIO_CONSTANT_10       (10U)
#define DIO_CONSTANT_16       (16U)

/* lower 4 bit mask value */
#define DIO_PIN_LOW4_MASK     (0x0FU)

/* Bit 4 to 11 Mask value */
#define DIO_4_TO_11_MASK      (0x0FF0U)

#if (DIO_DEV_ERROR_DETECT == STD_ON)
/* Status macro for initialization */
#define DIO_INITIALIZED            (1U)
#define DIO_NOT_INITIALIZED        (0U)
#endif /*(DIO_DEV_ERROR_DETECT == STD_ON) */

/* Port Number offset */
#define DIO_PORT_NUM_OFFSET   (4U)

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

#if (DIO_LOADABLE_USED == STD_OFF)
  #if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))
    #if(DIO_PB_FIXED_ADDRESS == STD_ON)
      #define DIO_START_SEC_CONST_32BIT
      #include "MemMap.h"
      
      /* To store the Dio driver configuration pointer */
      extern const Dio_ConfigType * const Dio_kConfigPtr;
      
      #define DIO_STOP_SEC_CONST_32BIT
      #include "MemMap.h"
    #else
      #define DIO_START_SEC_VAR_32BIT
      #include "MemMap.h"
      
      /* To store the Dio driver configuration pointer */
      extern const Dio_ConfigType *Dio_kConfigPtr;
      
      #define DIO_STOP_SEC_VAR_32BIT
      #include "MemMap.h"
    #endif /* DIO_PB_FIXED_ADDRESS == STD_ON */
  #endif /* DIO_DEV_ERROR_DETECT == STD_ON || DIO_SAFETY_ENABLE == STD_ON*/
#endif /* DIO_LOADABLE_USED == STD_OFF */

/*******************************************************************************
**                      Global Function prototype                             **
*******************************************************************************/

#define DIO_START_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

#if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))

/* This function checks ChannelId for DET error 
    DIO_E_PARAM_INVALID_CHANNEL_ID */
extern uint8 Dio_lCheckChannelId(uint8 ApiId, Dio_ChannelType ChannelId);

/* This function checks ChannelGroupId for DET error */
extern uint8 Dio_lCheckGroupId(uint8 ApiId, 
                                const Dio_ChannelGroupType *GroupIdPtr);

/* This function checks ChannelId for DET error 
    DIO_E_PARAM_INVALID_PORT_ID */
extern uint8 Dio_lCheckPortId (uint8 ApiId, Dio_PortType PortId);

/* Returns the validity of ChannelGroupID */
extern uint8 Dio_lErrorCheckChannelGroupDet(
   const Dio_ChannelGroupType *ChannelGroupIdPtr,
   uint8 ApiId
);

/* Returns the validity of ChannelID */
extern uint8 Dio_lErrorCheckChannelDet(
   Dio_ChannelType ChannelId,
   uint8 ApiId
);

/* Returns the validity of PortID */
extern uint8 Dio_lErrorCheckPortDet(Dio_PortType PortId, uint8 ApiId);

#endif /* DIO_DEV_ERROR_DETECT == STD_ON || DIO_SAFETY_ENABLE == STD_ON*/

/* The function like macro is to extract the port number from the passed
   ChannelId */
extern Dio_PortType Dio_lGetPortNumber(Dio_ChannelType ChannelId);

/* The function like macro is to extract the Address of Px_OUT */
extern Ifx_P *Dio_lGetPortAdr(Dio_PortType PortNumber);

/* The function like macro is to identify the pin number from the passed
   ChannelId */
extern uint8 Dio_lGetPinNumber(Dio_ChannelType ChannelId);

#define DIO_STOP_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#define DIO_START_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

#if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))

/*******************************************************************************
** Syntax           : Dio_lCheckAnalogChannel                                 **
**                    (                                                       **
**                      uint8 ApiId, uint32 PortReadOnly                      **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : ApiId - Service ID                                      **
**                    PortReadOnly - Flag to represent Analog PortPins        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - This function returns status for Read/Write Called on Analog Ports       **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint8 Dio_lCheckAnalogChannel(uint8 ApiId, uint32 PortReadOnly)
{
   uint8 ErrStatus;
   ErrStatus = (uint8)DIO_NO_ERROR;
   
   #if( DIO_FLIP_CHANNEL_API == STD_ON )
   if( ( (ApiId == DIO_SID_WRITECHANNEL) || 
         (ApiId == DIO_SID_FLIPCHANNEL) 
       ) &&  (PortReadOnly != 0U)
     )
     { 
       /* Error status = Error has occurred */
       ErrStatus = (uint8)DIO_ERROR;
     } 
   #else
   if( (ApiId == DIO_SID_WRITECHANNEL) &&  (PortReadOnly != 0U) )
   {
     /* Error status = Error has occurred */
     ErrStatus = (uint8)DIO_ERROR;
   }
   #endif
   return ErrStatus;
}

/*******************************************************************************
** Syntax           : Dio_lCheckAnalogPort                                    **
**                    (                                                       **
**                      uint8 ApiId, uint32 PortReadOnly                      **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : ApiId - Service ID                                      **
**                    PortReadOnly - Flag to represent Analog PortPins        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - This function returns status for Read/Write Called on Analog Ports       **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint8 Dio_lCheckAnalogPort(uint8 ApiId, uint32 PortReadOnly)
{
   uint8 ErrStatus;
   ErrStatus = (uint8)DIO_NO_ERROR;

   if( (ApiId == DIO_SID_WRITEPORT) &&  (PortReadOnly != 0U) )
   {
     /* Error status = Error has occurred */
     ErrStatus = (uint8)DIO_ERROR;
   }
   return ErrStatus;
}

#endif /*(DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON)*/

#define DIO_STOP_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

#endif /* DIO_VER_H */

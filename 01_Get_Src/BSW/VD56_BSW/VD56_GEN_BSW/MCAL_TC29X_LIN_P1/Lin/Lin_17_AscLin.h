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
**  $FILENAME   : Lin_17_AscLin.h $                                          **
**                                                                           **
**  $CC VERSION : \main\31 $                                                 **
**                                                                           **
**  $DATE       : 2013-06-21 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file exports                                  **
**                 - functionality of Lin driver.                            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
    TRACEABILITY : [cover parentID=DS_NAS_PR643] 
    [/cover]                      
**                                                                            **
*******************************************************************************/

#ifndef LIN_17_ASCLIN_H
#define LIN_17_ASCLIN_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/* Inclusion of Mcal Specific Global Header File */
#include "Mcal.h"

/* Inclusion EcuM_Cbk.h to notify the ECU State Manager on wake up validation*/
#include "EcuM_Cbk.h"

#include "Lin_GeneralTypes.h"  

/* Pre-compile/static configuration parameters for LIN                        */
#include "Lin_17_AscLin_Cfg.h"  

/* Conditional Inclusion of Development Error Tracer File */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Vendor ID */
#define LIN_17_ASCLIN_VENDOR_ID  (17U)

/* LIN Module ID 63 */
#define LIN_17_ASCLIN_MODULE_ID  (82U)

/* LIN Instance ID */
#define LIN_17_ASCLIN_INSTANCE_ID  (LIN_INDEX)

/*
   The Macro LIN_PB_FIXEDADDR is selected to OFF, if fixed address feature
   not selected 
*/
#ifndef LIN_PB_FIXEDADDR
#define LIN_PB_FIXEDADDR    (STD_OFF)
#endif

#if (LIN_DEV_ERROR_DETECT == STD_ON)
/*
  Development error values
*/
/* [cover parentID=DS_AS403_LIN048, DS_AS_LIN047,] */
/* [/cover] */

/* [cover parentID=DS_AS403_LIN214] */
  /* API service used without module initialization */
#define LIN_E_UNINIT            ((uint8)0x00)
/* [/cover] */
 
/* API service used without channel initialization */
#define LIN_E_CHANNEL_UNINIT    ((uint8)0x01)

/* [cover parentID=DS_AS403_LIN215] */
/* API service used with an invalid channel Identifier */
#define LIN_E_INVALID_CHANNEL    ((uint8)0x02)
/* [/cover] */

/* [cover parentID=DS_AS403_LIN216] */
/* API service used with an invalid pointer */
#define LIN_E_INVALID_POINTER   ((uint8)0x03)
/* [/cover] */

/* [cover parentID=DS_AS403_LIN213] */
/* API service used with an invalid state transition */
#define LIN_E_STATE_TRANSITION  ((uint8)0x04)
/* [/cover] */

/* [cover parentID=DS_AS403_LIN249] */
/*API Service called with NULL parameter.*/
#define LIN_E_PARAM_POINTER ((uint8)0x05)
/* [/cover] */

/* 
  API Service ID's
*/
/* API Service ID for Lin_17_AscLin_Init() */
#define LIN_SID_INIT                  ((uint8)0)

/* API Service ID for Lin_GetVersionInfo() */
#define LIN_SID_VERINFO          ((uint8)1)

/* API Service ID for Lin_SendFrame() */
#define LIN_SID_SENDFRAME         ((uint8)4)

/* API Service ID for Lin_17_AscLin_GoToSleep() */
#define LIN_SID_GOTOSLEEP            ((uint8)6)

/* API Service ID for Lin_WakeUp() */
#define LIN_SID_WAKEUP               ((uint8)7)

/* API Service ID for Lin_17_AscLin_GetStatus() */
#define LIN_SID_GETSTATUS            ((uint8)8)

/* API Service ID for Lin_17_AscLin_GoToSleepInternal() */
#define LIN_SID_GOTOSLEEPINTERNAL    ((uint8)9)

/* API Service ID for Lin_17_AscLin_CheckWakeup() */
#define LIN_SID_CHECKWAKEUP     ((uint8)10)
  
#endif /* (LIN_DEV_ERROR_DETECT == ON) */

/* LIN module instance ID to be used in Det_ReportError*/
#define LIN_MODULE_INSTANCE          ((uint8)LIN_17_ASCLIN_INSTANCE_ID)

/* LIN Buffer Size */
#define LIN_RESP_BUF_SIZE            (9U)

/* Macro's to check the wake is enabled by channel */
#define LIN_CHANNEL_WAKEUP_ENABLED (1U)
#define LIN_CHANNEL_WAKEUP_DISABLED (0U)

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_LIN161, DS_AS403_LIN001, DS_AS_LIN110, 
DS_AS403_LIN248_LIN237]
** Syntax           : void  Lin_17_AscLin_GetVersionInfo                      **
**                    (                                                       **
**                      Std_VersionInfoType *VersionInfoPtr                   **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x09                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : versioninfo - Pointer to where to store the             **
**                    version information of this module.                     **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - This function returns the version information of the module    **
*******************************************************************************/
#if (LIN_VERSION_INFO_API == STD_ON)\
  && (LIN_DEV_ERROR_DETECT == STD_ON)
#define Lin_17_AscLin_GetVersionInfo(VersionInfoPtr)                      \
{                                                                         \
  if ((VersionInfoPtr) == NULL_PTR)                                       \
  {                                                                       \
    /* Report to DET */                                                   \
    Det_ReportError(                                                      \
                     (uint16)LIN_17_ASCLIN_MODULE_ID,                     \
                     LIN_MODULE_INSTANCE,                                 \
                     LIN_SID_VERINFO,                                     \
                     LIN_E_PARAM_POINTER                                  \
                   );                                                     \
  }                                                                       \
  else                                                                    \
  {                                                                       \
  /* LIN Module ID */                                                     \
  ((Std_VersionInfoType*)(VersionInfoPtr))-> moduleID =                   \
                                                LIN_17_ASCLIN_MODULE_ID;  \
  /* LIN vendor ID */                                                     \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID =                    \
                                                  LIN_17_ASCLIN_VENDOR_ID;\
  /* major version of LIN */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =            \
                               (uint8)LIN_17_ASCLIN_SW_MAJOR_VERSION;         \
  /* minor version of LIN */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =            \
                               (uint8)LIN_17_ASCLIN_SW_MINOR_VERSION;         \
  /* patch version of LIN */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =            \
                               (uint8)LIN_17_ASCLIN_SW_PATCH_VERSION;          \
  }                                                                       \
}
#elif (LIN_VERSION_INFO_API == STD_ON) && (LIN_DEV_ERROR_DETECT == STD_OFF)
#define Lin_17_AscLin_GetVersionInfo(VersionInfoPtr)                           \
{                                                                         \
  /* Note that versioninfo pointer is not checked for NULL as the user is \
     supposed to send the memory allocated pointer */                     \
  /* LIN Module ID */                                                     \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID =                    \
                                                LIN_17_ASCLIN_MODULE_ID;  \
  /* LIN vendor ID */                                                     \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID =                    \
                                                LIN_17_ASCLIN_VENDOR_ID;  \
  /* major version of LIN */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =            \
                               (uint8)LIN_17_ASCLIN_SW_MAJOR_VERSION;         \
  /* minor version of LIN */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =            \
                               (uint8)LIN_17_ASCLIN_SW_MINOR_VERSION;          \
  /* patch version of LIN */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =            \
                               (uint8)LIN_17_ASCLIN_SW_PATCH_VERSION;          \
}/* end of Lin_17_AscLin_GetVersionInfo() */  
#else
#define Lin_17_AscLin_GetVersionInfo(VersionInfo)                         \
                                     ERROR_Lin_GetVersionInfo_NOT_SELECTED
#endif                               
/* [/cover] */

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* [cover parentID=DS_AS403_LIN013_3] */
/*
  This sturcture defines the channel timing parameters 
*/
typedef struct Lin_ChannelTimingConfigType
{
  /* BRG.NUMERATOR value  */
  uint16 HwBrgNumerator;
  /* BRG.DENOMINATOR value  */
  uint16 HwBrgDenominator;
  /* BITCON.PRESCALAR value  */
  uint16 HwBitconPrescalar;
  /* This is the delay inserted between transmission of bytes and also 
  the delay between the header and the response. 
                                             Delay is in terms of bit times  */
  uint8 InterByteResponseSpace;
  /* Iocr Depth for wakeup detection */
  uint8 HwWakeupIocrDepth;
  /* Prescalar for Wakeup detection */
  uint16 HwWakeupBitconPrescalar;
}Lin_ChannelTimingConfigType;
/* [/cover] */

/* [cover parentID=DS_AS403_LIN013_2] */
/*
Type: Lin_17_AscLin_ChannelType
This is the type of the external data structure containing the overall 
initialization data for one LIN Channel.   
*/
typedef struct Lin_17_AscLin_ChannelType 
{
  /* Specifies the channel timing*/
  Lin_ChannelTimingConfigType TimingConfig;
  /* Identifies the wake up source id */
  EcuM_WakeupSourceType WakeupSourceId;   
    /* Identifies the the ASCLINx */
  uint8 HwModule;
  /* Identifies the Lin channel support wake up */
  uint8 Wakeup;
  /* Wakeup value to be programmed for wakeup generation (250us to 5ms) */
  uint8 HwWakeupVal;
  /*Rx alternate pin selection*/
  uint8 RxAlternatePinSelect;
  /* Logical Channel ID given by the user */
  uint8 LogicalChannelId;
}Lin_17_AscLin_ChannelType;
/* [/cover] */

/*
Type: Lin_17_AscLin_ConfigType
*/
/* [cover parentID=DS_AS403_LIN013_1, DS_AS403_LIN247,DS_AS_LIN227,] */
typedef struct Lin_17_AscLin_ConfigType 
{
  /* Ptr to LIN Channel Config */    
  const Lin_17_AscLin_ChannelType *ChannelConfigPtr;
  /* No of channels Configured */      
  uint8        NoOfChannels;

}Lin_17_AscLin_ConfigType;
/* [/cover] */

/* [cover parentID=DS_AS403_LIN186, DS_AS403_LIN187_LIN188 , DS_AS403_LIN189] */
#if (LIN_DEBUG_SUPPORT == STD_ON)
typedef enum
{
  LIN_CH_UNINIT_I,
  LIN_CH_INIT_I,
  LIN_SEND_HEADER_I,
  LIN_SEND_RESPONSE_I,
  LIN_MASTER_TX_COMPLETE_I,
  LIN_RECEIVE_RESPONSE_I,
  LIN_RECEIVE_COMPLETE_I,
  LIN_WAKEUP_WAIT_I,
  LIN_TX_HEADER_ERROR_I,
  LIN_TX_ERROR_I,
  LIN_RX_ERROR_I,
  LIN_TX_HEADER_TIMEOUT_ERROR_I,
  LIN_RESPONSE_TIMEOUT_ERROR_I
}Lin_IntStatusType;

/* 
Lin_17_AscLin_ChannelInfoType: This structure is used for storing internal LIN
                     channel status and other information.
*/
typedef struct
{
   Lin_IntStatusType   State;    /* Current internal state of LIN driver */
   uint8   Sleep;    /* Sleep requested/not requested */
   Lin_FrameCsModelType   Cs;       /* Checksum type */
   uint8   Dl;       /* Data length of the sdu */
   Lin_FramePidType   Pid;      /* Pid of the Pdu being serviced */
   Lin_FrameResponseType   Drc;      /* Response type fo the Pdu */
} Lin_17_AscLin_ChannelInfoType;
#endif /*(LIN_DEBUG_MODE == ON)*/
/* [/cover] */


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define LIN_17_ASCLIN_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* Declaration of Lin Post Build Configuration */
extern const Lin_17_AscLin_ConfigType Lin_ConfigRoot[];
#define LIN_17_ASCLIN_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
** Syntax : void Lin_17_AscLin_Init( const Lin_17_AscLin_ConfigType* Config ) **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  Config - Pointer to LIN driver configuration set        **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module Initialization function.                       **
** Service for LIN initialization. The Initialization function shall          **
** initialize all common relevant registers of Lin channels with the values   **
** of the structure referenced by the parameter ConfigPtr.                    **
*******************************************************************************/
extern void Lin_17_AscLin_Init(const Lin_17_AscLin_ConfigType* ConfigPtr);

/*******************************************************************************
** Syntax : void Lin_17_AscLin_WakeupValidation(void)                         **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
** Description : Service to identifiy the Lin channel after a wake up is      **
** caused by LIN bus transceiver                                              **
*******************************************************************************/
#if ((LIN_17_ASCLIN_AR_RELEASE_MAJOR_VERSION >= 4) && \
      (LIN_17_ASCLIN_AR_RELEASE_MINOR_VERSION >= 0) && \
     (LIN_17_ASCLIN_AR_RELEASE_REVISION_VERSION <= 2))     
extern void Lin_17_AscLin_WakeupValidation(void);
#else
extern Std_ReturnType Lin_17_AscLin_CheckWakeup(uint8 Channel);
#endif

/*******************************************************************************
** Syntax : Std_ReturnType Lin_17_AscLin_SendFrame                            **
**  (                                                                         **
**    uint8 Channel,                                                          **
**    const Lin_PduType* PduInfoPtr                                           **
**  )                                                                         **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in): Channel - LIN channel to be addressed .                   **
**                  PduInfoPtr - Pointer to PDU containing the PID, Checksum  **
**                  model, Response type, Dl and SDU data pointer             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - send command has been accepted.                   **
**                   E_NOT_OK - send command has not been accepted, 
**                              development or production error occurred.     **
**                                                                            **
** Description : Service to send a Lin header and send/recv response.         **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Lin_17_AscLin_SendFrame
(
  uint8 Channel,
  Lin_PduType* PduInfoPtr
);

/*******************************************************************************
** Syntax : Std_ReturnType Lin_17_AscLin_GoToSleep(uint8 Channel)             **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non Reentrant                                                 **
**                                                                            **
** Parameters (in) : Channel - LIN channel to be addressed                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: Sleep command has been accepted                    **
**                   E_NOT_OK: Sleep command has not been accepted,           **
**                   development or production error occurred                 **
**                                                                            **
** Description : The service instructs the driver to transmit a 
**               go-to-sleep-command on the addressed LIN channel             **
**                                                                            **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Lin_17_AscLin_GoToSleep(uint8 Channel);

/*******************************************************************************
** Syntax : Std_ReturnType Lin_17_AscLin_GoToSleepInternal(uint8 Channel)     **
**                                                                            **
** Service ID:  0x09                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Reentrant                                                 **
**                                                                            **
** Parameters (in) : Channel - LIN channel to be addressed .                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: Command has been accepted.                         **
**                   E_NOT_OK: Command has not been accepted, development     **
**                   or production error occurred                             **
**                                                                            **
** Description : Sets the channel state to LIN_CH_SLEEP                       **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Lin_17_AscLin_GoToSleepInternal(uint8 Channel);

/*******************************************************************************
** Syntax           : Std_ReturnType Lin_17_AscLin_Wakeup(uint8 Channel)      **
**                                                                            **
** Service ID       : 0x07                                                    **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : Channel - LIN channel to be addressed                   **
**                                                                            **
** Return value     : E_OK: Wake-up request has been accepted                 **
**                    E_NOT_OK: Wake-up request has not been accepted,        **
**                    development or production error occurred                **
**                                                                            **
** Description      : This service Generates a wake up pulse                  **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Lin_17_AscLin_Wakeup(uint8 Channel);

/*******************************************************************************
** Syntax : Lin_StatusType Lin_17_AscLin_GetStatus                            **
**                                        (uint8 Channel, uint8 **LinSduPtr)  **
**                                                                            **
** Service ID:      0x08                                                      **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      non reentrant                                             **
**                                                                            **
** Parameters (in): Channel    : LIN channel to be addressed                  **
**                                                                            **
** Parameters (out):LinSduPtr : Reference to a shadow buffer or memory mapped **
**                               LIN Hardware receive buffer where the current**
**                               SDU is stored                                **
**                                                                            **
** Return value:    LIN_NOT_OK  : Development or Production error occurred    **
**                  LIN_TX_OK   : Successful transmission                     **
**                  LIN_TX_BUSY : Ongoing Transmission (Header or Response)   **
**                  LIN_TX_HEADER_ERROR :                                     **
**                      Erroneous header transmission such as:                **
**                         - Mismatch between sent and read back data         **
**                         - Identifier parity error or                       **
**                         - Physical bus error                               **
**                  LIN_TX_ERROR: Erroneous transmission                      **
**                         - Mismatch between sent and read back data         **
**                         - Physical bus error                               **
**                  LIN_RX_OK   : Reception of correct response               **
**                  LIN_RX_BUSY : Ongoing reception: at least one response    **
**                                byte has been received, but the checksum    **
**                                byte has not been received                  **
**                  LIN_RX_ERROR: Erroneous reception                         **
**                                - Framing error                             **
**                                - Data error                                **
**                                - Checksum error or Short response          **
**                  LIN_RX_NO_RESPONSE : No reception                         **
**                  LIN_CH_OPERATIONAL : Normal operation; the related LIN    **
**                                    channel is ready to transmit next header**
**                                    No data from previous frame available   **
**                                   (e.g. after initialization)              **
**                  LIN_SLEEP : Sleep mode operation; in this mode wake-up **
**                                 detection from slave nodes is enabled      **
**                                                                            **
** Description :    Indicates the current transmission, reception or          **
**                  operation status of the LIN driver                        **
**                                                                            **
**                  If a SDU has been successfully received, the SDU          **
**                  will be stored in a shadow buffer or memory mapped LIN    **
**                  Hardware receive buffer referenced by Lin_SduPtr.         **
**                  The buffer will only be valid and must be read until the  **
**                  next Lin_SendHeader function call.                        **
**                  The LIN driver shall provide a function to                **
**                  interrogate the status of the current frame transmission  **
**                  request ((Lin_17_AscLin_GetStatus)                        **
**                  The LIN driver shall provide a service for                **
**                  checking the current state of each LIN channel under its  **
**                  control (( Lin_17_AscLin_GetStatus)                       **
**                  LIN operation states for a LIN channel or frame,          **
**                  as returned by the API service Lin_17_AscLin_GetStatus()  **
**                                                                            **
*******************************************************************************/
extern Lin_StatusType Lin_17_AscLin_GetStatus(uint8 Channel, uint8 **LinSduPtr);


/*******************************************************************************
**                      Global Function Declarations:                         **
**             Functions to be Called From Interrupt/Scheduler Context        **
*******************************************************************************/
/*******************************************************************************
** Syntax :          void Lin_17_AscLin_IsrReceive( uint8  HwUnit)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  HwUnit : Represents ASCLIN hw module number              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever the Slave response data **
**                   is completely received by the ASCLIN w/o any errors      **
*******************************************************************************/
extern void Lin_17_AscLin_IsrReceive(uint8 HwUnit);
/*******************************************************************************
** Syntax :          void Lin_17_AscLin_IsrTransmit( uint8  HwUnit)           **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  HwUnit : Represents Hw Module number                     **
**                                                                            **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever the response data       **
**                   is successfully transmitted by the ASCLIN w/o any errors **
**                                                                            **
*******************************************************************************/
extern void Lin_17_AscLin_IsrTransmit(uint8 HwUnit);
/*******************************************************************************
** Syntax :          void Lin_17_AscLin_IsrError( uint8  HwUnit)              **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  HwUnit : Represents Hw Module number                     **
**                                                                            **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever there is an data        **
**                   transmission or reception error in ASCLIN                **
*******************************************************************************/
extern void Lin_17_AscLin_IsrError(uint8 HwUnit);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif /* LIN_H */


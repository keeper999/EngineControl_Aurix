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
**  $FILENAME   : Msc.h $                                                    **
**                                                                           **
**  $CC VERSION : \main\10 $                                                 **
**                                                                           **
**  $DATE       : 2013-11-07 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of MSC driver.                               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEABILITY : [cover parentID=SAS_NAS_MSC_PR1071]   [/cover]             **
**                                                                            **
*******************************************************************************/

#ifndef MSC_H
#define MSC_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

  /* Global functions like Set/Reset END INIT protection bit,
  Enable/Disable interrupts, Atomic write function */
#include "Mcal.h"

  /* Inclusion of configuration file */
#include "Msc_Cfg.h"

#if (MSC_DEV_ERROR_DETECT == STD_ON )
  /* Inclusion of Det.h */
#include "Det.h"
#endif /* End of MSC_DEV_ERROR_DETECT */

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#if (MSC_DEV_ERROR_DETECT == STD_ON)

/****************************Service ID's****************************/
#define MSC_SID_INIT                                   ((uint8)0x00U)
#define MSC_SID_DEINIT                                 ((uint8)0x01U)
#define MSC_SID_CHANGETXSTATUS                         ((uint8)0x02U)
#define MSC_SID_GETTXSTATUS                            ((uint8)0x03U)
#define MSC_SID_TXCMDFRAME                             ((uint8)0x04U)
#define MSC_SID_TXDATAFRAME                            ((uint8)0x05U)
#define MSC_SID_RECONFIGEMERDATA                       ((uint8)0x06U)
#define MSC_SID_GETRXSTATUS                            ((uint8)0x07U)
#define MSC_SID_GETRXDATA                              ((uint8)0x08U)
#define MSC_SID_SELRXDEVICE                            ((uint8)0x09U)
#define MSC_SID_STARTRXTIMEOUT                         ((uint8)0x0AU)
#define MSC_SID_GETRXTIMEOUT                           ((uint8)0x0BU)
#define MSC_SID_GETTIMEFRMCOUNTER                      ((uint8)0x0CU)
#define MSC_SID_GETVERSIONINFO                         ((uint8)0x0DU)
#define MSC_SID_CHANGERXSTATUS                         ((uint8)0x0EU)

/****************************DET Error ID***************************/
#define MSC_E_PARAM_CONFIG                             ((uint8)0x00U)
#define MSC_E_UNINIT                                   ((uint8)0x01U)
#define MSC_E_INVALID_MODULE                           ((uint8)0x02U)
#define MSC_E_INVALID_MODE                             ((uint8)0x03U)
#define MSC_E_INVALID_TXTYPE                           ((uint8)0x04U)
#define MSC_E_INVALID_DEVICE                           ((uint8)0x05U)
#define MSC_E_INVALID_STATE                            ((uint8)0x06U)
#define MSC_E_INVALID_RXREGISTER                       ((uint8)0x07U)
#define MSC_E_INVALID_RXDEVICE                         ((uint8)0x08U)
#define MSC_E_PARAM_POINTER                            ((uint8)0x09U)

#endif /* End of MSC_DEV_ERROR_DETECT */

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*
 * Type : Msc_PassiveTimeFrameCounterType
 * Typedef for Passive Time Frame Counter
*/
typedef uint8 Msc_PassiveTimeFrameCounterType;

/*
 * Type : Msc_NotificationPtrType
 * Notification pointer type for calling the application callback
 * on interrupts.
*/
typedef void(*Msc_NotificationPtrType)(void);

/*
 * Type : Msc_RxStatusType
 * Typedef for Rx frame status
*/
typedef enum
{
  MSC_RX_NOT_OK,
  MSC_DATA_RECEIVED,
  MSC_RX_ERROR,
  MSC_RX_NO_RESPONSE
}Msc_RxStatusType;

/*
 * Type : Msc_RxStateType
 * Typedef for switching ON/OFF Rx.
*/
typedef enum
{
  MSC_RX_ON,
  MSC_RX_OFF
}Msc_RxStateType;

/*
 * Type : Msc_TxStatusType
 * Typedef for indicating the Transmitter readiness for data/cmd.
*/
typedef enum
{
  MSC_TX_NOT_OK,
  MSC_CMDFRMTX_READY,
  MSC_CMDFRMTX_NOTREADY,
  MSC_DATAFRMTX_READY,
  MSC_DATAFRMTX_NOTREADY
}Msc_TxStatusType;

/*
 * Type : Msc_TxStateType
 * Typedef for switching ON/OFF the transmitter.
*/
typedef enum
{
  MSC_TX_ON,
  MSC_TX_OFF
}Msc_TxStateType;

/*
 * Type : Msc_UpstreamRegType
 * Typedef for Upstream registers.
*/
typedef enum
{
  MSC_UD0,
  MSC_UD1,
  MSC_UD2,
  MSC_UD3
}Msc_UpstreamRegType;

/*
 * Type : Msc_TxType
 * Typedef for indicating Type of frame to be tx.
*/
typedef enum
{
  MSC_CMD_FRAME,
  MSC_DATA_FRAME
}Msc_TxType;

/*
 * Type : Msc_TxDevSelectType
 * Typedef for selecting the Tx device.
*/
typedef enum
{
  MSC_TX_DEVICE_0,
  MSC_TX_DEVICE_1,
  MSC_TX_DEVICE_2,
  MSC_TX_DEVICE_3
}Msc_TxDevSelectType;

/*
 * Type : Msc_RxDevSelectType
 * Typedef for selecting the Rx device.
*/
typedef enum
{
  MSC_RX_DEVICE_0,
  MSC_RX_DEVICE_1,
  MSC_RX_DEVICE_2,
  MSC_RX_DEVICE_3,
  MSC_RX_DEVICE_4,
  MSC_RX_DEVICE_5,
  MSC_RX_DEVICE_6,
  MSC_RX_DEVICE_7
}Msc_RxDevSelectType;

/*
 * Type : Msc_RxTimeoutStatusType
 * Typedef for indicating timeout on upstream channel.
*/
typedef enum
{
  MSC_TIMEOUT_NOT_OK,
  MSC_UPSTREAM_NO_TIMEOUT,
  MSC_UPSTREAM_TIMEOUT
}Msc_RxTimeoutStatusType;

/*
 * Type : Msc_InterruptSettingsType
 * Typedef structure for storing the interrupt related configuration.
*/
typedef struct Msc_InterruptSettingsType
{
  uint32 InterruptControl;
  Msc_NotificationPtrType TimeFrmNotify;
  Msc_NotificationPtrType CmdFrmNotify;
  Msc_NotificationPtrType DataFrmNotify;
  Msc_NotificationPtrType RxFrmNotify;
  uint8 SRConfig;
}Msc_InterruptSettingsType;

/*
 * Type : Msc_ModuleConfigType
 * Typedef structure for storing configuration related to each module of MSC.
*/
typedef struct Msc_ModuleConfigType
{
  uint32 TxConfig;
  uint32 TxConfigExtn;
  uint32 DataBitSrcLowConfig;
  uint32 DataBitExtensionSrcLowConfig;
  uint32 DataBitSrcHighConfig;
  uint32 DataBitExtensionSrcHighConfig;
  uint32 DataRegSourceMask;
  uint32 DataRegSourceMaskExtn;
  uint32 DataEmergencyStopControl;
  uint32 DataExtnEmergencyStopControl;
  uint32 DataEmergencyValueLow;
  uint32 DataExtnEmergencyValueLow;
  uint32 DataEmergencyValueHigh;
  uint32 DataExtnEmergencyValueHigh;
  uint32 DataInjConfig;
  uint32 ClkConfig;
  uint32 RxConfig;
  uint32 SignalConfig;
  uint32 UpstreamTimeoutConfig;
  uint8 TimeFrmCnt;
  uint8 SleepMode;
  uint8 ExtensionValue;
  Msc_InterruptSettingsType InterruptConfig;
}Msc_ModuleConfigType;

/*
 * Type : Msc_ConfigType
 * Typedef structure for storing address of module configurations.
*/
typedef struct Msc_ConfigType
{
  const Msc_ModuleConfigType *ModCfgPtr[MSC_NUM_OF_MODULES];
}Msc_ConfigType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define MSC_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* Declaration of MSC Post Build Configuration */
extern const Msc_ConfigType Msc_ConfigRoot[];
#define MSC_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*Memory Map of the MSC Code*/
#define MSC_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void Msc_Init(const Msc_ConfigType* ConfigPtr)           **
**                                                                            **
** Service ID      : 0x00                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : ConfigPtr - Pointer to MSC Driver configuration set      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Driver Module Initialization                                 **
**               1.This function will initialize all relevant registers of    **
**                 with the values of structure given by ConfigPtr            **
**                                                                            **
*******************************************************************************/
extern void Msc_Init(const Msc_ConfigType* ConfigPtr);

#if (MSC_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void Msc_DeInit(void)                                    **
**                                                                            **
** Service ID      : 0x01                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Driver DeInitialization                                      **
**               1.This function will deinitialize the MSC peripheral         **
**                                                                            **
*******************************************************************************/
extern void Msc_DeInit(void);
#else
#define Msc_DeInit()                    ERROR_Msc_DeInit_NOT_SELECTED
#endif /* End of MSC_DEINIT_API */

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType Msc_ChangeTxState  (uint8 ModNum,         **
**                   Msc_TxStateType Mode)                                    **
**                                                                            **
** Service ID      : 0x02                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Mode - MSC_TX_ON - Transmitter is switched ON            **
**                          MSC_TX_OFF - Transmitter is switched OFF          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/E_NOTOK                                             **
**                                                                            **
** Description     : This function:                                           **
**   - Activates/Deactivates the transmitter (downstream channel) of the      **
**     MSC module                                                             **
*******************************************************************************/
extern Std_ReturnType Msc_ChangeTxState (uint8 ModNum, Msc_TxStateType Mode);

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Msc_TxStatusType Msc_GetTxStatus (uint8 ModNum,          **
**                   Msc_TxType FrameType                                     **
**                                                                            **
** Service ID      : 0x03                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   FrameType - MSC_CMD_FRAME - Check for Command frame      **
**                               MSC_DATA_FRAME - Check for Data frame        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Msc_TxStatusType                                         **
**                                                                            **
** Description     : This function:                                           **
**   - Returns the readiness of the Tx to accept new command /data frame      **
**     transmission requests                                                  **
*******************************************************************************/
extern Msc_TxStatusType Msc_GetTxStatus (uint8 ModNum, Msc_TxType FrameType);

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType Msc_TxCmdFrame (uint8 ModNum,             **
**                   Msc_TxDevSelectType Device, uint32 Msc_Cmd)              **
**                                                                            **
** Service ID      : 0x04                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Device - MSC_TX_DEVICE_0/MSC_TX_DEVICE_1/                **
                              MSC_TX_DEVICE_2/MSC_TX_DEVICE_3                 **
**                   Msc_Cmd - Command to be transmitted                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/E_NOT_OK                                            **
**                                                                            **
** Description     : This function:                                           **
**   - Transmits a command frame                                              **
*******************************************************************************/
extern Std_ReturnType Msc_TxCmdFrame (uint8 ModNum, Msc_TxDevSelectType Device,\
                               uint32 Msc_Cmd);

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType Msc_TxDataFrame (uint8 ModNum,            **
**                   Msc_TxDevSelectType DeviceHigh,                          **
**                   Msc_TxDevSelectType DeviceLow,const uint32 *Msc_Data)    **
**                                                                            **
** Service ID      : 0x05                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   DeviceHigh / DeviceLow - MSC_TX_DEVICE_0/                **
                     MSC_TX_DEVICE_1/MSC_TX_DEVICE_2/MSC_TX_DEVICE_3          **
**                   Msc_Data - Pointer to the Data to be transmitted         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/E_NOT_OK                                            **
**                                                                            **
** Description      : This function:                                          **
**   - Transmits a data frame                                                 **
*******************************************************************************/
extern Std_ReturnType Msc_TxDataFrame (uint8 ModNum,\
               Msc_TxDevSelectType DeviceHigh,Msc_TxDevSelectType DeviceLow,\
               const uint32 *Msc_Data);

#if ( MSC_EMERGENCY_DATA_API == STD_ON )
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType Msc_ReconfigureEmergencyData(uint8 ModNum,**
**                  uint32 Msc_EmergencyDataHigh, uint32 Msc_EmergencyDataLow)**
**                                                                            **
** Service ID      : 0x06                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Msc_EmergencyDataHigh - Higher 16 bits of emergency      **
**                   data                                                     **
**                   Msc_EmergencyDataHigh - Lower 16 bits of emergency       **
**                   data                                                     **
**                   Msc_Data - Pointer to the Data to be transmitted         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :    E_OK/E_NOT_OK                                         **
**                                                                            **
** Description     : This function:                                           **
**   - Reconfigures the emergency data in DD register                         **
*******************************************************************************/
extern Std_ReturnType Msc_ReconfigureEmergencyData(uint8 ModNum,\
               uint32 Msc_EmergencyDataHigh, uint32 Msc_EmergencyDataLow);
#else
#define Msc_ReconfigureEmergencyData(ModNum,Msc_EmergencyDataHigh,\
       Msc_EmergencyDataLow)   ERROR_Msc_ReconfigureEmergencyData_NOT_SELECTED
#endif /* End of MSC_EMERGENCY_DATA_API */

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType Msc_ChangeRxStatus (uint8 ModNum,         **
**                   Msc_RxStateType Mode)                                    **
**                                                                            **
** Service ID      : 0x0E                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Mode - MSC_RX_ON - Receiver is switched ON               **
**                          MSC_RX_OFF - Receiver is switched OFF             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/E_NOTOK                                             **
**                                                                            **
** Description     : This function:                                           **
**   - Activates/Deactivates the receiver (upstream channel) of the           **
**     MSC module                                                             **
*******************************************************************************/
extern Std_ReturnType Msc_ChangeRxState (uint8 ModNum, Msc_RxStateType Mode);

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Msc_RxStatusType  Msc_GetRxStatus (uint8 ModNum,         **
**                   Msc_UpstreamRegType Msc_RxRegister)                      **
**                                                                            **
** Service ID      : 0x07                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Msc_RxRegister - MSC_UD0/MSC_UD1/MSC_UD2/MSC_UD3         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Msc_RxStatusType                                         **
**                                                                            **
** Description     : This function :                                          **
**   - returns the status of the Rx register                                  **
*******************************************************************************/
extern Msc_RxStatusType  Msc_GetRxStatus (uint8 ModNum,\
                                  Msc_UpstreamRegType Msc_RxRegister);

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType Msc_GetRxData(uint8 ModNum,               **
**                   Msc_UpstreamRegType RxRegister, uint16 *DataRecd)        **
**                                                                            **
** Service ID      : 0x08                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Msc_RxRegister - MSC_UD0/MSC_UD1/MSC_UD2/MSC_UD3         **
**                                                                            **
** Parameters (out): DataRecd - UDx register data is copied to this variable  **
**                                                                            **
** Return value    : E_OK / E_NOT_OK                                          **
**                                                                            **
** Description     : This function :                                          **
**   - returns the data received in the Rx register                           **
*******************************************************************************/
extern Std_ReturnType Msc_GetRxData(uint8 ModNum,\
                             Msc_UpstreamRegType RxRegister, uint16 *DataRecd);

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType Msc_SelectRxDevice(uint8 ModNum,          **
**                   Msc_RxDevSelectType Msc_Device)                          **
**                                                                            **
** Service ID      : 0x09                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Msc_Device - Upstream Device to be selected              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK / E_NOT_OK                                          **
**                                                                            **
** Description     : This function :                                          **
**   - selects the upstream device                                            **
*******************************************************************************/
extern Std_ReturnType Msc_SelectRxDevice(uint8 ModNum,\
                                        Msc_RxDevSelectType Msc_Device);

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType Msc_StartRxTimeout(uint8 ModNum)          **
**                                                                            **
** Service ID      : 0x0A                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK / E_NOT_OK                                          **
**                                                                            **
** Description     : This function :                                          **
**   - starts the upstream timeout                                            **
*******************************************************************************/
extern Std_ReturnType Msc_StartRxTimeout(uint8 ModNum);

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Msc_RxTimeoutStatusType Msc_GetRxTimeoutStatus           **
**                  (uint8 ModNum)                                            **
**                                                                            **
** Service ID      : 0x0B                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Msc_RxTimeoutStatusType                                  **
**                                                                            **
** Description     : This function :                                          **
**   - returns the status of the  upstream timeout                            **
*******************************************************************************/
extern Msc_RxTimeoutStatusType Msc_GetRxTimeoutStatus(uint8 ModNum);

#if (MSC_PASSIVE_TIME_FRAME_API == STD_ON)
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType                                           **
**                   Msc_GetPassiveTimeFrameCounter (uint8 ModNum,            **
**                   Msc_PassiveTimeFrameCounterType *CounterValue)           **
**                                                                            **
** Service ID      : 0x0C                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Msc_GetPassiveTimeFrameCounter                           **
**                                                                            **
** Description     : This function :                                          **
**   - returns the status of the  upstream timeout                            **
*******************************************************************************/
extern Std_ReturnType Msc_GetPassiveTimeFrameCounter (uint8 ModNum,\
                                Msc_PassiveTimeFrameCounterType *CounterValue);
#else
#define Msc_GetPassiveTimeFrameCounter(ModNum,CounterValue)\
                    ERROR_Msc_GetPassiveTimeFrameCounter_NOT_SELECTED
#endif /* End of MSC_PASSIVE_TIME_FRAME_API */

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void Msc_InterruptHandler (uint8 ModNum,                 **
**                     uint8 ServiceNum)                                      **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   ServiceNum - Service number from which API is invoked    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function :                                          **
**   - Callbacks the configured functions for individual Interrupts           **
*******************************************************************************/
extern void Msc_InterruptHandler (uint8 ModNum, uint8 ServiceNum);

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_PR63_18,DS_NAS_PR63_19]           **
**                                                                            **
** Syntax     : void Msc_GetVersionInfo( Std_VersionInfoType *VersionInfoPtr) **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID   : 0x0D                                                        **
**                                                                            **
** Sync/Async   : Synchronous                                                 **
**                                                                            **
** Reentrancy   : Non-reentrant                                               **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): VersionInfoPtr (Pointer to store the version             **
**                   information of this module)                              **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
** Description  : This service returns the version information of this module.**
**               The version information includes:                            **
**               - Module Id                                                  **
**               - Vendor Id                                                  **
**               - Instance Id                                                **
**               - Vendor specific version numbers                            **
**                                                                            **
*******************************************************************************/
#if ((MSC_VERSION_INFO_API == STD_ON) && (MSC_DEV_ERROR_DETECT == STD_ON))
#define Msc_GetVersionInfo(VersionInfoPtr)                                \
{                                                                         \
  if ((VersionInfoPtr == NULL_PTR))                                       \
  {                                                                       \
    /* Report to DET */                                                   \
    Det_ReportError(                                                      \
                     (uint16)MSC_MODULE_ID,                               \
                     MSC_MODULE_INSTANCE,                                 \
                     MSC_SID_GETVERSIONINFO,                              \
                     MSC_E_PARAM_POINTER                                  \
                   );                                                     \
  }                                                                       \
  else                                                                    \
  {                                                                       \
    /* MSC Module ID */                                                   \
    ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = MSC_MODULE_ID;   \
    /* MSC vendor ID */                                                   \
    ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = MSC_VENDOR_ID;   \
    /* major version of MSC */                                            \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =          \
                                    (uint8)MSC_SW_MAJOR_VERSION;          \
    /* minor version of MSC */                                            \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =          \
                                    (uint8)MSC_SW_MINOR_VERSION;          \
    /* patch version of MSC */                                            \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =          \
                                    (uint8)MSC_SW_PATCH_VERSION;          \
  }                                                                       \
}
#elif ((MSC_VERSION_INFO_API == STD_ON) && (MSC_DEV_ERROR_DETECT == STD_OFF))
#define Msc_GetVersionInfo(VersionInfoPtr)                                \
{                                                                         \
  /* MSC Module ID */                                                     \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = MSC_MODULE_ID;     \
  /* MSC vendor ID */                                                     \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = MSC_VENDOR_ID;     \
  /* major version of MSC */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =            \
                                  (uint8)MSC_SW_MAJOR_VERSION;            \
  /* minor version of MSC */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =            \
                                  (uint8)MSC_SW_MINOR_VERSION;            \
  /* patch version of MSC */                                              \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =            \
                                  (uint8)MSC_SW_PATCH_VERSION;            \
}
#else
#define Msc_GetVersionInfo(VersionInfoPtr)\
                                 ERROR_Msc_GetVersionInfo_NOT_SELECTED
#endif

#define MSC_STOP_SEC_CODE
#include "MemMap.h"

#endif /* End of MSC_H*/

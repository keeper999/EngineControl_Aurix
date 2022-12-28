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
**  $FILENAME   : Lin_17_AscLin.c $                                          **
**                                                                           **
**  $CC VERSION : \main\48 $                                                 **
**                                                                           **
**  $DATE       : 2013-08-07 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of Lin driver.                               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
    TRACEABILITY : [cover parentID=DS_AS_LIN156, DS_NAS_PR734,
    DS_AS403_LIN226,DS_AS403_LIN234_LIN235,DS_NAS_PR912
    ,DS_AS_LIN177] [/cover]                      
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "IfxAsclin_reg.h"
#include "IfxSrc_reg.h"

/* Own header file, this includes own configuration file also */
#include "Lin_17_AscLin.h"

/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/* [cover parentID=DS_AS403_LIN062] */
/* LIN Header File Version Check */
#ifndef LIN_17_ASCLIN_SW_MAJOR_VERSION
  #error "LIN_17_ASCLIN_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef LIN_17_ASCLIN_SW_MINOR_VERSION
  #error "LIN_17_ASCLIN_SW_MINOR_VERSION is not defined. "
#endif

#ifndef LIN_17_ASCLIN_SW_PATCH_VERSION
  #error "LIN_17_ASCLIN_SW_PATCH_VERSION is not defined. "
#endif

#if (LIN_17_ASCLIN_SW_MAJOR_VERSION != 2U)
  #error "LIN_17_ASCLIN_SW_MAJOR_VERSION does not match. "
#endif

#if (LIN_17_ASCLIN_SW_MINOR_VERSION != 0U)
  #error "LIN_17_ASCLIN_SW_MINOR_VERSION does not match. "
#endif


/* AUTOSAR Secification File Version Check */
#ifndef LIN_17_ASCLIN_AR_RELEASE_MAJOR_VERSION
  #error "LIN_17_ASCLIN_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef LIN_17_ASCLIN_AR_RELEASE_MINOR_VERSION
  #error "LIN_17_ASCLIN_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef LIN_17_ASCLIN_AR_RELEASE_REVISION_VERSION
  #error "LIN_17_ASCLIN_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if (LIN_17_ASCLIN_AR_RELEASE_MAJOR_VERSION != 4U)
  #error "LIN_17_ASCLIN_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if (LIN_17_ASCLIN_AR_RELEASE_MINOR_VERSION != 0U)
  #error "LIN_17_ASCLIN_AR_RELEASE_MINOR_VERSION does not match. "
#endif

/*
  VERSION CHECK FOR DET MODULE INCLUSION
*/

#if ( LIN_DEV_ERROR_DETECT == STD_ON)

#ifndef DET_AR_RELEASE_MAJOR_VERSION
  #error "DET_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef DET_AR_RELEASE_MINOR_VERSION
  #error "DET_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif
#if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#endif
/* End Of LIN_DEV_ERROR_DETECT */

/* [/cover] */
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* ASC Register Start Address Mapping */
#define LIN_HW_MODULE  ((Ifx_ASCLIN *)(void *) &(MODULE_ASCLIN0))

#define LIN_ASCLIN_FRAMECON_INIT_MODE (0U)/* ASCLIN INIT mode */
#define LIN_ASCLIN_FRAMECONREG_LIN_MODE (3U) /* ASCLIN LIN mode */
#define LIN_ASCLIN_FRAMECONREG_PEN_VAL (0U) /* Disable Parity */
#define LIN_ASCLIN_FRAMECONREG_CEN_VAL (1U) /* Collision detection enable */
#define LIN_ASCLIN_FRAMECONREG_STOP_VAL (1U) /* 1 stop bit */
#define LIN_ASCLIN_FRAMECONREG_LEAD_VAL (2U) /* 1 bit Lead value */

#define LIN_ASCLIN_BITCONREG_OS_VAL (15U) /* Oversampling value = 16X */
#define LIN_ASCLIN_BITCONREG_SM_VAL (1U) /* Sample Mode = 3 bit */
#define LIN_ASCLIN_BITCON_SP_VAL (9U) /* Sample point = 9 */
#define LIN_ASCLIN_IOCRREG_DEPTH_VAL (0U) /* digital Glitch Filter Disabled  */
#define LIN_ASCLIN_LINCONREG_CSEN_VAL (1U) /* Hw Checksum Enable  */
#define LIN_ASCLIN_LINCON_MASTER_ENABLE (1U) /* Enable LIN as Master */
/* Checksum injection to Rxfifo disabled */
#define LIN_ASCLIN_LINCONREG_CSI_VAL (0U)  /* Checksum injection disable */
#define LIN_ASCLIN_LINBTIMER_BREAK_VAL (14U) /* Break = 13 bit/s */
#define LIN_ASCLIN_LINHTIMER_HEADER_VAL (48U) /* Header Timeout = 48 bits */
#define LIN_ASCLIN_TXFIFOCONREG_INW_VAL (1U) /* Inlet valve width = 1 byte */
#define LIN_ASCLIN_RXFIFOCON_OUTW_VAL (1U) /* Outlet valve width = 1 byte */
#define LIN_ASCLIN_CSRREG_CLKSEL_NOCLK (0U) /* No Clock  */
#define LIN_ASCLIN_CSRREG_CLKSEL_CLC (1U) /* Clk source = fCLC i.e fSPB */
#define LIN_ASCLIN_CSRREG_CLKSEL_EVROSC (2U) /* Clk source = fOSC */
#define LIN_ASCLIN_CSRREG_CLKSEL_FMAX (8U) /* Clk source = fMAX */

/* Lin Clock select source */
#define LIN_ASCLIN_CSRREG_CLKSEL (LIN_ASCLIN_CSRREG_CLKSEL_FMAX)

/* AscLin Error Flags */
#define LIN_ASCLIN_FLAGSREG_FE ((uint32)0x1 << 18U) /* Framing Error */
#define LIN_ASCLIN_FLAGSREG_HT ((uint32)0x1 << 19U) /* Header Timeout */
#define LIN_ASCLIN_FLAGSREG_RT ((uint32)0x1 << 20U) /* Response Timeout */
#define LIN_ASCLIN_FLAGSREG_LP ((uint32)0x1 << 22U) /* ID Parity Error */
#define LIN_ASCLIN_FLAGSREG_LC ((uint32)0x1 << 24U) /* Checksum Error */
#define LIN_ASCLIN_FLAGSREG_CE ((uint32)0x1 << 25U) /* Collision detected */
#define LIN_ASCLIN_FLAGSREG_RFO ((uint32)0x1 << 26U) /* Rx Fifo overflow */
#define LIN_ASCLIN_FLAGSREG_RFU ((uint32)0x1 << 27U) /* Rx Fifo underflow */
#define LIN_ASCLIN_FLAGSREG_TFO ((uint32)0x1 << 30U) /* Tx Fifo overflow */
#define LIN_ASCLIN_FLAGSREG_TFL ((uint32)0x1 << 31U) /* Tx Fifo Underflow */
#define LIN_ASCLIN_FLAGSREG_TC ((uint32)0x1 << 17U) /* Tx Fifo Underflow */
#define LIN_ASCLIN_FLAGSREG_FED ((uint32)0x1 << 5U) /* Falling edge detect */

/* Flagsset register offset  */
#define LIN_FLAGSSET_OFFSET_TRRQS  (15U)
#define LIN_FLAGSSET_OFFSET_THRQS  (14U)

/* AscLin Status Flags */
/* Transmit header Completed */
#define LIN_ASCLIN_FLAGSREG_TH ((uint32)0x00000001U)
/* Transmit Response Completed */
#define LIN_ASCLIN_FLAGSREG_TR ((uint32)0x00000002U)
/* Receive Response completed  */
#define LIN_ASCLIN_FLAGSREG_RR ((uint32)0x00000008U)

#define LIN_PID_MASK_WO_PARITY (0x3FU) /* Mask for PID to remove Parity bits */
/* Mask to Clear All register Flags */
#define LIN_ASCLIN_FLAGSCLEAR_VAL (0xDFFFE06FU)

/* SRC register for ASCLIN are offset by a below value  0x0C div 4 */
#define LIN_ASCLIN_SRC_ADDROFFSET (0x03U)

/* RXFIFO fill value when only ID is recieved */
#define LIN_RXFIFOVAL_IDONLY (1U)

#define LIN_ENABLE_FLAG (1U)
#define LIN_DISABLE_FLAG (0U)
#define LIN_SLEEPCMD_DL (8U)
#define LIN_SLEEPCMD_PID (60U)
#define LIN_SLEEPCMD_DATA0 (0x00U)
#define LIN_SLEEPCMD_DATA1TO7 (0xFFU)
#define LIN_SLEEPCMD_DATLEN (8U)
#define LIN_INTIALISED    (1U)

/* SRC register addresses */
#define SRC_ASCLIN0TXADDR  ((Ifx_SRC_SRCR_Bits volatile *) \
(void *)&(SRC_ASCLIN0TX))
#define SRC_ASCLIN0RXADDR  ((Ifx_SRC_SRCR_Bits volatile *) \
(void *)&(SRC_ASCLIN0RX))
#define SRC_ASCLIN0ERRADDR  ((Ifx_SRC_SRCR_Bits volatile *) \
(void *)&(SRC_ASCLIN0ERR))

/* Header Timeout Error */
#define LIN_ASCLIN_HEADER_TIMEOUT_ERR (LIN_ASCLIN_FLAGSREG_HT)
/* Response Timeout Error */
#define LIN_ASCLIN_RESP_TIMEOUT_ERR (LIN_ASCLIN_FLAGSREG_RT)

/* Flags, Flagsenable, Flagsclear register/s mask for
   Master to Slave transmission */
#define LIN_ASCLIN_FLAGS_MS_TX (LIN_ASCLIN_FLAGSREG_TR | LIN_ASCLIN_FLAGSREG_HT\
| LIN_ASCLIN_FLAGSREG_TFO | LIN_ASCLIN_FLAGSREG_CE | LIN_ASCLIN_FLAGSREG_RT \
| LIN_ASCLIN_FLAGSREG_FE | LIN_ASCLIN_FLAGSREG_LP )

/* Flags, Flagsenable, Flagsclear register/s mask for
   Slave to Master transmission */
#define LIN_ASCLIN_FLAGS_MS_RX (LIN_ASCLIN_FLAGSREG_RR | LIN_ASCLIN_FLAGSREG_HT\
| LIN_ASCLIN_FLAGSREG_RFO |  LIN_ASCLIN_FLAGSREG_RFU | LIN_ASCLIN_FLAGSREG_CE \
| LIN_ASCLIN_FLAGSREG_RT | LIN_ASCLIN_FLAGSREG_FE | LIN_ASCLIN_FLAGSREG_LC \
)

/* Flags, Flagsenable, Flagsclear register/s mask for
   Slave to Slave transmission */
#define LIN_ASCLIN_FLAGS_MS_HO (LIN_ASCLIN_FLAGSREG_TH | LIN_ASCLIN_FLAGSREG_HT\
| LIN_ASCLIN_FLAGSREG_TFO | LIN_ASCLIN_FLAGSREG_CE |  \
LIN_ASCLIN_FLAGSREG_FE | LIN_ASCLIN_FLAGSREG_LP )

/* Flags, Flagsenable, Flagsclear register/s mask for
   Master to Slave transmission */
#define LIN_ASCLIN_FLAGSCLEAR_MS_TX (LIN_ASCLIN_FLAGSREG_TR \
  | LIN_ASCLIN_FLAGSREG_HT\
| LIN_ASCLIN_FLAGSREG_TFO | LIN_ASCLIN_FLAGSREG_CE | LIN_ASCLIN_FLAGSREG_RT \
| LIN_ASCLIN_FLAGSREG_TFL | LIN_ASCLIN_FLAGSREG_TC \
| LIN_ASCLIN_FLAGSREG_FE | LIN_ASCLIN_FLAGSREG_LP )

/* Flags, Flagsenable, Flagsclear register/s mask for
   Slave to Master transmission */
#define LIN_ASCLIN_FLAGSCLEAR_MS_RX (LIN_ASCLIN_FLAGSREG_RR \
  | LIN_ASCLIN_FLAGSREG_HT\
| LIN_ASCLIN_FLAGSREG_RFO |  LIN_ASCLIN_FLAGSREG_RFU | LIN_ASCLIN_FLAGSREG_CE \
| LIN_ASCLIN_FLAGSREG_RT | LIN_ASCLIN_FLAGSREG_FE | LIN_ASCLIN_FLAGSREG_LC \
| LIN_ASCLIN_FLAGSREG_TFL | LIN_ASCLIN_FLAGSREG_TC)

/* Flags, Flagsenable, Flagsclear register/s mask for
   Slave to Slave transmission */
#define LIN_ASCLIN_FLAGSCLEAR_MS_HO (LIN_ASCLIN_FLAGSREG_TH \
  | LIN_ASCLIN_FLAGSREG_HT\
| LIN_ASCLIN_FLAGSREG_TFO | LIN_ASCLIN_FLAGSREG_CE |  \
LIN_ASCLIN_FLAGSREG_FE | LIN_ASCLIN_FLAGSREG_LP )

#define LIN_TIMEOUT_DURATION             (1000U)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*Enum for Sleep request */
enum
{
  LIN_SLEEP_NOT_REQ = 0U,
  LIN_SLEEP_REQ = 1U
};

#if (LIN_DEBUG_SUPPORT == STD_OFF)
typedef enum
{
  LIN_CH_UNINIT_I = 0U,
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
Lin_17_AscLin_ChannelInfoType: This structure is used for storing internal 
LIN channel status and other information.
*/
typedef struct Lin_17_AscLin_ChannelInfoType
{
   Lin_IntStatusType   State;    /* Current internal state of LIN driver */
   uint8   Sleep;    /* Sleep requested/not requested */
   Lin_FrameCsModelType   Cs;       /* Checksum type */
   uint8   Dl;       /* Data length of the sdu */
   Lin_FramePidType   Pid;      /* Pid of the Pdu being serviced */
   Lin_FrameResponseType   Drc;      /* Response type fo the Pdu */
}Lin_17_AscLin_ChannelInfoType;

#endif /*(LIN_DEBUG_SUPPORT == OFF)*/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
/* function returns the DET check status for channel, uninit */
static _INLINE_ Std_ReturnType Lin_lGetDetStatus(uint8 Channel, uint8 ApiId);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON)*/
_INLINE_ Lin_IntStatusType Lin_lGetIntErrorStatus(uint32 HwErrorFlags);
_INLINE_ void Lin_lHwFlushTxFifo(uint8 HwUnit);
_INLINE_ void Lin_lHwFlushRxFifo(uint8 HwUnit);
_INLINE_ void Lin_lHwDisableAllIntrFlags(uint8 HwUnit);
_INLINE_ void Lin_lHwReadRxFifo(uint8 HwUnit, volatile uint8 *Ptr, uint8 count);
_INLINE_ void Lin_lHwWriteTxFifo(uint8 HwUnit, uint8 *Ptr, uint8 count);
_INLINE_ uint32 Lin_lHwGetFlags(uint8 HwUnit);
_INLINE_ void Lin_lHwSendWakeupPulse(uint8 HwUnit, uint8 WakeupVal);
_INLINE_ uint8 Lin_lHwGetRxFifoFillValue(uint8 HwUnit);
_INLINE_ uint8 Lin_lHwGetRxDStatus(uint8 HwUnit);
_INLINE_ void Lin_lHwInitClcReg(uint8 HwUnit, uint32 Value);

static void Lin_lHwInit(uint8 HwUnit,
       Lin_ChannelTimingConfigType TimingConfig, uint8 RxAlternatePinSelect);
static void Lin_lHwStartTransmission(uint8 HwUnit, uint8 Channel);
static void Lin_lHwDeInitAscLin(uint8 HwUnit);
static void Lin_lHwEnableAscLinIntr(uint8 HwUnit);
static void Lin_lHwDisableAscLinIntr(uint8 HwUnit);
#if (LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT == STD_ON)
static void Lin_lHwConfigWakeup(uint8 HwUnit, uint8 IocrDepth,
                               uint16 BitconPrescalar);
static void Lin_lHwConfigAfterWakeup(uint8 HwUnit);
#endif

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/* [cover parentID=DS_AS_LIN207] */
/* [/cover] */

#define LIN_17_ASCLIN_START_SEC_VAR_8BIT

#include "MemMap.h"
/*
This informs which channel uses ASCLINx and Store the channel number
for use by other APIs
*/
static uint8 Lin_BusStatus[LIN_MAX_HW_UNIT];

/* [cover parentID=DS_AS_LIN026] */
/* Received data is loaded into this buffer */
static uint8  Lin_ResponseBuffer[LIN_MAXIMUM_CHANNEL][LIN_RESP_BUF_SIZE];
/* [/cover] */

/* This variable is used to check Init called */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
static uint8 Lin_InitStatus;
#endif/*(LIN_DEV_ERROR_DETECT == STD_ON)*/

#define LIN_17_ASCLIN_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define LIN_17_ASCLIN_START_SEC_VAR_UNSPECIFIED

#include "MemMap.h"

/*
  This variable holds the status of the driver and includes: checksum,
  sleep status, data length, Pid response type, previous byte transmitted.
*/
#if (LIN_DEBUG_SUPPORT == STD_ON)
Lin_17_AscLin_ChannelInfoType  Lin_17_AscLin_ChannelInfo[LIN_MAXIMUM_CHANNEL];
#else
static Lin_17_AscLin_ChannelInfoType                                        \
                                Lin_17_AscLin_ChannelInfo[LIN_MAXIMUM_CHANNEL];
#endif

#define LIN_17_ASCLIN_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define LIN_17_ASCLIN_START_SEC_VAR_16BIT
/*
 * To be used for global or static variables (32 bits) that are initialized
 * after every reset (the normal case)
 */
/* These variables must be initialized to 0 after every reset */
#include "MemMap.h"

#if (LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT == STD_ON)
static uint16 SavedPrescalar[LIN_MAX_HW_UNIT];
#endif/*#if (LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT == STD_ON)*/

#define LIN_17_ASCLIN_STOP_SEC_VAR_16BIT
#include "MemMap.h"


#define LIN_17_ASCLIN_START_SEC_VAR_32BIT
/*
 * To be used for global or static variables (32 bits) that are initialized
 * after every reset (the normal case)
 */
/* These variables must be initialized to 0 after every reset */
#include "MemMap.h"

/*
Variable Holds the Configuration Pointer given in Lin_17_AscLin_Init and
Lin_ChannelInit
*/
#if (LIN_PB_FIXEDADDR == STD_OFF)
static const Lin_17_AscLin_ConfigType* Lin_kConfigPtr;
#endif /*(LIN_PB_FIXEDADDR == OFF)*/

#define LIN_17_ASCLIN_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*
  To be used for global or static constants (32 bits)
 */
#define LIN_17_ASCLIN_START_SEC_CONST_32BIT

/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#include "MemMap.h"


#if (LIN_PB_FIXEDADDR == STD_ON)
/* Variable Holds the Configuration Pointer */
static const Lin_17_AscLin_ConfigType* 
                                      const Lin_kConfigPtr = &Lin_ConfigRoot[0];
#endif /*(LIN_PB_FIXEDADDR == STD_ON)*/

#define LIN_17_ASCLIN_STOP_SEC_CONST_32BIT
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*Memory Map of the LIN Code*/
#define LIN_17_ASCLIN_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_LIN006,
 DS_AS_LIN008_LIN099_LIN105_LIN146_LIN150_LIN145_LIN237,
 DS_AS403_LIN084_1_LIN171_LIN190_1,
 DS_NAS_PR913,DS_AS403_LIN250]**
** Syntax : void Lin_17_AscLin_Init                                           **
**                               ( const Lin_17_AscLin_ConfigType* ConfigPtr )**
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to LIN driver configuration set     **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module Initialization function.                       **
** Service for LIN initialization. The Initialization function shall          **
** initialize all the Lin channels with the values                            **
** of the structure referenced by the parameter ConfigPtr.                    **
*******************************************************************************/
void Lin_17_AscLin_Init(const Lin_17_AscLin_ConfigType* ConfigPtr)
{
  uint8 ModuleNo;
  uint8 Chan;
  uint8 MaxChannel;
  const Lin_17_AscLin_ChannelType   *ChannelConfigPtr;
#if (LIN_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType ReturnStatus;

  ReturnStatus = E_OK;
#endif

  #if (LIN_DEV_ERROR_DETECT == STD_ON) /* if DET detection is switched On */
  #if (LIN_PB_FIXEDADDR == STD_OFF)
  if (ConfigPtr == NULL_PTR)
  {
    /* Report to  DET */
    Det_ReportError(
                     (uint16)LIN_17_ASCLIN_MODULE_ID,
                     LIN_MODULE_INSTANCE,
                     LIN_SID_INIT,
                     LIN_E_INVALID_POINTER
                   );
    ReturnStatus = E_NOT_OK;
  }
  #else
  if (Lin_kConfigPtr != ConfigPtr)
  {
    /* Report to  DET */
    Det_ReportError(
                     (uint16)LIN_17_ASCLIN_MODULE_ID,
                     LIN_MODULE_INSTANCE,
                     LIN_SID_INIT,
                     LIN_E_INVALID_POINTER
                   );
    ReturnStatus = E_NOT_OK;
  }
  #endif/*(LIN_PB_FIXEDADDR == STD_ON)*/
  else if (Lin_InitStatus == LIN_INTIALISED)
  {
    /* Report to  DET */
    Det_ReportError(
                     (uint16)LIN_17_ASCLIN_MODULE_ID,
                     LIN_MODULE_INSTANCE,
                     LIN_SID_INIT,
                     LIN_E_STATE_TRANSITION
                    );
    ReturnStatus = E_NOT_OK;
  }
  else
  {
    /* Dummy else */
  }
  #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */

  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  if (ReturnStatus == E_OK)
  #endif
  {
    MaxChannel = ConfigPtr->NoOfChannels;

    /* Reset End Init Protection to access regsiters */
    Mcal_ResetENDINIT();

    /* Enable the ASCLIN hardware unit/s for all the Lin channels */
    for (Chan = 0U; Chan < MaxChannel; Chan++)
    {
      ChannelConfigPtr = &(ConfigPtr->ChannelConfigPtr[Chan]);

      /* Extract the hwmodule */
      ModuleNo =ChannelConfigPtr->HwModule;
      /* Enable the ASCLIN module and also set the EDIS bit (Sleep setting) */
      Lin_lHwInitClcReg(ModuleNo, LIN_ASCLIN_CLC);
    }
    /* Set End Init Protection */
    Mcal_SetENDINIT();

    for (Chan = 0U; Chan < MaxChannel; Chan++)
    {
      ChannelConfigPtr = &(ConfigPtr->ChannelConfigPtr[Chan]);
      /* Extract the Hw module */
      ModuleNo = ChannelConfigPtr->HwModule;

      /* Initialise the Lin Hardware. */
      Lin_lHwInit(ModuleNo, ChannelConfigPtr->TimingConfig,
                                ChannelConfigPtr->RxAlternatePinSelect);

      /* If RxD line = 0, provide notification */
      if (Lin_lHwGetRxDStatus(ModuleNo) == STD_LOW)
      {
         /* Set the wakeup event in ECUM regardless of LinChannelWakeupSupport*/
         EcuM_SetWakeupEvent((uint32)1U << (ChannelConfigPtr->WakeupSourceId));
      }/*(Lin_lHwGetRxDStatus(HwUnit) == STD_LOW)*/


      /* Init the Lin BusStatus variable */
      Lin_BusStatus[ModuleNo] = Chan;
      /* Init the channel State variable */
      Lin_17_AscLin_ChannelInfo[Chan].State = LIN_CH_INIT_I;
    }


    /* Store ConfigPtr for use by APIs*/
    #if (LIN_PB_FIXEDADDR == STD_OFF)
    Lin_kConfigPtr = ConfigPtr;
    #endif/*(LIN_PB_FIXEDADDR == OFF)*/

    #if (LIN_DEV_ERROR_DETECT == STD_ON)
    Lin_InitStatus = LIN_INTIALISED;
    #endif/*(LIN_DEV_ERROR_DETECT == STD_ON)*/
  }
  return ;
}
/*******************************************************************************
** Traceability : [cover parentID=
    DS_AS403_LIN040_LIN098_LIN107_LIN109_LIN237,
    DS_AS403_LIN160,DS_AS403_LIN251]                                          **
** Syntax : void Lin_17_AscLin_CheckWakeup(uint8 Channel)                     **
** [/cover]                                                                   **
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
Std_ReturnType Lin_17_AscLin_CheckWakeup(uint8 Channel)
{
  const Lin_17_AscLin_ChannelType   *ChannelConfigPtr;
  uint32 EcumStatus;
  uint8 HwUnit;
  Std_ReturnType ReturnStatus;
  uint8 IntCh = 0U;

  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  uint8   ChannelSleep;

  ChannelSleep      = 0U;
  #endif


  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  ReturnStatus = Lin_lGetDetStatus(Channel,LIN_SID_CHECKWAKEUP);
  if (ReturnStatus == E_OK)
  {

    /* Extract the internal channel based on Logical channel  */
    while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId != 
                       Channel)&&(IntCh != (Lin_kConfigPtr->NoOfChannels - 1U)))
    {
      IntCh++;
    }

    if (Lin_17_AscLin_ChannelInfo[IntCh].State == LIN_WAKEUP_WAIT_I)
    {
      ChannelSleep = 1U;
    }
    if(ChannelSleep == 0U)
    {
      /* Report to  DET */
      Det_ReportError(
                      (uint16)LIN_17_ASCLIN_MODULE_ID,
                      LIN_MODULE_INSTANCE,
                      LIN_SID_CHECKWAKEUP,
                      LIN_E_STATE_TRANSITION
                      );
      ReturnStatus = E_NOT_OK;
    }
  }
  #else
  ReturnStatus = E_OK;
  /* Extract the internal channel based on Logical channel  */
  while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId != Channel)&&
        (IntCh != (Lin_kConfigPtr->NoOfChannels - 1U)))
  {
    IntCh++;
  }
  
  #endif/*(LIN_DEV_ERROR_DETECT == STD_ON)*/

  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  if (ReturnStatus == E_OK)
  #endif
  {
    #if (LIN_DEV_ERROR_DETECT == STD_OFF)  
      if (Lin_17_AscLin_ChannelInfo[IntCh].State == LIN_WAKEUP_WAIT_I)
    #endif
      {
        ChannelConfigPtr = &(Lin_kConfigPtr->ChannelConfigPtr[IntCh]);

        HwUnit = ChannelConfigPtr->HwModule;

        /* If RxD line = 0, provide notification */
        if (Lin_lHwGetRxDStatus(HwUnit) == STD_LOW)
        {
           EcumStatus = ChannelConfigPtr->WakeupSourceId;
           /* Set the wakeup event in ECUM regardless of
              LinChannelWakeupSupport*/
           EcuM_SetWakeupEvent((uint32)1U << EcumStatus);
           /*Lin operational state*/
           Lin_17_AscLin_ChannelInfo[IntCh].State = LIN_CH_INIT_I;
           /* Clear FLAGS and Enable interrupts in ASCLIN SRC register. */
           Lin_lHwEnableAscLinIntr(HwUnit);
        }/*(Lin_lHwGetRxDStatus(HwUnit) == STD_LOW)*/
      }/*(Lin_17_AscLin_ChannelInfo[Channel].State == LIN_WAKEUP_WAIT_I)*/
  }
  return ReturnStatus;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS403_LIN191 ,
DS_AS403_LIN016_LIN017_LIN025_LIN192_LIN195_LIN197_LIN198_LIN199_LIN021_1_LIN237
,DS_AS_LIN053_LIN018_1]
** Syntax : Std_ReturnType Lin_17_AscLin_SendFrame                            **
**           (                                                                **
**             uint8 Channel,                                                 **
**             Lin_PduType* PduInfoPtr                                        **
**           )                                                                **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Asynchonous                                                   **
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
**                   E_NOT_OK - send command has not been accepted,           **
**                              development or production error occurred.     **
**                                                                            **
** Description : Service to send a Lin Frame (header and Response).           **
**                                                                            **
*******************************************************************************/
/*MISRA violation : use const on paramaters where appropriate
  Violation: since the prototype is defined by autosar standard and the driver
  code should follow the same. Hence the rule is violated.
*/
Std_ReturnType Lin_17_AscLin_SendFrame(uint8 Channel , Lin_PduType* PduInfoPtr)
{
  const Lin_17_AscLin_ChannelType   *ChannelConfigPtr;
  Lin_IntStatusType CurStatus;
  uint8 HwUnit;
  Std_ReturnType   RetVal;
  uint8 Index;
  uint8 *DataPtr;
  uint8 IntCh = 0U;


  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  /* if the channel, UnInit parameters is invalid */
  RetVal = Lin_lGetDetStatus(Channel,LIN_SID_SENDFRAME);
  if (RetVal == E_OK)
  {

    /* Extract the internal channel based on Logical channel  */
  while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId != Channel)&&
        (IntCh != (Lin_kConfigPtr->NoOfChannels - 1U)))
  {
    IntCh++;
  }

 }
  /* Check pointer validity */
  if ((RetVal == E_OK) && (PduInfoPtr == NULL_PTR))
  {
    /* Report to  DET */
    Det_ReportError(
                     (uint16)LIN_17_ASCLIN_MODULE_ID,
                     LIN_MODULE_INSTANCE,
                     LIN_SID_SENDFRAME,
                     LIN_E_PARAM_POINTER
                     );
    RetVal = E_NOT_OK;
  }
  /* Check for the channel state machine in Sleep state */
  else if ((RetVal == E_OK) &&
         (Lin_17_AscLin_ChannelInfo[IntCh].State == LIN_WAKEUP_WAIT_I))
  {
    /* Report to  DET */
    Det_ReportError(
                     (uint16)LIN_17_ASCLIN_MODULE_ID,
                     LIN_MODULE_INSTANCE,
                     LIN_SID_SENDFRAME,
                     LIN_E_STATE_TRANSITION
                     );
    RetVal = E_NOT_OK;
  }
  else
  {
    /* Dummy else */
  }
  #else
  RetVal = E_OK;
  while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId != Channel)&&
        (IntCh != (Lin_kConfigPtr->NoOfChannels - 1U)))
  {
    IntCh++;
  }
  #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */

  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  if (RetVal == E_OK)
  #endif
  {
    ChannelConfigPtr = &(Lin_kConfigPtr->ChannelConfigPtr[IntCh]);
    /* Extract the Hw module */
    HwUnit = ChannelConfigPtr->HwModule;

    CurStatus = Lin_17_AscLin_ChannelInfo[IntCh].State;

    /* Tx / Rx already in progress */
    if (CurStatus == LIN_SEND_HEADER_I)
    {
      /* RE-initialise the Hw Module */
      Lin_lHwDeInitAscLin(HwUnit);
      Lin_lHwInit(HwUnit, ChannelConfigPtr->TimingConfig,
                     ChannelConfigPtr->RxAlternatePinSelect);
    }

    /* No need to protect the global variables here since
       Either there is no previous transmission OR
       it's been cancelled and hw  re-initilised */

    /* Copy PDU parmaeters in Lin_Channel_Info */
    Lin_17_AscLin_ChannelInfo[IntCh].Dl = PduInfoPtr->Dl;
    Lin_17_AscLin_ChannelInfo[IntCh].Cs = PduInfoPtr->Cs;
    Lin_17_AscLin_ChannelInfo[IntCh].Pid = PduInfoPtr->Pid;
    Lin_17_AscLin_ChannelInfo[IntCh].Drc = PduInfoPtr->Drc;

    /* Copy the data to local buffer */
    #ifdef VALEO_PATCH_MCAL_LIN_FIX_SDR_PTR_ACCESS
	 if (LIN_MASTER_RESPONSE == Lin_17_AscLin_ChannelInfo[Channel].Drc )
    #endif /* VALEO_PATCH_MCAL_LIN_FIX_SDR_PTR_ACCESS */
    {
      Index = 0U;
      DataPtr = PduInfoPtr->SduPtr;
      do
      {
        Lin_ResponseBuffer[IntCh][Index] = *DataPtr;
        DataPtr++;
        Index++;
      }while (Index < Lin_17_AscLin_ChannelInfo[IntCh].Dl);
    }

    /* Start the Frame Transmission */
    Lin_lHwStartTransmission(HwUnit, IntCh);
    Lin_17_AscLin_ChannelInfo[IntCh].State = LIN_SEND_HEADER_I;
  }
  return (RetVal);
}


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_LIN035_LIN037,
DS_AS403_LIN089_LIN166,
DS_AS_LIN073_LIN074_LIN129_LIN131_LIN132_LIN172_LIN033_1_LIN034_1_LIN237]
** Syntax : Std_ReturnType Lin_17_AscLin_GoToSleep( uint8 Channel )           **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Asynchonous                                                   **
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
** Description :    The service instructs the driver to transmit a            **
**               go-to-sleep-command on the addressed LIN channel             **
**                                                                            **
*******************************************************************************/
Std_ReturnType Lin_17_AscLin_GoToSleep(uint8 Channel)
{
  const Lin_17_AscLin_ChannelType   *ChannelConfigPtr;
  Lin_IntStatusType CurStatus;
  uint8 HwUnit;
  Std_ReturnType  RetVal;
  uint8 Index;
  uint8 IntCh = 0U;


  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  /* if the channel, UnInit parameters is invalid */
  RetVal = Lin_lGetDetStatus(Channel,LIN_SID_GOTOSLEEP);
  if (RetVal == E_OK)
  {

 /* Extract the internal channel based on Logical channel  */
    while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId != 
    Channel) && (IntCh != (Lin_kConfigPtr->NoOfChannels - 1U)))
    {
      IntCh++;
    }
  }
  /* Check for the channel state machine in Sleep state */
  if ((RetVal == E_OK) && 
                  (Lin_17_AscLin_ChannelInfo[IntCh].State == LIN_WAKEUP_WAIT_I))
  {
    /* Report to  DET */
    Det_ReportError(
                     (uint16)LIN_17_ASCLIN_MODULE_ID,
                     LIN_MODULE_INSTANCE,
                     LIN_SID_GOTOSLEEP,
                     LIN_E_STATE_TRANSITION
                     );
    RetVal = E_NOT_OK;
  }
  #else
  RetVal = E_OK;
  while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId != Channel)&&
        (IntCh != (Lin_kConfigPtr->NoOfChannels - 1U)))
  {
    IntCh++;
  }
  #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */

  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  if (RetVal == E_OK)
  #endif
  {
    ChannelConfigPtr = &(Lin_kConfigPtr->ChannelConfigPtr[IntCh]);
    /* Extract HwUnit */
    HwUnit = ChannelConfigPtr->HwModule;

    CurStatus = Lin_17_AscLin_ChannelInfo[IntCh].State;

    /* Tx / Rx in progress */
    if (CurStatus == LIN_SEND_HEADER_I)
    {
      /* RE-initialise the Hw Module */
      Lin_lHwDeInitAscLin(HwUnit);
      Lin_lHwInit(HwUnit, ChannelConfigPtr->TimingConfig,
                            ChannelConfigPtr->RxAlternatePinSelect);
    }

    /* No need to protect the global variables here since
       Either there is no previous transmission OR
       it's been cancelled and hw  re-initilised */

    /* Update Lin_Channel_Info with Sleep command */
    Lin_17_AscLin_ChannelInfo[IntCh].Dl = LIN_SLEEPCMD_DL;
    Lin_17_AscLin_ChannelInfo[IntCh].Cs = LIN_CLASSIC_CS ;
    Lin_17_AscLin_ChannelInfo[IntCh].Pid = LIN_SLEEPCMD_PID;
    Lin_17_AscLin_ChannelInfo[IntCh].Drc = LIN_MASTER_RESPONSE;

    /* Sleep data */
    Lin_ResponseBuffer[IntCh][0U] = LIN_SLEEPCMD_DATA0;
    for(Index = 1U; Index < LIN_SLEEPCMD_DATLEN; Index++)
    {
      Lin_ResponseBuffer[IntCh][Index] = LIN_SLEEPCMD_DATA1TO7;
    }

    /* Start the Sleep Frame Transmission.
       Since sleep frame transmission is internal to Driver,
       Configure to send both header and response at one shot.
    */
    Lin_lHwStartTransmission(HwUnit, IntCh);

    /* Update the state variables. */
    Lin_17_AscLin_ChannelInfo[IntCh].State = LIN_SEND_HEADER_I;
    Lin_17_AscLin_ChannelInfo[IntCh].Sleep = (uint8)LIN_SLEEP_REQ;
  }
  return (RetVal);
}

/*******************************************************************************
** Traceability : [cover parentID=
   DS_AS_LIN033_2_LIN034_2_LIN095_LIN133_LIN135_LIN136_LIN237,
   DS_AS_LIN167_LIN222
]               **
** Syntax : Std_ReturnType Lin_17_AscLin_GoToSleepInternal( uint8 Channel )   **
** [/cover]                                                                   **
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
Std_ReturnType Lin_17_AscLin_GoToSleepInternal( uint8 Channel )
{
  const Lin_17_AscLin_ChannelType   *ChannelConfigPtr;
  uint8 HwUnit;
  Std_ReturnType  RetVal;
  uint8 IntCh = 0U;


  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  /* if the channel, UnInit parameters is invalid */
  RetVal = Lin_lGetDetStatus(Channel,LIN_SID_GOTOSLEEPINTERNAL);

  if (RetVal == E_OK)
  {
  /* Extract the internal channel based on Logical channel  */
    while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId !=        \
        Channel)&& (IntCh != (Lin_kConfigPtr->NoOfChannels - 1U)))
    {
      IntCh++;
    }
  }
  /* Check for the channel state machine in Sleep state */
  if ((RetVal == E_OK) && 
                 (Lin_17_AscLin_ChannelInfo[IntCh].State == LIN_WAKEUP_WAIT_I))
  {
    /* Report to  DET */
    Det_ReportError(
                     (uint16)LIN_17_ASCLIN_MODULE_ID,
                     LIN_MODULE_INSTANCE,
                     LIN_SID_GOTOSLEEPINTERNAL,
                     LIN_E_STATE_TRANSITION
                     );
    RetVal = E_NOT_OK;
  }
  #else
  RetVal = E_OK;
  /* Extract the internal channel based on Logical channel  */
  while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId != Channel)&&
        (IntCh != (Lin_kConfigPtr->NoOfChannels - 1U)))
  {
    IntCh++;
  }
  #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */

  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  if (RetVal == E_OK)
  #endif
  {
    ChannelConfigPtr = &(Lin_kConfigPtr->ChannelConfigPtr[IntCh]);

    /* Extract HwUnit */
    HwUnit = ChannelConfigPtr->HwModule;

    /* Clear Pending Intr and Disable them in FLAGSEN and SRC register */
    Lin_lHwDisableAscLinIntr(HwUnit);

    /* Change LIN Rx state to LIN_WAKEUP_WAIT */
    Lin_17_AscLin_ChannelInfo[IntCh].State = LIN_WAKEUP_WAIT_I;
    #if (LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT == STD_ON)
    if (LIN_CHANNEL_WAKEUP_ENABLED == (ChannelConfigPtr->Wakeup))
    {
      /* Configure the timings for wakeup detection */
      Lin_lHwConfigWakeup(HwUnit,
          ChannelConfigPtr->TimingConfig.HwWakeupIocrDepth,
          ChannelConfigPtr->TimingConfig.HwWakeupBitconPrescalar);
    }
    #endif
    Lin_17_AscLin_ChannelInfo[IntCh].Sleep = (uint8)LIN_SLEEP_REQ;
  }
  return (RetVal);
}

/*******************************************************************************
** Traceability : [cover parentID=
   DS_AS_LIN043_LIN137_LIN139_LIN140_LIN174_LIN209_LIN237_LIN212,
   DS_AS403_LIN169, DS_NAS_PR770_2,DS_AS403_LIN090
   ]                                                                          **
** Syntax : Std_ReturnType Lin_17_AscLin_Wakeup( uint8 Channel )              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:      7                                                         **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      non reentrant                                             **
**                                                                            **
** Parameters (in): Channel    : LIN channel to be addressed                  **
**                                                                            **
** Parameters (out):none                                                      **
**                                                                            **
** Return value:    E_OK     :Wake-up request has been accepted               **
**                  E_NOT_OK :Wake-up request has not been accepted,          **
**                            development or production error occurred        **
**                                                                            **
** Description :    The service function Lin_WakeUp generates a wakeup pulse  **
**                  on the addressed LIN channel                              **
**                                                                            **
**     Note :       The LIN channel shall be in the LIN_CH_SLEEP state when   **
**                  this service will be called.                              **
*******************************************************************************/
Std_ReturnType Lin_17_AscLin_Wakeup(uint8 Channel)
{
  const Lin_17_AscLin_ChannelType   *ChannelConfigPtr;
  uint8 HwUnit;
  Std_ReturnType  RetVal;
  uint8 WakeupVal;
  uint8 IntCh = 0U;


  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  /* if the channel, UnInit parameters is invalid */
  RetVal = Lin_lGetDetStatus(Channel,LIN_SID_WAKEUP);
  if (RetVal == E_OK)
  {
  /* Extract the internal channel based on Logical channel  */
    while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId != 
                     Channel) && (IntCh != (Lin_kConfigPtr->NoOfChannels - 1U)))
    {
      IntCh++;
    }
  }
  /* Check for the channel state machine in Sleep state */
  if ((RetVal == E_OK)&&
               (!(Lin_17_AscLin_ChannelInfo[IntCh].State == LIN_WAKEUP_WAIT_I)))
  {
    /* Report to  DET */
    Det_ReportError(
                     (uint16)LIN_17_ASCLIN_MODULE_ID,
                     LIN_MODULE_INSTANCE,
                     LIN_SID_WAKEUP,
                     LIN_E_STATE_TRANSITION
                     );
    RetVal = E_NOT_OK;

  }
  #else
  RetVal = E_OK;
  /* Extract the internal channel based on Logical channel  */
  while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId != Channel)&&
        (IntCh != (Lin_kConfigPtr->NoOfChannels - 1U)))
  {
    IntCh++;
  }
  #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */

  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  if (RetVal == E_OK)
  #endif
  {
    /* Change LIN state to LIN_CH_INIT_I */
    Lin_17_AscLin_ChannelInfo[IntCh].State = LIN_CH_INIT_I;
    Lin_17_AscLin_ChannelInfo[IntCh].Sleep = (uint8)LIN_SLEEP_NOT_REQ;

    ChannelConfigPtr = &(Lin_kConfigPtr->ChannelConfigPtr[IntCh]);

    /* Extract Hw Module */
    HwUnit = ChannelConfigPtr->HwModule;

    WakeupVal =  ChannelConfigPtr->HwWakeupVal;
    #if (LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT == STD_ON)
    if (LIN_CHANNEL_WAKEUP_ENABLED == (ChannelConfigPtr->Wakeup))
    {
      /* Configure the timings after the wakeup detection/generation */
      Lin_lHwConfigAfterWakeup(HwUnit);
    }
    #endif

    Lin_lHwSendWakeupPulse(HwUnit,WakeupVal );
    Lin_lHwEnableAscLinIntr(HwUnit);
  }
  return (RetVal);
}

/*******************************************************************************
** Traceability : [cover parentID=
DS_AS403_LIN168, 
DS_AS_LIN022_LIN091_LIN141_LIN143_LIN144_LIN211_LIN024_2_LIN238,
DS_NAS_PR770_1,DS_AS403_LIN092_LIN144
]
** Syntax : Lin_StatusType Lin_17_AscLin_GetStatus
                                           ( uint8 Channel, uint8 **LinSduPtr)**
** [/cover]                                                                   **
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
**                  LIN_SLEEP : Sleep mode operation; in this mode wake-up    **
**                                 detection from slave nodes is enabled      **
**                  LIN_TX_HEADER_TIMEOUT_ERROR : Header timeout occured      **
**                  LIN_RX_RESPONSE_TIMEOUT_ERROR : Response timeout occured  **
**                                                                            **
** Description :    Indicates the current transmission, reception or          **
**                  operation status of the LIN driver                        **
**                                                                            **
**                  If a SDU has been successfully received, the SDU          **
**                  will be stored in a shadow buffer or memory mapped LIN    **
**                  Hardware receive buffer referenced by Lin_SduPtr.         **
**                  The buffer will only be valid and must be read until the  **
**                  next Lin_17_AscLin_SendFrame function call.               **
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
Lin_StatusType Lin_17_AscLin_GetStatus( uint8 Channel, uint8 **LinSduPtr )
{
  Lin_StatusType  Status;
  Lin_IntStatusType    CurrentState;
  const Lin_17_AscLin_ChannelType   *ChannelConfigPtr;
  uint8 HwUnit;
  uint8 FifoValue;
  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType   DetStatus;
  #endif
  uint8 IntCh = 0U;


  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  /* if the channel, UnInit parameters is invalid */
  DetStatus = Lin_lGetDetStatus(Channel,LIN_SID_GETSTATUS);

  /* Check for the channel state machine in Sleep state */
  if ((DetStatus == E_OK) &&(LinSduPtr == NULL_PTR))
  {
    /* Report to  DET */
    Det_ReportError(
                     (uint16)LIN_17_ASCLIN_MODULE_ID,
                     LIN_MODULE_INSTANCE,
                     LIN_SID_GETSTATUS,
                     LIN_E_PARAM_POINTER
                     );
    Status = LIN_NOT_OK;
  }
  else if (DetStatus != E_OK)
  {
    Status = LIN_NOT_OK;
  }
  else
  {
    Status = LIN_TX_BUSY;
  }
  #else
    /* Initialize the return status to LIN_TX_BUSY */
  Status = LIN_TX_BUSY;
  #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */

#if (LIN_DEV_ERROR_DETECT == STD_ON)
  if(Status != LIN_NOT_OK)
#endif
  {
    /* Extract the internal channel based on Logical channel  */
    while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId != Channel)
     && (IntCh != (Lin_kConfigPtr->NoOfChannels - 1U)))
    {
      IntCh++;
    }
  }
  #if (LIN_DEV_ERROR_DETECT == STD_ON)
  if (Status != LIN_NOT_OK)
  #endif
  {
    /* Extract HwUnit */
    ChannelConfigPtr = &(Lin_kConfigPtr->ChannelConfigPtr[IntCh]);

    HwUnit = ChannelConfigPtr->HwModule;

    CurrentState = Lin_17_AscLin_ChannelInfo[IntCh].State;

    switch(CurrentState)
    {
      case LIN_MASTER_TX_COMPLETE_I:
      {
        /* Successful transmission */
        Status = LIN_TX_OK;
        break;
      }
      case LIN_WAKEUP_WAIT_I:
      {
        /* Lin is in Sleep */
        Status = LIN_CH_SLEEP;
        break;
      }
      case LIN_RECEIVE_COMPLETE_I:
      {
        /* Successful reception */
        Status = LIN_RX_OK;
        /* Assign the receive buffer pointer */
        *LinSduPtr = Lin_ResponseBuffer[IntCh];
        break;
      }
      case LIN_TX_HEADER_ERROR_I:
      {
        /* erroneous header transmission */
        Status = LIN_TX_HEADER_ERROR;
        break;
      }
      case LIN_TX_ERROR_I:
      {
        /* Erroneous transmission */
        Status = LIN_TX_ERROR;
        break;
      }
      case LIN_RX_ERROR_I:
      {
        /* Erroneous reception */
        Status = LIN_RX_ERROR;
        break;
      }

#ifdef LIN_17_TIMEOUT_SUPPORT
      case LIN_TX_HEADER_TIMEOUT_ERROR_I:
      {
        /* Header Timeout occured */
        Status = LIN_TX_HEADER_TIMEOUT_ERROR;
        break;
      }
      case LIN_RESPONSE_TIMEOUT_ERROR_I:
      {
        /* Response Timeout occured */
        Status = LIN_RX_RESPONSE_TIMEOUT_ERROR;
        break;
      }
#endif
      /* For AS4.x  LIN_SEND_RESPONSE_I is not available
        as Header + response are configured at one shot */
      case LIN_SEND_HEADER_I:
      {
          FifoValue = Lin_lHwGetRxFifoFillValue(HwUnit);
          if (LIN_RXFIFOVAL_IDONLY < FifoValue)
          {
            /* ID + atleast 1 response data byte received */
            Status = LIN_RX_BUSY;
          }
          else if (LIN_RXFIFOVAL_IDONLY == FifoValue )
          {
            /* Only ID received. No response data byte received */
            Status = LIN_RX_NO_RESPONSE;
          }
          else
          { /* Empty Else */
          }
        
        break;
      }
      default:
      {
        /* Default case is Normal operation */
        Status = LIN_OPERATIONAL;
        break;
      }

    }
  }
  return (Status);
}
/*******************************************************************************
** Traceability : [cover parentID=
   DS_AS_LIN024_1_LIN028_LIN060_LIN155_1_LIN157_1]
** Syntax :          void Lin_17_AscLin_IsrReceive( uint8  HwUnit)            **
** [/cover]                                                                   **
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
** Description :     This ISR will be called whenever the Slave response data **
**                   is completely received by the ASCLIN w/o any errors      **
**                                                                            **
*******************************************************************************/
void Lin_17_AscLin_IsrReceive(uint8  HwUnit)
{
  uint8  *RespPtr;
  uint8 Channel;

  /* Extract the Channel */
  Channel = Lin_BusStatus[HwUnit];
  /* copy the Response buffer pointer to local variable */
  RespPtr = Lin_ResponseBuffer[Channel];

  /* Read the Data from Rx FIFO */
  Lin_lHwReadRxFifo(HwUnit, RespPtr, Lin_17_AscLin_ChannelInfo[Channel].Dl);
  /* Flush the RX, TX FIFOs */
  Lin_lHwFlushTxFifo(HwUnit);
  Lin_lHwFlushRxFifo(HwUnit);
  /* Disable the interrupt FLAGS */
  Lin_lHwDisableAllIntrFlags(HwUnit);
  /* Update the state */
  Lin_17_AscLin_ChannelInfo[Channel].State = LIN_RECEIVE_COMPLETE_I;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_LIN155_2_LIN157_2]
** Syntax :          void Lin_17_AscLin_IsrTransmit( uint8  HwUnit)           **
** [/cover]                                                                   **
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
void Lin_17_AscLin_IsrTransmit(uint8  HwUnit)
{
  #if (LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT == STD_ON)
  const Lin_17_AscLin_ChannelType   *ChannelConfigPtr;
  #endif
  uint8 Channel;

  /* Extract the Channel */
  Channel = Lin_BusStatus[HwUnit];

  /* Flush the RX, TX FIFOs */
  Lin_lHwFlushTxFifo(HwUnit);
  Lin_lHwFlushRxFifo(HwUnit);
  /* Disable the interrupt FLAGS */
  Lin_lHwDisableAllIntrFlags(HwUnit);

  if (Lin_17_AscLin_ChannelInfo[Channel].Sleep != (uint8)LIN_SLEEP_REQ)
  {
    /* If the Sleep is Not requested,
        then update the state to Transmit completed */
    Lin_17_AscLin_ChannelInfo[Channel].State = LIN_MASTER_TX_COMPLETE_I;
  }
  else
  {
    /* If the Sleep is requested,then
       Update the state and Disable the Interrupts in SRC register. */
    Lin_17_AscLin_ChannelInfo[Channel].State = LIN_WAKEUP_WAIT_I;
    Lin_lHwDisableAscLinIntr(HwUnit);
    #if (LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT == STD_ON)
    ChannelConfigPtr = &(Lin_kConfigPtr->ChannelConfigPtr[Channel]);
    if (LIN_CHANNEL_WAKEUP_ENABLED == (ChannelConfigPtr->Wakeup))
    {
      /* Configure the timings for wakeup detection */
      Lin_lHwConfigWakeup(HwUnit,
          ChannelConfigPtr->TimingConfig.HwWakeupIocrDepth,
          ChannelConfigPtr->TimingConfig.HwWakeupBitconPrescalar);
    }
    #endif
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_LIN155_3_LIN157_3_LIN220,
   DS_AS403_LIN173_LIN176_LIN239_LIN240,

]
** Syntax :          void Lin_17_AscLin_IsrError( uint8  HwUnit)              **
** [/cover]                                                                   **
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
**                   transmission or reception error
**                   or a wakeup interrupt in ASCLIN                **
*******************************************************************************/
void Lin_17_AscLin_IsrError(uint8 HwUnit)
{
  #if (LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT == STD_ON)
  const Lin_17_AscLin_ChannelType   *ChannelConfigPtr;
  #endif
  uint32 HwErrorFlags;
  uint8 Channel;

  /* Extract the Channel */
  Channel = Lin_BusStatus[HwUnit];

  HwErrorFlags = Lin_lHwGetFlags(HwUnit);

  /* Flush the RX, TX FIFOs */
  Lin_lHwFlushTxFifo(HwUnit);
  Lin_lHwFlushRxFifo(HwUnit);
  /* Disable the interrupt FLAGS */
  Lin_lHwDisableAllIntrFlags(HwUnit);

  /* if Channel has NOT requested Sleep */
  if (Lin_17_AscLin_ChannelInfo[Channel].Sleep != (uint8)LIN_SLEEP_REQ)
  {
    /* Get the Error Status and update internal state */
    Lin_17_AscLin_ChannelInfo[Channel].State =                           \
                                     Lin_lGetIntErrorStatus(HwErrorFlags);
  }
  else
  {
    /* Wakeup intr (no error) */
    if ( (Lin_17_AscLin_ChannelInfo[Channel].State == LIN_WAKEUP_WAIT_I) &&
           ((HwErrorFlags & LIN_ASCLIN_FLAGSREG_FED ) != 0U))
    {
      #if (LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT == STD_ON)
      ChannelConfigPtr = &(Lin_kConfigPtr->ChannelConfigPtr[Channel]);
      /* Configure the timings after the wakeup detection */
      Lin_lHwConfigAfterWakeup(HwUnit);
      EcuM_CheckWakeup((uint32)1U << (ChannelConfigPtr->WakeupSourceId));
      #else
      /* Change LIN state to LIN_CH_INIT_I */
      Lin_17_AscLin_ChannelInfo[Channel].State = LIN_CH_INIT_I;
      #endif
      Lin_17_AscLin_ChannelInfo[Channel].Sleep = (uint8)LIN_SLEEP_NOT_REQ;
      Lin_lHwEnableAscLinIntr(HwUnit);

    }
    else
    {
      /* Update the state to wakeup wait and
         Disable the Interrupts in SRC register. */
      Lin_17_AscLin_ChannelInfo[Channel].State = LIN_WAKEUP_WAIT_I;
      Lin_lHwDisableAscLinIntr(HwUnit);

      #if (LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT == STD_ON)
      ChannelConfigPtr = &(Lin_kConfigPtr->ChannelConfigPtr[Channel]);
      /* Configure the timings for wakeup detection */
      Lin_lHwConfigWakeup(HwUnit,
          ChannelConfigPtr->TimingConfig.HwWakeupIocrDepth,
          ChannelConfigPtr->TimingConfig.HwWakeupBitconPrescalar);
      #endif
    }
  }
}

/*******************************************************************************
** Syntax           : _INLINE_ Lin_IntStatusType                              **
**                            Lin_lGetIntErrorStatus(uint32 HwErrorFlags)     **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwErrorFlags   : Hw error FLAGS as given by ASCLIN      **
**                                                                            **
** Parameters (out) : Lin_IntStatusType: Internal Status information          **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function returns the internal status information   **
**                   based on the asclin hw error flags register.             **
**                                                                            **
*******************************************************************************/
_INLINE_ Lin_IntStatusType Lin_lGetIntErrorStatus(uint32 HwErrorFlags)
{
  Lin_IntStatusType Status;

  /* Check for the header error. */
  /* Header Error: (Transmit header not completed) AND
     (Collision detected OR Tx-FIFO overflow OR Parity Error) */
  if ((((HwErrorFlags & ((uint32)LIN_ASCLIN_FLAGSREG_TH)) != 1U) &&
        ((HwErrorFlags & (LIN_ASCLIN_FLAGSREG_CE | LIN_ASCLIN_FLAGSREG_TFO |
        LIN_ASCLIN_FLAGSREG_LP)) != 0U) ) )
  {
    Status = LIN_TX_HEADER_ERROR_I;
  }
  /* Check for the header timeout error. */
  else if ((HwErrorFlags & LIN_ASCLIN_HEADER_TIMEOUT_ERR) != 0U)
  {
#ifdef LIN_17_TIMEOUT_SUPPORT
    Status = LIN_TX_HEADER_TIMEOUT_ERROR_I;
#else
    Status = LIN_TX_HEADER_ERROR_I;
#endif
  }
  /* Check for the transmit error. */
  /* Transmit Error:(Transmit header completed) AND
     (Collision detected OR Tx FIFO overflow) */
  else if (((HwErrorFlags & LIN_ASCLIN_FLAGSREG_TH) != 0U) &&
          ((HwErrorFlags & (LIN_ASCLIN_FLAGSREG_CE | LIN_ASCLIN_FLAGSREG_TFO))
            != 0U) )
  {
    Status = LIN_TX_ERROR_I;
  }
  /* Check for the receive error. */
  /* Receive Error:(Transmit header completed) AND
     (Checksum Error OR Rx-FIFO overflow/Underflow OR Framing Error) */
  else if (((HwErrorFlags & LIN_ASCLIN_FLAGSREG_TH) != 0U) &&
           ((HwErrorFlags & (LIN_ASCLIN_FLAGSREG_LC | LIN_ASCLIN_FLAGSREG_RFO |
            LIN_ASCLIN_FLAGSREG_RFU | LIN_ASCLIN_FLAGSREG_FE)) != 0U)
           )
  {
    Status = LIN_RX_ERROR_I;
  }
  /* Check for the response timeout error. */
  else if ((HwErrorFlags & LIN_ASCLIN_RESP_TIMEOUT_ERR) != 0U)
  {
#ifdef LIN_17_TIMEOUT_SUPPORT
    Status = LIN_RESPONSE_TIMEOUT_ERROR_I;
#else
    Status = LIN_RX_ERROR_I;
#endif
  }
  else
  {   /* No Error */
    Status = LIN_CH_INIT_I;
  }

  return (Status);
}
/*******************************************************************************
** Syntax : static _INLINE_ uint8 Lin_lGetDetStatus                           **
**         (                                                                  **
**           uint8 Channel,                                                   **
**           uint8 ApiId                                                      **
**         )                                                                  **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant (for different channel Ids)                        **
**                                                                            **
** Parameters (in) :   Channel - ChannelId                                    **
**                     ApiId - API ID                                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Returns DET status, E_OK or E_NOT_OK                     **
**                                                                            **
** Description : This Function returns the status of DET check                **
**                                                                            **
*******************************************************************************/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
static _INLINE_ Std_ReturnType Lin_lGetDetStatus(uint8 Channel, uint8 ApiId)
{
  Std_ReturnType ReturnStatus;
  uint8 MaxChannel;
  uint8 IntCh = 0U;

  ReturnStatus = E_OK;

  /* Check for LIN module initialization */
  if (Lin_InitStatus != LIN_INTIALISED)
  {
    /* Report to  DET */
    Det_ReportError(
                     (uint16)LIN_17_ASCLIN_MODULE_ID,
                     LIN_MODULE_INSTANCE,
                     ApiId,
                     LIN_E_UNINIT
                     );
    ReturnStatus = E_NOT_OK;
  }

  if (ReturnStatus == E_OK)
  {
    MaxChannel = Lin_kConfigPtr->NoOfChannels;

    /* Extract the internal channel based on Logical channel  */
    while((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId !=       \
                                      Channel)&& (IntCh != (MaxChannel - 1U)))
    {
      IntCh++;
    }
    /* check if logical channel Id of last Internal channelno doesn't Match 
    the Channel Id passed*/
    if ((Lin_kConfigPtr->ChannelConfigPtr[IntCh].LogicalChannelId != Channel)&&
        (IntCh == (MaxChannel - 1U)))
    {
        /* Report to  DET */
        Det_ReportError(
                         (uint16)LIN_17_ASCLIN_MODULE_ID,
                         LIN_MODULE_INSTANCE,
                         ApiId,
                         LIN_E_INVALID_CHANNEL
                         );
        ReturnStatus = E_NOT_OK;
    }
  }

  return (ReturnStatus);
}
#endif /*(LIN_DEV_ERROR_DETECT == STD_ON)*/

/*******************************************************************************
** Syntax           : _INLINE_ void                                           **
**                            Lin_lHwFlushTxFifo(uint8 HwUnit)                **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function flushes the transmit fifo.                **
**                                                                            **
*******************************************************************************/
_INLINE_ void Lin_lHwFlushTxFifo(uint8 HwUnit)
{
  Ifx_ASCLIN*  HwModulePtr;
  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);
  /* Flush the TX FIFO */
  HwModulePtr->TXFIFOCON.B.FLUSH = LIN_ENABLE_FLAG;
}
/*******************************************************************************
** Syntax           : _INLINE_ void                                           **
**                            Lin_lHwFlushRxFifo(uint8 HwUnit)                **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function flushes the receive fifo.                 **
**                                                                            **
*******************************************************************************/
_INLINE_ void Lin_lHwFlushRxFifo(uint8 HwUnit)
{
  Ifx_ASCLIN*  HwModulePtr;
  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);
  /* Flush the RX FIFO */
  HwModulePtr->RXFIFOCON.B.FLUSH = LIN_ENABLE_FLAG;
}

/*******************************************************************************
** Syntax           : _INLINE_ void                                           **
**                            Lin_lHwDisableAllIntrFlags(uint8 HwUnit)        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function clears & disables all the interrupt       **
**                    event triggers in ASCLIN                                **
*******************************************************************************/
_INLINE_ void Lin_lHwDisableAllIntrFlags(uint8 HwUnit)
{
  Ifx_ASCLIN*  HwModulePtr;
  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);

  /* Clear and disable all intr in FlagsEnable register */
  HwModulePtr->FLAGSCLEAR.U =
     LIN_ASCLIN_FLAGSCLEAR_MS_TX | LIN_ASCLIN_FLAGSCLEAR_MS_RX |
               LIN_ASCLIN_FLAGSCLEAR_MS_HO ;
  HwModulePtr->FLAGSENABLE.U = 0x00000000U;
}

/*******************************************************************************
** Syntax           : _INLINE_ void Lin_lHwReadRxFifo                         **
**                      (uint8 HwUnit, uint8 *Ptr, uint8 count)               **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwModule   : ASCLIN Hardware module no                  **
**                 Ptr : receive buffer pointer where data to be copied to    **
**                 count : no of bytes to be transfered                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function copies the data from the ASCLIN hardware  **
**                    rx fifo to the specified buffer with the given count    **
*******************************************************************************/
_INLINE_ void Lin_lHwReadRxFifo(uint8 HwUnit, volatile uint8 *Ptr, uint8 count)
{
  Ifx_ASCLIN*  HwModulePtr;

  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);
  *Ptr = (uint8)HwModulePtr->RXDATA.U;

  /* Copy the RX FIFO data to the given buffer */
  while(count != 0U)
  {
    *Ptr = (uint8)HwModulePtr->RXDATA.U;
    Ptr++;
    count--;
  }
}
/*******************************************************************************
** Syntax           : _INLINE_ uint32                                         **
**                      Lin_lHwGetFlags (uint8 HwUnit)                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : ASCLIN FLAGS regsiter                                   **
**                                                                            **
** Description      : This function returns the flags register                **
*******************************************************************************/
_INLINE_ uint32 Lin_lHwGetFlags(uint8 HwUnit)
{
  Ifx_ASCLIN*  HwModulePtr;
  uint32 Flags;
  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);
  Flags = HwModulePtr->FLAGS.U;
  return Flags;
}

/*******************************************************************************
** Syntax           : _INLINE_ void Lin_lHwSendWakeupPulse                    **
**                      (uint8 HwUnit, uint8 WakeupVal)                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                    WakeupVal : wakeup pulse value                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function sends the wakeup pulse with the           **
**                    time duration given by wakeup val                       **
*******************************************************************************/
_INLINE_ void Lin_lHwSendWakeupPulse(uint8 HwUnit, uint8 WakeupVal)
{
  Ifx_ASCLIN*  HwModulePtr;
  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);

  /* update the Wakeup pulse time duration in TX data  */
  HwModulePtr->TXDATA.U = WakeupVal;
  /* Set the Transmit wakeup pulse request bit */
  HwModulePtr->FLAGSSET.B.TWRQS = LIN_ENABLE_FLAG;
}

/*******************************************************************************
** Syntax           : static void Lin_lHwEnableAscLinIntr                     **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and enables the TX, RX, Err        **
**                    interrupts in SRC registers.
*******************************************************************************/
static void Lin_lHwEnableAscLinIntr(uint8 HwUnit)
{
  Ifx_SRC_SRCR_Bits IntrSrc;
  uint32 Offset;

  Offset = (uint32)HwUnit * LIN_ASCLIN_SRC_ADDROFFSET ;

  IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0TXADDR  +
                                     (Offset));
  IntrSrc.CLRR = 1U;
  IntrSrc.SWSCLR = 1U;
  IntrSrc.IOVCLR = 1U;
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0TXADDR +
                    Offset) = IntrSrc;

  IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0TXADDR  +
                                     (Offset));
  IntrSrc.SRE = 1U; /*  Enable intr */
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0TXADDR +
                    Offset) = IntrSrc;


  IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0RXADDR  +
                                     Offset );
  IntrSrc.CLRR = 1U;
  IntrSrc.SWSCLR = 1U;
  IntrSrc.IOVCLR = 1U;
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0RXADDR +
                    Offset) = IntrSrc;

  IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0RXADDR  +
                                     Offset );
  IntrSrc.SRE = 1U; /*  Enable intr */
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0RXADDR +
                    Offset) = IntrSrc;

  IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0ERRADDR  +
                                     Offset);
  IntrSrc.CLRR = 1U;
  IntrSrc.SWSCLR = 1U;
  IntrSrc.IOVCLR = 1U;
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0ERRADDR +
                    Offset) = IntrSrc;

  IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0ERRADDR  +
                                     Offset);
  IntrSrc.SRE = 1U; /*  Enable intr */
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0ERRADDR +
                    Offset) = IntrSrc;

}

/*******************************************************************************
** Syntax           : _INLINE_ void Lin_lHwDisableAscLinIntr                  **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and disables the TX, RX, Err       **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Lin_lHwDisableAscLinIntr(uint8 HwUnit)
{
  Ifx_SRC_SRCR_Bits IntrSrc;
  uint32 Offset;

  Offset = (uint32)HwUnit * LIN_ASCLIN_SRC_ADDROFFSET ;

  IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0TXADDR  +
                                     Offset);
  IntrSrc.CLRR = 1U;
  IntrSrc.SRE = 0U; /*  Disable intr */
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0TXADDR +
                    Offset) = IntrSrc;

  IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0RXADDR  +
                                     Offset);
  IntrSrc.CLRR = 1U;
  IntrSrc.SRE = 0U; /*  Disable intr */
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0RXADDR +
                    Offset) = IntrSrc;

  IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0ERRADDR  +
                                     Offset);
  IntrSrc.CLRR = 1U;
  IntrSrc.SRE = 0U; /*  Disable intr */
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0ERRADDR +
                    Offset) = IntrSrc;

}

/*******************************************************************************
** Syntax           : _INLINE_ uint8 Lin_lHwGetRxFifoFillValue                **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : recieve fifo fill value                                 **
**                                                                            **
** Description      : This function returns the Receive FIFO fill value       **
*******************************************************************************/
_INLINE_ uint8 Lin_lHwGetRxFifoFillValue(uint8 HwUnit)
{
  Ifx_ASCLIN*  HwModulePtr;
  uint8 Fifovalue;

  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);
  /* Read the RXFIFO FILL value from hw */
  Fifovalue = HwModulePtr->RXFIFOCON.B.FILL;
  return (Fifovalue);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS403_LIN084_2_LIN190_2]
** Syntax           : static void Lin_lHwInit                                 **
**                      (uint8 HwUnit,                                        **
   Lin_ChannelTimingConfigType TimingConfig, uint8 RxAlternatePinSelect)      **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                TimingConfig : Channel timing configuration parameter       **
**                RxAlternatePinSelect: Rx alternate pin selection            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function initialises the ASCLIN Hw module          **
*******************************************************************************/
static void Lin_lHwInit(uint8 HwUnit,Lin_ChannelTimingConfigType TimingConfig,
                uint8 RxAlternatePinSelect)
{
  Ifx_ASCLIN*  HwModulePtr;
  uint32 TimeOutCount ;

  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);
  
  /* Disable the Clock source. */
  HwModulePtr->CSR.B.CLKSEL = LIN_ASCLIN_CSRREG_CLKSEL_NOCLK;
  TimeOutCount = LIN_TIMEOUT_DURATION;
  /*Wait TW or poll for CSR.CON = 0*/
  while ((HwModulePtr->CSR.B.CON != 0U) && (TimeOutCount > 0U))
  {
    TimeOutCount-- ; 
  }

  /* Change to LIN mode */
  HwModulePtr->FRAMECON.B.MODE = LIN_ASCLIN_FRAMECON_INIT_MODE;
  /* Connect the Clock source */
  HwModulePtr->CSR.B.CLKSEL = LIN_ASCLIN_CSRREG_CLKSEL;
  TimeOutCount = LIN_TIMEOUT_DURATION;
  /* provide delay of TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /*Wait TW or poll for CSR.CON = 1*/
  while ((HwModulePtr->CSR.B.CON != 1U) && (TimeOutCount > 0U))
  {
    TimeOutCount-- ; 
  }

  /* Disable the Clock source. */
  HwModulePtr->CSR.B.CLKSEL = LIN_ASCLIN_CSRREG_CLKSEL_NOCLK;
  TimeOutCount = LIN_TIMEOUT_DURATION;
  /* provide delay of  TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  while ((HwModulePtr->CSR.B.CON != 0U) && (TimeOutCount > 0U))
  {
    TimeOutCount-- ; 
  }
  /* Change to LIN mode */
  HwModulePtr->FRAMECON.B.MODE = LIN_ASCLIN_FRAMECONREG_LIN_MODE;

  /* Lin mode is Master Mode */
  HwModulePtr->LIN.CON.B.MS = LIN_ASCLIN_LINCON_MASTER_ENABLE;
  /* Configure the Baudrate parameters */
  HwModulePtr->BRG.B.NUMERATOR = TimingConfig.HwBrgNumerator;
  HwModulePtr->BRG.B.DENOMINATOR = TimingConfig.HwBrgDenominator;
  HwModulePtr->BITCON.B.PRESCALER = TimingConfig.HwBitconPrescalar;
  HwModulePtr->BITCON.B.OVERSAMPLING = LIN_ASCLIN_BITCONREG_OS_VAL;
  /* Digital Glitch Filter = OFF */
  HwModulePtr->IOCR.B.DEPTH = LIN_ASCLIN_IOCRREG_DEPTH_VAL;
  /* Configure the Sample mode, Sample point, Parity, Collision detection */
  HwModulePtr->BITCON.B.SM = LIN_ASCLIN_BITCONREG_SM_VAL;
  HwModulePtr->BITCON.B.SAMPLEPOINT = LIN_ASCLIN_BITCON_SP_VAL;
  HwModulePtr->FRAMECON.B.PEN = LIN_ASCLIN_FRAMECONREG_PEN_VAL;
  HwModulePtr->FRAMECON.B.CEN = LIN_ASCLIN_FRAMECONREG_CEN_VAL;
  /* STOP bit = 1 */
  HwModulePtr->FRAMECON.B.STOP = LIN_ASCLIN_FRAMECONREG_STOP_VAL;
  /* LIN Break Timer */
  HwModulePtr->LIN.BTIMER.B.BREAK = LIN_ASCLIN_LINBTIMER_BREAK_VAL;
  /* LEAD val i.e delay b/w end of break and start of Sync character */
  HwModulePtr->FRAMECON.B.LEAD = LIN_ASCLIN_FRAMECONREG_LEAD_VAL;
  /* IDLE value i.e Interbyte space or response space */
  HwModulePtr->FRAMECON.B.IDLE = TimingConfig.InterByteResponseSpace;
  /* Hw checksum enable, Checksum  injection to Rx FIFO disable */
  HwModulePtr->LIN.CON.B.CSEN = LIN_ASCLIN_LINCONREG_CSEN_VAL;
  HwModulePtr->LIN.CON.B.CSI = LIN_ASCLIN_LINCONREG_CSI_VAL;
  /* Header Timeout = 48 bit times */
  HwModulePtr->LIN.HTIMER.B.HEADER = LIN_ASCLIN_LINHTIMER_HEADER_VAL;
  /* Configure the RX inlet, TX outlet width/s to 1 byte */
  HwModulePtr->TXFIFOCON.B.INW = LIN_ASCLIN_TXFIFOCONREG_INW_VAL;
  HwModulePtr->RXFIFOCON.B.OUTW = LIN_ASCLIN_RXFIFOCON_OUTW_VAL;

  HwModulePtr->IOCR.B.ALTI =  RxAlternatePinSelect; /* ALT1 used. */

  /* Connect the Clock source */
  HwModulePtr->CSR.B.CLKSEL = LIN_ASCLIN_CSRREG_CLKSEL;

  TimeOutCount = LIN_TIMEOUT_DURATION;
  /* provide delay of TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /*Wait TW or poll for CSR.CON = 1*/
  while ((HwModulePtr->CSR.B.CON != 1U) && (TimeOutCount > 0U))
  {
    TimeOutCount-- ; 
  }

  Lin_lHwEnableAscLinIntr(HwUnit);
}


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_LIN018_2_LIN019_LIN027]
** Syntax           : static void Lin_lHwStartTransmission                    **
**                      (uint8 HwUnit,                                        **
**                       uint8 Channel)                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                Channel : LIN Channel number                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function configures the ASCLIN hardware for        **
**                    Frame transmission.                                     **
*******************************************************************************/
static void Lin_lHwStartTransmission(uint8 HwUnit, uint8 Channel)
{
  Ifx_ASCLIN*  HwModulePtr;
  uint32 FrameTimeout;
  uint8 count;
  uint8 cntr;
  Lin_FrameResponseType LocalDrc;
  uint32 LocalPid;

  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);

  /* Calculate the Frame timeout value as per LIN2.1
     Frame Timeout =  Header Timeout + Response timeout
     Header Timeout = 34 * 1.4 = 47.6 (rounded to 48)
     Response timeout = (10 * (Datalength + 1)) * 1.4
                    = (datalength +1) * 10 * 1.4
                    = (datalength +1) * 14
     */
  FrameTimeout = ((Lin_17_AscLin_ChannelInfo[Channel].Dl + 1UL) * 14UL);

  FrameTimeout = FrameTimeout + 48UL ;

  /* Configure the data length, checksum , response timeout */
  HwModulePtr->DATCON.B.DATLEN = Lin_17_AscLin_ChannelInfo[Channel].Dl - 1U ;
  HwModulePtr->DATCON.B.CSM = (uint8)Lin_17_AscLin_ChannelInfo[Channel].Cs;
  HwModulePtr->DATCON.B.RESPONSE = (uint8)FrameTimeout;
  HwModulePtr->DATCON.B.RM = LIN_DISABLE_FLAG; /* Response mode = Frametype */

  /* Receive Buffer Mode = RXFIFO */
  HwModulePtr->RXFIFOCON.B.BUF = LIN_DISABLE_FLAG;

  HwModulePtr->RXFIFOCON.B.FLUSH = LIN_ENABLE_FLAG; /* Flush the Rx fifo */
  HwModulePtr->RXFIFOCON.B.ENI = LIN_DISABLE_FLAG; /* Disable the RX inlet */
  HwModulePtr->TXFIFOCON.B.FLUSH = LIN_ENABLE_FLAG; /* Flush the Tx fifo */

  /* Disable the Tx outlet b'fore the data entry */
  HwModulePtr->TXFIFOCON.B.ENO = LIN_DISABLE_FLAG;
  /* Clear all the Flags. */
  HwModulePtr->FLAGSCLEAR.U = LIN_ASCLIN_FLAGSCLEAR_VAL;

  /* Enable the appropriate interrupt Flags  */
  LocalDrc = Lin_17_AscLin_ChannelInfo[Channel].Drc;

  if (LIN_MASTER_RESPONSE == LocalDrc)
  {
    HwModulePtr->FLAGSENABLE.U = LIN_ASCLIN_FLAGS_MS_TX;
    HwModulePtr->DATCON.B.HO = LIN_DISABLE_FLAG;
  }
  else if (LIN_SLAVE_RESPONSE == LocalDrc)
  {
    HwModulePtr->FLAGSENABLE.U = LIN_ASCLIN_FLAGS_MS_RX;
    HwModulePtr->RXFIFOCON.B.ENI = LIN_ENABLE_FLAG;
    HwModulePtr->DATCON.B.HO = LIN_DISABLE_FLAG;
  }
  else
  {
    HwModulePtr->FLAGSENABLE.U = LIN_ASCLIN_FLAGS_MS_HO;
    HwModulePtr->DATCON.B.HO = LIN_ENABLE_FLAG;
  }

  /* Write ID to Tx Fifo.
    the Parity is masked out since the Hw generates the parity automatically */
  LocalPid = Lin_17_AscLin_ChannelInfo[Channel].Pid ;
  LocalPid &= LIN_PID_MASK_WO_PARITY;
  HwModulePtr->TXDATA.U =  LocalPid;


  /* Write Data bytes to Tx fifo in case of Master to Slave */
  if (Lin_17_AscLin_ChannelInfo[Channel].Drc == LIN_MASTER_RESPONSE)
  {
    count = Lin_17_AscLin_ChannelInfo[Channel].Dl;
    for (cntr = 0U; cntr < count; cntr++)
    {
      HwModulePtr->TXDATA.U = Lin_ResponseBuffer[Channel][cntr];
    }
  }

  /* Enable the Header Transmission */
  HwModulePtr->FLAGSSET.B.THRQS = LIN_ENABLE_FLAG ;
  
  /* Enable the Tx Outlet */
  HwModulePtr->TXFIFOCON.B.ENO = LIN_ENABLE_FLAG;

  /* Enable the Response transmission in case of Master to Slave  */
  if (Lin_17_AscLin_ChannelInfo[Channel].Drc == LIN_MASTER_RESPONSE)
  {
    HwModulePtr->FLAGSSET.B.TRRQS = LIN_ENABLE_FLAG ;
  }

}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS403_LIN021_2]
** Syntax           : static void Lin_lHwDeInitAscLin                         **
**                      (uint8 HwUnit)                                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function De-Initalises the ASCLIN and              **
**                    sets it to INIT mode.                                   **
*******************************************************************************/
static void Lin_lHwDeInitAscLin(uint8 HwUnit)
{
  Ifx_ASCLIN*  HwModulePtr;

  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);

  /* Disable the clock source, Change the mode to INIT
     and enable the clock source. */
  HwModulePtr->CSR.B.CLKSEL = LIN_ASCLIN_CSRREG_CLKSEL_NOCLK;
  HwModulePtr->FRAMECON.B.MODE = LIN_ASCLIN_FRAMECON_INIT_MODE;
  HwModulePtr->CSR.B.CLKSEL = LIN_ASCLIN_CSRREG_CLKSEL;

}

/*******************************************************************************
** Syntax           : _INLINE_ uint8 Lin_lHwGetRxDStatus                      **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Rx line pin level                                       **
**                                                                            **
** Description      : This function returns the Rx line pin level             **
*******************************************************************************/
_INLINE_ uint8 Lin_lHwGetRxDStatus(uint8 HwUnit)
{
  return LIN_HW_MODULE[HwUnit].IOCR.B.RXM ;
}

/*******************************************************************************
** Syntax           : _INLINE_ void Lin_lHwInitClcReg                         **
**                      (uint8 HwUnit, uint32 Value)                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function sets the clc register with given value    **
*******************************************************************************/
_INLINE_ void Lin_lHwInitClcReg(uint8 HwUnit, uint32 Value)
{
  volatile uint32 ReadBack;
  LIN_HW_MODULE[HwUnit].CLC.U = Value;
  ReadBack = LIN_HW_MODULE[HwUnit].CLC.U;
  UNUSED_PARAMETER(ReadBack)
}
#if (LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT == STD_ON)
/*******************************************************************************
** Syntax           : static void Lin_lHwConfigWakeup                         **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function configures the hardware for the wakeup    **
*******************************************************************************/
static void Lin_lHwConfigWakeup(uint8 HwUnit, uint8 IocrDepth,
                               uint16 BitconPrescalar)
{
  Ifx_ASCLIN*  HwModulePtr;
  Ifx_SRC_SRCR_Bits IntrSrc;
  uint32 Offset;

  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);
  /* Save the prescalar value */
  SavedPrescalar[HwUnit] = HwModulePtr->BITCON.B.PRESCALER;
  /* Disable the Clock source. */
  HwModulePtr->CSR.B.CLKSEL = LIN_ASCLIN_CSRREG_CLKSEL_NOCLK;
  /* Configure the Digital filter depth and  prescalar value for 
     wakeup detection */
  HwModulePtr->IOCR.B.DEPTH = IocrDepth;
  HwModulePtr->BITCON.B.PRESCALER = BitconPrescalar;
  /* Connect the Clock source */
  HwModulePtr->CSR.B.CLKSEL = LIN_ASCLIN_CSRREG_CLKSEL;

  /* Enable the FED flag and intr */
  HwModulePtr->FLAGSENABLE.B.FEDE = 1U;

  Offset = (uint32)HwUnit * LIN_ASCLIN_SRC_ADDROFFSET ;
  IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0ERRADDR  +
                                     Offset);
  IntrSrc.CLRR = 1U;
  IntrSrc.SRE = 1U; /*  Enable intr */
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)SRC_ASCLIN0ERRADDR +
                    Offset) = IntrSrc;

}
/*******************************************************************************
** Syntax           : static void Lin_lHwConfigAfterWakeup                    **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function configures the hardware after the wakeup
                      pulse is sent/ received   **
*******************************************************************************/
void Lin_lHwConfigAfterWakeup(uint8 HwUnit)
{
  Ifx_ASCLIN*  HwModulePtr;

  HwModulePtr = &(LIN_HW_MODULE[HwUnit]);

  HwModulePtr->FLAGSCLEAR.B.FEDC = 1U;  /* clear Falling edge intr */
  HwModulePtr->FLAGSENABLE.B.FEDE = 0U;  /* Disable Falling edge intr */
  HwModulePtr->CSR.B.CLKSEL = LIN_ASCLIN_CSRREG_CLKSEL_NOCLK;
  HwModulePtr->IOCR.B.DEPTH = LIN_ASCLIN_IOCRREG_DEPTH_VAL;
  HwModulePtr->BITCON.B.PRESCALER = SavedPrescalar[HwUnit];
  /* Connect the Clock source */
  HwModulePtr->CSR.B.CLKSEL = LIN_ASCLIN_CSRREG_CLKSEL;
}
#endif

/*Memory Map of the LIN Code*/
#define LIN_17_ASCLIN_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/





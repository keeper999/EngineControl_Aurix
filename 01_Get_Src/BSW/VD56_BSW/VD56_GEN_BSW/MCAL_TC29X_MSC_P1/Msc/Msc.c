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
**  $FILENAME   : Msc.c $                                                    **
**                                                                           **
**  $CC VERSION : \main\19 $                                                 **
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
**  TRACEABILITY : [cover parentID=DS_NAS_PR69_PR469_PR122_PR123,DS_NAS_PR647,
                   SAS_NAS_MSC_PR1071,DS_NAS_PR730,DS_NAS_PR746] [/cover]     **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

  /* Inclusion of controller sfr file */
#include "IfxSrc_reg.h"

  /* Inclusion of Msc sfr file */
#include "IfxMsc_reg.h"

  /* Inclusion of Msc.h header file */
#include "Msc.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*************** SW Version Checks ***************/
#ifndef MSC_SW_MAJOR_VERSION
  #error "MSC_SW_MAJOR_VERSION is not defined."
#endif

#ifndef MSC_SW_MINOR_VERSION
  #error "MSC_SW_MINOR_VERSION is not defined."
#endif

#ifndef MSC_SW_PATCH_VERSION
  #error "MSC_SW_PATCH_VERSION is not defined."
#endif

/* Check for Correct inclusion of headers */
#if ( MSC_SW_MAJOR_VERSION != 1U )
  #error "MSC_SW_MAJOR_VERSION does not match."
#endif
#if ( MSC_SW_MINOR_VERSION != 0U )
  #error "MSC_SW_MINOR_VERSION does not match."
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define MSC_DRIVER_UNINIT                     ((uint8)0U)
#define MSC_DRIVER_INIT                       ((uint8)1U)
#define MSC_UPSTREAM_BAUD_MASK                ((uint32)0x0000000EU)
#define MSC_CLOCK_DISABLE_VAL                 ((uint32)0x00000001U)
#define MSC_BIT0                              ((uint32)0x00000001U)
#define MSC_BIT1                              ((uint32)0x00000002U)
#define MSC_BIT2                              ((uint32)0x00000004U)
#define MSC_BIT3                              ((uint32)0x00000008U)
#define MSC_EMRDATA_HIGH_MASK                 ((uint32)0xFFFF0000U)
#define MSC_EMRDATA_LOW_MASK                  ((uint32)0x0000FFFFU)

#define MSC_ZERO_U                            (0U)
#define MSC_ONE_U                             (1U)
/* Start Address of MSC Register - MSC0_CLC*/
#define MSC_REGMAP                            ((Ifx_MSC *)(void *) &(MSC0_CLC))
/* Start Address of MSC Register - SRC_MSC0_SR0*/
#define MSC_SRC_REGMAP            ((Ifx_SRC_MSC *)(void *) &(SRC_MSC_MSC0_SR0))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*Memory Map of the MSC Code*/
#define MSC_START_SEC_CODE
#include "MemMap.h"

#if (MSC_DEV_ERROR_DETECT == STD_ON )

/* Fucntions to check for DET's*/
static Std_ReturnType Msc_lDetCheckUnInit(uint8 ServiceId);
static Std_ReturnType Msc_lDetCheckModule(uint8 ServiceId,uint8 Module);
static Std_ReturnType Msc_lDetCheckTxMode(uint8 ServiceId,\
                                         Msc_TxStateType TxState);
static Std_ReturnType Msc_lDetCheckTxType(uint8 ServiceId,\
                                         Msc_TxType FrmTyp);
static Std_ReturnType Msc_lDetCheckRxMode(uint8 ServiceId,\
                                         Msc_RxStateType RxState);
static Std_ReturnType Msc_lDetCheckTxDevice(uint8 ServiceId,\
                                           Msc_TxDevSelectType Device);
static Std_ReturnType Msc_lDetCheckTxState(uint8 ServiceId, uint8 ModNum);
static Std_ReturnType Msc_lDetCheckRxRegister(uint8 ServiceId,\
                                      Msc_UpstreamRegType UpReg);
static Std_ReturnType Msc_lDetCheckRxDevice(uint8 ServiceId,\
                                     Msc_RxDevSelectType Device);
#endif /* End of MSC_DEV_ERROR_DETECT */

/* Function to enable IRQ service requests */
static void Msc_lEnableHwIntrService(uint8 ModNum, uint8 SrvConfig);

#define MSC_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#if (MSC_PB_FIXEDADDR == STD_ON)
#define MSC_START_SEC_CONST_32BIT
/*
 * To be used for global constants (32 bits)
 * Inclusion of MemMap.h
*/
#include "MemMap.h"

/* To store the Msc driver configuration pointer */
static const Msc_ConfigType * const Msc_kConfigPtr = &Msc_ConfigRoot[0];

#define MSC_STOP_SEC_CONST_32BIT
#include "MemMap.h"
#endif /* End of MSC_PB_FIXEDADDR */

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#if (MSC_PB_FIXEDADDR == STD_OFF)
#define MSC_START_SEC_VAR_32BIT
/*
 * To be used for global or static variables (32 bits) that are initialized
 * after every reset (the normal case)
 * Inclusion of MemMap.h
*/
#include "MemMap.h"

static const Msc_ConfigType *Msc_kConfigPtr = NULL_PTR;

#define MSC_STOP_SEC_VAR_32BIT
#include "MemMap.h"
#endif /* End of MSC_PB_FIXEDADDR */

#define MSC_START_SEC_VAR_8BIT
/*
 * To be used for 8bit global variables
 * Inclusion of MemMap.h
*/
#include "MemMap.h"
#if ( MSC_DEBUG_SUPPORT == STD_ON )
  uint8 Msc_DriverState;
#else
  static uint8 Msc_DriverState;
#endif/* End of MSC_DEBUG_SUPPORT */

#define MSC_STOP_SEC_VAR_8BIT
#include "MemMap.h"
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#ifdef IFX_MSC_DEBUG01
  extern volatile uint32 TestMSC_DebugMask;
  extern volatile uint32 TestMSC_DebugMask01;
#endif/*#if(IFX_MSC_DEBUG01 == STD_ON)*/

#ifdef IFX_MSC_DEBUG02
  extern volatile uint32 TestMSC_DebugMask02;
#endif/*#if(IFX_MSC_DEBUG02 == STD_ON)*/

#ifdef IFX_MSC_DEBUG03
  extern volatile uint32 TestMSC_DebugMask03;
#endif/*#if(IFX_MSC_DEBUG03 == STD_ON)*/

#ifdef IFX_MSC_DEBUG04
  extern volatile uint32 TestMSC_DebugMask04;
#endif/*#if(IFX_MSC_DEBUG04 == STD_ON)*/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*Memory Map of the MSC Code*/
#define MSC_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_PR1072,DS_NAS_PR759_PR760_PR761,
                     DS_NAS_PR915,DS_NAS_PR63_5]                              **
**                                                                            **
** Syntax          : void Msc_Init(const Msc_ConfigType* ConfigPtr)           **
**                                                                            **
** [/cover]                                                                   **
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
void Msc_Init(const Msc_ConfigType* ConfigPtr)
{
  const Msc_ModuleConfigType *lModuleCfgPtr;
  uint8 ModNum;
  /* Check if DET is ON*/
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  /*Check if PB Fixed Address is OFF*/
  #if (MSC_PB_FIXEDADDR == STD_OFF)
  /*Report DET if Config Pointer is NULL*/
  if(ConfigPtr == NULL_PTR)
  #else
  /*Report DET if Config Pointer does not match*/
  if(ConfigPtr != Msc_kConfigPtr)
  #endif/* End of MSC_PB_FIXEDADDR */
  {
     /*Report DET on ConfigPtr error*/
     Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                    MSC_SID_INIT,MSC_E_PARAM_CONFIG);
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    if(Msc_DriverState != MSC_DRIVER_INIT)
    {
      #if (MSC_PB_FIXEDADDR == STD_OFF)
      /*Store the Config Pointer to Global variable*/
      Msc_kConfigPtr = ConfigPtr;
      #endif /* End of MSC_PB_FIXEDADDR  */

      /*Start from MSC0 module*/
      ModNum = (uint8)MSC_ZERO_U;
      /*Initialize all the MSC modules.*/
      while(ModNum < MSC_NUM_OF_MODULES)
      {
         /*Check if the module configuration exists*/
         if(ConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
         {
            lModuleCfgPtr = ConfigPtr->ModCfgPtr[ModNum];
            /*Clear the ENDINIT bit in the WDT_CONSR register in order
            to disable the write-protection for registers protected
            via the EndInit feature */
            Mcal_ResetENDINIT();

            /*Configure the Sleep Mode enable/diable*/
            MSC_REGMAP[ModNum].CLC.U = lModuleCfgPtr->SleepMode;

            /*Configure the clock settings for fMSC*/
            MSC_REGMAP[ModNum].FDR.U = lModuleCfgPtr->ClkConfig;

            /* Set the ENDINIT bit in the WDT_CONSR register again
            to enable the write-protection and to prevent a time-out */
            Mcal_SetENDINIT();

            /* Switch OFF the transmitter before configuring registers*/
            MSC_REGMAP[ModNum].ISC.B.SDDIS = MSC_ONE_U;

            /*Configure the downstream channel with TxConfig*/
            MSC_REGMAP[ModNum].DSC.U = lModuleCfgPtr->TxConfig;

            /*Configure the downstream channel with TxConfigExtn*/
            MSC_REGMAP[ModNum].DSTE.U = lModuleCfgPtr->TxConfigExtn;

            /*Configure the Source Select for lower 16 bits*/
            MSC_REGMAP[ModNum].DSDSL.U = lModuleCfgPtr->DataBitSrcLowConfig;

           /*Configure the Extension Source Select for lower 16 bits*/
            MSC_REGMAP[ModNum].DSDSLE.U =\
                                lModuleCfgPtr->DataBitExtensionSrcLowConfig;

            /*Configure the Source Select for Upper 16 bits*/
            MSC_REGMAP[ModNum].DSDSH.U = lModuleCfgPtr->DataBitSrcHighConfig;

            /*Configure the Extension Source Select for Upper 16 bits*/
            MSC_REGMAP[ModNum].DSDSHE.U =\
                                lModuleCfgPtr->DataBitExtensionSrcHighConfig;

            /*Configure the Emergency Stop Control for all bits*/
            MSC_REGMAP[ModNum].ESR.U = lModuleCfgPtr->DataEmergencyStopControl;

            /*Configure the Emergency Stop Control for all bits*/
            MSC_REGMAP[ModNum].ESRE.U =\
                                    lModuleCfgPtr->DataExtnEmergencyStopControl;

            /*Configure the Emergency Value for upper 16 bits*/
            MSC_REGMAP[ModNum].DD.B.DDH =\
                                  (uint16)lModuleCfgPtr->DataEmergencyValueHigh;

            /*Configure the Emergency Value for lower 16 bits*/
            MSC_REGMAP[ModNum].DD.B.DDL =\
                                  (uint16)lModuleCfgPtr->DataEmergencyValueLow;

            /*Configure the Emergency Value for upper 16 bits*/
            MSC_REGMAP[ModNum].DDE.B.DDHE =\
                          (uint16)lModuleCfgPtr->DataExtnEmergencyValueHigh;

            /*Configure the Emergency Value for lower 16 bits*/
            MSC_REGMAP[ModNum].DDE.B.DDLE =\
                           (uint16)lModuleCfgPtr->DataExtnEmergencyValueLow;

            /*Configure the Data Injection configuration from ext pin*/
            MSC_REGMAP[ModNum].DSCE.U = lModuleCfgPtr->DataInjConfig;

            /*Configure the Upstream channel with RxConfig*/
            MSC_REGMAP[ModNum].USR.U = lModuleCfgPtr->RxConfig;

            /*Configure the polarities for all signals*/
            MSC_REGMAP[ModNum].OCR.U = lModuleCfgPtr->SignalConfig;

            /*Configure the Time Frame count*/
            MSC_REGMAP[ModNum].DSS.B.NPTF = lModuleCfgPtr->TimeFrmCnt;

            /*Configure the Interrupt Service for all frames*/
            MSC_REGMAP[ModNum].ICR.U = lModuleCfgPtr->InterruptConfig.\
                                       InterruptControl;

            Msc_lEnableHwIntrService(ModNum,lModuleCfgPtr->InterruptConfig.\
                                       SRConfig);
         }
         /*Increment Module Pointer to the next module*/
         ModNum++;
      }
      /* Change the Msc_DriverState to initalzied*/
      Msc_DriverState = MSC_DRIVER_INIT;
    }
  }
}
#if (MSC_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_PR1073,DS_NAS_PR759_PR760_PR761,
                      DS_NAS_PR915]                                           **
**                                                                            **
** Syntax          : void Msc_DeInit(void)                                    **
**                                                                            **
** [/cover]                                                                   **
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
void Msc_DeInit(void)
{
  volatile uint32 Readback;
  uint8 ModNum;
  uint8 MscServReq;

  /*Start from MSC0 module*/
  ModNum = (uint8)MSC_ZERO_U;

  if(Msc_DriverState == MSC_DRIVER_INIT)
  {
    while(ModNum < MSC_NUM_OF_MODULES)
    {
      if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
      {
        /* Disable Service Requests */
        MscServReq = MSC_SRC_REGMAP[ModNum].SR0.B.SRE;
        if(MscServReq == MSC_ONE_U)
        {
          MSC_SRC_REGMAP[ModNum].SR0.B.CLRR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR0.B.IOVCLR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR0.B.SWSCLR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR0.B.SRE = MSC_ZERO_U;
        }

        MscServReq = MSC_SRC_REGMAP[ModNum].SR1.B.SRE;
        if(MscServReq == MSC_ONE_U)
        {
          MSC_SRC_REGMAP[ModNum].SR1.B.CLRR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR1.B.IOVCLR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR1.B.SWSCLR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR1.B.SRE = MSC_ZERO_U;
        }

        MscServReq = MSC_SRC_REGMAP[ModNum].SR2.B.SRE;
        if(MscServReq == MSC_ONE_U)
        {
          MSC_SRC_REGMAP[ModNum].SR2.B.CLRR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR2.B.IOVCLR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR2.B.SWSCLR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR2.B.SRE = MSC_ZERO_U;
        }

        MscServReq = MSC_SRC_REGMAP[ModNum].SR3.B.SRE;
        if(MscServReq == MSC_ONE_U)
        {
          MSC_SRC_REGMAP[ModNum].SR3.B.CLRR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR3.B.IOVCLR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR3.B.SWSCLR = MSC_ONE_U;
          MSC_SRC_REGMAP[ModNum].SR3.B.SRE = MSC_ZERO_U;
        }

        Mcal_ResetENDINIT();
        /* Set request to reset the MSC Kernel */
        MSC_REGMAP[ModNum].KRST0.B.RST = MSC_ONE_U;
        MSC_REGMAP[ModNum].KRST1.B.RST = MSC_ONE_U;
        Readback = MSC_REGMAP[ModNum].KRST0.U;
        Readback = MSC_REGMAP[ModNum].KRST1.U;
        UNUSED_PARAMETER(Readback)
        /* Clear the MSC Kernel Reset Flag */
        MSC_REGMAP[ModNum].KRSTCLR.B.CLR = MSC_ONE_U;
        /* Disable the Module using CLC register */
        MSC_REGMAP[ModNum].CLC.U = MSC_CLOCK_DISABLE_VAL;
        /* Set the ENDINIT bit in the WDT_CONSR register again
        to enable the write-protection and to prevent a time-out */
        Mcal_SetENDINIT();
      }
      /* Increment to the next MSC module*/
      ModNum++;
    }
  }
  #if (MSC_PB_FIXEDADDR == STD_OFF)
  /*Store the NULL to Global Pointer variable*/
  Msc_kConfigPtr = NULL_PTR;
  #endif /* End of MSC_PB_FIXEDADDR */

  /* Set Msc_DriverState to Un-Initialized */
  Msc_DriverState = MSC_DRIVER_UNINIT;
}
#endif /* End of MSC_DEINIT_API */

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_PR1074,DS_NAS_PR915,DS_NAS_PR63_6]**
**                                                                            **
** Syntax          : Std_ReturnType Msc_ChangeTxState  (uint8 ModNum,         **
**                   Msc_TxStateType Mode)                                    **
**                                                                            **
** [/cover]                                                                   **
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
** Return value    : E_OK/E_NOT_OK                                            **
**                                                                            **
** Description     : This function:                                           **
**   - Activates/Deactivates the transmitter (downstream channel) of the      **
**     MSC module                                                             **
*******************************************************************************/
Std_ReturnType Msc_ChangeTxState (uint8 ModNum, Msc_TxStateType Mode)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_CHANGETXSTATUS);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_CHANGETXSTATUS,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for MSC Tx state is valid */
        ErrorFlag = Msc_lDetCheckTxMode(MSC_SID_CHANGETXSTATUS,Mode);
     }
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    if(Mode == MSC_TX_ON)
    {
      /*Enable the Tx on downstream channel*/
      MSC_REGMAP[ModNum].ISC.B.CDDIS = MSC_ONE_U;
    }
    else
    {
      /*Disbale the Tx on downstream channel*/
      MSC_REGMAP[ModNum].ISC.B.SDDIS = MSC_ONE_U;
    }

    RetVal = E_OK;
  }
  return (RetVal);
}

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_PR1075,DS_NAS_PR915,DS_NAS_PR63_7]**
**                                                                            **
** Syntax          : Msc_TxStatusType Msc_GetTxStatus (uint8 ModNum,          **
**                   Msc_TxType FrameType                                     **
**                                                                            **
** [/cover]                                                                   **
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
Msc_TxStatusType Msc_GetTxStatus (uint8 ModNum, Msc_TxType FrameType)
{
  Msc_TxStatusType RetVal;
  uint8 FramePendingFlag;
  uint8 FrameActiveFlag;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_GETTXSTATUS);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_GETTXSTATUS,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for Tx frame type validity */
        ErrorFlag = Msc_lDetCheckTxType(MSC_SID_GETTXSTATUS,FrameType);
     }
  }
  /* If any DET is reported Return value is made MSC_TX_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
     RetVal = MSC_TX_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {

     /* Check for frame type is Command or Data*/
     if(FrameType == MSC_CMD_FRAME)
     {
        #ifdef IFX_MSC_DEBUG01
         FrameActiveFlag = TestMSC_DebugMask;
        #else
         FramePendingFlag = MSC_REGMAP[ModNum].DSC.B.CP;
         FrameActiveFlag = MSC_REGMAP[ModNum].DSS.B.CFA;
        #endif/*#ifdef IFX_MSC_DEBUG01 */
        /* Check if Command Frame Tx, Inactive and Not Pending*/
        if((FrameActiveFlag == MSC_ZERO_U) && (FramePendingFlag == MSC_ZERO_U))
        {
           RetVal = MSC_CMDFRMTX_READY;
        }
        else
        {
           RetVal = MSC_CMDFRMTX_NOTREADY;
        }
     }
     else
     {
        #ifdef IFX_MSC_DEBUG01
         FrameActiveFlag = TestMSC_DebugMask;
         FramePendingFlag = TestMSC_DebugMask01;
        #else
         FramePendingFlag = MSC_REGMAP[ModNum].DSC.B.DP;
         FrameActiveFlag = MSC_REGMAP[ModNum].DSS.B.DFA;
        #endif/*#ifdef IFX_MSC_DEBUG01 */
        /* Check if Data Frame Tx, Inactive and Not Pending*/
        if((FrameActiveFlag == MSC_ZERO_U) && (FramePendingFlag == MSC_ZERO_U))
        {
           RetVal = MSC_DATAFRMTX_READY;
        }
        else
        {
           RetVal = MSC_DATAFRMTX_NOTREADY;
        }
     }
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_PR1076,DS_NAS_PR915,DS_NAS_PR63_8]**
**                                                                            **
** Syntax          : Std_ReturnType Msc_TxCmdFrame (uint8 ModNum,             **
**                   Msc_TxDevSelectType Device, uint32 Msc_Cmd)              **
**                                                                            **
** [/cover]                                                                   **
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
Std_ReturnType Msc_TxCmdFrame (uint8 ModNum, Msc_TxDevSelectType Device,
                               uint32 Msc_Cmd)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_TXCMDFRAME);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_TXCMDFRAME,ModNum);
     if(ErrorFlag == E_OK)
     {
         /* Check for, Tx Device is valid */
        ErrorFlag = Msc_lDetCheckTxDevice(MSC_SID_TXCMDFRAME,Device);
        if(ErrorFlag == E_OK)
        {
           /* Check for, Transmitter is enabled */
           ErrorFlag = Msc_lDetCheckTxState(MSC_SID_TXCMDFRAME,ModNum);
        }
     }
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
     RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
     /* Select the device to the command is to be transmitted*/
     MSC_REGMAP[ModNum].OCR.B.CSC = (uint8)Device;

     /* Load the command value to the command register*/
     MSC_REGMAP[ModNum].DC.U = Msc_Cmd;

     RetVal = E_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_PR1077,DS_NAS_PR915,DS_NAS_PR63_9]**
**                                                                            **
** Syntax          : Std_ReturnType Msc_TxDataFrame (uint8 ModNum,            **
**                   Msc_TxDevSelectType DeviceHigh,                          **
**                   Msc_TxDevSelectType DeviceLow,const uint32 *Msc_Data)    **
**                                                                            **
** [/cover]                                                                   **
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
Std_ReturnType Msc_TxDataFrame (uint8 ModNum, Msc_TxDevSelectType DeviceHigh,
                         Msc_TxDevSelectType DeviceLow, const uint32 *Msc_Data)
{
  Std_ReturnType RetVal;
  uint32 lDataRegMask;
  uint32 DataVal;
  uint32 lExtnDataRegMask;
  uint32 ExtnDataVal;
  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_TXDATAFRAME);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_TXDATAFRAME,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for, MSC Tx Device is valid */
        ErrorFlag = Msc_lDetCheckTxDevice(MSC_SID_TXDATAFRAME,DeviceLow);
        if(ErrorFlag == E_OK)
        {
           /* Check for, MSC Tx Device is valid */
           ErrorFlag = Msc_lDetCheckTxDevice(MSC_SID_TXDATAFRAME,DeviceHigh);
           if(ErrorFlag == E_OK)
           {
              /* Check for MSC transmitter is in ON state */
              ErrorFlag = Msc_lDetCheckTxState(MSC_SID_TXDATAFRAME,ModNum);
           }
        }
     }
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
     RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
    {
      /* Select the device for Data Frame Transmission */
      MSC_REGMAP[ModNum].OCR.B.CSL = (uint8)DeviceLow;
      MSC_REGMAP[ModNum].OCR.B.CSH = (uint8)DeviceHigh;


      /* Check the bits for which Data register is selected as source*/
      lDataRegMask =\
       (uint32)(Msc_kConfigPtr->ModCfgPtr[ModNum]->DataRegSourceMask);
      /* Load transmit data into the Data register
         only for bits for which emergency data is not enabled.*/
      DataVal = ((uint32)(*(Msc_Data)));
      DataVal =\
          ((uint32)MSC_REGMAP[ModNum].DD.U & (uint32)(~lDataRegMask))|\
          (uint32)(DataVal & lDataRegMask);
       MSC_REGMAP[ModNum].DD.U = DataVal;

      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->ExtensionValue == 0x01U)
      {
        /* Check the bits for which Data register is selected as source*/
        lExtnDataRegMask =\
         (uint32)(Msc_kConfigPtr->ModCfgPtr[ModNum]->DataRegSourceMaskExtn);
        /* Load transmit data into the Data register
           only for bits for which emergency data is not enabled.*/
        ExtnDataVal = ((uint32)(*(Msc_Data+1U)));
        ExtnDataVal =\
            ((uint32)MSC_REGMAP[ModNum].DDE.U & (uint32)(~lExtnDataRegMask))|\
            (uint32)(ExtnDataVal & lExtnDataRegMask);

        MSC_REGMAP[ModNum].DDE.U = ExtnDataVal;
      }
      /* If MSC is in Triggered Mode, Set the Data Frame Pending bit*/
      if(MSC_REGMAP[ModNum].DSC.B.TM == MSC_ZERO_U)
      {
         /* Data Frame Pending request bit is set*/
         MSC_REGMAP[ModNum].ISC.B.SDP = MSC_ONE_U;
      }
      RetVal = E_OK;
    }
    else
    {
      /* No Configuration present for the MSC module requested*/
      RetVal = E_NOT_OK;
    }
  }
return (RetVal);
}
#if(MSC_EMERGENCY_DATA_API == STD_ON)
/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_PR1142,DS_NAS_PR915,DS_NAS_PR63_10]**
**                                                                            **
** Syntax          : Std_ReturnType Msc_ReconfigureEmergencyData(uint8 ModNum,**
**                  uint32 Msc_EmergencyDataHigh, uint32 Msc_EmergencyDataLow)**
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x06                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Msc_EmergencyDataHigh - The Higher 16 bits of emergency  **
**                   data high is for DDE.DDHE and the lower 16 bits of       **
**                   emergency data high is for DD.DDH                        **
**                   Msc_EmergencyDataLow  - The Higher 16 bits of emergency  **
**                   data low is for DDE.DDLE and the lower 16 bits of        **
**                   emergency data high is for DD.DDL                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :    E_OK/E_NOT_OK                                         **
**                                                                            **
** Description     : This function:                                           **
**   - Reconfigures the emergency data in DD register                         **
**   - Reconfigures the emergency data in DDE register                        **
*******************************************************************************/
Std_ReturnType Msc_ReconfigureEmergencyData(uint8 ModNum,
               uint32 Msc_EmergencyDataHigh, uint32 Msc_EmergencyDataLow)
{

  Std_ReturnType RetVal;
  uint32 lEmergencyConfig;
  uint32 lEmergencyConfigExtn;
  uint32 lEmergencyData;
  uint32 lEmergencyDataExtn;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_RECONFIGEMERDATA);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_RECONFIGEMERDATA,ModNum);
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
     RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    lEmergencyConfig = (uint32)MSC_REGMAP[ModNum].ESR.U;

    lEmergencyData = (((Msc_EmergencyDataHigh) & (MSC_EMRDATA_LOW_MASK))<<16)|\
                      (Msc_EmergencyDataLow & (MSC_EMRDATA_LOW_MASK));

    lEmergencyData =\
            ((uint32)MSC_REGMAP[ModNum].DD.U & (uint32)(~lEmergencyConfig))|\
             (uint32)(lEmergencyData & lEmergencyConfig);

    MSC_REGMAP[ModNum].DD.U = lEmergencyData;

    if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
    {
      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->ExtensionValue == 0x01U)
      {
        lEmergencyConfigExtn = (uint32)MSC_REGMAP[ModNum].ESRE.U;
      
        lEmergencyDataExtn =\
         ((Msc_EmergencyDataHigh) & (MSC_EMRDATA_HIGH_MASK))|\
         (((Msc_EmergencyDataLow) & (MSC_EMRDATA_HIGH_MASK))>>16);

        lEmergencyDataExtn =\
         ((uint32)MSC_REGMAP[ModNum].DDE.U & (uint32)(~lEmergencyConfigExtn))|\
         (uint32)(lEmergencyDataExtn & lEmergencyConfigExtn);

        MSC_REGMAP[ModNum].DDE.U = lEmergencyDataExtn;
      }
    }
    RetVal = E_OK;
  }
return (RetVal);
}
#endif /* End of MSC_EMERGENCY_DATA_API */
/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_PR1672,DS_NAS_PR915,DS_NAS_PR63_11]**
**                                                                            **
** Syntax          : Std_ReturnType Msc_ChangeRxStatus (uint8 ModNum,         **
**                   Msc_RxStateType Mode)                                    **
**                                                                            **
** [/cover]                                                                   **
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
Std_ReturnType Msc_ChangeRxState (uint8 ModNum, Msc_RxStateType Mode)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_CHANGERXSTATUS);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_CHANGERXSTATUS,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for MSC Rx state is valid */
        ErrorFlag = Msc_lDetCheckRxMode(MSC_SID_CHANGERXSTATUS,Mode);
     }
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    RetVal = E_OK;
    if(Mode == MSC_RX_ON)
    {
      /* Module Configuration available for the MSC ModNum*/
      if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
      {
        /* Load the Upstream baud rate from the configuration */
        MSC_REGMAP[ModNum].USR.B.URR =\
                        (uint8)((Msc_kConfigPtr->ModCfgPtr[ModNum]->\
                        RxConfig&MSC_UPSTREAM_BAUD_MASK)>>1U);
      }
      else
      {
        /*Configuration does not exist for ModNum*/
        RetVal = E_NOT_OK;
      }
    }
    else
    {
      /* Disable the Upstream channel. Set the baud rate to 0*/
      MSC_REGMAP[ModNum].USR.B.URR  = MSC_ZERO_U;
    }
  }
  return (RetVal);
}
/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_PR1078,DS_NAS_PR915,DS_NAS_PR63_12]**
**                                                                            **
** Syntax          : Msc_RxStatusType  Msc_GetRxStatus (uint8 ModNum,         **
**                   Msc_UpstreamRegType Msc_RxRegister)                      **
**                                                                            **
** [/cover]                                                                   **
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
Msc_RxStatusType  Msc_GetRxStatus (uint8 ModNum,
                                  Msc_UpstreamRegType Msc_RxRegister)
{
  Msc_RxStatusType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_GETRXSTATUS);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_GETRXSTATUS,ModNum);
     if(ErrorFlag == E_OK)
     {
       /* Check for, MSC Rx register is valid */
       ErrorFlag = Msc_lDetCheckRxRegister(MSC_SID_GETRXSTATUS,Msc_RxRegister);
     }
  }

  /* If any DET is reported Return value is made MSC_RX_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = MSC_RX_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    /*Error detected on the Rx frame*/
    if(MSC_REGMAP[ModNum].UD[Msc_RxRegister].B.PERR == MSC_ONE_U)
    {
      RetVal = MSC_RX_ERROR;
    }
    /*Valid data frame is received*/
    else if(MSC_REGMAP[ModNum].UD[Msc_RxRegister].B.V == MSC_ONE_U)
    {
      RetVal = MSC_DATA_RECEIVED;
    }
    /* No response, data frame not received*/
    else
    {
      RetVal = MSC_RX_NO_RESPONSE;
    }
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_PR1079,DS_NAS_PR915,DS_NAS_PR63_13]**
**                                                                            **
** Syntax          : Std_ReturnType Msc_GetRxData(uint8 ModNum,               **
**                   Msc_UpstreamRegType RxRegister, uint16 *DataRecd)        **
**                                                                            **
** [/cover]                                                                   **
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
Std_ReturnType Msc_GetRxData(uint8 ModNum, Msc_UpstreamRegType RxRegister,
                            uint16 *DataRecd)
{
  Std_ReturnType RetVal;
  uint16 DataVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_GETRXDATA);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_GETRXDATA,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for, MSC Rx register is valid */
        ErrorFlag = Msc_lDetCheckRxRegister(MSC_SID_GETRXDATA,RxRegister);
     }
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    /* Load the 8-bit data received , and the 2 bit address information*/
    DataVal = (uint16)MSC_REGMAP[ModNum].UD[RxRegister].B.LABF;
    DataVal = ((uint16)(DataVal<<8U) |\
               (uint16)(MSC_REGMAP[ModNum].UD[RxRegister].B.DATA));
    *DataRecd = DataVal;

    /* Clear the valid bit, after reading the data register */
    MSC_REGMAP[ModNum].UD[RxRegister].B.C = MSC_ONE_U;

    RetVal = E_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_PR1080,DS_NAS_PR915,DS_NAS_PR63_14]**
**                                                                            **
** Syntax          : Std_ReturnType Msc_SelectRxDevice(uint8 ModNum,          **
**                   Msc_RxDevSelectType Msc_Device)                          **
**                                                                            **
** [/cover]                                                                   **
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
Std_ReturnType Msc_SelectRxDevice(uint8 ModNum, Msc_RxDevSelectType Msc_Device)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_SELRXDEVICE);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_SELRXDEVICE,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for, MSC Rx Device is valid */
        ErrorFlag = Msc_lDetCheckRxDevice(MSC_SID_SELRXDEVICE,Msc_Device);
     }
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
     /*Select the Rx device*/
     MSC_REGMAP[ModNum].OCR.B.SDISEL = (uint8)Msc_Device;

     RetVal = E_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_PR1081,DS_NAS_PR915,DS_NAS_PR63_15]**
**                                                                            **
** Syntax          : Std_ReturnType Msc_StartRxTimeout(uint8 ModNum)          **
**                                                                            **
** [/cover]                                                                   **
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
Std_ReturnType Msc_StartRxTimeout(uint8 ModNum)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_STARTRXTIMEOUT);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_STARTRXTIMEOUT,ModNum);
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
     /*Check if selected MSC module is configured */
     if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
     {
       /*Clear the current timeout flag*/
       MSC_REGMAP[ModNum].USCE.B.USTC = MSC_ONE_U;

       /*Reload the Timeout Prescalar and Timeout Value,
         to start the timeout detection*/
       MSC_REGMAP[ModNum].USCE.U = Msc_kConfigPtr->ModCfgPtr[ModNum]->\
                                      UpstreamTimeoutConfig;
       RetVal = E_OK;
     }
     else
     {
       /* Configuration doesnot exist for the ModNum */
       RetVal = E_NOT_OK;
     }

  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_PR1082,DS_NAS_PR915,DS_NAS_PR63_16]**
**                                                                            **
** Syntax          : Msc_RxTimeoutStatusType Msc_GetRxTimeoutStatus           **
**                  (uint8 ModNum)                                            **
**                                                                            **
** [/cover]                                                                   **
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
Msc_RxTimeoutStatusType Msc_GetRxTimeoutStatus(uint8 ModNum)
{
  Msc_RxTimeoutStatusType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_GETRXTIMEOUT);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_GETRXTIMEOUT,ModNum);
  }

  /* If any DET is reported Return value is made MSC_TIMEOUT_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = MSC_TIMEOUT_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
     /*Check if timeout has happened*/
     if(MSC_REGMAP[ModNum].USCE.B.USTF == MSC_ONE_U)
     {
       RetVal = MSC_UPSTREAM_TIMEOUT;
     }
     else
     {
       RetVal = MSC_UPSTREAM_NO_TIMEOUT;
     }
  }
return (RetVal);
}

#if (MSC_PASSIVE_TIME_FRAME_API == STD_ON)
/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_PR1143,DS_NAS_PR915,
                     DS_NAS_PR63_17]                                          **
**                                                                            **
** Syntax          : Std_ReturnType                                           **
**                   Msc_GetPassiveTimeFrameCounter (uint8 ModNum,            **
**                   Msc_PassiveTimeFrameCounterType *CounterValue)           **
**                                                                            **
** [/cover]                                                                   **
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
Std_ReturnType Msc_GetPassiveTimeFrameCounter (uint8 ModNum,
              Msc_PassiveTimeFrameCounterType *CounterValue)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_GETTIMEFRMCOUNTER);
  if(ErrorFlag == E_OK)
  {
    /* Check for, MSC module number is valid */
    ErrorFlag = Msc_lDetCheckModule(MSC_SID_GETTIMEFRMCOUNTER,ModNum);
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    if(CounterValue != NULL_PTR)
    {
      /* Load the Passive Time frame Counter */
      *CounterValue = (Msc_PassiveTimeFrameCounterType)\
                    MSC_REGMAP[ModNum].DSS.B.PFC;
      RetVal = E_OK;
    }
    else
    {
      RetVal = E_NOT_OK;
    }
  }
return (RetVal);
}
#endif /* End of MSC_PASSIVE_TIME_FRAME_API */
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void Msc_InterruptHandler(uint8 ModNum,                  **
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
**   - Calls the configured application functions for individual Interrupts   **
*******************************************************************************/
void Msc_InterruptHandler(uint8 ModNum, uint8 ServiceNum)
{
  uint8 RxInptFlag;
  uint8 CmdInptFlag;
  uint8 DataInptFlag;
  uint8 TimeInptFlag;
  uint8 RxConfigSrv;
  uint8 CmdConfigSrv;
  uint8 DataConfigSrv;
  uint8 TimeConfigSrv;

  /* Interrupt Handler is executed only if Module is configured */
  if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
  {
    /*Capture the Interrupt Pending Flags*/
    RxInptFlag = MSC_REGMAP[ModNum].ISR.B.URDI;
    CmdInptFlag = MSC_REGMAP[ModNum].ISR.B.DECI;
    TimeInptFlag = MSC_REGMAP[ModNum].ISR.B.DTFI;
    DataInptFlag = MSC_REGMAP[ModNum].ISR.B.DEDI ;

    /* Capture the Service request configured for each interrupt */
    RxConfigSrv = MSC_REGMAP[ModNum].ICR.B.RDIP;
    CmdConfigSrv = MSC_REGMAP[ModNum].ICR.B.ECIP;
    TimeConfigSrv = MSC_REGMAP[ModNum].ICR.B.TFIP;
    DataConfigSrv = MSC_REGMAP[ModNum].ICR.B.EDIP;

    #ifdef IFX_MSC_DEBUG03
    TestMSC_DebugMask03 = ServiceNum;
    CmdConfigSrv = TestMSC_DebugMask03;
    TimeConfigSrv = TestMSC_DebugMask03;
    DataConfigSrv = TestMSC_DebugMask03;
    CmdInptFlag = MSC_ZERO_U;
    TimeInptFlag = MSC_ZERO_U;
    DataInptFlag = MSC_ZERO_U;
    #endif /*#ifdef IFX_MSC_DEBUG03 */

    #ifdef IFX_MSC_DEBUG04
    DataConfigSrv = TestMSC_DebugMask04;
    #endif/* #ifdef IFX_MSC_DEBUG04 */

    /* Rx Frame Interrupt Sevice */
    /* Check if, Rx interrupt is pending and current service is configired for
       this interrupt*/
    if((RxConfigSrv == ServiceNum) && (RxInptFlag == MSC_ONE_U))
    {
      /*Clear the Interrupt Pending Flag*/
      MSC_REGMAP[ModNum].ISC.B.CURDI = MSC_ONE_U;
      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.RxFrmNotify != NULL_PTR)
      {
        /*Call the Application Notifier Function*/
        (Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.RxFrmNotify)();
      }
    }
    /* Command Frame Interrupt Sevice */
    /* Check if, Cmd interrupt is pending and current service is configired
       for this interrupt*/
    else if((CmdConfigSrv == ServiceNum) && (CmdInptFlag == MSC_ONE_U))
    {
      /*Clear the Interrupt Pending Flag*/
      MSC_REGMAP[ModNum].ISC.B.CDECI = MSC_ONE_U;
      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.CmdFrmNotify != NULL_PTR)
      {
        /*Call the Application Notifier Function*/
        (Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.CmdFrmNotify)();
      }
    }
    /* Time Frame Interrupt Sevice */
    /* Check if, Time interrupt is pending and current service is configired
    for this interrupt*/
    else if((TimeConfigSrv == ServiceNum) && (TimeInptFlag == MSC_ONE_U))
    {
      /*Clear the Interrupt Pending Flag*/
      MSC_REGMAP[ModNum].ISC.B.CDTFI = MSC_ONE_U;
      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.TimeFrmNotify != NULL_PTR)
      {
        /*Call the Application Notifier Function*/
        (Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.TimeFrmNotify)();
      }
    }
    /* Data Frame Interrupt Sevice */
    /* Check if, Data interrupt is pending and current service is configired
       for this interrupt */
    else if((DataConfigSrv == ServiceNum) && (DataInptFlag  == MSC_ONE_U))
    {
      /*Clear the Interrupt Pending Flag*/
      MSC_REGMAP[ModNum].ISC.B.CDEDI = MSC_ONE_U;
      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.DataFrmNotify != NULL_PTR)
      {
        /*Call the Application Notifier Function*/
        (Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.DataFrmNotify)();
      }
    }
    else
    {
      /*Do Nothing*/
    }
  }

}


/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static void Msc_lEnableHwIntrService(uint8 ModNum,       **
**                   uint8 SrvConfig)                                         **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - Module Number                                   **
**                   SrvConfig - SR configuration                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function :                                          **
**   - enabled the Interrupt service requests                                 **
*******************************************************************************/
static void Msc_lEnableHwIntrService(uint8 ModNum, uint8 SrvConfig)
{
  if((SrvConfig & MSC_BIT0) == MSC_BIT0)
  {
    /* Enable SR0, if enabled in configuration*/
    MSC_SRC_REGMAP[ModNum].SR0.B.SRE = MSC_ONE_U;
  }
  if((SrvConfig & MSC_BIT1) == MSC_BIT1)
  {
    /* Enable SR1, if enabled in configuration*/
    MSC_SRC_REGMAP[ModNum].SR1.B.SRE = MSC_ONE_U;
  }
  if((SrvConfig & MSC_BIT2) == MSC_BIT2)
  {
    /* Enable SR2, if enabled in configuration*/
    MSC_SRC_REGMAP[ModNum].SR2.B.SRE = MSC_ONE_U;
  }
  if((SrvConfig & MSC_BIT3) == MSC_BIT3)
  {
    /* Enable SR3, if enabled in configuration*/
    MSC_SRC_REGMAP[ModNum].SR3.B.SRE = MSC_ONE_U;
  }
}

#if (MSC_DEV_ERROR_DETECT == STD_ON )
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckUnInit                **
**                   (uint8 ServiceId)                                        **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if MSC is uninitialized                                  **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckUnInit(uint8 ServiceId)
{
  Std_ReturnType RetVal;
  if(Msc_DriverState == MSC_DRIVER_UNINIT)
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_UNINIT);
    RetVal = E_NOT_OK;
  }
  else
  {
    RetVal = E_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : staticStd_ReturnType Msc_lDetCheckModule(uint8 ServiceId,**
**                   uint8 Module)                                            **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   Module - Module ID of MSC                                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if MSC module is invalid                                 **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckModule(uint8 ServiceId,uint8 Module)
{
  Std_ReturnType RetVal;
  uint8 ModuleDisabled;

  if(Module >= MSC_NUM_OF_MODULES)
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_MODULE);
    RetVal = E_NOT_OK;
  }
  else
  {
    #ifdef IFX_MSC_DEBUG02
    ModuleDisabled = TestMSC_DebugMask02;
    #else
    ModuleDisabled = MSC_REGMAP[Module].CLC.B.DISS;
    #endif/*#ifdef IFX_MSC_DEBUG02*/

    if( (ModuleDisabled == 1U) ||\
        (Msc_kConfigPtr->ModCfgPtr[Module] == NULL_PTR) )
    {
      Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                       ServiceId,MSC_E_INVALID_MODULE);
      RetVal = E_NOT_OK;
    }
    else
    {
      RetVal = E_OK;
    }
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckTxMode(uint8          **
**                       ServiceId, Msc_TxStateType TxState)                  **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   TxState - State of the tranmsmitter                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if transmitter of MSC module is OFF                      **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckTxMode(uint8 ServiceId,
                                         Msc_TxStateType TxState)
{
  Std_ReturnType RetVal;
  if((TxState == MSC_TX_ON) || (TxState == MSC_TX_OFF))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_MODE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckRxMode(uint8          **
**                       ServiceId, Msc_RxStateType RxState)                  **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   TxState - State of the tranmsmitter                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if Rx Mode is valid                                      **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckRxMode(uint8 ServiceId,
                                         Msc_RxStateType RxState)
{
  Std_ReturnType RetVal;
  if((RxState == MSC_RX_ON) || (RxState == MSC_RX_OFF))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_MODE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckTxType(uint8          **
**                   ServiceId, Msc_TxType FrmTyp)                            **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   FrmTyp - Type of Frame (Command/Data)                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if frame type is invalid                                 **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckTxType(uint8 ServiceId,
                                         Msc_TxType FrmTyp)
{
  Std_ReturnType RetVal;
  if((FrmTyp == MSC_CMD_FRAME) || (FrmTyp == MSC_DATA_FRAME))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_TXTYPE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckTxDevice(uint8        **
**                   ServiceId, Msc_TxDevSelectType Device)                   **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   Device - Downstream device                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if downstream device is invalid                          **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckTxDevice(uint8 ServiceId,
                                           Msc_TxDevSelectType Device)
{
  Std_ReturnType RetVal;
  if((Device == MSC_TX_DEVICE_0) || (Device == MSC_TX_DEVICE_1)||\
     (Device == MSC_TX_DEVICE_2) || (Device == MSC_TX_DEVICE_3))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_DEVICE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckTxState(uint8         **
**                   ServiceId, uint8 ModNum)                                 **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   ModNum - Module number for MSC                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if transmitter is in OFF state                           **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckTxState(uint8 ServiceId, uint8 ModNum)
{
  Std_ReturnType RetVal;

  if(MSC_REGMAP[ModNum].DSC.B.DSDIS == MSC_ZERO_U)
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_STATE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckRxRegister(uint8      **
**                   ServiceId, Msc_UpstreamRegType UpReg)                    **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   UpReg - Upstream Register for MSC                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if UpReg is invalid                                      **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckRxRegister(uint8 ServiceId,
                                      Msc_UpstreamRegType UpReg)
{
  Std_ReturnType RetVal;
  if((UpReg == MSC_UD0) || (UpReg == MSC_UD1) ||\
     (UpReg == MSC_UD2) || (UpReg == MSC_UD3))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_RXREGISTER);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckRxDevice(uint8        **
**                   ServiceId, Msc_RxDevSelectType Device)                   **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   Device - Upstream Device for MSC                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if Upstream Device is invalid                            **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckRxDevice(uint8 ServiceId,
                                     Msc_RxDevSelectType Device)
{
  Std_ReturnType RetVal;
  if((Device == MSC_RX_DEVICE_0) || (Device == MSC_RX_DEVICE_1) ||\
     (Device == MSC_RX_DEVICE_2) || (Device == MSC_RX_DEVICE_3) ||\
     (Device == MSC_RX_DEVICE_4) || (Device == MSC_RX_DEVICE_5) ||\
     (Device == MSC_RX_DEVICE_6) || (Device == MSC_RX_DEVICE_7))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_RXDEVICE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

#endif /* End of MSC_DEV_ERROR_DETECT */


#define MSC_STOP_SEC_CODE
#include "MemMap.h"



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
**  $FILENAME   : Gtm.c $                                                    **
**                                                                           **
**  $CC VERSION : \main\90 $                                                 **
**                                                                           **
**  $DATE       : 2014-02-04 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of <> driver.                                **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*  TRACEABILITY: [cover parentID=SAS_NAS_GTM_PR912,DS_NAS_PR1086,
DS_NAS_PR73,DS_NAS_PR228]
[/cover]
*/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Own header file, this includes own configuration file also */
#include "Gtm.h"
#include "Gtm_Local.h"
/* Include Irq definitions for IRQ */
#include "IfxSrc_reg.h"




/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define GTM_TIM_MODE_TIPM  (3U)
#define GTM_TIM_MODE_TBCM  (4U)

#define GTM_VALUE_ZERO (0U)
#define GTM_ONE (1)
#define GTM_ZERO (0)

#define GTM_ZERO_U (0U)
#define GTM_ONE_U (1U)
#define GTM_TWO_U (2U)
#define GTM_SIXTEEN_U (16U)
#define GTM_EIGHT_U (8U)
#define GTM_THREE_UL (3UL)


/* Get the IRQ Enable Information from a 8bit variable */
#define GTM_GET_IRQ_VAL_8 (0x3FUL)

/* Get the TIM EIRQ Enable Information from a 32 bit variable */
#define GTM_TIM_GET_EIRQ_VAL_32 (0x3FUL)

/* Get the TIM IN SRC register Information from a 32 bit variable */
#define GTM_TIM_GET_INSRC_VAL_32 (0xFFFFFFFFUL)

/* Get the TIM IN SRC register Information from a 32 bit variable */
#define GTM_TIM_GET_AUXIN_VAL_32 (0xFFUL)

#define GTM_GET_ARU_IRQ_VAL (0x07UL)
#define GTM_GET_FIFO_IRQ_VAL (0x0FUL)
#define GTM_GET_MCS_IRQ_VAL (0x0EUL)
/*Gets EIRQ value for MCS*/
#define GTM_GET_MCS_EIRQ_VAL (0x07L)

/* Get the IRQ Mode Information from a 8bit variable */
#define GTM_GET_MODE_VAL_8 (0xC0UL)
#define GTM_GET_EIRQ_VAL_8 (0x1E00UL)
#define GTM_GET_MODE_VAL_8_U (0xC0U)

/* Bits to shift to get the mode information to LSB for a 8 bit variable */
#define GTM_SHIFT_TO_LSB_8 (6)
#define GTM_SHIFT_EIRQ_TO_LSB_8 (9U)

/* Bits to shift to get the Dma information of FIFO to LSB */
#define GTM_FIFO_SHIFT_TO_LSB (2)
#define GTM_FIFO_DMA_MASK (0x30UL)
/* Get the FIFO EIRQ Enable Information from a 32 bit variable */
#define GTM_FIFO_GET_EIRQ_VAL_32 (0x0000000FUL)

/* Get the IRQ Enable Information from a 32 bit variable */
#define GTM_GET_IRQ_VAL_32 (0x3FFFFFFFUL)
/* Get the IRQ Mode Information from a 32 bit variable */
#define GTM_GET_MODE_VAL_32 (0xC0000000UL)
/* Bits to shift to get the mode information to LSB for a 32 bit variable */
#define GTM_SHIFT_TO_LSB_32 (30U)


#define GTM_TOM_CHAN_PER_SRN (2U)
#define GTM_ATOM_CHAN_PER_SRN (2U)
#define GTM_GET_INT_STATUS (3UL)


#define GTM_CLEAR_INTERRUPT (3UL)
#define GTM_CLEAR_TIM_INTERRUPT (0x3FUL)

#define GTM_TOM_TGC_GET_FUPD (0xFFFFUL)
#define GTM_TOM_TGC_CLEAR_FUPD (0x5555UL)
#define GTM_TOM_CHAN_ENABLE (3UL)

#define GTM_ATOM_CHAN_ENABLE (3UL)
#define GTM_ATOM_AGC_GET_FUPD (0xFFFFUL)
#define GTM_ATOM_AGC_CLEAR_FUPD (0x5555UL)

#define GTM_TIM_GET_MODE (0xEUL)
#define GTM_TIM_ENABLE_MASK (1UL)

#define GTM_TIM_EXT_CAP_ENABLE_MASK (0x7UL)

#define GTM_CCU1 (1U)

#define GTM_TIM_GLITCH_POS (5U)

#define GTM_CMU_CLK_ENABLE (2UL)
#define GTM_CMU_REG_CLK_ENABLE (3UL)
#define GTM_CMU_START_FROM_EXTCLK (16U)

#define GTM_DISABLE_ALL_CLOCKS (0x00555555U)

/* If this bit is 1, then it would indicate that ARU is not configured using
   Tool */
#define GTM_ARU_NOT_CONFIGURED (5U)
#define GTM_TBU_CONFIGURED (5U)
#define GTM_F2A_CONFIGURED (4U)


#define GTM_BITS_IN_U32 (32U)
#define GTM_TBU_GET_LOWER_NIBBLE  (0x0FUL)

#define GTM_BITS_PER_F2A (2U)
#define GTM_F2A_STR_CFG_MASK (0x7UL)
#define GTM_F2A_ENABLE (2UL)

#define GTM_MCS_CLEAR_INTERRUPTS (7UL)

#define GTM_DPLL_ENABLE (2UL)
#define GTM_GET_NUTE_FST (0x7FFUL)
#define GTM_DPLL_WNUT_POS (29U)
#define GTM_DPLL_WVTN_POS (31U)
#define GTM_DPLL_WNUS_POS (29U)
#define GTM_DPLL_WVSN_POS (31U)
/* Get the DPLL EIRQ Enable Information from a 32 bit variable */
#define GTM_DPLL_GET_EIRQ_VAL_32 (0x0FFFFFFFUL)

#define GTM_GET_NUSE_FSS (0x3F80000UL)
#define GTM_BRING_TO_LSB_19 (19U)
#define GTM_BRING_TO_VSN (7U)
#define GTM_GET_VSN (0xFC000000UL)
#define GTM_GET_VTN (0x1F800UL)
#define GTM_BRING_TO_VTN (8U)
#define GTM_DPLL_GET_OSS (0x60000UL)
#define GTM_BRING_TO_OSS (9U)
#define GTM_DPLL_CLEAR_INTERRUPTS (0x07ffffffUL)
#define GTM_SPE_CLEAR_INTERRUPTS (0xFUL)
/* Get the SPE EIRQ Enable Information from a 32 bit variable */
#define GTM_SPE_GET_EIRQ_VAL_32 (0x0000001FUL)

#define GTM_CMP_CLEAR_INTERRUPTS (0x00FFFFFFUL)

/* Get the CMU EIRQ Enable Information from a 32 bit variable */
#define GTM_CMU_GET_EIRQ_VAL_32 (0x00FFFFFFUL)
/* Get the CMU Fixed clock control line Info from a 32 bit variable */
#define GTM_GET_FIXED_CLK_VAL (0x0FUL)

#define GTM_CMU_NO_OF_CLOCKS (8U)
#define GTM_CMU_NO_OF_EXT_CLOCKS (3U)
#define GTM_CMU_TOTAL_CLOCKS (12U)


/* Address of first register of ICM from where the corresponding Sub-Modules
   status are reported */
#define GTM_TOM_ICM_BASE_ADDRESS (&GTM_ICM_IRQG_6)
#define GTM_ATOM_ICM_BASE_ADDRESS (&GTM_ICM_IRQG_9)

/* Number of Modules status that are reported per ICM register */
#define GTM_TOM_MODULES_IN_ICM_REG  (2U)
#define GTM_ATOM_MODULES_IN_ICM_REG (4U)

/* This signifies that number of TOM/ATOM/TIM module definitions present in a
   single element of GtmTomUsage/GtmAtomUsage/GtmTimUsage parameter */
#define GTM_TOM_MODS_IN_UINT32 (GTM_BITS_IN_U32/GTM_CHANNELS_PER_TOM_MODULE)
#define GTM_ATOM_MODS_IN_UINT32 (GTM_BITS_IN_U32/GTM_CHANNELS_PER_ATOM_MODULE)
#define GTM_TIM_MODS_IN_UINT32 (GTM_BITS_IN_U32/GTM_CHANNELS_PER_TIM_MODULE)

/* Number of DPLL Interrupts */
#define GTM_NUMBER_OF_DPLL_INT (27U)

#define GTM_CHAN_NOT_CONFIGURED (0xFFU)
#define GTM_MCAL_TIMEOUT_VAL (150000U)
#define GTM_INVALID_NUMBER (0xFFU)

/*Xor compare value for initcheck*/
#define GTM_32_XOR_COMPARE_VAL (0xFFFFFFFFUL)
#define GTM_GET_EN_REG_BIT (0x00555555UL)


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/** CMU object */
typedef Ifx_GTM_CMU_CLK0_5 Gtm_CmuClkCtrl;
typedef Ifx_GTM_CMU_ECLK_NUM Gtm_CmuEclkNumType;
typedef Ifx_GTM_CMU_ECLK_DEN Gtm_CmuEclkDenType;

typedef struct
{
  Gtm_CmuEclkNumType CmuEclkNum;
  Gtm_CmuEclkDenType CmuEclkDen;
}Gtm_CmuEclkType;


typedef volatile struct
{
  /* CMU Clock Enable Register */
  Ifx_GTM_CMU_CLK_EN CLK_EN;
  /* CMU Global Clock Control Numerator Register */
  Ifx_GTM_CMU_GCLK_NUM GCLK_NUM;
  /* CMU Global Clock Control Denominator Register */
  Ifx_GTM_CMU_GCLK_DEN GCLK_DEN;
  /* CMU Control For Clock Register */
  Gtm_CmuClkCtrl ClkCtrl[GTM_CMU_NO_OF_CLOCKS];
  /* CMU External Clock Control Registers */
  Gtm_CmuEclkType CmuEclk[GTM_CMU_NO_OF_EXT_CLOCKS];
  /* Fixed clock divider value  */
  uint32 GtmFxdClkControl; 
} Gtm_CmuType;


/** MSC objects */

typedef Ifx_GTM_MSCSET_CON0 Gtm_MscSetConType;

typedef volatile struct
{
    Gtm_MscSetConType CON[GTM_NO_OF_MSC_SETS];  /* MSC Set Control 0 Register */
} Gtm_MscSetsType;



#define GTM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/* To get the Source that has triggered Interrupt */
static _INLINE_ uint32 Gtm_lGetIntSource(uint32 Value, uint8 Index)
{
  return((uint32)(Value & (GTM_BIT_SET << Index )));
}

/* To identify if a sub-module is configured or not */
static _INLINE_ boolean Gtm_lGetUnused8(uint8 CtrlVal)
{
  return(((CtrlVal & GTM_SETUNUSED8) > GTM_VALUE_ZERO)?\
                                                  (boolean)TRUE:(boolean)FALSE);
}

/* To identify if a sub-module is configured or not */
static _INLINE_ boolean Gtm_lGetUnused32(uint32 CtrlVal)
{
  return(((CtrlVal & GTM_SETUNUSED32) > GTM_VALUE_ZERO)?\
                                                  (boolean)TRUE:(boolean)FALSE);
}

/* To get the value at bitposition of the input "Value" */
static _INLINE_ uint8 Gtm_lGetBit8(uint8 Value, uint8 BitPosition)
{
  return((uint8)(((Value & (uint8)(GTM_ONE_U << BitPosition))> GTM_VALUE_ZERO)
                                                            ?GTM_ONE:GTM_ZERO));
}

/* Get the Driver that uses the particular channel */
static _INLINE_ uint8 Gtm_lGetModuleIndex(uint32 ModUsage, uint8 Channel)
{
  return((uint8)((ModUsage & (GTM_THREE_UL << (GTM_TWO_U * Channel))) >>
                                                        (GTM_TWO_U * Channel)));
}

static _INLINE_ void Gtm_lCmuClockConfigure(void);

static _INLINE_ void Gtm_lAruConfigure(void);

static _INLINE_ void Gtm_lCmuExtClkConfigure(void);

static _INLINE_ void  Gtm_lCmuConfClkConfigure(void);

static _INLINE_ void Gtm_lFifoConfigure(void);

static _INLINE_ void Gtm_lTimConfigure(void);

static _INLINE_ void Gtm_lSaveTgcStatus(Ifx_GTM_TOM_TGC_TYPE *TomTgcRegPtr);

static _INLINE_ void Gtm_lTomHostTrigger(void);

static _INLINE_ void Gtm_lTomTgcConfigure(void);

static _INLINE_ void Gtm_lSaveAgcStatus(Ifx_GTM_ATOM_AGCx *AtomAgcRegPtr);


static _INLINE_ void Gtm_lAtomHostTrigger(void);

static _INLINE_ void Gtm_lAtomAgcConfigure(void);

static _INLINE_ void Gtm_lPortConfig(void);

static _INLINE_ void Gtm_lTbuConfig(void);

static _INLINE_ void Gtm_lF2aConfig(void);

static _INLINE_ void Gtm_lMcsConfig(void);

static _INLINE_ void Gtm_lDpllConfig(void);

static _INLINE_ void Gtm_lSpeConfig(void);

static _INLINE_ void Gtm_lCmpConfig(void);

static _INLINE_ void Gtm_lMscConnectionsConfig(void);

static _INLINE_ void Gtm_lDsadcConnectionsConfig(void);

static _INLINE_ void Gtm_lTtcanConnectionsConfig(void);

static _INLINE_ void Gtm_lEnableGtm(void);

static _INLINE_ void Gtm_lMapConfigure(void);

static _INLINE_ void Gtm_lTomConfigure(void);

static _INLINE_ void Gtm_lAtomConfigure(void);


static _INLINE_ uint32 Gtm_lGetAtomIrqStatus(uint8 ModuleNo,
                                             uint8 ChannelNumber);

static _INLINE_ uint32 Gtm_lGetTomIrqStatus(uint8 ModuleNo,
                                            uint8 ChannelNumber);

#ifdef VALEO_PATCH_MCAL_FIX_ISR_MNGT
static _INLINE_ boolean Gtm_lTimerCheckIntTrig(uint8 IrqVal,
                                             uint32 ChanIrqEnable,
                                             uint8 CcuSelect);
#endif  /* VALEO_PATCH_MCAL_FIX_ISR_MNGT */


#define GTM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*
 * To be used for global or static variables (32 bits) that are initialized
 * after every reset (the normal case)
   Inclusion of MemMap.h
*/

#define GTM_START_SEC_VAR_32BIT
#include "MemMap.h"

const Gtm_ConfigType *Gtm_kConfigPtr;

#define GTM_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#if ((GTM_NO_OF_TIM_CH_CONF_NOTIF > 0U)  ||(GTM_NO_OF_TOM_CH_CONF_NOTIF > 0U) \
                                        ||(GTM_NO_OF_ATOM_CH_CONF_NOTIF > 0U))

#define GTM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/* Declaration of GTM Notification Link time configuration */
extern const Gtm_NotificationConfigType Gtm_kNotifConfig0;


#define GTM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#endif


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#if (GTM_GPT_MODULE_USED == STD_ON)
/*******************************************************************************
** Syntax : void Gpt_Isr (uint8 ModChannelNo)                                 **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModChannelNo- Gpt channel number which called the        **
**            TOM channel interrupt                                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This ISR services the interrupt generated from GTM to GPT**
*******************************************************************************/
extern void Gpt_Isr(uint8 ModChannelNo);

#endif

#if (GTM_PWM_MODULE_USED == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_17_Gtm_Isr (uint8 ModChannelNo)                          **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModChannelNo- PWM channel number which called the        **
**            TOM channel interrupt                                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This ISR services the interrupt generated from GTM to PWM**
*******************************************************************************/
extern void Pwm_17_Gtm_Isr(uint8 ModChannelNo);

#endif

#if (GTM_ICU_MODULE_USED == STD_ON)
/*******************************************************************************
** Syntax : void Icu_17_GtmCcu6_Eru_Isr (uint8 ModChannelNo)                  **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModChannelNo- Icu channel number which called the        **
**            TOM channel interrupt                                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This ISR services the interrupt generated from GTM to ICU**
*******************************************************************************/
extern void Icu_17_GtmCcu6_Isr(uint8 ModChannelNo);

#endif

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*Memory Map of the GTM Code*/
#define GTM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1088,DS_NAS_PR1089,DS_NAS_PR1090,
   DS_NAS_PR1091,DS_NAS_SWSC_0002]
** Syntax : void Gtm_Init(const Gtm_ConfigType *ConfigPtr)                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non reentrant                                            **
**                                                                            **
** Parameters (in):  ConfigPtr - Pointer to configuration set                 **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This routine initializes the GTM module.                 **
**                   This routine must be called before executing ICU / PWM / **
**                   GPT driver.                                              **
**                   The intention of this function is to make the            **
**                   configuration settings for GTM driver                    **
**                   also enable Interrupt Request for all resources that is  **
**                   used across ICU/PWM/GPT and GTM modules.                 **
**                   Clock Setting for GTM module clock and clock bus         **
**                   configuration will be done in this                       **
**                   function.                                                **
**                                                                            **
*******************************************************************************/
void Gtm_Init(const Gtm_ConfigType *ConfigPtr)
{
  const Gtm_GeneralConfigType *GeneralConfigPtr; /* Pointer to General Config */
  uint32 TimeOut = GTM_MCAL_TIMEOUT_VAL;

  Gtm_kConfigPtr = ConfigPtr;

  /*************************** Enable GTM *************************************/
  Gtm_lEnableGtm();

  /********************* Enable GTM Global Clock ******************************/

  Gtm_lCmuClockConfigure();

  /********************* General Initialization********************************/
  /* Get the general configuration */
  GeneralConfigPtr = ConfigPtr->GtmModuleConfigPtr->GtmGeneralConfigPtr;

  GTM_CTRL.U = (uint32_t)(GeneralConfigPtr->GtmCtrlValue);
  GTM_IRQ_EN.U = (uint32_t)((uint32)GeneralConfigPtr->GtmIrqEnable & \
                                                             GTM_GET_IRQ_VAL_8);
                                                             
  GTM_IRQ_MODE.U = (uint32_t)(((uint32)(GeneralConfigPtr->GtmIrqEnable) & \
                                     GTM_GET_MODE_VAL_8) >> GTM_SHIFT_TO_LSB_8);
                                     
  GTM_EIRQ_EN.U = (uint32_t)(((uint32)(GeneralConfigPtr->GtmIrqEnable) & \
                                GTM_GET_EIRQ_VAL_8) >> GTM_SHIFT_EIRQ_TO_LSB_8);
                                     
                                
  /* SRN Enable */
  SRC_GTMAEIIRQ.U |= (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);

  /********************* ARU Initialization ***********************************/
  Gtm_lAruConfigure();

  /******************** FIFO Initialization ***********************************/
  Gtm_lFifoConfigure();

  /******************** MAP Initialization ************************************/
  Gtm_lMapConfigure();

  /******************** TIM Initialization ************************************/
  Gtm_lTimConfigure();

  /******************** TOM Initialization ************************************/

  Gtm_lTomConfigure();

  /******************** ATOM Initialization ***********************************/

  Gtm_lAtomConfigure();

  /******************** PORT Initialization ***********************************/
  Gtm_lPortConfig();

  /******************** TBU Initialization ************************************/
  Gtm_lTbuConfig();


  /******************** BRC Initialization ************************************/
  Gtm_lBrcConfig();
 

  /******************** F2A Initialization ************************************/
  Gtm_lF2aConfig();

  /******************** MCS Initialization ************************************/
  /* Mcs register initialization is performed */
  Gtm_lMcsConfig();

  /******************** MCFG Initialization ***********************************/
  /* Check if Mcfg is configured */
  if(Gtm_lGetUnused8(ConfigPtr->GtmModuleConfigPtr->GtmMcfgConfig) != \
                                                                 (boolean)FALSE)
  {
    GTM_MCFG_CTRL.U = (uint32)ConfigPtr->GtmModuleConfigPtr->GtmMcfgConfig;
  }
  /******************* DPLL Initialization ************************************/
  Gtm_lDpllConfig();


  /******************** SPE Initialization ************************************/
  Gtm_lSpeConfig();


  /******************** CMP Initialization ************************************/
  Gtm_lCmpConfig();

  /******************** Msc Connections Initialization ************************/
  Gtm_lMscConnectionsConfig();


  /******************** DSADC Connections Initialization **********************/
  Gtm_lDsadcConnectionsConfig();

  /********************** ADC Connections Initialization **********************/
  Gtm_lAdcConnectionsConfig();

  /********************** TTCAN Connections Initialization ********************/
  Gtm_lTtcanConnectionsConfig();

  /********************** PSI5 Connections Initialization *********************/
  GTM_PSI5OUTSEL0.U = ConfigPtr->GtmModuleConfigPtr->GtmPsi5OutSelect;

  /********************** PSI5S Connections Initialization ********************/
  GTM_PSI5SOUTSEL.U = ConfigPtr->GtmModuleConfigPtr->GtmPsi5SOutSelect;

  /********************** Access Enable Initialization ************************/
   
  Mcal_ResetSafetyENDINIT_Timed(TimeOut);
  GTM_ACCEN0.U = ConfigPtr->GtmModuleConfigPtr->GtmAccessEnable0;

  Mcal_SetSafetyENDINIT_Timed();


}/* End of Gtm_Init */

/*******************************************************************************
** Syntax : void Gtm_IsrTomModule(uint8 ModuleNo, uint8 ChannelNumber)        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - TOM Module Number                             **
**                   ChannelNumber - Channel number (0,2,4,6,8,10,12,14)      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All TOM Interrupt sources are mapped to this function.   **
**                   On an interrupt request from TOM isr, channel number and **
**                   module number are passed as parameter. Since 2 interrupt **
**                   sources are mapped  to one Interrupt node, the parameter **
**                   to this function will be an even number only.            **
*******************************************************************************/
void Gtm_IsrTomModule(uint8 ModuleNo, uint8 ChannelNumber)
{
#ifdef GTM_TOM_MODULE_USED

  uint8 ChanIndex;          /* Maintains an index to the channel to check     */
  uint8 ModChNum; /*Holds the GPT/PWM channel for ModuleNo and ChannelNumber */
  uint16 NotifRegVal; /* Holds the value of IRQ NOTIF reg before clearing reg */  
  uint32 IrqStatus;       /* Conveys which channel has triggered the Interrupt*/
  uint32 TomModuleUsage;  /*Holds the value of TOM module usage for ModuleNo*/
  #if (GTM_NO_OF_TOM_CH_CONF_NOTIF > 0U)
  Gtm_NotificationPtrType NotifFn;  /* Notification function */
  #endif

  Ifx_GTM_TOM_CH_TYPE *ChannelPtr; /* Pointer to the TOM channel Register  */
  /* Module usage configuration pointer*/
  const Gtm_ModUsageConfigType *ModUsageConfigPtr; 
  
  /* Get the GtmModUsageConfigPtr config pointer*/
  ModUsageConfigPtr =(Gtm_kConfigPtr->
                                  GtmModuleConfigPtr->GtmModUsageConfigPtr);
  /* Get the module channel no corresponding to ModuleNo and ChannelNumber
  for GTM compex driver - Notification index in array Gtm_kNotifConfig0[]
  for GPT - Gpt channel no
  for PWM - PWM channel no
  */
 
  /* Get the usage information for TOM module*/
  TomModuleUsage = (uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->                \
                                                  GtmTomModuleUsage[ModuleNo];


  
    /* Initialize ChanIndex to the number of channels mapped to one
       Interrupt Node */
    ChanIndex = GTM_TOM_CHAN_PER_SRN;
    /* Get the Irq Group status to detect the channel that has 
    triggered the ISR*/
    IrqStatus = Gtm_lGetTomIrqStatus(ModuleNo, ChannelNumber);
    /* Loop through both the channels */
    do
    {
      ChanIndex--;
      /* Check which the channel has triggered interrupt 
                                         ( 2 ATOM channel shares the same SRN)*/
#ifdef VALEO_PATCH_MCAL_FIX_ISR_MNGT
      if(Gtm_lGetIntSource((Gtm_lGetTomIrqStatus(ModuleNo, ChannelNumber)), ChanIndex))
#else
      if(Gtm_lGetIntSource(IrqStatus, ChanIndex))
#endif  /* VALEO_PATCH_MCAL_FIX_ISR_MNGT */
      {
        /* Get the Channel Register Pointer */
        ChannelPtr = &((*(Ifx_GTM_TOMx*)(void *)(MODULE_GTM.TOM)).
                                TOM_CH[ModuleNo].CH[ChannelNumber + ChanIndex]);
        /* Clear the status for receiving other interrupts */
        NotifRegVal = (uint16) ChannelPtr->IRQ_NOTIFY.U;
        ChannelPtr->IRQ_NOTIFY.U = GTM_CLEAR_INTERRUPT;
        ModChNum = ModUsageConfigPtr->                                         \
                              Gtm_TomUsage[ModuleNo][ChannelNumber + ChanIndex];
        
        #if (GTM_NO_OF_TOM_CH_CONF_NOTIF > 0U)

        if (Gtm_lGetModuleIndex(TomModuleUsage,ChannelNumber + ChanIndex) ==   \
                                                        GTM_TOM_DRIVER_COMPLEX)
        {
          /*Get notification number from Lcfg */
          NotifFn = Gtm_kNotifConfig0.TomNotifUsage[ModChNum];
          /* Call the notification function if configured */
          NotifFn(GTM_TOM_MODULE, ModuleNo,                                \
                                        ChannelNumber + ChanIndex,NotifRegVal);
        }
        #else
          UNUSED_PARAMETER(NotifRegVal)           
        #endif
        
        #if (GTM_GPT_MODULE_USED == STD_ON)
         if(Gtm_lGetModuleIndex(TomModuleUsage,ChannelNumber + ChanIndex) == \
                                                                 GTM_DRIVER_GPT)
         {
           Gpt_Isr(ModChNum);
         }
        #endif
        #if (GTM_PWM_MODULE_USED == STD_ON)
         if(Gtm_lGetModuleIndex(TomModuleUsage,ChannelNumber + ChanIndex) ==  \
                                                             GTM_DRIVER_PWM_MOD)
         {
           Pwm_17_Gtm_Isr(ModChNum);
         }
        #endif
      }
    /* Span through both the channels */
    }while(ChanIndex > GTM_ZERO_U);
#else /* included to remove GNU compilation warning */
  UNUSED_PARAMETER(ModuleNo)
  UNUSED_PARAMETER(ChannelNumber)  
#endif
/*#ifdef GTM_TOM_MODULE_USED*/
}

/*******************************************************************************
** Syntax : void Gtm_IsrAtomModule(uint8 ModuleNo, uint8 ChannelNumber)       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - ATOM Module number                            **
**                   ChannelNumber - Channel number (0,2,4,6)                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All ATOM Interrupt sources are mapped to this function.  **
**                   On an interrupt request from ATOM isr, channel number and**
**                   Module Number are passed as parameter. Since 2 interrupt **
**                   sources are mapped to one Interrupt node, the parameter  **
**                   to this function will be an even number only.            **
*******************************************************************************/
void Gtm_IsrAtomModule(uint8 ModuleNo, uint8 ChannelNumber)
{
#ifdef GTM_ATOM_MODULE_USED

  uint8 ChanIndex;          /* Maintains an index to the channel to check     */
  
  /*Holds the GPT/PWM channel for ModuleNo and ChannelNumber */
  uint8 ModUsageChno;  
  /*Holds the GPT/PWM/GTM channel for ModuleNo and ChannelNumber */
  uint8 ModChNum;  
  uint16 NotifRegVal; /* Holds the value of IRQ NOTIF reg before clearing reg */  
  uint32 IrqStatus;       /* Conveys which channel has triggered the Interrupt*/

#ifdef VALEO_PATCH_MCAL_FIX_ISR_MNGT
  uint8  CurrentCcu;       /* Patch: Local variable to count the CCU         */
  uint32 ChanIrqEnable;    /* Patch to get Interrupt Enable information       */
#endif  /* VALEO_PATCH_MCAL_FIX_ISR_MNGT */

  uint32 AtomModuleUsage;  /*Holds the value of ATOM module usage for ModuleNo*/
  #if (GTM_NO_OF_ATOM_CH_CONF_NOTIF > 0U)
  Gtm_NotificationPtrType NotifFn;  /* Notification function */
  #endif 
  /*Module usage configuration pointer*/
  const Gtm_ModUsageConfigType *ModUsageConfigPtr; 
  Ifx_GTM_ATOM_CH_TYPE *ChannelPtr; /* Pointer to the ATOM channel Register */
  /* Initialize ChanIndex to the number of channels mapped to one
     Interrupt Node */
  ChanIndex = GTM_ATOM_CHAN_PER_SRN;
  /* Get the Irq Group status to detect the channel that has triggered the ISR*/
  IrqStatus = Gtm_lGetAtomIrqStatus(ModuleNo, ChannelNumber);
  
  /* Get the GtmModUsageConfigPtr config pointer*/
  ModUsageConfigPtr =(Gtm_kConfigPtr->
                                      GtmModuleConfigPtr->GtmModUsageConfigPtr);
  /* Get the usage information for TOM module*/
  AtomModuleUsage = (uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->               \
                                         GtmAtomModuleUsage[ModuleNo/GTM_TWO_U];

  /* Get the module channel no corresponding to ModuleNo and ChannelNumber
  for GTM compex driver - Notification index in array Gtm_kNotifConfig0[]
  for GPT - Gpt channel no
  for PWM - PWM channel no
  */                                        

  /* Loop through both the channels */
  do
  {
    ChanIndex--;
    /* Check which the channel has triggered interrupt 
                                      ( 2 ATOM channel shares the same SRN)*/
    if(Gtm_lGetIntSource(IrqStatus, ChanIndex))
    {
      /* Get the Channel Register Pointer */
      ChannelPtr = &((*(Ifx_GTM_ATOMx*)(void *)(MODULE_GTM.ATOM)).           \
                      ATOM_CH[ModuleNo].CH[ChannelNumber + ChanIndex]);
      /* Clear the status for receiving other interrupts */
      NotifRegVal = (uint16) ChannelPtr->IRQ_NOTIFY.U;      
      ChannelPtr->IRQ_NOTIFY.U = GTM_CLEAR_INTERRUPT;
#ifdef VALEO_PATCH_MCAL_FIX_ISR_MNGT
      /* Patch to get the address of Irq enable register */
      ChanIrqEnable = (uint32)(ChannelPtr->IRQ_EN.U);
#endif  /* VALEO_PATCH_MCAL_FIX_ISR_MNGT */
      ModChNum = ModUsageConfigPtr->                                         \
                          Gtm_AtomUsage[ModuleNo][ChannelNumber + ChanIndex];
      ModUsageChno = ChannelNumber + ChanIndex;
       ModUsageChno = ((ModuleNo % GTM_TWO_U) == GTM_ONE_U )?                  \
          ((ModUsageChno * GTM_TWO_U) + GTM_SIXTEEN_U)/GTM_TWO_U:(ModUsageChno);

        #if (GTM_NO_OF_ATOM_CH_CONF_NOTIF > 0U)  

        if(Gtm_lGetModuleIndex(AtomModuleUsage,ModUsageChno) ==                \
                                                        GTM_TOM_DRIVER_COMPLEX)
        {      
#ifdef VALEO_PATCH_MCAL_FIX_ISR_MNGT
           /* Patch */
           CurrentCcu = GTM_CCU1 + 1U;
           /* If CCU1 has triggered and if CCU1 is enabled to trigger, then   */
           /* callthe corresponding modules ISR                               */
           while(CurrentCcu != 0U)
           {
              CurrentCcu--;
              if (Gtm_lTimerCheckIntTrig(NotifRegVal, ChanIrqEnable, CurrentCcu + 1U))
              {
                 /* Retrieve the Notification function corresponding to Channel */
                 /* MISRA Rule Violation 17.4
                    Pointer arithmetic other than array indexing used
                    This cannot be avoided because of Post Build structure */

           /* Get the Array position of the ATOM Channel */
          NotifFn = Gtm_kNotifConfig0.AtomNotifUsage[ModChNum];
          /* Call the notification function if configured */
                 NotifFn(GTM_ATOM_MODULE, ModuleNo, ChannelNumber + ChanIndex,
                         CurrentCcu);
              }
           }
           /* Patch End */
#else
          NotifFn(GTM_ATOM_MODULE, ModuleNo,                                 \
                                    ChannelNumber + ChanIndex, NotifRegVal);
#endif  /* VALEO_PATCH_MCAL_FIX_ISR_MNGT */
        }
        
        #else
          UNUSED_PARAMETER(NotifRegVal)                  
        #endif
        
        #if (GTM_GPT_MODULE_USED == STD_ON)   
        /*check if corresponding module no and channel no is used by GPT*/     
        if(Gtm_lGetModuleIndex(AtomModuleUsage,ModUsageChno)==           \
                                                                 GTM_DRIVER_GPT)
        {
           Gpt_Isr(ModChNum);
        }
        #endif
        #if (GTM_PWM_MODULE_USED == STD_ON)        
        /*check if corresponding module no and channel no is used by PWM*/     
        if(Gtm_lGetModuleIndex(AtomModuleUsage,ModUsageChno) ==         \
                                                            GTM_DRIVER_PWM_MOD)
        {
          Pwm_17_Gtm_Isr(ModChNum);
        }
        #endif
      } 
    }while(ChanIndex > 0U);
#else /* included to remove GNU compilation warning */
  UNUSED_PARAMETER(ModuleNo)
  UNUSED_PARAMETER(ChannelNumber) 
#endif 
/*#ifdef GTM_ATOM_MODULE_USED*/

}




/*******************************************************************************
** Syntax : void Gtm_IsrTimModule(uint8 ModuleNo, uint8 ChannelNumber)        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo: TIM Module Number                              **
**                   ChannelNumber - Channel number (0 to 7)                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All TIM Interrupt sources are mapped to this function.   **
**                   On an interrupt request from TIM isr, channel number and **
**                   module number are passed as parameter. Notification      **
**                   function if configured, will be called                   **
*******************************************************************************/
void Gtm_IsrTimModule(uint8 ModuleNo, uint8 ChannelNumber)
{
#ifdef GTM_TIM_MODULE_USED

  /* Following Holds the GPT/PWM channel for ModuleNo and ChannelNumber */
  uint8 ModUsageChno;  
  uint8 ModChNum;  /*Holds the GPT/PWM channel for ModuleNo and ChannelNumber */
  uint16 NotifRegVal; /* Holds the value of IRQ NOTIF reg before clearing reg */    
  uint32 TimModuleUsage;  /*Holds the value of TIM module usage for ModuleNo*/
  Ifx_GTM_TIM_CH_TYPE *TimChannelRegPtr; /* Pointer to TIM channel Register */
  /*Module usage configuration pointer*/
  const Gtm_ModUsageConfigType *ModUsageConfigPtr;
  #if (GTM_NO_OF_TIM_CH_CONF_NOTIF > 0U)
  Gtm_NotificationPtrType NotifFn;  /* Notification function */
  #endif
  
  /* Get the TIM module usage*/
  TimModuleUsage = (uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->                \
                                          GtmTimModuleUsage[ModuleNo/GTM_TWO_U];
  /* Get the module usage config pointer */
  ModUsageConfigPtr = (Gtm_kConfigPtr->                                        \
                                     GtmModuleConfigPtr->GtmModUsageConfigPtr);
  /* Retrieve the correspoding module ch no. i.e. for ICU - ICU channel no 
   and for GTM complex driver Notificaiton no*/
  ModChNum = ModUsageConfigPtr->Gtm_TimUsage[ModuleNo][ChannelNumber];
  
  /* Get the location of TIM channel registers */
  TimChannelRegPtr = &((*(Ifx_GTM_TIMx*)(void *)(MODULE_GTM.TIM)).           \
                                            CH_TIM[ModuleNo].CH[ChannelNumber]);
                                            
  /* Clear the Notify for receiving new interrupt requests */
  NotifRegVal = (uint16) TimChannelRegPtr->CH_IRQ_NOTIFY.U;  
  TimChannelRegPtr->CH_IRQ_NOTIFY.U = GTM_CLEAR_TIM_INTERRUPT;

  ModUsageChno = ChannelNumber;
  ModUsageChno = ((ModuleNo % GTM_TWO_U) == GTM_ONE_U )?                       \
          ((ModUsageChno * GTM_TWO_U) + GTM_SIXTEEN_U)/GTM_TWO_U:(ModUsageChno);
  
  #if (GTM_NO_OF_TIM_CH_CONF_NOTIF > 0U)
  
  if(Gtm_lGetModuleIndex(TimModuleUsage ,ModUsageChno) ==                      \
                                                        GTM_TIM_DRIVER_COMPLEX)
  {
    /* If interrupt has been raised for an unconfigured channel then 0xFF
       will be returned */
    NotifFn = Gtm_kNotifConfig0.TimNotifUsage[ModChNum];
    /* Call the notification function if configured */
    NotifFn(GTM_TIM_MODULE, ModuleNo, ChannelNumber, NotifRegVal);
  }
  #else
    UNUSED_PARAMETER(NotifRegVal)   
  #endif

  #if (GTM_ICU_MODULE_USED == STD_ON)
  if(Gtm_lGetModuleIndex(TimModuleUsage,ModUsageChno) == GTM_DRIVER_ICU)
  {
    Icu_17_GtmCcu6_Isr(ModChNum);
  }
     
  #endif
  #else /* included to remove GNU compilation warning */
    UNUSED_PARAMETER(ModuleNo)
    UNUSED_PARAMETER(ChannelNumber)
  #endif 
/*#ifdef GTM_TIM_MODULE_USED*/

}


/*******************************************************************************
** Syntax : static _INLINE_ uint32 Gtm_lGetAtomIrqStatus(uint8 ModuleNo,      **
**                                                       uint8 ChannelNumber) **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - ATOM Module Number                            **
**                   ChannelNumber - Channel number (0,2,4,6)                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     IrqStatus - Interrupt status of the channels             **
**                                                                            **
** Description :     This function fetches the interrupt status of the channel**
**                   number and the next channel number                       **
*******************************************************************************/
static _INLINE_ uint32 Gtm_lGetAtomIrqStatus(uint8 ModuleNo,uint8 ChannelNumber)
{
  volatile uint32 RegVal;
  uint32 IrqStatus;
  uint8 RegPos;

  /* Ascertain the position of Interrupt status for the corresponding module
     and channel*/
  RegPos = ((ModuleNo % GTM_ATOM_MODULES_IN_ICM_REG) * \
             GTM_CHANNELS_PER_ATOM_MODULE) + ChannelNumber;

  /* Identify the ICM register corresponding to the Module number */
  /* MISRA Rule Violation 11.4 and 17.4 Pointer to Pointer conversion*/
  /* Pointer to pointer conversion is performed to simplify the code. Since
     each of the ICM register has a different name, to make this available in a
     single functions, this conversion is performed. This pointer arithmetic
     is desired */

  RegVal = *(((uint32*)(void *)GTM_ATOM_ICM_BASE_ADDRESS) + \
                                        (ModuleNo/GTM_ATOM_MODULES_IN_ICM_REG));


  /* Retrieve the IRQ status of the channel number and the next channel */
  IrqStatus = (RegVal & (GTM_GET_INT_STATUS << RegPos)) >> (RegPos);
  return(IrqStatus);
}

/*******************************************************************************
** Syntax : static _INLINE_ uint32 Gtm_lGetTomIrqStatus(uint8 ModuleNo,       **
**                                                       uint8 ChannelNumber) **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - TOM Module Number                             **
**                   ChannelNumber - Channel number (0,2,4,6,8,10,12,14)      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     IrqStatus - Interrupt status of the channels             **
**                                                                            **
** Description :     This function fetches the interrupt status of the channel**
**                   number and the next channel number                       **
*******************************************************************************/
static _INLINE_ uint32 Gtm_lGetTomIrqStatus(uint8 ModuleNo,uint8 ChannelNumber)
{
  volatile uint32 RegVal;
  uint32 IrqStatus;
  uint8 RegPos;

  /* Ascertain the position of Interrupt status for the corresponding module
     and channel*/
  RegPos = ((ModuleNo % GTM_TOM_MODULES_IN_ICM_REG) * \
                                   GTM_CHANNELS_PER_TOM_MODULE) + ChannelNumber;

  /* Identify the ICM register corresponding to the Module number */
  /* Identify the ICM register corresponding to the Module number */
  /* MISRA Rule Violation 11.4 and 17.4 Pointer to Pointer conversion*/
  /* Pointer to pointer conversion is performed to simplify the code. Since
     each of the ICM register has a different name, to make this available in a
     single functions, this conversion is performed. This pointer arithmetic
     is desired */


  RegVal = *(((uint32*)(void *)GTM_TOM_ICM_BASE_ADDRESS) + \
                                         (ModuleNo/GTM_TOM_MODULES_IN_ICM_REG));


  /* Retrieve the IRQ status of the channel number and the next channel */
  IrqStatus = (RegVal & (GTM_GET_INT_STATUS << RegPos)) >> (RegPos);
  return(IrqStatus);
}


/*******************************************************************************
** Syntax : void Gtm_lCmuConfClkConfigure(void)                               **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize CMU module                        **
*******************************************************************************/
static _INLINE_ void  Gtm_lCmuConfClkConfigure(void)
{
  const Gtm_ClockSettingType *ClockSettingPtr;   /* Pointer to Clock Settings */
  uint8  Count;             /* Variable to maintain Loop Count                */



  /* Get Clock Configuration */
  ClockSettingPtr = Gtm_kConfigPtr->GtmClockSettingPtr;


  /* Configure all clocks */
  for(Count = GTM_ZERO_U; Count < GTM_CMU_NO_OF_CLOCKS; Count++)
  {
    if(ClockSettingPtr->GtmClockEnable & \
                 (uint32)(GTM_CMU_CLK_ENABLE << (Count * GTM_CMU_BITS_PER_CLK)))
    {
      /* The clock structure provided by Sfr will cause increase in code size.
         Hence a type Gtm_CmuType has been created and used to provide an
         array approach for CMU clocks */


      /* The CMU structure as per SFR does not support for arrayed approach. To
         reduce the code size, a new type Gtm_CmuType is introduced and is
         typecasted in this case */
      ((Gtm_CmuType*)(void*)&(MODULE_GTM.CMU))->ClkCtrl[Count].CTRL.U = \
                                           ClockSettingPtr->GtmCmuClkCnt[Count];

    }

  }
}

/*******************************************************************************
** Syntax : void Gtm_lCmuExtClkConfigure(void)                                **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize CMU module                        **
*******************************************************************************/
static _INLINE_ void Gtm_lCmuExtClkConfigure(void)
{
  const Gtm_ClockSettingType *ClockSettingPtr;   /* Pointer to Clock Settings */
  uint8  Count;             /* Variable to maintain Loop Count                */


  /* Get Clock Configuration */
  ClockSettingPtr = Gtm_kConfigPtr->GtmClockSettingPtr;

  /* Configure External Clocks         */
  for(Count = GTM_ZERO_U; Count < GTM_CMU_NO_OF_EXT_CLOCKS; Count++)
  {
    if(ClockSettingPtr->GtmClockEnable & \
      (uint32)(GTM_CMU_CLK_ENABLE <<((Count * GTM_CMU_BITS_PER_CLK) + \
      GTM_CMU_START_FROM_EXTCLK)))
    {
      /* The clock structure provided by Sfr will cause increase in code size.
         Hence a type Gtm_CmuType has been created and used to provide an
         array approach for CMU clocks */
      /* MISRA rule violation 11.4 and 1.2 */

      /* The CMU structure as per SFR does not support for arrayed approach. To
         reduce the code size, a new type Gtm_CmuType is introduced and is
         typecasted in this case */

      ((Gtm_CmuType*)(void*)&(MODULE_GTM.CMU))->CmuEclk[Count].CmuEclkNum.U =  \
                                   ClockSettingPtr->GtmEclk[Count].CmuEclkNum;
      ((Gtm_CmuType*)(void*)&(MODULE_GTM.CMU))->CmuEclk[Count].CmuEclkNum.U =  \
                                   ClockSettingPtr->GtmEclk[Count].CmuEclkNum;
      ((Gtm_CmuType*)(void*)&(MODULE_GTM.CMU))->CmuEclk[Count].CmuEclkDen.U =  \
                                   ClockSettingPtr->GtmEclk[Count].CmuEclkDen;


    }
  }
  ((Gtm_CmuType*)(void*)&(MODULE_GTM.CMU))->GtmFxdClkControl =                 \
                     ClockSettingPtr->GtmFxdClkControl & GTM_GET_FIXED_CLK_VAL;
}

/*******************************************************************************
** Syntax : void Gtm_lCmuClockConfigure(void)                                 **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize CMU module                        **
*******************************************************************************/
static _INLINE_ void Gtm_lCmuClockConfigure(void)
{
  const Gtm_ClockSettingType *ClockSettingPtr;   /* Pointer to Clock Settings */
  uint32 RegTemp;           /* Temporary variable to store the register value */
  uint32 RegTemp1;          /* Temporary variable to store the register value */
  uint32 RegTemp3;          /* Temporary variable to store the register value */
  uint32 RegTemp4;          /* Temporary variable to store the register value */
  uint8  Count;             /* Variable to maintain Loop Count                */
  uint8  EnableClock;       /* To Indicate if clock need to be enabled        */

  /* Get Clock Configuration */
  ClockSettingPtr = Gtm_kConfigPtr->GtmClockSettingPtr;

  /* Check if any new value configured for Numerator or Denominator of the
     Global Clock */

  /* The content of Numerator and Denominator are temporarily taken in local
     variables and used in the if statement below for Misra reasons.          */
  RegTemp3 = GTM_CMU_GCLK_NUM.U;
  RegTemp4 = GTM_CMU_GCLK_DEN.U;
  RegTemp1 = GTM_ZERO_UL;
  /* Indicate that Clock has been enabled prior */
  EnableClock = GTM_ZERO_U;

  if( (RegTemp3 != Gtm_kConfigPtr->GtmModuleConfigPtr->GtmGclkNum) ||          \
      (RegTemp4 != Gtm_kConfigPtr->GtmModuleConfigPtr->GtmGclkDen))
  {
    RegTemp = GTM_CMU_CLK_EN.U;

    /* Clock dividers can be initialized only when the corresponding clocks are
       disabled */
    GTM_CMU_CLK_EN.U = GTM_DISABLE_ALL_CLOCKS;
    /* Indicate that Clock has been disabled and need to be enabled */
    EnableClock = GTM_ONE_U;
    /* For reliable clock setting, it is recommended to have 2 initializations
       of Numerator followed by a single initialization of Denominator        */
    GTM_CMU_GCLK_NUM.U = Gtm_kConfigPtr->GtmModuleConfigPtr->GtmGclkNum;
    GTM_CMU_GCLK_NUM.U = Gtm_kConfigPtr->GtmModuleConfigPtr->GtmGclkNum;
    GTM_CMU_GCLK_DEN.U = Gtm_kConfigPtr->GtmModuleConfigPtr->GtmGclkDen;
    /* Reenable the Clocks which were enabled earlier. A valid clock enable will
       be read as 11b. For enabling, 10b has to be written, hence the
       conversion is performed as mentioned below */
    for(Count = GTM_ZERO_U; Count < GTM_CMU_TOTAL_CLOCKS; Count++)
    {
      if(( RegTemp & (GTM_CMU_REG_CLK_ENABLE << (Count * GTM_CMU_BITS_PER_CLK)) ) )
      {
        RegTemp1 |= (GTM_ENABLE_CLK << (Count * GTM_CMU_BITS_PER_CLK));
      }
    }
  }

  if(ClockSettingPtr != NULL_PTR)      /* Configure CMU clocks if configured  */
  {
    /* If clock is enabled, then it needs to be disabled for this activity */
    if(EnableClock == GTM_ZERO_U)
    {
      /* Disable all clock enables  */
      GTM_CMU_CLK_EN.U = GTM_DISABLE_ALL_CLOCKS;
    }

    /* Invoke the functions to configure Configurable and External Clocks */
    Gtm_lCmuConfClkConfigure();
    Gtm_lCmuExtClkConfigure();


    /* Enable clocks */
    GTM_CMU_CLK_EN.U = (uint32_t)(RegTemp1 |(ClockSettingPtr->GtmClockEnable));
    /* Indicate that Clock has been enabled and need not be enabled again */
    EnableClock = GTM_ZERO_U;
  }
  if(EnableClock == GTM_ONE_U)
  {
    GTM_CMU_CLK_EN.U = (uint32)RegTemp1;
  }
}

/*******************************************************************************
** Syntax : void Gtm_lAruConfigure(void)                                      **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize ARU module                        **
*******************************************************************************/
static _INLINE_ void Gtm_lAruConfigure(void)
{
  if(Gtm_lGetBit8(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAruConfig,
                  GTM_ARU_NOT_CONFIGURED) == GTM_ZERO_U)
  {
    /* If configured, the initilize Irq Enable and Mode */
    GTM_ARU_IRQ_MODE.U =                                                       \
           (uint32_t)(((uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAruConfig\
                                   & GTM_GET_MODE_VAL_8) >> GTM_SHIFT_TO_LSB_8);
    GTM_ARU_IRQ_EN.U =                                                         \
            (uint32_t)((uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAruConfig\
                                                         & GTM_GET_ARU_IRQ_VAL);

    /* SRN Enable */
    SRC_GTMARUIRQ0.U |= (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);
    SRC_GTMARUIRQ1.U |= (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);
    SRC_GTMARUIRQ2.U |= (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);
  }
}
/*******************************************************************************
** Syntax : void Gtm_lFifoConfigure(void)                                     **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize FIFO module                       **
*******************************************************************************/
static _INLINE_ void Gtm_lFifoConfigure(void)
{
  const Gtm_FifoConfigType *FifoConfigPtr;  /* Pointer to Fifo Config         */
  Ifx_GTM_FIFO_CH *FifoChannelPtr;     /* Pointer to FIFO Channel        */
  uint8  Count;                             /* Variable to maintain Loop Count*/

  /* Check if Fifo is configured */
  if(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmFifoConfigPtr != NULL_PTR)
  {
    for(Count=GTM_ZERO_U; Count < GTM_NO_OF_FIFO_CHANNELS; Count++)
    {
      /* MISRA Rule Violation 17.4
         Pointer arithmetic other than array indexing used
         This cannot be avoided because of Post Build structure */

     FifoConfigPtr =Gtm_kConfigPtr->GtmModuleConfigPtr->GtmFifoConfigPtr[Count];


      if(FifoConfigPtr != NULL_PTR)
      {
        FifoChannelPtr = &(MODULE_GTM.FIFO0.CH[Count]);


        /* Initialize the Start Address  */
        FifoChannelPtr->START_ADDR.U =                                 \
                           (uint32)FifoConfigPtr->FifoStartAddress;
        /* Initialize the End Address    */
        FifoChannelPtr->END_ADDR.U   =                                 \
                           (uint32)FifoConfigPtr->FifoEndAddress;
        /* Initialize the Upper Watermark Address  */
        FifoChannelPtr->UPPER_WM.U   =                                  \
                           (uint32)FifoConfigPtr->FifoUpperWatermark;
        /* Initialize the Lower Watermark Address  */
        FifoChannelPtr->LOWER_WM.U   =                                  \
                           (uint32)FifoConfigPtr->FifoLowerWatermark;
        /* Initialize the FIFO Channel Control Register  */
        FifoChannelPtr->CTRL.U      =                                  \
                           (uint32)FifoConfigPtr->FifoCtrl;
        /* Initialize the Irq Enable Register  */
        FifoChannelPtr->IRQ_EN.U        =                                  \
        (uint32_t)((uint32)FifoConfigPtr->FifoIrqEnable & GTM_GET_FIFO_IRQ_VAL);
        /* Initialize the Irq Mode Register  */

        
        FifoChannelPtr->IRQ_MODE.U = 
          (uint32_t)(((uint32)FifoConfigPtr->FifoIrqEnable & GTM_FIFO_DMA_MASK)
                                                      >> GTM_FIFO_SHIFT_TO_LSB)|
          (uint32_t)(((uint32)FifoConfigPtr->FifoIrqEnable & GTM_GET_MODE_VAL_8)
                                                      >> GTM_SHIFT_TO_LSB_8);

        /* Initialize the Error Irq Enable Register  */
        FifoChannelPtr->EIRQ_EN.U = (uint32_t)                              \
        ((uint32)FifoConfigPtr->FifoErrIrqEnable & GTM_FIFO_GET_EIRQ_VAL_32);

        /* Enable SRN */
        
        MODULE_SRC.GTM.GTM[0].PSM[0][Count].U|=                                \
                                       (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);
      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lTimConfigure(void)                                      **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize TIM module                        **
*******************************************************************************/
static _INLINE_ void Gtm_lTimConfigure(void)
{
  const Gtm_TimConfigType *TimConfigPtr;         /* Pointer to TIM Config     */
  Ifx_GTM_TIM_CH_TYPE *TimChannelRegPtr;       /* Pointer to TIM Channel    */
  Ifx_GTM_TIM_IN_SRC_RESET_TYPE *TimInScrRegPtr; 
                                              /* Pointer to TIM IN_SRC reg    */

  uint8 TimCnt;             /* Variable to TIM Channel Initialization Count   */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleNo;           /* Variable to hold Module Number                 */
  uint8 ChannelNo;          /* Variable to hold Channel Number                */
  uint8 TimMode;            /* Variable to hold the TIM Mode                  */


  /* Count to maintain track of the index in TIM Channel Config */
  TimCnt = GTM_ZERO_U;
  /* MajorCnt -Count to maintain an index to the GtmTimUsage Array            */
  /* MinorCnt -Count to maintain an index to the channels in GtmTimUsage Array*/
  for(MajorCnt = GTM_ZERO_U;
      MajorCnt <  \
            (((GTM_MAX_TIM_CHANNELS - GTM_ONE_U)/GTM_BITS_IN_U32) + GTM_ONE_U);
      MajorCnt++)
  {
    for(MinorCnt = GTM_ZERO_U; (MinorCnt < GTM_BITS_IN_U32); MinorCnt++)
    {
      /* MISRA Rule Violation 17.4
         Pointer arithmetic other than array indexing used
         This cannot be avoided because of Post Build structure */
        /* Derive Module Number and Channel Number from Loop Count information*/
        ModuleNo = ((MajorCnt * GTM_BITS_IN_U32) + MinorCnt)/
                                                    GTM_CHANNELS_PER_TIM_MODULE;
        ChannelNo = MinorCnt % GTM_CHANNELS_PER_TIM_MODULE;

      /* Check if the channel is configured */
      if((Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTimUsage[MajorCnt] &
         (GTM_BIT_SET << MinorCnt)) > GTM_ZERO_UL)
      {
        TimConfigPtr =&(Gtm_kConfigPtr->GtmModuleConfigPtr->\
                                                       GtmTimConfigPtr[TimCnt]);

        TimCnt++;

        /* Get the Pointer to the Channel Register Structure */
        TimChannelRegPtr = &(((*(Ifx_GTM_TIMx*)(void *)(MODULE_GTM.TIM)).
                                               CH_TIM[ModuleNo].CH[ChannelNo]));
        TimInScrRegPtr = &(((*(Ifx_GTM_TIMx*)(void *)(MODULE_GTM.TIM)).
                                            IN_SRC_RST[ModuleNo].IN_SRC_RESET));

        /* Configure all Channel paramters if the Channel usage is Complex    */
        if(TimConfigPtr->TimUsage == GTM_DRIVER_COMPLEX)
        {
          /* Mask the TIM Enable status before writing the control register */
          TimChannelRegPtr->CH_CTRL.U =                                        \
                        (uint32_t)(TimConfigPtr->TimCtrlValue & ~(GTM_BIT_SET));

          /* Configure Filter related parameters only if the Filter is
             configured */
          if(TimConfigPtr->GtmTimFltPtr!= NULL_PTR)
          {
            TimChannelRegPtr->CH_FLT_RE.U =                                \
                                TimConfigPtr->GtmTimFltPtr->TimRisingEdgeFilter;
            TimChannelRegPtr->CH_FLT_FE.U =                                \
                               TimConfigPtr->GtmTimFltPtr->TimFallingEdgeFilter;
          }
          TimChannelRegPtr->CH_TDUV.U =  TimConfigPtr->TimTduValue;
          TimChannelRegPtr->CH_IRQ_MODE.U =                              \
           (uint32_t)(((uint32)TimConfigPtr->TimIrqEn & GTM_GET_MODE_VAL_8_U) >>
                                                            GTM_SHIFT_TO_LSB_8);

          /* Clear all Pending Interrupts */
          TimChannelRegPtr->CH_IRQ_NOTIFY.U = GTM_CLEAR_TIM_INTERRUPT;
          TimChannelRegPtr->CH_IRQ_EN.U  =                               \
                 (uint32_t)((uint32)TimConfigPtr->TimIrqEn & GTM_GET_IRQ_VAL_8);
          /*Setting TIM EIRQ values*/
          TimChannelRegPtr->CH_EIRQ_EN.U  = (uint32_t)
                  ((uint32)TimConfigPtr->TimErrIrqEn & GTM_TIM_GET_EIRQ_VAL_32);
           
          /*Setting TIM IN_SRC values*/           
          TimInScrRegPtr->IN_SRC.U  =  (uint32_t)
                 ((uint32)TimConfigPtr->TimInSrcSel & GTM_TIM_GET_INSRC_VAL_32);
          
          /*Setting TIM AUX_IN values*/
          MODULE_GTM.TIM_AUX_IN_SRC[ModuleNo].U  = (uint32_t)                  \
          ((uint32)TimConfigPtr->TimAuxInSrcSel & GTM_TIM_GET_AUXIN_VAL_32);
          

          TimMode = \
          (uint8)((TimConfigPtr->TimCtrlValue & GTM_TIM_GET_MODE) >> GTM_ONE_U);

          /* CNTS register is writable only in TIPM and TBCM mode */
          if((TimMode == GTM_TIM_MODE_TIPM) || (TimMode == GTM_TIM_MODE_TBCM))
          {
            TimChannelRegPtr->CH_CNTS.U = TimConfigPtr->TimCntsValue;
          }

          /* Update the TIM Enable bit if enabled */
          TimChannelRegPtr->CH_CTRL.U |=                                \
                   (uint32_t)(TimConfigPtr->TimCtrlValue & GTM_TIM_ENABLE_MASK);
                   
         /* Update the TIM External Control register if EXT_CAP_EN is enabled */
          TimChannelRegPtr->CH_ECTRL.U |= (uint32_t)                           \
                   (TimConfigPtr->TimExtCapSrc & GTM_TIM_EXT_CAP_ENABLE_MASK);


          /* Enable SRN */
          MODULE_SRC.GTM.GTM[0].TIM[ModuleNo][ChannelNo].U |=        \
                                       (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);


        }
        /* If the channel is configured for ICU, then enable the SRN          */
        else
        {
          TimChannelRegPtr->CH_IRQ_NOTIFY.U = GTM_CLEAR_TIM_INTERRUPT;

          /* Enable SRN */
          MODULE_SRC.GTM.GTM[0].TIM[ModuleNo][ChannelNo].U |=        \
                                       (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);
        }
      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lSaveTgcStatus(Ifx_GTM_TOM_TGC_TYPE *TomTgcRegPtr)       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  TomTgcRegPtr - Pointer to TGC Configuration              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to Save TGC information                         **
*******************************************************************************/
static _INLINE_ void Gtm_lSaveTgcStatus(Ifx_GTM_TOM_TGC_TYPE *TomTgcRegPtr)
{
  uint8 MinorCnt;

  for(MinorCnt = GTM_ZERO_U; MinorCnt < GTM_SIXTEEN_U; MinorCnt++)
  {
    if((TomTgcRegPtr->ENDIS_STAT.U &  \
    (GTM_TOM_CHAN_ENABLE << (MinorCnt * GTM_TOM_BITS_PER_CHAN))) > GTM_ZERO_UL)
    {
      TomTgcRegPtr->ENDIS_CTRL.U =                                   \
      (uint32_t)(~(GTM_TOM_CHAN_DISABLE << (MinorCnt * GTM_TOM_BITS_PER_CHAN)));

    }
    if((TomTgcRegPtr->OUTEN_STAT.U &
       (GTM_TOM_CHAN_ENABLE<<(MinorCnt * GTM_TOM_BITS_PER_CHAN))) > GTM_ZERO_UL)
    {
      TomTgcRegPtr->OUTEN_CTRL.U =                                   \
      (uint32_t)(~(GTM_TOM_CHAN_DISABLE << (MinorCnt * GTM_TOM_BITS_PER_CHAN)));
    }
  }
}


/*******************************************************************************
** Syntax : void Gtm_lTomHostTrigger(void)                                    **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to provide TOM Host Trigger                     **
*******************************************************************************/
static _INLINE_ void Gtm_lTomHostTrigger(void)
{
  Ifx_GTM_TOM_TGC_TYPE *TomTgcRegPtr;            /* Pointer to TOM TGC Reg    */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */


  /* Check the Fupd status and invoke a Host Trigger to set the clocks        */
  /* MajorCnt - Count to maintain TOM Module Count            */
  /* MinorCnt - Count to maintain TGC Count                   */
  for(MajorCnt = GTM_ZERO_U; MajorCnt < GTM_NO_OF_TOM_MODULES; MajorCnt++)
  {
    for(MinorCnt = GTM_ZERO_U; MinorCnt < GTM_NO_OF_TGC_PER_MODULE;MinorCnt++)
    {
      TomTgcRegPtr = &(((*(Ifx_GTM_TOMx*)(void *)(MODULE_GTM.TOM)).
                                TOM_TGC[MajorCnt].TGC[MinorCnt]));

      if((TomTgcRegPtr->FUPD_CTRL.U & GTM_TOM_TGC_GET_FUPD) > GTM_ZERO_UL)
      {
        /* Invoke an Host Trigger */
        TomTgcRegPtr->GLB_CTRL.U |= (uint32_t)GTM_BIT_SET;
      }
    }
  }
}


/*******************************************************************************
** Syntax : void Gtm_lTomTgcConfigure(void)                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize TGC's of TOM                      **
*******************************************************************************/
static _INLINE_ void Gtm_lTomTgcConfigure(void)
{
  const Gtm_TomTgcConfigType *TomConfigPtr;      /* Pointer to TOM Config     */
  Ifx_GTM_TOM_TGC_TYPE* TomTgcRegPtr;            /* Pointer to TOM TGC Reg    */
  uint8 TomCnt;             /* Variable to TOM Channel Initialization Count   */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleNo;           /* Variable to hold Module Number                 */
  uint8 TgcNumber;          /* Variable to hold TGC Number                    */

  /* Count to maintain track of the index in TOM TGC Config      */
  TomCnt = GTM_ZERO_U;

  /* MajorCnt -Count to maintain an index to the GtmTomTgcUsage Array         */
  /* MinorCnt -Count to maintain an index to the channels in
     GtmTomTgcUsage Array*/
  for(MajorCnt = GTM_ZERO_U;
      MajorCnt <(((GTM_NO_OF_TOM_MODULES * GTM_NO_OF_TGC_PER_MODULE)/
                   GTM_BITS_IN_U32) + GTM_ONE_U);
      MajorCnt++)
  {
    for(MinorCnt = GTM_ZERO_U;
        (((MajorCnt * GTM_BITS_IN_U32)+ MinorCnt) <                             \
       (GTM_NO_OF_TOM_MODULES * GTM_NO_OF_TGC_PER_MODULE));
       MinorCnt++)

    {
      /* Check if the TGC is configured */
      if((Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTomTgcUsage[MajorCnt] &
         (GTM_BIT_SET << MinorCnt)) > GTM_ZERO_UL)
      {
        /* Extract Module Number and Channel Number from the Loop Count       */
        ModuleNo = ((MajorCnt * GTM_BITS_IN_U32) + MinorCnt)/
                     GTM_NO_OF_TGC_PER_MODULE;
        TgcNumber = (MinorCnt) % GTM_NO_OF_TGC_PER_MODULE;

        /* MISRA Rule Violation 17.4
           Pointer arithmetic other than array indexing used
           This cannot be avoided because of Post Build structure */

        /* Get the pointer to the TGC configuration */
        TomConfigPtr =                                                         \
              &(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTomTgcConfigPtr[TomCnt]);

        TomCnt++;

        /* Get the Pointer to the TGC registers */
        TomTgcRegPtr = &((*(Ifx_GTM_TOMx*)(void *)
                           (MODULE_GTM.TOM)).TOM_TGC[ModuleNo].TGC[TgcNumber]);


        TomTgcRegPtr->ACT_TB.U = TomConfigPtr->GtmTomActTb;
        TomTgcRegPtr->INT_TRIG.U = (uint32)(TomConfigPtr->GtmTomIntTrig);

        /* Check if the TGC is configured ie. if the channels for TGC is
           configured for Complex usage */
        if(TomConfigPtr->GtmTomTgcConfigGrpPtr != NULL_PTR)
        {
          TomTgcRegPtr->FUPD_CTRL.U  = \
                                TomConfigPtr->GtmTomTgcConfigGrpPtr->GtmTomFupd;
          TomTgcRegPtr->OUTEN_CTRL.U = \
            (uint32)(TomConfigPtr->GtmTomTgcConfigGrpPtr->GtmTomOutenCtrl);
          TomTgcRegPtr->OUTEN_STAT.U = \
            (uint32_t)(TomConfigPtr->GtmTomTgcConfigGrpPtr->GtmTomOutenStat);
          TomTgcRegPtr->GLB_CTRL.U   = (uint32_t)\
                  ((uint32)TomConfigPtr->GtmTomTgcConfigGrpPtr->GtmTomUpdateEn)\
                                                               << GTM_SIXTEEN_U;
          TomTgcRegPtr->ENDIS_CTRL.U = \
            (uint32)(TomConfigPtr->GtmTomTgcConfigGrpPtr->GtmTomEndisCtrl);
          TomTgcRegPtr->ENDIS_STAT.U = \
            (uint32)(TomConfigPtr->GtmTomTgcConfigGrpPtr->GtmTomEndisStat);

        }

      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lSaveAgcStatus(Ifx_GTM_ATOM_AGCx *AtomAgcRegPtr)         **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  AtomAgcRegPtr - Pointer to AGC configuration             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to save AGC's current configuration             **
*******************************************************************************/
static _INLINE_ void Gtm_lSaveAgcStatus(Ifx_GTM_ATOM_AGCx *AtomAgcRegPtr)
{
  uint8 MinorCnt;

  for(MinorCnt = GTM_ZERO_U; MinorCnt < GTM_SIXTEEN_U; MinorCnt++)
  {
    if((AtomAgcRegPtr->AGC_ENDIS_STAT.U &  \
      (GTM_ATOM_CHAN_ENABLE<<(MinorCnt * GTM_ATOM_BITS_PER_CHAN)))> GTM_ZERO_UL)
    {
      AtomAgcRegPtr->AGC_ENDIS_CTRL.U =                                 \
             (uint32_t)(~(GTM_ATOM_CHAN_DISABLE <<  \
             (MinorCnt * GTM_ATOM_BITS_PER_CHAN)));

    }
    if((AtomAgcRegPtr->AGC_OUTEN_STAT.U &
      (GTM_ATOM_CHAN_ENABLE<<(MinorCnt * GTM_ATOM_BITS_PER_CHAN)))> GTM_ZERO_UL)
    {
      AtomAgcRegPtr->AGC_OUTEN_CTRL.U =                                 \
             (uint32_t)(~(GTM_ATOM_CHAN_DISABLE << \
             (MinorCnt * GTM_ATOM_BITS_PER_CHAN)));
    }

  }
}


/*******************************************************************************
** Syntax : void Gtm_lAtomHostTrigger(void)                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to provide ATOM Host Trigger                    **
*******************************************************************************/
static _INLINE_ void Gtm_lAtomHostTrigger(void)
{
  Ifx_GTM_ATOM *AtomAgcRegPtr;             /* Pointer to ATOM AGC Reg   */
  uint8 MajorCnt;                          /* Variable to maintain Loop Count */



  /* Check the Fupd status and invoke a Host Trigger to set the clocks        */
  /* MajorCnt - Count to maintain ATOM Module Count            */
  for(MajorCnt = GTM_ZERO_U; MajorCnt < GTM_NO_OF_ATOM_MODULES; MajorCnt++)
  {
    /* Extract the TGC number from the Loop Count */
    AtomAgcRegPtr = &(MODULE_GTM.ATOM[MajorCnt]);

    if(AtomAgcRegPtr->AGC.FUPD_CTRL.U & GTM_ATOM_AGC_GET_FUPD)
    {
      /* Invoke an Host Trigger */
      AtomAgcRegPtr->AGC.GLB_CTRL.U |= (uint32_t)GTM_BIT_SET;
    }
  }
}


/*******************************************************************************
** Syntax : void Gtm_lAtomAgcConfigure(void)                                  **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize ATOM AGC's                        **
*******************************************************************************/
static _INLINE_ void Gtm_lAtomAgcConfigure(void)
{
  Ifx_GTM_ATOM_AGCx *AtomAgcRegPtr;             /* Pointer to ATOM AGC Reg   */
  const Gtm_AtomAgcConfigType *AtomConfigPtr;    /* Pointer to ATOM Config    */
  uint8 AtomCnt;            /* Variable to ATOM Channel Initialization Count  */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleNo;           /* Variable to hold Module Number                 */

  /* Count to maintain track of the index in ATOM AGC Config     */
  AtomCnt = GTM_ZERO_U;
  /* MajorCnt -Count to maintain an index to the GtmAtomAgcUsage Array        */
  /* MinorCnt -Count to maintain an index to the channels in
     GtmAtomAgcUsage Array*/
  for(MajorCnt = GTM_ZERO_U;
      MajorCnt <(((GTM_NO_OF_ATOM_MODULES * GTM_NO_OF_AGC_PER_MODULE)/
                   GTM_BITS_IN_U32)+ GTM_ONE_U);
      MajorCnt++)
  {
    for(MinorCnt = GTM_ZERO_U;
       (((MajorCnt * GTM_BITS_IN_U32)+ MinorCnt) <                             \
       (GTM_NO_OF_ATOM_MODULES * GTM_NO_OF_AGC_PER_MODULE));
       MinorCnt++)

    {
      /* Check if the AGC is configured */
      if((Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAtomAgcUsage[MajorCnt] &      \
        (GTM_BIT_SET << MinorCnt)) > GTM_ZERO_UL)
      {
        /* Extract Module Number and Channel Number from the Loop Count       */
        ModuleNo = ((MajorCnt * GTM_BITS_IN_U32) + MinorCnt)/
                     GTM_NO_OF_AGC_PER_MODULE;

        /* MISRA Rule Violation 17.4
           Pointer arithmetic other than array indexing used
           This cannot be avoided because of Post Build structure */

        /* Get the pointer to the AGC configuration */
        AtomConfigPtr =         \
            &(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAtomAgcConfigPtr[AtomCnt]);

        AtomCnt++;

        /* Get the Pointer to the AGC registers */
        
        AtomAgcRegPtr = &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).         \
                                                       ATOM_AGC[ModuleNo]);
                           

        AtomAgcRegPtr->AGC_ACT_TB.U = AtomConfigPtr->GtmAtomActTb;
        AtomAgcRegPtr->AGC_INT_TRIG.U = (uint32)(AtomConfigPtr->GtmAtomIntTrig);

        /* Check if the AGC is configured ie. if the channels for AGC is
           configured for Complex usage */
        if(AtomConfigPtr->GtmAtomAgcConfigGrpPtr != NULL_PTR)
        {
          AtomAgcRegPtr->AGC_FUPD_CTRL.U =                      \
                             AtomConfigPtr->GtmAtomAgcConfigGrpPtr->GtmAtomFupd;
          AtomAgcRegPtr->AGC_OUTEN_CTRL.U =                             \
              (uint32)(AtomConfigPtr->GtmAtomAgcConfigGrpPtr->GtmAtomOutenCtrl);
          AtomAgcRegPtr->AGC_OUTEN_STAT.U =                             \
              (uint32)(AtomConfigPtr->GtmAtomAgcConfigGrpPtr->GtmAtomOutenStat);
          AtomAgcRegPtr->AGC_GLB_CTRL.U   =  (uint32_t)\
          ((uint32)AtomConfigPtr->GtmAtomAgcConfigGrpPtr->GtmAtomUpdateEn)     \
                                                               << GTM_SIXTEEN_U;
          AtomAgcRegPtr->AGC_ENDIS_CTRL.U =                             \
              (uint32)(AtomConfigPtr->GtmAtomAgcConfigGrpPtr->GtmAtomEndisCtrl);
          AtomAgcRegPtr->AGC_ENDIS_STAT.U =                             \
              (uint32)(AtomConfigPtr->GtmAtomAgcConfigGrpPtr->GtmAtomEndisStat);
        }

      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lPortConfig(void)                                        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize Port Interfaces to GTM            **
*******************************************************************************/
static _INLINE_ void Gtm_lPortConfig(void)
{
  const Gtm_PortConfigType *PortConfigPtr;       /* Pointer to Port Config    */
  uint8 Count;

  /* Port configuration for TIM Channels */
  PortConfigPtr = Gtm_kConfigPtr->GtmPortConfigPtr;
  if(Gtm_kConfigPtr->GtmPortConfigPtr != NULL_PTR)
  {
    for(Count = GTM_ZERO_U ; Count < GTM_NO_OF_TIM_MODULES ; Count++)
    {
      MODULE_GTM.INOUTSEL.TIM[Count].INSEL.U = PortConfigPtr->TimInSel[Count];
    }
    /* Port configuration for TOM and ATOM Channels */
    for(Count = GTM_ZERO_U ; Count < GTM_NO_OF_TOUTSEL_REGISTERS ; Count++)
    {
      MODULE_GTM.INOUTSEL.T.OUTSEL[Count].U = PortConfigPtr->ToutSel[Count];
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lTbuConfig(void)                                         **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize TBU                               **
*******************************************************************************/
static _INLINE_ void Gtm_lTbuConfig(void)
{
  const Gtm_TbuConfigType *TbuConfigPtr;         /* Pointer to Tbu Config     */
  volatile Gtm_TbuType *GtmTbu;                  /* TBU Register type         */
  uint8 Count;

  /* Check if Tbu need to be Initialized */
  if(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTbuConfigPtr != NULL_PTR)
  {
    GtmTbu = (volatile Gtm_TbuType*)(void*)&(MODULE_GTM.TBU);

    for(Count =GTM_ZERO_U; Count < GTM_NO_OF_TBU_CHANNELS; Count++)
    {
      /* MISRA Rule Violation 17.4
         Pointer arithmetic other than array indexing used
         This cannot be avoided because of Post Build structure */

     TbuConfigPtr=&(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTbuConfigPtr[Count]);
      /* If the Tbu channel need to initialized*/
      if(Gtm_lGetUnused8(TbuConfigPtr->TbuChannelCtrl) == (boolean)FALSE)
      {
        /* Disable the channel if in case enabled prior */
        GTM_TBU_CHEN.U = (uint32_t)(GTM_BIT_SET << (GTM_BITS_PER_TBU * Count));
        GtmTbu->GtmTbuCh[Count].CH_CTRL.U =                       \
                     (uint32_t)((uint32)TbuConfigPtr->TbuChannelCtrl &         \
                     GTM_TBU_GET_LOWER_NIBBLE);
        GtmTbu->GtmTbuCh[Count].CH_BASE.U = TbuConfigPtr->TbuBaseValue;
        GTM_TBU_CHEN.U = ((uint32_t)(Gtm_lGetBit8(TbuConfigPtr->TbuChannelCtrl,\
                         GTM_TBU_CONFIGURED))                                  \
                         << ((GTM_BITS_PER_TBU * Count) + GTM_ONE_U));
      }
    }
  }
}


/*******************************************************************************
** Syntax : void Gtm_lF2aConfig(void)                                         **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize F2A                               **
*******************************************************************************/
static _INLINE_ void Gtm_lF2aConfig(void)
{
  const Gtm_F2aConfigType *F2aConfigPtr;         /* Pointer to F2a Config     */
  uint8 Count;

  /* Check if F2a is configured */
  if(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmF2aConfigPtr != NULL_PTR)
  {
    for(Count=GTM_ZERO_U; Count < GTM_NO_OF_FIFO_CHANNELS; Count++)
    {
      /* MISRA Rule Violation 17.4
         Pointer arithmetic other than array indexing used
         This cannot be avoided because of Post Build structure */

     F2aConfigPtr=&(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmF2aConfigPtr[Count]);


      /* Check if the F2a channel is configured */
      if(Gtm_lGetUnused8(F2aConfigPtr->F2aChannelConfig) == (boolean)FALSE)
      {
        /* Disable the channel before changing parameters */
        GTM_F2A0_ENABLE.U = \
                          (uint32_t)(GTM_BIT_SET << (Count * GTM_BITS_PER_F2A));
        MODULE_GTM.F2A0.RD_CH[Count].ARU_RD_FIFO.U = \
                                          (uint32)(F2aConfigPtr->F2aAruAddress);
        MODULE_GTM.F2A0.STR_CH[Count].STR_CFG.U = \
            ((uint32_t)((uint32)F2aConfigPtr->F2aChannelConfig &  \
            GTM_F2A_STR_CFG_MASK) << GTM_SIXTEEN_U);
        if(Gtm_lGetBit8(F2aConfigPtr->F2aChannelConfig,GTM_F2A_CONFIGURED) ==
          GTM_ONE_U)
        {
          GTM_F2A0_ENABLE.U = \
                       (uint32_t)(GTM_F2A_ENABLE << (Count * GTM_BITS_PER_F2A));
        }
      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lMcsConfig(void)                                         **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize MCS                               **
*******************************************************************************/
static _INLINE_ void Gtm_lMcsConfig(void)
{
  const Gtm_McsConfigType *McsConfigPtr;         /* Pointer to MCS Config     */
  uint8 Count;
  uint8 LoopCount;

  /* If any MCS Module is configured */
  if(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmMcsConfigPtr != NULL_PTR)
  {
    for(Count = GTM_ZERO_U; Count < GTM_NO_OF_MCS_MODULES; Count++)
    {
      /* MISRA Rule Violation 17.4
         Pointer arithmetic other than array indexing used
         This cannot be avoided because of Post Build structure */

     McsConfigPtr=&(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmMcsConfigPtr[Count]);


      /* Check if the Mcs module is configured */
      if(Gtm_lGetUnused8(McsConfigPtr->McsControl) == (boolean)FALSE)
      {
        MODULE_GTM.MCS[Count].CTRL.U = McsConfigPtr->McsControl;
        for(LoopCount = GTM_ZERO_U; LoopCount< GTM_NO_OF_MCS_CHANNELS;
            LoopCount++)
        {
          /* Clear the Pending Interrupt */
         ((*(Ifx_GTM_MCSx*)(void *)(MODULE_GTM.MCS)).CH_MCS[Count].
                     CH[LoopCount].CH_IRQ_NOTIFY.U) =  GTM_MCS_CLEAR_INTERRUPTS;
                                                       
          ((*(Ifx_GTM_MCSx*)(void *)(MODULE_GTM.MCS)).                         \
          CH_MCS[Count].CH[LoopCount].CH_IRQ_MODE.U) = (uint32_t)
           (((uint32)(McsConfigPtr->McsChannelConfig[LoopCount])               \
                                   & GTM_GET_MODE_VAL_8) >> GTM_SHIFT_TO_LSB_8);

          ((*(Ifx_GTM_MCSx*)(void *)(MODULE_GTM.MCS)).CH_MCS[Count].          \
           CH[LoopCount].CH_IRQ_EN.U)  = (uint32_t)(((uint32)                 \
           (McsConfigPtr->McsChannelConfig[LoopCount])& GTM_GET_MCS_IRQ_VAL)  \
                                                                 >> GTM_ONE_U);
                                           
          ((*(Ifx_GTM_MCSx*)(void *)(MODULE_GTM.MCS)).
           CH_MCS[Count].CH[LoopCount].CH_EIRQ_EN.U) = (uint32_t)             \
            (((uint32)(McsConfigPtr->McsErrIrqEnable[LoopCount])              \
                                               & (uint32)GTM_GET_MCS_EIRQ_VAL));

          /* Check if the MCS channel need to be enabled */
          if(Gtm_lGetBit8(McsConfigPtr->McsChannelConfig[LoopCount],GTM_ZERO_U))
          {
            /* It is expected that no RAM Reset is ongoing */
            ((*(Ifx_GTM_MCSx*)(void *)(MODULE_GTM.MCS)).
            CH_MCS[Count].CH[LoopCount].CH_CTRL.U) =                           \
            (uint32_t)(Gtm_lGetBit8(McsConfigPtr->McsChannelConfig[LoopCount], \
                                                                  GTM_ZERO_U));
          }
          /* Enable SRN */
          MODULE_SRC.GTM.GTM[0].MCS[Count][LoopCount].U |= \
                                         (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);
        }
      }
    }
  }

}

/*******************************************************************************
** Syntax : void Gtm_lDpllConfig(void)                                        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize DPLL                              **
*******************************************************************************/
static _INLINE_ void Gtm_lDpllConfig(void)
{
  const Gtm_DpllConfigType *DpllConfigPtr;       /* Pointer to DPLL Config    */
  uint32 RegTemp;           /* Temporary variable to store the register value */
  uint8 Count;

  /* Check if Dpll module is configured */
  DpllConfigPtr = Gtm_kConfigPtr->GtmModuleConfigPtr->GtmDpllConfigPtr;
  if(DpllConfigPtr != NULL_PTR)
  {
    /* Disable Dpll if enabled prior */
    GTM_DPLL_CTRL_1.U &= (uint32_t)(~GTM_DPLL_ENABLE);
    GTM_DPLL_CTRL_0.U = DpllConfigPtr->DpllCtrl0;
    /* Write all information except DEN */
    GTM_DPLL_CTRL_1.U = \
              (uint32_t)(DpllConfigPtr->DpllCtrl1 & (uint32)(~GTM_DPLL_ENABLE));
    GTM_DPLL_APT.U   = DpllConfigPtr->DpllApt;
    GTM_DPLL_APS.U   = DpllConfigPtr->DpllAps;
    GTM_DPLL_ADD_IN_LD1.U  = DpllConfigPtr->DpllAddInLoad1;
    GTM_DPLL_ADD_IN_LD2.U  = DpllConfigPtr->DpllAddInLoad2;
    GTM_DPLL_NTI_CNT.U= (uint32)DpllConfigPtr->DpllNtiCnt;
    GTM_DPLL_APT_2C.U = (uint32)DpllConfigPtr->DpllApt2c;
    GTM_DPLL_APS_1C3.U= (uint32)DpllConfigPtr->DpllAps1c3;
    GTM_DPLL_CTRL_2.U = \
                  (uint32_t)(((uint32)DpllConfigPtr->DpllCtrl2) << GTM_EIGHT_U);
    GTM_DPLL_CTRL_3.U = \
                  (uint32_t)(((uint32)DpllConfigPtr->DpllCtrl3) << GTM_EIGHT_U);
    GTM_DPLL_CTRL_4.U = \
                  (uint32_t)(((uint32)DpllConfigPtr->DpllCtrl4) << GTM_EIGHT_U);
    /* Get NUTE and FST */
    RegTemp = (DpllConfigPtr->DpllAssort0 & GTM_GET_NUTE_FST);
    RegTemp |= (GTM_BIT_SET << GTM_DPLL_WNUT_POS); /* Set WNUT*/
    /* get VTN */
    RegTemp |= ((DpllConfigPtr->DpllAssort0 & GTM_GET_VTN) << GTM_BRING_TO_VTN);
    RegTemp |= (GTM_BIT_SET << GTM_DPLL_WVTN_POS); /* Set WVTN*/
    GTM_DPLL_NUTC.U = RegTemp;
    /* Get NUSE and FSS */
    RegTemp = \
         (DpllConfigPtr->DpllAssort0 & GTM_GET_NUSE_FSS) >> GTM_BRING_TO_LSB_19;
    RegTemp |= (GTM_BIT_SET << GTM_DPLL_WNUS_POS); /* Set WNUS*/
    /* get VSN*/
    RegTemp |= ((DpllConfigPtr->DpllAssort0 & GTM_GET_VSN) >>GTM_BRING_TO_VSN);
    RegTemp |= (GTM_BIT_SET << GTM_DPLL_WVSN_POS); /* Set WVSN*/
    GTM_DPLL_NUSC.U = RegTemp;
    /* Get OSS */
    GTM_DPLL_OSW.U = (uint32_t)((DpllConfigPtr->DpllAssort0 & GTM_DPLL_GET_OSS)\
                                                           >> GTM_BRING_TO_OSS);
    for(Count = GTM_ZERO_U; Count < GTM_DPLL_NO_OF_ACTIONS; Count++)
    {
      MODULE_GTM.DPLL.ID_PMTR[Count].U =(uint32)DpllConfigPtr->DpllPmtr[Count];
    }
    /* Clear Pending Interrupts */
    GTM_DPLL_IRQ_NOTIFY.U = GTM_DPLL_CLEAR_INTERRUPTS;
    GTM_DPLL_IRQ_EN.U = \
               (uint32_t)((DpllConfigPtr->DpllIrqEnable) & GTM_GET_IRQ_VAL_32);
    GTM_DPLL_IRQ_MODE.U = \
                (uint32_t)((DpllConfigPtr->DpllIrqEnable & GTM_GET_MODE_VAL_32)\
                                                        >> GTM_SHIFT_TO_LSB_32);
    GTM_DPLL_EIRQ_EN.U =  (uint32_t)((DpllConfigPtr->DpllErrIntEnable &       \
                                                     GTM_DPLL_GET_EIRQ_VAL_32));
                                                        
    /* Enable Dpll */
    GTM_DPLL_CTRL_1.U |= (uint32_t)(GTM_DPLL_ENABLE);

    /* SRN Enable */
    for(Count = GTM_ZERO_U; Count < GTM_NUMBER_OF_DPLL_INT; Count++)
    {
      MODULE_SRC.GTM.GTM[0].DPLL[Count].U |=                                   \
                                       (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lSpeConfig(void)                                         **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize SPE                               **
*******************************************************************************/
static _INLINE_ void Gtm_lSpeConfig(void)
{
  const Gtm_SpeConfigType *SpeConfigPtr;         /* Pointer to SPE Config     */
  uint8 Count;
  uint8 LoopCount;          /* Variable to maintain Loop Count                */


  for(Count = GTM_ZERO_U; Count < GTM_NO_SPE_MODULES; Count++)
  {
    SpeConfigPtr = Gtm_kConfigPtr->GtmModuleConfigPtr->GtmSpeConfigPtr[Count];
    /* Check if Spe module is configured */
    if(SpeConfigPtr != NULL_PTR)
    {
      MODULE_GTM.SPE[Count].PAT.U =  SpeConfigPtr->SpePattern;
      for(LoopCount = GTM_ZERO_U;
          LoopCount < GTM_NO_OF_SPE_PATTERNS; LoopCount++)
      {
        MODULE_GTM.SPE[Count].OUT_PAT[LoopCount].U =
                                     (uint32)SpeConfigPtr->SpeOutput[LoopCount];
      }
      MODULE_GTM.SPE[Count].CTRL_STAT.U = SpeConfigPtr->SpeCtrlStat;
      MODULE_GTM.SPE[Count].IRQ_NOTIFY.U = GTM_SPE_CLEAR_INTERRUPTS;
      MODULE_GTM.SPE[Count].IRQ_MODE.U =                                      \
           (uint32_t)(((uint32)SpeConfigPtr->SpeIrq & GTM_GET_MODE_VAL_8) >>   \
                        GTM_SHIFT_TO_LSB_8);
      MODULE_GTM.SPE[Count].IRQ_EN.U =                                       \
                   (uint32_t)((uint32)SpeConfigPtr->SpeIrq & GTM_GET_IRQ_VAL_8);
      MODULE_GTM.SPE[Count].EIRQ_EN.U = (uint32_t)                            \
                   ((uint32)SpeConfigPtr->SpeErrIrq & GTM_SPE_GET_EIRQ_VAL_32);
      MODULE_SRC.GTM.GTM[0].SPEIRQ[Count].U |=                                \
                                        (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lCmpConfig(void)                                         **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize CMP                               **
*******************************************************************************/
static _INLINE_ void Gtm_lCmpConfig(void)
{
  const Gtm_CmpConfigType *CmpConfigPtr;         /* Pointer to Cmp Config     */

  /* Check if Cmp module is configured */
  if(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmCmpConfigPtr != NULL_PTR)
  {
    CmpConfigPtr = Gtm_kConfigPtr->GtmModuleConfigPtr->GtmCmpConfigPtr;
    MODULE_GTM.CMP.IRQ_NOTIFY.U = GTM_CMP_CLEAR_INTERRUPTS;
    MODULE_GTM.CMP.IRQ_MODE.U = \
               (uint32_t)((CmpConfigPtr->CmpIntEnable & GTM_GET_MODE_VAL_32) >>\
                                                           GTM_SHIFT_TO_LSB_32);
    MODULE_GTM.CMP.IRQ_EN.U = \
                    (uint32_t)(CmpConfigPtr->CmpIntEnable & GTM_GET_IRQ_VAL_32);
    MODULE_GTM.CMP.EN.U = CmpConfigPtr->CmpEnable;
    SRC_GTM_GTM0_CMPIRQ.U |= (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);
    MODULE_GTM.CMP.EIRQ_EN.U = \
            (uint32_t)(CmpConfigPtr->CmpErrIntEnable & GTM_CMU_GET_EIRQ_VAL_32);
  }
}

/*******************************************************************************
** Syntax : void Gtm_lMscConnectionsConfig(void)                              **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize MSC Connections                   **
*******************************************************************************/
static _INLINE_ void Gtm_lMscConnectionsConfig(void)
{
  const Gtm_MscConnectionsType *McsConnectionsPtr;/*Ptr to Msc Connections    */
  const Gtm_MscSetType *MscSetPtr;                /* Pointer to MSC Sets      */
  Gtm_MscSetsType *McsSets;                       /* Pointer to MSC Sets Reg  */
  const Gtm_MscInputCtrlType *MscInputCtrlPtr;   /* Pointer to MSC Input Ctrl */
  uint8 Count;
  uint8 LoopCount;                         /* Variable to maintain Loop Count */


  /* Check if Msc Connections is configured */
  if(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmMscConnectionsPtr != NULL_PTR)
  {
   McsConnectionsPtr = Gtm_kConfigPtr->GtmModuleConfigPtr->GtmMscConnectionsPtr;

    /* Initialization of MSC Sets registers */
    for(Count=GTM_ZERO_U;Count< GTM_NO_OF_MSC_SETS; Count++)
    {
      /* MISRA Rule Violation 17.4
         Pointer arithmetic other than array indexing used
         This cannot be avoided because of Post Build structure */

      MscSetPtr = &(McsConnectionsPtr->MscSets[Count]);


      for(LoopCount = GTM_ZERO_U;
          LoopCount < GTM_NO_MSC_CONTROLS_PER_SET; LoopCount++)
      {
        /* MISRA Rule Violation 11.4 and 1.2
         Unusual pointer cast (incompatible indirect types)
         cast from pointer to pointer
         Casting of MCS to Gtm_MscSetsType is done to change the base
         type of MCS as the type defined in SFR file is not flexible to
         provide an arrayed approach for accessing the MCS channels. */

        McsSets = (Gtm_MscSetsType*)(void*)&(MODULE_GTM.MSCSET_1S[Count]);


        McsSets->CON[LoopCount].U = MscSetPtr->MscConnection[LoopCount];
      }
    }
    /* Initialization of MSC Input Control registers */
    for(Count = GTM_ZERO_U ; Count < GTM_NO_OF_MSC_MODULES; Count++)
    {
      /* MISRA Rule Violation 17.4
         Pointer arithmetic other than array indexing used
         This cannot be avoided because of Post Build structure */

      MscInputCtrlPtr = &(McsConnectionsPtr->MscInputCtrlPtr[Count]);

      MODULE_GTM.MSCIN[Count].INLCON.U = MscInputCtrlPtr->MscLowControl;
      MODULE_GTM.MSCIN[Count].INHCON.U = MscInputCtrlPtr->MscHighControl;
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lDsadcConnectionsConfig(void)                            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize DSADC Connections                 **
*******************************************************************************/
static _INLINE_ void Gtm_lDsadcConnectionsConfig(void)
{
  const Gtm_DsadcConnectionsType *DsadcConnectionsPtr;/*Ptr to DSADC Connect  */

  /* Check if Dsadc Connections is configured */
  if(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmDsadcConnectionsPtr != NULL_PTR)
  {
    DsadcConnectionsPtr =                                                      \
                     Gtm_kConfigPtr->GtmModuleConfigPtr->GtmDsadcConnectionsPtr;

    GTM_DSADCINSEL0.U   = DsadcConnectionsPtr->DsadcInsel0;
    GTM_DSADCINSEL1.U   = DsadcConnectionsPtr->DsadcInsel1;
    GTM_DSADCINSEL2.U   = DsadcConnectionsPtr->DsadcInsel2;
    GTM_DSADCOUTSEL00.U = DsadcConnectionsPtr->DsadcOutsel00;
    GTM_DSADCOUTSEL10.U = DsadcConnectionsPtr->DsadcOutsel10;
  }
}

/*******************************************************************************
** Syntax : void Gtm_lTtcanConnectionsConfig(void)                            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize TTCAN Connections                 **
*******************************************************************************/
static _INLINE_ void Gtm_lTtcanConnectionsConfig(void)
{
  MODULE_GTM.INOUTSEL.CAN.OUTSEL.U =  \
                        Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTtcanTriggers[0];
}

/*******************************************************************************
** Syntax : void Gtm_lEnableGtm(void)                                         **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to Enable GTM                                   **
*******************************************************************************/
static _INLINE_ void Gtm_lEnableGtm(void)
{
  volatile uint32 ReadBack;
  Mcal_ResetENDINIT();
  MODULE_GTM.CLC.B.DISR = GTM_ZERO_U;      /* Enable the GTM Module */

  /* Enable GTM Sleep */
  if(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmModuleSleepEnable==               \
                                                              GTM_SLEEP_ENABLE)
  {
    MODULE_GTM.CLC.B.EDIS = GTM_ZERO_U;    /* Enable Sleep Mode if configured */
  }
  else
  {
    MODULE_GTM.CLC.B.EDIS = GTM_ONE_U;   /* Disable Sleep Mode if configured */
  }

  Mcal_SetENDINIT();

  /* Read back the CLC register */
  ReadBack = MODULE_GTM.CLC.U;

  /* ReadBack is required to ensure the CLC register modifications */
  UNUSED_PARAMETER(ReadBack)
}

/*******************************************************************************
** Syntax : void Gtm_lMapConfigure(void)                                      **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to Initialize MAP Module                        **
*******************************************************************************/
static _INLINE_ void Gtm_lMapConfigure(void)
{
  /* Check if Map module is configured */
  if(Gtm_lGetUnused32(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmMapConfig))
  {
    GTM_MAP_CTRL.U = Gtm_kConfigPtr->GtmModuleConfigPtr->GtmMapConfig;
  }
}

/*******************************************************************************
** Syntax : void Gtm_lTomConfigure(void)                                      **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to Initialize TOM Module                        **
*******************************************************************************/
static _INLINE_ void Gtm_lTomConfigure(void)
{
  Ifx_GTM_TOM_TGC_TYPE *TomTgcRegPtr;               /* Pointer to TOM TGC Reg */
  /* The following 3 variables backs up the FUPD, OUTEN and ENDIS before
     initialization of TOM/ATOM channels start. The array size should be maximum
     of TOM and ATOM. ATOM channels are more and TOM TGC's are more */
  uint32 FupdBackupValue[GTM_NO_OF_ATOM_MODULES][GTM_NO_OF_TGC_PER_MODULE];
  uint32 OutenCtrlBackupValue[GTM_NO_OF_ATOM_MODULES][GTM_NO_OF_TGC_PER_MODULE];
  uint32 EndisCtrlBackupValue[GTM_NO_OF_ATOM_MODULES][GTM_NO_OF_TGC_PER_MODULE];
  uint8 Count;              /* Variable to maintain Loop Count                */
  uint8 LoopCount;          /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleIndex;        /* Variable to hold the Module that uses the Timer*/



  /* This is required to retain the old values of EndisCtrl, OutenCtrl and Fupd,
     hence a Fupd given for setting the new clock value will not affect the
     previously existing channels */
  for(Count = GTM_ZERO_U; Count < GTM_NO_OF_TOM_MODULES; Count++)
  {
    for(LoopCount = GTM_ZERO_U;
        LoopCount < GTM_NO_OF_TGC_PER_MODULE; LoopCount++)
    {
      TomTgcRegPtr = &((*(Ifx_GTM_TOMx*)(void*)
                               (MODULE_GTM.TOM)).TOM_TGC[Count].TGC[LoopCount]);

      FupdBackupValue[Count][LoopCount] = TomTgcRegPtr->FUPD_CTRL.U;
      OutenCtrlBackupValue[Count][LoopCount] =                                 \
                                           TomTgcRegPtr->OUTEN_CTRL.U;
      EndisCtrlBackupValue[Count][LoopCount] =                                 \
                                           TomTgcRegPtr->ENDIS_CTRL.U;
      /* Make EndisCtrl and OutenCtrl to its Stat values */
      /* Clear the FUPD contents so on a Host Trigger, none of the old
         parameters are updated */
      TomTgcRegPtr->FUPD_CTRL.U = GTM_TOM_TGC_CLEAR_FUPD;

      Gtm_lSaveTgcStatus(TomTgcRegPtr);

      for(MinorCnt = GTM_ZERO_U;
          MinorCnt < GTM_TOM_CHANNELS_PER_TGC; MinorCnt++)
      {

        ModuleIndex = Gtm_lGetModuleIndex(                                     \
        (uint32)(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTomModuleUsage[Count]),
                    (uint8)(MinorCnt + (LoopCount * GTM_TOM_CHANNELS_PER_TGC)));

        if(ModuleIndex > GTM_ZERO_U)
        {

          /* Clear the information in FUPD/OutEn/EndisCtrl if the corresponding
             channel is configured for GPT or PWM */
          FupdBackupValue[Count][LoopCount] &=
                   ~(GTM_TOM_CHAN_ENABLE << (GTM_TOM_BITS_PER_CHAN * MinorCnt));
          OutenCtrlBackupValue[Count][LoopCount]&=
                   ~(GTM_TOM_CHAN_ENABLE << (GTM_TOM_BITS_PER_CHAN * MinorCnt));
          EndisCtrlBackupValue[Count][LoopCount]&=
                   ~(GTM_TOM_CHAN_ENABLE << (GTM_TOM_BITS_PER_CHAN * MinorCnt));
        }
      }
    }
  }

#if ((GTM_PWM_MODULE_USED == STD_ON) || (GTM_GPT_MODULE_USED == STD_ON))
  /* Clock Setting for GPT and PWM Modules */
  Gtm_lTomClockSetting();
  Gtm_lTomHostTrigger();
  /* Clock Settings End */
#endif
  /*  #if ((GTM_PWM_MODULE_USED == STD_ON) || (GTM_GPT_MODULE_USED == STD_ON))*/


  Gtm_lTomComplexConfig();

  Gtm_lTomTgcConfigure();

  /* Get the old values of Fupd/OutenCtrl/OutenStat values back again */
  for(Count = GTM_ZERO_U; Count < GTM_NO_OF_TOM_MODULES; Count++)
  {
    for(LoopCount = GTM_ZERO_U;
        LoopCount < GTM_NO_OF_TGC_PER_MODULE; LoopCount++)
    {
      /* Get the pointer to the TOM Registers */
      TomTgcRegPtr = &((*(Ifx_GTM_TOMx*)                                       \
                       (void *)(MODULE_GTM.TOM)).TOM_TGC[Count].TGC[LoopCount]);
      for(MinorCnt = GTM_ZERO_U; MinorCnt < GTM_SIXTEEN_U; MinorCnt++)
      {
        if((EndisCtrlBackupValue[Count][LoopCount]&                            \
                   (GTM_TOM_CHAN_ENABLE<<(MinorCnt * GTM_TOM_BITS_PER_CHAN)))> \
                   GTM_ZERO_UL)
        {
          TomTgcRegPtr->ENDIS_CTRL.U |=                             \
                (uint32_t)(GTM_TOM_CHAN_DISABLE <<                            \
                ((MinorCnt * GTM_TOM_BITS_PER_CHAN)+GTM_ONE_U));

        }
        if((OutenCtrlBackupValue[Count][LoopCount]&
                 (GTM_TOM_CHAN_ENABLE<<(MinorCnt * GTM_TOM_BITS_PER_CHAN)))>   \
                 GTM_ZERO_UL)
        {
          TomTgcRegPtr->OUTEN_CTRL.U |=                              \
                (uint32_t)(GTM_TOM_CHAN_DISABLE <<                             \
                ((MinorCnt * GTM_TOM_BITS_PER_CHAN)+GTM_ONE_U));
        }
        if((FupdBackupValue[Count][LoopCount] &
                (GTM_TOM_CHAN_ENABLE<<(MinorCnt * GTM_TOM_BITS_PER_CHAN))) >   \
                GTM_ZERO_UL)
        {
          TomTgcRegPtr->FUPD_CTRL.U |=                               \
                (uint32_t)(GTM_TOM_CHAN_DISABLE <<                             \
                ((MinorCnt * GTM_TOM_BITS_PER_CHAN)+GTM_ONE_U));
        }
      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lAtomConfigure(void)                                     **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to Initialize ATOM Module                       **
*******************************************************************************/
static _INLINE_ void Gtm_lAtomConfigure(void)
{
  Ifx_GTM_ATOM_AGCx *AtomAgcRegPtr;              /* Pointer to ATOM Registers*/
  /* The following 3 variables backs up the FUPD, OUTEN and ENDIS before
     initialization of TOM/ATOM channels start. The array size should be maximum
     of TOM and ATOM. ATOM channels are more and TOM TGC's are more */
  uint32 FupdBackupValue[GTM_NO_OF_ATOM_MODULES][GTM_NO_OF_TGC_PER_MODULE]=   \
                                                                     {{0U,0U}};
  uint32 OutenCtrlBackupValue[GTM_NO_OF_ATOM_MODULES][GTM_NO_OF_TGC_PER_MODULE]\
                                                                   = {{0U,0U}};
  uint32 EndisCtrlBackupValue[GTM_NO_OF_ATOM_MODULES][GTM_NO_OF_TGC_PER_MODULE]
                                                                    ={{0U,0U}};
  volatile uint8 Count;              /* Variable to maintain Loop Count       */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleIndex;        /* Variable to hold the Module that uses the Timer*/
  uint8 ChNo;        /* Variable to hold the Module number index */



  /* This is required to retain the old values of EndisCtrl, OutenCtrl and Fupd,
     hence a Fupd given for setting the new clock value will not affect the
     previously existing channels */
  for(Count = GTM_ZERO_U; Count < GTM_NO_OF_ATOM_MODULES; Count++)
  {
    /* Get the pointer to the ATOM Registers */
    ChNo = Count;
    AtomAgcRegPtr = &((*(Ifx_GTM_ATOMx*)(void*)(MODULE_GTM.ATOM)).         \
                                                       ATOM_AGC[Count]);
    

                                                          
    FupdBackupValue[Count][GTM_ZERO_U] = AtomAgcRegPtr->AGC_FUPD_CTRL.U;
    OutenCtrlBackupValue[Count][GTM_ZERO_U] = \
                                         AtomAgcRegPtr->AGC_OUTEN_CTRL.U;
    EndisCtrlBackupValue[Count][GTM_ZERO_U] = \
                                         AtomAgcRegPtr->AGC_ENDIS_CTRL.U;
    /* Make EndisCtrl and OutenCtrl to its Stat values */
    /* Clear the FUPD contents so on a Host Trigger, none of the old
       parameters are updated */
    AtomAgcRegPtr->AGC_FUPD_CTRL.U = GTM_ATOM_AGC_CLEAR_FUPD;

    Gtm_lSaveAgcStatus(AtomAgcRegPtr);
    ChNo = ((ChNo % GTM_TWO_U) == GTM_ONE_U ) ? (ChNo + GTM_SIXTEEN_U):(ChNo);

    for(MinorCnt = GTM_ZERO_U; MinorCnt < GTM_ATOM_CHANNELS_PER_AGC; MinorCnt++)
    {
      ModuleIndex = Gtm_lGetModuleIndex(
                                   (uint32)(Gtm_kConfigPtr->GtmModuleConfigPtr->
                                         GtmAtomModuleUsage[Count/GTM_TWO_U]), \
                                          ChNo);
      
      if(ModuleIndex > GTM_ZERO_U)
      {
        /* Clear the information in FUPD/OutEn/EndisCtrl if the corresponding
           channel is configured for GPT or PWM */
        FupdBackupValue[Count][GTM_ZERO_U] &= \
                 ~(GTM_ATOM_CHAN_ENABLE << (GTM_ATOM_BITS_PER_CHAN * MinorCnt));
        OutenCtrlBackupValue[Count][GTM_ZERO_U] &= \
                 ~(GTM_ATOM_CHAN_ENABLE << (GTM_ATOM_BITS_PER_CHAN * MinorCnt));
        EndisCtrlBackupValue[Count][GTM_ZERO_U] &= \
                 ~(GTM_ATOM_CHAN_ENABLE << (GTM_ATOM_BITS_PER_CHAN * MinorCnt));
      }
    }
  }



#if ((GTM_PWM_MODULE_USED == STD_ON) || (GTM_GPT_MODULE_USED == STD_ON))
  /* Clock Settings */
  Gtm_lAtomClockSetting();
  Gtm_lAtomHostTrigger();
  /* Clock Settings End */
#endif
  /* #if ((GTM_PWM_MODULE_USED == STD_ON) || (GTM_GPT_MODULE_USED == STD_ON)) */

  Gtm_lAtomComplexConfig();

  Gtm_lAtomAgcConfigure();


  /* Get the old values of Fupd/OutenCtrl/OutenStat values back again */
  for(Count = GTM_ZERO_U; Count < GTM_NO_OF_ATOM_MODULES; Count++)
  {
    /* Get the pointer to the ATOM Registers */
    AtomAgcRegPtr = &(*(Ifx_GTM_ATOM_AGCx*)(void *)(MODULE_GTM.ATOM));
    for(MinorCnt = GTM_ZERO_U; MinorCnt < GTM_SIXTEEN_U; MinorCnt++)
    {
      if((FupdBackupValue[Count][GTM_ZERO_U] & \
        (GTM_ATOM_CHAN_ENABLE << (MinorCnt * GTM_ATOM_BITS_PER_CHAN))) > \
        GTM_ZERO_UL)
      {
        AtomAgcRegPtr->AGC_FUPD_CTRL.U |= (uint32_t)\
          (GTM_ATOM_CHAN_DISABLE << ((MinorCnt * GTM_ATOM_BITS_PER_CHAN) + \
          GTM_ONE_U));
      }
      if((OutenCtrlBackupValue[Count][GTM_ZERO_U] & \
         (GTM_ATOM_CHAN_ENABLE << (MinorCnt * GTM_ATOM_BITS_PER_CHAN))) > \
         GTM_ZERO_UL)
      {
        AtomAgcRegPtr->AGC_OUTEN_CTRL.U |=(uint32_t)\
          (GTM_ATOM_CHAN_DISABLE << ((MinorCnt * GTM_ATOM_BITS_PER_CHAN) + \
          GTM_ONE_U));


      }
      if((EndisCtrlBackupValue[Count][GTM_ZERO_U] \
           & (GTM_ATOM_CHAN_ENABLE << (MinorCnt * GTM_ATOM_BITS_PER_CHAN))) >\
           GTM_ZERO_UL)
      {
        AtomAgcRegPtr->AGC_ENDIS_CTRL.U |= (uint32_t)\
          (GTM_ATOM_CHAN_DISABLE << ((MinorCnt * GTM_ATOM_BITS_PER_CHAN) + \
          GTM_ONE_U));


      }
    }
  }
}




/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1139_PR1138]
** Syntax : Gtm_AruReqStatusType Gtm_CtrlAruFrame(uint16 AruAddress, uint8    **
**                  ReqType, uint32* AruFrame, uint8 ReadReq)                 **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  AruAddress - ARU Address frame to be acted upon          **
                     ReqType – 0 – Request for Writing ARU frame              **
**                             1 – Request for Reading ARU frame              **
**                   AruFrame – Pointer to the location where                 **
**                              a)  In case of Write request, 2 uint32 ARU    **
**                                  frame content will be fetched from.       **
**                              b)  In case of read request, 2 uint32 ARU     **
**                                  frame will be written to.                 **
**                              Location pointed by AruFrame address will     **
**                              contain the Upper word of ARU frame. Location **
**                              pointer by AruFrame + 4 will contain the Lower**
**                              word of ARU frame.                            **
**                   ReadReq – This is applicable only if ReqType is 1        **
**                             0 – Only Issue a Read Request. ARU frame shall **
**                                 be reported only if the read is completed. **
**                             1 – Do not issue a Read Request. Only ARU frame**
**                                 content should be reported.                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     Boolean Status –                                         **
**                   When ReqType = 0,                                        **
**                      TRUE – Write request issued successfully.             **
**                      FALSE – Write could not be issued because of a        **
**                              previously pending request                    **
**                   When ReqType = 1,                                        **
**                      TRUE – Read request issued successfully. ARU Frame    **
**                             also read. Content pointed by AruFrame will be **
**                             valid                                          **
**                      FALSE –                                               **
**                   When ReadReq is 0,                                       **
**                   a) Read request not issued successfully because of       **
**                      previously pending request.                           **
**                   b) Read request issued successfully but ARU frame reading**
**                      is not completed.                                     **
**                   When ReadReq is 1,                                       **
**                   a) ARU Frame not read as ARU reading is not complete.    **
**                      Content pointed by AruFrame will be invalid.          **
**                                                                            **
** Description :     This service provides read and write functionality of    **
**                   ARU frames                                               **
*******************************************************************************/
Gtm_AruReqStatusType Gtm_CtrlAruFrame(uint16 AruAddress, uint8 ReqType,
                                  uint32* AruFrame,uint8 ReadReq)
{

  Gtm_AruReqStatusType RetVal;
  /* Initialize Return value as incorrect request */
  RetVal = GTM_INCORRECT_REQUEST;

  /* MISRA Rule Violation 17.4
     Pointer arithmetic other than array indexing used
     2 Words are accessed from AruAddress and hence pointer arithmetic is
     performed to simplify the code */

  /* Check if Writing ARU frame is requested */
  if(ReqType == GTM_WRITE_ARU_FRAME)
  {
    /* Initialize the return value as write failed */
    RetVal = GTM_ARU_WRITE_FAILED;
    /* Check if there is no pending Write or Read request */
    if((GTM_ARU_ACCESS.U & GTM_ARU_WREQ_RREQ_MASK) == 0UL)
    {
      /* No pending request present, process the Frame request */
      /* Write the data to be sent over ARU */
      GTM_ARU_DATA_L.U = *(AruFrame + 1);
      GTM_ARU_DATA_H.U = *AruFrame;
      /* Issue a Write request, providing the ARU address */
      GTM_ARU_ACCESS.U = AruAddress;
      GTM_ARU_ACCESS.U |= (uint32_t)GTM_ARU_WREQ_MASK;
      /* Update the Status */
      RetVal = GTM_ARU_WRITE_SUCCESSFUL;
    }
  }
  /* Check if Reading ARU frame is requested */
  else if(ReqType == GTM_READ_ARU_FRAME)
  {
    /* If the request is to issue a Read Request */
    if (ReadReq == GTM_ISSUE_ARU_READ)
    {
      /* Initialize the return value as Read failed */
      RetVal = GTM_ARU_READ_NOT_ISSUED;
      /* Check if there is no pending Write or Read request */
      if((GTM_ARU_ACCESS.U & GTM_ARU_WREQ_RREQ_MASK) == 0UL)
      {
        /* Issue a Read request, providing the ARU address */
        GTM_ARU_ACCESS.U = AruAddress;
        GTM_ARU_ACCESS.U |= (uint32_t)GTM_ARU_RREQ_MASK;
        /* Update the status for read issued but reading is not completed */
        RetVal = GTM_ARU_RD_ISSUED_BUT_NOT_CMPLT;
        /* Check if read is completed */
        if((GTM_ARU_ACCESS.U & GTM_ARU_RREQ_MASK) == 0UL)
        {
          /* Update the ARU frame information into the user buffer */
          *(AruFrame + 1) = GTM_ARU_DATA_L.U;
          *AruFrame = GTM_ARU_DATA_H.U;
          /* Update the Status */
          RetVal = GTM_ARU_RD_ISSUED_AND_COMPLETED;
        }
      }

    }
    else if(ReadReq == GTM_READ_ARU_CONTENT)
    {
      /* Initialize returns value as Read failed */
      RetVal = GTM_ARU_READ_FAILED;
      if((GTM_ARU_ACCESS.U & GTM_ARU_RREQ_MASK) == 0UL)
      {
        /* Update the ARU frame information into the user buffer */
        *(AruFrame + 1) = GTM_ARU_DATA_L.U;
        *AruFrame = GTM_ARU_DATA_H.U;
        /* Update the Status */
        RetVal = GTM_ARU_READ_SUCCESSFUL;
      }
    }
    else
    {
      /* Do Nothing */
    }
  }
  else
  {
    /* Do Nothing */
  }

  return(RetVal);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1092_4_PR1094_4]
** Syntax : void Gtm_ModifyOutputCtrl (uint8 TimerModule, uint8 ModuleNo,     **
**          uint8 ChannelNo, boolean ToEnable)                                **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  TimerModule - 0 – TOM,  1 - ATOM                         **
**                   ModuleNo – TOM Module Number                             **
**                   ChannelNo – TOM Channel Number                           **
**                   ToEnable – TRUE -> Enable TOM Output                     **
**                              FALSE -> Disable TOM Output                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service enables/disables the TOM Channel output.    **
*******************************************************************************/
void Gtm_ModifyOutputCtrl (uint8 TimerModule, uint8 ModuleNo,
                                    uint8 ChannelNo, boolean ToEnable)
{
  uint32 ActionToPerform;

  ActionToPerform = ((ToEnable == (boolean)TRUE)?\
                                           GTM_TOM_ENABLE:GTM_TOM_CHAN_DISABLE);

  if (TimerModule == GTM_TOM)
  {
    if(ChannelNo < GTM_TOM_TGC0_CHOSEN)
    {
      ((*(Ifx_GTM_TOMx*)(void *)(MODULE_GTM.TOM)).TOM_TGC[ModuleNo].          \
                                           TGC[GTM_TGC0].OUTEN_STAT.U) =      \
             (uint32_t)(ActionToPerform << (GTM_TOM_BITS_PER_CHAN * ChannelNo));
    }
    else if(ChannelNo < GTM_TOM_TGC1_CHOSEN)
    {
      ((*(Ifx_GTM_TOMx*)(void *)(MODULE_GTM.TOM)).TOM_TGC[ModuleNo].          \
                                                TGC[GTM_TGC1].OUTEN_STAT.U) = \
          (uint32_t)(ActionToPerform <<  \
          (GTM_TOM_BITS_PER_CHAN * (ChannelNo - GTM_TOM_CHANNELS_PER_TGC)));
    }
    else
    {
      /* Do Nothing */
    }
  }
  else if (TimerModule == GTM_ATOM)
  {
    if(ChannelNo < GTM_CHANNELS_PER_ATOM_MODULE)
    {
      MODULE_GTM.ATOM[ModuleNo].AGC.OUTEN_STAT.U =  \
            (uint32_t)(ActionToPerform << (GTM_ATOM_BITS_PER_CHAN * ChannelNo));
    }
  }
  else
  {
    /* Do Nothing */
  }
}

/*check if MCU InitCheck is enabled*/
#if (MCU_INITCHECK_API == STD_ON) 

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_GTM_SWSC_0001,DS_NAS_GTM_SWSC_0006,
DS_NAS_GTM_SWSC_0011,DS_NAS_GTM_SWSC_0130,SAS_NAS_GTM_SWSC_0075,
SAS_NAS_GTM_SWSC_0078]
 **
**                                                                            **
** Syntax          : void Gtm_InitCheck (const Gtm_ConfigType* ConfigPtr)     **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :    None                                                  **
**                                                                            **
** Sync/Async      :    Synchronous                                           **
**                                                                            **
** Reentrancy      :    Non Reentrant                                         **
**                                                                            **
** Parameters (in) :    ConfigPtr - Pointer to GTM Driver configuration set   **
**                                                                            **
** Parameters (out):    None                                                  **
**                                                                            **
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description     : This routine verifies the initialization the GTM driver. **
**                                                                            **
*******************************************************************************/
Std_ReturnType Gtm_InitCheck (const Gtm_ConfigType* ConfigPtr)
{
  uint32 TempCompVar = 0x0U;
  uint32 CompareVal = GTM_32_XOR_COMPARE_VAL;
  uint32 TempClockEnable;
  uint32 Count;
  const Gtm_GeneralConfigType *GeneralConfigPtr; /* Pointer to General Config */
  const Gtm_ClockSettingType *ClockSettingPtr;
  Std_ReturnType ErrorFlag;

  ErrorFlag = E_OK;    
  if (ConfigPtr == NULL_PTR)
  {
    ErrorFlag = E_NOT_OK;
  }
  else
  {
  ClockSettingPtr = ConfigPtr->GtmClockSettingPtr;
  GeneralConfigPtr = ConfigPtr->GtmModuleConfigPtr->GtmGeneralConfigPtr;

  TempClockEnable = ClockSettingPtr->GtmClockEnable;
  
  /* check the consistency of CLC register*/  
  TempCompVar = (uint32)(MODULE_GTM.CLC.B.EDIS);
  if(ConfigPtr->GtmModuleConfigPtr->GtmModuleSleepEnable == GTM_SLEEP_ENABLE)
  {
    TempCompVar = TempCompVar ^ ~(uint32)(GTM_ZERO_U);
  }
  else 
  {
    TempCompVar = TempCompVar ^ ~(uint32)(GTM_ONE_U);
  }
  CompareVal = ( TempCompVar == GTM_32_XOR_COMPARE_VAL) ? 
                                          CompareVal : (CompareVal & (0U));

  /* check the consistency of GTM CMU registers*/
  /* CMU CLK EN register*/  
  TempCompVar = TempClockEnable ^ GTM_GET_EN_REG_BIT;
  TempCompVar = TempCompVar ^ ~(uint32)GTM_CMU_CLK_EN.U;
  CompareVal = CompareVal ^ (~((uint32)TempCompVar));
  
  /* CMU CLK NUM and DEN register*/  
  TempCompVar = ConfigPtr->GtmModuleConfigPtr->GtmGclkNum;
  TempCompVar = TempCompVar ^ ~(((uint32)GTM_CMU_GCLK_NUM.U));
  CompareVal = CompareVal ^ (~((uint32)TempCompVar));
  TempCompVar = ConfigPtr->GtmModuleConfigPtr->GtmGclkDen; 
  TempCompVar = TempCompVar ^ ~(((uint32)GTM_CMU_GCLK_DEN.U));
  CompareVal = CompareVal ^ ~(((uint32)TempCompVar));
  

  /* CMU CLK CTRL register configuration*/
  for(Count = GTM_ZERO_U; Count < GTM_CMU_NO_OF_CLOCKS; Count++)
  {
    if((TempClockEnable ) &                              \
            (uint32)(GTM_CMU_CLK_ENABLE << (Count * GTM_CMU_BITS_PER_CLK)))
    {
      TempCompVar = ClockSettingPtr->GtmCmuClkCnt[Count];
      TempCompVar = TempCompVar ^ ~((uint32)(((Gtm_CmuType*)                \
                            (void*)&(MODULE_GTM.CMU))->ClkCtrl[Count].CTRL.U));
      CompareVal = CompareVal ^ ~((uint32)(TempCompVar));
    }
  }
  
  /* CMU EXT : NUM and DEN  register configuration*/
  for(Count = GTM_ZERO_U; Count < GTM_CMU_NO_OF_EXT_CLOCKS; Count++)
  {
   if(ClockSettingPtr->GtmClockEnable & \
      (uint32)(GTM_CMU_CLK_ENABLE <<((Count * GTM_CMU_BITS_PER_CLK) + \
      GTM_CMU_START_FROM_EXTCLK)))
   {
     TempCompVar = ClockSettingPtr->GtmEclk[Count].CmuEclkNum;
     TempCompVar = TempCompVar ^ ~((uint32)(((Gtm_CmuType*)
                      (void*)&(MODULE_GTM.CMU))->CmuEclk[Count].CmuEclkNum.U));
     CompareVal = CompareVal ^ ~((uint32)(TempCompVar));
       
     TempCompVar = ClockSettingPtr->GtmEclk[Count].CmuEclkDen;
     TempCompVar = TempCompVar ^ ~((uint32)(((Gtm_CmuType*)
                      (void*)&(MODULE_GTM.CMU))->CmuEclk[Count].CmuEclkDen.U));
     CompareVal = CompareVal ^ ~((uint32)(TempCompVar));
   }
  }
  
  /* CMU FXCLK register configuration*/  
  TempCompVar = (ClockSettingPtr->GtmFxdClkControl) & GTM_GET_FIXED_CLK_VAL;
  TempCompVar = TempCompVar ^ ~((uint32)
               ((((Gtm_CmuType*)(void*)&(MODULE_GTM.CMU))->GtmFxdClkControl)));
  CompareVal = CompareVal ^ ~(TempCompVar);

  /* check the consistency of GTM CTRL register*/        
  TempCompVar = GTM_CTRL.U ;
  TempCompVar = TempCompVar ^ ~((uint32)(GeneralConfigPtr->GtmCtrlValue));
  CompareVal = CompareVal ^ ~((uint32)(TempCompVar));
  /* check the consistency of GTM IRQ EN register */
  TempCompVar = GTM_IRQ_EN.U ;
  TempCompVar = TempCompVar ^ ~((uint32)
                         (GeneralConfigPtr->GtmIrqEnable & GTM_GET_IRQ_VAL_8));
  CompareVal = CompareVal ^ ~((uint32)(TempCompVar));
    /* check the consistency of GTM IRQ MODE register */
  TempCompVar = GTM_IRQ_MODE.U ;
  TempCompVar = TempCompVar ^ ~((uint32)(((GeneralConfigPtr->GtmIrqEnable) & \
                                   GTM_GET_MODE_VAL_8) >> GTM_SHIFT_TO_LSB_8));
  CompareVal = CompareVal ^ ~((uint32)(TempCompVar));
  /* check GTM SRN Enable register*/
  TempCompVar = (uint32)(SRC_GTMAEIIRQ.U & GTM_BIT_SRE_MASK) ;
  TempCompVar = TempCompVar ^ ~((uint32)(GTM_BIT_SET << GTM_BIT_SRE));
  CompareVal = CompareVal ^ ~((uint32)(TempCompVar));
  }
  if (!(CompareVal == GTM_32_XOR_COMPARE_VAL))
  {
    ErrorFlag = E_NOT_OK;
  }
  return ErrorFlag;
}

#endif
/* #if (MCU_INITCHECK_API == STD_ON) 
*/

#ifdef VALEO_PATCH_MCAL_FIX_ISR_MNGT
/*******************************************************************************
** Syntax : static _INLINE_ boolean Gtm_lTimerCheckIntTrig(uint8 IrqVal,      **
**                                           uint32 ChanIrqEnable,            **
**                                           uint8 CcuSelect)                 **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  IrqVal - Current Interrupt Value                         **
**                   ChanIrqEnable - Current Interrupt Enable Register Value  **
**                   CcuSelect - CCU0 or CCU1 to be evaluated                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to get the Interrupt Status                     **
*******************************************************************************/
static _INLINE_ boolean Gtm_lTimerCheckIntTrig(uint8 IrqVal,
                                             uint32 ChanIrqEnable,
                                             uint8 CcuSelect)
{
  boolean IntAvailable;
  IntAvailable = ((((IrqVal & CcuSelect)== CcuSelect) &&                       \
                   ((ChanIrqEnable & (uint32)CcuSelect) == (uint32)CcuSelect))?\
                    (boolean)TRUE:(boolean)FALSE);
  return(IntAvailable);
}
#endif  /* VALEO_PATCH_MCAL_FIX_ISR_MNGT */

#define GTM_STOP_SEC_CODE
#include "MemMap.h"


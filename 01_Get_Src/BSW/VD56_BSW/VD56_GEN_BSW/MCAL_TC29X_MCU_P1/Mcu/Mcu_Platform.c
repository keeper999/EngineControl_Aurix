/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Mcu_Platform.c $                                           **
**                                                                            **
**  $CC VERSION : \main\10 $                                                 **
**                                                                            **
**  $DATE       : 2014-01-21 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains AURIX derivative (platform specific)     **
**                functionality of MCU driver.                                **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Inclusion of controller sfr file */
#include "IfxScu_reg.h"
#include "Mcu.h"
#include "Mcu_Local.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* MACRO for Hardware timeout */
#define MCU_ERAY_MAX_TIMEOUT                 ((uint32)0x000001FFU)

/* MACRO for Oscillator to be disabled and power saving mode enabled */
#define MCU_OSCCON_DISOSC                    (3U)

/* Mask Values to be verified in Mcu_InitCheck */
#define MCU_PMSWCR0_MASK                     ((uint32)0x2080FF8EU) 

/* MASK for CCUCON Registers divider values */
#define MCU_CCUCON0_MASK_CLOCK_DIVIDERS      ((uint32)0x0F3F0FFFU)
#define MCU_CCUCON1_MASK_CLOCK_DIVIDERS      ((uint32)0x0FFFFFFFU)
#define MCU_CCUCON2_MASK_CLOCK_DIVIDERS      ((uint32)0x0000000FU)
#define MCU_CCUCON5_MASK_CLOCK_DIVIDERS      ((uint32)0x000000FFU)
#define MCU_CCUCON6_MASK_CLOCK_DIVIDERS      ((uint32)0x0000003FU)
#define MCU_CCUCON7_MASK_CLOCK_DIVIDERS      ((uint32)0x0000003FU)
#define MCU_CCUCON8_MASK_CLOCK_DIVIDERS      ((uint32)0x0000003FU)

/* MACRO for setting default value of PMSWCR0 during standby by MCU driver */
#define MCU_PMSWCR0_DEFAULT_VALUE            ((uint32)0x00620000U)
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define MCU_START_SEC_CODE
#include "MemMap.h"

/* ERAY PLL initialization function */
static Std_ReturnType Mcu_lErayPllClockInit(Mcu_ClockType ClockSetting);

/* Function to wait for VCO locking */
static _INLINE_ Std_ReturnType Mcu_lErayPllWaitVcoLock(void);

/* Functions to handle Standby Redundancy RAM */
static void Mcu_lHandleStandbyRAM(void);

#define MCU_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*Memory Map of the MCU Code*/
#define MCU_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax : Std_ReturnType Mcu_lPlatformInit (void)                           **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:  E_OK if successful else E_NOT_OK                            **
**                                                                            **
** Description :  This service shall initialize platform specific             **
**                functionality.                                              **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_lPlatformInit(void)
{
  Std_ReturnType RetValue;

  Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
  
  /* Initialize all clock dividers */
  SCU_CCUCON0.B.UP = 0U;
  SCU_CCUCON0.U = (uint32_t)
  (((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon0) &\
  MCU_CCUCON0_MASK_CLOCK_DIVIDERS)|MCU_CLKSEL_IS_PLL_AS_SOURCE);

  SCU_CCUCON1.B.UP = 0U;
  SCU_CCUCON1.U = (uint32_t)
  (((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon1) &\
  MCU_CCUCON1_MASK_CLOCK_DIVIDERS)|MCU_INSEL_IS_FOSC0_AS_SOURCE);

  SCU_CCUCON2.B.UP = 0U;
  SCU_CCUCON2.U = (uint32_t)
  ((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon2) &\
  MCU_CCUCON2_MASK_CLOCK_DIVIDERS);

  SCU_CCUCON5.B.UP = 0U;
  SCU_CCUCON5.U = (uint32_t)
  ((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon5) &\
  MCU_CCUCON5_MASK_CLOCK_DIVIDERS);

  /* Single Update for all CCUCON0,1,5 registers*/
  SCU_CCUCON0.B.UP=1U;
  /* Single Update for all CCUCON2 registers*/
  SCU_CCUCON2.B.UP=1U;

  SCU_CCUCON6.U = (uint32_t)
  ((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon6) &\
  MCU_CCUCON6_MASK_CLOCK_DIVIDERS);

  SCU_CCUCON7.U = (uint32_t)
  ((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon7) &\
  MCU_CCUCON7_MASK_CLOCK_DIVIDERS);

  SCU_CCUCON8.U = (uint32_t)
  ((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon8) &\
  MCU_CCUCON8_MASK_CLOCK_DIVIDERS);

  Mcal_SetSafetyENDINIT_Timed();
  
  /* Initialize ERAY sampling clock */
  RetValue = Mcu_lErayPllClockInit((Mcu_ClockType)Mcu_ClockSetting);
  
  return RetValue;
}/*End of Mcu_lPlatformInit()*/

/*******************************************************************************
** Syntax : Mcu_ResetType Mcu_lGetPlatformRstReason (void)                    **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   RstReasonRaw - Raw reset value                          **
**                                                                            **
** Parameters (out):  Type of reset occurred of Mcu_ResetType                 **
**                                                                            **
** Return value:      None                                                    **
**                                                                            **
** Description :  This service shall return the type of reset occurred        **
**                                                                            **
*******************************************************************************/
Mcu_ResetType Mcu_lGetPlatformRstReason(Mcu_RawResetType RstReasonRaw)
{
  Mcu_ResetType ResetValueToUser;

  /* Map the same to a value understandable by the user and which is in
  tandem with the one published in XDM */
  switch(RstReasonRaw)
  {
    case MCU_RAW_ESR0_RESET:
    {
      ResetValueToUser = MCU_ESR0_RESET;
      break;
    }
    case MCU_RAW_ESR1_RESET:
    {
      ResetValueToUser = MCU_ESR1_RESET;
      break;
    }
    case MCU_RAW_SMU_RESET:
    {
      ResetValueToUser = MCU_SMU_RESET;
      break;
    }
    case MCU_RAW_SW_RESET:
    {
      ResetValueToUser = MCU_SW_RESET;
      break;
    }
    case MCU_RAW_STM0_RESET:
    {
      ResetValueToUser = MCU_STM0_RESET;
      break;
    }
    case MCU_RAW_STM1_RESET:
    {
      ResetValueToUser = MCU_STM1_RESET;
      break;
    }
    case MCU_RAW_STM2_RESET:
    {
      ResetValueToUser = MCU_STM2_RESET;
      break;
    }
    case MCU_RAW_POWER_ON_RESET_1:
    case MCU_RAW_POWER_ON_RESET_2:
    {
      ResetValueToUser = MCU_POWER_ON_RESET;
      break;
    }
    case MCU_RAW_CB0_RESET:
    {
      ResetValueToUser = MCU_CB0_RESET;
      break;
    }
    case MCU_RAW_CB1_RESET:
    {
      ResetValueToUser = MCU_CB1_RESET;
      break;
    }
    case MCU_RAW_CB3_RESET:
    {
      ResetValueToUser = MCU_CB3_RESET;
      break;
    }
    case MCU_RAW_TP_RESET:
    {
      ResetValueToUser = MCU_TP_RESET;
      break;
    }
    case MCU_RAW_EVR13_RESET:
    {
      ResetValueToUser = MCU_EVR13_RESET;
      break;
    }
    case MCU_RAW_EVR33_RESET:
    {
      ResetValueToUser = MCU_EVR33_RESET;
      break;
    }
    case MCU_RAW_SUPPLY_WDOG_RESET:
    {
      ResetValueToUser = MCU_SUPPLY_WDOG_RESET;
      break;
    }
    case MCU_RAW_STBYR_RESET:
    {
      ResetValueToUser = MCU_STBYR_RESET;
      break;
    }
    default:
    {
      /* if none of the above match, give it as undefined */
      ResetValueToUser = MCU_RESET_UNDEFINED;
      break;
    }
  }

  return (ResetValueToUser);
}/*End of Mcu_lGetPlatformRstReason()*/

/*******************************************************************************
** Syntax : Std_ReturnType Mcu_lErayPllClockInit(Mcu_ClockType ClockSetting)  **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  E_OK if successful else E_NOT_OK                            **
**                                                                            **
** Description : Local function to initialize ERAY PLL                        **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Mcu_lErayPllClockInit(Mcu_ClockType ClockSetting)
{
  Std_ReturnType ErrorFlag;
  volatile uint32 PllStableDelay;
  uint8 PllNdiv;
  uint8 PllK2div;
  uint8 PllK3div;
  uint8 PllPdiv;

  /*Store PLL Divider values in local variables*/
  PllNdiv =Mcu_kConfigPtr->\
             ClockCfgPtr[ClockSetting].MCU_ErayPllDivValues.McuErayNDivider;

  PllK2div = Mcu_kConfigPtr->\
             ClockCfgPtr[ClockSetting].MCU_ErayPllDivValues.McuErayK2Divider;

  PllK3div = Mcu_kConfigPtr->\
             ClockCfgPtr[ClockSetting].MCU_ErayPllDivValues.McuErayK3Divider;
  PllPdiv = Mcu_kConfigPtr->\
             ClockCfgPtr[ClockSetting].MCU_ErayPllDivValues.McuErayPDivider;

   Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
  /* Enter Prescalar mode */
  /* Update K and N dividers */
  SCU_PLLERAYCON1.B.K1DIV = 0U;
  SCU_PLLERAYCON0.B.VCOBYP = 1U ;

  SCU_PLLERAYCON0.B.SETFINDIS = 1U;
  SCU_PLLERAYCON1.B.K2DIV = PllK2div;
  SCU_PLLERAYCON1.B.K3DIV = PllK3div;
  SCU_PLLERAYCON0.B.PDIV = PllPdiv;
  SCU_PLLERAYCON0.B.NDIV = PllNdiv;
  /* Enter normal mode */
  SCU_PLLERAYCON0.B.OSCDISCDIS = 1U;
  SCU_PLLERAYCON0.B.PLLPWD = 0U; /* Errata */
  SCU_PLLERAYCON0.B.CLRFINDIS = 1U;
  /*
    RESLD = 1     ==> Restart VCO lock detection
    CLRFINDIS = 1 ==> Connect OSC to PLL
    PLLPWD = 1    ==> PLL Power Saving Mode : Normal behaviour
    NDIV = FR_17_ERAY_PLL_NDIV (Pre-compile parameter)
  */
  SCU_PLLERAYCON0.B.PLLPWD = 1U;
  for(PllStableDelay=0U;PllStableDelay < MCU_PLL_STABLE_DELAY;PllStableDelay++)
  {}/*Errata*/
  SCU_PLLERAYCON0.B.RESLD = 1U;

  /* Set the ENDINIT bit in the WDT_CON0 register again
  to enable the write-protection and to prevent a time-out */
  Mcal_SetSafetyENDINIT_Timed();

  /* Wait for ERAY PLL VCO locking */
  ErrorFlag = Mcu_lErayPllWaitVcoLock();

  /*By Pass VCO only if PLL is locked*/
  if(ErrorFlag == E_OK)
  {
    /* Clear the ENDINIT bit in the WDT_CON0 register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);

    /*Bypass VCO*/
    SCU_PLLERAYCON0.B.VCOBYP = 0U;

    /* Distribute the clock */
    SCU_PLLERAYCON0.B.OSCDISCDIS = 0U;

    /* Set the ENDINIT bit in the WDT_CON0 register again
    to enable the write-protection and to prevent a time-out */
    Mcal_SetSafetyENDINIT_Timed();
  }
  return(ErrorFlag);
}/*End of Mcu_lErayPllClockInit()*/

/*******************************************************************************
** Syntax : void Mcu_lErayPllWaitVcoLock(void)                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Function to wait for ERAY PLL VCO locking                    **
**                                                                            **
*******************************************************************************/
static _INLINE_ Std_ReturnType Mcu_lErayPllWaitVcoLock(void)
{
  Std_ReturnType ErrorFlag;
  uint32 TimeOutCount;

  ErrorFlag = E_OK;
  TimeOutCount = MCU_ERAY_MAX_TIMEOUT;
  do
  {
    TimeOutCount-- ;
  } while ((SCU_PLLERAYSTAT.B.VCOLOCK != 1U) && (TimeOutCount > 0U)) ;

  if (TimeOutCount == 0U)
  {
    ErrorFlag = E_NOT_OK;
    #if (MCU_E_ERAY_TIMEOUT_DEM_REPORT == MCU_ENABLE_DEM_REPORT)
    Dem_ReportErrorStatus(MCU_E_ERAY_TIMEOUT, DEM_EVENT_STATUS_FAILED);
    #endif /*  #if (MCU_E_ERAY_TIMEOUT_DEM_REPORT == MCU_ENABLE_DEM_REPORT) */
  }
  return(ErrorFlag);
}/*End of Mcu_lErayPllWaitVcoLock()*/

/*******************************************************************************
** Syntax : void Mcu_lHandleStandbyRAM(void)                                  **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Function to handle Standby redundancy data                   **
**                                                                            **
*******************************************************************************/
static void Mcu_lHandleStandbyRAM(void)
{
  uint32 LoopCtr;
  uint32 *RARPtr;

  /* MISRA Rule 11.1 VIOLATION: cast from unsigned int to pointer, this is
     required to assign the ram base address to local variable to access
     ram memory.*/
  RARPtr = (uint32*)MCU_STANDBY_DSPR0_RAR_AREA;

  /* Read sequentially from DSPR0 reserved area used by firmware 
   * to store corrected redundancy data (RAR)
   */
  for (LoopCtr = 0U; LoopCtr < MCU_STANDBY_DSPR0_RAR_SIZE; LoopCtr++)
  {
    if ((*RARPtr != 0xFFFFFFFFU) && (*RARPtr != 0x0U))
    {
      uint32 *AddrPtr;
      /* MISRA Rule 11.1 VIOLATION: cast from unsigned int to pointer, this is
         required to assign the ram base address to local variable to access
         ram memory.*/      
      /* Use this as an address */
      AddrPtr = (uint32 *)(*RARPtr);
      /* Read the data and store it back in DSPR0 */
      *RARPtr = *AddrPtr;
    }
    RARPtr++;
  }
}/*End of Mcu_lHandleStandbyRAM()*/

/*******************************************************************************
** Syntax : void Mcu_lSetIdleMode(uint8 CoreId)                               **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): CoreId - Core Id                                          **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Function to enter Idle mode for CoreId                       **
**                                                                            **
*******************************************************************************/
void Mcu_lSetIdleMode(uint8 CoreId)
{
  uint8 CoreSelect;
  uint8 SystemModeSel;

  #if (MCU_SAFETY_ENABLE == STD_OFF)
  /* Clear the ENDINIT bit in the WDT_CON0 register in order
  to disable the write-protection for registers protected
  via the EndInit feature */
  /* The MCAL library disables the interrupts */
  Mcal_ResetENDINIT();
  #endif  
  
  CoreSelect = (uint8)(1U << CoreId);
  SystemModeSel = (uint8)SCU_PMSWCR1.B.CPUIDLSEL;
  if((CoreSelect == SystemModeSel) ||
     (MCU_INDIVIDUAL_CORE_IDLE_MODE == SystemModeSel))
  {
    MODULE_SCU.PMCSR[CoreId].B.REQSLP = ((uint8)(MCU_IDLE + 1U));
  }
  
  #if (MCU_SAFETY_ENABLE == STD_OFF)
  Mcal_SetENDINIT();
  #endif  
}/*End of Mcu_lSetIdleMode()*/

/*******************************************************************************
** Syntax : void Mcu_lSetSleepMode(uint8 CoreId)                              **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): CoreId - Core Id                                          **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Function to enter Sleep mode for CoreId                      **
**                                                                            **
*******************************************************************************/
void Mcu_lSetSleepMode(uint8 CoreId)
{
  uint8 CoreSelect;
  uint8 SystemModeSel;

  #if (MCU_SAFETY_ENABLE == STD_OFF)
  /* Clear the ENDINIT bit in the WDT_CON0 register in order
  to disable the write-protection for registers protected
  via the EndInit feature */
  /* The MCAL library disables the interrupts */
  Mcal_ResetENDINIT();
  #endif  
  
  CoreSelect = (uint8)(1U << CoreId);
  SystemModeSel = (uint8)SCU_PMSWCR1.B.CPUSEL;
  if((CoreSelect == SystemModeSel) ||
     (MCU_UNANIMOUS_SEL_SYSTEM_MODE == SystemModeSel))
  {
    MODULE_SCU.PMCSR[CoreId].B.REQSLP = ((uint8)(MCU_SLEEP + 1U));
  }

  #if (MCU_SAFETY_ENABLE == STD_OFF)
  Mcal_SetENDINIT();
  #endif    
}/*End of Mcu_lSetSleepMode()*/

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_MCUPR2869_PR2875_PR2877]             **
** Syntax : void Mcu_lSetStandbyMode(uint8 CoreId)                            **
** [/cover]                                                                   **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): CoreId - Core Id                                          **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Function to enter Standby mode for CoreId                    **
**                                                                            **
*******************************************************************************/
void Mcu_lSetStandbyMode(uint8 CoreId)
{
  uint8 CoreSelect;
  uint8 SystemModeSel;

  CoreSelect = (uint8)(1U << CoreId);
  SystemModeSel = (uint8)SCU_PMSWCR1.B.CPUSEL;
  
  /* Configure Standby only if enabled 
   * and the core is authorized to enter system to standby
   */ 
  if( (Mcu_kConfigPtr->StandbyCfgPtr != NULL_PTR) && 
      ((CoreSelect == SystemModeSel) ||
       (MCU_UNANIMOUS_SEL_SYSTEM_MODE == SystemModeSel)))
  {
    uint32 LoopCtr;
    uint32 CrcValue;
    uint32 *RARPtr;

    /* Handle RAM redundancy data */
    Mcu_lHandleStandbyRAM();
    
    if (Mcu_kConfigPtr->StandbyCfgPtr->CrcCheckEnable == (uint8)TRUE)
    { 
      CrcValue = 0U;
      /* MISRA Rule 11.1 VIOLATION: cast from unsigned int to pointer, this is
         required to assign the ram base address to local variable to access
         ram memory.*/            
      RARPtr = (uint32*)MCU_STANDBY_DSPR0_RAR_AREA;
      for (LoopCtr = 0U; LoopCtr < MCU_STANDBY_DSPR0_RAR_SIZE; LoopCtr++)
      {
        CrcValue = (uint32) CRC32((uint32)CrcValue, (uint32)*RARPtr);
        RARPtr++;
      }
      /* Store the caluclated CRC at the end of RAR area */
      *RARPtr = CrcValue;
    }
    
    #if (MCU_SAFETY_ENABLE == STD_OFF)
    Mcal_ResetENDINIT();    
    Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
    #endif

    #if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)
    /* Disable the clock monitoring unit */
    SCU_CCUCON3.U = 0U;
    SCU_CCUCON4.U = 0U;
    SCU_CCUCON9.U = 0U;   

    /* Single Update for all CCUCON3 & 4 registers*/
    SCU_CCUCON3.B.UP = 1U;

    /* Update for all CCUCON9 registers*/
    SCU_CCUCON9.B.UP = 1U;    
    #endif
    
    /*Select Back-up clock as the source for all clocks */
    SCU_CCUCON0.B.CLKSEL = 0U;
    /*Stop ADC clock */
    SCU_CCUCON0.B.ADCCLKSEL = 0U;
    /* Back-up clock is used as clock source is transferred to the CCU.*/
    SCU_CCUCON1.B.INSEL = 0U;
    /* Update for CCUCON0 and CCUCON1*/
    SCU_CCUCON1.B.UP = 1U;
    /* Disable Oscillator and put PLL/ERAY_PLL to power saving mode */
    SCU_OSCCON.B.MODE = MCU_OSCCON_DISOSC;
    /* VCO in Power Saving Mode */
    SCU_PLLCON0.B.VCOPWD = 1U; 
    SCU_PLLERAYCON0.B.VCOPWD = 1U; 
    /* PLL block is put into the Power Saving Mode */
    SCU_PLLCON0.B.PLLPWD = 0U; 
    SCU_PLLERAYCON0.B.PLLPWD = 0U;
    
    /* Set all pads to tristate and enable Standby RAM */
    MODULE_SCU.PMSWCR0.U |= (uint32_t)MCU_PMSWCR0_DEFAULT_VALUE;
   
    /* Configure IRADIS bit to disable Idle Request Acknowledge sequence 
     * activation for fast Standby Mode entry. This ensures that standby 
     * request is not blocked by a pending reset request / sequence
     */
    SCU_PMSWCR1.B.IRADIS = 1U;

    /* Configure Standby entry through REQSLP bit setting only */
    SCU_PMSWCR1.B.STBYEVEN = 1U; 
    SCU_PMSWCR1.B.STBYEV = 0U;

    /* Request the Standy mode */
    MODULE_SCU.PMCSR[CoreId].B.REQSLP = ((uint8)(MCU_STANDBY + 1U));
    
    #if (MCU_SAFETY_ENABLE == STD_OFF)
    Mcal_SetSafetyENDINIT_Timed();        
    Mcal_SetENDINIT();   
    #endif

  }
}/*End of Mcu_lSetStandbyMode()*/

#define MCU_STOP_SEC_CODE
#include "MemMap.h"

#define MCU_START_SEC_SAFETY_CODE
#include "MemMap.h"

#if (MCU_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Syntax : Std_ReturnType Mcu_lPlatformInitCheck (void)                      **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description :  This service shall verify the platform specific             **
**                initialization done by MCU.                                 **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_lPlatformInitCheck(void)
{
  Std_ReturnType ErrorFlag;
  uint32         TempFlag;
  uint32         TempFlag1;
  volatile uint32 CompareFlag = 0xFFFFFFFFU;  
  
  ErrorFlag = E_OK;

  if (Mcu_kConfigPtr->StandbyCfgPtr != NULL_PTR)
  {
    TempFlag = (uint32)SCU_PMSWCR0.U & MCU_PMSWCR0_MASK;
    TempFlag1 = Mcu_kConfigPtr->StandbyCfgPtr->PMSWCR0;

    CompareFlag &= (TempFlag ^ ~TempFlag1);  
  }  
  
  TempFlag = MCU_CCUCON0_MASK_CLOCK_DIVIDERS | MCU_CLKSEL_IS_PLL_AS_SOURCE;
  TempFlag1 = SCU_CCUCON0.U;
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon0 | 
        MCU_CLKSEL_IS_PLL_AS_SOURCE) 
        & TempFlag);

  TempFlag = MCU_CCUCON1_MASK_CLOCK_DIVIDERS | MCU_INSEL_IS_FOSC0_AS_SOURCE;
  TempFlag1 = SCU_CCUCON1.U;  
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon1 | 
        MCU_INSEL_IS_FOSC0_AS_SOURCE) 
        & TempFlag);

  TempFlag = MCU_CCUCON2_MASK_CLOCK_DIVIDERS;
  TempFlag1 = SCU_CCUCON2.U;  
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon2 & TempFlag);
     
  TempFlag = MCU_CCUCON5_MASK_CLOCK_DIVIDERS;
  TempFlag1 = SCU_CCUCON5.U;  
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon5 & TempFlag);       

  TempFlag = MCU_CCUCON6_MASK_CLOCK_DIVIDERS;
  TempFlag1 = SCU_CCUCON6.U;  
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon6 & TempFlag);       

  TempFlag = MCU_CCUCON7_MASK_CLOCK_DIVIDERS;
  TempFlag1 = SCU_CCUCON7.U;  
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon7 & TempFlag);       

  TempFlag = MCU_CCUCON8_MASK_CLOCK_DIVIDERS;
  TempFlag1 = SCU_CCUCON8.U;  
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon8 & TempFlag);   

  /* Verify PLL Eray settings */
  TempFlag = ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
              MCU_ErayPllDivValues.McuErayPDivider << 24U) |
            ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
              MCU_ErayPllDivValues.McuErayNDivider << 9U) |
             MCU_PLLPWD_IS_SET_TO_NORMAL; 
  TempFlag1 = SCU_PLLERAYCON0.U;
  CompareFlag &= (TempFlag1 ^ ~TempFlag);

  TempFlag = ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
              MCU_ErayPllDivValues.McuErayK3Divider << 8U) |
             (uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
              MCU_ErayPllDivValues.McuErayK2Divider;
  TempFlag1 = SCU_PLLERAYCON1.U;
  CompareFlag &= (TempFlag1 ^ ~TempFlag);
    
  if (CompareFlag != 0xFFFFFFFFU)     
  {
    ErrorFlag = E_NOT_OK;
  }
  
  return ErrorFlag;
}/*End of Mcu_lPlatformInitCheck()*/

#endif /*End Of MCU_SAFETY_ENABLE*/

#define MCU_STOP_SEC_SAFETY_CODE
#include "MemMap.h"

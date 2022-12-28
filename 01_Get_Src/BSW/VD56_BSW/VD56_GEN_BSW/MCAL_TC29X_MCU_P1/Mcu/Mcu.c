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
**  $FILENAME   : Mcu.c $                                                    **
**                                                                           **
**  $CC VERSION : \main\100 $                                                **
**                                                                           **
**  $DATE       : 2014-01-22 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains functionality of MCU driver.            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*  TRACEABILITY : [cover parentID=DS_NAS_PR912,DS_MCAL_SWSC_MCU0401,
  DS_MCAL_SWSC_MCU050,SAS_AS_MCU108_MCU211_MCU215_MCU109_MCU111_MCU213]    
                   [/cover]                                                   */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of controller sfr file */
#include "IfxSmu_reg.h"

  /* Inclusion of  Mcal header file */
#include "Mcal.h"

  /* Module header file, this includes module configuration file also */
  /* MCU108 :Inclusion of Mcu.h file*/
#include "Mcu.h"

#include "Mcu_Local.h"

#if (MCU_SAFETY_ENABLE == STD_ON)
#include "SafetyReport.h"
#endif
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/* Used to check the oscillator for PLL Valid Low Status Bit in OSCCON SFR*/
#define MCU_PLLLV_PLLHV_STATUS_CHECK   (0x00000102U)

#define MCU_RSTSTAT_MASK_VALUE         (0x13FD00FBU)
#define MCU_RSTSTAT_CLRC_BITS          (0x13810000U)

  /*This value masks the reset status register*/
#define MCU_RESET_REASON_MASK          (0x13BD00FBU)

  /*Delay in Microseconds for Mcu_InitClock and Mcu_DistributePllClock*/
#define MCU_DELAY                      (20UL)

/* When setting a bit to '1', this can be used */
#define MCU_BITVAL_1 (1U)

/* When setting a bit to '0', this can be used */
#define MCU_BITVAL_0 (0U)

/*Used for the delay after performing reset */
#define MCU_PERFORM_RESET_DELAY              (90000U)

/* Dealy for validating the frequency of PLL */
#define MCU_VALIDATE_OSC_FREQ_DELAY          (1000U)

/* Selection bit for normal mode in PLL status register */
#define MCU_PLLSTAT_NORMAL_MODE              (0x00U)

/* Delay for normal mode selection */
#define MCU_DELAY_NORMAL_MODE_SELECTION      (100U)

/* Macro to verify PLLCON0 - VCOBP = 1, OSCDISCDIS = 1 & PLLPWD = 1 */
#define MCU_PLLCON0_REGVAL_CHECK             (0x10001U)

/* Mask Values to be verified in Mcu_InitCheck */
#define MCU_PMSWCR1_MASK                     ((uint32)0x07001700U) 
#define MCU_OSCCON_MASK                      ((uint32)0x001F0102U)
#define MCU_PLLCON0_NORMAL_MASK              ((uint32)0x0F01FE43U)
#define MCU_PLLCON0_PRESCALAR_MASK           ((uint32)0x00010003U)
#define MCU_PLLCON1_PRESCALAR_MASK           ((uint32)0x007F0000U)
/* Mask for SMU alarms configuration related to PLL and OSC */
#define MCU_PLL_OSC_SMU_MASK                 ((uint32)0x00000007U)
#define MCU_PLL_CLKM_SMU_MASK                ((uint32)0x000003F8U)

/* Mask for STM timer reset settings*/
#define MCU_STM_RESET_ENABLE_MASK            ((uint32)0x00000007U)

/* MASK for CCUCON Registers divider values */
#define MCU_CCUCON3_MASK_CLOCK_DIVIDERS      ((uint32)0x00FFFFFFU)
#define MCU_CCUCON4_MASK_CLOCK_DIVIDERS      ((uint32)0x00FFFFFFU)
#define MCU_CCUCON9_MASK_CLOCK_DIVIDERS      ((uint32)0x000000FFU)

/* MASK for ADCCLKSEL bit in CCUCON0 */
#define MCU_CCUCON0_ADCCLKSEL_STOP           ((uint32)0x0C000000U)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define MCU_START_SEC_CODE
#include "MemMap.h"

#if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)
static _INLINE_ void Mcu_lInitClockMonitoring(void);
#endif

#define MCU_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


#if (MCU_PB_FIXEDADDR == STD_ON)
#define MCU_START_SEC_CONST_32BIT
/*
 * To be used for global or static variables (32 bits) that are initialized
 * after every reset (the normal case)
   Inclusion of MemMap.h
*/
#include "MemMap.h"

/* To store the Mcu driver configuration pointer */
const Mcu_ConfigType * const Mcu_kConfigPtr = &Mcu_ConfigRoot[0];

 /*
 * To be used for global or static variables (32 bits) that are initialized
 * after every reset (the normal case)
   Inclusion of MemMap.h
*/
#define MCU_STOP_SEC_CONST_32BIT
#include "MemMap.h"
#endif /*End Of MCU_PB_FIXEDADDR*/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

#define MCU_START_SEC_VAR_32BIT
#include "MemMap.h"

#if (MCU_PB_FIXEDADDR == STD_OFF)
const Mcu_ConfigType *Mcu_kConfigPtr = NULL_PTR;
#endif /* (MCU_PB_FIXEDADDR == STD_OFF)*/

/* No static qualifier - 
 * To avoid different AUTOSAR versions and also for debug support
 * DS_AS40X_MCU200
 */
uint32 Mcu_ResetStatusVal = MCU_RAW_RESET_UNDEFINED;

#define MCU_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#define MCU_START_SEC_VAR_8BIT
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#include "MemMap.h"

/* No static qualifier - 
 * To avoid different AUTOSAR versions and also for debug support
 * [cover parentID=DS_AS40X_MCU200] [/cover] 
 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
uint8 Mcu_DriverState;
#endif /* End MCU_DEV_ERROR_DETECT == STD_ON */

/* To store the Mcu clock setting used in Mcu_InitClock */
uint8 Mcu_ClockSetting;

  /*
  used for global or static variables (8 bits) that are initialized
  after every reset
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#define MCU_STOP_SEC_VAR_8BIT
#include "MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*Memory Map of the MCU Code*/
#define MCU_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Traceability    : [cover parentID=DS_AS_MCU101, DS_AS_MCU018,
   DS_AS_MCU026, DS_AS_MCU116, DS_AS_MCU245, DS_AS_MCU153, DS_MCAL_SWSC_MCU0403,
   DS_MCAL_SWSC_MCU0404]                                                      **
**                                                                            **
** Syntax          : void Mcu_Init(const Mcu_ConfigType* ConfigPtr)           **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :    0                                                     **
**                                                                            **
** Sync/Async      :    Synchronous                                           **
**                                                                            **
** Reentrancy      :    Non Reentrant                                         **
**                                                                            **
** Parameters (in) :    ConfigPtr - Pointer to MCU Driver configuration set   **
**                                                                            **
** Parameters (out):    None                                                  **
**                                                                            **
** Return value    :    None                                                  **
**                                                                            **
** Description     : This routine initializes the MCU driver. The intention of**
**                 this function is to make the configuration settings for    **
**                 power down, clock and RAM sections visible within the MCU  **
**                 driver.
**                 MCU026, MCU116,MCU126: Initialization of Mcu driver        **
**                                                                            **
*******************************************************************************/
void Mcu_Init( const Mcu_ConfigType *ConfigPtr )
{
  uint32 ResetConfig;
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;
  
  /*Initialize Error Flag with No Error*/
  ErrorFlag = MCU_ERR_NOT_FOUND;

  #if (MCU_PB_FIXEDADDR == STD_OFF)
  /* MCU126 Parameter check for Init */
  /*For PB Fixed Address STD_OFF : Check if passed parameter is NULL*/
  /* MCU012, MCU016, MCU013
   MCU018 - ConfigPtr shall not be NULL pointer.  */
  if (ConfigPtr == NULL_PTR)
  #else
  /*For PB Fixed Address STD_ON :ConfigPtr and Mcu_kConfigPtr should match*/
  if (Mcu_kConfigPtr != ConfigPtr)
  #endif  /*End Of MCU_PB_FIXEDADDR*/
  {
    #if (MCU_DEV_ERROR_DETECT == STD_ON)  
    Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_INIT,MCU_E_PARAM_CONFIG);
    #endif
    
    #if (MCU_SAFETY_ENABLE == STD_ON)
    /* Report an error */
    SafeMcal_ReportError ((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_INIT,MCU_E_PARAM_CONFIG);
    #endif
    /*Error flag is set*/
    ErrorFlag = MCU_ERR_FOUND;
  }
  
  #elif ( MCU_DEV_ERROR_DETECT == STD_OFF )
  /* To remove compiler warning of unused variable ConfigPtr*/
  UNUSED_PARAMETER(ConfigPtr)
  #endif  /*End Of MCU_DEV_ERROR_DETECT == STD_OFF */
  
  #if (MCU_SAFETY_ENABLE == STD_ON)
  if ((ErrorFlag != MCU_ERR_FOUND) &&
      (ConfigPtr->Marker != ((uint32)MCU_MODULE_ID << 16U)))
  {
    /* report to upper layer */
    ErrorFlag = MCU_ERR_FOUND;
    SafeMcal_ReportError ((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_INIT,MCU_E_PARAM_CONFIG);
    
  }
  #endif /*End Of MCU_SAFETY_ENABLE*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )
  /*If no error present*/
  if(ErrorFlag != MCU_ERR_FOUND)
  #endif
  {
     /*MCU120, MCU123, MCU124 Configuration  for PostBuild */
     /* Store the passed Mcu configuration parameter  ( Mcu_ConfigType* )*/

     #if (MCU_PB_FIXEDADDR == STD_OFF)
     /*MCU_PB_FIXEDADDR is STD_OFF : Assign ConfigPtr to the global variable*/
     Mcu_kConfigPtr = ConfigPtr;
     #endif /*End of MCU_PB_FIXEDADDR is STD_OFF*/

     /*Clear the SafetyENDINIT bit in the WDT_CON0 register in order
     to disable the write-protection for registers protected
     via the EndInit feature */
     Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);

     /*Capture the RSTSTAT register value in a variable*/

     Mcu_ResetStatusVal = (uint32)SCU_RSTSTAT.U;
     /*Clear the COLD reset status bits in the  RSTSTAT*/
     SCU_RSTCON2.B.CLRC = 1U;

     /*Assign the master core to control system mode or cpu idle mode changes*/
     SCU_PMSWCR1.U = (((uint32)MCU_SYSTEM_MODE_CORE << 24U) | /* CPUSEL bit */
                      ((uint32)MCU_IDLE_MODE_CORE << 8U)); /* CPUIDLSEL bit */

     #if (MCU_DISABLE_IRADIS == STD_ON)
     SCU_PMSWCR1.B.IRADIS = 1U;
     #else
     SCU_PMSWCR1.B.IRADIS = 0U;
     #endif

     /* Configure reset related registers */
     /* Configure RSTCON ; lower 16-bits */
     ResetConfig =(Mcu_kConfigPtr->ResetCfg | MCU_SW_RESET_CONFIG) &0x0000FFFFU;

     SCU_RSTCON.U = (uint32_t)ResetConfig;
     
     /* Configure ARSTDIS ; upper 16-bits */
     ResetConfig = Mcu_kConfigPtr->ResetCfg >> 16U;
     SCU_ARSTDIS.U = (uint32_t)ResetConfig;
     
     /* End of setting reset related configuration */

     /* Configure Standby registers if enabled*/ 
     if (Mcu_kConfigPtr->StandbyCfgPtr != NULL_PTR)
     {
      /* Update PMSWCR0 register */
      MODULE_SCU.PMSWCR0.U = Mcu_kConfigPtr->StandbyCfgPtr->PMSWCR0;
     }
     
     /* Set the SafetyENDINIT bit in the WDT_CON0 register again
     to enable the write-protection and to prevent a time-out */
     Mcal_SetSafetyENDINIT_Timed();

     /*Call Gtm_Init()*/
     #if (MCU_GTM_USED == STD_ON)
     Gtm_Init(ConfigPtr->GtmConfigRootPtr);
     #endif /*End of MCU_GTM_USED STD_ON */

     #if (MCU_CRC_HW_USED == STD_ON)
     Mcu_lCrcInit();
     #endif
     
     #if (MCU_DMA_USED == STD_ON)
     Mcu_lDmaInit();
     #endif
     
     #if (MCU_DEV_ERROR_DETECT == STD_ON)
     /*To confirm initialization*/
     Mcu_DriverState = MCU_DRIVER_INITIALIZED;
     #endif
  }
  return;

}/* End of Mcu_Init() */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101,
  DS_AS_MCU125, DS_AS_MCU011, DS_AS_MCU021, DS_AS_MCU154]                     **
**                                                                            **
** Syntax : Std_ReturnType Mcu_InitRamSection                                 **
**           (                                                                **
**             Mcu_RamSectionType    RamSection                               **
**           )                                                                **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    1                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non Reentrant                                               **
**                                                                            **
** Parameters (in):    RamSection: Selects RAM memory section provided in     **
**                     configuration set                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:    E_OK: command has been accepted                           **
**                  E_NOT_OK: command has not been accepted                   **
**                   e.g. due to parameter error                              **
**                                                                            **
** Description : This function initializes the RAM section wise. The          **
**                 definition of the section and the initialization value is  **
**                 provided from the configuration structure                  **
**               MCU011: RAM is initialized section wise                      **
**                                                                            **
*******************************************************************************/
Std_ReturnType    Mcu_InitRamSection (Mcu_RamSectionType    RamSection )
{
  #if (MCU_RAM_SECTORS != 0U)
  /* Local variables used in this block */
  uint8                 *RamBasePtr;
  uint8                  RamData;
  Mcu_RamSizeType        RamLength;
  #endif /*(MCU_RAM_SECTORS != 0U)*/

  Std_ReturnType RetValue ;
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;
  #endif

  #if ( MCU_DEV_ERROR_DETECT == STD_OFF ) && ( MCU_SAFETY_ENABLE == STD_ON )   
  ErrorFlag = MCU_ERR_NOT_FOUND;
  #endif
  
  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) 
  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_INITRAMSECTION);
  
  /*If Error Flag is not set*/
  if (MCU_ERR_FOUND != ErrorFlag)
  #endif
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )    
  {
    /*MCU021 : Check whether RamSection shall be within the sections
    defined in Configuration structure*/
    if ( RamSection >= (Mcu_kConfigPtr->NoOfRamCfg))
    {
      #if (MCU_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                      MCU_SID_INITRAMSECTION,MCU_E_PARAM_RAMSECTION);
      #endif 
      #if ( MCU_SAFETY_ENABLE == STD_ON )
      /* Report an error */
      SafeMcal_ReportError ((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_INITRAMSECTION,MCU_E_PARAM_RAMSECTION);
      
      #endif
      ErrorFlag = MCU_ERR_FOUND;
    } /* end of if ( RamSection >= (Mcu_kConfigPtr->NoOfRamCfg)) */
  } /* end of if(MCU_ERR_FOUND != ErrorFlag) */
  
  if(ErrorFlag == MCU_ERR_FOUND)
  {
     /*Return E_NOT_OK if Error is present*/
     RetValue = E_NOT_OK;
  }
  else
  #elif ( MCU_DEV_ERROR_DETECT == STD_OFF ) && (MCU_RAM_SECTORS == 0U)
  /* To remove compiler warning of unused variable RamSection*/
  UNUSED_PARAMETER(RamSection)
  #endif /*End for MCU_DEV_ERROR_DETECT == STD_OFF && MCU_RAM_SECTORS == 0U */
  {  /* Return E_OK if no Error*/

     RetValue = E_OK;
     /* End of MCU_DEV_ERROR_DETECT */

     #if (MCU_RAM_SECTORS != 0U)

    /* It may so happen that, in multiple config sets, some config sets will
    have no ram sectors defined.  In that case, if there is a access to those
    pointers, we get a memory exception.  To avoid that, ensure we are not
    dealing with NULL_PTR */
    if(Mcu_kConfigPtr->RamCfgPtr != NULL_PTR)
    {
      /* Ram Section Base Address is copied to the local variable*/
       RamBasePtr =
            (uint8*)(Mcu_kConfigPtr->RamCfgPtr[RamSection].RamBaseAdrPtr);

      /* Ram Section data pointer is copied to the local variable*/
      RamData =
            (uint8)(Mcu_kConfigPtr->RamCfgPtr[RamSection].RamPrstData);
      /* RAM length of 8 bit words is copied to local variable */
      RamLength =
           (Mcu_kConfigPtr->RamCfgPtr[RamSection].RamSize);

      /* Initialize all the 8 bit locations with user configured value */
      while (RamLength > (Mcu_RamSizeType)0)
      {
        *RamBasePtr = RamData;
        RamBasePtr++;
        RamLength--;
      }
    }
    #endif
  }
  /* Normal operation */
  return (RetValue);

}/*End Of Mcu_InitRamSection()*/

#if (MCU_INIT_CLOCK == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU017,
   DS_AS_MCU125, DS_AS_MCU137, DS_AS_MCU138, DS_AS40X_MCU210,
   DS_AS40X_MCU248, DS_AS_MCU155, DS_AS_MCU019, DS_MCAL_SWSC_MCU0405]         **
**                                                                            **
** Syntax : Std_ReturnType Mcu_InitClock                                      **
**           (                                                                **
**              Mcu_ClockType    ClockSetting                                 **
**           )                                                                **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    2                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non Reentrant                                               **
**                                                                            **
** Parameters (in):    ClockSetting:   Clock setting                          **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:    E_OK: command has been accepted                           **
**                  E_NOT_OK: command has not been accepted                   **
**                   e.g. due to parameter error                              **
**                                                                            **
** Description : This function initializes the PLL and other MCU specific     **
**                 clock options. The clock configuration parameters are      **
**                 provided via the configuration structure. In this function **
**                 the PLL lock procedure is started (if PLL shall be         **
**                 initialized) but the function does not wait until the PLL  **
**                 is locked                                                  **
**               Note: Mcu_InitClock only initializes the PLL parameters.     **
**                 PLL clock will be activated to the MCU distribution only   **
**                 after the PLL is locked and then Mcu_DistributePllClock is **
**                 called. i.e The sequence to activate PLL clock to the MCU  **
**                 clock distribution is                                      **
**                  1)Call Mcu_InitClock                                      **
**                  2)Call Mcu_GetPllStatus                                   **
**                  3)Mcu_DistributePllClock                                  **
**               MCU009: PLL and other MCU specific clock initialization      **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting )
{
  /* Local variables used in this API */
  volatile uint32 TimeoutCtr;
  uint32 OscconStatus;
  uint32 AG3CF0_Status;
  uint32 AG3CF1_Status;
  uint32 AG3CF2_Status;
  uint32 SmuStatus_Temp;
  Std_ReturnType RetValue;
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )  
  uint32 ErrorFlag;
  #endif

  #if ( MCU_DEV_ERROR_DETECT == STD_OFF ) && ( MCU_SAFETY_ENABLE == STD_ON )   
  ErrorFlag = MCU_ERR_NOT_FOUND;
  #endif
  
  /* Parameter check for the API if DET is STD_ON*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) 
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_INITCLOCK);

  /*If no Error is present*/
  if (MCU_ERR_FOUND != ErrorFlag)
  #endif
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )    
  {
    /* MCU019 :Check if the ID passed is valid */
    if ( ClockSetting >= Mcu_kConfigPtr->NoOfClockCfg )
    {
      #if (MCU_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_INITCLOCK,MCU_E_PARAM_CLOCK);
      #endif
      #if (MCU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_INITCLOCK,MCU_E_PARAM_CLOCK);
      
      #endif
      ErrorFlag = MCU_ERR_FOUND;
    } /* end of check for clock setting ID */

  } /* end of if (MCU_ERR_FOUND != ErrorFlag) */

  if (MCU_ERR_FOUND == ErrorFlag)
  {
     /*Return E_NOT_OK if error is present*/
     RetValue = E_NOT_OK;
  }
  else
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) || (MCU_SAFETY_ENABLE == STD_ON)*/
  {
    /*Store the current status of PLL, OSC and Clock Monitoring Alarms*/
    AG3CF0_Status = (((uint32)SMU_AGCF3_0.U) & 
                        (MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK));
    AG3CF1_Status = (((uint32)SMU_AGCF3_1.U) & 
                        (MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK));
    AG3CF2_Status = (((uint32)SMU_AGCF3_2.U) & 
                        (MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK));
    Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
    /* Enable access to SMU registers */
    SMU_KEYS.U =(uint32_t)0x000000bc;
    /*Clear all SMU alarms for PLL and OSC*/
    SmuStatus_Temp = (((uint32)SMU_AGCF3_0.U) & 
                          (~(MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK)));
    SMU_AGCF3_0.U = (uint32_t)SmuStatus_Temp;
    SmuStatus_Temp = (((uint32)SMU_AGCF3_1.U) & 
                          (~(MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK)));
    SMU_AGCF3_1.U = (uint32_t)SmuStatus_Temp;
    SmuStatus_Temp =  (((uint32)SMU_AGCF3_2.U) & 
                          (~(MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK)));
    SMU_AGCF3_2.U = (uint32_t)SmuStatus_Temp;
    /* Clear the keys to avoid any further update to SMU registers */
    SMU_KEYS.U =(uint32_t)0U;
    
    /*Select Fback as the source for all clocks during PLL initialization*/
    SCU_CCUCON0.B.CLKSEL = 0U;
    /*Stop ADC clock till PLL is intialized*/
    SCU_CCUCON0.U &= (uint32_t)~MCU_CCUCON0_ADCCLKSEL_STOP;
    /* Fosc0(Ext Osc) is used as clock source and a new complete parameter 
    set is transferred to the CCU.*/
    SCU_CCUCON1.B.INSEL = 1U;
    /* Update for CCUCON0 and CCUCON1*/
    SCU_CCUCON1.B.UP = 1U;

    /* OSCVAL  defines the divider value that generates  the reference clock
     that is supervised by the oscillator watchdog.
    fOSC / (OSCVAL + 1) ~ 2.5Mhz*/
    SCU_OSCCON.B.OSCVAL = MCU_OSCVAL_REG_VALUE;

    /* The Oscillator Watchdog of the PLL is cleared and restarted */
    SCU_OSCCON.B.OSCRES = 1U;

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
    
    /* Set the SafetyENDINIT bit in the WDT_CON0 register again
    to enable the write-protection and to prevent a time-out */
    Mcal_SetSafetyENDINIT_Timed();

    /* Timeout counter to come out of while loop in case the
      OSC frequency is not usable */
    TimeoutCtr = MCU_VALIDATE_OSC_FREQ_DELAY;

      /* wait until PLLLV and PLLHV flags are set */
    OscconStatus = (uint32)SCU_OSCCON.U;
    while((TimeoutCtr > 0UL) && ((((OscconStatus) &
         (uint32_t)MCU_PLLLV_PLLHV_STATUS_CHECK) !=
         ((uint32_t)MCU_PLLLV_PLLHV_STATUS_CHECK))))
    {
      OscconStatus = (uint32)SCU_OSCCON.U;
      --TimeoutCtr;
    }

    if(0U==TimeoutCtr)
    {
      #if(MCU_E_OSC_FAILURE_DEM_REPORT == MCU_ENABLE_DEM_REPORT)
      /*Report DEM for oscillator error*/
      Dem_ReportErrorStatus(MCU_E_OSC_FAILURE, DEM_EVENT_STATUS_FAILED);
      #endif /*End for(MCU_E_OSC_FAILURE_DEM_REPORT == MCU_ENABLE_DEM_REPORT)*/
      RetValue = E_NOT_OK;
    }
    else
    {
       /* Save the clock setting to be referred in Mcu Local functions 
        * Mcu_lPlatformInit, Mcu_lInitClockMonitoring and also for 
        * Mcu_DistributePllClock while configuring K2steps
        */
       Mcu_ClockSetting = (uint8)ClockSetting;      
       
      /* PLL bypass mode : PLL is configured in Prescaler Mode*/
      if (Mcu_kConfigPtr->ClockCfgPtr[ClockSetting].Mcu_ClockDivValues.PllMode
                                                         == 0U)
      {
         /* Prescaler Mode for PLL */
         /* Clear the SafetyENDINIT bit in the WDT_CON0 register in order
         to disable the write-protection for registers protected
         via the EndInit feature */
         Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);

         /* checking PLLBYPST flag*/
         if(SCU_PLLSTAT.B.VCOBYST==MCU_PLLSTAT_NORMAL_MODE)
         {
           /* Set K1DIV field to 0 */
           SCU_PLLCON1.B.K1DIV = 0U;

           SCU_PLLCON0.B.OSCDISCDIS = 0U;

           /*Enter Prescalar mode*/
           /* PLL is configured into Prescaler Mode; VCO is bypassed*/
           SCU_PLLCON0.B.VCOBYP = 1U;

           SCU_PLLCON0.B.SETFINDIS = 1U;
         }

         SCU_PLLCON1.B.K1DIV =\
         Mcu_kConfigPtr->ClockCfgPtr[ClockSetting].Mcu_ClockDivValues.K1div;

         /* In case of a PLL loss-of-lock bit PLLSTAT.FINDIS is not set*/
         SCU_PLLCON0.B.OSCDISCDIS = 1U;

         /*Set PLL to power saving mode - errata*/
         SCU_PLLCON0.B.PLLPWD = 0U;

         /* The input clock from the oscillator is connected to the VCO part */
         SCU_PLLCON0.B.CLRFINDIS = 1U;
         /*Set PLL to Normal mode*/
         SCU_PLLCON0.U = (uint32_t)((uint32)SCU_PLLCON0.U&\
                      MCU_VCOPWD_IS_SET_TO_NORMAL)|MCU_PLLPWD_IS_SET_TO_NORMAL;

         /*Delay for PLL to be stable*/
         for(TimeoutCtr=0U; TimeoutCtr < MCU_PLL_STABLE_DELAY;\
             TimeoutCtr++)
         {}

         Mcal_SetSafetyENDINIT_Timed();
         
         /* Call platform specific initialization */
         RetValue = Mcu_lPlatformInit();

         Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
         
         /* Enable Clock monitoring unit */
         #if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)       
         Mcu_lInitClockMonitoring();
         #endif
         
         /* Set the SafetyENDINIT bit in the WDT_CON0 register again
         to enable the write-protection and to prevent a time-out */
         Mcal_SetSafetyENDINIT_Timed();
      } /*Prescaler Mode*/
      else
      {
         /* Clear the ENDINIT bit in the WDT_CON0 register in order
         to disable the write-protection for registers protected
         via the EndInit feature */
         Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);

         /*Enter Prescalar mode*/
         /* Set VCOBYP = 1* and configure K1DIV with 1*/
         SCU_PLLCON1.B.K1DIV = 0U;

         /* In case of a PLL loss-of-lock bit PLLSTAT.FINDIS is set*/
         SCU_PLLCON0.B.OSCDISCDIS = 0U;
         /* PLL is configured into Prescaler Mode; VCO is bypassed*/
         SCU_PLLCON0.B.VCOBYP = 1U;
         /* Bit PLLSTAT.FINDIS is set. The input clock from the oscillator is
            disconnected from the VCO part.*/
         SCU_PLLCON0.B.SETFINDIS = 1U;

         SCU_PLLCON0.B.PDIV =\
         Mcu_kConfigPtr->ClockCfgPtr[ClockSetting].Mcu_ClockDivValues.Pdiv;
         SCU_PLLCON0.B.NDIV =\
         Mcu_kConfigPtr->ClockCfgPtr[ClockSetting].Mcu_ClockDivValues.Ndiv;
         SCU_PLLCON1.B.K3DIV =\
         Mcu_kConfigPtr->ClockCfgPtr[ClockSetting].Mcu_ClockDivValues.K3div;
         SCU_PLLCON1.B.K2DIV =\
                             Mcu_kConfigPtr->ClockCfgPtr[ClockSetting].K2div[0];

         /* In case of a PLL loss-of-lock bit PLLSTAT.FINDIS is not set*/
         SCU_PLLCON0.B.OSCDISCDIS = 1U;

         /*Set PLL to power saving mode - errata*/
         SCU_PLLCON0.B.PLLPWD = 0U;

         /* The input clock from the oscillator is connected to the VCO part */
         SCU_PLLCON0.B.CLRFINDIS = 1U;

         /*Set PLL to Normal mode - Exit Power Saving Mode*/
         SCU_PLLCON0.U = (uint32_t)((uint32)SCU_PLLCON0.U &\
                      MCU_VCOPWD_IS_SET_TO_NORMAL)|MCU_PLLPWD_IS_SET_TO_NORMAL;

         /*Delay for PLL to be stable - errata*/
         for(TimeoutCtr=0U; TimeoutCtr < MCU_PLL_STABLE_DELAY;
             TimeoutCtr++)
         {}

         /* restart the VCO lock detection */
         SCU_PLLCON0.B.RESLD = 1U;

         /* Set the ENDINIT bit in the WDT_CON0 register again
         to enable the write-protection and to prevent a time-out */
         Mcal_SetSafetyENDINIT_Timed();
         
         /* Initialize all clock dividers */
         /* Call platform specific initialization */
         RetValue = Mcu_lPlatformInit();
      }
    }

    /*Restore the SMU Status*/
    Mcal_ResetENDINIT();
    /*Clear any SMU TRAP request*/
    SCU_TRAPCLR.B.SMUT = 1U;
    Mcal_SetENDINIT();

    Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
    /* Enable access to SMU registers */
    SMU_KEYS.U = (uint32_t)0x000000bc;
    SMU_CMD.U = (uint32_t)0x00000005;
    /*Clear SMU alarms. To clear alarms SET the corresponding bit to 1.*/
    SMU_AG3.U = (uint32_t)(MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK);
    /*Restore SMU alarm configuration for PLL, OSC & Clock Monitoring Alarms*/
    SmuStatus_Temp = (((uint32)SMU_AGCF3_0.U) | AG3CF0_Status);
    SMU_AGCF3_0.U = (uint32_t)SmuStatus_Temp;
    SmuStatus_Temp = (((uint32)SMU_AGCF3_1.U) | AG3CF1_Status);
    SMU_AGCF3_1.U = (uint32_t)SmuStatus_Temp;
    SmuStatus_Temp = (((uint32)SMU_AGCF3_2.U) | AG3CF2_Status);
    SMU_AGCF3_2.U = (uint32_t)SmuStatus_Temp;
    /* Clear the keys to avoid any further update to SMU registers */
    SMU_KEYS.U =(uint32_t)0U;
    Mcal_SetSafetyENDINIT_Timed();
  }
  return (RetValue);
}/* End of Mcu_InitClock() */

#endif/* End of (MCU_INIT_CLOCK == STD_ON)*/

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU125,DS_AS_MCU122,
                   DS_AS_MCU140, DS_AS40X_MCU205, DS_AS_MCU156, 
                   DS_MCAL_SWSC_MCU0406]                                      **
**                                                                            **
** Syntax : void Mcu_DistributePllClock( void )                               **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    3                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non Reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description : This function activates the PLL clock to the MCU clock       **
**                 distribution. This function shall be executed, if the MCU  **
**                 needs a separate request to activate the PLL clock after   **
**                 the PLL is locked. In this case the current clock source   **
**                 (for example internal oscillator clock) is removed         **
**                 from MCU clock distribution.                               **
**               Note: Mcu_InitClock only initializes the PLL parameters.     **
**                 PLL clock will be activated to the MCU distribution only   **
**                 after the PLL is locked and then Mcu_DistributePllClock is **
**                 called. i.e The sequence to activate PLL clock to the MCU  **
**                 clock distribution is                                      **
**                  1)Call Mcu_InitClock                                      **
**                  2)Call Mcu_GetPllStatus                                   **
**                  3)Mcu_DistributePllClock                                  **
**               MCU028,MCU056: Activates PLL for clock distribution  .       **
**                                                                            **
*******************************************************************************/
void Mcu_DistributePllClock ( void )
{
  uint32 Index;
  uint32 K2Divsteps;
  volatile uint32 Delay;
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || (MCU_SAFETY_ENABLE == STD_ON)  
  uint32 ErrorFlag;
  #endif

  #if ( MCU_DEV_ERROR_DETECT == STD_OFF ) && ( MCU_SAFETY_ENABLE == STD_ON )   
  ErrorFlag = MCU_ERR_NOT_FOUND;
  #endif
  
  /*  Parameter check for the API if DET is STD_ON*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON )

  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_DISTRIBUTEPLLCLOCK);
  if (MCU_ERR_FOUND != ErrorFlag)
  #endif    
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || (MCU_SAFETY_ENABLE == STD_ON)    
  {
    /* MCU122 :Check if PLL is locked */
    if ( (Mcu_PllStatusType)SCU_PLLSTAT.B.VCOLOCK != MCU_PLL_LOCKED )
    {
      #if ( MCU_DEV_ERROR_DETECT == STD_ON )
      Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_DISTRIBUTEPLLCLOCK,MCU_E_PLL_NOT_LOCKED);
      #endif
      #if (MCU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_DISTRIBUTEPLLCLOCK,MCU_E_PLL_NOT_LOCKED);
      
      #endif
      ErrorFlag = MCU_ERR_FOUND;
    }
  }
  /*Execute only if Error is not set */
  if (MCU_ERR_FOUND != ErrorFlag)  
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) || (MCU_SAFETY_ENABLE == STD_ON)*/
  { 
    uint32 AG3CF0_Status;
    uint32 AG3CF1_Status;
    uint32 AG3CF2_Status;
    uint32 SmuStatus_Temp;
  
    /*Get the K2 Intermediate step values */
    K2Divsteps = ((uint32)(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                                  Mcu_ClockDivValues.K2steps) + 1U);
    Index = 1U;
    /* Clear the ENDINIT bit in the WDT_CON0 register in order
    to disable the write-protection for registers protected
    via the EndInit feature */


    Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);

    /* Normal operation, VCO is not bypassed */
    SCU_PLLCON0.B.VCOBYP = 0U;

     /*Give a delay for normal mode selection*/
    for (Delay = 0U; Delay < MCU_DELAY_NORMAL_MODE_SELECTION; Delay++)
    {
    }

    /*Run a loop for desired number of K2 intermediate step values*/
    do
    {
      /*Configure the next K2 step value*/
      SCU_PLLCON1.B.K2DIV =\
         Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].K2div[Index];

       /*Give a delay of minimum 6 CPU clock cycles*/
      for (Delay = 0UL; Delay < MCU_DELAY; Delay++)
      {
      }
      Index++;
    } while (Index <= K2Divsteps);

    /* In case of a PLL loss-of-lock bit PLLSTAT.FINDIS is cleared */
    SCU_PLLCON0.B.OSCDISCDIS = 0U;
  
    /*Store the current status of PLL and OSC Alrams*/
    AG3CF0_Status = (((uint32)SMU_AGCF3_0.U) & MCU_PLL_CLKM_SMU_MASK);
    AG3CF1_Status = (((uint32)SMU_AGCF3_1.U) & MCU_PLL_CLKM_SMU_MASK);
    AG3CF2_Status = (((uint32)SMU_AGCF3_2.U) & MCU_PLL_CLKM_SMU_MASK);
    /* Enable access to SMU registers */
    SMU_KEYS.U =(uint32_t)0x000000bc;
    /*Clear all SMU alarms for PLL and OSC*/
    SmuStatus_Temp = (((uint32)SMU_AGCF3_0.U) & (~MCU_PLL_CLKM_SMU_MASK));
    SMU_AGCF3_0.U = (uint32_t)SmuStatus_Temp;
    SmuStatus_Temp = (((uint32)SMU_AGCF3_1.U) & (~MCU_PLL_CLKM_SMU_MASK));
    SMU_AGCF3_1.U = (uint32_t)SmuStatus_Temp;
    SmuStatus_Temp =  (((uint32)SMU_AGCF3_2.U) & (~MCU_PLL_CLKM_SMU_MASK));
    SMU_AGCF3_2.U = (uint32_t)SmuStatus_Temp;
    /* Clear the keys to avoid any further update to SMU registers */
    SMU_KEYS.U =(uint32_t)0U;   
    
    /* Enable Clock monitoring unit */
    #if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)
    Mcu_lInitClockMonitoring();
    #endif

    /* Enable access to SMU registers */
    SMU_KEYS.U = (uint32_t)0x000000bc;
    SMU_CMD.U = (uint32_t)0x00000005;
    /*Clear SMU alarms. To clear alarms SET the corresponding bit to 1.*/
    SMU_AG3.U = (uint32_t)MCU_PLL_CLKM_SMU_MASK;
    /*Restore SMU alarm configuration for PLL & OSC*/
    SmuStatus_Temp = (((uint32)SMU_AGCF3_0.U) | AG3CF0_Status);
    SMU_AGCF3_0.U = (uint32_t)SmuStatus_Temp;
    SmuStatus_Temp = (((uint32)SMU_AGCF3_1.U) | AG3CF1_Status);
    SMU_AGCF3_1.U = (uint32_t)SmuStatus_Temp;
    SmuStatus_Temp = (((uint32)SMU_AGCF3_2.U) | AG3CF2_Status);
    SMU_AGCF3_2.U = (uint32_t)SmuStatus_Temp;
    /* Clear the keys to avoid any further update to SMU registers */
    SMU_KEYS.U =(uint32_t)0U;  
  
    /* Set the SafetyENDINIT bit in the WDT_CON0 register again
    to enable the wr   ite-protection and to prevent a time-out */
    Mcal_SetSafetyENDINIT_Timed();
  }
  return;
}/* End of Mcu_DistributePllClock() */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU125,DS_AS40X_MCU230
                   DS_AS_MCU008, DS_AS_MCU132, DS_AS_MCU157]                  **
**                                                                            **
** Syntax : Mcu_PllStatusType Mcu_GetPllStatus( void )                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    4                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Reentrant                                                   **
**                                                                            **
** Parameters (in):    None                                                   **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:   Mcu_PllStatusType                                          **
**                 Returns whether PLL is Locked,Unlocked or Undefined status **
**                                                                            **
** Description : This function provides the lock status of the PLL            **
**               MCU008: Lock status of the PLL is provided                   **
**                                                                            **
*******************************************************************************/
Mcu_PllStatusType    Mcu_GetPllStatus ( void )
{

  Mcu_PllStatusType RetValue;
  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  uint32 ErrorFlag;
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_GETPLLSTATUS);
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  if (MCU_ERR_FOUND == ErrorFlag)
  {
     /*Return Undefined in case of Error */
     RetValue = MCU_PLL_STATUS_UNDEFINED;
  }
  else
  #endif
  {
     /*Return the pll lock staus*/
     RetValue =  ((Mcu_PllStatusType)SCU_PLLSTAT.B.VCOLOCK);
  }
  return(RetValue);
}/* End of Mcu_GetPllStatus() */
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU125,DS_AS_MCU158,
                    DS_AS_MCU052, DS_AS_MCU005, DS_AS_MCU133]                 **
**                                                                            **
** Syntax : Mcu_ResetType Mcu_GetResetReason( void )                          **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    5                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Reentrant                                                   **
**                                                                            **
** Parameters (in):    None                                                   **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:  Mcu_ResetType                                               **
**                Returns the reset reason                                    **
**                                                                            **
** Description : The function reads the reset type from the hardware, if      **
**                 supported. If the hardware doesn't support the hardware    **
**                 detection of the reset reason, the return value for those  **
**                 resets is always MCU_POWER_ON_RESET.                       **
**               MCU005, MCU052, MCU012  : Function to read the reset type    **
**                from the hardware                                           **
**                                                                            **
*******************************************************************************/
Mcu_ResetType    Mcu_GetResetReason (void )
{
  /* Placeholder for Raw reset value */
  Mcu_RawResetType ResetReasonRaw;
  /* Placeholder for mapped reset value */
  Mcu_ResetType ResetValueToUser;

  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  uint32 ErrorFlag;
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_GETRESETREASON);
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  if ( MCU_ERR_FOUND == ErrorFlag)
  {
    /*Return Undefined in case of Error */
    ResetValueToUser = MCU_RESET_UNDEFINED;
  }
  else
  #endif /* End of MCU_DEV_ERROR_DETECT*/
  {
    /* Extract raw reset reason from the status register */
    ResetReasonRaw = ((Mcu_RawResetType)(Mcu_ResetStatusVal &
                      MCU_RESET_REASON_MASK));

    ResetValueToUser = Mcu_lGetPlatformRstReason(ResetReasonRaw);

  }/* Return the computed value which is user friendly */
  return(ResetValueToUser);
} /*End of Mcu_GetResetReason*/

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU125,DS_AS_MCU006,
                 DS_AS_MCU135, DS_AS_MCU159, DS_MCAL_SWSC_MCU0407]            **
** Syntax : Mcu_ResetType Mcu_GetResetRawValue( void )                        **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    6                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Reentrant                                                   **
**                                                                            **
** Parameters (in):    None                                                   **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:      Mcu_RawResetType                                        **
**                    Returns the reset reason                                **
**                                                                            **
** Description : The function reads the reset type from the hardware, if      **
**                 supported. If the hardware doesn't have reset status       **
**                 register return value shall be 0x0.                        **
**               MCU006:  Reset reason in a Raw register format               **
**                                                                            **
*******************************************************************************/
Mcu_RawResetType    Mcu_GetResetRawValue (void )
{
  Mcu_RawResetType RetValue ;
  /* Det specific local variables go here */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  uint32 ErrorFlag;

  /* End of Det specific local variables */

  /* Other function specific local variables go here */
  /* End of Other function specific local variables */

  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  ErrorFlag  = Mcu_lInitCallVerify(MCU_SID_GETRESETRAWVALUE);
  if(MCU_ERR_FOUND == ErrorFlag)
  {
    /*Return Undefined in case of Error */
    RetValue = MCU_RAW_RESET_UNDEFINED;
  }
  else
  #endif
  {
     RetValue =(Mcu_RawResetType)Mcu_ResetStatusVal;
  }
  return (RetValue);

}/*End of Mcu_GetResetRawValue*/

/* MCU007  : This function is available if the runtime parameter
   MCU_PERFORM_RESET_API is set to TRUE. */
#if (MCU_PERFORM_RESET_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU125,DS_AS_MCU146,
          DS_AS_MCU125, DS_AS_MCU055, DS_AS_MCU143, DS_AS_MCU144,DS_AS_MCU160,
          DS_MCAL_SWSC_MCU0408, DS_MCAL_SWSC_MCU0409, DS_MCAL_SWSC_MCU0410]   **
**                                                                            **
** Syntax :void Mcu_PerformReset( void )                                      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    7                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non reentrant                                               **
**                                                                            **
** Parameters (in):    None                                                   **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:       None                                                   **
**                                                                            **
** Description : The function performs a microcontroller reset. This is done  **
**                 by using the hardware feature of the microcontroller.      **
**                 The MCU specific reset type to be performed by this        **
**                 service shall be configured in the configuration set.      **
**              MCU007 , MCU055: The function performs a microcontroller      **
**             reset                                                          **
**                                                                            **
*******************************************************************************/
void Mcu_PerformReset( void )
{
  /* Local variables used in this API */
  volatile uint32 i;

  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON )
  uint32 ErrorFlag;
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_PERFORMRESET);

  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  if ( MCU_ERR_FOUND != ErrorFlag)
  #endif
  {
    /* End of MCU_DEV_ERROR_DETECT*/
    
    #if (MCU_SAFETY_ENABLE == STD_OFF)
    /*Clear the SafetyENDINIT bit in the WDT_CON0 register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
    #endif

    /* software Reset can be performed by writing to Reset Request register
    SWRSTCON */
    SCU_SWRSTCON.B.SWRSTREQ = MCU_BITVAL_1;
    /* Add some delay for HW to reset */
    for(i = 0U ; i< (uint32)MCU_PERFORM_RESET_DELAY; i++)
    {
    }
  }

  /* Mcal_SetENDINIT() is not required, as the MCU would RESET  */

}/* End of Mcu_PerformReset()*/
#endif
/* End of MCU_PERFORM_RESET_API*/

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU125,DS_AS40X_Mcu_SetMode_Note,
 DS_NAS_MCUPR2866_PR2867,DS_AS_MCU020, DS_AS_MCU147, DS_AS_MCU164, DS_AS_MCU161,
        DS_MCAL_SWSC_MCU0411, DS_MCAL_SWSC_MCU0412, DS_MCAL_SWSC_MCU0413]     **
**                                                                            **
** Syntax : void Mcu_SetMode                                                  **
**          (                                                                 **
**             Mcu_ModeType   McuMode                                         **
**          )                                                                 **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    8                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non reentrant                                               **
**                                                                            **
** Parameters (in):   McuMode : Set different MCU power modes configured in   **
**                    the configuration set                                   **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:      None                                                    **
**                                                                            **
** Description : This function activates the MCU power modes. In case the     **
**                CPU is switched off, the function is returned after a       **
**                wake-up was performed                                       **
**              MCU001: The MCU service to activate MCU reduced power modes   **
**                                                                            **
*******************************************************************************/
void Mcu_SetMode(Mcu_ModeType   McuMode)
{
  uint8 CoreId;

  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag ;
  #endif

  #if ( MCU_DEV_ERROR_DETECT == STD_OFF ) && ( MCU_SAFETY_ENABLE == STD_ON )   
  ErrorFlag = MCU_ERR_NOT_FOUND;
  #endif
  
  /* To remove the MISRA error this is used*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON )
  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_SETMODE);
  
  if (MCU_ERR_FOUND != ErrorFlag)
  #endif    
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )    
  {
    /* MCU020: Check if invalid ModeSetting Id is passed */
    if((McuMode >= MCU_MAX_NO_MODES) ||
      ((((uint32)1U << McuMode) & (Mcu_kConfigPtr->MaxMode)) == 0x00U) )
    {
      #if ( MCU_DEV_ERROR_DETECT == STD_ON )
      Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_SETMODE,MCU_E_PARAM_MODE);
      #endif
      #if ( MCU_SAFETY_ENABLE == STD_ON )
      /* report an error */
      SafeMcal_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_SETMODE,MCU_E_PARAM_MODE);      
      #endif
      ErrorFlag = MCU_ERR_FOUND ;
    } /* end of  if (McuMode >= MCU_NUMBER_OF_MODES) */
  } /* end of if(MCU_ERR_FOUND != ErrorFlag) */
  /* If DET is present return here */
  if (MCU_ERR_FOUND != ErrorFlag)  
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) || (MCU_SAFETY_ENABLE == STD_ON)*/
  {

    CoreId = Mcal_GetCoreId();
    
    if (MCU_IDLE == McuMode)
    {
      Mcu_lSetIdleMode(CoreId);
    }
    else if (MCU_SLEEP == McuMode)
    {
      Mcu_lSetSleepMode(CoreId);
    }
    else
    {
      Mcu_lSetStandbyMode(CoreId);
    }
  }
return;
}/*End of Mcu_SetMode()*/

#if (MCU_E_CLOCK_FAILURE_DEM_REPORT == MCU_ENABLE_DEM_REPORT)
/******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU049_MCU051, DS_AS_MCU166,
                  DS_AS_MCU226]                                              **
**                                                                           **
** Syntax :           void Mcu_ClockFailureNotification(void)                **
** [/cover]                                                                  **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   None                                                   **
**                                                                           **
** Parameters (out):  None                                                   **
**                                                                           **
** Return value:      void                                                   **
**                                                                           **
** Description :      Function reports clock fail error to DEM               **
**                                                                           **
*****************************************************************************/
void Mcu_ClockFailureNotification(void)
{
  /* Report the error to DEM only if
  McuClockSrcFailureNotification is enabled and DEM is configured */
  Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
}
#endif

#if (MCU_RAMP_TO_BACKUP_FREQ_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_MCUPR2873]                           **
**                                                                            **
** Syntax : void Mcu_RampToBackUpClockFreq( void )                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    NA                                                          **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non Reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:      E_OK: command has been accepted                         **
**                  E_NOT_OK: command has not been accepted                   **
**                                                                            **
** Description : This function ramps down from the current PLL frequency close**
**               to the back-up clock frequency. This shall be done in steps  **
**               but in reverse order from the steps done in                  **
**               Mcu_DistributePllClock. This function can be called only     **
**               after Mcu_InitClock and Mcu_DistributePllClock.              **
**               Note: This API will not ramp up if current PLL is already    **
**                     below the backup frequency                             **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_RampToBackUpClockFreq ( void )
{
  Std_ReturnType RetVal;

  RetVal = E_NOT_OK;
  
  #if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)
  Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
  /* Disable the clock monitoring unit */
  SCU_CCUCON3.U = 0U;
  SCU_CCUCON4.U = 0U;
  SCU_CCUCON9.U = 0U;   

  /* Single Update for all CCUCON3 & 4 registers*/
  SCU_CCUCON3.B.UP = 1U;

  /* Update for all CCUCON9 registers*/
  SCU_CCUCON9.B.UP = 1U;    
  Mcal_SetSafetyENDINIT_Timed();    
  #endif
    
  /* Check if Normal mode, VCO is not bypassed */
  if (SCU_PLLCON0.B.VCOBYP == 0U)
  {
    volatile uint32 Delay;
    uint32 PLLFreq;
    uint32 NDiv, PDiv, K2Div, K2Divsteps;
    
    /*Get the K2 Intermediate step values */
    K2Divsteps = (Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                                  Mcu_ClockDivValues.K2steps + (uint32)1U);
    NDiv = Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
            Mcu_ClockDivValues.Ndiv + (uint32)1U;
    PDiv = Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
            Mcu_ClockDivValues.Pdiv + (uint32)1U;

    /* Clear the ENDINIT bit in the WDT_CON0 register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
    
    /*
     * Run a loop for desired number of K2 intermediate step values till it
     * reaches close to the back up frequency
     */
    do
    {
      /*Configure the next K2 step value*/
      SCU_PLLCON1.B.K2DIV = Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting]\
                                                .K2div[K2Divsteps];
         
       /*Give a delay of minimum 6 CPU clock cycles*/
      for (Delay = 0UL; Delay < MCU_DELAY; Delay++)
      {
      }
      
      K2Div = Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].K2div[K2Divsteps] +
                  (uint32)1U;
      
      /* Calculate the PLL Frequency */ 
      PLLFreq = (MCU_MAIN_OSC_FREQ * NDiv)/( PDiv * K2Div);      
      
      K2Divsteps--;
    }while (PLLFreq > MCU_BACKUP_FREQ);

    /* Disable disconnecting the oscillator in case of PLL loss of lock */
    SCU_PLLCON0.B.OSCDISCDIS = 0U;
    
    /* Set the SafetyENDINIT bit in the WDT_CON0 register again
    to enable the wr   ite-protection and to prevent a time-out */
    Mcal_SetSafetyENDINIT_Timed();    
    
    RetVal = E_OK;
  }/* end of if (normal mode) */
  
  return RetVal;
}/* End of Mcu_RampToBackUpClockFreq() */
#endif /* End of MCU_RAMP_TO_BACKUP_FREQ_API */

#if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)

/*******************************************************************************
** Traceability : [cover parentID=]                                           **
**                                                                            **
** Syntax : void Mcu_lInitClockMonitoring (void)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    N/A                                                         **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non Reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:    None                                                      **
**                                                                            **
** Description : This function enables the Clock monitoring unit and monitors **
**                 the safety relevant clocks if they cross the frequency     **
**                 thresholds. If an failure is detected by the Clock         **
**                 monitoring unit, it will raise an SMU alarm. It is assumed **
**                 that the SMU alarms for clock monitoring are configured.   **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Mcu_lInitClockMonitoring(void)
{       
  SCU_CCUCON3.U = (uint32_t)
                  (Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon3 & 
                                          MCU_CCUCON3_MASK_CLOCK_DIVIDERS);
  SCU_CCUCON4.U = (uint32_t)
                  (Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon4 & 
                                          MCU_CCUCON4_MASK_CLOCK_DIVIDERS);
  SCU_CCUCON9.U = (uint32_t)
                  (Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon9 & 
                                          MCU_CCUCON9_MASK_CLOCK_DIVIDERS); 

  /* Single Update for all CCUCON3 & 4 registers*/
  SCU_CCUCON3.B.UP = 1U;
  
  /* Update for all CCUCON9 registers*/
  SCU_CCUCON9.B.UP = 1U;

}/* End of Mcu_lInitClockMonitoring() */

#endif /*End Of MCU_ENABLE_CLOCK_MONITORING*/

#define MCU_STOP_SEC_CODE
#include "MemMap.h"

#if (MCU_SAFETY_ENABLE == STD_ON)

#define MCU_START_SEC_SAFETY_CODE
#include "MemMap.h"

#if (MCU_INITCHECK_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SWSC_MCU0414, DS_MCAL_SWSC_MCU0415,
            DS_MCAL_SWSC_MCU0416, DS_MCAL_SWSC_MCU0417, DS_MCAL_SWSC_MCU0418] **
**                                                                            **
** Syntax          : void Mcu_InitCheck (const Mcu_ConfigType* ConfigPtr)     **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :    None                                                  **
**                                                                            **
** Sync/Async      :    Synchronous                                           **
**                                                                            **
** Reentrancy      :    Non Reentrant                                         **
**                                                                            **
** Parameters (in) :    ConfigPtr - Pointer to MCU Driver configuration set   **
**                                                                            **
** Parameters (out):    None                                                  **
**                                                                            **
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description     : This routine verifies the initialization the MCU driver. **
**                   Note: The sequence should be                             **
**                    1)Call Mcu_InitClock                                    **
**                    2)Call Mcu_GetPllStatus                                 **
**                    3)Call Mcu_DistributePllClock                           **
**                    4)Call Mcu_InitCheck                                    **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_InitCheck (const Mcu_ConfigType* ConfigPtr)
{ 
  Std_ReturnType ErrorFlag;
  Std_ReturnType TempErrFlag;  
  uint32         TempFlag;

  ErrorFlag = E_NOT_OK;
  
  if (Mcu_kConfigPtr == ConfigPtr)
  {
    volatile uint32 CompareFlag = 0xFFFFFFFFU;
    uint32 TempFlag1;

    /* To avoid multiple if conditions, storing in CompareFlag */
    /* Comparison to be done for initialization done by Mcu_Init() */ 
    TempFlag = (uint32)SCU_PMSWCR1.U & MCU_PMSWCR1_MASK;
    /* CPUSEL bit */
    TempFlag1 = ((uint32)MCU_SYSTEM_MODE_CORE << 24U);
    /* CPUIDLSEL bit */
    TempFlag1 |= ((uint32)MCU_IDLE_MODE_CORE << 8U);
    #if (MCU_DISABLE_IRADIS == STD_ON)
    /* IRADIS bit */
    TempFlag1 |= 1U << 12U;
    #endif      
    CompareFlag &= (TempFlag ^ ~TempFlag1);
     
    TempFlag = (uint32)SCU_RSTSTAT.U & (~MCU_RSTSTAT_CLRC_BITS);
    CompareFlag &= (TempFlag ^ ~(Mcu_ResetStatusVal & ~MCU_RSTSTAT_CLRC_BITS));

    TempFlag = ~(uint32)SCU_RSTCON.U;
    TempFlag1 = (Mcu_kConfigPtr->ResetCfg | MCU_SW_RESET_CONFIG) & 0x0000FFFFU;
    CompareFlag &= (TempFlag1 ^ TempFlag);

    TempFlag = ~(uint32)SCU_ARSTDIS.U;
    TempFlag1 = Mcu_kConfigPtr->ResetCfg >> 16U;
    CompareFlag &= (TempFlag1 ^ TempFlag);    
     
   /* Comparison to be done for initialization done by Mcu_InitClock() */ 
   TempFlag = (((uint32)MCU_OSCVAL_REG_VALUE << 16)) | 
              MCU_PLLLV_PLLHV_STATUS_CHECK;
   TempFlag1 = (uint32) SCU_OSCCON.U & MCU_OSCCON_MASK;
   CompareFlag &= (TempFlag1 ^ ~TempFlag);

   /* Verify Prescaler Mode*/
   if (Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Mcu_ClockDivValues.PllMode
                                                         == 0U)
   {
     TempFlag = MCU_PLLCON0_REGVAL_CHECK;
     TempFlag1 = SCU_PLLCON0.U & MCU_PLLCON0_PRESCALAR_MASK;
     CompareFlag &= (TempFlag1 ^ ~TempFlag);

     TempFlag = ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                        Mcu_ClockDivValues.K1div) << 16U;
     TempFlag1 = SCU_PLLCON1.U & MCU_PLLCON1_PRESCALAR_MASK;
     CompareFlag &= (TempFlag1 ^ ~TempFlag);      
   }
   else /* Verify Normal Mode*/
   {
     uint32 K2Divsteps = 
      ((uint32)(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                                  Mcu_ClockDivValues.K2steps) + 1U);
     TempFlag = ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                      Mcu_ClockDivValues.Pdiv << 24U) |
                ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                      Mcu_ClockDivValues.Ndiv << 9U) |
                  MCU_PLLPWD_IS_SET_TO_NORMAL; 
     TempFlag1 = SCU_PLLCON0.U & MCU_PLLCON0_NORMAL_MASK;
     CompareFlag &= (TempFlag1 ^ ~TempFlag);

     TempFlag =((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                Mcu_ClockDivValues.K3div << 8U) |
                Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].K2div[K2Divsteps];
     TempFlag1 = SCU_PLLCON1.U;     
     CompareFlag &= (TempFlag1 ^ ~TempFlag);         
   } /* end of Normal mode */
   
   #if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)
   /* Verify Clock monitoring registers */
   TempFlag = MCU_CCUCON3_MASK_CLOCK_DIVIDERS;
   TempFlag1 = SCU_CCUCON3.U;    
   CompareFlag &= (TempFlag1 & TempFlag) ^
       ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon3 & TempFlag); 

   TempFlag = MCU_CCUCON4_MASK_CLOCK_DIVIDERS;
   TempFlag1 = SCU_CCUCON4.U;       
   CompareFlag &= (TempFlag1 & TempFlag) ^
       ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon4 & TempFlag); 

   TempFlag = MCU_CCUCON9_MASK_CLOCK_DIVIDERS;
   TempFlag1 = SCU_CCUCON9.U;       
   CompareFlag &= (TempFlag1 & TempFlag) ^
       ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon9 & TempFlag); 
   #endif

   TempErrFlag = Mcu_lPlatformInitCheck();
   
   #if (MCU_GTM_USED == STD_ON)       
   TempErrFlag |= Gtm_InitCheck(ConfigPtr->GtmConfigRootPtr);
   #endif

   #if (MCU_CRC_HW_USED == STD_ON)       
   TempErrFlag |= Mcu_lCrcInitCheck();
   #endif

   #if (MCU_DMA_USED == STD_ON)       
   TempErrFlag |= Mcu_lDmaInitCheck();
   #endif
   
   /* Verify GTM initialization */
   if ( (CompareFlag == 0xFFFFFFFFU) && (TempErrFlag == E_OK) )
   {
     ErrorFlag = E_OK;
   }
  } /* end of if ConfigPtr!=NULL_PTR && Marker==MCU_MODULE_ID << 16U */

  return (ErrorFlag);
}/* End of Mcu_InitCheck() */
#endif /* end of MCU_INITCHECK_API == STD_ON */

#if (MCU_GETMODE_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SWSC_MCU0419, DS_MCAL_SWSC_MCU0420] **
**                                                                            **
** Syntax           : Mcu_ModeStateType  Mcu_GetMode                          **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in):   CoreId : The Core for which the mode needs to be        **
**                    dertermined                                             **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Mcu_ModeStateType  - Power mode status                  **
**                                                                            **
** Description      :                                                         **
**   - provides the mode the CPU is currently in                              **
**                                                                            **
*******************************************************************************/
Mcu_ModeStateType Mcu_GetMode(uint8 CoreId)
{
  Mcu_ModeStateType ModeState;
  
  if (CoreId >= MCAL_NO_OF_CORES)
  {
    /* Report an error */
    ModeState = MCU_UNDEFINED_MODE;
  }
  else
  {
    ModeState = (Mcu_ModeStateType)MODULE_SCU.PMCSR[CoreId].B.PMST;
  }
  return (ModeState); 
} /* End of Mcu_GetMode() */
#endif /* end of MCU_GETMODE_API == STD_ON */

#define MCU_STOP_SEC_SAFETY_CODE
#include "MemMap.h"

#endif /*End Of MCU_SAFETY_ENABLE*/



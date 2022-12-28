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
**  FILENAME  : Mcu_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\51 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-10-09, 14:34:16                                          **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : MCU configuration generated out of ECU configuration       **
**                 file  (Mcu.bmd)                                            **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Includes                                             **
*******************************************************************************/

/* Include module header file */
#include "Mcu.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/



/*
   Configuration Options:
   For the clock setting configuration
   PLL status
*/

/* Normal Mode */
#define MCU_NORMAL_MODE        (0x01U)

/******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/* Memory Mapping the configuration constant */
#define MCU_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/*
   Configuration : Mcu_ConfigType
   For Mcu_ConfigType: MCU specific configuration ID
   This id corresponds to the container name of the McuConfiguration.
   Use this as the parameter for API: Mcu_Init
    - MCU035 : Configuration of MCU
*/
/*
                     Container: McuClockSettingConfig
                     Multilplicity : 1 - *
*/


static const Mcu_ClockCfgType Mcu_kClockConfiguration0[] =
{
    /*McuClockSettingConfig_0*/
  {
    {
      /*K2 divider steps*/
      24U, /* 24.0 MHz*/
      10U, /* 55.0 MHz*/
      6U, /* 86.0 MHz*/
      4U, /* 120.0 MHz*/
      3U, /* 150.0 MHz*/
      2U  /* 200.0 MHz*/
    },
    {
      1U,                              /* K1DIV */
      5U,                              /* K3DIV */
      29U,                             /* NDIV */
      0U,                              /* PDIV */
      4U,                              /* K2DivSteps */
      MCU_NORMAL_MODE,                 /* NORMAL/PRESCALER MODE */
      0U                               /* reserved */
    },

    {
      19U,                             /* PLL ERAY N divider */
      4U,                              /* PLL ERAY K2 divider */
      4U,                              /* PLL ERAY K3 divider */
      0U,                              /* PLL ERAY P Divider */
      0U                               /* reserved */
    },
    /*
      SRI Clock     = 200.0MHz
      SPB Clock     = 100.0MHz
    */
    (uint32)0x061201a2U,/* CCUCON0 Register Configuration*/
    (uint32)0x02212212U,/* CCUCON1 Register Configuration*/
    (uint32)0x00000002U,/* CCUCON2 Register Configuration*/
    (uint32)0x00000001U,/* CCUCON5 Register Configuration*/
    (uint32)0x00000000U,/* CCUCON6 Register Configuration*/
    (uint32)0x00000000U,/* CCUCON7 Register Configuration*/
    (uint32)0x00000000U/* CCUCON8 Register Configuration*/
      }/*McuClockSettingConfig_0*/

};


/* Main MCU Configuration Structure */
const Mcu_ConfigType Mcu_ConfigRoot[1] =
{
  {
    /*McuModuleConfiguration_0*/
    
    /*Mcu Clock Configuration*/
    Mcu_kClockConfiguration0,
    #if (MCU_RAM_SECTORS != 0U)
    /*Mcu Ram Configuration is NULL_PTR as there is nothing configured here */
    NULL_PTR,
    #endif /* #if (MCU_RAM_SECTORS != 0U) */
    /*Ptr to Gtm_ConfigRoot*/
    &Gtm_ConfigRoot[0],
    /* Reset request configuration  */
    /* 
     * Upper 16-bits contain ARSTDIS register configuration value, 
     * lower 16-bits contain RSTCON register configuration value
     */
    0x45U,
    /* Total number of Clock settings */
    ((Mcu_ClockType)1U),
    /* Total number of RAM Sectors */
    ((Mcu_RamSectionType)0U),
    /* The maximum mode that is supported by this module instance */
    (MCU_MODE_MAX0),
    /* Ptr to Standby Mode in config structure */
    NULL_PTR,
  }
};

#define MCU_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

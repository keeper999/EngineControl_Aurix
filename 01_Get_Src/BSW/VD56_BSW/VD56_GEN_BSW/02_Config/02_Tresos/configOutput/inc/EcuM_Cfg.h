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
**   $FILENAME   : EcuM_Cfg.h $                                               **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   DATE, TIME: 2014-09-29, 11:35:21                                         **
**                                                                            **
**   GENERATOR : Build b131017-0205                                           **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**   DESCRIPTION  : EcuM configuration generated from ECU configuration file  **
**                                                                            **
**   SPECIFICATION(S) : AUTOSAR_SWS_ECU_StateManager.pdf, AS V4.0             **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: NO                                      **
**                                                                            **
*******************************************************************************/


#ifndef ECUM_CFG_H
#define ECUM_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dio.h"
#include "Gpt.h"
#include "Icu.h"
#include "Msc.h"
#include "Port.h"
#include "Pwm.h"
#include "Spi.h"
#include "Wdg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*
  Published parameters
*/
/* EcuM Vendor ID */
#define ECUM_VENDOR_ID                  ((uint16)17)
/* EcuM Module ID */
#define ECUM_MODULE_ID                  ((uint8)10)


/* Autosar version of the module */
#define ECUM_AS_VERSION (403)

/* AUTOSAR specification version numbers */
#define ECUM_AR_RELEASE_MAJOR_VERSION      (4U)
#define ECUM_AR_RELEASE_MINOR_VERSION      (0U)
#define ECUM_AR_RELEASE_REVISION_VERSION   (3U)

/* Vendor specific implementation version information */
#define ECUM_SW_MAJOR_VERSION   (2U)
#define ECUM_SW_MINOR_VERSION   (0U)
#define ECUM_SW_PATCH_VERSION   (0U)



/* Macros indicating the Mcu using the fixed address STD_OFF. */	
#define MCU_USES_FIXED_ADDR   (STD_OFF)	
/* Macros indicating the modules used by ECU State Manager */



#define ECUM_USES_GTM
#define ECUM_USES_PORT
#define ECUM_USES_DIO
#define ECUM_USES_ICU
#define ECUM_USES_PWM
#define ECUM_USES_GPT
#define ECUM_USES_SPI
#define ECUM_USES_MSC
#define ECUM_USES_WDG


/*
Configuration Options: Ecum_PostBuildConfigType 
SELECTABLE : Post Build Selectable
LOADABLE : Post Build Loadable.
*/
#define ECUM_SELECTABLE (0)
#define ECUM_LOADABLE (1U)
/*
Configuration: Ecum_PostBuildConfigType 
SELECTABLE : Post Build Selectable
LOADABLE : Post Build Loadable.
*/

#define ECUM_POSTBUILD_CONFIG_TYPE (ECUM_SELECTABLE)

/*
Configuration: EcuM_DriverInitListZeroConfig 
*/
#define EcuM_DriverInitListZeroConfig() \
{\
}
/*
Configuration: EcuM_DriverInitListOneConfig 
*/
#define EcuM_DriverInitListOneConfig(configptr) \
{\
\
  Port_Init(configptr->Port_ConfigData);  \
  Dio_Init(configptr->Dio_ConfigData);  \
  Icu_17_GtmCcu6_Init(configptr->Icu_ConfigData);  \
  Pwm_17_Gtm_Init(configptr->Pwm_ConfigData);  \
  Gpt_Init(configptr->Gpt_ConfigData);  \
  Spi_Init(configptr->Spi_ConfigData);  \
  Msc_Init(configptr->Msc_ConfigData);  \
  Wdg_17_Scu_Init(configptr->Wdg_ConfigData);  \
}

/*
Configuration: EcuM_DriverInitListTwoConfig 
*/
#define EcuM_DriverInitListTwoConfig(configptr) \
{\
}
/*
Configuration: EcuM_DriverInitListThreeConfig 
*/
#define EcuM_DriverInitListThreeConfig(configptr) \
{\
}

/*
Configuration: EcuM_DriverRestartListConfig 
*/
#define EcuM_DriverRestartListConfig() \
{\
}
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/***********************************************
 Structure of post-build configuration data for the EcuM.
 The structure elements are generated by code generator, depending upon the 
 modules used in PB configuration
  
***********************************************/
typedef struct EcuM_ConfigType_Tag 
{
  /* Identifier for post-build time configuration */
  const uint16                         ConfigurationIdentifier;
  /* Hash Identifier of pre compile time configuration */
  const uint32                         PreCompileIdentifier; 
  /* Pointers to config data of other MCAL modules (Post-build Only) */    

  const struct Mcu_ConfigType   * Mcu_ConfigData;
  const struct Port_ConfigType   * Port_ConfigData;
  const struct Dio_ConfigType   * Dio_ConfigData;
  const struct Icu_17_GtmCcu6_ConfigType   * Icu_ConfigData;

  const struct Pwm_17_Gtm_ConfigType   * Pwm_ConfigData;

  const struct Gpt_ConfigType   * Gpt_ConfigData;
  const struct Spi_ConfigType   * Spi_ConfigData;
  const struct Msc_ConfigType   * Msc_ConfigData;
  const struct Wdg_17_Scu_ConfigType   * Wdg_ConfigData;


 /* EcuM internal configuration data */
  const uint8               LocalConfigData;
}EcuM_ConfigType;


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


/*******************************************************************************
 * Exported name of post-build selectable configuration data for EcuM. 
 * Defined in the EcuM_Cfg.c
 ******************************************************************************/
#define ECUM_START_SEC_POSTBUILDCFG
#include "EcuM_MemMap.h"
extern const struct EcuM_ConfigType_Tag EcuM_ConfigAlternative[];
#define ECUM_STOP_SEC_POSTBUILDCFG
#include "EcuM_MemMap.h"

/************************************************
 * Declare parameter implemented as const.
 * Defined in the EcuM_Cfg.c
 ***********************************************/
#define ECUM_START_SEC_CONST_32BIT
#include "EcuM_MemMap.h"
extern const uint32 EcuM_ConfigConsistencyHash;
#define ECUM_STOP_SEC_CONST_32BIT
#include "EcuM_MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declaration	s                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif  /* _ECUM_CFG_H */

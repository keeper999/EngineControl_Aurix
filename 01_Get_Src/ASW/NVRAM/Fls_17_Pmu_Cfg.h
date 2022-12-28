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
**  $FILENAME   : Fls_17_Pmu_Cfg.h $                                         **
**                                                                           **
**  $CC VERSION : \main\33 $                                                 **
**                                                                           **
**  DATE, TIME: 2014-09-19, 14:17:22                                         **
**                                                                           **
**  GENERATOR : Build b131017-0205                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : FLS configuration generated out of ECU configuration      **
**                   file (Fls_17_Pmu.bmd)                                   **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef FLS_CFG_H 
#define FLS_CFG_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Typedefs Imported from Mem Interface */ 
#include "MemIf_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*
  Published parameters
*/
/* Fls Vendor ID */
#define FLS_17_PMU_VENDOR_ID                  ((uint16)17)  
/* FLS Module ID */
#define FLS_17_PMU_MODULE_ID                  ((uint16)92)

/* FLS Instance ID */
#define FLS_17_PMU_INSTANCE_ID                ((uint8)0)

#define Fls_17_PmuConf_FlsGeneral_FlsDriverIndex  FLS_17_PMU_INSTANCE_ID

/* Autosar specification version */
#define FLS_17_PMU_AR_RELEASE_MAJOR_VERSION           (4U)
#define FLS_17_PMU_AR_RELEASE_MINOR_VERSION           (0U)
#define FLS_17_PMU_AR_RELEASE_REVISION_VERSION        (3U)

/* Vendor specific implementation version information */
#define FLS_17_PMU_SW_MAJOR_VERSION           (2U)
#define FLS_17_PMU_SW_MINOR_VERSION           (1U)
#define FLS_17_PMU_SW_PATCH_VERSION           (3U)

/*
  The following macros will enable or disable a particular feature in FLS 
  module.Set the macro to STD_ON to enable the feature and STD_OFF to 
  disable the same.  
*/
/* Enable/Disable Development error detection(DET)  */
#define FLS_DEV_ERROR_DETECT         (STD_ON)

/* Flash access code is to be loaded before job start true/false*/
#define FLS_AC_LOAD_ON_JOB_START     (STD_OFF)

/* Flash job interrupt mode or polling mode*/
#define FLS_USE_INTERRUPTS          (STD_OFF)

/*Fls_cancel api selection*/
#define FLS_CANCEL_API             (STD_ON)

/*Fls_SetMode api selection*/
#define FLS_SET_MODE_API             (STD_ON)

/*Fls_compare api selection*/
#define FLS_COMPARE_API            (STD_ON)

/*Fls_GetJobResult api selection*/
#define FLS_GET_JOB_RESULT_API     (STD_ON)

/*Fls_GetStatus api selection*/
#define FLS_GET_STATUS_API         (STD_ON)

/*Fls_GetVersionInfo api selection*/
#define FLS_VERSION_INFO_API   (STD_OFF)

/*Erase suspend/resume feature selection*/
#define FLS_USE_ERASESUSPEND   (STD_ON)

/* Enable/Disable Debug support  */
#define FLS_DEBUG_SUPPORT     (STD_OFF)


/* IFX FEE is being used in configuration */
#define FLS_IFX_FEE_USED        (STD_ON)

/*DFLASH base/start address*/
#define FLS_BASE_ADDRESS           (0xaf000000U)

/*DFLASH total size*/
#define FLS_TOTAL_SIZE             (0x60000U)

#define DFLASH_BANK0_PHYSICAL    (FLS_BASE_ADDRESS)

/* Macro to Define  FLS_OFFSET of DFLASH0 and DFLASH1 */
#define FLS_OFFSET               ((uint32)0x30000U)


/* Physical Adress of data flash bank 1 */
#define DFLASH_BANK1_PHYSICAL    (0xaf030000U)


/* Number of DFLASH Banks */
#define FLS_NUMBER_OF_SECTORS    (2U) /* FLS_NUMBER_OF_SECTORS */
#define FLS_SECTOR_STARTADDRESS (0U)
/* Total size of each Data flash bank */
#define FLS_SECTOR_SIZE          (0x30000U) /* FLS_SECTOR_SIZE */
/* Page size of the Data flash is 128 bytes */
#define FLS_PAGE_SIZE            (8U)  /* FLS_PAGE_SIZE */
/* Number of Flash logical sectors to be erased in one erase command */
#define FLS_ERASE_SECTORS    (24U)


#define FLS_PB_FIXEDADDR          (STD_ON)

/* erase and write times are published in us */
#define FLS_17_PMU_ERASE_TIME            (1000000U)

#define FLS_17_PMU_WRITE_TIME            (150U)






#define FLS_E_COMPARE_FAILED_DEM_REPORT    (DISABLE_DEM_REPORT)

#define FLS_E_ERASE_FAILED_DEM_REPORT    (DISABLE_DEM_REPORT)

#define FLS_E_WRITE_FAILED_DEM_REPORT    (DISABLE_DEM_REPORT)

#define FLS_E_READ_FAILED_DEM_REPORT    (DISABLE_DEM_REPORT)

/* Hardare Timeout for Command cycle*/
#define FLS_CMDCYCLE_TIMEOUT            (25U)

/*Timeout for Erase suspend/resume feature*/
#if (FLS_USE_ERASESUSPEND == STD_ON)
#define FLS_ERASESUSPEND_TIMEOUT        (0x100U)
#endif

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* FLS_CFG_H */


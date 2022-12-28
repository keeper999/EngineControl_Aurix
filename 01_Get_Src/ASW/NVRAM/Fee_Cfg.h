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
**  $FILENAME   : Fee_Cfg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\16 $                                                 **
**                                                                           **
**  DATE, TIME: 2014-09-19, 14:17:23                                         **
**                                                                           **
**  GENERATOR : Build b131017-0205                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : FEE configuration generated out of ECU configuration      **
**                   file (Fee.bmd)                                          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef  FEE_CFG_H
#define  FEE_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* Typedefs Imported from Memory Abstract Interface */ 
#include "MemIf_Types.h"

/* Callback functions imported from NvM Module */
#include "NvM_Cbk.h"

/* Functions imported from Fls Module */
#include "Fls_17_Pmu.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/* FEE AS version information */
#define FEE_AS_VERSION (403)
#define FEE_AR_RELEASE_MAJOR_VERSION  (4U)
#define FEE_AR_RELEASE_MINOR_VERSION  (0U)
#define FEE_AR_RELEASE_REVISION_VERSION  (3U)

/* Vendor specific implementation version information */
#define FEE_SW_MAJOR_VERSION  (2U)
#define FEE_SW_MINOR_VERSION  (2U)
#define FEE_SW_PATCH_VERSION  (2U)

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
                        
/*******************************************************************************
**                    Static configuration parameters                         **
*******************************************************************************/

/* Development error detection enabled/disabled */
#define FEE_DEV_ERROR_DETECT       (STD_ON)

/* Fee_GetVersionInfo API enabled/disabled */
#define FEE_VERSION_INFO_API       (STD_OFF)

/* Fee_GetCycleCount API enabled/disabled */
#define FEE_GET_CYCLE_COUNT_API    (STD_OFF)

/* Fee_SetMode API enabled/disabled */
#define FEE_SET_MODE_SUPPORTED     (STD_ON)

/* Fee_17_GetPrevData API enabled/disabled */
#define FEE_GET_PREV_DATA_API      (STD_OFF)

/* Enable/Disable Debug support  */
#define FEE_DEBUG_SUPPORT     (STD_OFF)

/* Erase suspend/resume feature supported in FLS */
#define FEE_FLS_SUPPORTS_ERASE_SUSPEND  (STD_ON)

/* DFlash WordLine size */
#define FEE_DFLASH_WORDLINE_SIZE     (512U)

#define FEE_CONTINUE          (0U)
#define FEE_STOP_AT_GC        (1U)

#define FEE_UNCFG_BLK_OVERFLOW_HANDLE    (FEE_CONTINUE)

/* Virtual page size, i.e., DF_EEPROM page size */
#define FEE_VIRTUAL_PAGE_SIZE      (8U)

/* Logical block's overhead in bytes */
#define FEE_BLOCK_OVERHEAD         (17U)

/* Logical block's data page overhead in bytes */
#define FEE_PAGE_OVERHEAD          (1U)

/* Maximum blocking (delay) time in ms */
#define FEE_MAXIMUM_BLOCKING_TIME  (10U)

/* Maximum number of configured blocks to be handled */
#define FEE_MAX_BLOCK_COUNT        (1000U)

/* Symbolic names of logical blocks */
#ifdef FeeConf_FeeBlockConfiguration_Block_ConfigID /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_Block_ConfigID already defined
#else 
#define FeeConf_FeeBlockConfiguration_Block_ConfigID ((uint16)2)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Block_ConfigID */

#ifdef FeeConf_FeeBlockConfiguration_Block_ConfigID_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_Block_ConfigID_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_Block_ConfigID_1 ((uint16)3)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Block_ConfigID_1 */

#ifdef FeeConf_FeeBlockConfiguration_TEST_EEPROM_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TEST_EEPROM_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_TEST_EEPROM_1 ((uint16)4)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TEST_EEPROM_1 */

#ifdef FeeConf_FeeBlockConfiguration_TEST_EEPROM_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TEST_EEPROM_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_TEST_EEPROM_2 ((uint16)6)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TEST_EEPROM_2 */

#ifdef FeeConf_FeeBlockConfiguration_SPI_REREAD_FRAMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SPI_REREAD_FRAMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_SPI_REREAD_FRAMES ((uint16)8)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SPI_REREAD_FRAMES */

#ifdef FeeConf_FeeBlockConfiguration_EPMSRV /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_EPMSRV already defined
#else 
#define FeeConf_FeeBlockConfiguration_EPMSRV ((uint16)10)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_EPMSRV */

#ifdef FeeConf_FeeBlockConfiguration_DOWNLOAD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DOWNLOAD already defined
#else 
#define FeeConf_FeeBlockConfiguration_DOWNLOAD ((uint16)12)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DOWNLOAD */

#ifdef FeeConf_FeeBlockConfiguration_ECRITURES_EEPROM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ECRITURES_EEPROM already defined
#else 
#define FeeConf_FeeBlockConfiguration_ECRITURES_EEPROM ((uint16)14)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ECRITURES_EEPROM */

#ifdef FeeConf_FeeBlockConfiguration_RESET /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_RESET already defined
#else 
#define FeeConf_FeeBlockConfiguration_RESET ((uint16)16)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_RESET */

#ifdef FeeConf_FeeBlockConfiguration_EXCEPTION_REGS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_EXCEPTION_REGS already defined
#else 
#define FeeConf_FeeBlockConfiguration_EXCEPTION_REGS ((uint16)18)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_EXCEPTION_REGS */

#ifdef FeeConf_FeeBlockConfiguration_TEST_EEPROM_3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TEST_EEPROM_3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_TEST_EEPROM_3 ((uint16)20)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TEST_EEPROM_3 */

#ifdef FeeConf_FeeBlockConfiguration_REDPROD_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_REDPROD_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_REDPROD_1 ((uint16)22)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_REDPROD_1 */

#ifdef FeeConf_FeeBlockConfiguration_REDPROD_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_REDPROD_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_REDPROD_2 ((uint16)24)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_REDPROD_2 */

#ifdef FeeConf_FeeBlockConfiguration_REDPROD_5 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_REDPROD_5 already defined
#else 
#define FeeConf_FeeBlockConfiguration_REDPROD_5 ((uint16)26)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_REDPROD_5 */

#ifdef FeeConf_FeeBlockConfiguration_REDPROD_8 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_REDPROD_8 already defined
#else 
#define FeeConf_FeeBlockConfiguration_REDPROD_8 ((uint16)28)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_REDPROD_8 */

#ifdef FeeConf_FeeBlockConfiguration_PROD_1_VALEOIDENT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PROD_1_VALEOIDENT already defined
#else 
#define FeeConf_FeeBlockConfiguration_PROD_1_VALEOIDENT ((uint16)30)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PROD_1_VALEOIDENT */

#ifdef FeeConf_FeeBlockConfiguration_PROD_2_PSAIDENT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PROD_2_PSAIDENT already defined
#else 
#define FeeConf_FeeBlockConfiguration_PROD_2_PSAIDENT ((uint16)32)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PROD_2_PSAIDENT */

#ifdef FeeConf_FeeBlockConfiguration_PROD_5_CIENUM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PROD_5_CIENUM already defined
#else 
#define FeeConf_FeeBlockConfiguration_PROD_5_CIENUM ((uint16)34)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PROD_5_CIENUM */

#ifdef FeeConf_FeeBlockConfiguration_PROD_8_TRIMS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PROD_8_TRIMS already defined
#else 
#define FeeConf_FeeBlockConfiguration_PROD_8_TRIMS ((uint16)36)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PROD_8_TRIMS */

#ifdef FeeConf_FeeBlockConfiguration_EEPROM_VERSION /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_EEPROM_VERSION already defined
#else 
#define FeeConf_FeeBlockConfiguration_EEPROM_VERSION ((uint16)38)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_EEPROM_VERSION */

#ifdef FeeConf_FeeBlockConfiguration_KNKADPCOR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_KNKADPCOR already defined
#else 
#define FeeConf_FeeBlockConfiguration_KNKADPCOR ((uint16)40)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_KNKADPCOR */

#ifdef FeeConf_FeeBlockConfiguration_POSTEQUSRV /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_POSTEQUSRV already defined
#else 
#define FeeConf_FeeBlockConfiguration_POSTEQUSRV ((uint16)42)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_POSTEQUSRV */

#ifdef FeeConf_FeeBlockConfiguration_POSTEQUSRV_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_POSTEQUSRV_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_POSTEQUSRV_1 ((uint16)43)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_POSTEQUSRV_1 */

#ifdef FeeConf_FeeBlockConfiguration_SAIMMO_CODE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SAIMMO_CODE already defined
#else 
#define FeeConf_FeeBlockConfiguration_SAIMMO_CODE ((uint16)44)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SAIMMO_CODE */

#ifdef FeeConf_FeeBlockConfiguration_SAIMMO_CODE_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SAIMMO_CODE_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SAIMMO_CODE_1 ((uint16)45)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SAIMMO_CODE_1 */

#ifdef FeeConf_FeeBlockConfiguration_SAIMMO_ETAT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SAIMMO_ETAT already defined
#else 
#define FeeConf_FeeBlockConfiguration_SAIMMO_ETAT ((uint16)46)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SAIMMO_ETAT */

#ifdef FeeConf_FeeBlockConfiguration_SAIMMO_ETAT_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SAIMMO_ETAT_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SAIMMO_ETAT_1 ((uint16)47)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SAIMMO_ETAT_1 */

#ifdef FeeConf_FeeBlockConfiguration_TELECODAGE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TELECODAGE already defined
#else 
#define FeeConf_FeeBlockConfiguration_TELECODAGE ((uint16)48)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TELECODAGE */

#ifdef FeeConf_FeeBlockConfiguration_ACCPEM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ACCPEM already defined
#else 
#define FeeConf_FeeBlockConfiguration_ACCPEM ((uint16)50)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ACCPEM */

#ifdef FeeConf_FeeBlockConfiguration_ACCPLRNPOS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ACCPLRNPOS already defined
#else 
#define FeeConf_FeeBlockConfiguration_ACCPLRNPOS ((uint16)52)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ACCPLRNPOS */

#ifdef FeeConf_FeeBlockConfiguration_ACQCOT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ACQCOT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ACQCOT ((uint16)54)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ACQCOT */

#ifdef FeeConf_FeeBlockConfiguration_AFAMGTT_NVRAM_INT8_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFAMGTT_NVRAM_INT8_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFAMGTT_NVRAM_INT8_CONST ((uint16)56)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFAMGTT_NVRAM_INT8_CONST */

#ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT16_CALIB /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT16_CALIB already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT16_CALIB ((uint16)58)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT16_CALIB */

#ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT32_CALIB /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT32_CALIB already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT32_CALIB ((uint16)60)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT32_CALIB */

#ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT8_CALIB /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT8_CALIB already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT8_CALIB ((uint16)62)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT8_CALIB */

#ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_BOOLEAN_CALIB /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFAT_NVRAM_BOOLEAN_CALIB already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFAT_NVRAM_BOOLEAN_CALIB ((uint16)64)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_BOOLEAN_CALIB */

#ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT16_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT16_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT16_CONST ((uint16)66)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT16_CONST */

#ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT8_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT8_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT8_CONST ((uint16)68)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_INT8_CONST */

#ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_BOOLEAN_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFAT_NVRAM_BOOLEAN_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFAT_NVRAM_BOOLEAN_CONST ((uint16)70)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFAT_NVRAM_BOOLEAN_CONST */

#ifdef FeeConf_FeeBlockConfiguration_CLCNFISAGAIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CLCNFISAGAIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_CLCNFISAGAIN ((uint16)72)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CLCNFISAGAIN */

#ifdef FeeConf_FeeBlockConfiguration_CLUPEDPOSNDIAG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CLUPEDPOSNDIAG already defined
#else 
#define FeeConf_FeeBlockConfiguration_CLUPEDPOSNDIAG ((uint16)74)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CLUPEDPOSNDIAG */

#ifdef FeeConf_FeeBlockConfiguration_CLUSWTDIAG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CLUSWTDIAG already defined
#else 
#define FeeConf_FeeBlockConfiguration_CLUSWTDIAG ((uint16)76)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CLUSWTDIAG */

#ifdef FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT16_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT16_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT16_CONST_1 ((uint16)78)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT16_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT32_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT32_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT32_CONST_1 ((uint16)80)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT32_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT8_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT8_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT8_CONST_1 ((uint16)82)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COEMSTT_NVRAM_INT8_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_COFANCMDDIAG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COFANCMDDIAG already defined
#else 
#define FeeConf_FeeBlockConfiguration_COFANCMDDIAG ((uint16)84)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COFANCMDDIAG */

#ifdef FeeConf_FeeBlockConfiguration_FHCANF552 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FHCANF552 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FHCANF552 ((uint16)86)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FHCANF552 */

#ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT16_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT16_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT16_CONST_1 ((uint16)88)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT16_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_1 ((uint16)90)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_2 ((uint16)92)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_2 */

#ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_3 ((uint16)94)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_INT8_CONST_3 */

#ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_BOOLEAN_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_BOOLEAN_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_BOOLEAN_CONST_1 ((uint16)96)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_BOOLEAN_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_BOOLEAN_CONST_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_BOOLEAN_CONST_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_BOOLEAN_CONST_2 ((uint16)98)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COSTOPSTART_NVRAM_BOOLEAN_CONST_2 */

#ifdef FeeConf_FeeBlockConfiguration_CSTRFUCONCESTIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CSTRFUCONCESTIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_CSTRFUCONCESTIM ((uint16)100)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CSTRFUCONCESTIM */

#ifdef FeeConf_FeeBlockConfiguration_DCM_MANU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DCM_MANU already defined
#else 
#define FeeConf_FeeBlockConfiguration_DCM_MANU ((uint16)102)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DCM_MANU */

#ifdef FeeConf_FeeBlockConfiguration_DFWCTL_NVRAM_INT16_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFWCTL_NVRAM_INT16_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFWCTL_NVRAM_INT16_CONST ((uint16)104)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFWCTL_NVRAM_INT16_CONST */

#ifdef FeeConf_FeeBlockConfiguration_DIAGAIREXTPRES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DIAGAIREXTPRES already defined
#else 
#define FeeConf_FeeBlockConfiguration_DIAGAIREXTPRES ((uint16)106)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DIAGAIREXTPRES */

#ifdef FeeConf_FeeBlockConfiguration_DSO2SEN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DSO2SEN already defined
#else 
#define FeeConf_FeeBlockConfiguration_DSO2SEN ((uint16)108)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DSO2SEN */

#ifdef FeeConf_FeeBlockConfiguration_ECUMNG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ECUMNG already defined
#else 
#define FeeConf_FeeBlockConfiguration_ECUMNG ((uint16)110)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ECUMNG */

#ifdef FeeConf_FeeBlockConfiguration_ENGRUNST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ENGRUNST already defined
#else 
#define FeeConf_FeeBlockConfiguration_ENGRUNST ((uint16)112)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ENGRUNST */

#ifdef FeeConf_FeeBlockConfiguration_DIVERS_EEP_FIXE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DIVERS_EEP_FIXE already defined
#else 
#define FeeConf_FeeBlockConfiguration_DIVERS_EEP_FIXE ((uint16)114)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DIVERS_EEP_FIXE */

#ifdef FeeConf_FeeBlockConfiguration_EOMGSL_NVRAM_INT32_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_EOMGSL_NVRAM_INT32_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_EOMGSL_NVRAM_INT32_CONST ((uint16)116)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_EOMGSL_NVRAM_INT32_CONST */

#ifdef FeeConf_FeeBlockConfiguration_EXMGSLT2_NVRAM_INT16_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_EXMGSLT2_NVRAM_INT16_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_EXMGSLT2_NVRAM_INT16_CONST ((uint16)118)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_EXMGSLT2_NVRAM_INT16_CONST */

#ifdef FeeConf_FeeBlockConfiguration_FISARFUDET /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FISARFUDET already defined
#else 
#define FeeConf_FeeBlockConfiguration_FISARFUDET ((uint16)120)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FISARFUDET */

#ifdef FeeConf_FeeBlockConfiguration_FISA_NVRAM_INT8_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FISA_NVRAM_INT8_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FISA_NVRAM_INT8_CONST_1 ((uint16)122)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FISA_NVRAM_INT8_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_FLOWMNG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FLOWMNG already defined
#else 
#define FeeConf_FeeBlockConfiguration_FLOWMNG ((uint16)124)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FLOWMNG */

#ifdef FeeConf_FeeBlockConfiguration_FTPCTL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FTPCTL already defined
#else 
#define FeeConf_FeeBlockConfiguration_FTPCTL ((uint16)126)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FTPCTL */

#ifdef FeeConf_FeeBlockConfiguration_FUCNS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FUCNS already defined
#else 
#define FeeConf_FeeBlockConfiguration_FUCNS ((uint16)128)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FUCNS */

#ifdef FeeConf_FeeBlockConfiguration_FULVL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FULVL already defined
#else 
#define FeeConf_FeeBlockConfiguration_FULVL ((uint16)130)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FULVL */

#ifdef FeeConf_FeeBlockConfiguration_WUC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_WUC already defined
#else 
#define FeeConf_FeeBlockConfiguration_WUC ((uint16)132)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_WUC */

#ifdef FeeConf_FeeBlockConfiguration_STATUSOFDTC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STATUSOFDTC already defined
#else 
#define FeeConf_FeeBlockConfiguration_STATUSOFDTC ((uint16)134)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STATUSOFDTC */

#ifdef FeeConf_FeeBlockConfiguration_INDICOBD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INDICOBD already defined
#else 
#define FeeConf_FeeBlockConfiguration_INDICOBD ((uint16)136)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INDICOBD */

#ifdef FeeConf_FeeBlockConfiguration_IUPRGENDEN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IUPRGENDEN already defined
#else 
#define FeeConf_FeeBlockConfiguration_IUPRGENDEN ((uint16)138)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IUPRGENDEN */

#ifdef FeeConf_FeeBlockConfiguration_RC01 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_RC01 already defined
#else 
#define FeeConf_FeeBlockConfiguration_RC01 ((uint16)140)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_RC01 */

#ifdef FeeConf_FeeBlockConfiguration_GOBD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GOBD already defined
#else 
#define FeeConf_FeeBlockConfiguration_GOBD ((uint16)142)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GOBD */

#ifdef FeeConf_FeeBlockConfiguration_IUPRRATIO /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IUPRRATIO already defined
#else 
#define FeeConf_FeeBlockConfiguration_IUPRRATIO ((uint16)144)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IUPRRATIO */

#ifdef FeeConf_FeeBlockConfiguration_MEM1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM1 ((uint16)146)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM1 */

#ifdef FeeConf_FeeBlockConfiguration_MEM2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM2 ((uint16)148)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM2 */

#ifdef FeeConf_FeeBlockConfiguration_MEM3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM3 ((uint16)150)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM3 */

#ifdef FeeConf_FeeBlockConfiguration_MEM4 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM4 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM4 ((uint16)152)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM4 */

#ifdef FeeConf_FeeBlockConfiguration_MEM5 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM5 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM5 ((uint16)154)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM5 */

#ifdef FeeConf_FeeBlockConfiguration_MEM6 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM6 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM6 ((uint16)156)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM6 */

#ifdef FeeConf_FeeBlockConfiguration_MEM7 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM7 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM7 ((uint16)158)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM7 */

#ifdef FeeConf_FeeBlockConfiguration_MEM8 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM8 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM8 ((uint16)160)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM8 */

#ifdef FeeConf_FeeBlockConfiguration_MEM9 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM9 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM9 ((uint16)162)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM9 */

#ifdef FeeConf_FeeBlockConfiguration_MEM10 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM10 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM10 ((uint16)164)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM10 */

#ifdef FeeConf_FeeBlockConfiguration_MEM11 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM11 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM11 ((uint16)166)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM11 */

#ifdef FeeConf_FeeBlockConfiguration_MEM12 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM12 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM12 ((uint16)168)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM12 */

#ifdef FeeConf_FeeBlockConfiguration_MEM13 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM13 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM13 ((uint16)170)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM13 */

#ifdef FeeConf_FeeBlockConfiguration_MEM14 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM14 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM14 ((uint16)172)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM14 */

#ifdef FeeConf_FeeBlockConfiguration_MEM15 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM15 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM15 ((uint16)174)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM15 */

#ifdef FeeConf_FeeBlockConfiguration_MEM16 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM16 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM16 ((uint16)176)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM16 */

#ifdef FeeConf_FeeBlockConfiguration_MEM17 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM17 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM17 ((uint16)178)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM17 */

#ifdef FeeConf_FeeBlockConfiguration_MEM18 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM18 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM18 ((uint16)180)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM18 */

#ifdef FeeConf_FeeBlockConfiguration_MEM19 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM19 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM19 ((uint16)182)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM19 */

#ifdef FeeConf_FeeBlockConfiguration_MEM20 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM20 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM20 ((uint16)184)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM20 */

#ifdef FeeConf_FeeBlockConfiguration_MEM21 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM21 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM21 ((uint16)186)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM21 */

#ifdef FeeConf_FeeBlockConfiguration_MEM22 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM22 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM22 ((uint16)188)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM22 */

#ifdef FeeConf_FeeBlockConfiguration_MEM23 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM23 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM23 ((uint16)190)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM23 */

#ifdef FeeConf_FeeBlockConfiguration_MEM24 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM24 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM24 ((uint16)192)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM24 */

#ifdef FeeConf_FeeBlockConfiguration_MEM25 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM25 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM25 ((uint16)194)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM25 */

#ifdef FeeConf_FeeBlockConfiguration_MEM26 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM26 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM26 ((uint16)196)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM26 */

#ifdef FeeConf_FeeBlockConfiguration_MEM27 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM27 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM27 ((uint16)198)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM27 */

#ifdef FeeConf_FeeBlockConfiguration_MEM28 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM28 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM28 ((uint16)200)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM28 */

#ifdef FeeConf_FeeBlockConfiguration_MEM29 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM29 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM29 ((uint16)202)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM29 */

#ifdef FeeConf_FeeBlockConfiguration_MEM30 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM30 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM30 ((uint16)204)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM30 */

#ifdef FeeConf_FeeBlockConfiguration_MEM31 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM31 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM31 ((uint16)206)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM31 */

#ifdef FeeConf_FeeBlockConfiguration_MEM32 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM32 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM32 ((uint16)208)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM32 */

#ifdef FeeConf_FeeBlockConfiguration_MEM33 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM33 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM33 ((uint16)210)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM33 */

#ifdef FeeConf_FeeBlockConfiguration_MEM34 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM34 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM34 ((uint16)212)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM34 */

#ifdef FeeConf_FeeBlockConfiguration_MEM35 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM35 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM35 ((uint16)214)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM35 */

#ifdef FeeConf_FeeBlockConfiguration_MEM36 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM36 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM36 ((uint16)216)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM36 */

#ifdef FeeConf_FeeBlockConfiguration_MEM37 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM37 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM37 ((uint16)218)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM37 */

#ifdef FeeConf_FeeBlockConfiguration_MEM38 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM38 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM38 ((uint16)220)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM38 */

#ifdef FeeConf_FeeBlockConfiguration_MEM39 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM39 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM39 ((uint16)222)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM39 */

#ifdef FeeConf_FeeBlockConfiguration_MEM40 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MEM40 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MEM40 ((uint16)224)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MEM40 */

#ifdef FeeConf_FeeBlockConfiguration_GMIL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GMIL already defined
#else 
#define FeeConf_FeeBlockConfiguration_GMIL ((uint16)226)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GMIL */

#ifdef FeeConf_FeeBlockConfiguration_AASTART_BIDON /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AASTART_BIDON already defined
#else 
#define FeeConf_FeeBlockConfiguration_AASTART_BIDON ((uint16)228)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AASTART_BIDON */

#ifdef FeeConf_FeeBlockConfiguration_COH_PED /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_PED already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_PED ((uint16)230)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_PED */

#ifdef FeeConf_FeeBlockConfiguration_SCPOC_PED2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCPOC_PED2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCPOC_PED2 ((uint16)232)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCPOC_PED2 */

#ifdef FeeConf_FeeBlockConfiguration_SCG_PED2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_PED2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_PED2 ((uint16)234)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_PED2 */

#ifdef FeeConf_FeeBlockConfiguration_SCPOC_PED1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCPOC_PED1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCPOC_PED1 ((uint16)236)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCPOC_PED1 */

#ifdef FeeConf_FeeBlockConfiguration_SCG_PED1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_PED1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_PED1 ((uint16)238)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_PED1 */

#ifdef FeeConf_FeeBlockConfiguration_STUCKACCP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCKACCP already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCKACCP ((uint16)240)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCKACCP */

#ifdef FeeConf_FeeBlockConfiguration_SCPACCPSWT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCPACCPSWT already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCPACCPSWT ((uint16)242)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCPACCPSWT */

#ifdef FeeConf_FeeBlockConfiguration_STUCKACCPSWT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCKACCPSWT already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCKACCPSWT ((uint16)244)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCKACCPSWT */

#ifdef FeeConf_FeeBlockConfiguration_SCGACCPSWT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCGACCPSWT already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCGACCPSWT ((uint16)246)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCGACCPSWT */

#ifdef FeeConf_FeeBlockConfiguration_COHACCPSWT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COHACCPSWT already defined
#else 
#define FeeConf_FeeBlockConfiguration_COHACCPSWT ((uint16)248)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COHACCPSWT */

#ifdef FeeConf_FeeBlockConfiguration_COH_RACCP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_RACCP already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_RACCP ((uint16)250)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_RACCP */

#ifdef FeeConf_FeeBlockConfiguration_GRD_PACMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GRD_PACMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_GRD_PACMES ((uint16)252)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GRD_PACMES */

#ifdef FeeConf_FeeBlockConfiguration_HI_PACMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HI_PACMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_HI_PACMES ((uint16)254)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HI_PACMES */

#ifdef FeeConf_FeeBlockConfiguration_LO_PACMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LO_PACMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_LO_PACMES ((uint16)256)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LO_PACMES */

#ifdef FeeConf_FeeBlockConfiguration_GRD_TCOMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GRD_TCOMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_GRD_TCOMES ((uint16)258)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GRD_TCOMES */

#ifdef FeeConf_FeeBlockConfiguration_OC_TCOMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_TCOMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_TCOMES ((uint16)260)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_TCOMES */

#ifdef FeeConf_FeeBlockConfiguration_SCG_TCOMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_TCOMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_TCOMES ((uint16)262)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_TCOMES */

#ifdef FeeConf_FeeBlockConfiguration_SCP_TCOMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_TCOMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_TCOMES ((uint16)264)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_TCOMES */

#ifdef FeeConf_FeeBlockConfiguration_SCG_AIREXTPRESACQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_AIREXTPRESACQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_AIREXTPRESACQ ((uint16)266)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_AIREXTPRESACQ */

#ifdef FeeConf_FeeBlockConfiguration_SCP_AIREXTPRESACQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_AIREXTPRESACQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_AIREXTPRESACQ ((uint16)268)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_AIREXTPRESACQ */

#ifdef FeeConf_FeeBlockConfiguration_SCP_PDSTHRMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_PDSTHRMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_PDSTHRMES ((uint16)270)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_PDSTHRMES */

#ifdef FeeConf_FeeBlockConfiguration_SCG_PDSTHRMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_PDSTHRMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_PDSTHRMES ((uint16)272)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_PDSTHRMES */

#ifdef FeeConf_FeeBlockConfiguration_SCP_PBRKASI /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_PBRKASI already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_PBRKASI ((uint16)274)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_PBRKASI */

#ifdef FeeConf_FeeBlockConfiguration_SCG_PBRKASI /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_PBRKASI already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_PBRKASI ((uint16)276)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_PBRKASI */

#ifdef FeeConf_FeeBlockConfiguration_GRD_PBRKASI /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GRD_PBRKASI already defined
#else 
#define FeeConf_FeeBlockConfiguration_GRD_PBRKASI ((uint16)278)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GRD_PBRKASI */

#ifdef FeeConf_FeeBlockConfiguration_STALLCOH_PDSTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STALLCOH_PDSTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_STALLCOH_PDSTHR ((uint16)280)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STALLCOH_PDSTHR */

#ifdef FeeConf_FeeBlockConfiguration_CRKCOH_PDSTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CRKCOH_PDSTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_CRKCOH_PDSTHR ((uint16)282)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CRKCOH_PDSTHR */

#ifdef FeeConf_FeeBlockConfiguration_STABCOH_PDSTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STABCOH_PDSTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_STABCOH_PDSTHR ((uint16)284)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STABCOH_PDSTHR */

#ifdef FeeConf_FeeBlockConfiguration_THRCOH_PDSTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_THRCOH_PDSTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_THRCOH_PDSTHR ((uint16)286)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_THRCOH_PDSTHR */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_PDSTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_PDSTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_PDSTHR ((uint16)288)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_PDSTHR */

#ifdef FeeConf_FeeBlockConfiguration_FLDCOH_PDSTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FLDCOH_PDSTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_FLDCOH_PDSTHR ((uint16)290)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FLDCOH_PDSTHR */

#ifdef FeeConf_FeeBlockConfiguration_GRD_PDSTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GRD_PDSTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_GRD_PDSTHR ((uint16)292)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GRD_PDSTHR */

#ifdef FeeConf_FeeBlockConfiguration_MAX_PAIREXT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MAX_PAIREXT already defined
#else 
#define FeeConf_FeeBlockConfiguration_MAX_PAIREXT ((uint16)294)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MAX_PAIREXT */

#ifdef FeeConf_FeeBlockConfiguration_MIN_PAIREXT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MIN_PAIREXT already defined
#else 
#define FeeConf_FeeBlockConfiguration_MIN_PAIREXT ((uint16)296)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MIN_PAIREXT */

#ifdef FeeConf_FeeBlockConfiguration_GRD_PAIREXT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GRD_PAIREXT already defined
#else 
#define FeeConf_FeeBlockConfiguration_GRD_PAIREXT ((uint16)298)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GRD_PAIREXT */

#ifdef FeeConf_FeeBlockConfiguration_GRD_PAIREXTOLD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GRD_PAIREXTOLD already defined
#else 
#define FeeConf_FeeBlockConfiguration_GRD_PAIREXTOLD ((uint16)300)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GRD_PAIREXTOLD */

#ifdef FeeConf_FeeBlockConfiguration_COH_PBRKASI /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_PBRKASI already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_PBRKASI ((uint16)302)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_PBRKASI */

#ifdef FeeConf_FeeBlockConfiguration_SCP_PRELBRKASI /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_PRELBRKASI already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_PRELBRKASI ((uint16)304)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_PRELBRKASI */

#ifdef FeeConf_FeeBlockConfiguration_SCG_PRELBRKASI /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_PRELBRKASI already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_PRELBRKASI ((uint16)306)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_PRELBRKASI */

#ifdef FeeConf_FeeBlockConfiguration_GRD_PRELBRKASI /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GRD_PRELBRKASI already defined
#else 
#define FeeConf_FeeBlockConfiguration_GRD_PRELBRKASI ((uint16)308)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GRD_PRELBRKASI */

#ifdef FeeConf_FeeBlockConfiguration_BOOST1_PDSTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BOOST1_PDSTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_BOOST1_PDSTHR ((uint16)310)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BOOST1_PDSTHR */

#ifdef FeeConf_FeeBlockConfiguration_BOOST2_PDSTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BOOST2_PDSTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_BOOST2_PDSTHR ((uint16)312)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BOOST2_PDSTHR */

#ifdef FeeConf_FeeBlockConfiguration_BOOST3_PDSTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BOOST3_PDSTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_BOOST3_PDSTHR ((uint16)314)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BOOST3_PDSTHR */

#ifdef FeeConf_FeeBlockConfiguration_BOOST4_PDSTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BOOST4_PDSTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_BOOST4_PDSTHR ((uint16)316)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BOOST4_PDSTHR */

#ifdef FeeConf_FeeBlockConfiguration_OC_TAIRMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_TAIRMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_TAIRMES ((uint16)318)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_TAIRMES */

#ifdef FeeConf_FeeBlockConfiguration_SCG_TAIRMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_TAIRMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_TAIRMES ((uint16)320)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_TAIRMES */

#ifdef FeeConf_FeeBlockConfiguration_SCP_TAIRMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_TAIRMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_TAIRMES ((uint16)322)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_TAIRMES */

#ifdef FeeConf_FeeBlockConfiguration_GRD_TAIRMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GRD_TAIRMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_GRD_TAIRMES ((uint16)324)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GRD_TAIRMES */

#ifdef FeeConf_FeeBlockConfiguration_NEGOFS_TAIRMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_NEGOFS_TAIRMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_NEGOFS_TAIRMES ((uint16)326)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_NEGOFS_TAIRMES */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_TAIRMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_TAIRMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_TAIRMES ((uint16)328)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_TAIRMES */

#ifdef FeeConf_FeeBlockConfiguration_POSOFS_TAIRMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_POSOFS_TAIRMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_POSOFS_TAIRMES ((uint16)330)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_POSOFS_TAIRMES */

#ifdef FeeConf_FeeBlockConfiguration_STALLCOH_TAIRMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STALLCOH_TAIRMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_STALLCOH_TAIRMES ((uint16)332)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STALLCOH_TAIRMES */

#ifdef FeeConf_FeeBlockConfiguration_DECELCOH_BRKPED /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DECELCOH_BRKPED already defined
#else 
#define FeeConf_FeeBlockConfiguration_DECELCOH_BRKPED ((uint16)334)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DECELCOH_BRKPED */

#ifdef FeeConf_FeeBlockConfiguration_ACCELCOH_BRKPED /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ACCELCOH_BRKPED already defined
#else 
#define FeeConf_FeeBlockConfiguration_ACCELCOH_BRKPED ((uint16)336)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ACCELCOH_BRKPED */

#ifdef FeeConf_FeeBlockConfiguration_INVCOH_BRKPED /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVCOH_BRKPED already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVCOH_BRKPED ((uint16)338)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVCOH_BRKPED */

#ifdef FeeConf_FeeBlockConfiguration_DECELCOH_BRKPEDBVH2P /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DECELCOH_BRKPEDBVH2P already defined
#else 
#define FeeConf_FeeBlockConfiguration_DECELCOH_BRKPEDBVH2P ((uint16)340)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DECELCOH_BRKPEDBVH2P */

#ifdef FeeConf_FeeBlockConfiguration_ACCELCOH_BRKPEDBVH2P /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ACCELCOH_BRKPEDBVH2P already defined
#else 
#define FeeConf_FeeBlockConfiguration_ACCELCOH_BRKPEDBVH2P ((uint16)342)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ACCELCOH_BRKPEDBVH2P */

#ifdef FeeConf_FeeBlockConfiguration_COHBIT7_STDFTOBD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COHBIT7_STDFTOBD already defined
#else 
#define FeeConf_FeeBlockConfiguration_COHBIT7_STDFTOBD ((uint16)344)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COHBIT7_STDFTOBD */

#ifdef FeeConf_FeeBlockConfiguration_COHBIT4_STDFTOBD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COHBIT4_STDFTOBD already defined
#else 
#define FeeConf_FeeBlockConfiguration_COHBIT4_STDFTOBD ((uint16)346)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COHBIT4_STDFTOBD */

#ifdef FeeConf_FeeBlockConfiguration_COHBIT3_STDFTOBD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COHBIT3_STDFTOBD already defined
#else 
#define FeeConf_FeeBlockConfiguration_COHBIT3_STDFTOBD ((uint16)348)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COHBIT3_STDFTOBD */

#ifdef FeeConf_FeeBlockConfiguration_COHBIT2_STDFTOBD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COHBIT2_STDFTOBD already defined
#else 
#define FeeConf_FeeBlockConfiguration_COHBIT2_STDFTOBD ((uint16)350)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COHBIT2_STDFTOBD */

#ifdef FeeConf_FeeBlockConfiguration_CHKBATTSYS_IBATTMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CHKBATTSYS_IBATTMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_CHKBATTSYS_IBATTMES ((uint16)352)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CHKBATTSYS_IBATTMES */

#ifdef FeeConf_FeeBlockConfiguration_CHKBATTSYS_TBATTMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CHKBATTSYS_TBATTMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_CHKBATTSYS_TBATTMES ((uint16)354)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CHKBATTSYS_TBATTMES */

#ifdef FeeConf_FeeBlockConfiguration_CHKBATTSYS_UBATTCLC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CHKBATTSYS_UBATTCLC already defined
#else 
#define FeeConf_FeeBlockConfiguration_CHKBATTSYS_UBATTCLC ((uint16)356)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CHKBATTSYS_UBATTCLC */

#ifdef FeeConf_FeeBlockConfiguration_STFULVLDFT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STFULVLDFT already defined
#else 
#define FeeConf_FeeBlockConfiguration_STFULVLDFT ((uint16)358)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STFULVLDFT */

#ifdef FeeConf_FeeBlockConfiguration_COH_BMODSPTREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_BMODSPTREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_BMODSPTREQ ((uint16)360)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_BMODSPTREQ */

#ifdef FeeConf_FeeBlockConfiguration_COH_STCLUAC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_STCLUAC already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_STCLUAC ((uint16)362)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_STCLUAC */

#ifdef FeeConf_FeeBlockConfiguration_COH_STPWRAC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_STPWRAC already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_STPWRAC ((uint16)364)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_STPWRAC */

#ifdef FeeConf_FeeBlockConfiguration_SCP_UDSLS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_UDSLS already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_UDSLS ((uint16)366)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_UDSLS */

#ifdef FeeConf_FeeBlockConfiguration_OC_UDSLS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_UDSLS already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_UDSLS ((uint16)368)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_UDSLS */

#ifdef FeeConf_FeeBlockConfiguration_SCG_UDSLS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_UDSLS already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_UDSLS ((uint16)370)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_UDSLS */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_SIGGRDDIAG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_SIGGRDDIAG already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_SIGGRDDIAG ((uint16)372)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_SIGGRDDIAG */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_DSPLAUSFLD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_DSPLAUSFLD already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_DSPLAUSFLD ((uint16)374)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_DSPLAUSFLD */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_DSPLAUSFCO /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_DSPLAUSFCO already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_DSPLAUSFCO ((uint16)376)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_DSPLAUSFCO */

#ifdef FeeConf_FeeBlockConfiguration_OC_UUPLS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_UUPLS already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_UUPLS ((uint16)378)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_UUPLS */

#ifdef FeeConf_FeeBlockConfiguration_SCG_UUPLS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_UUPLS already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_UUPLS ((uint16)380)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_UUPLS */

#ifdef FeeConf_FeeBlockConfiguration_SCP_UUPLS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_UUPLS already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_UUPLS ((uint16)382)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_UUPLS */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_OXYSENSPERD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_OXYSENSPERD already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_OXYSENSPERD ((uint16)384)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_OXYSENSPERD */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_OXYAPVPERD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_OXYAPVPERD already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_OXYAPVPERD ((uint16)386)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_OXYAPVPERD */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_USPLAUSFLD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_USPLAUSFLD already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_USPLAUSFLD ((uint16)388)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_USPLAUSFLD */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_USPLAUSFCO /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_USPLAUSFCO already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_USPLAUSFCO ((uint16)390)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_USPLAUSFCO */

#ifdef FeeConf_FeeBlockConfiguration_COH_CLUST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_CLUST already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_CLUST ((uint16)392)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_CLUST */

#ifdef FeeConf_FeeBlockConfiguration_STUCK_CLUST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCK_CLUST already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCK_CLUST ((uint16)394)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCK_CLUST */

#ifdef FeeConf_FeeBlockConfiguration_SCP_RCLUPEDPRSSMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_RCLUPEDPRSSMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_RCLUPEDPRSSMES ((uint16)396)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_RCLUPEDPRSSMES */

#ifdef FeeConf_FeeBlockConfiguration_SCG_RCLUPEDPRSSMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_RCLUPEDPRSSMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_RCLUPEDPRSSMES ((uint16)398)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_RCLUPEDPRSSMES */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_RCLUPEDPRSSMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_RCLUPEDPRSSMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_RCLUPEDPRSSMES ((uint16)400)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_RCLUPEDPRSSMES */

#ifdef FeeConf_FeeBlockConfiguration_GRD_RCLUPEDPRSSMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GRD_RCLUPEDPRSSMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_GRD_RCLUPEDPRSSMES ((uint16)402)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GRD_RCLUPEDPRSSMES */

#ifdef FeeConf_FeeBlockConfiguration_FCTCLUP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FCTCLUP already defined
#else 
#define FeeConf_FeeBlockConfiguration_FCTCLUP ((uint16)404)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FCTCLUP */

#ifdef FeeConf_FeeBlockConfiguration_OC_DRVRFAN1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_DRVRFAN1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_DRVRFAN1 ((uint16)406)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_DRVRFAN1 */

#ifdef FeeConf_FeeBlockConfiguration_LO_DRVRFAN1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LO_DRVRFAN1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_LO_DRVRFAN1 ((uint16)408)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LO_DRVRFAN1 */

#ifdef FeeConf_FeeBlockConfiguration_HI_DRVRFAN1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HI_DRVRFAN1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_HI_DRVRFAN1 ((uint16)410)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HI_DRVRFAN1 */

#ifdef FeeConf_FeeBlockConfiguration_OC_DRVRFAN2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_DRVRFAN2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_DRVRFAN2 ((uint16)412)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_DRVRFAN2 */

#ifdef FeeConf_FeeBlockConfiguration_LO_DRVRFAN2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LO_DRVRFAN2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_LO_DRVRFAN2 ((uint16)414)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LO_DRVRFAN2 */

#ifdef FeeConf_FeeBlockConfiguration_HI_DRVRFAN2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HI_DRVRFAN2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_HI_DRVRFAN2 ((uint16)416)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HI_DRVRFAN2 */

#ifdef FeeConf_FeeBlockConfiguration_COH_STFANB1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_STFANB1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_STFANB1 ((uint16)418)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_STFANB1 */

#ifdef FeeConf_FeeBlockConfiguration_COH_STFANB2LOSPD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_STFANB2LOSPD already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_STFANB2LOSPD ((uint16)420)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_STFANB2LOSPD */

#ifdef FeeConf_FeeBlockConfiguration_COH_STFANB2HISPD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_STFANB2HISPD already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_STFANB2HISPD ((uint16)422)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_STFANB2HISPD */

#ifdef FeeConf_FeeBlockConfiguration_COH_STFANB2NOSPD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_STFANB2NOSPD already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_STFANB2NOSPD ((uint16)424)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_STFANB2NOSPD */

#ifdef FeeConf_FeeBlockConfiguration_CLSDRLY_STFANC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CLSDRLY_STFANC already defined
#else 
#define FeeConf_FeeBlockConfiguration_CLSDRLY_STFANC ((uint16)426)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CLSDRLY_STFANC */

#ifdef FeeConf_FeeBlockConfiguration_EL_STFANC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_EL_STFANC already defined
#else 
#define FeeConf_FeeBlockConfiguration_EL_STFANC ((uint16)428)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_EL_STFANC */

#ifdef FeeConf_FeeBlockConfiguration_UNVLD_STFANC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_UNVLD_STFANC already defined
#else 
#define FeeConf_FeeBlockConfiguration_UNVLD_STFANC ((uint16)430)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_UNVLD_STFANC */

#ifdef FeeConf_FeeBlockConfiguration_CRITSC_STFANC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CRITSC_STFANC already defined
#else 
#define FeeConf_FeeBlockConfiguration_CRITSC_STFANC ((uint16)432)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CRITSC_STFANC */

#ifdef FeeConf_FeeBlockConfiguration_ECI_STFANC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ECI_STFANC already defined
#else 
#define FeeConf_FeeBlockConfiguration_ECI_STFANC ((uint16)434)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ECI_STFANC */

#ifdef FeeConf_FeeBlockConfiguration_SCP_ECTREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_ECTREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_ECTREQ ((uint16)436)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_ECTREQ */

#ifdef FeeConf_FeeBlockConfiguration_SCG_ECTREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_ECTREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_ECTREQ ((uint16)438)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_ECTREQ */

#ifdef FeeConf_FeeBlockConfiguration_OC_ECTREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_ECTREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_ECTREQ ((uint16)440)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_ECTREQ */

#ifdef FeeConf_FeeBlockConfiguration_LINBLOCKEDBUS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LINBLOCKEDBUS already defined
#else 
#define FeeConf_FeeBlockConfiguration_LINBLOCKEDBUS ((uint16)442)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LINBLOCKEDBUS */

#ifdef FeeConf_FeeBlockConfiguration_ALTABSENTECU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ALTABSENTECU already defined
#else 
#define FeeConf_FeeBlockConfiguration_ALTABSENTECU ((uint16)444)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ALTABSENTECU */

#ifdef FeeConf_FeeBlockConfiguration_ETAT_ALT1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ETAT_ALT1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ETAT_ALT1 ((uint16)446)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ETAT_ALT1 */

#ifdef FeeConf_FeeBlockConfiguration_ETAT_ALT2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ETAT_ALT2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ETAT_ALT2 ((uint16)448)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ETAT_ALT2 */

#ifdef FeeConf_FeeBlockConfiguration_TRCK_TCOMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TRCK_TCOMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_TRCK_TCOMES ((uint16)450)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TRCK_TCOMES */

#ifdef FeeConf_FeeBlockConfiguration_WUP_TCOMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_WUP_TCOMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_WUP_TCOMES ((uint16)452)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_WUP_TCOMES */

#ifdef FeeConf_FeeBlockConfiguration_LOCSTRDRV /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LOCSTRDRV already defined
#else 
#define FeeConf_FeeBlockConfiguration_LOCSTRDRV ((uint16)454)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LOCSTRDRV */

#ifdef FeeConf_FeeBlockConfiguration_HICSTRDRV /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HICSTRDRV already defined
#else 
#define FeeConf_FeeBlockConfiguration_HICSTRDRV ((uint16)456)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HICSTRDRV */

#ifdef FeeConf_FeeBlockConfiguration_ELINFBSIDFT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELINFBSIDFT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELINFBSIDFT ((uint16)458)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELINFBSIDFT */

#ifdef FeeConf_FeeBlockConfiguration_ELCPTTRABSIDFT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELCPTTRABSIDFT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELCPTTRABSIDFT ((uint16)460)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELCPTTRABSIDFT */

#ifdef FeeConf_FeeBlockConfiguration_ELCHKCONSDFT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELCHKCONSDFT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELCHKCONSDFT ((uint16)462)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELCHKCONSDFT */

#ifdef FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSLIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSLIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSLIM ((uint16)464)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSLIM */

#ifdef FeeConf_FeeBlockConfiguration_ELCONSVARDFTVSLIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELCONSVARDFTVSLIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELCONSVARDFTVSLIM ((uint16)466)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELCONSVARDFTVSLIM */

#ifdef FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSREG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSREG already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSREG ((uint16)468)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSREG */

#ifdef FeeConf_FeeBlockConfiguration_ELCONSVARDFTVSREG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELCONSVARDFTVSREG already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELCONSVARDFTVSREG ((uint16)470)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELCONSVARDFTVSREG */

#ifdef FeeConf_FeeBlockConfiguration_ELCONSINITDFTVSREG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELCONSINITDFTVSREG already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELCONSINITDFTVSREG ((uint16)472)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELCONSINITDFTVSREG */

#ifdef FeeConf_FeeBlockConfiguration_ELDFTCRSCTL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELDFTCRSCTL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELDFTCRSCTL ((uint16)474)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELDFTCRSCTL */

#ifdef FeeConf_FeeBlockConfiguration_ZEROFRAMECNTDFT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ZEROFRAMECNTDFT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ZEROFRAMECNTDFT ((uint16)476)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ZEROFRAMECNTDFT */

#ifdef FeeConf_FeeBlockConfiguration_EVENFRAMECNTDFT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_EVENFRAMECNTDFT already defined
#else 
#define FeeConf_FeeBlockConfiguration_EVENFRAMECNTDFT ((uint16)478)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_EVENFRAMECNTDFT */

#ifdef FeeConf_FeeBlockConfiguration_ELFRAMECNTINCDFT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELFRAMECNTINCDFT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELFRAMECNTINCDFT ((uint16)480)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELFRAMECNTINCDFT */

#ifdef FeeConf_FeeBlockConfiguration_ELCONSCOHVSMAXP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELCONSCOHVSMAXP already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELCONSCOHVSMAXP ((uint16)482)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELCONSCOHVSMAXP */

#ifdef FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSMAXP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSMAXP already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSMAXP ((uint16)484)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELCONSDEFDFTVSMAXP */

#ifdef FeeConf_FeeBlockConfiguration_CRSCTLDFT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CRSCTLDFT already defined
#else 
#define FeeConf_FeeBlockConfiguration_CRSCTLDFT ((uint16)486)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CRSCTLDFT */

#ifdef FeeConf_FeeBlockConfiguration_F432LOST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_F432LOST already defined
#else 
#define FeeConf_FeeBlockConfiguration_F432LOST ((uint16)488)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_F432LOST */

#ifdef FeeConf_FeeBlockConfiguration_DFTEEPROM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTEEPROM already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTEEPROM ((uint16)490)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTEEPROM */

#ifdef FeeConf_FeeBlockConfiguration_FLASHCHK /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FLASHCHK already defined
#else 
#define FeeConf_FeeBlockConfiguration_FLASHCHK ((uint16)492)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FLASHCHK */

#ifdef FeeConf_FeeBlockConfiguration_SCP_BINHCRKALTHW /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_BINHCRKALTHW already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_BINHCRKALTHW ((uint16)494)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_BINHCRKALTHW */

#ifdef FeeConf_FeeBlockConfiguration_SCG_BINHCRKALTHW /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_BINHCRKALTHW already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_BINHCRKALTHW ((uint16)496)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_BINHCRKALTHW */

#ifdef FeeConf_FeeBlockConfiguration_SCP_UDFTSTACMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_UDFTSTACMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_UDFTSTACMD ((uint16)498)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_UDFTSTACMD */

#ifdef FeeConf_FeeBlockConfiguration_SCG_UDFTSTACMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_UDFTSTACMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_UDFTSTACMD ((uint16)500)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_UDFTSTACMD */

#ifdef FeeConf_FeeBlockConfiguration_INVLD_UDFTSTACMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLD_UDFTSTACMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLD_UDFTSTACMD ((uint16)502)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLD_UDFTSTACMD */

#ifdef FeeConf_FeeBlockConfiguration_SCP_ENGSTOUTIDC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_ENGSTOUTIDC already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_ENGSTOUTIDC ((uint16)504)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_ENGSTOUTIDC */

#ifdef FeeConf_FeeBlockConfiguration_SCG_ENGSTOUTIDC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_ENGSTOUTIDC already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_ENGSTOUTIDC ((uint16)506)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_ENGSTOUTIDC */

#ifdef FeeConf_FeeBlockConfiguration_OC_ENGSTOUTIDC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_ENGSTOUTIDC already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_ENGSTOUTIDC ((uint16)508)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_ENGSTOUTIDC */

#ifdef FeeConf_FeeBlockConfiguration_ORNGPFUENGST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGPFUENGST already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGPFUENGST ((uint16)510)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGPFUENGST */

#ifdef FeeConf_FeeBlockConfiguration_ORNGUNLOCKENGST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGUNLOCKENGST already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGUNLOCKENGST ((uint16)512)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGUNLOCKENGST */

#ifdef FeeConf_FeeBlockConfiguration_ORNGSYNCENGST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGSYNCENGST already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGSYNCENGST ((uint16)514)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGSYNCENGST */

#ifdef FeeConf_FeeBlockConfiguration_ORNGSTRTENGST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGSTRTENGST already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGSTRTENGST ((uint16)516)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGSTRTENGST */

#ifdef FeeConf_FeeBlockConfiguration_SCP_DML /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_DML already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_DML ((uint16)518)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_DML */

#ifdef FeeConf_FeeBlockConfiguration_OC_DML /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_DML already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_DML ((uint16)520)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_DML */

#ifdef FeeConf_FeeBlockConfiguration_SCG_DML /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_DML already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_DML ((uint16)522)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_DML */

#ifdef FeeConf_FeeBlockConfiguration_BLOCK_STRTR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BLOCK_STRTR already defined
#else 
#define FeeConf_FeeBlockConfiguration_BLOCK_STRTR ((uint16)524)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BLOCK_STRTR */

#ifdef FeeConf_FeeBlockConfiguration_REDESLIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_REDESLIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_REDESLIM ((uint16)526)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_REDESLIM */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_FUGAUGELVL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_FUGAUGELVL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_FUGAUGELVL ((uint16)528)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_FUGAUGELVL */

#ifdef FeeConf_FeeBlockConfiguration_LOFULVL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LOFULVL already defined
#else 
#define FeeConf_FeeBlockConfiguration_LOFULVL ((uint16)530)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LOFULVL */

#ifdef FeeConf_FeeBlockConfiguration_OC_FUGAUGE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_FUGAUGE already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_FUGAUGE ((uint16)532)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_FUGAUGE */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_FUGAUGE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_FUGAUGE already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_FUGAUGE ((uint16)534)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_FUGAUGE */

#ifdef FeeConf_FeeBlockConfiguration_SCG_FUGAUGE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_FUGAUGE already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_FUGAUGE ((uint16)536)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_FUGAUGE */

#ifdef FeeConf_FeeBlockConfiguration_SCG_PROPFUPMP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_PROPFUPMP already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_PROPFUPMP ((uint16)538)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_PROPFUPMP */

#ifdef FeeConf_FeeBlockConfiguration_SCP_PROPFUPMP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_PROPFUPMP already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_PROPFUPMP ((uint16)540)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_PROPFUPMP */

#ifdef FeeConf_FeeBlockConfiguration_OC_PROPFUPMP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_PROPFUPMP already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_PROPFUPMP ((uint16)542)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_PROPFUPMP */

#ifdef FeeConf_FeeBlockConfiguration_MAP_PROPFUPMP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MAP_PROPFUPMP already defined
#else 
#define FeeConf_FeeBlockConfiguration_MAP_PROPFUPMP ((uint16)544)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MAP_PROPFUPMP */

#ifdef FeeConf_FeeBlockConfiguration_GRAVSCP_PROPFUPMP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_GRAVSCP_PROPFUPMP already defined
#else 
#define FeeConf_FeeBlockConfiguration_GRAVSCP_PROPFUPMP ((uint16)546)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_GRAVSCP_PROPFUPMP */

#ifdef FeeConf_FeeBlockConfiguration_FRQ_PROPFUPMP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRQ_PROPFUPMP already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRQ_PROPFUPMP ((uint16)548)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRQ_PROPFUPMP */

#ifdef FeeConf_FeeBlockConfiguration_RVSGEAR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_RVSGEAR already defined
#else 
#define FeeConf_FeeBlockConfiguration_RVSGEAR ((uint16)550)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_RVSGEAR */

#ifdef FeeConf_FeeBlockConfiguration_SCP_BNEUT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_BNEUT already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_BNEUT ((uint16)552)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_BNEUT */

#ifdef FeeConf_FeeBlockConfiguration_SCG_BNEUT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_BNEUT already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_BNEUT ((uint16)554)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_BNEUT */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_BNEUT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_BNEUT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_BNEUT ((uint16)556)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_BNEUT */

#ifdef FeeConf_FeeBlockConfiguration_COH_STRTLOCK /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_STRTLOCK already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_STRTLOCK ((uint16)558)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_STRTLOCK */

#ifdef FeeConf_FeeBlockConfiguration_HI_DRVRSENO2DS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HI_DRVRSENO2DS already defined
#else 
#define FeeConf_FeeBlockConfiguration_HI_DRVRSENO2DS ((uint16)560)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HI_DRVRSENO2DS */

#ifdef FeeConf_FeeBlockConfiguration_LO_DRVRSENO2DS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LO_DRVRSENO2DS already defined
#else 
#define FeeConf_FeeBlockConfiguration_LO_DRVRSENO2DS ((uint16)562)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LO_DRVRSENO2DS */

#ifdef FeeConf_FeeBlockConfiguration_HI_DRVRSENO2US /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HI_DRVRSENO2US already defined
#else 
#define FeeConf_FeeBlockConfiguration_HI_DRVRSENO2US ((uint16)564)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HI_DRVRSENO2US */

#ifdef FeeConf_FeeBlockConfiguration_LO_DRVRSENO2US /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LO_DRVRSENO2US already defined
#else 
#define FeeConf_FeeBlockConfiguration_LO_DRVRSENO2US ((uint16)566)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LO_DRVRSENO2US */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_USHEAT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_USHEAT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_USHEAT ((uint16)568)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_USHEAT */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_DSHEAT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_DSHEAT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_DSHEAT ((uint16)570)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_DSHEAT */

#ifdef FeeConf_FeeBlockConfiguration_OC_IGCOIL1CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_IGCOIL1CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_IGCOIL1CMD ((uint16)572)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_IGCOIL1CMD */

#ifdef FeeConf_FeeBlockConfiguration_SCP_IGCOIL1CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_IGCOIL1CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_IGCOIL1CMD ((uint16)574)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_IGCOIL1CMD */

#ifdef FeeConf_FeeBlockConfiguration_OC_IGCOIL2CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_IGCOIL2CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_IGCOIL2CMD ((uint16)576)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_IGCOIL2CMD */

#ifdef FeeConf_FeeBlockConfiguration_SCP_IGCOIL2CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_IGCOIL2CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_IGCOIL2CMD ((uint16)578)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_IGCOIL2CMD */

#ifdef FeeConf_FeeBlockConfiguration_OC_IGCOIL3CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_IGCOIL3CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_IGCOIL3CMD ((uint16)580)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_IGCOIL3CMD */

#ifdef FeeConf_FeeBlockConfiguration_SCP_IGCOIL3CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_IGCOIL3CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_IGCOIL3CMD ((uint16)582)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_IGCOIL3CMD */

#ifdef FeeConf_FeeBlockConfiguration_OC_IGCOIL4CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_IGCOIL4CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_IGCOIL4CMD ((uint16)584)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_IGCOIL4CMD */

#ifdef FeeConf_FeeBlockConfiguration_SCP_IGCOIL4CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_IGCOIL4CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_IGCOIL4CMD ((uint16)586)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_IGCOIL4CMD */

#ifdef FeeConf_FeeBlockConfiguration_CMMABSENT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CMMABSENT already defined
#else 
#define FeeConf_FeeBlockConfiguration_CMMABSENT ((uint16)588)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CMMABSENT */

#ifdef FeeConf_FeeBlockConfiguration_CAPT_VOLABSENT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CAPT_VOLABSENT already defined
#else 
#define FeeConf_FeeBlockConfiguration_CAPT_VOLABSENT ((uint16)590)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CAPT_VOLABSENT */

#ifdef FeeConf_FeeBlockConfiguration_MISSF305 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF305 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF305 ((uint16)592)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF305 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF305 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF305 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF305 ((uint16)594)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF305 */

#ifdef FeeConf_FeeBlockConfiguration_CHKF305 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CHKF305 already defined
#else 
#define FeeConf_FeeBlockConfiguration_CHKF305 ((uint16)596)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CHKF305 */

#ifdef FeeConf_FeeBlockConfiguration_CNTF305 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CNTF305 already defined
#else 
#define FeeConf_FeeBlockConfiguration_CNTF305 ((uint16)598)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CNTF305 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF305P537 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF305P537 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF305P537 ((uint16)600)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF305P537 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF305P538 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF305P538 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF305P538 ((uint16)602)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF305P538 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF305P537 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF305P537 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF305P537 ((uint16)604)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF305P537 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF30D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF30D already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF30D ((uint16)606)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF30D */

#ifdef FeeConf_FeeBlockConfiguration_SHOF30D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF30D already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF30D ((uint16)608)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF30D */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF30DP263 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF30DP263 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF30DP263 ((uint16)610)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF30DP263 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF30DP264 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF30DP264 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF30DP264 ((uint16)612)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF30DP264 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF30DP265 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF30DP265 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF30DP265 ((uint16)614)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF30DP265 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF30DP266 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF30DP266 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF30DP266 ((uint16)616)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF30DP266 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF329 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF329 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF329 ((uint16)618)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF329 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF329 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF329 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF329 ((uint16)620)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF329 */

#ifdef FeeConf_FeeBlockConfiguration_CHKF329 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CHKF329 already defined
#else 
#define FeeConf_FeeBlockConfiguration_CHKF329 ((uint16)622)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CHKF329 */

#ifdef FeeConf_FeeBlockConfiguration_CNTF329 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CNTF329 already defined
#else 
#define FeeConf_FeeBlockConfiguration_CNTF329 ((uint16)624)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CNTF329 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF329P445 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF329P445 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF329P445 ((uint16)626)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF329P445 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF329P445 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF329P445 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF329P445 ((uint16)628)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF329P445 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF329P397 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF329P397 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF329P397 ((uint16)630)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF329P397 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF349 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF349 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF349 ((uint16)632)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF349 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF349 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF349 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF349 ((uint16)634)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF349 */

#ifdef FeeConf_FeeBlockConfiguration_CHKF349 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CHKF349 already defined
#else 
#define FeeConf_FeeBlockConfiguration_CHKF349 ((uint16)636)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CHKF349 */

#ifdef FeeConf_FeeBlockConfiguration_CNTF349 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CNTF349 already defined
#else 
#define FeeConf_FeeBlockConfiguration_CNTF349 ((uint16)638)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CNTF349 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF349P007 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF349P007 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF349P007 ((uint16)640)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF349P007 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF349P055 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF349P055 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF349P055 ((uint16)642)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF349P055 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF349P360 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF349P360 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF349P360 ((uint16)644)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF349P360 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF349P057 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF349P057 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF349P057 ((uint16)646)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF349P057 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF349P008 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF349P008 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF349P008 ((uint16)648)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF349P008 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF349P007 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF349P007 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF349P007 ((uint16)650)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF349P007 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF349P287 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF349P287 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF349P287 ((uint16)652)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF349P287 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF349PM1434 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF349PM1434 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF349PM1434 ((uint16)654)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF349PM1434 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF349P166 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF349P166 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF349P166 ((uint16)656)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF349P166 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF34D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF34D already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF34D ((uint16)658)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF34D */

#ifdef FeeConf_FeeBlockConfiguration_SHOF34D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF34D already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF34D ((uint16)660)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF34D */

#ifdef FeeConf_FeeBlockConfiguration_CNTF34D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CNTF34D already defined
#else 
#define FeeConf_FeeBlockConfiguration_CNTF34D ((uint16)662)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CNTF34D */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF34DFP0593 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF34DFP0593 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF34DFP0593 ((uint16)664)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF34DFP0593 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF34DPM1413 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF34DPM1413 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF34DPM1413 ((uint16)666)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF34DPM1413 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF34DP047 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF34DP047 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF34DP047 ((uint16)668)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF34DP047 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF34DP043 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF34DP043 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF34DP043 ((uint16)670)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF34DP043 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF34DP044 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF34DP044 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF34DP044 ((uint16)672)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF34DP044 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF34DP045 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF34DP045 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF34DP045 ((uint16)674)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF34DP045 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF34DFP0593 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF34DFP0593 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF34DFP0593 ((uint16)676)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF34DFP0593 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF34DPM1413 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF34DPM1413 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF34DPM1413 ((uint16)678)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF34DPM1413 */

#ifdef FeeConf_FeeBlockConfiguration_UC_FREINABSENT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_UC_FREINABSENT already defined
#else 
#define FeeConf_FeeBlockConfiguration_UC_FREINABSENT ((uint16)680)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_UC_FREINABSENT */

#ifdef FeeConf_FeeBlockConfiguration_MISSF38D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF38D already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF38D ((uint16)682)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF38D */

#ifdef FeeConf_FeeBlockConfiguration_SHOF38D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF38D already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF38D ((uint16)684)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF38D */

#ifdef FeeConf_FeeBlockConfiguration_CHKF38D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CHKF38D already defined
#else 
#define FeeConf_FeeBlockConfiguration_CHKF38D ((uint16)686)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CHKF38D */

#ifdef FeeConf_FeeBlockConfiguration_CNTF38D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CNTF38D already defined
#else 
#define FeeConf_FeeBlockConfiguration_CNTF38D ((uint16)688)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CNTF38D */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF38DP010 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF38DP010 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF38DP010 ((uint16)690)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF38DP010 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF38DP052 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF38DP052 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF38DP052 ((uint16)692)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF38DP052 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF3AD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF3AD already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF3AD ((uint16)694)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF3AD */

#ifdef FeeConf_FeeBlockConfiguration_SHOF3AD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF3AD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF3AD ((uint16)696)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF3AD */

#ifdef FeeConf_FeeBlockConfiguration_CHKF3AD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CHKF3AD already defined
#else 
#define FeeConf_FeeBlockConfiguration_CHKF3AD ((uint16)698)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CHKF3AD */

#ifdef FeeConf_FeeBlockConfiguration_CNTF3AD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CNTF3AD already defined
#else 
#define FeeConf_FeeBlockConfiguration_CNTF3AD ((uint16)700)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CNTF3AD */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF3ADP337 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF3ADP337 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF3ADP337 ((uint16)702)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF3ADP337 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF3C9 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF3C9 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF3C9 ((uint16)704)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF3C9 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF3C9 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF3C9 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF3C9 ((uint16)706)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF3C9 */

#ifdef FeeConf_FeeBlockConfiguration_CHKF3C9 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CHKF3C9 already defined
#else 
#define FeeConf_FeeBlockConfiguration_CHKF3C9 ((uint16)708)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CHKF3C9 */

#ifdef FeeConf_FeeBlockConfiguration_CNTF3C9 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CNTF3C9 already defined
#else 
#define FeeConf_FeeBlockConfiguration_CNTF3C9 ((uint16)710)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CNTF3C9 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF3C9P363 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF3C9P363 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF3C9P363 ((uint16)712)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF3C9P363 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF3C9P364 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF3C9P364 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF3C9P364 ((uint16)714)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF3C9P364 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF3C9P482 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF3C9P482 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF3C9P482 ((uint16)716)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF3C9P482 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF3C9P483 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF3C9P483 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF3C9P483 ((uint16)718)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF3C9P483 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF3C9P481 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF3C9P481 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF3C9P481 ((uint16)720)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF3C9P481 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF3C9P364 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF3C9P364 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF3C9P364 ((uint16)722)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF3C9P364 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF3C9P482 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF3C9P482 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF3C9P482 ((uint16)724)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF3C9P482 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF3C9P483 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF3C9P483 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF3C9P483 ((uint16)726)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF3C9P483 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF3CD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF3CD already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF3CD ((uint16)728)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF3CD */

#ifdef FeeConf_FeeBlockConfiguration_SHOF3CD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF3CD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF3CD ((uint16)730)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF3CD */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF3CDP225 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF3CDP225 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF3CDP225 ((uint16)732)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF3CDP225 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF3CDP515 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF3CDP515 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF3CDP515 ((uint16)734)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF3CDP515 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF3CDP319 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF3CDP319 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF3CDP319 ((uint16)736)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF3CDP319 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF3CDPM1387 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF3CDPM1387 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF3CDPM1387 ((uint16)738)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF3CDPM1387 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF3CDP319 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF3CDP319 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF3CDP319 ((uint16)740)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF3CDP319 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF412 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF412 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF412 ((uint16)742)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF412 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF412 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF412 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF412 ((uint16)744)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF412 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF412P040 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF412P040 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF412P040 ((uint16)746)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF412P040 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF432 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF432 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF432 ((uint16)748)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF432 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF432 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF432 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF432 ((uint16)750)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF432 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF432P214 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF432P214 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF432P214 ((uint16)752)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF432P214 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF432P249 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF432P249 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF432P249 ((uint16)754)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF432P249 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF432P251 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF432P251 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF432P251 ((uint16)756)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF432P251 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF432P402 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF432P402 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF432P402 ((uint16)758)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF432P402 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF432P368 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF432P368 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF432P368 ((uint16)760)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF432P368 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF432P369 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF432P369 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF432P369 ((uint16)762)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF432P369 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF432PM1424 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF432PM1424 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF432PM1424 ((uint16)764)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF432PM1424 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF44D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF44D already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF44D ((uint16)766)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF44D */

#ifdef FeeConf_FeeBlockConfiguration_SHOF44D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF44D already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF44D ((uint16)768)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF44D */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF44DFP0535 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF44DFP0535 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF44DFP0535 ((uint16)770)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF44DFP0535 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF44DP330 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF44DP330 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF44DP330 ((uint16)772)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF44DP330 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF44DP331 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF44DP331 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF44DP331 ((uint16)774)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF44DP331 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF44DP354 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF44DP354 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF44DP354 ((uint16)776)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF44DP354 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF44DP354 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF44DP354 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF44DP354 ((uint16)778)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF44DP354 */

#ifdef FeeConf_FeeBlockConfiguration_BVABSENT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BVABSENT already defined
#else 
#define FeeConf_FeeBlockConfiguration_BVABSENT ((uint16)780)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BVABSENT */

#ifdef FeeConf_FeeBlockConfiguration_MISSF489 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF489 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF489 ((uint16)782)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF489 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF489 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF489 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF489 ((uint16)784)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF489 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF489P102 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF489P102 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF489P102 ((uint16)786)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF489P102 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF489P254 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF489P254 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF489P254 ((uint16)788)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF489P254 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF489P218 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF489P218 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF489P218 ((uint16)790)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF489P218 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF489P254 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF489P254 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF489P254 ((uint16)792)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF489P254 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF489P218 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF489P218 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF489P218 ((uint16)794)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF489P218 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF492 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF492 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF492 ((uint16)796)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF492 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF492 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF492 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF492 ((uint16)798)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF492 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF495 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF495 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF495 ((uint16)800)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF495 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF495 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF495 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF495 ((uint16)802)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF495 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF4B2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF4B2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF4B2 ((uint16)804)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF4B2 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF4B2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF4B2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF4B2 ((uint16)806)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF4B2 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF4D2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF4D2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF4D2 ((uint16)808)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF4D2 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF4D2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF4D2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF4D2 ((uint16)810)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF4D2 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF4F2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF4F2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF4F2 ((uint16)812)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF4F2 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF4F2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF4F2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF4F2 ((uint16)814)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF4F2 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P434 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF4F2P434 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF4F2P434 ((uint16)816)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P434 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P438 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF4F2P438 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF4F2P438 ((uint16)818)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P438 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P429 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF4F2P429 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF4F2P429 ((uint16)820)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P429 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P437 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF4F2P437 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF4F2P437 ((uint16)822)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P437 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P490 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF4F2P490 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF4F2P490 ((uint16)824)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P490 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P491 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF4F2P491 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF4F2P491 ((uint16)826)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P491 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P492 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF4F2P492 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF4F2P492 ((uint16)828)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF4F2P492 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P434 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF4F2P434 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF4F2P434 ((uint16)830)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P434 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P438 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF4F2P438 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF4F2P438 ((uint16)832)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P438 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P437 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF4F2P437 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF4F2P437 ((uint16)834)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P437 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P490 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF4F2P490 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF4F2P490 ((uint16)836)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P490 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P493 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF4F2P493 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF4F2P493 ((uint16)838)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P493 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P491 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF4F2P491 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF4F2P491 ((uint16)840)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P491 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P494 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF4F2P494 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF4F2P494 ((uint16)842)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P494 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P492 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF4F2P492 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF4F2P492 ((uint16)844)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF4F2P492 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF50D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF50D already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF50D ((uint16)846)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF50D */

#ifdef FeeConf_FeeBlockConfiguration_SHOF50D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF50D already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF50D ((uint16)848)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF50D */

#ifdef FeeConf_FeeBlockConfiguration_CHKF50D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CHKF50D already defined
#else 
#define FeeConf_FeeBlockConfiguration_CHKF50D ((uint16)850)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CHKF50D */

#ifdef FeeConf_FeeBlockConfiguration_CNTF50D /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CNTF50D already defined
#else 
#define FeeConf_FeeBlockConfiguration_CNTF50D ((uint16)852)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CNTF50D */

#ifdef FeeConf_FeeBlockConfiguration_BSIABSENT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BSIABSENT already defined
#else 
#define FeeConf_FeeBlockConfiguration_BSIABSENT ((uint16)854)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BSIABSENT */

#ifdef FeeConf_FeeBlockConfiguration_MISSF50E /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF50E already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF50E ((uint16)856)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF50E */

#ifdef FeeConf_FeeBlockConfiguration_SHOF50E /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF50E already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF50E ((uint16)858)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF50E */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF50EPM1386 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF50EPM1386 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF50EPM1386 ((uint16)860)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF50EPM1386 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF50EP046 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF50EP046 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF50EP046 ((uint16)862)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF50EP046 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF50EP210 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF50EP210 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF50EP210 ((uint16)864)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF50EP210 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF50EP046 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF50EP046 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF50EP046 ((uint16)866)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF50EP046 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF50EP417 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF50EP417 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF50EP417 ((uint16)868)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF50EP417 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF50EP208 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF50EP208 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF50EP208 ((uint16)870)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF50EP208 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF532 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF532 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF532 ((uint16)872)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF532 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF532 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF532 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF532 ((uint16)874)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF532 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF532PM1414 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF532PM1414 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF532PM1414 ((uint16)876)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF532PM1414 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF532PM1415 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF532PM1415 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF532PM1415 ((uint16)878)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF532PM1415 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF532PM1416 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF532PM1416 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF532PM1416 ((uint16)880)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF532PM1416 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF532PM1414 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF532PM1414 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF532PM1414 ((uint16)882)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF532PM1414 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF532PM1415 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF532PM1415 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF532PM1415 ((uint16)884)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF532PM1415 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF532PM1416 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF532PM1416 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF532PM1416 ((uint16)886)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF532PM1416 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF552 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF552 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF552 ((uint16)888)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF552 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF552 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF552 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF552 ((uint16)890)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF552 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF552P255 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF552P255 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF552P255 ((uint16)892)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF552P255 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF552P256 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF552P256 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF552P256 ((uint16)894)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF552P256 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF552P257 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF552P257 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF552P257 ((uint16)896)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF552P257 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF552P325 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF552P325 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF552P325 ((uint16)898)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF552P325 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF552P015 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF552P015 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF552P015 ((uint16)900)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF552P015 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF552P326 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF552P326 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF552P326 ((uint16)902)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF552P326 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF552P255 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF552P255 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF552P255 ((uint16)904)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF552P255 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF552P256 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF552P256 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF552P256 ((uint16)906)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF552P256 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF552P257 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF552P257 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF552P257 ((uint16)908)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF552P257 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF572 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF572 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF572 ((uint16)910)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF572 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF572 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF572 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF572 ((uint16)912)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF572 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF572PM1360 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF572PM1360 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF572PM1360 ((uint16)914)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF572PM1360 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF572PM1360 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF572PM1360 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF572PM1360 ((uint16)916)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF572PM1360 */

#ifdef FeeConf_FeeBlockConfiguration_DMTRABSENT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DMTRABSENT already defined
#else 
#define FeeConf_FeeBlockConfiguration_DMTRABSENT ((uint16)918)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DMTRABSENT */

#ifdef FeeConf_FeeBlockConfiguration_MISSF57C /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF57C already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF57C ((uint16)920)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF57C */

#ifdef FeeConf_FeeBlockConfiguration_SHOF57C /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF57C already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF57C ((uint16)922)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF57C */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF57CPM1418 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF57CPM1418 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF57CPM1418 ((uint16)924)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF57CPM1418 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF592 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF592 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF592 ((uint16)926)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF592 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF592 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF592 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF592 ((uint16)928)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF592 */

#ifdef FeeConf_FeeBlockConfiguration_LIDF592 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LIDF592 already defined
#else 
#define FeeConf_FeeBlockConfiguration_LIDF592 ((uint16)930)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LIDF592 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF592P272 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF592P272 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF592P272 ((uint16)932)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF592P272 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF592P273 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF592P273 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF592P273 ((uint16)934)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF592P273 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF592P349 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF592P349 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF592P349 ((uint16)936)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF592P349 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF592P418 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF592P418 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF592P418 ((uint16)938)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF592P418 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF592P419 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF592P419 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF592P419 ((uint16)940)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF592P419 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF592P420 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF592P420 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF592P420 ((uint16)942)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF592P420 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF592P421_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF592P421_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF592P421_1 ((uint16)944)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF592P421_1 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF592P421_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF592P421_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF592P421_2 ((uint16)946)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF592P421_2 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF592P421_3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF592P421_3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF592P421_3 ((uint16)948)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF592P421_3 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF592P272 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF592P272 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF592P272 ((uint16)950)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF592P272 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF592P273 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF592P273 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF592P273 ((uint16)952)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF592P273 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF592P349 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF592P349 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF592P349 ((uint16)954)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF592P349 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF592P418 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF592P418 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF592P418 ((uint16)956)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF592P418 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF592P419 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF592P419 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF592P419 ((uint16)958)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF592P419 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF592P421_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF592P421_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF592P421_1 ((uint16)960)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF592P421_1 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF592P421_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF592P421_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF592P421_2 ((uint16)962)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF592P421_2 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF592P421_3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF592P421_3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF592P421_3 ((uint16)964)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF592P421_3 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF5B2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF5B2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF5B2 ((uint16)966)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF5B2 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF5B2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF5B2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF5B2 ((uint16)968)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF5B2 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF5B2P146 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF5B2P146 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF5B2P146 ((uint16)970)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF5B2P146 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF5B2P146 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF5B2P146 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF5B2P146 ((uint16)972)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF5B2P146 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF612 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF612 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF612 ((uint16)974)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF612 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF612 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF612 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF612 ((uint16)976)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF612 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF612P260 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF612P260 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF612P260 ((uint16)978)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF612P260 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF612P436 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF612P436 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF612P436 ((uint16)980)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF612P436 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF612P705 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF612P705 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF612P705 ((uint16)982)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF612P705 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF612P927 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF612P927 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF612P927 ((uint16)984)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF612P927 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF612P436 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF612P436 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF612P436 ((uint16)986)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF612P436 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF792 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF792 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF792 ((uint16)988)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF792 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF792 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF792 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF792 ((uint16)990)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF792 */

#ifdef FeeConf_FeeBlockConfiguration_MISSF7F2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSF7F2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSF7F2 ((uint16)992)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSF7F2 */

#ifdef FeeConf_FeeBlockConfiguration_SHOF7F2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SHOF7F2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SHOF7F2 ((uint16)994)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SHOF7F2 */

#ifdef FeeConf_FeeBlockConfiguration_LIDF7F2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LIDF7F2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_LIDF7F2 ((uint16)996)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LIDF7F2 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF7F2P146 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF7F2P146 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF7F2P146 ((uint16)998)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF7F2P146 */

#ifdef FeeConf_FeeBlockConfiguration_INVLDF7F2P015 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INVLDF7F2P015 already defined
#else 
#define FeeConf_FeeBlockConfiguration_INVLDF7F2P015 ((uint16)1000)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INVLDF7F2P015 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF7F2P849 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF7F2P849 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF7F2P849 ((uint16)1002)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF7F2P849 */

#ifdef FeeConf_FeeBlockConfiguration_FRBDF7F2P146 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FRBDF7F2P146 already defined
#else 
#define FeeConf_FeeBlockConfiguration_FRBDF7F2P146 ((uint16)1004)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FRBDF7F2P146 */

#ifdef FeeConf_FeeBlockConfiguration_SCP_INJ1CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_INJ1CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_INJ1CMD ((uint16)1006)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_INJ1CMD */

#ifdef FeeConf_FeeBlockConfiguration_OC_INJ1CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_INJ1CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_INJ1CMD ((uint16)1008)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_INJ1CMD */

#ifdef FeeConf_FeeBlockConfiguration_SCP_INJ2CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_INJ2CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_INJ2CMD ((uint16)1010)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_INJ2CMD */

#ifdef FeeConf_FeeBlockConfiguration_OC_INJ2CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_INJ2CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_INJ2CMD ((uint16)1012)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_INJ2CMD */

#ifdef FeeConf_FeeBlockConfiguration_SCP_INJ3CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_INJ3CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_INJ3CMD ((uint16)1014)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_INJ3CMD */

#ifdef FeeConf_FeeBlockConfiguration_OC_INJ3CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_INJ3CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_INJ3CMD ((uint16)1016)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_INJ3CMD */

#ifdef FeeConf_FeeBlockConfiguration_SCP_INJ4CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_INJ4CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_INJ4CMD ((uint16)1018)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_INJ4CMD */

#ifdef FeeConf_FeeBlockConfiguration_OC_INJ4CMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_INJ4CMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_INJ4CMD ((uint16)1020)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_INJ4CMD */

#ifdef FeeConf_FeeBlockConfiguration_ORNGLFBK_AFL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGLFBK_AFL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGLFBK_AFL ((uint16)1022)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGLFBK_AFL */

#ifdef FeeConf_FeeBlockConfiguration_DFTFU_AFL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTFU_AFL already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTFU_AFL ((uint16)1024)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTFU_AFL */

#ifdef FeeConf_FeeBlockConfiguration_DFTSENO2_AFL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTSENO2_AFL already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTSENO2_AFL ((uint16)1026)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTSENO2_AFL */

#ifdef FeeConf_FeeBlockConfiguration_ORNGLFBKGAS_AFL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGLFBKGAS_AFL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGLFBKGAS_AFL ((uint16)1028)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGLFBKGAS_AFL */

#ifdef FeeConf_FeeBlockConfiguration_DFTFUGAS_AFL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTFUGAS_AFL already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTFUGAS_AFL ((uint16)1030)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTFUGAS_AFL */

#ifdef FeeConf_FeeBlockConfiguration_DFTSENO2GAS_AFL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTSENO2GAS_AFL already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTSENO2GAS_AFL ((uint16)1032)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTSENO2GAS_AFL */

#ifdef FeeConf_FeeBlockConfiguration_ORNGLFBK_AFR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGLFBK_AFR already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGLFBK_AFR ((uint16)1034)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGLFBK_AFR */

#ifdef FeeConf_FeeBlockConfiguration_DFTFU_AFR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTFU_AFR already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTFU_AFR ((uint16)1036)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTFU_AFR */

#ifdef FeeConf_FeeBlockConfiguration_DFTSENO2_AFR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTSENO2_AFR already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTSENO2_AFR ((uint16)1038)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTSENO2_AFR */

#ifdef FeeConf_FeeBlockConfiguration_ORNGLFBKGAS_AFR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGLFBKGAS_AFR already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGLFBKGAS_AFR ((uint16)1040)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGLFBKGAS_AFR */

#ifdef FeeConf_FeeBlockConfiguration_DFTFUGAS_AFR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTFUGAS_AFR already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTFUGAS_AFR ((uint16)1042)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTFUGAS_AFR */

#ifdef FeeConf_FeeBlockConfiguration_DFTSENO2GAS_AFR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTSENO2GAS_AFR already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTSENO2GAS_AFR ((uint16)1044)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTSENO2GAS_AFR */

#ifdef FeeConf_FeeBlockConfiguration_HITALT_ALTCTL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HITALT_ALTCTL already defined
#else 
#define FeeConf_FeeBlockConfiguration_HITALT_ALTCTL ((uint16)1046)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HITALT_ALTCTL */

#ifdef FeeConf_FeeBlockConfiguration_MECAALT_ALTCTL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MECAALT_ALTCTL already defined
#else 
#define FeeConf_FeeBlockConfiguration_MECAALT_ALTCTL ((uint16)1048)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MECAALT_ALTCTL */

#ifdef FeeConf_FeeBlockConfiguration_ELECALT_ALTCTL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELECALT_ALTCTL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELECALT_ALTCTL ((uint16)1050)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELECALT_ALTCTL */

#ifdef FeeConf_FeeBlockConfiguration_COMALT_ALTCTL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COMALT_ALTCTL already defined
#else 
#define FeeConf_FeeBlockConfiguration_COMALT_ALTCTL ((uint16)1052)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COMALT_ALTCTL */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_KNKDIAG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_KNKDIAG already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_KNKDIAG ((uint16)1054)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_KNKDIAG */

#ifdef FeeConf_FeeBlockConfiguration_HHIT_NOISEADP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HHIT_NOISEADP already defined
#else 
#define FeeConf_FeeBlockConfiguration_HHIT_NOISEADP ((uint16)1056)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HHIT_NOISEADP */

#ifdef FeeConf_FeeBlockConfiguration_LHIT_NOISEADP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LHIT_NOISEADP already defined
#else 
#define FeeConf_FeeBlockConfiguration_LHIT_NOISEADP ((uint16)1058)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LHIT_NOISEADP */

#ifdef FeeConf_FeeBlockConfiguration_HSLD_NOISEADP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HSLD_NOISEADP already defined
#else 
#define FeeConf_FeeBlockConfiguration_HSLD_NOISEADP ((uint16)1060)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HSLD_NOISEADP */

#ifdef FeeConf_FeeBlockConfiguration_LSLD_NOISEADP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LSLD_NOISEADP already defined
#else 
#define FeeConf_FeeBlockConfiguration_LSLD_NOISEADP ((uint16)1062)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LSLD_NOISEADP */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_SHRTWINLRN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_SHRTWINLRN already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_SHRTWINLRN ((uint16)1064)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_SHRTWINLRN */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_LONGWINLRN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_LONGWINLRN already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_LONGWINLRN ((uint16)1066)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_LONGWINLRN */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_SHRTWINLRNMAX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_SHRTWINLRNMAX already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_SHRTWINLRNMAX ((uint16)1068)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_SHRTWINLRNMAX */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_LONGWINLRNMAX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_LONGWINLRNMAX already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_LONGWINLRNMAX ((uint16)1070)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_LONGWINLRNMAX */

#ifdef FeeConf_FeeBlockConfiguration_LOSTMISFROUGHNSROAD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LOSTMISFROUGHNSROAD already defined
#else 
#define FeeConf_FeeBlockConfiguration_LOSTMISFROUGHNSROAD ((uint16)1072)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LOSTMISFROUGHNSROAD */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMD1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATMD1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATMD1 ((uint16)1074)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMD1 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMD2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATMD2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATMD2 ((uint16)1076)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMD2 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMD3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATMD3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATMD3 ((uint16)1078)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMD3 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMD4 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATMD4 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATMD4 ((uint16)1080)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMD4 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDALL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATMDALL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATMDALL ((uint16)1082)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDALL */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC1 ((uint16)1084)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC1 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC2 ((uint16)1086)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC2 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC3 ((uint16)1088)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC3 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC4 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC4 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC4 ((uint16)1090)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTC4 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCALL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCALL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCALL ((uint16)1092)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCALL */

#ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMI1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGMISFEMI1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGMISFEMI1 ((uint16)1094)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMI1 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMI2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGMISFEMI2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGMISFEMI2 ((uint16)1096)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMI2 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMI3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGMISFEMI3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGMISFEMI3 ((uint16)1098)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMI3 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMI4 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGMISFEMI4 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGMISFEMI4 ((uint16)1100)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMI4 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIALL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGMISFEMIALL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGMISFEMIALL ((uint16)1102)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIALL */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ1 ((uint16)1104)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ1 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ2 ((uint16)1106)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ2 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ3 ((uint16)1108)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ3 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ4 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ4 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ4 ((uint16)1110)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZ4 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZALL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZALL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZALL ((uint16)1112)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATMDGAZALL */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ1 ((uint16)1114)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ1 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ2 ((uint16)1116)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ2 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ3 ((uint16)1118)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ3 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ4 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ4 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ4 ((uint16)1120)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZ4 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZALL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZALL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZALL ((uint16)1122)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGDMGCATDTCGAZALL */

#ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ1 ((uint16)1124)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ1 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ2 ((uint16)1126)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ2 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ3 ((uint16)1128)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ3 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ4 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ4 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ4 ((uint16)1130)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZ4 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZALL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZALL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZALL ((uint16)1132)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGMISFEMIGAZALL */

#ifdef FeeConf_FeeBlockConfiguration_DFTSENR_ACCP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTSENR_ACCP already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTSENR_ACCP ((uint16)1134)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTSENR_ACCP */

#ifdef FeeConf_FeeBlockConfiguration_OC_BINHCRKALTHW /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_BINHCRKALTHW already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_BINHCRKALTHW ((uint16)1136)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_BINHCRKALTHW */

#ifdef FeeConf_FeeBlockConfiguration_LO_UBATTSPC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LO_UBATTSPC already defined
#else 
#define FeeConf_FeeBlockConfiguration_LO_UBATTSPC ((uint16)1138)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LO_UBATTSPC */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES4 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_VMES4 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_VMES4 ((uint16)1140)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES4 */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES4_SFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_VMES4_SFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_VMES4_SFTY ((uint16)1142)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES4_SFTY */

#ifdef FeeConf_FeeBlockConfiguration_ALTABSENT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ALTABSENT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ALTABSENT ((uint16)1144)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ALTABSENT */

#ifdef FeeConf_FeeBlockConfiguration_BUSOFF /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BUSOFF already defined
#else 
#define FeeConf_FeeBlockConfiguration_BUSOFF ((uint16)1146)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BUSOFF */

#ifdef FeeConf_FeeBlockConfiguration_LINBLOCKED /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LINBLOCKED already defined
#else 
#define FeeConf_FeeBlockConfiguration_LINBLOCKED ((uint16)1148)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LINBLOCKED */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_CAT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_CAT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_CAT ((uint16)1150)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_CAT */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_CATAPV /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_CATAPV already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_CATAPV ((uint16)1152)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_CATAPV */

#ifdef FeeConf_FeeBlockConfiguration_ABSESPMUTE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ABSESPMUTE already defined
#else 
#define FeeConf_FeeBlockConfiguration_ABSESPMUTE ((uint16)1154)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ABSESPMUTE */

#ifdef FeeConf_FeeBlockConfiguration_BSIMUTE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BSIMUTE already defined
#else 
#define FeeConf_FeeBlockConfiguration_BSIMUTE ((uint16)1156)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BSIMUTE */

#ifdef FeeConf_FeeBlockConfiguration_BVAMUTE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BVAMUTE already defined
#else 
#define FeeConf_FeeBlockConfiguration_BVAMUTE ((uint16)1158)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BVAMUTE */

#ifdef FeeConf_FeeBlockConfiguration_ECMMUTE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ECMMUTE already defined
#else 
#define FeeConf_FeeBlockConfiguration_ECMMUTE ((uint16)1160)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ECMMUTE */

#ifdef FeeConf_FeeBlockConfiguration_DIRAMUTE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DIRAMUTE already defined
#else 
#define FeeConf_FeeBlockConfiguration_DIRAMUTE ((uint16)1162)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DIRAMUTE */

#ifdef FeeConf_FeeBlockConfiguration_CAVMUTE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CAVMUTE already defined
#else 
#define FeeConf_FeeBlockConfiguration_CAVMUTE ((uint16)1164)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CAVMUTE */

#ifdef FeeConf_FeeBlockConfiguration_DMTRMUTE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DMTRMUTE already defined
#else 
#define FeeConf_FeeBlockConfiguration_DMTRMUTE ((uint16)1166)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DMTRMUTE */

#ifdef FeeConf_FeeBlockConfiguration_F552BISP325INVLD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_F552BISP325INVLD already defined
#else 
#define FeeConf_FeeBlockConfiguration_F552BISP325INVLD ((uint16)1168)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_F552BISP325INVLD */

#ifdef FeeConf_FeeBlockConfiguration_F552P255INVLD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_F552P255INVLD already defined
#else 
#define FeeConf_FeeBlockConfiguration_F552P255INVLD ((uint16)1170)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_F552P255INVLD */

#ifdef FeeConf_FeeBlockConfiguration_F552P256INVLD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_F552P256INVLD already defined
#else 
#define FeeConf_FeeBlockConfiguration_F552P256INVLD ((uint16)1172)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_F552P256INVLD */

#ifdef FeeConf_FeeBlockConfiguration_F552P257INVLD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_F552P257INVLD already defined
#else 
#define FeeConf_FeeBlockConfiguration_F552P257INVLD ((uint16)1174)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_F552P257INVLD */

#ifdef FeeConf_FeeBlockConfiguration_HI_DMPVLVCMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HI_DMPVLVCMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_HI_DMPVLVCMD ((uint16)1176)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HI_DMPVLVCMD */

#ifdef FeeConf_FeeBlockConfiguration_LO_DMPVLVCMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LO_DMPVLVCMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_LO_DMPVLVCMD ((uint16)1178)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LO_DMPVLVCMD */

#ifdef FeeConf_FeeBlockConfiguration_HI_WGCCMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HI_WGCCMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_HI_WGCCMD ((uint16)1180)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HI_WGCCMD */

#ifdef FeeConf_FeeBlockConfiguration_LO_WGCCMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LO_WGCCMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_LO_WGCCMD ((uint16)1182)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LO_WGCCMD */

#ifdef FeeConf_FeeBlockConfiguration_OC_CTLPMPREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_CTLPMPREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_CTLPMPREQ ((uint16)1184)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_CTLPMPREQ */

#ifdef FeeConf_FeeBlockConfiguration_OC_CTP1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_CTP1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_CTP1 ((uint16)1186)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_CTP1 */

#ifdef FeeConf_FeeBlockConfiguration_OC_CTP2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_CTP2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_CTP2 ((uint16)1188)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_CTP2 */

#ifdef FeeConf_FeeBlockConfiguration_OC_TRBWAPMP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_TRBWAPMP already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_TRBWAPMP ((uint16)1190)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_TRBWAPMP */

#ifdef FeeConf_FeeBlockConfiguration_SCG_CTLPMPREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_CTLPMPREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_CTLPMPREQ ((uint16)1192)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_CTLPMPREQ */

#ifdef FeeConf_FeeBlockConfiguration_SCG_CTP1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_CTP1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_CTP1 ((uint16)1194)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_CTP1 */

#ifdef FeeConf_FeeBlockConfiguration_SCP_CTP1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_CTP1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_CTP1 ((uint16)1196)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_CTP1 */

#ifdef FeeConf_FeeBlockConfiguration_SCG_CTP2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_CTP2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_CTP2 ((uint16)1198)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_CTP2 */

#ifdef FeeConf_FeeBlockConfiguration_SCP_CTP2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_CTP2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_CTP2 ((uint16)1200)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_CTP2 */

#ifdef FeeConf_FeeBlockConfiguration_SCG_TRBWAPMP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_TRBWAPMP already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_TRBWAPMP ((uint16)1202)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_TRBWAPMP */

#ifdef FeeConf_FeeBlockConfiguration_SCP_CTLPMPREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_CTLPMPREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_CTLPMPREQ ((uint16)1204)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_CTLPMPREQ */

#ifdef FeeConf_FeeBlockConfiguration_SCP_TRBWAPMP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_TRBWAPMP already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_TRBWAPMP ((uint16)1206)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_TRBWAPMP */

#ifdef FeeConf_FeeBlockConfiguration_SCG_BLOWBY1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_BLOWBY1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_BLOWBY1 ((uint16)1208)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_BLOWBY1 */

#ifdef FeeConf_FeeBlockConfiguration_SCG_BLOWBY2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_BLOWBY2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_BLOWBY2 ((uint16)1210)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_BLOWBY2 */

#ifdef FeeConf_FeeBlockConfiguration_SCP_BLOWBY1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_BLOWBY1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_BLOWBY1 ((uint16)1212)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_BLOWBY1 */

#ifdef FeeConf_FeeBlockConfiguration_SCP_BLOWBY2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_BLOWBY2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_BLOWBY2 ((uint16)1214)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_BLOWBY2 */

#ifdef FeeConf_FeeBlockConfiguration_OC_BLOWBY1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_BLOWBY1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_BLOWBY1 ((uint16)1216)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_BLOWBY1 */

#ifdef FeeConf_FeeBlockConfiguration_OC_BLOWBY2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_BLOWBY2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_BLOWBY2 ((uint16)1218)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_BLOWBY2 */

#ifdef FeeConf_FeeBlockConfiguration_ORNGHITOILESTIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGHITOILESTIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGHITOILESTIM ((uint16)1220)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGHITOILESTIM */

#ifdef FeeConf_FeeBlockConfiguration_PWRLMRK /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PWRLMRK already defined
#else 
#define FeeConf_FeeBlockConfiguration_PWRLMRK ((uint16)1222)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PWRLMRK */

#ifdef FeeConf_FeeBlockConfiguration_SCP_VSSNWACVREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_VSSNWACVREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_VSSNWACVREQ ((uint16)1224)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_VSSNWACVREQ */

#ifdef FeeConf_FeeBlockConfiguration_SCG_VSSNWACVREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_VSSNWACVREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_VSSNWACVREQ ((uint16)1226)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_VSSNWACVREQ */

#ifdef FeeConf_FeeBlockConfiguration_HI_UBATTMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HI_UBATTMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_HI_UBATTMES ((uint16)1228)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HI_UBATTMES */

#ifdef FeeConf_FeeBlockConfiguration_LO_UBATTMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LO_UBATTMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_LO_UBATTMES ((uint16)1230)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LO_UBATTMES */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_VMES1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_VMES1 ((uint16)1232)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES1 */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES1_SFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_VMES1_SFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_VMES1_SFTY ((uint16)1234)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES1_SFTY */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_VMES2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_VMES2 ((uint16)1236)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES2 */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES2_SFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_VMES2_SFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_VMES2_SFTY ((uint16)1238)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES2_SFTY */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_VMES3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_VMES3 ((uint16)1240)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES3 */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES3_SFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_VMES3_SFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_VMES3_SFTY ((uint16)1242)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_VMES3_SFTY */

#ifdef FeeConf_FeeBlockConfiguration_INV_CALID /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INV_CALID already defined
#else 
#define FeeConf_FeeBlockConfiguration_INV_CALID ((uint16)1244)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INV_CALID */

#ifdef FeeConf_FeeBlockConfiguration_STUCK_MAINRLY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCK_MAINRLY already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCK_MAINRLY ((uint16)1246)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCK_MAINRLY */

#ifdef FeeConf_FeeBlockConfiguration_STUCK_PWRRLY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCK_PWRRLY already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCK_PWRRLY ((uint16)1248)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCK_PWRRLY */

#ifdef FeeConf_FeeBlockConfiguration_SCP_PWRRLY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCP_PWRRLY already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCP_PWRRLY ((uint16)1250)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCP_PWRRLY */

#ifdef FeeConf_FeeBlockConfiguration_OC_PWRRLY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OC_PWRRLY already defined
#else 
#define FeeConf_FeeBlockConfiguration_OC_PWRRLY ((uint16)1252)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OC_PWRRLY */

#ifdef FeeConf_FeeBlockConfiguration_SCG_PWRRLY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCG_PWRRLY already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCG_PWRRLY ((uint16)1254)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCG_PWRRLY */

#ifdef FeeConf_FeeBlockConfiguration_DFT_INFO_CRASH /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFT_INFO_CRASH already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFT_INFO_CRASH ((uint16)1256)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFT_INFO_CRASH */

#ifdef FeeConf_FeeBlockConfiguration_AFA_ADPAREFFEGRVLVLIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFA_ADPAREFFEGRVLVLIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFA_ADPAREFFEGRVLVLIM ((uint16)1258)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFA_ADPAREFFEGRVLVLIM */

#ifdef FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS1LIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS1LIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS1LIM ((uint16)1260)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS1LIM */

#ifdef FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS2LIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS2LIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS2LIM ((uint16)1262)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS2LIM */

#ifdef FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS3LIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS3LIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS3LIM ((uint16)1264)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFS3LIM */

#ifdef FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFSLIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFSLIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFSLIM ((uint16)1266)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFA_ADPAREFFTHROFSLIM */

#ifdef FeeConf_FeeBlockConfiguration_AFA_ADPCLSEXOFSLIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFA_ADPCLSEXOFSLIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFA_ADPCLSEXOFSLIM ((uint16)1268)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFA_ADPCLSEXOFSLIM */

#ifdef FeeConf_FeeBlockConfiguration_AFA_ADPINJOFSLIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFA_ADPINJOFSLIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFA_ADPINJOFSLIM ((uint16)1270)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFA_ADPINJOFSLIM */

#ifdef FeeConf_FeeBlockConfiguration_AFA_ADPIVSINJCONLIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFA_ADPIVSINJCONLIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFA_ADPIVSINJCONLIM ((uint16)1272)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFA_ADPIVSINJCONLIM */

#ifdef FeeConf_FeeBlockConfiguration_AFA_ADPOPINOFSLIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFA_ADPOPINOFSLIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFA_ADPOPINOFSLIM ((uint16)1274)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFA_ADPOPINOFSLIM */

#ifdef FeeConf_FeeBlockConfiguration_AFA_ADPSLOPINJCONLIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_AFA_ADPSLOPINJCONLIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_AFA_ADPSLOPINJCONLIM ((uint16)1276)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_AFA_ADPSLOPINJCONLIM */

#ifdef FeeConf_FeeBlockConfiguration_ANTIBOIL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ANTIBOIL already defined
#else 
#define FeeConf_FeeBlockConfiguration_ANTIBOIL ((uint16)1278)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ANTIBOIL */

#ifdef FeeConf_FeeBlockConfiguration_BLT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BLT already defined
#else 
#define FeeConf_FeeBlockConfiguration_BLT ((uint16)1280)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BLT */

#ifdef FeeConf_FeeBlockConfiguration_CAT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CAT already defined
#else 
#define FeeConf_FeeBlockConfiguration_CAT ((uint16)1282)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CAT */

#ifdef FeeConf_FeeBlockConfiguration_CATAPV /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CATAPV already defined
#else 
#define FeeConf_FeeBlockConfiguration_CATAPV ((uint16)1284)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CATAPV */

#ifdef FeeConf_FeeBlockConfiguration_CKSIG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CKSIG already defined
#else 
#define FeeConf_FeeBlockConfiguration_CKSIG ((uint16)1286)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CKSIG */

#ifdef FeeConf_FeeBlockConfiguration_COSYSDFCT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COSYSDFCT already defined
#else 
#define FeeConf_FeeBlockConfiguration_COSYSDFCT ((uint16)1288)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COSYSDFCT */

#ifdef FeeConf_FeeBlockConfiguration_CORLOSS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CORLOSS already defined
#else 
#define FeeConf_FeeBlockConfiguration_CORLOSS ((uint16)1290)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CORLOSS */

#ifdef FeeConf_FeeBlockConfiguration_CORSPCUR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CORSPCUR already defined
#else 
#define FeeConf_FeeBlockConfiguration_CORSPCUR ((uint16)1292)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CORSPCUR */

#ifdef FeeConf_FeeBlockConfiguration_CUTREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CUTREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_CUTREQ ((uint16)1294)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CUTREQ */

#ifdef FeeConf_FeeBlockConfiguration_FSFBLOCKCLS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FSFBLOCKCLS already defined
#else 
#define FeeConf_FeeBlockConfiguration_FSFBLOCKCLS ((uint16)1296)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FSFBLOCKCLS */

#ifdef FeeConf_FeeBlockConfiguration_FSFBLOCKOP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_FSFBLOCKOP already defined
#else 
#define FeeConf_FeeBlockConfiguration_FSFBLOCKOP ((uint16)1298)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FSFBLOCKOP */

#ifdef FeeConf_FeeBlockConfiguration_IRVENGSTOP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IRVENGSTOP already defined
#else 
#define FeeConf_FeeBlockConfiguration_IRVENGSTOP ((uint16)1300)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IRVENGSTOP */

#ifdef FeeConf_FeeBlockConfiguration_LGENGRSTRTINH /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LGENGRSTRTINH already defined
#else 
#define FeeConf_FeeBlockConfiguration_LGENGRSTRTINH ((uint16)1302)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LGENGRSTRTINH */

#ifdef FeeConf_FeeBlockConfiguration_MAINWKUDISRD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MAINWKUDISRD already defined
#else 
#define FeeConf_FeeBlockConfiguration_MAINWKUDISRD ((uint16)1304)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MAINWKUDISRD */

#ifdef FeeConf_FeeBlockConfiguration_MAINWKUINCST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MAINWKUINCST already defined
#else 
#define FeeConf_FeeBlockConfiguration_MAINWKUINCST ((uint16)1306)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MAINWKUINCST */

#ifdef FeeConf_FeeBlockConfiguration_ORNGCUTOFFREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGCUTOFFREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGCUTOFFREQ ((uint16)1308)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGCUTOFFREQ */

#ifdef FeeConf_FeeBlockConfiguration_ORNGGCCLU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGGCCLU already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGGCCLU ((uint16)1310)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGGCCLU */

#ifdef FeeConf_FeeBlockConfiguration_ORNGGCMINCLU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGGCMINCLU already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGGCMINCLU ((uint16)1312)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGGCMINCLU */

#ifdef FeeConf_FeeBlockConfiguration_ORNGGCNEUT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGGCNEUT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGGCNEUT ((uint16)1314)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGGCNEUT */

#ifdef FeeConf_FeeBlockConfiguration_ORNGGEARENACLU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGGEARENACLU already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGGEARENACLU ((uint16)1316)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGGEARENACLU */

#ifdef FeeConf_FeeBlockConfiguration_ORNGGEARMINCLU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGGEARMINCLU already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGGEARMINCLU ((uint16)1318)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGGEARMINCLU */

#ifdef FeeConf_FeeBlockConfiguration_ORNGGEARNEUT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGGEARNEUT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGGEARNEUT ((uint16)1320)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGGEARNEUT */

#ifdef FeeConf_FeeBlockConfiguration_ORNGHIDRAGRED /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGHIDRAGRED already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGHIDRAGRED ((uint16)1322)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGHIDRAGRED */

#ifdef FeeConf_FeeBlockConfiguration_ORNGHINEUT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGHINEUT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGHINEUT ((uint16)1324)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGHINEUT */

#ifdef FeeConf_FeeBlockConfiguration_ORNGLODRAGRED /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGLODRAGRED already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGLODRAGRED ((uint16)1326)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGLODRAGRED */

#ifdef FeeConf_FeeBlockConfiguration_ORNGLONEUT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGLONEUT already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGLONEUT ((uint16)1328)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGLONEUT */

#ifdef FeeConf_FeeBlockConfiguration_ORNGMPLREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGMPLREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGMPLREQ ((uint16)1330)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGMPLREQ */

#ifdef FeeConf_FeeBlockConfiguration_ORNGSTOPREQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGSTOPREQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGSTOPREQ ((uint16)1332)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGSTOPREQ */

#ifdef FeeConf_FeeBlockConfiguration_OBSADP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OBSADP already defined
#else 
#define FeeConf_FeeBlockConfiguration_OBSADP ((uint16)1334)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OBSADP */

#ifdef FeeConf_FeeBlockConfiguration_PROTADP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PROTADP already defined
#else 
#define FeeConf_FeeBlockConfiguration_PROTADP ((uint16)1336)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PROTADP */

#ifdef FeeConf_FeeBlockConfiguration_RCDLINESCG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_RCDLINESCG already defined
#else 
#define FeeConf_FeeBlockConfiguration_RCDLINESCG ((uint16)1338)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_RCDLINESCG */

#ifdef FeeConf_FeeBlockConfiguration_RATCONVTRACLC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_RATCONVTRACLC already defined
#else 
#define FeeConf_FeeBlockConfiguration_RATCONVTRACLC ((uint16)1340)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_RATCONVTRACLC */

#ifdef FeeConf_FeeBlockConfiguration_SFTYORNGAMT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SFTYORNGAMT already defined
#else 
#define FeeConf_FeeBlockConfiguration_SFTYORNGAMT ((uint16)1342)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SFTYORNGAMT */

#ifdef FeeConf_FeeBlockConfiguration_SFTYORNGAT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SFTYORNGAT already defined
#else 
#define FeeConf_FeeBlockConfiguration_SFTYORNGAT ((uint16)1344)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SFTYORNGAT */

#ifdef FeeConf_FeeBlockConfiguration_SPDVEHCLC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SPDVEHCLC already defined
#else 
#define FeeConf_FeeBlockConfiguration_SPDVEHCLC ((uint16)1346)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SPDVEHCLC */

#ifdef FeeConf_FeeBlockConfiguration_STAACVTHD1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STAACVTHD1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_STAACVTHD1 ((uint16)1348)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STAACVTHD1 */

#ifdef FeeConf_FeeBlockConfiguration_STAACVTHD2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STAACVTHD2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_STAACVTHD2 ((uint16)1350)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STAACVTHD2 */

#ifdef FeeConf_FeeBlockConfiguration_STACMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STACMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_STACMD ((uint16)1352)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STACMD */

#ifdef FeeConf_FeeBlockConfiguration_STACMDINFO /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STACMDINFO already defined
#else 
#define FeeConf_FeeBlockConfiguration_STACMDINFO ((uint16)1354)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STACMDINFO */

#ifdef FeeConf_FeeBlockConfiguration_STAELCMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STAELCMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_STAELCMD ((uint16)1356)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STAELCMD */

#ifdef FeeConf_FeeBlockConfiguration_STUCKMEC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCKMEC already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCKMEC ((uint16)1358)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCKMEC */

#ifdef FeeConf_FeeBlockConfiguration_TCOBLOCK /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TCOBLOCK already defined
#else 
#define FeeConf_FeeBlockConfiguration_TCOBLOCK ((uint16)1360)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TCOBLOCK */

#ifdef FeeConf_FeeBlockConfiguration_TCOOVERESTIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TCOOVERESTIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_TCOOVERESTIM ((uint16)1362)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TCOOVERESTIM */

#ifdef FeeConf_FeeBlockConfiguration_TCOSLOWRISE /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TCOSLOWRISE already defined
#else 
#define FeeConf_FeeBlockConfiguration_TCOSLOWRISE ((uint16)1364)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TCOSLOWRISE */

#ifdef FeeConf_FeeBlockConfiguration_TCOUNDESTIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TCOUNDESTIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_TCOUNDESTIM ((uint16)1366)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TCOUNDESTIM */

#ifdef FeeConf_FeeBlockConfiguration_TCOWARN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TCOWARN already defined
#else 
#define FeeConf_FeeBlockConfiguration_TCOWARN ((uint16)1368)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TCOWARN */

#ifdef FeeConf_FeeBlockConfiguration_THERMOSTUCKCLS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_THERMOSTUCKCLS already defined
#else 
#define FeeConf_FeeBlockConfiguration_THERMOSTUCKCLS ((uint16)1370)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_THERMOSTUCKCLS */

#ifdef FeeConf_FeeBlockConfiguration_THERMOSTUCKOP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_THERMOSTUCKOP already defined
#else 
#define FeeConf_FeeBlockConfiguration_THERMOSTUCKOP ((uint16)1372)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_THERMOSTUCKOP */

#ifdef FeeConf_FeeBlockConfiguration_TQALT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TQALT already defined
#else 
#define FeeConf_FeeBlockConfiguration_TQALT ((uint16)1374)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TQALT */

#ifdef FeeConf_FeeBlockConfiguration_VSLIM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_VSLIM already defined
#else 
#define FeeConf_FeeBlockConfiguration_VSLIM ((uint16)1376)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_VSLIM */

#ifdef FeeConf_FeeBlockConfiguration_VSLIMBODY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_VSLIMBODY already defined
#else 
#define FeeConf_FeeBlockConfiguration_VSLIMBODY ((uint16)1378)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_VSLIMBODY */

#ifdef FeeConf_FeeBlockConfiguration_VSMAX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_VSMAX already defined
#else 
#define FeeConf_FeeBlockConfiguration_VSMAX ((uint16)1380)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_VSMAX */

#ifdef FeeConf_FeeBlockConfiguration_VSMAXP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_VSMAXP already defined
#else 
#define FeeConf_FeeBlockConfiguration_VSMAXP ((uint16)1382)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_VSMAXP */

#ifdef FeeConf_FeeBlockConfiguration_VSREG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_VSREG already defined
#else 
#define FeeConf_FeeBlockConfiguration_VSREG ((uint16)1384)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_VSREG */

#ifdef FeeConf_FeeBlockConfiguration_VSREGBODY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_VSREGBODY already defined
#else 
#define FeeConf_FeeBlockConfiguration_VSREGBODY ((uint16)1386)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_VSREGBODY */

#ifdef FeeConf_FeeBlockConfiguration_VSREGVEH /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_VSREGVEH already defined
#else 
#define FeeConf_FeeBlockConfiguration_VSREGVEH ((uint16)1388)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_VSREGVEH */

#ifdef FeeConf_FeeBlockConfiguration_IBATTMAXCKG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IBATTMAXCKG already defined
#else 
#define FeeConf_FeeBlockConfiguration_IBATTMAXCKG ((uint16)1390)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IBATTMAXCKG */

#ifdef FeeConf_FeeBlockConfiguration_IBATTMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IBATTMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_IBATTMES ((uint16)1392)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IBATTMES */

#ifdef FeeConf_FeeBlockConfiguration_RBATTSOC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_RBATTSOC already defined
#else 
#define FeeConf_FeeBlockConfiguration_RBATTSOC ((uint16)1394)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_RBATTSOC */

#ifdef FeeConf_FeeBlockConfiguration_RESBATTIT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_RESBATTIT already defined
#else 
#define FeeConf_FeeBlockConfiguration_RESBATTIT ((uint16)1396)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_RESBATTIT */

#ifdef FeeConf_FeeBlockConfiguration_TBATTMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TBATTMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_TBATTMES ((uint16)1398)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TBATTMES */

#ifdef FeeConf_FeeBlockConfiguration_TQALTRV /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TQALTRV already defined
#else 
#define FeeConf_FeeBlockConfiguration_TQALTRV ((uint16)1400)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TQALTRV */

#ifdef FeeConf_FeeBlockConfiguration_UBATTMES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_UBATTMES already defined
#else 
#define FeeConf_FeeBlockConfiguration_UBATTMES ((uint16)1402)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_UBATTMES */

#ifdef FeeConf_FeeBlockConfiguration_UBATTMINCKG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_UBATTMINCKG already defined
#else 
#define FeeConf_FeeBlockConfiguration_UBATTMINCKG ((uint16)1404)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_UBATTMINCKG */

#ifdef FeeConf_FeeBlockConfiguration_UBATTOC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_UBATTOC already defined
#else 
#define FeeConf_FeeBlockConfiguration_UBATTOC ((uint16)1406)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_UBATTOC */

#ifdef FeeConf_FeeBlockConfiguration_UBATTRSTRT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_UBATTRSTRT already defined
#else 
#define FeeConf_FeeBlockConfiguration_UBATTRSTRT ((uint16)1408)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_UBATTRSTRT */

#ifdef FeeConf_FeeBlockConfiguration_UBATTSTRT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_UBATTSTRT already defined
#else 
#define FeeConf_FeeBlockConfiguration_UBATTSTRT ((uint16)1410)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_UBATTSTRT */

#ifdef FeeConf_FeeBlockConfiguration_NOANSWCTLUNIT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_NOANSWCTLUNIT already defined
#else 
#define FeeConf_FeeBlockConfiguration_NOANSWCTLUNIT ((uint16)1412)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_NOANSWCTLUNIT */

#ifdef FeeConf_FeeBlockConfiguration_WRGANSWCTLUNIT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_WRGANSWCTLUNIT already defined
#else 
#define FeeConf_FeeBlockConfiguration_WRGANSWCTLUNIT ((uint16)1414)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_WRGANSWCTLUNIT */

#ifdef FeeConf_FeeBlockConfiguration_IMMOCODNOTREAD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IMMOCODNOTREAD already defined
#else 
#define FeeConf_FeeBlockConfiguration_IMMOCODNOTREAD ((uint16)1416)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IMMOCODNOTREAD */

#ifdef FeeConf_FeeBlockConfiguration_NOGAP_CKSTS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_NOGAP_CKSTS already defined
#else 
#define FeeConf_FeeBlockConfiguration_NOGAP_CKSTS ((uint16)1418)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_NOGAP_CKSTS */

#ifdef FeeConf_FeeBlockConfiguration_TOOTHCOH_CKSTS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TOOTHCOH_CKSTS already defined
#else 
#define FeeConf_FeeBlockConfiguration_TOOTHCOH_CKSTS ((uint16)1420)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TOOTHCOH_CKSTS */

#ifdef FeeConf_FeeBlockConfiguration_HITOOTHCOH_CKSTS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HITOOTHCOH_CKSTS already defined
#else 
#define FeeConf_FeeBlockConfiguration_HITOOTHCOH_CKSTS ((uint16)1422)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HITOOTHCOH_CKSTS */

#ifdef FeeConf_FeeBlockConfiguration_IUPRSYNT1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IUPRSYNT1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_IUPRSYNT1 ((uint16)1424)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IUPRSYNT1 */

#ifdef FeeConf_FeeBlockConfiguration_IUPRSYNT2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IUPRSYNT2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_IUPRSYNT2 ((uint16)1426)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IUPRSYNT2 */

#ifdef FeeConf_FeeBlockConfiguration_IUPRSYNT3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IUPRSYNT3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_IUPRSYNT3 ((uint16)1428)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IUPRSYNT3 */

#ifdef FeeConf_FeeBlockConfiguration_SFTYCHKPT_PFCMNG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SFTYCHKPT_PFCMNG already defined
#else 
#define FeeConf_FeeBlockConfiguration_SFTYCHKPT_PFCMNG ((uint16)1430)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SFTYCHKPT_PFCMNG */

#ifdef FeeConf_FeeBlockConfiguration_IRVSTT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IRVSTT already defined
#else 
#define FeeConf_FeeBlockConfiguration_IRVSTT ((uint16)1432)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IRVSTT */

#ifdef FeeConf_FeeBlockConfiguration_RVLIH /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_RVLIH already defined
#else 
#define FeeConf_FeeBlockConfiguration_RVLIH ((uint16)1434)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_RVLIH */

#ifdef FeeConf_FeeBlockConfiguration_IRVVSCTL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IRVVSCTL already defined
#else 
#define FeeConf_FeeBlockConfiguration_IRVVSCTL ((uint16)1436)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IRVVSCTL */

#ifdef FeeConf_FeeBlockConfiguration_INHCHKINITSFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INHCHKINITSFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_INHCHKINITSFTY ((uint16)1438)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INHCHKINITSFTY */

#ifdef FeeConf_FeeBlockConfiguration_DRVTRA /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DRVTRA already defined
#else 
#define FeeConf_FeeBlockConfiguration_DRVTRA ((uint16)1440)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DRVTRA */

#ifdef FeeConf_FeeBlockConfiguration_INHENGSTOPSTT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INHENGSTOPSTT already defined
#else 
#define FeeConf_FeeBlockConfiguration_INHENGSTOPSTT ((uint16)1442)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INHENGSTOPSTT */

#ifdef FeeConf_FeeBlockConfiguration_IRVECU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IRVECU already defined
#else 
#define FeeConf_FeeBlockConfiguration_IRVECU ((uint16)1444)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IRVECU */

#ifdef FeeConf_FeeBlockConfiguration_IRVEM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IRVEM already defined
#else 
#define FeeConf_FeeBlockConfiguration_IRVEM ((uint16)1446)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IRVEM */

#ifdef FeeConf_FeeBlockConfiguration_COMSPI_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COMSPI_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_COMSPI_CPU ((uint16)1448)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COMSPI_CPU */

#ifdef FeeConf_FeeBlockConfiguration_COMTOUT_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COMTOUT_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_COMTOUT_CPU ((uint16)1450)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COMTOUT_CPU */

#ifdef FeeConf_FeeBlockConfiguration_SYNCMON_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SYNCMON_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_SYNCMON_CPU ((uint16)1452)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SYNCMON_CPU */

#ifdef FeeConf_FeeBlockConfiguration_ACCP_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ACCP_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_ACCP_CPU ((uint16)1454)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ACCP_CPU */

#ifdef FeeConf_FeeBlockConfiguration_THR_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_THR_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_THR_CPU ((uint16)1456)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_THR_CPU */

#ifdef FeeConf_FeeBlockConfiguration_CLK_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CLK_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_CLK_CPU ((uint16)1458)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CLK_CPU */

#ifdef FeeConf_FeeBlockConfiguration_ALGO_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ALGO_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_ALGO_CPU ((uint16)1460)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ALGO_CPU */

#ifdef FeeConf_FeeBlockConfiguration_COMSPI_CPUSFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COMSPI_CPUSFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_COMSPI_CPUSFTY ((uint16)1462)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COMSPI_CPUSFTY */

#ifdef FeeConf_FeeBlockConfiguration_COMTOUT_CPUSFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COMTOUT_CPUSFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_COMTOUT_CPUSFTY ((uint16)1464)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COMTOUT_CPUSFTY */

#ifdef FeeConf_FeeBlockConfiguration_SYNCMON_CPUSFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SYNCMON_CPUSFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_SYNCMON_CPUSFTY ((uint16)1466)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SYNCMON_CPUSFTY */

#ifdef FeeConf_FeeBlockConfiguration_CLK_CPUSFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CLK_CPUSFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_CLK_CPUSFTY ((uint16)1468)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CLK_CPUSFTY */

#ifdef FeeConf_FeeBlockConfiguration_ALGO_CPUSFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ALGO_CPUSFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_ALGO_CPUSFTY ((uint16)1470)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ALGO_CPUSFTY */

#ifdef FeeConf_FeeBlockConfiguration_CKSROM_CPUSFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CKSROM_CPUSFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_CKSROM_CPUSFTY ((uint16)1472)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CKSROM_CPUSFTY */

#ifdef FeeConf_FeeBlockConfiguration_DEGMOD_CPUSFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DEGMOD_CPUSFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_DEGMOD_CPUSFTY ((uint16)1474)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DEGMOD_CPUSFTY */

#ifdef FeeConf_FeeBlockConfiguration_HI_AENG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HI_AENG already defined
#else 
#define FeeConf_FeeBlockConfiguration_HI_AENG ((uint16)1476)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HI_AENG */

#ifdef FeeConf_FeeBlockConfiguration_HI_NENG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HI_NENG already defined
#else 
#define FeeConf_FeeBlockConfiguration_HI_NENG ((uint16)1478)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HI_NENG */

#ifdef FeeConf_FeeBlockConfiguration_DISTSIG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DISTSIG already defined
#else 
#define FeeConf_FeeBlockConfiguration_DISTSIG ((uint16)1480)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DISTSIG */

#ifdef FeeConf_FeeBlockConfiguration_COH_INCM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_INCM already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_INCM ((uint16)1482)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_INCM */

#ifdef FeeConf_FeeBlockConfiguration_COH_EXCM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_EXCM already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_EXCM ((uint16)1484)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_EXCM */

#ifdef FeeConf_FeeBlockConfiguration_ENGSPDCOHCK /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ENGSPDCOHCK already defined
#else 
#define FeeConf_FeeBlockConfiguration_ENGSPDCOHCK ((uint16)1486)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ENGSPDCOHCK */

#ifdef FeeConf_FeeBlockConfiguration_ENGSPDCOHINCM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ENGSPDCOHINCM already defined
#else 
#define FeeConf_FeeBlockConfiguration_ENGSPDCOHINCM ((uint16)1488)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ENGSPDCOHINCM */

#ifdef FeeConf_FeeBlockConfiguration_ENGSPDCOHEXCM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ENGSPDCOHEXCM already defined
#else 
#define FeeConf_FeeBlockConfiguration_ENGSPDCOHEXCM ((uint16)1490)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ENGSPDCOHEXCM */

#ifdef FeeConf_FeeBlockConfiguration_NOSIGCK /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_NOSIGCK already defined
#else 
#define FeeConf_FeeBlockConfiguration_NOSIGCK ((uint16)1492)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_NOSIGCK */

#ifdef FeeConf_FeeBlockConfiguration_SIGLOSSCK /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SIGLOSSCK already defined
#else 
#define FeeConf_FeeBlockConfiguration_SIGLOSSCK ((uint16)1494)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SIGLOSSCK */

#ifdef FeeConf_FeeBlockConfiguration_NOSIGINCM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_NOSIGINCM already defined
#else 
#define FeeConf_FeeBlockConfiguration_NOSIGINCM ((uint16)1496)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_NOSIGINCM */

#ifdef FeeConf_FeeBlockConfiguration_SIGLOSSINCM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SIGLOSSINCM already defined
#else 
#define FeeConf_FeeBlockConfiguration_SIGLOSSINCM ((uint16)1498)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SIGLOSSINCM */

#ifdef FeeConf_FeeBlockConfiguration_NOSIGEXCM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_NOSIGEXCM already defined
#else 
#define FeeConf_FeeBlockConfiguration_NOSIGEXCM ((uint16)1500)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_NOSIGEXCM */

#ifdef FeeConf_FeeBlockConfiguration_SIGLOSSEXCM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SIGLOSSEXCM already defined
#else 
#define FeeConf_FeeBlockConfiguration_SIGLOSSEXCM ((uint16)1502)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SIGLOSSEXCM */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_TIENGSTOP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_TIENGSTOP already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_TIENGSTOP ((uint16)1504)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_TIENGSTOP */

#ifdef FeeConf_FeeBlockConfiguration_COH_TIENGSTOP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_TIENGSTOP already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_TIENGSTOP ((uint16)1506)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_TIENGSTOP */

#ifdef FeeConf_FeeBlockConfiguration_INV_VARCOD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INV_VARCOD already defined
#else 
#define FeeConf_FeeBlockConfiguration_INV_VARCOD ((uint16)1508)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INV_VARCOD */

#ifdef FeeConf_FeeBlockConfiguration_ORNGSERVO /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGSERVO already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGSERVO ((uint16)1510)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGSERVO */

#ifdef FeeConf_FeeBlockConfiguration_ORNGSERVODIFPOS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGSERVODIFPOS already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGSERVODIFPOS ((uint16)1512)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGSERVODIFPOS */

#ifdef FeeConf_FeeBlockConfiguration_ORNGSERVODIFNEG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGSERVODIFNEG already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGSERVODIFNEG ((uint16)1514)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGSERVODIFNEG */

#ifdef FeeConf_FeeBlockConfiguration_ENDSTOPREQ1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ENDSTOPREQ1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ENDSTOPREQ1 ((uint16)1516)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ENDSTOPREQ1 */

#ifdef FeeConf_FeeBlockConfiguration_ENDSTOPREQ2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ENDSTOPREQ2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_ENDSTOPREQ2 ((uint16)1518)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ENDSTOPREQ2 */

#ifdef FeeConf_FeeBlockConfiguration_CLSIDLCTL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CLSIDLCTL already defined
#else 
#define FeeConf_FeeBlockConfiguration_CLSIDLCTL ((uint16)1520)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CLSIDLCTL */

#ifdef FeeConf_FeeBlockConfiguration_LIHREQ1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LIHREQ1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_LIHREQ1 ((uint16)1522)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LIHREQ1 */

#ifdef FeeConf_FeeBlockConfiguration_LIHREQ2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LIHREQ2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_LIHREQ2 ((uint16)1524)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LIHREQ2 */

#ifdef FeeConf_FeeBlockConfiguration_COHPOSNSNSR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COHPOSNSNSR already defined
#else 
#define FeeConf_FeeBlockConfiguration_COHPOSNSNSR ((uint16)1526)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COHPOSNSNSR */

#ifdef FeeConf_FeeBlockConfiguration_SCPPOSNSNSR1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCPPOSNSNSR1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCPPOSNSNSR1 ((uint16)1528)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCPPOSNSNSR1 */

#ifdef FeeConf_FeeBlockConfiguration_SCGPOSNSNSR1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCGPOSNSNSR1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCGPOSNSNSR1 ((uint16)1530)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCGPOSNSNSR1 */

#ifdef FeeConf_FeeBlockConfiguration_SCPPOSNSNSR2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCPPOSNSNSR2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCPPOSNSNSR2 ((uint16)1532)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCPPOSNSNSR2 */

#ifdef FeeConf_FeeBlockConfiguration_SCGPOSNSNSR2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SCGPOSNSNSR2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_SCGPOSNSNSR2 ((uint16)1534)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SCGPOSNSNSR2 */

#ifdef FeeConf_FeeBlockConfiguration_DFTSENR_THR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTSENR_THR already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTSENR_THR ((uint16)1536)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTSENR_THR */

#ifdef FeeConf_FeeBlockConfiguration_OVLD_THRCMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OVLD_THRCMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_OVLD_THRCMD ((uint16)1538)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OVLD_THRCMD */

#ifdef FeeConf_FeeBlockConfiguration_CPT_THRCMD /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CPT_THRCMD already defined
#else 
#define FeeConf_FeeBlockConfiguration_CPT_THRCMD ((uint16)1540)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CPT_THRCMD */

#ifdef FeeConf_FeeBlockConfiguration_READPININHTHR_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_READPININHTHR_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_READPININHTHR_CPU ((uint16)1542)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_READPININHTHR_CPU */

#ifdef FeeConf_FeeBlockConfiguration_INHTHR_CPUSFTY /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INHTHR_CPUSFTY already defined
#else 
#define FeeConf_FeeBlockConfiguration_INHTHR_CPUSFTY ((uint16)1544)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INHTHR_CPUSFTY */

#ifdef FeeConf_FeeBlockConfiguration_OVLDTHERMOTHR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OVLDTHERMOTHR already defined
#else 
#define FeeConf_FeeBlockConfiguration_OVLDTHERMOTHR ((uint16)1546)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OVLDTHERMOTHR */

#ifdef FeeConf_FeeBlockConfiguration_ORNGSFTYDFTLIH /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGSFTYDFTLIH already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGSFTYDFTLIH ((uint16)1548)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGSFTYDFTLIH */

#ifdef FeeConf_FeeBlockConfiguration_ELDIAGINHPIN0_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELDIAGINHPIN0_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELDIAGINHPIN0_CPU ((uint16)1550)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELDIAGINHPIN0_CPU */

#ifdef FeeConf_FeeBlockConfiguration_ELDIAGINHPIN1_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ELDIAGINHPIN1_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_ELDIAGINHPIN1_CPU ((uint16)1552)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ELDIAGINHPIN1_CPU */

#ifdef FeeConf_FeeBlockConfiguration_MCPRAMTEST_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MCPRAMTEST_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_MCPRAMTEST_CPU ((uint16)1554)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MCPRAMTEST_CPU */

#ifdef FeeConf_FeeBlockConfiguration_MCPFLASHCKS_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MCPFLASHCKS_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_MCPFLASHCKS_CPU ((uint16)1556)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MCPFLASHCKS_CPU */

#ifdef FeeConf_FeeBlockConfiguration_MCWCKSCALC_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MCWCKSCALC_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_MCWCKSCALC_CPU ((uint16)1558)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MCWCKSCALC_CPU */

#ifdef FeeConf_FeeBlockConfiguration_MCWINITSFTYRSLT_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MCWINITSFTYRSLT_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_MCWINITSFTYRSLT_CPU ((uint16)1560)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MCWINITSFTYRSLT_CPU */

#ifdef FeeConf_FeeBlockConfiguration_MCWFCTTEST_CPU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MCWFCTTEST_CPU already defined
#else 
#define FeeConf_FeeBlockConfiguration_MCWFCTTEST_CPU ((uint16)1562)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MCWFCTTEST_CPU */

#ifdef FeeConf_FeeBlockConfiguration_CLUDMGAFTS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CLUDMGAFTS already defined
#else 
#define FeeConf_FeeBlockConfiguration_CLUDMGAFTS ((uint16)1564)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CLUDMGAFTS */

#ifdef FeeConf_FeeBlockConfiguration_COH_SPDVEH /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_COH_SPDVEH already defined
#else 
#define FeeConf_FeeBlockConfiguration_COH_SPDVEH ((uint16)1566)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_COH_SPDVEH */

#ifdef FeeConf_FeeBlockConfiguration_ORNG_SPDVEH /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNG_SPDVEH already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNG_SPDVEH ((uint16)1568)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNG_SPDVEH */

#ifdef FeeConf_FeeBlockConfiguration_SERVOERRVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SERVOERRVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_SERVOERRVLVACTEX ((uint16)1570)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SERVOERRVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_IMAXVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IMAXVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_IMAXVLVACTEX ((uint16)1572)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IMAXVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_ORNGSPDVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGSPDVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGSPDVLVACTEX ((uint16)1574)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGSPDVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_ORNGSHIFTVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGSHIFTVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGSHIFTVLVACTEX ((uint16)1576)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGSHIFTVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_MISSTOOTHVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSTOOTHVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSTOOTHVLVACTEX ((uint16)1578)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSTOOTHVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_TDCDIAGVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TDCDIAGVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_TDCDIAGVLVACTEX ((uint16)1580)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TDCDIAGVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_CLNERRVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CLNERRVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_CLNERRVLVACTEX ((uint16)1582)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CLNERRVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_LRNENDSTOPVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LRNENDSTOPVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_LRNENDSTOPVLVACTEX ((uint16)1584)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LRNENDSTOPVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_ENDSTOPOLDVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ENDSTOPOLDVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_ENDSTOPOLDVLVACTEX ((uint16)1586)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ENDSTOPOLDVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_LRNFAILIMVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LRNFAILIMVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_LRNFAILIMVLVACTEX ((uint16)1588)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LRNFAILIMVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_OLDLRNVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OLDLRNVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_OLDLRNVLVACTEX ((uint16)1590)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OLDLRNVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_LOVLVACTEXDRV /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LOVLVACTEXDRV already defined
#else 
#define FeeConf_FeeBlockConfiguration_LOVLVACTEXDRV ((uint16)1592)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LOVLVACTEXDRV */

#ifdef FeeConf_FeeBlockConfiguration_HIVLVACTEXDRV /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HIVLVACTEXDRV already defined
#else 
#define FeeConf_FeeBlockConfiguration_HIVLVACTEXDRV ((uint16)1594)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HIVLVACTEXDRV */

#ifdef FeeConf_FeeBlockConfiguration_DFTCVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTCVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTCVLVACTEX ((uint16)1596)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTCVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_ORNGCVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGCVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGCVLVACTEX ((uint16)1598)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGCVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_CMDCVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CMDCVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_CMDCVLVACTEX ((uint16)1600)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CMDCVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_SLOWC1VLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SLOWC1VLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_SLOWC1VLVACTEX ((uint16)1602)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SLOWC1VLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_SLOWC2VLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SLOWC2VLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_SLOWC2VLVACTEX ((uint16)1604)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SLOWC2VLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_DFTHVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTHVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTHVLVACTEX ((uint16)1606)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTHVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_ORNGHVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGHVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGHVLVACTEX ((uint16)1608)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGHVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_CMDHVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CMDHVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_CMDHVLVACTEX ((uint16)1610)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CMDHVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_STUCKHVLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCKHVLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCKHVLVACTEX ((uint16)1612)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCKHVLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_SLOWH1VLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SLOWH1VLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_SLOWH1VLVACTEX ((uint16)1614)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SLOWH1VLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_STUCKH1VLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCKH1VLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCKH1VLVACTEX ((uint16)1616)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCKH1VLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_SLOWH2VLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SLOWH2VLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_SLOWH2VLVACTEX ((uint16)1618)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SLOWH2VLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_STUCKH2VLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCKH2VLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCKH2VLVACTEX ((uint16)1620)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCKH2VLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_STUCKH3VLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCKH3VLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCKH3VLVACTEX ((uint16)1622)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCKH3VLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_DIFPOS1VLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DIFPOS1VLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_DIFPOS1VLVACTEX ((uint16)1624)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DIFPOS1VLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_DIFPOS2VLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DIFPOS2VLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_DIFPOS2VLVACTEX ((uint16)1626)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DIFPOS2VLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_DIFNEG1VLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DIFNEG1VLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_DIFNEG1VLVACTEX ((uint16)1628)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DIFNEG1VLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_DIFNEG2VLVACTEX /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DIFNEG2VLVACTEX already defined
#else 
#define FeeConf_FeeBlockConfiguration_DIFNEG2VLVACTEX ((uint16)1630)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DIFNEG2VLVACTEX */

#ifdef FeeConf_FeeBlockConfiguration_SERVOERRVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SERVOERRVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_SERVOERRVLVACTIN ((uint16)1632)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SERVOERRVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_IMAXVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IMAXVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_IMAXVLVACTIN ((uint16)1634)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IMAXVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_ORNGSPDVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGSPDVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGSPDVLVACTIN ((uint16)1636)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGSPDVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_ORNGSHIFTVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGSHIFTVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGSHIFTVLVACTIN ((uint16)1638)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGSHIFTVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_MISSTOOTHVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISSTOOTHVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISSTOOTHVLVACTIN ((uint16)1640)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISSTOOTHVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_TDCDIAGVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TDCDIAGVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_TDCDIAGVLVACTIN ((uint16)1642)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TDCDIAGVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_CLNERRVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CLNERRVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_CLNERRVLVACTIN ((uint16)1644)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CLNERRVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_LRNENDSTOPVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LRNENDSTOPVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_LRNENDSTOPVLVACTIN ((uint16)1646)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LRNENDSTOPVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_ENDSTOPOLDVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ENDSTOPOLDVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_ENDSTOPOLDVLVACTIN ((uint16)1648)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ENDSTOPOLDVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_LRNFAILIMVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LRNFAILIMVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_LRNFAILIMVLVACTIN ((uint16)1650)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LRNFAILIMVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_OLDLRNVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OLDLRNVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_OLDLRNVLVACTIN ((uint16)1652)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OLDLRNVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_LOVLVACTINDRV /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_LOVLVACTINDRV already defined
#else 
#define FeeConf_FeeBlockConfiguration_LOVLVACTINDRV ((uint16)1654)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_LOVLVACTINDRV */

#ifdef FeeConf_FeeBlockConfiguration_HIVLVACTINDRV /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HIVLVACTINDRV already defined
#else 
#define FeeConf_FeeBlockConfiguration_HIVLVACTINDRV ((uint16)1656)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HIVLVACTINDRV */

#ifdef FeeConf_FeeBlockConfiguration_DFTCVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTCVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTCVLVACTIN ((uint16)1658)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTCVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_ORNGCVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGCVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGCVLVACTIN ((uint16)1660)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGCVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_CMDCVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CMDCVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_CMDCVLVACTIN ((uint16)1662)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CMDCVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_SLOWC1VLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SLOWC1VLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_SLOWC1VLVACTIN ((uint16)1664)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SLOWC1VLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_SLOWC2VLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SLOWC2VLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_SLOWC2VLVACTIN ((uint16)1666)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SLOWC2VLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_DFTHVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DFTHVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_DFTHVLVACTIN ((uint16)1668)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DFTHVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_ORNGHVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ORNGHVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_ORNGHVLVACTIN ((uint16)1670)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ORNGHVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_CMDHVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_CMDHVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_CMDHVLVACTIN ((uint16)1672)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_CMDHVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_STUCKHVLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCKHVLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCKHVLVACTIN ((uint16)1674)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCKHVLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_SLOWH1VLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SLOWH1VLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_SLOWH1VLVACTIN ((uint16)1676)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SLOWH1VLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_STUCKH1VLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCKH1VLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCKH1VLVACTIN ((uint16)1678)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCKH1VLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_SLOWH2VLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SLOWH2VLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_SLOWH2VLVACTIN ((uint16)1680)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SLOWH2VLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_STUCKH2VLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCKH2VLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCKH2VLVACTIN ((uint16)1682)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCKH2VLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_STUCKH3VLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STUCKH3VLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_STUCKH3VLVACTIN ((uint16)1684)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STUCKH3VLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_DIFPOS1VLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DIFPOS1VLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_DIFPOS1VLVACTIN ((uint16)1686)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DIFPOS1VLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_DIFPOS2VLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DIFPOS2VLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_DIFPOS2VLVACTIN ((uint16)1688)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DIFPOS2VLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_DIFNEG1VLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DIFNEG1VLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_DIFNEG1VLVACTIN ((uint16)1690)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DIFNEG1VLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_DIFNEG2VLVACTIN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_DIFNEG2VLVACTIN already defined
#else 
#define FeeConf_FeeBlockConfiguration_DIFNEG2VLVACTIN ((uint16)1692)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_DIFNEG2VLVACTIN */

#ifdef FeeConf_FeeBlockConfiguration_ZZEND_BIDON /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ZZEND_BIDON already defined
#else 
#define FeeConf_FeeBlockConfiguration_ZZEND_BIDON ((uint16)1694)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ZZEND_BIDON */

#ifdef FeeConf_FeeBlockConfiguration_HEATSENO2DSDERIDIAG /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HEATSENO2DSDERIDIAG already defined
#else 
#define FeeConf_FeeBlockConfiguration_HEATSENO2DSDERIDIAG ((uint16)1696)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HEATSENO2DSDERIDIAG */

#ifdef FeeConf_FeeBlockConfiguration_HEATSENO2DS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HEATSENO2DS already defined
#else 
#define FeeConf_FeeBlockConfiguration_HEATSENO2DS ((uint16)1698)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HEATSENO2DS */

#ifdef FeeConf_FeeBlockConfiguration_HEATSENO2US /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_HEATSENO2US already defined
#else 
#define FeeConf_FeeBlockConfiguration_HEATSENO2US ((uint16)1700)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_HEATSENO2US */

#ifdef FeeConf_FeeBlockConfiguration_IFAIRSYSIGSYS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_IFAIRSYSIGSYS already defined
#else 
#define FeeConf_FeeBlockConfiguration_IFAIRSYSIGSYS ((uint16)1702)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_IFAIRSYSIGSYS */

#ifdef FeeConf_FeeBlockConfiguration_INJFARCTLDSCTL /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INJFARCTLDSCTL already defined
#else 
#define FeeConf_FeeBlockConfiguration_INJFARCTLDSCTL ((uint16)1704)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INJFARCTLDSCTL */

#ifdef FeeConf_FeeBlockConfiguration_MISFDFTLRN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MISFDFTLRN already defined
#else 
#define FeeConf_FeeBlockConfiguration_MISFDFTLRN ((uint16)1706)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MISFDFTLRN */

#ifdef FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT16_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT16_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT16_CONST ((uint16)1708)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT16_CONST */

#ifdef FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST ((uint16)1710)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST */

#ifdef FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST_1 ((uint16)1712)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST_2 ((uint16)1714)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_MPM_NVRAM_INT32_CONST_2 */

#ifdef FeeConf_FeeBlockConfiguration_INJRCHRN /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_INJRCHRN already defined
#else 
#define FeeConf_FeeBlockConfiguration_INJRCHRN ((uint16)1716)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_INJRCHRN */

#ifdef FeeConf_FeeBlockConfiguration_OBDSRV06 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_OBDSRV06 already defined
#else 
#define FeeConf_FeeBlockConfiguration_OBDSRV06 ((uint16)1718)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_OBDSRV06 */

#ifdef FeeConf_FeeBlockConfiguration_POSTEQUSRV_BANTISCANNING /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_POSTEQUSRV_BANTISCANNING already defined
#else 
#define FeeConf_FeeBlockConfiguration_POSTEQUSRV_BANTISCANNING ((uint16)1720)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_POSTEQUSRV_BANTISCANNING */

#ifdef FeeConf_FeeBlockConfiguration_PREDES /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PREDES already defined
#else 
#define FeeConf_FeeBlockConfiguration_PREDES ((uint16)1722)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PREDES */

#ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT16_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT16_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT16_CONST_1 ((uint16)1724)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT16_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT16_CONST_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT16_CONST_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT16_CONST_2 ((uint16)1726)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT16_CONST_2 */

#ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_1 ((uint16)1728)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_2 ((uint16)1730)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_2 */

#ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_3 ((uint16)1732)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT32_CONST_3 */

#ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT8_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT8_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT8_CONST_1 ((uint16)1734)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT8_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT8_CONST_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT8_CONST_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT8_CONST_2 ((uint16)1736)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_INT8_CONST_2 */

#ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_BOOLEAN_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_BOOLEAN_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_BOOLEAN_CONST_1 ((uint16)1738)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_BOOLEAN_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_BOOLEAN_CONST_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_BOOLEAN_CONST_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_BOOLEAN_CONST_2 ((uint16)1740)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PRODELEM_NVRAM_BOOLEAN_CONST_2 */

#ifdef FeeConf_FeeBlockConfiguration_PRODELENG_NVRAM_INT32_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PRODELENG_NVRAM_INT32_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_PRODELENG_NVRAM_INT32_CONST_1 ((uint16)1742)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PRODELENG_NVRAM_INT32_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_PROTMANCLU /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PROTMANCLU already defined
#else 
#define FeeConf_FeeBlockConfiguration_PROTMANCLU ((uint16)1744)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PROTMANCLU */

#ifdef FeeConf_FeeBlockConfiguration_ECUSTSRVPWRLST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_ECUSTSRVPWRLST already defined
#else 
#define FeeConf_FeeBlockConfiguration_ECUSTSRVPWRLST ((uint16)1746)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_ECUSTSRVPWRLST */

#ifdef FeeConf_FeeBlockConfiguration_REFIDETA /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_REFIDETA already defined
#else 
#define FeeConf_FeeBlockConfiguration_REFIDETA ((uint16)1748)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_REFIDETA */

#ifdef FeeConf_FeeBlockConfiguration_RANDOM /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_RANDOM already defined
#else 
#define FeeConf_FeeBlockConfiguration_RANDOM ((uint16)1750)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_RANDOM */

#ifdef FeeConf_FeeBlockConfiguration_SFTYMNGR /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SFTYMNGR already defined
#else 
#define FeeConf_FeeBlockConfiguration_SFTYMNGR ((uint16)1752)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SFTYMNGR */

#ifdef FeeConf_FeeBlockConfiguration_SPYEMSTT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SPYEMSTT already defined
#else 
#define FeeConf_FeeBlockConfiguration_SPYEMSTT ((uint16)1754)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SPYEMSTT */

#ifdef FeeConf_FeeBlockConfiguration_SPYSTT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SPYSTT already defined
#else 
#define FeeConf_FeeBlockConfiguration_SPYSTT ((uint16)1756)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SPYSTT */

#ifdef FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT16_CONST_3 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT16_CONST_3 already defined
#else 
#define FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT16_CONST_3 ((uint16)1758)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT16_CONST_3 */

#ifdef FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT32_CONST_1 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT32_CONST_1 already defined
#else 
#define FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT32_CONST_1 ((uint16)1760)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT32_CONST_1 */

#ifdef FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT32_CONST_2 /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT32_CONST_2 already defined
#else 
#define FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT32_CONST_2 ((uint16)1762)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_STOPSTRTEM_NVRAM_INT32_CONST_2 */

#ifdef FeeConf_FeeBlockConfiguration_SYNCENGCLC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_SYNCENGCLC already defined
#else 
#define FeeConf_FeeBlockConfiguration_SYNCENGCLC ((uint16)1764)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_SYNCENGCLC */

#ifdef FeeConf_FeeBlockConfiguration_TELE_BANTISCANNING /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TELE_BANTISCANNING already defined
#else 
#define FeeConf_FeeBlockConfiguration_TELE_BANTISCANNING ((uint16)1766)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TELE_BANTISCANNING */

#ifdef FeeConf_FeeBlockConfiguration_THMGT_NVRAM_INT8_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_THMGT_NVRAM_INT8_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_THMGT_NVRAM_INT8_CONST ((uint16)1768)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_THMGT_NVRAM_INT8_CONST */

#ifdef FeeConf_FeeBlockConfiguration_THMGT_NVRAM_BOOLEAN_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_THMGT_NVRAM_BOOLEAN_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_THMGT_NVRAM_BOOLEAN_CONST ((uint16)1770)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_THMGT_NVRAM_BOOLEAN_CONST */

#ifdef FeeConf_FeeBlockConfiguration_THRSPT_NVRAM_INT32_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_THRSPT_NVRAM_INT32_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_THRSPT_NVRAM_INT32_CONST ((uint16)1772)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_THRSPT_NVRAM_INT32_CONST */

#ifdef FeeConf_FeeBlockConfiguration_PAP_MOT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_PAP_MOT already defined
#else 
#define FeeConf_FeeBlockConfiguration_PAP_MOT ((uint16)1774)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_PAP_MOT */

#ifdef FeeConf_FeeBlockConfiguration_TIENGSTOP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TIENGSTOP already defined
#else 
#define FeeConf_FeeBlockConfiguration_TIENGSTOP ((uint16)1776)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TIENGSTOP */

#ifdef FeeConf_FeeBlockConfiguration_TOILEST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TOILEST already defined
#else 
#define FeeConf_FeeBlockConfiguration_TOILEST ((uint16)1778)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TOILEST */

#ifdef FeeConf_FeeBlockConfiguration_TPM_NVRAM_INT16_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TPM_NVRAM_INT16_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_TPM_NVRAM_INT16_CONST ((uint16)1780)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TPM_NVRAM_INT16_CONST */

#ifdef FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT16_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT16_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT16_CONST ((uint16)1782)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT16_CONST */

#ifdef FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT32_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT32_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT32_CONST ((uint16)1784)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT32_CONST */

#ifdef FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT8_CONST /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT8_CONST already defined
#else 
#define FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT8_CONST ((uint16)1786)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TQADPCMP_NVRAM_INT8_CONST */

#ifdef FeeConf_FeeBlockConfiguration_TWCMGT /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_TWCMGT already defined
#else 
#define FeeConf_FeeBlockConfiguration_TWCMGT ((uint16)1788)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_TWCMGT */

#ifdef FeeConf_FeeBlockConfiguration_UPLSACQ /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_UPLSACQ already defined
#else 
#define FeeConf_FeeBlockConfiguration_UPLSACQ ((uint16)1790)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_UPLSACQ */

#ifdef FeeConf_FeeBlockConfiguration_USTHRMT_NVRAM_INT16_CALIB /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_USTHRMT_NVRAM_INT16_CALIB already defined
#else 
#define FeeConf_FeeBlockConfiguration_USTHRMT_NVRAM_INT16_CALIB ((uint16)1792)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_USTHRMT_NVRAM_INT16_CALIB */

#ifdef FeeConf_FeeBlockConfiguration_VLVACTEXENDSTOP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_VLVACTEXENDSTOP already defined
#else 
#define FeeConf_FeeBlockConfiguration_VLVACTEXENDSTOP ((uint16)1794)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_VLVACTEXENDSTOP */

#ifdef FeeConf_FeeBlockConfiguration_VLVACTINENDSTOP /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_VLVACTINENDSTOP already defined
#else 
#define FeeConf_FeeBlockConfiguration_VLVACTINENDSTOP ((uint16)1796)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_VLVACTINENDSTOP */

#ifdef FeeConf_FeeBlockConfiguration_VSC /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_VSC already defined
#else 
#define FeeConf_FeeBlockConfiguration_VSC ((uint16)1798)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_VSC */

#ifdef FeeConf_FeeBlockConfiguration_BSW_BLOCK_RESET /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BSW_BLOCK_RESET already defined
#else 
#define FeeConf_FeeBlockConfiguration_BSW_BLOCK_RESET ((uint16)1800)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BSW_BLOCK_RESET */

#ifdef FeeConf_FeeBlockConfiguration_BSW_BLOCK_EXCEPTIONS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BSW_BLOCK_EXCEPTIONS already defined
#else 
#define FeeConf_FeeBlockConfiguration_BSW_BLOCK_EXCEPTIONS ((uint16)1802)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BSW_BLOCK_EXCEPTIONS */

#ifdef FeeConf_FeeBlockConfiguration_BSW_BLOCK_MEAS /* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_BSW_BLOCK_MEAS already defined
#else 
#define FeeConf_FeeBlockConfiguration_BSW_BLOCK_MEAS ((uint16)1804)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_BSW_BLOCK_MEAS */


#define FEE_DISABLE_DEM_REPORT   (0U)
#define FEE_ENABLE_DEM_REPORT    (1U)

/* DEM Configurations */
#define FEE_GC_INIT_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)
#define FEE_WRITE_DEM_REPORT         (FEE_DISABLE_DEM_REPORT)
#define FEE_READ_DEM_REPORT          (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_WRITE_DEM_REPORT      (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_READ_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_ERASE_DEM_REPORT      (FEE_DISABLE_DEM_REPORT)
#define FEE_INVALIDATE_DEM_REPORT    (FEE_DISABLE_DEM_REPORT)
#define FEE_WRITE_CYCLES_DEM_REPORT  (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_TRIG_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)
#define FEE_UNCFG_BLK_DEM_REPORT     (FEE_DISABLE_DEM_REPORT)
#define FEE_DEM_ENABLED              (STD_OFF)

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define FEE_CONFIG_PTR      (Fee_CfgPtr)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#endif /* #ifndef FEE_CFG_H */

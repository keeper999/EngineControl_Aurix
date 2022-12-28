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
**  $FILENAME   : Fee_Ver.c $                                                **
**                                                                           **
**  $CC VERSION : \main\3 $                                                  **
**                                                                           **
**  $DATE       : 2013-11-14 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                 - AUTOSAR version specific functionality of FEE driver    **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
   Traceability :
                    [cover parentID=DS_NAS_PR730]
                    [/cover]
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Flash header file */
#include "Fee.h"

#if (FEE_DEM_ENABLED == STD_ON)
/* Inclusion of Dem.h  */
#include "Dem.h"
#endif

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*
    AUTOSAR VERSION CHECK FOR FEE MODULE INCLUSION
*/

#ifndef FEE_AR_RELEASE_MAJOR_VERSION
  #error "FEE_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef FEE_AR_RELEASE_MINOR_VERSION
  #error "FEE_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef FEE_AR_RELEASE_REVISION_VERSION
  #error "FEE_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if ( FEE_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "FEE_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( FEE_AR_RELEASE_MINOR_VERSION != 0U )
  #error "FEE_AR_RELEASE_MINOR_VERSION does not match. "
#endif

/*
    DRIVER VERSION CHECK FOR FEE MODULE INCLUSION
*/

#ifndef FEE_SW_MAJOR_VERSION
  #error "FEE_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef FEE_SW_MINOR_VERSION
  #error "FEE_SW_MINOR_VERSION is not defined. "
#endif

#ifndef FEE_SW_PATCH_VERSION
  #error "FEE_SW_PATCH_VERSION is not defined. "
#endif

#if ( FEE_SW_MAJOR_VERSION != 2U )
  #error "FEE_SW_MAJOR_VERSION does not match. "
#endif

#if ( FEE_SW_MINOR_VERSION != 2U )
  #error "FEE_SW_MINOR_VERSION does not match. "
#endif

/*
    VERSION CHECK FOR DET MODULE INCLUSION
*/

#if (FEE_DEV_ERROR_DETECT == STD_ON)

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

/*
    VERSION CHECK FOR DEM MODULE INCLUSION
*/

#if (FEE_DEM_ENABLED == STD_ON)

  #ifndef DEM_AR_RELEASE_MAJOR_VERSION
    #error "DEM_AR_RELEASE_MAJOR_VERSION is not defined. "
  #endif
  
  #ifndef DEM_AR_RELEASE_MINOR_VERSION
    #error "DEM_AR_RELEASE_MINOR_VERSION is not defined. "
  #endif
  
  #if ( DEM_AR_RELEASE_MAJOR_VERSION != 4U )
    #error "DEM_AR_RELEASE_MAJOR_VERSION does not match. "
  #endif
  #if ( DEM_AR_RELEASE_MINOR_VERSION != 0U )
    #error "DEM_AR_RELEASE_MINOR_VERSION does not match. "
  #endif

#endif

/*
    VERSION CHECK FOR FLS MODULE INCLUSION
*/

#ifndef FLS_17_PMU_AR_RELEASE_MAJOR_VERSION
  #error "FLS_17_PMU_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef FLS_17_PMU_AR_RELEASE_MINOR_VERSION
  #error "FLS_17_PMU_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#if ( FLS_17_PMU_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "FLS_17_PMU_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( FLS_17_PMU_AR_RELEASE_MINOR_VERSION != 0U )
  #error "FLS_17_PMU_AR_RELEASE_MINOR_VERSION does not match. "
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

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

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


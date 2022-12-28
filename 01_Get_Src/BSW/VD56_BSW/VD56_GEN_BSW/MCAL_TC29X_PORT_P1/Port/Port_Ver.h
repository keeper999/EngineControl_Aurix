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
**  $FILENAME   : Port_Ver.h                                                  **
**                                                                            **
**  $CC VERSION : \main\5 $                                                  **
**                                                                            **
**  $DATE       : 2014-01-10 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of Port driver.                            **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/
/* Traceability : [cover parentID=DS_AS_PORT129,
                  DS_AS_PORT051,DS_AS_PORT116,DS_AS40X_PORT001_PI,
                  DS_NAS_PORT_PR912_2,DS_AS_PORT072_1,DS_AS_PORT072_2,
                  DS_AS_PORT072_3,DS_AS_PORT072_4,DS_AS_PORT072_5,
                  DS_AS_PORT072_6,DS_AS_PORT072_7,DS_AS_PORT072_8,
                  DS_AS_PORT072_9,DS_AS_PORTConfigType,DS_AS_PORT073,
                  DS_AS_PORTPinType,DS_AS_PORT219,DS_AS_PORT013,
                  DS_AS_PORTPinDirectionType,DS_AS_PORT220,DS_AS_PORT046,
                  DS_AS_PORTPinModeType,DS_AS_PORT221,
                  DS_AS_PORT124,DS_AS_PORT212
                  DS_NAS_PORT_PR730]                                
                  [/cover]                                                    */



/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
/* PORT080: Inclusion structure */
#include "Port.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

#ifndef PORT_AR_RELEASE_MAJOR_VERSION
  #error "PORT_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef PORT_AR_RELEASE_MINOR_VERSION
  #error "PORT_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef PORT_AR_RELEASE_REVISION_VERSION
  #error "PORT_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if ( PORT_AR_RELEASE_MAJOR_VERSION != 4U)
  #error "PORT_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( PORT_AR_RELEASE_MINOR_VERSION != 0U )
  #error "PORT_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#ifndef PORT_SW_MAJOR_VERSION
  #error "PORT_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef PORT_SW_MINOR_VERSION
  #error "PORT_SW_MINOR_VERSION is not defined. "
#endif

#ifndef PORT_SW_PATCH_VERSION
  #error "PORT_SW_PATCH_VERSION is not defined. "
#endif

/* Check for Correct inclusion of headers */
#if ( PORT_SW_MAJOR_VERSION != 3U )
  #error "PORT_SW_MAJOR_VERSION does not match. "
#endif
#if ( PORT_SW_MINOR_VERSION != 0U )
  #error "PORT_SW_MINOR_VERSION does not match. "
#endif

#if (PORT_DEV_ERROR_DETECT == STD_ON)

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

#endif /*#if (PORT_DEV_ERROR_DETECT == STD_ON)*/

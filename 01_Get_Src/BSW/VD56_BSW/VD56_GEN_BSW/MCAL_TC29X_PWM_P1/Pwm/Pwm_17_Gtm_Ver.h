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
**  $FILENAME   : Pwm_17_Gtm_Ver.h                                            **
**                                                                            **
**  $CC VERSION : \main\3 $                                                  **
**                                                                            **
**  $DATE       : 2013-08-22 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of Pwm driver.                            **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/
/* Traceability : 
                                                                     */



/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
#include "Pwm_17_Gtm.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/* Check for definition of the AS Version */
#ifndef PWM_17_GTM_AR_RELEASE_MAJOR_VERSION
  #error "PWM_17_GTM_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef PWM_17_GTM_AR_RELEASE_MINOR_VERSION
  #error "PWM_17_GTM_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef PWM_17_GTM_AR_RELEASE_REVISION_VERSION
  #error "PWM_17_GTM_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if ( PWM_17_GTM_AR_RELEASE_MAJOR_VERSION != 4U)
  #error "PWM_17_GTM_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( PWM_17_GTM_AR_RELEASE_MINOR_VERSION != 0U )
  #error "PWM_17_GTM_AR_RELEASE_MINOR_VERSION does not match. "
#endif

/* PWM029: */
/* Check for definition of SW version Information */
#ifndef PWM_17_GTM_SW_MAJOR_VERSION
  #error "PWM_17_GTM_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef PWM_17_GTM_SW_MINOR_VERSION
  #error "PWM_17_GTM_SW_MINOR_VERSION is not defined. "
#endif

#ifndef PWM_17_GTM_SW_PATCH_VERSION
  #error "PWM_17_GTM_SW_PATCH_VERSION is not defined. "
#endif

#if ( PWM_17_GTM_SW_MAJOR_VERSION != 3U )
  #error "PWM_17_GTM_SW_MAJOR_VERSION does not match. "
#endif
#if ( PWM_17_GTM_SW_MINOR_VERSION != 0U )
  #error "PWM_17_GTM_SW_MINOR_VERSION does not match. "
#endif

/*
  PWM029: Inter Module Checks to avoid integration of incompatible files
*/
#if ( PWM_DEV_ERROR_DETECT == STD_ON)
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
/* PWM_DEV_ERROR_DETECT == STD_ON) */

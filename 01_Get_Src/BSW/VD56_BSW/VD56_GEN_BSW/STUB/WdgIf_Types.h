/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2006)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : WdgIf_Types                                                   **
**                                                                            **
**  VERSION   : 2.0.2                                                         **
**                                                                            **
**  DATE      : 2012.10.23                                                    **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Independent                                                   **
**                                                                            **
**  COMPILER  : Independent                                                   **
**                                                                            **                                                                        **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file is used for the definitions of types used        **
**                                          by the interface.                 **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :  NA                                                    **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: NO                                       **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Author(s) Identity                                   **
*******************************************************************************
**                                                                           **
** Initials     Name                                                         **
** --------------------------------------------------------------------------**
** RS           Roopa Sirur                                                  **
** MK           Mundhra Karan                                                **
******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0: 2007.04.16, RS  : Created the Initial Version *
 * V2.0.0: 2012.05.10, MK  : Corrected Misra error for '_WDGIF_TYPES_H_' *
 * V2.0.1: 2012.06.08, MK  : Removed WdgIf_StatusType
 * V2.0.2: 2012.10.23, MK  : Corrected  WDGIF_TYPES_H
*/

/*---- Protection against multiple inclusion -------------------------------*/
#ifndef WDGIF_TYPES_H
#define WDGIF_TYPES_H

#include "Std_Types.h"

/*---- Version identification - --------------------------------------------*/

  /*refer to WDGIF023*/
#define WDGIF_TYPES_MAJOR_VERSION      (3U)
#define WDGIF_TYPES_MINOR_VERSION      (0U)
#define WDGIF_TYPES_PATCH_VERSION      (0U)

/*---- Switch between external and forward declaration ---------------------*/

/*---- API Type definitions ------------------------------------------------*/

typedef enum
{
    WDGIF_OFF_MODE = 0,
    WDGIF_SLOW_MODE,
    WDGIF_FAST_MODE
} WdgIf_ModeType; /*refer to WDGIF016*/

/*---- Include of configuration (public section) ---------------------------*/

/* #include "WdgIf_Cfg.h" */
/*--------------------------------------------------------------------------*/
#endif  /* End of WdgIf_Types.h */

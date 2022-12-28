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
**  $FILENAME   : Icu_17_GtmCcu6_Dbg.h $                                     **
**                                                                           **
**  $CC VERSION : \main\8 $                                                  **
**                                                                           **
**  $DATE       : 2013-08-12 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - functionality of ICU driver.                             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: no                                     **
**                                                                           **
******************************************************************************/
#ifndef ICU_17_GTMCCU6_DBG_H
#define ICU_17_GTMCCU6_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Icu_17_GtmCcu6.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

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
#if ( ICU_DEBUG_SUPPORT == STD_ON )
/*  [cover parentID=DS_AS40X_ICU350] */

#define ICU_17_GTMCCU6_START_SEC_VAR_8BIT
#include "MemMap.h"

  extern uint8 Icu_17_GtmCcu6_InitStatus;
  extern Icu_17_GtmCcu6_ModeType Icu_17_GtmCcu6_GlobMode;
  
#define ICU_17_GTMCCU6_STOP_SEC_VAR_8BIT
#include "MemMap.h"

/* [/cover]  */
#endif

#endif /* ICU_17_GTMCCU6_DBG_H */

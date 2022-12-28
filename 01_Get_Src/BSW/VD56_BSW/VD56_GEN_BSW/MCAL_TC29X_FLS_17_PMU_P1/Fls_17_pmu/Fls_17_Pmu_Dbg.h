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
**  $FILENAME   : Fls_17_Pmu_Dbg.h $                                         **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-26 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file exports the debug functionality of FLS driver   **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
   Traceability:
                    [cover parentID=DS_AS402_FLS303,DS_AS402_FLS304]
                    [/cover]
*******************************************************************************/

#ifndef FLS_17_PMU_DBG_H
#define FLS_17_PMU_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Fls_17_Pmu.h"

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
#define FLS_17_PMU_START_SEC_VAR_32BIT
#include "MemMap.h"

#ifdef FLS_STATE_VAR
#if ( FLS_DEBUG_SUPPORT == STD_ON )
extern Fls_17_Pmu_StateType FLS_STATE_VAR;
#endif
#endif


#define FLS_17_PMU_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#endif /* FLS_17_PMU_DBG_H */

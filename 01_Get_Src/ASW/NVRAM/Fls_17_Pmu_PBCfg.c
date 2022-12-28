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
**  $FILENAME   : Fls_17_Pmu_PBCfg.c $                                       **
**                                                                           **
**  $CC VERSION : \main\35 $                                                 **
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

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include Flash Module File */
#include "Fls_17_Pmu.h"
#include "Fls_17_Pmu_ac.h"
/*Include for Fls call back function */
#include "Fls_17_Cbk.h"
/* Include Diagnostic Error Manager Header */
#include "Dem.h"

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

/* Function declaration of Fls Job End Notification */
extern void Fee_JobEndNotification(void);

/* Function declaration of Fls Job Error Notifications */
extern void Fee_JobErrorNotification(void);

/* Function declaration of Illegal State Notification */
extern void Fee_17_IllegalStateNotification(void);

/*******************************************************************************
**                      Global Constant Definitions                          **
*******************************************************************************/

#define FLS_17_PMU_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/* Fls State Variable structure */
#if(FLS_DEBUG_SUPPORT == STD_OFF)
static Fls_17_Pmu_StateType  FlsStateVar;
#else
Fls_17_Pmu_StateType  FlsStateVar;
#endif

#define FLS_17_PMU_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define FLS_17_PMU_START_SEC_POSTBUILDCFG
#include "MemMap.h"

const Fls_17_Pmu_ConfigType Fls_17_Pmu_ConfigRoot[] = 
{
  {
    /* Fls state variable structure */
    &FlsStateVar,

    /* Maximum number of bytes to Read in one cycle */
    /* Fast Mode */
    65535U,
    /* Normal Mode */
    32U,

    /* Job End Notification */
    &Fee_JobEndNotification,

    /* Job Error Notification */
    &Fee_JobErrorNotification,

    /* Illegal State Notification */
    &Fee_17_IllegalStateNotification,

    /*Wait state configuration for Read access and error correction */
    (((uint32)FLS_WAIT_STATE_READACCESS9 << 6U) | 
      ((uint32)FLS_WAIT_STATE_ERRORCORRECTION1 << 12U) ),

    /*Flash access code address in RAM */ 
    (Fls_WriteCmdPtrType)(void*)&Fls_WriteCmdCycles,
    /*Flash access code address in RAM */      
    (Fls_EraseCmdPtrType)(void*)&Fls_EraseCmdCycles,
    /* FlsCallCycle for timeout monitoring,convert to us by multiplying by 1000 * 1000 */
    10000U,


    /* Default mode of FLS driver */
    MEMIF_MODE_FAST
  }
};


#define FLS_17_PMU_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"


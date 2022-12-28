#if !defined(RTE_INTERN_APPLICATION_CORE2_H)
#define RTE_INTERN_APPLICATION_CORE2_H

/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /*
  * This file contains internal Rte declarations
  *
  * This file has been automatically generated by
  * EB tresos AutoCore Rte Generator Version 6.1.57
  * on Mon Nov 03 12:24:26 CET 2014. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

/*==================[inclusions]=============================================*/

#include <Os.h>                     /* OS header file */
#include <Rte_Type.h>               /* RTE types header file */
#include <TSMem.h>          /* Include memory copy functions */
#include <Rte_Partitioning.h>        /* Inter-Partition Communication */

/*==================[macros]=================================================*/

/*------------------[ticks to ns]--------------------------------------------*/

#ifdef OS_NsToTicks_Schedule_table_counter
#define RTE_NS_TO_TICKS OS_NsToTicks_Schedule_table_counter
#else
#define RTE_NS_TO_TICKS(ns) (((TickType) ((ns) / 500000)))
#endif

/*------------------[starting of schedule tables]----------------------------*/

#define Rte_StartScheduleTable_Rte_DefaultScheduleTable_1() (StartScheduleTableRel (Rte_DefaultScheduleTable_1, 20U))

/*------------------[RTE events]---------------------------------------------*/

/*------------------[symbolic names for COM signals]-------------------------*/

/*------------------[interrupt locking]--------------------------------------*/

#define Rte_IntLock()     SuspendAllInterrupts()
#define Rte_IntUnlock()   ResumeAllInterrupts()

/*------------------[partition states]---------------------------------------*/

#define RTE_PARTITION_UNINITIALIZED 0x0U
#define RTE_PARTITION_ACTIVE 0x1U
#define RTE_PARTITION_STOPPED 0x2U
#define RTE_PARTITION_TERMINATED 0x3U
#define RTE_PARTITION_RESTARTING 0x4U
#define RTE_PARTITION_STARTING 0x5U

/*------------------[client request states]----------------------------------*/

/*------------------[internal mode declarations]-------------------------------*/

/*------------------[mode disabling dependencies]----------------------------*/

/*------------------[BSW task name]------------------------------------------*/

/*==================[type definitions]=======================================*/

/*------------------[receive buffer types]-----------------------------------*/

typedef struct 
{
  VAR(dt_Icd_state, AUTOMATIC) value;
} Rte_ReceiveBuffer_4585_Type;

/*------------------[shared buffer types]------------------------------------*/

/*------------------[receive queue types]------------------------------------*/

/*------------------[client request types]-----------------------------------*/

/*------------------[invocation queue types]---------------------------------*/

/*------------------[mode receive queue types]-------------------------------*/

/*------------------[event mask type]----------------------------------------*/

/*------------------[mode disabling dependency type]-------------------------*/

/*------------------[client data structure types]----------------------------*/

/*-------------------[buffer data structure type]----------------------------*/

typedef struct
{
  VAR(Rte_ReceiveBuffer_4585_Type, TYPEDEF) Rte_ReceiveBuffer_4585;
} Rte_SwcBufferDataStructureType_Application_Core2;

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

#define RTE_START_SEC_APPLICATION_CORE2_CODE
#include "MemMap.h"

/*------------------[declaration of API functions]---------------------------*/

#define RTE_STOP_SEC_APPLICATION_CORE2_CODE
#include "MemMap.h"
/*------------------[OS object declarations]---------------------------------*/

#define RTE_START_SEC_APPLICATION_CORE2_CODE
#include "MemMap.h"

DeclareTask (OSTSK_C_10MS_6);
DeclareTask (OSTSK_C_1000MS_5);
DeclareTask (OSTSK_C_10MS_8);
DeclareTask (OSTSK_C_200MS_2);
DeclareTask (OSTSK_S_BDC_2);
DeclareTask (OSTSK_S_FUNCTIONAL_TEST_ABORT);
DeclareTask (OSTSK_S_FUNCTIONAL_TEST_START);
DeclareTask (OSTSK_C_1000MS_1);
DeclareTask (OSTSK_C_1000MS_1_POST);
DeclareTask (OSTSK_C_1000MS_2);
DeclareTask (OSTSK_C_1000MS_2_POST);
DeclareTask (OSTSK_C_1000MS_3);
DeclareTask (OSTSK_C_1000MS_3_POST);
DeclareTask (OSTSK_C_1000MS_4);
DeclareTask (OSTSK_C_1000MS_4_POST);
DeclareTask (OSTSK_C_1000MS_5_POST);
DeclareTask (OSTSK_C_100MS_1);
DeclareTask (OSTSK_C_100MS_1_POST);
DeclareTask (OSTSK_C_100MS_2);
DeclareTask (OSTSK_C_100MS_2_POST);
DeclareTask (OSTSK_C_100MS_3);
DeclareTask (OSTSK_C_100MS_3_POST);
DeclareTask (OSTSK_C_10MS_1);
DeclareTask (OSTSK_C_10MS_1_POST);
DeclareTask (OSTSK_C_10MS_2);
DeclareTask (OSTSK_C_10MS_2_POST);
DeclareTask (OSTSK_C_10MS_3);
DeclareTask (OSTSK_C_10MS_3_POST);
DeclareTask (OSTSK_C_10MS_4);
DeclareTask (OSTSK_C_10MS_4_POST);
DeclareTask (OSTSK_C_10MS_5);
DeclareTask (OSTSK_C_10MS_5_POST);
DeclareTask (OSTSK_C_10MS_6_POST);
DeclareTask (OSTSK_C_10MS_7);
DeclareTask (OSTSK_C_10MS_7_POST);
DeclareTask (OSTSK_C_10MS_8_POST);
DeclareTask (OSTSK_C_10MS_9);
DeclareTask (OSTSK_C_10MS_9_POST);
DeclareTask (OSTSK_C_2000MS);
DeclareTask (OSTSK_C_2000MS_POST);
DeclareTask (OSTSK_C_200MS_1);
DeclareTask (OSTSK_C_200MS_1_POST);
DeclareTask (OSTSK_C_200MS_2_POST);
DeclareTask (OSTSK_C_200MS_3);
DeclareTask (OSTSK_C_200MS_3_POST);
DeclareTask (OSTSK_C_200MS_4);
DeclareTask (OSTSK_C_200MS_4_POST);
DeclareTask (OSTSK_C_20MS_1);
DeclareTask (OSTSK_C_20MS_1_POST);
DeclareTask (OSTSK_C_20MS_2);
DeclareTask (OSTSK_C_20MS_2_POST);
DeclareTask (OSTSK_C_20MS_3);
DeclareTask (OSTSK_C_20MS_3_POST);
DeclareTask (OSTSK_C_20MS_4);
DeclareTask (OSTSK_C_20MS_4_POST);
DeclareTask (OSTSK_C_20MS_5);
DeclareTask (OSTSK_C_20MS_5_POST);
DeclareTask (OSTSK_C_2MS);
DeclareTask (OSTSK_C_2MS_POST);
DeclareTask (OSTSK_C_2_5MS_1);
DeclareTask (OSTSK_C_2_5MS_1_POST);
DeclareTask (OSTSK_C_2_5MS_2);
DeclareTask (OSTSK_C_2_5MS_2_POST);
DeclareTask (OSTSK_C_4000MS);
DeclareTask (OSTSK_C_4000MS_POST);
DeclareTask (OSTSK_C_400MS);
DeclareTask (OSTSK_C_400MS_POST);
DeclareTask (OSTSK_C_40MS_1);
DeclareTask (OSTSK_C_40MS_1_POST);
DeclareTask (OSTSK_C_40MS_2);
DeclareTask (OSTSK_C_40MS_2_POST);
DeclareTask (OSTSK_C_40MS_3);
DeclareTask (OSTSK_C_40MS_3_POST);
DeclareTask (OSTSK_C_40MS_4);
DeclareTask (OSTSK_C_40MS_4_POST);
DeclareTask (OSTSK_C_40MS_5);
DeclareTask (OSTSK_C_40MS_5_POST);
DeclareTask (OSTSK_C_50MS);
DeclareTask (OSTSK_C_50MS_POST);
DeclareTask (OSTSK_C_5MS_1);
DeclareTask (OSTSK_C_5MS_1_POST);
DeclareTask (OSTSK_C_5MS_2);
DeclareTask (OSTSK_C_5MS_2_POST);
DeclareTask (OSTSK_C_5MS_3);
DeclareTask (OSTSK_C_5MS_3_POST);
DeclareTask (OSTSK_C_5MS_4);
DeclareTask (OSTSK_C_5MS_4_POST);
DeclareTask (OSTSK_C_5MS_5);
DeclareTask (OSTSK_C_5MS_5_POST);
DeclareTask (OSTSK_C_60000MS);
DeclareTask (OSTSK_C_60000MS_POST);
DeclareTask (OSTSK_S_1_4_TDC);
DeclareTask (OSTSK_S_1_4_TDC_POST);
DeclareTask (OSTSK_S_BDC_1);
DeclareTask (OSTSK_S_BDC_1_POST);
DeclareTask (OSTSK_S_BDC_2_POST);
DeclareTask (OSTSK_S_CRK_OFF);
DeclareTask (OSTSK_S_CRK_OFF_POST);
DeclareTask (OSTSK_S_CRK_ON);
DeclareTask (OSTSK_S_CRK_ON_POST);
DeclareTask (OSTSK_S_EEST);
DeclareTask (OSTSK_S_EEST_POST);
DeclareTask (OSTSK_S_ENG_RUN);
DeclareTask (OSTSK_S_ENG_RUN_POST);
DeclareTask (OSTSK_S_ENG_STAL);
DeclareTask (OSTSK_S_ENG_STAL_POST);
DeclareTask (OSTSK_S_EX_CAM_EDGE);
DeclareTask (OSTSK_S_EX_CAM_EDGE_POST);
DeclareTask (OSTSK_S_EX_CAM_PERIOD);
DeclareTask (OSTSK_S_EX_CAM_PERIOD_POST);
DeclareTask (OSTSK_S_ICLC_EVENT);
DeclareTask (OSTSK_S_ICLC_EVENT_POST);
DeclareTask (OSTSK_S_IGK_OFF);
DeclareTask (OSTSK_S_IGK_OFF_POST);
DeclareTask (OSTSK_S_IGK_ON);
DeclareTask (OSTSK_S_IGK_ON_POST);
DeclareTask (OSTSK_S_INJ_EVENT);
DeclareTask (OSTSK_S_INJ_EVENT_POST);
DeclareTask (OSTSK_S_IN_CAM_EDGE);
DeclareTask (OSTSK_S_IN_CAM_EDGE_POST);
DeclareTask (OSTSK_S_IN_CAM_PERIOD);
DeclareTask (OSTSK_S_IN_CAM_PERIOD_POST);
DeclareTask (OSTSK_S_KNK_WIN);
DeclareTask (OSTSK_S_KNK_WIN_POST);
DeclareTask (OSTSK_S_LTOO);
DeclareTask (OSTSK_S_LTOO_POST);
DeclareTask (OSTSK_S_LTOO1);
DeclareTask (OSTSK_S_LTOO1_POST);
DeclareTask (OSTSK_S_N_INV);
DeclareTask (OSTSK_S_N_INV_POST);
DeclareTask (OSTSK_S_N_INV_OFF);
DeclareTask (OSTSK_S_N_INV_OFF_POST);
DeclareTask (OSTSK_S_PTMHAL_EVT);
DeclareTask (OSTSK_S_PTMHAL_EVT_POST);
DeclareTask (OSTSK_S_SPILL_EVENT);
DeclareTask (OSTSK_S_SPILL_EVENT_POST);
DeclareTask (OSTSK_S_TDC_1);
DeclareTask (OSTSK_S_TDC_1_POST);
DeclareTask (OSTSK_S_TDC_2);
DeclareTask (OSTSK_S_TDC_2_POST);
DeclareTask (OSTSK_S_THR);
DeclareTask (OSTSK_S_THR_POST);
DeclareTask (OSTSK_S_TOLO);
DeclareTask (OSTSK_S_TOLO_POST);
DeclareTask (OSTSK_S_TOOTH);
DeclareTask (OSTSK_S_TOOTH_POST);

#define RTE_STOP_SEC_APPLICATION_CORE2_CODE
#include "MemMap.h"

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*----------------------[swc buffer data structure]--------------------------*/

#define RTE_START_SEC_APPLICATION_CORE2_VAR_UNSPECIFIED
#include "MemMap.h"

extern VAR(Rte_SwcBufferDataStructureType_Application_Core2, RTE_VAR) Rte_SwcBDS_Application_Core2;

#define RTE_STOP_SEC_APPLICATION_CORE2_VAR_UNSPECIFIED
#include "MemMap.h"

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/
/** @} doxygen end group definition */
#endif /* !defined(RTE_INTERN_APPLICATION_CORE2_H) */
/*==================[end of file]============================================*/

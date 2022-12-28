/*
 * This is Os_Cfg.h, auto-generated for:
 *   Project: P2017_ASW
 *   Target:  TriCoreHighTec
 *   Variant: TC29x
 *   Version: 5.0.2
 *   [$UKS 650]
 */
#ifndef OS_CFG_H
#define OS_CFG_H
#define OS_TARGET_TRICOREHIGHTEC
#define OS_TRICORE_UNTRUSTED_MASK 0x1000U
#define OS_INIT_SRC_GPSR02 (0x1401U)
#define OS_INIT_SRC_GPSR01 (0xc01U)
#define OS_INIT_SRC_GPSR00 (0x401U)
#define OS_INIT_SRC_STM0SR0 (0x1402U)
#define OS_INIT_SRC_GTMTIM17 (0x1403U)
#define OS_INIT_SRC_GTMTOM12 (0x1404U)
#define OS_INIT_SRC_ASCLIN1ERR (0xc05U)
#define OS_INIT_SRC_ASCLIN1RX (0xc06U)
#define OS_INIT_SRC_ASCLIN1TX (0xc07U)
#define OS_INIT_SRC_CANINT8 (0xc08U)
#define OS_INIT_SRC_CANINT4 (0xc09U)
#define OS_INIT_SRC_CANINT0 (0xc0aU)
#define OS_INIT_SRC_CANINT9 (0xc0bU)
#define OS_INIT_SRC_CANINT5 (0xc0cU)
#define OS_INIT_SRC_CANINT1 (0xc0dU)
#define OS_INIT_SRC_CANINT10 (0xc0eU)
#define OS_INIT_SRC_CANINT6 (0xc0fU)
#define OS_INIT_SRC_CANINT2 (0xc10U)
#define OS_INIT_SRC_CANINT11 (0xc11U)
#define OS_INIT_SRC_CANINT7 (0xc12U)
#define OS_INIT_SRC_CANINT3 (0xc13U)
#define OS_INIT_SRC_DMACH10 (0x1414U)
#define OS_INIT_SRC_GTMTOM26 (0x1415U)
#define OS_INIT_SRC_MSC0SR4 (0x1416U)
#define OS_INIT_SRC_MSC0SR0 (0x1417U)
#define OS_INIT_SRC_DMACH0 (0x1418U)
#define OS_INIT_SRC_DMACH4 (0x1419U)
#define OS_INIT_SRC_DMACH8 (0x141aU)
#define OS_INIT_SRC_DMACH1 (0x141bU)
#define OS_INIT_SRC_DMACH5 (0x141cU)
#define OS_INIT_SRC_DMACH9 (0x141dU)
#define OS_INIT_SRC_QSPI0ERR (0x141eU)
#define OS_INIT_SRC_QSPI0PT (0x141fU)
#define OS_INIT_SRC_QSPI0U (0x1420U)
#define OS_INIT_SRC_QSPI2ERR (0x1421U)
#define OS_INIT_SRC_QSPI2PT (0x1422U)
#define OS_INIT_SRC_QSPI2U (0x1423U)
#define OS_INIT_SRC_QSPI4ERR (0x1424U)
#define OS_INIT_SRC_QSPI4PT (0x1425U)
#define OS_INIT_SRC_QSPI4U (0x1426U)
#define OS_INIT_SRC_GPSR10 (0x1427U)
#define OS_INIT_SRC_GTMATOM31 (0x1428U)
#define OS_INIT_SRC_GTMTIM03 (0x1429U)
#define OS_INIT_SRC_GTMTIM04 (0x142aU)
#define OS_INIT_SRC_GTMATOM03 (0x142bU)
#define OS_INIT_SRC_GTMATOM01 (0x142cU)
#define OS_INIT_SRC_GTMATOM02 (0x142dU)
#define OS_INIT_SRC_GTMATOM00 (0x142eU)
#define OS_INIT_SRC_GTMATOM30 (0x142fU)
#define OS_INIT_SRC_GTMATOM11 (0x1430U)
#define OS_INIT_SRC_GTMATOM12 (0x1431U)
#define OS_INIT_SRC_GTMATOM22 (0x1432U)
#define OS_INIT_SRC_GTMATOM13 (0x1433U)
#define OS_INIT_SRC_GTMATOM32 (0x1434U)
#define OS_INIT_SRC_GTMATOM23 (0x1435U)
#define OS_INIT_SRC_GTMTOM03 (0x1436U)
#define OS_INIT_SRC_GTMDPLL13 (0x1437U)
#define OS_INIT_SRC_GTMDPLL23 (0x1438U)
#define OS_INIT_SRC_GTMDPLL14 (0x1439U)
#define OS_INIT_SRC_GTMMCS00 (0x143aU)
#define OS_INIT_SRC_GTMTIM01 (0x143bU)
#define OS_INIT_SRC_GTMDPLL0 (0x143cU)
#define OS_INIT_SRC_GTMDPLL7 (0x143dU)
#define OS_INIT_SRC_GTMDPLL18 (0x143eU)
#define OS_INIT_SRC_GTMDPLL19 (0x143fU)
#define OS_INIT_SRC_GTMDPLL20 (0x1440U)
#define OS_INIT_SRC_GTMTIM00 (0x1441U)
#define OS_VEC_Os_CrossCoreISR2 (1U)
#define OS_CORE_Os_CrossCoreISR2 (2U)
#define OS_VEC_Os_CrossCoreISR1 (1U)
#define OS_CORE_Os_CrossCoreISR1 (1U)
#define OS_VEC_Os_CrossCoreISR0 (1U)
#define OS_CORE_Os_CrossCoreISR0 (0U)
#define OS_VEC_OsKRN_SCHEDULER_MANAGE_IT (2U)
#define OS_CORE_OsKRN_SCHEDULER_MANAGE_IT (2U)
#define OS_VEC_OsCJ135_U2450_ICU_IRQ_ISR (3U)
#define OS_CORE_OsCJ135_U2450_ICU_IRQ_ISR (2U)
#define OS_VEC_OsCJ135_U2450_GPT_IRQ_ISR (4U)
#define OS_CORE_OsCJ135_U2450_GPT_IRQ_ISR (2U)
#define OS_VEC_OsSRC_ASCLIN_ASCLIN1_ERR_ISR (5U)
#define OS_CORE_OsSRC_ASCLIN_ASCLIN1_ERR_ISR (1U)
#define OS_VEC_OsSRC_ASCLIN_ASCLIN1_RX_ISR (6U)
#define OS_CORE_OsSRC_ASCLIN_ASCLIN1_RX_ISR (1U)
#define OS_VEC_OsSRC_ASCLIN_ASCLIN1_TX_ISR (7U)
#define OS_CORE_OsSRC_ASCLIN_ASCLIN1_TX_ISR (1U)
#define OS_VEC_OsCAN_0_BUS_OFF (8U)
#define OS_CORE_OsCAN_0_BUS_OFF (1U)
#define OS_VEC_OsCAN_0_RECEIVE (9U)
#define OS_CORE_OsCAN_0_RECEIVE (1U)
#define OS_VEC_OsCAN_0_TRANSMIT (10U)
#define OS_CORE_OsCAN_0_TRANSMIT (1U)
#define OS_VEC_OsCAN_1_BUS_OFF (11U)
#define OS_CORE_OsCAN_1_BUS_OFF (1U)
#define OS_VEC_OsCAN_1_RECEIVE (12U)
#define OS_CORE_OsCAN_1_RECEIVE (1U)
#define OS_VEC_OsCAN_1_TRANSMIT (13U)
#define OS_CORE_OsCAN_1_TRANSMIT (1U)
#define OS_VEC_OsCAN_2_BUS_OFF (14U)
#define OS_CORE_OsCAN_2_BUS_OFF (1U)
#define OS_VEC_OsCAN_2_RECEIVE (15U)
#define OS_CORE_OsCAN_2_RECEIVE (1U)
#define OS_VEC_OsCAN_2_TRANSMIT (16U)
#define OS_CORE_OsCAN_2_TRANSMIT (1U)
#define OS_VEC_OsCAN_3_BUS_OFF (17U)
#define OS_CORE_OsCAN_3_BUS_OFF (1U)
#define OS_VEC_OsCAN_3_RECEIVE (18U)
#define OS_CORE_OsCAN_3_RECEIVE (1U)
#define OS_VEC_OsCAN_3_TRANSMIT (19U)
#define OS_CORE_OsCAN_3_TRANSMIT (1U)
#define OS_VEC_OsDMA_ISR_MSC0RX (20U)
#define OS_CORE_OsDMA_ISR_MSC0RX (2U)
#define OS_VEC_OsTHRHAL_PAP_PLUS_IT (21U)
#define OS_CORE_OsTHRHAL_PAP_PLUS_IT (2U)
#define OS_VEC_OsTLE8718_CMD_RX_TIMEOUT_IT (22U)
#define OS_CORE_OsTLE8718_CMD_RX_TIMEOUT_IT (2U)
#define OS_VEC_OsTLE8718_CMD_TX_IT (23U)
#define OS_CORE_OsTLE8718_CMD_TX_IT (2U)
#define OS_VEC_OsDMA_ISR_QSPI0RX (24U)
#define OS_CORE_OsDMA_ISR_QSPI0RX (2U)
#define OS_VEC_OsDMA_ISR_QSPI2RX (25U)
#define OS_CORE_OsDMA_ISR_QSPI2RX (2U)
#define OS_VEC_OsDMA_ISR_QSPI4RX (26U)
#define OS_CORE_OsDMA_ISR_QSPI4RX (2U)
#define OS_VEC_OsDMA_ISR_QSPI0TX (27U)
#define OS_CORE_OsDMA_ISR_QSPI0TX (2U)
#define OS_VEC_OsDMA_ISR_QSPI2TX (28U)
#define OS_CORE_OsDMA_ISR_QSPI2TX (2U)
#define OS_VEC_OsDMA_ISR_QSPI4TX (29U)
#define OS_CORE_OsDMA_ISR_QSPI4TX (2U)
#define OS_VEC_OsSRC_SPI0_ERR_ISR (30U)
#define OS_CORE_OsSRC_SPI0_ERR_ISR (2U)
#define OS_VEC_OsSRC_SPI0_PHASE_T_ISR (31U)
#define OS_CORE_OsSRC_SPI0_PHASE_T_ISR (2U)
#define OS_VEC_OsSRC_SPI0_USER_ISR (32U)
#define OS_CORE_OsSRC_SPI0_USER_ISR (2U)
#define OS_VEC_OsSRC_SPI2_ERR_ISR (33U)
#define OS_CORE_OsSRC_SPI2_ERR_ISR (2U)
#define OS_VEC_OsSRC_SPI2_PHASE_T_ISR (34U)
#define OS_CORE_OsSRC_SPI2_PHASE_T_ISR (2U)
#define OS_VEC_OsSRC_SPI2_USER_ISR (35U)
#define OS_CORE_OsSRC_SPI2_USER_ISR (2U)
#define OS_VEC_OsSRC_SPI4_ERR_ISR (36U)
#define OS_CORE_OsSRC_SPI4_ERR_ISR (2U)
#define OS_VEC_OsSRC_SPI4_PHASE_T_ISR (37U)
#define OS_CORE_OsSRC_SPI4_PHASE_T_ISR (2U)
#define OS_VEC_OsSRC_SPI4_USER_ISR (38U)
#define OS_CORE_OsSRC_SPI4_USER_ISR (2U)
#define OS_VEC_OsTSKSRV_ACTIVATION_MANAGER_IT (39U)
#define OS_CORE_OsTSKSRV_ACTIVATION_MANAGER_IT (2U)
#define OS_VEC_ANGSCHED_ANGULAR_ALARM_1 (40U)
#define OS_CORE_ANGSCHED_ANGULAR_ALARM_1 (2U)
#define OS_VEC_CAMHAL_ANGULAR_ALARM_EXHAUST (41U)
#define OS_CORE_CAMHAL_ANGULAR_ALARM_EXHAUST (2U)
#define OS_VEC_CAMHAL_ANGULAR_ALARM_INTAKE (42U)
#define OS_CORE_CAMHAL_ANGULAR_ALARM_INTAKE (2U)
#define OS_VEC_IGNHAL_ANGULAR_ALARM_COIL_A_CMD_AND_B_WDG (43U)
#define OS_CORE_IGNHAL_ANGULAR_ALARM_COIL_A_CMD_AND_B_WDG (2U)
#define OS_VEC_IGNHAL_ANGULAR_ALARM_COIL_B_CMD_AND_A_WDG (44U)
#define OS_CORE_IGNHAL_ANGULAR_ALARM_COIL_B_CMD_AND_A_WDG (2U)
#define OS_VEC_IGNHAL_ANGULAR_ALARM_COIL_C_CMD (45U)
#define OS_CORE_IGNHAL_ANGULAR_ALARM_COIL_C_CMD (2U)
#define OS_VEC_IGNHAL_ANGULAR_ALARM_COIL_C_WDG (46U)
#define OS_CORE_IGNHAL_ANGULAR_ALARM_COIL_C_WDG (2U)
#define OS_VEC_IGNHAL_ANGULAR_ALARM_IGN_REF_TEETH (47U)
#define OS_CORE_IGNHAL_ANGULAR_ALARM_IGN_REF_TEETH (2U)
#define OS_VEC_INJHAL_ANGULAR_ALARM_INJ_1_HP_PMP (48U)
#define OS_CORE_INJHAL_ANGULAR_ALARM_INJ_1_HP_PMP (2U)
#define OS_VEC_INJHAL_ANGULAR_ALARM_INJ_2_AND_INJ3 (49U)
#define OS_CORE_INJHAL_ANGULAR_ALARM_INJ_2_AND_INJ3 (2U)
#define OS_VEC_KNWHAL_ANGULAR_ALARM_KNW_SAMPLING_WIN (50U)
#define OS_CORE_KNWHAL_ANGULAR_ALARM_KNW_SAMPLING_WIN (2U)
#define OS_VEC_PMPHAL_DELAY (51U)
#define OS_CORE_PMPHAL_DELAY (2U)
#define OS_VEC_PTMHAL_ANGULAR_ALARM_SPILL_EVENT (52U)
#define OS_CORE_PTMHAL_ANGULAR_ALARM_SPILL_EVENT (2U)
#define OS_VEC_TDCHAL_ANGULAR_ALARM_TDC (53U)
#define OS_CORE_TDCHAL_ANGULAR_ALARM_TDC (2U)
#define OS_VEC_L9781_DELAY (54U)
#define OS_CORE_L9781_DELAY (2U)
#define OS_VEC_CRKHAL_DPLL_GET_LOCK (55U)
#define OS_CORE_CRKHAL_DPLL_GET_LOCK (2U)
#define OS_VEC_CRKHAL_CRK_ON_MANAGEMENT (56U)
#define OS_CORE_CRKHAL_CRK_ON_MANAGEMENT (2U)
#define OS_VEC_CRKHAL_DPLL_LOST_LOCK (57U)
#define OS_CORE_CRKHAL_DPLL_LOST_LOCK (2U)
#define OS_VEC_CRKHAL_TOOTH_TASK_MANAGEMENT (58U)
#define OS_CORE_CRKHAL_TOOTH_TASK_MANAGEMENT (2U)
#define OS_VEC_CRKHAL_TIM_CRK_INPUT_TO_MCS (59U)
#define OS_CORE_CRKHAL_TIM_CRK_INPUT_TO_MCS (2U)
#define OS_VEC_CRKHAL_DPLL_CHANGE_DIRECTION (60U)
#define OS_CORE_CRKHAL_DPLL_CHANGE_DIRECTION (2U)
#define OS_VEC_CRKHAL_DPLL_LONG_TOOTH (61U)
#define OS_CORE_CRKHAL_DPLL_LONG_TOOTH (2U)
#define OS_VEC_CRKHAL_START_OF_SYNC_WIN (62U)
#define OS_CORE_CRKHAL_START_OF_SYNC_WIN (2U)
#define OS_VEC_CRKHAL_SYNC_SEARCH_AND_CTRL (63U)
#define OS_CORE_CRKHAL_SYNC_SEARCH_AND_CTRL (2U)
#define OS_VEC_CRKHAL_UPDATE_INT_ANGULAR_OFFSET (64U)
#define OS_CORE_CRKHAL_UPDATE_INT_ANGULAR_OFFSET (2U)
#define OS_VEC_CRKHAL_TIM_CRK_INPUT_TO_DPLL (65U)
#define OS_CORE_CRKHAL_TIM_CRK_INPUT_TO_DPLL (2U)
#define Os_Core0_SRN (SRC_GPSR00)
DECLARE_CAT1_ISR(Os_CrossCoreISR0);
#define Os_Core1_SRN (SRC_GPSR01)
DECLARE_CAT1_ISR(Os_CrossCoreISR1);
#define Os_Core2_SRN (SRC_GPSR02)
DECLARE_CAT1_ISR(Os_CrossCoreISR2);
#define OS_NUM_SRNS (677U)
DECLARE_CAT1_ISR(ANGSCHED_ANGULAR_ALARM_1);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CAMHAL_ANGULAR_ALARM_EXHAUST);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CAMHAL_ANGULAR_ALARM_INTAKE);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(IGNHAL_ANGULAR_ALARM_COIL_A_CMD_AND_B_WDG);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(IGNHAL_ANGULAR_ALARM_COIL_B_CMD_AND_A_WDG);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(IGNHAL_ANGULAR_ALARM_COIL_C_CMD);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(IGNHAL_ANGULAR_ALARM_COIL_C_WDG);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(IGNHAL_ANGULAR_ALARM_IGN_REF_TEETH);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(INJHAL_ANGULAR_ALARM_INJ_1_HP_PMP);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(INJHAL_ANGULAR_ALARM_INJ_2_AND_INJ3);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(KNWHAL_ANGULAR_ALARM_KNW_SAMPLING_WIN);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(PMPHAL_DELAY);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(PTMHAL_ANGULAR_ALARM_SPILL_EVENT);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(TDCHAL_ANGULAR_ALARM_TDC);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(L9781_DELAY);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CRKHAL_DPLL_GET_LOCK);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CRKHAL_CRK_ON_MANAGEMENT);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CRKHAL_DPLL_LOST_LOCK);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CRKHAL_TOOTH_TASK_MANAGEMENT);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CRKHAL_TIM_CRK_INPUT_TO_MCS);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CRKHAL_DPLL_CHANGE_DIRECTION);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CRKHAL_DPLL_LONG_TOOTH);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CRKHAL_START_OF_SYNC_WIN);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CRKHAL_SYNC_SEARCH_AND_CTRL);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CRKHAL_UPDATE_INT_ANGULAR_OFFSET);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(CRKHAL_TIM_CRK_INPUT_TO_DPLL);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(SWFAIL_vidNotHandledISR);


#define OS_NUM_APPMODES (2U)
#define OS_NUM_APPLICATIONS (3U)
#define OS_NUM_SPINLOCKS (1U)
#define OS_NUM_TRUSTED_FUNCTIONS (0U)
#define OS_NUM_EVENTS (0U)
#define OS_NUM_TASKS (257U)
#define OS_NUM_ISRS (38U)
#define OS_NUM_RESOURCES (0U)
#define OS_NUM_ALARMS (0U)
#define OS_NUM_SCHEDULETABLES (1U)
#define OS_NUM_TRACEPOINTS (3U)
#define OS_NUM_TASKTRACEPOINTS (0U)
#define OS_NUM_INTERVALS (0U)
#define OS_NUM_TRACECATEGORIES (0U)
#define OS_TRACE_CATEGORY_ALWAYS ((Os_TraceCategoriesType)(0x80000000UL))
#define OS_TRACE_CATEGORY_NEVER  ((Os_TraceCategoriesType)(0x00000000UL))

/* [MISRA 2004 Rule 19.7] */ /*lint -estring(961, OS_TICKS2*) */
#define OS_NUM_COUNTERS (1U)
#define OSCYCLEDURATION (5) /* [$UKS 1224] */
#define OSCYCLESPERSECOND (200000000U) /* [$UKS 1225] */
#define OSSWTICKDURATION (5) /* [$UKS 1226] */
#define OSSWTICKSPERSECOND (200000000U) /* [$UKS 1227] */
#define OS_TICKS2NS_Schedule_table_counter(ticks) ((PhysicalTimeType)((ticks) * 500000U)) /* [$UKS 843] */
#define OS_TICKS2US_Schedule_table_counter(ticks) ((PhysicalTimeType)((ticks) * 500U)) /* [$UKS 843] */
#define OS_TICKS2MS_Schedule_table_counter(ticks) ((PhysicalTimeType)((ticks) / 2U)) /* [$UKS 843] */
#define OS_TICKS2SEC_Schedule_table_counter(ticks) ((PhysicalTimeType)((ticks) / 2000U)) /* [$UKS 843] */
#define OSMAXALLOWEDVALUE_Schedule_table_counter (8000U) /* [$UKS 219] */
#define OSTICKSPERBASE_Schedule_table_counter (1U) /* [$UKS 220] */
#define OSTICKDURATION_Schedule_table_counter OS_TICKS2NS_Schedule_table_counter(1U) /* [$UKS 221] */
#define OSMINCYCLE_Schedule_table_counter (0U) /* [$UKS 222] */
#define OSMAXALLOWEDVALUE OSMAXALLOWEDVALUE_SystemCounter /* [$UKS 215] */
#define OSTICKSPERBASE OSTICKSPERBASE_SystemCounter /* [$UKS 216] */
#define OSTICKDURATION OSTICKDURATION_SystemCounter /* [$UKS 217] */
#define OSMINCYCLE OSMINCYCLE_SystemCounter /* [$UKS 218] */
#define OS_NUM_CORES (3U)
#define OS_NUM_OS_CORES (3U)
#define OS_CORE_ID_MASTER (0U)  /* [$UKS 1609] */
/* [$UKS 1611] */
#define OS_CORE_ID_0 (0U)
#define OS_CORE_ID_1 (1U)
#define OS_CORE_ID_2 (2U)


/* ------------------------------------------------- */
/* [MISRA 2004 Rule 19.1] */ /*lint -save -esym(961, 19.1) */
#define OS_START_SEC_APPL_CODE
#include "MemMap.h" /* [MISRA 2004 Rule 19.15] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_RTMCLD_CPU_LOAD_MNG(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_RTMCLD2_CPU_LOAD_MNG(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_WTDG_REFRESH_WATCHDOG_BSW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_WTDG_REFRESH_WATCHDOG_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DUMMY_TIE_CORE0(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DUMMY_TIE_CORE1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DUMMY_TIE_CORE2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DUMMY_DRE_CORE0(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DUMMY_DRE_CORE1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DUMMY_DRE_CORE2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DUMMY_MSE_CORE0(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DUMMY_MSE_CORE1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DUMMY_MSE_CORE2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_INIT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_60000MS(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_60000MS_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_60000MS_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_4000MS(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_4000MS_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_4000MS_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2000MS(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2000MS_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2000MS_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_5(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_5_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_5_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_4(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_4_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_4_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_3(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_3_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_3_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_2_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_2_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_1_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_1000MS_1_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_400MS(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_400MS_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_400MS_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_4(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_4_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_4_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_3(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_3_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_3_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_2_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_2_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_1_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_200MS_1_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_100MS_3(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_100MS_3_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_100MS_3_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_100MS_2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_100MS_2_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_100MS_2_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_100MS_1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_100MS_1_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_100MS_1_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_50MS(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_50MS_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_50MS_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_5(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_5_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_5_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_4(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_4_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_4_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_3(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_3_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_3_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_2_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_2_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_1_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_40MS_1_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_5(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_5_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_5_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_4(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_4_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_4_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_3(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_3_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_3_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_2_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_2_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_1_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_20MS_1_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_9(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_9_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_9_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_8(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_8_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_8_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_7(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_7_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_7_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_6(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_6_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_6_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_5(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_5_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_5_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_4(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_4_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_4_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_3(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_3_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_3_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_2_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_2_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_1_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_10MS_1_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_5(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_5_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_5_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_4(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_4_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_4_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_3(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_3_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_3_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_2_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_2_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_1_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_5MS_1_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DEVAID_COMM_CAN(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_OILLV_EVENT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2_5MS_2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_FUNCTIONAL_TEST_END(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2_5MS_2_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2_5MS_2_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_CJ135_U2450_IRQ(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_FUNCTIONAL_TEST_ABORT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_FUNCTIONAL_TEST_START(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_L9960_SPIM(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_CJ135_U2450_SPIM(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TLE8718_MSCM_END_SEQ(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IGK_OFF(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IGK_OFF_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IGK_OFF_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IGK_ON(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IGK_ON_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IGK_ON_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_B_D(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_B_D_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_B_D_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_A_C(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_A_C_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_A_C_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_D(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_D_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_D_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_C(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_C_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_C_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_B(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_B_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_B_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_A(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_A_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_DIAG_COIL_A_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_EEST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_EEST_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_EEST_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_N_INV_OFF(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_N_INV_OFF_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_N_INV_OFF_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_CRK_OFF(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_CRK_OFF_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_CRK_OFF_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_N_INV(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_N_INV_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_N_INV_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_ENG_STAL(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_ENG_STAL_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_ENG_STAL_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TOLO(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TOLO_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TOLO_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_LTOO(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_LTOO_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_LTOO_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_LTOO1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_LTOO1_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_LTOO1_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_ENG_RUN(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_ENG_RUN_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_ENG_RUN_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_CRK_ON(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_CRK_ON_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_CRK_ON_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_KNK_WIN(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_KNK_WIN_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_KNK_WIN_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_EX_CAM_EDGE(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_EX_CAM_EDGE_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_EX_CAM_EDGE_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IN_CAM_EDGE(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IN_CAM_EDGE_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IN_CAM_EDGE_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_SPILL_EVENT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_SPILL_EVENT_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_SPILL_EVENT_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_EX_CAM_PERIOD(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_EX_CAM_PERIOD_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_EX_CAM_PERIOD_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IN_CAM_PERIOD(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IN_CAM_PERIOD_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_IN_CAM_PERIOD_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_PTMHAL_EVT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_PTMHAL_EVT_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_PTMHAL_EVT_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_BDC_2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_BDC_2_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_BDC_2_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_BDC_1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_BDC_1_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_BDC_1_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_INJ_EVENT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_INJ_EVENT_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_INJ_EVENT_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_ICLC_EVENT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_ICLC_EVENT_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_ICLC_EVENT_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TDC_2(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TDC_2_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TDC_2_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TDC_1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TDC_1_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TDC_1_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2_5MS_1(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2_5MS_1_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2_5MS_1_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2MS(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2MS_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_C_2MS_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_1_4_TDC(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_1_4_TDC_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_1_4_TDC_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TOOTH(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TOOTH_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_TOOTH_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_THR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_THR_ASW(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OSTSK_S_THR_POST(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsKRN_SCHEDULER_MANAGE_IT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCJ135_U2450_ICU_IRQ_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCJ135_U2450_GPT_IRQ_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_ASCLIN_ASCLIN1_ERR_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_ASCLIN_ASCLIN1_RX_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_ASCLIN_ASCLIN1_TX_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_0_BUS_OFF(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_0_RECEIVE(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_0_TRANSMIT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_1_BUS_OFF(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_1_RECEIVE(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_1_TRANSMIT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_2_BUS_OFF(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_2_RECEIVE(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_2_TRANSMIT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_3_BUS_OFF(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_3_RECEIVE(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsCAN_3_TRANSMIT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsDMA_ISR_MSC0RX(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsTHRHAL_PAP_PLUS_IT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsTLE8718_CMD_RX_TIMEOUT_IT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsTLE8718_CMD_TX_IT(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsDMA_ISR_QSPI0RX(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsDMA_ISR_QSPI2RX(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsDMA_ISR_QSPI4RX(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsDMA_ISR_QSPI0TX(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsDMA_ISR_QSPI2TX(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsDMA_ISR_QSPI4TX(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_SPI0_ERR_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_SPI0_PHASE_T_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_SPI0_USER_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_SPI2_ERR_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_SPI2_PHASE_T_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_SPI2_USER_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_SPI4_ERR_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_SPI4_PHASE_T_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsSRC_SPI4_USER_ISR(void);
extern FUNC(void, OS_APPL_CODE) Os_Entry_OsTSKSRV_ACTIVATION_MANAGER_IT(void);
/* [MISRA 2004 Rule 19.1] */ /*lint -save -esym(961, 19.1) */
#define OS_STOP_SEC_APPL_CODE
#include "MemMap.h" /* [MISRA 2004 Rule 19.15] */ /*lint !e537 !e451 */
/*lint -restore */

/* ------------------------------------------------- */
/* [MISRA 2004 Rule 19.1] */ /*lint -save -esym(961, 19.1) */
#define OS_START_SEC_CODE_LIB
#include "MemMap.h" /* [MISRA 2004 Rule 19.15] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(StatusType, OS_CODE) Os_IncrementCounter_Schedule_table_counter(void);
/* [MISRA 2004 Rule 19.1] */ /*lint -save -esym(961, 19.1) */
#define OS_STOP_SEC_CODE_LIB
#include "MemMap.h" /* [MISRA 2004 Rule 19.15] */ /*lint !e537 !e451 */
/*lint -restore */






/* -------- AppMode declarations --------- */
#define OS_NOAPPMODE ((AppModeType)0U)
#define OSDEFAULTAPPMODE ((AppModeType)1U)  /* [$UKS 381] [$UKS 383] */

/* ----- OS-Application declarations ----- */
#define Application_Core0 ((ApplicationType)1U) /* [$UKS 412] */
#define Application_Core1 ((ApplicationType)2U) /* [$UKS 412] */
#define Application_Core2 ((ApplicationType)3U) /* [$UKS 412] */

/* ----- Spinlock declarations ----- */
#define DGOHAL_Spinlock ((SpinlockIdType)1U)

/* -------- Event declarations --------- */

/* -------- Task declarations --------- */
#define OSTSK_S_RTMCLD_CPU_LOAD_MNG ((TaskType)(&Os_const_tasks[0U]))
DeclareTask(OSTSK_S_RTMCLD_CPU_LOAD_MNG)
#define OSTSK_S_RTMCLD2_CPU_LOAD_MNG ((TaskType)(&Os_const_tasks[1U]))
DeclareTask(OSTSK_S_RTMCLD2_CPU_LOAD_MNG)
#define OSTSK_S_WTDG_REFRESH_WATCHDOG_BSW ((TaskType)(&Os_const_tasks[2U]))
DeclareTask(OSTSK_S_WTDG_REFRESH_WATCHDOG_BSW)
#define OSTSK_S_WTDG_REFRESH_WATCHDOG_ASW ((TaskType)(&Os_const_tasks[3U]))
DeclareTask(OSTSK_S_WTDG_REFRESH_WATCHDOG_ASW)
#define OSTSK_S_DUMMY_TIE_CORE0 ((TaskType)(&Os_const_tasks[4U]))
DeclareTask(OSTSK_S_DUMMY_TIE_CORE0)
#define OSTSK_S_DUMMY_TIE_CORE1 ((TaskType)(&Os_const_tasks[5U]))
DeclareTask(OSTSK_S_DUMMY_TIE_CORE1)
#define OSTSK_S_DUMMY_TIE_CORE2 ((TaskType)(&Os_const_tasks[6U]))
DeclareTask(OSTSK_S_DUMMY_TIE_CORE2)
#define OSTSK_S_DUMMY_DRE_CORE0 ((TaskType)(&Os_const_tasks[7U]))
DeclareTask(OSTSK_S_DUMMY_DRE_CORE0)
#define OSTSK_S_DUMMY_DRE_CORE1 ((TaskType)(&Os_const_tasks[8U]))
DeclareTask(OSTSK_S_DUMMY_DRE_CORE1)
#define OSTSK_S_DUMMY_DRE_CORE2 ((TaskType)(&Os_const_tasks[9U]))
DeclareTask(OSTSK_S_DUMMY_DRE_CORE2)
#define OSTSK_S_DUMMY_MSE_CORE0 ((TaskType)(&Os_const_tasks[10U]))
DeclareTask(OSTSK_S_DUMMY_MSE_CORE0)
#define OSTSK_S_DUMMY_MSE_CORE1 ((TaskType)(&Os_const_tasks[11U]))
DeclareTask(OSTSK_S_DUMMY_MSE_CORE1)
#define OSTSK_S_DUMMY_MSE_CORE2 ((TaskType)(&Os_const_tasks[12U]))
DeclareTask(OSTSK_S_DUMMY_MSE_CORE2)
#define OSTSK_S_INIT ((TaskType)(&Os_const_tasks[13U]))
DeclareTask(OSTSK_S_INIT)
#define OSTSK_C_60000MS ((TaskType)(&Os_const_tasks[14U]))
DeclareTask(OSTSK_C_60000MS)
#define OSTSK_C_60000MS_ASW ((TaskType)(&Os_const_tasks[15U]))
DeclareTask(OSTSK_C_60000MS_ASW)
#define OSTSK_C_60000MS_POST ((TaskType)(&Os_const_tasks[16U]))
DeclareTask(OSTSK_C_60000MS_POST)
#define OSTSK_C_4000MS ((TaskType)(&Os_const_tasks[17U]))
DeclareTask(OSTSK_C_4000MS)
#define OSTSK_C_4000MS_ASW ((TaskType)(&Os_const_tasks[18U]))
DeclareTask(OSTSK_C_4000MS_ASW)
#define OSTSK_C_4000MS_POST ((TaskType)(&Os_const_tasks[19U]))
DeclareTask(OSTSK_C_4000MS_POST)
#define OSTSK_C_2000MS ((TaskType)(&Os_const_tasks[20U]))
DeclareTask(OSTSK_C_2000MS)
#define OSTSK_C_2000MS_ASW ((TaskType)(&Os_const_tasks[21U]))
DeclareTask(OSTSK_C_2000MS_ASW)
#define OSTSK_C_2000MS_POST ((TaskType)(&Os_const_tasks[22U]))
DeclareTask(OSTSK_C_2000MS_POST)
#define OSTSK_C_1000MS_5 ((TaskType)(&Os_const_tasks[23U]))
DeclareTask(OSTSK_C_1000MS_5)
#define OSTSK_C_1000MS_5_ASW ((TaskType)(&Os_const_tasks[24U]))
DeclareTask(OSTSK_C_1000MS_5_ASW)
#define OSTSK_C_1000MS_5_POST ((TaskType)(&Os_const_tasks[25U]))
DeclareTask(OSTSK_C_1000MS_5_POST)
#define OSTSK_C_1000MS_4 ((TaskType)(&Os_const_tasks[26U]))
DeclareTask(OSTSK_C_1000MS_4)
#define OSTSK_C_1000MS_4_ASW ((TaskType)(&Os_const_tasks[27U]))
DeclareTask(OSTSK_C_1000MS_4_ASW)
#define OSTSK_C_1000MS_4_POST ((TaskType)(&Os_const_tasks[28U]))
DeclareTask(OSTSK_C_1000MS_4_POST)
#define OSTSK_C_1000MS_3 ((TaskType)(&Os_const_tasks[29U]))
DeclareTask(OSTSK_C_1000MS_3)
#define OSTSK_C_1000MS_3_ASW ((TaskType)(&Os_const_tasks[30U]))
DeclareTask(OSTSK_C_1000MS_3_ASW)
#define OSTSK_C_1000MS_3_POST ((TaskType)(&Os_const_tasks[31U]))
DeclareTask(OSTSK_C_1000MS_3_POST)
#define OSTSK_C_1000MS_2 ((TaskType)(&Os_const_tasks[32U]))
DeclareTask(OSTSK_C_1000MS_2)
#define OSTSK_C_1000MS_2_ASW ((TaskType)(&Os_const_tasks[33U]))
DeclareTask(OSTSK_C_1000MS_2_ASW)
#define OSTSK_C_1000MS_2_POST ((TaskType)(&Os_const_tasks[34U]))
DeclareTask(OSTSK_C_1000MS_2_POST)
#define OSTSK_C_1000MS_1 ((TaskType)(&Os_const_tasks[35U]))
DeclareTask(OSTSK_C_1000MS_1)
#define OSTSK_C_1000MS_1_ASW ((TaskType)(&Os_const_tasks[36U]))
DeclareTask(OSTSK_C_1000MS_1_ASW)
#define OSTSK_C_1000MS_1_POST ((TaskType)(&Os_const_tasks[37U]))
DeclareTask(OSTSK_C_1000MS_1_POST)
#define OSTSK_C_400MS ((TaskType)(&Os_const_tasks[38U]))
DeclareTask(OSTSK_C_400MS)
#define OSTSK_C_400MS_ASW ((TaskType)(&Os_const_tasks[39U]))
DeclareTask(OSTSK_C_400MS_ASW)
#define OSTSK_C_400MS_POST ((TaskType)(&Os_const_tasks[40U]))
DeclareTask(OSTSK_C_400MS_POST)
#define OSTSK_C_200MS_4 ((TaskType)(&Os_const_tasks[41U]))
DeclareTask(OSTSK_C_200MS_4)
#define OSTSK_C_200MS_4_ASW ((TaskType)(&Os_const_tasks[42U]))
DeclareTask(OSTSK_C_200MS_4_ASW)
#define OSTSK_C_200MS_4_POST ((TaskType)(&Os_const_tasks[43U]))
DeclareTask(OSTSK_C_200MS_4_POST)
#define OSTSK_C_200MS_3 ((TaskType)(&Os_const_tasks[44U]))
DeclareTask(OSTSK_C_200MS_3)
#define OSTSK_C_200MS_3_ASW ((TaskType)(&Os_const_tasks[45U]))
DeclareTask(OSTSK_C_200MS_3_ASW)
#define OSTSK_C_200MS_3_POST ((TaskType)(&Os_const_tasks[46U]))
DeclareTask(OSTSK_C_200MS_3_POST)
#define OSTSK_C_200MS_2 ((TaskType)(&Os_const_tasks[47U]))
DeclareTask(OSTSK_C_200MS_2)
#define OSTSK_C_200MS_2_ASW ((TaskType)(&Os_const_tasks[48U]))
DeclareTask(OSTSK_C_200MS_2_ASW)
#define OSTSK_C_200MS_2_POST ((TaskType)(&Os_const_tasks[49U]))
DeclareTask(OSTSK_C_200MS_2_POST)
#define OSTSK_C_200MS_1 ((TaskType)(&Os_const_tasks[50U]))
DeclareTask(OSTSK_C_200MS_1)
#define OSTSK_C_200MS_1_ASW ((TaskType)(&Os_const_tasks[51U]))
DeclareTask(OSTSK_C_200MS_1_ASW)
#define OSTSK_C_200MS_1_POST ((TaskType)(&Os_const_tasks[52U]))
DeclareTask(OSTSK_C_200MS_1_POST)
#define OSTSK_C_100MS_3 ((TaskType)(&Os_const_tasks[53U]))
DeclareTask(OSTSK_C_100MS_3)
#define OSTSK_C_100MS_3_ASW ((TaskType)(&Os_const_tasks[54U]))
DeclareTask(OSTSK_C_100MS_3_ASW)
#define OSTSK_C_100MS_3_POST ((TaskType)(&Os_const_tasks[55U]))
DeclareTask(OSTSK_C_100MS_3_POST)
#define OSTSK_C_100MS_2 ((TaskType)(&Os_const_tasks[56U]))
DeclareTask(OSTSK_C_100MS_2)
#define OSTSK_C_100MS_2_ASW ((TaskType)(&Os_const_tasks[57U]))
DeclareTask(OSTSK_C_100MS_2_ASW)
#define OSTSK_C_100MS_2_POST ((TaskType)(&Os_const_tasks[58U]))
DeclareTask(OSTSK_C_100MS_2_POST)
#define OSTSK_C_100MS_1 ((TaskType)(&Os_const_tasks[59U]))
DeclareTask(OSTSK_C_100MS_1)
#define OSTSK_C_100MS_1_ASW ((TaskType)(&Os_const_tasks[60U]))
DeclareTask(OSTSK_C_100MS_1_ASW)
#define OSTSK_C_100MS_1_POST ((TaskType)(&Os_const_tasks[61U]))
DeclareTask(OSTSK_C_100MS_1_POST)
#define OSTSK_C_50MS ((TaskType)(&Os_const_tasks[62U]))
DeclareTask(OSTSK_C_50MS)
#define OSTSK_C_50MS_ASW ((TaskType)(&Os_const_tasks[63U]))
DeclareTask(OSTSK_C_50MS_ASW)
#define OSTSK_C_50MS_POST ((TaskType)(&Os_const_tasks[64U]))
DeclareTask(OSTSK_C_50MS_POST)
#define OSTSK_C_40MS_5 ((TaskType)(&Os_const_tasks[65U]))
DeclareTask(OSTSK_C_40MS_5)
#define OSTSK_C_40MS_5_ASW ((TaskType)(&Os_const_tasks[66U]))
DeclareTask(OSTSK_C_40MS_5_ASW)
#define OSTSK_C_40MS_5_POST ((TaskType)(&Os_const_tasks[67U]))
DeclareTask(OSTSK_C_40MS_5_POST)
#define OSTSK_C_40MS_4 ((TaskType)(&Os_const_tasks[68U]))
DeclareTask(OSTSK_C_40MS_4)
#define OSTSK_C_40MS_4_ASW ((TaskType)(&Os_const_tasks[69U]))
DeclareTask(OSTSK_C_40MS_4_ASW)
#define OSTSK_C_40MS_4_POST ((TaskType)(&Os_const_tasks[70U]))
DeclareTask(OSTSK_C_40MS_4_POST)
#define OSTSK_C_40MS_3 ((TaskType)(&Os_const_tasks[71U]))
DeclareTask(OSTSK_C_40MS_3)
#define OSTSK_C_40MS_3_ASW ((TaskType)(&Os_const_tasks[72U]))
DeclareTask(OSTSK_C_40MS_3_ASW)
#define OSTSK_C_40MS_3_POST ((TaskType)(&Os_const_tasks[73U]))
DeclareTask(OSTSK_C_40MS_3_POST)
#define OSTSK_C_40MS_2 ((TaskType)(&Os_const_tasks[74U]))
DeclareTask(OSTSK_C_40MS_2)
#define OSTSK_C_40MS_2_ASW ((TaskType)(&Os_const_tasks[75U]))
DeclareTask(OSTSK_C_40MS_2_ASW)
#define OSTSK_C_40MS_2_POST ((TaskType)(&Os_const_tasks[76U]))
DeclareTask(OSTSK_C_40MS_2_POST)
#define OSTSK_C_40MS_1 ((TaskType)(&Os_const_tasks[77U]))
DeclareTask(OSTSK_C_40MS_1)
#define OSTSK_C_40MS_1_ASW ((TaskType)(&Os_const_tasks[78U]))
DeclareTask(OSTSK_C_40MS_1_ASW)
#define OSTSK_C_40MS_1_POST ((TaskType)(&Os_const_tasks[79U]))
DeclareTask(OSTSK_C_40MS_1_POST)
#define OSTSK_C_20MS_5 ((TaskType)(&Os_const_tasks[80U]))
DeclareTask(OSTSK_C_20MS_5)
#define OSTSK_C_20MS_5_ASW ((TaskType)(&Os_const_tasks[81U]))
DeclareTask(OSTSK_C_20MS_5_ASW)
#define OSTSK_C_20MS_5_POST ((TaskType)(&Os_const_tasks[82U]))
DeclareTask(OSTSK_C_20MS_5_POST)
#define OSTSK_C_20MS_4 ((TaskType)(&Os_const_tasks[83U]))
DeclareTask(OSTSK_C_20MS_4)
#define OSTSK_C_20MS_4_ASW ((TaskType)(&Os_const_tasks[84U]))
DeclareTask(OSTSK_C_20MS_4_ASW)
#define OSTSK_C_20MS_4_POST ((TaskType)(&Os_const_tasks[85U]))
DeclareTask(OSTSK_C_20MS_4_POST)
#define OSTSK_C_20MS_3 ((TaskType)(&Os_const_tasks[86U]))
DeclareTask(OSTSK_C_20MS_3)
#define OSTSK_C_20MS_3_ASW ((TaskType)(&Os_const_tasks[87U]))
DeclareTask(OSTSK_C_20MS_3_ASW)
#define OSTSK_C_20MS_3_POST ((TaskType)(&Os_const_tasks[88U]))
DeclareTask(OSTSK_C_20MS_3_POST)
#define OSTSK_C_20MS_2 ((TaskType)(&Os_const_tasks[89U]))
DeclareTask(OSTSK_C_20MS_2)
#define OSTSK_C_20MS_2_ASW ((TaskType)(&Os_const_tasks[90U]))
DeclareTask(OSTSK_C_20MS_2_ASW)
#define OSTSK_C_20MS_2_POST ((TaskType)(&Os_const_tasks[91U]))
DeclareTask(OSTSK_C_20MS_2_POST)
#define OSTSK_C_20MS_1 ((TaskType)(&Os_const_tasks[92U]))
DeclareTask(OSTSK_C_20MS_1)
#define OSTSK_C_20MS_1_ASW ((TaskType)(&Os_const_tasks[93U]))
DeclareTask(OSTSK_C_20MS_1_ASW)
#define OSTSK_C_20MS_1_POST ((TaskType)(&Os_const_tasks[94U]))
DeclareTask(OSTSK_C_20MS_1_POST)
#define OSTSK_C_10MS_9 ((TaskType)(&Os_const_tasks[95U]))
DeclareTask(OSTSK_C_10MS_9)
#define OSTSK_C_10MS_9_ASW ((TaskType)(&Os_const_tasks[96U]))
DeclareTask(OSTSK_C_10MS_9_ASW)
#define OSTSK_C_10MS_9_POST ((TaskType)(&Os_const_tasks[97U]))
DeclareTask(OSTSK_C_10MS_9_POST)
#define OSTSK_C_10MS_8 ((TaskType)(&Os_const_tasks[98U]))
DeclareTask(OSTSK_C_10MS_8)
#define OSTSK_C_10MS_8_ASW ((TaskType)(&Os_const_tasks[99U]))
DeclareTask(OSTSK_C_10MS_8_ASW)
#define OSTSK_C_10MS_8_POST ((TaskType)(&Os_const_tasks[100U]))
DeclareTask(OSTSK_C_10MS_8_POST)
#define OSTSK_C_10MS_7 ((TaskType)(&Os_const_tasks[101U]))
DeclareTask(OSTSK_C_10MS_7)
#define OSTSK_C_10MS_7_ASW ((TaskType)(&Os_const_tasks[102U]))
DeclareTask(OSTSK_C_10MS_7_ASW)
#define OSTSK_C_10MS_7_POST ((TaskType)(&Os_const_tasks[103U]))
DeclareTask(OSTSK_C_10MS_7_POST)
#define OSTSK_C_10MS_6 ((TaskType)(&Os_const_tasks[104U]))
DeclareTask(OSTSK_C_10MS_6)
#define OSTSK_C_10MS_6_ASW ((TaskType)(&Os_const_tasks[105U]))
DeclareTask(OSTSK_C_10MS_6_ASW)
#define OSTSK_C_10MS_6_POST ((TaskType)(&Os_const_tasks[106U]))
DeclareTask(OSTSK_C_10MS_6_POST)
#define OSTSK_C_10MS_5 ((TaskType)(&Os_const_tasks[107U]))
DeclareTask(OSTSK_C_10MS_5)
#define OSTSK_C_10MS_5_ASW ((TaskType)(&Os_const_tasks[108U]))
DeclareTask(OSTSK_C_10MS_5_ASW)
#define OSTSK_C_10MS_5_POST ((TaskType)(&Os_const_tasks[109U]))
DeclareTask(OSTSK_C_10MS_5_POST)
#define OSTSK_C_10MS_4 ((TaskType)(&Os_const_tasks[110U]))
DeclareTask(OSTSK_C_10MS_4)
#define OSTSK_C_10MS_4_ASW ((TaskType)(&Os_const_tasks[111U]))
DeclareTask(OSTSK_C_10MS_4_ASW)
#define OSTSK_C_10MS_4_POST ((TaskType)(&Os_const_tasks[112U]))
DeclareTask(OSTSK_C_10MS_4_POST)
#define OSTSK_C_10MS_3 ((TaskType)(&Os_const_tasks[113U]))
DeclareTask(OSTSK_C_10MS_3)
#define OSTSK_C_10MS_3_ASW ((TaskType)(&Os_const_tasks[114U]))
DeclareTask(OSTSK_C_10MS_3_ASW)
#define OSTSK_C_10MS_3_POST ((TaskType)(&Os_const_tasks[115U]))
DeclareTask(OSTSK_C_10MS_3_POST)
#define OSTSK_C_10MS_2 ((TaskType)(&Os_const_tasks[116U]))
DeclareTask(OSTSK_C_10MS_2)
#define OSTSK_C_10MS_2_ASW ((TaskType)(&Os_const_tasks[117U]))
DeclareTask(OSTSK_C_10MS_2_ASW)
#define OSTSK_C_10MS_2_POST ((TaskType)(&Os_const_tasks[118U]))
DeclareTask(OSTSK_C_10MS_2_POST)
#define OSTSK_C_10MS_1 ((TaskType)(&Os_const_tasks[119U]))
DeclareTask(OSTSK_C_10MS_1)
#define OSTSK_C_10MS_1_ASW ((TaskType)(&Os_const_tasks[120U]))
DeclareTask(OSTSK_C_10MS_1_ASW)
#define OSTSK_C_10MS_1_POST ((TaskType)(&Os_const_tasks[121U]))
DeclareTask(OSTSK_C_10MS_1_POST)
#define OSTSK_C_5MS_5 ((TaskType)(&Os_const_tasks[122U]))
DeclareTask(OSTSK_C_5MS_5)
#define OSTSK_C_5MS_5_ASW ((TaskType)(&Os_const_tasks[123U]))
DeclareTask(OSTSK_C_5MS_5_ASW)
#define OSTSK_C_5MS_5_POST ((TaskType)(&Os_const_tasks[124U]))
DeclareTask(OSTSK_C_5MS_5_POST)
#define OSTSK_C_5MS_4 ((TaskType)(&Os_const_tasks[125U]))
DeclareTask(OSTSK_C_5MS_4)
#define OSTSK_C_5MS_4_ASW ((TaskType)(&Os_const_tasks[126U]))
DeclareTask(OSTSK_C_5MS_4_ASW)
#define OSTSK_C_5MS_4_POST ((TaskType)(&Os_const_tasks[127U]))
DeclareTask(OSTSK_C_5MS_4_POST)
#define OSTSK_C_5MS_3 ((TaskType)(&Os_const_tasks[128U]))
DeclareTask(OSTSK_C_5MS_3)
#define OSTSK_C_5MS_3_ASW ((TaskType)(&Os_const_tasks[129U]))
DeclareTask(OSTSK_C_5MS_3_ASW)
#define OSTSK_C_5MS_3_POST ((TaskType)(&Os_const_tasks[130U]))
DeclareTask(OSTSK_C_5MS_3_POST)
#define OSTSK_C_5MS_2 ((TaskType)(&Os_const_tasks[131U]))
DeclareTask(OSTSK_C_5MS_2)
#define OSTSK_C_5MS_2_ASW ((TaskType)(&Os_const_tasks[132U]))
DeclareTask(OSTSK_C_5MS_2_ASW)
#define OSTSK_C_5MS_2_POST ((TaskType)(&Os_const_tasks[133U]))
DeclareTask(OSTSK_C_5MS_2_POST)
#define OSTSK_C_5MS_1 ((TaskType)(&Os_const_tasks[134U]))
DeclareTask(OSTSK_C_5MS_1)
#define OSTSK_C_5MS_1_ASW ((TaskType)(&Os_const_tasks[135U]))
DeclareTask(OSTSK_C_5MS_1_ASW)
#define OSTSK_C_5MS_1_POST ((TaskType)(&Os_const_tasks[136U]))
DeclareTask(OSTSK_C_5MS_1_POST)
#define OSTSK_S_DEVAID_COMM_CAN ((TaskType)(&Os_const_tasks[137U]))
DeclareTask(OSTSK_S_DEVAID_COMM_CAN)
#define OSTSK_S_OILLV_EVENT ((TaskType)(&Os_const_tasks[138U]))
DeclareTask(OSTSK_S_OILLV_EVENT)
#define OSTSK_C_2_5MS_2 ((TaskType)(&Os_const_tasks[139U]))
DeclareTask(OSTSK_C_2_5MS_2)
#define OSTSK_S_FUNCTIONAL_TEST_END ((TaskType)(&Os_const_tasks[140U]))
DeclareTask(OSTSK_S_FUNCTIONAL_TEST_END)
#define OSTSK_C_2_5MS_2_ASW ((TaskType)(&Os_const_tasks[141U]))
DeclareTask(OSTSK_C_2_5MS_2_ASW)
#define OSTSK_C_2_5MS_2_POST ((TaskType)(&Os_const_tasks[142U]))
DeclareTask(OSTSK_C_2_5MS_2_POST)
#define OSTSK_S_CJ135_U2450_IRQ ((TaskType)(&Os_const_tasks[143U]))
DeclareTask(OSTSK_S_CJ135_U2450_IRQ)
#define OSTSK_S_FUNCTIONAL_TEST_ABORT ((TaskType)(&Os_const_tasks[144U]))
DeclareTask(OSTSK_S_FUNCTIONAL_TEST_ABORT)
#define OSTSK_S_FUNCTIONAL_TEST_START ((TaskType)(&Os_const_tasks[145U]))
DeclareTask(OSTSK_S_FUNCTIONAL_TEST_START)
#define OSTSK_S_L9960_SPIM ((TaskType)(&Os_const_tasks[146U]))
DeclareTask(OSTSK_S_L9960_SPIM)
#define OSTSK_S_CJ135_U2450_SPIM ((TaskType)(&Os_const_tasks[147U]))
DeclareTask(OSTSK_S_CJ135_U2450_SPIM)
#define OSTSK_S_TLE8718_MSCM_END_SEQ ((TaskType)(&Os_const_tasks[148U]))
DeclareTask(OSTSK_S_TLE8718_MSCM_END_SEQ)
#define OSTSK_S_IGK_OFF ((TaskType)(&Os_const_tasks[149U]))
DeclareTask(OSTSK_S_IGK_OFF)
#define OSTSK_S_IGK_OFF_ASW ((TaskType)(&Os_const_tasks[150U]))
DeclareTask(OSTSK_S_IGK_OFF_ASW)
#define OSTSK_S_IGK_OFF_POST ((TaskType)(&Os_const_tasks[151U]))
DeclareTask(OSTSK_S_IGK_OFF_POST)
#define OSTSK_S_IGK_ON ((TaskType)(&Os_const_tasks[152U]))
DeclareTask(OSTSK_S_IGK_ON)
#define OSTSK_S_IGK_ON_ASW ((TaskType)(&Os_const_tasks[153U]))
DeclareTask(OSTSK_S_IGK_ON_ASW)
#define OSTSK_S_IGK_ON_POST ((TaskType)(&Os_const_tasks[154U]))
DeclareTask(OSTSK_S_IGK_ON_POST)
#define OSTSK_S_DIAG_COIL_B_D ((TaskType)(&Os_const_tasks[155U]))
DeclareTask(OSTSK_S_DIAG_COIL_B_D)
#define OSTSK_S_DIAG_COIL_B_D_ASW ((TaskType)(&Os_const_tasks[156U]))
DeclareTask(OSTSK_S_DIAG_COIL_B_D_ASW)
#define OSTSK_S_DIAG_COIL_B_D_POST ((TaskType)(&Os_const_tasks[157U]))
DeclareTask(OSTSK_S_DIAG_COIL_B_D_POST)
#define OSTSK_S_DIAG_COIL_A_C ((TaskType)(&Os_const_tasks[158U]))
DeclareTask(OSTSK_S_DIAG_COIL_A_C)
#define OSTSK_S_DIAG_COIL_A_C_ASW ((TaskType)(&Os_const_tasks[159U]))
DeclareTask(OSTSK_S_DIAG_COIL_A_C_ASW)
#define OSTSK_S_DIAG_COIL_A_C_POST ((TaskType)(&Os_const_tasks[160U]))
DeclareTask(OSTSK_S_DIAG_COIL_A_C_POST)
#define OSTSK_S_DIAG_COIL_D ((TaskType)(&Os_const_tasks[161U]))
DeclareTask(OSTSK_S_DIAG_COIL_D)
#define OSTSK_S_DIAG_COIL_D_ASW ((TaskType)(&Os_const_tasks[162U]))
DeclareTask(OSTSK_S_DIAG_COIL_D_ASW)
#define OSTSK_S_DIAG_COIL_D_POST ((TaskType)(&Os_const_tasks[163U]))
DeclareTask(OSTSK_S_DIAG_COIL_D_POST)
#define OSTSK_S_DIAG_COIL_C ((TaskType)(&Os_const_tasks[164U]))
DeclareTask(OSTSK_S_DIAG_COIL_C)
#define OSTSK_S_DIAG_COIL_C_ASW ((TaskType)(&Os_const_tasks[165U]))
DeclareTask(OSTSK_S_DIAG_COIL_C_ASW)
#define OSTSK_S_DIAG_COIL_C_POST ((TaskType)(&Os_const_tasks[166U]))
DeclareTask(OSTSK_S_DIAG_COIL_C_POST)
#define OSTSK_S_DIAG_COIL_B ((TaskType)(&Os_const_tasks[167U]))
DeclareTask(OSTSK_S_DIAG_COIL_B)
#define OSTSK_S_DIAG_COIL_B_ASW ((TaskType)(&Os_const_tasks[168U]))
DeclareTask(OSTSK_S_DIAG_COIL_B_ASW)
#define OSTSK_S_DIAG_COIL_B_POST ((TaskType)(&Os_const_tasks[169U]))
DeclareTask(OSTSK_S_DIAG_COIL_B_POST)
#define OSTSK_S_DIAG_COIL_A ((TaskType)(&Os_const_tasks[170U]))
DeclareTask(OSTSK_S_DIAG_COIL_A)
#define OSTSK_S_DIAG_COIL_A_ASW ((TaskType)(&Os_const_tasks[171U]))
DeclareTask(OSTSK_S_DIAG_COIL_A_ASW)
#define OSTSK_S_DIAG_COIL_A_POST ((TaskType)(&Os_const_tasks[172U]))
DeclareTask(OSTSK_S_DIAG_COIL_A_POST)
#define OSTSK_S_EEST ((TaskType)(&Os_const_tasks[173U]))
DeclareTask(OSTSK_S_EEST)
#define OSTSK_S_EEST_ASW ((TaskType)(&Os_const_tasks[174U]))
DeclareTask(OSTSK_S_EEST_ASW)
#define OSTSK_S_EEST_POST ((TaskType)(&Os_const_tasks[175U]))
DeclareTask(OSTSK_S_EEST_POST)
#define OSTSK_S_N_INV_OFF ((TaskType)(&Os_const_tasks[176U]))
DeclareTask(OSTSK_S_N_INV_OFF)
#define OSTSK_S_N_INV_OFF_ASW ((TaskType)(&Os_const_tasks[177U]))
DeclareTask(OSTSK_S_N_INV_OFF_ASW)
#define OSTSK_S_N_INV_OFF_POST ((TaskType)(&Os_const_tasks[178U]))
DeclareTask(OSTSK_S_N_INV_OFF_POST)
#define OSTSK_S_CRK_OFF ((TaskType)(&Os_const_tasks[179U]))
DeclareTask(OSTSK_S_CRK_OFF)
#define OSTSK_S_CRK_OFF_ASW ((TaskType)(&Os_const_tasks[180U]))
DeclareTask(OSTSK_S_CRK_OFF_ASW)
#define OSTSK_S_CRK_OFF_POST ((TaskType)(&Os_const_tasks[181U]))
DeclareTask(OSTSK_S_CRK_OFF_POST)
#define OSTSK_S_N_INV ((TaskType)(&Os_const_tasks[182U]))
DeclareTask(OSTSK_S_N_INV)
#define OSTSK_S_N_INV_ASW ((TaskType)(&Os_const_tasks[183U]))
DeclareTask(OSTSK_S_N_INV_ASW)
#define OSTSK_S_N_INV_POST ((TaskType)(&Os_const_tasks[184U]))
DeclareTask(OSTSK_S_N_INV_POST)
#define OSTSK_S_ENG_STAL ((TaskType)(&Os_const_tasks[185U]))
DeclareTask(OSTSK_S_ENG_STAL)
#define OSTSK_S_ENG_STAL_ASW ((TaskType)(&Os_const_tasks[186U]))
DeclareTask(OSTSK_S_ENG_STAL_ASW)
#define OSTSK_S_ENG_STAL_POST ((TaskType)(&Os_const_tasks[187U]))
DeclareTask(OSTSK_S_ENG_STAL_POST)
#define OSTSK_S_TOLO ((TaskType)(&Os_const_tasks[188U]))
DeclareTask(OSTSK_S_TOLO)
#define OSTSK_S_TOLO_ASW ((TaskType)(&Os_const_tasks[189U]))
DeclareTask(OSTSK_S_TOLO_ASW)
#define OSTSK_S_TOLO_POST ((TaskType)(&Os_const_tasks[190U]))
DeclareTask(OSTSK_S_TOLO_POST)
#define OSTSK_S_LTOO ((TaskType)(&Os_const_tasks[191U]))
DeclareTask(OSTSK_S_LTOO)
#define OSTSK_S_LTOO_ASW ((TaskType)(&Os_const_tasks[192U]))
DeclareTask(OSTSK_S_LTOO_ASW)
#define OSTSK_S_LTOO_POST ((TaskType)(&Os_const_tasks[193U]))
DeclareTask(OSTSK_S_LTOO_POST)
#define OSTSK_S_LTOO1 ((TaskType)(&Os_const_tasks[194U]))
DeclareTask(OSTSK_S_LTOO1)
#define OSTSK_S_LTOO1_ASW ((TaskType)(&Os_const_tasks[195U]))
DeclareTask(OSTSK_S_LTOO1_ASW)
#define OSTSK_S_LTOO1_POST ((TaskType)(&Os_const_tasks[196U]))
DeclareTask(OSTSK_S_LTOO1_POST)
#define OSTSK_S_ENG_RUN ((TaskType)(&Os_const_tasks[197U]))
DeclareTask(OSTSK_S_ENG_RUN)
#define OSTSK_S_ENG_RUN_ASW ((TaskType)(&Os_const_tasks[198U]))
DeclareTask(OSTSK_S_ENG_RUN_ASW)
#define OSTSK_S_ENG_RUN_POST ((TaskType)(&Os_const_tasks[199U]))
DeclareTask(OSTSK_S_ENG_RUN_POST)
#define OSTSK_S_CRK_ON ((TaskType)(&Os_const_tasks[200U]))
DeclareTask(OSTSK_S_CRK_ON)
#define OSTSK_S_CRK_ON_ASW ((TaskType)(&Os_const_tasks[201U]))
DeclareTask(OSTSK_S_CRK_ON_ASW)
#define OSTSK_S_CRK_ON_POST ((TaskType)(&Os_const_tasks[202U]))
DeclareTask(OSTSK_S_CRK_ON_POST)
#define OSTSK_S_KNK_WIN ((TaskType)(&Os_const_tasks[203U]))
DeclareTask(OSTSK_S_KNK_WIN)
#define OSTSK_S_KNK_WIN_ASW ((TaskType)(&Os_const_tasks[204U]))
DeclareTask(OSTSK_S_KNK_WIN_ASW)
#define OSTSK_S_KNK_WIN_POST ((TaskType)(&Os_const_tasks[205U]))
DeclareTask(OSTSK_S_KNK_WIN_POST)
#define OSTSK_S_EX_CAM_EDGE ((TaskType)(&Os_const_tasks[206U]))
DeclareTask(OSTSK_S_EX_CAM_EDGE)
#define OSTSK_S_EX_CAM_EDGE_ASW ((TaskType)(&Os_const_tasks[207U]))
DeclareTask(OSTSK_S_EX_CAM_EDGE_ASW)
#define OSTSK_S_EX_CAM_EDGE_POST ((TaskType)(&Os_const_tasks[208U]))
DeclareTask(OSTSK_S_EX_CAM_EDGE_POST)
#define OSTSK_S_IN_CAM_EDGE ((TaskType)(&Os_const_tasks[209U]))
DeclareTask(OSTSK_S_IN_CAM_EDGE)
#define OSTSK_S_IN_CAM_EDGE_ASW ((TaskType)(&Os_const_tasks[210U]))
DeclareTask(OSTSK_S_IN_CAM_EDGE_ASW)
#define OSTSK_S_IN_CAM_EDGE_POST ((TaskType)(&Os_const_tasks[211U]))
DeclareTask(OSTSK_S_IN_CAM_EDGE_POST)
#define OSTSK_S_SPILL_EVENT ((TaskType)(&Os_const_tasks[212U]))
DeclareTask(OSTSK_S_SPILL_EVENT)
#define OSTSK_S_SPILL_EVENT_ASW ((TaskType)(&Os_const_tasks[213U]))
DeclareTask(OSTSK_S_SPILL_EVENT_ASW)
#define OSTSK_S_SPILL_EVENT_POST ((TaskType)(&Os_const_tasks[214U]))
DeclareTask(OSTSK_S_SPILL_EVENT_POST)
#define OSTSK_S_EX_CAM_PERIOD ((TaskType)(&Os_const_tasks[215U]))
DeclareTask(OSTSK_S_EX_CAM_PERIOD)
#define OSTSK_S_EX_CAM_PERIOD_ASW ((TaskType)(&Os_const_tasks[216U]))
DeclareTask(OSTSK_S_EX_CAM_PERIOD_ASW)
#define OSTSK_S_EX_CAM_PERIOD_POST ((TaskType)(&Os_const_tasks[217U]))
DeclareTask(OSTSK_S_EX_CAM_PERIOD_POST)
#define OSTSK_S_IN_CAM_PERIOD ((TaskType)(&Os_const_tasks[218U]))
DeclareTask(OSTSK_S_IN_CAM_PERIOD)
#define OSTSK_S_IN_CAM_PERIOD_ASW ((TaskType)(&Os_const_tasks[219U]))
DeclareTask(OSTSK_S_IN_CAM_PERIOD_ASW)
#define OSTSK_S_IN_CAM_PERIOD_POST ((TaskType)(&Os_const_tasks[220U]))
DeclareTask(OSTSK_S_IN_CAM_PERIOD_POST)
#define OSTSK_S_PTMHAL_EVT ((TaskType)(&Os_const_tasks[221U]))
DeclareTask(OSTSK_S_PTMHAL_EVT)
#define OSTSK_S_PTMHAL_EVT_ASW ((TaskType)(&Os_const_tasks[222U]))
DeclareTask(OSTSK_S_PTMHAL_EVT_ASW)
#define OSTSK_S_PTMHAL_EVT_POST ((TaskType)(&Os_const_tasks[223U]))
DeclareTask(OSTSK_S_PTMHAL_EVT_POST)
#define OSTSK_S_BDC_2 ((TaskType)(&Os_const_tasks[224U]))
DeclareTask(OSTSK_S_BDC_2)
#define OSTSK_S_BDC_2_ASW ((TaskType)(&Os_const_tasks[225U]))
DeclareTask(OSTSK_S_BDC_2_ASW)
#define OSTSK_S_BDC_2_POST ((TaskType)(&Os_const_tasks[226U]))
DeclareTask(OSTSK_S_BDC_2_POST)
#define OSTSK_S_BDC_1 ((TaskType)(&Os_const_tasks[227U]))
DeclareTask(OSTSK_S_BDC_1)
#define OSTSK_S_BDC_1_ASW ((TaskType)(&Os_const_tasks[228U]))
DeclareTask(OSTSK_S_BDC_1_ASW)
#define OSTSK_S_BDC_1_POST ((TaskType)(&Os_const_tasks[229U]))
DeclareTask(OSTSK_S_BDC_1_POST)
#define OSTSK_S_INJ_EVENT ((TaskType)(&Os_const_tasks[230U]))
DeclareTask(OSTSK_S_INJ_EVENT)
#define OSTSK_S_INJ_EVENT_ASW ((TaskType)(&Os_const_tasks[231U]))
DeclareTask(OSTSK_S_INJ_EVENT_ASW)
#define OSTSK_S_INJ_EVENT_POST ((TaskType)(&Os_const_tasks[232U]))
DeclareTask(OSTSK_S_INJ_EVENT_POST)
#define OSTSK_S_ICLC_EVENT ((TaskType)(&Os_const_tasks[233U]))
DeclareTask(OSTSK_S_ICLC_EVENT)
#define OSTSK_S_ICLC_EVENT_ASW ((TaskType)(&Os_const_tasks[234U]))
DeclareTask(OSTSK_S_ICLC_EVENT_ASW)
#define OSTSK_S_ICLC_EVENT_POST ((TaskType)(&Os_const_tasks[235U]))
DeclareTask(OSTSK_S_ICLC_EVENT_POST)
#define OSTSK_S_TDC_2 ((TaskType)(&Os_const_tasks[236U]))
DeclareTask(OSTSK_S_TDC_2)
#define OSTSK_S_TDC_2_ASW ((TaskType)(&Os_const_tasks[237U]))
DeclareTask(OSTSK_S_TDC_2_ASW)
#define OSTSK_S_TDC_2_POST ((TaskType)(&Os_const_tasks[238U]))
DeclareTask(OSTSK_S_TDC_2_POST)
#define OSTSK_S_TDC_1 ((TaskType)(&Os_const_tasks[239U]))
DeclareTask(OSTSK_S_TDC_1)
#define OSTSK_S_TDC_1_ASW ((TaskType)(&Os_const_tasks[240U]))
DeclareTask(OSTSK_S_TDC_1_ASW)
#define OSTSK_S_TDC_1_POST ((TaskType)(&Os_const_tasks[241U]))
DeclareTask(OSTSK_S_TDC_1_POST)
#define OSTSK_C_2_5MS_1 ((TaskType)(&Os_const_tasks[242U]))
DeclareTask(OSTSK_C_2_5MS_1)
#define OSTSK_C_2_5MS_1_ASW ((TaskType)(&Os_const_tasks[243U]))
DeclareTask(OSTSK_C_2_5MS_1_ASW)
#define OSTSK_C_2_5MS_1_POST ((TaskType)(&Os_const_tasks[244U]))
DeclareTask(OSTSK_C_2_5MS_1_POST)
#define OSTSK_C_2MS ((TaskType)(&Os_const_tasks[245U]))
DeclareTask(OSTSK_C_2MS)
#define OSTSK_C_2MS_ASW ((TaskType)(&Os_const_tasks[246U]))
DeclareTask(OSTSK_C_2MS_ASW)
#define OSTSK_C_2MS_POST ((TaskType)(&Os_const_tasks[247U]))
DeclareTask(OSTSK_C_2MS_POST)
#define OSTSK_S_1_4_TDC ((TaskType)(&Os_const_tasks[248U]))
DeclareTask(OSTSK_S_1_4_TDC)
#define OSTSK_S_1_4_TDC_ASW ((TaskType)(&Os_const_tasks[249U]))
DeclareTask(OSTSK_S_1_4_TDC_ASW)
#define OSTSK_S_1_4_TDC_POST ((TaskType)(&Os_const_tasks[250U]))
DeclareTask(OSTSK_S_1_4_TDC_POST)
#define OSTSK_S_TOOTH ((TaskType)(&Os_const_tasks[251U]))
DeclareTask(OSTSK_S_TOOTH)
#define OSTSK_S_TOOTH_ASW ((TaskType)(&Os_const_tasks[252U]))
DeclareTask(OSTSK_S_TOOTH_ASW)
#define OSTSK_S_TOOTH_POST ((TaskType)(&Os_const_tasks[253U]))
DeclareTask(OSTSK_S_TOOTH_POST)
#define OSTSK_S_THR ((TaskType)(&Os_const_tasks[254U]))
DeclareTask(OSTSK_S_THR)
#define OSTSK_S_THR_ASW ((TaskType)(&Os_const_tasks[255U]))
DeclareTask(OSTSK_S_THR_ASW)
#define OSTSK_S_THR_POST ((TaskType)(&Os_const_tasks[256U]))
DeclareTask(OSTSK_S_THR_POST)

/* -------- ISR declarations --------- */
#define OsKRN_SCHEDULER_MANAGE_IT ((ISRType)(&Os_const_isrs[0U]))
DeclareISR(OsKRN_SCHEDULER_MANAGE_IT)
#define OsCJ135_U2450_ICU_IRQ_ISR ((ISRType)(&Os_const_isrs[1U]))
DeclareISR(OsCJ135_U2450_ICU_IRQ_ISR)
#define OsCJ135_U2450_GPT_IRQ_ISR ((ISRType)(&Os_const_isrs[2U]))
DeclareISR(OsCJ135_U2450_GPT_IRQ_ISR)
#define OsSRC_ASCLIN_ASCLIN1_ERR_ISR ((ISRType)(&Os_const_isrs[3U]))
DeclareISR(OsSRC_ASCLIN_ASCLIN1_ERR_ISR)
#define OsSRC_ASCLIN_ASCLIN1_RX_ISR ((ISRType)(&Os_const_isrs[4U]))
DeclareISR(OsSRC_ASCLIN_ASCLIN1_RX_ISR)
#define OsSRC_ASCLIN_ASCLIN1_TX_ISR ((ISRType)(&Os_const_isrs[5U]))
DeclareISR(OsSRC_ASCLIN_ASCLIN1_TX_ISR)
#define OsCAN_0_BUS_OFF ((ISRType)(&Os_const_isrs[6U]))
DeclareISR(OsCAN_0_BUS_OFF)
#define OsCAN_0_RECEIVE ((ISRType)(&Os_const_isrs[7U]))
DeclareISR(OsCAN_0_RECEIVE)
#define OsCAN_0_TRANSMIT ((ISRType)(&Os_const_isrs[8U]))
DeclareISR(OsCAN_0_TRANSMIT)
#define OsCAN_1_BUS_OFF ((ISRType)(&Os_const_isrs[9U]))
DeclareISR(OsCAN_1_BUS_OFF)
#define OsCAN_1_RECEIVE ((ISRType)(&Os_const_isrs[10U]))
DeclareISR(OsCAN_1_RECEIVE)
#define OsCAN_1_TRANSMIT ((ISRType)(&Os_const_isrs[11U]))
DeclareISR(OsCAN_1_TRANSMIT)
#define OsCAN_2_BUS_OFF ((ISRType)(&Os_const_isrs[12U]))
DeclareISR(OsCAN_2_BUS_OFF)
#define OsCAN_2_RECEIVE ((ISRType)(&Os_const_isrs[13U]))
DeclareISR(OsCAN_2_RECEIVE)
#define OsCAN_2_TRANSMIT ((ISRType)(&Os_const_isrs[14U]))
DeclareISR(OsCAN_2_TRANSMIT)
#define OsCAN_3_BUS_OFF ((ISRType)(&Os_const_isrs[15U]))
DeclareISR(OsCAN_3_BUS_OFF)
#define OsCAN_3_RECEIVE ((ISRType)(&Os_const_isrs[16U]))
DeclareISR(OsCAN_3_RECEIVE)
#define OsCAN_3_TRANSMIT ((ISRType)(&Os_const_isrs[17U]))
DeclareISR(OsCAN_3_TRANSMIT)
#define OsDMA_ISR_MSC0RX ((ISRType)(&Os_const_isrs[18U]))
DeclareISR(OsDMA_ISR_MSC0RX)
#define OsTHRHAL_PAP_PLUS_IT ((ISRType)(&Os_const_isrs[19U]))
DeclareISR(OsTHRHAL_PAP_PLUS_IT)
#define OsTLE8718_CMD_RX_TIMEOUT_IT ((ISRType)(&Os_const_isrs[20U]))
DeclareISR(OsTLE8718_CMD_RX_TIMEOUT_IT)
#define OsTLE8718_CMD_TX_IT ((ISRType)(&Os_const_isrs[21U]))
DeclareISR(OsTLE8718_CMD_TX_IT)
#define OsDMA_ISR_QSPI0RX ((ISRType)(&Os_const_isrs[22U]))
DeclareISR(OsDMA_ISR_QSPI0RX)
#define OsDMA_ISR_QSPI2RX ((ISRType)(&Os_const_isrs[23U]))
DeclareISR(OsDMA_ISR_QSPI2RX)
#define OsDMA_ISR_QSPI4RX ((ISRType)(&Os_const_isrs[24U]))
DeclareISR(OsDMA_ISR_QSPI4RX)
#define OsDMA_ISR_QSPI0TX ((ISRType)(&Os_const_isrs[25U]))
DeclareISR(OsDMA_ISR_QSPI0TX)
#define OsDMA_ISR_QSPI2TX ((ISRType)(&Os_const_isrs[26U]))
DeclareISR(OsDMA_ISR_QSPI2TX)
#define OsDMA_ISR_QSPI4TX ((ISRType)(&Os_const_isrs[27U]))
DeclareISR(OsDMA_ISR_QSPI4TX)
#define OsSRC_SPI0_ERR_ISR ((ISRType)(&Os_const_isrs[28U]))
DeclareISR(OsSRC_SPI0_ERR_ISR)
#define OsSRC_SPI0_PHASE_T_ISR ((ISRType)(&Os_const_isrs[29U]))
DeclareISR(OsSRC_SPI0_PHASE_T_ISR)
#define OsSRC_SPI0_USER_ISR ((ISRType)(&Os_const_isrs[30U]))
DeclareISR(OsSRC_SPI0_USER_ISR)
#define OsSRC_SPI2_ERR_ISR ((ISRType)(&Os_const_isrs[31U]))
DeclareISR(OsSRC_SPI2_ERR_ISR)
#define OsSRC_SPI2_PHASE_T_ISR ((ISRType)(&Os_const_isrs[32U]))
DeclareISR(OsSRC_SPI2_PHASE_T_ISR)
#define OsSRC_SPI2_USER_ISR ((ISRType)(&Os_const_isrs[33U]))
DeclareISR(OsSRC_SPI2_USER_ISR)
#define OsSRC_SPI4_ERR_ISR ((ISRType)(&Os_const_isrs[34U]))
DeclareISR(OsSRC_SPI4_ERR_ISR)
#define OsSRC_SPI4_PHASE_T_ISR ((ISRType)(&Os_const_isrs[35U]))
DeclareISR(OsSRC_SPI4_PHASE_T_ISR)
#define OsSRC_SPI4_USER_ISR ((ISRType)(&Os_const_isrs[36U]))
DeclareISR(OsSRC_SPI4_USER_ISR)
#define OsTSKSRV_ACTIVATION_MANAGER_IT ((ISRType)(&Os_const_isrs[37U]))
DeclareISR(OsTSKSRV_ACTIVATION_MANAGER_IT)

/* -------- Resource declarations --------- */

/* -------- Counter declarations --------- */
#define Schedule_table_counter (&Os_const_counters[0U])
DeclareCounter(Schedule_table_counter)

/* -------- Alarm declaration --------- */

/* -------- ScheduleTable declaration --------- */

#define toto (&Os_const_scheduletables[0U])
#define OS_DURATION_toto (8000U)
DeclareScheduleTable(toto)

/* -------- Tracepoint declarations --------- */
#define OSApp_Application_Core0 (1U)
#define OSApp_Application_Core1 (2U)
#define OSApp_Application_Core2 (3U)

/* -------- TaskTracepoint declarations --------- */

/* -------- Interval declarations --------- */

/* -------- Filtered APIs --------- */
#define Os_LogTracepoint(TpointID,Category) /* never */
#define Os_LogTracepointValue(TpointID,Value,Category) /* never */
#define Os_LogTracepointData(TpointID,Data,Length,Category) /* never */
#define Os_LogTaskTracepoint(TTpointID,Category) /* never */
#define Os_LogTaskTracepointValue(TTpointID,Value,Category) /* never */
#define Os_LogTaskTracepointData(TTpointID,Data,Length,Category) /* never */
#define Os_LogIntervalStart(IntervalID,Category) /* never */
#define Os_LogIntervalStartValue(IntervalID,Value,Category) /* never */
#define Os_LogIntervalStartData(IntervalID,Data,Length,Category) /* never */
#define Os_LogIntervalEnd(IntervalID,Category) /* never */
#define Os_LogIntervalEndValue(IntervalID,Value,Category) /* never */
#define Os_LogIntervalEndData(IntervalID,Data,Length,Category) /* never */
#ifndef OS_TRACE_NAMESPACE_PURE /* [$UKS 1154] */
/* [MISRA 2004 Rule 19.7] */ /*lint -estring(961, LogTrace* ,LogTaskTrace* ,LogInterval*) */  #define LogTracepoint(TpointID,Category) Os_LogTracepoint(TpointID,Category)
  #define LogTracepointValue(TpointID,Value,Category) Os_LogTracepointValue(TpointID,Value,Category)
  #define LogTracepointData(TpointID,Data,Length,Category) Os_LogTracepointData(TpointID,Data,Length,Category)
  #define LogTaskTracepoint(TTpointID,Category) Os_LogTaskTracepoint(TTpointID,Category)
  #define LogTaskTracepointValue(TTpointID,Value,Category) Os_LogTaskTracepointValue(TTpointID,Value,Category)
  #define LogTaskTracepointData(TTpointID,Data,Length,Category) Os_LogTaskTracepointData(TTpointID,Data,Length,Category)
  #define LogIntervalStart(IntervalID,Category) Os_LogIntervalStart(IntervalID,Category)
  #define LogIntervalStartValue(IntervalID,Value,Category) Os_LogIntervalStartValue(IntervalID,Value,Category)
  #define LogIntervalStartData(IntervalID,Data,Length,Category) Os_LogIntervalStartData(IntervalID,Data,Length,Category)
  #define LogIntervalEnd(IntervalID,Category) Os_LogIntervalEnd(IntervalID,Category)
  #define LogIntervalEndValue(IntervalID,Value,Category) Os_LogIntervalEndValue(IntervalID,Value,Category)
  #define LogIntervalEndData(IntervalID,Data,Length,Category) Os_LogIntervalEndData(IntervalID,Data,Length,Category)
#endif

#define Os_Cat1_ANGSCHED_ANGULAR_ALARM_1 (297U)
#define Os_Cat1_CAMHAL_ANGULAR_ALARM_EXHAUST (298U)
#define Os_Cat1_CAMHAL_ANGULAR_ALARM_INTAKE (299U)
#define Os_Cat1_IGNHAL_ANGULAR_ALARM_COIL_A_CMD_AND_B_WDG (300U)
#define Os_Cat1_IGNHAL_ANGULAR_ALARM_COIL_B_CMD_AND_A_WDG (301U)
#define Os_Cat1_IGNHAL_ANGULAR_ALARM_COIL_C_CMD (302U)
#define Os_Cat1_IGNHAL_ANGULAR_ALARM_COIL_C_WDG (303U)
#define Os_Cat1_IGNHAL_ANGULAR_ALARM_IGN_REF_TEETH (304U)
#define Os_Cat1_INJHAL_ANGULAR_ALARM_INJ_1_HP_PMP (305U)
#define Os_Cat1_INJHAL_ANGULAR_ALARM_INJ_2_AND_INJ3 (306U)
#define Os_Cat1_KNWHAL_ANGULAR_ALARM_KNW_SAMPLING_WIN (307U)
#define Os_Cat1_PMPHAL_DELAY (308U)
#define Os_Cat1_PTMHAL_ANGULAR_ALARM_SPILL_EVENT (309U)
#define Os_Cat1_TDCHAL_ANGULAR_ALARM_TDC (310U)
#define Os_Cat1_L9781_DELAY (311U)
#define Os_Cat1_CRKHAL_DPLL_GET_LOCK (312U)
#define Os_Cat1_CRKHAL_CRK_ON_MANAGEMENT (313U)
#define Os_Cat1_CRKHAL_DPLL_LOST_LOCK (314U)
#define Os_Cat1_CRKHAL_TOOTH_TASK_MANAGEMENT (315U)
#define Os_Cat1_CRKHAL_TIM_CRK_INPUT_TO_MCS (316U)
#define Os_Cat1_CRKHAL_DPLL_CHANGE_DIRECTION (317U)
#define Os_Cat1_CRKHAL_DPLL_LONG_TOOTH (318U)
#define Os_Cat1_CRKHAL_START_OF_SYNC_WIN (319U)
#define Os_Cat1_CRKHAL_SYNC_SEARCH_AND_CTRL (320U)
#define Os_Cat1_CRKHAL_UPDATE_INT_ANGULAR_OFFSET (321U)
#define Os_Cat1_CRKHAL_TIM_CRK_INPUT_TO_DPLL (322U)
/* [MISRA 2004 Rule 19.12] */ /*lint -save -esym(960, 19.12) */
/* [MISRA 2004 Rule 19.13] */ /*lint -save -esym(961, 19.13) */
#define Os_LogCat1ISRStart(IsrId)  /* [$UKS 1036] [$UKS 1037] [$UKS 1177] */
/*lint -restore */
/*lint -restore */
/* [MISRA 2004 Rule 19.12] */ /*lint -save -esym(960, 19.12) */
/* [MISRA 2004 Rule 19.13] */ /*lint -save -esym(961, 19.13) */
#define Os_LogCat1ISREnd(IsrId)  /* [$UKS 1038] [$UKS 1039] [$UKS 1178] */
/*lint -restore */
/*lint -restore */

#ifndef OS_TRACE_NAMESPACE_PURE /* [$UKS 1154] */
  #define LogCat1ISRStart Os_LogCat1ISRStart
  #define LogCat1ISREnd Os_LogCat1ISREnd
#endif
#endif /* OS_CFG_H */

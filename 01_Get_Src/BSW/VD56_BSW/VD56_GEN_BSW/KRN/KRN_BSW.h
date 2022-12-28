/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_BSW.h                                               */
/* !Description     : Defines BSW macros directly called by the tasks         */
/*                                                                            */
/* !Reference       : V03 NT 08 06774                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192555.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/


#ifndef KRN_BSW_H
#define KRN_BSW_H

#define KRN_START_SEC_CODE
#include "KRN_MemMap.h"

void KRN_vidInit(void);
void KRN_vidINIT_BSW_PRE(void);
void KRN_vidINIT_BSW_POST(void);
void KRN_vidS_INIT_BSW_PRE(void);
void KRN_vidC_2MS_BSW_PRE(void);
void KRN_vidC_2MS_BSW_POST(void);
void KRN_vidC_2_5MS_1_BSW_PRE(void);
void KRN_vidC_2_5MS_1_BSW_POST(void);
void KRN_vidC_2_5MS_2_BSW_PRE(void);
void KRN_vidC_2_5MS_2_BSW_POST(void);
void KRN_vidC_5MS_1_BSW_PRE(void);
void KRN_vidC_5MS_1_BSW_POST(void);
void KRN_vidC_5MS_2_BSW_PRE(void);
void KRN_vidC_5MS_2_BSW_POST(void);
void KRN_vidC_5MS_3_BSW_PRE(void);
void KRN_vidC_5MS_3_BSW_POST(void);
void KRN_vidC_5MS_4_BSW_PRE(void);
void KRN_vidC_5MS_4_BSW_POST(void);
void KRN_vidC_5MS_5_BSW_PRE(void);
void KRN_vidC_5MS_5_BSW_POST(void);
void KRN_vidC_10MS_1_BSW_PRE(void);
void KRN_vidC_10MS_1_BSW_POST(void);
void KRN_vidC_10MS_2_BSW_PRE(void);
void KRN_vidC_10MS_2_BSW_POST(void);
void KRN_vidC_10MS_3_BSW_PRE(void);
void KRN_vidC_10MS_3_BSW_POST(void);
void KRN_vidC_10MS_4_BSW_PRE(void);
void KRN_vidC_10MS_4_BSW_POST(void);
void KRN_vidC_10MS_5_BSW_PRE(void);
void KRN_vidC_10MS_5_BSW_POST(void);
void KRN_vidC_10MS_6_BSW_PRE(void);
void KRN_vidC_10MS_6_BSW_POST(void);
void KRN_vidC_10MS_7_BSW_PRE(void);
void KRN_vidC_10MS_7_BSW_POST(void);
void KRN_vidC_10MS_8_BSW_PRE(void);
void KRN_vidC_10MS_8_BSW_POST(void);
void KRN_vidC_10MS_9_BSW_PRE(void);
void KRN_vidC_10MS_9_BSW_POST(void);
void KRN_vidC_20MS_1_BSW_PRE(void);
void KRN_vidC_20MS_1_BSW_POST(void);
void KRN_vidC_20MS_2_BSW_PRE(void);
void KRN_vidC_20MS_2_BSW_POST(void);
void KRN_vidC_20MS_3_BSW_PRE(void);
void KRN_vidC_20MS_3_BSW_POST(void);
void KRN_vidC_20MS_4_BSW_PRE(void);
void KRN_vidC_20MS_4_BSW_POST(void);
void KRN_vidC_20MS_5_BSW_PRE(void);
void KRN_vidC_20MS_5_BSW_POST(void);
void KRN_vidC_40MS_1_BSW_PRE(void);
void KRN_vidC_40MS_1_BSW_POST(void);
void KRN_vidC_40MS_2_BSW_PRE(void);
void KRN_vidC_40MS_2_BSW_POST(void);
void KRN_vidC_40MS_3_BSW_PRE(void);
void KRN_vidC_40MS_3_BSW_POST(void);
void KRN_vidC_40MS_4_BSW_PRE(void);
void KRN_vidC_40MS_4_BSW_POST(void);
void KRN_vidC_40MS_5_BSW_PRE(void);
void KRN_vidC_40MS_5_BSW_POST(void);
void KRN_vidC_50MS_BSW_PRE(void);
void KRN_vidC_50MS_BSW_POST(void);
void KRN_vidC_100MS_1_BSW_PRE(void);
void KRN_vidC_100MS_1_BSW_POST(void);
void KRN_vidC_100MS_2_BSW_PRE(void);
void KRN_vidC_100MS_2_BSW_POST(void);
void KRN_vidC_100MS_3_BSW_PRE(void);
void KRN_vidC_100MS_3_BSW_POST(void);
void KRN_vidC_200MS_1_BSW_PRE(void);
void KRN_vidC_200MS_1_BSW_POST(void);
void KRN_vidC_200MS_2_BSW_PRE(void);
void KRN_vidC_200MS_2_BSW_POST(void);
void KRN_vidC_200MS_3_BSW_PRE(void);
void KRN_vidC_200MS_3_BSW_POST(void);
void KRN_vidC_200MS_4_BSW_PRE(void);
void KRN_vidC_200MS_4_BSW_POST(void);
void KRN_vidC_400MS_BSW_PRE(void);
void KRN_vidC_400MS_BSW_POST(void);
void KRN_vidC_1000MS_1_BSW_PRE(void);
void KRN_vidC_1000MS_1_BSW_POST(void);
void KRN_vidC_1000MS_2_BSW_PRE(void);
void KRN_vidC_1000MS_2_BSW_POST(void);
void KRN_vidC_1000MS_3_BSW_PRE(void);
void KRN_vidC_1000MS_3_BSW_POST(void);
void KRN_vidC_1000MS_4_BSW_PRE(void);
void KRN_vidC_1000MS_4_BSW_POST(void);
void KRN_vidC_1000MS_5_BSW_PRE(void);
void KRN_vidC_1000MS_5_BSW_POST(void);
void KRN_vidC_2000MS_BSW_PRE(void);
void KRN_vidC_2000MS_BSW_POST(void);
void KRN_vidC_4000MS_BSW_PRE(void);
void KRN_vidC_4000MS_BSW_POST(void);
void KRN_vidC_60000MS_BSW_PRE(void);
void KRN_vidC_60000MS_BSW_POST(void);
void KRN_vidS_TDC_BSW_PRE(void);
void KRN_vidS_TDC_BSW_POST(void);
void KRN_vidS_TDC_1_BSW_PRE(void);
void KRN_vidS_TDC_1_BSW_POST(void);
void KRN_vidS_TDC_2_BSW_PRE(void);
void KRN_vidS_TDC_2_BSW_POST(void);
void KRN_vidS_BDC_BSW_PRE(void);
void KRN_vidS_BDC_BSW_POST(void);
void KRN_vidS_BDC_1_BSW_PRE(void);
void KRN_vidS_BDC_1_BSW_POST(void);
void KRN_vidS_BDC_2_BSW_PRE(void);
void KRN_vidS_BDC_2_BSW_POST(void);
void KRN_vidS_KNK_WIN_BSW_PRE(void);
void KRN_vidS_KNK_WIN_BSW_POST(void);
void KRN_vidS_CRK_ON_BSW_PRE(void);
void KRN_vidS_CRK_ON_BSW_POST(void);
void KRN_vidS_ENG_RUN_BSW_PRE(void);
void KRN_vidS_ENG_RUN_BSW_POST(void);
void KRN_vidS_LTOO1_BSW_PRE(void);
void KRN_vidS_LTOO1_BSW_POST(void);
void KRN_vidS_LTOO_BSW_PRE(void);
void KRN_vidS_LTOO_BSW_POST(void);
void KRN_vidS_TOLO_INTERRUPT_BSW(void);
void KRN_vidS_TOLO_BSW_PRE(void);
void KRN_vidS_TOLO_BSW_POST(void);
void KRN_vidS_ENG_STAL_BSW_PRE(void);
void KRN_vidS_ENG_STAL_BSW_POST(void);
void KRN_vidS_CRK_OFF_BSW_PRE(void);
void KRN_vidS_CRK_OFF_BSW_POST(void);
void KRN_vidS_DIAG_COIL_A_BSW_PRE(void);
void KRN_vidS_DIAG_COIL_A_BSW_POST(void);
void KRN_vidS_DIAG_COIL_B_BSW_PRE(void);
void KRN_vidS_DIAG_COIL_B_BSW_POST(void);
void KRN_vidS_DIAG_COIL_C_BSW_PRE(void);
void KRN_vidS_DIAG_COIL_C_BSW_POST(void);
void KRN_vidS_DIAG_COIL_D_BSW_PRE(void);
void KRN_vidS_DIAG_COIL_D_BSW_POST(void);
void KRN_vidS_DIAG_COIL_A_C_BSW_PRE(void);
void KRN_vidS_DIAG_COIL_A_C_BSW_POST(void);
void KRN_vidS_DIAG_COIL_B_D_BSW_PRE(void);
void KRN_vidS_DIAG_COIL_B_D_BSW_POST(void);
void KRN_vidINCAM_DOWN_MODE_BSW_PRE(void);
void KRN_vidINCAM_NORMAL_MODE_BSW_PRE(void);
void KRN_vidEXCAM_DOWN_MODE_BSW_PRE(void);
void KRN_vidEXCAM_NORMAL_MODE_BSW_PRE(void);
void KRN_vidS_1_4_TDC_BSW_PRE(void);
void KRN_vidS_1_4_TDC_BSW_POST(void);
void KRN_vidCRK_DOWN_MODE_BSW_PRE(void);
void KRN_vidCRK_NORMAL_MODE_BSW_PRE(void);
void KRN_vidS_IGK_ON_BSW_PRE(void);
void KRN_vidS_IGK_ON_BSW_POST(void);
void KRN_vidS_IGK_OFF_BSW_PRE(void);
void KRN_vidS_IGK_OFF_BSW_POST(void);
void KRN_vidS_EEST_BSW_PRE(void);
void KRN_vidS_EEST_BSW_POST(void);
void KRN_vidS_THR_BSW_PRE(void);
void KRN_vidS_THR_BSW_POST(void);
void KRN_vidS_SPILL_EVENT_BSW_PRE(void);
void KRN_vidS_SPILL_EVENT_BSW_POST(void);
void KRN_vidS_N_INV_BSW_PRE(void);
void KRN_vidS_N_INV_BSW_POST(void);
void KRN_vidS_N_INV_OFF_BSW_PRE(void);
void KRN_vidS_N_INV_OFF_BSW_POST(void);
void KRN_vidS_TOOTH_BSW_PRE(void);
void KRN_vidS_TOOTH_BSW_POST(void);
void KRN_vidS_IN_CAM_EDGE_BSW_PRE(void);
void KRN_vidS_IN_CAM_EDGE_BSW_POST(void);
void KRN_vidS_IN_CAM_PERIOD_BSW_PRE(void);
void KRN_vidS_IN_CAM_PERIOD_BSW_POST(void);
void KRN_vidS_EX_CAM_EDGE_BSW_PRE(void);
void KRN_vidS_EX_CAM_EDGE_BSW_POST(void);
void KRN_vidS_EX_CAM_PERIOD_BSW_PRE(void);
void KRN_vidS_EX_CAM_PERIOD_BSW_POST(void);
void KRN_vidS_INJ_EVENT_BSW_PRE(void);
void KRN_vidS_INJ_EVENT_BSW_POST(void);
void KRN_vidS_PTMHAL_EVT_BSW_PRE(void);
void KRN_vidS_PTMHAL_EVT_BSW_POST(void);
void KRN_vidS_WTDG_REFRESH_WATCHDOG_BSW_PRE(void);
void KRN_vidS_WTDG_REFRESH_WATCHDOG_ASW_PRE(void);
void KRN_vidS_DEVAID_COMM_CAN_BSW_PRE(void);
void KRN_vidS_ICLC_EVENT_BSW_PRE(void);
void KRN_vidS_ICLC_EVENT_BSW_POST(void);

#define KRN_STOP_SEC_CODE
#include "KRN_MemMap.h"

#endif /* KRN_BSW_H */

/*-------------------------------- end of file -------------------------------*/

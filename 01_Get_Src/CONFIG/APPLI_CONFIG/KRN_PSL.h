/******************************************************************************/
/* !Layer           : APPLI                                                   */
/* !Component       : KRN                                                     */
/* !Description     : Kernel Layer                                            */
/*                                                                            */
/* !File            : KRN_PSL.h                                               */
/* !Description     : Defines ASW macros directly called by the tasks         */
/*                                                                            */
/* !Reference       : PTS_DOC_XXXXXXX                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A93483.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/


#ifndef KRN_PSL_H
#define KRN_PSL_H

#define TST_START_SEC_TST_CODE
#include "TST_MemMap.h"

void KRN_vidC_2MS_PSL_PRE(void);
void KRN_vidC_2MS_PSL_POST(void);
void KRN_vidC_2_5MS_1_PSL_PRE(void);
void KRN_vidC_2_5MS_1_PSL_POST(void);
void KRN_vidC_2_5MS_2_PSL_PRE(void);
void KRN_vidC_2_5MS_2_PSL_POST(void);
void KRN_vidC_5MS_1_PSL_PRE(void);
void KRN_vidC_5MS_1_PSL_POST(void);
void KRN_vidC_5MS_2_PSL_PRE(void);
void KRN_vidC_5MS_2_PSL_POST(void);
void KRN_vidC_5MS_3_PSL_PRE(void);
void KRN_vidC_5MS_3_PSL_POST(void);
void KRN_vidC_5MS_4_PSL_PRE(void);
void KRN_vidC_5MS_4_PSL_POST(void);
void KRN_vidC_5MS_5_PSL_PRE(void);
void KRN_vidC_5MS_5_PSL_POST(void);
void KRN_vidC_10MS_1_PSL_PRE(void);
void KRN_vidC_10MS_1_PSL_POST(void);
void KRN_vidC_10MS_2_PSL_PRE(void);
void KRN_vidC_10MS_2_PSL_POST(void);
void KRN_vidC_10MS_3_PSL_PRE(void);
void KRN_vidC_10MS_3_PSL_POST(void);
void KRN_vidC_10MS_4_PSL_PRE(void);
void KRN_vidC_10MS_4_PSL_POST(void);
void KRN_vidC_10MS_5_PSL_PRE(void);
void KRN_vidC_10MS_5_PSL_POST(void);
void KRN_vidC_10MS_6_PSL_PRE(void);
void KRN_vidC_10MS_6_PSL_POST(void);
void KRN_vidC_10MS_7_PSL_PRE(void);
void KRN_vidC_10MS_7_PSL_POST(void);
void KRN_vidC_10MS_8_PSL_PRE(void);
void KRN_vidC_10MS_8_PSL_POST(void);
void KRN_vidC_10MS_9_PSL_PRE(void);
void KRN_vidC_10MS_9_PSL_POST(void);
void KRN_vidC_20MS_1_PSL_PRE(void);
void KRN_vidC_20MS_1_PSL_POST(void);
void KRN_vidC_20MS_2_PSL_PRE(void);
void KRN_vidC_20MS_2_PSL_POST(void);
void KRN_vidC_20MS_3_PSL_PRE(void);
void KRN_vidC_20MS_3_PSL_POST(void);
void KRN_vidC_20MS_4_PSL_PRE(void);
void KRN_vidC_20MS_4_PSL_POST(void);
void KRN_vidC_20MS_5_PSL_PRE(void);
void KRN_vidC_20MS_5_PSL_POST(void);
void KRN_vidC_40MS_1_PSL_PRE(void);
void KRN_vidC_40MS_1_PSL_POST(void);
void KRN_vidC_40MS_2_PSL_PRE(void);
void KRN_vidC_40MS_2_PSL_POST(void);
void KRN_vidC_40MS_3_PSL_PRE(void);
void KRN_vidC_40MS_3_PSL_POST(void);
void KRN_vidC_40MS_4_PSL_PRE(void);
void KRN_vidC_40MS_4_PSL_POST(void);
void KRN_vidC_40MS_5_PSL_PRE(void);
void KRN_vidC_40MS_5_PSL_POST(void);
void KRN_vidC_50MS_PSL_PRE(void);
void KRN_vidC_50MS_PSL_POST(void);
void KRN_vidC_100MS_1_PSL_PRE(void);
void KRN_vidC_100MS_1_PSL_POST(void);
void KRN_vidC_100MS_2_PSL_PRE(void);
void KRN_vidC_100MS_2_PSL_POST(void);
void KRN_vidC_100MS_3_PSL_PRE(void);
void KRN_vidC_100MS_3_PSL_POST(void);
void KRN_vidC_200MS_1_PSL_PRE(void);
void KRN_vidC_200MS_1_PSL_POST(void);
void KRN_vidC_200MS_2_PSL_PRE(void);
void KRN_vidC_200MS_2_PSL_POST(void);
void KRN_vidC_200MS_3_PSL_PRE(void);
void KRN_vidC_200MS_3_PSL_POST(void);
void KRN_vidC_200MS_4_PSL_PRE(void);
void KRN_vidC_200MS_4_PSL_POST(void);
void KRN_vidC_400MS_PSL_PRE(void);
void KRN_vidC_400MS_PSL_POST(void);
void KRN_vidC_1000MS_1_PSL_PRE(void);
void KRN_vidC_1000MS_1_PSL_POST(void);
void KRN_vidC_1000MS_2_PSL_PRE(void);
void KRN_vidC_1000MS_2_PSL_POST(void);
void KRN_vidC_1000MS_3_PSL_PRE(void);
void KRN_vidC_1000MS_3_PSL_POST(void);
void KRN_vidC_1000MS_4_PSL_PRE(void);
void KRN_vidC_1000MS_4_PSL_POST(void);
void KRN_vidC_1000MS_5_PSL_PRE(void);
void KRN_vidC_1000MS_5_PSL_POST(void);
void KRN_vidC_2000MS_PSL_PRE(void);
void KRN_vidC_2000MS_PSL_POST(void);
void KRN_vidC_4000MS_PSL_PRE(void);
void KRN_vidC_4000MS_PSL_POST(void);
void KRN_vidC_60000MS_PSL_PRE(void);
void KRN_vidC_60000MS_PSL_POST(void);
void KRN_vidS_1_4_TDC_PSL_PRE(void);
void KRN_vidS_1_4_TDC_PSL_POST(void);
void KRN_vidS_TDC_1_PSL_PRE(void);
void KRN_vidS_TDC_1_PSL_POST(void);
void KRN_vidS_TDC_2_PSL_PRE(void);
void KRN_vidS_TDC_2_PSL_POST(void);
void KRN_vidS_BDC_1_PSL_PRE(void);
void KRN_vidS_BDC_1_PSL_POST(void);
void KRN_vidS_BDC_2_PSL_PRE(void);
void KRN_vidS_BDC_2_PSL_POST(void);
void KRN_vidS_KNK_WIN_PSL_PRE(void);
void KRN_vidS_KNK_WIN_PSL_POST(void);
void KRN_vidS_CRK_ON_PSL_PRE(void);
void KRN_vidS_CRK_ON_PSL_POST(void);
void KRN_vidS_ENG_RUN_PSL_PRE(void);
void KRN_vidS_ENG_RUN_PSL_POST(void);
void KRN_vidS_LTOO1_PSL_PRE(void);
void KRN_vidS_LTOO1_PSL_POST(void);
void KRN_vidS_LTOO_PSL_PRE(void);
void KRN_vidS_LTOO_PSL_POST(void);
void KRN_vidS_TOLO_PSL_PRE(void);
void KRN_vidS_TOLO_PSL_POST(void);
void KRN_vidS_ENG_STAL_PSL_PRE(void);
void KRN_vidS_ENG_STAL_PSL_POST(void);
void KRN_vidS_CRK_OFF_PSL_PRE(void);
void KRN_vidS_CRK_OFF_PSL_POST(void);
void KRN_vidS_DIAG_COIL_A_PSL_PRE(void);
void KRN_vidS_DIAG_COIL_A_PSL_POST(void);
void KRN_vidS_DIAG_COIL_B_PSL_PRE(void);
void KRN_vidS_DIAG_COIL_B_PSL_POST(void);
void KRN_vidS_DIAG_COIL_C_PSL_PRE(void);
void KRN_vidS_DIAG_COIL_C_PSL_POST(void);
void KRN_vidS_DIAG_COIL_D_PSL_PRE(void);
void KRN_vidS_DIAG_COIL_D_PSL_POST(void);
void KRN_vidS_DIAG_COIL_A_C_PSL_PRE(void);
void KRN_vidS_DIAG_COIL_A_C_PSL_POST(void);
void KRN_vidS_DIAG_COIL_B_D_PSL_PRE(void);
void KRN_vidS_DIAG_COIL_B_D_PSL_POST(void);
void KRN_vidS_IGK_ON_PSL_PRE(void);
void KRN_vidS_IGK_ON_PSL_POST(void);
void KRN_vidS_IGK_OFF_PSL_PRE(void);
void KRN_vidS_IGK_OFF_PSL_POST(void);
void KRN_vidS_EEST_PSL_PRE(void);
void KRN_vidS_EEST_PSL_POST(void);
void KRN_vidS_THR_PSL_PRE(void);
void KRN_vidS_THR_PSL_POST(void);
void KRN_vidS_ENG_SPEED_OUTPUT_PSL_PRE(void);
void KRN_vidS_ENG_SPEED_OUTPUT_PSL_POST(void);
void KRN_vidS_N_INV_PSL_PRE(void);
void KRN_vidS_N_INV_PSL_POST(void);
void KRN_vidS_N_INV_OFF_PSL_PRE(void);
void KRN_vidS_N_INV_OFF_PSL_POST(void);
void KRN_vidS_TOOTH_PSL_PRE(void);
void KRN_vidS_TOOTH_PSL_POST(void);
void KRN_vidS_IN_CAM_EDGE_PSL_PRE(void);
void KRN_vidS_IN_CAM_EDGE_PSL_POST(void);
void KRN_vidS_IN_CAM_PERIOD_PSL_PRE(void);
void KRN_vidS_IN_CAM_PERIOD_PSL_POST(void);
void KRN_vidS_EX_CAM_EDGE_PSL_PRE(void);
void KRN_vidS_EX_CAM_EDGE_PSL_POST(void);
void KRN_vidS_EX_CAM_PERIOD_PSL_PRE(void);
void KRN_vidS_EX_CAM_PERIOD_PSL_POST(void);
void KRN_vidS_INJ_EVENT_PSL_PRE(void);
void KRN_vidS_INJ_EVENT_PSL_POST(void);
void KRN_vidS_PTMHAL_EVT_PSL_PRE(void);
void KRN_vidS_PTMHAL_EVT_PSL_POST(void);

#define TST_STOP_SEC_TST_CODE
#include "TST_MemMap.h"

#endif /* KRN_PSL_H */

/*-------------------------------- end of file -------------------------------*/

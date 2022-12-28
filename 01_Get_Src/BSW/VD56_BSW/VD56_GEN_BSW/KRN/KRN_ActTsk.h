/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     : Kernel Layer                                            */
/*                                                                            */
/* !File            : KRN_ActTsk.h                                            */
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
 * %PID: P2017_BSW:0A192565.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef KRN_ACTTSK_H
#define KRN_ACTTSK_H

#define KRN_START_SEC_CODE
#include "KRN_MemMap.h"

void  KRN_vidActivate_OSTSK_C_2MS_ASW(void);
void  KRN_vidActivate_OSTSK_C_2MS_POST(void);
void  KRN_vidActivate_OSTSK_C_2_5MS_1_ASW(void);
void  KRN_vidActivate_OSTSK_C_2_5MS_1_POST(void);
void  KRN_vidActivate_OSTSK_C_2_5MS_2_ASW(void);
void  KRN_vidActivate_OSTSK_C_2_5MS_2_POST(void);
void  KRN_vidActivate_OSTSK_C_5MS_1_ASW(void);
void  KRN_vidActivate_OSTSK_C_5MS_1_POST(void);
void  KRN_vidActivate_OSTSK_C_5MS_2_ASW(void);
void  KRN_vidActivate_OSTSK_C_5MS_2_POST(void);
void  KRN_vidActivate_OSTSK_C_5MS_3_ASW(void);
void  KRN_vidActivate_OSTSK_C_5MS_3_POST(void);
void  KRN_vidActivate_OSTSK_C_5MS_4_ASW(void);
void  KRN_vidActivate_OSTSK_C_5MS_4_POST(void);
void  KRN_vidActivate_OSTSK_C_5MS_5_ASW(void);
void  KRN_vidActivate_OSTSK_C_5MS_5_POST(void);
void  KRN_vidActivate_OSTSK_C_10MS_1_ASW(void);
void  KRN_vidActivate_OSTSK_C_10MS_1_POST(void);
void  KRN_vidActivate_OSTSK_C_10MS_2_ASW(void);
void  KRN_vidActivate_OSTSK_C_10MS_2_POST(void);
void  KRN_vidActivate_OSTSK_C_10MS_3_ASW(void);
void  KRN_vidActivate_OSTSK_C_10MS_3_POST(void);
void  KRN_vidActivate_OSTSK_C_10MS_4_ASW(void);
void  KRN_vidActivate_OSTSK_C_10MS_4_POST(void);
void  KRN_vidActivate_OSTSK_C_10MS_5_ASW(void);
void  KRN_vidActivate_OSTSK_C_10MS_5_POST(void);
void  KRN_vidActivate_OSTSK_C_10MS_6_ASW(void);
void  KRN_vidActivate_OSTSK_C_10MS_6_POST(void);
void  KRN_vidActivate_OSTSK_C_10MS_7_ASW(void);
void  KRN_vidActivate_OSTSK_C_10MS_7_POST(void);
void  KRN_vidActivate_OSTSK_C_10MS_8_ASW(void);
void  KRN_vidActivate_OSTSK_C_10MS_8_POST(void);
void  KRN_vidActivate_OSTSK_C_10MS_9_ASW(void);
void  KRN_vidActivate_OSTSK_C_10MS_9_POST(void);
void  KRN_vidActivate_OSTSK_C_20MS_1_ASW(void);
void  KRN_vidActivate_OSTSK_C_20MS_1_POST(void);
void  KRN_vidActivate_OSTSK_C_20MS_2_ASW(void);
void  KRN_vidActivate_OSTSK_C_20MS_2_POST(void);
void  KRN_vidActivate_OSTSK_C_20MS_3_ASW(void);
void  KRN_vidActivate_OSTSK_C_20MS_3_POST(void);
void  KRN_vidActivate_OSTSK_C_20MS_4_ASW(void);
void  KRN_vidActivate_OSTSK_C_20MS_4_POST(void);
void  KRN_vidActivate_OSTSK_C_20MS_5_ASW(void);
void  KRN_vidActivate_OSTSK_C_20MS_5_POST(void);
void  KRN_vidActivate_OSTSK_C_40MS_1_ASW(void);
void  KRN_vidActivate_OSTSK_C_40MS_1_POST(void);
void  KRN_vidActivate_OSTSK_C_40MS_2_ASW(void);
void  KRN_vidActivate_OSTSK_C_40MS_2_POST(void);
void  KRN_vidActivate_OSTSK_C_40MS_3_ASW(void);
void  KRN_vidActivate_OSTSK_C_40MS_3_POST(void);
void  KRN_vidActivate_OSTSK_C_40MS_4_ASW(void);
void  KRN_vidActivate_OSTSK_C_40MS_4_POST(void);
void  KRN_vidActivate_OSTSK_C_40MS_5_ASW(void);
void  KRN_vidActivate_OSTSK_C_40MS_5_POST(void);
void  KRN_vidActivate_OSTSK_C_50MS_ASW(void);
void  KRN_vidActivate_OSTSK_C_50MS_POST(void);
void  KRN_vidActivate_OSTSK_C_100MS_1_ASW(void);
void  KRN_vidActivate_OSTSK_C_100MS_1_POST(void);
void  KRN_vidActivate_OSTSK_C_100MS_2_ASW(void);
void  KRN_vidActivate_OSTSK_C_100MS_2_POST(void);
void  KRN_vidActivate_OSTSK_C_100MS_3_ASW(void);
void  KRN_vidActivate_OSTSK_C_100MS_3_POST(void);
void  KRN_vidActivate_OSTSK_C_200MS_1_ASW(void);
void  KRN_vidActivate_OSTSK_C_200MS_1_POST(void);
void  KRN_vidActivate_OSTSK_C_200MS_2_ASW(void);
void  KRN_vidActivate_OSTSK_C_200MS_2_POST(void);
void  KRN_vidActivate_OSTSK_C_200MS_3_ASW(void);
void  KRN_vidActivate_OSTSK_C_200MS_3_POST(void);
void  KRN_vidActivate_OSTSK_C_200MS_4_ASW(void);
void  KRN_vidActivate_OSTSK_C_200MS_4_POST(void);
void  KRN_vidActivate_OSTSK_C_400MS_ASW(void);
void  KRN_vidActivate_OSTSK_C_400MS_POST(void);
void  KRN_vidActivate_OSTSK_C_1000MS_1_ASW(void);
void  KRN_vidActivate_OSTSK_C_1000MS_1_POST(void);
void  KRN_vidActivate_OSTSK_C_1000MS_2_ASW(void);
void  KRN_vidActivate_OSTSK_C_1000MS_2_POST(void);
void  KRN_vidActivate_OSTSK_C_1000MS_3_ASW(void);
void  KRN_vidActivate_OSTSK_C_1000MS_3_POST(void);
void  KRN_vidActivate_OSTSK_C_1000MS_4_ASW(void);
void  KRN_vidActivate_OSTSK_C_1000MS_4_POST(void);
void  KRN_vidActivate_OSTSK_C_1000MS_5_ASW(void);
void  KRN_vidActivate_OSTSK_C_1000MS_5_POST(void);
void  KRN_vidActivate_OSTSK_C_2000MS_ASW(void);
void  KRN_vidActivate_OSTSK_C_2000MS_POST(void);
void  KRN_vidActivate_OSTSK_C_4000MS_ASW(void);
void  KRN_vidActivate_OSTSK_C_4000MS_POST(void);
void  KRN_vidActivate_OSTSK_C_60000MS_ASW(void);
void  KRN_vidActivate_OSTSK_C_60000MS_POST(void);
void  KRN_vidActivate_OSTSK_S_1_4_TDC_ASW(void);
void  KRN_vidActivate_OSTSK_S_1_4_TDC_POST(void);
void  KRN_vidActivate_OSTSK_S_TDC_1_ASW(void);
void  KRN_vidActivate_OSTSK_S_TDC_1_POST(void);
void  KRN_vidActivate_OSTSK_S_TDC_2_ASW(void);
void  KRN_vidActivate_OSTSK_S_TDC_2_POST(void);
void  KRN_vidActivate_OSTSK_S_BDC_1_ASW(void);
void  KRN_vidActivate_OSTSK_S_BDC_1_POST(void);
void  KRN_vidActivate_OSTSK_S_BDC_2_ASW(void);
void  KRN_vidActivate_OSTSK_S_BDC_2_POST(void);
void  KRN_vidActivate_OSTSK_S_KNK_WIN_ASW(void);
void  KRN_vidActivate_OSTSK_S_KNK_WIN_POST(void);
void  KRN_vidActivate_OSTSK_S_CRK_ON_ASW(void);
void  KRN_vidActivate_OSTSK_S_CRK_ON_POST(void);
void  KRN_vidActivate_OSTSK_S_ENG_RUN_ASW(void);
void  KRN_vidActivate_OSTSK_S_ENG_RUN_POST(void);
void  KRN_vidActivate_OSTSK_S_LTOO1_ASW(void);
void  KRN_vidActivate_OSTSK_S_LTOO1_POST(void);
void  KRN_vidActivate_OSTSK_S_LTOO_ASW(void);
void  KRN_vidActivate_OSTSK_S_LTOO_POST(void);
void  KRN_vidActivate_OSTSK_S_TOLO_ASW(void);
void  KRN_vidActivate_OSTSK_S_TOLO_POST(void);
void  KRN_vidActivate_OSTSK_S_ENG_STAL_ASW(void);
void  KRN_vidActivate_OSTSK_S_ENG_STAL_POST(void);
void  KRN_vidActivate_OSTSK_S_CRK_OFF_ASW(void);
void  KRN_vidActivate_OSTSK_S_CRK_OFF_POST(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_A_ASW(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_A_POST(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_B_ASW(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_B_POST(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_C_ASW(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_C_POST(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_D_ASW(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_D_POST(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_A_C_ASW(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_A_C_POST(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_B_D_ASW(void);
void  KRN_vidActivate_OSTSK_S_DIAG_COIL_B_D_POST(void);
void  KRN_vidActivate_OSTSK_S_IGK_ON_ASW(void);
void  KRN_vidActivate_OSTSK_S_IGK_ON_POST(void);
void  KRN_vidActivate_OSTSK_S_IGK_OFF_ASW(void);
void  KRN_vidActivate_OSTSK_S_IGK_OFF_POST(void);
void  KRN_vidActivate_OSTSK_S_EEST_ASW(void);
void  KRN_vidActivate_OSTSK_S_EEST_POST(void);
void  KRN_vidActivate_OSTSK_S_THR_ASW(void);
void  KRN_vidActivate_OSTSK_S_THR_POST(void);
void  KRN_vidActivate_OSTSK_S_SPILL_EVENT_ASW(void);
void  KRN_vidActivate_OSTSK_S_SPILL_EVENT_POST(void);
void  KRN_vidActivate_OSTSK_S_N_INV_ASW(void);
void  KRN_vidActivate_OSTSK_S_N_INV_POST(void);
void  KRN_vidActivate_OSTSK_S_N_INV_OFF_ASW(void);
void  KRN_vidActivate_OSTSK_S_N_INV_OFF_POST(void);
void  KRN_vidActivate_OSTSK_S_TOOTH_ASW(void);
void  KRN_vidActivate_OSTSK_S_TOOTH_POST(void);
void  KRN_vidActivate_OSTSK_S_IN_CAM_EDGE_ASW(void);
void  KRN_vidActivate_OSTSK_S_IN_CAM_EDGE_POST(void);
void  KRN_vidActivate_OSTSK_S_IN_CAM_PERIOD_ASW(void);
void  KRN_vidActivate_OSTSK_S_IN_CAM_PERIOD_POST(void);
void  KRN_vidActivate_OSTSK_S_EX_CAM_EDGE_ASW(void);
void  KRN_vidActivate_OSTSK_S_EX_CAM_EDGE_POST(void);
void  KRN_vidActivate_OSTSK_S_EX_CAM_PERIOD_ASW(void);
void  KRN_vidActivate_OSTSK_S_EX_CAM_PERIOD_POST(void);
void  KRN_vidActivate_OSTSK_S_INJ_EVENT_ASW(void);
void  KRN_vidActivate_OSTSK_S_INJ_EVENT_POST(void);
void  KRN_vidActivate_OSTSK_S_PTMHAL_EVT_ASW(void);
void  KRN_vidActivate_OSTSK_S_PTMHAL_EVT_POST(void);
void  KRN_vidActivate_OSTSK_S_ICLC_EVENT_ASW(void);
void  KRN_vidActivate_OSTSK_S_ICLC_EVENT_POST(void);

#define KRN_STOP_SEC_CODE
#include "KRN_MemMap.h"

#endif /* KRN_ACTTSK_H */

/*-------------------------------- end of file -------------------------------*/

/******************************************************************************/
/* !Layer           : APPLI                                                   */
/* !Component       : KRN                                                     */
/* !Description     : Kernel Layer                                            */
/*                                                                            */
/* !File            : KRN_ASW.h                                               */
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
 * %PID: P2017_BSW:A583.A-SRC;18 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef KRN_ASW_H
#define KRN_ASW_H

#define TST_START_SEC_TST_CODE
#include "TST_MemMap.h"

void KRN_vidINIT_ASW_1(void);
void KRN_vidINIT_ASW_2(void);
void KRN_vidINIT_ASW_3(void);
void KRN_vidINIT_ASW_4(void);
void KRN_vidINIT_ASW_POST(void);
void KRN_vidC_2MS_ASW(void);
void KRN_vidC_2_5MS_1_ASW(void);
void KRN_vidC_2_5MS_2_ASW(void);
void KRN_vidC_5MS_1_ASW(void);
void KRN_vidC_5MS_2_ASW(void);
void KRN_vidC_5MS_3_ASW(void);
void KRN_vidC_5MS_4_ASW(void);
void KRN_vidC_5MS_5_ASW(void);
void KRN_vidC_10MS_1_ASW(void);
void KRN_vidC_10MS_2_ASW(void);
void KRN_vidC_10MS_3_ASW(void);
void KRN_vidC_10MS_4_ASW(void);
void KRN_vidC_10MS_5_ASW(void);
void KRN_vidC_10MS_6_ASW(void);
void KRN_vidC_10MS_7_ASW(void);
void KRN_vidC_10MS_8_ASW(void);
void KRN_vidC_10MS_9_ASW(void);
void KRN_vidC_20MS_1_ASW(void);
void KRN_vidC_20MS_2_ASW(void);
void KRN_vidC_20MS_3_ASW(void);
void KRN_vidC_20MS_4_ASW(void);
void KRN_vidC_20MS_5_ASW(void);
void KRN_vidC_40MS_1_ASW(void);
void KRN_vidC_40MS_2_ASW(void);
void KRN_vidC_40MS_3_ASW(void);
void KRN_vidC_40MS_4_ASW(void);
void KRN_vidC_40MS_5_ASW(void);
void KRN_vidC_50MS_ASW(void);
void KRN_vidC_100MS_1_ASW(void);
void KRN_vidC_100MS_2_ASW(void);
void KRN_vidC_100MS_3_ASW(void);
void KRN_vidC_200MS_1_ASW(void);
void KRN_vidC_200MS_2_ASW(void);
void KRN_vidC_200MS_3_ASW(void);
void KRN_vidC_200MS_4_ASW(void);
void KRN_vidC_400MS_ASW(void);
void KRN_vidC_400MS_ASW(void);
void KRN_vidC_1000MS_1_ASW(void);
void KRN_vidC_1000MS_2_ASW(void);
void KRN_vidC_1000MS_3_ASW(void);
void KRN_vidC_1000MS_4_ASW(void);
void KRN_vidC_1000MS_5_ASW(void);
void KRN_vidC_2000MS_ASW(void);
void KRN_vidC_4000MS_ASW(void);
void KRN_vidC_60000MS_ASW(void);
void KRN_vidS_TDC_1_ASW(void);
void KRN_vidS_TDC_2_ASW(void);
void KRN_vidS_BDC_1_ASW(void);
void KRN_vidS_BDC_2_ASW(void);
void KRN_vidS_DIAG_COIL_A_ASW(void);
void KRN_vidS_DIAG_COIL_B_ASW(void);
void KRN_vidS_DIAG_COIL_C_ASW(void);
void KRN_vidS_DIAG_COIL_D_ASW(void);
void KRN_vidS_DIAG_COIL_A_C_ASW(void);
void KRN_vidS_DIAG_COIL_B_D_ASW(void);

void KRN_vidCRK_DOWN_MODE_ASW(void);
void KRN_vidCRK_NORMAL_MODE_ASW(void);
void KRN_vidSYNC_FOUND_ASW(void);
void KRN_vidS_EEST_ASW(void);
void KRN_vidS_INJ_EVENT_ASW(void);
void KRN_vidS_PTMHAL_EVT_ASW(void);

void KRN_vidS_1_4_TDC_ASW(void);
void KRN_vidS_ENG_RUN_ASW(void);
void KRN_vidS_CRK_ON_ASW(void);
void KRN_vidS_CRK_OFF_ASW(void);
void KRN_vidS_LTOO_ASW(void);
void KRN_vidS_LTOO1_ASW(void);
void KRN_vidS_TOLO_ASW(void);
void KRN_vidS_ENG_STAL_ASW(void);
void KRN_vidS_IGK_ON_ASW(void);
void KRN_vidS_IGK_OFF_ASW(void);
void KRN_vidS_KNK_WIN_ASW(void);
void KRN_vidINCAM_DOWN_MODE_ASW(void);
void KRN_vidINCAM_NORMAL_MODE_ASW(void);
void KRN_vidEXCAM_DOWN_MODE_ASW(void);
void KRN_vidEXCAM_NORMAL_MODE_ASW(void);
void KRN_vidS_THR_ASW(void);
void KRN_vidS_ENG_SPEED_OUTPUT_ASW(void);
void KRN_vidS_N_INV_ASW(void);
void KRN_vidS_N_INV_OFF_ASW(void);
void KRN_vidS_TOOTH_ASW(void);
void KRN_vidS_IN_CAM_PERIOD_ASW(void);
void KRN_vidS_EX_CAM_PERIOD_ASW(void);
void KRN_vidS_IN_CAM_EDGE_ASW(void);
void KRN_vidS_EX_CAM_EDGE_ASW(void);

void KRN_vidS_FUNCTIONAL_TEST_START_ASW(void);
void KRN_vidS_FUNCTIONAL_TEST_ABORT_ASW(void);
void KRN_vidS_FUNCTIONAL_TEST_END_ASW(void);

#define TST_STOP_SEC_TST_CODE
#include "TST_MemMap.h"

#endif /* KRN_ASW_H */

/*-------------------------------- end of file -------------------------------*/

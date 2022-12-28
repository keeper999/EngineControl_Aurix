/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : TST_KRN.c                                               */
/* !Description     : Defines Software tasks                                  */
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
 * %PID: P2017_BSW:A93486.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "KRN_ASW.h"
#include "KRN_BSW.h"
#include "KRN.h"
#include "KRN_L.h"
#include "Os.h"
#include "Os_Cfg.h"
#include "TDCHAL.h"
#include "KRN_PSL.h"
#include "KRN_ActTsk.h"

#define TST_START_SEC_TST_CODE
#include "TST_MemMap.h"

/******************************************************************************/
/* !FuncName    : OSTSK_S_DUMMY_TIE_CORE2                                     */
/* !Description : This task is activated on diagnosis on Coil A               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_DUMMY_TIE_CORE2)
{
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DUMMY_TIE_CORE0                                     */
/* !Description : This task is activated on diagnosis on Coil A               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_DUMMY_TIE_CORE0)
{
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DUMMY_TIE_CORE0                                     */
/* !Description : This task is activated on diagnosis on Coil A               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_DUMMY_DRE_CORE0)
{
   (void)TerminateTask();
}


/******************************************************************************/
/* !FuncName    : OSTSK_S_DUMMY_TIE_CORE0                                     */
/* !Description : This task is activated on diagnosis on Coil A               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_DUMMY_MSE_CORE0)
{
   (void)TerminateTask();
}


/******************************************************************************/
/* !FuncName    : OSTSK_S_OILLV_EVENT                                         */
/* !Description : This task is activated on diagnosis on Coil A               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_OILLV_EVENT)
{
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_A                                         */
/* !Description : This task is activated on diagnosis on Coil A               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_A)
{
   KRN_vidS_DIAG_COIL_A_BSW_PRE();
   KRN_vidS_DIAG_COIL_A_PSL_PRE();
   KRN_vidS_DIAG_COIL_A_ASW();
   KRN_vidActivate_OSTSK_S_DIAG_COIL_A_ASW();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_A_ASW                                     */
/* !Description : This task is the ASW of OSTSK_S_DIAG_COIL_A event task      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_A_ASW)
{
   KRN_vidActivate_OSTSK_S_DIAG_COIL_A_POST();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_A_POST                                    */
/* !Description : This task is the POST of OSTSK_S_DIAG_COIL_A event task     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_A_POST)
{
   KRN_vidS_DIAG_COIL_A_PSL_POST();
   KRN_vidS_DIAG_COIL_A_BSW_POST();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_B                                         */
/* !Description : This task is activated on diagnosis on Coil B               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_B)
{
   KRN_vidS_DIAG_COIL_B_BSW_PRE();
   KRN_vidS_DIAG_COIL_B_PSL_PRE();
   KRN_vidS_DIAG_COIL_B_ASW();
   KRN_vidActivate_OSTSK_S_DIAG_COIL_B_ASW();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_B_ASW                                     */
/* !Description : This task is the ASW of OSTSK_S_DIAG_COIL_B event task      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_B_ASW)
{
   KRN_vidActivate_OSTSK_S_DIAG_COIL_B_POST();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_B_POST                                    */
/* !Description : This task is the POST of OSTSK_S_DIAG_COIL_B event task     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_B_POST)
{
   KRN_vidS_DIAG_COIL_B_PSL_POST();
   KRN_vidS_DIAG_COIL_B_BSW_POST();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_C                                         */
/* !Description : This task is activated on diagnosis on Coil C               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_C)
{
   KRN_vidS_DIAG_COIL_C_BSW_PRE();
   KRN_vidS_DIAG_COIL_C_PSL_PRE();
   KRN_vidS_DIAG_COIL_C_ASW();
   KRN_vidActivate_OSTSK_S_DIAG_COIL_C_ASW();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_C_ASW                                     */
/* !Description : This task is the ASW of OSTSK_S_DIAG_COIL_C event task      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_C_ASW)
{
   KRN_vidActivate_OSTSK_S_DIAG_COIL_C_POST();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_C_POST                                    */
/* !Description : This task is the POST of OSTSK_S_DIAG_COIL_C event task     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_C_POST)
{
   KRN_vidS_DIAG_COIL_C_PSL_POST();
   KRN_vidS_DIAG_COIL_C_BSW_POST();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_D                                         */
/* !Description : This task is activated on diagnosis on Coil D               */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_D)
{
   KRN_vidS_DIAG_COIL_D_BSW_PRE();
   KRN_vidS_DIAG_COIL_D_PSL_PRE();
   KRN_vidS_DIAG_COIL_D_ASW();
   KRN_vidActivate_OSTSK_S_DIAG_COIL_D_ASW();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_D_ASW                                     */
/* !Description : This task is the ASW of OSTSK_S_DIAG_COIL_D event task      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_D_ASW)
{
   KRN_vidActivate_OSTSK_S_DIAG_COIL_D_POST();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_D_POST                                    */
/* !Description : This task is the POST of OSTSK_S_DIAG_COIL_D event task     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_D_POST)
{
   KRN_vidS_DIAG_COIL_D_PSL_POST();
   KRN_vidS_DIAG_COIL_D_BSW_POST();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_A_C                                       */
/* !Description : This task is activated on diagnosis on Coil A_C             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_A_C)
{
   KRN_vidS_DIAG_COIL_A_C_BSW_PRE();
   KRN_vidS_DIAG_COIL_A_C_PSL_PRE();
   KRN_vidS_DIAG_COIL_A_C_ASW();
   KRN_vidActivate_OSTSK_S_DIAG_COIL_A_C_ASW();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_A_C_ASW                                   */
/* !Description : This task is the ASW of OSTSK_S_DIAG_COIL_A_C event task    */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_A_C_ASW)
{
   KRN_vidActivate_OSTSK_S_DIAG_COIL_A_C_POST();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_A_C_POST                                  */
/* !Description : This task is the POST of OSTSK_S_DIAG_COIL_A_C event task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_A_C_POST)
{
   KRN_vidS_DIAG_COIL_A_C_PSL_POST();
   KRN_vidS_DIAG_COIL_A_C_BSW_POST();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : OSTSK_S_DIAG_COIL_B_D                                       */
/* !Description : This task is activated on diagnosis on Coil B_D             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_B_D)
{
   KRN_vidS_DIAG_COIL_B_D_BSW_PRE();
   KRN_vidS_DIAG_COIL_B_D_PSL_PRE();
   KRN_vidS_DIAG_COIL_B_D_ASW();
   KRN_vidActivate_OSTSK_S_DIAG_COIL_B_D_ASW();
   (void)TerminateTask();
}

/****************************************
/* !FuncName    : OSTSK_S_DIAG_COIL_B_D_ASW                                   */
/* !Description : This task is the ASW of OSTSK_S_DIAG_COIL_B_D event task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_B_D_ASW)
{
   KRN_vidActivate_OSTSK_S_DIAG_COIL_B_D_POST();
   (void)TerminateTask();
}

/****************************************
/* !FuncName    : OSTSK_S_DIAG_COIL_B_D_POST                                  */
/* !Description : This task is the POST of OSTSK_S_DIAG_COIL_B_D event task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
TASK(OSTSK_S_DIAG_COIL_B_D_POST)
{
   KRN_vidS_DIAG_COIL_B_D_PSL_POST();
   KRN_vidS_DIAG_COIL_B_D_BSW_POST();
   (void)TerminateTask();
}

/******************************************************************************/
/* !FuncName    : KRN_vidInCamDwnModeEntry                                    */
/* !Description : Callback for Intake camshaft Downgraded Mode Entry          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidInCamDwnModeEntry(void)
{
   KRN_vidINCAM_DOWN_MODE_BSW_PRE();
   KRN_vidINCAM_DOWN_MODE_ASW();
   KRN_vidINCAM_DOWN_MODE_BSW_POST();
}

/******************************************************************************/
/* !FuncName    : KRN_vidInCamNormalModeEntry                                 */
/* !Description : Callback for Intake camshaft Normal Mode Entry              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidInCamNormalModeEntry(void)
{
   KRN_vidINCAM_NORMAL_MODE_BSW_PRE();
   KRN_vidINCAM_NORMAL_MODE_ASW();
   KRN_vidINCAM_NORMAL_MODE_BSW_POST();
}

/******************************************************************************/
/* !FuncName    : KRN_vidExCamDwnModeEntry                                    */
/* !Description : Callback for Exhaust camshaft Downgraded Mode Entry         */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidExCamDwnModeEntry(void)
{
   KRN_vidEXCAM_DOWN_MODE_BSW_PRE();
   KRN_vidEXCAM_DOWN_MODE_ASW();
   KRN_vidEXCAM_DOWN_MODE_BSW_POST();
}

/******************************************************************************/
/* !FuncName    : KRN_vidExCamNormalModeEntry                                 */
/* !Description : Callback for Exhaust camshaft Normal Mode Entry             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidExCamNormalModeEntry(void)
{
   KRN_vidEXCAM_NORMAL_MODE_BSW_PRE();
   KRN_vidEXCAM_NORMAL_MODE_ASW();
   KRN_vidEXCAM_NORMAL_MODE_BSW_POST();
}

/******************************************************************************/
/* !FuncName    : KRN_vidCrkDwnModeEntry                                      */
/* !Description : Callback for CRKHAL Downgraded Mode Entry                   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidCrkDwnModeEntry(void)
{
   KRN_vidCRK_DOWN_MODE_BSW_PRE();
   KRN_vidCRK_DOWN_MODE_ASW();
   KRN_vidCRK_DOWN_MODE_BSW_POST();
}

/******************************************************************************/
/* !FuncName    : KRN_vidCrkNormalModeEntry                                   */
/* !Description : Callback for CRKHAL Normal Mode Entry                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidCrkNormalModeEntry(void)
{
   KRN_vidCRK_NORMAL_MODE_BSW_PRE();
   KRN_vidCRK_NORMAL_MODE_ASW();
   KRN_vidCRK_NORMAL_MODE_BSW_POST();
}

/******************************************************************************/
/* !FuncName    : KRN_vidSyncLossEntry                                        */
/* !Description : Callback for engine synchronization loss                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidSyncLossEntry(void)
{
   KRN_vidS_TOLO_INTERRUPT_BSW();
}

/******************************************************************************/
/* !FuncName    : KRN_vidSyncFoundEntry                                       */
/* !Description : Callback for engine synchronization found                   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidSyncFoundEntry(void)
{
   KRN_vidSYNC_FOUND_BSW_PRE();
   KRN_vidSYNC_FOUND_ASW();
   KRN_vidSYNC_FOUND_BSW_POST();
}

#define TST_STOP_SEC_TST_CODE
#include "TST_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

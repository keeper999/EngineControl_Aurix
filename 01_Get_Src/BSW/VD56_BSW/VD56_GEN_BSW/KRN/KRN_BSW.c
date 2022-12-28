/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_BSW.c                                               */
/* !Description     : Defines BSW functions directly called by the tasks      */
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
 * %PID: P2017_BSW:0A192599.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "ADCBSL.h"
#include "ADCHAL.h"
#include "ANGSCHED.h"
#include "CAMHAL.h"
#include "CJ135.h"
#include "CRKHAL.h"
#include "DEVHAL.h"
#include "DGOHAL.h"
#include "DIOHAL.h"
#include "DIOHAL_Hook_Cfg.h"
#include "Fee.h"
#include "Fls.h"
#include "GPT.h"
#include "HBHAL.h"
#include "IGNHAL.h"
#include "INJHAL.h"
#include "KNWHAL.h"
#include "KRN_Private.h"
#include "LBHOT.h"
#include "ISR_Cfg.h"
#include "L9781.h"
#include "MOS.h"
#include "NVM.h"
#include "NvMIf.h"
#include "Os.h"
#include "Os_DisableInterrupts.h"
#include "PFCHAL.h"
#include "PMPHAL.h"
#include "PRSHAL.h"
#include "PTMHAL.h"
#include "PWDHAL.h"
#include "PWLHAL.h"
#include "PWMHAL.h"
#include "RSTSRV.h"
#include "RTMCKS.h"
#include "RTMCLD.h"
#include "RTMCLD2.h"
#include "RTMTSK.h"
#include "SWFAIL.h"
#include "TDCHAL.h"
#include "THRHAL.h"
#include "TLE8718.h"
#include "TLF35584.h"
#include "TSKSRV.h"
#include "Wdg.h"

#include "KRN_ASW.h"
#include "KRN_BSW.h"

#define KRN_START_SEC_CODE
#include "KRN_MemMap.h"

/******************************************************************************/
/* !FuncName    : KRN_vidInit                                                 */
/* !Description : Initialisation of the software                              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidInit(void)
{
   KRN_vidDisableOsAccess();
   Wdg_vidRefreshWatchdog();
   KRN_vidINIT_BSW_PRE();
   Wdg_vidRefreshWatchdog();
   KRN_vidINIT_ASW_1();
   Wdg_vidRefreshWatchdog();
   KRN_vidINIT_ASW_2();
   Wdg_vidRefreshWatchdog();
   KRN_vidINIT_ASW_3();
   Wdg_vidRefreshWatchdog();
   KRN_vidINIT_ASW_4();
   Wdg_vidRefreshWatchdog();
   KRN_vidINIT_BSW_POST();
   Wdg_vidRefreshWatchdog();
   KRN_vidINIT_ASW_POST();
   Wdg_vidRefreshWatchdog();
   KRN_vidEnableOsAccess();
}


/******************************************************************************/
/* !FuncName    : KRN_vidINIT_BSW_PRE                                         */
/* !Description : BSW function called at the beginning of the INIT task       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidINIT_BSW_PRE(void)
{
   /* ECU components initialization                                      */
   SWFAIL_vidInit();
   PWLHAL_vidReadKeyDiagMainRly();
   DEVHAL_vidInit();
   KRN_vidInitChecksumCheck();

   /* OsEnaOsInterrupt shall be called just after calling INTBSL_vidInit */

   DMADRV_vidInit();
   ADCBSL_vidInit();
   NvM_Init();
   Wdg_SetMode(WDGIF_OFF_MODE);
   NvMIf_vidInit();
   Wdg_SetMode(WDGIF_FAST_MODE);
   /* Wdg_vidRefreshWatchdog must be called after transition OFF -> FAST */
   Wdg_vidRefreshWatchdog();
/*   E2PROM_vidCheckRedObjValidity();*/
   /* End of ECU components initialization                               */

   /* ECU status initialization                                          */
   RSTSRV_vidInitEntry();
   KRN_vidSaveManualResetContext();
   DGOHAL_vidInit();
   L9781_vidInit();
   /* End of ECU status initialization                                   */

   /* Functional initialization code shall be added here                 */
   /* These components shall not need variables initialization by ASW    */
   PWLHAL_vidInit();
   CRKHAL_vidInit();
   DIOHAL_vidInit();
   DIOHAL_vidInitHook();
   TDCHAL_vidInit();
   IgnHALInit();
   INJHAL_vidInit();
   PMPHAL_vidInit();
   CAMHAL_vidInit();
   PWMHAL_vidInit();
   RTMTSK_vidTaskTimeMeasureInit();
   KNWHAL_vidInit();
   HBHAL_vidInit();
   THRHAL_vidInit();
   CJ135_vidInit();
   TSKSRV_vidInit();
   PWLHAL_vidDiagMainRly();
   TLE8718_vidInit();
   LBHOT_vidInit();
   PWDHAL_vidInit();
/*   MCWDG_vidEnable();*/
   Gpt_StartTimer(GptConf_GptChannel_MOS_TIMER, 0xFFFFU);
   Gpt_StartTimer(GptConf_GptChannel_APPLICATIVE_500NS, 0xFFFFFFU);
   ADCBSL_vidWaitInitCompletion();
   ADCHAL_vidInit();
   MOS_vidInit();
   MOS_vidEnableDiag(MOS_udtQ1504_1);
   MOS_vidEnableDiag(MOS_udtQ1504_2);
   MOS_vidEnableCmd(MOS_udtQ1504_1, HOD_CUT_OFF_WITHOUT_FAULT);
   MOS_vidEnableCmd(MOS_udtQ1504_2, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_1, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_2, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_3, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_4, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_5, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_6, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_7, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_8, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_9, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_10, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_11, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_13, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_14, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_15, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_16, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_17, HOD_CUT_OFF_WITHOUT_FAULT);
   TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_18, HOD_CUT_OFF_WITHOUT_FAULT);
   PTMHAL_vidInit();
   PFCHAL_vidInit();
   PFCHAL_vidEnable();
   ANGSCHED_vidInit();
   /* End of functional initialization code                              */
}


/******************************************************************************/
/* !FuncName    : KRN_vidINIT_BSW_POST                                        */
/* !Description : BSW function called at the end of the INIT task             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidINIT_BSW_POST(void)
{
   /* Functional initialization code shall be added here                */
   /* These components shall need variables initialization by ASW       */

   /* End of Functional initialization code                             */

   /* ECU components start                                              */
   KRN_vidSchedulerInit();
   /* End of ECU components start                                       */

   /* Shall be end of the POST init macro                               */
   KRN_vid60000msTaskFrom4000msInit();
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_INIT_BSW_PRE                                       */
/* !Description : BSW function called at the beginning of the OSTSK_S_INIT    */
/*                auto started task                                           */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidS_INIT_BSW_PRE(void)
{
   TLF35584_vidInit();
   TLE8718_vidEnable(TLE8718_udtINSTANCE_1);
   L9781_udtEnable();
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_2MS_BSW_PRE                                        */
/* !Description : BSW function called at the beginning of the OSTSK_C_2MS task*/
/*                                                                            */
/* !LastAuthor  : G. Mostafa                                                  */
/******************************************************************************/
void KRN_vidC_2MS_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_2MS_BSW_POST                                       */
/* !Description : BSW function called at the end of the OSTSK_C_2MS task      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_2MS_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_2_5MS_1_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the                 */
/*                OSTSK_C_2_5MS_1 task                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_2_5MS_1_BSW_PRE(void)
{
   PWDHAL_vidEntry_2500us();
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_2_5MS_1_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_C_2_5MS_1 task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_2_5MS_1_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_2_5MS_2_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_C_2_5MS_2 */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_2_5MS_2_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_2_5MS_2_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_C_2_5MS_2 task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_2_5MS_2_BSW_POST(void)
{
}



/******************************************************************************/
/* !FuncName    : KRN_vidC_5MS_1_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the OSTSK_C_5MS task*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidC_5MS_1_BSW_PRE(void)
{
   DIOHAL_vidMainFunction();
   L9781_vidDiagManager();
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_5MS_1_BSW_POST                                     */
/* !Description : BSW function called at the end of the OSTSK_C_5MS task      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_5MS_1_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_5MS_2_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the OSTSK_C_5MS task*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_5MS_2_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_5MS_2_BSW_POST                                     */
/* !Description : BSW function called at the end of the OSTSK_C_5MS task      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_5MS_2_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_5MS_3_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the OSTSK_C_5MS task*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_5MS_3_BSW_PRE(void)
{
   RTMCKS_vidMainFunction(TMS_CKS);
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_5MS_3_BSW_POST                                     */
/* !Description : BSW function called at the end of the OSTSK_C_5MS task      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_5MS_3_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_5MS_4_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the OSTSK_C_5MS task*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_5MS_4_BSW_PRE(void)
{
   THRHAL_vidMainFunction();
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_5MS_4_BSW_POST                                     */
/* !Description : BSW function called at the end of the OSTSK_C_5MS task      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_5MS_4_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_5MS_5_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the OSTSK_C_5MS task*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_5MS_5_BSW_PRE(void)
{
   RTMCKS_vidMainFunction(GLOBAL_CKS);
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_5MS_5_BSW_POST                                     */
/* !Description : BSW function called at the end of the OSTSK_C_5MS task      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_5MS_5_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_1_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_10MS_1  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidC_10MS_1_BSW_PRE(void)
{
   ADCHAL_vidEntry_10ms_EVENT();
   CAMHAL_vidTimeoutDetection();
   CJ135_vidMainFunction();
   IGNHAL_vidPeriodicIgnVbrf();
   TLE8718_vidEntry_10ms();
   ActivateTask(OSTSK_S_WTDG_REFRESH_WATCHDOG_ASW);
   ActivateTask(OSTSK_S_WTDG_REFRESH_WATCHDOG_BSW);
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_1_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_10MS_1 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_1_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_2_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_10MS_2  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_2_BSW_PRE(void)
{
   Fls_MainFunction();
   Fee_MainFunction();
   NvM_MainFunction();
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_2_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_10MS_2 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_2_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_3_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_10MS_3  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_3_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_3_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_10MS_3 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_3_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_4_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_10MS_4  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_4_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_4_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_10MS_4 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_4_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_5_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_10MS_5  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_5_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_5_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_10MS_5 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_5_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_6_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_10MS_6  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_6_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_6_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_10MS_6 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_6_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_7_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_10MS_7  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_7_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_7_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_10MS_7 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_7_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_8_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_10MS_8  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_10MS_8_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_8_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_10MS_8 task   */
/*                                                                            */
/* !LastAuthor  : G. Mostafa                                                  */
/******************************************************************************/
void KRN_vidC_10MS_8_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_9_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_10MS_9  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
void KRN_vidC_10MS_9_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_10MS_9_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_10MS_9 task   */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
void KRN_vidC_10MS_9_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_20MS_1_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_20MS_1  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
void KRN_vidC_20MS_1_BSW_PRE(void)
{
   MOS_vidEntry_20ms();
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_20MS_1_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_20MS_1 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_20MS_1_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_20MS_2_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_20MS_2  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_20MS_2_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_20MS_2_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_20MS_2 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_20MS_2_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_20MS_3_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_20MS_3  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_20MS_3_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_20MS_3_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_20MS_3 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_20MS_3_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_20MS_4_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_20MS_4  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_20MS_4_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_20MS_4_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_20MS_4 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_20MS_4_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_20MS_5_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_20MS_5  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_20MS_5_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_20MS_5_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_20MS_5 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_20MS_5_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_40MS_1_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_40MS_1  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_40MS_1_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_40MS_1_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_40MS_1 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_40MS_1_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_40MS_2_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_40MS_2  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_40MS_2_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_40MS_2_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_40MS_2 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_40MS_2_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_40MS_3_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_40MS_3  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_40MS_3_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_40MS_3_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_40MS_3 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_40MS_3_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_40MS_4_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_40MS_4  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_40MS_4_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_40MS_4_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_40MS_4 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_40MS_4_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_40MS_5_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_40MS_5  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_40MS_5_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_40MS_5_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_40MS_5 task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_40MS_5_BSW_POST(void)
{
   /* OsControlStacks(); stubbed for mockup*/
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_50MS_BSW_PRE                                       */
/* !Description : BSW function called at the beginning of the OSTSK_C_50MS    */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_50MS_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_50MS_BSW_POST                                      */
/* !Description : BSW function called at the end of the OSTSK_C_50MS   task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_50MS_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_100MS_1_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_C_100MS_1 */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_100MS_1_BSW_PRE(void)
{
   TLE8718_vidEntry_100ms();
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_100MS_1_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_C_100MS_1 task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_100MS_1_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_100MS_2_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_C_100MS_2 */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_100MS_2_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_100MS_2_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_C_100MS_2 task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_100MS_2_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_100MS_3_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_C_100MS_3 */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_100MS_3_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_100MS_3_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_C_100MS_3 task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_100MS_3_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_200MS_1_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_C_200MS_1 */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_200MS_1_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_200MS_1_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_C_200MS_1 task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_200MS_1_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_200MS_2_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_C_200MS_2 */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_200MS_2_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_200MS_2_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_C_200MS_2 task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_200MS_2_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_200MS_3_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_C_200MS_3 */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_200MS_3_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_200MS_3_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_C_200MS_3 task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_200MS_3_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_200MS_4_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_C_200MS_4 */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_200MS_4_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_200MS_4_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_C_200MS_4 task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_200MS_4_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_400MS_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the OSTSK_C_400MS   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_400MS_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_400MS_BSW_POST                                     */
/* !Description : BSW function called at the end of the OSTSK_C_400MS   task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_400MS_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_1000MS_1_BSW_PRE                                   */
/* !Description : BSW function called at the beginning of the OSTSK_C_1000MS_1*/
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_1000MS_1_BSW_PRE(void)
{
   RTMCLD_vidMainFunction();
   RTMCLD2_vidMainFunction();
   KRN_vidStackMetric();
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_1000MS_1_BSW_POST                                  */
/* !Description : BSW function called at the end of the OSTSK_C_1000MS_1 task */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_1000MS_1_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_1000MS_2_BSW_PRE                                   */
/* !Description : BSW function called at the beginning of the OSTSK_C_1000MS_2*/
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_1000MS_2_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_1000MS_2_BSW_POST                                  */
/* !Description : BSW function called at the end of the OSTSK_C_1000MS_2 task */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_1000MS_2_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_1000MS_3_BSW_PRE                                   */
/* !Description : BSW function called at the beginning of the OSTSK_C_1000MS_3*/
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_1000MS_3_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_1000MS_3_BSW_POST                                  */
/* !Description : BSW function called at the end of the OSTSK_C_1000MS_3 task */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_1000MS_3_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_1000MS_4_BSW_PRE                                   */
/* !Description : BSW function called at the beginning of the OSTSK_C_1000MS_4*/
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_1000MS_4_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_1000MS_4_BSW_POST                                  */
/* !Description : BSW function called at the end of the OSTSK_C_1000MS_4 task */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_1000MS_4_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_1000MS_5_BSW_PRE                                   */
/* !Description : BSW function called at the beginning of the OSTSK_C_1000MS_5*/
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_1000MS_5_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_1000MS_5_BSW_POST                                  */
/* !Description : BSW function called at the end of the OSTSK_C_1000MS_5 task */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_1000MS_5_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_2000MS_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_2000MS  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_2000MS_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_2000MS_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_2000MS task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_2000MS_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_4000MS_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_C_4000MS  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_4000MS_BSW_PRE(void)
{
   KRN_vid60000msTaskFrom4000ms();
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_4000MS_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_C_4000MS task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_4000MS_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_60000MS_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_C_60000MS */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_60000MS_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidC_60000MS_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_C_60000MS task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidC_60000MS_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_TDC_BSW_PRE                                        */
/* !Description : BSW function called at the beginning of the                 */
/*                OSTSK_S_TDC tasks                                           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_TDC_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_TDC_BSW_POST                                       */
/* !Description : BSW function called at the end of the OSTSK_S_TDC tasks     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_TDC_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_BDC_BSW_PRE                                        */
/* !Description : BSW function called at the beginning of the                 */
/*                OSTSK_S_BDC tasks                                           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_BDC_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_BDC_BSW_POST                                       */
/* !Description : BSW function called at the end of the OSTSK_S_BDC tasks     */
/*                                                                            */
/* !LastAuthor  : H. Saidi                                                    */
/******************************************************************************/
void KRN_vidS_BDC_BSW_POST(void)
{
   IGNHAL_vidCoilTdcAdvAvail();
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_KNK_WIN_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_S_KNK_WIN */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_KNK_WIN_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_KNK_WIN_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_S_KNK_WIN task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_KNK_WIN_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_CRK_ON_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_S_CRK_ON  */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_CRK_ON_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_CRK_ON_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_S_CRK_ON task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_CRK_ON_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_ENG_RUN_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_S_ENG_RUN */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_ENG_RUN_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_ENG_RUN_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_S_ENG_RUN task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_ENG_RUN_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_LTOO1_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the OSTSK_S_LTOO1   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidS_LTOO1_BSW_PRE(void)
{
   TDCHAL_vidEnable();
   PRSHAL_vidInit();
   INJHAL_vidCrkSyncFoundEntry(GDI_1_TO_3);
   PMPHAL_vidCrkSyncFoundEntry();
   ANGSCHED_vidEnable(ANGSCHED_u8ALARM_1);
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_LTOO1_BSW_POST                                     */
/* !Description : BSW function called at the end of the OSTSK_S_LTOO1 task    */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_LTOO1_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_LTOO_BSW_PRE                                       */
/* !Description : BSW function called at the beginning of the OSTSK_S_LTOO    */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_LTOO_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_LTOO_BSW_POST                                      */
/* !Description : BSW function called at the end of the OSTSK_S_LTOO task     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_LTOO_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_TOLO_INTERRUPT_BSW                                 */
/* !Description : BSW function called immediately when synchronization is lost*/
/*                so directly in CRKHAL interrupt                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidS_TOLO_INTERRUPT_BSW(void)
{
   TDCHAL_vidDisable();
   PRSHAL_vidDeInit();
   INJHAL_vidCrkSyncLostEntry(GDI_1_TO_3);
   ANGSCHED_vidDisable(ANGSCHED_u8ALARM_1);
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_TOLO_BSW_PRE                                       */
/* !Description : BSW function called at the beginning of the OSTSK_S_TOLO    */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidS_TOLO_BSW_PRE(void)
{
   KNWHAL_vidCrkSyncLostEntry();
   PMPHAL_vidCrkSyncLostEntry();
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_TOLO_BSW_POST                                      */
/* !Description : BSW function called at the end of the OSTSK_S_TOLO task     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_TOLO_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_ENG_STAL_BSW_PRE                                   */
/* !Description : BSW function called at the beginning of the OSTSK_S_ENG_STAL*/
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_ENG_STAL_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_ENG_STAL_BSW_POST                                  */
/* !Description : BSW function called at the end of the OSTSK_S_ENG_STAL task */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_ENG_STAL_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_CRK_OFF_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_S_CRK_OFF */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_CRK_OFF_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_CRK_OFF_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_S_CRK_OFF task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_CRK_OFF_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_A_BSW_PRE                                */
/* !Description : BSW function called at the beginning of the                 */
/*                OSTSK_S_DIAG_COIL_A task                                    */
/*                                                                            */
/* !LastAuthor  : H. Saidi                                                    */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_A_BSW_PRE(void)
{
   diagnostic_bobine_a();
   IGNHAL_vidAdaptCoilCalc(IGNHAL_u8COIL_A);
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_A_BSW_POST                               */
/* !Description : BSW function called at the end of the OSTSK_S_DIAG_COIL_A   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_A_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_B_BSW_PRE                                */
/* !Description : BSW function called at the beginning of the                 */
/*                OSTSK_S_DIAG_COIL_B task                                    */
/*                                                                            */
/* !LastAuthor  : H. Saidi                                                    */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_B_BSW_PRE(void)
{
   diagnostic_bobine_b();
   IGNHAL_vidAdaptCoilCalc(IGNHAL_u8COIL_B);
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_B_BSW_POST                               */
/* !Description : BSW function called at the end of the OSTSK_S_DIAG_COIL_B   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_B_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_C_BSW_PRE                                */
/* !Description : BSW function called at the beginning of the                 */
/*                OSTSK_S_DIAG_COIL_C task                                    */
/*                                                                            */
/* !LastAuthor  : H. Saidi                                                    */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_C_BSW_PRE(void)
{
   diagnostic_bobine_c();
   IGNHAL_vidAdaptCoilCalc(IGNHAL_u8COIL_C);
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_C_BSW_POST                               */
/* !Description : BSW function called at the end of the OSTSK_S_DIAG_COIL_C   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_C_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_D_BSW_PRE                                */
/* !Description : BSW function called at the beginning of the                 */
/*                OSTSK_S_DIAG_COIL_D task                                    */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_D_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_D_BSW_POST                               */
/* !Description : BSW function called at the end of the OSTSK_S_DIAG_COIL_D   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_D_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_A_C_BSW_PRE                              */
/* !Description : BSW function called at the beginning of the                 */
/*                OSTSK_S_DIAG_COIL_A_C task                                  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_A_C_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_A_C_BSW_POST                             */
/* !Description : BSW function called at the end of the OSTSK_S_DIAG_COIL_A_C */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_A_C_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_B_D_BSW_PRE                              */
/* !Description : BSW function called at the beginning of the                 */
/*                OSTSK_S_DIAG_COIL_B_D  task                                 */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_B_D_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_B_D_BSW_POST                             */
/* !Description : BSW function called at the end of the                       */
/*                OSTSK_S_DIAG_COIL_B_D task                                  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_B_D_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidINCAM_DOWN_MODE_BSW_PRE                              */
/* !Description : BSW function called at the beginning of the Intake camshaft */
/*                Downgraded Mode Entry Callback                              */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidINCAM_DOWN_MODE_BSW_PRE(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidINCAM_NORMAL_MODE_BSW_PRE                            */
/* !Description : BSW function called at the beginning of the Intake camshaft */
/*                Normal Mode Entry Callback                                  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidINCAM_NORMAL_MODE_BSW_PRE(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidEXCAM_DOWN_MODE_BSW_PRE                              */
/* !Description : BSW function called at the beginning of the Exhaust camshaft*/
/*                Downgraded Mode Entry Callback                              */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidEXCAM_DOWN_MODE_BSW_PRE(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidEXCAM_NORMAL_MODE_BSW_PRE                            */
/* !Description : BSW function called at the beginning of the Exhaust camshaft*/
/*                Normal Mode Entry Callback                                  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidEXCAM_NORMAL_MODE_BSW_PRE(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_1_4_TDC_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the E_1_4_TDC task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_1_4_TDC_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_1_4_TDC_BSW_POST                                   */
/* !Description : BSW function called at the end of the E_1_4_TDC task        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_1_4_TDC_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidCRK_DOWN_MODE_BSW_PRE                                */
/* !Description : BSW function called at the beginning of the CRKHAL          */
/*                Downgraded Mode                                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidCRK_DOWN_MODE_BSW_PRE(void)
{
   CAMHAL_vidMngrCrkDwnModeEntry(CAMHAL_udtCH_CM_81);
}


/******************************************************************************/
/* !FuncName    : KRN_vidCRK_NORMAL_MODE_BSW_PRE                              */
/* !Description : BSW function called at the beginning of the CRKHAL Normal Mo*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidCRK_NORMAL_MODE_BSW_PRE(void)
{
   CAMHAL_vidMngrCrkNormalModeEntry();
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_IGK_ON_BSW_PRE                                     */
/* !Description : BSW function called at the beginning of the OSTSK_S_IGK_ON t*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_IGK_ON_BSW_PRE(void)
{
   DEVHAL_vidTrapDevaidPowerDown(DEVHAL_u8TRAP_PWD_INACTIVE);
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_IGK_ON_BSW_POST                                    */
/* !Description : BSW function called at the end of the OSTSK_S_IGK_ON task   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_IGK_ON_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_IGK_OFF_BSW_PRE                                    */
/* !Description : BSW function called at the beginning of the OSTSK_S_IGK_OFF */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_IGK_OFF_BSW_PRE(void)
{
   DEVHAL_vidTrapDevaidPowerDown(DEVHAL_u8TRAP_PWD_ACTIVE);
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_IGK_OFF_BSW_POST                                   */
/* !Description : BSW function called at the end of the OSTSK_S_IGK_OFF task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_IGK_OFF_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_EEST_BSW_PRE                                       */
/* !Description : BSW function called at the beginning of the OSTSK_S_EEST    */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : H. Saidi                                                    */
/******************************************************************************/
void KRN_vidS_EEST_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_EEST_BSW_POST                                      */
/* !Description : BSW function called at the end of the OSTSK_S_EEST task     */
/*                                                                            */
/* !LastAuthor  : H. Saidi                                                    */
/******************************************************************************/
void KRN_vidS_EEST_BSW_POST(void)
{
   RSTSRV_vidPowerDownEntry();
   NvMIf_vidWriteAll();
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_THR_BSW_PRE                                        */
/* !Description : BSW function called at the beginning of the OSTSK_S_THR task*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_THR_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_THR_BSW_POST                                       */
/* !Description : BSW function called at the end of the OSTSK_S_THR task      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_THR_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_SPILL_EVENT_BSW_PRE                                */
/* !Description : BSW function called at the beginning of the                 */
/*                OSTSK_S_SPILL_EVENT task                                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidS_SPILL_EVENT_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_SPILL_EVENT_BSW_POST                               */
/* !Description : BSW function called at the end of the OSTSK_S_SPILL_EVENT   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidS_SPILL_EVENT_BSW_POST(void)
{
   PMPHAL_vidSpillCommandManager();
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_N_INV_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the OSTSK_S_N_INV   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_N_INV_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_N_INV_BSW_POST                                     */
/* !Description : BSW function called at the end of the OSTSK_S_N_INV task    */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_N_INV_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_N_INV_OFF_BSW_PRE                                  */
/* !Description : BSW function called at the beginning of the S_N_INV_OFF     */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_N_INV_OFF_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_N_INV_OFF_BSW_POST                                 */
/* !Description : BSW function called at the end of the OSTSK_S_N_INV_OFF task*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_N_INV_OFF_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_TOOTH_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the S_TOOTH task    */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_TOOTH_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_TOOTH_BSW_POST                                     */
/* !Description : BSW function called at the end of the OSTSK_S_TOOTH task    */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_TOOTH_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_IN_CAM_EDGE_BSW_PRE                                */
/* !Description : BSW function called at the beginning of the S_IN_CAM_EDGE   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */  
/******************************************************************************/
void KRN_vidS_IN_CAM_EDGE_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_IN_CAM_EDGE_BSW_POST                               */
/* !Description : BSW function called at the end of the OSTSK_S_IN_CAM_EDGE   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_IN_CAM_EDGE_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_IN_CAM_PERIOD_BSW_PRE                              */
/* !Description : BSW function called at the beginning of the S_IN_CAM_PERIOD */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_IN_CAM_PERIOD_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_IN_CAM_PERIOD_BSW_POST                             */
/* !Description : BSW function called at the end of the OSTSK_S_IN_CAM_PERIOD */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_IN_CAM_PERIOD_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_EX_CAM_EDGE_BSW_PRE                                */
/* !Description : BSW function called at the beginning of the S_EX_CAM_EDGE   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_EX_CAM_EDGE_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_EX_CAM_EDGE_BSW_POST                               */
/* !Description : BSW function called at the end of the OSTSK_S_EX_CAM_EDGE   */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_EX_CAM_EDGE_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_EX_CAM_PERIOD_BSW_PRE                              */
/* !Description : BSW function called at the beginning of the S_EX_CAM_PERIOD */
/*                task                                                        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_EX_CAM_PERIOD_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_EX_CAM_PERIOD_BSW_POST                             */
/* !Description : BSW function called at the end of the S_EX_CAM_PERIOD task  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_EX_CAM_PERIOD_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_INJ_EVENT_BSW_PRE                                  */
/* !Description : BSW function called at the beginning of the INJ_EVENT event */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_INJ_EVENT_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_INJ_EVENT_BSW_POST                                 */
/* !Description : BSW function called in the end of the INJ_EVENT event       */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_INJ_EVENT_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_PTMHAL_EVT_BSW_PRE                                 */
/* !Description : BSW function called at the beginning of the PTMHAL event    */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_PTMHAL_EVT_BSW_PRE(void)
{
   PTMHAL_vidPacksDurationCalc(PTMHAL_u8PTMHAL_EVT_CALL);
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_PTMHAL_EVT_BSW_POST                                */
/* !Description : BSW function called at the end of the PTMHAL event          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_PTMHAL_EVT_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_TDC_1_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the TDC_1 event     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_TDC_1_BSW_PRE(void)
{
   switch (TDCHAL_ku8NumberOfCylinders)
   {
      case TDCHAL_u8THREE_CYLINDERS:
         KRN_vidS_TDC_BSW_PRE();
         break;

      case TDCHAL_u8FOUR_CYLINDERS:
         KRN_vidS_TDC_BSW_PRE();
         KRN_vidS_BDC_BSW_PRE();
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_TDC_1_BSW_POST                                     */
/* !Description : BSW function called at the end of the TDC_1 event           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_TDC_1_BSW_POST(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_TDC_2_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the TDC_2 event     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_TDC_2_BSW_PRE(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_TDC_2_BSW_POST                                     */
/* !Description : BSW function called at the end of the TDC_2 event           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_TDC_2_BSW_POST(void)
{
   switch (TDCHAL_ku8NumberOfCylinders)
   {
      case TDCHAL_u8THREE_CYLINDERS:
         KRN_vidS_TDC_BSW_POST();
         break;

      case TDCHAL_u8FOUR_CYLINDERS:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_BDC_1_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the BDC_1 event     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_BDC_1_BSW_PRE(void)
{
   switch (TDCHAL_ku8NumberOfCylinders)
   {
      case TDCHAL_u8THREE_CYLINDERS:
         KRN_vidS_BDC_BSW_PRE();
         break;

      case TDCHAL_u8FOUR_CYLINDERS:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_BDC_1_BSW_POST                                     */
/* !Description : BSW function called at the end of the BDC_1 event           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_BDC_1_BSW_POST(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_BDC_2_BSW_PRE                                      */
/* !Description : BSW function called at the beginning of the BDC_2 event     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_BDC_2_BSW_PRE(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_BDC_2_BSW_POST                                     */
/* !Description : BSW function called at the end of the BDC_2 event           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_BDC_2_BSW_POST(void)
{
   switch (TDCHAL_ku8NumberOfCylinders)
   {
      case TDCHAL_u8THREE_CYLINDERS:
         KRN_vidS_BDC_BSW_POST();
         break;

      case TDCHAL_u8FOUR_CYLINDERS:
         KRN_vidS_TDC_BSW_POST();
         KRN_vidS_BDC_BSW_POST();
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_WTDG_REFRESH_WATCHDOG_BSW_PRE                      */
/* !Description : BSW function called at the beginning of the task named      */
/*                OSTSK_S_WTDG_REFRESH_WATCHDOG_BSW                           */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidS_WTDG_REFRESH_WATCHDOG_BSW_PRE(void)
{
   Wdg_vidRefreshWatchdog();
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_WTDG_REFRESH_WATCHDOG_ASW_PRE                      */
/* !Description : BSW function called at the beginning of the task named      */
/*                OSTSK_S_WTDG_REFRESH_WATCHDOG_ASW                           */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidS_WTDG_REFRESH_WATCHDOG_ASW_PRE(void)
{
   Wdg_vidRefreshWatchdog();
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_DEVAID_COMM_CAN_BSW_PRE                            */
/* !Description : BSW function called at the beginning of the task named      */
/*                OSTSK_S_DEVAID_COMM_CAN                                     */
/*                                                                            */
/* !LastAuthor  : J. Soufflet                                                 */
/******************************************************************************/
void KRN_vidS_DEVAID_COMM_CAN_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_ICLC_EVENT_BSW_PRE                                 */
/* !Description : BSW function called at the beginning of the ICLC event      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidS_ICLC_EVENT_BSW_PRE(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidS_ICLC_EVENT_BSW_POST                                */
/* !Description : BSW function called at the end of the ICLC event            */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidS_ICLC_EVENT_BSW_POST(void)
{
}

#define KRN_STOP_SEC_CODE
#include "KRN_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

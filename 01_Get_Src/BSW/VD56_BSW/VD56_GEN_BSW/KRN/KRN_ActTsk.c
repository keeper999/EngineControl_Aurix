/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_ActTsk.c                                            */
/* !Description     : Defines Software tasks                                  */
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
 * %PID: P2017_BSW:0A192598.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Os.h"
#include "KRN_ActTsk.h"

#define KRN_START_SEC_CODE
#include "KRN_MemMap.h"

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_2MS_ASW                             */
/* !Description : This function active the task OSTSK_C_2MS_ASW               */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_2MS_ASW(void)
{
   ActivateTask(OSTSK_C_2MS_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_2MS_POST                            */
/* !Description : This function active the task OSTSK_C_2MS_POST              */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_2MS_POST(void)
{
   ActivateTask(OSTSK_C_2MS_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_2_5MS_1_ASW                         */
/* !Description : This function active the task OSTSK_C_2_5MS_1_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_2_5MS_1_ASW(void)
{
   ActivateTask(OSTSK_C_2_5MS_1_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_2_5MS_1_POST                        */
/* !Description : This function active the task OSTSK_C_2_5MS_1_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_2_5MS_1_POST(void)
{
   ActivateTask(OSTSK_C_2_5MS_1_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_2_5MS_2_ASW                         */
/* !Description : This function active the task OSTSK_C_2_5MS_2_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_2_5MS_2_ASW(void)
{
   ActivateTask(OSTSK_C_2_5MS_2_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_2_5MS_2_POST                        */
/* !Description : This function active the task OSTSK_C_2_5MS_2_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_2_5MS_2_POST(void)
{
   ActivateTask(OSTSK_C_2_5MS_2_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_5MS_1_ASW                           */
/* !Description : This function active the task OSTSK_C_5MS_1_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_5MS_1_ASW(void)
{
   ActivateTask(OSTSK_C_5MS_1_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_5MS_1_POST                          */
/* !Description : This function active the task OSTSK_C_5MS_1_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_5MS_1_POST(void)
{
   ActivateTask(OSTSK_C_5MS_1_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_5MS_2_ASW                           */
/* !Description : This function active the task OSTSK_C_5MS_2_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_5MS_2_ASW(void)
{
   ActivateTask(OSTSK_C_5MS_2_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_5MS_2_POST                          */
/* !Description : This function active the task OSTSK_C_5MS_2_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_5MS_2_POST(void)
{
   ActivateTask(OSTSK_C_5MS_2_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_5MS_3_ASW                           */
/* !Description : This function active the task OSTSK_C_5MS_3_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_5MS_3_ASW(void)
{
   ActivateTask(OSTSK_C_5MS_3_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_5MS_3_POST                          */
/* !Description : This function active the task OSTSK_C_5MS_3_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_5MS_3_POST(void)
{
   ActivateTask(OSTSK_C_5MS_3_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_5MS_4_ASW                           */
/* !Description : This function active the task OSTSK_C_5MS_4_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_5MS_4_ASW(void)
{
   ActivateTask(OSTSK_C_5MS_4_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_5MS_4_POST                          */
/* !Description : This function active the task OSTSK_C_5MS_4_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_5MS_4_POST(void)
{
   ActivateTask(OSTSK_C_5MS_4_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_5MS_5_ASW                           */
/* !Description : This function active the task OSTSK_C_5MS_5_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_5MS_5_ASW(void)
{
   ActivateTask(OSTSK_C_5MS_5_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_5MS_5_POST                          */
/* !Description : This function active the task OSTSK_C_5MS_5_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_5MS_5_POST(void)
{
   ActivateTask(OSTSK_C_5MS_5_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_1_ASW                          */
/* !Description : This function active the task OSTSK_C_10MS_1_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_1_ASW(void)
{
   ActivateTask(OSTSK_C_10MS_1_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_1_POST                         */
/* !Description : This function active the task OSTSK_C_10MS_1_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_1_POST(void)
{
   ActivateTask(OSTSK_C_10MS_1_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_2_ASW                          */
/* !Description : This function active the task OSTSK_C_10MS_2_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_2_ASW(void)
{
   ActivateTask(OSTSK_C_10MS_2_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_2_POST                         */
/* !Description : This function active the task OSTSK_C_10MS_2_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_2_POST(void)
{
   ActivateTask(OSTSK_C_10MS_2_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_3_ASW                          */
/* !Description : This function active the task OSTSK_C_10MS_3_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_3_ASW(void)
{
   ActivateTask(OSTSK_C_10MS_3_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_3_POST                         */
/* !Description : This function active the task OSTSK_C_10MS_3_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_3_POST(void)
{
   ActivateTask(OSTSK_C_10MS_3_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_4_ASW                          */
/* !Description : This function active the task OSTSK_C_10MS_4_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_4_ASW(void)
{
   ActivateTask(OSTSK_C_10MS_4_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_4_POST                         */
/* !Description : This function active the task OSTSK_C_10MS_4_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_4_POST(void)
{
   ActivateTask(OSTSK_C_10MS_4_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_5_ASW                          */
/* !Description : This function active the task OSTSK_C_10MS_5_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_5_ASW(void)
{
   ActivateTask(OSTSK_C_10MS_5_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_5_POST                         */
/* !Description : This function active the task OSTSK_C_10MS_5_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_5_POST(void)
{
   ActivateTask(OSTSK_C_10MS_5_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_6_ASW                          */
/* !Description : This function active the task OSTSK_C_10MS_6_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_6_ASW(void)
{
   ActivateTask(OSTSK_C_10MS_6_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_6_POST                         */
/* !Description : This function active the task OSTSK_C_10MS_6_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_6_POST(void)
{
   ActivateTask(OSTSK_C_10MS_6_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_7_ASW                          */
/* !Description : This function active the task OSTSK_C_10MS_7_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_7_ASW(void)
{
   ActivateTask(OSTSK_C_10MS_7_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_7_POST                         */
/* !Description : This function active the task OSTSK_C_10MS_7_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_7_POST(void)
{
   ActivateTask(OSTSK_C_10MS_7_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_8_ASW                          */
/* !Description : This function active the task OSTSK_C_10MS_8_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_8_ASW(void)
{
   ActivateTask(OSTSK_C_10MS_8_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_8_POST                         */
/* !Description : This function active the task OSTSK_C_10MS_8_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_8_POST(void)
{
   ActivateTask(OSTSK_C_10MS_8_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_9_ASW                          */
/* !Description : This function active the task OSTSK_C_10MS_9_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_9_ASW(void)
{
   ActivateTask(OSTSK_C_10MS_9_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_10MS_9_POST                         */
/* !Description : This function active the task OSTSK_C_10MS_9_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_10MS_9_POST(void)
{
   ActivateTask(OSTSK_C_10MS_9_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_20MS_1_ASW                          */
/* !Description : This function active the task OSTSK_C_20MS_1_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_20MS_1_ASW(void)
{
   ActivateTask(OSTSK_C_20MS_1_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_20MS_1_POST                         */
/* !Description : This function active the task OSTSK_C_20MS_1_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_20MS_1_POST(void)
{
   ActivateTask(OSTSK_C_20MS_1_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_20MS_2_ASW                          */
/* !Description : This function active the task OSTSK_C_20MS_2_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_20MS_2_ASW(void)
{
   ActivateTask(OSTSK_C_20MS_2_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_20MS_2_POST                         */
/* !Description : This function active the task OSTSK_C_20MS_2_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_20MS_2_POST(void)
{
   ActivateTask(OSTSK_C_20MS_2_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_20MS_3_ASW                          */
/* !Description : This function active the task OSTSK_C_20MS_3_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_20MS_3_ASW(void)
{
   ActivateTask(OSTSK_C_20MS_3_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_20MS_3_POST                         */
/* !Description : This function active the task OSTSK_C_20MS_3_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_20MS_3_POST(void)
{
   ActivateTask(OSTSK_C_20MS_3_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_20MS_4_ASW                          */
/* !Description : This function active the task OSTSK_C_20MS_4_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_20MS_4_ASW(void)
{
   ActivateTask(OSTSK_C_20MS_4_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_20MS_4_POST                         */
/* !Description : This function active the task OSTSK_C_20MS_4_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_20MS_4_POST(void)
{
   ActivateTask(OSTSK_C_20MS_4_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_20MS_5_ASW                          */
/* !Description : This function active the task OSTSK_C_20MS_5_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_20MS_5_ASW(void)
{
   ActivateTask(OSTSK_C_20MS_5_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_20MS_5_POST                         */
/* !Description : This function active the task OSTSK_C_20MS_5_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_20MS_5_POST(void)
{
   ActivateTask(OSTSK_C_20MS_5_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_40MS_1_ASW                          */
/* !Description : This function active the task OSTSK_C_40MS_1_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_40MS_1_ASW(void)
{
   ActivateTask(OSTSK_C_40MS_1_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_40MS_1_POST                         */
/* !Description : This function active the task OSTSK_C_40MS_1_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_40MS_1_POST(void)
{
   ActivateTask(OSTSK_C_40MS_1_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_40MS_2_ASW                          */
/* !Description : This function active the task OSTSK_C_40MS_2_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_40MS_2_ASW(void)
{
   ActivateTask(OSTSK_C_40MS_2_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_40MS_2_POST                         */
/* !Description : This function active the task OSTSK_C_40MS_2_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_40MS_2_POST(void)
{
   ActivateTask(OSTSK_C_40MS_2_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_40MS_3_ASW                          */
/* !Description : This function active the task OSTSK_C_40MS_3_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_40MS_3_ASW(void)
{
   ActivateTask(OSTSK_C_40MS_3_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_40MS_3_POST                         */
/* !Description : This function active the task OSTSK_C_40MS_3_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_40MS_3_POST(void)
{
   ActivateTask(OSTSK_C_40MS_3_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_40MS_4_ASW                          */
/* !Description : This function active the task OSTSK_C_40MS_4_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_40MS_4_ASW(void)
{
   ActivateTask(OSTSK_C_40MS_4_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_40MS_4_POST                         */
/* !Description : This function active the task OSTSK_C_40MS_4_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_40MS_4_POST(void)
{
   ActivateTask(OSTSK_C_40MS_4_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_40MS_5_ASW                          */
/* !Description : This function active the task OSTSK_C_40MS_5_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_40MS_5_ASW(void)
{
   ActivateTask(OSTSK_C_40MS_5_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_40MS_5_POST                         */
/* !Description : This function active the task OSTSK_C_40MS_5_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_40MS_5_POST(void)
{
   ActivateTask(OSTSK_C_40MS_5_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_50MS_ASW                            */
/* !Description : This function active the task OSTSK_C_50MS_ASW              */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_50MS_ASW(void)
{
   ActivateTask(OSTSK_C_50MS_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_50MS_POST                           */
/* !Description : This function active the task OSTSK_C_50MS_POST             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_50MS_POST(void)
{
   ActivateTask(OSTSK_C_50MS_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_100MS_1_ASW                         */
/* !Description : This function active the task OSTSK_C_100MS_1_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_100MS_1_ASW(void)
{
   ActivateTask(OSTSK_C_100MS_1_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_100MS_1_POST                        */
/* !Description : This function active the task OSTSK_C_100MS_1_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_100MS_1_POST(void)
{
   ActivateTask(OSTSK_C_100MS_1_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_100MS_2_ASW                         */
/* !Description : This function active the task OSTSK_C_100MS_2_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_100MS_2_ASW(void)
{
   ActivateTask(OSTSK_C_100MS_2_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_100MS_2_POST                        */
/* !Description : This function active the task OSTSK_C_100MS_2_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_100MS_2_POST(void)
{
   ActivateTask(OSTSK_C_100MS_2_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_100MS_3_ASW                         */
/* !Description : This function active the task OSTSK_C_100MS_3_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_100MS_3_ASW(void)
{
   ActivateTask(OSTSK_C_100MS_3_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_100MS_3_POST                        */
/* !Description : This function active the task OSTSK_C_100MS_3_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_100MS_3_POST(void)
{
   ActivateTask(OSTSK_C_100MS_3_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_200MS_1_ASW                         */
/* !Description : This function active the task OSTSK_C_200MS_1_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_200MS_1_ASW(void)
{
   ActivateTask(OSTSK_C_200MS_1_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_200MS_1_POST                        */
/* !Description : This function active the task OSTSK_C_200MS_1_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_200MS_1_POST(void)
{
   ActivateTask(OSTSK_C_200MS_1_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_200MS_2_ASW                         */
/* !Description : This function active the task OSTSK_C_200MS_2_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_200MS_2_ASW(void)
{
   ActivateTask(OSTSK_C_200MS_2_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_200MS_2_POST                        */
/* !Description : This function active the task OSTSK_C_200MS_2_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_200MS_2_POST(void)
{
   ActivateTask(OSTSK_C_200MS_2_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_200MS_3_ASW                         */
/* !Description : This function active the task OSTSK_C_200MS_3_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_200MS_3_ASW(void)
{
   ActivateTask(OSTSK_C_200MS_3_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_200MS_3_POST                        */
/* !Description : This function active the task OSTSK_C_200MS_3_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_200MS_3_POST(void)
{
   ActivateTask(OSTSK_C_200MS_3_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_200MS_4_ASW                         */
/* !Description : This function active the task OSTSK_C_200MS_4_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_200MS_4_ASW(void)
{
   ActivateTask(OSTSK_C_200MS_4_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_200MS_4_POST                        */
/* !Description : This function active the task OSTSK_C_200MS_4_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_200MS_4_POST(void)
{
   ActivateTask(OSTSK_C_200MS_4_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_400MS_ASW                           */
/* !Description : This function active the task OSTSK_C_400MS_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_400MS_ASW(void)
{
   ActivateTask(OSTSK_C_400MS_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_400MS_POST                          */
/* !Description : This function active the task OSTSK_C_400MS_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_400MS_POST(void)
{
   ActivateTask(OSTSK_C_400MS_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_1000MS_1_ASW                        */
/* !Description : This function active the task OSTSK_C_1000MS_1_ASW          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_1000MS_1_ASW(void)
{
   ActivateTask(OSTSK_C_1000MS_1_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_1000MS_1_POST                       */
/* !Description : This function active the task OSTSK_C_1000MS_1_POST         */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_1000MS_1_POST(void)
{
   ActivateTask(OSTSK_C_1000MS_1_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_1000MS_2_ASW                        */
/* !Description : This function active the task OSTSK_C_1000MS_2_ASW          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_1000MS_2_ASW(void)
{
   ActivateTask(OSTSK_C_1000MS_2_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_1000MS_2_POST                       */
/* !Description : This function active the task OSTSK_C_1000MS_2_POST         */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_1000MS_2_POST(void)
{
   ActivateTask(OSTSK_C_1000MS_2_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_1000MS_3_ASW                        */
/* !Description : This function active the task OSTSK_C_1000MS_3_ASW          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_1000MS_3_ASW(void)
{
   ActivateTask(OSTSK_C_1000MS_3_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_1000MS_3_POST                       */
/* !Description : This function active the task OSTSK_C_1000MS_3_POST         */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_1000MS_3_POST(void)
{
   ActivateTask(OSTSK_C_1000MS_3_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_1000MS_4_ASW                        */
/* !Description : This function active the task OSTSK_C_1000MS_4_ASW          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_1000MS_4_ASW(void)
{
   ActivateTask(OSTSK_C_1000MS_4_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_1000MS_4_POST                       */
/* !Description : This function active the task OSTSK_C_1000MS_4_POST         */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_1000MS_4_POST(void)
{
   ActivateTask(OSTSK_C_1000MS_4_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_1000MS_5_ASW                        */
/* !Description : This function active the task OSTSK_C_1000MS_5_ASW          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_1000MS_5_ASW(void)
{
   ActivateTask(OSTSK_C_1000MS_5_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_1000MS_5_POST                       */
/* !Description : This function active the task OSTSK_C_1000MS_5_POST         */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_1000MS_5_POST(void)
{
   ActivateTask(OSTSK_C_1000MS_5_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_2000MS_ASW                          */
/* !Description : This function active the task OSTSK_C_2000MS_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_2000MS_ASW(void)
{
   ActivateTask(OSTSK_C_2000MS_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_2000MS_POST                         */
/* !Description : This function active the task OSTSK_C_2000MS_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_2000MS_POST(void)
{
   ActivateTask(OSTSK_C_2000MS_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_4000MS_ASW                          */
/* !Description : This function active the task OSTSK_C_4000MS_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_4000MS_ASW(void)
{
   ActivateTask(OSTSK_C_4000MS_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_4000MS_POST                         */
/* !Description : This function active the task OSTSK_C_4000MS_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_4000MS_POST(void)
{
   ActivateTask(OSTSK_C_4000MS_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_60000MS_ASW                         */
/* !Description : This function active the task OSTSK_C_60000MS_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_60000MS_ASW(void)
{
   ActivateTask(OSTSK_C_60000MS_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_C_60000MS_POST                        */
/* !Description : This function active the task OSTSK_C_60000MS_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_C_60000MS_POST(void)
{
   ActivateTask(OSTSK_C_60000MS_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_1_4_TDC_ASW                         */
/* !Description : This function active the task OSTSK_S_1_4_TDC_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_1_4_TDC_ASW(void)
{
   ActivateTask(OSTSK_S_1_4_TDC_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_1_4_TDC_POST                        */
/* !Description : This function active the task OSTSK_S_1_4_TDC_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_1_4_TDC_POST(void)
{
   ActivateTask(OSTSK_S_1_4_TDC_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_TDC_1_ASW                           */
/* !Description : This function active the task OSTSK_S_TDC_1_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_TDC_1_ASW(void)
{
   ActivateTask(OSTSK_S_TDC_1_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_TDC_1_POST                          */
/* !Description : This function active the task OSTSK_S_TDC_1_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_TDC_1_POST(void)
{
   ActivateTask(OSTSK_S_TDC_1_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_TDC_2_ASW                           */
/* !Description : This function active the task OSTSK_S_TDC_2_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_TDC_2_ASW(void)
{
   ActivateTask(OSTSK_S_TDC_2_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_TDC_2_POST                          */
/* !Description : This function active the task OSTSK_S_TDC_2_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_TDC_2_POST(void)
{
   ActivateTask(OSTSK_S_TDC_2_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_BDC_1_ASW                           */
/* !Description : This function active the task OSTSK_S_BDC_1_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_BDC_1_ASW(void)
{
   ActivateTask(OSTSK_S_BDC_1_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_BDC_1_POST                          */
/* !Description : This function active the task OSTSK_S_BDC_1_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_BDC_1_POST(void)
{
   ActivateTask(OSTSK_S_BDC_1_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_BDC_2_ASW                           */
/* !Description : This function active the task OSTSK_S_BDC_2_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_BDC_2_ASW(void)
{
   ActivateTask(OSTSK_S_BDC_2_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_BDC_2_POST                          */
/* !Description : This function active the task OSTSK_S_BDC_2_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_BDC_2_POST(void)
{
   ActivateTask(OSTSK_S_BDC_2_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_KNK_WIN_ASW                         */
/* !Description : This function active the task OSTSK_S_KNK_WIN_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_KNK_WIN_ASW(void)
{
   ActivateTask(OSTSK_S_KNK_WIN_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_KNK_WIN_POST                        */
/* !Description : This function active the task OSTSK_S_KNK_WIN_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_KNK_WIN_POST(void)
{
   ActivateTask(OSTSK_S_KNK_WIN_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_CRK_ON_ASW                          */
/* !Description : This function active the task OSTSK_S_CRK_ON_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_CRK_ON_ASW(void)
{
   ActivateTask(OSTSK_S_CRK_ON_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_CRK_ON_POST                         */
/* !Description : This function active the task OSTSK_S_CRK_ON_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_CRK_ON_POST(void)
{
   ActivateTask(OSTSK_S_CRK_ON_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_ENG_RUN_ASW                         */
/* !Description : This function active the task OSTSK_S_ENG_RUN_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_ENG_RUN_ASW(void)
{
   ActivateTask(OSTSK_S_ENG_RUN_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_ENG_RUN_POST                        */
/* !Description : This function active the task OSTSK_S_ENG_RUN_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_ENG_RUN_POST(void)
{
   ActivateTask(OSTSK_S_ENG_RUN_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_LTOO1_ASW                           */
/* !Description : This function active the task OSTSK_S_LTOO1_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_LTOO1_ASW(void)
{
   ActivateTask(OSTSK_S_LTOO1_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_LTOO1_POST                          */
/* !Description : This function active the task OSTSK_S_LTOO1_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_LTOO1_POST(void)
{
   ActivateTask(OSTSK_S_LTOO1_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_LTOO_ASW                            */
/* !Description : This function active the task OSTSK_S_LTOO_ASW              */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_LTOO_ASW(void)
{
   ActivateTask(OSTSK_S_LTOO_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_LTOO_POST_ASW                       */
/* !Description : This function active the task OSTSK_S_LTOO_POST_ASW         */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_LTOO_POST(void)
{
   ActivateTask(OSTSK_S_LTOO_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_TOLO_ASW                            */
/* !Description : This function active the task OSTSK_S_TOLO_ASW              */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_TOLO_ASW(void)
{
   ActivateTask(OSTSK_S_TOLO_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_TOLO_POST                           */
/* !Description : This function active the task OSTSK_S_TOLO_POST             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_TOLO_POST(void)
{
   ActivateTask(OSTSK_S_TOLO_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_ENG_STAL_ASW                        */
/* !Description : This function active the task OSTSK_S_ENG_STAL_ASW          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_ENG_STAL_ASW(void)
{
   ActivateTask(OSTSK_S_ENG_STAL_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_ENG_STAL_POST                       */
/* !Description : This function active the task OSTSK_S_ENG_STAL_POST         */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_ENG_STAL_POST(void)
{
   ActivateTask(OSTSK_S_ENG_STAL_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_CRK_OFF_ASW                         */
/* !Description : This function active the task OSTSK_S_CRK_OFF_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_CRK_OFF_ASW(void)
{
   ActivateTask(OSTSK_S_CRK_OFF_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_CRK_OFF_POST                        */
/* !Description : This function active the task OSTSK_S_CRK_OFF_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_CRK_OFF_POST(void)
{
   ActivateTask(OSTSK_S_CRK_OFF_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_A_ASW                     */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_A_ASW       */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_A_ASW(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_A_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_A_POST                    */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_A_POST      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_A_POST(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_A_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_B_ASW                     */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_B_ASW       */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_B_ASW(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_B_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_B_POST                    */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_B_POST      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_B_POST(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_B_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_C_ASW                     */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_C_ASW       */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_C_ASW(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_C_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_C_POST                    */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_C_POST      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_C_POST(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_C_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_D_ASW                     */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_D_ASW       */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_D_ASW(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_D_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_D_POST                    */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_D_POST      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_D_POST(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_D_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_A_C_ASW                   */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_A_C_ASW     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_A_C_ASW(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_A_C_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_A_C_POST                  */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_A_C_BSW_POST*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_A_C_POST(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_A_C_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_B_D_ASW                   */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_B_D_ASW     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_B_D_ASW(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_B_D_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_DIAG_COIL_B_D_POST                  */
/* !Description : This function active the task OSTSK_S_DIAG_COIL_B_D_BSW_POST*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_DIAG_COIL_B_D_POST(void)
{
   ActivateTask(OSTSK_S_DIAG_COIL_B_D_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_IGK_ON_ASW                          */
/* !Description : This function active the task OSTSK_S_IGK_ON_ASW            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_IGK_ON_ASW(void)
{
   ActivateTask(OSTSK_S_IGK_ON_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_IGK_ON_POST                         */
/* !Description : This function active the task OSTSK_S_IGK_ON_POST           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_IGK_ON_POST(void)
{
   ActivateTask(OSTSK_S_IGK_ON_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_IGK_OFF_ASW                         */
/* !Description : This function active the task OSTSK_S_IGK_OFF_ASW           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_IGK_OFF_ASW(void)
{
   ActivateTask(OSTSK_S_IGK_OFF_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_IGK_OFF_POST                        */
/* !Description : This function active the task OSTSK_S_IGK_OFF_POST          */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_IGK_OFF_POST(void)
{
   ActivateTask(OSTSK_S_IGK_OFF_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_EEST_ASW                            */
/* !Description : This function active the task OSTSK_S_EEST_ASW              */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_EEST_ASW(void)
{
   ActivateTask(OSTSK_S_EEST_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_EEST_POST                           */
/* !Description : This function active the task OSTSK_S_EEST_POST             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_EEST_POST(void)
{
   ActivateTask(OSTSK_S_EEST_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_THR_ASW                             */
/* !Description : This function active the task OSTSK_S_THR_ASW               */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_THR_ASW(void)
{
   ActivateTask(OSTSK_S_THR_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_THR_POST                            */
/* !Description : This function active the task OSTSK_S_THR_POST              */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_THR_POST(void)
{
   ActivateTask(OSTSK_S_THR_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_SPILL_EVENT_ASW                     */
/* !Description : This function active the task OSTSK_S_SPILL_EVENT_ASW       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_SPILL_EVENT_ASW(void)
{
   ActivateTask(OSTSK_S_SPILL_EVENT_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_SPILL_EVENT_POST                    */
/* !Description : This function active the task OSTSK_S_SPILL_EVENT_BSW_POST  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_SPILL_EVENT_POST(void)
{
   ActivateTask(OSTSK_S_SPILL_EVENT_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_N_INV_ASW                           */
/* !Description : This function active the task OSTSK_S_N_INV_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_N_INV_ASW(void)
{
   ActivateTask(OSTSK_S_N_INV_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_N_INV_POST                          */
/* !Description : This function active the task OSTSK_S_N_INV_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_N_INV_POST(void)
{
   ActivateTask(OSTSK_S_N_INV_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_N_INV_OFF_ASW                       */
/* !Description : This function active the task OSTSK_S_N_INV_OFF_ASW         */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_N_INV_OFF_ASW(void)
{
   ActivateTask(OSTSK_S_N_INV_OFF_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_N_INV_OFF_POST                      */
/* !Description : This function active the task OSTSK_S_N_INV_OFF_POST        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_N_INV_OFF_POST(void)
{
   ActivateTask(OSTSK_S_N_INV_OFF_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_TOOTH_ASW                           */
/* !Description : This function active the task OSTSK_S_TOOTH_ASW             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_TOOTH_ASW(void)
{
   ActivateTask(OSTSK_S_TOOTH_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_TOOTH_POST                          */
/* !Description : This function active the task OSTSK_S_TOOTH_POST            */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_TOOTH_POST(void)
{
   ActivateTask(OSTSK_S_TOOTH_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_IN_CAM_EDGE_ASW                     */
/* !Description : This function active the task OSTSK_S_IN_CAM_EDGE_ASW       */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_IN_CAM_EDGE_ASW(void)
{
   ActivateTask(OSTSK_S_IN_CAM_EDGE_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_IN_CAM_EDGE_POST                    */
/* !Description : This function active the task OSTSK_S_IN_CAM_EDGE_POST      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_IN_CAM_EDGE_POST(void)
{
   ActivateTask(OSTSK_S_IN_CAM_EDGE_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_IN_CAM_PERIOD_ASW                   */
/* !Description : This function active the task OSTSK_S_IN_CAM_PERIOD_ASW     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_IN_CAM_PERIOD_ASW(void)
{
   ActivateTask(OSTSK_S_IN_CAM_PERIOD_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_IN_CAM_PERIOD_POST                  */
/* !Description : This function active the task OSTSK_S_IN_CAM_PERIOD_BSW_POST*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_IN_CAM_PERIOD_POST(void)
{
   ActivateTask(OSTSK_S_IN_CAM_PERIOD_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_EX_CAM_EDGE_ASW                     */
/* !Description : This function active the task OSTSK_S_EX_CAM_EDGE_ASW       */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_EX_CAM_EDGE_ASW(void)
{
   ActivateTask(OSTSK_S_EX_CAM_EDGE_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_EX_CAM_EDGE_POST                    */
/* !Description : This function active the task OSTSK_S_EX_CAM_EDGE_POST      */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_EX_CAM_EDGE_POST(void)
{
   ActivateTask(OSTSK_S_EX_CAM_EDGE_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_EX_CAM_PERIOD_ASW                   */
/* !Description : This function active the task OSTSK_S_EX_CAM_PERIOD_ASW     */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_EX_CAM_PERIOD_ASW(void)
{
   ActivateTask(OSTSK_S_EX_CAM_PERIOD_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_EX_CAM_PERIOD_POST                  */
/* !Description : This function active the task OSTSK_S_EX_CAM_PERIOD_BSW_POST*/
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_EX_CAM_PERIOD_POST(void)
{
   ActivateTask(OSTSK_S_EX_CAM_PERIOD_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_INJ_EVENT_ASW                       */
/* !Description : This function active the task OSTSK_S_INJ_EVENT_ASW         */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_INJ_EVENT_ASW(void)
{
   ActivateTask(OSTSK_S_INJ_EVENT_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_INJ_EVENT_POST                      */
/* !Description : This function active the task OSTSK_S_INJ_EVENT_POST        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_INJ_EVENT_POST(void)
{
   ActivateTask(OSTSK_S_INJ_EVENT_POST);
}
/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_PTMHAL_EVT_ASW                      */
/* !Description : This function active the task OSTSK_S_PTMHAL_EVT_ASW        */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_PTMHAL_EVT_ASW(void)
{
   ActivateTask(OSTSK_S_PTMHAL_EVT_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_PTMHAL_EVT_POST                     */
/* !Description : This function active the task OSTSK_S_PTMHAL_EVT_POST       */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_PTMHAL_EVT_POST(void)
{
   ActivateTask(OSTSK_S_PTMHAL_EVT_POST);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_ICLC_EVENT_ASW                      */
/* !Description : This function active the task OSTSK_S_ICLC_EVENT_ASW        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_ICLC_EVENT_ASW(void)
{
   ActivateTask(OSTSK_S_ICLC_EVENT_ASW);
}

/******************************************************************************/
/* !FuncName    : KRN_vidActivate_OSTSK_S_ICLC_EVENT_POST                     */
/* !Description : This function active the task OSTSK_S_ICLC_EVENT_BSW_POST   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidActivate_OSTSK_S_ICLC_EVENT_POST(void)
{
   ActivateTask(OSTSK_S_ICLC_EVENT_POST);
}

#define KRN_STOP_SEC_CODE
#include "KRN_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

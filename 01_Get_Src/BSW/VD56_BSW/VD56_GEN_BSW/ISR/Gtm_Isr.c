/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ISR                                                     */
/* !Description     : ISR Management                                          */
/*                                                                            */
/* !File            : Gtm_Isr.c                                               */
/* !Description     : ISR definition of Gtm component                         */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192597.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Gtm.h"
#include "Isr_Cfg.h"
#include "Os.h"

/******************************************************************************/
/* !Comment: Declaration of ISR linked to TOM, ATOM and TIM                   */
/*           Except for TIM0_0 and TIM0_1 reserved for CRKHAL component       */
/******************************************************************************/

#define ISR_START_SEC_CODE
#include "ISR_MemMap.h"

/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM0_0_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM0_0 & TOM0_1  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM0_0_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM0_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(0, 0);
}
#endif /* if (SRC_GTM_GTM0_TOM0_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM0_1_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM0_2 & TOM0_3  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM0_1_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM0_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(0, 2);
}
#endif /* if (SRC_GTM_GTM0_TOM0_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM0_2_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM0_4 & TOM0_5  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM0_2_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM0_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(0, 4);
}
#endif /* if (SRC_GTM_GTM0_TOM0_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM0_3_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM0_6 & TOM0_7  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM0_3_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM0_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(0, 6);
}
#endif /* if (SRC_GTM_GTM0_TOM0_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM0_4_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM0_8 & TOM0_9  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM0_4_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM0_4_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(0, 8);
}
#endif /* if (SRC_GTM_GTM0_TOM0_4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM0_5_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM0_10 & TOM0_11*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM0_5_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM0_5_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(0, 10);
}
#endif /* if (SRC_GTM_GTM0_TOM0_5_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM0_6_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM0_12 & TOM0_13*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM0_6_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM0_6_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(0, 12);
}
#endif /* if (SRC_GTM_GTM0_TOM0_6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM0_7_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM0_14 & TOM0_15*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM0_7_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM0_7_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(0, 14);
}
#endif /* if (SRC_GTM_GTM0_TOM0_7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM1_0_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM1_0 & TOM1_1  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM1_0_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM1_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(1, 0);
}
#endif /* if (SRC_GTM_GTM0_TOM1_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM1_1_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM1_2 & TOM1_3  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM1_1_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM1_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(1, 2);
}
#endif /* if (SRC_GTM_GTM0_TOM1_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM1_2_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM1_4 & TOM1_5  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM1_2_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM1_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(1, 4);
}
#endif /* if (SRC_GTM_GTM0_TOM1_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM1_3_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM1_6 & TOM1_7  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM1_3_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM1_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(1, 6);
}
#endif /* if (SRC_GTM_GTM0_TOM1_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM1_4_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM1_8 & TOM1_9  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM1_4_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM1_4_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(1, 8);
}
#endif /* if (SRC_GTM_GTM0_TOM1_4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM1_5_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM1_10 & TOM1_11*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM1_5_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM1_5_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(1, 10);
}
#endif /* if (SRC_GTM_GTM0_TOM1_5_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM1_6_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM1_12 & TOM1_13*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM1_6_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM1_6_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(1, 12);
}
#endif /* if (SRC_GTM_GTM0_TOM1_6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM1_7_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM1_14 & TOM1_15*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM1_7_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM1_7_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(1, 14);
}
#endif /* if (SRC_GTM_GTM0_TOM1_7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM2_0_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM2_0 & TOM2_1  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM2_0_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM2_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(2, 0);
}
#endif /* if (SRC_GTM_GTM0_TOM2_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM2_1_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM2_2 & TOM2_3  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM2_1_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM2_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(2, 2);
}
#endif /* if (SRC_GTM_GTM0_TOM2_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM2_2_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM2_4 & TOM2_5  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM2_2_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM2_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(2, 4);
}
#endif /* if (SRC_GTM_GTM0_TOM2_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM2_3_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM2_6 & TOM2_7  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM2_3_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM2_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(2, 6);
}
#endif /* if (SRC_GTM_GTM0_TOM2_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM2_4_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM2_8 & TOM2_9  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM2_4_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM2_4_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(2, 8);
}
#endif /* if (SRC_GTM_GTM0_TOM2_4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM2_5_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM2_10 & TOM2_11*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM2_5_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM2_5_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(2, 10);
}
#endif /* if (SRC_GTM_GTM0_TOM2_5_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM2_6_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM2_12 & TOM2_13*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM2_6_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM2_6_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(2, 12);
}
#endif /* if (SRC_GTM_GTM0_TOM2_6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM2_7_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM2_14 & TOM2_15*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM2_7_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM2_7_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(2, 14);
}
#endif /* if (SRC_GTM_GTM0_TOM2_7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM3_0_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM3_0 & TOM3_1  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM3_0_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM3_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(3, 0);
}
#endif /* if (SRC_GTM_GTM0_TOM3_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM3_1_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM3_2 & TOM3_3  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM3_1_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM3_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(3, 2);
}
#endif /* if (SRC_GTM_GTM0_TOM3_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM3_2_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM3_4 & TOM3_5  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM3_2_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM3_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(3, 4);
}
#endif /* if (SRC_GTM_GTM0_TOM3_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM3_3_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM3_6 & TOM3_7  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM3_3_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM3_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(3, 6);
}
#endif /* if (SRC_GTM_GTM0_TOM3_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM3_4_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM3_8 & TOM3_9  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM3_4_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM3_4_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(3, 8);
}
#endif /* if (SRC_GTM_GTM0_TOM3_4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM3_5_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM3_10 & TOM3_11*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM3_5_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM3_5_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(3, 10);
}
#endif /* if (SRC_GTM_GTM0_TOM3_5_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM3_6_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM3_12 & TOM3_13*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM3_6_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM3_6_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(3, 12);
}
#endif /* if (SRC_GTM_GTM0_TOM3_6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM3_7_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM3_14 & TOM3_15*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM3_7_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM3_7_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(3, 14);
}
#endif /* if (SRC_GTM_GTM0_TOM3_7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM4_0_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM4_0 & TOM4_1  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM4_0_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM4_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(4, 0);
}
#endif /* if (SRC_GTM_GTM0_TOM4_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM4_1_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM4_2 & TOM4_3  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM4_1_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM4_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(4, 2);
}
#endif /* if (SRC_GTM_GTM0_TOM4_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM4_2_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM4_4 & TOM4_5  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM4_2_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM4_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(4, 4);
}
#endif /* if (SRC_GTM_GTM0_TOM4_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM4_3_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM4_6 & TOM4_7  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM4_3_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM4_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(4, 6);
}
#endif /* if (SRC_GTM_GTM0_TOM4_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM4_4_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM4_8 & TOM4_9  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM4_4_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM4_4_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(4, 8);
}
#endif /* if (SRC_GTM_GTM0_TOM4_4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM4_5_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM4_10 & TOM4_11*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM4_5_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM4_5_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(4, 10);
}
#endif /* if (SRC_GTM_GTM0_TOM4_5_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM4_6_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM4_12 & TOM4_13*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM4_6_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM4_6_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(4, 12);
}
#endif /* if (SRC_GTM_GTM0_TOM4_6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TOM4_7_ISR)                                */
/* !Description : Interrupt for GTM TOM modules for channels TOM4_14 & TOM4_15*/
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TOM4_7_USED == STD_ON)
INT(SRC_GTM_GTM0_TOM4_7_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTomModule(4, 14);
}
#endif /* if (SRC_GTM_GTM0_TOM4_7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM0_0_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM0_0 & ATOM0_1      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM0_0_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM0_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(0, 0);
}
#endif /* if (SRC_GTM_GTM0_ATOM0_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM0_1_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM0_2 & ATOM0_3      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM0_1_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM0_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(0, 2);
}
#endif /* if (SRC_GTM_GTM0_ATOM0_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM0_2_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM0_4 & ATOM0_5      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM0_2_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM0_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(0, 4);
}
#endif /* if (SRC_GTM_GTM0_ATOM0_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM0_3_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM0_6 & ATOM0_7      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM0_3_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM0_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(0, 6);
}
#endif /* if (SRC_GTM_GTM0_ATOM0_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM1_0_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM1_0 & ATOM1_1      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM1_0_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM1_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(1, 0);
}
#endif /* if (SRC_GTM_GTM0_ATOM1_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM1_1_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM1_2 & ATOM1_3      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM1_1_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM1_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(1, 2);
}
#endif /* if (SRC_GTM_GTM0_ATOM1_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM1_2_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM1_4 & ATOM1_5      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM1_2_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM1_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(1, 4);
}
#endif /* if (SRC_GTM_GTM0_ATOM1_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM1_3_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM1_6 & ATOM1_7      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM1_3_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM1_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(1, 6);
}
#endif /* if (SRC_GTM_GTM0_ATOM1_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM2_0_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM2_0 & ATOM2_1      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM2_0_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM2_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(2, 0);
}
#endif /* if (SRC_GTM_GTM0_ATOM2_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM2_1_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM2_2 & ATOM2_3      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM2_1_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM2_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(2, 2);
}
#endif /* if (SRC_GTM_GTM0_ATOM2_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM2_2_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM2_4 & ATOM2_5      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM2_2_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM2_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(2, 4);
}
#endif /* if (SRC_GTM_GTM0_ATOM2_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM2_3_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM2_6 & ATOM2_7      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM2_3_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM2_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(2, 6);
}
#endif /* if (SRC_GTM_GTM0_ATOM2_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM3_0_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM3_0 & ATOM3_1      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM3_0_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM3_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(3, 0);
}
#endif /* if (SRC_GTM_GTM0_ATOM3_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM3_1_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM3_2 & ATOM3_3      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM3_1_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM3_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(3, 2);
}
#endif /* if (SRC_GTM_GTM0_ATOM3_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM3_2_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM3_4 & ATOM3_5      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM3_2_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM3_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(3, 4);
}
#endif /* if (SRC_GTM_GTM0_ATOM3_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM3_3_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM3_6 & ATOM3_7      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM3_3_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM3_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(3, 6);
}
#endif /* if (SRC_GTM_GTM0_ATOM3_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM4_0_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM4_0 & ATOM4_1      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM4_0_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM4_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(4, 0);
}
#endif /* if (SRC_GTM_GTM0_ATOM4_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM4_1_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM4_2 & ATOM4_3      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM4_1_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM4_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(4, 2);
}
#endif /* if (SRC_GTM_GTM0_ATOM4_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM4_2_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM4_4 & ATOM4_5      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM4_2_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM4_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(4, 4);
}
#endif /* if (SRC_GTM_GTM0_ATOM4_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM4_3_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM4_6 & ATOM4_7      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM4_3_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM4_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(4, 6);
}
#endif /* if (SRC_GTM_GTM0_ATOM4_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM5_0_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM5_0 & ATOM5_1      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM5_0_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM5_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(5, 0);
}
#endif /* if (SRC_GTM_GTM0_ATOM5_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM5_1_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM5_2 & ATOM5_3      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM5_1_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM5_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(5, 2);
}
#endif /* if (SRC_GTM_GTM0_ATOM5_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM5_2_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM5_4 & ATOM5_5      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM5_2_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM5_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(5, 4);
}
#endif /* if (SRC_GTM_GTM0_ATOM5_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM5_3_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM5_6 & ATOM5_7      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM5_3_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM5_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(5, 6);
}
#endif /* if (SRC_GTM_GTM0_ATOM5_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM6_0_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM6_0 & ATOM6_1      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM6_0_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM6_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(6, 0);
}
#endif /* if (SRC_GTM_GTM0_ATOM6_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM6_1_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM6_2 & ATOM6_3      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM6_1_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM6_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(6, 2);
}
#endif /* if (SRC_GTM_GTM0_ATOM6_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM6_2_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM6_4 & ATOM6_5      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM6_2_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM6_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(6, 4);
}
#endif /* if (SRC_GTM_GTM0_ATOM6_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM6_3_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM6_6 & ATOM6_7      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM6_3_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM6_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(6, 6);
}
#endif /* if (SRC_GTM_GTM0_ATOM6_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM7_0_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM7_0 & ATOM7_1      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM7_0_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM7_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(7, 0);
}
#endif /* if (SRC_GTM_GTM0_ATOM7_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM7_1_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM7_2 & ATOM7_3      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM7_1_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM7_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(7, 2);
}
#endif /* if (SRC_GTM_GTM0_ATOM7_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM7_2_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM7_4 & ATOM7_5      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM7_2_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM7_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(7, 4);
}
#endif /* if (SRC_GTM_GTM0_ATOM7_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM7_3_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM7_6 & ATOM7_7      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM7_3_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM7_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(7, 6);
}
#endif /* if (SRC_GTM_GTM0_ATOM7_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM8_0_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM8_0 & ATOM8_1      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM8_0_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM8_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(8, 0);
}
#endif /* if (SRC_GTM_GTM0_ATOM8_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM8_1_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM8_2 & ATOM8_3      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM8_1_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM8_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(8, 2);
}
#endif /* if (SRC_GTM_GTM0_ATOM8_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM8_2_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM8_4 & ATOM8_5      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM8_2_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM8_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(8, 4);
}
#endif /* if (SRC_GTM_GTM0_ATOM8_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_ATOM8_3_ISR)                               */
/* !Description : IT for GTM ATOM modules for channels ATOM8_6 & ATOM8_7      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_ATOM8_3_USED == STD_ON)
INT(SRC_GTM_GTM0_ATOM8_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrAtomModule(8, 6);
}
#endif /* if (SRC_GTM_GTM0_ATOM8_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM0_2_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM0_2             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM0_2_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM0_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(0, 2);
}
#endif /* if (SRC_GTM_GTM0_TIM0_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM0_3_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM0_3             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM0_3_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM0_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(0, 3);
}
#endif /* if (SRC_GTM_GTM0_TIM0_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM0_4_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM0_4             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM0_4_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM0_4_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(0, 4);
}
#endif /* if (SRC_GTM_GTM0_TIM0_4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM0_5_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM0_5             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM0_5_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM0_5_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(0, 5);
}
#endif /* if (SRC_GTM_GTM0_TIM0_5_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM0_6_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM0_6             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM0_6_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM0_6_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(0, 6);
}
#endif /* if (SRC_GTM_GTM0_TIM0_6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM0_7_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM0_7             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM0_7_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM0_7_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(0, 7);
}
#endif /* if (SRC_GTM_GTM0_TIM0_7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM1_0_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM1_0             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM1_0_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM1_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(1, 0);
}
#endif /* if (SRC_GTM_GTM0_TIM1_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM1_1_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM1_1             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM1_1_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM1_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(1, 1);
}
#endif /* if (SRC_GTM_GTM0_TIM1_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM1_2_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM1_2             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM1_2_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM1_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(1, 2);
}
#endif /* if (SRC_GTM_GTM0_TIM1_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM1_3_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM1_3             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM1_3_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM1_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(1, 3);
}
#endif /* if (SRC_GTM_GTM0_TIM1_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM1_4_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM1_4             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM1_4_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM1_4_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(1, 4);
}
#endif /* if (SRC_GTM_GTM0_TIM1_4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM1_5_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM1_5             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM1_5_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM1_5_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(1, 5);
}
#endif /* if (SRC_GTM_GTM0_TIM1_5_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM1_6_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM1_6             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM1_6_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM1_6_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(1, 6);
}
#endif /* if (SRC_GTM_GTM0_TIM1_6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM1_7_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM1_7             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM1_7_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM1_7_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(1, 7);
}
#endif /* if (SRC_GTM_GTM0_TIM1_7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM2_0_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM2_0             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM2_0_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM2_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(2, 0);
}
#endif /* if (SRC_GTM_GTM0_TIM2_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM2_1_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM2_1             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM2_1_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM2_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(2, 1);
}
#endif /* if (SRC_GTM_GTM0_TIM2_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM2_2_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM2_2             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM2_2_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM2_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(2, 2);
}
#endif /* if (SRC_GTM_GTM0_TIM2_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM2_3_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM2_3             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM2_3_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM2_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(2, 3);
}
#endif /* if (SRC_GTM_GTM0_TIM2_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM2_4_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM2_4             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM2_4_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM2_4_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(2, 4);
}
#endif /* if (SRC_GTM_GTM0_TIM2_4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM2_5_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM2_5             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM2_5_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM2_5_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(2, 5);
}
#endif /* if (SRC_GTM_GTM0_TIM2_5_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM2_6_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM2_6             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM2_6_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM2_6_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(2, 6);
}
#endif /* if (SRC_GTM_GTM0_TIM2_6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM2_7_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM2_7             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM2_7_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM2_7_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(2, 7);
}
#endif /* if (SRC_GTM_GTM0_TIM2_7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM3_0_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM3_0             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM3_0_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM3_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(3, 0);
}
#endif /* if (SRC_GTM_GTM0_TIM3_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM3_1_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM3_1             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM3_1_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM3_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(3, 1);
}
#endif /* if (SRC_GTM_GTM0_TIM3_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM3_2_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM3_2             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM3_2_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM3_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(3, 2);
}
#endif /* if (SRC_GTM_GTM0_TIM3_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM3_3_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM3_3             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM3_3_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM3_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(3, 3);
}
#endif /* if (SRC_GTM_GTM0_TIM3_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM3_4_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM3_4             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM3_4_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM3_4_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(3, 4);
}
#endif /* if (SRC_GTM_GTM0_TIM3_4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM3_5_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM3_5             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM3_5_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM3_5_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(3, 5);
}
#endif /* if (SRC_GTM_GTM0_TIM3_5_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM3_6_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM3_6             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM3_6_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM3_6_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(3, 6);
}
#endif /* if (SRC_GTM_GTM0_TIM3_6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM3_7_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM3_7             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM3_7_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM3_7_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(3, 7);
}
#endif /* if (SRC_GTM_GTM0_TIM3_7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM4_0_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM4_0             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM4_0_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM4_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(4, 0);
}
#endif /* if (SRC_GTM_GTM0_TIM4_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM4_1_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM4_1             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM4_1_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM4_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(4, 1);
}
#endif /* if (SRC_GTM_GTM0_TIM4_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM4_2_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM4_2             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM4_2_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM4_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(4, 2);
}
#endif /* if (SRC_GTM_GTM0_TIM4_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM4_3_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM4_3             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM4_3_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM4_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(4, 3);
}
#endif /* if (SRC_GTM_GTM0_TIM4_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM4_4_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM4_4             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM4_4_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM4_4_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(4, 4);
}
#endif /* if (SRC_GTM_GTM0_TIM4_4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM4_5_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM4_5             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM4_5_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM4_5_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(4, 5);
}
#endif /* if (SRC_GTM_GTM0_TIM4_5_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM4_6_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM4_6             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM4_6_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM4_6_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(4, 6);
}
#endif /* if (SRC_GTM_GTM0_TIM4_6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM4_7_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM4_7             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM4_7_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM4_7_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(4, 7);
}
#endif /* if (SRC_GTM_GTM0_TIM4_7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM5_0_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM5_0             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM5_0_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM5_0_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(5, 0);
}
#endif /* if (SRC_GTM_GTM0_TIM5_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM5_1_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM5_1             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM5_1_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM5_1_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(5, 1);
}
#endif /* if (SRC_GTM_GTM0_TIM5_1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM5_2_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM5_2             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM5_2_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM5_2_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(5, 2);
}
#endif /* if (SRC_GTM_GTM0_TIM5_2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM5_3_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM5_3             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM5_3_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM5_3_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(5, 3);
}
#endif /* if (SRC_GTM_GTM0_TIM5_3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM5_4_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM5_4             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM5_4_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM5_4_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(5, 4);
}
#endif /* if (SRC_GTM_GTM0_TIM5_4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM5_5_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM5_5             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM5_5_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM5_5_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(5, 5);
}
#endif /* if (SRC_GTM_GTM0_TIM5_5_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM5_6_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM5_6             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM5_6_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM5_6_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(5, 6);
}
#endif /* if (SRC_GTM_GTM0_TIM5_6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM5_7_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM5_7             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM5_7_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM5_7_ISR)
{
   /* Parameter is Channel Number */
   Gtm_IsrTimModule(5, 7);
}
#endif /* if (SRC_GTM_GTM0_TIM5_7_USED == STD_ON) */


#define ISR_STOP_SEC_CODE
#include "ISR_MemMap.h"

/*-------------------------------- END OF FILE -------------------------------*/

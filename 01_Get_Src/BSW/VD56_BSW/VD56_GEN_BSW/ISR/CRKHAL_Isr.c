/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ISR                                                     */
/* !Description     : ISR Management                                          */
/*                                                                            */
/* !File            : CRKHAL_Isr.c                                            */
/* !Description     : ISR definition of CRKHAL component                      */
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
 * %PID: P2017_BSW:0A192562.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "CRKHAL.h"
#include "Isr_Cfg.h"
#include "Os.h"

#define ISR_START_SEC_CODE
#include "ISR_MemMap.h"

/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM0_0_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM0_0             */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM0_0_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM0_0_ISR)
{
   CRKHAL_vidTimCrkInputToDpllIsr();
}
#endif /* if (SRC_GTM_GTM0_TIM0_0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_TIM0_1_ISR)                                */
/* !Description : Interrupt for GTM TIM module for channel TIM0_1             */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if (SRC_GTM_GTM0_TIM0_1_USED == STD_ON)
INT(SRC_GTM_GTM0_TIM0_1_ISR)
{
   CRKHAL_vidTimCrkInputToMcsIsr();
}
#endif /* if (SRC_GTM_GTM0_TIM0_1_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_DPLL0_ISR)                                 */
/* !Description : Interrupt for GTM DPLL module linked to SRC_GTM_GTM0_DPLL0  */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if (SRC_GTM_GTM0_DPLL0_USED == STD_ON)
INT(SRC_GTM_GTM0_DPLL0_ISR)
{
   CRKHAL_vidDirectionChangeIsr();
}
#endif /* if (SRC_GTM_GTM0_DPLL0_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_DPLL7_ISR)                                 */
/* !Description : Interrupt for GTM DPLL module linked to SRC_GTM_GTM0_DPLL7  */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if (SRC_GTM_GTM0_DPLL7_USED == STD_ON)
INT(SRC_GTM_GTM0_DPLL7_ISR)
{
   CRKHAL_vidDpllLongToothIsr();
}
#endif /* if (SRC_GTM_GTM0_DPLL7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_DPLL13_ISR)                                */
/* !Description : Interrupt for GTM DPLL module linked to SRC_GTM_GTM0_DPLL13 */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if (SRC_GTM_GTM0_DPLL13_USED == STD_ON)
INT(SRC_GTM_GTM0_DPLL13_ISR)
{
   CRKHAL_vidDpllGetLockIsr();
}
#endif /* if (SRC_GTM_GTM0_DPLL13_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_DPLL14ISR)                                 */
/* !Description : Interrupt for GTM DPLL module linked to SRC_GTM_GTM0_DPLL14 */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if (SRC_GTM_GTM0_DPLL14_USED == STD_ON)
INT(SRC_GTM_GTM0_DPLL14_ISR)
{
   CRKHAL_vidDpllLostLockIsr();
}
#endif /* if (SRC_GTM_GTM0_DPLL14_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_DPLL18_ISR)                                */
/* !Description : Interrupt for GTM DPLL module linked to SRC_GTM_GTM0_DPLL18 */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if (SRC_GTM_GTM0_DPLL18_USED == STD_ON)
INT(SRC_GTM_GTM0_DPLL18_ISR)
{
   CRKHAL_vidStartOfSyncWinIsr();
}
#endif /* if (SRC_GTM_GTM0_DPLL18_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_DPLL19_ISR)                                */
/* !Description : Interrupt for GTM DPLL module linked to SRC_GTM_GTM0_DPLL19 */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if (SRC_GTM_GTM0_DPLL19_USED == STD_ON)
INT(SRC_GTM_GTM0_DPLL19_ISR)
{
   CRKHAL_vidSynchSearchAndCtlIsr();
}
#endif /* if (SRC_GTM_GTM0_DPLL19_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_DPLL20_ISR)                                */
/* !Description : Interrupt for GTM DPLL module linked to SRC_GTM_GTM0_DPLL20 */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if (SRC_GTM_GTM0_DPLL20_USED == STD_ON)
INT(SRC_GTM_GTM0_DPLL20_ISR)
{
   CRKHAL_vidUpdateIntAngOffIsr();
}
#endif /* if (SRC_GTM_GTM0_DPLL20_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_DPLL23_ISR)                                */
/* !Description : Interrupt for GTM DPLL module linked to SRC_GTM_GTM0_DPLL23 */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if (SRC_GTM_GTM0_DPLL23_USED == STD_ON)
INT(SRC_GTM_GTM0_DPLL23_ISR)
{
   CRKHAL_vidCrkOnMngtIsr();
}
#endif /* if (SRC_GTM_GTM0_DPLL23_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_GTM_GTM0_MCS0_0_ISR)                                */
/* !Description : Interrupt for GTM MCS module linked to SRC_GTM_GTM0_MCS0_0  */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if (SRC_GTM_GTM0_MCS0_0_USED == STD_ON)
INT(SRC_GTM_GTM0_MCS0_0_ISR)
{
   CRKHAL_vidMcsTaskMgmtIsr();
}
#endif /* if (SRC_GTM_GTM0_MCS0_0_USED == STD_ON) */


#define ISR_STOP_SEC_CODE
#include "ISR_MemMap.h"

/*-------------------------------- END OF FILE -------------------------------*/

/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ISR                                                     */
/* !Description     : ISR Management                                          */
/*                                                                            */
/* !File            : Ccu6_Isr.c                                              */
/* !Description     : ISR definition of Ccu6 component                        */
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
 * %PID: P2017_BSW:0A192548.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

/******************************************************************************/
/* !Comment: SRC_CCU6_CCU60_SRx_ISR (x = 0..3) are used in Autosar ICU module */
/* !Comment: SRC_CCU6_CCU61_SRx_ISR (x = 0..3) are not used                   */
/******************************************************************************/

#include "Std_Types.h"
#include "Icu_17_GtmCcu6.h"
#include "Isr_Cfg.h"
#include "Os.h"

#define ISR_START_SEC_CODE
#include "ISR_MemMap.h"

/******************************************************************************/
/* !FuncName    : INT(SRC_CCU6_CCU60_SR0_ISR                                  */
/* !Description : This is Interrput Service request nodes 0 for the  CCU60    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_CCU6_CCU60_SR0_USED == STD_ON)
INT(SRC_CCU6_CCU60_SR0_ISR)
{
   /* Call Icu Interrupt funtion */
   Icu_17_GtmCcu6_Ccu_Isr(0);
}
#endif /* if (SRC_CCU6_CCU60_SR0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_CCU6_CCU60_SR1_ISR                                  */
/* !Description : This is Interrupt Service request nodes 1 for the  CCU60    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_CCU6_CCU60_SR1_USED == STD_ON)
INT(SRC_CCU6_CCU60_SR1_ISR)
{
   /* Call Icu Interrupt funtion */
   Icu_17_GtmCcu6_Ccu_Isr(1);
}
#endif /* if (SRC_CCU6_CCU60_SR1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_CCU6_CCU60_SR2_ISR                                  */
/* !Description : This is Interrupt Service request nodes 2 for the  CCU60    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_CCU6_CCU60_SR2_USED == STD_ON)
INT(SRC_CCU6_CCU60_SR2_ISR)
{
   /* Call Icu Interrupt funtion */
   Icu_17_GtmCcu6_Ccu_Isr(2);
}
#endif /* if (SRC_CCU6_CCU60_SR2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_CCU6_CCU60_SR3_ISR                                  */
/* !Description : This is Interrupt Service request nodes 3 for the  CCU60    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_CCU6_CCU60_SR3_USED == STD_ON)
INT(SRC_CCU6_CCU60_SR3_ISR)
{
   /* Call Icu Interrupt funtion */
   Icu_17_GtmCcu6_Ccu_Isr(3);
}
#endif /* if (SRC_CCU6_CCU60_SR3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_CCU6_CCU61_SR0_ISR                                  */
/* !Description : This is Interrupt Service request nodes 0 for the  CCU61    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_CCU6_CCU61_SR0_USED == STD_ON)
INT(SRC_CCU6_CCU61_SR0_ISR)
{
}
#endif /* if (SRC_CCU6_CCU61_SR0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_CCU6_CCU61_SR1_ISR                                  */
/* !Description : This is Interrupt Service request nodes 1 for the  CCU61    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_CCU6_CCU61_SR1_USED == STD_ON)
INT(SRC_CCU6_CCU61_SR1_ISR)
{
}
#endif /* if (SRC_CCU6_CCU61_SR1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_CCU6_CCU61_SR2_ISR                                  */
/* !Description : This is Interrupt Service request nodes 2 for the  CCU61    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_CCU6_CCU61_SR2_USED == STD_ON)
INT(SRC_CCU6_CCU61_SR2_ISR)
{
}
#endif /* if (SRC_CCU6_CCU61_SR2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_CCU6_CCU61_SR3_ISR                                  */
/* !Description : This is Interrupt Service request nodes 3 for the  CCU61    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_CCU6_CCU61_SR3_USED == STD_ON)
INT(SRC_CCU6_CCU61_SR3_ISR)
{
}
#endif /* if (SRC_CCU6_CCU61_SR3_USED == STD_ON) */


#define ISR_STOP_SEC_CODE
#include "ISR_MemMap.h"

/*-------------------------------- END OF FILE -------------------------------*/

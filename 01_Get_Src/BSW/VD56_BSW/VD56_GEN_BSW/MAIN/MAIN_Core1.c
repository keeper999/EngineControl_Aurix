/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : MAIN                                                    */
/* !Description     : Core Main Functions                                     */
/*                                                                            */
/* !File            : MAIN_Core1.c                                            */
/* !Description     : Main function of Core 1                                 */
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
 * %PID: P2017_BSW:0A111569.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "KRN.h"
#include "MAIN.h"
#include "Std_Types.h"

#define MAIN_START_SEC_CODE
#include "MAIN_MemMap.h"

/******************************************************************************/
/* !FuncName    : MAIN_core1_main                                             */
/* !Description : Main function of Core 1                                     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void MAIN_core1_main(void)
{
   __disable();

   KRN_vidOsLaunch();/*mockup Core2*/

   while (1)
   {
   }
}

#define MAIN_STOP_SEC_CODE
#include "MAIN_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

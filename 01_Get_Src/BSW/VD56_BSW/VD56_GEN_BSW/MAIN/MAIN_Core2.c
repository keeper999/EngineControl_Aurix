/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : MAIN                                                    */
/* !Description     : Core Main Functions                                     */
/*                                                                            */
/* !File            : MAIN_Core2.c                                            */
/* !Description     : Main function of Core 2                                 */
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
 * %PID: P2017_BSW:0A111568.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "MAIN.h"
#include "Std_Types.h"
#include "KRN.h"

#define MAIN_START_SEC_CODE
#include "MAIN_MemMap.h"

/******************************************************************************/
/* !FuncName    : MAIN_core2_main                                             */
/* !Description : Main function of Core 2                                     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void MAIN_core2_main(void)
{
   __disable();

   KRN_vidStartup();/*mockup Core2*/

   while (1)
   {
   }
}

#define MAIN_STOP_SEC_CODE
#include "MAIN_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

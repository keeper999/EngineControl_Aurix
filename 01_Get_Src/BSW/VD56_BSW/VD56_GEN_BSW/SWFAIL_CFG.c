/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SWFAIL                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : SWFAIL_CFG.c                                            */
/* !Description     : Configuration of SWFAIL Component                       */
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
 * %PID: P2017_BSW:0A192496.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Os.h"
#include "RSTSRV.h"
#include "SWFAIL.h"
#include "SWFAIL_CFG.h"

#define SWFAIL_START_SEC_CODE
#include "SWFAIL_MemMap.h"

/******************************************************************************/
/* !FuncName    : SWFAIL_vidPerformManualReset                                */
/* !Description : Performs manual reset upon exception occurrence. The        */
/*                implementation of this function is project dependent.       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void SWFAIL_vidPerformManualReset(void)
{
    RSTSRV_vidPerformReset(RSTSRV_udtSOFTWARE_RESET);
   /* !Comment: No return from this function; because RSTSRV_vidPerformReset( */
   /*           RSTSRV_udtSOFTWARE_RESET) will not return.                    */
}

/******************************************************************************/
/* !FuncName    : SWFAIL_vidNotHandledISRHook                                 */
/* !Description : Performs manual reset upon not handled isr. The             */
/*                implementation of this function is project dependent.       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void SWFAIL_vidNotHandledISRHook(void)
{
   SWFAIL_vidSoftwareErrorHook();
   RSTSRV_vidPerformReset(RSTSRV_udtSOFTWARE_RESET);
   /* !Comment: No return from this function; because RSTSRV_vidPerformReset( */
   /*           RSTSRV_udtSOFTWARE_RESET) will not return.                    */
}


#define SWFAIL_STOP_SEC_CODE
#include "SWFAIL_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

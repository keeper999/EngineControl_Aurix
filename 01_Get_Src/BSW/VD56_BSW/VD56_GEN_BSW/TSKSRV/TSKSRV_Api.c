/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : TSKSRV                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : TSKSRV_API.c                                            */
/* !Description     : TSKSRV APIs                                             */
/*                                                                            */
/* !Reference       : V03 NT 12 00698                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A283.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Os.h"
#include "Os_DisableInterrupts.h"
#include "Std_Types.h"
#include "Std_Limits.h"
#include "TSKSRV.h"
#include "TSKSRV_I.h"

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define  TSKSRV_START_SEC_CODE
#include "TSKSRV_MemMap.h"


/******************************************************************************/
/* !FuncName    : TSKSRV_vidInit                                              */
/* !Description : Initialization of TSKSRV component                          */
/*                                                                            */
/* !Trace_To    : VEES_R_12_00698_003                                         */
/* !Trace_To    : VEES_R_12_00698_004                                         */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void TSKSRV_vidInit(void)
{
   sint8_least s8LocalIndex;


   for (s8LocalIndex = UINT8_MIN;
        s8LocalIndex < TSKSRV_u8NUMBER_OF_TASKS;
        s8LocalIndex++)
   {
      TSKSRV_abActivationRequest[s8LocalIndex] = FALSE;
   }
   Os_Enable_OsTSKSRV_ACTIVATION_MANAGER_IT();

}

#define  TSKSRV_STOP_SEC_CODE
#include "TSKSRV_MemMap.h"


/*-------------------------------- end of file -------------------------------*/

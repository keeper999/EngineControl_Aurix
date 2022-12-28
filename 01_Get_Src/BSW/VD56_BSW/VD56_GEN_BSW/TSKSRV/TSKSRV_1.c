/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : TSKSRV                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : TSKSRV_1.c                                              */
/* !Description     : TSKSRV Callback                                         */
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
 * %PID: P2017_BSW:A285.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "Os.h"
#include "TSKSRV.h"
#include "TSKSRV_I.h"
#include "TSKSRV_L.h"

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define  TSKSRV_START_SEC_CODE
#include "TSKSRV_MemMap.h"


/******************************************************************************/
/* !FuncName    : INT(TSKSRV_ACTIVATION_MANAGER_IT)                           */
/* !Description : TSKSRV Software ISR2 in which tasks are activated           */
/*                                                                            */
/* !Trace_To    : VEES_R_12_00698_009                                         */
/* !Trace_To    : VEES_R_12_00698_010                                         */
/*                                                                            */
/* !LastAuthor  :  L. Baglin                                                  */
/******************************************************************************/
INT(TSKSRV_ACTIVATION_MANAGER_IT)
{
   sint32 s32LocalIndex;


   for (s32LocalIndex = UINT8_MIN;
        s32LocalIndex < TSKSRV_u8NUMBER_OF_TASKS;
        s32LocalIndex++)
   {
      if (TSKSRV_abActivationRequest[s32LocalIndex] != FALSE)
      {
         (void)ActivateTask(TSKSRV_audtOSTasks[s32LocalIndex]);
         TSKSRV_abActivationRequest[s32LocalIndex] = FALSE;
      }
   }
}

#define  TSKSRV_STOP_SEC_CODE
#include "TSKSRV_MemMap.h"


/*-------------------------------- end of file -------------------------------*/

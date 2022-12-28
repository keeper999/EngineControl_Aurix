/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : HOOK                                                    */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : HOOK.c                                                  */
/* !Description     : APIs of HOOK Component                                  */
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
 * %PID: P2017_BSW:0A192538.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "HOOK_Cfg_E.h"
#include "KRN.h"
#include "Os.h"
#include "RSTSRV.h"
#include "RTMTSK.h"
#include "SWFAIL.h"


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define OS_START_SEC_CALLOUT_CODE
#include "MemMap.h"

/******************************************************************************/
/* !FuncName    : ErrorHook                                                   */
/* !Description : OS hook error process                                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void ErrorHook (StatusType Error)
{
   OSServiceIdType udtLocalServiceId;
   TaskType        udtLocalTaskId;


   switch (Error)
   {
/*      case E_OS_SYS_STACK_OVERFLOW:
         SuspendAllInterrupts();
         SWFAIL_vidStackOverflowHook(OSError_ControlStacks_TaskID());
         RSTSRV_vidPerformReset(RSTSRV_udtSOFTWARE_RESET);*/
         /* No return of this function */
/*         break;*/

/*      case E_OS_SYS_STACK_UNDERFLOW:
         SuspendAllInterrupts();
         SWFAIL_vidStackUnderflowHook(OSError_ControlStacks_TaskID());
         RSTSRV_vidPerformReset(RSTSRV_udtSOFTWARE_RESET);*/
         /* No return of this function */
/*         break;*/

      case E_OS_LIMIT:
         SuspendAllInterrupts();
         udtLocalServiceId = OSErrorGetServiceId();
         udtLocalTaskId = OSError_ActivateTask_TaskID();
         ResumeAllInterrupts();
         if (udtLocalServiceId == OSServiceId_ActivateTask)
         {
            HOOK_vidTASK_OVERRUN_ERROR(udtLocalTaskId);
         }
         break;

      case E_OS_ID:
      case E_OS_CALLEVEL:
      case E_OS_RESOURCE:
      case E_OS_NOFUNC:
      case E_OS_VALUE:
      case E_OS_STATE:
      case E_OS_ACCESS:
      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/******************************************************************************/
/* !FuncName    : PreTaskHook                                                 */
/* !Description : OS task hook precede process                                */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void PreTaskHook(void)
{
   RTMTSK_vidTaskTimeMeasureStart();
}

/******************************************************************************/
/* !FuncName    : PostTaskHook                                                */
/* !Description : OS task hook post process                                   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void PostTaskHook(void)
{
   RTMTSK_vidTaskTimeMeasure();
}

/******************************************************************************/
/* !FuncName    : StartupHook                                                 */
/* !Description : OS startup hook process                                     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void StartupHook(void)
{
   CoreIdType core_id = GetCoreID();
   switch (core_id)
   {
      case 0:
         KRN_vidWaitForOsInitEnd();       
         break;
      case 1:
         KRN_vidWaitForOsInitEnd();       
         break;
      case 2:
         KRN_vidInit(); /* Because BSW runs in Core2 */
         break;
      default :
         break;
   }
}

/******************************************************************************/
/* !FuncName    : ShutdownHook                                                */
/* !Description : OS shutdown hook process                                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void ShutdownHook(StatusType Error)
{
   Error = Error;
}

#define OS_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/

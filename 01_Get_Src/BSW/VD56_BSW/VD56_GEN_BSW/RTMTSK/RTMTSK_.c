/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : RTMTSK                                                  */
/* !Description     : Real time task duration calculation                     */
/*                                                                            */
/* !File            : RTMTSK_.c                                               */
/* !Description     : APIs of RTMTSK Component                                */
/*                                                                            */
/* !Reference       : V03 NT 10 08733                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A111634.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "IfxStm.h"
#include "Os.h"
#include "RTMTSK_Cfg.h"
#include "RTMTSK.h"
#include "RTMTSK_L.h"

#define RTMTSK_START_SEC_CODE
#include "RTMTSK_MemMap.h"

/******************************************************************************/
/* !FuncName    : RTMTSK_vidTaskTimeMeasureInit                               */
/* !Description : Initialization of RTMTSK variables                          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void RTMTSK_vidTaskTimeMeasureInit(void)
{
   RTMTSK_u32TaskId = UINT32_MAX;
}


/******************************************************************************/
/* !FuncName    : RTMTSK_vidTaskTimeMeasureStart                              */
/* !Description : Saving of date to compute task duration                     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void RTMTSK_vidTaskTimeMeasureStart(void)
{
   RTMTSK_u32TaskStartTime = (uint32)IfxStm_getLower(&MODULE_STM0);
}


/******************************************************************************/
/* !FuncName    : RTMTSK_vidTaskTimeMeasure                                   */
/* !Description : Measure of task duration                                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void RTMTSK_vidTaskTimeMeasure(void)
{
   TaskType udtLocalTaskId;
   uint32   u32LocalTaskDuration;
   uint32   u32LocalTaskIndex;

   (void)GetTaskID(&udtLocalTaskId);
   u32LocalTaskIndex = OS_TASKTYPE_TO_INDEX(udtLocalTaskId);
   if (  (u32LocalTaskIndex == RTMTSK_u32TaskId)
      || (u32LocalTaskIndex == RTMTSK_ku32TaskId))
   {
      u32LocalTaskDuration = (uint32)( IfxStm_getLower(&MODULE_STM0)
                                     - RTMTSK_u32TaskStartTime);

      RTMTSK_u32TaskDuration = (uint32)( ( u32LocalTaskDuration
                                         * RTMTSK_REAL_RESOL_COEF)
                                       / RTMTSK_DESIRED_RESOL_COEF);
   }
}

#define RTMTSK_STOP_SEC_CODE
#include "RTMTSK_MemMap.h"

/*------------------------------- end of file --------------------------------*/

/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_3.c                                                 */
/* !Description     : Scheduler management                                    */
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
 * %PID: P2017_BSW:0A192514.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"

#include "IfxStm.h"
#include "Isr_Cfg.h"
#include "Os.h"
#include "Os_Cfg.h"
#include "Os_DisableInterrupts.h"

#include "KRN.h"
#include "KRN_Private.h"
#include "KRN_CFG_I.h"

#define KRN_START_SEC_CODE
#include "KRN_MemMap.h"

/******************************************************************************/
/* !FuncName    : KRN_vidSchedulerInit                                        */
/* !Description : Initialize the scheduler                                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidSchedulerInit(void)
{
   IfxStm_CompareConfig stmCompareConfig;


   /* Initialize STM for the triggers */
   KRN_u16SchedulerOverrunCnt = 0;
   KRN_u32CompareValue        = IfxStm_getFrequency(&MODULE_STM0)
                                / KRN_u16SCHEDULER_PERIOD_500US;

   (void)StartScheduleTableRel((&Os_const_scheduletables[0]), 1U);


   /* ena suspend by debugger */
   IfxStm_enableOcdsSuspend(&MODULE_STM0);
   /* ena suspend by debugger */

   /* Call the constructor of configuration */
   IfxStm_initCompareConfig(&stmCompareConfig);

   /* Modify only the number of ticks and enable the trigger output */
   stmCompareConfig.ticks = KRN_u32CompareValue;   /*Interrupt after KRN_u32CompareValue ticks from now */

   /* Now Compare functionality is initialized */
   IfxStm_initCompare(&MODULE_STM0, &stmCompareConfig);

   /* Enable interrupt service requests for STM trigger outputs */
   Os_Enable_OsKRN_SCHEDULER_MANAGE_IT();

}

/******************************************************************************/
/* !FuncName    : INT(KRN_SCHEDULER_MANAGE_IT)                                */
/* !Description : Scheduler Interrupt                                         */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
INT(KRN_SCHEDULER_MANAGE_IT)
{
   uint32 u32LocalNextDate;
   uint32 u32LocalDuration;


   u32LocalNextDate = (uint32)(IfxStm_getCompare(&MODULE_STM0, 0)
                               + KRN_u32CompareValue);

   IfxStm_updateCompare(&MODULE_STM0, 0, u32LocalNextDate);

   IncrementCounter(Schedule_table_counter);

   u32LocalDuration = (uint32)(IfxStm_getCompare(&MODULE_STM0, 0) )
                      - IfxStm_getLower(&MODULE_STM0);

   if ( (u32LocalDuration & MSB_REGISTER_MASK) != 0)
   {
      KRN_u16SchedulerOverrunCnt++;
      INTBSL_vidSTART_SW_IT(KRN_SCHEDULER_MANAGE_IT);
   }
}

#define KRN_STOP_SEC_CODE
#include "KRN_MemMap.h"

/*------------------------------- end of file --------------------------------*/

/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : ANGSCHED                                                */
/* !Description     : Angular scheduler Component                             */
/*                                                                            */
/* !File            : ANGSCHED_IRQ.c                                          */
/* !Description     : ANGSCHED events handler                                 */
/*                                                                            */
/* !Reference       : V03 NT 10 08984                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192492.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "ANGSCHED_IRQ.h"
#include "ADCHAL.h"
#include "TSKSRV.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/

#define ANGSCHED_START_SEC_CODE
#include "ANGSCHED_MemMap.h"

/******************************************************************************/
/* !FuncName    : ANGSCHED_vidInjCallback                                     */
/* !Description : INJHAL event handler.                                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void ANGSCHED_vidInjCallback(uint32 u32Date)
{
   COMPILER_UNUSED_PARAMETER(u32Date);
   ADCHAL_vidEntry_ANGSCHED_INJ_EVENT();
   TSKSRV_vidActivateTask(INJ_EVENT);
}

/******************************************************************************/
/* !FuncName    : ANGSCHED_vidBumLtooCallback                                 */
/* !Description : BUM CRK LTOO event handler.                                 */
/*                                                                            */
/* !LastAuthor  : A. Kamal                                                    */
/******************************************************************************/
void ANGSCHED_vidBumLtooCallback(uint32 u32Date)
{
   COMPILER_UNUSED_PARAMETER(u32Date);
   TSKSRV_vidActivateTask(CRKHAL_LTOO_EVENT);
}

#define ANGSCHED_STOP_SEC_CODE
#include "ANGSCHED_MemMap.h"


/*------------------------------ end of file ---------------------------------*/

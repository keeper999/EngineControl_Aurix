/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : ANGSCHED                                                */
/* !Description     : Angular scheduler Component                             */
/*                                                                            */
/* !File            : ANGSCHED_API.c                                          */
/* !Description     : API of the ANGSCHED Component                           */
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
 * %PID: P2017_BSW:A30421.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "ANGSCHED.h"

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define ANGSCHED_START_SEC_CODE
#include "ANGSCHED_MemMap.h"


/******************************************************************************/
/* !FuncName    : ANGSCHED_vidInit                                            */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Y. Badr                                                     */
/******************************************************************************/
void ANGSCHED_vidInit(void)
{
   ANGSCHED_vidINTERNAL_INIT();
}

/******************************************************************************/
/* !FuncName    : ANGSCHED_vidEnable                                          */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Y. Badr                                                     */
/******************************************************************************/
void ANGSCHED_vidEnable
(
   uint8 u8AngschedAlarm
)
{
   ANGSCHED_vidENABLE_ALARM(u8AngschedAlarm);
}

/******************************************************************************/
/* !FuncName    : ANGSCHED_vidDisable                                         */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Y. Badr                                                     */
/******************************************************************************/
void ANGSCHED_vidDisable
(
   uint8 u8AngschedAlarm
)
{
   ANGSCHED_vidDISABLE_ALARM(u8AngschedAlarm);
}

#define ANGSCHED_STOP_SEC_CODE
#include "ANGSCHED_MemMap.h"


/*------------------------------ end of file ---------------------------------*/

/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : STARTUP                                                 */
/* !Description     : Start-up                                                */
/*                                                                            */
/* !File            : STARTUP.c                                               */
/* !Description     : Start-up software                                       */
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
 * %PID: P2017_BSW:0A111581.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Os.h"
#include "STARTUP.h"

#define STARTUP_START_SEC_CODE
#include "STARTUP_MemMap.h"

/******************************************************************************/
/* !FuncName    : cstart                                                      */
/* !Description : Function called by the Os to start all core                 */
/*                                                                            */
/* !LastAuthor  : J. Soufflet                                                 */
/******************************************************************************/
void cstart(void)
{
   CoreIdType core_id = GetCoreID();
   switch (core_id)
   {
      case 0 :
         break;
      case 1 :
         __non_return_call(STARTUP_Core1_start);
         break;
      case 2 :
         __non_return_call(STARTUP_Core2_start);
         break;
      default :
         break;
   }
}

#define STARTUP_STOP_SEC_CODE
#include "STARTUP_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

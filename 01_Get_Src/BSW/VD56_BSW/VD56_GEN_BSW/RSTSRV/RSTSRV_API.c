/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : RSTSRV                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : RSTSRV_API.c                                            */
/* !Description     : APIs of RSTSRV Component                                */
/*                                                                            */
/* !Reference       : V03 NT 07 02929                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A256.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "MCU.h"
#include "SchM_RSTSRV.h"
#include "RSTSRV.h"
#include "RSTSRV_Private.h"
#include "SWFAIL.h"

#define RSTSRV_START_SEC_CODE
#include "RSTSRV_MemMap.h"

/******************************************************************************/
/* !FuncName    : RSTSRV_udtReadResetState                                    */
/* !Description :                                                             */
/*                                                                            */
/* !TraceTo     : VEES_R_07_02929_001.01                                      */
/* !TraceTo     : VEES_R_07_02929_002.01                                      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
RSTSRV_tudtResetType RSTSRV_udtReadResetState(void)
{
   RSTSRV_tudtResetType udtLocalResetType;

   if (RSTSRV_bSWResetDetected == TRUE)
   {
      udtLocalResetType = RSTSRV_udtSOFTWARE_RESET;
   }
   else
   {
      if (((sint32)RSTSRV_u16HotResetCtr) <= 1)
      {
         udtLocalResetType = RSTSRV_udtNORMAL_STARTUP_RESET;
      }
      else
      {
         udtLocalResetType = RSTSRV_udtHARDWARE_RESET;
      }
   }
   return(udtLocalResetType);
}

/******************************************************************************/
/* !FuncName    : RSTSRV_vidPerformReset                                      */
/* !Description :                                                             */
/*                                                                            */
/* !TraceTo     : VEES_R_07_02929_003.01                                      */
/* !TraceTo     : VEES_R_07_02929_004.01                                      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void RSTSRV_vidPerformReset(RSTSRV_tudtResetType udtRequestedResetType)
{

   switch(udtRequestedResetType)
   {
   case RSTSRV_udtSOFTWARE_RESET:
      Mcu_PerformReset();
      break;
   case RSTSRV_udtHARDWARE_RESET:
      SchM_Enter_RSTSRV_ACCESS_001();
      Mcu_PerformReset(); // dbg
      while (1)
      {
       /*  WTDG_vidINT(); // dbg */
      }
      break;
   case RSTSRV_udtNORMAL_STARTUP_RESET:
   default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
}

#define RSTSRV_STOP_SEC_CODE
#include "RSTSRV_MemMap.h"

/*------------------------------- end of file --------------------------------*/

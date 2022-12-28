/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : DEVHAL                                                  */
/* !Description     : DEVHAL Component                                        */
/*                                                                            */
/* !File            : DEVHAL_Cfg.c                                            */
/* !Description     : DEVHAL configuration                                    */
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
 * %PID: %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "CRKHAL.h"
#include "DEVHAL_Cfg.h"
#include "Dio.h"
#include "HBHAL.h"

#define DEVHAL_START_SEC_CODE
#include "DEVHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : DEVHAL_bWaitProtectionCond                                  */
/* !Description : Return the DEVAID protection state.                         */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
boolean DEVHAL_bWaitProtectionCond(void)
{
   boolean bLocalCondOk;
   HBHAL_tenuStatus udtLocalStatus;

   bLocalCondOk = FALSE;

   HBHAL_vidDisable(CM_18_CM_19_L9960);
   udtLocalStatus = HBHAL_enuReadStatus(CM_18_CM_19_L9960);
   if (udtLocalStatus == HBHAL_H_BRIDGE_DISABLED)
   {
      bLocalCondOk = TRUE;
   }
   return(bLocalCondOk);
}

/******************************************************************************/
/* !FuncName    : DEVHAL_bCheckReprogCond                                     */
/* !Description : Returns ECU state for devaid reprog authorization.          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
boolean DEVHAL_bCheckReprogCond(void)
{
   boolean bLocalRunningStatus;
   boolean bLocalPowerKeyStatus;

   (void) CRKHAL_udtReadStatus(CRKHAL_u8RUNNING, &bLocalRunningStatus);
   bLocalPowerKeyStatus = Dio_ReadChannel(DioConf_DioChannel_M_STARTUP_IGK);

   return((bLocalRunningStatus == FALSE) && (bLocalPowerKeyStatus != STD_OFF));
}

#define DEVHAL_STOP_SEC_CODE
#include "DEVHAL_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

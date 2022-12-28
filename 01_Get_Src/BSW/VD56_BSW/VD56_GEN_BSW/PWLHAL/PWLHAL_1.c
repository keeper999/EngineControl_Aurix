/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PWLHAL                                                  */
/* !Description     : Power Latch Hardware Abstraction Layer                  */
/*                                                                            */
/* !File            : PWLHAL_1.c                                              */
/* !Description     : Internal functions of PWLHAL Component                  */
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
 * %PID: P2017_BSW:A11986.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "DEVHAL.h"
#include "Dio.h"
#include "PWLHAL_Cfg.h"
#include "PWLHAL_Def.h"
#include "SWFAIL.h"

#define PWLHAL_START_SEC_CODE
#include "PWLHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : PWLHAL_vidPowerDownManagement                               */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Hamdi Saidi                                                 */
/******************************************************************************/
void PWLHAL_vidPowerDownManagement(void)
{
	uint16 u16LocalShutdownCnt;


	u16LocalShutdownCnt = PWLHAL_u16ShutdownCnt;
   if (u16LocalShutdownCnt == 0)
   {
      switch (PWLHAL_enuEcuPowerState)
      {
         case PWLHAL_ECU_POWER_ON:
            break;

         case PWLHAL_ACTR_CUT_OFF_DELAY:
            PWLHAL_vidWRITE_POWER_RELAY(STD_OFF);
            u16LocalShutdownCnt     = PWLHAL_ku16ShutdownDly;
            PWLHAL_enuEcuPowerState = PWLHAL_MAIN_RLY_CUT_OFF_DELAY;
            break;

         case PWLHAL_MAIN_RLY_CUT_OFF_DELAY:
            PWLHAL_vidDEVAID_POWER_DOWN();
            PWLHAL_u8MainRlyCutReq = PWLHAL_u8PWDWN_CUT_REQ;
            Dio_WriteChannel(PWLHAL_udtPWL_MAIN_RLY, STD_OFF);
            u16LocalShutdownCnt     = 1u + PWLHAL_u16ONE_SECOND;
            PWLHAL_enuEcuPowerState = PWLHAL_ECU_POWER_DOWN;
            break;

         case PWLHAL_ECU_POWER_DOWN:
            while (1)
            {
            }
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
      }
   }
	if (u16LocalShutdownCnt > 0)
	{
	   u16LocalShutdownCnt = u16LocalShutdownCnt - 1U;
	}
	PWLHAL_u16ShutdownCnt = u16LocalShutdownCnt;
}

#define PWLHAL_STOP_SEC_CODE
#include "PWLHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/

/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : INJHAL Component                                        */
/*                                                                            */
/* !File            : INJHAL_FG_PRE_INJ.c                                     */
/* !Description     : Management of Full Group Injection                      */
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
 * %PID: P2017_BSW:A26581.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"

#include "INJHAL.h"
#include "INJHAL_CFG_I.h"
#include "SWFAIL.h"


#define INJHAL_START_SEC_CODE
#include "INJHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : INJHAL_vidFGPreinjManagement                                */
/* !Description : API to manage the FG pre injection                          */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidFGPreinjManagement
(
   uint8 u8InstanceId
)
{
   if (u8InstanceId < INJHAL_u8NB_INSTANCES)
   {
      INJHAL_aenuInjComponentStatus[u8InstanceId] = INJHAL_enuCOMP_FG_PRE_INJ;
      /* clear the interrupts */
      INJHAL_vidclearFGAngIrq(u8InstanceId) ;

      if (INJHAL_au32FGPreInjTime[u8InstanceId] != (uint32)UINT32_MIN)
      {
         /* Set closing Condition for all the Injectors */
         INJHAL_vidCfgStartFGPreInj(u8InstanceId,
                                    INJHAL_au32FGPreInjTime[u8InstanceId]);
         INJHAL_abInjStarted[u8InstanceId] = (boolean)TRUE;
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

#define INJHAL_STOP_SEC_CODE
#include "INJHAL_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

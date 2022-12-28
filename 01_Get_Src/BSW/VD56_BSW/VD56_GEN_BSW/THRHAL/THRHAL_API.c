/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : THRHAL                                                  */
/* !Description     : THRHAL Component                                        */
/*                                                                            */
/* !File            : THRHAL_API.c                                            */
/* !Description     : APIs of THRHAL Component                                */
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
 * %PID: P2017_BSW:0A111672.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "ADCHAL.h"
#include "Dio.h"
#include "L9960.h"
#include "Os.h"
#include "Os_DisableInterrupts.h"
#include "Pwm.h"
#include "THRHAL.h"
#include "THRHAL_Cfg.h"
#include "THRHAL_Def.h"

#define THRHAL_START_SEC_CODE
#include "THRHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : THRHAL_vidInit                                              */
/* !Description : Initialization of THRHAL component                          */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
void THRHAL_vidInit(void)
{
   L9960_vidInit();

   THRHAL_u8Counter = THRHAL_u8TASK_ACTIVATION_COUNTER;
   Os_Enable_OsTHRHAL_PAP_PLUS_IT();
   Pwm_EnableNotification(Pwm_17_GtmConf_PwmChannel_M_INTK_THR_MOT_PWM,
                          PWM_RISING_EDGE);

}


/******************************************************************************/
/* !FuncName    : THRHAL_vidInterrupt                                         */
/* !Description : THRHAL interrupt callback                                   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void THRHAL_vidInterrupt(void)
{
   if (THRHAL_u8Counter >= THRHAL_u8TASK_ACTIVATION_COUNTER)
   {
      THRHAL_u8Counter = UINT8_MIN;
      ADCHAL_vidEntry_THR_EVENT();
      (void)ActivateTask(THRHAL_THR_EVENT);
   }
   else
   {
      THRHAL_u8Counter ++;
   }
}

/******************************************************************************/
/* !FuncName    : THRHAL_vidMainFunction                                      */
/* !Description : Main Function                                               */
/*                                                                            */
/* !LastAuthor  : L. Voilmy                                                   */
/******************************************************************************/
void THRHAL_vidMainFunction(void)
{
   L9960_vidMainFunction();
}

/******************************************************************************/
/* !FuncName    : THRHAL_vidDisable                                           */
/* !Description : Disable the H-Bridge driver (stub)                          */
/*                                                                            */
/* !LastAuthor  : L. Voilmy                                                   */
/******************************************************************************/
void THRHAL_vidDisable(void)
{
   Dio_WriteChannel(DioConf_DioChannel_M_INTK_THR_INH, STD_HIGH);
}

/******************************************************************************/
/* !FuncName    : THRHAL_vidEnable                                            */
/* !Description : Enable the H-Bridge driver (stub)                           */
/*                                                                            */
/* !LastAuthor  : L. Voilmy                                                   */
/******************************************************************************/
void THRHAL_vidEnable(void)
{
   Dio_WriteChannel(DioConf_DioChannel_M_INTK_THR_INH, STD_LOW);
}


#define THRHAL_STOP_SEC_CODE
#include "THRHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/

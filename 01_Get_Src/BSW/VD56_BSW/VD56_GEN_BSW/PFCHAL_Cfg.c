/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                     */
/* !Component       : PFCHAL                                                  */
/* !Description     : Configuration of the PFCHAL component                   */
/*                                                                            */
/* !File            : PFCHAL_CFG.c                                            */
/* !Description     : Configuration of the PFCHAL Component                   */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/

#include "Std_Types.h"
#include "Dio.h"
#include "PFCHAL.h"
#include "PFCHAL_Cfg_I.h"
#include "PFCHAL_I.h"
#include "Pwm.h"
#include "SWFAIL.h"
#include "TLE8718.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define PFCHAL_START_SEC_VAR_8BIT
#include "PFCHAL_MemMap.h"

uint8 PFCHAL_au8CurrentMode[PFCHAL_u8CHANNEL_NB];

#define PFCHAL_STOP_SEC_VAR_8BIT
#include "PFCHAL_MemMap.h"


#define PFCHAL_START_SEC_CONST_UNSPECIFIED
#include "PFCHAL_MemMap.h"

/* !Comment: Array of pointer to functions of all defined DioEnable.          */
void (* const PFCHAL_akpfvidChannelConfig[PFCHAL_u8CHANNEL_NB])(uint8) =
{
   PFCHAL_vidConfig_CH_63
};

#define PFCHAL_STOP_SEC_CONST_UNSPECIFIED
#include "PFCHAL_MemMap.h"


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

#define PFCHAL_START_SEC_CODE
#include "PFCHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : PFCHAL_vidInitConfig                                        */
/* !Description : Configuration initialization                                */
/*                                                                            */
/* !LastAuthor  : E. RIAD                                                     */
/******************************************************************************/
void PFCHAL_vidInitConfig(void)
{
   PFCHAL_vidConfig_CH_63(PFCHAL_u8DIO_MODE);
}

/******************************************************************************/
/* !FuncName    : PFCHAL_vidConfig_CH_63                                      */
/* !Description : Configure the ressource for CH_63                           */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void PFCHAL_vidConfig_CH_63(uint8 u8Mode)
{
   switch (u8Mode)
   {
      case PFCHAL_u8DIO_MODE:
         if (PFCHAL_au8CurrentMode[PFCHAL_u8CH_63] != PFCHAL_u8DIO_MODE)
         {
            Pwm_DisableNotification(Pwm_17_GtmConf_PwmChannel_M_COOLANT_FAN_1);
            TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_12, HOD_MODE_DIO);
            TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_12, STD_LOW);
            TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_12, HOD_CUT_OFF_WITHOUT_FAULT);
            PFCHAL_au8CurrentMode[PFCHAL_u8CH_63] = PFCHAL_u8DIO_MODE;
         }
         break;

      case PFCHAL_u8PWM_MODE:
         if (PFCHAL_au8CurrentMode[PFCHAL_u8CH_63] != PFCHAL_u8PWM_MODE)
         {
            TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_12, HOD_MODE_PWM);
            TLE8718_vidPwmSetOutputToIdle(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_12);
            Pwm_EnableNotification(Pwm_17_GtmConf_PwmChannel_M_COOLANT_FAN_1, PWM_RISING_EDGE);
            TLE8718_vidEnableCmd(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_12, HOD_CUT_OFF_WITHOUT_FAULT);
            PFCHAL_au8CurrentMode[PFCHAL_u8CH_63] = PFCHAL_u8PWM_MODE;
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

#define PFCHAL_STOP_SEC_CODE
#include "PFCHAL_MemMap.h"


/*------------------------------ end of file ---------------------------------*/
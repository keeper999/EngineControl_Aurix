/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Cfg.c                                                                                   */
/* !Description     : Configuration of TLE8718 Component                                                              */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192575.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"

#include "DGOHAL.h"
#include "Dio.h"
#include "Pwm.h"
#include "TLE8718.h"
#include "TLE8718_L.h"
#include "TLE8718_Msc.h"
#include "TLE8718_Typ.h"

/**********************************************************************************************************************/
/* FUNCTION DECLARATION                                                                                               */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : Msc_Interrupt_HandlerMSC0_RxFrame                                                                   */
/* !Description : Notification Callback of MC0 Rx Frame IT                                                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void Msc_Interrupt_HandlerMSC0RxFrame(void)
{
   TLE8718_vidMscRxFrameNotif(TLE8718_udtINSTANCE_1);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMc0TxCmdFrameNotif                                                                       */
/* !Description : Notification Callback of MC0 Tx Command Frame IT                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMc0TxCmdFrameNotif(void)
{
   TLE8718_vidMscTxFrameNotif(TLE8718_udtINSTANCE_1);
}

/**********************************************************************************************************************/
/* !FuncName    : Msc_Interrupt_HandlerMSC0_SR4                                                                       */
/* !Description : Interrupt Handler Function of MC0 Rx Frame Timeout IT                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void Msc_Interrupt_HandlerMSC0_SR4(void)
{
   TLE8718_vidMscTimeoutNotif(TLE8718_udtINSTANCE_1);
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* CONSTANTS DECLARATION                                                                                              */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CONST_8BIT
#include "TLE8718_MemMap.h"

/* !MComment: MSC Module Used For The TLE8718 Instance */
const uint8 TLE8718_kau8Module[TLE8718_udtINSTANCE_NB] =
{
   0u /* MSC0 used for TLE8718 Instance */
};

/* !MComment: Definition Of The Output Mode Type : TLE8718_u8DIO_MODE / TLE8718_u8PWM_MODE / TLE8718_u8CDD_MODE */
const uint8 TLE8718_kau8OutputMode[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB] =
{
   {
      TLE8718_u8PWM_MODE, /* TLE8718_udtOUT_1  is configured as a PWM */
      TLE8718_u8PWM_MODE, /* TLE8718_udtOUT_2  is configured as a PWM */
      TLE8718_u8DIO_MODE, /* TLE8718_udtOUT_3  is configured as a DIO */
      TLE8718_u8PWM_MODE, /* TLE8718_udtOUT_4  is configured as a PWM */
      TLE8718_u8DIO_MODE, /* TLE8718_udtOUT_5  is configured as a DIO */
      TLE8718_u8DIO_MODE, /* TLE8718_udtOUT_6  is configured as a DIO */
      TLE8718_u8PWM_MODE, /* TLE8718_udtOUT_7  is configured as a PWM */
      TLE8718_u8DIO_MODE, /* TLE8718_udtOUT_8  is configured as a DIO */
      TLE8718_u8PWM_MODE, /* TLE8718_udtOUT_9  is configured as a PWM */
      TLE8718_u8PWM_MODE, /* TLE8718_udtOUT_10 is configured as a PWM */
      TLE8718_u8DIO_MODE, /* TLE8718_udtOUT_11 is configured as a DIO */
      TLE8718_u8PWM_MODE, /* TLE8718_udtOUT_12 is configured as a PWM */
      TLE8718_u8DIO_MODE, /* TLE8718_udtOUT_13 is configured as a DIO */
      TLE8718_u8DIO_MODE, /* TLE8718_udtOUT_14 is configured as a DIO */
      TLE8718_u8DIO_MODE, /* TLE8718_udtOUT_15 is configured as a DIO */ 
      TLE8718_u8DIO_MODE, /* TLE8718_udtOUT_16 is configured as a DIO */
      TLE8718_u8PWM_MODE, /* TLE8718_udtOUT_17 is configured as a PWM */
      TLE8718_u8PWM_MODE  /* TLE8718_udtOUT_18 is configured as a PWM */
   }
};

/* !MComment: Initial Value Of TLE8718 Outputs Controlled By MSC Data Frame */
const uint8 TLE8718_kau8ReactivationDelay[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB] =
{
   {
      18u, /* TLE8718_udtOUT_1 Reactivation Delay  */
      18u, /* TLE8718_udtOUT_2 Reactivation Delay  */
      18u, /* TLE8718_udtOUT_3 Reactivation Delay  */
      18u, /* TLE8718_udtOUT_4 Reactivation Delay  */
      18u, /* TLE8718_udtOUT_5 Reactivation Delay  */
      18u, /* TLE8718_udtOUT_6 Reactivation Delay  */
      18u, /* TLE8718_udtOUT_7 Reactivation Delay  */
      18u, /* TLE8718_udtOUT_8 Reactivation Delay  */
      18u, /* TLE8718_udtOUT_9 Reactivation Delay  */
      18u, /* TLE8718_udtOUT_10 Reactivation Delay */
      18u, /* TLE8718_udtOUT_11 Reactivation Delay */
      18u, /* TLE8718_udtOUT_12 Reactivation Delay */
      18u, /* TLE8718_udtOUT_13 Reactivation Delay */
      18u, /* TLE8718_udtOUT_14 Reactivation Delay */
      18u, /* TLE8718_udtOUT_15 Reactivation Delay */
      18u, /* TLE8718_udtOUT_16 Reactivation Delay */
      18u, /* TLE8718_udtOUT_17 Reactivation Delay */
      18u  /* TLE8718_udtOUT_18 Reactivation Delay */
   }
};

/* !MComment: Declaration of the number of short circuit to Vbat is necessary */
/*            before enable the short circuit protection                      */
const uint8 TLE8718_kau8ShortCircuitDetectNb[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB] =
{
   {
      0u, /* TLE8718_udtOUT_1 Short circuit Detection Number  */
      0u, /* TLE8718_udtOUT_2 Short circuit Detection Number  */
      0u, /* TLE8718_udtOUT_3 Short circuit Detection Number  */
      0u, /* TLE8718_udtOUT_4 Short circuit Detection Number  */
      0u, /* TLE8718_udtOUT_5 Short circuit Detection Number  */
      0u, /* TLE8718_udtOUT_6 Short circuit Detection Number  */
      0u, /* TLE8718_udtOUT_7 Short circuit Detection Number  */
      0u, /* TLE8718_udtOUT_8 Short circuit Detection Number  */
      0u, /* TLE8718_udtOUT_9 Short circuit Detection Number  */
      0u, /* TLE8718_udtOUT_10 Short circuit Detection Number */
      0u, /* TLE8718_udtOUT_11 Short circuit Detection Number */
      0u, /* TLE8718_udtOUT_12 Short circuit Detection Number */
      0u, /* TLE8718_udtOUT_13 Short circuit Detection Number */
      0u, /* TLE8718_udtOUT_14 Short circuit Detection Number */
      0u, /* TLE8718_udtOUT_15 Short circuit Detection Number */
      0u, /* TLE8718_udtOUT_16 Short circuit Detection Number */
      0u, /* TLE8718_udtOUT_17 Short circuit Detection Number */
      0u  /* TLE8718_udtOUT_18 Short circuit Detection Number */
   }
};

#define TLE8718_STOP_SEC_CONST_8BIT
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_CONST_UNSPECIFIED
#include "TLE8718_MemMap.h"

const DGOHAL_tudtChannel TLE8718_kaudtDgohalChannel[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB] =
{
   {
      DGOHAL_udtTLE8718_OUT1,
      DGOHAL_udtTLE8718_OUT2,
      DGOHAL_udtTLE8718_OUT3,
      DGOHAL_udtTLE8718_OUT4,
      DGOHAL_udtTLE8718_OUT5,
      DGOHAL_udtTLE8718_OUT6,
      DGOHAL_udtTLE8718_OUT7,
      DGOHAL_udtTLE8718_OUT8,
      DGOHAL_udtTLE8718_OUT9,
      DGOHAL_udtTLE8718_OUT10,
      DGOHAL_udtTLE8718_OUT11,
      DGOHAL_udtTLE8718_OUT12,
      DGOHAL_udtTLE8718_OUT13,
      DGOHAL_udtTLE8718_OUT14,
      DGOHAL_udtTLE8718_OUT15,
      DGOHAL_udtTLE8718_OUT16,
      DGOHAL_udtTLE8718_OUT17,
      DGOHAL_udtTLE8718_OUT18
   }
};

const Dio_ChannelType TLE8718_kaudtAbeDioChannel[TLE8718_udtINSTANCE_NB] =
{
   DioConf_DioChannel_M_TLE8718_ENABLE
};

/* !MComment: DIO Channel of MSC Dis5_10 Output Used For The TLE8718 Instance */
const Dio_ChannelType TLE8718_kaudtDis5_10DioChannel[TLE8718_udtINSTANCE_NB] =
{
   0u /* Default value: Dis5_10 input of TLE8718 is plugged to VCC_5V */
};

/* !MComment: MSC Device Select Used For The TLE8718 Instance */
const Msc_RxDevSelectType TLE8718_kaudtRxDevice[TLE8718_udtINSTANCE_NB] =
{
   3u
};

/* !MComment: MSC Device Select Used For The TLE8718 Instance */
const Msc_TxDevSelectType TLE8718_kaudtTxDevice[TLE8718_udtINSTANCE_NB] =
{
   1u
};

/* !MComment: Declaration Of The PWM MCAL Channel (AUTOSAR or LIBEMB) */
const Pwm_ChannelType TLE8718_kaudtPwmChannel[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB] =
{
   {
      Pwm_17_GtmConf_PwmChannel_M_MAIN_UPS_LBDA_SNS_HEAT,    /* TLE8718_udtOUT_1  */
      Pwm_17_GtmConf_PwmChannel_M_EXH_VVT,                   /* TLE8718_udtOUT_2  */
      Pwm_17_GtmConf_PwmChannel_M_MAIN_DWN_LBDA_SNS_HEAT,    /* TLE8718_udtOUT_3  */
      Pwm_17_GtmConf_PwmChannel_M_INTK_VVT,                  /* TLE8718_udtOUT_4  */
      PWM_MAX_CHANNELS,                                      /* TLE8718_udtOUT_5  */
      PWM_MAX_CHANNELS,                                      /* TLE8718_udtOUT_6  */
      Pwm_17_GtmConf_PwmChannel_M_CANISTER_PURGE_VALVE,      /* TLE8718_udtOUT_7  */
      PWM_MAX_CHANNELS,                                      /* TLE8718_udtOUT_8  */
      Pwm_17_GtmConf_PwmChannel_M_DUMP_VALVE,                /* TLE8718_udtOUT_9  */
      Pwm_17_GtmConf_PwmChannel_M_OIL_VAR_PUMP_VALVE,        /* TLE8718_udtOUT_10 */
      PWM_MAX_CHANNELS,                                      /* TLE8718_udtOUT_11 */
      Pwm_17_GtmConf_PwmChannel_M_COOLANT_FAN_1,             /* TLE8718_udtOUT_12 */
      PWM_MAX_CHANNELS,                                      /* TLE8718_udtOUT_13 */
      PWM_MAX_CHANNELS,                                      /* TLE8718_udtOUT_14 */
      PWM_MAX_CHANNELS,                                      /* TLE8718_udtOUT_15 */ 
      PWM_MAX_CHANNELS,                                      /* TLE8718_udtOUT_16 */
      Pwm_17_GtmConf_PwmChannel_M_TURBO_COOLING_PUMP,        /* TLE8718_udtOUT_17 */
      Pwm_17_GtmConf_PwmChannel_M_LOW_PRES_FUEL_PUMP_VAR_SPD /* TLE8718_udtOUT_18 */
   }
};

#define TLE8718_STOP_SEC_CONST_UNSPECIFIED
#include "TLE8718_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/

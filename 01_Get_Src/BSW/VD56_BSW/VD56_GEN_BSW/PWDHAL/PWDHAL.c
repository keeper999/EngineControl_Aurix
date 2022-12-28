/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PWDHAL                                                                                          */
/* !Description     : Pulse width demodulation                                                                        */
/*                                                                                                                    */
/* !File            : PWDHAL.c                                                                                        */
/* !Description     : Main code                                                                                       */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5611943                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A3332.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/


#include "Std_Types.h"
#include "MATHSRV.h"
#include "SWFAIL.h"
#include "PWDHAL.h"
#include "PWDHAL_Types.h"
#include "PWDHAL_Cfg.h"
#include "PWDHAL_Co.h"
#include "PWDHAL_Private.h"

#include "Icu.h"

/**********************************************************************************************************************/
/* Check that used define for conditionnal compilation exist                                                          */
/**********************************************************************************************************************/
#ifndef PWDHAL_coPERIOD_INIT_TO_MAX
   #error The macro-constant PWDHAL_coPERIOD_INIT_TO_MAX shall be defined
#endif


#ifndef PWDHAL_coTRUE
   #error The macro-constant PWDHAL_coTRUE shall be defined
#endif



/**********************************************************************************************************************/
/* DATA DEFINITION                                                                                                    */
/**********************************************************************************************************************/

#define PWDHAL_START_SEC_VAR_UNSPECIFIED
#include "PWDHAL_MemMap.h"

/* Struture of PWDHAL data */
STATIC VAR(PWDHAL_tstrData, PWDHAL_VAR) PWDHAL_astrData[PWDHAL_u8NUMBER_OF_CHANNELS];

#define PWDHAL_STOP_SEC_VAR_UNSPECIFIED
#include "PWDHAL_MemMap.h"

/**********************************************************************************************************************/
/* INTERNAL FUNCTION DEFINITION                                                                                       */
/**********************************************************************************************************************/
STATIC void PWDHAL_vidInitChannel(uint8 u8Channel, PWDHAL_tstrData * pstrPwdData);


/**********************************************************************************************************************/
/* API DEFINITION                                                                                                     */
/**********************************************************************************************************************/

#define PWDHAL_START_SEC_CODE
#include "PWDHAL_MemMap.h"


/**********************************************************************************************************************/
/* !FuncName    : PWDHAL_vidInit                                                                                      */
/* !Description : PWDHAL_vidInit initializes all internal variables related to the channel u8Channel                  */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_09_05009_001.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_002.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/

void PWDHAL_vidInit(void)
{

   uint8_least         u8LocChannel;
   PWDHAL_tstrData   * pstrPwdData;


   for (u8LocChannel = 0;
        u8LocChannel < PWDHAL_u8NUMBER_OF_CHANNELS;
        u8LocChannel++)
   {
      pstrPwdData = &PWDHAL_astrData[u8LocChannel];
      pstrPwdData->bEnable = FALSE;
      pstrPwdData->udtTimeoutCounter = PWDHAL_udtTIMEOUT_TYPE_MAX;
      PWDHAL_vidInitChannel((uint8)u8LocChannel, pstrPwdData);
   }
}


/**********************************************************************************************************************/
/* !FuncName    : PWDHAL_vidEnable                                                                                    */
/* !Description : PWDHAL_vidEnable enables the work of the PWD for demodulating the PWM signal of the <u8Channel>.    */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_09_05009_004.02                                                                              */
/* !Trace_To    : VEES_R_09_05009_005.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/

void PWDHAL_vidEnable(uint8 u8Channel)
{
   if (u8Channel < PWDHAL_u8NUMBER_OF_CHANNELS)
   {
      if (PWDHAL_astrData[u8Channel].bEnable != TRUE)
      {
         PWDHAL_astrData[u8Channel].bEnable = TRUE;

         Icu_StartSignalMeasurement(PWDHAL_akudtIcuChannel[u8Channel]);
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}


/**********************************************************************************************************************/
/* !FuncName    : PWDHAL_vidDisable                                                                                   */
/* !Description : PWDHAL_vidDisable disables the work of the PWD for demodulating the PWM signal of the <u8Channel>   */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_09_05009_006.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_007.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_008.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/

void PWDHAL_vidDisable(uint8 u8Channel)
{
   PWDHAL_tstrData   * pstrPwdData;

   if (u8Channel < PWDHAL_u8NUMBER_OF_CHANNELS)
   {
      pstrPwdData = &PWDHAL_astrData[u8Channel];
      if (pstrPwdData->bEnable != FALSE)
      {
         Icu_StopSignalMeasurement(PWDHAL_akudtIcuChannel[u8Channel]);

         PWDHAL_vidInitChannel(u8Channel, pstrPwdData);
         pstrPwdData->udtTimeoutCounter = pstrPwdData->udtTimeoutReloadValue;
         pstrPwdData->bEnable           = FALSE;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}


/**********************************************************************************************************************/
/* !FuncName    : PWDHAL_udtGetPeriodAndDutyCycle                                                                     */
/* !Description : Returns the period and the duty cycle of the PWM channel <u8Channel>                                */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_09_05009_009.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_010.02                                                                              */
/* !Trace_To    : VEES_R_09_05009_011.02                                                                              */
/* !Trace_To    : VEES_R_09_05009_015.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_016.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_017.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType PWDHAL_udtGetPeriodAndDutyCycle
(
   uint8 u8Channel,
   PWDHAL_tudtPeriod* pudtPeriod,
   PWDHAL_tudtDutyCycle* pudtDutyCycle
)
{
   Std_ReturnType      udtLocalStatus = E_NOT_OK;
   PWDHAL_tudtPeriod   udtLocalPeriod;
   PWDHAL_tstrData   * pstrPwdData;

   if (u8Channel < PWDHAL_u8NUMBER_OF_CHANNELS)
   {
      pstrPwdData = &PWDHAL_astrData[u8Channel];
      if(pstrPwdData->bEnable != FALSE)
      {

         udtLocalPeriod = pstrPwdData->udtPeriod;
         *pudtPeriod    = MATHSRV_udtMIN(udtLocalPeriod, PWDHAL_akudtPeriodDesiredMax[u8Channel]);
         *pudtDutyCycle = pstrPwdData->udtDutyCycle;
         if (  (udtLocalPeriod == PWDHAL_udtPERIOD_MAX_VALUE)
            || (udtLocalPeriod == 0)
            || (pstrPwdData->bFirstPeriodOccured == FALSE) )
         {
            udtLocalStatus = E_NOT_OK;
         }
         else
         {
            udtLocalStatus = E_OK;
         }
      }
   }
   return(udtLocalStatus);
}


/**********************************************************************************************************************/
/* !FuncName    : PWDHAL_udtWriteTimeoutValue                                                                         */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_09_05009_018.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_019.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_020.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_021.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType PWDHAL_udtWriteTimeoutValue(uint8 u8Channel, PWDHAL_tudtTimeoutType udtTimeoutValue)
{
   Std_ReturnType     udtLocalReturn;
   uint32             u32LocalResult;
   uint32             u32LocalTimeoutParam;
   uint32             u32LocalSamplRate;
   PWDHAL_tstrData  * pstrPwdData;

   u32LocalTimeoutParam = (uint32)udtTimeoutValue;

   if (u8Channel < PWDHAL_u8NUMBER_OF_CHANNELS)
   {
      /* Scale the time out parameter
         ScaledTimeOut = udtTimeoutValue *  PWDHAL_aku32TimeoutParamResNs
                                       / PWDHAL_aku32SamplingRateNs */
      u32LocalResult = Mfx_Mul_u32u32_u32(u32LocalTimeoutParam, PWDHAL_aku32TimeoutParamResNs[u8Channel]);

      if (u32LocalResult > 0)
      {
         /* If overflow occurs return E_NOT_OK else E_OK */
         u32LocalSamplRate = PWDHAL_aku32SamplingRateNs[u8Channel];

         if (  (u32LocalResult < PWDHAL_udtTIMEOUT_TYPE_MAX)
            && (u32LocalSamplRate > 0) )
         {
            udtLocalReturn = E_OK;
            if ( (u32LocalResult % u32LocalSamplRate) == 0)
            {
               u32LocalResult = (u32LocalResult / u32LocalSamplRate) - 1;
            }
            else
            {
               u32LocalResult = (u32LocalResult / u32LocalSamplRate);
            }
         }
         else
         {
            udtLocalReturn = E_NOT_OK;
            u32LocalResult = PWDHAL_udtTIMEOUT_TYPE_MAX;
         }
      }
      else
      {
         udtLocalReturn = E_OK;
         u32LocalResult = 0;
      }
      pstrPwdData = &PWDHAL_astrData[u8Channel];

      /* Cast the final result according to the timeout parameter type */
      pstrPwdData->udtTimeoutReloadValue = (PWDHAL_tudtTimeoutType)u32LocalResult;
      if (pstrPwdData->bEnable == FALSE)
      {
         pstrPwdData->udtTimeoutCounter = pstrPwdData->udtTimeoutReloadValue;
      }
   }
   else
   {
      udtLocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return(udtLocalReturn);
}

/**********************************************************************************************************************/
/* INTENRAL FUNCTION DEFINITION                                                                                       */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : PWDHAL_vidMainFunction                                                                              */
/* !Description : The periodically called API, to update the signal period and duty cycle values, and monitors the    */
/*                time out of the signal.                                                                             */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_09_05009_018.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_019.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_020.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_021.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : M. Khalaf-Allah                                                                                     */
/**********************************************************************************************************************/
void PWDHAL_vidMainFunction(uint8 u8Channel)
{
   Dio_LevelType       bLocalCurrentLevelIsActive;
   Icu_ValueType       udtLocalPeriodRaw;
   Icu_ValueType       udtLocalActiveDurationRaw;
   uint32              u32LocalPeriod;
   Icu_DutyCycleType   strLocPeriodAndActiveTime;
   PWDHAL_tstrData   * pstrPwdData;


   #if (PWDHAL_coSAME_DUTY_CYCLE_MAX == PWDHAL_coTRUE)
   uint32 u32LocalDutyCycle;
   #endif

   pstrPwdData = &PWDHAL_astrData[u8Channel];

   if (pstrPwdData->bEnable != FALSE)
   {
      Icu_GetDutyCycleValues(PWDHAL_akudtIcuChannel[u8Channel], &strLocPeriodAndActiveTime);

      /* !Comment: Calculate the state of the pin, for timeout management            */
      bLocalCurrentLevelIsActive = Dio_ReadChannel(PWDHAL_akudtDioChannel[u8Channel]);

      /* If period is null, that means that no new measurement as been done => no new period occured */
      if(strLocPeriodAndActiveTime.PeriodTime != 0)
      {

         udtLocalPeriodRaw         = strLocPeriodAndActiveTime.PeriodTime;
         udtLocalActiveDurationRaw = strLocPeriodAndActiveTime.ActiveTime;


         /* !Comment: DownCounter is refreshed each new valid period    */
         pstrPwdData->udtTimeoutCounter = pstrPwdData->udtTimeoutReloadValue;

         u32LocalPeriod = PWDHAL_u32PERIOD_AUTO_SCALING(u8Channel, udtLocalPeriodRaw);

         #if (PWDHAL_coPERIOD_TYPE_UINT32 == PWDHAL_coTRUE)
         pstrPwdData->udtPeriod = u32LocalPeriod;
         #else
         pstrPwdData->udtPeriod = (PWDHAL_tudtPeriod)( (u32LocalPeriod > (uint32)PWDHAL_udtPERIOD_MAX_VALUE)
                                                             ? PWDHAL_udtPERIOD_MAX_VALUE
                                                             : u32LocalPeriod);
         #endif /* if (PWDHAL_coPERIOD_TYPE_UINT32 == PWDHAL_coTRUE) */

         if (pstrPwdData->udtPeriod != PWDHAL_udtPERIOD_MAX_VALUE)
         {
            pstrPwdData->bFirstPeriodOccured = TRUE;
            #if (PWDHAL_coSAME_DUTY_CYCLE_MAX == PWDHAL_coTRUE)
            if (udtLocalActiveDurationRaw < (UINT32_MAX / (uint32)PWDHAL_udtDESIRED_DUTY_CYCLE_MAX) )
            {
               u32LocalDutyCycle = (uint32)udtLocalActiveDurationRaw
                                   * PWDHAL_udtDESIRED_DUTY_CYCLE_MAX;
               pstrPwdData->udtDutyCycle =
                  (PWDHAL_tudtDutyCycle)Mfx_RDiv_u32u32_u32(u32LocalDutyCycle, (uint32)udtLocalPeriodRaw);
            }
            else
            {
               pstrPwdData->udtDutyCycle = (PWDHAL_tudtDutyCycle)Mfx_RMulDiv_u32u32u32_u32(
                  (uint32)udtLocalActiveDurationRaw,
                  PWDHAL_udtDESIRED_DUTY_CYCLE_MAX,
                  (uint32)udtLocalPeriodRaw);
            }
            #else /* if (PWDHAL_coSAME_DUTY_CYCLE_MAX == PWDHAL_coTRUE) */
            pstrPwdData->udtDutyCycle = (PWDHAL_tudtDutyCycle)Mfx_RMulDiv_u32u32u32_u32(
               (uint32)udtLocalActiveDurationRaw,
               (uint32)PWDHAL_akudtDutyCycleDesiredMax[u8Channel],
               (uint32)udtLocalPeriodRaw);
            #endif /* if (PWDHAL_coSAME_DUTY_CYCLE_MAX == PWDHAL_coTRUE) */
         }
         else
         {
            pstrPwdData->udtDutyCycle = 0;
            SWFAIL_vidSoftwareErrorHook();
         }
      }
      else
      {
         /* We may have a 0 or 100% duty cycle signal here .... or a too low frequency */

         /* !Comment: DownCounter is refreshed each pin state change       */
         if (bLocalCurrentLevelIsActive != pstrPwdData->bCurrentLevelIsActive)
         {
            /* if the pin states changed, then we are in the case of a too low frequency */
            pstrPwdData->udtTimeoutCounter = pstrPwdData->udtTimeoutReloadValue;
         }
         else
         {
            if (pstrPwdData->udtTimeoutCounter != 0)
            {
               pstrPwdData->udtTimeoutCounter = pstrPwdData->udtTimeoutCounter - 1;
            }
            else
            {
               /* A timeout occurs without any edge, so the input is freeze to HIGH */
               /*(ducty = 100%) or to LOW (duty = 0%)                               */
               pstrPwdData->udtTimeoutCounter    = pstrPwdData->udtTimeoutReloadValue;

               /* restart the measurement, to prevent to have a icu timer overflow */
               Icu_StopSignalMeasurement(PWDHAL_akudtIcuChannel[u8Channel]);
               Icu_StartSignalMeasurement(PWDHAL_akudtIcuChannel[u8Channel]);

               if (PWDHAL_akbFreezePeriodOnTimeout[u8Channel] == FALSE)
               {
                  pstrPwdData->udtPeriod = PWDHAL_akudtPeriodDesiredMax[u8Channel];
               }

               if (bLocalCurrentLevelIsActive == PWDHAL_aku8ChannelActiveLevel[u8Channel])
               {
                  #if (PWDHAL_coSAME_DUTY_CYCLE_MAX == PWDHAL_coTRUE)
                  pstrPwdData->udtDutyCycle = PWDHAL_udtDESIRED_DUTY_CYCLE_MAX;
                  #else /* if (PWDHAL_coSAME_DUTY_CYCLE_MAX == PWDHAL_coTRUE) */
                  pstrPwdData->udtDutyCycle = PWDHAL_akudtDutyCycleDesiredMax[u8Channel];
                  #endif /* if (PWDHAL_coSAME_DUTY_CYCLE_MAX == PWDHAL_coTRUE) */
               }
               else
               {
                  pstrPwdData->udtDutyCycle = 0;
               }
            }
         }
      }
      /* !Comment: pin state is refreshed each 2ms                         */
      pstrPwdData->bCurrentLevelIsActive = bLocalCurrentLevelIsActive;
   }
}



/**********************************************************************************************************************/
/* !FuncName    : PWDHAL_vidInitChannel                                                                               */
/* !Description : Initialize one channel                                                                              */
/*                time out of the signal.                                                                             */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_09_05009_018.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_019.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_020.01                                                                              */
/* !Trace_To    : VEES_R_09_05009_021.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
STATIC void PWDHAL_vidInitChannel(uint8 u8Channel, PWDHAL_tstrData * pstrPwdData)
{

   #if (PWDHAL_coPERIOD_INIT_TO_MAX == PWDHAL_coTRUE)
   pstrPwdData->udtPeriod = PWDHAL_akudtPeriodDesiredMax[u8Channel];
   #else
   pstrPwdData->udtPeriod = 0;
   #endif /* if (PWDHAL_coPERIOD_INIT_TO_MAX == PWDHAL_coTRUE) */

   pstrPwdData->udtDutyCycle          = 0;
   pstrPwdData->bCurrentLevelIsActive = FALSE;
   pstrPwdData->bFirstPeriodOccured   = FALSE;
}

#define PWDHAL_STOP_SEC_CODE
#include "PWDHAL_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/

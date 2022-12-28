/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : PWM                                                     */
/* !Description     : Pulse Width Modulation Module.                          */
/*                                                                            */
/* !File            : Pwm_17_Gtm_add_on.c                                     */
/* !Description     : This file defines the add-on API of the PWM component.  */
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
 * %PID: P2017_BSW:0A111765.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Limits.h"
#include "Std_Types.h"

#include "Gtm.h"
#include "Pwm_17_Gtm.h"
#include "Pwm_17_Gtm_add_on.h"
#include "Pwm_17_Gtm_Cfg.h"

/* Assigned Hw unit Position */
#define PWM_HWUNIT_POS         ((uint8)(0x7f))

#define PWM_DUTY_VAL_MIN       ((uint16)(0x0000))

/* Used for referring Pwm_17_Gtm_PropertyType */
#define PWM_SHIFTED_CHANNEL    (1U)

/* Reference Channel Position */
#define PWM_REFERENCE_CHAN_POS (12U)

/* lower 6-Bit mask to get the channel ID */
#define PWM_6BIT_MASK          (0x3FU)

/* Polarity Position */
#define PWM_POLSTATE_POS       (0x7U)
#define PWM_POLSTATE_MAX       ((uint32)0x1)

/* Channel Mode Positions */
#define PWM_CHANNEL_MODE_POS   ((uint32)0xA)
#define PWM_CHANNEL_MODE_MAX   ((uint32)0x3)

#define PWM_INVALID_NUMBER     (0xFFU)

/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/
/* Type for PwmPropery */
typedef union
{
   unsigned_int U;
   struct
   {
      unsigned_int Polarity      : 1; /* PWM_POLARITY_HIGH or PWM_POLARITY_LOW */
      unsigned_int Coherency     : 1; /* PWM_NON_COHERENT or PWM_COHERENT  */
      unsigned_int ChannelType   : 1; /* PWM_SHIFTED_CHANNEL or PWM_NORMAL_CHANNEL*/
      unsigned_int IsReference   : 1; /* PWM_REFERENCE_CHANNEL or
                                         PWM_NOT_REFERENCE_CHANNEL */
      unsigned_int PreviousState : 1; /* PWM_IDLE_CHANNEL or PWM_ACTIVE_CHANNEL  */
      unsigned_int Padding       : 3;
      unsigned_int RefChannelId  : 8;
      unsigned_int Reserved      : 16;
   }            B;
} Pwm_17_Gtm_PropertyType;

#define PWM_17_GTM_START_SEC_CODE
#include "PWM_17_GTM_MemMap.h"

static _INLINE_ uint8 Pwm_lAssignedHW(uint32 Value);
static _INLINE_ Pwm_17_Gtm_ChannelType Pwm_lReferChan(uint32 Value);
static _INLINE_ uint8                       Pwm_lPolarity(uint32 Value);
static _INLINE_ Pwm_17_Gtm_ChannelClassType Pwm_lChanClass(uint32 Value);
static Pwm_ChannelIdentifierType Pwm_lGtmChannelIdentifier(
          Pwm_GlobalChannelNumberType GlobalChannelNumber);

/******************************************************************************/
/* !FuncName    : Pwm_lAssignedHW                                             */
/* !Description : Local function to obtain the Assigned HW Unit from          */
/*                PwmChannelInfo                                              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
static _INLINE_ uint8 Pwm_lAssignedHW(uint32 Value)
{
   uint8 RetVal;


   RetVal = ((uint8)((Value) & (uint32)PWM_HWUNIT_POS));
   return (RetVal);
}

/******************************************************************************/
/* !FuncName    : Pwm_lReferChan                                              */
/* !Description : Local function :To obtain Reference channel Number          */
/*                                                                            */
/* !LastAuthor  : G. Mostafa                                                  */
/******************************************************************************/
static _INLINE_ Pwm_17_Gtm_ChannelType Pwm_lReferChan(uint32 Value)
{
   Pwm_17_Gtm_ChannelType RetVal;


   RetVal = (((uint32)(Value) >> PWM_REFERENCE_CHAN_POS) & (PWM_6BIT_MASK));
   return (RetVal);
}

/******************************************************************************/
/* !FuncName    : Pwm_lPolarity                                               */
/* !Description : Local function :To obtain the Polarity                      */
/*                                                                            */
/* !LastAuthor  : G. Mostafa                                                  */
/******************************************************************************/
static _INLINE_ uint8 Pwm_lPolarity(uint32 Value)
{
   uint8 RetVal;


   RetVal = (Pwm_17_Gtm_OutputStateType)(((uint32)(Value) >> PWM_POLSTATE_POS)
                                         & (PWM_POLSTATE_MAX)
                                        );
   return(RetVal);
}

/******************************************************************************/
/* !FuncName    : Pwm_lChanClass                                              */
/* !Description : Local function :To obtain the channel class                 */
/*                                                                            */
/* !LastAuthor  : G. Mostafa                                                  */
/******************************************************************************/
static _INLINE_ Pwm_17_Gtm_ChannelClassType Pwm_lChanClass(uint32 Value)
{
   Pwm_17_Gtm_ChannelClassType RetVal;


   RetVal = (Pwm_17_Gtm_ChannelClassType) \
           (((uint32)(Value) >> PWM_CHANNEL_MODE_POS) & (PWM_CHANNEL_MODE_MAX));
   return (RetVal);
}

/******************************************************************************/
/* !FuncName    : Pwm_lGtmGetTomDutyCycle                                     */
/* !Description : Local function :To get TOM Duty cycle                       */
/*                                                                            */
/* !LastAuthor  : G. Mostafa                                                  */
/******************************************************************************/
static uint16 Pwm_lGtmGetTomDutyCycle
(
   Pwm_ChannelIdentifierType GlobalChannelId,
   Pwm_17_Gtm_PropertyType   PwmProperty
)
{
   const Pwm_17_Gtm_ConfigType *const  Local_kConfigPtr = &Pwm_ConfigRoot[0];
   const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr;
   Pwm_17_Gtm_ChannelType              MainChannel;
   Pwm_17_Gtm_PeriodType               Period;
   uint8                               u8LocalModuleNumber;
   uint8                               u8LocalChannelNumber;
   uint8                               u8LocalCounter;
   Gtm_OutputLevelType                 OutputState;
   uint16                              u16LocalPeriodReg;
   uint16                              u16LocalDutyReg;
   uint16                              u16LocalDutyCycle;

   /* Extract the Module specific information */   
   u8LocalModuleNumber  = GlobalChannelId.ModuleNo;
   u8LocalChannelNumber = GlobalChannelId.ChannelNo;

   u16LocalPeriodReg = Gtm_GetTomCompareValCm0(u8LocalModuleNumber,
                                               u8LocalChannelNumber);
   u16LocalDutyReg = Gtm_GetTomCompareValCm1(u8LocalModuleNumber,
                                             u8LocalChannelNumber);

   #if (  (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) \
       || (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
   if (PwmProperty.B.ChannelType == PWM_SHIFTED_CHANNEL)
   {
      LocalPwmChanPtr = Local_kConfigPtr->ChannelConfigPtr;
      u8LocalCounter  = UINT8_MIN;
      while (u8LocalCounter != u8LocalChannelNumber)
      {
         LocalPwmChanPtr++;
         u8LocalCounter++;
      }
      MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
      /* Get main period */
      Period =
         ((Local_kConfigPtr->ChannelConfigPtr) + MainChannel)->PeriodDefault;

      if (u16LocalPeriodReg == u16LocalDutyReg)
      {
         OutputState = Gtm_GetTomOutputState(u8LocalModuleNumber,
                                             u8LocalChannelNumber);
         if (OutputState != PwmProperty.B.Polarity)
         {
            u16LocalDutyCycle = PWM_DUTY_VAL_MIN;
         }
         else
         {
            u16LocalDutyCycle = Period;
         }
      }
     else
     {
         /* CM0 Reg = u16LocalPeriodReg = Shift */
         /* CM1 Reg = u16LocalDutyReg = Duty + Shift modulo Period               */
         /* If PWM_USED_FIXED_PERIOD_CENTER_ALIGNED: Shift = (Period - Duty) / 2 */
         /* So, Duty = (u16LocalDutyReg - u16LocalPeriodReg) modulo Period       */
         if (u16LocalDutyReg > u16LocalPeriodReg)
         {
            /* Case (Duty + Shift) modulo Period > Shift */
            /* ie Case (Duty + Shift) < Period           */
            u16LocalDutyCycle = u16LocalDutyReg - u16LocalPeriodReg;
         }
         else
         {
            /* Case (Duty + Shift) modulo Period < Shift */
            /* ie Case (Duty + Shift) > Period            */
            u16LocalDutyCycle = (uint16) ( (Period - u16LocalPeriodReg)
                                         + u16LocalDutyReg;
         }
      }
   }
   else
   #endif /* if (  (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
                || (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)) */
   {
      COMPILER_UNUSED_PARAMETER(u8LocalCounter);
      COMPILER_UNUSED_PARAMETER(Period);
      COMPILER_UNUSED_PARAMETER(MainChannel);
      COMPILER_UNUSED_PARAMETER(LocalPwmChanPtr);
      COMPILER_UNUSED_PARAMETER(Local_kConfigPtr);

      if (u16LocalPeriodReg <= u16LocalDutyReg)
      {
         OutputState = Gtm_GetTomOutputState(u8LocalModuleNumber,
                                             u8LocalChannelNumber);
         if (OutputState != PwmProperty.B.Polarity)
         {
            u16LocalDutyCycle = PWM_DUTY_VAL_MIN;
         }
         else
         {
            u16LocalDutyCycle = u16LocalPeriodReg;
         }
      }
      else
      {
         u16LocalDutyCycle = u16LocalDutyReg;
      }
   }

   return (u16LocalDutyCycle);
}

/******************************************************************************/
/* !FuncName    : Pwm_lGtmGetAtomDutyCycle                                    */
/* !Description : Local function :To get ATOM Duty cycle                      */
/* !Description : Only usable if Duty cycle raw value is 16 bits value        */
/*                                                                            */
/* !LastAuthor  : G. Mostafa                                                  */
/******************************************************************************/
static uint16 Pwm_lGtmGetAtomDutyCycle
(
   Pwm_ChannelIdentifierType GlobalChannelId,
   Pwm_17_Gtm_PropertyType   PwmProperty
)
{
   const Pwm_17_Gtm_ConfigType *const  Local_kConfigPtr = &Pwm_ConfigRoot[0];
   const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr;
   Pwm_17_Gtm_ChannelType              MainChannel;
   Pwm_17_Gtm_PeriodType               Period;
   uint8                               u8LocalModuleNumber;
   uint8                               u8LocalChannelNumber;
   uint8                               u8LocalCounter;
   Gtm_OutputLevelType                 OutputState;
   uint32                              u32LocalPeriodReg;
   uint32                              u32LocalDutyReg;
   uint16                              u16LocalDutyCycle;

   /* Extract the Module specific information */   
   u8LocalModuleNumber  = GlobalChannelId.ModuleNo;
   u8LocalChannelNumber = GlobalChannelId.ChannelNo;

   u32LocalPeriodReg = Gtm_GetAtomCompareValCm0(u8LocalModuleNumber,
                                                u8LocalChannelNumber);
   u32LocalDutyReg = Gtm_GetAtomCompareValCm1(u8LocalModuleNumber,
                                              u8LocalChannelNumber);

   #if (  (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) \
       || (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
   if (PwmProperty.B.ChannelType == PWM_SHIFTED_CHANNEL)
   {
      LocalPwmChanPtr = Local_kConfigPtr->ChannelConfigPtr;
      u8LocalCounter  = UINT8_MIN;
      while (u8LocalCounter != u8LocalChannelNumber)
      {
         LocalPwmChanPtr++;
         u8LocalCounter++;
      }
      MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
      /* Get main period */
      Period =
         ((Local_kConfigPtr->ChannelConfigPtr) + MainChannel)->PeriodDefault;

      if (u32LocalPeriodReg == u32LocalDutyReg)
      {
         OutputState = Gtm_GetTomOutputState(u8LocalModuleNumber,
                                             u8LocalChannelNumber);
         if (OutputState != PwmProperty.B.Polarity)
         {
            u16LocalDutyCycle = PWM_DUTY_VAL_MIN;
         }
         else
         {
            u16LocalDutyCycle = (uint16)Period;
         }
      }
     else
     {
         /* CM0 Reg = u16LocalPeriodReg = Shift */
         /* CM1 Reg = u16LocalDutyReg = Duty + Shift modulo Period               */
         /* If PWM_USED_FIXED_PERIOD_CENTER_ALIGNED: Shift = (Period - Duty) / 2 */
         /* So, Duty = (u16LocalDutyReg - u16LocalPeriodReg) modulo Period       */
         if (u32LocalDutyReg > u32LocalPeriodReg)
         {
            /* Case (Duty + Shift) modulo Period > Shift */
            /* ie Case (Duty + Shift) < Period           */
            u16LocalDutyCycle = (uint16)(u32LocalDutyReg - u32LocalPeriodReg);
         }
         else
         {
            /* Case (Duty + Shift) modulo Period < Shift */
            /* ie Case (Duty + Shift) > Period            */
            u16LocalDutyCycle = (uint16) ( (Period - u32LocalPeriodReg)
                                         + u32LocalDutyReg;
         }
      }
   }
   else
   #endif /* if (  (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
                || (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)) */
   {
      COMPILER_UNUSED_PARAMETER(u8LocalCounter);
      COMPILER_UNUSED_PARAMETER(Period);
      COMPILER_UNUSED_PARAMETER(MainChannel);
      COMPILER_UNUSED_PARAMETER(LocalPwmChanPtr);
      COMPILER_UNUSED_PARAMETER(Local_kConfigPtr);

      if (u32LocalPeriodReg <= u32LocalDutyReg)
      {
         OutputState = Gtm_GetTomOutputState(u8LocalModuleNumber,
                                             u8LocalChannelNumber);
         if (OutputState != PwmProperty.B.Polarity)
         {
            u16LocalDutyCycle = PWM_DUTY_VAL_MIN;
         }
         else
         {
            u16LocalDutyCycle = (uint16)u32LocalPeriodReg;
         }
      }
      else
      {
         u16LocalDutyCycle = (uint16)u32LocalDutyReg;
      }
   }

   return(u16LocalDutyCycle);
}

/******************************************************************************/
/* !FuncName    : Pwm_lGtmChannelIdentifier                                   */
/* !Description : This routine converts the Global Channel Number to its      */
/*                corresponding Channel Number, Module Number, TGC/AGC number.*/
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Pwm_ChannelIdentifierType Pwm_lGtmChannelIdentifier(
                               Pwm_GlobalChannelNumberType GlobalChannelNumber )
{
  Pwm_ChannelIdentifierType ChannelIdentifier;
  Pwm_GlobalChannelNumberType TempChannelNumber;


  ChannelIdentifier.ChannelNo = PWM_INVALID_NUMBER;
  ChannelIdentifier.ModuleId = PWM_INVALID_NUMBER;
  ChannelIdentifier.ModuleNo = PWM_INVALID_NUMBER;
  ChannelIdentifier.GroupNo = PWM_INVALID_NUMBER;
  

  #if(GTM_TOM_USED_BY_OTHER_DRIVERS == STD_ON)
  /* Check if its a TOM channel */
  if((GlobalChannelNumber >= GTM_MAX_TIM_CHANNELS)  &&
      (GlobalChannelNumber < (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS)))
  {
    TempChannelNumber = GlobalChannelNumber - GTM_MAX_TIM_CHANNELS;
    /* Calculate Module Id of the TOM channel */
    ChannelIdentifier.ModuleId = GTM_TOM_MODULE;
    ChannelIdentifier.ModuleNo  =                    \
                 (uint8)(TempChannelNumber / GTM_CHANNELS_PER_TOM_MODULE);

    /* Calculate Channel number of the TOM channel */
    ChannelIdentifier.ChannelNo= TempChannelNumber %GTM_CHANNELS_PER_TOM_MODULE;
    ChannelIdentifier.GroupNo = 
                       (ChannelIdentifier.ChannelNo)/GTM_TOM_CHANNELS_PER_TGC;

  }
  #endif /*   #if(GTM_TOM_USED_BY_OTHER_DRIVERS == STD_ON)   */

  #if(GTM_ATOM_USED_BY_OTHER_DRIVERS == STD_ON)
  /* Check if its a ATOM channel */
  if((GlobalChannelNumber >= (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS))
    && (GlobalChannelNumber <                                                  \
         (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS + GTM_MAX_ATOM_CHANNELS)))
  {

    TempChannelNumber =
            GlobalChannelNumber - (GTM_MAX_TIM_CHANNELS + GTM_MAX_TOM_CHANNELS);
    /* Calculate Module Id of the ATOM channel */
    ChannelIdentifier.ModuleId = GTM_ATOM_MODULE;
    ChannelIdentifier.ModuleNo  =                                   \
                    (uint8)(TempChannelNumber / GTM_CHANNELS_PER_ATOM_MODULE);

    /* Calculate Channel number of the ATOM channel */
    ChannelIdentifier.ChannelNo = 
                               TempChannelNumber%GTM_CHANNELS_PER_ATOM_MODULE;
  }
  #endif 
  /*   #if(GTM_ATOM_USED_BY_OTHER_DRIVERS == STD_ON)   */

  return (ChannelIdentifier);
}

/******************************************************************************/
/* !FuncName    : Pwm_17_Gtm_vidGetDutyCycle                                  */
/* !Description : Service to get Duty cycle                                   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
uint16 Pwm_17_Gtm_vidGetDutyCycle
(
   Pwm_17_Gtm_ChannelType ChannelNumber
)
{
   const Pwm_17_Gtm_ConfigType *const  Local_kConfigPtr = &Pwm_ConfigRoot[0];
   const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr;
   Pwm_17_Gtm_ChannelClassType         ChannelKind;
   Pwm_17_Gtm_PropertyType             PwmProperty;
   uint8                               u8LocalCellUsed;
   /* !Comment: Structure to get Module info  */
   Pwm_ChannelIdentifierType LocalGlobalChannelId;
   uint16                    u16LocalDutyCycle;
   uint8                     u8LocalCounter;


   u16LocalDutyCycle = UINT16_MIN;

   if (ChannelNumber < Local_kConfigPtr->MaxChannels)
   {
      u8LocalCounter  = UINT8_MIN;
      LocalPwmChanPtr = Local_kConfigPtr->ChannelConfigPtr;
      while (u8LocalCounter != ChannelNumber)
      {
         LocalPwmChanPtr++;
         u8LocalCounter++;
      }
      u8LocalCellUsed        = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
      PwmProperty.U          = 0x0U;
      PwmProperty.B.Polarity = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
      ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);

      #if (  (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) \
          || (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
      if (  (ChannelKind == PWM_FIXED_PERIOD_SHIFTED)
         || (ChannelKind == PWM_FIXED_PERIOD_CENTER_ALIGNED))
      {
         PwmProperty.B.ChannelType = PWM_SHIFTED_CHANNEL;
      }
      #else /* if (  (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
                   || (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)) */
      COMPILER_UNUSED_PARAMETER(ChannelKind);
      #endif /* if (  (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
                   || (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)) */

      /* !Comment: Extract the Module specific information */
      LocalGlobalChannelId = Pwm_lGtmChannelIdentifier(u8LocalCellUsed);

      if (LocalGlobalChannelId.ModuleId == GTM_TOM_MODULE)
      {
         u16LocalDutyCycle = Pwm_lGtmGetTomDutyCycle(LocalGlobalChannelId,
                                                     PwmProperty);
      }
      if (LocalGlobalChannelId.ModuleId == GTM_ATOM_MODULE)
      {
         u16LocalDutyCycle = Pwm_lGtmGetAtomDutyCycle(LocalGlobalChannelId,
                                                      PwmProperty);
      }
   }
   return(u16LocalDutyCycle);
}

#define PWM_17_GTM_STOP_SEC_CODE
#include "PWM_17_GTM_MemMap.h"
/*------------------------------ end of file ---------------------------------*/

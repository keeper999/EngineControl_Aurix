/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Gtm_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\61 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-29, 11:35:17                                          **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Mcu.bmd                                           **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : complex driver implementation                          **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME  : Gtm.m                                                        **
**                                                                           **
**  $CC VERSION : \main\46 $                                                 **
**                                                                           **
**  DATE, TIME: 2014-09-29, 11:35:17                                         **
**                                                                           **
**  GENERATOR : Build b131017-0205                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file (Mcu.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
*******************************************************************************/




/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
#include "Gtm.h"



/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Note:
The user can configure the parameters with the tag Configuration:
The user should not change anything under the tag Configuration Options:
*/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define GTM_INTERRUPT_LEVEL_MODE          (0U)
#define GTM_INTERRUPT_PULSE_MODE          (1U)
#define GTM_INTERRUPT_PULSE_NOTIFY_MODE   (2U) 
#define GTM_INTERRUPT_SINGLE_PULSE_MODE   (3U)

#define TSPP1_SUBUNIT_OUTPUT 5

/* For Tbu */
#define BITS_0_TO_23   (0U)
#define BITS_3_TO_26   (1U)
#define FREE_RUNNING_COUNTER_MODE      (0)
#define FORWARD_BACKWARD_COUNTER_MODE  (1)

#define Gtm_lTbuBuildControl(Bit0, Bit123, Bit5)                              \
 (0x00U | (uint8)Bit0 | (uint8)((uint8)Bit123 << 1) | (uint8)((uint8)Bit5 << 5))
#define Gtm_lTimerCtrlValue(Word, ClockValue)                                 \
                             ((uint32)Word | (uint32)((uint32)ClockValue << 12))
#define Gtm_TimbuildReg(Word, ClockValue)                                     \
                              ((uint32)Word| (uint32)((uint32)ClockValue << 24))
#define Gtm_TimTduBuildReg(Word, ClockValue)                                  \
                             ((uint32)Word | (uint32)((uint32)ClockValue << 28))
#define Gtm_MapBuildReg(Word, ClockValue)                                     \
                              ((uint32)Word | (uint32)((uint32)ClockValue << 1))

/* For Interrupt Mode Appending */
#define Gtm_lIncludeIntMode8Bit(Bytevalue, IrqMode)                           \
                               ((uint8)Bytevalue | (uint8)((uint8)IrqMode << 6))
#define Gtm_lIncludeIntMode16Bit(Intvalue, IrqMode)                           \
                            ((uint16)Intvalue | (uint16)((uint16)IrqMode << 14))
#define Gtm_lIncludeIntMode32Bit(Wordvalue, IrqMode)                          \
                           ((uint32)Wordvalue | (uint32)((uint32)IrqMode << 30))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define MCU_START_SEC_POSTBUILDCFG
#include "MemMap.h"

static const Gtm_ClockSettingType Gtm_kClockSetting0 = 
{
  0x0096aaaaU,
  {
    0x00000009U,
    0x00000004U,
    0x00000000U,
    0x00000031U,
    0x0000013fU,
    0x0000027fU,
    0x0000c34fU,
    0x00030d3fU,
  },

    0x0U,

  {
    {  0x00000032U,  0x00000001U  },
    {  0x00000001U,  0x00000001U  },
    {  0x00000001U,  0x00000001U  }
  }
};

static const Gtm_GeneralConfigType Gtm_kGeneralConfig0 =
{
  0x0001U,
  Gtm_lIncludeIntMode8Bit(0U,GTM_INTERRUPT_PULSE_NOTIFY_MODE)
  };





static const Gtm_TomTgcConfigGroupType Gtm_kTomTgcConfigGroup0[] =
{
  {

      0x0022U,
      0x0000U,
      0x0022U,
      0x0000U,
      0x0000U,
      0x00000000U,      
  },
  {

      0x0002U,
      0x0000U,
      0x0002U,
      0x0000U,
      0x0000U,      
      0x00000000U,
  },

};

static const Gtm_TomChannelConfigType Gtm_kTomChannelConfig0[]=
{
  {
    0x1U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
  },     

  {
    0x1U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
  },     

  {
    0x1U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
    0x0U,
  },     


};
static const Gtm_TomTgcConfigType Gtm_kTomTgcConfig0[] =
{
  {
    0x0U,
    0x0U,
    NULL_PTR	
  },
  {
    0x0U,
    0x0U,
    NULL_PTR	
  },
  {
    0x0U,
    0x0U,
    &Gtm_kTomTgcConfigGroup0[0]
  },
  {
    0x0U,
    0x0U,
    &Gtm_kTomTgcConfigGroup0[1]
  },
  {
    0x0U,
    0x0U,
    NULL_PTR	
  },
  {
    0x0U,
    0x0U,
    NULL_PTR	
  },

};

static const Gtm_TomConfigType Gtm_kTomConfig0[] = 
{
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_1),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_GPT,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_1),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_1),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_GPT,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    &Gtm_kTomChannelConfig0[0]
  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    &Gtm_kTomChannelConfig0[1]
  },


  {
    GTM_DRIVER_GPT,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_1),
    NULL_PTR

  },


  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    &Gtm_kTomChannelConfig0[2]
  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_PULSE_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_2),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_1),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_1),
    NULL_PTR

  },


  {
    GTM_DRIVER_GPT,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_1),
    NULL_PTR

  },


};

static const Gtm_AtomAgcConfigGroupType Gtm_kAtomAgcConfigGroup0[] =
{
  {
      0x0000U,
      0x0000U,
      0xa8a8U,
      0x0000U,
      0x8820U,
      0x00000000U,

  },
  {
      0x0000U,
      0x0000U,
      0x0aa0U,
      0x0000U,
      0x0000U,
      0x00000000U,

  },
  {
      0x0000U,
      0x0000U,
      0xa200U,
      0x0000U,
      0x0000U,
      0x00000000U,

  },
  {
      0x0000U,
      0x0000U,
      0x0aa2U,
      0x0000U,
      0x0000U,
      0x00000000U,

  },

};

static const Gtm_AtomChannelConfigType Gtm_kAtomChannelConfig0[]=
{
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     
  {
    0x2U,
    0x1fe01feU,
    0x0U,
    0x0U, 
    0x0U,
    0x0U,
    0x0U

  },     

};

static const Gtm_AtomAgcConfigType Gtm_kAtomAgcConfig0[] =
{
  {
    0x0U,
    0x0U,
    &Gtm_kAtomAgcConfigGroup0[0]
  },
  {
    0x0U,
    0x0U,
    &Gtm_kAtomAgcConfigGroup0[1]
  },
  {
    0x0U,
    0x0U,
    &Gtm_kAtomAgcConfigGroup0[2]
  },
  {
    0x0U,
    0x0U,
    &Gtm_kAtomAgcConfigGroup0[3]
  },
  {
    0x0U,
    0x0U,
    NULL_PTR	
  },

};

static const Gtm_AtomConfigType Gtm_kAtomConfig0[] = 
{
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[0],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[1],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[2],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[3],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[4],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[5],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[6],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[7],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[8],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[9],

  },
  {
    GTM_DRIVER_GPT,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[10],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[11],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[12],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[13],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[14],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[15],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[16],

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_PULSE_NOTIFY_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[17],

  },
  {
    GTM_DRIVER_GPT,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_3),
    NULL_PTR,

  },

};

const Gtm_TimFltType Gtm_kTimFlt0[] = 
{
  {
    0x00000040U,
    0x00000040U
  },
  {
    0x00000040U,
    0x00000040U
  },
  {
    0x00000064U,
    0x00000064U
  },
};



static const Gtm_TimConfigType Gtm_kTimConfig0[] =
{
  {
    GTM_DRIVER_COMPLEX,
    Gtm_lIncludeIntMode8Bit(0x1U,GTM_INTERRUPT_PULSE_NOTIFY_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x14404U, GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kTimFlt0[0],
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_COMPLEX,
    Gtm_lIncludeIntMode8Bit(0x1U,GTM_INTERRUPT_PULSE_NOTIFY_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x14404U, GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kTimFlt0[1],
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x510000U, GTM_CONFIGURABLE_CLOCK_4),
    &Gtm_kTimFlt0[2],
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00000000U,
    0x00000000U,
    0x00000000U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_4),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x0U  
  },


};

static const Gtm_ModUsageConfigType Gtm_kModUsage0 =
{  
  { /*TIM Module Usage */
    
     /*TIM0 Module Usage*/   {
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0x00U, /*GTM Configured channel*/
      0x01U, /*GTM Configured channel*/
      0x0U, /*ICU channel no*/
      0x1U, /*ICU channel no*/
      0x2U, /*ICU channel no*/
   },
     /*TIM1 Module Usage*/
   {
      0x3U, /*ICU channel no*/
      0x4U, /*ICU channel no*/
      0x5U, /*ICU channel no*/
      0x6U, /*ICU channel no*/
      0x7U, /*ICU channel no*/
      0x8U, /*ICU channel no*/
      0x9U, /*ICU channel no*/
      0xaU, /*ICU channel no*/
   },
     /*TIM2 Module Usage*/
   {
      0xbU, /*ICU channel no*/
      0xcU, /*ICU channel no*/
      0xdU, /*ICU channel no*/
      0xeU, /*ICU channel no*/
      0xfU, /*ICU channel no*/
      0x10U, /*ICU channel no*/
      0x11U, /*ICU channel no*/
      0x12U, /*ICU channel no*/
   },
     /*TIM3 Module Usage*/
   {
      0x13U, /*ICU channel no*/
      0x14U, /*ICU channel no*/
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0x15U, /*ICU channel no*/
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
   },
     /*TIM4 Module Usage*/
   {
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
   },
     /*TIM5 Module Usage*/   {
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
   }

  },
  {   /*TOM module Usage */
     /*TOM Module 0 Usage*/    {
      0x0U,/*PWM channel no*/
      0x1U,/*PWM channel no*/
      0x2U,/*PWM channel no*/
      0x0U, /*GPT channel no*/
      0x3U,/*PWM channel no*/
      0x4U,/*PWM channel no*/
      0x5U,/*PWM channel no*/
      0x1U, /*GPT channel no*/
      0x6U,/*PWM channel no*/
      0x7U,/*PWM channel no*/
      0x8U,/*PWM channel no*/
      0x9U,/*PWM channel no*/
      0xaU,/*PWM channel no*/
      0xbU,/*PWM channel no*/
      0xcU,/*PWM channel no*/
      0xdU,/*PWM channel no*/
    },
     /*TOM Module 1 Usage*/
    {
      0x00U, /* GTM configured channel*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x01U, /* GTM configured channel*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x5U, /*GPT channel no*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x02U, /* GTM configured channel*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0xeU,/*PWM channel no*/
      0xfU,/*PWM channel no*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x10U,/*PWM channel no*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x11U,/*PWM channel no*/
    },
     /*TOM Module 2 Usage*/
    {
      0x12U,/*PWM channel no*/
      0x13U,/*PWM channel no*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x14U,/*PWM channel no*/
      0x15U,/*PWM channel no*/
      0x16U,/*PWM channel no*/
      0x17U,/*PWM channel no*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      0x18U,/*PWM channel no*/
      0x19U,/*PWM channel no*/
      0x2U, /*GPT channel no*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*TOM Module 3 Usage*/
    {
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*TOM Module 4 Usage*/
    {
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
    }
  },
  {     /*ATOM module Usage */


     /*ATOM Module 0 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      0x00U, /*GTM configured channel */
      0x01U, /*GTM configured channel */
      0x02U, /*GTM configured channel */
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      0x03U, /*GTM configured channel */
      0x04U, /*GTM configured channel */
      0x05U, /*GTM configured channel */
    },
     /*ATOM Module 1 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      0x06U, /*GTM configured channel */
      0x07U, /*GTM configured channel */
      0x08U, /*GTM configured channel */
      0x09U, /*GTM configured channel */
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      0x3U, /*GPT channel no*/
    },
     /*ATOM Module 2 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      0x0aU, /*GTM configured channel */
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      0x0bU, /*GTM configured channel */
      0x0cU, /*GTM configured channel */
    },
     /*ATOM Module 3 Usage*/
   {
      0x0dU, /*GTM configured channel */
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      0x0eU, /*GTM configured channel */
      0x0fU, /*GTM configured channel */
      0x10U, /*GTM configured channel */
      0x11U, /*GTM configured channel */
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },

   /*ATOM Module 4 Usage*/
   {
      0x4U, /*GPT channel no*/
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*ATOM Module 5 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*ATOM Module 6 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*ATOM Module 7 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*ATOM Module 8 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    }

  }
};


static const Gtm_TbuConfigType Gtm_kTbuConfig0[GTM_NO_OF_TBU_CHANNELS] = 
{
  {  Gtm_lTbuBuildControl(BITS_0_TO_23, GTM_CONFIGURABLE_CLOCK_0, 1U),  0U  },
  {  GTM_SETUNUSED8 ,0x00000000U   },
  {  GTM_SETUNUSED8 ,0x00000000U   },
};

static const uint8 Gtm_kAdcConnections0[GTM_NO_OF_ADC_MODULES] = 
{
  0x00U,  0x00U,  0x00U,  0x00U,  0x00U,  0x00U,  0x00U,  0x00U,  0x00U,  0x00U,  0x00U,  0x00U,
};

static const Gtm_MscSetType Gtm_kMscSet0[GTM_NO_OF_MSC_SETS]= 
{
  {
    {
      0x0a000609U,
      0x0e0d0000U,
      0x00000004U,
      0x01000c00U
    }
  },
  {
    {  
      0x00000000U,
      0x00000000U,
      0x00000000U,
      0x00000000U
    }
  },
  {
    {  
      0x00000000U,
      0x00000001U,
      0x00000000U,
      0x00000000U
    }
  },
  {
    {  
      0x00000000U,
      0x00000000U,
      0x00000000U,
      0x00000000U
    }
  }  
};

static const Gtm_MscInputCtrlType Gtm_kMscInputCtrl0[GTM_NO_OF_MSC_MODULES]=
{
  {
    0x02000200U,
    0x00000000U,
  },
  {
    0x00000000U,
    0x00000000U,
  },
};

static const Gtm_MscConnectionsType Gtm_kMscConnections0 = 
{
  &Gtm_kMscSet0[0],
  &Gtm_kMscInputCtrl0[0]
};


static const Gtm_PortConfigType Gtm_kPortConfig0 =
{
  {
    0x78811000U,
    0x46663983U,
    0x72777176U,
    0x00010045U,
    0x00000000U,
    0x00000000U
  },
  {
    0x00004050U,
    0x00000000U,
    0x28020000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00004000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U

  }
};

static const Gtm_ModuleConfigType Gtm_kModuleConfig0 =
{
  0x00U | (uint8)((uint8)1U << 5),  /* ARU Configuration */
  GTM_SETUNUSED8,  /* Mcfg Configuration*/
  GTM_SLEEP_ENABLE,  /* Module Sleep Mode */
  1U,  /* Global Clock Configuration - Numerator */
  1U,/* Global Clock Configuration - Denominator */
  0xFFFFFFFFU,  /* Access Enable 0 */
  0UL,  /* Access Enable 1 */
  {  0x55555680U, 
     0x01055555U,
     0x00000000U
      },    /* TIM Module Usage by GTM and ICU driver*/
  {  0x13fffff8U,
     0x00000000U
  },  /* TIM Usage */
  &Gtm_kTimConfig0[0],  /* TIM Configuration Pointer */
  {0x0000003fU},  /* TOM TGC Usage */
  &Gtm_kTomTgcConfig0[0],  /* TOM TGC Configuration Pointer */
  {0x55559595U,
   0x44530233U,0x25055005U, 0x00000000U, 0x00000000U  
   },
  {0xad15ffffU,
   0x000073c3U,

   0x00000000U
  },  /* TOM Usage */
  &Gtm_kTomConfig0[0],  /* TOM Configuration Pointer */
  {0x0000001fU},  /* ATOM AGC Usage */
  &Gtm_kAtomAgcConfig0[0],  /* ATOM AGC Configuration Pointer */  
  { 0x8ff0fcfcU, 
    0x0ff3f300U, 
    0x00000002U,
    0x00000000U,
    0x00000000U
  },
  {0x3dd0bceeU,
    
    0x00000001U,
    
    
    0x00000000U
    
    },  /* ATOM Usage */
  &Gtm_kAtomConfig0[0],  /* ATOM Configuration Pointer */   
    
  


  &Gtm_kModUsage0, /* Configuration for GTM Usage by other modules */
  &Gtm_kGeneralConfig0,  /* GTM General Configuration */
  &Gtm_kTbuConfig0[0],  /* TBU Configuration Pointer */
  NULL_PTR,  /* BRC Configuration Pointer*/
  NULL_PTR,  /* Fifo Configuration Pointer*/
  NULL_PTR,  /* F2a Configuration Pointer*/
  NULL_PTR,  /* Mcs Configuration Pointer*/
  GTM_SETUNUSED32,  /* Map Configuration*/
  NULL_PTR,  /* Dpll Configuration Pointer*/
  { /* Spe Configurations*/
    NULL_PTR,  /* Spe Configuration Pointer*/
    NULL_PTR,  /* Spe Configuration Pointer*/
    NULL_PTR,  /* Spe Configuration Pointer*/
    NULL_PTR,  /* Spe Configuration Pointer*/
  },
  NULL_PTR,  /* Cmp Configuration Pointer*/
  &Gtm_kMscConnections0,  /* Msc Configuration Pointer*/
  NULL_PTR,  /* Dsadc Connections Configuration Pointer*/
  &Gtm_kAdcConnections0[0],  /* Adc Connections Configuration Pointer*/
  {
    0x00000000U,  /* Ttcan Connections Configuration*/
  },
  0x00000000U,  /* Psi5 Connections Configuration Pointer*/
  0x00000000U  /* Psi5S Connections Configuration Pointer*/
};

const Gtm_ConfigType Gtm_ConfigRoot[]  =
{
  {
    /*  GTM Module Clock Settings  */
    &Gtm_kClockSetting0,
    /*  Pointer to Gtm Configuration structure  */
    &Gtm_kPortConfig0,
    &Gtm_kModuleConfig0,
  },
};
#define MCU_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"




/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


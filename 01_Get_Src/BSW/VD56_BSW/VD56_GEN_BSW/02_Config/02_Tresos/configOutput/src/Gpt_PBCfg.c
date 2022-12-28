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
**  FILENAME  : Gpt_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\20 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-29, 11:35:20                                         **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Gpt.bmd                                           **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GPT configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_GPT_Driver, Release AS4.0.3                **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include module header File */ 
#include "Gpt.h"

/*******************************************************************************
**                      Inclusion File Check                                  **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/



/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#define GPT_START_SEC_CODE
#include "MemMap.h"




/* 
   Channel Notification Function Declaration 
*/

/* L9781_STARTUP_SEQUENCE channel notification function declaration */
extern void L9781_vidStartupSequence(void);



/* PMP_DELAY channel notification function declaration */
extern void PMPHAL_vidDelayEndNotification(void);



/* CJ135_IRQ_TIMER channel notification function declaration */
extern void CJ135_vidEndIrqTimer_U2450(void);




#define GPT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/* MISRA RULE 87 VIOLATION: Inclusion of MemMap.h in between the code can't 
   be avoided as it is required for mapping global variables, constants 
   and code
*/ 


/* Memory Mapping the configuration constant */
#define GPT_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* 
   Channel Configuration Instance GptChannelConfigSet_0
*/ 
static const Gpt_ChannelConfigType Gpt_kChannelConfig0[ ] =
{

  /* Channel Symbolic Name(ChannelId) : MOS_TIMER 
     GTM TOM/ATOM Channel : GTM_TOM0_CHANNEL3 in GPT_MODE_CONTINUOUS
  */ 
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    NULL_PTR, /* Notification Function */
    #endif
    #if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
        && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
    0U, /* Wakeup Info */
    #endif
    /* Assigned Hardware Unit */
    GTM_TOM0_CHANNEL3,
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    (boolean)FALSE, /* Wakeup Capability */
    #endif
    GPT_MODE_CONTINUOUS, /* Channel Mode */
    #if (GPT_SAFETY_ENABLE == STD_ON)
    GPT_QM_SIGNAL, /* Channel Signal Type */
    #endif
    GTM_FIXED_CLOCK_1 /* Channel Clock frequency */
  },

  /* Channel Symbolic Name(ChannelId) : L9781_STARTUP_SEQUENCE 
     GTM TOM/ATOM Channel : GTM_TOM0_CHANNEL7 in GPT_MODE_ONESHOT
  */ 
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    &L9781_vidStartupSequence, /* Notification Function */
    #endif
    #if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
        && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
    0U, /* Wakeup Info */
    #endif
    /* Assigned Hardware Unit */
    GTM_TOM0_CHANNEL7,
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    (boolean)FALSE, /* Wakeup Capability */
    #endif
    GPT_MODE_ONESHOT, /* Channel Mode */
    #if (GPT_SAFETY_ENABLE == STD_ON)
    GPT_QM_SIGNAL, /* Channel Signal Type */
    #endif
    GTM_FIXED_CLOCK_2 /* Channel Clock frequency */
  },

  /* Channel Symbolic Name(ChannelId) : PWL_TIMER 
     GTM TOM/ATOM Channel : GTM_TOM2_CHANNEL14 in GPT_MODE_CONTINUOUS
  */ 
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    NULL_PTR, /* Notification Function */
    #endif
    #if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
        && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
    0U, /* Wakeup Info */
    #endif
    /* Assigned Hardware Unit */
    GTM_TOM2_CHANNEL14,
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    (boolean)FALSE, /* Wakeup Capability */
    #endif
    GPT_MODE_CONTINUOUS, /* Channel Mode */
    #if (GPT_SAFETY_ENABLE == STD_ON)
    GPT_QM_SIGNAL, /* Channel Signal Type */
    #endif
    GTM_FIXED_CLOCK_1 /* Channel Clock frequency */
  },

  /* Channel Symbolic Name(ChannelId) : PMP_DELAY 
     GTM TOM/ATOM Channel : GTM_ATOM1_CHANNEL7 in GPT_MODE_ONESHOT
  */ 
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    &PMPHAL_vidDelayEndNotification, /* Notification Function */
    #endif
    #if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
        && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
    0U, /* Wakeup Info */
    #endif
    /* Assigned Hardware Unit */
    GTM_ATOM1_CHANNEL7,
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    (boolean)FALSE, /* Wakeup Capability */
    #endif
    GPT_MODE_ONESHOT, /* Channel Mode */
    #if (GPT_SAFETY_ENABLE == STD_ON)
    GPT_QM_SIGNAL, /* Channel Signal Type */
    #endif
    GTM_CONFIGURABLE_CLOCK_0 /* Channel Clock frequency */
  },

  /* Channel Symbolic Name(ChannelId) : APPLICATIVE_500NS 
     GTM TOM/ATOM Channel : GTM_ATOM4_CHANNEL0 in GPT_MODE_CONTINUOUS
  */ 
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    NULL_PTR, /* Notification Function */
    #endif
    #if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
        && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
    0U, /* Wakeup Info */
    #endif
    /* Assigned Hardware Unit */
    GTM_ATOM4_CHANNEL0,
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    (boolean)FALSE, /* Wakeup Capability */
    #endif
    GPT_MODE_CONTINUOUS, /* Channel Mode */
    #if (GPT_SAFETY_ENABLE == STD_ON)
    GPT_QM_SIGNAL, /* Channel Signal Type */
    #endif
    GTM_CONFIGURABLE_CLOCK_3 /* Channel Clock frequency */
  },

  /* Channel Symbolic Name(ChannelId) : CJ135_IRQ_TIMER 
     GTM TOM/ATOM Channel : GTM_TOM1_CHANNEL4 in GPT_MODE_ONESHOT
  */ 
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    &CJ135_vidEndIrqTimer_U2450, /* Notification Function */
    #endif
    #if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
        && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
    0U, /* Wakeup Info */
    #endif
    /* Assigned Hardware Unit */
    GTM_TOM1_CHANNEL4,
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    (boolean)FALSE, /* Wakeup Capability */
    #endif
    GPT_MODE_ONESHOT, /* Channel Mode */
    #if (GPT_SAFETY_ENABLE == STD_ON)
    GPT_QM_SIGNAL, /* Channel Signal Type */
    #endif
    GTM_FIXED_CLOCK_1 /* Channel Clock frequency */
  }
};




/* 
Configuration: Configuration  
 Definition of Gpt_ConfigType structure
*/
const Gpt_ConfigType Gpt_ConfigRoot[1] = 
{

  {  
    #if (GPT_SAFETY_ENABLE == STD_ON)
    (uint32)GPT_MODULE_ID << 16U,  
    #endif
    Gpt_kChannelConfig0,

    6U,
}
};

#define GPT_STOP_SEC_POSTBUILDCFG
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

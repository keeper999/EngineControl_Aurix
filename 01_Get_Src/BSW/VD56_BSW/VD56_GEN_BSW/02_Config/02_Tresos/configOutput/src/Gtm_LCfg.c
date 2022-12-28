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
**  FILENAME  : Gtm_LCfg.c                                                   **
**                                                                           **
**  $CC VERSION : \main\15 $                                                 **
**                                                                           **
**  DATE, TIME: 2014-09-29, 11:35:16                                         **
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
**  DATE, TIME: 2014-09-29, 11:35:16                                         **
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

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/
extern void Wdg_17_Scu_Cbk_GtmNotifySRV
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void Wdg_17_Scu_Cbk_GtmNotifySRV
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void Wdg_17_Scu_Cbk_GtmNotifySRV
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void IGNHAL_vidDiagIsr_COIL_C
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom0Ch2Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void IGNHAL_vidDiagIsr_COIL_A
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom0Ch5Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void IGNHAL_vidDiagIsr_COIL_B
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom0Ch7Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom1Ch2Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom1Ch3Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom1Ch4Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom1Ch5Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom2Ch4Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom2Ch6Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom2Ch7Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom3Ch0Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom3Ch2Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom3Ch3Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom3Ch4Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CRKHAL_vidAtom3Ch5Callback
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CAMHAL_vidExCamCaptureManagement
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
extern void CAMHAL_vidInCamCaptureManagement
  (uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo,uint16 IrqNotifVal);
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

#define GTM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#ifdef GTM_MOD_CH_CONFIGURED
#if (GTM_MOD_CH_CONFIGURED == (STD_ON))

const Gtm_NotificationConfigType Gtm_kNotifConfig0 =
{
#if (GTM_NO_OF_TIM_CH_CONF_NOTIF > 0U)
	
{
    /*TIM Notification pointers*/

        &CAMHAL_vidExCamCaptureManagement,
        &CAMHAL_vidInCamCaptureManagement,
},
#endif 
  
#if (GTM_NO_OF_TOM_CH_CONF_NOTIF > 0U)
{    /*TOM Notification pointers*/

        &Wdg_17_Scu_Cbk_GtmNotifySRV,
        &Wdg_17_Scu_Cbk_GtmNotifySRV,
        &Wdg_17_Scu_Cbk_GtmNotifySRV,

  },
#endif

#if (GTM_NO_OF_ATOM_CH_CONF_NOTIF > 0U)
  {
    /*ATOM Notification pointers*/

        &IGNHAL_vidDiagIsr_COIL_C,
        &CRKHAL_vidAtom0Ch2Callback,
        &IGNHAL_vidDiagIsr_COIL_A,
        &CRKHAL_vidAtom0Ch5Callback,
        &IGNHAL_vidDiagIsr_COIL_B,
        &CRKHAL_vidAtom0Ch7Callback,
        &CRKHAL_vidAtom1Ch2Callback,
        &CRKHAL_vidAtom1Ch3Callback,
        &CRKHAL_vidAtom1Ch4Callback,
        &CRKHAL_vidAtom1Ch5Callback,
        &CRKHAL_vidAtom2Ch4Callback,
        &CRKHAL_vidAtom2Ch6Callback,
        &CRKHAL_vidAtom2Ch7Callback,
        &CRKHAL_vidAtom3Ch0Callback,
        &CRKHAL_vidAtom3Ch2Callback,
        &CRKHAL_vidAtom3Ch3Callback,
        &CRKHAL_vidAtom3Ch4Callback,
        &CRKHAL_vidAtom3Ch5Callback,
}
#endif
};
#endif 
/*#ifdef GTM_MOD_CH_CONFIGURED*/
#endif 
/*#if (GTM_MOD_CH_CONFIGURED == (STD_ON))*/

#define GTM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"



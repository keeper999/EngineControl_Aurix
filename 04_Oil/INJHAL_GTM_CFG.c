/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : Injection Hardware Abstraction Layer                    */
/*                                                                            */
/* !File            : INJHAL_GTM_CFG.c                                        */
/* !Description     : Configuration of the INJHAL Component                   */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "CRKHAL.h"
#include "IfxGtm_Ccu.h"
#include "INJHAL_CFG_E.h"
#include "INJHAL_GTM_CFG.h"
#include "INJHAL_I.h"

/*lint -save -e927 */
/*lint -save -e928 */
/*lint -save -e929 */
/*lint -save -e960 */

#define INJHAL_START_SEC_CODE
#include "INJHAL_MemMap.h"

static void INJHAL_vidCoilToPin(void);

/******************************************************************************/
/* !FuncName    : INJHAL_vidGtmInit                                           */
/* !Description : API initialises the global variables used for GTM for       */
/*                the INJHAL component.                                       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidGtmInit(void)
{
	 /*lint -esym(960,11.4) */
   INJHAL_pstrSN_CM_66 = (volatile Ifx_GTM_ATOM_CH *)
                         (IFX_GTM_BASE + ATOM_BASE_OFFSET +
                         (ATOM_OFFSET * INJHAL_snGET_ATOM(SN_CM_66))+
                         (ATOM_CH_OFFSET * INJHAL_snGET_ATOM_CH(SN_CM_66)));
   INJHAL_pstrAgcSN_CM_66 = (volatile Ifx_GTM_ATOM_AGC*)
                            (IFX_GTM_BASE + ATOM_BASE_OFFSET +
                            (ATOM_OFFSET * INJHAL_snGET_ATOM(SN_CM_66))+
                            (ATOM_AGC_OFFSET));

   /* Disable of angular and timer alarms */
   CRKHAL_vidDeactivateAlarmMode(CRKHAL_u8ALARM_INJ_1_ANGLE);
   CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_INJ_1_ANGLE);
   IfxGtm_vidAtomDisableNotification(INJHAL_pstrSN_CM_66,
                                     (uint8)IfxGtm_Compare_Unit_0);

   INJHAL_pstrSN_CM_45 = (volatile Ifx_GTM_ATOM_CH *)
                         (IFX_GTM_BASE + ATOM_BASE_OFFSET +
                         (ATOM_OFFSET * INJHAL_snGET_ATOM(SN_CM_45))+
                         (ATOM_CH_OFFSET * INJHAL_snGET_ATOM_CH(SN_CM_45)));
   INJHAL_pstrAgcSN_CM_45 = (volatile Ifx_GTM_ATOM_AGC*)
                            (IFX_GTM_BASE + ATOM_BASE_OFFSET +
                            (ATOM_OFFSET * INJHAL_snGET_ATOM(SN_CM_45))+
                            (ATOM_AGC_OFFSET));

   /* Disable of angular and timer alarms */
   CRKHAL_vidDeactivateAlarmMode(CRKHAL_u8ALARM_INJ_2_ANGLE);
   CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_INJ_2_ANGLE);
   IfxGtm_vidAtomDisableNotification(INJHAL_pstrSN_CM_45,
                                     (uint8)IfxGtm_Compare_Unit_0);

   INJHAL_pstrSN_CM_24 = (volatile Ifx_GTM_ATOM_CH *)
                         (IFX_GTM_BASE + ATOM_BASE_OFFSET +
                         (ATOM_OFFSET * INJHAL_snGET_ATOM(SN_CM_24))+
                         (ATOM_CH_OFFSET * INJHAL_snGET_ATOM_CH(SN_CM_24)));
   INJHAL_pstrAgcSN_CM_24 = (volatile Ifx_GTM_ATOM_AGC*)
                            (IFX_GTM_BASE + ATOM_BASE_OFFSET +
                            (ATOM_OFFSET * INJHAL_snGET_ATOM(SN_CM_24))+
                            (ATOM_AGC_OFFSET));

   /* Disable of angular and timer alarms */
   CRKHAL_vidDeactivateAlarmMode(CRKHAL_u8ALARM_INJ_3_ANGLE);
   CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_INJ_3_ANGLE);
   IfxGtm_vidAtomDisableNotification(INJHAL_pstrSN_CM_24,
                                     (uint8)IfxGtm_Compare_Unit_0);


}

/******************************************************************************/
/* !FuncName    : INJHAL_vidCoilToPin                                         */
/* !Description : API Connects ATOM output to IO pin                          */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
static void INJHAL_vidCoilToPin(void)
{
   IfxGtm_vidAtomToPin(INJHAL_SN_CM_66_TOUT_REG,
                       INJHAL_SN_CM_66_TOUT_SEL,
                       (Ifx_P *)INJHAL_SN_CM_66_PORT,
                       INJHAL_SN_CM_66_PIN,
                       (IfxGtmToutSel)INJHAL_SN_CM_66_GTM_TIMER);

   IfxGtm_vidAtomToPin(INJHAL_SN_CM_45_TOUT_REG,
                       INJHAL_SN_CM_45_TOUT_SEL,
                       (Ifx_P *)INJHAL_SN_CM_45_PORT,
                       INJHAL_SN_CM_45_PIN,
                       (IfxGtmToutSel)INJHAL_SN_CM_45_GTM_TIMER);

   IfxGtm_vidAtomToPin(INJHAL_SN_CM_24_TOUT_REG,
                       INJHAL_SN_CM_24_TOUT_SEL,
                       (Ifx_P *)INJHAL_SN_CM_24_PORT,
                       INJHAL_SN_CM_24_PIN,
                       (IfxGtmToutSel)INJHAL_SN_CM_24_GTM_TIMER);


}

/******************************************************************************/
/* !FuncName    : INJHAL_vidCoilToPinDisconnect                               */
/* !Description : API Connects ATOM output to IO pin                          */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidCoilToPinDisconnect(void)
{
   IfxGtm_vidAtomToPinDisconnect( INJHAL_SN_CM_66_TOUT_REG,
                                  INJHAL_SN_CM_66_TOUT_SEL,
                                  (Ifx_P *)INJHAL_SN_CM_66_PORT,
                                  INJHAL_SN_CM_66_PIN,
                                  (IfxGtmToutSel)0U);

   IfxGtm_vidAtomToPinDisconnect( INJHAL_SN_CM_45_TOUT_REG,
                                  INJHAL_SN_CM_45_TOUT_SEL,
                                  (Ifx_P *)INJHAL_SN_CM_45_PORT,
                                  INJHAL_SN_CM_45_PIN,
                                  (IfxGtmToutSel)0U);

   IfxGtm_vidAtomToPinDisconnect( INJHAL_SN_CM_24_TOUT_REG,
                                  INJHAL_SN_CM_24_TOUT_SEL,
                                  (Ifx_P *)INJHAL_SN_CM_24_PORT,
                                  INJHAL_SN_CM_24_PIN,
                                  (IfxGtmToutSel)0U);


}

/******************************************************************************/
/* !FuncName    : INJHAL_GtmEnable                                            */
/* !Description : API initialises the ATOM channels for                       */
/*                the INJHAL component.                                       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_GtmEnable(void)
{
   /* Enable the ATOM assocaited to injectors */
   IfxGtm_vidAtomEnableChannel(INJHAL_pstrSN_CM_66,
                               INJHAL_pstrAgcSN_CM_66,
                               INJHAL_snGET_ATOM_CH(SN_CM_66),
                               IfxGtm_Atom_Level_Low);

   IfxGtm_vidAtomEnableChannel(INJHAL_pstrSN_CM_45,
                               INJHAL_pstrAgcSN_CM_45,
                               INJHAL_snGET_ATOM_CH(SN_CM_45),
                               IfxGtm_Atom_Level_Low);

   IfxGtm_vidAtomEnableChannel(INJHAL_pstrSN_CM_24,
                               INJHAL_pstrAgcSN_CM_24,
                               INJHAL_snGET_ATOM_CH(SN_CM_24),
                               IfxGtm_Atom_Level_Low);

   /* TOUTSEL and IOCR configurations for injections */
   INJHAL_vidCoilToPin();
}

/******************************************************************************/
/* !FuncName    : INJHAL_GtmDisable                                           */
/* !Description : API disables the ATOM channels for                          */
/*                the INJHAL component.                                       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_GtmDisable(void)
{
   /* Disable the ATOM associated to injectors */
   IfxGtm_vidAtomDisableChannel(INJHAL_pstrSN_CM_66,
                                INJHAL_pstrAgcSN_CM_66,
                                INJHAL_snGET_ATOM_CH(SN_CM_66),
                                IfxGtm_Atom_Level_High);

   IfxGtm_vidAtomDisableChannel(INJHAL_pstrSN_CM_45,
                                INJHAL_pstrAgcSN_CM_45,
                                INJHAL_snGET_ATOM_CH(SN_CM_45),
                                IfxGtm_Atom_Level_High);

   IfxGtm_vidAtomDisableChannel(INJHAL_pstrSN_CM_24,
                                INJHAL_pstrAgcSN_CM_24,
                                INJHAL_snGET_ATOM_CH(SN_CM_24),
                                IfxGtm_Atom_Level_High);

   INJHAL_vidCoilToPinDisconnect();
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidCheckIntr                                         */
/* !Description : API checks whether time/angle interrupt on GTM              */
/*                                                                            */
/******************************************************************************/
uint32 INJHAL_vidCheckIntr(uint8 uin8Injector)
{
   uint32 u32TimeAngle ;

   u32TimeAngle = 0U ;

   switch (uin8Injector)
   {
      case CM_66:
    	  u32TimeAngle = IfxGtm_u32AtomIrqAngTime(INJHAL_pstrSN_CM_66);
         break;

      case CM_45:
    	  u32TimeAngle = IfxGtm_u32AtomIrqAngTime(INJHAL_pstrSN_CM_45);
         break;

      case CM_24:
    	  u32TimeAngle = IfxGtm_u32AtomIrqAngTime(INJHAL_pstrSN_CM_24);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   if(u32TimeAngle == IFXGTM_IRQ_UNKNOWN)
   {
     SWFAIL_vidSoftwareErrorHook();
   }
   return(u32TimeAngle);
}

/******************************************************************************/
/* !FuncName    : INJHAL_vidEnableFG                                          */
/* !Description : API initialises FG pre injection                            */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidEnableFG (uint32 u32FGAngle)
{
   IfxGtm_vidAtomSetCond(INJHAL_pstrSN_CM_66,
                         u32FGAngle,
                         INACTIVE_CCU0,
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU1_ONLY_OUT_ACTIVE);

   IfxGtm_vidAtomSetCond(INJHAL_pstrSN_CM_45,
                         u32FGAngle,
                         INACTIVE_CCU0,
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU1_ONLY_OUT_ACTIVE);

   IfxGtm_vidAtomSetCond(INJHAL_pstrSN_CM_24,
                         u32FGAngle,
                         INACTIVE_CCU0,
                         (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                         CCU1_ONLY_OUT_ACTIVE);


}

/******************************************************************************/
/* !FuncName    : INJHAL_vidEnableFGImmediate                                 */
/* !Description : API initialises FG pre injection                            */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void INJHAL_vidEnableFGImmediate(void)
{
   uint32 u32FGAngle ;
   u32FGAngle = GTM_TBU_ANGLE;

   SchM_Enter_INJHAL_ACCESS_007();
   IfxGtm_vidAtomSetCond_Immediate (INJHAL_pstrSN_CM_66,
                                    u32FGAngle,
                                    INACTIVE_CCU0,
                                    (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                                    CCU1_ONLY_OUT_ACTIVE);

   IfxGtm_vidAtomSetCond_Immediate (INJHAL_pstrSN_CM_45,
                                    u32FGAngle,
                                    INACTIVE_CCU0,
                                    (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                                    CCU1_ONLY_OUT_ACTIVE);

   IfxGtm_vidAtomSetCond_Immediate (INJHAL_pstrSN_CM_24,
                                    u32FGAngle,
                                    INACTIVE_CCU0,
                                    (uint8)IfxGtm_Atom_Cmp_Ctrl_TbuGe,
                                    CCU1_ONLY_OUT_ACTIVE);


   SchM_Exit_INJHAL_ACCESS_007();
}

#define INJHAL_STOP_SEC_CODE
#include "INJHAL_MemMap.h"

/*lint -restore */
/*------------------------------- end of file --------------------------------*/

/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CCU                                                     */
/* !Description     : GTM_CCU Component                                       */
/*                                                                            */
/* !File            : IfxGtm_Ccu.c                                            */
/* !Description     : Definition of data of Gtm Ccu Component                 */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/******************************************************************************/
/* VERSION   : v.0.1          DATE : Oct 18 2013                         */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A18540.A-SRC;10 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "Dio.h"
#include "CRKHAL_L.h"
#include "IfxGtm_Ccu.h"
#include "IfxGtm_Def.h"
#include "IfxGtm_Typ.h"
#include "IfxPort_regdef.h"
/*#include "IfxGtm_Tbu_dpll.h" - MISRA - violations */
#include "SWFAIL.h"

/******************************************************************************/
/*                           Macros                                           */
/******************************************************************************/
/** \addtogroup CRAKHAL
 * \{ */

/******************************************************************************/
/*                           Typedefs                                         */
/******************************************************************************/


/******************************************************************************/
/*                           Enums                                            */
/******************************************************************************/


/******************************************************************************/
/*                           Struct                                           */
/******************************************************************************/


/******************************************************************************/
/*                           Variables                                        */
/******************************************************************************/

/******************************************************************************/
/*                           Function prototypes                              */
/******************************************************************************/

#define CRKHAL_START_SEC_CODE
#include "CRKHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomEnableChannel                                 */
/* !Description : This function configures ATOM                               */
/*     1)   Configure Atom control register based on passed Atom Number       */
/*     2)   Configure Atom control to SOMC mode                               */
/*     3)   Configure interrupt for pulse notify mode                         */
/*     4)   Configure registers like ENDIS_CTRL, ENDIS_STAT, OUTEN_CTRL,      */
/*             OUTEN_STAT, FUPD_CTRL                                          */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidAtomEnableChannel(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                                 volatile Ifx_GTM_ATOM_AGC *Ifx_Atom_Agc,
                                 IfxGtm_AtomCh  Channel,
                                 IfxGtm_Atom_Level Level
                             )
{    
   uint32   u32LocalData_Val;
   IFX_GTM_WRITE_REG(Ifx_Atom->CTRL.U,
                     IFX_GTM_ATOM_CH_CTRL_WR_MASK_SL,
                     IFX_GTM_ATOM_CH_CTRL_SL_OFF,
                     Level);
   /* Ifx_Atom->CTRL.B.SL   = (uint32)Level; */
   IFX_GTM_WRITE_REG(Ifx_Atom->CTRL.U,
                     IFX_GTM_ATOM_CH_CTRL_WR_MASK_MODE,
                     IFX_GTM_ATOM_CH_CTRL_MODE_OFF,
                     (uint32)IfxGtm_Atom_Mode_SOMC);
  /* Ifx_Atom->CTRL.B.MODE = (uint32)IfxGtm_Atom_Mode_SOMC; */
   Ifx_Atom->IRQ_MODE.U = (uint32)IfxGtm_IrqMode_PulseNotifyMode; 
                                    
   u32LocalData_Val = (uint32)((uint32)(IfxGtm_AtomCtrl_Enable)
                   << (2U * (uint32)Channel));

   Ifx_Atom_Agc->ENDIS_CTRL.U = u32LocalData_Val;
   Ifx_Atom_Agc->ENDIS_STAT.U = u32LocalData_Val;
   Ifx_Atom_Agc->OUTEN_CTRL.U = u32LocalData_Val;
   Ifx_Atom_Agc->OUTEN_STAT.U = u32LocalData_Val;
   Ifx_Atom_Agc->FUPD_CTRL.U  = u32LocalData_Val;
   
   Ifx_Atom->IRQ_NOTIFY.U = 3U;
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomDisableChannel                                */
/* !Description : This function disables ATOM Channel                         */
/*               - Configures the ATOM CTRL register SL bit as per level      */
/*                passed as parameter.                                        */
/*               - Disable CCU0 & 1 in CTRL register                          */
/*               - reset all other registers like ENDIS_CTRL, ENDIS_STAT,     */
/*                 OUTEN_CTRL, OUTEN_STAT, FUPD_CTRL                          */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidAtomDisableChannel(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                                  volatile Ifx_GTM_ATOM_AGC *Ifx_Atom_Agc,
                                  IfxGtm_AtomCh  Channel,
                                  IfxGtm_Atom_Level Level
                                 )
{      
   uint32   u32LocalData_Val;
   IFX_GTM_WRITE_REG(Ifx_Atom->CTRL.U,
                     IFX_GTM_ATOM_CH_CTRL_WR_MASK_SL,
                     IFX_GTM_ATOM_CH_CTRL_SL_OFF,
                     Level);
   /* Ifx_Atom->CTRL.B.SL = (uint32)Level; */

   u32LocalData_Val = (uint32)((uint32)(IfxGtm_AtomCtrl_Disable)
                   << (2U * (uint32)Channel));
   /* The value being written into the ACB field is a legal value. This value
     will disable both the CCU0 and CCU1 comparisions */
   Ifx_Atom->CTRL.U = 0x9C0 ;

   Ifx_Atom_Agc->ENDIS_CTRL.U = u32LocalData_Val;
   Ifx_Atom_Agc->ENDIS_STAT.U = u32LocalData_Val;
   Ifx_Atom_Agc->OUTEN_CTRL.U = u32LocalData_Val;
   Ifx_Atom_Agc->OUTEN_STAT.U = u32LocalData_Val;
   Ifx_Atom_Agc->FUPD_CTRL.U  = u32LocalData_Val;
}
   
/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomWriteMode                                     */
/* !Description : This function configures the ATOM acb register for Action on*/
/*                the Compare Match.                                          */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidAtomWriteMode(volatile Ifx_GTM_ATOM_CH *Ifx_Atom, uint8 acb)
{
   /* Action on the Compare Match */
   IFX_GTM_WRITE_REG(Ifx_Atom->CTRL.U,
                     IFX_GTM_ATOM_CH_CTRL_WR_MASK_ACB,
                     IFX_GTM_ATOM_CH_CTRL_ACB_OFF,
                     acb);
   /* Ifx_Atom->CTRL.B.ACB = acb; */
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomWriteMode                                     */
/* !Description : This function configures TIM channel which used for Alarm   */
/*                events of CAM functionality.                                */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimWriteMode(volatile Ifx_GTM_TIM_CH *Ifx_Tim, uint8 mode)
{
  switch(mode)
  {
    case MODE_CAP_RISING:
      IFX_GTM_CLEAR_BIT(Ifx_Tim->CTRL.U, IFX_GTM_TIM_CH_CTRL_ISL_OFF);
      IFX_GTM_SET_BIT(Ifx_Tim->CTRL.U, IFX_GTM_TIM_CH_CTRL_DSL_OFF);
          break;

    case MODE_CAP_FALLING:
      IFX_GTM_CLEAR_BIT(Ifx_Tim->CTRL.U, IFX_GTM_TIM_CH_CTRL_ISL_OFF);
      IFX_GTM_CLEAR_BIT(Ifx_Tim->CTRL.U, IFX_GTM_TIM_CH_CTRL_DSL_OFF);
          break;

    case MODE_CAP_BOTH_EDGES:
      IFX_GTM_SET_BIT(Ifx_Tim->CTRL.U, IFX_GTM_TIM_CH_CTRL_ISL_OFF);
      IFX_GTM_CLEAR_BIT(Ifx_Tim->CTRL.U, IFX_GTM_TIM_CH_CTRL_DSL_OFF);
          break;

   default:
          break;

  }

  IfxGtm_vidTimEnable(Ifx_Tim);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomWrite                                         */
/* !Description : This function writes to ATOM channel depending on passing   */
/*                parameter. The angle and time condition, cmp startergy will */
/*                be passed as parameter. Depending on these factors the      */
/*                compare register is loaded.                                 */
/* Note:          This function uses CCU0 or 1 depends on timeCond parameter. */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidAtomWrite(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                         uint32 angleCond, /* absolute angle */
                         uint32 timeCond, /* read relative time */
                         uint8 cmpStrategy
                        )
{
   uint32 u32LocalCapturedTime;
   uint32 u32LocalCapturedAng;
   uint32 u32LocalAbsRel;
   
   /* read required to unlock the registers */
   u32LocalCapturedTime = (uint32)Ifx_Atom->SR0.U;
   u32LocalCapturedAng  = (uint32)Ifx_Atom->SR1.U;
   COMPILER_UNUSED_PARAMETER(u32LocalCapturedTime);
   COMPILER_UNUSED_PARAMETER(u32LocalCapturedAng);
   
   /* set the Compare startegy */ 
   IFX_GTM_WRITE_REG(Ifx_Atom->CTRL.U,
                     IFX_GTM_ATOM_CH_CTRL_WR_MASK_CMP_CTRL,
                     IFX_GTM_ATOM_CH_CTRL_CMP_CTRL_OFF,
                     cmpStrategy);
   /* Ifx_Atom->CTRL.B.CMP_CTRL = cmpStrategy; */
   
   /* Convert to relative angle */
   u32LocalAbsRel = IfxGtm_u32TbuConvAbsToRelAng(angleCond);
   
   /* Set the CM0 and CM1 registers */
   if (timeCond != INACTIVE_CCU0)
   {   
      Ifx_Atom->CM0.U = (uint32) (timeCond & (GTM_TBU_TIMER_MAX_LIMIT));
   }
   if (angleCond != INACTIVE_CCU1)
   {   
      Ifx_Atom->CM1.U = (uint32) (u32LocalAbsRel & (GTM_TBU_TIMER_MAX_LIMIT));
   }
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomEnableNotif                                   */
/* !Description : This function enables Alarm notification by configuring     */
/*                interrupt enable.                                           */
/*               Note:This function uses CCU0 or 1 depending on passed        */
/*               parameter Compare_Unit                                       */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidAtomEnableNotif(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                               uint8 compare_Unit
                              )
{ 
   if ((uint8)IfxGtm_Compare_Unit_1 == compare_Unit)
   {
      IFX_GTM_SET_BIT(Ifx_Atom->IRQ_EN.U,
                      IFX_GTM_ATOM_CH_IRQ_EN_CCU1TC_IRQ_EN_OFF);
      /* Ifx_Atom->IRQ_EN.B.CCU1TC_IRQ_EN = 1U; */
   }
   else
   {                               
      IFX_GTM_SET_BIT(Ifx_Atom->IRQ_EN.U,
                      IFX_GTM_ATOM_CH_IRQ_EN_CCU0TC_IRQ_EN_OFF);
      /* Ifx_Atom->IRQ_EN.B.CCU0TC_IRQ_EN = 1U; */
   }
}                         
      
/******************************************************************************/
/* !FuncName    : IfxGtm_vidTimEnableNotif                                    */
/* !Description : This function enables Tim Alarm notification by configuring */
/*                interrupt enable.                                           */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimEnableNotif(volatile Ifx_GTM_TIM_CH *Ifx_Tim)
{
   IFX_GTM_SET_BIT(Ifx_Tim->IRQ_EN.U, IFX_GTM_TIM_CH_IRQ_EN_NEWVAL_IRQ_EN_OFF);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomDisableNotification                           */
/* !Description : This function disables Alarm Notification by disabling      */
/*                Interrupt.                                                  */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidAtomDisableNotification(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                                       uint8 compare_Unit
                                      )
{ 
   if ((uint8)IfxGtm_Compare_Unit_1 == compare_Unit)
   {   
      IFX_GTM_CLEAR_BIT(Ifx_Atom->IRQ_EN.U,
                        IFX_GTM_ATOM_CH_IRQ_EN_CCU1TC_IRQ_EN_OFF);
      /* Ifx_Atom->IRQ_EN.B.CCU1TC_IRQ_EN = 0U; */
   }
   else
   {
      IFX_GTM_CLEAR_BIT(Ifx_Atom->IRQ_EN.U,
                        IFX_GTM_ATOM_CH_IRQ_EN_CCU0TC_IRQ_EN_OFF);
      /* Ifx_Atom->IRQ_EN.B.CCU0TC_IRQ_EN = 0U; */
   }
}
/******************************************************************************/
/* !FuncName    : IfxGtm_vidTimDisableNotification                            */
/* !Description : This function disables TIM Notification by disabling        */
/*                Interrupt.                                                  */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimDisableNotification(volatile Ifx_GTM_TIM_CH *Ifx_Tim)
{ 
  IFX_GTM_CLEAR_BIT(Ifx_Tim->IRQ_EN.U, IFX_GTM_TIM_CH_IRQ_EN_NEWVAL_IRQ_EN_OFF);
}  

/******************************************************************************/
/* !FuncName    : IfxGtm_u32AtomIrqAngTime                                    */
/* !Description : This function returns the interrupt notification status of  */
/*               CCU0 or 1.                                                   */
/*                                                                            */
/******************************************************************************/
uint32 IfxGtm_u32AtomIrqAngTime(volatile Ifx_GTM_ATOM_CH *Ifx_Atom)
{
   uint32 u32LocalTime_Angle;

   if (  IFX_GTM_READ_REG_BITFIELD(Ifx_Atom->IRQ_NOTIFY.U,
                                   IFX_GTM_ATOM_CH_IRQ_CCU0TC_RD_MASK_BIT)
      != (boolean)FALSE) 
   /* if (1U == Ifx_Atom->IRQ_NOTIFY.B.CCU0TC) */
   {
      u32LocalTime_Angle = 1U;
   }
   else
   /* else if (1U == Ifx_Atom->IRQ_NOTIFY.B.CCU1TC) */
   {
      if (  IFX_GTM_READ_REG_BITFIELD(Ifx_Atom->IRQ_NOTIFY.U,
                                      IFX_GTM_ATOM_CH_IRQ_CCU1TC_RD_MASK_BIT)
         != (boolean)FALSE)
      {
         u32LocalTime_Angle = 0U;
      }
      else
      {
         u32LocalTime_Angle = (uint32)IFXGTM_IRQ_UNKNOWN;
      }
   }
   return(u32LocalTime_Angle);
}  

/******************************************************************************/
/* !FuncName    : IfxGtm_u8GetTimToMcsToothCount                              */
/* !Description : This function returns the Tooth counter from TIM channel    */
/*                                                                            */
/******************************************************************************/
uint8 IfxGtm_u8GetTimToMcsToothCount(void)
{
   uint8 u8LocalToothCount = (uint8)UINT8_MIN;
   /*(uint8)(CRKHAL_Tim0CrkToMcs->GPR0.B.ECNT)*/
   uint32 u32LocalToothCount = CRKHAL_Tim0CrkToMcs->GPR0.U;
   u8LocalToothCount = (uint8)(u32LocalToothCount
                    >> IFX_GTM_TIM_CH_CNTS_ECNT_OFF);
   return(u8LocalToothCount);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_ubTimReadInputSgn                                    */
/* !Description : This function returns Signal level of CRANK input by        */
/*                reading Dio_ReadChannel.                                    */
/*                                                                            */
/******************************************************************************/
boolean IfxGtm_ubTimReadInputSgn(Dio_ChannelType ChannelId )
{
   boolean  bLocalTimReadInputSgn = (boolean)TRUE;
   bLocalTimReadInputSgn = ((boolean)Dio_ReadChannel(ChannelId));
/*   bLocalTimReadInputSgn = ((boolean)IFX_GTM_READ_REG(CRKHAL_Tim0CrkToDpll->GPR0.U,
                           Ifx_GTM_TIM_CH_GPRx_RD_MASK_ECNT,
                           IFX_GTM_TIM_CH_GPR0_ECNT_OFF));*/
   return (bLocalTimReadInputSgn);
   /* return((boolean)CRKHAL_Tim0CrkToDpll->GPR0.B.ECNT % 2U); */
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTimEnableDetection                                */
/* !Description : This function enables both TIM channels by calling:         */
/*                IfxGtm_vidTimEnable(CRKHAL_Tim0CrkToDpll);                  */
/*                IfxGtm_vidTimEnable(CRKHAL_Tim0CrkToMcs);                   */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimEnableDetection(void)
{
   IfxGtm_vidTimEnable(CRKHAL_Tim0CrkToDpll);
   IfxGtm_vidTimEnable(CRKHAL_Tim0CrkToMcs);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTimEnable                                         */
/* !Description : This function enables the TIM channel used for CRANK input. */
/*          TIM channel connected to DPLL & MCS are enabled via this function.*/
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimEnable(Ifx_GTM_TIM_CH* Ifx_GtmTimCh)
{
   IFX_GTM_SET_BIT(Ifx_GtmTimCh->CTRL.U,
                   IFX_GTM_TIM_CH_CTRL_TIM_EN_OFF); /* Enable Tim Ch */
   /* Ifx_GtmTimCh->CTRL.B.TIM_EN = (1U); */
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTimDisableDetection                               */
/* !Description : This function disable TIM channel ISR                       */
/*             IfxGtm_vidTimDisable(CRKHAL_Tim0CrkToDpll);                    */
/*             IfxGtm_vidTimDisable(CRKHAL_Tim0CrkToMcs);                     */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimDisableDetection(void)
{
   IfxGtm_vidTimDisable(CRKHAL_Tim0CrkToDpll);
   IfxGtm_vidTimDisable(CRKHAL_Tim0CrkToMcs);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTimDisable                                        */
/* !Description : This function disables the TIM Channel. Following functions */
/*               are called.                                                  */
/*            IfxGtm_vidTimDisable(CRKHAL_Tim0CrkToDpll);                     */
/*            IfxGtm_vidTimDisable(CRKHAL_Tim0CrkToMcs);                      */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimDisable(Ifx_GTM_TIM_CH* Ifx_GtmTimCh)
{
   IFX_GTM_CLEAR_BIT(Ifx_GtmTimCh->CTRL.U,
                     IFX_GTM_TIM_CH_CTRL_TIM_EN_OFF); /* Disable Tim Ch */
   /* Ifx_GtmTimCh->CTRL.B.TIM_EN = (0U); */
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidDisableTimeOut                                    */
/* !Description : This function Disables Time Out of TIM channels by calling  */
/*               below functions:                                             */
/*            IfxGtm_vidTimDisableTimeOut(CRKHAL_Tim0CrkToDpll);              */
/*            IfxGtm_vidTimDisableTimeOut(CRKHAL_Tim0CrkToMcs);               */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidDisableTimeOut(void)
{
   IfxGtm_vidTimDisableTimeOut(CRKHAL_Tim0CrkToDpll);
   IfxGtm_vidTimDisableTimeOut(CRKHAL_Tim0CrkToMcs);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTimDisableTimeOut                                 */
/* !Description : This function disables time out and also disables interrupt */
/*               of TIM Channels                                              */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimDisableTimeOut(Ifx_GTM_TIM_CH* Ifx_GtmTimCh)
{
   /* Disable Time Out */
   IFX_GTM_WRITE_REG(Ifx_GtmTimCh->CTRL.U,
                     IFX_GTM_TIM_CH_CTRL_WR_MASK_TOCTRL,
                     IFX_GTM_TIM_CH_CTRL_TOCTRL_OFF,
                     IfxGtm_TimTDUDisable);
   /* Ifx_GtmTimCh->CTRL.B.TOCTRL = (0U); */
   Ifx_GtmTimCh->IRQ_NOTIFY.U = (0x10U);
   IFX_GTM_CLEAR_BIT(Ifx_GtmTimCh->IRQ_EN.U,
                     IFX_GTM_TIM_CH_IRQ_EN_TODET_IRQ_EN_OFF);
   /* Ifx_GtmTimCh->IRQ_EN.B.TODET_IRQ_EN = (0U); */
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomCcu1Write                                     */
/* !Description : This function configures absolute angel to configurable     */
/*                ATOM channel                                                */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidAtomCcu1Write(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                             uint32 u32AbsoluteAngle
                            )
{
   /* used below line for unlock */
   uint32 u32LocalSR1 = Ifx_Atom->SR1.U;
   COMPILER_UNUSED_PARAMETER(u32LocalSR1);

   Ifx_Atom->CTRL.B.CMP_CTRL =
         (uint32)IfxGtm_Atom_Cmp_Ctrl_TbuGe;

   Ifx_Atom->CM1.B.CM1 = IfxGtm_u32TbuConvAbsToRelAng(u32AbsoluteAngle);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_u32AtomCcu1Read                                      */
/* !Description : This function returns angular reference value form CM1      */
/*                register.                                                   */
/*                                                                            */
/******************************************************************************/
uint32 IfxGtm_u32AtomCcu1Read(volatile Ifx_GTM_ATOM_CH *Ifx_Atom)
{
   uint32 u32LocalAtomCcu1Read = (uint32)UINT32_MIN;
   u32LocalAtomCcu1Read = (uint32)IfxGtm_u16TbuConvRelToAbsAng(Ifx_Atom->CM1.U);
    return (u32LocalAtomCcu1Read);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_u32TimGPR1Read                                       */
/* !Description : This function returns angular reference value form TIM GPR1 */
/*               register                                                     */
/*                                                                            */
/******************************************************************************/
uint32 IfxGtm_u32TimGPR1Read(volatile Ifx_GTM_TIM_CH *Ifx_Tim)
{
   uint32 u32LocalGPR1 = 0U;
   u32LocalGPR1 =
         IFX_GTM_READ_REG_BITFIELD(Ifx_Tim->GPR1.U,
                             Ifx_GTM_TIM_CH_GPR1_RD_MASK_GPR1);
   return ((uint32)IfxGtm_u16TbuConvRelToAbsAng(u32LocalGPR1));
}

/******************************************************************************/
/* !FuncName    : IfxGtm_u32AtomCcu0Read                                      */
/* !Description : This function Reads the ccu0 value from CM0 register        */
/*                                                                            */
/******************************************************************************/
uint32 IfxGtm_u32AtomCcu0Read(volatile Ifx_GTM_ATOM_CH *Ifx_Atom)
{
   uint32 u32LocalAtomCcu0Read = (uint32)UINT32_MIN;
   u32LocalAtomCcu0Read = (uint32)(Ifx_Atom->CM0.U);
    return (u32LocalAtomCcu0Read);
}
/******************************************************************************/
/* !FuncName    : IfxGtm_u32ReadCapTime                                       */
/* !Description : This function reads the capture time                        */
/*                                                                            */
/******************************************************************************/
uint32 IfxGtm_u32ReadCapTime (volatile Ifx_GTM_ATOM_CH *Ifx_Atom)
{
   uint32 u32LocalReadCapTime = (uint32)UINT32_MIN;
   u32LocalReadCapTime = Ifx_Atom->SR0.U;
    return (u32LocalReadCapTime);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_u32ReadCapAng                                        */
/* !Description : This function returns capture angle from SR1 register       */
/*                                                                            */
/******************************************************************************/
uint32 IfxGtm_u32ReadCapAng (volatile Ifx_GTM_ATOM_CH *Ifx_Atom)
{
   uint32 u32LocalReadCapAng = (uint32)UINT32_MIN;
   u32LocalReadCapAng = Ifx_Atom->SR1.U;
    return (u32LocalReadCapAng);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomToPin                                         */
/* !Description : This function configures ATOM channel to pin.               */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidAtomToPin (uint16 tout,
                          uint16 toutSel,
                          Ifx_P *port,
                          uint16 pinIndex,
                          IfxGtmToutSel Sel
                         )
{
   uint32 u32LocalTout_RegVal;
   uint32 u32LocalTout_Mask;

   u32LocalTout_RegVal =  MODULE_GTM.INOUTSEL.T.OUTSEL[tout].U ;
   u32LocalTout_Mask = (~((uint32)(3 << (toutSel * 2)))) ;

   MODULE_GTM.INOUTSEL.T.OUTSEL[tout].U  = ( u32LocalTout_RegVal & u32LocalTout_Mask);
   MODULE_GTM.INOUTSEL.T.OUTSEL[tout].U |= (Sel << (toutSel * 2U));

   volatile Ifx_P_IOCR0 *iocr = &(port->IOCR0);
   uint8 iocrIndex = (pinIndex / 4);
   uint8 shift = (pinIndex & 0x3U) * 8;
   __ldmst (&iocr[iocrIndex].U, (0xFFUL << shift), ((uint32)0x88 << shift));
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomToPinDisconnect                               */
/* !Description : This function disconnects ATOM channel to pin.              */
/*                                                                            */
/******************************************************************************/

void IfxGtm_vidAtomToPinDisconnect(uint16 tout,
                                   uint16 toutSel,
                                   Ifx_P *port,
                                   uint16 pinIndex,
                                   IfxGtmToutSel Sel)
{

   uint32 u32LocalTout_Mask ;
   uint32 u32LocalTout_RegVal ;

   volatile Ifx_P_IOCR0 *iocr = &(port->IOCR0);
   uint8 iocrIndex = (pinIndex / 4);
   uint8 shift = (pinIndex & 0x3U) * 8;

   __ldmst (&iocr[iocrIndex].U, (0xFFUL << shift), ((uint32)0x80U << shift));

   u32LocalTout_RegVal = port->OUT.U ;
   u32LocalTout_RegVal &= ~(1 << pinIndex) ;
   port->OUT.U = u32LocalTout_RegVal;

   u32LocalTout_RegVal =  MODULE_GTM.INOUTSEL.T.OUTSEL[tout].U ;
   u32LocalTout_Mask = (~((uint32)(3 << (toutSel * 2)))) ;

   MODULE_GTM.INOUTSEL.T.OUTSEL[tout].U  = ( u32LocalTout_RegVal & u32LocalTout_Mask);
   MODULE_GTM.INOUTSEL.T.OUTSEL[tout].U |= (Sel << (toutSel * 2U));
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomSetCond                                       */
/* !Description : This function set the Compare strategy and also Set the CM0 */
/*               and CM1 registers.                                           */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidAtomSetCond(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                           uint32 angleCond, /* absolute angle */
                           uint32 timeCond,  /* read relative time */
                           uint8 cmpStrategy,
                           uint8 acb
                       )
{
   uint32 u32LocalcapturedTime; /* Variable required for Unlock */
   uint32 u32LocalcapturedAng;  /* Variable required for Unlock */
   uint32 u32LocalabsRel;

   /* read required to unlcok the registers */
   u32LocalcapturedTime = (uint32)Ifx_Atom->SR0.U;
   u32LocalcapturedAng  = (uint32)Ifx_Atom->SR1.U;
   COMPILER_UNUSED_PARAMETER(u32LocalcapturedTime);
   COMPILER_UNUSED_PARAMETER(u32LocalcapturedAng);

   /* set the Compare startegy */
   IFX_GTM_WRITE_REG(Ifx_Atom->CTRL.U,
                     IFX_GTM_ATOM_CH_CTRL_WR_MASK_CMP_CTRL,
                     IFX_GTM_ATOM_CH_CTRL_CMP_CTRL_OFF,
                     cmpStrategy);
   /* Ifx_Atom->CTRL.B_CH_CTRL_DEFAULT.CMP_CTRL = cmpStrategy;*/

   IFX_GTM_WRITE_REG(Ifx_Atom->CTRL.U,
                     IFX_GTM_ATOM_CH_CTRL_WR_MASK_ACB,
                     IFX_GTM_ATOM_CH_CTRL_ACB_OFF,
                     acb);
   /* Ifx_Atom->CTRL.B_CH_CTRL_DEFAULT.ACB = acb;*/

   /* Convert to relative angle */
   u32LocalabsRel = IfxGtm_u32TbuConvAbsToRelAng(angleCond);

   /* Set the CM0 and CM1 registers */
   if (timeCond != INACTIVE_CCU0)
   {
      Ifx_Atom->CM0.U = (uint32) (timeCond & (GTM_TBU_TIMER_MAX_LIMIT));
   }
   if (angleCond != INACTIVE_CCU1)
   {
      Ifx_Atom->CM1.U = (uint32) (u32LocalabsRel & (GTM_TBU_TIMER_MAX_LIMIT));
   }
}
/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomSetCond_Immediate                             */
/* !Description : This function set the Compare strategy and also Set the CM0 */
/*                and CM1 registers. The action will be performed immediate   */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidAtomSetCond_Immediate(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                                     uint32 angleCond, /* relative angle */
                                     uint32 timeCond,  /* read relative time */
                                     uint8 cmpStrategy ,
                                     uint8 acb
                                     )
{
   uint32 u32LocalcapturedTime; /* Variable required for Unlock */
   uint32 u32LocalcapturedAng; /* Variable required for Unlock */

   /* read required to unlock the registers */
   u32LocalcapturedTime = (uint32)Ifx_Atom->SR0.U;
   u32LocalcapturedAng = (uint32)Ifx_Atom->SR1.U;
   COMPILER_UNUSED_PARAMETER(u32LocalcapturedTime);
   COMPILER_UNUSED_PARAMETER(u32LocalcapturedAng);

   /* set the Compare startegy */
   IFX_GTM_WRITE_REG(Ifx_Atom->CTRL.U,
                     IFX_GTM_ATOM_CH_CTRL_WR_MASK_CMP_CTRL,
                     IFX_GTM_ATOM_CH_CTRL_CMP_CTRL_OFF,
                     cmpStrategy);
   /*Ifx_Atom->CTRL.B_CH_CTRL_DEFAULT.CMP_CTRL = cmpStrategy;*/

   IFX_GTM_WRITE_REG(Ifx_Atom->CTRL.U,
                     IFX_GTM_ATOM_CH_CTRL_WR_MASK_ACB,
                     IFX_GTM_ATOM_CH_CTRL_ACB_OFF,
                     acb);
   /*Ifx_Atom->CTRL.B_CH_CTRL_DEFAULT.ACB = acb;*/

   /* Set the CM0 and CM1 registers */
   if (timeCond != INACTIVE_CCU0)
   {
      Ifx_Atom->CM0.U = (uint32) (timeCond & (GTM_TBU_TIMER_MAX_LIMIT));
   }
   if (angleCond != INACTIVE_CCU1)
   {
      Ifx_Atom->CM1.U = (uint32) (angleCond & (GTM_TBU_TIMER_MAX_LIMIT));
   }
}
/******************************************************************************/
/* !FuncName    : IfxGtm_vIfxGtm_vidDeactivateAlarmidAtomDisableMode          */
/* !Description : This function disables ATOM and disables the notification   */
/*                by calling below functions:                                 */
/*      IfxGtm_vidAtomWriteMode(Ifx_Atom, CCU1_MODE_DISABLE);                 */
/*      IfxGtm_vidAtomDisableNotification(Ifx_Atom,IfxGtm_Compare_Unit_1);    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
Std_ReturnType IfxGtm_vidDeactivateAlarm(volatile Ifx_GTM_ATOM_CH *Ifx_Atom)
{
   uint32 u32LocalACB42value = (uint32)UINT32_MIN;
   uint32 u32LocalACB10value = (uint32)UINT32_MIN;
   Std_ReturnType udtLocalRetValue;

   /*IfxGtm_vidAtomWriteMode(Ifx_Atom, CCU1_MODE_DISABLE);*/
   IfxGtm_vidAtomDisableNotification(Ifx_Atom,IfxGtm_Compare_Unit_1);

   u32LocalACB42value =
      IFX_GTM_READ_REG(Ifx_Atom->CTRL.U,
                       IFX_GTM_ATOM_CH_CTRL_RD_MASK_ACB42,
                       IFX_GTM_ATOM_CH_CTRL_SOMC_ACB42_OFF);

   u32LocalACB10value =
      IFX_GTM_READ_REG(Ifx_Atom->CTRL.U,
                       IFX_GTM_ATOM_CH_CTRL_RD_MASK_ACB10,
                       IFX_GTM_ATOM_CH_CTRL_SOMC_ACB10_OFF);

   switch(u32LocalACB42value)
   {
      case SERVE_FIRST_ACB42:
         switch(u32LocalACB10value)
         {
            case SERVE_FIRST_OUT_ACTIVE:
               IfxGtm_vidAtomWriteMode(Ifx_Atom, CCU0_ONLY_OUT_ACTIVE);
               udtLocalRetValue = E_OK;
               break;

            case SERVE_FIRST_OUT_INACT:
               IfxGtm_vidAtomWriteMode(Ifx_Atom, CCU0_ONLY_OUT_INACT);
               udtLocalRetValue = E_OK;
               break;

            case SERVE_FIRST_OUT_NO_CHANGE:
               IfxGtm_vidAtomWriteMode(Ifx_Atom, CCU0_ONLY_OUT_NO_CHANGE);
               udtLocalRetValue = E_OK;
               break;

            case SERVE_FIRST_OUT_TOGGLE:
               IfxGtm_vidAtomWriteMode(Ifx_Atom, CCU0_ONLY_OUT_TOGGLE);
               udtLocalRetValue = E_OK;
               break;

            default:
               udtLocalRetValue = E_NOT_OK;
               break;
         }
         break;

      case CCU0_ONLY_ACB42:
         udtLocalRetValue = E_OK;
         break;

      case CCU1_ONLY_ACB42:
         IfxGtm_vidAtomWriteMode(Ifx_Atom, CCU1_MODE_DISABLE);
         udtLocalRetValue = E_OK;
         break;

      case CCU0_CCU1_CMP_DISABLE_ACB42:
         udtLocalRetValue = E_OK;
         break;

      default:
         udtLocalRetValue = E_NOT_OK;
         break;
   }
   return(udtLocalRetValue);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_udtDeactivateAlarmTim                                */
/* !Description : This function disables TIM and disables the notification by */
/*               calling below functions:                                     */
/*           IfxGtm_vidTimDisableNotification (Ifx_Atom, CCU1_MODE_DISABLE);  */
/*               IfxGtm_vidTimDisable (Ifx_Atom,IfxGtm_Compare_Unit_1);       */
/*                                                                            */
/******************************************************************************/
Std_ReturnType IfxGtm_udtDeactivateAlarmTim(volatile Ifx_GTM_TIM_CH *Ifx_Tim)
{
   IfxGtm_vidTimDisableNotification(Ifx_Tim);
   IfxGtm_vidTimDisable(Ifx_Tim);
   return(E_OK);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidActivateAlarm                                     */
/* !Description : This function activates alarm with respect to Atom channel  */
/*                & mode. Internally calls:                                   */
/*               IfxGtm_vidAtomWriteMode(Ifx_Atom,u8mode);                    */
/*               IfxGtm_vidAtomEnableNotif(Ifx_Atom,IfxGtm_AtomCcu1_Enable);  */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidActivateAlarm(volatile Ifx_GTM_ATOM_CH *Ifx_Atom, uint8 u8mode)
{
   IfxGtm_vidAtomWriteMode(Ifx_Atom,u8mode);
   IfxGtm_vidAtomEnableNotif(Ifx_Atom,IfxGtm_AtomCcu1_Enable);
}
/******************************************************************************/
/* !FuncName    : IfxGtm_vidAtomClearInterrupt                                */
/* !Description : The API clears the interrupt on the selected source         */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidAtomClearInterrupt(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                                  uint8 compare_Unit
                                 )
{
   if((uint8)IfxGtm_Compare_Unit_1 == compare_Unit)
   {
      Ifx_Atom->IRQ_NOTIFY.U = 2U;
   }
   else
   {
      Ifx_Atom->IRQ_NOTIFY.U = 1U;
   }
}

/******************************************************************************/
/* !FuncName    : IfxGtm_u8AtomIsChannelEnabled                               */
/* !Description : The API checks if the channel is enabled or not             */
/*                                                                            */
/******************************************************************************/
uint8 IfxGtm_u8AtomIsChannelEnabled(volatile Ifx_GTM_ATOM_AGC *Ifx_Atom_Agc,
                                  IfxGtm_AtomCh  Channel
                                   )
{
  uint32 u32LocalValue ;
  uint32 u32LocalChannel ;

  /* Check if the channel is enabled or disabled */
  u32LocalValue = Ifx_Atom_Agc->ENDIS_STAT.U ;
  u32LocalChannel = 2U * (uint32)Channel ;
  u32LocalValue = (u32LocalValue >> u32LocalChannel) & 3U ;

  /* if channel is disabled value would be 0 */
  if(u32LocalValue == 0U)
  {
    return(0U) ; /*channel is disabled */
  }
  else
  {
    return(1U); /* channel enabled */
  }
}

/******************************************************************************/
/* !FuncName    : IfxGtm_u8IsAtomRunning                                      */
/* !Description : returns Atom Running Status                                 */
/*                                                                            */
/******************************************************************************/
uint8 IfxGtm_u8IsAtomRunning(volatile Ifx_GTM_ATOM_CH *Ifx_Atom)
{
  return (Ifx_Atom->CTRL.B.ACB);
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidDISABLE_ATOM_COMPARISION                          */
/* !Description : The API disable atom compare                                */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidDISABLE_ATOM_COMPARISION(volatile Ifx_GTM_ATOM_CH *AtomPtr)
{
    IFX_GTM_WRITE_REG(AtomPtr->CTRL.U,
                 IFX_GTM_ATOM_CH_CTRL_WR_MASK_ACB,
                 IFX_GTM_ATOM_CH_CTRL_ACB_OFF,
                 0x1C);
}

#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

/*------------------------------ end of file ---------------------------------*/

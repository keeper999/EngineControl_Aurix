/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : GTM_CCU                                                 */
/* !Description     : GTM CCU Component                                       */
/*                                                                            */
/* !File            : IfxGtm_Ccu.h                                            */
/* !Description     : Definition of data of CCU Component                     */
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
 * %PID: P2017_BSW:A18535.A-SRC;8 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IfxGtm_Ccu_H_
#define IfxGtm_Ccu_H_

/******************************************************************************/
/*                      Includes                                              */
/******************************************************************************/

#include "Std_Types.h"
#include "Dio.h"
#include "IfxGtm_Def.h"
#include "IfxPort_regdef.h"
#include "CRKHAL_Cfg_Gtm.h"
#include "CRKHAL_Cfg.h"

/******************************************************************************/
/*                           Macros                                           */
/******************************************************************************/
#define IFXGTM_IRQ_UNKNOWN (1024U)
/** \addtogroup CRAKHAL
 * \{ */
/******************************************************************************/
/* !Description : TIM0CH0 Configurations                                      */
/*                                                                            */
/******************************************************************************/
#define CRANK_TIM_CAPTURE_CTRL_Cfg  (0x00004404U)

/******************************************************************************/
/* !Description : TIM0CH1 Configurations                                      */
/*                                                                            */
/******************************************************************************/
#define CRANK_TIM_PROCESS_CTRL_Cfg  (0x00000F60U)

/******************************************************************************/
/* !Description : TIM0CH1 Filter Configurations                               */
/*                                                                            */
/******************************************************************************/
/*#define CRANK_TIM_PROCESS_FltRE_Cfg (0x00000040U)
#define CRANK_TIM_PROCESS_FltFE_Cfg (0x00000050U)*/

/******************************************************************************/
/* !FuncName    : GTM_TIM_CAPTURE_TIMEOUT                                     */
/* !Description : This macro configures the Timeout value for Capture         */
/* 				  channel(TIM0CH0)											            */
/*                                                                            */
/******************************************************************************/
#define GTM_TIM_CAPTURE_TIMEOUT(Value) \
do \
{ \
	uint32 u32LocalTdu ; \
  u32LocalTdu = (uint32)((uint32) Value \
                             | ((uint32)CRANK_CAPTURE_TDU_CLK \
                               << IFX_GTM_TIM_CH_TDUV_TCS_OFF)); \
   CRKHAL_Tim0CrkToDpll->TDUV.U = u32LocalTdu;\
}\
while(0)

/******************************************************************************/
/* !FuncName    : GTM_TIM_PROCESS_TIMEOUT                                     */
/* !Description : This macro configures the Timeout value for Process         */
/* 				  channel(TIM0CH0)											            */
/*                                                                            */
/******************************************************************************/
#define GTM_TIM_PROCESS_TIMEOUT(Value) \
do \
{ \
		uint32 u32LocalTdu_1 ; \
		u32LocalTdu_1 = (uint32)(Value \
                            | ((uint32)CRANK_PROCESS_TDU_CLK \
                              << (uint32)IFX_GTM_TIM_CH_TDUV_TCS_OFF)); \
   CRKHAL_Tim0CrkToMcs->TDUV.U = u32LocalTdu_1 ;\
}\
while(0)

/******************************************************************************/
/* !FuncName    : GTM_TIM0CH0_PIN_CONFIG                                      */
/* !Description : This macro configures the Port pin to TIM channel (TIM0CH0) */
/*                                                                            */
/******************************************************************************/
#define GTM_TIM0CH0_PIN_CONFIG(u8CrkInput) \
do \
{ \
   if(CRKHAL_u8CrkInputSignal == 0U) \
   { \
      CRKHAL_u8CrkInputSignal = (uint8)CRKHAL_TIM0CH0_IN_PORT; \
   } \
   IFX_GTM_WRITE_REG(GTM_TIM0INSEL.U, \
                     (uint32)IFX_GTM_TIM_INSEL_WR_MASK_CH0SEL, \
                     (uint32)IFX_GTM_INOUTSEL_TIM_INSEL_CH0SEL_OFF, \
                     (uint32)CRKHAL_u8CrkInputSignal); \
} \
while (0)
/* GTM_TIM0INSEL.B.CH0SEL = (CRKHAL_u8CrkInputSignal); */

/******************************************************************************/
/* !FuncName    : IfxGtm_snTimToothPeriod                                     */
/* !Description : This macro returns tooth period from (TIM0CH1) GPR1 register*/
/*                                                                            */
/******************************************************************************/
/*#define IfxGtm_snTimToothPeriod() CRKHAL_Tim0CrkToMcs->GPR1.B.GPR1*/
#define IfxGtm_snTimToothPeriod() \
   IFX_GTM_READ_REG_BITFIELD(CRKHAL_Tim0CrkToMcs->GPR1.U, \
                             Ifx_GTM_TIM_CH_GPR0_RD_MASK_GPR0)

/******************************************************************************/
/* !FuncName    : IfxGtm_snTimEdgeTimeStamp                                   */
/* !Description : This macro returns the edge time stamp from (TIM0CH00 GPR0  */
/* 			      register													               */
/*                                                                            */
/******************************************************************************/
#define IfxGtm_snTimEdgeTimeStamp() \
   IFX_GTM_READ_REG_BITFIELD(CRKHAL_Tim0CrkToDpll->GPR0.U, \
                             Ifx_GTM_TIM_CH_GPR0_RD_MASK_GPR0)

/******************************************************************************/
/* !FuncName    : IfxGtm_snTimEdgeAngleValue                                  */
/* !Description : This macro returns Returns angle of edge of the tooth from  */
/* 				  TIM0CH0 GPR1 register      								            */
/*                                                                            */
/******************************************************************************/
#define IfxGtm_snTimEdgeAngleValue() \
   IFX_GTM_READ_REG_BITFIELD(CRKHAL_Tim0CrkToDpll->GPR1.U, \
                             Ifx_GTM_TIM_CH_GPR1_RD_MASK_GPR1)

/******************************************************************************/
/* !Description : GET_GTM_INTERRUPT_ENABLE_STATUS                             */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToDpll->IRQ_EN.B.NEWVAL_IRQ_EN */
/* #define GET_GTM_INTERRUPT_ENABLE_STATUS_NEWVAL \
      IFX_READ_REG_BITFIELD(CRKHAL_Tim0CrkToDpll->IRQ_EN.U, \
                            IFX_GTM_TIM_CH_IRQ_EN_RD_MASK_NEWVAL_IRQ_EN) */

/* CRKHAL_Tim0CrkToDpll->IRQ_EN.B.TODET_IRQ_EN */
/* #define GET_GTM_INTERRUPT_ENABLE_STATUS_ENG_STALL \
      IFX_READ_REG_BITFIELD(CRKHAL_Tim0CrkToDpll->IRQ_EN.U, \
                            IFX_GTM_TIM_CH_IRQ_EN_RD_MASK_TODET_IRQ_EN) */

/* CRKHAL_Tim0CrkToMcs->IRQ_EN.B.TODET_IRQ_EN */
/* #define GET_GTM_INTERRUPT_ENABLE_STATUS_CRK_OFF \
      IFX_READ_REG_BITFIELD(CRKHAL_Tim0CrkToMcs->IRQ_EN.U, \
                            IFX_GTM_TIM_CH_IRQ_EN_RD_MASK_TODET_IRQ_EN) */


/******************************************************************************/
/* !FuncName    : GTM_IRQ_NOTIFY_TIM_NEWVAL                                   */
/* !Description : Gets the TIM (TIM0CH0) NEWVAL notify status                 */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToDpll->IRQ_NOTIFY.B.NEWVAL */
#define GTM_IRQ_NOTIFY_TIM_NEWVAL \
   IFX_GTM_READ_REG_BITFIELD(CRKHAL_Tim0CrkToDpll->IRQ_NOTIFY.U, \
                              IFX_GTM_TIM_CH_IRQ_RD_MASK_NEWVAL)

/******************************************************************************/
/* !FuncName    : GTM_IRQ_NOTIFY_TIM_ENG_STALL                                */
/* !Description : Gets the TIM (TIM0CH0) TODET notify status                  */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToDpll->IRQ_NOTIFY.B.TODET */
#define GTM_IRQ_NOTIFY_TIM_ENG_STALL \
   IFX_GTM_READ_REG_BITFIELD(CRKHAL_Tim0CrkToDpll->IRQ_NOTIFY.U, \
                             IFX_GTM_TIM_CH_IRQ_RD_MASK_TODET)

/******************************************************************************/
/* !FuncName    : GTM_IRQ_NOTIFY_TIM_CRK_OFF                                  */
/* !Description : Gets the TIM (TIM0CH1) TODET notify status                  */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToMcs->IRQ_NOTIFY.B.TODET */
#define GTM_IRQ_NOTIFY_TIM_CRK_OFF \
   IFX_GTM_READ_REG_BITFIELD(CRKHAL_Tim0CrkToMcs->IRQ_NOTIFY.U, \
                             IFX_GTM_TIM_CH_IRQ_RD_MASK_TODET)

/******************************************************************************/
/* !FuncName    : GTM_ENABLE_INTERRUPT_NEWVAL                                 */
/* !Description : Enables TIM (TIM0CH0) NEWVAL interrupt                      */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToDpll->IRQ_EN.B.NEWVAL_IRQ_EN = (1U) */
#define GTM_ENABLE_INTERRUPT_NEWVAL \
   IFX_GTM_SET_BIT(CRKHAL_Tim0CrkToDpll->IRQ_EN.U, \
                   IFX_GTM_TIM_CH_IRQ_EN_NEWVAL_IRQ_EN_OFF)

/******************************************************************************/
/* !FuncName    : GTM_ENABLE_INTERRUPT_ENG_STALL                              */
/* !Description : Enables TIM (TIM0CH0) TODET interrupt                       */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToDpll->IRQ_EN.B.TODET_IRQ_EN = (1U) */
#define GTM_ENABLE_INTERRUPT_ENG_STALL \
   IFX_GTM_SET_BIT(CRKHAL_Tim0CrkToDpll->IRQ_EN.U, \
                   IFX_GTM_TIM_CH_IRQ_EN_TODET_IRQ_EN_OFF)

/******************************************************************************/
/* !FuncName    : GTM_ENABLE_INTERRUPT_CRK_OFF                                */
/* !Description : Enables TIM (TIM0CH1) TODET interrupt                       */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToMcs->IRQ_EN.B.TODET_IRQ_EN = (1U) */
#define GTM_ENABLE_INTERRUPT_CRK_OFF \
   IFX_GTM_SET_BIT(CRKHAL_Tim0CrkToMcs->IRQ_EN.U, \
                   IFX_GTM_TIM_CH_IRQ_EN_TODET_IRQ_EN_OFF)

/******************************************************************************/
/* !FuncName    : GTM_DISABLE_INTERRUPT_NEWVAL                                */
/* !Description : Disables TIM (TIM0CH0) NEWVAL interrupt                     */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToDpll->IRQ_EN.B.NEWVAL_IRQ_EN = (0U) */
#define GTM_DISABLE_INTERRUPT_NEWVAL \
   IFX_GTM_CLEAR_BIT(CRKHAL_Tim0CrkToDpll->IRQ_EN.U, \
                     IFX_GTM_TIM_CH_IRQ_EN_NEWVAL_IRQ_EN_OFF)

/******************************************************************************/
/* !FuncName    : GTM_DISABLE_INTERRUPT_ENG_STALL                             */
/* !Description : Disables TIM (TIM0CH0) TODET interrupt                      */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToDpll->IRQ_EN.B.TODET_IRQ_EN = (0U) */
#define GTM_DISABLE_INTERRUPT_ENG_STALL \
   IFX_GTM_CLEAR_BIT(CRKHAL_Tim0CrkToDpll->IRQ_EN.U, \
                     IFX_GTM_TIM_CH_IRQ_EN_TODET_IRQ_EN_OFF)

/******************************************************************************/
/* !FuncName    : GTM_DISABLE_INTERRUPT_CRK_OFF                               */
/* !Description : Disables TIM (TIM0CH1) TODET interrupt                      */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToMcs->IRQ_EN.B.TODET_IRQ_EN = (0U) */
#define GTM_DISABLE_INTERRUPT_CRK_OFF \
   IFX_GTM_CLEAR_BIT(CRKHAL_Tim0CrkToMcs->IRQ_EN.U, \
                     IFX_GTM_TIM_CH_IRQ_EN_TODET_IRQ_EN_OFF)

/******************************************************************************/
/* !FuncName    : GTM_CLEAR_NOTIFY_NEWVAL                                     */
/* !Description : Resets TIM (TIM0CH0) NEWVAL notify status                   */
/*                                                                            */
/******************************************************************************/
#define GTM_CLEAR_NOTIFY_NEWVAL     CRKHAL_Tim0CrkToDpll->IRQ_NOTIFY.U = (0x1U)

/******************************************************************************/
/* !FuncName    : GTM_CLEAR_NOTIFY_ENG_STALL                                  */
/* !Description : Resets TIM (TIM0CH0) TODET notify status                    */
/*                                                                            */
/******************************************************************************/
#define GTM_CLEAR_NOTIFY_ENG_STALL  CRKHAL_Tim0CrkToDpll->IRQ_NOTIFY.U = (0x10U)

/******************************************************************************/
/* !FuncName    : GTM_CLEAR_NOTIFY_CRK_OFF                                    */
/* !Description : Resets TIM (TIM0CH1) TODET notify status                    */
/*                                                                            */
/******************************************************************************/
#define GTM_CLEAR_NOTIFY_CRK_OFF    CRKHAL_Tim0CrkToMcs->IRQ_NOTIFY.U = (0x10U)

/******************************************************************************/
/* !FuncName    : GTM_ENABLE_TIM_TIMEOUT_ENG_STALL                            */
/* !Description : Enables TIM (TIM0CH0) Timeout feature                       */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToDpll->CTRL.B.TOCTRL = IfxGtm_TimTDUFallingEdge; */
#define GTM_ENABLE_TIM_TIMEOUT_ENG_STALL \
   IFX_GTM_WRITE_REG(CRKHAL_Tim0CrkToDpll->CTRL.U, \
                     (uint32)IFX_GTM_TIM_CH_CTRL_WR_MASK_TOCTRL, \
                     (uint32)IFX_GTM_TIM_CH_CTRL_TOCTRL_OFF, \
                     (uint32)IfxGtm_TimTDUFallingEdge)

/******************************************************************************/
/* !FuncName    : GTM_ENABLE_TIM_TIMEOUT_CRK_OFF                              */
/* !Description : Enables TIM (TIM0CH1) Timeout feature                       */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToMcs->CTRL.B.TOCTRL = IfxGtm_TimTDUFallingEdge; */
#define GTM_ENABLE_TIM_TIMEOUT_CRK_OFF \
   IFX_GTM_WRITE_REG(CRKHAL_Tim0CrkToMcs->CTRL.U, \
                     (uint32)IFX_GTM_TIM_CH_CTRL_WR_MASK_TOCTRL, \
                     (uint32)IFX_GTM_TIM_CH_CTRL_TOCTRL_OFF, \
                     (uint32)IfxGtm_TimTDUFallingEdge)

/******************************************************************************/
/* !FuncName    : GTM_DISABLE_TIM_TIMEOUT_ENG_STALL                           */
/* !Description : Disables TIM (TIM0CH0) Timeout feature                      */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToDpll->CTRL.B.TOCTRL = IfxGtm_TimTDUDisable; */
#define GTM_DISABLE_TIM_TIMEOUT_ENG_STALL \
   IFX_GTM_WRITE_REG(CRKHAL_Tim0CrkToDpll->CTRL.U, \
                     (uint32)IFX_GTM_TIM_CH_CTRL_WR_MASK_TOCTRL, \
                     (uint32)IFX_GTM_TIM_CH_CTRL_TOCTRL_OFF, \
                     (uint32)IfxGtm_TimTDUDisable)

/******************************************************************************/
/* !FuncName    : GTM_DISABLE_TIM_TIMEOUT_CRK_OFF                             */
/* !Description : Disables TIM (TIM0CH1) Timeout feature                      */
/*                                                                            */
/******************************************************************************/
/* CRKHAL_Tim0CrkToMcs->CTRL.B.TOCTRL = IfxGtm_TimTDUDisable; */
#define GTM_DISABLE_TIM_TIMEOUT_CRK_OFF \
   IFX_GTM_WRITE_REG(CRKHAL_Tim0CrkToMcs->CTRL.U, \
                     (uint32)IFX_GTM_TIM_CH_CTRL_WR_MASK_TOCTRL, \
                     (uint32)IFX_GTM_TIM_CH_CTRL_TOCTRL_OFF, \
                     (uint32)IfxGtm_TimTDUDisable)

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

void IfxGtm_vidAtomEnableChannel( volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                               volatile Ifx_GTM_ATOM_AGC *Ifx_Atom_Agc,
                               IfxGtm_AtomCh  Channel,
                               IfxGtm_Atom_Level Level
                             );

void IfxGtm_vidAtomDisableChannel( volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                               volatile Ifx_GTM_ATOM_AGC *Ifx_Atom_Agc,
                               IfxGtm_AtomCh  Channel,
                               IfxGtm_Atom_Level Level
                              );
                              
void IfxGtm_vidAtomWriteMode(volatile Ifx_GTM_ATOM_CH *Ifx_Atom, uint8 acb);
                         
void IfxGtm_vidAtomWrite(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                        uint32 angleCond, 
                        uint32 timeCond, 
                        uint8 cmpStrategy
                     );
                     
void IfxGtm_vidAtomEnableNotif(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                               uint8 compare_Unit
                              );

void IfxGtm_vidAtomDisableNotification(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                                     uint8 compare_Unit
                                    );
                                    
uint32 IfxGtm_u32AtomIrqAngTime(volatile Ifx_GTM_ATOM_CH *Ifx_Atom);

uint8 IfxGtm_u8GetTimToMcsToothCount(void);

boolean IfxGtm_ubTimReadInputSgn(Dio_ChannelType ChannelId );

void IfxGtm_vidTimEnableDetection(void);

void IfxGtm_vidTimEnable(Ifx_GTM_TIM_CH* Ifx_GtmTimCh);

void IfxGtm_vidTimDisableDetection(void);

void IfxGtm_vidTimDisable(Ifx_GTM_TIM_CH* Ifx_GtmTimCh);

void IfxGtm_vidDisableTimeOut(void);

void IfxGtm_vidTimDisableTimeOut(Ifx_GTM_TIM_CH* Ifx_GtmTimCh);

void IfxGtm_vidAtomCcu1Write(volatile Ifx_GTM_ATOM_CH   *Ifx_Atom,
		uint32 u32AbsoluteAngle);

uint32 IfxGtm_u32AtomCcu1Read(volatile Ifx_GTM_ATOM_CH   *Ifx_Atom);

uint32 IfxGtm_u32AtomCcu0Read(volatile Ifx_GTM_ATOM_CH   *Ifx_Atom);

uint32 IfxGtm_u32ReadCapTime(volatile Ifx_GTM_ATOM_CH *Ifx_Atom);

uint32 IfxGtm_u32ReadCapAng(volatile Ifx_GTM_ATOM_CH *Ifx_Atom);

void IfxGtm_vidAtomToPin(uint16 tout,
                         uint16 toutSel,
                         Ifx_P *port,
                         uint16 pinIndex,
                         IfxGtmToutSel Sel);

void IfxGtm_vidAtomToPinDisconnect(uint16 tout,
								           uint16 toutSel,
								           Ifx_P *port,
								           uint16 pinIndex,
								           IfxGtmToutSel Sel);

void IfxGtm_vidAtomSetCond(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                          uint32 angleCond,
                          uint32 timeCond,
                          uint8 cmpStrategy,
                          uint8 acb);

void IfxGtm_vidAtomSetCond_Immediate(volatile Ifx_GTM_ATOM_CH *Ifx_Atom,
                                      uint32 angleCond,
                                      uint32 timeCond,
                                      uint8 cmpStrategy,
                                      uint8 acb
                                    );

Std_ReturnType IfxGtm_vidDeactivateAlarm( volatile Ifx_GTM_ATOM_CH   *Ifx_Atom);

void IfxGtm_vidActivateAlarm(volatile Ifx_GTM_ATOM_CH   *Ifx_Atom, uint8 u8mode);

void IfxGtm_vidAtomClearInterrupt(volatile Ifx_GTM_ATOM_CH   *Ifx_Atom ,
		uint8 compare_Unit);

uint8 IfxGtm_u8AtomIsChannelEnabled(volatile Ifx_GTM_ATOM_AGC *Ifx_Atom_Agc,
		                            IfxGtm_AtomCh  Channel
                                   );
void IfxGtm_vidDISABLE_ATOM_COMPARISION(volatile Ifx_GTM_ATOM_CH *AtomPtr);

uint8 IfxGtm_u8IsAtomRunning(volatile Ifx_GTM_ATOM_CH *Ifx_Atom);

void IfxGtm_vidTimEnableNotif(volatile Ifx_GTM_TIM_CH *Ifx_Tim);

void IfxGtm_vidTimDisableNotification(volatile Ifx_GTM_TIM_CH *Ifx_Tim);

void IfxGtm_vidTimWriteMode(volatile Ifx_GTM_TIM_CH *Ifx_Tim, uint8 mode);

Std_ReturnType IfxGtm_udtDeactivateAlarmTim(volatile Ifx_GTM_TIM_CH *Ifx_Tim);

uint32 IfxGtm_u32TimGPR1Read(volatile Ifx_GTM_TIM_CH *Ifx_Tim);

#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

#endif
/* IfxGtm_Ccu_H_ */

/*------------------------------ end of file ---------------------------------*/

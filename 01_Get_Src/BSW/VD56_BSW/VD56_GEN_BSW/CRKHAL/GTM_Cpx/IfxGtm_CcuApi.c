/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : GTM_CCU                                                 */
/* !Description     : GTM_CCU Component                                       */
/*                                                                            */
/* !File            : IfxGtm_CcuApi.c                                         */
/* !Description     : Definition GTM CCU APIs                                 */
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
 * %PID: P2017_BSW:A18531.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
/* GTM_CCUAPIC.1   / IfxGtm_vidInitTimCh                                      */
/* GTM_CCUAPIC.2   / IfxGtm_vidTimCaptureCfg                                  */
/* GTM_CCUAPIC.3   / IfxGtm_vidTim0CrkToMcsCfg                                */
/* GTM_CCUAPIC.3   / IfxGtm_vidTimFilterConfig                                */
/* GTM_CCUAPIC.3   / IfxGtm_vidTimCfg                                         */
/* GTM_CCUAPIC.3   / IfxGtm_vidTimNoiseConfig                                 */
/******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"

#include "CRKHAL_L.h"

#include "IfxGtm_Def.h"
#include "IfxGtm_Ccu.h"

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
/* !FuncName    : IfxGtm_vidInitTimCh                                         */
/* !Description : Initializes selected TIM channel to TIM variables.          */
/*                CRKHAL_Tim0CrkToDpll - TIM0CH0                              */
/*                CRKHAL_Tim0CrkToMcs - TIM0CH1                               */
/*                                                                            */
/******************************************************************************/

void IfxGtm_vidInitTimCh(void)
{
   CRKHAL_Tim0CrkToDpll = (Ifx_GTM_TIM_CH *)(IFX_GTM_BASE + TIM_GLB_OFFSET +
      (TIMxCHxOFFSET * CRANK_TIM_CH_xSEL));
   CRKHAL_Tim0CrkToMcs = (Ifx_GTM_TIM_CH *)(IFX_GTM_BASE + TIM_GLB_OFFSET +
      (TIMxCHxOFFSET * CRANK_TIM_CH_ySEL));
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTimCaptureCfg                                     */
/* !Description : This function configures TIM Channel used for Capture (DPLL)*/
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimCaptureCfg(void)
{

   CRKHAL_Tim0CrkToDpll->IRQ_MODE.U = (uint32)IfxGtm_IrqMode_PulseNotifyMode;
   /* TIM Ctrl Settings */
   CRKHAL_Tim0CrkToDpll->CTRL.U = CRANK_TIM_CAPTURE_CTRL_Cfg;
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTim0CrkToMcsCfg                                   */
/* !Description : This function configures TIM channel used for Process (MCS) */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTim0CrkToMcsCfg(void)
{

   CRKHAL_Tim0CrkToMcs->IRQ_MODE.U = (uint32)IfxGtm_IrqMode_PulseNotifyMode;
   /* TIM Ctrl Settings */
   CRKHAL_Tim0CrkToMcs->CTRL.U = CRANK_TIM_PROCESS_CTRL_Cfg;
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTimFilterConfig                                   */
/* !Description : This function configures TIM Channel Filter Rising Edge (RE)*/
/*                & Falling Edge (FE) Filters                                 */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimFilterConfig(Ifx_GTM_TIM_CH* Ifx_GtmTimCh,
                               uint32 u32ValueRe,
                               uint32 u32ValueFe)
{
   Ifx_GtmTimCh->FLT_RE.U = u32ValueRe; /* Acceptance time for rising edge */
   Ifx_GtmTimCh->FLT_FE.U = u32ValueFe; /* Acceptance time for falling edge */
   IFX_GTM_SET_BIT(Ifx_GtmTimCh->CTRL.U, IFX_GTM_TIM_CH_CTRL_FLT_EN_OFF);
   /* Ifx_GtmTimCh->CTRL.B.FLT_EN = 1U; */
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTimCfg                                            */
/* !Description : This function initializes TIM Channels used for Capture(DPLL)*/
/*                & Process (MCS) by calling functions:                       */
/*                IfxGtm_vidTimCaptureCfg();                                  */
/*                IfxGtm_vidTim0CrkToMcsCfg();                                */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimCfg(void)
{
   IfxGtm_vidTimCaptureCfg();

   /* TimCaptureNoise configured from earlier */

   IfxGtm_vidTim0CrkToMcsCfg();

/* IfxGtm_vidTimFilterConfig(CRKHAL_Tim0CrkToMcs, CRANK_TIM_PROCESS_FltRE_Cfg,
         CRANK_TIM_PROCESS_FltFE_Cfg);
*/
}

/******************************************************************************/
/* !FuncName    : IfxGtm_vidTimNoiseConfig                                    */
/* !Description : This function configures Noise Canceler by configuring TIM  */
/*                Filters (RE & FE) of TIM Channels Capture (DPLL) & Process(MCS)*/
/* Formula for Calculating T = (FLT_xE+1)*TFLT_CLK, whereas TFLT_CLK is the   */
/* clock period of the selected CMU clock signal in bit field                 */
/* FLT_CNT_FRQ of register TIMi_CHx_CTRL.                                     */
/*                                                                            */
/******************************************************************************/
void IfxGtm_vidTimNoiseConfig(uint32 u32Value)
{
   IfxGtm_vidTimFilterConfig(CRKHAL_Tim0CrkToDpll, u32Value, u32Value);
   IfxGtm_vidTimFilterConfig(CRKHAL_Tim0CrkToMcs, u32Value, u32Value);
}

#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

/*------------------------------ end of file ---------------------------------*/

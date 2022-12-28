/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : CAMHAL GTM interface functions                          */
/*                                                                            */
/* !File            : CAMHAL_gtm_cfg.c                                        */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;
 * <Revision>
 * %PID: P2017_BSW:0A192502.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "CAMHAL.h"
#include "CAMHAL_API.h"
#include "CAMHAL_Cfg.h"
#include "CAMHAL_Cfg_I.h"
#include "CAMHAL_gtm_cfg.h"
#include "IfxGtm_CcuApi.h"
#include "SWFAIL.h"


#define CAMHAL_START_SEC_CODE
#include "CAMHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : CAMHAL_vidGtmInit                                           */
/* !Description : Initializes the TIM channels used for CAMHAL                */
/*                                                                            */
/******************************************************************************/
void CAMHAL_vidGtmInit(void)
{
   CAMHAL_IntakeTim = (Ifx_GTM_TIM_CH *)(IFX_GTM_BASE + TIM_GLB_OFFSET
                                         + (TIM_OFFSET * CAMHAL_snGET_TIM_FROM_CFG(INTAKE))
                                         + (TIMxCHxOFFSET * CAMHAL_snGET_TIM_Channel_FROM_CFG(INTAKE)));

   CAMHAL_ExhaustTim = (Ifx_GTM_TIM_CH *)(IFX_GTM_BASE + TIM_GLB_OFFSET
                                          + (TIM_OFFSET * CAMHAL_snGET_TIM_FROM_CFG(EXHAUST))
                                          + (TIMxCHxOFFSET * CAMHAL_snGET_TIM_Channel_FROM_CFG(EXHAUST)));

}

/******************************************************************************/
/* !FuncName    : CAMHAL_u32EdgeTimeRead                                      */
/* !Description : Reads the Captured Time when the edge happens               */
/*                                                                            */
/******************************************************************************/
uint32 CAMHAL_u32EdgeTimeRead(CAMHAL_tudtChannel udtChannelName )
{
   uint32 u32LocalEdgeTime ;

   switch(udtChannelName)
   {
      case CAMHAL_udtCH_CM_81:
         u32LocalEdgeTime = IFX_GTM_READ_REG_BITFIELD(CAMHAL_IntakeTim->GPR0.U,
         Ifx_GTM_TIM_CH_GPR0_RD_MASK_GPR0);
         break;

      case CAMHAL_udtCH_CM_72:
         u32LocalEdgeTime = IFX_GTM_READ_REG_BITFIELD(CAMHAL_ExhaustTim->GPR0.U,
         Ifx_GTM_TIM_CH_GPR0_RD_MASK_GPR0);
         break;

      default:
         u32LocalEdgeTime = UINT32_MIN;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   return(u32LocalEdgeTime);
}

#define CAMHAL_STOP_SEC_CODE
#include "CAMHAL_MemMap.h"

/*-------------------------------- end of file -------------------------------*/



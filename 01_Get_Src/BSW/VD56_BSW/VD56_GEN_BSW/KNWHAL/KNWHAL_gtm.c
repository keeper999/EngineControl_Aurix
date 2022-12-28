/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : KNWHAL                                                  */
/* !Description     : Knock Window Layer                                      */
/*                                                                            */
/* !File            : KNKHAL_gtm_cfg.c                                        */
/* !Description     : GTM configuration for KNWHAL                            */
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
 * %PID: P2017_BSW:0A170693.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#include "KNWHAL_Cfg.h"
#include "KNWHAL_gtm.h"
#include "CAMHAL_CFG_I.h"
#include "IfxGtm_Ccu.h"

/*lint -esym(960,17.4) */
/*lint -esym(960,11.5) */
/*lint -save -e927 */
/*lint -save -e928 */
/*lint -save -e929 */

#define KNWHAL_START_SEC_CODE
#include "KNWHAL_MemMap.h"


static const volatile Ifx_GTM_ATOM_CH *KNWHAL_pstrKNW_SAMPLING_WIN =
{
   (Ifx_GTM_ATOM_CH *)(IFX_GTM_BASE + ATOM_BASE_OFFSET
                       + (ATOM_OFFSET * KNWHAL_snGET_ATOM_FROM_CFG(KNW_SAMPLING_WIN) )
                       + (ATOM_CH_OFFSET * KNWHAL_snGET_ATOM_Channel_FROM_CFG(KNW_SAMPLING_WIN) ) )
};

static const volatile Ifx_GTM_ATOM_AGC *KNWHAL_pstrAgcKNW_SAMPLING_WIN =
{
   (Ifx_GTM_ATOM_AGC *)(IFX_GTM_BASE + ATOM_BASE_OFFSET
                        + (ATOM_OFFSET * KNWHAL_snGET_ATOM_FROM_CFG(KNW_SAMPLING_WIN) )
                        + (ATOM_AGC_OFFSET) )
};
void KNWHAL_GtmEnable(void)
{
   IfxGtm_vidAtomEnableChannel( (volatile Ifx_GTM_ATOM_CH *)KNWHAL_pstrKNW_SAMPLING_WIN,
                                (volatile Ifx_GTM_ATOM_AGC *)KNWHAL_pstrAgcKNW_SAMPLING_WIN,
                                KNWHAL_snGET_ATOM_Channel_FROM_CFG(KNW_SAMPLING_WIN),
                                IfxGtm_Atom_Level_Low
                              );
}

void KNWHAL_GtmDisable(void)
{
   IfxGtm_vidAtomDisableChannel( (volatile Ifx_GTM_ATOM_CH *)KNWHAL_pstrKNW_SAMPLING_WIN,
                                 (volatile Ifx_GTM_ATOM_AGC *)KNWHAL_pstrAgcKNW_SAMPLING_WIN,
                                 KNWHAL_snGET_ATOM_Channel_FROM_CFG(KNW_SAMPLING_WIN),
                                 IfxGtm_Atom_Level_High
                               );
}

/*lint -restore */
#define KNWHAL_STOP_SEC_CODE
#include "KNWHAL_MemMap.h"
/*------------------------------- end of file --------------------------------*/

/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : GTM_CCU                                                 */
/* !Description     : GTM_CCU Component                                       */
/*                                                                            */
/* !File            : IfxGtm_CcuApi.h                                         */
/* !Description     : Definition of GTM CCU APIs                              */
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
 * %PID: P2017_BSW:A18522.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#ifndef IFXGTM_CCUAPI_H_
#define IFXGTM_CCUAPI_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "IfxGtm_Typ.h"
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

void IfxGtm_vidInitTimCh(void);

void IfxGtm_vidTim0CrkToDpllCfg(void);

void IfxGtm_vidTim0CrkToMcsCfg(void);

void IfxGtm_vidTimFilterConfig(Ifx_GTM_TIM_CH* Ifx_GtmTimCh, \
                               uint32 u32ValueRe, \
                               uint32 u32ValueFe);

void IfxGtm_vidTimCfg(void);

void IfxGtm_vidTimNoiseConfig(uint32 u32Value);

#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

#endif /* IFXGTM_CCUAPI_H_ */

/*------------------------------ end of file ---------------------------------*/

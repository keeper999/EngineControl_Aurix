/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : KNWHAL                                                  */
/* !Description     : Knock Window Layer                                      */
/*                                                                            */
/* !File            : KNKHAL_gtm_cfg.h                                        */
/* !Description     : GTM configuration for KNWHAL declarations               */
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
 * %PID: P2017_BSW:0A170689.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef KNWHAL_GTM_CFG_H_
#define KNWHAL_GTM_CFG_H_

/*lint -esym(960,19.12) */
#define KNWHAL_snGET_ATOM_Channel_FROM_CFG(snCoilName) \
   (CRKHAL_sn ## snCoilName ## _CHANNEL)

#define KNWHAL_snGET_ATOM_FROM_CFG(snAlarmName) \
   (CRKHAL_sn ## snAlarmName ## _ATOM)

#define KNWHAL_START_SEC_CODE
#include "KNWHAL_MemMap.h"

void KNWHAL_GtmEnable(void);
void KNWHAL_GtmDisable(void);

#define KNWHAL_STOP_SEC_CODE
#include "KNWHAL_MemMap.h"

#endif /* KNWHAL_GTM_CFG_H_ */
/*---------------------------------------------------- end of file ---------------------------------------------------*/

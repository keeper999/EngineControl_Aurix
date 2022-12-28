/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : CAMHAL GTM interface functions                          */
/*                                                                            */
/* !File            : CAMHAL_gtm_cfg.h                                        */
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
 * %PID: P2017_BSW:0A192390.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef CAMHAL_GTM_CFG_H
#define CAMHAL_GTM_CFG_H

#include "Std_Types.h"
#include "CAMHAL_L.h"
#include "IfxGtm_Def.h"


#define CAMHAL_START_SEC_CODE
#include "CAMHAL_MemMap.h"

void CAMHAL_vidGtmInit(void);
uint32 CAMHAL_u32EdgeTimeRead(CAMHAL_tudtChannel udtChannelName);

#define CAMHAL_STOP_SEC_CODE
#include "CAMHAL_MemMap.h"


#endif /* CAMHAL_GTM_CFG_H */

/*------------------------------ end of file ---------------------------------*/

/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PMPHAL                                                                                          */
/* !Description     : Pump Hardware Abstraction Layer                                                                 */
/*                                                                                                                    */
/* !File            : PMPHAL_GTM_CFG.h                                                                                */
/* !Description     : Configuration of the PMPHAL Component                                                           */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/

#ifndef PMPHAL_GTM_CFG_H_
#define PMPHAL_GTM_CFG_H_

#include "CRKHAL_Cfg.h"
#include "IfxGtm_Def.h"
#include "IfxGtm_Typ.h"
#include "IfxPort_reg.h"

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
#define PMPHAL_SPILL_CMD_TOUT          (70u)

#define PMPHAL_SPILL_CMD_PORT          (&MODULE_P20)

#define PMPHAL_SPILL_CMD_PIN           (14u)
#define PMPHAL_SPILL_CMD_GTM_TIMER     (2u)


/* Derived internal parameters */
#define PMPHAL_SPILL_CMD_TOUT_REG      (PMPHAL_SPILL_CMD_TOUT / 16u)
#define PMPHAL_SPILL_CMD_TOUT_SEL      (PMPHAL_SPILL_CMD_TOUT - (PMPHAL_SPILL_CMD_TOUT_REG * 16u))

#define PMPHAL_snSPILL_CMD_ATOM        CRKHAL_snM_CMD_GDI_PMP_ANGLE_ATOM
#define PMPHAL_snSPILL_CMD_ATOM_CH     CRKHAL_snM_CMD_GDI_PMP_ANGLE_CHANNEL

/**********************************************************************************************************************/
/* VARIABLES                                                                                                          */
/**********************************************************************************************************************/
#define PMPHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "PMPHAL_MemMap.h"

extern volatile Ifx_GTM_ATOM_CH*       PMPHAL_pstrSPILL_CMD_CH;
extern volatile Ifx_GTM_ATOM_AGC*      PMPHAL_pstrAgcSPILL_CMD_CH;

#define PMPHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "PMPHAL_MemMap.h"

/**********************************************************************************************************************/
/* FUNCTIONS                                                                                                          */
/**********************************************************************************************************************/
#define PMPHAL_START_SEC_CODE
#include "PMPHAL_MemMap.h"

extern void PMPHAL_vidGtmInit(void);
extern void PMPHAL_vidGtmEnable(void);
extern void PMPHAL_vidGtmDisable(void);

#define PMPHAL_STOP_SEC_CODE
#include "PMPHAL_MemMap.h"

#endif /* PMPHAL_GTM_CFG_H_ */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

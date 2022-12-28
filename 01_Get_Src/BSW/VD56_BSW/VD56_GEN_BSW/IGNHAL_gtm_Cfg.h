/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_gtm_Cfg.h                                        */
/* !Description     : IGNHAL configuration                                    */
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
 * %PID: P2017_BSW:0A192497.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IGNHAL_GTM_CFG_H
#define IGNHAL_GTM_CFG_H

#include "IfxPort_reg.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define IGNHAL_COIL_A_TOUT       (45U)  /* TOUT45_SELC_PORT23_PIN4 */
#define IGNHAL_COIL_B_TOUT       (46U)  /* TOUT46_SELC_PORT23_PIN5 */
#define IGNHAL_COIL_C_TOUT       (40U)  /* TOUT40_SELC_PORT32_PIN4 */

#define IGNHAL_COIL_A_PORT       (&MODULE_P23)
#define IGNHAL_COIL_B_PORT       (&MODULE_P23)
#define IGNHAL_COIL_C_PORT       (&MODULE_P32)

#define IGNHAL_COIL_A_PIN        (4U)
#define IGNHAL_COIL_B_PIN        (5U)
#define IGNHAL_COIL_C_PIN        (4U)

#define IGNHAL_COIL_A_GTM_TIMER  (2U) /* TIMER C */
#define IGNHAL_COIL_B_GTM_TIMER  (2U) /* TIMER C */
#define IGNHAL_COIL_C_GTM_TIMER  (2U) /* TIMER C */


/* derived internal parameters */
#define IGNHAL_COIL_A_TOUT_REG   (IGNHAL_COIL_A_TOUT / 16U)
#define IGNHAL_COIL_B_TOUT_REG   (IGNHAL_COIL_B_TOUT / 16U)
#define IGNHAL_COIL_C_TOUT_REG   (IGNHAL_COIL_C_TOUT / 16U)

#define IGNHAL_COIL_A_TOUT_SEL   (IGNHAL_COIL_A_TOUT - (IGNHAL_COIL_A_TOUT_REG * 16U) )
#define IGNHAL_COIL_B_TOUT_SEL   (IGNHAL_COIL_B_TOUT - (IGNHAL_COIL_B_TOUT_REG * 16U) )
#define IGNHAL_COIL_C_TOUT_SEL   (IGNHAL_COIL_C_TOUT - (IGNHAL_COIL_C_TOUT_REG * 16U) )


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

extern void IGNHAL_GtmInit(void);
extern void IGNHAL_GtmEnable(void);
extern void IGNHAL_GtmDisable(void);

#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"


#endif /* IGNHAL_GTM_CFG_H */

/*------------------------------ end of file ---------------------------------*/

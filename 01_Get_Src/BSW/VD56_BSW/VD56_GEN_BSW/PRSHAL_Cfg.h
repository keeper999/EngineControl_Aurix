/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PRSHAL                                                  */
/* !Description     : PRSHAL Component                                        */
/*                                                                            */
/* !File            : PRSHAL_Cfg.h                                            */
/* !Description     : Configuration of PRSHAL Component                       */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192470.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef PRSHAL_CFG_H
#define PRSHAL_CFG_H

#include "ADCHAL.h"
#include "CRKHAL.h"
#include "TDCHAL.h"
#include "TSKSRV.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* !MComment: CRKHAL channel for PRSHAL component                             */
#define PRSHAL_u8CRKHAL_CHANNEL   CRKHAL_u8ALARM_IT_1_4_TDC

/* !MComment: Offset for PRSHAL event                                         */
#define PRSHAL_u16OFFSET          (TDCHAL_u16TDC_OFFSET / 4)

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/* !MComment: Function called for updating air pressure from ADC              */
#define PRSHAL_vidUPDATE_PRESSURE_HOOK() \
do \
{ \
   ADCHAL_vidEntry_1_4_TDC_EVENT(); \
} \
while (0)

/* !MComment: Function called for task activation                             */
#define PRSHAL_vidACTIVATE_TASK() \
   TSKSRV_vidActivateTask(OSTSK_S_1_4_TDC)

#endif /* PRSHAL_CFG_H */

/*-------------------------------- end of file -------------------------------*/

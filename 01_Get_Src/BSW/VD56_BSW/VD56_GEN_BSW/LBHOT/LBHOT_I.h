/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : LBHOT                                                   */
/* !Description     : Oxygen (Lambda) Sensor Heating management               */
/*                                                                            */
/* !File            : LBHOT_I.h                                               */
/* !Description     : LBHOT's Private Header                                  */
/*                                                                            */
/* !Reference       : V03 NT 06 03885                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A36799.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef LBHOT_I_H
#define LBHOT_I_H

#include "Std_Types.h"
#include "Pwm.h"


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define LBHOT_START_SEC_VAR_CLEARED_16BIT
#include "LBHOT_MemMap.h"

extern uint16 LBHOT_u16DutyCycle;

#define LBHOT_STOP_SEC_VAR_CLEARED_16BIT
#include "LBHOT_MemMap.h"

#define LBHOT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "LBHOT_MemMap.h"

extern Pwm_PeriodType LBHOT_udtPeriod;

#define LBHOT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "LBHOT_MemMap.h"

#endif /* LBHOT_I_H */

/*------------------------------- end of file --------------------------------*/

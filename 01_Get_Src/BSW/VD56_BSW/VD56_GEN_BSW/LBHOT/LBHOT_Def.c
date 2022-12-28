/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : LBHOT                                                   */
/* !Description     : Oxygen (Lambda) Sensor Heating management               */
/*                                                                            */
/* !File            : LBHOT_Def.c                                             */
/* !Description     : LBHOT's Data Definition                                 */
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
 * %PID: P2017_BSW:A36800.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Pwm.h"
#include "LBHOT.h"
#include "LBHOT_I.h"


/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/

#define LBHOT_START_SEC_CALIB_BOOLEAN
#include "LBHOT_MemMap.h"

const boolean LBHOT_kbEnableLbupHotPwmMode = 0;

#define LBHOT_STOP_SEC_CALIB_BOOLEAN
#include "LBHOT_MemMap.h"


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define LBHOT_START_SEC_VAR_CLEARED_BOOLEAN
#include "LBHOT_MemMap.h"

boolean  LBHOT_bLbdwHotAppliCmd;
boolean  LBHOT_bLbupHotAppliCmd;

#define LBHOT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "LBHOT_MemMap.h"

#define LBHOT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "LBHOT_MemMap.h"

Pwm_PeriodType LBHOT_udtPeriod;

#define LBHOT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "LBHOT_MemMap.h"

#define LBHOT_START_SEC_VAR_CLEARED_16BIT
#include "LBHOT_MemMap.h"

uint16 LBHOT_u16DutyCycle;

#define LBHOT_STOP_SEC_VAR_CLEARED_16BIT
#include "LBHOT_MemMap.h"

/*------------------------------- end of file --------------------------------*/

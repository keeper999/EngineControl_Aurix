/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TDCHAL                                                  */
/* !Description     : TDCHAL Component                                        */
/*                                                                            */
/* !File            : TDCHAL_Def.c                                            */
/* !Description     : Data definitions used in setpoint mechanism             */
/*                                                                            */
/* !Reference       : PTS DOC 5038320                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A269.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "TDCHAL_Cfg.h"
#include "TDCHAL_L.h"

#ifndef TDCHAL_coBDC_ENABLED
   #error "TDCHAL_coBDC should be defined"
#endif

#ifndef TDCHAL_coBDC_CALC_PER_ON_ENABLED
   #error "TDCHAL_coBDC_CALC_PER_ON_ENABLED should be defined"
#endif

#ifndef TRUE
   #error "TRUE should be defined"
#endif

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define TDCHAL_START_SEC_CALIB_8BIT
#include "TDCHAL_MemMap.h"

/* !MComment: TDC counter at each setpoint.                                   */
const uint8 TDCHAL_kau8TDCCounter[TDCHAL_u8MAX_NB_SETPOINTS] =
{
   0
};

/* !MComment: Array of indices to choose which action to take on SetPoint.    */
const uint8 TDCHAL_kau8OnSetPointIdx[TDCHAL_u8MAX_NB_SETPOINTS] =
{
   0
};

#define TDCHAL_STOP_SEC_CALIB_8BIT
#include "TDCHAL_MemMap.h"

#define TDCHAL_START_SEC_CALIB_16BIT
#include "TDCHAL_MemMap.h"

/* !MComment: Setpoints angles                                                */
const uint16 TDCHAL_kau16SetPointAngles[TDCHAL_u8MAX_NB_SETPOINTS] =
{
   0
};

#define TDCHAL_STOP_SEC_CALIB_16BIT
#include "TDCHAL_MemMap.h"


/*------------------------------ end of file ---------------------------------*/

/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TDCHAL                                                  */
/* !Description     : Configuration of the TDCHAL component                   */
/*                                                                            */
/* !File            : TDCHAL_Cfg.c                                            */
/* !Description     : Configuration of the TDCHAL component                   */
/*                                                                            */
/* !Reference       : V03 NT 09 06361                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192443.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "TDCHAL_Cfg.h"
#include "TDCHAL_L.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define TDCHAL_START_SEC_CONST_UNSPECIFIED
#include "TDCHAL_MemMap.h"

/* !MComment: Array of pointer to functions of all defined OnSetPoint.        */
void (* const TDCHAL_kapfvidOnSetPoint[TDCHAL_u8NB_ACTIONS_ON_SETPOINT])(void)=
{
   &TDCHAL_vidOnTDC,
   &TDCHAL_vidOnBDC
};

#define TDCHAL_STOP_SEC_CONST_UNSPECIFIED
#include "TDCHAL_MemMap.h"

/*------------------------------ end of file ---------------------------------*/

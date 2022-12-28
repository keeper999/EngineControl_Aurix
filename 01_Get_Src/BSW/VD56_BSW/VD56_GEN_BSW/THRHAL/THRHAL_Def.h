/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : THRHAL                                                  */
/* !Description     : THRHAL Component                                        */
/*                                                                            */
/* !File            : THRHAL_Def.h                                            */
/* !Description     : Declaration of data of THRHAL Component                 */
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
 * %PID: P2017_BSW:0A111491.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef THRHAL_DEF_H
#define THRHAL_DEF_H

#include "Std_Types.h"

#define THRHAL_START_SEC_VAR_CLEARED_8BIT
#include "THRHAL_MemMap.h"

extern uint8 THRHAL_u8Counter;

#define THRHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "THRHAL_MemMap.h"

#endif /* THRHAL_DEF_H */

/*-------------------------------- end of file -------------------------------*/

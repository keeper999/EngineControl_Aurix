/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : THRHAL                                                  */
/* !Description     : THRHAL Component                                        */
/*                                                                            */
/* !File            : THRHAL_Def.c                                            */
/* !Description     : Definition of data of THRHAL Component                  */
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
 * %PID: P2017_BSW:0A111557.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "THRHAL_Def.h"
#include "THRHAL.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define THRHAL_START_SEC_VAR_CLEARED_8BIT
#include "THRHAL_MemMap.h"

uint8 THRHAL_u8Counter;

#define THRHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "THRHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/


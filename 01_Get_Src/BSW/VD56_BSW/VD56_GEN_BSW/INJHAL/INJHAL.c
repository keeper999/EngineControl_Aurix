/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : INJHAL Component                                        */
/*                                                                            */
/* !File            : INJHAL.c                                                */
/* !Description     : Data Definition of INJHAL Component                     */
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
 * %PID: P2017_BSW:A26577.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"

/******************************************************************************/
/* VARIABLES                                                                  */
/******************************************************************************/

#define INJHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "INJHAL_MemMap.h"

boolean INJHAL_bTestMode;

#define INJHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "INJHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/

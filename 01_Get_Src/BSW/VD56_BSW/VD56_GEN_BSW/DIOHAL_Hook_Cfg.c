/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : DIOHAL                                                  */
/* !Description     : DIOHAL Component                                        */
/*                                                                            */
/* !File            : DIOHAL_Hook_Cfg.c                                       */
/* !Description     : Config of the CLUTCH_PED_POS_OR_STARTLOCK Pin           */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * %The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192425.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

#define GEN_BSW_START_SEC_CALIB_BOOLEAN
#include "GEN_BSW_MemMap.h"

const boolean DIOHAL_kbClutchPedPosPullToUbat = 0u;

#define GEN_BSW_STOP_SEC_CALIB_BOOLEAN
#include "GEN_BSW_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

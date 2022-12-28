/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : DIOHAL                                                  */
/* !Description     : DIOHAL Component                                        */
/*                                                                            */
/* !File            : DIOHAL_Hook_Cfg.h                                       */
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
 * %PID: P2017_BSW:0A192494.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#ifndef DIOHAL_HOOK_CFG_H
#define DIOHAL_HOOK_CFG_H

#include "Std_Types.h"
#include "Dio.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

#define GEN_BSW_START_SEC_CALIB_BOOLEAN
#include "GEN_BSW_MemMap.h"

extern const boolean DIOHAL_kbClutchPedPosPullToUbat;

#define GEN_BSW_STOP_SEC_CALIB_BOOLEAN
#include "GEN_BSW_MemMap.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/******************************************************************************/
/* !FuncName    : DIOHAL_vidInitHook                                          */
/* !Description : This macro configures the pull up resistor voltage source   */
/*                associated with the pin CLUTCH_PED_POS_OR_STARTLOCK         */
/*                whether VCC_5V or UBATCF                                    */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define DIOHAL_vidInitHook() \
do \
{ \
   if (DIOHAL_kbClutchPedPosPullToUbat != FALSE) \
   { \
      Dio_WriteChannel(DioConf_DioChannel_M_PULL_UP_VBAT, STD_ON); \
      Dio_WriteChannel(DioConf_DioChannel_M_PULL_UP_VCC, STD_OFF); \
   } \
   else \
   { \
      Dio_WriteChannel(DioConf_DioChannel_M_PULL_UP_VBAT, STD_OFF); \
      Dio_WriteChannel(DioConf_DioChannel_M_PULL_UP_VCC, STD_ON); \
   } \
} \
while (0)

#endif /* DIOHAL_HOOK_CFG_H */

/*-------------------------------- end of file -------------------------------*/

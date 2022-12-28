/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : INJHAL Component                                        */
/*                                                                            */
/* !File            : INJHAL_L.h                                              */
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
 * %PID: P2017_BSW:A26583.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef INJHAL_L_H
#define INJHAL_L_H

#include "Std_Types.h"
#include "INJHAL_TYP.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define INJHAL_bPRE_INJ_AUTHORIZED        1u
#define INJHAL_bPRE_INJ_UNAUTHORIZED      0u
#define INJHAL_u16_1_DEG_FOR_PRE_INJ      64u    /* 1 * INJHAL_u16COMMON_ANGLE_RESOL   */
#define INJHAL_u16_715_DEGREES            45760u /* 715 * INJHAL_u16COMMON_ANGLE_RESOL */
#define INJHAL_u16COMMON_ANGLE_RESOL      64u    /* CRKHAL_u16COMMON_ANGLE_RESOL       */
#define INJHAL_u16ENGINE_CYCLE            46080u /* 720 * INJHAL_u16COMMON_ANGLE_RESOL */
#define INJHAL_u8BF_UPDT_ANGLE_SHIFT      8u
#define INJHAL_udtBEFORE_END_OF_CYCLE     INJHAL_u8NB_INJ_PULSES
#define INJHAL_udtINVALID_PULSE           255u


/******************************************************************************/
/* VARIABLES                                                                  */
/******************************************************************************/
#define INJHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "INJHAL_MemMap.h"

extern boolean INJHAL_bTestMode;

#define INJHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "INJHAL_MemMap.h"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define INJHAL_START_SEC_CODE
#include "INJHAL_MemMap.h"

void INJHAL_vidFGPreinjManagement(uint8 u8InstanceId);
void INJHAL_vidUpdateAngleReference(uint16* pu16Angle);

#define INJHAL_STOP_SEC_CODE
#include "INJHAL_MemMap.h"

#endif /* INJHAL_L_H */

/*-------------------------------- end of file -------------------------------*/

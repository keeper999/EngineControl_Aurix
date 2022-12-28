/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PWDHAL                                                                                          */
/* !Description     : Pulse width demodulation                                                                        */
/*                                                                                                                    */
/* !File            : PWDHAL_Private.h                                                                                */
/* !Description     : Data definitions                                                                                */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5611943                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A3497.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef PWDHAL_PRIVATE_H
#define PWDHAL_PRIVATE_H

#include "Std_Types.h"
#include "PWDHAL_Types.h"
#include "Dio.h"

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

#define PWDHAL_START_SEC_CONST_BOOLEAN
#include "PWDHAL_MemMap.h"

/* Desired period to return when timout occurs is it the Max or last measured */
extern CONST(boolean,PWDHAL_CONST) PWDHAL_akbFreezePeriodOnTimeout[PWDHAL_u8NUMBER_OF_CHANNELS];

#define PWDHAL_STOP_SEC_CONST_BOOLEAN
#include "PWDHAL_MemMap.h"

#define PWDHAL_START_SEC_CONST_8BIT
#include "PWDHAL_MemMap.h"

/* Active Level of every pwdhal channel                                       */
extern CONST(Dio_LevelType,PWDHAL_CONST) PWDHAL_aku8ChannelActiveLevel[PWDHAL_u8NUMBER_OF_CHANNELS];

#define PWDHAL_STOP_SEC_CONST_8BIT
#include "PWDHAL_MemMap.h"

#define PWDHAL_START_SEC_CONST_32BIT
#include "PWDHAL_MemMap.h"

/* Timout paramter resolution in ns                                           */
extern CONST(uint32,PWDHAL_CONST) PWDHAL_aku32TimeoutParamResNs[PWDHAL_u8NUMBER_OF_CHANNELS];

/* Sampling rate parameter in ns                                              */
extern CONST(uint32,PWDHAL_CONST) PWDHAL_aku32SamplingRateNs[PWDHAL_u8NUMBER_OF_CHANNELS];


#define PWDHAL_STOP_SEC_CONST_32BIT
#include "PWDHAL_MemMap.h"

#define PWDHAL_START_SEC_CONST_UNSPECIFIED
#include "PWDHAL_MemMap.h"


/* !Comment: Array of constants for the desired period MAX  per channel.      */
extern CONST(PWDHAL_tudtPeriod,PWDHAL_CONST) PWDHAL_akudtPeriodDesiredMax[PWDHAL_u8NUMBER_OF_CHANNELS];

#if (PWDHAL_coSAME_DUTY_CYCLE_MAX != PWDHAL_coTRUE)
extern CONST(PWDHAL_tudtDutyCycle,PWDHAL_CONST) PWDHAL_akudtDutyCycleDesiredMax[PWDHAL_u8NUMBER_OF_CHANNELS];
#endif /* (PWDHAL_coSAME_DUTY_CYCLE_MAX == PWDHAL_coTRUE) */

/* !Comment: Array of Dio channel.      */
extern CONST(Dio_ChannelType,PWDHAL_CONST) PWDHAL_akudtDioChannel[PWDHAL_u8NUMBER_OF_CHANNELS];
/* !Comment: Array of Icu channel.      */
extern CONST(Icu_ChannelType,PWDHAL_CONST) PWDHAL_akudtIcuChannel[PWDHAL_u8NUMBER_OF_CHANNELS];

#define PWDHAL_STOP_SEC_CONST_UNSPECIFIED
#include "PWDHAL_MemMap.h"


#endif /* PWDHAL_PRIVATE_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/

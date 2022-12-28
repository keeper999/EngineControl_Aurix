/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : PWDHAL                                                                                          */
/* !Description     : Pulse width demodulation                                                                        */
/*                                                                                                                    */
/* !File            : PWDHAL_Types.h                                                                                  */
/* !Description     : Types definitions                                                                               */
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
 * %PID: LIBEMB:A3481.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef PWDHAL_TYPES_H
#define PWDHAL_TYPES_H

#include "Std_Types.h"
#include "PWDHAL_Co.h"
#include "Dio.h"

#if (PWDHAL_coDUTY_CYCLE_RETURN_TYPE == PWDHAL_co_uint32)
typedef uint32 PWDHAL_tudtDutyCycle;
#elif (PWDHAL_coDUTY_CYCLE_RETURN_TYPE == PWDHAL_co_uint16)
typedef uint16 PWDHAL_tudtDutyCycle;
#else /* (PWDHAL_coDUTY_CYCLE_RETURN_TYPE == PWDHAL_co_uint32) */
typedef uint8 PWDHAL_tudtDutyCycle;
#endif /* (PWDHAL_coDUTY_CYCLE_RETURN_TYPE == PWDHAL_co_uint32) */

#if (PWDHAL_coTIMEOUT_PARAM_TYPE == PWDHAL_co_uint32)
typedef uint32 PWDHAL_tudtTimeoutType;
#elif (PWDHAL_coTIMEOUT_PARAM_TYPE == PWDHAL_co_uint16)
typedef uint16 PWDHAL_tudtTimeoutType;
#else /* (PWDHAL_coTIMEOUT_PARAM_TYPE == PWDHAL_co_uint32) */
typedef uint8 PWDHAL_tudtTimeoutType;
#endif /* (PWDHAL_coTIMEOUT_PARAM_TYPE == PWDHAL_co_uint32) */

#if (PWDHAL_coPERIOD_RETURN_TYPE == PWDHAL_co_uint32)
typedef uint32 PWDHAL_tudtPeriod;
#elif (PWDHAL_coPERIOD_RETURN_TYPE == PWDHAL_co_uint16)
typedef uint16 PWDHAL_tudtPeriod;
#else /* (PWDHAL_coPERIOD_RETURN_TYPE == PWDHAL_co_uint32) */
typedef uint8 PWDHAL_tudtPeriod;
#endif /* (PWDHAL_coPERIOD_RETURN_TYPE == PWDHAL_co_uint32) */

typedef struct {
   PWDHAL_tudtTimeoutType  udtTimeoutCounter;
   PWDHAL_tudtTimeoutType  udtTimeoutReloadValue;
   PWDHAL_tudtPeriod       udtPeriod;
   PWDHAL_tudtDutyCycle    udtDutyCycle;
   Dio_LevelType           bCurrentLevelIsActive;
   boolean                 bEnable;
   boolean                 bFirstPeriodOccured;
} PWDHAL_tstrData;


#endif /* PWDHAL_TYPES_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/

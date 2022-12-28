/**********************************************************************************************************************/
/* !Layer           : SRVL                                                                                            */
/* !Component       : RTMCLD2                                                                                          */
/* !Description     : Real time measurement of CPU load                                                               */
/*                                                                                                                    */
/* !File            : RTMCLD2_DEF.h                                                                                    */
/* !Description     : Real time measurement of CPU load                                                               */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5385380                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A96785.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef RTMCLD2_DEF_H
#define RTMCLD2_DEF_H


#include "STD_TYPES.h"
#include "RTMCLD2_CFG.h"
#include "RTMCLD2_Co.h"

#ifndef RTMCLD2_coENABLE
   #error the macro-constant RTMCLD2_coENABLE shall be defined
#endif

#ifndef RTMCLD2_coLOOP_MEASURE
   #error the macro-constant RTMCLD2_coENABLE shall be defined
#endif


#if (RTMCLD2_coLOOP_MEASURE == RTMCLD2_coENABLE)

   #define RTMCLD2_START_SEC_VAR_NOINIT_8BIT
   #include "RTMCLD2_MemMap.h"
extern uint8 RTMCLD2_u8TestDone;
   #define RTMCLD2_STOP_SEC_VAR_NOINIT_8BIT
   #include "RTMCLD2_MemMap.h"

   #define RTMCLD2_START_SEC_VAR_NOINIT_32BIT
   #include "RTMCLD2_MemMap.h"
extern uint32 RTMCLD2_u32MeasuredValue;
   #define RTMCLD2_STOP_SEC_VAR_NOINIT_32BIT
   #include "RTMCLD2_MemMap.h"

#endif /* RTMCLD2_coLOOP_MEASURE == RTMCLD2_coENABLE */


#define RTMCLD2_START_SEC_VAR_NOINIT_32BIT
#include "RTMCLD2_MemMap.h"
extern uint32 RTMCLD2_u32IdleClock;
#define RTMCLD2_STOP_SEC_VAR_NOINIT_32BIT
#include "RTMCLD2_MemMap.h"

#define RTMCLD2_START_SEC_VAR_32BIT
#include "RTMCLD2_MemMap.h"
extern uint32 RTMCLD2_u32Load;
extern uint32 RTMCLD2_u32PrevIdleClock;

#if (RTMCLD2_coCONFIGURATION_TYPE != RTMCLD2_coPREBUILD)
extern uint32 RTMCLD2_u32MeasurementPeriodMs;
#endif
#define RTMCLD2_STOP_SEC_VAR_32BIT
#include "RTMCLD2_MemMap.h"

#define RTMCLD2_START_SEC_VAR_16BIT
#include "RTMCLD2_MemMap.h"
extern uint16  RTMCLD2_u16MeasurementPeriodCounter;
#define RTMCLD2_STOP_SEC_VAR_16BIT
#include "RTMCLD2_MemMap.h"


#endif /* RTMCLD2_DEF_H */

/*------------------------------------------------------- end of file ------------------------------------------------*/

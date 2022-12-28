/**********************************************************************************************************************/
/* !Layer           : SRVL                                                                                            */
/* !Component       : RTMCLD                                                                                          */
/* !Description     : Real time measurement of CPU load                                                               */
/*                                                                                                                    */
/* !File            : RTMCLD_DEF.c                                                                                    */
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
 * %PID: LIBEMB:A1062.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/


#include "Std_Types.h"
#include "RTMCLD_CFG.h"
#include "RTMCLD_Co.h"
#include "RTMCLD_Def.h"

#ifndef RTMCLD_coENABLE
   #error the macro-constant RTMCLD_coENABLE shall be defined
#endif

#ifndef RTMCLD_coLOOP_MEASURE
   #error the macro-constant RTMCLD_coENABLE shall be defined
#endif

/**********************************************************************************************************************/
/* DATA DEFINITION                                                                                                    */
/**********************************************************************************************************************/

#if (RTMCLD_coLOOP_MEASURE == RTMCLD_coENABLE)

   #define RTMCLD_START_SEC_VAR_NOINIT_8BIT
   #include "RTMCLD_MemMap.h"
uint8 RTMCLD_u8TestDone;
   #define RTMCLD_STOP_SEC_VAR_NOINIT_8BIT
   #include "RTMCLD_MemMap.h"

   #define RTMCLD_START_SEC_VAR_NOINIT_32BIT
   #include "RTMCLD_MemMap.h"
uint32 RTMCLD_u32MeasuredValue;
   #define RTMCLD_STOP_SEC_VAR_NOINIT_32BIT
   #include "RTMCLD_MemMap.h"

#endif /* RTMCLD_coLOOP_MEASURE == RTMCLD_coENABLE */

#define RTMCLD_START_SEC_VAR_NOINIT_32BIT
#include "RTMCLD_MemMap.h"
uint32 RTMCLD_u32IdleClock;
#define RTMCLD_STOP_SEC_VAR_NOINIT_32BIT
#include "RTMCLD_MemMap.h"

#define RTMCLD_START_SEC_VAR_32BIT
#include "RTMCLD_MemMap.h"
uint32 RTMCLD_u32Load;
uint32 RTMCLD_u32PrevIdleClock;

#if (RTMCLD_coCONFIGURATION_TYPE != RTMCLD_coPREBUILD)
uint32 RTMCLD_u32MeasurementPeriodMs;
#endif
#define RTMCLD_STOP_SEC_VAR_32BIT
#include "RTMCLD_MemMap.h"

#define RTMCLD_START_SEC_VAR_16BIT
#include "RTMCLD_MemMap.h"
uint16 RTMCLD_u16MeasurementPeriodCounter;
#define RTMCLD_STOP_SEC_VAR_16BIT
#include "RTMCLD_MemMap.h"


/*------------------------------------------------------- end of file ------------------------------------------------*/

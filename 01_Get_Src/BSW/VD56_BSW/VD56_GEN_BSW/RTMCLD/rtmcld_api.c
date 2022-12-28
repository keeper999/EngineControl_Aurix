/**********************************************************************************************************************/
/* !Layer           : SRVL                                                                                            */
/* !Component       : RTMCLD                                                                                          */
/* !Description     : Real time measurement of CPU load                                                               */
/*                                                                                                                    */
/* !File            : RTMCLD_API.c                                                                                    */
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
 * %PID: LIBEMB:A1061.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "OS_API.h"

#include "RTMCLD.h"
#include "RTMCLD_EndlessLoop.h"
#include "RTMCLD_CFG.h"
#include "RTMCLD_DEF.h"
#include "RTMCLD_Co.h"
#include "SWFAIL.h"
#include "ar_mfx.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation define are defined                                                             */
/**********************************************************************************************************************/

#ifndef RTMCLD_coLOOP_MEASURE
   #error the macro-constant RTMCLD_coLOOP_MEASURE shall be defined
#endif
#ifndef RTMCLD_coENABLE
   #error the macro-constant RTMCLD_coENABLE shall be defined
#endif
#ifndef RTMCLD_coDISABLE
   #error the macro-constant RTMCLD_coDISABLE shall be defined
#endif
#ifndef RTMCLD_coCONFIGURATION_TYPE
   #error the macro-constant RTMCLD_coCONFIGURATION_TYPE shall be defined
#endif
#ifndef RTMCLD_coRUNTIME
   #error the macro-constant RTMCLD_coRUNTIME shall be defined
#endif
#ifndef RTMCLD_coPREBUILD
   #error the macro-constant RTMCLD_coPREBUILD shall be defined
#endif
#ifndef RTMCLD_coPOSTBUILD
   #error the macro-constant RTMCLD_coPOSTBUILD shall be defined
#endif


STATIC INLINE void RTMCLD_vidLoadMeasure(void);
STATIC INLINE void RTMCLD_vidReloadPeriodCounter(void);

#define RTMCLD_START_SEC_RTMCLD_ENDLESS_LOOP_CODE
#include "RTMCLD_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : TASK OSTSK_S_RTMCLD_CPU_LOAD_MNG                                                                    */
/* !Description : This task shall be used in both the verification of the loop duration and the CPU load calculations.*/
/*                                                                                                                    */
/* !Trace_To    : VEES_R_11_05504_005.01                                                                              */
/* !Trace_To    : VEES_R_11_05504_006.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  A.Nagy                                                                                             */
/**********************************************************************************************************************/
TASK(OSTSK_S_RTMCLD_CPU_LOAD_MNG)
{
   RTMCLD_u32Load          = 0;
   RTMCLD_u32IdleClock     = 0;
   RTMCLD_u32PrevIdleClock = 0;

   RTMCLD_u16MeasurementPeriodCounter = 0;

   #if (RTMCLD_coCONFIGURATION_TYPE != RTMCLD_coPREBUILD)
   RTMCLD_u32MeasurementPeriodMs = 1;      /* for safety should be different to 0... but will be recomputed before use*/
   #endif

   #if (RTMCLD_coLOOP_MEASURE == RTMCLD_coENABLE)
   if (RTMCLD_u8TestDone != 0x5A)
   {
      RTMCLD_u8TestDone = 0x5A;
      RTMCLD_vidSTART_MEASUREMENT_TIMER();
   }
   #endif /* RTMCLD_coLOOP_MEASURE == RTMCLD_coENABLE */

   RTMCLD_vidEndlessLoop();

   /* There is no termination to this task because the function               */
   /* RTMCLD_vidEndlessLoop() has a forever loop that never ends              */
}
#define RTMCLD_STOP_SEC_RTMCLD_ENDLESS_LOOP_CODE
#include "RTMCLD_MemMap.h"


#define RTMCLD_START_SEC_CODE
#include "RTMCLD_MemMap.h"
/**********************************************************************************************************************/
/* !FuncName    : RTMCLD_vidEndLoopDurationMeas                                                                       */
/* !Description : Stores the current number of 200 loops from the  RTMCLD_u32IdleClock counter                        */
/*                                                                                                                    */
/* !LastAuthor  :  A.Nagy                                                                                             */
/**********************************************************************************************************************/
void RTMCLD_vidEndLoopDurationMeas(void)
{

   #if (RTMCLD_coLOOP_MEASURE == RTMCLD_coENABLE)
   RTMCLD_u32MeasuredValue = RTMCLD_u32IdleClock;
   #endif /* RTMCLD_coLOOP_MEASURE == RTMCLD_coENABLE */
}

/**********************************************************************************************************************/
/* !FuncName    : RTMCLD_vidMainFunction                                                                              */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !LastAuthor  :  A.Nagy                                                                                             */
/**********************************************************************************************************************/
void RTMCLD_vidMainFunction(void)
{
   if (RTMCLD_u16MeasurementPeriodCounter > 0)
   {
      RTMCLD_u16MeasurementPeriodCounter--;
      if (RTMCLD_u16MeasurementPeriodCounter == 0)
      {
         RTMCLD_vidLoadMeasure();
         RTMCLD_vidReloadPeriodCounter();
      }
   }
   else
   {
      RTMCLD_vidReloadPeriodCounter();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : RTMCLD_vidLoadMeasure                                                                               */
/* !Description : Returns in RTMCLD_uint32Load the percent of Load in the measurement period                          */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_11_05504_013.01                                                                              */
/* !Trace_To    : VEES_R_11_05504_014.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  A.Nagy                                                                                             */
/**********************************************************************************************************************/

STATIC INLINE void RTMCLD_vidLoadMeasure(void)
{
   uint32 u32LocIdleClock;


   #if (RTMCLD_coCONFIGURATION_TYPE != RTMCLD_coPREBUILD)
   uint32 u32LocIdle;
   uint32 u32LocRTMLoadRaw;

   u32LocIdleClock         = RTMCLD_u32IdleClock;
   u32LocRTMLoadRaw        = u32LocIdleClock - RTMCLD_u32PrevIdleClock;
   RTMCLD_u32PrevIdleClock = u32LocIdleClock;

   if (u32LocRTMLoadRaw <= (UINT32_MAX / RTMCLD_udtENDLESS_LOOP_EXEC_TIME) )
   {
      u32LocIdle = ( (u32LocRTMLoadRaw * RTMCLD_udtENDLESS_LOOP_EXEC_TIME)
                     / RTMCLD_u32MeasurementPeriodMs);
   }
   else
   {
      u32LocIdle = Mfx_RMulDiv_u32u32u32_u32(u32LocRTMLoadRaw, (uint32)RTMCLD_udtENDLESS_LOOP_EXEC_TIME,
                                             RTMCLD_u32MeasurementPeriodMs);
   }

   if (u32LocIdle < 1000000)
   {
      RTMCLD_u32Load = (1000000 - u32LocIdle) / 100;
   }
   else
   {
      RTMCLD_u32Load = 0;
      SWFAIL_vidSoftwareErrorHook();
   }

   #else /* if (RTMCLD_coCONFIGURATION_TYPE != RTMCLD_coPREBUILD) */
   u32LocIdleClock         = RTMCLD_u32IdleClock;
   RTMCLD_u32Load          = (u32LocIdleClock - RTMCLD_u32PrevIdleClock);
   RTMCLD_u32PrevIdleClock = u32LocIdleClock;
   #endif /* if (RTMCLD_coCONFIGURATION_TYPE != RTMCLD_coPREBUILD) */
}

/**********************************************************************************************************************/
/* !FuncName    : RTMCLD_vidReloadPeriodCounter                                                                       */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_11_05504_005.01                                                                              */
/* !Trace_To    : VEES_R_11_05504_006.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  A.Nagy                                                                                             */
/**********************************************************************************************************************/
STATIC INLINE void RTMCLD_vidReloadPeriodCounter(void)
{
   #if (RTMCLD_coCONFIGURATION_TYPE != RTMCLD_coPREBUILD)

   uint16 u16LocCounterValue;

   u16LocCounterValue = RTMCLD_u16GetReloadValueCounter();

   if (u16LocCounterValue == 0) /* to prevent a division by 0 into RTMCLD_vidLoadMeasure function */
   {
      RTMCLD_u16MeasurementPeriodCounter = RTMCLD_u16MAIN_LOOPS_NB;
      RTMCLD_u32MeasurementPeriodMs      = RTMCLD_u16MAIN_LOOPS_NB * RTMCLD_u16MAIN_FUNCTION_PERIOD_MS;
   }
   else
   {
      RTMCLD_u16MeasurementPeriodCounter = u16LocCounterValue;
      RTMCLD_u32MeasurementPeriodMs      = u16LocCounterValue * RTMCLD_u16MAIN_FUNCTION_PERIOD_MS;
   }

   #else /* if (RTMCLD_coCONFIGURATION_TYPE != RTMCLD_coPREBUILD) */
   RTMCLD_u16MeasurementPeriodCounter = RTMCLD_u16MAIN_LOOPS_NB;
   #endif /* if (RTMCLD_coCONFIGURATION_TYPE != RTMCLD_coPREBUILD) */
}

#define RTMCLD_STOP_SEC_CODE
#include "RTMCLD_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/

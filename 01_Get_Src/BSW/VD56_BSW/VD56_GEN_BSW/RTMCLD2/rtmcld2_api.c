/**********************************************************************************************************************/
/* !Layer           : SRVL                                                                                            */
/* !Component       : RTMCLD2                                                                                          */
/* !Description     : Real time measurement of CPU load                                                               */
/*                                                                                                                    */
/* !File            : RTMCLD2_API.c                                                                                    */
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
 * %PID: P2017_BSW:A96793.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "OS_API.h"

#include "RTMCLD2.h"
#include "RTMCLD2_EndlessLoop_Tricore.h"
#include "RTMCLD2_CFG.h"
#include "RTMCLD2_DEF.h"
#include "RTMCLD2_Co.h"
#include "SWFAIL.h"
#include "ar_mfx.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation define are defined                                                             */
/**********************************************************************************************************************/

#ifndef RTMCLD2_coLOOP_MEASURE
   #error the macro-constant RTMCLD2_coLOOP_MEASURE shall be defined
#endif
#ifndef RTMCLD2_coENABLE
   #error the macro-constant RTMCLD2_coENABLE shall be defined
#endif
#ifndef RTMCLD2_coDISABLE
   #error the macro-constant RTMCLD2_coDISABLE shall be defined
#endif
#ifndef RTMCLD2_coCONFIGURATION_TYPE
   #error the macro-constant RTMCLD2_coCONFIGURATION_TYPE shall be defined
#endif
#ifndef RTMCLD2_coRUNTIME
   #error the macro-constant RTMCLD2_coRUNTIME shall be defined
#endif
#ifndef RTMCLD2_coPREBUILD
   #error the macro-constant RTMCLD2_coPREBUILD shall be defined
#endif
#ifndef RTMCLD2_coPOSTBUILD
   #error the macro-constant RTMCLD2_coPOSTBUILD shall be defined
#endif


STATIC INLINE void RTMCLD2_vidLoadMeasure(void);
STATIC INLINE void RTMCLD2_vidReloadPeriodCounter(void);

#define RTMCLD2_START_SEC_RTMCLD_ENDLESS_LOOP_CODE
#include "RTMCLD2_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : TASK OSTSK_S_RTMCLD2_CPU_LOAD_MNG                                                                    */
/* !Description : This task shall be used in both the verification of the loop duration and the CPU load calculations.*/
/*                                                                                                                    */
/* !Trace_To    : VEES_R_11_05504_005.01                                                                              */
/* !Trace_To    : VEES_R_11_05504_006.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  A.Nagy                                                                                             */
/**********************************************************************************************************************/
TASK(OSTSK_S_RTMCLD2_CPU_LOAD_MNG)
{
   RTMCLD2_u32Load          = 0;
   RTMCLD2_u32IdleClock     = 0;
   RTMCLD2_u32PrevIdleClock = 0;

   RTMCLD2_u16MeasurementPeriodCounter = 0;

   #if (RTMCLD2_coCONFIGURATION_TYPE != RTMCLD2_coPREBUILD)
   RTMCLD2_u32MeasurementPeriodMs = 1;      /* for safety should be different to 0... but will be recomputed before use*/
   #endif

   #if (RTMCLD2_coLOOP_MEASURE == RTMCLD2_coENABLE)
   if (RTMCLD2_u8TestDone != 0x5A)
   {
      RTMCLD2_u8TestDone = 0x5A;
      RTMCLD2_vidSTART_MEASUREMENT_TIMER();
   }
   #endif /* RTMCLD2_coLOOP_MEASURE == RTMCLD2_coENABLE */

   RTMCLD2_vidEndlessLoop();

   /* There is no termination to this task because the function               */
   /* RTMCLD2_vidEndlessLoop() has a forever loop that never ends              */
}
#define RTMCLD2_STOP_SEC_RTMCLD_ENDLESS_LOOP_CODE
#include "RTMCLD2_MemMap.h"


#define RTMCLD2_START_SEC_CODE
#include "RTMCLD2_MemMap.h"
/**********************************************************************************************************************/
/* !FuncName    : RTMCLD2_vidEndLoopDurationMeas                                                                       */
/* !Description : Stores the current number of 200 loops from the  RTMCLD2_u32IdleClock counter                        */
/*                                                                                                                    */
/* !LastAuthor  :  A.Nagy                                                                                             */
/**********************************************************************************************************************/
void RTMCLD2_vidEndLoopDurationMeas(void)
{

   #if (RTMCLD2_coLOOP_MEASURE == RTMCLD2_coENABLE)
   RTMCLD2_u32MeasuredValue = RTMCLD2_u32IdleClock;
   #endif /* RTMCLD2_coLOOP_MEASURE == RTMCLD2_coENABLE */
}

/**********************************************************************************************************************/
/* !FuncName    : RTMCLD2_vidMainFunction                                                                              */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !LastAuthor  :  A.Nagy                                                                                             */
/**********************************************************************************************************************/
void RTMCLD2_vidMainFunction(void)
{
   if (RTMCLD2_u16MeasurementPeriodCounter > 0)
   {
      RTMCLD2_u16MeasurementPeriodCounter--;
      if (RTMCLD2_u16MeasurementPeriodCounter == 0)
      {
         RTMCLD2_vidLoadMeasure();
         RTMCLD2_vidReloadPeriodCounter();
      }
   }
   else
   {
      RTMCLD2_vidReloadPeriodCounter();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : RTMCLD2_vidLoadMeasure                                                                               */
/* !Description : Returns in RTMCLD2_uint32Load the percent of Load in the measurement period                          */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_11_05504_013.01                                                                              */
/* !Trace_To    : VEES_R_11_05504_014.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  A.Nagy                                                                                             */
/**********************************************************************************************************************/

STATIC INLINE void RTMCLD2_vidLoadMeasure(void)
{
   uint32 u32LocIdleClock;


   #if (RTMCLD2_coCONFIGURATION_TYPE != RTMCLD2_coPREBUILD)
   uint32 u32LocIdle;
   uint32 u32LocRTMLoadRaw;

   u32LocIdleClock         = RTMCLD2_u32IdleClock;
   u32LocRTMLoadRaw        = u32LocIdleClock - RTMCLD2_u32PrevIdleClock;
   RTMCLD2_u32PrevIdleClock = u32LocIdleClock;

   if (u32LocRTMLoadRaw <= (UINT32_MAX / RTMCLD2_udtENDLESS_LOOP_EXEC_TIME) )
   {
      u32LocIdle = ( (u32LocRTMLoadRaw * RTMCLD2_udtENDLESS_LOOP_EXEC_TIME)
                     / RTMCLD2_u32MeasurementPeriodMs);
   }
   else
   {
      u32LocIdle = Mfx_RMulDiv_u32u32u32_u32(u32LocRTMLoadRaw, (uint32)RTMCLD2_udtENDLESS_LOOP_EXEC_TIME,
                                             RTMCLD2_u32MeasurementPeriodMs);
   }

   if (u32LocIdle < 1000000)
   {
      RTMCLD2_u32Load = (1000000 - u32LocIdle) / 100;
   }
   else
   {
      RTMCLD2_u32Load = 0;
      SWFAIL_vidSoftwareErrorHook();
   }

   #else /* if (RTMCLD2_coCONFIGURATION_TYPE != RTMCLD2_coPREBUILD) */
   u32LocIdleClock         = RTMCLD2_u32IdleClock;
   RTMCLD2_u32Load          = (u32LocIdleClock - RTMCLD2_u32PrevIdleClock);
   RTMCLD2_u32PrevIdleClock = u32LocIdleClock;
   #endif /* if (RTMCLD2_coCONFIGURATION_TYPE != RTMCLD2_coPREBUILD) */
}

/**********************************************************************************************************************/
/* !FuncName    : RTMCLD2_vidReloadPeriodCounter                                                                       */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_11_05504_005.01                                                                              */
/* !Trace_To    : VEES_R_11_05504_006.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  A.Nagy                                                                                             */
/**********************************************************************************************************************/
STATIC INLINE void RTMCLD2_vidReloadPeriodCounter(void)
{
   #if (RTMCLD2_coCONFIGURATION_TYPE != RTMCLD2_coPREBUILD)

   uint16 u16LocCounterValue;

   u16LocCounterValue = RTMCLD2_u16GetReloadValueCounter();

   if (u16LocCounterValue == 0) /* to prevent a division by 0 into RTMCLD2_vidLoadMeasure function */
   {
      RTMCLD2_u16MeasurementPeriodCounter = RTMCLD2_u16MAIN_LOOPS_NB;
      RTMCLD2_u32MeasurementPeriodMs      = RTMCLD2_u16MAIN_LOOPS_NB * RTMCLD2_u16MAIN_FUNCTION_PERIOD_MS;
   }
   else
   {
      RTMCLD2_u16MeasurementPeriodCounter = u16LocCounterValue;
      RTMCLD2_u32MeasurementPeriodMs      = u16LocCounterValue * RTMCLD2_u16MAIN_FUNCTION_PERIOD_MS;
   }

   #else /* if (RTMCLD2_coCONFIGURATION_TYPE != RTMCLD2_coPREBUILD) */
   RTMCLD2_u16MeasurementPeriodCounter = RTMCLD2_u16MAIN_LOOPS_NB;
   #endif /* if (RTMCLD2_coCONFIGURATION_TYPE != RTMCLD2_coPREBUILD) */
}

#define RTMCLD2_STOP_SEC_CODE
#include "RTMCLD2_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/

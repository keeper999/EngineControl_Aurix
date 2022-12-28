/**********************************************************************************************************************/
/* !Layer           : SRVL                                                                                            */
/* !Component       : RTMCLD2                                                                                          */
/* !Description     : Real time measurement of CPU load                                                               */
/*                                                                                                                    */
/* !File            : RTMCLD2_EndlessLoop_Tricore.h                                                                    */
/* !Description     : Endless loop in assembler for Infineon Tricore microcontroller                                  */
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
 * %PID: P2017_BSW:A96789.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef RTMCLD2_ENDLESSLOOP_H
#define RTMCLD2_ENDLESSLOOP_H

#include "Std_Types.h"
#include "RTMCLD2.h"
#include "RTMCLD2_DEF.h"
#include "RTMCLD2_CFG.h"

/**********************************************************************************************************************/
/* Conditionnal inclusion                                                                                             */
/**********************************************************************************************************************/

#define RTMCLD2_START_SEC_RTMCLD_ENDLESS_LOOP_CODE
#include "RTMCLD2_MemMap.h"


/**********************************************************************************************************************/
/* !FuncName    : RTMCLD2_vidEndlessLoop                                                                               */
/* !Description : The endless loop function to increment the loop counter.                                            */
/*                                                                                                                    */
/* !LastAuthor  :  L. Baglin                                                                                          */
/**********************************************************************************************************************/
#if defined(__TASKING__)
STATIC INLINE void RTMCLD2_vidEndlessLoop(void)
{

   __asm("movh.a a15,#@his(RTMCLD2_u32IdleClock)") ;
   __asm("lea a15,[a15]@los(RTMCLD2_u32IdleClock)") ;
   __asm(".LoopRTM:") ;
   __asm("ld.w d15,[a15]") ;
   __asm("add  d15,#1") ;
   __asm("st.w [a15],d15") ;
   __asm("nop") ;
   __asm("nop") ;
   __asm("nop") ;
   __asm("nop") ;
   __asm("nop") ;
   __asm("j .LoopRTM") ;

}

#elif defined(_GNU_C_TRICORE_)

STATIC INLINE void RTMCLD2_vidEndlessLoop(void)
{

   __asm("movh.a %a15,hi:RTMCLD2_u32IdleClock") ;
   __asm("lea %a15,[%a15]lo:RTMCLD2_u32IdleClock") ;
   __asm(".LoopRTM:");
   __asm("ld.w %d15,[%a15]");
   __asm("add  %d15, 1");
   __asm("st.w [%a15],%d15");
   __asm("nop");
   __asm("nop");
   __asm("nop");
   __asm("nop");
   __asm("nop");
   __asm("j .LoopRTM");
 
}

#else
#error "Compiler unsupported"
#endif

#define RTMCLD2_STOP_SEC_RTMCLD_ENDLESS_LOOP_CODE
#include "RTMCLD2_MemMap.h"


#endif /* RTMCLD2_ENDLESSLOOP_H */

/*--------------------------------------------------- end of file ----------------------------------------------------*/

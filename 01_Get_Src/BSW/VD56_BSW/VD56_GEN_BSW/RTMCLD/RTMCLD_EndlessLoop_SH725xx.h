/**********************************************************************************************************************/
/* !Layer           : SRVL                                                                                            */
/* !Component       : RTMCLD                                                                                          */
/* !Description     : Real time measurement of CPU load                                                               */
/*                                                                                                                    */
/* !File            : RTMCLD_EndlessLoop_SH725xx.h                                                                    */
/* !Description     : Endless loop in assembler for Renesas SH725xx microcontroller                                   */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5385380                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* !CompReq : ASM                                                                                                     */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A1064.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef RTMCLD_ENDLESSLOOP_H
#define RTMCLD_ENDLESSLOOP_H

#include "Std_Types.h"
#include "RTMCLD.h"
#include "RTMCLD_CFG.h"

/**********************************************************************************************************************/
/* Conditionnal inclusion                                                                                             */
/**********************************************************************************************************************/

#ifdef _RENESAS_C_SH725xx_

#define RTMCLD_START_SEC_RTMCLD_ENDLESS_LOOP_CODE
#include "RTMCLD_MemMap.h"

#pragma inline_asm(RTMCLD_vidEndlessLoop)

/**********************************************************************************************************************/
/* !FuncName    : RTMCLD_vidEndlessLoop                                                                               */
/* !Description : The endless loop function to increment the loop counter.                                            */
/*                                                                                                                    */
/* !LastAuthor  :  L. Baglin                                                                                          */
/**********************************************************************************************************************/
STATIC void RTMCLD_vidEndlessLoop(void)
{
      MOV.L #_RTMCLD_u32IdleClock, R1
      .ALIGN   4
?0001:
      MOV.L @R1,R2
      NOP
      ADD   #1, R2
      NOP
      MOV.L R2,@R1
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      NOP
      BRA   ?0001
      NOP
}

#define RTMCLD_STOP_SEC_RTMCLD_ENDLESS_LOOP_CODE
#include "RTMCLD_MemMap.h"

#else/* ifdef _RENESAS_C_SH725xx_ */
   #error this version of RTMCLD is not compatible with your micrcontroller defined in Compiler.h
#endif /* ifdef _RENESAS_C_SH725xx_ */



#endif /* RTMCLD_ENDLESSLOOP_H */

/*--------------------------------------------------- end of file ----------------------------------------------------*/

/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : div_repeat_ssu32_sat                                    */
/*                                                                            */
/* !File            : div_repeat_ssu32_sat.c                                  */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Mon Mar 07 14:40:10 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/div_repeat_$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   18 Mar 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "rtwtypes.h"
#include "rtw_shared_utils.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE_LIB" */
#define VemsRtLib_START_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

SInt32 div_repeat_ssu32_sat(SInt32 localnumerator, UInt32 localdenominator,
  UInt32 localnRepeatSub)
{
  SInt32 localquotient;
  UInt32 localtempAbsQuotient;
  UInt32 localquotientNeedsNegation;
  if (localdenominator == ((UInt32)0)) {
    localquotient = (localnumerator >= 0) ? MAX_int32_T : MIN_int32_T;

    /* divide by zero handler */
  } else {
    localquotientNeedsNegation = (localnumerator < 0);
    localtempAbsQuotient = div_repeat_u32_sat((UInt32)((localnumerator >= 0) ?
      localnumerator : (-localnumerator)), localdenominator, localnRepeatSub);
    if (localquotientNeedsNegation) {
      localquotient = (localtempAbsQuotient <= 2147483647U) ? ((SInt32)
        (-((SInt32)localtempAbsQuotient))) : MIN_int32_T;
    } else {
      localquotient = (localtempAbsQuotient <= 2147483647U) ? ((SInt32)
        localtempAbsQuotient) : MAX_int32_T;
    }
  }

  return localquotient;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

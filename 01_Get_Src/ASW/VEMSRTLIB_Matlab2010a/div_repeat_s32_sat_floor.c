/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : div_repeat_s32_sat_floor                                */
/*                                                                            */
/* !File            : div_repeat_s32_sat_floor.c                              */
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
/*   Code generated on: Thu Jan 06 15:56:59 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/div_repeat_$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   17 Jan 2011 $*/
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

SInt32 div_repeat_s32_sat_floor(SInt32 localnumerator, SInt32
  localdenominator, UInt32 localnRepeatSub)
{
  SInt32 localquotient;
  UInt32 localquotientNeedsNegation;
  UInt32 localabsNumerator;
  UInt32 localabsDenominator;
  if (localdenominator == 0) {
    localquotient = (localnumerator >= 0) ? MAX_int32_T : MIN_int32_T;

    /* divide by zero handler */
  } else {
    localabsNumerator = (UInt32)((localnumerator >= 0) ? localnumerator :
      (-localnumerator));
    localabsDenominator = (UInt32)((localdenominator >= 0) ? localdenominator :
                                     (-localdenominator));
    localquotientNeedsNegation = ((localnumerator < 0) != (localdenominator < 0));
    if (localquotientNeedsNegation) {
      localabsNumerator = div_repeat_u32_sat_ceiling(localabsNumerator,
        localabsDenominator, localnRepeatSub);
      localquotient = (localabsNumerator <= 2147483647U) ? ((SInt32)(-((SInt32)
        localabsNumerator))) : MIN_int32_T;
    } else {
      localabsNumerator = div_repeat_u32_sat(localabsNumerator,
        localabsDenominator, localnRepeatSub);
      localquotient = (localabsNumerator <= 2147483647U) ? ((SInt32)
        localabsNumerator) : MAX_int32_T;
    }
  }

  return localquotient;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

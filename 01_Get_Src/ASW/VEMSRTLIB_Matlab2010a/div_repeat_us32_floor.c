/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : div_repeat_us32_floor                                   */
/*                                                                            */
/* !File            : div_repeat_us32_floor.c                                 */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
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
/*   Code generated on: Mon Oct 25 10:21:39 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/div_repeat_$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   pchinazz                               $$Date::   08 Nov 2010 $*/
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
#define VemsRtLib_START_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

UInt32 div_repeat_us32_floor(SInt32 localnumerator, SInt32 localdenominator,
  UInt32 localnRepeatSub)
{
  UInt32 localquotient;
  UInt32 localquotientNeedsNegation;
  UInt32 localabsNumerator;
  UInt32 localabsDenominator;
  if (localdenominator == 0) {
    localquotient = (localnumerator >= 0) ? MAX_uint32_T : 0U;

    /* divide by zero handler */
  } else {
    localabsNumerator = (UInt32)((localnumerator >= 0) ? localnumerator :
      (-localnumerator));
    localabsDenominator = (UInt32)((localdenominator >= 0) ? localdenominator :
                                     (-localdenominator));
    localquotientNeedsNegation = ((localnumerator < 0) != (localdenominator < 0));
    if (localquotientNeedsNegation) {
      localabsNumerator = div_repeat_u32_ceiling(localabsNumerator,
        localabsDenominator, localnRepeatSub);
      localquotient = (UInt32)(-((SInt32)localabsNumerator));
    } else {
      localabsNumerator = div_repeat_u32(localabsNumerator, localabsDenominator,
        localnRepeatSub);
      localquotient = localabsNumerator;
    }
  }

  return localquotient;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

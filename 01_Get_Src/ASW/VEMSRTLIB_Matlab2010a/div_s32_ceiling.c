/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : div_s32_ceiling                                         */
/*                                                                            */
/* !File            : div_s32_ceiling.c                                       */
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
/*   Code generated on: Tue Nov 02 14:21:05 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/div_s32_cei$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   02 Nov 2010 $*/
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

SInt32 div_s32_ceiling(SInt32 localnumerator, SInt32 localdenominator)
{
  SInt32 localquotient;
  UInt32 localabsNumerator;
  UInt32 localabsDenominator;
  UInt32 localtempAbsQuotient;
  UInt32 localquotientNeedsNegation;
  if (localdenominator == 0) {
    localquotient = (localnumerator >= 0) ? MAX_int32_T : MIN_int32_T;

    /* divide by zero handler */
  } else {
    localabsNumerator = (UInt32)((localnumerator >= 0) ? localnumerator :
      (-localnumerator));
    localabsDenominator = (UInt32)((localdenominator >= 0) ? localdenominator :
                                     (-localdenominator));
    localquotientNeedsNegation = ((localnumerator < 0) != (localdenominator < 0));
    localtempAbsQuotient = localabsNumerator / localabsDenominator;
    if (!localquotientNeedsNegation) {
      localabsNumerator = localabsNumerator % localabsDenominator;
      if (localabsNumerator > ((UInt32)0)) {
        localtempAbsQuotient = localtempAbsQuotient + ((UInt32)1);
      }
    }

    localquotient = localquotientNeedsNegation ? ((SInt32)(-((SInt32)
      localtempAbsQuotient))) : ((SInt32)localtempAbsQuotient);
  }

  return localquotient;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : div_s32_sat_near                                        */
/*                                                                            */
/* !File            : div_s32_sat_near.c                                      */
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
/*   Code generated on: Thu Mar 24 19:49:03 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/div_s32_sat$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   ADELVARE                               $$Date::   25 Mar 2011 $*/
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

SInt32 div_s32_sat_near(SInt32 localnumerator, SInt32 localdenominator)
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
    if ((!localquotientNeedsNegation) && (localtempAbsQuotient >= 2147483647U))
    {
      localquotient = MAX_int32_T;
    } else if ((localquotientNeedsNegation) && (localtempAbsQuotient >
                2147483647U)) {
      localquotient = MIN_int32_T;
    } else {
      localabsNumerator = localabsNumerator % localabsDenominator;
      localabsNumerator = (localabsNumerator << 1);
      if ((localabsNumerator >= localabsDenominator) &&
          ((!localquotientNeedsNegation) || (localabsNumerator >
            localabsDenominator))) {
        localtempAbsQuotient = localtempAbsQuotient + ((UInt32)1);
      }

      localquotient = localquotientNeedsNegation ? ((SInt32)(-((SInt32)
        localtempAbsQuotient))) : ((SInt32)localtempAbsQuotient);
    }
  }

  return localquotient;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

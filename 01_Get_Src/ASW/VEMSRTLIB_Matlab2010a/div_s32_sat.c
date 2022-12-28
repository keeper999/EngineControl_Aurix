/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : div_s32_sat                                             */
/*                                                                            */
/* !File            : div_s32_sat.c                                           */
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
/*   Code generated on: Tue Sep 14 10:11:52 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/div_s32_sat$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   14 Sep 2010 $*/
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

SInt32 div_s32_sat(SInt32 localnumerator, SInt32 localdenominator)
{
  SInt32 localquotient;
  UInt32 localtempAbsQuotient;
  UInt32 localquotientNeedsNegation;
  if (localdenominator == 0) {
    localquotient = (localnumerator >= 0) ? MAX_int32_T : MIN_int32_T;

    /* divide by zero handler */
  } else {
    localquotientNeedsNegation = ((localnumerator < 0) != (localdenominator < 0));
    localtempAbsQuotient = ((UInt32)((localnumerator >= 0) ? localnumerator :
                             (-localnumerator))) / ((UInt32)((localdenominator
      >= 0) ? localdenominator : (-localdenominator)));
    if ((!localquotientNeedsNegation) && (localtempAbsQuotient >= 2147483647U))
    {
      localquotient = MAX_int32_T;
    } else if ((localquotientNeedsNegation) && (localtempAbsQuotient >
                2147483647U)) {
      localquotient = MIN_int32_T;
    } else {
      localquotient = localquotientNeedsNegation ? ((SInt32)(-((SInt32)
        localtempAbsQuotient))) : ((SInt32)localtempAbsQuotient);
    }
  }

  return localquotient;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

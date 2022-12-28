/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : div_repeat_u32_sat                                      */
/*                                                                            */
/* !File            : div_repeat_u32_sat.c                                    */
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
/*   Code generated on: Wed Nov 03 10:02:57 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/div_repeat_$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   04 Nov 2010 $*/
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

UInt32 div_repeat_u32_sat(UInt32 localnumerator, UInt32 localdenominator,
  UInt32 localnRepeatSub)
{
  UInt32 localquotient;
  UInt32 localiRepeatSub;
  UInt8 localnumeratorExtraBit;
  UInt32 localtempQuotient;
  UInt8 localoverflow;
  if (localdenominator == ((UInt32)0)) {
    localquotient = MAX_uint32_T;

    /* divide by zero handler */
  } else {
    localoverflow = (UInt8)0U;
    localtempQuotient = localnumerator / localdenominator;
    localnumerator = localnumerator % localdenominator;
    for (localiRepeatSub = (UInt32)0; localiRepeatSub < localnRepeatSub;
         localiRepeatSub = localiRepeatSub + ((UInt32)1)) {
      localnumeratorExtraBit = (localnumerator >= 2147483648U);
      localnumerator = (localnumerator << 1);
      localoverflow = ((localoverflow) || (localtempQuotient >= 2147483648U));
      localtempQuotient = (localtempQuotient << 1);
      if ((localnumeratorExtraBit) || (localnumerator >= localdenominator)) {
        localtempQuotient = localtempQuotient + ((UInt32)1);
        localnumerator = localnumerator - localdenominator;
      }
    }

    if (localoverflow) {
      localquotient = MAX_uint32_T;
    } else {
      localquotient = localtempQuotient;
    }
  }

  return localquotient;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : div_repeat_u32_sat_ceiling                              */
/*                                                                            */
/* !File            : div_repeat_u32_sat_ceiling.c                            */
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

UInt32 div_repeat_u32_sat_ceiling(UInt32 localnumerator, UInt32
  localdenominator, UInt32 localnRepeatSub)
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

    if ((localoverflow) || (localtempQuotient >= MAX_uint32_T)) {
      localquotient = MAX_uint32_T;
    } else {
      localquotient = localtempQuotient;
      if (localnumerator > 0U) {
        localquotient = localquotient + ((UInt32)1);
      }
    }
  }

  return localquotient;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : div_repeat_u32                                          */
/*                                                                            */
/* !File            : div_repeat_u32.c                                        */
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

UInt32 div_repeat_u32(UInt32 localnumerator, UInt32 localdenominator,
  UInt32 localnRepeatSub)
{
  UInt32 localquotient;
  UInt32 localiRepeatSub;
  UInt8 localnumeratorExtraBit;
  if (localdenominator == ((UInt32)0)) {
    localquotient = MAX_uint32_T;

    /* divide by zero handler */
  } else {
    localquotient = localnumerator / localdenominator;
    localnumerator = localnumerator % localdenominator;
    for (localiRepeatSub = (UInt32)0; localiRepeatSub < localnRepeatSub;
         localiRepeatSub = localiRepeatSub + ((UInt32)1)) {
      localnumeratorExtraBit = (localnumerator >= 2147483648U);
      localnumerator = (localnumerator << 1);
      localquotient = (localquotient << 1);
      if ((localnumeratorExtraBit) || (localnumerator >= localdenominator)) {
        localquotient = localquotient + ((UInt32)1);
        localnumerator = localnumerator - localdenominator;
      }
    }
  }

  return localquotient;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

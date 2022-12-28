/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : binsearch_u32u16_prevIdx                                */
/*                                                                            */
/* !File            : binsearch_u32u16_prevIdx.c                              */
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
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Jul 31 10:29:41 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/binsearch_u$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   01 Aug 2012 $*/
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

UInt32 binsearch_u32u16_prevIdx(UInt16 localu, const UInt16 localbp[],
  UInt32 localstartIndex, UInt32 localmaxIndex)
{
  UInt32 localbpIndex;
  UInt32 localiRght;
  UInt32 localiLeft;
  UInt32 localbpIdx;
  UInt32 localfound;

  /* Binary Search using Previous Index */
  localbpIdx = localstartIndex;
  localiLeft = 0U;
  localiRght = localmaxIndex;
  localfound = 0U;
  while (localfound == 0U) {
    if (localu < localbp[localbpIdx]) {
      localiRght = localbpIdx - 1U;
      localbpIdx = ((localiRght + localiLeft) >> 1U);
    } else if (localu < localbp[localbpIdx + 1U]) {
      localfound = 1U;
    } else {
      localiLeft = localbpIdx + 1U;
      localbpIdx = ((localiRght + localiLeft) >> 1U);
    }
  }

  localbpIndex = localbpIdx;
  return localbpIndex;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

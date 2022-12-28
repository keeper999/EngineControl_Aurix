/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : look1_is16lfIf_binlcns                                  */
/*                                                                            */
/* !File            : look1_is16lfIf_binlcns.c                                */
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
/*   Code generated on: Thu Aug 09 08:30:50 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/look1_is16l$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   24 Aug 2012 $*/
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

Float32 look1_is16lfIf_binlcns(SInt16 localu0, const SInt16 localbp0[], const
  SInt16 localtable[], UInt32 localmaxIndex)
{
  Float32 localy;
  Float32 localfrac;
  SInt16 localbpLeftVar;
  UInt32 localiRght;
  UInt32 localiLeft;
  UInt32 localbpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'nearest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Process out of range input: 'Clip to range'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  if (localu0 <= localbp0[0U]) {
    localiLeft = 0U;
    localfrac = 0.0F;
  } else if (localu0 < localbp0[localmaxIndex]) {
    /* Binary Search */
    localbpIdx = ((localmaxIndex + 1U) >> 1U);
    localiLeft = 0U;
    localiRght = localmaxIndex;
    while ((localiRght - localiLeft) > 1U) {
      if (localu0 < localbp0[localbpIdx]) {
        localiRght = localbpIdx;
      } else {
        localiLeft = localbpIdx;
      }

      localbpIdx = ((localiRght + localiLeft) >> 1U);
    }

    localbpLeftVar = localbp0[localiLeft];
    localfrac = ((Float32)((UInt16)(((UInt32)localu0) - ((UInt32)
      localbpLeftVar)))) / ((Float32)((UInt16)(localbp0[localiLeft + 1U] -
      localbpLeftVar)));
  } else {
    localiLeft = localmaxIndex - 1U;
    localfrac = 1.0F;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'nearest'
     Overflow mode: 'saturate'
   */
  localbpLeftVar = localtable[localiLeft];
  localy = (((((Float32)localtable[localiLeft + 1U]) * 0.0625F) - (((Float32)
    localbpLeftVar) * 0.0625F)) * localfrac) + (((Float32)localbpLeftVar) *
    0.0625F);
  return localy;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

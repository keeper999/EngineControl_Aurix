/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : look2_1fdv2bdvbcvbfbbr3nfbbnx                           */
/*                                                                            */
/* !File            : look2_1fdv2bdvbcvbfbbr3nfbbnx.c                         */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
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
/*   Code generated on: Wed Jun 27 13:45:13 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/look2_1fdv2$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   adelvare                               $$Date::   03 Jul 2012 $*/
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

Float32 look2_1fdv2bdvbcvbfbbr3nfbbnx(UInt16 localu0, UInt32 localu1, const
  UInt16 localbp0[], const UInt32 localbp1[], const UInt16 localtable[],
  const UInt32 localmaxIndex[], UInt32 localstride)
{
  Float32 localy;
  UInt32 localmaxIndex0;
  UInt32 localmaxIndex1;
  Float32 localfrac;
  UInt32 localbpIndices[2];
  Float32 localfractions[2];
  UInt16 localbpLeftVar;
  UInt32 localbpIdx;
  UInt32 localiLeft;

  /* Lookup 2-D
     Canonical function name: look2_iu16u32lftu16n27If_binlcns
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'nearest'
   */
  localmaxIndex0 = localmaxIndex[0U];
  localmaxIndex1 = localmaxIndex[1U];

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Process out of range input: 'Clip to range'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  if (localu0 <= localbp0[0U]) {
    localiLeft = 0U;
    localfrac = 0.0F;
  } else if (localu0 < localbp0[localmaxIndex0]) {
    /* Binary Search */
    localbpIdx = ((localmaxIndex0 + 1U) >> 1U);
    localiLeft = 0U;
    while ((localmaxIndex0 - localiLeft) > 1U) {
      if (localu0 < localbp0[localbpIdx]) {
        localmaxIndex0 = localbpIdx;
      } else {
        localiLeft = localbpIdx;
      }

      localbpIdx = ((localmaxIndex0 + localiLeft) >> 1U);
    }

    localbpLeftVar = localbp0[localiLeft];
    localfrac = ((Float32)((UInt16)(((UInt32)localu0) - ((UInt32)
      localbpLeftVar)))) / ((Float32)((UInt16)(((UInt32)localbp0[localiLeft
      + 1U]) - ((UInt32)localbpLeftVar))));
  } else {
    localiLeft = localmaxIndex0 - 1U;
    localfrac = 1.0F;
  }

  localfractions[0U] = localfrac;
  localbpIndices[0U] = localiLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Process out of range input: 'Clip to range'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  if (localu1 <= localbp1[0U]) {
    localiLeft = 0U;
    localfrac = 0.0F;
  } else if (localu1 < localbp1[localmaxIndex1]) {
    /* Binary Search */
    localmaxIndex0 = ((localmaxIndex1 + 1U) >> 1U);
    localiLeft = 0U;
    while ((localmaxIndex1 - localiLeft) > 1U) {
      if (localu1 < localbp1[localmaxIndex0]) {
        localmaxIndex1 = localmaxIndex0;
      } else {
        localiLeft = localmaxIndex0;
      }

      localmaxIndex0 = ((localmaxIndex1 + localiLeft) >> 1U);
    }

    localmaxIndex0 = localbp1[localiLeft];
    localfrac = (Float32)(((Float32d)(localu1 - localmaxIndex0)) / ((Float32d)
      (localbp1[localiLeft + 1U] - localmaxIndex0)));
  } else {
    localiLeft = localmaxIndex1 - 1U;
    localfrac = 1.0F;
  }

  localfractions[1U] = localfrac;
  localbpIndices[1U] = localiLeft;

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'nearest'
     Overflow mode: 'saturate'
   */
  localmaxIndex0 = (localbpIndices[1] * localstride) + localbpIndices[0];
  localbpLeftVar = localtable[localmaxIndex0];
  localfrac = (((((Float32)localtable[localmaxIndex0 + 1U]) * 7.450580597E-009F)
                - (((Float32)localbpLeftVar) * 7.450580597E-009F)) *
               localfractions[0]) + (((Float32)localbpLeftVar) *
    7.450580597E-009F);
  localmaxIndex0 = localmaxIndex0 + localstride;
  localbpLeftVar = localtable[localmaxIndex0];
  localy = ((((((((Float32)localtable[localmaxIndex0 + 1U]) * 7.450580597E-009F)
                - (((Float32)localbpLeftVar) * 7.450580597E-009F)) *
               localfractions[0]) + (((Float32)localbpLeftVar) *
    7.450580597E-009F)) - localfrac) * localfractions[1]) + localfrac;
  return localy;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

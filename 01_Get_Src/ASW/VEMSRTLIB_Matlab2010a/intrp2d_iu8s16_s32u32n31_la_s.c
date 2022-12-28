/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : intrp2d_iu8s16_s32u32n31_la_s                           */
/*                                                                            */
/* !File            : intrp2d_iu8s16_s32u32n31_la_s.c                         */
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
/*   Code generated on: Thu Apr 12 19:26:29 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/intrp2d_iu8$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   20 Apr 2012 $*/
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

UInt8 intrp2d_iu8s16_s32u32n31_la_s(const SInt32 localbpIndex[], const
  UInt32 localfrac[], const UInt8 localtable[], UInt32 localstride, const
  UInt32 localmaxIndex[])
{
  UInt8 localy;
  UInt8 localyL_1d;
  UInt32 localoffset_1d;
  UInt8 localyL_0d0;
  UInt8 localintermRes;

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  localoffset_1d = ((UInt32)(localbpIndex[1] * ((SInt32)localstride))) +
    ((UInt32)localbpIndex[0]);
  if (((UInt32)localbpIndex[0]) == localmaxIndex[0]) {
    localyL_1d = localtable[localoffset_1d];
  } else {
    localyL_0d0 = localtable[localoffset_1d];
    localintermRes = (UInt8)mul_s32_s32_u32_sr31((SInt32)((SInt16)
      (localtable[localoffset_1d + 1U] - localyL_0d0)), localfrac[0]);
    localyL_1d = (UInt8)(((UInt32)localyL_0d0) + ((UInt32)localintermRes));
  }

  if (((UInt32)localbpIndex[1]) == localmaxIndex[1]) {
    localy = localyL_1d;
  } else {
    localoffset_1d = localoffset_1d + localstride;
    if (((UInt32)localbpIndex[0]) == localmaxIndex[0]) {
      localyL_0d0 = localtable[localoffset_1d];
    } else {
      localyL_0d0 = localtable[localoffset_1d];
      localintermRes = (UInt8)mul_s32_s32_u32_sr31((SInt32)((SInt16)
        (localtable[localoffset_1d + 1U] - localyL_0d0)), localfrac[0]);
      localyL_0d0 = (UInt8)(((UInt32)localyL_0d0) + ((UInt32)
        localintermRes));
    }

    localyL_0d0 = (UInt8)mul_s32_s32_u32_sr31((SInt32)((SInt16)(localyL_0d0
      - localyL_1d)), localfrac[1]);
    localy = (UInt8)(((UInt32)localyL_1d) + ((UInt32)localyL_0d0));
  }

  return localy;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

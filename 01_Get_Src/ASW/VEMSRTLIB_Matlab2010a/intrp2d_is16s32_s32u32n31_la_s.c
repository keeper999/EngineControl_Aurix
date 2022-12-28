/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : intrp2d_is16s32_s32u32n31_la_s                          */
/*                                                                            */
/* !File            : intrp2d_is16s32_s32u32n31_la_s.c                        */
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
/*   Code generated on: Thu May 24 09:08:24 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/intrp2d_is1$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   31 May 2012 $*/
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

SInt16 intrp2d_is16s32_s32u32n31_la_s(const SInt32 localbpIndex[], const
  UInt32 localfrac[], const SInt16 localtable[], UInt32 localstride, const
  UInt32 localmaxIndex[])
{
  SInt16 localy;
  SInt16 localyL_1d;
  UInt32 localoffset_1d;
  SInt16 localyL_0d0;
  SInt16 localintermRes;

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
    localintermRes = (SInt16)mul_s32_s32_u32_sr31(localtable[localoffset_1d +
      1U] - localyL_0d0, localfrac[0]);
    localyL_1d = (SInt16)(localyL_0d0 + localintermRes);
  }

  if (((UInt32)localbpIndex[1]) == localmaxIndex[1]) {
    localy = localyL_1d;
  } else {
    localoffset_1d = localoffset_1d + localstride;
    if (((UInt32)localbpIndex[0]) == localmaxIndex[0]) {
      localyL_0d0 = localtable[localoffset_1d];
    } else {
      localyL_0d0 = localtable[localoffset_1d];
      localintermRes = (SInt16)mul_s32_s32_u32_sr31(localtable[localoffset_1d +
        1U] - localyL_0d0, localfrac[0]);
      localyL_0d0 = (SInt16)(localyL_0d0 + localintermRes);
    }

    localyL_0d0 = (SInt16)mul_s32_s32_u32_sr31(localyL_0d0 - localyL_1d,
      localfrac[1]);
    localy = (SInt16)(localyL_1d + localyL_0d0);
  }

  return localy;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

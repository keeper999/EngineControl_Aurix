/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : intrp1d_iu8s16_s32u32n31_la_s                           */
/*                                                                            */
/* !File            : intrp1d_iu8s16_s32u32n31_la_s.c                         */
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/intrp1d_iu8$*/
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

UInt8 intrp1d_iu8s16_s32u32n31_la_s(SInt32 localbpIndex, UInt32 localfrac,
  const UInt8 localtable[], UInt32 localmaxIndex)
{
  UInt8 localy;
  UInt32 localoffset_0d;
  UInt8 localyL_0d0;
  UInt8 localintermRes;

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  localoffset_0d = (UInt32)localbpIndex;
  if (((UInt32)localbpIndex) == localmaxIndex) {
    localy = localtable[localoffset_0d];
  } else {
    localyL_0d0 = localtable[localoffset_0d];
    localintermRes = (UInt8)mul_s32_s32_u32_sr31((SInt32)((SInt16)
      (localtable[localoffset_0d + 1U] - localyL_0d0)), localfrac);
    localy = (UInt8)(((UInt32)localyL_0d0) + ((UInt32)localintermRes));
  }

  return localy;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

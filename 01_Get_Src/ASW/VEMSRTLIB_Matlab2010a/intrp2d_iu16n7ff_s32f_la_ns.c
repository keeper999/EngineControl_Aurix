/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : intrp2d_iu16n7ff_s32f_la_ns                             */
/*                                                                            */
/* !File            : intrp2d_iu16n7ff_s32f_la_ns.c                           */
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
/*   Code generated on: Mon May 28 18:55:36 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/intrp2d_iu1$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   29 May 2012 $*/
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

Float32 intrp2d_iu16n7ff_s32f_la_ns(const SInt32 localbpIndex[], const
  Float32 localfrac[], const UInt16 localtable[], UInt32 localstride, const
  UInt32 localmaxIndex[])
{
  Float32 localy;
  Float32 localyL_1d;
  Float32 localyR_1d;
  UInt32 localoffset_1d;
  UInt16 localyL_0d0;

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'nearest'
     Overflow mode: 'saturate'
   */
  localoffset_1d = ((UInt32)(localbpIndex[1] * ((SInt32)localstride))) +
    ((UInt32)localbpIndex[0]);
  if (((UInt32)localbpIndex[0]) == localmaxIndex[0]) {
    localyL_1d = ((Float32)localtable[localoffset_1d]) * 0.0078125F;
  } else {
    localyL_0d0 = localtable[localoffset_1d];
    localyL_1d = (((((Float32)localtable[localoffset_1d + 1U]) * 0.0078125F) -
                   (((Float32)localyL_0d0) * 0.0078125F)) * localfrac[0]) +
      (((Float32)localyL_0d0) * 0.0078125F);
  }

  if (((UInt32)localbpIndex[1]) == localmaxIndex[1]) {
    localy = localyL_1d;
  } else {
    localoffset_1d = localoffset_1d + localstride;
    if (((UInt32)localbpIndex[0]) == localmaxIndex[0]) {
      localyR_1d = ((Float32)localtable[localoffset_1d]) * 0.0078125F;
    } else {
      localyL_0d0 = localtable[localoffset_1d];
      localyR_1d = (((((Float32)localtable[localoffset_1d + 1U]) * 0.0078125F)
                     - (((Float32)localyL_0d0) * 0.0078125F)) * localfrac[0]) +
        (((Float32)localyL_0d0) * 0.0078125F);
    }

    localy = ((localyR_1d - localyL_1d) * localfrac[1]) + localyL_1d;
  }

  return localy;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

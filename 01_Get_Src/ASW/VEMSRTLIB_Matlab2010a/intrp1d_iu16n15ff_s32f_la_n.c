/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : intrp1d_iu16n15ff_s32f_la_n                             */
/*                                                                            */
/* !File            : intrp1d_iu16n15ff_s32f_la_n.c                           */
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
/*   Code generated on: Mon Jun 11 17:25:46 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/intrp1d_iu1$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Jun 2012 $*/
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

Float32 intrp1d_iu16n15ff_s32f_la_n(SInt32 localbpIndex, Float32 localfrac,
  const UInt16 localtable[], UInt32 localmaxIndex)
{
  Float32 localy;
  UInt32 localoffset_0d;
  UInt16 localyL_0d0;

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'nearest'
     Overflow mode: 'wrapping'
   */
  localoffset_0d = (UInt32)localbpIndex;
  if (((UInt32)localbpIndex) == localmaxIndex) {
    localy = (((Float32)localtable[localoffset_0d]) * 3.921508687E-005F) +
      6.000000238E-001F;
  } else {
    localyL_0d0 = localtable[localoffset_0d];
    localy = ((((((Float32)localtable[localoffset_0d + 1U]) * 3.921508687E-005F)
                + 6.000000238E-001F) - ((((Float32)localyL_0d0) *
      3.921508687E-005F) + 6.000000238E-001F)) * localfrac) + ((((Float32)
      localyL_0d0) * 3.921508687E-005F) + 6.000000238E-001F);
  }

  return localy;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : intrp1d_iu16p3ff_s32f_la                                */
/*                                                                            */
/* !File            : intrp1d_iu16p3ff_s32f_la.c                              */
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

Float32 intrp1d_iu16p3ff_s32f_la(SInt32 localbpIndex, Float32 localfrac,
  const UInt16 localtable[], UInt32 localmaxIndex)
{
  Float32 localy;
  UInt32 localoffset_0d;
  UInt16 localyL_0d0;

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'wrapping'
   */
  localoffset_0d = (UInt32)localbpIndex;
  if (((UInt32)localbpIndex) == localmaxIndex) {
    localy = ((Float32)localtable[localoffset_0d]) * 8.0F;
  } else {
    localyL_0d0 = localtable[localoffset_0d];
    localy = (((((Float32)localtable[localoffset_0d + 1U]) * 8.0F) -
               (((Float32)localyL_0d0) * 8.0F)) * localfrac) + (((Float32)
      localyL_0d0) * 8.0F);
  }

  return localy;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

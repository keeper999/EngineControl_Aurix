/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : intrp2d_is16n19ff_u32f_l_ns                             */
/*                                                                            */
/* !File            : intrp2d_is16n19ff_u32f_l_ns.c                           */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
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
/*   Code generated on: Wed Sep 12 10:33:08 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/intrp2d_is1$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   25 Sep 2012 $*/
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

Float32 intrp2d_is16n19ff_u32f_l_ns(const UInt32 localbpIndex[], const
  Float32 localfrac[], const SInt16 localtable[], UInt32 localstride)
{
  Float32 localy;
  Float32 localyL_1d;
  UInt32 localoffset_1d;
  SInt16 localyL_0d0;

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'nearest'
     Overflow mode: 'saturate'
   */
  localoffset_1d = (localbpIndex[1] * localstride) + localbpIndex[0];
  localyL_0d0 = localtable[localoffset_1d];
  localyL_1d = (((((Float32)localtable[localoffset_1d + 1U]) *
                  3.200000037E-006F) - (((Float32)localyL_0d0) *
    3.200000037E-006F)) * localfrac[0]) + (((Float32)localyL_0d0) *
    3.200000037E-006F);
  localoffset_1d = localoffset_1d + localstride;
  localyL_0d0 = localtable[localoffset_1d];
  localy = ((((((((Float32)localtable[localoffset_1d + 1U]) * 3.200000037E-006F)
                - (((Float32)localyL_0d0) * 3.200000037E-006F)) * localfrac[0])
              + (((Float32)localyL_0d0) * 3.200000037E-006F)) - localyL_1d) *
            localfrac[1]) + localyL_1d;
  return localy;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

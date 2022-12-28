/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : mul_s32_s32_u32_sr7_sat_near                            */
/*                                                                            */
/* !File            : mul_s32_s32_u32_sr7_sat_near.c                          */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Unspecified (assume 32-bit Generic)")*/
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.2  (R2008b)  04-Aug-2008                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Fri Jan 15 16:03:22 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/mul_s32_s32$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   13 Nov 2012 $*/
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

SInt32 mul_s32_s32_u32_sr7_sat_near(SInt32 locala, UInt32 localb)
{
  SInt32 localresult;
  UInt32 localu32_chi;
  UInt32 localu32_clo;
  UInt32 localu32_roundup;
  SInt32 localtmp;
  mul_wide_su32(locala, localb, &localu32_chi, &localu32_clo);
  localu32_roundup = (UInt32)((localu32_clo & 64U) != 0);
  localu32_clo = ((UInt32)((localu32_chi << 25) | (localu32_clo >> 7))) +
    localu32_roundup;
  localtmp = (SInt32)localu32_chi;
  localu32_chi = ((UInt32)((localu32_roundup) && (localu32_clo == ((UInt32)0))))
    + ((UInt32)((localtmp >= 0) ? ((SInt32)(((UInt32)localtmp) >> 7)) :
                  (~((SInt32)(((UInt32)(~localtmp)) >> 7)))));
  if ((((SInt32)localu32_chi) > 0) || ((localu32_chi == ((UInt32)0)) &&
       (localu32_clo >= 2147483648U))) {
    localresult = MAX_int32_T;
  } else if ((((SInt32)localu32_chi) < (-1)) || ((((SInt32)localu32_chi) ==
               (-1)) && (localu32_clo < 2147483648U))) {
    localresult = MIN_int32_T;
  } else {
    localresult = (SInt32)localu32_clo;
  }

  return localresult;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

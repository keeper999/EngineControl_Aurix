/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : mul_u32_s32_s32_sr33_sat_near                           */
/*                                                                            */
/* !File            : mul_u32_s32_s32_sr33_sat_near.c                         */
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
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Mar 26 11:02:10 2013                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/mul_u32_s32$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Apr 2013 $*/
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

UInt32 mul_u32_s32_s32_sr33_sat_near(SInt32 locala, SInt32 localb)
{
  UInt32 localresult;
  UInt32 localu32_chi;
  UInt32 localu32_clo;
  UInt32 localu32_roundup;
  mul_wide_s32(locala, localb, &localu32_chi, &localu32_clo);
  localu32_roundup = ((localu32_chi & 1U) != 0);
  localu32_clo = ((UInt32)(((SInt32)localu32_chi) >> 1)) + localu32_roundup;
  if ((((SInt32)localu32_chi) >= 0) || ((localu32_roundup) && (localu32_clo ==
        ((UInt32)0)))) {
    localu32_chi = (UInt32)0;
  } else {
    localu32_chi = (UInt32)((SInt32)(-1));
  }

  if (((SInt32)localu32_chi) >= 0) {
    if (localu32_chi) {
      localresult = MAX_uint32_T;
    } else {
      localresult = localu32_clo;
    }
  } else {
    localresult = 0U;
  }

  return localresult;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

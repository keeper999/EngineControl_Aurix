/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : mul_s32_s32_s32_sr31_sat_zero                           */
/*                                                                            */
/* !File            : mul_s32_s32_s32_sr31_sat_zero.c                         */
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
/*   Code generated on: Thu Mar 24 19:49:03 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/mul_s32_s32$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   ADELVARE                               $$Date::   25 Mar 2011 $*/
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

SInt32 mul_s32_s32_s32_sr31_sat_zero(SInt32 locala, SInt32 localb)
{
  SInt32 localresult;
  UInt32 localu32_chi;
  UInt32 localu32_clo;
  UInt32 localu32_roundup;
  mul_wide_s32(locala, localb, &localu32_chi, &localu32_clo);
  localu32_roundup = ((((SInt32)localu32_chi) < 0) && (localu32_clo &
    2147483647U));
  localu32_clo = ((UInt32)((localu32_chi << 1) | (localu32_clo >> 31))) +
    localu32_roundup;
  localu32_chi = ((UInt32)((localu32_roundup) && (localu32_clo == ((UInt32)0))))
    + ((UInt32)(((SInt32)localu32_chi) >> 31));
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

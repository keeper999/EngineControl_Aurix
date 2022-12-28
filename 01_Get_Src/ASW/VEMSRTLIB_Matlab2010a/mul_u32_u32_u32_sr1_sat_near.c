/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : mul_u32_u32_u32_sr1_sat_near                            */
/*                                                                            */
/* !File            : mul_u32_u32_u32_sr1_sat_near.c                          */
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
/*   Code generated on: Tue Jul 22 11:03:57 2014                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/mul_u32_u32$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   28 Aug 2014 $*/
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

UInt32 mul_u32_u32_u32_sr1_sat_near(UInt32 locala, UInt32 localb)
{
  UInt32 localresult;
  UInt32 localu32_chi;
  UInt32 localu32_clo;
  UInt32 localu32_roundup;
  mul_wide_u32(locala, localb, &localu32_chi, &localu32_clo);
  localu32_roundup = ((localu32_clo & 1U) != 0);
  localu32_clo = ((UInt32)((localu32_chi << 31) | (localu32_clo >> 1))) +
    localu32_roundup;
  localu32_chi = ((UInt32)((localu32_roundup) && (localu32_clo == ((UInt32)0))))
    + (localu32_chi >> 1);
  if (localu32_chi) {
    localresult = MAX_uint32_T;
  } else {
    localresult = localu32_clo;
  }

  return localresult;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

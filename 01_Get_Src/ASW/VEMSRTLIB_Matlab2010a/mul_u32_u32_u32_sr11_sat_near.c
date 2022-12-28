/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : mul_u32_u32_u32_sr11_sat_near                           */
/*                                                                            */
/* !File            : mul_u32_u32_u32_sr11_sat_near.c                         */
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
/*   Code generated on: Fri Jan 15 16:04:25 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/mul_u32_u32$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   17 Oct 2012 $*/
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

UInt32 mul_u32_u32_u32_sr11_sat_near(UInt32 locala, UInt32 localb)
{
  UInt32 localresult;
  UInt32 localu32_chi;
  UInt32 localu32_clo;
  UInt32 localu32_roundup;
  mul_wide_u32(locala, localb, &localu32_chi, &localu32_clo);
  localu32_roundup = (UInt32)((localu32_clo & 1024U) != 0);
  localu32_clo = ((UInt32)((localu32_chi << 21) | (localu32_clo >> 11))) +
    localu32_roundup;
  localu32_chi = ((UInt32)((localu32_roundup) && (localu32_clo == ((UInt32)0))))
    + (localu32_chi >> 11);
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

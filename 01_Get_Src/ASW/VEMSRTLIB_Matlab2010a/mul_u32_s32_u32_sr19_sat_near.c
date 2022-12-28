/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : mul_u32_s32_u32_sr19_sat_near                           */
/*                                                                            */
/* !File            : mul_u32_s32_u32_sr19_sat_near.c                         */
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
/*   Code generated on: Fri Jan 15 16:03:06 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/mul_u32_s32$*/
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

UInt32 mul_u32_s32_u32_sr19_sat_near(SInt32 locala, UInt32 localb)
{
  UInt32 localresult;
  UInt32 localu32_chi;
  UInt32 localu32_clo;
  UInt32 localu32_roundup;
  SInt32 localtmp;
  mul_wide_su32(locala, localb, &localu32_chi, &localu32_clo);
  localu32_roundup = (UInt32)((localu32_clo & 262144U) != 0);
  localu32_clo = ((UInt32)((localu32_chi << 13) | (localu32_clo >> 19))) +
    localu32_roundup;
  localtmp = (SInt32)localu32_chi;
  localu32_chi = ((UInt32)((localu32_roundup) && (localu32_clo == ((UInt32)0))))
    + ((UInt32)((localtmp >= 0) ? ((SInt32)(((UInt32)localtmp) >> 19)) :
                  (~((SInt32)(((UInt32)(~localtmp)) >> 19)))));
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

/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : mul_u32_s32_s32_sr38_sat                                */
/*                                                                            */
/* !File            : mul_u32_s32_s32_sr38_sat.c                              */
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
/*   Code generated on: Fri Aug 17 14:51:27 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/mul_u32_s32$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Aug 2012 $*/
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

UInt32 mul_u32_s32_s32_sr38_sat(SInt32 locala, SInt32 localb)
{
  UInt32 localresult;
  UInt32 localu32_chi;
  UInt32 localu32_clo;
  mul_wide_s32(locala, localb, &localu32_chi, &localu32_clo);
  localu32_clo = (UInt32)(((SInt32)localu32_chi) >> 6);
  localu32_chi = (((SInt32)localu32_chi) >= 0) ? 0U : ((UInt32)((SInt32)(-1)));
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

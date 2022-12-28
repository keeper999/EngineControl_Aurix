/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : plook_u8u16u16n14u32n31_binca_f                         */
/*                                                                            */
/* !File            : plook_u8u16u16n14u32n31_binca_f.c                       */
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
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Mar 10 16:09:00 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/plook_u8u16$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   ADELVARE                               $$Date::   17 Jun 2011 $*/
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

UInt8 plook_u8u16u16n14u32n31_binca_f(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, UInt32 *localfraction)
{
  UInt8 localbpIndex;
  UInt16 localuCast;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Process out of range input: 'Clip to range'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'ACTEMS_FloorF'
   */
  if (localu > 3U) {
    localuCast = MAX_uint16_T;
  } else {
    localuCast = (localu << 14U);
  }

  if ((((UInt32)localu) << 14U) < ((UInt32)localbp[0U])) {
    localbpIndex = 0U;
    *localfraction = 0U;
  } else if (localuCast < localbp[localmaxIndex]) {
    localbpIndex = binsearch_u8u16(localuCast, localbp, (localmaxIndex + 1U) >>
      1U, localmaxIndex);
    *localfraction = div_repeat_u32((((UInt32)localu) << 14U) - ((UInt32)
      localbp[(UInt32)localbpIndex]), (UInt32)((UInt16)(((UInt32)
      localbp[((UInt32)localbpIndex) + 1U]) - ((UInt32)localbp[(UInt32)
      localbpIndex]))), 31U);
  } else {
    localbpIndex = (UInt8)localmaxIndex;
    *localfraction = 0U;
  }

  return localbpIndex;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

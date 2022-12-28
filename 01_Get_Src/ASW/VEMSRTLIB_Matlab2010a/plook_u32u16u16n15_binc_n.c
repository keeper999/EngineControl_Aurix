/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : plook_u32u16u16n15_binc_n                               */
/*                                                                            */
/* !File            : plook_u32u16u16n15_binc_n.c                             */
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
/*   Code generated on: Thu Aug 30 10:49:36 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/plook_u32u1$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   30 Aug 2012 $*/
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

UInt32 plook_u32u16u16n15_binc_n(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, UInt16 *localfraction)
{
  UInt32 localbpIndex;
  UInt16 localbpLeftVar;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Process out of range input: 'Clip to range'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'nearest'
   */
  if (localu <= localbp[0U]) {
    localbpIndex = 0U;
    *localfraction = 0U;
  } else if (localu < localbp[localmaxIndex]) {
    localbpIndex = binsearch_u32u16(localu, localbp, (localmaxIndex + 1U) >> 1U,
      localmaxIndex);
    localbpLeftVar = localbp[localbpIndex];
    *localfraction = (UInt16)div_u32_near(((UInt32)((UInt16)(((UInt32)
      localu) - ((UInt32)localbpLeftVar)))) << 15U, (UInt32)((UInt16)
      (((UInt32)localbp[localbpIndex + 1U]) - ((UInt32)localbpLeftVar))));
  } else {
    localbpIndex = localmaxIndex - 1U;
    *localfraction = 32768U;
  }

  return localbpIndex;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

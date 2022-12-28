/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : plook_u32u16f_bincpa                                    */
/*                                                                            */
/* !File            : plook_u32u16f_bincpa.c                                  */
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
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Jul 31 10:29:41 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/plook_u32u1$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   01 Aug 2012 $*/
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

UInt32 plook_u32u16f_bincpa(UInt16 localu, const UInt16 localbp[],
  UInt32 localmaxIndex, Float32 *localfraction, UInt32 *localprevIndex)
{
  UInt32 localbpIndex;
  UInt32 localstartIndex;
  UInt16 localbpLeftVar;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Process out of range input: 'Clip to range'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
   */
  if (localu <= localbp[0U]) {
    localbpIndex = 0U;
    *localfraction = 0.0F;
  } else if (localu < localbp[localmaxIndex]) {
    localstartIndex = *localprevIndex;
    localbpIndex = binsearch_u32u16_prevIdx(localu, localbp, localstartIndex,
      localmaxIndex);
    localbpLeftVar = localbp[localbpIndex];
    *localfraction = ((Float32)((UInt16)(((UInt32)localu) - ((UInt32)
      localbpLeftVar)))) / ((Float32)((UInt16)(((UInt32)
      localbp[localbpIndex + 1U]) - ((UInt32)localbpLeftVar))));
  } else {
    localbpIndex = localmaxIndex;
    *localfraction = 0.0F;
  }

  *localprevIndex = localbpIndex;
  return localbpIndex;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

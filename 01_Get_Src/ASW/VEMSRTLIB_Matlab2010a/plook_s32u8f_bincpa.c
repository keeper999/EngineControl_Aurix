/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : plook_s32u8f_bincpa                                     */
/*                                                                            */
/* !File            : plook_s32u8f_bincpa.c                                   */
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
/*   Code generated on: Mon May 28 18:55:36 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/plook_s32u8$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   29 May 2012 $*/
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

SInt32 plook_s32u8f_bincpa(UInt8 localu, const UInt8 localbp[], UInt32
  localmaxIndex, Float32 *localfraction, SInt32 *localprevIndex)
{
  SInt32 localbpIndex;
  UInt32 localstartIndex;
  UInt8 localbpLeftVar;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Process out of range input: 'Clip to range'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
   */
  if (localu <= localbp[0U]) {
    localbpIndex = 0;
    *localfraction = 0.0F;
  } else if (localu < localbp[localmaxIndex]) {
    localstartIndex = (UInt32)(*localprevIndex);
    localbpIndex = binsearch_s32u8_prevIdx(localu, localbp, localstartIndex,
      localmaxIndex);
    localbpLeftVar = localbp[(UInt32)localbpIndex];
    *localfraction = ((Float32)((UInt8)(((UInt32)localu) - ((UInt32)
      localbpLeftVar)))) / ((Float32)((UInt8)(((UInt32)localbp[((UInt32)
      localbpIndex) + 1U]) - ((UInt32)localbpLeftVar))));
  } else {
    localbpIndex = (SInt32)localmaxIndex;
    *localfraction = 0.0F;
  }

  *localprevIndex = localbpIndex;
  return localbpIndex;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

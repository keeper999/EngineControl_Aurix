/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : plook_u32u16f_lincp                                     */
/*                                                                            */
/* !File            : plook_u32u16f_lincp.c                                   */
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
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Mon Jul 16 03:42:42 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/plook_u32u1$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   17 Jul 2012 $*/
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

UInt32 plook_u32u16f_lincp(UInt16 localu, const UInt16 localbp[], UInt32
  localmaxIndex, Float32 *localfraction, UInt32 *localprevIndex)
{
  UInt32 localbpIndex;
  UInt32 localstartIndex;
  UInt16 localbpLeftVar;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Process out of range input: 'Clip to range'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  if (localu <= localbp[0U]) {
    localbpIndex = 0U;
    *localfraction = 0.0F;
  } else if (localu < localbp[localmaxIndex]) {
    localstartIndex = *localprevIndex;
    localbpIndex = linsearch_u32u16(localu, localbp, localstartIndex);
    localbpLeftVar = localbp[localbpIndex];
    *localfraction = ((Float32)((UInt16)(((UInt32)localu) - ((UInt32)
      localbpLeftVar)))) / ((Float32)((UInt16)(((UInt32)
      localbp[localbpIndex + 1U]) - ((UInt32)localbpLeftVar))));
  } else {
    localbpIndex = localmaxIndex - 1U;
    *localfraction = 1.0F;
  }

  *localprevIndex = localbpIndex;
  return localbpIndex;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

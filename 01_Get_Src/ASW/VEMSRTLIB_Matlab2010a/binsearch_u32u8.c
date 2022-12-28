/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : binsearch_u32u8                                         */
/*                                                                            */
/* !File            : binsearch_u32u8.c                                       */
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
/*   Code generated on: Wed Jun 20 16:59:36 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/binsearch_u$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   adelvare                               $$Date::   26 Jun 2012 $*/
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

UInt32 binsearch_u32u8(UInt8 localu, const UInt8 localbp[], UInt32
  localstartIndex, UInt32 localmaxIndex)
{
  UInt32 localbpIndex;
  UInt32 localiRght;
  UInt32 localiLeft;
  UInt32 localbpIdx;

  /* Binary Search */
  localbpIdx = localstartIndex;
  localiLeft = 0U;
  localiRght = localmaxIndex;
  while ((localiRght - localiLeft) > 1U) {
    if (localu < localbp[localbpIdx]) {
      localiRght = localbpIdx;
    } else {
      localiLeft = localbpIdx;
    }

    localbpIdx = ((localiRght + localiLeft) >> 1U);
  }

  localbpIndex = localiLeft;
  return localbpIndex;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : BINARYSEARCH_S16_Near_iL                                */
/*                                                                            */
/* !File            : BINARYSEARCH_S16_Near_iL.c                              */
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
/*   Code generated on: Sun Sep 22 15:31:03 2013                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/BINARYSEARC$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   23 Sep 2013 $*/
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

/*********************************************************************
 * Lookup Binary Search Utility BINARYSEARCH_S16_Near_iL
 */
void BINARYSEARCH_S16_Near_iL( UInt32 *piLeft, SInt16 u, const SInt16 *pData,
  UInt32 iHi)
{
  UInt32 iRght;

  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  iRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    iRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    UInt32 i;

    /* Do a binary search. */
    while (( iRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + iRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        iRght = i;
      } else {
        *piLeft = i;
      }
    }

    /* Adjust the left index, if necessary, so that it always gives */
    /* the index of the data point nearest the current input value. */
    {
      UInt32 diffLeft, diffRght;
      diffLeft = u - pData[*piLeft];
      diffRght = pData[iRght] - u;
      if (diffRght <= diffLeft ) {
        *piLeft = iRght;
      }
    }
  }
}

/* end macro BINARYSEARCH_S16_Near_iL
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

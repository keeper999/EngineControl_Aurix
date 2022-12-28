/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : LookUp_U32_S16                                          */
/*                                                                            */
/* !File            : LookUp_U32_S16.c                                        */
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
/*   Code generated on: Thu Jan 27 11:04:24 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/LookUp_U32_$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   08 Feb 2011 $*/
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

/*********************************************************************
 * Lookup Utility LookUp_U32_S16
 */
void LookUp_U32_S16( UInt32 *pY, const UInt32 *pYData, SInt16 u, const
                    SInt16 *pUData, UInt32 iHi)
{
  UInt32 iLeft;
  UInt32 iRght;
  BINARYSEARCH_S16( &(iLeft), &(iRght), u, pUData, iHi);

  {
    UInt32 lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      SInt16 num;
      SInt16 den;
      den = pUData[iRght];
      den = (SInt16)(den - pUData[iLeft]);
      num = u;
      num = (SInt16)(num - pUData[iLeft]);
      lambda = div_repeat_us32_floor(num << 16U, (SInt32)den, (UInt32)15);
    } else {
      lambda = 0U;
    }

    {
      UInt32 yTemp2;
      UInt32 absDiff;
      (*pY) = pYData[iLeft];
      if (pYData[iRght] >= pYData[iLeft] ) {
        absDiff = pYData[iRght];
        absDiff = absDiff - pYData[iLeft];
        yTemp2 = mul_u32_u32_u32_sr31(lambda, absDiff);
        (*pY) = (*pY) + yTemp2;
      } else {
        absDiff = pYData[iLeft];
        absDiff = absDiff - pYData[iRght];
        yTemp2 = mul_u32_u32_u32_sr31(lambda, absDiff);
        (*pY) = (*pY) - yTemp2;
      }
    }
  }
}

/* end function LookUp_U32_S16
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

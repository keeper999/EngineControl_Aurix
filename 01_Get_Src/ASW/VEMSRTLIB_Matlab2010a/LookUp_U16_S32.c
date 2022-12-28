/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : LookUp_U16_S32                                          */
/*                                                                            */
/* !File            : LookUp_U16_S32.c                                        */
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
/*   Code generated on: Wed Jul 04 17:31:06 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/LookUp_U16_$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   05 Jul 2012 $*/
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
 * Lookup Utility LookUp_U16_S32
 */
void LookUp_U16_S32( UInt16 *pY, const UInt16 *pYData, SInt32 u, const
                    SInt32 *pUData, UInt32 iHi)
{
  UInt32 iLeft;
  UInt32 iRght;
  BINARYSEARCH_S32( &(iLeft), &(iRght), u, pUData, iHi);

  {
    UInt32 lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      SInt32 num;
      SInt32 den;
      den = pUData[iRght];
      den = den - pUData[iLeft];
      num = u;
      num = num - pUData[iLeft];
      lambda = div_repeat_us32_floor(num, den, (UInt32)31);
    } else {
      lambda = 0U;
    }

    {
      UInt16 yTemp2;
      UInt16 absDiff;
      (*pY) = pYData[iLeft];
      if (pYData[iRght] >= pYData[iLeft] ) {
        absDiff = pYData[iRght];
        absDiff = (UInt16)(((UInt32)absDiff) - ((UInt32)pYData[iLeft]));
        yTemp2 = (UInt16)mul_u32_u32_u32_sr31(lambda, (UInt32)absDiff);
        (*pY) = (UInt16)(((UInt32)(*pY)) + ((UInt32)yTemp2));
      } else {
        absDiff = pYData[iLeft];
        absDiff = (UInt16)(((UInt32)absDiff) - ((UInt32)pYData[iRght]));
        yTemp2 = (UInt16)mul_u32_u32_u32_sr31(lambda, (UInt32)absDiff);
        (*pY) = (UInt16)(((UInt32)(*pY)) - ((UInt32)yTemp2));
      }
    }
  }
}

/* end function LookUp_U16_S32
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

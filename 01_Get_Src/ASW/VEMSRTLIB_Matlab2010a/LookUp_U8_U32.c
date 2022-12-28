/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : LookUp_U8_U32                                           */
/*                                                                            */
/* !File            : LookUp_U8_U32.c                                         */
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
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Fri Mar 04 16:00:12 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/LookUp_U8_U$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   07 Mar 2011 $*/
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
 * Lookup Utility LookUp_U8_U32
 */
void LookUp_U8_U32( UInt8 *pY, const UInt8 *pYData, UInt32 u, const
                   UInt32 *pUData, UInt32 iHi)
{
  UInt32 iLeft;
  UInt32 iRght;
  BINARYSEARCH_U32( &(iLeft), &(iRght), u, pUData, iHi);

  {
    UInt32 lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      UInt32 num;
      UInt32 den;
      den = pUData[iRght];
      den = den - pUData[iLeft];
      num = u;
      num = num - pUData[iLeft];
      lambda = div_repeat_u32(num, den, (UInt32)31);
    } else {
      lambda = 0U;
    }

    {
      UInt8 yTemp2;
      UInt8 absDiff;
      (*pY) = pYData[iLeft];
      if (pYData[iRght] >= pYData[iLeft] ) {
        absDiff = pYData[iRght];
        absDiff = (UInt8)(((UInt32)absDiff) - ((UInt32)pYData[iLeft]));
        yTemp2 = (UInt8)mul_u32_u32_u32_sr31(lambda, (UInt32)absDiff);
        (*pY) = (UInt8)(((UInt32)(*pY)) + ((UInt32)yTemp2));
      } else {
        absDiff = pYData[iLeft];
        absDiff = (UInt8)(((UInt32)absDiff) - ((UInt32)pYData[iRght]));
        yTemp2 = (UInt8)mul_u32_u32_u32_sr31(lambda, (UInt32)absDiff);
        (*pY) = (UInt8)(((UInt32)(*pY)) - ((UInt32)yTemp2));
      }
    }
  }
}

/* end function LookUp_U8_U32
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

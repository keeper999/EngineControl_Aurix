/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : LookUp_U32_U16                                          */
/*                                                                            */
/* !File            : LookUp_U32_U16.c                                        */
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/LookUp_U32_$*/
/* $Revision::   1.1                                                         $*/
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

/*********************************************************************
 * Lookup Utility LookUp_U32_U16
 */
void LookUp_U32_U16( UInt32 *pY, const UInt32 *pYData, UInt16 u, const
                    UInt16 *pUData, UInt32 iHi)
{
  UInt32 iLeft;
  UInt32 iRght;
  BINARYSEARCH_U16( &(iLeft), &(iRght), u, pUData, iHi);

  {
    UInt32 lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      UInt16 num;
      UInt16 den;
      den = pUData[iRght];
      den = (UInt16)(((UInt32)den) - ((UInt32)pUData[iLeft]));
      num = u;
      num = (UInt16)(((UInt32)num) - ((UInt32)pUData[iLeft]));
      lambda = div_repeat_u32(((UInt32)num) << 16U, (UInt32)den, (UInt32)
        15);
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

/* end function LookUp_U32_U16
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

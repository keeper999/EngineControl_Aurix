/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : Look2D_U32_U16_U8                                       */
/*                                                                            */
/* !File            : Look2D_U32_U16_U8.c                                     */
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
/*   Code generated on: Mon Feb 07 17:32:18 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/Look2D_U32_$*/
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
 * Lookup 2D Lookup Utility Look2D_U32_U16_U8
 */
void Look2D_U32_U16_U8( UInt32 *pY, const UInt32 *pYData, UInt16 u0, const
  UInt16 *pU0Data, UInt32 iHiU0, UInt8 u1, const UInt8 *pU1Data,
  UInt32 iHiU1)
{
  UInt32 iLeftU0, iRghtU0, iLeftU1, iRghtU1;
  BINARYSEARCH_U16( &(iLeftU0), &(iRghtU0), u0, pU0Data, iHiU0);
  BINARYSEARCH_U8( &(iLeftU1), &(iRghtU1), u1, pU1Data, iHiU1);

  {
    UInt16 u0Left = pU0Data[iLeftU0];
    UInt16 u0Rght = pU0Data[iRghtU0];
    UInt8 u1Left = pU1Data[iLeftU1];
    UInt8 u1Rght = pU1Data[iRghtU1];
    UInt32 yTemp;
    UInt32 yLeftLeft;
    UInt32 yLeftRght;
    UInt32 yRghtLeft;
    UInt32 yRghtRght;
    UInt32 u1Lambda;
    UInt32 u0Lambda;
    if (u1Rght > u1Left ) {
      UInt8 num;
      UInt8 den;
      den = u1Rght;
      den = (UInt8)(((UInt32)den) - ((UInt32)u1Left));
      num = u1;
      num = (UInt8)(((UInt32)num) - ((UInt32)u1Left));
      u1Lambda = div_repeat_u32(((UInt32)num) << 24U, (UInt32)den, (UInt32)
        7);
    } else {
      u1Lambda = 0U;
    }

    if (u0Rght > u0Left ) {
      UInt16 num;
      UInt16 den;
      den = u0Rght;
      den = (UInt16)(((UInt32)den) - ((UInt32)u0Left));
      num = u0;
      num = (UInt16)(((UInt32)num) - ((UInt32)u0Left));
      u0Lambda = div_repeat_u32(((UInt32)num) << 16U, (UInt32)den, (UInt32)
        15);
    } else {
      u0Lambda = 0U;
    }

    iHiU0++;
    iLeftU1 *= iHiU0;
    iRghtU1 *= iHiU0;
    yRghtLeft = pYData[(iRghtU0+iLeftU1)];
    yRghtRght = pYData[(iRghtU0+iRghtU1)];
    yLeftLeft = pYData[(iLeftU0+iLeftU1)];
    yLeftRght = pYData[(iLeftU0+iRghtU1)];

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the left u0
     */
    {
      UInt32 yTemp2;
      UInt32 absDiff;
      (*pY) = yLeftLeft;
      if (yLeftRght >= yLeftLeft ) {
        absDiff = yLeftRght;
        absDiff = absDiff - yLeftLeft;
        yTemp2 = mul_u32_u32_u32_sr31(u1Lambda, absDiff);
        (*pY) = (*pY) + yTemp2;
      } else {
        absDiff = yLeftLeft;
        absDiff = absDiff - yLeftRght;
        yTemp2 = mul_u32_u32_u32_sr31(u1Lambda, absDiff);
        (*pY) = (*pY) - yTemp2;
      }
    }

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the right u0
     */
    {
      UInt32 yTemp2;
      UInt32 absDiff;
      yTemp = yRghtLeft;
      if (yRghtRght >= yRghtLeft ) {
        absDiff = yRghtRght;
        absDiff = absDiff - yRghtLeft;
        yTemp2 = mul_u32_u32_u32_sr31(u1Lambda, absDiff);
        yTemp = yTemp + yTemp2;
      } else {
        absDiff = yRghtLeft;
        absDiff = absDiff - yRghtRght;
        yTemp2 = mul_u32_u32_u32_sr31(u1Lambda, absDiff);
        yTemp = yTemp - yTemp2;
      }
    }

    /*
     * Interpolate along u0 variable
     *    with the u1 variable locked on its interpolated value
     */
    {
      UInt32 yTemp2;
      UInt32 absDiff;
      if (yTemp >= (*pY) ) {
        absDiff = yTemp;
        absDiff = absDiff - (*pY);
        yTemp2 = mul_u32_u32_u32_sr31(u0Lambda, absDiff);
        (*pY) = (*pY) + yTemp2;
      } else {
        absDiff = (*pY);
        absDiff = absDiff - yTemp;
        yTemp2 = mul_u32_u32_u32_sr31(u0Lambda, absDiff);
        (*pY) = (*pY) - yTemp2;
      }
    }
  }
}

/* end function Look2D_U32_U16_U8
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : Look2D_S32_U16_U8                                       */
/*                                                                            */
/* !File            : Look2D_S32_U16_U8.c                                     */
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
/*   Code generated on: Thu Nov 04 10:57:04 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/Look2D_S32_$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   09 Nov 2010 $*/
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
 * Lookup 2D Lookup Utility Look2D_S32_U16_U8
 */
void Look2D_S32_U16_U8( SInt32 *pY, const SInt32 *pYData, UInt16 u0, const
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
    SInt32 yTemp;
    SInt32 yLeftLeft;
    SInt32 yLeftRght;
    SInt32 yRghtLeft;
    SInt32 yRghtRght;
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
    (*pY) = yLeftRght;
    (*pY) = (*pY) - yLeftLeft;
    (*pY) = mul_s32_s32_u32_sr31((*pY), u1Lambda);
    (*pY) = (*pY) + yLeftLeft;

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the right u0
     */
    yTemp = yRghtRght;
    yTemp = yTemp - yRghtLeft;
    yTemp = mul_s32_s32_u32_sr31(yTemp, u1Lambda);
    yTemp = yTemp + yRghtLeft;

    /*
     * Interpolate along u0 variable
     *    with the u1 variable locked on its interpolated value
     */
    {
      SInt32 tempDiff;
      SInt32 tempConversion;
      tempConversion = (*pY);
      tempDiff = yTemp;
      tempDiff = tempDiff - (*pY);
      (*pY) = mul_s32_s32_u32_sr31(tempDiff, u0Lambda);
      (*pY) = (*pY) + tempConversion;
    }
  }
}

/* end function Look2D_S32_U16_U8
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

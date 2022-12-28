/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : Look2D_U8_U32_U16                                       */
/*                                                                            */
/* !File            : Look2D_U8_U32_U16.c                                     */
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/Look2D_U8_U$*/
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
 * Lookup 2D Lookup Utility Look2D_U8_U32_U16
 */
void Look2D_U8_U32_U16( UInt8 *pY, const UInt8 *pYData, UInt32 u0, const
  UInt32 *pU0Data, UInt32 iHiU0, UInt16 u1, const UInt16 *pU1Data,
  UInt32 iHiU1)
{
  UInt32 iLeftU0, iRghtU0, iLeftU1, iRghtU1;
  BINARYSEARCH_U32( &(iLeftU0), &(iRghtU0), u0, pU0Data, iHiU0);
  BINARYSEARCH_U16( &(iLeftU1), &(iRghtU1), u1, pU1Data, iHiU1);

  {
    UInt32 u0Left = pU0Data[iLeftU0];
    UInt32 u0Rght = pU0Data[iRghtU0];
    UInt16 u1Left = pU1Data[iLeftU1];
    UInt16 u1Rght = pU1Data[iRghtU1];
    UInt8 yTemp;
    UInt8 yLeftLeft;
    UInt8 yLeftRght;
    UInt8 yRghtLeft;
    UInt8 yRghtRght;
    UInt32 u0Lambda;
    if (u0Rght > u0Left ) {
      UInt32 num;
      UInt32 den;
      den = u0Rght;
      den = den - u0Left;
      num = u0;
      num = num - u0Left;
      u0Lambda = div_repeat_u32(num, den, (UInt32)31);
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
    INTERPOLATE_U8_U16( pY, yLeftLeft, yLeftRght, u1, u1Left, u1Rght);

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the right u0
     */
    INTERPOLATE_U8_U16( (&(yTemp)), yRghtLeft, yRghtRght, u1, u1Left, u1Rght);

    /*
     * Interpolate along u0 variable
     *    with the u1 variable locked on its interpolated value
     */
    {
      UInt8 yTemp2;
      UInt8 absDiff;
      if (yTemp >= (*pY) ) {
        absDiff = yTemp;
        absDiff = (UInt8)(((UInt32)absDiff) - ((UInt32)(*pY)));
        yTemp2 = (UInt8)mul_u32_u32_u32_sr31(u0Lambda, (UInt32)absDiff);
        (*pY) = (UInt8)(((UInt32)(*pY)) + ((UInt32)yTemp2));
      } else {
        absDiff = (*pY);
        absDiff = (UInt8)(((UInt32)absDiff) - ((UInt32)yTemp));
        yTemp2 = (UInt8)mul_u32_u32_u32_sr31(u0Lambda, (UInt32)absDiff);
        (*pY) = (UInt8)(((UInt32)(*pY)) - ((UInt32)yTemp2));
      }
    }
  }
}

/* end function Look2D_U8_U32_U16
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

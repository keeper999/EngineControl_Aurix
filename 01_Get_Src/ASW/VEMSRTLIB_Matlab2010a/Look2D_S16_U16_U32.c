/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : Look2D_S16_U16_U32                                      */
/*                                                                            */
/* !File            : Look2D_S16_U16_U32.c                                    */
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/Look2D_S16_$*/
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
 * Lookup 2D Lookup Utility Look2D_S16_U16_U32
 */
void Look2D_S16_U16_U32( SInt16 *pY, const SInt16 *pYData, UInt16 u0, const
  UInt16 *pU0Data, UInt32 iHiU0, UInt32 u1, const UInt32 *pU1Data,
  UInt32 iHiU1)
{
  UInt32 iLeftU0, iRghtU0, iLeftU1, iRghtU1;
  BINARYSEARCH_U16( &(iLeftU0), &(iRghtU0), u0, pU0Data, iHiU0);
  BINARYSEARCH_U32( &(iLeftU1), &(iRghtU1), u1, pU1Data, iHiU1);

  {
    UInt16 u0Left = pU0Data[iLeftU0];
    UInt16 u0Rght = pU0Data[iRghtU0];
    UInt32 u1Left = pU1Data[iLeftU1];
    UInt32 u1Rght = pU1Data[iRghtU1];
    SInt16 yTemp;
    SInt16 yLeftLeft;
    SInt16 yLeftRght;
    SInt16 yRghtLeft;
    SInt16 yRghtRght;
    UInt32 u1Lambda;
    if (u1Rght > u1Left ) {
      UInt32 num;
      UInt32 den;
      den = u1Rght;
      den = den - u1Left;
      num = u1;
      num = num - u1Left;
      u1Lambda = div_repeat_u32(num, den, (UInt32)31);
    } else {
      u1Lambda = 0U;
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
    (*pY) = (SInt16)((*pY) - yLeftLeft);
    (*pY) = (SInt16)mul_s32_s32_u32_sr31((SInt32)(*pY), u1Lambda);
    (*pY) = (SInt16)((*pY) + yLeftLeft);

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the right u0
     */
    yTemp = yRghtRght;
    yTemp = (SInt16)(yTemp - yRghtLeft);
    yTemp = (SInt16)mul_s32_s32_u32_sr31((SInt32)yTemp, u1Lambda);
    yTemp = (SInt16)(yTemp + yRghtLeft);

    /*
     * Interpolate along u0 variable
     *    with the u1 variable locked on its interpolated value
     */
    INTERPOLATE_S16_U16( pY, (*pY), yTemp, u0, u0Left, u0Rght);
  }
}

/* end function Look2D_S16_U16_U32
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

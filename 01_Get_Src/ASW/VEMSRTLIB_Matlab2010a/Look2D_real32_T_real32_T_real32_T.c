/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : Look2D_real32_T_real32_T_real32_T                       */
/*                                                                            */
/* !File            : Look2D_real32_T_real32_T_real32_T.c                     */
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
/*   Code generated on: Mon Oct 04 15:33:07 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/Look2D_real$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   04 Oct 2010 $*/
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
 * Lookup 2D Lookup Utility Look2D_real32_T_real32_T_real32_T
 */
void Look2D_real32_T_real32_T_real32_T( Float32 *pY, const Float32 *pYData,
  Float32 u0, const Float32 *pU0Data, UInt32 iHiU0, Float32 u1, const
  Float32 *pU1Data, UInt32 iHiU1)
{
  UInt32 iLeftU0, iRghtU0, iLeftU1, iRghtU1;
  BINARYSEARCH_real32_T( &(iLeftU0), &(iRghtU0), u0, pU0Data, iHiU0);
  BINARYSEARCH_real32_T( &(iLeftU1), &(iRghtU1), u1, pU1Data, iHiU1);

  {
    Float32 u0Left = pU0Data[iLeftU0];
    Float32 u0Rght = pU0Data[iRghtU0];
    Float32 u1Left = pU1Data[iLeftU1];
    Float32 u1Rght = pU1Data[iRghtU1];
    Float32 yTemp;
    Float32 yLeftLeft;
    Float32 yLeftRght;
    Float32 yRghtLeft;
    Float32 yRghtRght;
    Float32 u1Lambda;
    Float32 u0Lambda;
    if (u1Rght > u1Left ) {
      Float32 num;
      Float32 den;
      den = u1Rght;
      den = den - u1Left;
      num = u1;
      num = num - u1Left;
      u1Lambda = num / den;
    } else {
      u1Lambda = 0.0F;
    }

    if (u0Rght > u0Left ) {
      Float32 num;
      Float32 den;
      den = u0Rght;
      den = den - u0Left;
      num = u0;
      num = num - u0Left;
      u0Lambda = num / den;
    } else {
      u0Lambda = 0.0F;
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
      Float32 yLeftCast;
      Float32 yRghtCast;
      yLeftCast = yLeftLeft;
      yRghtCast = yLeftRght;
      yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the right u0
     */
    {
      Float32 yLeftCast;
      Float32 yRghtCast;
      yLeftCast = yRghtLeft;
      yRghtCast = yRghtRght;
      yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
      yTemp = yLeftCast;
    }

    /*
     * Interpolate along u0 variable
     *    with the u1 variable locked on its interpolated value
     */
    {
      Float32 yLeftCast;
      Float32 yRghtCast;
      yLeftCast = (*pY);
      yRghtCast = yTemp;
      yLeftCast += u0Lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

/* end function Look2D_real32_T_real32_T_real32_T
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

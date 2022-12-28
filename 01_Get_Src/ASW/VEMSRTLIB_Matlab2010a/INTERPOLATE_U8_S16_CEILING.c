/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : INTERPOLATE_U8_S16_CEILING                              */
/*                                                                            */
/* !File            : INTERPOLATE_U8_S16_CEILING.c                            */
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
/*   Code generated on: Tue Nov 02 14:21:05 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/INTERPOLATE$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   02 Nov 2010 $*/
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
 * Lookup Interpolation INTERPOLATE_U8_S16_CEILING
 */
void INTERPOLATE_U8_S16_CEILING( UInt8 *pY, UInt8 yL, UInt8 yR, SInt16 x,
  SInt16 xL, SInt16 xR)
{
  SInt32 bigProd;
  UInt8 yDiff;
  SInt16 xNum;
  SInt16 xDen;
  *pY = yL;

  /* If x is not strictly between xR and xL
   * then an interpolation calculation is not necessary x == xL
   * or not valid.  The invalid situation is expected when the input
   * is beyond the left or right end of the table.  The design is
   * that yL holds the correct value for *pY
   * in invalid situations.
   */
  if ((xR > xL) && (x > xL) ) {
    xDen = xR;
    xDen = (SInt16)(xDen - xL);
    xNum = x;
    xNum = (SInt16)(xNum - xL);
    if (yR >= yL ) {
      yDiff = yR;
      yDiff = (UInt8)(((UInt32)yDiff) - ((UInt32)yL));
    } else {
      yDiff = yL;
      yDiff = (UInt8)(((UInt32)yDiff) - ((UInt32)yR));
    }

    bigProd = yDiff * xNum;
    yDiff = (UInt8)div_s32_ceiling(bigProd, (SInt32)xDen);
    if (yR >= yL ) {
      *pY = (UInt8)(((UInt32)*pY) + ((UInt32)yDiff));
    } else {
      *pY = (UInt8)(((UInt32)*pY) - ((UInt32)yDiff));
    }
  }
}

/* end INTERPOLATE_U8_S16_CEILING
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : shared utils                                            */
/*                                                                            */
/* !Module          : INTERPOLATE_U16_S8                                      */
/*                                                                            */
/* !File            : INTERPOLATE_U16_S8.c                                    */
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
/*   Code generated on: Thu Jan 06 15:56:59 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/INTERPOLATE$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   17 Jan 2011 $*/
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
 * Lookup Interpolation INTERPOLATE_U16_S8
 */
void INTERPOLATE_U16_S8( UInt16 *pY, UInt16 yL, UInt16 yR, SInt8 x,
  SInt8 xL, SInt8 xR)
{
  SInt32 bigProd;
  UInt16 yDiff;
  SInt8 xNum;
  SInt8 xDen;
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
    xDen = (SInt8)(xDen - xL);
    xNum = x;
    xNum = (SInt8)(xNum - xL);
    if (yR >= yL ) {
      yDiff = yR;
      yDiff = (UInt16)(((UInt32)yDiff) - ((UInt32)yL));
    } else {
      yDiff = yL;
      yDiff = (UInt16)(((UInt32)yDiff) - ((UInt32)yR));
    }

    bigProd = yDiff * xNum;
    yDiff = (UInt16)div_s32_floor(bigProd, (SInt32)xDen);
    if (yR >= yL ) {
      *pY = (UInt16)(((UInt32)*pY) + ((UInt32)yDiff));
    } else {
      *pY = (UInt16)(((UInt32)*pY) - ((UInt32)yDiff));
    }
  }
}

/* end INTERPOLATE_U16_S8
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

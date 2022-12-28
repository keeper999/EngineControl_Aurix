/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : INTERPOLATE_S8_U8_CEILING                               */
/*                                                                            */
/* !File            : INTERPOLATE_S8_U8_CEILING.c                             */
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
 * Lookup Interpolation INTERPOLATE_S8_U8_CEILING
 */
void INTERPOLATE_S8_U8_CEILING( SInt8 *pY, SInt8 yL, SInt8 yR, UInt8 x,
  UInt8 xL, UInt8 xR)
{
  SInt32 bigProd;
  SInt8 yDiff;
  UInt8 xNum;
  UInt8 xDen;
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
    xDen = (UInt8)(((UInt32)xDen) - ((UInt32)xL));
    xNum = x;
    xNum = (UInt8)(((UInt32)xNum) - ((UInt32)xL));
    yDiff = yR;
    yDiff = (SInt8)(yDiff - yL);
    bigProd = yDiff * xNum;
    yDiff = div_s8s32_ceiling(bigProd, (SInt32)xDen);
    *pY = (SInt8)(*pY + yDiff);
  }
}

/* end INTERPOLATE_S8_U8_CEILING
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

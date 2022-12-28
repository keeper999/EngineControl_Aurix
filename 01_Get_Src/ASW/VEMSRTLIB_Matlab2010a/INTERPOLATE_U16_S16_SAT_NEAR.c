/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : INTERPOLATE_U16_S16_SAT_NEAR                            */
/*                                                                            */
/* !File            : INTERPOLATE_U16_S16_SAT_NEAR.c                          */
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
/*   Code generated on: Thu Mar 24 19:49:03 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/INTERPOLATE$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   ADELVARE                               $$Date::   25 Mar 2011 $*/
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
 * Lookup Interpolation INTERPOLATE_U16_S16_SAT_NEAR
 */
void INTERPOLATE_U16_S16_SAT_NEAR( UInt16 *pY, UInt16 yL, UInt16 yR,
  SInt16 x, SInt16 xL, SInt16 xR)
{
  SInt32 bigProd;
  UInt16 yDiff;
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

    {
      SInt32 rtb_s32_tmp;
      SInt16 rtb_s16_tmp;
      rtb_s32_tmp = xDen - xL;
      if (rtb_s32_tmp > 32767) {
        rtb_s16_tmp = MAX_int16_T;
      } else if (rtb_s32_tmp <= -32768) {
        rtb_s16_tmp = MIN_int16_T;
      } else {
        rtb_s16_tmp = (SInt16)rtb_s32_tmp;
      }

      xDen = rtb_s16_tmp;
    }

    xNum = x;

    {
      SInt32 rtb_s32_tmp;
      SInt16 rtb_s16_tmp;
      rtb_s32_tmp = xNum - xL;
      if (rtb_s32_tmp > 32767) {
        rtb_s16_tmp = MAX_int16_T;
      } else if (rtb_s32_tmp <= -32768) {
        rtb_s16_tmp = MIN_int16_T;
      } else {
        rtb_s16_tmp = (SInt16)rtb_s32_tmp;
      }

      xNum = rtb_s16_tmp;
    }

    if (yR >= yL ) {
      yDiff = yR;

      {
        UInt32 rtb_u32_q;
        UInt32 rtb_u32_qY;
        UInt16 rtb_u16_tmp;
        rtb_u32_q = yDiff;
        rtb_u32_qY = rtb_u32_q - ((UInt32)yL);
        if (rtb_u32_qY > rtb_u32_q) {
          rtb_u32_qY = 0U;
        }

        if (rtb_u32_qY > 65535U) {
          rtb_u16_tmp = MAX_uint16_T;
        } else {
          rtb_u16_tmp = (UInt16)rtb_u32_qY;
        }

        yDiff = rtb_u16_tmp;
      }
    } else {
      yDiff = yL;

      {
        UInt32 rtb_u32_q;
        UInt32 rtb_u32_qY;
        UInt16 rtb_u16_tmp;
        rtb_u32_q = yDiff;
        rtb_u32_qY = rtb_u32_q - ((UInt32)yR);
        if (rtb_u32_qY > rtb_u32_q) {
          rtb_u32_qY = 0U;
        }

        if (rtb_u32_qY > 65535U) {
          rtb_u16_tmp = MAX_uint16_T;
        } else {
          rtb_u16_tmp = (UInt16)rtb_u32_qY;
        }

        yDiff = rtb_u16_tmp;
      }
    }

    bigProd = yDiff * xNum;

    {
      SInt32 rtb_s32_tmp;
      UInt16 rtb_u16_tmp;
      rtb_s32_tmp = div_s32_sat_near(bigProd, (SInt32)xDen);
      if (rtb_s32_tmp <= 0) {
        rtb_u16_tmp = 0U;
      } else if (rtb_s32_tmp > 65535) {
        rtb_u16_tmp = MAX_uint16_T;
      } else {
        rtb_u16_tmp = (UInt16)rtb_s32_tmp;
      }

      yDiff = rtb_u16_tmp;
    }

    if (yR >= yL ) {
      {
        UInt32 rtb_u32_tmp;
        UInt16 rtb_u16_tmp;
        rtb_u32_tmp = ((UInt32)*pY) + ((UInt32)yDiff);
        if (rtb_u32_tmp > 65535U) {
          rtb_u16_tmp = MAX_uint16_T;
        } else {
          rtb_u16_tmp = (UInt16)rtb_u32_tmp;
        }

        *pY = rtb_u16_tmp;
      }
    } else {
      {
        UInt32 rtb_u32_q;
        UInt32 rtb_u32_qY;
        UInt16 rtb_u16_tmp;
        rtb_u32_q = *pY;
        rtb_u32_qY = rtb_u32_q - ((UInt32)yDiff);
        if (rtb_u32_qY > rtb_u32_q) {
          rtb_u32_qY = 0U;
        }

        if (rtb_u32_qY > 65535U) {
          rtb_u16_tmp = MAX_uint16_T;
        } else {
          rtb_u16_tmp = (UInt16)rtb_u32_qY;
        }

        *pY = rtb_u16_tmp;
      }
    }
  }
}

/* end INTERPOLATE_U16_S16_SAT_NEAR
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

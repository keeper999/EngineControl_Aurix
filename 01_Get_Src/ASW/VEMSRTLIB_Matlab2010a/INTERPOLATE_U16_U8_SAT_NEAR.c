/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : INTERPOLATE_U16_U8_SAT_NEAR                             */
/*                                                                            */
/* !File            : INTERPOLATE_U16_U8_SAT_NEAR.c                           */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Unspecified (assume 32-bit Generic)")*/
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
/*   Tool             : RTW-EC 7.2  (R2008b)  04-Aug-2008                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Fri Jan 15 16:03:37 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/INTERPOLATE$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   17 Oct 2012 $*/
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
 * Lookup Interpolation INTERPOLATE_U16_U8_SAT_NEAR
 */
void INTERPOLATE_U16_U8_SAT_NEAR( UInt16 *pY, UInt16 yL, UInt16 yR,
  UInt8 x, UInt8 xL, UInt8 xR)
{
  UInt32 bigProd;
  UInt16 yDiff;
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

    {
      UInt32 rtb_u32_tmp;
      UInt32 rtb_u32_tmp_b;
      UInt8 rtb_u8_tmp;
      rtb_u32_tmp = (UInt32)xDen;
      rtb_u32_tmp_b = rtb_u32_tmp - ((UInt32)xL);
      if (rtb_u32_tmp_b > rtb_u32_tmp) {
        rtb_u32_tmp_b = (UInt32)0U;
      }

      if (rtb_u32_tmp_b > 255U) {
        rtb_u8_tmp = MAX_uint8_T;
      } else {
        rtb_u8_tmp = (UInt8)rtb_u32_tmp_b;
      }

      xDen = rtb_u8_tmp;
    }

    xNum = x;

    {
      UInt32 rtb_u32_tmp;
      UInt32 rtb_u32_tmp_b;
      UInt8 rtb_u8_tmp;
      rtb_u32_tmp = (UInt32)xNum;
      rtb_u32_tmp_b = rtb_u32_tmp - ((UInt32)xL);
      if (rtb_u32_tmp_b > rtb_u32_tmp) {
        rtb_u32_tmp_b = (UInt32)0U;
      }

      if (rtb_u32_tmp_b > 255U) {
        rtb_u8_tmp = MAX_uint8_T;
      } else {
        rtb_u8_tmp = (UInt8)rtb_u32_tmp_b;
      }

      xNum = rtb_u8_tmp;
    }

    if (yR >= yL ) {
      yDiff = yR;

      {
        UInt32 rtb_u32_tmp;
        UInt32 rtb_u32_tmp_b;
        UInt16 rtb_u16_tmp;
        rtb_u32_tmp = (UInt32)yDiff;
        rtb_u32_tmp_b = rtb_u32_tmp - ((UInt32)yL);
        if (rtb_u32_tmp_b > rtb_u32_tmp) {
          rtb_u32_tmp_b = (UInt32)0U;
        }

        if (rtb_u32_tmp_b > 65535U) {
          rtb_u16_tmp = MAX_uint16_T;
        } else {
          rtb_u16_tmp = (UInt16)rtb_u32_tmp_b;
        }

        yDiff = rtb_u16_tmp;
      }
    } else {
      yDiff = yL;

      {
        UInt32 rtb_u32_tmp;
        UInt32 rtb_u32_tmp_b;
        UInt16 rtb_u16_tmp;
        rtb_u32_tmp = (UInt32)yDiff;
        rtb_u32_tmp_b = rtb_u32_tmp - ((UInt32)yR);
        if (rtb_u32_tmp_b > rtb_u32_tmp) {
          rtb_u32_tmp_b = (UInt32)0U;
        }

        if (rtb_u32_tmp_b > 65535U) {
          rtb_u16_tmp = MAX_uint16_T;
        } else {
          rtb_u16_tmp = (UInt16)rtb_u32_tmp_b;
        }

        yDiff = rtb_u16_tmp;
      }
    }

    bigProd = ((UInt32)yDiff) * ((UInt32)xNum);

    {
      UInt32 rtb_u32_tmp;
      UInt16 rtb_u16_tmp;
      rtb_u32_tmp = div_u32_near(bigProd, (UInt32)xDen);
      if (rtb_u32_tmp > 65535U) {
        rtb_u16_tmp = MAX_uint16_T;
      } else {
        rtb_u16_tmp = (UInt16)rtb_u32_tmp;
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
        UInt32 rtb_u32_tmp;
        UInt32 rtb_u32_tmp_b;
        UInt16 rtb_u16_tmp;
        rtb_u32_tmp = (UInt32)*pY;
        rtb_u32_tmp_b = rtb_u32_tmp - ((UInt32)yDiff);
        if (rtb_u32_tmp_b > rtb_u32_tmp) {
          rtb_u32_tmp_b = (UInt32)0U;
        }

        if (rtb_u32_tmp_b > 65535U) {
          rtb_u16_tmp = MAX_uint16_T;
        } else {
          rtb_u16_tmp = (UInt16)rtb_u32_tmp_b;
        }

        *pY = rtb_u16_tmp;
      }
    }
  }
}

/* end INTERPOLATE_U16_U8_SAT_NEAR
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

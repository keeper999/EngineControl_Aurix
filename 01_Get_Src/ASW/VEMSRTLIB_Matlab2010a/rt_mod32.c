/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : rt_mod32                                                */
/*                                                                            */
/* !File            : rt_mod32.c                                              */
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
/*   Code generated on: Thu Mar 03 14:37:52 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/rt_mod32.c_$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   ADELVARE                               $$Date::   17 Jun 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "rt_mod32.h"
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

/*
 * Calls single-precision version of MOD directly, with no guards against
 * domain error or non-finites
 */
Float32 rt_mod32(const Float32 xr, const Float32 yr)
{
  Float32 zr, yrf, tr, trf, wr;
  if (yr == 0.0F) {
    zr = xr;
  } else {
    yrf = (Float32)ACTEMS_FloorF(yr);
    tr = xr/yr;
    if (yr == yrf) {
      /* Integer denominator.  Use conventional formula.*/
      trf = (Float32)ACTEMS_FloorF(tr);
      zr = xr - trf*yr;
    } else {
      /* Noninteger denominator. Check for nearly integer quotient.*/
      if ((Float32)ACTEMS_FabsF(tr) < 8.388608E+006F) {
        wr = ((tr < 0.0F) ? -(Float32)ACTEMS_FloorF(((Float32)ACTEMS_FabsF(tr) + 0.5F)) :
              (Float32)ACTEMS_FloorF(((Float32)ACTEMS_FabsF(tr) + 0.5F)));
      } else {
        wr = tr;
      }

      if ((Float32)ACTEMS_FabsF(tr - wr) <= ((FLT_EPSILON)*(Float32)ACTEMS_FabsF(tr))) {
        zr = 0.0F;
      } else {
        trf = (Float32)ACTEMS_FloorF(tr);
        zr = (tr - trf)*yr;
      }
    }
  }

  return zr;
}                                      /* end rt_mod32 */

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

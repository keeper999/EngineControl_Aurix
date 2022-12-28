/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : rt_rem32                                                */
/*                                                                            */
/* !File            : rt_rem32.c                                              */
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
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Aug 30 11:55:14 2012                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/rt_rem32.c_$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   adelvare                               $$Date::   03 Oct 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "rt_rem32.h"
#include "ACTEMS_FloorF.h"
#include "ACTEMS_FabsF.h"
#include "ACTEMS_CeilF.h"

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
 * Calls single-precision version of REM directly, with no guards against
 * domain error or non-finites
 */
Float32 rt_rem32(const Float32 xr, const Float32 yr)
{
  Float32 zr, yrf, tr, trf, wr;
  yrf = (yr < 0.0F) ? (Float32)ACTEMS_CeilF(yr) : (Float32)ACTEMS_FloorF(yr);
  tr = xr/yr;
  if (yr == yrf) {
    /* Integer denominator.  Use conventional formula.*/
    trf = (tr < 0.0F) ? (Float32)ACTEMS_CeilF(tr) : (Float32)ACTEMS_FloorF(tr);
    zr = xr - trf*yr;
  } else {
    /* Noninteger denominator. Check for nearly integer quotient.*/
    if (ACTEMS_FabsF(tr) < 8.388608E+006F) {
      wr = ((tr < 0.0F) ? -(Float32)ACTEMS_FloorF((ACTEMS_FabsF(tr) + 0.5F)) :
            (Float32)ACTEMS_FloorF((ACTEMS_FabsF(tr) + 0.5F)));
    } else {
      wr = tr;
    }

    if (ACTEMS_FabsF(tr - wr) <= ((FLT_EPSILON)*ACTEMS_FabsF(tr))) {
      zr = 0.0F;
    } else {
      trf = (tr < 0.0F) ? (Float32)ACTEMS_CeilF(tr) : (Float32)ACTEMS_FloorF
        (tr);
      zr = (tr - trf)*yr;
    }
  }

  return zr;
}                                      /* end rt_rem32 */

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

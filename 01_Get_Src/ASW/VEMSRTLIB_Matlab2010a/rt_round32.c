/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : rt_round32                                              */
/*                                                                            */
/* !File            : rt_round32.c                                            */
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
/*   Tool             : RTW-EC 7.2  (R2008b)  04-Aug-2008                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Fri Dec 04 16:13:21 2009                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/rt_round32.$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   17 Oct 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "rt_round32.h"
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

/* Function: rt_round32 =======================================================
 * Abstract:
 *   Calls single-precision version of ROUND directly, with no guards against
 *   domain error or non-finites
 */
Float32 rt_round32(const Float32 xr)
{
  Float32 zr, axr = (Float32)ACTEMS_FabsF(xr);
  if (axr < 4.503599627E+015F) {
    if (xr < 0.0F) {
      zr = -(Float32)ACTEMS_FloorF(axr + 0.5F);
    } else {
      zr = (Float32)ACTEMS_FloorF(axr + 0.5F);
    }
  } else {
    zr = xr;
  }

  return zr;
}                                      /* end rt_round32 */

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

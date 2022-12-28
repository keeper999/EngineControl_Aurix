/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : mul_wide_su32                                           */
/*                                                                            */
/* !File            : mul_wide_su32.c                                         */
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
/*   Code generated on: Wed Sep 01 15:33:59 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/mul_wide_su$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/

#include "rtwtypes.h"
#include "rtw_shared_utils.h"

#ifndef VEMSRTLIBT_RENESAS_OPT

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

void mul_wide_su32(SInt32 localin0, UInt32 localin2, UInt32
                   *localptrOutBitsHi, UInt32 *localptrOutBitsLo)
{
  UInt32 localoutBitsLo;
  UInt32 localabsIn0;
  UInt32 localin0Hi;
  UInt32 localin1Lo;
  UInt32 localin1Hi;
  UInt32 localproductHiLo;
  UInt32 localproductLoHi;
  localabsIn0 = (UInt32)((localin0 < 0) ? (-localin0) : localin0);
  localin0Hi = (localabsIn0 >> 16);
  localabsIn0 = localabsIn0 & 65535U;
  localin1Hi = (localin2 >> 16);
  localin1Lo = localin2 & 65535U;
  localproductHiLo = localin0Hi * localin1Lo;
  localproductLoHi = localabsIn0 * localin1Hi;
  localabsIn0 = localabsIn0 * localin1Lo;
  localin1Lo = (UInt32)0;
  localoutBitsLo = (localproductLoHi << 16) + localabsIn0;
  if (localoutBitsLo < localabsIn0) {
    localin1Lo = (UInt32)1;
  }

  localabsIn0 = localoutBitsLo;
  localoutBitsLo = (localproductHiLo << 16) + localoutBitsLo;
  if (localoutBitsLo < localabsIn0) {
    localin1Lo = localin1Lo + ((UInt32)1);
  }

  localabsIn0 = (((localin0Hi * localin1Hi) + localin1Lo) + (localproductLoHi >>
    16)) + (localproductHiLo >> 16);
  if (!((localin2 == ((UInt32)0)) || (localin0 >= 0))) {
    localabsIn0 = ~localabsIn0;
    localoutBitsLo = ~localoutBitsLo;
    localoutBitsLo = localoutBitsLo + ((UInt32)1);
    if (localoutBitsLo == ((UInt32)0)) {
      localabsIn0 = localabsIn0 + ((UInt32)1);
    }
  }

  *localptrOutBitsHi = localabsIn0;
  *localptrOutBitsLo = localoutBitsLo;
}

#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

#endif /* VEMSRTLIBT_RENESAS_OPT */

/*-------------------------------- end of file -------------------------------*/

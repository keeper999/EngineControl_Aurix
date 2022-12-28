/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : EngMGslT                                                */
/* !Description     : EngMGslT Software Component                             */
/*                                                                            */
/* !Module          : EngMGslT                                                */
/*                                                                            */
/* !File            : EngMGslT_data.c                                         */
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
/*   Model name       : EngMGslT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /EngMGslT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M05-EngMGslT/5-S$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   31 May 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "EngMGslT.h"
#include "EngMGslT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* Constant parameters (auto storage) */
#define EngMGslT_START_SEC_CONST_UNSPECIFIED
#include "EngMGslT_MemMap.h"
const ConstParam_EngMGslT EngMGslT_ConstP = {
  /* Computed Parameter: InterpolationUsingPr
   * Referenced by: '<S460>/Interpolation Using Prelookup3'
   */
  { 8.499755859E-001F, 9.099731445E-001F, 9.099731445E-001F, 9.099731445E-001F,
    9.099731445E-001F, 8.900146484E-001F, 8.385009766E-001F, 7.069702148E-001F,
    5.786743164E-001F, 5.142211914E-001F, 3.843994141E-001F, 2.999877930E-001F,
    2.584838867E-001F, 2.156982422E-001F, 1.906127930E-001F, 1.500244141E-001F },

  /* Computed Parameter: InterpolationUsing_a
   * Referenced by: '<S465>/Interpolation Using Prelookup3'
   */
  { 8.557128906E-001F, 9.398193359E-001F, 9.401245117E-001F, 9.401245117E-001F,
    9.418945313E-001F, 9.450073242E-001F, 9.749755859E-001F, 1.005004883E+000F,
    1.094970703E+000F, 1.105102539E+000F, 1.084899902E+000F, 1.090087891E+000F,
    1.069885254E+000F, 1.046997070E+000F, 1.013000488E+000F, 9.530029297E-001F },

  /* Computed Parameter: InterpolationUsing_l
   * Referenced by: '<S471>/Interpolation Using Prelookup3'
   */
  { 8.557128906E-001F, 9.398193359E-001F, 9.401245117E-001F, 9.401245117E-001F,
    9.418945313E-001F, 9.450073242E-001F, 9.749755859E-001F, 1.005004883E+000F,
    1.049987793E+000F, 1.049987793E+000F, 1.049987793E+000F, 1.049987793E+000F,
    1.049987793E+000F, 1.046997070E+000F, 1.013000488E+000F, 9.530029297E-001F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S445>/Interpolation Using Prelookup3'
   *   '<S446>/Interpolation Using Prelookup3'
   *   '<S493>/Interpolation Using Prelookup3'
   *   '<S494>/Interpolation Using Prelookup3'
   */
  { 15U, 15U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S504>/Interpolation Using Prelookup3'
   *   '<S505>/Interpolation Using Prelookup3'
   */
  { 15U, 16U }
};
#define EngMGslT_STOP_SEC_CONST_UNSPECIFIED
#include "EngMGslT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

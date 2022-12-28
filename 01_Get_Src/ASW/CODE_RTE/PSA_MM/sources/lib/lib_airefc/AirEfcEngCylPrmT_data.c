/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirEfcEngCylPrmT                                        */
/* !Description     : AirEfcEngCylPrmT Software Component                     */
/*                                                                            */
/* !Module          : AirEfcEngCylPrmT                                        */
/*                                                                            */
/* !File            : AirEfcEngCylPrmT_data.c                                 */
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
/*   Model name       : AirEfcEngCylPrmT_AUTOSAR.mdl                          */
/*   Root subsystem   : /AirEfcEngCylPrmT                                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M04-AirEfcEngCyl$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   29 May 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AirEfcEngCylPrmT.h"
#include "AirEfcEngCylPrmT_private.h"

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
#define AirEfcEngCylPrmT_START_SEC_CONST_UNSPECIFIED
#include "AirEfcEngCylPrmT_MemMap.h"
const ConstParam_AirEfcEngCylPrmT AirEfcEngCylPrmT_ConstP = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S26>/Interpolation Using Prelookup3'
   *   '<S324>/Interpolation Using Prelookup3'
   */
  { 17U, 15U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S42>/Interpolation Using Prelookup3'
   *   '<S45>/Interpolation Using Prelookup3'
   *   '<S52>/Interpolation Using Prelookup3'
   *   '<S102>/Interpolation Using Prelookup3'
   *   '<S154>/Interpolation Using Prelookup3'
   */
  { 17U, 12U },

  /* Computed Parameter: InterpolationUsingPre
   * Referenced by: '<S115>/Interpolation Using Prelookup3'
   */
  { 17U, 10U },

  /* Computed Parameter: InterpolationUsingP_d
   * Referenced by: '<S171>/Interpolation Using Prelookup3'
   */
  { 12U, 12U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S188>/Interpolation Using Prelookup3'
   *   '<S236>/Interpolation Using Prelookup3'
   */
  { 7U, 10U },

  /* Computed Parameter: InterpolationUsingP_p
   * Referenced by: '<S271>/Interpolation Using Prelookup3'
   */
  { 17U, 9U },

  /* Computed Parameter: InterpolationUsingP_a
   * Referenced by: '<S359>/Interpolation Using Prelookup3'
   */
  { 17U, 19U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S413>/Interpolation Using Prelookup3'
   *   '<S431>/Interpolation Using Prelookup3'
   */
  { 12U, 13U }
};
#define AirEfcEngCylPrmT_STOP_SEC_CONST_UNSPECIFIED
#include "AirEfcEngCylPrmT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

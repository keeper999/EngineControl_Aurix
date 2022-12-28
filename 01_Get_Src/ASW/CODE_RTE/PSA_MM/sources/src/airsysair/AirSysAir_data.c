/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirSysAir                                               */
/* !Description     : AirSysAir Software Component                            */
/*                                                                            */
/* !Module          : AirSysAir                                               */
/*                                                                            */
/* !File            : AirSysAir_data.c                                        */
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
/*   Model name       : AirSysAir_AUTOSAR.mdl                                 */
/*   Root subsystem   : /AirSysAir                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M17-AirSysAir/5-$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AirSysAir.h"
#include "AirSysAir_private.h"

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
#define AirSysAir_START_SEC_CONST_UNSPECIFIED
#include "AirSysAir_MemMap.h"
const ConstParam_AirSysAir AirSysAir_ConstP = {
  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S124>/Lookup Table (n-D)'
   */
  { 9U, 8U },

  /* Computed Parameter: LookupTablenD_maxIn_j
   * Referenced by: '<S247>/Lookup Table (n-D)'
   */
  { 7U, 5U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S226>/Logic'
   *   '<S110>/Logic'
   *   '<S162>/Logic'
   *   '<S177>/Logic'
   *   '<S174>/Logic'
   *   '<S175>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 }
};
#define AirSysAir_STOP_SEC_CONST_UNSPECIFIED
#include "AirSysAir_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

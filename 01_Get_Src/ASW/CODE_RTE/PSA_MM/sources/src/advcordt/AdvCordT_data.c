/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvCordT                                                */
/* !Description     : AdvCordT Software Component                             */
/*                                                                            */
/* !Module          : AdvCordT                                                */
/*                                                                            */
/* !File            : AdvCordT_data.c                                         */
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
/*   Model name       : AdvCordT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /AdvCordT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M07-AdvCordT/5-$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvCordT.h"
#include "AdvCordT_private.h"

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
#define AdvCordT_START_SEC_CONST_UNSPECIFIED
#include "AdvCordT_MemMap.h"
const ConstParam_AdvCordT AdvCordT_ConstP = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_0_0_0_0_0'
   *   '<S52>/Cste_1_0_0_0_0_0_1'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_1_0_0_0_0'
   *   '<S52>/Cste_1_1_0_0_0_0_1'
   */
  { 1.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_1_1_0_0_0'
   *   '<S52>/Cste_1_1_1_0_0_0_1'
   */
  { 1.0F, 1.0F, 1.0F, 0.0F, 0.0F, 0.0F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_1_1_1_0_0'
   *   '<S52>/Cste_1_1_1_1_0_0_1'
   */
  { 1.0F, 1.0F, 1.0F, 1.0F, 0.0F, 0.0F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_1_1_1_1_0'
   *   '<S52>/Cste_1_1_1_1_1_0_1'
   */
  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.0F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_1_1_1_1_1_1'
   *   '<S52>/Cste_1_1_1_1_1_1_1'
   */
  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F },

  /* Computed Parameter: Cste_0_60_60_60_60_60
   * Referenced by: '<S52>/Cste_0_60_60_60_60_60'
   */
  { 0.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F },

  /* Computed Parameter: Cste_0_0_60_60_60_60_
   * Referenced by: '<S52>/Cste_0_0_60_60_60_60'
   */
  { 0.0F, 0.0F, 60.0F, 60.0F, 60.0F, 60.0F },

  /* Computed Parameter: Cste_0_0_0_60_60_60_V
   * Referenced by: '<S52>/Cste_0_0_0_60_60_60'
   */
  { 0.0F, 0.0F, 0.0F, 60.0F, 60.0F, 60.0F },

  /* Computed Parameter: Cste_0_0_0_0_60_60_Va
   * Referenced by: '<S52>/Cste_0_0_0_0_60_60'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 60.0F, 60.0F },

  /* Computed Parameter: Cste_0_0_0_0_0_60_Val
   * Referenced by: '<S52>/Cste_0_0_0_0_0_60'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 60.0F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S52>/Cste_0_0_0_0_0_0'
   *   '<S52>/Cste_0_0_0_0_0_0_1'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: Cste_0_36_36_36_36_36
   * Referenced by: '<S52>/Cste_0_36_36_36_36_36'
   */
  { 0.0F, -36.0F, -36.0F, -36.0F, -36.0F, -36.0F },

  /* Computed Parameter: Cste_0_0_36_36_36_36_
   * Referenced by: '<S52>/Cste_0_0_36_36_36_36'
   */
  { 0.0F, 0.0F, -36.0F, -36.0F, -36.0F, -36.0F },

  /* Computed Parameter: Cste_0_0_0_36_36_36_V
   * Referenced by: '<S52>/Cste_0_0_0_36_36_36'
   */
  { 0.0F, 0.0F, 0.0F, -36.0F, -36.0F, -36.0F },

  /* Computed Parameter: Cste_0_0_0_0_36_36_Va
   * Referenced by: '<S52>/Cste_0_0_0_0_36_36'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, -36.0F, -36.0F },

  /* Computed Parameter: Cste_0_0_0_0_0_36_Val
   * Referenced by: '<S52>/Cste_0_0_0_0_0_36'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -36.0F },

  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S42>/Lookup Table (n-D)'
   */
  { 15U, 15U }
};
#define AdvCordT_STOP_SEC_CONST_UNSPECIFIED
#include "AdvCordT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

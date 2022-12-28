/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjAstWupCmp                                            */
/* !Description     : INJECTION CORRECTION IN AFTER START AND WARM UP         */
/*                                                                            */
/* !Module          : InjAstWupCmp                                            */
/*                                                                            */
/* !File            : InjAstWupCmp_data.c                                     */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
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
/*   Code generated on: Mon Feb 18 18:51:55 2013                              */
/*   Model name       : InjAstWupCmp_AUTOCODE.mdl                             */
/*   Model version    : 1.510                                                 */
/*   Root subsystem   : /InjAstWupCmp                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJASTWUPCMP/InjAstWupCmp_$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   22 Feb 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjAstWupCmp.h"
#include "InjAstWupCmp_private.h"

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
const ConstParam_InjAstWupCmp InjAstWupCmp_ConstP = {
  /* Computed Parameter: UnitDelay_X0
   * Referenced by: '<S153>/Unit Delay'
   */
  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S54>/Lookup Table (n-D)'
   *   '<S76>/Lookup Table (n-D)'
   *   '<S96>/Lookup Table (n-D)'
   */
  { 7U, 11U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S120>/Lookup Table (n-D)'
   *   '<S55>/Lookup Table (n-D)'
   *   '<S77>/Lookup Table (n-D)'
   *   '<S97>/Lookup Table (n-D)'
   */
  { 7U, 7U },

  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S143>/Lookup Table (n-D)'
   */
  { 17U, 8U },

  /* Computed Parameter: LookupTablenD_maxIn_k
   * Referenced by: '<S144>/Lookup Table (n-D)'
   */
  { 17U, 11U }
};

/*-------------------------------- end of file -------------------------------*/

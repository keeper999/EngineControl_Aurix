/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjResuCmp                                              */
/* !Description     : InjResuCmp : INJECTION COMPENSATION AFTER CUT OFF       */
/*                                                                            */
/* !Module          : InjResuCmp                                              */
/*                                                                            */
/* !File            : InjResuCmp_data.c                                       */
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
/*   Code generated on: Mon Dec 02 18:06:23 2013                              */
/*   Model name       : InjResuCmp_AUTOCODE.mdl                               */
/*   Model version    : 1.293                                                 */
/*   Root subsystem   : /InjResuCmp                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJRESUCMP/InjResuCmp_data$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   04 Dec 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjResuCmp.h"
#include "InjResuCmp_private.h"

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
const ConstParam_InjResuCmp InjResuCmp_ConstP = {
  /* Computed Parameter: ConstMat_Value
   * Referenced by: '<S54>/ConstMat'
   */
  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S16>/Logic'
   *   '<S17>/Logic'
   *   '<S18>/Logic'
   *   '<S19>/Logic'
   *   '<S20>/Logic'
   *   '<S21>/Logic'
   *   '<S174>/Logic'
   *   '<S175>/Logic'
   *   '<S176>/Logic'
   *   '<S177>/Logic'
   *   '<S178>/Logic'
   *   '<S179>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 },

  /* Computed Parameter: UnitDelay_X0
   * Referenced by: '<S34>/Unit Delay'
   */
  { 1, 1, 1, 1, 1, 1 }
};

/*-------------------------------- end of file -------------------------------*/

/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pFuSp                                                   */
/* !Description     : pFuSp : Fuel Pressure Set Point                         */
/*                                                                            */
/* !Module          : pFuSp                                                   */
/*                                                                            */
/* !File            : pFuSp_data.c                                            */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
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
/*   Code generated on: Thu Dec 20 19:22:07 2012                              */
/*   Model name       : pFuSp_AUTOCODE.mdl                                    */
/*   Model version    : 1.341                                                 */
/*   Root subsystem   : /pFuSp                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/PFUSP/pFuSp_data.c_v      $*/
/* $Revision::   1.3                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   07 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "pFuSp.h"
#include "pFuSp_private.h"

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
const ConstParam_pFuSp pFuSp_ConstP = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S100>/Logic'
   *   '<S121>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0 },

  /* Computed Parameter: Logic_table
   * Referenced by: '<S97>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 }
};

/*-------------------------------- end of file -------------------------------*/

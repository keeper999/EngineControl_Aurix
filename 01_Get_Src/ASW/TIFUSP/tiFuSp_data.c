/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : tiFuSp                                                  */
/* !Description     : CALCUL DU TEMPS D INJECTION                             */
/*                                                                            */
/* !Module          : tiFuSp                                                  */
/*                                                                            */
/* !File            : tiFuSp_data.c                                           */
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
/*   Code generated on: Sun Nov 17 20:13:35 2013                              */
/*   Model name       : tiFuSp_AUTOCODE.mdl                                   */
/*   Model version    : 1.766                                                 */
/*   Root subsystem   : /tiFuSp                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/TIFUSP/tiFuSp_data.c_v    $*/
/* $Revision::   1.12                                                        $*/
/* $Author::   HHAMLAOU                               $$Date::   19 Nov 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "tiFuSp.h"
#include "tiFuSp_private.h"

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
const ConstParam_tiFuSp tiFuSp_ConstP = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S214>/Lookup Table (n-D)'
   *   '<S96>/Lookup Table (n-D)'
   *   '<S122>/Lookup Table (n-D)'
   *   '<S132>/Lookup Table (n-D)'
   *   '<S142>/Lookup Table (n-D)'
   *   '<S160>/Lookup Table (n-D)'
   */
  { 15U, 15U },

  /* Computed Parameter: LookupTablenD_maxIn_b
   * Referenced by: '<S154>/Lookup Table (n-D)'
   */
  { 15U, 7U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S164>/ConstMat'
   *   '<S164>/ConstMat_1'
   *   '<S164>/ConstMat_2'
   *   '<S164>/ConstMat_5'
   *   '<S167>/ConstMat'
   *   '<S167>/ConstMat_1'
   *   '<S167>/ConstMat_2'
   *   '<S167>/ConstMat_4'
   *   '<S189>/ConstMat'
   *   '<S189>/ConstMat_1'
   *   '<S189>/ConstMat_2'
   *   '<S189>/ConstMat_4'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S8>/InjrSys_prm_bDettiInjMin'
   *   '<S88>/ConstMat'
   */
  { 0, 0, 0, 0, 0, 0 }
};

/*-------------------------------- end of file -------------------------------*/

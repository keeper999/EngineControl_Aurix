/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : facFuTran                                               */
/* !Description     : FACFUTRAN : INJECTED FUEL MASS CORRECTION FACTOR DURING LOAD TRANSIENT*/
/*                                                                            */
/* !Module          : facFuTran                                               */
/*                                                                            */
/* !File            : facFuTran_data.c                                        */
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
/*   Code generated on: Sun Oct 20 19:51:56 2013                              */
/*   Model name       : facFuTran_AUTOCODE.mdl                                */
/*   Model version    : 1.539                                                 */
/*   Root subsystem   : /facFuTran                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/FACFUTRAN/facFuTran_data.c$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   22 Oct 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "facFuTran.h"
#include "facFuTran_private.h"

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
const ConstParam_facFuTran facFuTran_ConstP = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S161>/Lookup Table (n-D)'
   *   '<S162>/Lookup Table (n-D)'
   */
  { 8U, 8U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S16>/Logic'
   *   '<S21>/Logic'
   *   '<S38>/Logic'
   *   '<S43>/Logic'
   *   '<S170>/Logic'
   *   '<S202>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 }
};

/*-------------------------------- end of file -------------------------------*/

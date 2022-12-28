/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAT                                                    */
/* !Description     : AFAT Software component                                 */
/*                                                                            */
/* !Module          : AFAT                                                    */
/*                                                                            */
/* !File            : AFAT_data.c                                             */
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
/*   Model name       : AFAT_SWC.mdl                                          */
/*   Root subsystem   : /AFAT                                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   21 Jul 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAT.h"
#include "AFAT_private.h"

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
#define AFAT_START_SEC_CONST_UNSPECIFIED
#include "AFAT_MemMap.h"
const ConstParam_AFAT AFAT_ConstP = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<Root>/_DataStoreBlk_1'
   *   '<Root>/_DataStoreBlk_10'
   *   '<S15>/0_dim_1'
   *   '<S15>/0_dim_64'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<Root>/_DataStoreBlk_13'
   *   '<S15>/Bool5'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<Root>/_DataStoreBlk_15'
   *   '<S15>/Bool8'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<Root>/_DataStoreBlk_8'
   *   '<S84>/Constant10'
   *   '<S390>/Constant10'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<Root>/_DataStoreBlk_17'
   *   '<S15>/Bool10'
   *   '<S84>/Constant7'
   *   '<S390>/Constant7'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<Root>/_DataStoreBlk_3'
   *   '<S15>/Bool11'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
#define AFAT_STOP_SEC_CONST_UNSPECIFIED
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

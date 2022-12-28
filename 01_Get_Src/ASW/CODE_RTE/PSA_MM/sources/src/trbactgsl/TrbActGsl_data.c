/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActGsl                                               */
/* !Description     : TrbActGsl Software Component                            */
/*                                                                            */
/* !Module          : TrbActGsl                                               */
/*                                                                            */
/* !File            : TrbActGsl_data.c                                        */
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
/*   Model name       : TrbActGsl_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActGsl                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M15-TrbActGsl/5-$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   15 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "TrbActGsl.h"
#include "TrbActGsl_private.h"

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
#define TrbActGsl_START_SEC_CONST_UNSPECIFIED
#include "TrbActGsl_MemMap.h"
const ConstParam_TrbActGsl TrbActGsl_ConstP = {
  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S33>/Lookup Table (n-D)'
   */
  { 8U, 15U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S116>/Lookup Table (n-D)'
   *   '<S32>/Lookup Table (n-D)'
   */
  { 15U, 15U },

  /* Computed Parameter: LookupTablenD_maxIn_f
   * Referenced by: '<S47>/Lookup Table (n-D)'
   */
  { 15U, 8U },

  /* Computed Parameter: LookupTablenD_maxIn_l
   * Referenced by: '<S115>/Lookup Table (n-D)'
   */
  { 8U, 8U },

  /* Computed Parameter: Logic_table
   * Referenced by: '<S50>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 }
};
#define TrbActGsl_STOP_SEC_CONST_UNSPECIFIED
#include "TrbActGsl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

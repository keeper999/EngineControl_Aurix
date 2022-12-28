/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvMinT                                                 */
/* !Description     : AdvMinT Software Component                              */
/*                                                                            */
/* !Module          : AdvMinT                                                 */
/*                                                                            */
/* !File            : AdvMinT_data.c                                          */
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
/*   Model name       : AdvMinT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /AdvMinT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M02-AdvMinT/5-S$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   23 Oct 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvMinT.h"
#include "AdvMinT_private.h"

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
#define AdvMinT_START_SEC_CONST_UNSPECIFIED
#include "AdvMinT_MemMap.h"
const ConstParam_AdvMinT AdvMinT_ConstP = {
  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S117>/Lookup Table (n-D)'
   */
  { 15U, 15U },

  /* Computed Parameter: Logic_table
   * Referenced by: '<S19>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 }
};
#define AdvMinT_STOP_SEC_CONST_UNSPECIFIED
#include "AdvMinT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

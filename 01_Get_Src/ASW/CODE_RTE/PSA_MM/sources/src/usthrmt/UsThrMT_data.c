/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : UsThrMT                                                 */
/* !Description     : UsThrMT Software Component                              */
/*                                                                            */
/* !Module          : UsThrMT                                                 */
/*                                                                            */
/* !File            : UsThrMT_data.c                                          */
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
/*   Model name       : UsThrMT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /UsThrMT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M01-UsThrMT/5-SO$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   14 Nov 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "UsThrMT.h"
#include "UsThrMT_private.h"

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
#define UsThrMT_START_SEC_CONST_UNSPECIFIED
#include "UsThrMT_MemMap.h"
const ConstParam_UsThrMT UsThrMT_ConstP = {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S187>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0 },

  /* Computed Parameter: Logic_table_i
   * Referenced by: '<S58>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 }
};
#define UsThrMT_STOP_SEC_CONST_UNSPECIFIED
#include "UsThrMT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

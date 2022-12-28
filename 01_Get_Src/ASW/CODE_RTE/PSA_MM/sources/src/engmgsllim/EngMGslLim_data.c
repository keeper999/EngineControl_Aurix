/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : EngMGslLim                                              */
/* !Description     : EngMGslLim Software Component                           */
/*                                                                            */
/* !Module          : EngMGslLim                                              */
/*                                                                            */
/* !File            : EngMGslLim_data.c                                       */
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
/*   Model name       : EngMGslLim_AUTOSAR.mdl                                */
/*   Root subsystem   : /EngMGslLim                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M16-EngMGslLim/5$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   08 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "EngMGslLim.h"
#include "EngMGslLim_private.h"

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
#define EngMGslLim_START_SEC_CONST_UNSPECIFIED
#include "EngMGslLim_MemMap.h"
const ConstParam_EngMGslLim EngMGslLim_ConstP = {
  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S217>/Lookup Table (n-D)'
   */
  { 7U, 15U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S74>/Logic'
   *   '<S267>/Logic'
   *   '<S279>/Logic'
   *   '<S386>/Logic'
   *   '<S365>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0 }
};
#define EngMGslLim_STOP_SEC_CONST_UNSPECIFIED
#include "EngMGslLim_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

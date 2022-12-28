/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : DmpVlv_H                                                */
/* !Description     : DmpVlv_H Software Component                             */
/*                                                                            */
/* !Module          : DmpVlv_H                                                */
/*                                                                            */
/* !File            : DmpVlv_H_data.c                                         */
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
/*   Model name       : DmpVlv_H_AUTOSAR.mdl                                  */
/*   Root subsystem   : /DmpVlv_H                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M12-DmpVlvH/5-SO$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "DmpVlv_H.h"
#include "DmpVlv_H_private.h"

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
#define DmpVlv_H_START_SEC_CONST_UNSPECIFIED
#include "DmpVlv_H_MemMap.h"
const ConstParam_DmpVlv_H DmpVlv_H_ConstP = {
  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S56>/Lookup Table (n-D)'
   */
  { 7U, 6U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S50>/Logic'
   *   '<S51>/Logic'
   *   '<S89>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 }
};
#define DmpVlv_H_STOP_SEC_CONST_UNSPECIFIED
#include "DmpVlv_H_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

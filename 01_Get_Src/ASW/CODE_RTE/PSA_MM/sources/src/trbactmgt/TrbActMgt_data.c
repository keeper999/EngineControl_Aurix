/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActMgt                                               */
/* !Description     : TrbActMgt Software Component                            */
/*                                                                            */
/* !Module          : TrbActMgt                                               */
/*                                                                            */
/* !File            : TrbActMgt_data.c                                        */
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
/*   Model name       : TrbActMgt_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActMgt                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M13-TrbActMgt/5-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "TrbActMgt.h"
#include "TrbActMgt_private.h"

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
#define TrbActMgt_START_SEC_CONST_UNSPECIFIED
#include "TrbActMgt_MemMap.h"
const ConstParam_TrbActMgt TrbActMgt_ConstP = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S27>/Logic'
   *   '<S41>/Logic'
   *   '<S48>/Logic'
   *   '<S127>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 }
};
#define TrbActMgt_STOP_SEC_CONST_UNSPECIFIED
#include "TrbActMgt_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActSys                                               */
/* !Description     : TrbActSys Software Component                            */
/*                                                                            */
/* !Module          : TrbActSys                                               */
/*                                                                            */
/* !File            : TrbActSys_data.c                                        */
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
/*   Model name       : TrbActSys_AUTOSAR.mdl                                 */
/*   Root subsystem   : /TrbActSys                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M14-TrbActSys/5-$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   15 Jan 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "TrbActSys.h"
#include "TrbActSys_private.h"

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
#define TrbActSys_START_SEC_CONST_UNSPECIFIED
#include "TrbActSys_MemMap.h"
const ConstParam_TrbActSys TrbActSys_ConstP = {
  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S69>/Lookup Table (n-D)'
   */
  { 15U, 15U },

  /* Computed Parameter: LookupTablenD_maxIn_o
   * Referenced by: '<S120>/Lookup Table (n-D)'
   */
  { 8U, 15U }
};
#define TrbActSys_STOP_SEC_CONST_UNSPECIFIED
#include "TrbActSys_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

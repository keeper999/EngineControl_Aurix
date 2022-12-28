/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvMaxT                                                 */
/* !Description     : AdvMaxT Software Component                              */
/*                                                                            */
/* !Module          : AdvMaxT                                                 */
/*                                                                            */
/* !File            : AdvMaxT_data.c                                          */
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
/*   Model name       : AdvMaxT_AUTOSAR.mdl                                   */
/*   Root subsystem   : /AdvMaxT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M04-AdvMaxT/5-S$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   11 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvMaxT.h"
#include "AdvMaxT_private.h"

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
#define AdvMaxT_START_SEC_CONST_UNSPECIFIED
#include "AdvMaxT_MemMap.h"

/* Invariant block signals (auto storage) */
ConstBlockIO_AdvMaxT AdvMaxT_ConstB = {
  { 96U, 96U, 96U, 96U, 96U, 96U }
  /* '<S9>/Data Type Conversion' */
};

const ConstParam_AdvMaxT AdvMaxT_ConstP = {
  /* Computed Parameter: Ext_noCylEng_SC1_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC1'
   */
  { 1U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Ext_noCylEng_SC2_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC2'
   */
  { 1U, 1U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Ext_noCylEng_SC3_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC3'
   */
  { 1U, 1U, 1U, 0U, 0U, 0U },

  /* Computed Parameter: Ext_noCylEng_SC4_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC4'
   */
  { 1U, 1U, 1U, 1U, 0U, 0U },

  /* Computed Parameter: Ext_noCylEng_SC5_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC5'
   */
  { 1U, 1U, 1U, 1U, 1U, 0U },

  /* Computed Parameter: Ext_noCylEng_SC6_Valu
   * Referenced by: '<S58>/Ext_noCylEng_SC6'
   */
  { 1U, 1U, 1U, 1U, 1U, 1U }
};
#define AdvMaxT_STOP_SEC_CONST_UNSPECIFIED
#include "AdvMaxT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

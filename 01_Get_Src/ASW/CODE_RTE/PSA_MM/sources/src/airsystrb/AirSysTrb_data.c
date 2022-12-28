/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirSysTrb                                               */
/* !Description     : AirSysTrb Software Component                            */
/*                                                                            */
/* !Module          : AirSysTrb                                               */
/*                                                                            */
/* !File            : AirSysTrb_data.c                                        */
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
/*   Model name       : AirSysTrb_AUTOSAR.mdl                                 */
/*   Root subsystem   : /AirSysTrb                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M18-AirSysTrb/5-$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   PLCHINAZ                               $$Date::   30 Jun 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AirSysTrb.h"
#include "AirSysTrb_private.h"
#define AirSysTrb_START_SEC_CONST_UNSPECIFIED
#include "AirSysTrb_MemMap.h"

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
const ConstParam_AirSysTrb AirSysTrb_ConstP = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/Logic'
   *   '<S64>/Logic'
   *   '<S65>/Logic'
   *   '<S75>/Logic'
   *   '<S85>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 }
};

#define AirSysTrb_STOP_SEC_CONST_UNSPECIFIED
#include "AirSysTrb_MemMap.h"
/*-------------------------------- end of file -------------------------------*/

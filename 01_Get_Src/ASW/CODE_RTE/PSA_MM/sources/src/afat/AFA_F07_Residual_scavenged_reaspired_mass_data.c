/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA                                                     */
/* !Description     : AFA Software Component                                  */
/*                                                                            */
/* !File            : AFA_F07_Residual_scavenged_reaspired_mass_data.c        */
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
/*   Model name       : AFA_F07_Residual_scavenged_reaspired_mass.mdl         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F07_Residual_scavenged_reaspired_mass.h"
#include "AFA_F07_Residual_scavenged_reaspired_mass_private.h"

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
const ConstParam_AFA_F07_Residual_sca AFA_F07_Residual_scaveng_ConstP = {
  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S18>/Lookup Table (n-D)'
   */
  { 17U, 11U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S28>/Lookup Table (n-D)'
   *   '<S29>/Lookup Table (n-D)'
   */
  { 17U, 24U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S42>/Lookup Table (n-D)'
   *   '<S43>/Lookup Table (n-D)'
   */
  { 17U, 23U },

  /* Computed Parameter: LookupTablenD_maxIn_a
   * Referenced by: '<S56>/Lookup Table (n-D)'
   */
  { 17U, 12U },

  /* Computed Parameter: LookupTablenD_maxIn_l
   * Referenced by: '<S79>/Lookup Table (n-D)'
   */
  { 7U, 24U },

  /* Computed Parameter: LookupTablenD_maxIn_f
   * Referenced by: '<S102>/Lookup Table (n-D)'
   */
  { 7U, 10U }
};
#define AFAT_STOP_SEC_CONST_UNSPECIFIED
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/


/*-------------------------------- end of file -------------------------------*/

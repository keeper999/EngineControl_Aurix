/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : OilTqCf                                                 */
/* !Description     : OIL TORQUE CONFIGURATION                                */
/*                                                                            */
/* !Module          : OilTqCf                                                 */
/*                                                                            */
/* !File            : OilTqCf_data.c                                          */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
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
/*   Code generated on: Sun Oct 21 15:29:22 2012                              */
/*   Model name       : OilTqCf_AUTOCODE.mdl                                  */
/*   Model version    : 1.64                                                  */
/*   Root subsystem   : /OilTqCf                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/OILTQCF_CA/OilTqC$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   25 Oct 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "OilTqCf.h"
#include "OilTqCf_private.h"

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
const ConstParam_OilTqCf OilTqCf_ConstP = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S8>/Lookup Table (n-D)'
   *   '<S9>/Lookup Table (n-D)'
   */
  { 8U, 3U },

  /* Computed Parameter: Logic_table
   * Referenced by: '<S15>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1 },

  /* Computed Parameter: Logic_table_f
   * Referenced by: '<S23>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0 }
};

/*-------------------------------- end of file -------------------------------*/

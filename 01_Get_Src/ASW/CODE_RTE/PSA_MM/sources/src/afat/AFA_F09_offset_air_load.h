/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F09_offset_air_load                                 */
/*                                                                            */
/* !File            : AFA_F09_offset_air_load.h                               */
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
/*   Model name       : AFA_F09_offset_air_load.mdl                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F09_offset_air_load_h_
#define RTW_HEADER_AFA_F09_offset_air_load_h_
#ifndef AFA_F09_offset_air_load_COMMON_INCLUDES_
# define AFA_F09_offset_air_load_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "ACTEMS_FloorF.h"
#include "ACTEMS_LdexpF.h"
#endif                                 /* AFA_F09_offset_air_load_COMMON_INCLUDES_ */

#include "AFA_F09_offset_air_load_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Declare data in section "SEC_VAR_UNSPECIFIED" */


#define AFAT_START_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  RTW declares the memory for these signals
 * and exports their symbols.
 *
 */
extern UInt32 AFA_facOfsEfcGrd_pDsThr;/* '<Root>/Sum2' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

extern SInt16 AFA_facOfsGrdEfc_agCkEx;/* '<Root>/Product12' */
extern SInt16 AFA_facOfsGrdEfc_agCkIn;/* '<Root>/Product15' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F09_offset_air_load(const UInt16 *rtu_AFA_facTAirUsInVl9,
  const UInt16 *rtu_AFA_facTBurnCyl, const SInt16
  *rtu_AFA_facTBurnGrdCyl_agCkEx, const SInt16 *rtu_AFA_facTBurnGrdCyl_agCkIn,
  const UInt16 *rtu_AFA_rMassBurnRg, const UInt16 *rtu_AFA_rMassBurn, const
  SInt16 *rtu_AFA_rMassBurn_agCkE9, const SInt16 *rtu_AFA_rMassBurn_agCkI9,
  const SInt16 *rtu_AFA_mGrdBurnRspg_p9, const UInt16 *rtu_AFA_facAirScv,
  const UInt16 *rtu_AFA_mGrdAirScvTot_p9, UInt32
  *rty_AFA_facOfsEfcGrd_pDsThr, SInt16 *rty_AFA_facOfsGrdEfc_agCkEx, SInt16
  *rty_AFA_facOfsGrdEfc_agCkIn);

/* Model reference registration function */
extern void mr_AFA_F09_offset_ai_initialize(void);

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : AFA_F09_offset_air_load
 */

/*-
 * Requirements for '<Root>': AFA_F09_offset_air_load
 */
#endif                                 /* RTW_HEADER_AFA_F09_offset_air_load_h_ */

/*-------------------------------- end of file -------------------------------*/

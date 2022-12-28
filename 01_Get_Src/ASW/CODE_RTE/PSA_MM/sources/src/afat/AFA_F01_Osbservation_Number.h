/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F01_Osbservation_Number                             */
/*                                                                            */
/* !File            : AFA_F01_Osbservation_Number.h                           */
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
/*   Model name       : AFA_F01_Osbservation_Number.mdl                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F01_Osbservation_Number_h_
#define RTW_HEADER_AFA_F01_Osbservation_Number_h_
#ifndef AFA_F01_Osbservation_Number_COMMON_INCLUDES_
# define AFA_F01_Osbservation_Number_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F01_Osbservation_Number_import.h"
#include "rtw_shared_utils.h"
#include "rt_MIN.h"
#endif                                 /* AFA_F01_Osbservation_Number_COMMON_INCLUDES_ */

#include "AFA_F01_Osbservation_Number_types.h"

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


#define AFAT_START_SEC_INTERNAL_VAR_8BIT
#include "AFAT_MemMap.h"


/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  RTW declares the memory for these signals
 * and exports their symbols.
 *
 */
extern UInt8 AFA_noObsDoneIdl;       /* '<Root>/Switch' */
extern UInt8 AFA_noObsDoneIdlTmp;    /* '<Root>/Signal Conversion2' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  RTW declares the memory for these states
 * and exports their symbols.
 *
 */
extern UInt8 AFA_prm_noObsDonePrev_MP;/* '<Root>/Data Store Memory' */
extern UInt8 AFA_prm_noObsDoneRaw_MP[9];/* '<Root>/Data Store Memory1' */

#define AFAT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F01_Osbservation_Number(const Boolean
  *rtu_IdlSys_bAcvIdlCtl, const UInt16 *rtu_Ext_nEng, const UInt16
  *rtu_EngM_rTotLdExCor, const UInt8 rtu_AFA_prm_noObsDoneMat_PIM[9], const
  UInt8 *rtu_AFA_noObsDoneIdlPrev, const Boolean *rtu_EOM_bSpcInjMod, const
  UInt8 *rtu_AFA_noObsSpcInjModPrev, const UInt16 *rtu_AFA_noAdpEfc, UInt8
  rty_AFA_prm_noObsDoneMat_PIM1[9], Boolean *rty_AFA_bEngStopAuth, UInt8
  *rty_AFA_noObsDoneIdlTmp, UInt8 *rty_AFA_noObsSpcInjMod);

/* Model reference registration function */
extern void mr_AFA_F01_Osbservat_initialize(void);

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
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/AFA_nEngRef1_A' : Unused code path elimination
 * Block '<Root>/AFA_rLdRef1_A' : Unused code path elimination
 * Block '<S1>/BKPT1' : Unused code path elimination
 * Block '<S1>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S1>/TABLE' : Unused code path elimination
 * Block '<S2>/BKPT1' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S2>/TABLE' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<Root>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<Root>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<Root>/Signal Conversion5' : Eliminate redundant signal conversion block
 */

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
 * '<Root>' : AFA_F01_Osbservation_Number
 * '<S1>'   : AFA_F01_Osbservation_Number/Carto_1D
 * '<S2>'   : AFA_F01_Osbservation_Number/Carto_1D1
 * '<S3>'   : AFA_F01_Osbservation_Number/One_Based_Assignment_2D
 * '<S4>'   : AFA_F01_Osbservation_Number/One_Based_Selector_2D
 */

/*-
 * Requirements for '<Root>': AFA_F01_Osbservation_Number
 */
#endif                                 /* RTW_HEADER_AFA_F01_Osbservation_Number_h_ */

/*-------------------------------- end of file -------------------------------*/

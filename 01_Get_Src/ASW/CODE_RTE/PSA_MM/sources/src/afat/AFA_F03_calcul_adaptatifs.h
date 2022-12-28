/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F03_calcul_adaptatifs                               */
/*                                                                            */
/* !File            : AFA_F03_calcul_adaptatifs.h                             */
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
/*   Model name       : AFA_F03_calcul_adaptatifs.mdl                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jan 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F03_calcul_adaptatifs_h_
#define RTW_HEADER_AFA_F03_calcul_adaptatifs_h_
#ifndef AFA_F03_calcul_adaptatifs_COMMON_INCLUDES_
# define AFA_F03_calcul_adaptatifs_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFA_F03_calcul_adaptatifs_import.h"
#endif                                 /* AFA_F03_calcul_adaptatifs_COMMON_INCLUDES_ */

#include "AFA_F03_calcul_adaptatifs_types.h"

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
extern SInt32 AFA_facSlopInjGainPrev; /* '<Root>/Signal Conversion3' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

extern SInt16 AFA_arEffThrOfsPrev;    /* '<Root>/Signal Conversion4' */
extern SInt16 AFA_facIvsInjGainPrev;  /* '<Root>/Signal Conversion' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_8BIT
#include "AFAT_MemMap.h"

extern SInt8 AFA_tiOffInjPrev;        /* '<Root>/Signal Conversion2' */
extern SInt8 AFA_facArEffThrOfs1Prev; /* '<Root>/Signal Conversion5' */
extern SInt8 AFA_facArEffThrOfs2Prev; /* '<Root>/Signal Conversion6' */
extern SInt8 AFA_facArEffThrOfs3Prev; /* '<Root>/Signal Conversion7' */
extern SInt8 AFA_rCor_arEffEGRVlvPrev;/* '<Root>/Signal Conversion8' */
extern SInt8 AFA_agCkOpInVlvOfsPrev;  /* '<Root>/Signal Conversion1' */
extern SInt8 AFA_agCkClsExVlvOfsPrev; /* '<Root>/Signal Conversion9' */

#define AFAT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F03_calcul_adaptatifs(const SInt16 rtu_AFA_prm_rErr_PIM[8],
  const SInt8 *rtu_AFA_tiOffInjPrev3, const SInt32 *rtu_AFA_facSlopInjGainP3,
  const SInt16 *rtu_AFA_arEffThrOfsPrev3, const SInt8
  *rtu_AFA_facArEffThrOfs1P3, const SInt8 *rtu_AFA_facArEffThrOfs2P3, const
  SInt8 *rtu_AFA_facArEffThrOfs3P3, const SInt8 *rtu_AFA_rCor_arEffEGRVlvP3,
  const SInt16 *rtu_AFA_facIvsInjGainP3, const SInt8 *rtu_AFA_agCkOpInVlvOfsP3,
  const SInt8 *rtu_AFA_agCkClsExVlvOfsP3, SInt16 *rty_AFA_facIvsInjGai2,
  SInt8 *rty_AFA_tiOffInj3, SInt32 *rty_AFA_facSlopInjGain3, SInt16
  *rty_AFA_arEffThrOf3, SInt8 *rty_AFA_facArEffThrOf12, SInt8
  *rty_AFA_facArEffThrOf22, SInt8 *rty_AFA_facArEffThrOf32, SInt8
  *rty_AFA_rCor_arEffEGRV3, SInt8 *rty_AFA_agCkOpInVlvOf3, SInt8
  *rty_AFA_agCkClsExVlvOf3, SInt8 *rty_AFA_arEffEGRVlvOf3);

/* Model reference registration function */
extern void mr_AFA_F03_calcul_ad_initialize(void);

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
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/Relational Operator' : Unused code path elimination
 * Block '<S1>/Relational Operator1' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Propagation' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Relational Operator' : Unused code path elimination
 * Block '<S2>/Relational Operator1' : Unused code path elimination
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Propagation' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Relational Operator' : Unused code path elimination
 * Block '<S3>/Relational Operator1' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Propagation' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Relational Operator' : Unused code path elimination
 * Block '<S4>/Relational Operator1' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Data Type Propagation' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/Relational Operator' : Unused code path elimination
 * Block '<S5>/Relational Operator1' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Propagation' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Relational Operator' : Unused code path elimination
 * Block '<S6>/Relational Operator1' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Propagation' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Relational Operator' : Unused code path elimination
 * Block '<S7>/Relational Operator1' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Propagation' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Relational Operator' : Unused code path elimination
 * Block '<S8>/Relational Operator1' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Propagation' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Relational Operator' : Unused code path elimination
 * Block '<S9>/Relational Operator1' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Propagation' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Relational Operator' : Unused code path elimination
 * Block '<S10>/Relational Operator1' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S62>/Data Type Propagation' : Unused code path elimination
 * Block '<S34>/Conversion' : Eliminate redundant data type conversion
 * Block '<S36>/Conversion' : Eliminate redundant data type conversion
 * Block '<S37>/Conversion' : Eliminate redundant data type conversion
 * Block '<S39>/Conversion' : Eliminate redundant data type conversion
 * Block '<S40>/Conversion' : Eliminate redundant data type conversion
 * Block '<S42>/Conversion' : Eliminate redundant data type conversion
 * Block '<S43>/Conversion' : Eliminate redundant data type conversion
 * Block '<S46>/Conversion' : Eliminate redundant data type conversion
 * Block '<S49>/Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Conversion' : Eliminate redundant data type conversion
 * Block '<S58>/Conversion' : Eliminate redundant data type conversion
 * Block '<S60>/Conversion' : Eliminate redundant data type conversion
 * Block '<S61>/Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Switch' : Eliminated due to constant selection input
 * Block '<S19>/Switch' : Eliminated due to constant selection input
 * Block '<S20>/Switch' : Eliminated due to constant selection input
 * Block '<S21>/Switch' : Eliminated due to constant selection input
 * Block '<S18>/Add2' : Unused code path elimination
 * Block '<S18>/Constant' : Unused code path elimination
 * Block '<S18>/offset1' : Unused code path elimination
 * Block '<S19>/Add2' : Unused code path elimination
 * Block '<S19>/Constant' : Unused code path elimination
 * Block '<S19>/offset1' : Unused code path elimination
 * Block '<S20>/Add2' : Unused code path elimination
 * Block '<S20>/Constant' : Unused code path elimination
 * Block '<S20>/offset1' : Unused code path elimination
 * Block '<S21>/Add2' : Unused code path elimination
 * Block '<S21>/Constant' : Unused code path elimination
 * Block '<S21>/offset1' : Unused code path elimination
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
 * '<Root>' : AFA_F03_calcul_adaptatifs
 * '<S1>'   : AFA_F03_calcul_adaptatifs/Clamp
 * '<S2>'   : AFA_F03_calcul_adaptatifs/Clamp1
 * '<S3>'   : AFA_F03_calcul_adaptatifs/Clamp2
 * '<S4>'   : AFA_F03_calcul_adaptatifs/Clamp3
 * '<S5>'   : AFA_F03_calcul_adaptatifs/Clamp4
 * '<S6>'   : AFA_F03_calcul_adaptatifs/Clamp5
 * '<S7>'   : AFA_F03_calcul_adaptatifs/Clamp6
 * '<S8>'   : AFA_F03_calcul_adaptatifs/Clamp7
 * '<S9>'   : AFA_F03_calcul_adaptatifs/Clamp8
 * '<S10>'  : AFA_F03_calcul_adaptatifs/Clamp9
 * '<S11>'  : AFA_F03_calcul_adaptatifs/DeadZone2
 * '<S12>'  : AFA_F03_calcul_adaptatifs/Product1
 * '<S13>'  : AFA_F03_calcul_adaptatifs/Product10
 * '<S14>'  : AFA_F03_calcul_adaptatifs/Product2
 * '<S15>'  : AFA_F03_calcul_adaptatifs/Product5
 * '<S16>'  : AFA_F03_calcul_adaptatifs/Product6
 * '<S17>'  : AFA_F03_calcul_adaptatifs/Product7
 * '<S18>'  : AFA_F03_calcul_adaptatifs/SingleToFixdt
 * '<S19>'  : AFA_F03_calcul_adaptatifs/SingleToFixdt1
 * '<S20>'  : AFA_F03_calcul_adaptatifs/SingleToFixdt2
 * '<S21>'  : AFA_F03_calcul_adaptatifs/SingleToFixdt3
 * '<S22>'  : AFA_F03_calcul_adaptatifs/multiplication
 * '<S23>'  : AFA_F03_calcul_adaptatifs/multiplication1
 * '<S24>'  : AFA_F03_calcul_adaptatifs/multiplication10
 * '<S25>'  : AFA_F03_calcul_adaptatifs/multiplication2
 * '<S26>'  : AFA_F03_calcul_adaptatifs/multiplication3
 * '<S27>'  : AFA_F03_calcul_adaptatifs/multiplication4
 * '<S28>'  : AFA_F03_calcul_adaptatifs/multiplication5
 * '<S29>'  : AFA_F03_calcul_adaptatifs/multiplication6
 * '<S30>'  : AFA_F03_calcul_adaptatifs/multiplication7
 * '<S31>'  : AFA_F03_calcul_adaptatifs/multiplication8
 * '<S32>'  : AFA_F03_calcul_adaptatifs/multiplication9
 * '<S33>'  : AFA_F03_calcul_adaptatifs/Clamp/Data Type Conversion Inherited
 * '<S34>'  : AFA_F03_calcul_adaptatifs/Clamp/Data Type Conversion Inherited1
 * '<S35>'  : AFA_F03_calcul_adaptatifs/Clamp/Saturation Dynamic
 * '<S36>'  : AFA_F03_calcul_adaptatifs/Clamp1/Data Type Conversion Inherited
 * '<S37>'  : AFA_F03_calcul_adaptatifs/Clamp1/Data Type Conversion Inherited1
 * '<S38>'  : AFA_F03_calcul_adaptatifs/Clamp1/Saturation Dynamic
 * '<S39>'  : AFA_F03_calcul_adaptatifs/Clamp2/Data Type Conversion Inherited
 * '<S40>'  : AFA_F03_calcul_adaptatifs/Clamp2/Data Type Conversion Inherited1
 * '<S41>'  : AFA_F03_calcul_adaptatifs/Clamp2/Saturation Dynamic
 * '<S42>'  : AFA_F03_calcul_adaptatifs/Clamp3/Data Type Conversion Inherited
 * '<S43>'  : AFA_F03_calcul_adaptatifs/Clamp3/Data Type Conversion Inherited1
 * '<S44>'  : AFA_F03_calcul_adaptatifs/Clamp3/Saturation Dynamic
 * '<S45>'  : AFA_F03_calcul_adaptatifs/Clamp4/Data Type Conversion Inherited
 * '<S46>'  : AFA_F03_calcul_adaptatifs/Clamp4/Data Type Conversion Inherited1
 * '<S47>'  : AFA_F03_calcul_adaptatifs/Clamp4/Saturation Dynamic
 * '<S48>'  : AFA_F03_calcul_adaptatifs/Clamp5/Data Type Conversion Inherited
 * '<S49>'  : AFA_F03_calcul_adaptatifs/Clamp5/Data Type Conversion Inherited1
 * '<S50>'  : AFA_F03_calcul_adaptatifs/Clamp5/Saturation Dynamic
 * '<S51>'  : AFA_F03_calcul_adaptatifs/Clamp6/Data Type Conversion Inherited
 * '<S52>'  : AFA_F03_calcul_adaptatifs/Clamp6/Data Type Conversion Inherited1
 * '<S53>'  : AFA_F03_calcul_adaptatifs/Clamp6/Saturation Dynamic
 * '<S54>'  : AFA_F03_calcul_adaptatifs/Clamp7/Data Type Conversion Inherited
 * '<S55>'  : AFA_F03_calcul_adaptatifs/Clamp7/Data Type Conversion Inherited1
 * '<S56>'  : AFA_F03_calcul_adaptatifs/Clamp7/Saturation Dynamic
 * '<S57>'  : AFA_F03_calcul_adaptatifs/Clamp8/Data Type Conversion Inherited
 * '<S58>'  : AFA_F03_calcul_adaptatifs/Clamp8/Data Type Conversion Inherited1
 * '<S59>'  : AFA_F03_calcul_adaptatifs/Clamp8/Saturation Dynamic
 * '<S60>'  : AFA_F03_calcul_adaptatifs/Clamp9/Data Type Conversion Inherited
 * '<S61>'  : AFA_F03_calcul_adaptatifs/Clamp9/Data Type Conversion Inherited1
 * '<S62>'  : AFA_F03_calcul_adaptatifs/Clamp9/Saturation Dynamic
 */

/*-
 * Requirements for '<Root>': AFA_F03_calcul_adaptatifs
 */
#endif                                 /* RTW_HEADER_AFA_F03_calcul_adaptatifs_h_ */

/*-------------------------------- end of file -------------------------------*/

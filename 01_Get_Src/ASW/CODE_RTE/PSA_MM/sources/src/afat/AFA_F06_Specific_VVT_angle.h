/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F06_Specific_VVT_angle                              */
/*                                                                            */
/* !File            : AFA_F06_Specific_VVT_angle.h                            */
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
/*   Model name       : AFA_F06_Specific_VVT_angle.mdl                        */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F06_Specific_VVT_angle_h_
#define RTW_HEADER_AFA_F06_Specific_VVT_angle_h_
#ifndef AFA_F06_Specific_VVT_angle_COMMON_INCLUDES_
# define AFA_F06_Specific_VVT_angle_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AFA_F06_Specific_VVT_angle_COMMON_INCLUDES_ */

#include "AFA_F06_Specific_VVT_angle_types.h"

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


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  RTW declares the memory for these signals
 * and exports their symbols.
 *
 */
extern UInt16 AFA_agCkPosnVlvOvlp;   /* '<Root>/Divide' */
extern SInt16 AFA_agCkVlvOvlp;        /* '<Root>/Sum' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

extern void mr_AFA_F06_Specific_VVT_angle(const SInt16
  *rtu_AFA_agCkClsExVlvEstimRef1_, const SInt16 *rtu_AFA_agCkOpInVlvEstimRef1_,
  SInt16 *rty_AFA_agCkVlvOvlp, UInt16 *rty_AFA_agCkPosnVlvOvlp);

/* Model reference registration function */
extern void mr_AFA_F06_Specific__initialize(void);

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
 * '<Root>' : AFA_F06_Specific_VVT_angle
 */

/*-
 * Requirements for '<Root>': AFA_F06_Specific_VVT_angle
 */
#endif                                 /* RTW_HEADER_AFA_F06_Specific_VVT_angle_h_ */

/*-------------------------------- end of file -------------------------------*/

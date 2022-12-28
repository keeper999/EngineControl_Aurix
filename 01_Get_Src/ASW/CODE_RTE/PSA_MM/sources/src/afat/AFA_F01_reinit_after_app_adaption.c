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
/* !File            : AFA_F01_reinit_after_app_adaption.c                     */
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
/*   Model name       : AFA_F01_reinit_after_app_adaption.mdl                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jul 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F01_reinit_after_app_adaption.h"
#include "AFA_F01_reinit_after_app_adaption_private.h"
#include "AFAT.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


/* Exported block signals */
UInt16 AFA_noAdpEfcPrev;             /* '<Root>/Signal Conversion1' */
UInt16 AFA_noAdpEfcAstPrev;          /* '<Root>/Signal Conversion' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F01_reinit_after_app_adaption' */
void mr_AFA_F01_reinit_after_app_ada(const UInt16 *rtu_AFA_noAdpEfcPrev, const
  UInt16 *rtu_AFA_noAdpEfcAstPrev, const UInt16 rtu_AFA_prm_covErrEstim[8],
  const UInt16 rtu_AFA_prm_covErr[64], UInt16 *rty_AFA_noAdpEfc, SInt16
  rty_AFA_prm_rErr_PIM[8], UInt8 *rty_AFA_noObsDoneIni, Boolean
  *rty_AFA_bAuthClsCanPurg, UInt8 rty_AFA_prm_noObsDoneMat_PIM[9], UInt8
  *rty_AFA_noObsDoneIdlIni, UInt16 *rty_AFA_noAdpEfcAst, UInt16
  rty_AFA_prm_covErrEstimMat[64])
{
  UInt16 localSwitch1[8];
  SInt32 locali;
  UInt32 localtmp;
  UInt16 locallocalAFA_noAdpEfcAst;

  /* SignalConversion: '<Root>/Signal Conversion1' */
  AFA_noAdpEfcPrev = (*rtu_AFA_noAdpEfcPrev);

  /* Sum: '<Root>/Subtract1' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  localtmp = (UInt32)(AFA_noAdpEfcPrev + 1);
  if (localtmp > 65535U) {
    locallocalAFA_noAdpEfcAst = MAX_uint16_T;
  } else {
    locallocalAFA_noAdpEfcAst = (UInt16)localtmp;
  }

  /* If: '<Root>/If' incorporates:
   *  ActionPort: '<S1>/Action Port'
   *  ActionPort: '<S2>/Action Port'
   *  Constant: '<Root>/AFA_noAdpEfcCovErrRstThd_C'
   *  SubSystem: '<Root>/F01_reinit_covariance'
   *  SubSystem: '<Root>/F01_reinit_covariance1'
   *
   * Block requirements for '<Root>/F01_reinit_covariance':
   *  1. SubSystem "F01_reinit_covariance" !Trace_To : VEMS_R_11_04467_013.01 ;
   */
  if (AFA_noAdpEfcCovErrRstThd_C >= locallocalAFA_noAdpEfcAst) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/AFA_bSelRstCovErrMod_C'
     *  Constant: '<S1>/AFA_prm_covErrIni_C'
     */
    for (locali = 0; locali < 8; locali++) {
      if (AFA_bSelRstCovErrMod_C) {
        localSwitch1[locali] = AFA_prm_covErrIni_C[(locali)];
      } else {
        localSwitch1[locali] = rtu_AFA_prm_covErrEstim[(locali)];
      }
    }

    /* Embedded MATLAB: '<S1>/Diag_Vect2Mat' */
    /* Embedded MATLAB Function 'Diag_Vect2Mat': '<S3>:1' */
    /* '<S3>:1:2' */
    memset((void *)(&rty_AFA_prm_covErrEstimMat[0]), (SInt32)0U, sizeof
           (UInt16) << 6U);
    for (locali = 0; locali < 8; locali++) {
      rty_AFA_prm_covErrEstimMat[locali + (locali << 3)] = localSwitch1[locali];
    }
  } else {
    /* SignalConversion: '<S2>/Signal Conversion1' */
    for (locali = 0; locali < 64; locali++) {
      rty_AFA_prm_covErrEstimMat[(locali)] = rtu_AFA_prm_covErr[(locali)];
    }
  }

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/AFA_noAdpEfcMinThd_C'
   */
  (*rty_AFA_bAuthClsCanPurg) = (locallocalAFA_noAdpEfcAst >=
    AFA_noAdpEfcMinThd_C);

  /* SignalConversion: '<Root>/Signal Conversion3' */
  (*rty_AFA_noAdpEfc) = locallocalAFA_noAdpEfcAst;

  /* Constant: '<Root>/Constant' */
  for (locali = 0; locali < 8; locali++) {
    rty_AFA_prm_rErr_PIM[(locali)] =
      AFA_F01_reinit_after_app_ConstP.Constant_Value[(locali)];
  }

  /* Constant: '<Root>/Constant2' */
  (*rty_AFA_noObsDoneIni) = 0U;

  /* Constant: '<Root>/Constant7' */
  for (locali = 0; locali < 9; locali++) {
    rty_AFA_prm_noObsDoneMat_PIM[(locali)] =
      AFA_F01_reinit_after_app_ConstP.Constant7_Value[(locali)];
  }

  /* Constant: '<Root>/Constant1' */
  (*rty_AFA_noObsDoneIdlIni) = 0U;

  /* SignalConversion: '<Root>/Signal Conversion' */
  AFA_noAdpEfcAstPrev = (*rtu_AFA_noAdpEfcAstPrev);

  /* SignalConversion: '<Root>/Signal Conversion2' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Sum: '<Root>/Subtract2'
   */
  localtmp = (UInt32)(AFA_noAdpEfcAstPrev + 1);
  if (localtmp > 65535U) {
    (*rty_AFA_noAdpEfcAst) = MAX_uint16_T;
  } else {
    (*rty_AFA_noAdpEfcAst) = (UInt16)localtmp;
  }
}

/* Model initialize function */
void mr_AFA_F01_reinit_af_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

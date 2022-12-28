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
/* !File            : AFA_F07_add_IVO_reference_noise.c                       */
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
/*   Model name       : AFA_F07_add_IVO_reference_noise.mdl                   */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   20 Feb 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F07_add_IVO_reference_noise.h"
#include "AFA_F07_add_IVO_reference_noise_private.h"
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

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F07_add_IVO_reference_noise' */
void mr_AFA_F07_add_IVO_reference_no(const UInt16 rtu_AFA_prm_covNoise4[8],
  UInt16 rty_AFA_prm_covN[8])
{
  UInt8 localMatrixConcatenation[8];
  SInt32 locali;
  UInt32 localtmp;
  UInt16 localtmp_0;

  /* Constant: '<Root>/AFA_covNoiseValOpInInc_C' */
  localMatrixConcatenation[0] = AFA_covNoiseValOpInInc_C;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix ConcatenationIn2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  localMatrixConcatenation[1] = 0U;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix ConcatenationIn3' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  localMatrixConcatenation[2] = 0U;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix ConcatenationIn4' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  localMatrixConcatenation[3] = 0U;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix ConcatenationIn5' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  localMatrixConcatenation[4] = 0U;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix ConcatenationIn6' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  localMatrixConcatenation[5] = 0U;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix ConcatenationIn7' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  localMatrixConcatenation[6] = 0U;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix ConcatenationIn8' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  localMatrixConcatenation[7] = 0U;

  /* Sum: '<Root>/Subtract' */
  for (locali = 0; locali < 8; locali++) {
    localtmp = (UInt32)((localMatrixConcatenation[locali] << 3) +
                          rtu_AFA_prm_covNoise4[(locali)]);
    if (localtmp > 65535U) {
      localtmp_0 = MAX_uint16_T;
    } else {
      localtmp_0 = (UInt16)localtmp;
    }

    rty_AFA_prm_covN[(locali)] = localtmp_0;
  }
}

/* Model initialize function */
void mr_AFA_F07_add_IVO_r_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

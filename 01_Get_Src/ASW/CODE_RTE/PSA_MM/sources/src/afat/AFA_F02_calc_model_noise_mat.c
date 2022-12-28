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
/* !File            : AFA_F02_calc_model_noise_mat.c                          */
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
/*   Model name       : AFA_F02_calc_model_noise_mat.mdl                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jul 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F02_calc_model_noise_mat.h"
#include "AFA_F02_calc_model_noise_mat_private.h"
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

/* Output and update for referenced model: 'AFA_F02_calc_model_noise_mat' */
void mr_AFA_F02_calc_model_noise_mat(const UInt16 rtu_AFA_prm_covNoiseVal_PIM
  [8], const UInt16 rtu_AFA_prm_covErr[64], UInt16
  rty_AFA_prm_covPredErrMat_PIM[64])
{
  UInt16 localy[64];
  SInt32 locali;
  UInt32 localtmp;
  UInt16 localtmp_0;

  /* Embedded MATLAB: '<Root>/Diag_Vect2Mat' */
  /* Embedded MATLAB Function 'Diag_Vect2Mat': '<S1>:1' */
  /* '<S1>:1:2' */
  memset((void *)(&localy[0]), (SInt32)0U, sizeof(UInt16) << 6U);
  for (locali = 0; locali < 8; locali++) {
    localy[locali + (locali << 3)] = rtu_AFA_prm_covNoiseVal_PIM[(locali)];
  }

  /* Sum: '<Root>/Add' */
  for (locali = 0; locali < 64; locali++) {
    localtmp = (UInt32)(localy[locali] + rtu_AFA_prm_covErr[(locali)]);
    if (localtmp > 65535U) {
      localtmp_0 = MAX_uint16_T;
    } else {
      localtmp_0 = (UInt16)localtmp;
    }

    rty_AFA_prm_covPredErrMat_PIM[(locali)] = localtmp_0;
  }
}

/* Model initialize function */
void mr_AFA_F02_calc_mode_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

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
/* !File            : AFA_F03_reset_cumulated_model_noise_v.c                 */
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
/*   Model name       : AFA_F03_reset_cumulated_model_noise_v.mdl             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jul 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F03_reset_cumulated_model_noise_v.h"
#include "AFA_F03_reset_cumulated_model_noise_v_private.h"
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

/* Output and update for referenced model: 'AFA_F03_reset_cumulated_model_noise_v' */
void mr_AFA_F03_reset_cumulated_mode(const UInt16 rtu_AFA_prm_covErr1[64],
  UInt16 rty_AFA_prm_covErr[8], UInt16 rty_AFA_prm_covN[8])
{
  SInt32 locali;

  /* Embedded MATLAB: '<Root>/Diag_Mat2Vect' */
  /* Embedded MATLAB Function 'Diag_Mat2Vect': '<S1>:1' */
  /* '<S1>:1:2' */
  for (locali = 0; locali < 8; locali++) {
    rty_AFA_prm_covErr[(locali)] = rtu_AFA_prm_covErr1[(9 * locali)];

    /* Constant: '<Root>/Constant2' */
    rty_AFA_prm_covN[(locali)] =
      AFA_F03_reset_cumulated__ConstP.Constant2_Value[(locali)];
  }
}

/* Model initialize function */
void mr_AFA_F03_reset_cum_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

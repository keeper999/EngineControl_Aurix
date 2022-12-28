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
/* !File            : AFA_F07_calc_error_param_vect.c                         */
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
/*   Model name       : AFA_F07_calc_error_param_vect.mdl                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Nov 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F07_calc_error_param_vect.h"
#include "AFA_F07_calc_error_param_vect_private.h"
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

/* Output and update for referenced model: 'AFA_F07_calc_error_param_vect' */
void mr_AFA_F07_calc_error_param_vec(const SInt16 rtu_AFA_prm_facOutInnov_PIM[2],
  const SInt16 rtu_AFA_prm_rErrPrev[8], const SInt16 rtu_AFA_prm_facKalm[16],
  SInt16 rty_AFA_prm_rErr_PIM[8])
{
  SInt32 localtmp;
  Float32 localtmp_0;
  SInt16 localtmp_1;

  /* Sum: '<Root>/Subtract' incorporates:
   *  Product: '<Root>/Product1'
   *  SignalConversion: '<Root>/Signal Conversion1'
   */
  for (localtmp = 0; localtmp < 8; localtmp++) {
    localtmp_0 = (Float32)ACTEMS_FloorF((((((((Float32)
      rtu_AFA_prm_facKalm[localtmp + 8]) * 3.051757813E-005F) * (((Float32)
      rtu_AFA_prm_facOutInnov_PIM[1]) * 0.00390625F)) + ((((Float32)
      rtu_AFA_prm_facKalm[(localtmp)]) * 3.051757813E-005F) * (((Float32)
      rtu_AFA_prm_facOutInnov_PIM[0]) * 0.00390625F))) + (((Float32)
      rtu_AFA_prm_rErrPrev[(localtmp)]) * 0.0001220703125F)) * 8192.0F) + 0.5F);
    if (((Float32d)localtmp_0) < 32768.0F) {
      if (((Float32d)localtmp_0) >= -32768.0F) {
        localtmp_1 = (SInt16)localtmp_0;
      } else {
        localtmp_1 = MIN_int16_T;
      }
    } else {
      localtmp_1 = MAX_int16_T;
    }

    rty_AFA_prm_rErr_PIM[(localtmp)] = localtmp_1;
  }
}

/* Model initialize function */
void mr_AFA_F07_calc_erro_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

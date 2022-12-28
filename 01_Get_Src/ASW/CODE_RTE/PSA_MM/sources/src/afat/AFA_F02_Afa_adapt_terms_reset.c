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
/* !File            : AFA_F02_Afa_adapt_terms_reset.c                         */
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
/*   Model name       : AFA_F02_Afa_adapt_terms_reset.mdl                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Dec 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F02_Afa_adapt_terms_reset.h"
#include "AFA_F02_Afa_adapt_terms_reset_private.h"
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

/* Output and update for referenced model: 'AFA_F02_Afa_adapt_terms_reset' */
void mr_AFA_F02_Afa_adapt_terms_rese(SInt16 *rty_AFA_facIvsInjGai1, SInt8
  *rty_AFA_tiOffInj, SInt32 *rty_AFA_facSlopInjGai1, SInt16
  *rty_AFA_arEffThrOfs, SInt8 *rty_AFA_facArEffThrOf11, SInt8
  *rty_AFA_facArEffThrOf21, SInt8 *rty_AFA_facArEffThrOf31, SInt8
  *rty_AFA_rCor_arEffEGRVl1, SInt8 *rty_AFA_agCkOpInVlvOf1, SInt8
  *rty_AFA_agCkClsExVlvOf1, SInt8 *rty_AFA_arEffEGRVl1)
{
  /* Constant: '<Root>/AFA_facIvsInjGainIni_C' */
  (*rty_AFA_facIvsInjGai1) = AFA_facIvsInjGainIni_C;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/AFA_tiOffInjIni_C'
   */
  if (AFA_tiOffInjIni_C > 127) {
    (*rty_AFA_tiOffInj) = MAX_int8_T;
  } else if (AFA_tiOffInjIni_C <= -128) {
    (*rty_AFA_tiOffInj) = MIN_int8_T;
  } else {
    (*rty_AFA_tiOffInj) = (SInt8)AFA_tiOffInjIni_C;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/AFA_facSlopInjGainIni_C'
   */
  (*rty_AFA_facSlopInjGai1) = mul_s32_s32_s32_sr28_sat(AFA_facSlopInjGainIni_C,
    375299969);

  /* Constant: '<Root>/AFA_arEffThrOfsIni_C' */
  (*rty_AFA_arEffThrOfs) = AFA_arEffThrOfsIni_C;

  /* Constant: '<Root>/AFA_facArEffThrOfs1Ini_C' */
  (*rty_AFA_facArEffThrOf11) = AFA_facArEffThrOfs1Ini_C;

  /* Constant: '<Root>/AFA_facArEffThrOfs2Ini_C' */
  (*rty_AFA_facArEffThrOf21) = AFA_facArEffThrOfs2Ini_C;

  /* Constant: '<Root>/AFA_facArEffThrOfs3Ini_C' */
  (*rty_AFA_facArEffThrOf31) = AFA_facArEffThrOfs3Ini_C;

  /* Constant: '<Root>/AFA_rCor_arEffEGRVlvIni_C' */
  (*rty_AFA_rCor_arEffEGRVl1) = AFA_rCor_arEffEGRVlvIni_C;

  /* Constant: '<Root>/AFA_agCkOpInVlvOfsIni_C' */
  (*rty_AFA_agCkOpInVlvOf1) = AFA_agCkOpInVlvOfsIni_C;

  /* Constant: '<Root>/AFA_agCkClsExVlvOfsIni_C' */
  (*rty_AFA_agCkClsExVlvOf1) = AFA_agCkClsExVlvOfsIni_C;

  /* Constant: '<Root>/AFA_arEffEGRVlvOfsIni_C' */
  (*rty_AFA_arEffEGRVl1) = AFA_arEffEGRVlvOfsIni_C;
}

/* Model initialize function */
void mr_AFA_F02_Afa_adapt_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

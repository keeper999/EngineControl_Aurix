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
/* !File            : AFA_F04_detect_adaptation_stop.c                        */
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
/*   Model name       : AFA_F04_detect_adaptation_stop.mdl                    */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   04 Dec 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F04_detect_adaptation_stop.h"
#include "AFA_F04_detect_adaptation_stop_private.h"
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

/* Output and update for referenced model: 'AFA_F04_detect_adaptation_stop' */
void mr_AFA_F04_detect_adaptation_st(const SInt16 *rtu_AFA_facIvsInjGain, const
  SInt8 *rtu_AFA_tiOffInj, const SInt32 *rtu_AFA_facSlopInjGain, const SInt16
  *rtu_AFA_arEffThrOfs, const SInt8 *rtu_AFA_facArEffThrOfs1, const SInt8
  *rtu_AFA_facArEffThrOfs2, const SInt8 *rtu_AFA_facArEffThrOfs3, const SInt8 *
  rtu_AFA_rCor_arEffEGRVlv, const SInt8 *rtu_AFA_agCkOpInVlvOfs, const SInt8
  *rtu_AFA_agCkClsExVlvOfs, Boolean *rty_AFA_bMonRunAdpIvsInjConLim, Boolean
  *rty_AFA_bDgoAdpIvsInjConLim, Boolean *rty_AFA_bMonRunAdpInjOfsLim,
  Boolean *rty_AFA_bDgoAdpInjOfsLim, Boolean
  *rty_AFA_bMonRunAdpSlopInjConLim, Boolean *rty_AFA_bDgoAdpSlopInjConLim,
  Boolean *rty_AFA_bMonRunAdpArEffThrOfsLi, Boolean
  *rty_AFA_bDgoAdpArEffThrOfsLim, Boolean *rty_AFA_bMonRunAdpArEffThrOfs1L,
  Boolean *rty_AFA_bDgoAdpArEffThrOfs1Lim, Boolean
  *rty_AFA_bMonRunAdpArEffThrOfs2L, Boolean *rty_AFA_bDgoAdpArEffThrOfs2Lim,
  Boolean *rty_AFA_bMonRunAdpArEffThrOfs3L, Boolean
  *rty_AFA_bDgoAdpArEffThrOfs3Lim, Boolean *rty_AFA_bMonRunAdpArEffEGRVlvLi,
  Boolean *rty_AFA_bDgoAdpArEffEGRVlvLim, Boolean
  *rty_AFA_bMonRunAdpOpInOfsLim, Boolean *rty_AFA_bDgoAdpOpInOfsLim, Boolean
  *rty_AFA_bMonRunAdpClsExOfsLim, Boolean *rty_AFA_bDgoAdpClsExOfsLim)
{
  UInt16 localAbs3;
  UInt8 localAbs7;
  UInt32 localAbs2;
  SInt8 localSwitch1;
  SInt32 localtmp;

  /* Constant: '<Root>/Constant3' */
  (*rty_AFA_bMonRunAdpIvsInjConLim) = TRUE;

  /* Abs: '<Root>/Abs' */
  if ((*rtu_AFA_facIvsInjGain) < 0) {
    localAbs3 = (UInt16)((UInt32)(-(*rtu_AFA_facIvsInjGain)));
  } else {
    localAbs3 = (UInt16)(*rtu_AFA_facIvsInjGain);
  }

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/AFA_facIvsInjGainSat_C'
   */
  (*rty_AFA_bDgoAdpIvsInjConLim) = (localAbs3 >= AFA_facIvsInjGainSat_C);

  /* Constant: '<Root>/Constant' */
  (*rty_AFA_bMonRunAdpInjOfsLim) = TRUE;

  /* Abs: '<Root>/Abs1' */
  if ((*rtu_AFA_tiOffInj) < 0) {
    localAbs7 = (UInt8)((UInt32)(-(*rtu_AFA_tiOffInj)));
  } else {
    localAbs7 = (UInt8)(*rtu_AFA_tiOffInj);
  }

  /* RelationalOperator: '<Root>/Relational Operator1' incorporates:
   *  Constant: '<Root>/AFA_tiOffInjSat_C'
   */
  (*rty_AFA_bDgoAdpInjOfsLim) = (localAbs7 >= AFA_tiOffInjSat_C);

  /* Constant: '<Root>/Constant1' */
  (*rty_AFA_bMonRunAdpSlopInjConLim) = TRUE;

  /* Abs: '<Root>/Abs2' */
  if ((*rtu_AFA_facSlopInjGain) < 0) {
    localAbs2 = (UInt32)(-(*rtu_AFA_facSlopInjGain));
  } else {
    localAbs2 = (UInt32)(*rtu_AFA_facSlopInjGain);
  }

  /* RelationalOperator: '<Root>/Relational Operator2' incorporates:
   *  Constant: '<Root>/AFA_facSlopInjGainSat_C'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  (*rty_AFA_bDgoAdpSlopInjConLim) = (localAbs2 >= mul_u32_u32_u32_sr28_sat
    (AFA_facSlopInjGainSat_C, 375299969U));

  /* Constant: '<Root>/Constant4' */
  (*rty_AFA_bMonRunAdpArEffThrOfsLi) = TRUE;

  /* Abs: '<Root>/Abs3' */
  if ((*rtu_AFA_arEffThrOfs) < 0) {
    localAbs3 = (UInt16)((UInt32)(-(*rtu_AFA_arEffThrOfs)));
  } else {
    localAbs3 = (UInt16)(*rtu_AFA_arEffThrOfs);
  }

  /* RelationalOperator: '<Root>/Relational Operator3' incorporates:
   *  Constant: '<Root>/AFA_arEffThrOfsSat_C'
   */
  (*rty_AFA_bDgoAdpArEffThrOfsLim) = (localAbs3 >= AFA_arEffThrOfsSat_C);

  /* Constant: '<Root>/Constant6' */
  (*rty_AFA_bMonRunAdpArEffThrOfs1L) = TRUE;

  /* Abs: '<Root>/Abs4' */
  if ((*rtu_AFA_facArEffThrOfs1) < 0) {
    localAbs7 = (UInt8)((UInt32)(-(*rtu_AFA_facArEffThrOfs1)));
  } else {
    localAbs7 = (UInt8)(*rtu_AFA_facArEffThrOfs1);
  }

  /* RelationalOperator: '<Root>/Relational Operator4' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs1Sat_C'
   */
  (*rty_AFA_bDgoAdpArEffThrOfs1Lim) = (localAbs7 >= AFA_facArEffThrOfs1Sat_C);

  /* Constant: '<Root>/Constant7' */
  (*rty_AFA_bMonRunAdpArEffThrOfs2L) = TRUE;

  /* Abs: '<Root>/Abs5' */
  if ((*rtu_AFA_facArEffThrOfs2) < 0) {
    localAbs7 = (UInt8)((UInt32)(-(*rtu_AFA_facArEffThrOfs2)));
  } else {
    localAbs7 = (UInt8)(*rtu_AFA_facArEffThrOfs2);
  }

  /* RelationalOperator: '<Root>/Relational Operator5' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs2Sat_C'
   */
  (*rty_AFA_bDgoAdpArEffThrOfs2Lim) = (localAbs7 >= AFA_facArEffThrOfs2Sat_C);

  /* Constant: '<Root>/Constant8' */
  (*rty_AFA_bMonRunAdpArEffThrOfs3L) = TRUE;

  /* Abs: '<Root>/Abs6' */
  if ((*rtu_AFA_facArEffThrOfs3) < 0) {
    localAbs7 = (UInt8)((UInt32)(-(*rtu_AFA_facArEffThrOfs3)));
  } else {
    localAbs7 = (UInt8)(*rtu_AFA_facArEffThrOfs3);
  }

  /* RelationalOperator: '<Root>/Relational Operator6' incorporates:
   *  Constant: '<Root>/AFA_facArEffThrOfs3Sat_C'
   */
  (*rty_AFA_bDgoAdpArEffThrOfs3Lim) = (localAbs7 >= AFA_facArEffThrOfs3Sat_C);

  /* Constant: '<Root>/Constant9' */
  (*rty_AFA_bMonRunAdpArEffEGRVlvLi) = TRUE;

  /* Abs: '<Root>/Abs7' */
  if ((*rtu_AFA_rCor_arEffEGRVlv) < 0) {
    localAbs7 = (UInt8)((((UInt32)(-(*rtu_AFA_rCor_arEffEGRVlv))) > 0U) ?
                          255 : 0);
  } else {
    localAbs7 = (UInt8)((((UInt8)(*rtu_AFA_rCor_arEffEGRVlv)) > 0) ? 255 : 0);
  }

  /* RelationalOperator: '<Root>/Relational Operator7' incorporates:
   *  Constant: '<Root>/AFA_rCorArEffEGRVlvReqSat_C'
   */
  (*rty_AFA_bDgoAdpArEffEGRVlvLim) = (((UInt32)localAbs7) >= ((UInt32)
    (AFA_rCorArEffEGRVlvReqSat_C << 10)));

  /* Constant: '<Root>/Constant13' */
  (*rty_AFA_bMonRunAdpOpInOfsLim) = TRUE;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant16'
   *  Constant: '<Root>/Constant17'
   *  Product: '<S1>/Divide'
   *  RelationalOperator: '<Root>/Relational Operator10'
   */
  if ((*rtu_AFA_agCkOpInVlvOfs) >= 0) {
    localSwitch1 = (*rtu_AFA_agCkOpInVlvOfs);
  } else {
    localtmp = -(*rtu_AFA_agCkOpInVlvOfs);
    if (localtmp > 127) {
      localSwitch1 = MAX_int8_T;
    } else {
      localSwitch1 = (SInt8)localtmp;
    }
  }

  /* RelationalOperator: '<Root>/Relational Operator8' incorporates:
   *  Constant: '<Root>/AFA_agCkVlvInSat_C'
   */
  (*rty_AFA_bDgoAdpOpInOfsLim) = (localSwitch1 >= AFA_agCkVlvInSat_C);

  /* Constant: '<Root>/Constant15' */
  (*rty_AFA_bMonRunAdpClsExOfsLim) = TRUE;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant18'
   *  Constant: '<Root>/Constant19'
   *  Product: '<S2>/Divide'
   *  RelationalOperator: '<Root>/Relational Operator11'
   */
  if ((*rtu_AFA_agCkClsExVlvOfs) >= 0) {
    localSwitch1 = (*rtu_AFA_agCkClsExVlvOfs);
  } else {
    localtmp = -(*rtu_AFA_agCkClsExVlvOfs);
    if (localtmp > 127) {
      localSwitch1 = MAX_int8_T;
    } else {
      localSwitch1 = (SInt8)localtmp;
    }
  }

  /* RelationalOperator: '<Root>/Relational Operator9' incorporates:
   *  Constant: '<Root>/AFA_agCkVlvExSat_C'
   */
  (*rty_AFA_bDgoAdpClsExOfsLim) = (localSwitch1 >= AFA_agCkVlvExSat_C);
}

/* Model initialize function */
void mr_AFA_F04_detect_ad_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

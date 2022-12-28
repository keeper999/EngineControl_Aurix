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
/* !File            : AFA_F00_init_scruter_environ_adaptation.c               */
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
/*   Model name       : AFA_F00_init_scruter_environ_adaptation.mdl           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   ADELVARE                               $$Date::   13 May 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F00_init_scruter_environ_adaptation.h"
#include "AFA_F00_init_scruter_environ_adaptation_private.h"
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

/* Output and update for referenced model: 'AFA_F00_init_scruter_environ_adaptation' */
void mr_AFA_F00_init_scruter_environ(const UInt16 *rtu_ThrLrn_rOpClsThrBol,
  const UInt16 *rtu_UsThrM_pAirExtEstim, const UInt32 *rtu_EGRVlv_rOpClsEGR1,
  const UInt16 rtu_VlvAct_prm_agCkOpIn1[4], const UInt16
  rtu_VlvAct_prm_agCkClsEx1[4], Boolean *rty_AFA_bClsEGRRef, Boolean
  *rty_AFA_bFitPresAirExt, Boolean *rty_AFA_bFitZeroPosnThr, Boolean
  *rty_AFA_bFitOpInVlvBol, Boolean *rty_AFA_bFitClsExVlvBol, UInt16
  *rty_AFA_rOpClsThrBolHld, UInt16 *rty_AFA_pAirExtEstimHld, UInt16
  *rty_AFA_rOpClsEGRVlvBol1, UInt16 *rty_AFA_agCkOpInVlvBol1, UInt16
  *rty_AFA_agCkClsExVlvBo1)
{
  UInt32 localtmp;

  /* Constant: '<Root>/Bool' */
  (*rty_AFA_bClsEGRRef) = FALSE;

  /* Constant: '<Root>/Bool1' */
  (*rty_AFA_bFitPresAirExt) = FALSE;

  /* Constant: '<Root>/Bool2' */
  (*rty_AFA_bFitZeroPosnThr) = FALSE;

  /* Constant: '<Root>/Bool3' */
  (*rty_AFA_bFitOpInVlvBol) = FALSE;

  /* Constant: '<Root>/Bool4' */
  (*rty_AFA_bFitClsExVlvBol) = FALSE;

  /* SignalConversion: '<Root>/Signal Conversion1' */
  (*rty_AFA_rOpClsThrBolHld) = (*rtu_ThrLrn_rOpClsThrBol);

  /* SignalConversion: '<Root>/Signal Conversion2' */
  (*rty_AFA_pAirExtEstimHld) = (*rtu_UsThrM_pAirExtEstim);

  /* SignalConversion: '<Root>/Signal Conversion3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  localtmp = ((*rtu_EGRVlv_rOpClsEGR1) >> 6);
  if (localtmp > 65535U) {
    (*rty_AFA_rOpClsEGRVlvBol1) = MAX_uint16_T;
  } else {
    (*rty_AFA_rOpClsEGRVlvBol1) = (UInt16)localtmp;
  }

  /* SignalConversion: '<Root>/Signal Conversion4' */
  (*rty_AFA_agCkOpInVlvBol1) = rtu_VlvAct_prm_agCkOpIn1[0];

  /* SignalConversion: '<Root>/Signal Conversion5' */
  (*rty_AFA_agCkClsExVlvBo1) = rtu_VlvAct_prm_agCkClsEx1[0];
}

/* Model initialize function */
void mr_AFA_F00_init_scru_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

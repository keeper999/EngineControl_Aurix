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
/* !File            : AFA_F01_lire_adaptatifs_en_eeprom.c                     */
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
/*   Model name       : AFA_F01_lire_adaptatifs_en_eeprom.mdl                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Jul 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F01_lire_adaptatifs_en_eeprom.h"
#include "AFA_F01_lire_adaptatifs_en_eeprom_private.h"
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

/* Output and update for referenced model: 'AFA_F01_lire_adaptatifs_en_eeprom' */
void mr_AFA_F01_lire_adaptatifs_en_e(const SInt16 *rtu_AFA_facIvsInjGain_NV,
  const SInt8 *rtu_AFA_tiOffInj_NV, const SInt32 *rtu_AFA_facSlopInjGain_NV,
  const SInt16 *rtu_AFA_arEffThrOfs_NV, const SInt8
  *rtu_AFA_facArEffThrOfs1_NV, const SInt8 *rtu_AFA_facArEffThrOfs2_NV, const
  SInt8 *rtu_AFA_facArEffThrOfs3_NV, const SInt8 *rtu_AFA_rCor_arEffEGRVlv_NV,
  const SInt8 *rtu_AFA_agCkOpInVlvOfs_NV, const SInt8
  *rtu_AFA_agCkClsExVlvOfs_NV, SInt16 *rty_AFA_facIvsInjGain2, SInt8
  *rty_AFA_tiOffInj2, SInt32 *rty_AFA_facSlopInjGain2, SInt16
  *rty_AFA_arEffThrOfs2, SInt8 *rty_AFA_facArEffThrOfs1, SInt8
  *rty_AFA_facArEffThrOfs2, SInt8 *rty_AFA_facArEffThrOfs3, SInt8
  *rty_AFA_rCor_arEffEGRV2, SInt8 *rty_AFA_agCkOpInVlvOf2, SInt8
  *rty_AFA_agCkClsExVlvOf2)
{
  /* SignalConversion: '<Root>/Signal Conversion' */
  (*rty_AFA_facIvsInjGain2) = (*rtu_AFA_facIvsInjGain_NV);

  /* SignalConversion: '<Root>/Signal Conversion1' */
  (*rty_AFA_tiOffInj2) = (*rtu_AFA_tiOffInj_NV);

  /* SignalConversion: '<Root>/Signal Conversion2' */
  (*rty_AFA_facSlopInjGain2) = (*rtu_AFA_facSlopInjGain_NV);

  /* SignalConversion: '<Root>/Signal Conversion3' */
  (*rty_AFA_arEffThrOfs2) = (*rtu_AFA_arEffThrOfs_NV);

  /* SignalConversion: '<Root>/Signal Conversion4' */
  (*rty_AFA_facArEffThrOfs1) = (*rtu_AFA_facArEffThrOfs1_NV);

  /* SignalConversion: '<Root>/Signal Conversion5' */
  (*rty_AFA_facArEffThrOfs2) = (*rtu_AFA_facArEffThrOfs2_NV);

  /* SignalConversion: '<Root>/Signal Conversion6' */
  (*rty_AFA_facArEffThrOfs3) = (*rtu_AFA_facArEffThrOfs3_NV);

  /* SignalConversion: '<Root>/Signal Conversion7' */
  (*rty_AFA_rCor_arEffEGRV2) = (*rtu_AFA_rCor_arEffEGRVlv_NV);

  /* SignalConversion: '<Root>/Signal Conversion8' */
  (*rty_AFA_agCkOpInVlvOf2) = (*rtu_AFA_agCkOpInVlvOfs_NV);

  /* SignalConversion: '<Root>/Signal Conversion9' */
  (*rty_AFA_agCkClsExVlvOf2) = (*rtu_AFA_agCkClsExVlvOfs_NV);
}

/* Model initialize function */
void mr_AFA_F01_lire_adap_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

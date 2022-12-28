/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F01_lire_adaptatifs_en_eeprom                       */
/*                                                                            */
/* !File            : AFA_F01_lire_adaptatifs_en_eeprom.h                     */
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
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Jul 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F01_lire_adaptatifs_en_eeprom_h_
#define RTW_HEADER_AFA_F01_lire_adaptatifs_en_eeprom_h_
#ifndef AFA_F01_lire_adaptatifs_en_eeprom_COMMON_INCLUDES_
# define AFA_F01_lire_adaptatifs_en_eeprom_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AFA_F01_lire_adaptatifs_en_eeprom_COMMON_INCLUDES_ */

#include "AFA_F01_lire_adaptatifs_en_eeprom_types.h"

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

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Model reference registration function */
extern void mr_AFA_F01_lire_adap_initialize(void);


extern void mr_AFA_F01_lire_adaptatifs_en_e(const SInt16
  *rtu_AFA_facIvsInjGain_NV, const SInt8 *rtu_AFA_tiOffInj_NV, const SInt32
  *rtu_AFA_facSlopInjGain_NV, const SInt16 *rtu_AFA_arEffThrOfs_NV, const
  SInt8 *rtu_AFA_facArEffThrOfs1_NV, const SInt8 *rtu_AFA_facArEffThrOfs2_NV,
  const SInt8 *rtu_AFA_facArEffThrOfs3_NV, const SInt8
  *rtu_AFA_rCor_arEffEGRVlv_NV, const SInt8 *rtu_AFA_agCkOpInVlvOfs_NV, const
  SInt8 *rtu_AFA_agCkClsExVlvOfs_NV, SInt16 *rty_AFA_facIvsInjGain2, SInt8
  *rty_AFA_tiOffInj2, SInt32 *rty_AFA_facSlopInjGain2, SInt16
  *rty_AFA_arEffThrOfs2, SInt8 *rty_AFA_facArEffThrOfs1, SInt8
  *rty_AFA_facArEffThrOfs2, SInt8 *rty_AFA_facArEffThrOfs3, SInt8
  *rty_AFA_rCor_arEffEGRV2, SInt8 *rty_AFA_agCkOpInVlvOf2, SInt8
  *rty_AFA_agCkClsExVlvOf2);

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
 * '<Root>' : AFA_F01_lire_adaptatifs_en_eeprom
 */

/*-
 * Requirements for '<Root>': AFA_F01_lire_adaptatifs_en_eeprom
 */
#endif                                 /* RTW_HEADER_AFA_F01_lire_adaptatifs_en_eeprom_h_ */

/*-------------------------------- end of file -------------------------------*/

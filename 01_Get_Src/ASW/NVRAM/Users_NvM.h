/******************************************************************************/
/*                                                                            */
/* !Layer          : SRV                                                      */
/*                                                                            */
/* !Component      : NVRAM                                                    */
/*                                                                            */
/* !Module         : Users_NvM                                                */
/* !Description    : Contains structure and callback declaration              */
/*                   of the blocks NVM                                        */
/*                                                                            */
/* !File           : Users_NvM.H                                              */
/*                                                                            */
/* !Scope          : Public                                                   */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2014 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/NVRAM/Users_NvM.h_v               $*/
/* $Revision::   1.4      $$Author::   wbouach     $$Date::   19 Sep 2014 14:$*/
/******************************************************************************/
/*       THIS FILE IS GENERATED AUTOMATICALY BY GenGlueCfromXLS TOOL          */
/*       Generated date 19/09/14 at 14:21:18                                   */
/******************************************************************************/

#ifndef USERS_NVM_H
#define USERS_NVM_H

#include "NVRAM_TYP.H"
#include "BSW_NvM.H"
#include "SAIMMO_L.h"
#include "AFAMgtT_nvm_valeo.h"
#include "AFAT_nvm_valeo.h"
#include "COEMSTT_nvm_valeo.h"
#include "COSTOPSTART_nvm_valeo.h"
#include "DFWCTL_nvm_valeo.h"
#include "EOMGSL_nvm_valeo.h"
#include "ExMGslT2_nvm_valeo.h"
#include "FISA_nvm_valeo.h"
#include "gdgar.h"
#include "MPM_nvm_valeo.h"
#include "PRODELEM_nvm_valeo.h"
#include "PRODELENG_nvm_valeo.h"
#include "STOPSTRTEM_nvm_valeo.h"
#include "THMGT_nvm_valeo.h"
#include "ThrSpT_nvm_valeo.h"
#include "TPM_nvm_valeo.h"
#include "TQADPCMP_nvm_valeo.h"
#include "UsThrMT_nvm_valeo.h"

/*********************************************************************************/
/* DECLARATION DES STRUCTURES NvMRxmBlockDataStruct & Callback d'initialisation  */
/*********************************************************************************/

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM TEST_EEPROM_1: */
extern TEST_EEPROM_1_NvMBlockDataStruct TEST_EEPROM_1_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM TEST_EEPROM_1: */
extern const TEST_EEPROM_1_NvMBlockDataStruct TEST_EEPROM_1_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM TEST_EEPROM_2: */
extern TEST_EEPROM_2_NvMBlockDataStruct TEST_EEPROM_2_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM TEST_EEPROM_2: */
extern const TEST_EEPROM_2_NvMBlockDataStruct TEST_EEPROM_2_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM SPI_REREAD_FRAMES: */
extern SPI_REREAD_FRAMES_NvMBlockDataStruct SPI_REREAD_FRAMES_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM SPI_REREAD_FRAMES: */
extern const SPI_REREAD_FRAMES_NvMBlockDataStruct SPI_REREAD_FRAMES_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM EPMSRV: */
extern EPMSRV_NvMBlockDataStruct EPMSRV_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM EPMSRV: */
extern const EPMSRV_NvMBlockDataStruct EPMSRV_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM DOWNLOAD: */
extern DOWNLOAD_NvMBlockDataStruct DOWNLOAD_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM DOWNLOAD: */
extern const DOWNLOAD_NvMBlockDataStruct DOWNLOAD_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM ECRITURES_EEPROM: */
extern ECRITURES_EEPROM_NvMBlockDataStruct ECRITURES_EEPROM_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM ECRITURES_EEPROM: */
extern const ECRITURES_EEPROM_NvMBlockDataStruct ECRITURES_EEPROM_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM RESET: */
extern RESET_NvMBlockDataStruct RESET_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM RESET: */
extern const RESET_NvMBlockDataStruct RESET_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM EXCEPTION_REGS: */
extern EXCEPTION_REGS_NvMBlockDataStruct EXCEPTION_REGS_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM EXCEPTION_REGS: */
extern const EXCEPTION_REGS_NvMBlockDataStruct EXCEPTION_REGS_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM TEST_EEPROM_3: */
extern TEST_EEPROM_3_NvMBlockDataStruct TEST_EEPROM_3_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM TEST_EEPROM_3: */
extern const TEST_EEPROM_3_NvMBlockDataStruct TEST_EEPROM_3_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM REDPROD_1: */
extern REDPROD_1_NvMBlockDataStruct REDPROD_1_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM REDPROD_1: */
extern const REDPROD_1_NvMBlockDataStruct REDPROD_1_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM REDPROD_2: */
extern REDPROD_2_NvMBlockDataStruct REDPROD_2_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM REDPROD_2: */
extern const REDPROD_2_NvMBlockDataStruct REDPROD_2_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM REDPROD_5: */
extern REDPROD_5_NvMBlockDataStruct REDPROD_5_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM REDPROD_5: */
extern const REDPROD_5_NvMBlockDataStruct REDPROD_5_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM REDPROD_8: */
extern REDPROD_8_NvMBlockDataStruct REDPROD_8_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM REDPROD_8: */
extern const REDPROD_8_NvMBlockDataStruct REDPROD_8_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM PROD_1_VALEOIDENT: */
extern PROD_1_VALEOIDENT_NvMBlockDataStruct PROD_1_VALEOIDENT_NvMRamBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM PROD_2_PSAIDENT: */
extern PROD_2_PSAIDENT_NvMBlockDataStruct PROD_2_PSAIDENT_NvMRamBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM PROD_5_CIENUM: */
extern PROD_5_CIENUM_NvMBlockDataStruct PROD_5_CIENUM_NvMRamBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM PROD_8_TRIMS: */
extern PROD_8_TRIMS_NvMBlockDataStruct PROD_8_TRIMS_NvMRamBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM EEPROM_VERSION: */
extern EEPROM_VERSION_NvMBlockDataStruct EEPROM_VERSION_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM EEPROM_VERSION: */
extern const EEPROM_VERSION_NvMBlockDataStruct EEPROM_VERSION_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM KNKADPCOR: */
extern KNKADPCOR_NvMBlockDataStruct KNKADPCOR_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM KNKADPCOR: */
extern const KNKADPCOR_NvMBlockDataStruct KNKADPCOR_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM POSTEQUSRV: */
extern POSTEQUSRV_NvMBlockDataStruct POSTEQUSRV_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM POSTEQUSRV: */
extern const POSTEQUSRV_NvMBlockDataStruct POSTEQUSRV_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM SAIMMO_CODE: */
extern Std_ReturnType NVM_SAIMMO_CODE__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SAIMMO_ETAT: */
extern Std_ReturnType NVM_SAIMMO_ETAT__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM TELECODAGE: */
extern TELECODAGE_NvMBlockDataStruct TELECODAGE_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM TELECODAGE: */
extern const TELECODAGE_NvMBlockDataStruct TELECODAGE_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM TELECODAGE: */
extern Std_ReturnType NVM_TELECODAGE_NVMSRV_vidInit(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM ACCPEM: */
extern ACCPEM_NvMBlockDataStruct ACCPEM_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM ACCPEM: */
extern const ACCPEM_NvMBlockDataStruct ACCPEM_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM ACCPLRNPOS: */
extern ACCPLRNPOS_NvMBlockDataStruct ACCPLRNPOS_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM ACCPLRNPOS: */
extern const ACCPLRNPOS_NvMBlockDataStruct ACCPLRNPOS_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM ACCPLRNPOS: */
extern Std_ReturnType NVM_ACCPLRNPOS_NVMSRV_vidInit(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM ACQCOT: */
extern ACQCOT_NvMBlockDataStruct ACQCOT_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM ACQCOT: */
extern const ACQCOT_NvMBlockDataStruct ACQCOT_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM ACQCOT: */
extern Std_ReturnType NVM_ACQCOT_NVMSRV_vidInit(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFAMGTT_NVRAM_INT8_CONST: */
extern Std_ReturnType NVM_AFAMgtT_NVRAM_int8_const__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFAT_NVRAM_INT16_CALIB: */
extern Std_ReturnType NVM_AFAT_NVRAM_int16_calib__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFAT_NVRAM_INT32_CALIB: */
extern Std_ReturnType NVM_AFAT_NVRAM_int32_calib__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFAT_NVRAM_INT8_CALIB: */
extern Std_ReturnType NVM_AFAT_NVRAM_int8_calib__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFAT_NVRAM_BOOLEAN_CALIB: */
extern Std_ReturnType NVM_AFAT_NVRAM_boolean_calib__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFAT_NVRAM_INT16_CONST: */
extern Std_ReturnType NVM_AFAT_NVRAM_int16_const__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFAT_NVRAM_INT8_CONST: */
extern Std_ReturnType NVM_AFAT_NVRAM_int8_const__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFAT_NVRAM_BOOLEAN_CONST: */
extern Std_ReturnType NVM_AFAT_NVRAM_boolean_const__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM CLCNFISAGAIN: */
extern CLCNFISAGAIN_NvMBlockDataStruct CLCNFISAGAIN_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM CLCNFISAGAIN: */
extern const CLCNFISAGAIN_NvMBlockDataStruct CLCNFISAGAIN_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM CLUPEDPOSNDIAG: */
extern CLUPEDPOSNDIAG_NvMBlockDataStruct CLUPEDPOSNDIAG_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM CLUPEDPOSNDIAG: */
extern const CLUPEDPOSNDIAG_NvMBlockDataStruct CLUPEDPOSNDIAG_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM CLUSWTDIAG: */
extern CLUSWTDIAG_NvMBlockDataStruct CLUSWTDIAG_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM CLUSWTDIAG: */
extern const CLUSWTDIAG_NvMBlockDataStruct CLUSWTDIAG_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM COEMSTT_NVRAM_INT16_CONST_1: */
extern Std_ReturnType NVM_COEMSTT_NVRAM_int16_const_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COEMSTT_NVRAM_INT32_CONST_1: */
extern Std_ReturnType NVM_COEMSTT_NVRAM_int32_const_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COEMSTT_NVRAM_INT8_CONST_1: */
extern Std_ReturnType NVM_COEMSTT_NVRAM_int8_const_1__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM COFANCMDDIAG: */
extern COFANCMDDIAG_NvMBlockDataStruct COFANCMDDIAG_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM COFANCMDDIAG: */
extern const COFANCMDDIAG_NvMBlockDataStruct COFANCMDDIAG_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM FHCANF552: */
extern FHCANF552_NvMBlockDataStruct FHCANF552_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM FHCANF552: */
extern const FHCANF552_NvMBlockDataStruct FHCANF552_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_INT16_CONST_1: */
extern Std_ReturnType NVM_COSTOPSTART_NVRAM_int16_const_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_INT8_CONST_1: */
extern Std_ReturnType NVM_COSTOPSTART_NVRAM_int8_const_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_INT8_CONST_2: */
extern Std_ReturnType NVM_COSTOPSTART_NVRAM_int8_const_2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_INT8_CONST_3: */
extern Std_ReturnType NVM_COSTOPSTART_NVRAM_int8_const_3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_BOOLEAN_CONST_1: */
extern Std_ReturnType NVM_COSTOPSTART_NVRAM_boolean_const_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_BOOLEAN_CONST_2: */
extern Std_ReturnType NVM_COSTOPSTART_NVRAM_boolean_const_2__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM CSTRFUCONCESTIM: */
extern CSTRFUCONCESTIM_NvMBlockDataStruct CSTRFUCONCESTIM_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM CSTRFUCONCESTIM: */
extern const CSTRFUCONCESTIM_NvMBlockDataStruct CSTRFUCONCESTIM_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM CSTRFUCONCESTIM: */
extern Std_ReturnType NVM_CSTRFUCONCESTIM_NVMSRV_vidInit(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM DCM_MANU: */
extern DCM_MANU_NvMBlockDataStruct DCM_MANU_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM DCM_MANU: */
extern const DCM_MANU_NvMBlockDataStruct DCM_MANU_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM DFWCTL_NVRAM_INT16_CONST: */
extern Std_ReturnType NVM_DFWCTL_NVRAM_int16_const__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM DIAGAIREXTPRES: */
extern DIAGAIREXTPRES_NvMBlockDataStruct DIAGAIREXTPRES_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM DIAGAIREXTPRES: */
extern const DIAGAIREXTPRES_NvMBlockDataStruct DIAGAIREXTPRES_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM DSO2SEN: */
extern DSO2SEN_NvMBlockDataStruct DSO2SEN_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM DSO2SEN: */
extern const DSO2SEN_NvMBlockDataStruct DSO2SEN_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM ECUMNG: */
extern ECUMNG_NvMBlockDataStruct ECUMNG_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM ECUMNG: */
extern const ECUMNG_NvMBlockDataStruct ECUMNG_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM ECUMNG: */
extern Std_ReturnType NVM_ECUMNG_NVMSRV_vidInit(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM ENGRUNST: */
extern ENGRUNST_NvMBlockDataStruct ENGRUNST_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM ENGRUNST: */
extern const ENGRUNST_NvMBlockDataStruct ENGRUNST_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM DIVERS_EEP_FIXE: */
extern DIVERS_EEP_FIXE_NvMBlockDataStruct DIVERS_EEP_FIXE_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM DIVERS_EEP_FIXE: */
extern const DIVERS_EEP_FIXE_NvMBlockDataStruct DIVERS_EEP_FIXE_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM EOMGSL_NVRAM_INT32_CONST: */
extern Std_ReturnType NVM_EOMGSL_NVRAM_int32_const__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM EXMGSLT2_NVRAM_INT16_CONST: */
extern Std_ReturnType NVM_ExMGslT2_NVRAM_int16_const__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM FISARFUDET: */
extern FISARFUDET_NvMBlockDataStruct FISARFUDET_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM FISARFUDET: */
extern const FISARFUDET_NvMBlockDataStruct FISARFUDET_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM FISA_NVRAM_INT8_CONST_1: */
extern Std_ReturnType NVM_FISA_NVRAM_int8_const_1__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM FLOWMNG: */
extern FLOWMNG_NvMBlockDataStruct FLOWMNG_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM FLOWMNG: */
extern const FLOWMNG_NvMBlockDataStruct FLOWMNG_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM FTPCTL: */
extern FTPCTL_NvMBlockDataStruct FTPCTL_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM FTPCTL: */
extern const FTPCTL_NvMBlockDataStruct FTPCTL_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM FUCNS: */
extern FUCNS_NvMBlockDataStruct FUCNS_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM FUCNS: */
extern const FUCNS_NvMBlockDataStruct FUCNS_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM FULVL: */
extern FULVL_NvMBlockDataStruct FULVL_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM FULVL: */
extern const FULVL_NvMBlockDataStruct FULVL_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM WUC: */
extern WUC_NvMBlockDataStruct WUC_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM WUC: */
extern const WUC_NvMBlockDataStruct WUC_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM STATUSOFDTC: */
extern STATUSOFDTC_NvMBlockDataStruct STATUSOFDTC_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM STATUSOFDTC: */
extern const STATUSOFDTC_NvMBlockDataStruct STATUSOFDTC_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM INDICOBD: */
extern INDICOBD_NvMBlockDataStruct INDICOBD_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM INDICOBD: */
extern const INDICOBD_NvMBlockDataStruct INDICOBD_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM IUPRGENDEN: */
extern IUPRGENDEN_NvMBlockDataStruct IUPRGENDEN_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM IUPRGENDEN: */
extern const IUPRGENDEN_NvMBlockDataStruct IUPRGENDEN_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM RC01: */
extern RC01_NvMBlockDataStruct RC01_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM RC01: */
extern const RC01_NvMBlockDataStruct RC01_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM GOBD: */
extern GOBD_NvMBlockDataStruct GOBD_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM GOBD: */
extern const GOBD_NvMBlockDataStruct GOBD_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM IUPRRATIO: */
extern IUPRRATIO_NvMBlockDataStruct IUPRRATIO_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM IUPRRATIO: */
extern const IUPRRATIO_NvMBlockDataStruct IUPRRATIO_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM1: */
extern MEM1_NvMBlockDataStruct MEM1_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM1: */
extern const MEM1_NvMBlockDataStruct MEM1_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM2: */
extern MEM2_NvMBlockDataStruct MEM2_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM2: */
extern const MEM2_NvMBlockDataStruct MEM2_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM3: */
extern MEM3_NvMBlockDataStruct MEM3_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM3: */
extern const MEM3_NvMBlockDataStruct MEM3_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM4: */
extern MEM4_NvMBlockDataStruct MEM4_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM4: */
extern const MEM4_NvMBlockDataStruct MEM4_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM5: */
extern MEM5_NvMBlockDataStruct MEM5_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM5: */
extern const MEM5_NvMBlockDataStruct MEM5_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM6: */
extern MEM6_NvMBlockDataStruct MEM6_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM6: */
extern const MEM6_NvMBlockDataStruct MEM6_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM7: */
extern MEM7_NvMBlockDataStruct MEM7_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM7: */
extern const MEM7_NvMBlockDataStruct MEM7_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM8: */
extern MEM8_NvMBlockDataStruct MEM8_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM8: */
extern const MEM8_NvMBlockDataStruct MEM8_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM9: */
extern MEM9_NvMBlockDataStruct MEM9_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM9: */
extern const MEM9_NvMBlockDataStruct MEM9_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM10: */
extern MEM10_NvMBlockDataStruct MEM10_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM10: */
extern const MEM10_NvMBlockDataStruct MEM10_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM11: */
extern MEM11_NvMBlockDataStruct MEM11_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM11: */
extern const MEM11_NvMBlockDataStruct MEM11_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM12: */
extern MEM12_NvMBlockDataStruct MEM12_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM12: */
extern const MEM12_NvMBlockDataStruct MEM12_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM13: */
extern MEM13_NvMBlockDataStruct MEM13_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM13: */
extern const MEM13_NvMBlockDataStruct MEM13_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM14: */
extern MEM14_NvMBlockDataStruct MEM14_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM14: */
extern const MEM14_NvMBlockDataStruct MEM14_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM15: */
extern MEM15_NvMBlockDataStruct MEM15_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM15: */
extern const MEM15_NvMBlockDataStruct MEM15_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM16: */
extern MEM16_NvMBlockDataStruct MEM16_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM16: */
extern const MEM16_NvMBlockDataStruct MEM16_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM17: */
extern MEM17_NvMBlockDataStruct MEM17_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM17: */
extern const MEM17_NvMBlockDataStruct MEM17_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM18: */
extern MEM18_NvMBlockDataStruct MEM18_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM18: */
extern const MEM18_NvMBlockDataStruct MEM18_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM19: */
extern MEM19_NvMBlockDataStruct MEM19_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM19: */
extern const MEM19_NvMBlockDataStruct MEM19_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM20: */
extern MEM20_NvMBlockDataStruct MEM20_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM20: */
extern const MEM20_NvMBlockDataStruct MEM20_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM21: */
extern MEM21_NvMBlockDataStruct MEM21_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM21: */
extern const MEM21_NvMBlockDataStruct MEM21_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM22: */
extern MEM22_NvMBlockDataStruct MEM22_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM22: */
extern const MEM22_NvMBlockDataStruct MEM22_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM23: */
extern MEM23_NvMBlockDataStruct MEM23_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM23: */
extern const MEM23_NvMBlockDataStruct MEM23_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM24: */
extern MEM24_NvMBlockDataStruct MEM24_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM24: */
extern const MEM24_NvMBlockDataStruct MEM24_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM25: */
extern MEM25_NvMBlockDataStruct MEM25_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM25: */
extern const MEM25_NvMBlockDataStruct MEM25_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM26: */
extern MEM26_NvMBlockDataStruct MEM26_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM26: */
extern const MEM26_NvMBlockDataStruct MEM26_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM27: */
extern MEM27_NvMBlockDataStruct MEM27_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM27: */
extern const MEM27_NvMBlockDataStruct MEM27_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM28: */
extern MEM28_NvMBlockDataStruct MEM28_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM28: */
extern const MEM28_NvMBlockDataStruct MEM28_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM29: */
extern MEM29_NvMBlockDataStruct MEM29_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM29: */
extern const MEM29_NvMBlockDataStruct MEM29_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM30: */
extern MEM30_NvMBlockDataStruct MEM30_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM30: */
extern const MEM30_NvMBlockDataStruct MEM30_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM31: */
extern MEM31_NvMBlockDataStruct MEM31_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM31: */
extern const MEM31_NvMBlockDataStruct MEM31_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM32: */
extern MEM32_NvMBlockDataStruct MEM32_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM32: */
extern const MEM32_NvMBlockDataStruct MEM32_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM33: */
extern MEM33_NvMBlockDataStruct MEM33_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM33: */
extern const MEM33_NvMBlockDataStruct MEM33_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM34: */
extern MEM34_NvMBlockDataStruct MEM34_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM34: */
extern const MEM34_NvMBlockDataStruct MEM34_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM35: */
extern MEM35_NvMBlockDataStruct MEM35_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM35: */
extern const MEM35_NvMBlockDataStruct MEM35_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM36: */
extern MEM36_NvMBlockDataStruct MEM36_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM36: */
extern const MEM36_NvMBlockDataStruct MEM36_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM37: */
extern MEM37_NvMBlockDataStruct MEM37_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM37: */
extern const MEM37_NvMBlockDataStruct MEM37_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM38: */
extern MEM38_NvMBlockDataStruct MEM38_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM38: */
extern const MEM38_NvMBlockDataStruct MEM38_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM39: */
extern MEM39_NvMBlockDataStruct MEM39_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM39: */
extern const MEM39_NvMBlockDataStruct MEM39_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MEM40: */
extern MEM40_NvMBlockDataStruct MEM40_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MEM40: */
extern const MEM40_NvMBlockDataStruct MEM40_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM GMIL: */
extern GMIL_NvMBlockDataStruct GMIL_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM GMIL: */
extern const GMIL_NvMBlockDataStruct GMIL_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM AASTART_BIDON: */
extern Std_ReturnType NVM_AaStart_Bidon__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_PED: */
extern Std_ReturnType NVM_Coh_Ped__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCPOC_PED2: */
extern Std_ReturnType NVM_ScpOc_Ped2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_PED2: */
extern Std_ReturnType NVM_Scg_Ped2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCPOC_PED1: */
extern Std_ReturnType NVM_ScpOc_Ped1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_PED1: */
extern Std_ReturnType NVM_Scg_Ped1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCKACCP: */
extern Std_ReturnType NVM_StuckAccP__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCPACCPSWT: */
extern Std_ReturnType NVM_ScpAccPSwt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCKACCPSWT: */
extern Std_ReturnType NVM_StuckAccPSwt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCGACCPSWT: */
extern Std_ReturnType NVM_ScgAccPSwt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COHACCPSWT: */
extern Std_ReturnType NVM_CohAccPSwt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_RACCP: */
extern Std_ReturnType NVM_Coh_rAccP__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM GRD_PACMES: */
extern Std_ReturnType NVM_Grd_pACMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HI_PACMES: */
extern Std_ReturnType NVM_Hi_pACMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LO_PACMES: */
extern Std_ReturnType NVM_Lo_pACMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM GRD_TCOMES: */
extern Std_ReturnType NVM_Grd_tCoMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_TCOMES: */
extern Std_ReturnType NVM_Oc_tCoMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_TCOMES: */
extern Std_ReturnType NVM_Scg_tCoMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_TCOMES: */
extern Std_ReturnType NVM_Scp_tCoMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_AIREXTPRESACQ: */
extern Std_ReturnType NVM_Scg_AirExtPresAcq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_AIREXTPRESACQ: */
extern Std_ReturnType NVM_Scp_AirExtPresAcq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_PDSTHRMES: */
extern Std_ReturnType NVM_Scp_pDsThrMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_PDSTHRMES: */
extern Std_ReturnType NVM_Scg_pDsThrMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_PBRKASI: */
extern Std_ReturnType NVM_Scp_pBrkAsi__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_PBRKASI: */
extern Std_ReturnType NVM_Scg_pBrkAsi__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM GRD_PBRKASI: */
extern Std_ReturnType NVM_Grd_pBrkAsi__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STALLCOH_PDSTHR: */
extern Std_ReturnType NVM_StallCoh_pDsThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CRKCOH_PDSTHR: */
extern Std_ReturnType NVM_CrkCoh_pDsThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STABCOH_PDSTHR: */
extern Std_ReturnType NVM_StabCoh_pDsThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM THRCOH_PDSTHR: */
extern Std_ReturnType NVM_ThrCoh_pDsThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_PDSTHR: */
extern Std_ReturnType NVM_ORng_pDsThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FLDCOH_PDSTHR: */
extern Std_ReturnType NVM_FldCoh_pDsThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM GRD_PDSTHR: */
extern Std_ReturnType NVM_Grd_pDsThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MAX_PAIREXT: */
extern Std_ReturnType NVM_Max_pAirExt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MIN_PAIREXT: */
extern Std_ReturnType NVM_Min_pAirExt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM GRD_PAIREXT: */
extern Std_ReturnType NVM_Grd_pAirExt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM GRD_PAIREXTOLD: */
extern Std_ReturnType NVM_Grd_pAirExtOld__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_PBRKASI: */
extern Std_ReturnType NVM_Coh_pBrkAsi__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_PRELBRKASI: */
extern Std_ReturnType NVM_Scp_pRelBrkAsi__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_PRELBRKASI: */
extern Std_ReturnType NVM_Scg_pRelBrkAsi__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM GRD_PRELBRKASI: */
extern Std_ReturnType NVM_Grd_pRelBrkAsi__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM BOOST1_PDSTHR: */
extern Std_ReturnType NVM_Boost1_pDsThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM BOOST2_PDSTHR: */
extern Std_ReturnType NVM_Boost2_pDsThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM BOOST3_PDSTHR: */
extern Std_ReturnType NVM_Boost3_pDsThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM BOOST4_PDSTHR: */
extern Std_ReturnType NVM_Boost4_pDsThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_TAIRMES: */
extern Std_ReturnType NVM_Oc_tAirMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_TAIRMES: */
extern Std_ReturnType NVM_Scg_tAirMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_TAIRMES: */
extern Std_ReturnType NVM_Scp_tAirMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM GRD_TAIRMES: */
extern Std_ReturnType NVM_Grd_tAirMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM NEGOFS_TAIRMES: */
extern Std_ReturnType NVM_NegOfs_tAirMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_TAIRMES: */
extern Std_ReturnType NVM_ORng_tAirMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM POSOFS_TAIRMES: */
extern Std_ReturnType NVM_PosOfs_tAirMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STALLCOH_TAIRMES: */
extern Std_ReturnType NVM_StallCoh_tAirMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DECELCOH_BRKPED: */
extern Std_ReturnType NVM_DecelCoh_BrkPed__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ACCELCOH_BRKPED: */
extern Std_ReturnType NVM_AccelCoh_BrkPed__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVCOH_BRKPED: */
extern Std_ReturnType NVM_InvCoh_BrkPed__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DECELCOH_BRKPEDBVH2P: */
extern Std_ReturnType NVM_DecelCoh_BrkPedBVH2p__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ACCELCOH_BRKPEDBVH2P: */
extern Std_ReturnType NVM_AccelCoh_BrkPedBVH2p__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COHBIT7_STDFTOBD: */
extern Std_ReturnType NVM_CohBit7_stDftOBD__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COHBIT4_STDFTOBD: */
extern Std_ReturnType NVM_CohBit4_stDftOBD__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COHBIT3_STDFTOBD: */
extern Std_ReturnType NVM_CohBit3_stDftOBD__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COHBIT2_STDFTOBD: */
extern Std_ReturnType NVM_CohBit2_stDftOBD__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CHKBATTSYS_IBATTMES: */
extern Std_ReturnType NVM_ChkBattSys_iBattMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CHKBATTSYS_TBATTMES: */
extern Std_ReturnType NVM_ChkBattSys_tBattMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CHKBATTSYS_UBATTCLC: */
extern Std_ReturnType NVM_ChkBattSys_uBattClc__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STFULVLDFT: */
extern Std_ReturnType NVM_StFuLvlDft__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_BMODSPTREQ: */
extern Std_ReturnType NVM_Coh_bModSptReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_STCLUAC: */
extern Std_ReturnType NVM_Coh_stCluAC__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_STPWRAC: */
extern Std_ReturnType NVM_Coh_stPwrAC__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_UDSLS: */
extern Std_ReturnType NVM_Scp_uDsLs__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_UDSLS: */
extern Std_ReturnType NVM_Oc_uDsLs__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_UDSLS: */
extern Std_ReturnType NVM_Scg_uDsLs__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_SIGGRDDIAG: */
extern Std_ReturnType NVM_ORng_SigGrdDiag__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_DSPLAUSFLD: */
extern Std_ReturnType NVM_ORng_DsPlausFld__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_DSPLAUSFCO: */
extern Std_ReturnType NVM_ORng_DsPlausFco__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_UUPLS: */
extern Std_ReturnType NVM_Oc_uUpLs__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_UUPLS: */
extern Std_ReturnType NVM_Scg_uUpLs__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_UUPLS: */
extern Std_ReturnType NVM_Scp_uUpLs__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_OXYSENSPERD: */
extern Std_ReturnType NVM_ORng_OxySensPerd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_OXYAPVPERD: */
extern Std_ReturnType NVM_ORng_OxyApvPerd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_USPLAUSFLD: */
extern Std_ReturnType NVM_ORng_UsPlausFld__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_USPLAUSFCO: */
extern Std_ReturnType NVM_ORng_UsPlausFco__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_CLUST: */
extern Std_ReturnType NVM_Coh_CluSt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCK_CLUST: */
extern Std_ReturnType NVM_Stuck_CluSt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_RCLUPEDPRSSMES: */
extern Std_ReturnType NVM_Scp_rCluPedPrssMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_RCLUPEDPRSSMES: */
extern Std_ReturnType NVM_Scg_rCluPedPrssMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_RCLUPEDPRSSMES: */
extern Std_ReturnType NVM_ORng_rCluPedPrssMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM GRD_RCLUPEDPRSSMES: */
extern Std_ReturnType NVM_Grd_rCluPedPrssMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FCTCLUP: */
extern Std_ReturnType NVM_FctCluP__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_DRVRFAN1: */
extern Std_ReturnType NVM_Oc_DrvrFan1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LO_DRVRFAN1: */
extern Std_ReturnType NVM_Lo_DrvrFan1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HI_DRVRFAN1: */
extern Std_ReturnType NVM_Hi_DrvrFan1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_DRVRFAN2: */
extern Std_ReturnType NVM_Oc_DrvrFan2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LO_DRVRFAN2: */
extern Std_ReturnType NVM_Lo_DrvrFan2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HI_DRVRFAN2: */
extern Std_ReturnType NVM_Hi_DrvrFan2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_STFANB1: */
extern Std_ReturnType NVM_Coh_StFanB1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_STFANB2LOSPD: */
extern Std_ReturnType NVM_Coh_StFanB2LoSpd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_STFANB2HISPD: */
extern Std_ReturnType NVM_Coh_StFanB2HiSpd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_STFANB2NOSPD: */
extern Std_ReturnType NVM_Coh_StFanB2NoSpd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CLSDRLY_STFANC: */
extern Std_ReturnType NVM_ClsdRly_StFanC__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM EL_STFANC: */
extern Std_ReturnType NVM_El_StFanC__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM UNVLD_STFANC: */
extern Std_ReturnType NVM_UnVld_StFanC__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CRITSC_STFANC: */
extern Std_ReturnType NVM_CritSc_StFanC__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ECI_STFANC: */
extern Std_ReturnType NVM_ECI_StFanC__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_ECTREQ: */
extern Std_ReturnType NVM_Scp_ECTReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_ECTREQ: */
extern Std_ReturnType NVM_Scg_ECTReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_ECTREQ: */
extern Std_ReturnType NVM_Oc_ECTReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LINBLOCKEDBUS: */
extern Std_ReturnType NVM_LinBlockedBus__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ALTABSENTECU: */
extern Std_ReturnType NVM_AltAbsentEcu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ETAT_ALT1: */
extern Std_ReturnType NVM_Etat_Alt1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ETAT_ALT2: */
extern Std_ReturnType NVM_Etat_Alt2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TRCK_TCOMES: */
extern Std_ReturnType NVM_Trck_tCoMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM WUP_TCOMES: */
extern Std_ReturnType NVM_Wup_tCoMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LOCSTRDRV: */
extern Std_ReturnType NVM_LoCstrDrv__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HICSTRDRV: */
extern Std_ReturnType NVM_HiCstrDrv__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELINFBSIDFT: */
extern Std_ReturnType NVM_ElInfBsiDft__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELCPTTRABSIDFT: */
extern Std_ReturnType NVM_ElCptTraBsiDft__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELCHKCONSDFT: */
extern Std_ReturnType NVM_ElChkConsDft__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELCONSDEFDFTVSLIM: */
extern Std_ReturnType NVM_ElConsDefDftVSLim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELCONSVARDFTVSLIM: */
extern Std_ReturnType NVM_ElConsVarDftVSLim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELCONSDEFDFTVSREG: */
extern Std_ReturnType NVM_ElConsDefDftVSReg__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELCONSVARDFTVSREG: */
extern Std_ReturnType NVM_ElConsVarDftVSReg__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELCONSINITDFTVSREG: */
extern Std_ReturnType NVM_ElConsInitDftVSReg__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELDFTCRSCTL: */
extern Std_ReturnType NVM_ElDftCrsCtl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ZEROFRAMECNTDFT: */
extern Std_ReturnType NVM_ZeroFrameCntDft__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM EVENFRAMECNTDFT: */
extern Std_ReturnType NVM_EvenFrameCntDft__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELFRAMECNTINCDFT: */
extern Std_ReturnType NVM_ElFrameCntIncDft__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELCONSCOHVSMAXP: */
extern Std_ReturnType NVM_ElConsCohVSMaxp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELCONSDEFDFTVSMAXP: */
extern Std_ReturnType NVM_ElConsDefDftVSMaxp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CRSCTLDFT: */
extern Std_ReturnType NVM_CrsCtlDft__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM F432LOST: */
extern Std_ReturnType NVM_F432Lost__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTEEPROM: */
extern Std_ReturnType NVM_DftEeprom__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FLASHCHK: */
extern Std_ReturnType NVM_FlashChk__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_BINHCRKALTHW: */
extern Std_ReturnType NVM_Scp_bInhCrkAltHw__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_BINHCRKALTHW: */
extern Std_ReturnType NVM_Scg_bInhCrkAltHw__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_UDFTSTACMD: */
extern Std_ReturnType NVM_Scp_uDftStaCmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_UDFTSTACMD: */
extern Std_ReturnType NVM_Scg_uDftStaCmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLD_UDFTSTACMD: */
extern Std_ReturnType NVM_Invld_uDftStaCmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_ENGSTOUTIDC: */
extern Std_ReturnType NVM_Scp_EngStOutIdc__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_ENGSTOUTIDC: */
extern Std_ReturnType NVM_Scg_EngStOutIdc__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_ENGSTOUTIDC: */
extern Std_ReturnType NVM_Oc_EngStOutIdc__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGPFUENGST: */
extern Std_ReturnType NVM_ORngPFuEngSt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGUNLOCKENGST: */
extern Std_ReturnType NVM_ORngUnlockEngSt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGSYNCENGST: */
extern Std_ReturnType NVM_ORngSyncEngSt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGSTRTENGST: */
extern Std_ReturnType NVM_ORngStrtEngSt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_DML: */
extern Std_ReturnType NVM_Scp_Dml__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_DML: */
extern Std_ReturnType NVM_Oc_Dml__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_DML: */
extern Std_ReturnType NVM_Scg_Dml__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM BLOCK_STRTR: */
extern Std_ReturnType NVM_Block_Strtr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM REDESLIM: */
extern Std_ReturnType NVM_RedESLim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_FUGAUGELVL: */
extern Std_ReturnType NVM_ORng_FuGaugeLvl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LOFULVL: */
extern Std_ReturnType NVM_LoFuLvl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_FUGAUGE: */
extern Std_ReturnType NVM_Oc_FuGauge__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_FUGAUGE: */
extern Std_ReturnType NVM_ORng_FuGauge__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_FUGAUGE: */
extern Std_ReturnType NVM_Scg_FuGauge__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_PROPFUPMP: */
extern Std_ReturnType NVM_Scg_PropFuPmp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_PROPFUPMP: */
extern Std_ReturnType NVM_Scp_PropFuPmp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_PROPFUPMP: */
extern Std_ReturnType NVM_Oc_PropFuPmp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MAP_PROPFUPMP: */
extern Std_ReturnType NVM_Map_PropFuPmp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM GRAVSCP_PROPFUPMP: */
extern Std_ReturnType NVM_GravScp_PropFuPmp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRQ_PROPFUPMP: */
extern Std_ReturnType NVM_Frq_PropFuPmp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM RVSGEAR: */
extern Std_ReturnType NVM_RvsGear__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_BNEUT: */
extern Std_ReturnType NVM_Scp_bNeut__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_BNEUT: */
extern Std_ReturnType NVM_Scg_bNeut__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_BNEUT: */
extern Std_ReturnType NVM_ORng_bNeut__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_STRTLOCK: */
extern Std_ReturnType NVM_Coh_StrtLock__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HI_DRVRSENO2DS: */
extern Std_ReturnType NVM_Hi_DrvrSenO2Ds__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LO_DRVRSENO2DS: */
extern Std_ReturnType NVM_Lo_DrvrSenO2Ds__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HI_DRVRSENO2US: */
extern Std_ReturnType NVM_Hi_DrvrSenO2Us__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LO_DRVRSENO2US: */
extern Std_ReturnType NVM_Lo_DrvrSenO2Us__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_USHEAT: */
extern Std_ReturnType NVM_ORng_UsHeat__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_DSHEAT: */
extern Std_ReturnType NVM_ORng_DsHeat__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_IGCOIL1CMD: */
extern Std_ReturnType NVM_Oc_IgCoil1Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_IGCOIL1CMD: */
extern Std_ReturnType NVM_Scp_IgCoil1Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_IGCOIL2CMD: */
extern Std_ReturnType NVM_Oc_IgCoil2Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_IGCOIL2CMD: */
extern Std_ReturnType NVM_Scp_IgCoil2Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_IGCOIL3CMD: */
extern Std_ReturnType NVM_Oc_IgCoil3Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_IGCOIL3CMD: */
extern Std_ReturnType NVM_Scp_IgCoil3Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_IGCOIL4CMD: */
extern Std_ReturnType NVM_Oc_IgCoil4Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_IGCOIL4CMD: */
extern Std_ReturnType NVM_Scp_IgCoil4Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CMMABSENT: */
extern Std_ReturnType NVM_CmmAbsent__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CAPT_VOLABSENT: */
extern Std_ReturnType NVM_CAPT_VOLAbsent__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF305: */
extern Std_ReturnType NVM_MissF305__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF305: */
extern Std_ReturnType NVM_ShoF305__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CHKF305: */
extern Std_ReturnType NVM_ChkF305__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CNTF305: */
extern Std_ReturnType NVM_CntF305__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF305P537: */
extern Std_ReturnType NVM_InvldF305P537__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF305P538: */
extern Std_ReturnType NVM_InvldF305P538__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF305P537: */
extern Std_ReturnType NVM_FrbdF305P537__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF30D: */
extern Std_ReturnType NVM_MissF30D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF30D: */
extern Std_ReturnType NVM_ShoF30D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF30DP263: */
extern Std_ReturnType NVM_InvldF30DP263__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF30DP264: */
extern Std_ReturnType NVM_InvldF30DP264__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF30DP265: */
extern Std_ReturnType NVM_InvldF30DP265__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF30DP266: */
extern Std_ReturnType NVM_InvldF30DP266__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF329: */
extern Std_ReturnType NVM_MissF329__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF329: */
extern Std_ReturnType NVM_ShoF329__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CHKF329: */
extern Std_ReturnType NVM_ChkF329__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CNTF329: */
extern Std_ReturnType NVM_CntF329__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF329P445: */
extern Std_ReturnType NVM_InvldF329P445__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF329P445: */
extern Std_ReturnType NVM_FrbdF329P445__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF329P397: */
extern Std_ReturnType NVM_FrbdF329P397__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF349: */
extern Std_ReturnType NVM_MissF349__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF349: */
extern Std_ReturnType NVM_ShoF349__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CHKF349: */
extern Std_ReturnType NVM_ChkF349__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CNTF349: */
extern Std_ReturnType NVM_CntF349__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF349P007: */
extern Std_ReturnType NVM_InvldF349P007__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF349P055: */
extern Std_ReturnType NVM_InvldF349P055__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF349P360: */
extern Std_ReturnType NVM_FrbdF349P360__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF349P057: */
extern Std_ReturnType NVM_FrbdF349P057__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF349P008: */
extern Std_ReturnType NVM_FrbdF349P008__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF349P007: */
extern Std_ReturnType NVM_FrbdF349P007__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF349P287: */
extern Std_ReturnType NVM_FrbdF349P287__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF349PM1434: */
extern Std_ReturnType NVM_FrbdF349PM1434__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF349P166: */
extern Std_ReturnType NVM_FrbdF349P166__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF34D: */
extern Std_ReturnType NVM_MissF34D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF34D: */
extern Std_ReturnType NVM_ShoF34D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CNTF34D: */
extern Std_ReturnType NVM_CntF34D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF34DFP0593: */
extern Std_ReturnType NVM_InvldF34DFP0593__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF34DPM1413: */
extern Std_ReturnType NVM_InvldF34DPM1413__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF34DP047: */
extern Std_ReturnType NVM_FrbdF34DP047__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF34DP043: */
extern Std_ReturnType NVM_FrbdF34DP043__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF34DP044: */
extern Std_ReturnType NVM_FrbdF34DP044__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF34DP045: */
extern Std_ReturnType NVM_FrbdF34DP045__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF34DFP0593: */
extern Std_ReturnType NVM_FrbdF34DFP0593__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF34DPM1413: */
extern Std_ReturnType NVM_FrbdF34DPM1413__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM UC_FREINABSENT: */
extern Std_ReturnType NVM_UC_FREINAbsent__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF38D: */
extern Std_ReturnType NVM_MissF38D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF38D: */
extern Std_ReturnType NVM_ShoF38D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CHKF38D: */
extern Std_ReturnType NVM_ChkF38D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CNTF38D: */
extern Std_ReturnType NVM_CntF38D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF38DP010: */
extern Std_ReturnType NVM_InvldF38DP010__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF38DP052: */
extern Std_ReturnType NVM_InvldF38DP052__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF3AD: */
extern Std_ReturnType NVM_MissF3AD__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF3AD: */
extern Std_ReturnType NVM_ShoF3AD__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CHKF3AD: */
extern Std_ReturnType NVM_ChkF3AD__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CNTF3AD: */
extern Std_ReturnType NVM_CntF3AD__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF3ADP337: */
extern Std_ReturnType NVM_FrbdF3ADP337__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF3C9: */
extern Std_ReturnType NVM_MissF3C9__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF3C9: */
extern Std_ReturnType NVM_ShoF3C9__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CHKF3C9: */
extern Std_ReturnType NVM_ChkF3C9__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CNTF3C9: */
extern Std_ReturnType NVM_CntF3C9__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF3C9P363: */
extern Std_ReturnType NVM_InvldF3C9P363__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF3C9P364: */
extern Std_ReturnType NVM_InvldF3C9P364__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF3C9P482: */
extern Std_ReturnType NVM_InvldF3C9P482__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF3C9P483: */
extern Std_ReturnType NVM_InvldF3C9P483__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF3C9P481: */
extern Std_ReturnType NVM_FrbdF3C9P481__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF3C9P364: */
extern Std_ReturnType NVM_FrbdF3C9P364__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF3C9P482: */
extern Std_ReturnType NVM_FrbdF3C9P482__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF3C9P483: */
extern Std_ReturnType NVM_FrbdF3C9P483__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF3CD: */
extern Std_ReturnType NVM_MissF3CD__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF3CD: */
extern Std_ReturnType NVM_ShoF3CD__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF3CDP225: */
extern Std_ReturnType NVM_InvldF3CDP225__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF3CDP515: */
extern Std_ReturnType NVM_InvldF3CDP515__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF3CDP319: */
extern Std_ReturnType NVM_InvldF3CDP319__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF3CDPM1387: */
extern Std_ReturnType NVM_FrbdF3CDPM1387__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF3CDP319: */
extern Std_ReturnType NVM_FrbdF3CDP319__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF412: */
extern Std_ReturnType NVM_MissF412__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF412: */
extern Std_ReturnType NVM_ShoF412__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF412P040: */
extern Std_ReturnType NVM_InvldF412P040__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF432: */
extern Std_ReturnType NVM_MissF432__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF432: */
extern Std_ReturnType NVM_ShoF432__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF432P214: */
extern Std_ReturnType NVM_InvldF432P214__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF432P249: */
extern Std_ReturnType NVM_FrbdF432P249__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF432P251: */
extern Std_ReturnType NVM_FrbdF432P251__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF432P402: */
extern Std_ReturnType NVM_FrbdF432P402__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF432P368: */
extern Std_ReturnType NVM_FrbdF432P368__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF432P369: */
extern Std_ReturnType NVM_FrbdF432P369__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF432PM1424: */
extern Std_ReturnType NVM_FrbdF432PM1424__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF44D: */
extern Std_ReturnType NVM_MissF44D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF44D: */
extern Std_ReturnType NVM_ShoF44D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF44DFP0535: */
extern Std_ReturnType NVM_InvldF44DFP0535__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF44DP330: */
extern Std_ReturnType NVM_InvldF44DP330__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF44DP331: */
extern Std_ReturnType NVM_InvldF44DP331__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF44DP354: */
extern Std_ReturnType NVM_InvldF44DP354__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF44DP354: */
extern Std_ReturnType NVM_FrbdF44DP354__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM BVABSENT: */
extern Std_ReturnType NVM_BVAbsent__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF489: */
extern Std_ReturnType NVM_MissF489__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF489: */
extern Std_ReturnType NVM_ShoF489__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF489P102: */
extern Std_ReturnType NVM_InvldF489P102__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF489P254: */
extern Std_ReturnType NVM_InvldF489P254__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF489P218: */
extern Std_ReturnType NVM_InvldF489P218__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF489P254: */
extern Std_ReturnType NVM_FrbdF489P254__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF489P218: */
extern Std_ReturnType NVM_FrbdF489P218__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF492: */
extern Std_ReturnType NVM_MissF492__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF492: */
extern Std_ReturnType NVM_ShoF492__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF495: */
extern Std_ReturnType NVM_MissF495__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF495: */
extern Std_ReturnType NVM_ShoF495__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF4B2: */
extern Std_ReturnType NVM_MissF4B2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF4B2: */
extern Std_ReturnType NVM_ShoF4B2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF4D2: */
extern Std_ReturnType NVM_MissF4D2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF4D2: */
extern Std_ReturnType NVM_ShoF4D2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF4F2: */
extern Std_ReturnType NVM_MissF4F2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF4F2: */
extern Std_ReturnType NVM_ShoF4F2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF4F2P434: */
extern Std_ReturnType NVM_InvldF4F2P434__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF4F2P438: */
extern Std_ReturnType NVM_InvldF4F2P438__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF4F2P429: */
extern Std_ReturnType NVM_InvldF4F2P429__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF4F2P437: */
extern Std_ReturnType NVM_InvldF4F2P437__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF4F2P490: */
extern Std_ReturnType NVM_InvldF4F2P490__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF4F2P491: */
extern Std_ReturnType NVM_InvldF4F2P491__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF4F2P492: */
extern Std_ReturnType NVM_InvldF4F2P492__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF4F2P434: */
extern Std_ReturnType NVM_FrbdF4F2P434__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF4F2P438: */
extern Std_ReturnType NVM_FrbdF4F2P438__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF4F2P437: */
extern Std_ReturnType NVM_FrbdF4F2P437__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF4F2P490: */
extern Std_ReturnType NVM_FrbdF4F2P490__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF4F2P493: */
extern Std_ReturnType NVM_FrbdF4F2P493__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF4F2P491: */
extern Std_ReturnType NVM_FrbdF4F2P491__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF4F2P494: */
extern Std_ReturnType NVM_FrbdF4F2P494__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF4F2P492: */
extern Std_ReturnType NVM_FrbdF4F2P492__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF50D: */
extern Std_ReturnType NVM_MissF50D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF50D: */
extern Std_ReturnType NVM_ShoF50D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CHKF50D: */
extern Std_ReturnType NVM_ChkF50D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CNTF50D: */
extern Std_ReturnType NVM_CntF50D__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM BSIABSENT: */
extern Std_ReturnType NVM_BSIAbsent__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF50E: */
extern Std_ReturnType NVM_MissF50E__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF50E: */
extern Std_ReturnType NVM_ShoF50E__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF50EPM1386: */
extern Std_ReturnType NVM_InvldF50EPM1386__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF50EP046: */
extern Std_ReturnType NVM_InvldF50EP046__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF50EP210: */
extern Std_ReturnType NVM_InvldF50EP210__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF50EP046: */
extern Std_ReturnType NVM_FrbdF50EP046__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF50EP417: */
extern Std_ReturnType NVM_FrbdF50EP417__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF50EP208: */
extern Std_ReturnType NVM_FrbdF50EP208__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF532: */
extern Std_ReturnType NVM_MissF532__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF532: */
extern Std_ReturnType NVM_ShoF532__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF532PM1414: */
extern Std_ReturnType NVM_InvldF532PM1414__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF532PM1415: */
extern Std_ReturnType NVM_InvldF532PM1415__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF532PM1416: */
extern Std_ReturnType NVM_InvldF532PM1416__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF532PM1414: */
extern Std_ReturnType NVM_FrbdF532PM1414__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF532PM1415: */
extern Std_ReturnType NVM_FrbdF532PM1415__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF532PM1416: */
extern Std_ReturnType NVM_FrbdF532PM1416__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF552: */
extern Std_ReturnType NVM_MissF552__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF552: */
extern Std_ReturnType NVM_ShoF552__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF552P255: */
extern Std_ReturnType NVM_InvldF552P255__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF552P256: */
extern Std_ReturnType NVM_InvldF552P256__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF552P257: */
extern Std_ReturnType NVM_InvldF552P257__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF552P325: */
extern Std_ReturnType NVM_InvldF552P325__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF552P015: */
extern Std_ReturnType NVM_InvldF552P015__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF552P326: */
extern Std_ReturnType NVM_InvldF552P326__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF552P255: */
extern Std_ReturnType NVM_FrbdF552P255__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF552P256: */
extern Std_ReturnType NVM_FrbdF552P256__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF552P257: */
extern Std_ReturnType NVM_FrbdF552P257__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF572: */
extern Std_ReturnType NVM_MissF572__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF572: */
extern Std_ReturnType NVM_ShoF572__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF572PM1360: */
extern Std_ReturnType NVM_InvldF572PM1360__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF572PM1360: */
extern Std_ReturnType NVM_FrbdF572PM1360__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DMTRABSENT: */
extern Std_ReturnType NVM_DMTRAbsent__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF57C: */
extern Std_ReturnType NVM_MissF57C__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF57C: */
extern Std_ReturnType NVM_ShoF57C__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF57CPM1418: */
extern Std_ReturnType NVM_InvldF57CPM1418__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF592: */
extern Std_ReturnType NVM_MissF592__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF592: */
extern Std_ReturnType NVM_ShoF592__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LIDF592: */
extern Std_ReturnType NVM_LIDF592__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF592P272: */
extern Std_ReturnType NVM_InvldF592P272__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF592P273: */
extern Std_ReturnType NVM_InvldF592P273__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF592P349: */
extern Std_ReturnType NVM_InvldF592P349__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF592P418: */
extern Std_ReturnType NVM_InvldF592P418__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF592P419: */
extern Std_ReturnType NVM_InvldF592P419__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF592P420: */
extern Std_ReturnType NVM_InvldF592P420__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF592P421_1: */
extern Std_ReturnType NVM_InvldF592P421_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF592P421_2: */
extern Std_ReturnType NVM_InvldF592P421_2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF592P421_3: */
extern Std_ReturnType NVM_InvldF592P421_3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF592P272: */
extern Std_ReturnType NVM_FrbdF592P272__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF592P273: */
extern Std_ReturnType NVM_FrbdF592P273__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF592P349: */
extern Std_ReturnType NVM_FrbdF592P349__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF592P418: */
extern Std_ReturnType NVM_FrbdF592P418__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF592P419: */
extern Std_ReturnType NVM_FrbdF592P419__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF592P421_1: */
extern Std_ReturnType NVM_FrbdF592P421_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF592P421_2: */
extern Std_ReturnType NVM_FrbdF592P421_2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF592P421_3: */
extern Std_ReturnType NVM_FrbdF592P421_3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF5B2: */
extern Std_ReturnType NVM_MissF5B2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF5B2: */
extern Std_ReturnType NVM_ShoF5B2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF5B2P146: */
extern Std_ReturnType NVM_InvldF5B2P146__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF5B2P146: */
extern Std_ReturnType NVM_FrbdF5B2P146__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF612: */
extern Std_ReturnType NVM_MissF612__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF612: */
extern Std_ReturnType NVM_ShoF612__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF612P260: */
extern Std_ReturnType NVM_InvldF612P260__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF612P436: */
extern Std_ReturnType NVM_InvldF612P436__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF612P705: */
extern Std_ReturnType NVM_InvldF612P705__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF612P927: */
extern Std_ReturnType NVM_FrbdF612P927__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF612P436: */
extern Std_ReturnType NVM_FrbdF612P436__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF792: */
extern Std_ReturnType NVM_MissF792__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF792: */
extern Std_ReturnType NVM_ShoF792__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSF7F2: */
extern Std_ReturnType NVM_MissF7F2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SHOF7F2: */
extern Std_ReturnType NVM_ShoF7F2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LIDF7F2: */
extern Std_ReturnType NVM_LIDF7F2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF7F2P146: */
extern Std_ReturnType NVM_InvldF7F2P146__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INVLDF7F2P015: */
extern Std_ReturnType NVM_InvldF7F2P015__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF7F2P849: */
extern Std_ReturnType NVM_FrbdF7F2P849__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FRBDF7F2P146: */
extern Std_ReturnType NVM_FrbdF7F2P146__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_INJ1CMD: */
extern Std_ReturnType NVM_Scp_Inj1Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_INJ1CMD: */
extern Std_ReturnType NVM_Oc_Inj1Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_INJ2CMD: */
extern Std_ReturnType NVM_Scp_Inj2Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_INJ2CMD: */
extern Std_ReturnType NVM_Oc_Inj2Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_INJ3CMD: */
extern Std_ReturnType NVM_Scp_Inj3Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_INJ3CMD: */
extern Std_ReturnType NVM_Oc_Inj3Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_INJ4CMD: */
extern Std_ReturnType NVM_Scp_Inj4Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_INJ4CMD: */
extern Std_ReturnType NVM_Oc_Inj4Cmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGLFBK_AFL: */
extern Std_ReturnType NVM_ORngLfbk_Afl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTFU_AFL: */
extern Std_ReturnType NVM_DftFu_Afl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTSENO2_AFL: */
extern Std_ReturnType NVM_DftSenO2_Afl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGLFBKGAS_AFL: */
extern Std_ReturnType NVM_ORngLfbkGas_Afl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTFUGAS_AFL: */
extern Std_ReturnType NVM_DftFuGas_Afl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTSENO2GAS_AFL: */
extern Std_ReturnType NVM_DftSenO2Gas_Afl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGLFBK_AFR: */
extern Std_ReturnType NVM_ORngLfbk_Afr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTFU_AFR: */
extern Std_ReturnType NVM_DftFu_Afr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTSENO2_AFR: */
extern Std_ReturnType NVM_DftSenO2_Afr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGLFBKGAS_AFR: */
extern Std_ReturnType NVM_ORngLfbkGas_Afr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTFUGAS_AFR: */
extern Std_ReturnType NVM_DftFuGas_Afr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTSENO2GAS_AFR: */
extern Std_ReturnType NVM_DftSenO2Gas_Afr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HITALT_ALTCTL: */
extern Std_ReturnType NVM_HiTAlt_AltCtl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MECAALT_ALTCTL: */
extern Std_ReturnType NVM_MecaAlt_AltCtl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELECALT_ALTCTL: */
extern Std_ReturnType NVM_ElecAlt_AltCtl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COMALT_ALTCTL: */
extern Std_ReturnType NVM_ComAlt_AltCtl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_KNKDIAG: */
extern Std_ReturnType NVM_ORng_KnkDiag__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HHIT_NOISEADP: */
extern Std_ReturnType NVM_HHit_NoiseAdp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LHIT_NOISEADP: */
extern Std_ReturnType NVM_LHit_NoiseAdp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HSLD_NOISEADP: */
extern Std_ReturnType NVM_HSld_NoiseAdp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LSLD_NOISEADP: */
extern Std_ReturnType NVM_LSld_NoiseAdp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_SHRTWINLRN: */
extern Std_ReturnType NVM_ORng_ShrtWinLrn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_LONGWINLRN: */
extern Std_ReturnType NVM_ORng_LongWinLrn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_SHRTWINLRNMAX: */
extern Std_ReturnType NVM_ORng_ShrtWinLrnMax__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_LONGWINLRNMAX: */
extern Std_ReturnType NVM_ORng_LongWinLrnMax__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LOSTMISFROUGHNSROAD: */
extern Std_ReturnType NVM_LostMisfRoughnsRoad__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATMD1: */
extern Std_ReturnType NVM_ORngDmgCatMD1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATMD2: */
extern Std_ReturnType NVM_ORngDmgCatMD2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATMD3: */
extern Std_ReturnType NVM_ORngDmgCatMD3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATMD4: */
extern Std_ReturnType NVM_ORngDmgCatMD4__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATMDALL: */
extern Std_ReturnType NVM_ORngDmgCatMDAll__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATDTC1: */
extern Std_ReturnType NVM_ORngDmgCatDTC1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATDTC2: */
extern Std_ReturnType NVM_ORngDmgCatDTC2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATDTC3: */
extern Std_ReturnType NVM_ORngDmgCatDTC3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATDTC4: */
extern Std_ReturnType NVM_ORngDmgCatDTC4__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATDTCALL: */
extern Std_ReturnType NVM_ORngDmgCatDTCAll__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGMISFEMI1: */
extern Std_ReturnType NVM_ORngMisfEmi1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGMISFEMI2: */
extern Std_ReturnType NVM_ORngMisfEmi2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGMISFEMI3: */
extern Std_ReturnType NVM_ORngMisfEmi3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGMISFEMI4: */
extern Std_ReturnType NVM_ORngMisfEmi4__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGMISFEMIALL: */
extern Std_ReturnType NVM_ORngMisfEmiAll__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATMDGAZ1: */
extern Std_ReturnType NVM_ORngDmgCatMDGaz1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATMDGAZ2: */
extern Std_ReturnType NVM_ORngDmgCatMDGaz2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATMDGAZ3: */
extern Std_ReturnType NVM_ORngDmgCatMDGaz3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATMDGAZ4: */
extern Std_ReturnType NVM_ORngDmgCatMDGaz4__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATMDGAZALL: */
extern Std_ReturnType NVM_ORngDmgCatMDGazAll__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATDTCGAZ1: */
extern Std_ReturnType NVM_ORngDmgCatDTCGaz1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATDTCGAZ2: */
extern Std_ReturnType NVM_ORngDmgCatDTCGaz2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATDTCGAZ3: */
extern Std_ReturnType NVM_ORngDmgCatDTCGaz3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATDTCGAZ4: */
extern Std_ReturnType NVM_ORngDmgCatDTCGaz4__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGDMGCATDTCGAZALL: */
extern Std_ReturnType NVM_ORngDmgCatDTCGazAll__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGMISFEMIGAZ1: */
extern Std_ReturnType NVM_ORngMisfEmiGaz1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGMISFEMIGAZ2: */
extern Std_ReturnType NVM_ORngMisfEmiGaz2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGMISFEMIGAZ3: */
extern Std_ReturnType NVM_ORngMisfEmiGaz3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGMISFEMIGAZ4: */
extern Std_ReturnType NVM_ORngMisfEmiGaz4__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGMISFEMIGAZALL: */
extern Std_ReturnType NVM_ORngMisfEmiGazAll__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTSENR_ACCP: */
extern Std_ReturnType NVM_DftSenr_AccP__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_BINHCRKALTHW: */
extern Std_ReturnType NVM_Oc_bInhCrkAltHw__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LO_UBATTSPC: */
extern Std_ReturnType NVM_Lo_uBattSpc__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_VMES4: */
extern Std_ReturnType NVM_ORng_vMes4__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_VMES4_SFTY: */
extern Std_ReturnType NVM_ORng_vMes4_Sfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ALTABSENT: */
extern Std_ReturnType NVM_AltAbsent__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM BUSOFF: */
extern Std_ReturnType NVM_BusOff__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LINBLOCKED: */
extern Std_ReturnType NVM_LinBlocked__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_CAT: */
extern Std_ReturnType NVM_ORng_Cat__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_CATAPV: */
extern Std_ReturnType NVM_ORng_CatApv__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ABSESPMUTE: */
extern Std_ReturnType NVM_AbsEspMute__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM BSIMUTE: */
extern Std_ReturnType NVM_BsiMute__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM BVAMUTE: */
extern Std_ReturnType NVM_BvaMute__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ECMMUTE: */
extern Std_ReturnType NVM_EcmMute__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DIRAMUTE: */
extern Std_ReturnType NVM_DiraMute__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CAVMUTE: */
extern Std_ReturnType NVM_CAVMute__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DMTRMUTE: */
extern Std_ReturnType NVM_DmtrMute__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM F552BISP325INVLD: */
extern Std_ReturnType NVM_F552bisP325Invld__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM F552P255INVLD: */
extern Std_ReturnType NVM_F552P255Invld__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM F552P256INVLD: */
extern Std_ReturnType NVM_F552P256Invld__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM F552P257INVLD: */
extern Std_ReturnType NVM_F552P257Invld__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HI_DMPVLVCMD: */
extern Std_ReturnType NVM_Hi_DmpVlvCmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LO_DMPVLVCMD: */
extern Std_ReturnType NVM_Lo_DmpVlvCmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HI_WGCCMD: */
extern Std_ReturnType NVM_Hi_WgcCmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LO_WGCCMD: */
extern Std_ReturnType NVM_Lo_WgcCmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_CTLPMPREQ: */
extern Std_ReturnType NVM_Oc_CtlPmpReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_CTP1: */
extern Std_ReturnType NVM_Oc_CTP1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_CTP2: */
extern Std_ReturnType NVM_Oc_CTP2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_TRBWAPMP: */
extern Std_ReturnType NVM_Oc_TrbWaPmp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_CTLPMPREQ: */
extern Std_ReturnType NVM_Scg_CtlPmpReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_CTP1: */
extern Std_ReturnType NVM_Scg_CTP1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_CTP1: */
extern Std_ReturnType NVM_Scp_CTP1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_CTP2: */
extern Std_ReturnType NVM_Scg_CTP2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_CTP2: */
extern Std_ReturnType NVM_Scp_CTP2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_TRBWAPMP: */
extern Std_ReturnType NVM_Scg_TrbWaPmp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_CTLPMPREQ: */
extern Std_ReturnType NVM_Scp_CtlPmpReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_TRBWAPMP: */
extern Std_ReturnType NVM_Scp_TrbWaPmp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_BLOWBY1: */
extern Std_ReturnType NVM_Scg_BlowBy1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_BLOWBY2: */
extern Std_ReturnType NVM_Scg_BlowBy2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_BLOWBY1: */
extern Std_ReturnType NVM_Scp_BlowBy1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_BLOWBY2: */
extern Std_ReturnType NVM_Scp_BlowBy2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_BLOWBY1: */
extern Std_ReturnType NVM_Oc_BlowBy1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_BLOWBY2: */
extern Std_ReturnType NVM_Oc_BlowBy2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGHITOILESTIM: */
extern Std_ReturnType NVM_ORngHiTOilEstim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM PWRLMRK: */
extern Std_ReturnType NVM_PwrlMrk__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_VSSNWACVREQ: */
extern Std_ReturnType NVM_Scp_VSSNwAcvReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_VSSNWACVREQ: */
extern Std_ReturnType NVM_Scg_VSSNwAcvReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HI_UBATTMES: */
extern Std_ReturnType NVM_Hi_uBattMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LO_UBATTMES: */
extern Std_ReturnType NVM_Lo_uBattMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_VMES1: */
extern Std_ReturnType NVM_ORng_vMes1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_VMES1_SFTY: */
extern Std_ReturnType NVM_ORng_vMes1_Sfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_VMES2: */
extern Std_ReturnType NVM_ORng_vMes2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_VMES2_SFTY: */
extern Std_ReturnType NVM_ORng_vMes2_Sfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_VMES3: */
extern Std_ReturnType NVM_ORng_vMes3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_VMES3_SFTY: */
extern Std_ReturnType NVM_ORng_vMes3_Sfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INV_CALID: */
extern Std_ReturnType NVM_Inv_CalId__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCK_MAINRLY: */
extern Std_ReturnType NVM_Stuck_MainRly__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCK_PWRRLY: */
extern Std_ReturnType NVM_Stuck_PwrRly__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCP_PWRRLY: */
extern Std_ReturnType NVM_Scp_PwrRly__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OC_PWRRLY: */
extern Std_ReturnType NVM_Oc_PwrRly__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCG_PWRRLY: */
extern Std_ReturnType NVM_Scg_PwrRly__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFT_INFO_CRASH: */
extern Std_ReturnType NVM_Dft_Info_Crash__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFA_ADPAREFFEGRVLVLIM: */
extern Std_ReturnType NVM_AFA_AdpArEffEGRVlvLim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFA_ADPAREFFTHROFS1LIM: */
extern Std_ReturnType NVM_AFA_AdpArEffThrOfs1Lim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFA_ADPAREFFTHROFS2LIM: */
extern Std_ReturnType NVM_AFA_AdpArEffThrOfs2Lim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFA_ADPAREFFTHROFS3LIM: */
extern Std_ReturnType NVM_AFA_AdpArEffThrOfs3Lim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFA_ADPAREFFTHROFSLIM: */
extern Std_ReturnType NVM_AFA_AdpArEffThrOfsLim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFA_ADPCLSEXOFSLIM: */
extern Std_ReturnType NVM_AFA_AdpClsExOfsLim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFA_ADPINJOFSLIM: */
extern Std_ReturnType NVM_AFA_AdpInjOfsLim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFA_ADPIVSINJCONLIM: */
extern Std_ReturnType NVM_AFA_AdpIvsInjConLim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFA_ADPOPINOFSLIM: */
extern Std_ReturnType NVM_AFA_AdpOpInOfsLim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM AFA_ADPSLOPINJCONLIM: */
extern Std_ReturnType NVM_AFA_AdpSlopInjConLim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ANTIBOIL: */
extern Std_ReturnType NVM_AntiBoil__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM BLT: */
extern Std_ReturnType NVM_Blt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CAT: */
extern Std_ReturnType NVM_Cat__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CATAPV: */
extern Std_ReturnType NVM_CatApv__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CKSIG: */
extern Std_ReturnType NVM_CkSig__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COSYSDFCT: */
extern Std_ReturnType NVM_CoSysDfct__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CORLOSS: */
extern Std_ReturnType NVM_CorLoss__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CORSPCUR: */
extern Std_ReturnType NVM_CorSpCur__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CUTREQ: */
extern Std_ReturnType NVM_CutReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FSFBLOCKCLS: */
extern Std_ReturnType NVM_FSFBlockCls__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM FSFBLOCKOP: */
extern Std_ReturnType NVM_FSFBlockOp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IRVENGSTOP: */
extern Std_ReturnType NVM_IrvEngStop__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LGENGRSTRTINH: */
extern Std_ReturnType NVM_LgEngRStrtInh__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MAINWKUDISRD: */
extern Std_ReturnType NVM_MainWkuDisrd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MAINWKUINCST: */
extern Std_ReturnType NVM_MainWkuIncst__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGCUTOFFREQ: */
extern Std_ReturnType NVM_ORngCutOffReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGGCCLU: */
extern Std_ReturnType NVM_ORngGcClu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGGCMINCLU: */
extern Std_ReturnType NVM_ORngGcMinClu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGGCNEUT: */
extern Std_ReturnType NVM_ORngGcNeut__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGGEARENACLU: */
extern Std_ReturnType NVM_ORngGearEnaClu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGGEARMINCLU: */
extern Std_ReturnType NVM_ORngGearMinClu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGGEARNEUT: */
extern Std_ReturnType NVM_ORngGearNeut__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGHIDRAGRED: */
extern Std_ReturnType NVM_ORngHiDragRed__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGHINEUT: */
extern Std_ReturnType NVM_ORngHiNeut__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGLODRAGRED: */
extern Std_ReturnType NVM_ORngLoDragRed__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGLONEUT: */
extern Std_ReturnType NVM_ORngLoNeut__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGMPLREQ: */
extern Std_ReturnType NVM_ORngMplReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGSTOPREQ: */
extern Std_ReturnType NVM_ORngStopReq__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OBSADP: */
extern Std_ReturnType NVM_ObsAdp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM PROTADP: */
extern Std_ReturnType NVM_ProtAdp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM RCDLINESCG: */
extern Std_ReturnType NVM_RCDLineScg__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM RATCONVTRACLC: */
extern Std_ReturnType NVM_RatConvTraClc__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SFTYORNGAMT: */
extern Std_ReturnType NVM_SftyORngAMT__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SFTYORNGAT: */
extern Std_ReturnType NVM_SftyORngAT__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SPDVEHCLC: */
extern Std_ReturnType NVM_SpdVehClc__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STAACVTHD1: */
extern Std_ReturnType NVM_StaAcvThd1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STAACVTHD2: */
extern Std_ReturnType NVM_StaAcvThd2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STACMD: */
extern Std_ReturnType NVM_StaCmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STACMDINFO: */
extern Std_ReturnType NVM_StaCmdInfo__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STAELCMD: */
extern Std_ReturnType NVM_StaElCmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCKMEC: */
extern Std_ReturnType NVM_StuckMec__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TCOBLOCK: */
extern Std_ReturnType NVM_TCoBlock__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TCOOVERESTIM: */
extern Std_ReturnType NVM_TCoOverEstim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TCOSLOWRISE: */
extern Std_ReturnType NVM_TCoSlowRise__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TCOUNDESTIM: */
extern Std_ReturnType NVM_TCoUndEstim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TCOWARN: */
extern Std_ReturnType NVM_TCoWarn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM THERMOSTUCKCLS: */
extern Std_ReturnType NVM_ThermoStuckCls__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM THERMOSTUCKOP: */
extern Std_ReturnType NVM_ThermoStuckOp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TQALT: */
extern Std_ReturnType NVM_TqAlt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM VSLIM: */
extern Std_ReturnType NVM_VSLim__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM VSLIMBODY: */
extern Std_ReturnType NVM_VSLimBody__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM VSMAX: */
extern Std_ReturnType NVM_VSMax__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM VSMAXP: */
extern Std_ReturnType NVM_VSMaxp__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM VSREG: */
extern Std_ReturnType NVM_VSReg__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM VSREGBODY: */
extern Std_ReturnType NVM_VSRegBody__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM VSREGVEH: */
extern Std_ReturnType NVM_VSRegVeh__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IBATTMAXCKG: */
extern Std_ReturnType NVM_iBattMaxCkg__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IBATTMES: */
extern Std_ReturnType NVM_iBattMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM RBATTSOC: */
extern Std_ReturnType NVM_rBattSoC__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM RESBATTIT: */
extern Std_ReturnType NVM_resBattIt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TBATTMES: */
extern Std_ReturnType NVM_tBattMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TQALTRV: */
extern Std_ReturnType NVM_tqAltRv__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM UBATTMES: */
extern Std_ReturnType NVM_uBattMes__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM UBATTMINCKG: */
extern Std_ReturnType NVM_uBattMinCkg__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM UBATTOC: */
extern Std_ReturnType NVM_uBattOc__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM UBATTRSTRT: */
extern Std_ReturnType NVM_uBattRstrt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM UBATTSTRT: */
extern Std_ReturnType NVM_uBattStrt__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM NOANSWCTLUNIT: */
extern Std_ReturnType NVM_NoAnswCtlUnit__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM WRGANSWCTLUNIT: */
extern Std_ReturnType NVM_WrgAnswCtlUnit__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IMMOCODNOTREAD: */
extern Std_ReturnType NVM_ImmoCodNotRead__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM NOGAP_CKSTS: */
extern Std_ReturnType NVM_NoGap_CkSts__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TOOTHCOH_CKSTS: */
extern Std_ReturnType NVM_ToothCoh_CkSts__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HITOOTHCOH_CKSTS: */
extern Std_ReturnType NVM_HiToothCoh_CkSts__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IUPRSYNT1: */
extern Std_ReturnType NVM_IUPRSynt1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IUPRSYNT2: */
extern Std_ReturnType NVM_IUPRSynt2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IUPRSYNT3: */
extern Std_ReturnType NVM_IUPRSynt3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SFTYCHKPT_PFCMNG: */
extern Std_ReturnType NVM_SftyChkPt_PfcMng__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IRVSTT: */
extern Std_ReturnType NVM_IrvSTT__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM RVLIH: */
extern Std_ReturnType NVM_RvLih__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IRVVSCTL: */
extern Std_ReturnType NVM_IrvVSCtl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INHCHKINITSFTY: */
extern Std_ReturnType NVM_InhChkInitSfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DRVTRA: */
extern Std_ReturnType NVM_DrvTra__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INHENGSTOPSTT: */
extern Std_ReturnType NVM_InhEngStopSTT__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IRVECU: */
extern Std_ReturnType NVM_IrvECU__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IRVEM: */
extern Std_ReturnType NVM_IrvEM__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COMSPI_CPU: */
extern Std_ReturnType NVM_ComSpi_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COMTOUT_CPU: */
extern Std_ReturnType NVM_ComTout_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SYNCMON_CPU: */
extern Std_ReturnType NVM_SyncMon_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ACCP_CPU: */
extern Std_ReturnType NVM_AccP_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM THR_CPU: */
extern Std_ReturnType NVM_Thr_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CLK_CPU: */
extern Std_ReturnType NVM_Clk_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ALGO_CPU: */
extern Std_ReturnType NVM_Algo_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COMSPI_CPUSFTY: */
extern Std_ReturnType NVM_ComSpi_CpuSfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COMTOUT_CPUSFTY: */
extern Std_ReturnType NVM_ComTout_CpuSfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SYNCMON_CPUSFTY: */
extern Std_ReturnType NVM_SyncMon_CpuSfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CLK_CPUSFTY: */
extern Std_ReturnType NVM_Clk_CpuSfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ALGO_CPUSFTY: */
extern Std_ReturnType NVM_Algo_CpuSfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CKSROM_CPUSFTY: */
extern Std_ReturnType NVM_CksRom_CpuSfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DEGMOD_CPUSFTY: */
extern Std_ReturnType NVM_DegMod_CpuSfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HI_AENG: */
extern Std_ReturnType NVM_Hi_aEng__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HI_NENG: */
extern Std_ReturnType NVM_Hi_nEng__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DISTSIG: */
extern Std_ReturnType NVM_DistSig__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_INCM: */
extern Std_ReturnType NVM_Coh_InCm__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_EXCM: */
extern Std_ReturnType NVM_Coh_ExCm__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ENGSPDCOHCK: */
extern Std_ReturnType NVM_EngSpdCohCk__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ENGSPDCOHINCM: */
extern Std_ReturnType NVM_EngSpdCohInCm__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ENGSPDCOHEXCM: */
extern Std_ReturnType NVM_EngSpdCohExCm__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM NOSIGCK: */
extern Std_ReturnType NVM_NoSigCk__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SIGLOSSCK: */
extern Std_ReturnType NVM_SigLossCk__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM NOSIGINCM: */
extern Std_ReturnType NVM_NoSigInCm__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SIGLOSSINCM: */
extern Std_ReturnType NVM_SigLossInCm__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM NOSIGEXCM: */
extern Std_ReturnType NVM_NoSigExCm__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SIGLOSSEXCM: */
extern Std_ReturnType NVM_SigLossExCm__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_TIENGSTOP: */
extern Std_ReturnType NVM_ORng_tiEngStop__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_TIENGSTOP: */
extern Std_ReturnType NVM_Coh_tiEngStop__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INV_VARCOD: */
extern Std_ReturnType NVM_Inv_VarCod__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGSERVO: */
extern Std_ReturnType NVM_ORngServo__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGSERVODIFPOS: */
extern Std_ReturnType NVM_ORngServoDifPos__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGSERVODIFNEG: */
extern Std_ReturnType NVM_ORngServoDifNeg__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ENDSTOPREQ1: */
extern Std_ReturnType NVM_EndStopReq1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ENDSTOPREQ2: */
extern Std_ReturnType NVM_EndStopReq2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CLSIDLCTL: */
extern Std_ReturnType NVM_ClsIdlCtl__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LIHREQ1: */
extern Std_ReturnType NVM_LihReq1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LIHREQ2: */
extern Std_ReturnType NVM_LihReq2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COHPOSNSNSR: */
extern Std_ReturnType NVM_CohPosnSnsr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCPPOSNSNSR1: */
extern Std_ReturnType NVM_ScpPosnSnsr1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCGPOSNSNSR1: */
extern Std_ReturnType NVM_ScgPosnSnsr1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCPPOSNSNSR2: */
extern Std_ReturnType NVM_ScpPosnSnsr2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SCGPOSNSNSR2: */
extern Std_ReturnType NVM_ScgPosnSnsr2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTSENR_THR: */
extern Std_ReturnType NVM_DftSenr_Thr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OVLD_THRCMD: */
extern Std_ReturnType NVM_Ovld_ThrCmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CPT_THRCMD: */
extern Std_ReturnType NVM_Cpt_ThrCmd__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM READPININHTHR_CPU: */
extern Std_ReturnType NVM_ReadPinInhThr_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM INHTHR_CPUSFTY: */
extern Std_ReturnType NVM_InhThr_CpuSfty__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OVLDTHERMOTHR: */
extern Std_ReturnType NVM_OvldThermoThr__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGSFTYDFTLIH: */
extern Std_ReturnType NVM_ORngSftyDftLih__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELDIAGINHPIN0_CPU: */
extern Std_ReturnType NVM_ElDiagInhPin0_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ELDIAGINHPIN1_CPU: */
extern Std_ReturnType NVM_ElDiagInhPin1_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MCPRAMTEST_CPU: */
extern Std_ReturnType NVM_McpRAMTest_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MCPFLASHCKS_CPU: */
extern Std_ReturnType NVM_McpFlashCks_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MCWCKSCALC_CPU: */
extern Std_ReturnType NVM_McwCksCalc_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MCWINITSFTYRSLT_CPU: */
extern Std_ReturnType NVM_McwInitSftyRslt_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MCWFCTTEST_CPU: */
extern Std_ReturnType NVM_McwFctTest_Cpu__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CLUDMGAFTS: */
extern Std_ReturnType NVM_CluDmgAfts__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM COH_SPDVEH: */
extern Std_ReturnType NVM_Coh_spdVeh__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNG_SPDVEH: */
extern Std_ReturnType NVM_ORng_spdVeh__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SERVOERRVLVACTEX: */
extern Std_ReturnType NVM_ServoErrVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IMAXVLVACTEX: */
extern Std_ReturnType NVM_IMaxVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGSPDVLVACTEX: */
extern Std_ReturnType NVM_ORngSpdVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGSHIFTVLVACTEX: */
extern Std_ReturnType NVM_ORngShiftVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSTOOTHVLVACTEX: */
extern Std_ReturnType NVM_MissToothVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TDCDIAGVLVACTEX: */
extern Std_ReturnType NVM_TDCDiagVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CLNERRVLVACTEX: */
extern Std_ReturnType NVM_ClnErrVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LRNENDSTOPVLVACTEX: */
extern Std_ReturnType NVM_LrnEndStopVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ENDSTOPOLDVLVACTEX: */
extern Std_ReturnType NVM_EndStopOldVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LRNFAILIMVLVACTEX: */
extern Std_ReturnType NVM_LrnFaiLimVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OLDLRNVLVACTEX: */
extern Std_ReturnType NVM_OldLrnVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LOVLVACTEXDRV: */
extern Std_ReturnType NVM_LoVlvActExDrv__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HIVLVACTEXDRV: */
extern Std_ReturnType NVM_HiVlvActExDrv__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTCVLVACTEX: */
extern Std_ReturnType NVM_DftCVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGCVLVACTEX: */
extern Std_ReturnType NVM_ORngCVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CMDCVLVACTEX: */
extern Std_ReturnType NVM_CmdCVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SLOWC1VLVACTEX: */
extern Std_ReturnType NVM_SlowC1VlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SLOWC2VLVACTEX: */
extern Std_ReturnType NVM_SlowC2VlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTHVLVACTEX: */
extern Std_ReturnType NVM_DftHVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGHVLVACTEX: */
extern Std_ReturnType NVM_ORngHVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CMDHVLVACTEX: */
extern Std_ReturnType NVM_CmdHVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCKHVLVACTEX: */
extern Std_ReturnType NVM_StuckHVlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SLOWH1VLVACTEX: */
extern Std_ReturnType NVM_SlowH1VlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCKH1VLVACTEX: */
extern Std_ReturnType NVM_StuckH1VlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SLOWH2VLVACTEX: */
extern Std_ReturnType NVM_SlowH2VlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCKH2VLVACTEX: */
extern Std_ReturnType NVM_StuckH2VlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCKH3VLVACTEX: */
extern Std_ReturnType NVM_StuckH3VlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DIFPOS1VLVACTEX: */
extern Std_ReturnType NVM_DifPos1VlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DIFPOS2VLVACTEX: */
extern Std_ReturnType NVM_DifPos2VlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DIFNEG1VLVACTEX: */
extern Std_ReturnType NVM_DifNeg1VlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DIFNEG2VLVACTEX: */
extern Std_ReturnType NVM_DifNeg2VlvActEx__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SERVOERRVLVACTIN: */
extern Std_ReturnType NVM_ServoErrVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM IMAXVLVACTIN: */
extern Std_ReturnType NVM_IMaxVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGSPDVLVACTIN: */
extern Std_ReturnType NVM_ORngSpdVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGSHIFTVLVACTIN: */
extern Std_ReturnType NVM_ORngShiftVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MISSTOOTHVLVACTIN: */
extern Std_ReturnType NVM_MissToothVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TDCDIAGVLVACTIN: */
extern Std_ReturnType NVM_TDCDiagVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CLNERRVLVACTIN: */
extern Std_ReturnType NVM_ClnErrVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LRNENDSTOPVLVACTIN: */
extern Std_ReturnType NVM_LrnEndStopVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ENDSTOPOLDVLVACTIN: */
extern Std_ReturnType NVM_EndStopOldVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LRNFAILIMVLVACTIN: */
extern Std_ReturnType NVM_LrnFaiLimVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM OLDLRNVLVACTIN: */
extern Std_ReturnType NVM_OldLrnVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM LOVLVACTINDRV: */
extern Std_ReturnType NVM_LoVlvActInDrv__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM HIVLVACTINDRV: */
extern Std_ReturnType NVM_HiVlvActInDrv__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTCVLVACTIN: */
extern Std_ReturnType NVM_DftCVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGCVLVACTIN: */
extern Std_ReturnType NVM_ORngCVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CMDCVLVACTIN: */
extern Std_ReturnType NVM_CmdCVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SLOWC1VLVACTIN: */
extern Std_ReturnType NVM_SlowC1VlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SLOWC2VLVACTIN: */
extern Std_ReturnType NVM_SlowC2VlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DFTHVLVACTIN: */
extern Std_ReturnType NVM_DftHVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ORNGHVLVACTIN: */
extern Std_ReturnType NVM_ORngHVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM CMDHVLVACTIN: */
extern Std_ReturnType NVM_CmdHVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCKHVLVACTIN: */
extern Std_ReturnType NVM_StuckHVlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SLOWH1VLVACTIN: */
extern Std_ReturnType NVM_SlowH1VlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCKH1VLVACTIN: */
extern Std_ReturnType NVM_StuckH1VlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM SLOWH2VLVACTIN: */
extern Std_ReturnType NVM_SlowH2VlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCKH2VLVACTIN: */
extern Std_ReturnType NVM_StuckH2VlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STUCKH3VLVACTIN: */
extern Std_ReturnType NVM_StuckH3VlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DIFPOS1VLVACTIN: */
extern Std_ReturnType NVM_DifPos1VlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DIFPOS2VLVACTIN: */
extern Std_ReturnType NVM_DifPos2VlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DIFNEG1VLVACTIN: */
extern Std_ReturnType NVM_DifNeg1VlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM DIFNEG2VLVACTIN: */
extern Std_ReturnType NVM_DifNeg2VlvActIn__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM ZZEND_BIDON: */
extern Std_ReturnType NVM_ZzEnd_Bidon__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM HEATSENO2DSDERIDIAG: */
extern HEATSENO2DSDERIDIAG_NvMBlockDataStruct HEATSENO2DSDERIDIAG_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM HEATSENO2DSDERIDIAG: */
extern const HEATSENO2DSDERIDIAG_NvMBlockDataStruct HEATSENO2DSDERIDIAG_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM HEATSENO2DS: */
extern HEATSENO2DS_NvMBlockDataStruct HEATSENO2DS_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM HEATSENO2DS: */
extern const HEATSENO2DS_NvMBlockDataStruct HEATSENO2DS_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM HEATSENO2US: */
extern HEATSENO2US_NvMBlockDataStruct HEATSENO2US_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM HEATSENO2US: */
extern const HEATSENO2US_NvMBlockDataStruct HEATSENO2US_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM IFAIRSYSIGSYS: */
extern IFAIRSYSIGSYS_NvMBlockDataStruct IFAIRSYSIGSYS_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM IFAIRSYSIGSYS: */
extern const IFAIRSYSIGSYS_NvMBlockDataStruct IFAIRSYSIGSYS_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM INJFARCTLDSCTL: */
extern INJFARCTLDSCTL_NvMBlockDataStruct INJFARCTLDSCTL_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM INJFARCTLDSCTL: */
extern const INJFARCTLDSCTL_NvMBlockDataStruct INJFARCTLDSCTL_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM MISFDFTLRN: */
extern MISFDFTLRN_NvMBlockDataStruct MISFDFTLRN_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM MISFDFTLRN: */
extern const MISFDFTLRN_NvMBlockDataStruct MISFDFTLRN_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM MPM_NVRAM_INT16_CONST: */
extern Std_ReturnType NVM_MPM_NVRAM_int16_const__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MPM_NVRAM_INT32_CONST: */
extern Std_ReturnType NVM_MPM_NVRAM_int32_const__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MPM_NVRAM_INT32_CONST_1: */
extern Std_ReturnType NVM_MPM_NVRAM_int32_const_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM MPM_NVRAM_INT32_CONST_2: */
extern Std_ReturnType NVM_MPM_NVRAM_int32_const_2__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM INJRCHRN: */
extern INJRCHRN_NvMBlockDataStruct INJRCHRN_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM INJRCHRN: */
extern const INJRCHRN_NvMBlockDataStruct INJRCHRN_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM OBDSRV06: */
extern OBDSRV06_NvMBlockDataStruct OBDSRV06_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM OBDSRV06: */
extern const OBDSRV06_NvMBlockDataStruct OBDSRV06_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM OBDSRV06: */
extern Std_ReturnType NVM_OBDSRV06_NVMSRV_vidInit(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM POSTEQUSRV_BANTISCANNING: */
extern POSTEQUSRV_BANTISCANNING_NvMBlockDataStruct POSTEQUSRV_BANTISCANNING_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM POSTEQUSRV_BANTISCANNING: */
extern const POSTEQUSRV_BANTISCANNING_NvMBlockDataStruct POSTEQUSRV_BANTISCANNING_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM PREDES: */
extern PREDES_NvMBlockDataStruct PREDES_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM PREDES: */
extern const PREDES_NvMBlockDataStruct PREDES_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT16_CONST_1: */
extern Std_ReturnType NVM_PRODELEM_NVRAM_int16_const_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT16_CONST_2: */
extern Std_ReturnType NVM_PRODELEM_NVRAM_int16_const_2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT32_CONST_1: */
extern Std_ReturnType NVM_PRODELEM_NVRAM_int32_const_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT32_CONST_2: */
extern Std_ReturnType NVM_PRODELEM_NVRAM_int32_const_2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT32_CONST_3: */
extern Std_ReturnType NVM_PRODELEM_NVRAM_int32_const_3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT8_CONST_1: */
extern Std_ReturnType NVM_PRODELEM_NVRAM_int8_const_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT8_CONST_2: */
extern Std_ReturnType NVM_PRODELEM_NVRAM_int8_const_2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM PRODELEM_NVRAM_BOOLEAN_CONST_1: */
extern Std_ReturnType NVM_PRODELEM_NVRAM_boolean_const_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM PRODELEM_NVRAM_BOOLEAN_CONST_2: */
extern Std_ReturnType NVM_PRODELEM_NVRAM_boolean_const_2__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM PRODELENG_NVRAM_INT32_CONST_1: */
extern Std_ReturnType NVM_PRODELENG_NVRAM_int32_const_1__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM PROTMANCLU: */
extern PROTMANCLU_NvMBlockDataStruct PROTMANCLU_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM PROTMANCLU: */
extern const PROTMANCLU_NvMBlockDataStruct PROTMANCLU_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM ECUSTSRVPWRLST: */
extern ECUSTSRVPWRLST_NvMBlockDataStruct ECUSTSRVPWRLST_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM ECUSTSRVPWRLST: */
extern const ECUSTSRVPWRLST_NvMBlockDataStruct ECUSTSRVPWRLST_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM REFIDETA: */
extern REFIDETA_NvMBlockDataStruct REFIDETA_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM REFIDETA: */
extern const REFIDETA_NvMBlockDataStruct REFIDETA_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM RANDOM: */
extern RANDOM_NvMBlockDataStruct RANDOM_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM RANDOM: */
extern const RANDOM_NvMBlockDataStruct RANDOM_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM SFTYMNGR: */
extern SFTYMNGR_NvMBlockDataStruct SFTYMNGR_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM SFTYMNGR: */
extern const SFTYMNGR_NvMBlockDataStruct SFTYMNGR_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM SPYEMSTT: */
extern SPYEMSTT_NvMBlockDataStruct SPYEMSTT_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM SPYEMSTT: */
extern const SPYEMSTT_NvMBlockDataStruct SPYEMSTT_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM SPYEMSTT: */
extern Std_ReturnType NVM_SPYEMSTT_NVMSRV_vidInit(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM SPYSTT: */
extern SPYSTT_NvMBlockDataStruct SPYSTT_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM SPYSTT: */
extern const SPYSTT_NvMBlockDataStruct SPYSTT_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM SPYSTT: */
extern Std_ReturnType NVM_SPYSTT_NVMSRV_vidInit(void);

/* Déclaration externe de la callback d'initialisation du block NVM STOPSTRTEM_NVRAM_INT16_CONST_3: */
extern Std_ReturnType NVM_STOPSTRTEM_NVRAM_int16_const_3__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STOPSTRTEM_NVRAM_INT32_CONST_1: */
extern Std_ReturnType NVM_STOPSTRTEM_NVRAM_int32_const_1__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM STOPSTRTEM_NVRAM_INT32_CONST_2: */
extern Std_ReturnType NVM_STOPSTRTEM_NVRAM_int32_const_2__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM SYNCENGCLC: */
extern SYNCENGCLC_NvMBlockDataStruct SYNCENGCLC_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM SYNCENGCLC: */
extern const SYNCENGCLC_NvMBlockDataStruct SYNCENGCLC_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM TELE_BANTISCANNING: */
extern TELE_BANTISCANNING_NvMBlockDataStruct TELE_BANTISCANNING_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM TELE_BANTISCANNING: */
extern const TELE_BANTISCANNING_NvMBlockDataStruct TELE_BANTISCANNING_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM THMGT_NVRAM_INT8_CONST: */
extern Std_ReturnType NVM_THMGT_NVRAM_int8_const__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM THMGT_NVRAM_BOOLEAN_CONST: */
extern Std_ReturnType NVM_THMGT_NVRAM_boolean_const__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM THRSPT_NVRAM_INT32_CONST: */
extern Std_ReturnType NVM_ThrSpT_NVRAM_int32_const__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM PAP_MOT: */
extern PAP_MOT_NvMBlockDataStruct PAP_MOT_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM PAP_MOT: */
extern const PAP_MOT_NvMBlockDataStruct PAP_MOT_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM PAP_MOT: */
extern Std_ReturnType NVM_pap_mot_NVMSRV_vidInit(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM TIENGSTOP: */
extern TIENGSTOP_NvMBlockDataStruct TIENGSTOP_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM TIENGSTOP: */
extern const TIENGSTOP_NvMBlockDataStruct TIENGSTOP_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM TOILEST: */
extern TOILEST_NvMBlockDataStruct TOILEST_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM TOILEST: */
extern const TOILEST_NvMBlockDataStruct TOILEST_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM TPM_NVRAM_INT16_CONST: */
extern Std_ReturnType NVM_TPM_NVRAM_int16_const__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TQADPCMP_NVRAM_INT16_CONST: */
extern Std_ReturnType NVM_TQADPCMP_NVRAM_int16_const__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TQADPCMP_NVRAM_INT32_CONST: */
extern Std_ReturnType NVM_TQADPCMP_NVRAM_int32_const__nvmini(void);

/* Déclaration externe de la callback d'initialisation du block NVM TQADPCMP_NVRAM_INT8_CONST: */
extern Std_ReturnType NVM_TQADPCMP_NVRAM_int8_const__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM TWCMGT: */
extern TWCMGT_NvMBlockDataStruct TWCMGT_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM TWCMGT: */
extern const TWCMGT_NvMBlockDataStruct TWCMGT_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM UPLSACQ: */
extern UPLSACQ_NvMBlockDataStruct UPLSACQ_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM UPLSACQ: */
extern const UPLSACQ_NvMBlockDataStruct UPLSACQ_NvMRomBlockDataStruct;

/* Déclaration externe de la callback d'initialisation du block NVM USTHRMT_NVRAM_INT16_CALIB: */
extern Std_ReturnType NVM_UsThrMT_NVRAM_int16_calib__nvmini(void);

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM VLVACTEXENDSTOP: */
extern VLVACTEXENDSTOP_NvMBlockDataStruct VLVACTEXENDSTOP_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM VLVACTEXENDSTOP: */
extern const VLVACTEXENDSTOP_NvMBlockDataStruct VLVACTEXENDSTOP_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM VLVACTINENDSTOP: */
extern VLVACTINENDSTOP_NvMBlockDataStruct VLVACTINENDSTOP_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM VLVACTINENDSTOP: */
extern const VLVACTINENDSTOP_NvMBlockDataStruct VLVACTINENDSTOP_NvMRomBlockDataStruct;

/* Déclaration externe de la structure NvMRamBlockDataStruct du block NVM VSC: */
extern VSC_NvMBlockDataStruct VSC_NvMRamBlockDataStruct;
/* Déclaration externe de la structure NvMRomBlockDataStruct du block NVM VSC: */
extern const VSC_NvMBlockDataStruct VSC_NvMRomBlockDataStruct;


#endif /* USERS_NVM_H */

/******************************************************************************/
/*                                                                            */
/* !Layer          : SRV                                                      */
/*                                                                            */
/* !Component      : NVRAM                                                    */
/*                                                                            */
/* !Module         : Vems_NVRAM                                               */
/* !Description    : Contains I/F Vems macro NVRAM component                  */
/*                                                                            */
/* !File           : Vems_NVRAM.H                                             */
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
/* $Archive::   P:/EBx_V46/LDA/REF/modules/NVRAM/Vems_NVRAM.h_v              $*/
/* $Revision::   1.4      $$Author::   ygorget     $$Date::   24 Sep 2014 12:$*/
/******************************************************************************/
/*       THIS FILE IS GENERATED AUTOMATICALY BY GenGlueCfromXLS TOOL          */
/*       Generated date 19/09/14 at 14:21:18                                   */
/******************************************************************************/

#ifndef VEMS_NVRAM_H
#define VEMS_NVRAM_H

#include "NVRAM_TYP.H"
#include "Users_NvM.H"


/*******************************************************************************************
    Creation des macros necessaires pour la variable NVMSRV_u16TestEeprom_1                       
********************************************************************************************/

#define NVMSRV_u16TestEeprom_1         TEST_EEPROM_1_NvMRamBlockDataStruct.NVMSRV_u16TestEeprom_1

/*******************************************************************************************
    Creation des macros necessaires pour la variable NVMSRV_u16TestEeprom_2                       
********************************************************************************************/

#define NVMSRV_u16TestEeprom_2         TEST_EEPROM_2_NvMRamBlockDataStruct.NVMSRV_u16TestEeprom_2

/*******************************************************************************************
    Creation des macros necessaires pour la variable NVMSRV_u32SavedReReadFrameCntr                       
********************************************************************************************/

#define NVMSRV_u32SavedReReadFrameCntr         SPI_REREAD_FRAMES_NvMRamBlockDataStruct.NVMSRV_u32SavedReReadFrameCntr

/*******************************************************************************************
    Creation des macros necessaires pour la variable EPMSRV_u8TdcCounter                       
********************************************************************************************/

#define EPMSRV_u8TdcCounter         EPMSRV_NvMRamBlockDataStruct.EPMSRV_u8TdcCounter

/*******************************************************************************************
    Creation des macros necessaires pour la variable Cpt_tel_eep                       
********************************************************************************************/

#define Cpt_tel_eep         DOWNLOAD_NvMRamBlockDataStruct.Cpt_tel_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Eep_nb_ecr_pages                       
********************************************************************************************/

#define Eep_nb_ecr_pages         ECRITURES_EEPROM_NvMRamBlockDataStruct.Eep_nb_ecr_pages

/*******************************************************************************************
    Creation des macros necessaires pour la variable Eep_nb_total_ecr_pages                       
********************************************************************************************/

#define Eep_nb_total_ecr_pages         ECRITURES_EEPROM_NvMRamBlockDataStruct.Eep_nb_total_ecr_pages

/*******************************************************************************************
    Creation des macros necessaires pour la variable RSTSRV_u16HotResetCtr                       
********************************************************************************************/

#define RSTSRV_u16HotResetCtr         RESET_NvMRamBlockDataStruct.RSTSRV_u16HotResetCtr

/*******************************************************************************************
    Creation des macros necessaires pour la variable ErrorStackIdx_eep                       
********************************************************************************************/

#define ErrorStackIdx_eep         EXCEPTION_REGS_NvMRamBlockDataStruct.ErrorStackIdx_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Compteur_defaut_pile_eep                       
********************************************************************************************/

#define Compteur_defaut_pile_eep         EXCEPTION_REGS_NvMRamBlockDataStruct.Compteur_defaut_pile_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Compteur_defaut_except_eep                       
********************************************************************************************/

#define Compteur_defaut_except_eep         EXCEPTION_REGS_NvMRamBlockDataStruct.Compteur_defaut_except_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Type_de_defaut_eep                       
********************************************************************************************/

#define Type_de_defaut_eep         EXCEPTION_REGS_NvMRamBlockDataStruct.Type_de_defaut_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable ErrorAddress_eep                       
********************************************************************************************/

#define ErrorAddress_eep         EXCEPTION_REGS_NvMRamBlockDataStruct.ErrorAddress_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable NVMSRV_u16TestEeprom_3                       
********************************************************************************************/

#define NVMSRV_u16TestEeprom_3         TEST_EEPROM_3_NvMRamBlockDataStruct.NVMSRV_u16TestEeprom_3

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8Prod1Reserve                         
******************************************************************************************/

#define RED_au8Prod1Reserve         REDPROD_1_NvMRamBlockDataStruct.RED_au8Prod1Reserve

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8ECUSerial                         
******************************************************************************************/

#define RED_au8ECUSerial         REDPROD_1_NvMRamBlockDataStruct.RED_au8ECUSerial

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8RefCIndex                         
******************************************************************************************/

#define RED_au8RefCIndex         REDPROD_1_NvMRamBlockDataStruct.RED_au8RefCIndex

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8RefCNum                         
******************************************************************************************/

#define RED_au8RefCNum         REDPROD_1_NvMRamBlockDataStruct.RED_au8RefCNum

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8RefAIndex                         
******************************************************************************************/

#define RED_au8RefAIndex         REDPROD_1_NvMRamBlockDataStruct.RED_au8RefAIndex

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8RefANum                         
******************************************************************************************/

#define RED_au8RefANum         REDPROD_1_NvMRamBlockDataStruct.RED_au8RefANum

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8Prod2Reserve                         
******************************************************************************************/

#define RED_au8Prod2Reserve         REDPROD_2_NvMRamBlockDataStruct.RED_au8Prod2Reserve

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8FuncProductNum                         
******************************************************************************************/

#define RED_au8FuncProductNum         REDPROD_2_NvMRamBlockDataStruct.RED_au8FuncProductNum

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8FuncSchematicNum                         
******************************************************************************************/

#define RED_au8FuncSchematicNum         REDPROD_2_NvMRamBlockDataStruct.RED_au8FuncSchematicNum

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8Prod5Reserve                         
******************************************************************************************/

#define RED_au8Prod5Reserve         REDPROD_5_NvMRamBlockDataStruct.RED_au8Prod5Reserve

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8InitialMcwRomChecksum                         
******************************************************************************************/

#define RED_au8InitialMcwRomChecksum         REDPROD_5_NvMRamBlockDataStruct.RED_au8InitialMcwRomChecksum

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8CieValeoNumIdx                         
******************************************************************************************/

#define RED_au8CieValeoNumIdx         REDPROD_5_NvMRamBlockDataStruct.RED_au8CieValeoNumIdx

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8CieValeoNum                         
******************************************************************************************/

#define RED_au8CieValeoNum         REDPROD_5_NvMRamBlockDataStruct.RED_au8CieValeoNum

/******************************************************************************************
   Creation des macros necessaires pour le tableau RED_au8Prod8Reserve                         
******************************************************************************************/

#define RED_au8Prod8Reserve         REDPROD_8_NvMRamBlockDataStruct.RED_au8Prod8Reserve

/*******************************************************************************************
    Creation des macros necessaires pour la variable RED_s8TrimGainOutput_CM_3                       
********************************************************************************************/

#define RED_s8TrimGainOutput_CM_3         REDPROD_8_NvMRamBlockDataStruct.RED_s8TrimGainOutput_CM_3

/*******************************************************************************************
    Creation des macros necessaires pour la variable RED_s8TrimGainOutput_CM_24                       
********************************************************************************************/

#define RED_s8TrimGainOutput_CM_24         REDPROD_8_NvMRamBlockDataStruct.RED_s8TrimGainOutput_CM_24

/*******************************************************************************************
    Creation des macros necessaires pour la variable RED_s8TrimGainOutput_CM_45                       
********************************************************************************************/

#define RED_s8TrimGainOutput_CM_45         REDPROD_8_NvMRamBlockDataStruct.RED_s8TrimGainOutput_CM_45

/*******************************************************************************************
    Creation des macros necessaires pour la variable RED_s8TrimGainOutput_CM_66                       
********************************************************************************************/

#define RED_s8TrimGainOutput_CM_66         REDPROD_8_NvMRamBlockDataStruct.RED_s8TrimGainOutput_CM_66

/*******************************************************************************************
    Creation des macros necessaires pour la variable RED_s8BatTrimOffset                       
********************************************************************************************/

#define RED_s8BatTrimOffset         REDPROD_8_NvMRamBlockDataStruct.RED_s8BatTrimOffset

/*******************************************************************************************
    Creation des macros necessaires pour la variable RED_s8BatTrimGain                       
********************************************************************************************/

#define RED_s8BatTrimGain         REDPROD_8_NvMRamBlockDataStruct.RED_s8BatTrimGain

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8Prod1Reserve                         
******************************************************************************************/

#define PROD_au8Prod1Reserve         PROD_1_VALEOIDENT_NvMRamBlockDataStruct.PROD_au8Prod1Reserve

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8ECUSerial                         
******************************************************************************************/

#define PROD_au8ECUSerial         PROD_1_VALEOIDENT_NvMRamBlockDataStruct.PROD_au8ECUSerial

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8RefCIndex                         
******************************************************************************************/

#define PROD_au8RefCIndex         PROD_1_VALEOIDENT_NvMRamBlockDataStruct.PROD_au8RefCIndex

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8RefCNum                         
******************************************************************************************/

#define PROD_au8RefCNum         PROD_1_VALEOIDENT_NvMRamBlockDataStruct.PROD_au8RefCNum

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8RefAIndex                         
******************************************************************************************/

#define PROD_au8RefAIndex         PROD_1_VALEOIDENT_NvMRamBlockDataStruct.PROD_au8RefAIndex

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8RefANum                         
******************************************************************************************/

#define PROD_au8RefANum         PROD_1_VALEOIDENT_NvMRamBlockDataStruct.PROD_au8RefANum

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8Prod2Reserve                         
******************************************************************************************/

#define PROD_au8Prod2Reserve         PROD_2_PSAIDENT_NvMRamBlockDataStruct.PROD_au8Prod2Reserve

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8FuncProductNum                         
******************************************************************************************/

#define PROD_au8FuncProductNum         PROD_2_PSAIDENT_NvMRamBlockDataStruct.PROD_au8FuncProductNum

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8FuncSchematicNum                         
******************************************************************************************/

#define PROD_au8FuncSchematicNum         PROD_2_PSAIDENT_NvMRamBlockDataStruct.PROD_au8FuncSchematicNum

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8Prod5Reserve                         
******************************************************************************************/

#define PROD_au8Prod5Reserve         PROD_5_CIENUM_NvMRamBlockDataStruct.PROD_au8Prod5Reserve

/******************************************************************************************
   Creation des macros necessaires pour le tableau MCWDG_au8InitialMcwRomChecksum                         
******************************************************************************************/

#define MCWDG_au8InitialMcwRomChecksum         PROD_5_CIENUM_NvMRamBlockDataStruct.MCWDG_au8InitialMcwRomChecksum

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8CieValeoNumIdx                         
******************************************************************************************/

#define PROD_au8CieValeoNumIdx         PROD_5_CIENUM_NvMRamBlockDataStruct.PROD_au8CieValeoNumIdx

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8CieValeoNum                         
******************************************************************************************/

#define PROD_au8CieValeoNum         PROD_5_CIENUM_NvMRamBlockDataStruct.PROD_au8CieValeoNum

/******************************************************************************************
   Creation des macros necessaires pour le tableau PROD_au8Prod8Reserve                         
******************************************************************************************/

#define PROD_au8Prod8Reserve         PROD_8_TRIMS_NvMRamBlockDataStruct.PROD_au8Prod8Reserve

/*******************************************************************************************
    Creation des macros necessaires pour la variable IGNHAL_s8TrimGainOutput_CM_3                       
********************************************************************************************/

//#define IGNHAL_s8TrimGainOutput_CM_3         PROD_8_TRIMS_NvMRamBlockDataStruct.IGNHAL_s8TrimGainOutput_CM_3

/*******************************************************************************************
    Creation des macros necessaires pour la variable IGNHAL_s8TrimGainOutput_CM_24                       
********************************************************************************************/

//#define IGNHAL_s8TrimGainOutput_CM_24         PROD_8_TRIMS_NvMRamBlockDataStruct.IGNHAL_s8TrimGainOutput_CM_24

/*******************************************************************************************
    Creation des macros necessaires pour la variable IGNHAL_s8TrimGainOutput_CM_45                       
********************************************************************************************/

//#define IGNHAL_s8TrimGainOutput_CM_45         PROD_8_TRIMS_NvMRamBlockDataStruct.IGNHAL_s8TrimGainOutput_CM_45

/*******************************************************************************************
    Creation des macros necessaires pour la variable IGNHAL_s8TrimGainOutput_CM_66                       
********************************************************************************************/

//#define IGNHAL_s8TrimGainOutput_CM_66         PROD_8_TRIMS_NvMRamBlockDataStruct.IGNHAL_s8TrimGainOutput_CM_66

/*******************************************************************************************
    Creation des macros necessaires pour la variable ADCHAL_s8BatTrimOffset                       
********************************************************************************************/

//#define ADCHAL_s8BatTrimOffset         PROD_8_TRIMS_NvMRamBlockDataStruct.ADCHAL_s8BatTrimOffset

/*******************************************************************************************
    Creation des macros necessaires pour la variable ADCHAL_s8BatTrimGain                       
********************************************************************************************/

//#define ADCHAL_s8BatTrimGain         PROD_8_TRIMS_NvMRamBlockDataStruct.ADCHAL_s8BatTrimGain

/*******************************************************************************************
    Creation des macros necessaires pour la variable Version_eeprom                       
********************************************************************************************/

#define Version_eeprom         EEPROM_VERSION_NvMRamBlockDataStruct.Version_eeprom

/******************************************************************************************
   Creation des macros necessaires pour le tableau Av_bmax_adapt_anti_k_cyl4                         
******************************************************************************************/

#define Av_bmax_adapt_anti_k_cyl4         KNKADPCOR_NvMRamBlockDataStruct.Av_bmax_adapt_anti_k_cyl4

/******************************************************************************************
   Creation des macros necessaires pour le tableau Av_bmax_adapt_anti_k_cyl3                         
******************************************************************************************/

#define Av_bmax_adapt_anti_k_cyl3         KNKADPCOR_NvMRamBlockDataStruct.Av_bmax_adapt_anti_k_cyl3

/******************************************************************************************
   Creation des macros necessaires pour le tableau Av_bmax_adapt_anti_k_cyl2                         
******************************************************************************************/

#define Av_bmax_adapt_anti_k_cyl2         KNKADPCOR_NvMRamBlockDataStruct.Av_bmax_adapt_anti_k_cyl2

/******************************************************************************************
   Creation des macros necessaires pour le tableau Av_bmax_adapt_anti_k_cyl1                         
******************************************************************************************/

#define Av_bmax_adapt_anti_k_cyl1         KNKADPCOR_NvMRamBlockDataStruct.Av_bmax_adapt_anti_k_cyl1

/*******************************************************************************************
    Creation des macros necessaires pour la variable Srv_bPostEquDone                       
********************************************************************************************/

#define Srv_bPostEquDone         POSTEQUSRV_NvMRamBlockDataStruct.Srv_bPostEquDone

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_spdVehVSMaxPrmaReq1                       
********************************************************************************************/

#define Ext_spdVehVSMaxPrmaReq1         POSTEQUSRV_NvMRamBlockDataStruct.Ext_spdVehVSMaxPrmaReq1

/*******************************************************************************************
    Creation des macros necessaires pour la variable Srv_PostEquIndice                       
********************************************************************************************/

#define Srv_PostEquIndice         POSTEQUSRV_NvMRamBlockDataStruct.Srv_PostEquIndice

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tele_program_add_heat                       
********************************************************************************************/

#define Tele_program_add_heat         TELECODAGE_NvMRamBlockDataStruct.Tele_program_add_heat

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tele_program_car                       
********************************************************************************************/

#define Tele_program_car         TELECODAGE_NvMRamBlockDataStruct.Tele_program_car

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tele_program_press_clim                       
********************************************************************************************/

#define Tele_program_press_clim         TELECODAGE_NvMRamBlockDataStruct.Tele_program_press_clim

/*******************************************************************************************
    Creation des macros necessaires pour la variable Id_telecodage_eeprom                       
********************************************************************************************/

#define Id_telecodage_eeprom         TELECODAGE_NvMRamBlockDataStruct.Id_telecodage_eeprom

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tele_program_gear_box                       
********************************************************************************************/

#define Tele_program_gear_box         TELECODAGE_NvMRamBlockDataStruct.Tele_program_gear_box

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tele_program_fric                       
********************************************************************************************/

#define Tele_program_fric         TELECODAGE_NvMRamBlockDataStruct.Tele_program_fric

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tele_program_nb                       
********************************************************************************************/

#define Tele_program_nb         TELECODAGE_NvMRamBlockDataStruct.Tele_program_nb

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tele_program_alternator                       
********************************************************************************************/

#define Tele_program_alternator         TELECODAGE_NvMRamBlockDataStruct.Tele_program_alternator

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tele_program_uc                       
********************************************************************************************/

#define Tele_program_uc         TELECODAGE_NvMRamBlockDataStruct.Tele_program_uc

/*******************************************************************************************
    Creation des macros necessaires pour la variable AccPEM_bAccPInvld                       
********************************************************************************************/

#define AccPEM_bAccPInvld         ACCPEM_NvMRamBlockDataStruct.AccPEM_bAccPInvld

/*******************************************************************************************
    Creation des macros necessaires pour la variable Dv_1_app_pos_ped_pc                       
********************************************************************************************/

#define Dv_1_app_pos_ped_pc         ACCPLRNPOS_NvMRamBlockDataStruct.Dv_1_app_pos_ped_pc

/*******************************************************************************************
    Creation des macros necessaires pour la variable Dv_1_app_pos_ped_pl                       
********************************************************************************************/

#define Dv_1_app_pos_ped_pl         ACCPLRNPOS_NvMRamBlockDataStruct.Dv_1_app_pos_ped_pl

/*******************************************************************************************
    Creation des macros necessaires pour la variable Dv_2_app_pos_ped_pc                       
********************************************************************************************/

#define Dv_2_app_pos_ped_pc         ACCPLRNPOS_NvMRamBlockDataStruct.Dv_2_app_pos_ped_pc

/*******************************************************************************************
    Creation des macros necessaires pour la variable Dv_2_app_pos_ped_pl                       
********************************************************************************************/

#define Dv_2_app_pos_ped_pl         ACCPLRNPOS_NvMRamBlockDataStruct.Dv_2_app_pos_ped_pl

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_tCoMesPwrl                       
********************************************************************************************/

#define Ext_tCoMesPwrl         ACQCOT_NvMRamBlockDataStruct.Ext_tCoMesPwrl

/*******************************************************************************************
    Creation des macros necessaires pour la variable FISA_facOld_nvm                       
********************************************************************************************/

#define FISA_facOld_nvm         CLCNFISAGAIN_NvMRamBlockDataStruct.FISA_facOld_nvm

/*******************************************************************************************
    Creation des macros necessaires pour la variable StaCtl_ctDiagCluP_NV                       
********************************************************************************************/

#define StaCtl_ctDiagCluP_NV         CLUPEDPOSNDIAG_NvMRamBlockDataStruct.StaCtl_ctDiagCluP_NV

/*******************************************************************************************
    Creation des macros necessaires pour la variable Cps_switch_mal_utilise_cpt                       
********************************************************************************************/

#define Cps_switch_mal_utilise_cpt         CLUSWTDIAG_NvMRamBlockDataStruct.Cps_switch_mal_utilise_cpt

/*******************************************************************************************
    Creation des macros necessaires pour la variable CoFan_ctRskCritScFanC                       
********************************************************************************************/

#define CoFan_ctRskCritScFanC         COFANCMDDIAG_NvMRamBlockDataStruct.CoFan_ctRskCritScFanC

/*******************************************************************************************
    Creation des macros necessaires pour la variable CoFan_ctCritScFanC                       
********************************************************************************************/

#define CoFan_ctCritScFanC         COFANCMDDIAG_NvMRamBlockDataStruct.CoFan_ctCritScFanC

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_dstVehTotMes                       
********************************************************************************************/

#define Ext_dstVehTotMes         FHCANF552_NvMRamBlockDataStruct.Ext_dstVehTotMes

/*******************************************************************************************
    Creation des macros necessaires pour la variable Cpc_fuel_vapour_concentration                       
********************************************************************************************/

#define Cpc_fuel_vapour_concentration         CSTRFUCONCESTIM_NvMRamBlockDataStruct.Cpc_fuel_vapour_concentration

/*******************************************************************************************
    Creation des macros necessaires pour la variable Afts_stSpcFactSTTReq_eep                       
********************************************************************************************/

#define Afts_stSpcFactSTTReq_eep         DCM_MANU_NvMRamBlockDataStruct.Afts_stSpcFactSTTReq_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Afts_bInhIniRunReq_eep                       
********************************************************************************************/

#define Afts_bInhIniRunReq_eep         DCM_MANU_NvMRamBlockDataStruct.Afts_bInhIniRunReq_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Afts_bInhStSoCBatt_eep                       
********************************************************************************************/

#define Afts_bInhStSoCBatt_eep         DCM_MANU_NvMRamBlockDataStruct.Afts_bInhStSoCBatt_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable UsThrM_pAirExtEstimRefOld                       
********************************************************************************************/

#define UsThrM_pAirExtEstimRefOld         DIAGAIREXTPRES_NvMRamBlockDataStruct.UsThrM_pAirExtEstimRefOld

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tension_sonde_av_max_cycle                       
********************************************************************************************/

#define Tension_sonde_av_max_cycle         DSO2SEN_NvMRamBlockDataStruct.Tension_sonde_av_max_cycle

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tension_sonde_av_min_cycle                       
********************************************************************************************/

#define Tension_sonde_av_min_cycle         DSO2SEN_NvMRamBlockDataStruct.Tension_sonde_av_min_cycle

/*******************************************************************************************
    Creation des macros necessaires pour la variable EcuSt_ctHotRst_Count                       
********************************************************************************************/

#define EcuSt_ctHotRst_Count         ECUMNG_NvMRamBlockDataStruct.EcuSt_ctHotRst_Count

/*******************************************************************************************
    Creation des macros necessaires pour la variable ESLim_tiCntOverNEngMax                       
********************************************************************************************/

#define ESLim_tiCntOverNEngMax         ENGRUNST_NvMRamBlockDataStruct.ESLim_tiCntOverNEngMax

/*******************************************************************************************
    Creation des macros necessaires pour la variable Dml_demarrage_count_eep                       
********************************************************************************************/

#define Dml_demarrage_count_eep         DIVERS_EEP_FIXE_NvMRamBlockDataStruct.Dml_demarrage_count_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable First_crank                       
********************************************************************************************/

#define First_crank         DIVERS_EEP_FIXE_NvMRamBlockDataStruct.First_crank

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_volFuCns                       
********************************************************************************************/

#define Ext_volFuCns         FISARFUDET_NvMRamBlockDataStruct.Ext_volFuCns

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_bRFuDet                       
********************************************************************************************/

#define Ext_bRFuDet         FISARFUDET_NvMRamBlockDataStruct.Ext_bRFuDet

/*******************************************************************************************
    Creation des macros necessaires pour la variable RFuDet_bRstAdp_nvm                       
********************************************************************************************/

#define RFuDet_bRstAdp_nvm         FISARFUDET_NvMRamBlockDataStruct.RFuDet_bRstAdp_nvm

/*******************************************************************************************
    Creation des macros necessaires pour la variable FISA_facRst_nvm                       
********************************************************************************************/

#define FISA_facRst_nvm         FISARFUDET_NvMRamBlockDataStruct.FISA_facRst_nvm

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_volFuOld                       
********************************************************************************************/

#define Ext_volFuOld         FISARFUDET_NvMRamBlockDataStruct.Ext_volFuOld

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_ctSecPwrl                       
********************************************************************************************/

#define Ext_ctSecPwrl         FLOWMNG_NvMRamBlockDataStruct.Ext_ctSecPwrl

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_ctVehPwrl                       
********************************************************************************************/

#define Ext_ctVehPwrl         FLOWMNG_NvMRamBlockDataStruct.Ext_ctVehPwrl

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_ctVehPwrl2004                       
********************************************************************************************/

#define Ext_ctVehPwrl2004         FLOWMNG_NvMRamBlockDataStruct.Ext_ctVehPwrl2004

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_ctDayPwrl                       
********************************************************************************************/

#define Ext_ctDayPwrl         FLOWMNG_NvMRamBlockDataStruct.Ext_ctDayPwrl

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_ctYrPwrl                       
********************************************************************************************/

#define Ext_ctYrPwrl         FLOWMNG_NvMRamBlockDataStruct.Ext_ctYrPwrl

/*******************************************************************************************
    Creation des macros necessaires pour la variable FTPCtl_ctFirstCmdFuPmpTmr_NV                       
********************************************************************************************/

#define FTPCtl_ctFirstCmdFuPmpTmr_NV         FTPCTL_NvMRamBlockDataStruct.FTPCtl_ctFirstCmdFuPmpTmr_NV

/*******************************************************************************************
    Creation des macros necessaires pour la variable FTPCtl_bFirstCmdFuPmp_NV                       
********************************************************************************************/

#define FTPCtl_bFirstCmdFuPmp_NV         FTPCTL_NvMRamBlockDataStruct.FTPCtl_bFirstCmdFuPmp_NV

/*******************************************************************************************
    Creation des macros necessaires pour la variable Consommation_carburant_totale                       
********************************************************************************************/

#define Consommation_carburant_totale         FUCNS_NvMRamBlockDataStruct.Consommation_carburant_totale

/*******************************************************************************************
    Creation des macros necessaires pour la variable Flev_fuel_level_in_eep                       
********************************************************************************************/

#define Flev_fuel_level_in_eep         FULVL_NvMRamBlockDataStruct.Flev_fuel_level_in_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable WUC_tCoRefEep                       
********************************************************************************************/

#define WUC_tCoRefEep         WUC_NvMRamBlockDataStruct.WUC_tCoRefEep

/*******************************************************************************************
    Creation des macros necessaires pour la variable WUC_ctWupDftClr                       
********************************************************************************************/

#define WUC_ctWupDftClr         WUC_NvMRamBlockDataStruct.WUC_ctWupDftClr

/*******************************************************************************************
    Creation des macros necessaires pour la variable WUC_bWupSt                       
********************************************************************************************/

#define WUC_bWupSt         WUC_NvMRamBlockDataStruct.WUC_bWupSt

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_prmDtcStatus                         
******************************************************************************************/

#define GD_prmDtcStatus         STATUSOFDTC_NvMRamBlockDataStruct.GD_prmDtcStatus

/*******************************************************************************************
    Creation des macros necessaires pour la variable GMIL_dstKmMilOn                       
********************************************************************************************/

#define GMIL_dstKmMilOn         INDICOBD_NvMRamBlockDataStruct.GMIL_dstKmMilOn

/*******************************************************************************************
    Creation des macros necessaires pour la variable GMIL_dstKmRstDft                       
********************************************************************************************/

#define GMIL_dstKmRstDft         INDICOBD_NvMRamBlockDataStruct.GMIL_dstKmRstDft

/*******************************************************************************************
    Creation des macros necessaires pour la variable GMIL_tiMinsEngrunMilOn                       
********************************************************************************************/

#define GMIL_tiMinsEngrunMilOn         INDICOBD_NvMRamBlockDataStruct.GMIL_tiMinsEngrunMilOn

/*******************************************************************************************
    Creation des macros necessaires pour la variable GMIL_tiMinsEngrunRstDft                       
********************************************************************************************/

#define GMIL_tiMinsEngrunRstDft         INDICOBD_NvMRamBlockDataStruct.GMIL_tiMinsEngrunRstDft

/*******************************************************************************************
    Creation des macros necessaires pour la variable IndicOBD_ctDftObdCf                       
********************************************************************************************/

#define IndicOBD_ctDftObdCf         INDICOBD_NvMRamBlockDataStruct.IndicOBD_ctDftObdCf

/*******************************************************************************************
    Creation des macros necessaires pour la variable Iupr_gen_denom_count_eep                       
********************************************************************************************/

#define Iupr_gen_denom_count_eep         IUPRGENDEN_NvMRamBlockDataStruct.Iupr_gen_denom_count_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable IUPR_ctObdStrt                       
********************************************************************************************/

#define IUPR_ctObdStrt         IUPRGENDEN_NvMRamBlockDataStruct.IUPR_ctObdStrt

/*******************************************************************************************
    Creation des macros necessaires pour la variable Rdy_u16ClasRdy_EEPROM                       
********************************************************************************************/

#define Rdy_u16ClasRdy_EEPROM         RC01_NvMRamBlockDataStruct.Rdy_u16ClasRdy_EEPROM

/******************************************************************************************
   Creation des macros necessaires pour le tableau Rdy_au8Rdy_EEPROM                         
******************************************************************************************/

#define Rdy_au8Rdy_EEPROM         RC01_NvMRamBlockDataStruct.Rdy_au8Rdy_EEPROM

/******************************************************************************************
   Creation des macros necessaires pour le tableau GOBD_bPresDC                         
******************************************************************************************/

#define GOBD_bPresDC         GOBD_NvMRamBlockDataStruct.GOBD_bPresDC

/******************************************************************************************
   Creation des macros necessaires pour le tableau GOBD_ctDC                         
******************************************************************************************/

#define GOBD_ctDC         GOBD_NvMRamBlockDataStruct.GOBD_ctDC

/******************************************************************************************
   Creation des macros necessaires pour le tableau GOBD_ctWUC                         
******************************************************************************************/

#define GOBD_ctWUC         GOBD_NvMRamBlockDataStruct.GOBD_ctWUC

/******************************************************************************************
   Creation des macros necessaires pour le tableau GOBD_bNCfDC                         
******************************************************************************************/

#define GOBD_bNCfDC         GOBD_NvMRamBlockDataStruct.GOBD_bNCfDC

/******************************************************************************************
   Creation des macros necessaires pour le tableau IUPR_ctDenRat                         
******************************************************************************************/

#define IUPR_ctDenRat         IUPRRATIO_NvMRamBlockDataStruct.IUPR_ctDenRat

/******************************************************************************************
   Creation des macros necessaires pour le tableau IUPR_ctNumRat                         
******************************************************************************************/

#define IUPR_ctNumRat         IUPRRATIO_NvMRamBlockDataStruct.IUPR_ctNumRat

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au32dstAbsKmNoFrf                         
******************************************************************************************/

#define GD_au32dstAbsKmNoFrf         MEM1_NvMRamBlockDataStruct.GD_au32dstAbsKmNoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au32prmClasFrf1NoFrf                         
******************************************************************************************/

#define GD_au32prmClasFrf1NoFrf         MEM2_NvMRamBlockDataStruct.GD_au32prmClasFrf1NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au32prmClasFrf2NoFrf                         
******************************************************************************************/

#define GD_au32prmClasFrf2NoFrf         MEM3_NvMRamBlockDataStruct.GD_au32prmClasFrf2NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au32prmClasFrf3NoFrf                         
******************************************************************************************/

#define GD_au32prmClasFrf3NoFrf         MEM4_NvMRamBlockDataStruct.GD_au32prmClasFrf3NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au32prmClasFrf4NoFrf                         
******************************************************************************************/

#define GD_au32prmClasFrf4NoFrf         MEM5_NvMRamBlockDataStruct.GD_au32prmClasFrf4NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au32prmClasFrf5NoFrf                         
******************************************************************************************/

#define GD_au32prmClasFrf5NoFrf         MEM6_NvMRamBlockDataStruct.GD_au32prmClasFrf5NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au32prmClasFrf6NoFrf                         
******************************************************************************************/

#define GD_au32prmClasFrf6NoFrf         MEM7_NvMRamBlockDataStruct.GD_au32prmClasFrf6NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au32prmClasFrf7NoFrf                         
******************************************************************************************/

#define GD_au32prmClasFrf7NoFrf         MEM8_NvMRamBlockDataStruct.GD_au32prmClasFrf7NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au32prmClasFrf8NoFrf                         
******************************************************************************************/

#define GD_au32prmClasFrf8NoFrf         MEM9_NvMRamBlockDataStruct.GD_au32prmClasFrf8NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au32prmClasFrf9NoFrf                         
******************************************************************************************/

#define GD_au32prmClasFrf9NoFrf         MEM10_NvMRamBlockDataStruct.GD_au32prmClasFrf9NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_uBattMes_NoFrf                         
******************************************************************************************/

#define GD_uBattMes_NoFrf         MEM11_NvMRamBlockDataStruct.GD_uBattMes_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au16nEngNoFrf                         
******************************************************************************************/

#define GD_au16nEngNoFrf         MEM12_NvMRamBlockDataStruct.GD_au16nEngNoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au16idxDftNoFrf                         
******************************************************************************************/

#define GD_au16idxDftNoFrf         MEM13_NvMRamBlockDataStruct.GD_au16idxDftNoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_spdVeh_NoFrf                         
******************************************************************************************/

#define GD_spdVeh_NoFrf         MEM14_NvMRamBlockDataStruct.GD_spdVeh_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_as16tCoMesNoFrf                         
******************************************************************************************/

#define GD_as16tCoMesNoFrf         MEM15_NvMRamBlockDataStruct.GD_as16tCoMesNoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au8StFrfRecNoFrf                         
******************************************************************************************/

#define GD_au8StFrfRecNoFrf         MEM16_NvMRamBlockDataStruct.GD_au8StFrfRecNoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au8idxFltToCxtNoFrf                         
******************************************************************************************/

#define GD_au8idxFltToCxtNoFrf         MEM17_NvMRamBlockDataStruct.GD_au8idxFltToCxtNoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau Fault_context_eep_eobd                         
******************************************************************************************/

#define Fault_context_eep_eobd         MEM18_NvMRamBlockDataStruct.Fault_context_eep_eobd

/*******************************************************************************************
    Creation des macros necessaires pour la variable Free_context_eobd                       
********************************************************************************************/

#define Free_context_eobd         MEM19_NvMRamBlockDataStruct.Free_context_eobd

/*******************************************************************************************
    Creation des macros necessaires pour la variable GD_ctSngDftMem                       
********************************************************************************************/

#define GD_ctSngDftMem         MEM19_NvMRamBlockDataStruct.GD_ctSngDftMem

/*******************************************************************************************
    Creation des macros necessaires pour la variable GD_bMaxDftMem                       
********************************************************************************************/

#define GD_bMaxDftMem         MEM19_NvMRamBlockDataStruct.GD_bMaxDftMem

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au8RnkFrf                         
******************************************************************************************/

#define GD_au8RnkFrf         MEM19_NvMRamBlockDataStruct.GD_au8RnkFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au16prmClasDID1                         
******************************************************************************************/

#define GD_au16prmClasDID1         MEM20_NvMRamBlockDataStruct.GD_au16prmClasDID1

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au16prmClasDID2                         
******************************************************************************************/

#define GD_au16prmClasDID2         MEM21_NvMRamBlockDataStruct.GD_au16prmClasDID2

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au16prmClasDID3                         
******************************************************************************************/

#define GD_au16prmClasDID3         MEM22_NvMRamBlockDataStruct.GD_au16prmClasDID3

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au16prmClasDID4                         
******************************************************************************************/

#define GD_au16prmClasDID4         MEM23_NvMRamBlockDataStruct.GD_au16prmClasDID4

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au16prmClasDID5                         
******************************************************************************************/

#define GD_au16prmClasDID5         MEM24_NvMRamBlockDataStruct.GD_au16prmClasDID5

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au16prmClasDID6                         
******************************************************************************************/

#define GD_au16prmClasDID6         MEM25_NvMRamBlockDataStruct.GD_au16prmClasDID6

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au16prmClasDID7                         
******************************************************************************************/

#define GD_au16prmClasDID7         MEM26_NvMRamBlockDataStruct.GD_au16prmClasDID7

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au16prmClasDID8                         
******************************************************************************************/

#define GD_au16prmClasDID8         MEM27_NvMRamBlockDataStruct.GD_au16prmClasDID8

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_au16prmClasDID9                         
******************************************************************************************/

#define GD_au16prmClasDID9         MEM28_NvMRamBlockDataStruct.GD_au16prmClasDID9

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_Pid04_NoFrf                         
******************************************************************************************/

#define GD_Pid04_NoFrf         MEM29_NvMRamBlockDataStruct.GD_Pid04_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_Pid05_NoFrf                         
******************************************************************************************/

#define GD_Pid05_NoFrf         MEM30_NvMRamBlockDataStruct.GD_Pid05_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_Pid0B_NoFrf                         
******************************************************************************************/

#define GD_Pid0B_NoFrf         MEM31_NvMRamBlockDataStruct.GD_Pid0B_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_Pid0C_NoFrf                         
******************************************************************************************/

#define GD_Pid0C_NoFrf         MEM32_NvMRamBlockDataStruct.GD_Pid0C_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_Pid0D_NoFrf                         
******************************************************************************************/

#define GD_Pid0D_NoFrf         MEM33_NvMRamBlockDataStruct.GD_Pid0D_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_Pid03_NoFrf                         
******************************************************************************************/

#define GD_Pid03_NoFrf         MEM34_NvMRamBlockDataStruct.GD_Pid03_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_Pid23_NoFrf                         
******************************************************************************************/

#define GD_Pid23_NoFrf         MEM35_NvMRamBlockDataStruct.GD_Pid23_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_Pid06_NoFrf                         
******************************************************************************************/

#define GD_Pid06_NoFrf         MEM36_NvMRamBlockDataStruct.GD_Pid06_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_Pid42_NoFrf                         
******************************************************************************************/

#define GD_Pid42_NoFrf         MEM37_NvMRamBlockDataStruct.GD_Pid42_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_tiCurVehTmr_NoFrf                         
******************************************************************************************/

#define GD_tiCurVehTmr_NoFrf         MEM38_NvMRamBlockDataStruct.GD_tiCurVehTmr_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_rAccP_NoFrf                         
******************************************************************************************/

#define GD_rAccP_NoFrf         MEM39_NvMRamBlockDataStruct.GD_rAccP_NoFrf

/******************************************************************************************
   Creation des macros necessaires pour le tableau GD_Pid07_NoFrf                         
******************************************************************************************/

#define GD_Pid07_NoFrf         MEM40_NvMRamBlockDataStruct.GD_Pid07_NoFrf

/*******************************************************************************************
    Creation des macros necessaires pour la variable GMIL_bDftMilOn                       
********************************************************************************************/

#define GMIL_bDftMilOn         GMIL_NvMRamBlockDataStruct.GMIL_bDftMilOn

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ldsd_trk_ewma_essence_eep                       
********************************************************************************************/

#define Ldsd_trk_ewma_essence_eep         HEATSENO2DSDERIDIAG_NvMRamBlockDataStruct.Ldsd_trk_ewma_essence_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ldsd_trk_ewma_gaz_eep                       
********************************************************************************************/

#define Ldsd_trk_ewma_gaz_eep         HEATSENO2DSDERIDIAG_NvMRamBlockDataStruct.Ldsd_trk_ewma_gaz_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable LsSys_tiLsDsDlyDewTranOkStall                       
********************************************************************************************/

#define LsSys_tiLsDsDlyDewTranOkStall         HEATSENO2DS_NvMRamBlockDataStruct.LsSys_tiLsDsDlyDewTranOkStall

/*******************************************************************************************
    Creation des macros necessaires pour la variable LsSys_tiLsUsDlyDewTranOkStall                       
********************************************************************************************/

#define LsSys_tiLsUsDlyDewTranOkStall         HEATSENO2US_NvMRamBlockDataStruct.LsSys_tiLsUsDlyDewTranOkStall

/*******************************************************************************************
    Creation des macros necessaires pour la variable Eep_UsThrM_pAirExtEstim                       
********************************************************************************************/

#define Eep_UsThrM_pAirExtEstim         IFAIRSYSIGSYS_NvMRamBlockDataStruct.Eep_UsThrM_pAirExtEstim

/*******************************************************************************************
    Creation des macros necessaires pour la variable temps_fonctionnement_moteur                       
********************************************************************************************/

#define temps_fonctionnement_moteur         IFAIRSYSIGSYS_NvMRamBlockDataStruct.temps_fonctionnement_moteur

/*******************************************************************************************
    Creation des macros necessaires pour la variable temps_allumage_ecu                       
********************************************************************************************/

#define temps_allumage_ecu         IFAIRSYSIGSYS_NvMRamBlockDataStruct.temps_allumage_ecu

/*******************************************************************************************
    Creation des macros necessaires pour la variable Feedback_correction_Tmp                       
********************************************************************************************/

#define Feedback_correction_Tmp         INJFARCTLDSCTL_NvMRamBlockDataStruct.Feedback_correction_Tmp

/******************************************************************************************
   Creation des macros necessaires pour le tableau Mf_adap_lw_corr_count_uavn1                         
******************************************************************************************/

#define Mf_adap_lw_corr_count_uavn1         MISFDFTLRN_NvMRamBlockDataStruct.Mf_adap_lw_corr_count_uavn1

/******************************************************************************************
   Creation des macros necessaires pour le tableau Mf_adap_shrt_corr_count_uavn1                         
******************************************************************************************/

#define Mf_adap_shrt_corr_count_uavn1         MISFDFTLRN_NvMRamBlockDataStruct.Mf_adap_shrt_corr_count_uavn1

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyBdcWinLrnCyl1                         
******************************************************************************************/

#define Misf_prm_tiDlyBdcWinLrnCyl1         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyBdcWinLrnCyl1

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyBdcWinLrnCyl2                         
******************************************************************************************/

#define Misf_prm_tiDlyBdcWinLrnCyl2         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyBdcWinLrnCyl2

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyBdcWinLrnCyl3                         
******************************************************************************************/

#define Misf_prm_tiDlyBdcWinLrnCyl3         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyBdcWinLrnCyl3

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyBdcWinLrnCyl4                         
******************************************************************************************/

#define Misf_prm_tiDlyBdcWinLrnCyl4         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyBdcWinLrnCyl4

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyExpWinLrnCyl1                         
******************************************************************************************/

#define Misf_prm_tiDlyExpWinLrnCyl1         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyExpWinLrnCyl1

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyExpWinLrnCyl2                         
******************************************************************************************/

#define Misf_prm_tiDlyExpWinLrnCyl2         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyExpWinLrnCyl2

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyExpWinLrnCyl3                         
******************************************************************************************/

#define Misf_prm_tiDlyExpWinLrnCyl3         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyExpWinLrnCyl3

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyExpWinLrnCyl4                         
******************************************************************************************/

#define Misf_prm_tiDlyExpWinLrnCyl4         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyExpWinLrnCyl4

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyLongWinLrnCyl1                         
******************************************************************************************/

#define Misf_prm_tiDlyLongWinLrnCyl1         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyLongWinLrnCyl1

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyLongWinLrnCyl2                         
******************************************************************************************/

#define Misf_prm_tiDlyLongWinLrnCyl2         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyLongWinLrnCyl2

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyLongWinLrnCyl3                         
******************************************************************************************/

#define Misf_prm_tiDlyLongWinLrnCyl3         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyLongWinLrnCyl3

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyLongWinLrnCyl4                         
******************************************************************************************/

#define Misf_prm_tiDlyLongWinLrnCyl4         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyLongWinLrnCyl4

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyTDCWinLrnCyl1                         
******************************************************************************************/

#define Misf_prm_tiDlyTDCWinLrnCyl1         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyTDCWinLrnCyl1

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyTDCWinLrnCyl2                         
******************************************************************************************/

#define Misf_prm_tiDlyTDCWinLrnCyl2         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyTDCWinLrnCyl2

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyTDCWinLrnCyl3                         
******************************************************************************************/

#define Misf_prm_tiDlyTDCWinLrnCyl3         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyTDCWinLrnCyl3

/******************************************************************************************
   Creation des macros necessaires pour le tableau Misf_prm_tiDlyTDCWinLrnCyl4                         
******************************************************************************************/

#define Misf_prm_tiDlyTDCWinLrnCyl4         MISFDFTLRN_NvMRamBlockDataStruct.Misf_prm_tiDlyTDCWinLrnCyl4

/******************************************************************************************
   Creation des macros necessaires pour le tableau Mf_adap_lw_delta_applied_uavn1                         
******************************************************************************************/

#define Mf_adap_lw_delta_applied_uavn1         MISFDFTLRN_NvMRamBlockDataStruct.Mf_adap_lw_delta_applied_uavn1

/******************************************************************************************
   Creation des macros necessaires pour le tableau Mf_adap_Exp_delta_applied_uavn1                         
******************************************************************************************/

#define Mf_adap_Exp_delta_applied_uavn1         MISFDFTLRN_NvMRamBlockDataStruct.Mf_adap_Exp_delta_applied_uavn1

/******************************************************************************************
   Creation des macros necessaires pour le tableau Mf_adap_TDC_delta_applied_uavn1                         
******************************************************************************************/

#define Mf_adap_TDC_delta_applied_uavn1         MISFDFTLRN_NvMRamBlockDataStruct.Mf_adap_TDC_delta_applied_uavn1

/******************************************************************************************
   Creation des macros necessaires pour le tableau Mf_adap_Bdc_delta_applied_uavn1                         
******************************************************************************************/

#define Mf_adap_Bdc_delta_applied_uavn1         MISFDFTLRN_NvMRamBlockDataStruct.Mf_adap_Bdc_delta_applied_uavn1

/*******************************************************************************************
    Creation des macros necessaires pour la variable Mf_adap_lw_no_rlzd_uavb0                       
********************************************************************************************/

#define Mf_adap_lw_no_rlzd_uavb0         MISFDFTLRN_NvMRamBlockDataStruct.Mf_adap_lw_no_rlzd_uavb0

/*******************************************************************************************
    Creation des macros necessaires pour la variable Mf_adap_shrt_no_rlzd_uavb0                       
********************************************************************************************/

#define Mf_adap_shrt_no_rlzd_uavb0         MISFDFTLRN_NvMRamBlockDataStruct.Mf_adap_shrt_no_rlzd_uavb0

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_stTypInjr                       
********************************************************************************************/

#define Ext_stTypInjr         INJRCHRN_NvMRamBlockDataStruct.Ext_stTypInjr

/*******************************************************************************************
    Creation des macros necessaires pour la variable CatMon_facMes_Obd6Mod_eep                       
********************************************************************************************/

#define CatMon_facMes_Obd6Mod_eep         OBDSRV06_NvMRamBlockDataStruct.CatMon_facMes_Obd6Mod_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable HeatSenO2_DsFacMes_Obd6Mod_eep                       
********************************************************************************************/

#define HeatSenO2_DsFacMes_Obd6Mod_eep         OBDSRV06_NvMRamBlockDataStruct.HeatSenO2_DsFacMes_Obd6Mod_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable HeatSenO2_UsFacMes_Obd6Mod_eep                       
********************************************************************************************/

#define HeatSenO2_UsFacMes_Obd6Mod_eep         OBDSRV06_NvMRamBlockDataStruct.HeatSenO2_UsFacMes_Obd6Mod_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable MonMisf_ctOccurMfAvg10DCCyl1_eep                       
********************************************************************************************/

#define MonMisf_ctOccurMfAvg10DCCyl1_eep         OBDSRV06_NvMRamBlockDataStruct.MonMisf_ctOccurMfAvg10DCCyl1_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable MonMisf_ctOccurMfAvg10DCCyl2_eep                       
********************************************************************************************/

#define MonMisf_ctOccurMfAvg10DCCyl2_eep         OBDSRV06_NvMRamBlockDataStruct.MonMisf_ctOccurMfAvg10DCCyl2_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable MonMisf_ctOccurMfAvg10DCCyl3_eep                       
********************************************************************************************/

#define MonMisf_ctOccurMfAvg10DCCyl3_eep         OBDSRV06_NvMRamBlockDataStruct.MonMisf_ctOccurMfAvg10DCCyl3_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable MonMisf_ctOccurMfAvg10DCCyl4_eep                       
********************************************************************************************/

#define MonMisf_ctOccurMfAvg10DCCyl4_eep         OBDSRV06_NvMRamBlockDataStruct.MonMisf_ctOccurMfAvg10DCCyl4_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable MonMisf_ctOccurMfDCCyl1_eep                       
********************************************************************************************/

#define MonMisf_ctOccurMfDCCyl1_eep         OBDSRV06_NvMRamBlockDataStruct.MonMisf_ctOccurMfDCCyl1_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable MonMisf_ctOccurMfDCCyl2_eep                       
********************************************************************************************/

#define MonMisf_ctOccurMfDCCyl2_eep         OBDSRV06_NvMRamBlockDataStruct.MonMisf_ctOccurMfDCCyl2_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable MonMisf_ctOccurMfDCCyl3_eep                       
********************************************************************************************/

#define MonMisf_ctOccurMfDCCyl3_eep         OBDSRV06_NvMRamBlockDataStruct.MonMisf_ctOccurMfDCCyl3_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable MonMisf_ctOccurMfDCCyl4_eep                       
********************************************************************************************/

#define MonMisf_ctOccurMfDCCyl4_eep         OBDSRV06_NvMRamBlockDataStruct.MonMisf_ctOccurMfDCCyl4_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Oxy_sens_period_var_eep                       
********************************************************************************************/

#define Oxy_sens_period_var_eep         OBDSRV06_NvMRamBlockDataStruct.Oxy_sens_period_var_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable SenO2Ds_FcoPlausMes_Obd6Mod_eep                       
********************************************************************************************/

#define SenO2Ds_FcoPlausMes_Obd6Mod_eep         OBDSRV06_NvMRamBlockDataStruct.SenO2Ds_FcoPlausMes_Obd6Mod_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable SenO2Ds_FldPlausMes_Obd6Mod_eep                       
********************************************************************************************/

#define SenO2Ds_FldPlausMes_Obd6Mod_eep         OBDSRV06_NvMRamBlockDataStruct.SenO2Ds_FldPlausMes_Obd6Mod_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable SenO2Ds_SigGrdFacMes_Obd6Mod_eep                       
********************************************************************************************/

#define SenO2Ds_SigGrdFacMes_Obd6Mod_eep         OBDSRV06_NvMRamBlockDataStruct.SenO2Ds_SigGrdFacMes_Obd6Mod_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable SenO2Ds_SigGrd_Obd6Mod_eep                       
********************************************************************************************/

#define SenO2Ds_SigGrd_Obd6Mod_eep         OBDSRV06_NvMRamBlockDataStruct.SenO2Ds_SigGrd_Obd6Mod_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable SenO2Us_FcoPlausMes_Obd6Mod_eep                       
********************************************************************************************/

#define SenO2Us_FcoPlausMes_Obd6Mod_eep         OBDSRV06_NvMRamBlockDataStruct.SenO2Us_FcoPlausMes_Obd6Mod_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable SenO2Us_FldPlausMes_Obd6Mod_eep                       
********************************************************************************************/

#define SenO2Us_FldPlausMes_Obd6Mod_eep         OBDSRV06_NvMRamBlockDataStruct.SenO2Us_FldPlausMes_Obd6Mod_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tension_sonde_am_max_cycle_eep                       
********************************************************************************************/

#define Tension_sonde_am_max_cycle_eep         OBDSRV06_NvMRamBlockDataStruct.Tension_sonde_am_max_cycle_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tension_sonde_am_min_cycle_eep                       
********************************************************************************************/

#define Tension_sonde_am_min_cycle_eep         OBDSRV06_NvMRamBlockDataStruct.Tension_sonde_am_min_cycle_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tension_sonde_av_max_cycle_eep                       
********************************************************************************************/

#define Tension_sonde_av_max_cycle_eep         OBDSRV06_NvMRamBlockDataStruct.Tension_sonde_av_max_cycle_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tension_sonde_av_min_cycle_eep                       
********************************************************************************************/

#define Tension_sonde_av_min_cycle_eep         OBDSRV06_NvMRamBlockDataStruct.Tension_sonde_av_min_cycle_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Srv_bAntiScanPostEqu                       
********************************************************************************************/

#define Srv_bAntiScanPostEqu         POSTEQUSRV_BANTISCANNING_NvMRamBlockDataStruct.Srv_bAntiScanPostEqu

/*******************************************************************************************
    Creation des macros necessaires pour la variable PredEs_tiErrOkN2EgdChgDir_NV                       
********************************************************************************************/

#define PredEs_tiErrOkN2EgdChgDir_NV         PREDES_NvMRamBlockDataStruct.PredEs_tiErrOkN2EgdChgDir_NV

/*******************************************************************************************
    Creation des macros necessaires pour la variable PredEs_tiErrOkN2EgdChgDir2_NV                       
********************************************************************************************/

#define PredEs_tiErrOkN2EgdChgDir2_NV         PREDES_NvMRamBlockDataStruct.PredEs_tiErrOkN2EgdChgDir2_NV

/*******************************************************************************************
    Creation des macros necessaires pour la variable PredEs_ctOkOscN_NV                       
********************************************************************************************/

#define PredEs_ctOkOscN_NV         PREDES_NvMRamBlockDataStruct.PredEs_ctOkOscN_NV

/*******************************************************************************************
    Creation des macros necessaires pour la variable CoPt_tiEngStopMem_NV                       
********************************************************************************************/

#define CoPt_tiEngStopMem_NV         PROTMANCLU_NvMRamBlockDataStruct.CoPt_tiEngStopMem_NV

/******************************************************************************************
   Creation des macros necessaires pour le tableau CoPt_prm_tCluEstimMem_NV                         
******************************************************************************************/

#define CoPt_prm_tCluEstimMem_NV         PROTMANCLU_NvMRamBlockDataStruct.CoPt_prm_tCluEstimMem_NV

/*******************************************************************************************
    Creation des macros necessaires pour la variable EcuSt_SrvPwrlSt                       
********************************************************************************************/

#define EcuSt_SrvPwrlSt         ECUSTSRVPWRLST_NvMRamBlockDataStruct.EcuSt_SrvPwrlSt

/******************************************************************************************
   Creation des macros necessaires pour le tableau Ref_ident_etal                         
******************************************************************************************/

#define Ref_ident_etal         REFIDETA_NvMRamBlockDataStruct.Ref_ident_etal

/*******************************************************************************************
    Creation des macros necessaires pour la variable RND_u16SeedOldAlea                       
********************************************************************************************/

#define RND_u16SeedOldAlea         RANDOM_NvMRamBlockDataStruct.RND_u16SeedOldAlea

/*******************************************************************************************
    Creation des macros necessaires pour la variable RND_u16SeedTimer                       
********************************************************************************************/

#define RND_u16SeedTimer         RANDOM_NvMRamBlockDataStruct.RND_u16SeedTimer

/******************************************************************************************
   Creation des macros necessaires pour le tableau SftyMgt_prm_bDftHis                         
******************************************************************************************/

#define SftyMgt_prm_bDftHis         SFTYMNGR_NvMRamBlockDataStruct.SftyMgt_prm_bDftHis

/******************************************************************************************
   Creation des macros necessaires pour le tableau SftyMgt_prm_bFrfNew                         
******************************************************************************************/

#define SftyMgt_prm_bFrfNew         SFTYMNGR_NvMRamBlockDataStruct.SftyMgt_prm_bFrfNew

/*******************************************************************************************
    Creation des macros necessaires pour la variable SftyMgt_ctWrMem                       
********************************************************************************************/

#define SftyMgt_ctWrMem         SFTYMNGR_NvMRamBlockDataStruct.SftyMgt_ctWrMem

/*******************************************************************************************
    Creation des macros necessaires pour la variable SftyMgt_ctDftLaddNew                       
********************************************************************************************/

#define SftyMgt_ctDftLaddNew         SFTYMNGR_NvMRamBlockDataStruct.SftyMgt_ctDftLaddNew

/******************************************************************************************
   Creation des macros necessaires pour le tableau SpyEmSTT_prmHisDstWin1                         
******************************************************************************************/

#define SpyEmSTT_prmHisDstWin1         SPYEMSTT_NvMRamBlockDataStruct.SpyEmSTT_prmHisDstWin1

/******************************************************************************************
   Creation des macros necessaires pour le tableau SpyEmSTT_prmHistNotStopCase1                         
******************************************************************************************/

#define SpyEmSTT_prmHistNotStopCase1         SPYEMSTT_NvMRamBlockDataStruct.SpyEmSTT_prmHistNotStopCase1

/******************************************************************************************
   Creation des macros necessaires pour le tableau SpyEmSTT_prmHistNotStopCase2                         
******************************************************************************************/

#define SpyEmSTT_prmHistNotStopCase2         SPYEMSTT_NvMRamBlockDataStruct.SpyEmSTT_prmHistNotStopCase2

/******************************************************************************************
   Creation des macros necessaires pour le tableau SpyEmSTT_prmHistNotStopCase3                         
******************************************************************************************/

#define SpyEmSTT_prmHistNotStopCase3         SPYEMSTT_NvMRamBlockDataStruct.SpyEmSTT_prmHistNotStopCase3

/******************************************************************************************
   Creation des macros necessaires pour le tableau SpySTT_prmHisDstWin1                         
******************************************************************************************/

#define SpySTT_prmHisDstWin1         SPYSTT_NvMRamBlockDataStruct.SpySTT_prmHisDstWin1

/******************************************************************************************
   Creation des macros necessaires pour le tableau SpySTT_prmHisNotStopCase1                         
******************************************************************************************/

#define SpySTT_prmHisNotStopCase1         SPYSTT_NvMRamBlockDataStruct.SpySTT_prmHisNotStopCase1

/******************************************************************************************
   Creation des macros necessaires pour le tableau SpySTT_prmHisNotStopCase2                         
******************************************************************************************/

#define SpySTT_prmHisNotStopCase2         SPYSTT_NvMRamBlockDataStruct.SpySTT_prmHisNotStopCase2

/******************************************************************************************
   Creation des macros necessaires pour le tableau SpySTT_prmHisNotStopCase3                         
******************************************************************************************/

#define SpySTT_prmHisNotStopCase3         SPYSTT_NvMRamBlockDataStruct.SpySTT_prmHisNotStopCase3

/*******************************************************************************************
    Creation des macros necessaires pour la variable SpySTT_stRStrtFailRec1                       
********************************************************************************************/

#define SpySTT_stRStrtFailRec1         SPYSTT_NvMRamBlockDataStruct.SpySTT_stRStrtFailRec1

/*******************************************************************************************
    Creation des macros necessaires pour la variable SpySTT_stRStrtFailRec2                       
********************************************************************************************/

#define SpySTT_stRStrtFailRec2         SPYSTT_NvMRamBlockDataStruct.SpySTT_stRStrtFailRec2

/*******************************************************************************************
    Creation des macros necessaires pour la variable SpySTT_stRStrtFailRec3                       
********************************************************************************************/

#define SpySTT_stRStrtFailRec3         SPYSTT_NvMRamBlockDataStruct.SpySTT_stRStrtFailRec3

/*******************************************************************************************
    Creation des macros necessaires pour la variable SpySTT_stCutCaseRec                       
********************************************************************************************/

#define SpySTT_stCutCaseRec         SPYSTT_NvMRamBlockDataStruct.SpySTT_stCutCaseRec

/******************************************************************************************
   Creation des macros necessaires pour le tableau Sync_prm_bLrnCorAr                         
******************************************************************************************/

#define Sync_prm_bLrnCorAr         SYNCENGCLC_NvMRamBlockDataStruct.Sync_prm_bLrnCorAr

/******************************************************************************************
   Creation des macros necessaires pour le tableau Sync_prm_nCornEngCyl1                         
******************************************************************************************/

#define Sync_prm_nCornEngCyl1         SYNCENGCLC_NvMRamBlockDataStruct.Sync_prm_nCornEngCyl1

/******************************************************************************************
   Creation des macros necessaires pour le tableau Sync_prm_nCornEngCyl2                         
******************************************************************************************/

#define Sync_prm_nCornEngCyl2         SYNCENGCLC_NvMRamBlockDataStruct.Sync_prm_nCornEngCyl2

/******************************************************************************************
   Creation des macros necessaires pour le tableau Sync_prm_nCornEngCyl3                         
******************************************************************************************/

#define Sync_prm_nCornEngCyl3         SYNCENGCLC_NvMRamBlockDataStruct.Sync_prm_nCornEngCyl3

/*******************************************************************************************
    Creation des macros necessaires pour la variable Srv_bAntiScanning                       
********************************************************************************************/

#define Srv_bAntiScanning         TELE_BANTISCANNING_NvMRamBlockDataStruct.Srv_bAntiScanning

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_1_open_throttle_pos                       
********************************************************************************************/

#define Tpac_1_open_throttle_pos         PAP_MOT_NvMRamBlockDataStruct.Tpac_1_open_throttle_pos

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_2_open_throttle_pos                       
********************************************************************************************/

#define Tpac_2_open_throttle_pos         PAP_MOT_NvMRamBlockDataStruct.Tpac_2_open_throttle_pos

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_1_limp_home_pos                       
********************************************************************************************/

#define Tpac_1_limp_home_pos         PAP_MOT_NvMRamBlockDataStruct.Tpac_1_limp_home_pos

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_2_limp_home_pos                       
********************************************************************************************/

#define Tpac_2_limp_home_pos         PAP_MOT_NvMRamBlockDataStruct.Tpac_2_limp_home_pos

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_1_clo_throttle_filt_pos                       
********************************************************************************************/

#define Tpac_1_clo_throttle_filt_pos         PAP_MOT_NvMRamBlockDataStruct.Tpac_1_clo_throttle_filt_pos

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_2_clo_throttle_filt_pos                       
********************************************************************************************/

#define Tpac_2_clo_throttle_filt_pos         PAP_MOT_NvMRamBlockDataStruct.Tpac_2_clo_throttle_filt_pos

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_1_closed_throttle_ref                       
********************************************************************************************/

#define Tpac_1_closed_throttle_ref         PAP_MOT_NvMRamBlockDataStruct.Tpac_1_closed_throttle_ref

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_2_closed_throttle_ref                       
********************************************************************************************/

#define Tpac_2_closed_throttle_ref         PAP_MOT_NvMRamBlockDataStruct.Tpac_2_closed_throttle_ref

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_1_closed_throttle_pos                       
********************************************************************************************/

#define Tpac_1_closed_throttle_pos         PAP_MOT_NvMRamBlockDataStruct.Tpac_1_closed_throttle_pos

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_2_closed_throttle_pos                       
********************************************************************************************/

#define Tpac_2_closed_throttle_pos         PAP_MOT_NvMRamBlockDataStruct.Tpac_2_closed_throttle_pos

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_thrusts_powerlatch_counter                       
********************************************************************************************/

#define Tpac_thrusts_powerlatch_counter         PAP_MOT_NvMRamBlockDataStruct.Tpac_thrusts_powerlatch_counter

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_thrusts_enable                       
********************************************************************************************/

#define Tpac_thrusts_enable         PAP_MOT_NvMRamBlockDataStruct.Tpac_thrusts_enable

/*******************************************************************************************
    Creation des macros necessaires pour la variable Thr_bNewThrCpt                       
********************************************************************************************/

#define Thr_bNewThrCpt         PAP_MOT_NvMRamBlockDataStruct.Thr_bNewThrCpt

/*******************************************************************************************
    Creation des macros necessaires pour la variable Thr_bRstStopsLrnReq                       
********************************************************************************************/

#define Thr_bRstStopsLrnReq         PAP_MOT_NvMRamBlockDataStruct.Thr_bRstStopsLrnReq

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_FCln_powerlatch_counter                       
********************************************************************************************/

#define Tpac_FCln_powerlatch_counter         PAP_MOT_NvMRamBlockDataStruct.Tpac_FCln_powerlatch_counter

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tpac_FCln_enable                       
********************************************************************************************/

#define Tpac_FCln_enable         PAP_MOT_NvMRamBlockDataStruct.Tpac_FCln_enable

/*******************************************************************************************
    Creation des macros necessaires pour la variable Date_emf_dernier_arret_s                       
********************************************************************************************/

#define Date_emf_dernier_arret_s         TIENGSTOP_NvMRamBlockDataStruct.Date_emf_dernier_arret_s

/*******************************************************************************************
    Creation des macros necessaires pour la variable Date_emf_dernier_reveil_s                       
********************************************************************************************/

#define Date_emf_dernier_reveil_s         TIENGSTOP_NvMRamBlockDataStruct.Date_emf_dernier_reveil_s

/*******************************************************************************************
    Creation des macros necessaires pour la variable Date_emf_demarrage_s                       
********************************************************************************************/

#define Date_emf_demarrage_s         TIENGSTOP_NvMRamBlockDataStruct.Date_emf_demarrage_s

/*******************************************************************************************
    Creation des macros necessaires pour la variable Date_emf_dernier_arret_j                       
********************************************************************************************/

#define Date_emf_dernier_arret_j         TIENGSTOP_NvMRamBlockDataStruct.Date_emf_dernier_arret_j

/*******************************************************************************************
    Creation des macros necessaires pour la variable Date_emf_dernier_reveil_j                       
********************************************************************************************/

#define Date_emf_dernier_reveil_j         TIENGSTOP_NvMRamBlockDataStruct.Date_emf_dernier_reveil_j

/*******************************************************************************************
    Creation des macros necessaires pour la variable Date_emf_demarrage_j                       
********************************************************************************************/

#define Date_emf_demarrage_j         TIENGSTOP_NvMRamBlockDataStruct.Date_emf_demarrage_j

/*******************************************************************************************
    Creation des macros necessaires pour la variable Date_emf_dernier_arret_a                       
********************************************************************************************/

#define Date_emf_dernier_arret_a         TIENGSTOP_NvMRamBlockDataStruct.Date_emf_dernier_arret_a

/*******************************************************************************************
    Creation des macros necessaires pour la variable Date_emf_dernier_reveil_a                       
********************************************************************************************/

#define Date_emf_dernier_reveil_a         TIENGSTOP_NvMRamBlockDataStruct.Date_emf_dernier_reveil_a

/*******************************************************************************************
    Creation des macros necessaires pour la variable Date_emf_demarrage_a                       
********************************************************************************************/

#define Date_emf_demarrage_a         TIENGSTOP_NvMRamBlockDataStruct.Date_emf_demarrage_a

/*******************************************************************************************
    Creation des macros necessaires pour la variable Eng_tOilEstim_NV                       
********************************************************************************************/

#define Eng_tOilEstim_NV         TOILEST_NvMRamBlockDataStruct.Eng_tOilEstim_NV

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_tCoMes_NV                       
********************************************************************************************/

#define Ext_tCoMes_NV         TOILEST_NvMRamBlockDataStruct.Ext_tCoMes_NV

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_tAir_NV                       
********************************************************************************************/

#define Ext_tAir_NV         TOILEST_NvMRamBlockDataStruct.Ext_tAir_NV

/*******************************************************************************************
    Creation des macros necessaires pour la variable TWCMgt_tiPha1_NV                       
********************************************************************************************/

#define TWCMgt_tiPha1_NV         TWCMGT_NvMRamBlockDataStruct.TWCMgt_tiPha1_NV

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tension_sonde_am_max_cycle                       
********************************************************************************************/

#define Tension_sonde_am_max_cycle         UPLSACQ_NvMRamBlockDataStruct.Tension_sonde_am_max_cycle

/*******************************************************************************************
    Creation des macros necessaires pour la variable Tension_sonde_am_min_cycle                       
********************************************************************************************/

#define Tension_sonde_am_min_cycle         UPLSACQ_NvMRamBlockDataStruct.Tension_sonde_am_min_cycle

/******************************************************************************************
   Creation des macros necessaires pour le tableau Vcpe_cam_offsets_eep                         
******************************************************************************************/

#define Vcpe_cam_offsets_eep         VLVACTEXENDSTOP_NvMRamBlockDataStruct.Vcpe_cam_offsets_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable VlvAct_bExOfsFrstLrn_eep                       
********************************************************************************************/

#define VlvAct_bExOfsFrstLrn_eep         VLVACTEXENDSTOP_NvMRamBlockDataStruct.VlvAct_bExOfsFrstLrn_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_stAgCmExFrstAdapt_eep                       
********************************************************************************************/

#define Ext_stAgCmExFrstAdapt_eep         VLVACTEXENDSTOP_NvMRamBlockDataStruct.Ext_stAgCmExFrstAdapt_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable VlvAct_bExOfsFrstLrnWouDft_eep                       
********************************************************************************************/

#define VlvAct_bExOfsFrstLrnWouDft_eep         VLVACTEXENDSTOP_NvMRamBlockDataStruct.VlvAct_bExOfsFrstLrnWouDft_eep

/******************************************************************************************
   Creation des macros necessaires pour le tableau Vcpi_cam_offsets_eep                         
******************************************************************************************/

#define Vcpi_cam_offsets_eep         VLVACTINENDSTOP_NvMRamBlockDataStruct.Vcpi_cam_offsets_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable VlvAct_bInOfsFrstLrn_eep                       
********************************************************************************************/

#define VlvAct_bInOfsFrstLrn_eep         VLVACTINENDSTOP_NvMRamBlockDataStruct.VlvAct_bInOfsFrstLrn_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable Ext_stAgCmInFrstAdapt_eep                       
********************************************************************************************/

#define Ext_stAgCmInFrstAdapt_eep         VLVACTINENDSTOP_NvMRamBlockDataStruct.Ext_stAgCmInFrstAdapt_eep

/*******************************************************************************************
    Creation des macros necessaires pour la variable VlvAct_bInOfsFrstLrnWouDft_eep                       
********************************************************************************************/

#define VlvAct_bInOfsFrstLrnWouDft_eep         VLVACTINENDSTOP_NvMRamBlockDataStruct.VlvAct_bInOfsFrstLrnWouDft_eep

/******************************************************************************************
   Creation des macros necessaires pour le tableau VSCtl_prmLstCrsCtlDeacCaus1                         
******************************************************************************************/

#define VSCtl_prmLstCrsCtlDeacCaus1         VSC_NvMRamBlockDataStruct.VSCtl_prmLstCrsCtlDeacCaus1

/******************************************************************************************
   Creation des macros necessaires pour le tableau VSCtl_prmLstCrsCtlDeacCaus2                         
******************************************************************************************/

#define VSCtl_prmLstCrsCtlDeacCaus2         VSC_NvMRamBlockDataStruct.VSCtl_prmLstCrsCtlDeacCaus2

/******************************************************************************************
   Creation des macros necessaires pour le tableau VSCtl_prmLstCrsCtlDeacCaus3                         
******************************************************************************************/

#define VSCtl_prmLstCrsCtlDeacCaus3         VSC_NvMRamBlockDataStruct.VSCtl_prmLstCrsCtlDeacCaus3

/******************************************************************************************
   Creation des macros necessaires pour le tableau VSCtl_prmLstCrsCtlDeacCaus4                         
******************************************************************************************/

#define VSCtl_prmLstCrsCtlDeacCaus4         VSC_NvMRamBlockDataStruct.VSCtl_prmLstCrsCtlDeacCaus4

/******************************************************************************************
   Creation des macros necessaires pour le tableau VSCtl_prmLstCrsCtlDeacCaus5                         
******************************************************************************************/

#define VSCtl_prmLstCrsCtlDeacCaus5         VSC_NvMRamBlockDataStruct.VSCtl_prmLstCrsCtlDeacCaus5

/******************************************************************************************
   Creation des macros necessaires pour le tableau VSCtl_prmLstCrsCtlDeacCaus6                         
******************************************************************************************/

#define VSCtl_prmLstCrsCtlDeacCaus6         VSC_NvMRamBlockDataStruct.VSCtl_prmLstCrsCtlDeacCaus6

/******************************************************************************************
   Creation des macros necessaires pour le tableau VSCtl_prmLstCrsCtlDeacCaus7                         
******************************************************************************************/

#define VSCtl_prmLstCrsCtlDeacCaus7         VSC_NvMRamBlockDataStruct.VSCtl_prmLstCrsCtlDeacCaus7

/******************************************************************************************
   Creation des macros necessaires pour le tableau VSCtl_prmLstCrsCtlDeacCaus8                         
******************************************************************************************/

#define VSCtl_prmLstCrsCtlDeacCaus8         VSC_NvMRamBlockDataStruct.VSCtl_prmLstCrsCtlDeacCaus8

/******************************************************************************************
   Creation des macros necessaires pour le tableau VSCtl_prmLstCrsCtlDeacCaus9                         
******************************************************************************************/

#define VSCtl_prmLstCrsCtlDeacCaus9         VSC_NvMRamBlockDataStruct.VSCtl_prmLstCrsCtlDeacCaus9

/******************************************************************************************
   Creation des macros necessaires pour le tableau VSCtl_prmLstCrsCtlDeacCaus10                         
******************************************************************************************/

#define VSCtl_prmLstCrsCtlDeacCaus10         VSC_NvMRamBlockDataStruct.VSCtl_prmLstCrsCtlDeacCaus10

/******************************************************************************************
   Creation des macros necessaires pour le tableau VSCtl_prmLstCrsCtlDeacCaus11                         
******************************************************************************************/

#define VSCtl_prmLstCrsCtlDeacCaus11         VSC_NvMRamBlockDataStruct.VSCtl_prmLstCrsCtlDeacCaus11


#endif /* VEMS_NVRAM_H */


/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : Autosar Com module                                      */
/*                                                                            */
/* !Module          : Com                                                     */
/* !Description     : Autosar Com module                                      */
/*                                                                            */
/* !File            : Com_Cfg.h                                               */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/03-Com/02_$*/
/* $Revision::   1.3      $$Author::   ngalal         $$Date::   Dec 04 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef COM_CFG_H
#define COM_CFG_H

#include "Com_CfgTypes.h"
#include "ComStack_Types.h"

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */


/**********************************************************************************************************************
  Published Information
**********************************************************************************************************************/
#define     COM_CFG_VENDOR_ID                       (38U)
#define     COM_CFG_MODULE_ID                       (50U)
#define     COM_CFG_AR_RELEASE_MAJOR_VERSION        (4U)
#define     COM_CFG_AR_RELEASE_MINOR_VERSION        (1U)
#define     COM_CFG_AR_RELEASE_REVISION_VERSION     (2U)
#define     COM_CFG_MAJOR_VERSION                (2U)
#define     COM_CFG_MINOR_VERSION                (0U)

#define Com_u8FILTERING_DIR Com_u8DIRECTION_RX

#define Com_bIE_REQUIRMENTS STD_ON  
#define Com_bGW_ENABLED STD_OFF
#define COM_DEV_ERROR_DETECT STD_ON
#define COM_SUPPORTED_IPDU_GROUPS 6U

#define COM_VERSION_INFO_API STD_OFF  
#define Com_u16NO_OF_RXIPDU_CALLOUT   29U
#define Com_u16NO_OF_TXIPDU_CALLOUT   2U
#define Com_u16NO_OF_IPDU_COUNTER     5U

#define     Com_f32FLOAT32_TOLERANCE                       0.0F
                                                    
#define     Com_f64FLOAT64_TOLERANCE                       0.0F
   

#define Com_u16NO_OF_IPDU_REPLIC       0U

/******************************************************************************/
/*! \Description Size of CancelTxSupportFlg Array \n
         calculation method: \n
          ((COM_u8NO_OF_IPDU-1)/8)+1   \n 
*******************************************************************************/

#define Com_u16CANCEL_TX_SPRT_SIZE     9U

/******************************************************************************/
/*! \Description Size of ReplicasBuffer Array \n
         calculation method: \n
          IPduLength * (ku8NoOfReplicas)   \n
*******************************************************************************/

#define Com_u16REPLIC_BUFF_SIZE       0U 

/******************************************************************************/
/*! \Description (Com_GenApi.h and Com_GenApi.c) files should be generated \n
                  only if this configuration parameter is set to true. \n
*******************************************************************************/
#define COM_bRCV_SIG_GEN_ENABLE       STD_OFF

/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable  \n
Sending Ipdu N Times \n
*******************************************************************************/
#define Com_bNTIMES_SUPPORT STD_ON


/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable  \n
Checking and Tx calling Callouts      \n
*******************************************************************************/
#define Com_bTX_CALLOUT_SUPPORT STD_ON


/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable  \n
signal Update bits processing          \n
*******************************************************************************/
#define Com_bUBIT_SUPPORT STD_ON

 
/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable  \n
Gateway Description signals                 \n
*******************************************************************************/
#define Com_bGW_DESC_SUPPORT STD_ON
  
  
/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
IPDU Transmission mode selection              \n
*******************************************************************************/
#define Com_bTMS_SUPPORT STD_ON

/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
IPDU Minimum Delay time for transmission              \n
*******************************************************************************/
#define Com_bMDT_SUPPORT STD_ON
  
/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
IPDU Counter Support                \n
*******************************************************************************/
#define Com_bIPDU_COUNTER_SUPPORT STD_ON
  
/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
IPDU and Signal Timeout Support       \n
*******************************************************************************/
#define Com_bTO_SUPPORT STD_ON

/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
 Tx Signals Error notification Support           \n
*******************************************************************************/
#define Com_bTX_INACTIVE_ERROR STD_ON

/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
 Tx IPDU check Active Support           \n
*******************************************************************************/
#define Com_bTX_INACTIVE_CHECK STD_OFF
  
  
/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
 Rx IPDU check Active Support           \n
*******************************************************************************/
#define Com_bRX_INACTIVE_CHECK STD_ON


/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
Float Signal processing support       \n
*******************************************************************************/
#define Com_bFLOAT_SIGNAL_SUPPORT STD_ON

  
/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
Invalid value Signal processing support       \n
*******************************************************************************/
#define Com_bDATA_INVALID_SUPPORT STD_ON
  

/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
Internal NULL pointer Check        \n
*******************************************************************************/
#define Com_bPTR_NULL_CHECK STD_ON
  
/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
Rx IPdus Replicas Support            \n
*******************************************************************************/
#define Com_bRX_REPLICAS_SUPPORT STD_ON
  
 
/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
Signal group Processing support            \n
*******************************************************************************/
#define Com_bSIGNAL_GROUP_SUPPORT STD_OFF
 
/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable   \n
Checking and Rx calling Callouts            \n
*******************************************************************************/
#define Com_bRX_CALLOUT_SUPPORT STD_ON

  

/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable  \n
Checking and Tx calling Callouts      \n
*******************************************************************************/
#define Com_bDATA_TP_SUPPORT STD_ON
  
  
/******************************************************************************/
/*! \Description Configuration parameter used to switch between    \n
COM module will work on Post Build variant or Not  \n
*******************************************************************************/
#define Com_bPB_VARIANT STD_ON

/******************************************************************************/
/*! \Description Configuration parameter used to enable/disable    \n
version check between Com and other interfaced modules\n
*******************************************************************************/
#define COM_bINTER_MOD_VER_CHECK    STD_OFF
  

#define Com_u16MAX_RX_IPDU_LENGTH 8

/******************************************************************************/
/*! \Description Configuration parameter used to Enable and Disable  \n
Cancel Transmit support feature  \n
*******************************************************************************/
#define Com_bPDUR_CANCEL_TRANSMIT_SUPPORT STD_ON

#define COM_START_CONFIG_DATA_UNSPECIFIED
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */

#if Com_u16NO_OF_RXIPDU_CALLOUT > 0u
extern CONST(Com_tpfbRxIpduCallout, COM_CFG_CONST)   Com_akpfbeRxIPduCalloutPtrs[Com_u16NO_OF_RXIPDU_CALLOUT];
#endif
#if Com_u16NO_OF_TXIPDU_CALLOUT > 0u
extern CONST(Com_tpfbTxIpduCallout, COM_CFG_CONST)   Com_akpfbeTxIPduCalloutPtrs[Com_u16NO_OF_TXIPDU_CALLOUT];
#endif
#if Com_u16NO_OF_IPDU_COUNTER > 0u
extern CONST(Com_tstrIPduCounter, COM_CFG_CONST)     Com_akstreIPduCounters[Com_u16NO_OF_IPDU_COUNTER];
#endif
#if Com_u16NO_OF_IPDU_REPLIC > 0u
extern CONST(Com_tstrIPduReplication, COM_CFG_CONST) Com_akstreIPduReplication[Com_u16NO_OF_IPDU_REPLIC];
#endif
#define COM_STOP_CONFIG_DATA_UNSPECIFIED
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */


#define COM_START_CONFIG_DATA_8
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */

#if Com_u16CANCEL_TX_SPRT_SIZE > 0u
extern CONST(uint8, COM_CFG_CONST)                   Com_aku8eCancelTxSupportFlg[Com_u16CANCEL_TX_SPRT_SIZE];
#endif
#define COM_STOP_CONFIG_DATA_8
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */


#define COM_START_SEC_VAR_8
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */

#if Com_u16NO_OF_IPDU_REPLIC > 0u
extern VAR(Com_tu8ReplicasCounter, COM_VAR_NOINIT)          Com_au8eReplicasCounter[Com_u16NO_OF_IPDU_REPLIC];
#endif
#if Com_u16REPLIC_BUFF_SIZE > 0u
extern VAR(uint8, COM_VAR_NOINIT)                           Com_au8eReplicasBuffer[Com_u16REPLIC_BUFF_SIZE];
#endif
#if Com_u16NO_OF_IPDU_COUNTER > 0u
extern VAR(Com_tu8IPduCounterRam, COM_VAR_NOINIT)           Com_au8eIPduCounterRam[Com_u16NO_OF_IPDU_COUNTER];
#endif

#define COM_STOP_SEC_VAR_8
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838 ++ */
#include "Memmap.h"
/* PRQA S 0838 -- */

/* Signals and SignalGroups name defintions */
/* ComIPdu */

#define Com_CMM_BV_2E8 0
#define Com_CMM_588 1
#define Com_CMM_608 2
#define Com_CMM_3B8 3
#define Com_STT_CMM_3C8 4
#define Com_CMM_788 5
#define Com_CMM_108 6
#define Com_CMM_348 7
#define Com_CMM_7A8 8
#define Com_CMM_488 9
#define Com_EAC_CMM_BSI_072 10
#define Com_EOBD_ON_CAN_7E8 11
#define Com_CMM_438 12
#define Com_EAC_CMM_UCC_0E8 13
#define Com_JDD_CAN_CMM_768 14
#define Com_CMM_5F8 15
#define Com_CMM_228 16
#define Com_CMM_1E8 17
#define Com_CMM_388 18
#define Com_CMM_468 19
#define Com_DIAG_ON_CAN_688 20
#define Com_CMM_208 21
#define Com_BSI_572 22
#define Com_CLIM_50E 23
#define Com_V2_BSI_552 24
#define Com_DIRA_495 25
#define Com_BSI_4F2 26
#define Com_V2_BV_3C9 27
#define Com_CONTEXTE_1_7F2 28
#define Com_CRASH_4C8 29
#define Com_DAT_BSI_532 30
#define Com_NEW_JDD_55F 31
#define Com_VDS_BSI_492 32
#define Com_V2_BV_489 33
#define Com_NEW_JDD_CMM_768 34
#define Com_ABR_50D 35
#define Com_CONTEXTE_1_5B2 36
#define Com_BSI_592 37
#define Com_CDS_34D 38
#define Com_BSI_792 39
#define Com_FRE_30D 40
#define Com_ELECTRON_BSI_092 41
#define Com_EOBD_ON_CAN_7DF 42
#define Com_RQD_CMM_BSI_072 43
#define Com_UDS_ON_CAN_7FF 44
#define Com_ABR_44D 45
#define Com_VOL_305 46
#define Com_DIAG_ON_CAN_6A8 47
#define Com_BSI_CMM_0A8 48
#define Com_UCC_CMM_0E0 49
#define Com_STT_BV_329 50
#define Com_FRE_3CD 51
#define Com_JDD_CAN_BSI_772 52
#define Com_V2_BVA_349 53
#define Com_EASY_MOVE_3AD 54
#define Com_RQD_CMM_UCC_0E8 55
#define Com_WMI_BSI_4D2 56
#define Com_DMTR_57C 57
#define Com_BSI_612 58
#define Com_VIS_BSI_4B2 59
#define Com_ABR_38D 60
#define Com_EOBD_ON_CAN_7E0 61
#define Com_BSI_412 62
#define Com_BSI_432 63
#define Com_CDE_ALT 64
#define Com_ETA_ALT1 65
#define Com_ETA_ALT2 66
/* ComIPduGroup */

#define Com_CMM_EB_atmo_Euro_6_2_redundant_sig_RxPduGroup 1
#define Com_TempPduGroupFor_Diag 0
#define Com_TxPduGroup_Electronic_Integration 3
#define Com_TxPduGroup_Normal_Mode 4
#define Com_TxPduGroup_Power_Latch 2
/* ComSignal and ComGroupSignal */

#define Com_CNS_RAP_GMP_MAX_CMM_BV_2E8 0
#define Com_LIBRE_5_CMM_BV_2E8 1
#define Com_CNS_POT_CPLE_ROUE_GMP_ABS_CMM_BV_2E8 2
#define Com_CTRL_CPLE_GMP_ACT_CMM_BV_2E8 3
#define Com_STS_PIL_TRANS_GMP_CMM_BV_2E8 4
#define Com_CNS_RAP_GMP_MIN_CMM_BV_2E8 5
#define Com_POS_ACCEL_COND_GMP_CMM_BV_2E8 6
#define Com_Data3_CONTEXTE_1_7F2 7
#define Com_Data1_CONTEXTE_1_7F2 8
#define Com_RESERVE_64_EOBD_ON_CAN_7E0 9
#define Com_SOC_DMTC_CMM_588 10
#define Com_VALEUR_CHARGE_CALCULEE_CMM_588 11
#define Com_VOL_ADDITIF_A_AJOUTER_CMM_588 12
#define Com_DMD_NEUTRE_GSI_CMM_588 13
#define Com_PRESSION_ATMO_CMM_588 14
#define Com_ETAT_CMDE_POMPE_EAU_CMM_588 15
#define Com_PSEUDO_CONSO_CARBURANT_CMM_588 16
#define Com_ETAT_READ_CODE_CMM_CMM_588 17
#define Com_DEFAUT_ECM_SFT_CMM_588 18
#define Com_IHM_CLIGNO_ECO_CMM_588 19
#define Com_ALRT_PRESS_HUILE_CMM_588 20
#define Com_SYNCHRO_STOP_DIFF_CMM_588 21
#define Com_SITUATION_VIE_CMM_588 22
#define Com_DDE_ALLUM_LED_ORANGE_CMM_588 23
#define Com_IHM_DMD_DEBRAYAGE_CMM_588 24
#define Com_NIV_HUILE_MOT_CMM_588 25
#define Com_DDE_ALLUM_LED_ROUGE_CMM_588 26
#define Com_MODE_FONC_MOT_CMM_588 27
#define Com_SENS_CHGMT_RAP_CMM_588 28
#define Com_ETAT_FONCTION_STT_CMM_588 29
#define Com_AUTOR_PILT_POMPE_ADD_CMM_588 30
#define Com_CDE_PUISS_VVT_CMM_588 31
#define Com_RAP_CIBLE_TRANSMIS_CMM_588 32
#define Com_RESERVE_64_UDS_ON_CAN_7FF 33
#define Com_CPLMT1_COUPLE_REEL_CMM_3B8 34
#define Com_CPLMT1_CPL_POT_AP_TR_CMM_3B8 35
#define Com_CPLMT1_REGIME_MOTEUR_CMM_3B8 36
#define Com_CPLMT1_CPL_CND_AP_TR_CMM_3B8 37
#define Com_CPLMT1_VOLONTE_COND_CMM_3B8 38
#define Com_CPT_PROCESS_4B_3B8_CMM_3B8 39
#define Com_RESERVE_64_EOBD_ON_CAN_7DF 40
#define Com_ETAT_POINT_MORT_STT_CMM_3C8 41
#define Com_DDE_OUV_CDT_STT_CMM_3C8 42
#define Com_TYPE_REDEM_STT_CMM_3C8 43
#define Com_ARRET_MOT_EN_COURS_STT_CMM_3C8 44
#define Com_DATA_BYTE8_CMM_768 45
#define Com_ETAT_ELECTR_UCE_CMM_788 46
#define Com_STATUS_REVEIL_PARTIEL_GMP_CMM_788 47
#define Com_LIBRE_1_CMM_468 48
#define Com_CODE_DEFAUT_CMM_788 49
#define Com_STATUS_CONFABSENT_CMM_788 50
#define Com_VERSION_SOFT_CMM_108 51
#define Com_EDITION_CALIB_CMM_108 52
#define Com_VERS_DATE2_MOIS_CMM_108 53
#define Com_EDITION_SOFT_CMM_108 54
#define Com_VERS_DATE2_ANNEE_CMM_108 55
#define Com_VERSION_APPLI_CMM_108 56
#define Com_VERS_DATE2_JOUR_CMM_108 57
#define Com_VERSION_SYSTEME_CMM_108 58
#define Com_DELEST_SECU_MOT_NIV2_CMM_348 59
#define Com_ETAT_CMM_DYN_CMM_348 60
#define Com_ETAT_CONS_APPL_GMV_CMM_348 61
#define Com_CONS_SOUL_PUIS_COMP_CMM_348 62
#define Com_RAP_ENGAGE_CALCULE_CMM_348 63
#define Com_REQ_MIL_FIXE_CMM_348 64
#define Com_ETAT_MT_CMM_348 65
#define Com_SYNCHRO_DC_GLOBAL_CMM_348 66
#define Com_CONTACT_OBD_CMM_348 67
#define Com_PRES_DEF_OBD_SIGNALE_SUR_MIL_CMM_348 68
#define Com_BES_PREP_MOT_CMM_348 69
#define Com_REQ_MIL_CLNGNT_CMM_348 70
#define Com_DDE_MODE_BV_MET_CMM_348 71
#define Com_AUTORIS_DECOL_BV_CMM_348 72
#define Com_ACQ_ASR_MSR_CMM_348 73
#define Com_MODES_DEGRADES_MT_CMM_348 74
#define Com_CONT_EMBR_CMM_CMM_348 75
#define Com_SOUTIEN_GENE_ELECT_CMM_348 76
#define Com_COUPLE_RESISTANT_CMM_348 77
#define Com_CPLE_COND_AVT_TRT_CMM_348 78
#define Com_ETAT_REALISATION_WUC_CMM_348 79
#define Com_DATA_BYTE7_CMM_768 80
#define Com_PRESSION_REFRI_2_CMM_348 81
#define Com_ETAT_CNS_ASR_MSR_CMM_348 82
#define Com_EAU_GAZOLE_CMM_348 83
#define Com_U_MAX_CNS_CMM_7A8 84
#define Com_VAR_NEG_MAX_CNS_CMM_7A8 85
#define Com_U_MIN_CNS_CMM_7A8 86
#define Com_VAR_POS_MAX_CNS_CMM_7A8 87
#define Com_DATA_BYTE6_CMM_768 88
#define Com_RATES_COMBUSTION_CMM_488 89
#define Com_CNS_POMPE_EAU_RTE_CMM_488 90
#define Com_DMD_GMP_CLIGNO_STOP_SVCE_CMM_488 91
#define Com_TEMP_AIR_MOT_CMM_488 92
#define Com_TEMP_EAU_MOT_CMM_488 93
#define Com_RISQUE_COLMATAGE_FAP_CMM_488 94
#define Com_REQ_LAMPE_MIL_CMM_488 95
#define Com_PRESSION_REFRI_CMM_488 96
#define Com_CNS_REGUL_RALENTI_CMM_488 97
#define Com_TYPE_INFO_CONSO_CARB_CMM_488 98
#define Com_CONSO_CARBURANT_CMM_488 99
#define Com_FORCAGE_PRESSION_BVA_CMM_488 100
#define Com_DDE_ALLUM_VOY_MLGE_PVRE_CMM_488 101
#define Com_TEMP_HUILE_MOT_CMM_488 102
#define Com_ETAT_GESTION_CLIM_CMM_488 103
#define Com_DEM_EN_COURS_CMM_488 104
#define Com_DEFAUT_RVV_LVV_CMM_488 105
#define Com_ALRT_TEMP_EAU_CMM_488 106
#define Com_COUP_CLIM_SECU_CMM_488 107
#define Com_REQ_LAMPE_PRECH_CMM_488 108
#define Com_ETAT_CALCULATR_EAC_CMM_BSI_072 109
#define Com_RESERVE_8_EAC_CMM_BSI_072 110
#define Com_RESERVE_64_EOBD_ON_CAN_7E8 111
#define Com_ENVOI_ETAT_CALCULATR_EAC_CMM_BSI_072 112
#define Com_LIBRE_6_CMM_7A8 113
#define Com_LIBRE_CMM_348 114
#define Com_REGIME_CPLE_MAX_CMM_438 115
#define Com_PUISS_AFF_DYN_CMM_438 116
#define Com_PRCT_PRESSION_SURAL_CMM_438 117
#define Com_INDICE_PERFO_CMM_438 118
#define Com_PRCT_PUISS_AFF_DYN_CMM_438 119
#define Com_PRCT_CPLE_AFF_DYN_CMM_438 120
#define Com_CPLE_AFF_DYN_CMM_438 121
#define Com_CPLE_MINI_CMM_438 122
#define Com_LIBRE_4_CMM_788 123
#define Com_ETAT_CALCULATR_EAC_CMM_UCC_0E8 124
#define Com_RESERVE_8_EAC_CMM_UCC_0E8 125
#define Com_LIBRE_STT_CMM_3C8 126
#define Com_ENVOI_ETAT_CALCULATR_EAC_CMM_UCC_0E8 127
#define Com_DATA_EMIS_JDD_JDD_CAN_CMM_768 128
#define Com_BESOINS_MTH_CDB_1_CMM_5F8 129
#define Com_BESOINS_SEEM_CDB_2_CMM_5F8 130
#define Com_BESOINS_TAR_CDB_1_CMM_5F8 131
#define Com_BESOINS_TAV_CDB_1_CMM_5F8 132
#define Com_BESOINS_SEEM_CDB_1_CMM_5F8 133
#define Com_POS_PDLE_EMBR_CMM_CMM_228 134
#define Com_LIBRE_5_CMM_228 135
#define Com_LIBRE_3_CMM_228 136
#define Com_CPT_PROCESS_4B_228_CMM_228 137
#define Com_INFO_CPLE_EASY_MOVE_CMM_228 138
#define Com_CPLE_DISPO_HILL_ASSIST_CMM_228 139
#define Com_CPLE_MOT_PRECIS_CMM_228 140
#define Com_POINT_DUR_SECU_CMM_228 141
#define Com_PRESS_MASTERV_2_HYB_CMM_228 142
#define Com_AUTORISATION_RDT_CMM_228 143
#define Com_CPLE_EM_INCERTAIN_CMM_228 144
#define Com_EFCMNT_PDLE_ACCEL_CMM_228 145
#define Com_CHKSUM_TRME_DYN5_CMM_CMM_228 146
#define Com_CPLE_POT_MAX_INST_CMM_228 147
#define Com_FREEWHEELING_REQ_CMM_228 148
#define Com_CMD_MEAP_CMM_1E8 149
#define Com_ETAT_DEBIT_AERO_CMM_1E8 150
#define Com_CONS_SOUL_THERM_COMP_CMM_1E8 151
#define Com_DDE_BOOST_SCR_INJ_CMM_1E8 152
#define Com_REQ_CHARGE_MOT_CMM_1E8 153
#define Com_TEMP_CARB_CMM_1E8 154
#define Com_LIBRE_2_CMM_1E8 155
#define Com_DEFAUT_CMM_CMM_1E8 156
#define Com_LIBRE_1_CMM_1E8 157
#define Com_TYPAGE_U_SEEM_CMM_1E8 158
#define Com_POS_MEAP_SOFT_CMM_1E8 159
#define Com_DDE_BOOST_SCR_DEGEL_CMM_1E8 160
#define Com_PREPA_AR_EN_COURS_CMM_1E8 161
#define Com_U_SEEM_REF_CMM_1E8 162
#define Com_TEMP_REGUL_EAU_MOT_CMM_1E8 163
#define Com_K_U_SEEM_CMM_1E8 164
#define Com_DDE_TENS_MIN_GMV_CMM_1E8 165
#define Com_CPT_NBR_REDEM_CMM_1E8 166
#define Com_DISTANCE_BV_CMM_388 167
#define Com_VITESSE_VEHICULE_BV_NF_CMM_388 168
#define Com_ACCEL_LONGI_BV_CMM_388 169
#define Com_VITESSE_VEHICULE_BV_CMM_388 170
#define Com_DMD_REL_R2_CMM_468 171
#define Com_DEFAUT_PROD_CMM_468 172
#define Com_CNS_U_REG_ALTERN_CMM_468 173
#define Com_AUTOR_CMM_DAE_CMM_468 174
#define Com_NIV_PROD_GEN_CMM_468 175
#define Com_REQ_LAMPE_DEF_VIDE_CMM_468 176
#define Com_DMD_ACT_CONS_SEEM_CMM_468 177
#define Com_IMMINENCE_STOP_MTH_CMM_468 178
#define Com_ETAT_CDT_VHL_CMM_468 179
#define Com_ETAT_ACTIV_WARMUP_CMM_468 180
#define Com_CONTACT_FREIN2_INC_CMM_468 181
#define Com_DMD_LEST_PROD_EE_CMM_468 182
#define Com_ETAT_DAMP_CMM_CMM_468 183
#define Com_TRANSIT_TURBO_CRS_CMM_468 184
#define Com_ETAT_FEE_CMM_468 185
#define Com_DEFAUT_CMM_CMM_468 186
#define Com_LIBRE_4_CMM_3B8 187
#define Com_DMD_REL_R3_CMM_468 188
#define Com_ETAT_AUTORISATION_DEM_CMM_468 189
#define Com_BESOIN_NIVEAU_CARB_CMM_468 190
#define Com_DELEST_SECU_MOT_NIV1_CMM_468 191
#define Com_Data2_CONTEXTE_1_7F2 192
#define Com_PROTECTION_DEMARREUR_CMM_468 193
#define Com_DMD_REL_R1_CMM_468 194
#define Com_ETAT_GAP_CMM_468 195
#define Com_AUTORISATION_RAMPAGE_CMM_468 196
#define Com_ETAT_PROD_CMM_468 197
#define Com_CMM608Data1_CMM_608 198
#define Com_PRESSION_SURAL_CMM_468 199
#define Com_ETAT_DEMARREUR_CMM_468 200
#define Com_DDE_DELEST_STTA_CMM_468 201
#define Com_RESERVE_64_DIAG_ON_CAN_688 202
#define Com_CPLE_COND_APR_TRT_CMM_208 203
#define Com_VOLONTE_COND_CMM_208 204
#define Com_REQ_CHARGE_MOT_CMM_208 205
#define Com_FIGEAGE_PERTURB_CPLE_CMM_208 206
#define Com_DIAG_MUX_ON_CMM_208 207
#define Com_REGIME_MOTEUR_CMM_208 208
#define Com_ETAT_RVV_LVV_CMM_208 209
#define Com_AC_OUT_CMM_208 210
#define Com_CPLE_ANTICIPE_CMM_208 211
#define Com_COUPLE_REEL_CMM_208 212
#define Com_CPLE_MT_INCERTAINS_CMM_208 213
#define Com_CPLE_POT_APR_TRT_CMM_208 214
#define Com_CONTACT_FREIN2_CMM_208 215
#define Com_CMM608Data5_CMM_608 216
#define Com_CMM608Data6_CMM_608 217
#define Com_BESOINS_GEI_CDB_3_BSI_572 218
#define Com_AUT_WARM_UP_GEI_BSI_572 219
#define Com_BAT_DEFAUT_T_BIN_BSI_572 220
#define Com_BAT_U_PRED_REDEM_BSI_572 221
#define Com_BAT_DEFAUT_U_BIN_BSI_572 222
#define Com_BESOINS_GEI_CDB_1_BSI_572 223
#define Com_BESOINS_GEI_CDB_2_BSI_572 224
#define Com_BAT_DEFAUT_I_BIN_BSI_572 225
#define Com_DEM_RAL_HAB_CLIM_50E 226
#define Com_CPT_TRAME_BSI_CLIM_50E 227
#define Com_CNS_CONT_GMV_CLIM_CLIM_50E 228
#define Com_CHKSUM_CONS_RVV_LVV_CLIM_50E 229
#define Com_INTERD_ARRET_HAB_CLIM_50E 230
#define Com_PUISS_MECA_CLIM_CLIM_50E 231
#define Com_DDE_ACTIVATION_LVV_CLIM_50E 232
#define Com_TYPE_REGUL_LONGI_CLIM_50E 233
#define Com_DEF_IDENT_HAB_CLIM_50E 234
#define Com_NIV_DELESTAGE_SEV_CLIM_50E 235
#define Com_DDE_REDEM_MOT_HAB_CLIM_50E 236
#define Com_PRES_COND_CLIM_50E 237
#define Com_CONS_LIM_VITESSE_VEH_CLIM_50E 238
#define Com_DDE_ACTIVATION_RVV_ACC_CLIM_50E 239
#define Com_ETAT_EMB_COMP_CLIM_50E 240
#define Com_CMM552DATA6_V2_BSI_552 241
#define Com_CMM552DATA5_V2_BSI_552 242
#define Com_CMM552DATA4_V2_BSI_552 243
#define Com_AUTOR_ARRET_MOT_DA_DIRA_495 244
#define Com_DDE_REDEM_DA_DIRA_495 245
#define Com_VALEUR_SOC_ETENDUE_BSI_4F2 246
#define Com_POS_MEAP_ACT_BSI_4F2 247
#define Com_BAT_RES_INT_ESTIM_BSI_4F2 248
#define Com_VAR_TENSION_PROD_EE_BSI_4F2 249
#define Com_BAT_UBATT_CO_ESTIM_BSI_4F2 250
#define Com_GRAV_ER_TENSION_MIN_BSI_4F2 251
#define Com_STATUS_SOC_BSI_4F2 252
#define Com_DMD_MEAP_CLIM_BSI_4F2 253
#define Com_GRAV_ER_TENSION_MAX_BSI_4F2 254
#define Com_TENSION_MIN_PROD_EE_BSI_4F2 255
#define Com_TENSION_MAX_PROD_EE_BSI_4F2 256
#define Com_CPLE_PERTE_BVA_V2_BV_3C9 257
#define Com_REGIME_ENT_BOITE_ETENDU_V2_BV_3C9 258
#define Com_CPT_PROCESS_4B_V2_3C9_V2_BV_3C9 259
#define Com_CPLE_MAX_TRANS_EMBR_V2_BV_3C9 260
#define Com_TAUX_CONV_CPLE_GMP_V2_BV_3C9 261
#define Com_CHKSUM_TRME_DYN_V2_3C9_V2_BV_3C9 262
#define Com_CMM608Data7_CMM_608 263
#define Com_C2000_V2_BV_3C9 264
#define Com_GMP_TRANS_STS_V2_BV_3C9 265
#define Com_RAP_CIBLE_BVMP_V2_BV_3C9 266
#define Com_CODE_DIAGNOSTIC_CONTEXTE_1_7F2 267
#define Com_ETAT_INFO_EOBD_BSI_CONTEXTE_1_7F2 268
#define Com_INFO_CRASH_CRASH_4C8 269
#define Com_CMM608Data2_CMM_608 270
#define Com_BAT_I_MAX_TRAITE_DAT_BSI_532 271
#define Com_BAT_U_MIN_TRAITE_DAT_BSI_532 272
#define Com_BAT_RINT_NORM_TRAITE_DAT_BSI_532 273
#define Com_DATA_ACQ_JDD_BSI_2_NEW_JDD_55F 274
#define Com_VDS_4_VDS_BSI_492 275
#define Com_VDS_2_VDS_BSI_492 276
#define Com_VDS_6_VDS_BSI_492 277
#define Com_VDS_5_VDS_BSI_492 278
#define Com_VDS_1_VDS_BSI_492 279
#define Com_VDS_3_VDS_BSI_492 280
#define Com_DEFAUT_ETAT_BV_V2_BV_489 281
#define Com_IND_SPORT_GMP_PRCT_V2_BV_489 282
#define Com_RC01_PERMANENT_SYNTHESE_BV_V2_BV_489 283
#define Com_PROG_BV_SELECT_V2_BV_489 284
#define Com_CMM608Data3_CMM_608 285
#define Com_INTERDICTION_DEMA_V2_BV_489 286
#define Com_REQ_GMV_BV_V2_BV_489 287
#define Com_DMD_ALLUM_MIL_GUS_BV_V2_BV_489 288
#define Com_TEMP_HUILE_BV_V2_BV_489 289
#define Com_TAUX_CONV_CPLE_ETENDU_V2_BV_489 290
#define Com_CMD_RESET_MIL_ON_BV_V2_BV_489 291
#define Com_DMD_ALLUMAGE_MIL_DEFAUTS_BV_V2_BV_489 292
#define Com_CPT_PROCESS_4B_50D_ABR_50D 293
#define Com_REGUL_ABR_ABR_50D 294
#define Com_BES_FREIN_STT_ABR_50D 295
#define Com_CHKSUM_TRME_DAT_UC_FREIN_ABR_50D 296
#define Com_ETAT_INFO_EOBD_BSI_CONTEXTE_1_5B2 297
#define Com_TEMP_AIR_EXT_CONTEXTE_1_5B2 298
#define Com_CALIBRE_IBATT_BSI_592 299
#define Com_TYPE_PILT_ALTERN_BSI_592 300
#define Com_DMD_CHANGEMENT_ETAT_STT_BSI_592 301
#define Com_TEMP_BATT_BSI_592 302
#define Com_IBATT_BSI_592 303
#define Com_ETAT_CHARGE_BATTERIE_BSI_592 304
#define Com_U_BATT_BECB_BSI_592 305
#define Com_REGUL_ESP_CDS_34D 306
#define Com_ETAT_FNCT_HILL_ASSIST_CDS_34D 307
#define Com_CPT_PROCESS_4B_ESP_CDS_34D 308
#define Com_CNS_CPLE_STAT_ASR_CDS_34D 309
#define Com_REGUL_ESP_SEUL_CDS_34D 310
#define Com_TYPE_PIL_CPLE_ESP_CDS_34D 311
#define Com_REQ_LAMPE_REGUL_ASR_ESP_CDS_34D 312
#define Com_CNS_CPLE_MSR_CDS_34D 313
#define Com_REGUL_ASR_CDS_34D 314
#define Com_PENTE_STATIQUE_CDS_34D 315
#define Com_CNS_CPLE_DYN_ASR_CDS_34D 316
#define Com_ETAT_LIGNE_RCD_BSI_792 317
#define Com_VITESSE_ROUE_AVG_NF_FRE_30D 318
#define Com_VITESSE_ROUE_ARG_NF_FRE_30D 319
#define Com_VITESSE_ROUE_ARD_NF_FRE_30D 320
#define Com_VITESSE_ROUE_AVD_NF_FRE_30D 321
#define Com_MODE_DIAG_ELECTRON_BSI_092 322
#define Com_EFFAC_DEFAUT_DIAG_ELECTRON_BSI_092 323
#define Com_DIAG_INTEGRA_ELEC_ELECTRON_BSI_092 324
#define Com_CMM608Data8_CMM_608 325
#define Com_CMM608Data4_CMM_608 326
#define Com_CMM552DATA7_V2_BSI_552 327
#define Com_VITESSE_ROUE_ARD_ABR_44D 328
#define Com_VITESSE_ROUE_ARG_ABR_44D 329
#define Com_VITESSE_VEH_ROUES_AV_ABR_44D 330
#define Com_REGIME_MOYEN_ROUES_AV_ABR_44D 331
#define Com_CPT_PROCESS_4B_A_VOL_VOL_305 332
#define Com_ANGLE_VOLANT_VOL_305 333
#define Com_VITESSE_ROT_VOL_VOL_305 334
#define Com_CHKSUM_VOL_VOL_305 335
#define Com_RESERVE_64_DIAG_ON_CAN_6A8 336
#define Com_CMM552DATA8_V2_BSI_552 337
#define Com_ETAT_DTC_NEW_JDD_CMM_768 338
#define Com_CLF_BSI_PDS_FRT_BSI_CMM_0A8 339
#define Com_CLF_BSI_PDS_FBLE_BSI_CMM_0A8 340
#define Com_AUTORIS_DVRRLLGE_BSI_CMM_0A8 341
#define Com_CLF_BSI_PDS_PLS_FRT_BSI_CMM_0A8 342
#define Com_CLF_BSI_PDS_PLS_FBLE_BSI_CMM_0A8 343
#define Com_CLF_UC_CLIENT_PDS_PLS_FRT_UCC_CMM_0E0 344
#define Com_CLF_UC_CLIENT_PDS_PLS_FBLE_UCC_CMM_0E0 345
#define Com_AUTORIS_DVRRLLGE_UCC_CMM_0E0 346
#define Com_CLF_UC_CLIENT_PDS_FBLE_UCC_CMM_0E0 347
#define Com_CLF_UC_CLIENT_PDS_FRT_UCC_CMM_0E0 348
#define Com_DEFAUT_STT_BV_STT_BV_329 349
#define Com_AUTOR_REDEM_BV_STT_BV_329 350
#define Com_CHKSUM_TRME_DYN_BV_329_STT_BV_329 351
#define Com_CPT_PROCESS_4B_BV_329_STT_BV_329 352
#define Com_CPLE_RESIST_PREDIT_STT_BV_329 353
#define Com_AUTOR_STOP_BV_STT_BV_329 354
#define Com_POS_LEVIER_P_N_STT_BV_329 355
#define Com_DMD_REDEM_BV_STT_BV_329 356
#define Com_CONTACT_FREIN3_HS_FRE_3CD 357
#define Com_PRESSION_MAITRE_CYL_FRE_3CD 358
#define Com_CONTACT_FREIN3_FRE_3CD 359
#define Com_FREINAGE_EN_COURS_FRE_3CD 360
#define Com_INHIB_REDEM_EMOVE_FRE_3CD 361
#define Com_POS_PED_EMBR_FRE_3CD 362
#define Com_DATA_ACQ_JDD_BSI_JDD_CAN_BSI_772 363
#define Com_INH_CHGT_CPR_CLIM_V2_BVA_349 364
#define Com_CNS_CPLE_REQ_BV_V2_BVA_349 365
#define Com_ETAT_CONVERT_BVA_V2_BVA_349 366
#define Com_RAP_BV_ENGAGE_MECA_V2_BVA_349 367
#define Com_ETAT_DEMUL_V2_BVA_349 368
#define Com_CHKSUM_TRME_DYN_V2_349_V2_BVA_349 369
#define Com_REGUL_REGIM_DEMAND_V2_BVA_349 370
#define Com_TYPE_RELANCE_REGIME_V2_BVA_349 371
#define Com_CPLE_MAX_ADM_BV_V2_BVA_349 372
#define Com_RAP_CIBLE_BVA_V2_BVA_349 373
#define Com_ETAT_COUPLAGE_V2_BVA_349 374
#define Com_CNS_REGUL_REGIM_V2_BVA_349 375
#define Com_CPT_PROCESS_4B_V2_349_V2_BVA_349 376
#define Com_POS_LEVIER_BV_V2_BVA_349 377
#define Com_ETAT_TRANS_CPLE_V2_BVA_349 378
#define Com_ETAT_TRAINEE_BVA_V2_BVA_349 379
#define Com_CHGT_RAP_EN_COURS_V2_BVA_349 380
#define Com_TYPE_SIP_V2_BVA_349 381
#define Com_PHASE_CHGT_ETAT_CDT_V2_BVA_349 382
#define Com_TYPE_MESSAGE_NEW_JDD_CMM_768 383
#define Com_DEFAUT_FNCT_EASY_MOVE_EASY_MOVE_3AD 384
#define Com_CPT_PROCESS_4B_EASY_MOVE_ESP_EASY_MOVE_3AD 385
#define Com_DDE_INHI_FNCT_RVV_EASY_MOVE_3AD 386
#define Com_ETAT_FNCT_FREIN_STATION_EASY_MOVE_3AD 387
#define Com_CHKSUM_TRME_DYN_EASY_MOVE_ESP_EASY_MOVE_3AD 388
#define Com_WMI_3_WMI_BSI_4D2 389
#define Com_WMI_1_WMI_BSI_4D2 390
#define Com_WMI_2_WMI_BSI_4D2 391
#define Com_ETAT_DMTR_DMTR_57C 392
#define Com_CONFIG_VHL_BSI_612 393
#define Com_U_PRED_DEMARRAGE_BSI_612 394
#define Com_MODE_CONF_VEH_BSI_612 395
#define Com_INFO_NIV_CARB_BSI_612 396
#define Com_VIS_1_VIS_BSI_4B2 397
#define Com_VIS_8_VIS_BSI_4B2 398
#define Com_VIS_5_VIS_BSI_4B2 399
#define Com_VIS_3_VIS_BSI_4B2 400
#define Com_VIS_6_VIS_BSI_4B2 401
#define Com_VIS_4_VIS_BSI_4B2 402
#define Com_VIS_7_VIS_BSI_4B2 403
#define Com_VIS_2_VIS_BSI_4B2 404
#define Com_AUTOR_ARRET_HILL_STT_ABR_38D 405
#define Com_CHKSUM_TRME_DYN_UC_FREIN_ABR_38D 406
#define Com_CPT_PROCESS_4B_38D_ABR_38D 407
#define Com_ACCEL_LONGI_ROUES_ABR_38D 408
#define Com_VITESSE_VEHICULE_ROUES_ABR_38D 409
#define Com_RESERVE_1_NEW_JDD_CMM_768 410
#define Com_DIAG_MINI_CARB_BSI_412 411
#define Com_DDE_CHAUF_HAB_BSI_412 412
#define Com_MINI_CARB_BSI_412 413
#define Com_REQ_CHAUF_HAB_BSI_412 414
#define Com_CONTACT_FREIN1_BSI_412 415
#define Com_DDE_MES_HUILE_MOT_BSI_412 416
#define Com_CONTACT_FREIN1_HS_BSI_412 417
#define Com_CONTACT_FREIN_PRK_BSI_412 418
#define Com_CPLMNT_ACTIVATION_DYN_BSI_412 419
#define Com_MARCHE_AR_BVM_BSI_412 420
#define Com_ACTIVATION_DYN_BSI_412 421
#define Com_REVEIL_MES_HUILE_MOT_BSI_432 422
#define Com_REVEIL_PREPA_DEM_MOT_BSI_432 423
#define Com_CTX_JDD_BSI_432 424
#define Com_DDE_PREPA_MOTEUR_BSI_432 425
#define Com_REVEIL_POST_VENTIL_MOT_BSI_432 426
#define Com_ETAT_RESEAU_ELEC_BSI_432 427
#define Com_DDE_DEM_MAINTENU_2_SEV_DEM_BSI_432 428
#define Com_REVEIL_PRINCIPAL_BSI_432 429
#define Com_REVEIL_PRECHAUF_FLEX_BSI_432 430
#define Com_ETAT_PRINCIP_SEV_BSI_432 431
#define Com_VOLONTE_DEM_GENE_BSI_432 432
#define Com_DDE_COUP_MT_BSI_432 433
#define Com_STATUT_DMD_DEM_BSI_432 434
#define Com_REVEIL_ANTICIPATION_ADC_BSI_432 435
#define Com_NOMBRE_TRAMES_NEW_JDD_CMM_768 436
#define Com_DATA_BYTE5_CMM_768 437
#define Com_CODES_DEFAUT_NEW_JDD_CMM_768 438
#define Com_NUMERO_TRAME_NEW_JDD_CMM_768 439
#define Com_SEED_PDS_PLS_FORT_RQD_CMM_UCC_0E8 440
#define Com_SEED_PDS_PLS_FBLE_RQD_CMM_UCC_0E8 441
#define Com_SEED_PDS_FRT_RQD_CMM_UCC_0E8 442
#define Com_SEED_PDS_FBLE_RQD_CMM_UCC_0E8 443
#define Com_SEED_PDS_PLS_FORT_RQD_CMM_BSI_072 444
#define Com_SEED_PDS_PLS_FBLE_RQD_CMM_BSI_072 445
#define Com_SEED_PDS_FRT_RQD_CMM_BSI_072 446
#define Com_SEED_PDS_FBLE_RQD_CMM_BSI_072 447
#define Com_DDE_DVRRLLGE_RQD_CMM_BSI_072 448
#define Com_CMM552DATA3_V2_BSI_552 449
#define Com_CMM552DATA2_V2_BSI_552 450
#define Com_CMM552DATA1_V2_BSI_552 451
#define Com_DDE_DVRRLLGE_RQD_CMM_UCC_0E8 452
#define Com_V_REG_CDE_ALT 453
#define Com_Reserved1_CDE_ALT 454
#define Com_T_LRC_CDE_ALT 455
#define Com_LRC_OFF_ON_CDE_ALT 456
#define Com_I_LIM_CDE_ALT 457
#define Com_Reserved2_CDE_ALT 458
#define Com_Reserved3_CDE_ALT 459
#define Com_DEFAUT_HT_ALT_ETA_ALT1 460
#define Com_DEFAUT_MECA_ALT_ETA_ALT1 461
#define Com_DEFAUT_ELEC_ALT_ETA_ALT1 462
#define Com_RCO_ETA_ALT1 463
#define Com_I_ROT_ETA_ALT1 464
#define Com_DEFAUT_COM_ALT_ETA_ALT1 465
#define Com_TOF_ETA_ALT1 466
#define Com_FNR_ETA_ALT2 467
#define Com_CLASS_ETA_ALT2 468
/* ComSignalGroup */


/* PRQA S 0850 --                                                             */

#endif  /* COM_CFG_H */

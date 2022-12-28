/***************************************************************************
;**
;** FILE NAME      : JDD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
#include "JDD.H"
#include "JDD_L.H"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#pragma section ".calib" a
const boolean  Jbsi_bInh_C[JBSI_BINH_C_LNS] = {0};
const boolean  Jbsi_manu_inh = 0;
const boolean  Jbsi_manu_inh_3_trames_evt_fug = 0;
const uint8  Jbsi_calib_tempo_envoi_trame = 0;
const uint8  Jbsi_calib_tentative_envoi = 0;
const uint8  Jbsi_calib_tentative_envoi_proc = 0;
const uint8  Jbsi_calib_time_out = 0;
const uint8  Jbsi_tempo_restart_proc_delay = 0;
const uint8  JDD_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Jbsi_etat_automate;
uint8 Jbsi_etat_rcd;
boolean Jbsi_abstDTCNoCxt[JBSI_ABSTDTCNOCXT_COLS];
boolean Jbsi_ack_bsi;
boolean Jbsi_autorise_fin_power_latch;
boolean Jbsi_etat_dtc;
boolean Jbsi_pertinence_info_bsi;
boolean JDD_bEvtFailurePerm[JDD_BEVTFAILUREPERM_COLS];
uint32 Jbsi_au32idxBuffer01NoCxt[JBSI_AU32IDXBUFFER01NOCXT_COLS];
uint32 Jbsi_au32idxBuffer02NoCxt[JBSI_AU32IDXBUFFER02NOCXT_COLS];
uint32 Jbsi_au32idxBuffer03NoCxt[JBSI_AU32IDXBUFFER03NOCXT_COLS];
uint32 Jbsi_au32idxBuffer04NoCxt[JBSI_AU32IDXBUFFER04NOCXT_COLS];
uint32 Jbsi_au32idxBuffer05NoCxt[JBSI_AU32IDXBUFFER05NOCXT_COLS];
uint32 Jbsi_au32idxBuffer06NoCxt[JBSI_AU32IDXBUFFER06NOCXT_COLS];
uint32 Jbsi_au32idxBuffer07NoCxt[JBSI_AU32IDXBUFFER07NOCXT_COLS];
uint32 Jbsi_au32idxBuffer08NoCxt[JBSI_AU32IDXBUFFER08NOCXT_COLS];
uint32 Jbsi_au32idxBuffer09NoCxt[JBSI_AU32IDXBUFFER09NOCXT_COLS];
uint32 Jbsi_au32idxBuffer10NoCxt[JBSI_AU32IDXBUFFER10NOCXT_COLS];
uint32 Jbsi_au32noDTCNoCxt[JBSI_AU32NODTCNOCXT_COLS];
uint32 Jbsi_code_defaut;
uint32 Jbsi_cpt_temp_local_av_synchro;
uint32 Jbsi_kilometrage;
uint32 Jbsi_ref_horaire;
uint8 Jbsi_au8idxFltToCxtNoCxt[JBSI_AU8IDXFLTTOCXTNOCXT_COLS];
uint8 Jbsi_au8stCxtRecNoCxt[JBSI_AU8STCXTRECNOCXT_COLS];
uint8 Jbsi_Correct_lente;
uint8 Jbsi_engine_air_load;
uint8 Jbsi_etat_alimentation;
uint8 Jbsi_etat_principal_sev;
uint8 Jbsi_etat_reseau_electrique;
uint8 Jbsi_info_moteur_therm;
uint8 Jbsi_Lbd_closed_loop;
uint8 Jbsi_Ld_feedback;
uint8 Jbsi_nbre_panne_en_attente;
uint8 Jbsi_nombre_trame;
uint8 Jbsi_numero_trame;
uint8 Jbsi_pDsThrMes;
uint8 Jbsi_shunt_parc_bsi;
uint8 Jbsi_spdVeh;
uint8 Jbsi_tCoMes;
uint8 Jbsi_tempo_envoi_trame;
uint8 Jbsi_tempo_restart_processus;
uint8 Jbsi_tentative_envoi;
uint8 Jbsi_tentative_envoi_processus;
uint8 Jbsi_time_out;
uint8 Jbsi_type_message;
uint8 JDD_u8JbsiEtatAutomatePrev;
uint16 Jbsi_au16idxDftNoCxt[JBSI_AU16IDXDFTNOCXT_COLS];
uint16 Jbsi_nEng;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


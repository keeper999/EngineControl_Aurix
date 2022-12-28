/***************************************************************************
;**
;** FILE NAME      : JDD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef JDD_H
#define JDD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define JBSI_ACK_CMM_55F                  136
#define JBSI_ACK_CMM_772                  8
#define JBSI_BINH_C_LNS                       ( 972 )
#define JBSI_NB_CTXT                      30

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st111 */
#define JBSI_ANTICIPATION                 1
#define JBSI_POWER_LATCH                  2
#define JBSI_TRANSIT                      4
#define JBSI_POWER_ON                     8
#define JBSI_POWER_ON_DEFAUT              16
#define JBSI_SLEEPING                     32
/*extern uint8 Jbsi_etat_rcd;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Jbsi_bInh_C[JBSI_BINH_C_LNS];
extern const boolean  Jbsi_manu_inh;
extern const boolean  Jbsi_manu_inh_3_trames_evt_fug;
extern const uint8  Jbsi_calib_tempo_envoi_trame;
extern const uint8  Jbsi_calib_tentative_envoi;
extern const uint8  Jbsi_calib_tentative_envoi_proc;
extern const uint8  Jbsi_calib_time_out;
extern const uint8  Jbsi_tempo_restart_proc_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Jbsi_etat_rcd;
extern boolean Jbsi_autorise_fin_power_latch;
extern boolean Jbsi_etat_dtc;
extern boolean Jbsi_pertinence_info_bsi;
extern uint32 Jbsi_code_defaut;
extern uint32 Jbsi_kilometrage;
extern uint32 Jbsi_ref_horaire;
extern uint8 Jbsi_Correct_lente;
extern uint8 Jbsi_engine_air_load;
extern uint8 Jbsi_etat_alimentation;
extern uint8 Jbsi_etat_principal_sev;
extern uint8 Jbsi_etat_reseau_electrique;
extern uint8 Jbsi_info_moteur_therm;
extern uint8 Jbsi_Lbd_closed_loop;
extern uint8 Jbsi_Ld_feedback;
extern uint8 Jbsi_nombre_trame;
extern uint8 Jbsi_numero_trame;
extern uint8 Jbsi_pDsThrMes;
extern uint8 Jbsi_shunt_parc_bsi;
extern uint8 Jbsi_spdVeh;
extern uint8 Jbsi_tCoMes;
extern uint8 Jbsi_type_message;
extern uint16 Jbsi_nEng;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GD_EveRst_GJDD(void);
void GD_EveRstDft_GJDD(void);
void GD_EveRxn55F_GJDD(void);
void GD_EveRxn772_GJDD(void);
void GD_SdlFast_GJDD(void);
void JDD_CxtFrfRec(uint16 u16IdxDft);
void JDD_DftExitUnval(uint16 u16IdxDft);
void JDD_DftInPres(uint16 u16IdxDft);
void JDD_RstDftCal(void);


#endif /* JDD_H */

/*-------------------------------- end of file -------------------------------*/

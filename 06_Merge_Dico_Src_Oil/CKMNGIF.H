/***************************************************************************
;**
;** FILE NAME      : CKMNGIF.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CKMNGIF_H
#define CKMNGIF_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define REGIME_ACCEL_MAX_THRESH_MAP_COLS       ( 6 )
#define TABLE_CYL_PHYS_ORDRE_ALLUMAGE_COLS     ( 6 )

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

extern const boolean  Cipd_inh_dephia;
extern const boolean  Sync_bAcvBDCEngSpdClcn_C;
extern const boolean  Sync_bAcvTest_CpuSfty_C;
extern const uint8  Engine_spd_der_filter_gain;
extern const uint8  Regime_accel_max_thresh_map[REGIME_ACCEL_MAX_THRESH_MAP_COLS];
extern const uint8  Table_cyl_phys_ordre_allumage[TABLE_CYL_PHYS_ORDRE_ALLUMAGE_COLS];
extern const uint16  Regime_moteur_max_thresh;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Moteur_tournant;
extern boolean Sync_bRotDetEng;
extern sint8 Engine_speed_derivate;
extern uint8 Eng_noCmbNxtCyl;
extern uint8 Ext_ctTDC;
extern sint16 Ext_aEng;
extern uint16 Compteur_de_pmh;
extern uint16 Duree_dent;
extern uint16 Ext_nEngBDC;
extern uint16 Ext_nEngFineResl;
extern uint16 Ext_nEngTDC;
extern uint16 Offset_reperes_ang;
extern uint16 Periode_angulaire;
extern uint16 Periode_moteur;
extern uint16 Periode_moteur_hold;
extern uint16 Regime_moteur_0_125;
extern uint16 Regime_moteur_filtre;
extern uint16 Sync_agCkPosnRef1;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Sync_EveBDC_CkMngIf(void);
void Sync_EveCkOf_CkMngIf(void);
void Sync_EveCkOn_CkMngIf(void);
void Sync_EveCkSnOn_CkMngIf(void);
void Sync_EveRst_CkMngIf(void);
void Sync_EveRTSt_CkMngIf(void);
void Sync_EveStTR_CkMngIf(void);
void Sync_EveTDC_CkMngIf(void);
void Sync_EveTDC_CkMngIf3(void);
void Sync_SdlFast_CkMngIf(void);
void Sync_SdlMid_CkMngIf(void);


#endif /* CKMNGIF_H */

/*-------------------------------- end of file -------------------------------*/

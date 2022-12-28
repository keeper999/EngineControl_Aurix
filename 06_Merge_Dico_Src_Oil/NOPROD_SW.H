/***************************************************************************
;**
;** FILE NAME      : NOPROD_SW.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef NOPROD_SW_H
#define NOPROD_SW_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BNCFDC                            1
#define BP_DCM                            10
#define BPRESDC                           0
#define BVA                               1
#define BVM                               0
#define BVMP                              2
#define CH_ADC_CRU_VSL_MOD_V              17
#define CH_DIO_OUT_OIL_PRES_ACQ           255
#define CH_INJ_4_GDI                      3
#define DGOHAL_udtINJ_4                   3
#define DTC_STT_CRANK_DELAY_MAP_COLS           ( 16 )
#define essence                           3
#define essence_vers_gaz                  2
#define EVAP_DCM                          11
#define Ext_stGasMod_SC                   0
#define Ext_stGslMod_SC                   3
#define Ext_stPwrOff_SC                   16
#define Ext_stPwrOn_SC                    128
#define Ext_stTranGasGsl_SC               1
#define Ext_stTranGslGas_SC               2
#define Ext_stWaitAnt_SC                  8
#define Ext_stWaitPwrl_SC                 32
#define gaz                               0
#define gaz_vers_essence                  1
#define GD_AU8SIZEPARAM_LNS                   ( 147 )
#define GOBD_ETAT_HIST_OFF                5
#define GOBD_ETAT_HIST_ON                 4
#define INJ_HAL_ALL_CYLINDER              255
#define INJ_HAL_CYLINDER_4_MASK           0
#define MISF_WIN_NBR                      4
#define REGIME_MOTEUR_BKPT_MAP_COLS            ( 16 )
#define SRV_INJRCHRNECU_DATANOK           4
#define SRV_INJRCHRNECU_WAIT              0
#define SRV_INJRCHRNECU_WRITE             2
#define SRV_PRM_IDCHRNINJR_COLS                ( 2 )
#define STTD_PRESENT                      3

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st44 */
#define Cl15_BOSCH_LIX_C2                 1
#define Cl12_VALEO_TG12C                  40
#define Cl15_VALEO_FG15T044               47
#define Cl18_MELCO_9G135Hd135mm           165
#define Cl8_MELCO_6GA3_d121mm             167
#define Cl12_MELCO_6GA3_d135mm            179
/*extern uint8 NOPROD:Ext_stAltClasBSSCf;*/

/* enum st69 */
#define SAF_PUMP_VALVE_ACTIVATED          32
#define SAF_DISABLED_NOT_IN_RUNNING       128
/*extern uint8 NOPROD:Saf_status;*/

/* enum st77 */
/*extern uint8 Srv_stInjrChrnEcuStatus;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  Dtc_STT_crank_delay_map[DTC_STT_CRANK_DELAY_MAP_COLS];
extern const uint8  NOPROD_u8Inhib;
extern const uint8  Sfty_maskCfgDiag_C;
extern const uint8  Srv_IdChrnInjr_C;
extern const uint16  Regime_moteur_bkpt_map[REGIME_MOTEUR_BKPT_MAP_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Srv_stInjrChrnEcuStatus;
extern boolean Immo_bLockECUCAN;
extern uint32 DEBUG_u32Data01;
extern uint32 DEBUG_u32Data02;
extern uint32 DEBUG_u32Data03;
extern uint32 DEBUG_u32Data04;
extern uint32 DEBUG_u32Data05;
extern uint32 Tpc_free_wheeling_delay_temp;
extern uint8 Immo_bfImmoReadStDft;
extern uint8 Immo_stCANMatchOptReadSt;
extern uint8 Immo_stProgImmoReadSt;
extern uint8 Srv_prm_IdChrnInjr[SRV_PRM_IDCHRNINJR_COLS];
extern sint32 DEBUG_s32Data11;
extern sint32 DEBUG_s32Data12;
extern sint32 DEBUG_s32Data13;
extern sint32 DEBUG_s32Data14;
extern sint32 DEBUG_s32Data15;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/



#endif /* NOPROD_SW_H */

/*-------------------------------- end of file -------------------------------*/

/***************************************************************************
;**
;** FILE NAME      : THRPOSNSPLRN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRPOSNSPLRN.H"
#include "THRPOSNSPLRN_L.H"
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
const boolean  Thr_bMblRstorAcv_C = 0;
const boolean  Thr_FLrnClCtl_bManInh_C = 0;
const uint8  Thr_FLrnClCtl_tiDlyExiLoThru_C = 0;
const uint8  Thr_FLrnClCtl_tiDlyIniHiThru_C = 0;
const uint8  Thr_FLrnClCtl_tiDlyIniLoThru_C = 0;
const uint8  THRPOSNSPLRN_u8Inhib = 0;
const uint8  Tpac_MblRstor_air_temp_mini = 0;
const uint8  Tpac_MblRstor_water_temp_mini = 0;
const uint16  Thr_FClnClCtl_posnExiLoThruSp_C = 0;
const uint16  Thr_FClnClCtl_posnHiThruSp_C = 0;
const uint16  Thr_FClnClCtl_posnIniHiThruSp_C = 0;
const uint16  Thr_FClnClCtl_posnIniLoThruSp_C = 0;
const uint16  Thr_FClnClCtl_posnLoThruSp_C = 0;
const uint16  Thr_FClnClCtl_posnReturnLihSp_C = 0;
const uint16  Thr_FClnClCtl_vExiLoThru_C = 0;
const uint16  Thr_FClnClCtl_vHiThru_C = 0;
const uint16  Thr_FClnClCtl_vIniHiThru_C = 0;
const uint16  Thr_FClnClCtl_vIniLoThru_C = 0;
const uint16  Thr_FClnClCtl_vLoThru_C = 0;
const uint16  Thr_FClnClCtl_vReturnLih_C = 0;
const uint16  Thr_FLrnClCtl_posnExiLoThruSp_C = 0;
const uint16  Thr_FLrnClCtl_posnHiThruSp_C = 0;
const uint16  Thr_FLrnClCtl_posnIniHiThruSp_C = 0;
const uint16  Thr_FLrnClCtl_posnIniLoThruSp_C = 0;
const uint16  Thr_FLrnClCtl_posnLoThruSp_C = 0;
const uint16  Thr_FLrnClCtl_posnReturnLihSp_C = 0;
const uint16  Thr_FLrnClCtl_vExiLoThru_C = 0;
const uint16  Thr_FLrnClCtl_vHiThru_C = 0;
const uint16  Thr_FLrnClCtl_vIniHiThru_C = 0;
const uint16  Thr_FLrnClCtl_vIniLoThru_C = 0;
const uint16  Thr_FLrnClCtl_vLoThru_C = 0;
const uint16  Thr_FLrnClCtl_vReturnLih_C = 0;
const uint16  Thr_FMblRstor_posnReturnLihSp_C = 0;
const uint16  Thr_FMblRstor_ti_bkpt_map[THR_FMBLRSTOR_TI_BKPT_MAP_COLS] = {0};
const uint16  Thr_FMblRstorClCtl_HithruThd_C = 0;
const uint16  Thr_FMblRstorClCtl_LihSp_C = 0;
const uint16  Thr_FMblRstorClCtl_Sp_map[THR_FMBLRSTORCLCTL_SP_MAP_COLS] = {0};
const uint16  Thr_FMblRstorClCtl_SpMax_C = 0;
const uint16  Thr_FMblRstorClCtl_vHithru_C = 0;
const uint16  Thr_FMblRstorClCtl_vTar_C = 0;
const uint16  Thr_FMobRstor_tiMaxAuth_C = 0;
const uint16  Thr_uBattMaxStopsMblRstor_C = 0;
const uint16  Thr_uBattMinStopsMblRstor_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Thr_bMblRstorAcv;
boolean Thr_bMblRstorEna;
boolean Thr_bMblRstorInProgs;
boolean Thr_FClnClCtl_bAcv;
boolean Thr_FLrnClCtl_bAcv;
boolean Thr_FLrnClCtl_bTempoEnd;
boolean Thr_FSpcReqClCtl_bAcv;
uint8 Thr_FLrnClCtl_titempo;
uint8 ThrPosnSpLrn_u8State;
uint16 Thr_FClnClCtl_posnSp;
uint16 Thr_FLrnClCtl_posnExiLoThruSp;
uint16 Thr_FLrnClCtl_posnHiThruSp;
uint16 Thr_FLrnClCtl_posnIniHiThruSp;
uint16 Thr_FLrnClCtl_posnIniLoThruSp;
uint16 Thr_FLrnClCtl_posnLoThruSp;
uint16 Thr_FLrnClCtl_posnReturnLihSp;
uint16 Thr_FLrnClCtl_posnSp;
uint16 Thr_FLrnClCtl_posnTar;
uint16 Thr_FLrnClCtl_vExiLoThru;
uint16 Thr_FLrnClCtl_vHiThru;
uint16 Thr_FLrnClCtl_vIniHiThru;
uint16 Thr_FLrnClCtl_vIniLoThru;
uint16 Thr_FLrnClCtl_vLoThru;
uint16 Thr_FLrnClCtl_vReturnLih;
uint16 Thr_FLrnClCtl_vTar;
uint16 Thr_FMblRstor_tiMblRstor;
uint16 Thr_FMblRstorClCtl_posnSp;
uint16 Thr_FMblRstorClCtl_SpRaw;
uint16 Thr_FSpcReqClCtl_posnSp;
uint16 Thr_SampleTiMid_physVal;
uint16 THRPOSNSPLRN_u16SlewOut;
uint16 THRPOSNSPLRN_u16TimerCount;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


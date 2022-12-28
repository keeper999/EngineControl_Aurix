/***************************************************************************
;**
;** FILE NAME      : THRPOSNSPLRN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRPOSNSPLRN_H
#define THRPOSNSPLRN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define THR_FMBLRSTOR_TI_BKPT_MAP_COLS         ( 16 )
#define THR_FMBLRSTORCLCTL_SP_MAP_COLS         ( 16 )
#define THRPOSNSPLRN_EXIT_LOW_THRUST      5
#define THRPOSNSPLRN_HIGH_THRUST_SEARCH   1
#define THRPOSNSPLRN_INIT                 0
#define THRPOSNSPLRN_LIMP_HOME            4
#define THRPOSNSPLRN_LOW_THRUST_SEARCH    2
#define THRPOSNSPLRN_MCW_INHIBIT_TEST     3

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

extern const boolean  Thr_bMblRstorAcv_C;
extern const boolean  Thr_FLrnClCtl_bManInh_C;
extern const uint8  Thr_FLrnClCtl_tiDlyExiLoThru_C;
extern const uint8  Thr_FLrnClCtl_tiDlyIniHiThru_C;
extern const uint8  Thr_FLrnClCtl_tiDlyIniLoThru_C;
extern const uint8  Tpac_MblRstor_air_temp_mini;
extern const uint8  Tpac_MblRstor_water_temp_mini;
extern const uint16  Thr_FClnClCtl_posnExiLoThruSp_C;
extern const uint16  Thr_FClnClCtl_posnHiThruSp_C;
extern const uint16  Thr_FClnClCtl_posnIniHiThruSp_C;
extern const uint16  Thr_FClnClCtl_posnIniLoThruSp_C;
extern const uint16  Thr_FClnClCtl_posnLoThruSp_C;
extern const uint16  Thr_FClnClCtl_posnReturnLihSp_C;
extern const uint16  Thr_FClnClCtl_vExiLoThru_C;
extern const uint16  Thr_FClnClCtl_vHiThru_C;
extern const uint16  Thr_FClnClCtl_vIniHiThru_C;
extern const uint16  Thr_FClnClCtl_vIniLoThru_C;
extern const uint16  Thr_FClnClCtl_vLoThru_C;
extern const uint16  Thr_FClnClCtl_vReturnLih_C;
extern const uint16  Thr_FLrnClCtl_posnExiLoThruSp_C;
extern const uint16  Thr_FLrnClCtl_posnHiThruSp_C;
extern const uint16  Thr_FLrnClCtl_posnIniHiThruSp_C;
extern const uint16  Thr_FLrnClCtl_posnIniLoThruSp_C;
extern const uint16  Thr_FLrnClCtl_posnLoThruSp_C;
extern const uint16  Thr_FLrnClCtl_posnReturnLihSp_C;
extern const uint16  Thr_FLrnClCtl_vExiLoThru_C;
extern const uint16  Thr_FLrnClCtl_vHiThru_C;
extern const uint16  Thr_FLrnClCtl_vIniHiThru_C;
extern const uint16  Thr_FLrnClCtl_vIniLoThru_C;
extern const uint16  Thr_FLrnClCtl_vLoThru_C;
extern const uint16  Thr_FLrnClCtl_vReturnLih_C;
extern const uint16  Thr_FMblRstor_posnReturnLihSp_C;
extern const uint16  Thr_FMblRstor_ti_bkpt_map[THR_FMBLRSTOR_TI_BKPT_MAP_COLS];
extern const uint16  Thr_FMblRstorClCtl_HithruThd_C;
extern const uint16  Thr_FMblRstorClCtl_LihSp_C;
extern const uint16  Thr_FMblRstorClCtl_Sp_map[THR_FMBLRSTORCLCTL_SP_MAP_COLS];
extern const uint16  Thr_FMblRstorClCtl_SpMax_C;
extern const uint16  Thr_FMblRstorClCtl_vHithru_C;
extern const uint16  Thr_FMblRstorClCtl_vTar_C;
extern const uint16  Thr_FMobRstor_tiMaxAuth_C;
extern const uint16  Thr_uBattMaxStopsMblRstor_C;
extern const uint16  Thr_uBattMinStopsMblRstor_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bMblRstorAcv;
extern boolean Thr_bMblRstorInProgs;
extern boolean Thr_FClnClCtl_bAcv;
extern boolean Thr_FLrnClCtl_bAcv;
extern boolean Thr_FSpcReqClCtl_bAcv;
extern uint16 Thr_FSpcReqClCtl_posnSp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveRst_ThrPosnSpSpc(void);
void Thr_SdlMid_ThrPosnSpSpc(void);


#endif /* THRPOSNSPLRN_H */

/*-------------------------------- end of file -------------------------------*/

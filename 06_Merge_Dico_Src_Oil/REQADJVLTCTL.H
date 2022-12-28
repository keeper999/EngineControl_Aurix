/***************************************************************************
;**
;** FILE NAME      : REQADJVLTCTL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef REQADJVLTCTL_H
#define REQADJVLTCTL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define LSSYS_BLSDSMAINOXCHEATMODEREQ_M_COLS   ( 8 )
#define LSSYS_BLSUSMAINOXCHEATMODEREQ_M_COLS   ( 8 )
#define LSSYS_LSDSMAINOXCHEATMODEREQ_T_COLS    ( 8 )
#define LSSYS_LSUSMAINOXCHEATMODEREQ_T_COLS    ( 8 )

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

extern const boolean  LsSys_bEnaLsDs_AdjuBattNom_C;
extern const boolean  LsSys_bEnaLsUs_AdjuBattNom_C;
extern const boolean  LsSys_bLsDsMainOxCHeatModeReq_M[LSSYS_BLSDSMAINOXCHEATMODEREQ_M_COLS];
extern const boolean  LsSys_bLsUsMainOxCHeatModeReq_M[LSSYS_BLSUSMAINOXCHEATMODEREQ_M_COLS];
extern const uint8  LsSys_LsDsMainOxCHeatModeReq_T[LSSYS_LSDSMAINOXCHEATMODEREQ_T_COLS];
extern const uint8  LsSys_LsUsMainOxCHeatModeReq_T[LSSYS_LSUSMAINOXCHEATMODEREQ_T_COLS];
extern const uint16  LsSys_uBatt2LsDsMainOxCRef_C;
extern const uint16  LsSys_uBatt2LsDsMainOxCThd_C;
extern const uint16  LsSys_uBatt2LsUsMainOxCRef_C;
extern const uint16  LsSys_uBatt2LsUsMainOxCThd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean LsSys_bAdj_uBattNom;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HeatSenO2_EveRst_ReqAdjVltCtl(void);
void HeatSenO2_SdlMid_ReqAdjVltCtl(void);


#endif /* REQADJVLTCTL_H */

/*-------------------------------- end of file -------------------------------*/

/***************************************************************************
;**
;** FILE NAME      : ACCPACQPOS.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPACQPOS_H
#define ACCPACQPOS_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ACCP1_LINPOS_MAP_COLS                  ( 4 )
#define ACCP1_LINPOSBKPT_MAP_COLS              ( 4 )
#define ACCP2_LINPOS_MAP_COLS                  ( 4 )
#define ACCP2_LINPOSBKPT_MAP_COLS              ( 4 )

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

extern const uint8  AccP1_filter_gain;
extern const uint8  AccP2_filter_gain;
extern const uint16  AccP_uThdCohSens_C;
extern const uint16  AccP_uThdScgSens1_C;
extern const uint16  AccP_uThdScgSens2_C;
extern const uint16  AccP_uThdScpSens1_C;
extern const uint16  AccP_uThdScpSens2_C;
extern const uint16  AccP1_LinPos_Map[ACCP1_LINPOS_MAP_COLS];
extern const uint16  AccP1_LinPosBkpt_Map[ACCP1_LINPOSBKPT_MAP_COLS];
extern const uint16  AccP2_LinPos_Map[ACCP2_LINPOS_MAP_COLS];
extern const uint16  AccP2_LinPosBkpt_Map[ACCP2_LINPOSBKPT_MAP_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Aps_1_raw_position;
extern uint16 Pos_pedale_1_result_ad_conv;
extern uint16 Pos_pedale_2_result_ad_conv;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AccP_EveRst_AcqPosn(void);
void AccP_SdlFast_AcqPosn(void);


#endif /* ACCPACQPOS_H */

/*-------------------------------- end of file -------------------------------*/

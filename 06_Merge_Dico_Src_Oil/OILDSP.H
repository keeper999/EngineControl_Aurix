/***************************************************************************
;**
;** FILE NAME      : OILDSP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OILDSP_H
#define OILDSP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define OILDSP_NENG_A_COLS                     ( 8 )
#define OILDSP_RAIRLD_A_COLS                   ( 8 )
#define OILDSP_RCRCPRESINPRESBLBYCND_T_COLS    ( 8 )
#define OILDSP_RFUDSPINBLBYCND_T_COLS          ( 8 )
#define OILDSP_RFUMASSINOIL_T_COLS             ( 8 )
#define OILDSP_RMASSFLOWINBLBYCND_M_LNS       ( 8 )
#define OILDSP_RMASSFLOWINBLBYCND_M_COLS       ( 8 )
#define OILDSP_TCOMES_A_COLS                   ( 8 )
#define OILDSP_TOILMES_A_COLS                  ( 8 )

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

extern const uint32  OilDsp_mFuInOilEstimInit_C;
extern const uint8  OilDsp_facAfs_C;
extern const uint8  OilDsp_rCrcPresInPresBlbyCnd_T[OILDSP_RCRCPRESINPRESBLBYCND_T_COLS];
extern const uint8  OilDsp_rFuDspInBlbyCnd_T[OILDSP_RFUDSPINBLBYCND_T_COLS];
extern const uint8  OilDsp_rFuDspInj_C;
extern const uint8  OilDsp_rFuDspInjThd_C;
extern const uint8  OilDsp_rFuMassInOil_T[OILDSP_RFUMASSINOIL_T_COLS];
extern const uint8  OilDsp_rMassFlowInBlbyCnd_M[OILDSP_RMASSFLOWINBLBYCND_M_LNS][OILDSP_RMASSFLOWINBLBYCND_M_COLS];
extern const uint8  OilDsp_tCoMes_A[OILDSP_TCOMES_A_COLS];
extern const sint16  OilDsp_tAbsorbPhaMax_C;
extern const sint16  OilDsp_tAbsorbPhaMaxThd_C;
extern const sint16  OilDsp_tDspPhaMin_C;
extern const sint16  OilDsp_tDspPhaMinThd_C;
extern const uint16  OilDsp_nEng_A[OILDSP_NENG_A_COLS];
extern const uint16  OilDsp_rAirLd_A[OILDSP_RAIRLD_A_COLS];
extern const uint16  OilDsp_tOilMes_A[OILDSP_TOILMES_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void OilSys_EveRst_OilDsp(void);
void OilSys_EveTDC_OilDsp(void);
void OilSys_SdlMid_OilDsp(void);


#endif /* OILDSP_H */

/*-------------------------------- end of file -------------------------------*/

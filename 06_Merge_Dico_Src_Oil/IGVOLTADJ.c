/***************************************************************************
;**
;** FILE NAME      : IGVOLTADJ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IGVOLTADJ.H"
#include "IGVOLTADJ_L.H"
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
const boolean  IgVoltAdj_bActVoltAdj_C = 0;
const boolean  IgVoltAdj_bVoltAdj_M[IGVOLTADJ_BVOLTADJ_M_LNS][IGVOLTADJ_BVOLTADJ_M_COLS] = {0};
const uint32  IgVoltAdj_dstVehMinVoltAdj_C = 0;
const uint8  IgVoltAdj_rIcdBstReqHiThd_C = 0;
const uint8  IgVoltAdj_rIcdBstReqLoThd_C = 0;
const uint8  IGVOLTADJ_u8Inhib = 0;
const uint16  IgVoltAdj_nEng_bVoltAdjX_A[IGVOLTADJ_NENG_BVOLTADJX_A_COLS] = {0};
const uint16  IgVoltAdj_rAir_bVoltAdjY_A[IGVOLTADJ_RAIR_BVOLTADJY_A_COLS] = {0};
const uint16  IgVoltAdj_tiActDly_C = 0;
const uint16  IgVoltAdj_tiDeacDly_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IGVOLTADJ_bOutputHysteresis;
boolean IGVOLTADJ_bOutputTrndly;
boolean IGVOLTADJ_bResultComp_prev;
boolean IGVOLTADJ_bVltAdjZnFlipFlopOut;
boolean IgVoltAdj_bVoltAdj;
boolean IgVoltAdj_bVoltAdjOpp;
boolean IgVoltAdj_bVoltAdjReq;
boolean IgVoltAdjReq_bVoltAdj;
uint16 IGVOLTADJ_u16VtAjZnTrnOnDlyCntr1;
uint16 IGVOLTADJ_u16VtAjZnTrnOnDlyCntr2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


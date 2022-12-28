/***************************************************************************
;**
;** FILE NAME      : VLVACTEXESTIM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTEXESTIM.H"
#include "VLVACTEXESTIM_L.H"
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
const boolean  VlvAct_bExPosnEstimCmdOfsSel_C = 0;
const boolean  VlvAct_bExPosnEstimInh_C = 0;
const uint8  VlvAct_ExPosnEstimCmdDb_C = 0;
const uint8  VlvAct_ExPosnEstimInvTo_M[VLVACT_EXPOSNESTIMINVTO_M_LNS][VLVACT_EXPOSNESTIMINVTO_M_COLS] = {0};
const uint8  VlvAct_ExPosnEstimK_M[VLVACT_EXPOSNESTIMK_M_LNS][VLVACT_EXPOSNESTIMK_M_COLS] = {0};
const uint8  VlvAct_ExPosnEstimMax_C = 0;
const uint8  VlvAct_ExPosnEstimMin_C = 0;
const uint8  VlvAct_nExPosnEstim_T[VLVACT_NEXPOSNESTIM_T_COLS] = {0};
const uint8  VlvAct_nExPosnEstimEnaMax_C = 0;
const uint8  VlvAct_tOilExPosnEstim_T[VLVACT_TOILEXPOSNESTIM_T_COLS] = {0};
const uint8  VLVACTEXESTIM_u8Inhib = 0;
const uint16  VlvAct_ExPosnEstimCmdOfs_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 VlvAct_ExPosnEstimGainA;
sint16 VlvAct_agCmExSpdEstim;
sint16 VlvAct_ExMngStCmdNorm;
sint16 VlvAct_ExPosnEstimSpd;
uint16 VlvAct_agCmExEstimVar;
uint16 VlvAct_agCmExMesVar;
uint16 VlvAct_agCmExPosnEstim;
uint16 VlvAct_ExPosnEstimGainB;
uint16 VlvAct_ExPosnEstimPosn;
uint16 VLVACTEXESTIM_u16agCmExEstimPrev;
uint16 VLVACTEXESTIM_u16agCmExEstimVar;
uint16 VLVACTEXESTIM_u16RelExVvtMesPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


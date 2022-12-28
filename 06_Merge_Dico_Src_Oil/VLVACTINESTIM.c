/***************************************************************************
;**
;** FILE NAME      : VLVACTINESTIM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTINESTIM.H"
#include "VLVACTINESTIM_L.H"
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
const boolean  VlvAct_bInPosnEstimCmdOfsSel_C = 0;
const boolean  VlvAct_bInPosnEstimInh_C = 0;
const uint8  VlvAct_InPosnEstimCmdDb_C = 0;
const uint8  VlvAct_InPosnEstimInvTo_M[VLVACT_INPOSNESTIMINVTO_M_LNS][VLVACT_INPOSNESTIMINVTO_M_COLS] = {0};
const uint8  VlvAct_InPosnEstimK_M[VLVACT_INPOSNESTIMK_M_LNS][VLVACT_INPOSNESTIMK_M_COLS] = {0};
const uint8  VlvAct_InPosnEstimMax_C = 0;
const uint8  VlvAct_InPosnEstimMin_C = 0;
const uint8  VlvAct_nInPosnEstim_T[VLVACT_NINPOSNESTIM_T_COLS] = {0};
const uint8  VlvAct_nInPosnEstimEnaMax_C = 0;
const uint8  VlvAct_tOilInPosnEstim_T[VLVACT_TOILINPOSNESTIM_T_COLS] = {0};
const uint8  VLVACTINESTIM_u8Inhib = 0;
const uint16  VlvAct_InPosnEstimCmdOfs_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 VlvAct_InPosnEstimGainA;
sint16 VlvAct_agCmInSpdEstim;
sint16 VlvAct_InMngStCmdNorm;
sint16 VlvAct_InPosnEstimSpd;
uint16 VlvAct_agCmInEstimVar;
uint16 VlvAct_agCmInMesVar;
uint16 VlvAct_agCmInPosnEstim;
uint16 VlvAct_InPosnEstimGainB;
uint16 VlvAct_InPosnEstimPosn;
uint16 VLVACTINESTIM_u16agCmInEstimPrev;
uint16 VLVACTINESTIM_u16agCmInEstimVar;
uint16 VLVACTINESTIM_u16RelInVvtMesPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


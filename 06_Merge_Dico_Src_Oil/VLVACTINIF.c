/***************************************************************************
;**
;** FILE NAME      : VLVACTINIF.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTINIF.H"
#include "VLVACTINIF_L.H"
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
const boolean  VlvAct_bInCmVlvActOfsEna_C = 0;
const boolean  VlvAct_bInhDiagPresScavIdc_C = 0;
const boolean  VlvAct_bInSelDefPos_C = 0;
const boolean  Vxx_vvtc_in_angl_test_bed = 0;
const sint8  VlvAct_agCkOpInVlvReqRef0Max_C = 0;
const sint8  VlvAct_agCkOpInVlvReqRef0Min_C = 0;
const uint8  VlvAct_agInMaxSlopVlvSpPos_C = 0;
const uint8  VlvAct_agInMinSlopVlvSpPos_C = 0;
const uint8  VlvAct_tiInLihPosDly_C = 0;
const uint8  VLVACTINIF_u8Inhib = 0;
const sint16  Ext_agCkOpInVlvEstimRef0Ini_C = 0;
const sint16  VlvAct_agCkInCmRefOfs_C = 0;
const sint16  VlvAct_agCkInCmToothOfsMax_C = 0;
const uint16  VlvAct_agCkInCmSpMax_C = 0;
const uint16  VlvAct_agCkInCmSpMin_C = 0;
const uint16  VlvAct_agCkInExVlvDif_T[VLVACT_AGCKINEXVLVDIF_T_COLS] = {0};
const uint16  VlvAct_agInLihPos_C = 0;
const uint16  VlvAct_agInSpFuncIntlThd_C = 0;
const uint16  VlvAct_agInSpFuncIntlThdHi_C = 0;
const uint16  VlvAct_agInSpFuncIntlThdHiHys_C = 0;
const uint16  VlvAct_agInSpFuncIntlThdHys_C = 0;
const uint16  VlvAct_agInSpFuncIntlThdHysInf_C = 0;
const uint16  VlvAct_agInSpFuncIntlThdLo_C = 0;
const uint16  VlvAct_agInSpFuncIntlThdLoHys_C = 0;
const uint16  VlvAct_agInSpFuncIntlThdMax_C = 0;
const uint16  VlvAct_agInSpFuncIntlThdMaxHys_C = 0;
const uint16  VlvAct_agInSpFuncIntThdMaxHys1_C = 0;
const uint16  VlvAct_pInhDiagPresScavDif_M[VLVACT_PINHDIAGPRESSCAVDIF_M_COLS] = {0};
const uint16  VlvAct_tiDlyInhDiagPresScavOff_C = 0;
const uint16  Vxx_vvtc_in_angl_sp_cal = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VlvAct_bCmdInServoLocLop;
boolean VlvAct_bInSpFuncIntlHiOutIdc;
boolean VlvAct_bInSpFuncIntlHiOutIdcInt;
boolean VlvAct_bInSpFuncIntlLoOutIdc;
boolean VlvAct_bInSpFuncIntlLoOutIdcInt;
boolean VLVACTINIF_bLihPosTimerOut;
boolean VLVACTINIF_bSwitchOutPrev;
boolean VLVACTINIF_bTimerInitPrev;
boolean VLVACTINIF_bTimerInputPrev;
boolean VLVACTINIF_bTimerOut;
boolean VLVACTINIF_bVcpiCamOffsetLndPrev;
sint8 VlvAct_agCkOpInVlvReqRef0;
sint8 VlvAct_agCkOpInVlvReqRef0Max;
sint8 VlvAct_agCkOpInVlvReqRef0Min;
uint8 VLVACTINIF_u8TimerCount;
sint16 VlvAct_agCkInCmOfs;
sint16 VlvAct_agCkInCmToothErr[VLVACT_AGCKINCMTOOTHERR_COLS];
sint16 VlvAct_agCkInCmToothOfs;
sint16 VlvAct_agCkInCmVlvActOfs;
sint16 VlvAct_agCkInExVlvDif;
uint16 VlvAct_agInSpFuncIntlThdHi;
uint16 VlvAct_agInSpFuncIntlThdLo;
uint16 VlvAct_prm_agCkOpInVlvMax[VLVACT_PRM_AGCKOPINVLVMAX_COLS];
uint16 VlvAct_tiDlyInhDiagPresScavOff;
uint16 VLVACTINIF_u16SlewRateOut;
uint16 Vxx_vvtc_in_angl_sp;
uint16 Vxx_vvtc_in_angl_sp_Int;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


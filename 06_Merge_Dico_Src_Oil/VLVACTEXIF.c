/***************************************************************************
;**
;** FILE NAME      : VLVACTEXIF.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTEXIF.H"
#include "VLVACTEXIF_L.H"
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
const boolean  VlvAct_bAcvVlvAgReqRef0Sat_C = 0;
const boolean  VlvAct_bExCmVlvActOfsEna_C = 0;
const boolean  VlvAct_bExSelDefPos_C = 0;
const boolean  Vxx_vvtc_ex_angl_test_bed = 0;
const sint8  VlvAct_agCkClsExVlvReqRef0Max_C = 0;
const sint8  VlvAct_agCkClsExVlvReqRef0Min_C = 0;
const uint8  VlvAct_agExMaxSlopVlvSpPos_C = 0;
const uint8  VlvAct_agExMinSlopVlvSpPos_C = 0;
const uint8  VlvAct_tiExLihPosDly_C = 0;
const uint8  VLVACTEXIF_u8Inhib = 0;
const sint16  Ext_agCkClsExVlvEstimRef0_C = 0;
const sint16  VlvAct_agCkExCmRefOfs_C = 0;
const sint16  VlvAct_agCkExCmSpMax_C = 0;
const sint16  VlvAct_agCkExCmSpMin_C = 0;
const sint16  VlvAct_agCkExCmToothOfsMax_C = 0;
const uint16  VlvAct_agExLihPos_C = 0;
const uint16  VlvAct_agExSpFuncIntlThd_C = 0;
const uint16  VlvAct_agExSpFuncIntlThdHi_C = 0;
const uint16  VlvAct_agExSpFuncIntlThdHiHys_C = 0;
const uint16  VlvAct_agExSpFuncIntlThdHys_C = 0;
const uint16  VlvAct_agExSpFuncIntlThdHysInf_C = 0;
const uint16  VlvAct_agExSpFuncIntlThdLo_C = 0;
const uint16  VlvAct_agExSpFuncIntlThdLoHys_C = 0;
const uint16  VlvAct_agExSpFuncIntlThdMax_C = 0;
const uint16  VlvAct_agExSpFuncIntlThdMaxHys_C = 0;
const uint16  VlvAct_agExSpFuncIntThdMaxHys1_C = 0;
const uint16  Vxx_vvtc_ex_angl_sp_cal = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VlvAct_bCmdExServoLocLop;
boolean VlvAct_bExSpFuncIntlHiOutIdc;
boolean VlvAct_bExSpFuncIntlHiOutIdcInt;
boolean VlvAct_bExSpFuncIntlLoOutIdc;
boolean VlvAct_bExSpFuncIntlLoOutIdcInt;
boolean VLVACTEXIF_bLihPosTimerOut;
boolean VLVACTEXIF_bTimerInputPrev;
boolean VLVACTEXIF_bVcpeCamOffsetLndPrev;
sint8 VlvAct_agCkClsExVlvReqRef0;
sint8 VlvAct_agCkClsExVlvReqRef0Max;
sint8 VlvAct_agCkClsExVlvReqRef0Min;
uint8 VLVACTEXIF_u8TimerCount;
sint16 VlvAct_agCkExCmOfs;
sint16 VlvAct_agCkExCmToothErr[VLVACT_AGCKEXCMTOOTHERR_COLS];
sint16 VlvAct_agCkExCmToothOfs;
sint16 VlvAct_agCkExCmVlvActOfs;
uint16 VlvAct_agExSpFuncIntlThdHi;
uint16 VlvAct_agExSpFuncIntlThdLo;
uint16 VlvAct_prm_agCkClsExVlvMax[VLVACT_PRM_AGCKCLSEXVLVMAX_COLS];
uint16 VLVACTEXIF_u16SlewRateOut;
uint16 Vxx_vvtc_ex_angl_sp;
uint16 Vxx_vvtc_ex_angl_sp_Int;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


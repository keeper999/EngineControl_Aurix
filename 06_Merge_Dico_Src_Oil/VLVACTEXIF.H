/***************************************************************************
;**
;** FILE NAME      : VLVACTEXIF.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXIF_H
#define VLVACTEXIF_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_PRM_AGCKCLSEXVLVBOL_COLS        ( 4 )
#define VLVACT_PRM_AGCKCLSEXVLVMAX_COLS        ( 4 )

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

extern const boolean  VlvAct_bAcvVlvAgReqRef0Sat_C;
extern const boolean  VlvAct_bExCmVlvActOfsEna_C;
extern const boolean  VlvAct_bExSelDefPos_C;
extern const boolean  Vxx_vvtc_ex_angl_test_bed;
extern const sint8  VlvAct_agCkClsExVlvReqRef0Max_C;
extern const sint8  VlvAct_agCkClsExVlvReqRef0Min_C;
extern const uint8  VlvAct_agExMaxSlopVlvSpPos_C;
extern const uint8  VlvAct_agExMinSlopVlvSpPos_C;
extern const uint8  VlvAct_tiExLihPosDly_C;
extern const sint16  Ext_agCkClsExVlvEstimRef0_C;
extern const sint16  VlvAct_agCkExCmRefOfs_C;
extern const sint16  VlvAct_agCkExCmSpMax_C;
extern const sint16  VlvAct_agCkExCmSpMin_C;
extern const sint16  VlvAct_agCkExCmToothOfsMax_C;
extern const uint16  VlvAct_agExLihPos_C;
extern const uint16  VlvAct_agExSpFuncIntlThd_C;
extern const uint16  VlvAct_agExSpFuncIntlThdHi_C;
extern const uint16  VlvAct_agExSpFuncIntlThdHiHys_C;
extern const uint16  VlvAct_agExSpFuncIntlThdHys_C;
extern const uint16  VlvAct_agExSpFuncIntlThdHysInf_C;
extern const uint16  VlvAct_agExSpFuncIntlThdLo_C;
extern const uint16  VlvAct_agExSpFuncIntlThdLoHys_C;
extern const uint16  VlvAct_agExSpFuncIntlThdMax_C;
extern const uint16  VlvAct_agExSpFuncIntlThdMaxHys_C;
extern const uint16  VlvAct_agExSpFuncIntThdMaxHys1_C;
extern const uint16  Vxx_vvtc_ex_angl_sp_cal;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bCmdExServoLocLop;
extern boolean VlvAct_bExSpFuncIntlHiOutIdc;
extern boolean VlvAct_bExSpFuncIntlLoOutIdc;
extern sint8 VlvAct_agCkClsExVlvReqRef0;
extern sint8 VlvAct_agCkClsExVlvReqRef0Max;
extern sint8 VlvAct_agCkClsExVlvReqRef0Min;
extern sint16 VlvAct_agCkExCmVlvActOfs;
extern uint16 VlvAct_prm_agCkClsExVlvMax[VLVACT_PRM_AGCKCLSEXVLVMAX_COLS];
extern uint16 Vxx_vvtc_ex_angl_sp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveExCmToo_ExIf(void);
void VlvAct_EveRst_ExIf(void);
void VlvAct_SdlFast_ExIf_1(void);
void VlvAct_SdlFast_ExIf_2(void);


#endif /* VLVACTEXIF_H */

/*-------------------------------- end of file -------------------------------*/

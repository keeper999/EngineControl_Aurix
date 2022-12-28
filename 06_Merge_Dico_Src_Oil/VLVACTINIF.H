/***************************************************************************
;**
;** FILE NAME      : VLVACTINIF.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINIF_H
#define VLVACTINIF_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_AGCKINEXVLVDIF_T_COLS           ( 10 )
#define VLVACT_PINHDIAGPRESSCAVDIF_M_COLS      ( 10 )
#define VLVACT_PRM_AGCKOPINVLVBOL_COLS         ( 4 )
#define VLVACT_PRM_AGCKOPINVLVMAX_COLS         ( 4 )

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

extern const boolean  VlvAct_bInCmVlvActOfsEna_C;
extern const boolean  VlvAct_bInhDiagPresScavIdc_C;
extern const boolean  VlvAct_bInSelDefPos_C;
extern const boolean  Vxx_vvtc_in_angl_test_bed;
extern const sint8  VlvAct_agCkOpInVlvReqRef0Max_C;
extern const sint8  VlvAct_agCkOpInVlvReqRef0Min_C;
extern const uint8  VlvAct_agInMaxSlopVlvSpPos_C;
extern const uint8  VlvAct_agInMinSlopVlvSpPos_C;
extern const uint8  VlvAct_tiInLihPosDly_C;
extern const sint16  Ext_agCkOpInVlvEstimRef0Ini_C;
extern const sint16  VlvAct_agCkInCmRefOfs_C;
extern const sint16  VlvAct_agCkInCmToothOfsMax_C;
extern const uint16  VlvAct_agCkInCmSpMax_C;
extern const uint16  VlvAct_agCkInCmSpMin_C;
extern const uint16  VlvAct_agCkInExVlvDif_T[VLVACT_AGCKINEXVLVDIF_T_COLS];
extern const uint16  VlvAct_agInLihPos_C;
extern const uint16  VlvAct_agInSpFuncIntlThd_C;
extern const uint16  VlvAct_agInSpFuncIntlThdHi_C;
extern const uint16  VlvAct_agInSpFuncIntlThdHiHys_C;
extern const uint16  VlvAct_agInSpFuncIntlThdHys_C;
extern const uint16  VlvAct_agInSpFuncIntlThdHysInf_C;
extern const uint16  VlvAct_agInSpFuncIntlThdLo_C;
extern const uint16  VlvAct_agInSpFuncIntlThdLoHys_C;
extern const uint16  VlvAct_agInSpFuncIntlThdMax_C;
extern const uint16  VlvAct_agInSpFuncIntlThdMaxHys_C;
extern const uint16  VlvAct_agInSpFuncIntThdMaxHys1_C;
extern const uint16  VlvAct_pInhDiagPresScavDif_M[VLVACT_PINHDIAGPRESSCAVDIF_M_COLS];
extern const uint16  VlvAct_tiDlyInhDiagPresScavOff_C;
extern const uint16  Vxx_vvtc_in_angl_sp_cal;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bCmdInServoLocLop;
extern boolean VlvAct_bInSpFuncIntlHiOutIdc;
extern boolean VlvAct_bInSpFuncIntlLoOutIdc;
extern sint8 VlvAct_agCkOpInVlvReqRef0;
extern sint8 VlvAct_agCkOpInVlvReqRef0Max;
extern sint8 VlvAct_agCkOpInVlvReqRef0Min;
extern sint16 VlvAct_agCkInCmVlvActOfs;
extern uint16 VlvAct_prm_agCkOpInVlvMax[VLVACT_PRM_AGCKOPINVLVMAX_COLS];
extern uint16 Vxx_vvtc_in_angl_sp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveInCmToo_InIf(void);
void VlvAct_EveRst_InIf(void);
void VlvAct_SdlFast_InIf_1(void);
void VlvAct_SdlFast_InIf_2(void);
void VlvAct_SdlFast_InIf_3(void);


#endif /* VLVACTINIF_H */

/*-------------------------------- end of file -------------------------------*/

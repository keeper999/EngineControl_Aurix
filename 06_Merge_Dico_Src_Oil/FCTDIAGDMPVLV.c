/***************************************************************************
;**
;** FILE NAME      : FCTDIAGDMPVLV.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FCTDIAGDMPVLV.H"
#include "FCTDIAGDMPVLV_L.H"
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
const uint32  DmpVlv_tiAcvCntOscStuckCls_C = 0;
const uint8  DmpVlv_CoefPresStuckCls_C = 0;
const uint8  DmpVlv_ctThdDiagStuckCls_T[DMPVLV_CTTHDDIAGSTUCKCLS_T_COLS] = {0};
const uint8  DmpVlv_nbMaxOscStuckCls_C = 0;
const uint8  DmpVlv_tCo_A[DMPVLV_TCO_A_COLS] = {0};
const uint8  FCTDIAGDMPVLV_u8Inhib = 0;
const sint16  DmpVlv_pOfsOscStuckCls_C = 0;
const sint16  DmpVlv_pThdOscStuckCls_C = 0;
const sint16  DmpVlv_pUsThrCorReqOfst_C = 0;
const uint16  DmpVlv_GainFiltPresStuckCls_C = 0;
const uint16  DmpVlv_nEngMaxThd_T[DMPVLV_NENGMAXTHD_T_COLS] = {0};
const uint16  DmpVlv_nEngMinThd_T[DMPVLV_NENGMINTHD_T_COLS] = {0};
const uint16  DmpVlv_pAirExtMes_A[DMPVLV_PAIREXTMES_A_COLS] = {0};
const uint16  DmpVlv_pAirInter_A[DMPVLV_PAIRINTER_A_COLS] = {0};
const uint16  DmpVlv_pThdAcvDiagStuckCls_C = 0;
const uint16  DmpVlv_pThdBoostPres_M[DMPVLV_PTHDBOOSTPRES_M_LNS][DMPVLV_PTHDBOOSTPRES_M_COLS] = {0};
const uint16  DmpVlv_pUsThrCorServoErrThd_C = 0;
const uint16  DmpVlv_rThdCmdStuckCls_C = 0;
const uint16  DmpVlv_tiTrbActStuckCls_C = 0;
const uint16  DmpVlv_tiTrbActStuckOp_T[DMPVLV_TITRBACTSTUCKOP_T_COLS] = {0};
const uint16  DmpVlv_uBattMinStuckCls_C = 0;
const uint16  FctDiagDmpVlv_nEng_A[FCTDIAGDMPVLV_NENG_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean DmpVlv_bDgoStuckCls_DmpVlv;
boolean DmpVlv_bDgoStuckOp_DmpVlv;
boolean DmpVlv_bEndCntOscStuckCls;
boolean DmpVlv_bMonRunStuckCls_DmpVlv;
boolean DmpVlv_bMonRunStuckOp_DmpVlv;
boolean DmpVlv_bOscStuckCls;
boolean DmpVlv_bPresOscStuckCls;
boolean FCTDIAGDMPVLV_bOscStuckCls_prev;
boolean FCTDIAGDMPVLV_bPresOscStuck_prev;
boolean FCTDIAGDMPVLV_bTimeOut1;
boolean FCTDIAGDMPVLV_bTimeOut2;
boolean FCTDIAGDMPVLV_bTimer1Init_prev;
boolean FCTDIAGDMPVLV_bTimer2Init_prev;
boolean FCTDIAGDMPVLV_bTimer3Init_prev;
uint32 DmpVlv_tiAcvCntOscStuckCls;
uint32 FCTDIAGDMPVLV_u32FilterKMem;
uint8 DmpVlv_ctDiagStuckCls;
uint8 DmpVlv_ctPresOscStuckCls;
uint8 DmpVlv_ctThdDiagStuckCls;
sint16 DmpVlv_pDiagFiltStuckCls;
uint16 DmpVlv_pAirExtMesInter;
uint16 DmpVlv_pThdBoostPres;
uint16 DmpVlv_pThdBoostPresWgStuckOp;
uint16 DmpVlv_tiStuckCls;
uint16 DmpVlv_tiStuckOp;
uint16 FCTDIAGDMPVLV_u16FilterOutput;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


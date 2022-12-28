/***************************************************************************
;**
;** FILE NAME      : COES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "COES.H"
#include "COES_L.H"
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
const boolean  CoEs_bAcvClsCanPurgSTTEs_C = 0;
const boolean  CoEs_bAcvIgCutOffSTTEs_C = 0;
const boolean  CoEs_bAcvIgSysSTTEs_C = 0;
const boolean  CoEs_bAcvInjCutOffSTTEs_C = 0;
const boolean  CoEs_bAcvIntrCdnEngRun_C = 0;
const boolean  CoEs_bAcvIntrCdnNStall_C = 0;
const boolean  CoEs_bAcvIntrSTTEs_C = 0;
const boolean  CoEs_bAcvOilPmpSysSTTEs_C = 0;
const boolean  CoEs_bAcvThrSysSTTEs_C = 0;
const boolean  CoEs_bAcvVlvSysLockPosnSTTEs_C = 0;
const boolean  CoEs_bAcvVlvSysRiseSTTEs_C = 0;
const boolean  CoEs_bCdnExVlvLockPosn_C = 0;
const boolean  CoEs_bCdnInVlvLockPosn_C = 0;
const boolean  CoEs_bCfCdnIntrSTT_C = 0;
const boolean  CoEs_bCfNEngIntrSTTEs_C = 0;
const boolean  CoEs_bDeacCdnCanPurg_C = 0;
const uint8  CoEs_rCmdLimCanPurg_C = 0;
const uint8  CoEs_tCo_nLimIntr_A[COES_TCO_NLIMINTR_A_COLS] = {0};
const uint8  CoEs_tiCutIg_C = 0;
const uint8  CoEs_tiDlyVldNNull_C = 0;
const uint8  COES_u8Inhib = 0;
const uint16  CoEs_facFilNEngTth_C = 0;
const uint16  CoEs_nEndIntrSTTEs_T[COES_NENDINTRSTTES_T_COLS] = {0};
const uint16  CoEs_nLimIntrSTTEs_T[COES_NLIMINTRSTTES_T_COLS] = {0};
const uint16  CoEs_nLimLoIntrSTTEs_T[COES_NLIMLOINTRSTTES_T_COLS] = {0};
const uint16  CoEs_tiDlyCanPurgCls_C = 0;
const uint16  CoEs_tiDlyCmdCanPurgIntrSTTEs_C = 0;
const uint16  CoEs_tiDlyCmdVlvSysIntrSTTEs_C = 0;
const uint16  CoEs_tiDlyIntrSTTEsHiEngSpd_C = 0;
const uint16  CoEs_tiDlyIntrSTTEsLoEngSpd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 COES_stStopSeq;
boolean CoEs_bAcvClsCanPurgSTTEs;
boolean CoEs_bAcvIgCutOffSTTEs;
boolean CoEs_bAcvOilPmpSysSTTEs;
boolean CoEs_bAcvThrSysSTTEs;
boolean CoEs_bAcvVlvSysLockPosnSTTEs_MP;
boolean CoEs_bAcvVlvSysRiseSTTEs;
boolean CoEs_bCmdActrSTTEs;
boolean CoEs_bCndEngHiLim_MP;
boolean CoEs_bCndEngLoLim_MP;
boolean COES_bCoPTStEngRunPrev;
boolean CoEs_bCutActrSTTEs;
boolean CoEs_bCutOffIgSTTEs;
boolean COES_bCutOffSeqInterrupRS;
boolean CoEs_bDlyCanPurgCls;
boolean CoEs_bDlyCanPurgCls_MP;
boolean CoEs_bDlyEndIntrHiSpd_MP;
boolean CoEs_bDlyEndIntrLoSpd_MP;
boolean CoEs_bEndIntrCdnEngSpd_MP;
boolean CoEs_bEngStopReq;
boolean CoEs_bIntrSTTEs;
boolean CoEs_bIntrSTTEsHiEngSpdPrev;
boolean CoEs_bIntrSTTEsLoEngSpdPrev;
boolean CoEs_bPctlAcvClsCanPurgSTTEs;
boolean CoEs_bPctlAcvClsCanPurgSTTEs_MP;
boolean CoEs_bPctlAcvVlvSysLockPosnSTTEs;
boolean COES_btiDlyCanPurgClsPrev;
boolean CoEs_btiDlyCmdCanPurgIntSTTEPrev;
boolean CoEs_btiDlyCmdVlvSysIntrSTTEPrev;
boolean CoEs_bVlvSysLockPosn;
uint32 COES_u32FiltredEngTthClcFilMem;
uint8 CoEs_tiCutOffIg;
uint8 COES_u8CoStrtRStrtStEngStrtPrev;
uint16 CoEs_nEngTthClcFil;
uint16 COES_u16CoEs_nEngTthClcFilPrev;
uint16 COES_u16Counter_CoEs_bIntrSTTEs;
uint16 COES_u16TiDlyCanPurgCls;
uint16 COES_u16TiDlyCmdCanPurgIntrSTTEs;
uint16 COES_u16TiDlyCmdVlvSysIntrSTTEs;
uint16 COES_u16TiDlyIntrSTTEsHiEngSpd;
uint16 COES_u16TiDlyIntrSTTEsLoEngSpd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


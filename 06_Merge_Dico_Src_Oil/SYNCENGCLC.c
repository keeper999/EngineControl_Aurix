/***************************************************************************
;**
;** FILE NAME      : SYNCENGCLC.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SYNCENGCLC.H"
#include "SYNCENGCLC_L.H"
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
const sint8  Sync_MaxCorBody1_C = 0;
const sint8  Sync_MaxCorBody2_C = 0;
const sint8  Sync_MaxCorBody3_C = 0;
const sint8  Sync_MaxCorBody4_C = 0;
const sint8  Sync_MaxCorBody5_C = 0;
const uint8  Sync_no_GearLrnCornEngClc_C = 0;
const uint8  Sync_NrSampleMin_C = 0;
const uint8  Sync_ThdCorHys_C = 0;
const uint8  Sync_TiCutOffLrnCornEngClc_C = 0;
const uint8  SYNCENGCLC_u8Inhib = 0;
const sint16  Sync_tCo_LrnCornEngClc_C = 0;
const uint16  Sync_ThdMvCorMin_C = 0;
const uint16  Sync_ThdnEngClcMax_C = 0;
const uint16  Sync_ThdnEngClcMin_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 SYNCENGCLC_StAssignEngArea;
boolean Sync_bAckdMvCyl1ArAcv;
boolean Sync_bAckdMvCyl2ArAcv;
boolean Sync_bAckdMvCyl3ArAcv;
boolean Sync_bChgnoArAcvnEngClc;
boolean Sync_bCondLrnCornEngClc;
boolean Sync_bEndMemrnCycEng;
boolean Sync_bIdlSpdInsdArAcv;
boolean Sync_bLrnCorArAcv;
boolean Sync_bnEngInsdAr;
boolean Sync_bProtClcSum;
boolean SYNCENGCLC_bHysOut;
boolean SYNCENGCLC_bTimeOut;
boolean SYNCENGCLC_bTimeOutInit;
uint32 Sync_ct_SampleCyl1ArAcv;
uint32 Sync_ct_SampleCyl2ArAcv;
uint32 Sync_ct_SampleCyl3ArAcv;
uint32 Sync_nSumCyl1ArAcv;
uint32 Sync_nSumCyl1ArAcvPrev;
uint32 Sync_nSumCyl2ArAcv;
uint32 Sync_nSumCyl2ArAcvPrev;
uint32 Sync_nSumCyl3ArAcv;
uint32 Sync_nSumCyl3ArAcvPrev;
sint8 Sync_CorCyl1ArAcv;
sint8 Sync_CorCyl2ArAcv;
sint8 Sync_CorCyl3ArAcv;
sint8 Sync_nCorContnsCyl1;
sint8 Sync_nCorContnsCyl2;
sint8 Sync_nCorContnsCyl3;
sint8 Sync_nCorContnsCylCmb;
sint8 Sync_prm_nCorContnsCyl1[SYNC_PRM_NCORCONTNSCYL1_COLS];
sint8 Sync_prm_nCorContnsCyl2[SYNC_PRM_NCORCONTNSCYL2_COLS];
sint8 Sync_prm_nCorContnsCyl3[SYNC_PRM_NCORCONTNSCYL3_COLS];
uint8 Sync_ct_MemrnEngCyl;
uint8 Sync_ctTiCutOff;
uint8 Sync_no_ArAcvnEngClc;
uint8 Sync_no_BodyCorSatEngClc;
uint8 Sync_no_MemrArAcvnEngClc;
uint8 Sync_no_PrevMemrArAcvnEngClc;
uint8 Sync_prm_bnEngInsdAr[SYNC_PRM_BNENGINSDAR_COLS];
uint8 SYNCENGCLC_u8NoArAcvnEngClc;
uint8 SYNCENGCLC_u8NumberActiveZonPrev;
uint16 Sync_nCycEngMemrCyl1;
uint16 Sync_nCycEngMemrCyl2;
uint16 Sync_nCycEngMemrCyl3;
uint16 Sync_nMemrCyl1;
uint16 Sync_nMemrCyl2;
uint16 Sync_nMemrCyl3;
uint16 Sync_nMvAllCylArAcv;
uint16 Sync_nMvCyl1ArAcv;
uint16 Sync_nMvCyl2ArAcv;
uint16 Sync_nMvCyl3ArAcv;
uint16 Sync_prm_nThdnEngClc[SYNC_PRM_NTHDNENGCLC_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


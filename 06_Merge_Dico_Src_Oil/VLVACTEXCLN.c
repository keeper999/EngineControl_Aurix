/***************************************************************************
;**
;** FILE NAME      : VLVACTEXCLN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTEXCLN.H"
#include "VLVACTEXCLN_L.H"
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
const boolean  VlvAct_bExSelTypCmdProfTyp_C = 0;
const boolean  VlvAct_bInhExHealClnDoneCt_C = 0;
const boolean  VlvAct_bInhExNormClnDoneCt_C = 0;
const uint8  VlvAct_ctExFrstClnCycThd_C = 0;
const uint8  VlvAct_ctExHealClnDoneThd_C = 0;
const uint8  VlvAct_ctExNormClnDoneThd_C = 0;
const uint8  VlvAct_ExFrstClnCmd_M[VLVACT_EXFRSTCLNCMD_M_COLS] = {0};
const uint8  VlvAct_ExHealClnCmd_M[VLVACT_EXHEALCLNCMD_M_COLS] = {0};
const uint8  VlvAct_ExNormClnCmd_M[VLVACT_EXNORMCLNCMD_M_COLS] = {0};
const uint8  VlvAct_noHealClnActExDftThd_C = 0;
const uint8  VlvAct_tiExClnEndThd_C = 0;
const uint8  VlvAct_tiExFrstClnIdc_T[VLVACT_TIEXFRSTCLNIDC_T_COLS] = {0};
const uint8  VlvAct_tiExHealClnIdc_T[VLVACT_TIEXHEALCLNIDC_T_COLS] = {0};
const uint8  VlvAct_tiExNormClnIdc_T[VLVACT_TIEXNORMCLNIDC_T_COLS] = {0};
const uint8  VLVACTEXCLN_u8Inhib = 0;
const uint16  VlvAct_AgExHealClnErrThd_C = 0;
const uint16  VlvAct_AgExNormClnThd_C = 0;
const uint16  VlvAct_ExClnCmdMax_C = 0;
const uint16  VlvAct_ExClnCmdMin_C = 0;
const uint16  VlvAct_tiExHealClnMonErrDly_C = 0;
const uint16  VlvAct_tiExNormClnDly_C = 0;
const uint16  VlvAct_tiHealClnActExDly_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VlvAct_bAcvExHealCln;
boolean VlvAct_bDgoClnErrVlvActEx;
boolean VlvAct_bExFrstClnDone;
boolean VlvAct_bExFrstClnStReq;
boolean VlvAct_bExHealClnEnd;
boolean VlvAct_bExHealClnStFrstReq;
boolean VlvAct_bExHealClnStMonGlblReq;
boolean VlvAct_bExHealClnStMonReq;
boolean VlvAct_bExManClnEnaIdc;
boolean VlvAct_bExMngClnStReq;
boolean VlvAct_bExNormClnEnd;
boolean VlvAct_bExNormClnStReq;
boolean VlvAct_bMonRunClnErrVlvActEx;
boolean VLVACTEXCLN_bFrtErrCntRst_Prev;
boolean VLVACTEXCLN_bInitTimer1_Prev;
boolean VLVACTEXCLN_bInitTimer2_Prev;
boolean VLVACTEXCLN_bLocalCalcPrev;
boolean VLVACTEXCLN_bLocalComparePrev;
boolean VLVACTEXCLN_bManCleanVarUpPrev;
boolean VLVACTEXCLN_bRctClnVarUdtPrev;
boolean VLVACTEXCLN_bTimeout;
boolean VLVACTEXCLN_bTimeout1;
boolean VLVACTEXCLN_bTimeout2;
boolean VLVACTEXCLN_bTriggerPrev;
boolean VLVACTEXCLN_bVlAcvExHealCln_Prev;
boolean VLVACTEXCLN_bVlvActClnBeEnaPrev;
uint32 VLVACTEXCLN_u32TimerCount2;
uint8 VlvAct_ctExFrstClnCyc;
uint8 VlvAct_ctExHealClnDone;
uint8 VlvAct_CtExHealClnErr;
uint8 VlvAct_ctExNormClnDone;
uint8 VlvAct_tiExClnIdc;
uint8 VlvAct_tiExFrstClnIdc;
uint8 VlvAct_tiExHealClnIdc;
uint8 VlvAct_tiExNormClnIdc;
uint16 VlvAct_ExClnStCmd;
uint16 VlvAct_tiExHealClnMonErrDly;
uint16 VLVACTEXCLN_u16TimerCount;
uint16 VLVACTEXCLN_u16TimerCount1;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


/***************************************************************************
;**
;** FILE NAME      : VLVACTINCLN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTINCLN.H"
#include "VLVACTINCLN_L.H"
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
const boolean  VlvAct_bInhInHealClnDoneCt_C = 0;
const boolean  VlvAct_bInhInNormClnDoneCt_C = 0;
const boolean  VlvAct_bInSelTypCmdProfTyp_C = 0;
const uint8  VlvAct_ctInFrstClnCycThd_C = 0;
const uint8  VlvAct_ctInHealClnDoneThd_C = 0;
const uint8  VlvAct_ctInNormClnDoneThd_C = 0;
const uint8  VlvAct_InFrstClnCmd_M[VLVACT_INFRSTCLNCMD_M_COLS] = {0};
const uint8  VlvAct_InHealClnCmd_M[VLVACT_INHEALCLNCMD_M_COLS] = {0};
const uint8  VlvAct_InNormClnCmd_M[VLVACT_INNORMCLNCMD_M_COLS] = {0};
const uint8  VlvAct_noHealClnActInDftThd_C = 0;
const uint8  VlvAct_tiInClnEndThd_C = 0;
const uint8  VlvAct_tiInFrstClnIdc_T[VLVACT_TIINFRSTCLNIDC_T_COLS] = {0};
const uint8  VlvAct_tiInHealClnIdc_T[VLVACT_TIINHEALCLNIDC_T_COLS] = {0};
const uint8  VlvAct_tiInNormClnIdc_T[VLVACT_TIINNORMCLNIDC_T_COLS] = {0};
const uint8  VLVACTINCLN_u8Inhib = 0;
const uint16  VlvAct_AgInHealClnErrThd_C = 0;
const uint16  VlvAct_AgInNormClnThd_C = 0;
const uint16  VlvAct_InClnCmdMax_C = 0;
const uint16  VlvAct_InClnCmdMin_C = 0;
const uint16  VlvAct_tiHealClnActInDly_C = 0;
const uint16  VlvAct_tiInHealClnMonErrDly_C = 0;
const uint16  VlvAct_tiInNormClnDly_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VlvAct_bAcvInHealCln;
boolean VlvAct_bDgoClnErrVlvActIn;
boolean VlvAct_bInFrstClnDone;
boolean VlvAct_bInFrstClnStReq;
boolean VlvAct_bInHealClnEnd;
boolean VlvAct_bInHealClnStFrstReq;
boolean VlvAct_bInHealClnStMonGlblReq;
boolean VlvAct_bInHealClnStMonReq;
boolean VlvAct_bInManClnEnaIdc;
boolean VlvAct_bInMngClnStReq;
boolean VlvAct_bInNormClnEnd;
boolean VlvAct_bInNormClnStReq;
boolean VlvAct_bMonRunClnErrVlvActIn;
boolean VLVACTINCLN_bCompVcpiVlv_Prev;
boolean VLVACTINCLN_bFrtErrCntRst_Prev;
boolean VLVACTINCLN_bInitTimer1_Prev;
boolean VLVACTINCLN_bInitTimer2_Prev;
boolean VLVACTINCLN_bLocalCalcPrev;
boolean VLVACTINCLN_bLocalComparePrev;
boolean VLVACTINCLN_bManCleanVarUpPrev;
boolean VLVACTINCLN_bRctClnVarUdtPrev;
boolean VLVACTINCLN_bTimeout;
boolean VLVACTINCLN_bTimeout1;
boolean VLVACTINCLN_bTimeout2;
boolean VLVACTINCLN_bTriggerPrev;
boolean VLVACTINCLN_bVlAcvInHealCln_Prev;
boolean VLVACTINCLN_bVlvActClnBeEnaPrev;
uint32 VLVACTINCLN_u32TimerCount2;
uint8 VlvAct_ctInFrstClnCyc;
uint8 VlvAct_ctInHealClnDone;
uint8 VlvAct_CtInHealClnErr;
uint8 VlvAct_ctInNormClnDone;
uint8 VlvAct_tiInClnIdc;
uint8 VlvAct_tiInFrstClnIdc;
uint8 VlvAct_tiInHealClnIdc;
uint8 VlvAct_tiInNormClnIdc;
uint16 VlvAct_InClnStCmd;
uint16 VlvAct_tiInHealClnMonErrDly;
uint16 VLVACTINCLN_u16TimerCount;
uint16 VLVACTINCLN_u16TimerCount1;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


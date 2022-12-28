/***************************************************************************
;**
;** FILE NAME      : SPTMOD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SPTMOD.H"
#include "SPTMOD_L.H"
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
const boolean  TqSys_bBoostPresSelModSpt_C = 0;
const boolean  TqSys_bChaRegSelModSpt_C = 0;
const uint8  SPTMOD_u8Inhib = 0;
const uint8  TqSys_facAntiOscFilModSpt_C = 0;
const uint8  TqSys_facAntiOscModSpt_C = 0;
const uint8  TqSys_idxTqEfcModSptSel_C = 0;
const uint8  TqSys_noGearModSpt_A[TQSYS_NOGEARMODSPT_A_COLS] = {0};
const uint8  TqSys_rHystPrfNomModSpt_C = 0;
const uint8  TqSys_rPrfNomModSpt_T[TQSYS_RPRFNOMMODSPT_T_COLS] = {0};
const uint8  TqSys_spdHystIdlModSpt_C = 0;
const uint8  TqSys_tiDeltaFootOffFilModSpt_C = 0;
const uint8  TqSys_tiDeltaFootOffModSpt_C = 0;
const uint8  TqSys_tiFilTqEfcFilModSpt_M[TQSYS_TIFILTQEFCFILMODSPT_M_LNS][TQSYS_TIFILTQEFCFILMODSPT_M_COLS] = {0};
const uint8  TqSys_tiFilTqEfcModSpt_M[TQSYS_TIFILTQEFCMODSPT_M_LNS][TQSYS_TIFILTQEFCMODSPT_M_COLS] = {0};
const uint16  TqSys_nEngModSpt_A[TQSYS_NENGMODSPT_A_COLS] = {0};
const uint16  TqSys_pBoostMaxModSpt_T[TQSYS_PBOOSTMAXMODSPT_T_COLS] = {0};
const uint16  TqSys_pExtModSptY_A[TQSYS_PEXTMODSPTY_A_COLS] = {0};
const uint16  TqSys_pwrMaxModSpt_T[TQSYS_PWRMAXMODSPT_T_COLS] = {0};
const uint16  TqSys_rAccPFootOffModSpt_C = 0;
const uint16  TqSys_spdThdIdlModSpt_C = 0;
const uint16  TqSys_tqEfcMaxGBxModSpt_T[TQSYS_TQEFCMAXGBXMODSPT_T_COLS] = {0};
const uint16  TqSys_tqEfcMaxModSpt_T[TQSYS_TQEFCMAXMODSPT_T_COLS] = {0};
const uint16  TqSys_tqEfcMaxNomModSpt_M[TQSYS_TQEFCMAXNOMMODSPT_M_LNS][TQSYS_TQEFCMAXNOMMODSPT_M_COLS] = {0};
const uint16  TqSys_tqEfcMaxTrbOff_T[TQSYS_TQEFCMAXTRBOFF_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean SPTMOD_bExt_ModSptSwitch;
boolean SPTMOD_bHystOutput1;
boolean SPTMOD_bHystOutput2;
uint32 SPTMOD_u32TqEfcLimModSptFi1Rest1;
uint32 SPTMOD_u32TqEfcLimModSptFi1Rest2;
uint32 SPTMOD_u32TqEfcLimModSptFi2Rest1;
uint32 SPTMOD_u32TqEfcLimModSptFi2Rest2;
uint8 TqSys_rBoostPresClcModSpt;
uint8 TqSys_rBoostPresSndModSpt;
uint8 TqSys_rPwrEngClcModSpt;
uint8 TqSys_rPwrEngSndModSpt;
uint8 TqSys_rTqEfcClcModSpt;
uint8 TqSys_rTqEfcSndModSpt;
uint8 TqSys_stModSpt;
sint16 TqDem_tqEfcLimModSptFil1;
sint16 TqDem_tqEfcLimModSptFil2;
sint16 TqSys_tqEfcMaxNomModSpt;
sint16 TqSys_tqEfcModSpt;
uint16 TqSys_pBoostClcModSpt;
uint16 TqSys_pBoostSndModSpt;
uint16 TqSys_pwrEngClcModSpt;
uint16 TqSys_pwrEngSndModSpt;
uint16 TqSys_tqEfcClcModSpt;
uint16 TqSys_tqEfcSndModSpt;
sint32 SPTMOD_s32TqEfcLimModSptFi1Prev1;
sint32 SPTMOD_s32TqEfcLimModSptFi1Prev2;
sint32 SPTMOD_s32TqEfcLimModSptFi2Prev1;
sint32 SPTMOD_s32TqEfcLimModSptFi2Prev2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


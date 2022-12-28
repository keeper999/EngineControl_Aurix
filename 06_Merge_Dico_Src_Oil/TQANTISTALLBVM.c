/***************************************************************************
;**
;** FILE NAME      : TQANTISTALLBVM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQANTISTALLBVM.H"
#include "TQANTISTALLBVM_L.H"
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
const boolean  IdlSys_bAcvBrkCdnAntiStall_C = 0;
const boolean  IdlSys_bEnaAntiStall_C = 0;
const uint8  IdlSys_noTDCTestAntiStall_T[IDLSYS_NOTDCTESTANTISTALL_T_COLS] = {0};
const uint8  IdlSys_tiFilNGrdAntiStall_C = 0;
const uint8  IdlSys_tiInhAntiStall_C = 0;
const uint8  IdlSys_tiInhBrkAntiStall_T[IDLSYS_TIINHBRKANTISTALL_T_COLS] = {0};
const uint8  TQANTISTALLBVM_u8Inhib = 0;
const uint16  IdlSys_nGrdAntiStall_A[IDLSYS_NGRDANTISTALL_A_COLS] = {0};
const uint16  IdlSys_nOfsAcvAntiStall_M[IDLSYS_NOFSACVANTISTALL_M_LNS][IDLSYS_NOFSACVANTISTALL_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 TQANTISTALLBVM_stAcvAntiStall;
boolean IdlSys_bAcvAntiStallPrev;
boolean IdlSys_bAcvBrkAntiStall_MP;
boolean IdlSys_bDlyAuthAntiStall;
boolean IdlSys_bInhBrkAntiStall;
boolean IdlSys_bIniAntiStall;
boolean TQANTISTALLBVM_bTOffDlyAutInPrev;
boolean TQANTISTALLBVM_bTOffDlyBrkInPrev;
uint8 IdlSys_ctTestAcvAntiStall;
uint8 IdlSys_noTDCTestAntiStall;
sint16 IdlSys_nGrdAntiStall_MP;
uint16 IdlSys_nDifAcvAntiStall;
uint16 IdlSys_nOfsAcvAntiStall;
uint16 TQANTISTALLBVM_u16TOffDlyAuthCnt;
uint16 TQANTISTALLBVM_u16TOffDlyBrkCnt;
sint32 TQANTISTALLBVM_s32FilterMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


/***************************************************************************
;**
;** FILE NAME      : TQANTISTALLBVM_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQANTISTALLBVM_L_H
#define TQANTISTALLBVM_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st73 */
#define TQANTISTALLBVM_bINITIAL_STATE     0
#define TQANTISTALLBVM_bWAIT_ACTIV_STATE  1
#define TQANTISTALLBVM_bACTIV_STATE       2
/*extern uint8 TQANTISTALLBVM_stAcvAntiStall;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  TQANTISTALLBVM_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 TQANTISTALLBVM_stAcvAntiStall;
extern boolean IdlSys_bAcvAntiStallPrev;
extern boolean IdlSys_bAcvBrkAntiStall_MP;
extern boolean IdlSys_bDlyAuthAntiStall;
extern boolean IdlSys_bInhBrkAntiStall;
extern boolean IdlSys_bIniAntiStall;
extern boolean TQANTISTALLBVM_bTOffDlyAutInPrev;
extern boolean TQANTISTALLBVM_bTOffDlyBrkInPrev;
extern uint8 IdlSys_ctTestAcvAntiStall;
extern uint8 IdlSys_noTDCTestAntiStall;
extern sint16 IdlSys_nGrdAntiStall_MP;
extern uint16 IdlSys_nDifAcvAntiStall;
extern uint16 IdlSys_nOfsAcvAntiStall;
extern uint16 TQANTISTALLBVM_u16TOffDlyAuthCnt;
extern uint16 TQANTISTALLBVM_u16TOffDlyBrkCnt;
extern sint32 TQANTISTALLBVM_s32FilterMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQANTISTALLBVM_vidActivAntical(void);
void TQANTISTALLBVM_vidAnticalBVM(void);
void TQANTISTALLBVM_vidAutActAntiCal(void);
void TQANTISTALLBVM_vidConditionActiv(void);
void TQANTISTALLBVM_vidGestionAntical(void);
void TQANTISTALLBVM_vidInhibAntical(void);
void TQANTISTALLBVM_vidInitOutput(void);
void TQANTISTALLBVM_vidSeuilsActiv(void);
void TQANTISTALLBVM_vidSigActivFrein(void);


#endif /* TQANTISTALLBVM_L_H */

/*-------------------------------- end of file -------------------------------*/

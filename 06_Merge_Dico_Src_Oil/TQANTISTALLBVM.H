/***************************************************************************
;**
;** FILE NAME      : TQANTISTALLBVM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQANTISTALLBVM_H
#define TQANTISTALLBVM_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IDLSYS_NGRDANTISTALL_A_COLS            ( 12 )
#define IDLSYS_NOFSACVANTISTALL_M_LNS         ( 12 )
#define IDLSYS_NOFSACVANTISTALL_M_COLS         ( 8 )
#define IDLSYS_NOTDCTESTANTISTALL_T_COLS       ( 8 )
#define IDLSYS_TIINHBRKANTISTALL_T_COLS        ( 8 )

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

extern const boolean  IdlSys_bAcvBrkCdnAntiStall_C;
extern const boolean  IdlSys_bEnaAntiStall_C;
extern const uint8  IdlSys_noTDCTestAntiStall_T[IDLSYS_NOTDCTESTANTISTALL_T_COLS];
extern const uint8  IdlSys_tiFilNGrdAntiStall_C;
extern const uint8  IdlSys_tiInhAntiStall_C;
extern const uint8  IdlSys_tiInhBrkAntiStall_T[IDLSYS_TIINHBRKANTISTALL_T_COLS];
extern const uint16  IdlSys_nGrdAntiStall_A[IDLSYS_NGRDANTISTALL_A_COLS];
extern const uint16  IdlSys_nOfsAcvAntiStall_M[IDLSYS_NOFSACVANTISTALL_M_LNS][IDLSYS_NOFSACVANTISTALL_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IdlSys_EveSync_AntiStall(void);
void TQANTISTALLBVM_vidEntryInit(void);


#endif /* TQANTISTALLBVM_H */

/*-------------------------------- end of file -------------------------------*/

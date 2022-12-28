/***************************************************************************
;**
;** FILE NAME      : IDLCTRL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IDLCTRL_H
#define IDLCTRL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IDLSYS_FACDERIDLCTL1_M_LNS            ( 4 )
#define IDLSYS_FACDERIDLCTL1_M_COLS            ( 8 )
#define IDLSYS_FACDERIDLCTL2_M_LNS            ( 4 )
#define IDLSYS_FACDERIDLCTL2_M_COLS            ( 8 )
#define IDLSYS_FACDERIDLCTL3_M_LNS            ( 4 )
#define IDLSYS_FACDERIDLCTL3_M_COLS            ( 8 )
#define IDLSYS_FACDERIDLCTL4_M_LNS            ( 4 )
#define IDLSYS_FACDERIDLCTL4_M_COLS            ( 8 )
#define IDLSYS_FACFILIDLCTL1_M_LNS            ( 4 )
#define IDLSYS_FACFILIDLCTL1_M_COLS            ( 8 )
#define IDLSYS_FACFILIDLCTL2_M_LNS            ( 4 )
#define IDLSYS_FACFILIDLCTL2_M_COLS            ( 8 )
#define IDLSYS_FACFILIDLCTL3_M_LNS            ( 4 )
#define IDLSYS_FACFILIDLCTL3_M_COLS            ( 8 )
#define IDLSYS_FACFILIDLCTL4_M_LNS            ( 4 )
#define IDLSYS_FACFILIDLCTL4_M_COLS            ( 8 )
#define IDLSYS_FACINTIDLCTL1_M_LNS            ( 4 )
#define IDLSYS_FACINTIDLCTL1_M_COLS            ( 8 )
#define IDLSYS_FACINTIDLCTL2_M_LNS            ( 4 )
#define IDLSYS_FACINTIDLCTL2_M_COLS            ( 8 )
#define IDLSYS_FACINTIDLCTL3_M_LNS            ( 4 )
#define IDLSYS_FACINTIDLCTL3_M_COLS            ( 8 )
#define IDLSYS_FACINTIDLCTL4_M_LNS            ( 4 )
#define IDLSYS_FACINTIDLCTL4_M_COLS            ( 8 )
#define IDLSYS_FACPROPIDLCTL1_M_LNS           ( 4 )
#define IDLSYS_FACPROPIDLCTL1_M_COLS           ( 8 )
#define IDLSYS_FACPROPIDLCTL2_M_LNS           ( 4 )
#define IDLSYS_FACPROPIDLCTL2_M_COLS           ( 8 )
#define IDLSYS_FACPROPIDLCTL3_M_LNS           ( 4 )
#define IDLSYS_FACPROPIDLCTL3_M_COLS           ( 8 )
#define IDLSYS_FACPROPIDLCTL4_M_LNS           ( 4 )
#define IDLSYS_FACPROPIDLCTL4_M_COLS           ( 8 )
#define IDLSYS_NERRIDL_A_COLS                  ( 8 )
#define IDLSYS_NERRIDLCORLIM_A_COLS            ( 8 )
#define IDLSYS_NERRIDLPID_A_COLS               ( 8 )
#define IDLSYS_NERRIDLPID_M_LNS               ( 4 )
#define IDLSYS_NERRIDLPID_M_COLS               ( 8 )
#define IDLSYS_TIFILTQIDLAIR_M_LNS            ( 4 )
#define IDLSYS_TIFILTQIDLAIR_M_COLS            ( 8 )
#define IDLSYS_TIFILTQIDLAIRSPC_M_LNS         ( 4 )
#define IDLSYS_TIFILTQIDLAIRSPC_M_COLS         ( 8 )
#define IDLSYS_TQERRIDLAIR_A_COLS              ( 8 )
#define IDLSYS_TQIDLCORMAXBRK_M_LNS           ( 4 )
#define IDLSYS_TQIDLCORMAXBRK_M_COLS           ( 8 )
#define IDLSYS_TQIDLCORMAXNORM_M_LNS          ( 4 )
#define IDLSYS_TQIDLCORMAXNORM_M_COLS          ( 8 )

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

extern const boolean  IdlSys_bAcvSBPA_C;
extern const boolean  IdlSys_bSelNErrFac_C;
extern const uint8  IdlSys_noAvgNErr_C;
extern const sint16  IdlSys_tqDecMaxIdlCorMax_C;
extern const sint16  IdlSys_tqOfsIdlCorSatMin_C;
extern const uint16  IdlSys_facDerIdlCtl1_M[IDLSYS_FACDERIDLCTL1_M_LNS][IDLSYS_FACDERIDLCTL1_M_COLS];
extern const uint16  IdlSys_facDerIdlCtl2_M[IDLSYS_FACDERIDLCTL2_M_LNS][IDLSYS_FACDERIDLCTL2_M_COLS];
extern const uint16  IdlSys_facDerIdlCtl3_M[IDLSYS_FACDERIDLCTL3_M_LNS][IDLSYS_FACDERIDLCTL3_M_COLS];
extern const uint16  IdlSys_facDerIdlCtl4_M[IDLSYS_FACDERIDLCTL4_M_LNS][IDLSYS_FACDERIDLCTL4_M_COLS];
extern const uint16  IdlSys_facFilIdlCtl1_M[IDLSYS_FACFILIDLCTL1_M_LNS][IDLSYS_FACFILIDLCTL1_M_COLS];
extern const uint16  IdlSys_facFilIdlCtl2_M[IDLSYS_FACFILIDLCTL2_M_LNS][IDLSYS_FACFILIDLCTL2_M_COLS];
extern const uint16  IdlSys_facFilIdlCtl3_M[IDLSYS_FACFILIDLCTL3_M_LNS][IDLSYS_FACFILIDLCTL3_M_COLS];
extern const uint16  IdlSys_facFilIdlCtl4_M[IDLSYS_FACFILIDLCTL4_M_LNS][IDLSYS_FACFILIDLCTL4_M_COLS];
extern const uint16  IdlSys_facIntIdlCtl1_M[IDLSYS_FACINTIDLCTL1_M_LNS][IDLSYS_FACINTIDLCTL1_M_COLS];
extern const uint16  IdlSys_facIntIdlCtl2_M[IDLSYS_FACINTIDLCTL2_M_LNS][IDLSYS_FACINTIDLCTL2_M_COLS];
extern const uint16  IdlSys_facIntIdlCtl3_M[IDLSYS_FACINTIDLCTL3_M_LNS][IDLSYS_FACINTIDLCTL3_M_COLS];
extern const uint16  IdlSys_facIntIdlCtl4_M[IDLSYS_FACINTIDLCTL4_M_LNS][IDLSYS_FACINTIDLCTL4_M_COLS];
extern const uint16  IdlSys_facPropIdlCtl1_M[IDLSYS_FACPROPIDLCTL1_M_LNS][IDLSYS_FACPROPIDLCTL1_M_COLS];
extern const uint16  IdlSys_facPropIdlCtl2_M[IDLSYS_FACPROPIDLCTL2_M_LNS][IDLSYS_FACPROPIDLCTL2_M_COLS];
extern const uint16  IdlSys_facPropIdlCtl3_M[IDLSYS_FACPROPIDLCTL3_M_LNS][IDLSYS_FACPROPIDLCTL3_M_COLS];
extern const uint16  IdlSys_facPropIdlCtl4_M[IDLSYS_FACPROPIDLCTL4_M_LNS][IDLSYS_FACPROPIDLCTL4_M_COLS];
extern const uint16  IdlSys_nErrIdl_A[IDLSYS_NERRIDL_A_COLS];
extern const uint16  IdlSys_nErrIdlCorLim_A[IDLSYS_NERRIDLCORLIM_A_COLS];
extern const uint16  IdlSys_nErrIdlPID_A[IDLSYS_NERRIDLPID_A_COLS];
extern const uint16  IdlSys_nErrIdlPID_M[IDLSYS_NERRIDLPID_M_LNS][IDLSYS_NERRIDLPID_M_COLS];
extern const uint16  IdlSys_tiFilTqIdlAir_M[IDLSYS_TIFILTQIDLAIR_M_LNS][IDLSYS_TIFILTQIDLAIR_M_COLS];
extern const uint16  IdlSys_tiFilTqIdlAirSpc_M[IDLSYS_TIFILTQIDLAIRSPC_M_LNS][IDLSYS_TIFILTQIDLAIRSPC_M_COLS];
extern const uint16  IdlSys_tqErrIdlAir_A[IDLSYS_TQERRIDLAIR_A_COLS];
extern const uint16  IdlSys_tqIdlCorMaxBrk_M[IDLSYS_TQIDLCORMAXBRK_M_LNS][IDLSYS_TQIDLCORMAXBRK_M_COLS];
extern const uint16  IdlSys_tqIdlCorMaxNorm_M[IDLSYS_TQIDLCORMAXNORM_M_LNS][IDLSYS_TQIDLCORMAXNORM_M_COLS];
extern const uint16  IdlSys_tqIncMaxIdlCorMax_C;
extern const uint16  IdlSys_tqOfsIdlCorSatMax_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern sint16 IdlSys_tqIdcIdlNotSat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IDLCTRL_vidEntryInit(void);
void IdlSys_EveSync_tqIdcIdl(void);


#endif /* IDLCTRL_H */

/*-------------------------------- end of file -------------------------------*/

/***************************************************************************
;**
;** FILE NAME      : IDLCTRL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IDLCTRL.H"
#include "IDLCTRL_L.H"
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
const boolean  IdlSys_bAcvSBPA_C = 0;
const boolean  IdlSys_bSelNErrFac_C = 0;
const uint8  IDLCTRL_u8Inhib = 0;
const uint8  IdlSys_noAvgNErr_C = 0;
const sint16  IdlSys_tqDecMaxIdlCorMax_C = 0;
const sint16  IdlSys_tqOfsIdlCorSatMin_C = 0;
const uint16  IdlSys_facDerIdlCtl1_M[IDLSYS_FACDERIDLCTL1_M_LNS][IDLSYS_FACDERIDLCTL1_M_COLS] = {0};
const uint16  IdlSys_facDerIdlCtl2_M[IDLSYS_FACDERIDLCTL2_M_LNS][IDLSYS_FACDERIDLCTL2_M_COLS] = {0};
const uint16  IdlSys_facDerIdlCtl3_M[IDLSYS_FACDERIDLCTL3_M_LNS][IDLSYS_FACDERIDLCTL3_M_COLS] = {0};
const uint16  IdlSys_facDerIdlCtl4_M[IDLSYS_FACDERIDLCTL4_M_LNS][IDLSYS_FACDERIDLCTL4_M_COLS] = {0};
const uint16  IdlSys_facFilIdlCtl1_M[IDLSYS_FACFILIDLCTL1_M_LNS][IDLSYS_FACFILIDLCTL1_M_COLS] = {0};
const uint16  IdlSys_facFilIdlCtl2_M[IDLSYS_FACFILIDLCTL2_M_LNS][IDLSYS_FACFILIDLCTL2_M_COLS] = {0};
const uint16  IdlSys_facFilIdlCtl3_M[IDLSYS_FACFILIDLCTL3_M_LNS][IDLSYS_FACFILIDLCTL3_M_COLS] = {0};
const uint16  IdlSys_facFilIdlCtl4_M[IDLSYS_FACFILIDLCTL4_M_LNS][IDLSYS_FACFILIDLCTL4_M_COLS] = {0};
const uint16  IdlSys_facIntIdlCtl1_M[IDLSYS_FACINTIDLCTL1_M_LNS][IDLSYS_FACINTIDLCTL1_M_COLS] = {0};
const uint16  IdlSys_facIntIdlCtl2_M[IDLSYS_FACINTIDLCTL2_M_LNS][IDLSYS_FACINTIDLCTL2_M_COLS] = {0};
const uint16  IdlSys_facIntIdlCtl3_M[IDLSYS_FACINTIDLCTL3_M_LNS][IDLSYS_FACINTIDLCTL3_M_COLS] = {0};
const uint16  IdlSys_facIntIdlCtl4_M[IDLSYS_FACINTIDLCTL4_M_LNS][IDLSYS_FACINTIDLCTL4_M_COLS] = {0};
const uint16  IdlSys_facPropIdlCtl1_M[IDLSYS_FACPROPIDLCTL1_M_LNS][IDLSYS_FACPROPIDLCTL1_M_COLS] = {0};
const uint16  IdlSys_facPropIdlCtl2_M[IDLSYS_FACPROPIDLCTL2_M_LNS][IDLSYS_FACPROPIDLCTL2_M_COLS] = {0};
const uint16  IdlSys_facPropIdlCtl3_M[IDLSYS_FACPROPIDLCTL3_M_LNS][IDLSYS_FACPROPIDLCTL3_M_COLS] = {0};
const uint16  IdlSys_facPropIdlCtl4_M[IDLSYS_FACPROPIDLCTL4_M_LNS][IDLSYS_FACPROPIDLCTL4_M_COLS] = {0};
const uint16  IdlSys_nErrIdl_A[IDLSYS_NERRIDL_A_COLS] = {0};
const uint16  IdlSys_nErrIdlCorLim_A[IDLSYS_NERRIDLCORLIM_A_COLS] = {0};
const uint16  IdlSys_nErrIdlPID_A[IDLSYS_NERRIDLPID_A_COLS] = {0};
const uint16  IdlSys_nErrIdlPID_M[IDLSYS_NERRIDLPID_M_LNS][IDLSYS_NERRIDLPID_M_COLS] = {0};
const uint16  IdlSys_tiFilTqIdlAir_M[IDLSYS_TIFILTQIDLAIR_M_LNS][IDLSYS_TIFILTQIDLAIR_M_COLS] = {0};
const uint16  IdlSys_tiFilTqIdlAirSpc_M[IDLSYS_TIFILTQIDLAIRSPC_M_LNS][IDLSYS_TIFILTQIDLAIRSPC_M_COLS] = {0};
const uint16  IdlSys_tqErrIdlAir_A[IDLSYS_TQERRIDLAIR_A_COLS] = {0};
const uint16  IdlSys_tqIdlCorMaxBrk_M[IDLSYS_TQIDLCORMAXBRK_M_LNS][IDLSYS_TQIDLCORMAXBRK_M_COLS] = {0};
const uint16  IdlSys_tqIdlCorMaxNorm_M[IDLSYS_TQIDLCORMAXNORM_M_LNS][IDLSYS_TQIDLCORMAXNORM_M_COLS] = {0};
const uint16  IdlSys_tqIncMaxIdlCorMax_C = 0;
const uint16  IdlSys_tqOfsIdlCorSatMax_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IDLCTRL_bRstCalc;
uint8 IDLCTRL_u8Ind;
sint16 IDLCTRL_s16EngErrIdlCtlPrev;
sint16 IdlSys_nErrIdlCtl;
sint16 IdlSys_nErrIdlCtl1;
sint16 IdlSys_nErrIdlCtl2;
sint16 IdlSys_nErrIdlCtlPID;
sint16 IdlSys_tqIdcAirIdlRaw;
sint16 IdlSys_tqIdcIdlNotSat;
sint16 IdlSys_tqIdcIdlRaw;
sint16 IdlSys_tqIdcIdlSatMin;
sint16 IdlSys_tqIdlCorDer_MP;
sint16 IdlSys_tqIdlCorDerFil_MP;
sint16 IdlSys_tqIdlCorIni;
sint16 IdlSys_tqIdlCorInt_MP;
sint16 IdlSys_tqIdlCorMax;
sint16 IdlSys_tqIdlCorMin;
sint16 IdlSys_tqIdlCorPID;
sint16 IdlSys_tqIdlCorProp_MP;
sint16 IdlSys_tqIdlCorSatMin;
uint16 IDLCTRL_u16nErrIdlAir;
uint16 IDLCTRL_u16RatLimOutput;
uint16 IDLCTRL_u16TabSample[IDLCTRL_U16TABSAMPLE_COLS];
uint16 IDLCTRL_u16TqErrIdlAir;
uint16 IdlSys_facDerIdlCtl;
uint16 IdlSys_facFilIdlCtl;
uint16 IdlSys_facIntIdlCtl;
uint16 IdlSys_facPropIdlCtl;
uint16 IdlSys_tiFilTqIdlAir_MP;
sint32 IDLCTRL_s32TqIdcAirIdlRawFiltMem;
sint32 IDLCTRL_s32TqIdlCor;
sint32 IdlSys_tqIdlCor;
sint32 IdlSys_tqIdlCorNotSat_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


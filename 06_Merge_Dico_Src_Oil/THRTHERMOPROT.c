/***************************************************************************
;**
;** FILE NAME      : THRTHERMOPROT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRTHERMOPROT.H"
#include "THRTHERMOPROT_L.H"
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
const boolean  Thr_bAcvCdnCll_thermoProt_C = 0;
const boolean  Thr_bAcvCdnLih_thermoProt_C = 0;
const boolean  Thr_bAcvCdnLrn_thermoProt_C = 0;
const boolean  Thr_bAcvCdnSp_thermoProt_C = 0;
const boolean  Thr_bTypDiagThermoProt_C = 0;
const uint8  Thr_tiDlyCfmOvldThermoThr_C = 0;
const uint8  THRTHERMOPROT_u8Inhib = 0;
const uint16  Thr_acvSpThd_ThermoProt_C = 0;
const uint16  Thr_dlyAcvCll_thermoProt_C = 0;
const uint16  Thr_facFilUCmd_C = 0;
const uint16  Thr_facGrd_C = 0;
const uint16  Thr_facPwr_C = 0;
const uint16  Thr_tEngThd_C = 0;
const sint32  Thr_uCmdThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Thr_bCdnCll_thermoProt;
boolean Thr_bCdnLih_thermoProt;
boolean Thr_bCdnSpThd_thermoProt;
boolean Thr_bCdnStopLrn_thermoProt;
boolean Thr_bDgoOvldThermoThr;
boolean Thr_bMonRunOvldThermoThr;
boolean THRTHERMOPROT_bDlyCfmOvldThrPrev;
boolean THRTHERMOPROT_bThermoThrTimeOut;
boolean THRTHERMOPROT_bTpacOpenLpCtrPrev;
uint32 Thr_tEngEstim;
uint8 THRTHERMOPROT_u8ThrDlCfmOvldThr;
sint16 Thr_tEngGrd;
sint16 Thr_uCmdFil;
uint16 THRTHERMOPROT_u16ThrthermoProt;
sint32 THRTHERMOPROT_s32ThruCmdFilMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


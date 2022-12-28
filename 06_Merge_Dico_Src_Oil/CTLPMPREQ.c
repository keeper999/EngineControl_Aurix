/***************************************************************************
;**
;** FILE NAME      : CTLPMPREQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CTLPMPREQ.H"
#include "CTLPMPREQ_L.H"
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
const boolean  Ext_bAcv_OilPmp_rCtlBattCor_C = 0;
const boolean  OilSysHw_bSelCmdFreq_C = 0;
const uint8  CTLPMPREQ_u8Inhib = 0;
const uint8  Ext_uBattMes_Nom = 0;
const uint8  OilSysHw_iMesOilPmpGain_C = 0;
const uint16  OilSysHw_CtlPmpReq_CmdFreq_C = 0;
const uint16  OilSysHw_CtlPmpReq_DrvMax_C = 0;
const uint16  OilSysHw_CtlPmpReq_DrvMin_C = 0;
const uint16  OilSysHw_frqBaseFrqPmpCmd_T[OILSYSHW_FRQBASEFRQPMPCMD_T_COLS] = {0};
const uint16  OilSysHw_frqOfsThdDZone1_C = 0;
const uint16  OilSysHw_frqOfsThdDZone2_C = 0;
const uint16  OilSysHw_frqRetDZone1_C = 0;
const uint16  OilSysHw_frqRetDZone2_C = 0;
const uint16  OilSysHw_frqThdDZone1_C = 0;
const uint16  OilSysHw_frqThdDZone2_C = 0;
const uint16  OilSysHw_nEngOfsThdZone1_C = 0;
const uint16  OilSysHw_nEngThdZone1_C = 0;
const uint16  OilSysHw_tOil_frqPmpCmd_A[OILSYSHW_TOIL_FRQPMPCMD_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CTLPMPREQ_bHysteresis1Output;
boolean CTLPMPREQ_bHysteresis2Output;
boolean CTLPMPREQ_bHysteresis3Output;
boolean OilSysHw_bDgoOc_CtlPmpReq;
boolean OilSysHw_bDgoScg_CtlPmpReq;
boolean OilSysHw_bDgoScp_CtlPmpReq;
boolean OilSysHw_bMonRunOc_CtlPmpReq;
boolean OilSysHw_bMonRunScg_CtlPmpReq;
boolean OilSysHw_bMonRunScp_CtlPmpReq;
uint32 CTLPMPREQ_u32ExtIMesOilPmpMEM;
uint8 Ext_uBattMes_Fil;
uint8 OilSysHw_noFacFrqCmdOilPmp;
sint16 CTLPMPREQ_s16ExtUBattMesPrev;
uint16 Ext_iMesOilPmp;
uint16 Ext_iMesOilPmp_Prev;
uint16 OilSys_CtlPmpReq_Abs;
uint16 OilSysHw_CtlPmpReq;
uint16 OilSysHw_CtlPmpReq_Cor;
uint16 OilSysHw_CtlPmpReq_Drv;
uint16 OilSysHw_CtlPmpReq_Lim;
uint16 OilSysHw_frqBaseFrqPmpCmd;
uint16 OilSysHw_frqCmdFreqZone;
uint16 OilSysHw_frqInjFreq;
uint16 OilSysHw_frqPmpCmdRaw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


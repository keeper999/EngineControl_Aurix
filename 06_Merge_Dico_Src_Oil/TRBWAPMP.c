/***************************************************************************
;**
;** FILE NAME      : TRBWAPMP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TRBWAPMP.H"
#include "TRBWAPMP_L.H"
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
const boolean  Ext_bAcvCtlBattCor_TrbWaPmp_C = 0;
const boolean  TrbCoSysHw_bInvDuCy_C = 0;
const uint8  TrbWaPmp_TiInh_DiagEl_C = 0;
const uint8  TRBWAPMP_u8Inhib = 0;
const uint16  TrbCoSysHw_WaPmpReqFreq_C = 0;
const uint16  TrbCoSysHw_WaPmpReqMax_C = 0;
const uint16  TrbCoSysHw_WaPmpReqMin_C = 0;
const uint16  TrbCoSysHw_WaPmpReqMinDiagEl_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TrbCoSysHw_bDgoOc_TrbWaPmp;
boolean TrbCoSysHw_bDgoScg_TrbWaPmp;
boolean TrbCoSysHw_bDgoScp_TrbWaPmp;
boolean TrbCoSysHw_bMonRunOc_TrbWaPmp;
boolean TrbCoSysHw_bMonRunScg_TrbWaPmp;
boolean TrbCoSysHw_bMonRunScp_TrbWaPmp;
boolean TRBWAPMP_bInitDiagnosisTimerPRev;
boolean TrbWaPmp_bTiInh_DiagEl;
uint8 TRBWAPMP_u8Timer;
sint16 TRBWAPMP_s16ExtuBattMesPrev;
uint16 Ext_uBattMes_Filtered;
uint16 TrbCoSysHw_RcoTact;
uint16 TrbCoSysHw_rCtlWaPmpReq;
uint16 TrbCoSysHw_rCtlWaPmpReq_Abs;
uint16 TrbCoSysHw_rCtlWaPmpReq_Cnv;
uint16 TrbCoSysHw_rCtlWaPmpReq_Cor;
uint16 TrbCoSysHw_rCtlWaPmpReq_Drv;
uint16 TrbCoSysHw_rCtlWaPmpReq_Lim;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


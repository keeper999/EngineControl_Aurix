/***************************************************************************
;**
;** FILE NAME      : PROPFUPMP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PROPFUPMP.H"
#include "PROPFUPMP_L.H"
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
const uint8  Ext_stDftFuPmpRcv_C = 0;
const uint8  FuPmp_tiInhDiag_C = 0;
const uint8  PROPFUPMP_u8Inhib = 0;
const uint16  Ext_FlowFuTnkPmp_A[EXT_FLOWFUTNKPMP_A_COLS] = {0};
const uint16  Ext_FlowFuTnkPmp_T[EXT_FLOWFUTNKPMP_T_COLS] = {0};
const uint16  FuPmp_rFlowFuTnkPmpDft_C = 0;
const uint16  FuPmp_rFlowFuTnkPmpIni_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ctrl_bInhCmd_FuTnkPmp;
boolean FuPmp_bDgoFrq_PropFuPmp;
boolean FuPmp_bDgoGravScp_PropFuPmp;
boolean FuPmp_bDgoMap_PropFuPmp;
boolean FuPmp_bDgoOc_PropFuPmp;
boolean FuPmp_bDgoScg_PropFuPmp;
boolean FuPmp_bDgoScp_PropFuPmp;
boolean FuPmp_bMonRunFrq_PropFuPmp;
boolean FuPmp_bMonRunGravScp_PropFuPmp;
boolean FuPmp_bMonRunMap_PropFuPmp;
boolean FuPmp_bMonRunOc_PropFuPmp;
boolean FuPmp_bMonRunScg_PropFuPmp;
boolean FuPmp_bMonRunScp_PropFuPmp;
boolean PROPFUPMP_bPwrRly_rCtl_Prev;
boolean PROPFUPMP_bTimeout;
uint32 Ext_tiPerStFlowFuTnkPmp;
uint8 Ext_frqStFlowFuTnkPmp;
uint8 Ext_stDftFuTnkPmp;
uint8 Ext_stDftFuTnkPmpMem;
uint8 Ext_stFlowFuTnkPmp_Conv;
uint8 PROPFUPMP_u8TimerCpt;
uint16 Ext_rFlowFuTnkPmp;
uint16 Ext_rStFlowFuTnkPmp;
uint16 FuPmp_rFlowFuTnkPmp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


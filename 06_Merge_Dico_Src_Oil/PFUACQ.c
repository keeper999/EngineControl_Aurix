/***************************************************************************
;**
;** FILE NAME      : PFUACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PFUACQ.H"
#include "PFUACQ_L.H"
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
const uint8  PFUACQ_u8Inhib = 0;
const uint16  Ext_pFuMes_T[EXT_PFUMES_T_COLS] = {0};
const uint16  Ext_pFuMesSpl_T[EXT_PFUMESSPL_T_COLS] = {0};
const uint16  Ext_pFuMesWRV_C = 0;
const uint16  Ext_pFuRcv_C = 0;
const uint16  Ext_uDgoCoh_pFuMes_C = 0;
const uint16  Ext_uDgoScg_pFuMes_C = 0;
const uint16  Ext_uDgoScp_pFuMes_C = 0;
const uint16  PFuAcq_nEng_A[PFUACQ_NENG_A_COLS] = {0};
const uint16  PFuAcq_rFilGainPFuRailMes_T[PFUACQ_RFILGAINPFURAILMES_T_COLS] = {0};
const uint16  PFuAcq_rFilGainPFuRailSplMes_T[PFUACQ_RFILGAINPFURAILSPLMES_T_COLS] = {0};
const uint16  PFuAcq_uPFuMes_A[PFUACQ_UPFUMES_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoCoh_PFuAcq;
boolean Ext_bDgoScg_PFuAcq;
boolean Ext_bDgoScp_PFuAcq;
boolean Ext_bMonRunCoh_PFuAcq;
boolean Ext_bMonRunScg_PFuAcq;
boolean Ext_bMonRunScp_PFuAcq;
uint32 PFUACQ_u32RailFilt_Mem;
uint32 PFUACQ_u32RailSplFilt_Mem;
uint16 Ext_pFuMesWRV;
uint16 Ext_pFuRailMes;
uint16 Ext_pFuRailMesRef;
uint16 Ext_pFuRailSplMes;
uint16 Ext_upFuMesNorm;
uint16 Ext_upFuMesSplNorm;
uint16 PFuAcq_pFuRailFilt;
uint16 PFuAcq_pFuRailMes;
uint16 PFuAcq_pFuRailMesPrev;
uint16 PFuAcq_pFuRailMesRaw;
uint16 PFuAcq_pFuRailMesSplPrev;
uint16 PFuAcq_pFuRailSplFilt;
uint16 PFuAcq_pFuRailSplMes;
uint16 PFuAcq_pFuRailSplMesRaw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


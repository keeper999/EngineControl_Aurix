/***************************************************************************
;**
;** FILE NAME      : CLUPEDFREQACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CLUPEDFREQACQ.H"
#include "CLUPEDFREQACQ_L.H"
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
const uint8  Clu_nDecCpt_ScgPrssMes_C = 0;
const uint8  Clu_nDecCpt_ScpPrssMes_C = 0;
const uint8  Clu_nDownTranThd_ScgPrssMes_C = 0;
const uint8  Clu_nDownTranThd_ScpPrssMes_C = 0;
const uint8  Clu_nInitCpt_ScgPrssMes_C = 0;
const uint8  Clu_nInitCpt_ScpPrssMes_C = 0;
const uint8  Clu_nUpTranThd_ScgPrssMes_C = 0;
const uint8  Clu_nUpTranThd_ScpPrssMes_C = 0;
const uint8  CLUPEDFREQACQ_u8Inhib = 0;
const uint16  Clu_FEmbFreq_Max_C = 0;
const uint16  Clu_FEmbFreq_Min_C = 0;
const uint16  Clu_GradEmbFreqCrois_C = 0;
const uint16  Clu_GradEmbFreqDecrois_C = 0;
const uint16  Clu_PosPed_Map[CLU_POSPED_MAP_COLS] = {0};
const uint16  Clu_rCluPedPrssMesFault_C = 0;
const uint16  Clu_Rco_Bkpt[CLU_RCO_BKPT_COLS] = {0};
const uint16  Clu_RcoEmbFreq_Max_C = 0;
const uint16  Clu_RcoEmbFreq_Min_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CLUPEDFREQACQ_bFilSig_1;
boolean CLUPEDFREQACQ_bFilSig_2;
boolean CLUPEDFREQACQ_bScgrCluPedPrsMes;
boolean CLUPEDFREQACQ_bScprCluPedPrsMes;
boolean Ext_bDftSftyScg_rCluPedPrssMes;
boolean Ext_bDftSftyScp_rCluPedPrssMes;
boolean Ext_bDgoGrd_rCluPedPrssMes;
boolean Ext_bDgoORng_rCluPedPrssMes;
boolean Ext_bDgoScg_rCluPedPrssMes;
boolean Ext_bDgoScp_rCluPedPrssMes;
boolean Ext_bMonRunGrd_rCluPedPrssMes;
boolean Ext_bMonRunORng_rCluPedPrssMes;
boolean Ext_bMonRunScg_rCluPedPrssMes;
boolean Ext_bMonRunScp_rCluPedPrssMes;
uint8 CLUPEDFREQACQ_u8CntFilt_1;
uint8 CLUPEDFREQACQ_u8CntFilt_2;
uint8 Ext_ctDftSftyScg_rCluPedPrssMes;
uint8 Ext_ctDftSftyScp_rCluPedPrssMes;
uint16 Clu_perRateCluPedPrssMes;
uint16 Clu_rCluPedPrssLnrMes;
uint16 Clu_rCluPedPrssLnrMesPrev;
uint16 Clu_rCluPedPrssMem;
uint16 Ext_rCluPedPrssBrutMes;
uint16 Ext_rCluPedPrssMes;
uint16 Ext_rCluPedPrssMesPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


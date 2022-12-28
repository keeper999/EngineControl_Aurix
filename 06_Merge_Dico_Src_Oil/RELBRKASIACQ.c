/***************************************************************************
;**
;** FILE NAME      : RELBRKASIACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "RELBRKASIACQ.H"
#include "RELBRKASIACQ_L.H"
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
const uint8  AirPres_nDecCpt_ScgRelBrkAsi_C = 0;
const uint8  AirPres_nDecCpt_ScpRelBrkAsi_C = 0;
const uint8  AirPres_nDownTranThd_ScgRelAsi_C = 0;
const uint8  AirPres_nDownTranThd_ScpRelAsi_C = 0;
const uint8  AirPres_nInitCptConf_ScgRelAsi_C = 0;
const uint8  AirPres_nInitCptConf_ScpRelAsi_C = 0;
const uint8  AirPres_noAcvGrdDiag_C = 0;
const uint8  AirPres_nUpTranThd_ScgRelAsi_C = 0;
const uint8  AirPres_nUpTranThd_ScpRelAsi_C = 0;
const uint8  AirPres_pRelBrkAsi_T[AIRPRES_PRELBRKASI_T_COLS] = {0};
const uint8  Ext_pRelBrkAsiIni_C = 0;
const uint8  Ext_pRelBrkAsiRcv_C = 0;
const uint8  RELBRKASIACQ_u8Inhib = 0;
const uint16  AirPres_uRelBrkAsi_A[AIRPRES_URELBRKASI_A_COLS] = {0};
const uint16  Ext_facRelBrkAsiFilCoef_C = 0;
const uint16  Ext_uDgoGrd_pRelBrkAsi_C = 0;
const uint16  Ext_uDgoScg_pRelBrkAsi_C = 0;
const uint16  Ext_uDgoScp_pRelBrkAsi_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean AirPres_bDftSftyScg_pRelBrkAsi;
boolean AirPres_bDftSftyScp_pRelBrkAsi;
boolean Ext_bDgoGrd_pRelBrkAsi;
boolean Ext_bDgoScg_pRelBrkAsi;
boolean Ext_bDgoScp_pRelBrkAsi;
boolean Ext_bMonRunGrd_pRelBrkAsi;
boolean Ext_bMonRunScg_pRelBrkAsi;
boolean Ext_bMonRunScp_pRelBrkAsi;
boolean RELBRKASIACQ_bFilSig_1;
boolean RELBRKASIACQ_bFilSig_2;
boolean RELBRKASIACQ_bScg_pRelBrkAsi;
boolean RELBRKASIACQ_bScp_pRelBrkAsi;
uint32 RELBRKASIACQ_u32OutFilterMem;
uint8 AirPres_ctAcvGrdDiag;
uint8 AirPres_ctDftSftyScg_pRelBrkAsi;
uint8 AirPres_ctDftSftyScp_pRelBrkAsi;
uint8 Ext_pRelBrkAsiLnr;
uint8 Ext_pRelBrkAsiMem;
uint8 Ext_pRelBrkAsiMes;
uint8 Ext_pRelBrkAsiMesSI;
uint8 RELBRKASIACQ_u8CntFilt_1;
uint8 RELBRKASIACQ_u8CntFilt_2;
uint16 Ext_uRelBrkAsi;
uint16 Ext_uRelBrkAsiFil;
uint16 RELBRKASIACQ_u16ExtReBrAsiPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


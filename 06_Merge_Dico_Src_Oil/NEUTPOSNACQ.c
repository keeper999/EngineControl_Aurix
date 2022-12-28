/***************************************************************************
;**
;** FILE NAME      : NEUTPOSNACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "NEUTPOSNACQ.H"
#include "NEUTPOSNACQ_L.H"
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
const boolean  Ext_bNeutFault_C = 0;
const uint8  NeutPosnAcq_nDecCpt_ORng_C = 0;
const uint8  NeutPosnAcq_nDecCpt_Scg_C = 0;
const uint8  NeutPosnAcq_nDecCpt_Scp_C = 0;
const uint8  NeutPosnAcq_nDownTranThd_ORng_C = 0;
const uint8  NeutPosnAcq_nDownTranThd_Scg_C = 0;
const uint8  NeutPosnAcq_nDownTranThd_Scp_C = 0;
const uint8  NeutPosnAcq_nInitCptConf_ORng_C = 0;
const uint8  NeutPosnAcq_nInitCptConf_Scg_C = 0;
const uint8  NeutPosnAcq_nInitCptConf_Scp_C = 0;
const uint8  NeutPosnAcq_nUpTranThd_ORng_C = 0;
const uint8  NeutPosnAcq_nUpTranThd_Scg_C = 0;
const uint8  NeutPosnAcq_nUpTranThd_Scp_C = 0;
const uint8  NEUTPOSNACQ_u8Inhib = 0;
const uint16  Ext_frqMaxNeut_C = 0;
const uint16  Ext_frqMinNeut_C = 0;
const uint16  Ext_rDgoScg_bNeut_C = 0;
const uint16  Ext_rDgoScp_bNeut_C = 0;
const uint16  Ext_rThdNeut1_C = 0;
const uint16  Ext_rThdNeut2_C = 0;
const uint16  Ext_rThdNeut3_C = 0;
const uint16  Ext_rThdNeut4_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoORng_bNeut;
boolean Ext_bDgoScg_bNeut;
boolean Ext_bDgoScp_bNeut;
boolean Ext_bMonRunORng_bNeut;
boolean Ext_bMonRunScg_bNeut;
boolean Ext_bMonRunScp_bNeut;
boolean Ext_bNeutNom;
boolean NeutPosnAcq_bDftSftyORng_bNeut;
boolean NeutPosnAcq_bDftSftyScg_bNeut;
boolean NeutPosnAcq_bDftSftyScp_bNeut;
boolean NEUTPOSNACQ_bFilSig_1;
boolean NEUTPOSNACQ_bFilSig_2;
boolean NEUTPOSNACQ_bFilSig_3;
boolean NEUTPOSNACQ_bORng_bNeut;
boolean NEUTPOSNACQ_bScg_bNeut;
boolean NEUTPOSNACQ_bScp_bNeut;
uint8 Ext_tiPerNeut;
uint8 NeutPosnAcq_ctDftSftyORng_bNeut;
uint8 NeutPosnAcq_ctDftSftyScg_bNeut;
uint8 NeutPosnAcq_ctDftSftyScp_bNeut;
uint8 NEUTPOSNACQ_u8CntFilt_1;
uint8 NEUTPOSNACQ_u8CntFilt_2;
uint8 NEUTPOSNACQ_u8CntFilt_3;
uint16 Ext_PerNeut;
uint16 Ext_rNeut;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : SFTYMNGR                                                 */
/*                                                                            */
/* !Module         : SFTYMNGR                                                 */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : SFTYMNGR.C75                                             */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEMS                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SFTYMNGR/SFTYMNGR.c7v $*/
/* $Revision::   1.13     $$Author::   mbenfrad       $$Date::   21 May 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SFTYMNGR.h"
#include "SFTYMNGR_l.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st104 */
/*      NOMINAL_EM                       =  1 */
/*      DEFAUT_EM                        =  2 */
/*      IRV_EM                           =  3 */
/*      LADDER_EM                        =  4 */
/*uint8 SFTYMNGR_stDiagEMState;*/

/* enum st102 */
/*      NOMINAL_STT                      =  1 */
/*      DEFAUT_STT                       =  2 */
/*      IRV_STT                          =  3 */
/*      LADDER_STT                       =  4 */
/*uint8 SFTYMNGR_stDiagSTTState;*/

/* enum st101 */
/*      NOMINAL_VSCTL                    =  1 */
/*      DEFAUT_VSCTL                     =  2 */
/*      IRV_VSCTL                        =  3 */
/*      LADDER_VSCTL                     =  4 */
/*uint8 SFTYMNGR_stDiagVSCtlState;*/

/* enum st103 */
/*      KEYOFF                           =  1 */
/*      DEFAUT_INACTIF                   =  2 */
/*      DEFAUT_ACTIF                     =  3 */
/*      FIN_ESCALADE_DEFAUT_ACTIF        =  4 */
/*      FIN_ESCALADE_DEFAUT_INACTIF      =  5 */
/*uint8 SFTYMNGR_stEscaladeDefautsState;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
const boolean  SftyMgt_bEnaDftKeyOff_C = 0;
const boolean  SftyMgt_bInhDftAutChk_nEng_C = 0;
const boolean  SftyMgt_bInhDftEMEdge_C = 0;
const boolean  SftyMgt_bInhDftIpAutChkIni_C = 0;
const boolean  SftyMgt_bInhDftIpECU_nEng_C = 0;
const boolean  SftyMgt_bInhDftIpEM_C = 0;
const boolean  SftyMgt_bInhDftIpSTT_C = 0;
const boolean  SftyMgt_bInhDftIpVSCtl_C = 0;
const boolean  SftyMgt_bInhDftNomTest_C = 0;
const boolean  SftyMgt_bInhDftSatMem_C = 0;
const boolean  SftyMgt_bInhDftSTTEdge_C = 0;
const boolean  SftyMgt_bInhDftVSCtlEdge_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  SftyMgt_noSdlOnRstHw_C = 0;
const uint8  SftyMgt_noSdlOnRstSw_C = 0;
const uint8  SftyMgt_stDftLadd_T[SFTYMGT_STDFTLADD_T_COLS] = {0};
const uint8  SftyMgt_stEngStop_C = 0;
const uint8  SftyMgt_stLih_C = 0;
const uint8  SftyMgt_stNom_C = 0;
const uint8  SftyMgt_stRstHw_C = 0;
const uint8  SftyMgt_stRstSw_C = 0;
const uint8  SftyMgt_stSfty3EngStopReq_C = 0;
const uint8  SftyMgt_stSfty3RstHwReq_C = 0;
const uint8  SftyMgt_tiDlyInhDftIpECULadd_C = 0;
const uint8  SFTYMNGR_u8Inhib = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const uint16  SftyMgt_ctStopWrMemThd_C = 0;
const uint16  SftyMgt_nEngInhDftIpAutChkThd_C = 0;
const uint16  SftyMgt_nEngInhDftIpECUThd_C = 0;
const uint16  SftyMgt_spdVehAftsThd_C = 0;
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
boolean SftyMgt_bDftIpECUCord;
boolean SftyMgt_bDftIpEMLadd;
boolean SftyMgt_bDftIpEnaAutChkPrio;
boolean SftyMgt_bDftIpEnaECU;
boolean SftyMgt_bDftIpEnaEM;
boolean SftyMgt_bDftIpEnaSTT;
boolean SftyMgt_bDftIpEnaVSCtl;
boolean SftyMgt_bDftIpSTTLadd;
boolean SftyMgt_bDftIpVSCtlLadd;
boolean SftyMgt_bDgoIni;
boolean SftyMgt_bDgoIrvECU;
boolean SftyMgt_bDgoIrvECUTmp;
boolean SftyMgt_bDgoIrvEdgeECU;
boolean SftyMgt_bDgoIrvEdgeEM;
boolean SftyMgt_bDgoIrvEdgeSTT;
boolean SftyMgt_bDgoIrvEdgeVSCtl;
boolean SftyMgt_bDgoIrvEM;
boolean SftyMgt_bDgoIrvEMTmp;
boolean SftyMgt_bDgoIrvEngStop;
boolean SftyMgt_bDgoIrvSTT;
boolean SftyMgt_bDgoIrvSTTTmp;
boolean SftyMgt_bDgoIrvVSCtl;
boolean SftyMgt_bDgoIrvVSCtlTmp;
boolean SftyMgt_bDgoRvLih;
boolean SftyMgt_bDgoSatMem;
boolean SftyMgt_bDgoSatMemEveDft;
boolean SftyMgt_bDgoSatMemEveKeyOff;
boolean SftyMgt_bDgoSatMemEveSat;
boolean SftyMgt_bEnaWrMem;
boolean SftyMgt_bEveDftWrMem;
boolean SftyMgt_bEveDftWrMemEna;
boolean SftyMgt_bEveIniDftWrMemEna;
boolean SftyMgt_bEveIniEna;
boolean SftyMgt_bEveKeyOffWrMem;
boolean SftyMgt_bEveKeyOffWrMemEna;
boolean SftyMgt_bEveMemSat;
boolean SftyMgt_bEveWrMem;
boolean SftyMgt_bInhDftEdge;
boolean SftyMgt_bInhDftIpAutChkPrioNEng;
boolean SftyMgt_bInhDftIpECU_nEng;
boolean SftyMgt_bInhDftIpECULadd;
boolean SftyMgt_bInhSTT;
boolean SftyMgt_bKeyOffEdge;
boolean SftyMgt_bMonRunIrvECU;
boolean SftyMgt_bMonRunIrvEM;
boolean SftyMgt_bMonRunIrvEngStop;
boolean SftyMgt_bMonRunIrvSTT;
boolean SftyMgt_bMonRunIrvVSCtl;
boolean SftyMgt_bMonRunRvLih;
boolean SftyMgt_bPresentInitVar;
boolean SftyMgt_bRstHwReq;
boolean SftyMgt_bRstHwReqAnt;
boolean SftyMgt_bRstSwReq;
boolean SftyMgt_bRstSwReqAnt;
boolean SftyMgt_bSfty3EngStopReqEdge;
boolean SftyMgt_bSfty3RstHwReqEdge;
boolean SFTYMNGR_bExtKeyOffPrev;
boolean SFTYMNGR_bResetAutomate;
boolean SFTYMNGR_bRstHwReqAntPrev1;
boolean SFTYMNGR_bRstHwReqAntPrev2;
boolean SFTYMNGR_bRstHwReqAntPrev3;
boolean SFTYMNGR_bRstHwReqAntPrev4;
boolean SFTYMNGR_bRstSwReqAntPrev1;
boolean SFTYMNGR_bRstSwReqAntPrev2;
boolean SFTYMNGR_bRstSwReqAntPrev3;
boolean SFTYMNGR_bRstSwReqAntPrev4;
boolean SFTYMNGR_bSfty3RstHwReqPrev;
boolean SFTYMNGR_bSftyEngStopReqPrev;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
uint32 SftyMgt_prm_bDftHisEveDft[SFTYMGT_PRM_BDFTHISEVEDFT_COLS];
uint32 SftyMgt_prm_bDftHisEveDftAfts[SFTYMGT_PRM_BDFTHISEVEDFTAFTS_COLS];
uint32 SftyMgt_prm_bDftHisEveIniAfts[SFTYMGT_PRM_BDFTHISEVEINIAFTS_COLS];
uint32 SftyMgt_prm_bDftHisEveKeyOff[SFTYMGT_PRM_BDFTHISEVEKEYOFF_COLS];
uint32 SftyMgt_prm_bDftHisOld[SFTYMGT_PRM_BDFTHISOLD_COLS];
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
uint8 SftyMgt_ctDftLadd;
uint8 SftyMgt_ctDftLaddCord;
uint8 SftyMgt_ctDftLaddEveDft;
uint8 SftyMgt_ctDftLaddEveKeyOff;
uint8 SftyMgt_stDftLaddIp;
uint8 SFTYMNGR_u8ctDftLaddPrev;
uint8 SFTYMNGR_stDiagEMState;
uint8 SFTYMNGR_stDiagSTTState;
uint8 SFTYMNGR_stDiagVSCtlState;
uint8 SFTYMNGR_stEscaladeDefautsState;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
uint16 SftyMgt_ctWrMemEveDft;
uint16 SftyMgt_ctWrMemEveKeyOff;
uint16 SftyMgt_ctWrMemOld;
uint16 SftyMgt_prm_bDftHisAfts[SFTYMGT_PRM_BDFTHISAFTS_COLS];
uint16 SftyMgt_prm_bDftHisAfts1;
uint16 SftyMgt_prm_bDftHisAfts2;
uint16 SftyMgt_prm_bDftHisAfts3;
uint16 SftyMgt_prm_bDftHisAfts4;
uint16 SftyMgt_prm_bDftHisAfts5;
uint16 SftyMgt_prm_bDftHisAfts6;
uint16 SftyMgt_prm_bDftHisAfts7;
uint16 SftyMgt_prm_bDftHisAfts8;
uint16 SftyMgt_prm_bFrfEveDft[SFTYMGT_PRM_BFRFEVEDFT_COLS];
uint16 SftyMgt_prm_bFrfEveKeyOff[SFTYMGT_PRM_BFRFEVEKEYOFF_COLS];
uint16 SftyMgt_prm_bFrfOld[SFTYMGT_PRM_BFRFOLD_COLS];
uint16 SFTYMNGR_u16CntTurnOffDlySmpl;
uint16 SFTYMNGR_u16RstTurnOffDlySmpl;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


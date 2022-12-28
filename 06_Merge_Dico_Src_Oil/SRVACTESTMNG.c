/***************************************************************************
;**
;** FILE NAME      : SRVACTESTMNG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SRVACTESTMNG.H"
#include "SRVACTESTMNG_L.H"
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
const boolean  ActrTestMng_bInhCondAccPed = 0;
const boolean  Srv_bInhCohRespActrTstThr_C = 0;
const boolean  Srv_bInhFailStpActrTstThr_C = 0;
const uint8  SRVACTESTMNG_u8Inhib = 0;
const uint16  ActrTstMng_TiDlyNMot = 0;
const uint16  Afts_nTarIdlVlvActTest_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 ActrTstMng_stActrTst;
boolean ActrTestMng_bInhFRM;
boolean ActrTstMng_bCoh;
boolean ActrTstMng_bDftCmd;
boolean ActrTstMng_bDftCTP1;
boolean ActrTstMng_bDftCTP2;
boolean ActrTstMng_bDftEE;
boolean ActrTstMng_bDftInjrFlow;
boolean ActrTstMng_bDftPrailLeak;
boolean ActrTstMng_bDurtyVlv;
boolean ActrTstMng_bFlapBlockOp;
boolean ActrTstMng_bFlapFaild;
boolean ActrTstMng_bFlapStayOp;
boolean ActrTstMng_bFrq;
boolean ActrTstMng_bGavScp;
boolean ActrTstMng_bIntmCirc;
boolean ActrTstMng_bMap;
boolean ActrTstMng_bOc;
boolean ActrTstMng_bOcCTP2;
boolean ActrTstMng_bOcHiFan;
boolean ActrTstMng_bScg;
boolean ActrTstMng_bScgCTP2;
boolean ActrTstMng_bScgHiFan;
boolean ActrTstMng_bScp;
boolean ActrTstMng_bScpCTP2;
boolean ActrTstMng_bScpHiFan;
boolean ActrTstMng_bStuckVlv;
boolean ActrTstMng_bUsPlausFco;
boolean ActrTstMng_bUsPlausFld;
boolean ActrTstMng_TstCmpl;
boolean ActrTstMng_VvtDynPb;
boolean ActrTstMng_VvtStatPb;
boolean Afts_bAcvVlvActTest_nTarIdl;
boolean Srv_bActrTstCndClcd;
boolean Srv_bActrTstEna;
boolean Srv_bTestCdn;
boolean Srv_bTestCdnRunning;
boolean SRVACTESTMNG_ActrTstMng_TstCmpl;
boolean SRVACTESTMNG_bActrTstCmplPrev;
boolean SRVACTESTMNG_bActrTstCmplPrev1;
boolean SRVACTESTMNG_bB2HiSpdTstCmplPrev;
boolean SRVACTESTMNG_bB2loSpdTstCmplPrev;
boolean SRVACTESTMNG_bCoil1TstCmplPrev;
boolean SRVACTESTMNG_bCoil2TstCmplPrev;
boolean SRVACTESTMNG_bCoil3TstCmplPrev;
boolean SRVACTESTMNG_bCoil4TstCmplPrev;
boolean SRVACTESTMNG_bCtlPmpReqTstCmplPv;
boolean SRVACTESTMNG_bCTP_TstCmplPrev;
boolean SRVACTESTMNG_bCTstCmplPrev;
boolean SRVACTESTMNG_bDftacc_pedal;
boolean SRVACTESTMNG_bDftgear_box;
boolean SRVACTESTMNG_bDftGMVact;
boolean SRVACTESTMNG_bDftInjDone;
boolean SRVACTESTMNG_bDftpFu;
boolean SRVACTESTMNG_bDftPrailInc;
boolean SRVACTESTMNG_bDftPrailMax;
boolean SRVACTESTMNG_bDftReg_mot_Running;
boolean SRVACTESTMNG_bDftRegime_moteur;
boolean SRVACTESTMNG_bDfttCoMes;
boolean SRVACTESTMNG_bDftTstHPPmp;
boolean SRVACTESTMNG_bDftUbat;
boolean SRVACTESTMNG_bDftVehicle_speed;
boolean SRVACTESTMNG_bDsTstCmplPrev;
boolean SRVACTESTMNG_bECTTstCmplPrev;
boolean SRVACTESTMNG_bExActrTstSpEndPrev;
boolean SRVACTESTMNG_bFuTnkPmpTstCmplPv;
boolean SRVACTESTMNG_bInActrTstSpEndPrev;
boolean SRVACTESTMNG_bInj1TstCmplPrev;
boolean SRVACTESTMNG_bInj2TstCmplPrev;
boolean SRVACTESTMNG_bInj3TstCmplPrev;
boolean SRVACTESTMNG_bInj4TstCmplPrev;
boolean SRVACTESTMNG_bMeap_TstCmplPrev;
boolean SRVACTESTMNG_bOil_bBlowByPrev;
boolean SRVACTESTMNG_bPurgTstCmplPrev;
boolean SRVACTESTMNG_bSp_bActrTstPrev;
boolean SRVACTESTMNG_bSrvbActrTstDmdPrev;
boolean SRVACTESTMNG_bTestTrbTstCmplPv;
boolean SRVACTESTMNG_bThrTstCmplPrev;
boolean SRVACTESTMNG_bTimeOut;
boolean SRVACTESTMNG_bTrbWaPmpTstCmplPv;
boolean SRVACTESTMNG_bUsTstCmplPrev;
boolean SRVACTESTMNG_bVlvTstCmplPrev;
uint8 Srv_stActrTstFeedback;
uint8 Srv_stTestDftCdn;
uint8 SRVACTESTMNG_u8CodeTstActionPrev;
uint8 SRVACTESTMNG_u8SrvstAcTstStPrev;
uint16 Afts_nTarIdlVlvActTest;
uint16 SRVACTESTMNG_u16Timer;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


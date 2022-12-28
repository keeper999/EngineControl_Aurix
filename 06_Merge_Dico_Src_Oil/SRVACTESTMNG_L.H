/***************************************************************************
;**
;** FILE NAME      : SRVACTESTMNG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SRVACTESTMNG_L_H
#define SRVACTESTMNG_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ACTRTSTMNG_ACTRTST_DONE           3
#define ACTRTSTMNG_ACTRTST_PB             5
#define ACTRTSTMNG_ACTRTST_STOP           6

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st93 */
#define ACTRTSTMNG_ACTRTST_IDLE           1
#define ACTRTSTMNG_ACTRTST_IMPO           2
#define ACTRTSTMNG_ACTRTST_PROGS          4
/*extern uint8 ActrTstMng_stActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  SRVACTESTMNG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 ActrTstMng_stActrTst;
extern boolean ActrTstMng_bCoh;
extern boolean ActrTstMng_bDftCmd;
extern boolean ActrTstMng_bDftCTP1;
extern boolean ActrTstMng_bDftCTP2;
extern boolean ActrTstMng_bDftEE;
extern boolean ActrTstMng_bDftInjrFlow;
extern boolean ActrTstMng_bDftPrailLeak;
extern boolean ActrTstMng_bDurtyVlv;
extern boolean ActrTstMng_bFlapBlockOp;
extern boolean ActrTstMng_bFlapFaild;
extern boolean ActrTstMng_bFlapStayOp;
extern boolean ActrTstMng_bFrq;
extern boolean ActrTstMng_bGavScp;
extern boolean ActrTstMng_bIntmCirc;
extern boolean ActrTstMng_bMap;
extern boolean ActrTstMng_bOc;
extern boolean ActrTstMng_bOcCTP2;
extern boolean ActrTstMng_bOcHiFan;
extern boolean ActrTstMng_bScg;
extern boolean ActrTstMng_bScgCTP2;
extern boolean ActrTstMng_bScgHiFan;
extern boolean ActrTstMng_bScp;
extern boolean ActrTstMng_bScpCTP2;
extern boolean ActrTstMng_bScpHiFan;
extern boolean ActrTstMng_bStuckVlv;
extern boolean ActrTstMng_bUsPlausFco;
extern boolean ActrTstMng_bUsPlausFld;
extern boolean ActrTstMng_TstCmpl;
extern boolean ActrTstMng_VvtDynPb;
extern boolean ActrTstMng_VvtStatPb;
extern boolean Srv_bActrTstCndClcd;
extern boolean SRVACTESTMNG_ActrTstMng_TstCmpl;
extern boolean SRVACTESTMNG_bActrTstCmplPrev;
extern boolean SRVACTESTMNG_bActrTstCmplPrev1;
extern boolean SRVACTESTMNG_bB2HiSpdTstCmplPrev;
extern boolean SRVACTESTMNG_bB2loSpdTstCmplPrev;
extern boolean SRVACTESTMNG_bCoil1TstCmplPrev;
extern boolean SRVACTESTMNG_bCoil2TstCmplPrev;
extern boolean SRVACTESTMNG_bCoil3TstCmplPrev;
extern boolean SRVACTESTMNG_bCoil4TstCmplPrev;
extern boolean SRVACTESTMNG_bCtlPmpReqTstCmplPv;
extern boolean SRVACTESTMNG_bCTP_TstCmplPrev;
extern boolean SRVACTESTMNG_bCTstCmplPrev;
extern boolean SRVACTESTMNG_bDftacc_pedal;
extern boolean SRVACTESTMNG_bDftgear_box;
extern boolean SRVACTESTMNG_bDftGMVact;
extern boolean SRVACTESTMNG_bDftInjDone;
extern boolean SRVACTESTMNG_bDftpFu;
extern boolean SRVACTESTMNG_bDftPrailInc;
extern boolean SRVACTESTMNG_bDftPrailMax;
extern boolean SRVACTESTMNG_bDftReg_mot_Running;
extern boolean SRVACTESTMNG_bDftRegime_moteur;
extern boolean SRVACTESTMNG_bDfttCoMes;
extern boolean SRVACTESTMNG_bDftTstHPPmp;
extern boolean SRVACTESTMNG_bDftUbat;
extern boolean SRVACTESTMNG_bDftVehicle_speed;
extern boolean SRVACTESTMNG_bDsTstCmplPrev;
extern boolean SRVACTESTMNG_bECTTstCmplPrev;
extern boolean SRVACTESTMNG_bExActrTstSpEndPrev;
extern boolean SRVACTESTMNG_bFuTnkPmpTstCmplPv;
extern boolean SRVACTESTMNG_bInActrTstSpEndPrev;
extern boolean SRVACTESTMNG_bInj1TstCmplPrev;
extern boolean SRVACTESTMNG_bInj2TstCmplPrev;
extern boolean SRVACTESTMNG_bInj3TstCmplPrev;
extern boolean SRVACTESTMNG_bInj4TstCmplPrev;
extern boolean SRVACTESTMNG_bMeap_TstCmplPrev;
extern boolean SRVACTESTMNG_bOil_bBlowByPrev;
extern boolean SRVACTESTMNG_bPurgTstCmplPrev;
extern boolean SRVACTESTMNG_bSp_bActrTstPrev;
extern boolean SRVACTESTMNG_bSrvbActrTstDmdPrev;
extern boolean SRVACTESTMNG_bTestTrbTstCmplPv;
extern boolean SRVACTESTMNG_bThrTstCmplPrev;
extern boolean SRVACTESTMNG_bTimeOut;
extern boolean SRVACTESTMNG_bTrbWaPmpTstCmplPv;
extern boolean SRVACTESTMNG_bUsTstCmplPrev;
extern boolean SRVACTESTMNG_bVlvTstCmplPrev;
extern uint8 SRVACTESTMNG_u8CodeTstActionPrev;
extern uint8 SRVACTESTMNG_u8SrvstAcTstStPrev;
extern uint16 SRVACTESTMNG_u16Timer;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SRVACTESTMNG_CtlPmpReq(void);
void SRVACTESTMNG_HPPmpTst(void);
void SRVACTESTMNG_PropFuPmp(void);
void SRVACTESTMNG_ThMgtECTTst(void);
void SRVACTESTMNG_vidActrTst1Res(void);
void SRVACTESTMNG_vidActrTst2Res(void);
void SRVACTESTMNG_vidActrTst3Res(void);
void SRVACTESTMNG_vidActrTst4Res(void);
void SRVACTESTMNG_vidActrTstAcvChart(void);
void SRVACTESTMNG_vidActrTstCdn(void);
void SRVACTESTMNG_vidActrTstCmpfollow(void);
void SRVACTESTMNG_vidActrTstCmpl(void);
void SRVACTESTMNG_vidActrTstRes(void);
void SRVACTESTMNG_vidB2FanHiSpdTst(void);
void SRVACTESTMNG_vidB2FanLoSpdTst(void);
void SRVACTESTMNG_vidBlowBy1(void);
void SRVACTESTMNG_vidBlowBy2(void);
void SRVACTESTMNG_vidCFanTst(void);
void SRVACTESTMNG_vidCoil_1Tst(void);
void SRVACTESTMNG_vidCoil_2Tst(void);
void SRVACTESTMNG_vidCoil_3Tst(void);
void SRVACTESTMNG_vidCoil_4Tst(void);
void SRVACTESTMNG_vidCstrTst(void);
void SRVACTESTMNG_vidCTPtst(void);
void SRVACTESTMNG_vidDumpValveTst(void);
void SRVACTESTMNG_vidExVVTTst(void);
void SRVACTESTMNG_vidFarSpTst(void);
void SRVACTESTMNG_vidHeatSenO2DsTst(void);
void SRVACTESTMNG_vidHeatSenO2UsTst(void);
void SRVACTESTMNG_vidInitOutput(void);
void SRVACTESTMNG_vidInj1Tst(void);
void SRVACTESTMNG_vidInj2Tst(void);
void SRVACTESTMNG_vidInj3Tst(void);
void SRVACTESTMNG_vidInj4Tst(void);
void SRVACTESTMNG_vidInVVTTst(void);
void SRVACTESTMNG_vidMEAPtst(void);
void SRVACTESTMNG_vidPwrRlyTst(void);
void SRVACTESTMNG_vidTestDftCdn(void);
void SRVACTESTMNG_vidTestDftCdnRun(void);
void SRVACTESTMNG_vidThMgt(void);
void SRVACTESTMNG_vidThrTst(void);
void SRVACTESTMNG_vidTstCdnClcn(void);
void SRVACTESTMNG_WgcCmd(void);


#endif /* SRVACTESTMNG_L_H */

/*-------------------------------- end of file -------------------------------*/

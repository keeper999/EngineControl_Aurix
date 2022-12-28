/***************************************************************************
;**
;** FILE NAME      : COFANCMDDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COFANCMDDIAG_L_H
#define COFANCMDDIAG_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st59 */
#define COFAN_INIT                        1
#define COFANB1_VNULLE                    2
#define COFANB1_ATTENTE                   3
#define COFANB1_GV                        4
#define COFANB2_VNULLE                    5
#define COFANB2_ATTENTE                   6
#define COFANB2_PV                        7
#define COFANB2_GV                        8
#define COFANC_INIT                       9
#define COFANC_RO                         10
#define COFANC_RFAO                       11
#define COFANC_GMVP                       12
#define COFANC_RFGMVP                     13
#define COFANC_RF                         14
#define COFANB1_DEFAUT                    15
#define COFANB2_DEFAUT                    16
#define COFANC_DEFAUT                     17
/*extern uint8 CoFan_stAcvCoFanCmd;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  COFANCMDDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 CoFan_stAcvCoFanCmd;
extern boolean CoFan_bAcvCoFan1Cmd;
extern boolean CoFan_bAcvCoFan2Cmd;
extern boolean CoFan_bDCDftStFanC;
extern boolean CoFan_bDgoClsdRly_StFanC;
extern boolean CoFan_bDgoCoh_StFanB1;
extern boolean CoFan_bDgoCoh_StFanB2HiSpd;
extern boolean CoFan_bDgoCoh_StFanB2LoSpd;
extern boolean CoFan_bDgoCoh_StFanB2NoSpd;
extern boolean CoFan_bDgoCritSc_StFanC;
extern boolean CoFan_bDgoECI_StFanC;
extern boolean CoFan_bDgoEl_StFanC;
extern boolean CoFan_bDgoHi_DrvrFan1;
extern boolean CoFan_bDgoHi_DrvrFan2;
extern boolean CoFan_bDgoLo_DrvrFan1;
extern boolean CoFan_bDgoLo_DrvrFan2;
extern boolean CoFan_bDgoOc_DrvrFan1;
extern boolean CoFan_bDgoOc_DrvrFan2;
extern boolean CoFan_bDgoUnVld_StFanC;
extern boolean CoFan_bFanB2HiSpd2;
extern boolean CoFan_bMonRunClsdRly_StFanC;
extern boolean CoFan_bMonRunCoh_StFanB1;
extern boolean CoFan_bMonRunCoh_StFanB2HiSpd;
extern boolean CoFan_bMonRunCoh_StFanB2LoSpd;
extern boolean CoFan_bMonRunCoh_StFanB2NoSpd;
extern boolean CoFan_bMonRunCritSc_StFanC;
extern boolean CoFan_bMonRunECI_StFanC;
extern boolean CoFan_bMonRunEl_StFanC;
extern boolean CoFan_bMonRunHi_DrvrFan1;
extern boolean CoFan_bMonRunHi_DrvrFan2;
extern boolean CoFan_bMonRunLo_DrvrFan1;
extern boolean CoFan_bMonRunLo_DrvrFan2;
extern boolean CoFan_bMonRunOc_DrvrFan1;
extern boolean CoFan_bMonRunOc_DrvrFan2;
extern boolean CoFan_bMonRunUnVld_StFanC;
extern boolean COFANCMDDIAG_bDgoEl_DrvrFan2;
extern boolean COFANCMDDIAG_bDgoHiDrvrFan1;
extern boolean COFANCMDDIAG_bDgoHiDrvrFan2;
extern boolean COFANCMDDIAG_bFaultGround1;
extern boolean COFANCMDDIAG_bFaultGround2;
extern boolean COFANCMDDIAG_bFaultOpen1;
extern boolean COFANCMDDIAG_bFaultOpen2;
extern boolean COFANCMDDIAG_bLocalCoFan1Cmdprev;
extern boolean COFANCMDDIAG_bLocalCoFan2Cmdprev;
extern boolean COFANCMDDIAG_bLocalInpTimer1prev;
extern boolean COFANCMDDIAG_bLocalInpTimer2prev;
extern boolean COFANCMDDIAG_bLocalInpTimer5prev;
extern boolean COFANCMDDIAG_bMonRunCoFan;
extern boolean COFANCMDDIAG_bMonRunCoh_B2NoSpd;
extern boolean COFANCMDDIAG_bMonRunCoh_Output;
extern boolean COFANCMDDIAG_bMonRunCoh_StFanB1;
extern boolean COFANCMDDIAG_bMonRunCoh_StFanB2;
extern boolean COFANCMDDIAG_bNoMaxThdPrev;
extern boolean COFANCMDDIAG_bNoRecThdPrev;
extern boolean COFANCMDDIAG_bNoThdPrev;
extern boolean COFANCMDDIAG_bStFanCPrev;
extern uint8 CoFan_rRCOFanC;
extern uint8 CoFan_rSpdFanCReqFil;
extern uint8 CoFan_rSpdFanPred;
extern uint8 COFANCMDDIAG_u8LocalCount;
extern uint8 COFANCMDDIAG_u8LocalcountTimer1;
extern uint8 COFANCMDDIAG_u8LocalcountTimer2;
extern uint8 COFANCMDDIAG_u8LocalcountTimer3;
extern uint8 COFANCMDDIAG_u8LocalcountTimer4;
extern uint8 COFANCMDDIAG_u8LocalcountTimer5;
extern uint8 COFANCMDDIAG_u8SchmitOutput1;
extern uint16 CoFan_ctDftStFanC;
extern uint16 CoFan_rAcvCoFan1Cmd;
extern uint16 CoFan_tiDlyTranActrProt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void COFANCMDDIAG_vidCoFan1Cmd(void);
void COFANCMDDIAG_vidCoFan1CmdFricC(void);
void COFANCMDDIAG_vidCofanB2_DEFAUT(void);
void COFANCMDDIAG_vidCofanB2_GVTran(void);
void COFANCMDDIAG_vidCofanB2_PVTran(void);
void COFANCMDDIAG_vidCofanB2VNullTran(void);
void COFANCMDDIAG_vidCofanB2WaitTran(void);
void COFANCMDDIAG_vidCofanc_Default_T(void);
void COFANCMDDIAG_vidCofanc_Gmvp_T(void);
void COFANCMDDIAG_vidCofanc_Init_T(void);
void COFANCMDDIAG_vidCofanc_Rf_T(void);
void COFANCMDDIAG_vidCofanc_Rfao_T(void);
void COFANCMDDIAG_vidCofanc_Rfgmvp_T(void);
void COFANCMDDIAG_vidCofanc_Ro_T(void);
void COFANCMDDIAG_vidCoFanCmd(void);
void COFANCMDDIAG_vidCoFanCmdB1(void);
void COFANCMDDIAG_vidCoFanCmdB2(void);
void COFANCMDDIAG_vidCoFanCmdC(void);
void COFANCMDDIAG_vidCoFanCtlMng(void);
void COFANCMDDIAG_vidCoFanCtlMngB1(void);
void COFANCMDDIAG_vidCoFanCtlMngB2(void);
void COFANCMDDIAG_vidCoFanCtlMngC(void);
void COFANCMDDIAG_vidCoFanSpdMng(void);
void COFANCMDDIAG_vidCritScCnt(void);
void COFANCMDDIAG_vidCritScRlyElDgo(void);
void COFANCMDDIAG_vidDgClsdRlyCoFanB2(void);
void COFANCMDDIAG_vidDgCohCoFB2NoSpd(void);
void COFANCMDDIAG_vidDgoCoFanB1(void);
void COFANCMDDIAG_vidDgoCoFanB2(void);
void COFANCMDDIAG_vidDgoCoFanC(void);
void COFANCMDDIAG_vidDgoCohB2(void);
void COFANCMDDIAG_vidDgoCohCoFanB1(void);
void COFANCMDDIAG_vidDgoCohCoFanB2(void);
void COFANCMDDIAG_vidDgoHalFanC(void);
void COFANCMDDIAG_vidDiagBMonRun(void);
void COFANCMDDIAG_vidDiagCoFan(void);
void COFANCMDDIAG_vidDiagCoFanEna(void);
void COFANCMDDIAG_vidECIDgo(void);
void COFANCMDDIAG_vidInit(void);
void COFANCMDDIAG_vidInitFricC(void);
void COFANCMDDIAG_vidInitOutput(void);
void COFANCMDDIAG_vidMngTimer(void);
void COFANCMDDIAG_vidRstCoFanCtlMng(void);
void COFANCMDDIAG_vidRstDft(void);
void COFANCMDDIAG_vidRstDftFricC(void);
void COFANCMDDIAG_vidSpdFanB1Mng(void);
void COFANCMDDIAG_vidSpdFanB2Mng(void);
void COFANCMDDIAG_vidSpdFanCMng(void);


#endif /* COFANCMDDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/

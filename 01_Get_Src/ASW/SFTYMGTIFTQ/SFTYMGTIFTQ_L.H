/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : SFTYMGTIFTQ                                              */
/*                                                                            */
/* !Module         : SFTYMGTIFTQ                                              */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : SFTYMGTIFTQ_L.H                                          */
/*                                                                            */
/* !Scope          : Private                                                  */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEES                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SFTYMGTIFTQ/SFTYMGTIFTQ_L.H_v     $*/
/* $Revision::   1.3      $$Author::   hmelloul       $$Date::   21 Mar 2011 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef SFTYMGTIFTQ_L_H
#define SFTYMGTIFTQ_L_H

#include "STD_TYPES.h"

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

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SFTYMGTIFTQ_u8Inhib;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean SftyMgt_bDftStuckAccP;
extern boolean SftyMgt_bDgoInhChkInitSfty;
extern boolean SftyMgt_bEepromStatus;
extern boolean SftyMgt_bInpChkAccP;
extern boolean SftyMgt_bInpChkBrk;
extern boolean SftyMgt_bInpChkClu;
extern boolean SftyMgt_bInpChkF329;
extern boolean SftyMgt_bInpChkF349;
extern boolean SftyMgt_bInpChkF34D;
extern boolean SftyMgt_bInpChkF38D;
extern boolean SftyMgt_bInpChkNeutPosn;
extern boolean SftyMgt_bInpChkThr;
extern boolean SftyMgt_bInpChkVehSpd;
extern boolean SftyMgt_bMonRunInhChkInitSfty;
extern boolean SFTYMGTIFTQ_bDgoAlgo_Cpu;
extern boolean SFTYMGTIFTQ_bDgoAlgo_CpuSfty;
extern boolean SFTYMGTIFTQ_bDgoClk_Cpu;
extern boolean SFTYMGTIFTQ_bDgoClk_CpuSfty;
extern boolean SFTYMGTIFTQ_bDgoIrvEMPrev1;
extern boolean SFTYMGTIFTQ_bDgoIrvSTTPrev1;
extern boolean SFTYMGTIFTQ_bDgoIrvVSCtlPrev1;
extern boolean SFTYMGTIFTQ_bFilSig_1;
extern boolean SFTYMGTIFTQ_bRawSig;
extern boolean SFTYMGTIFTQ_bStuckAccP;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8 SFTYMGTIFTQ_CtDftSftyStuckAccP;
extern uint8 SFTYMGTIFTQ_u8AntiBounceCounter;
extern uint8 SFTYMGTIFTQ_u8CntFilt_1;
extern uint8 SFTYMGTIFTQ_u8ctDftLaddPrev1;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16 Sfty_ctrAccPCpu;
extern uint16 Sfty_ctrAlgoCpu;
extern uint16 Sfty_ctrAlgoCpuSfty;
extern uint16 Sfty_ctrClkCpu;
extern uint16 Sfty_ctrClkCpuSfty;
extern uint16 Sfty_ctrThrCpu;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SFTYMGTIFTQ_vidAccPAcquiSftyLvl2(void);
void SFTYMGTIFTQ_vidAcPInpChkSftyLvl2(void);
void SFTYMGTIFTQ_vidBrkAcquiSftyLvl2(void);
void SFTYMGTIFTQ_vidBrkInpChkSftyLvl2(void);
void SFTYMGTIFTQ_vidCluAcquiSftyLvl2(void);
void SFTYMGTIFTQ_vidCluInpChkSftyLvl2(void);
void SFTYMGTIFTQ_vidDftAutChkIni(void);
void SFTYMGTIFTQ_vidDiagInpLvl2An(void);
void SFTYMGTIFTQ_vidDiagInpLvl2An_1(void);
void SFTYMGTIFTQ_vidDiagSensAcquiLvl2(void);
void SFTYMGTIFTQ_vidEeprom(void);
void SFTYMGTIFTQ_vidEnabEngStopReq(void);
void SFTYMGTIFTQ_vidF329RxLvl2(void);
void SFTYMGTIFTQ_vidF329SftyLevel2(void);
void SFTYMGTIFTQ_vidF349RxLvl2(void);
void SFTYMGTIFTQ_vidF349SftyLevel2(void);
void SFTYMGTIFTQ_vidF34DSftyLevel2(void);
void SFTYMGTIFTQ_vidF38DRxLvl2(void);
void SFTYMGTIFTQ_vidF38DSftyLevel2(void);
void SFTYMGTIFTQ_vidFstftLvl3(void);
void SFTYMGTIFTQ_vidInerface(void);
void SFTYMGTIFTQ_vidInhSftylvl2Afts(void);
void SFTYMGTIFTQ_vidInitOutput(void);
void SFTYMGTIFTQ_vidInitOutput1(void);
void SFTYMGTIFTQ_vidInpChkLvl2(void);
void SFTYMGTIFTQ_vidInpIgTqRelzd(void);
void SFTYMGTIFTQ_vidInpInjTqRelzd(void);
void SFTYMGTIFTQ_vidNeutPosnAqSftLvl2(void);
void SFTYMGTIFTQ_vidNeutPosnSftyLvl2(void);
void SFTYMGTIFTQ_vidNoProdTqMon(void);
void SFTYMGTIFTQ_vidRam_uncleared(void);
void SFTYMGTIFTQ_vidRst(void);
void SFTYMGTIFTQ_vidRstHw(void);
void SFTYMGTIFTQ_vidRstSw(void);
void SFTYMGTIFTQ_vidSensInpCkSftyLvl2(void);
void SFTYMGTIFTQ_vidSndDftLvl3(void);
void SFTYMGTIFTQ_vidThrAcquiSftyLvl2(void);
void SFTYMGTIFTQ_vidThrInpChkSftyLvl2(void);
void SFTYMGTIFTQ_vidVehSpdInpSftyLvl2(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* SFTYMGTIFTQ_L_H */

/*-------------------------------- end of file -------------------------------*/

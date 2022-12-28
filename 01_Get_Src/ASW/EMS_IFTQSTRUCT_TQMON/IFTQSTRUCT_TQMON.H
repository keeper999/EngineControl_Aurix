/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : IFTQSTRUCT_TQMON                                         */
/*                                                                            */
/* !Module         : IFTQSTRUCT_TQMON                                         */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : IFTQSTRUCT_TQMON.H                                       */
/*                                                                            */
/* !Scope          : Public                                                   */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/IFTQSTRUCT_TQMON/IFTQS$*/
/* $Revision::   1.16     $$Author::   mbenfrad       $$Date::   15 Feb 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef IFTQSTRUCT_TQMON_H
#define IFTQSTRUCT_TQMON_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_AGCKCLSEXCAL_M_LNS            (16)
#define SFTYMGT_AGCKCLSEXCAL_M_COLS            (16)
#define SFTYMGT_AGCKCLSEXCAL_T_COLS            (16)
#define SFTYMGT_AGCKCLSEXCAL2_M_LNS           (16)
#define SFTYMGT_AGCKCLSEXCAL2_M_COLS           (16)
#define SFTYMGT_AGCKOPINCAL_M_LNS             (16)
#define SFTYMGT_AGCKOPINCAL_M_COLS             (16)
#define SFTYMGT_AGCKOPINCAL_T_COLS             (16)
#define SFTYMGT_AGCKOPINCAL2_M_LNS            (16)
#define SFTYMGT_AGCKOPINCAL2_M_COLS            (16)
#define SFTYMGT_NENG_A_COLS                    (16)
#define SFTYMGT_NENGY_A_COLS                   (16)
#define SFTYMGT_NOGEARCORDDRIVFIL_A_COLS       (9)
#define SFTYMGT_NOGEARCORDDRIVFIL_T_COLS       (9)
#define SFTYMGT_PRM_BDECEACVTQSYS_COLS         (5)
#define SFTYMGT_PRM_BNREGREQ_COLS              (5)
#define SFTYMGT_PRM_NCKFIL_COLS                (5)
#define SFTYMGT_PRM_NOGEARCORDDRIVFIL_COLS     (5)
#define SFTYMGT_PRM_NOTARGEARTRA_COLS          (5)
#define SFTYMGT_PRM_TQLIMEM_COLS               (5)
#define SFTYMGT_RAIRLDX_A_COLS                 (16)
#define SFTYMGT_SPD1000RATCF_T_COLS            (8)
#define SFTYMGT_SPD1000RATHI_A_COLS            (8)
#define SftyMgt_tiSdlIf_SC                40           /* 40 */

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
extern const boolean  SftyMgt_bAcvGain_nCkFil_C;
extern const boolean  SftyMgt_bCkClsExVlvSel_C;
extern const boolean  SftyMgt_bCkOpInVlvSel_C;
extern const boolean  SftyMgt_bCluTyp_C;
extern const boolean  SftyMgt_bCompSpd1000_C;
extern const boolean  SftyMgt_bGearTyp_C;
extern const boolean  SftyMgt_bInhModCur_C;
extern const boolean  SftyMgt_bModCurNotEnaOffs_C;
extern const boolean  SftyMgt_bSelDlySdl_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_facGainFil_nCkFil_C;
extern const uint8  SftyMgt_facTranModThd_C;
extern const uint8  SftyMgt_noGearCordDrivFil_A[SFTYMGT_NOGEARCORDDRIVFIL_A_COLS];
extern const uint8  SftyMgt_noGearCordDrivFil_T[SFTYMGT_NOGEARCORDDRIVFIL_T_COLS];
extern const uint8  SftyMgt_rThdOpTraPHiFreq_C;
extern const uint8  SftyMgt_tiDlyEgdGearSfty_C;
extern const uint8  SftyMgt_tiDlyStrtExtAcv_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const uint16  SftyMgt_agCkClsExCal_M[SFTYMGT_AGCKCLSEXCAL_M_LNS][SFTYMGT_AGCKCLSEXCAL_M_COLS];
extern const uint16  SftyMgt_agCkClsExCal_T[SFTYMGT_AGCKCLSEXCAL_T_COLS];
extern const uint16  SftyMgt_agCkClsExCal2_M[SFTYMGT_AGCKCLSEXCAL2_M_LNS][SFTYMGT_AGCKCLSEXCAL2_M_COLS];
extern const uint16  SftyMgt_agCkClsExDownThd_C;
extern const uint16  SftyMgt_agCkClsExUpThd_C;
extern const uint16  SftyMgt_agCkOpInCal_M[SFTYMGT_AGCKOPINCAL_M_LNS][SFTYMGT_AGCKOPINCAL_M_COLS];
extern const uint16  SftyMgt_agCkOpInCal_T[SFTYMGT_AGCKOPINCAL_T_COLS];
extern const uint16  SftyMgt_agCkOpInCal2_M[SFTYMGT_AGCKOPINCAL2_M_LNS][SFTYMGT_AGCKOPINCAL2_M_COLS];
extern const uint16  SftyMgt_agCkOpInDownThd_C;
extern const uint16  SftyMgt_agCkOpInUpThd_C;
extern const uint16  SftyMgt_facGearRat_C;
extern const uint16  SftyMgt_nEng_A[SFTYMGT_NENG_A_COLS];
extern const uint16  SftyMgt_nEngY_A[SFTYMGT_NENGY_A_COLS];
extern const uint16  SftyMgt_nStrExtAcvThd_C;
extern const uint16  SftyMgt_rAirLdX_A[SFTYMGT_RAIRLDX_A_COLS];
extern const uint16  SftyMgt_spd1000RatCf_T[SFTYMGT_SPD1000RATCF_T_COLS];
extern const uint16  SftyMgt_spd1000RatHi_A[SFTYMGT_SPD1000RATHI_A_COLS];
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
extern boolean SftyMgt_bAcvAutoInj;
extern boolean SftyMgt_bAcvCllTqCll;
extern boolean SftyMgt_bAcvCllUnChk;
extern boolean SftyMgt_bAcvDrvTraInvldFRM;
extern boolean SftyMgt_bAcvIdlCll;
extern boolean SftyMgt_bAcvNRegTakeOffTqDem;
extern boolean SftyMgt_bATParkNeutExt;
extern boolean SftyMgt_bDeacAOS;
extern boolean SftyMgt_bDeceAcvCll;
extern boolean SftyMgt_bDgoSftyORngAMCoPTSt;
extern boolean SftyMgt_bDgoSftyORngATCoPTSt;
extern boolean SftyMgt_bDgoSIPORngCoPt;
extern boolean SftyMgt_bDrvTraAMTExt;
extern boolean SftyMgt_bEnaPresOffsSfty;
extern boolean SftyMgt_bEnaTqOfsSfty;
extern boolean SftyMgt_bEngSpdLimHiIntvFRM;
extern boolean SftyMgt_bEngSpdLimLoIntvFRM;
extern boolean SftyMgt_bEngStrtReq;
extern boolean SftyMgt_bFuCutOffReqTqSys;
extern boolean SftyMgt_bInhAntiDBFRM;
extern boolean SftyMgt_bInhCnvLossMdl_FRM;
extern boolean SftyMgt_bInhCoPtSIPFRM;
extern boolean SftyMgt_bInhCoStrtRStrt;
extern boolean SftyMgt_bInhNRegTakeOffFRM;
extern boolean SftyMgt_bInhRvTqDemTakeOffFRM;
extern boolean SftyMgt_bInhStgPmpLoss_FRM;
extern boolean SftyMgt_bInhTqCllFRM;
extern boolean SftyMgt_bIniIdlCtlIdlSys;
extern boolean SftyMgt_bModSptTqDem;
extern boolean SftyMgt_bOpTra;
extern boolean SftyMgt_bSIPCoPt;
extern boolean SftyMgt_bStaAuthStaCtl;
extern boolean SftyMgt_bStaReq;
extern boolean SftyMgt_bSTTCf;
extern boolean SftyMgt_bTakeOffCoPt;
extern boolean SftyMgt_bTqGrdLimBuf;
extern boolean SftyMgt_bTqSysAcvTqSys;
extern boolean SftyMgt_prm_bDeceAcvTqSys[SFTYMGT_PRM_BDECEACVTQSYS_COLS];
extern boolean SftyMgt_prm_bNRegReq[SFTYMGT_PRM_BNREGREQ_COLS];
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern sint8 SftyMgt_noEgdGearSfty;
extern sint8 SftyMgt_prm_noTarGearTra[SFTYMGT_PRM_NOTARGEARTRA_COLS];
extern uint8 SftyMgt_noAcvCyl;
extern uint8 SftyMgt_noEgdGearCordCoPt;
extern uint8 SftyMgt_noGearCord;
extern uint8 SftyMgt_prm_noGearCordDrivFil[SFTYMGT_PRM_NOGEARCORDDRIVFIL_COLS];
extern uint8 SftyMgt_stClu;
extern uint8 SftyMgt_stDrvTraCoPTSt;
extern uint8 SftyMgt_stTqPTMinCtlVSCtl;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern sint16 SftyMgt_prm_tqLimEM[SFTYMGT_PRM_TQLIMEM_COLS];
extern sint16 SftyMgt_tqAirReqGBxCoPt;
extern sint16 SftyMgt_tqAltLossUnChkBuf;
extern sint16 SftyMgt_tqCkAntiOscCor;
extern sint16 SftyMgt_tqCkDrivFilEngLim;
extern sint16 SftyMgt_tqCkEfcFil;
extern sint16 SftyMgt_tqCkEfcFilTqSys;
extern sint16 SftyMgt_tqCkEfcMaxVSCtl;
extern sint16 SftyMgt_tqCkEfcMinVSCtl;
extern sint16 SftyMgt_tqCkEfcTqDem;
extern sint16 SftyMgt_tqCkEfcWoutAntiDBTqDem;
extern sint16 SftyMgt_tqCkEngLossAdpUnChkBuf;
extern sint16 SftyMgt_tqDrvRawCoPt;
extern sint16 SftyMgt_tqEfcDifLrnOutDZone;
extern sint16 SftyMgt_tqEfcNRegTakeOffEco;
extern sint16 SftyMgt_tqEfcNRegTakeOffNorm;
extern sint16 SftyMgt_tqEfcReqCoChaChk;
extern sint16 SftyMgt_tqEfcReqCoChaUnChkBuf;
extern sint16 SftyMgt_tqGBx;
extern sint16 SftyMgt_tqIdcAirReqTqSys;
extern sint16 SftyMgt_tqIdcEngCurMaxEngLim;
extern sint16 SftyMgt_tqIdcIdl;
extern sint16 SftyMgt_tqIdcNReg;
extern sint16 SftyMgt_tqIdcRedEngLim;
extern sint16 SftyMgt_tqIdcReqCordNRegReq;
extern sint16 SftyMgt_tqIdcSysEngLim;
extern sint16 SftyMgt_tqLimEM;
extern sint16 SftyMgt_tqMaxRes;
extern sint16 SftyMgt_tqReqGBxCoPt;
extern sint16 SftyMgt_tqSumLossCmp;
extern sint16 SftyMgt_tqSumLossCmpUnChkBuf;
extern uint16 SftyMgt_nCkFil;
extern uint16 SftyMgt_nCkFilBuf;
extern uint16 SftyMgt_nOfsIdlTakeOff;
extern uint16 SftyMgt_nTarIdl;
extern uint16 SftyMgt_nTarIdlATTqSys;
extern uint16 SftyMgt_nTarIdlDynIdlSys;
extern uint16 SftyMgt_nTarIdlSftyTqSys;
extern uint16 SftyMgt_nTarIdlStrtTqSys;
extern uint16 SftyMgt_nTarIdlUnChkBuf;
extern uint16 SftyMgt_pAirExtMesCorUsThrM;
extern uint16 SftyMgt_pAirExtMesSI;
extern uint16 SftyMgt_pDsThrCor;
extern uint16 SftyMgt_prm_nCkFil[SFTYMGT_PRM_NCKFIL_COLS];
extern uint16 SftyMgt_pwrAC5Loss;
extern uint16 SftyMgt_rAccPSptModTqDem;
extern uint16 SftyMgt_rDrivTakeOffTqDem;
extern uint16 SftyMgt_spdVehBuf;
extern uint16 SftyMgt_tqACLossUnChkBuf;
extern uint16 SftyMgt_tqAuxLossTqCmp;
extern uint16 SftyMgt_tqCkEngLossUnChkBuf;
extern uint16 SftyMgt_tqCkPmpHiPUnChkBuf;
extern uint16 SftyMgt_tqCnvLossUnChkBuf;
extern uint16 SftyMgt_tqFanStrtLossUnChkBuf;
extern uint16 SftyMgt_tqStgPmpLossUnChkBuf;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void IFTQSTRUCT_TQMON_vidEntryInit(void);
void SftyMgt_Sdl10ms_IfTMS(void);
void SftyMgt_Sdl40ms_IfTMS(void);
void SftyMgt_SdlMid_bEnaTqOfs(void);
void SftyMgt_SdlMid_bInjCutOff(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* IFTQSTRUCT_TQMON_H */

/*-------------------------------- end of file -------------------------------*/

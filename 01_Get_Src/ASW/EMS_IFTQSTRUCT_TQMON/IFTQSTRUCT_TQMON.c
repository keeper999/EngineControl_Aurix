/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : IFTQSTRUCT_TQMON                                         */
/*                                                                            */
/* !Module         : IFTQSTRUCT_TQMON                                         */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : IFTQSTRUCT_TQMON.C75                                     */
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

#include "STD_TYPES.h"
#include "IFTQSTRUCT_TQMON.h"
#include "IFTQSTRUCT_TQMON_l.h"

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

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
const boolean  SftyMgt_bAcvGain_nCkFil_C = 0;
const boolean  SftyMgt_bCkClsExVlvSel_C = 0;
const boolean  SftyMgt_bCkOpInVlvSel_C = 0;
const boolean  SftyMgt_bCluTyp_C = 0;
const boolean  SftyMgt_bCompSpd1000_C = 0;
const boolean  SftyMgt_bGearTyp_C = 0;
const boolean  SftyMgt_bInhModCur_C = 0;
const boolean  SftyMgt_bModCurNotEnaOffs_C = 0;
const boolean  SftyMgt_bSelDlySdl_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  IFTQSTRUCT_TQMON_u8Inhib = 0;
const uint8  SftyMgt_facGainFil_nCkFil_C = 0;
const uint8  SftyMgt_facTranModThd_C = 0;
const uint8  SftyMgt_noGearCordDrivFil_A[SFTYMGT_NOGEARCORDDRIVFIL_A_COLS] = {0};
const uint8  SftyMgt_noGearCordDrivFil_T[SFTYMGT_NOGEARCORDDRIVFIL_T_COLS] = {0};
const uint8  SftyMgt_rThdOpTraPHiFreq_C = 0;
const uint8  SftyMgt_tiDlyEgdGearSfty_C = 0;
const uint8  SftyMgt_tiDlyStrtExtAcv_C = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const uint16  SftyMgt_agCkClsExCal_M[SFTYMGT_AGCKCLSEXCAL_M_LNS][SFTYMGT_AGCKCLSEXCAL_M_COLS] = {0};
const uint16  SftyMgt_agCkClsExCal_T[SFTYMGT_AGCKCLSEXCAL_T_COLS] = {0};
const uint16  SftyMgt_agCkClsExCal2_M[SFTYMGT_AGCKCLSEXCAL2_M_LNS][SFTYMGT_AGCKCLSEXCAL2_M_COLS] = {0};
const uint16  SftyMgt_agCkClsExDownThd_C = 0;
const uint16  SftyMgt_agCkClsExUpThd_C = 0;
const uint16  SftyMgt_agCkOpInCal_M[SFTYMGT_AGCKOPINCAL_M_LNS][SFTYMGT_AGCKOPINCAL_M_COLS] = {0};
const uint16  SftyMgt_agCkOpInCal_T[SFTYMGT_AGCKOPINCAL_T_COLS] = {0};
const uint16  SftyMgt_agCkOpInCal2_M[SFTYMGT_AGCKOPINCAL2_M_LNS][SFTYMGT_AGCKOPINCAL2_M_COLS] = {0};
const uint16  SftyMgt_agCkOpInDownThd_C = 0;
const uint16  SftyMgt_agCkOpInUpThd_C = 0;
const uint16  SftyMgt_facGearRat_C = 0;
const uint16  SftyMgt_nEng_A[SFTYMGT_NENG_A_COLS] = {0};
const uint16  SftyMgt_nEngY_A[SFTYMGT_NENGY_A_COLS] = {0};
const uint16  SftyMgt_nStrExtAcvThd_C = 0;
const uint16  SftyMgt_rAirLdX_A[SFTYMGT_RAIRLDX_A_COLS] = {0};
const uint16  SftyMgt_spd1000RatCf_T[SFTYMGT_SPD1000RATCF_T_COLS] = {0};
const uint16  SftyMgt_spd1000RatHi_A[SFTYMGT_SPD1000RATHI_A_COLS] = {0};
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
boolean IFTQSTRUCT_TQMON_bAcvNRegReOut;
boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev;
boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev1;
boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev2;
boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev3;
boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev4;
boolean IFTQSTRUCT_TQMON_bDeceAcvOut;
boolean IFTQSTRUCT_TQMON_bDeceAcvPrev;
boolean IFTQSTRUCT_TQMON_bDeceAcvPrev1;
boolean IFTQSTRUCT_TQMON_bDeceAcvPrev2;
boolean IFTQSTRUCT_TQMON_bDeceAcvPrev3;
boolean IFTQSTRUCT_TQMON_bDeceAcvPrev4;
boolean SftyMgt_bAcvAutoInj;
boolean SftyMgt_bAcvCllTqCll;
boolean SftyMgt_bAcvCllUnChk;
boolean SftyMgt_bAcvDrvTraInvldFRM;
boolean SftyMgt_bAcvIdlCll;
boolean SftyMgt_bAcvNRegTakeOffTqDem;
boolean SftyMgt_bATParkNeutExt;
boolean SftyMgt_bDeacAOS;
boolean SftyMgt_bDeceAcvCll;
boolean SftyMgt_bDgoSftyORngAMCoPTSt;
boolean SftyMgt_bDgoSftyORngATCoPTSt;
boolean SftyMgt_bDgoSIPORngCoPt;
boolean SftyMgt_bDrvTraAMTExt;
boolean SftyMgt_bEnaPresOffsSfty;
boolean SftyMgt_bEnaTqOfsSfty;
boolean SftyMgt_bEngSpdLimHiIntvFRM;
boolean SftyMgt_bEngSpdLimLoIntvFRM;
boolean SftyMgt_bEngStrtReq;
boolean SftyMgt_bFuCutOffReqTqSys;
boolean SftyMgt_bInhAntiDBFRM;
boolean SftyMgt_bInhCnvLossMdl_FRM;
boolean SftyMgt_bInhCoPtSIPFRM;
boolean SftyMgt_bInhCoStrtRStrt;
boolean SftyMgt_bInhNRegTakeOffFRM;
boolean SftyMgt_bInhRvTqDemTakeOffFRM;
boolean SftyMgt_bInhStgPmpLoss_FRM;
boolean SftyMgt_bInhTqCllFRM;
boolean SftyMgt_bIniIdlCtlIdlSys;
boolean SftyMgt_bModSptTqDem;
boolean SftyMgt_bOpTra;
boolean SftyMgt_bSIPCoPt;
boolean SftyMgt_bStaAuthStaCtl;
boolean SftyMgt_bStaReq;
boolean SftyMgt_bSTTCf;
boolean SftyMgt_bTakeOffCoPt;
boolean SftyMgt_bTqGrdLimBuf;
boolean SftyMgt_bTqSysAcvTqSys;
boolean SftyMgt_prm_bDeceAcvRaw[SFTYMGT_PRM_BDECEACVRAW_COLS];
boolean SftyMgt_prm_bDeceAcvTqSys[SFTYMGT_PRM_BDECEACVTQSYS_COLS];
boolean SftyMgt_prm_bNRegReq[SFTYMGT_PRM_BNREGREQ_COLS];
boolean SftyMgt_prm_bNRegReqRaw[SFTYMGT_PRM_BNREGREQRAW_COLS];
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
sint8 IFTQSTRUCT_TQMON_s8TarGearOut;
sint8 IFTQSTRUCT_TQMON_s8TarGearPrev;
sint8 IFTQSTRUCT_TQMON_s8TarGearPrev1;
sint8 IFTQSTRUCT_TQMON_s8TarGearPrev2;
sint8 IFTQSTRUCT_TQMON_s8TarGearPrev3;
sint8 IFTQSTRUCT_TQMON_s8TarGearPrev4;
sint8 SftyMgt_noEgdGearSfty;
sint8 SftyMgt_prm_noTarGearTra[SFTYMGT_PRM_NOTARGEARTRA_COLS];
sint8 SftyMgt_prm_noTarGearTraRaw[SFTYMGT_PRM_NOTARGEARTRARAW_COLS];
uint8 IFTQSTRUCT_TQMON_u8CorDrFilOut;
uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev1;
uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev2;
uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev3;
uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev4;
uint8 IFTQSTRUCT_TQMON_u8CorDriFilPrev;
uint8 IFTQSTRUCT_TQMON_u8TiDlyEgdGrCtr;
uint8 IFTQSTRUCT_TQMON_u8TiDlyTqSysCtr;
uint8 SftyMgt_noAcvCyl;
uint8 SftyMgt_noEgdGearCordCoPt;
uint8 SftyMgt_noGearCord;
uint8 SftyMgt_prm_noGearCordDrivFil[SFTYMGT_PRM_NOGEARCORDDRIVFIL_COLS];
uint8 SftyMgt_prm_noGearDrivFilRaw[SFTYMGT_PRM_NOGEARDRIVFILRAW_COLS];
uint8 SftyMgt_stClu;
uint8 SftyMgt_stDrvTraCoPTSt;
uint8 SftyMgt_stTqPTMinCtlVSCtl;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
sint16 IFTQSTRUCT_TQMON_s16TqLimEMOut;
sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev;
sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev1;
sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev2;
sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev3;
sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev4;
sint16 SftyMgt_prm_tqLimEM[SFTYMGT_PRM_TQLIMEM_COLS];
sint16 SftyMgt_prm_tqLimEMRaw[SFTYMGT_PRM_TQLIMEMRAW_COLS];
sint16 SftyMgt_tqAirReqGBxCoPt;
sint16 SftyMgt_tqAltLossUnChkBuf;
sint16 SftyMgt_tqCkAntiOscCor;
sint16 SftyMgt_tqCkDrivFilEngLim;
sint16 SftyMgt_tqCkEfcFil;
sint16 SftyMgt_tqCkEfcFilTqSys;
sint16 SftyMgt_tqCkEfcMaxVSCtl;
sint16 SftyMgt_tqCkEfcMinVSCtl;
sint16 SftyMgt_tqCkEfcTqDem;
sint16 SftyMgt_tqCkEfcWoutAntiDBTqDem;
sint16 SftyMgt_tqCkEngLossAdpUnChkBuf;
sint16 SftyMgt_tqDrvRawCoPt;
sint16 SftyMgt_tqEfcDifLrnOutDZone;
sint16 SftyMgt_tqEfcNRegTakeOffEco;
sint16 SftyMgt_tqEfcNRegTakeOffNorm;
sint16 SftyMgt_tqEfcReqCoChaChk;
sint16 SftyMgt_tqEfcReqCoChaUnChkBuf;
sint16 SftyMgt_tqGBx;
sint16 SftyMgt_tqIdcAirReqTqSys;
sint16 SftyMgt_tqIdcEngCurMaxEngLim;
sint16 SftyMgt_tqIdcIdl;
sint16 SftyMgt_tqIdcNReg;
sint16 SftyMgt_tqIdcRedEngLim;
sint16 SftyMgt_tqIdcReqCordNRegReq;
sint16 SftyMgt_tqIdcSysEngLim;
sint16 SftyMgt_tqLimEM;
sint16 SftyMgt_tqMaxRes;
sint16 SftyMgt_tqReqGBxCoPt;
sint16 SftyMgt_tqSumLossCmp;
sint16 SftyMgt_tqSumLossCmpUnChkBuf;
uint16 IFTQSTRUCT_TQMON_u16CkFilOut;
uint16 IFTQSTRUCT_TQMON_u16CkFilPrev;
uint16 IFTQSTRUCT_TQMON_u16CkFilPrev1;
uint16 IFTQSTRUCT_TQMON_u16CkFilPrev2;
uint16 IFTQSTRUCT_TQMON_u16CkFilPrev3;
uint16 IFTQSTRUCT_TQMON_u16CkFilPrev4;
uint16 IFTQSTRUCT_TQMON_u16FilterOut;
uint16 IFTQSTRUCT_TQMON_u16SpdVeh;
uint16 SftyMgt_agCkClsExCal_MP;
uint16 SftyMgt_agCkClsExCal2_MP;
uint16 SftyMgt_agCkOpInCal_MP;
uint16 SftyMgt_agCkOpInCal2_MP;
uint16 SftyMgt_nCkFil;
uint16 SftyMgt_nCkFilBuf;
uint16 SftyMgt_nOfsIdlTakeOff;
uint16 SftyMgt_nTarIdl;
uint16 SftyMgt_nTarIdlATTqSys;
uint16 SftyMgt_nTarIdlDynIdlSys;
uint16 SftyMgt_nTarIdlSftyTqSys;
uint16 SftyMgt_nTarIdlStrtTqSys;
uint16 SftyMgt_nTarIdlUnChkBuf;
uint16 SftyMgt_pAirExtMesCorUsThrM;
uint16 SftyMgt_pAirExtMesSI;
uint16 SftyMgt_pDsThrCor;
uint16 SftyMgt_prm_nCkFil[SFTYMGT_PRM_NCKFIL_COLS];
uint16 SftyMgt_prm_nCkFilRaw[SFTYMGT_PRM_NCKFILRAW_COLS];
uint16 SftyMgt_pwrAC5Loss;
uint16 SftyMgt_rAccPSptModTqDem;
uint16 SftyMgt_rDrivTakeOffTqDem;
uint16 SftyMgt_spd1000RatCf_MP;
uint16 SftyMgt_spdVehBuf;
uint16 SftyMgt_tqACLossUnChkBuf;
uint16 SftyMgt_tqAuxLossTqCmp;
uint16 SftyMgt_tqCkEngLossUnChkBuf;
uint16 SftyMgt_tqCkPmpHiPUnChkBuf;
uint16 SftyMgt_tqCnvLossUnChkBuf;
uint16 SftyMgt_tqFanStrtLossUnChkBuf;
uint16 SftyMgt_tqStgPmpLossUnChkBuf;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
uint32 IFTQSTRUCT_TQMON_u32nEngFiltMem;
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


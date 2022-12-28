/***************************************************************************
;**
;** FILE NAME      : IDLMGR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IDLMGR.H"
#include "IDLMGR_L.H"
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
const boolean  IdlSys_bAcvIgMinSpc_C = 0;
const boolean  IdlSys_bBrkDftVal_C = 0;
const boolean  IdlSys_bCfNEngFil_C = 0;
const boolean  IdlSys_bCfNGrdFil_C = 0;
const boolean  IdlSys_bCfTEng_C = 0;
const boolean  IdlSys_bDiCutOffSTTEs_C = 0;
const boolean  IdlSys_bEnaIdlCtlAcvStrt_C = 0;
const boolean  IdlSys_bInhNSpcTarIdlDyn_C = 0;
const boolean  IdlSys_bStCpl_T[IDLSYS_BSTCPL_T_COLS] = {0};
const boolean  IdlSys_bStDriv_M[IDLSYS_BSTDRIV_M_LNS][IDLSYS_BSTDRIV_M_COLS] = {0};
const boolean  IdlSys_bTqCnvLoss_C = 0;
const boolean  IdlSys_bTqSysAcvSel_C = 0;
const uint8  IDLMGR_u8Inhib = 0;
const uint8  IdlSys_idxIniIdlGearDec_C = 0;
const uint8  IdlSys_idxIniIdlGearInc_C = 0;
const uint8  IdlSys_idxIniIdlGearNeut_C = 0;
const uint8  IdlSys_jEng_C = 0;
const uint8  IdlSys_mVeh_C = 0;
const uint8  IdlSys_noGear_T[IDLSYS_NOGEAR_T_COLS] = {0};
const uint8  IdlSys_spdVehRvsThdHi_C = 0;
const uint8  IdlSys_spdVehRvsThdLo_C = 0;
const uint8  IdlSys_spdVehThdHi_C = 0;
const uint8  IdlSys_spdVehThdLo_C = 0;
const uint8  IdlSys_stGSTyp_T[IDLSYS_STGSTYP_T_COLS] = {0};
const uint8  IdlSys_tEng_A[IDLSYS_TENG_A_COLS] = {0};
const uint8  IdlSys_tiAcvIgMinSpc_T[IDLSYS_TIACVIGMINSPC_T_COLS] = {0};
const uint8  IdlSys_tiAuthAntiStallAT_C = 0;
const uint8  IdlSys_tqHiAcvIdlCtlDyn_T[IDLSYS_TQHIACVIDLCTLDYN_T_COLS] = {0};
const uint8  IdlSys_tqHiAuthInjCutOff_T[IDLSYS_TQHIAUTHINJCUTOFF_T_COLS] = {0};
const uint8  IdlSys_tqLoAcvIdlCtlDyn_T[IDLSYS_TQLOACVIDLCTLDYN_T_COLS] = {0};
const uint8  IdlSys_tqOfsLoEngNOnIdl_T[IDLSYS_TQOFSLOENGNONIDL_T_COLS] = {0};
const sint16  IdlSys_facTranMinIdlDyn_C = 0;
const sint16  IdlSys_nEngLowIni_C = 0;
const sint16  IdlSys_nInhInjDyn_T[IDLSYS_NINHINJDYN_T_COLS] = {0};
const sint16  IdlSys_tqIniNEngLow_C = 0;
const uint16  IdlSys_facAntNEng1_C = 0;
const uint16  IdlSys_facAntNEng2_C = 0;
const uint16  IdlSys_facAntNEng3_C = 0;
const uint16  IdlSys_facAntNGrd1_C = 0;
const uint16  IdlSys_facAntNGrd2_C = 0;
const uint16  IdlSys_facAntNGrd3_C = 0;
const uint16  IdlSys_facCorIdlDyn_T[IDLSYS_FACCORIDLDYN_T_COLS] = {0};
const uint16  IdlSys_facCorNOfsCutOff_T[IDLSYS_FACCORNOFSCUTOFF_T_COLS] = {0};
const uint16  IdlSys_facCorTqAntiStallAT_T[IDLSYS_FACCORTQANTISTALLAT_T_COLS] = {0};
const uint16  IdlSys_facCorTqIdlStab_M[IDLSYS_FACCORTQIDLSTAB_M_LNS][IDLSYS_FACCORTQIDLSTAB_M_COLS] = {0};
const uint16  IdlSys_facIdlDynBrk_M[IDLSYS_FACIDLDYNBRK_M_LNS][IDLSYS_FACIDLDYNBRK_M_COLS] = {0};
const uint16  IdlSys_facIdlDynNorm_M[IDLSYS_FACIDLDYNNORM_M_LNS][IDLSYS_FACIDLDYNNORM_M_COLS] = {0};
const uint16  IdlSys_facIntNEng1_C = 0;
const uint16  IdlSys_facIntNEng2_C = 0;
const uint16  IdlSys_facIntNEng3_C = 0;
const uint16  IdlSys_facIntNGrd1_C = 0;
const uint16  IdlSys_facIntNGrd2_C = 0;
const uint16  IdlSys_facIntNGrd3_C = 0;
const uint16  IdlSys_facTranMaxIdlDyn_C = 0;
const uint16  IdlSys_jVeh_T[IDLSYS_JVEH_T_COLS] = {0};
const uint16  IdlSys_nErrIdlDyn_A[IDLSYS_NERRIDLDYN_A_COLS] = {0};
const uint16  IdlSys_nErrIdlStabX_A[IDLSYS_NERRIDLSTABX_A_COLS] = {0};
const uint16  IdlSys_nErrIdlStabY_A[IDLSYS_NERRIDLSTABY_A_COLS] = {0};
const uint16  IdlSys_nGrdEngAntiStallAT_A[IDLSYS_NGRDENGANTISTALLAT_A_COLS] = {0};
const uint16  IdlSys_nGrdEngInjCutOff_A[IDLSYS_NGRDENGINJCUTOFF_A_COLS] = {0};
const uint16  IdlSys_nOfsAcvIdlCtl_T[IDLSYS_NOFSACVIDLCTL_T_COLS] = {0};
const uint16  IdlSys_nOfsDeacIdlCtl_T[IDLSYS_NOFSDEACIDLCTL_T_COLS] = {0};
const uint16  IdlSys_nOfsIniTarIdl_C = 0;
const uint16  IdlSys_nOfsIniTarIdlDyn_C = 0;
const uint16  IdlSys_nOfsInjCutOff_M[IDLSYS_NOFSINJCUTOFF_M_LNS][IDLSYS_NOFSINJCUTOFF_M_COLS] = {0};
const uint16  IdlSys_nOfsRstrtAuthIdlCtl_T[IDLSYS_NOFSRSTRTAUTHIDLCTL_T_COLS] = {0};
const uint16  IdlSys_nOfsStrtAuthIdlCtl_T[IDLSYS_NOFSSTRTAUTHIDLCTL_T_COLS] = {0};
const uint16  IdlSys_nThdHiEnaIdl_C = 0;
const uint16  IdlSys_nThdLoEnaIdl_C = 0;
const uint16  IdlSys_spdVehTqClu_A[IDLSYS_SPDVEHTQCLU_A_COLS] = {0};
const uint16  IdlSys_tiFilEngSpd_C = 0;
const uint16  IdlSys_tiFilNEng1_A[IDLSYS_TIFILNENG1_A_COLS] = {0};
const uint16  IdlSys_tiFilNEng1_C = 0;
const uint16  IdlSys_tiFilNEng1_T[IDLSYS_TIFILNENG1_T_COLS] = {0};
const uint16  IdlSys_tiFilNEng2_A[IDLSYS_TIFILNENG2_A_COLS] = {0};
const uint16  IdlSys_tiFilNEng2_C = 0;
const uint16  IdlSys_tiFilNEng2_T[IDLSYS_TIFILNENG2_T_COLS] = {0};
const uint16  IdlSys_tiFilNEng3_C = 0;
const uint16  IdlSys_tiFilNGrd_A[IDLSYS_TIFILNGRD_A_COLS] = {0};
const uint16  IdlSys_tiFilNGrd_T[IDLSYS_TIFILNGRD_T_COLS] = {0};
const uint16  IdlSys_tiFilNGrd1_C = 0;
const uint16  IdlSys_tiFilNGrd2_C = 0;
const uint16  IdlSys_tiFilNGrd3_C = 0;
const uint16  IdlSys_tiFilRatGear_C = 0;
const uint16  IdlSys_tiFilTqLossCmp_A[IDLSYS_TIFILTQLOSSCMP_A_COLS] = {0};
const uint16  IdlSys_tiFilTqLossCmp_T[IDLSYS_TIFILTQLOSSCMP_T_COLS] = {0};
const uint16  IdlSys_tiFilTqMaxClu_A[IDLSYS_TIFILTQMAXCLU_A_COLS] = {0};
const uint16  IdlSys_tiFilTqMaxClu_T[IDLSYS_TIFILTQMAXCLU_T_COLS] = {0};
const uint16  IdlSys_tiFilVehSpd_C = 0;
const uint16  IdlSys_tiTranCll_C = 0;
const uint16  IdlSys_tiTranFilNEng_C = 0;
const uint16  IdlSys_tiTranFilNGrd_C = 0;
const uint16  IdlSys_tqIdcAntiStallAT_M[IDLSYS_TQIDCANTISTALLAT_M_LNS][IDLSYS_TQIDCANTISTALLAT_M_COLS] = {0};
const uint16  IdlSys_tqIncCll_C = 0;
const uint16  IdlSys_tqMaxClu_A[IDLSYS_TQMAXCLU_A_COLS] = {0};
const uint16  IdlSys_tqMaxClu_M[IDLSYS_TQMAXCLU_M_LNS][IDLSYS_TQMAXCLU_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 IDLMGR_stCutInj;
uint8 IDLMGR_stRegSup;
boolean IDLMGR_bAcvAntiStallFilPrev;
boolean IDLMGR_bAcvAntiStallFilSecPrev;
boolean IDLMGR_bAcvIdlCrawlPrev;
boolean IDLMGR_bAcvIdlCtlDynPrev;
boolean IDLMGR_bAcvIdlCtlPrev;
boolean IDLMGR_bAcvIdlCtlSecPrev;
boolean IDLMGR_bAcvStrtTqSysPrev;
boolean IDLMGR_bBasculeRS;
boolean IDLMGR_bHystveh;
boolean IDLMGR_bIniIdlReqPrev;
boolean IDLMGR_bNegHysVeh;
boolean IDLMGR_bTqSysAcvPrev;
boolean IDLMGR_bTurnOffDelayOut;
boolean IDLMGR_bTurnOffDelayOut2;
boolean IdlSys_bAcvAntiStallAT;
boolean IdlSys_bAcvBrk;
boolean IdlSys_bAcvIdlCrawl;
boolean IdlSys_bAcvIdlCtlDyn;
boolean IdlSys_bAcvIdlCtlEngSpd;
boolean IdlSys_bAcvIdlCtlStrt;
boolean IdlSys_bAcvNThd_MP;
boolean IdlSys_bAuthIdlCtlNEng;
boolean IdlSys_bAuthIdlCtlStEng;
boolean IdlSys_bAuthInjCutOff;
boolean IdlSys_bAuthInjCutOffTqMin;
boolean IdlSys_bDeacIdlCtlEngSpd;
boolean IdlSys_bDiCutOffSTTEs;
boolean IdlSys_bEnaIdl;
boolean IdlSys_bEngNOnIdl;
boolean IdlSys_bIniIdl;
boolean IdlSys_bIniIdlCtl;
boolean IdlSys_bIniIdlCtlCrawlChg;
boolean IdlSys_bIniIdlCtlDyn;
boolean IdlSys_bIniIdlCtlGearChg;
boolean IdlSys_bIniIdlCtlModChg;
boolean IdlSys_bRstNEstim;
boolean IdlSys_bRvs_MP;
boolean IdlSys_bSpcTarIdlDyn_MP;
uint32 IDLMGR_u32FiltredEngSpdMem;
uint32 IDLMGR_u32FiltredIdlSpdVehMem;
uint32 IDLMGR_u32FiltredSysRGearMem;
uint32 IDLMGR_u32FiltreEngFil1Mem;
uint32 IDLMGR_u32FiltreEngFil2Mem;
uint8 IDLMGR_u8IdlSysIdxFilGainPrev;
uint8 IDLMGR_u8IdxIdlCtlModPrev;
uint8 IDLMGR_u8OldIdxFilGainPrev;
uint8 IdlSys_idxFilGain;
uint8 IdlSys_idxIniIdlTq_MP;
uint8 IdlSys_noGear;
uint8 IdlSys_noGearPrev;
sint16 IdlSys_nErrIdlDyn_MP;
sint16 IdlSys_nGrdEng;
sint16 IdlSys_nGrdPred;
sint16 IdlSys_nGrdRaw_MP;
sint16 IdlSys_nGrdTarIdl;
sint16 IdlSys_nOfsAuthIdlCtl_MP;
sint16 IdlSys_nOfsIdlDyn_MP;
sint16 IdlSys_tEng;
sint16 IdlSys_tqEfcEngReal_MP;
sint16 IdlSys_tqEfcTarIdl_MP;
sint16 IdlSys_tqHiAcvIdlCtlDyn_MP;
sint16 IdlSys_tqIdcIdlIni;
sint16 IdlSys_tqIdcIdlIniAir;
sint16 IdlSys_tqIdcIdlStab;
sint16 IdlSys_tqLoAcvIdlCtlDyn_MP;
sint16 IdlSys_tqLoss;
sint16 IdlSys_tqLossCmp;
sint16 IdlSys_tqMaxClu;
sint16 IdlSys_tqMaxCluFil_MP;
uint16 IDLMGR_IdlSys_nTarIdlDynPrev;
uint16 IDLMGR_u16ErrIdlDyn_A;
uint16 IDLMGR_u16FilAEngInPrev;
uint16 IDLMGR_u16InputFilNEng1Prev;
uint16 IDLMGR_u16InputFilNEng2Prev;
uint16 IDLMGR_u16InputLossCmpMapPrev;
uint16 IDLMGR_u16InTarIdlPrev;
uint16 IDLMGR_u16MeasuredEngSpdFilt;
uint16 IDLMGR_u16MeasuredIdlSysSpdVeh;
uint16 IDLMGR_u16MltpSwRmpTranStep;
uint16 IDLMGR_u16MltpSwRmpTrFilGrdStep;
uint16 IDLMGR_u16StabX_A;
uint16 IDLMGR_u16StabY_A;
uint16 IDLMGR_u16SwitchPrev;
uint16 IDLMGR_u16TiFilTqMaxCluPrev;
uint16 IDLMGR_u16TurnOffDlyCnt;
uint16 IDLMGR_u16TurnOffDlyCnt2;
uint16 IdlSys_facAnt[IDLSYS_FACANT_COLS];
uint16 IdlSys_facAntNEng;
uint16 IdlSys_facAntNGrd;
uint16 IdlSys_facCorIdlDyn_MP;
uint16 IdlSys_facIdlDyn;
uint16 IdlSys_facIdlDynBrk_MP;
uint16 IdlSys_facIdlDynNorm_MP;
uint16 IdlSys_facIdlDynRaw_MP;
uint16 IdlSys_facInt[IDLSYS_FACINT_COLS];
uint16 IdlSys_facIntNEng;
uint16 IdlSys_facIntNGrd;
uint16 IdlSys_jVeh;
uint16 IdlSys_jVehFil;
uint16 IdlSys_nAuthInjCutOff;
uint16 IdlSys_nEng;
uint16 IdlSys_nEngEstim[IDLSYS_NENGESTIM_COLS];
uint16 IdlSys_nEngEstim1;
uint16 IdlSys_nEngEstim2;
uint16 IdlSys_nEngFil1;
uint16 IdlSys_nEngFil2;
uint16 IdlSys_nOfsAcvIdlCtl_MP;
uint16 IdlSys_nOfsDeacIdlCtl_MP;
uint16 IdlSys_nOfsInjCutOff;
uint16 IdlSys_nTarIdlDyn;
uint16 IdlSys_nTarIdlDynPrev;
uint16 IdlSys_rGear_MP;
uint16 IdlSys_rGearRaw_MP;
uint16 IdlSys_rTranIdlDyn_MP;
uint16 IdlSys_tiFil[IDLSYS_TIFIL_COLS];
uint16 IdlSys_tiFilNEng;
uint16 IdlSys_tiFilNEng1_MP;
uint16 IdlSys_tiFilNEng2_MP;
uint16 IdlSys_tiFilNGrd;
uint16 IdlSys_tiFilNGrd_MP;
uint16 IdlSys_tiFilTqLossCmp_MP;
uint16 IdlSys_tiFilTqMaxClu_MP;
uint16 IdlSys_tiTranFilGrd;
uint16 IdlSys_tiTranFilNGrd;
uint16 IdlSys_tqCnvLoss;
sint32 IDLMGR_s32FiltredIdlSpdVehMem;
sint32 IDLMGR_s32FiltredIdlSysaEngMem;
sint32 IDLMGR_s32FiltredMaxCluFilMem;
sint32 IDLMGR_s32nEngAddPrev[IDLMGR_S32NENGADDPREV_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


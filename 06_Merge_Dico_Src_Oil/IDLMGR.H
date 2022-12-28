/***************************************************************************
;**
;** FILE NAME      : IDLMGR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IDLMGR_H
#define IDLMGR_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IDLSYS_BSTCPL_T_COLS                   ( 4 )
#define IDLSYS_BSTDRIV_M_LNS                  ( 3 )
#define IDLSYS_BSTDRIV_M_COLS                  ( 4 )
#define IDLSYS_FACCORIDLDYN_T_COLS             ( 8 )
#define IDLSYS_FACCORNOFSCUTOFF_T_COLS         ( 8 )
#define IDLSYS_FACCORTQANTISTALLAT_T_COLS      ( 8 )
#define IDLSYS_FACCORTQIDLSTAB_M_LNS          ( 8 )
#define IDLSYS_FACCORTQIDLSTAB_M_COLS          ( 8 )
#define IDLSYS_FACIDLDYNBRK_M_LNS             ( 4 )
#define IDLSYS_FACIDLDYNBRK_M_COLS             ( 8 )
#define IDLSYS_FACIDLDYNNORM_M_LNS            ( 4 )
#define IDLSYS_FACIDLDYNNORM_M_COLS            ( 8 )
#define IDLSYS_JVEH_T_COLS                     ( 8 )
#define IDLSYS_NERRIDLDYN_A_COLS               ( 8 )
#define IDLSYS_NERRIDLSTABX_A_COLS             ( 8 )
#define IDLSYS_NERRIDLSTABY_A_COLS             ( 8 )
#define IDLSYS_NGRDENGANTISTALLAT_A_COLS       ( 8 )
#define IDLSYS_NGRDENGINJCUTOFF_A_COLS         ( 8 )
#define IDLSYS_NINHINJDYN_T_COLS               ( 4 )
#define IDLSYS_NOFSACVIDLCTL_T_COLS            ( 4 )
#define IDLSYS_NOFSDEACIDLCTL_T_COLS           ( 4 )
#define IDLSYS_NOFSINJCUTOFF_M_LNS            ( 8 )
#define IDLSYS_NOFSINJCUTOFF_M_COLS            ( 4 )
#define IDLSYS_NOFSRSTRTAUTHIDLCTL_T_COLS      ( 8 )
#define IDLSYS_NOFSSTRTAUTHIDLCTL_T_COLS       ( 8 )
#define IDLSYS_NOGEAR_T_COLS                   ( 8 )
#define IDLSYS_SPDVEHTQCLU_A_COLS              ( 4 )
#define IDLSYS_STGSTYP_T_COLS                  ( 6 )
#define IDLSYS_TENG_A_COLS                     ( 8 )
#define IDLSYS_TIACVIGMINSPC_T_COLS            ( 4 )
#define IDLSYS_TIFILNENG1_A_COLS               ( 8 )
#define IDLSYS_TIFILNENG1_T_COLS               ( 8 )
#define IDLSYS_TIFILNENG2_A_COLS               ( 8 )
#define IDLSYS_TIFILNENG2_T_COLS               ( 8 )
#define IDLSYS_TIFILNGRD_A_COLS                ( 8 )
#define IDLSYS_TIFILNGRD_T_COLS                ( 8 )
#define IDLSYS_TIFILTQLOSSCMP_A_COLS           ( 4 )
#define IDLSYS_TIFILTQLOSSCMP_T_COLS           ( 4 )
#define IDLSYS_TIFILTQMAXCLU_A_COLS            ( 4 )
#define IDLSYS_TIFILTQMAXCLU_T_COLS            ( 4 )
#define IDLSYS_TQHIACVIDLCTLDYN_T_COLS         ( 4 )
#define IDLSYS_TQHIAUTHINJCUTOFF_T_COLS        ( 4 )
#define IDLSYS_TQIDCANTISTALLAT_M_LNS         ( 8 )
#define IDLSYS_TQIDCANTISTALLAT_M_COLS         ( 4 )
#define IDLSYS_TQLOACVIDLCTLDYN_T_COLS         ( 4 )
#define IDLSYS_TQMAXCLU_A_COLS                 ( 8 )
#define IDLSYS_TQMAXCLU_M_LNS                 ( 4 )
#define IDLSYS_TQMAXCLU_M_COLS                 ( 8 )
#define IDLSYS_TQOFSLOENGNONIDL_T_COLS         ( 4 )

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

extern const boolean  IdlSys_bAcvIgMinSpc_C;
extern const boolean  IdlSys_bBrkDftVal_C;
extern const boolean  IdlSys_bCfNEngFil_C;
extern const boolean  IdlSys_bCfNGrdFil_C;
extern const boolean  IdlSys_bCfTEng_C;
extern const boolean  IdlSys_bDiCutOffSTTEs_C;
extern const boolean  IdlSys_bEnaIdlCtlAcvStrt_C;
extern const boolean  IdlSys_bInhNSpcTarIdlDyn_C;
extern const boolean  IdlSys_bStCpl_T[IDLSYS_BSTCPL_T_COLS];
extern const boolean  IdlSys_bStDriv_M[IDLSYS_BSTDRIV_M_LNS][IDLSYS_BSTDRIV_M_COLS];
extern const boolean  IdlSys_bTqCnvLoss_C;
extern const boolean  IdlSys_bTqSysAcvSel_C;
extern const uint8  IdlSys_idxIniIdlGearDec_C;
extern const uint8  IdlSys_idxIniIdlGearInc_C;
extern const uint8  IdlSys_idxIniIdlGearNeut_C;
extern const uint8  IdlSys_jEng_C;
extern const uint8  IdlSys_mVeh_C;
extern const uint8  IdlSys_noGear_T[IDLSYS_NOGEAR_T_COLS];
extern const uint8  IdlSys_spdVehRvsThdHi_C;
extern const uint8  IdlSys_spdVehRvsThdLo_C;
extern const uint8  IdlSys_spdVehThdHi_C;
extern const uint8  IdlSys_spdVehThdLo_C;
extern const uint8  IdlSys_stGSTyp_T[IDLSYS_STGSTYP_T_COLS];
extern const uint8  IdlSys_tEng_A[IDLSYS_TENG_A_COLS];
extern const uint8  IdlSys_tiAcvIgMinSpc_T[IDLSYS_TIACVIGMINSPC_T_COLS];
extern const uint8  IdlSys_tiAuthAntiStallAT_C;
extern const uint8  IdlSys_tqHiAcvIdlCtlDyn_T[IDLSYS_TQHIACVIDLCTLDYN_T_COLS];
extern const uint8  IdlSys_tqHiAuthInjCutOff_T[IDLSYS_TQHIAUTHINJCUTOFF_T_COLS];
extern const uint8  IdlSys_tqLoAcvIdlCtlDyn_T[IDLSYS_TQLOACVIDLCTLDYN_T_COLS];
extern const uint8  IdlSys_tqOfsLoEngNOnIdl_T[IDLSYS_TQOFSLOENGNONIDL_T_COLS];
extern const sint16  IdlSys_facTranMinIdlDyn_C;
extern const sint16  IdlSys_nEngLowIni_C;
extern const sint16  IdlSys_nInhInjDyn_T[IDLSYS_NINHINJDYN_T_COLS];
extern const sint16  IdlSys_tqIniNEngLow_C;
extern const uint16  IdlSys_facAntNEng1_C;
extern const uint16  IdlSys_facAntNEng2_C;
extern const uint16  IdlSys_facAntNEng3_C;
extern const uint16  IdlSys_facAntNGrd1_C;
extern const uint16  IdlSys_facAntNGrd2_C;
extern const uint16  IdlSys_facAntNGrd3_C;
extern const uint16  IdlSys_facCorIdlDyn_T[IDLSYS_FACCORIDLDYN_T_COLS];
extern const uint16  IdlSys_facCorNOfsCutOff_T[IDLSYS_FACCORNOFSCUTOFF_T_COLS];
extern const uint16  IdlSys_facCorTqAntiStallAT_T[IDLSYS_FACCORTQANTISTALLAT_T_COLS];
extern const uint16  IdlSys_facCorTqIdlStab_M[IDLSYS_FACCORTQIDLSTAB_M_LNS][IDLSYS_FACCORTQIDLSTAB_M_COLS];
extern const uint16  IdlSys_facIdlDynBrk_M[IDLSYS_FACIDLDYNBRK_M_LNS][IDLSYS_FACIDLDYNBRK_M_COLS];
extern const uint16  IdlSys_facIdlDynNorm_M[IDLSYS_FACIDLDYNNORM_M_LNS][IDLSYS_FACIDLDYNNORM_M_COLS];
extern const uint16  IdlSys_facIntNEng1_C;
extern const uint16  IdlSys_facIntNEng2_C;
extern const uint16  IdlSys_facIntNEng3_C;
extern const uint16  IdlSys_facIntNGrd1_C;
extern const uint16  IdlSys_facIntNGrd2_C;
extern const uint16  IdlSys_facIntNGrd3_C;
extern const uint16  IdlSys_facTranMaxIdlDyn_C;
extern const uint16  IdlSys_jVeh_T[IDLSYS_JVEH_T_COLS];
extern const uint16  IdlSys_nErrIdlDyn_A[IDLSYS_NERRIDLDYN_A_COLS];
extern const uint16  IdlSys_nErrIdlStabX_A[IDLSYS_NERRIDLSTABX_A_COLS];
extern const uint16  IdlSys_nErrIdlStabY_A[IDLSYS_NERRIDLSTABY_A_COLS];
extern const uint16  IdlSys_nGrdEngAntiStallAT_A[IDLSYS_NGRDENGANTISTALLAT_A_COLS];
extern const uint16  IdlSys_nGrdEngInjCutOff_A[IDLSYS_NGRDENGINJCUTOFF_A_COLS];
extern const uint16  IdlSys_nOfsAcvIdlCtl_T[IDLSYS_NOFSACVIDLCTL_T_COLS];
extern const uint16  IdlSys_nOfsDeacIdlCtl_T[IDLSYS_NOFSDEACIDLCTL_T_COLS];
extern const uint16  IdlSys_nOfsIniTarIdl_C;
extern const uint16  IdlSys_nOfsIniTarIdlDyn_C;
extern const uint16  IdlSys_nOfsInjCutOff_M[IDLSYS_NOFSINJCUTOFF_M_LNS][IDLSYS_NOFSINJCUTOFF_M_COLS];
extern const uint16  IdlSys_nOfsRstrtAuthIdlCtl_T[IDLSYS_NOFSRSTRTAUTHIDLCTL_T_COLS];
extern const uint16  IdlSys_nOfsStrtAuthIdlCtl_T[IDLSYS_NOFSSTRTAUTHIDLCTL_T_COLS];
extern const uint16  IdlSys_nThdHiEnaIdl_C;
extern const uint16  IdlSys_nThdLoEnaIdl_C;
extern const uint16  IdlSys_spdVehTqClu_A[IDLSYS_SPDVEHTQCLU_A_COLS];
extern const uint16  IdlSys_tiFilEngSpd_C;
extern const uint16  IdlSys_tiFilNEng1_A[IDLSYS_TIFILNENG1_A_COLS];
extern const uint16  IdlSys_tiFilNEng1_C;
extern const uint16  IdlSys_tiFilNEng1_T[IDLSYS_TIFILNENG1_T_COLS];
extern const uint16  IdlSys_tiFilNEng2_A[IDLSYS_TIFILNENG2_A_COLS];
extern const uint16  IdlSys_tiFilNEng2_C;
extern const uint16  IdlSys_tiFilNEng2_T[IDLSYS_TIFILNENG2_T_COLS];
extern const uint16  IdlSys_tiFilNEng3_C;
extern const uint16  IdlSys_tiFilNGrd_A[IDLSYS_TIFILNGRD_A_COLS];
extern const uint16  IdlSys_tiFilNGrd_T[IDLSYS_TIFILNGRD_T_COLS];
extern const uint16  IdlSys_tiFilNGrd1_C;
extern const uint16  IdlSys_tiFilNGrd2_C;
extern const uint16  IdlSys_tiFilNGrd3_C;
extern const uint16  IdlSys_tiFilRatGear_C;
extern const uint16  IdlSys_tiFilTqLossCmp_A[IDLSYS_TIFILTQLOSSCMP_A_COLS];
extern const uint16  IdlSys_tiFilTqLossCmp_T[IDLSYS_TIFILTQLOSSCMP_T_COLS];
extern const uint16  IdlSys_tiFilTqMaxClu_A[IDLSYS_TIFILTQMAXCLU_A_COLS];
extern const uint16  IdlSys_tiFilTqMaxClu_T[IDLSYS_TIFILTQMAXCLU_T_COLS];
extern const uint16  IdlSys_tiFilVehSpd_C;
extern const uint16  IdlSys_tiTranCll_C;
extern const uint16  IdlSys_tiTranFilNEng_C;
extern const uint16  IdlSys_tiTranFilNGrd_C;
extern const uint16  IdlSys_tqIdcAntiStallAT_M[IDLSYS_TQIDCANTISTALLAT_M_LNS][IDLSYS_TQIDCANTISTALLAT_M_COLS];
extern const uint16  IdlSys_tqIncCll_C;
extern const uint16  IdlSys_tqMaxClu_A[IDLSYS_TQMAXCLU_A_COLS];
extern const uint16  IdlSys_tqMaxClu_M[IDLSYS_TQMAXCLU_M_LNS][IDLSYS_TQMAXCLU_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IdlSys_bAcvBrk;
extern boolean IdlSys_bAuthInjCutOff;
extern boolean IdlSys_bEnaIdl;
extern boolean IdlSys_bIniIdlCtl;
extern uint8 IdlSys_noGear;
extern sint16 IdlSys_tqIdcIdlIni;
extern sint16 IdlSys_tqIdcIdlIniAir;
extern sint16 IdlSys_tqIdcIdlStab;
extern sint16 IdlSys_tqLoss;
extern uint16 IdlSys_nTarIdlDyn;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IDLMGR_vidEntryInit(void);
void IdlSys_EveSync_bAcvIdlCtl(void);


#endif /* IDLMGR_H */

/*-------------------------------- end of file -------------------------------*/

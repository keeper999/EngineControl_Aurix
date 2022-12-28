/***************************************************************************
;**
;** FILE NAME      : IDLMGR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IDLMGR_L_H
#define IDLMGR_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IDLMGR_S32NENGADDPREV_COLS             ( 2 )
#define IDLSYS_FACANT_COLS                     ( 2 )
#define IDLSYS_FACINT_COLS                     ( 2 )
#define IDLSYS_NENGESTIM_COLS                  ( 2 )
#define IDLSYS_TIFIL_COLS                      ( 2 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st1600 */
#define IDLMGR_u8INHIB_CUT_INJ            1
#define IDLMGR_u8TEMPO_CUT_INJ            2
#define IDLMGR_u8AUTO_CUT_INJ             4
/*extern uint8 IDLMGR_stCutInj;*/

/* enum st14 */
#define REGULATOR_OFF                     1
#define WAIT_ON                           2
#define INIT_ENTRY                        4
/*extern uint8 IDLMGR_stRegSup;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  IDLMGR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 IDLMGR_stCutInj;
extern uint8 IDLMGR_stRegSup;
extern boolean IDLMGR_bAcvAntiStallFilPrev;
extern boolean IDLMGR_bAcvAntiStallFilSecPrev;
extern boolean IDLMGR_bAcvIdlCrawlPrev;
extern boolean IDLMGR_bAcvIdlCtlDynPrev;
extern boolean IDLMGR_bAcvIdlCtlPrev;
extern boolean IDLMGR_bAcvIdlCtlSecPrev;
extern boolean IDLMGR_bAcvStrtTqSysPrev;
extern boolean IDLMGR_bBasculeRS;
extern boolean IDLMGR_bHystveh;
extern boolean IDLMGR_bIniIdlReqPrev;
extern boolean IDLMGR_bNegHysVeh;
extern boolean IDLMGR_bTqSysAcvPrev;
extern boolean IDLMGR_bTurnOffDelayOut;
extern boolean IDLMGR_bTurnOffDelayOut2;
extern boolean IdlSys_bAcvAntiStallAT;
extern boolean IdlSys_bAcvIdlCrawl;
extern boolean IdlSys_bAcvIdlCtlDyn;
extern boolean IdlSys_bAcvIdlCtlEngSpd;
extern boolean IdlSys_bAcvIdlCtlStrt;
extern boolean IdlSys_bAcvNThd_MP;
extern boolean IdlSys_bAuthIdlCtlNEng;
extern boolean IdlSys_bAuthIdlCtlStEng;
extern boolean IdlSys_bAuthInjCutOffTqMin;
extern boolean IdlSys_bDeacIdlCtlEngSpd;
extern boolean IdlSys_bDiCutOffSTTEs;
extern boolean IdlSys_bEngNOnIdl;
extern boolean IdlSys_bIniIdl;
extern boolean IdlSys_bIniIdlCtlCrawlChg;
extern boolean IdlSys_bIniIdlCtlDyn;
extern boolean IdlSys_bIniIdlCtlGearChg;
extern boolean IdlSys_bIniIdlCtlModChg;
extern boolean IdlSys_bRstNEstim;
extern boolean IdlSys_bRvs_MP;
extern boolean IdlSys_bSpcTarIdlDyn_MP;
extern uint32 IDLMGR_u32FiltredEngSpdMem;
extern uint32 IDLMGR_u32FiltredIdlSpdVehMem;
extern uint32 IDLMGR_u32FiltredSysRGearMem;
extern uint32 IDLMGR_u32FiltreEngFil1Mem;
extern uint32 IDLMGR_u32FiltreEngFil2Mem;
extern uint8 IDLMGR_u8IdlSysIdxFilGainPrev;
extern uint8 IDLMGR_u8IdxIdlCtlModPrev;
extern uint8 IDLMGR_u8OldIdxFilGainPrev;
extern uint8 IdlSys_idxFilGain;
extern uint8 IdlSys_idxIniIdlTq_MP;
extern uint8 IdlSys_noGearPrev;
extern sint16 IdlSys_nErrIdlDyn_MP;
extern sint16 IdlSys_nGrdEng;
extern sint16 IdlSys_nGrdPred;
extern sint16 IdlSys_nGrdRaw_MP;
extern sint16 IdlSys_nGrdTarIdl;
extern sint16 IdlSys_nOfsAuthIdlCtl_MP;
extern sint16 IdlSys_nOfsIdlDyn_MP;
extern sint16 IdlSys_tEng;
extern sint16 IdlSys_tqEfcEngReal_MP;
extern sint16 IdlSys_tqEfcTarIdl_MP;
extern sint16 IdlSys_tqHiAcvIdlCtlDyn_MP;
extern sint16 IdlSys_tqLoAcvIdlCtlDyn_MP;
extern sint16 IdlSys_tqLossCmp;
extern sint16 IdlSys_tqMaxClu;
extern sint16 IdlSys_tqMaxCluFil_MP;
extern uint16 IDLMGR_IdlSys_nTarIdlDynPrev;
extern uint16 IDLMGR_u16ErrIdlDyn_A;
extern uint16 IDLMGR_u16FilAEngInPrev;
extern uint16 IDLMGR_u16InputFilNEng1Prev;
extern uint16 IDLMGR_u16InputFilNEng2Prev;
extern uint16 IDLMGR_u16InputLossCmpMapPrev;
extern uint16 IDLMGR_u16InTarIdlPrev;
extern uint16 IDLMGR_u16MeasuredEngSpdFilt;
extern uint16 IDLMGR_u16MeasuredIdlSysSpdVeh;
extern uint16 IDLMGR_u16MltpSwRmpTranStep;
extern uint16 IDLMGR_u16MltpSwRmpTrFilGrdStep;
extern uint16 IDLMGR_u16StabX_A;
extern uint16 IDLMGR_u16StabY_A;
extern uint16 IDLMGR_u16SwitchPrev;
extern uint16 IDLMGR_u16TiFilTqMaxCluPrev;
extern uint16 IDLMGR_u16TurnOffDlyCnt;
extern uint16 IDLMGR_u16TurnOffDlyCnt2;
extern uint16 IdlSys_facAnt[IDLSYS_FACANT_COLS];
extern uint16 IdlSys_facAntNEng;
extern uint16 IdlSys_facAntNGrd;
extern uint16 IdlSys_facCorIdlDyn_MP;
extern uint16 IdlSys_facIdlDyn;
extern uint16 IdlSys_facIdlDynBrk_MP;
extern uint16 IdlSys_facIdlDynNorm_MP;
extern uint16 IdlSys_facIdlDynRaw_MP;
extern uint16 IdlSys_facInt[IDLSYS_FACINT_COLS];
extern uint16 IdlSys_facIntNEng;
extern uint16 IdlSys_facIntNGrd;
extern uint16 IdlSys_jVeh;
extern uint16 IdlSys_jVehFil;
extern uint16 IdlSys_nAuthInjCutOff;
extern uint16 IdlSys_nEng;
extern uint16 IdlSys_nEngEstim[IDLSYS_NENGESTIM_COLS];
extern uint16 IdlSys_nEngEstim1;
extern uint16 IdlSys_nEngEstim2;
extern uint16 IdlSys_nEngFil1;
extern uint16 IdlSys_nEngFil2;
extern uint16 IdlSys_nOfsAcvIdlCtl_MP;
extern uint16 IdlSys_nOfsDeacIdlCtl_MP;
extern uint16 IdlSys_nOfsInjCutOff;
extern uint16 IdlSys_nTarIdlDynPrev;
extern uint16 IdlSys_rGear_MP;
extern uint16 IdlSys_rGearRaw_MP;
extern uint16 IdlSys_rTranIdlDyn_MP;
extern uint16 IdlSys_tiFil[IDLSYS_TIFIL_COLS];
extern uint16 IdlSys_tiFilNEng;
extern uint16 IdlSys_tiFilNEng1_MP;
extern uint16 IdlSys_tiFilNEng2_MP;
extern uint16 IdlSys_tiFilNGrd;
extern uint16 IdlSys_tiFilNGrd_MP;
extern uint16 IdlSys_tiFilTqLossCmp_MP;
extern uint16 IdlSys_tiFilTqMaxClu_MP;
extern uint16 IdlSys_tiTranFilGrd;
extern uint16 IdlSys_tiTranFilNGrd;
extern uint16 IdlSys_tqCnvLoss;
extern sint32 IDLMGR_s32FiltredIdlSpdVehMem;
extern sint32 IDLMGR_s32FiltredIdlSysaEngMem;
extern sint32 IDLMGR_s32FiltredMaxCluFilMem;
extern sint32 IDLMGR_s32nEngAddPrev[IDLMGR_S32NENGADDPREV_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IDLMGR_vidActiver_ralenti(void);
void IDLMGR_vidBoucler_stuct_couple(void);
void IDLMGR_vidCalc_auto_coupure_inj(void);
void IDLMGR_vidCalc_autorisation_inj(void);
void IDLMGR_vidCalc_condition_couple(void);
void IDLMGR_vidCalc_couple_init_reg(void);
void IDLMGR_vidCalc_couple_isop(void);
void IDLMGR_vidCalc_couple_perte_comp(void);
void IDLMGR_vidCalc_gains_filt_regime(void);
void IDLMGR_vidCalc_gains_filtre_grad(void);
void IDLMGR_vidCalc_inertie_veh(void);
void IDLMGR_vidCalc_offset_coup_inj(void);
void IDLMGR_vidCalc_pertes_convr_BVA(void);
void IDLMGR_vidCalc_pertes_embr_BVMP(void);
void IDLMGR_vidCalc_transition_gains(void);
void IDLMGR_vidCalculer_coef_ralenti(void);
void IDLMGR_vidCalculer_cond_regime(void);
void IDLMGR_vidCalculer_consigne_dyn(void);
void IDLMGR_vidCalculer_couple_pertes(void);
void IDLMGR_vidCalculer_info_regime(void);
void IDLMGR_vidCalculer_ralenti(void);
void IDLMGR_vidCalculer_reg_grad_spec(void);
void IDLMGR_vidCalculer_regime_estime(void);
void IDLMGR_vidCalculer_regime_filtre(void);
void IDLMGR_vidCalculer_valeurs_replis(void);
void IDLMGR_vidChange_rapport_boite(void);
void IDLMGR_vidDet_chang_etat_rampage(void);
void IDLMGR_vidDet_changement_mode(void);
void IDLMGR_vidDet_etat_moteur(void);
void IDLMGR_vidDet_ralenti_effectif(void);
void IDLMGR_vidDet_regime_critique(void);
void IDLMGR_vidDeterminer_demarrage(void);
void IDLMGR_vidDeterminer_etat_moteur(void);
void IDLMGR_vidDeterminer_inj_dyn(void);
void IDLMGR_vidEstimer_regime(void);
void IDLMGR_vidInitOutput(void);
void IDLMGR_vidMainTraiter_les_info(void);
void IDLMGR_vidManager_le_ralenti(void);
void IDLMGR_vidPiloter_avances_mini(void);
void IDLMGR_vidReinit_en_surregime(void);
void IDLMGR_vidSuperv_regu_de_ralenti(void);
void IDLMGR_vidTraiter_informations(void);
void IDLMGR_vidTraiter_les_info(void);


#endif /* IDLMGR_L_H */

/*-------------------------------- end of file -------------------------------*/

/***************************************************************************
;**
;** FILE NAME      : KNKACQFILT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKACQFILT.H"
#include "KNKACQFILT_L.H"
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
const boolean  KnkAcqFilt_bAcvFreq6_C = 0;
const boolean  KnkAcqFilt_bInhFiltRbl_C = 0;
const uint8  Duree_fenetre_rumble_min = 0;
const uint8  Knk_ScaEgyCoef_C = 0;
const uint8  KnkAcqFilt_CalcParam3_T[KNKACQFILT_CALCPARAM3_T_COLS] = {0};
const uint8  KnkAcqFilt_CalcParam6_T[KNKACQFILT_CALCPARAM6_T_COLS] = {0};
const uint8  KnkAcqFilt_facCylOfsInjrNoise_T[KNKACQFILT_FACCYLOFSINJRNOISE_T_COLS] = {0};
const uint8  KnkAcqFilt_frqCalcParam3_A[KNKACQFILT_FRQCALCPARAM3_A_COLS] = {0};
const uint8  KnkAcqFilt_frqCalcParam6_A[KNKACQFILT_FRQCALCPARAM6_A_COLS] = {0};
const uint8  KnkAcqFilt_noSigConvGain_A[KNKACQFILT_NOSIGCONVGAIN_A_COLS] = {0};
const uint8  KnkAcqFilt_noSigConvGain_T[KNKACQFILT_NOSIGCONVGAIN_T_COLS] = {0};
const uint8  KnkAcqFilt_numSampleFiltInit_C = 0;
const uint8  KNKACQFILT_u8Inhib = 0;
const uint8  KnkMgt_noCmpr_A[KNKMGT_NOCMPR_A_COLS] = {0};
const uint8  KnkMgt_NrProfCmd_A[KNKMGT_NRPROFCMD_A_COLS] = {0};
const uint8  KnkMgt_stTypElCmdInjrReq_A[KNKMGT_STTYPELCMDINJRREQ_A_COLS] = {0};
const uint8  KnkMgt_tCoMes_A[KNKMGT_TCOMES_A_COLS] = {0};
const uint8  KnkRbl_ScaEgyCoef_C = 0;
const sint16  knk_agInjrNoiseThd_C = 0;
const sint16  knk_agPmpHPnoiseThd_C = 0;
const uint16  knk_agInjCnvTDCref_C = 0;
const uint16  knk_agInjrNoiseEndThd_C = 0;
const uint16  knk_agPmpHPnoiseEndThd_C = 0;
const uint16  Knk_nEngThrOfsInjrNoise_C = 0;
const uint16  KnkAcqFilt_nEngSigConvGain_A[KNKACQFILT_NENGSIGCONVGAIN_A_COLS] = {0};
const uint16  KnkAcqFilt_OfsInjrSommeClq_M[KNKACQFILT_OFSINJRSOMMECLQ_M_LNS][KNKACQFILT_OFSINJRSOMMECLQ_M_COLS] = {0};
const uint16  KnkAcqFilt_OfsSommeClq_M[KNKACQFILT_OFSSOMMECLQ_M_LNS][KNKACQFILT_OFSSOMMECLQ_M_COLS] = {0};
const uint16  KnkAcqFilt_rSigConvGain_T[KNKACQFILT_RSIGCONVGAIN_T_COLS] = {0};
const uint16  KnkAcqFilt_rSigConvNom_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Acq_knk_rbl_cfg_win_status_upvb0;
boolean KNKACQFILT_bAcvCalSdlFastPrev;
boolean KnkRbl_bAcvCalSdlFast;
boolean KnkTreat_bInhRblAcq;
uint32 KnkAcqFilt_noKnkMesRawTblIdx[KNKACQFILT_NOKNKMESRAWTBLIDX_COLS];
uint32 somme_clq;
uint32 somme_rbl[SOMME_RBL_COLS];
sint8 KnkAcqFilt_FiltParam;
uint8 Knk_noCyl;
uint8 KnkAcqFilt_noKnkMesWin;
uint8 KnkAcqFilt_noSigConvGain;
uint8 KnkAcqFilt_noSigConvGainApp;
uint8 KnkAcqFilt_noSigConvGainReq;
uint8 KNKACQFILT_u8DebfencliquetisPrev;
uint8 KNKACQFILT_u8DurfencliquetisPrev;
uint8 KnkRbl_noCyl;
sint16 KnkAcqFilt_prm_agKnkMesWinRaw[KNKACQFILT_PRM_AGKNKMESWINRAW_COLS];
uint16 Fin_fenetre_cliquetis;
uint16 Knk_OfsInjrNoiseKnk;
uint16 Knk_OfsPmpHPNoiseKnk;
uint16 KnkAcqFilt_agTDCOfs;
uint16 KnkAcqFilt_agWdWinFiltInit;
uint16 KnkAcqFilt_prm_agKnkMesWin[KNKACQFILT_PRM_AGKNKMESWIN_COLS];
uint16 KnkAcqFilt_prm_uKnkMesRaw[KNKACQFILT_PRM_UKNKMESRAW_COLS];
uint16 KnkAcqFilt_rSigConvGainApp;
uint16 Somme_clq_cyl[SOMME_CLQ_CYL_COLS];
uint16 Somme_clq_rbl_cyl[SOMME_CLQ_RBL_CYL_LNS][SOMME_CLQ_RBL_CYL_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


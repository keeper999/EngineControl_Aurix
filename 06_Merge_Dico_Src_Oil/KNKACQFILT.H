/***************************************************************************
;**
;** FILE NAME      : KNKACQFILT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKACQFILT_H
#define KNKACQFILT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNKACQFILT_CALCPARAM3_T_COLS           ( 25 )
#define KNKACQFILT_CALCPARAM6_T_COLS           ( 21 )
#define KNKACQFILT_FACCYLOFSINJRNOISE_T_COLS   ( 6 )
#define KNKACQFILT_FRQCALCPARAM3_A_COLS        ( 25 )
#define KNKACQFILT_FRQCALCPARAM6_A_COLS        ( 21 )
#define KNKACQFILT_NENGSIGCONVGAIN_A_COLS      ( 16 )
#define KNKACQFILT_NOSIGCONVGAIN_A_COLS        ( 16 )
#define KNKACQFILT_NOSIGCONVGAIN_T_COLS        ( 16 )
#define KNKACQFILT_OFSINJRSOMMECLQ_M_LNS      ( 9 )
#define KNKACQFILT_OFSINJRSOMMECLQ_M_COLS      ( 5 )
#define KNKACQFILT_OFSSOMMECLQ_M_LNS          ( 9 )
#define KNKACQFILT_OFSSOMMECLQ_M_COLS          ( 15 )
#define KNKACQFILT_RSIGCONVGAIN_T_COLS         ( 16 )
#define KNKMGT_NOCMPR_A_COLS                   ( 6 )
#define KNKMGT_NRPROFCMD_A_COLS                ( 15 )
#define KNKMGT_STTYPELCMDINJRREQ_A_COLS        ( 5 )
#define KNKMGT_TCOMES_A_COLS                   ( 9 )
#define SOMME_CLQ_CYL_COLS                     ( 4 )
#define SOMME_CLQ_RBL_CYL_LNS                 ( 16 )
#define SOMME_CLQ_RBL_CYL_COLS                 ( 4 )

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

extern const boolean  KnkAcqFilt_bAcvFreq6_C;
extern const boolean  KnkAcqFilt_bInhFiltRbl_C;
extern const uint8  Duree_fenetre_rumble_min;
extern const uint8  Knk_ScaEgyCoef_C;
extern const uint8  KnkAcqFilt_CalcParam3_T[KNKACQFILT_CALCPARAM3_T_COLS];
extern const uint8  KnkAcqFilt_CalcParam6_T[KNKACQFILT_CALCPARAM6_T_COLS];
extern const uint8  KnkAcqFilt_facCylOfsInjrNoise_T[KNKACQFILT_FACCYLOFSINJRNOISE_T_COLS];
extern const uint8  KnkAcqFilt_frqCalcParam3_A[KNKACQFILT_FRQCALCPARAM3_A_COLS];
extern const uint8  KnkAcqFilt_frqCalcParam6_A[KNKACQFILT_FRQCALCPARAM6_A_COLS];
extern const uint8  KnkAcqFilt_noSigConvGain_A[KNKACQFILT_NOSIGCONVGAIN_A_COLS];
extern const uint8  KnkAcqFilt_noSigConvGain_T[KNKACQFILT_NOSIGCONVGAIN_T_COLS];
extern const uint8  KnkAcqFilt_numSampleFiltInit_C;
extern const uint8  KnkMgt_noCmpr_A[KNKMGT_NOCMPR_A_COLS];
extern const uint8  KnkMgt_NrProfCmd_A[KNKMGT_NRPROFCMD_A_COLS];
extern const uint8  KnkMgt_stTypElCmdInjrReq_A[KNKMGT_STTYPELCMDINJRREQ_A_COLS];
extern const uint8  KnkMgt_tCoMes_A[KNKMGT_TCOMES_A_COLS];
extern const uint8  KnkRbl_ScaEgyCoef_C;
extern const sint16  knk_agInjrNoiseThd_C;
extern const sint16  knk_agPmpHPnoiseThd_C;
extern const uint16  knk_agInjCnvTDCref_C;
extern const uint16  knk_agInjrNoiseEndThd_C;
extern const uint16  knk_agPmpHPnoiseEndThd_C;
extern const uint16  Knk_nEngThrOfsInjrNoise_C;
extern const uint16  KnkAcqFilt_nEngSigConvGain_A[KNKACQFILT_NENGSIGCONVGAIN_A_COLS];
extern const uint16  KnkAcqFilt_OfsInjrSommeClq_M[KNKACQFILT_OFSINJRSOMMECLQ_M_LNS][KNKACQFILT_OFSINJRSOMMECLQ_M_COLS];
extern const uint16  KnkAcqFilt_OfsSommeClq_M[KNKACQFILT_OFSSOMMECLQ_M_LNS][KNKACQFILT_OFSSOMMECLQ_M_COLS];
extern const uint16  KnkAcqFilt_rSigConvGain_T[KNKACQFILT_RSIGCONVGAIN_T_COLS];
extern const uint16  KnkAcqFilt_rSigConvNom_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Acq_knk_rbl_cfg_win_status_upvb0;
extern uint8 Knk_noCyl;
extern uint8 KnkRbl_noCyl;
extern uint16 Somme_clq_cyl[SOMME_CLQ_CYL_COLS];
extern uint16 Somme_clq_rbl_cyl[SOMME_CLQ_RBL_CYL_LNS][SOMME_CLQ_RBL_CYL_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkTreat_EveCkSnOn_KnkAcqFilt(void);
void KnkTreat_EveKnk_KnkAcqFiltFst(void);
void KnkTreat_EveKnk_KnkAcqFiltLst(void);
void KnkTreat_EveRst_KnkAcqFilt(void);
void KnkTreat_SdlFast_KnkAcqFilt(void);


#endif /* KNKACQFILT_H */

/*-------------------------------- end of file -------------------------------*/

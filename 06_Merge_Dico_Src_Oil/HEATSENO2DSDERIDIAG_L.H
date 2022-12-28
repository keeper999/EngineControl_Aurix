/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DSDERIDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2DSDERIDIAG_L_H
#define HEATSENO2DSDERIDIAG_L_H

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

/* enum st68 */
#define LDSD_TRK_DIAG_DISABLE             0
#define LDSD_TRK_DIAG_INIT                2
#define LDSD_TRK_DIAG_STOP                4
#define LDSD_TRK_DIAG_THRESH_MAX          8
#define LDSD_TRK_DIAG_THRESH_MIN          16
/*extern uint8 Ldsd_trk_diag_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  HEATSENO2DSDERIDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Ldsd_trk_diag_state;
extern boolean HEATSENO2DSDERIDIAG_bCondEnaPrev;
extern boolean Ldsd_trk_cond_enable;
extern boolean Ldsd_trk_diag_end;
extern boolean Ldsd_trk_first_diag;
extern boolean Ldsd_trk_init_fait;
extern boolean Ldsd_trk_sonde_nok;
extern boolean SenO2Ds_bDgoORng_SigGrdDiag;
extern boolean SenO2Ds_bMonRunORng_SigGrdDiag;
extern boolean SenO2Ds_bMonRunRaw_SigGrdDiag;
extern boolean SenO2Ds_bMonWaitORng_SigGrdDiag;
extern boolean SenO2Ds_bMonWaitRaw_SigGrdDiag;
extern uint8 HEATSENO2DSDERIDIAG_u8DiagStPrev;
extern uint8 HEATSENO2DSDERIDIAG_u8StGasPrev;
extern uint8 Ldsd_trk_iteration;
extern uint8 Ldsd_trk_sonde_ok;
extern uint16 Ldsd_trk_diag_count;
extern uint16 Ldsd_trk_diag_count_delta_high;
extern uint16 Ldsd_trk_diag_count_delta_low;
extern uint16 Ldsd_trk_diag_thd_voltage_temp;
extern uint16 Ldsd_trk_ewma_first_diag;
extern uint16 Ldsd_trk_high_voltage;
extern uint16 Ldsd_trk_low_voltage;
extern uint16 Ldsd_trk_max_voltage_temp;
extern uint16 Ldsd_trk_min_voltage_temp;
extern uint16 Ldsd_trk_pumped_gas_mfr;
extern uint16 Ldsd_trk_tension_s_av_prec;
extern uint16 Ldsd_trk_voltage_pond;
extern uint16 SenO2Ds_SigGrdFacMesRaw;
extern uint16 SenO2Ds_SigGrdFacMinRaw;
extern uint16 SenO2Ds_tiInhSigGrdDiag;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HEATSENO2DSDERIDIAG_vidAvgEwma(void);
void HEATSENO2DSDERIDIAG_vidAvgPnd(void);
void HEATSENO2DSDERIDIAG_vidCalcAvg(void);
void HEATSENO2DSDERIDIAG_vidDiag(void);
void HEATSENO2DSDERIDIAG_vidDiagSO2Ok(void);
void HEATSENO2DSDERIDIAG_vidDiaSO2Nok(void);
void HEATSENO2DSDERIDIAG_vidFacMes(void);
void HEATSENO2DSDERIDIAG_vidFirstDiag(void);
void HEATSENO2DSDERIDIAG_vidFirstTime(void);
void HEATSENO2DSDERIDIAG_vidGasGsl(void);
void HEATSENO2DSDERIDIAG_vidGslGas(void);
void HEATSENO2DSDERIDIAG_vidIniOutput(void);
void HEATSENO2DSDERIDIAG_vidInitGaz(void);
void HEATSENO2DSDERIDIAG_vidInitGsl(void);
void HEATSENO2DSDERIDIAG_vidInitTran(void);
void HEATSENO2DSDERIDIAG_vidSavePwrl(void);
void HEATSENO2DSDERIDIAG_vidSeqDiag(void);
void HEATSENO2DSDERIDIAG_vidSigEuro6(void);
void HEATSENO2DSDERIDIAG_vidSwitch(void);
void HEATSENO2DSDERIDIAG_vidTrkCond(void);
void HEATSENO2DSDERIDIAG_vidTrkDiag(void);
void HEATSENO2DSDERIDIAG_vidTrkInit(void);
void HEATSENO2DSDERIDIAG_vidTrkMgr(void);
void HEATSENO2DSDERIDIAG_vidTrkNormal(void);


#endif /* HEATSENO2DSDERIDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/

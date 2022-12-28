/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DSDERIDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2DSDERIDIAG_H
#define HEATSENO2DSDERIDIAG_H

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


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Manu_inh_ldsd_trk_diag_so2_av;
extern const boolean  SenO2Ds_bAcvEuro6SigGrdDiag_C;
extern const boolean  SenO2Ds_bAcvSeqSigGrdDiag_C;
extern const boolean  SenO2Ds_bInhMonWait_sigGrd_C;
extern const boolean  SenO2Ds_bInhSigGrdDiagPresScav_C;
extern const uint8  Ldsd_trk_iteration_thresh;
extern const uint8  Ldsd_trk_iteration_thresh_gas;
extern const uint8  Ldsd_trk_sonde_ok_thresh;
extern const uint8  Ldsd_trk_sonde_ok_thresh_gas;
extern const uint16  Ldsd_trk_coef_pond;
extern const uint16  Ldsd_trk_coef_pond_gas;
extern const uint16  Ldsd_trk_diag_thresh_voltage;
extern const uint16  Ldsd_trk_diag_thresh_voltage_gas;
extern const uint16  Ldsd_trk_ewma_thresh;
extern const uint16  Ldsd_trk_ewma_thresh_gas;
extern const uint16  Ldsd_trk_max_voltage;
extern const uint16  Ldsd_trk_max_voltage_gas;
extern const uint16  Ldsd_trk_min_temp_cata;
extern const uint16  Ldsd_trk_min_temp_cata_gas;
extern const uint16  Ldsd_trk_min_voltage;
extern const uint16  Ldsd_trk_min_voltage_gas;
extern const uint16  Ldsd_trk_voltage_pond_dif_max;
extern const uint16  Ldsd_trk_voltage_pond_dif_max_g;
extern const uint16  Ldsd_trk_voltage_pond_dif_min;
extern const uint16  Ldsd_trk_voltage_pond_dif_min_g;
extern const uint16  SenO2Ds_tiInhSigGrdDiag_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean SenO2Ds_bAcvSeqMemSigGrdDiag;
extern boolean SenO2Ds_bAcvSeqSigGrdDiag;
extern uint16 Ldsd_trk_ewma_eep;
extern uint16 Ldsd_trk_ewma_failure;
extern uint16 Ldsd_trk_ewma_no_fail;
extern uint16 SenO2Ds_SigGrdFacMes_Obd6Mod;
extern uint16 SenO2Ds_SigGrdFacMin_Obd6Mod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SenO2Ds_EvePwrl_SigGrdDiag(void);
void SenO2Ds_EveRst_SigGrdDiag(void);
void SenO2Ds_SdlFast_SigGrdDiag(void);
void SenO2Ds_SdlMid_SigGrdDiag(void);


#endif /* HEATSENO2DSDERIDIAG_H */

/*-------------------------------- end of file -------------------------------*/

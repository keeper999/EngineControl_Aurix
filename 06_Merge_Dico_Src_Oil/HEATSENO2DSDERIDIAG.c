/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DSDERIDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "HEATSENO2DSDERIDIAG.H"
#include "HEATSENO2DSDERIDIAG_L.H"
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
const boolean  Manu_inh_ldsd_trk_diag_so2_av = 0;
const boolean  SenO2Ds_bAcvEuro6SigGrdDiag_C = 0;
const boolean  SenO2Ds_bAcvSeqSigGrdDiag_C = 0;
const boolean  SenO2Ds_bInhMonWait_sigGrd_C = 0;
const boolean  SenO2Ds_bInhSigGrdDiagPresScav_C = 0;
const uint8  HEATSENO2DSDERIDIAG_u8Inhib = 0;
const uint8  Ldsd_trk_iteration_thresh = 0;
const uint8  Ldsd_trk_iteration_thresh_gas = 0;
const uint8  Ldsd_trk_sonde_ok_thresh = 0;
const uint8  Ldsd_trk_sonde_ok_thresh_gas = 0;
const uint16  Ldsd_trk_coef_pond = 0;
const uint16  Ldsd_trk_coef_pond_gas = 0;
const uint16  Ldsd_trk_diag_thresh_voltage = 0;
const uint16  Ldsd_trk_diag_thresh_voltage_gas = 0;
const uint16  Ldsd_trk_ewma_thresh = 0;
const uint16  Ldsd_trk_ewma_thresh_gas = 0;
const uint16  Ldsd_trk_max_voltage = 0;
const uint16  Ldsd_trk_max_voltage_gas = 0;
const uint16  Ldsd_trk_min_temp_cata = 0;
const uint16  Ldsd_trk_min_temp_cata_gas = 0;
const uint16  Ldsd_trk_min_voltage = 0;
const uint16  Ldsd_trk_min_voltage_gas = 0;
const uint16  Ldsd_trk_voltage_pond_dif_max = 0;
const uint16  Ldsd_trk_voltage_pond_dif_max_g = 0;
const uint16  Ldsd_trk_voltage_pond_dif_min = 0;
const uint16  Ldsd_trk_voltage_pond_dif_min_g = 0;
const uint16  SenO2Ds_tiInhSigGrdDiag_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Ldsd_trk_diag_state;
boolean HEATSENO2DSDERIDIAG_bCondEnaPrev;
boolean Ldsd_trk_cond_enable;
boolean Ldsd_trk_diag_end;
boolean Ldsd_trk_first_diag;
boolean Ldsd_trk_init_fait;
boolean Ldsd_trk_sonde_nok;
boolean SenO2Ds_bAcvSeqMemSigGrdDiag;
boolean SenO2Ds_bAcvSeqSigGrdDiag;
boolean SenO2Ds_bDgoORng_SigGrdDiag;
boolean SenO2Ds_bMonRunORng_SigGrdDiag;
boolean SenO2Ds_bMonRunRaw_SigGrdDiag;
boolean SenO2Ds_bMonWaitORng_SigGrdDiag;
boolean SenO2Ds_bMonWaitRaw_SigGrdDiag;
uint8 HEATSENO2DSDERIDIAG_u8DiagStPrev;
uint8 HEATSENO2DSDERIDIAG_u8StGasPrev;
uint8 Ldsd_trk_iteration;
uint8 Ldsd_trk_sonde_ok;
uint16 Ldsd_trk_diag_count;
uint16 Ldsd_trk_diag_count_delta_high;
uint16 Ldsd_trk_diag_count_delta_low;
uint16 Ldsd_trk_diag_thd_voltage_temp;
uint16 Ldsd_trk_ewma_eep;
uint16 Ldsd_trk_ewma_failure;
uint16 Ldsd_trk_ewma_first_diag;
uint16 Ldsd_trk_ewma_no_fail;
uint16 Ldsd_trk_high_voltage;
uint16 Ldsd_trk_low_voltage;
uint16 Ldsd_trk_max_voltage_temp;
uint16 Ldsd_trk_min_voltage_temp;
uint16 Ldsd_trk_pumped_gas_mfr;
uint16 Ldsd_trk_tension_s_av_prec;
uint16 Ldsd_trk_voltage_pond;
uint16 SenO2Ds_SigGrdFacMes_Obd6Mod;
uint16 SenO2Ds_SigGrdFacMesRaw;
uint16 SenO2Ds_SigGrdFacMin_Obd6Mod;
uint16 SenO2Ds_SigGrdFacMinRaw;
uint16 SenO2Ds_tiInhSigGrdDiag;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


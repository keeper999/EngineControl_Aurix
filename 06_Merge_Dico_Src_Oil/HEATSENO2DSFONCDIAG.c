/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DSFONCDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "HEATSENO2DSFONCDIAG.H"
#include "HEATSENO2DSFONCDIAG_L.H"
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
const boolean  LsMon_bAcvChkRMixtItrsv_C = 0;
const boolean  LsMon_bManDiagFcoActiv_C = 0;
const boolean  LsMon_bManDiagFldActiv_C = 0;
const boolean  Manu_inh_diag_av_max_delay = 0;
const boolean  Manu_inh_Ldsd_av_diag_intru_cond = 0;
const boolean  SenO2Ds_bAcvEuro6DsPlausFco_C = 0;
const boolean  SenO2Ds_bAcvEuro6DsPlausFld_C = 0;
const boolean  SenO2Ds_bAcvSeqDsPlausFld_C = 0;
const boolean  SenO2Ds_bInhDiagPresScav_C = 0;
const boolean  SenO2Ds_bInhMonWait_PlausFco_C = 0;
const boolean  SenO2Ds_bInhMonWait_PlausFld_C = 0;
const uint32  LsMon_rMixtMaxItrsvSenO2Ds_C = 0;
const uint32  LsMon_rMixtMinItrsvSenO2Ds_C = 0;
const uint8  HEATSENO2DSFONCDIAG_u8Inhib = 0;
const uint8  Ldsd_av_f_diag_fco_mAir_thd_g = 0;
const uint8  Ldsd_av_f_diag_fco_mAir_thresh = 0;
const uint8  Ldsd_av_f_diag_fld_mAir_thd_g = 0;
const uint8  Ldsd_av_f_diag_fld_mAir_thresh = 0;
const uint8  Ldsd_av_f_diag_obj_rich_thd_g = 0;
const uint8  Ldsd_av_f_diag_obj_rich_thresh = 0;
const sint16  Ldsd_av_f_diag_water_temp_thresh = 0;
const uint16  Ldsd_av_diag_delay_sensor_hot = 0;
const uint16  Ldsd_av_diag_delay_sensor_hot_g = 0;
const uint16  Ldsd_av_f_diag_fco_conf_delay = 0;
const uint16  Ldsd_av_f_diag_fco_thd_g = 0;
const uint16  Ldsd_av_f_diag_fco_thresh = 0;
const uint16  Ldsd_av_f_diag_fld_conf_delay = 0;
const uint16  Ldsd_av_f_diag_fld_thd_g = 0;
const uint16  Ldsd_av_f_diag_fld_thresh = 0;
const uint16  Ldsd_av_f_diag_max_delay = 0;
const uint16  Ldsd_av_f_diag_max_delay_gas = 0;
const uint16  Ldsd_av_f_diag_mf_emiss_thd_g = 0;
const uint16  Ldsd_av_f_diag_mf_emiss_thresh = 0;
const uint16  LsMon_tiCfmSenO2DsDiagFco_C = 0;
const uint16  LsMon_tiCfmSenO2DsDiagFld_C = 0;
const uint16  LsMon_tiRStrtItrsvFco_C = 0;
const uint16  LsMon_tiRStrtItrsvFld_C = 0;
const uint16  LsMon_uThdSenO2DsDiagFco_C = 0;
const uint16  LsMon_uThdSenO2DsDiagFcoGas_C = 0;
const uint16  LsMon_uThdSenO2DsDiagFld_C = 0;
const uint16  LsMon_uThdSenO2DsDiagFldGas_C = 0;
const uint16  SenO2Ds_tiInhDiag_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean HEATSENO2DSFONCDIAG_bAcvItDsDiag;
boolean HEATSENO2DSFONCDIAG_bAvItDsDgBva;
boolean HEATSENO2DSFONCDIAG_bEnTCataPrev;
boolean Ldsd_av_diag_cond;
boolean Ldsd_av_diag_intru_cond;
boolean Ldsd_av_ena_mode_defaut;
boolean Ldsd_av_fco;
boolean Ldsd_av_fco_no_failure;
boolean Ldsd_av_fld;
boolean Ldsd_av_fld_confirm;
boolean Ldsd_av_fld_failure;
boolean Ldsd_av_fld_no_failure;
boolean Ldsd_av_fld_or_fco;
boolean LsMon_bItrsvSenO2DsDiagDoneFco;
boolean LsMon_bItrsvSenO2DsDiagDoneFld;
boolean LsMon_bThdSenO2DsDiagFco;
boolean LsMon_bThdSenO2DsDiagFld;
boolean SenO2Ds_bAcvSeqDsPlausFld;
boolean SenO2Ds_bAcvSeqMemDsPlausFld;
boolean SenO2Ds_bDgoORng_DsPlausFco;
boolean SenO2Ds_bDgoORng_DsPlausFld;
boolean SenO2Ds_bMonRunORng_DsPlausFco;
boolean SenO2Ds_bMonRunORng_DsPlausFld;
boolean SenO2Ds_bMonRunRaw_DsPlausFco;
boolean SenO2Ds_bMonRunRaw_DsPlausFld;
boolean SenO2Ds_bMonWaitORng_DsPlausFco;
boolean SenO2Ds_bMonWaitORng_DsPlausFld;
boolean SenO2Ds_bMonWaitRaw_DsPlausFco;
boolean SenO2Ds_bMonWaitRaw_DsPlausFld;
uint32 HEATSENO2DSFONCDIAG_u32mAirCor;
uint8 HEATSENO2DSFONCDIAG_u8SysGasPrev;
uint8 LsMon_mfAirCorIntSenO2Ds;
uint16 Ldsd_av_diag_ai_count;
uint16 Ldsd_av_f_diag_confirm_count;
uint16 Ldsd_av_f_diag_count;
uint16 LsMon_tiCfmSenO2DsDiagFco;
uint16 LsMon_tiCfmSenO2DsDiagFld;
uint16 LsMon_tiRStrtItrsvFco;
uint16 LsMon_tiRStrtItrsvFld;
uint16 SenO2Ds_FcoPlausFacMax_Obd6Mod;
uint16 SenO2Ds_FcoPlausFacMaxRaw;
uint16 SenO2Ds_FcoPlausFacMes_Obd6Mod;
uint16 SenO2Ds_FcoPlausFacMesRaw;
uint16 SenO2Ds_FldPlausFacMes_Obd6Mod;
uint16 SenO2Ds_FldPlausFacMesRaw;
uint16 SenO2Ds_FldPlausFacMin_Obd6Mod;
uint16 SenO2Ds_FldPlausFacMinRaw;
uint16 SenO2Ds_tiInhDiag;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


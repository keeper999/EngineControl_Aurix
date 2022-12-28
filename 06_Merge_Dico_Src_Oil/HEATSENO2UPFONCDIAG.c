/***************************************************************************
;**
;** FILE NAME      : HEATSENO2UPFONCDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "HEATSENO2UPFONCDIAG.H"
#include "HEATSENO2UPFONCDIAG_L.H"
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
const boolean  Manu_inh_diag_am_max_delay = 0;
const boolean  Manu_inh_Ldsd_am_diag_norm_cond = 0;
const boolean  SenO2Us_bAcvEuro6UsPlausFco_C = 0;
const boolean  SenO2Us_bAcvEuro6UsPlausFld_C = 0;
const boolean  SenO2Us_bAcvSeqUsPlausFld_C = 0;
const boolean  SenO2Us_bInhDiagIdlCdn_C = 0;
const boolean  SenO2Us_bInhDiagPresScav_C = 0;
const boolean  SenO2Us_bInhMonWait_PlausFco_C = 0;
const boolean  SenO2Us_bInhMonWait_PlausFld_C = 0;
const uint8  HEATSENO2UPFONCDIAG_u8Inhib = 0;
const uint8  Ldsd_am_f_diag_fco_mAir_thd_g = 0;
const uint8  Ldsd_am_f_diag_fco_mAir_thresh = 0;
const uint8  Ldsd_am_f_diag_fld_mAir_thd_g = 0;
const uint8  Ldsd_am_f_diag_fld_mAir_thresh = 0;
const uint8  Ldsd_am_f_diag_obj_rich_thd_g = 0;
const uint8  Ldsd_am_f_diag_obj_rich_thresh = 0;
const uint8  SenO2Us_rOpCanPurgMax_C = 0;
const sint16  Ldsd_am_f_diag_water_temp_thd_g = 0;
const sint16  Ldsd_am_f_diag_water_temp_thresh = 0;
const uint16  Ldsd_am_diag_delay_sensor_hot = 0;
const uint16  Ldsd_am_diag_delay_sensor_hot_g = 0;
const uint16  Ldsd_am_f_diag_fco_conf_delay = 0;
const uint16  Ldsd_am_f_diag_fco_conf_g_delay = 0;
const uint16  Ldsd_am_f_diag_fco_thd_g = 0;
const uint16  Ldsd_am_f_diag_fco_thresh = 0;
const uint16  Ldsd_am_f_diag_fld_conf_delay = 0;
const uint16  Ldsd_am_f_diag_fld_conf_g_delay = 0;
const uint16  Ldsd_am_f_diag_fld_thd_g = 0;
const uint16  Ldsd_am_f_diag_fld_thresh = 0;
const uint16  Ldsd_am_f_diag_max_delay = 0;
const uint16  Ldsd_am_f_diag_mf_emiss_thd_g = 0;
const uint16  Ldsd_am_f_diag_mf_emiss_thresh = 0;
const uint16  LsMon_tiCfmSenO2UsDiag_C = 0;
const uint16  LsMon_uThdSenO2UsDiag_C = 0;
const uint16  LsMon_uThdSenO2UsDiagGas_C = 0;
const uint16  SenO2Us_tiInhDiag_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean HEATSENO2UPFONCDIAG_bEnTCataPrev;
boolean Ldsd_am_diag_cond;
boolean Ldsd_am_diag_norm_cond;
boolean Ldsd_am_ena_mode_defaut;
boolean Ldsd_am_fco;
boolean Ldsd_am_fld;
boolean Ldsd_am_fld_confirm;
boolean Ldsd_am_fld_failure;
boolean Ldsd_am_fld_or_fco;
boolean LsMon_bThdSenO2UsDiag;
boolean SenO2Us_bAcvSeqMemUsPlausFld;
boolean SenO2Us_bAcvSeqUsPlausFld;
boolean SenO2Us_bDgoORng_UsPlausFco;
boolean SenO2Us_bDgoORng_UsPlausFld;
boolean SenO2Us_bMonRunORng_UsPlausFco;
boolean SenO2Us_bMonRunORng_UsPlausFld;
boolean SenO2Us_bMonRunRaw_UsPlausFco;
boolean SenO2Us_bMonRunRaw_UsPlausFld;
boolean SenO2Us_bMonWaitORng_UsPlausFco;
boolean SenO2Us_bMonWaitORng_UsPlausFld;
boolean SenO2Us_bMonWaitRaw_UsPlausFco;
boolean SenO2Us_bMonWaitRaw_UsPlausFld;
uint32 HEATSENO2UPFONCDIAG_u32MfAirCor;
uint8 HEATSENO2UPFONCDIAG_u8SysGasPrev;
uint8 LsMon_mfAirCorIntSenO2Us;
uint16 Ldsd_am_diag_ai_count;
uint16 Ldsd_am_f_diag_confirm_count;
uint16 Ldsd_am_f_diag_count;
uint16 LsMon_tiCfmSenO2UsDiag;
uint16 SenO2Us_FcoPlausFacMax_Obd6Mod;
uint16 SenO2Us_FcoPlausFacMaxRaw;
uint16 SenO2Us_FcoPlausFacMes_Obd6Mod;
uint16 SenO2Us_FcoPlausFacMesRaw;
uint16 SenO2Us_FldPlausFacMes_Obd6Mod;
uint16 SenO2Us_FldPlausFacMesRaw;
uint16 SenO2Us_FldPlausFacMin_Obd6Mod;
uint16 SenO2Us_FldPlausFacMinRaw;
uint16 SenO2Us_tiInhDiag;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


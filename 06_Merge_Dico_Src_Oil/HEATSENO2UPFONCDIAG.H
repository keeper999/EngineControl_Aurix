/***************************************************************************
;**
;** FILE NAME      : HEATSENO2UPFONCDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2UPFONCDIAG_H
#define HEATSENO2UPFONCDIAG_H

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

extern const boolean  Manu_inh_diag_am_max_delay;
extern const boolean  Manu_inh_Ldsd_am_diag_norm_cond;
extern const boolean  SenO2Us_bAcvEuro6UsPlausFco_C;
extern const boolean  SenO2Us_bAcvEuro6UsPlausFld_C;
extern const boolean  SenO2Us_bAcvSeqUsPlausFld_C;
extern const boolean  SenO2Us_bInhDiagIdlCdn_C;
extern const boolean  SenO2Us_bInhDiagPresScav_C;
extern const boolean  SenO2Us_bInhMonWait_PlausFco_C;
extern const boolean  SenO2Us_bInhMonWait_PlausFld_C;
extern const uint8  Ldsd_am_f_diag_fco_mAir_thd_g;
extern const uint8  Ldsd_am_f_diag_fco_mAir_thresh;
extern const uint8  Ldsd_am_f_diag_fld_mAir_thd_g;
extern const uint8  Ldsd_am_f_diag_fld_mAir_thresh;
extern const uint8  Ldsd_am_f_diag_obj_rich_thd_g;
extern const uint8  Ldsd_am_f_diag_obj_rich_thresh;
extern const uint8  SenO2Us_rOpCanPurgMax_C;
extern const sint16  Ldsd_am_f_diag_water_temp_thd_g;
extern const sint16  Ldsd_am_f_diag_water_temp_thresh;
extern const uint16  Ldsd_am_diag_delay_sensor_hot;
extern const uint16  Ldsd_am_diag_delay_sensor_hot_g;
extern const uint16  Ldsd_am_f_diag_fco_conf_delay;
extern const uint16  Ldsd_am_f_diag_fco_conf_g_delay;
extern const uint16  Ldsd_am_f_diag_fco_thd_g;
extern const uint16  Ldsd_am_f_diag_fco_thresh;
extern const uint16  Ldsd_am_f_diag_fld_conf_delay;
extern const uint16  Ldsd_am_f_diag_fld_conf_g_delay;
extern const uint16  Ldsd_am_f_diag_fld_thd_g;
extern const uint16  Ldsd_am_f_diag_fld_thresh;
extern const uint16  Ldsd_am_f_diag_max_delay;
extern const uint16  Ldsd_am_f_diag_mf_emiss_thd_g;
extern const uint16  Ldsd_am_f_diag_mf_emiss_thresh;
extern const uint16  LsMon_tiCfmSenO2UsDiag_C;
extern const uint16  LsMon_uThdSenO2UsDiag_C;
extern const uint16  LsMon_uThdSenO2UsDiagGas_C;
extern const uint16  SenO2Us_tiInhDiag_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean SenO2Us_bAcvSeqMemUsPlausFld;
extern boolean SenO2Us_bAcvSeqUsPlausFld;
extern uint16 SenO2Us_FcoPlausFacMax_Obd6Mod;
extern uint16 SenO2Us_FcoPlausFacMes_Obd6Mod;
extern uint16 SenO2Us_FldPlausFacMes_Obd6Mod;
extern uint16 SenO2Us_FldPlausFacMin_Obd6Mod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SenO2Us_EveRst_UsPlaus(void);
void SenO2Us_SdlFast_UsPlaus(void);


#endif /* HEATSENO2UPFONCDIAG_H */

/*-------------------------------- end of file -------------------------------*/

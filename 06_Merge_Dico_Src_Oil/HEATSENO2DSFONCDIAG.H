/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DSFONCDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2DSFONCDIAG_H
#define HEATSENO2DSFONCDIAG_H

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

extern const boolean  LsMon_bAcvChkRMixtItrsv_C;
extern const boolean  LsMon_bManDiagFcoActiv_C;
extern const boolean  LsMon_bManDiagFldActiv_C;
extern const boolean  Manu_inh_diag_av_max_delay;
extern const boolean  Manu_inh_Ldsd_av_diag_intru_cond;
extern const boolean  SenO2Ds_bAcvEuro6DsPlausFco_C;
extern const boolean  SenO2Ds_bAcvEuro6DsPlausFld_C;
extern const boolean  SenO2Ds_bAcvSeqDsPlausFld_C;
extern const boolean  SenO2Ds_bInhDiagPresScav_C;
extern const boolean  SenO2Ds_bInhMonWait_PlausFco_C;
extern const boolean  SenO2Ds_bInhMonWait_PlausFld_C;
extern const uint32  LsMon_rMixtMaxItrsvSenO2Ds_C;
extern const uint32  LsMon_rMixtMinItrsvSenO2Ds_C;
extern const uint8  Ldsd_av_f_diag_fco_mAir_thd_g;
extern const uint8  Ldsd_av_f_diag_fco_mAir_thresh;
extern const uint8  Ldsd_av_f_diag_fld_mAir_thd_g;
extern const uint8  Ldsd_av_f_diag_fld_mAir_thresh;
extern const uint8  Ldsd_av_f_diag_obj_rich_thd_g;
extern const uint8  Ldsd_av_f_diag_obj_rich_thresh;
extern const sint16  Ldsd_av_f_diag_water_temp_thresh;
extern const uint16  Ldsd_av_diag_delay_sensor_hot;
extern const uint16  Ldsd_av_diag_delay_sensor_hot_g;
extern const uint16  Ldsd_av_f_diag_fco_conf_delay;
extern const uint16  Ldsd_av_f_diag_fco_thd_g;
extern const uint16  Ldsd_av_f_diag_fco_thresh;
extern const uint16  Ldsd_av_f_diag_fld_conf_delay;
extern const uint16  Ldsd_av_f_diag_fld_thd_g;
extern const uint16  Ldsd_av_f_diag_fld_thresh;
extern const uint16  Ldsd_av_f_diag_max_delay;
extern const uint16  Ldsd_av_f_diag_max_delay_gas;
extern const uint16  Ldsd_av_f_diag_mf_emiss_thd_g;
extern const uint16  Ldsd_av_f_diag_mf_emiss_thresh;
extern const uint16  LsMon_tiCfmSenO2DsDiagFco_C;
extern const uint16  LsMon_tiCfmSenO2DsDiagFld_C;
extern const uint16  LsMon_tiRStrtItrsvFco_C;
extern const uint16  LsMon_tiRStrtItrsvFld_C;
extern const uint16  LsMon_uThdSenO2DsDiagFco_C;
extern const uint16  LsMon_uThdSenO2DsDiagFcoGas_C;
extern const uint16  LsMon_uThdSenO2DsDiagFld_C;
extern const uint16  LsMon_uThdSenO2DsDiagFldGas_C;
extern const uint16  SenO2Ds_tiInhDiag_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean SenO2Ds_bAcvSeqDsPlausFld;
extern boolean SenO2Ds_bAcvSeqMemDsPlausFld;
extern uint16 SenO2Ds_FcoPlausFacMax_Obd6Mod;
extern uint16 SenO2Ds_FcoPlausFacMes_Obd6Mod;
extern uint16 SenO2Ds_FldPlausFacMes_Obd6Mod;
extern uint16 SenO2Ds_FldPlausFacMin_Obd6Mod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SenO2Ds_EveRst_DsPlaus(void);
void SenO2Ds_SdlMid_DsPlaus(void);


#endif /* HEATSENO2DSFONCDIAG_H */

/*-------------------------------- end of file -------------------------------*/

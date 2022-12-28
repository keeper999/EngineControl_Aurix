/***************************************************************************
;**
;** FILE NAME      : VLVACTINENDSTOP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTINENDSTOP.H"
#include "VLVACTINENDSTOP_L.H"
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
const boolean  VlvAct_bInLrnEndStopLimEna_C = 0;
const boolean  VlvAct_bInLrnFrstOfsAuthByp_C = 0;
const boolean  VlvAct_bInLrnFrstOfsAuthMan_C = 0;
const boolean  VlvAct_bInOfsFrstLrnByp_C = 0;
const boolean  VlvAct_bInOfsFrstLrnMan_C = 0;
const boolean  VlvAct_bInOfsFrstLrnWouDftMan_C = 0;
const boolean  VlvAct_bInOfsFrstLrnWoutDftByp_C = 0;
const boolean  VlvAct_bInOfsFrstLrnWoutDftMod_C = 0;
const boolean  Vta_intake_cam_offsets_manu_inh = 0;
const boolean  Vta_intake_force_off_learning = 0;
const boolean  Vta_intake_run_learning_dsb = 0;
const uint8  Kfvcpi_k_offset_filter = 0;
const uint8  VlvAct_nEngInLrnThdHiFrst_C = 0;
const uint8  VlvAct_nEngInLrnThdHiFrstHys_C = 0;
const uint8  VlvAct_nEngInLrnThdLoDiag_C = 0;
const uint8  VlvAct_nEngInLrnThdLoFrst_C = 0;
const uint8  VlvAct_nEngInLrnThdLoFrstHys_C = 0;
const uint8  VlvAct_noInLrnCntMin_C = 0;
const uint8  VlvAct_noOfsInValConfThd_C = 0;
const uint8  VLVACTINENDSTOP_u8Inhib = 0;
const uint8  Vta_intake_min_reg = 0;
const sint16  VlvAct_tCoInLrnThdHiFrst_C = 0;
const sint16  VlvAct_tCoInLrnThdHiFrstHys_C = 0;
const sint16  VlvAct_tCoInLrnThdLoFrst_C = 0;
const sint16  VlvAct_tCoInLrnThdLoFrstHys_C = 0;
const sint16  VlvAct_tOilInLrnThdHiFrst_C = 0;
const sint16  VlvAct_tOilInLrnThdHiFrstHys_C = 0;
const sint16  VlvAct_tOilInLrnThdLoFrst_C = 0;
const sint16  VlvAct_tOilInLrnThdLoFrstHys_C = 0;
const uint16  Kcvcpi_learn_zero_offsets = 0;
const uint16  Kfvcpi_t_offset_learn_delay = 0;
const uint16  Kfvcpi_t_zero_set_time = 0;
const uint16  VlvAct_agInMesLrnLim_C = 0;
const uint16  VlvAct_CtInLrnEndStopRelzdThd_C = 0;
const uint16  VlvAct_InCmdMinLrnValThd_C = 0;
const uint16  VlvAct_noFaiLrnInThd_C = 0;
const uint16  Vta_intake_learn_delay = 0;
const uint16  Vta_intake_off_margin = 0;
const uint16  Vta_intake_old_off_margin = 0;
const uint16  Vta_intake_reference_angle[VTA_INTAKE_REFERENCE_ANGLE_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Ext_stAgCmInAdapt;
uint8 Ext_stAgCmInFrstAdapt;
boolean Eep_dem_ecr_obj_objet_vvt;
boolean Ena_bInOfsFrstLrnWouDft;
boolean Vbx_pf_vta_intake;
boolean Vbx_vvtc_X_toth_learn_dft;
boolean Vcpi_cam_offsets_are_learned;
boolean VlvAct_bDgoEndStopOldVlvActIn;
boolean VlvAct_bDgoLrnEndStopVlvActIn;
boolean VlvAct_bDgoLrnFaiLimVlvActIn;
boolean VlvAct_bDgoOldLrnVlvActIn;
boolean VlvAct_bInFrstClnAuth;
boolean VlvAct_bInLrnFrstOfsAuth;
boolean VlvAct_bInOfsClcnInh;
boolean VlvAct_bInOfsFrstLrn;
boolean VlvAct_bInOfsFrstLrnWouDft;
boolean VlvAct_bInOfsLrnDone;
boolean VlvAct_bInRunLrnAuth;
boolean VlvAct_bMonRunEndStopOldVlvActIn;
boolean VlvAct_bMonRunLrnEndStopVlvActIn;
boolean VlvAct_bMonRunLrnFaiLimVlvActIn;
boolean VlvAct_bMonRunOldLrnVlvActIn;
boolean VLVACTINENDSTOP_bFrstHystOut01;
boolean VLVACTINENDSTOP_bFrstHystOut02;
boolean VLVACTINENDSTOP_bFrstHystOut03;
boolean VLVACTINENDSTOP_bFrstHystOut04;
boolean VLVACTINENDSTOP_bFrstHystOut05;
boolean VLVACTINENDSTOP_bFrstHystOut06;
boolean VLVACTINENDSTOP_bIni2ndTimerPrev;
boolean VLVACTINENDSTOP_bIntakeOffPrev;
boolean VLVACTINENDSTOP_bIntAllowLng;
boolean VLVACTINENDSTOP_bMotSyncPrev;
boolean VLVACTINENDSTOP_bOffLearnPrev;
boolean VLVACTINENDSTOP_bTimeOut1;
boolean VLVACTINENDSTOP_bTimeOut2;
boolean Vta_intake_allow_delay;
boolean Vta_intake_allow_learning;
boolean Vta_intake_allow_run_learning;
boolean Vta_intake_hot_learning;
boolean Vta_intake_hot_offsets;
boolean Vta_intake_inh_old_off_eep;
boolean Vta_intake_learn_failure;
uint32 VlvAct_AgOfsInValAdd[VLVACT_AGOFSINVALADD_COLS];
uint32 VLVACTINENDSTOP_u32FiltreCamMem0;
uint32 VLVACTINENDSTOP_u32FiltreCamMem1;
uint32 VLVACTINENDSTOP_u32FiltreCamMem2;
uint32 VLVACTINENDSTOP_u32FiltreCamMem3;
uint8 Vcpi_learn_zero_counter;
uint8 VlvAct_CtOfsInConf;
uint16 VlvAct_CtInLrnEndStopFai;
uint16 VlvAct_CtInLrnEndStopRelzd;
uint16 VLVACTINENDSTOP_u16Timer1;
uint16 VLVACTINENDSTOP_u16Timer2;
uint16 Vta_intake_cam_off_mes[VTA_INTAKE_CAM_OFF_MES_COLS];
uint16 Vta_intake_cam_off_mes_av[VTA_INTAKE_CAM_OFF_MES_AV_COLS];
uint16 Vta_intake_cam_old_off_eep[VTA_INTAKE_CAM_OLD_OFF_EEP_COLS];
uint16 Vta_intake_learn_tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


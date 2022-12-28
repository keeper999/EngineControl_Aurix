/***************************************************************************
;**
;** FILE NAME      : VLVACTEXENDSTOP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTEXENDSTOP.H"
#include "VLVACTEXENDSTOP_L.H"
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
const boolean  VlvAct_bExLrnEndStopLimEna_C = 0;
const boolean  VlvAct_bExLrnFrstOfsAuthByp_C = 0;
const boolean  VlvAct_bExLrnFrstOfsAuthMan_C = 0;
const boolean  VlvAct_bExOfsFrstLrnByp_C = 0;
const boolean  VlvAct_bExOfsFrstLrnMan_C = 0;
const boolean  VlvAct_bExOfsFrstLrnWouDftByp_C = 0;
const boolean  VlvAct_bExOfsFrstLrnWouDftMan_C = 0;
const boolean  VlvAct_bExOfsFrstLrnWoutDftMod_C = 0;
const boolean  Vta_exhaust_cam_offsets_manu_inh = 0;
const boolean  Vta_exhaust_force_off_learning = 0;
const boolean  Vta_exhaust_run_learning_dsb = 0;
const uint8  Kfvcpe_k_offset_filter = 0;
const uint8  VlvAct_nEngExLrnThdHiFrst_C = 0;
const uint8  VlvAct_nEngExLrnThdHiFrstHys_C = 0;
const uint8  VlvAct_nEngExLrnThdLoDiag_C = 0;
const uint8  VlvAct_nEngExLrnThdLoFrst_C = 0;
const uint8  VlvAct_nEngExLrnThdLoFrstHys_C = 0;
const uint8  VlvAct_noExLrnCntMin_C = 0;
const uint8  VlvAct_noOfsExValConfThd_C = 0;
const uint8  VLVACTEXENDSTOP_u8Inhib = 0;
const uint8  Vta_exhaust_min_reg = 0;
const sint16  VlvAct_tCoExLrnThdHiFrst_C = 0;
const sint16  VlvAct_tCoExLrnThdHiFrstHys_C = 0;
const sint16  VlvAct_tCoExLrnThdLoFrst_C = 0;
const sint16  VlvAct_tCoExLrnThdLoFrstHys_C = 0;
const sint16  VlvAct_tOilExLrnThdHiFrst_C = 0;
const sint16  VlvAct_tOilExLrnThdHiFrstHys_C = 0;
const sint16  VlvAct_tOilExLrnThdLoFrst_C = 0;
const sint16  VlvAct_tOilExLrnThdLoFrstHys_C = 0;
const uint16  Kcvcpe_learn_zero_offsets = 0;
const uint16  Kfvcpe_t_offset_learn_delay = 0;
const uint16  Kfvcpe_t_zero_set_time = 0;
const uint16  VlvAct_agExMesLrnLim_C = 0;
const uint16  VlvAct_CtExLrnEndStopRelzdThd_C = 0;
const uint16  VlvAct_ExCmdMinLrnValThd_C = 0;
const uint16  VlvAct_noFaiLrnExThd_C = 0;
const uint16  Vta_exhaust_learn_delay = 0;
const uint16  Vta_exhaust_off_margin = 0;
const uint16  Vta_exhaust_old_off_margin = 0;
const uint16  Vta_exhaust_reference_angle[VTA_EXHAUST_REFERENCE_ANGLE_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Ext_stAgCmExAdapt;
uint8 Ext_stAgCmExFrstAdapt;
boolean Eep_dem_ecr_obj_objet_vvt2;
boolean Vbx_pf_vta_exhaust;
boolean Vbx_vvtc_X_toth_learn_dft2;
boolean Vcpe_cam_offsets_are_learned;
boolean VlvAct_bDgoEndStopOldVlvActEx;
boolean VlvAct_bDgoLrnEndStopVlvActEx;
boolean VlvAct_bDgoLrnFaiLimVlvActEx;
boolean VlvAct_bDgoOldLrnVlvActEx;
boolean VlvAct_bExFrstClnAuth;
boolean VlvAct_bExLrnFrstOfsAuth;
boolean VlvAct_bExOfsClcnInh;
boolean VlvAct_bExOfsFrstLrn;
boolean VlvAct_bExOfsFrstLrnWouDft;
boolean VlvAct_bExOfsLrnDone;
boolean VlvAct_bExRunLrnAuth;
boolean VlvAct_bMonRunEndStopOldVlvActEx;
boolean VlvAct_bMonRunLrnEndStopVlvActEx;
boolean VlvAct_bMonRunLrnFaiLimVlvActEx;
boolean VlvAct_bMonRunOldLrnVlvActEx;
boolean VLVACTEXENDSTOP_bExhaustOffPrev;
boolean VLVACTEXENDSTOP_bExtAllowLng;
boolean VLVACTEXENDSTOP_bFrstHystOut01;
boolean VLVACTEXENDSTOP_bFrstHystOut02;
boolean VLVACTEXENDSTOP_bFrstHystOut03;
boolean VLVACTEXENDSTOP_bFrstHystOut04;
boolean VLVACTEXENDSTOP_bFrstHystOut05;
boolean VLVACTEXENDSTOP_bFrstHystOut06;
boolean VLVACTEXENDSTOP_bIni2ndTimerPrev;
boolean VLVACTEXENDSTOP_bMotSyncPrev;
boolean VLVACTEXENDSTOP_bOffLearnPrev;
boolean VLVACTEXENDSTOP_bTimeOut1;
boolean VLVACTEXENDSTOP_bTimeOut2;
boolean Vta_exhaust_allow_delay;
boolean Vta_exhaust_allow_learning;
boolean Vta_exhaust_allow_run_learning;
boolean Vta_exhaust_hot_learning;
boolean Vta_exhaust_hot_offsets;
boolean Vta_exhaust_inh_old_off_eep;
boolean Vta_exhaust_learn_failure;
uint32 VlvAct_AgOfsExValAdd[VLVACT_AGOFSEXVALADD_COLS];
uint32 VLVACTEXENDSTOP_u32FiltreCamMem0;
uint32 VLVACTEXENDSTOP_u32FiltreCamMem1;
uint32 VLVACTEXENDSTOP_u32FiltreCamMem2;
uint32 VLVACTEXENDSTOP_u32FiltreCamMem3;
uint8 Vcpe_learn_zero_counter;
uint8 VlvAct_CtOfsExConf;
uint16 VlvAct_CtExLrnEndStopFai;
uint16 VlvAct_CtExLrnEndStopRelzd;
uint16 VLVACTEXENDSTOP_u16Timer1;
uint16 VLVACTEXENDSTOP_u16Timer2;
uint16 Vta_exhaust_cam_off_mes[VTA_EXHAUST_CAM_OFF_MES_COLS];
uint16 Vta_exhaust_cam_off_mes_av[VTA_EXHAUST_CAM_OFF_MES_AV_COLS];
uint16 Vta_exhaust_cam_old_off_eep[VTA_EXHAUST_CAM_OLD_OFF_EEP_COLS];
uint16 Vta_exhaust_learn_tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


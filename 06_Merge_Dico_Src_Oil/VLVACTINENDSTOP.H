/***************************************************************************
;**
;** FILE NAME      : VLVACTINENDSTOP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINENDSTOP_H
#define VLVACTINENDSTOP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VCPI_CAM_OFFSETS_COLS                  ( 4 )
#define VTA_INTAKE_REFERENCE_ANGLE_COLS        ( 4 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st62 */
#define VLVACT_ST_INLRN_NOTDONE           0
#define VLVACT_ST_INLRN_DONE              1
#define VLVACT_ST_INLRN_RUN               2
/*extern uint8 Ext_stAgCmInAdapt;*/

/* enum st116 */
#define VLVACT_ST_INFRSTLRN_NOTDONE       0
#define VLVACT_ST_INFRSTLRN_DONE          1
#define VLVACT_ST_INFRSTLRN_RUN           2
/*extern uint8 Ext_stAgCmInFrstAdapt;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  VlvAct_bInLrnEndStopLimEna_C;
extern const boolean  VlvAct_bInLrnFrstOfsAuthByp_C;
extern const boolean  VlvAct_bInLrnFrstOfsAuthMan_C;
extern const boolean  VlvAct_bInOfsFrstLrnByp_C;
extern const boolean  VlvAct_bInOfsFrstLrnMan_C;
extern const boolean  VlvAct_bInOfsFrstLrnWouDftMan_C;
extern const boolean  VlvAct_bInOfsFrstLrnWoutDftByp_C;
extern const boolean  VlvAct_bInOfsFrstLrnWoutDftMod_C;
extern const boolean  Vta_intake_cam_offsets_manu_inh;
extern const boolean  Vta_intake_force_off_learning;
extern const boolean  Vta_intake_run_learning_dsb;
extern const uint8  Kfvcpi_k_offset_filter;
extern const uint8  VlvAct_nEngInLrnThdHiFrst_C;
extern const uint8  VlvAct_nEngInLrnThdHiFrstHys_C;
extern const uint8  VlvAct_nEngInLrnThdLoDiag_C;
extern const uint8  VlvAct_nEngInLrnThdLoFrst_C;
extern const uint8  VlvAct_nEngInLrnThdLoFrstHys_C;
extern const uint8  VlvAct_noInLrnCntMin_C;
extern const uint8  VlvAct_noOfsInValConfThd_C;
extern const uint8  Vta_intake_min_reg;
extern const sint16  VlvAct_tCoInLrnThdHiFrst_C;
extern const sint16  VlvAct_tCoInLrnThdHiFrstHys_C;
extern const sint16  VlvAct_tCoInLrnThdLoFrst_C;
extern const sint16  VlvAct_tCoInLrnThdLoFrstHys_C;
extern const sint16  VlvAct_tOilInLrnThdHiFrst_C;
extern const sint16  VlvAct_tOilInLrnThdHiFrstHys_C;
extern const sint16  VlvAct_tOilInLrnThdLoFrst_C;
extern const sint16  VlvAct_tOilInLrnThdLoFrstHys_C;
extern const uint16  Kcvcpi_learn_zero_offsets;
extern const uint16  Kfvcpi_t_offset_learn_delay;
extern const uint16  Kfvcpi_t_zero_set_time;
extern const uint16  VlvAct_agInMesLrnLim_C;
extern const uint16  VlvAct_CtInLrnEndStopRelzdThd_C;
extern const uint16  VlvAct_InCmdMinLrnValThd_C;
extern const uint16  VlvAct_noFaiLrnInThd_C;
extern const uint16  Vta_intake_learn_delay;
extern const uint16  Vta_intake_off_margin;
extern const uint16  Vta_intake_old_off_margin;
extern const uint16  Vta_intake_reference_angle[VTA_INTAKE_REFERENCE_ANGLE_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Ext_stAgCmInAdapt;
extern uint8 Ext_stAgCmInFrstAdapt;
extern boolean Vcpi_cam_offsets_are_learned;
extern boolean VlvAct_bInFrstClnAuth;
extern boolean VlvAct_bInLrnFrstOfsAuth;
extern boolean VlvAct_bInOfsClcnInh;
extern boolean VlvAct_bInOfsFrstLrn;
extern boolean VlvAct_bInOfsFrstLrnWouDft;
extern boolean Vta_intake_allow_learning;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveCkSnOn_InEndStop(void);
void VlvAct_EveInCmToo_InEndStop(void);
void VlvAct_EveKOn_InEndStop(void);
void VlvAct_EvePwrl_InEndStop(void);
void VlvAct_EveRst_InEndStop(void);
void VlvAct_EveRstVVT_InEndStop(void);
void VlvAct_SdlFast_InEndStop(void);
void VlvAct_SdlSlow_InEndStop(void);


#endif /* VLVACTINENDSTOP_H */

/*-------------------------------- end of file -------------------------------*/

/***************************************************************************
;**
;** FILE NAME      : VLVACTEXENDSTOP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXENDSTOP_H
#define VLVACTEXENDSTOP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VCPE_CAM_OFFSETS_COLS                  ( 4 )
#define VLVACT_ST_EXFRSTLRN_DONE          1
#define VLVACT_ST_EXFRSTLRN_NOTDONE       0
#define VLVACT_ST_EXFRSTLRN_RUN           2
#define VLVACT_ST_EXLRN_DONE              1
#define VLVACT_ST_EXLRN_NOTDONE           0
#define VLVACT_ST_EXLRN_RUN               2
#define VTA_EXHAUST_REFERENCE_ANGLE_COLS       ( 4 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st17 */
/*extern uint8 Ext_stAgCmExAdapt;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  VlvAct_bExLrnEndStopLimEna_C;
extern const boolean  VlvAct_bExLrnFrstOfsAuthByp_C;
extern const boolean  VlvAct_bExLrnFrstOfsAuthMan_C;
extern const boolean  VlvAct_bExOfsFrstLrnByp_C;
extern const boolean  VlvAct_bExOfsFrstLrnMan_C;
extern const boolean  VlvAct_bExOfsFrstLrnWouDftByp_C;
extern const boolean  VlvAct_bExOfsFrstLrnWouDftMan_C;
extern const boolean  VlvAct_bExOfsFrstLrnWoutDftMod_C;
extern const boolean  Vta_exhaust_cam_offsets_manu_inh;
extern const boolean  Vta_exhaust_force_off_learning;
extern const boolean  Vta_exhaust_run_learning_dsb;
extern const uint8  Kfvcpe_k_offset_filter;
extern const uint8  VlvAct_nEngExLrnThdHiFrst_C;
extern const uint8  VlvAct_nEngExLrnThdHiFrstHys_C;
extern const uint8  VlvAct_nEngExLrnThdLoDiag_C;
extern const uint8  VlvAct_nEngExLrnThdLoFrst_C;
extern const uint8  VlvAct_nEngExLrnThdLoFrstHys_C;
extern const uint8  VlvAct_noExLrnCntMin_C;
extern const uint8  VlvAct_noOfsExValConfThd_C;
extern const uint8  Vta_exhaust_min_reg;
extern const sint16  VlvAct_tCoExLrnThdHiFrst_C;
extern const sint16  VlvAct_tCoExLrnThdHiFrstHys_C;
extern const sint16  VlvAct_tCoExLrnThdLoFrst_C;
extern const sint16  VlvAct_tCoExLrnThdLoFrstHys_C;
extern const sint16  VlvAct_tOilExLrnThdHiFrst_C;
extern const sint16  VlvAct_tOilExLrnThdHiFrstHys_C;
extern const sint16  VlvAct_tOilExLrnThdLoFrst_C;
extern const sint16  VlvAct_tOilExLrnThdLoFrstHys_C;
extern const uint16  Kcvcpe_learn_zero_offsets;
extern const uint16  Kfvcpe_t_offset_learn_delay;
extern const uint16  Kfvcpe_t_zero_set_time;
extern const uint16  VlvAct_agExMesLrnLim_C;
extern const uint16  VlvAct_CtExLrnEndStopRelzdThd_C;
extern const uint16  VlvAct_ExCmdMinLrnValThd_C;
extern const uint16  VlvAct_noFaiLrnExThd_C;
extern const uint16  Vta_exhaust_learn_delay;
extern const uint16  Vta_exhaust_off_margin;
extern const uint16  Vta_exhaust_old_off_margin;
extern const uint16  Vta_exhaust_reference_angle[VTA_EXHAUST_REFERENCE_ANGLE_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Ext_stAgCmExAdapt;
extern uint8 Ext_stAgCmExFrstAdapt;
extern boolean Vcpe_cam_offsets_are_learned;
extern boolean VlvAct_bExFrstClnAuth;
extern boolean VlvAct_bExLrnFrstOfsAuth;
extern boolean VlvAct_bExOfsClcnInh;
extern boolean VlvAct_bExOfsFrstLrn;
extern boolean VlvAct_bExOfsFrstLrnWouDft;
extern boolean Vta_exhaust_allow_learning;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveCkSnOn_ExEndStop(void);
void VlvAct_EveExCmToo_ExEndStop(void);
void VlvAct_EveKOn_ExEndStop(void);
void VlvAct_EvePwrl_ExEndStop(void);
void VlvAct_EveRst_ExEndStop(void);
void VlvAct_EveRstVVT_ExEndStop(void);
void VlvAct_SdlFast_ExEndStop(void);
void VlvAct_SdlSlow_ExEndStop(void);


#endif /* VLVACTEXENDSTOP_H */

/*-------------------------------- end of file -------------------------------*/

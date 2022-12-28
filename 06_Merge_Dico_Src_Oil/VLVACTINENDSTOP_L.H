/***************************************************************************
;**
;** FILE NAME      : VLVACTINENDSTOP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINENDSTOP_L_H
#define VLVACTINENDSTOP_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_AGOFSINVALADD_COLS              ( 4 )
#define VLVACTINENDSTOP_u8OFFLENGTH       4
#define VTA_INTAKE_CAM_OFF_MES_COLS            ( 4 )
#define VTA_INTAKE_CAM_OFF_MES_AV_COLS         ( 4 )
#define VTA_INTAKE_CAM_OLD_OFF_EEP_COLS        ( 4 )

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

extern const uint8  VLVACTINENDSTOP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Eep_dem_ecr_obj_objet_vvt;
extern boolean Ena_bInOfsFrstLrnWouDft;
extern boolean Vbx_pf_vta_intake;
extern boolean Vbx_vvtc_X_toth_learn_dft;
extern boolean VlvAct_bDgoEndStopOldVlvActIn;
extern boolean VlvAct_bDgoLrnEndStopVlvActIn;
extern boolean VlvAct_bDgoLrnFaiLimVlvActIn;
extern boolean VlvAct_bDgoOldLrnVlvActIn;
extern boolean VlvAct_bInOfsLrnDone;
extern boolean VlvAct_bInRunLrnAuth;
extern boolean VlvAct_bMonRunEndStopOldVlvActIn;
extern boolean VlvAct_bMonRunLrnEndStopVlvActIn;
extern boolean VlvAct_bMonRunLrnFaiLimVlvActIn;
extern boolean VlvAct_bMonRunOldLrnVlvActIn;
extern boolean VLVACTINENDSTOP_bFrstHystOut01;
extern boolean VLVACTINENDSTOP_bFrstHystOut02;
extern boolean VLVACTINENDSTOP_bFrstHystOut03;
extern boolean VLVACTINENDSTOP_bFrstHystOut04;
extern boolean VLVACTINENDSTOP_bFrstHystOut05;
extern boolean VLVACTINENDSTOP_bFrstHystOut06;
extern boolean VLVACTINENDSTOP_bIni2ndTimerPrev;
extern boolean VLVACTINENDSTOP_bIntakeOffPrev;
extern boolean VLVACTINENDSTOP_bIntAllowLng;
extern boolean VLVACTINENDSTOP_bMotSyncPrev;
extern boolean VLVACTINENDSTOP_bOffLearnPrev;
extern boolean VLVACTINENDSTOP_bTimeOut1;
extern boolean VLVACTINENDSTOP_bTimeOut2;
extern boolean Vta_intake_allow_delay;
extern boolean Vta_intake_allow_run_learning;
extern boolean Vta_intake_hot_learning;
extern boolean Vta_intake_hot_offsets;
extern boolean Vta_intake_inh_old_off_eep;
extern boolean Vta_intake_learn_failure;
extern uint32 VlvAct_AgOfsInValAdd[VLVACT_AGOFSINVALADD_COLS];
extern uint32 VLVACTINENDSTOP_u32FiltreCamMem0;
extern uint32 VLVACTINENDSTOP_u32FiltreCamMem1;
extern uint32 VLVACTINENDSTOP_u32FiltreCamMem2;
extern uint32 VLVACTINENDSTOP_u32FiltreCamMem3;
extern uint8 Vcpi_learn_zero_counter;
extern uint8 VlvAct_CtOfsInConf;
extern uint16 VlvAct_CtInLrnEndStopFai;
extern uint16 VlvAct_CtInLrnEndStopRelzd;
extern uint16 VLVACTINENDSTOP_u16Timer1;
extern uint16 VLVACTINENDSTOP_u16Timer2;
extern uint16 Vta_intake_cam_off_mes[VTA_INTAKE_CAM_OFF_MES_COLS];
extern uint16 Vta_intake_cam_off_mes_av[VTA_INTAKE_CAM_OFF_MES_AV_COLS];
extern uint16 Vta_intake_cam_old_off_eep[VTA_INTAKE_CAM_OLD_OFF_EEP_COLS];
extern uint16 Vta_intake_learn_tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTINENDSTOP_IntOffIndUpdate(void);
void VLVACTINENDSTOP_IntOffIndUpdate1(void);
void VLVACTINENDSTOP_vidEepromWrite(void);
void VLVACTINENDSTOP_vidFrstOffLrnCon(void);
void VLVACTINENDSTOP_vidFrtLrnWtDfCpt(void);
void VLVACTINENDSTOP_vidInitDiagSrv(void);
void VLVACTINENDSTOP_vidInitFailure(void);
void VLVACTINENDSTOP_vidInitOutput(void);
void VLVACTINENDSTOP_vidInOffReset(void);
void VLVACTINENDSTOP_vidInOffsets(void);
void VLVACTINENDSTOP_vidIntakeOff(void);
void VLVACTINENDSTOP_vidIntAllowLearn(void);
void VLVACTINENDSTOP_vidIntAllowLrng(void);
void VLVACTINENDSTOP_vidLearningDiag(void);
void VLVACTINENDSTOP_vidLearningReset(void);
void VLVACTINENDSTOP_vidLstLrnTmpCntr(void);
void VLVACTINENDSTOP_vidMemoirisaCond(void);
void VLVACTINENDSTOP_vidMemoirisation(void);
void VLVACTINENDSTOP_vidOffAvrgComp(void);
void VLVACTINENDSTOP_vidOffCons(void);
void VLVACTINENDSTOP_vidOffLrnErrDet(uint16 u16Margin,uint16 *u16IntakeAngle,uint16 *u16OffMes ,boolean *bErrDet);
void VLVACTINENDSTOP_vidOffsetsReset(void);
void VLVACTINENDSTOP_vidPrevOfLrnErDt(void);
void VLVACTINENDSTOP_vidReset(void);


#endif /* VLVACTINENDSTOP_L_H */

/*-------------------------------- end of file -------------------------------*/

/***************************************************************************
;**
;** FILE NAME      : VLVACTEXENDSTOP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXENDSTOP_L_H
#define VLVACTEXENDSTOP_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_AGOFSEXVALADD_COLS              ( 4 )
#define VLVACTEXENDSTOP_u8OFFLENGTH       4
#define VTA_EXHAUST_CAM_OFF_MES_COLS           ( 4 )
#define VTA_EXHAUST_CAM_OFF_MES_AV_COLS        ( 4 )
#define VTA_EXHAUST_CAM_OLD_OFF_EEP_COLS       ( 4 )

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

extern const uint8  VLVACTEXENDSTOP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Eep_dem_ecr_obj_objet_vvt2;
extern boolean Vbx_pf_vta_exhaust;
extern boolean Vbx_vvtc_X_toth_learn_dft2;
extern boolean VlvAct_bDgoEndStopOldVlvActEx;
extern boolean VlvAct_bDgoLrnEndStopVlvActEx;
extern boolean VlvAct_bDgoLrnFaiLimVlvActEx;
extern boolean VlvAct_bDgoOldLrnVlvActEx;
extern boolean VlvAct_bExOfsLrnDone;
extern boolean VlvAct_bExRunLrnAuth;
extern boolean VlvAct_bMonRunEndStopOldVlvActEx;
extern boolean VlvAct_bMonRunLrnEndStopVlvActEx;
extern boolean VlvAct_bMonRunLrnFaiLimVlvActEx;
extern boolean VlvAct_bMonRunOldLrnVlvActEx;
extern boolean VLVACTEXENDSTOP_bExhaustOffPrev;
extern boolean VLVACTEXENDSTOP_bExtAllowLng;
extern boolean VLVACTEXENDSTOP_bFrstHystOut01;
extern boolean VLVACTEXENDSTOP_bFrstHystOut02;
extern boolean VLVACTEXENDSTOP_bFrstHystOut03;
extern boolean VLVACTEXENDSTOP_bFrstHystOut04;
extern boolean VLVACTEXENDSTOP_bFrstHystOut05;
extern boolean VLVACTEXENDSTOP_bFrstHystOut06;
extern boolean VLVACTEXENDSTOP_bIni2ndTimerPrev;
extern boolean VLVACTEXENDSTOP_bMotSyncPrev;
extern boolean VLVACTEXENDSTOP_bOffLearnPrev;
extern boolean VLVACTEXENDSTOP_bTimeOut1;
extern boolean VLVACTEXENDSTOP_bTimeOut2;
extern boolean Vta_exhaust_allow_delay;
extern boolean Vta_exhaust_allow_run_learning;
extern boolean Vta_exhaust_hot_learning;
extern boolean Vta_exhaust_hot_offsets;
extern boolean Vta_exhaust_inh_old_off_eep;
extern boolean Vta_exhaust_learn_failure;
extern uint32 VlvAct_AgOfsExValAdd[VLVACT_AGOFSEXVALADD_COLS];
extern uint32 VLVACTEXENDSTOP_u32FiltreCamMem0;
extern uint32 VLVACTEXENDSTOP_u32FiltreCamMem1;
extern uint32 VLVACTEXENDSTOP_u32FiltreCamMem2;
extern uint32 VLVACTEXENDSTOP_u32FiltreCamMem3;
extern uint8 Vcpe_learn_zero_counter;
extern uint8 VlvAct_CtOfsExConf;
extern uint16 VlvAct_CtExLrnEndStopFai;
extern uint16 VlvAct_CtExLrnEndStopRelzd;
extern uint16 VLVACTEXENDSTOP_u16Timer1;
extern uint16 VLVACTEXENDSTOP_u16Timer2;
extern uint16 Vta_exhaust_cam_off_mes[VTA_EXHAUST_CAM_OFF_MES_COLS];
extern uint16 Vta_exhaust_cam_off_mes_av[VTA_EXHAUST_CAM_OFF_MES_AV_COLS];
extern uint16 Vta_exhaust_cam_old_off_eep[VTA_EXHAUST_CAM_OLD_OFF_EEP_COLS];
extern uint16 Vta_exhaust_learn_tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTEXENDSTOP_ExtOffIndUpdate(void);
void VLVACTEXENDSTOP_ExtOffIndUpdate1(void);
void VLVACTEXENDSTOP_vidEepromWrite(void);
void VLVACTEXENDSTOP_vidExhaustOff(void);
void VLVACTEXENDSTOP_vidExOffReset(void);
void VLVACTEXENDSTOP_vidExOffsets(void);
void VLVACTEXENDSTOP_vidExtAllowLearn(void);
void VLVACTEXENDSTOP_vidExtAllowLrng(void);
void VLVACTEXENDSTOP_vidFrstOffLrnCon(void);
void VLVACTEXENDSTOP_vidFrtLrnWtDfCpt(void);
void VLVACTEXENDSTOP_vidInitDiagSrv(void);
void VLVACTEXENDSTOP_vidInitFailure(void);
void VLVACTEXENDSTOP_vidInitOutput(void);
void VLVACTEXENDSTOP_vidLearningDiag(void);
void VLVACTEXENDSTOP_vidLearningReset(void);
void VLVACTEXENDSTOP_vidLstLrnTmpCntr(void);
void VLVACTEXENDSTOP_vidMemoirisaCond(void);
void VLVACTEXENDSTOP_vidMemoirisation(void);
void VLVACTEXENDSTOP_vidOffAvrgComp(void);
void VLVACTEXENDSTOP_vidOffCons(void);
void VLVACTEXENDSTOP_vidOffLrnErrDet(uint16 u16Margin,uint16 *u16ExhaustAngle,uint16 *u16OffMes,boolean *bErrDet);
void VLVACTEXENDSTOP_vidOffsetsReset(void);
void VLVACTEXENDSTOP_vidPrvLrnErDetec(void);
void VLVACTEXENDSTOP_vidReset(void);


#endif /* VLVACTEXENDSTOP_L_H */

/*-------------------------------- end of file -------------------------------*/

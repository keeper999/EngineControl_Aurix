/***************************************************************************
;**
;** FILE NAME      : THRPOSMES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRPOSMES_L_H
#define THRPOSMES_L_H

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

extern const uint8  THRPOSMES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoDftSenr_Thr;
extern boolean Ext_bMonRunDftSenr_Thr;
extern boolean Thr_bDgoCohPosnSnsr;
extern boolean Thr_bDgoScgPosnSnsr1;
extern boolean Thr_bDgoScgPosnSnsr2;
extern boolean Thr_bDgoScpPosnSnsr1;
extern boolean Thr_bDgoScpPosnSnsr2;
extern boolean Thr_bMonRunCohPosnSnsr;
extern boolean Thr_bMonRunScgPosnSnsr1;
extern boolean Thr_bMonRunScgPosnSnsr2;
extern boolean Thr_bMonRunScpPosnSnsr1;
extern boolean Thr_bMonRunScpPosnSnsr2;
extern boolean Thr_bMonWaitCohPosnSnsr;
extern boolean Thr_bMonWaitScgPosnSnsr1;
extern boolean Thr_bMonWaitScgPosnSnsr2;
extern boolean Thr_bMonWaitScpPosnSnsr1;
extern boolean Thr_bMonWaitScpPosnSnsr2;
extern boolean THRPOSMES_bDftSftyCohPosnSnsr;
extern boolean THRPOSMES_bDftSftyScgPosnSnsr1;
extern boolean THRPOSMES_bDftSftyScgPosnSnsr2;
extern boolean THRPOSMES_bDftSftyScpPosnSnsr1;
extern boolean THRPOSMES_bDftSftyScpPosnSnsr2;
extern boolean THRPOSMES_bFilSig_1;
extern boolean THRPOSMES_bFilSig_2;
extern boolean THRPOSMES_bFilSig_3;
extern boolean THRPOSMES_bFilSig_4;
extern boolean THRPOSMES_bFilSig_5;
extern boolean THRPOSMES_bTpsSensDefDiagEnaPrev;
extern boolean Tps_sensing_default_diag_enable;
extern uint32 THRPOSMES_u32AccuFilterMem;
extern uint32 THRPOSMES_u32DeltaVoltageFilt;
extern uint32 THRPOSMES_u32VoltFilterMem;
extern uint8 THRPOSMES_u8CntFilt_1;
extern uint8 THRPOSMES_u8CntFilt_2;
extern uint8 THRPOSMES_u8CntFilt_3;
extern uint8 THRPOSMES_u8CntFilt_4;
extern uint8 THRPOSMES_u8CntFilt_5;
extern uint8 THRPOSMES_u8CountNiv2_1;
extern uint8 THRPOSMES_u8CountNiv2_2;
extern uint8 THRPOSMES_u8CountNiv2_3;
extern uint8 THRPOSMES_u8CountNiv2_4;
extern uint8 THRPOSMES_u8CountNiv2_5;
extern uint16 Tension_alimentation_thr_filtree;
extern uint16 Tps_coh_abs_error;
extern uint16 Tps_coh_filt_abs_error;
extern uint16 Tps_position_tolerance;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRPOSMES_vidAcqPosition1(void);
void THRPOSMES_vidAcqPosition2(void);
void THRPOSMES_vidCohPosnSnsrSafetyL2(void);
void THRPOSMES_vidDbleDefaillanceThr(void);
void THRPOSMES_vidDiagDisable(void);
void THRPOSMES_vidDiagElec(void);
void THRPOSMES_vidDiagElecCohPosSnsr(void);
void THRPOSMES_vidDiagElecPosRange(void);
void THRPOSMES_vidDiagOcPosSnsr2(void);
void THRPOSMES_vidFilterU32(uint8 u8FilterGain,uint32 *pu32AccuracyFilterValue,uint32 u32MeasuredValue);
void THRPOSMES_vidInitOutput(void);
void THRPOSMES_vidSafetyLevel2(void);
void THRPOSMES_vidTpsPosTolerance(void);
void THRPOSMES_vidVoltageFilter(void);


#endif /* THRPOSMES_L_H */

/*-------------------------------- end of file -------------------------------*/

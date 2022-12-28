/***************************************************************************
;**
;** FILE NAME      : CKMNGIF_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CKMNGIF_L_H
#define CKMNGIF_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CKMNGIF_U16REGIMEMOTEURPREV_COLS       ( 3 )
#define NB_INJ_SPD_PREV                   3

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

extern const uint8  CKMNGIF_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoHi_aEng;
extern boolean Ext_bDgoHi_nEng;
extern boolean Ext_bMonRunHi_aEng;
extern boolean Ext_bMonRunHi_nEng;
extern uint32 CKMNGIF_u32FiltredEngSpdMem;
extern sint8 Engine_speed_derivate_filt;
extern uint8 Regime_moteur_accel_max_thresh;
extern uint16 CKMNGIF_u16EngSpdClcn;
extern uint16 CKMNGIF_u16RegimeMoteurPrev[CKMNGIF_U16REGIMEMOTEURPREV_COLS];
extern uint16 Periode_moteur_calc;
extern uint16 Periode_moteur_calc_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CKMNGIF_vidAcqui_duree_dent(void);
void CKMNGIF_vidBdcTreatment(void);
void CKMNGIF_vidCalcBdcEngSpd(void);
void CKMNGIF_vidCountPmh(void);
void CKMNGIF_vidDiagEngFail(void);
void CKMNGIF_vidEnginePeriodFind(void);
void CKMNGIF_vidEnginePeriodMeasure(void);
void CKMNGIF_vidEngineRotDetection(void);
void CKMNGIF_vidEngineRotNoDetection(void);
void CKMNGIF_vidEngineSpeedCalc(void);
void CKMNGIF_vidEngineSpeedDerivCalc(void);
void CKMNGIF_vidFiltEngineSpeedCalc(void);
void CKMNGIF_vidInitOutput(void);
void CKMNGIF_vidNoExCyl(void);
void CKMNGIF_vidPeriodeCyl(void);
void CKMNGIF_vidPhaseCylEch(void);
void CKMNGIF_vidRunToStall(void);
void CKMNGIF_vidStallToRun(void);
void CKMNGIF_vidSynchroFound(void);
void CKMNGIF_vidTDCTreatment(void);
void CKMNGIF_vidToothCylEch(void);


#endif /* CKMNGIF_L_H */

/*-------------------------------- end of file -------------------------------*/

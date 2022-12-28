/***************************************************************************
;**
;** FILE NAME      : AIRTQEFF_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AIRTQEFF_L_H
#define AIRTQEFF_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIRSYS_PRM_BACVEFFCYCCAL_COLS          ( 14 )
#define AIRSYS_PRM_EFFAFRCLC_COLS              ( 3 )
#define AIRSYS_PRM_EFFAFRFLEXCOR_MP_COLS       ( 3 )
#define AIRSYS_PRM_EFFCYC_COLS                 ( 14 )

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

extern const uint8  AIRTQEFF_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AirSys_bAcvCycCal1;
extern boolean AirSys_bAcvCycCal10;
extern boolean AirSys_bAcvCycCal11;
extern boolean AirSys_bAcvCycCal12;
extern boolean AirSys_bAcvCycCal13;
extern boolean AirSys_bAcvCycCal14;
extern boolean AirSys_bAcvCycCal2;
extern boolean AirSys_bAcvCycCal3;
extern boolean AirSys_bAcvCycCal4;
extern boolean AirSys_bAcvCycCal5;
extern boolean AirSys_bAcvCycCal6;
extern boolean AirSys_bAcvCycCal7;
extern boolean AirSys_bAcvCycCal8;
extern boolean AirSys_bAcvCycCal9;
extern boolean AirSys_prm_bAcvEffCycCal[AIRSYS_PRM_BACVEFFCYCCAL_COLS];
extern uint8 AirSys_effEGRClc;
extern uint8 AirSys_effEGRWiFlexCor_MP;
extern uint8 AirSys_facBasModCur;
extern uint8 AirSys_facBasModTar;
extern uint8 AirSys_facTranMod;
extern uint8 AirSys_idxBas1ModCur;
extern uint8 AirSys_idxBas1ModTar;
extern uint8 AirSys_idxBas2ModCur;
extern uint8 AirSys_idxBas2ModTar;
extern uint16 AirSys_effCycTran;
extern uint16 AirSys_effCycWiFlexCor_MP;
extern uint16 AirSys_effEffCycBas1ModCur;
extern uint16 AirSys_effEffCycBas1ModTar;
extern uint16 AirSys_effEffCycBas2ModCur;
extern uint16 AirSys_effEffCycBas2ModTar;
extern uint16 AirSys_prm_effAfrClc[AIRSYS_PRM_EFFAFRCLC_COLS];
extern uint16 AirSys_prm_effAfrFlexCor_MP[AIRSYS_PRM_EFFAFRFLEXCOR_MP_COLS];
extern uint16 AirSys_prm_effCyc[AIRSYS_PRM_EFFCYC_COLS];
extern uint16 AirSys_tqIdcHPCal1;
extern uint16 AirSys_tqIdcHPCal10;
extern uint16 AirSys_tqIdcHPCal11;
extern uint16 AirSys_tqIdcHPCal12;
extern uint16 AirSys_tqIdcHPCal13;
extern uint16 AirSys_tqIdcHPCal14;
extern uint16 AirSys_tqIdcHPCal2;
extern uint16 AirSys_tqIdcHPCal3;
extern uint16 AirSys_tqIdcHPCal4;
extern uint16 AirSys_tqIdcHPCal5;
extern uint16 AirSys_tqIdcHPCal6;
extern uint16 AirSys_tqIdcHPCal7;
extern uint16 AirSys_tqIdcHPCal8;
extern uint16 AirSys_tqIdcHPCal9;
extern uint16 AIRTQEFF_u16Barycentre1;
extern uint16 AIRTQEFF_u16Barycentre2;
extern uint16 AIRTQEFF_u16Inj_rlamEng_A_input;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AIRTQEFF_vidCalc_afr_efficiency(void);
void AIRTQEFF_vidCalc_egr_efficiency(void);
void AIRTQEFF_vidCalc_rendement(void);
void AIRTQEFF_vidCalc_rendement_Afr(void);
void AIRTQEFF_vidCalc_rendement_cyc(void);
void AIRTQEFF_vidCalc_rendement_EGR(void);
void AIRTQEFF_vidCalibration_1(void);
void AIRTQEFF_vidCalibration_10(void);
void AIRTQEFF_vidCalibration_11(void);
void AIRTQEFF_vidCalibration_12(void);
void AIRTQEFF_vidCalibration_13(void);
void AIRTQEFF_vidCalibration_14(void);
void AIRTQEFF_vidCalibration_2(void);
void AIRTQEFF_vidCalibration_3(void);
void AIRTQEFF_vidCalibration_4(void);
void AIRTQEFF_vidCalibration_5(void);
void AIRTQEFF_vidCalibration_6(void);
void AIRTQEFF_vidCalibration_7(void);
void AIRTQEFF_vidCalibration_8(void);
void AIRTQEFF_vidCalibration_9(void);
void AIRTQEFF_vidCalibrations(void);
void AIRTQEFF_vidCoordination_1(void);
void AIRTQEFF_vidCoordination_2(void);
void AIRTQEFF_vidCoordination_3(void);
void AIRTQEFF_vidInit_afr_efficicency(void);
void AIRTQEFF_vidinit_egr_efficicency(void);
void AIRTQEFF_vidInit_rendement(void);
void AIRTQEFF_vidInit_rendement_cycle(void);
void AIRTQEFF_vidInitOutput(void);
void AIRTQEFF_vidInterpolation(void);
void AIRTQEFF_vidMode_Mask(void);
void AIRTQEFF_vidSelect_Modes(void);
void AIRTQEFF_vidUnvectorize_Mode(void);
void AIRTQEFF_vidUnvectorz_Activ_Bool(void);
void AIRTQEFF_vidVectorz_Calibrations(void);


#endif /* AIRTQEFF_L_H */

/*-------------------------------- end of file -------------------------------*/

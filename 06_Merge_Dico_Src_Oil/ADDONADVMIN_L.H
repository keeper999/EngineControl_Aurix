/***************************************************************************
;**
;** FILE NAME      : ADDONADVMIN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ADDONADVMIN_L_H
#define ADDONADVMIN_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGSYS_PRM_BACVOFSAGIGMINCAL_COLS       ( 14 )
#define IGSYS_PRM_OFSAGIGMIN_COLS              ( 14 )

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

extern const uint8  ADDONADVMIN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IgSys_bAcvOfsAgIgMinCal1;
extern boolean IgSys_bAcvOfsAgIgMinCal10;
extern boolean IgSys_bAcvOfsAgIgMinCal11;
extern boolean IgSys_bAcvOfsAgIgMinCal12;
extern boolean IgSys_bAcvOfsAgIgMinCal13;
extern boolean IgSys_bAcvOfsAgIgMinCal14;
extern boolean IgSys_bAcvOfsAgIgMinCal2;
extern boolean IgSys_bAcvOfsAgIgMinCal3;
extern boolean IgSys_bAcvOfsAgIgMinCal4;
extern boolean IgSys_bAcvOfsAgIgMinCal5;
extern boolean IgSys_bAcvOfsAgIgMinCal6;
extern boolean IgSys_bAcvOfsAgIgMinCal7;
extern boolean IgSys_bAcvOfsAgIgMinCal8;
extern boolean IgSys_bAcvOfsAgIgMinCal9;
extern boolean IgSys_prm_bAcvOfsAgIgMinCal[IGSYS_PRM_BACVOFSAGIGMINCAL_COLS];
extern uint8 IgSys_facOfsAgIgMinBasModCur;
extern uint8 IgSys_facOfsAgIgMinBasModTar;
extern uint8 IgSys_facOfsAgIgMinTranMod;
extern uint8 IgSys_idxOfsAgIgMinBas1ModCur;
extern uint8 IgSys_idxOfsAgIgMinBas1ModTar;
extern uint8 IgSys_idxOfsAgIgMinBas2ModCur;
extern uint8 IgSys_idxOfsAgIgMinBas2ModTar;
extern sint16 IgSys_agIgCmbModOfsMinCur_MP;
extern sint16 IgSys_agIgCmbModOfsMinTar_MP;
extern sint16 IgSys_ofsAgIgMinBas1ModCur;
extern sint16 IgSys_ofsAgIgMinBas1ModTar;
extern sint16 IgSys_ofsAgIgMinBas2ModCur;
extern sint16 IgSys_ofsAgIgMinBas2ModTar;
extern sint16 IgSys_ofsAgIgMinCal1;
extern sint16 IgSys_ofsAgIgMinCal10;
extern sint16 IgSys_ofsAgIgMinCal11;
extern sint16 IgSys_ofsAgIgMinCal12;
extern sint16 IgSys_ofsAgIgMinCal13;
extern sint16 IgSys_ofsAgIgMinCal14;
extern sint16 IgSys_ofsAgIgMinCal2;
extern sint16 IgSys_ofsAgIgMinCal3;
extern sint16 IgSys_ofsAgIgMinCal4;
extern sint16 IgSys_ofsAgIgMinCal5;
extern sint16 IgSys_ofsAgIgMinCal6;
extern sint16 IgSys_ofsAgIgMinCal7;
extern sint16 IgSys_ofsAgIgMinCal8;
extern sint16 IgSys_ofsAgIgMinCal9;
extern sint16 IgSys_prm_ofsAgIgMin[IGSYS_PRM_OFSAGIGMIN_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ADDONADVMIN_vidCalibration_1(void);
void ADDONADVMIN_vidCalibration_10(void);
void ADDONADVMIN_vidCalibration_11(void);
void ADDONADVMIN_vidCalibration_12(void);
void ADDONADVMIN_vidCalibration_13(void);
void ADDONADVMIN_vidCalibration_14(void);
void ADDONADVMIN_vidCalibration_2(void);
void ADDONADVMIN_vidCalibration_3(void);
void ADDONADVMIN_vidCalibration_4(void);
void ADDONADVMIN_vidCalibration_5(void);
void ADDONADVMIN_vidCalibration_6(void);
void ADDONADVMIN_vidCalibration_7(void);
void ADDONADVMIN_vidCalibration_8(void);
void ADDONADVMIN_vidCalibration_9(void);
void ADDONADVMIN_vidCalibrations(void);
void ADDONADVMIN_vidInitOutput(void);
void ADDONADVMIN_vidInterpolation(void);
void ADDONADVMIN_vidMode_Mask(void);
void ADDONADVMIN_vidOffset_Aamini(void);
void ADDONADVMIN_vidSelect_Modes(void);
void ADDONADVMIN_vidUnvectorize_Mode(void);
void ADDONADVMIN_vidUnvectrzActivBool(void);
void ADDONADVMIN_vidVectorizeCalibs(void);


#endif /* ADDONADVMIN_L_H */

/*-------------------------------- end of file -------------------------------*/

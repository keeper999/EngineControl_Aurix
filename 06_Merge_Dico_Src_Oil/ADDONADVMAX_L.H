/***************************************************************************
;**
;** FILE NAME      : ADDONADVMAX_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ADDONADVMAX_L_H
#define ADDONADVMAX_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGSYS_PRM_BACVOFSAGIGMAXCAL_COLS       ( 14 )
#define IGSYS_PRM_OFSAGIGMAX_COLS              ( 14 )

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

extern const uint8  ADDONADVMAX_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IgSys_bAcvOfsAgIgMaxCal1;
extern boolean IgSys_bAcvOfsAgIgMaxCal10;
extern boolean IgSys_bAcvOfsAgIgMaxCal11;
extern boolean IgSys_bAcvOfsAgIgMaxCal12;
extern boolean IgSys_bAcvOfsAgIgMaxCal13;
extern boolean IgSys_bAcvOfsAgIgMaxCal14;
extern boolean IgSys_bAcvOfsAgIgMaxCal2;
extern boolean IgSys_bAcvOfsAgIgMaxCal3;
extern boolean IgSys_bAcvOfsAgIgMaxCal4;
extern boolean IgSys_bAcvOfsAgIgMaxCal5;
extern boolean IgSys_bAcvOfsAgIgMaxCal6;
extern boolean IgSys_bAcvOfsAgIgMaxCal7;
extern boolean IgSys_bAcvOfsAgIgMaxCal8;
extern boolean IgSys_bAcvOfsAgIgMaxCal9;
extern boolean IgSys_prm_bAcvOfsAgIgMaxCal[IGSYS_PRM_BACVOFSAGIGMAXCAL_COLS];
extern uint8 IgSys_facOfsAgIgMaxBasModCur;
extern uint8 IgSys_facOfsAgIgMaxBasModTar;
extern uint8 IgSys_facOfsAgIgMaxTranMod;
extern uint8 IgSys_idxOfsAgIgMaxBas1ModCur;
extern uint8 IgSys_idxOfsAgIgMaxBas1ModTar;
extern uint8 IgSys_idxOfsAgIgMaxBas2ModCur;
extern uint8 IgSys_idxOfsAgIgMaxBas2ModTar;
extern sint16 IgSys_agIgCmbModOfsMaxCur_MP;
extern sint16 IgSys_agIgCmbModOfsMaxTar_MP;
extern sint16 IgSys_ofsAgIgMaxBas1ModCur;
extern sint16 IgSys_ofsAgIgMaxBas1ModTar;
extern sint16 IgSys_ofsAgIgMaxBas2ModCur;
extern sint16 IgSys_ofsAgIgMaxBas2ModTar;
extern sint16 IgSys_ofsAgIgMaxCal1;
extern sint16 IgSys_ofsAgIgMaxCal10;
extern sint16 IgSys_ofsAgIgMaxCal11;
extern sint16 IgSys_ofsAgIgMaxCal12;
extern sint16 IgSys_ofsAgIgMaxCal13;
extern sint16 IgSys_ofsAgIgMaxCal14;
extern sint16 IgSys_ofsAgIgMaxCal2;
extern sint16 IgSys_ofsAgIgMaxCal3;
extern sint16 IgSys_ofsAgIgMaxCal4;
extern sint16 IgSys_ofsAgIgMaxCal5;
extern sint16 IgSys_ofsAgIgMaxCal6;
extern sint16 IgSys_ofsAgIgMaxCal7;
extern sint16 IgSys_ofsAgIgMaxCal8;
extern sint16 IgSys_ofsAgIgMaxCal9;
extern sint16 IgSys_prm_ofsAgIgMax[IGSYS_PRM_OFSAGIGMAX_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ADDONADVMAX_vidCalibration_1(void);
void ADDONADVMAX_vidCalibration_10(void);
void ADDONADVMAX_vidCalibration_11(void);
void ADDONADVMAX_vidCalibration_12(void);
void ADDONADVMAX_vidCalibration_13(void);
void ADDONADVMAX_vidCalibration_14(void);
void ADDONADVMAX_vidCalibration_2(void);
void ADDONADVMAX_vidCalibration_3(void);
void ADDONADVMAX_vidCalibration_4(void);
void ADDONADVMAX_vidCalibration_5(void);
void ADDONADVMAX_vidCalibration_6(void);
void ADDONADVMAX_vidCalibration_7(void);
void ADDONADVMAX_vidCalibration_8(void);
void ADDONADVMAX_vidCalibration_9(void);
void ADDONADVMAX_vidCalibrations(void);
void ADDONADVMAX_vidInitOutput(void);
void ADDONADVMAX_vidInterpolation(void);
void ADDONADVMAX_vidMode_Mask(void);
void ADDONADVMAX_vidOffset_Aamaxi(void);
void ADDONADVMAX_vidSelect_Modes(void);
void ADDONADVMAX_vidUnvectorize_Mode(void);
void ADDONADVMAX_vidUnvectrzActivBool(void);
void ADDONADVMAX_vidVectorizeCalibs(void);


#endif /* ADDONADVMAX_L_H */

/*-------------------------------- end of file -------------------------------*/

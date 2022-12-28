/***************************************************************************
;**
;** FILE NAME      : ADDONADVOPTM_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ADDONADVOPTM_L_H
#define ADDONADVOPTM_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGSYS_PRM_BACVOFSAGIGOPTMCAL_COLS      ( 17 )
#define IGSYS_PRM_OFSAGIGOPTM_COLS             ( 17 )

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

extern const uint8  ADDONADVOPTM_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IgSys_bAcvOfsAgIgOptmCal1;
extern boolean IgSys_bAcvOfsAgIgOptmCal10;
extern boolean IgSys_bAcvOfsAgIgOptmCal11;
extern boolean IgSys_bAcvOfsAgIgOptmCal12;
extern boolean IgSys_bAcvOfsAgIgOptmCal13;
extern boolean IgSys_bAcvOfsAgIgOptmCal14;
extern boolean IgSys_bAcvOfsAgIgOptmCal15;
extern boolean IgSys_bAcvOfsAgIgOptmCal16;
extern boolean IgSys_bAcvOfsAgIgOptmCal17;
extern boolean IgSys_bAcvOfsAgIgOptmCal2;
extern boolean IgSys_bAcvOfsAgIgOptmCal3;
extern boolean IgSys_bAcvOfsAgIgOptmCal4;
extern boolean IgSys_bAcvOfsAgIgOptmCal5;
extern boolean IgSys_bAcvOfsAgIgOptmCal6;
extern boolean IgSys_bAcvOfsAgIgOptmCal7;
extern boolean IgSys_bAcvOfsAgIgOptmCal8;
extern boolean IgSys_bAcvOfsAgIgOptmCal9;
extern boolean IgSys_prm_bAcvOfsAgIgOptmCal[IGSYS_PRM_BACVOFSAGIGOPTMCAL_COLS];
extern uint8 IgSys_facOfsAgIgOpBasModCur;
extern uint8 IgSys_facOfsAgIgOpBasModTar;
extern uint8 IgSys_facOfsAgIgOpTranMod;
extern uint8 IgSys_idxOfsAgIgOpBas1ModCur;
extern uint8 IgSys_idxOfsAgIgOpBas1ModTar;
extern uint8 IgSys_idxOfsAgIgOpBas2ModCur;
extern uint8 IgSys_idxOfsAgIgOpBas2ModTar;
extern sint16 IgSys_agIgCmbModOfsCur_MP;
extern sint16 IgSys_agIgCmbModOfsTar_MP;
extern sint16 IgSys_ofsAgIgOptmBas1ModCur;
extern sint16 IgSys_ofsAgIgOptmBas1ModTar;
extern sint16 IgSys_ofsAgIgOptmBas2ModCur;
extern sint16 IgSys_ofsAgIgOptmBas2ModTar;
extern sint16 IgSys_ofsAgIgOptmCal1;
extern sint16 IgSys_ofsAgIgOptmCal10;
extern sint16 IgSys_ofsAgIgOptmCal11;
extern sint16 IgSys_ofsAgIgOptmCal12;
extern sint16 IgSys_ofsAgIgOptmCal13;
extern sint16 IgSys_ofsAgIgOptmCal14;
extern sint16 IgSys_ofsAgIgOptmCal15;
extern sint16 IgSys_ofsAgIgOptmCal16;
extern sint16 IgSys_ofsAgIgOptmCal17;
extern sint16 IgSys_ofsAgIgOptmCal2;
extern sint16 IgSys_ofsAgIgOptmCal3;
extern sint16 IgSys_ofsAgIgOptmCal4;
extern sint16 IgSys_ofsAgIgOptmCal5;
extern sint16 IgSys_ofsAgIgOptmCal6;
extern sint16 IgSys_ofsAgIgOptmCal7;
extern sint16 IgSys_ofsAgIgOptmCal8;
extern sint16 IgSys_ofsAgIgOptmCal9;
extern sint16 IgSys_prm_ofsAgIgOptm[IGSYS_PRM_OFSAGIGOPTM_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ADDONADVOPTM_vidCalibration_1(void);
void ADDONADVOPTM_vidCalibration_10(void);
void ADDONADVOPTM_vidCalibration_11(void);
void ADDONADVOPTM_vidCalibration_12(void);
void ADDONADVOPTM_vidCalibration_13(void);
void ADDONADVOPTM_vidCalibration_14(void);
void ADDONADVOPTM_vidCalibration_15(void);
void ADDONADVOPTM_vidCalibration_16(void);
void ADDONADVOPTM_vidCalibration_17(void);
void ADDONADVOPTM_vidCalibration_2(void);
void ADDONADVOPTM_vidCalibration_3(void);
void ADDONADVOPTM_vidCalibration_4(void);
void ADDONADVOPTM_vidCalibration_5(void);
void ADDONADVOPTM_vidCalibration_6(void);
void ADDONADVOPTM_vidCalibration_7(void);
void ADDONADVOPTM_vidCalibration_8(void);
void ADDONADVOPTM_vidCalibration_9(void);
void ADDONADVOPTM_vidCalibrations(void);
void ADDONADVOPTM_vidInitOutput(void);
void ADDONADVOPTM_vidInterpolation(void);
void ADDONADVOPTM_vidMode_Mask(void);
void ADDONADVOPTM_vidOffset_AAO(void);
void ADDONADVOPTM_vidSelect_Modes(void);
void ADDONADVOPTM_vidUnvectorActvBool(void);
void ADDONADVOPTM_vidUnvectorize_Mode(void);
void ADDONADVOPTM_vidVectorize_Calib(void);


#endif /* ADDONADVOPTM_L_H */

/*-------------------------------- end of file -------------------------------*/

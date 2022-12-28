/***************************************************************************
;**
;** FILE NAME      : VVTSPLIMCORD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VVTSPLIMCORD_L_H
#define VVTSPLIMCORD_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define EXM_PRM_BACVTEXOFSCAL_COLS             ( 14 )
#define EXM_PRM_TEXOFSCAL_COLS                 ( 14 )

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

extern const uint8  VVTSPLIMCORD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ExM_bAcvTExOfsCal1;
extern boolean ExM_bAcvTExOfsCal10;
extern boolean ExM_bAcvTExOfsCal11;
extern boolean ExM_bAcvTExOfsCal12;
extern boolean ExM_bAcvTExOfsCal13;
extern boolean ExM_bAcvTExOfsCal14;
extern boolean ExM_bAcvTExOfsCal2;
extern boolean ExM_bAcvTExOfsCal3;
extern boolean ExM_bAcvTExOfsCal4;
extern boolean ExM_bAcvTExOfsCal5;
extern boolean ExM_bAcvTExOfsCal6;
extern boolean ExM_bAcvTExOfsCal7;
extern boolean ExM_bAcvTExOfsCal8;
extern boolean ExM_bAcvTExOfsCal9;
extern boolean ExM_prm_bAcvTExOfsCal[EXM_PRM_BACVTEXOFSCAL_COLS];
extern uint8 ExM_facBasModCur;
extern uint8 ExM_facBasModTar;
extern uint8 ExM_facTranMod;
extern uint8 ExM_idxBas1ModCur;
extern uint8 ExM_idxBas1ModTar;
extern uint8 ExM_idxBas2ModCur;
extern uint8 ExM_idxBas2ModTar;
extern sint16 ExM_prm_tExOfsCal[EXM_PRM_TEXOFSCAL_COLS];
extern sint16 ExM_tExOfsBas1ModCur;
extern sint16 ExM_tExOfsBas1ModTar;
extern sint16 ExM_tExOfsBas2ModCur;
extern sint16 ExM_tExOfsBas2ModTar;
extern sint16 ExM_tExOfsCal1;
extern sint16 ExM_tExOfsCal10;
extern sint16 ExM_tExOfsCal11;
extern sint16 ExM_tExOfsCal12;
extern sint16 ExM_tExOfsCal13;
extern sint16 ExM_tExOfsCal14;
extern sint16 ExM_tExOfsCal2;
extern sint16 ExM_tExOfsCal3;
extern sint16 ExM_tExOfsCal4;
extern sint16 ExM_tExOfsCal5;
extern sint16 ExM_tExOfsCal6;
extern sint16 ExM_tExOfsCal7;
extern sint16 ExM_tExOfsCal8;
extern sint16 ExM_tExOfsCal9;
extern sint16 ExM_tExOfsModCur_MP;
extern sint16 ExM_tExOfsModTar_MP;
extern uint16 ExM_nEngCor;
extern uint16 ExM_rAirLdCor;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VVTSPLIMCORD_vidCalibration_1(void);
void VVTSPLIMCORD_vidCalibration_10(void);
void VVTSPLIMCORD_vidCalibration_11(void);
void VVTSPLIMCORD_vidCalibration_12(void);
void VVTSPLIMCORD_vidCalibration_13(void);
void VVTSPLIMCORD_vidCalibration_14(void);
void VVTSPLIMCORD_vidCalibration_2(void);
void VVTSPLIMCORD_vidCalibration_3(void);
void VVTSPLIMCORD_vidCalibration_4(void);
void VVTSPLIMCORD_vidCalibration_5(void);
void VVTSPLIMCORD_vidCalibration_6(void);
void VVTSPLIMCORD_vidCalibration_7(void);
void VVTSPLIMCORD_vidCalibration_8(void);
void VVTSPLIMCORD_vidCalibration_9(void);
void VVTSPLIMCORD_vidCalibrations(void);
void VVTSPLIMCORD_vidExOfs(void);
void VVTSPLIMCORD_vidInitOutput(void);
void VVTSPLIMCORD_vidInterpolation(void);
void VVTSPLIMCORD_vidMode_Mask(void);
void VVTSPLIMCORD_vidSelect_Modes(void);
void VVTSPLIMCORD_vidUnvect_Act_Bool(void);
void VVTSPLIMCORD_vidUnvectorize_Mode(void);
void VVTSPLIMCORD_vidVectorize_Calib(void);


#endif /* VVTSPLIMCORD_L_H */

/*-------------------------------- end of file -------------------------------*/

/***************************************************************************
;**
;** FILE NAME      : VLVINSPMGT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVINSPMGT_L_H
#define VLVINSPMGT_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVSYS_PRM_AGCKOPINCAL_COLS            ( 18 )
#define VLVSYS_PRM_BACVOPINCAL_COLS            ( 18 )

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

extern const uint8  VLVINSPMGT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvSys_bAcvOpInCal1;
extern boolean VlvSys_bAcvOpInCal10;
extern boolean VlvSys_bAcvOpInCal11;
extern boolean VlvSys_bAcvOpInCal12;
extern boolean VlvSys_bAcvOpInCal13;
extern boolean VlvSys_bAcvOpInCal14;
extern boolean VlvSys_bAcvOpInCal15;
extern boolean VlvSys_bAcvOpInCal16;
extern boolean VlvSys_bAcvOpInCal17;
extern boolean VlvSys_bAcvOpInCal18;
extern boolean VlvSys_bAcvOpInCal2;
extern boolean VlvSys_bAcvOpInCal3;
extern boolean VlvSys_bAcvOpInCal4;
extern boolean VlvSys_bAcvOpInCal5;
extern boolean VlvSys_bAcvOpInCal6;
extern boolean VlvSys_bAcvOpInCal7;
extern boolean VlvSys_bAcvOpInCal8;
extern boolean VlvSys_bAcvOpInCal9;
extern boolean VlvSys_prm_bAcvOpInCal[VLVSYS_PRM_BACVOPINCAL_COLS];
extern sint8 VlvSys_agCkOpInCal1;
extern sint8 VlvSys_agCkOpInCal10;
extern sint8 VlvSys_agCkOpInCal11;
extern sint8 VlvSys_agCkOpInCal12;
extern sint8 VlvSys_agCkOpInCal13;
extern sint8 VlvSys_agCkOpInCal14;
extern sint8 VlvSys_agCkOpInCal15;
extern sint8 VlvSys_agCkOpInCal16;
extern sint8 VlvSys_agCkOpInCal17;
extern sint8 VlvSys_agCkOpInCal18;
extern sint8 VlvSys_agCkOpInCal2;
extern sint8 VlvSys_agCkOpInCal3;
extern sint8 VlvSys_agCkOpInCal4;
extern sint8 VlvSys_agCkOpInCal5;
extern sint8 VlvSys_agCkOpInCal6;
extern sint8 VlvSys_agCkOpInCal7;
extern sint8 VlvSys_agCkOpInCal8;
extern sint8 VlvSys_agCkOpInCal9;
extern sint8 VlvSys_agCkOpInVlvBas1ModCur;
extern sint8 VlvSys_agCkOpInVlvBas1ModTar;
extern sint8 VlvSys_agCkOpInVlvBas2ModCur;
extern sint8 VlvSys_agCkOpInVlvBas2ModTar;
extern sint8 VlvSys_prm_agCkOpInCal[VLVSYS_PRM_AGCKOPINCAL_COLS];
extern uint8 VlvSys_facBasModCurOpIn;
extern uint8 VlvSys_facBasModTarOpIn;
extern uint8 VlvSys_facTranModOpIn;
extern uint8 VlvSys_idxBas1ModCurOpIn;
extern uint8 VlvSys_idxBas1ModTarOpIn;
extern uint8 VlvSys_idxBas2ModCurOpIn;
extern uint8 VlvSys_idxBas2ModTarOpIn;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVINSPMGT_vidCalibration_1(void);
void VLVINSPMGT_vidCalibration_10(void);
void VLVINSPMGT_vidCalibration_11(void);
void VLVINSPMGT_vidCalibration_12(void);
void VLVINSPMGT_vidCalibration_13(void);
void VLVINSPMGT_vidCalibration_14(void);
void VLVINSPMGT_vidCalibration_15(void);
void VLVINSPMGT_vidCalibration_16(void);
void VLVINSPMGT_vidCalibration_17(void);
void VLVINSPMGT_vidCalibration_18(void);
void VLVINSPMGT_vidCalibration_2(void);
void VLVINSPMGT_vidCalibration_3(void);
void VLVINSPMGT_vidCalibration_4(void);
void VLVINSPMGT_vidCalibration_5(void);
void VLVINSPMGT_vidCalibration_6(void);
void VLVINSPMGT_vidCalibration_7(void);
void VLVINSPMGT_vidCalibration_8(void);
void VLVINSPMGT_vidCalibration_9(void);
void VLVINSPMGT_vidCalibrations(void);
void VLVINSPMGT_vidInit(void);
void VLVINSPMGT_vidInitOutput(void);
void VLVINSPMGT_vidInterpolation(void);
void VLVINSPMGT_vidMode_Mask(void);
void VLVINSPMGT_vidSelect_Modes(void);
void VLVINSPMGT_vidUnvect_Activ_Bool(void);
void VLVINSPMGT_vidUnvectorize_Mode(void);
void VLVINSPMGT_vidVectorize_Calibs(void);
void VLVINSPMGT_vidVlvIn(void);
void VLVINSPMGT_vidVlvInEna(void);


#endif /* VLVINSPMGT_L_H */

/*-------------------------------- end of file -------------------------------*/

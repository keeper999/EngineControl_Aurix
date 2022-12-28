/***************************************************************************
;**
;** FILE NAME      : VLVEXSPMGT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVEXSPMGT_L_H
#define VLVEXSPMGT_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVSYS_PRM_AGCKCLSEXCAL_COLS           ( 18 )
#define VLVSYS_PRM_BACVCLSEXCAL_COLS           ( 18 )

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

extern const uint8  VLVEXSPMGT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvSys_bAcvClsExCal1;
extern boolean VlvSys_bAcvClsExCal10;
extern boolean VlvSys_bAcvClsExCal11;
extern boolean VlvSys_bAcvClsExCal12;
extern boolean VlvSys_bAcvClsExCal13;
extern boolean VlvSys_bAcvClsExCal14;
extern boolean VlvSys_bAcvClsExCal15;
extern boolean VlvSys_bAcvClsExCal16;
extern boolean VlvSys_bAcvClsExCal17;
extern boolean VlvSys_bAcvClsExCal18;
extern boolean VlvSys_bAcvClsExCal2;
extern boolean VlvSys_bAcvClsExCal3;
extern boolean VlvSys_bAcvClsExCal4;
extern boolean VlvSys_bAcvClsExCal5;
extern boolean VlvSys_bAcvClsExCal6;
extern boolean VlvSys_bAcvClsExCal7;
extern boolean VlvSys_bAcvClsExCal8;
extern boolean VlvSys_bAcvClsExCal9;
extern boolean VlvSys_prm_bAcvClsExCal[VLVSYS_PRM_BACVCLSEXCAL_COLS];
extern sint8 VlvSys_agCkClsExBas1ModCur;
extern sint8 VlvSys_agCkClsExBas1ModTar;
extern sint8 VlvSys_agCkClsExBas2ModCur;
extern sint8 VlvSys_agCkClsExBas2ModTar;
extern sint8 VlvSys_agCkClsExCal1;
extern sint8 VlvSys_agCkClsExCal10;
extern sint8 VlvSys_agCkClsExCal11;
extern sint8 VlvSys_agCkClsExCal12;
extern sint8 VlvSys_agCkClsExCal13;
extern sint8 VlvSys_agCkClsExCal14;
extern sint8 VlvSys_agCkClsExCal15;
extern sint8 VlvSys_agCkClsExCal16;
extern sint8 VlvSys_agCkClsExCal17;
extern sint8 VlvSys_agCkClsExCal18;
extern sint8 VlvSys_agCkClsExCal2;
extern sint8 VlvSys_agCkClsExCal3;
extern sint8 VlvSys_agCkClsExCal4;
extern sint8 VlvSys_agCkClsExCal5;
extern sint8 VlvSys_agCkClsExCal6;
extern sint8 VlvSys_agCkClsExCal7;
extern sint8 VlvSys_agCkClsExCal8;
extern sint8 VlvSys_agCkClsExCal9;
extern sint8 VlvSys_prm_agCkClsExCal[VLVSYS_PRM_AGCKCLSEXCAL_COLS];
extern uint8 VlvSys_facBasModCurClsEx;
extern uint8 VlvSys_facBasModTarClsEx;
extern uint8 VlvSys_facTranModClsEx;
extern uint8 VlvSys_idxBas1ModCurClsEx;
extern uint8 VlvSys_idxBas1ModTarClsEx;
extern uint8 VlvSys_idxBas2ModCurClsEx;
extern uint8 VlvSys_idxBas2ModTarClsEx;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVEXSPMGT_vidCalibration_1(void);
void VLVEXSPMGT_vidCalibration_10(void);
void VLVEXSPMGT_vidCalibration_11(void);
void VLVEXSPMGT_vidCalibration_12(void);
void VLVEXSPMGT_vidCalibration_13(void);
void VLVEXSPMGT_vidCalibration_14(void);
void VLVEXSPMGT_vidCalibration_15(void);
void VLVEXSPMGT_vidCalibration_16(void);
void VLVEXSPMGT_vidCalibration_17(void);
void VLVEXSPMGT_vidCalibration_18(void);
void VLVEXSPMGT_vidCalibration_2(void);
void VLVEXSPMGT_vidCalibration_3(void);
void VLVEXSPMGT_vidCalibration_4(void);
void VLVEXSPMGT_vidCalibration_5(void);
void VLVEXSPMGT_vidCalibration_6(void);
void VLVEXSPMGT_vidCalibration_7(void);
void VLVEXSPMGT_vidCalibration_8(void);
void VLVEXSPMGT_vidCalibration_9(void);
void VLVEXSPMGT_vidCalibrations(void);
void VLVEXSPMGT_vidInit(void);
void VLVEXSPMGT_vidInitOutput(void);
void VLVEXSPMGT_vidInterpolation(void);
void VLVEXSPMGT_vidMode_Mask(void);
void VLVEXSPMGT_vidSelect_Modes(void);
void VLVEXSPMGT_vidUnvect_Activ_Bool(void);
void VLVEXSPMGT_vidUnvectorize_Mode(void);
void VLVEXSPMGT_vidVectorize_Calibs(void);
void VLVEXSPMGT_vidVlvEx(void);
void VLVEXSPMGT_vidVlvExEna(void);


#endif /* VLVEXSPMGT_L_H */

/*-------------------------------- end of file -------------------------------*/

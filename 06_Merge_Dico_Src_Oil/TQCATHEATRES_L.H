/***************************************************************************
;**
;** FILE NAME      : TQCATHEATRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQCATHEATRES_L_H
#define TQCATHEATRES_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQCATHEATRES_u8Table              8
#define TQRES_PRM_BACVEOMRESMOD_COLS           ( 8 )
#define TQRES_PRM_TQEOMRES_COLS                ( 8 )

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

extern const uint8  TQCATHEATRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TqRes_bAcvEOMResMod1;
extern boolean TqRes_bAcvEOMResMod2;
extern boolean TqRes_bAcvEOMResMod3;
extern boolean TqRes_bAcvEOMResMod4;
extern boolean TqRes_bAcvEOMResMod5;
extern boolean TqRes_bAcvEOMResMod6;
extern boolean TqRes_bAcvEOMResMod7;
extern boolean TqRes_bAcvEOMResMod8;
extern boolean TqRes_prm_bAcvEOMResMod[TQRES_PRM_BACVEOMRESMOD_COLS];
extern uint8 TqRes_facBasModCur;
extern uint8 TqRes_facBasModTar;
extern uint8 TqRes_facTranMod;
extern uint8 TqRes_idxBas1ModCur;
extern uint8 TqRes_idxBas1ModTar;
extern uint8 TqRes_idxBas2ModCur;
extern uint8 TqRes_idxBas2ModTar;
extern uint16 TqRes_prm_tqEOMRes[TQRES_PRM_TQEOMRES_COLS];
extern uint16 TqRes_tqBas1ModCur;
extern uint16 TqRes_tqBas1ModTar;
extern uint16 TqRes_tqBas2ModCur;
extern uint16 TqRes_tqBas2ModTar;
extern uint16 TqRes_tqEOMResMod1;
extern uint16 TqRes_tqEOMResMod2;
extern uint16 TqRes_tqEOMResMod3;
extern uint16 TqRes_tqEOMResMod4;
extern uint16 TqRes_tqEOMResMod5;
extern uint16 TqRes_tqEOMResMod6;
extern uint16 TqRes_tqEOMResMod7;
extern uint16 TqRes_tqEOMResMod8;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQCATHEATRES_vidCalibration1(void);
void TQCATHEATRES_vidCalibration2(void);
void TQCATHEATRES_vidCalibration3(void);
void TQCATHEATRES_vidCalibration4(void);
void TQCATHEATRES_vidCalibration5(void);
void TQCATHEATRES_vidCalibration6(void);
void TQCATHEATRES_vidCalibration7(void);
void TQCATHEATRES_vidCalibration8(void);
void TQCATHEATRES_vidCalibrations(void);
void TQCATHEATRES_vidDeterminSetpoint(void);
void TQCATHEATRES_vidInitOutput(void);
void TQCATHEATRES_vidInterpolation(void);
void TQCATHEATRES_vidModeMask(void);
void TQCATHEATRES_vidSelectModes(void);
void TQCATHEATRES_vidUnvectActiveBool(void);
void TQCATHEATRES_vidUnvectorizeMode(void);
void TQCATHEATRES_vidVectCalibrations(void);


#endif /* TQCATHEATRES_L_H */

/*-------------------------------- end of file -------------------------------*/

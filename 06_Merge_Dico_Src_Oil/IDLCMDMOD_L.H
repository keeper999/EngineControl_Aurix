/***************************************************************************
;**
;** FILE NAME      : IDLCMDMOD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IDLCMDMOD_L_H
#define IDLCMDMOD_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQSYS_PRM_NTARIDLCMBMOD_COLS           ( 7 )

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

extern const uint8  IDLCMDMOD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TqSys_bAcvNTarIdlCmbModEgd;
extern uint8 TqSys_facBasModCur;
extern uint8 TqSys_facBasModTar;
extern uint8 TqSys_facTranMod;
extern uint8 TqSys_idxBas1ModCur;
extern uint8 TqSys_idxBas1ModTar;
extern uint8 TqSys_idxBas2ModCur;
extern uint8 TqSys_idxBas2ModTar;
extern uint16 TqSys_nTarIdlBas1ModCur;
extern uint16 TqSys_nTarIdlBas1ModTar;
extern uint16 TqSys_nTarIdlBas2ModCur;
extern uint16 TqSys_nTarIdlBas2ModTar;
extern uint16 TqSys_nTarIdlCmbMod1;
extern uint16 TqSys_nTarIdlCmbMod2;
extern uint16 TqSys_nTarIdlCmbMod3;
extern uint16 TqSys_nTarIdlCmbMod4;
extern uint16 TqSys_nTarIdlCmbMod5;
extern uint16 TqSys_nTarIdlCmbMod6;
extern uint16 TqSys_nTarIdlCmbMod7;
extern uint16 TqSys_prm_nTarIdlCmbMod[TQSYS_PRM_NTARIDLCMBMOD_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IDLCMDMOD_vidCalibration1(void);
void IDLCMDMOD_vidCalibration2(void);
void IDLCMDMOD_vidCalibration3(void);
void IDLCMDMOD_vidCalibration4(void);
void IDLCMDMOD_vidCalibration5(void);
void IDLCMDMOD_vidCalibration6(void);
void IDLCMDMOD_vidCalibration7(void);
void IDLCMDMOD_vidCalibrations(void);
void IDLCMDMOD_vidDetermineSetpoint(void);
void IDLCMDMOD_vidDtrminePwrtrainStat(void);
void IDLCMDMOD_vidInitOutput(void);
void IDLCMDMOD_vidInterpolation(void);
void IDLCMDMOD_vidSelectModes(void);
void IDLCMDMOD_vidUnvectorizeMode(void);
void IDLCMDMOD_vidVectorizCalibration(void);


#endif /* IDLCMDMOD_L_H */

/*-------------------------------- end of file -------------------------------*/

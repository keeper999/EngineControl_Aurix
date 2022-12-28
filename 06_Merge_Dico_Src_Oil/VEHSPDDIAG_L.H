/***************************************************************************
;**
;** FILE NAME      : VEHSPDDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VEHSPDDIAG_L_H
#define VEHSPDDIAG_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


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

extern const uint8  VEHSPDDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VehSpd_bCnd1Coh_spdVeh;
extern boolean VehSpd_bCnd2Coh_spdVeh;
extern boolean VehSpd_bDgoCoh_spdVeh;
extern boolean VehSpd_bDgoORng_spdVeh;
extern boolean VehSpd_bMonRunCoh_spdVeh;
extern boolean VehSpd_bMonRunORng_spdVeh;
extern boolean VEHSPDDIAG_bFilSig_1;
extern boolean VEHSPDDIAG_bORng_spdVeh;
extern uint8 VehSpd_ctDftSftyORng_spdVeh;
extern uint8 VehSpd_ctEngSpdMesPoint;
extern uint8 VehSpd_ctIdcReqMesPoint;
extern uint8 VEHSPDDIAG_u8CntFilt_1;
extern sint16 VEHSPDDIAG_TqSys_tqIdcReqPrev;
extern uint16 VEHSPDDIAG_Regime_moteurPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VEHSPDDIAG_vidActivateDiag(void);
void VEHSPDDIAG_vidCheckStabilityCond(void);
void VEHSPDDIAG_vidConsistDetectActiv(void);
void VEHSPDDIAG_vidConsistency_Test(void);
void VEHSPDDIAG_vidInit(void);
void VEHSPDDIAG_vidMaxValDetectActiv(void);
void VEHSPDDIAG_vidMaxValueTested(void);
void VEHSPDDIAG_vidRunDiag(void);


#endif /* VEHSPDDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/

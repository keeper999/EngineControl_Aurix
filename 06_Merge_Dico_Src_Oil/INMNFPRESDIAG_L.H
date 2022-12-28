/***************************************************************************
;**
;** FILE NAME      : INMNFPRESDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INMNFPRESDIAG_L_H
#define INMNFPRESDIAG_L_H

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

extern const uint8  INMNFPRESDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AirPres_bAuthUpdPres;
extern boolean AirPres_bCanPurgOk;
extern boolean AirPres_bDetFirstRun;
extern boolean AirPres_bDetFirstSt;
extern boolean AirPres_bDetFirstStTCk;
extern boolean AirPres_bDgoCrkCoh_pDsThr;
extern boolean AirPres_bDgoFldCoh_pDsThr;
extern boolean AirPres_bDgoGrd_pDsThr;
extern boolean AirPres_bDgoORng_pDsThr;
extern boolean AirPres_bDgoStabCoh_pDsThr;
extern boolean AirPres_bDgoStallCoh_pDsThr;
extern boolean AirPres_bDgoThrCoh_pDsThr;
extern boolean AirPres_bDiagAftStall;
extern boolean AirPres_bMonRunCrkCoh_pDsThr;
extern boolean AirPres_bMonRunFldCoh_pDsThr;
extern boolean AirPres_bMonRunGrd_pDsThr;
extern boolean AirPres_bMonRunORng_pDsThr;
extern boolean AirPres_bMonRunStabCoh_pDsThr;
extern boolean AirPres_bMonRunStallCoh_pDsThr;
extern boolean AirPres_bMonRunThrCoh_pDsThr;
extern boolean AirPres_bMonWaitCrkCoh_pDsThr;
extern boolean INMNFPRESDIAG_bAirPresDgoStabCoh;
extern boolean INMNFPRESDIAG_bDetFirstStPrev;
extern boolean INMNFPRESDIAG_bDiagActIndicator;
extern boolean INMNFPRESDIAG_bWkuMainPrev;
extern uint8 AirPres_idxGrdDiagPresDsThr;
extern uint8 AirPres_pDsThrDif;
extern uint8 AirPres_pDsThrDif3;
extern uint8 AirPres_rOpDif;
extern uint8 AirPres_rOpMem;
extern uint8 AirPres_rPresThrSat;
extern uint8 AirPres_tiDly_CanPurg;
extern uint8 Diag_map_pressure_counter;
extern uint8 Diag_press_stall_to_run_counter;
extern uint16 AirPres_Manifold_PresAcq;
extern uint16 AirPres_pAirExtMem;
extern uint16 AirPres_pDsThrFldMem;
extern uint16 AirPres_pDsThrOpMem;
extern uint16 AirPres_pFrzDsThrDiagGrd;
extern uint16 AirPres_rBSVClc;
extern uint16 AirPres_sThrClc;
extern uint16 Diag_min_pressure_in_crank;
extern uint16 Ext_pAirExtStrt;
extern uint16 Ext_pDsThrStrt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INMNFPRESDIAG_vidAirPressSens(void);
void INMNFPRESDIAG_vidAirPressSens1(void);
void INMNFPRESDIAG_vidCanPurgVerif(void);
void INMNFPRESDIAG_vidDetectInCrank(void);
void INMNFPRESDIAG_vidDetectionEnabled(void);
void INMNFPRESDIAG_vidDftPres_GrdPres(void);
void INMNFPRESDIAG_vidDftPres_PresLim(void);
void INMNFPRESDIAG_vidDftPres_Reinit(void);
void INMNFPRESDIAG_vidDftPres_Stall(void);
void INMNFPRESDIAG_vidDftPresFullload(void);
void INMNFPRESDIAG_vidDftPresNormOper(void);
void INMNFPRESDIAG_vidDftPresStallRun(void);
void INMNFPRESDIAG_vidDiagAuthFulLoad(void);
void INMNFPRESDIAG_vidDiagFctStab(void);
void INMNFPRESDIAG_vidInitOutput(void);
void INMNFPRESDIAG_vidMfPrDiagBfStart(void);
void INMNFPRESDIAG_vidMfPrDiagDrStart(void);
void INMNFPRESDIAG_vidMnfPresDiagAuth(void);
void INMNFPRESDIAG_vidMnfPresDiagGrd(void);
void INMNFPRESDIAG_vidMnfPresDiagInit(void);
void INMNFPRESDIAG_vidMnfPresDiagLim(void);
void INMNFPRESDIAG_vidMngActivStart(void);
void INMNFPRESDIAG_vidNoAirPressSens(void);
void INMNFPRESDIAG_vidNoAirPressSens1(void);
void INMNFPRESDIAG_vidPrsDiagStallIni(void);
void INMNFPRESDIAG_vidRefPressFreeze(void);
void INMNFPRESDIAG_vidThrCohAuth(void);
void INMNFPRESDIAG_vidThrCohDiag(void);
void INMNFPRESDIAG_vidUpdtMnfPresCrnk(void);
void INMNFPRESDIAG_vidUpdtMnfPresStll(void);


#endif /* INMNFPRESDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/

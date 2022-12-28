/***************************************************************************
;**
;** FILE NAME      : TOILEST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TOILEST_L_H
#define TOILEST_L_H

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

extern const uint8  TOILEST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Eng_bIniTOil;
extern boolean TOILEST_btOilEstEngRunRstPrev;
extern boolean TOILEST_btOilEstEngStopRstPrev;
extern uint8 Eng_stTOilCalc;
extern uint8 Eng_tiInvldTAir;
extern uint8 TOILEST_u8DeltaEngTOilExtTAir;
extern sint16 Eng_tOilCorEngCh_MP;
extern sint16 Eng_tOilCorEngRun_MP;
extern sint16 Eng_tOilCorExtCnd_MP;
extern sint16 Eng_tOilEstimEngRun;
extern sint16 Eng_tOilEstimEngRunRaw;
extern sint16 Eng_tOilEstimEngStopRaw_MP;
extern sint16 Eng_tOilEstimIni;
extern sint16 Eng_tOilEstimIni1_MP;
extern sint16 Eng_tOilEstimIni2_MP;
extern sint16 Eng_tOilEstimIni3_MP;
extern sint16 Eng_tOilEstimPrec;
extern sint16 Eng_tOilEstimRaw;
extern sint16 Eng_tOilWaPmpOff_MP;
extern sint16 Eng_tOilWaPmpOn_MP;
extern uint16 Eng_rCorTOilIni_MP;
extern uint16 Eng_tiFilTOilEngRun_MP;
extern sint32 Eng_tOilEngRunFil_MP;
extern sint32 Eng_tOilEstimEngStop;
extern sint32 TOILEST_s32tOilEngRunFiltMem;
extern sint32 TOILEST_s32tOilEstEngStopFiltMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TOILEST_vidCalcThuilBruteMotTour(void);
void TOILEST_vidCalcThuileInit(void);
void TOILEST_vidCalcThuileMoteurCoupe(void);
void TOILEST_vidCalcThuileMotTournant(void);
void TOILEST_vidCalculerThuile(void);
void TOILEST_vidCalculEtatEstimateur(void);
void TOILEST_vidInitialiser(void);
void TOILEST_vidInitOutput(void);
void TOILEST_vidPowerLatch(void);
void TOILEST_vidReconfigurerThuile(void);
void TOILEST_vidSelectionnerThuile(void);


#endif /* TOILEST_L_H */

/*-------------------------------- end of file -------------------------------*/

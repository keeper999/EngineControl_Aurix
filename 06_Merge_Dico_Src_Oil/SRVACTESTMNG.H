/***************************************************************************
;**
;** FILE NAME      : SRVACTESTMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SRVACTESTMNG_H
#define SRVACTESTMNG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ACC_PED_NOK                       4
#define ACTION_EN_COURS                   2
#define ACTION_TERMINEE_OK                3
#define ActrTstMng_TiDecrNMot_SC          5
#define ARRET_DU_PILOTAGE                 5
#define BRAKE_PED_NOK                     5
#define CIRCUIT_OUVERT                    1
#define CIRCUIT_OUVERT_CTP2               6
#define CIRCUIT_OUVERT_GV                 4
#define CLUTCH_PED_NOK                    6
#define COURT_CIRCUIT_AGGRAVE             6
#define COURT_CIRCUIT_MASSE               2
#define COURT_CIRCUIT_MASSE_CTP2          7
#define COURT_CIRCUIT_MASSE_GV            5
#define COURT_CIRCUIT_PLUS                3
#define COURT_CIRCUIT_PLUS_CTP2           8
#define COURT_CIRCUIT_PLUS_GV             6
#define DEFAUT_1_CTP                      4
#define DEFAUT_2_CTP                      5
#define DEFAUT_DEBIT_INJECTEUR            18
#define DEFAUT_ELEC_CMDE                  6
#define DEFAUT_ELECTRIQUE                 1
#define DEFAUT_FREQUENCE                  7
#define DEFAUT_FUITE_PRES_RAIL            17
#define DEFAUT_RICHESSE_BLOQUE_PAUVRE     4
#define DEFAUT_RICHESSE_BLOQUE_RICHE      5
#define DEFAUT_VOLET                      4
#define DEFAUT_VOLET_BLOQUE               5
#define DEFAUT_VOLET_RESTE_OUVERT         6
#define DEFAUT_VVT_DYN                    5
#define DEFAUT_VVT_STAT                   4
#define ECU_NOK                           0
#define GEAR_BOX_NOK                      7
#define GMV_ACT_TEST_CTP                  4
#define HORS_PLAGE_SIGNAL                 5
#define HPPMP_FRM_NOK                     10
#define HPPMP_MONTEE_PRAIL_NOK            9
#define HPPMP_PRAIL_NOK                   11
#define INJDONE_BOBINE_NOK                4
#define PAS_DE_DEFAUT                     0
#define PILOTAGE_NON_LANCE                1
#define PRES_FUEL_NOK                     4
#define PROBLEME                          4
#define REGIME_MOTEUR_NOK                 3
#define TEMP_WATER_NOK                    8
#define TEST_CONDITION_OK                 255
#define UBAT_NOK                          1
#define VANNE_COLLEE                      5
#define VANNE_ENCRASSEE                   4
#define VEHICLE_SPEED_NOK                 2
#define VVT_DFT_NOK                       10

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

extern const boolean  ActrTestMng_bInhCondAccPed;
extern const boolean  Srv_bInhCohRespActrTstThr_C;
extern const boolean  Srv_bInhFailStpActrTstThr_C;
extern const uint16  ActrTstMng_TiDlyNMot;
extern const uint16  Afts_nTarIdlVlvActTest_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ActrTestMng_bInhFRM;
extern boolean Afts_bAcvVlvActTest_nTarIdl;
extern boolean Srv_bActrTstEna;
extern boolean Srv_bTestCdn;
extern boolean Srv_bTestCdnRunning;
extern uint8 Srv_stActrTstFeedback;
extern uint8 Srv_stTestDftCdn;
extern uint16 Afts_nTarIdlVlvActTest;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Srv_EveRst_ActrTstMng(void);
void Srv_SdlMid_ActrTstMng(void);


#endif /* SRVACTESTMNG_H */

/*-------------------------------- end of file -------------------------------*/

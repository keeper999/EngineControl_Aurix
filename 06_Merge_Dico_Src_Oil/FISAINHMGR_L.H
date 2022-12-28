/***************************************************************************
;**
;** FILE NAME      : FISAINHMGR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FISAINHMGR_L_H
#define FISAINHMGR_L_H

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

extern const uint8  FISAINHMGR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Demarrage_poussette;
extern boolean Detection_consommateurs_actifs;
extern boolean Detection_demarrage_poussette;
extern boolean Ext_nEngCrkInf;
extern boolean Ext_uBattMesDeltaSup;
extern sint16 Ext_uBattMes_prev;
extern sint16 TqRes_tqMaxRes_prev;
extern uint16 Ext_uBattMesDelta;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FISAINHMGR_vidCrankingState(void);
void FISAINHMGR_vidFisaCaseDetermin(void);
void FISAINHMGR_vidFisaLearningInhib(void);
void FISAINHMGR_vidInhibObservInst(void);
void FISAINHMGR_vidInitOutput(void);
void FISAINHMGR_vidMoveModeRefugeLean(void);
void FISAINHMGR_vidMoveModeRefugeRich(void);
void FISAINHMGR_vidReconfigManagement(void);


#endif /* FISAINHMGR_L_H */

/*-------------------------------- end of file -------------------------------*/

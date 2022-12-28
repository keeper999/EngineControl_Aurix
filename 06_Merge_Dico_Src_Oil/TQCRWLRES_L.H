/***************************************************************************
;**
;** FILE NAME      : TQCRWLRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQCRWLRES_L_H
#define TQCRWLRES_L_H

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

extern const uint8  TQCRWLRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TQCRWLRES_bCPtAcvDyTqResCrwlPrev;
extern boolean TQCRWLRES_bCPtAcvStTqResCrwlPrev;
extern uint32 TQCRWLRES_u32Filtre1Mem;
extern uint32 TQCRWLRES_u32Filtre2Mem;
extern sint16 TqRes_tqCrwlResDyn;
extern sint16 TqRes_tqCrwlResDynNoSat_MP;
extern sint16 TqRes_tqCrwlResSat_MP;
extern sint16 TqRes_tqCrwlResStat;
extern sint16 TqRes_tqCrwlResStatNoSat_MP;
extern sint16 TqRes_tqMaxClu;
extern sint16 TqRes_tqReqClu;
extern uint16 TqRes_tqCrwlResPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQCRWLRES_vidCalcResRampageDyn(void);
void TQCRWLRES_vidCalcResRampageStat(void);
void TQCRWLRES_vidFilterCplBVMP(void);
void TQCRWLRES_vidInitOutput(void);
void TQCRWLRES_vidReserveRampBVMP(void);


#endif /* TQCRWLRES_L_H */

/*-------------------------------- end of file -------------------------------*/

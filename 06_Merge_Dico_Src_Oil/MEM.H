/***************************************************************************
;**
;** FILE NAME      : MEM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MEM_H
#define MEM_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
#include "MEM_Macro.h"
#include "NVMSRV.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DEFAULT_DTC                       16777215
#define GD_NB_DFTCXTMAX                   40
#define GD_NB_DFTMEMMAX                   30
#define GD_NODTC_LNS                          ( 972 )
#define GD_NODTC_C_LNS                        ( 972 )

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

extern const uint32  GD_NoDTC_C[GD_NODTC_C_LNS];
extern const uint8  MEM_AllowEepSave;
extern const uint16  GD_DID_dstAbsKm_C;
extern const uint16  GD_DID_nEng_C;
extern const uint16  GD_DID_rAccP_C;
extern const uint16  GD_DID_spdVeh_C;
extern const uint16  GD_DID_tCoMes_C;
extern const uint16  GD_DID_tiCurVehTmr_C;
extern const uint16  GD_DID_uBattMes_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 GD_NoDTC[GD_NODTC_LNS];
extern uint16 GD_DID_dstAbsKm;
extern uint16 GD_DID_nEng;
extern uint16 GD_DID_rAccP;
extern uint16 GD_DID_spdVeh;
extern uint16 GD_DID_tCoMes;
extern uint16 GD_DID_tiCurVehTmr;
extern uint16 GD_DID_uBattMes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MEM_vidMngEveCDThUp(uint16 u16IdxDft);
void MEM_vidMngEveDftClr(uint16 u16IdxDft);
void MEM_vidMngEveFrfRec(uint16 u16IdxDft);
void MEM_vidMngEveInit(void);
void MEM_vidMngEveKeyOn(void);
void MEM_vidMngEveRstDft(void);
void MEM_vidMngEveRstDftCal(void);
void MEM_vidMngEveRstDftObd(void);
void MEM_vidMngEveStObdRec(uint16 u16IdxDft);


#endif /* MEM_H */

/*-------------------------------- end of file -------------------------------*/

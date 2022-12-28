/***************************************************************************
;**
;** FILE NAME      : PREDES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PREDES_H
#define PREDES_H

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

extern const boolean  PredEs_bAcvOKOscN_C;
extern const boolean  PredEs_bBypTi3LstCgtClc_C;
extern const boolean  PredEs_bChgOKN2EgdChgDir_C;
extern const boolean  PredEs_bForcAcvRecBuf_C;
extern const boolean  PredEs_bTrigBufNEsSet_C;
extern const sint8  PredEs_tiIncErrOkEgdChgDir_C;
extern const uint8  PredEs_bAcvInfoCpl_C;
extern const uint8  PredEs_facFilN2Dec_C;
extern const uint8  PredEs_nLim2Inc1_C;
extern const uint8  PredEs_noCaseBuf_C;
extern const uint8  PredEs_noCgtPhaEng_C;
extern const uint8  PredEs_noFirstTrigBufNEs_C;
extern const uint8  PredEs_noLim2Inc_C;
extern const uint8  PredEs_nStaEgdLoThd2_C;
extern const uint8  PredEs_nThdAcvFct_C;
extern const uint8  PredEs_nVldOKN2Egd_C;
extern const uint16  PredEs_tiDlyStaEgdHiThd_C;
extern const uint16  PredEs_tiUncrtTrigFct_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean PredEs_bDetSlowNPred;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PredEs_Sdl10ms_PredEs(void);
void PredEs_vidEntryInit(void);


#endif /* PREDES_H */

/*-------------------------------- end of file -------------------------------*/

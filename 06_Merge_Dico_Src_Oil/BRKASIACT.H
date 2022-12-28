/***************************************************************************
;**
;** FILE NAME      : BRKASIACT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BRKASIACT_H
#define BRKASIACT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQSYS_PDELTABRKASI_M_LNS              ( 5 )
#define TQSYS_PDELTABRKASI_M_COLS              ( 5 )
#define TQSYS_PDELTAREQBRKASI_T_COLS           ( 5 )
#define TQSYS_PEXTBRKASIX_A_COLS               ( 5 )
#define TQSYS_TAIRBRKASIX_A_COLS               ( 6 )
#define TQSYS_TIENGSTRTBRKASI_M_LNS           ( 6 )
#define TQSYS_TIENGSTRTBRKASI_M_COLS           ( 6 )
#define TQSYS_TOILBRKASIY_A_COLS               ( 6 )
#define TQSYS_TQLOSSBRKASIY_A_COLS             ( 5 )

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

extern const boolean  TqSys_bAcvBrkAsi_C;
extern const boolean  TqSys_bAcvBrkAsiImdtStra_C;
extern const uint8  TqSys_pDeltaHysBrkAsi_C;
extern const uint8  TqSys_spdVehThdBrkAsi_C;
extern const uint8  TqSys_tAirBrkAsiX_A[TQSYS_TAIRBRKASIX_A_COLS];
extern const uint8  TqSys_tOilBrkAsiY_A[TQSYS_TOILBRKASIY_A_COLS];
extern const uint16  TqSys_pDeltaBrkAsi_M[TQSYS_PDELTABRKASI_M_LNS][TQSYS_PDELTABRKASI_M_COLS];
extern const uint16  TqSys_pDeltaReqBrkAsi_T[TQSYS_PDELTAREQBRKASI_T_COLS];
extern const uint16  TqSys_pExtBrkAsiX_A[TQSYS_PEXTBRKASIX_A_COLS];
extern const uint16  TqSys_pExtThdBrkAsi_C;
extern const uint16  TqSys_pStgThdBrkAsi_C;
extern const uint16  TqSys_rAccPThdBrkAsi_C;
extern const uint16  TqSys_tiBrkAsiACMax_C;
extern const uint16  TqSys_tiBrkAsiAltMax_C;
extern const uint16  TqSys_tiDeceAcvBrkAsi_C;
extern const uint16  TqSys_tiEngStrtBrkAsi_M[TQSYS_TIENGSTRTBRKASI_M_LNS][TQSYS_TIENGSTRTBRKASI_M_COLS];
extern const uint16  TqSys_tiInhACWaitMax_C;
extern const uint16  TqSys_tiRlsAltWaitMax_C;
extern const uint16  TqSys_tqLossBrkAsiY_A[TQSYS_TQLOSSBRKASIY_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 TqSys_stBrkAsi;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void BRKASIACT_vidEntryInit(void);
void TqSys_Sdl10ms_BrkAsi(void);


#endif /* BRKASIACT_H */

/*-------------------------------- end of file -------------------------------*/

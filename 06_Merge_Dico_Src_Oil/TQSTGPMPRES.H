/***************************************************************************
;**
;** FILE NAME      : TQSTGPMPRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQSTGPMPRES_H
#define TQSTGPMPRES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQRES_AGSTRWHLTHR_T_COLS               ( 8 )
#define TQRES_AGVSTRWHL_A_COLS                 ( 8 )
#define TQRES_NENGSTGPMPRES_A_COLS             ( 8 )
#define TQRES_SPDVEHSTGPMPRES_A_COLS           ( 8 )
#define TQRES_TQSTGPMPRES_M_LNS               ( 8 )
#define TQRES_TQSTGPMPRES_M_COLS               ( 8 )

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

extern const boolean  TqRes_bAcvCdnAgStgPmpRes_C;
extern const boolean  TqRes_bAcvStgPmpRes_C;
extern const uint8  TqRes_agvStrWhl_A[TQRES_AGVSTRWHL_A_COLS];
extern const uint8  TqRes_facFilAgStgPmpRes_C;
extern const uint8  TqRes_facFilAvgStgPmpRes_C;
extern const uint8  TqRes_spdThrStgPmpRes_C;
extern const uint8  TqRes_spdVehStgPmpRes_A[TQRES_SPDVEHSTGPMPRES_A_COLS];
extern const uint8  TqRes_tiCdnStgPmpStgPmpRes_C;
extern const uint8  TqRes_tiCdnStrWhlStgPmpRes_C;
extern const sint16  TqRes_tCoThrStgPmpRes_C;
extern const sint16  TqRes_tqDecMaxStgPmpRes_C;
extern const uint16  TqRes_agStrWhlThr_T[TQRES_AGSTRWHLTHR_T_COLS];
extern const uint16  TqRes_nEngStgPmpRes_A[TQRES_NENGSTGPMPRES_A_COLS];
extern const uint16  TqRes_pStgPmpThrStgPmpRes_C;
extern const uint16  TqRes_tiThrEngRunStgPmpRes_C;
extern const uint16  TqRes_tqIncMaxStgPmpRes_C;
extern const uint16  TqRes_tqStgPmpRes_M[TQRES_TQSTGPMPRES_M_LNS][TQRES_TQSTGPMPRES_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TqRes_tqStgPmpRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQSTGPMPRES_vidEntry_10ms(void);
void TQSTGPMPRES_vidEntryInit(void);


#endif /* TQSTGPMPRES_H */

/*-------------------------------- end of file -------------------------------*/

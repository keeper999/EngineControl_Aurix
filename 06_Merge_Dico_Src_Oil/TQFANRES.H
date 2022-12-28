/***************************************************************************
;**
;** FILE NAME      : TQFANRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQFANRES_H
#define TQFANRES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQRES_FACCMPFANRES_M_LNS              ( 8 )
#define TQRES_FACCMPFANRES_M_COLS              ( 8 )
#define TQRES_NENGFANRES_A_COLS                ( 8 )
#define TQRES_SPDVEHFANRES_A_COLS              ( 8 )

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

extern const uint8  TqRes_facCmpFanRes_M[TQRES_FACCMPFANRES_M_LNS][TQRES_FACCMPFANRES_M_COLS];
extern const uint8  TqRes_facFilTqFanLoss_C;
extern const uint8  TqRes_rSpdThrFanRes_C;
extern const uint8  TqRes_tiFanRes_C;
extern const sint16  TqRes_tqDecMaxFanRes_C;
extern const uint16  TqRes_nEngFanRes_A[TQRES_NENGFANRES_A_COLS];
extern const uint16  TqRes_spdVehFanRes_A[TQRES_SPDVEHFANRES_A_COLS];
extern const uint16  TqRes_tqCmpB1FanLoss_C;
extern const uint16  TqRes_tqCmpGvB2FanLoss_C;
extern const uint16  TqRes_tqCmpPvB2FanLoss_C;
extern const uint16  TqRes_tqCmpPvGvB2FanLoss_C;
extern const uint16  TqRes_tqFanResB1_C;
extern const uint16  TqRes_tqFanResB2_C;
extern const uint16  TqRes_tqFanResC_C;
extern const uint16  TqRes_tqIncMaxFanRes_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TqRes_bCdnFanRes;
extern uint16 TqRes_tqFanRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQFANRES_vidEntry_10ms(void);
void TQFANRES_vidEntryInit(void);


#endif /* TQFANRES_H */

/*-------------------------------- end of file -------------------------------*/

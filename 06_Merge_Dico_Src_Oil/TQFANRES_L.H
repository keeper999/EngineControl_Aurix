/***************************************************************************
;**
;** FILE NAME      : TQFANRES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQFANRES_L_H
#define TQFANRES_L_H

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

extern const uint8  TQFANRES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TQFANRES_bCdnFanResPrev;
extern boolean TQFANRES_bCmdHiSpdFanPrev;
extern boolean TQFANRES_bCmdLoSpdFanPrev;
extern boolean TQFANRES_bGmvTrigger;
extern boolean TQFANRES_bTurnOffDelayIn;
extern boolean TqRes_bCdnHiSpdFanRes_MP;
extern boolean TqRes_bCdnLnrSpdFanRes_MP;
extern boolean TqRes_bCdnLoSpdFanRes_MP;
extern boolean TqRes_bCmdHiSpdFan;
extern boolean TqRes_bCmdLoSpdFan;
extern boolean TqRes_bRstTqFanLoss_MP;
extern boolean TqRes_bTarHiSpdFan;
extern boolean TqRes_bTarLoSpdFan;
extern uint32 TQFANRES_u32FiltredFanStrtLosMem;
extern uint8 TqRes_rSpdFanReq;
extern uint8 TqRes_tiFanRes;
extern uint16 TQFANRES_u16tiFanResCpt1;
extern uint16 TQFANRES_u16tiFanResCpt2;
extern uint16 TQFANRES_u16tiFanResCpt3;
extern uint16 TqRes_facCmpFanRes;
extern uint16 TqRes_tqFanResNotSat_MP;
extern uint16 TqRes_tqFanResSat_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQFANRES_vidCalculReserveGMV(void);
void TQFANRES_vidConditionReserveGMV(void);
void TQFANRES_vidCoupleTransitoireGMV(void);
void TQFANRES_vidHiSpdDelayOn(void);
void TQFANRES_vidInitOutput(void);
void TQFANRES_vidLoSpdDelayOn(void);
void TQFANRES_vidReserveGMV(void);
void TQFANRES_vidStFanDelayOff(void);
void TQFANRES_vidTraitementEntreesGMV(void);


#endif /* TQFANRES_L_H */

/*-------------------------------- end of file -------------------------------*/

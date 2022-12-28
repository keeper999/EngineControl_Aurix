/***************************************************************************
;**
;** FILE NAME      : FCTDIAGWG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FCTDIAGWG_L_H
#define FCTDIAGWG_L_H

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

extern const uint8  FCTDIAGWG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean FCTDIAGWG_bTimeout1;
extern boolean FCTDIAGWG_bTimerInit;
extern boolean Wg_bDgoStuckCls_pTrbAct;
extern boolean Wg_bDgoStuckOp_pTrbAct;
extern boolean Wg_bMonRunStuckCls_pTrbAct;
extern boolean Wg_bMonRunStuckOp_pTrbAct;
extern uint8 Wg_tiStuckOp;
extern uint16 Wg_pAirExtMesInter;
extern uint16 Wg_pTrbActStuckOp;
extern uint16 Wg_pUsThrNatStuckCls;
extern uint16 Wg_tiStuckCls;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FCTDIAGWG_vidAcvActStuckCls(void);
void FCTDIAGWG_vidAcvActStuckOp(void);
void FCTDIAGWG_vidClcpUsThrNat(void);
void FCTDIAGWG_vidCls_pTrbAct(void);
void FCTDIAGWG_vidInit(void);
void FCTDIAGWG_vidInitOutput(void);
void FCTDIAGWG_vidOp_pTrbAct(void);
void FCTDIAGWG_vidPTrb_ActStuckOp(void);
void FCTDIAGWG_vidStuckCls_pTrbAct(void);


#endif /* FCTDIAGWG_L_H */

/*-------------------------------- end of file -------------------------------*/

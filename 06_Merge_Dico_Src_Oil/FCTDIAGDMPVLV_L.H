/***************************************************************************
;**
;** FILE NAME      : FCTDIAGDMPVLV_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FCTDIAGDMPVLV_L_H
#define FCTDIAGDMPVLV_L_H

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

extern const uint8  FCTDIAGDMPVLV_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean DmpVlv_bDgoStuckCls_DmpVlv;
extern boolean DmpVlv_bDgoStuckOp_DmpVlv;
extern boolean DmpVlv_bEndCntOscStuckCls;
extern boolean DmpVlv_bMonRunStuckCls_DmpVlv;
extern boolean DmpVlv_bMonRunStuckOp_DmpVlv;
extern boolean DmpVlv_bOscStuckCls;
extern boolean DmpVlv_bPresOscStuckCls;
extern boolean FCTDIAGDMPVLV_bOscStuckCls_prev;
extern boolean FCTDIAGDMPVLV_bPresOscStuck_prev;
extern boolean FCTDIAGDMPVLV_bTimeOut1;
extern boolean FCTDIAGDMPVLV_bTimeOut2;
extern boolean FCTDIAGDMPVLV_bTimer1Init_prev;
extern boolean FCTDIAGDMPVLV_bTimer2Init_prev;
extern boolean FCTDIAGDMPVLV_bTimer3Init_prev;
extern uint32 DmpVlv_tiAcvCntOscStuckCls;
extern uint32 FCTDIAGDMPVLV_u32FilterKMem;
extern uint8 DmpVlv_ctDiagStuckCls;
extern uint8 DmpVlv_ctPresOscStuckCls;
extern uint8 DmpVlv_ctThdDiagStuckCls;
extern sint16 DmpVlv_pDiagFiltStuckCls;
extern uint16 DmpVlv_pAirExtMesInter;
extern uint16 DmpVlv_pThdBoostPres;
extern uint16 DmpVlv_pThdBoostPresWgStuckOp;
extern uint16 DmpVlv_tiStuckCls;
extern uint16 DmpVlv_tiStuckOp;
extern uint16 FCTDIAGDMPVLV_u16FilterOutput;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FCTDIAGDMPVLV_vidCntDiagStuckCls(void);
void FCTDIAGDMPVLV_vidCondStuckCls(void);
void FCTDIAGDMPVLV_vidCondStuckOp(void);
void FCTDIAGDMPVLV_vidDetOscStuckCls(void);
void FCTDIAGDMPVLV_vidDiagStuckOp(void);
void FCTDIAGDMPVLV_vidDmpVlv_Op(void);
void FCTDIAGDMPVLV_vidDmpVlvCls(void);
void FCTDIAGDMPVLV_vidInit(void);
void FCTDIAGDMPVLV_vidInitOutput(void);


#endif /* FCTDIAGDMPVLV_L_H */

/*-------------------------------- end of file -------------------------------*/

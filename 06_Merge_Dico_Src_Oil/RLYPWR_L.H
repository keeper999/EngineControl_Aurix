/***************************************************************************
;**
;** FILE NAME      : RLYPWR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RLYPWR_L_H
#define RLYPWR_L_H

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

/* enum st61 */
#define RLYPWRMNG_INITCLOSED              0
#define RLYPWRMNG_INITOPEN                1
#define RLYPWRMNG_OPEN                    2
#define RLYPWRMNG_CLOSE                   3
#define RLYPWRMNG_ACTRCUTWAIT             4
/*extern uint8 RlyPwrMng_stPwrRlyCmd;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  RLYPWR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 RlyPwrMng_stPwrRlyCmd;
extern boolean Actionneurs_Int;
extern boolean EcuSt_bPwrlLong;
extern boolean Rly_bTiEndHldRlyActr;
extern boolean RlyPwr_bActivTempoEcoBatt;
extern boolean RlyPwr_bAcvModEcoBatt;
extern boolean RLYPWR_bEcuStPwrlLongPrev;
extern boolean RlyPwr_bEndDiag;
extern boolean RlyPwr_bEngStopped;
extern boolean RlyPwr_bInitTempoEcoBatt;
extern uint8 RlyPwr_ctInhDiagOcCmdActr;
extern uint8 RLYPWR_u8PowercondstatePrev;
extern uint16 Rly_InitTimer;
extern uint16 Rly_tiEndHldRlyActr;
extern uint16 RlyPwr_tiAftEndDiag;
extern uint16 RlyPwr_tiEcuStPwrlLong;
extern uint16 RlyPwr_tiWaitAcvModEcoBatt;
extern uint16 RlyPwr_tiWaitOp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void RLYPWR_vidFinMaintRelPrinp(void);
void RLYPWR_vidInitbEndDiag(void);
void RLYPWR_vidInitbPwrLong(void);
void RLYPWR_vidInitOutput(void);
void RLYPWR_vidInitTempo(void);
void RLYPWR_vidInitWaitAcvModEcoBatt(void);
void RLYPWR_vidInitWaitPwrlEnd(void);
void RLYPWR_vidPrevEcuStPwrlLong(void);
void RLYPWR_vidRlyMngHldReq(void);
void RLYPWR_vidRlyPwrActrTst(void);
void RLYPWR_vidRlyPwrAcvCond(void);
void RLYPWR_vidRlyPwrAcvModEcoBatt(void);
void RLYPWR_vidRlyPwrCtlMng(void);
void RLYPWR_vidRlyPwrDiagActif(void);
void RLYPWR_vidRlyPwrDiagInh(void);
void RLYPWR_vidRlyPwrDiagNotInh(void);
void RLYPWR_vidRlyPwrEcoBatt(void);
void RLYPWR_vidRlyPwrMngDiagNotInh(void);
void RLYPWR_vidRlyPwrTestPwrlLong(void);
void RLYPWR_vidWaitAcvModEcoBatt(void);
void RLYPWR_vidWaitAcvModEcoBattCalib(void);
void RLYPWR_vidWaitPwrlEnd(void);


#endif /* RLYPWR_L_H */

/*-------------------------------- end of file -------------------------------*/

/***************************************************************************
;**
;** FILE NAME      : SYNCCKCMMONDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCCKCMMONDIAG_L_H
#define SYNCCKCMMONDIAG_L_H

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

extern const uint8  SYNCCKCMMONDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Sync_bCmnCdnCkDiag;
extern boolean Sync_bCmnCdnExCmDiag;
extern boolean Sync_bCmnCdnInCmDiag;
extern boolean Sync_bDgoNoSigCk;
extern boolean Sync_bDgoNoSigExCm;
extern boolean Sync_bDgoNoSigInCm;
extern boolean Sync_bDgoSigLossCk;
extern boolean Sync_bDgoSigLossExCm;
extern boolean Sync_bDgoSigLossInCm;
extern boolean Sync_bEnaDiagNoSigCk;
extern boolean Sync_bEnaDiagNoSigExCam;
extern boolean Sync_bEnaDiagNoSigInCam;
extern boolean Sync_bMinTimeElpdExCam;
extern boolean Sync_bMinTimeElpdInCam;
extern boolean Sync_bMonRunNoSigCk;
extern boolean Sync_bMonRunNoSigExCm;
extern boolean Sync_bMonRunNoSigInCm;
extern boolean Sync_bMonRunSigLossCk;
extern boolean Sync_bMonRunSigLossExCm;
extern boolean Sync_bMonRunSigLossInCm;
extern boolean SYNCCKCMMONDIAG_bAcqCrkEngExPrev;
extern boolean SYNCCKCMMONDIAG_bAcqCrkEngInPrev;
extern boolean SYNCCKCMMONDIAG_bCrkExCamSynPrev;
extern boolean SYNCCKCMMONDIAG_bCrkExCamTimeout;
extern boolean SYNCCKCMMONDIAG_bCrkInCamSynPrev;
extern boolean SYNCCKCMMONDIAG_bCrkInCamTimeout;
extern uint8 SYNCCKCMMONDIAG_u8CrkExTimerCnt;
extern uint8 SYNCCKCMMONDIAG_u8CrkInTimerCnt;
extern uint8 SYNCCKCMMONDIAG_u8ExCmTimerCnt;
extern uint8 SYNCCKCMMONDIAG_u8InCmTimerCnt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SYNCCKCMMONDIAG_vidCkMonRst(void);
void SYNCCKCMMONDIAG_vidClcDgoNoSigCk(void);
void SYNCCKCMMONDIAG_vidClDgoLossCk(void);
void SYNCCKCMMONDIAG_vidClDgoLossExCm(void);
void SYNCCKCMMONDIAG_vidClDgoLossInCm(void);
void SYNCCKCMMONDIAG_vidClDgoNoSgExCm(void);
void SYNCCKCMMONDIAG_vidClDgoNoSgInCm(void);
void SYNCCKCMMONDIAG_vidClEnaDgoNoSg(void);
void SYNCCKCMMONDIAG_vidClEveCkMonRst(void);
void SYNCCKCMMONDIAG_vidCmnCdnCkDiag(void);
void SYNCCKCMMONDIAG_vidCmnCdnExCmDgo(void);
void SYNCCKCMMONDIAG_vidCmnCdnInCmDgo(void);
void SYNCCKCMMONDIAG_vidGenrCkDiagEve(void);
void SYNCCKCMMONDIAG_vidGenrCmDiagEve(void);
void SYNCCKCMMONDIAG_vidGenrLossExCm(void);
void SYNCCKCMMONDIAG_vidGenrLossInCm(void);
void SYNCCKCMMONDIAG_vidGenrNoSigCk(void);
void SYNCCKCMMONDIAG_vidGenrNoSigExCm(void);
void SYNCCKCMMONDIAG_vidGenrNoSigInCm(void);
void SYNCCKCMMONDIAG_vidGenrSigLossCk(void);
void SYNCCKCMMONDIAG_vidIniEnaDgoNoSg(void);
void SYNCCKCMMONDIAG_vidInitOutput(void);
void SYNCCKCMMONDIAG_vidLossCkMonCl(void);
void SYNCCKCMMONDIAG_vidLossCkMonIni(void);
void SYNCCKCMMONDIAG_vidLossCkMonRst(void);
void SYNCCKCMMONDIAG_vidLossExCmCl(void);
void SYNCCKCMMONDIAG_vidLossExCmIni(void);
void SYNCCKCMMONDIAG_vidLossInCmCl(void);
void SYNCCKCMMONDIAG_vidLossInCmIni(void);
void SYNCCKCMMONDIAG_vidNoSgCkMonClcn(void);
void SYNCCKCMMONDIAG_vidNoSgExCmIni(void);
void SYNCCKCMMONDIAG_vidNoSgExCmMonCl(void);
void SYNCCKCMMONDIAG_vidNoSgInCmCl(void);
void SYNCCKCMMONDIAG_vidNoSgInCmIni(void);
void SYNCCKCMMONDIAG_vidNoSigCkMonIni(void);
void SYNCCKCMMONDIAG_vidNoSigCkMonRst(void);


#endif /* SYNCCKCMMONDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/

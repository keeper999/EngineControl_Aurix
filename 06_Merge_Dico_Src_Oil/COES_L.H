/***************************************************************************
;**
;** FILE NAME      : COES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COES_L_H
#define COES_L_H

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

/* enum st24 */
#define COES_STOPSEQ_THIRDSTEP            1
#define COES_STOPSEQ_INIT                 2
#define COES_STOPSEQ_FIRSTSTEP            4
#define COES_STOPSEQ_SECONDSTEP           8
/*extern uint8 COES_stStopSeq;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  COES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 COES_stStopSeq;
extern boolean CoEs_bAcvVlvSysLockPosnSTTEs_MP;
extern boolean CoEs_bCmdActrSTTEs;
extern boolean CoEs_bCndEngHiLim_MP;
extern boolean CoEs_bCndEngLoLim_MP;
extern boolean COES_bCoPTStEngRunPrev;
extern boolean CoEs_bCutActrSTTEs;
extern boolean CoEs_bCutOffIgSTTEs;
extern boolean COES_bCutOffSeqInterrupRS;
extern boolean CoEs_bDlyCanPurgCls;
extern boolean CoEs_bDlyCanPurgCls_MP;
extern boolean CoEs_bDlyEndIntrHiSpd_MP;
extern boolean CoEs_bDlyEndIntrLoSpd_MP;
extern boolean CoEs_bEndIntrCdnEngSpd_MP;
extern boolean CoEs_bEngStopReq;
extern boolean CoEs_bIntrSTTEs;
extern boolean CoEs_bIntrSTTEsHiEngSpdPrev;
extern boolean CoEs_bIntrSTTEsLoEngSpdPrev;
extern boolean CoEs_bPctlAcvClsCanPurgSTTEs;
extern boolean CoEs_bPctlAcvClsCanPurgSTTEs_MP;
extern boolean CoEs_bPctlAcvVlvSysLockPosnSTTEs;
extern boolean COES_btiDlyCanPurgClsPrev;
extern boolean CoEs_btiDlyCmdCanPurgIntSTTEPrev;
extern boolean CoEs_btiDlyCmdVlvSysIntrSTTEPrev;
extern boolean CoEs_bVlvSysLockPosn;
extern uint32 COES_u32FiltredEngTthClcFilMem;
extern uint8 CoEs_tiCutOffIg;
extern uint8 COES_u8CoStrtRStrtStEngStrtPrev;
extern uint16 CoEs_nEngTthClcFil;
extern uint16 COES_u16CoEs_nEngTthClcFilPrev;
extern uint16 COES_u16Counter_CoEs_bIntrSTTEs;
extern uint16 COES_u16TiDlyCanPurgCls;
extern uint16 COES_u16TiDlyCmdCanPurgIntrSTTEs;
extern uint16 COES_u16TiDlyCmdVlvSysIntrSTTEs;
extern uint16 COES_u16TiDlyIntrSTTEsHiEngSpd;
extern uint16 COES_u16TiDlyIntrSTTEsLoEngSpd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void COES_vidCutOffSequenceInterrupt(void);
void COES_vidDetecterInterrupSeqArret(void);
void COES_vidFiltrerRegimeDentADent(void);
void COES_vidImposeDelaiActivCanister(void);
void COES_vidImposerDelaiActivVanos(void);
void COES_vidInitOutput(void);
void COES_vidInterdirInterrupSeqArret(void);
void COES_vidObserverVanneCanisFermee(void);
void COES_vidObserverVanosPositionRef(void);
void COES_vidSelectionnerCommandArret(void);
void COES_vidSequencerPhaseArretSTT(void);


#endif /* COES_L_H */

/*-------------------------------- end of file -------------------------------*/

/***************************************************************************
;**
;** FILE NAME      : JDD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef JDD_L_H
#define JDD_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define JBSI_ABSTDTCNOCXT_COLS                 ( 30 )
#define JBSI_AU16IDXDFTNOCXT_COLS              ( 30 )
#define JBSI_AU32IDXBUFFER01NOCXT_COLS         ( 30 )
#define JBSI_AU32IDXBUFFER02NOCXT_COLS         ( 30 )
#define JBSI_AU32IDXBUFFER03NOCXT_COLS         ( 30 )
#define JBSI_AU32IDXBUFFER04NOCXT_COLS         ( 30 )
#define JBSI_AU32IDXBUFFER05NOCXT_COLS         ( 30 )
#define JBSI_AU32IDXBUFFER06NOCXT_COLS         ( 30 )
#define JBSI_AU32IDXBUFFER07NOCXT_COLS         ( 30 )
#define JBSI_AU32IDXBUFFER08NOCXT_COLS         ( 30 )
#define JBSI_AU32IDXBUFFER09NOCXT_COLS         ( 30 )
#define JBSI_AU32IDXBUFFER10NOCXT_COLS         ( 30 )
#define JBSI_AU32NODTCNOCXT_COLS               ( 30 )
#define JBSI_AU8IDXFLTTOCXTNOCXT_COLS          ( 30 )
#define JBSI_AU8STCXTRECNOCXT_COLS             ( 30 )
#define JDD_BEVTFAILUREPERM_COLS               ( 972 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st112 */
#define JBSI_IDLE                         0
#define JBSI_ATTENTE_ENVOI_TRAME_1        1
#define JBSI_ATTENTE_ENVOI_TRAME_2        2
#define JBSI_ATTENTE_ENVOI_TRAME_3        3
#define JBSI_ATTENTE_ACQUITTEMENT         4
#define JBSI_ATTENTE_RESTART_PROCESSUS    5
/*extern uint8 Jbsi_etat_automate;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  JDD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Jbsi_etat_automate;
extern boolean Jbsi_abstDTCNoCxt[JBSI_ABSTDTCNOCXT_COLS];
extern boolean Jbsi_ack_bsi;
extern boolean JDD_bEvtFailurePerm[JDD_BEVTFAILUREPERM_COLS];
extern uint32 Jbsi_au32idxBuffer01NoCxt[JBSI_AU32IDXBUFFER01NOCXT_COLS];
extern uint32 Jbsi_au32idxBuffer02NoCxt[JBSI_AU32IDXBUFFER02NOCXT_COLS];
extern uint32 Jbsi_au32idxBuffer03NoCxt[JBSI_AU32IDXBUFFER03NOCXT_COLS];
extern uint32 Jbsi_au32idxBuffer04NoCxt[JBSI_AU32IDXBUFFER04NOCXT_COLS];
extern uint32 Jbsi_au32idxBuffer05NoCxt[JBSI_AU32IDXBUFFER05NOCXT_COLS];
extern uint32 Jbsi_au32idxBuffer06NoCxt[JBSI_AU32IDXBUFFER06NOCXT_COLS];
extern uint32 Jbsi_au32idxBuffer07NoCxt[JBSI_AU32IDXBUFFER07NOCXT_COLS];
extern uint32 Jbsi_au32idxBuffer08NoCxt[JBSI_AU32IDXBUFFER08NOCXT_COLS];
extern uint32 Jbsi_au32idxBuffer09NoCxt[JBSI_AU32IDXBUFFER09NOCXT_COLS];
extern uint32 Jbsi_au32idxBuffer10NoCxt[JBSI_AU32IDXBUFFER10NOCXT_COLS];
extern uint32 Jbsi_au32noDTCNoCxt[JBSI_AU32NODTCNOCXT_COLS];
extern uint32 Jbsi_cpt_temp_local_av_synchro;
extern uint8 Jbsi_au8idxFltToCxtNoCxt[JBSI_AU8IDXFLTTOCXTNOCXT_COLS];
extern uint8 Jbsi_au8stCxtRecNoCxt[JBSI_AU8STCXTRECNOCXT_COLS];
extern uint8 Jbsi_nbre_panne_en_attente;
extern uint8 Jbsi_tempo_envoi_trame;
extern uint8 Jbsi_tempo_restart_processus;
extern uint8 Jbsi_tentative_envoi;
extern uint8 Jbsi_tentative_envoi_processus;
extern uint8 Jbsi_time_out;
extern uint8 JDD_u8JbsiEtatAutomatePrev;
extern uint16 Jbsi_au16idxDftNoCxt[JBSI_AU16IDXDFTNOCXT_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void JDD_vidAcqFrame55F(void);
void JDD_vidAcqFrame772(void);
void JDD_vidAcquisitionCptBeforSyncro(void);
void JDD_vidCaptureData(uint16 u16IdxDft);
void JDD_vidDftClrData(void);
void JDD_vidFillBufferContextFailure(uint16 u16IdxDft);
void JDD_vidIni(void);
void JDD_vidInitOutput(void);
void JDD_vidReqClrDft(void);
void JDD_vidRstAckBsi(void);
void JDD_vidSetStateDtcFugitf(uint16 u16IdxDft);
void JDD_vidSetStateDtcPresent(uint16 u16IdxDft);
void JDD_vidStartFaultSending(void);
void JDD_vidStateJbsiIdle(void);
void JDD_vidStateJbsiWaitAcquittement(void);
void JDD_vidStateJbsiWaitRestartProc(void);
void JDD_vidStateJbsiWaitSendFrame1(void);
void JDD_vidStateJbsiWaitSendFrame2(void);
void JDD_vidStateJbsiWaitSendFrame3(void);
void JDD_vidTimeCounterBeforeSynchro(void);
void JDD_vidTransmissionFramesMngr(void);
void JDD_vidTransToIdleOrSendFrame1(void);


#endif /* JDD_L_H */

/*-------------------------------- end of file -------------------------------*/

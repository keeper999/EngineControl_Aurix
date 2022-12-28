/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR component                     */
/*                                                                            */
/*!Module          : LinIf_Types_Internal                                    */
/*!Description     : The internal types used in the LinIf                    */
/*                                                                            */
/*!\File             LinIf_Types_Internal.h                                  */
/* \par              The internal types used in the LinIf                    */
/*!Scope           : Private Component                                       */
/*                                                                            */
/*!Target          : All                                                     */
/*                                                                            */
/*!Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/20_LinIf/0$*/
/* $Revision::   1.13     $$Author::   MTAYMOUR       $$Date::   Feb 19 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef LINIF_TYPES_INTERNAL_H
#define LINIF_TYPES_INTERNAL_H

#include "Std_Types.h"
#include "Compiler.h"
#include "LinIf_Types.h"


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

typedef P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtLinSendFrame) 
(
    VAR(uint8, AUTOMATIC), 
    P2VAR(Lin_PduType, AUTOMATIC, AUTOMATIC)
);


typedef P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtLinGotoSleep) 
(
    VAR(uint8, AUTOMATIC)
);

typedef P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtGoToSleepInternal) 
(
    VAR(uint8, AUTOMATIC)
);


typedef P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtLinWakeup) 
(
    VAR(uint8, AUTOMATIC)
);

typedef P2FUNC(Lin_StatusType, LINIF_APPL_CODE, LinIf_tpfenuLinGetStatus) 
(
    VAR(uint8, AUTOMATIC),
    P2VAR(P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA), AUTOMATIC, AUTOMATIC)
);

typedef P2FUNC(void, LINIF_APPL_CODE, LinIf_tpfvidLinWakeupValidation) 
(
    void
);


typedef P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtLinTrcvSetOpMode) 
(
    VAR(uint8, AUTOMATIC),
    VAR(LinTrcv_TrcvModeType, AUTOMATIC)
);

typedef P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtLinTrcvGetOpMode) 
(
    VAR(uint8, AUTOMATIC),
    P2VAR(LinTrcv_TrcvModeType, AUTOMATIC, LINIF_APPL_DATA)
);

typedef P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtLinTrcvGetWuReason) 
(
    VAR(uint8, AUTOMATIC),
    P2VAR(LinIf_TrcvWakeupReasonType, AUTOMATIC, LINIF_APPL_DATA)
);

typedef P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtTrcvSetWakeupMode) 
(
    VAR(uint8, AUTOMATIC),
    VAR(LinIf_TrcvWakeupModeType, AUTOMATIC)
);

typedef P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtLinTrcvCheckWakeup) 
(
    VAR(uint8, AUTOMATIC)
);


typedef struct
{
#if(LinIf_u8TP_SUPPORTED == STD_ON)
    VAR(boolean, AUTOMATIC) bTPDataAvailable;
    VAR(boolean, AUTOMATIC) bTPStartNewFrame;
    VAR(boolean, AUTOMATIC) bTPRxFrameSetupDone;
    VAR(boolean, AUTOMATIC) bTPUDSRPFMaxReached;
    VAR(boolean, AUTOMATIC) bTpFrameSent;
#endif
    VAR(boolean, AUTOMATIC) bGotoSleepFlag;
    VAR(boolean, AUTOMATIC) bSendGotoSleep;
    VAR(boolean, AUTOMATIC) bSendWakeup;
    VAR(boolean, AUTOMATIC) bIsNConfOngoing;
    VAR(boolean, AUTOMATIC) bIsEventTrigCol;
    VAR(boolean, AUTOMATIC) bNConfMRFFailed;
    
    VAR(uint8, AUTOMATIC) u8IFChannelState;
    VAR(uint8, AUTOMATIC) u8IFCommState;
    VAR(uint8, AUTOMATIC) au8DataBuffer[LinIf_u8FRAME_SIZE];
    VAR(uint8, AUTOMATIC) u8TimeToNextEntry;
    VAR(uint8, AUTOMATIC) u8FrameTimeCounter;
    VAR(uint8, AUTOMATIC) u8NCSlaveIndex;
#if(LinIf_u8TP_SUPPORTED == STD_ON)    
    VAR(uint8, AUTOMATIC) u8TPChannelState;
    VAR(uint8, AUTOMATIC) u8TPCommState;
    VAR(uint8, AUTOMATIC) au8TPDataBuffer[LinIf_u8FRAME_SIZE];
    VAR(uint8, AUTOMATIC) u8CurrTPFrameLength;
    VAR(uint8, AUTOMATIC) u8TPNextSeqNum;
    VAR(uint8, AUTOMATIC) u8TPLastAdrsdNAD;
    VAR(uint8, AUTOMATIC) u8CurrentTxTimeout;
#endif
    VAR(uint16, AUTOMATIC) u16NextEntryIndex;
    VAR(uint16, AUTOMATIC) u16IntSchEntryIndex;
#if(LinIf_u8TP_SUPPORTED == STD_ON)
    VAR(uint16, AUTOMATIC) u16TPTimoutTimer;
    VAR(uint16, AUTOMATIC) u16TPUDSPendFrameCnt;
    VAR(PduLengthType, AUTOMATIC) udtTPRemData;
    VAR(PduLengthType, AUTOMATIC) udtTPCurrRxMsgLen;
#endif
    P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST) 
        pkstrCurrScheduleTab;
    P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST) 
        pkstrPrevScheduleTab;
    P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) 
        pkstrCurrentFrame;
    P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST) 
        pkstrBufferedSchTab;
#if(LinIf_u8TP_SUPPORTED == STD_ON)
    P2CONST(LinIf_tstrTPTransmittedNSdu, AUTOMATIC, LINIF_CALIB_CONST) 
        pkstrCurrTPTxNsdu;
    P2CONST(LinIf_tstrTPReceivedNSdu, AUTOMATIC, LINIF_CALIB_CONST) 
        pkstrCurrTPRecNsdu;
#endif
} LinIf_tstrChannelVars;                                             


typedef struct
{
    VAR(LinIf_tpfudtLinTrcvSetOpMode, AUTOMATIC) pfudtSetOpMode;
    VAR(LinIf_tpfudtLinTrcvGetOpMode, AUTOMATIC) pfudtGetOpMode;
    VAR(LinIf_tpfudtLinTrcvGetWuReason, AUTOMATIC) pfudtGetBusWuReason;
    VAR(LinIf_tpfudtLinTrcvCheckWakeup, AUTOMATIC) pfudtCheckWakeup;
    VAR(LinIf_tpfudtTrcvSetWakeupMode, AUTOMATIC) pfudtSetWakeupMode;
} LinIf_tstrLinTrcvDrvRef;

typedef struct
{
    VAR(LinIf_tpfudtLinSendFrame, AUTOMATIC) pfudtSendFrame;
    VAR(LinIf_tpfudtLinGotoSleep, AUTOMATIC) pfudtGotoSleep;
    VAR(LinIf_tpfudtGoToSleepInternal, AUTOMATIC) pfudtGotoSleepInternal;
    VAR(LinIf_tpfudtLinWakeup, AUTOMATIC) pfudtWakeup;
    VAR(LinIf_tpfenuLinGetStatus, AUTOMATIC) pfenuGetStatus;
    VAR(LinIf_tpfvidLinWakeupValidation, AUTOMATIC) pfvidWakeupValidation;
} LinIf_tstrLinDrvRef;


typedef struct
{
    VAR(boolean, AUTOMATIC) bWakeUpNotification;
    VAR(uint8, AUTOMATIC) u8TransceiverChannelId;
    VAR(LinIf_tstrLinTrcvDrvRef, AUTOMATIC) strTrcvRef;
} LinIf_tstrTransceiverDrvConfig;

typedef enum
{
    LinIf_NORMAL,
    LinIf_SLEEP
} LinIf_tenuChannelStartupState;



typedef struct
{
    /* Range: 0x00..0x3f*/
    VAR(uint8, AUTOMATIC) u8ResponseErrorBitPos;
    P2CONST(Dem_EventIdType, AUTOMATIC, LINIF_CFG_CONST) 
        pkudtEResponseErrDetected;
    P2CONST(Dem_EventIdType, AUTOMATIC, LINIF_CFG_CONST) 
        pkudtENCNoResponse;
} LinIf_tstrChannelSlaveParams;


typedef P2FUNC(void, LINIF_APPL_CODE, LinIf_tpfvidEnterCriticalSec)(void);
typedef P2FUNC(void, LINIF_APPL_CODE, LinIf_tpfvidExitCriticalSec)(void);



typedef struct
{
	/*! pkstrBufferedSchTab's Critical sections in LinIf_vidSTMMain function */
    VAR(LinIf_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterSecSchTab000;
    VAR(LinIf_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitSecSchTab000;
	
    /*! pkstrBufferedSchTab's Critical sections in LinIf_ScheduleRequest function */
	VAR(LinIf_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterSecSchTab001;
    VAR(LinIf_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitSecSchTab001;
	
	 /*! bGotoSleepFlag's Critical sections in LinIf_GotoSleep function */
	VAR(LinIf_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterSecGotoSleep000;
    VAR(LinIf_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitSecGotoSleep000;
	
	
	/*! bGotoSleepFlag's Critical sections in LinIf_Wakeup function */
    VAR(LinIf_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterSecGotoSleep001;
    VAR(LinIf_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitSecGotoSleep001;
	
	
	/*! bGotoSleepFlag's Critical sections in LinIf_MainFunction function */
	VAR(LinIf_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterSecGotoSleep002;
    VAR(LinIf_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitSecGotoSleep002;
	
	
		/*! bGotoSleepFlag's Critical sections in LinIf_CheckWakeup function */
    VAR(LinIf_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterSecGotoSleep003;
    VAR(LinIf_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitSecGotoSleep003;
	
	
	
	/*! bSendWakeup's Critical sections in LinIf_Wakeup function */
	VAR(LinIf_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterSecSendWkup000;
    VAR(LinIf_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitSecSendWkup000;
	
	
	/*! bSendWakeup's Critical sections in LinIf_MainFunction function */
	VAR(LinIf_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterSecSendWkup001;
    VAR(LinIf_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitSecSendWkup001;
	
		/*! bSendWakeup's Critical sections in LinIf_CheckWakeup function */
	VAR(LinIf_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterSecSendWkup002;
    VAR(LinIf_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitSecSendWkup002;
	
} LinIf_tstrChannelCriticalSec;

typedef struct
{
    VAR(uint8, AUTOMATIC) u8LinIfChannelId;
    VAR(uint8, AUTOMATIC) u8LinChannelId;
	
    /*VAR(uint8, AUTOMATIC) u8DrvRefIndex;*/
	P2CONST(LinIf_tstrLinDrvRef, AUTOMATIC, LINIF_CALIB_CONST) 
									pkstrDrvRef;
    VAR(boolean, AUTOMATIC) bTrcvPresent;
    VAR(uint8, AUTOMATIC) u8TrcvDrvConfIndex;
    VAR(LinIf_tenuChannelStartupState, AUTOMATIC) enuStartupState;
    VAR(uint8, AUTOMATIC) u8ComMChannelId;
    VAR(uint8, AUTOMATIC) u8SlavesIndex;
    VAR(uint8, AUTOMATIC) u8NumberOfSlaves;
    VAR(uint32, AUTOMATIC) u32WakeupSourceType;
} LinIf_tstrChannelStaticConf;


#endif /* LINIF_TYPES_INTERNAL_H */

/*-------------------------------- end of file -------------------------------*/

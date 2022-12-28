/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR component                     */
/*                                                                            */
/*!Module          : LinIf_Types                                             */
/*!Description     : The global types of LinIf                                */
/*                                                                            */
/*!\File             LinIf_Types.h                                           */
/* \par              The global types of LinIf                                */
/*!Scope           : Public                                                  */
/*                                                                            */
/*!Target          : All                                                     */
/*                                                                            */
/*!Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/20_LinIf/0$*/
/* $Revision::   1.19     $$Author::   MTAYMOUR       $$Date::   Mar 30 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef LINIF_TYPES_H
#define LINIF_TYPES_H

#include "Std_Types.h"
#include "Compiler.h"
#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"
#include "Dem.h"
#include "LinIf_Cfg.h"

/*!\Description the Maximum LIN Frame Data Size */
#define LinIf_u8FRAME_SIZE      8

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/*!\Description    A temp. solution to fix integration problem between LinIf and
				   EcuM till the migration to revision 3. For reference check 
				   TeamTrack ticket 03882                                     */
/*!\ This ticket is fixed and LinIf_ConfigType is now type of PB general configration */
/*typedef void LinIf_ConfigType;*/



/*!\Description    Index of the schedule table that is selectable and followed 
                    by LIN Interface. Value is unique per LIN 
                    channel/controller, but not per ECU. \n
    \Range          0..255  \n                                                */
typedef uint8 LinIf_SchHandleType;

/*!\Description    This type denotes the wake up reason detected by the LIN 
                    transceiver in detail.  \n
    \Range          LINIF_TRCV_WU_ERROR,
                    LINIF_TRCV_WU_NOT_SUPPORTED,
                    LINIF_TRCV_WU_BY_BUS,
                    LINIF_TRCV_WU_BY_PIN,
                    LINIF_TRCV_WU_INTERNALLY,
                    LINIF_TRCV_WU_RESET,
                    LINIF_TRCV_WU_POWER_ON  \n                                */
typedef enum
{
    LINIF_TRCV_WU_ERROR,
    LINIF_TRCV_WU_NOT_SUPPORTED,
    LINIF_TRCV_WU_BY_BUS,
    LINIF_TRCV_WU_BY_PIN,
    LINIF_TRCV_WU_INTERNALLY,
    LINIF_TRCV_WU_RESET,
    LINIF_TRCV_WU_POWER_ON
} LinIf_TrcvWakeupReasonType;

/*!\Description    Wake up operating modes of the LIN Transceiver Driver.\n
    \Range          LINIF_TRCV_WU_ENABLE,
                    LINIF_TRCV_WU_DISABLE,
                    LINIF_TRCV_WU_CLEAR  \n                                */
typedef enum
{
    LINIF_TRCV_WU_ENABLE,
    LINIF_TRCV_WU_DISABLE,
    LINIF_TRCV_WU_CLEAR 
} LinIf_TrcvWakeupModeType;

/*!\Description    This type denotes which Schedule table can be requested
                    by LIN TP during diagnostic session .\n
    \Range          LINTP_APPLICATIVE_SCHEDULE,
                    LINTP_DIAG_REQUEST,
                    LINTP_DIAG_RESPONSE  \n                                */
typedef enum
{
    LINTP_APPLICATIVE_SCHEDULE,
    LINTP_DIAG_REQUEST,
    LINTP_DIAG_RESPONSE
} LinTp_Mode;


/* LINIF schedule Table types */

/*!\Description    A schedule table can be executed in two different modes.\n
    \Range          LinIf_RUN_CONTINUOUS,
                    LinIf_RUN_ONCE  \n                                        */
typedef enum 
{
    LinIf_RUN_CONTINUOUS,
    LinIf_RUN_ONCE
} LinIf_tenuSchRunMode;

/*!\Description    Defines, where a schedule table shall be proceeded in case 
                    if it has been interrupted by a RUN-ONCE table. \n
    \Range          LinIf_START_FROM_BEGINNING,
                    LinIf_CONTINUE_AT_IT_POINT  \n                            */
typedef enum 
{
    LinIf_START_FROM_BEGINNING,
    LinIf_CONTINUE_AT_IT_POINT
} LinIf_tenuSchResumePosition;

/*!\Description    Represents a schedule entry .\n                           */
typedef struct 
{
    /*!\Description    Index of this entry in the schedule table. \n
        \Range          0..255  \n                                            */
    VAR(uint8, AUTOMATIC) u8EntryIndex;
    /*!\Description    Delay to next entry in schedule table in multiple of 
                        timebase ticks \n
        \Range          0..255 \n
        \Unit           Timebase ticks                                        */
    VAR(uint8, AUTOMATIC) u8Delay;
    /*!\Description    Index of the collision resolving schedule table if the 
                        entry contains an event triggered frame \n
        \Range          0..65535  \n                                          */
    VAR(uint16, AUTOMATIC) u16ColResolvTabIndex;
    /*!\Description    Index of the frame attached to this schedule entry. \n
        \Range          0..65535  \n                                          */
    VAR(uint16, AUTOMATIC) u16FrameIndex;
} LinIf_tstrSchEntry;

/*!\Description        Represents a schedule table \n */
typedef struct 
{
    VAR(LinIf_SchHandleType, AUTOMATIC) kudtIndex;
    VAR(LinIf_tenuSchRunMode, AUTOMATIC) enuRunMode;
    VAR(LinIf_tenuSchResumePosition, AUTOMATIC) enuResumePosition;
    VAR(uint16, AUTOMATIC) u16NumberOfEntries;
    VAR(uint16, AUTOMATIC) u16StartEntryIndex;
} LinIf_tstrScheduleTable;

/*********************************End of figure 23*****************************/
/******************************************************************************/
/********************************Start of figure 22****************************/

typedef enum
{
    LinIf_UNCONDITIONAL           = 0x00, /* 0000 0000 */
    LinIf_EVENT_TRIGGERED         = 0x01, /* 0000 0001 */
    LinIf_SPORADIC                = 0x02, /* 0000 0010 */
    LinIf_SRF                     = 0x20, /* 0010 0000 */
    LinIf_MRF                     = 0x60, /* 0110 0000 */
    LinIf_UNASSIGN                = 0x61, /* 0110 0001 */
#if (LinIf_bOPTIONAL_REQ_SUPPORT == STD_ON)
    LinIf_CONDITIONAL             = 0x62, /* 0110 0011 */
    LinIf_ASSIGN_NAD              = 0x63, /* 0110 0010 */
#endif
    LinIf_FREE                    = 0x64, /* 0110 0100 */
    LinIf_SAVE_CONFIGURATION      = 0x65, /* 0110 0101 */
    LinIf_ASSIGN_FRM_ID_RANGE     = 0x66, /* 0110 0110 */
    LinIf_ASSIGN                  = 0x67  /* 0110 0111 */
} LinIf_tenuFrameType;

typedef enum
{
    LinIf_CLASSIC,
    LinIf_ENHANCED
} LinIf_tenuChecksumType;


typedef enum
{
    LinIf_TX_PDU,
    LinIf_RX_PDU,
    LinIf_SLAVE_TO_SLAVE_PDU,
    LinIf_INTERNAL_PDU
}LinIf_tenuFrameDirection;



typedef P2FUNC(Std_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtTriggerTxULType)
(
    VAR(PduIdType, AUTOMATIC),
    P2VAR(PduInfoType, AUTOMATIC, AUTOMATIC)
);

/*void <User_TxConfirmation>( 
    PduIdType TxPduId 
)*/

typedef P2FUNC(void, LINIF_APPL_CODE, LinIf_tpfvidTxConfirmULType)
(
    VAR(PduIdType, AUTOMATIC)
);

/*void <User_RxIndication>( 
    PduIdType RxPduId, 
    PduInfoType* PduInfoPtr 
) */

typedef P2FUNC(void, LINIF_APPL_CODE, LinIf_tpfvidRxIndicationULType)
(
    VAR(PduIdType, AUTOMATIC),
    P2VAR(PduInfoType, AUTOMATIC, AUTOMATIC)
);

/*void <User>_ScheduleRequestConfirmation( 
    NetworkHandleType network, 
    LinIf_SchHandleType schedule 
)*/
typedef P2FUNC(void, LINIF_APPL_CODE, LinIf_tpfvidSchReqConfULType)
( 
    VAR(NetworkHandleType, AUTOMATIC), 
    VAR(LinIf_SchHandleType, AUTOMATIC)
);

/*void <User>_GotoSleepConfirmation( 
    NetworkHandleType channel, 
    boolean success 
)*/
typedef P2FUNC(void, LINIF_APPL_CODE, LinIf_tpfvidGotoSleepConfULType)
( 
    VAR(NetworkHandleType, AUTOMATIC), 
    VAR(boolean, AUTOMATIC)
);

/*void <User>_WakeupConfirmation( 
    NetworkHandleType channel, 
    boolean success 
)*/
typedef P2FUNC(void, LINIF_APPL_CODE, LinIf_tpfvidWakeupConfULType)
( 
    VAR(NetworkHandleType, AUTOMATIC), 
    VAR(boolean, AUTOMATIC)
);



typedef struct
{
    VAR(LinIf_tpfudtTriggerTxULType, AUTOMATIC) pfudtTxTriggerTransmit;
    VAR(LinIf_tpfvidTxConfirmULType, AUTOMATIC) pfvidTxConfirmationUL;
    VAR(PduIdType, AUTOMATIC) udtLinIfTxPduId;
    VAR(PduIdType, AUTOMATIC) udtLinIfTxPduRef;
} LinIf_tstrTxPduParams;

typedef struct
{
    VAR(LinIf_tpfvidRxIndicationULType, AUTOMATIC) pfvidRxIndication;
    VAR(PduIdType, AUTOMATIC) udtLinIfRxPduRef;
} LinIf_tstrRxPduParams;

typedef struct
{
    VAR(uint8, AUTOMATIC) u8Pid;
    P2CONST(Dem_EventIdType, AUTOMATIC,LINIF_CALIB_CONST) pkudtLinIfEResponse;
    VAR(uint8, AUTOMATIC) u8Length; 
    VAR(uint8, AUTOMATIC) u8MaxFrameTime;
    VAR(LinIf_tenuFrameType, AUTOMATIC) enuFrameType;
    VAR(LinIf_tenuChecksumType, AUTOMATIC) enuChecksumType;
    VAR(LinIf_tenuFrameDirection, AUTOMATIC) enuFrameDirection;
    P2CONST(LinIf_tstrTxPduParams, AUTOMATIC, LINIF_CALIB_CONST) pkstrTxParams;
    P2CONST(LinIf_tstrRxPduParams, AUTOMATIC, LINIF_CALIB_CONST) pkstrRxParams;
    P2CONST(uint8, AUTOMATIC, LINIF_CALIB_CONST) pku8FixedFrameData;
    VAR(uint8, AUTOMATIC) u8NumberOfSubFrames;
    VAR(uint16, AUTOMATIC) u16SubFramesIndex;
    VAR(boolean, AUTOMATIC) bIsSporadic;
    /*VAR(uint16, AUTOMATIC) u16SporadicIndex;*/
	P2VAR(boolean, AUTOMATIC, AUTOMATIC) pbSporadic;
    /* Desc: index of slave in the channel */
    /* Range: 0..0x0F, 0xFF */
    VAR(uint8, AUTOMATIC) u8ErrorSlaveIndex;
    /* Desc: index of slave for the node configuration command */
    /* Range: 0..0x0F, 0xFF */
    VAR(uint8, AUTOMATIC) u8NCSlaveIdx;
} LinIf_tstrFrame;


typedef struct
{
    VAR(uint8, AUTOMATIC) u8Priority;
    /*VAR(uint16, AUTOMATIC) u16FrameIndex;*/
	P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrame;
} LinIf_tstrSubstitutionFrame;


typedef struct
{
    /* index of the channel in the channel array*/
    VAR(uint8, AUTOMATIC) u8ChannelIndx;
    VAR(uint8, AUTOMATIC) u8NumberOfSchTabs;
    VAR(uint16, AUTOMATIC) u16ScheduleTablesIndex;
    VAR(LinIf_tpfvidSchReqConfULType, AUTOMATIC) pfvidSchReqConfrm;
    VAR(LinIf_tpfvidGotoSleepConfULType, AUTOMATIC) pfvidGotoSleepConfrm;
    VAR(LinIf_tpfvidWakeupConfULType, AUTOMATIC) pfvidWakeUpConfrm;
    VAR(uint8, AUTOMATIC) u8NumberOfFrames;
    VAR(uint16, AUTOMATIC) u16FramesIndex;
#if (LinIf_u8TP_SUPPORTED == STD_ON)
    VAR(uint16, AUTOMATIC) u16TpTransNsdusIndex;
    VAR(uint16, AUTOMATIC) u16NumberOfTransTp;
    VAR(uint16, AUTOMATIC) u16TpRecNsdusIndex;
    VAR(uint16, AUTOMATIC) u16NumberOfRecTp;
#endif
    VAR(uint8, AUTOMATIC) u8GotoSleepCmdTime;
    VAR(uint8, AUTOMATIC) u8WakeupCmdTime;
}LinIf_tstrChannelPBConf;


/*********************************End of figure 22*****************************/
/******************************************************************************/
/********************************Start of figure 24****************************/
/*************************************LinTp************************************/
#if (LinIf_u8TP_SUPPORTED == STD_ON)

typedef P2FUNC(void, LINIF_APPL_CODE, LinIf_tpfvidLinTpRxIndType) 
(
    VAR(PduIdType, AUTOMATIC),
    VAR(NotifResultType, AUTOMATIC)
);

typedef P2FUNC(void, LINIF_APPL_CODE, LinIf_tpfvidLinTpTxConfirmation)
( 
    VAR(PduIdType, AUTOMATIC), 
    VAR(NotifResultType, AUTOMATIC)
);

typedef P2FUNC(void, LINIF_APPL_CODE, LinIf_tpfvidLinTpChngParamConf)
( 
    VAR(PduIdType, AUTOMATIC), 
    VAR(NotifResultType, AUTOMATIC) 
);

typedef P2FUNC(BufReq_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtLinTpCopyTxData)
( 
    VAR(PduIdType, AUTOMATIC) , 
    P2VAR(PduInfoType, AUTOMATIC, AUTOMATIC) , 
    P2VAR(RetryInfoType, AUTOMATIC, AUTOMATIC) , 
    P2VAR(PduLengthType, AUTOMATIC, LINIF_VAR)  
);

typedef P2FUNC(BufReq_ReturnType, LINIF_APPL_CODE, LinIf_tpfudtLinTpCopyRxData)
( 
    VAR(PduIdType, AUTOMATIC) , 
    P2VAR(PduInfoType, AUTOMATIC, AUTOMATIC) , 
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC)  
);

typedef P2FUNC(BufReq_ReturnType,LINIF_APPL_CODE,LinIf_tpfudtTpStartOfReception)
( 
    VAR(PduIdType, AUTOMATIC) ,
	P2VAR(PduInfoType, AUTOMATIC, AUTOMATIC) , 	
    VAR(PduLengthType, AUTOMATIC) , 
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC)  
);

typedef struct
{
    VAR(uint8, AUTOMATIC) u8ChannelId;
    VAR(PduIdType, AUTOMATIC) u16TxNsduId;
    VAR(uint8, AUTOMATIC) u8NAD;
    VAR(PduIdType, AUTOMATIC) u16TxNsduRef;
    VAR(LinIf_tpfvidLinTpTxConfirmation, AUTOMATIC) pfvidTxConfirmation;
} LinIf_tstrTPTransmittedNSdu;

typedef struct
{
    VAR(PduIdType, AUTOMATIC) u16RxNsduRef;
    VAR(uint8, AUTOMATIC) u8NAD;
    VAR(uint16, AUTOMATIC) u16Dl;
    VAR(PduIdType, AUTOMATIC) u16RxNsduId;
    VAR(uint8, AUTOMATIC) u8ChannelId;
    VAR(LinIf_tpfvidLinTpRxIndType, AUTOMATIC) pfvidRxIndication;
} LinIf_tstrTPReceivedNSdu;


/*!\Description    This is the base type for the configuration of the LIN 
                    Transport Protocol A pointer to an instance of this 
                    structure will be used in the initialization of the LIN 
                    Transport Protocol. \n                                   */
typedef struct
{
    VAR(uint16, AUTOMATIC) u16NumberOfRxNsdus;
    VAR(uint16, AUTOMATIC) u16NumberOfTxNsdus;
    P2CONST(LinIf_tstrTPTransmittedNSdu, AUTOMATIC, LINIF_CALIB_CONST) 
                                                                   pkstrTxNsdus;
    P2CONST(LinIf_tstrTPReceivedNSdu, AUTOMATIC,LINIF_CALIB_CONST) pkstrRxNsdus;
    VAR(LinIf_tpfudtLinTpCopyTxData, AUTOMATIC) pfudtCopyTxData;
    VAR(LinIf_tpfudtLinTpCopyRxData, AUTOMATIC) pfudtCopyRxData;
    VAR(LinIf_tpfudtTpStartOfReception, AUTOMATIC) pfudtStartOfReception;
    VAR(uint16, AUTOMATIC) u16LinTpNAs;
    /* N_Cs = (0.9*N_Cr)-N_As */
    VAR(uint16, AUTOMATIC) u16LinTpNCs;
    VAR(uint16, AUTOMATIC) u16LinTpNCr;
    VAR(uint16, AUTOMATIC) u16LinTpP2Timing;
    VAR(uint16, AUTOMATIC) u16LinTpP2Max;
    VAR(uint16, AUTOMATIC) u16LinTpMaxUDSRPF;

} LinTp_ConfigType;
#endif

typedef struct
{
    VAR(uint16, AUTOMATIC) u16NumberOfTxFrames;
    P2CONST(LinIf_tstrChannelPBConf,AUTOMATIC,LINIF_CALIB_CONST) pkstrChannels;
    P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrames;
    P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST) 
                                                        pkstrScheduleTables;
    P2CONST(LinIf_tstrSchEntry, AUTOMATIC, LINIF_CALIB_CONST) 
                                                        pkstrScheduleEntries;
    P2CONST(LinIf_tstrSubstitutionFrame, AUTOMATIC, LINIF_CALIB_CONST)
                                                        pkstrSubstFrames;
    P2VAR(boolean, AUTOMATIC, LINIF_CALIB_CONST) pbSporadicFramesFlags;
	P2CONST(uint16, AUTOMATIC, LINIF_CALIB_CONST) pku16TxMappingTable;
} LinIf_ConfigType;

#endif /* LINIF_TYPES_H */

/*-------------------------------- end of file -------------------------------*/

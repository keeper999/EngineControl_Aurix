/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : AUTOSAR Communication Module                            */
/*                                                                            */
/* !Module          : Com                                                     */
/*                                                                            */
/* !File            : Com_Types.h                                             */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : ALL                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/03-Com/02_$*/
/* $Revision::   1.41                                                        $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file Com_Types.h
*
* \par
*   Declarations of Com Pos-build parameters data types                       */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup module Com
* This is the grouping of the Com module members.
* \{
*/
/******************************************************************************/

#ifndef COM_TYPES_H
#define COM_TYPES_H

#include "ComStack_Types.h"


#define Com_u8CNCL_TXSPP_FLG  	  1u  /*! for Tx IPDU*/
#define Com_u8INIT_TX_MO_FLG      4u  /*! for Tx IPDU*/

typedef uint8 Com_udtIPduInitiStatus;



/******************************************************************************/
/*! \Description The AUTOSAR COM modules signal object identifier.           */
/*! \Range: 0..<SignalIdmax>                                                  */
/*! Trace_To:                                                                 */
/******************************************************************************/
typedef uint16        Com_SignalIdType;

/******************************************************************************/
/*! \Description The COM Status Type.
             This is a status value returned by the API service
             Com_GetStatus().                                                 */
/*! Trace_To:                                                                 */
/******************************************************************************/
typedef     enum
{
    COM_UNINIT,         /* The AUTOSAR COM module is not initialized          */
    COM_INIT            /* The AUTOSAR COM module is initialized and usable   */
} Com_StatusType;

/******************************************************************************/
/*! \Description Defines Post Build configuration types used by the Main \n
                 PostBuild configuration ROM Structure \n */
/******************************************************************************/

/******************************************************************************/
/*! \Description Defines the I-PDU direction Symbols \n */
/******************************************************************************/
#define Com_u8DIRECTION_TX 0
#define Com_u8DIRECTION_RX 1

/******************************************************************************/
/*! \Description Defines a type of I-PDU lookup table structure \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description For Tx, is the index of this Ipdu in COM_akstrTxIPdu \n
                     For Rx, is the index of this Ipdu in COM_akstrRxIPdu \n
    */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16Index;

    /**************************************************************************/
    /*! \Description I-PDU direction \n
                     calculation method:  \n
                       if ComIPduDirection = RECEIVE then Com_u8DIRECTION_RX \n
                       if ComIPduDirection = SEND then Com_u8DIRECTION_TX \n
        \Range  Com_u8DIRECTION_RX, Com_u8DIRECTION_TX \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC)  u8Direction;
} Com_tstrIPduLookUp;

/******************************************************************************/
/*! \Description Defines the I-PDU Signal Processing Symbols \n */
/******************************************************************************/
#define Com_u8SIG_PROC_IMMEDIATE  0
#define Com_u8SIG_PROC_DEFERRED   1

/******************************************************************************/
/*! \Description Defines the I-PDU type Symbols \n */
/******************************************************************************/
#define Com_u8IPDU_TYPE_NORMAL   0
#define Com_u8IPDU_TYPE_TP       1

/******************************************************************************/
/*! \Description Defines a type of I-PDU FirstTimeout  \n
                 calculation method: \n
                     For Rx I-PDU:
                      SmallestFirstTimeout = the smallest configured  \n
                        ComSignalFirstTimeout or ComSignalGroupFirstTimeout \n
                        parameter of all the signalsand signal groups all \n
                        signals and signal groups without update-bits within \n
                        the I-PDU. \n
                     Com_tu16IPduFirstTimeout = \n
                                   SmallestFirstTimeout/ComRxTimeBase
                     For Tx I-PDU - equals to ComFirstTimeout/ComTxTimeBase \n
                      SmallestFirstTimeout = the smallest configured  \n
                        ComSignalFirstTimeout or ComSignalGroupFirstTimeout \n
                        parameter of all the signalsand signal groups all \n
                        signals and signal groups within \n
                        the I-PDU. \n
                     Com_tu16IPduFirstTimeout = \n
                                   SmallestFirstTimeout/ComTxTimeBase */
/******************************************************************************/
typedef uint32 Com_tu32IPduFirstTimeout;


/* --OPTIMIZATION Rx IPDU ROM FLAGs*/

/* 7              6             			  5  			              4                     3                   2            1                 0
   bfSigTimeout	   bfIPduFirstTimeout		  bfIPduTimeout	             bfType	          bfSigProcessing		    bfCallout	   bfIPduCounter     bfReplication*/

 
#define Com_u8RX_IPDUSIGPROCESSING     0x08 /*AUTOSAR*/
#define Com_u8RX_IPDUTYPE_MASK            	0x10 /*AUTOSAR*/
#define Com_u8RX_IPDUSIGTIMEOUT       0x80

typedef  uint8 Com_udtRxIPduFlags;
/******************************************************************************/
/*! \Description Defines a type of Rx I-PDU Structure \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index in COM_akstrIPduCalloutPointersArray of the I-PDU \n
                     callout function pointer if exists \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC)  u16IPduCalloutIndex;

    /**************************************************************************/
    /*! \Description Index in COM_akudtIPduSignalMapping to ID of the first \n
                     signal/signal group belongs in this I-PDU. \n
                     Signals/signal groups belong to the same I-PDU \n
                     are placed in COM_akudtIPduSignalMapping consicutively \n
                     and in the right order. \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC)  u16IPduSigMappingIndex;

    /**************************************************************************/
    /*! \Description Number of the signals/signal groups included \n
                     in this I-PDU   \n
                     calculation method: equals  \n
                        number of ComIPduSignalGroupRefs \n
                        + number of ComIPduSignalRefs \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC)  u16IPduNoOfSignals;

    /**************************************************************************/
    /*! \Description Index in COM_akstrIPduCounter to the I-PDU counter \n
                     structure  \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC)  u16IPduCounterIndex;

    /**************************************************************************/
    /*! \Description Index in COM_akstrIPduReplication to the I-PDU \n
                     Replication structure \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC)  u16IPduReplicationIndex;

    /**************************************************************************/
    /*! \Description Flags indicating optional/boolean parameters configured \n
                     for Rx I-PDU \n
                     calculation method: see Com_tbfRxIPduFlags \n
                     type definition \n */
    /**************************************************************************/
	VAR(Com_udtRxIPduFlags, AUTOMATIC) udteRxIPduFlags;

    /**************************************************************************/
    /*! \Description Index in COM_au8IPduBufferArray to the first byte of the \n
                     RAM buffer of this I-PDU \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32IPduBufferIndex;

    /**************************************************************************/
    /*! \Description I-PDU length in bytes \n
                     calculation method: \n
                       max_bit_pos = the maximum of ComBitPosition of all \n
                       signals/group signals belong to this I-PDU; \n
                       if(signal which has the max_bit_pos is of \n
                          UINT8_N/UINT8_DYN type) \n
                       { \n
                         length = length of the signal which has the \n
                         max_bit_pos; \n
                         ku16IPduLength = ((max_bit_pos-1)/8)+1 + length; \n
                       } \n
                       else \n
                       { \n
                         end_bit_pos = max_bit_pos + ComBitSize of the signal \n
                         which has the max_bit_pos; \n
                         u16IPduLength = ((end_bit_pos-1)/8)+1; \n
                       } \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16IPduLength;

    /**************************************************************************/
    /*! \Description Index in COM_au32TOTimerArray, Points to the RAM  \n
                     location which holds the run time timer variable \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16TOTimerIndex;

    /**************************************************************************/
    /*! \Description I-PDU based Timeout. Only valid on receiver side in case \n
                     I-PDU based deadline monitoring is needed. \n
                      calculation method: \n
                        the smallest configured ComSignalTimeout or \n
                        ComSignalGroupTimeout parameter of all the signals \n
                        and signal groups without update-bits within \n
                        without update-bits within the I-PDU. \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32Timeout;

    /**************************************************************************/
    /*! \Description Index to I-PDU based First Timeout. Only valid on \n
                     receiver side in case I-PDU based deadline monitoring is \n
                     needed. \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16FirstTimeoutIndex;

    /**************************************************************************/
    /*! \Description Index to the RAM counter which is used to store the \n
                     number of bytes sent or received when processing an \n
                     I-PDU of type TP. Indexes \n
                     COM_au16TpIPduByteCounterArray. \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16TpIPduByteCtrIndex;

    /**************************************************************************/
    /*! \Description Index to the start location of Handle IDs of I-PDU \n
                          groups which contain this I-PDU. Indexes \n
                          ComIPduToIPduGroupMappingArray . \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16IPduGroupMapIndex;

    /**************************************************************************/
    /*! \Description  Number of  I-PDU groups which contains this I-PDU \n
                          calculation method: \n
                             equals the number of I-PDU groups which \n
                             contains this I-PDU \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16NumberOfIPduGroups;

    /**************************************************************************/
    /*! \Description  ComIPduHandleId   \n */
    /**************************************************************************/
    VAR(PduIdType, AUTOMATIC) u16IPduId;

} Com_tstrRxIPdu;


/* -- OPTIMIZATION Rx IPDU ROM FLAGs*/

/* 7              6               5  			     4                     3               2                1                 0
            	   bfTMS		  bfMDT	             bfIPduTimeout	       bfType          bfSigProcessing  bfCallout	   bfIPduCounter   */

#define Com_u8TX_IPDUSIGPROCESSING     0x04 /*AUTOSAR*/
#define Com_u8TX_IPDUTYPE_MASK         	    0x08 /*AUTOSAR*/

#define Com_u8TX_IPDUTMS_MASK       		0x40 /*AUTOSAR*/

typedef  uint8 Com_udtTxIPduFlags;



/******************************************************************************/
/*! \Description Defines a type of Tx I-PDU CancelTransmitSupport flags \n
            calculation method: \n
                each Com_tstrTxIPdu has a flag in the array of \n
                Com_tu8IPduCancelTransmitSupport. the location of the flag is \n
                the PduId
                Flag value equals:
                TRUE  if ComTxIPduCancelTransmitSupport = 1 \n
                    configured \n
                    FALSE if ComTxIPduCancelTransmitSupport = 0 \n */
/******************************************************************************/
typedef uint8 Com_tu8IPduCancelTxSupport;

/******************************************************************************/
/*! \Description Defines a type of TxModeTimer  \n */
/******************************************************************************/
typedef uint32 Com_tu32TxModeTimer;

/******************************************************************************/
/*! \Description Defines the TxMode Symbols \n */
/******************************************************************************/
#define     Com_u8TX_MODE_DIRECT        0U
#define     Com_u8TX_MODE_MIXED         1U
#define     Com_u8TX_MODE_NONE          2U
#define     Com_u8TX_MODE_PERIODIC      3U

/******************************************************************************/
/*! \Description Defines a type of TxMode ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description TxMode \n
                     calculation method: equals ComTxModeMode \n
        \Range Com_u8TX_MODE_DIRECT, Com_u8TX_MODE_MIXED, \n
               Com_u8TX_MODE_NONE, Com_u8TX_MODE_PERIODIC \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8TxMode;

    /**************************************************************************/
    /*! \Description index to TxMode structure in the array which \n
                     corresponds to u8TxMode.  \n
                     When u8TxMode = Com_u8TX_MODE_NONE this parameter is \n
                     ignored \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16Index;
} Com_tstrTxMode;

/******************************************************************************/
/*! \Description Defines a type of TxModeDirect ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Number Of Repetitions Defines the number of repetitions \n
                     for the transmission mode DIRECT \n
                     calculation method: equals ComTxModeNumberOfRepetitions \n
        \Range 0..255 \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8NumberOfRepetitions;

    /**************************************************************************/
    /*! \Description Repetition Period Defines the repetition period in \n
                     multiple of ComTxTimeBase of the multiple transmissions \n
                     calculation method: \n
                        equals ComTxModeRepetitionPeriod/ComTxTimeBase \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32RepetitionPeriod;

    /**************************************************************************/
    /*! \Description Index in COM_au8TxModeRepetitionsCounter to RAM \n
                     variable holding the count of repetitions \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16RepetitionsCtrIndex;

    /**************************************************************************/
    /*! \Description Index in COM_au32TxModeTimer to RAM \n
                     variable holding the the timer of repetition period \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16RepetitionPrdTmrIx;
} Com_tstrTxModeDirect;

/******************************************************************************/
/*! \Description Defines a type of TxModePeriodic ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Defines the period in multiple of ComTxTimeBase between  \n
                     the start of the I-PDU by Com_IpduGroupControl and the \n
                      first transmission request in case ComTxModeMode is \n
                      configured to PERIODIC \n
                     calculation method: \n
                        equals ComTxModeTimeOffset/ComTxTimeBase  \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32TimeOffset;

    /**************************************************************************/
    /*! \Description Defines the repetition period in  multiple of \n
                     ComTxTimeBase of the periodic transmission requests in \n
                     case ComTxModeMode is configured to PERIODIC \n
                     calculation method: \n
                        equals ComTxModeTimePeriod/ComTxTimeBase \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32TimePeriod;

    /**************************************************************************/
    /*! \Description Index in COM_au32TxModeTimer to RAM \n
                     variable holding the Offset/ Periodic Timer \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16TimerIndex;
} Com_tstrTxModePeriodic;

/******************************************************************************/
/*! \Description Defines a type of TxModeMixed ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Number Of Repetitions Defines the number of repetitions \n
                     for the DIRECT part of the  transmission mode MIXED \n
                     calculation method: equals ComTxModeNumberOfRepetitions \n
        \Range 0..255 \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8NumberOfRepetitions;

    /**************************************************************************/
    /*! \Description Repetition Period Defines the repetition period for the \n
                     DIRECT part of the  transmission mode MIXED in \n
                     multiple of ComTxTimeBase of the multiple transmissions \n
                     calculation method: \n
                        equals ComTxModeRepetitionPeriod/ComTxTimeBase \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32RepetitionPeriod;

    /**************************************************************************/
    /*! \Description Index in COM_au8TxModeRepetitionsCounter to RAM \n
                     variable holding the count of repetitions for the DIRECT \n
                      part of the  transmission mode MIXED \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16RepetitionsCtrIndex;

    /**************************************************************************/
    /*! \Description Index in COM_au32TxModeTimer to RAM \n
                     variable holding the the timer of repetition period for \n
                     the DIRECT part of the  transmission mode MIXED \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16RepetitionPrdTmrIx;

    /**************************************************************************/
    /*! \Description Defines the period in multiple of ComTxTimeBase between  \n
                     the start of the I-PDU by Com_IpduGroupControl and the \n
                      first transmission request for the PERIODIC part of \n
                      the  transmission mode MIXED \n
                     calculation method: \n
                        equals ComTxModeTimeOffset/ComTxTimeBase  \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32TimeOffset;

    /**************************************************************************/
    /*! \Description Defines the repetition period in  multiple of \n
                     ComTxTimeBase of the periodic transmission requests for \n
                     the PERIODIC part of the transmission mode MIXED \n
                     calculation method: \n
                        equals ComTxModeTimePeriod/ComTxTimeBase \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32TimePeriod;

    /**************************************************************************/
    /*! \Description Index in COM_au32TxModeTimer to RAM \n
                     variable holding the Offset/ Periodic Timer for the \n
                     PERIODIC part of the transmission mode MIXED \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16TimerIndex;
} Com_tstrTxModeMixed;

/******************************************************************************/
/*! \Description Defines a type of MDTimer  \n */
/******************************************************************************/
typedef uint32 Com_tu32MDTimer;

/******************************************************************************/
/*! \Description Defines a type of Pointer to generated IPdu notification \n
 function which calls all signal/signal group notifications \n 
   --OPTIMIZATION*/
/******************************************************************************/
typedef P2FUNC(void, AUTOMATIC, Com_tpfvidIPduNotification) (void);


/******************************************************************************/
/*! \Description Defines a type of Pointer to generated IPdu timeout notification \n
 function which calls all signal/signal group TimeOut notifications \n 
   --OPTIMIZATION*/
/******************************************************************************/
typedef P2FUNC(void, AUTOMATIC, Com_tpfvidIPduTimeOutNotific) (void);

/******************************************************************************/
/*! \Description Defines a type of Pointer to generated IPdu Error notification \n
 function which calls all signal/signal group Error notifications \n 
   --OPTIMIZATION*/
/******************************************************************************/
typedef P2FUNC(void, AUTOMATIC, Com_tpfvidIPduErrorNotific) (void);

/******************************************************************************/
/*! \Description Defines a type of Tx I-PDU Structure \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index in COM_akpfIPduCalloutPointersArray of the I-PDU \n
                     callout function pointer if exists \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC)  u16IPduCalloutIndex;

    /**************************************************************************/
    /*! \Description Index in COM_akudtIPduSignalMapping to ID of the first \n
                     signal/signal group belongs in this I-PDU. \n
                     Signals/signal groups belong to the same I-PDU \n
                     are placed in COM_audtIPduSignalMapping consicutively \n
                     and in the right order. \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC)  u16IPduSigMappingIndex;

    /**************************************************************************/
    /*! \Description Number of the signals/signal groups included \n
                     in this I-PDU   \n
                     calculation method: equals  \n
                        number of ComIPduSignalGroupRefs \n
                        + number of ComIPduSignalRefs \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC)  u16IPduNoOfSignals;

    /**************************************************************************/
    /*! \Description Index in COM_akstrIPduCounter to the I-PDU counter \n
                     structure  \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC)  u16IPduCounterIndex;

    /**************************************************************************/
    /*! \Description Flags indicating optional/boolean parameters configured \n
                     for Tx I-PDU \n
                     calculation method: see Com_tbfTxIPduFlags \n
                     type definition \n */
    /**************************************************************************/
    VAR(Com_udtTxIPduFlags, AUTOMATIC) udteTxIPduFlags;

    /**************************************************************************/
    /*! \Description Index in COM_au8IPduBufferArray to the first byte of the \n
                     RAM buffer of this I-PDU \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32IPduBufferIndex;

    /**************************************************************************/
    /*! \Description I-PDU length in bytes \n
                     calculation method: \n
                       max_bit_pos = the maximum of ComBitPosition of all \n
                       signals/group signals belong to this I-PDU; \n
                       if(signal which has the max_bit_pos is of \n
                          UINT8_N/UINT8_DYN type) \n
                       { \n
                         length = length of the signal which has the \n
                         max_bit_pos; \n
                         ku16IPduLength = ((max_bit_pos-1)/8)+1 + length; \n
                       } \n
                       else \n
                       { \n
                         end_bit_pos = max_bit_pos + ComBitSize of the signal \n
                         which has the max_bit_pos; \n
                         u16IPduLength = ((end_bit_pos-1)/8)+1; \n
                       } \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16IPduLength;

    /**************************************************************************/
    /*! \Description Index in COM_au32TOTimerArray, Points to the RAM  \n
                     location which holds the run time timer variable \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16TOTimerIndex;

    /**************************************************************************/
    /*! \Description I-PDU based Timeout. Only valid on Sender side in case \n
                     I-PDU based deadline monitoring is needed. \n
                      calculation method: \n
                        the smallest configured ComSignalTimeout or \n
                        ComSignalGroupTimeout parameter of all the signals \n
                        and signal groups without update-bits within \n
                        the I-PDU. \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32Timeout;

    /**************************************************************************/
    /*! \Description Index to I-PDU based First Timeout. Only valid on \n
                     receiver side in case I-PDU based deadline monitoring is \n
                     needed. \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16FirstTimeoutIndex;

    /**************************************************************************/
    /*! \Description Index to the RAM counter which is used to store the \n
                     number of bytes sent or received when processing an \n
                     I-PDU of type TP. Indexes \n
                     COM_au16TpIPduByteCounterArray. \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16TpIPduByteCtrIndex;

    /**************************************************************************/
    /*! \Description Index to the start location of Handle IDs of I-PDU \n
                          groups which contain this I-PDU. Indexes \n
                          ComIPduToIPduGroupMappingArray . \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16IPduGroupMapIndex;

    /**************************************************************************/
    /*! \Description Number of  I-PDU groups which contains this I-PDU \n
                          calculation method: \n
                             equals the number of  I-PDU groups which \n
                             contains this I-PDU \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16NumberOfIPduGroups;

    /**************************************************************************/
    /*! \Description Minimum Delay Time (MDT) between successive \n
                     transmissions of this I-PDU in multiple of \n
                     Com_MainFunctionTx ticks \n
                          calculation method: \n
                             equals ComMinimumDelayTime/ComTxTimeBase \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32MinimumDelayTime;

    /**************************************************************************/
    /*! \Description  Index in COM_au32MDTimerArray, Points to the RAM \n
                      location that holds the MDT run-time timer variable  \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16MDTimerIndex;

    /**************************************************************************/
    /*! \Description  Index to the byte used to fill un-used I-PDU areas  \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16TxUnusedAreasDefltIx;

    /**************************************************************************/
    /*! \Description  Index in COM_kaudTxMode, Points to TxModeFalse   \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16TxModeFalseIndex;

    /**************************************************************************/
    /*! \Description  Index in COM_kaudTxMode, Points to TxModeTrue   \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16TxModeTrueIndex;

    /**************************************************************************/
    /*! \Description  ComIPduHandleId   \n */
    /**************************************************************************/
    VAR(PduIdType, AUTOMATIC) u16IPduId;

    /**************************************************************************/
    /*! \Description  PduR I-PDU ID   \n */
    /**************************************************************************/
    VAR(PduIdType, AUTOMATIC) u16PduRIPduId;
    
    /**************************************************************************/
    /*! \Description Pointer to notification function which calls all 
                      signal/signal group Notifications\n
                     calculation method: pointer to a generated function  \n 
                     --OPTIMIZATION*/
    /**************************************************************************/
    Com_tpfvidIPduNotification pfvidIPduNotifPtr;
	
    /**************************************************************************/
    /*! \Description Pointer to Timeout notification function which calls all 
                      signal/signal group Timeout Notifications\n
                     calculation method: pointer to a generated function  \n 
                     --OPTIMIZATION*/
    /**************************************************************************/
    Com_tpfvidIPduTimeOutNotific pfvidIPduTimeOutNotifPtr;
	
	/**************************************************************************/
    /*! \Description Pointer to Error notification function which calls all 
                      signal/signal group Error Notifications\n
                     calculation method: pointer to a generated function  \n 
                     --OPTIMIZATION*/
    /**************************************************************************/
    Com_tpfvidIPduErrorNotific  pfvidIPduErrorNotifPtr;
	
} Com_tstrTxIPdu;

/******************************************************************************/
/*! \Description Defines the I-PDU ComIPduToSignalMapping.Type Symbols \n */
/******************************************************************************/
#define     Com_u8SIGNAL              0U
#define     Com_u8SIGNALGROUP         1U
#define     Com_u8GWSIGNAL            5U
#define     Com_u8GWSIGNALGROUP       6U

/******************************************************************************/
/*! \Description Defines a type of IPdu To Signal Mapping Structure \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description type of the data structure referred by Index \n
                     in this I-PDU   \n
                     calculation method: equals  \n
                        Com_u8SIGNAL if Signal \n
                        Com_u8SIGNALGROUP if Signal group \n
                        Com_u8GWSIGNAL GW source or distenation signal \n
                        Com_u8GWSIGNALGROUP GW source or distenation signal group \n
        \Range Com_u8SIGNAL, Com_u8SIGNALGROUP,
        Com_u8GWSIGNAL or Com_u8GWSIGNALGROUP \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC)  u8Type;

    /**************************************************************************/
    /*! \Description index to the structure of Signal, Signal group, \n
                     GW source or distenation signal or GW source or \n
                     distenation signal group   \n
                     calculation method:  \n
                        If Type = SIGNAL : index of the signal \n
                          ComSignalGroupPBArray and ComSignalGroupLTArray \n
                        If Type = SIGNALGROUP: index of the signal group \n
                          container in ComSignalGroupPBArray and \n
                          ComSignalGroupLTArray
                        If Type = GWXXXXXXX : index in \n
                           ComGWSignalMappingArray \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16Index;
} Com_tstrIPduToSignalMapping;

/******************************************************************************/
/*! \Description Defines the Signal Types Symbols \n */
/******************************************************************************/
#define Com_u8SIGNAL_TYPE_BOOLEAN   0
#define Com_u8SIGNAL_TYPE_FLOAT32   1
#define Com_u8SIGNAL_TYPE_FLOAT64   2
#define Com_u8SIGNAL_TYPE_SINT16    3
#define Com_u8SIGNAL_TYPE_SINT32    4
#define Com_u8SIGNAL_TYPE_SINT8     5
#define Com_u8SIGNAL_TYPE_UINT16    6
#define Com_u8SIGNAL_TYPE_UINT32    7
#define Com_u8SIGNAL_TYPE_UINT8     8
#define Com_u8SIGNAL_TYPE_UINT8DYN  9
#define Com_u8SIGNAL_TYPE_UINT8N    10

/******************************************************************************/
/*! \Description Defines the Transfer Properties Symbols \n */
/******************************************************************************/
#define Com_u8TXPROP_PENDING       0
#define Com_u8TXPROP_TRIGGERED     1
#define Com_u8TXPROP_TRIG_CHANGE   2

/******************************************************************************/
/*! \Description Defines the Signal Endianess Symbols \n */
/******************************************************************************/
#define Com_u8ENDIANESS_BIG                0
#define Com_u8ENDIANESS_LITTLE             1
#define Com_u8ENDIANESS_OPAQUE             2

/******************************************************************************/
/*! \Description Defines the  Signal Direction Symbols \n */
/******************************************************************************/
#define Com_u8SIG_DIR_SEND                0
#define Com_u8SIG_DIR_RECEIVE             1

/******************************************************************************/
/*! \Description Defines the  bit-fields size Symbols \n */
/******************************************************************************/
#define Com_u8ENDIANESS_BF_SIZE                2
#define Com_u8TX_PROPERTY_BF_SIZE              2


/* -- OPTIMIZATION Signal ROM FLAGs*/

/* 7               6 			     5                     4					3, 2    		   1, 0
   bfDescFilter	   bfDirection	    bfTimeout	          bfUpdateBit       bfTxProperty   	   bfEndianess   */


#define Com_u8SIGNAL_ENDIANESS           0x03 /*AutoSAR*/
#define Com_u8SIGNAL_TXPROPERTY          0x0C /*AutoSAR*/
#define Com_u8SIGNAL_DIRECTION           0x40 /*AutoSAR*/

typedef uint8 Com_tu8SignalPBFlags;
/******************************************************************************/
/*! \Description Defines the Signal Stucture Type Symbols for \n
                 Com_tstrSignalLookUp \n */
/******************************************************************************/
#define Com_u8SIG_STRUCT_SIG               0U
#define Com_u8SIG_STRUCT_GROUPSIG          4U
#define Com_u8SIG_STRUCT_SRCDESC           2U
#define Com_u8SIG_STRUCT_DSTDESC           3U

/******************************************************************************/
/*! \Description Defines a type of Signal Look Up ROM Structure  \n
                 this structure is used to map the SignalId to the internal \n
                 structures of signal or group signals */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Signal Structure type \n
        \Range
            COM_u8SIG_STRUCTURE_TYPE_SIGNAL          \n
            COM_u8SIG_STRUCTURE_TYPE_GROUPSIGNAL     \n
            Com_u8SIG_STRUCT_SRCDESC                 \n
            Com_u8SIG_STRUCT_DSTDESC */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC)  u8StructureType;

    /**************************************************************************/
    /*! \Description Index in signal or group signal array according to \n
                     u8StructureType \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC)  u16Index;
} Com_tstrSignalLookUp;

/******************************************************************************/
/*! \Description Defines a type of ComSignalPB ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Starting position within the I-PDU \n
                     calculation method: equals ComBitPosition \n
        \Range 0..2031 \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16BitPosition;

    /**************************************************************************/
    /*! \Description Size in bits, for non-array signal types \n
        \Range 0..64 \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8BitSize;

    /**************************************************************************/
    /*! \Description Depending on Signal type, Index in the corresponding \n
                     Signal Init Value Array \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16SignalInitValueIndex;

    /**************************************************************************/
    /*! \Description Signal types \n
                     calculation method: one of Signal Types Symbols \n
                     according to ComSignalType \n
        \Range
            Com_u8SIGNAL_TYPE_BOOLEAN \n
            Com_u8SIGNAL_TYPE_FLOAT32 \n
            Com_u8SIGNAL_TYPE_FLOAT64 \n
            Com_u8SIGNAL_TYPE_SINT16  \n
            Com_u8SIGNAL_TYPE_SINT32  \n
            Com_u8SIGNAL_TYPE_SINT8   \n
            Com_u8SIGNAL_TYPE_UINT16  \n
            Com_u8SIGNAL_TYPE_UINT32  \n
            Com_u8SIGNAL_TYPE_UINT8   \n
            COM_u8SIGNAL_TYPE_UINT8DYN \n
            COM_u8SIGNAL_TYPE_UINT8N \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8SignalType;

    /**************************************************************************/
    /*! \Description Defines the length of the deadline monitoring \n
                     timeout period in multiple of the main function \n
                     time base. \n
                     calculation method: \n
                     for Rx Signals - equals to ComTimeout/ComRxTimeBase \n
                     for Tx Signals - equals to ComTimeout/ComTxTimeBase \n
        \Range 0..ComTimeout/ComRxTimeBase
               0..ComTimeout/ComTxTimeBase    \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32Timeout;
	
    /**************************************************************************/
    /*! \Description Defines the length of the first deadline monitoring \n
                     timeout period in multiple of the main function \n
                     time base. \n
                     calculation method: \n
                     for Rx Signals - equals to ComFirstTimeout/ComRxTimeBase \n
                     for Tx Signals - equals to ComFirstTimeout/ComTxTimeBase \n
        \Range 0..ComFirstTimeout/ComRxTimeBase \n
               0..ComFirstTimeout/ComTxTimeBase    \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32FirstTimeout;
	
    /**************************************************************************/
    /*! \Description Index in COM_au32TOTimerArray, Points to the RAM  \n
                     location which holds the run time timer variable \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16TOTimerIndex;

    /**************************************************************************/
    /*! \Description Bit position of update-bit inside I-PDU. \n
                     calculation method: equals ComUpdateBitPosition \n
        \Range 0..2031 \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16UpdateBitPosition;

    /**************************************************************************/
    /*! \Description I-PDU Handle of the I-PDU which contains this signal \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16IPduIndex;

    /*Flags indicating optional/boolean parameters configured
      for signal                                                              */
    /**************************************************************************/
    /*! \Description Flags indicating PB optional/boolean parameters  \n
                     configured for signal \n
                     calculation method: see Com_tbfSignalPBFlags \n
                     type definition \n */
    /**************************************************************************/
    VAR(Com_tu8SignalPBFlags, AUTOMATIC) udteSignalFlags;

    /**************************************************************************/
    /*! \Description Index to the signal object RAM location \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16SignalObjectIndex;
} Com_tstrSignalPB;

#define Com_u8SIGNALGRP_TXPROPERTY    0x03 /*AutoSAR*/
#define Com_u8SIGNALGRP_DIRECTION      0x10 /*AutoSAR*/


typedef uint8 Com_tu8SignalGroupPBFlags; 

/******************************************************************************/
/*! \Description Defines a type of ComSignaGrouplPB ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Defines the length of the deadline monitoring \n
                     timeout period in multiple of the main function \n
                     time base. \n
                     calculation method: \n
                     for Rx Signals - equals to ComTimeout/ComRxTimeBase \n
                     for Tx Signals - equals to ComTimeout/ComTxTimeBase \n
        \Range 0..ComTimeout/ComRxTimeBase
               0..ComTimeout/ComTxTimeBase    \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32Timeout;

	/**************************************************************************/
    /*! \Description Defines the length of the first deadline monitoring \n
                     timeout period in multiple of the main function \n
                     time base. \n
                     calculation method: \n
                     for Rx Signals - equals to ComFirstTimeout/ComRxTimeBase \n
                     for Tx Signals - equals to ComFirstTimeout/ComTxTimeBase \n
        \Range 0..ComFirstTimeout/ComRxTimeBase \n
               0..ComFirstTimeout/ComTxTimeBase    \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32FirstTimeout;
	
    /**************************************************************************/
    /*! \Description Index in COM_au32TOTimerArray, Points to the RAM  \n
                     location which holds the run time timer variable \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16TOTimerIndex;

    /**************************************************************************/
    /*! \Description Bit position of update-bit inside I-PDU. \n
                     calculation method: equals ComUpdateBitPosition \n
        \Range 0..2031 \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16UpdateBitPosition;

    /**************************************************************************/
    /*! \Description I-PDU Handle of the I-PDU which contains this signal \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16IPduIndex;

    /**************************************************************************/
    /*! \Description  index to the first group signal belongs to this group \n*/
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16GroupSignalIndex;

    /**************************************************************************/
    /*! \Description  number of group signal belongs to this group \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16NoOfGroupSignals;

    /**************************************************************************/
    /*! \Description Flags indicating PB optional/boolean parameters  \n
                     configured for signal group \n
                     calculation method: see Com_tbfSignalGroupPBFlags \n
                     type definition \n */
    /**************************************************************************/
    VAR(Com_tu8SignalGroupPBFlags, AUTOMATIC) udteSignalGroupFlags;

} Com_tstrSignalGroupPB;


#define Com_u8GRPSIGNAL_ENDIANESS      0x03 /*AutoSAR*/
#define Com_u8GRPSIGNAL_DIRECTION      0x04 /*AutoSAR*/



typedef uint8 Com_tu8GroupSignalPBFlags;

/******************************************************************************/
/*! \Description Defines a type of ComGroupSignalPB ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Starting position within the I-PDU \n
                     calculation method: equals ComBitPosition \n
        \Range 0..2031 \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16BitPosition;

    /**************************************************************************/
    /*! \Description Size in bits, for non-array signal types \n
        \Range 0..64 \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8BitSize;

    /**************************************************************************/
    /*! \Description Depending on Signal type, Index in the corresponding \n
                     Signal Init Value Array \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16SignalInitValueIndex;

    /**************************************************************************/
    /*! \Description Signal types \n
                     calculation method: one of Signal Types Symbols \n
                     according to ComSignalType \n
        \Range
            Com_u8SIGNAL_TYPE_BOOLEAN \n
            Com_u8SIGNAL_TYPE_FLOAT32 \n
            Com_u8SIGNAL_TYPE_FLOAT64 \n
            Com_u8SIGNAL_TYPE_SINT16  \n
            Com_u8SIGNAL_TYPE_SINT32  \n
            Com_u8SIGNAL_TYPE_SINT8   \n
            Com_u8SIGNAL_TYPE_UINT16  \n
            Com_u8SIGNAL_TYPE_UINT32  \n
            Com_u8SIGNAL_TYPE_UINT8   \n
            COM_u8SIGNAL_TYPE_UINT8DYN \n
            COM_u8SIGNAL_TYPE_UINT8N \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8SignalType;

    /**************************************************************************/
    /*! \Description I-PDU Handle of the I-PDU which contains this signal \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16IPduIndex;

    /**************************************************************************/
    /*! \Description Flags indicating PB optional/boolean parameters  \n
                     configured for signal \n
                     calculation method: see Com_tbfGroupSignalPBFlags \n
                     type definition \n */
    /**************************************************************************/
    VAR(Com_tu8GroupSignalPBFlags, AUTOMATIC) udteGroupSignalFlags;

    /**************************************************************************/
    /*! \Description Index to the Shadow buffer RAM location \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16ShadowBufferIndex;

    /**************************************************************************/
    /*! \Description Index to the signal object RAM location \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16SignalObjectIndex;
} Com_tstrGroupSignalPB;


/******************************************************************************/
/*! \Description Defines a type of I-PDU Group ID  \n */
/******************************************************************************/
typedef uint16 Com_tu16IPduGroupId;


/******************************************************************************/
/*! \Description Defines a type of I-PDU Group ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description index to the first I-PDU belongs to this I-PDU group in \n
                     COM_akudtIPduGroupToIPduMappingArray \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16IPduMappingIndex;

    /**************************************************************************/
    /*! \Description number of I-PDUs belonging to this I-PDU group  \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16NoOfIPdus;
} Com_tstrIPduGroup;


/******************************************************************************/
/*! \Description Defines the GW Signal Stucture Type Symbols for \n
                 Com_tstrGWSignalMapping \n */
/******************************************************************************/
#define Com_u8GW_STRUCT_SIG               0U
#define Com_u8GW_STRUCT_SIGGROUP          1U
#define Com_u8GW_STRUCT_SRC_DESC          2U
#define Com_u8GW_STRUCT_DST_DESC          3U


/******************************************************************************/
/*! \Description Defines a type of Gateway mapping ROM Structure  \n */
/******************************************************************************/
typedef struct
{
  /**************************************************************************/
  /*! \Description  Index in: \n
                      Com_akstrSignalLT and Com_akstrSignalPB \n
                      Or Com_akstrSignalGroupLT and Com_akstrSignalGroupPB \n
                      Or Com_akstrGWSrcDesc \n
                      For 1:n signal gateway multiple \n
                      Com_tstrGWSignalMapping structures shall be placed \n
                      consecutively having the same SrcIndex \n */
  /**************************************************************************/
  VAR(uint16, AUTOMATIC) u16SrcIndex;

  /**************************************************************************/
  /*! \Description  Index in: \n
                      Com_akstrSignalLT and Com_akstrSignalPB \n
                      Or Com_akstrSignalGroupLT and Com_akstrSignalGroupPB \n
                      Or Com_akstrGWDstDesc \n */
  /**************************************************************************/
  VAR(uint16, AUTOMATIC) u16DstIndex;

  /**************************************************************************/
  /*! \Description structure type \n
      \Range
                   Com_u8GW_STRUCT_SIG
                   Com_u8GW_STRUCT_SIGGROUP
                   Com_u8GW_STRUCT_SRC_DESC: ComGwSourceDescription
  */
  /**************************************************************************/
  VAR(uint8, AUTOMATIC) u8SrcStructType;

  /**************************************************************************/
  /*! \Description structure type \n
      \Range
                   Com_u8GW_STRUCT_SIG
                   Com_u8GW_STRUCT_SIGGROUP
                   Com_u8GW_STRUCT_DST_DESC: ComGwSourceDescription
  */
  /**************************************************************************/
  VAR(uint8, AUTOMATIC) u8DstStructType;

} Com_tstrGWSignalMapping;

/******************************************************************************/
/*! \Description Defines a type of ComGwSourceDescription ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Starting position within the I-PDU \n
                     calculation method: equals ComBitPosition \n
        \Range 0..2031 \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16BitPosition;

    /**************************************************************************/
    /*! \Description Size in bits, for non-array signal types \n
        \Range 0..64 \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8BitSize;

    /**************************************************************************/
    /*! \Description Signal types \n
                     calculation method: one of Signal Types Symbols \n
                     according to ComSignalType \n
        \Range
            Com_u8SIGNAL_TYPE_BOOLEAN \n
            Com_u8SIGNAL_TYPE_FLOAT32 \n
            Com_u8SIGNAL_TYPE_FLOAT64 \n
            Com_u8SIGNAL_TYPE_SINT16  \n
            Com_u8SIGNAL_TYPE_SINT32  \n
            Com_u8SIGNAL_TYPE_SINT8   \n
            Com_u8SIGNAL_TYPE_UINT16  \n
            Com_u8SIGNAL_TYPE_UINT32  \n
            Com_u8SIGNAL_TYPE_UINT8   \n
            COM_u8SIGNAL_TYPE_UINT8DYN \n
            COM_u8SIGNAL_TYPE_UINT8N \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8SignalType;

    /**************************************************************************/
    /*! \Description Bit position of update-bit inside I-PDU. \n
                     calculation method: equals ComUpdateBitPosition \n
        \Range 0..2031 \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16UpdateBitPosition;

    /**************************************************************************/
    /*! \Description I-PDU Handle of the I-PDU which contains this signal \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16IPduIndex;

    /**************************************************************************/
    /*! \Description Index of ComGWSignalLength in Com_aku16GWSigLength \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16LengthIndex;

    /**************************************************************************/
    /*! \Description Flags indicating PB optional/boolean parameters  \n
                     configured for signal \n
                     calculation method: see Com_tbfSignalPBFlags \n
                     type definition \n */
    /**************************************************************************/
	VAR(Com_tu8SignalPBFlags, AUTOMATIC) udteSignalFlags;

    /**************************************************************************/
    /*! \Description Index to the signal object RAM location \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16SignalObjectIndex;

    /**************************************************************************/
    /*! \Description This parameter is automatically generated by \n
                     configuration tool \n
                     calculation method: each ComGwSourceDescription or \n
                     ComGwDestinationDescription shall have ID starting from \n
                     signals and group signals maximum HandleId   */
    /**************************************************************************/
    VAR(Com_SignalIdType, AUTOMATIC) u16SignalId;
} Com_tstrGWSrcDesc;

/******************************************************************************/
/*! \Description Defines a type of ComGwDestinationDescription ROM Structure \n
*******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Starting position within the I-PDU \n
                     calculation method: equals ComBitPosition \n
        \Range 0..2031 \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16BitPosition;

    /**************************************************************************/
    /*! \Description Size in bits, for non-array signal types \n
        \Range 0..64 \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8BitSize;

    /**************************************************************************/
    /*! \Description Depending on Signal type, Index in the corresponding \n
                     Signal Init Value Array \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16SignalInitValueIndex;

    /**************************************************************************/
    /*! \Description Signal types \n
                     calculation method: one of Signal Types Symbols \n
                     according to ComSignalType \n
        \Range
            Com_u8SIGNAL_TYPE_BOOLEAN \n
            Com_u8SIGNAL_TYPE_FLOAT32 \n
            Com_u8SIGNAL_TYPE_FLOAT64 \n
            Com_u8SIGNAL_TYPE_SINT16  \n
            Com_u8SIGNAL_TYPE_SINT32  \n
            Com_u8SIGNAL_TYPE_SINT8   \n
            Com_u8SIGNAL_TYPE_UINT16  \n
            Com_u8SIGNAL_TYPE_UINT32  \n
            Com_u8SIGNAL_TYPE_UINT8   \n
            COM_u8SIGNAL_TYPE_UINT8DYN \n
            COM_u8SIGNAL_TYPE_UINT8N \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8SignalType;

    /**************************************************************************/
    /*! \Description Bit position of update-bit inside I-PDU. \n
                     calculation method: equals ComUpdateBitPosition \n
        \Range 0..2031 \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16UpdateBitPosition;

    /**************************************************************************/
    /*! \Description I-PDU Handle of the I-PDU which contains this signal \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16IPduIndex;

    /**************************************************************************/
    /*! \Description Index of ComGWSignalLength in Com_aku16GWSigLength \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16LengthIndex;

    /**************************************************************************/
    /*! \Description Flags indicating PB optional/boolean parameters  \n
                     configured for signal \n
                     calculation method: see Com_tbfSignalPBFlags \n
                     type definition \n */
    /**************************************************************************/
	VAR(Com_tu8SignalPBFlags, AUTOMATIC) udteSignalFlags;

    /**************************************************************************/
    /*! \Description Index to the signal object RAM location \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16SignalObjectIndex;

    /**************************************************************************/
    /*! \Description This parameter is automatically generated by \n
                     configuration tool \n
                     calculation method: each ComGwSourceDescription or \n
                     ComGwDestinationDescription shall have ID starting from \n
                     signals and group signals maximum HandleId   */
    /**************************************************************************/
    VAR(Com_SignalIdType, AUTOMATIC) u16SignalId;

    /**************************************************************************/
    /*! \Description Index in COM_akstrFilter array \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16FilterIndex;

} Com_tstrGWDstDesc;

/******************************************************************************/
/*! \Description Defines a type of Main PostBuild configuration \n
                 ROM Structure \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Unique identifier of the configuration set \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC)  u32ConfigurationId;

/* PRQA S 8018,8218,8518,8418 ++*/
    /**************************************************************************/
    /*! \Description Pointer to IPduLookUp array \n */
    /**************************************************************************/
    P2CONST(Com_tstrIPduLookUp,AUTOMATIC,TYPEDEF) pkstrIPduLookUp;

    /**************************************************************************/
    /*! \Description Pointer to RxIPdu array \n */
    /**************************************************************************/
    P2CONST(Com_tstrRxIPdu,AUTOMATIC,TYPEDEF)pkstrRxIPdu;

    /**************************************************************************/
    /*! \Description Pointer to TxIPdu array \n */
    /**************************************************************************/
    P2CONST(Com_tstrTxIPdu,AUTOMATIC,TYPEDEF)pkstrTxIPdu;

    /**************************************************************************/
    /*! \Description Pointer to IPduToSignalMapping array \n */
    /**************************************************************************/
    P2CONST(Com_tstrIPduToSignalMapping,AUTOMATIC,TYPEDEF)
                                            pkstrIPduToSignalMapping;

    /**************************************************************************/
    /*! \Description Pointer to IPduBuffer array \n */
    /**************************************************************************/
    P2VAR(uint8,AUTOMATIC,TYPEDEF)pu8IPduBuffer;

    /**************************************************************************/
    /*! \Description Pointer to SignalPB array \n */
    /**************************************************************************/
    P2CONST(Com_tstrSignalPB,AUTOMATIC,TYPEDEF)pkstrSignalPB;

    P2CONST(Com_tstrSignalGroupPB,AUTOMATIC,TYPEDEF)pkstrSignalGroupPB;
    P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,TYPEDEF)pkstrGroupSignalPB;


    /**************************************************************************/
    /*! \Description Pointer to IPduGroup array \n */
    /**************************************************************************/
    P2CONST(Com_tstrIPduGroup,AUTOMATIC,TYPEDEF)pkstrIPduGroup;

    /**************************************************************************/
    /*! \Description Pointer to IPduToIPduGroupMapping array \n */
    /**************************************************************************/
    P2CONST(Com_tu16IPduGroupId,AUTOMATIC,TYPEDEF)
                                            pku16IPduToIPduGroupMap;

    /**************************************************************************/
    /*! \Description Pointer to IPduGroupToIPduMapping array \n */
    /**************************************************************************/
    P2CONST(PduIdType,AUTOMATIC,TYPEDEF)
                                            pku16IPduGroupToIPduMap;

    /**************************************************************************/
    /*! \Description Pointer to TxMode array \n */
    /**************************************************************************/
    P2CONST(Com_tstrTxMode,AUTOMATIC,TYPEDEF)pkstrTxMode;

    /**************************************************************************/
    /*! \Description Pointer to TxModeDirect array \n */
    /**************************************************************************/
    P2CONST(Com_tstrTxModeDirect,AUTOMATIC,TYPEDEF)pkstrTxModeDirect;

    /**************************************************************************/
    /*! \Description Pointer to TxModePeriodic array \n */
    /**************************************************************************/
    P2CONST(Com_tstrTxModePeriodic,AUTOMATIC,TYPEDEF)
                                            pkstrTxModePeriodic;

    /**************************************************************************/
    /*! \Description Pointer to TxModeMixed array \n */
    /**************************************************************************/
    P2CONST(Com_tstrTxModeMixed,AUTOMATIC,TYPEDEF)pkstrTxModeMixed;

    /**************************************************************************/
    /*! \Description Pointer to TxModeTimer array \n */
    /**************************************************************************/
    P2VAR(Com_tu32TxModeTimer,AUTOMATIC,TYPEDEF)pu32TxModeTimer;

    /**************************************************************************/
    /*! \Description Pointer to TxModeRepetitionsCounter array \n */
    /**************************************************************************/
    P2VAR(uint8,AUTOMATIC,TYPEDEF)pu8TxModeRepetitionsCtr;

    /**************************************************************************/
    /*! \Description Pointer to MDTimer array \n */
    /**************************************************************************/
    P2VAR(Com_tu32MDTimer,AUTOMATIC,TYPEDEF)pu32MDTimer;

    /**************************************************************************/
    /*! \Description Pointer to GWSignalMapping array \n */
    /**************************************************************************/
    P2CONST(Com_tstrGWSignalMapping,AUTOMATIC,TYPEDEF)pkstrGWSignalMapping;

    /**************************************************************************/
    /*! \Description Pointer to GWSrcDesc array \n */
    /**************************************************************************/
    P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,TYPEDEF)pkstrGWSrcDesc;

    /**************************************************************************/
    /*! \Description Pointer to GWDstDesc array \n */
    /**************************************************************************/
    P2CONST(Com_tstrGWDstDesc,AUTOMATIC,TYPEDEF)pkstrGWDstDesc;

    /**************************************************************************/
    /*! \Description Pointer to SignalLookUp array \n  */
    /**************************************************************************/
    P2CONST(Com_tstrSignalLookUp,AUTOMATIC,TYPEDEF)pkstrSignalLookUp;

    /**************************************************************************/
    /*! \Description Pointer to SignalInitFilterResult array \n  */
    /**************************************************************************/
    P2CONST(uint8,AUTOMATIC,TYPEDEF)pku8SigInitFilterResult;

    /**************************************************************************/
    /*! \Description Pointers to different types SignalInitValue arrays \n  */
    /**************************************************************************/
    P2CONST(boolean,AUTOMATIC,TYPEDEF)pkbSignalInitValueB;

    P2CONST(uint8,AUTOMATIC,TYPEDEF)pku8SignalInitValueU8U8N;

    P2CONST(sint8,AUTOMATIC,TYPEDEF)pks8SignalInitValueS8;

    P2CONST(uint16,AUTOMATIC,TYPEDEF)pku16SignalInitValueU16;

    P2CONST(sint16,AUTOMATIC,TYPEDEF)pks16SignalInitValueS16;

    P2CONST(uint32,AUTOMATIC,TYPEDEF)pku32SignalInitValueU32;

    P2CONST(sint32,AUTOMATIC,TYPEDEF)pks32SignalInitValueS32;

    P2CONST(float32,AUTOMATIC,TYPEDEF)pkf32SignalInitValueF32;

    P2CONST(float64,AUTOMATIC,TYPEDEF)pkf64SignalInitValueF64;

    /**************************************************************************/
    /*! \Description  Pointers to different types SignalObject arrays \n  */
    /**************************************************************************/
    P2VAR(boolean,AUTOMATIC,TYPEDEF)pbSignalObjectB;

    P2VAR(uint8,AUTOMATIC,TYPEDEF)pu8SignalObjectU8U8N;

    P2VAR(sint8,AUTOMATIC,TYPEDEF)ps8SignalObjectS8;

    P2VAR(uint16,AUTOMATIC,TYPEDEF)pu16SignalObjectU16;

    P2VAR(sint16,AUTOMATIC,TYPEDEF)ps16SignalObjectS16;

    P2VAR(uint32,AUTOMATIC,TYPEDEF)pu32SignalObjectU32;

    P2VAR(sint32,AUTOMATIC,TYPEDEF)ps32SignalObjectS32;

    P2VAR(float32,AUTOMATIC,TYPEDEF)pf32SignalObjectF32;

    P2VAR(float64,AUTOMATIC,TYPEDEF)pf64SignalObjectF64;

    /**************************************************************************/
    /*! \Description  Pointer to ONE_EVERY_N filter Period array \n  */
    /**************************************************************************/
    P2CONST(uint32,AUTOMATIC,TYPEDEF)pku32OneEveryNFPeriod;

    P2VAR(uint32,AUTOMATIC,AUTOMATIC)
                            pu32TimeOutTimer;

    VAR(uint16, AUTOMATIC)  u16GWSignalMappingMaxIx;

    P2VAR(uint16,AUTOMATIC,AUTOMATIC)
                            pu16TpByteCounter;
							
    VAR(uint16, AUTOMATIC)  u16TpByteCounterMaxIx;
	
	P2CONST(uint32,AUTOMATIC,TYPEDEF) pku32IpduFirstTO;
	
	P2CONST(Com_udtIPduInitiStatus,AUTOMATIC,TYPEDEF) pkudteInitIPduStatus;
/* PRQA S 8018,8218,8518,8418 --*/
} Com_ConfigType;

#endif /* COM_TYPES_H_INCLUDED */

/** \} */ /* end of Com module group */

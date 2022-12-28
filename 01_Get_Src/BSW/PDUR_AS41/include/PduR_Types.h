/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !File            : PduR_Types.h                                            */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
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
/* PRQA S 0292 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/02_PduR/02$*/
/* $Revision::   1.29     $$Author::   sedrees        $$Date::   Mar 23 2014 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#ifndef PDUR_TYPES_H
#define PDUR_TYPES_H

#include "Std_Types.h"
#include "Compiler.h"
#include "ComStack_Types.h"

#include "PduR_Cfg.h"


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
#ifndef E_PENDING
#define     E_PENDING                           10U
#endif

/******************************************************************************/
/*! \Description    State of the PDU Router module  \n
    \Range          PDUR_UNINIT, PDUR_ONLINE, PDUR_REDUCED \n
*******************************************************************************/
typedef uint8   PduR_StateType;

#define PDUR_UNINIT                     0x00
#define PDUR_ONLINE                     0x01
#define PDUR_REDUCED                    0x02


/******************************************************************************/
/*! \Description    Extends the Std_ReturnType to include PENDING response
    \Range          E_OK, E_NOT_OK, E_PENDING \n
*******************************************************************************/
typedef     uint8       PduR_ReturnType;

/******************************************************************************/
/*! \Description    Identifies the post build configuration currently used
                    for routing of the I-PDUs \n
    \Range          0..65535 \n
*******************************************************************************/
typedef uint16  PduR_PBConfigIdType;

/******************************************************************************/
/*! \Description    Identifies the routing path group \n
    \Range          0..65535 \n
*******************************************************************************/
typedef uint16  PduR_RoutingPathGroupIdType;

/******************************************************************************/
/*! \Description    Identifies the FIFO buffer type (immediate/deferred) \n
    \Range          PduR_u8IMMEDIATE, PduR_u8DEFERRED \n
*******************************************************************************/
typedef uint8   PduR_tu8TxBuffFIFOType;

#define PduR_u8IMMEDIATE                0x00
#define PduR_u8DEFERRED                 0x01

/******************************************************************************/
/*! \Description    Identifies different data provision for an I-PDU \n
    \Range          PduR_u8DIRECT, PduR_u8TRIGGERED, PduR_u8NONINTERFACE \n
*******************************************************************************/
typedef uint8   PduR_tu8DataProvisionType;

#define PduR_u8DIRECT                   0x00
#define PduR_u8TRIGGERED                0x01
#define PduR_u8NONINTERFACE             0x02
#define PduR_u8UPPER                    0x03


/******************************************************************************/
/* Enumerations                                                               */
/******************************************************************************/



/******************************************************************************/
/* Function Pointers                                                          */
/******************************************************************************/

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_tpfu8TransmitFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId,
   P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)  pkstrPduInfo);

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_tpfu8CancelTxFunc)(
    VAR(PduIdType, AUTOMATIC)                        udtId);

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_tpfu8CancelRxFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId);

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_tpfu8ChangeParamFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId,
   VAR(TPParameterType, AUTOMATIC)                  strParam,
   VAR(uint16, AUTOMATIC)                           u16Value);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_tpfvidIfRxIndFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)    pstrPduInfo);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_tpfvidTpRxIndFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId,
   VAR(NotifResultType, PDUR_APPL_DATA)             u8Result);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_tpfenuCopyRxDataFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)    pstrPduInfo,
   P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)  pu16BuffSize);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_tpfenuStartOfRxFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)    pstrPduInfo,
   VAR(PduLengthType, AUTOMATIC)                    u16TpSduLen,
   P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)  pu16BuffSize);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_tpfvidChngPrmConfFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId,
   VAR(NotifResultType, PDUR_APPL_DATA)             u8Result);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_tpfvidTxIfConfirmFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_tpfvidTxTpConfirmFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId,
   VAR(NotifResultType, PDUR_APPL_DATA)             u8Result);

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_tpfu8TriggerTxFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)    pstrPduInfo);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_tpfenuCopyTxDataFunc)(
   VAR(PduIdType, AUTOMATIC)                        udtId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)    pstrPduInfo,
   P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA)  pstrRetry,
   P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)  pu16AvData);

typedef P2FUNC(boolean, PDUR_CALLOUT_CODE, PduR_tpfbGateCallOut)(
   VAR(PduIdType, AUTOMATIC)                        udtPduId,
   P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)  pkstrPduInfo);

typedef P2FUNC(void, PDUR_CODE, PduR_tpfvidBswModuleInitFunc)(void);

/******************************************************************************/
/* Structures                                                                 */
/******************************************************************************/

/*-----------------------------Func Pointer Tables----------------------------*/

/******************************************************************************/
/*! \Description    Function pointer tables generated when there exist a 
                    PduRBswModule that has the following parameters set to TRUE
                    PduRLowerModule PduRCommunicationInterface \n
*******************************************************************************/
typedef struct {
    VAR(PduR_tpfu8TransmitFunc, PDUR_CALIB_CONST)       pfu8IfTransmit;
    VAR(PduR_tpfu8CancelTxFunc, PDUR_CALIB_CONST)       pfu8IfCancelTransmit;
} PduR_tstrIfTxFuncPtrType;

/******************************************************************************/
/*! \Description    Function pointer tables generated when there exist a 
                    PduRBswModule that has the following parameters set to TRUE
                    PduRLowerModule PduRTransportProtocol \n
*******************************************************************************/
typedef struct {
    VAR(PduR_tpfu8TransmitFunc, PDUR_CALIB_CONST)       pfu8TpTransmit;
    VAR(PduR_tpfu8CancelRxFunc, PDUR_CALIB_CONST)       pfu8TpCancelRxReq;
    VAR(PduR_tpfu8CancelTxFunc, PDUR_CALIB_CONST)       pfu8TpCancelTxReq;
    VAR(PduR_tpfu8ChangeParamFunc, PDUR_CALIB_CONST)    pfu8TpChangeParamReq;
} PduR_tstrTpTxFuncPtrType;

/******************************************************************************/
/*! \Description    Function pointer tables generated when there exist a 
                    PduRBswModule that has the following parameters set to TRUE
                    PduRUpperModule PduRCommunicationInterface \n
*******************************************************************************/
typedef struct {
    VAR(PduR_tpfvidIfRxIndFunc, PDUR_CALIB_CONST)       pfvidUpIfRxIndication;
} PduR_tstrIf2UpRxFuncPtrType;

/******************************************************************************/
/*! \Description    Function pointer tables generated when there exist a 
                    PduRBswModule that has the following parameters set to TRUE
                    PduRUpperModule PduRTransportProtocol \n
*******************************************************************************/
typedef struct {
    VAR(PduR_tpfvidTpRxIndFunc, PDUR_CALIB_CONST)       pfvidUpTpRxIndication;
    VAR(PduR_tpfenuCopyRxDataFunc, PDUR_CALIB_CONST)    pfenuUpTpCopyRxData;
    VAR(PduR_tpfenuStartOfRxFunc, PDUR_CALIB_CONST)     pfenuUpTpStartOfRx;
} PduR_tstrTp2UpRxFuncPtrType;

/******************************************************************************/
/*! \Description    Function pointer tables generated when there exist a 
                    PduRBswModule that has the following parameters set to TRUE
                    PduRUpperModule PduRCommunicationInterface \n
*******************************************************************************/
typedef struct {
    VAR(PduR_tpfvidTxIfConfirmFunc, PDUR_CALIB_CONST)   pfvidUpIfTxConf;
    VAR(PduR_tpfu8TriggerTxFunc, PDUR_CALIB_CONST)      pfu8UpIfTriggerTx;
} PduR_tstrIf2UpTxFuncPtrType;

/******************************************************************************/
/*! \Description    Function pointer tables generated when there exist a 
                    PduRBswModule that has the following parameters set to TRUE
                    PduRUpperModule PduRTransportProtocol \n
*******************************************************************************/
typedef struct {
    VAR(PduR_tpfvidTxTpConfirmFunc, PDUR_CALIB_CONST)   pfvidUpTpTxConf;
    VAR(PduR_tpfenuCopyTxDataFunc, PDUR_CALIB_CONST)    pfenuUpTpCopyTxData;
} PduR_tstrTp2UpTxFuncPtrType;

/*---------------------------------TX Buffers---------------------------------*/

/******************************************************************************/
/*! \Description    Control structure used in IF gatewaying per each buffer \n
*******************************************************************************/
typedef struct {
    VAR(uint8, AUTOMATIC)                                       u8First;
    VAR(uint8, AUTOMATIC)                                       u8Last;
    VAR(uint8, AUTOMATIC)                                       u8Count;
} PduR_tstrTxCntrlType;

/******************************************************************************/
/*! \Description    Header structure used in IF gatewaying per each buffer \n
*******************************************************************************/
typedef struct {
    VAR(PduIdType, AUTOMATIC)                                   udtPduId;
    VAR(PduLengthType, AUTOMATIC)                               udtPduLen;
} PduR_tstrTxHdrType;

/******************************************************************************/
/*! \Description    Created as a single entry per each PduRTxBufferTable \n
*******************************************************************************/
typedef struct {
    /* PduRTxBufferTable.PduRTxBuffer.PduRTxBufferDepth                       */
    VAR(uint8, AUTOMATIC)                                       u8BuffDepth;
    /* PduRTxBufferTable.PduRTxBuffer.PduRTxBufferLength                      */
    VAR(uint8, AUTOMATIC)                                       u8BuffLength;
    /* PduRTxBufferTable.PduRTxBuffer.PduRTxBufferFIFOType                    */
    VAR(PduR_tu8TxBuffFIFOType, AUTOMATIC)                      u8BuffFIFOType;

    P2VAR(PduR_tstrTxCntrlType, AUTOMATIC, PDUR_VAR)            pstrBuffCtrl;
    P2VAR(PduR_tstrTxHdrType, AUTOMATIC, PDUR_VAR)              pstrTxBuffOfHdr;
    P2VAR(uint8, AUTOMATIC, PDUR_VAR)                           pu8TxBuffOfData;
} PduR_tstrTxBuffPCCfgType;

/*---------------------------------TP Buffers---------------------------------*/

/******************************************************************************/
/*! \Description    Control structure used in TP gatewaying per each buffer \n
*******************************************************************************/
typedef struct {
    VAR(uint16, AUTOMATIC)                                      u16BuffLength;
    P2VAR(uint8, AUTOMATIC, PDUR_VAR)                           pu8BuffData;
} PduR_tstrTpBuffPCCfgType;

/*--------------------------------TP Multicast--------------------------------*/

/******************************************************************************/
/*! \Description    Routing table used in multicasting over TP to hold the set
                    of destinations that the operation will be perfomed on \n
*******************************************************************************/
typedef struct {
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduRef            */
    VAR(PduIdType, AUTOMATIC)                       udtDstPduRefId;
    /* Auto-generated                                                         */
    VAR(uint8, AUTOMATIC)                           u8DstPduDeviceId;
    /* Auto-generated                                                         */
    VAR(uint16, AUTOMATIC)                          u16IPduGlobalId;
    /* PduRRoutingPathGroup.PduRRoutingPathGroupId containing this Dests Ref  */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RPathGrpId;
    #endif
    /* Auto-generated                                                         */
    VAR(PduIdType, AUTOMATIC)                       udtCntrlId;
    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
    /* CopyTxData API ID for this destination                                 */
    VAR(uint8, AUTOMATIC)                           u8CopyTxApiId;
    #endif
} PduR_tstrMultiTpRTableType;

/******************************************************************************/
/*! \Description    Helper table used in multicasting over TP to hold some 
                    extra information used to aid implementation's logic \n
*******************************************************************************/
typedef struct {
    VAR(uint8, AUTOMATIC)                           u8StartId;
    VAR(uint8, AUTOMATIC)                           u8CntrMax;
    VAR(PduIdType, AUTOMATIC)                       udtSrcPduRefId;
    VAR(uint8, AUTOMATIC)                           u8SrcPduDeviceId;
    VAR(uint16, AUTOMATIC)                          u16TxGlobalId;
} PduR_tstrMultiTpSubRTType;

/******************************************************************************/
/*! \Description    Control table used in multicasting over TP to hold some 
                    extra information used to aid implementation's logic \n
*******************************************************************************/
typedef struct {
    VAR(boolean, AUTOMATIC)                         bIsFirst;
    VAR(uint8, AUTOMATIC)                           u8CntrValue;
    VAR(NotifResultType, AUTOMATIC)                 u8ConfResult;
} PduR_tstrMultiTpCntrlType;

/*--------------------------------IF Multicast--------------------------------*/

/******************************************************************************/
/*! \Description    Routing table used in multicasting over IF to hold the set
                    of destinations that the operation will be perfomed on \n
*******************************************************************************/
typedef struct {
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduRef            */
    VAR(PduIdType, AUTOMATIC)                       udtDstPduRefId;
    /* Auto-generated                                                         */
    VAR(uint8, AUTOMATIC)                           u8DstPduDeviceId;
    /* Auto-generated                                                         */
    VAR(uint16, AUTOMATIC)                          u16IPduGlobalId;
    /* PduRRoutingPathGroup.PduRRoutingPathGroupId containing this Dests Ref  */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RPathGrpId;
    #endif
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduDataProvision  */
    VAR(PduR_tu8DataProvisionType, AUTOMATIC)       u8DataProvision;
    /* Auto-generated                                                         */
    VAR(PduIdType, AUTOMATIC)                       udtCntrlId;
} PduR_tstrMultiIfRTableType;

/******************************************************************************/
/*! \Description    Helper table used in multicasting over IF to hold some 
                    extra information used to aid implementation's logic \n
*******************************************************************************/
typedef struct {
    VAR(uint8, AUTOMATIC)                           u8CntrMax;
    VAR(boolean, AUTOMATIC)                         bTxConf;
    VAR(PduIdType, AUTOMATIC)                       udtSrcPduRefId;
    VAR(uint8, AUTOMATIC)                           u8SrcPduDeviceId;
    VAR(uint16, AUTOMATIC)                          u16TxGlobalId;
} PduR_tstrMultiIfSubRTType;

/*---------------------------------TP Gateway---------------------------------*/

/******************************************************************************/
/*! \Description    Control table used in gatewaying over TP to hold some 
                    extra information used to aid implementation's logic \n
*******************************************************************************/
typedef struct {
    VAR(uint16, AUTOMATIC)                          u16BuffIdx;
    VAR(uint8, AUTOMATIC)                           u8CntrValue;
    VAR(boolean, AUTOMATIC)                         bTxDone;
} PduR_tstrGateTpCntrlType;

/******************************************************************************/
/*! \Description    Helper table used in multicasting over TP to hold some 
                    extra information used to aid implementation's logic \n
*******************************************************************************/
typedef struct {
    VAR(uint8, AUTOMATIC)                           u8StartId;
    VAR(uint16, AUTOMATIC)                          u16RxGlobalId;
    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
    VAR(uint8, AUTOMATIC)                           u8StartRxApiId;
    VAR(uint8, AUTOMATIC)                           u8CopyRxDApiId;
    VAR(uint8, AUTOMATIC)                           u8RxIndApiId;
    #endif
} PduR_tstrGateTpSubRTType;

/*-------------------------------Routing Tables-------------------------------*/

/******************************************************************************/
/*! \Description    Routing table that holds (for each upper BswModule) the 
                    information of the destinations that this module will 
                    communicate with (e.g.: transmit to its msg) \n
*******************************************************************************/
typedef struct {
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduRef            */
    VAR(PduIdType, AUTOMATIC)                       udtDstPduRefId;
    /* Auto-generated                                                         */
    VAR(uint8, AUTOMATIC)                           u8DstPduDeviceId;
    /* Auto-generated                                                         */
    VAR(uint16, AUTOMATIC)                          u16IPduGlobalId;
    /* PduRRoutingPathGroup.PduRRoutingPathGroupId containing this Dests Ref  */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RPathGrpId;
    #endif
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduDataProvision  */
    VAR(PduR_tu8DataProvisionType, AUTOMATIC)       u8DataProvision;
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRTxConfirmation        */
    VAR(boolean, AUTOMATIC)                         bTxConfirmation;
} PduR_tstrUpTxRTableType;

/******************************************************************************/
/*! \Description    Routing table that holds (for each TP upper BswModule) the 
                    reverse information used when a cancellation operation or
                    change parameter operation are invoked \n
*******************************************************************************/
typedef struct {
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduRef            */
    VAR(PduIdType, AUTOMATIC)                       udtDstPduRefId;
    /* Auto-generated                                                         */
    VAR(uint8, AUTOMATIC)                           u8DstPduDeviceRefId;
    /* Auto-generated                                                         */
    VAR(PduIdType, AUTOMATIC)                       udtLowPduRefId;
    /* PduRRoutingPathGroup.PduRRoutingPathGroupId containing this Dests Ref  */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RPathGrpId;
    #endif
} PduR_tstrUpTpRevTableType;

/******************************************************************************/
/*! \Description    Routing table that holds (for each lower IF BswModule) the 
                    information of the source that this module will communicate
                    with (e.g.: forward the confirmation to) \n
*******************************************************************************/
typedef struct {
    /* PduRRoutingTable.PduRRoutingPath.PduRSrcPdu.PduRSrcPduRef              */
    VAR(PduIdType, AUTOMATIC)                       udtUpPduRefId;
    /* Auto-generated                                                         */
    VAR(uint8, AUTOMATIC)                           u8UpPduDeviceId;
    /* Auto-generated                                                         */
    VAR(uint16, AUTOMATIC)                          u16IPduGlobalId;
    /* PduRRoutingPathGroup.PduRRoutingPathGroupId containing this Dests Ref  */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RPathGrpId;
    #endif
    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduDataProvision  */
    VAR(PduR_tu8DataProvisionType, AUTOMATIC)       u8DataProvision;
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRTxConfirmation        */
    VAR(boolean, AUTOMATIC)                         bTxConfirmation;
    #endif
} PduR_tstrLoIfTxRTableType;

/******************************************************************************/
/*! \Description    Routing table that holds (for each lower TP BswModule) the 
                    information of the source that this module will communicate
                    with (e.g.: forward the confirmation to) \n
*******************************************************************************/
typedef struct {
    /* PduRRoutingTable.PduRRoutingPath.PduRSrcPdu.PduRSrcPduRef              */
    VAR(PduIdType, AUTOMATIC)                       udtUpPduRefId;
    /* Auto-generated                                                         */
    VAR(uint8, AUTOMATIC)                           u8UpPduDeviceId;
    /* Auto-generated                                                         */
    VAR(uint16, AUTOMATIC)                          u16IPduGlobalId;
    /* PduRRoutingPathGroup.PduRRoutingPathGroupId containing this Dests Ref  */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RPathGrpId;
    #endif
} PduR_tstrLoTpTxRTableType;

/******************************************************************************/
/*! \Description    Routing table that holds (for each lower IF BswModule) the 
                    information of the destinations that this module will 
                    communicate with (e.g.: transfer the RxIndication to) \n
*******************************************************************************/
typedef struct {
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduRef            */
    VAR(PduIdType, AUTOMATIC)                       udtUpPduRefId;
    /* Auto-generated                                                         */
    VAR(uint8, AUTOMATIC)                           u8UpPduDeviceId;
    /* PduRRoutingPathGroup.PduRRoutingPathGroupId containing this Dests Ref  */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RPathGrpId;
    #endif
} PduR_tstrLoIfRxRTableType;

/******************************************************************************/
/*! \Description    Routing table that holds (for each lower IF BswModule) the 
                    information of the destinations (only upper) that this 
                    module will communicate with (e.g.: transfer RxIndication 
                    to multiple upper layers - Up Multicast Feature) \n
*******************************************************************************/
typedef struct {
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduRef            */
    VAR(PduIdType, AUTOMATIC)                       udtUpPduRefId;
    /* Auto-generated                                                         */
    VAR(uint8, AUTOMATIC)                           u8UpPduDeviceId;
    /* PduRRoutingPathGroup.PduRRoutingPathGroupId containing this Dests Ref  */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RPathGrpId;
    #endif
    /* Auto-generated                                                         */
    VAR(PduIdType, AUTOMATIC)                       udtCntrlId;
} PduR_tstrLoIfMulRxRTableType;

/******************************************************************************/
/*! \Description    Routing table that holds (for each lower TP BswModule) the 
                    information of the destinations that this module will 
                    communicate with (e.g.: transfer the RxIndication to) \n
*******************************************************************************/
typedef struct {
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduRef            */
    VAR(PduIdType, AUTOMATIC)                       udtUpPduRefId;
    /* Auto-generated                                                         */
    VAR(uint8, AUTOMATIC)                           u8UpPduDeviceId;
    /* Auto-generated                                                         */
    VAR(uint16, AUTOMATIC)                          u16IPduGlobalId;
    /* PduRRoutingPathGroup.PduRRoutingPathGroupId containing this Dests Ref  */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RPathGrpId;
    #endif
} PduR_tstrLoTpRxRTableType;

/******************************************************************************/
/*! \Description    Routing table that holds all the IF destinations that a
                    gatewaying IF operation will be operating on \n
*******************************************************************************/
typedef struct {
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduRef            */
    VAR(PduIdType, AUTOMATIC)                                 udtDstPduRefId;
    /* Auto-generated                                                         */
    VAR(uint8, AUTOMATIC)                                     u8DstPduDeviceId;
    /* Auto-generated                                                         */
    VAR(uint16, AUTOMATIC)                                    u16IPduGlobalId;
    /* PduRRoutingPathGroup.PduRRoutingPathGroupId containing this Dests Ref  */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)               u16RPathGrpId;
    #endif
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduDataProvision  */
    VAR(PduR_tu8DataProvisionType, AUTOMATIC)                 u8DataProvision;
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRTxConfirmation        */
    VAR(boolean, AUTOMATIC)                                   bTxConfirmation;
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestTxBufferRef       */
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CONST)  pkstrTxBuffRef;
    /* Auto-generated                                                         */
    VAR(PduIdType, AUTOMATIC)                                 udtCntrlId;
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDefaultValue          */
    P2CONST(uint8, AUTOMATIC, PDUR_CFG_CONST)                 pku8DefData;
    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
    /* RxIndication API ID for this destination                               */
    VAR(uint8, AUTOMATIC)                                     u8RxIndApiId;
    /* Txconfirmation API ID for this destination                             */
    VAR(uint8, AUTOMATIC)                                     u8TxConfApiId;
    /* TriggerTransmit API ID for this destination                            */
    VAR(uint8, AUTOMATIC)                                     u8TrigTxApiId;
    #endif
    #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
    VAR(PduR_tpfbGateCallOut, AUTOMATIC)                      pfbGateCallOut;
    #endif
} PduR_tstrGateIfRTableType;

/******************************************************************************/
/*! \Description    Routing table that holds all the TP destinations that a
                    gatewaying TP operation will be operating on \n
*******************************************************************************/
typedef struct {
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRDestPduRef            */
    VAR(PduIdType, AUTOMATIC)                                 udtDstPduRefId;
    /* Auto-generated                                                         */
    VAR(uint8, AUTOMATIC)                                     u8DstPduDeviceId;
    /* Auto-generated                                                         */
    VAR(uint16, AUTOMATIC)                                    u16IPduGlobalId;
    /* PduRRoutingPathGroup.PduRRoutingPathGroupId containing this Dests Ref  */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)               u16RPathGrpId;
    #endif
    /* Auto-generated                                                         */
    VAR(PduIdType, AUTOMATIC)                                 udtCntrlId;
    /* PduRRoutingTable.PduRRoutingPath.PduRDestPdu.PduRTpThreshold           */
    VAR(uint8, AUTOMATIC)                                     u8BuffThreshold;
    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
    /* CopyTxData API ID for this destination                                 */
    VAR(uint8, AUTOMATIC)                                     u8CopyTxDApiId;
    #endif
    #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
    VAR(PduR_tpfbGateCallOut, AUTOMATIC)                      pfbGateCallOut;
    #endif
} PduR_tstrGateTpRTableType;

/******************************************************************************/
/*! \Description    Function pointer tables generated when there exist a 
                    PduRBswModule that has the following parameters set to TRUE
                    PduRLowerModule and PduRTransportProtocol 
                    or PduRUpperModule \n
*******************************************************************************/
typedef struct {
    VAR(PduR_tpfvidBswModuleInitFunc, PDUR_CALIB_CONST)       pfvidBswModuleInit;
} PduR_tstrBswModInitFuncPtrType;

/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/


#endif /* PDUR_TYPES_H */

/*------------------------------- end of file --------------------------------*/

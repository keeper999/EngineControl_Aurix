/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : CanTp                                                   */
/* !Description     : CanTp is the component between the PDU Router and the   */
/*                    CAN Interface module. The main purpose of the CanTp     */
/*                    component is to segment and reassemble CAN I-PDUs longer*/
/*                    than 8 bytes                                            */
/*                                                                            */
/* !File            : CanTp_Utilities.h                                       */
/*                                                                            */
/* !Scope           : PrivateComponent                                        */
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
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/19_CanTp/0$*/
/* $Revision::   1.4      $$Author::   sedrees        $$Date::   Mar 27 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/******************************************************************************/
/*! \file CanTp_Utilities.h
*
* \par
*   This file contains the services, data, or macros exported by the
    Utilities sub-component.                                                  \n
    The Utilities sub-component contains common utility services that are
    used by the Main, Reception, and Transmission sub-components.             */
/******************************************************************************/
#ifndef CANTP_UTILITIES_H
#define CANTP_UTILITIES_H

#include "Std_Types.h"
#include "CanTp_LocalCfg.h"
#include "PduR_CanTp.h"
#include "CanIf.h"

#if(CanTp_bDEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


/******************************************************************************/
/*************************** CanTpConnection State ****************************/
/******************************************************************************/
/*                                                                            */
/*                          bits [7|6|5|4|3|2|1|0]                            */
/*                               ^DIR^OPER.^FRAME'                            */
/*                                                                            */
/*  <DIR> 00 IDLE   <OPERATION> 000 IDLE        <frame> 000 IDLE              */
/*        01 RX                 001 REQBUFF             001 SF                */
/*        10 TX                 010 TANSMIT             010 FF                */
/*                              011 WAITRX              011 CF                */
/*                              100 WAITCONF            100 LAST_CF           */
/*                              101 HANDLE              101 FC_CTS            */
/*                                                      110 FC_WAIT           */
/*                                                      111 FC_OVFLW          */
/******************************************************************************/


#define CanTp_u8DIRECTION_OFFSET    (uint8)6
#define CanTp_u8OPERATION_OFFSET    (uint8)3



#define CanTp_u8DIR_IDLE            (uint8)0
#define CanTp_u8DIR_RX              ((uint8)1 << CanTp_u8DIRECTION_OFFSET)
#define CanTp_u8DIR_TX              ((uint8)2 << CanTp_u8DIRECTION_OFFSET)
#define CanTp_u8DIR_MASK            ((uint8)3 << CanTp_u8DIRECTION_OFFSET)

#define CanTp_u8OP_NOT_USED         (uint8)0
#define CanTp_u8OPERATION_REQBUFF   ((uint8)1 << CanTp_u8OPERATION_OFFSET)
#define CanTp_u8OPERATION_TRANSMIT  ((uint8)2 << CanTp_u8OPERATION_OFFSET)
#define CanTp_u8OPERATION_WAITRX    ((uint8)3 << CanTp_u8OPERATION_OFFSET)
#define CanTp_u8OPERATION_WAITCONF  ((uint8)4 << CanTp_u8OPERATION_OFFSET)
#define CanTp_u8OPERATION_HANDLE    ((uint8)5 << CanTp_u8OPERATION_OFFSET)
#define CanTp_u8OPERATION_MASK      ((uint8)7 << CanTp_u8OPERATION_OFFSET)

#define CanTp_u8FRAME_NOT_USED      (uint8)0
#define CanTp_u8FRAME_SF            (uint8)1
#define CanTp_u8FRAME_FF            (uint8)2
#define CanTp_u8FRAME_CF            (uint8)3
#define CanTp_u8FRAME_LAST_CF       (uint8)4
#define CanTp_u8FRAME_FC_CTS        (uint8)5
#define CanTp_u8FRAME_FC_WAIT       (uint8)6
#define CanTp_u8FRAME_FC_OVFLW      (uint8)7
#define CanTp_u8FRAME_MASK          (uint8)7


/******************************************************************************/
/*! \Description    State is Idle                                             \n
*******************************************************************************/
#define CanTp_u8IDLE_STATE \
  (uint8)(CanTp_u8DIR_IDLE | CanTp_u8OP_NOT_USED | CanTp_u8FRAME_NOT_USED)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Request Buffer for a Single Frame    \n
*******************************************************************************/
#define CanTp_u8RX_REQBUFF_SF \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_REQBUFF | CanTp_u8FRAME_SF)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Request Buffer for a First Frame     \n
*******************************************************************************/
#define CanTp_u8RX_REQBUFF_FF \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_REQBUFF  | CanTp_u8FRAME_FF)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Request Buffer for a Consecutive 
                    Frame                                                     \n
*******************************************************************************/
#define CanTp_u8RX_REQBUFF_CF \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_REQBUFF  | CanTp_u8FRAME_CF)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Request Buffer for a last 
                    Consecutive Frame                                         \n
*******************************************************************************/
#define CanTp_u8RX_REQBUFF_LAST_CF \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_REQBUFF  | CanTp_u8FRAME_LAST_CF)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Transmit Flow Control Frame "Clear To
                    Send"                                                     \n
*******************************************************************************/
#define CanTp_u8RX_TRANSMIT_FC_CTS \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_TRANSMIT | CanTp_u8FRAME_FC_CTS)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Transmit Flow Control Frame "WAIT"   \n
*******************************************************************************/
#define CanTp_u8RX_TRANSMIT_FC_WAIT \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_TRANSMIT | CanTp_u8FRAME_FC_WAIT)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Transmit Flow Control Frame
                    "OVERFLOW"                                                \n
*******************************************************************************/
#define CanTp_u8RX_TRANSMIT_FC_OVFLW \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_TRANSMIT | CanTp_u8FRAME_FC_OVFLW)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Wait for Flow Control Frame "Clear To
                    Send" transmission confirmation                           \n
*******************************************************************************/
#define CanTp_u8RX_WAITCONF_FC_CTS \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_WAITCONF | CanTp_u8FRAME_FC_CTS)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Wait for Flow Control Frame "WAIT"
                    transmission confirmation                                 \n
*******************************************************************************/
#define CanTp_u8RX_WAITCONF_FC_WAIT \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_WAITCONF | CanTp_u8FRAME_FC_WAIT)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Wait for Flow Control Frame "OVERFLOW"
                    transmission confirmation                                 \n
*******************************************************************************/
#define CanTp_u8RX_WAITCONF_FC_OVFLW \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_WAITCONF | CanTp_u8FRAME_FC_OVFLW)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Wait for consecutive frame reception \n
*******************************************************************************/
#define CanTp_u8RX_WAITRX_CF \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_WAITRX   | CanTp_u8FRAME_CF)


/******************************************************************************/
/*! \Description    Rx CanTpConnection - Wait for last consecutive frame
                    reception                                                 \n
*******************************************************************************/
#define CanTp_u8RX_WAITRX_LAST_CF \
  (uint8)(CanTp_u8DIR_RX | CanTp_u8OPERATION_WAITRX   | CanTp_u8FRAME_LAST_CF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Request Buffer for a Single Frame    \n
*******************************************************************************/
#define CanTp_u8TX_REQBUFF_SF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_REQBUFF  | CanTp_u8FRAME_SF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Request Buffer for a First Frame     \n
*******************************************************************************/
#define CanTp_u8TX_REQBUFF_FF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_REQBUFF  | CanTp_u8FRAME_FF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Request Buffer for a Consecutive
                    Frame                                                     \n
*******************************************************************************/
#define CanTp_u8TX_REQBUFF_CF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_REQBUFF  | CanTp_u8FRAME_CF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Request Buffer for a last Consecutive
                    Frame                                                     \n
*******************************************************************************/
#define CanTp_u8TX_REQBUFF_LAST_CF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_REQBUFF  | CanTp_u8FRAME_LAST_CF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Transmit a Single Frame              \n
*******************************************************************************/
#define CanTp_u8TX_TRANSMIT_SF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_TRANSMIT | CanTp_u8FRAME_SF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Transmit a First Frame               \n
*******************************************************************************/
#define CanTp_u8TX_TRANSMIT_FF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_TRANSMIT | CanTp_u8FRAME_FF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Transmit a Consecutive Frame         \n
*******************************************************************************/
#define CanTp_u8TX_TRANSMIT_CF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_TRANSMIT | CanTp_u8FRAME_CF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Transmit a last Consecutive Frame    \n
*******************************************************************************/
#define CanTp_u8TX_TRANSMIT_LAST_CF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_TRANSMIT | CanTp_u8FRAME_LAST_CF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Wait for Single Frame transmission
                    confirmation                                              \n
*******************************************************************************/
#define CanTp_u8TX_WAITCONF_SF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_WAITCONF | CanTp_u8FRAME_SF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Wait for First Frame transmission
                    confirmation                                              \n
*******************************************************************************/
#define CanTp_u8TX_WAITCONF_FF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_WAITCONF | CanTp_u8FRAME_FF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Wait for Consecutive Frame transmission
                    confirmation                                              \n
*******************************************************************************/
#define CanTp_u8TX_WAITCONF_CF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_WAITCONF | CanTp_u8FRAME_CF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Wait for last Consecutive Frame
                    transmission confirmation                                 \n
*******************************************************************************/
#define CanTp_u8TX_WAITCONF_LAST_CF \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_WAITCONF | CanTp_u8FRAME_LAST_CF)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Wait for Flow Control Frame reception\n
*******************************************************************************/
#define CanTp_u8TX_WAITRX_FC \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_WAITRX   | CanTp_u8FRAME_FC_CTS)


/******************************************************************************/
/*! \Description    Tx CanTpConnection - Handle Flow Control                  \n
*******************************************************************************/
#define CanTp_u8TX_HANDLE_FC \
  (uint8)(CanTp_u8DIR_TX | CanTp_u8OPERATION_HANDLE   | CanTp_u8FRAME_FC_CTS)


/******************************************************************************/
/*! \Description    N_PCI type value of a single frame according to           \n
                    ISO 15765-2_2004                                          \n
    \Range          0                                                         \n
*******************************************************************************/
#define CanTp_u8SINGLE_FRAME        (uint8)0

/******************************************************************************/
/*! \Description    N_PCI type value of a first frame according to            \n
                    ISO 15765-2_2004                                          \n
    \Range          1                                                         \n
*******************************************************************************/
#define CanTp_u8FIRST_FRAME         (uint8)1

/******************************************************************************/
/*! \Description    N_PCI type value of a consecutive frame according to      \n
                    ISO 15765-2_2004                                          \n
    \Range          2                                                         \n
*******************************************************************************/
#define CanTp_u8CONSECUTIVE_FRAME   (uint8)2

/******************************************************************************/
/*! \Description    N_PCI type value of a flow control frame according to     \n
                    ISO 15765-2_2004                                          \n
    \Range          3                                                         \n
*******************************************************************************/
#define CanTp_u8FLOW_CONTROL_FRAME  (uint8)3

/******************************************************************************/
/*! \Description    A mask used to extract the N_PCI type out of the first PCI\n
                    byte of a received frame in order to identify the frame   \n
                    type                                                      \n
    \Range          0xF0                                                      \n
*******************************************************************************/
#define CanTp_u8PCI_FRAME_TYPE_MASK (uint8)0xF0



#define CanTp_u16MAX_NSDU_LENGTH        (uint16)0x0FFF

#define CanTp_u8STD_SF_PCI_BYTE         0
#define CanTp_u8SF_NUM_PCI_BYTES        1
#define CanTp_u8STD_SF_DATA_BYTE        1
#define CanTp_u8STD_SF_DATA_LENGTH      7
#define CanTp_u8SF_PCI_DL_MASK          (uint8)0x0F

#define CanTp_u8STD_FF_PCI_BYTE         0
#define CanTp_u8STD_FF_DATA_BYTE        2
#define CanTp_u8STD_FF_DATA_LENGTH      6
#define CanTp_u8FF_PCI_ID_MASK          (uint8)0x10
#define CanTp_u16FF_PCI_DL_L_MASK       (uint16)0xFF
#define CanTp_u16FF_PCI_DL_H_MASK       0xF00

#define CanTp_u8STD_CF_PCI_BYTE         0
#define CanTp_u8CF_NUM_PCI_BYTES        1
#define CanTp_u8STD_CF_DATA_BYTE        1
#define CanTp_u8STD_CF_DATA_LENGTH      7
#define CanTp_u8CF_PCI_ID_MASK          0x20
#define CanTp_u8CF_PCI_SN_MASK          (uint8)0x0F
#define CanTp_u8CF_MAX_SN               15

#define CanTp_u8FC_FS_CTS               (uint8)0
#define CanTp_u8FC_FS_WAIT              (uint8)1
#define CanTp_u8FC_FS_OVFLW             (uint8)2
#define CanTp_u8FC_FS_TYPE_MASK         (uint8)0x0F
#define CanTp_u8FC_FC_FS_MASK           (uint8)0x30
#define CanTp_u8STD_FC_PCI_BYTE         0
#define CanTp_u8FC_NUM_PCI_BYTES        3


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [3453]: Function-like macros are used for  */
/*              optimization                                                  */
/* PRQA S 3453 ++                                                             */

/******************************************************************************/
/*! \Description    Macro to extract the N_PCI type value out of the first PCI
                    byte of the received frame                                \n
    \Return         N_PCI type value                                          \n
*******************************************************************************/
#define CanTp_u8PCI_FRAME_TYPE(                                                \
/*! \param  u8FirstPciByte  First PCI byte of the received frame             */\
u8FirstPciByte)                                                                \
    (uint8)(((u8FirstPciByte) & CanTp_u8PCI_FRAME_TYPE_MASK) >> 4)


/******************************************************************************/
/*! \Description    Macro to get the direction of the CanTpConnection (Tx/Rx) \n
    \Return         CanTpConnection direction                                 \n
*******************************************************************************/
#define CanTp_u8GET_DIRECTION(                                                 \
/*! \param  pstrChannelResources  Pointer to the CanTpConnection resources   */\
pstrChannelResources)                                                          \
    (((pstrChannelResources)->u8ConnectionState & CanTp_u8DIR_MASK))


/******************************************************************************/
/*! \Description    Macro to get the operation taking place on the 
                    CanTpConnection                                           \n
    \Return         CanTpConnection operation                                 \n
*******************************************************************************/
#define CanTp_u8GET_OPERATION(                                                 \
/*! \param  pstrChannelResources  Pointer to the CanTpConnection resources   */\
pstrChannelResources)                                                          \
    (((pstrChannelResources)->u8ConnectionState & CanTp_u8OPERATION_MASK))


/******************************************************************************/
/*! \Description    Macro to get the type of the frame being handled on the
                    CanTpConnection                                           \n
    \Return         Frame type                                                \n
*******************************************************************************/
#define CanTp_u8GET_FRAME_TYPE(                                                \
/*! \param  pstrChannelResources  Pointer to the CanTpConnection resources   */\
pstrChannelResources)                                                          \
    (((pstrChannelResources)->u8ConnectionState & CanTp_u8FRAME_MASK))


#define CanTp_vidREPORT_DET_ERROR(u8ApiId, u8ErrorId)                          \
   ((void)Det_ReportError(                                                     \
                    CANTP_MODULE_ID, CANTP_INSTANCE_ID, (u8ApiId), (u8ErrorId)))

/******************************************************************************/

#define CanTp_udtLOWER_LAYER_TX(udtTxPduId, pkudPduInfo)                       \
                                      CanIf_Transmit((udtTxPduId),(pkudPduInfo))

/******************************************************************************/

#define CanTp_vidUPPER_LAYER_INDIC(udtIPduId, udtResult)                       \
                                 PduR_CanTpRxIndication((udtIPduId),(udtResult))

/******************************************************************************/

#define CanTp_vidUPPER_LAYER_CONF(udtIPduId, udtResult)                        \
                               PduR_CanTpTxConfirmation((udtIPduId),(udtResult))

/******************************************************************************/

#define CanTp_udtUPPER_LAYER_START(                                            \
                      udtIPduId,pudtPduInfo,udtSduLength,pudtAvilableLength)   \
            PduR_CanTpStartOfReception(                                        \
			         (udtIPduId),(NULL_PTR),(udtSduLength),(pudtAvilableLength))

/******************************************************************************/

#define CanTp_udtUPPER_LAYER_RX_COPY(udtIPduId,pudtPduInfo,pudtAvilableLength) \
            PduR_CanTpCopyRxData((udtIPduId),(pudtPduInfo),(pudtAvilableLength))

/******************************************************************************/

#define CanTp_udtUPPER_LAYER_TX_COPY(                                          \
                         udtIPduId,pudtPduInfo, pudtRetry, pudtAvilableLength) \
            PduR_CanTpCopyTxData(                                              \
                    (udtIPduId),(pudtPduInfo),(pudtRetry), (pudtAvilableLength))

/******************************************************************************/

#define CanTp_vidUPPER_LAYER_PAR_CONF(udtIPduId, udtResult)                    \
                  PduR_CanTpChangeParameterConfirmation((udtIPduId),(udtResult))

/******************************************************************************/

/* PRQA S 3453 --                                                             */


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define CANTP_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/*! \Description    This function performs the initialization of the
                    CanTpConnection resources after stopping the CanTpConnection
                    after a reception/transmission operation                  \n
    \param[in/out]  pstrChannelResources    Pointer to the CanTpConnection 
                                            resources at which the transmission/
                                            reception operation is taking
                                            place                             \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidInitChannelResources (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pstrChannelResources);


/******************************************************************************/
/*! \Description    A function used to copy data from a source buffer to
                    a destination buffer                                      \n
    \param[in]      pku8Source      Pointer to the address of the source
                                    buffer                                    \n
    \param[in/out]  pu8Destination  Pointer to the address of the destination
                                    buffer                                    \n
    \param[in]      u8Length        Length of the data to be copied           \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidMemoryCopy (
    P2CONST(uint8, AUTOMATIC, CANTP_APPL_DATA)  pku8Source,
    P2VAR(uint8, AUTOMATIC, CANTP_VAR)   pu8Destination,
    VAR(uint8, AUTOMATIC)   u8Length);


/******************************************************************************/
/*! \Description    A function used to pad a number of bytes in an 8-byte 
                    buffer with a constant value                              \n
    \param[in]      u8StartByte     Location of the byte from which the padding
                                    shall start                               \n
    \param[in/out]  pu8TxBuffer     Pointer to the address of the buffer      \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidPadTxBuffer (
    VAR(uint8, AUTOMATIC) u8StartByte,
    P2VAR(uint8, AUTOMATIC, CANTP_VAR) pu8TxBuffer);


/******************************************************************************/
/*! \Description    A function that checks whether the next consecutive frame
                    to be handled will be the last frame in the message or not\n
    \param[in]      u8Direction             Direction of the CanTpConnection  \n
    \param[in]      pstrChannelResources    Pointer to the CanTpConnection 
                                            resources at which the transmission/
                                            reception operation is taking
                                            place                             \n
    \param[in]      udtNSduId               ID of the CanTpNSdu being handled \n
    \return         Check result:                                             \n
                    TRUE:                   Next consecutive frame is the last
                                            frame in the message              \n
                    FALSE:                  Next consecutive frame is not the
                                            last frame in the message         \n
*******************************************************************************/
extern FUNC(boolean, CANTP_CODE) CanTp_bIsNextFrameLastInMsg (
    VAR(uint8, AUTOMATIC)       u8Direction,
    VAR(PduIdType, AUTOMATIC)   udtNSduId,
	P2CONST(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
							                            pkstrChannelResources);


#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#endif  /* CANTP_UTILITIES_H */

/*-------------------------------- end of file -------------------------------*/

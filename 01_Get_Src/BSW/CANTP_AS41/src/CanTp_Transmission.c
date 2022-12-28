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
/* !File            : CanTp_Transmission.c                                    */
/*                                                                            */
/* !Scope           : Private                                                 */
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
/* $Revision::   1.13     $$Author::   AELSOHBY       $$Date::   Mar 31 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp_Transmission.c
*
* \par
*   This file contains the implementation of the Transmission sub-component.  \n
    The Transmission sub-component contains all the services needed to perfrom
    a TxNSdu transmission operation.                                          */
/******************************************************************************/

/* !Deviation : Inhibit MISRA rule [0838]: Multiple inclusion prevention      */
/*              macros solves multiple/re-inclusions issues                   */
/* PRQA S 0838 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0838]: AUTOMATIC keyword is defined as an */
/*              empty macro                                                   */
/* PRQA S 0850 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0862]: Memmap.h is used for assignation   */
/*              memory segments in the linker                                 */
/* PRQA S 0862 L1                                                             */
/* PRQA S 5087 L1                                                             */

#include "CanTp_Utilities.h"
#include "CanTp_Main.h"
#include "CanTp_Transmission.h"
#include "CanTp.h"

    

/******************************************************************************/
/* LOCAL FUNCTIONS DECLARATION                                                */
/******************************************************************************/

#define CANTP_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/*! \Description    This function stops and re-initializes a CanTpConnection
                    resources after transmission, and notifies the upper layer
                    with the transmission result                              \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
    \param[in]      udtTxNSduId             CanTpTxNSduId that was being 
                                            handled                           \n
                    \Range                  0 .. CanTp_u16NUM_OF_TX_NSDUS-1   \n
    \param[in]      udtResult               Transmission result               \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidStopTxChannel(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                    pudtChannelResources,
    VAR(NotifResultType, AUTOMATIC) udtResult,
	VAR(PduIdType, AUTOMATIC)       udtTxNSduId);


/******************************************************************************/
/*! \Description    This function performs the development errors checking for
                    CanTp_Transmit() API                                      \n
    \param[in]      pkudtCanTpTxInfoPtr     A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
    \param[out]     pudtReturnValue         A pointer to a flag variable that
                                            indicates whether an error was
                                            detected or not                   \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidCheckTransmitErrors(
    VAR(PduIdType, AUTOMATIC) udtCanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) pkudtCanTpTxInfoPtr,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) pudtReturnValue);


/*! \Description    This function handles transmission cancellation requests  \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidHandleTxCancelReq (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function calculates the number of frames that will 
                    transmitted in the next block of frames, according to
                    the BS value received within the flow control frame       \n
    \param[in]      udtTxNSduId             CanTpTxNSduId that is currently
                                            being handled in the transmission
                                            operation                         \n
                    \Range                  0 .. CanTp_u16NUM_OF_TX_NSDUS-1   \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
    \param[in]      u8ReceivedBlockSize     BS value received within the flow
                                            control frame                     \n
*******************************************************************************/
LOCAL_INLINE FUNC(void, CANTP_CODE) vidCalculateBlockSize(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pudtChannelResources,    
	VAR(PduIdType, AUTOMATIC)   udtTxNSduId,
    VAR(uint8, AUTOMATIC)       u8ReceivedBlockSize);


/******************************************************************************/
/*! \Description    This function calculates the number of main function calls  
                    remaining before the next consecutive frame can be 
                    transmitted, according to the STmin value received within 
                    the flow control frame                                    \n
    \param[in]      udtTxNSduId             CanTpTxNSduId that is currently
                                            being handled in the transmission
                                            operation                         \n
                    \Range                  0 .. CanTp_u16NUM_OF_TX_NSDUS-1   \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
    \param[in]      u8ReceivedBlockSize     STmin value received within the 
                                            flow control frame                \n
*******************************************************************************/
LOCAL_INLINE FUNC(void, CANTP_CODE) vidCalculateSTmin(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pudtChannelResources,
	VAR(PduIdType, AUTOMATIC)   udtTxNSduId,
    VAR(uint8, AUTOMATIC)       u8ReceivedSTmin);


/******************************************************************************/
/*! \Description    This function handles the flow control that was received 
                    and stored in the local buffer till the next Main function
                    call                                                      \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidHandleFCFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function checks whether the STmin time has passed and
                    that the next consecutive frame can be transmitted or not \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
*******************************************************************************/
LOCAL_INLINE FUNC(void, CANTP_CODE) vidCheckIfSTminPassed(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function calculates the number of data bytes that   
                    need to be requested from the upper layer before proceeding
                    to transmit a frame                                       \n
    \param[in]      pkstrChannelResources   A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
    \param[in]      pu8StartByteLocation    A pointer to a variable that stores
                                            the location of the first data byte
                                            in the frame according to the
                                            addressing format of the 
                                            CanTpTxNSdu                       \n
    \param[in]      pu8BytesRemaining       A pointer to a variable that stores
                                            the number of bytes remaining to 
                                            be requested from the upper layer 
                                            (Total bytes needed - bytes already
                                            received from upper layer and stored
                                            in the local buffer               \n
    \param[in]      pu8BytesToBeProvided    A pointer to a variable that stores
                                            the total number of bytes that need
                                            to be provided from the upper layer
                                            before proceeding to transmit the
                                            frame                             \n
*******************************************************************************/
LOCAL_INLINE FUNC(void, CANTP_CODE) vidCalculateNeededBytes (
    P2CONST(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pkstrChannelResources,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8StartByteLocation,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8BytesRemaining,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8BytesToBeProvided);


/******************************************************************************/
/*! \Description    This function requests the data bytes (from the upper layer)
                    that need to be transmitted for each frame                \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidRequestTxBuffer (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function prepares the PCI information of a single
                    frame and writes it to the local frame buffer             \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
    \param[out]     pu8Dlc                  A pointer to variable at which the
                                            DLC of the single frame to be
                                            transmitted is stored             \n
*******************************************************************************/
LOCAL_INLINE FUNC(void, CANTP_CODE) vidPrepareSingleFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pudtChannelResources,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8Dlc);


/******************************************************************************/
/*! \Description    This function prepares the PCI information of a first
                    frame and writes it to the local frame buffer             \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
    \param[out]     pu8Dlc                  A pointer to variable at which the
                                            DLC of the first frame to be
                                            transmitted is stored             \n
*******************************************************************************/
LOCAL_INLINE FUNC(void, CANTP_CODE) vidPrepareFirstFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pudtChannelResources,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8Dlc);


/******************************************************************************/
/*! \Description    This function prepares the PCI information of a consecutive
                    frame and writes it to the local frame buffer             \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
    \param[out]     pu8Dlc                  A pointer to variable at which the
                                            DLC of the consecutive frame to be
                                            transmitted is stored             \n
*******************************************************************************/
LOCAL_INLINE FUNC(void, CANTP_CODE) vidPrepareConsecFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pudtChannelResources,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8Dlc);


/******************************************************************************/
/*! \Description    This function  sets the state machine of the CanTpConnection
                    state to its next state after a successful frame 
                    transmission                                              \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
    \param[in]      udtNSduIdHandled        CanTpTxNSduId that is currently
                                            being handled in the transmission
                                            operation                         \n
                    \Range                  0 .. CanTp_u16NUM_OF_TX_NSDUS-1   \n
    \param[in]      u8FrameType             Type of the frame that was
                                            transmitted                       \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidNextStateAfterTx (
	P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
														pudtChannelResources,
	VAR(uint8, AUTOMATIC)       u8FrameType,
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled
);


/******************************************************************************/
/*! \Description    This function prepares handles the transmission of SF, FF, 
                    or CF to the lower layer module after the data is provided
                    successfully from the upper layer                         \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidTransmitTxFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);




/******************************************************************************/
/* LOCAL FUNCTIONS DEFINITION                                                 */
/******************************************************************************/

static FUNC(void, CANTP_CODE) vidStopTxChannel(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                    pudtChannelResources,
    VAR(NotifResultType, AUTOMATIC) udtResult,
	VAR(PduIdType, AUTOMATIC)       udtTxNSduId)
{
    /*! \Trace_To   CanTp-CDD-0037(0), CanTp-CDD-0158(0)                      */

    VAR(PduIdType, AUTOMATIC)   udtUpperLayerId;

    /*! Get the IPduId linked to this CanTpTxNSdu in order to be passed to the
        upper layer callback                                                  */
    udtUpperLayerId = 
              CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtTxNSduId].udtTxIPduId;

    /*! Call the upper layer confirmation callback with the 
        corresponding notification result                                     */
    CanTp_vidUPPER_LAYER_CONF(udtUpperLayerId, udtResult);

    /*! Re-initialize the  CanTpConnection resources                          */
    CanTp_vidInitChannelResources(pudtChannelResources);
}

/******************************************************************************/

#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

static FUNC(void, CANTP_CODE) vidCheckTransmitErrors(
    VAR(PduIdType, AUTOMATIC) udtCanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) pkudtCanTpTxInfoPtr,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) pudtReturnValue)
{
    VAR(uint8, AUTOMATIC)           u8MaxLengthAllowed;

    /*! If a NULL pointer is received:                                        */
    if((pkudtCanTpTxInfoPtr == 
                       (P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA))NULL_PTR)
       ||
       (pkudtCanTpTxInfoPtr->SduDataPtr == NULL_PTR))
    {
        /*! Report the corresponding DET error code and return E_NOT_OK       */
        /*! \Trace_To   CanTp-CDD-0162(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8TRANSMIT_ID, CANTP_E_PARAM_POINTER);
        *pudtReturnValue = E_NOT_OK;
    }
    /*! If an invalid TxNSduId is received                                    */
    else if(udtCanTpTxSduId >= CanTp_u16NUM_OF_TX_NSDUS)
    {
        /*! Report the corresponding DET error code and return E_NOT_OK       */
        /*! \Trace_To   CanTp-CDD-5059(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8TRANSMIT_ID, CANTP_E_PARAM_ID);
        *pudtReturnValue = E_NOT_OK;
    }
    /*! If a TxNSdu with invalid length was requested for transmission due to:\n
        -Length = 0                                                           \n
        -Length is greater than the max. allowed (4095 bytes)                 \n
        -Length is less than the min. length configured for this CanTpTxNSdu  */
    else if((pkudtCanTpTxInfoPtr->SduLength == 0)
        ||
        (pkudtCanTpTxInfoPtr->SduLength > CanTp_u16MAX_NSDU_LENGTH)
        ||
        (pkudtCanTpTxInfoPtr->SduLength 
                < CanTp_akstreTxNSduPCCfg[udtCanTpTxSduId].u16TxDataLengthCode))
    {
        /*! Report the corresponding DET error code and return E_NOT_OK       */
        /*! \Trace_To   CanTp-CDD-5058(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8TRANSMIT_ID,
                                                     CANTP_E_INVALID_TX_LENGTH);
        *pudtReturnValue = E_NOT_OK;
    }
    else
    {
        /*! \note   If the target address type of the CanTpTxNSdu is configured
                    as functional addressing, then only single frame
                    transmission is allowed                                   */
                
        /*! If the target address type of the CanTpTxNSdu is configured as
            functional addressing:                                            */
        if(CanTp_akstreTxNSduPCCfg[udtCanTpTxSduId].u8TxTaType 
                                                  == CanTp_u8FUNCTIONAL_ADDRESS)
        {
            /*! If the addressing format of the CanTpTxNSdu is configured as
                standard addressing then the max. number of bytes that can be
                transmitted in a single frame are 7 bytes                     */
            if(CanTp_akstreTxNSduPCCfg[udtCanTpTxSduId].u8TxAddressingFormat
                                                 == CanTp_u8STANDARD_ADDRESSING)
            {
                u8MaxLengthAllowed = CanTp_u8STD_SF_DATA_LENGTH;
            }
            /*! If the addressing format of the CanTpTxNSdu is configured as
                extended or mixed addressing then the max. number of bytes that
                can be transmitted in a single frame are 6 bytes              */
            else
            {
                u8MaxLengthAllowed = (uint8)(CanTp_u8STD_SF_DATA_LENGTH - 1);
            }

            /*! If the length of the TxNSdu will not fit in a single frame:   */
            if(pkudtCanTpTxInfoPtr->SduLength > (uint16)u8MaxLengthAllowed)
            {
                /*! Report the corresponding DET error code and return 
                    E_NOT_OK                                                  */
                /*! \Trace_To   CanTp-CDD-5099(0)                             */
                CanTp_vidREPORT_DET_ERROR(CanTp_u8TRANSMIT_ID,
                                                        CANTP_E_INVALID_TATYPE);
                *pudtReturnValue = E_NOT_OK;
            }
        }
    }
}

#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidHandleTxCancelReq (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)   u8Direction;
    VAR(uint8, AUTOMATIC)   u8LocalChannelId;
	P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)	pudtCancelledNSduId;
	P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)	pudtHandledNSduId;
    u8Direction = CanTp_u8GET_DIRECTION(pudtChannelResources);

    u8LocalChannelId = 
        CanTp_akstreTxNSduPCCfg[pudtChannelResources->udtHandledNSduId].
                                                                u8ChannelNumber;
	pudtCancelledNSduId = &(pudtChannelResources->strTxCancelRequest.udtCancelledNSduId);
	pudtHandledNSduId = &(pudtChannelResources->udtHandledNSduId);

    CanTp_akstreCriticalSections
		[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
													 pfvidEnterCriticalSec002_08();

    /*! \note   Before performing the cancellation, a check shall be performed
                to assure that the transmission operation of the TxNSdu 
                requested for cancellation is still in progress.              \n
                Although when the cancellation request was accepted the
                transmission was still in progress and the cancellation handling
                is performed directly on the next Main function call, but assume
                the folloing case:                                            \n
                1-The Main Function was preempted by the cancellation request
                  of CanTp_CancelTransmit                                     \n
                2-The request was accepted                                    \n
                3-The Main function execution continues and the CanTpConnection
                  was stopped (due to failure, timeout, transmission
                  completeion, etc ..) and its state was set to IDLE          */


    /*! If the transmission operation of the CanTpTxNSdu is still in progress:*/
    if(u8Direction == CanTp_u8DIR_TX)
    {
        if((*pudtCancelledNSduId) == (*pudtHandledNSduId))
        {
            /*! Abort the current transmission, reset the CanTpConnection 
                resources, and notify the upper layer that the cancellation
                request was performed correctly                               */

            /*! \Trace_To   CanTp-CDD-0041(0), CanTp-CDD-0165(0)              */
            /*! \Trace_To   CanTp-CDD-0166(0)                                 */
            vidStopTxChannel(pudtChannelResources, NTFRSLT_E_CANCELATION_OK,
														(*pudtCancelledNSduId));
        }
    }

    CanTp_akstreCriticalSections
		[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
													  pfvidExitCriticalSec002_08();

    /*! If the transmission operation of the CanTpTxNSdu was not in progress, 
        then that means that the transmission operation was stopped (between
        accepting the request and the Main function call) and the upper layer
        was already notified with the notification result
        (Timeout, failure, completeion, etc ..) so there is no need to notify
        the upper layer again with the cancellation request failure           */

    /*! Clear the cancellation request flag to indicate that no cancellation
        request on this CanTpConnection is pending for handling               */
    pudtChannelResources->strTxCancelRequest.bCancellationRequest = FALSE;
}
/******************************************************************************/

LOCAL_INLINE FUNC(void, CANTP_CODE) vidCalculateBlockSize(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pudtChannelResources,    
	VAR(PduIdType, AUTOMATIC)   udtTxNSduId,
    VAR(uint8, AUTOMATIC)       u8ReceivedBlockSize)
{
    VAR(uint16, AUTOMATIC)  u16RemainingMsgLength;
    VAR(uint16, AUTOMATIC)  u16BlockSizeToTxAllData;
    VAR(uint8, AUTOMATIC)   u8ConsecutiveFrameDL;
    
    /*! Get the remaining message length to be transmitted                    */
    u16RemainingMsgLength = pudtChannelResources->u16MessageLength;


    /*! If the addressing format of the CanTpTxNSdu is configured as
        standard addressing then the consecutive frame can hold up to 7 bytes */
    if(CanTp_akstreTxNSduPCCfg[udtTxNSduId].u8TxAddressingFormat
                                                 == CanTp_u8STANDARD_ADDRESSING)
    {
        u8ConsecutiveFrameDL = CanTp_u8STD_CF_DATA_LENGTH;
    }
    /*! If the addressing format of the CanTpTxNSdu is configured as
        extended or mixed addressing then the consecutive frame can hold up to
        6 bytes                                                               */
    else
    {
        u8ConsecutiveFrameDL = CanTp_u8STD_CF_DATA_LENGTH - 1;
    }

    /*! Calculate the number of consecutive frames needed to transmit all the
        remaining data bytes of the message                                   */

    if((u16RemainingMsgLength % u8ConsecutiveFrameDL)==0)
    {
        u16BlockSizeToTxAllData =
                           u16RemainingMsgLength / (uint16)u8ConsecutiveFrameDL;
    }
    else
    {
        u16BlockSizeToTxAllData =
                     (u16RemainingMsgLength / (uint16)u8ConsecutiveFrameDL) + 1;
    }

    /*! \Trace_To   CanTp-CDD-5077(0)                                         */

    /*! If the Block Size received within the flow control frame is equal to 0,
        then all remaining data can be transmitted in successive consecutive
        frames without waiting for a new flow control                         */
    if(u8ReceivedBlockSize==0)
    {
        /*! Set the block size variable of the CanTpConnection resources to the
            number of consecutive frames that need to be transmitted in order to
            transmit all the remaining data bytes of the message              */
        pudtChannelResources->u16BlockSize = u16BlockSizeToTxAllData;
    }
    /*! If the Block Size received within the flow control frame is not equal to
        0, then the number of successive consecutive frames that can be
        transmitted before waiting for a new flow control is limited to the
        block size value received withing the flow control frame              */
    else
    {
        /*! If the receiver can receive a number of successive consecutive that
            are greater than the number of consecutive frames needed to transmit
            all the reamining data bytes of the message:                      */
        if((uint16)u8ReceivedBlockSize > u16BlockSizeToTxAllData)
        {
            /*! Set the block size variable of the CanTpConnection resources to
                the number of consecutive frames that need to be transmitted in
                order to transmit all the remaining data bytes of the message */
            pudtChannelResources->u16BlockSize = u16BlockSizeToTxAllData;
        }
        /*! If the receiver can receive a number of successive consecutive that
            is less than the number of consecutive frames needed to transmit
            all the reamining data bytes of the message:                      */
        else
        {
            /*! Set the block size variable of the CanTpConnection resources to
                the block size value received within the flow control.        \n
                After transmitting this number of consecutive frames, the CanTp
                transmitter shall wait for a new flow control frame from the
                receiver                                                      */
            pudtChannelResources->u16BlockSize = (uint16)u8ReceivedBlockSize;
        }
    }
}

/******************************************************************************/

LOCAL_INLINE FUNC(void, CANTP_CODE) vidCalculateSTmin(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pudtChannelResources,
	VAR(PduIdType, AUTOMATIC)   udtTxNSduId,
    VAR(uint8, AUTOMATIC)       u8ReceivedSTmin)
{
    VAR(uint32, AUTOMATIC)      u32ReceivedSTminInMicro;

    /*! \Trace_To   CanTp-CDD-5078(0)                                         */

    /*! If the STmin value received within the flow control frame is equal to 0,
        then the consecutive frames can be transmitted with the maximum 
        transmission rate which is a frame in each Main function call         */
    if(u8ReceivedSTmin == 0)
    {
        pudtChannelResources->u16STminTimeoutValue = 
                   CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtTxNSduId].u16NCs;
    }
    /*! If the STmin value received within the flow control frame is not equal
        to 0, then the consecutive frames transmission rate will be limited to
        the STmin value received                                              */
    else
    {
        /*! If the STmin value received is between 0 and 127 (the milli-seconds
            range was used), then multiply the value received by 1000 to get
            the time in micro seconds that the CanTp transmitter must wait
            between each 2 consecutive frames                                 */
        if(u8ReceivedSTmin<=127)
        {
            u32ReceivedSTminInMicro = u8ReceivedSTmin * (1000UL);

        }
        /*! If the STmin value received is between 241 and 249 (the 100 micro-
            seconds range was used), then get the corresponding time in micro
            seconds that the CanTp transmitter must wait between each 2 
            consecutive frames                                                */
        else if((u8ReceivedSTmin >=241) && (u8ReceivedSTmin<=249))
        {
            u32ReceivedSTminInMicro = ((uint8)(u8ReceivedSTmin % 240)) * 100UL;
        }
        /*! If the STmin value received is out of the two defined ranges, then
            use the maximum valid STmin value which is 127 milli-seconds      */
        else
        {
            /*! \Trace_To   CanTp-CDD-0283(0)                                 */
            u32ReceivedSTminInMicro = 127000UL;
        }

        /*! Set the u16STminTimeoutValue with the value that when the
            u16TimeoutCounter reaches then the consecutive frame is eligible for
            transmission                                                      */

        if((u32ReceivedSTminInMicro % 
                          CanTp_pkstreGlobalConfig->u32MainFunctionPeriod) == 0)
        {
            
            pudtChannelResources->u16STminTimeoutValue = 
                (uint16)
                (CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtTxNSduId].u16NCs
                - (u32ReceivedSTminInMicro / 
                              CanTp_pkstreGlobalConfig->u32MainFunctionPeriod));
        }
        else
        {
            pudtChannelResources->u16STminTimeoutValue = 
                (uint16)(
                CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtTxNSduId].u16NCs
                - ((u32ReceivedSTminInMicro / 
                        CanTp_pkstreGlobalConfig->u32MainFunctionPeriod) + 1 ));
        }
    }

}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidHandleFCFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)                       u8FlowStatusType;
    VAR(PduIdType, AUTOMATIC)                   udtNSduIdHandled;
    P2CONST(uint8, AUTOMATIC, CANTP_VAR) pku8ReceivedFrame;


    /*! Get the ID of the CanTpTxNSdu that is currently being transmitted     */
    udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

    /*! Assign the local pointer to the address of the local buffer where the
        received flow control is stored                                       */
    pku8ReceivedFrame = pudtChannelResources->au8LocalDataBuffer;

    /*! Get the flow status type out of the first PCI byte                    */
    /*! \Trace_To   CanTp-CDD-5088(0)                                         */
    u8FlowStatusType = pku8ReceivedFrame[CanTp_u8STD_FC_PCI_BYTE] & 
                                                        CanTp_u8FC_FS_TYPE_MASK;

    /*! If the flow status type is "Clear To Send":                           */
    if(u8FlowStatusType == CanTp_u8FC_FS_CTS)
    {
        /*! Call the function responsible for calculating the number of
            successive consecutive frames that will be transmitted by the CanTp
            transmitter before waiting for a new flow control frame           */
        /*! \Trace_To   CanTp-CDD-5089(0)                                     */
        vidCalculateBlockSize(pudtChannelResources,udtNSduIdHandled,
            pku8ReceivedFrame[CanTp_u8STD_FC_PCI_BYTE+1]);

        /*! Call the function responsible for getting the STmin out of the
            flow control frame                                                */
        /*! \Trace_To   CanTp-CDD-5090(0)                                     */
        vidCalculateSTmin(pudtChannelResources, udtNSduIdHandled,
            pku8ReceivedFrame[CanTp_u8STD_FC_PCI_BYTE+2]);

        /*! Set the TimeoutCounter with NCs timeout value                     */
        /*! \Trace_To   CanTp-CDD-5035(0)                                     */
        pudtChannelResources->u16TimeoutCounter = 
          CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtNSduIdHandled].u16NCs;

        /*! If the CanTp will send only 1 consecutive frame before waiting for
            a new flow control, then this consecutive frame shall be considered
            as the last consecutive frame in the block                        \n
            The CanTpConnection state shall be set to
            CanTp_u8TX_REQBUFF_LAST_CF                                        */
        if(pudtChannelResources->u16BlockSize == 1)
        {
            pudtChannelResources->u8ConnectionState = 
                                             CanTp_u8TX_REQBUFF_LAST_CF;
        }
        /*! If the CanTp will send more than 1 consecutive frame before waiting
            for a new flow control, then this consecutive frame shall not be
            considered as the last consecutive frame in the block             \n
            The CanTpConnection state shall be set to
            CanTp_u8TX_REQBUFF_CF                                             */
        else
        {
            pudtChannelResources->u8ConnectionState = 
                                                  CanTp_u8TX_REQBUFF_CF;
        }
       
    }
    /*! If the flow status type is "Wait":                                    */
    else if(u8FlowStatusType == CanTp_u8FC_FS_WAIT)
    {
        /*! Set the TimeoutCounter with NBs timeout value                     */
        /*! \Trace_To   CanTp-CDD-5144(0)                                     */
        pudtChannelResources->u16TimeoutCounter = 
          CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtNSduIdHandled].u16NBs;

        /*! Set the CanTpConnection state to CanTp_u8TX_WAITRX_FC, as the 
            receiver is asking the transmitter not to transmit its consecutive
            frames and to wait till a new flow control is received            */
        pudtChannelResources->u8ConnectionState = CanTp_u8TX_WAITRX_FC;
    }
    else
    {
        /*! If the flow status type is "Overflow":                            */
        if(u8FlowStatusType == CanTp_u8FC_FS_OVFLW)
        {
            /*! Abort the current transmission, reset the CanTpConnection 
                resources, and notify the upper layer that no buffer is
                available at the receiver side                                */
            /*! \Trace_To   CanTp-CDD-0081(0)                                 */
            vidStopTxChannel(pudtChannelResources, NTFRSLT_E_NO_BUFFER,
															udtNSduIdHandled);
        }
        /*! If the flow status type is invalid                                */
        else
        {
            /*! Abort the current transmission, reset the CanTpConnection 
                resources, and notify the upper layer that a flow control frame
                with invalid status was received                              */
            /*! \Trace_To   CanTp-CDD-0082(0)                                 */
            vidStopTxChannel(pudtChannelResources, NTFRSLT_E_INVALID_FS,
															udtNSduIdHandled);
        }
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! \Trace_To   CanTp-CDD-5069(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8MAIN_FUNCTION_ID,
                                                           CANTP_E_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    }
}

/******************************************************************************/

LOCAL_INLINE FUNC(void, CANTP_CODE) vidCheckIfSTminPassed(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    /*! If u16TimeoutCounter reached the value of u16STminTimeoutValue:       */
    if(pudtChannelResources->u16STminTimeoutValue 
                                     == pudtChannelResources->u16TimeoutCounter)
    {
        /*! Set the STmin flag to indicate that STmin time has passed         */
        pudtChannelResources->bSTminPassed = TRUE;
    }
}

/******************************************************************************/

LOCAL_INLINE FUNC(void, CANTP_CODE) vidCalculateNeededBytes (
    P2CONST(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pkstrChannelResources,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8StartByteLocation,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8BytesRemaining,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8BytesToBeProvided)
{
    VAR(uint8, AUTOMATIC)       u8FrameType;
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled;

    /*! Get the type of the frame whose data is going to be requested         */
    u8FrameType = CanTp_u8GET_FRAME_TYPE(pkstrChannelResources);

    /*! Get the ID of the CanTpTxNSdu currently being handled                 */
    udtNSduIdHandled = pkstrChannelResources->udtHandledNSduId;

    switch(u8FrameType)
    {
        /*! If the frame is a single frame                                    */
    case(CanTp_u8FRAME_SF):
        
        /*! The number of data bytes that must to be provided by the upper
            layer for this frame is the total number of bytes of the message  */
        *pu8BytesToBeProvided = 
            (uint8)pkstrChannelResources->u16MessageLength;
    
        /*! If the addressing format of the CanTpTxNSdu is configured as
            standard addressing then the first data byte will be located at 
            the second byte of the single frame                               */
        if(CanTp_akstreTxNSduPCCfg[udtNSduIdHandled].u8TxAddressingFormat == 
                                                    CanTp_u8STANDARD_ADDRESSING)
        {
            *pu8StartByteLocation = CanTp_u8STD_SF_DATA_BYTE;
        }
        /*! If the addressing format of the CanTpTxNSdu is configured as
            extended or mixed addressing then the first data byte will be 
            located at the third byte of the single frame                     */
        else
        {
            *pu8StartByteLocation = (uint8)(CanTp_u8STD_SF_DATA_BYTE + 1);
        }
        /*! The number of data bytes remaining to be provided by the upper
            layer for this frame = The number of bytes that must to be provided
            - the number of bytes already provided on the previous retry and 
            stored in the local buffer                                        */
            
        *pu8BytesRemaining =
            *pu8BytesToBeProvided - pkstrChannelResources->u8BytesInLocalBuffer;

        break;

        /*! If the frame is a first frame                                     */
    case(CanTp_u8FRAME_FF):

        /*! If the addressing format of the CanTpTxNSdu is configured as
            standard addressing then:
            -The first data byte will be located at the third byte of the first
             frame                                                            \n
            -The number of data bytes that must to be provided by the upper 
             layer for this frame is 6 bytes                                  */
        if(CanTp_akstreTxNSduPCCfg[udtNSduIdHandled].u8TxAddressingFormat 
                                                 == CanTp_u8STANDARD_ADDRESSING)
        {
            *pu8BytesToBeProvided = CanTp_u8STD_FF_DATA_LENGTH;
            *pu8StartByteLocation = CanTp_u8STD_FF_DATA_BYTE;
        }
        /*! If the addressing format of the CanTpTxNSdu is configured as
            extended or mixed addressing then:
            -The first data byte will be located at the fourth byte of the first
             frame                                                            \n
            -The number of data bytes that must to be provided by the upper
             layer for this frame is 5 bytes                                  */
        else
        {
            *pu8BytesToBeProvided = CanTp_u8STD_FF_DATA_LENGTH - 1;
            *pu8StartByteLocation = (uint8)(CanTp_u8STD_FF_DATA_BYTE + 1);
        }

        /*! The number of data bytes remaining to be provided by the upper
            layer for this frame = The number of bytes that must to be provided
            - the number of bytes already provided on the previous retry and 
            stored in the local buffer                                        */
        *pu8BytesRemaining = 
            *pu8BytesToBeProvided - pkstrChannelResources->u8BytesInLocalBuffer;

        break;

        /*! If the frame is a consecutive frame or a last consecutive frame   */
    case(CanTp_u8FRAME_CF):
    case(CanTp_u8FRAME_LAST_CF):

        /*! If the addressing format of the CanTpTxNSdu is configured as
            standard addressing:                                              */
        if(CanTp_akstreTxNSduPCCfg[udtNSduIdHandled].u8TxAddressingFormat 
                                                 == CanTp_u8STANDARD_ADDRESSING)
        {
            /*! If the number of the remaining bytes of the message is less than
                or equal to 7 bytes:                                          */
            if(pkstrChannelResources->u16MessageLength
                                          <= (uint16)CanTp_u8STD_CF_DATA_LENGTH)
            {
                /*! The number of data bytes that must be provided by the upper
                    layer is the number of remaining bytes of the message     */
                *pu8BytesToBeProvided = 
                                 (uint8)pkstrChannelResources->u16MessageLength;
            }

            /*! If the number of the remaining bytes of the message is greater
                than 7 bytes:                                                 */

            else
            {
               /*! The number of data bytes that must be provided by the upper
                    layer is 7 bytes                                          */
                *pu8BytesToBeProvided = CanTp_u8STD_CF_DATA_LENGTH;
            }

            /*! The first data byte will be located at the second byte of the
                frame                                                         */
            *pu8StartByteLocation = CanTp_u8STD_CF_DATA_BYTE;
        }

        /*! If the addressing format of the CanTpTxNSdu is configured as
            extended or mixed addressing:                                     */
        else
        {
            /*! If the number of the remaining bytes of the message is less than
                or equal to 6 bytes:                                          */
            if(pkstrChannelResources->u16MessageLength 
                                            <= (CanTp_u8STD_CF_DATA_LENGTH - 1))
            {
                /*! The number of data bytes that must be provided by the upper
                    layer is the number of remaining bytes of the message     */
                *pu8BytesToBeProvided =
                                 (uint8)pkstrChannelResources->u16MessageLength;
            }

            /*! If the number of the remaining bytes of the message is greater
                than 6 bytes:                                                 */
            else
            {
               /*! The number of data bytes that must be provided by the upper
                    layer is 6 bytes                                          */
                *pu8BytesToBeProvided = CanTp_u8STD_CF_DATA_LENGTH - 1;
            }

            /*! The first data byte will be located at the third byte of the
                frame                                                         */
            *pu8StartByteLocation = (uint8)(CanTp_u8STD_CF_DATA_BYTE + 1);
        }

        /*! The number of data bytes remaining to be provided by the upper
            layer for this frame = The number of bytes that must to be provided
            - the number of bytes already provided on the previous retry and 
            stored in the local buffer                                        */
        *pu8BytesRemaining =
            *pu8BytesToBeProvided - pkstrChannelResources->u8BytesInLocalBuffer;

        break;

    default:
        break;
    }

}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidRequestTxBuffer (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)               u8FrameType;
    VAR(BufReq_ReturnType, AUTOMATIC)   udtBufferRequestStatus;
    VAR(PduIdType, AUTOMATIC)           udtNSduIdHandled;
    VAR(PduIdType, AUTOMATIC)           udtUpperLayerId;
    VAR(PduInfoType, AUTOMATIC)         udtPduInfo;
    VAR(PduLengthType, AUTOMATIC)       udtAvailableDataLength;
    VAR(RetryInfoType, AUTOMATIC)       udtPduRRetry;
    VAR(uint8, AUTOMATIC)               u8StartByteLocation = 0;
    VAR(uint8, AUTOMATIC)               u8BytesRemaining = 0;
    VAR(uint8, AUTOMATIC)               u8BytesToBeProvided = 0;

    /*! Get the type of the frame that its data is going to be requested      */
    u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

    /*! Get the ID of the CanTpTxNSdu currently being handled                 */
    udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

    /*! Get the IPduId linked to this CanTpTxNSdu in order to be passed to the
        upper layer callbacks                                                 */
    udtUpperLayerId = 
         CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtNSduIdHandled].udtTxIPduId;

    /*! Set the TpDataState to TP_NORETRY                                     */
    /*! \Trace_To   CanTp-CDD-0073(0)                                         */
    udtPduRRetry.TpDataState = TP_NORETRY;

    /*! Calculate the total number of bytes that must be provided for the frame,
        the number of bytes remaining to be provided, and the location of the
        first data byte within the frame                                      */
    vidCalculateNeededBytes(pudtChannelResources,
                 &u8StartByteLocation, &u8BytesRemaining, &u8BytesToBeProvided);

    /*! Set the SduDataPtr to the address of the byte location where the upper 
        layer shall start coptying its data to                                */
    udtPduInfo.SduDataPtr = 
        &(pudtChannelResources->au8LocalDataBuffer
            [pudtChannelResources->u8BytesInLocalBuffer + u8StartByteLocation]);

    /*! Set the SduLenth to the number of bytes remaining to be provided by the
        upper layer                                                           */
    udtPduInfo.SduLength = (uint16)u8BytesRemaining;
    
    /*! Call the upper layer callback responsible for copying the frame data
        bytes                                                                 */
    /*! \Trace_To   CanTp-CDD-0072(0), CanTp-CDD-5031(0)                      */
    udtBufferRequestStatus = 
        CanTp_udtUPPER_LAYER_TX_COPY(udtUpperLayerId,
                           &udtPduInfo, &udtPduRRetry, &udtAvailableDataLength);

    /*! If the upper layer returns BUFREQ_OK:                                 */
    /*! \Trace_To   CanTp-CDD-0079(0)                                         */
    if(udtBufferRequestStatus == BUFREQ_OK)
    {
        /*! if the upper layer has copied the number of data bytes remaining: */
        if(udtPduInfo.SduLength >= u8BytesRemaining)
        {
            /*! Add the number of the remaining bytes to the number of bytes 
                that were previously provided and stored in the local buffer  */
            pudtChannelResources->u8BytesInLocalBuffer += u8BytesRemaining;
        }
        else
        {
            /*! Add the number of copied bytes to the number of bytes that were
                previously provided and stored in the local buffer            */
            pudtChannelResources->u8BytesInLocalBuffer +=
                                                    (uint8)udtPduInfo.SduLength;
        }

        /*! If the number of bytes that must be provided for this frame is
            currently available in the local buffer:                          */
        if(pudtChannelResources->u8BytesInLocalBuffer >=u8BytesToBeProvided)
        {
            /*! If the frame is a single frame, set CanTpConnection to 
                CanTp_u8TX_TRANSMIT_SF in order to transmit the single frame  */
            if(u8FrameType == CanTp_u8FRAME_SF)
            {
                pudtChannelResources->u8ConnectionState = 
                                                         CanTp_u8TX_TRANSMIT_SF;
            }
            /*! If the frame is a first frame, set CanTpConnection to 
                CanTp_u8TX_TRANSMIT_FF in order to transmit the first frame and
                decrement the number of bytes provided from the total message
                length to be transmitted                                      */
            else if(u8FrameType == CanTp_u8FRAME_FF)
            {
                pudtChannelResources->u8ConnectionState =
                                                         CanTp_u8TX_TRANSMIT_FF;

                pudtChannelResources->u16MessageLength -= u8BytesToBeProvided;
            }
            /*! If the frame is a consecutive frame, set CanTpConnection to 
                CanTp_u8TX_TRANSMIT_CF in order to transmit the consecutive 
                frame and decrement the number of bytes provided from the total
                message length to be transmitted                              */
            else if(u8FrameType == CanTp_u8FRAME_CF)
            {
                pudtChannelResources->u8ConnectionState 
                                                       = CanTp_u8TX_TRANSMIT_CF;

                pudtChannelResources->u16MessageLength -= u8BytesToBeProvided;
            }
            /*! If the frame is a last consecutive frame, set CanTpConnection to
                CanTp_u8TX_TRANSMIT_LAST_CF in order to transmit the last 
                consecutive  frame and decrement the number of bytes provided
                from the total message length to be transmitted               */
            else if(u8FrameType == CanTp_u8FRAME_LAST_CF)
            {
                pudtChannelResources->u8ConnectionState 
                                                  = CanTp_u8TX_TRANSMIT_LAST_CF;

                pudtChannelResources->u16MessageLength -= u8BytesToBeProvided;
            }
            /*! This statement shall not breached                             */
            else
            {
            }
        }
    }
    /*! If the upper layer returns BUFREQ_E_BUSY:                             */
    else if(udtBufferRequestStatus == BUFREQ_E_BUSY)
    {
        /*! Do nothing and wait for the next Main function call to retry      */
        /*! \Trace_To   CanTp-CDD-0076(0)                                     */
    }
    /*! If the upper layer returns a value other than BUFREQ_OK or 
        BUFREQ_E_BUSY:                                                        */
    else
    {
        /*! Abort the current transmission, reset the CanTpConnection 
            resources, and notify the upper layer that the transmission
            operation has failed                                              */
        /*! \Trace_To   CanTp-CDD-0074(0)                                     */
        vidStopTxChannel(pudtChannelResources, NTFRSLT_E_NOT_OK,
                                            udtNSduIdHandled);

#if(CanTp_bDEV_ERROR_DETECT == STD_ON)
        /*! \Trace_To   CanTp-CDD-5165(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8MAIN_FUNCTION_ID, CANTP_E_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    }
}

/******************************************************************************/

LOCAL_INLINE FUNC(void, CANTP_CODE) vidPrepareSingleFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pudtChannelResources,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8Dlc)
{
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled;

    /*! Get the ID of the CanTpTxNSdu currently being handled                 */
    udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

    /*! If the addressing format of the CanTpTxNSdu is configured as
        standard addressing:                                                  */
    if(CanTp_akstreTxNSduPCCfg[udtNSduIdHandled].u8TxAddressingFormat 
                                                 == CanTp_u8STANDARD_ADDRESSING)
    {
        /*! Write the message length at the specified location (low nibble of
            the 1st PCI byte located at the 1st byte of the single frame      */
        /*! \Trace_To   CanTp-CDD-5080(0)                                     */
        pudtChannelResources->au8LocalDataBuffer[CanTp_u8STD_SF_PCI_BYTE] = 
        (uint8)pudtChannelResources->u16MessageLength & CanTp_u8SF_PCI_DL_MASK;
        
        /*! Set the total frame length (message length + 1 PCI byte           */
        *pu8Dlc = 
            (uint8)(pudtChannelResources->u16MessageLength 
                                                    + CanTp_u8SF_NUM_PCI_BYTES);
    }
    /*! If the addressing format of the CanTpTxNSdu is configured as
        extended or mixed addressing:                                         */
    else
    {
        /*! Write the message length at the specified location (low nibble of
            the 1st PCI byte located at the second byte of the single frame   */
        pudtChannelResources->au8LocalDataBuffer[CanTp_u8STD_SF_PCI_BYTE+1] = 
            (uint8)(pudtChannelResources->u16MessageLength) 
                                                       & CanTp_u8SF_PCI_DL_MASK;

        /*! Set the total frame length (message length + 1 PCI byte + 1 byte for
            Target Address in case of extended addressing or Address Extention
            in case of mixed addressing                                       */
        *pu8Dlc = 
            (uint8)(pudtChannelResources->u16MessageLength 
                                                + CanTp_u8SF_NUM_PCI_BYTES + 1);
    }
}

/******************************************************************************/

LOCAL_INLINE FUNC(void, CANTP_CODE) vidPrepareFirstFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pudtChannelResources,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8Dlc)
{
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled;
    VAR(uint16, AUTOMATIC)      u16TotalMsgLength;              
    VAR(uint8, AUTOMATIC)       u8PciFirstByte;
    VAR(uint8, AUTOMATIC)       u8FirstFrameBytes;

    /*! Get the ID of the CanTpTxNSdu currently being handled                 */
    udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;
    
    /*! If the addressing format of the CanTpTxNSdu is configured as
        standard addressing:                                                  */
    if(CanTp_akstreTxNSduPCCfg[udtNSduIdHandled].u8TxAddressingFormat 
                                                 == CanTp_u8STANDARD_ADDRESSING)
    {
        /*! The first PCI byte will be located at the first byte of the frame */
        u8PciFirstByte = CanTp_u8STD_FF_PCI_BYTE;

        /*! The first frame will hold 6 data bytes                            */
        u8FirstFrameBytes = CanTp_u8STD_FF_DATA_LENGTH;
    }
    /*! If the addressing format of the CanTpTxNSdu is configured as
        extended or mixed addressing:                                         */
    else
    {
        /*! The first PCI byte will be located at the second byte of the frame*/
        u8PciFirstByte = CanTp_u8STD_FF_PCI_BYTE + 1;

        /*! The first frame will hold 5 data bytes                            */
        u8FirstFrameBytes = CanTp_u8STD_FF_DATA_LENGTH - 1;
    }

    /*! Write the total message length at the specified location (low nibble of
        the 1st PCI byte in addition to the 2nd PCI byte                      */
    
    /*! \note   The number of first frame data bytes was added to the total
                message length, because this value was decremented from the 
                total message length after being provided from the upper layer*/
    /*! \Trace_To   CanTp-CDD-5072(0)                                         */
    u16TotalMsgLength = 
                     pudtChannelResources->u16MessageLength + u8FirstFrameBytes;

    pudtChannelResources->au8LocalDataBuffer[u8PciFirstByte] = 
        ((uint8)((u16TotalMsgLength & CanTp_u16FF_PCI_DL_H_MASK) >> 8) 
                                                    | (CanTp_u8FF_PCI_ID_MASK));

    pudtChannelResources->au8LocalDataBuffer[u8PciFirstByte + 1] = 
                         (uint8)(u16TotalMsgLength & CanTp_u16FF_PCI_DL_L_MASK);

    /*! Set the total frame length to 8 bytes as the first frame must be 
        transmitted with 8 bytes                                              */
    *pu8Dlc = 8;
}

/******************************************************************************/

LOCAL_INLINE FUNC(void, CANTP_CODE) vidPrepareConsecFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pudtChannelResources,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8Dlc)
{
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled;             
    VAR(uint8, AUTOMATIC)       u8PciByte;
    VAR(uint8, AUTOMATIC)       u8NextSequenceNumber;

    /*! Get the ID of the CanTpTxNSdu currently being handled                 */
    udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

    /*! \Trace_To   CanTp-CDD-5070(0)                                         */

    /*! If the addressing format of the CanTpTxNSdu is configured as
        standard addressing:                                                  */
    if(CanTp_akstreTxNSduPCCfg[udtNSduIdHandled].u8TxAddressingFormat 
                                                 == CanTp_u8STANDARD_ADDRESSING)
    {
        /*! The PCI byte will be located at the first byte of the frame       */
        u8PciByte = CanTp_u8STD_FC_PCI_BYTE;

        /*! Set the total frame length (number of data bytes in local buffer
            + 1 PCI byte)                                                     */
        *pu8Dlc = 
            pudtChannelResources->u8BytesInLocalBuffer 
                                                     + CanTp_u8CF_NUM_PCI_BYTES;
    }
    /*! If the addressing format of the CanTpTxNSdu is configured as
        extended or mixed addressing:                                         */
    else
    {
        /*! The PCI byte will be located at the second byte of the frame      */
        u8PciByte = CanTp_u8STD_FC_PCI_BYTE + 1;

        /*! Set the total frame length (number of data bytes in local buffer
            + 1 PCI byte + 1 byte for Target Address in case of extended 
            addressing or Address Extention in case of mixed addressing       */
        *pu8Dlc = 
            pudtChannelResources->u8BytesInLocalBuffer 
                                                 + CanTp_u8CF_NUM_PCI_BYTES + 1;
    }

    /*! Calculate the sequence number of the consecutive frame to be 
        transmitted                                                           */

    /*! \Trace_To   CanTp-CDD-5082(0), CanTp-CDD-5084(0), CanTp-CDD-5087(0)   */

    /*! If the previous consecutive frame was transmitted with sequence number
        = 15 then reset the sequence number to 0, otherwise increment the
        previous sequence number                                              */
    if(pudtChannelResources->u8SequenceNumber == CanTp_u8CF_MAX_SN)
    {
        pudtChannelResources->u8SequenceNumber = 0;
    }
    else
    {
        pudtChannelResources->u8SequenceNumber++;
    }

    /*! Write the sequence number at the specified location (low nibble of
        the PCI byte of the single frame                                      */
    /*! \Trace_To   CanTp-CDD-5073(0)                                         */
    u8NextSequenceNumber = pudtChannelResources->u8SequenceNumber;

    pudtChannelResources->au8LocalDataBuffer[u8PciByte] = 
        ((u8NextSequenceNumber & CanTp_u8CF_PCI_SN_MASK) 
                                                      | CanTp_u8CF_PCI_ID_MASK);
}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidNextStateAfterTx (
	P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
															pudtChannelResources,    
	VAR(uint8, AUTOMATIC)       u8FrameType,
	VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled)
{

    /*! Set the number of bytes in local buffer to 0 after transmitting the
        frame successfully                                                    */
    pudtChannelResources->u8BytesInLocalBuffer = 0;

    /*! \Trace_To   CanTp-CDD-5016(0)                                         */

    /*! If the transmitted frame is a single frame:                           */
    if(u8FrameType == CanTp_u8FRAME_SF)
    {
        /*! Set the CanTpConnection state to "Waiting for single frame 
            confirmation"                                                     */
        pudtChannelResources->u8ConnectionState = CanTp_u8TX_WAITCONF_SF;
        
    }
    /*! If the transmitted frame is a first frame:                            */
    else if(u8FrameType == CanTp_u8FRAME_FF)
    {
        /*! Set the CanTpConnection state to "Waiting for first frame 
            confirmation"                                                     */
        pudtChannelResources->u8ConnectionState = CanTp_u8TX_WAITCONF_FF;
    }
    /*! If the transmitted frame is a consecutive frame:                      */
    else if(u8FrameType == CanTp_u8FRAME_CF)
    {
        /*! Clear the STmin flag                                              */
        pudtChannelResources->bSTminPassed = FALSE;
        
        /*! Set the CanTpConnection state to "Waiting for consecutive frame 
            confirmation"                                                     */
        pudtChannelResources->u8ConnectionState = CanTp_u8TX_WAITCONF_CF;
    }
    /*! If the transmitted frame is a last consecutive frame in a block:      */
    else if(u8FrameType == CanTp_u8FRAME_LAST_CF)
    {
        /*! Clear the STmin flag                                              */
        pudtChannelResources->bSTminPassed = FALSE;

        /*! Call the function responsible for checking if the last consecutive
            frame in this block is the last consecutive frame in the message,
            then set the LastFrameInMsg flag with the return result           */
        pudtChannelResources->bLastFrameInMsg = 
            CanTp_bIsNextFrameLastInMsg(
                        CanTp_u8DIR_TX, udtNSduIdHandled, pudtChannelResources);

        /*! Set the CanTpConnection state to "Waiting for last consecutive frame
            confirmation"                                                     */
        pudtChannelResources->u8ConnectionState = CanTp_u8TX_WAITCONF_LAST_CF;
    }
    else
    {
    }
}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidTransmitTxFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)           u8FrameType;
    VAR(PduIdType, AUTOMATIC)       udtNSduIdHandled;
    VAR(Std_ReturnType, AUTOMATIC)  udtCanIfTransmitStatus;
    VAR(PduIdType, AUTOMATIC)       udtLowerLayerId;
    VAR(PduInfoType, AUTOMATIC)     udtPduInfo;
    VAR(uint8, AUTOMATIC)           u8TxFrameDlc=0;

    /*! Get the type of the frame that is going to be transmitted             */
    u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

    /*! Get the ID of the CanTpTxNSdu currently being handled                 */
    udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

    /*! Get the LSduId linked to this CanTpTxNSdu in order to be passed to the
        lower layer API                                                       */
    udtLowerLayerId =
         CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtNSduIdHandled].udtTxLSduId;

    /*! If transmission retry is disabled, start preparing the frame directly,
        but if transmission retry is enabled then start preparing the frame only
        of this is the first transmission retry                               */

#if(CanTp_bCANIF_TRANSMIT_RETRY == STD_ON)
    if(pudtChannelResources->bFirstTransmitRetry == TRUE)
    {
#endif  /* CanTp_bCANIF_TRANSMIT_RETRY == STD_ON */

        /* !Deviation : Inhibit MISRA rule [2215]: The indentation is not     */
        /*              consisitent with the configured path because the "if" */
        /*              statement might be switched off using a pre-processor */
        /*              parameter                                             */
        /* PRQA S 2215 ++                                                     */
        switch(u8FrameType)
        /* PRQA S 2215 --                                                     */
        {
            /*! If the frame to be transmitted is a single frame, call the 
                function responsible for preparing single frames              */
        case(CanTp_u8FRAME_SF):
            vidPrepareSingleFrame(pudtChannelResources, &u8TxFrameDlc);
            break;

            /*! If the frame to be transmitted is a firste frame, call the 
                function responsible for preparing first frames               */
        case(CanTp_u8FRAME_FF):
            vidPrepareFirstFrame(pudtChannelResources, &u8TxFrameDlc);
            break;

            /*! If the frame to be transmitted is a consecutive frame or
                a last consecutive frame, call the function responsible for 
                preparing single frames                                       */
        case(CanTp_u8FRAME_CF):
        case(CanTp_u8FRAME_LAST_CF):
            vidPrepareConsecFrame(pudtChannelResources, &u8TxFrameDlc);
            break;

        default:
            break;
        }

        /*! If the addressing format of the CanTpTxNSdu is configured as
            extended addressing:                                              */
        if(CanTp_akstreTxNSduPCCfg[udtNSduIdHandled].u8TxAddressingFormat 
                                                 == CanTp_u8EXTENDED_ADDRESSING)
        {
            /*! Write the Target Address value configured for this CanTpTxNSdu
                at the first byte of the transmitted frame                    */
            /*! \Trace_To   CanTp-CDD-5094(0)                                 */
            pudtChannelResources->au8LocalDataBuffer[0] 
                   = CanTp_akstreTxNSduPCCfg[udtNSduIdHandled].u8NTargetAddress;
        }
        /*! If the addressing format of the CanTpTxNSdu is configured as
            mixed addressing:                                                 */
        else if(CanTp_akstreTxNSduPCCfg[udtNSduIdHandled].u8TxAddressingFormat 
                                                    == CanTp_u8MIXED_ADDRESSING)
        {
            /*! Write the Address Extension value configured for this
                CanTpTxNSdu at the first byte of the transmitted frame        */
            /*! \Trace_To   CanTp-CDD-5096(0)                                 */
            pudtChannelResources->au8LocalDataBuffer[0]
                = CanTp_akstreTxNSduPCCfg[udtNSduIdHandled].u8NAddressExtension;
        }
        /*! If the addressing format of the CanTpTxNSdu is configured as
            standard addressing:                                              */
        else
        {
            /*! Do nothing                                                    */
        }

        /*! If the total frame length is less than 8 bytes and the CanTpTxNSdu
            is configured with padding enabled:                               */
        /*! \Trace_To   CanTp-CDD-5154(0)                                     */
        if((CanTp_akstreTxNSduPCCfg[udtNSduIdHandled].u8TxPaddingActivation == 
                                      CanTp_u8PADDING_ON) && (u8TxFrameDlc < 8))
        {
            /*! Call the function responsible for padding the unused bytes of
                the frame                                                     */
            CanTp_vidPadTxBuffer(u8TxFrameDlc,
                                      pudtChannelResources->au8LocalDataBuffer);

            /*! Set the frame length to 8 bytes                               */
            u8TxFrameDlc = 8;
        }
        
        /*! Set the TimeoutCounter with NAs timeout value                     */
        pudtChannelResources->u16TimeoutCounter =
              CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtNSduIdHandled].u16NAs;

#if(CanTp_bCANIF_TRANSMIT_RETRY == STD_ON)
        /*! If transmission retry is enabled, clear the FirstTransmitRetry flag
            after preparing the frame, in order not to re-prepare the frame
            again if another transmit retry was performed in the next Main
            function call                                                     */
        pudtChannelResources->bFirstTransmitRetry = FALSE;
    }
    /*! If transmission retry is enabled and this is not the first retry, then
        get the frame length that was stored on the first transmission retry  */
    else
    {
        u8TxFrameDlc = pudtChannelResources->u8FrameDlc;
    }
#endif  /* CanTp_bCANIF_TRANSMIT_RETRY == STD_ON */

    /*! Set the SduLength of the PduInfoType structure that will be passed
        to the lower layer with the frame length                              */
    udtPduInfo.SduLength = u8TxFrameDlc;

    /*! Set the SduDataPtr of the PduInfoType structure that will be passed
        to the address of the local buffer                                    */
    udtPduInfo.SduDataPtr = pudtChannelResources->au8LocalDataBuffer;

    /*! Call the lower layer API responsible for frame transmission           */
    udtCanIfTransmitStatus = 
                           CanTp_udtLOWER_LAYER_TX(udtLowerLayerId,&udtPduInfo);

    /*! If the lower layer returns E_OK and the frame was transmitted
        succesfully:                                                          */
    if(udtCanIfTransmitStatus == E_OK)
    {
        /*! Reset the FirstTransmitRetry flag if transmission retry is enabled*/
#if(CanTp_bCANIF_TRANSMIT_RETRY == STD_ON)

        pudtChannelResources->bFirstTransmitRetry = TRUE;

#endif  /* CanTp_bCANIF_TRANSMIT_RETRY == STD_ON */

        /*! Call the function responsible form setting the CanTpConnection 
            state to its next state after a successful frame transmission     */
        vidNextStateAfterTx(pudtChannelResources,u8FrameType,udtNSduIdHandled);
    }
    else
    {
#if(CanTp_bCANIF_TRANSMIT_RETRY == STD_ON)

        /*! If the transmission request was rejected by the lower layer and
            transmission retry is enabled, store the frame length to be used
            on the next retry instead of re-calculating it again              */
        pudtChannelResources->u8FrameDlc = u8TxFrameDlc;
#else
        /*! If the transmission request was rejected by the lower layer and
            transmission retry is disabled:                                   \n
            Abort the current transmission, reset the CanTpConnection resources,
            and notify the upper layer that the transmission operation has 
            failed                                                            */

        vidStopTxChannel(
                      pudtChannelResources, NTFRSLT_E_NOT_OK, udtNSduIdHandled);

#if(CanTp_bDEV_ERROR_DETECT == STD_ON)
        /*! \Trace_To   CanTp-CDD-5166(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8MAIN_FUNCTION_ID, CANTP_E_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */

#endif  /* CanTp_bCANIF_TRANSMIT_RETRY == STD_ON */

    }
}






/******************************************************************************/
/* GLOBAL FUNCTIONS DEFINITION                                                */
/******************************************************************************/

FUNC(Std_ReturnType, CANTP_CODE) CanTp_Transmit(
    VAR(PduIdType, AUTOMATIC) CanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) CanTpTxInfoPtr)
{
    /*! \Trace_To   CanTp-CDD-0036(0)                                         */

    VAR(Std_ReturnType, AUTOMATIC)  udtReturnValue = E_OK;
    VAR(uint16, AUTOMATIC)          u16LocalDataLength;
    VAR(uint16, AUTOMATIC)          u16TxResourcesIndex;
    VAR(uint8, AUTOMATIC)           u8LocalChannelId;
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                    pudtChannelResources;

	P2VAR(uint8, AUTOMATIC,AUTOMATIC)	pu8ConnectionState;
	P2VAR(boolean, AUTOMATIC,AUTOMATIC)	pbUnExpPduReceived;
	P2VAR(boolean, AUTOMATIC,AUTOMATIC)	pbCancellationRequest;
	P2VAR(PduIdType, AUTOMATIC,AUTOMATIC) pudtCancelledNSduId;
    /*! If the service was called while the CanTp is not initialized:         */
    if(CanTp_u8eCanTpGlobalState != CANTP_ON)
    {
        /*! If DET is enabled:                                                */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! Report the corresponding DET error code                           */
        /*! \Trace_To   CanTp-CDD-5009(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8TRANSMIT_ID, CANTP_E_UNINIT);

#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
        /*! \Trace_To   CanTp-CDD-5001(0)                                     */
        udtReturnValue = E_NOT_OK;
    }
    else
    {
        /*! If DET is enabled:                                                */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! Call an internal function resposible for checking DET errors of 
            CanTp_Transmit() API                                              */
        vidCheckTransmitErrors(CanTpTxSduId, CanTpTxInfoPtr, &udtReturnValue);
    }
   
    /*! If no DET errors were detected:                                       */
    if(udtReturnValue == E_OK)
    {

#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */

        /*! Get the index of the CanTpConnection resources -responsible for 
            handling the transmission operations- of the CanTpChannel that 
            the CanTpTxNSdu requested for transmission belongs to             */

        u8LocalChannelId = 
						  CanTp_akstreTxNSduPCCfg[CanTpTxSduId].u8ChannelNumber;

        /*! \Trace_To   CanTp-CDD-5150(0)                                     */
        u16TxResourcesIndex = 
                 CanTp_akstreTpChannels[u8LocalChannelId].u16IndexOfTxResources;

        /*! Assign the local pointer to the address of the CanTpConnection     
            resources                                                         */
        pudtChannelResources =
                             &CanTp_astreChannelsResources[u16TxResourcesIndex];

		pu8ConnectionState = &(pudtChannelResources->u8ConnectionState);
		pbUnExpPduReceived = &(pudtChannelResources->strUnExpectedPdu.bUnExpPduReceived);
		pbCancellationRequest = &(pudtChannelResources->strTxCancelRequest.bCancellationRequest);
		pudtCancelledNSduId = &(pudtChannelResources->strTxCancelRequest.udtCancelledNSduId);

        CanTp_akstreCriticalSections
			[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
													 pfvidEnterCriticalSec001_03();

        /*! Check if the CanTpConnection can handle the requested CanTpTxNSdu \n
            In order for the CanTpConnection to handle the CanTpTxNSdu, the
            following conditions shall be met:
            -The CanTpConnection state is IDLE
            -No un-expected PDU is pending for handling in the next Main
             function (in case of half-duplex channels)
            -No cancellation request for previous transmission -of the same
             CanTpTxNsdu- is still pending for cancellation in the next Main 
             function                                                         */

        /*! \Trace_To   CanTp-CDD-5151(0), CanTp-CDD-0107(0)                  */
        /*! \Trace_To   CanTp-CDD-0159(0)                                     */
        if(((*pu8ConnectionState) == CanTp_u8IDLE_STATE)
            && ((*pbUnExpPduReceived) != TRUE)
            && (((*pbCancellationRequest) == FALSE) ||
                ((*pudtCancelledNSduId) != CanTpTxSduId)))
        {
            /*! Get the length of the requested CanTpTxNSdu in a local 
                variable                                                      */
            /*! \Trace_To   CanTp-CDD-0069(0), CanTp-CDD-0161(0)              */
            u16LocalDataLength = CanTpTxInfoPtr->SduLength;

            /*! \Trace_To   CanTp-CDD-0155(0), CanTp-CDD-0156(0)              */

            /*! If the addressing format of the CanTpTxNSdu is configured as
                standard addressing then the max. number of bytes that can be
                transmitted in a single frame are 7 bytes                     */
            if(CanTp_akstreTxNSduPCCfg[CanTpTxSduId].u8TxAddressingFormat 
                                                 == CanTp_u8STANDARD_ADDRESSING)
            {
                /*! \Trace_To   CanTp-CDD-5030(0)                             */

                /*! If the message length is less than or equal to 7 bytes:   */
                if(u16LocalDataLength <= (uint16)CanTp_u8STD_SF_DATA_LENGTH)
                {
                    /*! Start a single frame transmission operation by setting
                        the CanTpConnection state to CanTp_u8TX_REQBUFF_SF    */
                    *pu8ConnectionState = CanTp_u8TX_REQBUFF_SF;
                }
                /*! If the message length is greater than 7 bytes:            */
                else
                {
                    /*! Start a multiple frame transmission operation by setting
                        the CanTpConnection state to CanTp_u8TX_REQBUFF_FF    */
                    *pu8ConnectionState = CanTp_u8TX_REQBUFF_FF;
                }
            }
            /*! If the addressing format of the CanTpTxNSdu is configured as
                extended or mixed addressing then the max. number of bytes that
                can be transmitted in a single frame are 6 bytes              */
            else
            {
                /*! If the message length is less than or equal to 6 bytes:   */
                if(u16LocalDataLength 
                                    <= (uint16)(CanTp_u8STD_SF_DATA_LENGTH - 1))
                {
                    /*! Start a single frame transmission operation by setting
                        the CanTpConnection state to CanTp_u8TX_REQBUFF_SF    */
                    *pu8ConnectionState = CanTp_u8TX_REQBUFF_SF;
                }
                else
                {
                    /*! Start a multiple frame transmission operation by setting
                        the CanTpConnection state to CanTp_u8TX_REQBUFF_FF    */
                    *pu8ConnectionState = CanTp_u8TX_REQBUFF_FF;
                }
            }

            CanTp_akstreCriticalSections
				[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
													  pfvidExitCriticalSec001_03();

            /*! Save the TxNSduId that is currently being handled on the 
                CanTpConnection                                               */
            pudtChannelResources->udtHandledNSduId = CanTpTxSduId;

            /*! Save the total meesage length                                 */
            pudtChannelResources->u16MessageLength = u16LocalDataLength;

            /*! Set the TimeoutCounter with NCs timeout value                 */
            /*! \note   An additional cycle was added to the timeout value
                        because the request is issued from an API context while
                        the timout calculations and handling is performed in the
                        Main function call                                    */
            /*! \Trace_To   CanTp-CDD-5032(0)                                 */
            pudtChannelResources->u16TimeoutCounter = 
                CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[CanTpTxSduId].u16NCs 
                                                                            + 1;
        }
        /*! If any DET error was detected:                                    */
        else
        {
            /*! Return E_NOT_OK                                               */
            udtReturnValue = E_NOT_OK;
        }
    }


    return (udtReturnValue);
}

/******************************************************************************/

FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelTransmit(
    VAR(PduIdType, AUTOMATIC) CanTpTxSduId)
{
    VAR(Std_ReturnType, AUTOMATIC)  udtReturnValue = E_NOT_OK;
    VAR(uint8, AUTOMATIC)           u8Direction;
    VAR(uint8, AUTOMATIC)           u8FrameType;
    VAR(uint16, AUTOMATIC)          u16IndexOfResources;
    VAR(boolean, AUTOMATIC)         bCancelTxEnabled;
    VAR(boolean, AUTOMATIC)         bLastFrame;
    VAR(PduIdType, AUTOMATIC)       udtNSduIdHandled;
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                    pudtChannelResources;


    /*! If the service was called while the CanTp is not initialized:         */
    /*! \Trace_To   CanTp-CDD-5002(0)                                         */
    if(CanTp_u8eCanTpGlobalState != CANTP_ON)
    {
        /*! If DET is enabled:                                                */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! Report the corresponding DET error code                           */
        /*! \Trace_To   CanTp-CDD-5010(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8CANCEL_TANSMIT_ID, CANTP_E_UNINIT);

#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    }

#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

    /*! If an invalid TxNSduId is received                                    */
    else if(CanTpTxSduId >= CanTp_u16NUM_OF_TX_NSDUS)
    {
        /*! Report the corresponding DET error code                           */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8CANCEL_TANSMIT_ID, CANTP_E_PARAM_ID);
    }
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    else
    {
        /*! If no DET errors were detected:                                   */

        /*! Get the index of the CanTpConnection resources -responsible for 
            handling the transmission operations- of the CanTpChannel that 
            the CanTpTxNSdu requested for transmission cancellation belongs to*/
        u16IndexOfResources = 
            CanTp_akstreTpChannels[CanTp_akstreTxNSduPCCfg[CanTpTxSduId]
                                        .u8ChannelNumber].u16IndexOfTxResources;

        /*! Assign the local pointer to the address of the CanTpConnection     
            resources                                                         */
        pudtChannelResources = 
                             &CanTp_astreChannelsResources[u16IndexOfResources];

        /*! Get the current direction of the CanTpConnection                  */
        u8Direction = CanTp_u8GET_DIRECTION(pudtChannelResources);

        /*! Get the type of the frame bing handled on the CanTpConnection     */
        u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

        /*! Get the NSduId of the NSdu currently being handled on the 
            CanTpConnection                                                   */
        udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

        /*! \Trace_To   CanTp-CDD-0164(0)                                     */

        /*! Check whether the cancellation can be performed or not            \n
            In order to perform the cancellation, the following conditions
            shall be met:                                                     \n
            -The CanTpConnection must be already performing a transmission 
             operation for the same CanTpTxNSdu requested for cancellation    \n
            -No previous cancellation request on this CanTpConnection is still
             pending to be handled in the next Main function (This scenario can
             happen only if 2 or more successive cancellation requests are 
             received between 2 Main function calls                           */
        if((u8Direction == CanTp_u8DIR_TX)
            &&
            (udtNSduIdHandled == CanTpTxSduId)
            &&
            (pudtChannelResources->strTxCancelRequest.bCancellationRequest !=
                                                                          TRUE))
        {
            bCancelTxEnabled =
                    CanTp_akstreTxNSduPCCfg[CanTpTxSduId].bTransmitCancellation;
            
            bLastFrame = pudtChannelResources->bLastFrameInMsg;

            /*! Check whether the cancellation request can be accepted or not \n
                In order to accept the cancellation request, the following
                conditions shall be met:                                      \n
                -The CanTpTxNSdu must be configured with Cancellation Enabled \n
                -A multiple frame transmission operation is currently taking
                 place for this CanTpTxNSdu and not a single frame transmission
                 operation                                                    \n
                -The last consecutive frame in the message was not yet
                 transmitted                                                  */

            /*! If the cancellation request can be accepted:                  */
            if((bCancelTxEnabled == TRUE)
                && (u8FrameType != CanTp_u8FRAME_SF) 
                && ((u8FrameType != CanTp_u8FRAME_LAST_CF) || 
                                                          (bLastFrame != TRUE)))
            {
                /*! Set the cancellation request flag to indicate that a 
                    cancellation request was requested and accepted on this
                    CanTpConnection, in order to handle it in the next Main
                    function                                                  */

                /*! \Trace_To   CanTp-CDD-5135(0)                             */
                pudtChannelResources->strTxCancelRequest.bCancellationRequest = 
                                                                           TRUE;
                
                /*! Save the ID of the TxNSdu to be cancelled                 */
                pudtChannelResources->strTxCancelRequest.udtCancelledNSduId =
                                                                   CanTpTxSduId;
                
                /*! Return E_OK to notify the upper layer that the request was
                    accepted and will be handled in the Main function         */
                udtReturnValue = E_OK;
            }

            /*! If the cancellation request can not be accepted return 
                E_NOT_OK                                                      */
        }
        else
        {
            /*! If the cancellation can not be performed:                     */

            /*! If DET is enabled:                                            */
            /*! Report the corresponding DET error code then return E_NOT_OK  */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)
            CanTp_vidREPORT_DET_ERROR(CanTp_u8CANCEL_TANSMIT_ID,
                                                    CANTP_E_OPER_NOT_SUPPORTED);
#endif            
        }
    }
    return udtReturnValue;
}

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_vidManageTxState (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)   u8FrameType;

    /*! If a cancellation request is pending to be handled                    */
    if(pudtChannelResources->strTxCancelRequest.bCancellationRequest == TRUE)
    {
        /*! Call the function resposible for handling a cancellation request  */

        /*! \Trace_To   CanTp-CDD-5136(0)                                     */
        vidHandleTxCancelReq(pudtChannelResources);
    }

    /*! If the CanTpConnection is currently handling a transmission   
        operation:                                                            */
    if((CanTp_u8GET_DIRECTION(pudtChannelResources)) == CanTp_u8DIR_TX)
    {
        /*! If the CanTpConnection state is CanTp_u8TX_HANDLE_FC, then call the
            function responsible for handling the flow control frame that was
            received and stored in the local buffer till the next Main function
            call                                                              */
        if(pudtChannelResources->u8ConnectionState == CanTp_u8TX_HANDLE_FC)
        {
            vidHandleFCFrame(pudtChannelResources);
        }


        /*! If the CanTpConnection is handling a consecutive frame or a last 
            consecutive frame, and the state is either CanTp_u8OPERATION_REQBUFF
            (requesting frame data from the upper layer) or 
            CanTp_u8OPERATION_TRANSMIT (frame data was provided by the upper 
            layer) and ready for transmission:                                */
        if((CanTp_u8GET_OPERATION(pudtChannelResources) 
                                                   == CanTp_u8OPERATION_REQBUFF)
            ||
            (CanTp_u8GET_OPERATION(pudtChannelResources) 
                                                 == CanTp_u8OPERATION_TRANSMIT))
        {
            u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

            if(((u8FrameType == CanTp_u8FRAME_CF) || 
                (u8FrameType == CanTp_u8FRAME_LAST_CF)) && 
                (pudtChannelResources->bSTminPassed == FALSE) )
            {
                /*! Call the function responsible for checking whether STmin
                    time has passed or not, so that the consecutive frame
                    can be transmitted                                        */
                vidCheckIfSTminPassed(pudtChannelResources);
            }
        }

        /*! If CanTpConnection state is CanTp_u8OPERATION_REQBUFF (requesting 
            frame data from the upper layer for SF, FF, or CF:                */
        if(CanTp_u8GET_OPERATION(pudtChannelResources) == 
                                                      CanTp_u8OPERATION_REQBUFF)
        {
            /*! Call the function responsible for requesting the frame data
                from the upper layer                                          */
            vidRequestTxBuffer(pudtChannelResources);
        }
        
        /*! If CanTpConnection state is CanTp_u8OPERATION_TRANSMIT (frame data
            were provided by the upper layer and the frame is ready for 
            transmissoin)                                                     */
        if(CanTp_u8GET_OPERATION(pudtChannelResources) 
                                                  == CanTp_u8OPERATION_TRANSMIT)
        {
            u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

            /*! If the frame is a single frame or a first frame then proceed to
                transmit the frame. While if the frame is a consecutive frame
                or a last consecutive frame then the STmin flag shall be checked
                before proceeding to frame transmission                       */
            if(((u8FrameType != CanTp_u8FRAME_CF) 
                                      && (u8FrameType != CanTp_u8FRAME_LAST_CF))
                ||
                (pudtChannelResources->bSTminPassed == TRUE))
            {
                vidTransmitTxFrame(pudtChannelResources);
            }
        }
    }
}

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_vidHandleTxTimeout (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)               u8Operation;
    VAR(PduIdType, AUTOMATIC)           udtNSduIdHandled;
    VAR(NotifResultType, AUTOMATIC)     udtErrorType;

    /*! Get the current transmission operation taking place on 
        this CanTpConnection                                                  */
    u8Operation = CanTp_u8GET_OPERATION(pudtChannelResources);

    /*! Get the ID of the CanTpTxNSdu currently being handled                 */
    udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

    switch(u8Operation)
    {
        /*! If the timeout occurred while trying to get a frame data bytes:   */
        /*! \Trace_To   CanTp-CDD-5034(0)                                     */
    case(CanTp_u8OPERATION_REQBUFF):
        /*! Report NTFRSLT_E_NOT_OK to the upper layer                        */
        /*! \Trace_To   CanTp-CDD-0078(0)                                     */
        udtErrorType = NTFRSLT_E_NOT_OK;
        break;

        /*! If the timeout occurred while waiting for a frame
            transmission confirmation, or if the timeout occurred while trying
            to re-transmit the rejected frame (only if transmission retry is
            enabled):                                                         */
        /*! \Trace_To   CanTp-CDD-0080(0), CanTp-CDD-5018(0)                  */
    case(CanTp_u8OPERATION_WAITCONF):
#if(CanTp_bCANIF_TRANSMIT_RETRY == STD_ON)
    case(CanTp_u8OPERATION_TRANSMIT):
#endif  /* CanTp_bCANIF_TRANSMIT_RETRY == STD_ON */

        /*! Report NTFRSLT_E_TIMEOUT_A to the upper layer to indicate that NAs 
            timeout has occurred                                              */
        udtErrorType = NTFRSLT_E_TIMEOUT_A;
        break;

        /*! If the timeout occurred while waiting for flow control reception: */
    case(CanTp_u8OPERATION_WAITRX):
        /*! Report NTFRSLT_E_TIMEOUT_BS to the upper layer to indicate that NBs 
            timeout has occurred                                              */
        /*! \Trace_To   CanTp-CDD-0084(0)                                     */
        udtErrorType = NTFRSLT_E_TIMEOUT_BS;
        break;

    default:
        udtErrorType = NTFRSLT_E_NOT_OK;
        break;
    }

    /*! Abort the current transmission, reset the CanTpConnection 
        resources, and notify the upper layer with the corresponding abortion
        reason                                                                */
    vidStopTxChannel(pudtChannelResources, udtErrorType, udtNSduIdHandled);

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
    /*! \Trace_To   CanTp-CDD-5062(0), CanTp-CDD-5063(0), CanTp-CDD-5064(0)   */
    CanTp_vidREPORT_DET_ERROR(CanTp_u8MAIN_FUNCTION_ID, CANTP_E_TX_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
}


/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_vidStoreFCFrame (
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)pkudtPduInfoPtr,
	VAR(PduIdType, AUTOMATIC) udtTxNSduId)
{
    VAR(uint16, AUTOMATIC)      u16IndexOfResources;
    VAR(uint8, AUTOMATIC)       u8PciFirstByteLocation;
    VAR(uint8, AUTOMATIC)       u8ReceivedFrameLen;
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pudtChannelResources;

    /*! Get the index of the CanTpConnection resources -responsible for 
        handling the transmission operations- of the CanTpChannel that 
        the CanTpTxNSdu belongs to                                            */
    u16IndexOfResources = 
        CanTp_akstreTpChannels[CanTp_akstreTxNSduPCCfg[udtTxNSduId].
                                         u8ChannelNumber].u16IndexOfTxResources;

    /*! Assign the local pointer to the address of the CanTpConnection 
        resources                                                             */
    pudtChannelResources = &CanTp_astreChannelsResources[u16IndexOfResources];

    /*! Get the length of the flow control frame received                     */
    u8ReceivedFrameLen = (uint8)pkudtPduInfoPtr->SduLength;

    /*! If the CanTpConnection state is waiting for flow control reception, and
        the CanTpConnection is already handling the same TxNSdu as the one to
        which the received flow control belongs:                              */
    /*! \Trace_To   CanTp-CDD-5037(0), CanTp-CDD-5044(0)                      */
    if((pudtChannelResources->u8ConnectionState == CanTp_u8TX_WAITRX_FC)
        && (pudtChannelResources->udtHandledNSduId == udtTxNSduId))
    {
        /*! If the addressing format of the CanTpTxNSdu is configured as
            standard addressing:                                              */
        if(CanTp_akstreTxNSduPCCfg[udtTxNSduId].u8TxAddressingFormat 
                                             == CanTp_u8STANDARD_ADDRESSING)
        {
            /*! The first PCI byte is located at the first byte of the frame  */
            u8PciFirstByteLocation = CanTp_u8STD_FC_PCI_BYTE;
        }
        /*! If the addressing format of the CanTpTxNSdu is configured as
            extended or mixed addressing:                                     */
        else
        {
            /*! The first PCI byte is located at the second byte of the frame */
            u8PciFirstByteLocation = CanTp_u8STD_FC_PCI_BYTE + 1;
        }

        /*! If the flow control frame is received with an invalid length, then
            it will be ignored.                                               \n
            The flow control length is considered as invalid if:              \n
            -If Padding is enabled for this CanTpTxNSdu and the length is not
             equal to 8 bytes                                                 \n
            -If Padding is diabled and standard addressing is used for this 
             CanTpTxNSdu, and the length is not equal to 3 bytes              \n
            -If Padding is diabled and exttended or mixed addressing is used
             for this CanTpTxNSdu, and the length is not equal to 4 bytes     */

        /*! \Trace_To   CanTp-CDD-5155(0)                                     */

        if( ((CanTp_akstreTxNSduPCCfg[udtTxNSduId].u8TxPaddingActivation 
                            == CanTp_u8PADDING_ON) && (u8ReceivedFrameLen != 8))
            ||
            ((CanTp_akstreTxNSduPCCfg[udtTxNSduId].u8TxPaddingActivation 
                        == CanTp_u8PADDING_OFF)    && 
                          (u8ReceivedFrameLen != (u8PciFirstByteLocation + 3))))
        {
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)
        CanTp_vidREPORT_DET_ERROR(CanTp_u8RX_INDICATION_ID,
                                                 CANTP_E_INVALID_RX_LENGTH);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
        
        }
    
        else
        {
            /*! If the flow control frame is received with valid length:      */

            /*! Copy the received PCI bytes to the local buffer in order to be
                handled in the next Main function call                        */
            CanTp_vidMemoryCopy(
                &(pkudtPduInfoPtr->SduDataPtr[u8PciFirstByteLocation]),
                                pudtChannelResources->au8LocalDataBuffer,
                                                      CanTp_u8FC_NUM_PCI_BYTES);

            /*! Set the CanTpConnection state to CanTp_u8TX_HANDLE_FC, in
                order to ignore any un-expected flow control PDUs received    */
            pudtChannelResources->u8ConnectionState = CanTp_u8TX_HANDLE_FC;
        }

    }
}

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_vidConfHandlerTx (
    VAR(PduIdType, AUTOMATIC) udtNSduId)
{
    /*! \Trace_To   CanTp-CDD-0282(0)                                         */

    VAR(uint8, AUTOMATIC)               u8FrameType;
    VAR(uint16, AUTOMATIC)              u16IndexOfResources;
    
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pudtChannelResources;

    /*! Get the index of the CanTpConnection resources -responsible for 
        handling the transmission operations- of the CanTpChannel that 
        the CanTpTxNSdu belongs to                                            */
    u16IndexOfResources = 
        CanTp_akstreTpChannels[CanTp_akstreTxNSduPCCfg[udtNSduId].
                                         u8ChannelNumber].u16IndexOfTxResources;

    /*! Assign the local pointer to the address of the CanTpConnection 
        resources                                                             */
    pudtChannelResources = &CanTp_astreChannelsResources[u16IndexOfResources];

    /*! \Trace_To   CanTp-CDD-5022(0)                                         */

    /*! Get the frame type                                                    */
    u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

    switch(u8FrameType)
    {
        /*! If a transmission confirmation is received for the transmitted
            single frame                                                      */
    case(CanTp_u8FRAME_SF):
        /*! Notify the upper layer with transmission success and re-initialize
            the CanTpConnection resources                                     */
        /*! \Trace_To   CanTp-CDD-5147(0)                                     */
        vidStopTxChannel(pudtChannelResources, NTFRSLT_OK, udtNSduId);
        break;

        /*! If a transmission confirmation is received for the transmitted
            first frame                                                       */
    case(CanTp_u8FRAME_FF):
        /*! Set the CanTpConnection state to "Waiting for flow control 
            reception"                                                        */
        pudtChannelResources->u8ConnectionState = CanTp_u8TX_WAITRX_FC;

        /*! Set the TimeoutCounter with NBs timeout value                     */
        /*! \note   An additional cycle was added to the timeout value because
                    the confirmation is received in CanTp_TxConfirmation
                    context while the timout calculations and handling is
                    performed in the Main function call                       */
        /*! \Trace_To   CanTp-CDD-5145(0)                                     */
        pudtChannelResources->u16TimeoutCounter = 
                 CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtNSduId].u16NBs + 1;
        break;

        /*! If a transmission confirmation is received for the transmitted
            consecutive frame                                                 */
    case(CanTp_u8FRAME_CF):

        /*! Decrement the number of consecutive frames remaining to be 
            transmitted in the current block                                  */
        pudtChannelResources->u16BlockSize--;

        /*! If only one consecutive frame is remaining to be transmitted in the
            current block:                                                    */
        if(pudtChannelResources->u16BlockSize == 1)
        {
            /*! Set the CanTpConnection state to CanTp_u8TX_REQBUFF_LAST_CF   */
            pudtChannelResources->u8ConnectionState = 
                                                     CanTp_u8TX_REQBUFF_LAST_CF;
        }
        /*! If more than one consecutive frame is remaining to be transmitted
            in the current block:                                             */
        else
        {
            /*! Set the CanTpConnection state to CanTp_u8TX_REQBUFF_CF        */
            pudtChannelResources->u8ConnectionState =
                                                          CanTp_u8TX_REQBUFF_CF;
        }

        

        /*! Set the TimeoutCounter with NCs timeout value                     */
        /*! \note   An additional cycle was added to the timeout value because
                    the confirmation is received in CanTp_TxConfirmation
                    context while the timout calculations and handling is
                    performed in the Main function call                       */
        pudtChannelResources->u16TimeoutCounter = 
                 CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtNSduId].u16NCs + 1;
        break;
    
        /*! If a transmission confirmation is received for the transmitted
            last consecutive frame                                            */
    case(CanTp_u8FRAME_LAST_CF):

        /*! If the transmitted last consecutive frame is the last frame in the
            message:                                                          */
        if(pudtChannelResources->u16MessageLength==0)
        {
            /*! Notify the upper layer with transmission success and 
                re-initialize the CanTpConnection resources                   */
            /*! \Trace_To   CanTp-CDD-5148(0)                                 */
            vidStopTxChannel(pudtChannelResources, NTFRSLT_OK, udtNSduId);
        }
        /*! If the transmitted last consecutive frame is not the last frame in 
            the message:                                                      */
        else
        {
        /*! Set the TimeoutCounter with NBs timeout value                     */
        /*! \note   An additional cycle was added to the timeout value because
                    the confirmation is received in ISR context while the
                    timout calculations and handling is performed in the
                    Main function call                                        */
            /*! \Trace_To   CanTp-CDD-5146(0)                                 */
            pudtChannelResources->u16TimeoutCounter = 
                 CanTp_pkstreGlobalConfig->pkstrTxNSduCfg[udtNSduId].u16NBs + 1;

            /*! Set the CanTpConnection state to CanTp_u8TX_WAITRX_FC and wait
                for a new flow control before starting to transmit the new
                block                                                         */
            pudtChannelResources->u8ConnectionState = CanTp_u8TX_WAITRX_FC;
        }
        break;

    default:
        break;
    }
}

#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/* PRQA L:L1                                                                  */
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
/* !File            : CanTp_Reception.c                                       */
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
/* $Revision::   1.16     $$Author::   AELSOHBY       $$Date::   Jun 25 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp_Reception.c
*
* \par
*   This file contains the implementation of the Reception sub-component.     \n
    The Reception sub-component contains all the services needed to perfrom
    an RxNSdu reception operation.                                            */
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
#include "CanTp_Reception.h"
#include "CanTp.h"


/******************************************************************************/
/* LOCAL FUNCTIONS DECLARATION                                                */
/******************************************************************************/

#define CANTP_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************/
/*! \Description    This function stops and re-initializes a CanTpConnection
                    resources after reception, and notifies the upper layer
                    with the reception result                                 \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            transmission operation is taking 
                                            place                             \n
    \param[in]      udtRxNSduId             CanTpRxNSduId that was being 
                                            handled                           \n
                    \Range                  0 .. CanTp_u16NUM_OF_RX_NSDUS-1   \n
    \param[in]      udtResult               Reception result                  \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidStopRxChannel(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                    pudtChannelResources,
    VAR(PduIdType, AUTOMATIC)       udtRxNSduId,
    VAR(NotifResultType, AUTOMATIC) udtResult);


/******************************************************************************/
/*! \Description    This function handles reception cancellation requests     \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking
                                            place                             \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidHandleRxCancelReq (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function handles consecutive frame reception errors  \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking
                                            place                             \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidHandleCFRxError (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function handles the reception of unexpected PDUs    \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking
                                            place                             \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidHandleUnExpectedPdus (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function calculates the number of data bytes that the
                    frame is holding according to its type                    \n
    \param[in]      pkstrChannelResources   A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking 
                                            place                             \n
    \param[in]      udtRxNSduId             CanTpRxNSduId that is being
                                            handled                           \n
                    \Range                  0 .. CanTp_u16NUM_OF_RX_NSDUS-1   \n
    \param[in]      u8FrameType             Type of the frame that is being
                                            handled                           \n
*******************************************************************************/
LOCAL_INLINE FUNC(uint8, CANTP_CODE) u8NumOfBytesInRxFrame (
    P2CONST(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pkstrChannelResources,
    VAR(PduIdType, AUTOMATIC)   udtRxNSduId,
    VAR(uint8, AUTOMATIC)       u8FrameType);


/******************************************************************************/
/*! \Description    This function notifies the upper layer with the start of
                    new reception and its length by calling the StartOfReception
                    callback                                                  \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking 
                                            place                             \n
    \param[in]      udtNSduIdHandled        CanTpRxNSduId that is being
                                            handled                           \n
                    \Range                  0 .. CanTp_u16NUM_OF_RX_NSDUS-1   \n
    \param[in]      u8FrameType             Type of the frame that is being
                                            handled                           \n
    \return         Request Result:                                           \n
                    TRUE:                   The buffer was allocated 
                                            (StartOfReception returned
                                            BUFREQ_OK)                        \n
                    FALSE:                  The buffer was not allocated 
                                            (StartOfReception didn't return
                                            BUFREQ_OK)                        \n
*******************************************************************************/
static FUNC(boolean, CANTP_CODE) bProvideRxBuffer(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                pudtChannelResources,
    VAR(PduIdType, AUTOMATIC)                   udtNSduIdHandled,
    VAR(uint8, AUTOMATIC)                       u8FrameType,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC)  pudtAvailableDataLength);


/******************************************************************************/
/*! \Description    This function calls the upper layer callback that returns
                    the available buffer size                                 \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking 
                                            place                             \n
    \param[in]      udtNSduIdHandled        CanTpRxNSduId that is being
                                            handled                           \n
                    \Range                  0 .. CanTp_u16NUM_OF_RX_NSDUS-1   \n
    \param[out]     pudtAvailableDataLength The number of bytes available in the
                                            upper layer buffer                \n
    \return         Request Result:                                           \n
                    TRUE:                   The upper layer has got at least 1
                                            byte available in its buffer      \n
                    FALSE:                  The upper layer has no buffer 
                                            available                         \n
*******************************************************************************/
static FUNC(boolean, CANTP_CODE) bCheckBufferSize(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                pudtChannelResources,
    VAR(PduIdType, AUTOMATIC)                   udtNSduIdHandled,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC)  pudtAvailableDataLength);



/******************************************************************************/
/*! \Description    This function checks if the reception operation was
                    completed successfully and notifies the upper layer       \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking 
                                            place                             \n
    \param[in]      u8FrameType             Type of the frame that is being
                                            handled                           \n
    \param[in]      udtNSduIdHandled        CanTpRxNSduId that is being
                                            handled                           \n
                    \Range                  0 .. CanTp_u16NUM_OF_RX_NSDUS-1   \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidHandleRxCompletion (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pudtChannelResources,
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled,
	VAR(uint8, AUTOMATIC)       u8FrameType);


/******************************************************************************/
/*! \Description    This function checks the buffer size of the next block of
                    frames, and calculates the block size value that will be
                    transmitted in the next flow control frame                \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking 
                                            place                             \n
    \param[in]      udtNSduIdHandled        CanTpRxNSduId that is being
                                            handled                           \n
                    \Range                  0 .. CanTp_u16NUM_OF_RX_NSDUS-1   \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidCheckNextBlockBuffer (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pudtChannelResources,
    VAR(PduIdType, AUTOMATIC)   udtRxNSduId);


/******************************************************************************/
/*! \Description    This function requests buffer for single frame, first
                    frame, or last consecutive frame data. In addition to that,
                    this service checks if sufficient buffer is available in
                    the upper layer to hold the next block of data            \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking 
                                            place                             \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidRequestRxBuffer (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function checks if a wait flow control shall be
                    transmitted or not                                        \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking 
                                            place                             \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidCheckFcWaitTransmit(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function prepares the PCI bytes of the flow control
                    frame                                                     \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking 
                                            place                             \n
    \param[out]     pu8DataBuffer           Pointer to the local buffer where
                                            the flow control is stored        \n
    \param[out]     pu8FrameDlc             Pointer to the variable holding
                                            the data length code of the flow
                                            control frame                     \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidPrepareFCFrame (
    P2CONST(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pkstrChannelResources,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8DataBuffer,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8FrameDlc);


/******************************************************************************/
/*! \Description    This function transmits a flow control frame to the lower
                    layer                                                     \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking 
                                            place                             \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidTransmitFCFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function transmits a flow control frame to the lower
                    layer                                                     \n
    \param[in]      udtRxNSduId             CanTpRxNSduId that is being
                                            handled                           \n
                    \Range                  0 .. CanTp_u16NUM_OF_RX_NSDUS-1   \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking 
                                            place                             \n
    \param[in]      u8PciByteLocation       Location of the PCI byte in the
                                            frame                             \n
    \param[in]      pudtPduInfoPtr          A pointer to a structure that
                                            contains the received data and its
                                            length                            \n
    \return         Error Check Result:                                       \n
                    TRUE:                   No errors were found, proceed to
                                            handle the consecutive frame      \n
                    FALSE:                  An error was found, don't proceed
                                            to handle the consecutive frame   \n
*******************************************************************************/
static FUNC(boolean, AUTOMATIC) bCheckCFErrors (
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)      pudtPduInfoPtr,
    VAR(PduIdType, AUTOMATIC)                           udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                        pudtChannelResources,
    VAR(uint8, AUTOMATIC)                               u8PciByteLocation);

/******************************************************************************/
/*! \Description    This function is responsible for providing the consecutive
                    frame data bytes to the upper layer                       \n
    \param[in]      pu8CFData               Pointer to the start address of the
                                            consecutive frame data            \n
    \param[in]      u8CFLength              Number of consecutive frame data
                                            bytes                             \n
    \param[in]      udtRxNSduId             CanTpRxNSduId that is being
                                            handled                           \n
                    \Range                  0 .. CanTp_u16NUM_OF_RX_NSDUS-1   \n
    \param[in/out]  pudtChannelResources    A pointer to the CanTpConnection
                                            resources structure at which the 
                                            reception operation is taking 
                                            place                             \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidCopyConsecutiveFrame (
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA)    pu8CFData,
    VAR(PduIdType, AUTOMATIC)                   udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)pudtChannelResources,
	VAR(uint8, AUTOMATIC)                       u8CFLength);


/******************************************************************************/
/* LOCAL FUNCTIONS DEFINITION                                                 */
/******************************************************************************/

static FUNC(void, CANTP_CODE) vidStopRxChannel(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                    pudtChannelResources,
    VAR(PduIdType, AUTOMATIC)       udtRxNSduId,
    VAR(NotifResultType, AUTOMATIC) udtResult)
{
    VAR(PduIdType, AUTOMATIC)   udtUpperLayerId;

    /*! Get the IPduId linked to this CanTpRxNSdu in order to be passed to the
        upper layer callback                                                  */
    udtUpperLayerId = 
              CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtRxNSduId].udtRxIPduId;

    /*! Re-initialize the  CanTpConnection resources                          */
    CanTp_vidInitChannelResources(pudtChannelResources);
    
	/*! Call the upper layer indication callback with the corresponding
        notification result                                                   */
    /*! \Trace_To   CanTp-CDD-0064(0)                                         */
    CanTp_vidUPPER_LAYER_INDIC(udtUpperLayerId, udtResult);
}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidHandleRxCancelReq (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)   u8Direction;
    VAR(uint8, AUTOMATIC)   u8LocalChannelId;
	P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)	pudtCancelledNSduId;
	P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)	pudtHandledNSduId;

    u8Direction = CanTp_u8GET_DIRECTION(pudtChannelResources);

    u8LocalChannelId = 
        CanTp_akstreRxNSduPCCfg[pudtChannelResources->udtHandledNSduId].
                                                                u8ChannelNumber;
	pudtCancelledNSduId = &(pudtChannelResources->strRxCancelRequest.udtCancelledNSduId);
	pudtHandledNSduId = &(pudtChannelResources->udtHandledNSduId);

    CanTp_akstreCriticalSections
		[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
													 pfvidEnterCriticalSec003_09();

    /*! \note   Before performing the cancellation, a check shall be performed
                to assure that the reception operation of the RxNSdu 
                requested for cancellation is still in progress.              \n
                Although when the cancellation request was accepted the
                reception was still in progress and the cancellation handling
                is performed directly on the next Main function call, but assume
                the folloing case:                                            \n
                1-The Main Function was preempted by the cancellation request 
                  of CanTp_CancelReceive                                      \n
                2-The request was accepted                                    \n
                3-The Main function execution continues and the CanTpConnection
                  was stopped (due to failure or timeout) and its state was set
                  to IDLE                                                     */

    /*! If the reception operation of the CanTpRxNSdu is still in progress:   */
    if(u8Direction == CanTp_u8DIR_RX)
    {
        if((*pudtCancelledNSduId) == (*pudtHandledNSduId))
        {
            /*! Abort the current reception, reset the CanTpConnection 
                resources, and notify the upper layer that the cancellation
                request was performed correctly                               */
            /*! \Trace_To   CanTp-CDD-0169(0),CanTp-CDD-0171(0)               */
            vidStopRxChannel(pudtChannelResources,(*pudtCancelledNSduId),
                                                      NTFRSLT_E_CANCELATION_OK);
        }
    }

    CanTp_akstreCriticalSections
		[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
													  pfvidExitCriticalSec003_09();

    /*! If the reception operation of the CanTpRxNSdu was not in progress, 
        then that means that the reception operation was stopped (between
        accepting the request and the Main function call) and the upper layer
        was already notified with the notification result
        (Timeout, failure, etc ..) so there is no need to notify the upper
        layer again with the cancellation request failure                     */

    /*! Clear the cancellation request flag to indicate that no cancellation
        request on this CanTpConnection is pending for handling               */
    pudtChannelResources->strRxCancelRequest.bCancellationRequest = FALSE;
}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidHandleCFRxError (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)       u8Direction;
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled;

    u8Direction = CanTp_u8GET_DIRECTION(pudtChannelResources);

    /*! If the reception operation of the CanTpRxNSdu is still in progress:   */
    if(u8Direction == CanTp_u8DIR_RX)
    {
        udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

        /*! Abort the current reception, reset the CanTpConnection 
            resources, and notify the upper layer with the notification result
            that was stored when the consecutive frame reception error 
            occurred                                                          */
        vidStopRxChannel(pudtChannelResources, udtNSduIdHandled,
               pudtChannelResources->strCFReceptionError.udtNotificationresult);
    }

    /*! Clear the consecutive frame reception error flag to indicate that no 
        consecutive frame error on this CanTpConnection is pending for 
        handling                                                              */
    pudtChannelResources->strCFReceptionError.bCFReceptionError = FALSE;
}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidHandleUnExpectedPdus (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)       u8Direction;
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled;
    VAR(PduInfoType, AUTOMATIC) udtUnExpPduInfo;
    VAR(PduIdType, AUTOMATIC)   udtUnExpNSduId;
    VAR(uint8, AUTOMATIC)       u8PciByteLocation;
    VAR(uint8, AUTOMATIC)       u8FrameType;
	VAR(uint8, AUTOMATIC)       u8LocalChannelId;
	P2VAR(PduIdType, AUTOMATIC,AUTOMATIC)	pudtRxNSduId;
	P2VAR(uint8, AUTOMATIC,AUTOMATIC)		pu8UnExpectedPduLen;
	P2VAR(uint8, AUTOMATIC,AUTOMATIC)		pu8UnExpectedPdu;
	P2VAR(boolean, AUTOMATIC,AUTOMATIC)		pbUnExpPduReceived;

    u8Direction = CanTp_u8GET_DIRECTION(pudtChannelResources);

    /*! \Trace_To   CanTp-CDD-5041(0), CanTp-CDD-5042(0)                      */
    /*! \Trace_To   CanTp-CDD-5048(0), CanTp-CDD-5049(0)                      */

    /*! Get the ID of the CanTpRxNSdu currently being handled             */
    udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

    u8LocalChannelId = 
					  CanTp_akstreRxNSduPCCfg[udtNSduIdHandled].u8ChannelNumber;

	pudtRxNSduId = &(pudtChannelResources->strUnExpectedPdu.udtRxNSduId);
	pu8UnExpectedPduLen = &(pudtChannelResources->strUnExpectedPdu.u8UnExpectedPduLen);
	pu8UnExpectedPdu = pudtChannelResources->strUnExpectedPdu.au8UnExpectedPdu;
	pbUnExpPduReceived = &(pudtChannelResources->strUnExpectedPdu.bUnExpPduReceived);

    CanTp_akstreCriticalSections
		[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
													 pfvidEnterCriticalSec001_06();

    /*! If a reception operation is still in progress on the CanTpConnection: */
    if(u8Direction == CanTp_u8DIR_RX)
    {
        /*! Abort the current reception, reset the CanTpConnection 
            resources, and notify the upper layer that the reception was 
            aborted due to un-expected PDU reception                          */
        vidStopRxChannel(pudtChannelResources,
                                         udtNSduIdHandled, NTFRSLT_E_UNEXP_PDU);
    }

    /*! Get the stored ID of the CanTpRxNSdu whose un-expected PDU was 
        received                                                              */
    udtUnExpNSduId = *pudtRxNSduId;

    /*! Get the stored length the un-expected PDU that was received           */
    udtUnExpPduInfo.SduLength = *pu8UnExpectedPduLen;

    /*! Get the address of the buffer where the un-expected PDU is stored     */
    udtUnExpPduInfo.SduDataPtr = pu8UnExpectedPdu;


    /*! If the addressing format of the CanTpRxNSdu is configured as
        standard addressing:                                                  */
    if(CanTp_akstreRxNSduPCCfg[udtUnExpNSduId].u8RxAddressingFormat == 
                                                    CanTp_u8STANDARD_ADDRESSING)
    {
        /*! The first PCI byte will be located at the first byte of the frame */
        u8PciByteLocation = 0;
    }
    /*! If the addressing format of the CanTpRxNSdu is configured as
        extended or mixed addressing:                                         */
    else
    {
        /*! The first PCI byte will be located at the second byte of the frame*/
        u8PciByteLocation = 1;
    }

    /*! Get the type of the received frame from the first PCI byte            */
    u8FrameType = 
          CanTp_u8PCI_FRAME_TYPE(pu8UnExpectedPdu[u8PciByteLocation]);

    /*! If the un-expected PDU received is a single frame:                    */
    if(u8FrameType == CanTp_u8SINGLE_FRAME)
    {
        /*! Call the function responsible for handling single frames          */
        CanTp_vidHandleSingleFrame(&udtUnExpPduInfo,
                                          udtUnExpNSduId, pudtChannelResources);
    }
    /*! If the un-expected PDU received is a first frame:                     */
    else
    {
        /*! Call the function responsible for handling first frames           */
        CanTp_vidHandleFirstFrame(&udtUnExpPduInfo,
                                          udtUnExpNSduId, pudtChannelResources);
    }

    /*! Clear the un-expected PDU flag to indicate that no un-expected PDU on 
        this CanTpConnection is pending for handling                          */
    *pbUnExpPduReceived = FALSE;


    CanTp_akstreCriticalSections
		[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
													  pfvidExitCriticalSec001_06();

}

/******************************************************************************/

LOCAL_INLINE FUNC(uint8, CANTP_CODE) u8NumOfBytesInRxFrame (
    P2CONST(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pkstrChannelResources,
    VAR(PduIdType, AUTOMATIC)   udtRxNSduId,
    VAR(uint8, AUTOMATIC)       u8FrameType)
{
    VAR(uint8, AUTOMATIC)       u8NumOfBytes=0;

    switch(u8FrameType)
    {
        /*! If the frame is a single frame                                    */
    case(CanTp_u8FRAME_SF):

        /*! Then the number of data bytes that this frame is holding is the 
            total message length                                              */
        u8NumOfBytes = (uint8)pkstrChannelResources->u16MessageLength;
        break;
    
        /*! If the frame is a first frame                                     */
    case(CanTp_u8FRAME_FF):

        /*! If the addressing format of the CanTpRxNSdu is configured as
            standard addressing:                                              */
        if(CanTp_akstreRxNSduPCCfg[udtRxNSduId].u8RxAddressingFormat
                                                 == CanTp_u8STANDARD_ADDRESSING)
        {
            /*! Then the number of data bytes that this frame is holding is 6 
                bytes                                                         */
            u8NumOfBytes = CanTp_u8STD_FF_DATA_LENGTH;
        }
        /*! If the addressing format of the CanTpRxNSdu is configured as
            extended or mixed addressing:                                     */
        else
        {
            /*! Then the number of data bytes that this frame is holding is 5 
                bytes                                                         */
            u8NumOfBytes = CanTp_u8STD_FF_DATA_LENGTH - 1;
        }
        break;

        /*! If the frame is a consecutive frame                               */
    case(CanTp_u8FRAME_CF):
        /*! If the addressing format of the CanTpRxNSdu is configured as
            standard addressing:                                              */
        if(CanTp_akstreRxNSduPCCfg[udtRxNSduId].u8RxAddressingFormat
                                                 == CanTp_u8STANDARD_ADDRESSING)
        {
            /*! Then the number of data bytes that this frame is holding is 7 
                bytes                                                         */
            u8NumOfBytes = CanTp_u8STD_CF_DATA_LENGTH;
        }
        /*! If the addressing format of the CanTpRxNSdu is configured as
            extended or mixed addressing:                                     */
        else
        {
            /*! Then the number of data bytes that this frame is holding is 6 
                bytes                                                         */
            u8NumOfBytes = CanTp_u8STD_CF_DATA_LENGTH - 1;
        }
        break;

        /*! If the frame is a last consecutive frame                          */
    case(CanTp_u8FRAME_LAST_CF):
        /*! If the addressing format of the CanTpRxNSdu is configured as
            standard addressing:                                              */
        if(CanTp_akstreRxNSduPCCfg[udtRxNSduId].u8RxAddressingFormat
                                                 == CanTp_u8STANDARD_ADDRESSING)
        {
            /*! Then the number of data bytes that this frame is holding is 7 
                bytes                                                         */
            u8NumOfBytes = CanTp_u8STD_CF_DATA_LENGTH;
        }
        /*! If the addressing format of the CanTpRxNSdu is configured as
            extended or mixed addressing:                                     */
        else
        {
            /*! Then the number of data bytes that this frame is holding is 6 
                bytes                                                         */
            u8NumOfBytes = CanTp_u8STD_CF_DATA_LENGTH - 1;
        }

        /*! If the last consecutive frame is the last frame in the message:   */
        if(pkstrChannelResources->u16MessageLength <= (uint16)u8NumOfBytes)
        {
            /*! Then this frame is holding the remaining message length       */
            u8NumOfBytes = (uint8)pkstrChannelResources->u16MessageLength;
        }

        break;

    default:
        break;
    }

    return u8NumOfBytes;
}

/******************************************************************************/

static FUNC(boolean, CANTP_CODE) bProvideRxBuffer(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                pudtChannelResources,
    VAR(PduIdType, AUTOMATIC)                   udtNSduIdHandled,
    VAR(uint8, AUTOMATIC)                       u8FrameType,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC)  pudtAvailableDataLength)
{
    VAR(boolean, AUTOMATIC)             bReturnValue= FALSE;
    VAR(BufReq_ReturnType, AUTOMATIC)   udtBufferRequestStatus;

    /*! Call StartOfReception of the upper layer to indicate the start of new
        reception with the total message length to be received                */
    /*! \Trace_To   CanTp-CDD-0045(0)                                         */
    udtBufferRequestStatus = CanTp_udtUPPER_LAYER_START(
        CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtNSduIdHandled].udtRxIPduId, 
        NULL_PTR,pudtChannelResources->u16MessageLength,pudtAvailableDataLength);

    /*! \Trace_To   CanTp-CDD-0065(0)                                         */

    /*! If the upper layer allocates a buffer and returns BUFREQ_OK:          */
    if(udtBufferRequestStatus == BUFREQ_OK)
    {
        /*! Set the Buffer Allocation flag and return TRUE                    */
        pudtChannelResources->bBufferAllocated = TRUE;
        bReturnValue = TRUE;
    }
    /*! If the upper layer temporarily can not provide a buffer and returns
        BUFREQ_E_BUSY                                                         */
    else if(udtBufferRequestStatus == BUFREQ_E_BUSY)
    {
        /*! Return FALSE                                                      */
    }
    /*! If the frame is a first frame (and not a single frame) and the upper 
        layer returns BUFREQ_E_OVFL (Total message length to be received exceeds
        the buffer size of the upper layer:                                   */
    /*! \Trace_To   CanTp-CDD-5027(0)                                         */
    else if((udtBufferRequestStatus == BUFREQ_E_OVFL) 
                                           && (u8FrameType == CanTp_u8FRAME_FF))
    {
        /*! Set CanTpConnection state to CanTp_u8RX_TRANSMIT_FC_OVFLW to
            transmit a WAIT flow control                                      */
        pudtChannelResources->u8ConnectionState 
                                                 = CanTp_u8RX_TRANSMIT_FC_OVFLW;
    }
    else
    {
        /*! Abort the current reception without sending a flow control,
            reset the CanTpConnection resources, and notify the upper layer that
            the reception has failed                                          */
        /*! \Trace_To   CanTp-CDD-0049(0)                                     */
        vidStopRxChannel(pudtChannelResources,
                                            udtNSduIdHandled, NTFRSLT_E_NOT_OK);

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
        /*! \Trace_To   CanTp-CDD-5160(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8MAIN_FUNCTION_ID, CANTP_E_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    }

    return bReturnValue;

}

/******************************************************************************/

static FUNC(boolean, CANTP_CODE) bCheckBufferSize(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                pudtChannelResources,
    VAR(PduIdType, AUTOMATIC)                   udtNSduIdHandled,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC)  pudtAvailableDataLength)
{
    VAR(boolean, AUTOMATIC)             bReturnValue= FALSE;
    VAR(BufReq_ReturnType, AUTOMATIC)   udtBufferRequestStatus;
    VAR(PduInfoType, AUTOMATIC)         udtPduInfo;

    /*! Set the SduDataPtr of the PduInfoType structure that will be passed to
        the upper layer with NULL                                             */
    udtPduInfo.SduDataPtr = NULL_PTR;

    /*! Set the SduLength of the PduInfoType structure that will be passed to
        the upper layer with 0                                                */
    udtPduInfo.SduLength = 0;

    /*! Call CopyRxData callback of the upper layer to check the available
        buffer size available                                                 */
    udtBufferRequestStatus = CanTp_udtUPPER_LAYER_RX_COPY(
        CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtNSduIdHandled].udtRxIPduId,
        &udtPduInfo, pudtAvailableDataLength);

    /*! If the upper layer returns BUFREQ_OK, then return TRUE                */
    if(udtBufferRequestStatus == BUFREQ_OK)
    {
        bReturnValue = TRUE;
    }
/*! If the upper layer returns BUFREQ_E_BUSY, then return FALSE               */
    else if(udtBufferRequestStatus == BUFREQ_E_BUSY)
    {

    }
    else
    {
        /*! Abort the current reception, reset the CanTpConnection resources,
            and notify the upper layer that the reception has failed          */
        vidStopRxChannel(pudtChannelResources,
                                            udtNSduIdHandled, NTFRSLT_E_NOT_OK);

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
        CanTp_vidREPORT_DET_ERROR(CanTp_u8MAIN_FUNCTION_ID, CANTP_E_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    }
    return bReturnValue;
}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidHandleRxCompletion (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pudtChannelResources,
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled,
	VAR(uint8, AUTOMATIC)       u8FrameType)
{
    /*! If the frame is a single frame:                                       */
    if(u8FrameType == CanTp_u8FRAME_SF)
    {
        /*! Notify the upper layer with reception success and re-initialize
            the CanTpConnection resources                                     */
        vidStopRxChannel(pudtChannelResources, udtNSduIdHandled, NTFRSLT_OK);
    }
    /*! If the frame is a last consecutive frame:                             */
    else if(u8FrameType == CanTp_u8FRAME_LAST_CF)
    {
        /*! Check if no more data bytes are remaining in the message to be
            received:                                                         */
        if(pudtChannelResources->u16MessageLength == 0)
        {
        /*! Notify the upper layer with reception success and re-initialize
            the CanTpConnection resources                                     */
            vidStopRxChannel(pudtChannelResources,
                                                  udtNSduIdHandled, NTFRSLT_OK);
        }
    }
    /*! If FF do nothing and wait for next main function                      */
    else
    {
    }
}

/******************************************************************************/

/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [4700]: Metric value out of threshold range*/
/*              The function is divided into two parts where one part of them */
/*              is always switched OFF by a pre-processor parameter           */
/* PRQA S 4700 ++                                                             */

static FUNC(void, CANTP_CODE) vidCheckNextBlockBuffer (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pudtChannelResources,
    VAR(PduIdType, AUTOMATIC)   udtRxNSduId)
{
    VAR(PduLengthType, AUTOMATIC)       udtAvailableBufferSize;
    VAR(uint8, AUTOMATIC)               u8CFDataLength;
    VAR(uint8, AUTOMATIC)               u8ConfiguredBlockSize;
    VAR(uint16, AUTOMATIC)              u16RemainingMsgLength;
    VAR(uint16, AUTOMATIC)              u16CurrentBlockSize;
    VAR(uint8, AUTOMATIC)               u8FrameType;
    VAR(boolean, AUTOMATIC)             bProceedToSendFC;

#if(CanTp_bDYNAMIC_RX_BLOCKSIZE == STD_ON)

    VAR(uint16, AUTOMATIC)              u16PossibleBlockSize;
    VAR(uint16, AUTOMATIC)              u16BlockSizeToFitMsg;

#else
    VAR(uint16, AUTOMATIC)              u16MinBuffSizeNeeded;

#endif

    /*! Check the number of bytes available in the upper layer buffer by
        calling the function resposible for checking the upper layer buffer
        size                                                                  */
    /*! \Trace_To   CanTp-CDD-5137(0)                                         */
    bProceedToSendFC = 
        bCheckBufferSize(pudtChannelResources,
                                          udtRxNSduId, &udtAvailableBufferSize);


    if(bProceedToSendFC == TRUE)
    {
        /*! If the addressing format of the CanTpRxNSdu is configured as
            standard addressing:                                              */
        if(CanTp_akstreRxNSduPCCfg[udtRxNSduId].u8RxAddressingFormat 
                                                 == CanTp_u8STANDARD_ADDRESSING)
        {
            /*! The consecutive frame will hold 7 data bytes                  */
            u8CFDataLength = CanTp_u8STD_CF_DATA_LENGTH;
        }
        /*! If the addressing format of the CanTpRxNSdu is configured as
            extended or mixed addressing:                                     */
        else
        {
            /*! The consecutive frame will hold 6 data bytes                  */
            u8CFDataLength = CanTp_u8STD_CF_DATA_LENGTH - 1;
        }

        /*! Get the number of bytes remaining to be received in the message   */
        u16RemainingMsgLength = pudtChannelResources->u16MessageLength;


        /*! Get the Block Size value configured for this CanTpRxNSdu          */
#if (CanTp_bCHANGE_PARAMETER_API == STD_ON)

        /*! If CanTp_bCHANGE_PARAMETER_API is configured with STD_ON, then get
            the recently changed block size value from the RAM variable of the
            CanTpRxNSdu holding the recent block size value                   */
        u8ConfiguredBlockSize = CanTp_au8eCurrentBlockSize[udtRxNSduId];
#else
        /*! If CanTp_bCHANGE_PARAMETER_API is configured with STD_OFF, then get
            the block size value from the configuration structure of the
            CanTpRxNSdu                                                       */
        u8ConfiguredBlockSize = 
            CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtRxNSduId].u8BlockSize;

#endif  /* CanTp_bCHANGE_PARAMETER_API == STD_ON */
        
        

        /*! If CanTp_bDYNAMIC_RX_BLOCKSIZE is configured with STD_ON, then the
            number of consecutive frames that will be transmitted in the next
            block of frames will be dependent on the available buffer size    \n
            The range of the block size value that will be transmitted in the
            next flow control frame is 0 to max. block size value (configured
            for the CanTpRxNSdu if CanTp_ChangeParameter is disabled 
            or recently updated value if CanTp_ChangeParameter is
            enabled                                                           */
#if(CanTp_bDYNAMIC_RX_BLOCKSIZE == STD_ON)

        pudtChannelResources->bFCWithZeroBS = FALSE;

        /*! According to the available buffer size, calculate the possible
            number of consecutive frames that can be transmitted              */
        if((udtAvailableBufferSize%u8CFDataLength)==0)
        {
            u16PossibleBlockSize =
                                udtAvailableBufferSize / (uint16)u8CFDataLength;
        }
        else
        {
            u16PossibleBlockSize =
                          (udtAvailableBufferSize / (uint16)u8CFDataLength) + 1;
        }
        
        /*! If the remaining data bytes in the message can fit in the possible
            number of consecutive frames allowed:                             */
        /*! \Trace_To   CanTp-CDD-5138(0)                                     */
        if((u16PossibleBlockSize * u8CFDataLength) > u16RemainingMsgLength)
        {
            /*! Calculate the number of consecutive frames needed to transmit
                the remaining message bytes                                   */
            if((u16RemainingMsgLength%u8CFDataLength)==0)
            {
                u16BlockSizeToFitMsg =
                                 u16RemainingMsgLength / (uint16)u8CFDataLength;
            }
            else
            {
                u16BlockSizeToFitMsg =
                           (u16RemainingMsgLength / (uint16)u8CFDataLength) + 1;
            }

            /*! If the number of consecutive frames needed to transmit the
                remaining message bytes exceeds the max. number of allowed
                block of consecutive frames:                                  */
            if((u16BlockSizeToFitMsg > u8ConfiguredBlockSize) 
                                                && (u8ConfiguredBlockSize != 0))
            {
                /*! Set the number of consecutive frames to be transmitted in
                    the next block to the max. number allowed                 */
                u16CurrentBlockSize = u8ConfiguredBlockSize;
            }
            /*! If the number of consecutive frames needed to transmit the
                remaining message bytes is less than the max. number of allowed
                block of consecutive frames:                                  */
            else
            {
                /*! Set the number of consecutive frames to be transmitted in
                    the next block to the number of consecutive frames needed
                    to transmit the remaining message bytes                   */
                u16CurrentBlockSize = u16BlockSizeToFitMsg;

                /*! Set FCWithZeroBS in order to transmit the next flow control
                    with block size value = 0                                 */
                pudtChannelResources->bFCWithZeroBS = TRUE;
            }
        }
        /*! If the remaining data bytes in the message can't fit in the possible
            number of consecutive frames allowed:                             */
        /*! \Trace_To   CanTp-CDD-5139(0)                                     */
        else
        {
            /*! If the possible number number of consecutive frames exceeds the
                max. number of allowed block of consecutive frames:           */
            if(u16PossibleBlockSize > u8ConfiguredBlockSize)
            {
                /*! Set the number of consecutive frames to be transmitted in
                    the next block to the max. number allowed                 */
                u16CurrentBlockSize = u8ConfiguredBlockSize;
            }
            /*! If the possible number number of consecutive frames doesn't
                exceed the max. number of allowed block of consecutive frames:*/
            else
            {
                /*! If the possible number of consecutive frames exceeds 255: */
                if(u16PossibleBlockSize > 255)
                {
                    /*! Limit the number of consecutive frames to 255         */
                    u16CurrentBlockSize = 255;
                }
                /*! If the possible number of consecutive frames does not
                    exceed 255:                                               */
                else
                {
                    /*! Set the number of consecutive frames to be transmitted
                        to the possible number of consecutive frames          */
                    u16CurrentBlockSize = u16PossibleBlockSize;
                }
            }
        }

        /*! If CanTp_bDYNAMIC_RX_BLOCKSIZE is configured with STD_OFF, then the
            number of consecutive frames that will be transmitted in the next
            block of frames must be the same as the number of block size
            configured for the CanTpRxNSdu if CanTp_ChangeParameter is
            disabled or recently updated value if CanTp_ChangeParameter
            is enabled. The only exception is the last block in the message
            which might contain fewer number of frames. If no buffer is
            available to hold this number of frames, a retry will be performed
            on the next Main function call till the buffer is available or till
            a timeout occurrs                                                 \n
            The block size value that will be transmitted in the next flow
            control frame is always constant                                  */

        /*! \Trace_To   CanTp-CDD-5142(0)                                     */

#else

        /*! If the remaining message size will fit in the mandatory block size
            configured:                                                       */
        if((u16RemainingMsgLength <= (u8CFDataLength * u8ConfiguredBlockSize))
            || (u8ConfiguredBlockSize == 0) )
        {
            /*! Calculate the number of consecutive frames needed to transmit
                the remaining message bytes                                   */
            /*! Calculate the minumum buffer size needed from the upper layer
                in order to send a flow control frame and start the next block
                reception                                                     */
            /*! \note   The upper layer shall provide buffer size at least
                        equals to (((mandatory no. of consecutive frames in the
                        block - 1) * number of bytes in a consecutive frame) 
                        + 1). A single byte must be provided for the data of 
                        the last consecutive frame in the block, while the
                        remaining data will be stored locally in the CanTp till
                        the remaining buffer is provided or till the timeout
                        occurrs                                               */
            if((u16RemainingMsgLength%u8CFDataLength)==0)
            {

                u16MinBuffSizeNeeded =
                    (((u16RemainingMsgLength/u8CFDataLength) - 1) 
                                                          * u8CFDataLength) + 1;

                u16CurrentBlockSize = u16RemainingMsgLength/u8CFDataLength;
            }
            else
            {
                u16MinBuffSizeNeeded =
                  ((u16RemainingMsgLength/u8CFDataLength) * u8CFDataLength) + 1;
                
                u16CurrentBlockSize =
                                     (u16RemainingMsgLength/u8CFDataLength) + 1;
            }
        }
       /*! If the remaining message size will not fit in the mandatory block
            size configured:                                                  */
        else
        {
            /*! Calculate the number of consecutive frames needed to transmit
                the remaining message bytes                                   */
            /*! Calculate the minumum buffer size needed from the upper layer
                in order to send a flow control frame and start the next block
                reception                                                     */

            u16MinBuffSizeNeeded =
                             ((u8ConfiguredBlockSize - 1) * u8CFDataLength) + 1;
            u16CurrentBlockSize = u8ConfiguredBlockSize;
        }

        /*! If the minimum buffer size needed is not yet provided by the upper
            layer:                                                            */
        if(udtAvailableBufferSize < u16MinBuffSizeNeeded)
        {
            /*! A flow control frame can not be transmitted and a retry will be
                performed in the next Main function if the timeout did not
                occurr                                                        */
            bProceedToSendFC = FALSE;
        }

        /*! If the minimum buffer size needed is provided by the upper layer,
            a clear to send flow control can be transmitted in order to start
            the reception of the next block of data                           */
        if(bProceedToSendFC == TRUE)
        {

#endif
            /*! Set the number of consecutive frames that will be transmitted
                in the next block                                             */
            pudtChannelResources->u16BlockSize = u16CurrentBlockSize;

            /*! If the latest frame received is a first frame, set the
                FirstFrame flag to TRUE                                       */
            u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);
            if(u8FrameType == CanTp_u8FRAME_FF)
            {
                pudtChannelResources->bFirstFrameReceived = TRUE;
            }

            /*! Clear the number of WAIT flow control frames transmitted      */
            pudtChannelResources->u8NumOfFCWaitFrames = 0;

            /*! Set CanTpConnection state to transmit "Clear To Send" flow
                control                                                       */
            /*! \Trace_To   CanTp-CDD-0057(0)                                 */
            pudtChannelResources->u8ConnectionState =
                                                     CanTp_u8RX_TRANSMIT_FC_CTS;

#if(CanTp_bDYNAMIC_RX_BLOCKSIZE != STD_ON)
        }
#endif
    }
}

/* PRQA S 4700 --                                                             */

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidRequestRxBuffer (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)               u8FrameType;
    VAR(uint8, AUTOMATIC)               u8TotalFrameBytes;
    VAR(uint8, AUTOMATIC)               u8BytesToBeCopied;
    VAR(BufReq_ReturnType, AUTOMATIC)   udtBufferRequestStatus;
    VAR(PduIdType, AUTOMATIC)           udtNSduIdHandled;
    VAR(PduInfoType, AUTOMATIC)         udtPduInfo;
    VAR(PduLengthType, AUTOMATIC)       udtAvailableDataLength;
    VAR(boolean,AUTOMATIC)              bProceedToCopyData;

    /*! Get the ID of the CanTpRxNSdu currently being handled                 */
    udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

    /*! If the local buffer still contains data to be provided to the upper
        layer:                                                                */
    if(pudtChannelResources->u8BytesInLocalBuffer!=0)
    {

        /*! Get the type of the frame being handled                           */
        u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);


        /*! Get the total number of data bytes that this frame type is holding 
            by calling the function resposible for calculating the number of 
            data bytes of each frame type                                     */
        u8TotalFrameBytes = 
            u8NumOfBytesInRxFrame(pudtChannelResources,
                                                 udtNSduIdHandled, u8FrameType);

        /*! If the reception buffer is still not yet allocated 
            (StartOfreception callback of the upper layer did not return
            BUFREQ_OK):                                                       */
        if(pudtChannelResources->bBufferAllocated != TRUE)
        {
            /*! Call the function responsible for calling StartOfReception
                callback of the upper layer. This step can be retried on
                next Main function calls till either the buffer is allocated
                or till the timeout occurrs                                   */
            bProceedToCopyData = 
                bProvideRxBuffer(pudtChannelResources,
                        udtNSduIdHandled, u8FrameType, &udtAvailableDataLength);
        }
        else
        {
            /*! If the buffer is already provided, check the number of bytes
                available in the upper layer buffer by calling the function
                resposible for checking the upper layer buffer size           */
            bProceedToCopyData = bCheckBufferSize(pudtChannelResources, 
                                     udtNSduIdHandled, &udtAvailableDataLength);
        }

        if(bProceedToCopyData == TRUE)
        {
            /*! If the available buffer size is greater than or equal to the
                number of data data bytes in the local buffer:                */
            if(udtAvailableDataLength >= 
                           (uint16)(pudtChannelResources->u8BytesInLocalBuffer))
            {
                /*! The number of bytes to be copied to the upper layer is the
                    number of data bytes in the local buffer                  */
                u8BytesToBeCopied = pudtChannelResources->u8BytesInLocalBuffer;
            }
            /*! If the available buffer size is less than the number of data 
            bytes in the local buffer:                                        */
            else
            {
                /*! The number of bytes to be copied to the upper layer is the
                    number of bytes available in the upper layer buffer       */
                u8BytesToBeCopied = (uint8) udtAvailableDataLength;
            }

            /*! Set SduLength of the PduInfoType stucture that will be passed
                t0 the upper layer to the number of bytes to be copied        */
            udtPduInfo.SduLength = u8BytesToBeCopied;

            /*! Set SduDataPtr of the PduInfoType stucture that will be passed
                t0 the upper layer to the address of the data byte in the local
                buffer that the copying process will start from               */
            udtPduInfo.SduDataPtr = 
                &(pudtChannelResources->au8LocalDataBuffer[u8TotalFrameBytes - 
                                 (pudtChannelResources->u8BytesInLocalBuffer)]);

            /*! Call CopyRxData of the upper layer to copy the data bytes from
                the local buffer                                              */
            /*! \Trace_To   CanTp-CDD-0113(0)                                 */
            udtBufferRequestStatus = 
                CanTp_udtUPPER_LAYER_RX_COPY(CanTp_pkstreGlobalConfig->
                                   pkstrRxNSduCfg[udtNSduIdHandled].udtRxIPduId,
                                          &udtPduInfo, &udtAvailableDataLength);

            /*! If the upper layer returns BUFREQ_OK and the number of bytes
                requested to be copied are copied successfully:               */
            if(udtBufferRequestStatus == BUFREQ_OK)
            {
                /*! Decrement the number of bytes copied by the upper layer 
                    from the number of data bytes in the local buffer to
                    indicate that these bytes were already copied             */
                pudtChannelResources->u8BytesInLocalBuffer -= u8BytesToBeCopied;

                /*! Decrement the number bytes copied by the upper layer from
                    the total message length to indicate that these bytes were
                    already copied                                            */
                pudtChannelResources->u16MessageLength -= u8BytesToBeCopied;

                /*! If all frame data bytes stored in the local buffer are
                    copied to the upper layer:                                */
                if(pudtChannelResources->u8BytesInLocalBuffer == 0)
                {
                    /*! Call the function responsible for checking if the
                        reception operation was completed and notifies the
                        upper layer                                           */
                    vidHandleRxCompletion(pudtChannelResources,udtNSduIdHandled
                                                 ,u8FrameType);
                }
            }
            /*! If the upper layer returns BUFREQ_E_BUSY:                     */
            else if(udtBufferRequestStatus == BUFREQ_E_BUSY)
            {
                /*! Do nothing and wait to retry on the next Main function call
                    unless the timeout occurrs                                */
            }
            else
            {
                /*! Abort the current reception, reset the CanTpConnection
                    resources, and notify the upper layer that the reception
                    has failed                                                */
                vidStopRxChannel(pudtChannelResources,
                                            udtNSduIdHandled, NTFRSLT_E_NOT_OK);

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
                /*! \Trace_To   CanTp-CDD-5161(0)                             */
                CanTp_vidREPORT_DET_ERROR(CanTp_u8MAIN_FUNCTION_ID,
                                                                   CANTP_E_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
            }
        }
    }

    /*! Get the type of the frame being handled                           */
    u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

    /*! If the frame is a first frame or a last consecutive frame (but not the
        last consecutive frame in the message, and the frame data were provided
        to the upper layer successfully:                                      */
    /*! \Trace_To   CanTp-CDD-0066(0), CanTp-CDD-0067(0)                      */
    if((pudtChannelResources->u8BytesInLocalBuffer == 0)
        &&
        ((u8FrameType == CanTp_u8FRAME_FF)
            || 
        ((u8FrameType == CanTp_u8FRAME_LAST_CF)
                          && (pudtChannelResources->bLastFrameInMsg == FALSE))))
    {
        /*! Call the function responsible for performing the needed calculations
            before transmitting the flow control frame                        */
        vidCheckNextBlockBuffer(pudtChannelResources, udtNSduIdHandled);
    }
}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidCheckFcWaitTransmit(
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled;

    /*! If this Main function call is the last call before the timeout
        occurrs:                                                              */
    /*! \Trace_To   CanTp-CDD-0054(0)                                         */
    if(pudtChannelResources->u16TimeoutCounter == 1)
    {
        /*! If the frame currently being handled is not the last frame in the
            message:                                                          */
        if(pudtChannelResources->bLastFrameInMsg != TRUE)
        {
            udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

            /*! If the number of successive WAIT flow controls that were
                transmitted didn't reach the max. number of successive flow
                control frames allowed for this CanTpRxNSdu:                  */
            if(pudtChannelResources->u8NumOfFCWaitFrames < 
                CanTp_pkstreGlobalConfig->pkstrRxNSduCfg
                                                 [udtNSduIdHandled].u16RxWftMax)
            {
                /*! Set the CanTpConnection to CanTp_u8RX_TRANSMIT_FC_WAIT to
                    transmit a WAIT flow control                              */

                pudtChannelResources->u8ConnectionState =
                                                    CanTp_u8RX_TRANSMIT_FC_WAIT;
                
            }
            /*! \Trace_To   CanTp-CDD-0055(0)                                 */
            else
            {
                /*! If the max. number of successive flow control frames was
                    reached:                                                  */
                /*! \Trace_To   CanTp-CDD-0284(0)                             */
                if(CanTp_pkstreGlobalConfig->pkstrRxNSduCfg
                                            [udtNSduIdHandled].u16RxWftMax != 0)
                {
                    /*! Abort the current reception, reset the CanTpConnection 
                        resources, and notify the upper layer that the max.
                        number of wait flow control transmissions was reached
                        (NTFRSLT_E_WFT_OVRN)                                  */
                    vidStopRxChannel(pudtChannelResources, 
                                          udtNSduIdHandled, NTFRSLT_E_WFT_OVRN);

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
					CanTp_vidREPORT_DET_ERROR(
										  CanTp_u8MAIN_FUNCTION_ID,CANTP_E_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
                }
            }
        }
    }
}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidPrepareFCFrame (
    P2CONST(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pkstrChannelResources,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8DataBuffer,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8FrameDlc)
{
    VAR(uint8, AUTOMATIC)       u8PciFirstByteLocation;
    VAR(uint8, AUTOMATIC)       u8STminValue;
    VAR(uint8, AUTOMATIC)       u8FrameType;
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled;

#if(CanTp_bDYNAMIC_RX_BLOCKSIZE != STD_ON)
    VAR(uint8, AUTOMATIC)       u8BlockSizeValue;
#endif  /* CanTp_bDYNAMIC_RX_BLOCKSIZE != STD_ON */

    /*! Get the type of the flow control frame to be prepared                 */
    u8FrameType = CanTp_u8GET_FRAME_TYPE(pkstrChannelResources);
    
    /*! Get the ID of the CanTpRxNSdu currently being handled                 */
    udtNSduIdHandled = pkstrChannelResources->udtHandledNSduId;

    /*! If the addressing format of the CanTpRxNSdu is configured as
        standard addressing:                                                  */
    if(CanTp_akstreRxNSduPCCfg[udtNSduIdHandled].u8RxAddressingFormat 
                                                 == CanTp_u8STANDARD_ADDRESSING)
    {
        /*! The first PCI byte of the flow control frame will be located at
            the first byte of the frame                                       */
        u8PciFirstByteLocation = CanTp_u8STD_FC_PCI_BYTE;
    }
    else
    {
        /*! The first PCI byte of the flow control frame will be located at
            the second byte of the frame                                      */
        u8PciFirstByteLocation = CanTp_u8STD_FC_PCI_BYTE + 1;
    }

    switch(u8FrameType)
    {
        /*! If the flow control to be prepared is a "Clear To Send" frame:   */
    case(CanTp_u8FRAME_FC_CTS):

        /*! Write the value 0 "Clear To Send" to the flow status parameter
            located at the lower nibble of the first PCI byte of the flow
            control frame                                                     */
        /*! \Trace_To   CanTp-CDD-5091(0)                                     */
        pu8DataBuffer[u8PciFirstByteLocation] =
                                      CanTp_u8FC_FC_FS_MASK | CanTp_u8FC_FS_CTS;

        /*! If CanTp_bDYNAMIC_RX_BLOCKSIZE is configured with STD_ON:         */
#if(CanTp_bDYNAMIC_RX_BLOCKSIZE == STD_ON)

        /*! If the bFCWithZeroBS flag is set to TRUE:                         */
        if(pkstrChannelResources->bFCWithZeroBS == TRUE)
        {
            /*! Write the value 0 at the block size parameter located at the
                second PCI byte of the flow control frame                     */
            pu8DataBuffer[u8PciFirstByteLocation + 1] = 0;
        }
        /*! If the bFCWithZeroBS flag is set to FALSE:                        */
        else
        {
            /*! Write the number of consecutive frames that will be received
                to the block size parameter located at the second PCI byte of
                the flow control frame                                        */
            pu8DataBuffer[u8PciFirstByteLocation + 1] = 
                                     (uint8)pkstrChannelResources->u16BlockSize;
        }
     
        
#else
        /*! If CanTp_bDYNAMIC_RX_BLOCKSIZE is configured with STD_OFF:        */

        /*! Get the configured block size value that will be transmitted in the
            flow control frame                                                */
        /*! \Trace_To   CanTp-CDD-5143(0)                                     */

#if (CanTp_bCHANGE_PARAMETER_API == STD_ON)
        u8BlockSizeValue = CanTp_au8eCurrentBlockSize[udtNSduIdHandled];
#else
        u8BlockSizeValue = 
            CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtNSduIdHandled].
                                                                    u8BlockSize;

#endif  /* CanTp_bCHANGE_PARAMETER_API == STD_ON */

        /*! Write configured block size value to the block size parameter
            located at the second PCI byte of the flow control frame          */
        /*! \Trace_To   CanTp-CDD-5092(0)                                     */
        pu8DataBuffer[u8PciFirstByteLocation + 1] = u8BlockSizeValue;

#endif  /* CanTp_bDYNAMIC_RX_BLOCKSIZE == STD_ON */


        /*! Get the configured STmin value that will be transmitted in the
            flow control frame                                                */
#if (CanTp_bCHANGE_PARAMETER_API == STD_ON)
        u8STminValue = CanTp_au8eCurrentSTmin[udtNSduIdHandled];
#else
        u8STminValue = 
             CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtNSduIdHandled].u8STmin;
#endif  /* CanTp_bCHANGE_PARAMETER_API == STD_ON */

        /*! Write configured STmin value to the STmin parameter located at the
            third PCI byte of the flow control frame                          */
        /*! \Trace_To   CanTp-CDD-5079(0), CanTp-CDD-5093(0)                  */
        pu8DataBuffer[u8PciFirstByteLocation + 2] = u8STminValue;

        break;

        /*! If the flow control to be prepared is an "Overflow" frame:        */
    case(CanTp_u8FRAME_FC_OVFLW):

        /*! Write the value 2 "Overflow" to the flow status parameter located
            at the lower nibble of the first PCI byte of the flow control
            frame                                                             */
        pu8DataBuffer[u8PciFirstByteLocation] =
                                    CanTp_u8FC_FC_FS_MASK | CanTp_u8FC_FS_OVFLW;

        pu8DataBuffer[u8PciFirstByteLocation + 1] = 0;
        pu8DataBuffer[u8PciFirstByteLocation + 2] = 0;
        break;

        /*! If the flow control to be prepared is a "WAIT" frame:             */
    case(CanTp_u8FRAME_FC_WAIT):

        /*! Write the value 1 "WAIT" to the flow status parameter located at
            the lower nibble of the first PCI byte of the flow control frame  */
        pu8DataBuffer[u8PciFirstByteLocation] =
                                     CanTp_u8FC_FC_FS_MASK | CanTp_u8FC_FS_WAIT;

        pu8DataBuffer[u8PciFirstByteLocation + 1] = 0;
        pu8DataBuffer[u8PciFirstByteLocation + 2] = 0;
        break;

    default:
        break;
    }

    /*! If the CanTpRxNSdu is configured with padding enabled:                */
    /*! \Trace_To   CanTp-CDD-5153(0)                                         */
    if(CanTp_akstreRxNSduPCCfg[udtNSduIdHandled].u8RxPaddingActivation
                                                          == CanTp_u8PADDING_ON)
    {
        /*! Call the function responsible for padding the unused bytes of
            the frame                                                         */
        CanTp_vidPadTxBuffer(u8PciFirstByteLocation + CanTp_u8FC_NUM_PCI_BYTES
                , pu8DataBuffer);

        /*! Set the frame length to 8 bytes                                   */
        *pu8FrameDlc = 8;
    }
    /*! If the CanTpRxNSdu is configured with padding disabled:               */
    else
    {
        /*! Set the frame length to 3 if standars addressing is used and 4 if
            extended or mixed addressing is used                              */
        *pu8FrameDlc = u8PciFirstByteLocation + CanTp_u8FC_NUM_PCI_BYTES;
    }

    /*! \Trace_To   CanTp-CDD-0093(0), CanTp-CDD-5153(0)                      */

    /*! If the addressing format of the CanTpRxNSdu is configured as
        extended addressing:                                                  */
    if(CanTp_akstreRxNSduPCCfg[udtNSduIdHandled].u8RxAddressingFormat 
                                                 == CanTp_u8EXTENDED_ADDRESSING)
    {
        /*! Write the Target Address value configured for this CanTpRxNSdu
            at the first byte of the transmitted flow control frame           */
        pu8DataBuffer[0] =
                    CanTp_akstreRxNSduPCCfg[udtNSduIdHandled].u8NTargetAddress;
    }
    /*! If the addressing format of the CanTpRxNSdu is configured as
        mixed addressing:                                                     */
    else if(CanTp_akstreRxNSduPCCfg[udtNSduIdHandled].u8RxAddressingFormat 
                                                    == CanTp_u8MIXED_ADDRESSING)
    {
        /*! Write the Address Extension value configured for this CanTpRxNSdu
            at the first byte of the transmitted flow control frame           */
        pu8DataBuffer[0] =
                  CanTp_akstreRxNSduPCCfg[udtNSduIdHandled].u8NAddressExtension;
    }
    /*! If the addressing format of the CanTpRxNSdu is configured as
        standard addressing:                                                  */
    else
    {
        /*! Do nothing                                                        */
    }
}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidTransmitFCFrame (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)           u8FrameType;
    VAR(PduIdType, AUTOMATIC)       udtNSduIdHandled;
    VAR(Std_ReturnType, AUTOMATIC)  u8CanIfTransmitStatus;
    VAR(PduIdType, AUTOMATIC)       udtLowerLayerId;
    VAR(PduInfoType, AUTOMATIC)     udtPduInfo;
    VAR(uint8, AUTOMATIC)           au8TempBuffer[CanTp_u8LOCAL_BUFFER_SIZE];
    VAR(uint8, AUTOMATIC)           u8FcFrameDlc;

    /*! Get the type of the flow control frame to be transmitted              */
    u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);
    
    /*! Get the ID of the CanTpRxNSdu currently being handled                 */
    udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;
    
    /*! Get the LSduId linked to this CanTpRxNSdu in order to be passed to the
        lower layer API while transmitting the flow control frame             */
    udtLowerLayerId =
       CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtNSduIdHandled].udtTxFcLSduId;

    /*! Call the function resposible for preparing the PCI bytes of the flow
        control frame                                                         */
    vidPrepareFCFrame(pudtChannelResources, au8TempBuffer, &u8FcFrameDlc);

#if(CanTp_bCANIF_TRANSMIT_RETRY == STD_ON)
    if(pudtChannelResources->bFirstTransmitRetry == TRUE)
    {
#endif  /* CanTp_bCANIF_TRANSMIT_RETRY == STD_ON */

        /* !Deviation : Inhibit MISRA rule [2215]: The indentation is not     */
        /*              consisitent with the configured path because the "if" */
        /*              statement might be switched off using a pre-processor */
        /*              parameter                                             */
        /* PRQA S 2215 ++                                                     */
        pudtChannelResources->u16TimeoutCounter = 
              CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtNSduIdHandled].u16NAr;
        /* PRQA S 2215 --                                                     */

#if(CanTp_bCANIF_TRANSMIT_RETRY == STD_ON)
        pudtChannelResources->bFirstTransmitRetry = FALSE;
    }
#endif  /* CanTp_bCANIF_TRANSMIT_RETRY == STD_ON */
    

    /*! Set SduDataPtr of the PduInfoType structure that will be passed to the
        lower layer with the address of the buffer containing the flow control*/
    udtPduInfo.SduDataPtr = au8TempBuffer;

    /*! Set SduLength of the PduInfoType structure that will be passed to the
        lower layer with the length of the flow control frame                 */
    udtPduInfo.SduLength = u8FcFrameDlc;

    /*! Call the lower layer transmit function to transmit the flow control
        frame                                                                 */
    u8CanIfTransmitStatus =
                           CanTp_udtLOWER_LAYER_TX(udtLowerLayerId,&udtPduInfo);

    /*! If the lower layer returns E_OK and the frame was transmitted
        succesfully:                                                          */
    if(u8CanIfTransmitStatus == E_OK)
    {
#if(CanTp_bCANIF_TRANSMIT_RETRY == STD_ON)
        /*! Reset the FirstTransmitRetry flag if transmission retry is enabled*/
        pudtChannelResources->bFirstTransmitRetry = TRUE;
#endif  /* CanTp_bCANIF_TRANSMIT_RETRY == STD_ON */

        /*! \Trace_To   CanTp-CDD-5019(0)                                     */

        /*! If the transmitted flow control is clear to send:                 */
        if(u8FrameType == CanTp_u8FRAME_FC_CTS)
        {
            /*! Set CanTpConnection state to wait for flow control clear to
                send confirmation                                             */
            pudtChannelResources->u8ConnectionState =
                                                     CanTp_u8RX_WAITCONF_FC_CTS;
        }
        /*! If the transmitted flow control is wait:                          */
        else if(u8FrameType == CanTp_u8FRAME_FC_WAIT)
        {
            /*! Increment the number of successive flow control wait
                transmitted                                                   */
            pudtChannelResources->u8NumOfFCWaitFrames++;

            /*! Set CanTpConnection state to wait for flow control wait
            confirmation                                                      */
            pudtChannelResources->u8ConnectionState = 
                                                    CanTp_u8RX_WAITCONF_FC_WAIT;
        }
        /*! If the transmitted flow control is overflow:                      */
        else if(u8FrameType == CanTp_u8FRAME_FC_OVFLW)
        {
            /*! Abort the current reception, reset the CanTpConnection
                resources, and notify the upper layer that the reception
                operation has failed                                          */
            vidStopRxChannel(pudtChannelResources, 
                      pudtChannelResources->udtHandledNSduId, NTFRSLT_E_NOT_OK);

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
            /*! \Trace_To   CanTp-CDD-5164(0)                                 */
            CanTp_vidREPORT_DET_ERROR(CanTp_u8MAIN_FUNCTION_ID, CANTP_E_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
        
        }
        else
        {
        }
    }
    else
    {
        /*! If the transmission request was rejected by the lower layer and
            transmission retry is disabled:                                   \n
            Abort the current reception, reset the CanTpConnection resources,
            and notify the upper layer that the reception operation has failed*/

#if(CanTp_bCANIF_TRANSMIT_RETRY != STD_ON)

        vidStopRxChannel(
                      pudtChannelResources, udtNSduIdHandled, NTFRSLT_E_NOT_OK);

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
        /*! \Trace_To   CanTp-CDD-5163(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8MAIN_FUNCTION_ID, CANTP_E_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */

#endif  /* CanTp_bCANIF_TRANSMIT_RETRY != STD_ON */
    }

}

/******************************************************************************/

static FUNC(boolean, AUTOMATIC) bCheckCFErrors (
    /* !Deviation : Inhibit MISRA rule [3673]: AutoSAR Mandatory interfaces.  */
    /*              Data is provided from the lower layer as variables and not*/
    /*              constants, and will be passed to the upper layer using    */
    /*              another mandatory AutoSAR interface as variables and not  */
    /*              constants                                                 */
    /* PRQA S 3673 ++                                                         */
	P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)      pudtPduInfoPtr,
    /* PRQA S 3673 --                                                         */
    VAR(PduIdType, AUTOMATIC)                           udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                        pudtChannelResources,
    VAR(uint8, AUTOMATIC)                               u8PciByteLocation)
{
    VAR(boolean, AUTOMATIC)     bReturnValue = TRUE;
    VAR(uint8, AUTOMATIC)       u8ReceivedSequenceNum;
    VAR(boolean, AUTOMATIC)     bLastFrame;
    VAR(uint16, AUTOMATIC)      u16RemainingData;
    VAR(uint8, AUTOMATIC)       u8Padding;


    bLastFrame = 
              pudtChannelResources->bLastFrameInMsg;
    
    u8Padding = CanTp_akstreRxNSduPCCfg[udtRxNSduId].u8RxPaddingActivation;
    
    u16RemainingData = pudtChannelResources->u16MessageLength;

    /*! Check that the length of the PDU received is valid                    \n
        It can be invalid if one of the following cases occurs:               \n
        -If padding is enabled for this CanTpRxNSdu and the frame data length
         code is not 8.                                                       \n
        -If padding is disabled and the frame data length code is not consistent
         with the single frame data length                                    \n
        -If the consecutive frame is not the last frame in the message and the
         frame data length is not 8.                                          \n
        -If padding is disabled and the last consecutive frame data length is
         not consistent with the remaining message length                     */
    /*! \Trace_To   CanTp-CDD-5157(0), CanTp-CDD-5071(0)                      */

    if(((u8Padding == CanTp_u8PADDING_ON) && (pudtPduInfoPtr->SduLength != 8))
        ||
        ((u8Padding == CanTp_u8PADDING_OFF) && (bLastFrame == TRUE) && 
        (pudtPduInfoPtr->SduLength != 
                                 ((u8PciByteLocation + 1) + u16RemainingData)))
        ||
        ((u8Padding == CanTp_u8PADDING_OFF) && (bLastFrame == FALSE) &&
                                              (pudtPduInfoPtr->SduLength != 8)))
    {
        /*! If the length of the PDU is invalid return FALSE to ignore the PDU*/

        /*! If DET is enabled:                                                */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! Report the corresponding DET error code                           */
        CanTp_vidREPORT_DET_ERROR(
                           CanTp_u8RX_INDICATION_ID, CANTP_E_INVALID_RX_LENGTH);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
        bReturnValue = FALSE;
    }
    else
    {
        /*! Read the sequence number of the consecutive frame located at the
            lower nibble of the PCI byte of the consecutive frame             */
        /*! \Trace_To   CanTp-CDD-5075(0)                                     */
        u8ReceivedSequenceNum = 
                    pudtPduInfoPtr->SduDataPtr[u8PciByteLocation]
                                                       & CanTp_u8CF_PCI_SN_MASK;

        /*! If the previous consecutive frame was received with sequence number
            = 15 then reset the sequence number to 0, otherwise increment the
            previous sequence number                                          */
        /*! \Trace_To   CanTp-CDD-5083(0), CanTp-CDD-5085(0)                  */
        /*! \Trace_To   CanTp-CDD-5086(0)                                     */
        if(pudtChannelResources->u8SequenceNumber == CanTp_u8CF_MAX_SN)
        {
            pudtChannelResources->u8SequenceNumber = 0;
        }
        else
        {
            pudtChannelResources->u8SequenceNumber++;
        }

        /*! If the consecutive frame is received with incorrect sequence
            number:                                                           */
        if(u8ReceivedSequenceNum != pudtChannelResources->u8SequenceNumber)
        {
            /*! Set the consecutive frame error flag and save the error type,
                to be handled in the next Main function                       */
            /*! \Trace_To   CanTp-CDD-0063(0)                                 */
            pudtChannelResources->strCFReceptionError.bCFReceptionError = TRUE;
            pudtChannelResources->strCFReceptionError.udtNotificationresult =
                                                             NTFRSLT_E_WRONG_SN;

            /*! Return FALSE in order not to handle the consecutive frame     */
            bReturnValue = FALSE;

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
            
            /*! \Trace_To   CanTp-CDD-5068(0)                                 */
            CanTp_vidREPORT_DET_ERROR(CanTp_u8RX_INDICATION_ID, CANTP_E_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
        }
    }

    return bReturnValue;
}

/******************************************************************************/

static FUNC(void, CANTP_CODE) vidCopyConsecutiveFrame (
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA)    pu8CFData,
    VAR(PduIdType, AUTOMATIC)                   udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR) pudtChannelResources,
	VAR(uint8, AUTOMATIC)                       u8CFLength)
{
    VAR(PduInfoType, AUTOMATIC)         udtPduInfo;
    VAR(PduLengthType, AUTOMATIC)       udtAvailableDataLength;
    VAR(BufReq_ReturnType, AUTOMATIC)   udtBufferRequestStatus;

    /*! Set SduLength of the PduInfoType structure that will be passed to the
        lower layer with the length of the consecutive frame                  */
    udtPduInfo.SduLength = u8CFLength;

    /*! Set SduDataPtr of the PduInfoType structure that will be passed to the
        lower layer with the start address of the consecutive frame data      */
    udtPduInfo.SduDataPtr = pu8CFData;

    /*! Call the upper layer callback function responisble for copying the
        received data                                                         */
    /*! \Trace_To   CanTp-CDD-0058(0)                                         */
    udtBufferRequestStatus = 
                CanTp_udtUPPER_LAYER_RX_COPY(CanTp_pkstreGlobalConfig->
                                   pkstrRxNSduCfg[udtRxNSduId].udtRxIPduId,
                                          &udtPduInfo, &udtAvailableDataLength);

    /*! If the upper layer returns BUFREQ_OK:                                 */
    if(udtBufferRequestStatus == BUFREQ_OK)
    {
        /*! Decrement the number of bytes copied to the upper layer from the
            total message length                                              */
        pudtChannelResources->u16MessageLength -= u8CFLength;

        /*! If there is only 1 consecutive frame remaining to be received in
            the current block:                                                */
        if(pudtChannelResources->u16BlockSize == 1)
        {
            /*! Set the CanTpConnection state to wait for last consecutive frame
                reception                                                     */
            pudtChannelResources->u8ConnectionState = CanTp_u8RX_WAITRX_LAST_CF;
            
            /*! Check if the last consecutive frame to be received is that last
                consecutive frame in the message                              */
            pudtChannelResources->bLastFrameInMsg =
                CanTp_bIsNextFrameLastInMsg(CanTp_u8DIR_RX, udtRxNSduId,
														pudtChannelResources);
        }
        /*! If there is still more than 1 consecutive frame remaining to be 
            received in the current block:                                    */
        else
        {
            /*! Set the CanTpConnection state to wait for consecutive frame
                reception                                                     */
            pudtChannelResources->u8ConnectionState = CanTp_u8RX_WAITRX_CF;
        }
    }
    /*! If the upper layer doesn't return BUFREQ_OK:                          */
    /*! \Trace_To   CanTp-CDD-0062(0), CanTp-CDD-5029(0)                      */
    else
    {

        /*! Set the consecutive frame error flag and save the error type, to be
            handled in the next Main function                                 */
        pudtChannelResources->strCFReceptionError.bCFReceptionError = TRUE;
        pudtChannelResources->strCFReceptionError.udtNotificationresult =
                                                               NTFRSLT_E_NOT_OK;

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
        /*! \Trace_To   CanTp-CDD-5162(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8RX_INDICATION_ID, CANTP_E_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */


    }
}

/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTIONS DEFINITION                                                */
/******************************************************************************/

FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelReceive(
    VAR(PduIdType, AUTOMATIC) CanTpRxSduId)
{
    VAR(Std_ReturnType, AUTOMATIC)  udtReturnValue = E_NOT_OK;
    VAR(uint8, AUTOMATIC)           u8Direction;
    VAR(uint8, AUTOMATIC)           u8FrameType;
    VAR(uint16, AUTOMATIC)          u16IndexOfResources;
    VAR(PduIdType, AUTOMATIC)       udtNSduIdHandled;
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                    pudtChannelResources;
    

    /*! If the service was called while the CanTp is not initialized:         */
    /*! \Trace_To   CanTp-CDD-5003(0)                                         */
    if(CanTp_u8eCanTpGlobalState != CANTP_ON)
    {
        /*! If DET is enabled:                                                */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! Report the corresponding DET error code                           */
        /*! \Trace_To   CanTp-CDD-5011(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8CANCEL_RECEIVE_ID, CANTP_E_UNINIT);

#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    }
    
    /*! If DET is enabled:                                                    */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)
    
    /*! If an invalid RxNSduId is received                                    */
    else if(CanTpRxSduId >= CanTp_u16NUM_OF_RX_NSDUS)
    {
        /*! Report the corresponding DET error code                           */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8CANCEL_RECEIVE_ID, CANTP_E_PARAM_ID);
    }
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    else
    {
        /*! If no DET errors were detected:                                   */
        
        /*! Get the index of the CanTpConnection resources -responsible for 
            handling the reception operations- of the CanTpChannel that 
            the CanTpRxNSdu requested for reception cancellation belongs to   */
        u16IndexOfResources = 
            CanTp_akstreTpChannels[CanTp_akstreRxNSduPCCfg[CanTpRxSduId]
                                        .u8ChannelNumber].u16IndexOfRxResources;
                                        
        /*! Assign the local pointer to the address of the CanTpConnection     
            resources                                                         */
        pudtChannelResources = 
                             &CanTp_astreChannelsResources[u16IndexOfResources];

        /*! Get the current direction of the CanTpConnection                  */
        u8Direction = CanTp_u8GET_DIRECTION(pudtChannelResources);

        /*! Get the current reception operation taking place on this
            CanTpConnection                                                   */
        u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

        /*! Get the ID of the CanTpRxNSdu currently being handled             */
        udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

        /*! \Trace_To   CanTp-CDD-0168(0),CanTp-CDD-0170(0)                   */

        /*! Check whether the cancellation can be performed or not            \n
            In order to perform the cancellation, the following conditions
            shall be met:                                                     \n
            -The CanTpConnection must be already performing a reception 
             operation for the same CanTpRxNSdu requested for cancellation    \n
            -No previous cancellation request on this CanTpConnection is still
             pending to be handled in the next Main function (This scenario can
             happen only if 2 or more successive cancellation requests are 
             received between 2 Main function calls                           */
        if( (u8Direction == CanTp_u8DIR_RX)
            &&
            (udtNSduIdHandled == CanTpRxSduId)
            &&
            (pudtChannelResources->strRxCancelRequest.bCancellationRequest !=
                                                                          TRUE))
        {
            /*! Check whether the cancellation request can be accepted or not \n
                In order to accept the cancellation request, the following
                conditions shall be met:                                      \n
                -A multiple frame reception operation is currently taking place
                 for this CanTpRxNSdu and not a single frame reception
                 operation                                                    \n
                -The CanTpConnection is not in the process of receiving the
                 last consecutive frame of the message                        */

            /*! If the cancellation request can be accepted:                  */
            if((u8FrameType != CanTp_u8FRAME_SF) && 
              ((u8FrameType != CanTp_u8FRAME_LAST_CF) ||
              (pudtChannelResources->bLastFrameInMsg != TRUE)))
            {
                /*! Set the cancellation request flag to indicate that a 
                    cancellation request was requested and accepted on this
                    CanTpConnection, in order to handle it in the next Main
                    function                                                  */
                pudtChannelResources->strRxCancelRequest.bCancellationRequest = 
                                                                           TRUE;
                
                /*! Save the ID of the RxNSdu to be cancelled                 */
                pudtChannelResources->strRxCancelRequest.udtCancelledNSduId =
                                                                   CanTpRxSduId;

                /*! Return E_OK to notify the upper layer that the request was
                    accepted and will be handled in the Main function         */
                udtReturnValue = E_OK;
            }
        }
        else
        {
            /*! If the cancellation can not be performed:                     */

            /*! If DET is enabled:                                            */
            /*! Report the corresponding DET error code then return E_NOT_OK  */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)
            CanTp_vidREPORT_DET_ERROR
                        (CanTp_u8CANCEL_RECEIVE_ID, CANTP_E_OPER_NOT_SUPPORTED);
#endif
        }
    }

    return udtReturnValue;
}

/******************************************************************************/

#if(CanTp_bCHANGE_PARAMETER_API == STD_ON)

FUNC(Std_ReturnType, CANTP_CODE) CanTp_ChangeParameter (
    VAR(PduIdType, AUTOMATIC)       id,
    VAR(TPParameterType, AUTOMATIC) parameter,
    VAR(uint16, AUTOMATIC)          value)
{
    /*! \Trace_To   CanTp-CDD-0087(0)                                         */

    VAR(uint8, AUTOMATIC)           u8Direction;
    VAR(uint8, AUTOMATIC)           u8FrameType;
    VAR(Std_ReturnType, AUTOMATIC)  udtReturnValue = E_NOT_OK;
    VAR(uint16, AUTOMATIC)          u16IndexOfResources;
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                    pudtChannelResources;


    /*! If the service was called while the CanTp is not initialized:         */
    /*! \Trace_To   CanTp-CDD-5004(0)                                         */
    if(CanTp_u8eCanTpGlobalState != CANTP_ON)
    {
        /*! If DET is enabled:                                                */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! Report the corresponding DET error code                           */
        /*! \Trace_To   CanTp-CDD-5012(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8CHANGE_PARAM_ID, CANTP_E_UNINIT);

#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
        
    }

    /*! If DET is enabled:                                                    */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

	else if(id >= CanTp_u16NUM_OF_RX_NSDUS)
	{
		/*! Report the corresponding DET error code and notify the upper layer 
            that an invalid parameter was received                            */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8CHANGE_PARAM_ID, CANTP_E_PARAM_ID);
	}

	/* !Deviation : Inhibit MISRA rule [3356]: Checking against invalid values*/
	/* !Deviation : Inhibit MISRA rule [3359]: Checking against invalid values*/
	/* !Deviation : Inhibit MISRA rule [3201]: Checking against invalid values*/

    /* PRQA S 3356 ++                                                         */
	/* PRQA S 3359 ++                                                         */
	/* PRQA S 3201 ++                                                         */

    /*! If an invalid RxNSduId is received or invalid parameter are received  */
    else if((parameter != STMIN) && (parameter != BS))

    /*! \Trace_To   CanTp-CDD-0175(0)                                         */
    {

	/* PRQA S 3356 --                                                         */
	/* PRQA S 3359 --                                                         */
	/* PRQA S 3201 --                                                         */

        /*! Report the corresponding DET error code and notify the upper layer 
            that an invalid parameter was received                            */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8CHANGE_PARAM_ID, CANTP_E_PARAM_ID);
    }
    /*! If the parameter is received with an invalid value:                   */
    else if( ((parameter == STMIN) &&
        (((value > 127) && (value < 241)) || (value > 249)))
        ||
        ((parameter == BS) && (value>255)))
    {
        /*! Report the corresponding DET error code and notify the upper layer 
            that an invalid value was received                                */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8CHANGE_PARAM_ID, CANTP_E_PARAM_ID);
    }
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    else
    {
        /*! Get the index of the CanTpConnection resources -responsible for 
            handling the reception operations- of the CanTpChannel that 
            the CanTpRxNSdu requested for parameter change belongs to         */
        u16IndexOfResources = 
        CanTp_akstreTpChannels[CanTp_akstreRxNSduPCCfg[id].u8ChannelNumber]
                                                         .u16IndexOfRxResources;

        /*! Assign the local pointer to the address of the CanTpConnection      
            resources                                                         */
        pudtChannelResources = 
                             &CanTp_astreChannelsResources[u16IndexOfResources];

        /*! Get the current direction of the CanTpConnection                  */
        u8Direction = CanTp_u8GET_DIRECTION(pudtChannelResources);

        /*! Get the type of the frame bing handled on the CanTpConnection     */
        u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

        

        /*! Check whether the change parameter request is possible or not     */
        /*! A change parameter request is not possible if the CanTpRxNSdu is
            already in a multiple frame reception process                     */

        /*! If the change parameter request is not possible:                  */
        /*! \Trace_To   CanTp-CDD-0173(0)                                     */
        if((u8Direction == CanTp_u8DIR_RX)
            && (pudtChannelResources->udtHandledNSduId == id) 
            && (u8FrameType != CanTp_u8FRAME_SF))
        {

        	/* Do nothing */

        }
        /*! If the change parameter request is possible:                      */
        /*! \Trace_To   CanTp-CDD-0176(0)                                     */
        else
        {
            /*! If the parameter is STmin:                                    */
            if(parameter == STMIN)
            {
                /*! Store the new STmin value to be used in next reception 
                    operations for this CanTpRxNSdu                           */
                CanTp_au8eCurrentSTmin[id] = (uint8)value;
            }
            /*! If the parameter is Block Size:                               */
            else
            {
                /*! Store the new Block Size value to be used in next reception 
                    operations for this CanTpRxNSdu                           */
                CanTp_au8eCurrentBlockSize[id] = (uint8)value;
            }

            /*! return E_OK                                                   */
            udtReturnValue = E_OK;            
        }
    }
   
    return udtReturnValue;

}
#endif  /* (CanTp_bCHANGE_PARAMETER_API == STD_ON) */

/******************************************************************************/

#if (CanTp_bREAD_PARAMETER_API == STD_ON)

FUNC(Std_ReturnType, CANTP_CODE) CanTp_ReadParameter(
    VAR(PduIdType, AUTOMATIC)       id,
    VAR(TPParameterType, AUTOMATIC) parameter,
    P2VAR(uint16, AUTOMATIC,AUTOMATIC)          value)
{
    return E_NOT_OK
}
#endif  /* CanTp_bREAD_PARAMETER_API == STD_ON */

/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [4700]: Metric value out of threshold range*/
/*              This function handles the reception operations sequentially   */
/*              and there is no need to divide it into multiple functions     */
/* PRQA S 4700 ++                                                             */

FUNC(void, CANTP_CODE) CanTp_vidManageRxState (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)   u8FrameType;

    /*! If a cancellation request is pending to be handled                    */
    if(pudtChannelResources->strRxCancelRequest.bCancellationRequest == TRUE)
    {
        /*! Call the function resposible for handling a cancellation requests */
        vidHandleRxCancelReq(pudtChannelResources);
    }

    /*! If a consecutive frame reception error is pending to be handled       */
    if(pudtChannelResources->strCFReceptionError.bCFReceptionError == TRUE)
    {
        /*! Call the function resposible for handling consecutive frame 
            reception  errors                                                 */
        vidHandleCFRxError(pudtChannelResources);
    }

    /*! If an unexpected PDU was received and is pending to be handled        */
    if(pudtChannelResources->strUnExpectedPdu.bUnExpPduReceived == TRUE)
    {
        /* REMINDER: ENTER CRITICAL SECTION */
        vidHandleUnExpectedPdus(pudtChannelResources);
        /* REMINDER: LEAVE CRITICAL SECTION */
    }

    /*! If the CanTpConnection is currently handling a reception operation    */
    if((CanTp_u8GET_DIRECTION(pudtChannelResources)) == CanTp_u8DIR_RX)
    {
        /*! If the reception operation being handled is "Request Buffer":     */
        if(CanTp_u8GET_OPERATION(pudtChannelResources) ==
                                                      CanTp_u8OPERATION_REQBUFF)
        {
            u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

            /*! If the frame whose buffer is to be requested is a single frame,
                a first frame, or a last consecutive frame:                   */
            if((u8FrameType == CanTp_u8FRAME_SF) || 
               (u8FrameType == CanTp_u8FRAME_FF) || 
               (u8FrameType == CanTp_u8FRAME_LAST_CF))
            {
                /*! Call the function responsible for requesting buffer for the
                    received data                                             */
                vidRequestRxBuffer(pudtChannelResources);
            }

        }
        

        /*! If the CanTpConnection is still in the phase of providing a buffer
            from the upper layer to hold the next block of data for a first
            frame or for a last consecutive frame except for the last
            consecutive frame in the message:                                 */
        if(CanTp_u8GET_OPERATION(pudtChannelResources) 
                                                   == CanTp_u8OPERATION_REQBUFF)
        {
            u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

            /*! \Trace_To   CanTp-CDD-0052(0)                                 */
            /*! \Trace_To   CanTp-CDD-0053(0)                                 */
            if((u8FrameType == CanTp_u8FRAME_FF) 
                || 
                ((u8FrameType == CanTp_u8FRAME_LAST_CF) &&
                               (pudtChannelResources->bLastFrameInMsg != TRUE)))
            {
                /*! Call the function responsible for deciding whether a wait
                    flow control is eligible for transmission or not          */
                vidCheckFcWaitTransmit(pudtChannelResources);
            }
        }

        if(CanTp_u8GET_OPERATION(pudtChannelResources) 
                                                  == CanTp_u8OPERATION_TRANSMIT)
        {
            vidTransmitFCFrame(pudtChannelResources);
        }
    }

}

/* PRQA S 4700 --                                                             */

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_vidHandleRxTimeout (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)               u8Operation;
    VAR(PduIdType, AUTOMATIC)           udtNSduIdHandled;
    VAR(NotifResultType, AUTOMATIC)     udtErrorType;

    /*! Get the current reception operation taking place on this
        CanTpConnection                                                       */
    u8Operation = CanTp_u8GET_OPERATION(pudtChannelResources);

    /*! Get the ID of the CanTpRxNSdu currently being handled                 */
    udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;

    switch(u8Operation)
    {
        /*! If the timeout occurred while trying to request a buffer from the
            upper layer:                                                      */
    case(CanTp_u8OPERATION_REQBUFF):
        /*! Report NTFRSLT_E_NOT_OK to the upper layer                        */
        /*! \Trace_To   CanTp-CDD-5026(0)                                     */
        udtErrorType = NTFRSLT_E_NOT_OK;
        break;

        /*! If the timeout occurred while waiting for a frame
            transmission confirmation, or if the timeout occurred while trying
            to re-transmit the rejected frame (only if transmission retry is
            enabled):                                                         */
    case(CanTp_u8OPERATION_WAITCONF):
#if(CanTp_bCANIF_TRANSMIT_RETRY == STD_ON)
    case(CanTp_u8OPERATION_TRANSMIT):
#endif  /* CanTp_bCANIF_TRANSMIT_RETRY == STD_ON */
        
        /*! Report NTFRSLT_E_TIMEOUT_A to the upper layer to indicate that NAr 
            timeout has occurred                                              */
        /*! \Trace_To   CanTp-CDD-5021(0)                                     */
        udtErrorType = NTFRSLT_E_TIMEOUT_A;
        break;

        /*! If the timeout occurred while waiting for a consecutive frame
            reception:                                                        */
    case(CanTp_u8OPERATION_WAITRX):
        /*! Report NTFRSLT_E_TIMEOUT_CR to the upper layer to indicate that NCr 
            timeout has occurred                                              */
        /*! \Trace_To   CanTp-CDD-0060(0)                                     */
        udtErrorType = NTFRSLT_E_TIMEOUT_CR;
        break;
    
    default:
        udtErrorType = NTFRSLT_E_NOT_OK;
        break;
    }

    /*! Abort the current reception, reset the CanTpConnection  resources,
        and notify the upper layer with the corresponding abortion reason     */
    vidStopRxChannel(pudtChannelResources, udtNSduIdHandled, udtErrorType);

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
    /*! \Trace_To   CanTp-CDD-5065(0), CanTp-CDD-5066(0), CanTp-CDD-5067(0)   */
    CanTp_vidREPORT_DET_ERROR(CanTp_u8MAIN_FUNCTION_ID, CANTP_E_RX_COM);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
}

/******************************************************************************/

FUNC(boolean, CANTP_CODE) CanTp_bHandleNewReception (
    /* !Deviation : Inhibit MISRA rule [3673]: AutoSAR Mandatory interfaces.  */
    /*              Data is provided from the lower layer as variables and not*/
    /*              constants, and will be passed to the upper layer using    */
    /*              another mandatory AutoSAR interface as variables and not  */
    /*              constants                                                 */
    /* PRQA S 3673 ++                                                         */
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)      pudtPduInfoPtr,
    /* PRQA S 3673 --                                                         */
    VAR(PduIdType, AUTOMATIC)                           udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                        pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)       u8Direction;
    VAR(boolean, AUTOMATIC)     bReturnvalue = FALSE;
    VAR(PduIdType, AUTOMATIC)   udtNSduIdHandled;
    VAR(uint8_least, AUTOMATIC)       u8LoopIndex;

    u8Direction = CanTp_u8GET_DIRECTION(pudtChannelResources);

    /*! If no un-expected PDUs, consecutive frame reception erros, cancellation
        requests for the same CanTpRxNSdu are pending to be handled in the next
        Main function call:                                                   */
    if((pudtChannelResources->strUnExpectedPdu.bUnExpPduReceived != TRUE) && 
        (pudtChannelResources->strCFReceptionError.bCFReceptionError != TRUE)
        &&
        ((pudtChannelResources->strRxCancelRequest.bCancellationRequest 
                == FALSE) || 
                (pudtChannelResources->strRxCancelRequest.udtCancelledNSduId != 
                                                                  udtRxNSduId)))
    {
        /*! If the CanTpConnection state is IDLE:                             */
        /*! \Trace_To   CanTp-CDD-5039(0), CanTp-CDD-5040(0)                  */
        /*! \Trace_To   CanTp-CDD-5046(0), CanTp-CDD-5047(0)                  */
        if(u8Direction == CanTp_u8DIR_IDLE)
        {
            /*! Return TRUE to indicate that the new reception can be handled */
            bReturnvalue = TRUE;
        }
        /*! If the CanTpConnection is currently handling a reception
            operation:                                                        */
        else if(u8Direction == CanTp_u8DIR_RX)
        {
            /*! If the CanTpConnection is handling the same CanTpRxNSdu:      */
            /*! \Trace_To   CanTp-CDD-5152(0), CanTp-CDD-0108(0)              */
            udtNSduIdHandled = pudtChannelResources->udtHandledNSduId;
            if(udtNSduIdHandled == udtRxNSduId)
            {
                /*! Set the new received PDU as an un-expected PDU in order to
                    be handled on the next main function call                 */
                pudtChannelResources->strUnExpectedPdu.bUnExpPduReceived = TRUE;
                pudtChannelResources->strUnExpectedPdu.udtRxNSduId =
                                                                    udtRxNSduId;
                pudtChannelResources->strUnExpectedPdu.u8UnExpectedPduLen = 
                                               (uint8)pudtPduInfoPtr->SduLength;

                for(u8LoopIndex = 0; u8LoopIndex < pudtPduInfoPtr->SduLength;
                                                                  u8LoopIndex++)
                {
                    pudtChannelResources->strUnExpectedPdu.
                        au8UnExpectedPdu[u8LoopIndex] = 
                                        pudtPduInfoPtr->SduDataPtr[u8LoopIndex];
                }
            }
        }
        /*! If the CanTpConnection is currently handling a transmission
            operation:                                                        */
        else
        {
            /*! Do nothing                                                    */
        }
    }

    return bReturnvalue;
}

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_vidHandleSingleFrame (
    /* !Deviation : Inhibit MISRA rule [3673]: AutoSAR Mandatory interfaces.  */
    /*              Data is provided from the lower layer as variables and not*/
    /*              constants, and will be passed to the upper layer using    */
    /*              another mandatory AutoSAR interface as variables and not  */
    /*              constants                                                 */
    /* PRQA S 3673 ++                                                         */
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)         pudtPduInfoPtr,
    /* PRQA S 3673 --                                                         */
    VAR(PduIdType, AUTOMATIC)                              udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)       u8MaxLength;
    VAR(uint8, AUTOMATIC)       u8StartByteLocation;
    VAR(uint8, AUTOMATIC)       u8PciByteLocation;
    VAR(uint8, AUTOMATIC)       u8SFDataLength;

    /*! If the addressing format of the CanTpRxNSdu is configured as standard
        addressing:                                                           */
    if(CanTp_akstreRxNSduPCCfg[udtRxNSduId].u8RxAddressingFormat 
                                                 == CanTp_u8STANDARD_ADDRESSING)
    {
        /*! The first data byte is located at the second byte of the frame    */
        u8StartByteLocation = CanTp_u8STD_SF_DATA_BYTE;
        
        /*! The PCI byte is located at the first byte of the frame            */
        u8PciByteLocation = CanTp_u8STD_SF_PCI_BYTE;

        /*! The frame can hold up to 7 data bytes                             */
        u8MaxLength = CanTp_u8STD_SF_DATA_LENGTH;
    }
    /*! If the addressing format of the CanTpRxNSdu is configured as extended
        or mixed addressing:                                                  */
    else
    {
        /*! The first data byte is located at the third byte of the frame     */
        u8StartByteLocation = CanTp_u8STD_SF_DATA_BYTE + 1;

        /*! The PCI byte is located at the second byte of the frame           */
        u8PciByteLocation = CanTp_u8STD_SF_PCI_BYTE + 1;

        /*! The frame can hold up to 6 data bytes                             */
        u8MaxLength = CanTp_u8STD_SF_DATA_LENGTH - 1;
    }
    
    /*! Read the single frame data length located at the lower nibble of the
        PCI byte                                                              */
    /*! \Trace_To   CanTp-CDD-5081(0)                                         */
        
    u8SFDataLength =
         pudtPduInfoPtr->SduDataPtr[u8PciByteLocation] & CanTp_u8SF_PCI_DL_MASK;

    /*! Check that the length of the PDU received is valid                    \n
        It can be invalid if one of the following cases occurs:               \n
        -The single frame data length exceeds the number of data bytes that the
         frame can hold.                                                      \n
        -The single frame data length is 0.                                   \n
        -The single frame data length is less than the min. length configured
         for this CanTpRxNSdu                                                 \n
        -If padding is enabled for this CanTpRxNSdu and the frame data length
         code is not 8.                                                       \n
        -If padding is disabled and the frame data length code is not consistent
         with the single frame data length                                    */
    
    /*! \Trace_To   CanTp-CDD-5156(0), CanTp-CDD-0259(0)                      */
    if(
        (u8SFDataLength > u8MaxLength)
        ||
        (u8SFDataLength == 0)
        ||
        ((uint16)u8SFDataLength < 
                       CanTp_akstreRxNSduPCCfg[udtRxNSduId].u16RxDataLengthCode)
        ||
        ((CanTp_akstreRxNSduPCCfg[udtRxNSduId].u8RxPaddingActivation 
                     == CanTp_u8PADDING_ON) && (pudtPduInfoPtr->SduLength != 8))
        ||
        ((CanTp_akstreRxNSduPCCfg[udtRxNSduId].u8RxPaddingActivation
                           == CanTp_u8PADDING_OFF) && (pudtPduInfoPtr->SduLength
                                    != (u8SFDataLength + u8StartByteLocation))))
    {
        /*! If the length of the PDU is invalid ignore the received PDU       */

        /*! If DET is enabled:                                                */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! Report the corresponding DET error code                           */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8RX_INDICATION_ID,
                                                     CANTP_E_INVALID_RX_LENGTH);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /*! Set the message length with the single frame data length          */
        pudtChannelResources->u16MessageLength = u8SFDataLength;

        /*! Copy the single frame data bytes to the local buffer to be provided
            to the upper layer in the next Main function call                 */
        
        CanTp_vidMemoryCopy(&(pudtPduInfoPtr->SduDataPtr[u8StartByteLocation]),
                  pudtChannelResources->au8LocalDataBuffer, u8SFDataLength); 

        pudtChannelResources->u8BytesInLocalBuffer = u8SFDataLength;
        
        /*! Set the TimeoutCounter with NBr timeout value                     */
        /*! \note   An additional cycle is added to the timeout value if the
                    request is issued from CanTp_RxIndication context while the 
                    timout calculations and handling is performed in the Main
                    function call. While in case of un-expected PDU arrival the
                    request is issued from the Main function so there is no
                    need to add the additional cycle                          */
        /*! \Trace_To   CanTp-CDD-5024(0)                                     */
        if(pudtChannelResources->strUnExpectedPdu.bUnExpPduReceived == TRUE)
        {
            pudtChannelResources->u16TimeoutCounter = 
                   CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtRxNSduId].u16NBr;
        }
        else
        {
            pudtChannelResources->u16TimeoutCounter = 
               CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtRxNSduId].u16NBr + 1;
        }

        /*! Set the CanTpConnectionState to CanTp_u8RX_REQBUFF_SF             */
        pudtChannelResources->udtHandledNSduId = udtRxNSduId;
        pudtChannelResources->u8ConnectionState = CanTp_u8RX_REQBUFF_SF;
    }
}

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_vidHandleFirstFrame (
    /* !Deviation : Inhibit MISRA rule [3673]: AutoSAR Mandatory interfaces.  */
    /*              Data is provided from the lower layer as variables and not*/
    /*              constants, and will be passed to the upper layer using    */
    /*              another mandatory AutoSAR interface as variables and not  */
    /*              constants                                                 */
    /* PRQA S 3673 ++                                                         */
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)         pudtPduInfoPtr,
    /* PRQA S 3673 --                                                         */
    VAR(PduIdType, AUTOMATIC)                              udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)       u8FirstFrameDataLength;
    VAR(uint8, AUTOMATIC)       u8StartByteLocation;
    VAR(uint8, AUTOMATIC)       u8FirstPciByteLocation;
    VAR(uint16, AUTOMATIC)      u16TotalMsgLength;
    VAR(uint16, AUTOMATIC)      u16MSDataLenByte;

    /*! If the addressing format of the CanTpRxNSdu is configured as standard
        addressing:                                                           */
    if(CanTp_akstreRxNSduPCCfg[udtRxNSduId].u8RxAddressingFormat
                                                 == CanTp_u8STANDARD_ADDRESSING)
    {
        /*! The first data byte is located at the third byte of the frame     */
        u8StartByteLocation = CanTp_u8STD_FF_DATA_BYTE;

        /*! The first PCI byte is located at the first byte of the frame      */
        u8FirstPciByteLocation = CanTp_u8STD_FF_PCI_BYTE;

        /*! The frame can hold up to 6 data bytes                             */
        u8FirstFrameDataLength = CanTp_u8STD_FF_DATA_LENGTH;
    }
    /*! If the addressing format of the CanTpRxNSdu is configured as extended
        or mixed addressing:                                                  */
    else
    {
        /*! The first data byte is located at the fourth byte of the frame    */
        u8StartByteLocation = CanTp_u8STD_FF_DATA_BYTE + 1;

        /*! The first PCI byte is located at the second byte of the frame     */
        u8FirstPciByteLocation = CanTp_u8STD_FF_PCI_BYTE + 1;

        /*! The frame can hold up to 5 data bytes                             */
        u8FirstFrameDataLength = CanTp_u8STD_FF_DATA_LENGTH - 1;
    }
    
    /*! Get the total message length from the specified location in the frame
        received (low nibble of the 1st PCI byte in addition to the 2nd PCI
        byte                                                                  */
    /*! \Trace_To   CanTp-CDD-5074(0)                                         */
    u16MSDataLenByte = pudtPduInfoPtr->SduDataPtr[u8FirstPciByteLocation];

    u16TotalMsgLength = (((u16MSDataLenByte) << 8)
                        & CanTp_u16FF_PCI_DL_H_MASK)
                        | 
                        ((uint16)(pudtPduInfoPtr->SduDataPtr
                                                [u8FirstPciByteLocation + 1]) 
                                                   & CanTp_u16FF_PCI_DL_L_MASK);

    /*! Check that the length of the PDU received is valid                    \n
        It can be invalid if one of the following cases occurs:               \n
        -The frame data length code is not 8                                  \n
        -The Total message length is less than 8 bytes in case of standard
         addressing                                                           \n
        -The Total message length is less than 7 bytes in case of extended
         or mixed addressing                                                  */
    /*! \Trace_To   CanTp-CDD-0264(0)                                         */
    if((pudtPduInfoPtr->SduLength != 8)
        ||
        (u16TotalMsgLength < (u8FirstFrameDataLength + 2)))
    {
        /*! If the length of the PDU is invalid ignore the received PDU       */

        /*! If DET is enabled:                                                */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)
        /*! Report the corresponding DET error code                           */
        /*! \Trace_To   CanTp-CDD-5061(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8RX_INDICATION_ID,
                                                     CANTP_E_INVALID_RX_LENGTH);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */        
    }
    /*! If the target address type of the CanTpRxNSdu is configured as
        functional addressing (as it is not allowed to perform multiple frame
        reception operations for functional addressing NSdus:                 */
    else if(CanTp_akstreRxNSduPCCfg[udtRxNSduId].u8RxTaType 
                                                  == CanTp_u8FUNCTIONAL_ADDRESS)
    {
        /*! If DET is enabled:                                                */
#if(CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! Report the corresponding DET error code                           */
        /*! \Trace_To   CanTp-CDD-5100(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8RX_INDICATION_ID,
                                                        CANTP_E_INVALID_TATYPE);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */        
    }
    else
    {
        /*! Set the message length with the total message length extracted from
            the first frame PCI bytes                                         */
        pudtChannelResources->u16MessageLength = u16TotalMsgLength;

        /*! Copy the first frame data bytes to the local buffer to be provided
            to the upper layer in the next Main function call                 */
        CanTp_vidMemoryCopy(&(pudtPduInfoPtr->SduDataPtr[u8StartByteLocation]),
                                   pudtChannelResources->au8LocalDataBuffer,
                                                    u8FirstFrameDataLength);

        pudtChannelResources->u8BytesInLocalBuffer = u8FirstFrameDataLength;
        
        /*! Set the TimeoutCounter with NBr timeout value                     */
        /*! \note   An additional cycle is added to the timeout value if the
                    request is issued from CanTp_RxIndication context while the 
                    timout calculations and handling is performed in the Main
                    function call. While in case of un-expected PDU arrival the
                    request is issued from the Main function so there is no
                    need to add the additional cycle                          */
        /*! \Trace_To   CanTp-CDD-5158(0)                                     */
        if(pudtChannelResources->strUnExpectedPdu.bUnExpPduReceived == TRUE)
        {
            pudtChannelResources->u16TimeoutCounter = 
                   CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtRxNSduId].u16NBr;
        }
        else
        {
            pudtChannelResources->u16TimeoutCounter = 
               CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtRxNSduId].u16NBr + 1;
        }

        /*! Set the CanTpConnectionState to CanTp_u8RX_REQBUFF_FF             */
        pudtChannelResources->u8ConnectionState = CanTp_u8RX_REQBUFF_FF;
        pudtChannelResources->udtHandledNSduId = udtRxNSduId;
    }
}

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_vidHandleConsecFrame (
    /* !Deviation : Inhibit MISRA rule [3673]: AutoSAR Mandatory interfaces.  */
    /*              Data is provided from the lower layer as variables and not*/
    /*              constants, and will be passed to the upper layer using    */
    /*              another mandatory AutoSAR interface as variables and not  */
    /*              constants                                                 */
    /* PRQA S 3673 ++                                                         */
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)         pudtPduInfoPtr,
    /* PRQA S 3673 --                                                         */
    VAR(PduIdType, AUTOMATIC)                              udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pudtChannelResources)
{
    VAR(uint8, AUTOMATIC)       u8StartByteLocation;
    VAR(uint8, AUTOMATIC)       u8PciByteLocation;
    VAR(uint8, AUTOMATIC)       u8FrameType;
    VAR(uint8, AUTOMATIC)       u8CFDataLength;
    VAR(boolean, AUTOMATIC)     bProceedHandling;

    /*! If the CanTpConnection state is currently waiting for the reception
        of a consecutive or last consecutive frame for this CanTpRxNSu, and
        there are no consecutive frame reception errors or cancellation
        requests to be handled in the next Main function call:                */
    /*! \Trace_To   CanTp-CDD-5038(0),  CanTp-CDD-5045(0)                     */

    if(((pudtChannelResources->u8ConnectionState == CanTp_u8RX_WAITRX_CF) ||
        (pudtChannelResources->u8ConnectionState == CanTp_u8RX_WAITRX_LAST_CF)) 
        &&
        (pudtChannelResources->udtHandledNSduId == udtRxNSduId)
        &&
        (pudtChannelResources->strCFReceptionError.bCFReceptionError != TRUE)
        &&
        (pudtChannelResources->strRxCancelRequest.bCancellationRequest != TRUE))
    {
    /*! If the addressing format of the CanTpRxNSdu is configured as standard
        addressing:                                                           */
        if(CanTp_akstreRxNSduPCCfg[udtRxNSduId].u8RxAddressingFormat 
                                                 == CanTp_u8STANDARD_ADDRESSING)
        {
            /*! The first data byte is located at the second byte of the frame*/
            u8StartByteLocation = CanTp_u8STD_CF_DATA_BYTE;
            
            /*! The PCI byte is located at the first byte of the frame        */
            u8PciByteLocation = CanTp_u8STD_CF_PCI_BYTE;

            /*! The frame can hold up to 7 data bytes                         */
            u8CFDataLength = CanTp_u8STD_CF_DATA_LENGTH;
        }
    /*! If the addressing format of the CanTpRxNSdu is configured as extended
        or mixed addressing:                                                  */
        else
        {
            /*! The first data byte is located at the third byte of the frame */
            u8StartByteLocation = CanTp_u8STD_CF_DATA_BYTE + 1;

            /*! The PCI byte is located at the second byte of the frame       */
            u8PciByteLocation = CanTp_u8STD_CF_PCI_BYTE + 1;

            /*! The frame can hold up to 6 data bytes                         */
            u8CFDataLength = CanTp_u8STD_CF_DATA_LENGTH - 1; 
        }

        /*! Call the function responsible for checking that the consecutive
            frame has no errors                                               */
        bProceedHandling = bCheckCFErrors(pudtPduInfoPtr, udtRxNSduId,
									pudtChannelResources, u8PciByteLocation);

        /*! If no errors were deteced in the consecutive frame:               */
        if(bProceedHandling == TRUE)
        {
            u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

            /*! Decrement the number of frames remaining to be received in the
                current block                                                 */
            /*! \Trace_To   CanTp-CDD-5076(0)                                 */
            pudtChannelResources->u16BlockSize--;

            /*! If the frame is a consecutive frame:                          */
            if(u8FrameType == CanTp_u8FRAME_CF)
            {
                pudtChannelResources->u8ConnectionState = 
                                                          CanTp_u8RX_REQBUFF_CF;

                /*! Call the function responsible for providing the consecutive
                    frame data bytes to the upper layer                       */
                vidCopyConsecutiveFrame(&(pudtPduInfoPtr->SduDataPtr
                        [u8StartByteLocation]), udtRxNSduId, 
										pudtChannelResources, u8CFDataLength );
                

                /*! Set the TimeoutCounter with NCr timeout value             */
                /*! \note   An additional cycle was added to the timeout value
                            because the request is issued from
                            CanTp_RxIndication() context while the timout
                            calculations and handling is performed in the
                            Main function call                                */

                /*! \Trace_To   CanTp-CDD-5140(0)                             */
                pudtChannelResources->u16TimeoutCounter = 
                    CanTp_pkstreGlobalConfig->pkstrRxNSduCfg
                                                       [udtRxNSduId].u16NCr + 1;
            }
            /*! If the frame is last consecutive frame:                       */
            else
            {
                /*! Set CanTpConnection state to CanTp_u8RX_REQBUFF_LAST_CF in
                    order to handle the last consecutive frame copying in the
                    next Main function                                        */
                pudtChannelResources->u8ConnectionState = 
                                                     CanTp_u8RX_REQBUFF_LAST_CF;

                /*! Set the TimeoutCounter with NBr timeout value             */
                /*! \note   An additional cycle was added to the timeout value
                            because the request is issued from
                            CanTp_RxIndication() context while the timout
                            calculations and handling is performed in the
                            Main function call                                */
                /*! \Trace_To   CanTp-CDD-5159(0)                             */
                pudtChannelResources->u16TimeoutCounter = 
                    CanTp_pkstreGlobalConfig->pkstrRxNSduCfg
                                                       [udtRxNSduId].u16NBr + 1;

                if(pudtChannelResources->u16MessageLength < u8CFDataLength)
                {
                    u8CFDataLength = 
                                  (uint8)pudtChannelResources->u16MessageLength;
                }
                
                /*! Copy the last consecutive frame data bytes to the local
                    buffer to be provided to the upper layer in the next Main
                    function call                                             */
                CanTp_vidMemoryCopy(
                    &(pudtPduInfoPtr->SduDataPtr[u8StartByteLocation]),
                      pudtChannelResources->au8LocalDataBuffer, u8CFDataLength);

                pudtChannelResources->u8BytesInLocalBuffer = u8CFDataLength;
            }
        }

    }
    /*! If an error was deteced in the consecutive frame:                     */
    else
    {
        /*! Ignore the frame                                                  */
    }
}

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_vidConfHandlerRx (
    VAR(PduIdType, AUTOMATIC) udtNSduId)
{
    VAR(uint8, AUTOMATIC)               u8FrameType;
    VAR(uint16, AUTOMATIC)              u16IndexOfResources;
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                        pudtChannelResources;

    /*! Get the index of the CanTpConnection resources -responsible for 
        handling the reception operations- of the CanTpChannel that the 
        CanTpRxNSdu belongs to                                                */
    u16IndexOfResources = 
        CanTp_akstreTpChannels[CanTp_akstreRxNSduPCCfg
                             [udtNSduId].u8ChannelNumber].u16IndexOfRxResources;

    /*! Assign the local pointer to the address of the CanTpConnection 
        resources                                                             */
    pudtChannelResources = &CanTp_astreChannelsResources[u16IndexOfResources];

    

    /*! Get the frame type                                                    */
    u8FrameType = CanTp_u8GET_FRAME_TYPE(pudtChannelResources);

    /*! \Trace_To   CanTp-CDD-5023(0)                                         */

    switch(u8FrameType)
    {
        /*! If a transmission confirmation is received for the transmitted
            "Clear To Send" flow control:                                     */
    case(CanTp_u8FRAME_FC_CTS):

        /*! Set the TimeoutCounter with NCr timeout value                     */
        /*! \note   An additional cycle was added to the timeout value because
                    the confirmation is received in CanTp_TxConfirmation
                    context while the timout calculations and handling is
                    performed in the Main function call                       */
        /*! \Trace_To   CanTp-CDD-5141(0), CanTp-CDD-5036(0)                  */
        pudtChannelResources->u16TimeoutCounter = 
                CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtNSduId].u16NCr + 1;

        /*! If the next block consists of only 1 consecutive frame:           */
        if(pudtChannelResources->u16BlockSize == 1)
        {
            /*! Set CanTpConnection state to CanTp_u8RX_WAITRX_LAST_CF        */
            pudtChannelResources->u8ConnectionState =
                                                      CanTp_u8RX_WAITRX_LAST_CF;
            
            /*! Check if the last consecutive frame is the last consecutive
                frame in the message                                          */
            pudtChannelResources->bLastFrameInMsg = 
                CanTp_bIsNextFrameLastInMsg(CanTp_u8DIR_RX,
                                                udtNSduId, pudtChannelResources);
        }
        /*! If the next block consists of more than 1 consecutive frame:      */
        else
        {
            /*! Set CanTpConnection state to CanTp_u8RX_WAITRX_CF             */
            pudtChannelResources->u8ConnectionState =
                                                           CanTp_u8RX_WAITRX_CF;
        }
        break;

        /*! If a transmission confirmation is received for the transmitted
            "Wait" flow control:                                              */
    case(CanTp_u8FRAME_FC_WAIT):
        if(pudtChannelResources->bFirstFrameReceived == TRUE)
        {
            pudtChannelResources->u8ConnectionState =
                                                     CanTp_u8RX_REQBUFF_LAST_CF;
        }
        else
        {
            pudtChannelResources->u8ConnectionState =
                                                          CanTp_u8RX_REQBUFF_FF;
        }

        /*! Set the TimeoutCounter with NBr timeout value                     */
        /*! \note   An additional cycle was added to the timeout value because
                    the confirmation is received in CanTp_TxConfirmation
                    context while the timout calculations and handling is
                    performed in the Main function call                       */
        pudtChannelResources->u16TimeoutCounter = 
                 CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[udtNSduId].u16NBr + 1;
        break;
        
    default:
        break;
    }
}

#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/* PRQA L:L1                                                                  */

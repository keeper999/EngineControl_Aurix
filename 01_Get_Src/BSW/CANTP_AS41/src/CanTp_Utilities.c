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
/* !File            : CanTp_Utilities.c                                       */
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
/* $Revision::   1.4      $$Author::   mamroussy      $$Date::   Feb 04 2013 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/******************************************************************************/
/*! \file CanTp_Utilities.c
*
* \par
*   This file contains the implementation of the Utilities sub-component.     \n
    The Utilities sub-component contains common utility services that are
    used by the Main, Reception, and Transmission sub-components.             */
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



/******************************************************************************/
/* GLOBAL FUNCTIONS DEFINITION                                                */
/******************************************************************************/

#define CANTP_START_SEC_CODE
#include "MemMap.h"

FUNC(void, CANTP_CODE) CanTp_vidInitChannelResources (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                           pstrChannelResources)
{

    /*! Initialize CanTpConnection resources                                  */
    pstrChannelResources->u16MessageLength = 0;
    pstrChannelResources->udtHandledNSduId = 0;
    pstrChannelResources->u16TimeoutCounter = 0;
    pstrChannelResources->u8BytesInLocalBuffer =0;
    pstrChannelResources->u16BlockSize = 0;
    pstrChannelResources->u8SequenceNumber = 0;
    pstrChannelResources->bLastFrameInMsg = FALSE;
#if (CanTp_bCANIF_TRANSMIT_RETRY == STD_ON)
    pstrChannelResources->bFirstTransmitRetry = TRUE;
#endif  /* CanTp_bCANIF_TRANSMIT_RETRY == STD_ON */

    
    pstrChannelResources->u16STminTimeoutValue = 0;    
    pstrChannelResources->bSTminPassed = FALSE;

    pstrChannelResources->bBufferAllocated = FALSE;
    pstrChannelResources->u8NumOfFCWaitFrames = 0;
    pstrChannelResources->bFirstFrameReceived = FALSE;
#if (CanTp_bDYNAMIC_RX_BLOCKSIZE == STD_ON)
    pstrChannelResources->bFCWithZeroBS = FALSE;
#endif

    pstrChannelResources->u8ConnectionState = CanTp_u8IDLE_STATE;
}

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_vidMemoryCopy (
    P2CONST(uint8, AUTOMATIC, CANTP_APPL_DATA)  pku8Source,
    P2VAR(uint8, AUTOMATIC, CANTP_VAR)   pu8Destination,
    VAR(uint8, AUTOMATIC)   u8Length)
{
    VAR(uint8_least, AUTOMATIC) u8LocalIndex;

    /*! Copy the data bytes from the source buffer to the destination buffer  */
    for(u8LocalIndex=0;u8LocalIndex<u8Length;u8LocalIndex++)
    {
        pu8Destination[u8LocalIndex] = pku8Source[u8LocalIndex];
    }
}

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_vidPadTxBuffer (
    VAR(uint8, AUTOMATIC) u8StartByte,
    P2VAR(uint8, AUTOMATIC, CANTP_VAR) pu8TxBuffer)
{
    VAR(uint8_least, AUTOMATIC)   u8LoopCounter;

    /*! Pad the remaining bytes of the 8-bytes buffer with the value defined by
        the configuration parameter CanTp_u8PADDING_BYTE                      */
    for(u8LoopCounter=u8StartByte; u8LoopCounter<8; u8LoopCounter++)
    {
        pu8TxBuffer[u8LoopCounter] = CanTp_u8PADDING_BYTE;
    }
}

/******************************************************************************/

FUNC(boolean, CANTP_CODE) CanTp_bIsNextFrameLastInMsg (
    VAR(uint8, AUTOMATIC)       u8Direction,
    VAR(PduIdType, AUTOMATIC)   udtNSduId,
	P2CONST(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
														pkstrChannelResources)
{
    VAR(uint8, AUTOMATIC)   u8CFDataLength;
    VAR(boolean, AUTOMATIC) bReturnValue;
    VAR(uint8, AUTOMATIC)   u8AddressingFormat;

    /*! Get the addressing format of the CanTpTxNSdu being handled            */
    if(u8Direction == CanTp_u8DIR_RX)
    {
        u8AddressingFormat = 
                        CanTp_akstreRxNSduPCCfg[udtNSduId].u8RxAddressingFormat;
    }
    else
    {
        u8AddressingFormat = 
                        CanTp_akstreTxNSduPCCfg[udtNSduId].u8TxAddressingFormat;
    }

    /*! If the CanTpTxNSdu is configured with standard addressing:            */
    if(u8AddressingFormat == CanTp_u8STANDARD_ADDRESSING)
    {
        /*! The consecutive frame can hold up to 7 bytes                      */
        u8CFDataLength = CanTp_u8STD_CF_DATA_LENGTH;
    }
    /*! Else If the CanTpTxNSdu is configured with extended or mixed
        addressing:                                                           */
    else
    {
        /*! The consecutive frame can hold up to 6 bytes                      */
        u8CFDataLength = CanTp_u8STD_CF_DATA_LENGTH - 1;
    }

    /*! If the remaining message bytes are more than the number of bytes that
        the consecutive frame can hold:                                       */
    if(pkstrChannelResources->u16MessageLength > u8CFDataLength)
    {
        /*! Return FALSE                                                      */
        bReturnValue = FALSE;
    }
    /*! Else If the remaining message bytes are less than or equal to the
        number of bytes that the consecutive frame can hold:                  */
    else
    {
        /*! Return TRUE                                                       */
        bReturnValue = TRUE;
    }

    return bReturnValue;
}

#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/* PRQA L:L1                                                                  */
/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR component                     */
/*                                                                            */
/*!Module          : LinIf_LinTransportProtocol                              */
/*!Description     : Implements the LinTp                                    */
/*                                                                            */
/*!\File             LinIf_LinTransportProtocol.c                            */
/* \par              Implements the LinTp                                    */
/*!Scope           : Private                                                 */
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
/* $Revision::   1.29     $$Author::   MTAYMOUR       $$Date::   Mar 30 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/


/*!Deviation : Inhibit MISRA rule [0838]: Multiple Inclusion prevention       */
/*              macros solve this issue                                       */
/* PRQA S 0838 L1                                                             */
/*!Deviation : Inhibit MISRA rule [2215]: Indentation problem is caused by    */
/*              Compiler abstraction macros                                   */
/* PRQA S 2215 L1                                                             */
/*!Deviation : Inhibit MISRA rule [0850]: The value for the macros are        */
/*              redefined in the QAC for comptability with ANSI C             */
/* PRQA S 0850 L1                                                             */
/*!Deviation : Inhibit MISRA rule [0862]: The MemMap.h is used to assign      */
/*              memory segments                                               */
/* PRQA S 0862 L1                                                             */
/*!Deviation : Inhibit MISRA rule [0857]: Most of the macros are defined in   */
/*              Compiler_Cfg file                                             */
/* PRQA S 0857 L1                                                             */
/*!Deviation : Inhibit MISRA rule [5087]: The value for the macros are        */
/*              non preprocessor directives  					   		      */
/* PRQA S 5087 L1                                                             */
#include "LinIf_Cfg.h"
 
#include "LinIf_Lcfg.h"
#include "LinIf_LinTransportProtocol.h"
#include "LinIf_Main.h"
#include "LinIf.h"
#include "BswM.h"

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#include "LinIf_DetErrors.h"
#endif

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/*!\Description    The NAD which functional requests shall be sent \n        */
#define u8FUNCTIONAL_NAD                0x7E
/*!\Description    The NAD which broadcast requests shall be sent  \n        */
#define u8BROADCAST_NAD                 0x7F
/*!\Description    That Maximum data length in a single frame (SF) \n        */
#define u8MAX_SIN_F_DATA_LEN            0x06
/*!\Description    That data length in a first frame (FF) \n                 */
#define u8FF_DATA_LENGTH                0x05
/*!\Description    That Maximum data length in a consecutive frame (CF) \n   */
#define u8MAX_CON_F_DATA_LEN            0x06

#define u16MAX_MSG_LEN                  0x0FFF


#define u8SINGLE_FRAME_TYPE             0x00
#define u8FIRST_FRAME_TYPE              0x01
#define u8CONSEC_FRAME_TYPE             0x02

/*!\Description    The first 4 bits in the PCI of a CF \n                    */
#define u8PCI_BASE_CONSEC_F             0x20
/*!\Description    The first 4 bits in the PCI of a SF \n                    */
#define u8PCI_BASE_SINGLE_F             0x00
/*!\Description    The first 4 bits in the PCI of a FF \n                    */
#define u8PCI_BASE_FIRST_F              0x10
/*!\Description    The padding byte to be added to fill an incomplete SF 
                    or CF\n                                                   */
#define u8PADDING_BYTE                  0xFFU


/*!\Description    The maximum sequence number in a CF \n                    */
#define u8MAX_SEQ_NUM                   15

/*!\Description    The TP channel comm. state IDLE \n                        */
#define u8TP_STATE_IDLE                 0
/*!\Description    The TP channel comm. state TRANSMIT \n                    */
#define u8TP_STATE_TRANS                1
/*!\Description    The TP channel comm. state RECEIVE \n                     */
#define u8TP_STATE_REC                  2

/*!\Description    The TP channel state UNINIT \n                            */
#define u8TP_CHANNEL_UNINIT             0
/*!\Description    The TP channel state IDLE \n                              */
#define u8TP_CHANNEL_IDLE               1
/*!\Description    The TP channel state BUSY \n                              */
#define u8TP_CHANNEL_BUSY               2

/*!\Description    A mask to get the higher 4 bits of a byte \n              */
#define u8HIGH_4_BIT_MASK               (uint8)0xF0
/*!\Description    A mask to check if the message is a TX TP message or not\n*/
#define u8TXTPMASK                      (uint8)0x60

/*!\Description    Value to indicate that there is no Tx timeout currently 
                   running  \n                                               */
#define u8TIMEOUT_NONE                  0
/*!\Description    Value to indicate that N_As Tx timeout is currently 
                   running  \n                                               */
#define u8TIMEOUT_AS                    1
/*!\Description    Value to indicate that N_Cs Tx timeout is currently 
                   running  \n                                               */
#define u8TIMEOUT_CS                    2

#if(LinIf_u8TP_SUPPORTED == STD_ON)



/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/*!\Description    Errors that can be found in a CF \n                       */
/*  \Range          */
typedef uint8 tu8CFrameErrType;
/*!\Description    No CF Error Found \n                                      */
#define u8CF_E_OK                       0
/*!\Description    Wrong NAD in CF found \n                                  */
#define u8CF_E_NAD                      1
/*!\Description    Wrong SN in CF found \n                                   */
#define u8CF_E_SN                       2

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define LINIF_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"
/*!\Description    Pointer to the LinTp Post-Build configuration structure \n*/
static P2CONST(LinTp_ConfigType, LINIF_VAR, LINIF_APPL_CONST) 
                                                        pkstrGlobalTPConfigPtr;

#define LINIF_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

#define LINIF_START_SEC_VAR_8
#include "Memmap.h"

/*!\Description    The state of the LinTransportProtocol Sub-Component \n
    \Range          LinIf_u8STATE_UNINIT, LinIf_u8STATE_INIT \n               */
static VAR(uint8, LINIF_VAR) LinIf_u8LinTpState = LinIf_u8STATE_UNINIT;

#define LINIF_STOP_SEC_VAR_8
#include "Memmap.h"

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
#endif

#define LINIF_START_SEC_CODE
#include "Memmap.h"

#if(LinIf_u8TP_SUPPORTED == STD_ON)
static FUNC(void, LINIF_CODE) vidCopyFrame(
    P2CONST(uint8, AUTOMATIC, LINIF_VAR) pku8Source,
    P2VAR(uint8, AUTOMATIC, LINIF_VAR) pu8Dest,
    VAR(uint8, AUTOMATIC) u8Length);

static FUNC(Std_ReturnType, LINIF_CODE) udtValidateNewRxMsg(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) pu16MessageLength);

static FUNC(Std_ReturnType, LINIF_CODE) udtSetupRxMsg(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) pu16AvailableBufferLen);

static FUNC(uint16, LINIF_CODE) u16GetMsgLenFromBuffer(
    P2CONST(uint8, AUTOMATIC, LINIF_VAR) pku8DataBuffer);


static FUNC(uint8, LINIF_CODE) u8CopyTpDataFromFrame(
    VAR(uint8, AUTOMATIC) u8ChannelIndex);


static FUNC(Std_ReturnType, LINIF_CODE) udtPrepareTpTxFrame(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    VAR(uint8, AUTOMATIC) u8DataLength,
    VAR(PduLengthType, AUTOMATIC) udtTPMessageLength,
    VAR(uint8, AUTOMATIC) u8FrameType);


static FUNC(void, LINIF_CODE) vidStopCurrRxMsg(
    VAR(uint8, AUTOMATIC)           u8ChannelIndex,
    VAR(NotifResultType, AUTOMATIC) udtReason,
    VAR(boolean, AUTOMATIC)         bResetTimer);

static FUNC(Std_ReturnType, LINIF_CODE) udtDeliverRxFrame(
    VAR(uint8, AUTOMATIC)   u8ChannelIndex,
    VAR(uint8, AUTOMATIC)   u8DataLength,
    VAR(boolean, AUTOMATIC) bTestBuffer);


static FUNC(void, LINIF_CODE) vidHandleCFRec(
    VAR(uint8, AUTOMATIC) u8ChannelIndex);


static FUNC(tu8CFrameErrType, LINIF_CODE) udtValidateCF(
    VAR(uint8, AUTOMATIC) u8ChannelIndex);

static FUNC(boolean, LINIF_CODE) bIsRespPendFrame(
    VAR(uint8, AUTOMATIC) u8ChannelIndex);

static FUNC(void, LINIF_CODE) vidStopCurrTransMsg(
    VAR(uint8, AUTOMATIC)           u8ChannelIndex,
    VAR(NotifResultType, AUTOMATIC) udtReason,
    VAR(boolean, AUTOMATIC)         bResetTimer);

static FUNC(void, LINIF_CODE) vidHandleTransmission(
    VAR(uint8, AUTOMATIC) u8ChannelIndex);

static FUNC(void, LINIF_CODE) vidResetChannelVars(
    VAR(uint8, AUTOMATIC) u8ChannelIndex);

static FUNC(void, LINIF_CODE) vidHandleReception(
    VAR(uint8, AUTOMATIC) u8ChannelIndex);

static FUNC(void, LINIF_CODE) vidHandleSFAndFF(
    VAR(uint8, AUTOMATIC) u8ChannelIndex);

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
/******************************************************************************/
/*!Function    :   vidCopyFrame                                              */
/*!\Description    Copies a data to a frame, if there is unused bytes they are
                    filled with u8PADDING_BYTE \n    
    \param[in]      Pointer to the source data buffer \n
        \Range          NOT NULL \n
    \param[in]      Pointer to the Frame buffer \n
        \Range          NOT NULL \n
    \param[in]      Length of the data to be copied \n  
        \Range          1..8 \n                                               */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidCopyFrame(
    P2CONST(uint8, AUTOMATIC, LINIF_VAR) pku8Source,
    P2VAR(uint8, AUTOMATIC, LINIF_VAR) pu8Dest,
    VAR(uint8, AUTOMATIC) u8Length)
{
    VAR(uint8_least, AUTOMATIC) u8LoopIndex;
    /*!Loop with the required length, copy data from source to destination */

    for(u8LoopIndex = 0; u8LoopIndex < u8Length; u8LoopIndex++)
    {
        pu8Dest[u8LoopIndex] = pku8Source[u8LoopIndex];
    }
    /*!Pad the rest of the frame with 0xFF */
    /*\Trace_To: LinIf-CDD-0427(0) */
    for(u8LoopIndex = u8Length; u8LoopIndex < LinIf_u8FRAME_SIZE; u8LoopIndex++)
    {
        pu8Dest[u8LoopIndex] = u8PADDING_BYTE;
    }
}


/******************************************************************************/
/*!Function    : udtValidateNewRxMsg                                         */
/*!\Description    Validates a new Rx Message by checking that it is from the 
                    correct slave, if the message is validated the a pointer to
                    the RxNsud structure is saved \n    
    \param[in]      The index of the channel that the message is received on \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n
    \param[out]     Pointer location where the length of the message is stored 
                    if the message is validated \n
        \Range          NOT NULL \n
    \return         E_OK    : Message validated and the length is set upon the 
                              return
                    E_NOT_OK: Message is an invalid message,
                              length is not set\n                             */
/******************************************************************************/
static FUNC(Std_ReturnType, LINIF_CODE) udtValidateNewRxMsg(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) pu16MessageLength)
{
    VAR(Std_ReturnType, AUTOMATIC)                      udtFuncRet;
    VAR(uint16, AUTOMATIC)                              u16RxNsduEndIndex;
    VAR(uint16, AUTOMATIC)                              u16RxNsduStartIndex;
    VAR(uint16_least, AUTOMATIC)                        u16LoopIndex;
    VAR(boolean, AUTOMATIC)                             bNADFound;
    VAR(uint8, AUTOMATIC)                               u8RecNAD;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;
	P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_VAR) 
														pkstrCurrChannelPB;
    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
	pkstrCurrChannelPB 	= &(LinIf_pkstreGlobalConfig->
										pkstrChannels[u8ChannelIndex]);
    /*!Get the received NAD from the first byte in channel's au8DataBuffer */
    /*\Trace_To: LinIf-CDD-0418(0) */
    u8RecNAD = pstrCurrChannelVars->au8DataBuffer[0];
    
    if(TRUE == pstrCurrChannelVars->bTPUDSRPFMaxReached)
    {
        udtFuncRet = E_NOT_OK;
    }
    /*!If the received NAD is equal to u8TPLastAdrsdNAD (last addressed NAD by 
        a TX message) */
    /*\Trace_To: LinIf-CDD-0129(0) */
    /*\Trace_To: LinIf-CDD-0130(0) */
    else if(pstrCurrChannelVars->u8TPLastAdrsdNAD == u8RecNAD)
    {
        u16RxNsduStartIndex = 
            pkstrCurrChannelPB->u16TpRecNsdusIndex;

        u16RxNsduEndIndex = 
            u16RxNsduStartIndex 
            + 
            pkstrCurrChannelPB->u16NumberOfRecTp;

        /*!Loop from u16TpRecNsdusIndex of the current channel to the end of
            the Rec Nsdus of the channel*/
        /*\Trace_To: LinIf-CDD-0125(0) */
        bNADFound = FALSE;
        for(u16LoopIndex = u16RxNsduStartIndex;
            (u16LoopIndex < u16RxNsduEndIndex) && (FALSE == bNADFound);
            u16LoopIndex++)
        {
            /*!If the Received NAD matches the searched RxNsdu's NAD do the 
                following and end the loop*/
            if( u8RecNAD 
                == 
                pkstrGlobalTPConfigPtr->pkstrRxNsdus[u16LoopIndex].u8NAD)
            {
                /*!Call u16GetMsgLenFromBuffer to get the message length from 
                    the channel's au8DataBuffer */
                *pu16MessageLength = u16GetMsgLenFromBuffer((const uint8 *)
                    &(pstrCurrChannelVars->au8DataBuffer[0]));

                /*!If the returned message length is 0 or less than the 
                    configured minimum length (LinTpDl), the message lenght is
                    invalid so the function shall return E_NOT_OK*/
                /*\Trace_To: LinIf-CDD-0431(0) */
                /*\Trace_To: LinIf-CDD-0432(0) */
                if( (0 == *pu16MessageLength)
                    ||
                    (   pkstrGlobalTPConfigPtr->pkstrRxNsdus[u16LoopIndex].u16Dl
                        >
                        *pu16MessageLength))
                {
                    udtFuncRet = E_NOT_OK;
                }
                /*!Else set pkstrCurrTPRecNsdu to the searched Nsdu*/
                else
                {
                    pstrCurrChannelVars->pkstrCurrTPRecNsdu = 
                        &(pkstrGlobalTPConfigPtr->pkstrRxNsdus[u16LoopIndex]);
                    udtFuncRet = E_OK;
                }
                /*!Endif */
                bNADFound = TRUE;
            }
            /*!Endif */
        }
        /*!End Loop */
        
        /*!If the loop ended without the finding a RxNsdu return E_NOT_OK */
        if(FALSE == bNADFound)
        {
            udtFuncRet = E_NOT_OK;
        }
        else
        {
            /*!Else if it has found a message and its length is valid, 
            return E_OK, and set channel's u8TPCommState to u8TP_STATE_REC */

            /*!Deviation: Inhibit MISRA rule [0288]: udtFuncRet must have been 
                           set because this line is reached only if bNADFound =
                           TRUE and this happen only after passing an IF and 
                           ELSE that set udtFuncRet                           */
            /* PRQA S 3353 ++                                                 */
            if(E_OK == udtFuncRet)
            /* PRQA S 3353 --                                                 */
            {
                pstrCurrChannelVars->u8TPCommState = u8TP_STATE_REC;
            }
            /*!Endif */
        }
    }
    /*!Else (the RecNad is not previously addressed and the previous Tx 
        Message was not a functional request) */
    else
    {
        /* return E_NOT_OK */
        /*\Trace_To: LinIf-CDD-0130(0) */
        udtFuncRet = E_NOT_OK;
    }
    /*!Endif */
    return udtFuncRet;
}

/******************************************************************************/
/*!Function    : udtValidateCF                                               */
/*!\Description    Validates a new recevied CF by checking that it is from the 
                    correct slave, and has correct parameters \n    
    \param[in]      The index of the channel that the message is received on \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n
    \return         u8CF_E_OK : CF validated \n
                    u8CF_E_SN : CF has invalid sequence number \n 
                    u8CF_E_NAD: CF has invalid NAD \n                         */
/******************************************************************************/
static FUNC(tu8CFrameErrType, LINIF_CODE) udtValidateCF(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    VAR(tu8CFrameErrType, AUTOMATIC)                        udtFuncRet;
    VAR(uint8, AUTOMATIC)                                   u8RecNAD;
    VAR(uint8, AUTOMATIC)                                   u8SeqNum;
    P2CONST(LinIf_tstrTPReceivedNSdu, AUTOMATIC, LINIF_CALIB_CONST) 
                                                            pkstrCurrRxSdu;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)      pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    pkstrCurrRxSdu  = pstrCurrChannelVars->pkstrCurrTPRecNsdu;

    /*!Get the received NAD from the first byte in channel's au8DataBuffer */
    /*\Trace_To: LinIf-CDD-0418(0) */
    u8RecNAD = pstrCurrChannelVars->au8DataBuffer[0];

    /*!If the pkstrCurrRxSdu->u8NAD (the current message NAD) is same as the
        received NAD */
    if(pkstrCurrRxSdu->u8NAD == u8RecNAD)
    {
        /*\Trace_To: LinIf-CDD-0423(0) */
        u8SeqNum = 
            pstrCurrChannelVars->au8DataBuffer[1] & 0x0F;

        /*!if the sequence number in the PCI (the second byte in 
            au8DataBuffer) is equal to u8TPNextSeqNum*/
        if(u8SeqNum == pstrCurrChannelVars->u8TPNextSeqNum)
        {
            /*!Increment u8TPNextSeqNum modulo 15 */
            pstrCurrChannelVars->u8TPNextSeqNum = 
                (pstrCurrChannelVars->u8TPNextSeqNum + 1) & 0x0F;
            /*!return u8CF_E_OK */
            udtFuncRet = u8CF_E_OK;
        }
        /*!Else return u8CF_E_OK */
        /*\Trace_To: LinIf-CDD-0127(0) */
        else
        {
            udtFuncRet = u8CF_E_SN;
        }
        /*!EndIf */
    }
    /*!Else (the received NAD is not of the current message's)
        return u8CF_E_NAD */
    /*\Trace_To: LinIf-CDD-0127(0) */
    else
    {
        udtFuncRet = u8CF_E_NAD;
    }
    /*!EndIf */
    return udtFuncRet;
}


/******************************************************************************/
/*!Function    : udtSetupRxMsg                                               */
/*!\Description    Setup buffer for a newly recieved Rx Message \n    
    \param[in]      The index of the channel that the message is received on \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n
    \param[out]     Currently available buffer size in the UL for this message\n
    \return         E_OK     : Upper layer didnot indicate that 
                               there is no buffer, so message processing shall
                               proceed \n
                    E_NOT_OK : Upper layer indicated that there is not buffer 
                               for the message, message shall be canceled \n  */
/******************************************************************************/
static FUNC(Std_ReturnType, LINIF_CODE) udtSetupRxMsg(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) pu16AvailableBufferLen)
{
    VAR(BufReq_ReturnType, AUTOMATIC)                       udtSORRet;
    VAR(Std_ReturnType, AUTOMATIC)                          udtFuncRet;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)      pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    /*!Call StartOfReception from the upper layer to reserve buffer for
    the message */
    /*\Trace_To: LinIf-CDD-0124(0) */
    /*\Trace_To: LinIf-CDD-0302(0) */
    udtSORRet = pkstrGlobalTPConfigPtr->
        pfudtStartOfReception(
            pstrCurrChannelVars->pkstrCurrTPRecNsdu->u16RxNsduRef,
			NULL_PTR,
            pstrCurrChannelVars->udtTPCurrRxMsgLen,
            pu16AvailableBufferLen);
    /*!If StartOfReception returns BUFREQ_OK*/
    if(BUFREQ_OK == udtSORRet)
    {
        /*!Set bTPRxFrameSetupDone to TRUE to indicate that buffer 
        reservation is done*/
        pstrCurrChannelVars->bTPRxFrameSetupDone = TRUE;
        /*!Save the return value as E_OK */
        udtFuncRet = E_OK;
    }
    /*!ElseIf StartOfReception returns BUFREQ_E_BUSY */
    else if (BUFREQ_E_BUSY == udtSORRet)
    {
        /*!Set bTPRxFrameSetupDone to FALSE to indicate that buffer 
        reservation is not done */
        pstrCurrChannelVars->bTPRxFrameSetupDone = FALSE;
        *pu16AvailableBufferLen = 0;
        /*!Save the return value as E_OK, even if reservation is not done,
        but it is not rejected by the upper layer */
        udtFuncRet = E_OK;
    }
    /*!Else (the return is BUFREQ_E_OVFL, BUFREQ_E_NOT_OK */
    else /* E_OVFL, or E_NOT_OK */
    {
        /*!Set bTPRxFrameSetupDone to FALSE to indicate that buffer 
        reservation is not done */
        pstrCurrChannelVars->bTPRxFrameSetupDone = FALSE;
        /*!Save the return value as E_NOT_OK */
        udtFuncRet = E_NOT_OK;
    }
    /*!End If */

    /*!If the return value shall be E_OK, set udtTPRemData to udtTPCurrRxMsgLen
        and u8TPCommState to u8TP_STATE_REC and u8TPChannelState to 
        u8TP_CHANNEL_BUSY */
    if(E_OK == udtFuncRet)
    {
        pstrCurrChannelVars->udtTPRemData = 
            pstrCurrChannelVars->udtTPCurrRxMsgLen;
        pstrCurrChannelVars->u8TPCommState = u8TP_STATE_REC;
        /*\Trace_To: LinIf-CDD-0116(0) */
        pstrCurrChannelVars->u8TPChannelState = u8TP_CHANNEL_BUSY;

    }
    /*!return the stored return value */
    return udtFuncRet;
}

/******************************************************************************/
/*!Function    : u16GetMsgLenFromBuffer                                      */
/*!\Description    Gets the message length from a received FF or SF \n    
    \param[in]      Pointer a buffer containing a FF. \n
    \return         The length of the TP message as extracted from the first
                    frame in the buffer                                       */
/******************************************************************************/
static FUNC(uint16, LINIF_CODE) u16GetMsgLenFromBuffer(
    P2CONST(uint8, AUTOMATIC, LINIF_VAR) pku8DataBuffer)
{
    VAR(uint8, AUTOMATIC)   u8PCI;
    VAR(uint16, AUTOMATIC)  u16MessageLength;

    /*!Get the PCI from element 1 in the input buffer */
    /*\Trace_To: LinIf-CDD-0419(0) */
    /*\Trace_To: LinIf-CDD-0420(0) */
    u8PCI = pku8DataBuffer[1];
    /*!If the first 4 bits are 0001 (First Frame) */
    if((u8PCI & u8HIGH_4_BIT_MASK) == u8PCI_BASE_FIRST_F)
    {
        /*!Set u16MessageLength = the 4 LSB of PCI * 256 + the value of element
            2 in the array */
        /*\Trace_To: LinIf-CDD-0424(0) */
        u16MessageLength =  (((uint16)(pku8DataBuffer[1]) & (uint16)0x0F) << 8)
                            |
                            (pku8DataBuffer[2]);
        
        /*\Trace_To: LinIf-CDD-0432(0) */
        /*!if the message fits in a single frame (u16MessageLength <
            u8MAX_SIN_F_DATA_LEN)why sending it in a FF, so set 
            u16MessageLength = 0 */
        if(u16MessageLength < u8MAX_SIN_F_DATA_LEN)
        {
            u16MessageLength = 0;
        }
    }

    /*!Else If the first 4 bits are 0000 (Single Frame) */
    else if((u8PCI & u8HIGH_4_BIT_MASK) == u8PCI_BASE_SINGLE_F)
    {
        /*!Set u16MessageLength = the 4 LSB of PCI */
        u16MessageLength = pku8DataBuffer[1] & 0x0F;
        /*!if the message does not fit in a single frame (u16MessageLength > 
            u8MAX_SIN_F_DATA_LEN) why sending it in a SF, so set 
            u16MessageLength = 0 */
        /*\Trace_To: LinIf-CDD-0431(0) */
        if(u16MessageLength > u8MAX_SIN_F_DATA_LEN)
        {
            u16MessageLength = 0;
        }
    }
    /*!Else (CF or invalid PCI) */
    else /* CF or invalid PCI */
    {
        /*!Set u16MessageLength to 0 */
        u16MessageLength = 0;
    }
    /*!EndIf */
    /*!return  u16MessageLength */
    return u16MessageLength;
}


/******************************************************************************/
/*!Function    : u8CopyTpDataFromFrame                                       */
/*!\Description    Copy Payload data froma TP frame \n
    \param[in]      The index of the channel that the message is received on \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n
    \return         The Size of the copied data                               */
/******************************************************************************/
static FUNC(uint8, LINIF_CODE) u8CopyTpDataFromFrame(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    VAR(uint8, AUTOMATIC)                               u8PCI;
    VAR(uint8_least, AUTOMATIC)                         u8LoopIndex;
    VAR(uint8, AUTOMATIC)                               u8StartIndex;
    VAR(uint8, AUTOMATIC)                               u8StopIndex;
    P2VAR(uint8, AUTOMATIC, LINIF_VAR)                  pu8Source;
    P2VAR(uint8, AUTOMATIC, LINIF_VAR)                  pu8Dest;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    pu8Source = &(pstrCurrChannelVars->au8DataBuffer[0]);
    pu8Dest = &(pstrCurrChannelVars->au8TPDataBuffer[0]);

    /*!Get the PCI from element 1 in the input buffer */
    /*\Trace_To: LinIf-CDD-0419(0) */
    /*\Trace_To: LinIf-CDD-0420(0) */
    u8PCI = pu8Source[1];

    /*!If the firs 4 Bits of PCI is 0001 (FF) */
    /*\Trace_To: LinIf-CDD-0422(0) */
    if((u8PCI & u8HIGH_4_BIT_MASK) == u8PCI_BASE_FIRST_F)
    {
        /* message length checked in validation */
        /*!set StartIndex to 3 and EndIndex to 8 (the data portion of the first
            frame)*/
        u8StartIndex = 3;
        u8StopIndex = 8;   
    }
    /*!Else If the firs 4 Bits of PCI is 0000 (SF) */
    /*\Trace_To: LinIf-CDD-0421(0) */
    else if((u8PCI & u8HIGH_4_BIT_MASK) == u8PCI_BASE_SINGLE_F)
    {
        /*!set StartIndex to 2 and EndIndex to the message Length which is 
            the 4 LSBs of PCI) (the data portion of the Single frame)*/
        u8StartIndex = 2;
        u8StopIndex = 2 + (u8PCI & 0x0F);
    }
    /*!Else If the firs 4 Bits of PCI is 0010 (CF) */
    else if((u8PCI & u8HIGH_4_BIT_MASK) == u8PCI_BASE_CONSEC_F)
    {
        /*!set StartIndex to 2 and EndIndex to 8 or 2 + remaining data length
            (the data portion of the consecutive frame)*/
        u8StartIndex = 2;
        if(pstrCurrChannelVars->udtTPRemData > u8MAX_CON_F_DATA_LEN)
        {
            u8StopIndex = 8;
        }
        else
        {
            u8StopIndex = (uint8)2 + (uint8)(pstrCurrChannelVars->udtTPRemData);
        }
    }
    /*!Else (the PCI is invalid) */
    else /* Invalid PCI */
    {
        /*!set StartIndex to 0 and EndIndex to 0 to indicate an error */
        u8StartIndex = 0;
        u8StopIndex = 0;
    }
    /*!EndIf */
    /*!LOOP from StartIndex to EndIndex -1 and copy the data to dest from index
        0 */
    for(u8LoopIndex = u8StartIndex; u8LoopIndex < u8StopIndex; u8LoopIndex++)
    {
        /*!Deviation : Inhibit MISRA rule [3690]: u8LoopIndex is initialized 
                        with the value of u8StartIndex and only incremented so 
                        no negative index can happen */
        /* PRQA S 3690 ++                                                     */
        pu8Dest[u8LoopIndex - u8StartIndex] = pu8Source[u8LoopIndex];
        /* PRQA S 3690 --                                                     */
    }
    /*! return EndIndex - StartIndex */
    return (u8StopIndex - u8StartIndex);
}

/******************************************************************************/
/*!Function    : bIsRespPendFrame                                            */
/*!\Description    Checks if the current received SF on the channel is a 
                    Response Pending Frame \n
    \param[in]      The index of the channel that the message is received on \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n
    \return         TRUE : The frame is really a RPF \n
                    FALSE: The frame is not a RPF                             */
/******************************************************************************/
static FUNC(boolean, LINIF_CODE) bIsRespPendFrame(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    VAR(boolean, AUTOMATIC)             bRet;
    P2VAR(uint8, AUTOMATIC, LINIF_VAR)  pu8DataBuffer;

    pu8DataBuffer = &(LinIf_astreChannelsVars[u8ChannelIndex].au8DataBuffer[0]);

    /*!If the PCI = 0x03, and the first data byte = 0x7F and the third data 
        byte = 0x78 return TRUE else return FALSE*/
    if( (0x03 == pu8DataBuffer[1])
        &&
        (0x7F == pu8DataBuffer[2])
        &&
        (0x78 == pu8DataBuffer[4]))
    {
        bRet = TRUE;
    }
    else
    {
        bRet = FALSE;
    }
    return bRet;
}

/******************************************************************************/
/*!Function    : vidStopCurrRxMsg                                            */
/*!\Description    Stops the current received message on a channel \n
    \param[in]      The index of the channel that the message is received on \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n
    \param[in]      The reason of stopping the message \n
        \Range          NTFRSLT_OK
                        NTFRSLT_E_NOT_OK
                        NTFRSLT_E_TIMEOUT_A
                        NTFRSLT_E_TIMEOUT_CR
                        NTFRSLT_E_WRONG_SN
                        NTFRSLT_E_UNEXP_PDU
                        NTFRSLT_E_NO_BUFFER  \n                               */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidStopCurrRxMsg(
    VAR(uint8, AUTOMATIC)           u8ChannelIndex,
    VAR(NotifResultType, AUTOMATIC) udtReason,
    VAR(boolean, AUTOMATIC)         bResetTimer)
{
    P2CONST(LinIf_tstrTPReceivedNSdu, AUTOMATIC, LINIF_CALIB_CONST) 
                                                            pkstrCurrRxNsdu;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)      pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    pkstrCurrRxNsdu = pstrCurrChannelVars->pkstrCurrTPRecNsdu;

    /*!If there is a message currently on the channel (i.e. pkstrCurrTPRecNsdu
        of the channel is not NULL) */
    if( pkstrCurrRxNsdu 
        != 
        (P2CONST(LinIf_tstrTPReceivedNSdu,
                 AUTOMATIC, 
                 LINIF_CALIB_CONST))NULL_PTR)
    {
        /*!Set u8TPCommState to u8TP_STATE_IDLE */
        pstrCurrChannelVars->u8TPCommState = u8TP_STATE_IDLE;
        /*!Set u8TPChannelState to u8TP_CHANNEL_IDLE */
        pstrCurrChannelVars->u8TPChannelState = u8TP_CHANNEL_IDLE;
        /*!Set pkstrCurrTPRecNsdu to NULL */
        pstrCurrChannelVars->pkstrCurrTPRecNsdu = NULL_PTR;

        /*!Set u8TPNextSeqNum to 1 */
        pstrCurrChannelVars->u8TPNextSeqNum = 1;
        /*!Set bTPRxFrameSetupDone to FALSE */
        pstrCurrChannelVars->bTPRxFrameSetupDone = FALSE;
        /*!Set bTPDataAvailable to FALSE */
        pstrCurrChannelVars->bTPDataAvailable = FALSE;
        
        /*!Call TpRxIndication with u16RxNsduRef, and the input reason */
        /*\Trace_To: LinIf-CDD-0133(0) */
        /*\Trace_To: LinIf-CDD-0145(0) */
        /*\Trace_To: LinIf-CDD-0292(0) */
        pkstrCurrRxNsdu->
            pfvidRxIndication(pkstrCurrRxNsdu->u16RxNsduRef, udtReason);
        
    }

    if(FALSE != bResetTimer)
    {
        /*!Set u16TPTimoutTimer to 0 to stop any running timeout */
        pstrCurrChannelVars->u16TPTimoutTimer = 0;
    }
}


/******************************************************************************/
/*!Function    : vidStopCurrTransMsg                                         */
/*!\Description    Stops the current transmitted message on a channel \n
    \param[in]      The index of the channel where the message is transmitted \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n
    \param[in]      The reason of stopping the message \n
        \Range          NTFRSLT_OK
                        NTFRSLT_E_NOT_OK
                        NTFRSLT_E_TIMEOUT_A
                        NTFRSLT_E_TIMEOUT_CR
                        NTFRSLT_E_WRONG_SN
                        NTFRSLT_E_UNEXP_PDU
                        NTFRSLT_E_NO_BUFFER  \n                               */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidStopCurrTransMsg(
    VAR(uint8, AUTOMATIC)           u8ChannelIndex,
    VAR(NotifResultType, AUTOMATIC) udtReason,
    VAR(boolean, AUTOMATIC)         bResetTimer)
{
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;

    P2CONST(LinIf_tstrTPTransmittedNSdu, AUTOMATIC, LINIF_CALIB_CONST) 
                                                        pkstrThisNdsu;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    
    pkstrThisNdsu = pstrCurrChannelVars->pkstrCurrTPTxNsdu;
        
    /*!If there is a message currently on the channel (i.e. pkstrCurrTPTxNsdu
        of the channel is not NULL) */
    if(
        (P2CONST(LinIf_tstrTPTransmittedNSdu,
                 LINIF_VAR,
                 LINIF_CALIB_CONST))NULL_PTR != pkstrThisNdsu)
    {
        
        /*!Set u8TPCommState to u8TP_STATE_IDLE */
        pstrCurrChannelVars->u8TPCommState = u8TP_STATE_IDLE;
        
        /*!Set u8TPChannelState to u8TP_CHANNEL_IDLE */
        /*\Trace_To: LinIf-CDD-0114(0) */
        pstrCurrChannelVars->u8TPChannelState = u8TP_CHANNEL_IDLE;
        
        /*!Set pkstrCurrTPRecNsdu to NULL */
        pstrCurrChannelVars->pkstrCurrTPTxNsdu = NULL_PTR;

        /*!Set u8TPNextSeqNum to 1 */
        pstrCurrChannelVars->u8TPNextSeqNum = 1;

        /*!Set bTPDataAvailable to FALSE */
        pstrCurrChannelVars->bTPDataAvailable = FALSE;

        /*!Set bTpFrameSent to FALSE */
        pstrCurrChannelVars->bTpFrameSent = FALSE;

        /*!Call TpTxConfirmation with u16TxNsduRef, and the input reason */
        /*\Trace_To: LinIf-CDD-0121(0) */
        /*\Trace_To: LinIf-CDD-0122(0) */
        /*\Trace_To: LinIf-CDD-0123(0) */
        /*\Trace_To: LinIf-CDD-0288(0) */
        pkstrThisNdsu->
            pfvidTxConfirmation(pkstrThisNdsu->u16TxNsduRef, udtReason);

    }
    /*!If the input reason to stop the message is anything but it is finished
        correctly set u16TPTimoutTimer to 0 to stop any running timeout */
    if((NTFRSLT_OK != udtReason) && (FALSE != bResetTimer))
    {
        pstrCurrChannelVars->u16TPTimoutTimer = 0;
    }
}

/******************************************************************************/
/*!Function    : vidHandleTransmission                                       */
/*!\Description    Handles buffer acquiring to fill the MRF according to the 
                    type of the next frame to be sent\n
    \param[in]      The index of the channel where the message is transmitted \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n                  */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleTransmission(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{

    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    /*!If bTPDataAvailable equals FALSE (there is not enough data for the 
        next frame) */
    /*\Trace_To: LinIf-CDD-0117(0) */
    if(FALSE == pstrCurrChannelVars->bTPDataAvailable)
    {
        VAR(Std_ReturnType, AUTOMATIC) udtRet;
        
        /*!If bTPStartNewFrame = true (a new frame has to be transmitted) */
        if(FALSE != pstrCurrChannelVars->bTPStartNewFrame)
        {
            /*!If udtTPRemData > u8MAX_SIN_F_DATA_LEN (the new message is a
                multi-frame message */
            if(pstrCurrChannelVars->udtTPRemData > u8MAX_SIN_F_DATA_LEN)
            {
                /*!Call udtPrepareTpTxFrame with the following parameters 
                   (u8ChannelIndex, u8FF_DATA_LENGTH,
                   pstrCurrChannelVars->udtTPRemData, u8FIRST_FRAME_TYPE) */
                udtRet = 
                    udtPrepareTpTxFrame(
                        u8ChannelIndex,
                        u8FF_DATA_LENGTH,
                        pstrCurrChannelVars->udtTPRemData,
                        u8FIRST_FRAME_TYPE);
            }
            /*!Else (a single frame) */
            /*\Trace_To: LinIf-CDD-0428(0) */
            else 
            {
                /*!Call udtPrepareTpTxFrame with the following parameters 
                   (u8ChannelIndex, pstrCurrChannelVars->udtTPRemData, 0,
                   u8SINGLE_FRAME_TYPE) */
                udtRet = 
                    udtPrepareTpTxFrame(
                        u8ChannelIndex,
                        (uint8)pstrCurrChannelVars->udtTPRemData,
                        0, 
                        u8SINGLE_FRAME_TYPE);
            }
            /*!EndIf */
        }
        /*!Else if udtTPRemData > 0 (no new frame has to be transmitted 
            and there is still data to be acquired) */
        else if(pstrCurrChannelVars->udtTPRemData > 0)
        {
            /*!If udtTPRemData > u8MAX_CON_F_DATA_LEN (the remaining data does 
                not fit in a single CF) */
            if(pstrCurrChannelVars->udtTPRemData > u8MAX_CON_F_DATA_LEN)
            {
                /*!Call udtPrepareTpTxFrame with the following parameters 
                   (u8ChannelIndex, u8MAX_CON_F_DATA_LEN, 0,
                   u8CONSEC_FRAME_TYPE) */
                udtRet = 
                    udtPrepareTpTxFrame(
                        u8ChannelIndex,
                        u8MAX_CON_F_DATA_LEN,
                        0,
                        u8CONSEC_FRAME_TYPE);
            }
            /*!Else (the remaining data fits in a single CF) */
            else 
            {
                /*!Call udtPrepareTpTxFrame with the following parameters 
                   (u8ChannelIndex, pstrCurrChannelVars->udtTPRemData, 0,
                   u8CONSEC_FRAME_TYPE) */
                udtRet = 
                    udtPrepareTpTxFrame(
                        u8ChannelIndex,
                        (uint8)pstrCurrChannelVars->udtTPRemData,
                        0,
                        u8CONSEC_FRAME_TYPE);
            }
            /*!EndIf */
        }
        else
        {
            udtRet = E_OK;
        }
        /*!EndIf */
        /*\Trace_To: LinIf-CDD-0123(0) */
        /*!If the return of udtPrepareTpTxFrame is not E_OK (the UL 
            indicated a failure) call vidStopCurrTransMsg with 
            NTFRSLT_E_NOT_OK */
        if(E_OK != udtRet)
        {
            vidStopCurrTransMsg(u8ChannelIndex, NTFRSLT_E_NOT_OK, TRUE);
        }
        /*!Else */
        else
        {
            /*!If bTPStartNewFrame is TRUE and bTPDataAvailable is TRUE
                (i.e. the first frame of the new message is prepared 
                successfully)*/
            if( (FALSE != pstrCurrChannelVars->bTPStartNewFrame)
                &&
                (FALSE != pstrCurrChannelVars->bTPDataAvailable))
            {
                /*!Set bTPStartNewFrame to false */
                pstrCurrChannelVars->bTPStartNewFrame = FALSE;
            }
            /*!EndIf */
        }
        /*!EndIf */
    }
    /*!EndIf */
}

/******************************************************************************/
/*!Function    : vidResetChannelVars                                         */
/*!\Description    Reset all TP channel variable to their default value \n
    \param[in]      The index of the channel where the message is transmitted \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n                  */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidResetChannelVars(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    /*!Set u8TPCommState to u8TP_STATE_IDLE */
    /*\Trace_To: LinIf-CDD-0257(0) */
    pstrCurrChannelVars->u8TPCommState = u8TP_STATE_IDLE;

    /*!Set bTPDataAvailable to FALSE */
    /*\Trace_To: LinIf-CDD-0257(0) */
    pstrCurrChannelVars->bTPDataAvailable = FALSE;
    /*!Set bTPStartNewFrame to FALSE */
    pstrCurrChannelVars->bTPStartNewFrame = FALSE;
    /*!Set bTPRxFrameSetupDone to FALSE */
    pstrCurrChannelVars->bTPRxFrameSetupDone = FALSE;
    /*!Set bNConfMRFFailed to FALSE */
    pstrCurrChannelVars->bNConfMRFFailed = FALSE;
    /*!Set bTPUDSRPFMaxReached to FALSE */
    pstrCurrChannelVars->bTPUDSRPFMaxReached = FALSE;
    /*!Set bTpFrameSent to FALSE */
    pstrCurrChannelVars->bTpFrameSent = FALSE;
    
    /*!Set u8TPNextSeqNum to 1*/
    pstrCurrChannelVars->u8TPNextSeqNum = 1;
    /*!Set u8TPLastAdrsdNAD to 0*/
    pstrCurrChannelVars->u8TPLastAdrsdNAD = 0;
    /*!Set u8CurrTPFrameLength to 0*/
    pstrCurrChannelVars->u8CurrTPFrameLength = 0;
    /*!Set udtTPCurrRxMsgLen to 0*/
    pstrCurrChannelVars->udtTPCurrRxMsgLen = 0;
    /*!Set u16TPTimoutTimer to 0*/
    pstrCurrChannelVars->u16TPTimoutTimer = 0U;
    /*!Set u16TPUDSPendFrameCnt to 0*/
    pstrCurrChannelVars->u16TPUDSPendFrameCnt = 0U;
    /*!Set udtTPRemData to 0*/
    pstrCurrChannelVars->udtTPRemData = 0;
    /*!Set u8NCSlaveIndex to 0*/
    pstrCurrChannelVars->u8NCSlaveIndex = 0xFF;
    
    
    /*!Set pkstrCurrTPRecNsdu to NULL*/
    /*\Trace_To: LinIf-CDD-0259(0) */
    /*\Trace_To: LinIf-CDD-0260(0) */
    pstrCurrChannelVars->pkstrCurrTPRecNsdu = NULL_PTR;
    /*!Set pkstrCurrTPTxNsdu to NULL*/
    pstrCurrChannelVars->pkstrCurrTPTxNsdu = NULL_PTR;
}

/******************************************************************************/
/*!Function    : vidHandleCFRec                                              */
/*!\Description    Handles reception of a CF \n
    \param[in]      The index of the channel where the message is transmitted \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n                  */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleCFRec(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    VAR(tu8CFrameErrType, AUTOMATIC)                    udtCFValRet;
    VAR(Std_ReturnType, AUTOMATIC)                      udtTemp;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    /*!Call udtValidateCF to check that the CF is valid */
    udtCFValRet = udtValidateCF(u8ChannelIndex);

    /*!If the message is validated (the return = u8CF_E_OK)*/
    if(u8CF_E_OK == udtCFValRet)
    {
        /*!Call u8CopyTpDataFromFrame to copy the data and save the length is
            u8CurrTPFrameLength */
        pstrCurrChannelVars->u8CurrTPFrameLength = 
            u8CopyTpDataFromFrame(u8ChannelIndex);

        /*!Set bTPDataAvailable to True */
        pstrCurrChannelVars->bTPDataAvailable = TRUE;
        
        /*!Call udtDeliverRxFrame with input u8CurrTPFrameLength */
        /*\Trace_To: LinIf-CDD-0143(0) */
        udtTemp = 
            udtDeliverRxFrame(
            u8ChannelIndex,
            pstrCurrChannelVars->u8CurrTPFrameLength, TRUE);
        
        /*!If the return of udtDeliverRxFrame is E_NOT_OK */
        /*\Trace_To: LinIf-CDD-0127(0) */
        if(E_OK != udtTemp)
        {
            /*!Call vidStopCurrRxMsg to stop the message with result equal to
                NTFRSLT_E_NOT_OK because the UL indicated a failure*/
            /*\Trace_To: LinIf-CDD-0145(0) */
            vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_E_NOT_OK, TRUE);
        }
        /*!EndIf */
    }
    /*!Else if the validation indicated that the sequence number is wrong 
        (the return = u8CF_E_SN) */
    /*\Trace_To: LinIf-CDD-0127(0) */
    /*\Trace_To: LinIf-CDD-0131(0) */
    else if(u8CF_E_SN == udtCFValRet)
    {
        /*!Call vidStopCurrRxMsg to stop the message with result equal to
                NTFRSLT_E_WRONG_SN */
        vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_E_WRONG_SN, TRUE);
        /*!Call BswM_LinTp_RequestMode with LINTP_APPLICATIVE_SCHEDULE to 
            request a schedule switch */
        BswM_LinTp_RequestMode(
            LinIf_udtGetChannelIdByIndex(u8ChannelIndex),
            LINTP_APPLICATIVE_SCHEDULE);
    }
    /*\Trace_To: LinIf-CDD-0127(0) */
    /*\Trace_To: LinIf-CDD-0131(0) */
    /*!Else (the validation indicated that the NAD is wrong 
        (the return = u8CF_E_NAD) */
    else /* u8CF_E_NAD */
    {
        /*!Call vidStopCurrRxMsg to stop the message with result equal to
            NTFRSLT_E_NOT_OK */
        vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_E_NOT_OK, TRUE);

        /*!Call BswM_LinTp_RequestMode with LINTP_APPLICATIVE_SCHEDULE to 
            request a schedule switch */
        BswM_LinTp_RequestMode(
            LinIf_udtGetChannelIdByIndex(u8ChannelIndex),
            LINTP_APPLICATIVE_SCHEDULE);
    }
    /*!EndIf */
}

/******************************************************************************/
/*!Function    : vidHandleReception                                          */
/*!\Description    Handles buffer acquiring to deliver a received frame data
                    to UL before the next SRF \n
    \param[in]      The index of the channel where the message is transmitted \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n                  */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleReception(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    VAR(Std_ReturnType, AUTOMATIC)                      udtTempRet;
    VAR(uint16, AUTOMATIC)                              u16AvailableBufferLen;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    /*!If bTPRxFrameSetupDone is FALSE (a new message is validated but 
        StartOfReception returned BUSY) */
    if(FALSE == pstrCurrChannelVars->bTPRxFrameSetupDone)
    {
        /*!Call udtSetupRxMsg to try to setup the message again */
        udtTempRet = udtSetupRxMsg(u8ChannelIndex, &u16AvailableBufferLen);
        
        /*!If there is no error in the setup (this mean that the UL may have
            indicated OK or BUSY) */
        if(E_OK == udtTempRet)
        {
            /*!If bTPRxFrameSetupDone is TRUE (the frame setup is done
                successfully) and returned available buffer is enough for the
                current frame data */
            if((FALSE != pstrCurrChannelVars->bTPRxFrameSetupDone)
               &&
               (u16AvailableBufferLen >= 
                                    pstrCurrChannelVars->u8CurrTPFrameLength))
            {
                /*!Call udtDeliverRxFrame to pass the data to upper layer */
                /* no need to check the result of the call as udtSetupRxMsg 
                   already indicated that there is enough buffer */
                (void)udtDeliverRxFrame(
                        u8ChannelIndex,
                        pstrCurrChannelVars->u8CurrTPFrameLength, FALSE);
            }
            /*!EndIf */
        }
        /*!Else (setup indicated error) */
        /*\Trace_To: LinIf-CDD-0127(0) */
        else
        {
            /*!Call vidStopCurrRxMsg with result = NTFRSLT_E_NOT_OK*/
            /*\Trace_To: LinIf-CDD-0145(0) */
            vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_E_NOT_OK, TRUE);
        }
        /*!EndIf */
    }
    /*!Else If bTPDataAvailable is true (There is data not passed to UL) */
    /*\Trace_To: LinIf-CDD-0143(0) */
    /*\Trace_To: LinIf-CDD-0144(0) */
    else if(FALSE != pstrCurrChannelVars->bTPDataAvailable)
    {
        /*!Call udtDeliverRxFrame to pass the data to upper layer */
        udtTempRet = 
            udtDeliverRxFrame(
                u8ChannelIndex,
                pstrCurrChannelVars->u8CurrTPFrameLength, TRUE);
        /*!If the return of udtDeliverRxFrame is not OK */
        if(E_OK != udtTempRet)
        {
            /*!Call vidStopCurrRxMsg with result = NTFRSLT_E_NOT_OK*/
            /*\Trace_To: LinIf-CDD-0145(0) */
            vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_E_NOT_OK, TRUE);
        }
        /*!EndIf */
    }
    else
    {
        /* do nothing just for misra */
    }
    /*!EndIf */
}


/******************************************************************************/
/*!Function    : vidHandleSFAndFF                                            */
/*!\Description    Handles Reception of a SF or a FF \n
    \param[in]      The index of the channel where the message is transmitted \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n                  */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleSFAndFF(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    VAR(Std_ReturnType, AUTOMATIC)                      udtTemp;
    VAR(BufReq_ReturnType, AUTOMATIC)                   enuCopyDataRet;
    VAR(PduLengthType, AUTOMATIC)                       udtAvailableBufferLen;
    VAR(uint8, AUTOMATIC)                               u8DataLength;
    VAR(PduInfoType, AUTOMATIC)                         strPduInfo;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    /*!Call udtSetupRxMsg to setup the newly received message */
    /*\Trace_To: LinIf-CDD-0124(0) */
    udtTemp = udtSetupRxMsg(u8ChannelIndex, &udtAvailableBufferLen);

    /*!If there is no error in the setup (this mean that the UL may have
        indicated OK or BUSY) */
    if(E_OK == udtTemp)
    {
        u8DataLength = pstrCurrChannelVars->u8CurrTPFrameLength;
        /*!If the available buffer after setup is greater than the received 
            frame data length */
        if( (udtAvailableBufferLen >= u8DataLength)
            &&
            (TRUE == pstrCurrChannelVars->bTPRxFrameSetupDone))
        {

            P2CONST(LinIf_tstrTPReceivedNSdu, AUTOMATIC, LINIF_CALIB_CONST) 
                pkstrCurrRx;

            pkstrCurrRx = pstrCurrChannelVars->pkstrCurrTPRecNsdu;

            /*!Call CopyRxData to pass the data in au8TPDataBuffer with data 
                lenght = u8CurrTPFrameLength to the UL*/
            strPduInfo.SduDataPtr = &(pstrCurrChannelVars->au8TPDataBuffer[0]);
            strPduInfo.SduLength = u8DataLength;
            /*\Trace_To: LinIf-CDD-0294(0) */
            enuCopyDataRet = pkstrGlobalTPConfigPtr->
                                    pfudtCopyRxData(pkstrCurrRx->u16RxNsduRef,
                                                    &strPduInfo,
                                                    &udtAvailableBufferLen);
            
            /*!if the return of CopyRxData is BUFREQ_OK */
            if(BUFREQ_OK == enuCopyDataRet)
            {
                /*!Set bTPDataAvailable to FALSE */
                pstrCurrChannelVars->bTPDataAvailable = FALSE;
                /*!Decrement udtTPRemData by u8CurrTPFrameLength and if 
                    reaches 0 call vidStopCurrRxMsg with result = NTFRSLT_OK */
                pstrCurrChannelVars->udtTPRemData -= u8DataLength;
                /*\Trace_To: LinIf-CDD-0126(0) */
                if(pstrCurrChannelVars->udtTPRemData == 0)
                {
                    vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_OK, TRUE);
                }
            }
            /*!Else if the return of CopyRxData is BUFREQ_E_BUSY */
            else if(BUFREQ_E_BUSY == enuCopyDataRet)
            {
                /*!Set bTPDataAvailable to TRUE */
                pstrCurrChannelVars->bTPDataAvailable = TRUE;
            }
            /*!Else (E_OVFL or E_NOT_OK) */
            else
            {
                /*!Call vidStopCurrRxMsg to free the reception resources*/
                vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_E_NOT_OK, TRUE);
            }
        }
        /*!Else (the available buffer length is not enough for the received 
            data) */
        else
        {
            /*!Set bTPDataAvailable to TRUE */
            pstrCurrChannelVars->bTPDataAvailable = TRUE;
        }
        /*!EndIf */
    }
    /*!Else (the message setup failed due to UL call returning NOT_OK) */
    else
    {
        /*!Set bTPDataAvailable to FALSE */
        pstrCurrChannelVars->bTPDataAvailable = FALSE;
        /*!Set u8TPCommState to u8TP_STATE_IDLE */
        pstrCurrChannelVars->u8TPCommState = u8TP_STATE_IDLE;
        /*!Set u8TPChannelState to u8TP_CHANNEL_IDLE */
        /*\Trace_To: LinIf-CDD-0114(0) */
        pstrCurrChannelVars->u8TPChannelState = u8TP_CHANNEL_IDLE;
        /*!Set pkstrCurrTPRecNsdu to NULL_PTR */
        pstrCurrChannelVars->pkstrCurrTPRecNsdu = NULL_PTR;
    }
    /*!EndIf */
}

/******************************************************************************/
/*!Function    : udtDeliverRxFrame                                           */
/*!\Description    Handles copying Rx data to the upper layer \n
    \param[in]      The index of the channel where the message is transmitted \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n
    \param[in]      The length of the data in the frame \n
        \Range          1..8 \n                                               
    \param[in]      If true, CopyRxData shall be called with 0 first to check 
                    for the size of the available buffer, if false CopyRxData 
                    with the actual data shall be performed without checking \n
        \Range          FALSE, TRUE \n 
    \return         E_OK        : The Upper layer did not indicate a failure \n
                    E_NOT_OK    : The Upper layer indicated a failure \n*/
/******************************************************************************/
static FUNC(Std_ReturnType, LINIF_CODE) udtDeliverRxFrame(
    VAR(uint8, AUTOMATIC)   u8ChannelIndex,
    VAR(uint8, AUTOMATIC)   u8DataLength,
    VAR(boolean, AUTOMATIC) bTestBuffer)
{
    VAR(Std_ReturnType, AUTOMATIC)                          udtFuncRet;
    VAR(BufReq_ReturnType, AUTOMATIC)                       udtCopyDataRet;
    P2CONST(LinIf_tstrTPReceivedNSdu, AUTOMATIC, LINIF_CALIB_CONST) 
                                                            pkstrCurrRx;
    VAR(PduInfoType, AUTOMATIC)                             strPduInfo;
    VAR(PduLengthType, AUTOMATIC)                           udtAvailableBuffer;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)      pstrCurrChannelVars;
    VAR(boolean, AUTOMATIC)                                 bContinue;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    pkstrCurrRx = pstrCurrChannelVars->pkstrCurrTPRecNsdu;

    strPduInfo.SduDataPtr = &(pstrCurrChannelVars->au8TPDataBuffer[0]);
    /*! Set FunctionRet to E_OK */
    udtFuncRet = E_OK;
    /*! Set bContinue to E_OK */
    bContinue = TRUE;

    /*! If bTestBuffer is TURE */
    if(FALSE != bTestBuffer)
    {
        /*! Call CopyRxData with data length = 0 */
        strPduInfo.SduLength = 0;

        udtCopyDataRet = pkstrGlobalTPConfigPtr->
            pfudtCopyRxData(
            pkstrCurrRx->u16RxNsduRef,
            &strPduInfo,
            &udtAvailableBuffer);
        /*! Set bContinue to false */
        bContinue = FALSE;
        /*! If the return of CopyRxData is BUFREQ_OK */ 
        if(BUFREQ_OK == udtCopyDataRet)
        {
            /*! If the available buffer size returned >= u8DataLength,
            set bContinue to true */
            if(udtAvailableBuffer >= u8DataLength)
            {
                bContinue = TRUE;
            }
            /*! End if */
        }
        /*! Else if the return of CopyRxData is BUFREQ_E_BUSY, do not set bContinue to true */
        /*! Else set the FunctionRet to E_NOT_OK */
        else 
        {
            if(BUFREQ_E_BUSY != udtCopyDataRet)   
            {
                udtFuncRet = E_NOT_OK;
            }
        }
        /*! End if */
    }
    /*! If bContinue equal to true */
    if(FALSE != bContinue)
    {
        strPduInfo.SduLength = u8DataLength;

        /*!Call CopyRxData and pass to it au8TPDataBuffer with the input length */
        /*\Trace_To: LinIf-CDD-0294(0) */
        udtCopyDataRet = pkstrGlobalTPConfigPtr->
            pfudtCopyRxData(
            pkstrCurrRx->u16RxNsduRef,
            &strPduInfo,
            &udtAvailableBuffer);

        udtFuncRet = E_OK;
        /*!If return value of CopyRxData is BUFREQ_OK */
        if(BUFREQ_OK == udtCopyDataRet)
        {
            /*!Set bTPDataAvailable to FALSE */ 
            /*\Trace_To: LinIf-CDD-0142(0) */
            pstrCurrChannelVars->bTPDataAvailable = FALSE;
            /*!Decrement the udtTPRemData by the input data length and if it 
            reaches 0 call vidStopCurrRxMsg with result = NTFRSLT_OK */ 
            pstrCurrChannelVars->udtTPRemData -= u8DataLength;
            if(pstrCurrChannelVars->udtTPRemData == 0)
            {
                /*\Trace_To: LinIf-CDD-0126(0) */
                vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_OK, TRUE);
            }
            /*!return E_OK */
        }
        /*!Else If return value of CopyRxData is BUFREQ_E_BUSY */
        else if (BUFREQ_E_BUSY == udtCopyDataRet)
        {
            /*!Set bTPDataAvailable to TRUE */ 
            /*!return E_OK */
            /*\Trace_To: LinIf-CDD-0142(0) */
            pstrCurrChannelVars->bTPDataAvailable = TRUE;
        }
        /*\Trace_To: LinIf-CDD-0127(0) */
        /*!Else (E_OVFL, or E_NOT_OK or any other invalid value) */
        else
        {
            /*!return E_NOT_OK */
            udtFuncRet = E_NOT_OK;
        }
    }
    /*! End if */
    return udtFuncRet;    
}
/******************************************************************************/
/*!Function    : udtPrepareTpTxFrame                                         */
/*!\Description    Handles copying Tx data from the upper layer and adding PCI
                    to it\n
    \param[in]      The index of the channel where the message is transmitted \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n
    \param[in]      The length of the requested data. it is used only in the 
                    case of SF and CF \n
        \Range          1..8 \n                                               
    \param[in]      The length of the whole TP message to be segmented. it is 
                    used only in the case of a FF \n
        \Range          1..4096 \n
    \param[in]      The type of the frame to be prepared \n
        \Range          u8SINGLE_FRAME_TYPE,
                        u8FIRST_FRAME_TYPE,
                        u8CONSEC_FRAME_TYPE \n
    \return         E_OK        : The Upper layer did not indicate a failure \n
                    E_NOT_OK    : The Upper layer indicated a failure \n*/
/******************************************************************************/
static FUNC(Std_ReturnType, LINIF_CODE) udtPrepareTpTxFrame(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    VAR(uint8, AUTOMATIC) u8DataLength,
    VAR(PduLengthType, AUTOMATIC) udtTPMessageLength,
    VAR(uint8, AUTOMATIC) u8FrameType)
{
    VAR(Std_ReturnType, AUTOMATIC)                      udtRet;
    VAR(PduInfoType, AUTOMATIC)                         strPduInfo;
    VAR(RetryInfoType, AUTOMATIC)                       strRetryInfo;
    VAR(BufReq_ReturnType, AUTOMATIC)                   udtCopyTxRet;
    VAR(PduLengthType, AUTOMATIC)                       udtTempRem;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    /* poll the available transmit data */
    strPduInfo.SduDataPtr = &(pstrCurrChannelVars->au8TPDataBuffer[0]);
    strPduInfo.SduLength = 0;
    strRetryInfo.TpDataState = TP_NORETRY;
    strRetryInfo.TxTpDataCnt = 0;
    /*!Call CopyTxData with data length = 0 to poll for the available data 
        buffer size */
    /*\Trace_To: LinIf-CDD-0290(0) */
    udtCopyTxRet =
        pkstrGlobalTPConfigPtr->pfudtCopyTxData(
        pstrCurrChannelVars->pkstrCurrTPTxNsdu->u16TxNsduRef,
        &strPduInfo,
        &strRetryInfo,
        &udtTempRem);

    /*!If the return from buffer poll is BUFREQ_OK */
    if(BUFREQ_OK == udtCopyTxRet)
    {
        /*!If the available buffer size >= the input data length */
        /*\Trace_To: LinIf-CDD-0422(0) */
        if(udtTempRem >= u8DataLength)
        {
            /*!Set SduLength in the PduInfoPtr to be sent to the input data 
                length */
            /*\Trace_To: LinIf-CDD-5165(0) */
            strPduInfo.SduLength = u8DataLength;
            /*!If the frame type is u8FIRST_FRAME_TYPE set SduDataPtr to
                &au8TPDataBuffer[3] else set it to &au8TPDataBuffer[2]*/
            if(u8FIRST_FRAME_TYPE == u8FrameType)
            {
                /*\Trace_To: LinIf-CDD-5154(0) */
                strPduInfo.SduDataPtr = 
                    &(pstrCurrChannelVars->
                        au8TPDataBuffer[LinIf_u8FRAME_SIZE-u8FF_DATA_LENGTH]);
            }
            /*\Trace_To: LinIf-CDD-0421(0) */
            else
            {
                /* SF or CF, note that the both have the same maximum data size,
                   and can have data length less than the maximum */
                /*\Trace_To: LinIf-CDD-5154(0) */
                strPduInfo.SduDataPtr = 
                    &(pstrCurrChannelVars->
                    au8TPDataBuffer[LinIf_u8FRAME_SIZE-u8MAX_SIN_F_DATA_LEN]);
            }

            /*!Call CopyTxData */
            /*\Trace_To: LinIf-CDD-0249(0) */
            /*\Trace_To: LinIf-CDD-0290(0) */
            udtCopyTxRet =
                pkstrGlobalTPConfigPtr->pfudtCopyTxData(
                pstrCurrChannelVars->pkstrCurrTPTxNsdu->u16TxNsduRef,
                &strPduInfo,
                &strRetryInfo,
                &udtTempRem);
            /*!If the return of the call is BUFREQ_OK (the data has been 
                copied successfully) */
            if(BUFREQ_OK == udtCopyTxRet)
            {
                VAR(uint8, AUTOMATIC) u8PCI;
                /*!Decrement udtTPRemData by input data length */
                
				if(FALSE != pstrCurrChannelVars->bTPStartNewFrame)
				{
					pstrCurrChannelVars->udtTPRemData -= u8DataLength;
				}
                
                /*!Set u8CurrTPFrameLength to input data length */
                pstrCurrChannelVars->u8CurrTPFrameLength = u8DataLength;

                /*!Set bTPDataAvailable to TRUE */
                /*\Trace_To: LinIf-CDD-0119(0) */
                pstrCurrChannelVars->bTPDataAvailable = TRUE;

                /*!Set the first byte in au8TPDataBuffer to 
                    pkstrCurrTPTxNsdu->u8NAD */
                /*\Trace_To: LinIf-CDD-0244(0) */
                /*\Trace_To: LinIf-CDD-0418(0) */
                /*\Trace_To: LinIf-CDD-0419(0) */
                pstrCurrChannelVars->au8TPDataBuffer[0] = 
                    pstrCurrChannelVars->pkstrCurrTPTxNsdu->u8NAD;
                /*!Set the function return to E_OK */
                udtRet = E_OK;
                /*!If the frame type is u8FIRST_FRAME_TYPE */
                if(u8FIRST_FRAME_TYPE == u8FrameType)
                {
                    /*!Set PCI 0x1X where X is the 4 MSBs of the input message
                        length */
                    /*!Set au8TPDataBuffer[2] to the remaininf 8 bits of the 
                        input length*/
                    /*\Trace_To: LinIf-CDD-0420(0) */
                    /*\Trace_To: LinIf-CDD-0424(0) */
                    u8PCI = (uint8)u8PCI_BASE_FIRST_F 
                            |
                            (uint8)((udtTPMessageLength>>8) & 0x000F);

                    pstrCurrChannelVars->au8TPDataBuffer[2] = 
                        (uint8)(udtTPMessageLength & 0x00FF);

                }
                /*!Else If the frame type is u8SINGLE_FRAME_TYPE */
                else if(u8SINGLE_FRAME_TYPE == u8FrameType)
                {
                    /*!Set PCI 0x0X where X is the input message length */
                    /*\Trace_To: LinIf-CDD-0420(0) */
                    u8PCI = u8PCI_BASE_SINGLE_F | ((u8DataLength)&0x0F);
                }
                /*!Else If the frame type is u8CONSEC_FRAME_TYPE */
                else if(u8CONSEC_FRAME_TYPE == u8FrameType)
                {
                    /*!Set PCI 0x2X where X is 4 LSBs of u8TPNextSeqNum  */
                    /*\Trace_To: LinIf-CDD-0420(0) */
                    /*\Trace_To: LinIf-CDD-0423(0) */
                    u8PCI = u8PCI_BASE_CONSEC_F 
                            | 
                            (pstrCurrChannelVars->u8TPNextSeqNum & 0x0F);

                    /*!Increment u8TPNextSeqNum by 1 modulo 15*/
                    pstrCurrChannelVars->u8TPNextSeqNum = 
                        (pstrCurrChannelVars->u8TPNextSeqNum + 1) & 0x0F;
                }
                /*!Else (the frame type is invalid) */
                else
                {
                    u8PCI = 0;
                    /*!Set the return of the function to E_NOT_OK*/
                    udtRet = E_NOT_OK;
                }
                /*!End If */
                /*!Set au8TPDataBuffer[1] to PCI */
                pstrCurrChannelVars->au8TPDataBuffer[1] = u8PCI;
            }
            /*!Else (return of CopyTxData is not BUFREQ_OK) */
            else
            {
                /*!Set bTPDataAvailable to FALSE to indicate that there is no
                    data for the next frame */
                /*\Trace_To: LinIf-CDD-0119(0) */
                pstrCurrChannelVars->bTPDataAvailable = FALSE;

                /*!If the return of CopyTxData is BUFREQ_E_BUSY */
                if (BUFREQ_E_BUSY == udtCopyTxRet)
                {
                    /*!Set the return of the function to E_OK (the UL did not
                        indicate a failure) */
                    udtRet = E_OK;
                }
                /*!Else (return of CopyTxData is not BUFREQ_E_BUSY) */
                /*\Trace_To: LinIf-CDD-0123(0) */
                else /* BUFREQ_E_OVFL, BUFREQ_E_NOT_OK, and any other invalid
                        value */
                {
                    /*!Set the return of the function to E_NOT_OK */
                    udtRet = E_NOT_OK;
                }
                /*!End If */
            }
            /*!End If */
        }
        else
        {
            /*!Set bTPDataAvailable to FALSE to indicate that there is no data for
                the next frame */
            pstrCurrChannelVars->bTPDataAvailable = FALSE;
            /*!Set the return of the function to E_OK (the UL did not indicate a
            failure) */
            udtRet = E_OK;
        }
        /*!End If */
    }
    /*!Else If the return of the polling is BUFREQ_E_BUSY */
    else if (BUFREQ_E_BUSY == udtCopyTxRet)
    {
        /*!Set bTPDataAvailable to FALSE to indicate that there is no data for
        the next frame */
        pstrCurrChannelVars->bTPDataAvailable = FALSE;
        /*!Set the return of the function to E_OK (the UL did not indicate a
            failure) */
        udtRet = E_OK;
    }
    /*!Else (return of CopyTxData is not BUFREQ_E_NOT_OK or BUFREQ_E_OVFL or 
        another invalid value) */
    else
    {
        /*!Set the function return to E_NOT_OK */
        /*\Trace_To: LinIf-CDD-0288(0) */
        udtRet = E_NOT_OK;
    }

    /*!Return the stored function return value */
    return udtRet;
/*!Deviation : Inhibit MISRA rule [4700]: No further simplification is       */
/*              possible                                                      */
/* PRQA S 4700 ++                                                             */
}
/* PRQA S 4700 --                                                             */
#endif

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function    : LinIf_vidTPSendFrame                                        */
/*!\Description    Called by STM to instruct the TP to send an MRF or an SRF\n
    \param[in]      The index of the channel where the message is transmitted \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n
    \param[in]      Pointer to the frame to be sent \n
        \Range          NOT NULL \n                                           */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidTPSendFrame(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrameToSend)
{
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    pstrCurrChannelVars->pkstrCurrentFrame = pkstrFrameToSend;

    /*!If the enuFrameType of the input frame is one of the  TP Tx messages 
        (MRF or Node Configuration Frame) */
    if((uint8)(((uint8)(pkstrFrameToSend->enuFrameType)) & u8TXTPMASK) 
        ==
        u8TXTPMASK)
    {
#if (LinIf_u8TP_SUPPORTED == STD_ON)
        /*!Set bNConfMRFFailed to FALSE */
        pstrCurrChannelVars->bNConfMRFFailed = FALSE;
        
        /*!If the enuFrameType is an MRF */
        if(LinIf_MRF == pkstrFrameToSend->enuFrameType) /* MRF */
        {
            vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_E_NOT_OK, FALSE);
            /*!Reset the state that a slave responded with RPF frames more
                than allowed by setting bTPUDSRPFMaxReached to false */
            pstrCurrChannelVars->bTPUDSRPFMaxReached = FALSE;
            /*!Set bIsNConfOngoing to FALSE */
            pstrCurrChannelVars->bIsNConfOngoing = FALSE;

            /*!If the bTPDataAvailable is TRUE (there is data to be sent) */
            /*\Trace_To: LinIf-CDD-0028(0) */
            /*\Trace_To: LinIf-CDD-0119(0) */
            if(TRUE == pstrCurrChannelVars->bTPDataAvailable)
            {
                
                /*!Start the N_As timeout by setting u16TPTimoutTimer to 
                pkstrGlobalTPConfigPtr->u16LinTpNAs */ 
                /*\Trace_To: LinIf-CDD-0435(0) */
                pstrCurrChannelVars->u16TPTimoutTimer = 
                    pkstrGlobalTPConfigPtr->u16LinTpNAs + 1;

                /*! Set u8CurrentTxTimeout to u8TIMEOUT_AS */
                pstrCurrChannelVars->u8CurrentTxTimeout = u8TIMEOUT_AS;

                /*!Call vidCopyFrame to copy the data in au8TPDataBuffer to the
                    IF data buffer au8DataBuffer with the current frame length 
                    with the appropriate length according to PCI */
                if(
                    (pstrCurrChannelVars->au8TPDataBuffer[1] & 
                                                        u8HIGH_4_BIT_MASK)
                    == u8PCI_BASE_FIRST_F)
                {
                    vidCopyFrame
                    ((const uint8 *)pstrCurrChannelVars->au8TPDataBuffer,
                    pstrCurrChannelVars->au8DataBuffer,
                    8);
                }
                else
                {
                    vidCopyFrame
                    ((const uint8 *)pstrCurrChannelVars->au8TPDataBuffer,
                    pstrCurrChannelVars->au8DataBuffer,
                    pstrCurrChannelVars->u8CurrTPFrameLength + 2);
                }
                /*!Call LinIf_vidIFSendFrame with the maximum Lin frame size */
                /*\Trace_To: LinIf-CDD-0028(0) */
                LinIf_vidIFSendFrame(u8ChannelIndex, LinIf_u8FRAME_SIZE);

                /*!Set bTPDataAvailable to FALSE */
                pstrCurrChannelVars->bTPDataAvailable = FALSE;
                /*!Set bTpFrameSent to FALSE */
                pstrCurrChannelVars->bTpFrameSent = TRUE;
            }
            /*!Else do nothing do not send the MRF*/
            /*!EndIf */
        }
        /*\Trace_To: LinIf-CDD-5007(0) */
        /*\Trace_To: LinIf-CDD-5008(0) */
        /*!Else (the frame type is a NC frame */
        else /* Node configuration frames */
        {
#endif

            VAR(uint8_least, AUTOMATIC)                  u8LoopIndex;
            P2CONST(uint8, AUTOMATIC, LINIF_CALIB_CONST) pku8FixedFrameBuffer;
            P2VAR(uint8, AUTOMATIC, LINIF_VAR)           pu8FrameBuffer;

            
            pku8FixedFrameBuffer = 
                pstrCurrChannelVars->pkstrCurrentFrame->pku8FixedFrameData;

            pu8FrameBuffer = 
                pstrCurrChannelVars->au8DataBuffer;

            /*!Copy pku8FixedFrameData of the input frame to au8DataBuffer */
            /*\Trace_To: LinIf-CDD-0098(0) */
            /*\Trace_To: LinIf-CDD-5007(0) */
            /*\Trace_To: LinIf-CDD-0094(0) */
            /*\Trace_To: LinIf-CDD-5007(0) */
            /*\Trace_To: LinIf-CDD-5008(0) */
            for(u8LoopIndex = 0;
                u8LoopIndex < LinIf_u8FRAME_SIZE;
                u8LoopIndex++)
            {
                pu8FrameBuffer[u8LoopIndex] = pku8FixedFrameBuffer[u8LoopIndex];
            }

            /*!Call LinIf_vidIFSendFrame with the maximum Lin frame size */
            LinIf_vidIFSendFrame(u8ChannelIndex, LinIf_u8FRAME_SIZE);

            /*!Set u8NCSlaveIndex of the channel to u8NCSlaveIdx of the frame*/
            pstrCurrChannelVars->u8NCSlaveIndex = 
                pstrCurrChannelVars->pkstrCurrentFrame->u8NCSlaveIdx;

#if (LinIf_u8TP_SUPPORTED == STD_ON)
            /*!Set bIsNConfOngoing to TRUE */
            pstrCurrChannelVars->bIsNConfOngoing = TRUE;
        }
#endif
        
        /*!EndIf */
    }
    /*!Else (the frame type SRF) */
    else /* LinIf_SRF */
    {

        /*!If bNConfMRFFailed is TRUE set it to FALSE and don't send the SRF*/
        if(FALSE != pstrCurrChannelVars->bNConfMRFFailed)
        {
            pstrCurrChannelVars->bNConfMRFFailed = FALSE;
        }

        /*!Else*/
        /*\Trace_To: LinIf-CDD-0029(0) */
        /*\Trace_To: LinIf-CDD-0143(0) */
        else
#if (LinIf_u8TP_SUPPORTED == STD_ON)
        {
			/*! AMET There is A bug here it Clear bTPDataAvailable for the current MRF Transmission*/
				/*! It's Removed because there is a debate around it around if MRF and SRF are in the 
					same Scedule table or Not*/		
			/*!if (pstrCurrChannelVars->udtTPRemData == 0 && pstrCurrChannelVars->bTPDataAvailable == FALSE)
			{
				vidStopCurrTransMsg(u8ChannelIndex, NTFRSLT_E_NOT_OK, FALSE);	
			}*/
            /*!If pkstrCurrTPRecNsdu is not NULL (there is Tp Rx Message 
            on going) */ 
			
            if(pstrCurrChannelVars->pkstrCurrTPRecNsdu != 
                (P2CONST(LinIf_tstrTPReceivedNSdu, AUTOMATIC, 
                LINIF_CALIB_CONST))NULL_PTR)
            {
                /*!If the bTPDataAvailable is False (no pending data 
                waiting to be copied to the upper layer) */
                if(FALSE == pstrCurrChannelVars->bTPDataAvailable)
                {
                    /*!Call LinIf_vidIFSendFrame to send the frame with
                    the maximum size of a Lin Frame */
                    LinIf_vidIFSendFrame(u8ChannelIndex, LinIf_u8FRAME_SIZE);
                }
                /*!EndIf */
            }
            /*!Else */
            else
#endif
/*!Deviation :  Inhibit MISRA rule [2209]: the brace style is not because it  */
/*              is shared between 2 configurations                            */
/* PRQA S 2209 ++                                                             */
            {
/* PRQA S 2209 --                                                             */
                /*!Call LinIf_vidIFSendFrame to send the frame with
                the maximum size of a Lin Frame */
                LinIf_vidIFSendFrame(u8ChannelIndex, LinIf_u8FRAME_SIZE);
            }
            /*!EndIf */
#if (LinIf_u8TP_SUPPORTED == STD_ON)
        }
        /*!EndIf */
#endif
    }
    /*!EndIf */
}

#if(LinIf_u8TP_SUPPORTED == STD_ON)
/******************************************************************************/
/*!Function    : LinIf_vidTPMain                                             */
/*!\Description    The Main executing function of the TP \n
    \param[in]      Pointer to a channel's post-build structure to operate on \n
        \Range          NOT NULL \n                                           */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidTPMain(
    P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_CALIB_CONST) pkstrChannel)
{
    VAR(uint8, AUTOMATIC)                               u8ChannelIndex;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;
    u8ChannelIndex = pkstrChannel->u8ChannelIndx;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    
    switch(pstrCurrChannelVars->u8TPCommState)
    {
    /*!If the input's channel u8TPCommState is u8TP_STATE_IDLE */
    case u8TP_STATE_IDLE:
        /* do nothing */
        break;
    /*!Else If the input's channel u8TPCommState is u8TP_STATE_TRANS */
    case u8TP_STATE_TRANS:
        {
            /*!Call vidHandleTransmission to continue with message
            transmission */
            /*\Trace_To: LinIf-CDD-0120(0) */
            vidHandleTransmission(u8ChannelIndex);
        }
        break;

    /*!Else If the input's channel u8TPCommState is u8TP_STATE_REC */
    case u8TP_STATE_REC:
        {
            /*!Call vidHandleReception to continue with message
            reception */
            vidHandleReception(u8ChannelIndex);
        }
        break;
        /*!EndIf */
    default:
        break;
    }
}


/******************************************************************************/
/*!Function    : LinIf_vidTPTimeoutHandler                                    */
/*!\Description    The function that handle timeouts of the TP \n
    \param[in]      Pointer to a channel's post-build structure to operate on \n
        \Range          NOT NULL \n                                           */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidTPTimeoutHandler(
    P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_CALIB_CONST) pkstrChannel)
{
    VAR(uint8, AUTOMATIC)                               u8ChannelIndex;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;
    u8ChannelIndex = pkstrChannel->u8ChannelIndx;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    
    switch(pstrCurrChannelVars->u8TPCommState)
    {
    /*!If the input's channel u8TPCommState is u8TP_STATE_IDLE */
    case u8TP_STATE_IDLE:
        /*!monitor P2 and P2Max Timing: */
        /*!If u16TPTimoutTimer != 0 */
        if(0 != pstrCurrChannelVars->u16TPTimoutTimer)
        {
            /*\Trace_To: LinIf-CDD-0135(0) */
            /*\Trace_To: LinIf-CDD-0136(0) */
            /*!Decrement u16TPTimoutTimer by 1 */
            pstrCurrChannelVars->u16TPTimoutTimer--;
            /*!If u16TPTimoutTimer reacehs 0 */
            if(0 == pstrCurrChannelVars->u16TPTimoutTimer)
            {
                /*!Call BswM_LinTp_RequestMode with input 
                    LINTP_APPLICATIVE_SCHEDULE to request switch to applicative 
                    schedule */
                BswM_LinTp_RequestMode(
                    LinIf_udtGetChannelIdByIndex(u8ChannelIndex),
                    LINTP_APPLICATIVE_SCHEDULE);
            }
            /*!EndIf */
        }
        break;
    /*!Else If the input's channel u8TPCommState is u8TP_STATE_TRANS */
    case u8TP_STATE_TRANS:
        {
            /*!monitor N_As Timeout: */
            /*!If u16TPTimoutTimer != 0 */
            if(0 != pstrCurrChannelVars->u16TPTimoutTimer)
            {
                /*!Decrement u16TPTimoutTimer by 1 */
                /*\Trace_To: LinIf-CDD-0434(0) */
                pstrCurrChannelVars->u16TPTimoutTimer--;
                /*!If u16TPTimoutTimer reacehs 0 */
                if(0 == pstrCurrChannelVars->u16TPTimoutTimer)
                {
                    /*! If u8CurrentTxTimeout = AS */
                    if(pstrCurrChannelVars->u8CurrentTxTimeout == u8TIMEOUT_AS)
                    {
                        /*!Call vidStopCurrRxMsg with result = 
                            NTFRSLT_E_TIMEOUT_A */
                        vidStopCurrTransMsg(u8ChannelIndex,
                                            NTFRSLT_E_TIMEOUT_A,
                                            TRUE);
                    }
                    /*! Else (CS) */
                    else
                    {
                        /*!Call vidStopCurrRxMsg with result = 
                            NTFRSLT_E_NOT_OK */
                        vidStopCurrTransMsg(u8ChannelIndex,
                                            NTFRSLT_E_NOT_OK,
                                            TRUE);
                    }
                    /*! End if*/

                    /*! Set u8TPLastAdrsdNAD to 0 so that no reception is
                        started unless a transmission is completed */
                    pstrCurrChannelVars->u8TPLastAdrsdNAD = 0;
                }
                /*!EndIf */
            }
            /*!EndIf */
        }
        break;

    /*!Else If the input's channel u8TPCommState is u8TP_STATE_REC */
    case u8TP_STATE_REC:
        {
            /*!monitor N_Cr and P2Max Timeouts: */
            /*!If u16TPTimoutTimer != 0 */
            if(0 != pstrCurrChannelVars->u16TPTimoutTimer)
            {
                /*!Decrement u16TPTimoutTimer by 1 */
                /*\Trace_To: LinIf-CDD-0433(0) */
                pstrCurrChannelVars->u16TPTimoutTimer--;
                /*!If u16TPTimoutTimer reacehs 0 */
                if(0 == pstrCurrChannelVars->u16TPTimoutTimer)
                {
                    /*! If bTPDataAvailable = true then it is a buffer request 
                        timeout, so call vidStopCurrRxMsg with result = 
                        NTFRSLT_E_NOT_OK else it is a N_Cr timeout so call
                        vidStopCurrRxMsg with 
                        result = NTFRSLT_E_TIMEOUT_CR */
                    if(pstrCurrChannelVars->bTPDataAvailable != FALSE)
                    {
                        vidStopCurrRxMsg(   u8ChannelIndex,
                                            NTFRSLT_E_NOT_OK,
                                            TRUE);
                    }
                    else
                    {
                        vidStopCurrRxMsg(   u8ChannelIndex,
                                            NTFRSLT_E_TIMEOUT_CR,
                                            TRUE);
                    }
                }
                /*!EndIf */
            }
            /*!EndIf */
        }
        break;
        /*!EndIf */
    default:
        break;
    }
/*!Deviation : Inhibit MISRA rule [4700]: No further simplification is       */
/*              possible                                                      */
/* PRQA S 4700 ++                                                             */
}
/* PRQA S 4700 --                                                             */

#endif
/******************************************************************************/
/*!Function    : LinIf_vidTPTxConf                                           */
/*!\Description    Call back from If that a TP frame \n
    \param[in]      The index of the channel where the frame is transmitted \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n
    \param[in]      Boolean to indicate that the frame transmission was 
                    successful or not \n
        \Range          FALSE, TRUE \n                                        */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidTPTxConf(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    VAR(boolean, AUTOMATIC) bTransmissionOK)
{
#if(LinIf_u8TP_SUPPORTED == STD_ON)
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    
    /*! If bTpFrameSent is false (no frame sent or the 
        message has been stopped) do nothing and ignore the confirmation */
    if(FALSE == pstrCurrChannelVars->bTpFrameSent)
    {
    }
    /*! Else if bIsNConfOngoing is TRUE */
    else if(FALSE != pstrCurrChannelVars->bIsNConfOngoing)
    {
#endif
        /*! If bTransmissionOK is FALSE */
        if(FALSE == bTransmissionOK)
        {
            /*!Set bNConfMRFFailed to TRUE */
#if(LinIf_u8TP_SUPPORTED == STD_ON)
            pstrCurrChannelVars->bNConfMRFFailed = TRUE;
#else
            LinIf_astreChannelsVars[u8ChannelIndex].bNConfMRFFailed = TRUE; /*Check it may be wrong*/
#endif
            /*!Note that P2 timeout is not started because there may not 
               be an SRF after the NC command */
        }
        /*!EndIf */
#if(LinIf_u8TP_SUPPORTED == STD_ON)
    }
    /*!EndIf */
    /*!Else (bIsNConfOngoing is FALSE) */
    else
    {
        /*! If bTransmissionOK is TRUE */
        if(FALSE != bTransmissionOK)
        {
            /*!If the message transmission is finished (udtTPRemData = 0)*/
            if(0 == pstrCurrChannelVars->udtTPRemData)
            {
                /*! If the NAD of the finished Message is not 0x7E 
                    (Functional NAD) or 0x7F (Broadcast NAD) */
                if( (pstrCurrChannelVars->pkstrCurrTPTxNsdu->u8NAD 
                            != u8FUNCTIONAL_NAD)
                    &&
                    (pstrCurrChannelVars->pkstrCurrTPTxNsdu->u8NAD 
                            != u8BROADCAST_NAD))
                {
                    /*! Set u8TPLastAdrsdNAD to the NAD of the finished 
                        Message */
                    pstrCurrChannelVars->u8TPLastAdrsdNAD = 
                            pstrCurrChannelVars->pkstrCurrTPTxNsdu->u8NAD;
                }
                /*!Call vidStopCurrTransMsg with result = NTFRSLT_OK to 
                    indicate successful transmission of a message */
                /*\Trace_To: LinIf-CDD-0121(0) */
				/*! AMET There is A bug here it Clear bTPDataAvailable for the current MRF Transmission at the Last Consecutive frame*/
                vidStopCurrTransMsg(u8ChannelIndex, NTFRSLT_OK, FALSE);
                
                /*!Start the P2Timout by setting u16TPTimoutTimer to 
                    pkstrGlobalTPConfigPtr->u16LinTpP2Timing + 1*/
                /*\Trace_To: LinIf-CDD-0412(0) */
                pstrCurrChannelVars->u16TPTimoutTimer = 
                    pkstrGlobalTPConfigPtr->u16LinTpP2Timing + 1;
            }
            /*!Else (udtTPRemData > 0) */
            else
            {
			  /*! AMET put new solution here "pstrCurrChannelVars->udtTPRemData -= pstrCurrChannelVars->u8CurrTPFrameLength"*/
                /*!Start the N_Cs timeout by setting u16TPTimoutTimer to 
                    pkstrGlobalTPConfigPtr->u16LinTpNCs + 1*/
                /*\Trace_To: LinIf-CDD-0435(0) */
				pstrCurrChannelVars->udtTPRemData -= pstrCurrChannelVars->u8CurrTPFrameLength;
                pstrCurrChannelVars->u16TPTimoutTimer = 
                    pkstrGlobalTPConfigPtr->u16LinTpNCs + 1;

                /*! Set u8CurrentTxTimeout to u8TIMEOUT_CS */
                pstrCurrChannelVars->u8CurrentTxTimeout = u8TIMEOUT_CS;
            }
            /*!EndIf */
        }
        /*!Else (bTransmissionOK is FALSE) */
        else
        {
            /*!Call vidStopCurrTransMsg with result = NTFRSLT_E_NOT_OK
                to indicate that an MRF sending process failed */
            /*\Trace_To: LinIf-CDD-0122(0) */
            vidStopCurrTransMsg(u8ChannelIndex, NTFRSLT_E_NOT_OK, TRUE);

            /*! Set u8TPLastAdrsdNAD to 0 so that no reception is started 
                unless a transmission is completed */
            pstrCurrChannelVars->u8TPLastAdrsdNAD = 0;
        }
        /*!EndIf */
    
    }
    /*!EndIf */
#endif
}
/******************************************************************************/
/*!Function    : LinIf_vidTPRxInd                                            */
/*!\Description    Call back from If that a TP frame is successfully received\n
    \param[in]      The index of the channel where the frame is received \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n                  */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidTPRxInd(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    VAR(uint8, AUTOMATIC)                               u8PCI;
#if(LinIf_u8TP_SUPPORTED == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)                      udtTemp;
    VAR(PduLengthType, AUTOMATIC)                       udtMessageLength;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;
    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    
    if(pstrCurrChannelVars->u8TPCommState != u8TP_STATE_TRANS)
    {
        /*!Extract the PCI byte from the second byte in au8DataBuffer */
        /*\Trace_To: LinIf-CDD-0419(0) */
        /*\Trace_To: LinIf-CDD-0420(0) */
        u8PCI = pstrCurrChannelVars->au8DataBuffer[1];
#else
        u8PCI = LinIf_astreChannelsVars[u8ChannelIndex].au8DataBuffer[1]; /*Check it may be wrong*/
#endif

#if(LinIf_u8TP_SUPPORTED == STD_ON)
        /* If the PCI byte 4 MSBs indicated that the frame is FF or SF */
        /*\Trace_To: LinIf-CDD-0134(0) */
        /*\Trace_To: LinIf-CDD-0419(0) */
        /*\Trace_To: LinIf-CDD-0420(0) */
        if( ((u8PCI & u8HIGH_4_BIT_MASK) == u8PCI_BASE_FIRST_F)
            ||
            ((u8PCI & u8HIGH_4_BIT_MASK) == u8PCI_BASE_SINGLE_F))
        {
            /*!If bIsNConfOngoing = false (there is no NC frame sent before */
            if(FALSE == pstrCurrChannelVars->bIsNConfOngoing)
            {
                /*!Call vidStopCurrRxMsg with result NTFRSLT_E_UNEXP_PDU to stop
                    any ongoing Rx message (if there is one)*/ 
                /*\Trace_To: LinIf-CDD-0132(0) */
                vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_E_UNEXP_PDU, FALSE);

                /*!Call udtValidateNewRxMsg to validate the new message from the
                    frame, and get the message length */
                /*\Trace_To: LinIf-CDD-0125(0) */
                udtTemp = 
                    udtValidateNewRxMsg(u8ChannelIndex, &udtMessageLength);

                /*!If the validation result = E_OK */
                if(E_OK == udtTemp)
                {
                    VAR(boolean, AUTOMATIC) bIsRPF;
                    /*!Call u8CopyTpDataFromFrame to copy extract the TP payload
                        + getting payload's length and store the length in 
                        u8CurrTPFrameLength*/
                    pstrCurrChannelVars->u8CurrTPFrameLength = 
                        u8CopyTpDataFromFrame(u8ChannelIndex);
                    /*!Set udtTPCurrRxMsgLen to the output message length from
                        udtValidateNewRxMsg */
                    pstrCurrChannelVars->udtTPCurrRxMsgLen = udtMessageLength;

                    /*!Call vidHandleSFAndFF to process the received frame */
                    vidHandleSFAndFF(u8ChannelIndex);
                    /*!Call bIsRespPendFrame to check if received frame is a 
                        ResponsePendingFrame */
                    /*\Trace_To: LinIf-CDD-0138(0) */
                    bIsRPF = bIsRespPendFrame(u8ChannelIndex);


                    /*!If the frame is not RPF */
                    if(FALSE == bIsRPF)
                    {
                        /*! If there is remaining data (a FF received or the 
                            data of the received SF data is not yet passed to 
                            the upper layer*/
                        if(pstrCurrChannelVars->udtTPRemData > 0)
                        {
                            /*!Start N_Cr timeout by setting u16TPTimoutTimer to
                                pkstrGlobalTPConfigPtr->u16LinTpNCr */
                            /*\Trace_To: LinIf-CDD-0435(0) */
                            pstrCurrChannelVars->u16TPTimoutTimer = 
                                pkstrGlobalTPConfigPtr->u16LinTpNCr + 1;
                        }
                        /*!Reset u16TPUDSPendFrameCnt to 0 */
                        pstrCurrChannelVars->u16TPUDSPendFrameCnt = 0;
                    }
                    /*!Else (the frame is RPF) */
                    else
                    {
                        /*!Start P2Max timeout by setting u16TPTimoutTimer to 
                            pkstrGlobalTPConfigPtr->u16LinTpP2Max */
                        /*\Trace_To: LinIf-CDD-0138(0) */
                        pstrCurrChannelVars->u16TPTimoutTimer = 
                            pkstrGlobalTPConfigPtr->u16LinTpP2Max + 1;

                        /*!Increment u16TPUDSPendFrameCnt by 1 */
                        pstrCurrChannelVars->u16TPUDSPendFrameCnt++;
                        
                        /*!If u16TPUDSPendFrameCnt reaches the configured 
                            maximum number of RPFs 
                            (pkstrGlobalTPConfigPtr->u16LinTpMaxUDSRPF) */
                        /*\Trace_To: LinIf-CDD-0140(0) */
                        if( pstrCurrChannelVars->u16TPUDSPendFrameCnt 
                            >
                            pkstrGlobalTPConfigPtr->u16LinTpMaxUDSRPF)
                        {
                            /*!Call BswM_LinTp_RequestMode with input 
                            LINTP_APPLICATIVE_SCHEDULE to request switch to 
                            applicative schedule */
                            BswM_LinTp_RequestMode(
                                LinIf_udtGetChannelIdByIndex(u8ChannelIndex),
                                LINTP_APPLICATIVE_SCHEDULE);

                            /*!Reset u16TPUDSPendFrameCnt to 0 */
                            pstrCurrChannelVars->u16TPUDSPendFrameCnt = 0;
                            /*!Set bTPUDSRPFMaxReached to TRUE */
                            pstrCurrChannelVars->bTPUDSRPFMaxReached = TRUE;
                            /*! Reset u16TPTimoutTimer to 0 to stop timeout 
                                monitoring */
                            pstrCurrChannelVars->u16TPTimoutTimer = 0;
                        }
                        /*!EndIf */
                    }
                    /*!EndIf */
                }
                /*!Else (the validation result is E_NOT_OK) */
                else
                {
                    /*!Do nothing, the message is dropped. */
                }
            }
            /*!Else (There is Node configuration frames sent) */
            /*\Trace_To: LinIf-CDD-0099(0) */
            else
            {
#endif
                /*!If PCI of the received frame indicated that it is not a SF)*/
                /*\Trace_To: LinIf-CDD-0420(0) */
                if((u8PCI & u8HIGH_4_BIT_MASK) != u8PCI_BASE_SINGLE_F)
                {
                    /*!Call LinIf_vidTPSRFNoResp to indicate that the slave did 
                        not respond to a NC frame*/
                    /*\Trace_To: LinIf-CDD-0100(0) */
                    LinIf_vidTPSRFNoResp(u8ChannelIndex);
                }
#if(LinIf_u8TP_SUPPORTED == STD_ON)
                /*!Else (the received frame is single frame) */
                else
                {
                    /*!Set bIsNConfOngoing to FALSE */
                    pstrCurrChannelVars->bIsNConfOngoing = FALSE;
                }
                /*!EndIf */
            }
            /*!EndIf */
        }
        /*!Else if the PCI received indicated a CF */
        /*\Trace_To: LinIf-CDD-0420(0) */
        else if((u8PCI & u8HIGH_4_BIT_MASK) == u8PCI_BASE_CONSEC_F)
        {
            /*!If the u8TPCommState of the channel is u8TP_STATE_REC */
            if(u8TP_STATE_REC == pstrCurrChannelVars->u8TPCommState)
            {
                /*!Accept the CF by Calling vidHandleCFRec and start the N_Cr 
                    timeout by setting u16TPTimoutTimerto u16LinTpNCr if there 
                    is still data to be received (udtTPRemData > 0) */
                vidHandleCFRec(u8ChannelIndex);
                if(pstrCurrChannelVars->udtTPRemData != 0)
                {
                    pstrCurrChannelVars->u16TPTimoutTimer = 
                    pkstrGlobalTPConfigPtr->u16LinTpNCr + 1;
                }
            }
            /*!Else */
            /*\Trace_To: LinIf-CDD-0131(0) */
            /*\Trace_To: LinIf-CDD-0134(0) */
            else
            {
                /*!Drop the frame, and Call BswM_LinTp_RequestMode with input 
                    LINTP_APPLICATIVE_SCHEDULE to request switch to applicative 
                    schedule */ 
                BswM_LinTp_RequestMode(
                    LinIf_udtGetChannelIdByIndex(u8ChannelIndex),
                    LINTP_APPLICATIVE_SCHEDULE);
            }
            /*!End If */
        }
        /*!Else (Invalid PCI) */
        /*\Trace_To: LinIf-CDD-0127(0) */
        else /* Invalid PCI */
        {
            /*!Call vidStopCurrRxMsg with result = NTFRSLT_E_UNEXP_PDU to stop 
                the current Rx Message (If any) */
            vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_E_UNEXP_PDU, TRUE);

            /*!Call BswM_LinTp_RequestMode with LINTP_APPLICATIVE_SCHEDULE to 
                request a schedule switch */
            BswM_LinTp_RequestMode(
                LinIf_udtGetChannelIdByIndex(u8ChannelIndex),
                LINTP_APPLICATIVE_SCHEDULE);
        }
        /*!End If */
    }
    /*!End If */
#endif
/*!Deviation : Inhibit MISRA rule [4700]: No further simplification is       */
/*              possible                                                      */
/* PRQA S 4700 ++                                                             */
}
/* PRQA S 4700 --                                                             */

/******************************************************************************/
/*!Function    : LinIf_vidTPSRFNoResp                                        */
/*!\Description    Call back from If that an SRF was not responded to \n
    \param[in]      The index of the channel where the frame is received \n
        \Range          0..LinIf_ku8eNumberOfChannels - 1 \n                  */
/*\Trace_To    : LinIf-CDD-0100(0)                                           */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidTPSRFNoResp(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;
    P2CONST(LinIf_tstrChannelSlaveParams, AUTOMATIC, LINIF_VAR) 
                                                        pkstrAddressedSlave;
    VAR(uint16, AUTOMATIC)                              u16AddressedSlaveIndex;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
#if(LinIf_u8TP_SUPPORTED == STD_ON)
    /*!If bIsNConfOngoing is TRUE */
    /*\Trace_To: LinIf-CDD-0448(0) */
    if(FALSE != pstrCurrChannelVars->bIsNConfOngoing)
    {
#endif
        /*!Report to DEM the pkudtENCNoResponse (if it is configured 
            ofcourse) of the slave whose index in the channel is 
            u8NCSlaveIndex */ 
        u16AddressedSlaveIndex = pstrCurrChannelVars->u8NCSlaveIndex 
                                 +
                                 LinIf_akstreChannelsLT[u8ChannelIndex].
                                    u8SlavesIndex;

        pkstrAddressedSlave = &LinIf_akstreSlaves[u16AddressedSlaveIndex];

        if( (P2CONST(Dem_EventIdType, LINIF_CFG_CONST, LINIF_CFG_CONST))NULL_PTR
            != 
            pkstrAddressedSlave->pkudtENCNoResponse)
        {
            Dem_ReportErrorStatus(
                *(pkstrAddressedSlave->pkudtENCNoResponse),
                DEM_EVENT_STATUS_FAILED);

        }

#if(LinIf_u8TP_SUPPORTED == STD_ON)
        /*!Set bIsNConfOngoing to FALSE */
        pstrCurrChannelVars->bIsNConfOngoing = FALSE;
    }
    /*!EndIf */
#endif
}

#if(LinIf_u8TP_SUPPORTED == STD_ON)
/******************************************************************************/
/*!Function    : LinTp_Init                                                  */
/*!\Description    Initializes the LIN Transport Layer. \n
    \param[in]      Pointer to a Post-Build configuration structure for LinTp\n
        \Range          NOT NULL \n                  */
/*\Trace_To    : LinIf-CDD-0234(0)                                           */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinTp_Init(
    P2CONST(LinTp_ConfigType, AUTOMATIC, LINIF_APPL_CONST) pkstrTpConfigPtr)
{
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is not LinIf_u8STATE_INIT report to 
        DET LINIF_E_UNINIT*/
    /*\Trace_To: LinIf-CDD-5034(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_INIT_ID,
            LINIF_E_UNINIT);
    }
    /*!Else If the LinIf_u8LinTpState is LinIf_u8STATE_INIT report to 
        DET LINIF_E_ALREADY_INITIALIZED*/
    /*\Trace_To: LinIf-CDD-0239(0) */
    else if(LinIf_u8STATE_INIT == LinIf_u8LinTpState)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_INIT_ID,
            LINIF_E_ALREADY_INITIALIZED);
    }
    /*!Else If the pkstrTpConfigPtr is NULL_PTR report to 
        DET LINIF_E_PARAMETER_POINTER */
    /*\Trace_To: LinIf-CDD-0238(0) */
    else if((P2CONST(LinTp_ConfigType, AUTOMATIC, LINIF_APPL_DATA))NULL_PTR
             ==
             pkstrTpConfigPtr)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_INIT_ID,
            LINIF_E_PARAMETER_POINTER);
    }
    /*!Else */
    else
    {
#endif
        VAR(uint8_least, AUTOMATIC) u8LoopIndex;
        /*!Store the input pointer into the local pointer 
            pkstrGlobalTPConfigPtr */
        /*\Trace_To: LinIf-CDD-0235(0) */
        /*\Trace_To: LinIf-CDD-5113(0) */
        pkstrGlobalTPConfigPtr = pkstrTpConfigPtr;

        /*!Call vidResetChannelVars for each channel */
        for(u8LoopIndex = 0;
            u8LoopIndex < LinIf_ku8eNumberOfChannels; 
            u8LoopIndex++)
        {
            /*\Trace_To: LinIf-CDD-0237(0) */
            vidResetChannelVars(u8LoopIndex);
            /*!Set u8TPChannelState to IDLE */
            LinIf_astreChannelsVars[u8LoopIndex].u8TPChannelState = 
                                                            u8TP_CHANNEL_IDLE;
        }
        /*!Set LinIf_u8LinTpState to LinIf_u8STATE_UNINIT */
        LinIf_u8LinTpState = LinIf_u8STATE_INIT;
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    }
    /*!EndIf */
#endif
}

/******************************************************************************/
/*!Function    : LinTp_Transmit                                              */
/*!\Description    Requests the transfer of segmented data. \n
    \param[in]      Nsdu Id of the requested Message \n
        \Range          0..pkstrGlobalTPConfigPtr->u16NumberOfTxNsdus - 1 \n
    \param[in]      Pointer to the data (not used) \n
        \Range          NOT NULL \n
    \return         E_OK: The request can be started successfully \n
                    E_NOT_OK: The request can not be started (e.g. there is
                    already an ongoing TP message on the selected channel) \n */
/*\Trace_To    : LinIf-CDD-0240(0)                                           */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinTp_Transmit(
    VAR(PduIdType, AUTOMATIC) udtLinTpTxSduId, 
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) pkstrLinTpTxInfoPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) udtRet;


#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is not LinIf_u8STATE_INIT report to 
        DET LINIF_E_UNINIT*/
    /*\Trace_To: LinIf-CDD-5036(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_TRANSMIT_ID,
            LINIF_E_UNINIT);
        udtRet = E_NOT_OK;
    }


    /*!Else If the LinIf_u8LinTpState is not LinIf_u8STATE_INIT report to 
        DET LINIF_E_UNINIT*/
    /*\Trace_To: LinIf-CDD-5158(0) */
    else
#endif
    if(LinIf_u8LinTpState != LinIf_u8STATE_INIT)
    {
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_TRANSMIT_ID,
            LINIF_E_UNINIT);
#endif
        udtRet = E_NOT_OK;

    }

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!Else If the pkstrLinTpTxInfoPtr is NULL_PTR report to 
        DET LINIF_E_PARAMETER_POINTER */
    /*\Trace_To: LinIf-CDD-0250(0) */
    else if((P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_DATA))NULL_PTR
            ==
            pkstrLinTpTxInfoPtr)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_TRANSMIT_ID,
            LINIF_E_PARAMETER_POINTER);
        udtRet = E_NOT_OK;
    }
    /*!Else If the udtLinTpTxSduId is invalid report to 
        DET LINIF_E_PARAMETER */
    /*\Trace_To: LinIf-CDD-0251(0) */
    else if(udtLinTpTxSduId >= pkstrGlobalTPConfigPtr->u16NumberOfTxNsdus)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_TRANSMIT_ID,
            LINIF_E_PARAMETER);
        udtRet = E_NOT_OK;
    }
#endif
    /*!Else */
    else
    {

        VAR(uint8, AUTOMATIC)                               u8ChannelIndex;
		VAR(uint8, AUTOMATIC)                               u8ChnlId;
        P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;
        u8ChnlId = pkstrGlobalTPConfigPtr->
            pkstrTxNsdus[udtLinTpTxSduId].u8ChannelId;
		
		(void)LinIf_udtGetChannelIndexById(u8ChnlId,&u8ChannelIndex);
        pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
        

        /*!If the input data length is 0 reject the message by returning 
            E_NOT_OK */
        if( (0 == pkstrLinTpTxInfoPtr->SduLength)
            ||
            (pkstrLinTpTxInfoPtr->SduLength > u16MAX_MSG_LEN))
        {
            udtRet = E_NOT_OK;
        }
        
        /*!else If the channel u8TPChannelState is u8TP_CHANNEL_IDLE or the Nad
            of the requested Message is the Functional NAD */
        /*\Trace_To: LinIf-CDD-0113(0) */
        /*\Trace_To: LinIf-CDD-0245(0) */
        /*\Trace_To: LinIf-CDD-0246(0) */
        /*\Trace_To: LinIf-CDD-0247(0) */
        else if((u8TP_CHANNEL_IDLE == pstrCurrChannelVars->u8TPChannelState)
                ||
                /*\Trace_To: LinIf-CDD-0248(0) */
                (u8FUNCTIONAL_NAD
                == 
                pkstrGlobalTPConfigPtr->pkstrTxNsdus[udtLinTpTxSduId].u8NAD)
            )
        {
            /*! Stop any current Transmission or reception (this happens only 
                if the request is a functional request (NAD = 0x7E)) and reset
                timeout timer by calling vidStopCurrTransMsg and 
                vidStopCurrRxMsg with result = NOT_OK   */
            vidStopCurrTransMsg(u8ChannelIndex, NTFRSLT_E_NOT_OK, TRUE);

            vidStopCurrRxMsg(u8ChannelIndex, NTFRSLT_E_NOT_OK, TRUE);

            /*!Accept the request by setting pkstrCurrTPTxNsdu to the Nsdu
                whose Id is the input*/
            /*\Trace_To: LinIf-CDD-0104(0) */
            /*\Trace_To: LinIf-CDD-0244(0) */
            pstrCurrChannelVars->pkstrCurrTPTxNsdu = 
                &(pkstrGlobalTPConfigPtr->pkstrTxNsdus[udtLinTpTxSduId]);

            /*!Set u8TPChannelState to u8TP_CHANNEL_BUSY */
            /*\Trace_To: LinIf-CDD-0243(0) */
            pstrCurrChannelVars->u8TPChannelState = u8TP_CHANNEL_BUSY;
            /*!Set u8TPCommState to u8TP_STATE_TRANS */
            pstrCurrChannelVars->u8TPCommState = u8TP_STATE_TRANS;
            /*!Set udtTPRemData to pkstrLinTpTxInfoPtr->SduLength */
            pstrCurrChannelVars->udtTPRemData = pkstrLinTpTxInfoPtr->SduLength;

            
            /*!Start the N_Cs timeout by setting u16TPTimoutTimer to 
                pkstrGlobalTPConfigPtr->u16LinTpNCs */
            /*\Trace_To: LinIf-CDD-0105(0) */
            pstrCurrChannelVars->u16TPTimoutTimer = 
                pkstrGlobalTPConfigPtr->u16LinTpNCs + 1;

            /*! Set u8CurrentTxTimeout to u8TIMEOUT_CS */
            pstrCurrChannelVars->u8CurrentTxTimeout = u8TIMEOUT_CS; 

            /*!Call CopyTxData with the appropriate length: */
            /*!If the SduLength does not fit in a SF */ 
            /*\Trace_To: LinIf-CDD-0429(0) */
            /*\Trace_To: LinIf-CDD-0241(0) */
            /*\Trace_To: LinIf-CDD-0249(0) */
            if(pkstrLinTpTxInfoPtr->SduLength > u8MAX_SIN_F_DATA_LEN)
            {
                /*!If the NAD of the frame is a functional NAD then reject the
                    frame by setting the return value to E_NOT_OK because 
                    functional requests are always SF */
                /*\Trace_To: LinIf-CDD-0429(0) */
                if( u8FUNCTIONAL_NAD 
                    ==
                    pstrCurrChannelVars->pkstrCurrTPTxNsdu->u8NAD)
                {
                    udtRet = E_NOT_OK;
                }
                /*!Else */
                /*\Trace_To: LinIf-CDD-0430(0) */
                else
                {
                    /*!the requested length > SF length then request data for a
                        FF by calling udtPrepareTpTxFrame with the following 
                        parameters u8ChannelIndex, u8FF_DATA_LENGTH, 
                        pkstrLinTpTxInfoPtr->SduLength, u8FIRST_FRAME_TYPE*/
                    /*\Trace_To: LinIf-CDD-5164(0) */
                    udtRet = 
                        udtPrepareTpTxFrame(
                            u8ChannelIndex,
                            u8FF_DATA_LENGTH,
                            pkstrLinTpTxInfoPtr->SduLength,
                            u8FIRST_FRAME_TYPE);
                }
                /*!EndIf */
            }
            /*!Else (a SF) */
            else /* a single frame */
            {
                /*!request data for a SF by calling udtPrepareTpTxFrame with
                    the following parameters u8ChannelIndex, 
                    pkstrLinTpTxInfoPtr->SduLength, 0, u8SINGLE_FRAME_TYPE */
                /*\Trace_To: LinIf-CDD-5164(0) */
                udtRet = 
                    udtPrepareTpTxFrame(
                        u8ChannelIndex,
                        (uint8)pkstrLinTpTxInfoPtr->SduLength,
                        0, 
                        u8SINGLE_FRAME_TYPE);               
            }

            /*!If The return of udtPrepareTpTxFrame is E_NOT_OK */
            /*!clean the channel stuff: */
            if(E_OK != udtRet)
            {
                /*!Set pkstrCurrTPTxNsdu to NULL_PTR */
                pstrCurrChannelVars->pkstrCurrTPTxNsdu = NULL_PTR;
                /*!Set u8TPChannelState to u8TP_CHANNEL_IDLE */
                pstrCurrChannelVars->u8TPChannelState = u8TP_CHANNEL_IDLE;
                /*!Set u8TPCommState to u8TP_STATE_IDLE */
                pstrCurrChannelVars->u8TPCommState = u8TP_STATE_IDLE;
                /*!Set udtTPRemData to 0 */
                pstrCurrChannelVars->udtTPRemData = 0;
                /*!Set bTPStartNewFrame to FALSE */
                pstrCurrChannelVars->bTPStartNewFrame = FALSE;
                
                pstrCurrChannelVars->u16TPTimoutTimer = 0;

                pstrCurrChannelVars->u8CurrentTxTimeout = u8TIMEOUT_NONE;
            }
            /*! Else */
            else
            {
                /*! If bTPDataAvailable = false (no data provided from the UL)*/
                if(FALSE == pstrCurrChannelVars->bTPDataAvailable)
                {
                    /*!Set bTPStartNewFrame to TRUE */
                    pstrCurrChannelVars->bTPStartNewFrame = TRUE;
                }
            }
            /*!EndIf */
        }
        /*!Else (the channel is not Idle and the request is not a functional
            request */
        /*\Trace_To: LinIf-CDD-0245(0) */
        else /* else reject the request */
        {
            /*!Reject the request by returning E_NOT_OK */
            udtRet = E_NOT_OK;
        }
    }

    return udtRet;
/*!Deviation : Inhibit MISRA rule [4700]: No further simplification is        */
/*              possible                                                      */
/* PRQA S 4700 ++                                                             */
}
/* PRQA S 4700 --                                                             */



/******************************************************************************/
/*!Function    : LinTp_Shutdown                                              */
/*!\Description    Shutdowns the LIN TP. \n                                  */
/*\Trace_To    : LinIf-CDD-0256(0)                                           */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinTp_Shutdown(void)
{
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is not LinIf_u8STATE_INIT report to 
        DET LINIF_E_UNINIT*/
    /*\Trace_To: LinIf-CDD-5038(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_SHUTDOWN_ID,
            LINIF_E_UNINIT);
    }
    /*!Else If the LinIf_u8LinTpState is not LinIf_u8STATE_INIT report to 
        DET LINIF_E_UNINIT*/
    /*\Trace_To: LinIf-CDD-5159(0) */
    else if(LinIf_u8LinTpState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_SHUTDOWN_ID,
            LINIF_E_UNINIT);
    }
    /*!Else */
    else
    {
#endif
        VAR(uint8_least, AUTOMATIC) u8LoopIndex;

        /*!Loop on all channels and call vidResetChannelVars */
        /*\Trace_To: LinIf-CDD-0258(0) */
        for(u8LoopIndex = 0;
            u8LoopIndex < LinIf_ku8eNumberOfChannels; 
            u8LoopIndex++)
        {
            /*\Trace_To: LinIf-CDD-0257(0) */
            /*\Trace_To: LinIf-CDD-0259(0) */
            /*\Trace_To: LinIf-CDD-0260(0) */
            /*\Trace_To: LinIf-CDD-0261(0) */
            vidResetChannelVars(u8LoopIndex);
            /*!Set u8TPChannelState to u8TP_CHANNEL_UNINIT */
            /*\Trace_To: LinIf-CDD-0237(0) */
            /*\Trace_To: LinIf-CDD-0261(0) */
            LinIf_astreChannelsVars[u8LoopIndex].u8TPChannelState = 
                                                            u8TP_CHANNEL_UNINIT;
        }
        /*!Set LinIf_u8LinTpState to LinIf_u8STATE_UNINIT */
        /*\Trace_To: LinIf-CDD-0257(0) */
        LinIf_u8LinTpState = LinIf_u8STATE_UNINIT;
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    }
#endif
}


/******************************************************************************/
/*!Function    : LinTp_CancelTransmit                                 */
/*!\Description    Cancels the request to transmit a LIN frame. \n
    \param[in]      Nsdu Id of the requested Message \n
        \Range          0..pkstrGlobalTPConfigPtr->u16NumberOfTxNsdus - 1 \n
    \return         E_NOT_OK: Cancellation request of the transfer of the 
                    specified Lin N-SDU is rejected  \n                       */
/*\Trace_To    : LinIf-CDD-0262(0)                                           */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinTp_CancelTransmit(
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when DevErroDetect is ON                                       */
/* PRQA S 3206 ++                                                             */
    VAR(PduIdType, AUTOMATIC) udtLinTpTxSduId)
/* PRQA S 3206 --                                                             */
{
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is not LinIf_u8STATE_INIT report to 
    DET LINIF_E_UNINIT*/
    /*\Trace_To: LinIf-CDD-5040(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_CANCEL_TX_ID,
            LINIF_E_UNINIT);

    }
    /*!Else If the LinIf_u8LinTpState is not LinIf_u8STATE_INIT report to 
        DET LINIF_E_UNINIT*/
    /*\Trace_To: LinIf-CDD-5160(0) */
    else if(LinIf_u8LinTpState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_CANCEL_TX_ID,
            LINIF_E_UNINIT);
    }
    /*!Else If the udtLinTpTxSduId is not valid report to 
        DET LINIF_E_PARAMETER*/
    /*\Trace_To: LinIf-CDD-0264(0) */
    else if(udtLinTpTxSduId >= pkstrGlobalTPConfigPtr->u16NumberOfTxNsdus)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_CANCEL_TX_ID,
            LINIF_E_PARAMETER);
    }
    else
    {
        /*!Else do nothing, jsut for MISRA */
    }
#endif
    /*!Return E_NOT_OK */
    /*\Trace_To: LinIf-CDD-0263(0),LinIf-CDD-0494(0) */
    return E_NOT_OK;
}


/******************************************************************************/
/*!Function    : LinTp_ChangeParameter                                */
/*!\Description    Cancels the request to transmit a LIN frame. \n
    \param[in]      Identification of the I-PDU to which the parameter the 
                    request shall affect.  \n
        \Range          0..pkstrGlobalTPConfigPtr->u16NumberOfRxNsdus - 1 \n
    \param[in]      The selected parameter that the request shall changed.\n
        \Range          STMIN, BS \n
    \param[in]      The value that the request shall change to.  \n
    \return         E_OK    : request is accepted (no errors in inputs).  \n
                    E_NOT_OK: request is not accepted. (errors in inputs).\n  */
/*\Trace_To    : LinIf-CDD-0265(0)                                           */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinTp_ChangeParameter(
    VAR(PduIdType, AUTOMATIC) udtPduId,
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when DevErroDetect is ON                                       */
/* PRQA S 3206 ++                                                             */
    VAR(TPParameterType, AUTOMATIC) enuParameter, 
/* PRQA S 3206 --                                                             */
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when DevErroDetect is ON                                       */
/* PRQA S 3206 ++                                                             */
    VAR(uint16, AUTOMATIC) u16Value)
/* PRQA S 3206 --                                                             */
{
    VAR(Std_ReturnType, AUTOMATIC) udtRet;

    udtRet = E_NOT_OK;

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is not LinIf_u8STATE_INIT report to 
        DET LINIF_E_UNINIT and return E_NOT_OK*/
    /*\Trace_To: LinIf-CDD-5042(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_CHG_PARAM_ID,
            LINIF_E_UNINIT);
    }
    /*!Else If the LinIf_u8LinTpState is not LinIf_u8STATE_INIT report to 
        DET LINIF_E_UNINIT and return E_NOT_OK*/
    /*\Trace_To: LinIf-CDD-5161(0) */
    else
#endif
    if(LinIf_u8LinTpState != LinIf_u8STATE_INIT)
    {
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_CHG_PARAM_ID,
            LINIF_E_UNINIT);
#endif
    }
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!Else If the udtPduId is invalid report to DET LINIF_E_PARAMETER and
        return E_NOT_OK */ 
    /*\Trace_To: LinIf-CDD-0267(0) */
    else if(udtPduId >= pkstrGlobalTPConfigPtr->u16NumberOfRxNsdus)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_CHG_PARAM_ID,
            LINIF_E_PARAMETER);
    }
    /*!Else If the enuParameter is invalid report to DET LINIF_E_PARAMETER 
        and return E_NOT_OK*/ 
    /*\Trace_To: LinIf-CDD-0267(0) */
    /*\Trace_To: LinIf-CDD-0267(0) */
    /*!Deviation : Inhibit MISRA rules 3356, 3359, 3201: This check is for 
                    checking of invalid value for the input parameter  */
    /* PRQA S 3356, 3359, 3201 L2                                             */
    else if((enuParameter != STMIN)
            &&
            (enuParameter != BS))
    {
    /* PRQA L:L2                                                              */
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINTP_CHG_PARAM_ID,
                LINIF_E_PARAMETER);
    }
    /*!Else If the enuParameter is STMIN and the value is not in the range 
        (0..0x7F and 0xF1..0xF9) report to DET LINIF_E_PARAMETER and return 
        E_NOT_OK*/
    /*\Trace_To: LinIf-CDD-0267(0) */
    else if((enuParameter == STMIN)
            &&
            (u16Value > 0xF9))
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_CHG_PARAM_ID,
            LINIF_E_PARAMETER);
    }
    else if((enuParameter == STMIN)
            &&
            (u16Value > 0x7F)
            && 
            (u16Value < 0xF1))
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_CHG_PARAM_ID,
            LINIF_E_PARAMETER);
    }
            
#endif
    /*!Else */
    else
    {

        /*!Call ChangeParamConf with result = NTFRSLT_E_PARAMETER_NOT_OK */
        /*\Trace_To: LinIf-CDD-0266(0) */
        /*\Trace_To: LinIf-CDD-0286(0) */
        /*!Return E_OK */
        udtRet = E_OK;
    }
    return udtRet;
}



/******************************************************************************/
/*!Function    : LinTp_CancelReceieve                                 */
/*!\Description    Cancels the request to receive a LIN frame. \n
    \param[in]      This parameter contains the Lin TP instance unique 
                    identifier of the Lin N-SDU which transfer has to be 
                    cancelled.  \n
        \Range          0..pkstrGlobalTPConfigPtr->u16NumberOfTRxNsdus - 1 \n
    \return          E_NOT_OK: Cancellation request of the transfer of the 
                               specified Lin N-SDU is rejected   \n           */
/*\Trace_To    : LinIf-CDD-0270(0)                                           */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinTp_CancelReceive(
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when DevErroDetect is ON                                       */
/* PRQA S 3206 ++                                                             */
    VAR(PduIdType, AUTOMATIC) udtLinTpRxSduId)
/* PRQA S 3206 --                                                             */
{
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is not LinIf_u8STATE_INIT report to 
        DET LINIF_E_UNINIT*/
    /*\Trace_To: LinIf-CDD-5046(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_CANCEL_REC_ID,
            LINIF_E_UNINIT);

    }
    /*!Else If the LinIf_u8LinTpState is not LinIf_u8STATE_INIT report to 
        DET LINIF_E_UNINIT*/
    /*\Trace_To: LinIf-CDD-5162(0) */
    else if(LinIf_u8LinTpState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_CANCEL_REC_ID,
            LINIF_E_UNINIT);
    }
    /*!Else If the udtLinTpRxSduId is not valie report to 
        DET LINIF_E_UNINIT*/
    /*\Trace_To: LinIf-CDD-0272(0) */
    else if(udtLinTpRxSduId >= pkstrGlobalTPConfigPtr->u16NumberOfRxNsdus)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_CANCEL_REC_ID,
            LINIF_E_PARAMETER);
    }
    else
    {
        /*!Else do nothing, jsut for MISRA */
    }
#endif
    /*\Trace_To: LinIf-CDD-0271(0) */
    /*!Return E_NOT_OK */
    return E_NOT_OK;
}


#if (LinIf_bTP_VERSION_INFO_API == STD_ON)
/******************************************************************************/
/*!Function    : LinTp_GetVersionInfo                                        */
/*!\Description    Returns the version information of this module.       \n
    \param[out]   Pointer to where to store the version information of this
                  module. \n
            \Range   NOT NULL  \n                                             */
/*\Trace_To    : LinIf-CDD-0252(0)                                           */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinTp_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, LINIF_APPL_DATA) pudtVersionInfo)
{
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true,
        report to Det LINIF_E_UNINIT */
    /*\Trace_To: LinIf-CDD-0254(0) */
    if(NULL_PTR == pudtVersionInfo)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINTP_GET_VERSION_ID,
            LINIF_E_PARAMETER_POINTER);
    }
    /*!Else */
    else
    {
#endif
        /*!
        Set moduleID         = LINIF_MODULE_ID
        Set vendorID         = LINIF_VENDOR_ID
        Set sw_major_version = LINIF_SW_MAJOR_VERSION
        Set sw_minor_version = LINIF_SW_MINOR_VERSION
        Set sw_patch_version = LINIF_SW_PATCH_VERSION */
        /*\Trace_To: LinIf-CDD-0253(0) */
        pudtVersionInfo->moduleID         = LINIF_MODULE_ID;
        pudtVersionInfo->vendorID         = LINIF_VENDOR_ID;
        pudtVersionInfo->sw_major_version = LINIF_SW_MAJOR_VERSION;
        pudtVersionInfo->sw_minor_version = LINIF_SW_MINOR_VERSION;
        pudtVersionInfo->sw_patch_version = LINIF_SW_PATCH_VERSION;

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif /* LinIf_bTP_VERSION_INFO_API == STD_ON */

#endif /* LinIf_u8TP_SUPPORTED == STD_ON */


#define LINIF_STOP_SEC_CODE
#include "Memmap.h"

/*-------------------------------- end of file -------------------------------*/
/* PRQA L:L1                                                                  */
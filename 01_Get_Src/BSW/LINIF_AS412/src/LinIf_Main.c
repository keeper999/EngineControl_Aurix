/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The AutoSAR Lin Interface R4.0                          */
/*                                                                            */
/*!Module          : Main                                                    */
/*!Description     : The module resposible for interaction with the LinDrv in*/
/*                    sending/receiving frames and handling network management*/
/*                                                                            */
/*!\File            : LinIf_Main.c                                            */
/* \par              The module resposible for interaction with the LinDrv in*/
/*                    sending/receiving frames and handling network management*/
/*!Scope           : Public                                                  */
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
/* $Revision::   1.32     $$Author::   AELSOHBY       $$Date::   Mar 30 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0838]: Multiple Inclusion prevention      */
/*              macros solve this issue                                       */
/* PRQA S 0838 L1                                                             */
/*!Deviation : Inhibit MISRA rule [2215]: Indentation problem is caused by   */
/*              Compiler abstraction macros                                   */
/* PRQA S 2215 L1                                                             */
/*!Deviation : Inhibit MISRA rule [0862]: The MemMap.h is used to assign     */
/*              memory segments                                               */
/* PRQA S 0862 L1                                                             */
/*!Deviation : Inhibit MISRA rule [0850]: The value for the macros are       */
/*              redefined in the QAC for comptability with ANSI C             */
/* PRQA S 0850 L1                                                             */
/*!Deviation : Inhibit MISRA rule [5087]: The value for the macros are        */
/*              non preprocessor directives  					   		      */
/* PRQA S 5087 L1                                                             */

#include "LinIf.h"
#include "LinIf_Cfg.h"
#include "LinIf_Lcfg.h"
#include "LinIf_Types.h"
#include "LinIf_Types_Internal.h"
#include "LinIf_Main.h"
#include "LinIf_ScheduleTableManager.h"
#include "LinIf_LinTransportProtocol.h"

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
#include "LinIf_DetErrors.h"

#endif
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/*!\Description : The PID of and MRF or Node configuration frame\n           */
#define u8MRF_ID                0x3CU   /* IDs 60 uses classic checksum */
#define u8SRF_ID                0x3DU   /* IDs 61 uses classic checksum */

/*!\Description : the maximum size of a Lin Frame \n                         */
#define u8FRAME_DATA_SIZE       0x08

/*!\Description : the  size of a the BitMasks array   \n                     */
#define u8BIT_MASKS_SIZE        8


/*!\Description : Symbol to indicate that a wakeup is done due to a request 
                    from upper layer    \n                                    */
#define u8UPPERLAYER_WAKEUP     0

/*!\Description : Symbol to indicate that a wakeup is done due to a wakeup 
                    from the bus     \n                                       */
#define u8BUS_WAKEUP            1


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define LINIF_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"
/*!\Description : The pointer to the post build configuration passed to the
                   LinIf \n*/
P2CONST(LinIf_ConfigType, LINIF_VAR, LINIF_APPL_CONST)
                                                       LinIf_pkstreGlobalConfig;

#define LINIF_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"



#define LINIF_START_SEC_VAR_8
#include "Memmap.h"

/*!\Description : The state variable of the LinIf that indicate whether it is 
              initialized or not    \n                                        */
/* \Range   : LinIf_u8STATE_UNINIT, LinIf_u8STATE_INIT      \n                */
VAR(uint8, LINIF_VAR) LinIf_u8eLinIfState = LinIf_u8STATE_UNINIT;

#define LINIF_STOP_SEC_VAR_8
#include "Memmap.h"

#define LINIF_START_SEC_CONST_8
#include "Memmap.h"
/*!Deviation : Inhibit MISRA rule [3218]: The array is global to reduce stack*/
/*              as its size is large                                          */
/* PRQA S 3218 ++                                                             */

/*!\Description Array of masks for 8 bit integerts, it is used for getting the 
              value of the response error bit in a response error frame       */
static CONST(uint8, LINIF_CONST) aku8BitMasks[u8BIT_MASKS_SIZE] = 
{
    0x01,   /* 0000 0001 */
    0x02,   /* 0000 0010 */
    0x04,   /* 0000 0100 */
    0x08,   /* 0000 1000 */
    0x10,   /* 0001 0000 */
    0x20,   /* 0010 0000 */
    0x40,   /* 0100 0000 */
    0x80    /* 1000 0000 */
};

#define LINIF_STOP_SEC_CONST_8
#include "Memmap.h"
/* PRQA S 3218 --                                                             */

#define LINIF_START_SEC_CODE
#include "Memmap.h"
/******************************************************************************/
/* Description : The function handles the response error bit in a response    */
/*                error frame                                                 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleRespErrBit(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrameRec);

/******************************************************************************/
/* Description : The function resposible for handling Network management      */
/*                (sleep frame handling and wakeup frames handling)           */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleNM(
   P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_CALIB_CONST) pkstrChannel);

/******************************************************************************/
/* Description : Function that is resposible for handling wakeup requests     */
/*                (wakeup requests in sleep and wakeup modes)                 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleWakeupRequest(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   VAR(uint8, AUTOMATIC) u8RequestingLayer);

/******************************************************************************/
/* Description :  Calls Lin_GetStatus and perform actions based on the current*/
/*                status, also returns the status because the caller may need */
/*                to do extra processing                                      */
/******************************************************************************/
static FUNC(Lin_StatusType, LINIF_CODE) enuCheckStatus(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    VAR(boolean, AUTOMATIC) bTolerateBusy);


/******************************************************************************/
/* Description : The function handling the Main Sub-Component normal          */
/*               communication State machine                                  */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidIFMain(
   P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_CALIB_CONST) pkstrChannel);

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
/******************************************************************************/
/*!Function    : vidHandleRespErrBit                                         */
/*!\Description The function handles the response error bit in a response   */
/*                error frame   \n                                             
    \param[in] The index of the channel that the frame is received on\n
             \Range   0..LinIf_ku8NumberOfChannels - 1  \n                   
    \param[in] Pointer to the received frame structure \n
             \Range   NOT NULL  \n                   */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleRespErrBit(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrameRec)
{

    /*! If the rec. frame has a valid slave index (0..15)*/
    if(pkstrFrameRec->u8ErrorSlaveIndex != 0xFF)
    {
        /*! Calculate the slave index in the Slaves array by adding 
                     the slave index of the frame to the starting slave index 
                     in the channel  */
        VAR(uint8, AUTOMATIC) u8ErrorBitPos;
        VAR(uint8, AUTOMATIC) u8SlaveIndex;
        u8SlaveIndex = 
            LinIf_akstreChannelsLT[u8ChannelIndex].u8SlavesIndex
            + pkstrFrameRec->u8ErrorSlaveIndex;


        /*!If the error bit of the slave (specified by ErrorBitPos) 
                     is 1 report ResponseErrorDetected error to DEM  
                     (if it is configured ofcourse)*/
        
        u8ErrorBitPos = LinIf_akstreSlaves[u8SlaveIndex].u8ResponseErrorBitPos;
        /*\Trace_To: LinIf-CDD-0090(0) */
        if(
            (   
                (LinIf_astreChannelsVars[u8ChannelIndex].
                au8DataBuffer[((u8ErrorBitPos >> 0x03) & 0x07)])
                & 
                (aku8BitMasks[(u8ErrorBitPos & 0x07)])
            )
            != 0
          )
        {
            
            if( LinIf_akstreSlaves[u8SlaveIndex].pkudtEResponseErrDetected 
                != 
                (P2CONST(Dem_EventIdType, LINIF_CFG_CONST, LINIF_CFG_CONST))
                NULL_PTR)
            {
                Dem_ReportErrorStatus
                    (
                        *(LinIf_akstreSlaves[u8SlaveIndex].
                                pkudtEResponseErrDetected),
                        DEM_EVENT_STATUS_FAILED
                    );
            }
        }
    }
}
/******************************************************************************/
/*!Function    : enuCheckStatus                                              */
/*!\Description  Calls Lin_GetStatus and perform actions based on the current*/
/*                status, also returns the status because the caller may need */
/*                to do extra processing \n 
    \param[in] The index of the channel that the frame is received on\n
             \Range   0..LinIf_ku8NumberOfChannels - 1  \n                   
    \param[in] Boolean to indicate whether the BUSY return from 
                 Lin_GetStatus shall be treated as error or not \n
             \Range  FALSE, TRUE \n
             
             
    \return LIN_NOT_OK,
                    LIN_TX_OK,
                    LIN_TX_BUSY,
                    LIN_TX_HEADER_ERROR,
                    LIN_TX_ERROR,
                    LIN_RX_OK,
                    LIN_RX_BUSY,
                    LIN_RX_ERROR,
                    LIN_RX_NO_RESPONSE,
                    LIN_OPERATIONAL,
                    LIN_CH_SLEEP  \n                   */     
/******************************************************************************/
static FUNC(Lin_StatusType, LINIF_CODE) enuCheckStatus(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    VAR(boolean, AUTOMATIC) bTolerateBusy)
{
    VAR(Lin_StatusType, AUTOMATIC)                              enuRetStatus;
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA)                    pu8Data;
    P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST)      pkstrLocFrame;
	P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;
	P2CONST(LinIf_tstrChannelStaticConf, AUTOMATIC, LINIF_CALIB_CONST)
														pkstrCurrChannelLT;
														
	pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
	pkstrCurrChannelLT   = &(LinIf_akstreChannelsLT[u8ChannelIndex]);
    pkstrLocFrame = pstrCurrChannelVars->pkstrCurrentFrame;

    /*! Call Lin_GetStatus of the driver of the currect channel      */
	enuRetStatus = pkstrCurrChannelLT->pkstrDrvRef->pfenuGetStatus
        (pkstrCurrChannelLT->u8LinChannelId, &pu8Data);

    /*! If there is no communication on the channel return           */
    /*! else */

    if( LinIf_u8IF_STATE_IDLE 
        != 
        pstrCurrChannelVars->u8IFCommState)
    {

        /*! If the call was to check gotosleep or wakeup (bGotoSleepFlag or 
            bSendWakeup is true) set the returned from GetStatus to 
            CH_OPERATIONAL if it is not (CH_SLEEP or LIN_NOT_OK)*/
        if( (FALSE != pstrCurrChannelVars->bSendGotoSleep)
            ||
            (FALSE != pstrCurrChannelVars->bSendWakeup))
        {
            if( (enuRetStatus != LIN_CH_SLEEP)
                &&
                (enuRetStatus != LIN_NOT_OK))
            {
                enuRetStatus = LIN_OPERATIONAL;
            }
        }
        /*! According to the returned status (after modification if any): */
        switch(enuRetStatus)
        {
        /*! If the returned is LIN_TX_OK */
        case LIN_TX_OK:
            {
                /*! If the frame is a TP or NC frame send it to TP 
                             (call TP_TxConf) else send TxConfirmation 
                             Normally (Call STM_TxConf) */
                if(LinIf_INTERNAL_PDU == pkstrLocFrame->enuFrameDirection)
                {
                    LinIf_vidTPTxConf(u8ChannelIndex, TRUE);
                }
                else
                {
                    LinIf_vidSTMTxConf(u8ChannelIndex);
                }
            }
            break;
        
        /*! If the returned is LIN_TX_BUSY */
        case LIN_TX_BUSY:
            {
                /*! If bTolerateBusy = true 
                             (busy shall not be treated as error) do nothing.
                             else if the frame is a TP frame indicate and error
                             in the call of TP_TxConf,
                             else report E_RESPONSE to DEM and Set the channel 
                             state to Idle*/
                if(FALSE == bTolerateBusy)
                {
                    if(LinIf_INTERNAL_PDU == pkstrLocFrame->enuFrameDirection)
                    {
                        LinIf_vidTPTxConf(u8ChannelIndex, FALSE);
                    }
                    /*\Trace_To: LinIf-CDD-0046(0) */
                    else if(
                        pkstrLocFrame->pkudtLinIfEResponse 
                        != 
                        (P2CONST(Dem_EventIdType,
                                 LINIF_CALIB_CONST,
                                 LINIF_CALIB_CONST))NULL_PTR)
                    {
                        Dem_ReportErrorStatus(
                            *(pkstrLocFrame->pkudtLinIfEResponse)
                            , DEM_EVENT_STATUS_FAILED);
                    }
                    else
                    {
                        /* do nothing just for MISRA */
                    }
                    pstrCurrChannelVars->u8IFCommState =
                                         LinIf_u8IF_STATE_IDLE;
                }
            }
            break;
        /*! If the returned is LIN_TX_HEADER_ERROR */
        case LIN_TX_HEADER_ERROR:
            {
                /*\Trace_To: LinIf-CDD-0039(0) */
                /*! Do nothing header errors are not reported to the 
                         upper layers */
                /*! if the frame is a TP frame indicate an error
                             in the call of TP_TxConf  */             
                if(LinIf_INTERNAL_PDU == pkstrLocFrame->enuFrameDirection)
                {
                    LinIf_vidTPTxConf(u8ChannelIndex, FALSE);
                }
            }
            break;
        /*! If the returned is LIN_TX_ERROR */
        case LIN_TX_ERROR:
            {
                /*! Store that there is no communication on channel*/

                /*! if the frame is a TP frame indicate an error
                             in the call of TP_TxConf,
                             else report E_RESPONSE to DEM  */             
                if(LinIf_INTERNAL_PDU == pkstrLocFrame->enuFrameDirection)
                {
                    LinIf_vidTPTxConf(u8ChannelIndex, FALSE);
                }
                /*\Trace_To: LinIf-CDD-0045(0) */
                else if(
                    pkstrLocFrame->pkudtLinIfEResponse 
                    != 
                    (P2CONST(Dem_EventIdType,
                             LINIF_CALIB_CONST,
                             LINIF_CALIB_CONST))NULL_PTR)
                {
                    Dem_ReportErrorStatus(*(pkstrLocFrame->pkudtLinIfEResponse)
                        , DEM_EVENT_STATUS_FAILED);
                }
                else
                {
                    /* do nothing just for MISRA */
                }
            }
            break;
        /*! If the returned is LIN_RX_OK */
        case LIN_RX_OK:
            {
                /*! Copy the data from the input LinDrv buffer 
                             (the second input parameter to the function) */
                /* note that buffer copying here is done only to make the data
                   on the channel saved in only one place in transmission and 
                   reception */
                VAR(uint8_least, AUTOMATIC)               u8LoopIndex;
                P2VAR(uint8, AUTOMATIC, LINIF_VAR)  pu8DataInChannel; 
                    
                pu8DataInChannel = 
                    &(pstrCurrChannelVars->au8DataBuffer[0]);

                for(u8LoopIndex = 0;
                    u8LoopIndex < u8FRAME_DATA_SIZE;
                    u8LoopIndex++)
                {
                    pu8DataInChannel[u8LoopIndex] = pu8Data[u8LoopIndex];
                }
                
                /*! If the message is an RxPdu call STM_RxInd, 
                             Else if it is an LinIf_SRF call TP_RxInd */
                if(LinIf_RX_PDU == pkstrLocFrame->enuFrameDirection)
                {
                    LinIf_vidSTMRxInd(u8ChannelIndex);     
                }
                else if(LinIf_SRF == pkstrLocFrame->enuFrameType)
                {
                    LinIf_vidTPRxInd(u8ChannelIndex);
                }
                else
                {
                    /* do nothing just for MISRA */
                }

                /*! Call vidHandleRespErrBit to handle Response Error
                             Bit checking */
                vidHandleRespErrBit(u8ChannelIndex, pkstrLocFrame);
                /*! Store that there is no communication on channel*/

            }
            break;
        /*! If the returned is LIN_RX_BUSY */
        case LIN_RX_BUSY:
            {
                /*! If bTolerateBusy = true 
                             (busy shall not be treated as error) do nothing.
                             else if the frame is a Event triggered frame call
                             LinIf_vidSTMHandlEvtTrigErr to handle the 
                             collision. */
                /*! else report E_RESPONSE to DEM and store that there
                             is no communication on channel */
                /*! Note that if the frame is an LinIf_SRF do nothing and do
                             not call TP_RxInd */
                if(FALSE == bTolerateBusy)
                {
                    /*\Trace_To: LinIf-CDD-0041(0) */
                    if(LinIf_EVENT_TRIGGERED == pkstrLocFrame->enuFrameType)
                    {
                        LinIf_vidSTMHandlEvtTrigErr(u8ChannelIndex);
                    }
                    /*\Trace_To: LinIf-CDD-0038(0) */
                    else if(
                        pkstrLocFrame->pkudtLinIfEResponse 
                        != 
                        (P2CONST(Dem_EventIdType,
                                 LINIF_CALIB_CONST,
                                 LINIF_CALIB_CONST))NULL_PTR)
                    {
                        Dem_ReportErrorStatus(
                            *(pkstrLocFrame->pkudtLinIfEResponse)
                            , DEM_EVENT_STATUS_FAILED);
                    }
                    else
                    {
                        /* do nothing just for MISRA */
                    }
                    pstrCurrChannelVars->u8IFCommState = 
                                         LinIf_u8IF_STATE_IDLE;
                }
            }
            break;
        /*! If the returned is LIN_RX_ERROR */
        case LIN_RX_ERROR:
            {
                /*! if the frame is a Event triggered frame call
                             LinIf_vidSTMHandlEvtTrigErr to handle the 
                             collision. */
                /*! else if the frame is uncondition report E_RESPONSE to DEM
                    and store that there is no communication on channel */
                /*! Note that if the frame is an LinIf_SRF do nothing and do
                             not call TP_RxInd */
                /*\Trace_To: LinIf-CDD-0035(0) */
                if(pkstrLocFrame->enuFrameType == LinIf_EVENT_TRIGGERED)
                {
                    
                    /*\Trace_To: LinIf-CDD-0041(0) */
                    /*\Trace_To: LinIf-CDD-0020(0) */
                    LinIf_vidSTMHandlEvtTrigErr(u8ChannelIndex);
                    
                }
                /*\Trace_To: LinIf-CDD-0037(0) */
                else if(
                    (pkstrLocFrame->enuFrameType == LinIf_UNCONDITIONAL)
                    &&
                    (pkstrLocFrame->pkudtLinIfEResponse 
                    != 
                    (P2CONST(Dem_EventIdType,
                             LINIF_CALIB_CONST,
                             LINIF_CALIB_CONST))NULL_PTR))
                {
                    Dem_ReportErrorStatus(*(pkstrLocFrame->pkudtLinIfEResponse)
                        , DEM_EVENT_STATUS_FAILED);
                }
                else
                {
                    /* do nothing just for MISRA */
                }
            }
            break;
        /*! If the returned is LIN_RX_NO_RESPONSE */
        case LIN_RX_NO_RESPONSE:
            {
                /*! If the frame is LinIf_SRF call LinIf_vidTPSRFNoResp */
                /*! else report E_RESPONSE to DEM and store that there
                             is no communication on channel */
                /*\Trace_To: LinIf-CDD-0036(0) */

                if(LinIf_SRF == pkstrLocFrame->enuFrameType)
                {
                    LinIf_vidTPSRFNoResp(u8ChannelIndex);
                }
                /*\Trace_To: LinIf-CDD-0038(0) */
                else if(
                    (pkstrLocFrame->enuFrameType != LinIf_EVENT_TRIGGERED)
                    &&
                    (pkstrLocFrame->pkudtLinIfEResponse 
                    !=
                    (P2CONST(Dem_EventIdType,
                             LINIF_CALIB_CONST,
                             LINIF_CALIB_CONST))NULL_PTR))
                {
                    Dem_ReportErrorStatus(*(pkstrLocFrame->pkudtLinIfEResponse)
                        , DEM_EVENT_STATUS_FAILED);
                }
                else
                {
                    /* do nothing just for MISRA */
                }

                /*! Note that if there is no response in event 
                             triggered frame do nothing, no slave wanted to 
                             respond */
            }

            break;
        /*! If the returned is LIN_OPERATIONAL or LIN_CH_SLEEP */
        case LIN_OPERATIONAL:
        case LIN_CH_SLEEP:
            /*! do nothing the confirmation will be done in the 
                         NM State-machine (vidHandleNM function) */
        break;

        /*! If the returned is LIN_NOT_OK do nothing */
        case LIN_NOT_OK:
        default:
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
            
#endif
            break;
        }
    }
    /*! return the returned value for Lin_GetStatus */
    return enuRetStatus;
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [4700]: No further simplification is       */
/*              possible                                                      */
/* PRQA S 4700 ++                                                             */
}
/* PRQA S 4700 --                                                             */

/******************************************************************************/
/*!Function    : vidHandleNM                                                 */
/*!\Description The function resposible for handling Network management      */
/*                (sleep frame handling and wakeup frames handling) \n 
    \param[in] Pointer to the channel posb-build conf. structure\n
             \Range   NOT NULL  \n                    */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleNM(
   P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_CALIB_CONST) pkstrChannel)
{
    VAR(uint8, AUTOMATIC)                               u8ChannelIndex;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;
	P2CONST(LinIf_tstrChannelStaticConf, AUTOMATIC, LINIF_CALIB_CONST)
														pkstrCurrChannelLT;
    u8ChannelIndex = pkstrChannel->u8ChannelIndx;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
	pkstrCurrChannelLT   = &(LinIf_akstreChannelsLT[u8ChannelIndex]);



    /*! According to the communication state of the current channel */
    switch(pstrCurrChannelVars->u8IFCommState)
    {
        /*! If the state is Idle */
    case LinIf_u8IF_STATE_IDLE:
        {	
            VAR(Std_ReturnType, AUTOMATIC)  udtRet;
            /*! If there is a goto sleep request ready to be sent */
            if(FALSE != pstrCurrChannelVars->bSendGotoSleep)
            {
                /*\Trace_To: LinIf-CDD-0078(0) */
                /*\Trace_To: LinIf-CDD-0194(0) */
                /*! If the channel state is CHANNEL_OPERATIONAL send 
                             the gotosleep frame by calling Lin_GotoSleep of
                             the driver controlling the channel */
                /*! else If the channel state is CHANNEL_SLEEP do not 
                             send the gotosleep frame, but call 
                             Lin_GotoSleepInternal of the driver controlling 
                             the channel */
                if( LinIf_u8CHANNEL_OPERATIONAL 
                    == 
                    pstrCurrChannelVars->u8IFChannelState)
                {
					udtRet = pkstrCurrChannelLT->pkstrDrvRef->pfudtGotoSleep(
										pkstrCurrChannelLT->u8LinChannelId);
						
                }
                /*\Trace_To: LinIf-CDD-0079(0) */
                /*\Trace_To: LinIf-CDD-0197(0) */
                else /* LinIf_u8CHANNEL_SLEEP */
                {	
					udtRet = pkstrCurrChannelLT->pkstrDrvRef->
					pfudtGotoSleepInternal(pkstrCurrChannelLT->u8LinChannelId);
                }

                /*! If the return of the call is E_NOT_OK clear the 
                             bSendGotoSleep and bGotoSleepFlag flags and call
                             UL_GoToSleepConfirmation with result = False */
                if(udtRet != E_OK)
                {
                    pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_IDLE;
                    pstrCurrChannelVars->bSendGotoSleep = FALSE;
                    pstrCurrChannelVars->bGotoSleepFlag = FALSE;
                    /*\Trace_To: LinIf-CDD-0282(0) */
                    pkstrChannel->pfvidGotoSleepConfrm(
                        LinIf_udtGetChannelIdByIndex(u8ChannelIndex), FALSE);
                }
                /*! Else set the comm state to LinIf_u8IF_STATE_WAIT
                             and set the FrameTimeCounter to GotoSleepCmdTime+1
                             if GotoSleep frame is set, but if the call was to
                             GotoSleepInternal the set the timer to 1 so that
                             the status to be checked in the next MainFunction
                             call. */
                /*! The FrameTimeCounter is set to GotoSleepCmdTime + 1 not 
                    GotoSleepCmdTime only to leave tolerance for the sleep 
                    frame. */
                else
                {
                    pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_WAIT;
                    if( LinIf_u8CHANNEL_OPERATIONAL 
                        == 
                        pstrCurrChannelVars->u8IFChannelState)
                    {
                        pstrCurrChannelVars->u8FrameTimeCounter = 
                            LinIf_pkstreGlobalConfig->
                               pkstrChannels[u8ChannelIndex].u8GotoSleepCmdTime + 1;
                    }
                    else
                    {
                        pstrCurrChannelVars->u8FrameTimeCounter = 1;
                    }
                }
            }
            /*! If there is a wakeup request ready to be sent */
            /*\Trace_To: LinIf-CDD-0200(0) */
            else if(FALSE != pstrCurrChannelVars->bSendWakeup)
            {
                /*! Call Lin_Wakeup of the driver controlling the Lin
                             channel, and if the call returns E_OK set the state
                             to wait and set FrameTimeCounter to WakeupCmdTime*/
                /*! Else reset the bSendWakeup to false and call 
                             WakeupConf with status = false */
				udtRet = pkstrCurrChannelLT->pkstrDrvRef->pfudtWakeup(
                    pkstrCurrChannelLT->u8LinChannelId);
                if(udtRet != E_OK)
                {
                    pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_IDLE;
                    pstrCurrChannelVars->bSendWakeup = FALSE;
                    /*\Trace_To: LinIf-CDD-0284(0) */
                    pkstrChannel->pfvidWakeUpConfrm(
                        LinIf_udtGetChannelIdByIndex(u8ChannelIndex), FALSE);
                }
                else
                {
                    pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_WAIT;
                    pstrCurrChannelVars->u8FrameTimeCounter = 
                        LinIf_pkstreGlobalConfig->pkstrChannels[u8ChannelIndex].
                            u8WakeupCmdTime;
                }
            }
            else
            {
                /* do nothing, just for MISRA, and this part of code shall never
                   be reached. as the funtion is called only in the case of 
                   GotoSleep or Wakeup requests. */
            }
        }
        
        break;
    /*! If the comm state of the current channel is wait */
    case LinIf_u8IF_STATE_WAIT:
        {
            /*! Decrement the FrameTimeCounter by 1 if it reaches 0 
                         check the channel status by calling enuCheckStatus  */
            pstrCurrChannelVars->u8FrameTimeCounter--;
            if(pstrCurrChannelVars->u8FrameTimeCounter == 0)
            {
                VAR(Lin_StatusType, AUTOMATIC) enuRetStatus;

                pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_IDLE;
                /*\Trace_To: LinIf-CDD-0080(0) */
                enuRetStatus = enuCheckStatus(u8ChannelIndex, FALSE);
                /*! if there is a gotosleep frame sent reset the 
                     bSendGotoSleep and bGotoSleepFlag flags and 
                     check for the channel status if it is LIN_CH_SLEEP
                     set the channel state to LinIf_u8CHANNEL_SLEEP and
                     call GotoSleepConf. with sucess = true and call
                     LinIf_vidSTMSetNullSchedule to set the current 
                     channel schedule to NULL_SCHEDULE */
                /*! If the channel state is not LIN_CH_SLEEP maintain
                             the channel state to LinIf_u8CHANNEL_OPERATIONAL
                             and call GotoSleepConf. with sucess = false */
                if(FALSE != pstrCurrChannelVars->bSendGotoSleep)
                {
                    pstrCurrChannelVars->bSendGotoSleep = FALSE;
                    pstrCurrChannelVars->bGotoSleepFlag = FALSE;
                    /*\Trace_To: LinIf-CDD-0080(0) */
                    if(LIN_CH_SLEEP == enuRetStatus)
                    {
                        /*\Trace_To: LinIf-CDD-0084(0) */
                        LinIf_vidSTMSetNullSchedule(u8ChannelIndex);

                        pstrCurrChannelVars->u8IFChannelState = 
                            LinIf_u8CHANNEL_SLEEP;
                        /*\Trace_To: LinIf-CDD-0082(0) */
                        /*\Trace_To: LinIf-CDD-0282(0) */
                        pkstrChannel->pfvidGotoSleepConfrm(
                            LinIf_udtGetChannelIdByIndex(u8ChannelIndex), TRUE);
                    }
                    /*\Trace_To: LinIf-CDD-0081(0) */
                    else
                    {
                        pstrCurrChannelVars->u8IFChannelState = 
                            LinIf_u8CHANNEL_OPERATIONAL;
                        /*\Trace_To: LinIf-CDD-0083(0) */
                        /*\Trace_To: LinIf-CDD-0282(0) */
                        pkstrChannel->pfvidGotoSleepConfrm(
                            LinIf_udtGetChannelIdByIndex(u8ChannelIndex),FALSE);
                    }
                }
                /*! if there is a wakeup frame sent reset the 
                             bSendWakeup flag and check for the channel status
                             if it is not LIN_CH_SLEEP and also not LIN_NOT_OK
                             set channel state to LinIf_u8CHANNEL_OPERATIONAL 
                             and call WakeupConf. with sucess = true */
                /*! Else maintain the channel state to 
                             LinIf_u8CHANNEL_SLEEP and call WakeupConf. with 
                             sucess = false */
                else if(FALSE != pstrCurrChannelVars->bSendWakeup)
                {
                    pstrCurrChannelVars->bSendWakeup = FALSE;
                    /*\Trace_To: LinIf-CDD-0085(0) */
                    if( (LIN_CH_SLEEP != enuRetStatus)
                        && 
                        (LIN_NOT_OK != enuRetStatus))
                    {
                        /*\Trace_To: LinIf-CDD-0076(0) */
                        pstrCurrChannelVars->u8IFChannelState = 
                            LinIf_u8CHANNEL_OPERATIONAL;
                        /*\Trace_To: LinIf-CDD-0284(0) */
                        pkstrChannel->pfvidWakeUpConfrm(
                            LinIf_udtGetChannelIdByIndex(u8ChannelIndex), TRUE);
                    }
                    else
                    {
                        pstrCurrChannelVars->u8IFChannelState = 
                            LinIf_u8CHANNEL_SLEEP;
                        /*\Trace_To: LinIf-CDD-0284(0) */
                        pkstrChannel->pfvidWakeUpConfrm(
                            LinIf_udtGetChannelIdByIndex(u8ChannelIndex),FALSE);
                    }   
                }
                else
                {
                    /* do nothing, just for MISRA, and this part of code shall 
                    never be reached. as the funtion is called only in the case
                    of GotoSleep or Wakeup requests. */
                }
            }
        }
        break;
    default:
        /*! if the current state of the channel is any thing but 
                     Idle and wait set the state to LinIf_u8IF_STATE_IDLE */
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
        /* TODO: Handle Error */
#endif
        pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_IDLE;
        break;
    }

/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [4700]: No further simplification is       */
/*              possible                                                      */
/* PRQA S 4700 ++                                                             */
}
/* PRQA S 4700 --                                                             */


/******************************************************************************/
/*!Function    : vidIFMain                                                   */
/*! \Description The function handling the Main Sub-Component normal         
                  communication State machine                               
     \param[in] Pointer to a channel PB conf stucture
             \Range   NOT NULL  \n                                            */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidIFMain(
   P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_CALIB_CONST) pkstrChannel)
{
    VAR(uint8, AUTOMATIC)                                   u8ChannelIndex;
    P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST)  pkstrCurrFrame;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)      pstrCurrChannelVars;
    VAR(Lin_StatusType, AUTOMATIC)                          enuRetStatus;

    u8ChannelIndex = pkstrChannel->u8ChannelIndx;
    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    
    pkstrCurrFrame = pstrCurrChannelVars->pkstrCurrentFrame;
    
    switch(pstrCurrChannelVars->u8IFCommState)
    {
        /*! If the current state of the channel is IDLE : */
    case LinIf_u8IF_STATE_IDLE:
        /*! do nothing */
        break;
        /*! Else If is send frame : */
    case LinIf_u8IF_STATE_SEND_FRAME:
        /*!The frame already sent, wait for the next cycle to check for the 
            MaxFrameTime */
        /*  !If the current frame is a slave to slave pdu then do not check for 
            status and return to idle*/ 
        /*\Trace_To: LinIf-CDD-0050(0) */
        if(LinIf_SLAVE_TO_SLAVE_PDU == pkstrCurrFrame->enuFrameDirection)
        {
            pstrCurrChannelVars->u8IFCommState = 
                                                LinIf_u8IF_STATE_IDLE;

        }
        else
        {
            /*!Else the frame already sent, wait for the next cycle to check 
                for the MaxFrameTime by setting the channel state to WAIT and
                the FrameTimeCounter to Frame's MaxTime*/
            pstrCurrChannelVars->u8IFCommState = 
                                                LinIf_u8IF_STATE_WAIT;

            pstrCurrChannelVars->u8FrameTimeCounter = 
                                                pkstrCurrFrame->u8MaxFrameTime;
        }
            /*! End if */
        break;
        /*! Else if the state is WAIT */
    case LinIf_u8IF_STATE_WAIT:
        {
            /*! Decrement the FrameTimeCounter */
            pstrCurrChannelVars->u8FrameTimeCounter--;
            /*! If the FrameTimeCounter reaches 0 */
            if(pstrCurrChannelVars->u8FrameTimeCounter == 0)
            {
                /*!Call enuCheckStatus passing to it the current channel index
                    and indicating that a busy return shall be tolerated. */
                enuRetStatus = enuCheckStatus(u8ChannelIndex, TRUE);

                /*!if a busy return  (TX_BUSY or RX_BUSY) set the state to 
                    CHK_BUSY */
                if( (LIN_TX_BUSY == enuRetStatus)
                    ||
                    (LIN_RX_BUSY == enuRetStatus))
                {
                    pstrCurrChannelVars->u8IFCommState = 
                        LinIf_u8IF_STATE_CHK_BUSY;
                }
                /*! Else the frame processing is done return to IDLE */
                else
                {
                    pstrCurrChannelVars->u8IFCommState = 
                        LinIf_u8IF_STATE_IDLE;
                }
                /*! Endif */
            }
            /*! Endif */
        }
        break;
        /*! Else if the state is CHK_BUSY */
    case LinIf_u8IF_STATE_CHK_BUSY:
        {            
            /*!Call enuCheckStatus passing to it the current channel index 
                and indicating that a busy return shall be tolerated. */
            enuRetStatus = enuCheckStatus(u8ChannelIndex, TRUE);
            /*!if a busy return  (TX_BUSY or RX_BUSY) remain in the state 
                CHK_BUSY */
            if( (LIN_TX_BUSY == enuRetStatus)
                ||
                (LIN_RX_BUSY == enuRetStatus))
            {
                pstrCurrChannelVars->u8IFCommState = 
                    LinIf_u8IF_STATE_CHK_BUSY;
            }
            /*! Else the frame processing is done return to IDLE */
            else
            {
                pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_IDLE;
            }
            /*! Endif */
        }
        /*! Endif */
        /*! In the case the state is invalid set the state to IDLE */
        break;
    default:
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
        /* TODO: Handle Error */
#endif
        pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_IDLE;
        break;
    }
}





/******************************************************************************/
/*!Function    : vidHandleWakeupRequest                                      */
/*!\Description The function that handles a wakeup request, either from bus or
                 from upper layer to determine if we shall send a wakeup signal
                 or not and also do actions if there is on going sleep 
                 request \n                               
    \param[in] The index of the current channel is the channels array
            \Range   0..LinIf_ku8eNumberOfChannels  \n
    \param[in] Integer to indicate the requesting layer
            \Range u8UPPERLAYER_WAKEUP, u8BUS_WAKEUP \n                       */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleWakeupRequest(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   VAR(uint8, AUTOMATIC) u8RequestingLayer)
{
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;
	P2CONST(LinIf_tstrChannelStaticConf, AUTOMATIC, LINIF_CALIB_CONST)
													   pkstrCurrChannelLT;
	P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_VAR) 
													   pkstrCurrChannelPB;
    P2CONST(LinIf_tstrChannelCriticalSec, AUTOMATIC, LINIF_VAR)
													   pkstrCurrChnlCritsection;
    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
	pkstrCurrChannelLT   = &(LinIf_akstreChannelsLT[u8ChannelIndex]);
	pkstrCurrChannelPB   = &(LinIf_pkstreGlobalConfig->pkstrChannels[u8ChannelIndex]);
    pkstrCurrChnlCritsection = &(LinIf_akstreChannelsCritSec[u8ChannelIndex]);
    /*!Enter GotoSleep critical section  */
    pkstrCurrChnlCritsection->pfvidEnterSecGotoSleep001();
	pkstrCurrChnlCritsection->pfvidEnterSecGotoSleep003();
	
	
	  /*!Enter SendWakeUp critical section  */
    pkstrCurrChnlCritsection->pfvidEnterSecSendWkup000();
	pkstrCurrChnlCritsection->pfvidEnterSecSendWkup002();
	
	
    /*! If there is a goto sleep command issued */
    if(TRUE == pstrCurrChannelVars->bGotoSleepFlag)
    {
        /*!If there the goto sleep command is sent and the communication 
            state of the channel is not Idle*/
        if( (TRUE == pstrCurrChannelVars->bSendGotoSleep)
            &&
            (LinIf_u8IF_STATE_IDLE != pstrCurrChannelVars->u8IFCommState))
        {
            /*!If the FrameTimeCounter is 0 then goto sleep command was sent
                and checked so set bSendWakeup flag = true */
            if(0 == pstrCurrChannelVars->u8FrameTimeCounter) 
            {
                /*\Trace_To: LinIf-CDD-0089(0) */
                pstrCurrChannelVars->bSendWakeup = TRUE;
                vidHandleNM(pkstrCurrChannelPB);
            }
            else /*!Else */
            {
                /*! goto sleep command was sent but was not checked so stop the
                     goto sleep command by setting bGotoSleepFlag and 
                     bSendGotoSleepto FALSE, and FrameTimeCounter to 0
                     and set the channel state to OPERATIONAL 
                     and comm. state to IDLE */
                /*\Trace_To: LinIf-CDD-0088(0) */
                pstrCurrChannelVars->bGotoSleepFlag = FALSE;
                pstrCurrChannelVars->bSendGotoSleep = FALSE;
                pstrCurrChannelVars->u8FrameTimeCounter = 0;
                pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_IDLE;
                pstrCurrChannelVars->u8IFChannelState = 
                    LinIf_u8CHANNEL_OPERATIONAL;

                /*! Call GotoSleeoConfirm with status = false to indicate that 
                    the gotosleep process is stopped */
                pkstrCurrChannelPB->pfvidGotoSleepConfrm(
                    LinIf_udtGetChannelIdByIndex(u8ChannelIndex), FALSE);

                /*\Trace_To: LinIf-CDD-0087(0) */
                /*!If the wakeup was from the bus, call the drivers 
                    Lin_WakeupValidation */
                if(u8BUS_WAKEUP == u8RequestingLayer)
                {
					pkstrCurrChannelLT->pkstrDrvRef->pfvidWakeupValidation();
                }
                /*!Else If the wakeup was from the upper layer, call the 
                    drivers wakeup confirmation */
                else if(u8UPPERLAYER_WAKEUP == u8RequestingLayer)
                {
                
                    pkstrCurrChannelPB->
                        pfvidWakeUpConfrm(
                            LinIf_udtGetChannelIdByIndex(u8ChannelIndex), TRUE);
                }
                else
                {
                    /* Do nothing Just for misra. */
                }
                /*! Endif */
            }
            /*! Endif */
        }
        /*! Else (no goto sleep command is sent yet or the channel is Idle) */
        else
        {
            /*! goto sleep command was not sent so stop the 
                     goto sleep command by setting bGotoSleepFlag and 
                     bSendGotoSleepto FALSE and set the channel state to 
                     OPERATIONAL */
            /*\Trace_To: LinIf-CDD-0076(0) */
            pstrCurrChannelVars->bGotoSleepFlag = FALSE;
            pstrCurrChannelVars->bSendGotoSleep = FALSE;
            pstrCurrChannelVars->u8IFChannelState = LinIf_u8CHANNEL_OPERATIONAL;
            pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_IDLE;
            /*!If the wakeup was from the bus, call the drivers 
                Lin_WakeupValidation */
            if(u8BUS_WAKEUP == u8RequestingLayer)
            {
                /*VAR(uint8, AUTOMATIC) u8DriverIndex;*/
                /*u8DriverIndex = 
                    LinIf_akstreChannelsLT[u8ChannelIndex].u8DrvRefIndex;*/
                /*LinIf_akstreLinDrvConf[u8DriverIndex].pfvidWakeupValidation();*/
				pkstrCurrChannelLT->pkstrDrvRef->pfvidWakeupValidation();
            }
            /*!Else (wakeup from upperlayer), call WakeupConf. with success = 
                true. */
            else
            {
                /*\Trace_To: LinIf-CDD-0284(0) */
                pkstrCurrChannelPB->pfvidWakeUpConfrm(
                    LinIf_udtGetChannelIdByIndex(u8ChannelIndex), TRUE);
            }
            /*! Endif */
        }
        /*! Endif */
    }
    /*! Else (no goto sleep command is issued from upper layer) */
    else
    {
        /*!If the channel is not sleep */
        /*\Trace_To: LinIf-CDD-0199(0) */
        if(pstrCurrChannelVars->u8IFChannelState != LinIf_u8CHANNEL_SLEEP)
        {
            /*! Maintain the channel state to OPERATIONAL*/
            pstrCurrChannelVars->u8IFChannelState = LinIf_u8CHANNEL_OPERATIONAL;
            /*\Trace_To: LinIf-CDD-0086(0) */
            /*!If the wakeup was from the bus, call the drivers 
                Lin_WakeupValidation */
            if(u8BUS_WAKEUP == u8RequestingLayer)
            {
				pkstrCurrChannelLT->pkstrDrvRef->pfvidWakeupValidation();
            }
            /*!Else (wakeup from upperlayer), call WakeupConf. with success = 
                true. */
            else /* wakeup from upperlayer */
            {
                /*\Trace_To: LinIf-CDD-0199(0) */
                /*\Trace_To: LinIf-CDD-0284(0) */
                pkstrCurrChannelPB->pfvidWakeUpConfrm(
                    LinIf_udtGetChannelIdByIndex(u8ChannelIndex), TRUE);
            }
            /*! Endif */
        }
        /*! Else (the channe is sleep) */
        else
        {
            /*! Set bSendWakeup flag = true */
            /*\Trace_To: LinIf-CDD-0200(0) */
            pstrCurrChannelVars->bSendWakeup = TRUE;
            vidHandleNM(pkstrCurrChannelPB);

        }
    }
	
	/*!Exit SendWakeUp critical section  */
	pkstrCurrChnlCritsection->pfvidExitSecSendWkup002();
    pkstrCurrChnlCritsection->pfvidExitSecSendWkup000();
	
    /*!Exit GotoSleep critical section 		 */
	pkstrCurrChnlCritsection->pfvidExitSecGotoSleep003();
    pkstrCurrChnlCritsection->pfvidExitSecGotoSleep001();


    
/*!Deviation : Inhibit MISRA rule [4700]: No further simplification is        */
/*              possible                                                      */
/* PRQA S 4700 ++                                                             */
}
/* PRQA S 4700 --                                                             */


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function    : LinIf_vidIFNewSchEntryCallout                               */
/*!\Description The function that is called by the schedule table manager when
                 a new schedule entry is due \n                               
    \param[in] The index of the current channel is the channels array
            \Range   0..LinIf_ku8eNumberOfChannels  \n                        */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidIFNewSchEntryCallout(
    VAR(uint8, AUTOMATIC) u8ChannelIndex
)
{
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    /*!If the channel comm. state is not Idle */
    if(LinIf_u8IF_STATE_IDLE != pstrCurrChannelVars->u8IFCommState)
    {
        /*!Call enuCheckStatus with tolerate busy = false to stop any on going
            message. and set the state to IDLE */
        /*\Trace_To: LinIf-CDD-0033(0) */
        (void)enuCheckStatus(u8ChannelIndex, FALSE);
        pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_IDLE;

    }
    /*! Endif */
    /*!If a gotosleep command is issued (bGotoSleepFlag = true) */
    /*\Trace_To: LinIf-CDD-0078(0) */
    if(TRUE == pstrCurrChannelVars->bGotoSleepFlag)
    {
        /*!Start sending gotosleep command on the bus by setting bSendGotoSleep
            = true */
        pstrCurrChannelVars->bSendGotoSleep = TRUE;
    }
    /*! Endif */
}

/******************************************************************************/
/*!Function    : LinIf_Init                                                  */
/*!\Description Initializes the LIN Interface \n                               
    \param[in] The global post build config pointer to the LinIf               
            \Range   NOT NULL  \n                                             */
/*\Trace_To    : LinIf-CDD-0169(0), LinIf-CDD-0170(0)                        */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_Init(
    P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_CONST) pkstrLinIfConf
)
{
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is Init and the DevErrorDetect is true, 
        report to Det LINIF_E_ALREADY_INITIALIZED */
    /*\Trace_To: LinIf-CDD-0174(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_UNINIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                        LINIF_INSTANCE_ID, 
                        LinIf_u8LINIF_INIT_SRV_ID,
                        LINIF_E_ALREADY_INITIALIZED);
    }
    /*!If the input pointer is NULL and the DevErrorDetect is true, 
        report to Det LINIF_E_PARAMETER_POINTER */
    /*\Trace_To: LinIf-CDD-0171(0) */
    else if(NULL_PTR == pkstrLinIfConf)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                        LINIF_INSTANCE_ID, 
                        LinIf_u8LINIF_INIT_SRV_ID,
                        LINIF_E_PARAMETER_POINTER);
    }
    else
    {
#endif
        VAR(uint8_least, AUTOMATIC)                               u8LoopIndex;
        P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;

        /*\Trace_To: LinIf-CDD-0172(0) */
        /*\Trace_To: LinIf-CDD-5003(0) */
        /*! Save the input pointer to LinIf_pkstreGlobalConfig */
        LinIf_pkstreGlobalConfig = pkstrLinIfConf;
        
        /*!LOOP on the channels */
        for(u8LoopIndex = 0;
            u8LoopIndex < LinIf_ku8eNumberOfChannels; 
            u8LoopIndex++)
        {
            pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8LoopIndex]);

            /*!If the preconfigured channel Starup state is NORMAL set the 
                Channel State to OPERATIONAL*/
            /*\Trace_To: LinIf-CDD-0074(0) */
            if( LinIf_akstreChannelsLT[u8LoopIndex].enuStartupState 
                == 
                LinIf_NORMAL)
            {
                pstrCurrChannelVars->u8IFChannelState = 
                    LinIf_u8CHANNEL_OPERATIONAL;
            }
            /*! Else set the Channel State to SLEEP */
  
            else
            {
                pstrCurrChannelVars->u8IFChannelState = LinIf_u8CHANNEL_SLEEP;
            }

            /*! set the Channel comm. State to IDLE*/
            pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_IDLE;

            /*! set the bGotoSleepFlag, bSendGotoSleep, bSendWakeup to FALSE */
            pstrCurrChannelVars->bGotoSleepFlag  = FALSE;
            pstrCurrChannelVars->bSendGotoSleep  = FALSE;
            pstrCurrChannelVars->bSendWakeup     = FALSE;
            /*!Call LinIf_vidSTMInit to initialize the channel vars that the 
               STM is concerned with*/
            LinIf_vidSTMInit(u8LoopIndex);
        }
        /*! set the LinIf_u8eLinIfState to INIT*/
        /*\Trace_To: LinIf-CDD-0068(0) */
        LinIf_u8eLinIfState = LinIf_u8STATE_INIT;

#if LinIf_u8DEV_ERROR_DETECT == STD_ON
    }
#endif
}
/******************************************************************************/
/*!Function    : LinIf_vidIFSendFrame                                        */
/*!\Description Sends a LIN frame on the specified channel with the specified
                 length \n                               
    \param[in]   The index of the current channel is the channels array
            \Range   0..LinIf_ku8eNumberOfChannels - 1 \n
    \param[in]   The frame length                
            \Range   1..8  \n                                                 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidIFSendFrame(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    VAR(uint8, AUTOMATIC) u8FrameLength
)
{
    VAR(Lin_PduType, AUTOMATIC)                             udtLinPdu;
    /*VAR(uint8, AUTOMATIC)                                   u8DriverIndex;*/
    P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST)  pkstrFrameToSend;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)      pstrCurrChannelVars;
	P2CONST(LinIf_tstrChannelStaticConf, AUTOMATIC, LINIF_CALIB_CONST)
															pkstrCurrChannelLT;
    VAR(Std_ReturnType, AUTOMATIC)                          udtSendFrameRet;

    pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    pkstrCurrChannelLT   = &(LinIf_akstreChannelsLT[u8ChannelIndex]);
    pkstrFrameToSend    = pstrCurrChannelVars->pkstrCurrentFrame;

    /*!Create an Lin Pdu (Lin_PduType) */
    /*!Set the checksum model according to the saved in pkstrCurrentFrame in
        the current channel */
    if(pkstrFrameToSend->enuChecksumType == LinIf_CLASSIC)
    {
        udtLinPdu.Cs = LIN_CLASSIC_CS;
    }
    else 
    {
        udtLinPdu.Cs = LIN_ENHANCED_CS;
    }
    /*! Set the data length to the input value*/
    udtLinPdu.Dl = u8FrameLength;

    /*!If the frame is Tx Frame or Internal Frame set the data pointer to the
        start of au8DataBuffer in the current channel */
    if( (pkstrFrameToSend->enuFrameDirection == LinIf_TX_PDU)
        ||
        (pkstrFrameToSend->enuFrameDirection == LinIf_INTERNAL_PDU))
    {
        udtLinPdu.SduPtr = &(pstrCurrChannelVars->au8DataBuffer[0]);
    }

    /*!If the frame is Tx Frame set its pid from pkstrCurrentFrame in the 
        current channel and set Drc to LIN_MASTER_RESPONSE */
    /*!If the frame is Rx Frame set its pid from pkstrCurrentFrame in the
        current channel and set Drc to LIN_SLAVE_RESPONSE */
    /*!If the frame is SlaveToSlave Frame set its pid from pkstrCurrentFrame
        in the current channel and set Drc to LIN_SLAVE_TO_SLAVE */
    /*!If the frame is Internal and LinIf_SRF Frame set its pid to 0x3D in the
        current channel and set Drc to LIN_SLAVE_RESPONSE */
    /*!If the frame is Internal and not LinIf_SRF Frame set its pid to 0x3C in
        the current channel and set Drc to LIN_MASTER_RESPONSE */
    if(LinIf_INTERNAL_PDU == pkstrFrameToSend->enuFrameDirection)
    {
        if( LinIf_SRF == pkstrFrameToSend->enuFrameType)
        {
            /*\Trace_To: LinIf-CDD-0416(0) */
            udtLinPdu.Pid = u8SRF_ID;
            udtLinPdu.Drc = LIN_SLAVE_RESPONSE;
        }
        else
        {
            /*\Trace_To: LinIf-CDD-0416(0) */
            udtLinPdu.Pid = u8MRF_ID;
            udtLinPdu.Drc = LIN_MASTER_RESPONSE;            
        }
    }
    else
    {
        udtLinPdu.Pid = pkstrFrameToSend->u8Pid;
        if(LinIf_TX_PDU == pkstrFrameToSend->enuFrameDirection)
        {
            /*\Trace_To: LinIf-CDD-0040(0) */
            udtLinPdu.Drc = LIN_MASTER_RESPONSE;
        }
        else if(LinIf_RX_PDU == pkstrFrameToSend->enuFrameDirection)
        {
            udtLinPdu.Drc = LIN_SLAVE_RESPONSE;
        }
        else if(LinIf_SLAVE_TO_SLAVE_PDU == pkstrFrameToSend->enuFrameDirection)
        {
            /*\Trace_To: LinIf-CDD-0048(0) */
            udtLinPdu.Drc = LIN_SLAVE_TO_SLAVE;
        }
        else
        {
            /* cannot reach here, Just for MISRA */
        }

    }

    /*! Call Lin_SendFrame of the driver controlling the current channel 
         with u8LinChannelId of the channel and the filled Lin Pdu */
    /*u8DriverIndex = LinIf_akstreChannelsLT[u8ChannelIndex].u8DrvRefIndex;*/

    /*\Trace_To: LinIf-CDD-0048(0) */
    /*\Trace_To: LinIf-CDD-0040(0) */
    /*\Trace_To: LinIf-CDD-0043(0) */
		
	udtSendFrameRet = pkstrCurrChannelLT->pkstrDrvRef->pfudtSendFrame
							(pkstrCurrChannelLT->u8LinChannelId, &udtLinPdu);

    /*!If the call returns E_OK set the channel comm. state to SEND_FRAME
        else do nothing */
    if(E_OK == udtSendFrameRet)
    {
        pstrCurrChannelVars->u8IFCommState = LinIf_u8IF_STATE_SEND_FRAME;
    }
}

/******************************************************************************/
/*!Function    : LinIf_MainFunction                                          */
/*!\Description  The main processing function of the LIN Interface           */
/*\Trace_To    : LinIf-CDD-0273(0)                                           */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_MainFunction(void)
{
    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true, 
        report to Det LINIF_E_UNINIT */
    /*\Trace_To: LinIf-CDD-5009(0) */
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                        LINIF_INSTANCE_ID, 
                        LinIf_u8LINIF_MAINFN_SRV_ID,
                        LINIF_E_UNINIT);
    }
    else
    {
#endif
        VAR(uint8_least, AUTOMATIC) u8LoopIndex;

        /*!LOOP on the channels */
        /*\Trace_To: LinIf-CDD-0274(0) */
        /*\Trace_To: LinIf-CDD-5005(0) */
        for(u8LoopIndex = 0;
            u8LoopIndex < LinIf_ku8eNumberOfChannels;
            u8LoopIndex++)
        {
            P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)
                pstrCurrChannelVars;
            
            P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_CALIB_CONST) 
                pkstrCurrChannel = 
                    &(LinIf_pkstreGlobalConfig->pkstrChannels[u8LoopIndex]);

            pstrCurrChannelVars = &LinIf_astreChannelsVars[u8LoopIndex];
            /*! If the channel state is OPERATIONAL */
            /*\Trace_To: LinIf-CDD-0072(0) */
            /*\Trace_To: LinIf-CDD-0077(0) */
            /*\Trace_To: LinIf-CDD-5002(0) */
            /*\Trace_To: LinIf-CDD-5149(0) */
            if( pstrCurrChannelVars->u8IFChannelState 
                == 
                LinIf_u8CHANNEL_OPERATIONAL)
            {
                /*! If bSendGotoSleep = FALSE */
                if(FALSE == pstrCurrChannelVars->bSendGotoSleep)
                {
#if (LinIf_u8TP_SUPPORTED == STD_ON)
                    /*!Call LinIf_vidTPMain */
                    /*\Trace_To: LinIf-CDD-0103(0) */
                    /*\Trace_To: LinIf-CDD-0276(0) */
                    /*\Trace_To: LinIf-CDD-0277(0) */
                    /*\Trace_To: LinIf-CDD-5115(0) */
                    /*\Trace_To: LinIf-CDD-5149(0) */
                    /*\Trace_To: LinIf-CDD-5050(1) */
                    LinIf_vidTPMain(pkstrCurrChannel);
#endif
                    /*!Call LinIf_vidSTMMain */
                    /*\Trace_To: LinIf-CDD-0073(0) */
                    /*\Trace_To: LinIf-CDD-0275(0) */
                    /*\Trace_To: LinIf-CDD-0277(0) */
                    /*\Trace_To: LinIf-CDD-5002(0) */
                    LinIf_vidSTMMain(pkstrCurrChannel);

                    /*!Call vidIFMain */
                    /*\Trace_To: LinIf-CDD-0277(0) */
                    vidIFMain(pkstrCurrChannel);

#if (LinIf_u8TP_SUPPORTED == STD_ON)
                    /*! Call LintIf_vidTPTimeoutHandler to handle Tp timeouts
                        after the STM and IF has done their work */
                    LinIf_vidTPTimeoutHandler(pkstrCurrChannel);
#endif

                    if( (FALSE != pstrCurrChannelVars->bGotoSleepFlag)
                        &&
                        (LinIf_u8IF_STATE_IDLE == 
                                        pstrCurrChannelVars->u8IFCommState))
                    {
                        pstrCurrChannelVars->bSendGotoSleep = TRUE;
                    }
                }
                /*! Endif */
            }
            /*! Else (the channel state is SLEEP */
            else
            {
                /*! If there is no Wakeup request (bSendWakeup = false) and 
                    there is sleep request (bGotoSleepFlag = true) set 
                    bSendGotoSleep to true. */
                if( (FALSE == pstrCurrChannelVars->bSendWakeup)
                    &&
                    (FALSE != pstrCurrChannelVars->bGotoSleepFlag))
                {
                    /*\Trace_To: LinIf-CDD-0079(0) */
                    pstrCurrChannelVars->bSendGotoSleep = TRUE;
                }
            }
            if( (FALSE != pstrCurrChannelVars->bSendWakeup)
                ||
                (FALSE != pstrCurrChannelVars->bSendGotoSleep))
            {  
                /*! Enter critical section to protect the current call of
                 vidHandleNM from interruption by wakeup handling             */
				P2CONST(LinIf_tstrChannelCriticalSec, AUTOMATIC, LINIF_VAR)
													   pkstrCurrChnlCritsection;
				pkstrCurrChnlCritsection = &(LinIf_akstreChannelsCritSec[u8LoopIndex]);
                pkstrCurrChnlCritsection->pfvidEnterSecGotoSleep002();
				
				/*!Enter SendWakeUp critical section  */
				pkstrCurrChnlCritsection->pfvidEnterSecSendWkup001();

                /*! Call vidHandleNM to handle sleep and wakeup requests 
                    for the channel) */
                /*\Trace_To: LinIf-CDD-0078(0) */
                /*\Trace_To: LinIf-CDD-0089(0) */
                vidHandleNM(pkstrCurrChannel);
                
               /*!Leave SendWakeUp critical section  */
				pkstrCurrChnlCritsection->pfvidExitSecSendWkup001();

                /*! Exit from the critical section  */
                pkstrCurrChnlCritsection->pfvidExitSecGotoSleep002();
            }
        }
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/******************************************************************************/
/*!Function    : LinIf_GotoSleep                                             */
/*!\Description Initiates a transition into the Sleep Mode on the 
                 selected channel.  \n                               
    \param[in]   Identification of the LIN channel. 
            \Range   0..LinIf_ku8eNumberOfChannels  \n
    \return 
    E_OK: Request to go to sleep has been accepted or sleep 
    transition is already in progress or controller is already in sleep 
    state 
    E_NOT_OK: Request to go to sleep has not been accepted due 
    to one or more of the following reasons: 
    - LIN Interface has not been initialized 
    - referenced channel does not exist (identification is out of range)      */

/******************************************************************************/

FUNC(Std_ReturnType, LINIF_CODE) LinIf_GotoSleep(
    VAR(NetworkHandleType, AUTOMATIC) udtChannel)
{
    /*\Trace_To    : LinIf-CDD-0193(0)                                       */
    VAR(Std_ReturnType, AUTOMATIC)  udtRet;
    VAR(uint8, AUTOMATIC)           u8ChannelIndex;

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true,
        report to Det LINIF_E_UNINIT */
    /*\Trace_To: LinIf-CDD-5020(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_GOSLEEP_SRV_ID,
                LINIF_E_UNINIT);
        udtRet = E_NOT_OK;
    }
    else
    {
#endif
        /*!Call LinIf_udtGetChannelIndexById to get the referenced channel 
            Index in the channels array */
        /*!If LinIf_udtGetChannelIndexById returns E_NOT_OK and the 
            DevErrorDetect is true, report to Det LINIF_E_NONEXISTENT_CHANNEL */
        /*\Trace_To: LinIf-CDD-0196(0) */
        udtRet = LinIf_udtGetChannelIndexById(udtChannel, &u8ChannelIndex);

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
        if(E_NOT_OK == udtRet)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                    LINIF_INSTANCE_ID, 
                    LinIf_u8LINIF_GOSLEEP_SRV_ID,
                    LINIF_E_NONEXISTENT_CHANNEL);
        }
        else
        {
#endif
            /*!Enter GotoSleep critical section to prevent pre-emption of 
               vidHandleNM*/
            LinIf_akstreChannelsCritSec[u8ChannelIndex].pfvidEnterSecGotoSleep000();
            /*!Set bGotoSleepFlag to TRUE */
            /*\Trace_To: LinIf-CDD-0194(0) */
            LinIf_astreChannelsVars[u8ChannelIndex].bGotoSleepFlag = TRUE;

            /*!Exit GotoSleep critical section  */
            LinIf_akstreChannelsCritSec[u8ChannelIndex].pfvidExitSecGotoSleep000();
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
    return udtRet;
}

/******************************************************************************/
/*!Function    : LinIf_Wakeup                                                */
/*!\Description Initiates the wake up process.  \n
    \param[in]   Identification of the LIN channel. 
            \Range   0..LinIf_ku8eNumberOfChannels  \n
    \return 
    E_OK: Request to wake up has been accepted or the 
    controller is not in sleep state. 
    E_NOT_OK: Request to wake up has not been accepted due to 
    one or more of the following reasons: 
    - LIN Interface has not been initialized 
    - referenced channel does not exist (identification is out of range)      */
/*\Trace_To    : LinIf-CDD-0198(0)                                           */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_Wakeup(
    VAR(NetworkHandleType, AUTOMATIC) udtChannel)
{
    VAR(Std_ReturnType, AUTOMATIC)  udtRet;
    VAR(uint8, AUTOMATIC)           u8ChannelIndex;

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true, 
        report to Det LINIF_E_UNINIT */
    /*\Trace_To: LinIf-CDD-5022(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_WAKEUP_SRV_ID,
                LINIF_E_UNINIT);
        udtRet = E_NOT_OK;
    }
    else
    {
#endif
        /*!Call LinIf_udtGetChannelIndexById to get the referenced channel 
            Index in the channels array */
        /*!If LinIf_udtGetChannelIndexById returns E_NOT_OK and the 
            DevErrorDetect is true,
            report to Det LINIF_E_NONEXISTENT_CHANNEL */
        /*! Else set the return to E_OK as the request shall be accepted */
        /*\Trace_To: LinIf-CDD-0201(0) */
        /*\Trace_To: LinIf-CDD-0199(0) */
        udtRet = LinIf_udtGetChannelIndexById(udtChannel, &u8ChannelIndex);

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
        if(E_NOT_OK == udtRet)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                    LINIF_INSTANCE_ID, 
                    LinIf_u8LINIF_WAKEUP_SRV_ID,
                    LINIF_E_NONEXISTENT_CHANNEL);
        }
        else
        {
#endif
        /*!Call vidHandleWakeupRequest indicating that the request is from the
            upper layer*/
        vidHandleWakeupRequest(u8ChannelIndex, u8UPPERLAYER_WAKEUP);
        /*\Trace_To: LinIf-CDD-0199(0) */

#if LinIf_u8DEV_ERROR_DETECT == STD_ON
        }
    }
#endif
    return udtRet;
}

/******************************************************************************/
/*!Function    : LinIf_CheckWakeup                                           */
/*!\Description Will be called when the EcuM has been notified about a wakeup
                 on a specific LIN channel  \n                               
    \param[in]   Source device, which initiated the wakeup event: 
                   LIN controller or LIN transceiver \n                        
    \return 
            E_OK: No error has occurred during execution of the API 
            E_NOT_OK: An error has occurred during execution of 
            the API or invalid WakeupSource                                  */
/*\Trace_To    : LinIf-CDD-0268(0)                                           */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_CheckWakeup(
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{
    VAR(Std_ReturnType, AUTOMATIC)  udtRet;
    VAR(uint8, AUTOMATIC)           u8ChannelIndex;
    VAR(uint8_least, AUTOMATIC)           u8LoopIndex;
    VAR(boolean, AUTOMATIC)         bFound;

    /*! Set return to E_NOT_OK */
    udtRet = E_NOT_OK;
    bFound = FALSE;

	u8ChannelIndex = 0;
	
    /*! Loop on each channel in LinIf_akstreChannelsLT */
    for(u8LoopIndex = 0;
        (u8LoopIndex < LinIf_ku8eNumberOfChannels) && (bFound == FALSE);
        u8LoopIndex++)
    {
        /*! If u8LinIfChannelId of the channel is equal to u8ChannelId */
        if( LinIf_akstreChannelsLT[u8LoopIndex].u32WakeupSourceType == WakeupSource)
        {
            /*! Set u8ChannelIndex to u8LoopIndex */
            u8ChannelIndex = u8LoopIndex;
            /*! Set return to E_OK */
            udtRet = E_OK;
            /*! Exit the Loop */
            bFound = TRUE;
        } 
        /*! End If */
    }
    /*! End Loop */
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)

    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true,
        report to Det LINIF_E_UNINIT */
    /*\Trace_To: LinIf-CDD-5043(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_CHKWKUP_SRV_ID,
                LINIF_E_UNINIT);    
    }
    else
    {

        /*!If WakeUp Source type doesn't map to a LinIf channel and the 
            DevErrorDetect is true, report to Det LINIF_E_PARAM_WAKEUPSOURCE */
        /*\Trace_To: LinIf-CDD-0269(0) */

        if(E_NOT_OK == udtRet)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                    LINIF_INSTANCE_ID, 
                    LinIf_u8LINIF_CHKWKUP_SRV_ID,
                    LINIF_E_PARAM_WAKEUPSOURCE);
        }
        else
        {
#endif
            /*\Trace_To: LinIf-CDD-0086(0) */
            /*!Call vidHandleWakeupRequest indicating that the request is from
                the bus*/
            vidHandleWakeupRequest(u8ChannelIndex, u8BUS_WAKEUP);

#if LinIf_u8DEV_ERROR_DETECT == STD_ON
        }
    }
#endif
    return udtRet;
}


/******************************************************************************/
/*!Function    : LinIf_SetTrcvMode                                           */
/*!\Description Set the given LIN transceiver to the given mode.   \n
    \param[in]   Identification of the LIN channel. 
            \Range   0..LinIf_ku8eNumberOfChannels  \n
    \param[in]   Requested mode transition 
            \Range  LINTRCV_TRCV_MODE_NORMAL, LINTRCV_TRCV_MODE_STANDBY, 
                    LINTRCV_TRCV_MODE_SLEEP  \n
    \return 
    E_OK: Will be returned, if the transceiver state has been 
    changed to the requested mode. 
    E_NOT_OK: Will be returned, if the transceiver state change has 
    failed or the parameter is out of the allowed range. The previous 
    state has not been changed.                                               */
/*\Trace_To    : LinIf-CDD-0202(0)                                           */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_SetTrcvMode(
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when LinIfMultipleTrcvDriverSupport is ON                      */
/* PRQA S 3206 ++                                                             */
    VAR(NetworkHandleType, AUTOMATIC) udtChannel,
/* PRQA S 3206 --                                                             */
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when LinIfMultipleTrcvDriverSupport is ON                      */
/* PRQA S 3206 ++                                                             */
    VAR(LinTrcv_TrcvModeType, AUTOMATIC) enuTransceiverMode)
/* PRQA S 3206 --                                                             */
{
    /*!If the Pre-Compile configuration LinIf_bMULTIPL_TRCV_SUPPORT is not 
        STD_ON and DevErrorDetect is true, report to Det 
        LINIF_E_TRCV_INV_CHANNEL */

#if ((LinIf_bMULTIPL_TRCV_SUPPORT == STD_ON) && (LinIf_u8NUMBER_OF_TRCVS > 0U))
    VAR(Std_ReturnType, AUTOMATIC)  udtRet;
    VAR(uint8, AUTOMATIC)           u8ChannelIndex;
    VAR(uint8, AUTOMATIC)           u8TrcvDriverIndex;
    VAR(uint8, AUTOMATIC)           u8TrcvChannelId;
    

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)

    VAR(Std_ReturnType, AUTOMATIC)  udtTempRet;
    
    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true,
        report to Det LINIF_E_UNINIT */
    /*\Trace_To: LinIf-CDD-5024(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SETTRCVMODE_ID,
                LINIF_E_UNINIT);
        udtRet = E_NOT_OK;
    }
    else
    {
        /*!Call LinIf_udtGetChannelIndexById to get the referenced channel 
            Index in the channels array */
        /*!If LinIf_udtGetChannelIndexById returns E_NOT_OK and the 
            DevErrorDetect is true, report to Det LINIF_E_TRCV_INV_CHANNEL */
        /*\Trace_To: LinIf-CDD-0206(0) */
        udtRet = LinIf_udtGetChannelIndexById(udtChannel, &u8ChannelIndex);
        if(E_NOT_OK == udtRet)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SETTRCVMODE_ID,
                LINIF_E_TRCV_INV_CHANNEL);
        }
        /*!If bTrcvPresent in this channel is FALSE (There is no transceiver 
            driver connected to this channel) and the DevErrorDetect is true,
            report to Det LINIF_E_TRCV_INV_CHANNEL */
        else if(LinIf_akstreChannelsLT[u8ChannelIndex].bTrcvPresent == FALSE)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SETTRCVMODE_ID,
                LINIF_E_TRCV_INV_CHANNEL);
            udtRet = E_NOT_OK;
        }
        /*!If enuTransceiverMode is invalid, report to Det 
            LINIF_E_TRCV_INV_MODE */
        /*\Trace_To: LinIf-CDD-0207(0) */
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3356, 3359, 3201]: The condition appears  */
/*             always false because it checks for an invalid value, and for   */
/*             the same reason the statement is unreachable                   */
/* PRQA S 3356, 3359, 3201 ++                                                 */
        else if((enuTransceiverMode != LINTRCV_TRCV_MODE_NORMAL)
            &&
            (enuTransceiverMode != LINTRCV_TRCV_MODE_STANDBY)
            &&
            (enuTransceiverMode != LINTRCV_TRCV_MODE_SLEEP))
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SETTRCVMODE_ID,
                LINIF_E_TRCV_INV_MODE);
            udtRet = E_NOT_OK;
        }
/* PRQA S 3356, 3359, 3201 --                                                 */
        else
        {        
            VAR(LinTrcv_TrcvModeType, AUTOMATIC) enuCurrTrcvMode;
#else
            (void)LinIf_udtGetChannelIndexById(udtChannel, &u8ChannelIndex);
#endif

            
            u8TrcvDriverIndex = 
                LinIf_akstreChannelsLT[u8ChannelIndex].u8TrcvDrvConfIndex;
            u8TrcvChannelId = 
                LinIf_akstreLinTrcvDrvConf[u8TrcvDriverIndex].
                u8TransceiverChannelId;

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
            /*!Call LinTrcv_GetOpMode if the returned mode is not 
                LINTRCV_TRCV_MODE_NORMAL and the requested mode is 
                LINTRCV_TRCV_MODE_SLEEP, and the DevErrorDetect is true,
                report to Det LINIF_E_TRCV_NOT_NORMAL */
            /*\Trace_To: LinIf-CDD-0208(0) */
            enuCurrTrcvMode = LINTRCV_TRCV_MODE_STANDBY;
            /* Ignore the return value of GetOpMode because if the 
               enuCurrTrcvMode is not changed Det is called and the function 
               is stopped */
            udtTempRet = 
                LinIf_akstreLinTrcvDrvConf[u8TrcvDriverIndex].strTrcvRef.
                pfudtGetOpMode(u8TrcvChannelId, &enuCurrTrcvMode);
            
            if( (   (enuCurrTrcvMode != LINTRCV_TRCV_MODE_NORMAL)
                    &&
                    (enuTransceiverMode == LINTRCV_TRCV_MODE_SLEEP)
                )
                ||
                (udtTempRet != E_OK))
            {
                (void)Det_ReportError(LINIF_MODULE_ID, 
                    LINIF_INSTANCE_ID, 
                    LinIf_u8LINIF_SETTRCVMODE_ID,
                    LINIF_E_TRCV_NOT_NORMAL);
                udtRet = E_NOT_OK;
            }
            else
            {
#endif
                /*!Else Call LinTrcv_SetOpMode with the input mode. */
                /*\Trace_To: LinIf-CDD-0203(0) */
                /*\Trace_To: LinIf-CDD-0204(0) */
                /*\Trace_To: LinIf-CDD-0205(0) */
                udtRet = LinIf_akstreLinTrcvDrvConf[u8TrcvDriverIndex].
                    strTrcvRef.
                    pfudtSetOpMode(u8TrcvChannelId, enuTransceiverMode);

#if LinIf_u8DEV_ERROR_DETECT == STD_ON
            }
        }
    }
#endif
    /*\Trace_To: LinIf-CDD-0205(0) */
    return udtRet;
    /*\Trace_To: LinIf-CDD-0209(0) */
#else /*(   (LinIf_bMULTIPL_TRCV_SUPPORT == STD_ON) 
            && (LinIf_u8NUMBER_OF_TRCVS > 0))*/
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(LINIF_MODULE_ID, 
        LINIF_INSTANCE_ID, 
        LinIf_u8LINIF_SETTRCVMODE_ID,
        LINIF_E_TRCV_INV_CHANNEL);
#endif
    return E_NOT_OK;
#endif
    

}



/******************************************************************************/
/*!Function    : LinIf_GetTrcvMode                                           */
/*!\Description Returns the actual state of a LIN Transceiver Driver.    \n
    \param[in]   Identification of the LIN channel. 
            \Range   0..LinIf_ku8eNumberOfChannels  \n
    \param[out]  Pointer to a memory location where output value will be 
                 stored. 
            \Range   NOT NULL  \n
    \return 
    E_OK: The call of the LINTransceiver Driver's API service 
    has returned E_OK 
    E_NOT_OK: The call of the LIN Transceiver Driver's API 
    service has returned E_NOT_OK                                             */
/*\Trace_To    : LinIf-CDD-0211(0)                                           */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_GetTrcvMode(
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when LinIfMultipleTrcvDriverSupport is ON                      */
/* PRQA S 3206 ++                                                             */
    VAR(NetworkHandleType, AUTOMATIC) udtChannel,
/* PRQA S 3206 --                                                             */
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when LinIfMultipleTrcvDriverSupport is ON                      */
/* PRQA S 3206 ++                                                             */
    P2VAR(LinTrcv_TrcvModeType, AUTOMATIC, LINIF_APPL_DATA) penuTransceiverMode)
/* PRQA S 3206 --                                                             */
{   
    /*!If the Pre-Compile configuration LinIf_bMULTIPL_TRCV_SUPPORT is not 
        STD_ON and DevErrorDetect is true, report to Det 
        LINIF_E_TRCV_INV_CHANNEL */

#if ((LinIf_bMULTIPL_TRCV_SUPPORT == STD_ON) && (LinIf_u8NUMBER_OF_TRCVS > 0U))
    
    VAR(uint8, AUTOMATIC)           u8ChannelIndex;
    VAR(uint8, AUTOMATIC)           u8TrcvDriverIndex;
    VAR(uint8, AUTOMATIC)           u8TrcvChannelId;
    VAR(Std_ReturnType, AUTOMATIC)  udtRet;

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true,
        report to Det LINIF_E_UNINIT */
    /*\Trace_To: LinIf-CDD-5026(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_GETTRCVMODE_ID,
                LINIF_E_UNINIT);
        udtRet = E_NOT_OK;
    }
    else
    {
        /*!Call LinIf_udtGetChannelIndexById to get the referenced channel 
            Index in the channels array */
        /*!If LinIf_udtGetChannelIndexById returns E_NOT_OK and the 
            DevErrorDetect is true, report to Det LINIF_E_TRCV_INV_CHANNEL */
        /*\Trace_To: LinIf-CDD-0213(0) */
        udtRet = LinIf_udtGetChannelIndexById(udtChannel, &u8ChannelIndex);

        if(E_NOT_OK == udtRet)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_GETTRCVMODE_ID,
                LINIF_E_TRCV_INV_CHANNEL);
        }
        /*!If bTrcvPresent in this channel is FALSE (There is no transceiver 
            driver connected to this channel) and the DevErrorDetect is true,
            report to Det LINIF_E_TRCV_INV_CHANNEL */
        else if(LinIf_akstreChannelsLT[u8ChannelIndex].bTrcvPresent == FALSE)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_GETTRCVMODE_ID,
                LINIF_E_TRCV_INV_CHANNEL);
            udtRet = E_NOT_OK;
        }
        /*!If the input pointer is NULL and DevErrorDetect is ON, report 
            LINIF_E_PARAMETER_POINTER to Det */
        /*\Trace_To: LinIf-CDD-0214(0) */
        else if(
            (P2VAR(LinTrcv_TrcvModeType, AUTOMATIC, LINIF_APPL_DATA))NULL_PTR
            == 
            penuTransceiverMode)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_GETTRCVMODE_ID,
                LINIF_E_PARAMETER_POINTER);
            udtRet = E_NOT_OK;
        }
        else
        {
#else
            (void)LinIf_udtGetChannelIndexById(udtChannel, &u8ChannelIndex);
#endif
            
            u8TrcvDriverIndex = 
                LinIf_akstreChannelsLT[u8ChannelIndex].u8TrcvDrvConfIndex;
            u8TrcvChannelId = 
                LinIf_akstreLinTrcvDrvConf[u8TrcvDriverIndex].
                u8TransceiverChannelId;
            
            /*!Call LinTrcv_GetOpMode with the input pointer. */
            /*\Trace_To: LinIf-CDD-0212(0) */
            udtRet = 
                LinIf_akstreLinTrcvDrvConf[u8TrcvDriverIndex].strTrcvRef.
                pfudtGetOpMode(u8TrcvChannelId, penuTransceiverMode);

#if LinIf_u8DEV_ERROR_DETECT == STD_ON
        }
    }
#endif
    return udtRet;
    /*\Trace_To: LinIf-CDD-0215(0) */
#else /*(LinIf_bMULTIPL_TRCV_SUPPORT != STD_ON)
        && (LinIf_u8NUMBER_OF_TRCVS == 0))*/
    
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(LINIF_MODULE_ID, 
        LINIF_INSTANCE_ID, 
        LinIf_u8LINIF_GETTRCVMODE_ID,
        LINIF_E_TRCV_INV_CHANNEL);
    
#endif
    return E_NOT_OK;
#endif
    
}
/******************************************************************************/
/*!Function    : LinIf_SetTrcvWakeupMode                                     */
/*!\Description This API enables, disables and clears the notification for 
                 wakeup events on the addressed network     \n
    \param[in]   Identification of the LIN channel. 
            \Range   0..LinIf_ku8eNumberOfChannels  \n
    \param[in]   Requested transceiver wake up reason. 
            \Range   LINIF_TRCV_WU_ENABLE, LINIF_TRCV_WU_DISABLE, 
                     LINIF_TRCV_WU_CLEAR  \n
    \return 
    E_OK: The call of the LIN Transceiver Driver's API 
    service 
    has returned E_OK. 
    E_NOT_OK: The call of the LIN Transceiver Driver's API
    service has returned E_NOT_OK.                                            */
/*\Trace_To    : LinIf-CDD-0224(0)                                           */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_SetTrcvWakeupMode(
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when LinIfMultipleTrcvDriverSupport is ON                      */
/* PRQA S 3206 ++                                                             */
    VAR(NetworkHandleType, AUTOMATIC) udtChannel,
/* PRQA S 3206 --                                                             */
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when LinIfMultipleTrcvDriverSupport is ON                      */
/* PRQA S 3206 ++                                                             */
    VAR(LinIf_TrcvWakeupModeType, AUTOMATIC) enuLinTrcvWakeupMode)
/* PRQA S 3206 --                                                             */
{
    /*!If the Pre-Compile configuration LinIf_bMULTIPL_TRCV_SUPPORT is not 
        STD_ON and DevErrorDetect is true, report to Det 
        LINIF_E_TRCV_INV_CHANNEL */
#if ((LinIf_bMULTIPL_TRCV_SUPPORT == STD_ON) && (LinIf_u8NUMBER_OF_TRCVS > 0U))

    VAR(uint8, AUTOMATIC)           u8ChannelIndex;
    VAR(uint8, AUTOMATIC)           u8TrcvDriverIndex;
    VAR(uint8, AUTOMATIC)           u8TrcvChannelId;
    VAR(Std_ReturnType, AUTOMATIC)  udtRet;

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true,
        report to Det LINIF_E_UNINIT */
    /*\Trace_To: LinIf-CDD-5030(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SETTRCVWUMD_ID,
                LINIF_E_UNINIT);
        udtRet = E_NOT_OK;
    }
    else
    {
        /*!Call LinIf_udtGetChannelIndexById to get the referenced channel
            Index in the channels array */
        /*!If LinIf_udtGetChannelIndexById returns E_NOT_OK and the 
            DevErrorDetect is true, report to Det LINIF_E_TRCV_INV_CHANNEL */
        /*\Trace_To: LinIf-CDD-0227(0) */
        udtRet = LinIf_udtGetChannelIndexById(udtChannel, &u8ChannelIndex);

        if(E_NOT_OK == udtRet)
        {
            /*\Trace_To: LinIf-CDD-0227(0) */
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SETTRCVWUMD_ID,
                LINIF_E_TRCV_INV_CHANNEL);
        }
        /*!If bTrcvPresent in this channel is FALSE (There is no transceiver 
            driver connected to this channel) and the DevErrorDetect is true,
            report to Det LINIF_E_TRCV_INV_CHANNEL */
        else if(LinIf_akstreChannelsLT[u8ChannelIndex].bTrcvPresent == FALSE)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SETTRCVWUMD_ID,
                LINIF_E_TRCV_INV_CHANNEL);
            udtRet = E_NOT_OK;
        }

        /*!If enuLinTrcvWakeupMode is invalid, report to Det 
            LINIF_E_PARAMETER */
        /*\Trace_To: LinIf-CDD-0228(0) */
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3356, 3359, 3201]: The condition appears  */
/*             always false because it checks for an invalid value, and for   */
/*             the same reason the statement is unreachable                   */
/* PRQA S 3356, 3359, 3201 ++                                                 */
        else if((enuLinTrcvWakeupMode != LINIF_TRCV_WU_ENABLE)
            &&
            (enuLinTrcvWakeupMode != LINIF_TRCV_WU_DISABLE)
            &&
            (enuLinTrcvWakeupMode != LINIF_TRCV_WU_CLEAR))
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SETTRCVWUMD_ID,
                LINIF_E_PARAMETER);
            udtRet = E_NOT_OK;
        }
/* PRQA S 3356, 3359, 3201 --                                                 */
        else
        {
#else
            (void)LinIf_udtGetChannelIndexById(udtChannel, &u8ChannelIndex);
#endif
            /*!Call LinTrcv_SetWakeupMode with the input values. */
            /*\Trace_To: LinIf-CDD-0225(0) */
            u8TrcvDriverIndex = 
                LinIf_akstreChannelsLT[u8ChannelIndex].u8TrcvDrvConfIndex;
            u8TrcvChannelId = 
                LinIf_akstreLinTrcvDrvConf[u8TrcvDriverIndex].
                u8TransceiverChannelId;

            udtRet = LinIf_akstreLinTrcvDrvConf[u8TrcvDriverIndex].strTrcvRef.
                pfudtSetWakeupMode(u8TrcvChannelId, enuLinTrcvWakeupMode);

#if LinIf_u8DEV_ERROR_DETECT == STD_ON
        }
    }
#endif
    return udtRet;
#else /*(LinIf_bMULTIPL_TRCV_SUPPORT != STD_ON)
        && (LinIf_u8NUMBER_OF_TRCVS == 0))*/
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*\Trace_To: LinIf-CDD-0229(0) */
    (void)Det_ReportError(LINIF_MODULE_ID, 
        LINIF_INSTANCE_ID, 
        LinIf_u8LINIF_SETTRCVWUMD_ID,
        LINIF_E_TRCV_INV_CHANNEL);
#endif
    return E_NOT_OK;
#endif
    
}
/******************************************************************************/
/*!Function    : LinIf_GetTrcvWakeupReason                                    */
/*!\Description    Returns the reason for the wake up that has been detecteted 
                    by the LIN Transceiver Driver.      \n
    \param[in]   Identification of the LIN channel. 
            \Range   0..LinIf_ku8eNumberOfChannels  \n
    \param[out]   Pointer to a memory location where output vale will be stored.
            \Range   NOT NULL  \n
    \return 
    E_OK    : The call of the LIN Transceiver Driver's API 
              service has returned E_OK. 
    E_NOT_OK: The call of the LIN Transceiver Driver's 
              API service has returned E_NOT_OK.                              */
/*\Trace_To    : LinIf-CDD-0217(0)                                            */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_GetTrcvWakeupReason(
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when LinIfMultipleTrcvDriverSupport is ON                      */
/* PRQA S 3206 ++                                                             */
    VAR(NetworkHandleType, AUTOMATIC) udtChannel,
/* PRQA S 3206 --                                                             */
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when LinIfMultipleTrcvDriverSupport is ON                      */
/* PRQA S 3206 ++                                                             */
    P2VAR(LinIf_TrcvWakeupReasonType, AUTOMATIC, LINIF_APPL_DATA) 
                                                            penuTrcvWuReasonPtr)
/* PRQA S 3206 --                                                             */
{
    /*!If the Pre-Compile configuration LinIf_bMULTIPL_TRCV_SUPPORT is not 
        STD_ON and DevErrorDetect is true, report to Det 
        LINIF_E_TRCV_INV_CHANNEL */
#if ((LinIf_bMULTIPL_TRCV_SUPPORT == STD_ON) && (LinIf_u8NUMBER_OF_TRCVS > 0U))

    VAR(uint8, AUTOMATIC)           u8ChannelIndex;
    VAR(uint8, AUTOMATIC)           u8TrcvDriverIndex;
    VAR(uint8, AUTOMATIC)           u8TrcvChannelId;
    VAR(Std_ReturnType, AUTOMATIC)  udtRet;

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)

    VAR(Std_ReturnType, AUTOMATIC)  udtTempRet;

    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true,
        report to Det LINIF_E_UNINIT */
    /*\Trace_To: LinIf-CDD-5028(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_GETTRCVWURS_ID,
                LINIF_E_UNINIT);
        udtRet = E_NOT_OK;
    }
    else
    {
        /*!Call LinIf_udtGetChannelIndexById to get the referenced channel 
            Index in the channels array */
        /*!If LinIf_udtGetChannelIndexById returns E_NOT_OK and the 
            DevErrorDetect is true, report to Det LINIF_E_TRCV_INV_CHANNEL */
        /*\Trace_To: LinIf-CDD-0219(0) */
        udtRet = LinIf_udtGetChannelIndexById(udtChannel, &u8ChannelIndex);

        if(E_NOT_OK == udtRet)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_GETTRCVWURS_ID,
                LINIF_E_TRCV_INV_CHANNEL);
        }
        /*!If bTrcvPresent in this channel is FALSE (There is no transceiver 
            driver connected to this channel) and the DevErrorDetect is true,
            report to Det LINIF_E_TRCV_INV_CHANNEL */
        else if(LinIf_akstreChannelsLT[u8ChannelIndex].bTrcvPresent == FALSE)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_GETTRCVWURS_ID,
                LINIF_E_TRCV_INV_CHANNEL);
            udtRet = E_NOT_OK;
        }
        /*!If the input pointer is NULL and DevErrorDetect is ON, report 
            LINIF_E_PARAMETER_POINTER to Det */
        /*\Trace_To: LinIf-CDD-0220(0) */
        else if(
            (P2VAR( LinIf_TrcvWakeupReasonType,
                    AUTOMATIC,
                    LINIF_APPL_DATA))NULL_PTR 
            == 
            penuTrcvWuReasonPtr)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_GETTRCVWURS_ID,
                LINIF_E_PARAMETER_POINTER);
            udtRet = E_NOT_OK;
        }
        else
        {
            VAR(LinTrcv_TrcvModeType, AUTOMATIC) enuCurrTrcvMode;
#else
            (void)LinIf_udtGetChannelIndexById(udtChannel, &u8ChannelIndex);
#endif

            u8TrcvDriverIndex = 
                LinIf_akstreChannelsLT[u8ChannelIndex].u8TrcvDrvConfIndex;
            u8TrcvChannelId = 
                LinIf_akstreLinTrcvDrvConf[u8TrcvDriverIndex].
                u8TransceiverChannelId;

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
            /*!Call LinTrcv_GetOpMode if the returned mode is not 
                LINTRCV_TRCV_MODE_STANDBY, and the DevErrorDetect is true,
                report to Det LINIF_E_TRCV_NOT_NORMAL */
            /*\Trace_To: LinIf-CDD-0221(0) */
            enuCurrTrcvMode = LINTRCV_TRCV_MODE_NORMAL;
            
            /* Ignore the return value of GetOpMode because if the 
               enuCurrTrcvMode is not changed Det is called and the function
               is stopped */
            udtTempRet = 
                LinIf_akstreLinTrcvDrvConf[u8TrcvDriverIndex].strTrcvRef.
                pfudtGetOpMode(u8TrcvChannelId, &enuCurrTrcvMode);
            
            if( (enuCurrTrcvMode != LINTRCV_TRCV_MODE_STANDBY)
                ||
                (udtTempRet != E_OK))
            {
                (void)Det_ReportError(LINIF_MODULE_ID, 
                    LINIF_INSTANCE_ID, 
                    LinIf_u8LINIF_GETTRCVWURS_ID,
                    LINIF_E_TRCV_NOT_NORMAL);
                udtRet = E_NOT_OK;
            }
            else
            {
#endif
                /*!Else Call LinTrcv_GetWakeupReason with the input pointer. */
                /*\Trace_To: LinIf-CDD-0218(0) */
                udtRet = 
                    LinIf_akstreLinTrcvDrvConf[u8TrcvDriverIndex].strTrcvRef.
                    pfudtGetBusWuReason(u8TrcvChannelId, penuTrcvWuReasonPtr);

#if LinIf_u8DEV_ERROR_DETECT == STD_ON
            }
        }
    }
#endif
    return udtRet;
#else /*(LinIf_bMULTIPL_TRCV_SUPPORT != STD_ON)
        && (LinIf_u8NUMBER_OF_TRCVS == 0))*/
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*\Trace_To: LinIf-CDD-0222(0) */
    (void)Det_ReportError(LINIF_MODULE_ID, 
        LINIF_INSTANCE_ID, 
        LinIf_u8LINIF_GETTRCVWURS_ID,
        LINIF_E_TRCV_INV_CHANNEL);
#endif
    return E_NOT_OK;
#endif
}

/******************************************************************************/
/*!Function    : LinIf_udtGetChannelIdByIndex                                */
/*!\Description    Returns Id of the input channel index that can be 
                    communicated to the upper layers      \n
    \param[in]   Index of the LIN channel in the channels array. 
            \Range   0..LinIf_ku8eNumberOfChannels  \n
    \return      The ChannelId communicated to the upper layer                */
/******************************************************************************/
FUNC(NetworkHandleType, LINIF_CODE) LinIf_udtGetChannelIdByIndex(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    /*!Return u8ComMChannelId in the channel link-time conf. */
    return LinIf_akstreChannelsLT[u8ChannelIndex].u8ComMChannelId;
}

/******************************************************************************/
/*!Function    : LinIf_udtGetChannelIndexById                                */
/*!\Description    Returns the index of the  of the channel whose Id is the  
                    input      \n
    \param[in]   Identification of the LIN channel. \n 
            \Range   0..LinIf_ku8eNumberOfChannels  \n
    \param[out]   Index of the Lin Channel in the channels array. \n 
            \Range   0..LinIf_ku8eNumberOfChannels  \n
    \return      
    E_OK: the channel is found and the index is returned 
    E_NOT_OK: the ChannelId is invalid                                        */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_udtGetChannelIndexById(
    VAR(NetworkHandleType, AUTOMATIC) u8ChannelId,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) pu8ChannelIndex)
{
    VAR(Std_ReturnType, AUTOMATIC)  udtRet;
    /*! Set return to E_NOT_OK */
    udtRet = E_NOT_OK;
    
        #if (LinIf_u16INDICATED_COUNT != 0)
        /* Idea here is that the Map is only necessary if the configured channel
           ports are not continuous, however, the check that the passed
           parameter "u8ChannelId" still has to be checked that it's less than or
           equal the largest configured channel Id, but that check is not
           necessary if the full range, i.e. 256, is configured.  */
        #if (LinIf_bCONT_PORTS == FALSE)
        #if (LinIf_u8MAX_PORT != 255)
        if (u8ChannelId <= LinIf_u8MAX_PORT)
        {
        #endif /* LinIf_u8MAX_PORT */
            #if (LinIf_u8NET_OFFSET == 0)
            *pu8ChannelIndex = LinIf_aku8eChannelIndexById[u8ChannelId];
            /*! Set return to E_OK */
            udtRet = E_OK;
            #else   /* LinIf_u8NET_OFFSET */
            if (u8ChannelId >= LinIf_u8NET_OFFSET)
            {
                *pu8ChannelIndex =
                       LinIf_aku8eChannelIndexById[u8ChannelId - LinIf_u8NET_OFFSET];
            #endif  /* LinIf_u8NET_OFFSET */
                /* Deviation [2215]: indentation is correct if the #if is false
                   and the #else block is active.
                */
                /* PRQA S 2215 ++*/
                if (*pu8ChannelIndex != LinIf_u8UNUSED)
                {
                   /*! Set return to E_OK */
                   udtRet = E_OK;
                }
                /* PRQA S 2215 --*/
            #if (LinIf_u8NET_OFFSET != 0)
            }
            #endif  /* LinIf_u8NET_OFFSET */
        #if (LinIf_u8MAX_PORT != 255)
        }
        #endif /* LinIf_u8MAX_PORT */
        #else  /* LinIf_bCONT_PORTS */
        /* Here Ports are continuous, thus lookup is not necessary, but an
           offset may need to be subtracted first */
        #if (LinIf_u8MAX_PORT != 255)
        if (u8ChannelId <= LinIf_u8MAX_PORT)
        {
        #endif /* LinIf_u8MAX_PORT */
            #if (LinIf_u8NET_OFFSET == 0)
            *pu8ChannelIndex = u8ChannelId;
            /*! Set return to E_OK */
            udtRet = E_OK;
            #else  /* LinIf_u8NET_OFFSET */
            if (u8ChannelId >= LinIf_u8NET_OFFSET)
            {
               *pu8ChannelIndex = u8ChannelId - LinIf_u8NET_OFFSET;
               /*! Set return to E_OK */
               udtRet = E_OK;
            }
            #endif /* LinIf_u8NET_OFFSET */
        #if (LinIf_u8MAX_PORT != 255)
        }
        #endif /* LinIf_u8MAX_PORT */
        #endif /* LinIf_bCONT_PORTS */
        #endif /* LinIf_u16INDICATED_COUNT */
    return udtRet;
}

/*!Deviation : Inhibit MISRA rule [3206]: WakeupSource argument is not used yet 
                 because function is not yet implemented                      */
/* PRQA S 3206 ++                                                             */

/********************************************************************************/
/*!Function    : LinIf_WakeupConfirmation                                       */
/*!\Description  The LIN Driver or LIN Transceiver Driver will call this 
                 function to report the wake up source after the successful 
                 wakeup detection during CheckWakeup or after power on by bus.
                 This function is release 4.1.2 specific and not implemented yet.
    \param[in]   Source device which initiated the wakeup event: 
                 LIN controller or LIN transceiver                              */
/*\Trace_To    : LinIf-CDD-0503(0)                                              */
/********************************************************************************/
FUNC(void, LINIF_CODE) LinIf_WakeupConfirmation(
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{

}

/* PRQA S 3206 --                                                             */
#define LINIF_STOP_SEC_CODE
#include "Memmap.h"


/*-------------------------------- end of file -------------------------------*/
/* PRQA L:L1                                                                  */
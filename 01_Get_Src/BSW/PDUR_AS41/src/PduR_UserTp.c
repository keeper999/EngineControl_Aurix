/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !File            : PduR_UserTp.c                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VALEO                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/02_PduR/02$*/
/* $Revision::   1.59     $$Author::   sedrees        $$Date::   Aug 24 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/* Includes                                                                   */
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

#include "Std_Types.h"
#include "PduR_Types.h"
#include "PduR_LocalTypes.h"

#include "PduR.h"
#include "PduR_UserTp.h"

#include "SchM_PduR.h"

#include "PduR_Cfg.h"

#if (PduR_bZERO_COST_OPERATION == STD_OFF)

#if(PduR_bTPLO_ENABLED == STD_ON)

#include "PduR_LocalCfg.h"

#if(PduR_bDEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Direct gatewaying value stored in configuration tables \n
    \Range          0x00
*******************************************************************************/
#define         u8DIRECT_GW_VALUE       0x00

/******************************************************************************/
/*! \Description    Zero based gatewaying copying from local buffers. Used to
                    manage successive requests that are all zero based \n
    \Range          0x00
*******************************************************************************/
#define         u8ZEROBASE_GW_COPY      0x00

/******************************************************************************/
/*! \Description    Normal gatewaying copying from local buffers. Used to manage
                    successive requests that copies data from last index \n
    \Range          0x01
*******************************************************************************/
#define         u8NORMAL_GW_COPY        0x01


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/* !Deviation : Inhibit MISRA rule: Implemented as a macro for readability    */
/* PRQA S 3453 ++                                                             */

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         TP Tx confirmation function pointers entries for u8Id \n
*******************************************************************************/
#define         pkstrTP_UP_TBL(u8Id)                                           \
                (&(PduR_pkstrePbCfg->pkstrTp2UpTxFuncTable[u8Id]))

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         TP Tx function pointers entries for u8Id \n
*******************************************************************************/
#define         pkstrTP_TX_TBL(u8Id)                                           \
                (&(PduR_pkstrePbCfg->pkstrTpTxFuncTable[u8Id]))

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         TP gatewaying entry identified by u8Id \n
*******************************************************************************/
#define         astrGATE_TP_TBL(u8Id)                                          \
                (PduR_pkstrePbCfg->pkstrGateTpRTable[u8Id])

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         TP sub information for the specified control Id \n
*******************************************************************************/
#define         astrGATE_TP_SUBTBL(u8CntrlId)                                  \
                (PduR_pkstrePbCfg->pkstrGateTpSubRT[u8CntrlId])

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         TP gatewaying control entry identified by u8Id \n
*******************************************************************************/
#define         astrGATE_TP_CTRL(u8Id)                                         \
                (PduR_pkstrePbCfg->pstrGateTpCntrl[u8Id])

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         Pointer to location of gatewaying buffer for u16BuffId \n
*******************************************************************************/
#define         pstrGATE_TP_BUF(u16BuffId)                                     \
                (PduR_akstreTpBuffers[u16BuffId].pu8BuffData)

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         TP multicasting entry identified by u8Id \n
*******************************************************************************/
#define         astrMULTI_TP_TBL(u8Id)                                         \
                (PduR_pkstrePbCfg->pkstrMultiTpRTable[u8Id])

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         TP multicasting sub-table entry identified by u8Id \n
*******************************************************************************/
#define         astrMULTI_TP_SUB_TBL(u8Id)                                     \
                (PduR_pkstrePbCfg->pkstrMultiTpSubRT[u8Id])

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         TP multicasting control entry identified by u8Id \n
*******************************************************************************/
#define         astrMULTI_TP_CTRL(u8Id)                                        \
                (PduR_pkstrePbCfg->pstrMultiTpCntrl[u8Id])

/* PRQA S 3453 --                                                             */


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/



/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

#define PDUR_START_SEC_CODE
#include "Memmap.h"

#if(PduR_bGATEWAYING_TP == STD_ON)

static FUNC(BufReq_ReturnType, PDUR_CODE) enuGetNewTpBuffer(
    VAR(PduLengthType, AUTOMATIC)                               udtMsgLen,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC)                         pu16BuffId);

static FUNC(void, PDUR_CODE) vidReserveTpBuffer(
    VAR(PduIdType, AUTOMATIC)                                   udtPduId,
    VAR(PduLengthType, AUTOMATIC)                               udtMsgLen,
    VAR(uint16, AUTOMATIC)                                      u16BuffId
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    , VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)                 u16RouteGrp
    #endif
    );

static FUNC(BufReq_ReturnType, PDUR_CODE) enuTpBufferAdd(
    VAR(uint16, AUTOMATIC)                                      u16BuffId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)             pkstrPduInfo
    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
    , VAR(uint8, AUTOMATIC)                                       u8ApiId
    #endif
    );

static FUNC(BufReq_ReturnType, PDUR_CODE) enuTpBufferRemove(
    VAR(uint16, AUTOMATIC)                                      u16BuffId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)               pstrPduInfo,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA)           pkstrRetry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)             pudtAvData,
    VAR(uint8, AUTOMATIC)                                       u8CopyType);

static FUNC(void, PDUR_CODE) vidHndlGtFlyCopyRxData(
    VAR(PduIdType, AUTOMATIC)                                   udtPduId);

#endif

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

#if(PduR_bGATEWAYING_TP == STD_ON)
/******************************************************************************/
/*! \Description    Local function to search for an available TP buffer \n
    \return         BUFREQ_OK, BUFREQ_E_BUSY, BUFREQ_E_OVFL \n
*******************************************************************************/
static FUNC(BufReq_ReturnType, PDUR_CODE) enuGetNewTpBuffer(
    VAR(PduLengthType, AUTOMATIC)                               udtMsgLen,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC)                         pu16BuffId)
{
    VAR(BufReq_ReturnType, AUTOMATIC)                           enuFuncRet;
    VAR(uint16_least, AUTOMATIC)                                u16LoopIdx;

    /*! Reset the local loop index counter                                    */
    u16LoopIdx  = 0;

    /*! Loop on all Tp buffers and check if a buffer is available or not      */
    while(u16LoopIdx < (uint16) PduR_u16MAX_TP_BUFFER_NUMBER)
    {
        /*! Check if there is a buffer of requested length                    */
        if(udtMsgLen <= PduR_akstreTpBuffers[u16LoopIdx].u16BuffLength)
        {
            /*! Check if the found buffer is free or not                      */
            if(PduR_astreTpBuffCtrl[u16LoopIdx].bIsFree == TRUE)
            {
                /*! Found a free buffer, return successfully                  */
                enuFuncRet      = BUFREQ_OK;
                (*pu16BuffId)   = u16LoopIdx;

                /*! Terminate the loop operation                              */
                u16LoopIdx      = PduR_u16MAX_TP_BUFFER_NUMBER;
            }
            else
            {
                /*! There is a buffer present with the required length, but its
                    currently in use. Set return to BUFREQ_E_BUSY             */
                enuFuncRet      = BUFREQ_E_BUSY;
            }
        }
        else
        {
            /*! Requested length did not match any of the buffers configured,
                set return to overflow as no matching size                    */
            enuFuncRet          = BUFREQ_E_OVFL;
        }

        /*! Increment loop index                                              */
        u16LoopIdx++;
    }

    return enuFuncRet;
}

/******************************************************************************/
/*! \Description    Reserves the TP buffer by setting the buffer as busy and
                    resetting the remaining buffer control information \n
    \return         void \n
*******************************************************************************/
static FUNC(void, PDUR_CODE) vidReserveTpBuffer(
    VAR(PduIdType, AUTOMATIC)                                   udtPduId,
    VAR(PduLengthType, AUTOMATIC)                               udtMsgLen,
    VAR(uint16, AUTOMATIC)                                      u16BuffId
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    , VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)                 u16RouteGrp
    #endif
    )
{
    VAR(PduIdType, AUTOMATIC)                                   udtCtrlId;

    /*! Set the buffer as busy - no protection needed, atomic instruction     */
    PduR_astreTpBuffCtrl[u16BuffId].bIsFree = FALSE;

    /*! Set/Reset the GateTpId to the ID passed in function                   */
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    PduR_astreTpBuffCtrl[u16BuffId].u16RPathGrpId = u16RouteGrp;
    #endif

    /*! Reset the Tp buffer control information                               */
    /*! No need for protection as setting/resetting these parameters is always
        done after checking if the buffer is free or not                      */
    PduR_astreTpBuffCtrl[u16BuffId].udtMsgLen       = udtMsgLen;

    PduR_astreTpBuffCtrl[u16BuffId].udtTxIdx        = 0;
    PduR_astreTpBuffCtrl[u16BuffId].udtTxAvBytes    = 0;

    PduR_astreTpBuffCtrl[u16BuffId].udtRxIdx        = 0;
    PduR_astreTpBuffCtrl[u16BuffId].udtRxAvBytes    = 
                                PduR_akstreTpBuffers[u16BuffId].u16BuffLength;

    /*! Reserve the buffer in the local array & reset the counter             */
    udtCtrlId = astrGATE_TP_TBL(udtPduId).udtCntrlId;
    astrGATE_TP_CTRL(udtCtrlId).u16BuffIdx  = u16BuffId;
    astrGATE_TP_CTRL(udtCtrlId).u8CntrValue = 0;
    astrGATE_TP_CTRL(udtCtrlId).bTxDone     = FALSE;
}

/******************************************************************************/
/*! \Description    Local function to copy received data in the TP buffers \n
    \return         BUFREQ_OK, BUFREQ_E_NOT_OK, BUFREQ_E_BUSY \n
    \Trace_To       PduR-CDD-5393(0)
*******************************************************************************/
static FUNC(BufReq_ReturnType, PDUR_CODE) enuTpBufferAdd(
    VAR(uint16, AUTOMATIC)                                      u16BuffId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)             pkstrPduInfo
    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
    , VAR(uint8, AUTOMATIC)                                       u8ApiId
    #endif
    )
{
    VAR(BufReq_ReturnType, AUTOMATIC)                           enuFuncRet;
    VAR(uint16, AUTOMATIC)                                      u16RxStart;
    VAR(uint16, AUTOMATIC)                                      u16CopyIdx;
    VAR(PduLengthType, AUTOMATIC)                               udtLoopIdx;
    VAR(PduLengthType, AUTOMATIC)                               udtSduLen;

    /*! Copy the length of the SDU to a local variable for faster execution   */
    udtSduLen = pkstrPduInfo->SduLength;

    /*! Check that the reserved buffer is BUSY (already reserved)             */
    if(PduR_astreTpBuffCtrl[u16BuffId].bIsFree == FALSE)
    {
        /*! Check that the data length to be copied can fit in the buffer     */
        if(udtSduLen <= PduR_astreTpBuffCtrl[u16BuffId].udtRxAvBytes)
        {
            /*! Protection needed againest data consistency                   */
            /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is          */
            /*              to be implemented during integration phase        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Enter_PduR(PduR_TP_BUFF_CTRL_COPYRX);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Update Tx bytes to copy and Rx remaining bytes                */
            PduR_astreTpBuffCtrl[u16BuffId].udtRxAvBytes = 
                                PduR_astreTpBuffCtrl[u16BuffId].udtRxAvBytes 
                                - udtSduLen;

            PduR_astreTpBuffCtrl[u16BuffId].udtTxAvBytes =
                                PduR_astreTpBuffCtrl[u16BuffId].udtTxAvBytes 
                                + udtSduLen;

            u16RxStart = PduR_astreTpBuffCtrl[u16BuffId].udtRxIdx;

            /*! Clear critical section                                        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_TP_BUFF_CTRL_COPYRX);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Copy the Rx Data to the Tp buffer associated                  */
            for(udtLoopIdx = 0; udtLoopIdx < udtSduLen; udtLoopIdx++)
            {
                u16CopyIdx = (uint16) ((udtLoopIdx + u16RxStart) 
                            % PduR_akstreTpBuffers[u16BuffId].u16BuffLength);

                PduR_akstreTpBuffers[u16BuffId].pu8BuffData[u16CopyIdx] 
                                        = pkstrPduInfo->SduDataPtr[udtLoopIdx];
            }

            /*! Protection needed againest data consistency                   */
            /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is          */
            /*              to be implemented during integration phase        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Enter_PduR(PduR_TP_BUFF_CTRL_COPYRX);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Update Rx index to start copying to next time                 */
            PduR_astreTpBuffCtrl[u16BuffId].udtRxIdx = ((u16RxStart + udtSduLen)
                            % PduR_akstreTpBuffers[u16BuffId].u16BuffLength);

            /*! Clear critical section                                        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_TP_BUFF_CTRL_COPYRX);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! If DET enabled, check that the requested bytes to copy shall
                not exceed the length of the original message                 */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            if(PduR_astreTpBuffCtrl[u16BuffId].udtTxAvBytes >
                                PduR_astreTpBuffCtrl[u16BuffId].udtMsgLen)
            {
                (void) Det_ReportError( PDUR_MODULE_ID,
                                        0,
                                        u8ApiId,
                                        PDUR_E_TP_TX_GW_LENGTH);
            }
            #endif

            /*! Set enuFuncRet as BUFREQ_OK                                   */
            enuFuncRet = BUFREQ_OK;
        }
        else
        {
            /*! No enough place for data to be copied to buffer               */
            /*! Set enuFuncRet as BUFREQ_E_BUSY                               */
            enuFuncRet = BUFREQ_E_BUSY;
        }
    }
    else
    {
        /*! Error occured, buffer can't be accessed. Return E_NOT_OK          */
        enuFuncRet  = BUFREQ_E_NOT_OK;
    }

    return enuFuncRet;
}

/* !Deviation : Inhibit MISRA rule: STCYC (Cyclomatic Complexity) is needed   */
/*              to fullfill the needed functionality of the API.              */
/*              No further simplification is needed.                          */
/* PRQA S 4700 ++                                                             */

/******************************************************************************/
/*! \Description    Local function to copy received data in the TP buffers \n
    \return         BUFREQ_OK, BUFREQ_E_NOT_OK, BUFREQ_E_BUSY \n
    \Trace_To       PduR-CDD-5088(2), PduR-CDD-5092(0)
*******************************************************************************/
static FUNC(BufReq_ReturnType, PDUR_CODE) enuTpBufferRemove(
    VAR(uint16, AUTOMATIC)                                      u16BuffId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)               pstrPduInfo,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA)           pkstrRetry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)             pudtAvData,
    VAR(uint8, AUTOMATIC)                                       u8CopyType)
{
    VAR(BufReq_ReturnType, AUTOMATIC)                           enuFuncRet;
    VAR(uint16_least, AUTOMATIC)                                u16LoopIdx;
    VAR(uint16, AUTOMATIC)                                      u16CopyStart;
    VAR(uint16, AUTOMATIC)                                      u16CopyLen;
    VAR(uint16, AUTOMATIC)                                      u16CopyIdx;
    VAR(uint16, AUTOMATIC)                                      u16AvTxBytes;
    VAR(uint16, AUTOMATIC)                                      u16AvTxBytesOld;
    VAR(uint16, AUTOMATIC)                                      u16AvRxBytes;
    VAR(uint16, AUTOMATIC)                                      u16AvRxBytesOld;

    /*! Check that the reserved buffer is BUSY (already reserved)             */
    if(PduR_astreTpBuffCtrl[u16BuffId].bIsFree == FALSE)
    {
        /*! Set the local variables holding the Tx/Rx available bytes info    */
        u16AvTxBytes    = PduR_astreTpBuffCtrl[u16BuffId].udtTxAvBytes;
        u16AvRxBytes    = PduR_astreTpBuffCtrl[u16BuffId].udtRxAvBytes;

        u16AvTxBytesOld = u16AvTxBytes;
        u16AvRxBytesOld = u16AvRxBytes;

        /*! Set the copying length to the passed length                       */
        u16CopyLen = pstrPduInfo->SduLength;

        /*! Check that there are available bytes to be copied from buffer     */
        /*! \Trace_To    PduR-CDD-5257(0)                                     */
        if  (   (u16CopyLen > u16AvTxBytes) 
                && (pkstrRetry->TpDataState == TP_NORETRY)
            )
        {
            /*! Return BUFREQ_E_BUSY as no available data to be copied        */
            enuFuncRet  = BUFREQ_E_BUSY;
        }
        else if (   (u16CopyLen > (PduR_astreTpBuffCtrl[u16BuffId].udtMsgLen
                                                    - pkstrRetry->TxTpDataCnt))
                    && (pkstrRetry->TpDataState == TP_DATARETRY)
                )
        {
            /*! Return BUFREQ_E_BUSY as no available data to be copied        */
            enuFuncRet  = BUFREQ_E_BUSY;
        }
        else
        {
            /*! Data is available to be copied. 3 copying types available     */
            /*! \Trace_To    PduR-CDD-0081(0)                                 */
            if(pkstrRetry->TpDataState == TP_DATARETRY)  /* RETRY             */
            {
                /*! This case is available only in DIRECT gatewaying so Rx
                    operation is over. Accordingly, no need for protection    */

                /*! Copying shall start from the passed index in request      */
                u16CopyStart = pkstrRetry->TxTpDataCnt;

                /*! Temporarly update # of available Tx bytes to use it       */
                u16AvTxBytes =  PduR_astreTpBuffCtrl[u16BuffId].udtMsgLen;

                /*! Now check the passed length against the full available Tx
                    data bytes (currently present and old data). Old data shall
                    still be present as this is DIRECT gatewaying             */
                if(pstrPduInfo->SduLength < u16AvTxBytes)
                {
                    u16CopyLen = pstrPduInfo->SduLength;
                }
                else
                {
                    u16CopyLen              = u16AvTxBytes;
                    pstrPduInfo->SduLength  = u16AvTxBytes;
                }

                /*! Temporarly set back the available Tx bytes to the actual
                    available length - the data count                         */
                u16AvTxBytes = u16AvTxBytes - pkstrRetry->TxTpDataCnt;
            }
            else if(u8CopyType == u8ZEROBASE_GW_COPY)   /* Copy from Idx=0    */
            {
                /*! Check the passed length against actual available bytes    */
                if(pstrPduInfo->SduLength < u16AvTxBytes)
                {
                    u16CopyLen = pstrPduInfo->SduLength;
                }
                else
                {
                    u16CopyLen              = u16AvTxBytes;
                    pstrPduInfo->SduLength  = u16AvTxBytes;
                }

                /*! Copying shall start from 0 - SF/MD copying                */
                u16CopyStart = 0;
            }
            else                                        /* Normal Copy        */
            {
                /*! Check the passed length against actual available bytes    */
                if(pstrPduInfo->SduLength < u16AvTxBytes)
                {
                    u16CopyLen = pstrPduInfo->SduLength;
                }
                else
                {
                    u16CopyLen              = u16AvTxBytes;
                    pstrPduInfo->SduLength  = u16AvTxBytes;
                }

                /*! Copying shall start from from the last index value        */
                u16CopyStart    = PduR_astreTpBuffCtrl[u16BuffId].udtTxIdx;
            }

            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            /*! Protection against copying from outside the buffer            */
            if(u16CopyStart < PduR_astreTpBuffCtrl[u16BuffId].udtMsgLen)
            {
            #endif
                
                /*! Protection needed againest data consistency               */
                /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is      */
                /*              to be implemented during integration phase    */
                /* PRQA S 3141 ++                                             */
                /* PRQA S 3138 ++                                             */
                SchM_Enter_PduR(PduR_TP_BUFF_CTRL_COPYTX);
                /* PRQA S 3141 --                                             */
                /* PRQA S 3138 --                                             */

                /*! Normal copying operation - update Tx bytes to copy and Rx
                    bytes remaining then set their values in the Cntrl data   */
                /*! \Trace_To    PduR-CDD-5089(0), PduR-CDD-5093(0)           */
                /*! \Trace_To    PduR-CDD-5094(0), PduR-CDD-5095(0)           */
                u16AvTxBytes    = u16AvTxBytes - u16CopyLen;
                u16AvRxBytes    = u16AvRxBytes + u16CopyLen;

                PduR_astreTpBuffCtrl[u16BuffId].udtTxAvBytes = u16AvTxBytes;
                PduR_astreTpBuffCtrl[u16BuffId].udtRxAvBytes = u16AvRxBytes;

                /*! Clear critical section                                    */
                /* PRQA S 3141 ++                                             */
                /* PRQA S 3138 ++                                             */
                SchM_Exit_PduR(PduR_TP_BUFF_CTRL_COPYTX);
                /* PRQA S 3141 --                                             */
                /* PRQA S 3138 --                                             */

                /*! Start copying the data to the buffer as requested         */
                for(u16LoopIdx = 0; u16LoopIdx < u16CopyLen; u16LoopIdx++)
                {
                    u16CopyIdx = (uint16) ((u16LoopIdx + u16CopyStart) 
                            % PduR_akstreTpBuffers[u16BuffId].u16BuffLength);

                    pstrPduInfo->SduDataPtr[u16LoopIdx] =
                                pstrGATE_TP_BUF(u16BuffId)[u16CopyIdx];
                }

                /*! Set the remaining available Tx bytes as specified above   */
                (*pudtAvData) = u16AvTxBytes;

                /*! Protection needed againest data consistency               */
                /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is      */
                /*              to be implemented during integration phase    */
                /* PRQA S 3141 ++                                             */
                /* PRQA S 3138 ++                                             */
                SchM_Enter_PduR(PduR_TP_BUFF_CTRL_COPYTX);
                /* PRQA S 3141 --                                             */
                /* PRQA S 3138 --                                             */

                if(u8CopyType == u8NORMAL_GW_COPY) /*! Copy from normal TxIdx */
                {
                    /*! Update Tx index to start copying to next time         */
                    PduR_astreTpBuffCtrl[u16BuffId].udtTxIdx = 
                                ((u16CopyStart + u16CopyLen) %
                                PduR_akstreTpBuffers[u16BuffId].u16BuffLength);
                }
                else /* Copy from Idx 0 OR RETRY cases                        */
                {
                    /*! Return available bytes of Tx/Rx back to old values    */
                    PduR_astreTpBuffCtrl[u16BuffId].udtTxAvBytes =
                                                                u16AvTxBytesOld;
                    PduR_astreTpBuffCtrl[u16BuffId].udtRxAvBytes =
                                                                u16AvRxBytesOld;
                }

                /*! Clear critical section                                    */
                /* PRQA S 3141 ++                                             */
                /* PRQA S 3138 ++                                             */
                SchM_Exit_PduR(PduR_TP_BUFF_CTRL_COPYTX);                    
                /* PRQA S 3141 --                                             */
                /* PRQA S 3138 --                                             */

                /*! Return BUFREQ_OK as data has been copied                  */
                enuFuncRet  = BUFREQ_OK;                            
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            }
            else
            {
                /*! Return BUFREQ_E_NOT_OK as copying shall be out of range   */
                enuFuncRet  = BUFREQ_E_NOT_OK;
            }
            #endif
        }
    }
    else
    {
        /*! Return BUFREQ_E_NOT_OK as buffer cannot be accessed               */
        enuFuncRet  = BUFREQ_E_NOT_OK;
    }

    return enuFuncRet;
}
/* PRQA S 4700 --                                                             */

/******************************************************************************/
/*! \Description    Handles TP gatewaying operation in case of a CopyRxData
                    call is invoked that targets an on-the-fly transmission \n
    \return         void \n
*******************************************************************************/
static FUNC(void, PDUR_CODE) vidHndlGtFlyCopyRxData(
    VAR(PduIdType, AUTOMATIC)                       udtPduId)
{
    VAR(uint16, AUTOMATIC)                          u16GlblPdu;
    VAR(uint16, AUTOMATIC)                          u16TpBuffId;
    VAR(uint16, AUTOMATIC)                          u16BuffId;
    VAR(PduIdType, AUTOMATIC)                       udtCtrlId;
    VAR(PduIdType, AUTOMATIC)                       udtTargetId;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RouteGrp;
    #endif

    VAR(uint8, AUTOMATIC)                           u8DevIdx;
    VAR(Std_ReturnType, AUTOMATIC)                  u8TxFnRet;
    VAR(PduInfoType, AUTOMATIC)                     strPduInfo;

    P2CONST(PduR_tstrTpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                    pkstrTpTxFp;

    #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
    VAR(boolean, AUTOMATIC)                         bGWStatus;
    #endif

    /*! Grab the control index and the associated Tp buffer index             */
    udtCtrlId   = astrGATE_TP_TBL(udtPduId).udtCntrlId;
    u16TpBuffId = astrGATE_TP_CTRL(udtCtrlId).u16BuffIdx;

    /*! Check if Tp threshold is reached or not to start the Tx process       */
    /*! \Trace_To   PduR-CDD-0083(0)                                          */
    if(astrGATE_TP_TBL(udtPduId).u8BuffThreshold <= 
                        PduR_astreTpBuffCtrl[u16TpBuffId].udtTxAvBytes)
    {
        /*! Prepare the transmission data                                     */
        strPduInfo.SduLength    = 
                            PduR_astreTpBuffCtrl[u16TpBuffId].udtMsgLen;
        strPduInfo.SduDataPtr   = 
                            PduR_akstreTpBuffers[u16TpBuffId].pu8BuffData;

        /*! No need to loop on all destinations as it's only one destination
            Prepare the data for this destination accordingly                 */

        /*! Prepare destination, routing group & global ids                   */
        udtTargetId = astrGATE_TP_TBL(udtPduId).udtDstPduRefId;
        u16GlblPdu  = astrGATE_TP_TBL(udtPduId).u16IPduGlobalId;

        /*! Prepare the transmit function pointer                             */
        u8DevIdx    = astrGATE_TP_TBL(udtPduId).u8DstPduDeviceId;
        pkstrTpTxFp = pkstrTP_TX_TBL(u8DevIdx);

        /*! Check routing group to see if Tx can take place                   */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp = astrGATE_TP_TBL(udtPduId).u16RPathGrpId;
        if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
        #endif
        {
            /*! Set global PDU state to INPROGRESS                            */
            PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8INPROGRESS;

            /*! Increment the corresponding counter                           */
            astrGATE_TP_CTRL(udtCtrlId).u8CntrValue++;

            #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
            /*! If call-outs are supported, perform the call-out check before
                calling the destination's transmit API                        */
            /*! \Trace_To   PduR-CDD-5403(0)                                  */
            if( astrGATE_TP_TBL(udtPduId).pfbGateCallOut !=
                                            (PduR_tpfbGateCallOut) NULL_PTR )
            {
                bGWStatus = astrGATE_TP_TBL(udtPduId).pfbGateCallOut(
                                udtTargetId, (const PduInfoType*) &strPduInfo);
            }
            else
            {
                bGWStatus = TRUE;
            }

            /*! If call-out returned TRUE, proceed with transmission          */
            /*! \Trace_To   PduR-CDD-5404(0)                                  */
            if(bGWStatus == TRUE)
            #endif
            {
                u8TxFnRet = pkstrTpTxFp->pfu8TpTransmit(
                                                    udtTargetId, &strPduInfo);

                if(u8TxFnRet != E_OK)
                {
                    /*! Set global PDU state to IDLE                          */
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                    /*! Get the previously reserved buffer & free it          */
                    u16BuffId   = astrGATE_TP_CTRL(udtCtrlId).u16BuffIdx;
                    PduR_astreTpBuffCtrl[u16BuffId].bIsFree = TRUE;

                    /*! Decrement the corresponding counter                   */
                    astrGATE_TP_CTRL(udtCtrlId).u8CntrValue--;

                    /*! If DET enabled, report that request was rejected      */
                    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
                    (void) Det_ReportError( PDUR_MODULE_ID,
                                            0,
                                            astrGATE_TP_SUBTBL(udtCtrlId)
                                                                .u8CopyRxDApiId,
                                            PDUR_E_TP_TX_REQ_REJECTED);
                    #endif
                }
            }
            #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
            /*! If call-out returned FALSE, terminate the transmission        */
            else
            {
                /*! Set global PDU state to IDLE                              */
                PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                /*! Get the previously reserved buffer & free it              */
                u16BuffId   = astrGATE_TP_CTRL(udtCtrlId).u16BuffIdx;
                PduR_astreTpBuffCtrl[u16BuffId].bIsFree = TRUE;

                /*! Decrement the corresponding counter                       */
                astrGATE_TP_CTRL(udtCtrlId).u8CntrValue--;
            }
            #endif

            /*! Set the transmission done to TRUE                             */
            astrGATE_TP_CTRL(udtCtrlId).bTxDone = TRUE;
        }
    }
}
#endif

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/********************/
/* Helper Functions */
/********************/

/******************************************************************************/
/*! \Description    Function used to perform DET related checks (INVALID_REQ and
                    INVALID_ID) and returns with OK/NOK based on the result \n
    \return         E_OK, E_NOT_OK \n
    \Trace_To       PduR-CDD-5156(0), PduR-CDD-5315(0), PduR-CDD-5114(0)
    \Trace_To       PduR-CDD-5155(0), PduR-CDD-5314(0), PduR-CDD-5176(0)
    \Trace_To       PduR-CDD-5283(0), PduR-CDD-5174(0)
*******************************************************************************/
FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8TpRxStatusChecker(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    P2VAR(PduR_tu8RoutingType, AUTOMATIC, AUTOMATIC)            pu8RtngType,
    P2CONST(PduR_tstrTpRxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf)
{
    VAR(PduR_ReturnType, AUTOMATIC)                             u8FuncRet;

    /*! Check module's initialization                                         */
    if(PduR_u8eState == PDUR_UNINIT)
    {
        /*! Report to DET if enabled                                          */
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError( PDUR_MODULE_ID,
                                0,
                                pkstrTblsRf->u8APIId,
                                PDUR_E_INVALID_REQUEST);
        #endif

        (*pu8RtngType)  = PduR_u8INVALID_ROUTING;
        u8FuncRet       = E_NOT_OK;
    }
    /*! Determine the routing type and report to DET if needed accordingly    */
    else
    {
        /*! Check id is in specified range of minimum routing tables          */
        if(udtId < pkstrTblsRf->u16MinRxTSize)
        {
            (*pu8RtngType)  = PduR_u8MINIMUM_ROUTING;
            u8FuncRet       = E_OK;
        }
        /*! Check id is in specified range of normal routing tables           */
        else if(    (PduR_u8eState == PDUR_ONLINE) && 
                    (udtId < (pkstrTblsRf->u16NrmRxTSize 
                            + pkstrTblsRf->u16MinRxTSize)))
        {
            (*pu8RtngType)  = PduR_u8NORMAL_ROUTING;
            u8FuncRet       = E_OK;
        }
        /*! id is in out of range                                             */
        else
        {
            (*pu8RtngType)  = PduR_u8INVALID_ROUTING;

            /*! Set the return type to NOT_OK                                 */
            u8FuncRet       = E_NOT_OK;
        }

        if((*pu8RtngType) == PduR_u8INVALID_ROUTING)
        {
            /*! Report to DET if enabled, Id is not in the valid range        */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    pkstrTblsRf->u8APIId,
                                    PDUR_E_PDU_ID_INVALID);
            #endif
        }
    }

    return u8FuncRet;
}

/******************************************************************************/
/*! \Description    Function used to perform DET related checks (INVALID_REQ and
                    INVALID_ID) and returns with OK/NOK based on the result \n
    \return         E_OK, E_NOT_OK \n
    \Trace_To       PduR-CDD-5154(0), PduR-CDD-5313(0), PduR-CDD-5113(0)
    \Trace_To       PduR-CDD-5153(0), PduR-CDD-5312(0), PduR-CDD-5175(0)
    \Trace_To       PduR-CDD-5152(0), PduR-CDD-5311(0), PduR-CDD-5321(0)
*******************************************************************************/
FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8TpTxStatusChecker(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    P2VAR(PduR_tu8RoutingType, AUTOMATIC, AUTOMATIC)            pu8RtngType,
    P2CONST(PduR_tstrTpTxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf)
{
    VAR(PduR_ReturnType, AUTOMATIC)                             u8FuncRet;

    /*! Check module's initialization                                         */
    if(PduR_u8eState == PDUR_UNINIT)
    {
        /*! Report to DET if enabled                                          */
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError( PDUR_MODULE_ID,
                                0,
                                pkstrTblsRf->u8APIId,
                                PDUR_E_INVALID_REQUEST);
        #endif

        (*pu8RtngType)  = PduR_u8INVALID_ROUTING;
        u8FuncRet       = E_NOT_OK;
    }
    /*! Determine the routing type and report to DET if needed accordingly    */
    else
    {
        /*! Check id is in specified range of minimum routing tables          */
        if(udtId < pkstrTblsRf->u16MinTxTSize)
        {
            (*pu8RtngType)  = PduR_u8MINIMUM_ROUTING;
            u8FuncRet       = E_OK;
        }
        /*! Check id is in specified range of normal routing tables           */
        else if(    (PduR_u8eState == PDUR_ONLINE) && 
                    (udtId < (pkstrTblsRf->u16NrmTxTSize 
                            + pkstrTblsRf->u16MinTxTSize)))
        {
            (*pu8RtngType)  = PduR_u8NORMAL_ROUTING;
            u8FuncRet       = E_OK;
        }
        /*! id is in out of range                                             */
        else
        {
            (*pu8RtngType)  = PduR_u8INVALID_ROUTING;

            /*! Set the return type to NOT_OK                                 */
            u8FuncRet       = E_NOT_OK;
        }

        if((*pu8RtngType) == PduR_u8INVALID_ROUTING)
        {
            /*! Report to DET if enabled, Id is not in the valid range        */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    pkstrTblsRf->u8APIId,
                                    PDUR_E_PDU_ID_INVALID);
            #endif
        }
    }

    return u8FuncRet;
}

/***********************************************/
/* Transport Protocol Layers Gateway Functions */
/***********************************************/

#if(PduR_bGATEWAYING_TP == STD_ON)
/******************************************************************************/
/*! \Description    StartOfReception TP gatewaying local function used to handle
                    the gatewaying operation over TP layer (sets respective 
                    counters, assigns local buffers ... etc) either for single 
                    or multiple destinations as defined \n
    \return         BUFREQ_OK, BUFREQ_E_NOT_OK, BUFREQ_E_BUSY, BUFREQ_E_OVFL \n
*******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuGateTpStartOfRx(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    /* !Deviation : Inhibit MISRA rule [3206]: This parameter is mandatory    */
    /*              by AUTOSAR specs.                                         */
    /* PRQA S 3206 ++                                                         */
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)    pstrPduInfo,
    /* PRQA S 3206 --                                                         */
    VAR(PduLengthType, AUTOMATIC)                   udtSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) pudtAvBuffSize)
{
    VAR(BufReq_ReturnType, AUTOMATIC)               enuFuncRet;
    VAR(PduIdType, AUTOMATIC)                       udtGtTblIdx;
    VAR(PduIdType, AUTOMATIC)                       udtCtrlId;
    VAR(uint16, AUTOMATIC)                          u16GlblPdu;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RouteGrp;
    #endif

    VAR(uint16, AUTOMATIC)                          u16BuffId;
    VAR(uint16, AUTOMATIC)                          u16SrchLength;
    VAR(boolean, AUTOMATIC)                         bRxInProgress;

    /*! Check udtPduId is in specified range of normal routing tables 
        or not (only normal routing as no gatewaying in reduced mode)         */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtPduId < PduR_pkstrePbCfg->udtGateTpRTSize))
    {
        /*! Grab routing group and control index, initialize local variables  */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp     = astrGATE_TP_TBL(udtPduId).u16RPathGrpId;
        #endif
        udtCtrlId       = astrGATE_TP_TBL(udtPduId).udtCntrlId;
        udtGtTblIdx     = udtPduId;
        bRxInProgress   = FALSE;

        /*! Check if there is any of the dests the messege will be gatewayed
            to are still in progress or not (to use pre-assigned buffer)      */
        while(  (udtCtrlId == astrGATE_TP_TBL(udtGtTblIdx).udtCntrlId) &&
                (udtGtTblIdx < PduR_pkstrePbCfg->udtGateTpRTSize))
        {
            u16GlblPdu = astrGATE_TP_TBL(udtGtTblIdx).u16IPduGlobalId;

            /*! If one of the destinations is not IDLE                        */
            if(PduR_au8eGlblPduState[u16GlblPdu] != PduR_u8IDLE)
            {
                /*! Terminate the loop and set flag to TRUE                   */
                bRxInProgress   = TRUE;
                udtCtrlId       = 0;
            }

            udtGtTblIdx++;
        }

        /*! Grab the control ID of the message to be received                 */
        udtCtrlId   = astrGATE_TP_TBL(udtPduId).udtCntrlId;

        if(pudtAvBuffSize == (PduLengthType *) NULL_PTR)
        {
            /*! Report to DET if enabled                                      */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    astrGATE_TP_SUBTBL(udtCtrlId)
                                                                .u8StartRxApiId,
                                    PDUR_E_NULL_POINTER);
            #endif

            /*! Set enuFuncRet to BUFREQ_E_NOT_OK as an error occured         */
            enuFuncRet = BUFREQ_E_NOT_OK;
        }
        /*! Check using the first element in the gateway set that the state of
            the IPDU ID is IDLE. This is to confirm that there is no previous
            operation is going and accordingly either search for a new free
            buffer and assign it or get the Id of the previously reserved one */
        else
        {
            if(bRxInProgress == TRUE)
            {
                /*! A previous request is on-going, clear the old buffer linked
                    with this request and start the search process again for a 
                    free Tp buffer. This to avoid having the new request with 
                    different length and to correctly assign the buffer       */

                /*! Get the previously reserved buffer & free it              */
                u16BuffId   = astrGATE_TP_CTRL(udtCtrlId).u16BuffIdx;
                PduR_astreTpBuffCtrl[u16BuffId].bIsFree = TRUE;
            }

            /*! Now a new request is to be served (either new or an old one but
                the buffer is free-d, now search for a free TP buffer that can 
                hold the requested length                                     */

            /*! Identify the type of gatewaying used (direct/on-the-fly)      */
            if(astrGATE_TP_TBL(udtPduId).u8BuffThreshold == u8DIRECT_GW_VALUE)
            {
                /*! Search length shall be equal to full message length       */
                u16SrchLength = udtSduLength;
            }
            else        /* On-the-fly gatewaying                              */
            {
                /*! Search length shall be equal to defined threshold         */
                u16SrchLength = astrGATE_TP_TBL(udtPduId).u8BuffThreshold;
            }

            /*! Protection needed againest data consistency                   */
            /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is          */
            /*              to be implemented during integration phase        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Enter_PduR(PduR_TP_BUFF_CTRL_START_OF_RX);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Request the new buffer based on identified length above       */
            enuFuncRet = enuGetNewTpBuffer(u16SrchLength, &u16BuffId);

            /*! If an empty buffer was found, assign buffer to the GateTp
                table Idx to be used afterwards in other gatewaying APIs      */
            if(enuFuncRet == BUFREQ_OK)
            {
                /*! Reserve the TP buffer (reserve the new buffer)            */
                #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
                vidReserveTpBuffer(udtPduId,     udtSduLength,
                                   u16BuffId,    u16RouteGrp);
                #else
                vidReserveTpBuffer(udtPduId, udtSduLength, u16BuffId);
                #endif

                /*! Return the size of the reserved buffer                    */
                (*pudtAvBuffSize) = 
                            PduR_akstreTpBuffers[u16BuffId].u16BuffLength;
            }
            else
            {
                /*! Do nothing                                                */
            }

            /*! Clear critical section                                        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_TP_BUFF_CTRL_START_OF_RX);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */
        }

        /*! Check return, if OK, start updating the global IPDU states        */
        if(enuFuncRet == BUFREQ_OK)
        {
            /*! Set global IPDU state for all Tx destinations to TOBEHANDLED  */
            udtGtTblIdx = udtPduId;
            udtCtrlId   = astrGATE_TP_TBL(udtGtTblIdx).udtCntrlId;

            while(  (udtCtrlId == astrGATE_TP_TBL(udtGtTblIdx).udtCntrlId) &&
                    (udtGtTblIdx < PduR_pkstrePbCfg->udtGateTpRTSize))
            {
                /*! Set global IPDU state to TOBEHANDLED                      */
                u16GlblPdu = astrGATE_TP_TBL(udtGtTblIdx).u16IPduGlobalId;
                PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8TOBEHANDLED;

                /*! Increment the gateway table index used                    */
                udtGtTblIdx++;
            }
        }
    }
    /*! udtPduId to be used in the Rx operation is out of range               */
    else
    {
        /*! Set enuFuncRet to BUFREQ_E_NOT_OK as an error occured             */
        enuFuncRet = BUFREQ_E_NOT_OK;
    }

    return enuFuncRet;
}

/******************************************************************************/
/*! \Description    TP gatewaying local function used to copy the received data
                    from the source module to the local PduR buffer attached \n
    \return         BUFREQ_OK, BUFREQ_E_NOT_OK, BUFREQ_E_BUSY \n
*******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuGateTpCopyRxData(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    /* !Deviation : Inhibit MISRA rule: Prototype is indirectly inforced by   */
    /*              AUTOSAR to comply to <Up>_CopyRxData prototype            */
    /* PRQA S 3673 ++                                                         */
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   pstrPduInfo,
    /* PRQA S 3673 --                                                         */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) pudtAvBuffSize)
{
    VAR(BufReq_ReturnType, AUTOMATIC)               enuFuncRet;
    VAR(uint16, AUTOMATIC)                          u16TpBuffId;
    VAR(uint16, AUTOMATIC)                          u16GlblPdu;
    VAR(PduIdType, AUTOMATIC)                       udtCtrlId;

    /*! Check udtPduId is in specified range of normal routing tables 
        or not (only normal routing as no gatewaying in reduced mode)         */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtPduId < PduR_pkstrePbCfg->udtGateTpRTSize))
    {
        /*! Regardless on the TP gatewaying type, data must be copied to the
            TP buffer associated with the passed Id unless length = 0         */

        /*! Grab the Ids of the TP buffer and the Rx Global IPDU ID           */
        udtCtrlId   = astrGATE_TP_TBL(udtPduId).udtCntrlId;
        u16TpBuffId = astrGATE_TP_CTRL(udtCtrlId).u16BuffIdx;
        u16GlblPdu  = astrGATE_TP_SUBTBL(udtCtrlId).u16RxGlobalId;

        /*! Check if the IPDU ID is INPROGRESS or not                         */
        /*! \Trace_To   PduR-CDD-5281(1)                                      */
        if(PduR_au8eGlblPduState[u16GlblPdu] != PduR_u8INPROGRESS)
        {
            /*! Set enuFuncRet to BUFREQ_E_NOT_OK as the specified ID is IDLE */
            enuFuncRet = BUFREQ_E_NOT_OK;
        }
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        else if(    (pstrPduInfo                == (PduInfoType*) NULL_PTR) ||
                    (pstrPduInfo->SduDataPtr    == (uint8 *) NULL_PTR)      ||
                    (pudtAvBuffSize             == (PduLengthType*) NULL_PTR))
        {
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    astrGATE_TP_SUBTBL(udtCtrlId)
                                                                .u8CopyRxDApiId,
                                    PDUR_E_NULL_POINTER);

            enuFuncRet = BUFREQ_E_NOT_OK;
        }
        #endif
        /*! If requested length = 0, return with the available buffer size    */
        /*! \Trace_To    PduR-CDD-5097(0)                                     */
        else if(pstrPduInfo->SduLength == 0)
        {
            /*! Return the size of the current available buffer for Rx        */
            (*pudtAvBuffSize) = PduR_astreTpBuffCtrl[u16TpBuffId].udtRxAvBytes;

            /*! Set enuFuncRet to BUFREQ_OK as the request is only size       */
            enuFuncRet = BUFREQ_OK;
        }
        else
        {
            /*! Copy the received data to the local Tp buffer & return size   */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            enuFuncRet = enuTpBufferAdd(    u16TpBuffId, pstrPduInfo,
                                            astrGATE_TP_SUBTBL(udtCtrlId)
                                            .u8CopyRxDApiId);
            #else
            enuFuncRet = enuTpBufferAdd(u16TpBuffId, pstrPduInfo);
            #endif
            (*pudtAvBuffSize) = PduR_astreTpBuffCtrl[u16TpBuffId].udtRxAvBytes;

            /*! Check if the gatewaying operation is direct or on-the-fly     */
            /*  FLY                                                           */
            if(astrGATE_TP_TBL(udtPduId).u8BuffThreshold != u8DIRECT_GW_VALUE)
            {
                if(enuFuncRet == BUFREQ_OK)
                {
                    if(astrGATE_TP_CTRL(udtCtrlId).bTxDone == FALSE)
                    {
                        /*! Handle CopyRxData operation for on-the-fly GW     */
                        vidHndlGtFlyCopyRxData(udtPduId);
                    }
                }
                else
                {
                    /*! Return BUFREQ_E_NOT_OK                                */
                    /*! Trace_To    PduR-CDD-5098(0)                          */
                    enuFuncRet = BUFREQ_E_NOT_OK;

                    /*! Set global Tx IPDU ID state to IDLE                   */
                    u16GlblPdu = astrGATE_TP_TBL(udtPduId).u16IPduGlobalId;

                    /*! Set global IPDU to IDLE (for all Tx IPDUs)            */
                    /*! Note: Gatewaying on-the-fly --> only one destination  */
                    /*! \Trace_To    PduR-CDD-5189(0)                         */
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                    /*! Clear the TP buffer                                   */
                    PduR_astreTpBuffCtrl[u16TpBuffId].bIsFree = TRUE;
                }
            }
            else    /* DIRECT                                                 */
            {
                /*! \Trace_To    PduR-CDD-5208(0)                             */
                /*! Do nothing, return with the same value of enuTpBufferAdd
                    API as further Tx is handled in GateTpRxIndication        */
            }
        }
    }
    /*! udtPduId to be used in the Rx operation is out of range               */
    else
    {
        /*! Set enuFuncRet to BUFREQ_E_NOT_OK as an error occured             */
        enuFuncRet = BUFREQ_E_NOT_OK;
    }

    return enuFuncRet;
}

/* !Deviation : Inhibit MISRA rule: STCYC (Cyclomatic Complexity) and STPTH   */
/*              (Estimated Path Count) are needed to fullfill the needed      */
/*              functionality of the API and can be reduced if not all the    */
/*              features are enabled in the PDUR.                             */
/*              No further simplification is needed.                          */
/* PRQA S 4700 ++                                                             */

/******************************************************************************/
/*! \Description    TP gatewaying local function used to gateway the PDU to
                    one (or more) destination \n
    \return         void \n
    \Trace_To       PduR-CDD-0079(0), PduR-CDD-5099(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidGateTpRxIndication(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    VAR(NotifResultType, AUTOMATIC)                 u8Result)
{
    VAR(uint16, AUTOMATIC)                          u16TpBuffId;
    VAR(uint16, AUTOMATIC)                          u16GlblPdu;

    VAR(PduIdType, AUTOMATIC)                       udtGtTblIdx;
    VAR(PduIdType, AUTOMATIC)                       udtCtrlId;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RouteGrp;
    #endif

    VAR(PduIdType, AUTOMATIC)                       udtTargetId;
    VAR(uint8, AUTOMATIC)                           u8DevIdx;
    VAR(Std_ReturnType, AUTOMATIC)                  u8TxFnRet;
    VAR(PduInfoType, AUTOMATIC)                     strPduInfo;


    P2CONST(PduR_tstrTpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                    pkstrTpTxFp;

    #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
    VAR(boolean, AUTOMATIC)                         bGWStatus;
    #endif

    /*! Check udtPduId is in specified range of normal routing tables 
        or not (only normal routing as no gatewaying in reduced mode)         */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtPduId < PduR_pkstrePbCfg->udtGateTpRTSize))
    {
        /*! Grab the control ID, TP buffer ID and global Rx IPDU ID           */
        udtCtrlId   = astrGATE_TP_TBL(udtPduId).udtCntrlId;
        u16TpBuffId = astrGATE_TP_CTRL(udtCtrlId).u16BuffIdx;
        u16GlblPdu  = astrGATE_TP_SUBTBL(udtCtrlId).u16RxGlobalId;
        udtGtTblIdx = udtPduId;

        /*! Check if the IPDU ID is INPROGRESS or not                         */
        if(PduR_au8eGlblPduState[u16GlblPdu] != PduR_u8INPROGRESS)
        {
            /*! Exit and ignore the received Rx Indication as IPDU was IDLE   */
        }
        /*! Check the result of the reception process, OK or NOK              */
        else if(u8Result != NTFRSLT_OK) /* Error result, regardless of code   */
        {
            /*! Clear Tp buffer and mark it as available for new requests and
                to block any CopyTxData requests from accessing it            */
            PduR_astreTpBuffCtrl[u16TpBuffId].bIsFree = TRUE;    /* atomic    */

            /*! Regardless of gatewaying type, mark the destination(s) Tx Global
                IPDU state to IDLE (loop on all destinations)                 */
            while(  (udtCtrlId == astrGATE_TP_TBL(udtGtTblIdx).udtCntrlId) &&
                    (udtGtTblIdx < PduR_pkstrePbCfg->udtGateTpRTSize))
            {
                /*! Trace_To    PduR-CDD-5100(0)                              */
                u16GlblPdu = astrGATE_TP_TBL(udtGtTblIdx).u16IPduGlobalId;
                PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                /*! Increment gatewaying counter value for next index         */
                udtGtTblIdx++;
            }
        }
        else    /* u8Result = NTFRSLT_OK                                      */
        {
            /*! Check gatewaying: On-the-Fly or Direct                        */
            /*  FLY                                                           */
            if(astrGATE_TP_TBL(udtPduId).u8BuffThreshold != u8DIRECT_GW_VALUE)
            {
                /*! Do nothing - transmission took place in CopyRxData and 
                    buffer clearing shall be done after TxConfirmation        */
            }
            else    /* DIRECT                                                 */
            {
                /*! Prepare the data to be gatewayed to the destination(s)    */
                udtGtTblIdx = udtPduId;

                /*! Prepare the transmission data                             */
                strPduInfo.SduLength    = 
                                PduR_astreTpBuffCtrl[u16TpBuffId].udtMsgLen;
                strPduInfo.SduDataPtr   = 
                                PduR_akstreTpBuffers[u16TpBuffId].pu8BuffData;

                /*! Loop on all destinations to request their TpTransmit fns  */
                while(   (udtCtrlId == astrGATE_TP_TBL(udtGtTblIdx).udtCntrlId)
                      && (udtGtTblIdx < PduR_pkstrePbCfg->udtGateTpRTSize))
                {
                    /*! Prepare the destination, routing group and global ids */
                    udtTargetId = astrGATE_TP_TBL(udtGtTblIdx).udtDstPduRefId;
                    u16GlblPdu  = astrGATE_TP_TBL(udtGtTblIdx).u16IPduGlobalId;

                    /*! Prepare the transmit function pointer                 */
                    u8DevIdx    = astrGATE_TP_TBL(udtGtTblIdx).u8DstPduDeviceId;
                    pkstrTpTxFp = pkstrTP_TX_TBL(u8DevIdx);

                    /*! Check routing group to see if Tx can take place       */
                    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
                    u16RouteGrp = astrGATE_TP_TBL(udtGtTblIdx).u16RPathGrpId;
                    if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
                    #endif
                    {
                        /*! Set global PDU state to INPROGRESS                */
                        PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8INPROGRESS;

                        /*! Increment the corresponding counter               */
                        astrGATE_TP_CTRL(udtCtrlId).u8CntrValue++;

                        #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
                        /*! If call-outs are supported, perform the call-out
                            check before calling the destination's Tx API     */
                        /*! \Trace_To   PduR-CDD-5405(0)                      */
                        if(astrGATE_TP_TBL(udtGtTblIdx).pfbGateCallOut !=
                                                (PduR_tpfbGateCallOut) NULL_PTR)
                        {
                            bGWStatus = astrGATE_TP_TBL(udtGtTblIdx)
                                    .pfbGateCallOut( udtTargetId,
                                            (const PduInfoType*) &strPduInfo);
                        }
                        else
                        {
                            bGWStatus = TRUE;
                        }
                        /*! If call-out returned TRUE, proceed with Tx        */
                        /*! \Trace_To   PduR-CDD-5406(0)                      */
                        if(bGWStatus == TRUE)
                        #endif
                        {
                            u8TxFnRet = pkstrTpTxFp->pfu8TpTransmit(
                                                    udtTargetId, &strPduInfo);

                            if((u8TxFnRet != E_OK) && (u8TxFnRet != E_PENDING))
                            {
                                /*! Set global PDU state to IDLE              */
                                PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                                /*! Decrement the corresponding counter       */
                                astrGATE_TP_CTRL(udtCtrlId).u8CntrValue--;

                                /*! If DET enabled, report to DET that request
                                    was rejected                              */
                                #if(PduR_bDEV_ERROR_DETECT == STD_ON)
                                (void) Det_ReportError(
                                                PDUR_MODULE_ID,
                                                0,
                                                astrGATE_TP_SUBTBL(udtCtrlId)
                                                                .u8RxIndApiId,
                                                PDUR_E_TP_TX_REQ_REJECTED);
                                #endif
                            }
                        }
                        #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
                        /*! If call-out returned FALSE, terminate the Tx      */
                        else
                        {
                            /*! Set global PDU state to IDLE                  */
                            PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                            /*! Decrement the corresponding counter           */
                            astrGATE_TP_CTRL(udtCtrlId).u8CntrValue--;
                        }
                        #endif
                    }

                    /*! Increment the gateway table index used                */
                    udtGtTblIdx++;
                }

                /*! If the counter value is at 0, then all destinations returned
                    with E_NOT_OK to the transmit request or all disabled in
                    their routing groups, accordingly the Tp buffer reserved
                    should be cleared too                                     */
                if(astrGATE_TP_CTRL(udtCtrlId).u8CntrValue == 0)
                {
                    PduR_astreTpBuffCtrl[u16TpBuffId].bIsFree = TRUE;
                }
            }
        }
    }
}

/* PRQA S 4700 --                                                             */

/******************************************************************************/
/*! \Description    TP gatewaying local function used to copy the data to be 
                    transmitted to the destination module from the local 
                    PduR buffer attached \n
    \return         BUFREQ_OK, BUFREQ_E_NOT_OK, BUFREQ_E_BUSY \n
*******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuGateTpCopyTxData(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   pstrPduInfo,
    /* !Deviation : Inhibit MISRA rule: Prototype is indirectly inforced by   */
    /*              AUTOSAR to comply to <Up>_CopyTxData prototype            */
    /* PRQA S 3673 ++                                                         */
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) pstrRetryInfo,
    /* PRQA S 3673 ++                                                         */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) pudtAvBuffSize)
{
    VAR(BufReq_ReturnType, AUTOMATIC)               enuFuncRet;
    VAR(uint16, AUTOMATIC)                          u16TpBuffId;
    VAR(uint16, AUTOMATIC)                          udtCtrlId;
    VAR(uint16, AUTOMATIC)                          u16GlblPdu;

    /*! Check udtPduId is in specified range of normal routing tables or not
        (only normal routing as no gatewaying in reduced mode)                */
    if(    (PduR_u8eState == PDUR_ONLINE) && 
           (udtPduId < PduR_pkstrePbCfg->udtGateTpRTSize))
    {
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /*! Perform API parameter checking against passing NULL pointers      */
        if(     (pstrPduInfo                == (PduInfoType *) NULL_PTR)
            ||  (pstrPduInfo->SduDataPtr    == (uint8 *) NULL_PTR)
            ||  (pstrRetryInfo              == (RetryInfoType *) NULL_PTR)
            ||  (pudtAvBuffSize             == (PduLengthType *) NULL_PTR))
        {
            /*! Report to DET if enabled                                      */
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    astrGATE_TP_TBL(udtPduId).u8CopyTxDApiId,
                                    PDUR_E_NULL_POINTER);

            enuFuncRet = BUFREQ_E_NOT_OK;
        }
        else
        #endif
        {
            /*! Regardless on the TP gatewaying type, data must be copied to 
                the TP buffer associated with the passed Id unless length = 0 */

            /*! Grab the Ids of the TP buffer                                 */
            udtCtrlId   = astrGATE_TP_TBL(udtPduId).udtCntrlId;
            u16TpBuffId = astrGATE_TP_CTRL(udtCtrlId).u16BuffIdx;

            /*! If requested length == 0, return available buffer size & exit */
            /*! \Trace_To    PduR-CDD-5096(0)                                 */
            if(pstrPduInfo->SduLength == 0)
            {
                /*! Return the size of the current available buffer for Tx    */
                (*pudtAvBuffSize) = 
                                PduR_astreTpBuffCtrl[u16TpBuffId].udtTxAvBytes;

                /*! Set enuFuncRet to BUFREQ_OK as the request is only size   */
                enuFuncRet = BUFREQ_OK;
            }
            else
            {
                /*! Check special conditions for on-the-fly gatewaying        */
                /*! \Trace_To    PduR-CDD-5090(0), PduR-CDD-5091(0)           */
                if( (pstrRetryInfo->TpDataState != TP_DATACONF) &&
                    (pstrRetryInfo->TpDataState != TP_NORETRY)  &&
                    (astrGATE_TP_TBL(udtPduId).u8BuffThreshold 
                                                        != u8DIRECT_GW_VALUE)
                   )
                {
                    /*! Stop further processing: set buffer as free and global
                        IPDU ID as idle and return BUFREQ_E_NOT_OK            */
                    u16GlblPdu  = astrGATE_TP_TBL(udtPduId).u16IPduGlobalId;

                    PduR_astreTpBuffCtrl[u16TpBuffId].bIsFree = TRUE;
                    PduR_au8eGlblPduState[u16GlblPdu]         = PduR_u8IDLE;
                    enuFuncRet                                = BUFREQ_E_NOT_OK;
                }
                else
                {
                    /*! Determine the copying type that shall be forwarded to 
                        local function responsible for copying the Tx Data    */
                    if(astrGATE_TP_CTRL(udtCtrlId).u8CntrValue == 0x01)
                    {
                        /*! Counter value == 1 --> only one destination is 
                            available so copying shall be done using normal 
                            index in cntrl info                               */
                        enuFuncRet = enuTpBufferRemove( u16TpBuffId,
                                                        pstrPduInfo,
                                                        pstrRetryInfo,
                                                        pudtAvBuffSize,
                                                        u8NORMAL_GW_COPY);
                    }
                    else
                    {
                        /*! Counter value > 1 --> multiple destinations are 
                            available so copying shall be done always starting 
                            from index 0                                      */
                        enuFuncRet = enuTpBufferRemove( u16TpBuffId,
                                                        pstrPduInfo,
                                                        pstrRetryInfo,
                                                        pudtAvBuffSize,
                                                        u8ZEROBASE_GW_COPY);
                    }
                }
            }
        }
    }
    /*! udtPduId to be used in the Rx operation is out of range               */
    else
    {
        /*! Set enuFuncRet to BUFREQ_E_NOT_OK as an error occured             */
        enuFuncRet = BUFREQ_E_NOT_OK;
    }

    return enuFuncRet;
}

/******************************************************************************/
/*! \Description    TP gatewaying local function used to act accordingly upon
                    receiving a TxConfirmation from lower layers (freeing the
                    Tp buffers and changing status to IDLE for IPDUs) \n
    \return         void \n
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidGateTpTxConfirm(
    VAR(PduIdType, AUTOMATIC)                       udtId,
    /* !Deviation : Inhibit MISRA rule: Prototype is indirectly inforced by   */
    /*              AUTOSAR to comply to <Up>_TpTxConfirmation prototype, but */
    /*              parameter is not needed in the context of this function   */
    /* PRQA S 3206 ++                                                         */
    VAR(NotifResultType, AUTOMATIC)                 u8Result)
    /* PRQA S 3206 ++                                                         */
{
    VAR(uint16, AUTOMATIC)                          u16TpBuffId;
    VAR(PduIdType, AUTOMATIC)                       udtGtTblIdx;
    VAR(PduIdType, AUTOMATIC)                       udtCtrlId;    
    VAR(uint16, AUTOMATIC)                          u16GlblPdu;

    /*! Check udtPduId is in specified range of normal routing tables or not
        (only normal routing as no gatewaying in reduced mode)                */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtId < PduR_pkstrePbCfg->udtGateTpRTSize))
    {
        /*! Grab the buffer ID, counter value and global IPDU ID used         */
        udtCtrlId   = astrGATE_TP_TBL(udtId).udtCntrlId;
        u16GlblPdu  = astrGATE_TP_TBL(udtId).u16IPduGlobalId;
        u16TpBuffId = astrGATE_TP_CTRL(udtCtrlId).u16BuffIdx;

        /*! Check if the IPDU ID is INPROGRESS or not                         */
        if(PduR_au8eGlblPduState[u16GlblPdu] == PduR_u8INPROGRESS)
        {
            /*! \Trace_To   PduR-CDD-5324(0)                                  */
            /*! Decrement the counter used for transmission                   */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            /*! Robustness check: Check that value is not 0 already           */
            if(astrGATE_TP_CTRL(udtCtrlId).u8CntrValue != 0)
            {
                (astrGATE_TP_CTRL(udtCtrlId).u8CntrValue)--;
            }
            #else
            (astrGATE_TP_CTRL(udtCtrlId).u8CntrValue)--;
            #endif

            /*! Check if the counter value reached 0 or not                   */
            /*! \Trace_To   PduR-CDD-5325(0)                                  */
            if(astrGATE_TP_CTRL(udtCtrlId).u8CntrValue == 0)
            {
                /*! Set the global IPDU state for all Tx destinations to IDLE */
                udtGtTblIdx = astrGATE_TP_SUBTBL(udtCtrlId).u8StartId;

                /*! Clear the TP buffer used                                  */
                /*! \Trace_To   PduR-CDD-0087(0)                              */
                PduR_astreTpBuffCtrl[u16TpBuffId].bIsFree = TRUE;

                while(   (udtCtrlId == astrGATE_TP_TBL(udtGtTblIdx).udtCntrlId)
                      && (udtGtTblIdx < PduR_pkstrePbCfg->udtGateTpRTSize))
                {
                    /*! Set global IPDU state for all Tx dests to PduR_u8IDLE */
                    u16GlblPdu = astrGATE_TP_TBL(udtGtTblIdx).u16IPduGlobalId;
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                    /*! Increment the gateway table index used                */
                    udtGtTblIdx++;
                }
            }
            else
            {
                /*! Do nothing, calls shall be discarded till counter == 0, 
                    counter will only be set to 0 at the end of TpTxConfirmation
                    so it shall never occur that the GateTpTxConfirmation shall 
                    be invoked with counter value = 0 more than once          */
            }
        }
    }
}
#endif

/***************************************************/
/* Transport Protocol Layer Multicasting Functions */
/***************************************************/

#if(PduR_bMULTICASTING_TP == STD_ON)
/******************************************************************************/
/*! \Description    TP multicast local function used to control the copying of 
                    data from the upper to lower layers by controling respective
                    counters responsible for this operation \n
    \return         BUFREQ_OK, BUFREQ_E_NOT_OK, BUFREQ_E_BUSY \n
*******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuMultiTpCopyTxData(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   pstrPduInfo,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) pstrRetryInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) pudtAvBuffSize)
{
    VAR(BufReq_ReturnType, AUTOMATIC)               enuFuncRet;
    VAR(PduIdType, AUTOMATIC)                       udtCtrlId;
    VAR(uint16, AUTOMATIC)                          u16GlblPdu;

    VAR(PduIdType, AUTOMATIC)                       udtTargetId;
    VAR(uint8, AUTOMATIC)                           u8DevIdx;
    VAR(RetryInfoType, AUTOMATIC)                   strRetry;

    P2CONST(PduR_tstrTp2UpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                    pkstrTpUpFp;

    /*! Perform API parameter checking against passing NULL pointers          */
    if(     (pstrPduInfo        == (PduInfoType *) NULL_PTR)
        ||  (pstrRetryInfo      == (RetryInfoType *) NULL_PTR)
        ||  (pudtAvBuffSize     == (PduLengthType *) NULL_PTR))
    {
        /*! Report to DET if enabled                                          */
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError( PDUR_MODULE_ID,
                                0,
                                astrMULTI_TP_TBL(udtPduId).u8CopyTxApiId,
                                PDUR_E_NULL_POINTER);
        #endif

        enuFuncRet = BUFREQ_E_NOT_OK;
    }
    /*! Check udtPduId is in specified range of normal routing tables or not
        (only normal routing as no gatewaying in reduced mode)                */
    else if(    (PduR_u8eState == PDUR_ONLINE) && 
                (udtPduId < PduR_pkstrePbCfg->udtMultiTpRTSize))
    {
        /*! Grab the control ID for the Tp multicasting operations            */
        udtCtrlId   = astrMULTI_TP_TBL(udtPduId).udtCntrlId;

        /*! Prepare dest, routing group & global ids                          */
        udtTargetId = astrMULTI_TP_SUB_TBL(udtCtrlId).udtSrcPduRefId;
        u16GlblPdu  = astrMULTI_TP_TBL(udtPduId).u16IPduGlobalId;

        /*! Prepare the Copy Tx Data function pointer                         */
        u8DevIdx    = astrMULTI_TP_SUB_TBL(udtCtrlId).u8SrcPduDeviceId;
        pkstrTpUpFp = pkstrTP_UP_TBL(u8DevIdx);

        /*! Request shall be forwarded to upper layer without ultering if the
            requested SduLength == 0 or TpDataState == TP_DATARETRY. Else,
            modifications shall take place for multicasting                   */
        /*! \Trace_To   PduR-CDD-5204(0)                                      */
        if( (pstrPduInfo->SduLength > 0) && 
            (pstrRetryInfo->TpDataState != TP_DATARETRY))
        {
            /*! Check if this is the first entry in the multicast set to be
                forwarded. If so, forward request with TP_CONFPENDING         */
            if(astrMULTI_TP_CTRL(udtCtrlId).bIsFirst == TRUE)
            {
                /*! \Trace_To   PduR-CDD-5201(0)                              */
                strRetry.TpDataState = TP_CONFPENDING;
                strRetry.TxTpDataCnt = 0;
                astrMULTI_TP_CTRL(udtCtrlId).bIsFirst = FALSE;
            }
            /*! Else, PduR shall handle passing the requests to upper layer
                using TP_DATARETRY and its own management of TxTpDataCnt      */
            /*! \Trace_To   PduR-CDD-5203(0)                                  */
            else
            {
                /*! \Trace_To   PduR-CDD-5202(0)                              */
                strRetry.TpDataState = TP_DATARETRY;
                strRetry.TxTpDataCnt =
                            PduR_pkstrePbCfg->pu16MultiTpCopyTxIdx[udtPduId];
            }

            /*! Request shall be forwarded after modifications. No need to check
                again the global IPDU state nor routing group as this was done
                in the local CopyTxData function earlier                      */
            enuFuncRet = pkstrTpUpFp->pfenuUpTpCopyTxData(
                    udtTargetId, pstrPduInfo, &strRetry, pudtAvBuffSize);

            /*! Check the return of the upper layer and act accordingly       */
            if(enuFuncRet == BUFREQ_OK)
            {
                /*! Increment counter of already copied data bytes for this
                    lower Tp module to the length of actual copied data       */
                /*! \Trace_To   PduR-CDD-5202(0)                              */
                PduR_pkstrePbCfg->pu16MultiTpCopyTxIdx[udtPduId] = 
                            PduR_pkstrePbCfg->pu16MultiTpCopyTxIdx[udtPduId]
                            + pstrPduInfo->SduLength;
            }
            else if(enuFuncRet != BUFREQ_E_BUSY)
            {
                /*! Error occured, set global IPDU ID to IDLE                 */
                PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;
            }
            else
            {
                /*! Do nothing                                                */
            }
        }
        else
        {
            /*! Request shall be forwarded with no modification. No need to
                check again the global IPDU state nor routing group as this was
                done in the local CopyTxData function earlier                 */
            enuFuncRet = pkstrTpUpFp->pfenuUpTpCopyTxData(
                    udtTargetId, pstrPduInfo, pstrRetryInfo, pudtAvBuffSize);
        }
    }
    /*! udtPduId to be used in the Rx operation is out of range               */
    else
    {
        /*! Set enuFuncRet to BUFREQ_E_NOT_OK as an Id is out of range        */
        enuFuncRet = BUFREQ_E_NOT_OK;
    }

    return enuFuncRet;
}

/******************************************************************************/
/*! \Description    TP multicast function used to act accordingly upon receiving
                    a TxConfirmation from lower layers (changing status to IDLE 
                    and informing upper layers with confirmation status) \n
    \return         void \n
    \Trace_To       PduR-CDD-0050(0), PduR-CDD-0101(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidMultiTpTxConfirm(
    VAR(PduIdType, AUTOMATIC)                       udtId,
    VAR(NotifResultType, AUTOMATIC)                 u8Result)
{
    VAR(PduIdType, AUTOMATIC)                       udtCtrlId;
    VAR(uint16, AUTOMATIC)                          u16GlblPdu;
    VAR(PduIdType, AUTOMATIC)                       udtTargetId;
    VAR(uint8, AUTOMATIC)                           u8DevIdx;
    VAR(uint8, AUTOMATIC)                           u8MultiTblIdx;

    P2CONST(PduR_tstrTp2UpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                    pkstrTpUpFp;


    /*! Check udtPduId is in specified range of normal routing tables or not
        (only normal routing as no gatewaying in reduced mode)                */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtId < PduR_pkstrePbCfg->udtMultiTpRTSize))
    {
        /*! Grab the control ID value from configuration                      */
        udtCtrlId   = astrMULTI_TP_TBL(udtId).udtCntrlId;

        /*! Prepare destination and TpTxConfirmation function pointer         */
        udtTargetId = astrMULTI_TP_SUB_TBL(udtCtrlId).udtSrcPduRefId;
        u8DevIdx    = astrMULTI_TP_SUB_TBL(udtCtrlId).u8SrcPduDeviceId;
        pkstrTpUpFp = pkstrTP_UP_TBL(u8DevIdx);

        /*! Set the GlblPdu to point to the Tx Global ID                      */
        u16GlblPdu = astrMULTI_TP_SUB_TBL(udtCtrlId).u16TxGlobalId;

        /*! Check u8Result (to see if an err in transmission occured or not)  */
        /*! \Trace_To   PduR-CDD-5070(1)                                      */
        if(     (u8Result != NTFRSLT_OK)
            &&  (u8Result != NTFRSLT_E_CANCELATION_OK)
            &&  (u8Result != NTFRSLT_E_CANCELATION_NOT_OK)  )
        {
            /*! An error has occured, inform upper layer with received error  */
            if(PduR_au8eGlblPduState[u16GlblPdu] != PduR_u8IDLE)
            {
                pkstrTpUpFp->pfvidUpTpTxConf(udtTargetId, u8Result);
            }

            /*! Set the global conf ID of the multicast set to IDLE           */
            PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

            /*! Reset the counter value (to handle future confirms)           */
            astrMULTI_TP_CTRL(udtCtrlId).u8CntrValue = 0;

            /*! Clear status of all IPDUs (for CopyTxData to act accordingly) */
            /*! \Trace_To   PduR-CDD-5071(0)                                  */
            u8MultiTblIdx = astrMULTI_TP_SUB_TBL(udtCtrlId).u8StartId;

            while(udtCtrlId == astrMULTI_TP_TBL(u8MultiTblIdx).udtCntrlId)
            {
                /*! Set global IPDU state for all Tx destinations to IDLE     */
                u16GlblPdu = astrMULTI_TP_TBL(u8MultiTblIdx).u16IPduGlobalId;
                PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                /*! Increment the multicasting table index used               */
                u8MultiTblIdx++;
            }
        }
        else
        {
            /*! No error, increment counter to note that a successful Tx      */
            /*! \Trace_To   PduR-CDD-5322(1)                                  */
            (astrMULTI_TP_CTRL(udtCtrlId).u8CntrValue)++;

            /*! Check if counter reached max value to inform the upper layer  */
            /*! \Trace_To   PduR-CDD-5326(1)                                  */
            if(astrMULTI_TP_CTRL(udtCtrlId).u8CntrValue 
                    == PduR_pkstrePbCfg->pkstrMultiTpSubRT[udtCtrlId].u8CntrMax)
            {
                /*! Inform upper layer with confirmation result               */
                pkstrTpUpFp->pfvidUpTpTxConf(
                        udtTargetId, astrMULTI_TP_CTRL(udtCtrlId).u8ConfResult);

                /*! Set the global conf ID of the multicast set to IDLE       */
                PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                /*! Reset the counter value (to handle future confirms)       */
                astrMULTI_TP_CTRL(udtCtrlId).u8CntrValue = 0;
            }
            else
            {
                /*! Normal confirmations are being received, update the RAM 
                    image for confirmation variable based on passed result    */
                if( (u8Result == NTFRSLT_E_CANCELATION_NOT_OK) ||
                    (       (u8Result == NTFRSLT_E_CANCELATION_OK) 
                        &&  (astrMULTI_TP_CTRL(udtCtrlId).u8ConfResult != 
                                                NTFRSLT_E_CANCELATION_NOT_OK)))
                {
                    astrMULTI_TP_CTRL(udtCtrlId).u8ConfResult = u8Result;
                }
                /*! In case of a confirmation came normally but a cancellation
                    process has started, then the return should be cancellation
                    NOK as one of the destinations finished its work and did not
                    cancel the operation successfully as stated               */
                else if(    (u8Result == NTFRSLT_OK) 
                        &&  (astrMULTI_TP_CTRL(udtCtrlId).u8ConfResult 
                                                == NTFRSLT_E_CANCELATION_OK))
                {
                    astrMULTI_TP_CTRL(udtCtrlId).u8ConfResult 
                                                = NTFRSLT_E_CANCELATION_NOT_OK;
                }
                else
                {
                    /*! Do nothing (if/else-if/else for MISRA compliance)     */
                }
            }
        }
    }
}
#endif

/**********************************************/
/* Transport Protocol Layer Default Functions */
/**********************************************/


/* !Deviation : Inhibit MISRA rule: API complexity is forced by requirements  */
/* PRQA S 4700 ++                                                             */
/******************************************************************************/
/*! \Description    Handles the start of reception of a frame on the transport 
                    protocol layer from a lower module and acts accordingly \n
    \return         BUFREQ_OK, BUFREQ_E_NOT_OK, BUFREQ_E_BUSY, BUFREQ_E_OVFL \n
    \Trace_To       PduR-CDD-0183(0), PduR-CDD-5190(0), PduR-CDD-5111(0)
    \Trace_To       PduR-CDD-5149(0), PduR-CDD-5150(0), PduR-CDD-5308(0)
    \Trace_To       PduR-CDD-5309(0)
*******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuLoTpStartOfRx(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    VAR(PduLengthType, AUTOMATIC)                               udtTpSduLen,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)             pudtBuffSize,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                         u8RtngType,
    P2CONST(PduR_tstrTpRxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf)
{
    VAR(BufReq_ReturnType, AUTOMATIC)               enuFuncRet;

    VAR(uint16, AUTOMATIC)                          u16GlblPduId;
    VAR(PduIdType, AUTOMATIC)                       udtTargetId;
    VAR(uint8, AUTOMATIC)                           u8DevIdx;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)     u16RouteGrp;
    #endif

    P2CONST(PduR_tstrLoTpRxRTableType, AUTOMATIC, PDUR_CFG_CONST)
                                                    pkstrRoute;
    P2CONST(PduR_tstrTp2UpRxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                    pkstrRxIndFp;

    /*! API parameters checking was already performed by the caller           */

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either
            minimum or normal routing as per the value of u8RtngType          */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute      = &pkstrTblsRf->pkstrMinRRxTRf[udtId];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrRxIndFp    = &pkstrTblsRf->pkstrMinRxFnTblRf[u8DevIdx];
        }
        else        /* u8NORMAL_ROUTING_ID */
        {
            /*! Prepare the target information for normal routing             */
            pkstrRoute      = &pkstrTblsRf->pkstrNrmRRxTRf[udtId 
                                            - pkstrTblsRf->u16MinRxTSize];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrRxIndFp    = &pkstrTblsRf->pkstrNrmRxFnTblRf[u8DevIdx];
        }

        /*! Grab the global IPDU ID, routing path group                       */
        u16GlblPduId    = pkstrRoute->u16IPduGlobalId;

        /*! Check the routing group of the IPDU ID passed                     */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp = pkstrRoute->u16RPathGrpId;
        if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
        #endif
        {
            /*! \Trace_To   PduR-CDD-5128(0)                                  */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            if(PduR_au8eGlblPduState[u16GlblPduId] != PduR_u8IDLE)
            {
                /*! Report to DET if enabled, duplicate IPdu ID */
                (void) Det_ReportError( PDUR_MODULE_ID,
                                        0,
                                        pkstrTblsRf->u8APIId,
                                        PDUR_E_DUPLICATED_IPDU_ID);
            }
            #endif

            /*! Identify the target ID used in forwarding the call            */
            /*! \Trace_To   PduR-CDD-5064(0)                                  */
            udtTargetId     = pkstrRoute->udtUpPduRefId;

            /*! Call the target function (forward the call)                   */
            /*! \Trace_To   PduR-CDD-0018(0)                                  */
            enuFuncRet = pkstrRxIndFp->pfenuUpTpStartOfRx(  udtTargetId,
                                                            NULL_PTR,
                                                            udtTpSduLen,
                                                            pudtBuffSize);

            /*! Check the retun of the UpStartOfRx function                   */
            /*! \Trace_To   PduR-CDD-0019(0)                                  */
            if(enuFuncRet != BUFREQ_OK)
            {
                /*! Set the Global PDU status to IDLE                         */
                PduR_au8eGlblPduState[u16GlblPduId] = PduR_u8IDLE;
            }
            else
            {
                /*! Set the Global PDU status to INPROGRESS                   */
                PduR_au8eGlblPduState[u16GlblPduId] = PduR_u8INPROGRESS;
            }
        }
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        else
        {
            /*! An error occured that caused the Global IPDU state to
                be IDLE, accordingly, set the return type to NOT_OK           */
            enuFuncRet = BUFREQ_E_NOT_OK;
        }
        #endif
    }
    else
    {
        enuFuncRet = BUFREQ_E_NOT_OK;
    }

    /*! \Trace_To   PduR-CDD-0020(0)                                          */
    return enuFuncRet;
}
/* PRQA S 4700 --                                                             */

/******************************************************************************/
/*! \Description    Handles the copying of Rx data of a frame on the transport 
                    protocol layer from a lower module and acts accordingly \n
    \return         BUFREQ_OK, BUFREQ_E_NOT_OK, BUFREQ_E_BUSY \n
    \Trace_To       PduR-CDD-0181(0), PduR-CDD-5038(0), PduR-CDD-5049(0)
    \Trace_To       PduR-CDD-5109(0), PduR-CDD-5145(0), PduR-CDD-5146(0)
    \Trace_To       PduR-CDD-5304(0), PduR-CDD-5305(0)
*******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuLoTpCopyRxData(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)               pstrInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)             pudtBuffSize,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                         u8RtngType,
    P2CONST(PduR_tstrTpRxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf)
{
    VAR(BufReq_ReturnType, AUTOMATIC)                           enuFuncRet;

    VAR(PduIdType, AUTOMATIC)                                   udtTargetId;
    VAR(uint8, AUTOMATIC)                                       u8DevIdx;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)                 u16RouteGrp;
    #endif

    P2CONST(PduR_tstrLoTpRxRTableType, AUTOMATIC, PDUR_CFG_CONST) 
                                                                pkstrRoute;
    P2CONST(PduR_tstrTp2UpRxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST) 
                                                                pkstrRxIndFp;

    /*! API parameters checking was already performed by the caller           */

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either
            minimum or normal routing as per the value of u8RtngType          */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute      = &pkstrTblsRf->pkstrMinRRxTRf[udtId];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrRxIndFp    = &pkstrTblsRf->pkstrMinRxFnTblRf[u8DevIdx];
        }
        else        /* u8NORMAL_ROUTING_ID                                    */
        {
            /*! Prepare the target information for normal routing */
            pkstrRoute      = &pkstrTblsRf->pkstrNrmRRxTRf[udtId - 
                                                pkstrTblsRf->u16MinRxTSize];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrRxIndFp    = &pkstrTblsRf->pkstrNrmRxFnTblRf[u8DevIdx];
        }

        /*! Check that routing group is enabled                               */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp = pkstrRoute->u16RPathGrpId;
        if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
        #endif
        {
            /*! Identify the target ID used in forwarding the call            */
            /*! \Trace_To   PduR-CDD-5062(0)                                  */
            udtTargetId = pkstrRoute->udtUpPduRefId;

            /*! Call the target function (forward the call)                   */
            /*! \Trace_To   PduR-CDD-0021(0)                                  */
            enuFuncRet = pkstrRxIndFp->pfenuUpTpCopyRxData( udtTargetId,
                                                            pstrInfo,
                                                            pudtBuffSize);
        }
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        else
        {
            /*! Routing group is disabled, set return to NOT_OK               */
            enuFuncRet = BUFREQ_E_NOT_OK;
        }
        #endif
    }
    else
    {
        enuFuncRet = BUFREQ_E_NOT_OK;
    }

    return enuFuncRet;
}

/******************************************************************************/
/*! \Description    Handles the reception of a frame on the transport protocol
                    layer from a lower module and acts accordingly \n
    \return         void \n
    \Trace_To       PduR-CDD-0182(0), PduR-CDD-5050(0), PduR-CDD-5307(0)
    \Trace_To       PduR-CDD-5110(0), PduR-CDD-5147(0), PduR-CDD-5148(0)
    \Trace_To       PduR-CDD-5173(0), PduR-CDD-5306(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidLoTpRxIndication(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    VAR(NotifResultType, AUTOMATIC)                             u8Result,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                         u8RtngType,
    P2CONST(PduR_tstrTpRxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf)
{
    VAR(uint16, AUTOMATIC)                                      u16GlblPduId;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)                 u16RouteGrp;
    #endif

    VAR(PduIdType, AUTOMATIC)                                   udtTargetId;
    VAR(uint8, AUTOMATIC)                                       u8DevIdx;

    P2CONST(PduR_tstrLoTpRxRTableType, AUTOMATIC, PDUR_CFG_CONST) 
                                                                pkstrRoute;
    P2CONST(PduR_tstrTp2UpRxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST) 
                                                                pkstrRxIndFp;

    /*! API parameters checking was already performed by the caller           */

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either
            minimum or normal routing as per the value of u8RtngType          */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute      = &pkstrTblsRf->pkstrMinRRxTRf[udtId];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrRxIndFp    = &pkstrTblsRf->pkstrMinRxFnTblRf[u8DevIdx];
        }
        else        /* u8NORMAL_ROUTING_ID                                    */
        {
            /*! Prepare the target information for normal routing             */
            pkstrRoute      = &pkstrTblsRf->pkstrNrmRRxTRf[udtId - 
                                                pkstrTblsRf->u16MinRxTSize];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrRxIndFp    = &pkstrTblsRf->pkstrNrmRxFnTblRf[u8DevIdx];
        }

        /*! Check that routing group is enabled                               */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp = pkstrRoute->u16RPathGrpId;
        if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
        #endif
        {
            /*! Identify the target ID used in forwarding the call            */
            /*! \Trace_To   PduR-CDD-5063(0)                                  */
            udtTargetId     = pkstrRoute->udtUpPduRefId;

            /*! Call the target function (forward the call)                   */
            /*! \Trace_To   PduR-CDD-0022(0), PduR-CDD-0023(0)
                \Trace_To   PduR-CDD-0107(0)                                  */
            pkstrRxIndFp->pfvidUpTpRxIndication(udtTargetId, u8Result);

            /*! Grab the global IPDU ID and set it to IDLE                    */
            u16GlblPduId    = pkstrRoute->u16IPduGlobalId;
            PduR_au8eGlblPduState[u16GlblPduId] = PduR_u8IDLE;
        }
        /*! Even if routing is disabled, the global ID must be set to IDLE    */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        else
        {
            /*! Grab the global IPDU ID and set it to IDLE                    */
            u16GlblPduId    = pkstrRoute->u16IPduGlobalId;
            PduR_au8eGlblPduState[u16GlblPduId] = PduR_u8IDLE;
        }
        #endif
    }
}

/******************************************************************************/
/*! \Description    Handles the copying of Tx data of a frame on the transport 
                    protocol layer to a lower module and acts accordingly \n
    \return         BUFREQ_OK, BUFREQ_E_NOT_OK, BUFREQ_E_BUSY \n
    \Trace_To       PduR-CDD-0184(0), PduR-CDD-5040(0), PduR-CDD-5051(0)
    \Trace_To       PduR-CDD-5112(0), PduR-CDD-5310(0), PduR-CDD-5151(0)
*******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_enuLoTpCopyTxData(
    VAR(PduIdType, AUTOMATIC)                                   udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)               pstrInfo,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA)             pstrRetry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)             pudtAvData,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                         u8RtngType,
    P2CONST(PduR_tstrTpTxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf)
{
    VAR(BufReq_ReturnType, AUTOMATIC)                           enuFuncRet;

    VAR(uint16, AUTOMATIC)                                      u16GlblPduId;
    VAR(PduIdType, AUTOMATIC)                                   udtTargetId;
    VAR(uint8, AUTOMATIC)                                       u8DevIdx;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)                 u16RouteGrp;
    #endif

    P2CONST(PduR_tstrLoTpTxRTableType, AUTOMATIC, PDUR_CFG_CONST) 
                                                                pkstrRoute;
    P2CONST(PduR_tstrTp2UpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST) 
                                                                pkstrCopyTxFp;

    /*! API parameters checking was already performed by the caller           */

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either
            minimum or normal routing as per the value of u8RtngType          */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute      = &pkstrTblsRf->pkstrMinRTxTRf[udtPduId];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrCopyTxFp   = &pkstrTblsRf->pkstrMinTxFnTblRf[u8DevIdx];
        }
        else        /* u8NORMAL_ROUTING_ID                                    */
        {
            /*! Prepare the target information for normal routing             */
            pkstrRoute      = &pkstrTblsRf->pkstrNrmRTxTRf[udtPduId
                                            - pkstrTblsRf->u16MinTxTSize];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrCopyTxFp   = &pkstrTblsRf->pkstrNrmTxFnTblRf[u8DevIdx];
        }

        /*! Grab the global IPDU ID, routing path group                       */
        u16GlblPduId    = pkstrRoute->u16IPduGlobalId;

        /*! Check that IPDU is INPROGRESS & routing group is enabled          */
        /*! \Trace_To   PduR-CDD-5072(0), PduR-CDD-5206(0)                    */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp = pkstrRoute->u16RPathGrpId;

        if( (PduR_au8eGlblPduState[u16GlblPduId] == PduR_u8INPROGRESS)
            &&  (PduR_abeRGrpStatus[u16RouteGrp] != FALSE))
        #else
        if(PduR_au8eGlblPduState[u16GlblPduId] == PduR_u8INPROGRESS)
        #endif
        {
            /*! Identify the target ID used in forwarding the call            */
            /*! \Trace_To   PduR-CDD-5065(0)                                  */
            udtTargetId     = pkstrRoute->udtUpPduRefId;

            /*! Call the target function (forward the call)                   */
            /*! \Trace_To   PduR-CDD-0041(0), PduR-CDD-0042(0)                */
            enuFuncRet = pkstrCopyTxFp->pfenuUpTpCopyTxData(
                            udtTargetId, pstrInfo, pstrRetry, pudtAvData);
        }
        else
        {
            /*! An error occured that caused the Global IPDU state to
                be IDLE, accordingly, set the return type to NOT_OK           */
            enuFuncRet = BUFREQ_E_NOT_OK;
        }
    }
    else
    {
        enuFuncRet = BUFREQ_E_NOT_OK;
    }

    return enuFuncRet;
}

/******************************************************************************/
/*! \Description    Function responsible for handling the TxConfirmation over Tp
                    from lower layers and passing it to upper layers (in case of
                    a multicast or gateway operation) the confirmation is passed
                    to another functions that deals with this
    \return         void \n
    \Trace_To       PduR-CDD-0185(0), PduR-CDD-5052(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidLoTpTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                                   udtId,
    VAR(NotifResultType, AUTOMATIC)                             u8Result,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                         u8RtngType,
    P2CONST(PduR_tstrTpTxRefType, AUTOMATIC, PDUR_VAR)   pkstrTblsRf)
{
    VAR(PduIdType, AUTOMATIC)                                   udtTargetId;
    VAR(uint8, AUTOMATIC)                                       u8DevIdx;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)                 u16RouteGrp;
    #endif

    VAR(uint16, AUTOMATIC)                                      u16GlblPdu;

    P2CONST(PduR_tstrLoTpTxRTableType, AUTOMATIC, PDUR_CFG_CONST)
                                                                pkstrRoute;
    P2CONST(PduR_tstrTp2UpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                                pkstrTxConfFp;

    /*! API parameters checking was already performed by the caller           */

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either
            minimum or normal routing as per the value of u8RtngType          */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute      = &pkstrTblsRf->pkstrMinRTxTRf[udtId];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrTxConfFp   = &pkstrTblsRf->pkstrMinTxFnTblRf[u8DevIdx];
        }
        else        /* u8NORMAL_ROUTING_ID                                    */
        {
            /*! Prepare the target information for normal routing             */
            pkstrRoute      = &pkstrTblsRf->pkstrNrmRTxTRf[udtId 
                                            - pkstrTblsRf->u16MinTxTSize];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrTxConfFp   = &pkstrTblsRf->pkstrNrmTxFnTblRf[u8DevIdx];
        }

        /*! Grab the routing path group and global IPDU ID                    */
        u16GlblPdu  = pkstrRoute->u16IPduGlobalId;

        /*! Check that routing group is enabled                               */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp = pkstrRoute->u16RPathGrpId;
        if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
        #endif
        {
            /*! Identify the target ID used in forwarding the call            */
            /*! \Trace_To   PduR-CDD-5066(0)                                  */
            udtTargetId     = pkstrRoute->udtUpPduRefId;

            /*! Call the target function (forward the call)                   */
            /*! \Trace_To   PduR-CDD-0043(0)                                  */
            pkstrTxConfFp->pfvidUpTpTxConf(udtTargetId, u8Result);

            /*! Set the global IPDU state to IDLE as Tx is confirmed          */
            PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;
        }
        /*! Even if routing is disabled, the global ID must be set to IDLE    */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        else
        {
            /*! Set the global IPDU state to IDLE as Tx is confirmed          */
            PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;
        }
        #endif
    }
}

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if(PduR_bTPLO_ENABLED == STD_ON) */

#endif /* #if (PduR_bZERO_COST_OPERATION == STD_OFF) */

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */

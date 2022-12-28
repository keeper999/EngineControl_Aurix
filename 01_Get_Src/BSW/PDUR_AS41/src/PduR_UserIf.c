/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !File            : PduR_UserIf.c                                           */
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
/* $Revision::   1.48     $$Author::   sedrees        $$Date::   Aug 24 2014 $*/
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
#include "PduR_Main.h"
#include "PduR_UserIf.h"

#include "SchM_PduR.h"

#include "PduR_Cfg.h"

#if (PduR_bZERO_COST_OPERATION == STD_OFF)

#if(PduR_bIFLO_ENABLED == STD_ON)

#include "PduR_LocalCfg.h"

#if(PduR_bDEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#include "Dem.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Minimum value to be configured for a FIFO buffer \n
    \Range          0x01
*******************************************************************************/
#define u8FIFO_MIN_VALUE            0x01

/******************************************************************************/
/*! \Description    Minimum frame length used in case of triggered gatewaying
                    communication is present and byte stuffing is enabled \n
    \Range          0x08
*******************************************************************************/
#if(PduR_bSTUFFING_SUPPORTED == STD_ON)
#define u8TRGRD_FRAME_SIZE          0x08
#endif

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/* !Deviation : Inhibit MISRA rule: Implemented as a macro for readability    */
/* PRQA S 3453 ++                                                             */

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         IF Tx Conf/Trigger Tx function pointers entries for u8Id \n
*******************************************************************************/
#define         pkstrIF_UP_TBL(u8Id)                                           \
                (&(PduR_pkstrePbCfg->pkstrIf2UpTxFuncTable[u8Id]))

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         IF Tx function pointers entries for u8Id \n
*******************************************************************************/
#define         pkstrIF_TX_TBL(u8Id)                                           \
                (&(PduR_pkstrePbCfg->pkstrIfTxFuncTable[u8Id]))

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         IF gatewaying entry identified by u8Id \n
*******************************************************************************/
#define         astrGATE_IF_TBL(u8Id)                                          \
                (PduR_pkstrePbCfg->pkstrGateIfRTable[u8Id])

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         Multi Up RX entry identified by u8Id \n
*******************************************************************************/
#define         astrMULTRX_IF_TBL(u8Id)                                        \
                (PduR_pkstrePbCfg->pkstrMultiUpRxRTable[u8Id])

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         IF Rx function pointers entries for u8Id \n
*******************************************************************************/
#define         pkstrIF_RX_TBL(u8Id)                                           \
                (&(PduR_pkstrePbCfg->pkstrIf2UpRxFuncTable[u8Id]))

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         IF multicasting entry identified by u8Id \n
*******************************************************************************/
#define         astrMULTI_IF_TBL(u8Id)                                         \
                (PduR_pkstrePbCfg->pkstrMultiIfRTable[u8Id])

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         IF multicasting sub-table entry identified by u8Id \n
*******************************************************************************/
#define         astrMULTI_IF_SUB_TBL(u8Id)                                     \
                (PduR_pkstrePbCfg->pkstrMultiIfSubRT[u8Id])

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


/* Tx Buffer Functions */
/* ******************* */
#if(PduR_bGATEWAYING_IF == STD_ON)
static FUNC(void, PDUR_CODE) vidTxBuffAdd(
    VAR(PduIdType, AUTOMATIC)                                     udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)                 pstrInfo,
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)  pkstrTxBuff);

static FUNC(void, PDUR_CODE) vidTxBuffRead(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)  pkstrTxBuff,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)                 pstrPduInfo,
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)                        pudtPduId);

static FUNC(void, PDUR_CODE) vidTxBuffPop(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)  pkstrTxBuff);

static FUNC(Std_ReturnType, PDUR_CODE) u8TxBuffReadPduId(
    VAR(PduIdType, AUTOMATIC)                                     udtPduId,
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)  pkstrTxBuff,
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)                        pudtGPduId);

static FUNC(void, PDUR_CODE) vidTxBuffPopUndo(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)  pkstrTxBuff);

static FUNC(boolean, PDUR_CODE) bTxBuffIsEmpty(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)  pkstrTxBuff);

static FUNC(boolean, PDUR_CODE) bTxBuffIsFull(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)  pkstrTxBuff);

/* Others Functions */
/* **************** */
static FUNC(void, PDUR_CODE) vidHandleNextTx(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)  pkstrTxBuff,
    VAR(uint16, AUTOMATIC)                                        u16TxCnfGId);

static FUNC(void, PDUR_CODE) vidHandleDirectRxInd(
    VAR(PduIdType, AUTOMATIC)                                     udtGtTblIdx,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)                 pstrPduInfo,
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)  pkstrTxBuff);

static FUNC(void, PDUR_CODE) vidHandleTrigrdRxInd(
    VAR(PduIdType, AUTOMATIC)                                     udtGtTblIdx,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)                 pstrPduInfo,
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)  pkstrTxBuff);

static FUNC(void, PDUR_CODE) vidHandleUpperRxInd(
    VAR(PduIdType, AUTOMATIC)                                     udtGtTblIdx,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)                 pstrPduInfo);
#endif

static FUNC(PduR_tu8RoutingType, PDUR_CODE) u8StatusChecker(
    VAR(PduIdType, AUTOMATIC)                                     udtPduId,
    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
    VAR(uint8, AUTOMATIC)                                         u8ApiId,
    #endif
    VAR(uint16, AUTOMATIC)                                        u16MinRTSize,
    VAR(uint16, AUTOMATIC)                                        u16NrmRTSize);

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

#if(PduR_bGATEWAYING_IF == STD_ON)
/******************************************************************************/
/*! \Description    Local function to add a new entry in the FIFO buffer \n
    \return         void \n
*******************************************************************************/
static FUNC(void, PDUR_CODE) vidTxBuffAdd(
    VAR(PduIdType, AUTOMATIC)                                       udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)                   pstrInfo,
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)    pkstrTxBuff)
{
    VAR(uint8, AUTOMATIC)             u8FIFOCurr;
    VAR(uint8_least, AUTOMATIC)       u8LoopIdx;
    VAR(uint8, AUTOMATIC)             u8CopyStart;
    VAR(uint8, AUTOMATIC)             u8LenToStore;
    VAR(uint8, AUTOMATIC)             u8BufferDepth;
    VAR(boolean, AUTOMATIC)           bBuffStatus;

    bBuffStatus = bTxBuffIsFull(pkstrTxBuff);

    if(bBuffStatus != FALSE)
    {
        /*! Flush FIFO buffer (clear buffer)                                  */
        PduR_vidTxBuffClear(pkstrTxBuff);

        /*! Report PDUR_E_PDU_INSTANCE_LOST to DEM module                     */
        Dem_ReportErrorStatus(  PDUR_E_PDU_INSTANCE_LOST,
                                DEM_EVENT_STATUS_FAILED);
    }
    else
    {
        /*! Do Nothing, copying will be done as the buffer was cleared        */
    }

    /*! Copy the buffer depth to a local variable for faster execution        */
    u8BufferDepth = pkstrTxBuff->u8BuffDepth;

    /*! Protection needed againest data consistency                           */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is                  */
    /*              to be implemented during integration phase                */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_PduR(PduR_TX_BUFF_CTRL_RX);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */

    /*! Increment the counter of the last FIFO entry in the used buffer       */
    u8FIFOCurr = pkstrTxBuff->pstrBuffCtrl->u8Last;

    u8FIFOCurr++;
    u8FIFOCurr = (uint8) (u8FIFOCurr % u8BufferDepth);

    pkstrTxBuff->pstrBuffCtrl->u8Last = u8FIFOCurr;

    /*! Clear critical section                                                */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_PduR(PduR_TX_BUFF_CTRL_RX);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */

    /*! \Trace_To   PduR-CDD-0061(0)                                          */
    if(pstrInfo->SduLength <= pkstrTxBuff->u8BuffLength)
    {
        u8LenToStore = (uint8) pstrInfo->SduLength;
    }
    else
    {
        u8LenToStore        = pkstrTxBuff->u8BuffLength;
        pstrInfo->SduLength = (PduLengthType) u8LenToStore;
    }

    /*! Copy the header to the corressponding FIFO entry in the buffer        */
    pkstrTxBuff->pstrTxBuffOfHdr[u8FIFOCurr].udtPduId  = udtPduId;
    pkstrTxBuff->pstrTxBuffOfHdr[u8FIFOCurr].udtPduLen = u8LenToStore;

    /*! Define the start index to start copying to                            */
    u8CopyStart = u8FIFOCurr * pkstrTxBuff->u8BuffLength;

    /* bug: 47883 - removed un-needed code part                               */
    /*! Copy the data to the corressponding FIFO entry in the buffer          */
    for(u8LoopIdx = 0; u8LoopIdx < u8LenToStore; u8LoopIdx++)
    {
        pkstrTxBuff->pu8TxBuffOfData[u8CopyStart + u8LoopIdx]
                                    = pstrInfo->SduDataPtr[u8LoopIdx];
    }

    /*! Increment FIFO buffer counter (used to check afterwards)              */
    pkstrTxBuff->pstrBuffCtrl->u8Count++;
}

/******************************************************************************/
/*! \Description    Local function to read an entry from the FIFO buffer \n
    \return         void \n
    \Trace_To       PduR-CDD-0073(0), PduR-CDD-0074(0)
*******************************************************************************/
static FUNC(void, PDUR_CODE) vidTxBuffRead(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)    pkstrTxBuff,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)                   pstrPduInfo,
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)                          pudtPduId)
{
    VAR(uint8, AUTOMATIC)                   u8FIFOCurr;
    VAR(PduLengthType , AUTOMATIC)          udtLoopIdx;
    VAR(PduLengthType , AUTOMATIC)          udtCopySize;
    VAR(PduLengthType , AUTOMATIC)          udtCopyStart;
    VAR(boolean, AUTOMATIC)                 bBuffStatus;

    u8FIFOCurr  = pkstrTxBuff->pstrBuffCtrl->u8First;
    bBuffStatus = bTxBuffIsEmpty(pkstrTxBuff);

    if(bBuffStatus == FALSE)
    {
        /*! Copy the PDU-ID to the passed pointer                             */
        (*pudtPduId) = pkstrTxBuff->pstrTxBuffOfHdr[u8FIFOCurr].udtPduId;

        /*! Define the start index to start copying from                      */
        udtCopyStart = u8FIFOCurr * pkstrTxBuff->u8BuffLength;

        /*! Define the number of bytes to be copied (shall be the size of the 
            message and it is the role of the configurator to make sure that the
            ptr to be passed is able to hold the messege length) - bug: 46830 */
        udtCopySize = pkstrTxBuff->pstrTxBuffOfHdr[u8FIFOCurr].udtPduLen;

        /*! Set the buffer length to the value of the CopySize temp variable  */
        pstrPduInfo->SduLength = udtCopySize;

        /*! Copy the actual data to the passed pointer                        */
        for(udtLoopIdx = 0; udtLoopIdx < udtCopySize; udtLoopIdx++)
        {
            pstrPduInfo->SduDataPtr[udtLoopIdx] =
                        pkstrTxBuff->pu8TxBuffOfData[udtCopyStart + udtLoopIdx];
        }
    }
    else
    {
        pstrPduInfo->SduLength  = 0x00;
        (*pudtPduId)            = 0x00;
    }
}

/******************************************************************************/
/*! \Description    Removes the oldest entry from the FIFO buffer by just
                    updating the counters (fixing buffer's control data) rather
                    than returning the data. Used when no need to grab actual
                    data from the Tx buffer (e.g.: Tx confirmation). \n
    \return         void \n
*******************************************************************************/
static FUNC(void, PDUR_CODE) vidTxBuffPop(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)    pkstrTxBuff)
{
    VAR(uint8, AUTOMATIC)       u8FIFOCurr;
    VAR(uint8, AUTOMATIC)       u8BufferDepth;
    VAR(boolean, AUTOMATIC)     bBuffStatus;

    /*! Copy the buffer depth to a local variable for faster execution        */
    u8BufferDepth = pkstrTxBuff->u8BuffDepth;

    /*! Protection needed againest data consistency                           */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is                  */
    /*              to be implemented during integration phase                */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_PduR(PduR_TX_BUFF_CTRL_TX);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */

    u8FIFOCurr  = pkstrTxBuff->pstrBuffCtrl->u8First;
    bBuffStatus = bTxBuffIsEmpty(pkstrTxBuff);

    if(bBuffStatus == FALSE)
    {
        /*! Set first counter to point to the next entry                      */
        u8FIFOCurr = (uint8) ((u8FIFOCurr + 1) % u8BufferDepth);
        pkstrTxBuff->pstrBuffCtrl->u8First = u8FIFOCurr;

        /*! Decrement FIFO buffer counter (used to check afterwards)          */
        pkstrTxBuff->pstrBuffCtrl->u8Count--;
    }

    /*! Clear critical section                                                */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_PduR(PduR_TX_BUFF_CTRL_TX);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */
}

/******************************************************************************/
/*! \Description    Removes the newest (just added) entry from the FIFO buffer 
                    by updating the counters (fixing buffer's control data).
                    Used in case of a Tx error to remove the errornous data \n
    \return         void \n
*******************************************************************************/
static FUNC(void, PDUR_CODE) vidTxBuffPopUndo(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)    pkstrTxBuff)
{
    VAR(uint8, AUTOMATIC)           u8FIFOCurr;
    VAR(uint8, AUTOMATIC)           u8BufferDepth;
    VAR(boolean, AUTOMATIC)         bBuffStatus;

    /*! Copy the buffer depth to a local variable for faster execution        */
    u8BufferDepth = pkstrTxBuff->u8BuffDepth;

    /*! Protection needed againest data consistency                           */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is                  */
    /*              to be implemented during integration phase                */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_PduR(PduR_TX_BUFF_CTRL_RX);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */

    u8FIFOCurr  = pkstrTxBuff->pstrBuffCtrl->u8Last;
    bBuffStatus = bTxBuffIsEmpty(pkstrTxBuff);

    if(bBuffStatus == FALSE)
    {
        /*! Set last counter to point to the previous entry                   */
        if(u8FIFOCurr == 0)
        {
            /*! Protect against subtracting 1 from 0, u8Last should be as
                the case of buffer initialization                             */
            u8FIFOCurr = u8BufferDepth - 1;
        }
        else
        {
            /*! u8Last !=0, decrement it normally                             */
            u8FIFOCurr = u8FIFOCurr - 1;
        }

        pkstrTxBuff->pstrBuffCtrl->u8Last = u8FIFOCurr;

        /*! Decrement FIFO buffer counter (used to check afterwards)          */
        pkstrTxBuff->pstrBuffCtrl->u8Count--;
    }
    else
    {
        /*! Do nothing, empty buffer                                          */
    }

    /*! Clear critical section                                                */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_PduR(PduR_TX_BUFF_CTRL_RX);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */
}

/******************************************************************************/
/*! \Description    Returns the IPDU ID of the oldest FIFO entry present \n
    \return         void \n
*******************************************************************************/
static FUNC(Std_ReturnType, PDUR_CODE) u8TxBuffReadPduId(
    VAR(PduIdType, AUTOMATIC)                                     udtPduId,
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)  pkstrTxBuff,
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)                        pudtGPduId)
{
    VAR(uint8, AUTOMATIC)               u8FIFOCurr;
    VAR(Std_ReturnType, AUTOMATIC)      u8FuncRet;

    u8FIFOCurr  = pkstrTxBuff->pstrBuffCtrl->u8First;

    /*! Return the Pdu Id of the oldest FIFO entry and return OK              */
    (*pudtGPduId) = pkstrTxBuff->pstrTxBuffOfHdr[u8FIFOCurr].udtPduId;

    if((*pudtGPduId) == udtPduId)
    {
        u8FuncRet = E_OK;
    }
    else
    {
        u8FuncRet = E_NOT_OK;
    }

    return u8FuncRet;
}

/******************************************************************************/
/*! \Description    Check if the FIFO buffer is empty or not \n
    \return         void \n
*******************************************************************************/
static FUNC(boolean, PDUR_CODE) bTxBuffIsEmpty(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)    pkstrTxBuff)
{
    VAR(boolean, AUTOMATIC)     bReturn;

    if(pkstrTxBuff->pstrBuffCtrl->u8Count == 0)
    {
        bReturn = TRUE;
    }
    else
    {
        bReturn = FALSE;
    }

    return bReturn;
}

/******************************************************************************/
/*! \Description    Check if the FIFO buffer is full or not \n
    \return         void \n
*******************************************************************************/
static FUNC(boolean, PDUR_CODE) bTxBuffIsFull(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)    pkstrTxBuff)
{
    VAR(boolean, AUTOMATIC)     bReturn;

    if(pkstrTxBuff->pstrBuffCtrl->u8Count == pkstrTxBuff->u8BuffDepth)
    {
        bReturn = TRUE;
    }
    else
    {
        bReturn = FALSE;
    }

    return bReturn;
}

/******************************************************************************/
/*! \Description    Handles the transmission of any further requests stored in
                    the IF buffer (after a TxConf or TriggerTx requests) \n
    \return         void \n
*******************************************************************************/
static FUNC(void, PDUR_CODE) vidHandleNextTx(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)    pkstrTxBuff,
    VAR(uint16, AUTOMATIC)                                          u16TxCnfGId)
{
    VAR(boolean, AUTOMATIC)                     bBuffStatus;
    VAR(boolean, AUTOMATIC)                     bNextTxOK;

    VAR(PduIdType, AUTOMATIC)                   udtTxPduId;
    VAR(Std_ReturnType, AUTOMATIC)              u8TxFnRet;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC) u16RouteGrp;
    #endif

    VAR(uint8, AUTOMATIC)                       u8DevIdx;
    VAR(uint16, AUTOMATIC)                      u16GlblPdu;

    VAR(PduInfoType, AUTOMATIC)                 strGtPduInfo;
    VAR(PduIdType, AUTOMATIC)                   udtGtPduId;
    VAR(uint8, AUTOMATIC)                       au8Data[PduR_u8GTWYIF_MAX_SIZE];

    P2CONST(PduR_tstrIfTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)
                                                pkstrIfTxFp;

    #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
    VAR(boolean, AUTOMATIC)                     bGWStatus;
    #endif

    /*! Check if buffer is empty or not, initialize NextTxOK variable         */
    bBuffStatus = bTxBuffIsEmpty(pkstrTxBuff);
    bNextTxOK   = FALSE;

    /*! If buffer is not empty and the buffer FIFO type is deferred, start
        handling the consecutive entries in the IF buffer accordingly         */
    if( (bBuffStatus == FALSE) &&
        (pkstrTxBuff->u8BuffFIFOType == PduR_u8DEFERRED))
    {
        while((bNextTxOK == FALSE) && (bBuffStatus == FALSE))
        {
            /*! Remove another entry from buffer & prepare it for Tx          */
            strGtPduInfo.SduDataPtr = au8Data;
            strGtPduInfo.SduLength  = PduR_u8GTWYIF_MAX_SIZE;
            vidTxBuffRead(pkstrTxBuff, &strGtPduInfo, &udtGtPduId);

            /*! Prepare the destination and routing group ids                 */
            u16GlblPdu  = astrGATE_IF_TBL(udtGtPduId).u16IPduGlobalId;
            u8DevIdx    = astrGATE_IF_TBL(udtGtPduId).u8DstPduDeviceId;
            udtTxPduId  = astrGATE_IF_TBL(udtGtPduId).udtDstPduRefId;

            /*! Prepare the transmit function pointer                         */
            pkstrIfTxFp = pkstrIF_TX_TBL(u8DevIdx);

            /*! Call the tranmission function                                 */
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            u16RouteGrp = astrGATE_IF_TBL(udtGtPduId).u16RPathGrpId;
            if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
            #endif
            {
                /*! Set global PDU state to TOBEHANDLED in case of having the
                    same ID to be Tx'ed again, otherwise set to INPROGRESS    */
                if(u16GlblPdu == u16TxCnfGId)
                {
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8TOBEHANDLED;
                }
                else
                {
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8INPROGRESS;
                }

                #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
                /*! If call-outs are supported, perform the call-out check
                    before calling the destination's transmit API             */
                /*! \Trace_To   PduR-CDD-5401(0), PduR-CDD-5402(0)            */
                /*              PduR-CDD-5407(0), PduR-CDD-5408(0)            */
                if( astrGATE_IF_TBL(udtGtPduId).pfbGateCallOut !=
                                            (PduR_tpfbGateCallOut) NULL_PTR )
                {
                    bGWStatus = astrGATE_IF_TBL(udtGtPduId).pfbGateCallOut(
                                udtTxPduId, (const PduInfoType*) &strGtPduInfo);
                }
                else
                {
                    bGWStatus = TRUE;
                }

                /*! If call-out returned TRUE, proceed with transmission      */
                if(bGWStatus == TRUE)
                #endif
                {
                    u8TxFnRet = pkstrIfTxFp->pfu8IfTransmit(
                                                    udtTxPduId, &strGtPduInfo);
                }
                #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
                /*! If call-out returned FALSE, terminate the transmission    */
                else
                {
                    u8TxFnRet = E_NOT_OK;
                }
                #endif

                if(u8TxFnRet == E_OK)
                {
                    if((astrGATE_IF_TBL(udtGtPduId).bTxConfirmation == TRUE) ||
                       (astrGATE_IF_TBL(udtGtPduId).u8DataProvision
                                                        == PduR_u8TRIGGERED))
                    {
                        /*! Terminate the loop operation and keep the entry in
                            the FIFO till either TTx or TxConf are received   */
                        bNextTxOK = TRUE;
                    }
                }
                else
                {
                    /*! Set global PDU state to IDLE                          */
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                    /*! Transmission of this request failed, pop it out of FIFO
                        and serve the next one in the list                    */
                    vidTxBuffPop(pkstrTxBuff);
                }
            }
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            else
            {
                /*! Routing group of this entry is disabled, set the global PDU
                    state to IDLE and pop it out from the FIFO buffer to start
                    serving the following requests (if exist)                 */
                PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;
                vidTxBuffPop(pkstrTxBuff);
            }
            #endif

            /*! Check if the buffer is now empty or not                       */
            bBuffStatus = bTxBuffIsEmpty(pkstrTxBuff);
        }
    }
    else
    {
        /*! Do nothing                                                        */
    }
}

/* !Deviation : Inhibit MISRA rule: STCYC (Cyclomatic Complexity) and STPTH   */
/*              (Estimated Path Count) are needed to fullfill the needed      */
/*              functionality of the API and can be reduced if not all the    */
/*              features are enabled in the PDUR.                             */
/*              No further simplification is needed.                          */
/* PRQA S 4700 ++                                                             */

/******************************************************************************/
/*! \Description    Handles IF gatewaying operation in case of direct data 
                    provision is configured \n
    \return         void \n
*******************************************************************************/
static FUNC(void, PDUR_CODE) vidHandleDirectRxInd(
    VAR(PduIdType, AUTOMATIC)                                       udtGtTblIdx,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)                   pstrPduInfo,
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)    pkstrTxBuff)
{
    VAR(uint16, AUTOMATIC)                                  u16GlblPdu;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    VAR(PduIdType, AUTOMATIC)                               udtTargetId;
    VAR(Std_ReturnType, AUTOMATIC)                          u8TxFnRet;
    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    P2CONST(PduR_tstrIfTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrIfTxFp;

    #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
    VAR(boolean, AUTOMATIC)                                 bGWStatus;
    #endif

    /*! Prepare the destination, routing group and global ids                 */
    udtTargetId     = astrGATE_IF_TBL(udtGtTblIdx).udtDstPduRefId;
    u16GlblPdu      = astrGATE_IF_TBL(udtGtTblIdx).u16IPduGlobalId;
    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    u16RouteGrp     = astrGATE_IF_TBL(udtGtTblIdx).u16RPathGrpId;
    #endif

    /*! Prepare the transmit function pointer                                 */
    u8DevIdx    = astrGATE_IF_TBL(udtGtTblIdx).u8DstPduDeviceId;
    pkstrIfTxFp = pkstrIF_TX_TBL(u8DevIdx);

    /*! Check if there is a FIFO buffer configured or not                     */
    if(pkstrTxBuff->u8BuffDepth < u8FIFO_MIN_VALUE)
    {
        /*! No FIFO configured, call Transmit & don't buffer if transmission
            is enabled on the destination                                     */

        /*! Set global I-PDU state to INPROGRESS if confirmation is enabled   */
        if (astrGATE_IF_TBL(udtGtTblIdx).bTxConfirmation == TRUE)
        {
            PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8INPROGRESS;
        }

        #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
        /*! If call-outs are supported, perform the call-out check before
            calling the destination's transmit API                            */
        if( astrGATE_IF_TBL(udtGtTblIdx).pfbGateCallOut !=
                                            (PduR_tpfbGateCallOut) NULL_PTR )
        {
            bGWStatus = astrGATE_IF_TBL(udtGtTblIdx).pfbGateCallOut(
                                udtTargetId, (const PduInfoType*) pstrPduInfo);
        }
        else
        {
            bGWStatus = TRUE;
        }

        /*! If call-out returned TRUE, proceed with transmission              */
        if(bGWStatus == TRUE)
        #endif
        {
            /*! Call transmit function (no need to check routing group as this
                was done already by the caller function)                      */
            u8TxFnRet = pkstrIfTxFp->pfu8IfTransmit(udtTargetId, pstrPduInfo);
        }
        #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
        /*! If call-out returned FALSE, terminate the transmission            */
        else
        {
            u8TxFnRet = E_NOT_OK;
        }
        #endif

        /*! Set global PDU state to IDLE if transmission was NOK              */
        if (u8TxFnRet != E_OK)
        {
            PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;
        }
    }
    else
    {
        /*! Buffer the data received                                          */
        vidTxBuffAdd(udtGtTblIdx, pstrPduInfo, pkstrTxBuff);

        /*! If the FIFO buffer contains only one entry, serve this entry      */
        if( (pkstrTxBuff->pstrBuffCtrl->u8Count == 1) ||
            (pkstrTxBuff->u8BuffFIFOType == PduR_u8IMMEDIATE))
        {
            /*! Call Tx function - data already buffered                      */
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
            #endif
            {
                /*! Set global I-PDU state to INPROGRESS if confirmation is 
                    enable                                                    */
                if(astrGATE_IF_TBL(udtGtTblIdx).bTxConfirmation == TRUE)
                {
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8INPROGRESS;
                }

                #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
                /*! If call-outs are supported, perform the call-out check
                    before calling the destination's transmit API             */
                if( astrGATE_IF_TBL(udtGtTblIdx).pfbGateCallOut !=
                                            (PduR_tpfbGateCallOut) NULL_PTR )
                {
                    bGWStatus = astrGATE_IF_TBL(udtGtTblIdx).pfbGateCallOut(
                                udtTargetId, (const PduInfoType*) pstrPduInfo);
                }
                else
                {
                    bGWStatus = TRUE;
                }

                /*! If call-out returned TRUE, proceed with transmission      */
                if(bGWStatus == TRUE)
                #endif
                {
                    u8TxFnRet = pkstrIfTxFp->pfu8IfTransmit(
                                                    udtTargetId, pstrPduInfo);
                }
                #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
                /*! If call-out returned FALSE, terminate the transmission    */
                else
                {
                    u8TxFnRet = E_NOT_OK;
                }
                #endif

                /*! Set global I-PDU state to IDLE if transmission was NOK    */
                if(u8TxFnRet != E_OK)
                {
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                    /*! Remove entry from buffer                              */
                    vidTxBuffPopUndo(pkstrTxBuff);
                }
            }
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            else
            {
                /*! No transmission - remove entry from buffer                */
                vidTxBuffPopUndo(pkstrTxBuff);
            }
            #endif
        }
        else
        {
            /*! Do nothing                                                    */
        }
    }
}

/* PRQA S 4700 --                                                             */

/******************************************************************************/
/*! \Description    Handles IF gatewaying operation in case of triggered data 
                    provision is configured \n
    \return         void \n
*******************************************************************************/
static FUNC(void, PDUR_CODE) vidHandleTrigrdRxInd(
    VAR(PduIdType, AUTOMATIC)                                       udtGtTblIdx,
    /* !Deviation : Inhibit MISRA rule: Prototype is indirectly inforced by   */
    /*              AUTOSAR to comply with the caller's prototype             */
    /* PRQA S 3673 ++                                                         */
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)                   pstrPduInfo,
    /* PRQA S 3673 --                                                         */
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)    pkstrTxBuff)
{
    VAR(uint16, AUTOMATIC)                          u16GlblPdu;
    VAR(PduIdType, AUTOMATIC)                       udtTargetId;
    VAR(Std_ReturnType, AUTOMATIC)                  u8TxFnRet;
    VAR(uint8, AUTOMATIC)                           u8DevIdx;
    VAR(PduInfoType, AUTOMATIC)                     strNewPduInfo;

    P2CONST(PduR_tstrIfTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                    pkstrIfTxFp;

    #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
    VAR(boolean, AUTOMATIC)                         bGWStatus;
    #endif
    #if(PduR_bSTUFFING_SUPPORTED == STD_ON)
    VAR(uint8, AUTOMATIC)                           au8Data[u8TRGRD_FRAME_SIZE];
    VAR(uint8_least, AUTOMATIC)                     u8LoopIdx;
    #endif

    /*! Prepare the destination and global id (RGrp was checked before)       */
    udtTargetId     = astrGATE_IF_TBL(udtGtTblIdx).udtDstPduRefId;
    u16GlblPdu      = astrGATE_IF_TBL(udtGtTblIdx).u16IPduGlobalId;

    /*! Prepare the transmit function pointer                                 */
    u8DevIdx    = astrGATE_IF_TBL(udtGtTblIdx).u8DstPduDeviceId;
    pkstrIfTxFp = pkstrIF_TX_TBL(u8DevIdx);

    #if(PduR_bSTUFFING_SUPPORTED == STD_ON)
    /*! If byte stuffing is enabled, then check the frame size if it is lower
        that the frame-size needed (8 bytes). If so, stuff the frame with
        configured stuffing byte value                                        */
    /*! \Trace_To   PduR-CDD-5398(0)                                          */
    if(pstrPduInfo->SduLength < (PduLengthType) u8TRGRD_FRAME_SIZE)
    {
        /*! Copy the original data to the new array                           */
        for(    u8LoopIdx = 0;
                u8LoopIdx < (uint8) pstrPduInfo->SduLength;
                u8LoopIdx++)
        {
            au8Data[u8LoopIdx] = pstrPduInfo->SduDataPtr[u8LoopIdx];
        }

        /*! Stuff the remaining of the array with the configured byte value   */
        for(    u8LoopIdx = (uint8) pstrPduInfo->SduLength;
                u8LoopIdx < u8TRGRD_FRAME_SIZE;
                u8LoopIdx++)
        {
            au8Data[u8LoopIdx] = PduR_u8STUFFING_VALUE;
        }

        /*! Update the new pointer with the new values and size               */
        strNewPduInfo.SduLength     = u8TRGRD_FRAME_SIZE;
        strNewPduInfo.SduDataPtr    = au8Data;
    }
    /*! Otherwise, or when the stuffing is not supported, copy the pointer's
        data to the new pointer to work on it as if it is the original one    */
    else
    #endif
    {
        strNewPduInfo.SduLength     = pstrPduInfo->SduLength;
        strNewPduInfo.SduDataPtr    = pstrPduInfo->SduDataPtr;
    }

    /*! In TRIGGERED provision, a FIFO must be present and data shall be
        buffered once an indication arrives                                   */
    vidTxBuffAdd(udtGtTblIdx, &strNewPduInfo, pkstrTxBuff);

    /*! If the FIFO buffer contains only one entry, serve this entry      */
    if( (pkstrTxBuff->pstrBuffCtrl->u8Count == 1) ||
        (pkstrTxBuff->u8BuffFIFOType == PduR_u8IMMEDIATE))
    {
         /*! Call transmit function (no need to check routing group as this was
            done already by the caller function)                              */

        /*! Set global PDU state to INPROGRESS even if confirmation is 
            FALSE, data must be retained till receiving the trigger 
            transmit request                                                  */
        PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8INPROGRESS;

        #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
        /*! If call-outs are supported, perform the call-out check before
            calling the destination's transmit API                            */
        if( astrGATE_IF_TBL(udtGtTblIdx).pfbGateCallOut !=
                                            (PduR_tpfbGateCallOut) NULL_PTR )
        {
            bGWStatus = astrGATE_IF_TBL(udtGtTblIdx).pfbGateCallOut(
                            udtTargetId, (const PduInfoType*) &strNewPduInfo);
        }
        else
        {
            bGWStatus = TRUE;
        }

        /*! If call-out returned TRUE, proceed with transmission      */
        if(bGWStatus == TRUE)
        #endif
        {
            u8TxFnRet = pkstrIfTxFp->pfu8IfTransmit(
                                                udtTargetId, &strNewPduInfo);
        }
        #if(PduR_bCALLOUT_SUPPORTED == STD_ON)
        /*! If call-out returned FALSE, terminate the transmission            */
        else
        {
            u8TxFnRet = E_NOT_OK;
        }
        #endif

        /*! Set global PDU state to IDLE if Tx if NOK                         */
        if(u8TxFnRet != E_OK)
        {
            PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

            /*! Remove entry from buffer                                      */
            vidTxBuffPopUndo(pkstrTxBuff);
        }
    }
    else
    {
        /*! Enough for buffering the message, a trigger transmit request will
            later arrive to transmit the new entry in the FIFO buffer         */
    }
}

/******************************************************************************/
/*! \Description    Handles IF gatewaying operation in case of passing the data
                    to the upper layer (gatewaying to upper) \n
    \return         void \n
*******************************************************************************/
static FUNC(void, PDUR_CODE) vidHandleUpperRxInd(
    VAR(PduIdType, AUTOMATIC)                                       udtGtTblIdx,
    /* !Deviation : Inhibit MISRA rule: Prototype is indirectly inforced by   */
    /*              AUTOSAR to comply to <Up>_RxIndication prototype          */
    /* PRQA S 3673 ++                                                         */
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)                   pstrPduInfo)
    /* PRQA S 3673 --                                                         */
{
    VAR(PduIdType, AUTOMATIC)                                       udtTargetId;
    VAR(uint8, AUTOMATIC)                                           u8DevIdx;

    P2CONST(PduR_tstrIfTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)    pkstrIfTxFp;

    /*! Prepare target/destination ID (RGrp was previously checked)           */
    udtTargetId     = astrGATE_IF_TBL(udtGtTblIdx).udtDstPduRefId;

    /*! Prepare the transmit function pointer                                 */
    u8DevIdx    = astrGATE_IF_TBL(udtGtTblIdx).u8DstPduDeviceId;
    pkstrIfTxFp = pkstrIF_TX_TBL(u8DevIdx);
    
    /*! Call transmit function (no need to check routing group as this was done
        already by the caller function)                                       */
    (void) pkstrIfTxFp->pfu8IfTransmit(udtTargetId, pstrPduInfo);

    /*! No need to set the global IPDU state, as no confirmations shall be
        received for passing the messege to the upper layer                   */
}
#endif

/******************************************************************************/
/*! \Description    Local function to check the PduR module status \n
    \return         PduR_u8MINIMUM_ROUTING, PduR_u8NORMAL_ROUTING or 
                    PduR_u8INVALID_ROUTING \n
*******************************************************************************/
static FUNC(PduR_tu8RoutingType, PDUR_CODE) u8StatusChecker(
    VAR(PduIdType, AUTOMATIC)                               udtPduId,
    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
    VAR(uint8, AUTOMATIC)                                   u8ApiId,
    #endif
    VAR(uint16, AUTOMATIC)                                  u16MinRTSize,
    VAR(uint16, AUTOMATIC)                                  u16NrmRTSize)
{
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType;

    /*! Check module's initialization                                         */
    if(PduR_u8eState == PDUR_UNINIT)
    {
        /*! Report to DET if enabled, invalid request is passed               */
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError( PDUR_MODULE_ID, 
                                0, 
                                u8ApiId, 
                                PDUR_E_INVALID_REQUEST);
        #endif

        /*! Set routing type to INVALID                                       */
        u8RtngType = PduR_u8INVALID_ROUTING;
    }
    else
    {
        /*! Check the PduId is in specified range of minimum routing tables   */
        if(udtPduId < u16MinRTSize)
        {
            /*! Set routing type to MINIMUM                                   */
            u8RtngType = PduR_u8MINIMUM_ROUTING;
        }
        /*! Check the PduId is in specified range of normal routing tables    */
        else if( (PduR_u8eState == PDUR_ONLINE) && (udtPduId < (u16NrmRTSize 
                                                             + u16MinRTSize))  )
        {
            /*! Set routing type to NORMAL                                    */
            u8RtngType = PduR_u8NORMAL_ROUTING;
        }
        /*! PduId is in out of range                                          */
        else
        {
            /*! Set routing type to INVALID                                   */
            u8RtngType = PduR_u8INVALID_ROUTING;

            /*! Report to DET if enabled, Id is not in the valid range        */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID, 
                                    0, 
                                    u8ApiId, 
                                    PDUR_E_PDU_ID_INVALID);
            #endif
        }
    }

    return u8RtngType;
}

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/**************************************/
/* Interface Layers Gateway Functions */
/**************************************/

#if(PduR_bGATEWAYING_IF == STD_ON)
/******************************************************************************/
/*! \Description    IF gatewaying local function used to gateway the PDU to
                    one (or more) destination and buffer the data \n
    \return         void \n
    \Trace_To       PduR-CDD-0075(0), PduR-CDD-0076(0), PduR-CDD-5073(1)
    \Trace_To       PduR-CDD-5162(0), PduR-CDD-5074(0), PduR-CDD-5075(0)
    \Trace_To       PduR-CDD-5076(0), PduR-CDD-5077(0), PduR-CDD-5078(0)
    \Trace_To       PduR-CDD-5079(0), PduR-CDD-5080(0), PduR-CDD-5081(0)
    \Trace_To       PduR-CDD-5274(0), PduR-CDD-5316(0), PduR-CDD-5317(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidGateRxIndication(
    VAR(PduIdType, AUTOMATIC)                           udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)       pstrPduInfo)
{
    VAR(PduIdType, AUTOMATIC)                           udtGtTblIdx;
    VAR(PduIdType, AUTOMATIC)                           udtCtrlId;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)         u16RouteGrp;
    #endif

    VAR(PduLengthType, AUTOMATIC)                       udtActualLen;

    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)
                                                        pkstrTxBuff;

    /*! Check udtPduId is in specified range of normal routing tables or not
        (only normal routing as no gatewaying in reduced mode)                */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtPduId < PduR_pkstrePbCfg->udtGateIfRTSize))
    {
        /* bug: 47882 */
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        if( (pstrPduInfo != (PduInfoType *) NULL_PTR) && 
            (pstrPduInfo->SduDataPtr != (uint8 *) NULL_PTR) )
        #endif
        {
            /*! Set loop related local variables to their initial values      */
            udtGtTblIdx     = udtPduId;
            udtActualLen    = pstrPduInfo->SduLength;
            udtCtrlId       = astrGATE_IF_TBL(udtPduId).udtCntrlId;

            /*! Loop on all destinations to request their IfTransmit fns      */
            while(  (udtCtrlId == astrGATE_IF_TBL(udtGtTblIdx).udtCntrlId) &&
                    (udtGtTblIdx < PduR_pkstrePbCfg->udtGateIfRTSize))
            {

                /*! Get the routing path group to check the handling of req.  */
                #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
                u16RouteGrp = astrGATE_IF_TBL(udtGtTblIdx).u16RPathGrpId;
                if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
                #endif
                {
                    pkstrTxBuff = astrGATE_IF_TBL(udtGtTblIdx).pkstrTxBuffRef;

                    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
                    /*! Check if FIFO buffer is not NULL, if so, report to DET*/
                    if(     (pkstrTxBuff == 
                                    (const PduR_tstrTxBuffPCCfgType *) NULL_PTR)
                        &&  (astrGATE_IF_TBL(udtGtTblIdx).u8DataProvision != 
                                    PduR_u8UPPER))
                    {
                        (void) Det_ReportError( PDUR_MODULE_ID,
                                                0,
                                                astrGATE_IF_TBL(udtGtTblIdx)
                                                                .u8RxIndApiId,
                                                PDUR_E_NULL_POINTER);
                    }
                    else
                    #endif
                    {
                        switch(astrGATE_IF_TBL(udtGtTblIdx).u8DataProvision)
                        {
                            /*! Handle the FIFO buffering & transmission based
                                on different gatewaying types                 */
                            /*! \Trace_To   PduR-CDD-5399(0), PduR-CDD-5400(0)*/
                            case PduR_u8DIRECT:
                            {
                                vidHandleDirectRxInd(   udtGtTblIdx,
                                                        pstrPduInfo,
                                                        pkstrTxBuff);
                            }
                            break;
                            case PduR_u8TRIGGERED:
                            {
                                vidHandleTrigrdRxInd(   udtGtTblIdx,
                                                        pstrPduInfo,
                                                        pkstrTxBuff);
                            }
                            break;
                            case PduR_u8UPPER:
                            {
                                vidHandleUpperRxInd(    udtGtTblIdx,
                                                        pstrPduInfo);
                            }
                            break;
                            default:
                                /*! Do nothing */
                            break;
                        }
                    }
                }

                /*! Increment the gateway table index used                    */
                udtGtTblIdx++;

                /*! Set the length of the Pdu to the old actual length        */
                pstrPduInfo->SduLength = udtActualLen;
            }

        }
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        else
        {
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    astrGATE_IF_TBL(udtPduId).u8RxIndApiId,
                                    PDUR_E_NULL_POINTER);
        }
        #endif
    }
}

/******************************************************************************/
/*! \Description    IF gatewaying local function used to confirm a gateway 
                    operation to a certain destination and acts accordingly \n
    \return         void \n
    \Trace_To       PduR-CDD-0060(0), PduR-CDD-5082(0), PduR-CDD-5083(0)
    \Trace_To       PduR-CDD-5084(0), PduR-CDD-5276(0), PduR-CDD-5318(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidGateTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                       udtPduId)
{
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)    pkstrTxBuff;
    VAR(uint16, AUTOMATIC)                                          u16GlblPdu;

    /*! Check udtPduId is in specified range of normal routing tables or not
        (only normal routing as no gatewaying in reduced mode)                */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtPduId < PduR_pkstrePbCfg->udtGateIfRTSize))
    {
        /*! Grab the configured IF buffer & Global ID for the passed PDU      */
        pkstrTxBuff = astrGATE_IF_TBL(udtPduId).pkstrTxBuffRef;
        u16GlblPdu  = astrGATE_IF_TBL(udtPduId).u16IPduGlobalId;

        #if(PduR_bDEV_ERROR_DETECT == STD_ON)

        /*! Check if the FIFO buffer is not NULL, if NULL report to DET       */
        if(pkstrTxBuff == (const PduR_tstrTxBuffPCCfgType *)NULL_PTR)
        {
            /*! Call DET with NULL_PTR Error                                  */
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    astrGATE_IF_TBL(udtPduId).u8TxConfApiId,
                                    PDUR_E_NULL_POINTER);
        }
        /*! Check that the passed ID is IDLE or not                           */
        else if((PduR_au8eGlblPduState[u16GlblPdu] == PduR_u8IDLE))
        {
            /*! Call DET with Invalid ID Error                                */
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    astrGATE_IF_TBL(udtPduId).u8TxConfApiId,
                                    PDUR_E_PDU_ID_INVALID);
        }
        else
        #endif
        {
            /*! No need to clear the IPDU global status as this will be done in
                the LoIfTxConfirmation function. Just perform GW operations   */

            /*! Check if there is a FIFO buffer configured or not             */
            if(pkstrTxBuff->u8BuffDepth < u8FIFO_MIN_VALUE)
            {
                /*! Do nothing - no FIFO configured                           */
            }
            else
            {
                /*! A FIFO configured, act accordingly, check gatewaying      */
                if(astrGATE_IF_TBL(udtPduId).u8DataProvision == PduR_u8DIRECT)
                {
                    /*! If DIRECT gatewaying configured, regardless FIFO type,
                        remove oldest entry from the FIFO buffer              */
                    vidTxBuffPop(pkstrTxBuff);

                    /*! Handle Tx of any other entries present in the buffer  */
                    vidHandleNextTx(pkstrTxBuff, u16GlblPdu);
                }
                else
                {
                    /*! Do nothing - TxConfirmation in TRIGGERED provision has
                        no effect (only trigger Tx that handles gatewaing)    */
                }
            }
        }
    }
}

/******************************************************************************/
/*! \Description    IF gatewaying local function used to confirm a gateway 
                    operation to a certain destination and acts accordingly \n
    \return         E_OK, E_NOT_OK \n
    \Trace_To       PduR-CDD-5085(0), PduR-CDD-5086(0), PduR-CDD-5087(0)
    \Trace_To       PduR-CDD-5277(0), PduR-CDD-5319(0)
*******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_u8GateTriggerTransmit(
    VAR(PduIdType, AUTOMATIC)                           udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)       pstrPduInfo)
{
    VAR(Std_ReturnType, AUTOMATIC)                      u8Return;
    VAR(Std_ReturnType, AUTOMATIC)                      u8ChkRet;
    VAR(boolean, AUTOMATIC)                             bBuffStatus;
    VAR(PduIdType, AUTOMATIC)                           udtGtPduId;
    VAR(uint8_least, AUTOMATIC)                         u8LoopIdx;
    VAR(uint16, AUTOMATIC)                              u16GlblPdu;

    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST)
                                                        pkstrTxBuff;

    /*! Check udtPduId is in specified range of normal routing tables or not
        (only normal routing as no gatewaying in reduced mode)                */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtPduId < PduR_pkstrePbCfg->udtGateIfRTSize))
    {
        /*! Grab the Tx buffer associated with Id and its global IPDU state   */
        pkstrTxBuff = astrGATE_IF_TBL(udtPduId).pkstrTxBuffRef;
        u16GlblPdu  = astrGATE_IF_TBL(udtPduId).u16IPduGlobalId;

        /*! Check if the FIFO buffer is not NULL and that it is configured, if
            NULL or non configured (FIFO depth = 0) report to DET             */
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        if( (pkstrTxBuff == (const PduR_tstrTxBuffPCCfgType *) NULL_PTR)
            ||  (pkstrTxBuff->u8BuffDepth < u8FIFO_MIN_VALUE)
            ||  (pstrPduInfo == (PduInfoType *) NULL_PTR)
            ||  (pstrPduInfo->SduDataPtr == (uint8 *) NULL_PTR))
        {
            /*! Call DET with NULL_PTR Error                                  */
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    astrGATE_IF_TBL(udtPduId).u8TrigTxApiId,
                                    PDUR_E_NULL_POINTER);

            /*! Return E_NOT_OK to the caller                                 */
            u8Return = E_NOT_OK;
        }
        else
        #endif
        {
            /*! Check if buffer is empty or not                               */
            bBuffStatus = bTxBuffIsEmpty(pkstrTxBuff);

            if(bBuffStatus == TRUE)
            {
                #if(PduR_bDEV_ERROR_DETECT == STD_ON)
                /*! If state is IDLE, E_NOT_OK shall be returned              */
                if(PduR_au8eGlblPduState[u16GlblPdu] == PduR_u8IDLE)
                {
                    /*! Report to DET that this is an invalid request         */
                    (void) Det_ReportError( PDUR_MODULE_ID,
                                            0,
                                            astrGATE_IF_TBL(udtPduId)
                                                                .u8TrigTxApiId,
                                            PDUR_E_PDU_ID_INVALID);

                    /*! Return E_NOT_OK to the caller                         */
                    u8Return = E_NOT_OK;
                }
                else /* State = PduR_u8INPROGRESS                             */
                #endif
                {
                    /*! Set & return default buffer values to PduInfoPtr      */
                    for(    u8LoopIdx = 0;
                            u8LoopIdx < pkstrTxBuff->u8BuffLength;
                            u8LoopIdx++)
                    {
                        pstrPduInfo->SduDataPtr[u8LoopIdx] = 
                            astrGATE_IF_TBL(udtPduId).pku8DefData[u8LoopIdx];
                    }

                    /*! Set & return the length of the PduInfoPtr             */
                    pstrPduInfo->SduLength = pkstrTxBuff->u8BuffLength;

                    /*! Return E_OK to the caller                             */
                    u8Return = E_OK;
                }
            }
            else
            {
                /*! FIFO configured and contains data. Check requested ID versus
                    ID of oldest entry stored in the FIFO buffer              */
                u8ChkRet = u8TxBuffReadPduId(
                                        udtPduId, pkstrTxBuff, &udtGtPduId);

                /*! If passed ID matches the ID in FIFO buffer, remove data   */
                if(u8ChkRet == E_OK)
                {
                    /*! Copy data from FIFO buffer to the passed pointer      */
                    vidTxBuffRead(pkstrTxBuff, pstrPduInfo, &udtGtPduId);
                    vidTxBuffPop(pkstrTxBuff);

                    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
                    /*! If state is IDLE, E_NOT_OK shall be returned          */
                    if(PduR_au8eGlblPduState[u16GlblPdu] == PduR_u8IDLE)
                    {
                        /*! Report to DET that this is an invalid request     */
                        (void) Det_ReportError( PDUR_MODULE_ID,
                                                0,
                                                astrGATE_IF_TBL(udtPduId)
                                                                .u8TrigTxApiId,
                                                PDUR_E_PDU_ID_INVALID);
            
                        /*! Return E_NOT_OK to the caller                     */
                        u8Return = E_NOT_OK;
                    }
                    else /* State = PduR_u8INPROGRESS                         */
                    #endif
                    {
                        /*! If no confirmation is configured to be received from
                            destination, then set the global state to IDLE    */
                        if(astrGATE_IF_TBL(udtPduId).bTxConfirmation == FALSE)
                        {
                            PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;
                        }
                        else
                        {
                            /*! Do nothing                                    */
                        }

                        /*! Handle Tx of any other entries present in buffer 
                            only if INPROGRESS, otherwise this is a problem in
                            the system (as if the TriggerTx was not received) */
                        vidHandleNextTx(pkstrTxBuff, u16GlblPdu);

                        /*! Return E_OK to the caller                         */
                        u8Return = E_OK;
                    }
                }
                else
                {
                    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
                    /*! If state is IDLE, E_NOT_OK shall be returned          */
                    if(PduR_au8eGlblPduState[u16GlblPdu] == PduR_u8IDLE)
                    {
                        /*! Report to DET that this is an invalid request     */
                        (void) Det_ReportError( PDUR_MODULE_ID,
                                                0,
                                                astrGATE_IF_TBL(udtPduId)
                                                                .u8TrigTxApiId,
                                                PDUR_E_PDU_ID_INVALID);
                    }
                    #endif

                    /*! Return E_NOT_OK to the caller                         */
                    /*! \Trace_To   PduR-CDD-0059(0)                          */
                    u8Return = E_NOT_OK;
                }
            }
        }
    }
    else
    {
        /*! Problem with the passed Id, return E_NOT_OK                       */
        u8Return = E_NOT_OK;
    }

    return u8Return;
}
#endif

/**********************************/
/* Multicasting Default Functions */
/**********************************/

#if(PduR_bMULTICASTING_IF == STD_ON)
/******************************************************************************/
/*! \Description    IF multicast function used to act accordingly upon receiving
                    a TxConfirmation from lower layers (informing upper layer 
                    with the confirmation when all destinations confirm) \n
    \return         void \n
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidMultiTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                                       udtPduId)
{
    VAR(PduIdType, AUTOMATIC)                                       udtCtrlId;
    VAR(PduIdType, AUTOMATIC)                                       udtTargetId;
    VAR(uint8, AUTOMATIC)                                           u8DevIdx;
    VAR(uint16, AUTOMATIC)                                          u16GlblPdu;

    P2CONST(PduR_tstrIf2UpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST) pkstrIfUpFp;

    /*! No NULL_PTR checking is needed as parameters are passed by value      */
    
    /*! Check udtPduId is in specified range of normal routing tables 
        or not (only normal routing as no gatewaying in reduced mode)         */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtPduId < PduR_pkstrePbCfg->udtMultiIfRTSize))
    {
        /*! Grab the control Id to pass it to the local function later on     */
        udtCtrlId   = astrMULTI_IF_TBL(udtPduId).udtCntrlId;

        /*! Check if this is the confirmation of the last transmitted PDU by 
            checking if it is the last entry in the Multicast If array or that 
            the control index of this entry is different than entry + 1       */
        /*! \Trace_To   PduR-CDD-5335(2), PduR-CDD-5337(2)                    */
        if( (udtPduId == (PduR_pkstrePbCfg->udtMultiIfRTSize - 1)) ||
            (astrMULTI_IF_TBL(udtPduId).udtCntrlId 
                        != astrMULTI_IF_TBL(udtPduId + 1).udtCntrlId))
        {
            /*! Prepare destination and TxConfirmation function pointer       */
            udtTargetId = astrMULTI_IF_SUB_TBL(udtCtrlId).udtSrcPduRefId;
            u8DevIdx    = astrMULTI_IF_SUB_TBL(udtCtrlId).u8SrcPduDeviceId;
            pkstrIfUpFp = pkstrIF_UP_TBL(u8DevIdx);

            /*! Forward the request to the upper layer                        */
            /*! \Trace_To   PduR-CDD-0029(0)                                  */
            pkstrIfUpFp->pfvidUpIfTxConf(udtTargetId);

            /*! Set the global confirmation ID of the multicast set to IDLE   */
            u16GlblPdu = astrMULTI_IF_SUB_TBL(udtCtrlId).u16TxGlobalId;
            PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;
        }

        /*! Set the IPDU ID to IDLE for the confirmation received             */
        /*! \Trace_To   PduR-CDD-5336(0)                                      */
        u16GlblPdu  = astrMULTI_IF_TBL(udtPduId).u16IPduGlobalId;
        PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;
    }
}

/******************************************************************************/
/*! \Description    IF trigger transmit function used to act accordingly upon 
                    receiving a TriggerTransmit request from lower layers \n
    \return         void \n
    \Trace_To       
*******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_u8MultiTriggerTransmit(
    VAR(PduIdType, AUTOMATIC)                                       udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)                   pstrPduInfo)
{
    VAR(Std_ReturnType, AUTOMATIC)                                  u8FuncRet;
    VAR(PduIdType, AUTOMATIC)                                       udtTargetId;
    VAR(uint8, AUTOMATIC)                                           u8DevIdx;
    VAR(PduIdType, AUTOMATIC)                                       udtCtrlId;

    P2CONST(PduR_tstrIf2UpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST) pkstrIfUpFp;

    /*! Check udtPduId is in specified range of normal routing tables or not
        (only normal routing as no gatewaying in reduced mode)                */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtPduId < PduR_pkstrePbCfg->udtMultiIfRTSize))
    {
        /*! Get the control ID                                                */
        udtCtrlId       = astrMULTI_IF_TBL(udtPduId).udtCntrlId;

        /*! Prepare destination and TriggerTransmit function pointer          */
        udtTargetId = astrMULTI_IF_SUB_TBL(udtCtrlId).udtSrcPduRefId;
        u8DevIdx    = astrMULTI_IF_SUB_TBL(udtCtrlId).u8SrcPduDeviceId;
        pkstrIfUpFp = pkstrIF_UP_TBL(u8DevIdx);

        /*! Forward the request to the upper layer                            */
        u8FuncRet = pkstrIfUpFp->pfu8UpIfTriggerTx(udtTargetId, pstrPduInfo);
    }
    /*! udtPduId to be used in the TriggerTx operation is out of range        */
    else
    {
        u8FuncRet = E_NOT_OK;
    }

    return u8FuncRet;
}
#endif


/**************************************/
/* Interface Layers Default Functions */
/**************************************/

/******************************************************************************/
/*! \Description    Handles the reception of a frame on the interface layer
                    from a lower module \n
    \return         void \n
    \Trace_To       PduR-CDD-5140(0), PduR-CDD-5171(0), PduR-CDD-5139(0)
    \Trace_To       PduR-CDD-5106(0), PduR-CDD-5036(0), PduR-CDD-5046(0)
    \Trace_To       PduR-CDD-5059(0), PduR-CDD-0016(0), PduR-CDD-0178(0)
    \Trace_To       PduR-CDD-5298(0), PduR-CDD-5299(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidLoIfRxIndication(
    VAR(PduIdType, AUTOMATIC)                                   udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)               pstrPduInfo,
    P2CONST(PduR_tstrIfRxRefType, AUTOMATIC, AUTOMATIC)         pkstrTblsRf)
{
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType;

    VAR(PduIdType, AUTOMATIC)                               udtTargetId;
    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    P2CONST(PduR_tstrLoIfRxRTableType, AUTOMATIC, PDUR_CFG_CONST) 
                                                            pkstrRoute;
    P2CONST(PduR_tstrIf2UpRxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST) 
                                                            pkstrRxIndFp;

    /*! Perform regular checks (initialization, out of range ... etc)         */
    u8RtngType = u8StatusChecker(   udtPduId,
                                    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
                                    pkstrTblsRf->u8APIId,
                                    #endif
                                    pkstrTblsRf->u16MinRxTSize,
                                    pkstrTblsRf->u16NrmRxTSize);

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either minimum
            or normal routing as per the value of u8RtngType                  */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute      = &pkstrTblsRf->pkstrMinRRxTRf[udtPduId];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrRxIndFp    = &pkstrTblsRf->pkstrMinRxFnTblRf[u8DevIdx];
        }
        else        /* u8NORMAL_ROUTING_ID                                    */
        {
            /*! Prepare the target information for normal routing             */
            pkstrRoute      = &pkstrTblsRf->pkstrNrmRRxTRf[udtPduId 
                                                - pkstrTblsRf->u16MinRxTSize];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrRxIndFp    = &pkstrTblsRf->pkstrNrmRxFnTblRf[u8DevIdx];
        }

        /*! Grab the routing path group and check if it is enabled or not     */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp = pkstrRoute->u16RPathGrpId;
        if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
        #endif
        {
            /*! Determine the target Id used in passing the call              */
            udtTargetId = pkstrRoute->udtUpPduRefId;

            /*! Call the target function (forward the call)                   */
            pkstrRxIndFp->pfvidUpIfRxIndication(udtTargetId, pstrPduInfo);
        }
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        else
        {
            /*! Do nothing, the routing path group is disabled so no forwarding
                for the message shall take place                              */
        }
        #endif
    }
}

#if(PduR_bIFUP_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description    IF up multicasting local function used to forward the PDU to
                    more than one upper destination \n
    \return         void \n
    \Trace_To       PduR-CDD-0014(0), PduR-CDD-0015(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidMultiUpRxIndication(
    VAR(PduIdType, AUTOMATIC)                               udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)           pstrPduInfo)
{
    VAR(uint8_least, AUTOMATIC)                             u8UpTblIdx;
    VAR(PduIdType, AUTOMATIC)                               udtCtrlId;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    VAR(PduIdType, AUTOMATIC)                               udtTargetId;
    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    P2CONST(PduR_tstrIf2UpRxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST) 
                                                            pkstrRxIndFp;

    /*! Check udtPduId is in specified range of normal routing tables or not
        (only normal routing as no multi upcasting in reduced mode)           */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtPduId < PduR_pkstrePbCfg->u16MultiUpRxRTSize))
    {
        /*! Set loop related local variables to their initial values          */
        u8UpTblIdx  = (uint8) udtPduId;
        udtCtrlId   = astrMULTRX_IF_TBL(udtPduId).udtCntrlId;

        /*! Loop on all destinations to request their IfTransmit fns          */
        while(  (u8UpTblIdx < PduR_pkstrePbCfg->u16MultiUpRxRTSize) &&
                (udtCtrlId == astrMULTRX_IF_TBL(u8UpTblIdx).udtCntrlId))
        {
            /*! Get the routing path group to check the handling of req.      */
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            u16RouteGrp = astrMULTRX_IF_TBL(u8UpTblIdx).u16RPathGrpId;
            if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
            #endif
            {
                /*! Prepare the target information for normal routing         */
                u8DevIdx        = astrMULTRX_IF_TBL(u8UpTblIdx).u8UpPduDeviceId;
                udtTargetId     = astrMULTRX_IF_TBL(u8UpTblIdx).udtUpPduRefId;
                pkstrRxIndFp    = pkstrIF_RX_TBL(u8DevIdx);

                /*! Call the target function (forward the call)               */
                pkstrRxIndFp->pfvidUpIfRxIndication(udtTargetId, pstrPduInfo);
            }

            /*! Increment the upper casting table index used                  */
            u8UpTblIdx++;
        }
    }
}
#endif

/******************************************************************************/
/*! \Description    Hanldes the confirmation of a transmission of a frame on 
                    the lower interface module and acts accordingly \n
    \return         void \n
    \Trace_To       PduR-CDD-0030(0), PduR-CDD-0179(0), PduR-CDD-5047(0)
    \Trace_To       PduR-CDD-5060(0), PduR-CDD-5107(0), PduR-CDD-5141(0)
    \Trace_To       PduR-CDD-5142(0), PduR-CDD-5172(0), PduR-CDD-5300(0)
    \Trace_To       PduR-CDD-5301(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidLoIfTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                                   udtPduId,
    P2CONST(PduR_tstrIfTxRefType, AUTOMATIC, AUTOMATIC)         pkstrTblsRf)
{
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType;

    VAR(PduIdType, AUTOMATIC)                               udtTargetId;
    VAR(uint8, AUTOMATIC)                                   u8DevIdx;
    VAR(uint16, AUTOMATIC)                                  u16GlblPdu;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    P2CONST(PduR_tstrLoIfTxRTableType, AUTOMATIC, PDUR_CFG_CONST) 
                                                            pkstrRoute;
    P2CONST(PduR_tstrIf2UpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST) 
                                                            pkstrTxConfFp;

    /*! Perform regular checks (initialization, out of range ... etc)         */
    u8RtngType = u8StatusChecker(   udtPduId,
                                    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
                                    pkstrTblsRf->u8APIId,
                                    #endif
                                    pkstrTblsRf->u16MinTxTSize,
                                    pkstrTblsRf->u16NrmTxTSize);

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either minimum or
            normal routing as per the value of u8RtngType                     */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute      = &pkstrTblsRf->pkstrMinRTxTRf[udtPduId];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrTxConfFp   = &pkstrTblsRf->pkstrMinTxFnTblRf[u8DevIdx];
        }
        else        /* u8NORMAL_ROUTING_ID                                    */
        {
            /*! Prepare the target information for normal routing             */
            pkstrRoute      = &pkstrTblsRf->pkstrNrmRTxTRf[
                                        udtPduId - pkstrTblsRf->u16MinTxTSize];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrTxConfFp   = &pkstrTblsRf->pkstrNrmTxFnTblRf[u8DevIdx];
        }

        /*! Check that confirmation is configured on this I-PDU               */
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        if(pkstrRoute->bTxConfirmation == FALSE)
        {
            /*! Report to DET if enabled, Id is not in valid range            */
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    pkstrTblsRf->u8APIId,
                                    PDUR_E_PDU_ID_INVALID);
        }
        else
        #endif
        {
            /*! Grab the global IPDU ID and routing path group                */
            u16GlblPdu  = pkstrRoute->u16IPduGlobalId;

            /*! Pass conf to upper/GW/MC if routing path group enabled        */
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            u16RouteGrp = pkstrRoute->u16RPathGrpId;
            if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
            #endif
            {
                /*! Determine the target Id used in passing the call          */
                udtTargetId = pkstrRoute->udtUpPduRefId;

                /*! Call the target function (forward the call)               */
                pkstrTxConfFp->pfvidUpIfTxConf(udtTargetId);

                if(PduR_au8eGlblPduState[u16GlblPdu] == PduR_u8TOBEHANDLED)
                {
                    /*! Manually set the ID to INPROGRESS as this is a GW 
                        operation on the same ID and needs its ID to be fixed */
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8INPROGRESS;
                }
                else
                {
                    /*! Clear the global Pdu status as a Tx is confirmed      */
                    /*! \Trace_To   PduR-CDD-5278(1)                          */
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;
                }
            }

            /*! Else: Return with no further action as the routing path group 
                is disabled. Nothing to be done                               */
        }
    }
}

/******************************************************************************/
/*! \Description    Hanldes the trigger transmit requests of a frame from the 
                    lower interface module and acts accordingly \n
    \return         E_OK, E_NOT_OK \n
    \Trace_To       PduR-CDD-0035(0), PduR-CDD-0035(0), PduR-CDD-0180(0)
    \Trace_To       PduR-CDD-5037(0), PduR-CDD-5048(0), PduR-CDD-5061(0)
    \Trace_To       PduR-CDD-5108(0), PduR-CDD-5143(0), PduR-CDD-5144(0)
    \Trace_To       PduR-CDD-5284(0), PduR-CDD-5302(0), PduR-CDD-5303(0)
*******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_u8LoIfTriggerTransmit(
    VAR(PduIdType, AUTOMATIC)                               udtPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)           pstrPduInfo,
    P2CONST(PduR_tstrIfTxRefType, AUTOMATIC, AUTOMATIC)     pkstrTblsRf)
{
    VAR(Std_ReturnType, AUTOMATIC)                          u8Return;
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType;

    VAR(PduIdType, AUTOMATIC)                               udtTargetId;
    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    P2CONST(PduR_tstrLoIfTxRTableType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrRoute;
    P2CONST(PduR_tstrIf2UpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrTxConfFp;

    /*! Perform regular checks (initialization, out of range ... etc)         */
    u8RtngType = u8StatusChecker(   udtPduId,
                                    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
                                    pkstrTblsRf->u8APIId,
                                    #endif
                                    pkstrTblsRf->u16MinTxTSize,
                                    pkstrTblsRf->u16NrmTxTSize);

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either minimum
            or normal routing as per the value of u8RtngType                  */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute      = &pkstrTblsRf->pkstrMinRTxTRf[udtPduId];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrTxConfFp   = &pkstrTblsRf->pkstrMinTxFnTblRf[u8DevIdx];
        }
        else        /* u8NORMAL_ROUTING_ID                                    */
        {
            /*! Prepare the target information for normal routing             */
            pkstrRoute      = &pkstrTblsRf->pkstrNrmRTxTRf[udtPduId 
                                                - pkstrTblsRf->u16MinTxTSize];
            u8DevIdx        = pkstrRoute->u8UpPduDeviceId;
            pkstrTxConfFp   = &pkstrTblsRf->pkstrNrmTxFnTblRf[u8DevIdx];
        }

        /*! Check data provision is TRIGGERED                                 */
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        if(pkstrRoute->u8DataProvision != PduR_u8TRIGGERED)
        {
            /*! Report to DET if enabled, Id is not in valid range            */
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    pkstrTblsRf->u8APIId,
                                    PDUR_E_PDU_ID_INVALID);

            /*! Return E_NOT_OK to the caller                                 */
            u8Return = E_NOT_OK;
        }
        else
        #endif
        {
            /*! Check if the routing path group is enabled or not             */
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            u16RouteGrp = pkstrRoute->u16RPathGrpId;
            if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
            #endif
            {
                /*! Copy the information to the temporarly variables          */
                udtTargetId     = pkstrRoute->udtUpPduRefId;

                /*! Call the target function (forward the call)               */
                /*! \Trace_To   PduR-CDD-0034(0)                              */
                u8Return = pkstrTxConfFp->pfu8UpIfTriggerTx(    udtTargetId,
                                                                pstrPduInfo);
            }
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            else
            {
                /*! Routing path group is disabled, return with failure       */
                u8Return = E_NOT_OK;
            }
            #endif
        }
    }
    else
    {
        u8Return = E_NOT_OK;
    }

    return u8Return;
}

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if(PduR_bIFLO_ENABLED == STD_ON) */

#endif /* #if (PduR_bZERO_COST_OPERATION == STD_OFF) */

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */

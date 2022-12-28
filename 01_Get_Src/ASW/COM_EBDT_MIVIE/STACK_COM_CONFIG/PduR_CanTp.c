
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !File            : PduR_CanTp.c                                            */
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
/* $Revision::   1.18     $$Author::   sedrees        $$Date::  24/08/2014   $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/* Includes                                                                   */
/******************************************************************************/

/* !Deviation : Inhibit MISRA rule [0838]: Multiple inclusion prevention      */
/*              macros solves multiple/re-inclusions issues                   */
/* PRQA S 0838 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0862]: Memmap.h is used for assignation   */
/*              memory segments in the linker                                 */
/* PRQA S 0862 L1                                                             */
/* PRQA S 5087 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: AUTOMATIC keyword is defined as an */
/*              empty macro                                                   */
/* PRQA S 0850 L1                                                             */

/* !Deviation: Inhibit MISRA rule [0857] Under certain configurations, PduR   */
/*             may have more than 1024 definitions, so the compiler should be */
/*             able to handle more than 1024 definitions.                     */
/* PRQA S 857 ++                                                              */

#include "Std_Types.h"
#include "PduR_Types.h"
#include "PduR_LocalTypes.h"

#include "PduR_CanTp.h"


#include "PduR_UserTp.h"


#include "SchM_PduR.h"

#include "PduR_Cfg.h"
#include "PduR_LocalCfg.h"
#include "PduR_LocalLCfg.h"

#if(PduR_bDEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define PDUR_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

/******************************************************************************/
/*! \Description    Holds references on CanTp Rx tables configurations \n
*******************************************************************************/
static VAR(PduR_tstrTpRxRefType, PDUR_VAR)       PduR_strRxTablesRef;

/******************************************************************************/
/*! \Description    Holds references on CanTp Tx tables configurations \n
*******************************************************************************/
static VAR(PduR_tstrTpTxRefType, PDUR_VAR)       PduR_strTxTablesRef;


#define PDUR_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

#define PDUR_START_SEC_VAR_BOOLEAN
#include "Memmap.h"
  
#if(PduR_u16MAX_CANTP_RX_MSGS > 0UL)
/******************************************************************************/
/*! \Description    Array of booleans to define if an ID is being served or not
                    in the CANTP context for API re-entrancy protection \n
                    API: PduR_CanTpRxIndication
*******************************************************************************/
static VAR(boolean, PDUR_VAR)
                        PduR_abCanTpRxIndAPI[PduR_u16MAX_CANTP_RX_MSGS];

/******************************************************************************/
/*! \Description    Array of booleans to define if an ID is being served or not
                    in the CANTP context for API re-entrancy protection \n
                    API: PduR_CanTpStartOfReception
*******************************************************************************/
static VAR(boolean, PDUR_VAR)
                        PduR_abCanTpStartOfRxAPI[PduR_u16MAX_CANTP_RX_MSGS];

/******************************************************************************/
/*! \Description    Array of booleans to define if an ID is being served or not
                    in the CANTP context for API re-entrancy protection \n
                    API: PduR_CanTpCopyRxData
*******************************************************************************/
static VAR(boolean, PDUR_VAR)
                        PduR_abCanTpCopyRxDataAPI[PduR_u16MAX_CANTP_RX_MSGS];
#endif
  
#if(PduR_u16MAX_CANTP_TX_MSGS > 0UL)
/******************************************************************************/
/*! \Description    Array of booleans to define if an ID is being served or not
                    in the CANTP context for API re-entrancy protection \n
                    API: PduR_CanTpCopyTxData
*******************************************************************************/
static VAR(boolean, PDUR_VAR)
                        PduR_abCanTpCopyTxDataAPI[PduR_u16MAX_CANTP_TX_MSGS];

/******************************************************************************/
/*! \Description    Array of booleans to define if an ID is being served or not
                    in the CANTP context for API re-entrancy protection \n
                    API: PduR_CanTpTxConfirmation
*******************************************************************************/
static VAR(boolean, PDUR_VAR)
                        PduR_abCanTpTxConfAPI[PduR_u16MAX_CANTP_TX_MSGS];

#endif
   
#define PDUR_STOP_SEC_VAR_BOOLEAN
#include "Memmap.h"

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

#define PDUR_START_SEC_CODE
#include "Memmap.h"

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/******************************************************************************/
/*! \Description    PduR_CanTpStartOfReception \n
    \return         void \n
    \Trace_To       PduR-CDD-5122(0), PduR-CDD-5280(0), PduR-CDD-0198(0), 
    \Trace_To       PduR-CDD-0200(0)
*******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception(
    VAR(PduIdType, AUTOMATIC)                       id,
    
    /* !Deviation : Inhibit MISRA rule [3206]: This parameter is mandatory    */
    /*              by AUTOSAR specs.                                         */
    /* PRQA S 3206 ++                                                         */
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   info,
    /* PRQA S 3206 --                                                         */
    VAR(PduLengthType, AUTOMATIC)                   TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
#if(PduR_u16MAX_CANTP_RX_MSGS > 0UL)
    VAR(BufReq_ReturnType, AUTOMATIC)                       enuFuncRet;

    VAR(PduR_ReturnType, AUTOMATIC)                         u8ChckRet;
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType;

    /*! Check API status if it is running or not                              */
    /*! Protection needed againest data consistency                           */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be            */
    /*              implemented during integration phase                      */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_PduR(PduR_CANTP_ACCESS_002);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */

    /*! Check module's status and passed Id status are correct or not         */
    PduR_strRxTablesRef.u8APIId = PduR_u8CANTPSTARTOFRX;
    u8ChckRet = PduR_u8TpRxStatusChecker(id, &u8RtngType, &PduR_strRxTablesRef);

    if(u8ChckRet == E_OK)
    {

        if(PduR_abCanTpStartOfRxAPI[id] == FALSE)
        {
            /*! API is not running, set running & start normal API sequence   */
            PduR_abCanTpStartOfRxAPI[id] = TRUE;

            /*! Clear critical section */
            /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be    */
            /*              implemented during integration phase              */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_CANTP_ACCESS_002);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Pass the call to the generic func                             */
            enuFuncRet = PduR_enuLoTpStartOfRx( id, TpSduLength,
                                                bufferSizePtr, u8RtngType,
                                                &PduR_strRxTablesRef);

            /*! API execution is over, set to API to FALSE - no protection
                is needed as access of this request is atomic                 */
            PduR_abCanTpStartOfRxAPI[id] = FALSE;
        }
        else
        {
            /*! Clear critical section                                        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_CANTP_ACCESS_002);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Report to DET with user defined code that API was called 
                while already being executed                                  */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    PduR_u8CANTPSTARTOFRX,
                                    PDUR_E_API_STILL_RUNNING);
            #endif

            enuFuncRet = BUFREQ_E_NOT_OK;
        }
    }
    else
    {
        /*! Clear critical section                                            */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_PduR(PduR_CANTP_ACCESS_002);
        /* PRQA S 3141 --                                                     */
        /* PRQA S 3138 --                                                     */

        enuFuncRet = BUFREQ_E_NOT_OK;
    }

    return enuFuncRet;
#else
    return BUFREQ_E_NOT_OK;
#endif
}

/******************************************************************************/
/*! \Description    PduR_CanTpCopyRxData \n
    \return         void \n
    \Trace_To       PduR-CDD-5120(0), PduR-CDD-5282(0), PduR-CDD-0198(0), 
    \Trace_To       PduR-CDD-0200(0)
*******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData(
    VAR(PduIdType, AUTOMATIC)                       id,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
#if(PduR_u16MAX_CANTP_RX_MSGS > 0UL)
    VAR(BufReq_ReturnType, AUTOMATIC)                       enuFuncRet;

    VAR(PduR_ReturnType, AUTOMATIC)                         u8ChckRet;
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType;

    /*! Check API status if it is running or not                              */
    /*! Protection needed againest data consistency                           */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be            */
    /*              implemented during integration phase                      */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_PduR(PduR_CANTP_ACCESS_003);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */

    /*! Check module's status and passed Id status are correct or not         */
    PduR_strRxTablesRef.u8APIId = PduR_u8CANTPCOPYRXDATA;
    u8ChckRet = PduR_u8TpRxStatusChecker(id, &u8RtngType, &PduR_strRxTablesRef);

    if(u8ChckRet == E_OK)
    {
        if(PduR_abCanTpCopyRxDataAPI[id] == FALSE)
        {
            /*! API is not running, set running & start normal API sequence   */
            PduR_abCanTpCopyRxDataAPI[id] = TRUE;

            /*! Clear critical section */
            /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be    */
            /*              implemented during integration phase              */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_CANTP_ACCESS_003);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Pass the call to the generic func                             */
            enuFuncRet = PduR_enuLoTpCopyRxData(
                    id, info, bufferSizePtr, u8RtngType, &PduR_strRxTablesRef);

            /*! API execution is over, set to API to FALSE - no protection
                is needed as access of this request is atomic                 */
            PduR_abCanTpCopyRxDataAPI[id] = FALSE;
        }
        else
        {
            /*! Clear critical section                                        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_CANTP_ACCESS_003);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Report to DET with user defined code that API was called 
                while already being executed                                  */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    PduR_u8CANTPCOPYRXDATA,
                                    PDUR_E_API_STILL_RUNNING);
            #endif

            enuFuncRet = BUFREQ_E_NOT_OK;
        }
    }
    else
    {
        /*! Clear critical section                                            */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_PduR(PduR_CANTP_ACCESS_003);
        /* PRQA S 3141 --                                                     */
        /* PRQA S 3138 --                                                     */

        enuFuncRet = BUFREQ_E_NOT_OK;
    }

    return enuFuncRet;
#else
    return BUFREQ_E_NOT_OK;
#endif
}

/******************************************************************************/
/*! \Description    PduR_CanTpRxIndication \n
    \return         void \n
    \Trace_To       PduR-CDD-5121(0), PduR-CDD-5279(0), PduR-CDD-0198(0), 
    \Trace_To       PduR-CDD-0200(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpRxIndication(
    VAR(PduIdType, AUTOMATIC)                       id,
    VAR(NotifResultType, AUTOMATIC)                 result)
{
#if(PduR_u16MAX_CANTP_RX_MSGS > 0UL)
    VAR(PduR_ReturnType, AUTOMATIC)                         u8FuncRet;
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType;

    /*! Check API status if it is running or not                              */
    /*! Protection needed againest data consistency                           */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be            */
    /*              implemented during integration phase                      */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_PduR(PduR_CANTP_ACCESS_001);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */

    /*! Check module's status and passed Id status are correct or not         */
    PduR_strRxTablesRef.u8APIId = PduR_u8CANTPRXINDICATION;
    u8FuncRet = PduR_u8TpRxStatusChecker(id, &u8RtngType, &PduR_strRxTablesRef);

    if(u8FuncRet == E_OK)
    {
        if(PduR_abCanTpRxIndAPI[id] == FALSE)
        {
            /*! API is not running, set running & start normal API sequence   */
            PduR_abCanTpRxIndAPI[id] = TRUE;

            /*! Clear critical section */
            /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be    */
            /*              implemented during integration phase              */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_CANTP_ACCESS_001);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Pass the call to the generic func                             */
            PduR_vidLoTpRxIndication(
                                id, result, u8RtngType, &PduR_strRxTablesRef);

            /*! API execution is over, set to API to FALSE - no protection
                is needed as access of this request is atomic                 */
            PduR_abCanTpRxIndAPI[id] = FALSE;
        }
        else
        {
            /*! Clear critical section                                        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_CANTP_ACCESS_001);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Report to DET with user defined code that API was called 
                while already being executed                                  */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    PduR_u8CANTPRXINDICATION,
                                    PDUR_E_API_STILL_RUNNING);
            #endif
        }
    }
    else
    {
        /*! Clear critical section                                            */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_PduR(PduR_CANTP_ACCESS_001);
        /* PRQA S 3141 --                                                     */
        /* PRQA S 3138 --                                                     */
    }
#endif
}

/******************************************************************************/
/*! \Description    PduR_CanTpCopyTxData \n
    \return         void \n
    \Trace_To       PduR-CDD-5123(0), PduR-CDD-5286(0), PduR-CDD-0198(0), 
    \Trace_To       PduR-CDD-0199(0), PduR-CDD-0200(0)
*******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData(
    VAR(PduIdType, AUTOMATIC)                       id,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
{
#if(PduR_u16MAX_CANTP_TX_MSGS > 0UL)
    VAR(BufReq_ReturnType, AUTOMATIC)                       enuFuncRet;

    VAR(PduR_ReturnType, AUTOMATIC)                         u8ChckRet;
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType;

    /*! Check API status if it is running or not                              */
    /*! Protection needed againest data consistency                           */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be            */
    /*              implemented during integration phase                      */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_PduR(PduR_CANTP_ACCESS_004);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */

    /*! Check module's status and passed Id status are correct or not         */
    PduR_strTxTablesRef.u8APIId = PduR_u8CANTPCOPYTXDATA;
    u8ChckRet = PduR_u8TpTxStatusChecker(id, &u8RtngType, &PduR_strTxTablesRef);

    if(u8ChckRet == E_OK)
    {
        if(PduR_abCanTpCopyTxDataAPI[id] == FALSE)
        {
            /*! API is not running, set running & start normal API sequence   */
            PduR_abCanTpCopyTxDataAPI[id] = TRUE;

            /*! Clear critical section */
            /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be    */
            /*              implemented during integration phase              */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_CANTP_ACCESS_004);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            #if(PduR_bCANTP_RETRY == STD_OFF)
            if(retry->TpDataState == TP_DATARETRY)
            {
                enuFuncRet = BUFREQ_E_NOT_OK;
            }
            else
            {
            #endif
            /* !Deviation : Inhibit MISRA rule [2215]: Indentation is         */
            /*              dependent on configuration                        */
            /* PRQA S 2215 ++                                                 */
                /*! Pass the call to the generic func                         */
                enuFuncRet = PduR_enuLoTpCopyTxData(id, info, retry,
                                                    availableDataPtr,
                                                    u8RtngType,
                                                    &PduR_strTxTablesRef);
            /* PRQA S 2215 --                                                 */
            #if(PduR_bCANTP_RETRY == STD_OFF)
            }
            #endif

            /*! API execution is over, set to API to FALSE - no protection
                is needed as access of this request is atomic                 */
            PduR_abCanTpCopyTxDataAPI[id] = FALSE;
        }
        else
        {
            /*! Clear critical section                                        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_CANTP_ACCESS_004);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Report to DET with user defined code that API was called 
                while already being executed                                  */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    PduR_u8CANTPCOPYTXDATA,
                                    PDUR_E_API_STILL_RUNNING);
            #endif

            enuFuncRet = BUFREQ_E_NOT_OK;
        }
    }
    else
    {
        /*! Clear critical section                                            */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_PduR(PduR_CANTP_ACCESS_004);
        /* PRQA S 3141 --                                                     */
        /* PRQA S 3138 --                                                     */

        enuFuncRet = BUFREQ_E_NOT_OK;
    }

    return enuFuncRet;
#else
    return BUFREQ_E_NOT_OK;
#endif
}

/******************************************************************************/
/*! \Description    PduR_CanTpTxConfirmation \n
    \return         void \n
    \Trace_To       PduR-CDD-5124(0), PduR-CDD-5323(0), PduR-CDD-0198(0), 
    \Trace_To       PduR-CDD-0200(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                               id,
    VAR(NotifResultType, AUTOMATIC)                         result)
{
#if(PduR_u16MAX_CANTP_TX_MSGS > 0UL)
    VAR(PduR_ReturnType, AUTOMATIC)                         u8FuncRet;
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType;

    /*! Check API status if it is running or not                              */
    /*! Protection needed againest data consistency                           */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be            */
    /*              implemented during integration phase                      */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_PduR(PduR_CANTP_ACCESS_005);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */

    /*! Check module's status and passed Id status are correct or not         */
    PduR_strTxTablesRef.u8APIId = PduR_u8CANTPTXCONFIRMATION;
    u8FuncRet = PduR_u8TpTxStatusChecker(id, &u8RtngType, &PduR_strTxTablesRef);

    if(u8FuncRet == E_OK)
    {
        if(PduR_abCanTpTxConfAPI[id] == FALSE)
        {
            /*! API is not running, set running & start normal API sequence   */
            PduR_abCanTpTxConfAPI[id] = TRUE;

            /*! Clear critical section */
            /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be    */
            /*              implemented during integration phase              */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_CANTP_ACCESS_005);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Pass the call to the generic func                             */
            PduR_vidLoTpTxConfirmation(
                                id, result, u8RtngType, &PduR_strTxTablesRef);

            /*! API execution is over, set to API to FALSE - no protection
                is needed as access of this request is atomic                 */
            PduR_abCanTpTxConfAPI[id] = FALSE;
        }
        else
        {
            /*! Clear critical section                                        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_CANTP_ACCESS_005);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Report to DET with user defined code that API was called 
                while already being executed                                  */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    PduR_u8CANTPTXCONFIRMATION,
                                    PDUR_E_API_STILL_RUNNING);
            #endif
        }
    }
    else
    {
        /*! Clear critical section                                            */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_PduR(PduR_CANTP_ACCESS_005);
        /* PRQA S 3141 --                                                     */
        /* PRQA S 3138 --                                                     */
    }
#endif
}

/******************************************************************************/
/*! \Description    Function used to initialize the CanTp sub componenet \n
    \return         void \n
    \Trace_To       
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidCanTpInit(void)
{
    VAR(uint16, AUTOMATIC)                          u16TpRxArrSize;
    VAR(uint16_least, AUTOMATIC)                    u16LoopIdx;

    if(PduR_u8eState == PDUR_REDUCED)
    {
        u16TpRxArrSize = PduR_ku16eCanTpRxMinRTSize;
    }
    else /* PduR_u8eState == PDUR_ONLINE  */
    {
        #if(PduR_u8NUMBER_OF_PB_CONFIGS > 0UL)
        u16TpRxArrSize = PduR_pkstrePbCfg->u16CanTpRxRTSize;
        #else
        u16TpRxArrSize = 0UL;
        #endif
    }
    #if(PduR_u16MAX_CANTP_RX_MSGS > 0UL)
    for(u16LoopIdx = 0; u16LoopIdx < u16TpRxArrSize; u16LoopIdx++)
    {
        /*! Set all I-PDU IDs status to false */
        PduR_abCanTpRxIndAPI[u16LoopIdx]        = FALSE;
        PduR_abCanTpStartOfRxAPI[u16LoopIdx]    = FALSE;
        PduR_abCanTpCopyRxDataAPI[u16LoopIdx]   = FALSE;
        
    }
    #endif
    if(PduR_u8eState == PDUR_REDUCED)
    {
        u16TpRxArrSize = PduR_ku16eCanTpTxMinRTSize;
    }
    else /* PduR_u8eState == PDUR_ONLINE  */
    {
        #if(PduR_u8NUMBER_OF_PB_CONFIGS > 0UL)
        u16TpRxArrSize = PduR_pkstrePbCfg->u16CanTpTxRTSize;
        #else
        u16TpRxArrSize = 0UL;
        #endif
    }
    #if(PduR_u16MAX_CANTP_TX_MSGS > 0UL)
    for(u16LoopIdx = 0; u16LoopIdx < u16TpRxArrSize; u16LoopIdx++)
    {
        /*! Set all I-PDU IDs status to false */
        PduR_abCanTpCopyTxDataAPI[u16LoopIdx]   = FALSE;
        PduR_abCanTpTxConfAPI[u16LoopIdx]       = FALSE;
    }
    #endif
    /*! Fill in the Tables Reference Structure */
    #if(PduR_u16CANTP_RX_MINRT_SIZE > 0UL  && PduR_bTPUP_ENABLED == STD_ON)
    PduR_strRxTablesRef.pkstrMinRRxTRf          = PduR_akstreCanTpRxMinRT;
    PduR_strRxTablesRef.pkstrMinRxFnTblRf       = PduR_akstreTp2UpMinFnPtRxT;
    #else
    PduR_strRxTablesRef.pkstrMinRRxTRf          = NULL_PTR;
    PduR_strRxTablesRef.pkstrMinRxFnTblRf       = NULL_PTR;
    #endif
    PduR_strRxTablesRef.u16MinRxTSize           = PduR_ku16eCanTpRxMinRTSize;
    PduR_strRxTablesRef.u8APIId                 = PduR_u8CANTPRXINDICATION;

    #if(PduR_u16CANTP_TX_MINRT_SIZE > 0UL && PduR_bTPUP_ENABLED == STD_ON)
    PduR_strTxTablesRef.pkstrMinRTxTRf          = PduR_akstreCanTpTxMinRT;
    PduR_strTxTablesRef.pkstrMinTxFnTblRf       = PduR_akstreTp2UpMinFnPtTxT;
    #else
    PduR_strTxTablesRef.pkstrMinRTxTRf          = NULL_PTR;
    PduR_strTxTablesRef.pkstrMinTxFnTblRf       = NULL_PTR;
    #endif
    PduR_strTxTablesRef.u16MinTxTSize           = PduR_ku16eCanTpTxMinRTSize;
    PduR_strTxTablesRef.u8APIId                 = PduR_u8CANTPCOPYTXDATA;

    if(PduR_u8eState == PDUR_ONLINE)
    {
        #if(PduR_u8NUMBER_OF_PB_CONFIGS > 0UL)
        PduR_strRxTablesRef.pkstrNrmRRxTRf      =
                        PduR_pkstrePbCfg->pkstrCanTpRxRTable;
        PduR_strRxTablesRef.pkstrNrmRxFnTblRf   =
                        PduR_pkstrePbCfg->pkstrTp2UpRxFuncTable;
        PduR_strRxTablesRef.u16NrmRxTSize       =
                        PduR_pkstrePbCfg->u16CanTpRxRTSize;

        PduR_strTxTablesRef.pkstrNrmRTxTRf          =
                        PduR_pkstrePbCfg->pkstrCanTpTxRTable;
        PduR_strTxTablesRef.pkstrNrmTxFnTblRf       =
                        PduR_pkstrePbCfg->pkstrTp2UpTxFuncTable;
        PduR_strTxTablesRef.u16NrmTxTSize           =
                        PduR_pkstrePbCfg->u16CanTpTxRTSize;
        #else
        PduR_strRxTablesRef.pkstrNrmRRxTRf      = NULL_PTR;
        PduR_strRxTablesRef.pkstrNrmRxFnTblRf   = NULL_PTR;
        PduR_strRxTablesRef.u16NrmRxTSize       = 0UL;

        PduR_strTxTablesRef.pkstrNrmRTxTRf      = NULL_PTR;
        PduR_strTxTablesRef.pkstrNrmTxFnTblRf   = NULL_PTR;
        PduR_strTxTablesRef.u16NrmTxTSize       = 0UL;
        #endif
    }
}
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

/* PRQA S 857 --                                                              */
/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */

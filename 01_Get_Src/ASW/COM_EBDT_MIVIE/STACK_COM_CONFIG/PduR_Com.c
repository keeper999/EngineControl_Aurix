
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !File            : PduR_Com.c                                            */
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

#include "PduR_Com.h"


#include "PduR_UserUp.h"


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
/*! \Description    Holds references on Com tables configurations \n
*******************************************************************************/
static VAR(PduR_tstrUpRefType, PDUR_VAR)     PduR_strUpTablesRef;

#define PDUR_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

#define PDUR_START_SEC_VAR_BOOLEAN
#include "Memmap.h"

#if(PduR_u16MAX_COM_TX_MSGS > 0UL)
/******************************************************************************/
/*! \Description    Array of booleans to define if an ID is being served or
                    not in the COM context for API re-entrancy protection \n
                    API: PduR_ComTransmit
*******************************************************************************/
static VAR(boolean, PDUR_VAR)
                            PduR_abComTransmitAPI[PduR_u16MAX_COM_TX_MSGS];


/******************************************************************************/
/*! \Description    Array of booleans to define if an ID is being served or
                    not in the COM context for API re-entrancy protection \n
                    API: PduR_ComCancelTransmit
*******************************************************************************/
static VAR(boolean, PDUR_VAR)
                            PduR_abComCancelTxAPI[PduR_u16MAX_COM_TX_MSGS];


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
/*! \Description    PduR_ComTransmit \n
    \return         E_OK, E_NOT_OK \n
    \Trace_To       PduR-CDD-5115(0), PduR-CDD-5288(0), PduR-CDD-0203(0)
*******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(
    VAR(PduIdType, AUTOMATIC)                               id,
    /* !Deviation : Inhibit MISRA rule: Prototype is indirectly inforced by   */
    /*              AUTOSAR to comply to PduR_<Up>Transmit prototype          */
    /* PRQA S 3673 ++                                                         */
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)           info)
    /* PRQA S 3673 --                                                         */
{
#if(PduR_u16MAX_COM_TX_MSGS > 0UL)
    VAR(Std_ReturnType, AUTOMATIC)                         u8FuncRet;
    VAR(PduR_tu8RoutingType, AUTOMATIC)                    u8RtngType;

    /*! Check API status if it is running or not                              */
    /*! Protection needed againest data consistency                           */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be            */
    /*              implemented during integration phase                      */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_PduR(PduR_COM_ACCESS_001);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */

    /*! Check module's status and passed Id status are correct or not         */
    PduR_strUpTablesRef.u8APIId = PduR_u8COMTRANSMIT;
    u8FuncRet = PduR_u8UpStatusChecker(id, &u8RtngType, &PduR_strUpTablesRef);

    if(u8FuncRet == E_OK)
    {
        if(PduR_abComTransmitAPI[id] == FALSE)
        {
            /*! API is not running, set running & start normal API sequence   */
            PduR_abComTransmitAPI[id] = TRUE;

            /*! Clear critical section                                        */
            /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be    */
            /*              implemented during integration phase              */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_COM_ACCESS_001);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Pass the call to the generic func                             */
            u8FuncRet = PduR_u8UpTransmit(
                                    id, info, u8RtngType, &PduR_strUpTablesRef);

            /*! API execution is over, set to API to FALSE - no protection
                is needed as access of this request is atomic                 */
            PduR_abComTransmitAPI[id] = FALSE;
        }
        else
        {
            /*! Clear critical section                                        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_COM_ACCESS_001);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Report to DET with user defined code that API was called 
                while already being executed                                  */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    PduR_u8COMTRANSMIT,
                                    PDUR_E_API_STILL_RUNNING);
            #endif

            u8FuncRet = E_NOT_OK;
        }
    }
    else
    {
        /*! Clear critical section                                            */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_PduR(PduR_COM_ACCESS_001);
        /* PRQA S 3141 --                                                     */
        /* PRQA S 3138 --                                                     */
    }

    return u8FuncRet;
#else
    return E_NOT_OK;
#endif
}


/******************************************************************************/
/*! \Description    PduR_ComCancelTransmit \n
    \return         E_OK, E_NOT_OK \n
    \Trace_To       PduR-CDD-5116(0), PduR-CDD-5327(0)
*******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComCancelTransmit(
    VAR(PduIdType, AUTOMATIC)                               id)
{
#if(PduR_u16MAX_COM_TX_MSGS > 0UL)
    VAR(Std_ReturnType, AUTOMATIC)                          u8FuncRet;
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType;

    /*! Check API status if it is running or not                              */
    /*! Protection needed againest data consistency                           */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be            */
    /*              implemented during integration phase                      */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_PduR(PduR_COM_ACCESS_002);
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */

    /*! Check module's status and passed Id status are correct or not         */
    PduR_strUpTablesRef.u8APIId = PduR_u8COMCANCELTRANSMIT;
    u8FuncRet = PduR_u8UpStatusChecker(id, &u8RtngType, &PduR_strUpTablesRef);

    if(u8FuncRet == E_OK)
    {
        if(PduR_abComCancelTxAPI[id] == FALSE)
        {
            /*! API is not running, set running & start normal API sequence   */
            PduR_abComCancelTxAPI[id] = TRUE;

            /*! Clear critical section                                        */
            /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be    */
            /*              implemented during integration phase              */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_COM_ACCESS_002);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Pass the call to the generic func                             */
            u8FuncRet = PduR_u8UpCancelTransmit(
                                        id, u8RtngType, &PduR_strUpTablesRef);

            /*! API execution is over, set to API to FALSE - no protection
                is needed as access of this request is atomic                 */
            PduR_abComCancelTxAPI[id] = FALSE;
        }
        else
        {
            /*! Clear critical section                                        */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Exit_PduR(PduR_COM_ACCESS_002);
            /* PRQA S 3141 --                                                 */
            /* PRQA S 3138 --                                                 */

            /*! Report to DET with user defined code that API was called 
                while already being executed                                  */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    PduR_u8COMCANCELTRANSMIT,
                                    PDUR_E_API_STILL_RUNNING);
            #endif

            u8FuncRet = E_NOT_OK;
        }
    }
    else
    {
        /*! Clear critical section                                            */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_PduR(PduR_COM_ACCESS_002);
        /* PRQA S 3141 --                                                     */
        /* PRQA S 3138 --                                                     */
    }

    return u8FuncRet;
#else
    return E_NOT_OK;
#endif
}


/******************************************************************************/
/*! \Description    Function used to initialize the Com sub componenet \n
    \return         void \n
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidComInit(void)
{
    VAR(uint16, AUTOMATIC)                          u16TpRxArrSize;
    VAR(uint16_least, AUTOMATIC)                    u16LoopIdx;

    if(PduR_u8eState == PDUR_REDUCED)
    {
        u16TpRxArrSize = PduR_ku16eComMinRTSize;
    }
    else /* PduR_u8eState == PDUR_ONLINE  */
    {
        #if(PduR_u8NUMBER_OF_PB_CONFIGS > 0UL)
        u16TpRxArrSize = PduR_pkstrePbCfg->u16ComUpTxRTSize;
        #else
        u16TpRxArrSize = 0UL;
        #endif
    }
    #if(PduR_u16MAX_COM_TX_MSGS > 0UL)
    for(u16LoopIdx = 0; u16LoopIdx < u16TpRxArrSize; u16LoopIdx++)
    {
        /*! Set all I-PDU IDs status to false                                 */
        PduR_abComTransmitAPI[u16LoopIdx]       = FALSE;
        PduR_abComCancelTxAPI[u16LoopIdx]       = FALSE;
        
    }
    #endif

    /*! Fill in the Tables Reference Structure from Link-Time Configs         */
    #if(PduR_u16COM_MINRT_SIZE > 0UL)
    PduR_strUpTablesRef.pkstrMinRTxTRf          = PduR_akstreComMinRT;
    #else
    PduR_strUpTablesRef.pkstrMinRTxTRf          = NULL_PTR;
    #endif
    PduR_strUpTablesRef.u16MinTxTSize           = PduR_ku16eComMinRTSize;

    #if(PduR_u16COM_REV_MINRT_SIZE > 0UL)
    PduR_strUpTablesRef.pkstrMinRevRTxTRf       = PduR_akstreComMinRevT;
    #else
    PduR_strUpTablesRef.pkstrMinRevRTxTRf       = NULL_PTR;
    #endif
    PduR_strUpTablesRef.u16MinRevTxTSize        = PduR_ku16eComMinRevTSize;

    #if(PduR_bIFLO_ENABLED == STD_ON)
    PduR_strUpTablesRef.pkstrMinIfTxFnTblRf     = PduR_akstreUp2IfTxMinFnPtT;
    #else
    PduR_strUpTablesRef.pkstrMinIfTxFnTblRf     = NULL_PTR;
    #endif

    #if(PduR_bTPLO_ENABLED == STD_ON)
    PduR_strUpTablesRef.pkstrMinTpTxFnTblRf     = PduR_akstreUp2TpTxMinFnPtT;
    #else
    PduR_strUpTablesRef.pkstrMinTpTxFnTblRf     = NULL_PTR;
    #endif

    PduR_strUpTablesRef.u8APIId                 = 0;

    /*! Fill in the Tables Reference Structure from Post-Build Configs        */
    if(PduR_u8eState == PDUR_ONLINE)
    {
        #if(PduR_u8NUMBER_OF_PB_CONFIGS > 0UL)
        PduR_strUpTablesRef.pkstrNrmRTxTRf      =
                                PduR_pkstrePbCfg->pkstrComUpTxRTable;
        PduR_strUpTablesRef.u16NrmTxTSize       =
                                PduR_pkstrePbCfg->u16ComUpTxRTSize;

        PduR_strUpTablesRef.pkstrNrmRevRTxTRf   =
                                PduR_pkstrePbCfg->pkstrComRevRTable;
        PduR_strUpTablesRef.u16NrmRevTxTSize    =
                                PduR_pkstrePbCfg->u16ComRevRTSize;
        #if(PduR_bIFLO_ENABLED == STD_ON)
        PduR_strUpTablesRef.pkstrNrmIfTxFnTblRf =
                                PduR_pkstrePbCfg->pkstrIfTxFuncTable;
        #endif
        #if(PduR_bTPLO_ENABLED == STD_ON)
        PduR_strUpTablesRef.pkstrNrmTpTxFnTblRf =
                                PduR_pkstrePbCfg->pkstrTpTxFuncTable;
        #endif
        #else
        PduR_strUpTablesRef.pkstrNrmRTxTRf      = NULL_PTR;
        PduR_strUpTablesRef.u16NrmTxTSize       = 0UL;

        PduR_strUpTablesRef.pkstrNrmRevRTxTRf   = NULL_PTR;
        PduR_strUpTablesRef.u16NrmRevTxTSize    = 0UL;

        PduR_strUpTablesRef.pkstrNrmIfTxFnTblRf = NULL_PTR;
        PduR_strUpTablesRef.pkstrNrmTpTxFnTblRf = NULL_PTR;
        #endif
    }
}

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

/* PRQA S 857 --                                                              */
/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */


/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !File            : PduR_Gate.c                                            */
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
/* $Revision::   1.4      $$Author::   sedrees        $$Date::   Aug 24 2014 $*/
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

/* !Deviation : Inhibit MISRA rule [0553]: File might be included but with no */
/*              external linkage due to disabling the gatewaying feature      */
/* PRQA S 0553 L1                                                             */

#include "Std_Types.h"
#include "PduR_Types.h"
#include "PduR_LocalTypes.h"

#include "PduR_Gate.h"
#include "PduR_Cfg.h"

/*! Include files of the corresponding supported upper layers                 */

#if(PduR_bCOM_PRESENT == STD_ON && (PduR_bGATEWAYING_IF == STD_ON \
 || PduR_bGATEWAYING_TP == STD_ON))
#include "Com_Cbk.h"
#endif


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

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

#if(PduR_bCOM_PRESENT == STD_ON && PduR_bGATEWAYING_IF == STD_ON)
/******************************************************************************/
/*! \Description    IF gatewaying local function used to handle the case when a
                    gatewayed messege shall be also forwarded to an upper layer
                    module at the same time \n
    \return         void \n
*******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_u8GtComRxInd(
    VAR(PduIdType, AUTOMATIC)                           udtPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)     pkstrPduInfo)
{
    VAR(PduInfoType, AUTOMATIC)                         strTmpInfo;

    strTmpInfo.SduDataPtr   = pkstrPduInfo->SduDataPtr;
    strTmpInfo.SduLength    = pkstrPduInfo->SduLength;

    /*! Directly call the upper layer function needed                         */
    Com_RxIndication(udtPduId, &strTmpInfo);

    return E_OK;
}
#endif

#if(PduR_bCOM_PRESENT == STD_ON && PduR_bGATEWAYING_TP == STD_ON)
/******************************************************************************/
/*! \Description    TP gatewaying local function used to handle the case when
                    a gatewayed messege shall be forwarded to an upper layer
                    module at the same time. Calls the respective upper APIs \n
    \return         E_NOT_OK, E_PENDING \n
    \Trace_To       PduR-CDD-5207(0)
*******************************************************************************/
FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8GtComTpRxInd(
    VAR(PduIdType, AUTOMATIC)                       udtPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pkstrPduInfo)
{
    VAR(PduLengthType, AUTOMATIC)                   udtLength;
    VAR(BufReq_ReturnType, AUTOMATIC)               enuRetStartOfRx;
    VAR(BufReq_ReturnType, AUTOMATIC)               enuRetCopyRxData;
    VAR(PduInfoType, AUTOMATIC)                     strTmpInfo;

    strTmpInfo.SduDataPtr   = pkstrPduInfo->SduDataPtr;
    strTmpInfo.SduLength    = pkstrPduInfo->SduLength;

    /*! Call the upper layer functions respectively in the defined order      */

    /*! Call the upper layer StartOfReception API                             */
    enuRetStartOfRx = Com_StartOfReception( udtPduId,
                                            NULL_PTR,
                                            pkstrPduInfo->SduLength,
                                            &udtLength);

    /*! Check the return of the StartOfReception API and act accordingly      */
    if(enuRetStartOfRx == BUFREQ_OK)
    {
        /*! Reception process can be proceeded, call next function            */
        /*! Call the upper layer CopyRxData API                               */
        enuRetCopyRxData = Com_CopyRxData(udtPduId, &strTmpInfo, &udtLength);

        /*! Check the return of the CopyRxData API and act accordingly        */
        if(enuRetCopyRxData == BUFREQ_OK)
        {
            /*! Inform the upper layer with a successful RxIndication message */
            /*! Call the upper layer TpRxIndication API                       */
            Com_TpRxIndication(udtPduId, NTFRSLT_OK);
        }
        else
        {
            /*! Inform the upper layer with a failure RxIndication message    */
            /*! Call the upper layer TpRxIndication API                       */
            Com_TpRxIndication(udtPduId, NTFRSLT_E_NOT_OK);
        }
    }

    /*! Set the return to be E_PENDING by default as the PDUR is gatewaying at
        its best effort and the is not interested in the actual return value  */
    return E_PENDING;
}
#endif


#define PDUR_STOP_SEC_CODE
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */

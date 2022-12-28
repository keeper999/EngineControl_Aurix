
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !File            : PduR_CanIf.c                                            */
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

#include "PduR_CanIf.h"


#include "PduR_UserIf.h"


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

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

#define PDUR_START_SEC_CODE
#include "Memmap.h"

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/******************************************************************************/
/*! \Description    PduR_CanIfRxIndication\n
    \return         void \n
    \Trace_To       PduR-CDD-0197(0), PduR-CDD-0198(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfRxIndication(
    VAR(PduIdType, AUTOMATIC)                       RxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   PduInfoPtr)
{
    VAR(PduR_tstrIfRxRefType, AUTOMATIC)            strRxTablesRef;

    /*! Fill in the Rx Tables Reference Structure */
    #if(PduR_u16CANIF_RX_MINRT_SIZE > 0UL && PduR_bIFUP_ENABLED == STD_ON)
    strRxTablesRef.pkstrMinRRxTRf           = PduR_akstreCanIfRxMinRT;
    strRxTablesRef.pkstrMinRxFnTblRf        = PduR_akstreIf2UpMinFnPtRxT;
    #else
    strRxTablesRef.pkstrMinRRxTRf           = NULL_PTR;
    strRxTablesRef.pkstrMinRxFnTblRf        = NULL_PTR;
    #endif

    strRxTablesRef.u16MinRxTSize            = PduR_ku16eCanIfRxMinRTSize;
    strRxTablesRef.u8APIId                  = PduR_u8CANIFRXINDICATION;

    if(PduR_u8eState == PDUR_ONLINE)
    {
        #if(PduR_u8NUMBER_OF_PB_CONFIGS > 0UL)
        strRxTablesRef.pkstrNrmRRxTRf       = PduR_pkstrePbCfg->pkstrCanIfRxRTable;
        strRxTablesRef.pkstrNrmRxFnTblRf    = PduR_pkstrePbCfg->pkstrIf2UpRxFuncTable;
        strRxTablesRef.u16NrmRxTSize        = PduR_pkstrePbCfg->u16CanIfRxRTSize;
        #else
        strRxTablesRef.pkstrNrmRRxTRf       = NULL_PTR;
        strRxTablesRef.pkstrNrmRxFnTblRf    = NULL_PTR;
        strRxTablesRef.u16NrmRxTSize        = 0UL;
        #endif
    }

    /*! Pass the call to the generic RxIndication function */
    PduR_vidLoIfRxIndication(RxPduId, PduInfoPtr, &strRxTablesRef);
}

/******************************************************************************/
/*! \Description    PduR_CanIfTxConfirmation \n
    \return         void \n
    \Trace_to       PduR-CDD-0197(0), PduR-CDD-0198(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                       TxPduId)
{
    VAR(PduR_tstrIfTxRefType, AUTOMATIC)            strTxTablesRef;

    /*! Fill in the Tx Tables Reference Structure */
    #if(PduR_u16CANIF_TX_MINRT_SIZE > 0UL && PduR_bIFUP_ENABLED == STD_ON)
    strTxTablesRef.pkstrMinRTxTRf           = PduR_akstreCanIfTxMinRT;
    strTxTablesRef.pkstrMinTxFnTblRf        = PduR_akstreIf2UpMinFnPtTxT;
    #else
    strTxTablesRef.pkstrMinRTxTRf           = NULL_PTR;
    strTxTablesRef.pkstrMinTxFnTblRf        = NULL_PTR;
    #endif

    strTxTablesRef.u16MinTxTSize            = PduR_ku16eCanIfTxMinRTSize;
    strTxTablesRef.u8APIId                  = PduR_u8CANIFTXCONFIRMATION;

    if(PduR_u8eState == PDUR_ONLINE)
    {
        #if(PduR_u8NUMBER_OF_PB_CONFIGS > 0UL)
        strTxTablesRef.pkstrNrmRTxTRf       = PduR_pkstrePbCfg->pkstrCanIfTxRTable;
        strTxTablesRef.pkstrNrmTxFnTblRf    = PduR_pkstrePbCfg->pkstrIf2UpTxFuncTable;
        strTxTablesRef.u16NrmTxTSize        = PduR_pkstrePbCfg->u16CanIfTxRTSize;
        #else
        strTxTablesRef.pkstrNrmRTxTRf       = NULL_PTR;
        strTxTablesRef.pkstrNrmTxFnTblRf    = NULL_PTR;
        strTxTablesRef.u16NrmTxTSize        = 0UL;
        #endif
    }

    /*! Pass the call to the generic RxIndication function */
    PduR_vidLoIfTxConfirmation(TxPduId, &strTxTablesRef);
}
    
/* PRQA S 857 --                                                              */
/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */

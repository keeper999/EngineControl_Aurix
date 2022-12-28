/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !File            : PduR_UserUp.c                                           */
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
/* $Revision::   1.35     $$Author::   sedrees        $$Date::   Aug 24 2014 $*/
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
#include "PduR_UserUp.h"

#include "SchM_PduR.h"

#include "PduR_LocalCfg.h"

#if (PduR_bZERO_COST_OPERATION == STD_OFF)

#if ((PduR_bIFUP_ENABLED == STD_ON ) || (PduR_bTPUP_ENABLED == STD_ON))

#if(PduR_bDEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/* !Deviation : Inhibit MISRA rule: Implemented as a macro for optimization   */
/* PRQA S 3453 ++                                                             */

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         TP Tx function pointers entries for u8Id \n
*******************************************************************************/
#define         pkstrTP_TX_TBL(u8Id)                                           \
                (&(PduR_pkstrePbCfg->pkstrTpTxFuncTable[u8Id]))

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
    \return         IF Tx function pointers entries for u8Id \n
*******************************************************************************/
#define         pkstrIF_TX_TBL(u8Id)                                           \
                (&(PduR_pkstrePbCfg->pkstrIfTxFuncTable[u8Id]))

/******************************************************************************/
/*! \Description    Returns entry specified by u8Id from specified PB array \n
    \return         IF multicasting entry identified by u8Id \n
*******************************************************************************/
#define         astrMULTI_IF_TBL(u8Id)                                         \
                (PduR_pkstrePbCfg->pkstrMultiIfRTable[u8Id])

/******************************************************************************/
/*! \Description    Returns the # of destinations for a multicast operation \n
    \return         IF multicasting count identified by u8Id \n
*******************************************************************************/
#define         u8MULTI_IF_TX_COUNT(u8Id)                                      \
                (PduR_pkstrePbCfg->pkstrMultiIfSubRT[u8Id].u8CntrMax)

/******************************************************************************/
/*! \Description    Returns the # of destinations for a multicast operation \n
    \return         TP multicasting count identified by u8Id \n
*******************************************************************************/
#define         u8MULTI_TP_TX_COUNT(u8Id)                                      \
                (PduR_pkstrePbCfg->pkstrMultiTpSubRT[u8Id].u8CntrMax)

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

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/******************************************************************************/

/********************/
/* Helper Functions */
/********************/

/******************************************************************************/
/*! \Description    Local function to search for the index in the reverse
                    tables for handling CancelRxReq and ChangeParamReq  \n
    \return         E_OK, E_NOT_OK and E_PENDING \n
    \Trace_To       PduR-CDD-5138(0), PduR-CDD-5297(0), PduR-CDD-5058(0)
    \Trace_To       PduR-CDD-5105(0), PduR-CDD-5296(0), PduR-CDD-5137(0)
    \Trace_To       PduR-CDD-5170(0), PduR-CDD-5136(0), PduR-CDD-5295(0)
    \Trace_To       PduR-CDD-5057(0), PduR-CDD-5104(0), PduR-CDD-5294(0)
    \Trace_To       PduR-CDD-5135(0)
*******************************************************************************/
FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8FindRevRoutingId(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf,
    P2VAR(PduR_tu8RoutingType, AUTOMATIC, AUTOMATIC)        pu8RtngType,
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)                  pudtTablesId)
{
    VAR(PduR_ReturnType, AUTOMATIC)                         u8FuncRet;
    VAR(PduIdType, AUTOMATIC)                               udtTblIdx;
    VAR(boolean, AUTOMATIC)                                 bIndexFound;

    /*! Routing is invalid till we find the udtId in the routing tables       */
    (*pu8RtngType)  = PduR_u8INVALID_ROUTING;
    u8FuncRet       = E_NOT_OK;
    
    /*! Initialize local variables                                            */
    udtTblIdx   = 0;
    bIndexFound = FALSE;

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
    }
    /*! Determine the routing type and report to DET if needed accordingly    */
    else
    {
        /*! Search for the udtId in the minimum routing tables                */
        while(  (udtTblIdx < pkstrTblsRf->u16MinRevTxTSize) && 
                (bIndexFound == FALSE))
        {
            if(pkstrTblsRf->pkstrMinRevRTxTRf[udtTblIdx].udtDstPduRefId
                                                                    == udtId)
            {
                bIndexFound     = TRUE;
                (*pu8RtngType)  = PduR_u8MINIMUM_ROUTING;
                u8FuncRet       = E_OK;
            }
            else
            {
                udtTblIdx++;
            }
        }

        /*! Seach for the udtId in the normal routing tables                  */
        if( (PduR_u8eState == PDUR_ONLINE) && (bIndexFound == FALSE) )
        {
            /*! Reset the index as it was incremented in min routing search   */
            udtTblIdx = 0;

            while(  (udtTblIdx < pkstrTblsRf->u16NrmRevTxTSize) &&
                    (bIndexFound == FALSE))
            {
                if( pkstrTblsRf->pkstrNrmRevRTxTRf[udtTblIdx].udtDstPduRefId
                                                                       == udtId)
                {
                    bIndexFound     = TRUE;
                    (*pu8RtngType)  = PduR_u8NORMAL_ROUTING;
                    udtTblIdx       = udtTblIdx + pkstrTblsRf->u16MinRevTxTSize;
                    u8FuncRet       = E_OK;
                }
                else
                {
                    udtTblIdx++;
                }
            }
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

    /*! Now pudtTablesId shall be holding either the correct value or the 
        maximum value inside the routing table (min/normal)                   */
    (*pudtTablesId) = udtTblIdx;

    return u8FuncRet;
}

/******************************************************************************/
/*! \Description    Function used to perform DET related checks (INVALID_REQ and
                    INVALID_ID) and returns with OK/NOK based on the result \n
    \return         E_OK, E_NOT_OK \n
    \Trace_To       PduR-CDD-5130(0), PduR-CDD-5289(0), PduR-CDD-5101(0)
    \Trace_To       PduR-CDD-5129(0), PduR-CDD-5287(0), PduR-CDD-5167(0)
    \Trace_To       PduR-CDD-5132(0), PduR-CDD-5291(0), PduR-CDD-5102(0)
    \Trace_To       PduR-CDD-5131(0), PduR-CDD-5290(0), PduR-CDD-5188(0)
    \Trace_To       PduR-CDD-5168(0)
*******************************************************************************/
FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8UpStatusChecker(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    P2VAR(PduR_tu8RoutingType, AUTOMATIC, AUTOMATIC)        pu8RtngType,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf)
{
    VAR(PduR_ReturnType, AUTOMATIC)                         u8FuncRet;

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

/******************************************************************************/

/********************************/
/* Upper Layer Normal Functions */
/********************************/

/* !Deviation : Inhibit MISRA rule: STCYC (Cyclomatic Complexity) is needed   */
/*              to fullfill the needed functionality of the API.              */
/*              No further simplification is needed.                          */
/* PRQA S 4700 ++                                                             */

/******************************************************************************/
/*! \Description    Transmit function called from upper layers in order to fire
                    a certain transmit operation to one or more lower layers \n
    \return         E_OK, E_NOT_OK, E_PENDING \n
    \Trace_To       PduR-CDD-0025(0), PduR-CDD-0031(0), PduR-CDD-0173(0)
    \Trace_To       PduR-CDD-5035(0), PduR-CDD-5041(0)
*******************************************************************************/
FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8UpTransmit(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)         pkstrInfo,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf)
{
    VAR(PduR_ReturnType, AUTOMATIC)                         u8FuncRet;

    VAR(uint16, AUTOMATIC)                                  u16GlblPduId;
    VAR(PduIdType, AUTOMATIC)                               udtTargetId;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    P2CONST(PduR_tstrUpTxRTableType, AUTOMATIC, PDUR_CFG_CONST) 
                                                            pkstrRoute;
    P2CONST(PduR_tstrTpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrTpTxFp;
    P2CONST(PduR_tstrIfTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrIfTxFp;

    /*! API parameters checking was already performed by the caller           */

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either
            minimum or normal routing as per the value of u8RtngType          */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute  = &pkstrTblsRf->pkstrMinRTxTRf[udtId];
            u8DevIdx    = pkstrRoute->u8DstPduDeviceId;
            pkstrTpTxFp = &pkstrTblsRf->pkstrMinTpTxFnTblRf[u8DevIdx];
            pkstrIfTxFp = &pkstrTblsRf->pkstrMinIfTxFnTblRf[u8DevIdx];
        }
        else        /* u8NORMAL_ROUTING_ID */
        {
            /*! Prepare the target information for normal routing             */
            pkstrRoute  = &pkstrTblsRf->pkstrNrmRTxTRf[udtId 
                                            - pkstrTblsRf->u16MinTxTSize];
            u8DevIdx    = pkstrRoute->u8DstPduDeviceId;
            pkstrTpTxFp = &pkstrTblsRf->pkstrNrmTpTxFnTblRf[u8DevIdx];
            pkstrIfTxFp = &pkstrTblsRf->pkstrNrmIfTxFnTblRf[u8DevIdx];
        }

        /*! Grab the global IPDU and routing path group IDs to check them     */
        u16GlblPduId    = pkstrRoute->u16IPduGlobalId;

        /*! Grab the target ID to be called in the destination's API          */
        /*! \Trace_To   PduR-CDD-5054(0)                                      */
        udtTargetId     = pkstrRoute->udtDstPduRefId;

        /*! \Trace_To   PduR-CDD-5157(0)                                      */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp = pkstrRoute->u16RPathGrpId;
        if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
        #endif
        {
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            /*! Check if IPDU is already being served & act accordingly       */
            /*! \Trace_To   PduR-CDD-5126(0)                                  */
            if(PduR_au8eGlblPduState[u16GlblPduId] != PduR_u8IDLE)
            {
                /*! Report to DET if enabled, duplicate IPdu ID               */
                (void) Det_ReportError( PDUR_MODULE_ID,
                                        0,
                                        pkstrTblsRf->u8APIId,
                                        PDUR_E_DUPLICATED_IPDU_ID);
            }
            #endif

            /*! Set state to INPROGRESS before transmitting                   */
            PduR_au8eGlblPduState[u16GlblPduId] = PduR_u8INPROGRESS;

            /*! Identify called lower layer (TP/IF) based on provision        */
            if(pkstrRoute->u8DataProvision == PduR_u8NONINTERFACE)
            {
                /*! \Trace_To   PduR-CDD-0032(0), PduR-CDD-5199(0)            */
                u8FuncRet = pkstrTpTxFp->pfu8TpTransmit(
                                                    udtTargetId, pkstrInfo);

                /*! If DET enabled and Tx returned E_NOT_OK, report to DET    */
                #if(PduR_bDEV_ERROR_DETECT == STD_ON)
                if(u8FuncRet == E_NOT_OK)
                {
                    (void) Det_ReportError( PDUR_MODULE_ID,
                                            0,
                                            pkstrTblsRf->u8APIId,
                                            PDUR_E_TP_TX_REQ_REJECTED);
                }
                #endif

                if(u8FuncRet == E_PENDING)
                {
                    u8FuncRet = E_NOT_OK;
                }
            }
            else    /* PduR_u8DIRECT || PduR_u8TRIGGERED */
            {
                /*! \Trace_To   PduR-CDD-0040(0), PduR-CDD-5199(0)            */
                u8FuncRet = pkstrIfTxFp->pfu8IfTransmit(
                                                    udtTargetId, pkstrInfo);

                /*! \Trace_To   PduR-CDD-0036(0)                              */
                if( (u8FuncRet == E_OK) &&
                    (pkstrRoute->u8DataProvision == PduR_u8TRIGGERED))
                {
                    u8FuncRet = E_OK;
                }
            }

            /*! Check the function's return and confirmation type             */
            if( (u8FuncRet == E_NOT_OK) || 
                (pkstrRoute->bTxConfirmation == FALSE) )
            {
                /*! Set global IPDU state to IDLE                             */
                PduR_au8eGlblPduState[u16GlblPduId] = PduR_u8IDLE;
            }
        }
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        else
        {
            /*! Do nothing, routing group disabled. Even if group is disabled
                for this single entry in the table, E_NOT_OK shall be returned
                and transmission shall be aborted from the start, this is 
                acceptable as the routing path group is disabled (enable the
                group first then transmit)                                    */
            u8FuncRet = E_NOT_OK;
        }
        #endif
    }
    else
    {
        u8FuncRet = E_NOT_OK;
    }

    /*! \Trace_To   PduR-CDD-0033(0), PduR-CDD-0044(0)                        */
    return u8FuncRet;
}

/* PRQA S 4700 --                                                             */

#if(PduR_bCANCEL_TX_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description    Cancel Transmit function called by the upper layer in order
                    to cancel an on-going transmission request on the If or Tp
                    layers (either single or multicast requests) \n
    \return         E_OK, E_NOT_OK \n
    \Trace_To       PduR-CDD-0174(0), PduR-CDD-5042(0), PduR-CDD-0175(0)
*******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_u8UpCancelTransmit(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf)
{
    VAR(PduR_ReturnType, AUTOMATIC)                         u8FuncRet;

    VAR(PduIdType, AUTOMATIC)                               udtTargetId;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    P2CONST(PduR_tstrUpTxRTableType, AUTOMATIC, PDUR_CFG_CONST) 
                                                            pkstrRoute;
    P2CONST(PduR_tstrIfTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrIfTxFp;
    P2CONST(PduR_tstrTpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrTpTxFp;
                                                            
    /*! API parameters checking was already performed by the caller           */

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either
            minimum or normal routing as per the value of u8RtngType          */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute  = &pkstrTblsRf->pkstrMinRTxTRf[udtId];
            u8DevIdx    = pkstrRoute->u8DstPduDeviceId;
            
            /*! Check the type of Destination whether it is Tp or If          */
            if(pkstrRoute->u8DataProvision == PduR_u8NONINTERFACE)
            {
                /*! If the destination is Tp          */
                pkstrTpTxFp = &pkstrTblsRf->pkstrMinTpTxFnTblRf[u8DevIdx];
            }
            else
            {
                /*! otherwise the destination is If          */
                pkstrIfTxFp = &pkstrTblsRf->pkstrMinIfTxFnTblRf[u8DevIdx];
            }
        }
        else        /* u8NORMAL_ROUTING_ID                                    */
        {
            /*! Prepare the target information for normal routing             */
            pkstrRoute  = &pkstrTblsRf->pkstrNrmRTxTRf[udtId 
                                            - pkstrTblsRf->u16MinTxTSize];
            u8DevIdx    = pkstrRoute->u8DstPduDeviceId;
            pkstrIfTxFp = &pkstrTblsRf->pkstrNrmIfTxFnTblRf[u8DevIdx];
            
            /*! Check the type of Destination whether it is Tp or If          */
            if(pkstrRoute->u8DataProvision == PduR_u8NONINTERFACE)
            {
                /*! If the destination is Tp          */
                pkstrTpTxFp = &pkstrTblsRf->pkstrNrmTpTxFnTblRf[u8DevIdx];
            }
            else
            {
                /*! otherwise the destination is If          */
                pkstrIfTxFp = &pkstrTblsRf->pkstrNrmIfTxFnTblRf[u8DevIdx];
            }
        }
        
        /*! Grab the target ID to be called in the destination's API          */
        /*! \Trace_To   PduR-CDD-5055(0)                                      */
        udtTargetId     = pkstrRoute->udtDstPduRefId;

        /*! \Trace_To   PduR-CDD-5158(0)                                      */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp = pkstrRoute->u16RPathGrpId;
        if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
        #endif
        {
            /*! Check the type of Destination whether it is Tp or If          */
            if(pkstrRoute->u8DataProvision == PduR_u8NONINTERFACE)
            {
                /*! Forward call LoTp even if an old request is still ongoing     */
                /*! \Trace_To   PduR-CDD-0095(0), PduR-CDD-5345(0)                */
                /* !Deviation : inhibit MISRA rule [30]: because The variable     */
                /*udtSEIndex will definitely be set in code above.                */
                /* PRQA S 3353 ++                                                 */
                u8FuncRet = pkstrTpTxFp->pfu8TpCancelTxReq(udtTargetId);
                /* PRQA S 3353 --                                                 */
            }
            else
            {
                /*! Forward call LoIf even if an old request is still ongoing     */
                /*! \Trace_To   PduR-CDD-0093(0), PduR-CDD-5345(0)                */
                /* !Deviation : inhibit MISRA rule [30]: because The variable     */
                /*udtSEIndex will definitely be set in code above.                */
                /* PRQA S 3353 ++                                                 */
                u8FuncRet = pkstrIfTxFp->pfu8IfCancelTransmit(udtTargetId);
                /* PRQA S 3353 --                                                 */
            }
        }
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        else
        {
            /*! An entry exist that its routing group is disabled, so cancel
                request cannot be invoked. Even though this entry may belong
                to a multicast group, E_NOT_OK shall be returned starting 
                from this entry and no need to pass the call to check other
                entries in the multicast table                                */
            u8FuncRet = E_NOT_OK;
        }
        #endif
    }
    else
    {
        u8FuncRet = E_NOT_OK;
    }

    /*! \Trace_To   PduR-CDD-5346(0)                                          */
    return u8FuncRet;
}
#endif /* #if(PduR_bCANCEL_TX_ENABLED == STD_ON) */

#if(PduR_bCANCEL_RX_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description    Cancel Receive function called by the upper layer in order
                    to cancel an on-going reception request on the TP layer \n
    \return         E_OK, E_NOT_OK \n
    \Trace_To       PduR-CDD-0177(0), PduR-CDD-5045(0)
*******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_u8UpCancelRxRequest(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf)
{
    VAR(Std_ReturnType, AUTOMATIC)                          u8FuncRet;

    VAR(PduIdType, AUTOMATIC)                               udtTargetId;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    P2CONST(PduR_tstrUpTpRevTableType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrRoute;
    P2CONST(PduR_tstrTpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrTpTxFp;

    /*! API parameters checking was already performed by the caller           */

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either
            minimum or normal routing as per the value of u8RtngType          */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute  = &pkstrTblsRf->pkstrMinRevRTxTRf[udtId];
            u8DevIdx    = pkstrRoute->u8DstPduDeviceRefId;
            pkstrTpTxFp = &pkstrTblsRf->pkstrMinTpTxFnTblRf[u8DevIdx];
        }
        else        /* u8NORMAL_ROUTING_ID                                    */
        {
            /*! Prepare the target information for normal routing             */
            pkstrRoute  = &pkstrTblsRf->pkstrNrmRevRTxTRf[udtId 
                                        - pkstrTblsRf->u16MinRevTxTSize];
            u8DevIdx    = pkstrRoute->u8DstPduDeviceRefId;
            pkstrTpTxFp = &pkstrTblsRf->pkstrNrmTpTxFnTblRf[u8DevIdx];
        }

        /*! Grab the target ID to be called in the destination's API          */
        udtTargetId     = pkstrRoute->udtLowPduRefId;

        /*! Check the routing path group to see if request shall proceed      */
        /*! \Trace_To   PduR-CDD-0103(0)                                      */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp = pkstrRoute->u16RPathGrpId;
        if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
        #endif
        {
            /*! Call lower layer (regardless if there is an old request)      */
            /*! \Trace_To   PduR-CDD-0102(0), PduR-CDD-0105(0)                */
            u8FuncRet = pkstrTpTxFp->pfu8TpCancelRxReq(udtTargetId);
        }
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        else
        {
            u8FuncRet = E_NOT_OK;
        }
        #endif
    }
    else
    {
        u8FuncRet = E_NOT_OK;
    }

    /*! \Trace_To   PduR-CDD-0106(0)                                          */
    return u8FuncRet;
}
#endif /* #if(PduR_bCANCEL_RX_ENABLED == STD_ON) */

#if(PduR_bCHANGE_PARAM_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description    Change Parameter function called by the upper layer in order
                    to change the TP parameters used in reception of a msg  \n
    \return         E_OK, E_NOT_OK \n
    \Trace_To       PduR-CDD-0176(0), PduR-CDD-5044(0)
*******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_u8UpChangeParamRequest(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    VAR(TPParameterType, AUTOMATIC)                         enuParameter,
    VAR(uint16, AUTOMATIC)                                  u16Value,
    VAR(PduR_tu8RoutingType, AUTOMATIC)                     u8RtngType,
    P2CONST(PduR_tstrUpRefType, AUTOMATIC, PDUR_VAR) pkstrTblsRf)
{
    VAR(Std_ReturnType, AUTOMATIC)                          u8FuncRet;

    VAR(PduIdType, AUTOMATIC)                               udtTargetId;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    P2CONST(PduR_tstrUpTpRevTableType, AUTOMATIC, PDUR_CFG_CONST) 
                                                            pkstrRoute;
    P2CONST(PduR_tstrTpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrTpTxFp;

    /*! API parameters checking was already performed by the caller           */

    if(u8RtngType != PduR_u8INVALID_ROUTING)
    {
        /*! Id is in the valid range, proceed accordingly with either
            minimum or normal routing as per the value of u8RtngType          */
        if(u8RtngType == PduR_u8MINIMUM_ROUTING)
        {
            /*! Prepare the target information for minimum routing            */
            pkstrRoute  = &pkstrTblsRf->pkstrMinRevRTxTRf[udtId];
            u8DevIdx    = pkstrRoute->u8DstPduDeviceRefId;
            pkstrTpTxFp = &pkstrTblsRf->pkstrMinTpTxFnTblRf[u8DevIdx];
        }
        else        /* u8NORMAL_ROUTING_ID                                    */
        {
            /*! Prepare the target information for normal routing             */
            pkstrRoute  = &pkstrTblsRf->pkstrNrmRevRTxTRf[udtId 
                                        - pkstrTblsRf->u16MinRevTxTSize];
            u8DevIdx    = pkstrRoute->u8DstPduDeviceRefId;
            pkstrTpTxFp = &pkstrTblsRf->pkstrNrmTpTxFnTblRf[u8DevIdx];
        }

        /*! Grab the target ID to be called in the destination's API          */
        udtTargetId     = pkstrRoute->udtLowPduRefId;

        /*! Check the routing path group to see if request shall proceed      */
        /*! \Trace_To   PduR-CDD-5160(0)                                      */
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        u16RouteGrp = pkstrRoute->u16RPathGrpId;
        if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
        #endif
        {
            if( pkstrTpTxFp->pfu8TpChangeParamReq != 
                                    (PduR_tpfu8ChangeParamFunc) NULL_PTR)
            {
                /*! Call lower layer (regardless an ongoing request)          */
                /*! \Trace_To   PduR-CDD-0108(0)                              */
                u8FuncRet = pkstrTpTxFp->pfu8TpChangeParamReq(
                                        udtTargetId, enuParameter, u16Value);
            }
            else
            {
                /*! Return E_NOT_OK as no function available to call          */
                u8FuncRet = E_NOT_OK;
            }
        }
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        else
        {
            u8FuncRet = E_NOT_OK;
        }
        #endif
    }
    else
    {
        u8FuncRet = E_NOT_OK;
    }

    /*! \Trace_To   PduR-CDD-0110(0)                                          */
    return u8FuncRet;
}
#endif /* #if(PduR_bCHANGE_PARAM_ENABLED == STD_ON) */

/**************************************/
/* Upper Layer Multicasting Functions */
/**************************************/

/* !Deviation : Inhibit MISRA rule: STCYC (Cyclomatic Complexity) and STPTH   */
/*              (Estimated Path Count) are needed to fullfill the needed      */
/*              functionality of the API and can be reduced if not all the    */
/*              features are enabled in the PDUR.                             */
/*              No further simplification is needed.                          */
/* PRQA S 4700 ++                                                             */

#if(PduR_bMULTICASTING_IF == STD_ON)
/******************************************************************************/
/*! \Description    Function responsible for transmitting a messege from the 
                    upper layer to multiple IF lower layers \n
    \return         E_OK, E_NOT_OK \n
    \Trace_To       PduR-CDD-5069(0)
*******************************************************************************/
FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8MultiIfTransmit(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)         pkstrInfo)
{
    VAR(PduR_ReturnType, AUTOMATIC)                         u8FuncRet;
    VAR(uint8_least, AUTOMATIC)                             u8LoopIdx;
    VAR(boolean, AUTOMATIC)                                 bIsTxErrOcc;

    VAR(PduIdType, AUTOMATIC)                               udtCtrlId;
    VAR(uint8, AUTOMATIC)                                   u8MltTblIdx;

    VAR(PduIdType, AUTOMATIC)                               udtTargetId;
    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    VAR(uint16, AUTOMATIC)                                  u16GlblPdu;
    VAR(Std_ReturnType, AUTOMATIC)                          u8TxFnRet;

    P2CONST(PduR_tstrIfTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrIfTxFp;

    /*! Check udtId is in specified range of normal routing tables 
        or not (only normal routing as no gatewaying in reduced mode)         */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtId < PduR_pkstrePbCfg->udtMultiIfRTSize))
    {
        /*! Initially set local function variables to their default values    */
        u8LoopIdx   = 0;
        bIsTxErrOcc = FALSE;

        /*! Set multicast table indexer and control ID values                 */
        u8MltTblIdx = (uint8) udtId;
        udtCtrlId   = astrMULTI_IF_TBL(udtId).udtCntrlId;

        /*! Start looping on all destinations in multicast table & Tx data    */
        while(u8LoopIdx < u8MULTI_IF_TX_COUNT(udtCtrlId))
        {
            /*! Prepare destination id and routing group id                   */
            udtTargetId = astrMULTI_IF_TBL(u8MltTblIdx).udtDstPduRefId;

            /*! Prepare the transmit function pointer                         */
            u8DevIdx    = astrMULTI_IF_TBL(u8MltTblIdx).u8DstPduDeviceId;
            pkstrIfTxFp = pkstrIF_TX_TBL(u8DevIdx);

            /*! Check routing group to see if Tx can take place or not        */
            /*! \Trace_To   PduR-CDD-5338(0)                                  */
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            u16RouteGrp = astrMULTI_IF_TBL(u8MltTblIdx).u16RPathGrpId;
            if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
            #endif
            {
                /*! Grab the global PDU ID for the current destination        */
                u16GlblPdu = astrMULTI_IF_TBL(u8MltTblIdx).u16IPduGlobalId;

                /*! If the confirmation is configured to be TRUE for this set */
                if(PduR_pkstrePbCfg->pkstrMultiIfSubRT[udtCtrlId].bTxConf 
                                                                        == TRUE)
                {
                    /*! Set the global IPDU state to INPROGRESS               */
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8INPROGRESS;
                }

                /*! Transmit the messege to the corresponding lower IF layer  */
                u8TxFnRet = pkstrIfTxFp->pfu8IfTransmit(udtTargetId, pkstrInfo);

                /*! \Trace_To   PduR-CDD-5333(0)                              */
                if(u8TxFnRet != E_OK)
                {
                    /*! One of destinations failed to transmit, set err flag  */
                    /*! \Trace_To   PduR-CDD-0038(0)                          */
                    bIsTxErrOcc = TRUE;

                    /*! Terminate the Tx loop (no need to Tx anymore)         */
                    u8LoopIdx = u8MULTI_IF_TX_COUNT(udtCtrlId);
                }
            }
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            else
            {
                /*! One of the destinations are disabled in their routing grp,
                    loop shall be terminated and error shall be returned      */
                bIsTxErrOcc = TRUE;
                u8LoopIdx   = u8MULTI_IF_TX_COUNT(udtCtrlId);
            }
            #endif
            
            /*! Increment the multicasting table index and the loop index     */
            u8MltTblIdx++;
            u8LoopIdx++;
        }

        /*! Check if an error in transmission has occured or not              */
        if(bIsTxErrOcc == TRUE)
        {
            /*! Set all global IPDU states to IDLE if confirmation is configured
                for this multicasting set {to clear any INPROGRESS states}    */
            if(PduR_pkstrePbCfg->pkstrMultiIfSubRT[udtCtrlId].bTxConf == TRUE)
            {
                u8MltTblIdx = (uint8) udtId;
                u8LoopIdx   = 0;

                while(u8LoopIdx < u8MULTI_IF_TX_COUNT(udtCtrlId))
                {
                    /*! Set global IPDU state for all Tx dests to IDLE        */
                    u16GlblPdu = astrMULTI_IF_TBL(u8MltTblIdx).u16IPduGlobalId;
                    PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                    /*! Increment the gateway table index used and loop index */
                    u8MltTblIdx++;
                    u8LoopIdx++;
                }
            }

            /*! Error occured, set return to E_NOT_OK                         */
            u8FuncRet   = E_NOT_OK;
        }
        else /* Transmission of multicast set is successfull                  */
        {
            /*! If any of destinations is IF & TRIGGERED, return E_OK    */
            /*! \Trace_To   PduR-CDD-0037(0)                                  */
            u8FuncRet = E_OK;
        }
    }
    /*! udtId to be used in the transmission operation is out of range        */
    else
    {
        u8FuncRet = E_NOT_OK;
    }

    return u8FuncRet;
}
/* PRQA S 4700 --                                                             */
#endif

#if(PduR_bMULTICASTING_TP == STD_ON)
/******************************************************************************/
/*! \Description    Function responsible for transmitting a messege from the 
                    upper layer to multiple IF lower layers \n
    \return         E_OK, E_NOT_OK, E_PENDING \n
    \Trace_To       PduR-CDD-5344(0)
*******************************************************************************/
FUNC(PduR_ReturnType, PDUR_CODE) PduR_u8MultiTpTransmit(
    VAR(PduIdType, AUTOMATIC)                               udtId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)         pkstrInfo)
{
    VAR(PduR_ReturnType, AUTOMATIC)                         u8FuncRet;
    VAR(uint8_least, AUTOMATIC)                             u8LoopIdx;
    VAR(boolean, AUTOMATIC)                                 bIsTxErrOcc;
    VAR(boolean, AUTOMATIC)                                 bIsRPathDisbl;

    VAR(PduIdType, AUTOMATIC)                               udtCtrlId;
    VAR(uint8, AUTOMATIC)                                   u8MltTblIdx;
    
    VAR(PduIdType, AUTOMATIC)                               udtTargetId;
    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    VAR(uint16, AUTOMATIC)                                  u16GlblPdu;
    VAR(Std_ReturnType, AUTOMATIC)                          u8TxFnRet;

    P2CONST(PduR_tstrTpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrTpTxFp;

    /*! Check udtId is in specified range of normal routing tables 
        or not (only normal routing as no gatewaying in reduced mode)         */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtId < PduR_pkstrePbCfg->udtMultiTpRTSize))
    {
        /*! Initially set local function variables to their default values    */
        u8LoopIdx       = 0;
        bIsTxErrOcc     = FALSE;
        bIsRPathDisbl   = FALSE;

        /*! Set multicast table indexer and control ID values                 */
        u8MltTblIdx = (uint8) udtId;
        udtCtrlId   = astrMULTI_TP_TBL(udtId).udtCntrlId;

        /*! Start looping on all destinations in multicast table & Tx data    */
        while(u8LoopIdx < u8MULTI_TP_TX_COUNT(udtCtrlId))
        {
            /*! Prepare destination id and routing group id                   */
            udtTargetId = astrMULTI_TP_TBL(u8MltTblIdx).udtDstPduRefId;

            /*! Prepare the transmit function pointer                         */
            u8DevIdx    = astrMULTI_TP_TBL(u8MltTblIdx).u8DstPduDeviceId;
            pkstrTpTxFp = pkstrTP_TX_TBL(u8DevIdx);

            /*! Check routing group to see if Tx can take place or not        */
            /*! \Trace_To   PduR-CDD-5341(0)                                  */
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            u16RouteGrp = astrMULTI_TP_TBL(u8MltTblIdx).u16RPathGrpId;
            if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
            #endif
            {
                /*! Grab the global PDU ID for the current destination        */
                u16GlblPdu = astrMULTI_TP_TBL(u8MltTblIdx).u16IPduGlobalId;

                /*! Set global IPDU state to INPROGRESS (in TP TxConf is must)*/
                PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8INPROGRESS;

                /*! Transmit the messege to the corresponding lower TP layer  */
                u8TxFnRet = pkstrTpTxFp->pfu8TpTransmit(udtTargetId, pkstrInfo);

                /*! \Trace_To   PduR-CDD-5205(0)                              */
                if(u8TxFnRet != E_OK)
                {
                    /*! One of the destinations failed to transmit the messege,
                        loop shall be terminated and error shall be returned  */
                    u8LoopIdx   = u8MULTI_TP_TX_COUNT(udtCtrlId);
                    bIsTxErrOcc = TRUE;
                }
                else
                {
                    /*! Transmission is acknowledged, set the copying index to 
                        0 for this TP destination                             */
                    /*! \Trace_To   PduR-CDD-5200(0)                          */
                    PduR_pkstrePbCfg->pu16MultiTpCopyTxIdx[u8MltTblIdx] = 0;
                }
            }
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            else
            {
                /*! One of the destinations are disabled in their routing group,
                    loop shall be terminated & error shall be returned        */
                u8LoopIdx       = u8MULTI_TP_TX_COUNT(udtCtrlId);
                bIsRPathDisbl   = TRUE;
            }
            #endif

            /*! Increment the multicasting table index and the loop index     */
            u8MltTblIdx++;
            u8LoopIdx++;
        }

        /*! Check if an error in transmission has occured or not              */
        if( (bIsTxErrOcc == TRUE) || (bIsRPathDisbl == TRUE) )
        {
            /*! Set the global IPDU state for all destinations to IDLE        */
            u8MltTblIdx = (uint8) udtId;
            u8LoopIdx   = 0;

            while(u8LoopIdx < u8MULTI_TP_TX_COUNT(udtCtrlId))
            {
                /*! Set global IPDU state for all Tx dests to IDLE            */
                u16GlblPdu = astrMULTI_TP_TBL(u8MltTblIdx).u16IPduGlobalId;
                PduR_au8eGlblPduState[u16GlblPdu] = PduR_u8IDLE;

                /*! Increment the multicast table index used and loop index   */
                u8MltTblIdx++;
                u8LoopIdx++;
            }
            
            /*! Error occured, set return to E_NOT_OK                     */
            u8FuncRet   = E_NOT_OK;
        }
        else
        {
            /*! Set the RAM control information for TP multicasting           */
            astrMULTI_TP_CTRL(udtCtrlId).bIsFirst       = TRUE;
            astrMULTI_TP_CTRL(udtCtrlId).u8ConfResult   = NTFRSLT_OK;
            astrMULTI_TP_CTRL(udtCtrlId).u8CntrValue    = 0;

            /* Successful transmission, return E_OK to the caller party       */
            u8FuncRet = E_OK;
        }
    }
    /*! udtId to be used in the transmission operation is out of range        */
    else
    {
        u8FuncRet = E_NOT_OK;
    }

    return u8FuncRet;
}
#endif

#if((PduR_bMULTICASTING_IF == STD_ON) && (PduR_bCANCEL_TX_ENABLED == STD_ON))
/******************************************************************************/
/*! \Description    Function responsible for canceling the transmit requests 
                    that was invoked in a multicasting context over IF layers \n
    \return         E_OK, E_NOT_OK \n
*******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_u8MultiCancelTransmit(
    VAR(PduIdType, AUTOMATIC)                               udtId)
{
    VAR(Std_ReturnType, AUTOMATIC)                          u8FuncRet;
    VAR(uint8_least, AUTOMATIC)                             u8LoopIdx;
    VAR(uint8, AUTOMATIC)                                   u8MltTblIdx;
    VAR(PduIdType, AUTOMATIC)                               udtCtrlId;
    
    VAR(PduIdType, AUTOMATIC)                               udtTargetId;
    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    VAR(Std_ReturnType, AUTOMATIC)                          u8CnclTxFnRet;

    P2CONST(PduR_tstrIfTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrIfTxFp;

    /*! Check udtId is in specified range of normal routing tables or not
        (only normal routing as no gatewaying in reduced mode)                */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtId < PduR_pkstrePbCfg->udtMultiIfRTSize))
    {
        /*! Initially set local function variables to their default values    */
        u8LoopIdx   = 0;
        u8MltTblIdx = (uint8) udtId;
        udtCtrlId   = astrMULTI_IF_TBL(udtId).udtCntrlId;
        u8FuncRet   = E_NOT_OK;

        /*! Start looping on all destinations in multicast table to cancel Tx */
        while(u8LoopIdx < u8MULTI_IF_TX_COUNT(udtCtrlId))
        {
            /*! Prepare destination id and routing group id                   */
            udtTargetId = astrMULTI_IF_TBL(u8MltTblIdx).udtDstPduRefId;

            /*! Prepare the transmit function pointer                         */
            u8DevIdx    = astrMULTI_IF_TBL(u8MltTblIdx).u8DstPduDeviceId;
            pkstrIfTxFp = pkstrIF_TX_TBL(u8DevIdx);

            /*! Check routing group to see if CancelTx can take place or not  */
            /*! \Trace_To   PduR-CDD-5347(0)                                  */
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            u16RouteGrp = astrMULTI_IF_TBL(u8MltTblIdx).u16RPathGrpId;
            if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
            #endif
            {
                /*! Forward the cancel request to the lower layer             */
                /*! \Trace_To   PduR-CDD-0094(0)                              */
                u8CnclTxFnRet = pkstrIfTxFp->pfu8IfCancelTransmit(udtTargetId);

                /*! \Trace_To   PduR-CDD-5348(0)                              */
                if(u8CnclTxFnRet != E_OK)
                {
                    /*! One of the destinations failed to cancel transmission,
                        loop shall be terminated and error shall be returned  */
                    u8LoopIdx   = u8MULTI_IF_TX_COUNT(udtCtrlId);
                    u8FuncRet   = E_NOT_OK;
                }
                else
                {
                    u8FuncRet  = E_OK;
                }
            }
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            else
            {
                /*! One of the destinations are disabled in their routing group,
                    loop shall be terminated and error shall be returned      */
                u8LoopIdx   = u8MULTI_IF_TX_COUNT(udtCtrlId);
                u8FuncRet   = E_NOT_OK;
            }
            #endif

            /*! Increment the multicasting table index and the loop index     */
            u8MltTblIdx++;
            u8LoopIdx++;
        }
    }
    /*! udtId to be used in the cancelation operation is out of range         */
    else
    {
        u8FuncRet = E_NOT_OK;
    }

    return u8FuncRet;
}
#endif

#if((PduR_bMULTICASTING_TP == STD_ON) && (PduR_bCANCEL_TX_ENABLED == STD_ON))
/******************************************************************************/
/*! \Description    Function responsible for canceling the transmit requests 
                    that was invoked in a multicasting context over TP layers \n
    \return         E_OK, E_NOT_OK \n
*******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_u8MultiCancelTxRequest(
    VAR(PduIdType, AUTOMATIC)                               udtId)
{
    VAR(Std_ReturnType, AUTOMATIC)                          u8FuncRet;
    VAR(uint8_least, AUTOMATIC)                             u8LoopIdx;
    VAR(PduIdType, AUTOMATIC)                               udtCtrlId;
    VAR(uint8, AUTOMATIC)                                   u8MltTblIdx;

    VAR(PduIdType, AUTOMATIC)                               udtTargetId;
    VAR(uint8, AUTOMATIC)                                   u8DevIdx;

    #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             u16RouteGrp;
    #endif

    VAR(Std_ReturnType, AUTOMATIC)                          u8CnclTxFnRet;

    P2CONST(PduR_tstrTpTxFuncPtrType, AUTOMATIC, PDUR_CFG_CONST)
                                                            pkstrTpTxFp;

    /*! Check udtId is in specified range of normal routing tables or not
        (only normal routing as no gatewaying in reduced mode)                */
    if(     (PduR_u8eState == PDUR_ONLINE) && 
            (udtId < PduR_pkstrePbCfg->udtMultiTpRTSize))
    {
        /*! Initially set local function variables to their default values    */
        u8LoopIdx   = 0;
        u8MltTblIdx = (uint8) udtId;
        udtCtrlId   = astrMULTI_TP_TBL(udtId).udtCntrlId;
        u8FuncRet   = E_NOT_OK;

        /*! Start looping on all destinations in multicast table to cancel Tx */
        while(u8LoopIdx < u8MULTI_TP_TX_COUNT(udtCtrlId))
        {
            /*! Prepare destination id and routing group id                   */
            udtTargetId = astrMULTI_TP_TBL(u8MltTblIdx).udtDstPduRefId;

            /*! Prepare the transmit function pointer                         */
            u8DevIdx    = astrMULTI_TP_TBL(u8MltTblIdx).u8DstPduDeviceId;
            pkstrTpTxFp = pkstrTP_TX_TBL(u8DevIdx);

            /*! Check routing group to see if CancelTx can take place or not  */
            /*! \Trace_To   PduR-CDD-5347(0)                                  */
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            u16RouteGrp = astrMULTI_TP_TBL(u8MltTblIdx).u16RPathGrpId;
            if(PduR_abeRGrpStatus[u16RouteGrp] != FALSE)
            #endif
            {
                /*! Forward the cancel request to the lower layer             */
                /*! \Trace_To   PduR-CDD-0096(0)                              */
                u8CnclTxFnRet = pkstrTpTxFp->pfu8TpCancelTxReq(udtTargetId);

                /*! Set the confirmation result to CANCELATION_OK as the PDUR
                    shall now report a confirmation of a cancelation operation*/
                astrMULTI_TP_CTRL(udtCtrlId).u8ConfResult 
                                                    = NTFRSLT_E_CANCELATION_OK;

                /*! \Trace_To   PduR-CDD-5348(0)                              */
                if(u8CnclTxFnRet != E_OK)
                {
                    /*! One of the destinations failed to cancel transmission,
                        loop shall be terminated and error shall be returned  */
                    u8LoopIdx   = u8MULTI_TP_TX_COUNT(udtCtrlId);
                    u8FuncRet   = E_NOT_OK;
                }
                else
                {
                    u8FuncRet  = E_OK;
                }
            }
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            else
            {
                /*! One of the destinations are disabled in their routing group,
                    loop shall be terminated and error shall be returned      */
                u8LoopIdx   = u8MULTI_TP_TX_COUNT(udtCtrlId);
                u8FuncRet   = E_NOT_OK;
            }
            #endif

            /*! Increment the multicasting table index and the loop index     */
            u8MltTblIdx++;
            u8LoopIdx++;
        }
    }
    /*! udtId to be used in the cancelation operation is out of range         */
    else
    {
        u8FuncRet = E_NOT_OK;
    }

    return u8FuncRet;
}
#endif

#endif /* #if ((PduR_bIFUP_ENABLED == STD_ON ) || (PduR_bTPUP_ENABLED == STD_ON)) */

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if (PduR_bZERO_COST_OPERATION == STD_OFF) */

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */

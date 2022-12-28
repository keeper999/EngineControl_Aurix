/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !File            : PduR_Main.c                                             */
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
/* $Revision::   1.44     $$Author::   sedrees        $$Date::   Aug 24 2014 $*/
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

#include "SchM_PduR.h"

#include "PduR_LocalCfg.h"
#include "PduR_LocalLCfg.h"

#if (PduR_bZERO_COST_OPERATION == STD_OFF)

#if(PduR_bDEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#include "Dem.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define PDUR_START_SEC_VAR_8
#include "Memmap.h"

/******************************************************************************/
/*! \Description    Global variable holding global PDU Router module state \n
    \Range          PDUR_UNINIT, PDUR_ONLINE, PDUR_REDUCED \n
*******************************************************************************/
VAR(PduR_StateType, PDUR_VAR) PduR_u8eState = PDUR_UNINIT;

#define PDUR_STOP_SEC_VAR_8
#include "Memmap.h"

#if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
#define PDUR_START_SEC_VAR_BOOLEAN
#include "Memmap.h"

/******************************************************************************/
/*! \Description    Global array holding the state of the routing path groups
                    at runtime (path enabled/disabled)
    \Range          TRUE (enabled), FALSE (disabled) \n
    \Size           PduR_u16MAX_ROUTE_GRP_NUMBER + 1
*******************************************************************************/
VAR(boolean, PDUR_VAR)
                        PduR_abeRGrpStatus[PduR_u16MAX_ROUTE_GRP_NUMBER + 1UL];

#define PDUR_STOP_SEC_VAR_BOOLEAN
#include "Memmap.h"
#endif

#define PDUR_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

/******************************************************************************/
/*! \Description    Global variable holding a pointer to the post-build config-
                    uration structures of the PDUR module \n
*******************************************************************************/
P2CONST(PduR_PBConfigType, PDUR_VAR, PDUR_APPL_CONST) PduR_pkstrePbCfg;

#define PDUR_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

#endif /* #if (PduR_bZERO_COST_OPERATION == STD_OFF) */

#define PDUR_START_SEC_CODE
#include "Memmap.h"

#if (PduR_bZERO_COST_OPERATION == STD_OFF)

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule: STCYC (Cyclomatic Complexity) and STPTH   */
/*              (Estimated Path Count) are needed to fullfill the needed      */
/*              functionality of the API and can be reduced if not all the    */
/*              features are enabled in the PDUR.                             */
/*              No further simplification is needed.                          */
/* PRQA S 4700 ++                                                             */
/******************************************************************************/
/*! \Description    Initialization function of the PduR module that in case of
                    successful initialization perform: \n
                    - update state and configuration pointer of module \n
                    - release all buffers (mark them all as ready) \n
                    - set data in Tx buffers to the default values defined \n
                    - set status of routing path groups (enabled/disabled) \n
                    In case of initialization failure, the function will update
                    the module's state to reduced and report error to DEM \n
    \return         void \n
    \Trace_To       PduR-CDD-0121(0), PduR-CDD-0122(0), PduR-CDD-0126(0)
    \Trace_To       PduR-CDD-0127(0), PduR-CDD-0157(0), PduR-CDD-0158(0)
    \Trace_To       PduR-CDD-0159(0), PduR-CDD-0160(0), PduR-CDD-5163(0)
    \Trace_To       PduR-CDD-5275(0)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_Init(
    P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_APPL_CONST)  ConfigPtr)
{
    VAR(uint16_least, AUTOMATIC)                                u16Idx;

    #if(PduR_bMULTICASTING_TP == STD_ON)
    VAR(PduIdType, AUTOMATIC)                                   udtIdx;
    VAR(PduIdType, AUTOMATIC)                                   udtMaxMultiTbls;
    #endif

    #if(PduR_bGATEWAYING_IF == STD_ON)
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CONST)    pkstrTxBuff;
    #endif

    /*! Check that the module is NOT initialized                              */
    /*! \Trace_To   PduR-CDD-5334(0)                                          */
    if(PduR_u8eState != PDUR_UNINIT)
    {
        /*! Report to DET if enabled */
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError( PDUR_MODULE_ID,
                                0,
                                PduR_u8INIT_API_ID,
                                PDUR_E_INVALID_REQUEST);
        #endif
    }
    /*! If ConfigPtr is equal to NULL - PduR shall operate in REDUCED mode    */
    else if(ConfigPtr == (const PduR_PBConfigType *) NULL_PTR)
    {
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /*! Enable/Disable routing path groups as configured                  */
        for(    u16Idx = 0; 
                u16Idx <= (uint16) PduR_u16MAX_ROUTE_GRP_NUMBER; 
                u16Idx++)
        {
            PduR_abeRGrpStatus[u16Idx] = PduR_akbeRGrpStatusPC[u16Idx];
        }
        #endif

        /*! Initialize link-time global IPDU's and set them to IDLE           */
        for(u16Idx = 0; u16Idx < PduR_ku8eNumOfGlobalPdus; u16Idx++)
        {
            PduR_au8eGlblPduState[u16Idx] = PduR_u8IDLE;
        }

        /*! Report to DEM and DET accordingly with respective errors          */
        /* Tickets:  to remove StdSW#Pdu Router (PduR)#06357                 */
        /* Dem_ReportErrorStatus(PDUR_E_INIT_FAILED, DEM_EVENT_STATUS_FAILED); */

        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError( PDUR_MODULE_ID,
                                0,
                                PduR_u8INIT_API_ID,
                                PDUR_E_CONFIG_PTR_INVALID);
        #endif

        /*! Set state to PDUR_REDUCED                                         */
        PduR_u8eState = PDUR_REDUCED;
    }
    /*! else - PduR shall operate in NORMAL mode                              */
    else
    {
        /*! No need for critical sections as module is still in UNINIT state  */

        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /*! Enable/Disable routing path groups as configured                  */
        for(    u16Idx = 0; 
                u16Idx <= (uint16) PduR_u16MAX_ROUTE_GRP_NUMBER; 
                u16Idx++)
        {
            PduR_abeRGrpStatus[u16Idx] = PduR_akbeRGrpStatusPC[u16Idx];
        }
        #endif

        /*! Set all Global I-PDUs to IDLE and ready for transmission regardless
            normal or reduced routing is used */
        for(u16Idx = 0; u16Idx < ConfigPtr->u16NumOfGlobalPdus; u16Idx++)
        {
            PduR_au8eGlblPduState[u16Idx] = PduR_u8IDLE;
        }

        #if((PduR_bGATEWAYING_IF == STD_ON) && (PduR_u16MAX_TX_BUFFER_NUMBER > 0UL))
        #if(PduR_u16MAX_TX_BUFFER_NUMBER > 1UL)
        /*! Release all transmission Tx buffers (reset buffer's state)        */
        for(    u16Idx = 0; 
                u16Idx < (uint16) PduR_u16MAX_TX_BUFFER_NUMBER; 
                u16Idx++)
        {
            /*! Grab buffer pointer from buffers array in Cfg.c               */
            pkstrTxBuff = &PduR_akstreTxBuffers[u16Idx];

            /*! Set control information of the FIFO buffer to CLEARED state   */
            PduR_vidTxBuffClear(pkstrTxBuff);
        }
        #else
        /*! Grab buffer pointer from buffers array in Cfg.c               */
        pkstrTxBuff = &PduR_akstreTxBuffers[0];

        /*! Set control information of the FIFO buffer to CLEARED state   */
        PduR_vidTxBuffClear(pkstrTxBuff);
        #endif
        #endif

        #if((PduR_bGATEWAYING_TP == STD_ON) && (PduR_u16MAX_TP_BUFFER_NUMBER > 0UL))
        #if(PduR_u16MAX_TP_BUFFER_NUMBER > 1UL)
        /*! Release all transmission Tp buffers (reset buffer's state)        */
        for(    u16Idx = 0; 
                u16Idx < (uint16) PduR_u16MAX_TP_BUFFER_NUMBER; 
                u16Idx++)
        {
            PduR_astreTpBuffCtrl[u16Idx].bIsFree        = TRUE;
            PduR_astreTpBuffCtrl[u16Idx].udtRxAvBytes   = 0;
            PduR_astreTpBuffCtrl[u16Idx].udtRxIdx       = 0;
            PduR_astreTpBuffCtrl[u16Idx].udtTxAvBytes   = 0;
            PduR_astreTpBuffCtrl[u16Idx].udtTxIdx       = 0;
            #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
            PduR_astreTpBuffCtrl[u16Idx].u16RPathGrpId  = 65535UL;
            #endif
        }
        #else
        PduR_astreTpBuffCtrl[0].bIsFree        = TRUE;
        PduR_astreTpBuffCtrl[0].udtRxAvBytes   = 0;
        PduR_astreTpBuffCtrl[0].udtRxIdx       = 0;
        PduR_astreTpBuffCtrl[0].udtTxAvBytes   = 0;
        PduR_astreTpBuffCtrl[0].udtTxIdx       = 0;
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        PduR_astreTpBuffCtrl[0].u16RPathGrpId  = 65535UL;
        #endif
        #endif
        #endif

        #if(PduR_bMULTICASTING_TP == STD_ON)
        /*! Reset TP TxConfirmation counters                                  */
        /*! \Trace_To   PduR-CDD-5353(1)                                      */
        udtMaxMultiTbls =   ConfigPtr->pkstrMultiTpRTable
                            [ConfigPtr->udtMultiTpRTSize - 1].udtCntrlId;

        for(udtIdx = 0; udtIdx < udtMaxMultiTbls; udtIdx++)
        {
            ConfigPtr->pstrMultiTpCntrl[udtIdx].u8CntrValue = 0;
        }
        #endif

        /*! Set state to PDUR_ONLINE & set PbConfigPtr to the passed value    */
        PduR_pkstrePbCfg    = ConfigPtr;
        PduR_u8eState       = PDUR_ONLINE;
    }

    /*! Start the call(s) to configured modules initialization functions      */
    /*! Call LoTp and Up sub-components initialization function                       */
    for(u16Idx = 0; PduR_akstreBswModuleInitFnPtT[u16Idx].pfvidBswModuleInit != NULL_PTR; u16Idx++)
    {
        PduR_akstreBswModuleInitFnPtT[u16Idx].pfvidBswModuleInit();
    }

}
/* PRQA S 4700 --                                                             */

#if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
/******************************************************************************/
/*! \Description    Enables a routing path group
    \return         void \n
    \Trace_To       PduR-CDD-0130(0), PduR-CDD-0165(0), PduR-CDD-0166(0)
    \Trace_To       PduR-CDD-0167(0), PduR-CDD-5272(1)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_EnableRouting(
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             id)
{

    /*! Check module's initialization                                         */
    if(PduR_u8eState == PDUR_ONLINE)
    {
        /*! Check if the routing group Id is present in the array or not      */
        if(id >= (PduR_RoutingPathGroupIdType) PduR_u16MAX_ROUTE_GRP_NUMBER)
        {
            /*! Id out of range, report to DET if enabled                     */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    PduR_u8ENABLE_RTNG_API_ID,
                                    PDUR_E_ROUTING_TABLE_ID_INVALID);
            #endif
        }
        else
        {
            /*! Id is in range, enable routing group in the local array       */
            PduR_abeRGrpStatus[id] = TRUE;
        }
    }
    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
    else
    {
        /*! Report to DET if enabled                                          */
        (void) Det_ReportError( PDUR_MODULE_ID,
                                0,
                                PduR_u8ENABLE_RTNG_API_ID,
                                PDUR_E_INVALID_REQUEST);
    }
    #endif
}

/* !Deviation : Inhibit MISRA rule: STCYC (Cyclomatic Complexity) and STPTH   */
/*              (Estimated Path Count) are needed to fullfill the needed      */
/*              functionality of the API and can be reduced if not all the    */
/*              features are enabled in the PDUR.                             */
/*              No further simplification is needed.                          */
/* PRQA S 4700 ++                                                             */

/******************************************************************************/
/*! \Description    Disables a routing path group
    \return         void \n
    \Trace_To       PduR-CDD-0131(0), PduR-CDD-0132(0), PduR-CDD-0168(0)
    \Trace_To       PduR-CDD-0169(0), PduR-CDD-0170(0), PduR-CDD-5273(1)
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_DisableRouting(
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             id)
{
    #if((PduR_bGATEWAYING_IF == STD_ON) || (PduR_bGATEWAYING_TP == STD_ON) ||  \
        (PduR_bMULTICASTING_IF == STD_ON) || (PduR_bMULTICASTING_TP == STD_ON))
    VAR(PduIdType, AUTOMATIC)                           udtLoopIdx;
    VAR(uint16, AUTOMATIC)                              u16GlblId;
    #endif

    #if(PduR_bGATEWAYING_IF == STD_ON)
    P2CONST(PduR_tstrTxBuffPCCfgType,  AUTOMATIC, PDUR_CONST)
                                                        pkstrTxBuff;
    P2CONST(PduR_tstrGateIfRTableType, AUTOMATIC, PDUR_CONST)
                                                        pkstrGateIfTbl;
    #endif
    
    #if(PduR_bGATEWAYING_TP == STD_ON)
    VAR(PduIdType, AUTOMATIC)                           udtCtrlId;
    VAR(PduIdType, AUTOMATIC)                           udtGtTpSubRTSize;
    VAR(PduIdType, AUTOMATIC)                           udtGtTpStrtIdx;
    VAR(uint16, AUTOMATIC)                              u16BuffId;
    VAR(boolean, AUTOMATIC)                             bRGrpStatus;
    VAR(boolean, AUTOMATIC)                             bSetHasGrpMember;

    P2CONST(PduR_tstrGateTpRTableType, AUTOMATIC, PDUR_CONST)
                                                        pkstrGateTpTbl;
    P2CONST(PduR_tstrGateTpSubRTType, AUTOMATIC, PDUR_CONST)
                                                        pkstrGateTpSubTbl;
    #endif
    
    #if(PduR_bMULTICASTING_IF == STD_ON)
    P2CONST(PduR_tstrMultiIfRTableType, AUTOMATIC, PDUR_CONST)
                                                        pkstrMltiIfTbl;
    #endif

    #if(PduR_bMULTICASTING_TP == STD_ON)
    P2CONST(PduR_tstrMultiTpRTableType, AUTOMATIC, PDUR_CONST)
                                                        pkstrMltiTpTbl;
    #endif

    /*! Check module's initialization                                         */
    if(PduR_u8eState == PDUR_ONLINE)
    {
        /*! Check if the routing group Id is present in the array or not      */
        if(id >= (PduR_RoutingPathGroupIdType) PduR_u16MAX_ROUTE_GRP_NUMBER)
        {
            /*! Id out of range, report to DET if enabled                     */
            #if(PduR_bDEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError( PDUR_MODULE_ID,
                                    0,
                                    PduR_u8DISBLE_RTNG_API_ID,
                                    PDUR_E_ROUTING_TABLE_ID_INVALID);
            #endif
        }
        else
        {
            /*! Id is in range, disable routing group in the local array      */
            PduR_abeRGrpStatus[id] = FALSE;

            /*! No need for a critical section for further operations as the
                routing group has been automically disabled and no calls will
                be invoked for APIs that has this routing group is disabled   */

            #if(PduR_bGATEWAYING_IF == STD_ON)
            /*! Grab the IF gatewaying table from the PbConfig array          */
            pkstrGateIfTbl = PduR_pkstrePbCfg->pkstrGateIfRTable;

            /*! Loop on all elements in the IF gatewaying PB table            */
            for(    udtLoopIdx = 0; 
                    udtLoopIdx < PduR_pkstrePbCfg->udtGateIfRTSize; 
                    udtLoopIdx++)
            {
                /*! Check if routing group present matches passed group id    */
                if(pkstrGateIfTbl[udtLoopIdx].u16RPathGrpId == id)
                {
                    /*! Set the global I-PDU state to IDLE                    */
                    u16GlblId = pkstrGateIfTbl[udtLoopIdx].u16IPduGlobalId;
                    PduR_au8eGlblPduState[u16GlblId] = PduR_u8IDLE;

                    /*! Grab the IF associated buffer with this ID            */
                    pkstrTxBuff = pkstrGateIfTbl[udtLoopIdx].pkstrTxBuffRef;

                    /*! Check if an IF buffer configured or dest is upper     */
                    if(pkstrTxBuff != (PduR_tstrTxBuffPCCfgType *) NULL_PTR)
                    {
                        /*! Clear IF buffer                                   */
                        PduR_vidTxBuffClear(pkstrTxBuff);
                    }
                }
            }
            #endif

            #if(PduR_bGATEWAYING_TP == STD_ON)
            /*! Grab the TP gatewaying table from the PbConfig array          */
            pkstrGateTpTbl = PduR_pkstrePbCfg->pkstrGateTpRTable;

            /*! Loop on all elements in the TP gatewaying PB table            */
            for(    udtLoopIdx = 0; 
                    udtLoopIdx < PduR_pkstrePbCfg->udtGateTpRTSize;
                    udtLoopIdx++)
            {
                /*! Check if routing group present matches passed group id    */
                if(pkstrGateTpTbl[udtLoopIdx].u16RPathGrpId == id)
                {
                    /*! Set the global Tx I-PDU state to IDLE                 */
                    u16GlblId = pkstrGateTpTbl[udtLoopIdx].u16IPduGlobalId;
                    PduR_au8eGlblPduState[u16GlblId] = PduR_u8IDLE;

                }
            }

            /*! Loop on all TP gatewaying sets to check if there exist a set 
                where all its routing path groups are disabled after disabling
                this ID (in order to free its associated TP buffer            */
            pkstrGateTpSubTbl   = PduR_pkstrePbCfg->pkstrGateTpSubRT;
            udtGtTpSubRTSize    = pkstrGateTpTbl[PduR_pkstrePbCfg->
                                                udtGateTpRTSize - 1].udtCntrlId;

            /*! Loop on the control information to grab nesseccary data       */
            for( udtLoopIdx = 0; udtLoopIdx < udtGtTpSubRTSize; udtLoopIdx++)
            {
                /*! Grab the start index to loop on in the Gate TP table      */
                udtGtTpStrtIdx = pkstrGateTpSubTbl[udtLoopIdx].u8StartId;

                /*! Initialize local used variables to default values         */
                bRGrpStatus         = FALSE;
                bSetHasGrpMember    = FALSE;

                udtCtrlId = pkstrGateTpTbl[udtGtTpStrtIdx].udtCntrlId;
                u16BuffId = PduR_pkstrePbCfg->pstrGateTpCntrl[udtLoopIdx]
                                                                    .u16BuffIdx;

                /*! Loop on the Gate TP table (per the provided information)  */
                while( (udtGtTpStrtIdx < PduR_pkstrePbCfg->udtGateTpRTSize) &&
                       (udtCtrlId == pkstrGateTpTbl[udtGtTpStrtIdx].udtCntrlId))
                {
                    /*! If there exist a routing group that is enabled in this
                        set, the the routing group status of the full set should
                        be marked as TRUE (as the buffer can be in use now)   */
                    if(PduR_abeRGrpStatus[pkstrGateTpTbl[udtGtTpStrtIdx].
                                                        u16RPathGrpId] == TRUE)
                    {
                        bRGrpStatus = TRUE;
                    }

                    /*! If the routing group ID passed has a corresponding match
                        in the set being processed, set the member to TRUE    */
                    if(pkstrGateTpTbl[udtGtTpStrtIdx].u16RPathGrpId == id)
                    {
                        bSetHasGrpMember = TRUE; 
                    }

                    /*! Increment the loop indexer                            */
                    udtGtTpStrtIdx++;
                }

                /*! If all destination's routing path group is now disabled and
                    the passed group ID is a match in this set                */
                if( (bRGrpStatus == FALSE) && (bSetHasGrpMember == TRUE) )
                {
                    /*! Release/Free the associated TP buffer                 */
                    PduR_astreTpBuffCtrl[u16BuffId].bIsFree = TRUE;
                    
                    /*! Set the global Rx I-PDU state to IDLE                 */
                    u16GlblId   = PduR_pkstrePbCfg->pkstrGateTpSubRT[udtCtrlId]
                                                                .u16RxGlobalId;
                    PduR_au8eGlblPduState[u16GlblId] = PduR_u8IDLE;                    
                }
            }
            #endif

            #if(PduR_bMULTICASTING_IF == STD_ON)
            /*! Grab the IF multicasting table from the PbConfig array        */
            pkstrMltiIfTbl = PduR_pkstrePbCfg->pkstrMultiIfRTable;

            /*! Loop on all elements in the IF gatewaying PB table            */
            for(    udtLoopIdx = 0; 
                    udtLoopIdx < PduR_pkstrePbCfg->udtMultiIfRTSize; 
                    udtLoopIdx++)
            {
                /*! Check if routing group present matches passed group id    */
                if(pkstrMltiIfTbl[udtLoopIdx].u16RPathGrpId == id)
                {
                    /*! Set the global I-PDU state to IDLE                    */
                    u16GlblId = pkstrMltiIfTbl[udtLoopIdx].u16IPduGlobalId;
                    PduR_au8eGlblPduState[u16GlblId] = PduR_u8IDLE;
                }
            }
            #endif

            #if(PduR_bMULTICASTING_TP == STD_ON)
           /*! Grab the TP multicasting table from the PbConfig array        */
            pkstrMltiTpTbl = PduR_pkstrePbCfg->pkstrMultiTpRTable;

            /*! Loop on all elements in the TP gatewaying PB table            */
            for(    udtLoopIdx = 0; 
                    udtLoopIdx < PduR_pkstrePbCfg->udtMultiTpRTSize; 
                    udtLoopIdx++)
            {
                /*! Check if routing group present matches passed group id    */
                if(pkstrMltiTpTbl[udtLoopIdx].u16RPathGrpId == id)
                {
                    /*! Set the global I-PDU state to IDLE                    */
                    u16GlblId = pkstrMltiTpTbl[udtLoopIdx].u16IPduGlobalId;
                    PduR_au8eGlblPduState[u16GlblId] = PduR_u8IDLE;
                }
            }
            #endif
        }
    }
    #if(PduR_bDEV_ERROR_DETECT == STD_ON)
    else
    {
        /*! Report to DET if enabled                                          */
        (void) Det_ReportError( PDUR_MODULE_ID,
                                0,
                                PduR_u8DISBLE_RTNG_API_ID,
                                PDUR_E_INVALID_REQUEST);
    }
    #endif
}
#endif

/* PRQA S 4700 --                                                             */

/******************************************************************************/
/*! \Description    Returns the unique identifier of the configuration used \n
    \return         PduR_PBConfigIdType \n
    \Trace_To       PduR-CDD-0163(0), PduR-CDD-0164(0), PduR-CDD-5271(1)
*******************************************************************************/
FUNC(PduR_PBConfigIdType, PDUR_CODE) PduR_GetConfigurationId(void)
{
    VAR(PduR_PBConfigIdType, AUTOMATIC)                     u16Return;

    /*! Check module's initialization                                         */
    if(PduR_u8eState != PDUR_ONLINE)
    {
        /*! Report to DET if enabled                                          */
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError( PDUR_MODULE_ID,
                                0,
                                PduR_u8GET_CFG_ID_API_ID,
                                PDUR_E_INVALID_REQUEST);
        #endif

        /*! Error in configuration, return 0                                  */
        u16Return = 0x00;
    }
    else
    {
        /*! Module is correctly, initialized, return configuration Id         */
        u16Return = PduR_pkstrePbCfg->u16ConfigurationId;
    }

    return u16Return;
}

/******************************************************************************/
/*! \Description    Clears the buffer and mark it as ready \n
    \return         void \n
*******************************************************************************/
FUNC(void, PDUR_CODE) PduR_vidTxBuffClear(
    P2CONST(PduR_tstrTxBuffPCCfgType, AUTOMATIC, PDUR_CFG_CONST) pkstrTxBuff)
{
    pkstrTxBuff->pstrBuffCtrl->u8Count = 0;
    pkstrTxBuff->pstrBuffCtrl->u8First = 0;
    pkstrTxBuff->pstrBuffCtrl->u8Last  = pkstrTxBuff->u8BuffDepth - 1;
}

#endif /* #if (PduR_bZERO_COST_OPERATION == STD_OFF) */

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */

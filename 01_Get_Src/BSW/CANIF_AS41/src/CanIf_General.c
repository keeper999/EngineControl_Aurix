/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                     */
/*                                                                            */
/*\!Component       : CanIf                                                   \n
    Description     : It represents the interface to the services of            
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_General                                           */
/*!\file            : CanIf_General.c                                         \n
    \Description    : This subcomponent is responsible for general            \n
                      functionalities that canot be in other sub-components   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/17_CanIf/0$*/
/* $Revision::   1.30     $$Author::   mamroussy   $$Date::   Aug 03 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/* PRQA S 0838,0863,0862 EOF */
/*MISRA Msg justification:   not included Multi Times QAC Violation*/
/* PRQA S 0850 EOF */
/*MISRA Msg justification:   Inhibit MISRA rule [0838]: AUTOMATIC keyword is    
                             defined as an empty macro                        */
/* PRQA S 0857 EOF */
/* MISRA Msg justification:  Number of macro definitions exceeds 1024 
                             as the module needs a lot of macro(s)            */	
#include "CanIf.h"
#include "CanIf_LocalCfg.h"
#include "CanIf_LocalLCfg.h"
#include "CanIf_PBCfg.h"
#include"CanIf_General.h"
#include"CanIf_Transmission.h"
#include"CanIf_Reception.h"
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
#include "Det.h"
#endif
/**********************      Version Checking       ***************************/
#define u8C_SW_MAJOR_VERSION    (2)
#define u8C_SW_MINOR_VERSION    (0)

/******************************************************************************/
/*                      Implementation version checking                       */
/******************************************************************************/
/*                           Intra-Module Checking                            */
/******************************************************************************/
#if (u8C_SW_MAJOR_VERSION != CANIF_SW_MAJOR_VERSION)
    #error Incompatible ComM SW major version between C & H files.
#endif

#if (u8C_SW_MINOR_VERSION != CANIF_SW_MINOR_VERSION)
    #error Incompatible ComM SW minor version between C & H files.
#endif

/******************************************************************************/
/* Inter-Module Checking - Module Header Files and Module C Files             */
/******************************************************************************/
#if (CanIf_bINTER_MOD_VER_CHECK == STD_ON)
#if (CANIF_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)
    #error Compiler AR RELEASE MAJOR VERSION is not compatible with CANIF AR \
           RELEASE MAJOR VERSION.
#endif
#if (CANIF_AR_RELEASE_MINOR_VERSION < COMPILER_AR_RELEASE_MINOR_VERSION)
    #error Compiler AR RELEASE MINOR VERSION is not compatible with CANIF AR \
           RELEASE MINOR VERSION.
#endif
#if (CANIF_AR_RELEASE_MAJOR_VERSION != MEM_AR_RELEASE_MAJOR_VERSION)
    #error MemMap AR RELEASE MAJOR VERSION is not compatible with CANIF AR \
           RELEASE MAJOR VERSION.
#endif
#if (CANIF_AR_RELEASE_MINOR_VERSION < MEM_AR_RELEASE_MINOR_VERSION)
    #error MemMap AR RELEASE MINOR VERSION is not compatible with CANIF AR \
           RELEASE MINOR VERSION.
#endif
#if (CANIF_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
    #error Std AR RELEASE MAJOR VERSION is not compatible with CANIF AR \
           RELEASE MAJOR VERSION.
#endif
#if (CANIF_AR_RELEASE_MINOR_VERSION < STD_AR_RELEASE_MINOR_VERSION)
    #error Std AR RELEASE MINOR VERSION is not compatible with CANIF AR \
           RELEASE MINOR VERSION.
#endif

#if (CANIF_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION)
    #error Platform AR RELEASE MAJOR VERSION is not compatible with CANIF AR \
           RELEASE MAJOR VERSION.
#endif
#if (CANIF_AR_RELEASE_MINOR_VERSION < PLATFORM_AR_RELEASE_MINOR_VERSION)
    #error Platform AR RELEASE MINOR VERSION is not compatible with CANIF AR \
           RELEASE MINOR VERSION.
#endif

#if (CANIF_AR_RELEASE_MAJOR_VERSION != COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION)
    #error ComStackType AR RELEASE MAJOR VERSION is not compatible with CANIF \
           AR RELEASE MAJOR VERSION.
#endif
#if (CANIF_AR_RELEASE_MINOR_VERSION < COMSTACKTYPE_AR_RELEASE_MINOR_VERSION)
    #error ComStackType AR RELEASE MINOR VERSION is not compatible with CANIF \
           AR RELEASE MINOR VERSION.
#endif

#if (CanIf_bDEV_ERR_DETECT == STD_ON)
#if (CANIF_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)
    #error Det AR RELEASE MAJOR VERSION is not compatible with CANIF AR \
           RELEASE MAJOR VERSION.
#endif
#if (CANIF_AR_RELEASE_MINOR_VERSION < DET_AR_RELEASE_MINOR_VERSION)
    #error Det AR RELEASE MINOR VERSION is not compatible with CANIF AR \
           RELEASE MINOR VERSION.
#endif
#endif  /* CanIf_bDEV_ERR_DETECT == STD_ON */
#endif	/* CanIf_bINTER_MOD_VER_CHECK == STD_ON */


#define CANIF_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/
/*!  \Description General Sate of Canif Initialized or un initialized         \n
     \Renge  CanIf_UNINITIALAIZED,CanIf_INITIALAIZED                            
*******************************************************************************/
VAR(CanIf_tenuGeneralState, CANIF_VAR) CanIf_enueGeneralState
        =CanIf_UNINITIALAIZED;
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/* PRQA L:L1 */ 

/******************************************************************************/
/*!  \Description Pointer to configuration parameter set, used for post build   
                  parameters.                                                   
*******************************************************************************/
P2CONST(CanIf_ConfigType,CANIF_VAR,CANIF_APPL_CONST)
    CanIf_pkstreConfigPtr;
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */
/******************************************************************************/
/*!\Description : This service Initializes internal and external interfaces     
                   of the CAN Interface for the further processing.           \n
    \param[in]     ConfigPtr: Pointer to configuration parameter set,           
                   used e.g. for post build parameters                        \n
    \Range         Not Null                                                   \n
    \Trace_To CANIF-CDD-0163(0)                                                 
*******************************************************************************/
/* PRQA S 4700 ++ */
/*MISRA Msg justification:  to avoid Long execution time                      */
FUNC(void, CANIF_CODE)CanIf_Init(
    P2CONST(CanIf_ConfigType,AUTOMATIC,CANIF_APPL_CONST)ConfigPtr)
{
    /*local variable to be used in looping                                   */
    VAR(uint32_least, AUTOMATIC) u32InitIndex;
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
	P2VAR(CanIf_tstrDynamicTxPduCanId, AUTOMATIC, AUTOMATIC)
                               pudtDynTxPduCanId;
#endif
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON || CanIf_bREAD_TX_NOTIF_API==STD_ON)
/* PRQA S 8018,8318,8518 ++ */
	P2CONST(CanIf_tstrTxPduPbCfg, AUTOMATIC, AUTOMATIC) 
                              pkudtTxPduPbCfg;
/* PRQA S 8018,8318,8518 -- */
#endif
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)								  
	P2VAR(CanIf_NotifStatusType, AUTOMATIC, AUTOMATIC)
                               penuTxNotifStat;
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)								   
	P2VAR(CanIf_NotifStatusType, AUTOMATIC, AUTOMATIC)
                               penuRxNotifStat;
/* PRQA S 8018,8318,8518 ++ */
	P2CONST(CanIf_tstrRxPduPbCfg, AUTOMATIC, AUTOMATIC)
                                 pkudteRxPduPbCfg;
/* PRQA S 8018,8318,8518 -- */
#endif							   
    /* \Trace_To CANIF-CDD-0166(0)                                            */
    /*!If parameter ConfigPtr of CanIf_Init() has an invalid value            */
    /* PRQA S 1311 ++ */
    /*MISRA Msg justification:   (casting to (void *) Compiler.h COTS)        */
    /* \Trace_To CANIF-CDD-0165(0)                                            */
    if(ConfigPtr==NULL_PTR)
    {
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        /*!report development error code CANIF_E_PARAM_POINTER to the 
           Det_ReportError                                                    */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8INIT_API,CANIF_E_PARAM_POINTER);
#endif
    }
    /* PRQA S 1311 -- */
    /*!else                                                                   */
    else
    {
        /*!Copy ConfigPtr input pointer to CanIf_pkstreConfigPtr              */
        CanIf_pkstreConfigPtr = ConfigPtr;
        /* \Trace_To CANIF-CDD-0164(0)                                        */
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
		pudtDynTxPduCanId=CanIf_udtGET_DYCANID_PBCFG;
		pkudtTxPduPbCfg=CanIf_udtGET_TXPDU_PBCFG;
        /*!for all TxpduIds                                                   */
        for(u32InitIndex=0;u32InitIndex<CanIf_udtGET_NUMOFTX_PBCFG;
            u32InitIndex++)
        {
            /*!if TxPdu is Dynamic                                            */
            if(pkudtTxPduPbCfg[u32InitIndex].enuTXPduType == CanIf_DYNAMIC)
            {
                /*!initialize TxPdu Dynamic Canid with Configured CanId       */
                pudtDynTxPduCanId[pkudtTxPduPbCfg[u32InitIndex].udtDyCanIdIndex].
                    udtCanId = pkudtTxPduPbCfg[u32InitIndex].udtCanId;
                /*!initialize Txpdu Canid Type with Configured CanidType      */
                pudtDynTxPduCanId[pkudtTxPduPbCfg[u32InitIndex].udtDyCanIdIndex].
					udtCanIdType = pkudtTxPduPbCfg[u32InitIndex].enuCanIdType;
            }
#if(CanIf_bTX_BUFFERING==STD_ON)
            /*!initialize every transmit L-PDU buffer assigned to the CanIf   */
            /* \Trace_To CANIF-CDD-0050(0)                                    */
            /* \Trace_To CANIF-CDD-0164(0)                                    */
            /*!Clear all Transmit buffers                                     */
            /*!Reset Queued flag for this TxPdu                               */
			if(pkudtTxPduPbCfg[u32InitIndex].CanIf_pudteTxBufferRefer
                !=NULL_PTR)
			{
                 pkudtTxPduPbCfg[u32InitIndex].CanIf_pudteTxBufferRefer->u8TxbufferStatus = CanIf_u8EMPTY_BUFFER;
			
			}
			
#endif
        }
#endif
        /* \Trace_To CANIF-CDD-0164(0)                                        */
        /*!for All Controllers                                                */
        for(u32InitIndex=0;u32InitIndex<CanIf_ku8eNumOfControllers;
            u32InitIndex++)
        {
            /*!Initialize all Pdu Channels to be Rx ONLINE                    */
            CanIf_astreCurrPduChannelMode[u32InitIndex].enuRxPath = 
                CanIf_RX_PATH_ONLINE;
             /*!Initialize all Pdu Channels to be Tx ONLINE                   */
            CanIf_astreCurrPduChannelMode[u32InitIndex].enuTxPath = 
                CanIf_TX_PATH_ONLINE;
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
			CanIf_astreCurrPduChannelMode[u32InitIndex].bPnTxfilter = FALSE;
#endif
            /*!take the CCMSM for every assigned CAN controller to state 
               CANIF_CS_INIT                                                  */
            /*!take that CCMSM to sub state CANIF_CS_STOPPED of state 
               CANIF_CS_INIT.                                                 */
            /*!don't Care about Current State CANIF_CS_INIT or 
               CANIF_CS_UNINIT                                                */
            /* \Trace_To CANIF-CDD-0068(0)                                    */
            /* \Trace_To CANIF-CDD-0069(0)                                    */
            /* \Trace_To CANIF-CDD-0164(0)                                    */
            /* \Trace_To CANIF-CDD-0070(0)                                    */
             /*!Initialize all Controllrers to be STOPPED                     */
            CanIf_aenueCurrControllerMode[u32InitIndex] = CANIF_CS_STOPPED;
#if (CanIf_bTXCONF_POLL_SUPPORT == STD_ON)
            /* \Trace_To CANIF-CDD-0164(0)                                    */
            /*!Clear all TxConfirmation States                                */
            CanIf_vidClearTxConfirmState((uint8)u32InitIndex);
#endif
#if ((CanIf_bWAKUP_CHK_VALID_API == STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
            /*!if Wakeup Support Enabled                                      */
            if(CanIf_akstreCtrlLCfg[u32InitIndex].bWakeupSupport
                ==STD_ON)
            {
                /*!clear all temporary stored wakeup events, 
                if CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API is enabled.       */
                /* \Trace_To CANIF-CDD-5220(0)                                */
                /* \Trace_To CANIF-CDD-0120(0)                                */
                /* \Trace_To CANIF-CDD-0164(0)                                */
                CanIf_astreCtrlWakeup[CanIf_akstreCtrlLCfg[u32InitIndex].
                    u8WkupEventIndex].bWakeupEvent=E_NOT_OK;
                /*!clear all temporary stored Wakeup Validation Events, 
                if CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API is enabled.       */
                CanIf_astreCtrlWakeup[CanIf_akstreCtrlLCfg[u32InitIndex].
                    u8WkupEventIndex].bWakeupValidation=E_NOT_OK;
            }
#endif
        }
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
		penuTxNotifStat=CanIf_udtGET_TXNOTIF_PBCFG;
        /*!for all TxPdus                                                     */
        for(u32InitIndex=0;u32InitIndex<CanIf_udtGET_NUMOFTX_PBCFG;
            u32InitIndex++)
        {
            /*!if Tx Notification status is enabled                           */
            if(pkudtTxPduPbCfg[u32InitIndex].bReadNotifyStatus ==STD_ON)
            {
                /*!clear Tx Notification status                               */
                /* \Trace_To CANIF-CDD-0164(0)                                */
                penuTxNotifStat[pkudtTxPduPbCfg[u32InitIndex].
                    udtNotifyStatusIndex]=CANIF_NO_NOTIFICATION;
            }
        }
#endif
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
		penuRxNotifStat=CanIf_udtGET_RXNOTIF_PBCFG;
		pkudteRxPduPbCfg=CanIf_udtGET_RXPDU_PBCFG;
        /*!for all RxPdus                                                     */
        for(u32InitIndex=0;u32InitIndex<CanIf_udtGET_NUMOFRX_PBCFG;
            u32InitIndex++)
        {
            /*!if Rx Notification status is enabled                           */
            if(pkudteRxPduPbCfg[u32InitIndex].bReadNotifyStatus ==STD_ON)
            {
                /*!clear Rx Notification status                               */
                /* \Trace_To CANIF-CDD-0164(0)                                */
                penuRxNotifStat[pkudteRxPduPbCfg[
					u32InitIndex].udtNotifyStatusIndex]=CANIF_NO_NOTIFICATION;
            }
        }
#endif
        /* \Trace_To CANIF-CDD-0164(0)                                        */
        /*!Change Canif Initialization state to be Initialized                */
        CanIf_enueGeneralState=CanIf_INITIALAIZED;
    }
}
/* PRQA S 4700 -- */

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */ 
/*--------------------------------End of File---------------------------------*/
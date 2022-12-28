/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_Transmission                                      */
/*!\file            : CanIf_Transmission.c                                    \n
    \Description    : Responsible for transmission related functionalities    */
/*                                                                            */
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
/* $Revision::   1.51     $$Author::   mamroussy      $$Date::   Jul 30 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* PRQA S 0838,0863,0862 EOF */
/*MISRA Msg justification:   not included Multi Times QAC Violation           */
/* PRQA S 0850 EOF */
/*MISRA Msg justification:   Inhibit MISRA rule [0838]: AUTOMATIC keyword is    
                             defined as an empty macro                        */
/* PRQA S 0857 EOF */
/* MISRA Msg justification:  Number of macro definitions exceeds 1024 
                             as the module needs a lot of macro(s)            */  							 
#include"CanIf.h"
#include "CanIf_LocalCfg.h"
#include "CanIf_LocalLCfg.h"
#include "CanIf_PBCfg.h"
#include"CanIf_Transmission.h"
#include"CanIf_Reception.h"
#include"CanIf_General.h"
#include "SchM_CanIf.h"
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
#include "Det.h"
#endif
#if(CanIf_bDEM_ERR_DETECT == STD_ON)
#include "Dem.h"
#endif
/******************************Version Checking********************************/
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
/*                               Private Symbols                              */
/******************************************************************************/
#define u16INVLD_DEM_E_STOP_ID                                  ((uint16)0xFFFFUL)


#define CANIF_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************/
/*                          LOCAL FUNCTION DECLARATION                        */
/******************************************************************************/
#if(CanIf_bTX_BUFFERING==STD_ON)
/******************************************************************************/
/*!\Description : This service stores data in CanTxpdu faied to be transmitted
                   in its buffer                                              \n
    \param[in]     udtSource: source to copy from                             \n
    \Range         not null                                                   \n
    \param[out]     udtDestination: destination to copy to                    \n
    \Range         not null                                                   \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
static FUNC(void, CANIF_CODE) vidCopyCanPdu(
                                P2CONST(Can_PduType, AUTOMATIC, CANIF_VAR)
                                udtSource,
                                P2VAR(CanIf_tstrLocalPduType,AUTOMATIC,CANIF_VAR)
                                udtDestination);
/******************************************************************************/
/*!\Description : This service Sends the highest priority TxPdu buffered     \n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU to be transmitted.     
                   This handle specifies the corresponding CAN L-PDU ID and
                   implicitly the CAN Driver instance as well as the            
                   corresponding CAN controller device.                       \n
    \Range         0.. PbCfg.CanIf_udtNumofTxPdus-1                           \n
*******************************************************************************/
static FUNC(void, CANIF_CODE)vidHandleTransmitBuffer(
                                VAR(PduIdType ,AUTOMATIC)CanTxPduId);
/******************************************************************************/
/*!\Description : this service gets the highest priority TxPdu to be            
                   transmitted if found and if not returns                      
                   CanIf_u8INVALID_TXPDU                                      \n
    \param[in]     udtTxPduStart: start index of TxPduIds buffer to start       
                   searching from                                             \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
    \param[in]     u16Hth: Hth that all searching process will take place in 
                   all buffers of Txpdus assigned to it                       \n
    \Range         0..CanIf_ku16eNumOfHth-1                                   \n
    \return        Highest Priority TxPdu buffered                            \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
*******************************************************************************/
/* PRQA S 3447,8023,8223,8423 ++ */
/*MISRA Msg justification: Local Inlining                                     */
LOCAL_INLINE FUNC(PduIdType, CANIF_CODE)udtGetHighPriorityTxpdu(
                                VAR(PduIdType ,AUTOMATIC)udtTxPduStart
                                ,VAR(uint16, AUTOMATIC) u16Hth);
/* PRQA S 3447,8023,8223,8423 -- */
/******************************************************************************/
/*!\Description : Normalize CanId (if needed)to make standard CanIds            
                   corresponds to Base Id of Extended one                     \n
    \param[in]     CanTxPduId: TxPduId that is required to normalize it         
                   CabnId                                                     \n
    \Range         0.. PbCfg.CanIf_udtNumofTxPdus-1                           \n
    \return        CanId after normalization                                  \n
    \Range         0x..1FFFFFFF                                               \n
*******************************************************************************/
static FUNC(Can_IdType, CANIF_CODE)udtGetNormalizedCanId(
                                 VAR(PduIdType ,AUTOMATIC)CanTxPduId);
/******************************************************************************/
/*!\Description : To Get Standard CanId in case comparing 2 CanIds (Same)       
                   Base Id(return TxPduId of the Standard CanId)              \n
    \param[in]     udtTxPduNext: Next TxPduId with same Can Id as               
                   udtTxPduSearch                                             \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
    \param[in]     udtTxPduSearch: xx                                         \n
    \return        Standard TxPduId                                           \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
*******************************************************************************/
/* PRQA S 3447,8023,8223,8423 ++ */
/*MISRA Msg justification: Local Inlining                                     */
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
LOCAL_INLINE FUNC(PduIdType, CANIF_CODE)udtHandleSESameCanId(
                                 VAR(PduIdType ,AUTOMATIC)udtTxPduNext
                                 ,VAR(PduIdType ,AUTOMATIC)udtTxPduSearch);
#endif
/* PRQA S 3447,8023,8223,8423 -- */
#endif
/******************************************************************************/
/*!\Description : this service get Can Id from RAM or Flash                     
                   (Static or Dynamic) and Set BIF or not                       
                   (Extended or Standard)                                     \n
    \param[in]     CanTxPduId: CanTxPduId: L-PDU handle of CAN L-PDU            
                   to be transmitted.This handle specifies the corresponding    
                   CAN L-PDU ID and implicitly the CAN Driver instance as       
                   well as the corresponding CAN controller device.           \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
    \return        BIF##CanId                                                 \n
    \Range         BIF##CanId                                                 \n
*******************************************************************************/
/* PRQA S 3447,8023,8223,8423 ++ */
/*MISRA Msg justification: Local Inlining                                     */
LOCAL_INLINE FUNC(Can_IdType, CANIF_CODE)udtSetCanId(
    CONST(PduIdType ,AUTOMATIC)udtCanTxPduId);
/* PRQA S 3447,8023,8223,8423 -- */    
/******************************************************************************/
/*                          GLOBAL FUNCTION DEFINITIONS                       */
/******************************************************************************/
/******************************************************************************/
/*!\Description : This service initiates a request for transmission of the 
                   CAN L-PDU specified by the CanTxPduId and CAN related data \n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU to be transmitted.
                   This handle specifies the corresponding CAN L-PDU ID and
                   implicitly the CAN Driver instance as well as the 
                   corresponding CAN controller device.                       \n
    \Range         0.. PbCfg.CanIf_udtNumofTxPdus-1                           \n
    \param[in]     PduInfoPtr: Pointer to a structure with CAN L-PDU 
                   related data: DLC and pointer to CAN L-SDU buffer          \n
    \Range         not null                                                   \n
    \return        Transmit request has been accepted or not                  \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0178(0)                                      
*******************************************************************************/
/* PRQA S 4700 ++ */
/*MISRA Msg justification:  Already Internal Services used , If more exec time 
will exceeds Normal                                                           */
FUNC(Std_ReturnType, CANIF_CODE)CanIf_Transmit(
    VAR(PduIdType, AUTOMATIC) CanTxPduId,
    P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_CONST)PduInfoPtr)
{
/* PRQA S 0781 ++ */
/*MISRA Msg justification:  names in Struct may be Repeated in Local Variables*/
    /*Local Variables                                                         */
    /* initialize return with E_NOT_OK                                        */
    VAR(Std_ReturnType, AUTOMATIC)              udtResult= E_NOT_OK;
    /* Can Write Result*/
    VAR(Can_ReturnType, AUTOMATIC)              udtWriteResult;
    /* Controller that TxPduId cancelled assigned to                          */
    VAR(uint8, AUTOMATIC)                       u8ControllerId;
    /* Hth that TxPduId cancelled assigned to                                 */
    VAR(uint16, AUTOMATIC)                      u16Hth;
     /* Index of TxPduID in the akstrTxPduPbCfg table                         */
    VAR(uint16, AUTOMATIC)                      u16TxPduIdIndex;
    /* Can Driver that TxPduId cancelled assigned to                          */
    VAR(uint8, AUTOMATIC)                       u8CanDrv;
    /*Local TxPdu of  Can_PduType to be filled with Data to be 
    transmitted or buffered                                                   */
    VAR(Can_PduType, AUTOMATIC)                 udtLocalTxPdu;
    /* Hth reference that TxPduId cancelled assigned to                       */
    VAR(Can_HwHandleType, AUTOMATIC)            udtHthRef;
    /* controller mode that TxPduId cancelled assigned to                     */
    VAR(CanIf_ControllerModeType, AUTOMATIC)    udtCurrControlMode;
    /* Pdu channel mode that TxPduId cancelled assigned to                    */
    VAR(CanIf_tenuTxPathMode, AUTOMATIC)    enuLocalTxPath;
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
	VAR(boolean, AUTOMATIC)	bLocalPnTxfilter;
#endif
	VAR(CanIf_tpfenuWrite, AUTOMATIC) LOC_pfenuWrite;
#if(CanIf_bTX_BUFFERING==STD_ON)
	P2VAR(uint8, AUTOMATIC, AUTOMATIC)	pu8TxbuffStatus;
	P2VAR(CanIf_tstrLocalPduType, AUTOMATIC, AUTOMATIC)	pudtBuffMessage;
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)
/* PRQA S 8018,8318,8518,8618 ++ */
	P2CONST(CanIf_tstrCriticalSection, AUTOMATIC, AUTOMATIC)	
												pkstreRxBuffCriticalSec;
/* PRQA S 8018,8318,8518,8618 -- */
#endif
#endif
    /* Pdu channel mode that TxPduId cancelled assigned to                    */
    VAR(PduLengthType, AUTOMATIC)               udtUsedLength;

/* PRQA S 0781 -- */
/*! #if CANIF_DEV_ERROR_DETECT is enabled                                     */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! if CanIf isnot initialized                                            */
    /* \Trace_To CANIF-CDD-5037(0)                                            */
    /* \Trace_To CANIF-CDD-0185(0)                                            */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report to the DET (using CANIF_E_UNINIT) and return E_NOT_OK      */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8TRANSMIT_API,CANIF_E_UNINIT);
        /*!return E_NOT_OK(leave udtResult as initialized)                    */
    }
    /*! elseif CanTxPduId input parameter is invalid (more than maximum the
        number of configured TxPdus)                                          */
    /* \Trace_To CANIF-CDD-0183(0)                                            */
    else if(CanTxPduId>=CanIf_udtGET_NUMOFTX_PBCFG)
    {
        /*! Report to the DET (using CANIF_E_INVALID_TXPDUID) 
        and return E_NOT_OK                                                   */
        /*!return E_NOT_OK(leave udtResult as initialized)                    */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8TRANSMIT_API,CANIF_E_INVALID_TXPDUID);
    }
    /*! elseif PduInfoPtr input parameter is Null Pointer                     */
    /* \Trace_To CANIF-CDD-0184(0)                                            */
    /* PRQA S 1311 ++ */
    /* MISRA Msg justification:   (casting to (void *) Compiler.h COTS)       */
    else if(PduInfoPtr==NULL_PTR)
        /* PRQA S 1311 -- */
    {
        /*! Report to the DET (using CANIF_E_PARAM_POINTER) and return E_NOT_OK
                                                                              */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8TRANSMIT_API,CANIF_E_PARAM_POINTER);
        /*!return E_NOT_OK(leave udtResult as initialized)                    */
    }
    /*! elseif PduInfoPtr->SduDataPtr is Null Pointer                         */
    /* \Trace_To CANIF-CDD-0184(0)                                            */
    /* PRQA S 1311 ++ */
    /*MISRA Msg justification:   (casting to (void *) Compiler.h COTS)        */
    else if(PduInfoPtr->SduDataPtr==NULL_PTR)
        /* PRQA S 1311 -- */
    {
        /*! Report to the DET (using CANIF_E_PARAM_POINTER) and return E_NOT_OK
                                                                              */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8TRANSMIT_API,CANIF_E_PARAM_POINTER);
        /*! return E_NOT_OK(leave udtResult as initialized)                   */
    }
    /*! else                                                                  */
    else
#endif
    {
        /*! Get index of TxPdu in the CanIf_pudtTxPduPbCfg table              */
        u16TxPduIdIndex =  CanIf_udtGET_TXPDU_MAP_PBCFG[CanTxPduId];
        /* \Trace_To CANIF-CDD-0180(0)                                        */
        /*! Get Hth that input parameter CanTxPduId is assigned to from Config*/
        u16Hth=CanIf_udtGET_TXPDU_PBCFG[u16TxPduIdIndex].u16Hth;
        /*! Get Hth reference in CanDrv that corresponds to Hth from Config   */
        udtHthRef = CanIf_akstreHthLCfg[u16Hth].udtCanHthRef;
        /*! Get Controller Id that of Hth from Config                         */
        u8ControllerId=CanIf_akstreHthLCfg[u16Hth].u8ControllerId;
        /*! Get Can Driver Id that of Controller from Config                  */
        u8CanDrv=CanIf_akstreCtrlLCfg[u8ControllerId].u8CanDrvId;
        /*! Get current Controller mode                                       */
        SchM_Enter_CanIf_CurrConMode_05();
        udtCurrControlMode=CanIf_aenueCurrControllerMode[u8ControllerId];
        SchM_Exit_CanIf_CurrConMode_05();
        /*! Get current L-Pdu Channel mode                                    */
        SchM_Enter_CanIf_PduChnlMod_05();
		enuLocalTxPath=CanIf_astreCurrPduChannelMode[u8ControllerId].enuTxPath;
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
		bLocalPnTxfilter=CanIf_astreCurrPduChannelMode[u8ControllerId].bPnTxfilter;
#endif
        SchM_Exit_CanIf_PduChnlMod_05();
        /*! if (the physical channel (defined by ControllerId) that the input   
        parameter CanTxPduId is assigned to is in CANIF_GET_OFFLINE_ACTIVE      
        OR CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE OR CANIF_GET_ONLINE OR            
        CANIF_GET_TX_ONLINE)AND(Controller mode (defined by ControllerId)that   
        the input parameter CanTxPduId is assigned to is in CANIF_CS_STARTED)   
        Resume Tranmit Process                                                */
        /* \Trace_To CANIF-CDD-0179(0),CANIF-CDD-5278(0),CANIF-CDD-5279(0)
									  ,CANIF-CDD-5280(0),CANIF-CDD-0514(0)    */
        if(
            (udtCurrControlMode==CANIF_CS_STARTED)&&
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
			((CanIf_udtGET_CTRL_PBCFG[u8ControllerId].bPnFilterIsEffective == FALSE)
			||(bLocalPnTxfilter == FALSE)
			||(CanIf_udtGET_TXPDU_PBCFG[u16TxPduIdIndex].bCanIfTxPduPnFilter == TRUE))&&
#endif
            ((enuLocalTxPath==CanIf_TX_PATH_ONLINE)||
            (enuLocalTxPath==CanIf_TX_PATH_OFF_ACTIVE))
            &&(PduInfoPtr->SduLength!=0)
            )
        {
                /*!used length is received one                                */
                udtUsedLength=PduInfoPtr->SduLength;
            /* PRQA S 2215 ++*/
            /*MISRA Msg justification:Indentation depends on. CanIf_bDLC_CHECK
              Config                                                          */
            udtLocalTxPdu.sdu=PduInfoPtr->SduDataPtr;
            /* PRQA S 2215 -- */
            /*!Load Local TxPdu with Length from PduInfoPtr input parameter   */
            udtLocalTxPdu.length=udtUsedLength;
            /*!Load Local TxPdu with TxPduId from CanTxPduId input parameter  */
            udtLocalTxPdu.swPduHandle=u16TxPduIdIndex;
            /*!Determine CanId for CanTxPduId input parameter                 */
            udtLocalTxPdu.id=udtSetCanId(u16TxPduIdIndex);
            /*! if the physical channel (defined by ControllerId)that the input 
            parameter CanTxPduId is assigned to and if it is in                 
            CANIF_GET_OFFLINE_ACTIVE or CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE    */
            /* \Trace_To CANIF-CDD-5025(0)                                    */
            if(enuLocalTxPath==CanIf_TX_PATH_OFF_ACTIVE)
            {
                /*!Return E_OK                                                */
                udtResult=E_OK;
                /*!if Ul service isn configured and ULName(ID) is valid       */
                /* PRQA S 3689 ++ */
                /*MISRA Msg justification:  No Way the UL Name exceeds array    
                Bounds,Protection done                                        */
				   if((*CanIf_udtGET_TXPDU_PBCFG[u16TxPduIdIndex].CanIf_pudteUlId[0])
                  != NULL_PTR)  
                {
                    /*! Call User Tx Confirm For Upper Layer using CanTxPduId   
                    and ULName(ID)configured services                         */
					(*CanIf_udtGET_TXPDU_PBCFG[u16TxPduIdIndex].CanIf_pudteUlId[0])(CanIf_udtGET_TXPDU_PBCFG[u16TxPduIdIndex].udtTxPduRef);
					
                }
                /* PRQA S 3689 -- */
            }
            /*! else the physical channel (defined by ControllerId)that the     
            input parameter CanTxPduId is assigned to and if it is in           
            CANIF_GET_ONLINE or CANIF_GET_TX_ONLINE                           */
            /* \Trace_To CANIF-CDD-5021(0)                                    */
            /* \Trace_To CANIF-CDD-5024(0)                                    */
            else
            {
				LOC_pfenuWrite=CanIf_akstreCanServicesPCCfg[u8CanDrv].pfenuWrite;
                /*!#if Tx Buffering is enabled                                */
#if(CanIf_bTX_BUFFERING==STD_ON)	
				pudtBuffMessage = &(CanIf_udtGET_TXPDU_PBCFG[u16TxPduIdIndex].
				CanIf_pudteTxBufferRefer->udtBufferedMessage); 
				pu8TxbuffStatus=&(CanIf_udtGET_TXPDU_PBCFG[u16TxPduIdIndex].
				CanIf_pudteTxBufferRefer->u8TxbufferStatus);
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)
				pkstreRxBuffCriticalSec = CanIf_udtGET_TXPDU_PBCFG[u16TxPduIdIndex].CanIf_pudteSchMExclArea;
				pkstreRxBuffCriticalSec->pfvidEnterCriticalSec();
#else
SchM_Enter_CanIf_CS0011();
#endif
#endif
                /*!forward enable forwarding of the transmit request calls
                CanIf_Transmit()to the CanDrv                                 */
                /*!save the result of transmit request to CanDrv              */
                udtWriteResult = LOC_pfenuWrite(udtHthRef,&udtLocalTxPdu);
                /*!Process the result of transmit request to CanDrv           */
                /*!If result of transmit request to CanDrv is OK              */
                /* \Trace_To CANIF-CDD-0182(0)*/
                if(udtWriteResult==CAN_OK)
                {
                    /*Return to UL E_OK                                       */
                    udtResult=E_OK;
                }
                /*!#if Tx Buffering is enabled                                */
#if(CanIf_bTX_BUFFERING==STD_ON)
                /*! elseif  result of transmit request to CanDrv is BUSY AND    
                Hth is of type BASIC                                          */
                /* \Trace_To CANIF-CDD-0044(0)                                */
                /* \Trace_To CANIF-CDD-0045(0)                                */
                else if((udtWriteResult==CAN_BUSY)&&
                    (CanIf_akstreHthLCfg[u16Hth].enuHandleType==CanIf_BASIC))
                {
                    /*! Save the message in pudtTxPduBuffer                   */
                    vidCopyCanPdu(&udtLocalTxPdu,pudtBuffMessage);
                    /*! Set buffered message type Flag of the buffer to NEW     
                    (buffering occured in CanIf_Transmit request from UL not    
                    from Cancellation)                                        */
                    /* \Trace_To CANIF-CDD-5221(0)*/
                    *pu8TxbuffStatus = CanIf_u8NEW_TXPDU;
                    /*! Return to UL E_OK                                     */
                    udtResult=E_OK;
                }
                /*!#if Tx buffering is disbled                                */
#else
                /*!elseif  result of transmit request to CanDrv is BUSY       */
                else if(udtWriteResult==CAN_BUSY)
                {
                    /*! Return to UL E_NOT_OK                                 */
                    udtResult=E_NOT_OK;
                }
#endif
                /*!else*/
                /*! Cases (CanIf_BASIC&&CAN_NOT_OK)or (CanIf_FULL&&CAN_NOT_OK)  
                or (CanIf_FULL&&CAN_BUSY)                                     */
                /*! Return to UL E_NOT_OK                                     */
                else
                {
                    /*!Do nothing                                             */
                }
/*!#if Tx Buffering is enabled                                                */
#if(CanIf_bTX_BUFFERING==STD_ON)
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)
				pkstreRxBuffCriticalSec->pfvidExitCriticalSec();
#else
SchM_Exit_CanIf_CS0011();
#endif
#endif
            }
        }
        /*! elseif 
        (the physical channel (defined by ControllerId) that the input parameter
        CanTxPduId is assigned to is in CANIF_GET_OFFLINE OR                    
        CANIF_GET_RX_ONLINE AND(Controller mode (defined by ControllerId)
        that the input parameter CanTxPduId is assigned to is in                
        CANIF_CS_STOPPED) prevent forwarding of the transmit request            
        calls to the CanDrv (returning E_NOT_OK to the calling upper            
        layer modules).                                                       */
        /* \Trace_To CANIF-CDD-5011(0)                                        */
        /* \Trace_To CANIF-CDD-5015(0)                                        */
        /* \Trace_To CANIF-CDD-0041(0)                                        */
        /* \Trace_To CANIF-CDD-0076(0)                                        */
        else if(((udtCurrControlMode==CANIF_CS_STOPPED)||
                 (enuLocalTxPath==CanIf_TX_PATH_OFFLINE))
                 &&(PduInfoPtr->SduLength!=0))
        {
            /*! raise the production error code CANIF_E_STOPPED 
            and CanIf_Tranmsit() and return E_NOT_OK.                         */
            /* \Trace_To CANIF-CDD-5035(0)                                    */
            /* \Trace_To CANIF-CDD-5036(0)                                    */
            /* \Trace_To CANIF-CDD-0042(0)                                    */
           if(CanIf_udtGET_TXPDU_PBCFG[u16TxPduIdIndex].u16DemESStopped
              !=u16INVLD_DEM_E_STOP_ID)
           {
#if(CanIf_bDEM_ERR_DETECT == STD_ON)
               Dem_ReportErrorStatus(
                CanIf_udtGET_TXPDU_PBCFG[u16TxPduIdIndex].u16DemESStopped,
                DEM_EVENT_STATUS_FAILED);
#endif
           }
            /*! Return to UL E_NOT_OK                                         */
        }
        /*!else
        (the Controller mode (defined by ControllerId)
        that the input parameter CanTxPduId is assigned to is in 
        CANIF_CS_SLEEP)prevent forwarding of the transmit request
        calls to the CanDrv (returning E_NOT_OK to the calling upper 
        layer modules).                                                       */
        else
        {
            /*!(PduInfoPtr->SduLength=0)                                      */
            /*!do Nothing                                                     */
            /* !leave udtResult=E_NOT_OK;                                     */
            /*! Bad Controller mode                                           */
        }
    }
    return(udtResult);
}
/* PRQA S 4700 -- */
/******************************************************************************/
/*!\Description : This service confirms a previously successfully performed     
                   cancellation of a pending Tx L-PDU transmit request.       \n
    \param[in]     PduInfoPtr: Pointer to a structure with CAN L-PDU related    
                   data: L-PDU handle of the successfully aborted CAN L-SDU,    
                   CAN identifier, DLC and pointer to CAN L-SDU buffer.       \n
    \Range         not null                                                   \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
/*!This service shouldn't be enables for any Driver except if Bufering          
   is enabled                                                                 */
#if(CanIf_bTX_BUFFERING==STD_ON)
FUNC(void, CANIF_CODE)CanIf_vidLocalCancelTxConf(
    P2CONST(Can_PduType,AUTOMATIC,CANIF_APPL_CONST)PduInfoPtr)
{
    /* PRQA S 0781 ++ */
    /*MISRA Msg justification:  names in Struct may be Repeated in Local 
    Variables                                                                 */
    /*!TxPduId cancelled                                                      */
    VAR(PduIdType, AUTOMATIC)                   udtTxPduId;
    /* Hth that TxPduId cancelled assigned to                                 */
    VAR(uint16, AUTOMATIC)                      u16Hth;
    /* Controlled that TxPduId cancelled assigned to                          */
    VAR(uint8, AUTOMATIC)                       u8ControllerId;
    /* controller mode that TxPduId cancelled assigned to                     */
    VAR(CanIf_ControllerModeType, AUTOMATIC)    udtCurrControlMode;
    /* Pdu Channel mode that TxPduId cancelled assigned to                    */
    VAR(CanIf_tstrPduMode, AUTOMATIC)           udtLocalTxRxPathPdu;
	P2VAR(CanIf_tenuTxPathMode, AUTOMATIC, AUTOMATIC)	penuTxPath;
/* PRQA S 8018,8318,8518,8618 ++ */
	P2CONST(CanIf_tenuHandleType, AUTOMATIC, AUTOMATIC) pkenuHandleType;
/* PRQA S 8018,8318,8518,8618 -- */
	P2VAR(uint8, AUTOMATIC, AUTOMATIC)	pu8TxbuffStatus;
	P2VAR(CanIf_tstrLocalPduType, AUTOMATIC, AUTOMATIC)      pudtBuffMessage;
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)
/* PRQA S 8018,8318,8518,8618 ++ */
	P2CONST(CanIf_tstrCriticalSection, AUTOMATIC, AUTOMATIC)	
												  pkstreRxBuffCriticalSec;
/* PRQA S 8018,8318,8518,8618 -- */
#endif
/* PRQA S 0781 -- */
    /* \Trace_To CANIF-CDD-5086(0)                                            */
    /* \Trace_To CANIF-CDD-0323(0)                                            */
    /* \Trace_To CANIF-CDD-0324(0)                                            */
    /*!if the Canif isnot initialized                                         */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
/*!#if the Development Error is enabled                                       */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        /*! Report to the DET (using CANIF_E_UNINIT) and return E_NOT_OK      */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CANCELTXCONF_API,CANIF_E_UNINIT);
#endif
    }
	else if (PduInfoPtr == NULL_PTR)
    {
/*!#if the Development Error is enabled                                       */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        /*! Report to the DET(using CANIF_E_PARAM_POINTER) and return E_NOT_OK*/
		CanIf_vidDET_REPORT_ERROR(CanIf_u8CANCELTXCONF_API,CANIF_E_PARAM_POINTER);
#endif
    }

    /* \Trace_To CANIF-CDD-0322(0)                                            */
/*!#if the Development Error is enabled                                       */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*!elseif swPduHandle is invalid                                          */
    else if(PduInfoPtr->swPduHandle>=CanIf_udtGET_NUMOFTX_PBCFG)
    {
        /*! Report to the DET (using CANIF_E_PARAM_LPDU) and return E_NOT_OK  */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CANCELTXCONF_API, CANIF_E_PARAM_LPDU);
    }
#endif
    /*!else*/
    else
    {
        /*!get CanTxPduId from PduInfoPtr input parameter                     */
        udtTxPduId = PduInfoPtr->swPduHandle;
        /*!get Hth from CanTxPduId Config                                     */
        u16Hth = CanIf_udtGET_TXPDU_PBCFG[udtTxPduId].u16Hth;
        /*!get Controller Id from Hth Config                                  */
        u8ControllerId=CanIf_akstreHthLCfg[u16Hth].u8ControllerId;
        /*!get current Controller mode using Controller Id                    */
        SchM_Enter_CanIf_CurrConMode_15();
        udtCurrControlMode=CanIf_aenueCurrControllerMode[u8ControllerId];
        SchM_Exit_CanIf_CurrConMode_15();
		penuTxPath=&(udtLocalTxRxPathPdu.enuTxPath);
        /*!get current Pdu Channel mode using Controller Id                   */
        SchM_Enter_CanIf_PduChnlMod_15();
        *penuTxPath = CanIf_astreCurrPduChannelMode[u8ControllerId].enuTxPath;
        SchM_Exit_CanIf_PduChnlMod_15();
		pkenuHandleType=&(CanIf_akstreHthLCfg[u16Hth].enuHandleType);
		pu8TxbuffStatus=&(CanIf_udtGET_TXPDU_PBCFG[udtTxPduId].
				CanIf_pudteTxBufferRefer->u8TxbufferStatus);
		pudtBuffMessage = &(CanIf_udtGET_TXPDU_PBCFG[udtTxPduId].CanIf_pudteTxBufferRefer->udtBufferedMessage);
				
        /* \Trace_To CANIF-CDD-0055(0)                                        */
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF) 
		pkstreRxBuffCriticalSec = CanIf_udtGET_TXPDU_PBCFG[udtTxPduId].CanIf_pudteSchMExclArea;
		pkstreRxBuffCriticalSec->pfvidEnterCriticalSec();
#else
SchM_Enter_CanIf_CS0011();
#endif
        /*!if Controller in Started mode and Pdu channel Tx Path is online  
            and Hth is from Basic-CAN type                                    */
        if(
            ((udtCurrControlMode==CANIF_CS_STARTED)&&
            (*penuTxPath==CanIf_TX_PATH_ONLINE))&&
            (*pkenuHandleType==CanIf_BASIC))
        {
            /*!if buffer doesn't contain new message                          */
            if(*pu8TxbuffStatus != CanIf_u8NEW_TXPDU)
            {
                /*!Save Cancelled message in its allocated buffer             */
                /* \Trace_To CANIF-CDD-0496(0)                                */
                vidCopyCanPdu(PduInfoPtr,pudtBuffMessage);
                /*!set the Aborted Flag                                       */
                /* \Trace_To CANIF-CDD-5223(0)                                */
                *pu8TxbuffStatus=CanIf_u8ABORTED_TXPDU;
            }
            /*!Send Higest Priority TxPdu                                     */
            vidHandleTransmitBuffer(udtTxPduId);
            /*!else                                                           */
            /*!Controller mode or channel mode isnot Started or Txonline      */
            /*!not expected to receive a Cancel of TxLpdu from CanDrv         */
        }
            /*! A buffered new message is already queued Do Nothing or the hth  
                is Full Can and no buferring supported for it                 */
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)
		pkstreRxBuffCriticalSec->pfvidExitCriticalSec();
#else
SchM_Exit_CanIf_CS0011();
#endif
    }
}
#endif
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)
/******************************************************************************/
/*!\Description : This service returns the confirmation status (confirmation    
                   occured of not) of a specific static or dynamic CAN Tx L-PDU,
                   requested by the CanTxPduId.                               \n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU to be transmitted.     
                   This handle specifies the corresponding CAN L-PDU ID and     
                   implicitly the CAN Driver instance as well as the            
                   corresponding CAN controller device.                       \n
    \Range         0.. PbCfg.CanIf_udtNumofTxPdus-1                           \n
    \return        Current confirmation status of the corresponding CAN         
                   Tx L-PDU.                                                  \n
    \Range         CANIF_NO_NOTIFICATION, CANIF_TX_RX_NOTIFICATION            \n
    \Trace_To CANIF-CDD-0200(0)                                                 
*******************************************************************************/
/* PRQA S 3206 ++ */
/* MISRA Msg justification: CanTxPduId can't be removed from the function 
		declaration even if it was not used because it is an Autosar service*/
FUNC(CanIf_NotifStatusType, CANIF_CODE)CanIf_ReadTxNotifStatus(
    VAR(PduIdType ,AUTOMATIC)CanTxPduId)
/* PRQA S 3206 -- */
{
    /*the return of the service                                               */
    VAR(CanIf_NotifStatusType, AUTOMATIC) udtTxNotifStatus =
        CANIF_NO_NOTIFICATION;
#if(CanIf_bREAD_TX_NOTIF_API != STD_OFF)
	P2VAR(CanIf_NotifStatusType, AUTOMATIC, CANIF_VAR)
                                                penuTxNotifStat;
#endif
/*!#if CanIf_ReadTxNotifStatus is disabled                                    */
/* \Trace_To CANIF-CDD-5044(0)                                                */
#if(CanIf_bREAD_TX_NOTIF_API ==STD_OFF)
    /*! Report to the DET (using ANIF_E_NOK_NOSUPPORT) and return E_NOT_OK    */
    CanIf_vidDET_REPORT_ERROR(CanIf_u8RDTXNTIFSTAT_API,CANIF_E_NOK_NOSUPPORT);
#else
/*!if Development error is enabled*/
    /* \Trace_To CANIF-CDD-5045(0)*/
    /* \Trace_To CANIF-CDD-0203(0)*/
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*!if Canif isnot initialized*/
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report to the DET (using CANIF_E_UNINIT) and return E_NOT_OK      */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8RDTXNTIFSTAT_API,CANIF_E_UNINIT);
    }
    /*!elseif CanTxPduId is out of range                                      */
    /* \Trace_To CANIF-CDD-0202(0)                                            */
    else if(CanTxPduId>=CanIf_udtGET_NUMOFTX_PBCFG)
    {
        /*! Report to the DET (using CANIF_E_UNINIT) and return 
        CANIF_E_INVALID_TXPDUID                                               */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8RDTXNTIFSTAT_API, 
            CANIF_E_INVALID_TXPDUID);
    }
    /*!else*/
    else
#endif
    {
        /* \Trace_To CANIF-CDD-0201(0)                                        */
        /*!if Read notification status is nabled for this CanTxPduId
            and notification status index of Notif Status array is valid      */
        if(CanIf_udtGET_TXPDU_PBCFG[CanIf_udtGET_TXPDU_MAP_PBCFG[CanTxPduId]].bReadNotifyStatus==STD_ON)
        {
			penuTxNotifStat=&(CanIf_udtGET_TXNOTIF_PBCFG
                [CanIf_udtGET_TXPDU_PBCFG[CanIf_udtGET_TXPDU_MAP_PBCFG[CanTxPduId]].udtNotifyStatusIndex]);
            SchM_Enter_CanIf_TxNotifStat_07();
            /*!Copy saved notification status for this CanTxPduId in 
            udtTxNotifStatus local variable                                   */
            /* \Trace_To CANIF-CDD-0201(0)                                    */
            udtTxNotifStatus = *penuTxNotifStat;
            /*!Reset saved notification status for this CanTxPduId            */
            /* \Trace_To CANIF-CDD-0201(0)*/
            *penuTxNotifStat = CANIF_NO_NOTIFICATION;
            SchM_Exit_CanIf_TxNotifStat_07();
        }
        /*!else Read notification status is disabled for this CanTxPduId
            or notification status index of Notif Status array is invalid     */
    }
    /*!return saved notification status for this CanTxPduId                   */
#endif/*(CanIf_bREAD_TX_NOTIF_API ==STD_OFF)                                  */
    return(udtTxNotifStatus);
}
#endif/*(CanIf_bREAD_TX_NOTIF_API ==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)    */
#if(CanIf_bTXCONF_POLL_SUPPORT==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)
/******************************************************************************/
/*!\Description : This service reports, if any TX confirmation has been done    
                   for the whole CAN controller since the last CAN controller   
                   start.                                                     \n
    \param[in]     ControllerId: Abstracted CanIf ControllerId which is         
                   assigned to a CAN controller                               \n
    \Range         0.. CanIf_ku8eNumOfControllers-1                           \n
    \return        Combined TX confirmation status for all TX PDUs of the       
                   CAN controller                                             \n
    \Range         CANIF_NO_NOTIFICATION, CANIF_TX_RX_NOTIFICATION            \n
    \Trace_To CANIF-CDD-0297(0)                                                 
*******************************************************************************/
/* PRQA S 3206 ++ */
/* MISRA Msg justification: ControllerId can't be removed from the function 
		declaration even if it was not used because it is an Autosar service*/
FUNC(CanIf_NotifStatusType, CANIF_CODE)CanIf_GetTxConfirmationState(
    VAR(uint8 ,AUTOMATIC)ControllerId)
/* PRQA S 3206 -- */
{
/* PRQA S 3197 EOF */
/* MISRA Msg justification:  The variable must be initialized with a default
                             value to handle some cases where it will not be
							 updated later (under certain pre-processor
							 configuration parameters)                        */	
							 
    /*the return of the service                                               */
    VAR(CanIf_NotifStatusType ,AUTOMATIC)enuTxConfirmState=
        CANIF_NO_NOTIFICATION;
/*!#if CanIf_GetTxConfirmationState is disabled                               */
/* \Trace_To CANIF-CDD-5073(0)                                                */
#if(CanIf_bTXCONF_POLL_SUPPORT==STD_OFF)
        /*! Report to the DET (using ANIF_E_NOK_NOSUPPORT) and return E_NOT_OK*/
    CanIf_vidDET_REPORT_ERROR(CanIf_u8GETTXCONFIRM_API,CANIF_E_NOK_NOSUPPORT);
#else
/*!if Development error is enabled                                            */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /* \Trace_To CANIF-CDD-5074(0)                                            */
    /* \Trace_To CANIF-CDD-0298(0)                                            */
    /*!if Canif isnot initialized                                             */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report to the DET (using CANIF_E_UNINIT) and return E_NOT_OK*/
        CanIf_vidDET_REPORT_ERROR(CanIf_u8GETTXCONFIRM_API,CANIF_E_UNINIT);
    }
    /*!elseif ControllerId is out of range                                    */
    /* \Trace_To CANIF-CDD-0299(0)                                            */
    else if(ControllerId>=CanIf_ku8eNumOfControllers)
    {
        /*! Report to the DET (using CANIF_E_PARAM_CONTROLLERID) and return     
        E_NOT_OK                                                              */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8GETTXCONFIRM_API, 
            CANIF_E_PARAM_CONTROLLERID);
    }
    /*!else                                                                   */
    else
#endif
    {
        /*!copy stored Tx Confirmation state for ControllerId input parameter   
           in  TxConfirmState local variable                                  */
        SchM_Enter_CanIf_TxConfStat_19();
        enuTxConfirmState =  CanIf_aenueTxConfirmState[ControllerId];
        SchM_Exit_CanIf_TxConfStat_19();
        /*!don't clear CanIf_aenueTxConfirmState[ControllerId] , it shall remain
        till next BusOff(will be cleared in Busoff of this ControllerId)      */
    }
#endif/*(CanIf_bTXCONF_POLL_SUPPORT==STD_OFF)                                 */
    /*!return copied TxConfirmState                                           */
    return(enuTxConfirmState);
}
#endif/*(CanIf_bTXCONF_POLL_SUPPORT==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)   */
#if(CanIf_bCANCEL_TRANSMIT==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)
/******************************************************************************/
/*!\Description : This is a dummy API introduced for interface compatibility. \n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU to be transmitted.     
                   This handle specifies the corresponding CAN L-PDU ID and     
                   implicitly the CAN Driver instance as well as the            
                   corresponding CAN controller device.                       \n
    \Range         0.. PbCfg.CanIf_udtNumofTxPdus-1                           \n
    \return        Always return E_OK except if input parameters is invalid     
                   or CanIf isn't initialized                                 \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0197(0)                                                 
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_CancelTransmit(
    VAR(PduIdType ,AUTOMATIC)CanTxPduId)
{
    /*the reurn of the service                                                */
    VAR(Std_ReturnType ,AUTOMATIC)udtReturn=E_NOT_OK;
/*!#if CanIf_CancelTransmit is disabled                                       */
#if(CanIf_bCANCEL_TRANSMIT==STD_OFF)
        /*! Report to the DET (using ANIF_E_NOK_NOSUPPORT) and return E_NOT_OK*/
    CanIf_vidDET_REPORT_ERROR(CanIf_u8CANCLTRANSMIT_API,CANIF_E_NOK_NOSUPPORT);
#else
/*!if Development error is enabled                                            */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /* \Trace_To CANIF-CDD-5039(0)                                            */
    /*!if CanIf isnot initialized                                             */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report to the DET (using ANIF_E_NOK_NOSUPPORT) and return E_NOT_OK*/
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CANCLTRANSMIT_API, CANIF_E_UNINIT);
    }
    /*!elseif CanTxPduId is invalid                                           */
    /* \Trace_To CANIF-CDD-5176(0)                                            */
    /* \Trace_To CANIF-CDD-0199(0)                                            */
    else if(CanTxPduId>=CanIf_udtGET_NUMOFTX_PBCFG)
    {
        /*! Report to the DET (using CANIF_E_INVALID_TXPDUID) and return 
        E_NOT_OK                                                              */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CANCLTRANSMIT_API,
            CANIF_E_INVALID_TXPDUID);
    }
    /*!else                                                                   */
    else
#endif
    {
        udtReturn=E_OK;
    /*!Do Nothing This is a dummy API introduced for interface compatibility. */
    }
#endif/*(CanIf_bCANCEL_TRANSMIT==STD_OFF)                                     */
    /*! Alwayes return E_OK                                                   */
    return(udtReturn);
}
#endif/*CanIf_bCANCEL_TRANSMIT==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)        */
/******************************************************************************/
/*!\Description : This service confirms a previously successfully processed     
                   transmission of a CAN TxPDU.                               \n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU to be transmitted.     
                   This handle specifies the corresponding CAN L-PDU ID and     
                   implicitly the CAN Driver instance as well as the            
                   corresponding CAN controller device.                       \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
    \return        void                                                       \n
    \Range         n/A                                                        \n
*******************************************************************************/
/* PRQA S 4700 ++ */
/*MISRA Msg justification: ISR,time is critical                               */
FUNC(void, CANIF_CODE)CanIf_vidLocalTxConf(
    VAR(PduIdType ,AUTOMATIC)CanTxPduId)
{
/* PRQA S 0781 ++ */
/*MISRA Msg justification:  names in Struct may be Repeated in Local Variables*/
    /*Hth that TxPdu transmitted is assigned to                               */
#if((CanIf_bTX_BUFFERING==STD_ON)||(CanIf_bTXCONF_POLL_SUPPORT==STD_ON))	
    VAR(uint16, AUTOMATIC)                      u16Hth;
    /*ControllerId that TxPdu transmitted is assigned to                      */
    VAR(uint8, AUTOMATIC)                       u8ControllerId;
#endif		
#if(CanIf_bTX_BUFFERING==STD_ON)	
    /*Controller mode that TxPdu transmitted is assigned to                   */
    VAR(CanIf_ControllerModeType, AUTOMATIC)    udtCurrControlMode;
    /*Pdu Channel mode that TxPdu transmitted is assigned to                  */
    VAR(CanIf_tstrPduMode, AUTOMATIC)           udtLocalTxRxPathPdu;
	P2VAR(CanIf_tenuTxPathMode, AUTOMATIC, AUTOMATIC)    penuTxPath;
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)
/* PRQA S 8018,8318,8518,8618 ++ */
	P2CONST(CanIf_tstrCriticalSection, AUTOMATIC, AUTOMATIC)	
												pkstreRxBuffCriticalSec;
/* PRQA S 8018,8318,8518,8618 -- */
#endif
#endif
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
	P2VAR(CanIf_NotifStatusType, AUTOMATIC, AUTOMATIC)
                                                penuTxNotifStat;
#endif
/* PRQA S 0781 -- */
    /*!if Canif isnot initialized                                             */
    /* \Trace_To CANIF-CDD-5077(0)                                            */
    /* \Trace_To CANIF-CDD-0307(0)                                            */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*!#if Develeopment error is enabled                                  */
        /* \Trace_To CANIF-CDD-0306(0)                                        */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        /*! Report to the DET (using CANIF_E_UNINIT) and return E_NOT_OK      */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8TXCONF_API,CANIF_E_UNINIT);
#endif
    }
    /*!#if Develeopment error is enabled                                      */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*!elseif   CanTxPduId is out of range                                    */
    /* \Trace_To CANIF-CDD-0305(0)                                            */
    else if(CanTxPduId>=CanIf_udtGET_NUMOFTX_PBCFG)
    {
        /*! Report to the DET (using CANIF_E_PARAM_LPDU) and return E_NOT_OK  */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8TXCONF_API, CANIF_E_PARAM_LPDU);
    }
#endif
    /*!else                                                                   */
    else
    {
#if((CanIf_bTX_BUFFERING==STD_ON)||(CanIf_bTXCONF_POLL_SUPPORT==STD_ON)||(CanIf_bPUBLIC_PN_SUPPORT==STD_ON))		
        /*!get Hth from CanTxPduId config                                     */
        u16Hth = CanIf_udtGET_TXPDU_PBCFG[CanTxPduId].u16Hth;	
        /*!get Controller from Hth config                                     */
        u8ControllerId=CanIf_akstreHthLCfg[u16Hth].u8ControllerId;
#endif
	/* \Trace_To CANIF-CDD-0513(0)											*/
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
	if (CanIf_udtGET_CTRL_PBCFG[u8ControllerId].bPnFilterIsEffective == TRUE)
	{
		CanIf_astreCurrPduChannelMode[u8ControllerId].bPnTxfilter=FALSE;
	}
#endif
#if(CanIf_bTX_BUFFERING==STD_ON)		
        /*!get current Controller mode                                        */
        SchM_Enter_CanIf_CurrConMode_13();
        udtCurrControlMode=CanIf_aenueCurrControllerMode[u8ControllerId];
        SchM_Exit_CanIf_CurrConMode_13();
		penuTxPath=&(CanIf_astreCurrPduChannelMode[u8ControllerId].enuTxPath);
        /*!get current Pdu Channel mode                                       */
        SchM_Enter_CanIf_PduChnlMod_13();
        udtLocalTxRxPathPdu.enuTxPath = *penuTxPath;
        SchM_Exit_CanIf_PduChnlMod_13();
#endif		
        /*!If those transmit L-PDUs, which are already waiting for transmission 
        in the CAN hardware transmit object,will be transmitted immediately     
        after change to CANIF_SET_TX_OFFLINE or CANIF_SET_OFFLINE mode and a    
        subsequent BusOff event occurs,In this case the CanIf executes          
        subsequent transmit confirmation notification to upper layer modules    
        (<User_TxConfirmation>()).                                            */
        /*!the New Transmit Confirmations is prohibited by prohibition of   
        Transmission                                                          */
        /* \Trace_To CANIF-CDD-5013(1)                                        */
        /*!#if(CanIf_bREAD_TX_NOTIF_API  is enabled)                          */
        /* \Trace_To CANIF-CDD-0304(0)                                        */
        /* \Trace_To CANIF-CDD-0063(0)                                        */
#if(CanIf_bREAD_TX_NOTIF_API ==STD_ON)
        /*!if Read notification status of this CanTxPduId is enabled            
        AND index of notification status in penuTxNotifStatus array is          
        valid                                                                 */
        /* PRQA S 3689 ++ */
        /*MISRA Msg justification:  No Way the UL Name exceeds array Bounds,
        Protection done                                                       */
        if(CanIf_udtGET_TXPDU_PBCFG[CanTxPduId].bReadNotifyStatus ==STD_ON)
        {
			penuTxNotifStat = &(CanIf_udtGET_TXNOTIF_PBCFG
			[CanIf_udtGET_TXPDU_PBCFG[CanTxPduId].udtNotifyStatusIndex]);
            SchM_Enter_CanIf_TxNotifStat_13();
            /*!Store notification Status CANIF_TX_RX_NOTIFICATION             */
            *penuTxNotifStat = CANIF_TX_RX_NOTIFICATION;
            SchM_Exit_CanIf_TxNotifStat_13();
        }
        /* PRQA S 3689 -- */
#endif
        /*!#if CanIf_bTXCONF_POLL_SUPPORT is enabled                      */
        /* \Trace_To CANIF-CDD-0053(0)                                    */
#if(CanIf_bTXCONF_POLL_SUPPORT==STD_ON)
        /*!store Tx Confirmation state fro this Controller                */
        SchM_Enter_CanIf_TxConfStat_13();
        CanIf_aenueTxConfirmState[u8ControllerId]=CANIF_TX_RX_NOTIFICATION;
        SchM_Exit_CanIf_TxConfStat_13();
#endif
        /*!if upper layer configured correctly                            */
        /* \Trace_To CANIF-CDD-5027(0)                                    */
        /* \Trace_To CANIF-CDD-0348(0)                                    */
        /* PRQA S 3689 ++ */
        /*MISRA Msg justification:  No Way the UL Name exceeds array Bounds,
        Protection done                                                   */

		if((*CanIf_udtGET_TXPDU_PBCFG[CanTxPduId].CanIf_pudteUlId[0])!=NULL_PTR)		
        {
            /* \Trace_To CANIF-CDD-0052(0)                                */
            /* \Trace_To CANIF-CDD-0349(0)                                */
            /*!notify upper layer with USER_TxConfirmation using UL Name    
            (ID) configured for this CanTxPduId                           */
		  (*CanIf_udtGET_TXPDU_PBCFG[CanTxPduId].CanIf_pudteUlId[0])(CanIf_udtGET_TXPDU_PBCFG
				[CanTxPduId].udtTxPduRef);
        }
        /*!if Tx Buffering is enabled                                     */
#if(CanIf_bTX_BUFFERING==STD_ON)
        /*!if Controller in Started mode and Pdu channel Tx Path is online  
        and Hth is from Basic-CAN type                                    */
        if(((udtLocalTxRxPathPdu.enuTxPath==CanIf_TX_PATH_ONLINE)
            &&(udtCurrControlMode==CANIF_CS_STARTED))
            &&(CanIf_akstreHthLCfg[u16Hth].enuHandleType==CanIf_BASIC))
        {
            /*!Handle Tx Buffer()                                         */
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)
			pkstreRxBuffCriticalSec = CanIf_udtGET_TXPDU_PBCFG[CanTxPduId].CanIf_pudteSchMExclArea;
			pkstreRxBuffCriticalSec->pfvidEnterCriticalSec();
			
#else
SchM_Enter_CanIf_CS0011  ();
#endif
          vidHandleTransmitBuffer(CanTxPduId);
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)
			pkstreRxBuffCriticalSec->pfvidExitCriticalSec();
#else
SchM_Exit_CanIf_CS0011();
#endif
        }
#endif
    }
}
/* PRQA S 4700 -- */
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON||CanIf_bDEV_ERR_DETECT == STD_ON)
/******************************************************************************/
/*!\Description : This service reconfigures the corresponding CAN identifier
                   of the requested CAN L-PDU.                                \n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU for transmission.
                   This ID specifies the corresponding CAN L-PDU ID and
                   implicitly the CAN Driver instance as well as the 
                   corresponding CAN controller device.                       \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
    \param[in]     Standard/Extended CAN ID of CAN L-PDU that
                   shall be transmitted.                                      \n
    \Range         0..0x7FF Standard    0..536870911 Extended                
                   BIF: 0 Standard , 1 Extended                               \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
    \Trace_To CANIF-CDD-0256(0)                                      
*******************************************************************************/
/* PRQA S 3206 ++ */
/* MISRA Msg justification: CanTxPduId, CanId can't be removed from the function 
		declaration even if it was not used because it is an Autosar service*/
FUNC(void, CANIF_CODE)CanIf_SetDynamicTxId(
    VAR(PduIdType, AUTOMATIC) CanTxPduId,
    VAR(Can_IdType, AUTOMATIC) CanId)
/* PRQA S 3206 -- */
{
/* PRQA S 0781 ++ */
/*MISRA Msg justification:  names in Struct may be Repeated in Local Variables*/
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
    /*Normalized CanId                                                        */
    VAR(Can_IdType, AUTOMATIC)          udtAbsoluteCanId;
    /*CanId Type                                                              */
    VAR(CanIf_tenuCanIdType, AUTOMATIC) enuCanIdType;
    /*redume or abort setting CanId                                           */
    VAR(boolean,AUTOMATIC)              bResumeSettingCanId=E_NOT_OK;
	P2VAR(Can_IdType, AUTOMATIC, AUTOMATIC)                  pudtCanId;
	P2VAR(CanIf_tenuCanIdType, AUTOMATIC, AUTOMATIC) pudtCanIdType;
#endif
/* PRQA S 0781 -- */
/*!#if CanIf_SetDynamicTxId isnot supported                                   */
/* \Trace_To CANIF-CDD-5055(0)                                                */
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_OFF)
     /*! Report to the DET (using CANIF_E_NOK_NOSUPPORT) */
    CanIf_vidDET_REPORT_ERROR(CanIf_u8SETDYNAMICTXID_API,CANIF_E_NOK_NOSUPPORT);
#else
    /* \Trace_To CANIF-CDD-0259(0)                                            */
    /* \Trace_To CANIF-CDD-0260(0)                                            */
    /* \Trace_To CANIF-CDD-5056(0)                                            */
    /*!if Canif isnot initialized                                             */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
/*!#if Development error is enabled                                           */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        /*! Report to the DET (using CANIF_E_UNINIT)                          */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETDYNAMICTXID_API, CANIF_E_UNINIT);
#endif
    }
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*!elseif                                                                 */
     /*!if CanTxPduId is invalid                                              */
    /* \Trace_To CANIF-CDD-0257(0)                                            */
    else if((CanTxPduId>=CanIf_udtGET_NUMOFTX_PBCFG)||
        (CanIf_udtGET_TXPDU_PBCFG[CanIf_udtGET_TXPDU_MAP_PBCFG[CanTxPduId]].enuTXPduType!=CanIf_DYNAMIC))
    {
        /*! Report to the DET (using CANIF_E_INVALID_TXPDUID)                 */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETDYNAMICTXID_API, 
            CANIF_E_INVALID_TXPDUID);
    }
#endif
    /*!else                                                                   */
    else
    {
        /* \Trace_To CANIF-CDD-0032(0)                                        */
        /*!Process BIF to determine the type of the CanId                     */
        /*!if determined type is Extended                                     */
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
        if((CanId&CanIf_u32CANID_MSB_MASK)==CanIf_u32CANID_MSB_MASK)
        {
            /*!if Bit22 to Bit28 all recessive                                */
            /* \Trace_To CANIF-CDD-0258(0)                                    */
            if(((CanId)&(CanIf_u32CANID_EXTENDED_MASK))==
                CanIf_u32CANID_EXTENDED_MASK)
            {
                 /*! Report to the DET (using CANIF_E_PARAM_CANID)            */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
                CanIf_vidDET_REPORT_ERROR(CanIf_u8SETDYNAMICTXID_API,
                    CANIF_E_PARAM_CANID);
#endif
            }
            /* \Trace_To CANIF-CDD-0258(0)                                    */
            /*!else                                                           */
            else
            {
                bResumeSettingCanId=E_OK;
                /*!reset BIF before storing CanId                             */
                udtAbsoluteCanId=CanId&(~CanIf_u32CANID_MSB_MASK);
                /*!set the CanId type                                         */
                enuCanIdType=CanIf_EXTENDED;
            }
        }
        /* \Trace_To CANIF-CDD-0032(0)                                        */
        /*!else                                                               */
        /*!determined type is Standard                                        */
        /* \Trace_To CANIF-CDD-0258(0)                                        */
        else
        {
#endif
            /*!if less than 0x7ff											  */
            /* \Trace_To CANIF-CDD-0258(0)                                    */
            if((CanId>CanIf_u32CANID_STANDARD_MASK)
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT16)
                /*!or Extended CanId requested to be Reconfigured when Extended 
                is disabled                                                   */
                ||(((CanId)&(CanIf_u32CANID_EXTENDED_MASK))
                ==CanIf_u32CANID_EXTENDED_MASK)
#endif
                )
            {
                /*! Report to the DET (using CANIF_E_PARAM_CANID)             */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
                CanIf_vidDET_REPORT_ERROR(CanIf_u8SETDYNAMICTXID_API,
                    CANIF_E_PARAM_CANID);
#endif
            }
            /* \Trace_To CANIF-CDD-0258(0)                                    */
            /*!else                                                           */
            else
            {
                bResumeSettingCanId=E_OK;
                /*!no need to reset BIF before storing CanId                  */
                udtAbsoluteCanId=CanId;
                /*!set the CanId type                                         */
                enuCanIdType=CanIf_STANDARD;
            }
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
        }
#endif
        /*!if Valid CanIf is requested                                        */
        if(bResumeSettingCanId==E_OK)
        {
			pudtCanId=&(CanIf_udtGET_DYCANID_PBCFG[CanIf_udtGET_TXPDU_PBCFG
				[CanTxPduId].udtDyCanIdIndex].udtCanId);
			pudtCanIdType=&(CanIf_udtGET_DYCANID_PBCFG[CanIf_udtGET_TXPDU_PBCFG
				[CanTxPduId].udtDyCanIdIndex].udtCanIdType);
            /* PRQA S 3353 ++ */
            /*MISRA Msg justification:  udtAbsoluteCanId and enuCanIdType is 
                                        sure set befor use,prtotected         */
            /*!save in determined CanId and Type in DynamicTxPduCanId array   */
            SchM_Enter_CanIf_DynTxPduCanId_0c();
            *pudtCanId=udtAbsoluteCanId;
            *pudtCanIdType=enuCanIdType;
            SchM_Exit_CanIf_DynTxPduCanId_0c();
            /* PRQA S 3353 -- */
        }
    }
#endif/*(CanIf_bSET_DYNAMIC_TXID_API==STD_OFF)                                */
}
#endif/*(CanIf_bSET_DYNAMIC_TXID_API==STD_ON||CanIf_bDEV_ERR_DETECT == STD_ON)*/
/*****************************************************************************/
/*                                 INTERNAL SERVICES                         */
/*****************************************************************************/
/******************************************************************************/
/*!\Description : This service Clear TxConfirmation State for ControllerId    \n
    \param[in]     u8ControllerId: the contreoller Id that its                  
                   Tx Confirmation state will be cleared                      \n
    \Range         0..PbCfg.CanIf_ku8eNumOfControllers-1                      \n
    \return        void                                                       \n
    \Range         n/A                                                        \n
*******************************************************************************/
#if (CanIf_bTXCONF_POLL_SUPPORT == STD_ON)
FUNC(void, CANIF_CODE)CanIf_vidClearTxConfirmState(uint8 u8ControllerId)
{
    /*!Clear Tx Confirmation state for this controller 
    defined by u8ControllerId input parameter                                 */
    SchM_Enter_CanIf_CS004();
    CanIf_aenueTxConfirmState[u8ControllerId]=CANIF_NO_NOTIFICATION;
    SchM_Exit_CanIf_CS004();
}
#endif
/******************************************************************************/
/*!\Description : This service Clear TxPdus Buffers for ControllerId          \n
    \param[in]     u8ControllerId: the controller that all TxPdus buffers       
                   assigned to will be cleared                                \n
    \Range         0..PbCfg.CanIf_ku8eNumOfControllers-1                      \n
    \return        void                                                       \n
    \Range         n/A                                                        \n
*******************************************************************************/
#if(CanIf_bTX_BUFFERING==STD_ON)
FUNC(void, CANIF_CODE)CanIf_vidClearTransmitBuffers(uint8 u8ControllerId)
{
    /*TxpduId that its buffer will be cleared                                 */
    VAR(PduIdType ,AUTOMATIC)   udtCanTxPduId;
    /*start index of TxPduId that buffers will be cleard                      */
    VAR(uint16 ,AUTOMATIC)      u16HthStartindex;
    /*stop index of TxPduId that buffers will be cleard                       */
    VAR(uint16 ,AUTOMATIC)      u16HthStopindex;
     /*Hth that all TxPduIds buffers are assigned to will be cleard           */
    VAR(uint16_least ,AUTOMATIC)      u16HthSearchindex;
    /*boolean to aboart loops                                                 */
    VAR(boolean ,AUTOMATIC)     bAbortLoop;
/* PRQA S 8018,8318,8518 ++ */
	P2CONST(CanIf_tstrHthTxPduCfg, AUTOMATIC, CANIF_APPL_CONST)
								pkudtHthTxPduCfg=CanIf_udtGET_HTHTXPDU_PBCFG;
	CONST(PduIdType, AUTOMATIC) kudtNumofTxPdus=CanIf_udtGET_NUMOFTX_PBCFG;
	P2CONST(CanIf_tstrTxPduPbCfg, AUTOMATIC, CANIF_APPL_CONST) 
                                    pkudtTxPduPbCfg=CanIf_udtGET_TXPDU_PBCFG;
/* PRQA S 8018,8318,8518 -- */
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)
/* PRQA S 8018,8318,8518,8618 ++ */
	P2CONST(CanIf_tstrCriticalSection, AUTOMATIC, AUTOMATIC)	
									pkstreRxBuffCriticalSec;
/* PRQA S 8018,8318,8518,8618 -- */
#endif
    /*determine the first hth assigned to this controller                     */
    u16HthStartindex=CanIf_akstreCtrlLCfg[u8ControllerId].u8HthStartIndex;
    /*determine the number of hths assigned to this controller                */
    u16HthStopindex=(u16HthStartindex+CanIf_akstreCtrlLCfg[u8ControllerId]
    .u8NumOfHth);
    /*loop for all Hth assigned to this controller                            */
    for(u16HthSearchindex=u16HthStartindex;u16HthSearchindex<u16HthStopindex;
        u16HthSearchindex++)
    {
        /*!if Hth is used(at least 1 TxPdu assigned to it)*/
        if((pkudtHthTxPduCfg[u16HthSearchindex].bHthUsed==STD_ON)
            &&
            (CanIf_akstreHthLCfg[u16HthSearchindex].enuHandleType==CanIf_BASIC))
        {
            /*!get the first TxPdu assigned to this hth*/
            udtCanTxPduId=pkudtHthTxPduCfg[u16HthSearchindex]
            .udtTxpduStartIndex;
            bAbortLoop=CanIf_u8RESUME_LOOP;
            /*!loop for all TxPdus assigned to this Hth                       */
            while((bAbortLoop!=CanIf_u8ABORT_LOOP)&&(udtCanTxPduId
                <kudtNumofTxPdus))
            {
                /*!if didn't reched next Hth                                  */
                if(pkudtTxPduPbCfg[udtCanTxPduId].u16Hth
                    ==u16HthSearchindex)
                {
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)				
			pkstreRxBuffCriticalSec = CanIf_udtGET_TXPDU_PBCFG[udtCanTxPduId].CanIf_pudteSchMExclArea;
			pkstreRxBuffCriticalSec->pfvidEnterCriticalSec();
#else
SchM_Enter_CanIf_CS0011  ();
#endif
					
                    /*!Reset Queued flag for this TxPdu                       */
					CanIf_udtGET_TXPDU_PBCFG[udtCanTxPduId].CanIf_pudteTxBufferRefer->
					u8TxbufferStatus = CanIf_u8EMPTY_BUFFER;
					
#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)	
			pkstreRxBuffCriticalSec->pfvidExitCriticalSec();
			
#else
SchM_Exit_CanIf_CS0011();
#endif
                }
                /*!else                                                       */
                else
                {
                    /*Abort Hth Loop                                          */
                    bAbortLoop=CanIf_u8ABORT_LOOP;
                }
                /*!get next TxPdu                                             */
                udtCanTxPduId++;
            }
        }
    }
}
#endif
/******************************************************************************/
/*!\Description : This service stores data in CanTxpdu faied to be transmitted  
                   in its buffer                                              \n
    \param[in]     udtSource: source to copy from                             \n
    \Range         not null                                                   \n
    \param[out]     udtDestination: destination to copy to                    \n
    \Range         not null                                                   \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
#if(CanIf_bTX_BUFFERING==STD_ON)
static FUNC(void, CANIF_CODE) vidCopyCanPdu(
    P2CONST(Can_PduType, AUTOMATIC, CANIF_VAR)udtSource,
    P2VAR(CanIf_tstrLocalPduType,AUTOMATIC,CANIF_VAR)udtDestination)
{
    /*index that is used in copying                                           */
    VAR(uint8_least ,AUTOMATIC)u8CopyIndex;
    /*Copy Length in TxPdu Corressponding buffer                              */
    udtDestination->length
        =udtSource->length;
    /*Copy CanId in TxPdu Corressponding buffer                               */
    udtDestination->id
        =udtSource->id;
    /*Copy TxPduId in TxPdu Corressponding buffer                             */
    udtDestination->swPduHandle
        =udtSource->swPduHandle;
    /*Loop on data Length                                                     */
    for(u8CopyIndex=0;u8CopyIndex<udtSource->length;u8CopyIndex++)
    {
        /*Copy Data(PayLoad) in TxPdu Corressponding buffer                   */
        udtDestination->sdu[u8CopyIndex]=udtSource->sdu[u8CopyIndex];
    }
}
#endif
/******************************************************************************/
/*!\Description : This service Sends the highest priority TxPdu buffered      \n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU to be transmitted.     
                   This handle specifies the corresponding CAN L-PDU ID and     
                   implicitly the CAN Driver instance as well as the            
                   corresponding CAN controller device.                       \n
    \Range         0.. PbCfg.CanIf_udtNumofTxPdus-1                           \n
*******************************************************************************/
#if(CanIf_bTX_BUFFERING==STD_ON)
static FUNC(void, CANIF_CODE)vidHandleTransmitBuffer(
    VAR(PduIdType ,AUTOMATIC)CanTxPduId)
{
    /* PRQA S 0781 ++ */
    /*MISRA Msg justification:  names in Struct may be Repeated in Local        
    Variables                                                                 */
    /*CanDrv Write Result                                                     */
    VAR(Can_ReturnType, AUTOMATIC)  udtWriteResult;
    /*Hth that TxPdu Id sassigned to                                          */
    VAR(uint16, AUTOMATIC)          u16Hth;
    /*CanDrv that TxPdu Id sassigned to                                       */
    VAR(uint8, AUTOMATIC)           u8CanDrv;
    /*higest priority TxPdu buffered                                          */
    VAR(PduIdType, AUTOMATIC)       udtHPriorityTxPduId;
	VAR(Can_PduType, AUTOMATIC) udtGlobalPduInfo;
    /* PRQA S 0781 -- */
    /*Determine the Hth Corressponding to the TxConfirmed TxPdu               */
    u16Hth = CanIf_udtGET_TXPDU_PBCFG[CanTxPduId].u16Hth;
    /*Determine Can Driver Id the hth Corressponding to                       */
    u8CanDrv=CanIf_akstreCtrlLCfg[CanIf_akstreHthLCfg[u16Hth].
        u8ControllerId].u8CanDrvId;
    /* \Trace_To CANIF-CDD-0048(0)                                            */
    /*!Search highst priority TxPdu assigned to u16Hth starting from            
    udtTxPduStartIndex                                                        */
    udtHPriorityTxPduId = udtGetHighPriorityTxpdu
        (CanIf_udtGET_HTHTXPDU_PBCFG[u16Hth].udtTxpduStartIndex,u16Hth);
    /* \Trace_To CANIF-CDD-0046(0)                                            */
    /*!Check if pending one found before Writing on CanDrv                    */
    if(udtHPriorityTxPduId!=CanIf_u8INVALID_TXPDU)
    {
		udtGlobalPduInfo.swPduHandle = CanIf_udtGET_TXPDU_PBCFG[udtHPriorityTxPduId].
				CanIf_pudteTxBufferRefer->udtBufferedMessage.swPduHandle;
		udtGlobalPduInfo.length = CanIf_udtGET_TXPDU_PBCFG[udtHPriorityTxPduId].
				CanIf_pudteTxBufferRefer->udtBufferedMessage.length;
		udtGlobalPduInfo.id = CanIf_udtGET_TXPDU_PBCFG[udtHPriorityTxPduId].
				CanIf_pudteTxBufferRefer->udtBufferedMessage.id;
		udtGlobalPduInfo.sdu = CanIf_udtGET_TXPDU_PBCFG[udtHPriorityTxPduId].
				CanIf_pudteTxBufferRefer->udtBufferedMessage.sdu;
        /* \Trace_To CANIF-CDD-0047(0)                                        */
        /*!Write Pending highest priority TxPdu on Candrv                     */
		udtWriteResult = CanIf_akstreCanServicesPCCfg[u8CanDrv]
        .pfenuWrite(CanIf_akstreHthLCfg[u16Hth].udtCanHthRef,
            &(udtGlobalPduInfo));
		
        /*!if Write Trial failed (CAN_BUSY)or(CAN_NOT_OK)                     */
        if((udtWriteResult==CAN_BUSY)||(udtWriteResult==CAN_NOT_OK))
        {
            /*!Leave Message Buffered                                         */
        }
        /* \Trace_To CANIF-CDD-0049(0)                                        */
        /*!else                                                               */
        /*!Write Trial (OK)                                                   */
        else
        {
            /*!reset Queued Flag in the Txpdu Buffer for the alredy written     
            TRxPdu                                                            */
			CanIf_udtGET_TXPDU_PBCFG[udtHPriorityTxPduId].CanIf_pudteTxBufferRefer->
			u8TxbufferStatus = CanIf_u8EMPTY_BUFFER;
        }
    }
}
#endif
/******************************************************************************/
/*!\Description : this service gets the highest priority TxPdu to be            
                   transmitted if found and if not returns                      
                   CanIf_u8INVALID_TXPDU                                      \n
    \param[in]     udtTxPduStart: start index of TxPduIds buffer to start       
                   searching from                                             \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
    \param[in]     u16Hth: Hth that all searching process will take place in    
                   all buffers of Txpdus assigned to it                       \n
    \Range         0..CanIf_ku16eNumOfHth-1                                   \n
    \return        Highest Priority TxPdu buffered                            \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
*******************************************************************************/
#if(CanIf_bTX_BUFFERING==STD_ON)
/* PRQA S 8023,8223,8423 ++ */
LOCAL_INLINE FUNC(PduIdType, CANIF_CODE)udtGetHighPriorityTxpdu(
    VAR(PduIdType ,AUTOMATIC)udtTxPduStart
    ,VAR(uint16, AUTOMATIC) u16Hth)
/* PRQA S 8023,8223,8423 -- */
{
    /*the search index that will be used in searching                         */
    VAR(PduIdType ,AUTOMATIC)   udtTxPduSearchIndex;
    /*the next index that will be used in searching                           */
    VAR(PduIdType ,AUTOMATIC)   udtTxPduNextIndex;
    /*boollen to abort loops                                                  */
    VAR(boolean,AUTOMATIC)      bAbortLoop=CanIf_u8RESUME_LOOP;
    /*Can Id of udtTxPduSearchIndex                                           */
    VAR(Can_IdType,AUTOMATIC)   udtCurrrentCanId;
    /*CanId of udtTxPduNextIndex                                              */
    VAR(Can_IdType,AUTOMATIC)   udtNextCanId;
/* PRQA S 8018,8318,8518 ++ */
	P2CONST(CanIf_tstrTxPduPbCfg, AUTOMATIC, CANIF_APPL_CONST) 
                                 pkudtTxPduPbCfg=CanIf_udtGET_TXPDU_PBCFG;
	CONST(PduIdType, AUTOMATIC)     kudtNumofTxPdus=CanIf_udtGET_NUMOFTX_PBCFG;
/* PRQA S 8018,8318,8518 -- */
    /*!loop on Txpdus assigned to Get first Queued Index if exists            */
	while((pkudtTxPduPbCfg[udtTxPduStart]
            .CanIf_pudteTxBufferRefer->u8TxbufferStatus==CanIf_u8EMPTY_BUFFER)&&
            ((udtTxPduStart<kudtNumofTxPdus)&&(bAbortLoop
               !=CanIf_u8ABORT_LOOP)))
    {
        /*!increment TxPduId                                                  */
        udtTxPduStart++;
        /*!if didn't exceed the free Hth                                      */
        if((pkudtTxPduPbCfg[udtTxPduStart].u16Hth ==u16Hth))
        {
            /*!Do Nothing                                                     */
        }
        /*!else                                                               */
        else
        {
            /*!dectrement TxPduId to avoid incorrect memory access            */
            udtTxPduStart--;
            /*no Queued TxPdu Found                                           */
            bAbortLoop=CanIf_u8ABORT_LOOP;
        }
    }
    /*!if at least one Queued TxPdu found                                     */
    if((udtTxPduStart<CanIf_udtGET_NUMOFTX_PBCFG)&&
        (bAbortLoop==CanIf_u8RESUME_LOOP))
    {
        /*!assign the Search index to found Queued one                        */
        udtTxPduSearchIndex = udtTxPduStart;
        /*!assign the Next index to found Queued +1                           */
        udtTxPduNextIndex = udtTxPduStart+1;
        bAbortLoop=CanIf_u8RESUME_LOOP;
        /*!loop to find the higest priority queued TxPdu                      */
        while((bAbortLoop!=CanIf_u8ABORT_LOOP)
            &&(udtTxPduNextIndex<kudtNumofTxPdus))
        {
            /*!if didn't exceed the free Hth                                  */
            if((pkudtTxPduPbCfg[udtTxPduNextIndex].u16Hth ==u16Hth))
            {
                udtCurrrentCanId = udtGetNormalizedCanId(udtTxPduSearchIndex);
                udtNextCanId = udtGetNormalizedCanId(udtTxPduNextIndex);
                /*!if Next (Normalized)index higehst priority to (Normalized)
                Search index and Queued                                       */
				if((pkudtTxPduPbCfg[udtTxPduNextIndex].CanIf_pudteTxBufferRefer->u8TxbufferStatus
                    !=CanIf_u8EMPTY_BUFFER)&&(udtCurrrentCanId>udtNextCanId))
                {
                    /*!Search index equal Next index                          */
                    udtTxPduSearchIndex = udtTxPduNextIndex;
                }
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
                /*!else if Next (Normalized)index same priority to (Normalized)
                   Search index and Queued                                    */
				else if((pkudtTxPduPbCfg[udtTxPduNextIndex].CanIf_pudteTxBufferRefer->
				u8TxbufferStatus!=CanIf_u8EMPTY_BUFFER)&&(udtCurrrentCanId==udtNextCanId))
                {
                    udtTxPduSearchIndex=udtHandleSESameCanId(udtTxPduNextIndex
                        ,udtTxPduSearchIndex);
                }
#endif
                /*!else                                                       */
                else
                {
                    /*!Do nothing                                             */
                }
            }
            /*!else                                                           */
            /*!exceed the free Hth                                            */
            else
            {
                /*!abort loop                                                 */
                bAbortLoop=CanIf_u8ABORT_LOOP;
            }
            /*!increment Next index                                           */
            udtTxPduNextIndex++;
        }
    }
    /*!else                                                                   */
    /*!No Queued TxPdu found                                                  */
    else
    {
        /*!return CanIf_u8INVALID_TXPDU                                       */
        udtTxPduSearchIndex=CanIf_u8INVALID_TXPDU;
    }
        /*!return Found Highest priority TxPduId if Found and 
        CanIf_u8INVALID_TXPDU if not found                                    */
    return(udtTxPduSearchIndex);
}
#endif
/******************************************************************************/
/*!\Description : Normalize CanId (if needed)to make standard CanIds            
                   corresponds to Base Id of Extended one                     \n
    \param[in]     CanTxPduId: TxPduId that is required to normalize it         
                   CabnId                                                     \n
    \Range         0.. PbCfg.CanIf_udtNumofTxPdus-1                           \n
    \return        CanId after normalization                                  \n
    \Range         0x..1FFFFFFF                                               \n
*******************************************************************************/
#if(CanIf_bTX_BUFFERING==STD_ON)
static FUNC(Can_IdType, CANIF_CODE)udtGetNormalizedCanId(
    VAR(PduIdType ,AUTOMATIC)CanTxPduId)
{
/* PRQA S 0781 ++ */
/*MISRA Msg justification:  names in Struct may be Repeated in Local Variables*/
    /*the return of the service                                               */
    VAR(Can_IdType,AUTOMATIC)udtCanId;
/* PRQA S 0781 -- */
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
    /*!if the Buffered Message has an extended CanId                          */
	if(((CanIf_udtGET_TXPDU_PBCFG[CanTxPduId].CanIf_pudteTxBufferRefer->
	udtBufferedMessage.id)&(CanIf_u32CANID_MSB_MASK))==CanIf_u32CANID_MSB_MASK)
    {
        /*!clear the MSB (BIF) and retrn this CanId                           */
		udtCanId=((CanIf_udtGET_TXPDU_PBCFG[CanTxPduId].CanIf_pudteTxBufferRefer->
		udtBufferedMessage.id)&(~CanIf_u32CANID_MSB_MASK));	
    }
    /*!else                                                                   */
    /*!standard CanId                                                         */
    else
    {
        /*!Shift left this CanId 18 bit then return this CanId                */
		udtCanId=((CanIf_udtGET_TXPDU_PBCFG[CanTxPduId].CanIf_pudteTxBufferRefer->udtBufferedMessage.id)<<18);
    }
#else
    /*!no extended CanIds Configured, Retuen Standard CanId as it is          */
	udtCanId=CanIf_udtGET_TXPDU_PBCFG[CanTxPduId].CanIf_pudteTxBufferRefer->udtBufferedMessage.id;	
#endif
    /*Return Normalized CanId                                                 */
    return(udtCanId);
}
#endif
/******************************************************************************/
/*!\Description : To Get Standard CanId in case comparing 2 CanIds (Same)       
                   Base Id(return TxPduId of the Standard CanId)              \n
    \param[in]     udtTxPduNext: Next TxPduId with same Can Id as               
                   udtTxPduSearch                                             \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
    \param[in]     udtTxPduSearch: xx                                         \n
    \return        Standard TxPduId                                           \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
*******************************************************************************/
#if((CanIf_bTX_BUFFERING==STD_ON)&&(CanIf_u8CANIDTYPE==CanIf_u8UINT32))
/* PRQA S 8023,8223,8423 ++ */
LOCAL_INLINE FUNC(PduIdType, CANIF_CODE)udtHandleSESameCanId(
    VAR(PduIdType ,AUTOMATIC)udtTxPduNext
    ,VAR(PduIdType ,AUTOMATIC)udtTxPduSearch)
/* PRQA S 8023,8223,8423 -- */
{
    /*the standard TxPduId (return of the service)                            */
    VAR(PduIdType ,AUTOMATIC)udtStandardPdu;
    /*!if the Next Buffered Message has an extended CanId*/
	if(((CanIf_udtGET_TXPDU_PBCFG[udtTxPduNext].CanIf_pudteTxBufferRefer->
	udtBufferedMessage.id)&(CanIf_u32CANID_MSB_MASK))==CanIf_u32CANID_MSB_MASK)
    {
        /*!The Standard CanId is for the Currnet TxPdu                        */
        udtStandardPdu=udtTxPduSearch;
    }
    /*!else                                                                   */
    /*!standard CanId                                                         */
    else
    {
        /*!The Standard CanId is for the Next TxPdu                           */
        udtStandardPdu=udtTxPduNext;
    }
    /*!return The Standard TxPdu                                              */
    return(udtStandardPdu);
}
#endif
/******************************************************************************/
/*!\Description : this service get Can Id from RAM or Flash                     
                   (Static or Dynamic) and Set BIF or not                       
                   (Extended or Standard)                                     \n
    \param[in]     CanTxPduId: CanTxPduId: L-PDU handle of CAN L-PDU            
                   to be transmitted.This handle specifies the corresponding    
                   CAN L-PDU ID and implicitly the CAN Driver instance as       
                   well as the corresponding CAN controller device.           \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
    \return        BIF##CanId                                                 \n
    \Range         BIF##CanId                                                 \n
*******************************************************************************/
/* PRQA S 8023,8223,8423 ++ */
LOCAL_INLINE FUNC(Can_IdType, CANIF_CODE)udtSetCanId(
    CONST(PduIdType ,AUTOMATIC)udtCanTxPduId)
/* PRQA S 8023,8223,8423 -- */
{
    /*the return of the set=rvice                                             */
    Can_IdType udtCanIdReturn;
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
	P2VAR(Can_IdType, AUTOMATIC, AUTOMATIC)          pudtCanId;
#endif
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
	P2VAR(CanIf_tenuCanIdType, AUTOMATIC, AUTOMATIC) pudtCanIdType;
#endif
/*!#if CANIF_PUBLIC_SETDYNAMICTXID_API is enabled                             */
#if(CanIf_bSET_DYNAMIC_TXID_API==STD_ON)
	pudtCanId=&(CanIf_udtGET_DYCANID_PBCFG[CanIf_udtGET_TXPDU_PBCFG
		[udtCanTxPduId].udtDyCanIdIndex].udtCanId);
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
	pudtCanIdType=&(CanIf_udtGET_DYCANID_PBCFG[CanIf_udtGET_TXPDU_PBCFG
		[udtCanTxPduId].udtDyCanIdIndex].udtCanIdType);
#endif
    /*!if udtCanTxPduId is from Dynamic type                                  */
    if(CanIf_udtGET_TXPDU_PBCFG[udtCanTxPduId].enuTXPduType==CanIf_DYNAMIC)
    {
        /*!get the Dynamic CanId from Dynamic CanId array usingindex Configured 
        for udtCanTxPduId                                                     */
        /* \Trace_To CANIF-CDD-0181(0)                                        */
        /*set the identifier extension flag of the CanId before the CanIf passes
        the static predefined CanId to the CanDrv at call of Can_Write().*/
        SchM_Enter_CanIf_DynTxPduCanId_05();
        /*!#if CanIdType is uint32                                            */
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
        if( *pudtCanIdType == CanIf_EXTENDED )
        {
            udtCanIdReturn=(*pudtCanId)|CanIf_u32CANID_MSB_MASK;
        }
        else
        {
#endif
            udtCanIdReturn=(*pudtCanId);
            /*!#if CanIdType is uint32                                        */
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
        }
#endif
        SchM_Exit_CanIf_DynTxPduCanId_05();
    }
    /*!else udtCanTxPduId is from Static type                                 */
    else
    {
        /*!get the Static CanId from udtCanTxPduId Config                     */
        /* \Trace_To CANIF-CDD-0181(0)                                        */
        /*set the identifier extension flag of the CanId before the CanIf passes
        the static predefined CanId to the CanDrv at call of Can_Write().     */
/*!#if CanIdType is uint32                                                    */
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
        if(CanIf_udtGET_TXPDU_PBCFG[udtCanTxPduId].enuCanIdType ==CanIf_EXTENDED)
        {
            udtCanIdReturn=CanIf_udtGET_TXPDU_PBCFG[udtCanTxPduId].
                udtCanId|CanIf_u32CANID_MSB_MASK;
        }
        else
        {
#endif
            udtCanIdReturn=CanIf_udtGET_TXPDU_PBCFG[udtCanTxPduId].udtCanId;
            /*!#if CanIdType is uint32                                        */
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
        }
#endif
    }
#else
    /*! No Dynamic udtCanTxPduId is configured                                */
    /*! get the Static CanId from udtCanTxPduId Config                        */
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
    if(CanIf_udtGET_TXPDU_PBCFG[udtCanTxPduId].enuCanIdType==CanIf_EXTENDED)
    {
        udtCanIdReturn=CanIf_udtGET_TXPDU_PBCFG[udtCanTxPduId]
            .udtCanId|CanIf_u32CANID_MSB_MASK;
    }
    else
    {
#endif
        udtCanIdReturn=CanIf_udtGET_TXPDU_PBCFG[udtCanTxPduId].udtCanId;
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
    }
#endif
#endif
    return(udtCanIdReturn);
}
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */ 
/*--------------------------------End of File---------------------------------*/

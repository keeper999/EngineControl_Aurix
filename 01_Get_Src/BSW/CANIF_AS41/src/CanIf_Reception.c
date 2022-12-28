/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_Reception                                         */
/*!\file            : CanIf_Reception.c                                       \n
    \Description    : Responsible for Reception related functionalities       */
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
/* $Revision::   1.41     $$Author::   mamroussy      $$Date::   Aug 03 2014 $*/
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
#include"CanIf.h"
#include "CanIf_LocalCfg.h"
#include "CanIf_LocalLCfg.h"
#include "CanIf_PBCfg.h"
#include"CanIf_Reception.h"
#include"CanIf_General.h"
#include "SchM_CanIf.h"
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
#include "Det.h"
#endif
#if(CanIf_bDEM_ERR_DETECT == STD_ON)
#include "Dem.h"
#endif
/****************************Version Checking**********************************/
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
#define u16INVLD_DEM_E_DLC                                      ((uint16)0xFFFFUL)

#define CANIF_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************/
/*                          LOCAL FUNCTION DECLARATION                        */
/******************************************************************************/
/******************************************************************************/
/*!\Description : This service Perform Actual Work Of RxIndication after        
                   RxPduId has been Found successfully                       \n
    \param[in]     udtReceivedRxPduId: received Rxpduid                      \n
    \Range         0..PbCfg.CanIf_udtNumofRxPdus-1                           \n
    \param[in]     u8Length: received Length (Configured or Received)        \n
    \Range         1..8                                                      \n
    \param[in]     pku8CanSduPtr: pointer to pay load                        \n
    \Range         not Null                                                  \n
*******************************************************************************/
/* PRQA S 3447,8023,8223,8423 ++ */
/*MISRA Msg justification: Local Inlining                                     */
LOCAL_INLINE FUNC(void, CANIF_CODE)vidLocalRxIndication(
    VAR(PduIdType, AUTOMATIC)   udtReceivedRxPduId,
    VAR(uint8, AUTOMATIC)       u8Length,
#if (COMSTACK_coPDU_INFO_TYPE_ADD_CANID == COMSTACK_coENABLE)       
	VAR(Can_IdType, AUTOMATIC)udtNormCanId,
#endif  
    P2CONST(uint8,AUTOMATIC,CANIF_APPL_CONST)pku8CanSduPtr);
/* PRQA S 3447,8023,8223,8423 -- */  
/******************************************************************************/
/*!\Description : Get the CanIf Hrh using CanDrv HRH reference and CanDrvId   \n
    \param[in]     CanDrvId: the Driver that envoked Rx_Indication            \n
    \Range         0..CanIf_u8NUM_OF_CAN_DRVS-1                               \n
    \param[in]     Hrh: Hard Ware Receive hande of this CanDrvId              \n
    \Range         0..(number of Hrhs assigned to this CanDrvId-1)            \n
    \return        Abstracted CanIf hrh                                       \n
    \Range         0..CanIf_ku16eNumOfHrh-1,(CanIf_u16INVALID_HRH case          
                   searching failed                                           \n
*******************************************************************************/
/* PRQA S 3447,8023,8223,8423 ++ */
/*MISRA Msg justification: Local Inlining                                     */
LOCAL_INLINE FUNC(uint16, CANIF_CODE)u16GetCanIfHrh(
    VAR(Can_HwHandleType, AUTOMATIC) Hrh,    
	VAR(uint8, AUTOMATIC) u8CanDrvId);
/* PRQA S 3447,8023,8223,8423 -- */      
/******************************************************************************/
/*!\Description : This service Search using CanId and And CanId Type to get     
                   RxPduId                                                    \n
    \param[in]     u16CanIfHrh: CanIf Hrh that message received on            \n
    \Range         0..CanIf_ku16eNumOfHrh-1                                   \n
    \param[in]     CanId: received Can Id after normalization                 \n
    \Range         0..0x7FF Standard, 0..536870911 Extended                     
                   BIF: 0 Standard , 1 Extended                               \n
    \param[in]     udtCanIdType: type of received CanId                       \n
    \Range         Standard , Extended                                        \n
    \return        found Rxpduid                                              \n
    \Range         0..PbCfg.CanIf_udtNumofRxPdus-1, CanIf_u8INVALID_RXPDU in    
                   case not found                                             \n
*******************************************************************************/
/* PRQA S 3447,8023,8223,8423 ++ */
/*MISRA Msg justification: Local Inlining                                     */
#if (CanIf_noBASIC_CAN_PDU==STD_OFF)
LOCAL_INLINE FUNC(PduIdType, CANIF_CODE)udtSearchRxPdu(
    VAR(uint16, AUTOMATIC)  u16CanIfHrh,
    VAR(Can_IdType, AUTOMATIC) CanId,
    VAR(CanIf_tenuCanIdType, AUTOMATIC) udtCanIdType);
#endif
/* PRQA S 3447,8023,8223,8423 -- */  
/******************************************************************************/
/*!\Description : Perform Hrh Sw Filtr (Upper Range and Lower Range)          \n
    \param[in]     u16CanIfHrh: CanIf Hrh that message received on            \n
    \Range         0..CanIf_ku16eNumOfHrh-1                                   \n
    \param[in]     CanId: received Can Id after normalization                 \n
    \Range         0..0x7FF Standard, 0..536870911 Extended                   \n
    \param[in]     udtCanIdType: type of received CanId                       \n
    \Range         Standard , Extended                                        \n
    \return        to indicate that hrh Sw Filted passed or failed            \n
    \Range         CanIf_u8HRH_SW_FIL_FAILED, CanIf_u8HRH_SW_FIL_PASSED       \n
*******************************************************************************/
#if(CanIf_bHRH_SW_FILTER==STD_ON)
/* PRQA S 3447,8023,8223,8423 ++ */
/*MISRA Msg justification: Local Inlining                                     */
LOCAL_INLINE FUNC(uint8, CANIF_CODE)u8HrhSwFilter(
                            VAR(uint16, AUTOMATIC) u16CanIfHrh,
                            VAR(Can_IdType, AUTOMATIC) CanId,
                            VAR(CanIf_tenuCanIdType, AUTOMATIC) udtCanIdType);
/* PRQA S 3447,8023,8223,8423 -- */ 
#endif
/******************************************************************************/
/*!\Description : normalize the Received CanId (using BIF)from Driver to        
                  CanId and Type(Standard and Extended)                       \n
    \param[out]     pudtCanIdPtr: pointer to normalized CanId(out param)      \n
    \Range         not null                                                   \n
    \param[out]     pudtCanIdTypePtr:  pudtCanIdPtr: pointer to CanId type      
                   (out param)                                                \n
    \Range         not null                                                   \n
    \param[in]     udtCanId: received CanId(Not normalized)                   \n
    \Range         0..0x7FF         0..536870911                                
                   BIF: 0 Standard , 0 Extended                               \n
    \return        Bad or CanId                                               \n
    \Range         CanIf_u8ABORT_RX_INDICATION..CanIf_u8RESUME_RX_INDICATION  \n
*******************************************************************************/
/* PRQA S 3447,8023,8223,8423 ++ */
/*MISRA Msg justification: Local Inlining                                     */
LOCAL_INLINE FUNC(uint8, CANIF_CODE)u8NormalizeCanId(
                            P2VAR(Can_IdType, AUTOMATIC,CANIF_VAR)pudtCanIdPtr,
                            VAR(Can_IdType, AUTOMATIC)  udtCanId,
							P2VAR(CanIf_tenuCanIdType, AUTOMATIC,CANIF_VAR) 
                            pudtCanIdTypePtr);
/* PRQA S 3447,8023,8223,8423 -- */                             
/******************************************************************************/
/*!\Description : This service Perform Hrh Sw Filter and Search the             
                   Corressponding RxPduId                                     \n
    \param[in]     u16CanIfHrh: Hrh that Message received on                  \n
    \Range         0..CanIf_ku16eNumOfHrh-1                                   \n
     \param[in]    udtCanId: received Can Id after normalization              \n
    \Range         0..0x7FF Standard, 0..536870911 Extended                   \n
    \param[in]     udtCanIdType: type of received CanId                       \n
    \Range         Standard , Extended                                        \n
    \return        found Rxpduid                                              \n
    \Range         0..PbCfg.CanIf_udtNumofRxPdus-1, CanIf_u8INVALID_RXPDU in    
                   case not found                                             \n
*******************************************************************************/
/* PRQA S 3447,8023,8223,8423 ++ */
/*MISRA Msg justification: Local Inlining                                     */
LOCAL_INLINE FUNC(PduIdType, CANIF_CODE)udtGetRxPduId(
    VAR(uint16, AUTOMATIC)  u16CanIfHrh,
    VAR(Can_IdType, AUTOMATIC) udtCanId,
    VAR(CanIf_tenuCanIdType, AUTOMATIC) udtCanIdType);
/* PRQA S 3447,8023,8223,8423 -- */        
/******************************************************************************/
/*                          GLOBAL FUNCTION DEFINITIONS                       */
/******************************************************************************/

/******************************************************************************/
/*!\Description : This service indicates a successful reception of a received   
                   CAN Rx L-PDU to the CanIf after passing all filters and      
                   validation checks.                                         \n
    \param[in]     CanDrvId: Can Drriver                                      \n
    \Range         0..CanIf_u8NUM_OF_CAN_DRVS-1                               \n
    \param[in]     Hrh: ID of the corresponding Hardware Object               \n
    \Range         0..(number of Hrh assigned to CanDrvId-1)                  \n
    \param[in]     CanId: Standard/Extended CAN ID of CAN L-PDU that            
                          has been successfully received                      \n
    \Range         0..0x7FF Standard    0..536870911 Extended                   
                   BIF: 0 Standard , 1 Extended                               \n
    \param[in]     CanDlc: Data Length Code (length of CAN L-PDU payload)     \n
    \Range         1..8                                                       \n
    \param[in]     CanSduPtr: Pointer to received L-SDU (payload)             \n
    \Range         Not Null                                                   \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
/* PRQA S 4700 ++ */
/*MISRA Msg justification:  Already Internal Services used , If more exec time 
                            will exceeds Normal                               */
FUNC(void, CANIF_CODE)CanIf_vidLocalRxIndic(
    VAR(Can_HwHandleType,       AUTOMATIC) Hrh,
    VAR(Can_IdType, AUTOMATIC)  CanId,
    VAR(uint8, AUTOMATIC)   CanDlc,
    P2CONST(uint8,AUTOMATIC,CANIF_APPL_CONST)CanSduPtr,
	VAR(uint8, AUTOMATIC)       CanDrvId)
{
/* PRQA S 0781 ++ */
/*MISRA Msg justification:  names in Struct may be Repeated in Local Variables*/
    /*Hrh thatmessage received on                                             */
    VAR(uint16, AUTOMATIC)                      u16CanIfHrh;
    /*received RxPduId                                                        */
    VAR(PduIdType, AUTOMATIC)                   udtRxPduId;
    /*Normalized Received CanId (after BIF analysed )                         */
    VAR(Can_IdType, AUTOMATIC)                  udtNormalizedCanId;
    /*Received CanId type (Extended , Standared)                              */
    VAR(CanIf_tenuCanIdType, AUTOMATIC)         udtCanIdType;
#if(CanIf_bDLC_CHECK==STD_ON)
    /*Dlc Check result                                                        */
    VAR(uint8, AUTOMATIC)                       u8DlcCkeckResult
        =CanIf_u8DLC_CHECK_PASSED;
#endif
    /*Length that will be passed to UL (Received or Configured)               */
    VAR(uint8, AUTOMATIC)                       u8UsedLength;
    /* reception status to break in failed level                              */
    VAR(uint8, AUTOMATIC)                       u8ReceptionStatus;
    /*Local Copy of current controller mode                                   */
    VAR(CanIf_ControllerModeType, AUTOMATIC)    udtCurrControllerMode;
    /*local copy of Pdu channel ode Rx path                                   */
    VAR(CanIf_tstrPduMode, AUTOMATIC)           udtLocalTxRxPathPdu;
/* PRQA S 0781 -- */
    /* \Trace_To CANIF-CDD-0317(0)                                            */
    /* \Trace_To CANIF-CDD-5083(0)                                            */
    /*!if Canif is not Initialized                                            */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        /* \Trace_To CANIF-CDD-0317(0)                                        */
        /*! Report to the DET (using CANIF_E_UNINIT)                          */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8RXINDICAT_API, CANIF_E_UNINIT);
#endif
    }
    /*!else                                                                   */
    /* \Trace_To CANIF-CDD-0318(0)                                            */
    else
    {
        u8ReceptionStatus = u8NormalizeCanId(&udtNormalizedCanId,CanId,
            &udtCanIdType);
        /*!if CanId Valitity Check passed                                     */
        if(u8ReceptionStatus==CanIf_u8RESUME_RX_INDICATION)
        {
            /* \Trace_To CANIF-CDD-0315(0)                                    */
            /*!if CanDlc is 0 or more than 8                                  */
            if((CanDlc==0)||(CanDlc>8))
            {
                /* \Trace_To CANIF-CDD-0315(0)                                */
                 /*! Report to the DET (using CANIF_E_PARAM_DLC)              */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
                CanIf_vidDET_REPORT_ERROR(CanIf_u8RXINDICAT_API,
                    CANIF_E_PARAM_DLC);
#endif
                u8ReceptionStatus=CanIf_u8ABORT_RX_INDICATION;
                /*!Abort RxIndication                                         */
            }
        }
        /*!if CanDlc Valitity Check passed*/
        if(u8ReceptionStatus==CanIf_u8RESUME_RX_INDICATION)
        {
            /* \Trace_To CANIF-CDD-0316(0)                                    */
            /*!if DataPtr is Null                                             */
            /* PRQA S 1311 ++ */
            /*MISRA Msg justification:   (casting to (void *) Compiler.h COTS)*/
            if(CanSduPtr==NULL_PTR)
            /* PRQA S 1311 -- */
            {
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
                /*! Report to the DET (using CANIF_E_PARAM_POINTER)           */
                CanIf_vidDET_REPORT_ERROR(CanIf_u8RXINDICAT_API,
                    CANIF_E_PARAM_POINTER);
#endif
                u8ReceptionStatus=CanIf_u8ABORT_RX_INDICATION;
                /*!Abort RxIndication                                         */
            }
        }
        /*!if Data Ptr Valitity Check passed                                  */
        if(u8ReceptionStatus==CanIf_u8RESUME_RX_INDICATION)
        {
            /*!get CanIf Hrh using HRH Reference of CanDrv                    */
            u16CanIfHrh = u16GetCanIfHrh(Hrh,CanDrvId);

            if(u16CanIfHrh==CanIf_u16INVALID_HRH)
            {
                /* \Trace_To CANIF-CDD-0313(0)                                */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
                /*! Report to the DET (using CANIF_E_PARAM_HRH)               */
                CanIf_vidDET_REPORT_ERROR(CanIf_u8RXINDICAT_API,
                    CANIF_E_PARAM_HRH);
                /*Skip RxIndication                                           */
#endif
#if(CanIf_bWAKUP_CHK_VALID_API==STD_ON)
                udtRxPduId = CanIf_u8INVALID_RXPDU;
#endif
            }
            /* \Trace_To CANIF-CDD-5014(0)                                    */
            /* \Trace_To CANIF-CDD-5018(0)                                    */
            /*!elseif PduChannel Mode is Rx Offline or Controller mode is       
               Stopped                                                        */
            /* \Trace_To CANIF-CDD-0507(0)                                    */
            /* \Trace_To CANIF-CDD-0127(0)                                    */
            else
			{
				/*!get Current Controller mode                                    */
				SchM_Enter_CanIf_CurrConMode_14();
                udtCurrControllerMode=CanIf_aenueCurrControllerMode
                    [CanIf_akstreHrhLCfg[u16CanIfHrh].u8ControllerId];
                SchM_Exit_CanIf_CurrConMode_14();
                SchM_Enter_CanIf_PduChnlMod_14();
                udtLocalTxRxPathPdu.enuRxPath=CanIf_astreCurrPduChannelMode
                [CanIf_akstreHrhLCfg[u16CanIfHrh].u8ControllerId].enuRxPath;
                SchM_Exit_CanIf_PduChnlMod_14();
				/* \Trace_To CANIF-CDD-0313(0)                                    */
				/*!if  CanIf Hrh not found(HRH Reference of CanDrv is uncorrect     
				CanIf_u16INVALID_HRH = 0xFFFF)                                 */
				/* \Trace_To CANIF-CDD-0311(0)                                    */
                udtRxPduId=udtGetRxPduId(u16CanIfHrh,udtNormalizedCanId,
                    udtCanIdType);

			if(((udtCurrControllerMode==CANIF_CS_STOPPED)
                ||
                (udtCurrControllerMode==CANIF_CS_SLEEP))
                ||
                (udtLocalTxRxPathPdu.enuRxPath==CanIf_RX_PATH_OFFLINE))
            {
                /*!Do Nothing and Abort RxIndication                          */
            }
            /* \Trace_To CANIF-CDD-5022(0)                                    */
            /* \Trace_To CANIF-CDD-0127(0)                                    */
            /*!else                                                           */
            /*!Start Filteration and Search                                   */
            else
			{
                /* \Trace_To CANIF-CDD-0057(0)                                */
                /*!if the Result is not (RxPduId not found)                     
                (CanIf_u8INVALID_RXPDU==(PduIdType)0xFFFFFFFF)                */
                if(udtRxPduId!=CanIf_u8INVALID_RXPDU)
                {
                    /* \Trace_To CANIF-CDD-0058(0)                            */
#if(CanIf_bDLC_CHECK==STD_ON)
                    /* \Trace_To CANIF-CDD-0058(0)                            */
                    /*!Check if Configured Dlc is not 0 (Static Dlc)          */
                    /*!if DlcCheck is enabled                                 */
                    if(CanIf_udtGET_RXPDU_PBCFG[udtRxPduId].u8DLC!=0)
                    {
                        /* \Trace_To CANIF-CDD-0058(0)                        */
                        /*!Start Dic Check                                    */
                        u8DlcCkeckResult=CanIf_u8CheckDlc((PduLengthType)CanDlc,
                            CanIf_udtGET_RXPDU_PBCFG[udtRxPduId].u8DLC);
                        /* \Trace_To CANIF-CDD-5262(0)                        */
                        /*!used length is configured one not received one     */
                        u8UsedLength=CanIf_udtGET_RXPDU_PBCFG[udtRxPduId].u8DLC;
                    }
                    /*!else                                                   */
                    else
                    {
                        /*!leave DlcCheck Passed as a default in case it is     
                        disabled                                              */
                        /*!used length is received one                        */
                        /* \Trace_To CANIF-CDD-5262(0)                        */
                        u8UsedLength=CanDlc;
                    }
                    /* \Trace_To CANIF-CDD-0137(0)                            */
                    /*!if DlcCheck Passed                                     */
                    if(u8DlcCkeckResult==CanIf_u8DLC_CHECK_PASSED)
                    {
#else
                        /* \Trace_To CANIF-CDD-5262(0)                        */
                        /*!used length is received one                        */
                        u8UsedLength=CanDlc;
#endif
                    /* \Trace_To CANIF-CDD-0311(0)                            */
                    /*!Perform Actual Work Of RxIndication after RxPduId
                    has been Found successfully                               */
                    /* PRQA S 2215 ++ */
                    /*MISRA Msg justification:   Indentation is not consistent 
                    with configured depth.as Pre-Compile Config Affect 
                    Indentation                                               */
                    vidLocalRxIndication(udtRxPduId,u8UsedLength,
#if (COMSTACK_coPDU_INFO_TYPE_ADD_CANID == COMSTACK_coENABLE)                      
                    udtNormalizedCanId,
#endif
					CanSduPtr);					
                    /* PRQA S 2215 -- */
#if(CanIf_bDLC_CHECK==STD_ON)
                    }
                    /*!else                                                   */
                    else
                    {
                        /* \Trace_To CANIF-CDD-0137(0)                        */
                        /* \Trace_To CANIF-CDD-5080(0)                        */
                        /* \Trace_To CANIF-CDD-5081(0)                        */
                        /*!Skip RxIndication Dic Check Failed                 */
                       if(CanIf_udtGET_RXPDU_PBCFG
                            [udtRxPduId].u16DemInvalidDlc!=u16INVLD_DEM_E_DLC)
                       {
#if(CanIf_bDEM_ERR_DETECT == STD_ON)
                           Dem_ReportErrorStatus(CanIf_udtGET_RXPDU_PBCFG
                            [udtRxPduId].u16DemInvalidDlc,
                            DEM_EVENT_STATUS_FAILED);
#endif
                       }
                    }
#endif
                }
            }
		}
#if((CanIf_bWAKUP_CHK_VALID_API==STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
            /*===========================Wakeup Validation====================*/
            /*!if Wakeup Support for that Controller is Enabled and The 
            Hrh is found*/
            /* PRQA S 3353 ++ */
            /*MISRA Msg justification:  u16CanIfHrh,udtCurrControllerMode
                                        ,udtRxPduId,u8DlcCkeckResult,is 
                                        sure set before this pointand 
                                        not invalid                           */
            /* PRQA S 3689 ++ */
            /*MISRA Msg justification:  u16CanIfHrh isn't out of pounds set 
                                        by u16GetCanIfHrh and 
                                        !=CanIf_u16INVALID_HRH                */
            if((udtRxPduId!=CanIf_u8INVALID_RXPDU)
#if(CanIf_bDLC_CHECK==STD_ON)
                &&(u8DlcCkeckResult==CanIf_u8DLC_CHECK_PASSED)
#endif
                )
            {
#if(CanIf_bWAKEUP_VALID_BY_NM==STD_ON)
				if(CanIf_udtGET_RXPDU_PBCFG
                    [udtRxPduId].CanIf_pudteUlId->u8UpperComponent == u8CAN_NM)
                {
#endif
                    if(CanIf_akstreCtrlLCfg
                        [CanIf_akstreHrhLCfg[u16CanIfHrh].
                        u8ControllerId].bWakeupSupport==STD_ON)
                    {
                        SchM_Enter_CanIf_CtrlWakeup_14();
                        /*!if the Controller is in started or stopprd mode    */
                        if((udtCurrControllerMode==CANIF_CS_STARTED)||
                            (udtCurrControllerMode==CANIF_CS_STOPPED))
                        {
                            /*!if a wakeup event is stored for that controller*/
                            if(CanIf_astreCtrlWakeup[CanIf_akstreCtrlLCfg
                                [CanIf_akstreHrhLCfg[u16CanIfHrh]
                                .u8ControllerId].u8WkupEventIndex]
                                .bWakeupEvent==E_OK)
                            {
                                /* |Trace_To CANIF-CDD-0116(0)                */
                                /*!Store a wakeup validation event            */
                                CanIf_astreCtrlWakeup
                                    [CanIf_akstreCtrlLCfg[CanIf_akstreHrhLCfg
                                    [u16CanIfHrh].u8ControllerId]
                                    .u8WkupEventIndex].bWakeupValidation=E_OK;
                            }
                        }
                        /*!else*/
                        else
                        {
                            /*!Store a wakeup validation event                */
                            /* \Trace_To CANIF-CDD-0115(0)                    */
                            CanIf_astreCtrlWakeup
                                [CanIf_akstreCtrlLCfg[CanIf_akstreHrhLCfg
                                [u16CanIfHrh].u8ControllerId].u8WkupEventIndex]
                                .bWakeupValidation=E_OK;
                        }
                        SchM_Exit_CanIf_CtrlWakeup_14();
                    }
#if(CanIf_bWAKEUP_VALID_BY_NM==STD_ON)
                }
#endif
            }
            /* PRQA S 3353 -- */
            /* PRQA S 3689 -- */
#endif
        }
    }
}
/* PRQA S 4700 -- */
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)
/******************************************************************************/
/*!\Description : This service returns the indication status                    
                   (indication occurred or not) of a specific CAN Rx L-PDU,     
                   requested by the CanRxPduId.                               \n
    \param[in]     CanRxPduId: L-PDU handle of CAN L-PDU to be received.        
                   This handle specifies the corresponding CAN L-PDU ID and     
                   implicitly the CAN Driver instance as well as the            
                   corresponding CAN controller device.                       \n
    \Range         0..(PbCfg.CanIf_udtNumofRxPdus-1)                          \n
    \return        Current indication status of the corresponding CAN Rx        
                   L-PDU.                                                     \n
    \Range         CANIF_NO_NOTIFICATION,CANIF_TX_RX_NOTIFICATION             \n
    \Trace_To CANIF-CDD-0237(0)                                                 
*******************************************************************************/
/* PRQA S 3206 ++ */
/* MISRA Msg justification: CanRxPduId can't be removed from the function 
		declaration even if it was not used because it is an Autosar service*/
FUNC(CanIf_NotifStatusType, CANIF_CODE)CanIf_ReadRxNotifStatus(
    VAR(PduIdType ,AUTOMATIC)CanRxPduId)
/* PRQA S 3206 -- */
{
    /*return of the service                                                   */
    VAR(CanIf_NotifStatusType, AUTOMATIC) udtRxNotifStatus 
        = CANIF_NO_NOTIFICATION;
    /* \Trace_To CANIF-CDD-5047(0)                                            */
    /*!#if CanIf_ReadRxNotifStatus is disabled                                */
#if(CanIf_bREAD_RX_NOTIF_API ==STD_OFF)
    /*! Report to the DET (using ANIF_E_NOK_NOSUPPORT) and return E_NOT_OK    */
    CanIf_vidDET_REPORT_ERROR(CanIf_u8RDRXNTIFSTAT_API,CANIF_E_NOK_NOSUPPORT);
#else
    /*!if Development error is enabled                                        */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*!if Canif isnot initialized                                             */
    /* \Trace_To CANIF-CDD-0240(0)                                            */
    /* \Trace_To CANIF-CDD-5048(0)                                            */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report to the DET (using CANIF_E_UNINIT)                          */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8RDRXNTIFSTAT_API,CANIF_E_UNINIT);
    }
    /*!elseif CanRxPduId is out of range                                      */
    /* \Trace_To CANIF-CDD-0239(0)                                            */
    else if(CanRxPduId>=CanIf_udtGET_NUMOFRX_PBCFG)
    {
        /*! Report to the DET (using CANIF_E_INVALID_RXPDUID)                 */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8RDRXNTIFSTAT_API, 
            CANIF_E_INVALID_RXPDUID);
    }
    /*!else                                                                   */
    else
#endif
    {
        /*!if Read notification status is nabled for this CanRxPduId
        and notification status index of Notif Status array is valid          */
        if(CanIf_udtGET_RXPDU_PBCFG[CanRxPduId].bReadNotifyStatus==STD_ON)
        {
            SchM_Enter_CanIf_RxNotifStat_08();
            /*!Copy saved notification status for this CanRxPduId in            
            udtTxNotifStatus local variable                                   */
            udtRxNotifStatus = CanIf_udtGET_RXNOTIF_PBCFG
                [CanIf_udtGET_RXPDU_PBCFG[CanRxPduId].udtNotifyStatusIndex];
        /* \Trace_To CANIF-CDD-0238(0)                                        */
            /*!Reset saved notification status for this CanRxPduId            */
			CanIf_udtGET_RXNOTIF_PBCFG[CanIf_udtGET_RXPDU_PBCFG[CanRxPduId].
                udtNotifyStatusIndex]=CANIF_NO_NOTIFICATION;
            SchM_Exit_CanIf_RxNotifStat_08();
        }
        /*!else                                                               */
        /*!CanIf_IC_2                                                         */
        else
        {
            /*!Return E_NOT_OK                                                */
            /*! Report to the DET (using CANIF_E_INVALID_RXPDUID)             */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
            CanIf_vidDET_REPORT_ERROR(CanIf_u8RDRXNTIFSTAT_API,
                CANIF_E_INVALID_RXPDUID);
#endif
        }
        /*!else Read notification status is disabled for this CanRxPduId
        or notification status index of Notif Status array is invalid         */
    }
    /*!return saved notification status for this CanRxPduId                   */
#endif/*(CanIf_bREAD_RX_NOTIF_API ==STD_OFF)                                  */
    return(udtRxNotifStatus);
}
#endif/*(CanIf_bREAD_RX_NOTIF_API ==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)    */
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)
/******************************************************************************/
/*!\Description : This service provides the CAN DLC and the received data 
                  of the requested CanRxPduId to the calling upper layer.     \n
    \param[in]     CanRxPduId: Receive L-PDU handle of CAN L-PDU. This handle 
                   specifies the corresponding CAN L-PDU ID and implicitly 
                   the CAN Driver instance as well as the corresponding 
                   CAN controller device.                                     \n
    \Range         0..(PbCfg.CanIf_udtNumofRxPdus-1)                          \n
    \param[out]     PduInfoPtr: Pointer to a structure with CAN L-PDU related 
                   data: DLC and pointer to CAN L-SDU buffer                  \n
    \Range         not NULL                                                   \n
    \return        Request for L-PDU data has been accepted or not            \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0190(0)                                      
*******************************************************************************/
/* PRQA S 3206 ++ */
/* MISRA Msg justification: CanRxPduId,PduInfoPtr can't be removed from the function 
		declaration even if it was not used because it is an Autosar service*/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_ReadRxPduData(
    VAR(PduIdType ,AUTOMATIC)CanRxPduId,
    P2VAR(PduInfoType,AUTOMATIC,CANIF_APPL_DATA)PduInfoPtr)
/* PRQA S 3206 -- */
{
    /*the return of the service                                               */
    VAR(uint8 ,AUTOMATIC)                       u8ReturnResult=E_NOT_OK;
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
    /*local copy for the current controller mode                              */
    VAR(CanIf_ControllerModeType ,AUTOMATIC)    udtCurrControllermode;
    /*local copy of pdu channel mode                                          */
    VAR(CanIf_tstrPduMode, AUTOMATIC)           udtLocalTxRxPathPdu;
    /*local variable to be used in copying process                            */
    VAR(uint8_least ,AUTOMATIC)                       u8CopyIndex;
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) pu8DataPtrDst;
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) pu8DataPtrSrc;
	P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC)  pudtSduLenDst;
	P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC)   pudtSduLenSrc;
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
/* PRQA S 3206,8018,8318,8518,8618 ++ */
	P2CONST(CanIf_tstrCriticalSection, AUTOMATIC, AUTOMATIC)
												pkstreRxBuffCriticalSec;
/* PRQA S 3206,8018,8318,8518,8618 ++ */
#endif
#endif
/*!#if CanIf_ReadRxPduData is disabled                                        */
/* \Trace_To CANIF-CDD-5041(0)                                                */
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_OFF)
        /*! Report to the DET (using ANIF_E_NOK_NOSUPPORT) and return E_NOT_OK*/
    CanIf_vidDET_REPORT_ERROR(CanIf_u8READRXDATA_API,CANIF_E_NOK_NOSUPPORT);
#else
/*!if Development error is enabled                                            */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*!if Canif isnot initialized                                             */
    /* \Trace_To CANIF-CDD-0194(0)                                            */
    /* \Trace_To CANIF-CDD-5042(0)                                            */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*!Return E_NOT_OK                                                    */
        /*! Report to the DET (using CANIF_E_UNINIT)                          */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8READRXDATA_API,CANIF_E_UNINIT);
    }
    /*!elseif CanRxPduId is out of range*/
    /* \Trace_To CANIF-CDD-0192(0)*/
    else if(CanRxPduId>=CanIf_udtGET_NUMOFRX_PBCFG)
    {
        /*!Return E_NOT_OK                                                    */
        /*! Report to the DET (using CANIF_E_INVALID_RXPDUID)                 */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8READRXDATA_API,
            CANIF_E_INVALID_RXPDUID);
    }
    /*!else                                                                   */
    /* \Trace_To CANIF-CDD-0193(0)                                            */
    else if(PduInfoPtr==NULL_PTR)
    {
        /*!Return E_NOT_OK                                                    */
        /*! Report to the DET (using CANIF_E_PARAM_POINTER)                   */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8READRXDATA_API,CANIF_E_PARAM_POINTER);
    }
    else
#endif
    {
        if(CanIf_udtGET_RXPDU_PBCFG[CanRxPduId].bRxPduReadData==STD_ON)
        {
            SchM_Enter_CanIf_CurrConMode_06();
            udtCurrControllermode=CanIf_aenueCurrControllerMode
                [CanIf_udtGET_RXPDU_PBCFG[CanRxPduId].u8ControllerId];
            SchM_Exit_CanIf_CurrConMode_06();
            SchM_Enter_CanIf_PduChnlMod_06();
            udtLocalTxRxPathPdu.enuRxPath=CanIf_astreCurrPduChannelMode
                [CanIf_udtGET_RXPDU_PBCFG[CanRxPduId].u8ControllerId].enuRxPath;
            SchM_Exit_CanIf_PduChnlMod_06();
            /* \Trace_To CANIF-CDD-0191(0)                                    */
            /*!if the corresponding CCMSM equal CANIF_CS_STARTED and the channel
            mode is in the receive path online.                               */
            if((udtCurrControllermode==CANIF_CS_STARTED)
                &&(udtLocalTxRxPathPdu.enuRxPath==CanIf_RX_PATH_ONLINE))
            {
                pu8DataPtrDst = PduInfoPtr->SduDataPtr;
				pu8DataPtrSrc = CanIf_udtGET_RXPDU_PBCFG[CanRxPduId].CanIf_pudteRxBufferRefer->SduDataPtr;
				pudtSduLenDst = &(PduInfoPtr->SduLength);
				pudtSduLenSrc = &(CanIf_udtGET_RXPDU_PBCFG[CanRxPduId].CanIf_pudteRxBufferRefer->SduLength);
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
				/*!Copy Data (PayLoad) of buffered message                    */
				pkstreRxBuffCriticalSec = CanIf_udtGET_RXPDU_PBCFG
                    [CanRxPduId].CanIf_pudteSchMExclArea;
				pkstreRxBuffCriticalSec->pfvidEnterCriticalSec();	
#else 
				SchM_Enter_CanIf_CS0010();
#endif
                for(u8CopyIndex=0;u8CopyIndex<(*pudtSduLenSrc);u8CopyIndex++)
                {
                    pu8DataPtrDst[u8CopyIndex] = pu8DataPtrSrc[u8CopyIndex];
                }
                /*!Copy Length of buffered message                            */
                (*pudtSduLenDst) = (*pudtSduLenSrc);
                /*!Return E_OK                                                */
                u8ReturnResult=E_OK;
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
                pkstreRxBuffCriticalSec->pfvidExitCriticalSec();
#else 
				SchM_Exit_CanIf_CS0010();
#endif
            }
            /*!else                                                           */
            /*!Return E_NOT_OK                                                */
            /*!Do Nothing                                                     */
        }
        /*!else                                                               */
        /*!CanIf_IC_1                                                         */
        else
        {
            /*!Return E_NOT_OK                                                */
            /*! Report to the DET (using CANIF_E_INVALID_RXPDUID)             */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
            CanIf_vidDET_REPORT_ERROR(CanIf_u8READRXDATA_API,
                CANIF_E_INVALID_RXPDUID);
#endif
        }
    }
#endif/*(CanIf_bREAD_RX_PDU_DATA_API==STD_OFF)                                */
    /*!Return Result                                                          */
    return(u8ReturnResult);
}
#endif/*(CanIf_bREAD_RX_PDU_DATA_API==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)  */
/******************************************************************************/
/*                           INTERNAL SERVICES                                */
/******************************************************************************/
/******************************************************************************/
/*!\Description : Get the CanIf Hrh using CanDrv HRH reference and CanDrvId   \n
    \param[in]     CanDrvId: the Driver that envoked Rx_Indication            \n
    \Range         0..CanIf_u8NUM_OF_CAN_DRVS-1                               \n
    \param[in]     Hrh: Hard Ware Receive hande of this CanDrvId              \n
    \Range         0..(number of Hrhs assigned to this CanDrvId-1)            \n
    \return        Abstracted CanIf hrh                                       \n
    \Range         0..CanIf_ku16eNumOfHrh-1,(CanIf_u16INVALID_HRH case          
                   searching failed                                           \n
*******************************************************************************/
/* PRQA S 8023,8223,8423 ++ */
LOCAL_INLINE FUNC(uint16, CANIF_CODE)u16GetCanIfHrh(
    VAR(Can_HwHandleType, AUTOMATIC) Hrh,
	VAR(uint8, AUTOMATIC) u8CanDrvId)
/* PRQA S 8023,8223,8423 -- */
{
    /*Local variable to be used in search                                     */
    VAR(uint16, AUTOMATIC) u16SearchIndex;
    /*searching start index                                                   */
    VAR(uint16, AUTOMATIC) u16StartIndex;
    /*searching Stop Index                                                    */
    VAR(uint16, AUTOMATIC) u16StopIndex;
    /*found Hrh(Service Return)                                               */
    VAR(uint16, AUTOMATIC) u16ReturnHrh=CanIf_u16INVALID_HRH;
/* PRQA S 8018,8318,8518 ++ */
	P2CONST(CanIf_tstrHrhPbCfg, AUTOMATIC, AUTOMATIC)
                                pkudtHrhPbCfg=CanIf_udtGET_HRH_PBCFG;
/* PRQA S 8018,8318,8518 -- */
    /*Get Start index Of Hrh for Searching                                    */
    u16StartIndex = CanIf_akstreCanDrvHrhMapLCfg[u8CanDrvId].
        u16HrhListStartindex;
#if(CanIf_bMULTI_DRV_SUPPORT==STD_ON)
    /*!Get  Stop index Of Hrh for Searching                                   */
    /*!if CanDrv is last CanDrv                                               */
    if((u8CanDrvId+1)>=CanIf_u8NUM_OF_CAN_DRVS)
    {
        /*!Stop index equal size of Hrhs                                      */
        u16StopIndex=CanIf_ku16eNumOfHrh;
    }
    /*!else CanDrv is not last CanDrv                                         */
    else
    {
        /*!Stop index equal Start index of Hrh Next CanDrv                    */
        u16StopIndex=CanIf_akstreCanDrvHrhMapLCfg[u8CanDrvId+1].
            u16HrhListStartindex;
    }
#else
    /*!if no more than one Can Drv                                            */
    u16StopIndex=CanIf_ku16eNumOfHrh;
#endif
    u16SearchIndex=u16StartIndex;
    /*!Loop for the Corressponding Hrh                                        */
    while((u16SearchIndex<u16StopIndex)&&(u16ReturnHrh==CanIf_u16INVALID_HRH))
    {
        /*!if hrh is used and Hrh reference eual Hrh input parameter          */
        if((pkudtHrhPbCfg[u16SearchIndex].bHrhUsed==STD_ON)
            &&(pkudtHrhPbCfg[u16SearchIndex].udtCanHrhRef==Hrh))
        {
            /*!return Found Hrh                                               */
            u16ReturnHrh = u16SearchIndex;
        }
        u16SearchIndex++;
    }
    return(u16ReturnHrh);
}
/******************************************************************************/
/*!\Description : Perform Hrh Sw Filtr (Upper Range and Lower Range)          \n
    \param[in]     u16CanIfHrh: CanIf Hrh that message received on            \n
    \Range         0..CanIf_ku16eNumOfHrh-1                                   \n
    \param[in]     CanId: received Can Id after normalization                 \n
    \Range         0..0x7FF Standard, 0..536870911 Extended                   \n
    \param[in]     udtCanIdType: type of received CanId                       \n
    \Range         Standard , Extended                                        \n
    \return        to indicate that hrh Sw Filted passed or failed            \n
    \Range         CanIf_u8HRH_SW_FIL_FAILED, CanIf_u8HRH_SW_FIL_PASSED       \n
*******************************************************************************/
/* PRQA S 4700 ++ */
/*MISRA Msg justification:  searching is complex can't be obtimized           */
/* PRQA S 8023,8223,8423 ++ */
#if(CanIf_bHRH_SW_FILTER==STD_ON)
LOCAL_INLINE FUNC(uint8, CANIF_CODE)u8HrhSwFilter(
    VAR(uint16, AUTOMATIC) u16CanIfHrh,
    VAR(Can_IdType, AUTOMATIC) CanId,
    VAR(CanIf_tenuCanIdType, AUTOMATIC) udtCanIdType)
{
/* PRQA S 8023,8223,8423 -- */
    /*Local variable to be used in search                                     */
    VAR(uint16, AUTOMATIC)  u16SearchIndex;
    /*searching start index                                                   */
    VAR(uint16, AUTOMATIC)  u16StartIndex;
    /*searching Stop index                                                    */
    VAR(uint16, AUTOMATIC)  u16StopIndex=0;
    /*next Hrh                                                                */
    VAR(uint16, AUTOMATIC)  u16NextHrh;
    /*return Result of the search failed or passed                            */
    VAR(uint8, AUTOMATIC)   u8ReturnResult=CanIf_u8HRH_SW_FIL_FAILED;
/* PRQA S 8018,8318,8518 ++ */
	P2CONST(CanIf_tstrHrhPbCfg, AUTOMATIC, CANIF_APPL_CONST)
                                pkudtHrhPbCfg=CanIf_udtGET_HRH_PBCFG;
#if(CanIf_udtSW_FILTER==CanIf_u8LINEAR || CanIf_udtSW_FILTER==CanIf_u8BINARY)
	P2CONST(CanIf_tstrHrhRangePbCfg, AUTOMATIC, CANIF_APPL_CONST)
                              pudteHrhRangePbCfg=CanIf_udtGET_HRHRANGE_PBCFG;
#endif
/* PRQA S 8018,8318,8518 -- */
    /*Get Hrh Sw Range Start Index                                            */
    u16StartIndex = CanIf_udtGET_HRH_PBCFG[u16CanIfHrh].u16CanIdRangeSI;
    /*if hrh is Last Hrh                                                      */
    if(u16CanIfHrh==(CanIf_ku16eNumOfHrh-1))
    {
        /*!Stop Index eual Max Size if Hrh Ranges                             */
        u16StopIndex=CanIf_udtHRH_RANGES_SIZE;
    }
    else
    {
        u16NextHrh=u16CanIfHrh+1;
        /*!loop on Next Hrhs                                                  */
        while(u16NextHrh<CanIf_ku16eNumOfHrh)
        {
            /*!if Next hrh is used                                            */
            if ((pkudtHrhPbCfg[u16NextHrh].bHrhUsed==STD_ON)
                &&(CanIf_akstreHrhLCfg[u16NextHrh].bHrhSwFilter==STD_ON))
            {
                /*!get Hrh Range Index of next Hrh                            */
                u16StopIndex = pkudtHrhPbCfg[u16NextHrh].
                    u16CanIdRangeSI;
                /*!Abort Loop                                                 */
                u16NextHrh = CanIf_ku16eNumOfHrh;
            }
            /*!Get Next Hrh                                                   */
            u16NextHrh++;
        }
    }
    /*!if Previous While Loop is aborted without finding the Hrh Sw Filter      
       Stop Index                                                             */
    if(u16StopIndex==0)
    {
        /*! No Next Hrh is used so Hrh Sw Range Stop Index equal Max Size       
            of Hrh Ranges                                                     */
        u16StopIndex = CanIf_udtHRH_RANGES_SIZE;
    }
    /*!else Previous While Loop is aborted after Successfuly found the Hrh Sw 
       Filter Start Index                                                     */
    /*!Loop on All Ranges assigned to that Hrh                                */
/*******************************************************************************
***********************************LINEAR SEARCH********************************
*******************************************************************************/
#if(CanIf_udtSW_FILTER==CanIf_u8LINEAR)
    u16SearchIndex=u16StartIndex;
    while((u16SearchIndex<u16StopIndex)&&(u8ReturnResult
        !=CanIf_u8HRH_SW_FIL_PASSED))
    {
        /*!if RangeType is the Same as Received CanId                         */
        if(((udtCanIdType==pudteHrhRangePbCfg[u16SearchIndex].
            udtRangeType)
            &&
            /*!and the Received CanId is found in range                       */
            (CanId<= pudteHrhRangePbCfg[u16SearchIndex].udtUpperCanId))
            &&
            (CanId>= pudteHrhRangePbCfg[u16SearchIndex].udtLowerCanId))
        {
            /*Return that Hrh Sw Filter passed                                */
            u8ReturnResult=CanIf_u8HRH_SW_FIL_PASSED;
        }
        u16SearchIndex++;
    }
/*******************************************************************************
***********************************BINARY SEARCH********************************
*******************************************************************************/
#elif(CanIf_udtSW_FILTER==CanIf_u8BINARY)
    u16StopIndex--;
    if((u16StopIndex-u16StartIndex)==0)
    {
        if(((udtCanIdType==CanIf_udtGET_HRHRANGE_PBCFG[u16StartIndex].
            udtRangeType)
            &&
            /*!and the Received CanId is found in range                       */
            (CanId<= CanIf_udtGET_HRHRANGE_PBCFG[u16StartIndex].udtUpperCanId))
            &&
            (CanId>= CanIf_udtGET_HRHRANGE_PBCFG[u16StartIndex].udtLowerCanId))
        {
            /*Return that Hrh Sw Filter passed                                */
            u8ReturnResult=CanIf_u8HRH_SW_FIL_PASSED;
        }
    }
    else if((u16StopIndex-u16StartIndex)==1)
    {
        if(((udtCanIdType==CanIf_udtGET_HRHRANGE_PBCFG[u16StartIndex].
            udtRangeType)
            &&
            /*!and the Received CanId is found in range                       */
            (CanId<= CanIf_udtGET_HRHRANGE_PBCFG[u16StartIndex].udtUpperCanId))
            &&
            (CanId>= CanIf_udtGET_HRHRANGE_PBCFG[u16StartIndex].udtLowerCanId))
        {
            /*Return that Hrh Sw Filter passed                                */
            u8ReturnResult=CanIf_u8HRH_SW_FIL_PASSED;
        }
        else if(((udtCanIdType==CanIf_udtGET_HRHRANGE_PBCFG[u16StopIndex].
            udtRangeType)
            &&
            /*!and the Received CanId is found in range                       */
            (CanId<= CanIf_udtGET_HRHRANGE_PBCFG[u16StopIndex].udtUpperCanId))
            &&
            (CanId>= CanIf_udtGET_HRHRANGE_PBCFG[u16StopIndex].udtLowerCanId))
        {
            /*Return that Hrh Sw Filter passed                                */
            u8ReturnResult=CanIf_u8HRH_SW_FIL_PASSED;
        }
        else
        {
            /*Do Nothing                                                      */
        }
    }
    else
    {
        while((u8ReturnResult!=CanIf_u8HRH_SW_FIL_PASSED)&&(u16StartIndex
            !=u16StopIndex))
        {
            /*!assign middle index                                            */
            /*!check if not last loop to avoid infinite loop                  */
            if((u16StopIndex-u16StartIndex)!=1)
            {
                /*!middle equal Start+Stop/2                                  */
                u16SearchIndex=(uint16)((u16StartIndex+u16StopIndex)/2);
            }
            /*!if last loop                                                   */
            else
            {
    /* PRQA S 3321 ++ */
    /*MISRA Msg justification:  u16SearchIndex is sure set before this point  */
                /*!if search was going downward                               */
                if(u16StartIndex==u16SearchIndex)
                {
    /* PRQA S 3321 -- */
                    /*!search index equal stop index                          */
                    u16SearchIndex=u16StopIndex;
                    /*!start index equal stop to abort next loop              */
                    u16StartIndex=u16StopIndex;

                }
                /*!else:search was going upward                               */
                else
                {
                    /*!search index equal start index                         */
                    u16SearchIndex=u16StartIndex;
                    /*!stop index equal start to abort next loop              */
                    u16StopIndex=u16StartIndex;
                }
            }
            /*!check if CanId found in the correct range and type             */
            if(((udtCanIdType==pudteHrhRangePbCfg[u16SearchIndex].
                udtRangeType)
                &&
                /*!and the Received CanId is found in range                   */
                (CanId<= pudteHrhRangePbCfg[u16SearchIndex].
                udtUpperCanId))
                &&
                (CanId>= pudteHrhRangePbCfg[u16SearchIndex].
                udtLowerCanId))
            {
                /*Return that Hrh Sw Filter passed                            */
                u8ReturnResult=CanIf_u8HRH_SW_FIL_PASSED;
            }
            /*!else if CanId is lower than middle or Configured Range is an     
               Extended Id                                                    */
            else if((CanId<pudteHrhRangePbCfg[u16SearchIndex].
                udtUpperCanId)
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
                ||(pudteHrhRangePbCfg[u16SearchIndex].udtRangeType
                ==CanIf_EXTENDED)
#endif
                )
            {
                /*!search upward                                              */
                u16StopIndex=u16SearchIndex;
            }
            /*!else if CanId is Greater than middle or Configured Range is      
               an Standard Id                                                 */
            else if((CanId>pudteHrhRangePbCfg[u16SearchIndex].
                udtUpperCanId)
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
                ||(pudteHrhRangePbCfg[u16SearchIndex].udtRangeType
                ==CanIf_STANDARD)
#endif
                )
            {
                /*!search downward                                            */
                u16StartIndex=u16SearchIndex;
            }
            else
            {
                /*!do nothing for Misra                                       */
            }
        }
    }
#endif
    /*!return result of Hrh Sw Filter                                         */
    return(u8ReturnResult);
}
#endif
/* PRQA S 4700 -- */
/******************************************************************************/
/*!\Description : This service Search using CanId and And CanId Type to get     
                   RxPduId                                                    \n
    \param[in]     u16CanIfHrh: CanIf Hrh that message received on            \n
    \Range         0..CanIf_ku16eNumOfHrh-1                                   \n
    \param[in]     CanId: received Can Id after normalization                 \n
    \Range         0..0x7FF Standard, 0..536870911 Extended                   \n
    \param[in]     udtCanIdType: type of received CanId                       \n
    \Range         Standard , Extended                                        \n
    \return        found Rxpduid                                              \n
    \Range         0..PbCfg.CanIf_udtNumofRxPdus-1, CanIf_u8INVALID_RXPDU in    
                   case not found                                             \n
*******************************************************************************/
/* PRQA S 4700 ++ */
/*MISRA Msg justification:  Already Internal Services used , If more exec time  
                            will exceeds Normal                               */
/* PRQA S 8023,8223,8423 ++ */
#if (CanIf_noBASIC_CAN_PDU==STD_OFF)
LOCAL_INLINE FUNC(PduIdType, CANIF_CODE)udtSearchRxPdu(
    VAR(uint16, AUTOMATIC)  u16CanIfHrh,
    VAR(Can_IdType, AUTOMATIC) CanId,
    VAR(CanIf_tenuCanIdType, AUTOMATIC) udtCanIdType)
{
/* PRQA S 8023,8223,8423 -- */
    /*Local variable to be used in search                                     */
    VAR(uint16_least, AUTOMATIC)      u16RxMapSearch;
    /*searching start index                                                   */
    VAR(uint16, AUTOMATIC)      u16RxMapStart;
    /*searching stop index                                                    */
    VAR(uint16, AUTOMATIC)      u16RxMapStop=0;
    /*found RxPduId(Service Return)                                           */
    VAR(PduIdType, AUTOMATIC)   udtResultRxPduId=CanIf_u8INVALID_RXPDU;
    /*next Hrh                                                                */
    VAR(uint16, AUTOMATIC)      u16NextHrh;
#if(CanIf_udtSW_FILTER==CanIf_u8LINEAR || CanIf_udtSW_FILTER==CanIf_u8BINARY)
/* PRQA S 8018,8318,8518 ++ */
	P2CONST(CanIf_tstrCanIdRxpduMap, AUTOMATIC, CANIF_APPL_CONST)
                              pudteCanIdRxpduMap=CanIf_udtGET_CANID_RXPDU_MAP;
#endif
	P2CONST(CanIf_tstrHrhPbCfg, AUTOMATIC, CANIF_APPL_CONST)
                              pkudtHrhPbCfg=CanIf_udtGET_HRH_PBCFG;
/* PRQA S 8018,8318,8518 -- */
    /*!get Start Index of RxPduMap of this Hrh                                */
    u16RxMapStart=  CanIf_udtGET_HRH_PBCFG[u16CanIfHrh].u16CanIdRxPduMapSI;
    /*!If Hrh is Last Hrh                                                     */
    if(u16CanIfHrh==(CanIf_ku16eNumOfHrh-1))
    {
        /*!Stop index is Max Size if the whole RxPduMap                       */
        u16RxMapStop=CanIf_udtCANID_RXPDU_SIZE;
    }
    /*!else                                                                   */
    else
    {
        u16NextHrh=u16CanIfHrh+1;
        /*!Loop for All Hrhrs                                                 */
        while(u16NextHrh<CanIf_ku16eNumOfHrh)
        {
            /*!if Hrh is used                                                 */
            if(pkudtHrhPbCfg[u16NextHrh].bHrhUsed==STD_ON)
            {
                /*!Stop Index equal RxPduId Start index of next Hrh           */
                u16RxMapStop = pkudtHrhPbCfg[u16NextHrh].
                    u16CanIdRxPduMapSI;
                /*!abort Loop                                                 */
                u16NextHrh = CanIf_ku16eNumOfHrh;
            }
            /*!Get Next Hrh                                                   */
            u16NextHrh++;
        }
    }
    /*!if Previous While Loop is aborted without finding the Hrh RxPdu          
       Map Start Index                                                        */
    if(u16RxMapStop==0)
    {
        /*!Stop index is Max Size if the whole RxPduMap                       */
        u16RxMapStop = CanIf_udtCANID_RXPDU_SIZE;
    }
    /*!else Previous While Loop is aborted after Successfuly found the Hrh      
    RxPdu Map Start Index                                                     */
    else
    {
        /*!Do nothing Leave Start and stop index of Hrh RxPdu Map Start Index 
        as it is                                                              */
    }
/*******************************************************************************
***********************************LINEAR SEARCH********************************
*******************************************************************************/
#if(CanIf_udtSW_FILTER==CanIf_u8LINEAR)
    /*!Loop For All Ranges of CanIds                                          */
    for(u16RxMapSearch=u16RxMapStart;u16RxMapSearch<u16RxMapStop;
        u16RxMapSearch++)
    {
        /*!if Canid Type is the same and Canid is in the Range                */
        if((
            udtCanIdType==pudteCanIdRxpduMap[u16RxMapSearch].
            udtRxPduCanIdType)
            &&
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
            (CanId<= pudteCanIdRxpduMap[u16RxMapSearch].udtUpperCanId)
            &&
            (CanId>= pudteCanIdRxpduMap[u16RxMapSearch].
            udtLowerCanId))
#else
			(CanId == pudteCanIdRxpduMap[u16RxMapSearch].udtUpperCanId))
#endif
        {
            /*!Return the Corressponding RxPduId                              */
            /* \Trace_To CANIF-CDD-0134(0)                                    */
            udtResultRxPduId=pudteCanIdRxpduMap[u16RxMapSearch].
                udtRxPduId;
        }
        /*!else                                                               */
        else
        {
            /*!Leave udtResultRxPduId=CanIf_u8INVALID_RXPDU;                  */
        }
    }
/*******************************************************************************
***********************************BINARY SEARCH********************************
*******************************************************************************/
#elif(CanIf_udtSW_FILTER==CanIf_u8BINARY)
    u16RxMapStop--;
    
	if( ((u16RxMapStop-u16RxMapStart)==0) || ((u16RxMapStop-u16RxMapStart)==1))
    {
        if((udtCanIdType==CanIf_udtGET_CANID_RXPDU_MAP[u16RxMapStart].
            udtRxPduCanIdType)
            &&
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
            /*!and the Received CanId is found in range                       */
            (CanId<= CanIf_udtGET_CANID_RXPDU_MAP[u16RxMapStart].udtUpperCanId)
            &&
            (CanId >= 
					 CanIf_udtGET_CANID_RXPDU_MAP[u16RxMapStart].udtLowerCanId))
#else
			(CanId == 
			         CanIf_udtGET_CANID_RXPDU_MAP[u16RxMapStart].udtUpperCanId))
#endif
        {
            /*Return RxPduId                                                  */
            udtResultRxPduId=CanIf_udtGET_CANID_RXPDU_MAP[u16RxMapStart].
                udtRxPduId;
        }

        if(((u16RxMapStop-u16RxMapStart)==1) && 
			                        (udtResultRxPduId == CanIf_u8INVALID_RXPDU))
		{
			if((udtCanIdType==CanIf_udtGET_CANID_RXPDU_MAP[u16RxMapStop].
            udtRxPduCanIdType)
            &&
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
            /*!and the Received CanId is found in range                       */
				(CanId <= 
				       CanIf_udtGET_CANID_RXPDU_MAP[u16RxMapStop].udtUpperCanId)
            &&
				(CanId >= 
				      CanIf_udtGET_CANID_RXPDU_MAP[u16RxMapStop].udtLowerCanId))
#else
				(CanId == 
				      CanIf_udtGET_CANID_RXPDU_MAP[u16RxMapStop].udtUpperCanId))
#endif
        {
            /*Return RxPduId                                                  */
            udtResultRxPduId=CanIf_udtGET_CANID_RXPDU_MAP[u16RxMapStop].
                udtRxPduId;
        }
            /*Do Nothing                                                      */
        }
    }
    else
    {
        /*!Loop Till Start Index Equal Stop Index or Loop Aborted             */
        while((udtResultRxPduId==CanIf_u8INVALID_RXPDU)&&( u16RxMapStart
            !=u16RxMapStop))
        {
            /*!Middle Equal (Start+Stop)/2                                    */
            /*!check if not last loop to avoid infinite loop                  */
            if((u16RxMapStop-u16RxMapStart)!=1)
            {
                /*!middle index equal start+stop/2                            */
                u16RxMapSearch=(uint16)((u16RxMapStart+u16RxMapStop)/2);
            }
            /*!else:last loop                                                 */
            else
            {
    /* PRQA S 3321 ++ */
    /*MISRA Msg justification:  u16SearchIndex is sure set before this point  */
                /*!if search was going downward                               */
                if(u16RxMapStart==u16RxMapSearch)
                {
    /* PRQA S 3321 -- */
                    /*!search index equal stop index                          */
                    u16RxMapSearch=u16RxMapStop;
                    /*!abort next loop                                        */
                    u16RxMapStart=u16RxMapStop;
                }
                /*!else:search was going upward                               */
                else
                {
                    /*!search index equal start loop                          */
                    u16RxMapSearch=u16RxMapStart;
                    /*!abotr next loop                                        */
                    u16RxMapStop=u16RxMapStart;
                }
            }
            /*!check if CanId found in the correct range and type             */
            if((udtCanIdType==pudteCanIdRxpduMap[u16RxMapSearch].
                udtRxPduCanIdType)
                &&
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
                /*!and the Received CanId is found in range                   */
                (CanId<= pudteCanIdRxpduMap[u16RxMapSearch].
                udtUpperCanId)
                &&
                (CanId>= pudteCanIdRxpduMap[u16RxMapSearch].
                udtLowerCanId))
#else
			(CanId == pudteCanIdRxpduMap[u16RxMapSearch].udtUpperCanId))
#endif
            {
                /*Return RxPduId                                              */
                udtResultRxPduId=pudteCanIdRxpduMap[u16RxMapSearch].
                    udtRxPduId;
            }
            /*!else if CanId is lower than middle or Configured Range is an 
               Extended Id                                                    */
            else if(CanId<pudteCanIdRxpduMap[u16RxMapSearch].
                udtUpperCanId)
            {
                /*!search upward                                              */
/* PRQA S 3212 ++ */
/*MISRA Msg justification: a cast is needed incase definition of type
										uint16 differs from type uint16_least */
                u16RxMapStop=(uint16)u16RxMapSearch;
/* PRQA S 3212 -- */
            }
            /*!else if CanId is Greater than middle or Configured Range is 
               an Standard Id                                                 */
            else if(CanId>pudteCanIdRxpduMap[u16RxMapSearch].
                udtUpperCanId)
            {
                /*!search downward                                            */
/* PRQA S 3212 ++ */
/*MISRA Msg justification: a cast is needed incase definition of type
										uint16 differs from type uint16_least */
                u16RxMapStart=(uint16)u16RxMapSearch;
/* PRQA S 3212 -- */
            }
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
            else if((udtCanIdType!=pudteCanIdRxpduMap[u16RxMapSearch].
                udtRxPduCanIdType)
                &&
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
                /*!and the Received CanId found in range but not from the same
                 type                                                         */
                (CanId<= pudteCanIdRxpduMap[u16RxMapSearch].
                udtUpperCanId)
                &&
                (CanId>= pudteCanIdRxpduMap[u16RxMapSearch].
                udtLowerCanId))
#else
			(CanId == pudteCanIdRxpduMap[u16RxMapSearch].udtUpperCanId))
#endif
            {
                /*!if type is standard                                        */
                if(pudteCanIdRxpduMap[u16RxMapSearch].
                    udtRxPduCanIdType==CanIf_STANDARD)
                {
                    /*!look for the next element                              */
                    u16RxMapStart=u16RxMapSearch;
                }
                /*!else*/
                else
                {
                    /*!look for the previoud element                          */
                    u16RxMapStop=u16RxMapSearch;
                }
            }
#endif
            /*!else                                                           */
            else
            {
                /*!do nothing just for misra                                  */
            }
        }
    }
#endif
    /*!return RxPduId                                                         */
    return (udtResultRxPduId);
}
#endif	/*CanIf_noBASIC_CAN_PDU*/
/******************************************************************************/
/*!\Description : The CanIf shall accept all L-PDUs with a received DLC value   
                   equal or greater then the configured DLC value.            \n
    \param[in]     u8ReceivedDlc: received Dlc                                \n
    \Range         1..8                                                       \n
    \param[in]     u8ConfiguredDlc: configured Dlc                            \n
    \Range         1..8                                                       \n
    \return        DlcCheck Passed or failed                                  \n
    \Range         CanIf_u8DLC_CHECK_PASSED,CanIf_u8DLC_CHECK_FAILED          \n
*******************************************************************************/
#if(CanIf_bDLC_CHECK==STD_ON)
FUNC(uint8, CANIF_CODE)CanIf_u8CheckDlc(
    VAR(PduLengthType, AUTOMATIC)   udtRxTxDlc,
    VAR(uint8, AUTOMATIC)           u8ConfiguredDlc)
{
    /*the service return Dlc check failed or passed                           */
    VAR(uint8, AUTOMATIC)      u8DlcCheckResult;
    /* \Trace_To CANIF-CDD-0135(0)*/
    /*if received DLC value equal or greater then the configured DLC value.   */
    if(udtRxTxDlc>=u8ConfiguredDlc)
    {
        /*!Dlc Check Passed                                                   */
        u8DlcCheckResult=CanIf_u8DLC_CHECK_PASSED;
    }else
    {
        /*!Dlc Check Failed                                                   */
        u8DlcCheckResult=CanIf_u8DLC_CHECK_FAILED;
    }
    return(u8DlcCheckResult);
}
#endif
/******************************************************************************/
/*!\Description : This service Perform Actual Work Of RxIndication after        
                   RxPduId has been Found successfully                        \n
    \param[in]     udtReceivedRxPduId: received Rxpduid                       \n
    \Range         0..PbCfg.CanIf_udtNumofRxPdus-1                            \n
    \param[in]     u8Length: received Length (Configured or Received)         \n
    \Range         1..8                                                       \n
    \param[in]     pku8CanSduPtr: pointer to pay load                         \n
    \Range         not Null                                                   \n
*******************************************************************************/
/* PRQA S 8023,8223,8423 ++ */
LOCAL_INLINE FUNC(void, CANIF_CODE)vidLocalRxIndication(
    VAR(PduIdType, AUTOMATIC)   udtReceivedRxPduId,
    VAR(uint8, AUTOMATIC)       u8Length,
#if (COMSTACK_coPDU_INFO_TYPE_ADD_CANID == COMSTACK_coENABLE)    
	VAR(Can_IdType, AUTOMATIC)                  udtNormCanId,
#endif
    P2CONST(uint8,AUTOMATIC,CANIF_APPL_CONST)pku8CanSduPtr)
/* PRQA S 8023,8223,8423 -- */
{
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
    /*!local Vaariable to be used in copying process                          */
    VAR(uint8_least ,AUTOMATIC)           u8CopyIndex;
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) pu8DataPtrDst;
#if (COMSTACK_coPDU_INFO_TYPE_ADD_CANID == COMSTACK_coENABLE)
P2VAR(Can_IdType ,AUTOMATIC ,AUTOMATIC) CanIdMOD;
#endif
	P2VAR(PduLengthType ,AUTOMATIC ,AUTOMATIC)  pudtSduLenDst;
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
/* PRQA S 8018,8318,8518 ++ */
	P2CONST(CanIf_tstrCriticalSection ,AUTOMATIC ,AUTOMATIC)
									pkstreRxBuffCriticalSec;
/* PRQA S 8018,8318,8518 -- */
#endif
#endif
    /*! pointer to be passed to UL                                            */
    VAR(PduInfoType, AUTOMATIC)     udtPduInfo;
/* \Trace_To CANIF-CDD-0061(0)                                                */
#if(CanIf_bREAD_RX_PDU_DATA_API==STD_ON)
/*******************************************************************************
***********************************RX BUFFERING*********************************
*******************************************************************************/
    /* \Trace_To CANIF-CDD-0061(0)                                            */
    /*!if buffering is enabled for this RxpduId                               */
    if(CanIf_udtGET_RXPDU_PBCFG[udtReceivedRxPduId].bRxPduReadData==STD_ON)
    {
#if (COMSTACK_coPDU_INFO_TYPE_ADD_CANID == COMSTACK_coENABLE)
	CanIdMOD = &(CanIf_udtGET_RXPDU_PBCFG[udtReceivedRxPduId].CanIf_pudteRxBufferRefer->udtCanId);
#endif
		pu8DataPtrDst = CanIf_udtGET_RXPDU_PBCFG[udtReceivedRxPduId].CanIf_pudteRxBufferRefer->SduDataPtr;
		pudtSduLenDst = &(CanIf_udtGET_RXPDU_PBCFG[udtReceivedRxPduId].CanIf_pudteRxBufferRefer->SduLength);
		
        /* \Trace_To CANIF-CDD-0061(0)                                        */
        /*!loop for Copying data received                                     */
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
		pkstreRxBuffCriticalSec = CanIf_udtGET_RXPDU_PBCFG[udtReceivedRxPduId].CanIf_pudteSchMExclArea;
		pkstreRxBuffCriticalSec->pfvidEnterCriticalSec();
#else 
		SchM_Enter_CanIf_CS0010();
#endif

        for(u8CopyIndex=0;u8CopyIndex<u8Length;u8CopyIndex++)
        {
            /*!Copy data in RxBuffer                                          */
            pu8DataPtrDst[u8CopyIndex]=pku8CanSduPtr[u8CopyIndex];
        }
        /*!copy length in buffer                                              */
        (*pudtSduLenDst) = u8Length;
#if (COMSTACK_coPDU_INFO_TYPE_ADD_CANID == COMSTACK_coENABLE)
     (*CanIdMOD) = udtNormCanId;
#endif
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
        pkstreRxBuffCriticalSec->pfvidExitCriticalSec();
#else 
		SchM_Exit_CanIf_CS0010();
#endif
    }
    /*!else                                                                   */
    else
    {
        /*!Do Nothing                                                         */
    }
#endif
/*******************************************************************************
***********************************RX NOTIFICATION******************************
*******************************************************************************/
/* \Trace_To CANIF-CDD-0312(0)                                                */
#if(CanIf_bREAD_RX_NOTIF_API ==STD_ON)
    /* \Trace_To CANIF-CDD-0312(0)                                            */
    /* \Trace_To CANIF-CDD-0064(0)                                            */
    /*!if Notification Status is enabled                                      */
    if(CanIf_udtGET_RXPDU_PBCFG[udtReceivedRxPduId].bReadNotifyStatus==STD_ON)
    {
        /*!store Notification Status                                          */
        /* \Trace_To CANIF-CDD-0312(0)                                        */
        /* \Trace_To CANIF-CDD-0064(0)                                        */
        SchM_Enter_CanIf_RxNotifStat_14();
        CanIf_udtGET_RXNOTIF_PBCFG[CanIf_udtGET_RXPDU_PBCFG[udtReceivedRxPduId].
            udtNotifyStatusIndex]=CANIF_TX_RX_NOTIFICATION;
        SchM_Exit_CanIf_RxNotifStat_14();
    }
    /*!else                                                                   */
    else
    {
        /*!Do Nothing                                                         */
    }
#endif
/*******************************************************************************
*****************************UPPER LAYER NOTIFICATION***************************
*******************************************************************************/
    /* PRQA S 0311 ++ */
    /*MISRA Msg justification:  Mandatory Interfaces Cn't be changed          */
    udtPduInfo.SduDataPtr=(uint8 *)pku8CanSduPtr;
    /*!Copy sdu Length                                                        */
    udtPduInfo.SduLength=u8Length;
#if (COMSTACK_coPDU_INFO_TYPE_ADD_CANID == COMSTACK_coENABLE)
	udtPduInfo.udtCanId = udtNormCanId;
#endif
    /* PRQA S 0311 -- */
    /*!if Upper layer notification Pointer to function not equal NULL         */
    /* PRQA S 3689 ++ */
    /*MISRA Msg justification:  No Way the UL Name exceeds array Bounds,        
                                Protection done                               */
        /* \Trace_To CANIF-CDD-0358(0)                                        */
        /* \Trace_To CANIF-CDD-0359(0)                                        */
        /* \Trace_TO CANIF-CDD-5028(0)                                        */
		if(CanIf_udtGET_RXPDU_PBCFG[udtReceivedRxPduId].
			CanIf_pudteUlId->pfudtRxIndication!=NULL_PTR)							  
			
        {
            /* \Trace_To CANIF-CDD-0059(0)                                    */
            /* \Trace_To CANIF-CDD-0060(0)                                    */
            /*!Call Upper layer notification Pointer to function              */
			CanIf_udtGET_RXPDU_PBCFG[udtReceivedRxPduId].
                CanIf_pudteUlId->pfudtRxIndication((CanIf_udtGET_RXPDU_PBCFG
                [udtReceivedRxPduId].udtRxPduRef),&udtPduInfo);	
        }
    /* PRQA S 3689 -- */
}

/******************************************************************************/
/*!\Description : normalize the Received CanId (using BIF)from Driver to        
                  CanId and Type(Standard and Extended)                       \n
    \param[out]     pudtCanIdPtr: pointer to normalized CanId(out param)      \n
    \Range         not null                                                   \n
    \param[out]     pudtCanIdTypePtr:  pudtCanIdPtr: pointer to CanId type      
                   (out param)                                                \n
    \Range         not null                                                   \n
    \param[in]     udtCanId: received CanId(Not normalized)                   \n
    \Range         0..0x7FF         0..536870911                                
                   BIF: 0 Standard , 0 Extended                               \n
    \return        Bad or CanId                                               \n
    \Range         CanIf_u8ABORT_RX_INDICATION..CanIf_u8RESUME_RX_INDICATION  \n
*******************************************************************************/
/* PRQA S 8023,8223,8423 ++ */
LOCAL_INLINE FUNC(uint8, CANIF_CODE)u8NormalizeCanId(
                            P2VAR(Can_IdType, AUTOMATIC,CANIF_VAR)pudtCanIdPtr,
                            VAR(Can_IdType, AUTOMATIC)  udtCanId,
							P2VAR(CanIf_tenuCanIdType, AUTOMATIC,CANIF_VAR) 
                            pudtCanIdTypePtr)
/* PRQA S 8023,8223,8423 -- */
{
    /* service return                                                         */
    VAR(uint8,AUTOMATIC)    u8ReceptionStatusRet=CanIf_u8ABORT_RX_INDICATION;
       /*!if CanId bit32 is set                                               */
        /* \Trace_To CANIF-CDD-0314(0)                                        */
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
        if((udtCanId&CanIf_u32CANID_MSB_MASK)==CanIf_u32CANID_MSB_MASK)
        {
            /*!if Bit22 to Bit28 all recessive                                */
            /* \Trace_To CANIF-CDD-0040(0)                                    */
            if((udtCanId&CanIf_u32CANID_EXTENDED_MASK)==
                CanIf_u32CANID_EXTENDED_MASK)
            {
                /* \Trace_To CANIF-CDD-0314(0)                                */
                /*! Report to the DET (using CANIF_E_PARAM_CANID)             */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
                CanIf_vidDET_REPORT_ERROR(CanIf_u8RXINDICAT_API,
                    CANIF_E_PARAM_CANID);
#endif
                /*!Abort RxIndication                                         */
            }
            /*!else                                                           */
            else
            {
                /*!reset BIF before storing CanId                             */
                *(pudtCanIdPtr)=udtCanId&(~CanIf_u32CANID_MSB_MASK);
                /*!set the CanId type                                         */
                /* \Trace_To CANIF-CDD-0040(0)                                */
                *(pudtCanIdTypePtr)=CanIf_EXTENDED;
                /*!Resume RxIndication                                        */
                u8ReceptionStatusRet=CanIf_u8RESUME_RX_INDICATION;
            }
        }
        /*!else                                                               */
        /*!determined type is Standard                                        */
        /* \Trace_To CANIF-CDD-0040(0)                                        */
        else
        {
#endif
            /* \Trace_To CANIF-CDD-0314(0)                                    */
            /*!if less than 0x7ff											  */
            if(udtCanId>CanIf_u32CANID_STANDARD_MASK)
            {
                /* \Trace_To CANIF-CDD-0314(0)                                */
                /*! Report to the DET (using CANIF_E_PARAM_CANID)             */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
                CanIf_vidDET_REPORT_ERROR(CanIf_u8RXINDICAT_API,
                    CANIF_E_PARAM_CANID);
#endif
                /*!Abort RxIndication                                         */
            }
            /*!else                                                           */
            else
            {
                /*!no need to reset BIF before storing CanId                  */
                *(pudtCanIdPtr)=udtCanId;
                /*!set the CanId type                                         */
                /* \Trace_To CANIF-CDD-0040(0)                                */
                *(pudtCanIdTypePtr)=CanIf_STANDARD;
                /*!Resume RxIndication                                        */
                u8ReceptionStatusRet=CanIf_u8RESUME_RX_INDICATION;
            }
#if(CanIf_u8CANIDTYPE==CanIf_u8UINT32)
        }
#endif
        return(u8ReceptionStatusRet);
}

/******************************************************************************/
/*!\Description : This service Perform Hrh Sw Filter and Search the             
                   Corressponding RxPduId                                     \n
    \param[in]     u16CanIfHrh: Hrh that Message received on                  \n
    \Range         0..CanIf_ku16eNumOfHrh-1                                   \n
     \param[in]    udtCanId: received Can Id after normalization              \n
    \Range         0..0x7FF Standard, 0..536870911 Extended                   \n
    \param[in]     udtCanIdType: type of received CanId                       \n
    \Range         Standard , Extended                                        \n
    \return        found Rxpduid                                              \n
    \Range         0..PbCfg.CanIf_udtNumofRxPdus-1, CanIf_u8INVALID_RXPDU       
                  in case not found                                           \n
*******************************************************************************/
/* PRQA S 8023,8223,8423 ++ */
LOCAL_INLINE FUNC(PduIdType, CANIF_CODE)udtGetRxPduId(
    VAR(uint16, AUTOMATIC)  u16CanIfHrh,
    VAR(Can_IdType, AUTOMATIC) udtCanId,
    VAR(CanIf_tenuCanIdType, AUTOMATIC) udtCanIdType)
/* PRQA S 8023,8223,8423 -- */
{
/* PRQA S 3197 ++ */
/* MISRA Msg justification:  The variable must be initialized with a default
                             value to handle some cases where it will not be
							 updated later (under certain pre-processor
							 configuration parameters)                        */	
    /*found RxPduId                                                           */
    VAR(PduIdType, AUTOMATIC) udtRxPduReturn  = CanIf_u8INVALID_RXPDU;
#if(CanIf_bHRH_SW_FILTER==STD_ON)
    /*Hrh Sw Filter result                                                    */
    VAR(uint8, AUTOMATIC)     u8HrhSwFilResult;
#endif
    /* \Trace_To CANIF-CDD-0039(0)                                            */
#if(CanIf_bHRH_SW_FILTER==STD_ON)
    /* \Trace_To CANIF-CDD-0039(0)                                            */
    /*!if Hrh Sw Filteration is enabled for this CanIf Hrh                    */
    if((CanIf_akstreHrhLCfg[u16CanIfHrh].bHrhSwFilter==STD_ON)
        &&(CanIf_akstreHrhLCfg[u16CanIfHrh].enuHandleType==CanIf_BASIC))
    {
        /* \Trace_To CANIF-CDD-0039(0)                                        */
        /*! Start Hrh Sw Filtertion                                           */
        /* PRQA S 3353 ++ */
        /*MISRA Msg justification:  udtAbsoluteCanId and enuCanIdType is sure   
        set before use,prtotected                                             */
        u8HrhSwFilResult=u8HrhSwFilter(u16CanIfHrh,udtCanId,udtCanIdType);
        /* PRQA S 3353 -- */
    }
    /*!else Hrh Sw Filteration is Disabled                                    */
    else
    {
        /*!Hrh Sw Filteration Passed as a default in case it is disabled      */
        u8HrhSwFilResult=CanIf_u8HRH_SW_FIL_PASSED;
    }
    /*!if Hrh Sw Filtertion Passed                                            */
    if(u8HrhSwFilResult==CanIf_u8HRH_SW_FIL_PASSED)
    {
#endif
#if (CanIf_noBASIC_CAN_PDU==STD_OFF)
        /*!if CanIf Hrh is BASIC Can                                          */
        if(CanIf_akstreHrhLCfg[u16CanIfHrh].enuHandleType==CanIf_BASIC)
        {
            /*!Search the Corressponding RxPduId using CanId and CanId Type and 
            CanIf Hrh                                                         */
            /* PRQA S 3353 ++ */
            /*MISRA Msg justification:  udtAbsoluteCanId and enuCanIdType is    
            sure set befor use,prtotected                                     */
            udtRxPduReturn=udtSearchRxPdu(u16CanIfHrh,udtCanId,udtCanIdType);
            /* PRQA S 3353 -- */
        }
        /*!else FULL Can                                                      */
        else
        {
#endif /*CanIf_noBASIC_CAN_PDU*/
            /*!Get RxPduid Directly Without Searching*/
            /*Check CanId type and CanId*/
            if((udtCanIdType==CanIf_udtGET_CANID_RXPDU_MAP
                [CanIf_udtGET_HRH_PBCFG[u16CanIfHrh].
                u16CanIdRxPduMapSI].udtRxPduCanIdType)
                &&
#if (CanIf_bNO_CANID_RANGE == STD_OFF)
                (udtCanId<= CanIf_udtGET_CANID_RXPDU_MAP
                [CanIf_udtGET_HRH_PBCFG[u16CanIfHrh].
                u16CanIdRxPduMapSI].udtUpperCanId)
                &&
                (udtCanId>= CanIf_udtGET_CANID_RXPDU_MAP
                [CanIf_udtGET_HRH_PBCFG[u16CanIfHrh].
                u16CanIdRxPduMapSI].udtLowerCanId))
#else
				(udtCanId== CanIf_udtGET_CANID_RXPDU_MAP
                [CanIf_udtGET_HRH_PBCFG[u16CanIfHrh].
                u16CanIdRxPduMapSI].udtUpperCanId))
#endif
            {
                /*!Get the Corressponding RxPduId                             */
                udtRxPduReturn=CanIf_udtGET_CANID_RXPDU_MAP
                    [CanIf_udtGET_HRH_PBCFG
                    [u16CanIfHrh].u16CanIdRxPduMapSI].udtRxPduId;
            }
            /*!else                                                           */
            else
            {
                udtRxPduReturn=CanIf_u8INVALID_RXPDU;
                /*! udtResultRxPduId=CanIf_u8INVALID_RXPDU;                   */
            }
#if (CanIf_noBASIC_CAN_PDU==STD_OFF)
        }
#endif /*CanIf_noBASIC_CAN_PDU*/
#if(CanIf_bHRH_SW_FILTER==STD_ON)
    }
    /*!else */
    else
    {
        /*!Hrh NotFound                                                       */
        /*!Do Nothing and Abort RxIndication                                  */
    }
#endif
    return(udtRxPduReturn);
/* PRQA S 3197 -- */
}
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */ 
/*--------------------------------End of File---------------------------------*/

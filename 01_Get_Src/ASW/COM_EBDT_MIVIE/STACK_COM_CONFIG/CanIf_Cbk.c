
/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_Cbk                                               */
/*!\file            : CanIf_Cbk.c                                             \n
    \Description    : Responsible for CallBacks related functionalities       */
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
/* $Revision::   1.5      $$Author::   amansour       $$Date::   Nov 02 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/* PRQA S 3453 EOF */
/*MISRA Msg justification:  Function Like Macro is used here although 
                            as it will simplify post-Build configuration 
                            access*/
/* PRQA S 0783,0781 EOF */
/*MISRA Msg justification:  names in Struct may be Repeated in Local Variables*/


/* PRQA S 0838,0863,0862 EOF */
/*MISRA Msg justification:   not included Multi Times QAC Violation*/
#include"CanIf_Cbk.h"
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
#include "Det.h"
#endif

#define CANIF_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/*!\Description : This service indicates a successful reception of a received 
                   CAN Rx L-PDU to the CanIf after passing all filters and 
                   validation checks.                                         \n
    \param[in]     Hrh: ID of the corresponding Hardware Object               \n
    \Range         0..Number of Hrh for Drv0                                  \n
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
    \Trace_To CANIF-CDD-0310(0)                                      
*******************************************************************************/
/*CanIfCtrlDrvCfg-->CanIfCtrlDrvRxIndication*/
#if CanIf_coRX_INDICATION == CanIf_coMIXTE
FUNC(void, CANIF_CODE)CanIf_RxIndication(
    VAR(Can_HwHandleType, AUTOMATIC) Hrh,
    VAR(Can_IdType, AUTOMATIC) CanId,
    VAR(uint8, AUTOMATIC) CanDlc,
    P2CONST(uint8,AUTOMATIC,CANIF_APPL_CONST)CanSduPtr)
{
    /*!if RxIndication is Configured for CanDrv 0*/
    if(CanIf_akstreCtrlDrvLCfg[0].bRxIndication==STD_ON)
    {
        /*!Call General RxIndication*/
        CanIf_vidLocalRxIndic(Hrh,CanId,CanDlc,CanSduPtr,0);
    }
    /*!else*/
    else
    {
#if(CanIf_bDEV_ERR_DETECT==STD_ON)
        /* \Trance_To CANIF-CDD-5082(0)*/
        /*!Report error CANIF_E_NOK_NOSUPPORT*/
        CanIf_vidDET_REPORT_ERROR
                    (CanIf_u8RXINDICAT_API,
                    CANIF_E_NOK_NOSUPPORT);
#endif
    }
}
#endif
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
    \Trace_To CANIF-CDD-0303(0)                                      
*******************************************************************************/
/*CanIfCtrlDrvCfg-->CanIfCtrlDrvTxConfirmation*/
FUNC(void, CANIF_CODE)CanIf_TxConfirmation(
            VAR(PduIdType ,AUTOMATIC)CanTxPduId)
{
    /*! if Tx_Confirmation for Drv0 is supported*/
    if(CanIf_akstreCtrlDrvLCfg[0].bTxConfirmation==STD_ON)
    {
        /* \Call General Tx_Confirmation*/
        CanIf_vidLocalTxConf(CanTxPduId);
    }
    /*!else*/
    else
    {
#if(CanIf_bDEV_ERR_DETECT==STD_ON)
        /* \Trace_To CANIF-CDD-5076(0)*/
        /*!Report error CANIF_E_NOK_NOSUPPORT*/
        CanIf_vidDET_REPORT_ERROR(
            CanIf_u8TXCONF_API,
            CANIF_E_NOK_NOSUPPORT);
#endif

    }
}
/*CanIfCtrlDrvCfg-->CanIfCtrlDrvTxCancellation*/
#if(((CanIf_bTX_BUFFERING==STD_ON)&&(CanIf_bCTRLDRV_0_TX_CANCEL==STD_ON))\
        ||(CanIf_bDEV_ERR_DETECT==STD_ON))
/******************************************************************************/
/*!\Description : This service confirms a previously successfully performed 
                   cancellation of a pending Tx L-PDU transmit request.       \n
    \param[in]     PduInfoPtr: Pointer to a structure with CAN L-PDU related 
                   data: L-PDU handle of the successfully aborted CAN L-SDU, 
                   CAN identifier, DLC and pointer to CAN L-SDU buffer.
                   , this service is implemented for Can Drv 0                \n
    \Range         not null                                                   \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
    \Trace_To CANIF-CDD-0321(0)                                      
*******************************************************************************/
/* PRQA S 3206 ++ */
/* MISRA Msg justification: PduInfoPtr can't be removed from the function 
declaration even if it was not used because it is an Autosar service*/
FUNC(void, CANIF_CODE)CanIf_CancelTxConfirmation(
    P2CONST(Can_PduType,AUTOMATIC,CANIF_APPL_CONST)PduInfoPtr)
/* PRQA S 3206 -- */
{
#if(CanIf_bCTRLDRV_0_TX_CANCEL==STD_OFF||(CanIf_bTX_BUFFERING==STD_OFF))
    /*!Report error CANIF_E_NOK_NOSUPPORT*/
    /* \Trace_To CANIF-CDD-5085(0)*/
    CanIf_vidDET_REPORT_ERROR(
            CanIf_u8CANCELTXCONF_API,
            CANIF_E_NOK_NOSUPPORT);
#else
    /*!Call general CancelTxConfirmation*/
    CanIf_vidLocalCancelTxConf(PduInfoPtr);
#endif
}
#endif
/******************************************************************************/
/*!\Description : This service indicates a Controller BusOff event 
                   referring to the corresponding CAN Controller it is 
                   implemented for DrvId 0 .                                  \n
    \param[in]     Controller:  CAN controllerId, which state has been 
                   transitioned.                                              \n
    \Range         Maximum Number of Controller assigned to that CanDrvId(0)  \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
    \Trace_To CANIF-CDD-0327(0)                                      
*******************************************************************************/
/*Can't be disabled for Can Drv*/
FUNC(void, CANIF_CODE)CanIf_ControllerBusOff(
     VAR(uint8, AUTOMATIC) ControllerId)
{
    CanIf_vidLocalCntrlBusOff(ControllerId,0);
}
/******************************************************************************/
/*!\Description : This service indicates a controller state transition 
                   referring to the corresponding CAN controller.             \n
    \param[in]     Controller:  CAN controller, which state has been 
                   transitioned.                                              \n
    \Range         Maximum Number of Controlers assigned to that Driver 0     \n
    \param[in]     ControllerMode:  Mode to which the CAN controller 
                   transitioned                                               \n
    \Range         CANIF_CS_SLEEP,CANIF_CS_STARTED,CANIF_CS_STOPPED           \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
    \Trace_To CANIF-CDD-0333(0)                                                 
*******************************************************************************/
/*Can't be disabled for Can Drv*/
FUNC(void, CANIF_CODE)CanIf_ControllerModeIndication(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(CanIf_ControllerModeType, AUTOMATIC) ControllerMode)
{
    CanIf_vidCntrlModeIndic(ControllerId,ControllerMode,0);
}

#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
          

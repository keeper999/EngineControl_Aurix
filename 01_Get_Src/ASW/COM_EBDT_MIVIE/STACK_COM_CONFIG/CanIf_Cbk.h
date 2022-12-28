
/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_Cbk                                               */
/*!\file            : CanIf_Cbk.h                                             \n
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
/* $Revision::   1.3      $$Author::   amansour       $$Date::   Oct 18 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
#ifndef CANIF_CBK_H
#define CANIF_CBK_H

#include"CanIf.h"
#include "CanIf_LocalCfg.h"
#include "CanIf_LocalLCfg.h"
#include "CanIf_PBCfg.h"
#include"CanIf_Reception.h"
#include "CanIf_General.h"
#include"CanIf_Transmission.h"
#include"CanIf_ModeHandler.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* !\Function    : CanIf_RxIndication                                         \n
   !\Description : This service indicates a successful reception of a received 
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
*******************************************************************************/
/*CanIfCtrlDrvCfg-->CanIfCtrlDrvRxIndication*/
#if CanIf_coRX_INDICATION == STD_ON
#define CanIf_RxIndication(Hrh,CanId,CanDlc,CanSduPtr)  CanIf_vidLocalRxIndic((Hrh),(CanId),(CanDlc),(CanSduPtr),(0))
#elif CanIf_coRX_INDICATION == STD_OFF && CanIf_bDEV_ERR_DETECT==STD_ON
#define CanIf_RxIndication(Hrh,CanId,CanDlc,CanSduPtr)  CanIf_vidDET_REPORT_ERROR(CanIf_u8RXINDICAT_API,CANIF_E_NOK_NOSUPPORT)
#elif CanIf_coRX_INDICATION == STD_OFF && CanIf_bDEV_ERR_DETECT==STD_OFF
#define CanIf_RxIndication(Hrh,CanId,CanDlc,CanSduPtr)
#else
extern FUNC(void, CANIF_CODE)CanIf_RxIndication(
    VAR(Can_HwHandleType, AUTOMATIC) Hrh,
    VAR(Can_IdType, AUTOMATIC) CanId,
    VAR(uint8, AUTOMATIC) CanDlc,
    P2CONST(uint8,AUTOMATIC,CANIF_APPL_CONST)CanSduPtr);
#endif

/******************************************************************************/
/* !\Function    : CanIf_TxConfirmation                                       \n
   !\Description : This service confirms a previously successfully processed 
                   transmission of a CAN TxPDU.                               \n
    \param[in]     CanTxPduId: L-PDU handle of CAN L-PDU to be transmitted.
                   This handle specifies the corresponding CAN L-PDU ID and
                   implicitly the CAN Driver instance as well as the
                   corresponding CAN controller device.                       \n
    \Range         0..PbCfg.CanIf_udtNumofTxPdus-1                            \n
    \return        void                                                       \n
    \Range         n/A                                                        \n
*******************************************************************************/
/*CanIfCtrlDrvCfg-->CanIfCtrlDrvTxConfirmation*/
FUNC(void, CANIF_CODE)CanIf_TxConfirmation(
            VAR(PduIdType ,AUTOMATIC)CanTxPduId);
/******************************************************************************/
/* !\Function    : CanIf_CancelTxConfirmation                                 \n
   !\Description : This service confirms a previously successfully performed 
                   cancellation of a pending Tx L-PDU transmit request.       \n
    \param[in]     PduInfoPtr: Pointer to a structure with CAN L-PDU related 
                   data: L-PDU handle of the successfully aborted CAN L-SDU, 
                   CAN identifier, DLC and pointer to CAN L-SDU buffer.
                   , this service is implemented for Can Drv 0                \n
    \Range         not null                                                   \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
/*CanIfCtrlDrvCfg-->CanIfCtrlDrvTxCancellation*/
#if(((CanIf_bTX_BUFFERING==STD_ON)&&(CanIf_bCTRLDRV_0_TX_CANCEL==STD_ON))\
            ||(CanIf_bDEV_ERR_DETECT==STD_ON))
FUNC(void, CANIF_CODE)CanIf_CancelTxConfirmation(
    P2CONST(Can_PduType,AUTOMATIC,CANIF_APPL_CONST)PduInfoPtr);
#endif
/******************************************************************************/
/* !\Function    : CanIf_ControllerBusOff                                     \n
   !\Description : This service indicates a Controller BusOff event 
                   referring to the corresponding CAN Controller it is 
                   implemented for DrvId 0 .                                  \n
    \param[in]     Controller:  CAN controllerId, which state has been 
                   transitioned.                                              \n
    \Range         Maximum Number of Controllers assigned to that CanDrvId(0) \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
/*Can't be disabled for Can Drv*/
FUNC(void, CANIF_CODE)CanIf_ControllerBusOff(
     VAR(uint8, AUTOMATIC) ControllerId);
/******************************************************************************/
/* !\Function    : CanIf_ControllerModeIndication_CanIf  \n
   !\Description : This service indicates a controller state transition 
                   referring to the corresponding CAN controller.             \n
    \param[in]     Controller:  CAN controllerId, which state has been 
                   transitioned.                                              \n
    \Range         Maximum Number of Controlers assigned to that Driver 0     \n
    \param[in]     ControllerMode:  Mode to which the CAN controller 
                   transitioned                                               \n
    \Range         CANIF_CS_SLEEP,CANIF_CS_STARTED,CANIF_CS_STOPPED           \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
/*Can't be disabled for Can Drv*/
FUNC(void, CANIF_CODE)CanIf_ControllerModeIndication(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(CanIf_ControllerModeType, AUTOMATIC) ControllerMode);

#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
/*--------------------------------END OF FILE---------------------------*/
#endif
          

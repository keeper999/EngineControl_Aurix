/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of            
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_Transmission                                      */
/*!\file            : CanIf_Transmission.h                                    \n
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
/* $Revision::   1.10     $$Author::   AELSOHBY       $$Date::   Jun 25 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
#ifndef CANIF_TRANSMISSION_H
#define CANIF_TRANSMISSION_H

/* PRQA S 3410 ++ */
/*MISRA Msg justification:  adding brackets results compilation error           
                            as parameters are Struct elements                 */
/* PRQA S 3453 ++ */
/*MISRA Msg justification:  Function Like Macro is used here although           
                            as it will simplify post-Build configuration        
                            access                                            */
/******************************************************************************/
/*!  \Description Getting TxPdu Configuration from PB Configuration             
*******************************************************************************/
#define CanIf_udtGET_TXPDU_PBCFG    \
            (CanIf_pkstreConfigPtr->CanIf_pudtTxPduPbCfg)
/******************************************************************************/
/*!  \Description Getting TxPdu buffer from PB Configuration                    
*******************************************************************************/
#define CanIf_udtGET_TXBUFF_PBCFG   \
            (CanIf_pkstreConfigPtr->pudtTxPduBuffer)
/******************************************************************************/
/*!  \Description Getting Size of TxPdu from PB Configuration                   
*******************************************************************************/
#define CanIf_udtGET_NUMOFTX_PBCFG              \
            (CanIf_pkstreConfigPtr->CanIf_udtNumofTxPdus)
/******************************************************************************/
/*!  \Description Getting Size of dynamic TxPdu from PB Configuration           
*******************************************************************************/
#define CanIf_udtGET_NUMOFDYTX_PBCFG            \
            (CanIf_pkstreConfigPtr->CanIf_udtSizeOfDynamicTxPdus)
/******************************************************************************/
/*!  \Description Getting dynamic TxPdu from PB Configuration                   
*******************************************************************************/
#define CanIf_udtGET_DYCANID_PBCFG              \
            (CanIf_pkstreConfigPtr->pudtDynamicTxPduCanId)
/******************************************************************************/
/*!  \Description Getting TxPdu notification status PB Configuration            
*******************************************************************************/
#define CanIf_udtGET_TXNOTIF_PBCFG              \
            (CanIf_pkstreConfigPtr->penuTxNotifStatus)
/******************************************************************************/
/*!  \Description Getting size of TxPdus notification status PB Configuration   
*******************************************************************************/
#define CanIf_udtNUMOFTXNOTI_PBCFG              \
            (CanIf_pkstreConfigPtr->CanIf_udtSizeOfTxNotifStatus)
/******************************************************************************/
/*!  \Description Getting Hth Pb Configuration from PB Configuration            
*******************************************************************************/
#define CanIf_udtGET_HTHTXPDU_PBCFG             \
            (CanIf_pkstreConfigPtr->CanIf_pudtHthTxPduCfg)
/******************************************************************************/
/*!  \Description Getting TxPduMapping Configuration from PB Configuration             
*******************************************************************************/
#define CanIf_udtGET_TXPDU_MAP_PBCFG    \
            (CanIf_pkstreConfigPtr->CanIf_pku16TxPduMappingPbCfg)
/* PRQA S 3453 -- */
/* PRQA S 3410 -- */

/******************************************************************************/
/*                                  DEFINES                                   */
/******************************************************************************/

#define CANIF_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* !\Function    : CanIf_vidClearTxConfirmState                               \n
   !\Description : This service Clear TxConfirmation State for ControllerId   \n
    \param[in]     u8ControllerId: the contreoller Id that its                  
                   Tx Confirmation state will be cleared                      \n
    \Range         0..PbCfg.CanIf_ku8eNumOfControllers-1                      \n
    \return        void                                                       \n
    \Range         n/A                                                        \n
*******************************************************************************/
#if (CanIf_bTXCONF_POLL_SUPPORT == STD_ON)
extern FUNC(void, CANIF_CODE)CanIf_vidClearTxConfirmState(uint8 u8ControllerId);
#endif
/******************************************************************************/
/* !\Function    : CanIf_vidClearTransmitBuffers                              \n
   !\Description : This service Clear TxPdus Buffers for ControllerId         \n
    \param[in]     u8ControllerId: the controller that all TxPdus buffers
                   assigned to will be cleared                                \n
    \Range         0..PbCfg.CanIf_ku8eNumOfControllers-1                      \n
    \return        void                                                       \n
    \Range         n/A                                                        \n
*******************************************************************************/
#if(CanIf_bTX_BUFFERING==STD_ON)
extern FUNC(void, CANIF_CODE)CanIf_vidClearTransmitBuffers
                (uint8 u8ControllerId);
#endif
/******************************************************************************/
/* !\Function    : CanIf_vidLocalTxConf                                       \n
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
extern FUNC(void, CANIF_CODE)CanIf_vidLocalTxConf(
            VAR(PduIdType ,AUTOMATIC)CanTxPduId);
/******************************************************************************/
/* !\Function    : CanIf_vidLocalCancelTxConf                                 \n
   !\Description : This service confirms a previously successfully performed    
                   cancellation of a pending Tx L-PDU transmit request.       \n
    \param[in]     PduInfoPtr: Pointer to a structure with CAN L-PDU related    
                   data: L-PDU handle of the successfully aborted CAN L-SDU,    
                   CAN identifier, DLC and pointer to CAN L-SDU buffer.       \n
    \Range         not null                                                   \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
#if(CanIf_bTX_BUFFERING==STD_ON)
extern FUNC(void, CANIF_CODE)CanIf_vidLocalCancelTxConf(
    P2CONST(Can_PduType,AUTOMATIC,CANIF_APPL_CONST)PduInfoPtr);
#endif
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

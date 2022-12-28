/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of            
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_Reception                                         */
/*!\file            : CanIf_Reception.h                                       \n
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
/* $Revision::   1.7      $$Author::   mamroussy      $$Date::   Jul 11 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
#ifndef CANIF_RECEPTION_H
#define CANIF_RECEPTION_H

/* PRQA S 3410 ++ */
/*MISRA Msg justification:  adding brackets results compilation error           
                            as parameters are Struct elements                 */
/* PRQA S 3453 ++ */
/*MISRA Msg justification:  Function Like Macro is used here although           
                            as it will simplify post-Build configuration        
                            access                                            */
/******************************************************************************/
/*!  \Description Getting Size Of RxPdus  from PB Configuration                 
*******************************************************************************/
#define CanIf_udtGET_NUMOFRX_PBCFG                      \
            (CanIf_pkstreConfigPtr->CanIf_udtNumofRxPdus)
/******************************************************************************/
/*!  \Description Getting Size of Rx Notification Status from PB Configuration  
*******************************************************************************/
#define CanIf_udtNUMOFRXNOTI_PBCFG                      \
            (CanIf_pkstreConfigPtr->CanIf_pkudtSizeOfRxNotifStatus)
/******************************************************************************/
/*!  \Description Getting Size of Hrh Ranges from PB Configuration              
*******************************************************************************/
#define CanIf_udtHRH_RANGES_SIZE                        \
            (CanIf_pkstreConfigPtr->CanIf_ku16SizeOfHrhRanges)
/******************************************************************************/
/*!  \Description Getting Size of RxPduId , CanId Map from PB Configuration     
*******************************************************************************/
#define CanIf_udtCANID_RXPDU_SIZE                       \
            (CanIf_pkstreConfigPtr->CanIf_ku16SizeOfCanIdRxPduMap)
/******************************************************************************/
/*!  \Description Getting Size of RxPdu buffers from PB Configuration           
*******************************************************************************/
#define CanIf_udtRX_BUFFER_SIZE                         \
            (CanIf_pkstreConfigPtr->CanIf_pkudtSizeOfRxBuffer)
/******************************************************************************/
/*!  \Description Getting Hrhs Configuration from PB Configuration              
*******************************************************************************/
#define CanIf_udtGET_HRH_PBCFG              \
            CanIf_pkstreConfigPtr->CanIf_pkudtHrhPbCfg
/******************************************************************************/
/*!  \Description Getting RxPdus Configuration from PB Configuration            
*******************************************************************************/
#define CanIf_udtGET_RXPDU_PBCFG            \
            (CanIf_pkstreConfigPtr->CanIf_pudteRxPduPbCfg)
/******************************************************************************/
/*!  \Description Getting Hrh Ranges Configuration from PB Configuration        
*******************************************************************************/
#define CanIf_udtGET_HRHRANGE_PBCFG         \
            CanIf_pkstreConfigPtr->CanIf_pudteHrhRangePbCfg
/******************************************************************************/
/*!  \Description Getting RxPduId CanId Map Configuration from PB Configuration 
*******************************************************************************/
#define CanIf_udtGET_CANID_RXPDU_MAP        \
            CanIf_pkstreConfigPtr->CanIf_pudteCanIdRxpduMap
/******************************************************************************/
/*!  \Description Getting RxPdu buffer from PB Configuration                    
*******************************************************************************/
#define CanIf_udtGET_RXBUFF_PBCFG           \
            CanIf_pkstreConfigPtr->pudtRxbuffer
/******************************************************************************/
/*!  \Description Getting RxPdu notification Status from PB Configuration       
*******************************************************************************/
#define CanIf_udtGET_RXNOTIF_PBCFG                       \
            CanIf_pkstreConfigPtr->penuRxNotifStatus
/* PRQA S 3453 -- */
/* PRQA S 3410 -- */
#define CANIF_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************/
/* !\Function    : CanIf_vidLocalRxIndic                                      \n
   !\Description : This service indicates a successful reception of a received  
                   CAN Rx L-PDU to the CanIf after passing all filters and      
                   validation checks.                                         \n
    \param[in]     Hrh: ID of the corresponding Hardware Object               \n
    \Range         0..(CanIf_ku16eNumOfHrh -1)                                \n
    \param[in]     CanId: Standard/Extended CAN ID of CAN L-PDU that            
                          has been successfully received                      \n
    \Range         0..0x7FF Standard    0..536870911 Extended                   
                   BIF: 0 Standard , 1 Extended                               \n
    \param[in]     CanDlc: Data Length Code (length of CAN L-PDU payload)     \n
    \Range         1..8                                                       \n
    \param[in]     CanSduPtr: Pointer to received L-SDU (payload)             \n
    \Range         Not Null                                                   \n
	\param[in]     CanDrvId: Can Drriver                                      \n
    \Range         0..CanIf_u8NUM_OF_CAN_DRVS-1                               \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
extern FUNC(void, CANIF_CODE)CanIf_vidLocalRxIndic(
    VAR(Can_HwHandleType, AUTOMATIC) Hrh,
    VAR(Can_IdType, AUTOMATIC) CanId,
    VAR(uint8, AUTOMATIC) CanDlc,
    P2CONST(uint8,AUTOMATIC,CANIF_APPL_CONST)CanSduPtr,
	VAR(uint8, AUTOMATIC) CanDrvId);
/******************************************************************************/
/* !\Function    : CanIf_u8CheckDlc                                           \n
   !\Description : The CanIf shall accept all L-PDUs with a received DLC value  
                   equal or greater then the configured DLC value.            \n
    \param[in]     u8ReceivedDlc: received Dlc                                \n
    \Range         1..8                                                       \n
    \param[in]     u8ConfiguredDlc: configured Dlc                            \n
    \Range         1..8                                                       \n
    \return        DlcCheck Passed or failed                                  \n
    \Range         CanIf_u8DLC_CHECK_PASSED,CanIf_u8DLC_CHECK_FAILED          \n
*******************************************************************************/
#if(CanIf_bDLC_CHECK==STD_ON)
extern FUNC(uint8, CANIF_CODE)CanIf_u8CheckDlc(
    VAR(PduLengthType, AUTOMATIC)   udtRxTxDlc,
    VAR(uint8, AUTOMATIC)   u8ConfiguredDlc);
#endif
/*---------------------------------End Of File----------------------------*/
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : CanTp                                                   */
/* !Description     : CanTp is the component between the PDU Router and the   */
/*                    CAN Interface module. The main purpose of the CanTp     */
/*                    component is to segment and reassemble CAN I-PDUs longer*/
/*                    than 8 bytes                                            */
/*                                                                            */
/* !File            : CanTp_Cbk.h                                             */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/19_CanTp/0$*/
/* $Revision::   1.0      $$Author::   madel          $$Date::   Nov 22 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp_Cbk.h
*
* \par
*   This file contains the callbacks exported by the CanTp Module to the lower
    layer                                                                     */
/******************************************************************************/
#ifndef CANTP_CBK_H
#define CANTP_CBK_H


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define CANTP_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/*! \Description    This function is called by the lower layer module to      
                    confirm the transmission of an NPDU                       \n
    \param[in]      TxPduId         Confirmation ID of the transmitted NPDU   \n
                    \Range          0 .. CanTp_u16NUM_OF_TX_PDU_IDS-1         \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_TxConfirmation(
    VAR(PduIdType,AUTOMATIC) TxPduId );


/******************************************************************************/
/*! \Description    This function indicates the reception of an NPDU from     
                    a lower layer communication module                        \n
    \param[in]      RxPduId         ID of the received NPDU                   \n
                    \Range          0 .. CanTp_u16NUM_OF_RX_PDU_IDS-1         \n
    \param[in]      PduInfoPtr      A pointer to a structure that contains the
                                    received data and its length              \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_RxIndication(
    VAR(PduIdType, AUTOMATIC)                       RxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)  PduInfoPtr);

#define CANTP_STOP_SEC_CODE
#include "MemMap.h"


#endif /* CANTP_CBK_H */

/*-------------------------------- end of file -------------------------------*/

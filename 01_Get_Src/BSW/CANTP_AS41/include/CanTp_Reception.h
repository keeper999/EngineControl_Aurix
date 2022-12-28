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
/* !File            : CanTp_Reception.h                                       */
/*                                                                            */
/* !Scope           : PrivateComponent                                        */
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
/* $Revision::   1.2      $$Author::   AELSOHBY       $$Date::   Mar 31 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp_Reception.h
*
* \par
*   This file contains the services exported by the Reception sub-component, 
    to be used by the Main sub-component                                      */
/******************************************************************************/
#ifndef CANTP_RECEPTION_H
#define CANTP_RECEPTION_H

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define CANTP_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/*! \Description    This function performs the periodic handling of the
                    reception operation on a certain CanTpConnection          \n
    \param[in/out]  pstrChannelResources    Pointer to the CanTpConnection 
                                            resources at which the reception
                                            operation is taking place         \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidManageRxState (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function handles the actions that need to be taken in 
                    case a timeout occurs while a reception operation is  
                    taking place                                              \n
    \param[in/out]  pstrChannelResources    Pointer to the CanTpConnection 
                                            resources at which the reception
                                            operation is taking place         \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidHandleRxTimeout (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function is called when a single frame or a first frame
                    is received to check whether the new reception can be 
                    handled or not                                            \n
    \param[in]      pudtPduInfoPtr          A pointer to a structure that
                                            contains the received data and its
                                            length                            \n
    \param[in]      udtRxNSduId             CanTpRxNSduId whose frame was
                                            received                          \n
    \param[in/out]  pstrChannelResources    Pointer to the CanTpConnection 
                                            resources at which the reception
                                            operation is taking place         \n
    \return         Handling new reception check:                             \n
                    TRUE:                   The new reception can be handled  \n
                    FALSE:                  The new reception can't be handled\n
*******************************************************************************/
extern FUNC(boolean, CANTP_CODE) CanTp_bHandleNewReception (
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)        pudtPduInfoPtr,
    VAR(PduIdType, AUTOMATIC)                             udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function is called to handle the reception of a single
                    frame                                                     \n
    \param[in]      pudtPduInfoPtr          A pointer to a structure that
                                            contains the received data and its
                                            length                            \n
    \param[in]      udtRxNSduId             CanTpRxNSduId whose frame was
                                            received                          \n
    \param[in/out]  pstrChannelResources    Pointer to the CanTpConnection 
                                            resources at which the reception
                                            operation is taking place         \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidHandleSingleFrame (
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)        pudtPduInfoPtr,
    VAR(PduIdType, AUTOMATIC)                             udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function is called to handle the reception of a first
                    frame                                                     \n
    \param[in]      pudtPduInfoPtr          A pointer to a structure that
                                            contains the received data and its
                                            length                            \n
    \param[in]      udtRxNSduId             CanTpRxNSduId whose frame was
                                            received                          \n
    \param[in/out]  pstrChannelResources    Pointer to the CanTpConnection 
                                            resources at which the reception
                                            operation is taking place         \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidHandleFirstFrame (
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)        pudtPduInfoPtr,
    VAR(PduIdType, AUTOMATIC)                             udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function is called to handle the reception of a 
                    consecutive frame                                         \n
    \param[in]      pudtPduInfoPtr          A pointer to a structure that
                                            contains the received data and its
                                            length                            \n
    \param[in]      udtRxNSduId             CanTpRxNSduId whose frame was
                                            received                          \n
    \param[in/out]  pstrChannelResources    Pointer to the CanTpConnection 
                                            resources at which the reception
                                            operation is taking place         \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidHandleConsecFrame (
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)        pudtPduInfoPtr,
    VAR(PduIdType, AUTOMATIC)                             udtRxNSduId,
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function performs the actions that need to be taken in
                    case a flow control transmission confirmation was received\n
    \param[in]      udtNSduId               CanTpRxNSduId whose flow control
                                            transmission confirmation was 
                                            receieved                         \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidConfHandlerRx (
    VAR(PduIdType, AUTOMATIC) udtNSduId);

#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANTP_RECEPTION_H */

/*-------------------------------- end of file -------------------------------*/
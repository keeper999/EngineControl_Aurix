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
/* !File            : CanTp_Transmission.h                                    */
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
/* $Revision::   1.3      $$Author::   AELSOHBY       $$Date::   Mar 31 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp_Transmission.h
*
* \par
*   This file contains the services exported by the Transmission sub-component, 
    to be used by the Main sub-component                                      */
/******************************************************************************/
#ifndef CANTP_TRANSMISSION_H
#define CANTP_TRANSMISSION_H

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define CANTP_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/*! \Description    This function performs the periodic handling of the
                    transmission operation on a certain CanTpConnection       \n
    \param[in/out]  pstrChannelResources    Pointer to the CanTpConnection 
                                            resources at which the
                                            transmission operation is taking
                                            place                             \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidManageTxState (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function handles the actions that need to be taken in 
                    case a timeout occurs while a transmission operation is  
                    taking place                                              \n
    \param[in/out]  pstrChannelResources    Pointer to the CanTpConnection 
                                            resources at which the
                                            transmission operation is taking
                                            place                             \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidHandleTxTimeout (
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                                          pudtChannelResources);


/******************************************************************************/
/*! \Description    This function stores the received flow control in the local
                    buffer in order to be hanlded in the next main function   \n
    \param[in]      udtTxNSduId             CanTpTxNSduId whose flow control 
                                            frame was received                \n
    \param[in]      pkudtPduInfoPtr         A pointer to a structure that
                                            contains the received frame and its
                                            length                            \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidStoreFCFrame (
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)pkudtPduInfoPtr,
	VAR(PduIdType, AUTOMATIC) udtTxNSduId);


/******************************************************************************/
/*! \Description    This function performs the actions that need to be taken in
                    case a transmission confirmation was received             \n
    \param[in]      udtNSduId               CanTpTxNSduId whose transmission
                                            confirmation was receieved        \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_vidConfHandlerTx (
    VAR(PduIdType, AUTOMATIC) udtNSduId);

#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANTP_TRANSMISSION_H */

/*-------------------------------- end of file -------------------------------*/
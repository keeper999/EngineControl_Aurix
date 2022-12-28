/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined CANSM_COMM_H)
#define CANSM_COMM_H
/*==================[inclusions]============================================*/

#include <ComStack_Types.h>    /* AUTOSAR communication stack types */
/*WORKAROUND OF JIRA TICKET "VALEO-ASR4-COMPANY-BUYOUT-223"*/
#include <CanSM_Version.h>     /* this module's version declaration */
#include <ComM.h>              /* Communication Manager's types */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function declarations]========================*/

#define CANSM_START_SEC_CODE
#include <MemMap.h>

/** \brief Request a change of the communication mode of a CAN network.
 **
 ** This service changes the communication mode of a CAN network to the requested one.
 **
 ** \param[in] network Handle of the target network.
 ** \param[in] ComM_Mode Requested communication mode.
 **
 ** \return Std_ReturnType
 ** \retval E_OK No Errors.
 ** \retval E_NOT_OK Requesting of Communication Mode failed.
 **
 ** \ServiceID{2}
 ** \Reentrancy{Reentrant (only for different network handles)}
 ** \Synchronicity{Asynchronous}
 */
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComMode (
  NetworkHandleType network,
  ComM_ModeType ComM_Mode
);

/** \brief Provide the current communication mode of a CAN network.
 **
 ** This service gets the current communication mode of a CAN network.
 **
 ** \param[in] network Handle of the target network.
 ** \param[out] ComM_ModePtr Pointer to where to store the current mode.
 **
 ** \return Std_ReturnType
 ** \retval E_OK No Error.
 ** \retval E_NOT_OK Getting of current Communication Mode failed.
 **
 ** \ServiceID{3}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetCurrentComMode (
  NetworkHandleType network,
  P2VAR(ComM_ModeType, AUTOMATIC, CANSM_APPL_DATA) ComM_ModePtr
);


#define CANSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* if !defined( CANSM_COMM_H ) */
/*==================[end of file]===========================================*/


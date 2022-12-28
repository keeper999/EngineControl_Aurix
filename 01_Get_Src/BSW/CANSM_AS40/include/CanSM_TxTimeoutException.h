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
#if (!defined CANSM_TXTIMEOUTEXCEPTION_H)
#define CANSM_TXTIMEOUTEXCEPTION_H

/*==================[inclusions]============================================*/

#include <ComStack_Types.h>    /* AUTOSAR communication stack types */

#include <CanSM_Cfg.h>         /* Generated configuration */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function declarations]========================*/

#if (CANSM_PNSUPPORT == STD_ON)

#define CANSM_START_SEC_CODE
#include <MemMap.h>

/** \brief Request recovery from Tx timeout exception
 **
 ** This function notifies the CanSM module, that the CanNm has detected
 ** a tx timeout exception for the  affected partial CAN network, which shall be
 ** recovered by the  CanSM  module  with  a  transition  to  no  communication
 ** and  back  to  the requested communication mode.
 **
 ** \param[in] Channel Affected CAN network
 **
 ** \ServiceID{11}
 ** \Reentrancy{Reentrant (only for different channels)}
 ** \Synchronicity{Asynchronous}
 */
extern FUNC(void, CANSM_CODE) CanSM_TxTimeoutException
(
  NetworkHandleType Channel
);

#define CANSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* CANSM_PNSUPPORT == STD_ON */

#endif /* if !defined( CANSM_TXTIMEOUTEXCEPTION_H ) */
/*==================[end of file]===========================================*/


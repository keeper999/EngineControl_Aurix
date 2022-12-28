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
#if (!defined CANSM_SCHM_H)
#define CANSM_SCHM_H
/*==================[inclusions]============================================*/

#include <ComStack_Types.h>    /* AUTOSAR communication stack types */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function declarations]========================*/

#define CANSM_START_SEC_CODE
#include <MemMap.h>

/** \brief This function handles asynchronous events, such as mode changes.
 **
 **
 ** This is the main function of the CanSM. It handles asynchronous
 ** events, such as mode changes. It is called cyclically with a fixed period
 ** from the BSW Scheduler.
 **
 ** \ProductionError{CANSM_E_BUS_OFF, thrown\, if there is a notification of
 **                  a bus-off event on a CAN controller}
 **
 ** \ServiceID{5}
 */
extern FUNC(void, CANSM_CODE) CanSM_MainFunction (
  void
);

#define CANSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* if !defined( CANSM_SCHM_H ) */
/*==================[end of file]===========================================*/


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
#if (!defined CANSM_BSWM_H)
#define CANSM_BSWM_H
/*==================[inclusions]============================================*/

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/** \brief Type to report current state to BswM */
typedef enum
{
  CANSM_BSWM_NO_COMMUNICATION,     /**< Report no communication */
  CANSM_BSWM_SILENT_COMMUNICATION, /**< Report silent commmunication */
  CANSM_BSWM_FULL_COMMUNICATION,   /**< Report full communication */
  CANSM_BSWM_BUS_OFF               /**< Report bus off */
} CanSM_BswMCurrentStateType;

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function declarations]========================*/

#endif /* if !defined( CANSM_BSWM_H ) */
/*==================[end of file]===========================================*/


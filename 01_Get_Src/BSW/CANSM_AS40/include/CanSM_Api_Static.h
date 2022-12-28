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
#if (!defined CANSM_API_STATIC_H)
#define CANSM_API_STATIC_H
/*==================[inclusions]============================================*/

#include <ComStack_Types.h>    /* AUTOSAR communication stack types */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/** \brief Post-build configuration type (no functionality).
 **
 ** Data structure type for the post-build configuration parameters. This is
 ** a non-functional data type necessary for the unused parameter of the
 ** CanSM_Init() function.
 */
typedef uint8 CanSM_ConfigType;



/**\brief Definition of the NetworkModeStateType.
 **
 **This type defines the states of the network mode state machine.
 */
typedef enum {
  CANSM_UNINITED = 0,         /**< Network is uninitialized (initial state). */
  CANSM_NO_COMMUNICATION,     /**< No communication. Wakeup can be detected.*/
  CANSM_SILENT_COMMUNICATION, /**< No outgoing communication.*/
  CANSM_FULL_COMMUNICATION    /**< All communication is possible.*/
} CanSM_NetworkModeStateType;


/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function declarations]========================*/

#define CANSM_START_SEC_CODE
#include <MemMap.h>

/** \brief Initializes the CanSM module.
 **
 ** This function initializes the CanSM module. It is the first
 ** function called in CanSM.
 **
 ** \param[in] ConfigPtr Pointer to init structure for the post-build
 **                      configuration parameters of the CanSM. This parameter
 **                      is ignored because post-build configuration is not
 **                      supported. Please use NULL_PTR as parameter for the
 **                      initialization.
 **
 ** \ServiceID{0}
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, CANSM_CODE) CanSM_Init (
  P2CONST( CanSM_ConfigType, AUTOMATIC, CANSM_APPL_CONST ) ConfigPtr
);

#define CANSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* if !defined( CANSM_API_STATIC_H ) */
/*==================[end of file]===========================================*/


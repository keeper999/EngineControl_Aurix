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
#if (!defined CANSM_API_H)
#define CANSM_API_H
/*==================[inclusions]============================================*/

#include <ComStack_Types.h>    /* AUTOSAR communication stack types */

#include <CanSM_Api_Static.h>  /* declaration of static Api functions */
#include <CanSM_Cfg.h>         /* Generated configuration */

/*==================[version check]=========================================*/

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function declarations]========================*/

#define CANSM_START_SEC_CODE
#include <MemMap.h>


#if (CANSM_VERSION_INFO_API == STD_ON)
/** \brief Get version information of the CanSM module.
 **
 ** This service puts out the version information of this module
 ** (module ID, vendor ID, vendor specific version numbers related to BSW00407).
 **
 ** \param[out] VersionInfo Pointer to where to store the version
 **             information of this module.
 **
 ** \ServiceID{1}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, CANSM_CODE) CanSM_GetVersionInfo (
  P2VAR(Std_VersionInfoType, AUTOMATIC, CANSM_APPL_DATA) VersionInfo
);
#endif

#define CANSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* if !defined( CANSM_API_H ) */
/*==================[end of file]===========================================*/


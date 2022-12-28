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
#if (!defined CANSM_VERSION_H)
#define CANSM_VERSION_H

/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined CANSM_VENDOR_ID)
#error CANSM_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: Elektrobit Automotive GmbH */
#define CANSM_VENDOR_ID         1U

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined CANSM_MODULE_ID)
#error CANSM_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification */
#define CANSM_MODULE_ID         140U

/*------------------[AUTOSAR release version identification]----------------*/

#if (defined CANSM_AR_RELEASE_MAJOR_VERSION)
#error CANSM_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define CANSM_AR_RELEASE_MAJOR_VERSION     4U

#if (defined CANSM_AR_RELEASE_MINOR_VERSION)
#error CANSM_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define CANSM_AR_RELEASE_MINOR_VERSION     0U

#if (defined CANSM_AR_RELEASE_REVISION_VERSION)
#error CANSM_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define CANSM_AR_RELEASE_REVISION_VERSION  3U

/*------------------[AUTOSAR module version identification]------------------*/

#if (defined CANSM_SW_MAJOR_VERSION)
#error CANSM_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define CANSM_SW_MAJOR_VERSION             3U

#if (defined CANSM_SW_MINOR_VERSION)
#error CANSM_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define CANSM_SW_MINOR_VERSION             3U

#if (defined CANSM_SW_PATCH_VERSION)
#error CANSM_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define CANSM_SW_PATCH_VERSION             2U

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( CANSM_VERSION_H ) */
/*==================[end of file]============================================*/

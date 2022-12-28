/**
 * \file
 *
 * \brief Autosar Rte
 *
 * This file contains the implementation of the Autosar
 * module Rte.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined RTE_VERSION_H)
#define RTE_VERSION_H

/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined RTE_VENDOR_ID)
#error RTE_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: Elektrobit Automotive GmbH */
#define RTE_VENDOR_ID         1U

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined RTE_MODULE_ID)
#error RTE_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification */
#define RTE_MODULE_ID         240U

/*------------------[AUTOSAR release version identification]----------------*/

#if (defined RTE_AR_RELEASE_MAJOR_VERSION)
#error RTE_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define RTE_AR_RELEASE_MAJOR_VERSION     4U

#if (defined RTE_AR_RELEASE_MINOR_VERSION)
#error RTE_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define RTE_AR_RELEASE_MINOR_VERSION     0U

#if (defined RTE_AR_RELEASE_REVISION_VERSION)
#error RTE_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define RTE_AR_RELEASE_REVISION_VERSION  3U

/*------------------[AUTOSAR module version identification]------------------*/

#if (defined RTE_SW_MAJOR_VERSION)
#error RTE_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define RTE_SW_MAJOR_VERSION             6U

#if (defined RTE_SW_MINOR_VERSION)
#error RTE_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define RTE_SW_MINOR_VERSION             1U

#if (defined RTE_SW_PATCH_VERSION)
#error RTE_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define RTE_SW_PATCH_VERSION             63U

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( RTE_VERSION_H ) */
/*==================[end of file]============================================*/

/**
 * \file
 *
 * \brief Autosar Base
 *
 * This file contains the implementation of the Autosar
 * module Base.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined TS_PBCONFIG_BASIC_TYPES_H)
#define TS_PBCONFIG_BASIC_TYPES_H

/*==================[inclusions]=============================================*/

#include <TSAutosar.h>

/*==================[macros]=================================================*/

/** \brief Maximum value for a TS_CfgOffsetType
 **
 ** This macro defines the maximum value for a TS_CfgOffsetType */
#define TS_CFG_OFFSET_TYPE_MAX UINT32_C(0xFFFFFFFF)

/** \brief Minimum value for a TS_CfgOffsetType
 **
 ** This macro defines the minimum value for a TS_CfgOffsetType */
#define TS_CFG_OFFSET_TYPE_MIN UINT32_C(0x00000000)

/** \brief Maximum value for a TS_VarOffsetType
 **
 ** This macro defines the maximum value for a TS_VarOffsetType */
#define TS_VAR_OFFSET_TYPE_MAX UINT16_C(0xFFFF)

/** \brief Minimum value for a TS_VarOffsetType
 **
 ** This macro defines the minimum value for a TS_VarOffsetType */
#define TS_VAR_OFFSET_TYPE_MIN UINT16_C(0x0000)

/*==================[type definitions]=======================================*/

/** \brief Typedef for relative references within the post-build configuration
 **
 ** This typedef defines a type that is used for relative references
 ** (i.e., offsets) within the post-build configuration */
typedef uint32 TS_CfgOffsetType;

/** \brief Typedef for relative references within the post-build RAM
 **
 ** This typedef defines a type that is used for relative references
 ** (i.e., offsets) within the post-build RAM */
typedef uint16 TS_VarOffsetType;

/*==================[external function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[external data]==========================================*/

#endif /* if (!defined TS_PBCONFIG_BASIC_TYPES_H) */

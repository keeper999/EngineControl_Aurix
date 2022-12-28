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
#if (!defined TS_PBCONFIG_TYPES_H)
#define TS_PBCONFIG_TYPES_H

/* MISRA-C:2004 Deviation List
 *
 * MISRA-1) Deviated Rule: 19.7 (advisory)
 * A function should be used in preference to a function-like macro
 *
 * Reason:
 * No functions are used instead of the affected macros, since those
 * macros are simply used to improve code readability.
 * Implementing them as functions could increase both - memory
 * footprint as well as execution time
 *
 * MISRA-2) Deviated Rule 19.6 (required)
 * #undef shall not be used
 *
 * Reason:
 * The user of this file has the possibility to redefine some macros
 * used in this file. Therefore they are undefined after use.
*/

/*==================[inclusions]=============================================*/

#include <TSPBConfig_BasicTypes.h> /* basic types for post build config */

/*==================[macros]=================================================*/

#if (defined TS_REF2VAR) /* to prevent double definition */
#error TS_REF2VAR already defined
#endif /* if (defined TS_REF2VAR) */

/** \brief abstraction for references in RAM referencing PB RAM elements
 **
 ** This macro abstracts the declaration and definition of references in
 ** RAM referencing post build RAM elements
 **
 ** The reference itself is modifiable.
 ** The references's target is modifiable.
 **
 ** \param[in] reftype type of the referenced constant */
/* Deviation MISRA-1 <+2> */
#define TS_REF2VAR(reftype) \
    VAR(TS_VarOffsetType, TYPEDEF)


#if (defined TS_CONSTREF2VAR) /* to prevent double definition */
#error TS_CONSTREF2VAR already defined
#endif /* if (defined TS_CONSTREF2VAR) */

/** \brief abstraction for references in ROM referencing PB RAM elements
 **
 ** This macro abstracts the declaration and definition of references in
 ** ROM referencing post build RAM elements
 **
 ** The reference itself is not modifiable  (read only).
 ** The references's target is modifiable.
 **
 ** \param[in] reftype type of the referenced constant */
/* Deviation MISRA-1 <+2> */
#define TS_CONSTREF2VAR(reftype) \
    CONST(TS_VarOffsetType, TYPEDEF)

#endif /* if (!defined TS_PBCONFIG_TYPES_H) */

/*
 * The following code is deliberately outside the inclusion guard,
 * since the user of this file should have the possibility to redfined
 * the following macros according to her setting of
 * TS_RELOCATABLE_CFG_ENABLE
 */

#if (!defined TS_RELOCATABLE_CFG_ENABLE)
#error TS_RELOCATABLE_CFG_ENABLE is not defined
#endif

#if (!defined STD_ON)
#error STD_ON is not defined
#endif

#if (!defined STD_OFF)
#error STD_OFF is not defined
#endif

#if ((TS_RELOCATABLE_CFG_ENABLE != STD_ON) && (TS_RELOCATABLE_CFG_ENABLE != STD_OFF))
#error TS_RELOCATABLE_CFG_ENABLE is neither STD_ON nor STD_OFF
#endif


/* Deviation MISRA-2 <+2> */
#undef TS_REF2CFG
#undef TS_CONSTREF2CFG

#if (TS_RELOCATABLE_CFG_ENABLE == STD_ON)
/** \brief abstraction for references in RAM referencing config elements
 **
 ** This macro abstracts the declaration and definition of references in
 ** RAM referencing config elements
 **
 ** The reference itself is modifiable.
 ** The references's target is not modifiable (read only).
 **
 ** \param[in] reftype type of the referenced constant */
/* Deviation MISRA-1 <+2> */
#define TS_REF2CFG(reftype) \
    VAR(TS_CfgOffsetType, TYPEDEF)

#elif (TS_RELOCATABLE_CFG_ENABLE == STD_OFF)

/** \brief abstraction for references in RAM referencing config elements
 **
 ** This macro abstracts the declaration and definition of references in
 ** RAM referencing config elements
 **
 ** The reference itself is modifiable.
 ** The references's target is not modifiable (read only).
 **
 ** \param[in] reftype type of the referenced constant */
/* Deviation MISRA-1 <+2> */
#define TS_REF2CFG(reftype) \
    P2CONST(reftype, TYPEDEF, TS_PB_CFG_PTR_CLASS)

#endif /* (TS_RELOCATABLE_CFG_ENABLE == STD_ON) */


#if (TS_RELOCATABLE_CFG_ENABLE == STD_ON)

/** \brief abstraction for references in ROM referencing config elements
 **
 ** This macro abstracts the declaration and definition of references in
 ** ROM referencing config elements
 **
 ** The reference itself is not modifiable  (read only).
 ** The references's target is not modifiable (read only).
 **
 ** \param[in] reftype type of the referenced constant */
/* Deviation MISRA-1 <+2> */
#define TS_CONSTREF2CFG(reftype) \
    CONST(TS_CfgOffsetType, TYPEDEF)

#elif (TS_RELOCATABLE_CFG_ENABLE == STD_OFF)

/** \brief abstraction for references in ROM referencing config elements
 **
 ** This macro abstracts the declaration and definition of references in
 ** ROM referencing config elements
 **
 ** The reference itself is not modifiable  (read only).
 ** The references's target is not modifiable (read only).
 **
 ** \param[in] reftype type of the referenced constant */
/* Deviation MISRA-1 <+2> */
#define TS_CONSTREF2CFG(reftype) \
    CONSTP2CONST(reftype, TYPEDEF, TS_PB_CFG_PTR_CLASS)

#endif /* (TS_RELOCATABLE_CFG_ENABLE == STD_ON) */

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[external data]==========================================*/

/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined TS_PBCONFIG_ACCESS_H)
#define TS_PBCONFIG_ACCESS_H


/*  Misra-C:2004 Deviation List
 *  MISRA-1) Deviated Rule 11.3 (advisory)
 *  A cast should not be performed between a pointer type and an integral type.
 *
 *  Reason:
 *  Actually this is not a cast between a pointer and a integral type, since
 *  0 is the null pointer constant.
 *
 *  MISRA-2) Deviated rule Rule 19.7 (advisory)
 *  A function should be used in preference to a function-like macro
 *
 *  Reason:
 *  No functions are used instead of the affected macros, since those
 *  macros are simply used to improve code readability.
 *  Implementing them as functions could increase both - memory
 *  footprint as well as execution time
 *
 *  MISRA-3) Deviated Rule 19.13 (advisory)
 *  The # and ## preprocessor operators should not be used
 *
 *  Reason:
 *  The ## is required here to prevent premature expansion of the
 *  pointer class compiler abstraction parameter which results in
 *  the call of a macro with an empty argument (in cases where the
 *  pointer class compiler abstraction is left empty by the
 *  integrator).
 *
 *  MISRA-4) Deviated Rule 19.6 (required)
 *  #undef shall not be used
 *
 *  Reason:
 *  Some macros can be redefined by the user of this file and they
 *  are undefined after use in this file.
 */

/*==================[inclusions]=============================================*/

#include <TSPBConfig_BasicTypes.h> /* basic types for post build config */

/*==================[macros]=================================================*/

/** \brief Get a const reference to a post-build RAM element - no
 ** check for invalid refs
 **
 ** This macro retrieves a const pointer to a post-build RAM element
 ** without checking for invalid references
 **
 ** \param[in] rambase base address of the module's post-build RAM.
 ** \param[in] reftype type of the referenced element in post-build RAM.
 ** \param[in] module short name of the respective module (all caps),
 ** e.g., PDUR
 ** \param[in] offset offset in post build RAM of the elements to which the
 ** reference shall be retrieved. */
/* Deviation MISRA-1, MISRA-2, MISRA-3 <+6> */
#define TS_UNCHECKEDGETCONSTVAR(rambase, reftype, module, offset)       \
         ((CONSTP2VAR(reftype, AUTOMATIC, module ## _VAR_NOINIT))       \
            (CONSTP2VAR(void, AUTOMATIC, module ## _VAR_NOINIT))        \
          &(((CONSTP2VAR(uint8, AUTOMATIC, module ## _VAR_NOINIT))      \
             (CONSTP2VAR(void, AUTOMATIC, module ## _VAR_NOINIT))       \
             rambase) [(offset)]))

/** \brief Get a const reference to a post-build RAM element
 **
 ** This macro retrieves a const pointer to a post-build RAM element
 **
 ** \param[in] rambase base address of the module's post-build RAM.
 ** \param[in] reftype type of the referenced element in post-build RAM.
 ** \param[in] module short name of the respective module (all caps),
 ** e.g., PDUR
 ** \param[in] offset offset in post build RAM of the elements to which the
 ** reference shall be retrieved. */
/* Deviation MISRA-1, MISRA-2, MISRA-3 <+4> */
#define TS_CHECKEDGETCONSTVAR(rambase, reftype, module, offset)         \
        (((offset) == TS_VAR_OFFSET_TYPE_MAX) ?                         \
         ((CONSTP2VAR(reftype, AUTOMATIC, module ## _VAR_NOINIT)) 0) : \
         TS_UNCHECKEDGETCONSTVAR(rambase, reftype, module, offset))

/** \brief Get a non-const reference to a post-build RAM element - no
 ** check for invalid refs
 **
 ** This macro retrieves a non-const pointer to a post-build RAM
 ** element without checking for invalid references
 **
 ** \param[in] rambase base address of the module's post-build RAM.
 ** \param[in] reftype type of the referenced element in post-build RAM.
 ** \param[in] module short name of the respective module (all caps),
 ** e.g., PDUR
 ** \param[in] offset offset in post build RAM of the elements to which the
 ** reference shall be retrieved. */
/* Deviation MISRA-1, MISRA-2, MISRA-3 <+6> */
#define TS_UNCHECKEDGETVAR(rambase, reftype, module, offset)    \
         ((P2VAR(reftype, AUTOMATIC, module ## _VAR_NOINIT))    \
            (P2VAR(void, AUTOMATIC, module ## _VAR_NOINIT))     \
          &(((P2VAR(uint8, AUTOMATIC, module ## _VAR_NOINIT))   \
             (P2VAR(void, AUTOMATIC, module ## _VAR_NOINIT))    \
             rambase) [(offset)]))

/** \brief Get a non-const reference to a post-build RAM element
 **
 ** This macro retrieves a non-const pointer to a post-build RAM element
 **
 ** \param[in] rambase base address of the module's post-build RAM.
 ** \param[in] reftype type of the referenced element in post-build RAM.
 ** \param[in] module short name of the respective module (all caps),
 ** e.g., PDUR
 ** \param[in] offset offset in post build RAM of the elements to which the
 ** reference shall be retrieved. */
/* Deviation MISRA-1, MISRA-2, MISRA-3 <+4> */
#define TS_CHECKEDGETVAR(rambase, reftype, module, offset)              \
        (((offset) == TS_VAR_OFFSET_TYPE_MAX) ?                         \
         ((P2VAR(reftype, AUTOMATIC, module ## _VAR_NOINIT)) 0) :      \
         TS_UNCHECKEDGETVAR(rambase, reftype, module, offset))

#endif /* if (!defined TS_PBCONFIG_ACCESS_H) */

/*
 * The following code is deliberately outside the inclusion guard,
 * since the user of this file should have the possibility to redfine
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

/* Deviation MISRA-4 <+4> */
#undef TS_UNCHECKEDGETCONSTCFG
#undef TS_CHECKEDGETCONSTCFG
#undef TS_UNCHECKEDGETCFG
#undef TS_CHECKEDGETCFG


#if (TS_RELOCATABLE_CFG_ENABLE == STD_ON)
/** \brief Get a const reference to a post-build config element - no
 ** check for invalid refs
 **
 ** This macro retrieves a const pointer to a post-build config
 ** element without checking for invalid references
 **
 ** \param[in] cfgbase base address of the module's post-build configuration.
 ** \param[in] reftype type of the referenced element in post-build
 ** configuration.
 ** \param[in] module short name of the respective module (all caps),
 ** e.g., PDUR
 ** \param[in] offset offset/pointer of/to the to element in the
 ** post-build configuration */
/* Deviation MISRA-1, MISRA-2, MISRA-3 <+6> */
#define TS_UNCHECKEDGETCONSTCFG(cfgbase, reftype, module, offset)       \
         ((CONSTP2CONST(reftype, AUTOMATIC, module ## _APPL_CONST))     \
            (CONSTP2CONST(void, AUTOMATIC, module ## _APPL_CONST))      \
          &(((CONSTP2CONST(uint8, AUTOMATIC, module ## _APPL_CONST))    \
             (CONSTP2CONST(void, AUTOMATIC, module ## _APPL_CONST))     \
             cfgbase) [(offset)]))

/** \brief Get a const reference to a post-build config element
 **
 ** This macro retrieves a const pointer to a post-build config element
 **
 ** \param[in] cfgbase base address of the module's post-build configuration.
 ** \param[in] reftype type of the referenced element in post-build
 ** configuration.
 ** \param[in] module short name of the respective module (all caps),
 ** e.g., PDUR
 ** \param[in] offset offset/pointer of/to the to element in the
 ** post-build configuration */
/* Deviation MISRA-1, MISRA-2, MISRA-3 <+4> */
#define TS_CHECKEDGETCONSTCFG(cfgbase, reftype, module, offset)         \
        (((offset) == 0U) ?                                             \
         ((CONSTP2CONST(reftype, AUTOMATIC, module ## _APPL_CONST)) 0) : \
         TS_UNCHECKEDGETCONSTCFG(cfgbase, reftype, module, offset))

/** \brief Get a non-const reference to a post-build config element -
 ** no check for invalid refs
 **
 ** This macro retrieves a non-const pointer to a post-build config
 ** element without checking for invalid references
 **
 ** \param[in] cfgbase base address of the module's post-build configuration.
 ** \param[in] reftype type of the referenced element in post-build
 ** configuration.
 ** \param[in] module short name of the respective module (all caps),
 ** e.g., PDUR
 ** \param[in] offset offset/pointer of/to the to element in the
 ** post-build configuration */
/* Deviation MISRA-1, MISRA-2, MISRA-3 <+6> */
#define TS_UNCHECKEDGETCFG(cfgbase, reftype, module, offset)    \
         ((P2CONST(reftype, AUTOMATIC, module ## _APPL_CONST))  \
            (P2CONST(void, AUTOMATIC, module ## _APPL_CONST))   \
          &(((P2CONST(uint8, AUTOMATIC, module ## _APPL_CONST)) \
             (P2CONST(void, AUTOMATIC, module ## _APPL_CONST))  \
             cfgbase) [(offset)]))

/** \brief Get a non-const reference to a post-build config element
 **
 ** This macro retrieves a non-const pointer to a post-build config element
 **
 ** \param[in] cfgbase base address of the module's post-build configuration.
 ** \param[in] reftype type of the referenced element in post-build
 ** configuration.
 ** \param[in] module short name of the respective module (all caps),
 ** e.g., PDUR
 ** \param[in] offset offset/pointer of/to the to element in the
 ** post-build configuration */
/* Deviation MISRA-1, MISRA-2, MISRA-3 <+4> */
#define TS_CHECKEDGETCFG(cfgbase, reftype, module, offset)              \
        (((offset) == 0U) ?                                             \
         ((P2CONST(reftype, AUTOMATIC, module ## _APPL_CONST)) 0) :    \
         TS_UNCHECKEDGETCFG(cfgbase, reftype, module, offset))

#elif (TS_RELOCATABLE_CFG_ENABLE == STD_OFF)
/* Deviation MISRA-2 */
#define TS_UNCHECKEDGETCONSTCFG(cfgbase, reftype, module, ptr) (ptr)
/* Deviation MISRA-2 */
#define TS_CHECKEDGETCONSTCFG(cfgbase, reftype, module, ptr) (ptr)
/* Deviation MISRA-2 */
#define TS_UNCHECKEDGETCFG(cfgbase, reftype, module, ptr) (ptr)
/* Deviation MISRA-2 */
#define TS_CHECKEDGETCFG(cfgbase, reftype, module, ptr) (ptr)
#endif /* (TS_RELOCATABLE_CFG_ENABLE) */

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[external data]==========================================*/

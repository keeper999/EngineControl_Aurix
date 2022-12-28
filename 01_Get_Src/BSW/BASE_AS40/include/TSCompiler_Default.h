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

#if (!defined TS_COMPILER_DEFAULT_H)
#define TS_COMPILER_DEFAULT_H

/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/** \brief Prevent empty translation unit
 **
 ** This macro shall be used to prevent that a translation unit is empty.
 **
 **/
#if ((defined TS_MERGED_COMPILE) && (defined STD_ON))
#if (TS_MERGED_COMPILE == STD_ON)
#define TS_PREVENTEMPTYTRANSLATIONUNIT
#else /* (TS_MERGED_COMPILE == STD_ON) */
#define TS_PREVENTEMPTYTRANSLATIONUNIT \
    typedef void TSPreventEmptyTranslationUnit;
#endif /* (TS_MERGED_COMPILE == STD_ON) */
#else /* (defined TS_MERGED_COMPILE) && (defined STD_ON) */
#define TS_PREVENTEMPTYTRANSLATIONUNIT \
    typedef void TSPreventEmptyTranslationUnit;
#endif /* (defined TS_MERGED_COMPILE) && (defined STD_ON) */


#if (defined TS_DEPRECATED_TYPEDEF)  /* to prevent double definition */
#error TS_DEPRECATED_TYPEDEF is already defined
#endif /* if (defined TS_DEPRECATED_TYPEDEF) */

/** \brief Tag a typedef as deprecated
 **
 ** This macro shall be used to tag a typedef as deprecated.
 **
 ** Example use:
 **
 ** typedef struct
 ** {
 **     uint8 member0;
 **     uint8 member1;
 ** } deprecatedType TS_DEPRECATED_TYPEDEF;
 **
 ** This yields the following warning for every _USE_ of the typedef
 ** during compilation:
 **
 ** appl.c: In function 'TestDeprecatedTypedef':
 ** appl.c:84: warning: 'deprecatedType' is deprecated
 **
 **/
#if (defined __GNUC__)
#define TS_DEPRECATED_TYPEDEF __attribute__ ((deprecated))
#else /* if (defined __GNUC__) */
#define TS_DEPRECATED_TYPEDEF
#endif /* if (defined __GNUC__) */


#if (defined TS_DEPRECATED_VARIABLE)  /* to prevent double definition */
#error TS_DEPRECATED_VARIABLE is already defined
#endif /* if (defined TS_DEPRECATED_VARIABLE) */

/** \brief Tag a variable as deprecated
 **
 ** This macro shall be used to tag a variable as deprecated.
 **
 ** Example use:
 **
 ** uint8 deprecatedVariable TS_DEPRECATED_VARIABLE;
 **
 ** This yields the following warning for every _USE_ of the variable
 ** during compilation:
 **
 ** appl.c: In function 'TestDeprecatedVariable':
 ** appl.c:91: warning: 'deprecatedVariable' is deprecated (declared at appl.c:48)
 **
 **/
#if (defined __GNUC__)
#define TS_DEPRECATED_VARIABLE __attribute__ ((deprecated))
#else /* if (defined __GNUC__) */
#define TS_DEPRECATED_VARIABLE
#endif /* if (defined __GNUC__) */


#if (defined TS_DEPRECATED_FUNCTION)  /* to prevent double definition */
#error TS_DEPRECATED_FUNCTION is already defined
#endif /* if (defined TS_DEPRECATED_FUNCTION) */

/** \brief Tag a function as deprecated
 **
 ** This macro shall be used to tag a function as deprecated.
 **
 ** Example use:
 **
 ** STATIC FUNC(void, EBTEST_CODE) TestDeprecatedFunction(void) TS_DEPRECATED_FUNCTION;
 **
 ** This yields the following warning for every _USE_ of the function
 ** during compilation:
 **
 ** appl.c: In function 'TestMain':
 ** appl.c:62: warning: 'TestDeprecatedFunction' is deprecated (declared at appl.c:29)
 **
 **/
#if (defined __GNUC__)
#define TS_DEPRECATED_FUNCTION __attribute__ ((deprecated))
#else /* if (defined __GNUC__) */
#define TS_DEPRECATED_FUNCTION
#endif /* if (defined __GNUC__) */


#if (defined TS_DOPRAGMA) /* to prevent double definition */
#error TS_DOPRAGMA is already defined
#endif /* if (defined TS_DOPRAGMA) */

#if (defined __GNUC__)
#define TS_DOPRAGMA(x) _Pragma (#x)
#else /* if (defined __GNUC__) */
#define TS_DOPRAGMA(x)
#endif /* if (defined __GNUC__) */

#if (defined TS_DEPRECATED_MACRO)  /* to prevent double definition */
#error TS_DEPRECATED_MACRO is already defined
#endif /* if (defined TS_DEPRECATED_MACRO) */

/** \brief Tag a macro as deprecated
 **
 ** This macro shall be used to tag a macro as deprecated.
 **
 ** Example use:
 **
 ** #define DEPRECATED_MACRO(a,b)                       \
 **     do                                              \
 **     {                                               \
 **         TS_DEPRECATED_MACRO(DEPRECATED_MACRO)       \
 **         (a) = (b);                                  \
 **     } while(0)
 **
 ** This yields the following warning for every _USE_ of the macro
 ** during compilation:
 **
 ** appl.c: In function 'TestDeprecatedMacro':
 ** appl.c:99: warning: ignoring #pragma Macro_DEPRECATED_MACRO_is_deprecated
 **
 ** Note that this warning that the #pragma is ignored is the best we can do, since the only
 ** means gcc provides to explicitly trigger warning messages are #error and #warning, which both
 ** cannot be used in macros. - Note further that #pragma message is not supported by gcc (although
 ** the docu states that is is).
 **/
#if (defined __GNUC__)
#define TS_DEPRECATED_MACRO(x) \
  TS_DOPRAGMA(Macro_ ## x ## _is_deprecated)
#else /* if (defined __GNUC__) */
#define TS_DEPRECATED_MACRO(x)
#endif /* if (defined __GNUC__) */

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/
#endif /* if !defined( COMPILER_COMMON_H ) */

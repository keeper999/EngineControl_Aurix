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

/* 
 * MISRA-C:2004 Deviation List
 * 
 * MISRA-1) Deviated Rule: 11.3 (advisory)
 * A cast should not be performed between a pointer type and
 * an integral type.
 *
 * Reason:
 * Depending on the standard library the offsetof() macro is expanded
 * to a construct which may violate this rule.
 * 
 * MISRA-2) Deviated Rule: 20.6 (required)
 * The macro 'offsetof()', in library <stddef.h> shall not be used.
 *
 * Reason:
 * MISRA-C:2004 Rule 20.6 gives the following rationale for
 * forbidding the use of this macro: "Use of this macro can lead
 * to undefined behaviour when the types of the operands are
 * incompatible or when bitfields are used."
 * This rationale is an ambiguous and incomplete deduction of a
 * statement in section G.2 "Undefined behavior" of the ISO 9899:1990
 * standard: "The behavior is undefined in the following
 * circumstances: The member designator parameter of an offsetof
 * macro is an invalid right operand of the .operator for the type
 * parameter, or designates a bit-field."
 * Since the only uses of offsetof in the context of this header
 * file is in line with the restrictions imposed by ISO 9899:1990, the
 * behavior is not undefined here.
 * The offsetof macro is needed to compute a structure member's
 * offset from the beginning of a structure in order to create
 * references within a relocatable post build configuration.
 *
 * MISRA-3) Deviated Rule: 10.1 (required)
 * The value of an expressionj of integer type shall not be implicitly converted to a different underlying type if:
 * a) it is not a conversion to a wider integer type of the same signedness, or
 * b) the expression is complex, or
 * c) the expression is not constant and is a function argument, or
 * d) the expression is not constant and is a return expression.
 *
 * Reason:
 * Known false-positive of PolySpace 2013a;
 * should be fixed with the next tool release
 * 
 * MISRA-4) Deviated Rule: 12.5 (required)
 * The operands of a logical '&&' or '||' shall be 'primary-expressions'.
 *
 * Reason:
 * Known false-positive of PolySpace 2013a
 */

/*==================[inclusions]=============================================*/

#include <Std_Types.h>
#include <TSPBConfig_Signature.h>

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

#define BASE_START_SEC_CODE
#include <MemMap.h>

/** \brief Checks whether the platform signature \p signature is valid
**
** \param[in] signature Platform signature
**
** \retval TRUE the platform signature \p signature is valid
** \retval FALSE the platform signature \p signature is invalid */
/* Deviation MISRA-1 <+16>, MISRA-2 <+16>, MISRA-3 <+16>, MISRA-4 <+16> */
#if 0
FUNC(boolean, BASE_CODE) TS_PlatformSigIsValid
(
  uint32 signature
)
{
  boolean RetVal = FALSE;

  if (TS_SIG_CHECK_ENDIANESS(signature) &&
      TS_SIG_CHECK_ALIGNMENT_ARRAY (signature) &&
      TS_SIG_CHECK_ALIGNMENT_STRUCT(signature) &&
      TS_SIG_CHECK_ALIGNMENT_SINT32(signature) &&
      TS_SIG_CHECK_ALIGNMENT_SINT16(signature) &&
      TS_SIG_CHECK_ALIGNMENT_SINT8(signature) &&
      TS_SIG_CHECK_ALIGNMENT_UINT32(signature) &&
      TS_SIG_CHECK_ALIGNMENT_UINT16(signature) &&
      TS_SIG_CHECK_ALIGNMENT_UINT8(signature))
  {
    RetVal = TRUE;
  }

  return RetVal;
}

#endif

#define BASE_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/

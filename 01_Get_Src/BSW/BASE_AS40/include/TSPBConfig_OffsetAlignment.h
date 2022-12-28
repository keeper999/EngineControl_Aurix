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
#if (!defined TS_PBCONFIG_OFFSET_ALIGNMENT_H)
#define TS_PBCONFIG_OFFSET_ALIGNMENT_H

/* MISRA-C:2004 Deviation List
 *
 * MISRA-1) Deviated Rule: 19.10 (required)
 * In the definition of a function-like macro each instance of a parameter
 * shall be enclose in parentheses unless it is used as the operand of
 * # or ##.
 *
 * Reason:
 * Parentheses are syntactically not allowed here.
 *
 * MISRA-2) Deviated Rule: 20.6 (required)
 * The macro offsetof, in library <stddef.h>, shall not be used
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
 */

/*==================[inclusions]=============================================*/



#include <TSAutosar.h>

/*==================[macros]=================================================*/

/*------------------[alignment and offset macros]----------------------------*/

/** \brief Get the byte offset of a structure member
 **
 ** This macro retrieves the byte offset of a given structure member from
 ** the start of the structure
 **
 ** \param[in] structure structure containing the member
 ** \param[in] member member for which the byte offset within the structure
 **            shall be retrieved */
/* Deviation MISRA-1, MISRA-2 <+2> */
#define TS_OFFSETOF(structure, member) \
  (offsetof(structure, member))

/** \brief Get alignment of type within structures
 **
 ** This macro retrieves the structure alignment requirements of a
 ** given type
 **
 ** \param[in] type type the alignment requirements shall be obtained for */
/* Deviation MISRA-1 <+2> */
#define TS_ALIGNOF(type) \
    TS_OFFSETOF(struct {uint8 nMember1; type nMember2;}, nMember2)

/** \brief Get alignment of an array of type type within structures
 **
 ** This macro retrieves the structure alignment requirements of an
 ** array containing elements elements of type type
 **
 ** \param[in] type type the alignment requirements shall be obtained for */
/* Deviation MISRA-1 <+2> */
#define TS_ARRAYALIGNOF(type,elements) \
    TS_OFFSETOF(struct {uint8 nMember1; type nMember2[elements];}, nMember2)

/** \brief Check whether additional padding is inserted
 **
 ** This macro checks whether additional padding bytes are inserted for
 ** structures solely consisting of uint8/uint16/uint32 members */
#define TS_ADDITIONAL_PADDING_BYTES_INSERTED()                  \
    ((                                                          \
        (sizeof(struct {uint8 nMember;}) != sizeof(uint8)) ||   \
        (sizeof(struct {uint16 nMember;}) != sizeof(uint16)) || \
        (sizeof(struct {uint32 nMember;}) != sizeof(uint32))    \
    ) != 0U)

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[external data]==========================================*/

#endif /* (!defined TS_PBCONFIG_OFFSET_ALIGNMENT_H) */

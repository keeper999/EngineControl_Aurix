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
#if (!defined TS_PBCONFIG_SIGNATURE_H)
#define TS_PBCONFIG_SIGNATURE_H


/* MISRA-C:2004 Deviation List
 *
 * MISRA-1) Deviated Rule: 19.12
 * There shall be at most one occurrence of the # or ## preprocessor
 * operators in a single macro definition.
 *
 * Reason:
 * The reason for this rule is that the order of evaluation these operators
 * is undefined. The macros in question don't depend on the order of evaluation.
 *
 * MISRA-2) Deviated Rule: 19.13
 * The # and ## preprocessor operators should not be used.
 *
 * Reason:
 * The rationale for this rule is that the evaluation order of the
 * # and ## operator is not defined. - Since only one instance of the ##
 * operator is used, there is no ambiguity due to the evaluation order
 */

/*==================[inclusions]=============================================*/

#include <TSAutosar.h>

#include <TSPBConfig_OffsetAlignment.h>

/*==================[macros]=================================================*/


/*
 * macros for the extraction of relevant information from the post-build
 * platform signature for consistency of endianness and alignment requirements
 *
 * Detailed information on the structure of the signature can be found in
 * http://wiki.elektrobit.com/index.php?title=Project:EB_tresos/Architecture/PostBuild&oldid=467588#Post-build_platform_signature_for_consistency_of_endianness_and_alignment_requirements
 */

/* macros for masks and shifts for extraction of alignment requirements */
#define TS_SIG_SINT32_ALIGNMENT_MASK UINT32_C(0x00000007)
#define TS_SIG_SINT32_ALIGNMENT_SHIFT UINT32_C(0)
#define TS_SIG_UINT32_ALIGNMENT_MASK UINT32_C(0x00000007)
#define TS_SIG_UINT32_ALIGNMENT_SHIFT UINT32_C(3)
#define TS_SIG_SINT16_ALIGNMENT_MASK UINT32_C(0x00000007)
#define TS_SIG_SINT16_ALIGNMENT_SHIFT UINT32_C(8)
#define TS_SIG_UINT16_ALIGNMENT_MASK UINT32_C(0x00000007)
#define TS_SIG_UINT16_ALIGNMENT_SHIFT UINT32_C(11)
#define TS_SIG_SINT8_ALIGNMENT_MASK UINT32_C(0x00000007)
#define TS_SIG_SINT8_ALIGNMENT_SHIFT UINT32_C(16)
#define TS_SIG_UINT8_ALIGNMENT_MASK UINT32_C(0x00000007)
#define TS_SIG_UINT8_ALIGNMENT_SHIFT UINT32_C(19)
#define TS_SIG_ARRAY_ALIGNMENT_MASK UINT32_C(0x00000007)
#define TS_SIG_ARRAY_ALIGNMENT_SHIFT UINT32_C(24)
#define TS_SIG_STRUCT_ALIGNMENT_MASK UINT32_C(0x00000007)
#define TS_SIG_STRUCT_ALIGNMENT_SHIFT UINT32_C(27)

#if (defined TS_SIG_GET_ALIGNMENT_HLP_HLP) /* to prevent double definition */
#error TS_SIG_GET_ALIGNMENT_HLP_HLP is already defined
#endif /* if (defined TS_SIG_GET_ALIGNMENT_HLP_HLP) */

/* Deviation MISRA-1, MISRA-2 <+2> */
#define TS_SIG_GET_ALIGNMENT_HLP_HLP(prefixedtype, signature) \
  (((signature) >> prefixedtype ## _ALIGNMENT_SHIFT) & prefixedtype ## _ALIGNMENT_MASK)


#if (defined TS_SIG_GET_ALIGNMENT_HLP) /* to prevent double definition */
#error TS_SIG_GET_ALIGNMENT_HLP is already defined
#endif /* if (defined TS_SIG_GET_ALIGNMENT_HLP) */

/* Deviation MISRA-2 <+2> */
#define TS_SIG_GET_ALIGNMENT_HLP(type, signature) \
  TS_SIG_GET_ALIGNMENT_HLP_HLP(TS_SIG_ ## type, signature)


#if (defined TS_SIG_GET_ALIGNMENT) /* to prevent double definition */
#error TS_SIG_GET_ALIGNMENT is already defined
#endif /* if (defined TS_SIG_GET_ALIGNMENT) */

/*
 * macro to extract the alignment requirements for a specific type from the signature
 */
#define TS_SIG_GET_ALIGNMENT(type, signature) \
  ((uint32)(UINT32_C(1) << TS_SIG_GET_ALIGNMENT_HLP(type, signature)))


#if (defined TS_SIG_CHECK_ALIGNMENT_UINT8) /* to prevent double definition */
#error TS_SIG_CHECK_ALIGNMENT_UINT8 is already defined
#endif /* if (defined TS_SIG_CHECK_ALIGNMENT_UINT8) */

/*
 * macro to check whether the alignment requirements of uint8 that were
 * assumed when generating the post build configuration match the machines
 * alignment requirements for uint8
 */
#define TS_SIG_CHECK_ALIGNMENT_UINT8(signature) \
  (TS_SIG_GET_ALIGNMENT(UINT8, signature) == TS_ALIGNOF(uint8))


#if (defined TS_SIG_CHECK_ALIGNMENT_UINT16) /* to prevent double definition */
#error TS_SIG_CHECK_ALIGNMENT_UINT16 is already defined
#endif /* if (defined TS_SIG_CHECK_ALIGNMENT_UINT16) */

/*
 * macro to check whether the alignment requirements of uint16 that were
 * assumed when generating the post build configuration match the machines
 * alignment requirements for uint16
 */
#define TS_SIG_CHECK_ALIGNMENT_UINT16(signature) \
  (TS_SIG_GET_ALIGNMENT(UINT16, signature) == TS_ALIGNOF(uint16))

#if (defined TS_SIG_CHECK_ALIGNMENT_UINT32) /* to prevent double definition */
#error TS_SIG_CHECK_ALIGNMENT_UINT32 is already defined
#endif /* if (defined TS_SIG_CHECK_ALIGNMENT_UINT32) */

/*
 * macro to check whether the alignment requirements of uint32 that were
 * assumed when generating the post build configuration match the machines
 * alignment requirements for uint32
 */
#define TS_SIG_CHECK_ALIGNMENT_UINT32(signature) \
  (TS_SIG_GET_ALIGNMENT(UINT32, signature) == TS_ALIGNOF(uint32))


#if (defined TS_SIG_CHECK_ALIGNMENT_SINT8) /* to prevent double definition */
#error TS_SIG_CHECK_ALIGNMENT_SINT8 is already defined
#endif /* if (defined TS_SIG_CHECK_ALIGNMENT_SINT8) */

/*
 * macro to check whether the alignment requirements of sint8 that were
 * assumed when generating the post build configuration match the machines
 * alignment requirements for sint8
 */
#define TS_SIG_CHECK_ALIGNMENT_SINT8(signature) \
  (TS_SIG_GET_ALIGNMENT(SINT8, signature) == TS_ALIGNOF(sint8))


#if (defined TS_SIG_CHECK_ALIGNMENT_SINT16) /* to prevent double definition */
#error TS_SIG_CHECK_ALIGNMENT_SINT16 is already defined
#endif /* if (defined TS_SIG_CHECK_ALIGNMENT_SINT16) */

/*
 * macro to check whether the alignment requirements of sint16 that were
 * assumed when generating the post build configuration match the machines
 * alignment requirements for sint16
 */
#define TS_SIG_CHECK_ALIGNMENT_SINT16(signature) \
  (TS_SIG_GET_ALIGNMENT(SINT16, signature) == TS_ALIGNOF(sint16))


#if (defined TS_SIG_CHECK_ALIGNMENT_SINT32) /* to prevent double definition */
#error TS_SIG_CHECK_ALIGNMENT_SINT32 is already defined
#endif /* if (defined TS_SIG_CHECK_ALIGNMENT_SINT32) */

/*
 * macro to check whether the alignment requirements of sint32 that were
 * assumed when generating the post build configuration match the machines
 * alignment requirements for sint32
 */
#define TS_SIG_CHECK_ALIGNMENT_SINT32(signature) \
  (TS_SIG_GET_ALIGNMENT(SINT32, signature) == TS_ALIGNOF(sint32))


#if (defined TS_SIG_CHECK_ALIGNMENT_STRUCT) /* to prevent double definition */
#error TS_SIG_CHECK_ALIGNMENT_STRUCT is already defined
#endif /* if (defined TS_SIG_CHECK_ALIGNMENT_STRUCT) */

/*
 * macro to check whether the minimal alignment requirements of structures that were
 * assumed when generating the post build configuration match the machines
 * minimal alignment requirements for structures. - using two uint8 members here to
 * address the fact that the TriCore EABI states that the minimal aligment requirement
 * of structs of 1 byte size is only 1 byte (instead of 2 bytes minimal alignment like
 * all struct of size > 1 byte)
 */
#define TS_SIG_CHECK_ALIGNMENT_STRUCT(signature) \
  (TS_SIG_GET_ALIGNMENT(STRUCT, signature) == TS_ALIGNOF(struct {uint8 nMember1; uint8 nMember2;}))


#if (defined TS_SIG_CHECK_ALIGNMENT_ARRAY) /* to prevent double definition */
#error TS_SIG_CHECK_ALIGNMENT_ARRAY is already defined
#endif /* if (defined TS_SIG_CHECK_ALIGNMENT_ARRAY) */

/*
 * macro to check whether the minimal alignment requirements of arrays that were
 * assumed when generating the post build configuration match the machines
 * minimal alignment requirements for arrays
 */
#define TS_SIG_CHECK_ALIGNMENT_ARRAY(signature) \
  (TS_SIG_GET_ALIGNMENT(ARRAY, signature) == TS_ARRAYALIGNOF(uint8, 1))


#if (defined TS_SIG_CHECK_ENDIANESS) /* to prevent double definition */
#error TS_SIG_CHECK_ENDIANESS is already defined
#endif /* if (defined TS_SIG_CHECK_ENDIANESS) */

/*
 * macro to check whether the endianness that was assumed when generating
 * the post build configuration match the machines endianness
 */
#define TS_SIG_CHECK_ENDIANESS(signature) \
  (((signature) & UINT32_C(0x80808080)) == UINT32_C(0x80000000))


#if (defined TS_PlatformSigIsValid) /* to prevent double definition */
#error TS_PlatformSigIsValid is already defined
#endif /* if (defined TS_PlatformSigIsValid) */

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define BASE_START_SEC_CODE
#include <MemMap.h>

/** \brief Checks whether the platform signature \p signature is valid
 **
 ** \param[in] signature Platform signature
 **
 ** \retval TRUE the platform signature \p signature is valid
 ** \retval FALSE the platform signature \p signature is invalid */
extern FUNC(boolean, BASE_CODE) TS_PlatformSigIsValid
(
  uint32 signature
);

#define BASE_STOP_SEC_CODE
#include <MemMap.h>

/*==================[external constants]=====================================*/

/*==================[external data]==========================================*/

#endif /* if (!defined TS_PBCONFIG_SIGNATURE_H) */

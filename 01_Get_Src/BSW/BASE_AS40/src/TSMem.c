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
 * Misra-C:2004 Deviations:
 *
 * MISRA-1) Deviated Rule: 17.4 (required)
 * Array indexing shall be the only allowed form of pointer arithmetic.
 *
 * Reason:
 * Pointer arithmetic is used for classical functions like memcpy() to
 * make them more readable and maintainable.
 *
 * MISRA-2) Deviated Rule: 19.10 (required)
 * In the definition of a function-like macro each instance of a parameter
 * shall be enclosed in parentheses.
 *
 * Reason:
 * Macros are used for type independent casts. Such a parameter cannot be
 * enclosed in parentheses as this would lead to a syntax error.
 *
 * MISRA-3) Deviated Rule: 11.3 (advisory)
 * A cast should not be perfomed between a pointer type and an
 * integral type.
 *
 * Reason:
 * The memory routines are optimized for dealing with aligned memory
 * sections and need to check the correct alignment before the operation.
 *
 * MISRA-4) Deviated Rule: 11.4 (advisory)
 * A cast should not be performed between a pointer to object type
 * and a different pointer to object type.
 *
 * Reason:
 * The memory routines are optimized for dealing with aligned memory
 * and the correct alignment has been checked before converting
 * to different object types (see MISRA-3).
 *
 * MISRA-5) Deviated Rule: 16.7 (advisory)
 * A pointer parameter in a function prototype should be declared as
 * pointer to const if the pointer is not used to modify the addressed
 * object.
 *
 * Reason:
 * The pointers in question are void pointers that are directly cast
 * to uint8 pointers which are used to modify the addressed object.
 *
 * MISRA-6) Deviated Rule: 10.1 (required)
 * Implicit conversion of the expression of underlying type 'unsigned int' to the
 * type 'signed int' that is not a wider integer type of the same signedness.
 *
 * Reason:
 * Known false-positive of PolySpace 2013a;
 * should be fixed with the next tool release
 */

/*==================[inclusions]=============================================*/

#include <Std_Types.h>
#include <TSMem.h>

/*==================[macros]=================================================*/

#if (defined TS_MEMCPY_NOCHECK)
#error TS_MEMCPY_NOCHECK is already defined
#endif

/** \brief Copies \p len bytes of memory from \p dst to \p src using
 ** type information passed in \p type
 **
 ** \param[in] dst Pointer to the destination address
 ** \param[in] src Pointer to the source address
 ** \param[in] len Amount of bytes to copy
 ** \param[in] type The type to perform the copying with */
#define TS_MEMCPY_NOCHECK(dst, src, len, type)              \
  do {                                                      \
    /* loop and copy */                                     \
    while ((len) >= (uint32)sizeof(type))                   \
    {                                                       \
      /* Deviation MISRA-2 <+2> */                          \
      *(P2VAR(type, AUTOMATIC, BASE_APPL_DATA))(dst) =      \
         *(P2CONST(type, AUTOMATIC, BASE_APPL_DATA))(src);  \
      /* Deviation MISRA-1 <+2> */                          \
      (src) += (uint32)sizeof(type);                        \
      (dst) += (uint32)sizeof(type);                        \
      (len) -= (uint32)sizeof(type);                        \
    }                                                       \
  } while (0)

/** \brief Assigns \p len times the value \p val to \p dst  using
 ** type information passed in  \p type
 **
 ** \param[in] dst Pointer to the destination address
 ** \param[in] val Value to be assigned
 ** \param[in] len Amount of bytes to assign
 ** \param[in] type The type to perform the assignment with */
#define TS_MEMSET_NOCHECK(dst, val, len, type)                \
  do                                                          \
  {                                                           \
    while ((len) >= (uint32)sizeof(type))                     \
    {                                                         \
      /* Deviation MISRA-2 */                                 \
      *(P2VAR(type, AUTOMATIC, BASE_APPL_DATA))(dst) = (val); \
      /* Deviation MISRA-1 */                                 \
      (dst) += (uint32)sizeof(type);                          \
      (len) -= (uint32)sizeof(type);                          \
    }                                                         \
  }                                                           \
  while (0)

#if (defined TS_MEMCMP_NOCHECK)
#error TS_MEMCMP_NOCHECK is already defined
#endif

/** \brief Compares \p len bytes of memory from \p dst to \p src using
 ** type information passed in \p type.
 **
 ** \pre RetVal should by of type Std_ReturnType
 **
 ** \param[in] a Pointer to the first memory block to compare
 ** \param[in] b Pointer to the second memory block to compare
 ** \param[in] len Amount of bytes to compare
 ** \param[in] RetVal The return value to pass result information
 ** \param[in] type The type to perform the comparison with */
#define TS_MEMCMP_NOCHECK(a, b, len, RetVal, type)                 \
   do {                                                            \
    /* loop and compare */                                         \
     while (((len) >= (uint32)sizeof(type)) && ((RetVal) == E_OK)) \
    {                                                              \
       /* Deviation MISRA-2 <+2> */                                \
       if ((*(P2CONST(type, AUTOMATIC, BASE_APPL_DATA))(a)) !=     \
           *(P2CONST(type, AUTOMATIC, BASE_APPL_DATA))(b))         \
      {                                                            \
        (RetVal) = E_NOT_OK;                                       \
      }                                                            \
      else                                                         \
      {                                                            \
        /* Deviation MISRA-1 <+2> */                               \
        (a) += (uint32)sizeof(type);                               \
        (b) += (uint32)sizeof(type);                               \
        (len) -= (uint32)sizeof(type);                             \
      }                                                            \
    }                                                              \
  } while (0)

#if (defined TS_MEM_IS_32ALIGNED)
#error TS_MEM_IS_32ALIGNED is already defined
#endif

/** \brief Tests if the parameter \p x is 32-bit aligned
 **
 ** \pre An address needs to be convertible to a uint32
 **
 ** \param[in] x the variable to check
 **
 ** \retval 1 the variable is 32-bit aligned
 ** \retval 0 the variable is not 32-bit aligned  */
#define TS_MEM_IS_32ALIGNED(x) (((uint32)(x) & 3U) == 0U)

#if (defined TS_MEM_IS_16ALIGNED)
#error TS_MEM_IS_16ALIGNED is already defined
#endif

/** \brief Tests if the parameter \p x is 16-bit aligned
 **
 ** \pre An address needs to be convertible to a uint32
 **
 ** \param[in] x the variable to check
 **
 ** \retval 1 the variable is 16-bit aligned
 ** \retval 0 the variable is not 16-bit aligned  */
#define TS_MEM_IS_16ALIGNED(x) (((uint32)(x) & 1U) == 0U)

#if (defined TS_MEM_OPT_LEN)
#error TS_MEM_OPT_LEN is already defined
#endif

/** \brief Defines the minimum amount of data to try optimization */
#define TS_MEM_OPT_LEN 16U

#if (defined TS_MEM_IS_ENOUGH_DATA)
#error TS_MEM_IS_ENOUGH_DATA is already defined
#endif

/** \brief tests if there is enough data to use optimization
 **
 ** \param[in] len amount of bytes
 **
 ** \retval 0 there is enough data
 ** \retval 1 not enough data */
#define TS_MEM_IS_ENOUGH_DATA(len) ((len) >= TS_MEM_OPT_LEN)

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

/*------------------[32-bit CPUs]--------------------------------------------*/
#if (CPU_TYPE == CPU_TYPE_32)

/*------------------[TS_MemCpy32]--------------------------------------------*/
/* Deviation MISRA-5 <+5> */
FUNC(void, BASE_CODE) TS_MemCpy32
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) src,
  const uint32 len
)
{
  /* define pointers for access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) src2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) src;
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* check if enough data is there for optimizing */
  if (TS_MEM_IS_ENOUGH_DATA(len2))
  {
    /* check if src and dst are both 32-bit aligned */
    /* Deviation MISRA-3 */
    if (TS_MEM_IS_32ALIGNED(src2) && TS_MEM_IS_32ALIGNED(dst2))
    {
       /* copy as much data in 32-bit mode */
       /* Deviation MISRA-1, MISRA-4, MISRA-6 */
       TS_MEMCPY_NOCHECK(dst2, src2, len2, uint32);
    }
    /* check if src and dst are both 16-bit aligned */
    /* Deviation MISRA-3 */
    else if (TS_MEM_IS_16ALIGNED(src2) && TS_MEM_IS_16ALIGNED(dst2))
    {
      /* try to copy the data using 16-bit-wise copy */
      /* Deviation MISRA-1, MISRA-4, MISRA-6 */
      TS_MEMCPY_NOCHECK(dst2, src2, len2, uint16);
    }
    else
    {
      /* for MISRA */
    }
  }

  /* optimized case:   copy the rest byte-wise
   * unoptimized case: copy everything byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint8);
}

/*------------------[TS_MemSet32]--------------------------------------------*/
/* Deviation MISRA-5 <+5> */
FUNC(void, BASE_CODE) TS_MemSet32
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const uint32 len
)
{
  /* define pointer for access */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* check if enough data is there for optimizing */
  if (TS_MEM_IS_ENOUGH_DATA(len2))
  {
    /* check if dst is 32-bit aligned */
    /* Deviation MISRA-3 */
    if (TS_MEM_IS_32ALIGNED(dst2))
    {
      /* construct a 32-bit value from the 8-bit input */
      const uint32 val2 =  (uint32)val         | ((uint32)val << 8U)  |
                          ((uint32)val << 16U) | ((uint32)val << 24U);

      /* assign data in 32-bit mode */
      /* Deviation MISRA-1, MISRA-4, MISRA-6 */
      TS_MEMSET_NOCHECK(dst2, val2, len2, uint32);
    }
    /* check if dst is 16-bit aligned */
    /* Deviation MISRA-3 */
    else if (TS_MEM_IS_16ALIGNED(dst2))
    {
      /* construct a 16-bit value from the 8-bit input */
      const uint16 val2 = (uint16)val | (uint16)((uint16)val << 8U);

      /* assign data in 16-bit mode */
      /* Deviation MISRA-1, MISRA-4, MISRA-6 */
      TS_MEMSET_NOCHECK(dst2, val2, len2, uint16);
    }
    else
    {
      /* for MISRA */
    }
  }

  /* optimized case:   assign the rest byte-wise
   * unoptimized case: assign everything byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, val, len2, uint8);
}

/*------------------[TS_MemBZero32]------------------------------------------*/
/* Deviation MISRA-5 <+5> */
FUNC(void, BASE_CODE) TS_MemBZero32
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint32 len
)
{
  /* define pointer for access */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* check if enough data is there for optimizing */
  if (TS_MEM_IS_ENOUGH_DATA(len2))
  {
    /* check if dst is 32-bit aligned */
    /* Deviation MISRA-3 */
    if (TS_MEM_IS_32ALIGNED(dst2))
    {
      /* assign data in 32-bit mode */
      /* Deviation MISRA-1, MISRA-4, MISRA-6 */
      TS_MEMSET_NOCHECK(dst2, 0U, len2, uint32);
    }
    /* check if dst is 16-bit aligned */
    /* Deviation MISRA-3 */
    else if (TS_MEM_IS_16ALIGNED(dst2))
    {
      /* assign data in 16-bit mode */
      /* Deviation MISRA-1, MISRA-4, MISRA-6 */
      TS_MEMSET_NOCHECK(dst2, 0U, len2, uint16);
    }
    else
    {
      /* for MISRA */
    }
  }

  /* optimized case:   assign the rest byte-wise
   * unoptimized case: assign everything byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, 0U, len2, uint8);
}

/*------------------[TS_MemCmp32]--------------------------------------------*/
FUNC(Std_ReturnType, BASE_CODE) TS_MemCmp32
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const uint32 len
)
{
  /* define type specific pointers for suitable access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  uint32 len2 = len;
  Std_ReturnType RetVal = E_OK;

  /* check if enough data is there for optimizing */
  if (TS_MEM_IS_ENOUGH_DATA(len2))
  {
    /* check if a and b are both 32-bit aligned */
    /* Deviation MISRA-3 */
    if (TS_MEM_IS_32ALIGNED(a2) && TS_MEM_IS_32ALIGNED(b2))
    {
      /* compare data in 32-bit mode */
      /* Deviation MISRA-1, MISRA-4, MISRA-6 */
      TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint32);

    }
    /* check if a and b are both 16-bit aligned */
    /* Deviation MISRA-3 */
    else if (TS_MEM_IS_16ALIGNED(a2) && TS_MEM_IS_16ALIGNED(b2))
    {
      /* compare data in 16-bit mode */
      /* Deviation MISRA-1, MISRA-4, MISRA-6 */
      TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint16);
    }
    else
    {
      /* for MISRA */
    }
  }

  /* the optimized compare macros may have already found a
   * difference, so we have to compare again */
  if (RetVal == E_OK)
  {
    /* optimized case:   compare the rest byte-wise
     * unoptimized case: compare everything byte-wise */
    /* Deviation MISRA-1, MISRA-6 */
    TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint8);
  }

  return RetVal;
}

#elif (CPU_TYPE == CPU_TYPE_16)
/*------------------[16-bit CPUs]--------------------------------------------*/

/*------------------[TS_MemCpy16]--------------------------------------------*/
FUNC(void, BASE_CODE) TS_MemCpy16
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) src,
  const uint32 len
)
{
  /* define pointers for access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) src2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) src;
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* check if enough data is there for optimizing */
  if (TS_MEM_IS_ENOUGH_DATA(len2))
  {
    /* check if src and dst are both 16-bit aligned */
    /* Deviation MISRA-3 */
    if (TS_MEM_IS_16ALIGNED(src2) && TS_MEM_IS_16ALIGNED(dst2))
    {
      /* try to copy the data using 16-bit-wise copy */
      /* Deviation MISRA-1, MISRA-4, MISRA-6 */
      TS_MEMCPY_NOCHECK(dst2, src2, len2, uint16);
    }
  }

  /* optimized case:   copy the rest byte-wise
   * unoptimized case: copy everything byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint8);
}

/*------------------[TS_MemSet16]--------------------------------------------*/
FUNC(void, BASE_CODE) TS_MemSet16
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const uint32 len
)
{
  /* define pointer for access */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* check if enough data is there for optimizing */
  if (TS_MEM_IS_ENOUGH_DATA(len2))
  {
    /* check if dst is 16-bit aligned */
    /* Deviation MISRA-3 */
    if (TS_MEM_IS_16ALIGNED(dst2))
    {
      /* construct a 16-bit value from the 8-bit input */
      const uint16 val2 = (uint16)val | (uint16)((uint16)val << 8U);

      /* assign data in 16-bit mode */
      /* Deviation MISRA-1, MISRA-4, MISRA-6 */
      TS_MEMSET_NOCHECK(dst2, val2, len2, uint16);
    }
  }

  /* optimized case:   assign the rest byte-wise
   * unoptimized case: assign everything byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, val, len2, uint8);
}

/*------------------[TS_MemBZero16]------------------------------------------*/
FUNC(void, BASE_CODE) TS_MemBZero16
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint32 len
)
{
  /* define pointer for access */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* check if enough data is there for optimizing */
  if (TS_MEM_IS_ENOUGH_DATA(len2))
  {
    /* check if dst is 16-bit aligned */
    /* Deviation MISRA-3 */
    if (TS_MEM_IS_16ALIGNED(dst2))
    {
      /* assign data in 16-bit mode */
      /* Deviation MISRA-1, MISRA-4, MISRA-6 */
      TS_MEMSET_NOCHECK(dst2, 0U, len2, uint16);
    }
  }

  /* optimized case:   assign the rest byte-wise
   * unoptimized case: assign everything byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, 0U, len2, uint8);
}

/*------------------[TS_MemCmp16]--------------------------------------------*/
FUNC(Std_ReturnType, BASE_CODE) TS_MemCmp16
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const uint32 len
)
{
  /* define type specific pointers for suitable access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  uint32 len2 = len;
  Std_ReturnType RetVal = E_OK;

  /* check if enough data is there for optimizing */
  if (TS_MEM_IS_ENOUGH_DATA(len2))
  {
    /* check if a and b are both 16-bit aligned */
    /* Deviation MISRA-3 */
    if (TS_MEM_IS_16ALIGNED(a2) && TS_MEM_IS_16ALIGNED(b2))
    {
      /* compare as much data in 16-bit mode */
      /* Deviation MISRA-1, MISRA-4, MISRA-6 */
      TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint16);
    }
  }

  /* the optimized compare macros may have already found a
   * difference, so we have to compare again */
  if (RetVal == E_OK)
  {
    /* optimized case:   compare the rest byte-wise
     * unoptimized case: compare everything byte-wise */
    /* Deviation MISRA-1, MISRA-6 */
    TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint8);
  }

  return RetVal;
}

#elif (CPU_TYPE == CPU_TYPE_8)
/*------------------[8-bit CPUs]---------------------------------------------*/

/*------------------[TS_MemCpy8]---------------------------------------------*/
FUNC(void, BASE_CODE) TS_MemCpy8
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) src,
  const uint32 len
)
{
  /* define pointers for access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) src2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) src;
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* copy everything byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint8);
}

/*------------------[TS_MemSet8]---------------------------------------------*/
FUNC(void, BASE_CODE) TS_MemSet8
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const uint32 len
)
{
  /* define pointer for access */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* assign everything byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, val, len2, uint8);
}

/*------------------[TS_MemBZero8]-------------------------------------------*/
FUNC(void, BASE_CODE) TS_MemBZero8
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint32 len
)
{
  /* define pointer for access */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* fill the buffer byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, 0U, len2, uint8);
}

/*------------------[TS_MemCmp8]---------------------------------------------*/
FUNC(Std_ReturnType, BASE_CODE) TS_MemCmp8
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const uint32 len
)
{
  /* define type specific pointers for suitable access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  uint32 len2 = len;
  Std_ReturnType RetVal = E_OK;

  /* compare everything byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint8);

  return RetVal;
}

#endif /* CPU_TYPE */

/*------------------[TS_MemMove]---------------------------------------------*/
/* Deviation MISRA-5 <+5> */
FUNC(void, BASE_CODE) TS_MemMove
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) src,
  const uint32 len
)
{
  /* define uint8 pointers for byte-wise access */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) src2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) src;
  uint32 len2 = len;

  /* if the start of the source block is "behind" the start of the destination
   * block, it is safe to copy 'forewards' ... */
  if (src2 > dst2)
  {
    for (len2 = len; len2 != 0U; len2--)
    {
      *dst2 = *src2;
      /* Deviation MISRA-1 <+2> */
      dst2++;
      src2++;
    }
  }

  /* ... and if the start of the source block is "before" the start of the destination
   * block, it is safe to copy 'backwards' ... */
  else if (src2 < dst2)
  {
    /* Deviation MISRA-1 <+2>, MISRA-6 <+2> */
    dst2 += len2 - 1U;
    src2 += len2 - 1U;

    for (len2 = len; len2 != 0U; len2--)
    {
      *dst2 = *src2;
      /* Deviation MISRA-1 <+2> */
      dst2--;
      src2--;
    }
  }

  /* ... otherwise the pointers are equal and there is no need to copy. */
  else
  {
    /* MISRA */
  }
}

/*------------------[TS_MemCpy32_NoCheck]------------------------------------*/
/* Deviation MISRA-5 <+5> */
FUNC(void, BASE_CODE) TS_MemCpy32_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) src,
  const uint32 len
)
{
  /* define pointers for access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) src2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) src;
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* copy as much data in 32-bit mode */
  /* Deviation MISRA-1, MISRA-4, MISRA-6  */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint32);

  /* copy the remaining parts byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint8);
}

/*------------------[TS_MemSet32_NoCheck]------------------------------------*/
/* Deviation MISRA-5 <+5> */
FUNC(void, BASE_CODE) TS_MemSet32_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const uint32 len
)
{
  /* define pointer for access */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* construct a 32-bit value from the 8-bit input */
  const uint32 val2 =  (uint32)val         | ((uint32)val << 8U)  |
                      ((uint32)val << 16U) | ((uint32)val << 24U);

  /* assign data in 32-bit mode */
  /* Deviation MISRA-1, MISRA-4, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, val2, len2, uint32);

  /* fill the remaining parts byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, val, len2, uint8);
}

/*------------------[TS_MemBZero32_NoCheck]----------------------------------*/
/* Deviation MISRA-5 <+5> */
FUNC(void, BASE_CODE) TS_MemBZero32_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint32 len
)
{
  /* define pointer for access */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* fill data in 32-bit mode */
  /* Deviation MISRA-1, MISRA-4, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, 0U, len2, uint32);

  /* fill the remaining parts byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, 0U, len2, uint8);
}

/*------------------[TS_MemCmp32_NoCheck]------------------------------------*/
FUNC(Std_ReturnType, BASE_CODE) TS_MemCmp32_NoCheck
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const uint32 len
)
{
  /* define type specific pointers for suitable access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  uint32 len2 = len;
  Std_ReturnType RetVal = E_OK;

  /* Deviation MISRA-1, MISRA-4, MISRA-6 */
  TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint32);

  /* the optimized compare macros may have already found a
   * difference, so we have to compare again */
  if (RetVal == E_OK)
  {
    /* compare the rest byte-wise */
    /* Deviation MISRA-1, MISRA-6 */
    TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint8);
  }

  return RetVal;
}

/*------------------[TS_MemCpy16_NoCheck]------------------------------------*/
/* Deviation MISRA-5 <+5> */
FUNC(void, BASE_CODE) TS_MemCpy16_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) src,
  const uint32 len
)
{
  /* define pointers for access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) src2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) src;
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* copy as much as possible in 16-bit mode */
  /* Deviation MISRA-1, MISRA-4, MISRA-6 */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint16);

  /* copy the rest byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint8);
}

/*------------------[TS_MemSet16_NoCheck]------------------------------------*/
/* Deviation MISRA-5 <+5> */
FUNC(void, BASE_CODE) TS_MemSet16_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const uint32 len
)
{
  /* define pointer for access */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* construct a 16-bit value from the 8-bit input */
  const uint16 val2 = (uint16)val | (uint16)((uint16)val << 8U);

  /* assign data in 16-bit mode */
  /* Deviation MISRA-1, MISRA-4, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, val2, len2, uint16);

  /* fill the rest byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, val, len2, uint8);
}

/*------------------[TS_MemBZero16_NoCheck]----------------------------------*/
/* Deviation MISRA-5 <+5> */
FUNC(void, BASE_CODE) TS_MemBZero16_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint32 len
)
{
  /* define pointer for access */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  uint32 len2 = len;

  /* assign data in 16-bit mode */
  /* Deviation MISRA-1, MISRA-4, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, 0U, len2, uint16);

  /* fill the rest byte-wise */
  /* Deviation MISRA-1, MISRA-6 */
  TS_MEMSET_NOCHECK(dst2, 0U, len2, uint8);
}

/*------------------[TS_MemCmp16_NoCheck]------------------------------------*/
FUNC(Std_ReturnType, BASE_CODE) TS_MemCmp16_NoCheck
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const uint32 len
)
{
  /* define type specific pointers for suitable access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  uint32 len2 = len;
  Std_ReturnType RetVal = E_OK;

  /* compare as much data in 16-bit mode as possible */
  /* Deviation MISRA-1, MISRA-4, MISRA-6 */
  TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint16);

  /* the optimized compare macros may have already found a
   * difference, so we have to compare again */
  if (RetVal == E_OK)
  {
    /* compare the rest byte-wise */
    /* Deviation MISRA-1, MISRA-6 */
    TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint8);
  }

  return RetVal;
}

/*==================[internal function definitions]==========================*/

#define BASE_STOP_SEC_CODE
#include <MemMap.h>

/*==================[end of file]============================================*/

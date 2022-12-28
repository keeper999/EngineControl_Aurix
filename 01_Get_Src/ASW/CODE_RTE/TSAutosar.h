#if (!defined TS_AUTOSAR_H)
#define TS_AUTOSAR_H

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

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 14.1: (required)
 *   "There shall be no unreachable code."
 *
 *     Reason:
 *     In order to provide a generic macro handling the
 *     clearing/setting of bits in integral data types of different
 *     width, the exact width of the data has to be queried and
 *     depending on the width the appropriate (possibly optimized)
 *     variant of the macro shall be invoked. - Since the data type
 *     however is know to the compiler, this results in unreachable
 *     code that will be removed by the compiler (which is exactly the
 *     desired behavior).
 *
 * MISRA-2) Deviated Rule: 19.10
 * In the definition of a function-like macro each instance of a parameter
 * shall be enclosed in parentheses.
 *
 * Reason: The parameters are passed to another macro where they are
 * correctly enclosed in parentheses.
 *
 * MISRA-3) Deviated Rule: 19.13
 * The # and ## preprocessor operators should not be used.
 *
 * Reason: The operators are used to add the 'U' or 'UL' suffix to constants
 * which can only be performed using the '##' operator.
 */

/*==================[inclusions]=============================================*/

#include <Std_Types.h>   /* Autosar standard data types */
#include <TSAutosar_Cfg.h> /* Non-Autosar platform specific definitions */
#include <TSPlatforms.h> /* Non-Autosar platform specific definitions */

/*==================[macros]=================================================*/

//#define RTE_VENDOR_ID                         1U
//#define RTE_AR_RELEASE_MAJOR_VERSION          4U
//#define RTE_AR_RELEASE_MINOR_VERSION          0U
//#define RTE_AR_RELEASE_REVISION_VERSION       3U
//#define RTE_SW_MAJOR_VERSION                  6U
//#define RTE_SW_MINOR_VERSION                  1U
//#define RTE_SW_PATCH_VERSION                  11U

/*------------------[macros set on the command line]-------------------------*/

#if (!defined TS_ARCH_FAMILY)
/** \brief Provides the target architecture family name */
//#error TS_ARCH_FAMILY must be defined on the commandline
#endif

#if (!defined TS_ARCH_DERIVATE)
/** \brief Provides the target derivate name */
//#error TS_ARCH_DERIVATE must be defined on the commandline
#endif

#define E_REQUEST_NOT_ACCEPTED       8U
#define E_PROTOCOL_NOT_ALLOWED       5U
#define E_PENDING                   10U
#define E_COMPARE_KEY_FAILED        11U 
#define E_FORCE_RCRRP               12U

#define DCM_SEC_LEV_LOCKED           0U  
#define DCM_SEC_LEV_L1               1U
#define DCM_SEC_LEV_ALL            255U

#define DCM_OBD_ON_CAN               0U
#define DCM_OBD_ON_FLEXRAY           1U
#define DCM_OBD_ON_IP                2U 
#define DCM_UDS_ON_CAN               3U
#define DCM_UDS_ON_FLEXRAY           4U
#define DCM_UDS_ON_IP                5U
#define DCM_ROE_ON_CAN               6U
#define DCM_ROE_ON_FLEXRAY           7U     
#define DCM_ROE_ON_IP                8U
#define DCM_UDS_ON_IP                5U
#define DCM_PERIODICTRANS_ON_CAN     9U
#define DCM_PERIODICTRANS_ON_FLEXRAY 10U
#define DCM_PERIODICTRANS_ON_IP      11U
#define DCM_SUPPLIER_1              240U
#define DCM_SUPPLIER_2              241U
#define DCM_SUPPLIER_3              242U
#define DCM_SUPPLIER_4              243U
#define DCM_SUPPLIER_5              244U 
#define DCM_SUPPLIER_6              245U
#define DCM_SUPPLIER_7              246U
#define DCM_SUPPLIER_8              247U
#define DCM_SUPPLIER_9              248U
#define DCM_SUPPLIER_10             249U 
#define DCM_SUPPLIER_11             250U
#define DCM_SUPPLIER_12             251U
#define DCM_SUPPLIER_13             252U
#define DCM_SUPPLIER_14             253U
#define DCM_SUPPLIER_15             254U 
 
//#define RTE_PTR2ARRAYTYPE_PASSING

#define DeclareEvent(event) 


#define Rte_TriggerTaskAlarm_0_0     1U
#define Rte_TriggerTaskAlarm_1_0     2U
#define Rte_TriggerTaskAlarm_2       3U
#define Rte_TriggerTaskAlarm_3       4U
#define Rte_TriggerTaskAlarm_4       3U
#define Rte_TriggerTaskAlarm_5       4U
#define Rte_TriggerTaskAlarm_6       3U
#define Rte_TriggerTaskAlarm_7       4U
#define Rte_TriggerTaskAlarm_8       3U
#define Rte_OSTimingEvent_0_0        0U
#define Rte_OSShutdownEvent          0U
#define OsTask_10ms                  0U
#define Rte_OSTimingEvent_1_0        0U
#define OsTask_40ms                  0U


/*------------------[architecture names]-------------------------------------*/

/* definition of architecture names */
#define TS_C16X        1U
#define TS_PA          2U
#define TS_EXCALIBUR   3U
#define TS_F2MC16L     4U
#define TS_MB91        5U
#define TS_H8          6U
#define TS_HC08        7U
#define TS_HC12        8U
#define TS_M32C        9U
#define TS_NEC78K     10U
#define TS_S12X       11U
#define TS_SAF7780    12U
#define TS_SH2        13U
#define TS_ST30       14U
#define TS_TMS470     15U
#define TS_TRICORE    16U
#define TS_V850       17U
#define TS_XC16X      18U
#define TS_WINDOWS    19U
#define TS_XC2000     20U
#define TS_R32C       21U
#define TS_MPC551X    22U
#define TS_EASYCAN    23U
#define TS_XPC56XX    24U
#define TS_M32R       25U
#define TS_PIC24H     26U
#define TS_NIOS2      27U
#define TS_MB96       28U
#define TS_SH4        29U
#define TS_EBX1XX     30U
#define TS_ARM        31U
#define TS_FCR4       32U
#define TS_PIKEOS     33U

/* Sanity checks for Atomic macros */
#if !( defined(TS_IntDisable) && defined(TS_IntRestore) )
#error "TSPlatforms.h is not correctly implemented"
#endif

#if (defined TS_PARAM_UNUSED)
#error TS_PARAM_UNUSED already defined
#endif

#if (defined EB_STATIC_CHECK)
/** \brief This macro can be used to avoid compiler warnings
 * It is left empty to not product a false positive for MISRA 14.2 */
#define TS_PARAM_UNUSED(x)
#else
/** \brief This macro can be used to avoid compiler warnings */
#define TS_PARAM_UNUSED(x) ((void) (x))
#endif

/* if a translation unit includes multiple C-Files, it will set this macro to STD_ON */
#ifndef TS_MERGED_COMPILE

/** \brief All source files are built seperately by default */
#define TS_MERGED_COMPILE STD_OFF

#endif /* TS_MERGED_COMPILE */

#if (TS_MERGED_COMPILE == STD_ON)

/** \brief Use internal linkage of function declarations, if merged, fast build is used */
#define TS_MOD_PRIV_DECL STATIC
/** \brief Use internal linkage of function definitions, if merged, fast build is used */
#define TS_MOD_PRIV_DEFN STATIC

#else /* TS_MERGED_COMPILE */

/** \brief Use external linkage of function declarations, if normal build is used */
#define TS_MOD_PRIV_DECL extern
/** \brief Use external linkage of function declarations, if normal build is used */
#define TS_MOD_PRIV_DEFN

#endif /* TS_MERGED_COMPILE */

#if (defined TS_VENDOR_ID_3SOFT)
#error TS_VENDOR_ID_3SOFT already defined
#endif

/** \brief definition of the unique vendor ID
 *
 * This vendor ID is based on the vendor ID published by the HIS.
 * It should be used for each module */
#define TS_VENDOR_ID_3SOFT 1U

#if (defined TS_VENDOR_ID_EB)
#error TS_VENDOR_ID_EB already defined
#endif

/** \brief map vendor ID of EB to 3SOFT */
#define TS_VENDOR_ID_EB TS_VENDOR_ID_3SOFT

#if (defined TS_PROD_ERR_REP_TO_DEM)
#error TS_PROD_ERR_REP_TO_DEM already defined
#endif

/** \brief definition of production error reporting defines - report to Dem
 *
 * The production error reporting could be configured to Dem, Det and off.
 * TS_PROD_ERR_REP_TO_DEM is used if the production error is reported
 * towards the Dem. */
#define TS_PROD_ERR_REP_TO_DEM 0U

#if (defined TS_PROD_ERR_REP_TO_DET)
#error TS_PROD_ERR_REP_TO_DET already defined
#endif

/** \brief definition of production error reporting defines - report to Det
 *
 * The production error reporting could be configured to Dem, Det and off.
 * TS_PROD_ERR_REP_TO_DET is used if the production error is reported
 * towards the Det. */
#define TS_PROD_ERR_REP_TO_DET 1U

#if (defined TS_PROD_ERR_DISABLE)
#error TS_PROD_ERR_DISABLE already defined
#endif

/** \brief definition of production error reporting defines - off
 *
 * The production error reporting could be configured to Dem, Det and off.
 * TS_PROD_ERR_DISABLE is used if the production error reporting is
 * switched off. */
#define TS_PROD_ERR_DISABLE 2U

/*------------------[UINTX_C macros]-----------------------------------------*/

#if (!defined UINT8_C)
/* Deviation MISRA-3 <+2> */
/** \brief Macro to define a constant of type uint8 */
#define UINT8_C(x) ((uint8) x ## U)
#endif

#if (!defined UINT16_C)
/* Deviation MISRA-3 <+2> */
/** \brief Macro to define a constant of type uint16 */
#define UINT16_C(x) ((uint16) x ## U)
#endif

#if (!defined UINT32_C)
/* Deviation MISRA-3 <+2> */
/** \brief Macro to define a constant of type uint32 */
#define UINT32_C(x) (x ## UL)
#endif

#if (!defined SINT8_C)
/** \brief Macro to define a constant of type sint8 */
#define SINT8_C(x) ((sint8)(x))
#endif

#if (!defined SINT16_C)
/** \brief Macro to define a constant of type sint16 */
#define SINT16_C(x) ((sint16)(x))
#endif

#if (!defined SINT32_C)
/* Deviation MISRA-3 <+2> */
/** \brief Macro to define a constant of type sint32 */
#define SINT32_C(x) (x ## L)
#endif

/*------------------[Bit library macros]-------------------------------------*/

/*------------------[TS_GetBit]----------------------------------------------*/
#if (!defined TS_GetBit)

/** \brief Extracts a bit from a variable of type \p OpType
 **
 ** This functions returns the bit number \p Bit from the variable
 ** of type \p OpType pointed to by \p Address.
 **
 ** The parameter \p OpType can either be \p uint8, \p uint16
 ** or \p uint32.
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to an object of type \p OpType
 ** \pre depending on the value of \p OpType, the parameter \p Bit
 **   shall have the following range:
 **   \p uint8: 0..7, \p uint16: 0..15, \p uint32: 0..31
 ** \pre \p OpType shall be one of \p uint8, \p uint16 or \p uint32
 ** \pre \p Result shall be a modifiable variable of type \p OpType.
 **
 ** \param[in]  Address pointer to the variable of type OpType *
 ** \param[in]  Bit     number of the bit to extract
 ** \param[in]  OpType  type of this whole operation
 ** \param[out] Result  variable of type \p OpType to store result
 **
 ** \remarks The parameters of this macro may be used in any way, especially
 **   they can be used more than once. They shall not contain side effects. */
#define TS_GetBit(Address,Bit,OpType,Result)         \
  ((Result) = (OpType) ((*(Address) & ((OpType)(1U<<(Bit)))) != 0U))

#endif

/*------------------[TS_GetBitGroup]-----------------------------------------*/
#if (!defined TS_GetBitGroup)
/** \brief Gets the level of a group of bits
 **
 ** This macro extracts the level of several consecutive bits indicated
 ** by \p Mask and \p Offset from the variable pointed to by \p Address.
 **
 ** Preconditions:
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a variable of type \p OpType
 ** \pre \p Mask shall be of type \p OpType
 ** \pre Depending on the type of \p OpType, the
 **   parameter \p Offset shall have the following range:
 **   \p uint8: 0..7, \p uint16: 0..15, \p uint32: 0..31
 ** \pre \p OpType shall be one of \p uint8, \p uint16 or \p uint32
 ** \pre \p Result shall be a modifiable variable of type \p OpType
 **
 ** \param[in]  Address pointer to the register to extract the information
 ** \param[in]  Mask    describes the consecutive bits, type OpType
 ** \param[in]  Offset  describes the bit positions, range: see above
 ** \param[in]  OpType  gives the type of the operation
 ** \param[out] Result  output parameter holding the result
 **
 ** \remarks The parameters of this macro may be used in any way, especially
 **   they can be used more than once. They shall not contain side effects. */
#define TS_GetBitGroup(Address,Mask,Offset,OpType,Result) \
  ((Result) = (OpType) (((OpType)(*(Address))) & (OpType)(Mask)) >> (Offset))

#endif

/*------------------[TS_AtomicSetBit_8]-------------------------------------*/
#if (!defined TS_AtomicSetBit_8)

/** \brief Set one bit of a 8 bit variable
 **
 ** This macro sets the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT : the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to set, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change */
#define TS_AtomicSetBit_8(Address, Bit)                         \
  do {                                                          \
    TS_IntStatusType TS_AtomicSetBitSave = TS_IntDisable();     \
    *(Address) |= (uint8)(1U << (Bit));                         \
    TS_IntRestore(TS_AtomicSetBitSave);                         \
  } while (0)

#endif

/*------------------[TS_AtomicSetBit_16]-------------------------------------*/
#if (!defined TS_AtomicSetBit_16)

/** \brief Set one bit of a 16 bit variable
 **
 ** This macro sets the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT : the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to set, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change */
#define TS_AtomicSetBit_16(Address, Bit)                        \
  do {                                                          \
    TS_IntStatusType TS_AtomicSetBitSave = TS_IntDisable();     \
    *(Address) |= (uint16)(1U << (Bit));                        \
    TS_IntRestore(TS_AtomicSetBitSave);                         \
  } while (0)

#endif

/*------------------[TS_AtomicSetBit_32]-------------------------------------*/
#if (!defined TS_AtomicSetBit_32)

/** \brief Set one bit of a 32 bit variable
 **
 ** This macro sets the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT : the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to set, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change */
#define TS_AtomicSetBit_32(Address, Bit)                        \
  do {                                                          \
    TS_IntStatusType TS_AtomicSetBitSave = TS_IntDisable();     \
    *(Address) |= (uint32)(1U << (Bit));                        \
    TS_IntRestore(TS_AtomicSetBitSave);                         \
  } while (0)

#endif

/*------------------[TS_AtomicSetBit]----------------------------------------*/
#if (!defined TS_AtomicSetBit)

/** \brief Set one bit of a variable
 **
 ** This macro sets the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT : the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to set, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change */
/* Deviation MISRA-1 <+15> */
#define TS_AtomicSetBit(Address, Bit)                           \
  do {                                                          \
    if (sizeof(*(Address)) == 1U)                               \
    {                                                           \
      TS_AtomicSetBit_8(Address, Bit);                          \
    }                                                           \
    else if (sizeof(*(Address)) == 2U)                          \
    {                                                           \
      TS_AtomicSetBit_16(Address, Bit);                         \
    }                                                           \
    else                                                        \
    {                                                           \
      TS_AtomicSetBit_32(Address, Bit);                         \
    }                                                           \
  } while (0)

#endif

/*------------------[TS_AtomicClearBit_32]-----------------------------------*/
#if (!defined TS_AtomicClearBit_8)

/** \brief Clear one bit of a 8 bit variable
 **
 ** This macro clears the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT: the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to clear, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change */
#define TS_AtomicClearBit_8(Address, Bit)                       \
  do {                                                          \
    TS_IntStatusType TS_AtomicClearBitSave = TS_IntDisable();   \
    *(Address) &= (uint8) ~((uint8)(1U << (Bit)));              \
    TS_IntRestore(TS_AtomicClearBitSave);                       \
  } while (0)

#endif

/*------------------[TS_AtomicClearBit_16]-----------------------------------*/
#if (!defined TS_AtomicClearBit_16)

/** \brief Clear one bit of a 16 bit variable
 **
 ** This macro clears the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT: the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to clear, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change */
#define TS_AtomicClearBit_16(Address, Bit)                      \
  do {                                                          \
    TS_IntStatusType TS_AtomicClearBitSave = TS_IntDisable();   \
    *(Address) &= (uint16) ~((uint16)(1U << (Bit)));            \
    TS_IntRestore(TS_AtomicClearBitSave);                       \
  } while (0)

#endif

/*------------------[TS_AtomicClearBit_32]-----------------------------------*/
#if (!defined TS_AtomicClearBit_32)

/** \brief Clear one bit of a 32 bit variable
 **
 ** This macro clears the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT: the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to clear, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change */
#define TS_AtomicClearBit_32(Address, Bit)                      \
  do {                                                          \
    TS_IntStatusType TS_AtomicClearBitSave = TS_IntDisable();   \
    *(Address) &= (uint32) ~((uint32)(1U << (Bit)));            \
    TS_IntRestore(TS_AtomicClearBitSave);                       \
  } while (0)

#endif

/*------------------[TS_AtomicClearBit]--------------------------------------*/
#if (!defined TS_AtomicClearBit)

/** \brief Clear one bit of a variable
 **
 ** This macro clears the bit \p Bit in the variable referenced
 ** by \p Address.
 ** It is an atomic load-and-store operation, in that software cannot
 ** interrupt between the load and the store and make modifications
 ** to the variable which would have be discarded by the store.
 **
 ** CAVEAT: the operation is not atomic where hardware outside the CPU
 ** can modify the variable (for example, multicore architecture, DMA,
 ** shared bus systems)
 **
 ** \pre \p Address shall be a valid pointer
 ** \pre \p Address shall point to a modifiable location
 ** \pre \p Bit shall have a value between 0 and n-1, where n is the number
 ** of bits of the variable referenced by \p Address
 **
 ** \param[in]  Bit     the bit to clear, range: 0 .. n-1
 ** \param[out] Address constant pointer to the variable to change */
/* Deviation MISRA-1 <+15> */
#define TS_AtomicClearBit(Address, Bit)                         \
  do {                                                          \
    if ( sizeof(*(Address)) == 1U)                              \
    {                                                           \
      TS_AtomicClearBit_8(Address, Bit);                        \
    }                                                           \
    else if (sizeof(*(Address)) == 2U)                          \
    {                                                           \
      TS_AtomicClearBit_16(Address, Bit);                       \
    }                                                           \
    else                                                        \
    {                                                           \
      TS_AtomicClearBit_32(Address, Bit);                       \
    }                                                           \
  } while (0)

#endif


/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[external data]==========================================*/

#endif /* if (!defined TS_AUTOSAR_H) */

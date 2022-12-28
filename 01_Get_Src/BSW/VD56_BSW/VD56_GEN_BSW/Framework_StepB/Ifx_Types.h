/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : IFX_CFG                                                 */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFX_TYPES.h                                             */
/* !Description     : Types definition used in framework software             */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A111649.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFX_TYPES_H
#define IFX_TYPES_H

/******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Data Types                                     **
**                      (Types not defined by AUTOSAR)                        **
*******************************************************************************/
typedef signed long long    sint64;         /**< \brief -9223372036854775808 .. +9223372036854775807     */
typedef unsigned long long  uint64;         /**< \brief                    0 .. 18446744073709551615     */

typedef const char*         pchar;          /**< \brief const char pointer                               */
typedef void*               pvoid;          /**< \brief void pointer                                     */
typedef volatile void*      vvoid;          /**< \brief volatile void pointer                            */



typedef sint64 TTime;                       /**< \brief Time in ticks */
#define TIME_INFINITE           ((TTime)0x7FFFFFFFFFFFFFFFLL)
#define TIME_NULL               ((TTime)0x0000000000000000LL)

#define ONES                    (0xFFFFFFFFFFFFFFFFU)
#define ZEROS                   (0x0000000000000000U)

#if CFG_LONG_SIZE_T
#define SIZE_T_MAX              (0x7FFFFFFFL)
typedef sint32                  SizeT;      /**< \brief Type used for data stream size */
#else
#define SIZE_T_MAX              (0x7FFF)
typedef sint16                  SizeT;      /**< \brief Type used for data stream size */
#endif

/** \brief Circular buffer definition. */
typedef struct
{
    void*   base;               /**< \brief buffer base address */
    uint16  index;              /**< \brief buffer current index */
    uint16  length;             /**< \brief buffer length*/
} CircBuf;

typedef uint16 Priority;        /**< \brief Used in interrupt service priorities */
typedef uint32 TimerVal;        /**< \brief Used in timer values */
typedef sint32 SignedTimerVal;  /**< \brief Used in signed timer values */

/** \brief Signal active state definition. */
typedef enum
{
    ActiveState_low = 0,        /**< \brief The signal is low active */
    ActiveState_high = 1        /**< \brief The signal is high active */
} ActiveState;

typedef enum
{
    ParityMode_even = 0,
    ParityMode_odd = 1
} ParityMode;

/** \brief Module address and index map */
typedef struct
{
    volatile void* module;      /**< \brief Module address */
    sint32 index;               /**< \brief Module index */
} IfxModule_IndexMap;


#ifdef __DCC__
#include "Ifx_TypesDcc.h"

#elif defined(__TASKING__)
#include "Ifx_TypesTasking.h"

#elif defined(_GNU_C_TRICORE_)
#include "Ifx_TypesGnuc.h"

#elif defined(__MSVC__)
#include "Ifx_TypesMsvc.h"
#else
#error Unsupported compiler.
#endif


#endif /* IFX_TYPES_H */


/*-------------------------------- end of file -------------------------------*/

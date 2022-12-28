/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXSTM_CFG.h                                            */
/* !Description     : Configuration of framework component managing STM       */
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
 * %PID: P2017_BSW:0A111714.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXSTM_CFG_H
#define IFXSTM_CFG_H
/******************************************************************************/
#include "Ifx_Cfg.h"
#include "IfxStm_reg.h"
#include "Ifx_Types.h"
/******************************************************************************/
/*                           Macro                                            */
/******************************************************************************/
#define IFXSTM_COUNT   (3)               /**< \brief STM count */
/******************************************************************************/
/*                           Enum                                             */
/******************************************************************************/

/* List of the available STM resources
 *
 */
typedef enum
{
    IfxStm_ResourceStm_0 = 0,                            /**< STM 0 */
    IfxStm_ResourceStm_1,                                /**< STM 1 */
    IfxStm_ResourceStm_2,                                /**< STM 2 */
    IfxStm_ResourceStm_none                              /**< None of the STM  */
} IfxStm_ResourceStm;

typedef enum
{
    IfxStm_Comparator_0 = 0,                             /**< Comparator 0 */
    IfxStm_Comparator_1,                                 /**< Comparator 1 */
} IfxStm_Comparator;


typedef enum
{
    IfxStm_ComparatorOffset_0 = 0,                       /**< Comparator start bit position 0 with 64 bit timer */
    IfxStm_ComparatorOffset_1,                           /**< Comparator start bit position1 with 64 bit timer */
    IfxStm_ComparatorOffset_2,                           /**< Comparator start bit position2 with 64 bit timer */
    IfxStm_ComparatorOffset_3,                           /**< Comparator start bit position3 with 64 bit timer */
    IfxStm_ComparatorOffset_4,                           /**< Comparator start bit position4 with 64 bit timer */
    IfxStm_ComparatorOffset_5,                           /**< Comparator start bit position5 with 64 bit timer */
    IfxStm_ComparatorOffset_6,                           /**< Comparator start bit position6 with 64 bit timer */
    IfxStm_ComparatorOffset_7,                           /**< Comparator start bit position7 with 64 bit timer */
    IfxStm_ComparatorOffset_8,                           /**< Comparator start bit position8 with 64 bit timer */
    IfxStm_ComparatorOffset_9,                           /**< Comparator start bit position9 with 64 bit timer */
    IfxStm_ComparatorOffset_10,                           /**< Comparator start bit position10 with 64 bit timer */
    IfxStm_ComparatorOffset_11,                           /**< Comparator start bit position11 with 64 bit timer */
    IfxStm_ComparatorOffset_12,                           /**< Comparator start bit position12 with 64 bit timer */
    IfxStm_ComparatorOffset_13,                           /**< Comparator start bit position13 with 64 bit timer */
    IfxStm_ComparatorOffset_14,                           /**< Comparator start bit position14 with 64 bit timer */
    IfxStm_ComparatorOffset_15,                           /**< Comparator start bit position15 with 64 bit timer */
    IfxStm_ComparatorOffset_16,                           /**< Comparator start bit position16 with 64 bit timer */
    IfxStm_ComparatorOffset_17,                           /**< Comparator start bit position17 with 64 bit timer */
    IfxStm_ComparatorOffset_18,                           /**< Comparator start bit position18 with 64 bit timer */
    IfxStm_ComparatorOffset_19,                           /**< Comparator start bit position19 with 64 bit timer */
    IfxStm_ComparatorOffset_20,                           /**< Comparator start bit position20 with 64 bit timer */
    IfxStm_ComparatorOffset_21,                           /**< Comparator start bit position21 with 64 bit timer */
    IfxStm_ComparatorOffset_22,                           /**< Comparator start bit position22 with 64 bit timer */
    IfxStm_ComparatorOffset_23,                           /**< Comparator start bit position23 with 64 bit timer */
    IfxStm_ComparatorOffset_24,                           /**< Comparator start bit position24 with 64 bit timer */
    IfxStm_ComparatorOffset_25,                           /**< Comparator start bit position25 with 64 bit timer */
    IfxStm_ComparatorOffset_26,                           /**< Comparator start bit position26 with 64 bit timer */
    IfxStm_ComparatorOffset_27,                           /**< Comparator start bit position27 with 64 bit timer */
    IfxStm_ComparatorOffset_28,                           /**< Comparator start bit position28 with 64 bit timer */
    IfxStm_ComparatorOffset_29,                           /**< Comparator start bit position29 with 64 bit timer */
    IfxStm_ComparatorOffset_30,                           /**< Comparator start bit position30 with 64 bit timer */
    IfxStm_ComparatorOffset_31,                           /**< Comparator start bit position31 with 64 bit timer */
} IfxStm_ComparatorOffset;

typedef enum
{
    IfxStm_ComparatorSize_1Bit = 0,                       /**< Size of compare value to compare with timer: 1 bit */
    IfxStm_ComparatorSize_2Bits,                          /**< Size of compare value to compare with timer: 2 bits */
    IfxStm_ComparatorSize_3Bits,                          /**< Size of compare value to compare with timer: 3 bits */
    IfxStm_ComparatorSize_4Bits,                          /**< Size of compare value to compare with timer: 4 bits */
    IfxStm_ComparatorSize_5Bits,                          /**< Size of compare value to compare with timer: 5 bits */
    IfxStm_ComparatorSize_6Bits,                          /**< Size of compare value to compare with timer: 6 bits */
    IfxStm_ComparatorSize_7Bits,                          /**< Size of compare value to compare with timer: 7 bits */
    IfxStm_ComparatorSize_8Bits,                          /**< Size of compare value to compare with timer: 8 bits */
    IfxStm_ComparatorSize_9Bits,                          /**< Size of compare value to compare with timer: 9 bits */
    IfxStm_ComparatorSize_10Bits,                          /**< Size of compare value to compare with timer: 10 bits */
    IfxStm_ComparatorSize_11Bits,                          /**< Size of compare value to compare with timer: 11 bits */
    IfxStm_ComparatorSize_12Bits,                          /**< Size of compare value to compare with timer: 12 bits */
    IfxStm_ComparatorSize_13Bits,                          /**< Size of compare value to compare with timer: 13 bits */
    IfxStm_ComparatorSize_14Bits,                          /**< Size of compare value to compare with timer: 14 bits */
    IfxStm_ComparatorSize_15Bits,                          /**< Size of compare value to compare with timer: 15 bits */
    IfxStm_ComparatorSize_16Bits,                          /**< Size of compare value to compare with timer: 16 bits */
    IfxStm_ComparatorSize_17Bits,                          /**< Size of compare value to compare with timer: 17 bits */
    IfxStm_ComparatorSize_18Bits,                          /**< Size of compare value to compare with timer: 18 bits */
    IfxStm_ComparatorSize_19Bits,                          /**< Size of compare value to compare with timer: 19 bits */
    IfxStm_ComparatorSize_20Bits,                          /**< Size of compare value to compare with timer: 20 bits */
    IfxStm_ComparatorSize_21Bits,                          /**< Size of compare value to compare with timer: 21 bits */
    IfxStm_ComparatorSize_22Bits,                          /**< Size of compare value to compare with timer: 22 bits */
    IfxStm_ComparatorSize_23Bits,                          /**< Size of compare value to compare with timer: 23 bits */
    IfxStm_ComparatorSize_24Bits,                          /**< Size of compare value to compare with timer: 24 bits */
    IfxStm_ComparatorSize_25Bits,                          /**< Size of compare value to compare with timer: 25 bits */
    IfxStm_ComparatorSize_26Bits,                          /**< Size of compare value to compare with timer: 26 bits */
    IfxStm_ComparatorSize_27Bits,                          /**< Size of compare value to compare with timer: 27 bits */
    IfxStm_ComparatorSize_28Bits,                          /**< Size of compare value to compare with timer: 28 bits */
    IfxStm_ComparatorSize_29Bits,                          /**< Size of compare value to compare with timer: 29 bits */
    IfxStm_ComparatorSize_30Bits,                          /**< Size of compare value to compare with timer: 30 bits */
    IfxStm_ComparatorSize_31Bits,                          /**< Size of compare value to compare with timer: 31 bits */
    IfxStm_ComparatorSize_32Bits,                          /**< Size of compare value to compare with timer: 32 bits */
} IfxStm_ComparatorSize;

typedef enum
{
    IfxStm_ComparatorInterrupt_Ir0 = 0,               /**< Select STMIR0 */
    IfxStm_ComparatorInterrupt_Ir1                    /**< Select STMIR1 */
} IfxStm_ComparatorInterrupt;

#define IFXSTM_START_SEC_CONST_UNSPECIFIED
#include "IFXSTM_MemMap.h"

extern const IfxModule_IndexMap IfxStm_cfg_indexMap[IFXSTM_COUNT];

#define IFXSTM_STOP_SEC_CONST_UNSPECIFIED
#include "IFXSTM_MemMap.h"

#endif /* IFXSTM_CFG_H */

/*-------------------------------- end of file -------------------------------*/

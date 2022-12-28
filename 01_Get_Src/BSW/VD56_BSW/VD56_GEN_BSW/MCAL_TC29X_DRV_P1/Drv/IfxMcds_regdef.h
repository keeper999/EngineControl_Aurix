/**
 * \file IfxMcds_regdef.h
 * \brief
 * \copyright Copyright (c) 2012 Infineon Technologies AG. All rights reserved.
 *
 *
 * $Revision: 1585 $
 * $Date: 2013-09-03 13:30:24 +0200 (Di, 03 Sep 2013) $
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Mcds Mcds
 * \ingroup IfxLld
 * 
 * \defgroup IfxLld_Mcds_Bitfields Bitfields
 * \ingroup IfxLld_Mcds
 * 
 * \defgroup IfxLld_Mcds_union Union
 * \ingroup IfxLld_Mcds
 * 
 * \defgroup IfxLld_Mcds_struct Struct
 * \ingroup IfxLld_Mcds
 * 
 */
#ifndef IFXMCDS_REGDEF_H
#define IFXMCDS_REGDEF_H
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/
/** \addtogroup IfxLld_Mcds_Bitfields
 * \{  */

/** \\brief  Action Definition Register */
typedef struct _Ifx_MCDS_ACT_Bits
{
    Ifx_Strict_32Bit AIS0:5;                /**< \brief [4:0] Action Input Selector (rw) */
    Ifx_Strict_32Bit AIQ0:2;                /**< \brief [6:5] Action Input Qualifier (rw) */
    Ifx_Strict_32Bit LV0:1;                 /**< \brief [7:7] Action Input Level Mode (rw) */
    Ifx_Strict_32Bit AIS1:5;                /**< \brief [12:8] Action Input Selector (rw) */
    Ifx_Strict_32Bit AIQ1:2;                /**< \brief [14:13] Action Input Qualifier (rw) */
    Ifx_Strict_32Bit LV1:1;                 /**< \brief [15:15] Action Input Level Mode (rw) */
    Ifx_Strict_32Bit AIS2:5;                /**< \brief [20:16] Action Input Selector (rw) */
    Ifx_Strict_32Bit AIQ2:2;                /**< \brief [22:21] Action Input Qualifier (rw) */
    Ifx_Strict_32Bit LV2:1;                 /**< \brief [23:23] Action Input Level Mode (rw) */
    Ifx_Strict_32Bit AIS3:5;                /**< \brief [28:24] Action Input Selector (rw) */
    Ifx_Strict_32Bit AIQ3:2;                /**< \brief [30:29] Action Input Qualifier (rw) */
    Ifx_Strict_32Bit LV3:1;                 /**< \brief [31:31] Action Input Level Mode (rw) */
} Ifx_MCDS_ACT_Bits;

/** \\brief  Clock Control Register */
typedef struct _Ifx_MCDS_CLC_Bits
{
    Ifx_Strict_32Bit DISR:1;                /**< \brief [0:0] Module Disable Request Bit (rw) */
    Ifx_Strict_32Bit DISS:1;                /**< \brief [1:1] Module Disable Status Bit (rh) */
    Ifx_Strict_32Bit reserved_2:30;         /**< \brief \internal Reserved */
} Ifx_MCDS_CLC_Bits;

/** \\brief  Counter Control Register */
typedef struct _Ifx_MCDS_CNT_CCL_Bits
{
    Ifx_Strict_32Bit INC0:7;                /**< \brief [6:0] Count Input Selector (rw) */
    Ifx_Strict_32Bit ILV0:1;                /**< \brief [7:7] Count Input Level Mode (rw) */
    Ifx_Strict_32Bit CLR0:6;                /**< \brief [13:8] Clear Input Selector (rw) */
    Ifx_Strict_32Bit reserved_14:1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit CLV0:1;                /**< \brief [15:15] Clear Input Level Mode (rw) */
    Ifx_Strict_32Bit INC1:7;                /**< \brief [22:16] Count Input Selector (rw) */
    Ifx_Strict_32Bit ILV1:1;                /**< \brief [23:23] Count Input Level Mode (rw) */
    Ifx_Strict_32Bit CLR1:6;                /**< \brief [29:24] Clear Input Selector (rw) */
    Ifx_Strict_32Bit reserved_30:1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit CLV1:1;                /**< \brief [31:31] Clear Input Level Mode (rw) */
} Ifx_MCDS_CNT_CCL_Bits;

/** \\brief  Current Count Register */
typedef struct _Ifx_MCDS_CNT_CNT_Bits
{
    Ifx_Strict_32Bit COUNT:16;              /**< \brief [15:0] Current Counter (rh) */
    Ifx_Strict_32Bit reserved_16:16;        /**< \brief \internal Reserved */
} Ifx_MCDS_CNT_CNT_Bits;

/** \\brief  Counter Limit Register */
typedef struct _Ifx_MCDS_CNT_LMT_Bits
{
    Ifx_Strict_32Bit LIMIT:16;              /**< \brief [15:0] Counter Limit (rw) */
    Ifx_Strict_32Bit reserved_16:14;        /**< \brief \internal Reserved */
    Ifx_Strict_32Bit MOD0:1;                /**< \brief [30:30] Modulo Count Control (rw) */
    Ifx_Strict_32Bit MOD1:1;                /**< \brief [31:31] Modulo Count Control (rw) */
} Ifx_MCDS_CNT_LMT_Bits;

/** \\brief  MCDS Control Register */
typedef struct _Ifx_MCDS_CT_Bits
{
    Ifx_Strict_32Bit reserved_0:13;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit EN:1;                  /**< \brief [13:13] MCDS Enable Flag (rh) */
    Ifx_Strict_32Bit CLRE:1;                /**< \brief [14:14] Clear MCDS Enable Flag (w) */
    Ifx_Strict_32Bit SETE:1;                /**< \brief [15:15] Set MCDS Enable Flag (w) */
    Ifx_Strict_32Bit BED:1;                 /**< \brief [16:16] Bus Error Disable Flag (rw) */
    Ifx_Strict_32Bit reserved_17:2;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit BED_P:1;               /**< \brief [19:19] Bus Error Disable Protection (w) */
    Ifx_Strict_32Bit reserved_20:1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit IRA:1;                 /**< \brief [21:21] Invalid Read Access Flag (rh) */
    Ifx_Strict_32Bit CLRI:1;                /**< \brief [22:22] Clear Invalid Access Bits (w) */
    Ifx_Strict_32Bit IWA:1;                 /**< \brief [23:23] Invalid Write Access Flag (rh) */
    Ifx_Strict_32Bit reserved_24:5;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit RES:1;                 /**< \brief [29:29] MCDS Reset Flag (rh) */
    Ifx_Strict_32Bit reserved_30:1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit SETR:1;                /**< \brief [31:31] MCDS Reset Request Bit (w) */
} Ifx_MCDS_CT_Bits;

/** \\brief  Event Definition Register */
typedef struct _Ifx_MCDS_EVT_Bits
{
    Ifx_Strict_32Bit EIQ0:2;                /**< \brief [1:0] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ1:2;                /**< \brief [3:2] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ2:2;                /**< \brief [5:4] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ3:2;                /**< \brief [7:6] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ4:2;                /**< \brief [9:8] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ5:2;                /**< \brief [11:10] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ6:2;                /**< \brief [13:12] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ7:2;                /**< \brief [15:14] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ8:2;                /**< \brief [17:16] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ9:2;                /**< \brief [19:18] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ10:2;               /**< \brief [21:20] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ11:2;               /**< \brief [23:22] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ12:2;               /**< \brief [25:24] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ13:2;               /**< \brief [27:26] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ14:2;               /**< \brief [29:28] Event Input Qualifier (rw) */
    Ifx_Strict_32Bit EIQ15:2;               /**< \brief [31:30] Event Input Qualifier (rw) */
} Ifx_MCDS_EVT_Bits;

/** \\brief  Trace Buffer Bottom Register */
typedef struct _Ifx_MCDS_FIFOBOT_Bits
{
    Ifx_Strict_32Bit reserved_0:12;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit BOTTOM:8;              /**< \brief [19:12] Trace Buffer lower Bound (rw) */
    Ifx_Strict_32Bit reserved_20:12;        /**< \brief \internal Reserved */
} Ifx_MCDS_FIFOBOT_Bits;

/** \\brief  Trace Buffer Control Register */
typedef struct _Ifx_MCDS_FIFOCTL_Bits
{
    Ifx_Strict_32Bit TRG:1;                 /**< \brief [0:0] Trigger Received Flag (rh) */
    Ifx_Strict_32Bit FFE:1;                 /**< \brief [1:1] FIFO Feeder Empty (rh) */
    Ifx_Strict_32Bit reserved_2:7;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit TRDIS:1;               /**< \brief [9:9] Trigger Disable Flag (rh) */
    Ifx_Strict_32Bit TRON:1;                /**< \brief [10:10] Clear Trigger Disable Flag (w) */
    Ifx_Strict_32Bit TROFF:1;               /**< \brief [11:11] Set Trigger Disable Flag (w) */
    Ifx_Strict_32Bit reserved_12:1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit FLSH:1;                /**< \brief [13:13] Flush Flag (rh) */
    Ifx_Strict_32Bit CLR:1;                 /**< \brief [14:14] Clear Flush Flag (w) */
    Ifx_Strict_32Bit SET:1;                 /**< \brief [15:15] Set Flush Flag (w) */
    Ifx_Strict_32Bit reserved_16:16;        /**< \brief \internal Reserved */
} Ifx_MCDS_FIFOCTL_Bits;

/** \\brief  Trace Buffer Write Pointer */
typedef struct _Ifx_MCDS_FIFONOW_Bits
{
    Ifx_Strict_32Bit reserved_0:5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit NOW:15;                /**< \brief [19:5] Trace Buffer Current Write Pointer (rh) */
    Ifx_Strict_32Bit reserved_20:12;        /**< \brief \internal Reserved */
} Ifx_MCDS_FIFONOW_Bits;

/** \\brief  Trace Buffer PRE/POST Register */
typedef struct _Ifx_MCDS_FIFOPRE_Bits
{
    Ifx_Strict_32Bit reserved_0:5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit PRE:15;                /**< \brief [19:5] Trace Buffer Pre-Trigger Area Size (rw) */
    Ifx_Strict_32Bit reserved_20:12;        /**< \brief \internal Reserved */
} Ifx_MCDS_FIFOPRE_Bits;

/** \\brief  Trace Buffer Top Register */
typedef struct _Ifx_MCDS_FIFOTOP_Bits
{
    Ifx_Strict_32Bit reserved_0:5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit TOP:15;                /**< \brief [19:5] Trace Buffer upper Bound (rw) */
    Ifx_Strict_32Bit reserved_20:12;        /**< \brief \internal Reserved */
} Ifx_MCDS_FIFOTOP_Bits;

/** \\brief  Trace Buffer Comparator Register */
typedef struct _Ifx_MCDS_FIFOWARN0_Bits
{
    Ifx_Strict_32Bit reserved_0:5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit WARN:15;               /**< \brief [19:5] Trace Buffer Warn Level (rw) */
    Ifx_Strict_32Bit reserved_20:10;        /**< \brief \internal Reserved */
    Ifx_Strict_32Bit OCDEN:1;               /**< \brief [30:30] Enable Trigger Output (rw) */
    Ifx_Strict_32Bit EN:1;                  /**< \brief [31:31] Enable Trigger Generation (rw) */
} Ifx_MCDS_FIFOWARN0_Bits;

/** \\brief  Trace Buffer Comparator Register */
typedef struct _Ifx_MCDS_FIFOWARN1_Bits
{
    Ifx_Strict_32Bit reserved_0:5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit WARN:15;               /**< \brief [19:5] Trace Buffer Warn Level (rw) */
    Ifx_Strict_32Bit reserved_20:10;        /**< \brief \internal Reserved */
    Ifx_Strict_32Bit OCDEN:1;               /**< \brief [30:30] Enable Trigger Output (rw) */
    Ifx_Strict_32Bit EN:1;                  /**< \brief [31:31] Enable Trigger Generation (rw) */
} Ifx_MCDS_FIFOWARN1_Bits;

/** \\brief  Module Identification Register */
typedef struct _Ifx_MCDS_ID_Bits
{
    Ifx_Strict_32Bit MOD_REV:8;             /**< \brief [7:0] Module Revision Number (r) */
    Ifx_Strict_32Bit MOD_TYPE:8;            /**< \brief [15:8] Module Type (r) */
    Ifx_Strict_32Bit MODNUMBER:16;          /**< \brief [31:16] Module Number Value (r) */
} Ifx_MCDS_ID_Bits;

/** \\brief  MCDS Signal Source Control */
typedef struct _Ifx_MCDS_MUX_Bits
{
    Ifx_Strict_32Bit TMUX0:4;               /**< \brief [3:0] Trace Source Select 0 (rw) */
    Ifx_Strict_32Bit reserved_4:3;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit TM0_P:1;               /**< \brief [7:7] Trace Source Select z Protection (w) */
    Ifx_Strict_32Bit TMUX1:4;               /**< \brief [11:8] Trace Source Select 1 (rw) */
    Ifx_Strict_32Bit reserved_12:3;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit TM1_P:1;               /**< \brief [15:15] Trace Source Select z Protection (w) */
    Ifx_Strict_32Bit TMUX2:3;               /**< \brief [18:16] Trace Source Select 2 (rw) */
    Ifx_Strict_32Bit TM2_P:1;               /**< \brief [19:19] Trace Source Select z Protection (w) */
    Ifx_Strict_32Bit TMUX3:3;               /**< \brief [22:20] Trace Source Select 3 (rw) */
    Ifx_Strict_32Bit TM3_P:1;               /**< \brief [23:23] Trace Source Select z Protection (w) */
    Ifx_Strict_32Bit RC:1;                  /**< \brief [24:24] Reference Clock Select (rw) */
    Ifx_Strict_32Bit reserved_25:2;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit RC_P:1;                /**< \brief [27:27] Reference Clock Select Protection (w) */
    Ifx_Strict_32Bit reserved_28:4;         /**< \brief \internal Reserved */
} Ifx_MCDS_MUX_Bits;

/** \\brief  OCDS Control and Status */
typedef struct _Ifx_MCDS_OCS_Bits
{
    Ifx_Strict_32Bit reserved_0:24;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit SUS:4;                 /**< \brief [27:24] OCDS Suspend Control (rw) */
    Ifx_Strict_32Bit SUS_P:1;               /**< \brief [28:28] SUS Write Protection (w) */
    Ifx_Strict_32Bit SUSSTA:1;              /**< \brief [29:29] Suspend State (rh) */
    Ifx_Strict_32Bit reserved_30:2;         /**< \brief \internal Reserved */
} Ifx_MCDS_OCS_Bits;

/** \\brief  Current Instruction Pointer */
typedef struct _Ifx_MCDS_TCX_CIP_Bits
{
    Ifx_Strict_32Bit reserved_0:1;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit CURRENT:31;            /**< \brief [31:1] Current Instruction Pointer (rh) */
} Ifx_MCDS_TCX_CIP_Bits;

/** \\brief  Debug Status Register */
typedef struct _Ifx_MCDS_TCX_DCSTS_Bits
{
    Ifx_Strict_32Bit SUS:1;                 /**< \brief [0:0] Suspended Flag (rh) */
    Ifx_Strict_32Bit IDLE:1;                /**< \brief [1:1] Run Flag (rh) */
    Ifx_Strict_32Bit HALT:1;                /**< \brief [2:2] Halted Flag (rh) */
    Ifx_Strict_32Bit ISR:1;                 /**< \brief [3:3] Interrupt Service Flag (rh) */
    Ifx_Strict_32Bit HBRK:1;                /**< \brief [4:4] Hardware Break Flag (rh) */
    Ifx_Strict_32Bit SBRK:1;                /**< \brief [5:5] Software Break Flag (rh) */
    Ifx_Strict_32Bit reserved_6:1;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit IEN:1;                 /**< \brief [7:7] Interrupt Enable Flag (rh) */
    Ifx_Strict_32Bit DBGEN:1;               /**< \brief [8:8] Debug Enabled Flag (rh) */
    Ifx_Strict_32Bit CLKDIV:2;              /**< \brief [10:9] Current Clock Divider (rh) */
    Ifx_Strict_32Bit reserved_11:21;        /**< \brief \internal Reserved */
} Ifx_MCDS_TCX_DCSTS_Bits;

/** \\brief  Compact Function Trace Register */
typedef struct _Ifx_MCDS_TCX_TCCFTREG_Bits
{
    Ifx_Strict_32Bit VSHRT_FCT:8;           /**< \brief [7:0] Length of very short leaf function (rw) */
    Ifx_Strict_32Bit reserved_8:8;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit SHRT_FCT:8;            /**< \brief [23:16] Length of short leaf function (rw) */
    Ifx_Strict_32Bit reserved_24:8;         /**< \brief \internal Reserved */
} Ifx_MCDS_TCX_TCCFTREG_Bits;

/** \\brief  Comparator Bound Register */
typedef struct _Ifx_MCDS_TCXEA_BND_Bits
{
    Ifx_Strict_32Bit BOUND:32;              /**< \brief [31:0] Address Comparator range lower bound (rw) */
} Ifx_MCDS_TCXEA_BND_Bits;

/** \\brief  Comparator Range Register */
typedef struct _Ifx_MCDS_TCXEA_RNG_Bits
{
    Ifx_Strict_32Bit RANGE:32;              /**< \brief [31:0] Address Comparator range size (rw) */
} Ifx_MCDS_TCXEA_RNG_Bits;

/** \\brief  Comparator Bound Register */
typedef struct _Ifx_MCDS_TCXIP_BND_Bits
{
    Ifx_Strict_32Bit reserved_0:1;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit BOUND:31;              /**< \brief [31:1] IP Comparator range lower bound (rw) */
} Ifx_MCDS_TCXIP_BND_Bits;

/** \\brief  Comparator Range Register */
typedef struct _Ifx_MCDS_TCXIP_RNG_Bits
{
    Ifx_Strict_32Bit reserved_0:1;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit RANGE:31;              /**< \brief [31:1] IP Comparator range size (rw) */
} Ifx_MCDS_TCXIP_RNG_Bits;

/** \\brief  Comparator Bound Register */
typedef struct _Ifx_MCDS_TCXWD_BND_Bits
{
    Ifx_Strict_32Bit BOUND:32;              /**< \brief [31:0] Data Comparator range lower bound (rw) */
} Ifx_MCDS_TCXWD_BND_Bits;

/** \\brief  Comparator Mask Register */
typedef struct _Ifx_MCDS_TCXWD_MSK_Bits
{
    Ifx_Strict_32Bit MASK:32;               /**< \brief [31:0] Data Comparator bit mask (rw) */
} Ifx_MCDS_TCXWD_MSK_Bits;

/** \\brief  Comparator Range Register */
typedef struct _Ifx_MCDS_TCXWD_RNG_Bits
{
    Ifx_Strict_32Bit RANGE:32;              /**< \brief [31:0] Data Comparator range size (rw) */
} Ifx_MCDS_TCXWD_RNG_Bits;

/** \\brief  Comparator Sign Register */
typedef struct _Ifx_MCDS_TCXWD_SGN_Bits
{
    Ifx_Strict_32Bit SIGN:6;                /**< \brief [5:0] Bit number (1...63) of sign bit (rw) */
    Ifx_Strict_32Bit reserved_6:8;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit EITHER:1;              /**< \brief [14:14] RANGE matching either side of BOUND (rw) */
    Ifx_Strict_32Bit BELOW:1;               /**< \brief [15:15] RANGE matching lower side of BOUND (rw) */
    Ifx_Strict_32Bit RELOAD:4;              /**< \brief [19:16] Reload Event Selector (rw) */
    Ifx_Strict_32Bit reserved_20:12;        /**< \brief \internal Reserved */
} Ifx_MCDS_TCXWD_SGN_Bits;

/** \\brief  Clock Counter Register */
typedef struct _Ifx_MCDS_TSUEMUCNT_Bits
{
    Ifx_Strict_32Bit COUNT:32;              /**< \brief [31:0] Current Count Value (rh) */
} Ifx_MCDS_TSUEMUCNT_Bits;

/** \\brief  Clock Prescaler Register */
typedef struct _Ifx_MCDS_TSUPRSCL_Bits
{
    Ifx_Strict_32Bit RELOAD:32;             /**< \brief [31:0] Prescaler Reload Value (rw) */
} Ifx_MCDS_TSUPRSCL_Bits;

/** \\brief  Clock Counter Register */
typedef struct _Ifx_MCDS_TSUREFCNT_Bits
{
    Ifx_Strict_32Bit COUNT:32;              /**< \brief [31:0] Current Count Value (rh) */
} Ifx_MCDS_TSUREFCNT_Bits;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Mcds_union
 * \{  */

/** \\brief  Action Definition Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_ACT_Bits B;
} Ifx_MCDS_ACT;

/** \\brief  Clock Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_CLC_Bits B;
} Ifx_MCDS_CLC;

/** \\brief  Counter Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_CNT_CCL_Bits B;
} Ifx_MCDS_CNT_CCL;

/** \\brief  Current Count Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_CNT_CNT_Bits B;
} Ifx_MCDS_CNT_CNT;

/** \\brief  Counter Limit Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_CNT_LMT_Bits B;
} Ifx_MCDS_CNT_LMT;

/** \\brief  MCDS Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_CT_Bits B;
} Ifx_MCDS_CT;

/** \\brief  Event Definition Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_EVT_Bits B;
} Ifx_MCDS_EVT;

/** \\brief  Trace Buffer Bottom Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_FIFOBOT_Bits B;
} Ifx_MCDS_FIFOBOT;

/** \\brief  Trace Buffer Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_FIFOCTL_Bits B;
} Ifx_MCDS_FIFOCTL;

/** \\brief  Trace Buffer Write Pointer */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_FIFONOW_Bits B;
} Ifx_MCDS_FIFONOW;

/** \\brief  Trace Buffer PRE/POST Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_FIFOPRE_Bits B;
} Ifx_MCDS_FIFOPRE;

/** \\brief  Trace Buffer Top Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_FIFOTOP_Bits B;
} Ifx_MCDS_FIFOTOP;

/** \\brief  Trace Buffer Comparator Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_FIFOWARN0_Bits B;
} Ifx_MCDS_FIFOWARN0;

/** \\brief  Trace Buffer Comparator Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_FIFOWARN1_Bits B;
} Ifx_MCDS_FIFOWARN1;

/** \\brief  Module Identification Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_ID_Bits B;
} Ifx_MCDS_ID;

/** \\brief  MCDS Signal Source Control */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_MUX_Bits B;
} Ifx_MCDS_MUX;

/** \\brief  OCDS Control and Status */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_OCS_Bits B;
} Ifx_MCDS_OCS;

/** \\brief  Current Instruction Pointer */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TCX_CIP_Bits B;
} Ifx_MCDS_TCX_CIP;

/** \\brief  Debug Status Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TCX_DCSTS_Bits B;
} Ifx_MCDS_TCX_DCSTS;

/** \\brief  Compact Function Trace Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TCX_TCCFTREG_Bits B;
} Ifx_MCDS_TCX_TCCFTREG;

/** \\brief  Comparator Bound Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TCXEA_BND_Bits B;
} Ifx_MCDS_TCXEA_BND;

/** \\brief  Comparator Range Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TCXEA_RNG_Bits B;
} Ifx_MCDS_TCXEA_RNG;

/** \\brief  Comparator Bound Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TCXIP_BND_Bits B;
} Ifx_MCDS_TCXIP_BND;

/** \\brief  Comparator Range Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TCXIP_RNG_Bits B;
} Ifx_MCDS_TCXIP_RNG;

/** \\brief  Comparator Bound Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TCXWD_BND_Bits B;
} Ifx_MCDS_TCXWD_BND;

/** \\brief  Comparator Mask Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TCXWD_MSK_Bits B;
} Ifx_MCDS_TCXWD_MSK;

/** \\brief  Comparator Range Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TCXWD_RNG_Bits B;
} Ifx_MCDS_TCXWD_RNG;

/** \\brief  Comparator Sign Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TCXWD_SGN_Bits B;
} Ifx_MCDS_TCXWD_SGN;

/** \\brief  Clock Counter Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TSUEMUCNT_Bits B;
} Ifx_MCDS_TSUEMUCNT;

/** \\brief  Clock Prescaler Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TSUPRSCL_Bits B;
} Ifx_MCDS_TSUPRSCL;

/** \\brief  Clock Counter Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_MCDS_TSUREFCNT_Bits B;
} Ifx_MCDS_TSUREFCNT;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Mcds_struct
 * \{  */
/******************************************************************************/
/** \name Object L2
 * \{  */

/** \\brief  Counter objects */
typedef volatile struct _Ifx_MCDS_CNT
{
    Ifx_MCDS_CNT_CCL CCL;                   /**< \brief 0, Counter Control Register */
    Ifx_MCDS_CNT_LMT LMT;                   /**< \brief 4, Counter Limit Register */
    Ifx_MCDS_CNT_CNT CNT;                   /**< \brief 8, Current Count Register */
    unsigned char reserved_C[4];            /**< \brief C, \internal Reserved */
} Ifx_MCDS_CNT;

/** \\brief  Comparator objects */
typedef volatile struct _Ifx_MCDS_TCXEA
{
    Ifx_MCDS_TCXEA_BND BND;                 /**< \brief 0, Comparator Bound Register */
    Ifx_MCDS_TCXEA_RNG RNG;                 /**< \brief 4, Comparator Range Register */
    unsigned char reserved_8[8];            /**< \brief 8, \internal Reserved */
} Ifx_MCDS_TCXEA;

/** \\brief  Comparator objects */
typedef volatile struct _Ifx_MCDS_TCXIP
{
    Ifx_MCDS_TCXIP_BND BND;                 /**< \brief 0, Comparator Bound Register */
    Ifx_MCDS_TCXIP_RNG RNG;                 /**< \brief 4, Comparator Range Register */
    unsigned char reserved_8[8];            /**< \brief 8, \internal Reserved */
} Ifx_MCDS_TCXIP;

/** \\brief  Comparator objects */
typedef volatile struct _Ifx_MCDS_TCXWD
{
    Ifx_MCDS_TCXWD_BND BND;                 /**< \brief 0, Comparator Bound Register */
    unsigned char reserved_4[4];            /**< \brief 4, \internal Reserved */
    Ifx_MCDS_TCXWD_RNG RNG;                 /**< \brief 8, Comparator Range Register */
    unsigned char reserved_C[4];            /**< \brief C, \internal Reserved */
    Ifx_MCDS_TCXWD_MSK MSK;                 /**< \brief 10, Comparator Mask Register */
    unsigned char reserved_14[8];           /**< \brief 14, \internal Reserved */
    Ifx_MCDS_TCXWD_SGN SGN;                 /**< \brief 1C, Comparator Sign Register */
} Ifx_MCDS_TCXWD;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Mcds_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */

/** \\brief  MCX object */
typedef volatile struct _Ifx_MCDS_MCX
{
    Ifx_MCDS_EVT EVT[16];                   /**< \brief 0, Event Definition Register */
    unsigned char reserved_40[64];          /**< \brief 40, \internal Reserved */
    Ifx_MCDS_ACT ACT[45];                   /**< \brief 80, Action Definition Register */
    unsigned char reserved_134[204];        /**< \brief 134, \internal Reserved */
    Ifx_MCDS_CNT CNT[8];                    /**< \brief 200, Counter objects */
} Ifx_MCDS_MCX;

/** \\brief  TCX object */
typedef volatile struct _Ifx_MCDS_TCX
{
    Ifx_MCDS_TCX_DCSTS DCSTS;               /**< \brief 0, Debug Status Register */
    unsigned char reserved_4[4];            /**< \brief 4, \internal Reserved */
    Ifx_MCDS_TCX_CIP CIP;                   /**< \brief 8, Current Instruction Pointer */
    Ifx_MCDS_TCX_TCCFTREG TCCFTREG;         /**< \brief C, Compact Function Trace Register */
    unsigned char reserved_10[1008];        /**< \brief 10, \internal Reserved */
    Ifx_MCDS_TCXEA EA[2];                   /**< \brief 400, Comparator objects */
    unsigned char reserved_420[96];         /**< \brief 420, \internal Reserved */
    Ifx_MCDS_TCXWD WD[2];                   /**< \brief 480, Comparator objects */
    unsigned char reserved_4C0[2880];       /**< \brief 4C0, \internal Reserved */
    Ifx_MCDS_TCXIP IP[2];                   /**< \brief 1000, Comparator objects */
} Ifx_MCDS_TCX;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Mcds_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \\brief  MCDS object */
typedef volatile struct _Ifx_MCDS
{
    Ifx_MCDS_CLC CLC;                       /**< \brief 0, Clock Control Register */
    Ifx_MCDS_OCS OCS;                       /**< \brief 4, OCDS Control and Status */
    Ifx_MCDS_ID ID;                         /**< \brief 8, Module Identification Register */
    unsigned char reserved_C[4];            /**< \brief C, \internal Reserved */
    Ifx_MCDS_CT CT;                         /**< \brief 10, MCDS Control Register */
    Ifx_MCDS_MUX MUX;                       /**< \brief 14, MCDS Signal Source Control */
    unsigned char reserved_18[488];         /**< \brief 18, \internal Reserved */
    Ifx_MCDS_FIFONOW FIFONOW;               /**< \brief 200, Trace Buffer Write Pointer */
    Ifx_MCDS_FIFOBOT FIFOBOT;               /**< \brief 204, Trace Buffer Bottom Register */
    Ifx_MCDS_FIFOPRE FIFOPRE;               /**< \brief 208, Trace Buffer PRE/POST Register */
    Ifx_MCDS_FIFOTOP FIFOTOP;               /**< \brief 20C, Trace Buffer Top Register */
    Ifx_MCDS_FIFOCTL FIFOCTL;               /**< \brief 210, Trace Buffer Control Register */
    Ifx_MCDS_FIFOWARN0 FIFOWARN0;           /**< \brief 214, Trace Buffer Comparator Register */
    Ifx_MCDS_FIFOWARN1 FIFOWARN1;           /**< \brief 218, Trace Buffer Comparator Register */
    unsigned char reserved_21C[484];        /**< \brief 21C, \internal Reserved */
    Ifx_MCDS_TSUREFCNT TSUREFCNT;           /**< \brief 400, Clock Counter Register */
    Ifx_MCDS_TSUPRSCL TSUPRSCL;             /**< \brief 404, Clock Prescaler Register */
    Ifx_MCDS_TSUEMUCNT TSUEMUCNT;           /**< \brief 408, Clock Counter Register */
    unsigned char reserved_40C[1012];       /**< \brief 40C, \internal Reserved */
    Ifx_MCDS_MCX MCX;                       /**< \brief 800, MCX object */
    unsigned char reserved_A80[5504];       /**< \brief A80, \internal Reserved */
    Ifx_MCDS_TCX TCX;                       /**< \brief 2000, TCX object */
    unsigned char reserved_3020[20448];     /**< \brief 3020, \internal Reserved */
} Ifx_MCDS;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXMCDS_REGDEF_H */

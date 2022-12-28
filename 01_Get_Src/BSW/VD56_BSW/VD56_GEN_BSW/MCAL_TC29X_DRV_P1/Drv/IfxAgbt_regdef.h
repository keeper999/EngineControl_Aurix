/**
 * \file IfxAgbt_regdef.h
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
 * \defgroup IfxLld_Agbt Agbt
 * \ingroup IfxLld
 * 
 * \defgroup IfxLld_Agbt_Bitfields Bitfields
 * \ingroup IfxLld_Agbt
 * 
 * \defgroup IfxLld_Agbt_union Union
 * \ingroup IfxLld_Agbt
 * 
 * \defgroup IfxLld_Agbt_struct Struct
 * \ingroup IfxLld_Agbt
 * 
 */
#ifndef IFXAGBT_REGDEF_H
#define IFXAGBT_REGDEF_H
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/
/** \addtogroup IfxLld_Agbt_Bitfields
 * \{  */

/** \\brief  Clock Control Register */
typedef struct _Ifx_AGBT_CLC_Bits
{
    Ifx_Strict_32Bit DISR:1;                /**< \brief [0:0] Module Disable Request Bit (rw) */
    Ifx_Strict_32Bit DISS:1;                /**< \brief [1:1] Module Disable Status Bit (rh) */
    Ifx_Strict_32Bit reserved_2:30;         /**< \brief \internal Reserved */
} Ifx_AGBT_CLC_Bits;

/** \\brief  FIFO Block Fill Level */
typedef struct _Ifx_AGBT_FBFLV_Bits
{
    Ifx_Strict_32Bit CURLVL:8;              /**< \brief [7:0] Current FIFO Fill Level (rh) */
    Ifx_Strict_32Bit MAXLVL:8;              /**< \brief [15:8] Maximum FIFO Fill Level (rwh) */
    Ifx_Strict_32Bit reserved_16:16;        /**< \brief \internal Reserved */
} Ifx_AGBT_FBFLV_Bits;

/** \\brief  FIFO Control Register */
typedef struct _Ifx_AGBT_FCTRL_Bits
{
    Ifx_Strict_32Bit WMLVL:8;               /**< \brief [7:0] Watermark Level (rw) */
    Ifx_Strict_32Bit reserved_8:24;         /**< \brief \internal Reserved */
} Ifx_AGBT_FCTRL_Bits;

/** \\brief  Module Identification Register */
typedef struct _Ifx_AGBT_ID_Bits
{
    Ifx_Strict_32Bit MOD_REV:8;             /**< \brief [7:0] Module Revision Number (r) */
    Ifx_Strict_32Bit MOD_TYPE:8;            /**< \brief [15:8] Module Type (r) */
    Ifx_Strict_32Bit MODNUMBER:16;          /**< \brief [31:16] Module Number Value (r) */
} Ifx_AGBT_ID_Bits;

/** \\brief  EMEM Interrupt enable register */
typedef struct _Ifx_AGBT_IRE_Bits
{
    Ifx_Strict_32Bit OFWE:1;                /**< \brief [0:0] FIFO overflow enable (rw) */
    Ifx_Strict_32Bit WME:1;                 /**< \brief [1:1] Watermark interrupt enable (rw) */
    Ifx_Strict_32Bit HWE:1;                 /**< \brief [2:2] Hardware error indication interrupt enable (rw) */
    Ifx_Strict_32Bit FERE:1;                /**< \brief [3:3] Truncated Frame error interrupt enable (rw) */
    Ifx_Strict_32Bit reserved_4:28;         /**< \brief \internal Reserved */
} Ifx_AGBT_IRE_Bits;

/** \\brief  EMEM Interrupt status register */
typedef struct _Ifx_AGBT_IRS_Bits
{
    Ifx_Strict_32Bit OFW:1;                 /**< \brief [0:0] FIFO overflow (rwh) */
    Ifx_Strict_32Bit WM:1;                  /**< \brief [1:1] FIFO watermark interrupt (rwh) */
    Ifx_Strict_32Bit HW:1;                  /**< \brief [2:2] Hardware error indication interrupt (rwh) */
    Ifx_Strict_32Bit FER:1;                 /**< \brief [3:3] Truncated Frame (rwh) */
    Ifx_Strict_32Bit reserved_4:28;         /**< \brief \internal Reserved */
} Ifx_AGBT_IRS_Bits;

/** \\brief  EMEM PLL Control Register 1 */
typedef struct _Ifx_AGBT_PLC1_Bits
{
    Ifx_Strict_32Bit PCTR0:1;               /**< \brief [0:0] Enable PLL to lock. (rw) */
    Ifx_Strict_32Bit PCTR1:1;               /**< \brief [1:1] Enable PLL divider by 2 (rw) */
    Ifx_Strict_32Bit PCTR2:1;               /**< \brief [2:2] Activate the clock for the tDC (rw) */
    Ifx_Strict_32Bit PCTR3:1;               /**< \brief [3:3] Activate the clock for the TX (rw) */
    Ifx_Strict_32Bit PCTR4:1;               /**< \brief [4:4] Activates the clock for the PI (rw) */
    Ifx_Strict_32Bit reserved_5:3;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit PCTR8:1;               /**< \brief [8:8] TXDFT_RN_CLK_ATE clock monitoring enable input (rw) */
    Ifx_Strict_32Bit PCTR9:1;               /**< \brief [9:9] TX_DFT_EN_CLK_TEST clock monitoring enable input (rw) */
    Ifx_Strict_32Bit PCTR10:1;              /**< \brief [10:10] Central Bias VREF monitoring enable input. (rw) */
    Ifx_Strict_32Bit PCTR11:1;              /**< \brief [11:11] CLKRX output clock monitoring enable input. (rw) */
    Ifx_Strict_32Bit PCTR12:1;              /**< \brief [12:12] Activate analog monitoring multiplexer. (rw) */
    Ifx_Strict_32Bit PCTR13_15:3;           /**< \brief [15:13] Analog and digital monitoring multiplexer select. (rw) */
    Ifx_Strict_32Bit PCTR16:1;              /**< \brief [16:16] Digital monitoring multiplexer input (rw) */
    Ifx_Strict_32Bit PCTR17:1;              /**< \brief [17:17] Activates digital monitoring multiplexer. (rw) */
    Ifx_Strict_32Bit PCTR18_20:3;           /**< \brief [20:18] Current trimming for TX-OCD reference current. (rw) */
    Ifx_Strict_32Bit PCTR21_23:3;           /**< \brief [23:21] Current trimming for DPLL-Bias block reference current. (rw) */
    Ifx_Strict_32Bit PCTR24:1;              /**< \brief [24:24] Select signal for register readback (rw) */
    Ifx_Strict_32Bit PCTR25:1;              /**< \brief [25:25] Write signal for internal PLL registers (rw) */
    Ifx_Strict_32Bit PCTRA:6;               /**< \brief [31:26] Address of internal PLL register (rw) */
} Ifx_AGBT_PLC1_Bits;

/** \\brief  EMEM PLL Control Register 2 */
typedef struct _Ifx_AGBT_PLC2_Bits
{
    Ifx_Strict_32Bit PCTRL2:32;             /**< \brief [31:0] PLL dynamic control bits [63:32] (rw) */
} Ifx_AGBT_PLC2_Bits;

/** \\brief  EMEM PLL Control Register 3 */
typedef struct _Ifx_AGBT_PLC3_Bits
{
    Ifx_Strict_32Bit PFCW:24;               /**< \brief [23:0] PLL multiplication factor selection (rw) */
    Ifx_Strict_32Bit CBTRIMCUR:3;           /**< \brief [26:24] Central Bias (rw) */
    Ifx_Strict_32Bit reserved_27:4;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit PRS:1;                 /**< \brief [31:31] PLL Ref. clock select (rw) */
} Ifx_AGBT_PLC3_Bits;

/** \\brief  EMEM Physical Layer Control Register 4 */
typedef struct _Ifx_AGBT_PLC4_Bits
{
    Ifx_Strict_32Bit PCSP:1;                /**< \brief [0:0] PCS layer bit polarity selection (rw) */
    Ifx_Strict_32Bit SEREN:1;               /**< \brief [1:1] Enable SERIALIZER (rwh) */
    Ifx_Strict_32Bit SERDEM:1;              /**< \brief [2:2] Activate SERIALIZER De-Emphasis Mode (rw) */
    Ifx_Strict_32Bit DPNBS:2;               /**< \brief [4:3] DATA PREDRIVER Current (rw) */
    Ifx_Strict_32Bit DPARE:3;               /**< \brief [7:5] DATA PREDRIVER Capacity (rw) */
    Ifx_Strict_32Bit DPSRE:3;               /**< \brief [10:8] DATA PREDRIVER High Level (rw) */
    Ifx_Strict_32Bit DPBYS:1;               /**< \brief [11:11] DATA PROVIDER Full Swing (rw) */
    Ifx_Strict_32Bit CLKRXSCMR:3;           /**< \brief [14:12] Clock Receiver reference voltage (rw) */
    Ifx_Strict_32Bit reserved_15:1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit OCDCVS:4;              /**< \brief [19:16] OFF-CHIP DRIVER (OCD) Current (rw) */
    Ifx_Strict_32Bit OCDRTS:5;              /**< \brief [24:20] OFF-CHIP DRIVER (OCD) Termination (rw) */
    Ifx_Strict_32Bit PCSMSB:1;              /**< \brief [25:25] MSB first (PCS) (rw) */
    Ifx_Strict_32Bit PCSBSW:1;              /**< \brief [26:26] Byte Swap (PCS) (rw) */
    Ifx_Strict_32Bit CLKRXSRTER:4;          /**< \brief [30:27] Clock Receiver Termination (rw) */
    Ifx_Strict_32Bit OCDDIFEN:1;            /**< \brief [31:31] OCD DIFFERENTIAL OUTPUT ENABLE (OCD) (rw) */
} Ifx_AGBT_PLC4_Bits;

/** \\brief  EMEM Production Test Register 5 */
typedef struct _Ifx_AGBT_PLC5_Bits
{
    Ifx_Strict_32Bit PLLREGDO:32;           /**< \brief [31:0] Readback data from internal PLL registers and BIST status register. Register selected by PLL Address field. (rh) */
} Ifx_AGBT_PLC5_Bits;

/** \\brief  Trace Auto Channel UP */
typedef struct _Ifx_AGBT_TACU_Bits
{
    Ifx_Strict_32Bit ACIC:24;               /**< \brief [23:0] Automatic Channel Initialization Counter (rw) */
    Ifx_Strict_32Bit reserved_24:7;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ACIEN:1;               /**< \brief [31:31] Automatic Channel Initialization enable (rw) */
} Ifx_AGBT_TACU_Bits;

/** \\brief  Trace Control Register */
typedef struct _Ifx_AGBT_TCR_Bits
{
    Ifx_Strict_32Bit TE:1;                  /**< \brief [0:0] Trace Enable (rwh) */
    Ifx_Strict_32Bit PLLE:1;                /**< \brief [1:1] PLL reset (rw) */
    Ifx_Strict_32Bit TXA:1;                 /**< \brief [2:2] Initialized (rwh) */
    Ifx_Strict_32Bit PON:1;                 /**< \brief [3:3] Power On (rw) */
    Ifx_Strict_32Bit TPV:1;                 /**< \brief [4:4] Trace Port Verified (rwh) */
    Ifx_Strict_32Bit BD:3;                  /**< \brief [7:5] Baud rate selection/availability (rw) */
    Ifx_Strict_32Bit reserved_8:8;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit AGBTON:1;              /**< \brief [16:16] EMEM on (rw) */
    Ifx_Strict_32Bit reserved_17:1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit CRCON:1;               /**< \brief [18:18] CRC append at the end of a data block on. (rw) */
    Ifx_Strict_32Bit ATPMON:1;              /**< \brief [19:19] Aurora Test Pattern Mode (rw) */
    Ifx_Strict_32Bit reserved_20:12;        /**< \brief \internal Reserved */
} Ifx_AGBT_TCR_Bits;

/** \\brief  Trace Status Register */
typedef struct _Ifx_AGBT_TSR_Bits
{
    Ifx_Strict_32Bit TXLNUP:1;              /**< \brief [0:0] TX lane up (rh) */
    Ifx_Strict_32Bit FBE:1;                 /**< \brief [1:1] FIFO Buffer empty indication (rh) */
    Ifx_Strict_32Bit PLK:1;                 /**< \brief [2:2] PLL lock status (rh) */
    Ifx_Strict_32Bit ATBS:2;                /**< \brief [4:3] AGBT Trace Buffer Size (rh) */
    Ifx_Strict_32Bit reserved_5:26;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit CHUP:1;                /**< \brief [31:31] Channel up (rh) */
} Ifx_AGBT_TSR_Bits;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Agbt_union
 * \{  */

/** \\brief  Clock Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_CLC_Bits B;
} Ifx_AGBT_CLC;

/** \\brief  FIFO Block Fill Level */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_FBFLV_Bits B;
} Ifx_AGBT_FBFLV;

/** \\brief  FIFO Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_FCTRL_Bits B;
} Ifx_AGBT_FCTRL;

/** \\brief  Module Identification Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_ID_Bits B;
} Ifx_AGBT_ID;

/** \\brief  EMEM Interrupt enable register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_IRE_Bits B;
} Ifx_AGBT_IRE;

/** \\brief  EMEM Interrupt status register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_IRS_Bits B;
} Ifx_AGBT_IRS;

/** \\brief  EMEM PLL Control Register 1 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_PLC1_Bits B;
} Ifx_AGBT_PLC1;

/** \\brief  EMEM PLL Control Register 2 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_PLC2_Bits B;
} Ifx_AGBT_PLC2;

/** \\brief  EMEM PLL Control Register 3 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_PLC3_Bits B;
} Ifx_AGBT_PLC3;

/** \\brief  EMEM Physical Layer Control Register 4 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_PLC4_Bits B;
} Ifx_AGBT_PLC4;

/** \\brief  EMEM Production Test Register 5 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_PLC5_Bits B;
} Ifx_AGBT_PLC5;

/** \\brief  Trace Auto Channel UP */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_TACU_Bits B;
} Ifx_AGBT_TACU;

/** \\brief  Trace Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_TCR_Bits B;
} Ifx_AGBT_TCR;

/** \\brief  Trace Status Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_AGBT_TSR_Bits B;
} Ifx_AGBT_TSR;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Agbt_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \\brief  AGBT object */
typedef volatile struct _Ifx_AGBT
{
    Ifx_AGBT_CLC CLC;                       /**< \brief 0, Clock Control Register */
    unsigned char reserved_4[4];            /**< \brief 4, \internal Reserved */
    Ifx_AGBT_ID ID;                         /**< \brief 8, Module Identification Register */
    unsigned char reserved_C[4];            /**< \brief C, \internal Reserved */
    Ifx_AGBT_TCR TCR;                       /**< \brief 10, Trace Control Register */
    Ifx_AGBT_TSR TSR;                       /**< \brief 14, Trace Status Register */
    Ifx_AGBT_FCTRL FCTRL;                   /**< \brief 18, FIFO Control Register */
    Ifx_AGBT_TACU TACU;                     /**< \brief 1C, Trace Auto Channel UP */
    Ifx_AGBT_FBFLV FBFLV;                   /**< \brief 20, FIFO Block Fill Level */
    Ifx_AGBT_IRS IRS;                       /**< \brief 24, EMEM Interrupt status register */
    Ifx_AGBT_IRE IRE;                       /**< \brief 28, EMEM Interrupt enable register */
    unsigned char reserved_2C[4];           /**< \brief 2C, \internal Reserved */
    Ifx_AGBT_PLC1 PLC1;                     /**< \brief 30, EMEM PLL Control Register 1 */
    Ifx_AGBT_PLC2 PLC2;                     /**< \brief 34, EMEM PLL Control Register 2 */
    Ifx_AGBT_PLC3 PLC3;                     /**< \brief 38, EMEM PLL Control Register 3 */
    Ifx_AGBT_PLC4 PLC4;                     /**< \brief 3C, EMEM Physical Layer Control Register 4 */
    unsigned char reserved_40[16];          /**< \brief 40, \internal Reserved */
    Ifx_AGBT_PLC5 PLC5;                     /**< \brief 50, EMEM Production Test Register 5 */
    unsigned char reserved_54[172];         /**< \brief 54, \internal Reserved */
} Ifx_AGBT;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXAGBT_REGDEF_H */

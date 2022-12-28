/**
 * \file IfxEmem_regdef.h
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
 * \defgroup IfxLld_Emem Emem
 * \ingroup IfxLld
 * 
 * \defgroup IfxLld_Emem_Bitfields Bitfields
 * \ingroup IfxLld_Emem
 * 
 * \defgroup IfxLld_Emem_union Union
 * \ingroup IfxLld_Emem
 * 
 * \defgroup IfxLld_Emem_struct Struct
 * \ingroup IfxLld_Emem
 * 
 */
#ifndef IFXEMEM_REGDEF_H
#define IFXEMEM_REGDEF_H
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/
/** \addtogroup IfxLld_Emem_Bitfields
 * \{  */

/** \\brief  Clock Control Register */
typedef struct _Ifx_EMEM_CLC_Bits
{
    Ifx_Strict_32Bit DISR:1;                /**< \brief [0:0] Module Disable Request Bit (rw) */
    Ifx_Strict_32Bit DISS:1;                /**< \brief [1:1] Module Disable Status Bit (rh) */
    Ifx_Strict_32Bit reserved_2:30;         /**< \brief \internal Reserved */
} Ifx_EMEM_CLC_Bits;

/** \\brief  Module Identification Register */
typedef struct _Ifx_EMEM_ID_Bits
{
    Ifx_Strict_32Bit MOD_REV:8;             /**< \brief [7:0] Module Revision Number (r) */
    Ifx_Strict_32Bit MOD_TYPE:8;            /**< \brief [15:8] Module Type (r) */
    Ifx_Strict_32Bit MODNUMBER:16;          /**< \brief [31:16] Module Number Value (r) */
} Ifx_EMEM_ID_Bits;

/** \\brief  Standby RAM Control Register */
typedef struct _Ifx_EMEM_SBRCTR_Bits
{
    Ifx_Strict_32Bit STBLOCK:1;             /**< \brief [0:0] Lock Flag (rh) */
    Ifx_Strict_32Bit STBULK:3;              /**< \brief [3:1] Unlock Lock Flag (w) */
    Ifx_Strict_32Bit STBSLK:4;              /**< \brief [7:4] Set Lock Flag (w) */
    Ifx_Strict_32Bit ACGSXAM0:1;            /**< \brief [8:8] Automatic Clock Gating Status of XAM0 (rh) */
    Ifx_Strict_32Bit reserved_9:3;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ACGEN:1;               /**< \brief [12:12] Automatic Clock Gating Enabling (rw) */
    Ifx_Strict_32Bit reserved_13:3;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ACGST0:1;              /**< \brief [16:16] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST1:1;              /**< \brief [17:17] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST2:1;              /**< \brief [18:18] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST3:1;              /**< \brief [19:19] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST4:1;              /**< \brief [20:20] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST5:1;              /**< \brief [21:21] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST6:1;              /**< \brief [22:22] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST7:1;              /**< \brief [23:23] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST8:1;              /**< \brief [24:24] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST9:1;              /**< \brief [25:25] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST10:1;             /**< \brief [26:26] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST11:1;             /**< \brief [27:27] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST12:1;             /**< \brief [28:28] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST13:1;             /**< \brief [29:29] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST14:1;             /**< \brief [30:30] Automatic Clock Gating Status of Tile x (rh) */
    Ifx_Strict_32Bit ACGST15:1;             /**< \brief [31:31] Automatic Clock Gating Status of Tile x (rh) */
} Ifx_EMEM_SBRCTR_Bits;

/** \\brief  Tile Configuration Register */
typedef struct _Ifx_EMEM_TILECONFIG_Bits
{
    Ifx_Strict_32Bit T0:2;                  /**< \brief [1:0] Tile x Allocation (w) */
    Ifx_Strict_32Bit T1:2;                  /**< \brief [3:2] Tile x Allocation (w) */
    Ifx_Strict_32Bit T2:2;                  /**< \brief [5:4] Tile x Allocation (w) */
    Ifx_Strict_32Bit T3:2;                  /**< \brief [7:6] Tile x Allocation (w) */
    Ifx_Strict_32Bit T4:2;                  /**< \brief [9:8] Tile x Allocation (w) */
    Ifx_Strict_32Bit T5:2;                  /**< \brief [11:10] Tile x Allocation (w) */
    Ifx_Strict_32Bit T6:2;                  /**< \brief [13:12] Tile x Allocation (w) */
    Ifx_Strict_32Bit T7:2;                  /**< \brief [15:14] Tile x Allocation (w) */
    Ifx_Strict_32Bit T8:2;                  /**< \brief [17:16] Tile x Allocation (w) */
    Ifx_Strict_32Bit T9:2;                  /**< \brief [19:18] Tile x Allocation (w) */
    Ifx_Strict_32Bit T10:2;                 /**< \brief [21:20] Tile x Allocation (w) */
    Ifx_Strict_32Bit T11:2;                 /**< \brief [23:22] Tile x Allocation (w) */
    Ifx_Strict_32Bit T12:2;                 /**< \brief [25:24] Tile x Allocation (w) */
    Ifx_Strict_32Bit T13:2;                 /**< \brief [27:26] Tile x Allocation (w) */
    Ifx_Strict_32Bit T14:2;                 /**< \brief [29:28] Tile x Allocation (w) */
    Ifx_Strict_32Bit T15:2;                 /**< \brief [31:30] Tile x Allocation (w) */
} Ifx_EMEM_TILECONFIG_Bits;

/** \\brief  Extended Tile Configuration Register */
typedef struct _Ifx_EMEM_TILECONFIGXM_Bits
{
    Ifx_Strict_32Bit XAM0:2;                /**< \brief [1:0] XAM0 Tile Allocation (w) */
    Ifx_Strict_32Bit reserved_2:30;         /**< \brief \internal Reserved */
} Ifx_EMEM_TILECONFIGXM_Bits;

/** \\brief  Tile Status Register */
typedef struct _Ifx_EMEM_TILESTATE_Bits
{
    Ifx_Strict_32Bit TILE0:2;               /**< \brief [1:0] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE1:2;               /**< \brief [3:2] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE2:2;               /**< \brief [5:4] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE3:2;               /**< \brief [7:6] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE4:2;               /**< \brief [9:8] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE5:2;               /**< \brief [11:10] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE6:2;               /**< \brief [13:12] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE7:2;               /**< \brief [15:14] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE8:2;               /**< \brief [17:16] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE9:2;               /**< \brief [19:18] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE10:2;              /**< \brief [21:20] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE11:2;              /**< \brief [23:22] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE12:2;              /**< \brief [25:24] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE13:2;              /**< \brief [27:26] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE14:2;              /**< \brief [29:28] Usage of Tile x (rh) */
    Ifx_Strict_32Bit TILE15:2;              /**< \brief [31:30] Usage of Tile x (rh) */
} Ifx_EMEM_TILESTATE_Bits;

/** \\brief  Extended Tile Status Register */
typedef struct _Ifx_EMEM_TILESTATEXM_Bits
{
    Ifx_Strict_32Bit XAM0:2;                /**< \brief [1:0] Usage of XAM0 Tile (rh) */
    Ifx_Strict_32Bit reserved_2:30;         /**< \brief \internal Reserved */
} Ifx_EMEM_TILESTATEXM_Bits;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Emem_union
 * \{  */

/** \\brief  Clock Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_EMEM_CLC_Bits B;
} Ifx_EMEM_CLC;

/** \\brief  Module Identification Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_EMEM_ID_Bits B;
} Ifx_EMEM_ID;

/** \\brief  Standby RAM Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_EMEM_SBRCTR_Bits B;
} Ifx_EMEM_SBRCTR;

/** \\brief  Tile Configuration Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_EMEM_TILECONFIG_Bits B;
} Ifx_EMEM_TILECONFIG;

/** \\brief  Extended Tile Configuration Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_EMEM_TILECONFIGXM_Bits B;
} Ifx_EMEM_TILECONFIGXM;

/** \\brief  Tile Status Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_EMEM_TILESTATE_Bits B;
} Ifx_EMEM_TILESTATE;

/** \\brief  Extended Tile Status Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_EMEM_TILESTATEXM_Bits B;
} Ifx_EMEM_TILESTATEXM;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Emem_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \\brief  EMEM object */
typedef volatile struct _Ifx_EMEM
{
    Ifx_EMEM_CLC CLC;                       /**< \brief 0, Clock Control Register */
    unsigned char reserved_4[4];            /**< \brief 4, \internal Reserved */
    Ifx_EMEM_ID ID;                         /**< \brief 8, Module Identification Register */
    unsigned char reserved_C[20];           /**< \brief C, \internal Reserved */
    Ifx_EMEM_TILECONFIG TILECONFIG;         /**< \brief 20, Tile Configuration Register */
    unsigned char reserved_24[8];           /**< \brief 24, \internal Reserved */
    Ifx_EMEM_TILESTATE TILESTATE;           /**< \brief 2C, Tile Status Register */
    unsigned char reserved_30[4];           /**< \brief 30, \internal Reserved */
    Ifx_EMEM_SBRCTR SBRCTR;                 /**< \brief 34, Standby RAM Control Register */
    unsigned char reserved_38[8];           /**< \brief 38, \internal Reserved */
    Ifx_EMEM_TILECONFIGXM TILECONFIGXM;     /**< \brief 40, Extended Tile Configuration Register */
    unsigned char reserved_44[8];           /**< \brief 44, \internal Reserved */
    Ifx_EMEM_TILESTATEXM TILESTATEXM;       /**< \brief 4C, Extended Tile Status Register */
    unsigned char reserved_50[176];         /**< \brief 50, \internal Reserved */
} Ifx_EMEM;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXEMEM_REGDEF_H */

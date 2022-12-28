/**
 * \file IfxMc_regdef.h
 * \brief
 * \copyright Copyright (c) 2012 Infineon Technologies AG. All rights reserved.
 *
 *
 * $Revision: 1586 $
 * $Date: 2013-09-03 14:43:49 +0200 (Di, 03 Sep 2013) $
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
 * \defgroup IfxLld_Mc Mc
 * \ingroup IfxLld
 * 
 * \defgroup IfxLld_Mc_Bitfields Bitfields
 * \ingroup IfxLld_Mc
 * 
 * \defgroup IfxLld_Mc_union Union
 * \ingroup IfxLld_Mc
 * 
 * \defgroup IfxLld_Mc_struct Struct
 * \ingroup IfxLld_Mc
 * 
 */
#ifndef IFXMC_REGDEF_H
#define IFXMC_REGDEF_H
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/
/** \addtogroup IfxLld_Mc_Bitfields
 * \{  */

/** \\brief  Configuration Register 0 */
typedef struct _Ifx_MC_CONFIG0_Bits
{
    unsigned short ACCSTYPE:8;              /**< \brief [7:0] Access type (rw) */
    unsigned short reserved_8:4;            /**< \brief \internal Reserved */
    unsigned short NUMACCS:4;               /**< \brief [15:12] Number of accesses per address (rw) */
} Ifx_MC_CONFIG0_Bits;

/** \\brief  Configuration Register 1 */
typedef struct _Ifx_MC_CONFIG1_Bits
{
    unsigned short ACCSPAT:8;               /**< \brief [7:0] Access pattern (rw) */
    unsigned short SELFASTB:4;              /**< \brief [11:8] Select Fast Bit (rw) */
    unsigned short AG_MOD:4;                /**< \brief [15:12] Address Generator Mode (rw) */
} Ifx_MC_CONFIG1_Bits;

/** \\brief  Memory ECC Detection Register */
typedef struct _Ifx_MC_ECCD_Bits
{
    unsigned short SERR:1;                  /**< \brief [0:0] Error Detected (rwh) */
    unsigned short CERR:1;                  /**< \brief [1:1] Correctable Error Detected (rwh) */
    unsigned short UERR:1;                  /**< \brief [2:2] Uncorrectable Error Detected (rwh) */
    unsigned short AERR:1;                  /**< \brief [3:3] Address Error Detected (rwh) */
    unsigned short TRC:1;                   /**< \brief [4:4] Tracking Clear (w) */
    unsigned short VAL:5;                   /**< \brief [9:5] Valid Bits (rh) */
    unsigned short reserved_10:1;           /**< \brief \internal Reserved */
    unsigned short CENE:1;                  /**< \brief [11:11] Correctable Error Notification Enable (rw) */
    unsigned short UENE:1;                  /**< \brief [12:12] Uncorrectable Error Notification Enable (rw) */
    unsigned short AENE:1;                  /**< \brief [13:13] Address Error Notification Enable (rw) */
    unsigned short ECE:1;                   /**< \brief [14:14] Error Correction Enable (rw) */
    unsigned short EOV:1;                   /**< \brief [15:15] Error Overflow (rh) */
} Ifx_MC_ECCD_Bits;

/** \\brief  ECC Safety Register */
typedef struct _Ifx_MC_ECCS_Bits
{
    unsigned short CENE:1;                  /**< \brief [0:0] Correctable Error Notification Enable (rw) */
    unsigned short UENE:1;                  /**< \brief [1:1] Uncorrectable Error Notification Enable (rw) */
    unsigned short AENE:1;                  /**< \brief [2:2] Address Error Notification Enable (rw) */
    unsigned short ECE:1;                   /**< \brief [3:3] Error Correction Enable (rw) */
    unsigned short TRE:1;                   /**< \brief [4:4] Tracking Enable (rw) */
    unsigned short BFLE:1;                  /**< \brief [5:5] Bit Flip Enable (rw) */
    unsigned short SFLE:2;                  /**< \brief [7:6] Signature Bit Flip Enables (rw) */
    unsigned short ECCMAP:2;                /**< \brief [9:8] ECC Bit Mapping Mode (rw) */
    unsigned short TC_WAY_SEL:2;            /**< \brief [11:10] TriCore Cache Way Select (rw) */
    unsigned short reserved_12:4;           /**< \brief \internal Reserved */
} Ifx_MC_ECCS_Bits;

/** \\brief  Error Tracking Register */
typedef struct _Ifx_MC_ETRR_Bits
{
    unsigned short ADDR:13;                 /**< \brief [12:0] Address of Error(i) (rh) */
    unsigned short MBI:3;                   /**< \brief [15:13] Memory Block Index of Error(i) (rh) */
} Ifx_MC_ETRR_Bits;

/** \\brief  MBIST Control Register */
typedef struct _Ifx_MC_MCONTROL_Bits
{
    unsigned short START:1;                 /**< \brief [0:0] START (rw) */
    unsigned short RESUME:1;                /**< \brief [1:1] Resume failed test (rwh) */
    unsigned short ESTF:1;                  /**< \brief [2:2] Enable Sticky Fail Bit (rw) */
    unsigned short DIR:1;                   /**< \brief [3:3] Direction Select (rw) */
    unsigned short DINIT:1;                 /**< \brief [4:4] Data Initialization Enable (rw) */
    unsigned short RCADR:1;                 /**< \brief [5:5] Fast Row / Fast Column Addressing Scheme Select (rw) */
    unsigned short ROWTOG:1;                /**< \brief [6:6] Row toggling (rw) */
    unsigned short BITTOG:1;                /**< \brief [7:7] Bit toggling (rw) */
    unsigned short GP_BASE:1;               /**< \brief [8:8] Galpat Base (rw) */
    unsigned short FAILDMP:1;               /**< \brief [9:9] Fail bitmap dump (rw) */
    unsigned short reserved_10:6;           /**< \brief \internal Reserved */
} Ifx_MC_MCONTROL_Bits;

/** \\brief  Status Register */
typedef struct _Ifx_MC_MSTATUS_Bits
{
    unsigned short DONE:1;                  /**< \brief [0:0] DONE (rh) */
    unsigned short FAIL:1;                  /**< \brief [1:1] FAIL (rh) */
    unsigned short FDA:1;                   /**< \brief [2:2] Fail Dump Available (rh) */
    unsigned short SFAIL:1;                 /**< \brief [3:3] Sticky Fail Bit (rh) */
    unsigned short reserved_4:12;           /**< \brief \internal Reserved */
} Ifx_MC_MSTATUS_Bits;

/** \\brief  Range Register, single address mode */
typedef struct _Ifx_MC_RANGE_Bits
{
    unsigned short ADDR:15;                 /**< \brief [14:0] Address (rw) */
    unsigned short RAEN:1;                  /**< \brief [15:15] Range Enable (rw) */
} Ifx_MC_RANGE_Bits;

/** \\brief  Read Data and Bit Flip Register */
typedef struct _Ifx_MC_RDBFL_Bits
{
    unsigned short WDATA:16;                /**< \brief [15:0] Word Data (rwh) */
} Ifx_MC_RDBFL_Bits;

/** \\brief  Revision ID Register */
typedef struct _Ifx_MC_REVID_Bits
{
    unsigned short REV_ID:16;               /**< \brief [15:0] Revision Identifier (r) */
} Ifx_MC_REVID_Bits;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Mc_union
 * \{  */

/** \\brief  Configuration Register 0 */
typedef union
{
    /** \brief Unsigned access */
    unsigned short U;
    /** \brief Signed access */
    signed short I;
    /** \brief Bitfield access */
    Ifx_MC_CONFIG0_Bits B;
} Ifx_MC_CONFIG0;

/** \\brief  Configuration Register 1 */
typedef union
{
    /** \brief Unsigned access */
    unsigned short U;
    /** \brief Signed access */
    signed short I;
    /** \brief Bitfield access */
    Ifx_MC_CONFIG1_Bits B;
} Ifx_MC_CONFIG1;

/** \\brief  Memory ECC Detection Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned short U;
    /** \brief Signed access */
    signed short I;
    /** \brief Bitfield access */
    Ifx_MC_ECCD_Bits B;
} Ifx_MC_ECCD;

/** \\brief  ECC Safety Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned short U;
    /** \brief Signed access */
    signed short I;
    /** \brief Bitfield access */
    Ifx_MC_ECCS_Bits B;
} Ifx_MC_ECCS;

/** \\brief  Error Tracking Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned short U;
    /** \brief Signed access */
    signed short I;
    /** \brief Bitfield access */
    Ifx_MC_ETRR_Bits B;
} Ifx_MC_ETRR;

/** \\brief  MBIST Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned short U;
    /** \brief Signed access */
    signed short I;
    /** \brief Bitfield access */
    Ifx_MC_MCONTROL_Bits B;
} Ifx_MC_MCONTROL;

/** \\brief  Status Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned short U;
    /** \brief Signed access */
    signed short I;
    /** \brief Bitfield access */
    Ifx_MC_MSTATUS_Bits B;
} Ifx_MC_MSTATUS;

/** \\brief  Range Register, single address mode */
typedef union
{
    /** \brief Unsigned access */
    unsigned short U;
    /** \brief Signed access */
    signed short I;
    /** \brief Bitfield access */
    Ifx_MC_RANGE_Bits B;
} Ifx_MC_RANGE;

/** \\brief  Read Data and Bit Flip Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned short U;
    /** \brief Signed access */
    signed short I;
    /** \brief Bitfield access */
    Ifx_MC_RDBFL_Bits B;
} Ifx_MC_RDBFL;

/** \\brief  Revision ID Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned short U;
    /** \brief Signed access */
    signed short I;
    /** \brief Bitfield access */
    Ifx_MC_REVID_Bits B;
} Ifx_MC_REVID;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Mc_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \\brief  MC object */
typedef volatile struct _Ifx_MC
{
    Ifx_MC_CONFIG0 CONFIG0;                 /**< \brief 0, Configuration Register 0 */
    Ifx_MC_CONFIG1 CONFIG1;                 /**< \brief 2, Configuration Register 1 */
    Ifx_MC_MCONTROL MCONTROL;               /**< \brief 4, MBIST Control Register */
    Ifx_MC_MSTATUS MSTATUS;                 /**< \brief 6, Status Register */
    Ifx_MC_RANGE RANGE;                     /**< \brief 8, Range Register, single address mode */
    unsigned char reserved_A[2];            /**< \brief A, \internal Reserved */
    Ifx_MC_REVID REVID;                     /**< \brief C, Revision ID Register */
    Ifx_MC_ECCS ECCS;                       /**< \brief E, ECC Safety Register */
    Ifx_MC_ECCD ECCD;                       /**< \brief 10, Memory ECC Detection Register */
    Ifx_MC_ETRR ETRR[5];                    /**< \brief 12, Error Tracking Register */
    unsigned char reserved_1C[132];         /**< \brief 1C, \internal Reserved */
    Ifx_MC_RDBFL RDBFL[40];                 /**< \brief A0, Read Data and Bit Flip Register */
    unsigned char reserved_F0[16];          /**< \brief F0, \internal Reserved */
} Ifx_MC;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXMC_REGDEF_H */

/**
 * \file IfxFft_regdef.h
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
 * \defgroup IfxLld_Fft Fft
 * \ingroup IfxLld
 * 
 * \defgroup IfxLld_Fft_Bitfields Bitfields
 * \ingroup IfxLld_Fft
 * 
 * \defgroup IfxLld_Fft_union Union
 * \ingroup IfxLld_Fft
 * 
 * \defgroup IfxLld_Fft_struct Struct
 * \ingroup IfxLld_Fft
 * 
 */
#ifndef IFXFFT_REGDEF_H
#define IFXFFT_REGDEF_H
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/
/** \addtogroup IfxLld_Fft_Bitfields
 * \{  */

/** \\brief  FFT Clock Control Register */
typedef struct _Ifx_FFT_CLC_Bits
{
    unsigned int DISR:1;                    /**< \brief [0:0] FFT Disable Request Bit (rw) */
    unsigned int DISS:1;                    /**< \brief [1:1] FFT Disable Status Bit (rh) */
    unsigned int reserved_2:30;             /**< \brief \internal Reserved */
} Ifx_FFT_CLC_Bits;

/** \\brief  FFT Control and Status Register */
typedef struct _Ifx_FFT_CSR_Bits
{
    unsigned int START:1;                   /**< \brief [0:0] Start Transform (rwh) */
    unsigned int reserved_1:7;              /**< \brief \internal Reserved */
    unsigned int LENGTH:4;                  /**< \brief [11:8] Length of Transform (rw) */
    unsigned int IFFT:1;                    /**< \brief [12:12] Inverse FFT (rw) */
    unsigned int WIN_BYP:1;                 /**< \brief [13:13] Window Bypass (rw) */
    unsigned int reserved_14:2;             /**< \brief \internal Reserved */
    unsigned int IN_FMT:2;                  /**< \brief [17:16] Input Format (rw) */
    unsigned int OUT_FMT:1;                 /**< \brief [18:18] Output Format (rw) */
    unsigned int BUSY:1;                    /**< \brief [19:19] FFT Engine Busy (rh) */
    unsigned int RFS:1;                     /**< \brief [20:20] Ready For Start (rh) */
    unsigned int reserved_21:11;            /**< \brief \internal Reserved */
} Ifx_FFT_CSR_Bits;

/** \\brief  FFT History0 Register */
typedef struct _Ifx_FFT_HISTORY0_Bits
{
    unsigned int reserved_0:8;              /**< \brief \internal Reserved */
    unsigned int LENGTH:4;                  /**< \brief [11:8] Length of Transform (rh) */
    unsigned int IFFT:1;                    /**< \brief [12:12] Inverse FFT (rh) */
    unsigned int WIN_BYP:1;                 /**< \brief [13:13] Window Bypass (rh) */
    unsigned int reserved_14:2;             /**< \brief \internal Reserved */
    unsigned int IN_FMT:2;                  /**< \brief [17:16] Input Format (rh) */
    unsigned int OUT_FMT:1;                 /**< \brief [18:18] Output Format (rh) */
    unsigned int BUSY:1;                    /**< \brief [19:19] FFT Engine Busy (rh) */
    unsigned int RFS:1;                     /**< \brief [20:20] Ready For Start (rh) */
    unsigned int reserved_21:11;            /**< \brief \internal Reserved */
} Ifx_FFT_HISTORY0_Bits;

/** \\brief  FFT History1 Register */
typedef struct _Ifx_FFT_HISTORY1_Bits
{
    unsigned int reserved_0:8;              /**< \brief \internal Reserved */
    unsigned int LENGTH:4;                  /**< \brief [11:8] Length of Transform (rh) */
    unsigned int IFFT:1;                    /**< \brief [12:12] Inverse FFT (rh) */
    unsigned int WIN_BYP:1;                 /**< \brief [13:13] Window Bypass (rh) */
    unsigned int reserved_14:2;             /**< \brief \internal Reserved */
    unsigned int IN_FMT:2;                  /**< \brief [17:16] Input Format (rh) */
    unsigned int OUT_FMT:1;                 /**< \brief [18:18] Output Format (rh) */
    unsigned int BUSY:1;                    /**< \brief [19:19] FFT Engine Busy (rh) */
    unsigned int RFS:1;                     /**< \brief [20:20] Ready For Start (rh) */
    unsigned int reserved_21:11;            /**< \brief \internal Reserved */
} Ifx_FFT_HISTORY1_Bits;

/** \\brief  FFT Identification Register */
typedef struct _Ifx_FFT_ID_Bits
{
    unsigned int MOD_REV:8;                 /**< \brief [7:0] Module Revision Number (r) */
    unsigned int MOD_TYPE:8;                /**< \brief [15:8] Module Type (r) */
    unsigned int MODNUMBER:16;              /**< \brief [31:16] Module Number Value (r) */
} Ifx_FFT_ID_Bits;

/** \\brief  FFT Kernel Reset Register 0 */
typedef struct _Ifx_FFT_KRST0_Bits
{
    unsigned int RST:1;                     /**< \brief [0:0] Kernel Reset (rwh) */
    unsigned int RSTSTAT:1;                 /**< \brief [1:1] Kernel Reset Status (rh) */
    unsigned int reserved_2:30;             /**< \brief \internal Reserved */
} Ifx_FFT_KRST0_Bits;

/** \\brief  FFT Kernel Reset Register 1 */
typedef struct _Ifx_FFT_KRST1_Bits
{
    unsigned int RST:1;                     /**< \brief [0:0] Kernel Reset (rwh) */
    unsigned int reserved_1:31;             /**< \brief \internal Reserved */
} Ifx_FFT_KRST1_Bits;

/** \\brief  FFT Kernel Reset Status Clear Register */
typedef struct _Ifx_FFT_KRSTCLR_Bits
{
    unsigned int CLR:1;                     /**< \brief [0:0] Kernel Reset Status Clear (w) */
    unsigned int reserved_1:31;             /**< \brief \internal Reserved */
} Ifx_FFT_KRSTCLR_Bits;

/** \\brief  FFT OCDS Control and Status */
typedef struct _Ifx_FFT_OCS_Bits
{
    unsigned int reserved_0:24;             /**< \brief \internal Reserved */
    unsigned int SUS:4;                     /**< \brief [27:24] OCDS Suspend Control (rw) */
    unsigned int SUS_P:1;                   /**< \brief [28:28] SUS Write Protection (w) */
    unsigned int SUSSTA:1;                  /**< \brief [29:29] Suspend State (rh) */
    unsigned int reserved_30:2;             /**< \brief \internal Reserved */
} Ifx_FFT_OCS_Bits;

/** \\brief  FFT OCDS Debug Access Register */
typedef struct _Ifx_FFT_ODA_Bits
{
    unsigned int DDREN:1;                   /**< \brief [0:0] Destructive Debug Read Enable (rw) */
    unsigned int DRDIS:1;                   /**< \brief [1:1] Destructive Read Disable (rw) */
    unsigned int reserved_2:30;             /**< \brief \internal Reserved */
} Ifx_FFT_ODA_Bits;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Fft_union
 * \{  */

/** \\brief  FFT Clock Control Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_FFT_CLC_Bits B;
} Ifx_FFT_CLC;

/** \\brief  FFT Control and Status Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_FFT_CSR_Bits B;
} Ifx_FFT_CSR;

/** \\brief  FFT History0 Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_FFT_HISTORY0_Bits B;
} Ifx_FFT_HISTORY0;

/** \\brief  FFT History1 Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_FFT_HISTORY1_Bits B;
} Ifx_FFT_HISTORY1;

/** \\brief  FFT Identification Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_FFT_ID_Bits B;
} Ifx_FFT_ID;

/** \\brief  FFT Kernel Reset Register 0 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_FFT_KRST0_Bits B;
} Ifx_FFT_KRST0;

/** \\brief  FFT Kernel Reset Register 1 */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_FFT_KRST1_Bits B;
} Ifx_FFT_KRST1;

/** \\brief  FFT Kernel Reset Status Clear Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_FFT_KRSTCLR_Bits B;
} Ifx_FFT_KRSTCLR;

/** \\brief  FFT OCDS Control and Status */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_FFT_OCS_Bits B;
} Ifx_FFT_OCS;

/** \\brief  FFT OCDS Debug Access Register */
typedef union
{
    /** \brief Unsigned access */
    unsigned int U;
    /** \brief Signed access */
    signed int I;
    /** \brief Bitfield access */
    Ifx_FFT_ODA_Bits B;
} Ifx_FFT_ODA;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Fft_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \\brief  FFT object */
typedef volatile struct _Ifx_FFT
{
    Ifx_FFT_CLC CLC;                        /**< \brief 0, FFT Clock Control Register */
    unsigned char reserved_4[4];            /**< \brief 4, \internal Reserved */
    Ifx_FFT_ID ID;                          /**< \brief 8, FFT Identification Register */
    unsigned char reserved_C[52];           /**< \brief C, \internal Reserved */
    Ifx_FFT_CSR CSR;                        /**< \brief 40, FFT Control and Status Register */
    unsigned char reserved_44[28];          /**< \brief 44, \internal Reserved */
    Ifx_FFT_HISTORY0 HISTORY0;              /**< \brief 60, FFT History0 Register */
    unsigned char reserved_64[12];          /**< \brief 64, \internal Reserved */
    Ifx_FFT_HISTORY1 HISTORY1;              /**< \brief 70, FFT History1 Register */
    unsigned char reserved_74[112];         /**< \brief 74, \internal Reserved */
    Ifx_FFT_ODA ODA;                        /**< \brief E4, FFT OCDS Debug Access Register */
    Ifx_FFT_OCS OCS;                        /**< \brief E8, FFT OCDS Control and Status */
    Ifx_FFT_KRSTCLR KRSTCLR;                /**< \brief EC, FFT Kernel Reset Status Clear Register */
    Ifx_FFT_KRST1 KRST1;                    /**< \brief F0, FFT Kernel Reset Register 1 */
    Ifx_FFT_KRST0 KRST0;                    /**< \brief F4, FFT Kernel Reset Register 0 */
    unsigned char reserved_F8[8];           /**< \brief F8, \internal Reserved */
} Ifx_FFT;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXFFT_REGDEF_H */

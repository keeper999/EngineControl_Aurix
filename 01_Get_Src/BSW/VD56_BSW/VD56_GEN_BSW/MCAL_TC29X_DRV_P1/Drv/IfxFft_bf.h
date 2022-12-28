/**
 * \file IfxFft_bf.h
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
 * \defgroup IfxLld_Fft_BitfieldsMask Bitfields mask and offset
 * \ingroup IfxLld_Fft
 * 
 */
#ifndef IFXFFT_BF_H
#define IFXFFT_BF_H
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Fft_BitfieldsMask
 * \{  */

/** \\brief  Length for Ifx_FFT_CLC_Bits.DISR */
#define IFX_FFT_CLC_DISR_LEN (1)

/** \\brief  Mask for Ifx_FFT_CLC_Bits.DISR */
#define IFX_FFT_CLC_DISR_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_CLC_Bits.DISR */
#define IFX_FFT_CLC_DISR_OFF (0)

/** \\brief  Length for Ifx_FFT_CLC_Bits.DISS */
#define IFX_FFT_CLC_DISS_LEN (1)

/** \\brief  Mask for Ifx_FFT_CLC_Bits.DISS */
#define IFX_FFT_CLC_DISS_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_CLC_Bits.DISS */
#define IFX_FFT_CLC_DISS_OFF (1)

/** \\brief  Length for Ifx_FFT_CSR_Bits.BUSY */
#define IFX_FFT_CSR_BUSY_LEN (1)

/** \\brief  Mask for Ifx_FFT_CSR_Bits.BUSY */
#define IFX_FFT_CSR_BUSY_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_CSR_Bits.BUSY */
#define IFX_FFT_CSR_BUSY_OFF (19)

/** \\brief  Length for Ifx_FFT_CSR_Bits.IFFT */
#define IFX_FFT_CSR_IFFT_LEN (1)

/** \\brief  Mask for Ifx_FFT_CSR_Bits.IFFT */
#define IFX_FFT_CSR_IFFT_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_CSR_Bits.IFFT */
#define IFX_FFT_CSR_IFFT_OFF (12)

/** \\brief  Length for Ifx_FFT_CSR_Bits.IN_FMT */
#define IFX_FFT_CSR_IN_FMT_LEN (2)

/** \\brief  Mask for Ifx_FFT_CSR_Bits.IN_FMT */
#define IFX_FFT_CSR_IN_FMT_MSK (0x3)

/** \\brief  Offset for Ifx_FFT_CSR_Bits.IN_FMT */
#define IFX_FFT_CSR_IN_FMT_OFF (16)

/** \\brief  Length for Ifx_FFT_CSR_Bits.LENGTH */
#define IFX_FFT_CSR_LENGTH_LEN (4)

/** \\brief  Mask for Ifx_FFT_CSR_Bits.LENGTH */
#define IFX_FFT_CSR_LENGTH_MSK (0xf)

/** \\brief  Offset for Ifx_FFT_CSR_Bits.LENGTH */
#define IFX_FFT_CSR_LENGTH_OFF (8)

/** \\brief  Length for Ifx_FFT_CSR_Bits.OUT_FMT */
#define IFX_FFT_CSR_OUT_FMT_LEN (1)

/** \\brief  Mask for Ifx_FFT_CSR_Bits.OUT_FMT */
#define IFX_FFT_CSR_OUT_FMT_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_CSR_Bits.OUT_FMT */
#define IFX_FFT_CSR_OUT_FMT_OFF (18)

/** \\brief  Length for Ifx_FFT_CSR_Bits.RFS */
#define IFX_FFT_CSR_RFS_LEN (1)

/** \\brief  Mask for Ifx_FFT_CSR_Bits.RFS */
#define IFX_FFT_CSR_RFS_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_CSR_Bits.RFS */
#define IFX_FFT_CSR_RFS_OFF (20)

/** \\brief  Length for Ifx_FFT_CSR_Bits.START */
#define IFX_FFT_CSR_START_LEN (1)

/** \\brief  Mask for Ifx_FFT_CSR_Bits.START */
#define IFX_FFT_CSR_START_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_CSR_Bits.START */
#define IFX_FFT_CSR_START_OFF (0)

/** \\brief  Length for Ifx_FFT_CSR_Bits.WIN_BYP */
#define IFX_FFT_CSR_WIN_BYP_LEN (1)

/** \\brief  Mask for Ifx_FFT_CSR_Bits.WIN_BYP */
#define IFX_FFT_CSR_WIN_BYP_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_CSR_Bits.WIN_BYP */
#define IFX_FFT_CSR_WIN_BYP_OFF (13)

/** \\brief  Length for Ifx_FFT_HISTORY0_Bits.BUSY */
#define IFX_FFT_HISTORY0_BUSY_LEN (1)

/** \\brief  Mask for Ifx_FFT_HISTORY0_Bits.BUSY */
#define IFX_FFT_HISTORY0_BUSY_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_HISTORY0_Bits.BUSY */
#define IFX_FFT_HISTORY0_BUSY_OFF (19)

/** \\brief  Length for Ifx_FFT_HISTORY0_Bits.IFFT */
#define IFX_FFT_HISTORY0_IFFT_LEN (1)

/** \\brief  Mask for Ifx_FFT_HISTORY0_Bits.IFFT */
#define IFX_FFT_HISTORY0_IFFT_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_HISTORY0_Bits.IFFT */
#define IFX_FFT_HISTORY0_IFFT_OFF (12)

/** \\brief  Length for Ifx_FFT_HISTORY0_Bits.IN_FMT */
#define IFX_FFT_HISTORY0_IN_FMT_LEN (2)

/** \\brief  Mask for Ifx_FFT_HISTORY0_Bits.IN_FMT */
#define IFX_FFT_HISTORY0_IN_FMT_MSK (0x3)

/** \\brief  Offset for Ifx_FFT_HISTORY0_Bits.IN_FMT */
#define IFX_FFT_HISTORY0_IN_FMT_OFF (16)

/** \\brief  Length for Ifx_FFT_HISTORY0_Bits.LENGTH */
#define IFX_FFT_HISTORY0_LENGTH_LEN (4)

/** \\brief  Mask for Ifx_FFT_HISTORY0_Bits.LENGTH */
#define IFX_FFT_HISTORY0_LENGTH_MSK (0xf)

/** \\brief  Offset for Ifx_FFT_HISTORY0_Bits.LENGTH */
#define IFX_FFT_HISTORY0_LENGTH_OFF (8)

/** \\brief  Length for Ifx_FFT_HISTORY0_Bits.OUT_FMT */
#define IFX_FFT_HISTORY0_OUT_FMT_LEN (1)

/** \\brief  Mask for Ifx_FFT_HISTORY0_Bits.OUT_FMT */
#define IFX_FFT_HISTORY0_OUT_FMT_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_HISTORY0_Bits.OUT_FMT */
#define IFX_FFT_HISTORY0_OUT_FMT_OFF (18)

/** \\brief  Length for Ifx_FFT_HISTORY0_Bits.RFS */
#define IFX_FFT_HISTORY0_RFS_LEN (1)

/** \\brief  Mask for Ifx_FFT_HISTORY0_Bits.RFS */
#define IFX_FFT_HISTORY0_RFS_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_HISTORY0_Bits.RFS */
#define IFX_FFT_HISTORY0_RFS_OFF (20)

/** \\brief  Length for Ifx_FFT_HISTORY0_Bits.WIN_BYP */
#define IFX_FFT_HISTORY0_WIN_BYP_LEN (1)

/** \\brief  Mask for Ifx_FFT_HISTORY0_Bits.WIN_BYP */
#define IFX_FFT_HISTORY0_WIN_BYP_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_HISTORY0_Bits.WIN_BYP */
#define IFX_FFT_HISTORY0_WIN_BYP_OFF (13)

/** \\brief  Length for Ifx_FFT_HISTORY1_Bits.BUSY */
#define IFX_FFT_HISTORY1_BUSY_LEN (1)

/** \\brief  Mask for Ifx_FFT_HISTORY1_Bits.BUSY */
#define IFX_FFT_HISTORY1_BUSY_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_HISTORY1_Bits.BUSY */
#define IFX_FFT_HISTORY1_BUSY_OFF (19)

/** \\brief  Length for Ifx_FFT_HISTORY1_Bits.IFFT */
#define IFX_FFT_HISTORY1_IFFT_LEN (1)

/** \\brief  Mask for Ifx_FFT_HISTORY1_Bits.IFFT */
#define IFX_FFT_HISTORY1_IFFT_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_HISTORY1_Bits.IFFT */
#define IFX_FFT_HISTORY1_IFFT_OFF (12)

/** \\brief  Length for Ifx_FFT_HISTORY1_Bits.IN_FMT */
#define IFX_FFT_HISTORY1_IN_FMT_LEN (2)

/** \\brief  Mask for Ifx_FFT_HISTORY1_Bits.IN_FMT */
#define IFX_FFT_HISTORY1_IN_FMT_MSK (0x3)

/** \\brief  Offset for Ifx_FFT_HISTORY1_Bits.IN_FMT */
#define IFX_FFT_HISTORY1_IN_FMT_OFF (16)

/** \\brief  Length for Ifx_FFT_HISTORY1_Bits.LENGTH */
#define IFX_FFT_HISTORY1_LENGTH_LEN (4)

/** \\brief  Mask for Ifx_FFT_HISTORY1_Bits.LENGTH */
#define IFX_FFT_HISTORY1_LENGTH_MSK (0xf)

/** \\brief  Offset for Ifx_FFT_HISTORY1_Bits.LENGTH */
#define IFX_FFT_HISTORY1_LENGTH_OFF (8)

/** \\brief  Length for Ifx_FFT_HISTORY1_Bits.OUT_FMT */
#define IFX_FFT_HISTORY1_OUT_FMT_LEN (1)

/** \\brief  Mask for Ifx_FFT_HISTORY1_Bits.OUT_FMT */
#define IFX_FFT_HISTORY1_OUT_FMT_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_HISTORY1_Bits.OUT_FMT */
#define IFX_FFT_HISTORY1_OUT_FMT_OFF (18)

/** \\brief  Length for Ifx_FFT_HISTORY1_Bits.RFS */
#define IFX_FFT_HISTORY1_RFS_LEN (1)

/** \\brief  Mask for Ifx_FFT_HISTORY1_Bits.RFS */
#define IFX_FFT_HISTORY1_RFS_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_HISTORY1_Bits.RFS */
#define IFX_FFT_HISTORY1_RFS_OFF (20)

/** \\brief  Length for Ifx_FFT_HISTORY1_Bits.WIN_BYP */
#define IFX_FFT_HISTORY1_WIN_BYP_LEN (1)

/** \\brief  Mask for Ifx_FFT_HISTORY1_Bits.WIN_BYP */
#define IFX_FFT_HISTORY1_WIN_BYP_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_HISTORY1_Bits.WIN_BYP */
#define IFX_FFT_HISTORY1_WIN_BYP_OFF (13)

/** \\brief  Length for Ifx_FFT_ID_Bits.MOD_REV */
#define IFX_FFT_ID_MOD_REV_LEN (8)

/** \\brief  Mask for Ifx_FFT_ID_Bits.MOD_REV */
#define IFX_FFT_ID_MOD_REV_MSK (0xff)

/** \\brief  Offset for Ifx_FFT_ID_Bits.MOD_REV */
#define IFX_FFT_ID_MOD_REV_OFF (0)

/** \\brief  Length for Ifx_FFT_ID_Bits.MOD_TYPE */
#define IFX_FFT_ID_MOD_TYPE_LEN (8)

/** \\brief  Mask for Ifx_FFT_ID_Bits.MOD_TYPE */
#define IFX_FFT_ID_MOD_TYPE_MSK (0xff)

/** \\brief  Offset for Ifx_FFT_ID_Bits.MOD_TYPE */
#define IFX_FFT_ID_MOD_TYPE_OFF (8)

/** \\brief  Length for Ifx_FFT_ID_Bits.MODNUMBER */
#define IFX_FFT_ID_MODNUMBER_LEN (16)

/** \\brief  Mask for Ifx_FFT_ID_Bits.MODNUMBER */
#define IFX_FFT_ID_MODNUMBER_MSK (0xffff)

/** \\brief  Offset for Ifx_FFT_ID_Bits.MODNUMBER */
#define IFX_FFT_ID_MODNUMBER_OFF (16)

/** \\brief  Length for Ifx_FFT_KRST0_Bits.RST */
#define IFX_FFT_KRST0_RST_LEN (1)

/** \\brief  Mask for Ifx_FFT_KRST0_Bits.RST */
#define IFX_FFT_KRST0_RST_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_KRST0_Bits.RST */
#define IFX_FFT_KRST0_RST_OFF (0)

/** \\brief  Length for Ifx_FFT_KRST0_Bits.RSTSTAT */
#define IFX_FFT_KRST0_RSTSTAT_LEN (1)

/** \\brief  Mask for Ifx_FFT_KRST0_Bits.RSTSTAT */
#define IFX_FFT_KRST0_RSTSTAT_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_KRST0_Bits.RSTSTAT */
#define IFX_FFT_KRST0_RSTSTAT_OFF (1)

/** \\brief  Length for Ifx_FFT_KRST1_Bits.RST */
#define IFX_FFT_KRST1_RST_LEN (1)

/** \\brief  Mask for Ifx_FFT_KRST1_Bits.RST */
#define IFX_FFT_KRST1_RST_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_KRST1_Bits.RST */
#define IFX_FFT_KRST1_RST_OFF (0)

/** \\brief  Length for Ifx_FFT_KRSTCLR_Bits.CLR */
#define IFX_FFT_KRSTCLR_CLR_LEN (1)

/** \\brief  Mask for Ifx_FFT_KRSTCLR_Bits.CLR */
#define IFX_FFT_KRSTCLR_CLR_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_KRSTCLR_Bits.CLR */
#define IFX_FFT_KRSTCLR_CLR_OFF (0)

/** \\brief  Length for Ifx_FFT_OCS_Bits.SUS */
#define IFX_FFT_OCS_SUS_LEN (4)

/** \\brief  Mask for Ifx_FFT_OCS_Bits.SUS */
#define IFX_FFT_OCS_SUS_MSK (0xf)

/** \\brief  Offset for Ifx_FFT_OCS_Bits.SUS */
#define IFX_FFT_OCS_SUS_OFF (24)

/** \\brief  Length for Ifx_FFT_OCS_Bits.SUS_P */
#define IFX_FFT_OCS_SUS_P_LEN (1)

/** \\brief  Mask for Ifx_FFT_OCS_Bits.SUS_P */
#define IFX_FFT_OCS_SUS_P_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_OCS_Bits.SUS_P */
#define IFX_FFT_OCS_SUS_P_OFF (28)

/** \\brief  Length for Ifx_FFT_OCS_Bits.SUSSTA */
#define IFX_FFT_OCS_SUSSTA_LEN (1)

/** \\brief  Mask for Ifx_FFT_OCS_Bits.SUSSTA */
#define IFX_FFT_OCS_SUSSTA_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_OCS_Bits.SUSSTA */
#define IFX_FFT_OCS_SUSSTA_OFF (29)

/** \\brief  Length for Ifx_FFT_ODA_Bits.DDREN */
#define IFX_FFT_ODA_DDREN_LEN (1)

/** \\brief  Mask for Ifx_FFT_ODA_Bits.DDREN */
#define IFX_FFT_ODA_DDREN_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_ODA_Bits.DDREN */
#define IFX_FFT_ODA_DDREN_OFF (0)

/** \\brief  Length for Ifx_FFT_ODA_Bits.DRDIS */
#define IFX_FFT_ODA_DRDIS_LEN (1)

/** \\brief  Mask for Ifx_FFT_ODA_Bits.DRDIS */
#define IFX_FFT_ODA_DRDIS_MSK (0x1)

/** \\brief  Offset for Ifx_FFT_ODA_Bits.DRDIS */
#define IFX_FFT_ODA_DRDIS_OFF (1)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXFFT_BF_H */

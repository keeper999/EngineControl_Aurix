/**
 * \file IfxAgbt_bf.h
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
 * \defgroup IfxLld_Agbt_BitfieldsMask Bitfields mask and offset
 * \ingroup IfxLld_Agbt
 * 
 */
#ifndef IFXAGBT_BF_H
#define IFXAGBT_BF_H
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Agbt_BitfieldsMask
 * \{  */

/** \\brief  Length for Ifx_AGBT_CLC_Bits.DISR */
#define IFX_AGBT_CLC_DISR_LEN (1)

/** \\brief  Mask for Ifx_AGBT_CLC_Bits.DISR */
#define IFX_AGBT_CLC_DISR_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_CLC_Bits.DISR */
#define IFX_AGBT_CLC_DISR_OFF (0)

/** \\brief  Length for Ifx_AGBT_CLC_Bits.DISS */
#define IFX_AGBT_CLC_DISS_LEN (1)

/** \\brief  Mask for Ifx_AGBT_CLC_Bits.DISS */
#define IFX_AGBT_CLC_DISS_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_CLC_Bits.DISS */
#define IFX_AGBT_CLC_DISS_OFF (1)

/** \\brief  Length for Ifx_AGBT_FBFLV_Bits.CURLVL */
#define IFX_AGBT_FBFLV_CURLVL_LEN (8)

/** \\brief  Mask for Ifx_AGBT_FBFLV_Bits.CURLVL */
#define IFX_AGBT_FBFLV_CURLVL_MSK (0xff)

/** \\brief  Offset for Ifx_AGBT_FBFLV_Bits.CURLVL */
#define IFX_AGBT_FBFLV_CURLVL_OFF (0)

/** \\brief  Length for Ifx_AGBT_FBFLV_Bits.MAXLVL */
#define IFX_AGBT_FBFLV_MAXLVL_LEN (8)

/** \\brief  Mask for Ifx_AGBT_FBFLV_Bits.MAXLVL */
#define IFX_AGBT_FBFLV_MAXLVL_MSK (0xff)

/** \\brief  Offset for Ifx_AGBT_FBFLV_Bits.MAXLVL */
#define IFX_AGBT_FBFLV_MAXLVL_OFF (8)

/** \\brief  Length for Ifx_AGBT_FCTRL_Bits.WMLVL */
#define IFX_AGBT_FCTRL_WMLVL_LEN (8)

/** \\brief  Mask for Ifx_AGBT_FCTRL_Bits.WMLVL */
#define IFX_AGBT_FCTRL_WMLVL_MSK (0xff)

/** \\brief  Offset for Ifx_AGBT_FCTRL_Bits.WMLVL */
#define IFX_AGBT_FCTRL_WMLVL_OFF (0)

/** \\brief  Length for Ifx_AGBT_ID_Bits.MOD_REV */
#define IFX_AGBT_ID_MOD_REV_LEN (8)

/** \\brief  Mask for Ifx_AGBT_ID_Bits.MOD_REV */
#define IFX_AGBT_ID_MOD_REV_MSK (0xff)

/** \\brief  Offset for Ifx_AGBT_ID_Bits.MOD_REV */
#define IFX_AGBT_ID_MOD_REV_OFF (0)

/** \\brief  Length for Ifx_AGBT_ID_Bits.MOD_TYPE */
#define IFX_AGBT_ID_MOD_TYPE_LEN (8)

/** \\brief  Mask for Ifx_AGBT_ID_Bits.MOD_TYPE */
#define IFX_AGBT_ID_MOD_TYPE_MSK (0xff)

/** \\brief  Offset for Ifx_AGBT_ID_Bits.MOD_TYPE */
#define IFX_AGBT_ID_MOD_TYPE_OFF (8)

/** \\brief  Length for Ifx_AGBT_ID_Bits.MODNUMBER */
#define IFX_AGBT_ID_MODNUMBER_LEN (16)

/** \\brief  Mask for Ifx_AGBT_ID_Bits.MODNUMBER */
#define IFX_AGBT_ID_MODNUMBER_MSK (0xffff)

/** \\brief  Offset for Ifx_AGBT_ID_Bits.MODNUMBER */
#define IFX_AGBT_ID_MODNUMBER_OFF (16)

/** \\brief  Length for Ifx_AGBT_IRE_Bits.FERE */
#define IFX_AGBT_IRE_FERE_LEN (1)

/** \\brief  Mask for Ifx_AGBT_IRE_Bits.FERE */
#define IFX_AGBT_IRE_FERE_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_IRE_Bits.FERE */
#define IFX_AGBT_IRE_FERE_OFF (3)

/** \\brief  Length for Ifx_AGBT_IRE_Bits.HWE */
#define IFX_AGBT_IRE_HWE_LEN (1)

/** \\brief  Mask for Ifx_AGBT_IRE_Bits.HWE */
#define IFX_AGBT_IRE_HWE_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_IRE_Bits.HWE */
#define IFX_AGBT_IRE_HWE_OFF (2)

/** \\brief  Length for Ifx_AGBT_IRE_Bits.OFWE */
#define IFX_AGBT_IRE_OFWE_LEN (1)

/** \\brief  Mask for Ifx_AGBT_IRE_Bits.OFWE */
#define IFX_AGBT_IRE_OFWE_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_IRE_Bits.OFWE */
#define IFX_AGBT_IRE_OFWE_OFF (0)

/** \\brief  Length for Ifx_AGBT_IRE_Bits.WME */
#define IFX_AGBT_IRE_WME_LEN (1)

/** \\brief  Mask for Ifx_AGBT_IRE_Bits.WME */
#define IFX_AGBT_IRE_WME_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_IRE_Bits.WME */
#define IFX_AGBT_IRE_WME_OFF (1)

/** \\brief  Length for Ifx_AGBT_IRS_Bits.FER */
#define IFX_AGBT_IRS_FER_LEN (1)

/** \\brief  Mask for Ifx_AGBT_IRS_Bits.FER */
#define IFX_AGBT_IRS_FER_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_IRS_Bits.FER */
#define IFX_AGBT_IRS_FER_OFF (3)

/** \\brief  Length for Ifx_AGBT_IRS_Bits.HW */
#define IFX_AGBT_IRS_HW_LEN (1)

/** \\brief  Mask for Ifx_AGBT_IRS_Bits.HW */
#define IFX_AGBT_IRS_HW_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_IRS_Bits.HW */
#define IFX_AGBT_IRS_HW_OFF (2)

/** \\brief  Length for Ifx_AGBT_IRS_Bits.OFW */
#define IFX_AGBT_IRS_OFW_LEN (1)

/** \\brief  Mask for Ifx_AGBT_IRS_Bits.OFW */
#define IFX_AGBT_IRS_OFW_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_IRS_Bits.OFW */
#define IFX_AGBT_IRS_OFW_OFF (0)

/** \\brief  Length for Ifx_AGBT_IRS_Bits.WM */
#define IFX_AGBT_IRS_WM_LEN (1)

/** \\brief  Mask for Ifx_AGBT_IRS_Bits.WM */
#define IFX_AGBT_IRS_WM_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_IRS_Bits.WM */
#define IFX_AGBT_IRS_WM_OFF (1)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR0 */
#define IFX_AGBT_PLC1_PCTR0_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR0 */
#define IFX_AGBT_PLC1_PCTR0_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR0 */
#define IFX_AGBT_PLC1_PCTR0_OFF (0)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR10 */
#define IFX_AGBT_PLC1_PCTR10_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR10 */
#define IFX_AGBT_PLC1_PCTR10_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR10 */
#define IFX_AGBT_PLC1_PCTR10_OFF (10)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR11 */
#define IFX_AGBT_PLC1_PCTR11_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR11 */
#define IFX_AGBT_PLC1_PCTR11_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR11 */
#define IFX_AGBT_PLC1_PCTR11_OFF (11)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR12 */
#define IFX_AGBT_PLC1_PCTR12_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR12 */
#define IFX_AGBT_PLC1_PCTR12_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR12 */
#define IFX_AGBT_PLC1_PCTR12_OFF (12)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR13_15 */
#define IFX_AGBT_PLC1_PCTR13_15_LEN (3)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR13_15 */
#define IFX_AGBT_PLC1_PCTR13_15_MSK (0x7)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR13_15 */
#define IFX_AGBT_PLC1_PCTR13_15_OFF (13)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR16 */
#define IFX_AGBT_PLC1_PCTR16_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR16 */
#define IFX_AGBT_PLC1_PCTR16_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR16 */
#define IFX_AGBT_PLC1_PCTR16_OFF (16)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR17 */
#define IFX_AGBT_PLC1_PCTR17_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR17 */
#define IFX_AGBT_PLC1_PCTR17_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR17 */
#define IFX_AGBT_PLC1_PCTR17_OFF (17)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR18_20 */
#define IFX_AGBT_PLC1_PCTR18_20_LEN (3)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR18_20 */
#define IFX_AGBT_PLC1_PCTR18_20_MSK (0x7)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR18_20 */
#define IFX_AGBT_PLC1_PCTR18_20_OFF (18)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR1 */
#define IFX_AGBT_PLC1_PCTR1_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR1 */
#define IFX_AGBT_PLC1_PCTR1_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR1 */
#define IFX_AGBT_PLC1_PCTR1_OFF (1)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR21_23 */
#define IFX_AGBT_PLC1_PCTR21_23_LEN (3)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR21_23 */
#define IFX_AGBT_PLC1_PCTR21_23_MSK (0x7)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR21_23 */
#define IFX_AGBT_PLC1_PCTR21_23_OFF (21)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR24 */
#define IFX_AGBT_PLC1_PCTR24_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR24 */
#define IFX_AGBT_PLC1_PCTR24_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR24 */
#define IFX_AGBT_PLC1_PCTR24_OFF (24)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR25 */
#define IFX_AGBT_PLC1_PCTR25_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR25 */
#define IFX_AGBT_PLC1_PCTR25_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR25 */
#define IFX_AGBT_PLC1_PCTR25_OFF (25)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR2 */
#define IFX_AGBT_PLC1_PCTR2_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR2 */
#define IFX_AGBT_PLC1_PCTR2_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR2 */
#define IFX_AGBT_PLC1_PCTR2_OFF (2)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR3 */
#define IFX_AGBT_PLC1_PCTR3_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR3 */
#define IFX_AGBT_PLC1_PCTR3_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR3 */
#define IFX_AGBT_PLC1_PCTR3_OFF (3)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR4 */
#define IFX_AGBT_PLC1_PCTR4_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR4 */
#define IFX_AGBT_PLC1_PCTR4_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR4 */
#define IFX_AGBT_PLC1_PCTR4_OFF (4)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR8 */
#define IFX_AGBT_PLC1_PCTR8_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR8 */
#define IFX_AGBT_PLC1_PCTR8_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR8 */
#define IFX_AGBT_PLC1_PCTR8_OFF (8)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTR9 */
#define IFX_AGBT_PLC1_PCTR9_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTR9 */
#define IFX_AGBT_PLC1_PCTR9_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTR9 */
#define IFX_AGBT_PLC1_PCTR9_OFF (9)

/** \\brief  Length for Ifx_AGBT_PLC1_Bits.PCTRA */
#define IFX_AGBT_PLC1_PCTRA_LEN (6)

/** \\brief  Mask for Ifx_AGBT_PLC1_Bits.PCTRA */
#define IFX_AGBT_PLC1_PCTRA_MSK (0x3f)

/** \\brief  Offset for Ifx_AGBT_PLC1_Bits.PCTRA */
#define IFX_AGBT_PLC1_PCTRA_OFF (26)

/** \\brief  Length for Ifx_AGBT_PLC2_Bits.PCTRL2 */
#define IFX_AGBT_PLC2_PCTRL2_LEN (32)

/** \\brief  Mask for Ifx_AGBT_PLC2_Bits.PCTRL2 */
#define IFX_AGBT_PLC2_PCTRL2_MSK (0xffffffff)

/** \\brief  Offset for Ifx_AGBT_PLC2_Bits.PCTRL2 */
#define IFX_AGBT_PLC2_PCTRL2_OFF (0)

/** \\brief  Length for Ifx_AGBT_PLC3_Bits.CBTRIMCUR */
#define IFX_AGBT_PLC3_CBTRIMCUR_LEN (3)

/** \\brief  Mask for Ifx_AGBT_PLC3_Bits.CBTRIMCUR */
#define IFX_AGBT_PLC3_CBTRIMCUR_MSK (0x7)

/** \\brief  Offset for Ifx_AGBT_PLC3_Bits.CBTRIMCUR */
#define IFX_AGBT_PLC3_CBTRIMCUR_OFF (24)

/** \\brief  Length for Ifx_AGBT_PLC3_Bits.PFCW */
#define IFX_AGBT_PLC3_PFCW_LEN (24)

/** \\brief  Mask for Ifx_AGBT_PLC3_Bits.PFCW */
#define IFX_AGBT_PLC3_PFCW_MSK (0xffffff)

/** \\brief  Offset for Ifx_AGBT_PLC3_Bits.PFCW */
#define IFX_AGBT_PLC3_PFCW_OFF (0)

/** \\brief  Length for Ifx_AGBT_PLC3_Bits.PRS */
#define IFX_AGBT_PLC3_PRS_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC3_Bits.PRS */
#define IFX_AGBT_PLC3_PRS_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC3_Bits.PRS */
#define IFX_AGBT_PLC3_PRS_OFF (31)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.CLKRXSCMR */
#define IFX_AGBT_PLC4_CLKRXSCMR_LEN (3)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.CLKRXSCMR */
#define IFX_AGBT_PLC4_CLKRXSCMR_MSK (0x7)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.CLKRXSCMR */
#define IFX_AGBT_PLC4_CLKRXSCMR_OFF (12)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.CLKRXSRTER */
#define IFX_AGBT_PLC4_CLKRXSRTER_LEN (4)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.CLKRXSRTER */
#define IFX_AGBT_PLC4_CLKRXSRTER_MSK (0xf)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.CLKRXSRTER */
#define IFX_AGBT_PLC4_CLKRXSRTER_OFF (27)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.DPARE */
#define IFX_AGBT_PLC4_DPARE_LEN (3)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.DPARE */
#define IFX_AGBT_PLC4_DPARE_MSK (0x7)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.DPARE */
#define IFX_AGBT_PLC4_DPARE_OFF (5)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.DPBYS */
#define IFX_AGBT_PLC4_DPBYS_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.DPBYS */
#define IFX_AGBT_PLC4_DPBYS_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.DPBYS */
#define IFX_AGBT_PLC4_DPBYS_OFF (11)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.DPNBS */
#define IFX_AGBT_PLC4_DPNBS_LEN (2)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.DPNBS */
#define IFX_AGBT_PLC4_DPNBS_MSK (0x3)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.DPNBS */
#define IFX_AGBT_PLC4_DPNBS_OFF (3)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.DPSRE */
#define IFX_AGBT_PLC4_DPSRE_LEN (3)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.DPSRE */
#define IFX_AGBT_PLC4_DPSRE_MSK (0x7)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.DPSRE */
#define IFX_AGBT_PLC4_DPSRE_OFF (8)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.OCDCVS */
#define IFX_AGBT_PLC4_OCDCVS_LEN (4)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.OCDCVS */
#define IFX_AGBT_PLC4_OCDCVS_MSK (0xf)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.OCDCVS */
#define IFX_AGBT_PLC4_OCDCVS_OFF (16)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.OCDDIFEN */
#define IFX_AGBT_PLC4_OCDDIFEN_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.OCDDIFEN */
#define IFX_AGBT_PLC4_OCDDIFEN_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.OCDDIFEN */
#define IFX_AGBT_PLC4_OCDDIFEN_OFF (31)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.OCDRTS */
#define IFX_AGBT_PLC4_OCDRTS_LEN (5)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.OCDRTS */
#define IFX_AGBT_PLC4_OCDRTS_MSK (0x1f)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.OCDRTS */
#define IFX_AGBT_PLC4_OCDRTS_OFF (20)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.PCSBSW */
#define IFX_AGBT_PLC4_PCSBSW_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.PCSBSW */
#define IFX_AGBT_PLC4_PCSBSW_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.PCSBSW */
#define IFX_AGBT_PLC4_PCSBSW_OFF (26)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.PCSMSB */
#define IFX_AGBT_PLC4_PCSMSB_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.PCSMSB */
#define IFX_AGBT_PLC4_PCSMSB_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.PCSMSB */
#define IFX_AGBT_PLC4_PCSMSB_OFF (25)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.PCSP */
#define IFX_AGBT_PLC4_PCSP_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.PCSP */
#define IFX_AGBT_PLC4_PCSP_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.PCSP */
#define IFX_AGBT_PLC4_PCSP_OFF (0)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.SERDEM */
#define IFX_AGBT_PLC4_SERDEM_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.SERDEM */
#define IFX_AGBT_PLC4_SERDEM_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.SERDEM */
#define IFX_AGBT_PLC4_SERDEM_OFF (2)

/** \\brief  Length for Ifx_AGBT_PLC4_Bits.SEREN */
#define IFX_AGBT_PLC4_SEREN_LEN (1)

/** \\brief  Mask for Ifx_AGBT_PLC4_Bits.SEREN */
#define IFX_AGBT_PLC4_SEREN_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_PLC4_Bits.SEREN */
#define IFX_AGBT_PLC4_SEREN_OFF (1)

/** \\brief  Length for Ifx_AGBT_PLC5_Bits.PLLREGDO */
#define IFX_AGBT_PLC5_PLLREGDO_LEN (32)

/** \\brief  Mask for Ifx_AGBT_PLC5_Bits.PLLREGDO */
#define IFX_AGBT_PLC5_PLLREGDO_MSK (0xffffffff)

/** \\brief  Offset for Ifx_AGBT_PLC5_Bits.PLLREGDO */
#define IFX_AGBT_PLC5_PLLREGDO_OFF (0)

/** \\brief  Length for Ifx_AGBT_TACU_Bits.ACIC */
#define IFX_AGBT_TACU_ACIC_LEN (24)

/** \\brief  Mask for Ifx_AGBT_TACU_Bits.ACIC */
#define IFX_AGBT_TACU_ACIC_MSK (0xffffff)

/** \\brief  Offset for Ifx_AGBT_TACU_Bits.ACIC */
#define IFX_AGBT_TACU_ACIC_OFF (0)

/** \\brief  Length for Ifx_AGBT_TACU_Bits.ACIEN */
#define IFX_AGBT_TACU_ACIEN_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TACU_Bits.ACIEN */
#define IFX_AGBT_TACU_ACIEN_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TACU_Bits.ACIEN */
#define IFX_AGBT_TACU_ACIEN_OFF (31)

/** \\brief  Length for Ifx_AGBT_TCR_Bits.AGBTON */
#define IFX_AGBT_TCR_AGBTON_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TCR_Bits.AGBTON */
#define IFX_AGBT_TCR_AGBTON_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TCR_Bits.AGBTON */
#define IFX_AGBT_TCR_AGBTON_OFF (16)

/** \\brief  Length for Ifx_AGBT_TCR_Bits.ATPMON */
#define IFX_AGBT_TCR_ATPMON_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TCR_Bits.ATPMON */
#define IFX_AGBT_TCR_ATPMON_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TCR_Bits.ATPMON */
#define IFX_AGBT_TCR_ATPMON_OFF (19)

/** \\brief  Length for Ifx_AGBT_TCR_Bits.BD */
#define IFX_AGBT_TCR_BD_LEN (3)

/** \\brief  Mask for Ifx_AGBT_TCR_Bits.BD */
#define IFX_AGBT_TCR_BD_MSK (0x7)

/** \\brief  Offset for Ifx_AGBT_TCR_Bits.BD */
#define IFX_AGBT_TCR_BD_OFF (5)

/** \\brief  Length for Ifx_AGBT_TCR_Bits.CRCON */
#define IFX_AGBT_TCR_CRCON_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TCR_Bits.CRCON */
#define IFX_AGBT_TCR_CRCON_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TCR_Bits.CRCON */
#define IFX_AGBT_TCR_CRCON_OFF (18)

/** \\brief  Length for Ifx_AGBT_TCR_Bits.PLLE */
#define IFX_AGBT_TCR_PLLE_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TCR_Bits.PLLE */
#define IFX_AGBT_TCR_PLLE_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TCR_Bits.PLLE */
#define IFX_AGBT_TCR_PLLE_OFF (1)

/** \\brief  Length for Ifx_AGBT_TCR_Bits.PON */
#define IFX_AGBT_TCR_PON_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TCR_Bits.PON */
#define IFX_AGBT_TCR_PON_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TCR_Bits.PON */
#define IFX_AGBT_TCR_PON_OFF (3)

/** \\brief  Length for Ifx_AGBT_TCR_Bits.TE */
#define IFX_AGBT_TCR_TE_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TCR_Bits.TE */
#define IFX_AGBT_TCR_TE_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TCR_Bits.TE */
#define IFX_AGBT_TCR_TE_OFF (0)

/** \\brief  Length for Ifx_AGBT_TCR_Bits.TPV */
#define IFX_AGBT_TCR_TPV_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TCR_Bits.TPV */
#define IFX_AGBT_TCR_TPV_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TCR_Bits.TPV */
#define IFX_AGBT_TCR_TPV_OFF (4)

/** \\brief  Length for Ifx_AGBT_TCR_Bits.TXA */
#define IFX_AGBT_TCR_TXA_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TCR_Bits.TXA */
#define IFX_AGBT_TCR_TXA_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TCR_Bits.TXA */
#define IFX_AGBT_TCR_TXA_OFF (2)

/** \\brief  Length for Ifx_AGBT_TSR_Bits.ATBS */
#define IFX_AGBT_TSR_ATBS_LEN (2)

/** \\brief  Mask for Ifx_AGBT_TSR_Bits.ATBS */
#define IFX_AGBT_TSR_ATBS_MSK (0x3)

/** \\brief  Offset for Ifx_AGBT_TSR_Bits.ATBS */
#define IFX_AGBT_TSR_ATBS_OFF (3)

/** \\brief  Length for Ifx_AGBT_TSR_Bits.CHUP */
#define IFX_AGBT_TSR_CHUP_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TSR_Bits.CHUP */
#define IFX_AGBT_TSR_CHUP_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TSR_Bits.CHUP */
#define IFX_AGBT_TSR_CHUP_OFF (31)

/** \\brief  Length for Ifx_AGBT_TSR_Bits.FBE */
#define IFX_AGBT_TSR_FBE_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TSR_Bits.FBE */
#define IFX_AGBT_TSR_FBE_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TSR_Bits.FBE */
#define IFX_AGBT_TSR_FBE_OFF (1)

/** \\brief  Length for Ifx_AGBT_TSR_Bits.PLK */
#define IFX_AGBT_TSR_PLK_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TSR_Bits.PLK */
#define IFX_AGBT_TSR_PLK_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TSR_Bits.PLK */
#define IFX_AGBT_TSR_PLK_OFF (2)

/** \\brief  Length for Ifx_AGBT_TSR_Bits.TXLNUP */
#define IFX_AGBT_TSR_TXLNUP_LEN (1)

/** \\brief  Mask for Ifx_AGBT_TSR_Bits.TXLNUP */
#define IFX_AGBT_TSR_TXLNUP_MSK (0x1)

/** \\brief  Offset for Ifx_AGBT_TSR_Bits.TXLNUP */
#define IFX_AGBT_TSR_TXLNUP_OFF (0)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXAGBT_BF_H */

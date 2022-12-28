/**
 * \file IfxAgbt_reg.h
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
 * \defgroup IfxLld_Agbt_Cfg Agbt address
 * \ingroup IfxLld_Agbt
 * 
 * \defgroup IfxLld_Agbt_Cfg_BaseAddress Base address
 * \ingroup IfxLld_Agbt_Cfg
 * 
 * \defgroup IfxLld_Agbt_Cfg_Agbt 2-AGBT
 * \ingroup IfxLld_Agbt_Cfg
 * 
 */
#ifndef IFXAGBT_REG_H
#define IFXAGBT_REG_H
/******************************************************************************/
#include "IfxAgbt_regdef.h"
/******************************************************************************/
/** \addtogroup IfxLld_Agbt_Cfg_BaseAddress
 * \{  */

/** \\brief  AGBT object */
#define MODULE_AGBT /*lint --e(923)*/ ((*(Ifx_AGBT*)0xF90E1000u))
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Agbt_Cfg_Agbt
 * \{  */

/** \\brief  0, Clock Control Register */
#define AGBT_CLC /*lint --e(923)*/ (*(volatile Ifx_AGBT_CLC*)0xF90E1000u)

/** \\brief  20, FIFO Block Fill Level */
#define AGBT_FBFLV /*lint --e(923)*/ (*(volatile Ifx_AGBT_FBFLV*)0xF90E1020u)

/** \\brief  18, FIFO Control Register */
#define AGBT_FCTRL /*lint --e(923)*/ (*(volatile Ifx_AGBT_FCTRL*)0xF90E1018u)

/** \\brief  8, Module Identification Register */
#define AGBT_ID /*lint --e(923)*/ (*(volatile Ifx_AGBT_ID*)0xF90E1008u)

/** \\brief  28, EMEM Interrupt enable register */
#define AGBT_IRE /*lint --e(923)*/ (*(volatile Ifx_AGBT_IRE*)0xF90E1028u)

/** \\brief  24, EMEM Interrupt status register */
#define AGBT_IRS /*lint --e(923)*/ (*(volatile Ifx_AGBT_IRS*)0xF90E1024u)

/** \\brief  30, EMEM PLL Control Register 1 */
#define AGBT_PLC1 /*lint --e(923)*/ (*(volatile Ifx_AGBT_PLC1*)0xF90E1030u)

/** \\brief  34, EMEM PLL Control Register 2 */
#define AGBT_PLC2 /*lint --e(923)*/ (*(volatile Ifx_AGBT_PLC2*)0xF90E1034u)

/** \\brief  38, EMEM PLL Control Register 3 */
#define AGBT_PLC3 /*lint --e(923)*/ (*(volatile Ifx_AGBT_PLC3*)0xF90E1038u)

/** \\brief  3C, EMEM Physical Layer Control Register 4 */
#define AGBT_PLC4 /*lint --e(923)*/ (*(volatile Ifx_AGBT_PLC4*)0xF90E103Cu)

/** \\brief  50, EMEM Production Test Register 5 */
#define AGBT_PLC5 /*lint --e(923)*/ (*(volatile Ifx_AGBT_PLC5*)0xF90E1050u)

/** \\brief  1C, Trace Auto Channel UP */
#define AGBT_TACU /*lint --e(923)*/ (*(volatile Ifx_AGBT_TACU*)0xF90E101Cu)

/** \\brief  10, Trace Control Register */
#define AGBT_TCR /*lint --e(923)*/ (*(volatile Ifx_AGBT_TCR*)0xF90E1010u)

/** \\brief  14, Trace Status Register */
#define AGBT_TSR /*lint --e(923)*/ (*(volatile Ifx_AGBT_TSR*)0xF90E1014u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXAGBT_REG_H */

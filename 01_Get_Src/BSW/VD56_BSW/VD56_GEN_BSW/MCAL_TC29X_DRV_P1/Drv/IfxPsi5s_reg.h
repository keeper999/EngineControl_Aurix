/**
 * \file IfxPsi5s_reg.h
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
 * \defgroup IfxLld_Psi5s_Cfg Psi5s address
 * \ingroup IfxLld_Psi5s
 * 
 * \defgroup IfxLld_Psi5s_Cfg_BaseAddress Base address
 * \ingroup IfxLld_Psi5s_Cfg
 * 
 * \defgroup IfxLld_Psi5s_Cfg_Psi5s 2-PSI5S
 * \ingroup IfxLld_Psi5s_Cfg
 * 
 */
#ifndef IFXPSI5S_REG_H
#define IFXPSI5S_REG_H
/******************************************************************************/
#include "IfxPsi5s_regdef.h"
/******************************************************************************/
/** \addtogroup IfxLld_Psi5s_Cfg_BaseAddress
 * \{  */

/** \\brief  PSI5S object */
#define MODULE_PSI5S /*lint --e(923)*/ ((*(Ifx_PSI5S*)0xF0007000u))
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Psi5s_Cfg_Psi5s
 * \{  */

/** \\brief  3D0, Access Enable Register 0 */
#define PSI5S_ACCEN0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_ACCEN0*)0xF00073D0u)

/** \\brief  3D4, Access Enable Register 1 */
#define PSI5S_ACCEN1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_ACCEN1*)0xF00073D4u)

/** \\brief  D4, Base Address Register */
#define PSI5S_BAR /*lint --e(923)*/ (*(volatile Ifx_PSI5S_BAR*)0xF00070D4u)

/** \\brief  214, Baud Rate Timer/Reload Register */
#define PSI5S_BG /*lint --e(923)*/ (*(volatile Ifx_PSI5S_BG*)0xF0007214u)

/** \\brief  170, CPU Direct Write Register */
#define PSI5S_CDW /*lint --e(923)*/ (*(volatile Ifx_PSI5S_CDW*)0xF0007170u)

/** \\brief  0, Clock Control Register */
#define PSI5S_CLC /*lint --e(923)*/ (*(volatile Ifx_PSI5S_CLC*)0xF0007000u)

/** \\brief  210, Control Register */
#define PSI5S_CON /*lint --e(923)*/ (*(volatile Ifx_PSI5S_CON*)0xF0007210u)

/** \\brief  110, Channel Trigger Value Register */
#define PSI5S_CTV0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_CTV*)0xF0007110u)

/** \\brief  114, Channel Trigger Value Register */
#define PSI5S_CTV1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_CTV*)0xF0007114u)

/** \\brief  118, Channel Trigger Value Register */
#define PSI5S_CTV2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_CTV*)0xF0007118u)

/** \\brief  11C, Channel Trigger Value Register */
#define PSI5S_CTV3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_CTV*)0xF000711Cu)

/** \\brief  120, Channel Trigger Value Register */
#define PSI5S_CTV4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_CTV*)0xF0007120u)

/** \\brief  24, Frame Counter Register */
#define PSI5S_FCNT /*lint --e(923)*/ (*(volatile Ifx_PSI5S_FCNT*)0xF0007024u)

/** \\brief  21C, Fractional Divider for Output CLK Register */
#define PSI5S_FDO /*lint --e(923)*/ (*(volatile Ifx_PSI5S_FDO*)0xF000721Cu)

/** \\brief  C, SMU Fractional Divider Register */
#define PSI5S_FDR /*lint --e(923)*/ (*(volatile Ifx_PSI5S_FDR*)0xF000700Cu)

/** \\brief  10, Fractional Divider Register for Time Stamp */
#define PSI5S_FDRT /*lint --e(923)*/ (*(volatile Ifx_PSI5S_FDRT*)0xF0007010u)

/** \\brief  218, Fractional Divider Register */
#define PSI5S_FDV /*lint --e(923)*/ (*(volatile Ifx_PSI5S_FDV*)0xF0007218u)

/** \\brief  1C, Global Control Register */
#define PSI5S_GCR /*lint --e(923)*/ (*(volatile Ifx_PSI5S_GCR*)0xF000701Cu)

/** \\brief  8, Module Identification Register */
#define PSI5S_ID /*lint --e(923)*/ (*(volatile Ifx_PSI5S_ID*)0xF0007008u)

/** \\brief  2E0, Interrupt Node Pointer Register */
#define PSI5S_INP0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INP*)0xF00072E0u)

/** \\brief  2E4, Interrupt Node Pointer Register */
#define PSI5S_INP1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INP*)0xF00072E4u)

/** \\brief  2E8, Interrupt Node Pointer Register */
#define PSI5S_INP2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INP*)0xF00072E8u)

/** \\brief  2EC, Interrupt Node Pointer Register */
#define PSI5S_INP3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INP*)0xF00072ECu)

/** \\brief  2F0, Interrupt Node Pointer Register */
#define PSI5S_INP4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INP*)0xF00072F0u)

/** \\brief  314, Interrupt Node Pointer G Register */
#define PSI5S_INPG /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INPG*)0xF0007314u)

/** \\brief  2A0, Interrupt Clear Register */
#define PSI5S_INTCLR0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTCLR*)0xF00072A0u)

/** \\brief  2A4, Interrupt Clear Register */
#define PSI5S_INTCLR1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTCLR*)0xF00072A4u)

/** \\brief  2A8, Interrupt Clear Register */
#define PSI5S_INTCLR2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTCLR*)0xF00072A8u)

/** \\brief  2AC, Interrupt Clear Register */
#define PSI5S_INTCLR3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTCLR*)0xF00072ACu)

/** \\brief  2B0, Interrupt Clear Register */
#define PSI5S_INTCLR4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTCLR*)0xF00072B0u)

/** \\brief  30C, Interrupt Clear Register G */
#define PSI5S_INTCLRG /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTCLRG*)0xF000730Cu)

/** \\brief  2C0, Interrupt Enable Register */
#define PSI5S_INTEN0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTEN*)0xF00072C0u)

/** \\brief  2C4, Interrupt Enable Register */
#define PSI5S_INTEN1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTEN*)0xF00072C4u)

/** \\brief  2C8, Interrupt Enable Register */
#define PSI5S_INTEN2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTEN*)0xF00072C8u)

/** \\brief  2CC, Interrupt Enable Register */
#define PSI5S_INTEN3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTEN*)0xF00072CCu)

/** \\brief  2D0, Interrupt Enable Register */
#define PSI5S_INTEN4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTEN*)0xF00072D0u)

/** \\brief  310, Interrupt Enable Register G */
#define PSI5S_INTENG /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTENG*)0xF0007310u)

/** \\brief  300, Interrupt Overview Register */
#define PSI5S_INTOV /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTOV*)0xF0007300u)

/** \\brief  280, Interrupt Set Register */
#define PSI5S_INTSET0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSET*)0xF0007280u)

/** \\brief  284, Interrupt Set Register */
#define PSI5S_INTSET1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSET*)0xF0007284u)

/** \\brief  288, Interrupt Set Register */
#define PSI5S_INTSET2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSET*)0xF0007288u)

/** \\brief  28C, Interrupt Set Register */
#define PSI5S_INTSET3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSET*)0xF000728Cu)

/** \\brief  290, Interrupt Set Register */
#define PSI5S_INTSET4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSET*)0xF0007290u)

/** \\brief  308, Interrupt Set Register G */
#define PSI5S_INTSETG /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSETG*)0xF0007308u)

/** \\brief  260, Interrupt Status Register */
#define PSI5S_INTSTAT0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSTAT*)0xF0007260u)

/** \\brief  264, Interrupt Status Register */
#define PSI5S_INTSTAT1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSTAT*)0xF0007264u)

/** \\brief  268, Interrupt Status Register */
#define PSI5S_INTSTAT2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSTAT*)0xF0007268u)

/** \\brief  26C, Interrupt Status Register */
#define PSI5S_INTSTAT3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSTAT*)0xF000726Cu)

/** \\brief  270, Interrupt Status Register */
#define PSI5S_INTSTAT4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSTAT*)0xF0007270u)

/** \\brief  304, Interrupt Status Register G */
#define PSI5S_INTSTATG /*lint --e(923)*/ (*(volatile Ifx_PSI5S_INTSTATG*)0xF0007304u)

/** \\brief  28, Input and Output Control Register */
#define PSI5S_IOCR /*lint --e(923)*/ (*(volatile Ifx_PSI5S_IOCR*)0xF0007028u)

/** \\brief  3D8, Kernel Reset Register 0 */
#define PSI5S_KRST0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_KRST0*)0xF00073D8u)

/** \\brief  3DC, Kernel Reset Register 1 */
#define PSI5S_KRST1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_KRST1*)0xF00073DCu)

/** \\brief  3E0, Kernel Reset Status Clear Register */
#define PSI5S_KRSTCLR /*lint --e(923)*/ (*(volatile Ifx_PSI5S_KRSTCLR*)0xF00073E0u)

/** \\brief  20, Number of Frames Control Register */
#define PSI5S_NFC /*lint --e(923)*/ (*(volatile Ifx_PSI5S_NFC*)0xF0007020u)

/** \\brief  3CC, OCDS Control and Status */
#define PSI5S_OCS /*lint --e(923)*/ (*(volatile Ifx_PSI5S_OCS*)0xF00073CCu)

/** \\brief  F0, Pulse Generation Control Register */
#define PSI5S_PGC0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_PGC*)0xF00070F0u)

/** \\brief  F4, Pulse Generation Control Register */
#define PSI5S_PGC1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_PGC*)0xF00070F4u)

/** \\brief  F8, Pulse Generation Control Register */
#define PSI5S_PGC2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_PGC*)0xF00070F8u)

/** \\brief  FC, Pulse Generation Control Register */
#define PSI5S_PGC3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_PGC*)0xF00070FCu)

/** \\brief  100, Pulse Generation Control Register */
#define PSI5S_PGC4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_PGC*)0xF0007100u)

/** \\brief  224, Receive Buffer Register */
#define PSI5S_RBUF /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RBUF*)0xF0007224u)

/** \\brief  30, Receiver Control Register A */
#define PSI5S_RCRA0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RCRA*)0xF0007030u)

/** \\brief  34, Receiver Control Register A */
#define PSI5S_RCRA1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RCRA*)0xF0007034u)

/** \\brief  38, Receiver Control Register A */
#define PSI5S_RCRA2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RCRA*)0xF0007038u)

/** \\brief  3C, Receiver Control Register A */
#define PSI5S_RCRA3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RCRA*)0xF000703Cu)

/** \\brief  40, Receiver Control Register A */
#define PSI5S_RCRA4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RCRA*)0xF0007040u)

/** \\brief  50, Receiver Control Register B */
#define PSI5S_RCRB0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RCRB*)0xF0007050u)

/** \\brief  54, Receiver Control Register B */
#define PSI5S_RCRB1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RCRB*)0xF0007054u)

/** \\brief  58, Receiver Control Register B */
#define PSI5S_RCRB2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RCRB*)0xF0007058u)

/** \\brief  5C, Receiver Control Register B */
#define PSI5S_RCRB3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RCRB*)0xF000705Cu)

/** \\brief  60, Receiver Control Register B */
#define PSI5S_RCRB4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RCRB*)0xF0007060u)

/** \\brief  B4, Receive Data Register */
#define PSI5S_RDR /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RDR*)0xF00070B4u)

/** \\brief  B0, Receive Status Register */
#define PSI5S_RDS /*lint --e(923)*/ (*(volatile Ifx_PSI5S_RDS*)0xF00070B0u)

/** \\brief  130, Send Control Register */
#define PSI5S_SCR0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_SCR*)0xF0007130u)

/** \\brief  134, Send Control Register */
#define PSI5S_SCR1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_SCR*)0xF0007134u)

/** \\brief  138, Send Control Register */
#define PSI5S_SCR2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_SCR*)0xF0007138u)

/** \\brief  13C, Send Control Register */
#define PSI5S_SCR3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_SCR*)0xF000713Cu)

/** \\brief  140, Send Control Register */
#define PSI5S_SCR4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_SCR*)0xF0007140u)

/** \\brief  150, Send Data Register */
#define PSI5S_SDR0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_SDR*)0xF0007150u)

/** \\brief  154, Send Data Register */
#define PSI5S_SDR1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_SDR*)0xF0007154u)

/** \\brief  158, Send Data Register */
#define PSI5S_SDR2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_SDR*)0xF0007158u)

/** \\brief  15C, Send Data Register */
#define PSI5S_SDR3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_SDR*)0xF000715Cu)

/** \\brief  160, Send Data Register */
#define PSI5S_SDR4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_SDR*)0xF0007160u)

/** \\brief  D0, Target Address Register */
#define PSI5S_TAR /*lint --e(923)*/ (*(volatile Ifx_PSI5S_TAR*)0xF00070D0u)

/** \\brief  220, Transmit Buffer Register */
#define PSI5S_TBUF /*lint --e(923)*/ (*(volatile Ifx_PSI5S_TBUF*)0xF0007220u)

/** \\brief  14, Time Stamp Count Register A */
#define PSI5S_TSCNTA /*lint --e(923)*/ (*(volatile Ifx_PSI5S_TSCNTA*)0xF0007014u)

/** \\brief  18, Time Stamp Count Register B */
#define PSI5S_TSCNTB /*lint --e(923)*/ (*(volatile Ifx_PSI5S_TSCNTB*)0xF0007018u)

/** \\brief  90, Capture Register */
#define PSI5S_TSCR0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_TSCR*)0xF0007090u)

/** \\brief  94, Capture Register */
#define PSI5S_TSCR1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_TSCR*)0xF0007094u)

/** \\brief  98, Capture Register */
#define PSI5S_TSCR2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_TSCR*)0xF0007098u)

/** \\brief  9C, Capture Register */
#define PSI5S_TSCR3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_TSCR*)0xF000709Cu)

/** \\brief  A0, Capture Register */
#define PSI5S_TSCR4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_TSCR*)0xF00070A0u)

/** \\brief  B8, Time Stamp Mirror Register TSM */
#define PSI5S_TSM /*lint --e(923)*/ (*(volatile Ifx_PSI5S_TSM*)0xF00070B8u)

/** \\brief  70, Watch Dog Timer Register */
#define PSI5S_WDT0 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_WDT*)0xF0007070u)

/** \\brief  74, Watch Dog Timer Register */
#define PSI5S_WDT1 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_WDT*)0xF0007074u)

/** \\brief  78, Watch Dog Timer Register */
#define PSI5S_WDT2 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_WDT*)0xF0007078u)

/** \\brief  7C, Watch Dog Timer Register */
#define PSI5S_WDT3 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_WDT*)0xF000707Cu)

/** \\brief  80, Watch Dog Timer Register */
#define PSI5S_WDT4 /*lint --e(923)*/ (*(volatile Ifx_PSI5S_WDT*)0xF0007080u)

/** \\brief  250, Write Hardware Bits Control Register */
#define PSI5S_WHBCON /*lint --e(923)*/ (*(volatile Ifx_PSI5S_WHBCON*)0xF0007250u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXPSI5S_REG_H */

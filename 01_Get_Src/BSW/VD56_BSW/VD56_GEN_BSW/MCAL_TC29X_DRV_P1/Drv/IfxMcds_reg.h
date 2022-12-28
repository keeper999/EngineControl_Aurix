/**
 * \file IfxMcds_reg.h
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
 * \defgroup IfxLld_Mcds_Cfg Mcds address
 * \ingroup IfxLld_Mcds
 * 
 * \defgroup IfxLld_Mcds_Cfg_BaseAddress Base address
 * \ingroup IfxLld_Mcds_Cfg
 * 
 * \defgroup IfxLld_Mcds_Cfg_Mcds 2-MCDS
 * \ingroup IfxLld_Mcds_Cfg
 * 
 */
#ifndef IFXMCDS_REG_H
#define IFXMCDS_REG_H
/******************************************************************************/
#include "IfxMcds_regdef.h"
/******************************************************************************/
/** \addtogroup IfxLld_Mcds_Cfg_BaseAddress
 * \{  */

/** \\brief  MCDS object */
#define MODULE_MCDS /*lint --e(923)*/ ((*(Ifx_MCDS*)0xF90E8000u))
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Mcds_Cfg_Mcds
 * \{  */

/** \\brief  0, Clock Control Register */
#define MCDS_CLC /*lint --e(923)*/ (*(volatile Ifx_MCDS_CLC*)0xF90E8000u)

/** \\brief  10, MCDS Control Register */
#define MCDS_CT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CT*)0xF90E8010u)

/** \\brief  204, Trace Buffer Bottom Register */
#define MCDS_FIFOBOT /*lint --e(923)*/ (*(volatile Ifx_MCDS_FIFOBOT*)0xF90E8204u)

/** \\brief  210, Trace Buffer Control Register */
#define MCDS_FIFOCTL /*lint --e(923)*/ (*(volatile Ifx_MCDS_FIFOCTL*)0xF90E8210u)

/** \\brief  200, Trace Buffer Write Pointer */
#define MCDS_FIFONOW /*lint --e(923)*/ (*(volatile Ifx_MCDS_FIFONOW*)0xF90E8200u)

/** \\brief  208, Trace Buffer PRE/POST Register */
#define MCDS_FIFOPRE /*lint --e(923)*/ (*(volatile Ifx_MCDS_FIFOPRE*)0xF90E8208u)

/** \\brief  20C, Trace Buffer Top Register */
#define MCDS_FIFOTOP /*lint --e(923)*/ (*(volatile Ifx_MCDS_FIFOTOP*)0xF90E820Cu)

/** \\brief  214, Trace Buffer Comparator Register */
#define MCDS_FIFOWARN0 /*lint --e(923)*/ (*(volatile Ifx_MCDS_FIFOWARN0*)0xF90E8214u)

/** \\brief  218, Trace Buffer Comparator Register */
#define MCDS_FIFOWARN1 /*lint --e(923)*/ (*(volatile Ifx_MCDS_FIFOWARN1*)0xF90E8218u)

/** \\brief  8, Module Identification Register */
#define MCDS_ID /*lint --e(923)*/ (*(volatile Ifx_MCDS_ID*)0xF90E8008u)

/** \\brief  880, Action Definition Register */
#define MCDS_MCX_ACT0 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8880u)

/** Alias (User Manual Name) for MCDS_MCX_ACT0.
* To use register names with standard convension, please use MCDS_MCX_ACT0.
*/
#define	MCDS_MCXACT0	(MCDS_MCX_ACT0)

/** \\brief  884, Action Definition Register */
#define MCDS_MCX_ACT1 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8884u)

/** Alias (User Manual Name) for MCDS_MCX_ACT1.
* To use register names with standard convension, please use MCDS_MCX_ACT1.
*/
#define	MCDS_MCXACT1	(MCDS_MCX_ACT1)

/** \\brief  8A8, Action Definition Register */
#define MCDS_MCX_ACT10 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88A8u)

/** Alias (User Manual Name) for MCDS_MCX_ACT10.
* To use register names with standard convension, please use MCDS_MCX_ACT10.
*/
#define	MCDS_MCXACT10	(MCDS_MCX_ACT10)

/** \\brief  8AC, Action Definition Register */
#define MCDS_MCX_ACT11 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88ACu)

/** Alias (User Manual Name) for MCDS_MCX_ACT11.
* To use register names with standard convension, please use MCDS_MCX_ACT11.
*/
#define	MCDS_MCXACT11	(MCDS_MCX_ACT11)

/** \\brief  8B0, Action Definition Register */
#define MCDS_MCX_ACT12 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88B0u)

/** Alias (User Manual Name) for MCDS_MCX_ACT12.
* To use register names with standard convension, please use MCDS_MCX_ACT12.
*/
#define	MCDS_MCXACT12	(MCDS_MCX_ACT12)

/** \\brief  8B4, Action Definition Register */
#define MCDS_MCX_ACT13 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88B4u)

/** Alias (User Manual Name) for MCDS_MCX_ACT13.
* To use register names with standard convension, please use MCDS_MCX_ACT13.
*/
#define	MCDS_MCXACT13	(MCDS_MCX_ACT13)

/** \\brief  8B8, Action Definition Register */
#define MCDS_MCX_ACT14 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88B8u)

/** Alias (User Manual Name) for MCDS_MCX_ACT14.
* To use register names with standard convension, please use MCDS_MCX_ACT14.
*/
#define	MCDS_MCXACT14	(MCDS_MCX_ACT14)

/** \\brief  8BC, Action Definition Register */
#define MCDS_MCX_ACT15 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88BCu)

/** Alias (User Manual Name) for MCDS_MCX_ACT15.
* To use register names with standard convension, please use MCDS_MCX_ACT15.
*/
#define	MCDS_MCXACT15	(MCDS_MCX_ACT15)

/** \\brief  8C0, Action Definition Register */
#define MCDS_MCX_ACT16 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88C0u)

/** Alias (User Manual Name) for MCDS_MCX_ACT16.
* To use register names with standard convension, please use MCDS_MCX_ACT16.
*/
#define	MCDS_MCXACT16	(MCDS_MCX_ACT16)

/** \\brief  8C4, Action Definition Register */
#define MCDS_MCX_ACT17 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88C4u)

/** Alias (User Manual Name) for MCDS_MCX_ACT17.
* To use register names with standard convension, please use MCDS_MCX_ACT17.
*/
#define	MCDS_MCXACT17	(MCDS_MCX_ACT17)

/** \\brief  8C8, Action Definition Register */
#define MCDS_MCX_ACT18 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88C8u)

/** Alias (User Manual Name) for MCDS_MCX_ACT18.
* To use register names with standard convension, please use MCDS_MCX_ACT18.
*/
#define	MCDS_MCXACT18	(MCDS_MCX_ACT18)

/** \\brief  8CC, Action Definition Register */
#define MCDS_MCX_ACT19 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88CCu)

/** Alias (User Manual Name) for MCDS_MCX_ACT19.
* To use register names with standard convension, please use MCDS_MCX_ACT19.
*/
#define	MCDS_MCXACT19	(MCDS_MCX_ACT19)

/** \\brief  888, Action Definition Register */
#define MCDS_MCX_ACT2 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8888u)

/** Alias (User Manual Name) for MCDS_MCX_ACT2.
* To use register names with standard convension, please use MCDS_MCX_ACT2.
*/
#define	MCDS_MCXACT2	(MCDS_MCX_ACT2)

/** \\brief  8D0, Action Definition Register */
#define MCDS_MCX_ACT20 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88D0u)

/** Alias (User Manual Name) for MCDS_MCX_ACT20.
* To use register names with standard convension, please use MCDS_MCX_ACT20.
*/
#define	MCDS_MCXACT20	(MCDS_MCX_ACT20)

/** \\brief  8D4, Action Definition Register */
#define MCDS_MCX_ACT21 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88D4u)

/** Alias (User Manual Name) for MCDS_MCX_ACT21.
* To use register names with standard convension, please use MCDS_MCX_ACT21.
*/
#define	MCDS_MCXACT21	(MCDS_MCX_ACT21)

/** \\brief  8D8, Action Definition Register */
#define MCDS_MCX_ACT22 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88D8u)

/** Alias (User Manual Name) for MCDS_MCX_ACT22.
* To use register names with standard convension, please use MCDS_MCX_ACT22.
*/
#define	MCDS_MCXACT22	(MCDS_MCX_ACT22)

/** \\brief  8DC, Action Definition Register */
#define MCDS_MCX_ACT23 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88DCu)

/** Alias (User Manual Name) for MCDS_MCX_ACT23.
* To use register names with standard convension, please use MCDS_MCX_ACT23.
*/
#define	MCDS_MCXACT23	(MCDS_MCX_ACT23)

/** \\brief  8E0, Action Definition Register */
#define MCDS_MCX_ACT24 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88E0u)

/** Alias (User Manual Name) for MCDS_MCX_ACT24.
* To use register names with standard convension, please use MCDS_MCX_ACT24.
*/
#define	MCDS_MCXACT24	(MCDS_MCX_ACT24)

/** \\brief  8E4, Action Definition Register */
#define MCDS_MCX_ACT25 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88E4u)

/** Alias (User Manual Name) for MCDS_MCX_ACT25.
* To use register names with standard convension, please use MCDS_MCX_ACT25.
*/
#define	MCDS_MCXACT25	(MCDS_MCX_ACT25)

/** \\brief  8E8, Action Definition Register */
#define MCDS_MCX_ACT26 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88E8u)

/** Alias (User Manual Name) for MCDS_MCX_ACT26.
* To use register names with standard convension, please use MCDS_MCX_ACT26.
*/
#define	MCDS_MCXACT26	(MCDS_MCX_ACT26)

/** \\brief  8EC, Action Definition Register */
#define MCDS_MCX_ACT27 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88ECu)

/** Alias (User Manual Name) for MCDS_MCX_ACT27.
* To use register names with standard convension, please use MCDS_MCX_ACT27.
*/
#define	MCDS_MCXACT27	(MCDS_MCX_ACT27)

/** \\brief  8F0, Action Definition Register */
#define MCDS_MCX_ACT28 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88F0u)

/** Alias (User Manual Name) for MCDS_MCX_ACT28.
* To use register names with standard convension, please use MCDS_MCX_ACT28.
*/
#define	MCDS_MCXACT28	(MCDS_MCX_ACT28)

/** \\brief  8F4, Action Definition Register */
#define MCDS_MCX_ACT29 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88F4u)

/** Alias (User Manual Name) for MCDS_MCX_ACT29.
* To use register names with standard convension, please use MCDS_MCX_ACT29.
*/
#define	MCDS_MCXACT29	(MCDS_MCX_ACT29)

/** \\brief  88C, Action Definition Register */
#define MCDS_MCX_ACT3 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E888Cu)

/** Alias (User Manual Name) for MCDS_MCX_ACT3.
* To use register names with standard convension, please use MCDS_MCX_ACT3.
*/
#define	MCDS_MCXACT3	(MCDS_MCX_ACT3)

/** \\brief  8F8, Action Definition Register */
#define MCDS_MCX_ACT30 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88F8u)

/** Alias (User Manual Name) for MCDS_MCX_ACT30.
* To use register names with standard convension, please use MCDS_MCX_ACT30.
*/
#define	MCDS_MCXACT30	(MCDS_MCX_ACT30)

/** \\brief  8FC, Action Definition Register */
#define MCDS_MCX_ACT31 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88FCu)

/** Alias (User Manual Name) for MCDS_MCX_ACT31.
* To use register names with standard convension, please use MCDS_MCX_ACT31.
*/
#define	MCDS_MCXACT31	(MCDS_MCX_ACT31)

/** \\brief  900, Action Definition Register */
#define MCDS_MCX_ACT32 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8900u)

/** Alias (User Manual Name) for MCDS_MCX_ACT32.
* To use register names with standard convension, please use MCDS_MCX_ACT32.
*/
#define	MCDS_MCXACT32	(MCDS_MCX_ACT32)

/** \\brief  904, Action Definition Register */
#define MCDS_MCX_ACT33 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8904u)

/** Alias (User Manual Name) for MCDS_MCX_ACT33.
* To use register names with standard convension, please use MCDS_MCX_ACT33.
*/
#define	MCDS_MCXACT33	(MCDS_MCX_ACT33)

/** \\brief  908, Action Definition Register */
#define MCDS_MCX_ACT34 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8908u)

/** Alias (User Manual Name) for MCDS_MCX_ACT34.
* To use register names with standard convension, please use MCDS_MCX_ACT34.
*/
#define	MCDS_MCXACT34	(MCDS_MCX_ACT34)

/** \\brief  90C, Action Definition Register */
#define MCDS_MCX_ACT35 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E890Cu)

/** Alias (User Manual Name) for MCDS_MCX_ACT35.
* To use register names with standard convension, please use MCDS_MCX_ACT35.
*/
#define	MCDS_MCXACT35	(MCDS_MCX_ACT35)

/** \\brief  910, Action Definition Register */
#define MCDS_MCX_ACT36 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8910u)

/** Alias (User Manual Name) for MCDS_MCX_ACT36.
* To use register names with standard convension, please use MCDS_MCX_ACT36.
*/
#define	MCDS_MCXACT36	(MCDS_MCX_ACT36)

/** \\brief  914, Action Definition Register */
#define MCDS_MCX_ACT37 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8914u)

/** Alias (User Manual Name) for MCDS_MCX_ACT37.
* To use register names with standard convension, please use MCDS_MCX_ACT37.
*/
#define	MCDS_MCXACT37	(MCDS_MCX_ACT37)

/** \\brief  918, Action Definition Register */
#define MCDS_MCX_ACT38 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8918u)

/** Alias (User Manual Name) for MCDS_MCX_ACT38.
* To use register names with standard convension, please use MCDS_MCX_ACT38.
*/
#define	MCDS_MCXACT38	(MCDS_MCX_ACT38)

/** \\brief  91C, Action Definition Register */
#define MCDS_MCX_ACT39 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E891Cu)

/** Alias (User Manual Name) for MCDS_MCX_ACT39.
* To use register names with standard convension, please use MCDS_MCX_ACT39.
*/
#define	MCDS_MCXACT39	(MCDS_MCX_ACT39)

/** \\brief  890, Action Definition Register */
#define MCDS_MCX_ACT4 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8890u)

/** Alias (User Manual Name) for MCDS_MCX_ACT4.
* To use register names with standard convension, please use MCDS_MCX_ACT4.
*/
#define	MCDS_MCXACT4	(MCDS_MCX_ACT4)

/** \\brief  920, Action Definition Register */
#define MCDS_MCX_ACT40 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8920u)

/** Alias (User Manual Name) for MCDS_MCX_ACT40.
* To use register names with standard convension, please use MCDS_MCX_ACT40.
*/
#define	MCDS_MCXACT40	(MCDS_MCX_ACT40)

/** \\brief  924, Action Definition Register */
#define MCDS_MCX_ACT41 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8924u)

/** Alias (User Manual Name) for MCDS_MCX_ACT41.
* To use register names with standard convension, please use MCDS_MCX_ACT41.
*/
#define	MCDS_MCXACT41	(MCDS_MCX_ACT41)

/** \\brief  928, Action Definition Register */
#define MCDS_MCX_ACT42 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8928u)

/** Alias (User Manual Name) for MCDS_MCX_ACT42.
* To use register names with standard convension, please use MCDS_MCX_ACT42.
*/
#define	MCDS_MCXACT42	(MCDS_MCX_ACT42)

/** \\brief  92C, Action Definition Register */
#define MCDS_MCX_ACT43 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E892Cu)

/** Alias (User Manual Name) for MCDS_MCX_ACT43.
* To use register names with standard convension, please use MCDS_MCX_ACT43.
*/
#define	MCDS_MCXACT43	(MCDS_MCX_ACT43)

/** \\brief  930, Action Definition Register */
#define MCDS_MCX_ACT44 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8930u)

/** Alias (User Manual Name) for MCDS_MCX_ACT44.
* To use register names with standard convension, please use MCDS_MCX_ACT44.
*/
#define	MCDS_MCXACT44	(MCDS_MCX_ACT44)

/** \\brief  894, Action Definition Register */
#define MCDS_MCX_ACT5 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8894u)

/** Alias (User Manual Name) for MCDS_MCX_ACT5.
* To use register names with standard convension, please use MCDS_MCX_ACT5.
*/
#define	MCDS_MCXACT5	(MCDS_MCX_ACT5)

/** \\brief  898, Action Definition Register */
#define MCDS_MCX_ACT6 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E8898u)

/** Alias (User Manual Name) for MCDS_MCX_ACT6.
* To use register names with standard convension, please use MCDS_MCX_ACT6.
*/
#define	MCDS_MCXACT6	(MCDS_MCX_ACT6)

/** \\brief  89C, Action Definition Register */
#define MCDS_MCX_ACT7 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E889Cu)

/** Alias (User Manual Name) for MCDS_MCX_ACT7.
* To use register names with standard convension, please use MCDS_MCX_ACT7.
*/
#define	MCDS_MCXACT7	(MCDS_MCX_ACT7)

/** \\brief  8A0, Action Definition Register */
#define MCDS_MCX_ACT8 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88A0u)

/** Alias (User Manual Name) for MCDS_MCX_ACT8.
* To use register names with standard convension, please use MCDS_MCX_ACT8.
*/
#define	MCDS_MCXACT8	(MCDS_MCX_ACT8)

/** \\brief  8A4, Action Definition Register */
#define MCDS_MCX_ACT9 /*lint --e(923)*/ (*(volatile Ifx_MCDS_ACT*)0xF90E88A4u)

/** Alias (User Manual Name) for MCDS_MCX_ACT9.
* To use register names with standard convension, please use MCDS_MCX_ACT9.
*/
#define	MCDS_MCXACT9	(MCDS_MCX_ACT9)

/** \\brief  A00, Counter Control Register */
#define MCDS_MCX_CNT0_CCL /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CCL*)0xF90E8A00u)

/** Alias (User Manual Name) for MCDS_MCX_CNT0_CCL.
* To use register names with standard convension, please use MCDS_MCX_CNT0_CCL.
*/
#define	MCDS_MCXCCL0	(MCDS_MCX_CNT0_CCL)

/** \\brief  A08, Current Count Register */
#define MCDS_MCX_CNT0_CNT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CNT*)0xF90E8A08u)

/** Alias (User Manual Name) for MCDS_MCX_CNT0_CNT.
* To use register names with standard convension, please use MCDS_MCX_CNT0_CNT.
*/
#define	MCDS_MCXCNT0	(MCDS_MCX_CNT0_CNT)

/** \\brief  A04, Counter Limit Register */
#define MCDS_MCX_CNT0_LMT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_LMT*)0xF90E8A04u)

/** Alias (User Manual Name) for MCDS_MCX_CNT0_LMT.
* To use register names with standard convension, please use MCDS_MCX_CNT0_LMT.
*/
#define	MCDS_MCXLMT0	(MCDS_MCX_CNT0_LMT)

/** \\brief  A10, Counter Control Register */
#define MCDS_MCX_CNT1_CCL /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CCL*)0xF90E8A10u)

/** Alias (User Manual Name) for MCDS_MCX_CNT1_CCL.
* To use register names with standard convension, please use MCDS_MCX_CNT1_CCL.
*/
#define	MCDS_MCXCCL1	(MCDS_MCX_CNT1_CCL)

/** \\brief  A18, Current Count Register */
#define MCDS_MCX_CNT1_CNT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CNT*)0xF90E8A18u)

/** Alias (User Manual Name) for MCDS_MCX_CNT1_CNT.
* To use register names with standard convension, please use MCDS_MCX_CNT1_CNT.
*/
#define	MCDS_MCXCNT1	(MCDS_MCX_CNT1_CNT)

/** \\brief  A14, Counter Limit Register */
#define MCDS_MCX_CNT1_LMT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_LMT*)0xF90E8A14u)

/** Alias (User Manual Name) for MCDS_MCX_CNT1_LMT.
* To use register names with standard convension, please use MCDS_MCX_CNT1_LMT.
*/
#define	MCDS_MCXLMT1	(MCDS_MCX_CNT1_LMT)

/** \\brief  A20, Counter Control Register */
#define MCDS_MCX_CNT2_CCL /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CCL*)0xF90E8A20u)

/** Alias (User Manual Name) for MCDS_MCX_CNT2_CCL.
* To use register names with standard convension, please use MCDS_MCX_CNT2_CCL.
*/
#define	MCDS_MCXCCL2	(MCDS_MCX_CNT2_CCL)

/** \\brief  A28, Current Count Register */
#define MCDS_MCX_CNT2_CNT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CNT*)0xF90E8A28u)

/** Alias (User Manual Name) for MCDS_MCX_CNT2_CNT.
* To use register names with standard convension, please use MCDS_MCX_CNT2_CNT.
*/
#define	MCDS_MCXCNT2	(MCDS_MCX_CNT2_CNT)

/** \\brief  A24, Counter Limit Register */
#define MCDS_MCX_CNT2_LMT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_LMT*)0xF90E8A24u)

/** Alias (User Manual Name) for MCDS_MCX_CNT2_LMT.
* To use register names with standard convension, please use MCDS_MCX_CNT2_LMT.
*/
#define	MCDS_MCXLMT2	(MCDS_MCX_CNT2_LMT)

/** \\brief  A30, Counter Control Register */
#define MCDS_MCX_CNT3_CCL /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CCL*)0xF90E8A30u)

/** Alias (User Manual Name) for MCDS_MCX_CNT3_CCL.
* To use register names with standard convension, please use MCDS_MCX_CNT3_CCL.
*/
#define	MCDS_MCXCCL3	(MCDS_MCX_CNT3_CCL)

/** \\brief  A38, Current Count Register */
#define MCDS_MCX_CNT3_CNT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CNT*)0xF90E8A38u)

/** Alias (User Manual Name) for MCDS_MCX_CNT3_CNT.
* To use register names with standard convension, please use MCDS_MCX_CNT3_CNT.
*/
#define	MCDS_MCXCNT3	(MCDS_MCX_CNT3_CNT)

/** \\brief  A34, Counter Limit Register */
#define MCDS_MCX_CNT3_LMT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_LMT*)0xF90E8A34u)

/** Alias (User Manual Name) for MCDS_MCX_CNT3_LMT.
* To use register names with standard convension, please use MCDS_MCX_CNT3_LMT.
*/
#define	MCDS_MCXLMT3	(MCDS_MCX_CNT3_LMT)

/** \\brief  A40, Counter Control Register */
#define MCDS_MCX_CNT4_CCL /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CCL*)0xF90E8A40u)

/** Alias (User Manual Name) for MCDS_MCX_CNT4_CCL.
* To use register names with standard convension, please use MCDS_MCX_CNT4_CCL.
*/
#define	MCDS_MCXCCL4	(MCDS_MCX_CNT4_CCL)

/** \\brief  A48, Current Count Register */
#define MCDS_MCX_CNT4_CNT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CNT*)0xF90E8A48u)

/** Alias (User Manual Name) for MCDS_MCX_CNT4_CNT.
* To use register names with standard convension, please use MCDS_MCX_CNT4_CNT.
*/
#define	MCDS_MCXCNT4	(MCDS_MCX_CNT4_CNT)

/** \\brief  A44, Counter Limit Register */
#define MCDS_MCX_CNT4_LMT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_LMT*)0xF90E8A44u)

/** Alias (User Manual Name) for MCDS_MCX_CNT4_LMT.
* To use register names with standard convension, please use MCDS_MCX_CNT4_LMT.
*/
#define	MCDS_MCXLMT4	(MCDS_MCX_CNT4_LMT)

/** \\brief  A50, Counter Control Register */
#define MCDS_MCX_CNT5_CCL /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CCL*)0xF90E8A50u)

/** Alias (User Manual Name) for MCDS_MCX_CNT5_CCL.
* To use register names with standard convension, please use MCDS_MCX_CNT5_CCL.
*/
#define	MCDS_MCXCCL5	(MCDS_MCX_CNT5_CCL)

/** \\brief  A58, Current Count Register */
#define MCDS_MCX_CNT5_CNT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CNT*)0xF90E8A58u)

/** Alias (User Manual Name) for MCDS_MCX_CNT5_CNT.
* To use register names with standard convension, please use MCDS_MCX_CNT5_CNT.
*/
#define	MCDS_MCXCNT5	(MCDS_MCX_CNT5_CNT)

/** \\brief  A54, Counter Limit Register */
#define MCDS_MCX_CNT5_LMT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_LMT*)0xF90E8A54u)

/** Alias (User Manual Name) for MCDS_MCX_CNT5_LMT.
* To use register names with standard convension, please use MCDS_MCX_CNT5_LMT.
*/
#define	MCDS_MCXLMT5	(MCDS_MCX_CNT5_LMT)

/** \\brief  A60, Counter Control Register */
#define MCDS_MCX_CNT6_CCL /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CCL*)0xF90E8A60u)

/** Alias (User Manual Name) for MCDS_MCX_CNT6_CCL.
* To use register names with standard convension, please use MCDS_MCX_CNT6_CCL.
*/
#define	MCDS_MCXCCL6	(MCDS_MCX_CNT6_CCL)

/** \\brief  A68, Current Count Register */
#define MCDS_MCX_CNT6_CNT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CNT*)0xF90E8A68u)

/** Alias (User Manual Name) for MCDS_MCX_CNT6_CNT.
* To use register names with standard convension, please use MCDS_MCX_CNT6_CNT.
*/
#define	MCDS_MCXCNT6	(MCDS_MCX_CNT6_CNT)

/** \\brief  A64, Counter Limit Register */
#define MCDS_MCX_CNT6_LMT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_LMT*)0xF90E8A64u)

/** Alias (User Manual Name) for MCDS_MCX_CNT6_LMT.
* To use register names with standard convension, please use MCDS_MCX_CNT6_LMT.
*/
#define	MCDS_MCXLMT6	(MCDS_MCX_CNT6_LMT)

/** \\brief  A70, Counter Control Register */
#define MCDS_MCX_CNT7_CCL /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CCL*)0xF90E8A70u)

/** Alias (User Manual Name) for MCDS_MCX_CNT7_CCL.
* To use register names with standard convension, please use MCDS_MCX_CNT7_CCL.
*/
#define	MCDS_MCXCCL7	(MCDS_MCX_CNT7_CCL)

/** \\brief  A78, Current Count Register */
#define MCDS_MCX_CNT7_CNT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_CNT*)0xF90E8A78u)

/** Alias (User Manual Name) for MCDS_MCX_CNT7_CNT.
* To use register names with standard convension, please use MCDS_MCX_CNT7_CNT.
*/
#define	MCDS_MCXCNT7	(MCDS_MCX_CNT7_CNT)

/** \\brief  A74, Counter Limit Register */
#define MCDS_MCX_CNT7_LMT /*lint --e(923)*/ (*(volatile Ifx_MCDS_CNT_LMT*)0xF90E8A74u)

/** Alias (User Manual Name) for MCDS_MCX_CNT7_LMT.
* To use register names with standard convension, please use MCDS_MCX_CNT7_LMT.
*/
#define	MCDS_MCXLMT7	(MCDS_MCX_CNT7_LMT)

/** \\brief  800, Event Definition Register */
#define MCDS_MCX_EVT0 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8800u)

/** Alias (User Manual Name) for MCDS_MCX_EVT0.
* To use register names with standard convension, please use MCDS_MCX_EVT0.
*/
#define	MCDS_MCXEVT0	(MCDS_MCX_EVT0)

/** \\brief  804, Event Definition Register */
#define MCDS_MCX_EVT1 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8804u)

/** Alias (User Manual Name) for MCDS_MCX_EVT1.
* To use register names with standard convension, please use MCDS_MCX_EVT1.
*/
#define	MCDS_MCXEVT1	(MCDS_MCX_EVT1)

/** \\brief  828, Event Definition Register */
#define MCDS_MCX_EVT10 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8828u)

/** Alias (User Manual Name) for MCDS_MCX_EVT10.
* To use register names with standard convension, please use MCDS_MCX_EVT10.
*/
#define	MCDS_MCXEVT10	(MCDS_MCX_EVT10)

/** \\brief  82C, Event Definition Register */
#define MCDS_MCX_EVT11 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E882Cu)

/** Alias (User Manual Name) for MCDS_MCX_EVT11.
* To use register names with standard convension, please use MCDS_MCX_EVT11.
*/
#define	MCDS_MCXEVT11	(MCDS_MCX_EVT11)

/** \\brief  830, Event Definition Register */
#define MCDS_MCX_EVT12 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8830u)

/** Alias (User Manual Name) for MCDS_MCX_EVT12.
* To use register names with standard convension, please use MCDS_MCX_EVT12.
*/
#define	MCDS_MCXEVT12	(MCDS_MCX_EVT12)

/** \\brief  834, Event Definition Register */
#define MCDS_MCX_EVT13 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8834u)

/** Alias (User Manual Name) for MCDS_MCX_EVT13.
* To use register names with standard convension, please use MCDS_MCX_EVT13.
*/
#define	MCDS_MCXEVT13	(MCDS_MCX_EVT13)

/** \\brief  838, Event Definition Register */
#define MCDS_MCX_EVT14 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8838u)

/** Alias (User Manual Name) for MCDS_MCX_EVT14.
* To use register names with standard convension, please use MCDS_MCX_EVT14.
*/
#define	MCDS_MCXEVT14	(MCDS_MCX_EVT14)

/** \\brief  83C, Event Definition Register */
#define MCDS_MCX_EVT15 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E883Cu)

/** Alias (User Manual Name) for MCDS_MCX_EVT15.
* To use register names with standard convension, please use MCDS_MCX_EVT15.
*/
#define	MCDS_MCXEVT15	(MCDS_MCX_EVT15)

/** \\brief  808, Event Definition Register */
#define MCDS_MCX_EVT2 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8808u)

/** Alias (User Manual Name) for MCDS_MCX_EVT2.
* To use register names with standard convension, please use MCDS_MCX_EVT2.
*/
#define	MCDS_MCXEVT2	(MCDS_MCX_EVT2)

/** \\brief  80C, Event Definition Register */
#define MCDS_MCX_EVT3 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E880Cu)

/** Alias (User Manual Name) for MCDS_MCX_EVT3.
* To use register names with standard convension, please use MCDS_MCX_EVT3.
*/
#define	MCDS_MCXEVT3	(MCDS_MCX_EVT3)

/** \\brief  810, Event Definition Register */
#define MCDS_MCX_EVT4 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8810u)

/** Alias (User Manual Name) for MCDS_MCX_EVT4.
* To use register names with standard convension, please use MCDS_MCX_EVT4.
*/
#define	MCDS_MCXEVT4	(MCDS_MCX_EVT4)

/** \\brief  814, Event Definition Register */
#define MCDS_MCX_EVT5 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8814u)

/** Alias (User Manual Name) for MCDS_MCX_EVT5.
* To use register names with standard convension, please use MCDS_MCX_EVT5.
*/
#define	MCDS_MCXEVT5	(MCDS_MCX_EVT5)

/** \\brief  818, Event Definition Register */
#define MCDS_MCX_EVT6 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8818u)

/** Alias (User Manual Name) for MCDS_MCX_EVT6.
* To use register names with standard convension, please use MCDS_MCX_EVT6.
*/
#define	MCDS_MCXEVT6	(MCDS_MCX_EVT6)

/** \\brief  81C, Event Definition Register */
#define MCDS_MCX_EVT7 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E881Cu)

/** Alias (User Manual Name) for MCDS_MCX_EVT7.
* To use register names with standard convension, please use MCDS_MCX_EVT7.
*/
#define	MCDS_MCXEVT7	(MCDS_MCX_EVT7)

/** \\brief  820, Event Definition Register */
#define MCDS_MCX_EVT8 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8820u)

/** Alias (User Manual Name) for MCDS_MCX_EVT8.
* To use register names with standard convension, please use MCDS_MCX_EVT8.
*/
#define	MCDS_MCXEVT8	(MCDS_MCX_EVT8)

/** \\brief  824, Event Definition Register */
#define MCDS_MCX_EVT9 /*lint --e(923)*/ (*(volatile Ifx_MCDS_EVT*)0xF90E8824u)

/** Alias (User Manual Name) for MCDS_MCX_EVT9.
* To use register names with standard convension, please use MCDS_MCX_EVT9.
*/
#define	MCDS_MCXEVT9	(MCDS_MCX_EVT9)

/** \\brief  14, MCDS Signal Source Control */
#define MCDS_MUX /*lint --e(923)*/ (*(volatile Ifx_MCDS_MUX*)0xF90E8014u)

/** \\brief  4, OCDS Control and Status */
#define MCDS_OCS /*lint --e(923)*/ (*(volatile Ifx_MCDS_OCS*)0xF90E8004u)

/** \\brief  2008, Current Instruction Pointer */
#define MCDS_TCX_CIP /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCX_CIP*)0xF90EA008u)

/** Alias (User Manual Name) for MCDS_TCX_CIP.
* To use register names with standard convension, please use MCDS_TCX_CIP.
*/
#define	MCDS_TCXCIP	(MCDS_TCX_CIP)

/** \\brief  2000, Debug Status Register */
#define MCDS_TCX_DCSTS /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCX_DCSTS*)0xF90EA000u)

/** Alias (User Manual Name) for MCDS_TCX_DCSTS.
* To use register names with standard convension, please use MCDS_TCX_DCSTS.
*/
#define	MCDS_TCXDCSTS	(MCDS_TCX_DCSTS)

/** \\brief  2400, Comparator Bound Register */
#define MCDS_TCX_EA0_BND /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXEA_BND*)0xF90EA400u)

/** Alias (User Manual Name) for MCDS_TCX_EA0_BND.
* To use register names with standard convension, please use MCDS_TCX_EA0_BND.
*/
#define	MCDS_TCXEABND0	(MCDS_TCX_EA0_BND)

/** \\brief  2404, Comparator Range Register */
#define MCDS_TCX_EA0_RNG /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXEA_RNG*)0xF90EA404u)

/** Alias (User Manual Name) for MCDS_TCX_EA0_RNG.
* To use register names with standard convension, please use MCDS_TCX_EA0_RNG.
*/
#define	MCDS_TCXEARNG0	(MCDS_TCX_EA0_RNG)

/** \\brief  2410, Comparator Bound Register */
#define MCDS_TCX_EA1_BND /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXEA_BND*)0xF90EA410u)

/** Alias (User Manual Name) for MCDS_TCX_EA1_BND.
* To use register names with standard convension, please use MCDS_TCX_EA1_BND.
*/
#define	MCDS_TCXEABND1	(MCDS_TCX_EA1_BND)

/** \\brief  2414, Comparator Range Register */
#define MCDS_TCX_EA1_RNG /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXEA_RNG*)0xF90EA414u)

/** Alias (User Manual Name) for MCDS_TCX_EA1_RNG.
* To use register names with standard convension, please use MCDS_TCX_EA1_RNG.
*/
#define	MCDS_TCXEARNG1	(MCDS_TCX_EA1_RNG)

/** \\brief  3000, Comparator Bound Register */
#define MCDS_TCX_IP0_BND /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXIP_BND*)0xF90EB000u)

/** Alias (User Manual Name) for MCDS_TCX_IP0_BND.
* To use register names with standard convension, please use MCDS_TCX_IP0_BND.
*/
#define	MCDS_TCXIPBND0	(MCDS_TCX_IP0_BND)

/** \\brief  3004, Comparator Range Register */
#define MCDS_TCX_IP0_RNG /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXIP_RNG*)0xF90EB004u)

/** Alias (User Manual Name) for MCDS_TCX_IP0_RNG.
* To use register names with standard convension, please use MCDS_TCX_IP0_RNG.
*/
#define	MCDS_TCXIPRNG0	(MCDS_TCX_IP0_RNG)

/** \\brief  3010, Comparator Bound Register */
#define MCDS_TCX_IP1_BND /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXIP_BND*)0xF90EB010u)

/** Alias (User Manual Name) for MCDS_TCX_IP1_BND.
* To use register names with standard convension, please use MCDS_TCX_IP1_BND.
*/
#define	MCDS_TCXIPBND1	(MCDS_TCX_IP1_BND)

/** \\brief  3014, Comparator Range Register */
#define MCDS_TCX_IP1_RNG /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXIP_RNG*)0xF90EB014u)

/** Alias (User Manual Name) for MCDS_TCX_IP1_RNG.
* To use register names with standard convension, please use MCDS_TCX_IP1_RNG.
*/
#define	MCDS_TCXIPRNG1	(MCDS_TCX_IP1_RNG)

/** \\brief  200C, Compact Function Trace Register */
#define MCDS_TCX_TCCFTREG /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCX_TCCFTREG*)0xF90EA00Cu)

/** Alias (User Manual Name) for MCDS_TCX_TCCFTREG.
* To use register names with standard convension, please use MCDS_TCX_TCCFTREG.
*/
#define	MCDS_TCCFTREG	(MCDS_TCX_TCCFTREG)

/** \\brief  2480, Comparator Bound Register */
#define MCDS_TCX_WD0_BND /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXWD_BND*)0xF90EA480u)

/** Alias (User Manual Name) for MCDS_TCX_WD0_BND.
* To use register names with standard convension, please use MCDS_TCX_WD0_BND.
*/
#define	MCDS_TCXWDBND0	(MCDS_TCX_WD0_BND)

/** \\brief  2490, Comparator Mask Register */
#define MCDS_TCX_WD0_MSK /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXWD_MSK*)0xF90EA490u)

/** Alias (User Manual Name) for MCDS_TCX_WD0_MSK.
* To use register names with standard convension, please use MCDS_TCX_WD0_MSK.
*/
#define	MCDS_TCXWDMSK0	(MCDS_TCX_WD0_MSK)

/** \\brief  2488, Comparator Range Register */
#define MCDS_TCX_WD0_RNG /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXWD_RNG*)0xF90EA488u)

/** Alias (User Manual Name) for MCDS_TCX_WD0_RNG.
* To use register names with standard convension, please use MCDS_TCX_WD0_RNG.
*/
#define	MCDS_TCXWDRNG0	(MCDS_TCX_WD0_RNG)

/** \\brief  249C, Comparator Sign Register */
#define MCDS_TCX_WD0_SGN /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXWD_SGN*)0xF90EA49Cu)

/** Alias (User Manual Name) for MCDS_TCX_WD0_SGN.
* To use register names with standard convension, please use MCDS_TCX_WD0_SGN.
*/
#define	MCDS_TCXWDSGN0	(MCDS_TCX_WD0_SGN)

/** \\brief  24A0, Comparator Bound Register */
#define MCDS_TCX_WD1_BND /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXWD_BND*)0xF90EA4A0u)

/** Alias (User Manual Name) for MCDS_TCX_WD1_BND.
* To use register names with standard convension, please use MCDS_TCX_WD1_BND.
*/
#define	MCDS_TCXWDBND1	(MCDS_TCX_WD1_BND)

/** \\brief  24B0, Comparator Mask Register */
#define MCDS_TCX_WD1_MSK /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXWD_MSK*)0xF90EA4B0u)

/** Alias (User Manual Name) for MCDS_TCX_WD1_MSK.
* To use register names with standard convension, please use MCDS_TCX_WD1_MSK.
*/
#define	MCDS_TCXWDMSK1	(MCDS_TCX_WD1_MSK)

/** \\brief  24A8, Comparator Range Register */
#define MCDS_TCX_WD1_RNG /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXWD_RNG*)0xF90EA4A8u)

/** Alias (User Manual Name) for MCDS_TCX_WD1_RNG.
* To use register names with standard convension, please use MCDS_TCX_WD1_RNG.
*/
#define	MCDS_TCXWDRNG1	(MCDS_TCX_WD1_RNG)

/** \\brief  24BC, Comparator Sign Register */
#define MCDS_TCX_WD1_SGN /*lint --e(923)*/ (*(volatile Ifx_MCDS_TCXWD_SGN*)0xF90EA4BCu)

/** Alias (User Manual Name) for MCDS_TCX_WD1_SGN.
* To use register names with standard convension, please use MCDS_TCX_WD1_SGN.
*/
#define	MCDS_TCXWDSGN1	(MCDS_TCX_WD1_SGN)

/** \\brief  408, Clock Counter Register */
#define MCDS_TSUEMUCNT /*lint --e(923)*/ (*(volatile Ifx_MCDS_TSUEMUCNT*)0xF90E8408u)

/** \\brief  404, Clock Prescaler Register */
#define MCDS_TSUPRSCL /*lint --e(923)*/ (*(volatile Ifx_MCDS_TSUPRSCL*)0xF90E8404u)

/** \\brief  400, Clock Counter Register */
#define MCDS_TSUREFCNT /*lint --e(923)*/ (*(volatile Ifx_MCDS_TSUREFCNT*)0xF90E8400u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXMCDS_REG_H */

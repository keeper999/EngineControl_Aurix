/**
 * \file IfxPmu_reg.h
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
 * \defgroup IfxLld_Pmu_Cfg Pmu address
 * \ingroup IfxLld_Pmu
 * 
 * \defgroup IfxLld_Pmu_Cfg_BaseAddress Base address
 * \ingroup IfxLld_Pmu_Cfg
 * 
 * \defgroup IfxLld_Pmu_Cfg_Pmu0 2-PMU0
 * \ingroup IfxLld_Pmu_Cfg
 * 
 */
#ifndef IFXPMU_REG_H
#define IFXPMU_REG_H
/******************************************************************************/
#include "IfxPmu_regdef.h"
/******************************************************************************/
/** \addtogroup IfxLld_Pmu_Cfg_BaseAddress
 * \{  */

/** \\brief  PMU object */
#define MODULE_PMU0 /*lint --e(923)*/ ((*(Ifx_PMU*)0xF8000500u))
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Pmu_Cfg_Pmu0
 * \{  */

/** \\brief  8, PMU0 Identification Register */
#define PMU0_ID /*lint --e(923)*/ (*(volatile Ifx_PMU_ID*)0xF8000508u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXPMU_REG_H */

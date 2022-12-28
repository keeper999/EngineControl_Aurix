/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : BSW Scheduler Module                                    */
/*                                                                            */
/* !File            : SchM_17_McalCfg.h                                       */
/* !Description     : SchM configuration of the MCAL components               */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192455.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SCHM_17_MCALCFG_H
#define SCHM_17_MCALCFG_H

#ifdef SCHM_FLS_17_PMU_HEADER
#error "SCHM_FLS_17_PMU_HEADER already defined"
#endif
#define SCHM_FLS_17_PMU_HEADER           "SchM_Fls_17_Pmu.h"

#ifdef SCHM_CAN_17_MCANP_HEADER
#error "SCHM_CAN_17_MCANP_HEADER already defined"
#endif
#define SCHM_CAN_17_MCANP_HEADER         "SchM_Can_17_MCanP.h"

#ifdef SCHM_ICU_17_GTMCCU6_HEADER
#error "SCHM_ICU_17_GTMCCU6_HEADER already defined"
#endif
#define SCHM_ICU_17_GTMCCU6_HEADER       "SchM_Icu_17_GtmCcu6.h"

#ifdef SCHM_WDG_17_SCU_HEADER
#error "SCHM_WDG_17_SCU_HEADER already defined"
#endif
#define SCHM_WDG_17_SCU_HEADER           "SchM_Wdg_17_Scu.h"

#ifdef SCHM_MCAL_WDGLIB_HEADER
#error "SCHM_MCAL_WDGLIB_HEADER already defined"
#endif
#define SCHM_MCAL_WDGLIB_HEADER          "SchM_Mcal_WdgLib.h"

#endif /* SCHM_17_MCALCFG_H */

/*-------------------------------- end of file -------------------------------*/
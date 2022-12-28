/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Compiler_Cfg.h                                                **
**                                                                            **
**  VERSION   : 1.1.2                                                         **
**                                                                            **
**  DATE      : 2012-09-17                                                    **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : TASKING / GNU / DIAB                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION:File contains additional   typedefs that are used for         **
**              bit field structures. Also the tasking intrinsic functions    **
**              are listed here.                                              **
**              Macros given for Modules are not in use.                      **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: yes                                      **
**                                                                            **
*******************************************************************************/



/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials            Name                                                   **
** -------------------------------------------------------------------------- **
** AT                  Angeswaran Thangaswamy                                 **
** DP                  Deepak Purushotham                                     **
** HM                  Hamzath Mohammed                                       **
** CS                  Chaitra Shanthpur                                      **
** SC                  Sandeep Chandrashekar                                  **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/



/*
 * V1.1.2: 2012-09-17, AT  : Updated for WINDRIVER compiler
 * V1.1.1: 2012-08-21, AT  : Updated for GNU compiler
 * V1.1.0: 2010-02-04, HM  : Implementation of IMASKLDMST
 *                           for variables outside 16K boundary.
 * V1.0.9: 2010-02-02, DP  : Added macro Mcal_Swap
 * V1.0.6: 2009-10-21, SC  : Added #define for STATIC
 * V1.0.7: 2009.06.17, HM  : Header changed to Audo
 * V1.0.6: 2008.10.16, HM  : Added comments; changed file header
 * V1.0.5: 2008.06.19, HM  : Added EXT_IMASKLDMST
 * V1.0.4: 2008.05.02, HM  : Added AudoF
 * V1.0.3: 2007.11.21, CS  : Typecase in Mcal_CountLeadingZeros macro changed
 * V1.0.2: 2007.06.20, HM  : Added Extract Routine
 * V1.0.1: 2007.02.07, HM  : AI00037385:Changed File Header Information
 * V1.0.0: 2006.05.03, HM  : Added Module Specific Compiler abstraction macros
 *                           for Tricore platform
 *
 */


#ifndef COMPILER_CFG_H 
#define COMPILER_CFG_H  

#include "Ifx_Cfg.h"
#include "Mcal_Compiler.h"
#include "Os_Compiler_Cfg.h"

/******************************************************************************/
/* !Comment: List of MCAL patch used                                          */
/******************************************************************************/
/* Patch for CAN */
#define VALEO_PATCH_MCAL_DISABLE_INTER_MODULE_CHECK

/* Patch for DRV */
#define VALEO_PATCH_MCAL_DRV_MEMMAP_SEC
#define VALEO_PATCH_MCAL_DRV_USE_SCHM
#define VALEO_PATCH_MCAL_DRV_INCLUDE_MCAL_OPTIONS_H

/* Patch for FLS */
#define VALEO_PATCH_MCAL_FLS_FIX_DET_TIMEOUT
#define VALEO_PATCH_MCAL_FLS_MEMMAP_SEC

/* Patch for ICU */
#define VALEO_PATCH_MCAL_ICU_FIX_ETXERN_INLINE
#define VALEO_PATCH_MCAL_ICU_MOVE_DECLARATION

/* Patch for LIN */
#define VALEO_PATCH_MCAL_LIN_FIX_SDR_PTR_ACCESS

/* Patch for MCU */
#define VALEO_PATCH_MCAL_FIX_ISR_MNGT

/* Patch for PWM */
#define VALEO_PATCH_MCAL_PWM_NOTIF_ON_0_AND_100_PERCENT

/* Patch for SPI */
#define VALEO_PATCH_MCAL_SPI_REMOVE_DEM
#define VALEO_PATCH_SPI_MEMMAP_SEC


/*this file shall not be modified by the user, CONST_CFG shall be defined in Ifx_Cfg.h */
#ifndef CONST_CFG
#define CONST_CFG               const     /* configuration constants are stored in ROM */
#endif

#define IFX_EXTERN              extern

/* !Comment: definition of keyword "inline" for 3.0 AUTOSAR release           */
#define INLINE


#pragma section ".bss"

/*Start: Common definitions ********************************************** */
extern unsigned int __A0_MEM[];         /**< center of A0 addressable area */
extern unsigned int __A1_MEM[];         /**< center of A1 addressable area */
extern unsigned int __A8_MEM[];         /**< center of A8 addressable area */
extern unsigned int __A9_MEM[];         /**< center of A9 addressable area */
extern unsigned int __TRAPTAB[];        /**< trap table */

/*End: Common definitions ************************************************ */

/*Start: Core 0 definitions ********************************************** */
extern unsigned long __clear_table[];  /* clear table entry */
extern unsigned long __copy_table[];   /* copy table entry  */

extern unsigned long __power_on_clear_table[];  /* power on clear table entry */
extern unsigned long __power_on_copy_table[];   /* power on copy table entry  */

/*C extern defintions */
extern unsigned int __USTACK0[];        /**< user stack end */
extern unsigned int __ISTACK0[];        /**< interrupt stack end */
extern unsigned int __INTTAB_CPU0[];    /**< Interrupt vector table */
extern unsigned int __CSA0[];           /**< context save area 1 begin */
extern unsigned int __CSA0_END[];       /**< context save area 1 begin */

/*Wrapper macros for the tool specific definitions */
#if defined(IFX_USE_SW_MANAGED_INT)
#define __INTTAB0    ((unsigned int)__INTTAB_CPU0 | (unsigned int)0x1FE0)
#else
#define __INTTAB0    __INTTAB_CPU0
#endif /*defined(IFX_USE_SW_MANAGED_INT) */

#define __SDATA1_0   __A0_MEM
#define __SDATA2_0   __A1_MEM
#define __SDATA3_0   __A8_MEM
#define __SDATA4_0   __A9_MEM
/*End: Core 0 definitions *****************************************************/

/*Start: Core 1 definitions ***************************************************/
extern unsigned int __USTACK1[];        /**< user stack end */
extern unsigned int __ISTACK1[];        /**< interrupt stack end */
extern unsigned int __INTTAB_CPU1[];    /**< Interrupt vector table */
extern unsigned int __CSA1[];           /**< context save area 1 begin */
extern unsigned int __CSA1_END[];       /**< context save area 1 begin */

/*Wrapper macros for the tool specific definitions */
#if defined(IFX_USE_SW_MANAGED_INT)
#define __INTTAB1    ((unsigned int)__INTTAB_CPU1 | (unsigned int)0x1FE0)
#else
#define __INTTAB1    __INTTAB_CPU1
#endif /*defined(IFX_USE_SW_MANAGED_INT) */

#define __SDATA1_1   __A0_MEM
#define __SDATA2_1   __A1_MEM
#define __SDATA3_1   __A8_MEM
#define __SDATA4_1   __A9_MEM
/*End: Core 1 definitions *****************************************************/

/*Start: Core 2 definitions ***************************************************/
extern unsigned int __USTACK2[];        /**< user stack end */
extern unsigned int __ISTACK2[];        /**< interrupt stack end */
extern unsigned int __INTTAB_CPU2[];    /**< Interrupt vector table */
extern unsigned int __CSA2[];           /**< context save area 1 begin */
extern unsigned int __CSA2_END[];       /**< context save area 1 begin */

/*Wrapper macros for the tool specific definitions */
#if defined(IFX_USE_SW_MANAGED_INT)
#define __INTTAB2    ((unsigned int)__INTTAB_CPU2 | (unsigned int)0x1FE0)
#else
#define __INTTAB2    __INTTAB_CPU2
#endif /*defined(IFX_USE_SW_MANAGED_INT) */

#define __SDATA1_2   __A0_MEM
#define __SDATA2_2   __A1_MEM
#define __SDATA3_2   __A8_MEM
#define __SDATA4_2   __A9_MEM
/*End: Core 2 definitions *****************************************************/
#pragma section
/******************************************************************************/

#define COMPILER_VERSION     0
#define COMPILER_REVISION    0

//dbg

/* Comment: Macro to declare interrupts */
#define DECLARE_IT(isr)                                         \
void __attribute__ ((interrupt_handler)) isr();                 \
void isr(void)

//dbg

#define COMPILER_UNUSED_PARAMETER(udtVariable) \
do \
{ \
   if ((udtVariable) != 0) \
   { \
   } \
} \
while(0)

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Configuration data                                    **
*******************************************************************************/
/** Store a single bit.
*/
#define __putbit(value,address,bitoffset ) __imaskldmst(address, value, bitoffset,1)

/** Convert context pointer to address pointer
 * \param[in] cx context pointer
 * \return address pointer
*/
IFX_INLINE void *__cx_to_addr (uint32 cx)
{
    uint32 seg_nr = __extru (cx, 16, 4);
    return (void *) __insert (seg_nr << 28, cx, 6, 16);
}

/** Convert address pointer to context pointer
 * \param[in] addr address pointer
 * \return context pointer
*/
IFX_INLINE uint32 __addr_to_cx (void *addr)
{
    uint32 seg_nr, seg_idx;
    seg_nr = __extru ((int) addr, 28, 4) << 16;
    seg_idx = __extru ((int) addr, 6, 16);
    return seg_nr | seg_idx;
}

#endif /* COMPILER_CFG_H */

/*-------------------------------- end of file -------------------------------*/

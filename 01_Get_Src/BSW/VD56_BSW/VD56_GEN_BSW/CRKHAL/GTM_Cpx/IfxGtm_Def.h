/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IFXGTM                                                  */
/* !Description     : GTM Driver                                              */
/*                                                                            */
/* !File            : IfxGtm_Def.h                                            */
/* !Description     : Definition of data of GTM Component                     */
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
 * %PID: P2017_BSW:A18524.A-SRC;8 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXGTMDEF_H_
#define IFXGTMDEF_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "IfxGtm_reg.h"
#include "IfxGtm_bf.h"
#include "CRKHAL_Typ.h"

/******************************************************************************/
/*                           Macros                                           */
/******************************************************************************/

#define IFX_GTM_BASE              ((uint8 *)&MODULE_GTM)

#define ATOMxCHxOFFSET            (0x80)
/* ATOM channel offset */
#define ATOM_0_OFFSET             (0xD000)
#define ATOM_1_OFFSET             (0xD800)
#define ATOM_2_OFFSET             (0xE000)
#define ATOM_3_OFFSET             (0xE800)
#define ATOM_4_OFFSET             (0xF000)
#define ATOM_5_OFFSET             (0xF800)
#define ATOM_6_OFFSET             (0x10000)
#define ATOM_7_OFFSET             (0x10800)
#define ATOM_8_OFFSET             (0x11000)

#define ATOM_BASE_OFFSET          (ATOM_0_OFFSET)
#define ATOM_CH_OFFSET            (0x80)
#define ATOM_AGC_OFFSET           (0x40)
#define ATOM_OFFSET               (0x800)

#define SRC_GTM_ATOM_BASE_OFFSET  (0x1D80)
#define SRC_GTM_ATOM_OFFSET       (0x10)
#define SRC_GTM_ATOM_CH_OFFSET    (0x4)

#define RAM_2b_OFFSET             (0x2C000)

#define TIM_GLB_OFFSET            (0x1000) /* Only TIM0 Possible */
#define TIMxCHxOFFSET             (0x80)
#define TIM_OFFSET                (0x800)

#define DPLL_RAM2_OFFSET          (0x2C000)
#define TSF_T_OFFSET              (0x400)
#define ADT_T_OFFSET              (0x800)
#define DT_T_OFFSET               (0xC00)

#define MCS0_RAM0_OFFSET          (0x38000)

#define GTM_DPLL_RR2_type         Ifx_GTM_REV /* shared struct */

#define GTM_MCS_SEL               (IFX_GTM_BASE + MCS0_RAM0_OFFSET)

#define GTM_MCS_MEM               (*( unsigned int *) GTM_MCS_SEL)

#define APT_WAPT_2b_setMsk        (0x00002000U)
#define APT_APT_2b_setMsk         (0x00000002U)

#define MCS_NO_RUN                ((uint32)0)
#define MCS_RUN                   ((uint32)1)
#define MCS_SYNC                  ((uint32)2)

/* Configurable Clocks */
#ifndef GTM_CONFIGURABLE_CLOCK_0
   #define GTM_CONFIGURABLE_CLOCK_0 (0U)
#endif
#ifndef GTM_CONFIGURABLE_CLOCK_1
   #define GTM_CONFIGURABLE_CLOCK_1 (1U)
#endif
#ifndef GTM_CONFIGURABLE_CLOCK_2
   #define GTM_CONFIGURABLE_CLOCK_2 (2U)
#endif
#ifndef GTM_CONFIGURABLE_CLOCK_3
   #define GTM_CONFIGURABLE_CLOCK_3 (3U)
#endif
#ifndef GTM_CONFIGURABLE_CLOCK_4
   #define GTM_CONFIGURABLE_CLOCK_4 (4U)
#endif
#ifndef GTM_CONFIGURABLE_CLOCK_5
   #define GTM_CONFIGURABLE_CLOCK_5 (5U)
#endif
#ifndef GTM_CONFIGURABLE_CLOCK_6
   #define GTM_CONFIGURABLE_CLOCK_6 (6U)
#endif
#ifndef GTM_CONFIGURABLE_CLOCK_7
   #define GTM_CONFIGURABLE_CLOCK_7 (7U)
#endif

#define TBU_DISABLE_CLR           (0x5U)
#define TBU_ENABLE_CLR            (0xAU)

#define INACTIVE_CCU0             ((uint32)(0xFFFFFFFFU))
#define INACTIVE_CCU1             ((uint32)(0xFFFFFFFFU))

#define CCU1_ONLY_OUT_NO_CHANGE   ((uint8)(0xCU)) /*0x011|00*/
#define CCU1_ONLY_OUT_ACTIVE      ((uint8)(0xDU)) /*0x011|01*/
#define CCU1_ONLY_OUT_INACT       ((uint8)(0xEU)) /*0x011|10*/
#define CCU1_ONLY_OUT_TOGGLE      ((uint8)(0xFU)) /*0x011|11*/

#define CCU0_ONLY_OUT_NO_CHANGE   (0x8U) /*0x010|00*/
#define CCU0_ONLY_OUT_ACTIVE      (0x9U) /*0x010|01*/
#define CCU0_ONLY_OUT_INACT       (0xAU) /*0x010|10*/
#define CCU0_ONLY_OUT_TOGGLE      (0xBU) /*0x010|11*/

#define SERVE_FIRST_OUT_ACTIVE    (0x1U) /*0x000|01*/
#define SERVE_FIRST_OUT_INACT     (0x2U) /*0x000|10*/
#define SERVE_FIRST_OUT_NO_CHANGE (0x0U) /*0x000|00*/
#define SERVE_FIRST_OUT_TOGGLE    (0x3U) /*0x000|11*/

/* TBU  */
#define GTM_TBU_Timer             GTM_TBU_CH0_BASE  /* TBU Timer uses TBU_CH0 */
#define GTM_TBU_Angle             GTM_TBU_CH1_BASE  /* TBU Angle uses TBU_CH1 */
#define GTM_TBU_CHy_BASE_MASK     (0x00FFFFFFU)

/*#define CCU1_MODE_DISABLE       ((uint8)0x1FU)*/
#define CCU1_MODE_DISABLE         ((uint8)CCU1_ONLY_OUT_NO_CHANGE)

/******************************************************************************/
/* !Description : Bit Operations                                              */
/*                                                                            */
/******************************************************************************/
/* TIM related bit Defnitions */
#define IFX_GTM_TIM_CH_CTRL_WR_MASK_TOCTRL       (0x3FFFFFFFU)
#define IFX_GTM_TIM_CH_CTRL_WR_MASK_TIM_EN       (0xFFFFFFFEU)

#define Ifx_GTM_TIM_CH_GPR0_RD_MASK_GPR0         (0x00FFFFFFU)
#define Ifx_GTM_TIM_CH_GPRx_RD_MASK_ECNT         (0x01000000U)
#define Ifx_GTM_TIM_CH_GPR1_RD_MASK_GPR1         (0x00FFFFFFU)

#define IFX_GTM_TIM_CH_IRQ_RD_MASK_NEWVAL        (0x00000001U)
#define IFX_GTM_TIM_CH_IRQ_RD_MASK_TODET         (0x00000010U)

#define IFX_GTM_TIM_INSEL_WR_MASK_CH0SEL         (0xFFFFFFF0U)


/* ATOM related bit Defnitions */
#define IFX_GTM_ATOM_CH_CTRL_WR_MASK_MODE        (0xFFFFFFFCU)
#define IFX_GTM_ATOM_CH_CTRL_WR_MASK_ACB         (0xFFFFFE0FU)
#define IFX_GTM_ATOM_CH_CTRL_WR_MASK_CMP_CTRL    (0xFFFFFEFFU)
#define IFX_GTM_ATOM_CH_CTRL_WR_MASK_SL          (0xFFFFF7FFU)

#define IFX_GTM_ATOM_CH_CTRL_RD_MASK_ACB42       (0x000001C0U)
#define IFX_GTM_ATOM_CH_CTRL_RD_MASK_ACB10       (0x00000030U)

#define IFX_GTM_ATOM_CH_IRQ_CCU0TC_WR_MASK_BIT   (0xFFFFFFFEU)
#define IFX_GTM_ATOM_CH_IRQ_CCU1TC_WR_MASK_BIT   (0xFFFFFFFDU)

#define IFX_GTM_ATOM_CH_IRQ_CCU0TC_RD_MASK_BIT   (0x00000001U)
#define IFX_GTM_ATOM_CH_IRQ_CCU1TC_RD_MASK_BIT   (0x00000002U)

#define SERVE_FIRST_ACB42                        (0x00)
#define CCU0_ONLY_ACB42                          (0x02)
#define CCU1_ONLY_ACB42                          (0x03)
#define CCU0_CCU1_CMP_DISABLE_ACB42              (0x07)

/* BIT defnations for GTM DPLL */
#define IFX_GTM_DPLL_TISI_BIT                    (0x00000020U) /* 5  Bit */
#define IFX_GTM_DPLL_MTI_BIT                     (0x00000080U) /* 7  Bit */
#define IFX_GTM_DPLL_GL1I_BIT                    (0x00002000U) /* 13 Bit */
#define IFX_GTM_DPLL_LL1I_BIT                    (0x00004000U) /* 14 Bit */
#define IFX_GTM_DPLL_TE0I_BIT                    (0x00040000U) /* 18 Bit */
#define IFX_GTM_DPLL_TE1I_BIT                    (0x00080000U) /* 19 Bit */
#define IFX_GTM_DPLL_TE2I_BIT                    (0x00100000U) /* 20 Bit */
#define IFX_GTM_DPLL_CDTI_BIT                    (0x00800000U) /* 23 Bit */
/*#define IFX_GTM_DPLL_TLR_BIT                   (0x02000000U) *//* 25 Bit */
#define IFX_GTM_DPLL_DCGI_BIT                    (0x08000000U) /* 27 Bit */

#define IFX_GTM_DPLL_NUTC_SYN_T_OLD_RD_MSK_BIT   (0x00070000U)
#define IFX_GTM_DPLL_NUTC_SYN_T_RD_MSK_BIT       (0x0000E000U)
#define IFX_GTM_DPLL_NUTC_NUTE_WR_MSK_BIT        (0xFFFFFFC00)
#define IFX_GTM_DPLL_NUTC_FST_WNUT_SET_BIT       (0x20000400U)

#define IFX_GTM_DPLL_STATUS_BWD1_RD_MSK_BIT      (0x00800000U)
#define IFX_GTM_DPLL_STATUS_LOCK1_RD_MSK_BIT     (0x40000000U)

#define IFX_GTM_DPLL_RAM_INI_INIT_RAM_RD_MSK_BIT (0x00000010U)

#define IFX_GTM_DPLL_OSW_OSS_WR_MSK_BIT          (0xFFFFFCFFU)
#define IFX_GTM_DPLL_OSW_SWON_T_RD_MSK_BIT       (0x00000002U)

#define IFX_GTM_DPLL_APT_2C_WR_MSK_BIT           (0xFFFFF003U)
#define IFX_GTM_DPLL_APT_2C_RD_MSK_BIT           (0x00000FFCU)

#define IFX_GTM_DPLL_APT_APT2B_RD_MSK_BIT        (0x00FFC000U)

#define IFX_GTM_DPLL_APT_APT_RD_MSK_BIT          (0x00000FFCU)

/* TBU bit defnitions */
#define IFX_GTM_TBU_CHEN_ENDIS_CH0_WR_MSK_BIT    (0xFFFFFFFCU)
#define IFX_GTM_TBU_CHEN_ENDIS_CH1_WR_MSK_BIT    (0xFFFFFFF3U)

#define IFX_GTM_TBU_CHEN_ENDIS_CH0_RD_MSK_BIT    (0x00000003U)
#define IFX_GTM_TBU_CHEN_ENDIS_CH1_RD_MSK_BIT    (0x0000000CU)

/** Macro to write new value to the bits in register */
#define IFX_GTM_WRITE_REG(reg, mask, pos, val) \
do \
{ \
   uint32 u32LocalVal_3 ; \
   uint32 u32LocalTemp = reg; \
   u32LocalTemp = (u32LocalTemp & mask); \
   u32LocalVal_3  = u32LocalTemp; \
   u32LocalVal_3 |= (val << pos); \
   reg = u32LocalVal_3 ;\
} \
while (0)

/** Macro to read the bits in register */
#define IFX_GTM_READ_REG(reg, mask, pos)   ((reg & mask) >> pos)
                                                            
/** Macro to read the bits in register - No shift operation */
#define IFX_GTM_READ_REG_BITFIELD(reg, mask)    (reg & mask)

/** Macro to set the particular bit in register */
/*#define IFX_GTM_SET_BIT(reg, pos)   ((uint32)reg) |= ((uint32)1U << (uint32)pos)*/
/*#define IFX_GTM_SET_BIT(reg, pos)   (reg) |= (1U << pos)*/
#define IFX_GTM_SET_BIT(reg, pos) \
do \
{ \
   uint32 u32LocalTemp = reg; \
   u32LocalTemp = (u32LocalTemp | ((uint32)1U << (uint32)pos)); \
   reg = u32LocalTemp; \
} \
while (0)

/** Macro to clear the particular bit in register */
/* #define IFX_GTM_CLEAR_BIT(reg, pos)   ((uint32)reg) &= (~((uint32)1U << pos)) */
/* #define IFX_GTM_CLEAR_BIT(reg, pos)   (reg) &= ~(1U << pos)*/
#define IFX_GTM_CLEAR_BIT(reg, pos) \
do \
{ \
   uint32 u32LocalTemp = reg; \
   u32LocalTemp = (u32LocalTemp & (~((uint32)1U << (uint32)pos))); \
   reg = u32LocalTemp; \
} \
while (0)

#endif /* IFGGTMDEF_H_ */

/*------------------------------ end of file ---------------------------------*/

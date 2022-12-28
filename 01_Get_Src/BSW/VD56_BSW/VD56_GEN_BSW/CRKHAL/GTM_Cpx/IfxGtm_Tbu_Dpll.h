/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TBU_DPLL                                                */
/* !Description     : TBU_DPLL Component                                      */
/*                                                                            */
/* !File            : IfxGtm_Tbu_Dpll.h                                       */
/* !Description     : Definition of data of TBU & DPLL Component              */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/******************************************************************************/
/* VERSION   : v.0.1          DATE : Oct 18 2013                         */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A18539.A-SRC;6 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXGTM_DPLL_H_
#define IFXGTM_DPLL_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "IfxGtm_Def.h"

/******************************************************************************/
/*                           Macros                                           */
/******************************************************************************/
/** \addtogroup CRAKHAL
 * \{ */
/** DPLL SETTINGS */
/* DPLL CTRL 0 settings */
#define DPLL_CTRL_0_SET          (0x62000000U) /* TEN = 1 | SEN = 1 | AMS = 1 */
/* DPLL CTRL 1 settings */
#define DPLL_CTRL_1_SET          (0x00000030U) /* SGE1 = 1 | PIT=1 */
#define DPLL_RAM_OFFSET          (0x1U) /*! Offset size of RAM - 256 */

#define DPLL_TLR_VAL (3U)

/** PROFILE CONFIGURATION **/
/* CRANK Normal increment Value */
#define CRKHAL_NORMAL_TOOTH_LEN  (0x10000U)
/* CRANK Gap Teeth = 3 x Normal increment Value */
#define CRKHAL_GAP_TOOTH_LEN     ((CRKHAL_NORMAL_TOOTH_LEN * \
    CRKHAL_udtNUM_GAP_TEETH) + CRKHAL_NORMAL_TOOTH_LEN)

#define CRKHAL_TE2               (0U)
#define CRKHAL_TE1_FIRST         (2U)

#define CRKHAL_TE0I_ENABLE       (0x02000U)      /* CRANK TE0I enable  */
#define CRKHAL_TE1I_ENABLE       (0x04000U)      /* CRANK TE1I enable */
#define CRKHAL_TE2I_ENABLE       (0x06000U)      /* CRANK TE2I enable  */

/* i.e. 2.0 - Normal Gap Tooth Timeout = (IFX_CRK_TS_T_CHECK_GAP * DT_T) / 1024*/
#define CRKHAL_TS_T_CHECK_GAP    ((uint32) 0x0800)
/* i.e. - No Gap Tooth Expected Timeout = (IFX_CRK_TS_T_CHECK_GAP * DT_T) / 1024*/
#define CRKHAL_TS_T_NO_GAP    ((uint32) 0xFC00)

#define CRKHAL_PVT_VAL           (25U)
#define CRKHAL_THMA_VAL          (2000U)

/* 24 bit timer on TBU */
#define GTM_TBU_TIMER_MAX_LIMIT      (0x00FFFFFFU)

/******************************************************************************/
/* !FuncName    : TBU_READ_TIME                                               */
/* !Description : Read the Current Time                                       */
/*                                                                            */
/******************************************************************************/
#define TBU_READ_TIME()              GTM_TBU_Timer.U

/******************************************************************************/
/* !FuncName    : GTM_TBU_ANGLE                                               */
/* !Description : Writes the Angle Value                                      */
/*                                                                            */
/******************************************************************************/
#define GTM_TBU_ANGLE                GTM_TBU_Angle.U

/******************************************************************************/
/* !FuncName    : vidSET_MODE_TBU                                             */
/* !Description : sets the TBU to Forward/Backward mode                       */
/*                                                                            */
/******************************************************************************/
#define vidSET_MODE_TBU()            vidTBU_MODE_FWBW()

/******************************************************************************/
/* !FuncName    : vidTBU_MODE_FWBW                                            */
/* !Description : Configures TBU ch1 enable                                   */
/*                                                                            */
/******************************************************************************/
#define vidTBU_MODE_FWBW()           GTM_TBU_CH1_CTRL.U = (uint32)(0x1U)

/******************************************************************************/
/* !FuncName    : vidDISABLE_TBU                                              */
/* !Description : Disables the TBU channels (Angular & Timer )                */
/*                                                                            */
/******************************************************************************/
#define vidDISABLE_TBU()             GTM_TBU_CHEN.U = (uint32)(0x00000005U)

/******************************************************************************/
/* !FuncName    : vidENABLE_TBU_ANG_TMR_CNTR                                  */
/* !Description : Enables the TBU angular and Timer counters                  */
/*                                                                            */
/******************************************************************************/
#define vidENABLE_TBU_ANG_TMR_CNTR() GTM_TBU_CHEN.U = (uint32)(0xAU)

/******************************************************************************/
/* !FuncName    : vidENABLE_TBU_TMR_CNTR                                      */
/* !Description : Enables the TBU Timer Counter                               */
/*                                                                            */
/******************************************************************************/
#define vidENABLE_TBU_TMR_CNTR() \
   IFX_GTM_WRITE_REG(GTM_TBU_CHEN.U, \
                          IFX_GTM_TBU_CHEN_ENDIS_CH0_WR_MSK_BIT, \
                IFX_GTM_TBU_CHEN_ENDIS_CH0_OFF, \
                          0x2U)

/******************************************************************************/
/* !FuncName    : vidENABLE_TBU_ANG_CNTR                                      */
/* !Description : Enables the TBU Angular Counter                             */
/*                                                                            */
/******************************************************************************/
#define vidENABLE_TBU_ANG_CNTR() \
   IFX_GTM_WRITE_REG(GTM_TBU_CHEN.U, \
                     (uint32)IFX_GTM_TBU_CHEN_ENDIS_CH1_WR_MSK_BIT, \
                     (uint32)IFX_GTM_TBU_CHEN_ENDIS_CH1_OFF, \
                     0x2U)
/* GTM_TBU_CHEN.B.ENDIS_CH1 = (uint32)(0x2U) */

/******************************************************************************/
/* !FuncName    : vidDISABLE_TBU_ANG_CNTR                                     */
/* !Description : Disables the TBU Angular Counter                            */
/*                                                                            */
/******************************************************************************/
#define vidDISABLE_TBU_ANG_CNTR() \
   IFX_GTM_WRITE_REG(GTM_TBU_CHEN.U, \
                     IFX_GTM_TBU_CHEN_ENDIS_CH1_WR_MSK_BIT, \
                     IFX_GTM_TBU_CHEN_ENDIS_CH1_OFF, \
                     0x1U)
/*GTM_TBU_CHEN.B.ENDIS_CH1 = (uint32)(0x1U)*/

/******************************************************************************/
/* !FuncName    : vidSET_GTM_TBU_ANGLE                                        */
/* !Description : Configures the TBU Channel Enable register, as per passed   */
/*                parameter - for Enable/Disable                              */
/*                                                                            */
/******************************************************************************/
#define vidSET_GTM_TBU_ANGLE(snEnableClrValue) \
do \
{ \
   GTM_TBU_CHEN.U     = (uint32)snEnableClrValue; \
   GTM_TBU_CH1_BASE.U = 0U; \
} \
while(0)

/******************************************************************************/
/**** MACRO - DPLL           **************************************************/
/******************************************************************************/
/** \brief Macro: returns Interrupt Enable Status
 *
 * \param None
 *
 * \return None.
 */
/*
#define GET_GTM_INTERRUPT_ENABLE_STATUS_CDTI    GTM_DPLL_IRQ_EN.B.CDTI_IRQ_EN
#define GET_GTM_INTERRUPT_ENABLE_STATUS_MTI     GTM_DPLL_IRQ_EN.B.MTI_IRQ_EN
#define GET_GTM_INTERRUPT_ENABLE_STATUS_GLI     GTM_DPLL_IRQ_EN.B.GL1I_IRQ_EN
#define GET_GTM_INTERRUPT_ENABLE_STATUS_LLI     GTM_DPLL_IRQ_EN.B.LL1I_IRQ_EN
#define GET_GTM_INTERRUPT_ENABLE_STATUS_TE1     GTM_DPLL_IRQ_EN.B.TE1I_IRQ_EN
*/

/******************************************************************************/
/** \brief Macro: Enables Selected Interrupts
 *
 * \param None
 *
 * \return None.
 */
/******************************************************************************/
/* #define GTM_ENABLE_INTERRUPT_CDTI   GTM_DPLL_IRQ_EN.B.CDTI_IRQ_EN = 1U */
#define GTM_ENABLE_INTERRUPT_CDTI \
   IFX_GTM_SET_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_CDTI_IRQ_EN_OFF)
/* #define GTM_ENABLE_INTERRUPT_MTI GTM_DPLL_IRQ_EN.B.MTI_IRQ_EN = 1U */
#define GTM_ENABLE_INTERRUPT_MTI \
   IFX_GTM_SET_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_MTI_IRQ_EN_OFF)
/* #define GTM_ENABLE_INTERRUPT_GLI GTM_DPLL_IRQ_EN.B.GL1I_IRQ_EN = 1U */
#define GTM_ENABLE_INTERRUPT_GLI \
   IFX_GTM_SET_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_GL1I_IRQ_EN_OFF)
/* #define GTM_ENABLE_INTERRUPT_LLI GTM_DPLL_IRQ_EN.B.LL1I_IRQ_EN = 1U */
#define GTM_ENABLE_INTERRUPT_LLI \
   IFX_GTM_SET_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_LL1I_IRQ_EN_OFF)
/* #define GTM_ENABLE_INTERRUPT_TE0 GTM_DPLL_IRQ_EN.B.TE0I_IRQ_EN = 1U */
#define GTM_ENABLE_INTERRUPT_TE0 \
   IFX_GTM_SET_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_TE0I_IRQ_EN_OFF)
/* #define GTM_ENABLE_INTERRUPT_TE1 GTM_DPLL_IRQ_EN.B.TE1I_IRQ_EN = 1U */
#define GTM_ENABLE_INTERRUPT_TE1 \
   IFX_GTM_SET_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_TE1I_IRQ_EN_OFF)
/* #define GTM_ENABLE_INTERRUPT_DIR GTM_DPLL_IRQ_EN.B.DCGI = 1U */
#define GTM_ENABLE_INTERRUPT_DIR \
		IFX_GTM_SET_BIT(GTM_DPLL_IRQ_EN.U,IFX_GTM_DPLL_IRQ_EN_DCGI_OFF)
/*#define GTM_ENABLE_INTERRUPT_TISI GTM_DPLL_IRQ_EN.B.TISI = 1U*/
#define GTM_ENABLE_INTERRUPT_TISI \
		IFX_GTM_SET_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_TISI_IRQ_EN_OFF)
/*#define GTM_ENABLE_INTERRUPT_TLR GTM_DPLL_IRQ_EN.B.TLR = 1U*/
/*#define GTM_ENABLE_INTERRUPT_TLR \
		IFX_GTM_SET_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_TORI_OFF)
*/
/******************************************************************************/
/** \brief Macro: Disables Selected Interrupts
 *
 * \param None
 *
 * \return None.
 */
/******************************************************************************/
/* #define GTM_DISABLE_INTERRUPT_CDTI  GTM_DPLL_IRQ_EN.B.CDTI_IRQ_EN = 0U */
#define GTM_DISABLE_INTERRUPT_CDTI \
   IFX_GTM_CLEAR_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_CDTI_IRQ_EN_OFF)
/* #define GTM_DISABLE_INTERRUPT_MTI   GTM_DPLL_IRQ_EN.B.MTI_IRQ_EN = 0U */
#define GTM_DISABLE_INTERRUPT_MTI \
   IFX_GTM_CLEAR_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_MTI_IRQ_EN_OFF)
/* #define GTM_DISABLE_INTERRUPT_GLI   GTM_DPLL_IRQ_EN.B.GL1I_IRQ_EN = 0U */
#define GTM_DISABLE_INTERRUPT_GLI \
   IFX_GTM_CLEAR_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_GL1I_IRQ_EN_OFF)
/* #define GTM_DISABLE_INTERRUPT_LLI   GTM_DPLL_IRQ_EN.B.LL1I_IRQ_EN = 0U */
#define GTM_DISABLE_INTERRUPT_LLI \
   IFX_GTM_CLEAR_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_LL1I_IRQ_EN_OFF)
/* #define GTM_DISABLE_INTERRUPT_TE0   GTM_DPLL_IRQ_EN.B.TE0I_IRQ_EN = 0U */
#define GTM_DISABLE_INTERRUPT_TE0 \
   IFX_GTM_CLEAR_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_TE0I_IRQ_EN_OFF)
/* #define GTM_DISABLE_INTERRUPT_TE1   GTM_DPLL_IRQ_EN.B.TE1I_IRQ_EN = 0U */
#define GTM_DISABLE_INTERRUPT_TE1 \
   IFX_GTM_CLEAR_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_TE1I_IRQ_EN_OFF)
/* #define GTM_DISABLE_INTERRUPT_DIR   GTM_DPLL_IRQ_EN.B.DCGI = 0U */
#define GTM_DISABLE_INTERRUPT_DIR \
		IFX_GTM_CLEAR_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_DCGI_OFF)
/*#define GTM_DISABLE_INTERRUPT_TISI   GTM_DPLL_IRQ_EN.B.TISI = 0U*/
#define GTM_DISABLE_INTERRUPT_TISI \
		IFX_GTM_CLEAR_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_TISI_IRQ_EN_OFF)
/*#define GTM_DISABLE_INTERRUPT_TLR   GTM_DPLL_IRQ_EN.B.TLR = 0U*/
/*#define GTM_DISABLE_INTERRUPT_TLR \
		IFX_GTM_CLEAR_BIT(GTM_DPLL_IRQ_EN.U, IFX_GTM_DPLL_IRQ_EN_TORI_OFF)
*/

/******************************************************************************/
/** \brief Macro: Clear Interrupt Notifications
 *
 * \param None
 *
 * \return None.
 */
/******************************************************************************/
/* B.TLR = 1U */
/*#define GTM_CLEAR_NOTIFY_TLR    GTM_DPLL_IRQ_NOTIFY.U = IFX_GTM_DPLL_TLR_BIT*/
/* B.TISI = 1U */
#define GTM_CLEAR_NOTIFY_TISI    GTM_DPLL_IRQ_NOTIFY.U = IFX_GTM_DPLL_TISI_BIT
/* B.CDTI = 1U */
#define GTM_CLEAR_NOTIFY_CDTI   GTM_DPLL_IRQ_NOTIFY.U = IFX_GTM_DPLL_CDTI_BIT
/* B.MTI = 1U */
#define GTM_CLEAR_NOTIFY_MTI    GTM_DPLL_IRQ_NOTIFY.U = IFX_GTM_DPLL_MTI_BIT
/* B.GL1I = 1U */
#define GTM_CLEAR_NOTIFY_GLI    GTM_DPLL_IRQ_NOTIFY.U = IFX_GTM_DPLL_GL1I_BIT
/* B.LL1I = 1U */
#define GTM_CLEAR_NOTIFY_LLI    GTM_DPLL_IRQ_NOTIFY.U = IFX_GTM_DPLL_LL1I_BIT
/* B.TE0I = 1U */
#define GTM_CLEAR_NOTIFY_TE0    GTM_DPLL_IRQ_NOTIFY.U = IFX_GTM_DPLL_TE0I_BIT
/* B.TE1I = 1U */
#define GTM_CLEAR_NOTIFY_TE1    GTM_DPLL_IRQ_NOTIFY.U = IFX_GTM_DPLL_TE1I_BIT
/* B.TE2I = 1U */
#define GTM_CLEAR_NOTIFY_TE2    GTM_DPLL_IRQ_NOTIFY.U = IFX_GTM_DPLL_TE2I_BIT
/* B.DCGI = 1U */
#define GTM_CLEAR_NOTIFY_DIR    GTM_DPLL_IRQ_NOTIFY.U = IFX_GTM_DPLL_DCGI_BIT

/******************************************************************************/
/* !FuncName    : vidRESET_GTM_DPLL_APTs                                      */
/* !Description : Reset DPLL APT - APT & APT2c pointers                       */
/*                                                                            */
/******************************************************************************/
#define vidRESET_GTM_DPLL_APTs() \
do\
{ \
   GTM_DPLL_APT_2C.U = (0U); \
   vidRESET_GTM_DPLL_APT(); \
} \
while(0)

/******************************************************************************/
/* !FuncName    : GTM_DPLL_APT2C_READ                                         */
/* !Description : Reads the current APT pointer located from APT2C register   */
/*                                                                            */
/******************************************************************************/
/* #define GTM_DPLL_APT2C_PTR   GTM_DPLL_APT_2C.B.APT_2c */
#define GTM_DPLL_APT2C_READ   IFX_GTM_READ_REG(GTM_DPLL_APT_2C.U, \
                                               (uint32)IFX_GTM_DPLL_APT_2C_RD_MSK_BIT, \
                                               (uint32)IFX_GTM_DPLL_APT_2C_APT_2C_OFF)

/******************************************************************************/
/* !FuncName    : GTM_DPLL_APT_APT2B_READ                                     */
/* !Description : Reads the current APT2B pointer located from APT register   */
/*                                                                            */
/******************************************************************************/
/* #define GTM_DPLL_APT2B_PTR   GTM_DPLL_APT.B.APT_2B */
#define GTM_DPLL_APT_APT2B_READ   IFX_GTM_READ_REG(GTM_DPLL_APT.U, \
                                      (uint32)IFX_GTM_DPLL_APT_APT2B_RD_MSK_BIT, \
                                      (uint32)IFX_GTM_DPLL_APT_APT_2B_OFF)

/******************************************************************************/
/* !FuncName    : GTM_DPLL_APT_APT_READ                                     */
/* !Description : Reads the current APT pointer located from APT register   */
/*                                                                            */
/******************************************************************************/
#define GTM_DPLL_APT_APT_READ   IFX_GTM_READ_REG(GTM_DPLL_APT.U, \
                                      (uint32)IFX_GTM_DPLL_APT_APT_RD_MSK_BIT, \
                                      (uint32)IFX_GTM_DPLL_APT_APT_OFF)

/******************************************************************************/
/* !FuncName    : vidRESET_GTM_DPLL_APT                                       */
/* !Description : Reset the APT Pointer                                       */
/*                                                                            */
/******************************************************************************/
#define vidRESET_GTM_DPLL_APT()  GTM_DPLL_APT.U = (uint32)(APT_WAPT_2b_setMsk \
                                                | APT_APT_2b_setMsk)

/******************************************************************************/
/* !FuncName    : GTM_DPLL_APT2C_SET                                          */
/* !Description : Reads the current APT pointer from APT2C register           */
/*                                                                            */
/******************************************************************************/
#define GTM_DPLL_APT2C_SET(snValue)\
do\
{ \
 uint32 u32LocalValue ; \
 u32LocalValue = ((uint32)snValue << (uint32)IFX_GTM_DPLL_APT_2C_APT_2C_OFF); \
 GTM_DPLL_APT_2C.U = u32LocalValue ;\
} \
while(0)
/******************************************************************************/
/* !FuncName    : vidSET_GTM_DPLL_APT_APT2b                                   */
/* !Description : Configures the APT2b as per configured parameter            */
/*                                                                            */
/******************************************************************************/
#define vidSET_GTM_DPLL_APT_APT2b(snValue) \
do\
{ \
	uint32 u32LocalValue ; \
	u32LocalValue = ( (uint32)snValue << (uint32)IFX_GTM_DPLL_APT_APT_2B_OFF) ; \
	u32LocalValue |= ((uint32)1 << (uint32)IFX_GTM_DPLL_APT_WAPT_2B_OFF);\
	 GTM_DPLL_APT.U = u32LocalValue;\
} \
while(0)
/***
   uint32 u32LocalVal = (uint32)( ((snValue << IFX_GTM_DPLL_APT_APT_OFF) \
                                | (0x2000U)) \
                      + ((snValue << IFX_GTM_DPLL_APT_APT_2B_OFF) | (0x2U))); \
   GTM_DPLL_APT.U = u32LocalVal; \
**/
/******************************************************************************/
/* !FuncName    : vidSET_GTM_DPLL_APT                                         */
/* !Description : Configures the APT as per configured parameter              */
/*                                                                            */
/******************************************************************************/
#define vidSET_GTM_DPLL_APT_APT(snValue) \
do\
{ \
	uint32 u32LocalValue_2 ; \
	u32LocalValue_2 = ((uint32)snValue << (uint32)IFX_GTM_DPLL_APT_APT_OFF) ; \
	u32LocalValue_2  |= (1U << (uint32)IFX_GTM_DPLL_APT_WAPT_OFF) ; \
	GTM_DPLL_APT.U =  u32LocalValue_2 ; \
} \
while(0)
/******************************************************************************/
/* !FuncName    : snGET_DPLL_NUTC_SYN_old                                     */
/* !Description : Reads the Number of Resent Trigger Events calculated from   */
/*                Number of real and virtual events to be considered for the  */
/*                last increment from NUTC register                           */
/*                                                                            */
/******************************************************************************/
/* #define snGET_DPLL_NUTC_SYN_old()   GTM_DPLL_NUTC.B.SYN_T_old */
#define snGET_DPLL_NUTC_SYN_old() \
   IFX_GTM_READ_REG(GTM_DPLL_NUTC.U, \
                    IFX_GTM_DPLL_NUTC_SYN_T_OLD_RD_MSK_BIT, \
                    IFX_GTM_DPLL_NUTC_SYN_T_OLD_OFF)

/******************************************************************************/
/* !FuncName    : snGET_DPLL_NUTC_SYN                                         */
/* !Description : Reads the Number of Resent Trigger Events calculated from   */
/*                Number of real and virtual events to be considered for the  */
/*                current increment from NUTC register                        */
/*                                                                            */
/******************************************************************************/
/* #define snGET_DPLL_NUTC_SYN      GTM_DPLL_NUTC.B.SYN_T */
#define snGET_DPLL_NUTC_SYN \
   IFX_GTM_READ_REG(GTM_DPLL_NUTC.U, \
                    IFX_GTM_DPLL_NUTC_SYN_T_RD_MSK_BIT, \
                    IFX_GTM_DPLL_NUTC_SYN_T_OFF)

/******************************************************************************/
/* !FuncName    : snSET_DPLL_NUTC_NUTE                                        */
/* !Description : Configures the Number of Recent TRIGGER Events used for     */
/*                calculations Number of recent TRIGGER events used for       */
/*                SUB_INC1 and action calculations modulo 2*(TNUmax+1)        */
/*                                                                            */
/******************************************************************************/
/* #define snSET_DPLL_NUTC_NUTE(Val) \
do \
{ \
   GTM_DPLL_NUTC.B.FST  = (1U); \
   GTM_DPLL_NUTC.B.NUTE = Val; \
} \
while(0) */

#define snSET_DPLL_NUTC_NUTE(Val) \
do \
{ \
   IFX_GTM_WRITE_REG(GTM_DPLL_NUTC.U, \
                     (uint32)IFX_GTM_DPLL_NUTC_NUTE_WR_MSK_BIT, \
                     (uint32)IFX_GTM_DPLL_NUTC_NUTE_OFF, \
                     (((uint32)Val) | (uint32)IFX_GTM_DPLL_NUTC_FST_WNUT_SET_BIT)); \
} \
while(0)

/******************************************************************************/
/* !FuncName    : snGET_DPLL_DT_ACT                                           */
/* !Description : Reads the Duration of last TRIGGER increment                */
/*                                                                            */
/******************************************************************************/
#define snGET_DPLL_DT_ACT()              GTM_DPLL_DT_T_ACT.U

/******************************************************************************/
/* !FuncName    : vidSET_DPLL_NTICNT_NTICNT                                   */
/* !Description : Configures DPLL Number of active TRIGGER events to interrupt*/
/*                                                                            */
/******************************************************************************/
#define vidSET_DPLL_NTICNT_NTICNT(Val)   GTM_DPLL_NTI_CNT.U = Val

/******************************************************************************/
/* !FuncName    : snGET_DPLL_NTICNT_NTICNT                                    */
/* !Description : Reads DPLL Number of active TRIGGER events to interrupt     */
/*                                                                            */
/******************************************************************************/
#define snGET_DPLL_NTICNT_NTICNT()   GTM_DPLL_NTI_CNT.U

/******************************************************************************/
/* !FuncName    : vidSET_DPLL_MPVALL1                                         */
/* !Description : Configures the missing pulses to be added/subtracted        */
/* 				  directly to SUB_INC1 and INC_CNT1 once                      */
/*                                                                            */
/******************************************************************************/
#define vidSET_DPLL_MPVALL1(Val)         GTM_DPLL_MPVAL1.U = Val

/******************************************************************************/
/* !FuncName    : snGET_DPLL_STATUS_BWD                                       */
/* !Description : Gets DPLL BWD (DIR) Status                                  */
/*                                                                            */
/******************************************************************************/
/* #define snGET_DPLL_STATUS_BWD    GTM_DPLL_STATUS.B.BWD1 */
#define snGET_DPLL_STATUS_BWD \
   IFX_GTM_READ_REG(GTM_DPLL_STATUS.U, \
                    IFX_GTM_DPLL_STATUS_BWD1_RD_MSK_BIT, \
                    IFX_GTM_DPLL_STATUS_BWD1_OFF)

/******************************************************************************/
/* !FuncName    : snGET_DPLL_PSTM                                             */
/* !Description : Gets Measured position stamp of last TRIGGER input          */
/*                                                                            */
/******************************************************************************/
#define snGET_DPLL_PSTM                  GTM_DPLL_PSTM_0.U

/******************************************************************************/
/* !FuncName    : snGET_DPLL_PSTM_OLD                                         */
/* !Description : Gets the Measured position stamp of last but one TRIGGER    */
/*				  input                                                       */
/*                                                                            */
/******************************************************************************/
#define snGET_DPLL_PSTM_OLD              GTM_DPLL_PSTM_1.U

/******************************************************************************/
/* !FuncName    : snGET_DPLL_OSW_SWON_T                                       */
/* !Description : Switch bit for LSB address of TRIGGER.                      */
/*                                                                            */
/******************************************************************************/
#define snGET_DPLL_OSW_SWON_T\
   IFX_GTM_READ_REG_BITFIELD(GTM_DPLL_OSW.U, \
                             IFX_GTM_DPLL_OSW_SWON_T_RD_MSK_BIT)

/******************************************************************************/
/* !FuncName    : snGET_DPLL_STATUS_LOCK                                      */
/* !Description : Gets DPLL LOCK Status                                       */
/*                                                                            */
/******************************************************************************/
/* #define snGET_DPLL_STATUS_LOCK   GTM_DPLL_STATUS.B.LOCK1 */
#define snGET_DPLL_STATUS_LOCK \
   IFX_GTM_READ_REG_BITFIELD(GTM_DPLL_STATUS.U, \
                             IFX_GTM_DPLL_STATUS_LOCK1_RD_MSK_BIT)

/******************************************************************************/
/* !FuncName    : vidDISABLE_DPLL_IRQ                                         */
/* !Description : Clears the DPLL IRQ Notification and Disables the IRQ Enable*/
/*                                                                            */
/******************************************************************************/
#define vidDISABLE_DPLL_IRQ() \
do \
{ \
   GTM_DPLL_IRQ_NOTIFY.U = (uint32) 0x0U; \
   GTM_DPLL_IRQ_EN.U     = (uint32) 0x0U; \
}\
while(0)

/******************************************************************************/
/* !FuncName    : vidENABLE_DPLL_IRQ                                          */
/* !Description : Enables the DPLL IRQ                                        */
/*                                                                            */
/******************************************************************************/
#define vidENABLE_DPLL_IRQ()   GTM_DPLL_IRQ_EN.U = (uint32) 0x00142000

/******************************************************************************/
/* !FuncName    : vidENABLE_DPLL_CTRL_DEN                                     */
/* !Description : Enables the DPLL                                            */
/*                                                                            */
/******************************************************************************/
/* #define vidENABLE_DPLL_CTRL_DEN()   GTM_DPLL_CTRL_1.B.DEN = 1U */
#define vidENABLE_DPLL_CTRL_DEN() \
   IFX_GTM_SET_BIT(GTM_DPLL_CTRL_1.U, IFX_GTM_DPLL_CTRL_1_DEN_OFF)

/******************************************************************************/
/* !FuncName    : vidDISABLE_DPLL_CTRL_DEN                                    */
/* !Description : Disable the DPLL                                            */
/*                                                                            */
/******************************************************************************/
/* #define vidDISABLE_DPLL_CTRL_DEN()  GTM_DPLL_CTRL_1.B.DEN = 0U */
#define vidDISABLE_DPLL_CTRL_DEN() \
   IFX_GTM_CLEAR_BIT(GTM_DPLL_CTRL_1.U, IFX_GTM_DPLL_CTRL_1_DEN_OFF)

/******************************************************************************/
/* !FuncName    : snGET_GTM_DPLL_TS                                           */
/* !Description : Gets the Actual signal TRIGGER time stamp register value    */
/*                                                                            */
/******************************************************************************/
#define snGET_GTM_DPLL_TS()   (GTM_DPLL_TS_T_0.U & ((uint32)0x00FFFFFF))

/******************************************************************************/
/* !FuncName    : snGET_GTM_DPLL_TS_OLD                                       */
/* !Description : Gets the Previous signal TRIGGER time stamp register value  */
/*                                                                            */
/******************************************************************************/
#define snGET_GTM_DPLL_TS_OLD() (GTM_DPLL_TS_T_1.U & ((uint32)0x00FFFFFF))

/******************************************************************************/
/* !FuncName    : GTM_SET_TRIGGER_HOLD_TIME                                   */
/* !Description : Configures the TRIGGER hold time min value to THMI register */
/*                                                                            */
/******************************************************************************/
#define GTM_SET_TRIGGER_HOLD_TIME(Val) GTM_DPLL_THMI.U = Val

/******************************************************************************/
/* !FuncName    : GTM_SET_TLR                                                 */
/* !Description : Configures the TRIGGER locking range value; the TOR bit in  */
/*                the DPLL_STATUS register is set when violated               */
/*                                                                            */
/******************************************************************************/
#define GTM_SET_TLR(Val) GTM_DPLL_TLR.U = Val

/******************************************************************************/
/* !FuncName    : GTM_SET_TOV                                                 */
/* !Description : Time Out Value of active TRIGGER Slope TOV register         */
/*                                                                            */
/******************************************************************************/
#define GTM_SET_TOV(Val) GTM_DPLL_TOV.U = Val

/******************************************************************************/
/* !FuncName    : GTM_SET_DPLL_CTRL_1                                         */
/* !Description : Configures the DPLL Control 1 Register                      */
/*                                                                            */
/******************************************************************************/
#define GTM_SET_DPLL_CTRL_1(val) GTM_DPLL_CTRL_1.U = (uint32) (DPLL_CTRL_1_SET \
   | ((val & IFX_GTM_DPLL_CTRL_1_SYN_NT_MSK) << IFX_GTM_DPLL_CTRL_1_SYN_NT_OFF) \
   | ((CRKHAL_udtFALLING_EDGE & IFX_GTM_DPLL_CTRL_1_SSL_MSK) << IFX_GTM_DPLL_CTRL_1_SSL_OFF) \
   | ((CRKHAL_kenuEdgeTypeDetection & IFX_GTM_DPLL_CTRL_1_TSL_MSK) << IFX_GTM_DPLL_CTRL_1_TSL_OFF))

/******************************************************************************/
/*                           Typedefs                                         */
/******************************************************************************/


/******************************************************************************/
/*                           Enums                                            */
/******************************************************************************/


/******************************************************************************/
/*                           Struct                                           */
/******************************************************************************/


/******************************************************************************/
/*                           Variables                                        */
/******************************************************************************/

#define CRKHAL_START_SEC_CODE
#include "CRKHAL_MemMap.h"

/******************************************************************************/
/*                           Function prototypes                              */
/******************************************************************************/

/* void IfxGtm_vidTbusDisable(void); */

/* void IfxGtm_vidTbuEnable(void); */

/* uint8 IfxGtm_u8GetNTooth(void); */

void IfxGtm_vidDpllConfig(uint8 u8TriggerN, \
                          uint8 u8StateN, \
                          uint16 u16MicrotickMlt, \
                          uint8 u8GapHalfScale);

void IfxGtm_vidCrankProfileInit(void);

void IfxGtm_vidTbuReEnable(void);

uint32 IfxGtm_u32TbuConvAbsToRelAng(uint32 u32absAngle);

uint16 IfxGtm_u16TbuCompRelAngles(uint32 u32AlarmStartRel, \
                                  uint32 u32CurrAngle, \
                                  uint32 u32TotalTicksRotation);

uint32 IfxGtm_u32TbuRelToAbsCorrectionFactor(void);

uint16 IfxGtm_u16TbuConvRelToAbsAng(uint32 u32relAngle);

#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

#endif /* IFXGTM_DPLL_H_ */

/*------------------------------ end of file ---------------------------------*/

/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9781                                                                                           */
/* !Description     : L9781 ASIC Abstraction Layer                                                                    */
/*                                                                                                                    */
/* !File            : L9781_CFG_I.h                                                                                   */
/* !Description     : Configuration of the L9781 Component                                                            */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/

#ifndef L9781_CFG_I_H
#define L9781_CFG_I_H

#include "Std_Types.h"

#include "L9781.h"
#include "L9781_I.h"
#include "L9781_L.h"

#include "DGOHAL.h"



/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
/*************************************************************************/
/* !Comment : L9781 SPI Write Frames definition for ASIC ST1             */
/*************************************************************************/
#define L9781_u32GEN_CONF_ST1            L9781_ku32GenConfCfg1
#define L9781_u32PDRV_CONF_ST1           L9781_ku32PdrvConfCfg1
#define L9781_u32ISEN_CONF_ST1           L9781_ku32IsenConfCfg1
#define L9781_u32AB_ZLC_OC_CONF_ST1      L9781_ku32AbZlcOcConfCfg1
#define L9781_u32FP_ZLC_OC_CONF_ST1      L9781_ku32FpZlcOcConfCfg1
#define L9781_u32DCDC_CONF_ST1           L9781_ku32DcdcConfCfg1
#define L9781_u32AB_FRA1_CONF_ST1        L9781_ku32AbFra1ConfCfg1
#define L9781_u32AB_FRA2_CONF_ST1        L9781_ku32AbFra2ConfCfg1
#define L9781_u32AB_FRA3_CONF_ST1        L9781_ku32AbFra3ConfCfg1
#define L9781_u32FP_FRA1_CONF_ST1        L9781_ku32FpFra1ConfCfg1
#define L9781_u32FP_FRA2_CONF_ST1        L9781_ku32FpFra2ConfCfg1
#define L9781_u32DIAG_PROT_CTRL_ST1      L9781_ku32DiagProtCtrlCfg1
#define L9781_u32PROT_FILT_CTRL_ST1      L9781_ku32ProtFiltCtrlCfg1
#define L9781_u32AB_PROT_CONF_ST1        L9781_ku32AbProtConfCfg1
#define L9781_u32FP_PROT_CONF_ST1        L9781_ku32FpProtConfCfg1
#define L9781_u32AB_IDLE_DLY_ST1         L9781_ku32AbIdleDlyCfg1
#define L9781_u32FP_IDLE_DLY_ST1         L9781_ku32FpIdleDlyCfg1
#define L9781_u32UNLOCK_DIAG_ST1         L9781_au32BankToUnlock[L9781_u8ASIC_1_CH]
#define L9781_u32PDRV_ENB_ST1            L9781_ku32PdrvEnbCfg1
#define L9781_u32AB_FRA1_PARA1_ST1       *L9781_kapku32AbFra1Para1[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA1_PARA2_ST1       *L9781_kapku32AbFra1Para2[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA1_PARA3_ST1       *L9781_kapku32AbFra1Para3[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA1_PARA4_ST1       *L9781_kapku32AbFra1Para4[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA2_PARA1_ST1       *L9781_kapku32AbFra2Para1[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA2_PARA2_ST1       *L9781_kapku32AbFra2Para2[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA2_PARA3_ST1       *L9781_kapku32AbFra2Para3[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA2_PARA4_ST1       *L9781_kapku32AbFra2Para4[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA3_PARA1_ST1       *L9781_kapku32AbFra3Para1[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA3_PARA2_ST1       *L9781_kapku32AbFra3Para2[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA3_PARA3_ST1       *L9781_kapku32AbFra3Para3[L9781_u8InjProfileIndex]
#define L9781_u32FP_FRA1_PARA1_ST1       *L9781_kapku32FpFra1Para1[L9781_u8PmpProfileIndex]
#define L9781_u32FP_FRA1_PARA2_ST1       *L9781_kapku32FpFra1Para2[L9781_u8PmpProfileIndex]
#define L9781_u32FP_FRA1_PARA3_ST1       *L9781_kapku32FpFra1Para3[L9781_u8PmpProfileIndex]
#define L9781_u32FP_FRA1_PARA4_ST1       *L9781_kapku32FpFra1Para4[L9781_u8PmpProfileIndex]
#define L9781_u32FP_FRA2_PARA1_ST1       *L9781_kapku32FpFra2Para1[L9781_u8PmpProfileIndex]
#define L9781_u32FP_FRA2_PARA2_ST1       *L9781_kapku32FpFra2Para2[L9781_u8PmpProfileIndex]
#define L9781_u32FP_FRA2_PARA3_ST1       *L9781_kapku32FpFra2Para3[L9781_u8PmpProfileIndex]


/*************************************************************************/
/* !Comment : L9781 SPI Write Frames definition for ASIC ST2             */
/*************************************************************************/
#define L9781_u32GEN_CONF_ST2            L9781_ku32GenConfCfg2
#define L9781_u32PDRV_CONF_ST2           L9781_ku32PdrvConfCfg2
#define L9781_u32ISEN_CONF_ST2           L9781_ku32IsenConfCfg2
#define L9781_u32AB_ZLC_OC_CONF_ST2      L9781_ku32AbZlcOcConfCfg2
#define L9781_u32FP_ZLC_OC_CONF_ST2      L9781_ku32FpZlcOcConfCfg2
#define L9781_u32DCDC_CONF_ST2           L9781_ku32DcdcConfCfg2
#define L9781_u32AB_FRA1_CONF_ST2        L9781_ku32AbFra1ConfCfg2
#define L9781_u32AB_FRA2_CONF_ST2        L9781_ku32AbFra2ConfCfg2
#define L9781_u32AB_FRA3_CONF_ST2        L9781_ku32AbFra3ConfCfg2
#define L9781_u32FP_FRA1_CONF_ST2        L9781_ku32FpFra1ConfCfg2
#define L9781_u32FP_FRA2_CONF_ST2        L9781_ku32FpFra2ConfCfg2
#define L9781_u32DIAG_PROT_CTRL_ST2      L9781_ku32DiagProtCtrlCfg2
#define L9781_u32PROT_FILT_CTRL_ST2      L9781_ku32ProtFiltCtrlCfg2
#define L9781_u32AB_PROT_CONF_ST2        L9781_ku32AbProtConfCfg2
#define L9781_u32FP_PROT_CONF_ST2        L9781_ku32FpProtConfCfg2
#define L9781_u32AB_IDLE_DLY_ST2         L9781_ku32AbIdleDlyCfg2
#define L9781_u32FP_IDLE_DLY_ST2         L9781_ku32FpIdleDlyCfg2
#define L9781_u32UNLOCK_DIAG_ST2         L9781_au32BankToUnlock[L9781_u8ASIC_2_CH]
#define L9781_u32PDRV_ENB_ST2            L9781_ku32PdrvEnbCfg2
#define L9781_u32AB_FRA1_PARA1_ST2       *L9781_kapku32AbFra1Para1[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA1_PARA2_ST2       *L9781_kapku32AbFra1Para2[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA1_PARA3_ST2       *L9781_kapku32AbFra1Para3[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA1_PARA4_ST2       *L9781_kapku32AbFra1Para4[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA2_PARA1_ST2       *L9781_kapku32AbFra2Para1[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA2_PARA2_ST2       *L9781_kapku32AbFra2Para2[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA2_PARA3_ST2       *L9781_kapku32AbFra2Para3[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA2_PARA4_ST2       *L9781_kapku32AbFra2Para4[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA3_PARA1_ST2       *L9781_kapku32AbFra3Para1[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA3_PARA2_ST2       *L9781_kapku32AbFra3Para2[L9781_u8InjProfileIndex]
#define L9781_u32AB_FRA3_PARA3_ST2       *L9781_kapku32AbFra3Para3[L9781_u8InjProfileIndex]
#define L9781_u32FP_FRA1_PARA1_ST2       0x00000000
#define L9781_u32FP_FRA1_PARA2_ST2       0x00000000
#define L9781_u32FP_FRA1_PARA3_ST2       0x00000000
#define L9781_u32FP_FRA1_PARA4_ST2       0x00000000
#define L9781_u32FP_FRA2_PARA1_ST2       0x00000000
#define L9781_u32FP_FRA2_PARA2_ST2       0x00000000
#define L9781_u32FP_FRA2_PARA3_ST2       0x00000000


/*************************************************************************/
/* !Comment : L9781 Number of ASIC components                            */
/*************************************************************************/
#define L9781_u8NB_ASIC                  2


/*************************************************************************/
/* !Comment : L9781 ASIC channel                                         */
/*************************************************************************/
#define L9781_u8ST1_CHANNEL              L9781_u8ASIC_1_CH
#define L9781_u8ST2_CHANNEL              L9781_u8ASIC_2_CH


/*************************************************************************/
/* !Comment : L9781 Number of injector profile for each ASIC             */
/*************************************************************************/
#define L9781_u8NB_INJ_PROF_MAX          4


/*************************************************************************/
/* !Comment : L9781 Number of pump profile for each ASIC                 */
/*************************************************************************/
#define L9781_u8NB_PMP_PROF_MAX          26


/*************************************************************************/
/* !Comment : L9781 Frame buffer pointer for INJ profile of each ASIC    */
/*************************************************************************/
#define L9781_pau32INJ_PROF_BKP_BUFF_ST1 L9781_au32InjProfBkpBuffSt1
#define L9781_pau32INJ_PROF_BKP_BUFF_ST2 L9781_au32InjProfBkpBuffSt2


/*************************************************************************/
/* !Comment : L9781 Frame buffer pointer for PMP profile of each ASIC    */
/*************************************************************************/
#define L9781_pau32PMP_PROF_BKP_BUFF_ST1 L9781_au32PmpProfBkpBuffSt1
#define L9781_pau32PMP_PROF_BKP_BUFF_ST2 L9781_au32PmpProfBkpBuffSt2




/*************************************************************************/
/* !Comment : VBOOST Diagnostic Parameters                               */
/*************************************************************************/
#define L9781_udtDGOHAL_VBOOST_DIAG_CH   DGOHAL_udtL9781_VBOOST
#define L9781_snVBOOST_VOLTAGE           AN_VBOOST


/*************************************************************************/
/* !Comment : L9781 Defintion of the external clock period               */
/*************************************************************************/
#define L9781_udtPERIOD_EXT_CLK          10

/*************************************************************************/
/* !Comment : GPT CFG LINK Channel                                       */
/*************************************************************************/
#define L9781_snGPT_STARTUP_SEQ_CH       GptConf_GptChannel_L9781_STARTUP_SEQUENCE
#define L9781_u32MAX_DLY_GPT_DYNAMIC     0xFFFF

/*************************************************************************/
/* !Comment : PWM CFG LINK Channel                                       */
/*************************************************************************/
#define L9781_snPWM_EXT_CLK_CH           Pwm_17_GtmConf_PwmChannel_M_ASIC_GDI_CLK_EXT

/*************************************************************************/
/* !Comment : PWM CFG LINK Channel                                       */
/*************************************************************************/
#define L9781_snDIO_RST_CH               DioConf_DioChannel_M_ASIC_GDI_RST
#define L9781_snDIO_ENABLE_CH            DioConf_DioChannel_M_ENA_INJ_OUTPUT
#define L9781_snDIO_IRQ_ST1_CH           DioConf_DioChannel_M_ASIC_1_GDI_IRQ
#define L9781_snDIO_IRQ_ST2_CH           DioConf_DioChannel_M_ASIC_2_GDI_IRQ


/*************************************************************************/
/* !Comment : SPI CFG LINK Channel                                       */
/*************************************************************************/
   #define L9781_snSPI_ST1_CH           SpiConf_SpiChannel_L9781_ASIC_1_CH
#define L9781_snSPI_ST1_SEQ          SpiConf_SpiSequence_L9781_ASIC_1_SEQ
#define L9781_snSPI_ST2_CH           SpiConf_SpiChannel_L9781_ASIC_2_CH
#define L9781_snSPI_ST2_SEQ          SpiConf_SpiSequence_L9781_ASIC_2_SEQ


/*************************************************************************/
/* !Comment : DGOHAL CFG LINK Channel                                    */
/*************************************************************************/
#define L9781_udtDGOHAL_BANK_AX_ST1_CH   DGOHAL_udtL9781_INJECTOR_1
#define L9781_udtDGOHAL_BANK_BX_ST1_CH   DGOHAL_udtL9781_INJECTOR_2
#define L9781_udtDGOHAL_BANK_FP_ST1_CH   DGOHAL_udtL9781_FUEL_PUMP
#define L9781_udtDGOHAL_ASIC_ST1_CH   DGOHAL_udtL9781_ASIC_GDI

#define L9781_udtDGOHAL_BANK_AX_ST2_CH   DGOHAL_udtL9781_INJECTOR_3
#define L9781_udtDGOHAL_ASIC_ST2_CH   DGOHAL_udtL9781_ASIC_GDI



/**********************************************************************************************************************/
/* CONSTANTS DECLARATION                                                                                              */
/**********************************************************************************************************************/
/****************/
/* uint32 Const */
/****************/
#define L9781_START_SEC_CONST_32BIT
#include "L9781_MemMap.h"

extern const uint32* const L9781_kapku32AbFra1Para1[L9781_u8NB_INJ_PROF_MAX];

extern const uint32* const L9781_kapku32AbFra1Para2[L9781_u8NB_INJ_PROF_MAX];

extern const uint32* const L9781_kapku32AbFra1Para3[L9781_u8NB_INJ_PROF_MAX];

extern const uint32* const L9781_kapku32AbFra1Para4[L9781_u8NB_INJ_PROF_MAX];

extern const uint32* const L9781_kapku32AbFra2Para1[L9781_u8NB_INJ_PROF_MAX];

extern const uint32* const L9781_kapku32AbFra2Para2[L9781_u8NB_INJ_PROF_MAX];

extern const uint32* const L9781_kapku32AbFra2Para3[L9781_u8NB_INJ_PROF_MAX];

extern const uint32* const L9781_kapku32AbFra2Para4[L9781_u8NB_INJ_PROF_MAX];

extern const uint32* const L9781_kapku32AbFra3Para1[L9781_u8NB_INJ_PROF_MAX];

extern const uint32* const L9781_kapku32AbFra3Para2[L9781_u8NB_INJ_PROF_MAX];

extern const uint32* const L9781_kapku32AbFra3Para3[L9781_u8NB_INJ_PROF_MAX];

extern const uint32* const L9781_kapku32FpFra1Para1[L9781_u8NB_PMP_PROF_MAX];

extern const uint32* const L9781_kapku32FpFra1Para2[L9781_u8NB_PMP_PROF_MAX];

extern const uint32* const L9781_kapku32FpFra1Para3[L9781_u8NB_PMP_PROF_MAX];

extern const uint32* const L9781_kapku32FpFra1Para4[L9781_u8NB_PMP_PROF_MAX];

extern const uint32* const L9781_kapku32FpFra2Para1[L9781_u8NB_PMP_PROF_MAX];

extern const uint32* const L9781_kapku32FpFra2Para2[L9781_u8NB_PMP_PROF_MAX];

extern const uint32* const L9781_kapku32FpFra2Para3[L9781_u8NB_PMP_PROF_MAX];


#define L9781_STOP_SEC_CONST_32BIT
#include "L9781_MemMap.h"
/**********************************************************************************************************************/
/* DATA DECLARATION                                                                                                   */
/**********************************************************************************************************************/
/*********************/
/* boolean Variables */
/*********************/
#define L9781_START_SEC_VAR_CLEARED_BOOLEAN
#include "L9781_MemMap.h"

extern boolean L9781_abFirstDiagRead[L9781_u8NB_ASIC];
extern boolean L9781_abBankLock[L9781_u8NB_BANK];

#define L9781_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "L9781_MemMap.h"


/*******************/
/* uint8 Variables */
/*******************/
#define L9781_START_SEC_VAR_CLEARED_8BIT
#include "L9781_MemMap.h"

extern uint8 L9781_au8UnlockTimeOut[L9781_u8NB_BANK][L9781_u8NB_ASIC];
extern uint8 L9781_au8PmpProfile[L9781_u8NB_ASIC];
extern uint8 L9781_au8InjProfile[L9781_u8NB_ASIC];

#define L9781_STOP_SEC_VAR_CLEARED_8BIT
#include "L9781_MemMap.h"


/********************/
/* uint16 Variables */
/********************/
#define L9781_START_SEC_VAR_CLEARED_16BIT
#include "L9781_MemMap.h"

extern uint16 L9781_au16FailureCounter[L9781_u8NB_BANK][L9781_u8NB_ASIC];

#define L9781_STOP_SEC_VAR_CLEARED_16BIT
#include "L9781_MemMap.h"


/********************/
/* uint32 Variables */
/********************/
#define L9781_START_SEC_VAR_CLEARED_32BIT
#include "L9781_MemMap.h"

extern uint32 L9781_au32DiagFpFrame[L9781_u8NB_ASIC];
extern uint32 L9781_au32IcStatusFrame[L9781_u8NB_ASIC];
extern uint32 L9781_au32DiagBankAFrame[L9781_u8NB_ASIC];
extern uint32 L9781_au32DiagBankBFrame[L9781_u8NB_ASIC];
extern uint32 L9781_au32BankToUnlock[L9781_u8NB_ASIC];
extern uint32 L9781_au32InjProfBkpBuffSt1[L9781_u8NB_FRAME_INJ_PROF];
extern uint32 L9781_au32PmpProfBkpBuffSt1[L9781_u8NB_FRAME_PMP_PROF];
extern uint32 L9781_au32InjProfBkpBuffSt2[L9781_u8NB_FRAME_INJ_PROF];
extern uint32 L9781_au32PmpProfBkpBuffSt2[L9781_u8NB_FRAME_PMP_PROF];

#define L9781_STOP_SEC_VAR_CLEARED_32BIT
#include "L9781_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define L9781_START_SEC_CODE
#include "L9781_MemMap.h"

extern boolean L9781_bReadIrqDiag(uint8 u8Channel);
extern void    L9781_vidClearAllDiag(uint8 u8Channel);
extern void    L9781_vidSpiLoadGenConf(uint8 u8Channel);
extern void    L9781_vidSpiLoadInjProf(uint8 u8Channel);
extern void    L9781_vidSpiLoadPmpProf(uint8 u8Channel);
extern void    L9781_vidSpiLoadUnlock(uint8 u8Channel);
extern void    L9781_vidSpiRequest(uint8 u8Channel);
extern void    L9781_vidUpdateDiag(uint8 u8Channel);

#define L9781_STOP_SEC_CODE
#include "L9781_MemMap.h"

#endif /* L9781_CFG_I_H */

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/


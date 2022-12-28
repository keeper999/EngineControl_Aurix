/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_Private.h                                                                                 */
/* !Description     : L9960 Private definition                                                                        */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A6055.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
#ifndef L9960_PRIVATE_H
#define L9960_PRIVATE_H

#include "L9960_Cfg.h"
#include "L9960_Types.h"


/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

/* Duty Cycle max value */
#define L9960_MAX_DUTY_CYCLE 32768
#define L9960_MIN_DUTY_CYCLE (-32768)

/* Duty Cycle value for driving the DIR pin */
#define L9960_FORWARD_DIR_DUTYCYCLE 32768u
#define L9960_REVERSE_DIR_DUTYCYCLE 0u

/* Number max -1 of allowed of failed Check register read  */
/* TODO: generate by OIL ? */
#define L9960_u8REGISTER_CHECK_NUMBER_OF_TRY 2
#define L9960_u8REGISTER_INIT_NUMBER_OF_TRY 3

/**********************************************************************************************************************/
/* return value of SpiM notifications                                                                                 */
/**********************************************************************************************************************/
#define L9960_E_OK            0
#define L9960_E_NOT_OK        1
#define L9960_E_SPI_ERROR     2
#define L9960_E_SPI_RUNNING   3

/**********************************************************************************************************************/
/* return value of L9960_u8HWSCManagement                                                                             */
/**********************************************************************************************************************/
#define L9960_u8HWSC_OK             0
#define L9960_u8HWSC_NOT_OK         1
#define L9960_u8HWSC_BUSY           2
#define L9960_u8HWSC_RESEND_HWSC    3


/**********************************************************************************************************************/
/* SPI protocol defines                                                                                               */
/**********************************************************************************************************************/

/* OVER_CURRENT registers bits (answer of cmd #1) */
#define L9960_bfOVER_CURRENT_OCH1_BITS         (0x0600u)
#define L9960_bfOVER_CURRENT_OCH0_BITS         (0x00C0u)
#define L9960_bfOVER_CURRENT_OCL1_BITS         (0x0018u)
#define L9960_bfOVER_CURRENT_OCL0_BITS         (0x0003u)

#define L9960_bfOVERLOAD_ON_OCH1    L9960_bfOVER_CURRENT_OCH1_BITS
#define L9960_bfOVERLOAD_ON_OCH0    L9960_bfOVER_CURRENT_OCH0_BITS
#define L9960_bfOVERLOAD_ON_OCL1    L9960_bfOVER_CURRENT_OCL1_BITS
#define L9960_bfOVERLOAD_ON_OCL0    L9960_bfOVER_CURRENT_OCL0_BITS

/* RESTART TRIGGER Command Configuration bits values (cmd #2) */
#define L9960_u16SPI_RESTART_TRIGGER_HWSC_TRIG   (0x0200u)
#define L9960_u16SPI_RESTART_TRIGGER_RESET_TRIG  (0x0400u)
#define L9960_u16SPI_RESTART_TRIGGER_CC_CONFIG   (0x0100u)

/* CONFIG_1  Command Configuration bits values (cmd #3) */
#define L9960_u16SPI_CONFIG_REG_1_CL_MASK           (0x0C00u)
#define L9960_u16SPI_CONFIG_REG_1_NOSR_MASK         (0x0200u)
#define L9960_u16SPI_CONFIG_REG_1_ISR_MASK          (0x0100u)
#define L9960_u16SPI_CONFIG_REG_1_VSR_MASK          (0x0080u)
#define L9960_u16SPI_CONFIG_REG_1_TDIAG1_MASK       (0x0070u)
#define L9960_u16SPI_CONFIG_REG_1_TSW_LOW_CUR_MASK  (0x0008u)
#define L9960_u16SPI_CONFIG_REG_1_DIAG_CLR_EN_MASK  (0x0002u)

#define L9960_u16SPI_CONFIG_REG_1_CL_POS           (10u)
#define L9960_u16SPI_CONFIG_REG_1_NOSR_POS         (9u)
#define L9960_u16SPI_CONFIG_REG_1_ISR_POS          (8u)
#define L9960_u16SPI_CONFIG_REG_1_VSR_POS          (7u)
#define L9960_u16SPI_CONFIG_REG_1_TDIAG1_POS       (4u)
#define L9960_u16SPI_CONFIG_REG_1_TSW_LOW_CUR_POS  (3u)
#define L9960_u16SPI_CONFIG_REG_1_DIAG_CLR_EN_POS  (1u)

/* CONFIG_2  Command Configuration bits values (cmd #4) */
#define L9960_u16SPI_CONFIG_REG_2_IN1_IN2_IF_MASK      (0x0800u)
#define L9960_u16SPI_CONFIG_REG_2_OTSD_THR_VAR_MASK    (0x0700u)
#define L9960_u16SPI_CONFIG_REG_2_OTWARN_THR_VAR_MASK  (0x00E0u)
#define L9960_u16SPI_CONFIG_REG_2_UV_PROT_EN_MASK      (0x0010u)
#define L9960_u16SPI_CONFIG_REG_2_NSPREAD_MASK         (0x0008u)
#define L9960_u16SPI_CONFIG_REG_2_UV_WIN_MASK          (0x0002u)

#define L9960_u16SPI_CONFIG_REG_2_IN1_IN2_IF_POS      (11u)
#define L9960_u16SPI_CONFIG_REG_2_OTSD_THR_VAR_POS    (8u)
#define L9960_u16SPI_CONFIG_REG_2_OTWARN_THR_VAR_POS  (5u)
#define L9960_u16SPI_CONFIG_REG_2_UV_PROT_EN_POS      (4u)
#define L9960_u16SPI_CONFIG_REG_2_NSPREAD_POS         (3u)
#define L9960_u16SPI_CONFIG_REG_2_UV_WIN_POS          (1u)

/* CONFIG_3  Command Configuration bits values (cmd #5) */
#define L9960_u16SPI_CONFIG_REG_3_VVL_MODE_MASK        (0x0800u)
#define L9960_u16SPI_CONFIG_REG_3_TVVL_MASK            (0x0780u)
#define L9960_u16SPI_CONFIG_REG_3_OTWARN_TSEC_EN_MASK  (0x0002u)

#define L9960_u16SPI_CONFIG_REG_3_VVL_MODE_POS        (11u)
#define L9960_u16SPI_CONFIG_REG_3_TVVL_POS            (7u)
#define L9960_u16SPI_CONFIG_REG_3_OTWARN_TSEC_EN_POS  (1u)

/* CONFIG_4  Command Configuration bits values (cmd #6) */
#define L9960_u16SPI_CONFIG_REG_4_TDSR_MASK              (0x0800u)
#define L9960_u16SPI_CONFIG_REG_4_OL_ON_MASK             (0x0400u)

#define L9960_u16SPI_CONFIG_REG_4_TDSR_POS              (11u)
#define L9960_u16SPI_CONFIG_REG_4_OL_ON_POS             (10u)

/* CONFIG_5  (answer of cmd #7e) */
#define L9960_bfSTATE_5_CC_BIT          (0x0200u)



/* STATE 1 registers bits (answer of cmd #8a) */
#define L9960_bfSTATE_1_NDIS_BIT          (0x0800u)
#define L9960_bfSTATE_1_DIS_BIT           (0x0400u)
#define L9960_bfSTATE_1_BRIDGE_EN_BIT     (0x0200u)
#define L9960_bfSTATE_1_HWSC_BITS         (0x01C0u)
#define L9960_bfSTATE_1_HWSC_NOT_DONE_BIT (0x0100u)  /* bit HWSC not done */
#define L9960_bfSTATE_1_VPS_UV_REG        (0x0020u)
#define L9960_bfSTATE_1_NGFAIL_BIT        (0x0010u)
#define L9960_bfSTATE_1_ILIM_REG_BIT      (0x0008u)
#define L9960_bfSTATE_1_VDD_OV_REG        (0x0004u)
#define L9960_bfSTATE_1_VDD_UV_REG        (0x0002u)
#define L9960_bfSTATE_1_VPS_UV            (0x0001u)



/* L9960_bfSTATE_1_HWSC_BITS values             */ 
/*    100 : Diag Done / HWSC and LBIST fail     */
/*    101 : HWSC running and LBIST success      */
/*    110 : HWSC fail and LBIST success         */
/*    111 : Diag Done / HWSC and LBIST success  */
#define L9960_bfSTATE_1_HWSC_FAIL_LBIST_FAIL     (0x0100u)
#define L9960_bfSTATE_1_HWSC_RUNNING_LBIST_OK    (0x0140u)
#define L9960_bfSTATE_1_HWSC_FAIL_LBIST_OK       (0x0180u)
#define L9960_bfSTATE_1_HWSC_OK_LBIST_OK         (0x01c0u)



/* STATE 2 registers bits (answer of cmd #8b) */
#define L9960_bfSTATE_2_OTSDCNT_BITS      (0x0FC0u)
#define L9960_bfSTATE_2_OTWARN_BIT        (0x0020u)
#define L9960_bfSTATE_2_OTWARN_REG_BIT    (0x0010u)
#define L9960_bfSTATE_2_NOTSD_BIT         (0x0008u)
#define L9960_bfSTATE_2_NOTSD_REG_BIT     (0x0004u)
#define L9960_bfSTATE_2_OL_ON_STATUS_BITS (0x0003u)

/* Open load bits L9960_bfSTATE_2_OL_ON_STATUS_BITS values */ 
#define L9960_bfSTATE_2_OL_ON_DONE_BIT     (0x0002u)
#define L9960_bfSTATE_2_OL_ON_DETECTED_BIT (0x0001u)


/* OFF DIAG bits (send command #9) */
#define L9960_bfOFF_DIAG_TRIG_BIT          (0x02u)

/* OFF DIAG bits (answer of cmd #9) */
#define L9960_bfOFF_DIAG_OFF_BITS          (0x07u)

/* Off Diag bits L9960_bfOFF_DIAG_OFF_BITS values         */ 
/* Decode Off Diag register                               */
/*    001 : Diag Done / Open Load detected                */
/*    010 : Short Circuit to VBatt (over current)         */
/*    011 : Short Circuit to Ground (over current)        */
/*    100 : Diag Done (no failure)                        */
/*    101 : Incorrect State to perform the Off diagnostic */
/*    110 : Diag not triggered (or Thz not expired)       */
/*    111 : Diag in progress                              */
#define L9960_bfOFF_DIAG_OPEN_LOAD         (0x01u)
#define L9960_bfOFF_DIAG_SHORT_VBATT       (0x02u)
#define L9960_bfOFF_DIAG_SHORT_GROUND      (0x03u)
#define L9960_bfOFF_DIAG_NO_FAULT          (0x04u)
#define L9960_bfOFF_DIAG_INCORRECT_STATE   (0x05u)
#define L9960_bfOFF_DIAG_NOT_TRIGGED       (0x06u)
#define L9960_bfOFF_DIAG_IN_PROGRESS       (0x07u)



/* Error Code */
#define L9960_u8SPI_OK                          0
#define L9960_u8SPI_RESEND                      1
#define L9960_u8SPI_FAILURE                     2
#define L9960_u8SPI_SEND_WRONG_CMD              3

/**********************************************************************************************************************/
/* CONSTANTS                                                                                                          */
/**********************************************************************************************************************/
#define L9960_START_SEC_CONST_UNSPECIFIED
#include "L9960_MemMap.h"

extern const L9960_tstrConfig L9960_akstrConfig[L9960_u8NB_OF_DEVICE];

#define L9960_STOP_SEC_CONST_UNSPECIFIED
#include "L9960_MemMap.h"


/**********************************************************************************************************************/
/* CALIBRATIONS                                                                                                       */
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* VARIABLES                                                                                                          */
/**********************************************************************************************************************/
#define L9960_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "L9960_MemMap.h"

extern L9960_strData L9960_astrData[L9960_u8NB_OF_DEVICE];

#define L9960_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "L9960_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/

#define L9960_START_SEC_CODE
#include "L9960_MemMap.h"

/* L9960_Registers.c */
extern Std_ReturnType L9960_udtCheckConfigValuesFromFlash(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern Std_ReturnType L9960_udtCheckConfigValuesFromRAM(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern Std_ReturnType L9960_udtCheckConfigReg_1(uint16 u16ConfigReg, uint16 u16CheckReg);
extern Std_ReturnType L9960_udtCheckConfigReg_2(uint16 u16ConfigReg, uint16 u16CheckReg);
extern Std_ReturnType L9960_udtCheckConfigReg_3(uint16 u16ConfigReg, uint16 u16CheckReg);
extern Std_ReturnType L9960_udtCheckConfigReg_4(uint16 u16ConfigReg, uint16 u16CheckReg);
extern Std_ReturnType L9960_udtCheckConfigReg_5(uint16 u16ConfigReg, uint16 u16CheckReg);
extern uint16 L9960_u16SetDefaultValueRegConfig1(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern uint16 L9960_u16SetDefaultValueRegConfig2(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern uint16 L9960_u16SetDefaultValueRegConfig3(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern uint16 L9960_u16SetDefaultValueRegConfig4(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidDecodeRegState1(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidDecodeRegState2(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidDecodeRegState5(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern void L9960_vidDecodeRegOverCurrent(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
extern boolean L9960_bDecodeDiagnosticOff(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);

/* L9960_Main.c */
extern void L9960_vidEnterInEnableState(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);

#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"


#endif /* L9960_PRIVATE_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

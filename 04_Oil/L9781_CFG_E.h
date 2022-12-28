/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9781                                                                                           */
/* !Description     : L9781 ASIC Abstraction Layer                                                                    */
/*                                                                                                                    */
/* !File            : L9781_CFG_E.h                                                                                   */
/* !Description     : Configuration of the L9781 Component                                                            */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/

#ifndef L9781_CFG_E_H
#define L9781_CFG_E_H

#include "Std_Types.h"

#include "L9781.h"
#include "L9781_I.h"
#include "L9781_L.h"

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

/*********************************************/
/* !Comment : L9781 Defintion of all channel */
/*********************************************/
#define L9781_u8ASIC_1_CH       0
#define L9781_u8ASIC_2_CH       1

/*******************************************************/
/* !Comment : L9781 Defintion of all injector profiles */
/*******************************************************/
#define L9781_u8PROF_HIGH_PRESS_INJ     0
#define L9781_u8PROF_LOW_PRESS_INJ     1
#define L9781_u8PROF_NOM_PRESS_INJ     2
#define L9781_u8PROF_OVER_PRESS_INJ     3

/***************************************************/
/* !Comment : L9781 Defintion of all pump profiles */
/***************************************************/
#define L9781_u8IDX_PROF_01_PMP     0
#define L9781_u8IDX_PROF_02_PMP     1
#define L9781_u8IDX_PROF_03_PMP     2
#define L9781_u8IDX_PROF_04_PMP     3
#define L9781_u8IDX_PROF_05_PMP     4
#define L9781_u8IDX_PROF_06_PMP     5
#define L9781_u8IDX_PROF_07_PMP     6
#define L9781_u8IDX_PROF_08_PMP     7
#define L9781_u8IDX_PROF_09_PMP     8
#define L9781_u8IDX_PROF_10_PMP     9
#define L9781_u8IDX_PROF_11_PMP     10
#define L9781_u8IDX_PROF_12_PMP     11
#define L9781_u8IDX_PROF_13_PMP     12
#define L9781_u8IDX_PROF_14_PMP     13
#define L9781_u8IDX_PROF_15_PMP     14
#define L9781_u8IDX_PROF_16_PMP     15
#define L9781_u8IDX_PROF_17_PMP     16
#define L9781_u8IDX_PROF_18_PMP     17
#define L9781_u8IDX_PROF_19_PMP     18
#define L9781_u8IDX_PROF_20_PMP     19
#define L9781_u8IDX_PROF_21_PMP     20
#define L9781_u8IDX_PROF_22_PMP     21
#define L9781_u8IDX_PROF_23_PMP     22
#define L9781_u8IDX_PROF_24_PMP     23
#define L9781_u8IDX_PROF_25_PMP     24
#define L9781_u8IDX_PROF_26_PMP     25

/***************************************************************/
/* !Comment : L9781 Defintion of default injector/pump profile */
/***************************************************************/
#define L9781_u8IDX_INJ_PROF_DEF   L9781_u8PROF_LOW_PRESS_INJ
#define L9781_u8IDX_PMP_PROF_DEF   L9781_u8IDX_PROF_01_PMP

/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define L9781_START_SEC_CODE
#include "L9781_MemMap.h"

extern void L9781_vidSpiRx_ST1(void);
extern void L9781_vidSpiRx_ST2(void);
extern void L9781_vidSpiTx_ST1(void);
extern void L9781_vidSpiTx_ST2(void);

#define L9781_STOP_SEC_CODE
#include "L9781_MemMap.h"

#endif /* L9781_CFG_E_H */

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/

/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : MCAL                                                                                            */
/*                                                                                                                    */
/* !Component       : DRV_SH7254X                                                                                     */
/* !Description     : SH7254X microcontroller familly driver layer.                                                   */
/*                                                                                                                    */
/* !Module          : INTDRV_I                                                                                        */
/* !Description     : Implementation of the INTDRV Component                                                          */
/*                                                                                                                    */
/* !File            : INTDRV_I.H                                                                                      */
/*                                                                                                                    */
/* !Scope           : PrivateComponent                                                                                */
/*                                                                                                                    */
/* !Target          : Renesas SH7254X                                                                                 */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO                                                                                                    */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* PVCS Information                                                                                                   */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/INTDRV_I.H_v                                                        $*/
/* $Revision::   1.0                                                                                                 $*/
/* $Author::   croche2                                                                        $$Date::   11 Mar 2014 $*/
/**********************************************************************************************************************/


#ifndef INTDRV_I_H
#define INTDRV_I_H

#include "STD_TYPES.H"
//include "micro.h"
//#include "WDTDRV.h"

/**********************************************************************************************************************/
/* !Comment : Priority Registers Shift values                                                                         */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_1                                                */
/**********************************************************************************************************************/
#define INTDRV_u8IRQ0_SHIFT 0x0Cu
#define INTDRV_u8IRQ1_SHIFT 0x08u
#define INTDRV_u8IRQ2_SHIFT 0x04u
#define INTDRV_u8IRQ3_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_2                                                */
/**********************************************************************************************************************/
#define INTDRV_u8IRQ4_SHIFT 0x0Cu
#define INTDRV_u8IRQ5_SHIFT 0x08u
#define INTDRV_u8IRQ6_SHIFT 0x04u
#define INTDRV_u8IRQ7_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_3                                                */
/**********************************************************************************************************************/
#define INTDRV_u8DMAC_0_SHIFT 0x0Cu
#define INTDRV_u8DMAC_1_SHIFT 0x08u
#define INTDRV_u8DMAC_2_SHIFT 0x04u
#define INTDRV_u8DMAC_3_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_4                                                */
/**********************************************************************************************************************/
#define INTDRV_u8DMAC_4_SHIFT 0x0Cu
#define INTDRV_u8DMAC_5_SHIFT 0x08u
#define INTDRV_u8DMAC_6_SHIFT 0x04u
#define INTDRV_u8DMAC_7_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_5                                                */
/**********************************************************************************************************************/
#define INTDRV_u8CMT_0_SHIFT    0x0Cu
#define INTDRV_u8CMT_1_SHIFT    0x08u
#define INTDRV_u8WD_TIMER_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_6                                                */
/**********************************************************************************************************************/
#define INTDRV_u8IC_A0_1_SHIFT 0x0Cu
#define INTDRV_u8IC_A2_3_SHIFT 0x08u
#define INTDRV_u8IC_A4_5_SHIFT 0x04u
#define INTDRV_u8OV_A_SHIFT    0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_7                                                */
/**********************************************************************************************************************/
#define INTDRV_u8CM_B0_1_SHIFT     0x0Cu
#define INTDRV_u8CM_B6_IC_B0_SHIFT 0x08u
#define INTDRV_u8IC_CM_C0_SHIFT    0x04u
#define INTDRV_u8OV_C0_SHIFT       0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_8                                                */
/**********************************************************************************************************************/
#define INTDRV_u8IC_CM_C1_SHIFT 0x0Cu
#define INTDRV_u8OV_C1_SHIFT    0x08u
#define INTDRV_u8IC_CM_C2_SHIFT 0x04u
#define INTDRV_u8OV_C2_SHIFT    0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_9                                                */
/**********************************************************************************************************************/
#define INTDRV_u8IC_CM_C3_SHIFT 0x0Cu
#define INTDRV_u8OV_C3_SHIFT    0x08u
#define INTDRV_u8IC_CM_C4_SHIFT 0x04u
#define INTDRV_u8OV_C4_SHIFT    0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_10                                               */
/**********************************************************************************************************************/
#define INTDRV_u8CM_D0_SHIFT         0x0Cu
#define INTDRV_u8OV_1D0_OV_2D0_SHIFT 0x08u
#define INTDRV_u8UF_D0_SHIFT         0x04u
#define INTDRV_u8CM_D1_SHIFT         0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_11                                               */
/**********************************************************************************************************************/
#define INTDRV_u8OV_1D1_OV_2D1_SHIFT 0x0Cu
#define INTDRV_u8UF_D1_SHIFT         0x08u
#define INTDRV_u8CM_D2_SHIFT         0x04u
#define INTDRV_u8OV_1D2_OV_2D2_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_12                                               */
/**********************************************************************************************************************/
#define INTDRV_u8UF_D2_SHIFT         0x0Cu
#define INTDRV_u8CM_D3_SHIFT         0x08u
#define INTDRV_u8OV_1D3_OV_2D3_SHIFT 0x04u
#define INTDRV_u8UF_D3_SHIFT         0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_14                                               */
/**********************************************************************************************************************/
#define INTDRV_u8CM_E0_SHIFT 0x04u
#define INTDRV_u8CM_E1_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_15                                               */
/**********************************************************************************************************************/
#define INTDRV_u8CM_E2_SHIFT 0x0Cu
#define INTDRV_u8CM_E3_SHIFT 0x08u
#define INTDRV_u8CM_E4_SHIFT 0x04u
#define INTDRV_u8CM_E5_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_16                                               */
/**********************************************************************************************************************/
#define INTDRV_u8IC_F0TO3_SHIFT   0x0Cu
#define INTDRV_u8IC_F4TO7_SHIFT   0x08u
#define INTDRV_u8IC_F8TO11_SHIFT  0x04u
#define INTDRV_u8IC_F12TO15_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_17                                               */
/**********************************************************************************************************************/
#define INTDRV_u8IC_F16TO19_SHIFT 0x0Cu

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_18                                               */
/**********************************************************************************************************************/
#define INTDRV_u8OV_F0TO3_SHIFT   0x0Cu
#define INTDRV_u8OV_F4TO7_SHIFT   0x08u
#define INTDRV_u8OV_F8TO11_SHIFT  0x04u
#define INTDRV_u8OV_F12TO15_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_19                                               */
/**********************************************************************************************************************/
#define INTDRV_u8OV_F16TO19_SHIFT 0x0Cu

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_20                                               */
/**********************************************************************************************************************/
#define INTDRV_u8CM_G0TO3_SHIFT 0x0Cu
#define INTDRV_u8CM_G4TO5_SHIFT 0x08u
#define INTDRV_u8CM_H0_SHIFT    0x04u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_21                                               */
/**********************************************************************************************************************/
#define INTDRV_u8FIFO_FULL_J0TO1_SHIFT 0x0Cu
#define INTDRV_u8OV_J0TO1_SHIFT        0x08u
#define INTDRV_u8FIFO_OV_J0TO1_SHIFT   0x04u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_22                                               */
/**********************************************************************************************************************/
#define INTDRV_u8ADC_A_SHIFT     0x0Cu
#define INTDRV_u8ADC_B_SHIFT     0x08u
#define INTDRV_u8ADCA_0TO3_SHIFT 0x04u
#define INTDRV_u8ADCA_4TO7_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_23                                               */
/**********************************************************************************************************************/
#define INTDRV_u8ADCA_8TO11_SHIFT  0x0Cu
#define INTDRV_u8ADCA_12TO15_SHIFT 0x08u
#define INTDRV_u8ADCB_40_SHIFT     0x04u
#define INTDRV_u8ADCB_41_SHIFT     0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_24                                               */
/**********************************************************************************************************************/
#define INTDRV_u8ADCB_42_SHIFT 0x0Cu
#define INTDRV_u8ADCB_43_SHIFT 0x08u
#define INTDRV_u8ADCB_44_SHIFT 0x04u
#define INTDRV_u8ADCB_45_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_25                                               */
/**********************************************************************************************************************/
#define INTDRV_u8ADCB_46_SHIFT 0x0Cu
#define INTDRV_u8ADCB_47_SHIFT 0x08u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_26                                               */
/**********************************************************************************************************************/
#define INTDRV_u8SCI_A_SHIFT 0x0Cu
#define INTDRV_u8SCI_B_SHIFT 0x08u
#define INTDRV_u8SCI_C_SHIFT 0x04u
#define INTDRV_u8SCI_D_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_27                                               */
/**********************************************************************************************************************/
#define INTDRV_u8SCI_E_SHIFT 0x0Cu
#define INTDRV_u8SPIA_SHIFT 0x08u
#define INTDRV_u8SPIB_SHIFT 0x04u
#define INTDRV_u8SPIC_SHIFT 0x00u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_28                                               */
/**********************************************************************************************************************/
#define INTDRV_u8CANA_SHIFT 0x0Cu
#define INTDRV_u8CANB_SHIFT 0x08u
#define INTDRV_u8CANC_SHIFT 0x04u

/**********************************************************************************************************************/
/* !Comment : Priority Registers Sub Group Shift values for IT_GROUP_29                                               */
/**********************************************************************************************************************/
#define INTDRV_u8ADMA_SHIFT 0x0Cu

/**********************************************************************************************************************/
/* !Comment : Bank Register Configuration                                                                             */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* !Comment : Bank Channel Enable values                                                                              */
/**********************************************************************************************************************/
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_1_BANK_ENABLE 0x0002
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_2_BANK_ENABLE 0x0004
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_3_BANK_ENABLE 0x0008
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_4_BANK_ENABLE 0x0010
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_5_BANK_ENABLE 0x0020
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_6_BANK_ENABLE 0x0040
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_7_BANK_ENABLE 0x0080
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_8_BANK_ENABLE 0x0100
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_9_BANK_ENABLE 0x0200
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_10_BANK_ENABLE 0x0400
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_11_BANK_ENABLE 0x0800
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_12_BANK_ENABLE 0x1000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_13_BANK_ENABLE 0x2000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_14_BANK_ENABLE 0x4000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_15_BANK_ENABLE 0x8000

/**********************************************************************************************************************/
/* !Comment : Bank Channel Disable Values                                                                             */
/**********************************************************************************************************************/
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_1_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_2_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_3_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_4_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_5_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_6_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_7_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_8_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_9_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_10_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_11_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_12_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_13_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_14_BANK_DISABLE 0x0000
#define INTDRV_u16BANK_CONFIG_ITLEVEL_BANK_SELECT_IT_LEV_15_BANK_DISABLE 0x0000

/**********************************************************************************************************************/
/* !Comment : "BANK_FUNCTION_CONFIG" Values                                                                           */
/**********************************************************************************************************************/
#define INTDRV_u16BANK_CONFIG_BANK_FUNCTION_CONFIG_DISABLED 0x0000
#define INTDRV_u16BANK_CONFIG_BANK_FUNCTION_CONFIG_ALL 0x4000
#define INTDRV_u16BANK_CONFIG_BANK_FUNCTION_CONFIG_BY_IT_LEVEL 0xC000

/**********************************************************************************************************************/
/* !Comment : "BANK_OVERFLOW_ENABLE" Values                                                                           */
/**********************************************************************************************************************/
#define INTDRV_u16BANK_CONFIG_BANK_OVERFLOW_ENABLE_ENABLE 0x2000
#define INTDRV_u16BANK_CONFIG_BANK_OVERFLOW_ENABLE_DISABLE 0x0000

/**********************************************************************************************************************/
/* !Comment : The Edge sensitivity values                                                                             */
/**********************************************************************************************************************/
/* !Comment : LOW_LEVEL                                                                                               */
/**********************************************************************************************************************/
#define INTDRV_u16IRQ_0_LOW_LEVEL 0x0000
#define INTDRV_u16IRQ_1_LOW_LEVEL 0x0000
#define INTDRV_u16IRQ_2_LOW_LEVEL 0x0000
#define INTDRV_u16IRQ_3_LOW_LEVEL 0x0000
#define INTDRV_u16IRQ_4_LOW_LEVEL 0x0000
#define INTDRV_u16IRQ_5_LOW_LEVEL 0x0000
#define INTDRV_u16IRQ_6_LOW_LEVEL 0x0000
#define INTDRV_u16IRQ_7_LOW_LEVEL 0x0000

/**********************************************************************************************************************/
/* !Comment : FALLING_EDGE                                                                                            */
/**********************************************************************************************************************/
#define INTDRV_u16IRQ_0_FALLING_EDGE 0x0001
#define INTDRV_u16IRQ_1_FALLING_EDGE 0x0004
#define INTDRV_u16IRQ_2_FALLING_EDGE 0x0010
#define INTDRV_u16IRQ_3_FALLING_EDGE 0x0040
#define INTDRV_u16IRQ_4_FALLING_EDGE 0x0100
#define INTDRV_u16IRQ_5_FALLING_EDGE 0x0400
#define INTDRV_u16IRQ_6_FALLING_EDGE 0x1000
#define INTDRV_u16IRQ_7_FALLING_EDGE 0x4000

/**********************************************************************************************************************/
/* !Comment : RISING_EDGE                                                                                             */
/**********************************************************************************************************************/
#define INTDRV_u16IRQ_0_RISING_EDGE 0x0002
#define INTDRV_u16IRQ_1_RISING_EDGE 0x0008
#define INTDRV_u16IRQ_2_RISING_EDGE 0x0020
#define INTDRV_u16IRQ_3_RISING_EDGE 0x0050
#define INTDRV_u16IRQ_4_RISING_EDGE 0x0200
#define INTDRV_u16IRQ_5_RISING_EDGE 0x0800
#define INTDRV_u16IRQ_6_RISING_EDGE 0x2000
#define INTDRV_u16IRQ_7_RISING_EDGE 0x8000

/**********************************************************************************************************************/
/* !Comment : BOTH_EDGES                                                                                              */
/**********************************************************************************************************************/
#define INTDRV_u16IRQ_0_BOTH_EDGES 0x0003
#define INTDRV_u16IRQ_1_BOTH_EDGES 0x000C
#define INTDRV_u16IRQ_2_BOTH_EDGES 0x0030
#define INTDRV_u16IRQ_3_BOTH_EDGES 0x00C0
#define INTDRV_u16IRQ_4_BOTH_EDGES 0x0300
#define INTDRV_u16IRQ_5_BOTH_EDGES 0x0C00
#define INTDRV_u16IRQ_6_BOTH_EDGES 0x3000
#define INTDRV_u16IRQ_7_BOTH_EDGES 0xC000

/**********************************************************************************************************************/
/* !Comment : It Priority register                                                                                    */
/**********************************************************************************************************************/
#define INTDRV_vu16IT_GROUP_1_PRIORITY_REG INTC.IPR01.WORD
#define INTDRV_vu16IT_GROUP_2_PRIORITY_REG INTC.IPR02.WORD
#define INTDRV_vu16IT_GROUP_3_PRIORITY_REG INTC.IPR03.WORD
#define INTDRV_vu16IT_GROUP_4_PRIORITY_REG INTC.IPR04.WORD
#define INTDRV_vu16IT_GROUP_5_PRIORITY_REG INTC.IPR05.WORD
#define INTDRV_vu16IT_GROUP_6_PRIORITY_REG INTC.IPR06.WORD
#define INTDRV_vu16IT_GROUP_7_PRIORITY_REG INTC.IPR07.WORD
#define INTDRV_vu16IT_GROUP_8_PRIORITY_REG INTC.IPR08.WORD
#define INTDRV_vu16IT_GROUP_9_PRIORITY_REG INTC.IPR09.WORD
#define INTDRV_vu16IT_GROUP_10_PRIORITY_REG INTC.IPR10.WORD
#define INTDRV_vu16IT_GROUP_11_PRIORITY_REG INTC.IPR11.WORD
#define INTDRV_vu16IT_GROUP_12_PRIORITY_REG INTC.IPR12.WORD
#define INTDRV_vu16IT_GROUP_14_PRIORITY_REG INTC.IPR14.WORD
#define INTDRV_vu16IT_GROUP_15_PRIORITY_REG INTC.IPR15.WORD
#define INTDRV_vu16IT_GROUP_16_PRIORITY_REG INTC.IPR16.WORD
#define INTDRV_vu16IT_GROUP_17_PRIORITY_REG INTC.IPR17.WORD
#define INTDRV_vu16IT_GROUP_18_PRIORITY_REG INTC.IPR18.WORD
#define INTDRV_vu16IT_GROUP_19_PRIORITY_REG INTC.IPR19.WORD
#define INTDRV_vu16IT_GROUP_20_PRIORITY_REG INTC.IPR20.WORD
#define INTDRV_vu16IT_GROUP_21_PRIORITY_REG INTC.IPR21.WORD
#define INTDRV_vu16IT_GROUP_22_PRIORITY_REG INTC.IPR22.WORD
#define INTDRV_vu16IT_GROUP_23_PRIORITY_REG INTC.IPR23.WORD
#define INTDRV_vu16IT_GROUP_24_PRIORITY_REG INTC.IPR24.WORD
#define INTDRV_vu16IT_GROUP_25_PRIORITY_REG INTC.IPR25.WORD
#define INTDRV_vu16IT_GROUP_26_PRIORITY_REG INTC.IPR26.WORD
#define INTDRV_vu16IT_GROUP_27_PRIORITY_REG INTC.IPR27.WORD
#define INTDRV_vu16IT_GROUP_28_PRIORITY_REG INTC.IPR28.WORD
#define INTDRV_vu16IT_GROUP_29_PRIORITY_REG INTC.IPR29.WORD


/**********************************************************************************************************************/
/* !Comment : Interrupts Enable bits                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* !Comment : RAM & ROM Interrupts Enable bits                                                                        */
/**********************************************************************************************************************/
#define INTDRV_vbRAM_PARITY_ER_IT_BIT        RAM.RAMINT.BIT.RPEIE
#define INTDRV_vbRAM_DETECT_2BITS_ER_IT_BIT  RAM.RAMINT.BIT.REDIE
#define INTDRV_vbRAM_CORRECT_1BIT_ER_IT_BIT  RAM.RAMINT.BIT.RECIE
#define INTDRV_vbROM_ACCESS_ER_IT_BIT        ROM.FAEINT.BIT.ROMAEIE
#define INTDRV_vbFCU_CMD_LOCK_IT_BIT         ROM.FAEINT.BIT.CMDLKIE
#define INTDRV_vbEEPROM_ACCESS_ER_IT_BIT     ROM.FAEINT.BIT.EEPAEIE
#define INTDRV_vbEEPROM_INST_FETCH_ER_IT_BIT ROM.FAEINT.BIT.EEPIFEIE
#define INTDRV_vbEEPROM_RD_PTCT_ER_IT_BIT    ROM.FAEINT.BIT.EEPRPEIE
#define INTDRV_vbEEPROM_WR_PTCT_ER_IT_BIT    ROM.FAEINT.BIT.EEPWPEIE

/**********************************************************************************************************************/
/* !Comment : SINT Interrupts Enable bits                                                                             */
/**********************************************************************************************************************/
#define INTDRV_vbSINT1_IT_BIT   INTC.SINTR1.BIT.SINTC
#define INTDRV_vbSINT2_IT_BIT   INTC.SINTR2.BIT.SINTC
#define INTDRV_vbSINT3_IT_BIT   INTC.SINTR3.BIT.SINTC
#define INTDRV_vbSINT4_IT_BIT   INTC.SINTR4.BIT.SINTC
#define INTDRV_vbSINT5_IT_BIT   INTC.SINTR5.BIT.SINTC
#define INTDRV_vbSINT6_IT_BIT   INTC.SINTR6.BIT.SINTC
#define INTDRV_vbSINT7_IT_BIT   INTC.SINTR7.BIT.SINTC
#define INTDRV_vbSINT8_IT_BIT   INTC.SINTR8.BIT.SINTC
#define INTDRV_vbSINT9_IT_BIT   INTC.SINTR9.BIT.SINTC
#define INTDRV_vbSINT10_IT_BIT  INTC.SINTR10.BIT.SINTC
#define INTDRV_vbSINT11_IT_BIT  INTC.SINTR11.BIT.SINTC
#define INTDRV_vbSINT12_IT_BIT  INTC.SINTR12.BIT.SINTC
#define INTDRV_vbSINT13_IT_BIT  INTC.SINTR13.BIT.SINTC
#define INTDRV_vbSINT14_IT_BIT  INTC.SINTR14.BIT.SINTC
#define INTDRV_vbSINT15_IT_BIT  INTC.SINTR15.BIT.SINTC

/**********************************************************************************************************************/
/* !Comment : DMA Interrupts Enable bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbDMA_0_0_DEI_IT_BIT DMAC0.CHCR.BIT.IE
#define INTDRV_vbDMA_0_0_HEI_IT_BIT DMAC0.CHCR.BIT.HIE
#define INTDRV_vbDMA_0_1_DEI_IT_BIT DMAC1.CHCR.BIT.IE
#define INTDRV_vbDMA_0_1_HEI_IT_BIT DMAC1.CHCR.BIT.HIE
#define INTDRV_vbDMA_0_2_DEI_IT_BIT DMAC2.CHCR.BIT.IE
#define INTDRV_vbDMA_0_2_HEI_IT_BIT DMAC2.CHCR.BIT.HIE
#define INTDRV_vbDMA_0_3_DEI_IT_BIT DMAC3.CHCR.BIT.IE
#define INTDRV_vbDMA_0_3_HEI_IT_BIT DMAC3.CHCR.BIT.HIE
#define INTDRV_vbDMA_0_4_DEI_IT_BIT DMAC4.CHCR.BIT.IE
#define INTDRV_vbDMA_0_4_HEI_IT_BIT DMAC4.CHCR.BIT.HIE
#define INTDRV_vbDMA_0_5_DEI_IT_BIT DMAC5.CHCR.BIT.IE
#define INTDRV_vbDMA_0_5_HEI_IT_BIT DMAC5.CHCR.BIT.HIE
#define INTDRV_vbDMA_0_6_DEI_IT_BIT DMAC6.CHCR.BIT.IE
#define INTDRV_vbDMA_0_6_HEI_IT_BIT DMAC6.CHCR.BIT.HIE
#define INTDRV_vbDMA_0_7_DEI_IT_BIT DMAC7.CHCR.BIT.IE
#define INTDRV_vbDMA_0_7_HEI_IT_BIT DMAC7.CHCR.BIT.HIE

/**********************************************************************************************************************/
/* !Comment : CMT Interrupts Enable bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbCMT_0_0_CM_IT_BIT CMT.Channel[0].CMCR.BIT.CMIE
#define INTDRV_vbCMT_1_0_CM_IT_BIT CMT.Channel[1].CMCR.BIT.CMIE

/**********************************************************************************************************************/
/* !Comment : TMR_A Interrupts Enable bits                                                                            */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_A0_0_IC_IT_BIT ATUA.TIERA.BIT.ICEA0
#define INTDRV_vbTMR_A0_1_IC_IT_BIT ATUA.TIERA.BIT.ICEA1
#define INTDRV_vbTMR_A0_2_IC_IT_BIT ATUA.TIERA.BIT.ICEA2
#define INTDRV_vbTMR_A0_3_IC_IT_BIT ATUA.TIERA.BIT.ICEA3
#define INTDRV_vbTMR_A0_4_IC_IT_BIT ATUA.TIERA.BIT.ICEA4
#define INTDRV_vbTMR_A0_5_IC_IT_BIT ATUA.TIERA.BIT.ICEA5
#define INTDRV_vbTMR_A0_0_OV_IT_BIT ATUA.TIERA.BIT.OVEA

/**********************************************************************************************************************/
/* !Comment : TMR_B Interrupts Enable bits                                                                            */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_B0_0_CM_IT_BIT ATUB.TIERB.BIT.CMEB0
#define INTDRV_vbTMR_B0_1_CM_IT_BIT ATUB.TIERB.BIT.CMEB1
#define INTDRV_vbTMR_B0_6_CM_IT_BIT ATUB.TIERB.BIT.CMEB6
#define INTDRV_vbTMR_B0_0_IC_IT_BIT ATUB.TIERB.BIT.ICEB0

/**********************************************************************************************************************/
/* !Comment : TMR_C Interrupts Enable bits                                                                            */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_C0_0_IC_CM_IT_BIT ATUC.SUBBLOCK[0].TIERC.BIT.IMEC0
#define INTDRV_vbTMR_C0_1_IC_CM_IT_BIT ATUC.SUBBLOCK[0].TIERC.BIT.IMEC1
#define INTDRV_vbTMR_C0_2_IC_CM_IT_BIT ATUC.SUBBLOCK[0].TIERC.BIT.IMEC2
#define INTDRV_vbTMR_C0_3_IC_CM_IT_BIT ATUC.SUBBLOCK[0].TIERC.BIT.IMEC3
#define INTDRV_vbTMR_C0_0_OV_IT_BIT    ATUC.SUBBLOCK[0].TIERC.BIT.OVEC
#define INTDRV_vbTMR_C1_0_IC_CM_IT_BIT ATUC.SUBBLOCK[1].TIERC.BIT.IMEC0
#define INTDRV_vbTMR_C1_1_IC_CM_IT_BIT ATUC.SUBBLOCK[1].TIERC.BIT.IMEC1
#define INTDRV_vbTMR_C1_2_IC_CM_IT_BIT ATUC.SUBBLOCK[1].TIERC.BIT.IMEC2
#define INTDRV_vbTMR_C1_3_IC_CM_IT_BIT ATUC.SUBBLOCK[1].TIERC.BIT.IMEC3
#define INTDRV_vbTMR_C1_0_OV_IT_BIT    ATUC.SUBBLOCK[1].TIERC.BIT.OVEC
#define INTDRV_vbTMR_C2_0_IC_CM_IT_BIT ATUC.SUBBLOCK[2].TIERC.BIT.IMEC0
#define INTDRV_vbTMR_C2_1_IC_CM_IT_BIT ATUC.SUBBLOCK[2].TIERC.BIT.IMEC1
#define INTDRV_vbTMR_C2_2_IC_CM_IT_BIT ATUC.SUBBLOCK[2].TIERC.BIT.IMEC2
#define INTDRV_vbTMR_C2_3_IC_CM_IT_BIT ATUC.SUBBLOCK[2].TIERC.BIT.IMEC3
#define INTDRV_vbTMR_C2_0_OV_IT_BIT    ATUC.SUBBLOCK[2].TIERC.BIT.OVEC
#define INTDRV_vbTMR_C3_0_IC_CM_IT_BIT ATUC.SUBBLOCK[3].TIERC.BIT.IMEC0
#define INTDRV_vbTMR_C3_1_IC_CM_IT_BIT ATUC.SUBBLOCK[3].TIERC.BIT.IMEC1
#define INTDRV_vbTMR_C3_2_IC_CM_IT_BIT ATUC.SUBBLOCK[3].TIERC.BIT.IMEC2
#define INTDRV_vbTMR_C3_3_IC_CM_IT_BIT ATUC.SUBBLOCK[3].TIERC.BIT.IMEC3
#define INTDRV_vbTMR_C3_0_OV_IT_BIT    ATUC.SUBBLOCK[3].TIERC.BIT.OVEC
#define INTDRV_vbTMR_C4_0_IC_CM_IT_BIT ATUC.SUBBLOCK[4].TIERC.BIT.IMEC0
#define INTDRV_vbTMR_C4_1_IC_CM_IT_BIT ATUC.SUBBLOCK[4].TIERC.BIT.IMEC1
#define INTDRV_vbTMR_C4_2_IC_CM_IT_BIT ATUC.SUBBLOCK[4].TIERC.BIT.IMEC2
#define INTDRV_vbTMR_C4_3_IC_CM_IT_BIT ATUC.SUBBLOCK[4].TIERC.BIT.IMEC3
#define INTDRV_vbTMR_C4_0_OV_IT_BIT    ATUC.SUBBLOCK[4].TIERC.BIT.OVEC

/**********************************************************************************************************************/
/* !Comment : TMR_D Interrupts Enable bits                                                                            */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_1D0_0_CM_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.CMEAD0
#define INTDRV_vbTMR_2D0_0_CM_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.CMEBD0
#define INTDRV_vbTMR_1D0_1_CM_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.CMEAD1
#define INTDRV_vbTMR_2D0_1_CM_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.CMEBD1
#define INTDRV_vbTMR_1D0_2_CM_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.CMEAD2
#define INTDRV_vbTMR_2D0_2_CM_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.CMEBD2
#define INTDRV_vbTMR_1D0_3_CM_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.CMEAD3
#define INTDRV_vbTMR_2D0_3_CM_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.CMEBD3
#define INTDRV_vbTMR_1D0_OV_IT_BIT   ATUD.SUBBLOCKB[0].TIERD.BIT.OVE1D
#define INTDRV_vbTMR_2D0_OV_IT_BIT   ATUD.SUBBLOCKB[0].TIERD.BIT.OVE2D
#define INTDRV_vbTMR_DD0_0_UF_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.UDED0
#define INTDRV_vbTMR_DD0_1_UF_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.UDED1
#define INTDRV_vbTMR_DD0_2_UF_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.UDED2
#define INTDRV_vbTMR_DD0_3_UF_IT_BIT ATUD.SUBBLOCKB[0].TIERD.BIT.UDED3
#define INTDRV_vbTMR_1D1_0_CM_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.CMEAD0
#define INTDRV_vbTMR_2D1_0_CM_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.CMEBD0
#define INTDRV_vbTMR_1D1_1_CM_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.CMEAD1
#define INTDRV_vbTMR_2D1_1_CM_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.CMEBD1
#define INTDRV_vbTMR_1D1_2_CM_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.CMEAD2
#define INTDRV_vbTMR_2D1_2_CM_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.CMEBD2
#define INTDRV_vbTMR_1D1_3_CM_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.CMEAD3
#define INTDRV_vbTMR_2D1_3_CM_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.CMEBD3
#define INTDRV_vbTMR_1D1_OV_IT_BIT   ATUD.SUBBLOCKB[1].TIERD.BIT.OVE1D
#define INTDRV_vbTMR_2D1_OV_IT_BIT   ATUD.SUBBLOCKB[1].TIERD.BIT.OVE2D
#define INTDRV_vbTMR_DD1_0_UF_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.UDED0
#define INTDRV_vbTMR_DD1_1_UF_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.UDED1
#define INTDRV_vbTMR_DD1_2_UF_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.UDED2
#define INTDRV_vbTMR_DD1_3_UF_IT_BIT ATUD.SUBBLOCKB[1].TIERD.BIT.UDED3
#define INTDRV_vbTMR_1D2_0_CM_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.CMEAD0
#define INTDRV_vbTMR_2D2_0_CM_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.CMEBD0
#define INTDRV_vbTMR_1D2_1_CM_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.CMEAD1
#define INTDRV_vbTMR_2D2_1_CM_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.CMEBD1
#define INTDRV_vbTMR_1D2_2_CM_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.CMEAD2
#define INTDRV_vbTMR_2D2_2_CM_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.CMEBD2
#define INTDRV_vbTMR_1D2_3_CM_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.CMEAD3
#define INTDRV_vbTMR_2D2_3_CM_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.CMEBD3
#define INTDRV_vbTMR_1D2_OV_IT_BIT   ATUD.SUBBLOCKB[2].TIERD.BIT.OVE1D
#define INTDRV_vbTMR_2D2_OV_IT_BIT   ATUD.SUBBLOCKB[2].TIERD.BIT.OVE2D
#define INTDRV_vbTMR_DD2_0_UF_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.UDED0
#define INTDRV_vbTMR_DD2_1_UF_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.UDED1
#define INTDRV_vbTMR_DD2_2_UF_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.UDED2
#define INTDRV_vbTMR_DD2_3_UF_IT_BIT ATUD.SUBBLOCKB[2].TIERD.BIT.UDED3
#define INTDRV_vbTMR_1D3_0_CM_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.CMEAD0
#define INTDRV_vbTMR_2D3_0_CM_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.CMEBD0
#define INTDRV_vbTMR_1D3_1_CM_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.CMEAD1
#define INTDRV_vbTMR_2D3_1_CM_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.CMEBD1
#define INTDRV_vbTMR_1D3_2_CM_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.CMEAD2
#define INTDRV_vbTMR_2D3_2_CM_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.CMEBD2
#define INTDRV_vbTMR_1D3_3_CM_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.CMEAD3
#define INTDRV_vbTMR_2D3_3_CM_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.CMEBD3
#define INTDRV_vbTMR_1D3_OV_IT_BIT   ATUD.SUBBLOCKB[3].TIERD.BIT.OVE1D
#define INTDRV_vbTMR_2D3_OV_IT_BIT   ATUD.SUBBLOCKB[3].TIERD.BIT.OVE2D
#define INTDRV_vbTMR_DD3_0_UF_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.UDED0
#define INTDRV_vbTMR_DD3_1_UF_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.UDED1
#define INTDRV_vbTMR_DD3_2_UF_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.UDED2
#define INTDRV_vbTMR_DD3_3_UF_IT_BIT ATUD.SUBBLOCKB[3].TIERD.BIT.UDED3

/**********************************************************************************************************************/
/* !Comment : TMR_E Interrupts Enable bits                                                                            */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_E0_0_CM_IT_BIT ATUE.SUBBLOCK[0].TIERE.BIT.CMEE0
#define INTDRV_vbTMR_E0_1_CM_IT_BIT ATUE.SUBBLOCK[0].TIERE.BIT.CMEE1
#define INTDRV_vbTMR_E0_2_CM_IT_BIT ATUE.SUBBLOCK[0].TIERE.BIT.CMEE2
#define INTDRV_vbTMR_E0_3_CM_IT_BIT ATUE.SUBBLOCK[0].TIERE.BIT.CMEE3
#define INTDRV_vbTMR_E1_0_CM_IT_BIT ATUE.SUBBLOCK[1].TIERE.BIT.CMEE0
#define INTDRV_vbTMR_E1_1_CM_IT_BIT ATUE.SUBBLOCK[1].TIERE.BIT.CMEE1
#define INTDRV_vbTMR_E1_2_CM_IT_BIT ATUE.SUBBLOCK[1].TIERE.BIT.CMEE2
#define INTDRV_vbTMR_E1_3_CM_IT_BIT ATUE.SUBBLOCK[1].TIERE.BIT.CMEE3
#define INTDRV_vbTMR_E2_0_CM_IT_BIT ATUE.SUBBLOCK[2].TIERE.BIT.CMEE0
#define INTDRV_vbTMR_E2_1_CM_IT_BIT ATUE.SUBBLOCK[2].TIERE.BIT.CMEE1
#define INTDRV_vbTMR_E2_2_CM_IT_BIT ATUE.SUBBLOCK[2].TIERE.BIT.CMEE2
#define INTDRV_vbTMR_E2_3_CM_IT_BIT ATUE.SUBBLOCK[2].TIERE.BIT.CMEE3
#define INTDRV_vbTMR_E3_0_CM_IT_BIT ATUE.SUBBLOCK[3].TIERE.BIT.CMEE0
#define INTDRV_vbTMR_E3_1_CM_IT_BIT ATUE.SUBBLOCK[3].TIERE.BIT.CMEE1
#define INTDRV_vbTMR_E3_2_CM_IT_BIT ATUE.SUBBLOCK[3].TIERE.BIT.CMEE2
#define INTDRV_vbTMR_E3_3_CM_IT_BIT ATUE.SUBBLOCK[3].TIERE.BIT.CMEE3
#define INTDRV_vbTMR_E4_0_CM_IT_BIT ATUE.SUBBLOCK[4].TIERE.BIT.CMEE0
#define INTDRV_vbTMR_E4_1_CM_IT_BIT ATUE.SUBBLOCK[4].TIERE.BIT.CMEE1
#define INTDRV_vbTMR_E4_2_CM_IT_BIT ATUE.SUBBLOCK[4].TIERE.BIT.CMEE2
#define INTDRV_vbTMR_E4_3_CM_IT_BIT ATUE.SUBBLOCK[4].TIERE.BIT.CMEE3
#define INTDRV_vbTMR_E5_0_CM_IT_BIT ATUE.SUBBLOCK[5].TIERE.BIT.CMEE0
#define INTDRV_vbTMR_E5_1_CM_IT_BIT ATUE.SUBBLOCK[5].TIERE.BIT.CMEE1
#define INTDRV_vbTMR_E5_2_CM_IT_BIT ATUE.SUBBLOCK[5].TIERE.BIT.CMEE2
#define INTDRV_vbTMR_E5_3_CM_IT_BIT ATUE.SUBBLOCK[5].TIERE.BIT.CMEE3

/**********************************************************************************************************************/
/* !Comment : TMR_F Interrupts Enable bits                                                                            */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_F0_0_IC_IT_BIT   ATUF.SUBBLOCK[0].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F1_0_IC_IT_BIT   ATUF.SUBBLOCK[1].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F2_0_IC_IT_BIT   ATUF.SUBBLOCK[2].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F3_0_IC_IT_BIT   ATUF.SUBBLOCK[3].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F4_0_IC_IT_BIT   ATUF.SUBBLOCK[4].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F5_0_IC_IT_BIT   ATUF.SUBBLOCK[5].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F6_0_IC_IT_BIT   ATUF.SUBBLOCK[6].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F7_0_IC_IT_BIT   ATUF.SUBBLOCK[7].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F8_0_IC_IT_BIT   ATUF.SUBBLOCK[8].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F9_0_IC_IT_BIT   ATUF.SUBBLOCK[9].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F10_0_IC_IT_BIT  ATUF.SUBBLOCK[10].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F11_0_IC_IT_BIT  ATUF.SUBBLOCK[11].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F12_0_IC_IT_BIT  ATUF.SUBBLOCK[12].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F13_0_IC_IT_BIT  ATUF.SUBBLOCK[13].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F14_0_IC_IT_BIT  ATUF.SUBBLOCK[14].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F15_0_IC_IT_BIT  ATUF.SUBBLOCK[15].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F16_0_IC_IT_BIT  ATUF.SUBBLOCK[16].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F17_0_IC_IT_BIT  ATUF.SUBBLOCK[17].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F18_0_IC_IT_BIT  ATUF.SUBBLOCK[18].TIERF.BIT.ICEF
#define INTDRV_vbTMR_F19_0_IC_IT_BIT  ATUF.SUBBLOCK[19].TIERF.BIT.ICEF
#define INTDRV_vbTMR_AF0_0_OV_IT_BIT  ATUF.SUBBLOCK[0].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF0_0_OV_IT_BIT  ATUF.SUBBLOCK[0].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF0_0_OV_IT_BIT  ATUF.SUBBLOCK[0].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF1_0_OV_IT_BIT  ATUF.SUBBLOCK[1].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF1_0_OV_IT_BIT  ATUF.SUBBLOCK[1].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF1_0_OV_IT_BIT  ATUF.SUBBLOCK[1].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF2_0_OV_IT_BIT  ATUF.SUBBLOCK[2].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF2_0_OV_IT_BIT  ATUF.SUBBLOCK[2].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF2_0_OV_IT_BIT  ATUF.SUBBLOCK[2].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF3_0_OV_IT_BIT  ATUF.SUBBLOCK[3].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF3_0_OV_IT_BIT  ATUF.SUBBLOCK[3].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF3_0_OV_IT_BIT  ATUF.SUBBLOCK[3].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF4_0_OV_IT_BIT  ATUF.SUBBLOCK[4].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF4_0_OV_IT_BIT  ATUF.SUBBLOCK[4].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF4_0_OV_IT_BIT  ATUF.SUBBLOCK[4].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF5_0_OV_IT_BIT  ATUF.SUBBLOCK[5].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF5_0_OV_IT_BIT  ATUF.SUBBLOCK[5].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF5_0_OV_IT_BIT  ATUF.SUBBLOCK[5].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF6_0_OV_IT_BIT  ATUF.SUBBLOCK[6].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF6_0_OV_IT_BIT  ATUF.SUBBLOCK[6].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF6_0_OV_IT_BIT  ATUF.SUBBLOCK[6].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF7_0_OV_IT_BIT  ATUF.SUBBLOCK[7].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF7_0_OV_IT_BIT  ATUF.SUBBLOCK[7].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF7_0_OV_IT_BIT  ATUF.SUBBLOCK[7].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF8_0_OV_IT_BIT  ATUF.SUBBLOCK[8].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF8_0_OV_IT_BIT  ATUF.SUBBLOCK[8].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF8_0_OV_IT_BIT  ATUF.SUBBLOCK[8].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF9_0_OV_IT_BIT  ATUF.SUBBLOCK[9].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF9_0_OV_IT_BIT  ATUF.SUBBLOCK[9].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF9_0_OV_IT_BIT  ATUF.SUBBLOCK[9].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF10_0_OV_IT_BIT ATUF.SUBBLOCK[10].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF10_0_OV_IT_BIT ATUF.SUBBLOCK[10].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF10_0_OV_IT_BIT ATUF.SUBBLOCK[10].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF11_0_OV_IT_BIT ATUF.SUBBLOCK[11].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF11_0_OV_IT_BIT ATUF.SUBBLOCK[11].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF11_0_OV_IT_BIT ATUF.SUBBLOCK[11].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF12_0_OV_IT_BIT ATUF.SUBBLOCK[12].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF12_0_OV_IT_BIT ATUF.SUBBLOCK[12].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF12_0_OV_IT_BIT ATUF.SUBBLOCK[12].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF13_0_OV_IT_BIT ATUF.SUBBLOCK[13].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF13_0_OV_IT_BIT ATUF.SUBBLOCK[13].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF13_0_OV_IT_BIT ATUF.SUBBLOCK[13].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF14_0_OV_IT_BIT ATUF.SUBBLOCK[14].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF14_0_OV_IT_BIT ATUF.SUBBLOCK[14].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF14_0_OV_IT_BIT ATUF.SUBBLOCK[14].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF15_0_OV_IT_BIT ATUF.SUBBLOCK[15].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF15_0_OV_IT_BIT ATUF.SUBBLOCK[15].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF15_0_OV_IT_BIT ATUF.SUBBLOCK[15].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF16_0_OV_IT_BIT ATUF.SUBBLOCK[16].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF16_0_OV_IT_BIT ATUF.SUBBLOCK[16].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF16_0_OV_IT_BIT ATUF.SUBBLOCK[16].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF17_0_OV_IT_BIT ATUF.SUBBLOCK[17].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF17_0_OV_IT_BIT ATUF.SUBBLOCK[17].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF17_0_OV_IT_BIT ATUF.SUBBLOCK[17].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF18_0_OV_IT_BIT ATUF.SUBBLOCK[18].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF18_0_OV_IT_BIT ATUF.SUBBLOCK[18].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF18_0_OV_IT_BIT ATUF.SUBBLOCK[18].TIERF.BIT.OVECF
#define INTDRV_vbTMR_AF19_0_OV_IT_BIT ATUF.SUBBLOCK[19].TIERF.BIT.OVEAF
#define INTDRV_vbTMR_BF19_0_OV_IT_BIT ATUF.SUBBLOCK[19].TIERF.BIT.OVEBF
#define INTDRV_vbTMR_CF19_0_OV_IT_BIT ATUF.SUBBLOCK[19].TIERF.BIT.OVECF

/**********************************************************************************************************************/
/* !Comment : TMR_G Interrupts Enable bits                                                                            */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_G0_0_CM_IT_BIT ATUG.SUBBLOCK[0].TCRG.BIT.CMEG
#define INTDRV_vbTMR_G1_0_CM_IT_BIT ATUG.SUBBLOCK[1].TCRG.BIT.CMEG
#define INTDRV_vbTMR_G2_0_CM_IT_BIT ATUG.SUBBLOCK[2].TCRG.BIT.CMEG
#define INTDRV_vbTMR_G3_0_CM_IT_BIT ATUG.SUBBLOCK[3].TCRG.BIT.CMEG
#define INTDRV_vbTMR_G4_0_CM_IT_BIT ATUG.SUBBLOCK[4].TCRG.BIT.CMEG
#define INTDRV_vbTMR_G5_0_CM_IT_BIT ATUG.SUBBLOCK[5].TCRG.BIT.CMEG

/**********************************************************************************************************************/
/* !Comment : TMR_H Interrupts Enable bits                                                                            */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_H0_0_CM_IT_BIT ATUH.TCRH.BIT.CMEH

/**********************************************************************************************************************/
/* !Comment : TMR_J Interrupts Enable bits                                                                            */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_J0_0_FIFO_FULL_IT_BIT ATUJ.SUBBLOCK[0].TIERJ.BIT.FDFEJ
#define INTDRV_vbTMR_J1_0_FIFO_FULL_IT_BIT ATUJ.SUBBLOCK[1].TIERJ.BIT.FDFEJ
#define INTDRV_vbTMR_J0_0_OV_IT_BIT        ATUJ.SUBBLOCK[0].TIERJ.BIT.OVEJ
#define INTDRV_vbTMR_J1_0_OV_IT_BIT        ATUJ.SUBBLOCK[1].TIERJ.BIT.OVEJ
#define INTDRV_vbTMR_J0_0_FIFO_OV_IT_BIT   ATUJ.SUBBLOCK[0].TIERJ.BIT.FDOVEJ
#define INTDRV_vbTMR_J1_0_FIFO_OV_IT_BIT   ATUJ.SUBBLOCK[1].TIERJ.BIT.FDOVEJ

/**********************************************************************************************************************/
/* !Comment : ADC Interrupts Enable bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbADCA_END_SCAN_CONV_IT_BIT    ADCA.ADCSR.BIT.ADIE
#define INTDRV_vbADCB_END_SCAN_CONV_IT_BIT    ADCB.ADCSR.BIT.ADIE
#define INTDRV_vbADCA_0_END_INTR_CONV_IT_BIT  ADCA.ADTRD.BIT.ADIDE0
#define INTDRV_vbADCA_1_END_INTR_CONV_IT_BIT  ADCA.ADTRD.BIT.ADIDE1
#define INTDRV_vbADCA_2_END_INTR_CONV_IT_BIT  ADCA.ADTRD.BIT.ADIDE2
#define INTDRV_vbADCA_3_END_INTR_CONV_IT_BIT  ADCA.ADTRD.BIT.ADIDE3
#define INTDRV_vbADCA_4_END_INTR_CONV_IT_BIT  ADCA.ADTRD.BIT.ADIDE4
#define INTDRV_vbADCA_5_END_INTR_CONV_IT_BIT  ADCA.ADTRD.BIT.ADIDE5
#define INTDRV_vbADCA_6_END_INTR_CONV_IT_BIT  ADCA.ADTRD.BIT.ADIDE6
#define INTDRV_vbADCA_7_END_INTR_CONV_IT_BIT  ADCA.ADTRD.BIT.ADIDE7
#define INTDRV_vbADCA_8_END_INTR_CONV_IT_BIT  ADCA.ADTRD.BIT.ADIDE8
#define INTDRV_vbADCA_9_END_INTR_CONV_IT_BIT  ADCA.ADTRD.BIT.ADIDE9
#define INTDRV_vbADCA_10_END_INTR_CONV_IT_BIT ADCA.ADTRD.BIT.ADIDE10
#define INTDRV_vbADCA_11_END_INTR_CONV_IT_BIT ADCA.ADTRD.BIT.ADIDE11
#define INTDRV_vbADCA_12_END_INTR_CONV_IT_BIT ADCA.ADTRD.BIT.ADIDE12
#define INTDRV_vbADCA_13_END_INTR_CONV_IT_BIT ADCA.ADTRD.BIT.ADIDE13
#define INTDRV_vbADCA_14_END_INTR_CONV_IT_BIT ADCA.ADTRD.BIT.ADIDE14
#define INTDRV_vbADCA_15_END_INTR_CONV_IT_BIT ADCA.ADTRD.BIT.ADIDE15
#define INTDRV_vbADCB_40_END_INTR_CONV_IT_BIT ADCB.ADTRD.BIT.ADIDE40
#define INTDRV_vbADCB_41_END_INTR_CONV_IT_BIT ADCB.ADTRD.BIT.ADIDE41
#define INTDRV_vbADCB_42_END_INTR_CONV_IT_BIT ADCB.ADTRD.BIT.ADIDE42
#define INTDRV_vbADCB_43_END_INTR_CONV_IT_BIT ADCB.ADTRD.BIT.ADIDE43
#define INTDRV_vbADCB_44_END_INTR_CONV_IT_BIT ADCB.ADTRD.BIT.ADIDE44
#define INTDRV_vbADCB_45_END_INTR_CONV_IT_BIT ADCB.ADTRD.BIT.ADIDE45
#define INTDRV_vbADCB_46_END_INTR_CONV_IT_BIT ADCB.ADTRD.BIT.ADIDE46
#define INTDRV_vbADCB_47_END_INTR_CONV_IT_BIT ADCB.ADTRD.BIT.ADIDE47

/**********************************************************************************************************************/
/* !Comment : SCI Interrupts Enable bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbSCI_A_RX_AND_ER_IT_BIT SCIA.SCSCR1.BIT.RIE
#define INTDRV_vbSCI_A_TX_IT_BIT        SCIA.SCSCR1.BIT.TIE
#define INTDRV_vbSCI_A_TX_END_IT_BIT    SCIA.SCSCR1.BIT.TEIE
#define INTDRV_vbSCI_B_RX_AND_ER_IT_BIT SCIB.SCSCR1.BIT.RIE
#define INTDRV_vbSCI_B_TX_IT_BIT        SCIB.SCSCR1.BIT.TIE
#define INTDRV_vbSCI_B_TX_END_IT_BIT    SCIB.SCSCR1.BIT.TEIE
#define INTDRV_vbSCI_C_RX_AND_ER_IT_BIT SCIC.SCSCR1.BIT.RIE
#define INTDRV_vbSCI_C_TX_IT_BIT        SCIC.SCSCR1.BIT.TIE
#define INTDRV_vbSCI_C_TX_END_IT_BIT    SCIC.SCSCR1.BIT.TEIE
#define INTDRV_vbSCI_D_RX_AND_ER_IT_BIT SCID.SCSCR1.BIT.RIE
#define INTDRV_vbSCI_D_TX_IT_BIT        SCID.SCSCR1.BIT.TIE
#define INTDRV_vbSCI_D_TX_END_IT_BIT    SCID.SCSCR1.BIT.TEIE
#define INTDRV_vbSCI_E_RX_AND_ER_IT_BIT SCIE.SCSCR1.BIT.RIE
#define INTDRV_vbSCI_E_TX_IT_BIT        SCIE.SCSCR1.BIT.TIE
#define INTDRV_vbSCI_E_TX_END_IT_BIT    SCIE.SCSCR1.BIT.TEIE

/**********************************************************************************************************************/
/* !Comment : SPI Interrupts Enable bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbRSPI_A_ER_IT_BIT RSPIA.SPCR.BIT.SPEIE
#define INTDRV_vbRSPI_A_RX_IT_BIT RSPIA.SPCR.BIT.SPRIE
#define INTDRV_vbRSPI_A_TX_IT_BIT RSPIA.SPCR.BIT.SPTIE
#define INTDRV_vbRSPI_B_ER_IT_BIT RSPIB.SPCR.BIT.SPEIE
#define INTDRV_vbRSPI_B_RX_IT_BIT RSPIB.SPCR.BIT.SPRIE
#define INTDRV_vbRSPI_B_TX_IT_BIT RSPIB.SPCR.BIT.SPTIE
#define INTDRV_vbRSPI_C_ER_IT_BIT RSPIC.SPCR.BIT.SPEIE
#define INTDRV_vbRSPI_C_RX_IT_BIT RSPIC.SPCR.BIT.SPRIE
#define INTDRV_vbRSPI_C_TX_IT_BIT RSPIC.SPCR.BIT.SPTIE

/**********************************************************************************************************************/
/* !Comment : CAN Interrupts Enable bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbCAN_A_ER_MODE_ER_IT_BIT                             RCANA.IMR.BIT.IMR5
#define INTDRV_vbCAN_A_BUS_OFF_RECOVER_IT_BIT                        RCANA.IMR.BIT.IMR6
#define INTDRV_vbCAN_A_TX_WARNING_ER_IT_BIT                          RCANA.IMR.BIT.IMR3
#define INTDRV_vbCAN_A_RX_WARNING_ER_IT_BIT                          RCANA.IMR.BIT.IMR4
#define INTDRV_vbCAN_A_RESET_HALT_CAN_IT_BIT                         RCANA.IMR.BIT.IMR0
#define INTDRV_vbCAN_A_OVR_FRAME_TX_IT_BIT                           RCANA.IMR.BIT.IMR7
#define INTDRV_vbCAN_A_UNREAD_MSG_OVW_IT_BIT                         RCANA.IMR.BIT.IMR9
#define INTDRV_vbCAN_A_START_NEW_SYS_MATRIX_IT_BIT                   RCANA.IMR.BIT.IMR10
#define INTDRV_vbCAN_A_TMR_2_CM_IT_BIT                               RCANA.IMR.BIT.IMR11
#define INTDRV_vbCAN_A_BUS_ACTIVE_IN_SLEEP_MODE_IT_BIT               RCANA.IMR.BIT.IMR12
#define INTDRV_vbCAN_A_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_IT_BIT RCANA.IMR.BIT.IMR13
#define INTDRV_vbCAN_A_TMR_0_CM_LOCAL_IT_BIT                         RCANA.IMR.BIT.IMR14
#define INTDRV_vbCAN_A_TMR_1_CM_CYCLE_IT_BIT                         RCANA.IMR.BIT.IMR15
#define INTDRV_vbCAN_A_DATA_FRAME_RECV_IT_BIT                        RCANA.IMR.BIT.IMR1
#define INTDRV_vbCAN_A_RM_FRAME_RECV_IT_BIT                          RCANA.IMR.BIT.IMR2
#define INTDRV_vbCAN_A_MSG_TRANS_IT_BIT                              RCANA.IMR.BIT.IMR8
#define INTDRV_vbCAN_B_ER_MODE_ER_IT_BIT                             RCANB.IMR.BIT.IMR5
#define INTDRV_vbCAN_B_BUS_OFF_RECOVER_IT_BIT                        RCANB.IMR.BIT.IMR6
#define INTDRV_vbCAN_B_TX_WARNING_ER_IT_BIT                          RCANB.IMR.BIT.IMR3
#define INTDRV_vbCAN_B_RX_WARNING_ER_IT_BIT                          RCANB.IMR.BIT.IMR4
#define INTDRV_vbCAN_B_RESET_HALT_CAN_IT_BIT                         RCANB.IMR.BIT.IMR0
#define INTDRV_vbCAN_B_OVR_FRAME_TX_IT_BIT                           RCANB.IMR.BIT.IMR7
#define INTDRV_vbCAN_B_UNREAD_MSG_OVW_IT_BIT                         RCANB.IMR.BIT.IMR9
#define INTDRV_vbCAN_B_START_NEW_SYS_MATRIX_IT_BIT                   RCANB.IMR.BIT.IMR10
#define INTDRV_vbCAN_B_TMR_2_CM_IT_BIT                               RCANB.IMR.BIT.IMR11
#define INTDRV_vbCAN_B_BUS_ACTIVE_IN_SLEEP_MODE_IT_BIT               RCANB.IMR.BIT.IMR12
#define INTDRV_vbCAN_B_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_IT_BIT RCANB.IMR.BIT.IMR13
#define INTDRV_vbCAN_B_TMR_0_CM_LOCAL_IT_BIT                         RCANB.IMR.BIT.IMR14
#define INTDRV_vbCAN_B_TMR_1_CM_CYCLE_IT_BIT                         RCANB.IMR.BIT.IMR15
#define INTDRV_vbCAN_B_DATA_FRAME_RECV_IT_BIT                        RCANB.IMR.BIT.IMR1
#define INTDRV_vbCAN_B_RM_FRAME_RECV_IT_BIT                          RCANB.IMR.BIT.IMR2
#define INTDRV_vbCAN_B_MSG_TRANS_IT_BIT                              RCANB.IMR.BIT.IMR8
#define INTDRV_vbCAN_C_ER_MODE_ER_IT_BIT                             RCANC.IMR.BIT.IMR5
#define INTDRV_vbCAN_C_BUS_OFF_RECOVER_IT_BIT                        RCANC.IMR.BIT.IMR6
#define INTDRV_vbCAN_C_TX_WARNING_ER_IT_BIT                          RCANC.IMR.BIT.IMR3
#define INTDRV_vbCAN_C_RX_WARNING_ER_IT_BIT                          RCANC.IMR.BIT.IMR4
#define INTDRV_vbCAN_C_RESET_HALT_CAN_IT_BIT                         RCANC.IMR.BIT.IMR0
#define INTDRV_vbCAN_C_OVR_FRAME_TX_IT_BIT                           RCANC.IMR.BIT.IMR7
#define INTDRV_vbCAN_C_UNREAD_MSG_OVW_IT_BIT                         RCANC.IMR.BIT.IMR9
#define INTDRV_vbCAN_C_START_NEW_SYS_MATRIX_IT_BIT                   RCANC.IMR.BIT.IMR10
#define INTDRV_vbCAN_C_TMR_2_CM_IT_BIT                               RCANC.IMR.BIT.IMR11
#define INTDRV_vbCAN_C_BUS_ACTIVE_IN_SLEEP_MODE_IT_BIT               RCANC.IMR.BIT.IMR12
#define INTDRV_vbCAN_C_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_IT_BIT RCANC.IMR.BIT.IMR13
#define INTDRV_vbCAN_C_TMR_0_CM_LOCAL_IT_BIT                         RCANC.IMR.BIT.IMR14
#define INTDRV_vbCAN_C_TMR_1_CM_CYCLE_IT_BIT                         RCANC.IMR.BIT.IMR15
#define INTDRV_vbCAN_C_DATA_FRAME_RECV_IT_BIT                        RCANC.IMR.BIT.IMR1
#define INTDRV_vbCAN_C_RM_FRAME_RECV_IT_BIT                          RCANC.IMR.BIT.IMR2
#define INTDRV_vbCAN_C_MSG_TRANS_IT_BIT                              RCANC.IMR.BIT.IMR8

/**********************************************************************************************************************/
/* !Comment : ADMA Interrupts Enable bits                                                                             */
/**********************************************************************************************************************/
#define INTDRV_vbADMA_2_IT_BIT  ADMAC.ADMAIE0.BIT.Channel2
#define INTDRV_vbADMA_3_IT_BIT  ADMAC.ADMAIE0.BIT.Channel3
#define INTDRV_vbADMA_4_IT_BIT  ADMAC.ADMAIE0.BIT.Channel4
#define INTDRV_vbADMA_5_IT_BIT  ADMAC.ADMAIE0.BIT.Channel5
#define INTDRV_vbADMA_6_IT_BIT  ADMAC.ADMAIE0.BIT.Channel6
#define INTDRV_vbADMA_7_IT_BIT  ADMAC.ADMAIE0.BIT.Channel7
#define INTDRV_vbADMA_8_IT_BIT  ADMAC.ADMAIE1.BIT.Channel8
#define INTDRV_vbADMA_9_IT_BIT  ADMAC.ADMAIE1.BIT.Channel9
#define INTDRV_vbADMA_10_IT_BIT ADMAC.ADMAIE1.BIT.Channel10
#define INTDRV_vbADMA_11_IT_BIT ADMAC.ADMAIE1.BIT.Channel11
#define INTDRV_vbADMA_12_IT_BIT ADMAC.ADMAIE1.BIT.Channel12
#define INTDRV_vbADMA_13_IT_BIT ADMAC.ADMAIE1.BIT.Channel13
#define INTDRV_vbADMA_14_IT_BIT ADMAC.ADMAIE1.BIT.Channel14
#define INTDRV_vbADMA_15_IT_BIT ADMAC.ADMAIE1.BIT.Channel15
#define INTDRV_vbADMA_16_IT_BIT ADMAC.ADMAIE2.BIT.Channel16
#define INTDRV_vbADMA_17_IT_BIT ADMAC.ADMAIE2.BIT.Channel17
#define INTDRV_vbADMA_18_IT_BIT ADMAC.ADMAIE2.BIT.Channel18
#define INTDRV_vbADMA_19_IT_BIT ADMAC.ADMAIE2.BIT.Channel19
#define INTDRV_vbADMA_20_IT_BIT ADMAC.ADMAIE2.BIT.Channel20
#define INTDRV_vbADMA_21_IT_BIT ADMAC.ADMAIE2.BIT.Channel21
#define INTDRV_vbADMA_22_IT_BIT ADMAC.ADMAIE2.BIT.Channel22
#define INTDRV_vbADMA_23_IT_BIT ADMAC.ADMAIE2.BIT.Channel23
#define INTDRV_vbADMA_24_IT_BIT ADMAC.ADMAIE3.BIT.Channel24
#define INTDRV_vbADMA_25_IT_BIT ADMAC.ADMAIE3.BIT.Channel25
#define INTDRV_vbADMA_26_IT_BIT ADMAC.ADMAIE3.BIT.Channel26
#define INTDRV_vbADMA_27_IT_BIT ADMAC.ADMAIE3.BIT.Channel27
#define INTDRV_vbADMA_28_IT_BIT ADMAC.ADMAIE3.BIT.Channel28
#define INTDRV_vbADMA_29_IT_BIT ADMAC.ADMAIE3.BIT.Channel29
#define INTDRV_vbADMA_30_IT_BIT ADMAC.ADMAIE3.BIT.Channel30
#define INTDRV_vbADMA_31_IT_BIT ADMAC.ADMAIE3.BIT.Channel31
#define INTDRV_vbADMA_32_IT_BIT ADMAC.ADMAIE4.BIT.Channel32
#define INTDRV_vbADMA_33_IT_BIT ADMAC.ADMAIE4.BIT.Channel33
#define INTDRV_vbADMA_34_IT_BIT ADMAC.ADMAIE4.BIT.Channel34
#define INTDRV_vbADMA_35_IT_BIT ADMAC.ADMAIE4.BIT.Channel35
#define INTDRV_vbADMA_36_IT_BIT ADMAC.ADMAIE4.BIT.Channel36
#define INTDRV_vbADMA_37_IT_BIT ADMAC.ADMAIE4.BIT.Channel37
#define INTDRV_vbADMA_38_IT_BIT ADMAC.ADMAIE4.BIT.Channel38
#define INTDRV_vbADMA_39_IT_BIT ADMAC.ADMAIE4.BIT.Channel39
#define INTDRV_vbADMA_40_IT_BIT ADMAC.ADMAIE5.BIT.Channel40
#define INTDRV_vbADMA_41_IT_BIT ADMAC.ADMAIE5.BIT.Channel41
#define INTDRV_vbADMA_42_IT_BIT ADMAC.ADMAIE5.BIT.Channel42
#define INTDRV_vbADMA_43_IT_BIT ADMAC.ADMAIE5.BIT.Channel43
#define INTDRV_vbADMA_44_IT_BIT ADMAC.ADMAIE5.BIT.Channel44
#define INTDRV_vbADMA_45_IT_BIT ADMAC.ADMAIE5.BIT.Channel45
#define INTDRV_vbADMA_46_IT_BIT ADMAC.ADMAIE5.BIT.Channel46
#define INTDRV_vbADMA_47_IT_BIT ADMAC.ADMAIE5.BIT.Channel47
#define INTDRV_vbADMA_56_IT_BIT ADMAC.ADMAIE7.BIT.Channel56
#define INTDRV_vbADMA_57_IT_BIT ADMAC.ADMAIE7.BIT.Channel57
#define INTDRV_vbADMA_58_IT_BIT ADMAC.ADMAIE7.BIT.Channel58
#define INTDRV_vbADMA_59_IT_BIT ADMAC.ADMAIE7.BIT.Channel59
#define INTDRV_vbADMA_60_IT_BIT ADMAC.ADMAIE7.BIT.Channel60
#define INTDRV_vbADMA_61_IT_BIT ADMAC.ADMAIE7.BIT.Channel61
#define INTDRV_vbADMA_62_IT_BIT ADMAC.ADMAIE7.BIT.Channel62
#define INTDRV_vbADMA_63_IT_BIT ADMAC.ADMAIE7.BIT.Channel63
#define INTDRV_vbADMA_64_IT_BIT ADMAC.ADMAIE8.BIT.Channel64
#define INTDRV_vbADMA_65_IT_BIT ADMAC.ADMAIE8.BIT.Channel65
#define INTDRV_vbADMA_66_IT_BIT ADMAC.ADMAIE8.BIT.Channel66
#define INTDRV_vbADMA_67_IT_BIT ADMAC.ADMAIE8.BIT.Channel67
#define INTDRV_vbADMA_68_IT_BIT ADMAC.ADMAIE8.BIT.Channel68
#define INTDRV_vbADMA_69_IT_BIT ADMAC.ADMAIE8.BIT.Channel69
#define INTDRV_vbADMA_70_IT_BIT ADMAC.ADMAIE8.BIT.Channel70
#define INTDRV_vbADMA_71_IT_BIT ADMAC.ADMAIE8.BIT.Channel71
#define INTDRV_vbADMA_74_IT_BIT ADMAC.ADMAIE9.BIT.Channel74

/**********************************************************************************************************************/
/* !Comment : Interrupts Flag bits                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* !Comment : IRQ Interrupts Flag bits                                                                                */
/**********************************************************************************************************************/
#define INTDRV_vbIRQ_0_IT_FLAG INTC.IRQRR.BIT.IRQ0F
#define INTDRV_vbIRQ_1_IT_FLAG INTC.IRQRR.BIT.IRQ1F
#define INTDRV_vbIRQ_2_IT_FLAG INTC.IRQRR.BIT.IRQ2F
#define INTDRV_vbIRQ_3_IT_FLAG INTC.IRQRR.BIT.IRQ3F
#define INTDRV_vbIRQ_4_IT_FLAG INTC.IRQRR.BIT.IRQ4F
#define INTDRV_vbIRQ_5_IT_FLAG INTC.IRQRR.BIT.IRQ5F
#define INTDRV_vbIRQ_6_IT_FLAG INTC.IRQRR.BIT.IRQ6F
#define INTDRV_vbIRQ_7_IT_FLAG INTC.IRQRR.BIT.IRQ7F

/**********************************************************************************************************************/
/* !Comment : RAM & ROM Interrupts Flag bits                                                                          */
/**********************************************************************************************************************/
#define INTDRV_vbRAM_PARITY_ER_IT_FLAG        RAM.RAMERR.BIT.RPARI
#define INTDRV_vbRAM_DETECT_2BITS_ER_IT_FLAG  RAM.RAMERR.BIT.RDTCT
#define INTDRV_vbRAM_CORRECT_1BIT_ER_IT_FLAG  RAM.RAMERR.BIT.RCRCT
#define INTDRV_vbROM_ACCESS_ER_IT_FLAG        ROM.FASTAT.BIT.ROMAE
#define INTDRV_vbFCU_CMD_LOCK_IT_FLAG         ROM.FASTAT.BIT.CMDLK
#define INTDRV_vbEEPROM_ACCESS_ER_IT_FLAG     ROM.FASTAT.BIT.EEPAE
#define INTDRV_vbEEPROM_INST_FETCH_ER_IT_FLAG ROM.FASTAT.BIT.EEPIFE
#define INTDRV_vbEEPROM_RD_PTCT_ER_IT_FLAG    ROM.FASTAT.BIT.EEPRPE
#define INTDRV_vbEEPROM_WR_PTCT_ER_IT_FLAG    ROM.FASTAT.BIT.EEPWPE

/**********************************************************************************************************************/
/* !Comment : SINT Interrupts Flag bits                                                                               */
/**********************************************************************************************************************/
#define INTDRV_vbSINT1_IT_FLAG   INTC.SINTR1.BIT.SINTC
#define INTDRV_vbSINT2_IT_FLAG   INTC.SINTR2.BIT.SINTC
#define INTDRV_vbSINT3_IT_FLAG   INTC.SINTR3.BIT.SINTC
#define INTDRV_vbSINT4_IT_FLAG   INTC.SINTR4.BIT.SINTC
#define INTDRV_vbSINT5_IT_FLAG   INTC.SINTR5.BIT.SINTC
#define INTDRV_vbSINT6_IT_FLAG   INTC.SINTR6.BIT.SINTC
#define INTDRV_vbSINT7_IT_FLAG   INTC.SINTR7.BIT.SINTC
#define INTDRV_vbSINT8_IT_FLAG   INTC.SINTR8.BIT.SINTC
#define INTDRV_vbSINT9_IT_FLAG   INTC.SINTR9.BIT.SINTC
#define INTDRV_vbSINT10_IT_FLAG  INTC.SINTR10.BIT.SINTC
#define INTDRV_vbSINT11_IT_FLAG  INTC.SINTR11.BIT.SINTC
#define INTDRV_vbSINT12_IT_FLAG  INTC.SINTR12.BIT.SINTC
#define INTDRV_vbSINT13_IT_FLAG  INTC.SINTR13.BIT.SINTC
#define INTDRV_vbSINT14_IT_FLAG  INTC.SINTR14.BIT.SINTC
#define INTDRV_vbSINT15_IT_FLAG  INTC.SINTR15.BIT.SINTC

/**********************************************************************************************************************/
/* !Comment : DMA Interrupts Flag bits                                                                                */
/**********************************************************************************************************************/
#define INTDRV_vbDMA_0_0_DEI_IT_FLAG DMAC0.CHFR.BIT.TE
#define INTDRV_vbDMA_0_0_HEI_IT_FLAG DMAC0.CHFR.BIT.HE
#define INTDRV_vbDMA_0_1_DEI_IT_FLAG DMAC1.CHFR.BIT.TE
#define INTDRV_vbDMA_0_1_HEI_IT_FLAG DMAC1.CHFR.BIT.HE
#define INTDRV_vbDMA_0_2_DEI_IT_FLAG DMAC2.CHFR.BIT.TE
#define INTDRV_vbDMA_0_2_HEI_IT_FLAG DMAC2.CHFR.BIT.HE
#define INTDRV_vbDMA_0_3_DEI_IT_FLAG DMAC3.CHFR.BIT.TE
#define INTDRV_vbDMA_0_3_HEI_IT_FLAG DMAC3.CHFR.BIT.HE
#define INTDRV_vbDMA_0_4_DEI_IT_FLAG DMAC4.CHFR.BIT.TE
#define INTDRV_vbDMA_0_4_HEI_IT_FLAG DMAC4.CHFR.BIT.HE
#define INTDRV_vbDMA_0_5_DEI_IT_FLAG DMAC5.CHFR.BIT.TE
#define INTDRV_vbDMA_0_5_HEI_IT_FLAG DMAC5.CHFR.BIT.HE
#define INTDRV_vbDMA_0_6_DEI_IT_FLAG DMAC6.CHFR.BIT.TE
#define INTDRV_vbDMA_0_6_HEI_IT_FLAG DMAC6.CHFR.BIT.HE
#define INTDRV_vbDMA_0_7_DEI_IT_FLAG DMAC7.CHFR.BIT.TE
#define INTDRV_vbDMA_0_7_HEI_IT_FLAG DMAC7.CHFR.BIT.HE

/**********************************************************************************************************************/
/* !Comment : CMT Interrupts Flag bits                                                                                */
/**********************************************************************************************************************/
#define INTDRV_vbCMT_0_0_CM_IT_FLAG CMT.Channel[0].CMSR.BIT.CMF
#define INTDRV_vbCMT_1_0_CM_IT_FLAG CMT.Channel[1].CMSR.BIT.CMF

/**********************************************************************************************************************/
/* !Comment : WDT Interrupts Flag bits                                                                                */
/**********************************************************************************************************************/
#define INTDRV_vbWDT_IT_IT_FLAG WDT.WTSR.BIT.IOVF

/**********************************************************************************************************************/
/* !Comment : TMR_A Interrupts Flag bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_A0_0_IC_IT_FLAG ATUA.TSRA.BIT.ICFA0
#define INTDRV_vbTMR_A0_1_IC_IT_FLAG ATUA.TSRA.BIT.ICFA1
#define INTDRV_vbTMR_A0_2_IC_IT_FLAG ATUA.TSRA.BIT.ICFA2
#define INTDRV_vbTMR_A0_3_IC_IT_FLAG ATUA.TSRA.BIT.ICFA3
#define INTDRV_vbTMR_A0_4_IC_IT_FLAG ATUA.TSRA.BIT.ICFA4
#define INTDRV_vbTMR_A0_5_IC_IT_FLAG ATUA.TSRA.BIT.ICFA5
#define INTDRV_vbTMR_A0_0_OV_IT_FLAG ATUA.TSRA.BIT.OVFA

/**********************************************************************************************************************/
/* !Comment : TMR_B Interrupts Flag bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_B0_0_CM_IT_FLAG ATUB.TSRB.BIT.CMFB0
#define INTDRV_vbTMR_B0_1_CM_IT_FLAG ATUB.TSRB.BIT.CMFB1
#define INTDRV_vbTMR_B0_6_CM_IT_FLAG ATUB.TSRB.BIT.CMFB6
#define INTDRV_vbTMR_B0_0_IC_IT_FLAG ATUB.TSRB.BIT.ICFB0

/**********************************************************************************************************************/
/* !Comment : TMR_C Interrupts Flag bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_C0_0_IC_CM_IT_FLAG ATUC.SUBBLOCK[0].TSRC.BIT.IMFC0
#define INTDRV_vbTMR_C0_1_IC_CM_IT_FLAG ATUC.SUBBLOCK[0].TSRC.BIT.IMFC1
#define INTDRV_vbTMR_C0_2_IC_CM_IT_FLAG ATUC.SUBBLOCK[0].TSRC.BIT.IMFC2
#define INTDRV_vbTMR_C0_3_IC_CM_IT_FLAG ATUC.SUBBLOCK[0].TSRC.BIT.IMFC3
#define INTDRV_vbTMR_C0_0_OV_IT_FLAG    ATUC.SUBBLOCK[0].TSRC.BIT.OVFC
#define INTDRV_vbTMR_C1_0_IC_CM_IT_FLAG ATUC.SUBBLOCK[1].TSRC.BIT.IMFC0
#define INTDRV_vbTMR_C1_1_IC_CM_IT_FLAG ATUC.SUBBLOCK[1].TSRC.BIT.IMFC1
#define INTDRV_vbTMR_C1_2_IC_CM_IT_FLAG ATUC.SUBBLOCK[1].TSRC.BIT.IMFC2
#define INTDRV_vbTMR_C1_3_IC_CM_IT_FLAG ATUC.SUBBLOCK[1].TSRC.BIT.IMFC3
#define INTDRV_vbTMR_C1_0_OV_IT_FLAG    ATUC.SUBBLOCK[1].TSRC.BIT.OVFC
#define INTDRV_vbTMR_C2_0_IC_CM_IT_FLAG ATUC.SUBBLOCK[2].TSRC.BIT.IMFC0
#define INTDRV_vbTMR_C2_1_IC_CM_IT_FLAG ATUC.SUBBLOCK[2].TSRC.BIT.IMFC1
#define INTDRV_vbTMR_C2_2_IC_CM_IT_FLAG ATUC.SUBBLOCK[2].TSRC.BIT.IMFC2
#define INTDRV_vbTMR_C2_3_IC_CM_IT_FLAG ATUC.SUBBLOCK[2].TSRC.BIT.IMFC3
#define INTDRV_vbTMR_C2_0_OV_IT_FLAG    ATUC.SUBBLOCK[2].TSRC.BIT.OVFC
#define INTDRV_vbTMR_C3_0_IC_CM_IT_FLAG ATUC.SUBBLOCK[3].TSRC.BIT.IMFC0
#define INTDRV_vbTMR_C3_1_IC_CM_IT_FLAG ATUC.SUBBLOCK[3].TSRC.BIT.IMFC1
#define INTDRV_vbTMR_C3_2_IC_CM_IT_FLAG ATUC.SUBBLOCK[3].TSRC.BIT.IMFC2
#define INTDRV_vbTMR_C3_3_IC_CM_IT_FLAG ATUC.SUBBLOCK[3].TSRC.BIT.IMFC3
#define INTDRV_vbTMR_C3_0_OV_IT_FLAG    ATUC.SUBBLOCK[3].TSRC.BIT.OVFC
#define INTDRV_vbTMR_C4_0_IC_CM_IT_FLAG ATUC.SUBBLOCK[4].TSRC.BIT.IMFC0
#define INTDRV_vbTMR_C4_1_IC_CM_IT_FLAG ATUC.SUBBLOCK[4].TSRC.BIT.IMFC1
#define INTDRV_vbTMR_C4_2_IC_CM_IT_FLAG ATUC.SUBBLOCK[4].TSRC.BIT.IMFC2
#define INTDRV_vbTMR_C4_3_IC_CM_IT_FLAG ATUC.SUBBLOCK[4].TSRC.BIT.IMFC3
#define INTDRV_vbTMR_C4_0_OV_IT_FLAG    ATUC.SUBBLOCK[4].TSRC.BIT.OVFC

/**********************************************************************************************************************/
/* !Comment : TMR_D Interrupts Flag bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_1D0_0_CM_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.CMFAD0
#define INTDRV_vbTMR_2D0_0_CM_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.CMFBD0
#define INTDRV_vbTMR_1D0_1_CM_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.CMFAD1
#define INTDRV_vbTMR_2D0_1_CM_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.CMFBD1
#define INTDRV_vbTMR_1D0_2_CM_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.CMFAD2
#define INTDRV_vbTMR_2D0_2_CM_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.CMFBD2
#define INTDRV_vbTMR_1D0_3_CM_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.CMFAD3
#define INTDRV_vbTMR_2D0_3_CM_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.CMFBD3
#define INTDRV_vbTMR_1D0_OV_IT_FLAG   ATUD.SUBBLOCKB[0].TSRD.BIT.OVF1D
#define INTDRV_vbTMR_2D0_OV_IT_FLAG   ATUD.SUBBLOCKB[0].TSRD.BIT.OVF2D
#define INTDRV_vbTMR_DD0_0_UF_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.UDFD0
#define INTDRV_vbTMR_DD0_1_UF_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.UDFD1
#define INTDRV_vbTMR_DD0_2_UF_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.UDFD2
#define INTDRV_vbTMR_DD0_3_UF_IT_FLAG ATUD.SUBBLOCKB[0].TSRD.BIT.UDFD3
#define INTDRV_vbTMR_1D1_0_CM_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.CMFAD0
#define INTDRV_vbTMR_2D1_0_CM_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.CMFBD0
#define INTDRV_vbTMR_1D1_1_CM_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.CMFAD1
#define INTDRV_vbTMR_2D1_1_CM_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.CMFBD1
#define INTDRV_vbTMR_1D1_2_CM_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.CMFAD2
#define INTDRV_vbTMR_2D1_2_CM_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.CMFBD2
#define INTDRV_vbTMR_1D1_3_CM_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.CMFAD3
#define INTDRV_vbTMR_2D1_3_CM_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.CMFBD3
#define INTDRV_vbTMR_1D1_OV_IT_FLAG   ATUD.SUBBLOCKB[1].TSRD.BIT.OVF1D
#define INTDRV_vbTMR_2D1_OV_IT_FLAG   ATUD.SUBBLOCKB[1].TSRD.BIT.OVF2D
#define INTDRV_vbTMR_DD1_0_UF_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.UDFD0
#define INTDRV_vbTMR_DD1_1_UF_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.UDFD1
#define INTDRV_vbTMR_DD1_2_UF_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.UDFD2
#define INTDRV_vbTMR_DD1_3_UF_IT_FLAG ATUD.SUBBLOCKB[1].TSRD.BIT.UDFD3
#define INTDRV_vbTMR_1D2_0_CM_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.CMFAD0
#define INTDRV_vbTMR_2D2_0_CM_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.CMFBD0
#define INTDRV_vbTMR_1D2_1_CM_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.CMFAD1
#define INTDRV_vbTMR_2D2_1_CM_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.CMFBD1
#define INTDRV_vbTMR_1D2_2_CM_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.CMFAD2
#define INTDRV_vbTMR_2D2_2_CM_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.CMFBD2
#define INTDRV_vbTMR_1D2_3_CM_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.CMFAD3
#define INTDRV_vbTMR_2D2_3_CM_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.CMFBD3
#define INTDRV_vbTMR_1D2_OV_IT_FLAG   ATUD.SUBBLOCKB[2].TSRD.BIT.OVF1D
#define INTDRV_vbTMR_2D2_OV_IT_FLAG   ATUD.SUBBLOCKB[2].TSRD.BIT.OVF2D
#define INTDRV_vbTMR_DD2_0_UF_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.UDFD0
#define INTDRV_vbTMR_DD2_1_UF_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.UDFD1
#define INTDRV_vbTMR_DD2_2_UF_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.UDFD2
#define INTDRV_vbTMR_DD2_3_UF_IT_FLAG ATUD.SUBBLOCKB[2].TSRD.BIT.UDFD3
#define INTDRV_vbTMR_1D3_0_CM_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.CMFAD0
#define INTDRV_vbTMR_2D3_0_CM_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.CMFBD0
#define INTDRV_vbTMR_1D3_1_CM_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.CMFAD1
#define INTDRV_vbTMR_2D3_1_CM_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.CMFBD1
#define INTDRV_vbTMR_1D3_2_CM_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.CMFAD2
#define INTDRV_vbTMR_2D3_2_CM_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.CMFBD2
#define INTDRV_vbTMR_1D3_3_CM_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.CMFAD3
#define INTDRV_vbTMR_2D3_3_CM_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.CMFBD3
#define INTDRV_vbTMR_1D3_OV_IT_FLAG   ATUD.SUBBLOCKB[3].TSRD.BIT.OVF1D
#define INTDRV_vbTMR_2D3_OV_IT_FLAG   ATUD.SUBBLOCKB[3].TSRD.BIT.OVF2D
#define INTDRV_vbTMR_DD3_0_UF_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.UDFD0
#define INTDRV_vbTMR_DD3_1_UF_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.UDFD1
#define INTDRV_vbTMR_DD3_2_UF_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.UDFD2
#define INTDRV_vbTMR_DD3_3_UF_IT_FLAG ATUD.SUBBLOCKB[3].TSRD.BIT.UDFD3

/**********************************************************************************************************************/
/* !Comment : TMR_E Interrupts Flag bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_E0_0_CM_IT_FLAG ATUE.SUBBLOCK[0].TSRE.BIT.CMFE0
#define INTDRV_vbTMR_E0_1_CM_IT_FLAG ATUE.SUBBLOCK[0].TSRE.BIT.CMFE1
#define INTDRV_vbTMR_E0_2_CM_IT_FLAG ATUE.SUBBLOCK[0].TSRE.BIT.CMFE2
#define INTDRV_vbTMR_E0_3_CM_IT_FLAG ATUE.SUBBLOCK[0].TSRE.BIT.CMFE3
#define INTDRV_vbTMR_E1_0_CM_IT_FLAG ATUE.SUBBLOCK[1].TSRE.BIT.CMFE0
#define INTDRV_vbTMR_E1_1_CM_IT_FLAG ATUE.SUBBLOCK[1].TSRE.BIT.CMFE1
#define INTDRV_vbTMR_E1_2_CM_IT_FLAG ATUE.SUBBLOCK[1].TSRE.BIT.CMFE2
#define INTDRV_vbTMR_E1_3_CM_IT_FLAG ATUE.SUBBLOCK[1].TSRE.BIT.CMFE3
#define INTDRV_vbTMR_E2_0_CM_IT_FLAG ATUE.SUBBLOCK[2].TSRE.BIT.CMFE0
#define INTDRV_vbTMR_E2_1_CM_IT_FLAG ATUE.SUBBLOCK[2].TSRE.BIT.CMFE1
#define INTDRV_vbTMR_E2_2_CM_IT_FLAG ATUE.SUBBLOCK[2].TSRE.BIT.CMFE2
#define INTDRV_vbTMR_E2_3_CM_IT_FLAG ATUE.SUBBLOCK[2].TSRE.BIT.CMFE3
#define INTDRV_vbTMR_E3_0_CM_IT_FLAG ATUE.SUBBLOCK[3].TSRE.BIT.CMFE0
#define INTDRV_vbTMR_E3_1_CM_IT_FLAG ATUE.SUBBLOCK[3].TSRE.BIT.CMFE1
#define INTDRV_vbTMR_E3_2_CM_IT_FLAG ATUE.SUBBLOCK[3].TSRE.BIT.CMFE2
#define INTDRV_vbTMR_E3_3_CM_IT_FLAG ATUE.SUBBLOCK[3].TSRE.BIT.CMFE3
#define INTDRV_vbTMR_E4_0_CM_IT_FLAG ATUE.SUBBLOCK[4].TSRE.BIT.CMFE0
#define INTDRV_vbTMR_E4_1_CM_IT_FLAG ATUE.SUBBLOCK[4].TSRE.BIT.CMFE1
#define INTDRV_vbTMR_E4_2_CM_IT_FLAG ATUE.SUBBLOCK[4].TSRE.BIT.CMFE2
#define INTDRV_vbTMR_E4_3_CM_IT_FLAG ATUE.SUBBLOCK[4].TSRE.BIT.CMFE3
#define INTDRV_vbTMR_E5_0_CM_IT_FLAG ATUE.SUBBLOCK[5].TSRE.BIT.CMFE0
#define INTDRV_vbTMR_E5_1_CM_IT_FLAG ATUE.SUBBLOCK[5].TSRE.BIT.CMFE1
#define INTDRV_vbTMR_E5_2_CM_IT_FLAG ATUE.SUBBLOCK[5].TSRE.BIT.CMFE2
#define INTDRV_vbTMR_E5_3_CM_IT_FLAG ATUE.SUBBLOCK[5].TSRE.BIT.CMFE3

/**********************************************************************************************************************/
/* !Comment : TMR_F Interrupts Flag bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_F0_0_IC_IT_FLAG   ATUF.SUBBLOCK[0].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F1_0_IC_IT_FLAG   ATUF.SUBBLOCK[1].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F2_0_IC_IT_FLAG   ATUF.SUBBLOCK[2].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F3_0_IC_IT_FLAG   ATUF.SUBBLOCK[3].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F4_0_IC_IT_FLAG   ATUF.SUBBLOCK[4].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F5_0_IC_IT_FLAG   ATUF.SUBBLOCK[5].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F6_0_IC_IT_FLAG   ATUF.SUBBLOCK[6].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F7_0_IC_IT_FLAG   ATUF.SUBBLOCK[7].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F8_0_IC_IT_FLAG   ATUF.SUBBLOCK[8].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F9_0_IC_IT_FLAG   ATUF.SUBBLOCK[9].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F10_0_IC_IT_FLAG  ATUF.SUBBLOCK[10].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F11_0_IC_IT_FLAG  ATUF.SUBBLOCK[11].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F12_0_IC_IT_FLAG  ATUF.SUBBLOCK[12].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F13_0_IC_IT_FLAG  ATUF.SUBBLOCK[13].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F14_0_IC_IT_FLAG  ATUF.SUBBLOCK[14].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F15_0_IC_IT_FLAG  ATUF.SUBBLOCK[15].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F16_0_IC_IT_FLAG  ATUF.SUBBLOCK[16].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F17_0_IC_IT_FLAG  ATUF.SUBBLOCK[17].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F18_0_IC_IT_FLAG  ATUF.SUBBLOCK[18].TSRF.BIT.ICFF
#define INTDRV_vbTMR_F19_0_IC_IT_FLAG  ATUF.SUBBLOCK[19].TSRF.BIT.ICFF
#define INTDRV_vbTMR_AF0_0_OV_IT_FLAG  ATUF.SUBBLOCK[0].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF0_0_OV_IT_FLAG  ATUF.SUBBLOCK[0].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF0_0_OV_IT_FLAG  ATUF.SUBBLOCK[0].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF1_0_OV_IT_FLAG  ATUF.SUBBLOCK[1].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF1_0_OV_IT_FLAG  ATUF.SUBBLOCK[1].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF1_0_OV_IT_FLAG  ATUF.SUBBLOCK[1].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF2_0_OV_IT_FLAG  ATUF.SUBBLOCK[2].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF2_0_OV_IT_FLAG  ATUF.SUBBLOCK[2].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF2_0_OV_IT_FLAG  ATUF.SUBBLOCK[2].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF3_0_OV_IT_FLAG  ATUF.SUBBLOCK[3].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF3_0_OV_IT_FLAG  ATUF.SUBBLOCK[3].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF3_0_OV_IT_FLAG  ATUF.SUBBLOCK[3].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF4_0_OV_IT_FLAG  ATUF.SUBBLOCK[4].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF4_0_OV_IT_FLAG  ATUF.SUBBLOCK[4].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF4_0_OV_IT_FLAG  ATUF.SUBBLOCK[4].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF5_0_OV_IT_FLAG  ATUF.SUBBLOCK[5].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF5_0_OV_IT_FLAG  ATUF.SUBBLOCK[5].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF5_0_OV_IT_FLAG  ATUF.SUBBLOCK[5].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF6_0_OV_IT_FLAG  ATUF.SUBBLOCK[6].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF6_0_OV_IT_FLAG  ATUF.SUBBLOCK[6].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF6_0_OV_IT_FLAG  ATUF.SUBBLOCK[6].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF7_0_OV_IT_FLAG  ATUF.SUBBLOCK[7].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF7_0_OV_IT_FLAG  ATUF.SUBBLOCK[7].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF7_0_OV_IT_FLAG  ATUF.SUBBLOCK[7].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF8_0_OV_IT_FLAG  ATUF.SUBBLOCK[8].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF8_0_OV_IT_FLAG  ATUF.SUBBLOCK[8].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF8_0_OV_IT_FLAG  ATUF.SUBBLOCK[8].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF9_0_OV_IT_FLAG  ATUF.SUBBLOCK[9].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF9_0_OV_IT_FLAG  ATUF.SUBBLOCK[9].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF9_0_OV_IT_FLAG  ATUF.SUBBLOCK[9].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF10_0_OV_IT_FLAG ATUF.SUBBLOCK[10].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF10_0_OV_IT_FLAG ATUF.SUBBLOCK[10].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF10_0_OV_IT_FLAG ATUF.SUBBLOCK[10].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF11_0_OV_IT_FLAG ATUF.SUBBLOCK[11].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF11_0_OV_IT_FLAG ATUF.SUBBLOCK[11].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF11_0_OV_IT_FLAG ATUF.SUBBLOCK[11].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF12_0_OV_IT_FLAG ATUF.SUBBLOCK[12].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF12_0_OV_IT_FLAG ATUF.SUBBLOCK[12].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF12_0_OV_IT_FLAG ATUF.SUBBLOCK[12].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF13_0_OV_IT_FLAG ATUF.SUBBLOCK[13].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF13_0_OV_IT_FLAG ATUF.SUBBLOCK[13].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF13_0_OV_IT_FLAG ATUF.SUBBLOCK[13].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF14_0_OV_IT_FLAG ATUF.SUBBLOCK[14].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF14_0_OV_IT_FLAG ATUF.SUBBLOCK[14].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF14_0_OV_IT_FLAG ATUF.SUBBLOCK[14].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF15_0_OV_IT_FLAG ATUF.SUBBLOCK[15].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF15_0_OV_IT_FLAG ATUF.SUBBLOCK[15].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF15_0_OV_IT_FLAG ATUF.SUBBLOCK[15].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF16_0_OV_IT_FLAG ATUF.SUBBLOCK[16].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF16_0_OV_IT_FLAG ATUF.SUBBLOCK[16].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF16_0_OV_IT_FLAG ATUF.SUBBLOCK[16].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF17_0_OV_IT_FLAG ATUF.SUBBLOCK[17].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF17_0_OV_IT_FLAG ATUF.SUBBLOCK[17].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF17_0_OV_IT_FLAG ATUF.SUBBLOCK[17].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF18_0_OV_IT_FLAG ATUF.SUBBLOCK[18].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF18_0_OV_IT_FLAG ATUF.SUBBLOCK[18].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF18_0_OV_IT_FLAG ATUF.SUBBLOCK[18].TSRF.BIT.OVFCF
#define INTDRV_vbTMR_AF19_0_OV_IT_FLAG ATUF.SUBBLOCK[19].TSRF.BIT.OVFAF
#define INTDRV_vbTMR_BF19_0_OV_IT_FLAG ATUF.SUBBLOCK[19].TSRF.BIT.OVFBF
#define INTDRV_vbTMR_CF19_0_OV_IT_FLAG ATUF.SUBBLOCK[19].TSRF.BIT.OVFCF

/**********************************************************************************************************************/
/* !Comment : TMR_G Interrupts Flag bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_G0_0_CM_IT_FLAG ATUG.SUBBLOCK[0].TSRG.BIT.CMFG
#define INTDRV_vbTMR_G1_0_CM_IT_FLAG ATUG.SUBBLOCK[1].TSRG.BIT.CMFG
#define INTDRV_vbTMR_G2_0_CM_IT_FLAG ATUG.SUBBLOCK[2].TSRG.BIT.CMFG
#define INTDRV_vbTMR_G3_0_CM_IT_FLAG ATUG.SUBBLOCK[3].TSRG.BIT.CMFG
#define INTDRV_vbTMR_G4_0_CM_IT_FLAG ATUG.SUBBLOCK[4].TSRG.BIT.CMFG
#define INTDRV_vbTMR_G5_0_CM_IT_FLAG ATUG.SUBBLOCK[5].TSRG.BIT.CMFG

/**********************************************************************************************************************/
/* !Comment : TMR_H Interrupts Flag bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_H0_0_CM_IT_FLAG ATUH.TSRH.BIT.CMFH

/**********************************************************************************************************************/
/* !Comment : TMR_J Interrupts Flag bits                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vbTMR_J0_0_FIFO_FULL_IT_FLAG ATUJ.SUBBLOCK[0].TSRJ.BIT.FDFFJ
#define INTDRV_vbTMR_J1_0_FIFO_FULL_IT_FLAG ATUJ.SUBBLOCK[1].TSRJ.BIT.FDFFJ
#define INTDRV_vbTMR_J0_0_OV_IT_FLAG        ATUJ.SUBBLOCK[0].TSRJ.BIT.OVFJ
#define INTDRV_vbTMR_J1_0_OV_IT_FLAG        ATUJ.SUBBLOCK[1].TSRJ.BIT.OVFJ
#define INTDRV_vbTMR_J0_0_FIFO_OV_IT_FLAG   ATUJ.SUBBLOCK[0].TSRJ.BIT.FDOVFJ
#define INTDRV_vbTMR_J1_0_FIFO_OV_IT_FLAG   ATUJ.SUBBLOCK[1].TSRJ.BIT.FDOVFJ

/**********************************************************************************************************************/
/* !Comment : ADC Interrupts Flag bits                                                                                */
/**********************************************************************************************************************/
#define INTDRV_vbADCA_END_SCAN_CONV_IT_FLAG   ADCA.ADREF.BIT.ADF
#define INTDRV_vbADCB_END_SCAN_CONV_IT_FLAG   ADCB.ADREF.BIT.ADF
#define INTDRV_vbADCA_0_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF0
#define INTDRV_vbADCA_1_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF1
#define INTDRV_vbADCA_2_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF2
#define INTDRV_vbADCA_3_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF3
#define INTDRV_vbADCA_4_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF4
#define INTDRV_vbADCA_5_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF5
#define INTDRV_vbADCA_6_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF6
#define INTDRV_vbADCA_7_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF7
#define INTDRV_vbADCA_8_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF8
#define INTDRV_vbADCA_9_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF9
#define INTDRV_vbADCA_10_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF10
#define INTDRV_vbADCA_11_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF11
#define INTDRV_vbADCA_12_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF12
#define INTDRV_vbADCA_13_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF13
#define INTDRV_vbADCA_14_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF14
#define INTDRV_vbADCA_15_END_INTR_CONV_IT_FLAG ADCA.ADTRF.BIT.ADTF15
#define INTDRV_vbADCB_40_END_INTR_CONV_IT_FLAG ADCB.ADTRF.BIT.ADTF40
#define INTDRV_vbADCB_41_END_INTR_CONV_IT_FLAG ADCB.ADTRF.BIT.ADTF41
#define INTDRV_vbADCB_42_END_INTR_CONV_IT_FLAG ADCB.ADTRF.BIT.ADTF42
#define INTDRV_vbADCB_43_END_INTR_CONV_IT_FLAG ADCB.ADTRF.BIT.ADTF43
#define INTDRV_vbADCB_44_END_INTR_CONV_IT_FLAG ADCB.ADTRF.BIT.ADTF44
#define INTDRV_vbADCB_45_END_INTR_CONV_IT_FLAG ADCB.ADTRF.BIT.ADTF45
#define INTDRV_vbADCB_46_END_INTR_CONV_IT_FLAG ADCB.ADTRF.BIT.ADTF46
#define INTDRV_vbADCB_47_END_INTR_CONV_IT_FLAG ADCB.ADTRF.BIT.ADTF47

/**********************************************************************************************************************/
/* !Comment : SCI Interrupts Flag bits                                                                                */
/**********************************************************************************************************************/
#define INTDRV_vbSCI_A_OVR_ER_IT_FLAG    SCIA.SCSSR1.BIT.ORER
#define INTDRV_vbSCI_A_FRAM_ER_IT_FLAG   SCIA.SCSSR1.BIT.FER
#define INTDRV_vbSCI_A_PARITY_ER_IT_FLAG SCIA.SCSSR1.BIT.PER
#define INTDRV_vbSCI_A_RX_IT_FLAG        SCIA.SCSSR1.BIT.RDRF
#define INTDRV_vbSCI_A_TX_IT_FLAG        SCIA.SCSSR1.BIT.TDRE
#define INTDRV_vbSCI_A_TX_END_IT_FLAG    SCIA.SCSSR1.BIT.TEND
#define INTDRV_vbSCI_B_OVR_ER_IT_FLAG    SCIB.SCSSR1.BIT.ORER
#define INTDRV_vbSCI_B_FRAM_ER_IT_FLAG   SCIB.SCSSR1.BIT.FER
#define INTDRV_vbSCI_B_PARITY_ER_IT_FLAG SCIB.SCSSR1.BIT.PER
#define INTDRV_vbSCI_B_RX_IT_FLAG        SCIB.SCSSR1.BIT.RDRF
#define INTDRV_vbSCI_B_TX_IT_FLAG        SCIB.SCSSR1.BIT.TDRE
#define INTDRV_vbSCI_B_TX_END_IT_FLAG    SCIB.SCSSR1.BIT.TEND
#define INTDRV_vbSCI_C_OVR_ER_IT_FLAG    SCIC.SCSSR1.BIT.ORER
#define INTDRV_vbSCI_C_FRAM_ER_IT_FLAG   SCIC.SCSSR1.BIT.FER
#define INTDRV_vbSCI_C_PARITY_ER_IT_FLAG SCIC.SCSSR1.BIT.PER
#define INTDRV_vbSCI_C_RX_IT_FLAG        SCIC.SCSSR1.BIT.RDRF
#define INTDRV_vbSCI_C_TX_IT_FLAG        SCIC.SCSSR1.BIT.TDRE
#define INTDRV_vbSCI_C_TX_END_IT_FLAG    SCIC.SCSSR1.BIT.TEND
#define INTDRV_vbSCI_D_OVR_ER_IT_FLAG    SCID.SCSSR1.BIT.ORER
#define INTDRV_vbSCI_D_FRAM_ER_IT_FLAG   SCID.SCSSR1.BIT.FER
#define INTDRV_vbSCI_D_PARITY_ER_IT_FLAG SCID.SCSSR1.BIT.PER
#define INTDRV_vbSCI_D_RX_IT_FLAG        SCID.SCSSR1.BIT.RDRF
#define INTDRV_vbSCI_D_TX_IT_FLAG        SCID.SCSSR1.BIT.TDRE
#define INTDRV_vbSCI_D_TX_END_IT_FLAG    SCID.SCSSR1.BIT.TEND
#define INTDRV_vbSCI_E_OVR_ER_IT_FLAG    SCIE.SCSSR1.BIT.ORER
#define INTDRV_vbSCI_E_FRAM_ER_IT_FLAG   SCIE.SCSSR1.BIT.FER
#define INTDRV_vbSCI_E_PARITY_ER_IT_FLAG SCIE.SCSSR1.BIT.PER
#define INTDRV_vbSCI_E_RX_IT_FLAG        SCIE.SCSSR1.BIT.RDRF
#define INTDRV_vbSCI_E_TX_IT_FLAG        SCIE.SCSSR1.BIT.TDRE
#define INTDRV_vbSCI_E_TX_END_IT_FLAG    SCIE.SCSSR1.BIT.TEND

/**********************************************************************************************************************/
/* !Comment : SPI Interrupts Flag bits                                                                                */
/**********************************************************************************************************************/
#define INTDRV_vbRSPI_A_OVR_ER_IT_FLAG        RSPIA.SPSR.BIT.OVRF
#define INTDRV_vbRSPI_A_MODE_FAULT_ER_IT_FLAG RSPIA.SPSR.BIT.MODF
#define INTDRV_vbRSPI_A_ER_IT_FLAG            RSPIA.SPSR.BIT.MODF
#define INTDRV_vbRSPI_A_RX_IT_FLAG            RSPIA.SPSR.BIT.SPRF
#define INTDRV_vbRSPI_A_TX_IT_FLAG            RSPIA.SPSR.BIT.SPTEF
#define INTDRV_vbRSPI_B_OVR_ER_IT_FLAG        RSPIB.SPSR.BIT.OVRF
#define INTDRV_vbRSPI_B_MODE_FAULT_ER_IT_FLAG RSPIB.SPSR.BIT.MODF
#define INTDRV_vbRSPI_B_ER_IT_FLAG            RSPIB.SPSR.BIT.MODF
#define INTDRV_vbRSPI_B_RX_IT_FLAG            RSPIB.SPSR.BIT.SPRF
#define INTDRV_vbRSPI_B_TX_IT_FLAG            RSPIB.SPSR.BIT.SPTEF
#define INTDRV_vbRSPI_C_OVR_ER_IT_FLAG        RSPIC.SPSR.BIT.OVRF
#define INTDRV_vbRSPI_C_MODE_FAULT_ER_IT_FLAG RSPIC.SPSR.BIT.MODF
#define INTDRV_vbRSPI_C_ER_IT_FLAG            RSPIC.SPSR.BIT.MODF
#define INTDRV_vbRSPI_C_RX_IT_FLAG            RSPIC.SPSR.BIT.SPRF
#define INTDRV_vbRSPI_C_TX_IT_FLAG            RSPIC.SPSR.BIT.SPTEF

/**********************************************************************************************************************/
/* !Comment : CAN Interrupts Flag bits                                                                                */
/**********************************************************************************************************************/
#define INTDRV_vbCAN_A_ER_MODE_ER_IT_FLAG                             RCANA.IRR.BIT.IRR5
#define INTDRV_vbCAN_A_BUS_OFF_RECOVER_IT_FLAG                        RCANA.IRR.BIT.IRR6
#define INTDRV_vbCAN_A_TX_WARNING_ER_IT_FLAG                          RCANA.IRR.BIT.IRR3
#define INTDRV_vbCAN_A_RX_WARNING_ER_IT_FLAG                          RCANA.IRR.BIT.IRR4
#define INTDRV_vbCAN_A_RESET_HALT_CAN_IT_FLAG                         RCANA.IRR.BIT.IRR0
#define INTDRV_vbCAN_A_OVR_FRAME_TX_IT_FLAG                           RCANA.IRR.BIT.IRR7
#define INTDRV_vbCAN_A_UNREAD_MSG_OVW_IT_FLAG                         RCANA.IRR.BIT.IRR9
#define INTDRV_vbCAN_A_START_NEW_SYS_MATRIX_IT_FLAG                   RCANA.IRR.BIT.IRR10
#define INTDRV_vbCAN_A_TMR_2_CM_IT_FLAG                               RCANA.IRR.BIT.IRR11
#define INTDRV_vbCAN_A_BUS_ACTIVE_IN_SLEEP_MODE_IT_FLAG               RCANA.IRR.BIT.IRR12
#define INTDRV_vbCAN_A_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_IT_FLAG RCANA.IRR.BIT.IRR13
#define INTDRV_vbCAN_A_TMR_0_CM_LOCAL_IT_FLAG                         RCANA.IRR.BIT.IRR14
#define INTDRV_vbCAN_A_TMR_1_CM_CYCLE_IT_FLAG                         RCANA.IRR.BIT.IRR15
#define INTDRV_vbCAN_A_DATA_FRAME_RECV_IT_FLAG                        RCANA.IRR.BIT.IRR1
#define INTDRV_vbCAN_A_RM_FRAME_RECV_IT_FLAG                          RCANA.IRR.BIT.IRR2
#define INTDRV_vbCAN_A_MSG_TRANS_IT_FLAG                              RCANA.IRR.BIT.IRR8
#define INTDRV_vbCAN_B_ER_MODE_ER_IT_FLAG                             RCANB.IRR.BIT.IRR5
#define INTDRV_vbCAN_B_BUS_OFF_RECOVER_IT_FLAG                        RCANB.IRR.BIT.IRR6
#define INTDRV_vbCAN_B_TX_WARNING_ER_IT_FLAG                          RCANB.IRR.BIT.IRR3
#define INTDRV_vbCAN_B_RX_WARNING_ER_IT_FLAG                          RCANB.IRR.BIT.IRR4
#define INTDRV_vbCAN_B_RESET_HALT_CAN_IT_FLAG                         RCANB.IRR.BIT.IRR0
#define INTDRV_vbCAN_B_OVR_FRAME_TX_IT_FLAG                           RCANB.IRR.BIT.IRR7
#define INTDRV_vbCAN_B_UNREAD_MSG_OVW_IT_FLAG                         RCANB.IRR.BIT.IRR9
#define INTDRV_vbCAN_B_START_NEW_SYS_MATRIX_IT_FLAG                   RCANB.IRR.BIT.IRR10
#define INTDRV_vbCAN_B_TMR_2_CM_IT_FLAG                               RCANB.IRR.BIT.IRR11
#define INTDRV_vbCAN_B_BUS_ACTIVE_IN_SLEEP_MODE_IT_FLAG               RCANB.IRR.BIT.IRR12
#define INTDRV_vbCAN_B_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_IT_FLAG RCANB.IRR.BIT.IRR13
#define INTDRV_vbCAN_B_TMR_0_CM_LOCAL_IT_FLAG                         RCANB.IRR.BIT.IRR14
#define INTDRV_vbCAN_B_TMR_1_CM_CYCLE_IT_FLAG                         RCANB.IRR.BIT.IRR15
#define INTDRV_vbCAN_B_DATA_FRAME_RECV_IT_FLAG                        RCANB.IRR.BIT.IRR1
#define INTDRV_vbCAN_B_RM_FRAME_RECV_IT_FLAG                          RCANB.IRR.BIT.IRR2
#define INTDRV_vbCAN_B_MSG_TRANS_IT_FLAG                              RCANB.IRR.BIT.IRR8
#define INTDRV_vbCAN_C_ER_MODE_ER_IT_FLAG                             RCANC.IRR.BIT.IRR5
#define INTDRV_vbCAN_C_BUS_OFF_RECOVER_IT_FLAG                        RCANC.IRR.BIT.IRR6
#define INTDRV_vbCAN_C_TX_WARNING_ER_IT_FLAG                          RCANC.IRR.BIT.IRR3
#define INTDRV_vbCAN_C_RX_WARNING_ER_IT_FLAG                          RCANC.IRR.BIT.IRR4
#define INTDRV_vbCAN_C_RESET_HALT_CAN_IT_FLAG                         RCANC.IRR.BIT.IRR0
#define INTDRV_vbCAN_C_OVR_FRAME_TX_IT_FLAG                           RCANC.IRR.BIT.IRR7
#define INTDRV_vbCAN_C_UNREAD_MSG_OVW_IT_FLAG                         RCANC.IRR.BIT.IRR9
#define INTDRV_vbCAN_C_START_NEW_SYS_MATRIX_IT_FLAG                   RCANC.IRR.BIT.IRR10
#define INTDRV_vbCAN_C_TMR_2_CM_IT_FLAG                               RCANC.IRR.BIT.IRR11
#define INTDRV_vbCAN_C_BUS_ACTIVE_IN_SLEEP_MODE_IT_FLAG               RCANC.IRR.BIT.IRR12
#define INTDRV_vbCAN_C_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_IT_FLAG RCANC.IRR.BIT.IRR13
#define INTDRV_vbCAN_C_TMR_0_CM_LOCAL_IT_FLAG                         RCANC.IRR.BIT.IRR14
#define INTDRV_vbCAN_C_TMR_1_CM_CYCLE_IT_FLAG                         RCANC.IRR.BIT.IRR15
#define INTDRV_vbCAN_C_DATA_FRAME_RECV_IT_FLAG                        RCANC.IRR.BIT.IRR1
#define INTDRV_vbCAN_C_RM_FRAME_RECV_IT_FLAG                          RCANC.IRR.BIT.IRR2
#define INTDRV_vbCAN_C_MSG_TRANS_IT_FLAG                              RCANC.IRR.BIT.IRR8

/**********************************************************************************************************************/
/* !Comment : ADMA Interrupts Flag bits                                                                               */
/**********************************************************************************************************************/
#define INTDRV_vbADMA_2_IT_FLAG ADMAC.ADMADV0.BIT.Channel2
#define INTDRV_vbADMA_3_IT_FLAG ADMAC.ADMADV0.BIT.Channel3
#define INTDRV_vbADMA_4_IT_FLAG ADMAC.ADMADV0.BIT.Channel4
#define INTDRV_vbADMA_5_IT_FLAG ADMAC.ADMADV0.BIT.Channel5
#define INTDRV_vbADMA_6_IT_FLAG ADMAC.ADMADV0.BIT.Channel6
#define INTDRV_vbADMA_7_IT_FLAG ADMAC.ADMADV0.BIT.Channel7
#define INTDRV_vbADMA_8_IT_FLAG ADMAC.ADMADV1.BIT.Channel8
#define INTDRV_vbADMA_9_IT_FLAG ADMAC.ADMADV1.BIT.Channel9
#define INTDRV_vbADMA_10_IT_FLAG ADMAC.ADMADV1.BIT.Channel10
#define INTDRV_vbADMA_11_IT_FLAG ADMAC.ADMADV1.BIT.Channel11
#define INTDRV_vbADMA_12_IT_FLAG ADMAC.ADMADV1.BIT.Channel12
#define INTDRV_vbADMA_13_IT_FLAG ADMAC.ADMADV1.BIT.Channel13
#define INTDRV_vbADMA_14_IT_FLAG ADMAC.ADMADV1.BIT.Channel14
#define INTDRV_vbADMA_15_IT_FLAG ADMAC.ADMADV1.BIT.Channel15
#define INTDRV_vbADMA_16_IT_FLAG ADMAC.ADMADV2.BIT.Channel16
#define INTDRV_vbADMA_17_IT_FLAG ADMAC.ADMADV2.BIT.Channel17
#define INTDRV_vbADMA_18_IT_FLAG ADMAC.ADMADV2.BIT.Channel18
#define INTDRV_vbADMA_19_IT_FLAG ADMAC.ADMADV2.BIT.Channel19
#define INTDRV_vbADMA_20_IT_FLAG ADMAC.ADMADV2.BIT.Channel20
#define INTDRV_vbADMA_21_IT_FLAG ADMAC.ADMADV2.BIT.Channel21
#define INTDRV_vbADMA_22_IT_FLAG ADMAC.ADMADV2.BIT.Channel22
#define INTDRV_vbADMA_23_IT_FLAG ADMAC.ADMADV2.BIT.Channel23
#define INTDRV_vbADMA_24_IT_FLAG ADMAC.ADMADV3.BIT.Channel24
#define INTDRV_vbADMA_25_IT_FLAG ADMAC.ADMADV3.BIT.Channel25
#define INTDRV_vbADMA_26_IT_FLAG ADMAC.ADMADV3.BIT.Channel26
#define INTDRV_vbADMA_27_IT_FLAG ADMAC.ADMADV3.BIT.Channel27
#define INTDRV_vbADMA_28_IT_FLAG ADMAC.ADMADV3.BIT.Channel28
#define INTDRV_vbADMA_29_IT_FLAG ADMAC.ADMADV3.BIT.Channel29
#define INTDRV_vbADMA_30_IT_FLAG ADMAC.ADMADV3.BIT.Channel30
#define INTDRV_vbADMA_31_IT_FLAG ADMAC.ADMADV3.BIT.Channel31
#define INTDRV_vbADMA_32_IT_FLAG ADMAC.ADMADV4.BIT.Channel32
#define INTDRV_vbADMA_33_IT_FLAG ADMAC.ADMADV4.BIT.Channel33
#define INTDRV_vbADMA_34_IT_FLAG ADMAC.ADMADV4.BIT.Channel34
#define INTDRV_vbADMA_35_IT_FLAG ADMAC.ADMADV4.BIT.Channel35
#define INTDRV_vbADMA_36_IT_FLAG ADMAC.ADMADV4.BIT.Channel36
#define INTDRV_vbADMA_37_IT_FLAG ADMAC.ADMADV4.BIT.Channel37
#define INTDRV_vbADMA_38_IT_FLAG ADMAC.ADMADV4.BIT.Channel38
#define INTDRV_vbADMA_39_IT_FLAG ADMAC.ADMADV4.BIT.Channel39
#define INTDRV_vbADMA_40_IT_FLAG ADMAC.ADMADV5.BIT.Channel40
#define INTDRV_vbADMA_41_IT_FLAG ADMAC.ADMADV5.BIT.Channel41
#define INTDRV_vbADMA_42_IT_FLAG ADMAC.ADMADV5.BIT.Channel42
#define INTDRV_vbADMA_43_IT_FLAG ADMAC.ADMADV5.BIT.Channel43
#define INTDRV_vbADMA_44_IT_FLAG ADMAC.ADMADV5.BIT.Channel44
#define INTDRV_vbADMA_45_IT_FLAG ADMAC.ADMADV5.BIT.Channel45
#define INTDRV_vbADMA_46_IT_FLAG ADMAC.ADMADV5.BIT.Channel46
#define INTDRV_vbADMA_47_IT_FLAG ADMAC.ADMADV5.BIT.Channel47
#define INTDRV_vbADMA_56_IT_FLAG ADMAC.ADMATE0.BIT.Channel56
#define INTDRV_vbADMA_57_IT_FLAG ADMAC.ADMATE0.BIT.Channel57
#define INTDRV_vbADMA_58_IT_FLAG ADMAC.ADMATE0.BIT.Channel58
#define INTDRV_vbADMA_59_IT_FLAG ADMAC.ADMATE0.BIT.Channel59
#define INTDRV_vbADMA_60_IT_FLAG ADMAC.ADMATE0.BIT.Channel60
#define INTDRV_vbADMA_61_IT_FLAG ADMAC.ADMATE0.BIT.Channel61
#define INTDRV_vbADMA_62_IT_FLAG ADMAC.ADMATE0.BIT.Channel62
#define INTDRV_vbADMA_63_IT_FLAG ADMAC.ADMATE0.BIT.Channel63
#define INTDRV_vbADMA_64_IT_FLAG ADMAC.ADMATE1.BIT.Channel64
#define INTDRV_vbADMA_65_IT_FLAG ADMAC.ADMATE1.BIT.Channel65
#define INTDRV_vbADMA_66_IT_FLAG ADMAC.ADMATE1.BIT.Channel66
#define INTDRV_vbADMA_67_IT_FLAG ADMAC.ADMATE1.BIT.Channel67
#define INTDRV_vbADMA_68_IT_FLAG ADMAC.ADMATE1.BIT.Channel68
#define INTDRV_vbADMA_69_IT_FLAG ADMAC.ADMATE1.BIT.Channel69
#define INTDRV_vbADMA_70_IT_FLAG ADMAC.ADMATE1.BIT.Channel70
#define INTDRV_vbADMA_71_IT_FLAG ADMAC.ADMATE1.BIT.Channel71
#define INTDRV_vbADMA_74_IT_FLAG ADMAC.ADMATE2.BIT.Channel74

/**********************************************************************************************************************/
/* !Comment : Flag Logical Type                                                                                       */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* !Comment : IRQ Flag Logical Type                                                                                   */
/**********************************************************************************************************************/
#define INTDRV_snIRQ_0_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snIRQ_1_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snIRQ_2_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snIRQ_3_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snIRQ_4_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snIRQ_5_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snIRQ_6_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snIRQ_7_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : SINT Logical Type                                                                                       */
/**********************************************************************************************************************/
#define INTDRV_snSINT1_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snSINT2_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snSINT3_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snSINT4_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snSINT5_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snSINT6_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snSINT7_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snSINT8_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snSINT9_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snSINT10_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snSINT11_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snSINT12_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snSINT13_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snSINT14_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snSINT15_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : RAM and ROM Flag Logical Type                                                                           */
/**********************************************************************************************************************/
#define INTDRV_snRAM_PARITY_ER_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snRAM_DETECT_2BITS_ER_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snRAM_CORRECT_1BIT_ER_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snROM_ACCESS_ER_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snFCU_CMD_LOCK_FLAG_W_LOGIC_TYP         REGULAR
#define INTDRV_snEEPROM_ACCESS_ER_FLAG_W_LOGIC_TYP     REGULAR
#define INTDRV_snEEPROM_INST_FETCH_ER_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snEEPROM_RD_PTCT_ER_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snEEPROM_WR_PTCT_ER_FLAG_W_LOGIC_TYP    REGULAR

/**********************************************************************************************************************/
/* !Comment : DMA Flag Logical Type                                                                                   */
/**********************************************************************************************************************/
#define INTDRV_snDMA_0_0_DEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_0_HEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_1_DEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_1_HEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_2_DEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_2_HEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_3_DEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_3_HEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_4_DEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_4_HEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_5_DEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_5_HEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_6_DEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_6_HEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_7_DEI_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snDMA_0_7_HEI_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : CMT Flag Logical Type                                                                                   */
/**********************************************************************************************************************/
#define INTDRV_snCMT_0_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snCMT_1_0_CM_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : WDT Flag Logical Type                                                                                   */
/**********************************************************************************************************************/
#define INTDRV_snWDT_IT_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : TMR_A Flag Logical Type                                                                                 */
/**********************************************************************************************************************/
#define INTDRV_snTMR_A0_0_IC_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_A0_1_IC_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_A0_2_IC_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_A0_3_IC_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_A0_4_IC_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_A0_5_IC_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_A0_0_OV_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : TMR_B Flag Logical Type                                                                                 */
/**********************************************************************************************************************/
#define INTDRV_snTMR_B0_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_B0_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_B0_6_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_B0_0_IC_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : TMR_C Flag Logical Type                                                                                 */
/**********************************************************************************************************************/
#define INTDRV_snTMR_C0_0_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C0_1_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C0_2_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C0_3_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C0_0_OV_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snTMR_C1_0_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C1_1_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C1_2_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C1_3_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C1_0_OV_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snTMR_C2_0_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C2_1_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C2_2_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C2_3_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C2_0_OV_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snTMR_C3_0_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C3_1_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C3_2_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C3_3_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C3_0_OV_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snTMR_C4_0_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C4_1_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C4_2_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C4_3_IC_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_C4_0_OV_FLAG_W_LOGIC_TYP    REGULAR

/**********************************************************************************************************************/
/* !Comment : TMR_D Flag Logical Type                                                                                 */
/**********************************************************************************************************************/
#define INTDRV_snTMR_1D0_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D0_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D0_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D0_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D0_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D0_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D0_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D0_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D0_OV_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_2D0_OV_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_DD0_0_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD0_1_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD0_2_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD0_3_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D1_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D1_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D1_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D1_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D1_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D1_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D1_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D1_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D1_OV_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_2D1_OV_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_DD1_0_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD1_1_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD1_2_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD1_3_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D2_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D2_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D2_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D2_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D2_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D2_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D2_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D2_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D2_OV_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_2D2_OV_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_DD2_0_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD2_1_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD2_2_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD2_3_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D3_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D3_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D3_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D3_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D3_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D3_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D3_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_2D3_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_1D3_OV_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_2D3_OV_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_DD3_0_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD3_1_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD3_2_UF_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_DD3_3_UF_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : TMR_E Flag Logical Type                                                                                 */
/**********************************************************************************************************************/
#define INTDRV_snTMR_E0_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E0_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E0_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E0_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E1_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E1_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E1_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E1_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E2_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E2_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E2_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E2_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E3_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E3_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E3_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E3_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E4_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E4_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E4_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E4_3_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E5_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E5_1_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E5_2_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_E5_3_CM_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : TMR_F Flag Logical Type                                                                                 */
/**********************************************************************************************************************/
#define INTDRV_snTMR_F0_0_IC_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_F1_0_IC_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_F2_0_IC_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_F3_0_IC_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_F4_0_IC_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_F5_0_IC_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_F6_0_IC_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_F7_0_IC_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_F8_0_IC_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_F9_0_IC_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_F10_0_IC_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_F11_0_IC_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_F12_0_IC_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_F13_0_IC_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_F14_0_IC_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_F15_0_IC_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_F16_0_IC_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_F17_0_IC_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_F18_0_IC_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_F19_0_IC_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_AF0_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_BF0_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_CF0_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_AF1_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_BF1_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_CF1_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_AF2_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_BF2_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_CF2_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_AF3_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_BF3_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_CF3_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_AF4_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_BF4_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_CF4_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_AF5_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_BF5_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_CF5_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_AF6_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_BF6_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_CF6_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_AF7_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_BF7_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_CF7_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_AF8_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_BF8_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_CF8_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_AF9_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_BF9_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_CF9_0_OV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snTMR_AF10_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_BF10_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_CF10_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_AF11_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_BF11_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_CF11_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_AF12_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_BF12_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_CF12_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_AF13_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_BF13_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_CF13_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_AF14_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_BF14_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_CF14_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_AF15_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_BF15_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_CF15_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_AF16_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_BF16_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_CF16_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_AF17_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_BF17_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_CF17_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_AF18_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_BF18_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_CF18_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_AF19_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_BF19_0_OV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_CF19_0_OV_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : TMR_G Flag Logical Type                                                                                 */
/**********************************************************************************************************************/
#define INTDRV_snTMR_G0_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_G1_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_G2_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_G3_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_G4_0_CM_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_G5_0_CM_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : TMR_H Flag Logical Type                                                                                 */
/**********************************************************************************************************************/
#define INTDRV_snTMR_H0_0_CM_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : TMR_J Flag Logical Type                                                                                 */
/**********************************************************************************************************************/
#define INTDRV_snTMR_J0_0_FIFO_FULL_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_J1_0_FIFO_FULL_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snTMR_J0_0_OV_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snTMR_J1_0_OV_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snTMR_J0_0_FIFO_OV_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snTMR_J1_0_FIFO_OV_FLAG_W_LOGIC_TYP   REGULAR

/**********************************************************************************************************************/
/* !Comment : ADC Flag Logical Type                                                                                   */
/**********************************************************************************************************************/
#define INTDRV_snADCA_END_SCAN_CONV_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snADCB_END_SCAN_CONV_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snADCA_0_END_INTR_CONV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADCA_1_END_INTR_CONV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADCA_2_END_INTR_CONV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADCA_3_END_INTR_CONV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADCA_4_END_INTR_CONV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADCA_5_END_INTR_CONV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADCA_6_END_INTR_CONV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADCA_7_END_INTR_CONV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADCA_8_END_INTR_CONV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADCA_9_END_INTR_CONV_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADCA_10_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCA_11_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCA_12_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCA_13_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCA_14_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCA_15_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCB_40_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCB_41_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCB_42_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCB_43_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCB_44_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCB_45_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCB_46_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADCB_47_END_INTR_CONV_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : SCI Flag Logical Type                                                                                   */
/**********************************************************************************************************************/
#define INTDRV_snSCI_A_OVR_ER_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snSCI_A_FRAM_ER_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snSCI_A_PARITY_ER_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snSCI_A_RX_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snSCI_A_TX_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snSCI_A_TX_END_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snSCI_B_OVR_ER_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snSCI_B_FRAM_ER_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snSCI_B_PARITY_ER_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snSCI_B_RX_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snSCI_B_TX_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snSCI_B_TX_END_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snSCI_C_OVR_ER_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snSCI_C_FRAM_ER_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snSCI_C_PARITY_ER_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snSCI_C_RX_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snSCI_C_TX_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snSCI_C_TX_END_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snSCI_D_OVR_ER_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snSCI_D_FRAM_ER_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snSCI_D_PARITY_ER_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snSCI_D_RX_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snSCI_D_TX_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snSCI_D_TX_END_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snSCI_E_OVR_ER_FLAG_W_LOGIC_TYP    REGULAR
#define INTDRV_snSCI_E_FRAM_ER_FLAG_W_LOGIC_TYP   REGULAR
#define INTDRV_snSCI_E_PARITY_ER_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snSCI_E_RX_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snSCI_E_TX_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snSCI_E_TX_END_FLAG_W_LOGIC_TYP    REGULAR

/**********************************************************************************************************************/
/* !Comment : SPI Flag Logical Type                                                                                   */
/**********************************************************************************************************************/
#define INTDRV_snRSPI_A_MODE_FAULT_ER_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snRSPI_A_OVR_ER_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snRSPI_A_RX_FLAG_W_LOGIC_TYP            REGULAR
#define INTDRV_snRSPI_A_TX_FLAG_W_LOGIC_TYP            REGULAR
#define INTDRV_snRSPI_A_ER_FLAG_W_LOGIC_TYP            REGULAR
#define INTDRV_snRSPI_B_MODE_FAULT_ER_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snRSPI_B_OVR_ER_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snRSPI_B_RX_FLAG_W_LOGIC_TYP            REGULAR
#define INTDRV_snRSPI_B_TX_FLAG_W_LOGIC_TYP            REGULAR
#define INTDRV_snRSPI_B_ER_FLAG_W_LOGIC_TYP            REGULAR
#define INTDRV_snRSPI_C_MODE_FAULT_ER_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snRSPI_C_OVR_ER_FLAG_W_LOGIC_TYP        REGULAR
#define INTDRV_snRSPI_C_RX_FLAG_W_LOGIC_TYP            REGULAR
#define INTDRV_snRSPI_C_TX_FLAG_W_LOGIC_TYP            REGULAR
#define INTDRV_snRSPI_C_ER_FLAG_W_LOGIC_TYP            REGULAR

/**********************************************************************************************************************/
/* !Comment : CAN Flag Logical Type                                                                                   */
/**********************************************************************************************************************/
#define INTDRV_snCAN_A_ER_MODE_ER_FLAG_W_LOGIC_TYP                             INVERTED
#define INTDRV_snCAN_A_BUS_OFF_RECOVER_FLAG_W_LOGIC_TYP                        INVERTED
#define INTDRV_snCAN_A_TX_WARNING_ER_FLAG_W_LOGIC_TYP                          INVERTED
#define INTDRV_snCAN_A_RX_WARNING_ER_FLAG_W_LOGIC_TYP                          INVERTED
#define INTDRV_snCAN_A_RESET_HALT_CAN_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_A_OVR_FRAME_TX_FLAG_W_LOGIC_TYP                           INVERTED
#define INTDRV_snCAN_A_UNREAD_MSG_OVW_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_A_START_NEW_SYS_MATRIX_FLAG_W_LOGIC_TYP                   INVERTED
#define INTDRV_snCAN_A_TMR_2_CM_FLAG_W_LOGIC_TYP                               INVERTED
#define INTDRV_snCAN_A_BUS_ACTIVE_IN_SLEEP_MODE_FLAG_W_LOGIC_TYP               INVERTED
#define INTDRV_snCAN_A_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_FLAG_W_LOGIC_TYP INVERTED
#define INTDRV_snCAN_A_TMR_0_CM_LOCAL_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_A_TMR_1_CM_CYCLE_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_A_DATA_FRAME_RECV_FLAG_W_LOGIC_TYP                        INVERTED
#define INTDRV_snCAN_A_RM_FRAME_RECV_FLAG_W_LOGIC_TYP                          INVERTED
#define INTDRV_snCAN_A_MSG_TRANS_FLAG_W_LOGIC_TYP                              INVERTED
#define INTDRV_snCAN_B_ER_MODE_ER_FLAG_W_LOGIC_TYP                             INVERTED
#define INTDRV_snCAN_B_BUS_OFF_RECOVER_FLAG_W_LOGIC_TYP                        INVERTED
#define INTDRV_snCAN_B_TX_WARNING_ER_FLAG_W_LOGIC_TYP                          INVERTED
#define INTDRV_snCAN_B_RX_WARNING_ER_FLAG_W_LOGIC_TYP                          INVERTED
#define INTDRV_snCAN_B_RESET_HALT_CAN_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_B_OVR_FRAME_TX_FLAG_W_LOGIC_TYP                           INVERTED
#define INTDRV_snCAN_B_UNREAD_MSG_OVW_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_B_START_NEW_SYS_MATRIX_FLAG_W_LOGIC_TYP                   INVERTED
#define INTDRV_snCAN_B_TMR_2_CM_FLAG_W_LOGIC_TYP                               INVERTED
#define INTDRV_snCAN_B_BUS_ACTIVE_IN_SLEEP_MODE_FLAG_W_LOGIC_TYP               INVERTED
#define INTDRV_snCAN_B_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_FLAG_W_LOGIC_TYP INVERTED
#define INTDRV_snCAN_B_TMR_0_CM_LOCAL_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_B_TMR_1_CM_CYCLE_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_B_DATA_FRAME_RECV_FLAG_W_LOGIC_TYP                        INVERTED
#define INTDRV_snCAN_B_RM_FRAME_RECV_FLAG_W_LOGIC_TYP                          INVERTED
#define INTDRV_snCAN_B_MSG_TRANS_FLAG_W_LOGIC_TYP                              INVERTED
#define INTDRV_snCAN_C_ER_MODE_ER_FLAG_W_LOGIC_TYP                             INVERTED
#define INTDRV_snCAN_C_BUS_OFF_RECOVER_FLAG_W_LOGIC_TYP                        INVERTED
#define INTDRV_snCAN_C_TX_WARNING_ER_FLAG_W_LOGIC_TYP                          INVERTED
#define INTDRV_snCAN_C_RX_WARNING_ER_FLAG_W_LOGIC_TYP                          INVERTED
#define INTDRV_snCAN_C_RESET_HALT_CAN_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_C_OVR_FRAME_TX_FLAG_W_LOGIC_TYP                           INVERTED
#define INTDRV_snCAN_C_UNREAD_MSG_OVW_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_C_START_NEW_SYS_MATRIX_FLAG_W_LOGIC_TYP                   INVERTED
#define INTDRV_snCAN_C_TMR_2_CM_FLAG_W_LOGIC_TYP                               INVERTED
#define INTDRV_snCAN_C_BUS_ACTIVE_IN_SLEEP_MODE_FLAG_W_LOGIC_TYP               INVERTED
#define INTDRV_snCAN_C_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_FLAG_W_LOGIC_TYP INVERTED
#define INTDRV_snCAN_C_TMR_0_CM_LOCAL_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_C_TMR_1_CM_CYCLE_FLAG_W_LOGIC_TYP                         INVERTED
#define INTDRV_snCAN_C_DATA_FRAME_RECV_FLAG_W_LOGIC_TYP                        INVERTED
#define INTDRV_snCAN_C_RM_FRAME_RECV_FLAG_W_LOGIC_TYP                          INVERTED
#define INTDRV_snCAN_C_MSG_TRANS_FLAG_W_LOGIC_TYP                              INVERTED

/**********************************************************************************************************************/
/* !Comment : ADMA Flag Logical Type                                                                                  */
/**********************************************************************************************************************/
#define INTDRV_snADMA_2_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADMA_3_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADMA_4_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADMA_5_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADMA_6_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADMA_7_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADMA_8_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADMA_9_FLAG_W_LOGIC_TYP  REGULAR
#define INTDRV_snADMA_10_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_11_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_12_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_13_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_14_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_15_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_16_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_17_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_18_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_19_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_20_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_21_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_22_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_23_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_24_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_25_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_26_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_27_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_28_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_29_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_30_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_31_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_32_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_33_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_34_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_35_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_36_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_37_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_38_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_39_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_40_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_41_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_42_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_43_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_44_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_45_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_46_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_47_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_56_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_57_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_58_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_59_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_60_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_61_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_62_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_63_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_64_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_65_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_66_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_67_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_68_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_69_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_70_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_71_FLAG_W_LOGIC_TYP REGULAR
#define INTDRV_snADMA_74_FLAG_W_LOGIC_TYP REGULAR

/**********************************************************************************************************************/
/* !Comment : Clearing Possibilities                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* !Comment : IRQ Interrupts Clearable / Not Clearable                                                                */
/**********************************************************************************************************************/
#define INTDRV_snIRQ_0_CLEARABLE CLEARABLE
#define INTDRV_snIRQ_1_CLEARABLE CLEARABLE
#define INTDRV_snIRQ_2_CLEARABLE CLEARABLE
#define INTDRV_snIRQ_3_CLEARABLE CLEARABLE
#define INTDRV_snIRQ_4_CLEARABLE CLEARABLE
#define INTDRV_snIRQ_5_CLEARABLE CLEARABLE
#define INTDRV_snIRQ_6_CLEARABLE CLEARABLE
#define INTDRV_snIRQ_7_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : SINT Clearable / Not Clearable                                                                          */
/**********************************************************************************************************************/
#define INTDRV_snSINT1_CLEARABLE  CLEARABLE
#define INTDRV_snSINT2_CLEARABLE  CLEARABLE
#define INTDRV_snSINT3_CLEARABLE  CLEARABLE
#define INTDRV_snSINT4_CLEARABLE  CLEARABLE
#define INTDRV_snSINT5_CLEARABLE  CLEARABLE
#define INTDRV_snSINT6_CLEARABLE  CLEARABLE
#define INTDRV_snSINT7_CLEARABLE  CLEARABLE
#define INTDRV_snSINT8_CLEARABLE  CLEARABLE
#define INTDRV_snSINT9_CLEARABLE  CLEARABLE
#define INTDRV_snSINT10_CLEARABLE CLEARABLE
#define INTDRV_snSINT11_CLEARABLE CLEARABLE
#define INTDRV_snSINT12_CLEARABLE CLEARABLE
#define INTDRV_snSINT13_CLEARABLE CLEARABLE
#define INTDRV_snSINT14_CLEARABLE CLEARABLE
#define INTDRV_snSINT15_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : RAM & ROM Interrupts Clearable / Not Clearable                                                          */
/**********************************************************************************************************************/
#define INTDRV_snRAM_PARITY_ER_CLEARABLE        CLEARABLE
#define INTDRV_snRAM_DETECT_2BITS_ER_CLEARABLE  CLEARABLE
#define INTDRV_snRAM_CORRECT_1BIT_ER_CLEARABLE  CLEARABLE
#define INTDRV_snROM_ACCESS_ER_CLEARABLE        CLEARABLE
#define INTDRV_snFCU_CMD_LOCK_CLEARABLE         CLEARABLE
#define INTDRV_snEEPROM_ACCESS_ER_CLEARABLE     CLEARABLE
#define INTDRV_snEEPROM_INST_FETCH_ER_CLEARABLE CLEARABLE
#define INTDRV_snEEPROM_RD_PTCT_ER_CLEARABLE    CLEARABLE
#define INTDRV_snEEPROM_WR_PTCT_ER_CLEARABLE    CLEARABLE

/**********************************************************************************************************************/
/* !Comment : DMA Interrupts Clearable / Not Clearable                                                                */
/**********************************************************************************************************************/
#define INTDRV_snDMA_0_0_DEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_0_HEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_1_DEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_1_HEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_2_DEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_2_HEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_3_DEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_3_HEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_4_DEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_4_HEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_5_DEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_5_HEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_6_DEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_6_HEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_7_DEI_CLEARABLE CLEARABLE
#define INTDRV_snDMA_0_7_HEI_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : CMT Interrupts Clearable / Not Clearable                                                                */
/**********************************************************************************************************************/
#define INTDRV_snCMT_0_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snCMT_1_0_CM_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : WDT Interrupts Clearable / Not Clearable                                                                */
/**********************************************************************************************************************/
#define INTDRV_snWDT_IT_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : TMR_A Interrupts Clearable / Not Clearable                                                              */
/**********************************************************************************************************************/
#define INTDRV_snTMR_A0_0_IC_CLEARABLE CLEARABLE
#define INTDRV_snTMR_A0_1_IC_CLEARABLE CLEARABLE
#define INTDRV_snTMR_A0_2_IC_CLEARABLE CLEARABLE
#define INTDRV_snTMR_A0_3_IC_CLEARABLE CLEARABLE
#define INTDRV_snTMR_A0_4_IC_CLEARABLE CLEARABLE
#define INTDRV_snTMR_A0_5_IC_CLEARABLE CLEARABLE
#define INTDRV_snTMR_A0_0_OV_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : TMR_B Interrupts Clearable / Not Clearable                                                              */
/**********************************************************************************************************************/
#define INTDRV_snTMR_B0_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_B0_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_B0_6_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_B0_0_IC_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : TMR_C Interrupts Clearable / Not Clearable                                                              */
/**********************************************************************************************************************/
#define INTDRV_snTMR_C0_0_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C0_1_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C0_2_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C0_3_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C0_0_OV_CLEARABLE    CLEARABLE
#define INTDRV_snTMR_C1_0_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C1_1_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C1_2_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C1_3_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C1_0_OV_CLEARABLE    CLEARABLE
#define INTDRV_snTMR_C2_0_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C2_1_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C2_2_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C2_3_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C2_0_OV_CLEARABLE    CLEARABLE
#define INTDRV_snTMR_C3_0_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C3_1_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C3_2_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C3_3_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C3_0_OV_CLEARABLE    CLEARABLE
#define INTDRV_snTMR_C4_0_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C4_1_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C4_2_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C4_3_IC_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_C4_0_OV_CLEARABLE    CLEARABLE

/**********************************************************************************************************************/
/* !Comment : TMR_D Interrupts Clearable / Not Clearable                                                              */
/**********************************************************************************************************************/
#define INTDRV_snTMR_1D0_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D0_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D0_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D0_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D0_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D0_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D0_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D0_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D0_OV_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_2D0_OV_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_DD0_0_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD0_1_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD0_2_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD0_3_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D1_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D1_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D1_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D1_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D1_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D1_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D1_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D1_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D1_OV_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_2D1_OV_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_DD1_0_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD1_1_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD1_2_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD1_3_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D2_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D2_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D2_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D2_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D2_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D2_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D2_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D2_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D2_OV_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_2D2_OV_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_DD2_0_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD2_1_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD2_2_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD2_3_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D3_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D3_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D3_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D3_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D3_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D3_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D3_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_2D3_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_1D3_OV_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_2D3_OV_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_DD3_0_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD3_1_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD3_2_UF_CLEARABLE CLEARABLE
#define INTDRV_snTMR_DD3_3_UF_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : TMR_E Interrupts Clearable / Not Clearable                                                              */
/**********************************************************************************************************************/
#define INTDRV_snTMR_E0_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E0_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E0_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E0_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E1_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E1_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E1_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E1_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E2_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E2_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E2_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E2_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E3_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E3_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E3_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E3_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E4_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E4_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E4_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E4_3_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E5_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E5_1_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E5_2_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_E5_3_CM_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : TMR_F Interrupts Clearable / Not Clearable                                                              */
/**********************************************************************************************************************/
#define INTDRV_snTMR_F0_0_IC_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_F1_0_IC_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_F2_0_IC_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_F3_0_IC_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_F4_0_IC_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_F5_0_IC_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_F6_0_IC_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_F7_0_IC_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_F8_0_IC_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_F9_0_IC_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_F10_0_IC_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_F11_0_IC_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_F12_0_IC_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_F13_0_IC_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_F14_0_IC_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_F15_0_IC_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_F16_0_IC_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_F17_0_IC_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_F18_0_IC_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_F19_0_IC_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_AF0_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_BF0_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_CF0_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_AF1_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_BF1_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_CF1_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_AF2_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_BF2_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_CF2_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_AF3_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_BF3_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_CF3_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_AF4_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_BF4_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_CF4_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_AF5_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_BF5_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_CF5_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_AF6_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_BF6_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_CF6_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_AF7_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_BF7_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_CF7_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_AF8_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_BF8_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_CF8_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_AF9_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_BF9_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_CF9_0_OV_CLEARABLE  CLEARABLE
#define INTDRV_snTMR_AF10_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_BF10_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_CF10_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_AF11_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_BF11_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_CF11_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_AF12_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_BF12_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_CF12_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_AF13_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_BF13_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_CF13_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_AF14_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_BF14_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_CF14_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_AF15_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_BF15_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_CF15_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_AF16_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_BF16_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_CF16_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_AF17_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_BF17_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_CF17_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_AF18_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_BF18_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_CF18_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_AF19_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_BF19_0_OV_CLEARABLE CLEARABLE
#define INTDRV_snTMR_CF19_0_OV_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : TMR_G Interrupts Clearable / Not Clearable                                                              */
/**********************************************************************************************************************/
#define INTDRV_snTMR_G0_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_G1_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_G2_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_G3_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_G4_0_CM_CLEARABLE CLEARABLE
#define INTDRV_snTMR_G5_0_CM_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : TMR_H Interrupts Clearable / Not Clearable                                                              */
/**********************************************************************************************************************/
#define INTDRV_snTMR_H0_0_CM_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : TMR_J Interrupts Clearable / Not Clearable                                                              */
/**********************************************************************************************************************/
#define INTDRV_snTMR_J0_0_FIFO_FULL_CLEARABLE CLEARABLE
#define INTDRV_snTMR_J1_0_FIFO_FULL_CLEARABLE CLEARABLE
#define INTDRV_snTMR_J0_0_OV_CLEARABLE        CLEARABLE
#define INTDRV_snTMR_J1_0_OV_CLEARABLE        CLEARABLE
#define INTDRV_snTMR_J0_0_FIFO_OV_CLEARABLE   CLEARABLE
#define INTDRV_snTMR_J1_0_FIFO_OV_CLEARABLE   CLEARABLE

/**********************************************************************************************************************/
/* !Comment : ADC Interrupts Clearable / Not Clearable                                                                */
/**********************************************************************************************************************/
#define INTDRV_snADCA_END_SCAN_CONV_CLEARABLE    CLEARABLE
#define INTDRV_snADCB_END_SCAN_CONV_CLEARABLE    CLEARABLE
#define INTDRV_snADCA_0_END_INTR_CONV_CLEARABLE  CLEARABLE
#define INTDRV_snADCA_1_END_INTR_CONV_CLEARABLE  CLEARABLE
#define INTDRV_snADCA_2_END_INTR_CONV_CLEARABLE  CLEARABLE
#define INTDRV_snADCA_3_END_INTR_CONV_CLEARABLE  CLEARABLE
#define INTDRV_snADCA_4_END_INTR_CONV_CLEARABLE  CLEARABLE
#define INTDRV_snADCA_5_END_INTR_CONV_CLEARABLE  CLEARABLE
#define INTDRV_snADCA_6_END_INTR_CONV_CLEARABLE  CLEARABLE
#define INTDRV_snADCA_7_END_INTR_CONV_CLEARABLE  CLEARABLE
#define INTDRV_snADCA_8_END_INTR_CONV_CLEARABLE  CLEARABLE
#define INTDRV_snADCA_9_END_INTR_CONV_CLEARABLE  CLEARABLE
#define INTDRV_snADCA_10_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCA_11_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCA_12_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCA_13_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCA_14_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCA_15_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCB_40_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCB_41_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCB_42_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCB_43_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCB_44_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCB_45_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCB_46_END_INTR_CONV_CLEARABLE CLEARABLE
#define INTDRV_snADCB_47_END_INTR_CONV_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : SCI Interrupts Clearable / Not Clearable                                                                */
/**********************************************************************************************************************/
#define INTDRV_snSCI_A_OVR_ER_CLEARABLE    CLEARABLE
#define INTDRV_snSCI_A_FRAM_ER_CLEARABLE   CLEARABLE
#define INTDRV_snSCI_A_PARITY_ER_CLEARABLE CLEARABLE
#define INTDRV_snSCI_A_RX_CLEARABLE        CLEARABLE
#define INTDRV_snSCI_A_TX_CLEARABLE        CLEARABLE
#define INTDRV_snSCI_A_TX_END_CLEARABLE    NOT_CLEARABLE
#define INTDRV_snSCI_B_OVR_ER_CLEARABLE    CLEARABLE
#define INTDRV_snSCI_B_FRAM_ER_CLEARABLE   CLEARABLE
#define INTDRV_snSCI_B_PARITY_ER_CLEARABLE CLEARABLE
#define INTDRV_snSCI_B_RX_CLEARABLE        CLEARABLE
#define INTDRV_snSCI_B_TX_CLEARABLE        CLEARABLE
#define INTDRV_snSCI_B_TX_END_CLEARABLE    NOT_CLEARABLE
#define INTDRV_snSCI_C_OVR_ER_CLEARABLE    CLEARABLE
#define INTDRV_snSCI_C_FRAM_ER_CLEARABLE   CLEARABLE
#define INTDRV_snSCI_C_PARITY_ER_CLEARABLE CLEARABLE
#define INTDRV_snSCI_C_RX_CLEARABLE        CLEARABLE
#define INTDRV_snSCI_C_TX_CLEARABLE        CLEARABLE
#define INTDRV_snSCI_C_TX_END_CLEARABLE    NOT_CLEARABLE
#define INTDRV_snSCI_D_OVR_ER_CLEARABLE    CLEARABLE
#define INTDRV_snSCI_D_FRAM_ER_CLEARABLE   CLEARABLE
#define INTDRV_snSCI_D_PARITY_ER_CLEARABLE CLEARABLE
#define INTDRV_snSCI_D_RX_CLEARABLE        CLEARABLE
#define INTDRV_snSCI_D_TX_CLEARABLE        CLEARABLE
#define INTDRV_snSCI_D_TX_END_CLEARABLE    NOT_CLEARABLE
#define INTDRV_snSCI_E_OVR_ER_CLEARABLE    CLEARABLE
#define INTDRV_snSCI_E_FRAM_ER_CLEARABLE   CLEARABLE
#define INTDRV_snSCI_E_PARITY_ER_CLEARABLE CLEARABLE
#define INTDRV_snSCI_E_RX_CLEARABLE        CLEARABLE
#define INTDRV_snSCI_E_TX_CLEARABLE        CLEARABLE
#define INTDRV_snSCI_E_TX_END_CLEARABLE    NOT_CLEARABLE

/**********************************************************************************************************************/
/* !Comment : SPI Interrupts Clearable / Not Clearable                                                                */
/**********************************************************************************************************************/
#define INTDRV_snRSPI_A_MODE_FAULT_ER_CLEARABLE CLEARABLE
#define INTDRV_snRSPI_A_OVR_ER_CLEARABLE        CLEARABLE
#define INTDRV_snRSPI_A_ER_CLEARABLE            NOT_CLEARABLE
#define INTDRV_snRSPI_A_RX_CLEARABLE            CLEARABLE
#define INTDRV_snRSPI_A_TX_CLEARABLE            CLEARABLE
#define INTDRV_snRSPI_B_MODE_FAULT_ER_CLEARABLE CLEARABLE
#define INTDRV_snRSPI_B_OVR_ER_CLEARABLE        CLEARABLE
#define INTDRV_snRSPI_B_ER_CLEARABLE            NOT_CLEARABLE
#define INTDRV_snRSPI_B_RX_CLEARABLE            CLEARABLE
#define INTDRV_snRSPI_B_TX_CLEARABLE            CLEARABLE
#define INTDRV_snRSPI_C_MODE_FAULT_ER_CLEARABLE CLEARABLE
#define INTDRV_snRSPI_C_OVR_ER_CLEARABLE        CLEARABLE
#define INTDRV_snRSPI_C_ER_CLEARABLE            NOT_CLEARABLE
#define INTDRV_snRSPI_C_RX_CLEARABLE            CLEARABLE
#define INTDRV_snRSPI_C_TX_CLEARABLE            CLEARABLE

/**********************************************************************************************************************/
/* !Comment : CAN Interrupts Clearable / Not Clearable                                                                */
/**********************************************************************************************************************/
#define INTDRV_snCAN_A_ER_MODE_ER_CLEARABLE                             CLEARABLE
#define INTDRV_snCAN_A_BUS_OFF_RECOVER_CLEARABLE                        CLEARABLE
#define INTDRV_snCAN_A_TX_WARNING_ER_CLEARABLE                          CLEARABLE
#define INTDRV_snCAN_A_RX_WARNING_ER_CLEARABLE                          CLEARABLE
#define INTDRV_snCAN_A_RESET_HALT_CAN_CLEARABLE                         CLEARABLE
#define INTDRV_snCAN_A_OVR_FRAME_TX_CLEARABLE                           CLEARABLE
#define INTDRV_snCAN_A_UNREAD_MSG_OVW_CLEARABLE                         NOT_CLEARABLE
#define INTDRV_snCAN_A_START_NEW_SYS_MATRIX_CLEARABLE                   CLEARABLE
#define INTDRV_snCAN_A_TMR_2_CM_CLEARABLE                               CLEARABLE
#define INTDRV_snCAN_A_BUS_ACTIVE_IN_SLEEP_MODE_CLEARABLE               CLEARABLE
#define INTDRV_snCAN_A_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_CLEARABLE CLEARABLE
#define INTDRV_snCAN_A_TMR_0_CM_LOCAL_CLEARABLE                         CLEARABLE
#define INTDRV_snCAN_A_TMR_1_CM_CYCLE_CLEARABLE                         CLEARABLE
#define INTDRV_snCAN_A_DATA_FRAME_RECV_CLEARABLE                        NOT_CLEARABLE
#define INTDRV_snCAN_A_RM_FRAME_RECV_CLEARABLE                          NOT_CLEARABLE
#define INTDRV_snCAN_A_MSG_TRANS_CLEARABLE                              NOT_CLEARABLE
#define INTDRV_snCAN_B_ER_MODE_ER_CLEARABLE                             CLEARABLE
#define INTDRV_snCAN_B_BUS_OFF_RECOVER_CLEARABLE                        CLEARABLE
#define INTDRV_snCAN_B_TX_WARNING_ER_CLEARABLE                          CLEARABLE
#define INTDRV_snCAN_B_RX_WARNING_ER_CLEARABLE                          CLEARABLE
#define INTDRV_snCAN_B_RESET_HALT_CAN_CLEARABLE                         CLEARABLE
#define INTDRV_snCAN_B_OVR_FRAME_TX_CLEARABLE                           CLEARABLE
#define INTDRV_snCAN_B_UNREAD_MSG_OVW_CLEARABLE                         NOT_CLEARABLE
#define INTDRV_snCAN_B_START_NEW_SYS_MATRIX_CLEARABLE                   CLEARABLE
#define INTDRV_snCAN_B_TMR_2_CM_CLEARABLE                               CLEARABLE
#define INTDRV_snCAN_B_BUS_ACTIVE_IN_SLEEP_MODE_CLEARABLE               CLEARABLE
#define INTDRV_snCAN_B_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_CLEARABLE CLEARABLE
#define INTDRV_snCAN_B_TMR_0_CM_LOCAL_CLEARABLE                         CLEARABLE
#define INTDRV_snCAN_B_TMR_1_CM_CYCLE_CLEARABLE                         CLEARABLE
#define INTDRV_snCAN_B_DATA_FRAME_RECV_CLEARABLE                        NOT_CLEARABLE
#define INTDRV_snCAN_B_RM_FRAME_RECV_CLEARABLE                          NOT_CLEARABLE
#define INTDRV_snCAN_B_MSG_TRANS_CLEARABLE                              NOT_CLEARABLE
#define INTDRV_snCAN_C_ER_MODE_ER_CLEARABLE                             CLEARABLE
#define INTDRV_snCAN_C_BUS_OFF_RECOVER_CLEARABLE                        CLEARABLE
#define INTDRV_snCAN_C_TX_WARNING_ER_CLEARABLE                          CLEARABLE
#define INTDRV_snCAN_C_RX_WARNING_ER_CLEARABLE                          CLEARABLE
#define INTDRV_snCAN_C_RESET_HALT_CAN_CLEARABLE                         CLEARABLE
#define INTDRV_snCAN_C_OVR_FRAME_TX_CLEARABLE                           CLEARABLE
#define INTDRV_snCAN_C_UNREAD_MSG_OVW_CLEARABLE                         NOT_CLEARABLE
#define INTDRV_snCAN_C_START_NEW_SYS_MATRIX_CLEARABLE                   CLEARABLE
#define INTDRV_snCAN_C_TMR_2_CM_CLEARABLE                               CLEARABLE
#define INTDRV_snCAN_C_BUS_ACTIVE_IN_SLEEP_MODE_CLEARABLE               CLEARABLE
#define INTDRV_snCAN_C_EV_TRIG_OVERUN_NEXT_IS_GAP_TEST_MSG_ER_CLEARABLE CLEARABLE
#define INTDRV_snCAN_C_TMR_0_CM_LOCAL_CLEARABLE                         CLEARABLE
#define INTDRV_snCAN_C_TMR_1_CM_CYCLE_CLEARABLE                         CLEARABLE
#define INTDRV_snCAN_C_DATA_FRAME_RECV_CLEARABLE                        NOT_CLEARABLE
#define INTDRV_snCAN_C_RM_FRAME_RECV_CLEARABLE                          NOT_CLEARABLE
#define INTDRV_snCAN_C_MSG_TRANS_CLEARABLE                              NOT_CLEARABLE

/**********************************************************************************************************************/
/* !Comment : ADMA Interrupts Clearable / Not Clearable                                                               */
/**********************************************************************************************************************/
#define INTDRV_snADMA_2_CLEARABLE  CLEARABLE
#define INTDRV_snADMA_3_CLEARABLE  CLEARABLE
#define INTDRV_snADMA_4_CLEARABLE  CLEARABLE
#define INTDRV_snADMA_5_CLEARABLE  CLEARABLE
#define INTDRV_snADMA_6_CLEARABLE  CLEARABLE
#define INTDRV_snADMA_7_CLEARABLE  CLEARABLE
#define INTDRV_snADMA_8_CLEARABLE  CLEARABLE
#define INTDRV_snADMA_9_CLEARABLE  CLEARABLE
#define INTDRV_snADMA_10_CLEARABLE CLEARABLE
#define INTDRV_snADMA_11_CLEARABLE CLEARABLE
#define INTDRV_snADMA_12_CLEARABLE CLEARABLE
#define INTDRV_snADMA_13_CLEARABLE CLEARABLE
#define INTDRV_snADMA_14_CLEARABLE CLEARABLE
#define INTDRV_snADMA_15_CLEARABLE CLEARABLE
#define INTDRV_snADMA_16_CLEARABLE CLEARABLE
#define INTDRV_snADMA_17_CLEARABLE CLEARABLE
#define INTDRV_snADMA_18_CLEARABLE CLEARABLE
#define INTDRV_snADMA_19_CLEARABLE CLEARABLE
#define INTDRV_snADMA_20_CLEARABLE CLEARABLE
#define INTDRV_snADMA_21_CLEARABLE CLEARABLE
#define INTDRV_snADMA_22_CLEARABLE CLEARABLE
#define INTDRV_snADMA_23_CLEARABLE CLEARABLE
#define INTDRV_snADMA_24_CLEARABLE CLEARABLE
#define INTDRV_snADMA_25_CLEARABLE CLEARABLE
#define INTDRV_snADMA_26_CLEARABLE CLEARABLE
#define INTDRV_snADMA_27_CLEARABLE CLEARABLE
#define INTDRV_snADMA_28_CLEARABLE CLEARABLE
#define INTDRV_snADMA_29_CLEARABLE CLEARABLE
#define INTDRV_snADMA_30_CLEARABLE CLEARABLE
#define INTDRV_snADMA_31_CLEARABLE CLEARABLE
#define INTDRV_snADMA_32_CLEARABLE CLEARABLE
#define INTDRV_snADMA_33_CLEARABLE CLEARABLE
#define INTDRV_snADMA_34_CLEARABLE CLEARABLE
#define INTDRV_snADMA_35_CLEARABLE CLEARABLE
#define INTDRV_snADMA_36_CLEARABLE CLEARABLE
#define INTDRV_snADMA_37_CLEARABLE CLEARABLE
#define INTDRV_snADMA_38_CLEARABLE CLEARABLE
#define INTDRV_snADMA_39_CLEARABLE CLEARABLE
#define INTDRV_snADMA_40_CLEARABLE CLEARABLE
#define INTDRV_snADMA_41_CLEARABLE CLEARABLE
#define INTDRV_snADMA_42_CLEARABLE CLEARABLE
#define INTDRV_snADMA_43_CLEARABLE CLEARABLE
#define INTDRV_snADMA_44_CLEARABLE CLEARABLE
#define INTDRV_snADMA_45_CLEARABLE CLEARABLE
#define INTDRV_snADMA_46_CLEARABLE CLEARABLE
#define INTDRV_snADMA_47_CLEARABLE CLEARABLE
#define INTDRV_snADMA_56_CLEARABLE CLEARABLE
#define INTDRV_snADMA_57_CLEARABLE CLEARABLE
#define INTDRV_snADMA_58_CLEARABLE CLEARABLE
#define INTDRV_snADMA_59_CLEARABLE CLEARABLE
#define INTDRV_snADMA_60_CLEARABLE CLEARABLE
#define INTDRV_snADMA_61_CLEARABLE CLEARABLE
#define INTDRV_snADMA_62_CLEARABLE CLEARABLE
#define INTDRV_snADMA_63_CLEARABLE CLEARABLE
#define INTDRV_snADMA_64_CLEARABLE CLEARABLE
#define INTDRV_snADMA_65_CLEARABLE CLEARABLE
#define INTDRV_snADMA_66_CLEARABLE CLEARABLE
#define INTDRV_snADMA_67_CLEARABLE CLEARABLE
#define INTDRV_snADMA_68_CLEARABLE CLEARABLE
#define INTDRV_snADMA_69_CLEARABLE CLEARABLE
#define INTDRV_snADMA_70_CLEARABLE CLEARABLE
#define INTDRV_snADMA_71_CLEARABLE CLEARABLE
#define INTDRV_snADMA_74_CLEARABLE CLEARABLE

/**********************************************************************************************************************/
/* !Comment : Interrupt Control Register                                                                              */
/**********************************************************************************************************************/
#define INTDRV_vu16IRQ_CONTROL_REG INTC.ICR1.WORD

/**********************************************************************************************************************/
/* !Comment : Bank Function Related Registers                                                                         */
/**********************************************************************************************************************/
#define  INTDRV_vu16ITLEVEL_BANK_SELECT_REG   INTC.IBCR.WORD
#define  INTDRV_vu16BANK_FUNCTION_CONFIG_REG  INTC.IBNR.WORD
#define  INTDRV_vu16BANK_OVERFLOW_ENABLE_REG  INTC.IBNR.WORD


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_vidSET_CONFIG                                                              */
/* !Number      : I.0x00                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/14.01                                                                                     */
/* !Trace_To    : INTDRV/EA/08.01                                                                                     */
/* !Trace_To    : INTDRV/EA/09.01                                                                                     */
/* !Trace_To    : INTDRV/EA/08.02                                                                                     */
/* !Trace_To    : INTDRV/EA/09.02                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. Sabry                                                                                               */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidSET_CONFIG_I( \
\
   snGroupChannel, \
   snConfSelect, \
   u16Config \
\
) \
   M1_INTDRV_vidSET_CONFIG_##snConfSelect(snGroupChannel, u16Config)

   /* Internal macros */

   #define M1_INTDRV_vidSET_CONFIG_IT_LEVEL(snGroupChannel, u16Config) \
      M2_INTDRV_vidSET_CONFIG_IT_LEVEL( \
         INTDRV_vu16GET_PRIORITY_REG(snGroupChannel), u16Config) \

   #define M2_INTDRV_vidSET_CONFIG_IT_LEVEL(vu16PriorityReg, u16Config) \
      M3_INTDRV_vidSET_CONFIG_IT_LEVEL(vu16PriorityReg, u16Config)

   #define M3_INTDRV_vidSET_CONFIG_IT_LEVEL(vu16PriorityReg, u16Config) \
      ((vu16PriorityReg) = (uint16)(u16Config))

   #define M1_INTDRV_vidSET_CONFIG_EDGE(snGroupChannel, u16Config) \
      M2_INTDRV_vidSET_CONFIG_EDGE(INTDRV_vu16GET_IRQ_CONTROL_REG(), u16Config) \

   #define M2_INTDRV_vidSET_CONFIG_EDGE(vu16ControlReg, u16Config) \
      M3_INTDRV_vidSET_CONFIG_EDGE(vu16ControlReg, u16Config)

   #define M3_INTDRV_vidSET_CONFIG_EDGE(vu16ControlReg, u16Config) \
      vu16ControlReg = (uint16)(u16Config)

   #define M1_INTDRV_vidSET_CONFIG_IT_DISABLE(snGroupChannel, u16Config) \
      M2_INTDRV_vidSET_CONFIG_IT_DISABLE_##snGroupChannel(u16Config)

   #define M2_INTDRV_vidSET_CONFIG_IT_DISABLE_ALL(u16Config) \
   do \
   { \
      /* Clear RAM interrupt enable */ \
      RAM.RAMINT.BYTE = 0x00U; \
      /* Clear ROM interrupt enable */ \
      ROM.FAEINT.BYTE = 0x00U; \
      /* Clear DMA interrupt enable */ \
      DMAC0.CHCR.LONG &= 0xDD00FF39UL; \
      DMAC1.CHCR.LONG &= 0xDD00FF39UL; \
      DMAC2.CHCR.LONG &= 0xDD00FF39UL; \
      DMAC3.CHCR.LONG &= 0xDD00FF39UL; \
      DMAC4.CHCR.LONG &= 0xDD00FF39UL; \
      DMAC5.CHCR.LONG &= 0xDD00FF39UL; \
      DMAC6.CHCR.LONG &= 0xDD00FF39UL; \
      DMAC7.CHCR.LONG &= 0xDD00FF39UL; \
      /* Clear CMT interrupt enable */ \
      CMT.Channel[0].CMCR.BYTE &= 0x03U; \
      CMT.Channel[1].CMCR.BYTE &= 0x03U; \
      /* Clear Timer A interrupt enable */ \
      ATUA.TIERA.BYTE = 0x00U; \
      /* Clear Timer B interrupt enable */ \
      ATUB.TIERB.BYTE &= 0x30U; \
      /* Clear Timer C interrupt enable */ \
      ATUC.SUBBLOCK[0].TIERC.BYTE = 0x00U; \
      ATUC.SUBBLOCK[1].TIERC.BYTE = 0x00U; \
      ATUC.SUBBLOCK[2].TIERC.BYTE = 0x00U; \
      ATUC.SUBBLOCK[3].TIERC.BYTE = 0x00U; \
      ATUC.SUBBLOCK[4].TIERC.BYTE = 0x00U; \
      /* Clear Timer D interrupt enable */ \
      ATUD.SUBBLOCKB[0].TIERD.WORD = 0x0000U; \
      ATUD.SUBBLOCKB[1].TIERD.WORD = 0x0000U; \
      ATUD.SUBBLOCKB[2].TIERD.WORD = 0x0000U; \
      ATUD.SUBBLOCKB[3].TIERD.WORD = 0x0000U; \
      /* Clear Timer E interrupt enable */ \
      ATUE.SUBBLOCK[0].TIERE.BYTE = 0x00U; \
      ATUE.SUBBLOCK[1].TIERE.BYTE = 0x00U; \
      ATUE.SUBBLOCK[2].TIERE.BYTE = 0x00U; \
      ATUE.SUBBLOCK[3].TIERE.BYTE = 0x00U; \
      ATUE.SUBBLOCK[4].TIERE.BYTE = 0x00U; \
      ATUE.SUBBLOCK[5].TIERE.BYTE = 0x00U; \
      /* Clear Timer F interrupt enable */ \
      ATUF.SUBBLOCK[0].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[1].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[2].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[3].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[4].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[5].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[6].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[7].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[8].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[9].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[10].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[11].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[12].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[13].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[14].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[15].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[16].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[17].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[18].TIERF.BYTE = 0x00U; \
      ATUF.SUBBLOCK[19].TIERF.BYTE = 0x00U; \
      /* Clear Timer G interrupt enable */ \
      ATUG.SUBBLOCK[0].TCRG.BYTE &= 0x72U; \
      ATUG.SUBBLOCK[1].TCRG.BYTE &= 0x72U; \
      ATUG.SUBBLOCK[2].TCRG.BYTE &= 0x72U; \
      ATUG.SUBBLOCK[3].TCRG.BYTE &= 0x72U; \
      ATUG.SUBBLOCK[4].TCRG.BYTE &= 0x72U; \
      ATUG.SUBBLOCK[5].TCRG.BYTE &= 0x72U; \
      /* Clear Timer H interrupt enable */ \
      ATUH.TCRH.BYTE &= 0x70U; \
      /* Clear Timer J interrupt enable */ \
      ATUJ.SUBBLOCK[0].TIERJ.BYTE = 0x00U; \
      ATUJ.SUBBLOCK[1].TIERJ.BYTE = 0x00U; \
      /* Clear ADC interrupt enable */ \
      ADCA.ADCSR.BYTE &= 0xC3U; \
      ADCB.ADCSR.BYTE &= 0xC3U; \
      ADCA.ADTRD.WORD = 0x0000U; \
      ADCB.ADTRD.BYTE = 0x00U; \
      /* Clear SCI interrupt enable */ \
      SCIA.SCSCR1.BYTE &= 0x32U; \
      SCIB.SCSCR1.BYTE &= 0x32U; \
      SCIC.SCSCR1.BYTE &= 0x32U; \
      SCID.SCSCR1.BYTE &= 0x32U; \
      SCIE.SCSCR1.BYTE &= 0x32U; \
      /* Clear SPI interrupt enable */ \
      RSPIA.SPCR.BYTE &= 0x4CU; \
      RSPIB.SPCR.BYTE &= 0x4CU; \
      RSPIC.SPCR.BYTE &= 0x4CU; \
      /* Clear CAN interrupt enable */ \
      RCANA.IMR.WORD = 0xFFFFU; \
      RCANB.IMR.WORD = 0xFFFFU; \
      RCANC.IMR.WORD = 0xFFFFU; \
      /* Clear ADMA interrupt enable */ \
      ADMAC.ADMAIE0.BYTE = 0x00U; \
      ADMAC.ADMAIE1.BYTE = 0x00U; \
      ADMAC.ADMAIE2.BYTE = 0x00U; \
      ADMAC.ADMAIE3.BYTE = 0x00U; \
      ADMAC.ADMAIE4.BYTE = 0x00U; \
      ADMAC.ADMAIE5.BYTE = 0x00U; \
      ADMAC.ADMAIE7.BYTE = 0x00U; \
      ADMAC.ADMAIE8.BYTE = 0x00U; \
      ADMAC.ADMAIE9.BYTE = 0x00U; \
      \
      /* Clear IRQ interrupt */ \
      INTC.IRQRR.WORD &= 0x0000U; \
      /* Clear RAM interrupt */ \
      RAM.RAMERR.BYTE &= 0x00U; \
      INTDRV_vu8RegValue = RAM.RAMERR.BYTE; \
      nop(); \
      nop(); \
      nop(); \
      nop(); \
      nop(); \
      /* Clear ROM interrupt */ \
      ROM.FASTAT.BYTE &= 0x10U; \
      /* Clear DMA interrupt */ \
      DMAC0.CHFR.BYTE &= 0x00U; \
      DMAC1.CHFR.BYTE &= 0x00U; \
      DMAC2.CHFR.BYTE &= 0x00U; \
      DMAC3.CHFR.BYTE &= 0x00U; \
      DMAC4.CHFR.BYTE &= 0x00U; \
      DMAC5.CHFR.BYTE &= 0x00U; \
      DMAC6.CHFR.BYTE &= 0x00U; \
      DMAC7.CHFR.BYTE &= 0x00U; \
      /* Clear CMT interrupt */ \
      CMT.Channel[0].CMSR.BYTE &= 0x00U; \
      CMT.Channel[1].CMSR.BYTE &= 0x00U; \
      /* Clear WDT interrupt */ \
      WDTDRV_vidCLEAR_OVERFLOW_FLAG(INTERVAL_TMR_OVF); \
      WDTDRV_vidCLEAR_OVERFLOW_FLAG(WATCHDOG_TMR_OVF); \
      /* Clear Timer A interrupt */ \
      ATUA.TSRA.BYTE &= 0x00U; \
      /* Clear Timer B interrupt */ \
      ATUB.TSRB.BYTE &= 0x00U; \
      /* Clear Timer C interrupt */ \
      ATUC.SUBBLOCK[0].TSRC.BYTE &= 0x00U; \
      ATUC.SUBBLOCK[1].TSRC.BYTE &= 0x00U; \
      ATUC.SUBBLOCK[2].TSRC.BYTE &= 0x00U; \
      ATUC.SUBBLOCK[3].TSRC.BYTE &= 0x00U; \
      ATUC.SUBBLOCK[4].TSRC.BYTE &= 0x00U; \
      /* Clear Timer D interrupt */ \
      ATUD.SUBBLOCKB[0].TSRD.WORD &= 0x0000U; \
      ATUD.SUBBLOCKB[1].TSRD.WORD &= 0x0000U; \
      ATUD.SUBBLOCKB[2].TSRD.WORD &= 0x0000U; \
      ATUD.SUBBLOCKB[3].TSRD.WORD &= 0x0000U; \
      /* Clear Timer E interrupt */ \
      ATUE.SUBBLOCK[0].TSRE.BYTE &= 0xF0U; \
      ATUE.SUBBLOCK[1].TSRE.BYTE &= 0xF0U; \
      ATUE.SUBBLOCK[2].TSRE.BYTE &= 0xF0U; \
      ATUE.SUBBLOCK[3].TSRE.BYTE &= 0xF0U; \
      ATUE.SUBBLOCK[4].TSRE.BYTE &= 0xF0U; \
      ATUE.SUBBLOCK[5].TSRE.BYTE &= 0xF0U; \
      /* Clear Timer F interrupt */ \
      ATUF.SUBBLOCK[0].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[1].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[2].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[3].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[4].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[5].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[6].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[7].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[8].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[9].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[10].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[11].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[12].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[13].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[14].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[15].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[16].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[17].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[18].TSRF.BYTE &= 0x00U; \
      ATUF.SUBBLOCK[19].TSRF.BYTE &= 0x00U; \
      /* Clear Timer G interrupt */ \
      ATUG.SUBBLOCK[0].TSRG.BYTE &= 0x02U; \
      ATUG.SUBBLOCK[1].TSRG.BYTE &= 0x02U; \
      ATUG.SUBBLOCK[2].TSRG.BYTE &= 0x02U; \
      ATUG.SUBBLOCK[3].TSRG.BYTE &= 0x02U; \
      ATUG.SUBBLOCK[4].TSRG.BYTE &= 0x02U; \
      ATUG.SUBBLOCK[5].TSRG.BYTE &= 0x02U; \
      /* Clear Timer H interrupt */ \
      ATUH.TSRH.BYTE &= 0x06U; \
      /* Clear Timer J interrupt */ \
      ATUJ.SUBBLOCK[0].TSRJ.BYTE &= 0x18U; \
      ATUJ.SUBBLOCK[1].TSRJ.BYTE &= 0x18U; \
      /* Clear ADC interrupt */ \
      ADCA.ADREF.BYTE &= 0xC0U; \
      ADCB.ADREF.BYTE &= 0xC0U; \
      ADCA.ADTRF.WORD &= 0x0000U; \
      ADCB.ADTRF.BYTE &= 0x00U; \
      /* Clear SCI interrupt */ \
      SCIA.SCSSR1.BYTE &= 0x04U; \
      SCIB.SCSSR1.BYTE &= 0x04U; \
      SCIC.SCSSR1.BYTE &= 0x04U; \
      SCID.SCSSR1.BYTE &= 0x04U; \
      SCIE.SCSSR1.BYTE &= 0x04U; \
      /* Clear SPI interrupt */ \
      RSPIA.SPSR.BYTE &= 0x00U; \
      RSPIB.SPSR.BYTE &= 0x00U; \
      RSPIC.SPSR.BYTE &= 0x00U; \
      /* Clear CAN interrupt */ \
      RCANA.IRR.WORD = 0xFFFFU; \
      RCANB.IRR.WORD = 0xFFFFU; \
      RCANC.IRR.WORD = 0xFFFFU; \
      /* Clear ADMA interrupt */ \
      ADMAC.ADMADV0.BYTE &= 0x00U; \
      ADMAC.ADMADV1.BYTE &= 0x00U; \
      ADMAC.ADMADV2.BYTE &= 0x00U; \
      ADMAC.ADMADV3.BYTE &= 0x00U; \
      ADMAC.ADMADV4.BYTE &= 0x00U; \
      ADMAC.ADMADV5.BYTE &= 0x00U; \
      ADMAC.ADMATE0.BYTE &= 0x00U; \
      ADMAC.ADMATE1.BYTE &= 0x00U; \
      ADMAC.ADMATE2.BYTE &= 0x00U; \
   } \
   while(0)


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_vidSET_BANK_CONFIG                                                         */
/* !Number      : I.0x01                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/02.01                                                                                     */
/* !Trace_To    : INTDRV/EA/04.01                                                                                     */
/* !Trace_To    : INTDRV/EA/15.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidSET_BANK_CONFIG_I( \
\
   snBankConfSelect, \
   u16BankConfig \
\
) \
   M1_INTDRV_vidSET_BANK_CONFIG_I(snBankConfSelect, u16BankConfig)

   /* Internal macros */

   #define M1_INTDRV_vidSET_BANK_CONFIG_I(snBankConfSelect, u16BankConfig) \
      M2_INTDRV_vidSET_BANK_CONFIG_I(INTDRV_vu16GET_BANK_CONFIG_REG( \
                                             snBankConfSelect), u16BankConfig)

   #define M2_INTDRV_vidSET_BANK_CONFIG_I(vu16BankConfigReg, u16BankConfig) \
      M3_INTDRV_vidSET_BANK_CONFIG_I(vu16BankConfigReg, u16BankConfig)

   #define M3_INTDRV_vidSET_BANK_CONFIG_I(vu16BankConfigReg, u16BankConfig) \
      ((vu16BankConfigReg) = (u16BankConfig))


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_u16GET_PRIORITY_VALUE                                                      */
/* !Number      : I.0x02                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/16.01                                                                                     */
/* !Trace_To    : INTDRV/EA/08.02                                                                                     */
/* !Trace_To    : INTDRV/EA/10.01                                                                                     */
/* !Trace_To    : INTDRV/EA/10.02                                                                                     */
/* !Trace_To    : INTDRV/EA/07.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_u16GET_PRIORITY_VALUE_I( \
\
   snSubGroupChannel, \
   u8ItLevel \
\
) \
   M1_INTDRV_u16GET_PRIORITY_VALUE_I(snSubGroupChannel, u8ItLevel)

   /* Internal macros */

   #define M1_INTDRV_u16GET_PRIORITY_VALUE_I(snSubGroupChannel,u8ItLevel) \
      M2_INTDRV_u16GET_PRIORITY_VALUE_I( \
         INTDRV_u8##snSubGroupChannel##_SHIFT,u8ItLevel)

   #define M2_INTDRV_u16GET_PRIORITY_VALUE_I(u16ShiftValue, u8ItLevel) \
      ((uint16)(u8ItLevel << u16ShiftValue))


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_u16GET_EDGE_VALUE                                                          */
/* !Number      : I.0x03                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/17.01                                                                                     */
/* !Trace_To    : INTDRV/EA/08.02                                                                                     */
/* !Trace_To    : INTDRV/EA/06.01                                                                                     */
/* !Trace_To    : INTDRV/EA/05.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_u16GET_EDGE_VALUE_I( \
\
   snIRQ, \
   snSensitivity \
\
)  \
   INTDRV_u16##snIRQ##_##snSensitivity


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_u16GET_BANK_CONFIG_VALUE                                                   */
/* !Number      : I.0x04                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/18.01                                                                                     */
/* !Trace_To    : INTDRV/EA/04.01                                                                                     */
/* !Trace_To    : INTDRV/EA/03.01                                                                                     */
/* !Trace_To    : INTDRV/EA/02.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_u16GET_BANK_CONFIG_VALUE_I( \
\
   snBankConfSelect, \
   snBankConfValue \
\
) \
   INTDRV_u16BANK_CONFIG_##snBankConfSelect##_##snBankConfValue


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_vidENABLE                                                                  */
/* !Number      : I.0x05                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/19.01                                                                                     */
/* !Trace_To    : INTDRV/EA/01.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidENABLE_I( \
\
   snChannel \
\
) \
do \
{ \
   INTDRV_vidACKNOWLEDGE_I(snChannel); \
   INTDRV_vbGET_IT_BIT(snChannel)  = (1); \
} \
while (0)


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_vidDISABLE                                                                 */
/* !Number      : I.0x06                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/20.01                                                                                     */
/* !Trace_To    : INTDRV/EA/01.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidDISABLE_I( \
\
   snChannel \
\
) \
   ((INTDRV_vbGET_IT_BIT(snChannel))  = (0))


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_bCHECK                                                                     */
/* !Number      : I.0x07                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/21.01                                                                                     */
/* !Trace_To    : INTDRV/EA/01.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_bCHECK_I( \
\
   snChannel \
\
) \
   (INTDRV_vbGET_IT_FLAG(snChannel))


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_vidACKNOWLEDGE                                                             */
/* !Number      : I.0x08                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/22.01                                                                                     */
/* !Trace_To    : INTDRV/EA/01.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidACKNOWLEDGE_I( \
\
   snChannel \
\
) \
   M1_INTDRV_vidACKNOWLEDGE_I(snChannel)

   /* Internal macros */

   #define M1_INTDRV_vidACKNOWLEDGE_I(snChannel) \
      M2_INTDRV_vidACKNOWLEDGE_I(INTDRV_snGET_WRITE_LOGICAL_TYPE(snChannel), \
                                 INTDRV_vbGET_IT_FLAG(snChannel), \
                                 INTDRV_snGET_IT_CLEARABLE(snChannel))

   #define M2_INTDRV_vidACKNOWLEDGE_I(snLogType, vbInterruptFlag, snClearable) \
      M3_INTDRV_vidACKNOWLEDGE_I(snLogType, vbInterruptFlag, snClearable)

   #define M3_INTDRV_vidACKNOWLEDGE_I(snLogType, vbInterruptFlag, snClearable) \
      M4_INTDRV_vidACKNOWLEDGE_##snClearable(snLogType, vbInterruptFlag)

   #define M4_INTDRV_vidACKNOWLEDGE_CLEARABLE(snLogType, vbInterruptFlag) \
      M5_INTDRV_vidACKNOWLEDGE_CLEARABLE_##snLogType(vbInterruptFlag)

   #define M4_INTDRV_vidACKNOWLEDGE_NOT_CLEARABLE(snLogType, vbInterruptFlag)

   #define M5_INTDRV_vidACKNOWLEDGE_CLEARABLE_REGULAR(vbInterruptFlag) \
   do \
   { \
      vbInterruptFlag = 0; \
   } \
   while(0)

   #define M5_INTDRV_vidACKNOWLEDGE_CLEARABLE_INVERTED(vbInterruptFlag) \
   do \
   { \
      vbInterruptFlag = 1; \
   } \
   while(0)


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_vidSuspendAll                                                              */
/* !Number      : I.0x09                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/23.01                                                                                     */
/* !Trace_To    : INTDRV/EA/23.02                                                                                     */
/* !Trace_To    : INTDRV/EA/11.02                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidSuspendAll_I( \
\
   ps32ItLevel \
\
) \
   do \
   { \
      *(ps32ItLevel) = get_imask(); \
      set_imask(15); \
   } \
   while (0)


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_vidResumeAll                                                               */
/* !Number      : I.0x0A                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/24.01                                                                                     */
/* !Trace_To    : INTDRV/EA/24.02                                                                                     */
/* !Trace_To    : INTDRV/EA/11.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidResumeAll_I( \
\
   s32ItLevel \
\
) \
   set_imask((int)s32ItLevel)


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_vidTrap                                                                    */
/* !Number      : I.0x0B                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/25.01                                                                                     */
/* !Trace_To    : INTDRV/EA/12.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidTrap_I( \
\
   s32VectNumber \
\
) \
/* The casting is done to avoid QAC message about the not used return       */ \
/* value of the built-in function _builtin_trapa cakked here                */ \
   (void)trapa(s32VectNumber)


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_papfvidGetVectTableRef                                                     */
/* !Number      : I.0x0C                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/26.01                                                                                     */
/* !Trace_To    : INTDRV/EA/13.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_papfvidGetVectTableRef_I( \
\
\
) \
   get_vbr()


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_vidSetVectTable                                                            */
/* !Number      : I.0x0D                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/27.01                                                                                     */
/* !Trace_To    : INTDRV/EA/13.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vidSetVectTable_I( \
\
   pafpvidVectTabRef \
\
) \
   set_vbr(pafpvidVectTabRef)


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Implementation of INTDRV_bGET_ENABLE_BIT                                                            */
/* !Number      : I.0x0E                                                                                              */
/* !Reference   : V01 NT 07 00012 / 3                                                                                 */
/*                                                                                                                    */
/* !Trace_To    : INTDRV/EA/01.01                                                                                     */
/* !Trace_To    : INTDRV/EA/28.01                                                                                     */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_bGET_ENABLE_BIT_I( \
\
   snChannel \
\
) \
   INTDRV_vbGET_IT_BIT(snChannel)


/**********************************************************************************************************************/
/* Private Services                                                                                                   */
/**********************************************************************************************************************/


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Return the flag according to the "snChannel" value                                                  */
/* !Number      : I.0x18                                                                                              */
/* !Reference   : NONE /                                                                                              */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vbGET_IT_FLAG( \
\
   snChannel \
\
) \
   INTDRV_vb##snChannel##_IT_FLAG


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Return the Enable Bit according to the "snChannel" value                                            */
/* !Number      : I.0x19                                                                                              */
/* !Reference   : NONE /                                                                                              */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vbGET_IT_BIT( \
\
   snChannel \
\
) \
   INTDRV_vb##snChannel##_IT_BIT


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Return CLEARABLE or NOT_CLEARABLE if the "snChannel" channel is available for INTDRV_vidACKNOWLEDGE */
/* !Number      : I.0x1A                                                                                              */
/* !Reference   : NONE /                                                                                              */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_snGET_IT_CLEARABLE( \
\
   snChannel \
\
) \
   INTDRV_sn##snChannel##_CLEARABLE


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Retrieves the priority register name for the specified group of channels                            */
/* !Number      : I.0x1B                                                                                              */
/* !Reference   : NONE /                                                                                              */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vu16GET_PRIORITY_REG( \
\
   snGroupChannel \
\
) \
   M1_INTDRV_vu16GET_PRIORITY_REG(snGroupChannel)

   /* Internal macros */
   #define M1_INTDRV_vu16GET_PRIORITY_REG(snGroupChannel) \
      INTDRV_vu16##snGroupChannel##_PRIORITY_REG


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Return the Control register for certain Group "snGroupChannel"                                      */
/* !Number      : I.0x1C                                                                                              */
/* !Reference   : NONE /                                                                                              */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vu16GET_IRQ_CONTROL_REG( \
\
\
) \
   INTDRV_vu16IRQ_CONTROL_REG


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Return the Bank config register for certain configuration "snBankConfSelect" the returned register  */
/*                shall be either BCR or BNR                                                                          */
/* !Number      : I.0x1D                                                                                              */
/* !Reference   : NONE /                                                                                              */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_vu16GET_BANK_CONFIG_REG( \
\
   snBankConfSelect \
\
) \
   INTDRV_vu16##snBankConfSelect##_REG


/*********************************************** <AUTO_MACRO_HEADER> **************************************************/
/*                                                                                                                    */
/* !Description : Return the corresponding logical of a "snChannel" value                                             */
/* !Number      : I.0x1E                                                                                              */
/* !Reference   : NONE /                                                                                              */
/*                                                                                                                    */
/*                                                                                                                    */
/********************************************** </AUTO_MACRO_HEADER> **************************************************/
/* !Author   : M. MEKOUAR                                                                                             */
/**********************************************************************************************************************/

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define INTDRV_snGET_WRITE_LOGICAL_TYPE( \
\
   snChannel \
\
) \
   INTDRV_sn##snChannel##_FLAG_W_LOGIC_TYP


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
extern volatile uint8 INTDRV_vu8RegValue;


#endif /* INTDRV_I_H */

/*--------------------------------------------------- end of file ----------------------------------------------------*/

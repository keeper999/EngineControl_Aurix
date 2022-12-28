/***************************************************************************
;**
;** FILE NAME      : L9781_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef L9781_L_H
#define L9781_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "L9781_CFG_E.h"
#include "L9781_E.h"
#include "L9781_TYP.h"
#include "STD_TYPES.h"
#include "TYPE.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define L9781_ABACTSTATUS_COLS                 ( 3 )
#define L9781_ABBANKLOCK_COLS                  ( 3 )
#define L9781_ABFIRSTDIAGREAD_COLS             ( 2 )
#define L9781_ABIRQACTSTATUS_COLS              ( 3 )
#define L9781_ABIRQIDLESTATUS_COLS             ( 3 )
#define L9781_ABONLYOVLSPIDIAGMODE_COLS        ( 2 )
#define L9781_AU16FAILURECOUNTER_LNS          ( 3 )
#define L9781_AU16FAILURECOUNTER_COLS          ( 2 )
#define L9781_AU32BANKTOUNLOCK_COLS            ( 2 )
#define L9781_AU32DIAGBANKAFRAME_COLS          ( 2 )
#define L9781_AU32DIAGBANKBFRAME_COLS          ( 2 )
#define L9781_AU32DIAGFPFRAME_COLS             ( 2 )
#define L9781_AU32ICSTATUSFRAME_COLS           ( 2 )
#define L9781_AU8FIFOSPIREQCH_COLS             ( 8 )
#define L9781_AU8FIFOSPIREQTYP_COLS            ( 8 )
#define L9781_AU8INJPROFILE_COLS               ( 2 )
#define L9781_AU8PMPPROFILE_COLS               ( 2 )
#define L9781_AU8UNLOCKTIMEOUT_LNS            ( 3 )
#define L9781_AU8UNLOCKTIMEOUT_COLS            ( 2 )
#define L9781_bfIRQ_DIAG_INIT             65535
#define L9781_bfNO_SPI_REQUEST            0
#define L9781_bfPROFILE_NOT_UPDATED       0
#define L9781_u16BIT_0_MASK               1
#define L9781_u16BUFFER_UNDEFINED         65535
#define L9781_u16DUTY_EXT_CLK             16384
#define L9781_u32BIT_0_MASK               1
#define L9781_u32BUFFER_UNDEFINED        -1
#define L9781_u32FRAME_DIAG_BANK_A       -1895825408
#define L9781_u32FRAME_DIAG_BANK_B       -1862270976
#define L9781_u32FRAME_DIAG_FP           -1845493760
#define L9781_u32FRAME_IC_STATUS         -2147483648
#define L9781_u32MASK_ADDR                2113929216
#define L9781_u32MASK_ADDR_DATA           2130706428
#define L9781_u32MASK_ALL_DIAG            126
#define L9781_u32MASK_BANK_A_LOCKED       131072
#define L9781_u32MASK_BANK_A_UNLOCK       16
#define L9781_u32MASK_BANK_B_LOCKED       262144
#define L9781_u32MASK_BANK_B_UNLOCK       256
#define L9781_u32MASK_BANK_FP_LOCKED      524288
#define L9781_u32MASK_BANK_FP_UNLOCK      4096
#define L9781_u32MASK_CC_GND              16384
#define L9781_u32MASK_CC_VB               8192
#define L9781_u32MASK_CMD                -2147483648
#define L9781_u32MASK_CMD_ADDR           -33554432
#define L9781_u32MASK_CMD_ADDR_DATA      -16777220
#define L9781_u32MASK_DIAG_A_CMD_X_ACT    4096
#define L9781_u32MASK_DIAG_A_IRQ_ACT      4
#define L9781_u32MASK_DIAG_A_IRQ_IDLE     2
#define L9781_u32MASK_DIAG_B_CMD_X_ACT    16384
#define L9781_u32MASK_DIAG_B_IRQ_ACT      16
#define L9781_u32MASK_DIAG_B_IRQ_IDLE     8
#define L9781_u32MASK_DIAG_FP_CMD_ACT     65536
#define L9781_u32MASK_DIAG_FP_IRQ_ACT     64
#define L9781_u32MASK_DIAG_FP_IRQ_IDLE    32
#define L9781_u32MASK_HS_GATE             64
#define L9781_u32MASK_HS_IRQ              16
#define L9781_u32MASK_HS_VDS              32
#define L9781_u32MASK_INPUT_DATA          16777212
#define L9781_u32MASK_LOAD_SEL            262144
#define L9781_u32MASK_LS_GATE             512
#define L9781_u32MASK_LS_IRQ              128
#define L9781_u32MASK_LS_VDS              256
#define L9781_u32MASK_LSX_GATE            512
#define L9781_u32MASK_LSX_IRQ             128
#define L9781_u32MASK_LSX_VDS             256
#define L9781_u32MASK_LSY_GATE            4096
#define L9781_u32MASK_LSY_IRQ             1024
#define L9781_u32MASK_LSY_VDS             2048
#define L9781_u32MASK_OCF_HS              16
#define L9781_u32MASK_OCF_LS              4
#define L9781_u32MASK_OCS_HS              32
#define L9781_u32MASK_OCS_LS              8
#define L9781_u32MASK_OL_P                32768
#define L9781_u32MASK_OL_X                32768
#define L9781_u32MASK_OL_Y                65536
#define L9781_u32MASK_OSR                 131072
#define L9781_u32MASK_OV_LATCH            1024
#define L9781_u32MASK_TX_ODD_PARITY       16777216
#define L9781_u32MASK_UV_LATCH            512
#define L9781_u32NO_BANK_TO_UNLOCK        0
#define L9781_u32SPI_WRITE_CMD            0
#define L9781_u8BANK_A                    0
#define L9781_u8BANK_AX                   0
#define L9781_u8BANK_AY                   0
#define L9781_u8BANK_B                    1
#define L9781_u8BANK_BX                   1
#define L9781_u8BANK_BY                   1
#define L9781_u8BANK_FP                   2
#define L9781_u8CHANNEL_UNDEFINED         255
#define L9781_u8FIFO_UNDEFINED            255
#define L9781_u8FIRST_BANK                0
#define L9781_u8FIRST_CHANNEL             0
#define L9781_u8ID_AB_FRA1_CONF           3
#define L9781_u8ID_AB_FRA1_PARA1          0
#define L9781_u8ID_AB_FRA1_PARA2          1
#define L9781_u8ID_AB_FRA1_PARA3          2
#define L9781_u8ID_AB_FRA1_PARA4          3
#define L9781_u8ID_AB_FRA2_CONF           4
#define L9781_u8ID_AB_FRA2_PARA1          4
#define L9781_u8ID_AB_FRA2_PARA2          5
#define L9781_u8ID_AB_FRA2_PARA3          6
#define L9781_u8ID_AB_FRA2_PARA4          7
#define L9781_u8ID_AB_FRA3_CONF           5
#define L9781_u8ID_AB_FRA3_PARA1          8
#define L9781_u8ID_AB_FRA3_PARA2          9
#define L9781_u8ID_AB_FRA3_PARA3          10
#define L9781_u8ID_AB_IDLE_DLY            15
#define L9781_u8ID_AB_PROT_CONF           13
#define L9781_u8ID_AB_ZLC_OC_CONF         6
#define L9781_u8ID_DCDC_CONF              10
#define L9781_u8ID_DIAG_BANK_A            1
#define L9781_u8ID_DIAG_BANK_B            2
#define L9781_u8ID_DIAG_FP                3
#define L9781_u8ID_DIAG_PROT_CTRL         11
#define L9781_u8ID_FIRST_SPI_FRAME        0
#define L9781_u8ID_FP_FRA1_CONF           7
#define L9781_u8ID_FP_FRA1_PARA1          0
#define L9781_u8ID_FP_FRA1_PARA2          1
#define L9781_u8ID_FP_FRA1_PARA3          2
#define L9781_u8ID_FP_FRA1_PARA4          3
#define L9781_u8ID_FP_FRA2_CONF           8
#define L9781_u8ID_FP_FRA2_PARA1          4
#define L9781_u8ID_FP_FRA2_PARA2          5
#define L9781_u8ID_FP_FRA2_PARA3          6
#define L9781_u8ID_FP_IDLE_DLY            16
#define L9781_u8ID_FP_PROT_CONF           14
#define L9781_u8ID_FP_ZLC_OC_CONF         9
#define L9781_u8ID_GEN_CONF               0
#define L9781_u8ID_IC_STATUS              0
#define L9781_u8ID_ISEN_CONF              2
#define L9781_u8ID_PDRV_CONF              1
#define L9781_u8ID_PDRV_ENB               17
#define L9781_u8ID_PROT_FILT_CTRL         12
#define L9781_u8ID_UNDEFINED              255
#define L9781_u8LOAD_DIAG_REQ             64
#define L9781_u8LOAD_INJ_PROF_REQ         16
#define L9781_u8LOAD_PMP_PROF_REQ         32
#define L9781_u8LOAD_UNLOCK_REQ           128
#define L9781_u8NB_ASIC                   2
#define L9781_u8NB_BANK                   3
#define L9781_u8NB_FRAME_DIAG             4
#define L9781_u8NB_FRAME_GEN_CONF         17
#define L9781_u8NB_FRAME_INJ_PROF         11
#define L9781_u8NB_FRAME_PMP_PROF         7
#define L9781_u8NB_SPI_REQ_MAX            8
#define L9781_u8NB_SPI_REQ_TYP            4
#define L9781_u8SHIFT_15_BITS             15
#define L9781_u8SHIFT_16_BITS             16
#define L9781_u8SHIFT_ADDR                25
#define L9781_u8SHIFT_TX_ODD_PARITY       24
#define L9781_u8UNLOCK_IDLE_DELAY         1
#define L9781_udtADDR_AB_FRA1_CONF        3
#define L9781_udtADDR_AB_FRA1_PARA1       18
#define L9781_udtADDR_AB_FRA1_PARA2       19
#define L9781_udtADDR_AB_FRA1_PARA3       20
#define L9781_udtADDR_AB_FRA1_PARA4       21
#define L9781_udtADDR_AB_FRA2_CONF        4
#define L9781_udtADDR_AB_FRA2_PARA1       22
#define L9781_udtADDR_AB_FRA2_PARA2       23
#define L9781_udtADDR_AB_FRA2_PARA3       24
#define L9781_udtADDR_AB_FRA2_PARA4       25
#define L9781_udtADDR_AB_FRA3_CONF        5
#define L9781_udtADDR_AB_FRA3_PARA1       26
#define L9781_udtADDR_AB_FRA3_PARA2       27
#define L9781_udtADDR_AB_FRA3_PARA3       28
#define L9781_udtADDR_AB_IDLE_DLY         15
#define L9781_udtADDR_AB_PROT_CONF        13
#define L9781_udtADDR_AB_ZLC_OC_CONF      6
#define L9781_udtADDR_DCDC_CONF           10
#define L9781_udtADDR_DIAG_PROT_CTRL      11
#define L9781_udtADDR_FP_FRA1_CONF        7
#define L9781_udtADDR_FP_FRA1_PARA1       29
#define L9781_udtADDR_FP_FRA1_PARA2       30
#define L9781_udtADDR_FP_FRA1_PARA3       31
#define L9781_udtADDR_FP_FRA1_PARA4       32
#define L9781_udtADDR_FP_FRA2_CONF        8
#define L9781_udtADDR_FP_FRA2_PARA1       33
#define L9781_udtADDR_FP_FRA2_PARA2       34
#define L9781_udtADDR_FP_FRA2_PARA3       35
#define L9781_udtADDR_FP_IDLE_DLY         16
#define L9781_udtADDR_FP_PROT_CONF        14
#define L9781_udtADDR_FP_ZLC_OC_CONF      9
#define L9781_udtADDR_GEN_CONF            0
#define L9781_udtADDR_ISEN_CONF           2
#define L9781_udtADDR_PDRV_CONF           1
#define L9781_udtADDR_PDRV_ENB            38
#define L9781_udtADDR_PROT_FILT_CTRL      12
#define L9781_udtADDR_UNLOCK_DIAG         17

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st9700 */
#define L9781_enuLOAD_IDLE                0
#define L9781_enuLOAD_GEN_CONF            1
#define L9781_enuLOAD_INJ_PROF            2
#define L9781_enuLOAD_PMP_PROF            4
#define L9781_enuLOAD_DIAG                8
#define L9781_enuLOAD_STARTUP_COMPLETE    16
#define L9781_enuLOAD_PDRV_ENB            32
#define L9781_enuLOAD_UNLOCK              64
/*extern uint8 L9781_enuLoadingState;*/

/* enum st9701 */
#define L9781_enuSTART_RST_ACTIVE_LVL     1
#define L9781_enuSTART_CLK_EXT            2
#define L9781_enuSTART_RST_INACTIVE_LVL   4
#define L9781_enuSTART_SPI_COM            8
#define L9781_enuSTART_W_CBT_CHARGE       16
#define L9781_enuSTART_ENABLE             32
#define L9781_enuSTART_END                64
/*extern uint8 L9781_enuStartupState;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint32  L9781_ku32AbFra1ConfCfg1;
extern const uint32  L9781_ku32AbFra1ConfCfg2;
extern const uint32  L9781_ku32AbFra1Para1Prof1;
extern const uint32  L9781_ku32AbFra1Para1Prof2;
extern const uint32  L9781_ku32AbFra1Para1Prof3;
extern const uint32  L9781_ku32AbFra1Para1Prof4;
extern const uint32  L9781_ku32AbFra1Para2Prof1;
extern const uint32  L9781_ku32AbFra1Para2Prof2;
extern const uint32  L9781_ku32AbFra1Para2Prof3;
extern const uint32  L9781_ku32AbFra1Para2Prof4;
extern const uint32  L9781_ku32AbFra1Para3Prof1;
extern const uint32  L9781_ku32AbFra1Para3Prof2;
extern const uint32  L9781_ku32AbFra1Para3Prof3;
extern const uint32  L9781_ku32AbFra1Para3Prof4;
extern const uint32  L9781_ku32AbFra1Para4Prof1;
extern const uint32  L9781_ku32AbFra1Para4Prof2;
extern const uint32  L9781_ku32AbFra1Para4Prof3;
extern const uint32  L9781_ku32AbFra1Para4Prof4;
extern const uint32  L9781_ku32AbFra2ConfCfg1;
extern const uint32  L9781_ku32AbFra2ConfCfg2;
extern const uint32  L9781_ku32AbFra2Para1Prof1;
extern const uint32  L9781_ku32AbFra2Para1Prof2;
extern const uint32  L9781_ku32AbFra2Para1Prof3;
extern const uint32  L9781_ku32AbFra2Para1Prof4;
extern const uint32  L9781_ku32AbFra2Para2Prof1;
extern const uint32  L9781_ku32AbFra2Para2Prof2;
extern const uint32  L9781_ku32AbFra2Para2Prof3;
extern const uint32  L9781_ku32AbFra2Para2Prof4;
extern const uint32  L9781_ku32AbFra2Para3Prof1;
extern const uint32  L9781_ku32AbFra2Para3Prof2;
extern const uint32  L9781_ku32AbFra2Para3Prof3;
extern const uint32  L9781_ku32AbFra2Para3Prof4;
extern const uint32  L9781_ku32AbFra2Para4Prof1;
extern const uint32  L9781_ku32AbFra2Para4Prof2;
extern const uint32  L9781_ku32AbFra2Para4Prof3;
extern const uint32  L9781_ku32AbFra2Para4Prof4;
extern const uint32  L9781_ku32AbFra3ConfCfg1;
extern const uint32  L9781_ku32AbFra3ConfCfg2;
extern const uint32  L9781_ku32AbFra3Para1Prof1;
extern const uint32  L9781_ku32AbFra3Para1Prof2;
extern const uint32  L9781_ku32AbFra3Para1Prof3;
extern const uint32  L9781_ku32AbFra3Para1Prof4;
extern const uint32  L9781_ku32AbFra3Para2Prof1;
extern const uint32  L9781_ku32AbFra3Para2Prof2;
extern const uint32  L9781_ku32AbFra3Para2Prof3;
extern const uint32  L9781_ku32AbFra3Para2Prof4;
extern const uint32  L9781_ku32AbFra3Para3Prof1;
extern const uint32  L9781_ku32AbFra3Para3Prof2;
extern const uint32  L9781_ku32AbFra3Para3Prof3;
extern const uint32  L9781_ku32AbFra3Para3Prof4;
extern const uint32  L9781_ku32AbIdleDlyCfg1;
extern const uint32  L9781_ku32AbIdleDlyCfg2;
extern const uint32  L9781_ku32AbProtConfCfg1;
extern const uint32  L9781_ku32AbProtConfCfg2;
extern const uint32  L9781_ku32AbZlcOcConfCfg1;
extern const uint32  L9781_ku32AbZlcOcConfCfg2;
extern const uint32  L9781_ku32DcdcConfCfg1;
extern const uint32  L9781_ku32DcdcConfCfg2;
extern const uint32  L9781_ku32DiagProtCtrlCfg1;
extern const uint32  L9781_ku32DiagProtCtrlCfg2;
extern const uint32  L9781_ku32FpFra1ConfCfg1;
extern const uint32  L9781_ku32FpFra1ConfCfg2;
extern const uint32  L9781_ku32FpFra1Para1Prof1;
extern const uint32  L9781_ku32FpFra1Para1Prof10;
extern const uint32  L9781_ku32FpFra1Para1Prof11;
extern const uint32  L9781_ku32FpFra1Para1Prof12;
extern const uint32  L9781_ku32FpFra1Para1Prof13;
extern const uint32  L9781_ku32FpFra1Para1Prof14;
extern const uint32  L9781_ku32FpFra1Para1Prof15;
extern const uint32  L9781_ku32FpFra1Para1Prof16;
extern const uint32  L9781_ku32FpFra1Para1Prof17;
extern const uint32  L9781_ku32FpFra1Para1Prof18;
extern const uint32  L9781_ku32FpFra1Para1Prof19;
extern const uint32  L9781_ku32FpFra1Para1Prof2;
extern const uint32  L9781_ku32FpFra1Para1Prof20;
extern const uint32  L9781_ku32FpFra1Para1Prof21;
extern const uint32  L9781_ku32FpFra1Para1Prof22;
extern const uint32  L9781_ku32FpFra1Para1Prof23;
extern const uint32  L9781_ku32FpFra1Para1Prof24;
extern const uint32  L9781_ku32FpFra1Para1Prof25;
extern const uint32  L9781_ku32FpFra1Para1Prof26;
extern const uint32  L9781_ku32FpFra1Para1Prof3;
extern const uint32  L9781_ku32FpFra1Para1Prof4;
extern const uint32  L9781_ku32FpFra1Para1Prof5;
extern const uint32  L9781_ku32FpFra1Para1Prof6;
extern const uint32  L9781_ku32FpFra1Para1Prof7;
extern const uint32  L9781_ku32FpFra1Para1Prof8;
extern const uint32  L9781_ku32FpFra1Para1Prof9;
extern const uint32  L9781_ku32FpFra1Para2Prof1;
extern const uint32  L9781_ku32FpFra1Para2Prof10;
extern const uint32  L9781_ku32FpFra1Para2Prof11;
extern const uint32  L9781_ku32FpFra1Para2Prof12;
extern const uint32  L9781_ku32FpFra1Para2Prof13;
extern const uint32  L9781_ku32FpFra1Para2Prof14;
extern const uint32  L9781_ku32FpFra1Para2Prof15;
extern const uint32  L9781_ku32FpFra1Para2Prof16;
extern const uint32  L9781_ku32FpFra1Para2Prof17;
extern const uint32  L9781_ku32FpFra1Para2Prof18;
extern const uint32  L9781_ku32FpFra1Para2Prof19;
extern const uint32  L9781_ku32FpFra1Para2Prof2;
extern const uint32  L9781_ku32FpFra1Para2Prof20;
extern const uint32  L9781_ku32FpFra1Para2Prof21;
extern const uint32  L9781_ku32FpFra1Para2Prof22;
extern const uint32  L9781_ku32FpFra1Para2Prof23;
extern const uint32  L9781_ku32FpFra1Para2Prof24;
extern const uint32  L9781_ku32FpFra1Para2Prof25;
extern const uint32  L9781_ku32FpFra1Para2Prof26;
extern const uint32  L9781_ku32FpFra1Para2Prof3;
extern const uint32  L9781_ku32FpFra1Para2Prof4;
extern const uint32  L9781_ku32FpFra1Para2Prof5;
extern const uint32  L9781_ku32FpFra1Para2Prof6;
extern const uint32  L9781_ku32FpFra1Para2Prof7;
extern const uint32  L9781_ku32FpFra1Para2Prof8;
extern const uint32  L9781_ku32FpFra1Para2Prof9;
extern const uint32  L9781_ku32FpFra1Para3Prof1;
extern const uint32  L9781_ku32FpFra1Para3Prof10;
extern const uint32  L9781_ku32FpFra1Para3Prof11;
extern const uint32  L9781_ku32FpFra1Para3Prof12;
extern const uint32  L9781_ku32FpFra1Para3Prof13;
extern const uint32  L9781_ku32FpFra1Para3Prof14;
extern const uint32  L9781_ku32FpFra1Para3Prof15;
extern const uint32  L9781_ku32FpFra1Para3Prof16;
extern const uint32  L9781_ku32FpFra1Para3Prof17;
extern const uint32  L9781_ku32FpFra1Para3Prof18;
extern const uint32  L9781_ku32FpFra1Para3Prof19;
extern const uint32  L9781_ku32FpFra1Para3Prof2;
extern const uint32  L9781_ku32FpFra1Para3Prof20;
extern const uint32  L9781_ku32FpFra1Para3Prof21;
extern const uint32  L9781_ku32FpFra1Para3Prof22;
extern const uint32  L9781_ku32FpFra1Para3Prof23;
extern const uint32  L9781_ku32FpFra1Para3Prof24;
extern const uint32  L9781_ku32FpFra1Para3Prof25;
extern const uint32  L9781_ku32FpFra1Para3Prof26;
extern const uint32  L9781_ku32FpFra1Para3Prof3;
extern const uint32  L9781_ku32FpFra1Para3Prof4;
extern const uint32  L9781_ku32FpFra1Para3Prof5;
extern const uint32  L9781_ku32FpFra1Para3Prof6;
extern const uint32  L9781_ku32FpFra1Para3Prof7;
extern const uint32  L9781_ku32FpFra1Para3Prof8;
extern const uint32  L9781_ku32FpFra1Para3Prof9;
extern const uint32  L9781_ku32FpFra1Para4Prof1;
extern const uint32  L9781_ku32FpFra1Para4Prof10;
extern const uint32  L9781_ku32FpFra1Para4Prof11;
extern const uint32  L9781_ku32FpFra1Para4Prof12;
extern const uint32  L9781_ku32FpFra1Para4Prof13;
extern const uint32  L9781_ku32FpFra1Para4Prof14;
extern const uint32  L9781_ku32FpFra1Para4Prof15;
extern const uint32  L9781_ku32FpFra1Para4Prof16;
extern const uint32  L9781_ku32FpFra1Para4Prof17;
extern const uint32  L9781_ku32FpFra1Para4Prof18;
extern const uint32  L9781_ku32FpFra1Para4Prof19;
extern const uint32  L9781_ku32FpFra1Para4Prof2;
extern const uint32  L9781_ku32FpFra1Para4Prof20;
extern const uint32  L9781_ku32FpFra1Para4Prof21;
extern const uint32  L9781_ku32FpFra1Para4Prof22;
extern const uint32  L9781_ku32FpFra1Para4Prof23;
extern const uint32  L9781_ku32FpFra1Para4Prof24;
extern const uint32  L9781_ku32FpFra1Para4Prof25;
extern const uint32  L9781_ku32FpFra1Para4Prof26;
extern const uint32  L9781_ku32FpFra1Para4Prof3;
extern const uint32  L9781_ku32FpFra1Para4Prof4;
extern const uint32  L9781_ku32FpFra1Para4Prof5;
extern const uint32  L9781_ku32FpFra1Para4Prof6;
extern const uint32  L9781_ku32FpFra1Para4Prof7;
extern const uint32  L9781_ku32FpFra1Para4Prof8;
extern const uint32  L9781_ku32FpFra1Para4Prof9;
extern const uint32  L9781_ku32FpFra2ConfCfg1;
extern const uint32  L9781_ku32FpFra2ConfCfg2;
extern const uint32  L9781_ku32FpFra2Para1Prof1;
extern const uint32  L9781_ku32FpFra2Para1Prof10;
extern const uint32  L9781_ku32FpFra2Para1Prof11;
extern const uint32  L9781_ku32FpFra2Para1Prof12;
extern const uint32  L9781_ku32FpFra2Para1Prof13;
extern const uint32  L9781_ku32FpFra2Para1Prof14;
extern const uint32  L9781_ku32FpFra2Para1Prof15;
extern const uint32  L9781_ku32FpFra2Para1Prof16;
extern const uint32  L9781_ku32FpFra2Para1Prof17;
extern const uint32  L9781_ku32FpFra2Para1Prof18;
extern const uint32  L9781_ku32FpFra2Para1Prof19;
extern const uint32  L9781_ku32FpFra2Para1Prof2;
extern const uint32  L9781_ku32FpFra2Para1Prof20;
extern const uint32  L9781_ku32FpFra2Para1Prof21;
extern const uint32  L9781_ku32FpFra2Para1Prof22;
extern const uint32  L9781_ku32FpFra2Para1Prof23;
extern const uint32  L9781_ku32FpFra2Para1Prof24;
extern const uint32  L9781_ku32FpFra2Para1Prof25;
extern const uint32  L9781_ku32FpFra2Para1Prof26;
extern const uint32  L9781_ku32FpFra2Para1Prof3;
extern const uint32  L9781_ku32FpFra2Para1Prof4;
extern const uint32  L9781_ku32FpFra2Para1Prof5;
extern const uint32  L9781_ku32FpFra2Para1Prof6;
extern const uint32  L9781_ku32FpFra2Para1Prof7;
extern const uint32  L9781_ku32FpFra2Para1Prof8;
extern const uint32  L9781_ku32FpFra2Para1Prof9;
extern const uint32  L9781_ku32FpFra2Para2Prof1;
extern const uint32  L9781_ku32FpFra2Para2Prof10;
extern const uint32  L9781_ku32FpFra2Para2Prof11;
extern const uint32  L9781_ku32FpFra2Para2Prof12;
extern const uint32  L9781_ku32FpFra2Para2Prof13;
extern const uint32  L9781_ku32FpFra2Para2Prof14;
extern const uint32  L9781_ku32FpFra2Para2Prof15;
extern const uint32  L9781_ku32FpFra2Para2Prof16;
extern const uint32  L9781_ku32FpFra2Para2Prof17;
extern const uint32  L9781_ku32FpFra2Para2Prof18;
extern const uint32  L9781_ku32FpFra2Para2Prof19;
extern const uint32  L9781_ku32FpFra2Para2Prof2;
extern const uint32  L9781_ku32FpFra2Para2Prof20;
extern const uint32  L9781_ku32FpFra2Para2Prof21;
extern const uint32  L9781_ku32FpFra2Para2Prof22;
extern const uint32  L9781_ku32FpFra2Para2Prof23;
extern const uint32  L9781_ku32FpFra2Para2Prof24;
extern const uint32  L9781_ku32FpFra2Para2Prof25;
extern const uint32  L9781_ku32FpFra2Para2Prof26;
extern const uint32  L9781_ku32FpFra2Para2Prof3;
extern const uint32  L9781_ku32FpFra2Para2Prof4;
extern const uint32  L9781_ku32FpFra2Para2Prof5;
extern const uint32  L9781_ku32FpFra2Para2Prof6;
extern const uint32  L9781_ku32FpFra2Para2Prof7;
extern const uint32  L9781_ku32FpFra2Para2Prof8;
extern const uint32  L9781_ku32FpFra2Para2Prof9;
extern const uint32  L9781_ku32FpFra2Para3Prof1;
extern const uint32  L9781_ku32FpFra2Para3Prof10;
extern const uint32  L9781_ku32FpFra2Para3Prof11;
extern const uint32  L9781_ku32FpFra2Para3Prof12;
extern const uint32  L9781_ku32FpFra2Para3Prof13;
extern const uint32  L9781_ku32FpFra2Para3Prof14;
extern const uint32  L9781_ku32FpFra2Para3Prof15;
extern const uint32  L9781_ku32FpFra2Para3Prof16;
extern const uint32  L9781_ku32FpFra2Para3Prof17;
extern const uint32  L9781_ku32FpFra2Para3Prof18;
extern const uint32  L9781_ku32FpFra2Para3Prof19;
extern const uint32  L9781_ku32FpFra2Para3Prof2;
extern const uint32  L9781_ku32FpFra2Para3Prof20;
extern const uint32  L9781_ku32FpFra2Para3Prof21;
extern const uint32  L9781_ku32FpFra2Para3Prof22;
extern const uint32  L9781_ku32FpFra2Para3Prof23;
extern const uint32  L9781_ku32FpFra2Para3Prof24;
extern const uint32  L9781_ku32FpFra2Para3Prof25;
extern const uint32  L9781_ku32FpFra2Para3Prof26;
extern const uint32  L9781_ku32FpFra2Para3Prof3;
extern const uint32  L9781_ku32FpFra2Para3Prof4;
extern const uint32  L9781_ku32FpFra2Para3Prof5;
extern const uint32  L9781_ku32FpFra2Para3Prof6;
extern const uint32  L9781_ku32FpFra2Para3Prof7;
extern const uint32  L9781_ku32FpFra2Para3Prof8;
extern const uint32  L9781_ku32FpFra2Para3Prof9;
extern const uint32  L9781_ku32FpIdleDlyCfg1;
extern const uint32  L9781_ku32FpIdleDlyCfg2;
extern const uint32  L9781_ku32FpProtConfCfg1;
extern const uint32  L9781_ku32FpProtConfCfg2;
extern const uint32  L9781_ku32FpZlcOcConfCfg1;
extern const uint32  L9781_ku32FpZlcOcConfCfg2;
extern const uint32  L9781_ku32GenConfCfg1;
extern const uint32  L9781_ku32GenConfCfg2;
extern const uint32  L9781_ku32IsenConfCfg1;
extern const uint32  L9781_ku32IsenConfCfg2;
extern const uint32  L9781_ku32PdrvConfCfg1;
extern const uint32  L9781_ku32PdrvConfCfg2;
extern const uint32  L9781_ku32PdrvEnbCfg1;
extern const uint32  L9781_ku32PdrvEnbCfg2;
extern const uint32  L9781_ku32ProtFiltCtrlCfg1;
extern const uint32  L9781_ku32ProtFiltCtrlCfg2;
extern const uint8  L9781_ku8DelayBeforeUnlock;
extern const uint8  L9781_ku8MaxSpiFailureNbAtInit;
extern const uint8  L9781_ku8VboostAuthDiagDly;
extern const uint16  L9781_ku16ClkToRstTime;
extern const uint16  L9781_ku16MaxBankFailure;
extern const uint16  L9781_ku16RstActiveTime;
extern const uint16  L9781_ku16RstToSpiTime;
extern const uint16  L9781_ku16VboostVoltHighLimit;
extern const uint16  L9781_ku16VboostVoltLowLimit;
extern const uint16  L9781_ku16WCbtChargeTime;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern uint8 L9781_enuLoadingState;
extern uint8 L9781_enuStartupState;
extern boolean L9781_abActStatus[L9781_ABACTSTATUS_COLS];
extern boolean L9781_abIrqActStatus[L9781_ABIRQACTSTATUS_COLS];
extern boolean L9781_abIrqIdleStatus[L9781_ABIRQIDLESTATUS_COLS];
extern boolean L9781_abOnlyOvlSpiDiagMode[L9781_ABONLYOVLSPIDIAGMODE_COLS];
extern boolean L9781_bCheckBuffer;
extern boolean L9781_bDiagOlBankAx;
extern boolean L9781_bDiagOlBankAy;
extern boolean L9781_bDiagOlBankBx;
extern boolean L9781_bDiagOlBankBy;
extern boolean L9781_bDiagOlBankFp;
extern boolean L9781_bDiagOvVbat;
extern boolean L9781_bDiagScGndBankAx;
extern boolean L9781_bDiagScGndBankAy;
extern boolean L9781_bDiagScGndBankBx;
extern boolean L9781_bDiagScGndBankBy;
extern boolean L9781_bDiagScGndBankFp;
extern boolean L9781_bDiagScVbBankAx;
extern boolean L9781_bDiagScVbBankAy;
extern boolean L9781_bDiagScVbBankBx;
extern boolean L9781_bDiagScVbBankBy;
extern boolean L9781_bDiagScVbBankFp;
extern boolean L9781_bDiagScVhsVlsBankAx;
extern boolean L9781_bDiagScVhsVlsBankAy;
extern boolean L9781_bDiagScVhsVlsBankBx;
extern boolean L9781_bDiagScVhsVlsBankBy;
extern boolean L9781_bDiagScVhsVlsBankFp;
extern boolean L9781_bDiagUvVbat;
extern boolean L9781_bEnabled;
extern boolean L9781_bEnableRequest;
extern boolean L9781_bFirstInitDone;
extern boolean L9781_bGdiAsicFullStopped;
extern boolean L9781_bReadDiagValid;
extern boolean L9781_bSpiAddressFail;
extern boolean L9781_bSpiComFailure;
extern boolean L9781_bSpiDataFail;
extern boolean L9781_bSpiFifoRequest;
extern boolean L9781_bSpiMswFrameTransmit;
extern boolean L9781_bSpiStartRequest;
extern boolean L9781_bSpiTxRequest;
extern boolean L9781_bStartupComplete;
extern boolean L9781_bStopModeActive;
extern uint32 L9781_u32SpiCorruptedAddress;
extern uint8 L9781_au8FifoSpiReqCh[L9781_AU8FIFOSPIREQCH_COLS];
extern uint8 L9781_au8FifoSpiReqTyp[L9781_AU8FIFOSPIREQTYP_COLS];
extern uint8 L9781_u8ComponentIndex;
extern uint8 L9781_u8ComponentToDiag;
extern uint8 L9781_u8InjFrameUpdtCnt;
extern uint8 L9781_u8InjProfileIndex;
extern uint8 L9781_u8NbSpiRequest;
extern uint8 L9781_u8PmpFrameUpdtCnt;
extern uint8 L9781_u8PmpProfileIndex;
extern uint8 L9781_u8SpiErrorCnt;
extern uint8 L9781_u8SpiFailureNbAtInit;
extern uint8 L9781_u8SpiFrameIndex;
extern uint8 L9781_u8VboostAuthDiagDcntr;
extern uint16 L9781_bfDiagComplete;
extern uint16 L9781_bfInjProfUpdated;
extern uint16 L9781_bfLoadDiagReq;
extern uint16 L9781_bfLoadInjProfReq;
extern uint16 L9781_bfLoadPmpProfReq;
extern uint16 L9781_bfLoadUnlockReq;
extern uint16 L9781_bfPmpProfUpdated;
extern uint16 L9781_u16SpiBufferRxLsw;
extern uint16 L9781_u16SpiBufferRxMsw;
extern uint16 L9781_u16SpiBufferTxLsw;
extern uint16 L9781_u16SpiBufferTxMsw;
extern uint16 L9781_u16SpiPrevFrameTxLsw;
extern uint16 L9781_u16SpiPrevFrameTxMsw;
extern uint16 L9781_u16VboostVoltage;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/



#endif /* L9781_L_H */

/*-------------------------------- end of file -------------------------------*/

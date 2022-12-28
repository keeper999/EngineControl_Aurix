/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Cfg_I.h                                                                                 */
/* !Description     : Internal Configuration of TLE8718 Component                                                     */
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
 * %PID: P2017_BSW:0A192582.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef TLE8718_CFG_I_H
#define TLE8718_CFG_I_H

#include "Std_Types.h"

#include "DGOHAL.h"
#include "IfxMsc_reg.h"
#include "Mcal_DmaLib.h"
#include "Mcal_DmaLib_Add_On.h"
#include "Msc_Add_On.h"
#include "TLE8718_L.h"
#include "TLE8718_Typ.h"

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

/* !MComment: Number Of TLE8718 Component Instances */
#define TLE8718_udtINSTANCE_NB           1u

/* !MComment: Definiton of DMA Channel Id Used to Receive Frames */
#define TLE8718_RX_DMA_CH                DMA_CHANNEL10

/* !MComment: Diagnoses of CC_VBat for PWMs are allowed only above the duty threashold TLE8718_DudtUTY_DIAG_MIN       */
/*            For a maximal frequency of 300Hz, maximal masking time = 135us ie a duty cycle of 4.05% = 1328dec       */
#define TLE8718_udtDUTY_DIAG_MIN         1328u

/* !MComment: Diagnoses of CC_Gnd and OC for PWMs are allowed only below the duty threashold TLE8718_udtDUTY_DIAG_MAX */
/*            For a maximal frequency of 300Hz, maximal masking time = 135us ie a duty cycle of 95.95% = 31440dec     */
#define TLE8718_udtDUTY_DIAG_MAX         31440u

/* !MComment: Configuration Of TLE8718 Behavior In Case Of Short Circuit To   */
/*            Battery Voltage. Allowed Values:                                */
/*             - TLE8718_OUTPUT_SWITCH_OFF                                    */
/*             - TLE8718_LIMITED_CURRENT                                      */
#define TLE8718_OUT1_SCB                 TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT2_SCB                 TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT3_SCB                 TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT4_SCB                 TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT5_SCB                 TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT6_SCB                 TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT7_SCB                 TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT8_SCB                 TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT9_SCB                 TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT10_SCB                TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT11_SCB                TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT12_SCB                TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT13_SCB                TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT14_SCB                TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT15_SCB                TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT16_SCB                TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT17_SCB                TLE8718_OUTPUT_SWITCH_OFF
#define TLE8718_OUT18_SCB                TLE8718_OUTPUT_SWITCH_OFF

/* !MComment: Configuration Of The Switch On/Off Of The Internal Diagnostic   */
/*            Pull-Down Current Source. Diagnosis Of OL Is Deactivated If Off */
/*            Allowed Values:                                                 */
/*             - TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_ENABLED             */
/*             - TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_DISABLED            */
#define TLE8718_OUT11_DIAC     TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_ENABLED
#define TLE8718_OUT12_DIAC     TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_ENABLED
#define TLE8718_OUT13_DIAC     TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_ENABLED
#define TLE8718_OUT14_DIAC     TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_ENABLED
#define TLE8718_OUT15_DIAC     TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_ENABLED
#define TLE8718_OUT16_DIAC     TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_ENABLED
#define TLE8718_OUT17_DIAC     TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_ENABLED
#define TLE8718_OUT18_DIAC     TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_ENABLED

/* !MComment: Configuration Of Rising Edge Filter Time Before Switching       */
/*            DELAYOUT Or RES15_16. Allowed Values:                           */
/*             - TLE8718_LONG_FILTER_TIME                                     */
/*             - TLE8718_SHORT_FILTER_TIME                                    */
#define TLE8718_DELAYIN_FIL              TLE8718_SHORT_FILTER_TIME

/* !MComment: VOUTn Is Checked In Addition To IOUTn And The Diagnosis Register*/
/*            SCB Is Only Set, If IOUTn_max And VOL Is Reached For Longer Than*/
/*            tDIAG_SCB. This Feature Is Available For OUT5...14 Only.        */
/*            Allowed Values:                                                 */
/*             - TLE8718_EXTENDED_SCB_ENABLED                                 */
/*             - TLE8718_EXTENDED_SCB_DISABLED                                */
#define TLE8718_EXT_SCB                  TLE8718_EXTENDED_SCB_DISABLED 

/* !MComment: Configuration Of DELAYIN - Filtering Time Before Switching      */
/*            DELAYOUT Low. Allowed Values:                                   */
/*             - TLE8718_LONG_DELAY                                           */
/*             - TLE8718_MEDIUM_LONG_DELAY                                    */
/*             - TLE8718_SHORT_LONG_DELAY                                     */
/*             - TLE8718_SHORT_DELAY                                          */
#define TLE8718_DELAYIN_CONF             TLE8718_SHORT_DELAY

/* !MComment: Configuration Of Upstream Divider                               */
/*            Allowed Values:                                                 */
/*             - TLE8718_CLOCK_DIV_16                                         */
/*             - TLE8718_CLOCK_DIV_32                                         */
/*             - TLE8718_CLOCK_DIV_64                                         */
/*             - TLE8718_CLOCK_DIV_128                                        */
#define TLE8718_FCL_CONF                 TLE8718_CLOCK_DIV_32

/* !MComment: Configuration Of Delay  For ABE and VDD monitoring To disable   */
/*            All Outputs. Allowed Values:                                    */
/*             - TLE8718_DISA_OUTPUT_SHORT_DELAY                              */
/*             - TLE8718_DISA_OUTPUT_LONG_DELAY                               */
#define TLE8718_ABE_IMPACT               TLE8718_DISA_OUTPUT_LONG_DELAY

/* !MComment: Configuration Of Enable Of VDD Monitoring Test                  */
/*            Allowed Values:                                                 */
/*             - TLE8718_VDD_MONITORING_DISABLED                              */
/*             - TLE8718_VDD_MONITORING_ENABLED                               */
#define TLE8718_MON_TEST                 TLE8718_VDD_MONITORING_DISABLED

/* !MComment: Configuration Of Enable Of Overvoltage And Undervoltage Tests   */
/*            Allowed Values:                                                 */
/*             - TLE8718_TEST_OVERVOLTAGE_THRESH                              */
/*             - TLE8718_TEST_UNDERVOLTAGE_THRESH                             */
#define TLE8718_MON_THRES                TLE8718_TEST_OVERVOLTAGE_THRESH

/* !MComment: Configuration Of Behavior Of The ABE Level And Output Stages On */
/*            The Return Of VDD From Overvoltage To The Correct Range.        */
/*            Allowed Values:                                                 */
/*             - TLE8718_ABE_LATCHED_AND_OUTPUTS_REMAIN_OFF                   */
/*             - TLE8718_ABE_INACTIVE                                         */
#define TLE8718_MON_LATCH      TLE8718_ABE_LATCHED_AND_OUTPUTS_REMAIN_OFF

/* !MComment: Configuration Of Enable Of Restart Timeout Counter For Delayed  */
/*            Reset Behavior. Available for OUT15 and OUT16 Only.             */
/*            Allowed Values:                                                 */
/*             - TLE8718_DELAYED_RESET_ON                                     */
/*             - TLE8718_DELAYED_RESET_OFF                                    */
#define TLE8718_OUT15_DELAY              TLE8718_DELAYED_RESET_OFF
#define TLE8718_OUT16_DELAY              TLE8718_DELAYED_RESET_OFF

/**********************************************************************************************************************/
/*  INTERNAL MACRO FUNCTIONS                                                                                          */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMSC_ENA_TX_CMD_IT                                                                        */
/* !Description : Enables MSC Cmd Frame Tx IT                                                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define TLE8718_vidMSC_ENA_TX_CMD_IT(udtInstance) \
do \
{ \
   Msc_vidEnaTxInterrupt(TLE8718_kau8Module[udtInstance]); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMSC_DISA_TX_CMD_IT                                                                       */
/* !Description : Disables MSC Cmd Frame Tx IT                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define TLE8718_vidMSC_DISA_TX_CMD_IT(udtInstance) \
do \
{ \
   Msc_vidDisaTxInterrupt(TLE8718_kau8Module[udtInstance]); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMSC_ENA_RX_FRAME_IT                                                                      */
/* !Description : Enables MSC Frame Rx IT                                                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define TLE8718_vidMSC_ENA_RX_FRAME_IT(udtInstance, u8RxFrameNb) \
do \
{ \
   /* DMA Configuration Beginning */ \
   uint32 u32LocalRxDataRegAddress;                                                                                \
   Msc_vidGetRxDataRegAddress(TLE8718_kau8Module[udtInstance], &u32LocalRxDataRegAddress);                         \
   Mcal_DmaSetSourceAddr(TLE8718_RX_DMA_CH, u32LocalRxDataRegAddress);        /* Source address */                 \
   Mcal_DmaSetDestAddr(TLE8718_RX_DMA_CH,   (uint32)&TLE8718_au32MscRxFrame); /* Destination address */            \
   Mcal_DmaSetDataWidth(TLE8718_RX_DMA_CH,  2u);                              /* Size = 32 bits */                 \
   Mcal_DmaCfgNoOfMovesPerTransfer(TLE8718_RX_DMA_CH, 1u);                    /* 1 Move by Transfer */             \
   Mcal_DmaSetTxCount(TLE8718_RX_DMA_CH, u8RxFrameNb);                        /* Number of Transfers */            \
   Mcal_DmaSetRroat(TLE8718_RX_DMA_CH,   0u); /* Write the PROAT = 0: one Transfer Per Request */                  \
   Mcal_DmaSetPrsel(TLE8718_RX_DMA_CH,   0u); /* Write the PRSEL = 0: Ch Request Sel_peripheral */                 \
   Mcal_DmaSetChmode(TLE8718_RX_DMA_CH,  0u); /* Write the CHMODE = 0: Single  Mode */                             \
   Mcal_DmaSetAdicr(TLE8718_RX_DMA_CH,                                                                             \
                    (0u         | /* Source Address Modification Factor: Address offset is 1 x MExCHCR.CHDW */     \
                    (1u  << 3u) | /* Increment of Source Address */                                                \
                    (0u  << 6u) | /* Dest Address Modification Factor: Address offset is 1 x MExCHCR.CHDW */       \
                    (1u  << 7u) | /* Increment of Dest Address */                                                  \
                    (0u  << 8u) | /* Circular Buffer Length Source: Source address SADR[31:0] is not updated */    \
                    (0u  << 12u)| /* Circular Buffer Length Dest: Destination address DADR[31:0] is not updated */ \
                    (0u  << 16u)| /* Shadow Control: Source and destination registers written directly. */         \
                    (1u  << 20u)| /* Source Circular Buffer Enable */                                              \
                    (0u  << 21u)| /* Dest Circular Buffer Disable */                                               \
                    (0u  << 22u)| /* Time Stamp Disabled */                                                        \
                    (0u  << 23u)| /* Disable Transaction Request Lost Interrupt */                                 \
                    (0u  << 24u)| /* Wrap Source Disabled */                                                       \
                    (0u  << 25u)| /* Wrap Dest Disabled */                                                         \
                    (2u  << 26u)| /* Interrupt Control: Interrupt trigger is generated when TCOUNT equals IRDV */  \
                    (0u  << 28u)  /* Threshold Limit of CHSRz.TCOUNT to triggger and IT: = 0 */));                 \
   Mcal_DmaChClrIntrFlags(TLE8718_RX_DMA_CH);                                                                      \
   Mcal_DmaEnableHwTransfer(TLE8718_RX_DMA_CH);                                                                    \
   Mcal_DmaEnableIntr(TLE8718_RX_DMA_CH);                                                                          \
   /* DMA Configuration End */ \
   Msc_vidEnaRxInterrupt(TLE8718_kau8Module[udtInstance]); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMSC_DISA_RX_FRAME_IT                                                                     */
/* !Description : Disables MSC Frame Rx IT                                                                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define TLE8718_vidMSC_DISA_RX_FRAME_IT(udtInstance) \
do \
{ \
   Msc_vidDisaRxInterrupt(TLE8718_kau8Module[udtInstance]); \
   Mcal_DmaResetDmaChannel(TLE8718_RX_DMA_CH); \
   Mcal_DmaDisableIntr(TLE8718_RX_DMA_CH); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMSC_START_TIMEOUT_IT                                                                     */
/* !Description : Starts MSC Timeout Interrupt For Rx&Tx Frames                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define TLE8718_vidMSC_START_TIMEOUT_IT(udtInstance) \
do \
{ \
   Msc_vidStartRxTimeoutAlarm(TLE8718_kau8Module[udtInstance]); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMSC_STOP_TIMEOUT_IT                                                                      */
/* !Description : Stops MSC Timeout Interrupt For Rx&Tx Frames                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define TLE8718_vidMSC_STOP_TIMEOUT_IT(udtInstance) \
do \
{ \
   Msc_vidStopRxTimeoutAlarm(TLE8718_kau8Module[udtInstance]); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDISA_TLE8718                                                                             */
/* !Description : Disables TLE8718 component                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define TLE8718_vidDISA_TLE8718(udtInstance) \
do \
{ \
   /* !Comment: Apply low level on ABE pin */ \
   Dio_WriteChannel(TLE8718_kaudtAbeDioChannel[udtInstance], STD_LOW); \
   /* !Comment: Apply low level on Dis5_10 pin */ \
   /* Dis5_10 input of TLE8718 is plugged to VCC_5V */ \
   /*Dio_WriteChannel(TLE8718_kaudtDis5_10DioChannel[udtInstance], STD_LOW);*/ \
} \
while (0u)
 
/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidENA_TLE8718                                                                              */
/* !Description : Enables TLE8718 component                                                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define TLE8718_vidENA_TLE8718(udtInstance) \
do \
{ \
   /* !Comment: Apply high level on ABE pin */ \
   Dio_WriteChannel(TLE8718_kaudtAbeDioChannel[udtInstance], STD_HIGH); \
   /* !Comment: Apply high level on Dis5_10 pin */ \
   Dio_WriteChannel(TLE8718_kaudtDis5_10DioChannel[udtInstance], STD_HIGH); \
} \
while (0u)

#endif /* TLE8718_CFG_I_H */

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/

/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_Spi.h                                                                                     */
/* !Description     : Low layer SPI protocol                                                                          */
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
 * %PID: LIBEMB:A6093.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
#ifndef L9960_SPI_H
#define L9960_SPI_H

#include "Std_Types.h"
#include "Spi.h"
#include "L9960.h"
#include "L9960_Private.h"
#include "L9960_Types.h"
#include "SchM_L9960.h"


/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

/* READ command : we can define the whole 16 bits to send                                                             */
#define L9960_u16SPI_CMD_READ_OVERCURRENT       0x1000u
#define L9960_u16SPI_CMD_READ_CONFIG_1          0x7003u
#define L9960_u16SPI_CMD_READ_CONFIG_2          0x7005u
#define L9960_u16SPI_CMD_READ_CONFIG_3          0x7009u
#define L9960_u16SPI_CMD_READ_CONFIG_4          0x7011u
#define L9960_u16SPI_CMD_READ_CONFIG_5          0x7021u
#define L9960_u16SPI_CMD_READ_STATE_1           0x8000u
#define L9960_u16SPI_CMD_READ_STATE_2           0x8003u
#define L9960_u16SPI_CMD_READ_STATE_3           0x8005u

#define L9960_u16SPI_CMD_READ_CMP_TRACA_1       0xD000u
#define L9960_u16SPI_CMD_READ_CMP_TRACA_2       0xD003u

#define L9960_u16SPI_CMD_READ_ASIC_NAME         0xF001u
#define L9960_u16SPI_CMD_READ_ASIC_VERSION      0xF002u
#define L9960_u16SPI_CMD_READ_VHDL_VERSION      0xF004u


/* Select the command to send for the dummy frame */
#define L9960_u16DUMMY_FRAME_CMD L9960_u16SPI_CMD_READ_ASIC_NAME

/* WRITE Command: some bits are fixed (like address) and other dependent of need (configuration) */
/* We create 2 define, one for a mask to choose modifiable bits          */
/* And one with register value at reset (without parity bit) : the word to send is ( xxx_POR_VALUE_xxx | (xxx_MASK_xxx & value))      */
#define L9960_u16SPI_POR_VALUE_RESTART_TRIGGER   0x2100u
#define L9960_u16SPI_MASK_RESTART_TRIGGER        0x0F00u

#define L9960_u16SPI_POR_VALUE_CONFIG_1          0x35FEu
#define L9960_u16SPI_MASK_CONFIG_1               0x0FFAu

#define L9960_u16SPI_POR_VALUE_CONFIG_2          0x4000u
#define L9960_u16SPI_MASK_CONFIG_2               0x0FFAu

#define L9960_u16SPI_POR_VALUE_CONFIG_3          0x5780u
#define L9960_u16SPI_MASK_CONFIG_3               0x0F82u

#define L9960_u16SPI_POR_VALUE_CONFIG_4          0x6000u
#define L9960_u16SPI_MASK_CONFIG_4               0x0C00u /* TODO: bit D8 to D0 not specified */

#define L9960_u16SPI_POR_VALUE_OFF_STATE_DIAG    0x9000u
#define L9960_u16SPI_MASK_OFF_STATE_DIAG         0x0002u


/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* Basic command of SPI handler                                                                                       */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
#define L9960_START_SEC_CODE
#include "L9960_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
extern uint16 L9960_SpiConstructWordToSend(uint16 u16SpiDefaultValue, uint16 u16SpiMask, uint16 u16SpiData);
extern void L9960_vidSpiTxConfirmation(const L9960_tstrConfig *pkstrConfig,
                                       L9960_strData          *pstrData,
                                       uint16                  u16ReceiveData);
extern void L9960_vidSpiResetErrorCounter(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);

extern void L9960_vidSpiInit(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);


/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiTransmit                                                                                */
/* !Description : Save the command to send (for a re-try if needed), and send the command on SPI bus                  */
/*                This function mustn't be called by L9960_SpiM                                                       */
/*                It is an internal fonction of L9960_Spi (low layer)                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiTransmit(const L9960_tstrConfig *pkstrConfig,
                                       L9960_strData          *pstrData,
                                       uint16                  u16SpiInstruction)
{
   pstrData->u16SpiLastSentCommand = u16SpiInstruction;

   /* bit set to TRUE when we send the Dummy frame */
   pstrData->bSpiDummyFrameSent = FALSE;

   /* TODO: check the return value ?? */
   (void)Spi_WriteIB(pkstrConfig->udtSpiChannelId, (const uint8 *)(&u16SpiInstruction) );
   (void)Spi_AsyncTransmit(pkstrConfig->udtSpiSequenceId);
}


/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdOverCurrent                                                                      */
/* !Description : send the word #1 id                                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdOvercurrent(const L9960_tstrConfig *pkstrConfig,
                                                 L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_OVERCURRENT);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdRestartTrigger                                                                   */
/* !Description : send the word #2 id                                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdRestartTrigger(const L9960_tstrConfig *pkstrConfig,
                                                    L9960_strData          *pstrData,
                                                    uint16                  u16DataToSend)
{
   uint16 u16LocData;
   u16LocData = L9960_SpiConstructWordToSend(L9960_u16SPI_POR_VALUE_RESTART_TRIGGER,
                                             L9960_u16SPI_MASK_RESTART_TRIGGER,
                                             u16DataToSend);
   L9960_vidSpiTransmit(pkstrConfig, pstrData, u16LocData);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdConfig1                                                                          */
/* !Description : send the word #3 id                                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdConfig1(const L9960_tstrConfig *pkstrConfig,
                                             L9960_strData          *pstrData,
                                             uint16                  u16DataToSend)
{
   uint16 u16LocData;

   u16LocData = L9960_SpiConstructWordToSend(L9960_u16SPI_POR_VALUE_CONFIG_1,
                                             L9960_u16SPI_MASK_CONFIG_1,
                                             u16DataToSend);
   L9960_vidSpiTransmit(pkstrConfig, pstrData, u16LocData);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdConfig2                                                                          */
/* !Description : send the word #4 id                                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdConfig2(const L9960_tstrConfig *pkstrConfig,
                                             L9960_strData          *pstrData,
                                             uint16                  u16DataToSend)
{
   uint16 u16LocData;

   u16LocData = L9960_SpiConstructWordToSend(L9960_u16SPI_POR_VALUE_CONFIG_2,
                                             L9960_u16SPI_MASK_CONFIG_2,
                                             u16DataToSend);
   L9960_vidSpiTransmit(pkstrConfig, pstrData, u16LocData);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdConfig3                                                                          */
/* !Description : send the word #5 id                                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdConfig3(const L9960_tstrConfig *pkstrConfig,
                                             L9960_strData          *pstrData,
                                             uint16                  u16DataToSend)
{
   uint16 u16LocData;

   u16LocData = L9960_SpiConstructWordToSend(L9960_u16SPI_POR_VALUE_CONFIG_3,
                                             L9960_u16SPI_MASK_CONFIG_3,
                                             u16DataToSend);
   L9960_vidSpiTransmit(pkstrConfig, pstrData, u16LocData);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdConfig4                                                                          */
/* !Description : send the word #6 id                                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdConfig4(const L9960_tstrConfig *pkstrConfig,
                                             L9960_strData          *pstrData,
                                             uint16                  u16DataToSend)
{
   uint16 u16LocData;

   u16LocData = L9960_SpiConstructWordToSend(L9960_u16SPI_POR_VALUE_CONFIG_4,
                                             L9960_u16SPI_MASK_CONFIG_4,
                                             u16DataToSend);
   L9960_vidSpiTransmit(pkstrConfig, pstrData, u16LocData);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdConfigReq1                                                                       */
/* !Description : send the word #7a id                                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdConfigReq1(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_CONFIG_1);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdConfigReq2                                                                       */
/* !Description : send the word #7b id                                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdConfigReq2(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_CONFIG_2);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdConfigReq3                                                                       */
/* !Description : send the word #7c id                                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdConfigReq3(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_CONFIG_3);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdConfigReq4                                                                       */
/* !Description : send the word #7d id                                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdConfigReq4(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_CONFIG_4);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdConfigReq5                                                                       */
/* !Description : send the word #7e id                                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdConfigReq5(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_CONFIG_5);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdStateReq1                                                                        */
/* !Description : send the word #8a id                                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdStateReq1(const L9960_tstrConfig *pkstrConfig,
                                               L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_STATE_1);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdStateReq2                                                                        */
/* !Description : send the word #8b id                                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdStateReq2(const L9960_tstrConfig *pkstrConfig,
                                               L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_STATE_2);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdStateReq3                                                                        */
/* !Description : send the word #8c id                                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdStateReq3(const L9960_tstrConfig *pkstrConfig,
                                               L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_STATE_3);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdOffStateDiag                                                                     */
/* !Description : send the word #9 id                                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdOffStateDiag(const L9960_tstrConfig *pkstrConfig,
                                                  L9960_strData          *pstrData,
                                                  uint16                  u16DataToSend)
{
   uint16 u16LocData;

   u16LocData = L9960_SpiConstructWordToSend(L9960_u16SPI_POR_VALUE_OFF_STATE_DIAG,
                                             L9960_u16SPI_MASK_OFF_STATE_DIAG,
                                             u16DataToSend);
   L9960_vidSpiTransmit(pkstrConfig, pstrData, u16LocData);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdTraceNbReq1                                                                      */
/* !Description : send the word #13a id                                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdTraceNbReq1(const L9960_tstrConfig *pkstrConfig,
                                                 L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_CMP_TRACA_1);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdTraceNbReq2                                                                      */
/* !Description : send the word #13b id                                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdTraceNbReq2(const L9960_tstrConfig *pkstrConfig,
                                                 L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_CMP_TRACA_2);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdAsicNameReq                                                                      */
/* !Description : send the word #15a id                                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdAsicNameReq(const L9960_tstrConfig *pkstrConfig,
                                               L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_ASIC_NAME);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdAsicVerReq                                                                       */
/* !Description : send the word #15b id                                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdAsicVerReq(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_ASIC_VERSION);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiSendCmdVhdlVerReq                                                                       */
/* !Description : send the word #15c id                                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiSendCmdVhdlVerReq(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData          *pstrData)
{
   L9960_vidSpiTransmit(pkstrConfig, pstrData, L9960_u16SPI_CMD_READ_VHDL_VERSION);
}


/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiTransmit                                                                                */
/* !Description : Save the command to send (for a re-try if needed), and send the command on SPI bus                  */
/*                This function mustn't be called by L9960_SpiM                                                       */
/*                It is an internal fonction of L9960_Spi (low layer)                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiTransmitDummyFrame(const L9960_tstrConfig *pkstrConfig,
                                                 L9960_strData          *pstrData)
{
   uint16 u16Loc = L9960_u16DUMMY_FRAME_CMD;
   /* bit set to TRUE when we send the Dummy frame */
   pstrData->bSpiDummyFrameSent = TRUE;

   /* TODO: check the return value ?? */
   (void)Spi_WriteIB(pkstrConfig->udtSpiChannelId, (const uint8 *)(&u16Loc) );
   (void)Spi_AsyncTransmit(pkstrConfig->udtSpiSequenceId);
}

/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* High Level command of SPI handler                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiStartHWSC                                                                               */
/* !Description : This function send a HWSC request                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpiStartHWSC(const L9960_tstrConfig *pkstrConfig,
                                        L9960_strData          *pstrData)
{
   /* Don't change CC config, don't touch to reset trig, just set the HWSC bit */
   L9960_vidSpiSendCmdRestartTrigger(pkstrConfig, pstrData, L9960_u16SPI_POR_VALUE_RESTART_TRIGGER
                                                          | L9960_u16SPI_RESTART_TRIGGER_HWSC_TRIG);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpi_StartOpenLoadOnDiag                                                                    */
/* !Description : This function send a HWSC request                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpi_StartOpenLoadOnDiag(const L9960_tstrConfig *pkstrConfig,
                                                   L9960_strData          *pstrData)
{
   /* TODO: the TDSR bit is set once in u16SpiMChipRegConfiguration4, so if corrupted, we corrupt the L9960 config */
   
   /* TODO: temporary quick patch : the open load report failure when DIR pin value change       */
   /* ST confirmed to not perform Open load detection when DIR pin change.                       */
   /* this patch remove the open load diag request, and a better solution must be found (change  */
   /* the sequence)                                                                              */
   /*
   L9960_vidSpiSendCmdConfig4(pkstrConfig, pstrData, pstrData->u16SpiMChipRegConfiguration4
                                                          | L9960_u16SPI_CONFIG_REG_4_OL_ON_MASK);
   */
   L9960_vidSpiSendCmdConfig4(pkstrConfig, pstrData, pstrData->u16SpiMChipRegConfiguration4);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpi_StartOffStateDiag                                                                      */
/* !Description : This function send a Off State Diag Request                                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidSpi_StartOffStateDiag(const L9960_tstrConfig *pkstrConfig,
                                                 L9960_strData          *pstrData)
{
   L9960_vidSpiSendCmdOffStateDiag(pkstrConfig, pstrData, L9960_bfOFF_DIAG_TRIG_BIT);
}

#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"

#endif /* L9960_SPI_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

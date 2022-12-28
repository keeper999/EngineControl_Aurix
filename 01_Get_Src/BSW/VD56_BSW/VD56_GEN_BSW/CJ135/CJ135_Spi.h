/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_Spi.h                                                                                     */
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
 * %PID: P2017_BSW:0A188678.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
#ifndef CJ135_SPI_H
#define CJ135_SPI_H

#include "Std_Types.h"
#include "Spi.h"
#include "CJ135.h"
#include "CJ135_Private.h"
#include "CJ135_Types.h"
#include "SchM_CJ135.h"


/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

/* 16 bit instructions (01 6bit instr << 8)                                 */
/* 8 bits register write frame is made of CJ135_u16CMD_WR_<xxx> + data      */
/* 8 bits register read frame is made of only CJ135_u16CMD_RD_<xxx>         */
/* 16 bits register read frame is made of CJ135_u16CMD_RD_REGISTER + adress */
/* RAM read frame is made of CJ135_u16CMD_RD_RAM + adress                   */
/* 16 bits register write is a sequence of three frames :                   */
/* high byte frame : CJ135_u16CMD_WR_HIGHBYTE + high_byte_data              */
/* low byte frame : CJ135_u16CMD_WR_LOWBYTE + low_byte_data                 */
/* adress frame : CJ135_u16CMD_WR_ADDRESS + adress                          */
#define CJ135_u16CMD_RD_IDENT           16384 /* 0x4000 */
#define CJ135_u16CMD_RD_REV             17664 /* 0x4500 */
#define CJ135_u16CMD_RD_HW_REV          18688 /* 0x4900 */
#define CJ135_u16CMD_SW_RST             18944 /* 0x4A00 */
#define CJ135_u16CMD_RD_CHIPSTAT        19456 /* 0x4C00 */
#define CJ135_u16CMD_WR_LOCK            20224 /* 0x4F00 */
#define CJ135_u16CMD_RD_DIAG0           20736 /* 0x5100 */
#define CJ135_u16CMD_WR_HIGHBYTE        20992 /* 0x5200 */
#define CJ135_u16CMD_RD_DSPSTAT         21504 /* 0x5400 */
#define CJ135_u16CMD_WR_LOWBYTE         22272 /* 0x5700 */
#define CJ135_u16CMD_WR_ADDRESS         23296 /* 0x5B00 */
#define CJ135_u16CMD_RD_REGISTER        23808 /* 0x5D00 */
#define CJ135_u16CMD_RD_RAM             24832 /* 0x6100 */
#define CJ135_u16CMD_RD_DIAG1           25600 /* 0x6400 */

/* 8 bits register values                   */
/* TBD : remove and replace by calibrations */
#define CJ135_u8REG_SW_RST_B             0x00 /*TBD*/
#define CJ135_u8REG_LOCK_B               0x00 /*TBD*/

/* 8 bit adresses for 16 bits registers (01 6bit instr << 8) */
#define CJ135_u8REG_ADDR_MODE               0 /* 0x00 */
#define CJ135_u8REG_ADDR_UNSET              3 /* 0x03 */
#define CJ135_u8REG_ADDR_UEGO0              5 /* 0x05 */
#define CJ135_u8REG_ADDR_UEGO1              6 /* 0x06 */
#define CJ135_u8REG_ADDR_UEGO2              9 /* 0x09 */
#define CJ135_u8REG_ADDR_UP0LEAN           10 /* 0x0A */
#define CJ135_u8REG_ADDR_UP0RICH           12 /* 0x0C */
#define CJ135_u8REG_ADDR_UEGO3             15 /* 0x0F */
#define CJ135_u8REG_ADDR_UEGO4             17 /* 0x11 */
#define CJ135_u8REG_ADDR_UEGO5             18 /* 0x12 */
#define CJ135_u8REG_ADDR_IPOFF             20 /* 0x14 */
#define CJ135_u8REG_ADDR_STEERPAT          23 /* 0x17 */
#define CJ135_u8REG_ADDR_CONFIGDSP         24 /* 0x18 */
#define CJ135_u8REG_ADDR_TRIM              27 /* 0x1B */
#define CJ135_u8REG_ADDR_REFPAT            29 /* 0x1D */
#define CJ135_u8REG_ADDR_FREE              30 /* 0x1E */
#define CJ135_u8REG_ADDR_ACTUAL_MODE       33 /* 0x21 */

/* RAM adresses                                               */
/* RAM read frame is made of CJ135_u16CMD_RD_RAM + RAM adress */
#define CJ135_u8RAM_ADDR_MODE               0 /* 0x00 */
#define CJ135_u8RAM_ADDR_NORMAL3_IP1        3 /* 0x03 */
#define CJ135_u8RAM_ADDR_NORMAL3_URIE      17 /* 0x11 */
#define CJ135_u8RAM_ADDR_NORMAL3_IP2       23 /* 0x17 */
#define CJ135_u8RAM_ADDR_NORMAL3_UG0       29 /* 0x1D */
#define CJ135_u8RAM_ADDR_NORMAL3_UN0       34 /* 0x22 */
#define CJ135_u8RAM_ADDR_NORMAL3_IP3       40 /* 0x28 */
#define CJ135_u8RAM_ADDR_NORMAL3_IP4       58 /* 0x3A */
#define CJ135_u8RAM_ADDR_NORMAL3_UCAL      78 /* 0x4E */
#define CJ135_u8RAM_ADDR_NORMAL3_IP5       86 /* 0x56 */

#define CJ135_u8RAM_ADDR_WARMUP_URIE       51 /* 0x33 */
#define CJ135_u8RAM_ADDR_WARMUP_UN0        48 /* 0x30 */
#define CJ135_u8RAM_ADDR_WARMUP_UCAL       40 /* 0x28 */


/* Select the command to send for the dummy frame */
#define CJ135_u16DUMMY_FRAME_CMD CJ135_u16CMD_RD_IDENT

/**********************************************************************************************************************/
/* MACROS                                                                                                             */
/**********************************************************************************************************************/
#define CJ135_u16SelectHighByte(u16RegisterValue) ((u16RegisterValue)>>8)

#define CJ135_u16SelectLowByte(u16RegisterValue) ((u16RegisterValue)&0x00FFu)

/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* Basic command of SPI handler                                                                                       */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/


#define CJ135_START_SEC_CODE
#include "CJ135_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
extern void CJ135_vidSpiTxConfirmation(const CJ135_tstrConfig *pkstrConfig,
                                       CJ135_strData          *pstrData,
                                       uint16                  u16ReceiveData);
extern void CJ135_vidSpiResetErrorCounter(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);

extern void CJ135_vidSpiInit(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiTransmit                                                                                */
/* !Description : Save the command to send (for a re-try if needed), and send the command on SPI bus                  */
/*                This function mustn't be called by CJ135_SpiM                                                       */
/*                It is an internal fonction of CJ135_Spi (low layer)                                                 */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiTransmit(const CJ135_tstrConfig *pkstrConfig,
                                       CJ135_strData          *pstrData,
                                       uint16                  u16SpiInstruction)
{
   pstrData->u16SpiLastSentCommand = u16SpiInstruction;

   /* TODO: check the return value ?? */
   (void)Spi_WriteIB(pkstrConfig->udtSpiChannelId, (const uint8 *)(&u16SpiInstruction) );
   (void)Spi_AsyncTransmit(pkstrConfig->udtSpiSequenceId);
}

/**********************************************************************************************************************/
/**********************************************************************************************************************/
/** 8 bits register write frames                                                                                     **/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWriteSwRst                                                                       */
/* !Description : Send the write Sw Rst cmd                                                                           */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWriteSwRst(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_SW_RST + CJ135_u8REG_SW_RST_B);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWriteLock                                                                        */
/* !Description : Send the write Lock cmd                                                                             */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWriteLock(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOCK + CJ135_u8REG_LOCK_B);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/**********************************************************************************************************************/
/** 8 bits register read frame                                                                                       **/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadIdent                                                                        */
/* !Description : Send the read ident cmd                                                                             */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadIdent(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   CJ135_vidSpiTransmit(pkstrConfig, pstrData, CJ135_u16CMD_RD_IDENT);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRev                                                                          */
/* !Description : Send the read rev cmd                                                                               */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRev(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   CJ135_vidSpiTransmit(pkstrConfig, pstrData, CJ135_u16CMD_RD_REV);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadHwRev                                                                        */
/* !Description : Send the read hw rev cmd                                                                            */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadHwRev(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   CJ135_vidSpiTransmit(pkstrConfig, pstrData, CJ135_u16CMD_RD_HW_REV);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadChipstat                                                                     */
/* !Description : Send the read chipstat reg cmd                                                                      */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadChipstat(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   CJ135_vidSpiTransmit(pkstrConfig, pstrData, CJ135_u16CMD_RD_CHIPSTAT);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadDiag0                                                                        */
/* !Description : Send the read diag0 reg cmd                                                                         */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadDiag0(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   CJ135_vidSpiTransmit(pkstrConfig, pstrData, CJ135_u16CMD_RD_DIAG0);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadDSPStat                                                                      */
/* !Description : Send the read dspstat reg cmd                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadDSPStat(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   CJ135_vidSpiTransmit(pkstrConfig, pstrData, CJ135_u16CMD_RD_DSPSTAT);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadDiag1                                                                        */
/* !Description : Send the read diag1 reg cmd                                                                         */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadDiag1(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   CJ135_vidSpiTransmit(pkstrConfig, pstrData, CJ135_u16CMD_RD_DIAG1);
}

/**********************************************************************************************************************/
/**********************************************************************************************************************/
/** 16 bits register read frame                                                                                      **/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadMode                                                                         */
/* !Description : Read the Mode reg                                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadMode(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_MODE);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadUnset                                                                        */
/* !Description : Read the Unset reg                                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadUnset(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_UNSET);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadUego0                                                                        */
/* !Description : Read the Uego0 reg                                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadUego0(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_UEGO0);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadUego1                                                                        */
/* !Description : Read the Uego1 reg                                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadUego1(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_UEGO1);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadUego2                                                                        */
/* !Description : Read the Uego2 reg                                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadUego2(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_UEGO2);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadUp0lean                                                                      */
/* !Description : Read the Up0lean reg                                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadUp0lean(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_UP0LEAN);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadUp0rich                                                                      */
/* !Description : Read the Up0rich reg                                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadUp0rich(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_UP0RICH);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadUego3                                                                        */
/* !Description : Read the Uego3 reg                                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadUego3(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_UEGO3);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadUego4                                                                        */
/* !Description : Read the Uego4 reg                                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadUego4(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_UEGO4);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadUego5                                                                        */
/* !Description : Read the Uego5 reg                                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadUego5(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_UEGO5);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadIpoff                                                                        */
/* !Description : Read the IPOFF reg                                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadIpoff(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_IPOFF);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadSteerpat                                                                     */
/* !Description : Read the Steerpat reg                                                                               */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadSteerpat(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_STEERPAT);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadConfigDSP                                                                    */
/* !Description : Read the ConfigDSP reg                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadConfigDSP(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_CONFIGDSP);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadTrim                                                                         */
/* !Description : Read the Trim reg                                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadTrim(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_TRIM);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRefpat                                                                       */
/* !Description : Read the Refpat reg                                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRefpat(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_REFPAT);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadFree                                                                         */
/* !Description : Read the Free reg                                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadFree(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_FREE);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadActualMode                                                                   */
/* !Description : Read the Actual Mode reg                                                                            */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadActualMode(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_REGISTER + CJ135_u8REG_ADDR_ACTUAL_MODE);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/**********************************************************************************************************************/
/** read in RAM frames                                                                                               **/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamMode                                                                      */
/* !Description : Read the mode field of RAM in all modes                                                             */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamMode(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_MODE);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamN3Ip1                                                                     */
/* !Description : Read the first value of Ip field of RAM in Normal3 mode                                             */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamN3Ip1(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_NORMAL3_IP1);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamN3Urie                                                                    */
/* !Description : Read the Urie field of RAM in Normal3 mode                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamN3Urie(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_NORMAL3_URIE);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamN3Ip2                                                                     */
/* !Description : Read the second value of Ip field of RAM in Normal3 mode                                            */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamN3Ip2(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_NORMAL3_IP2);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamN3Ug0                                                                     */
/* !Description : Read the Ug0 field of RAM in Normal3 mode                                                           */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamN3Ug0(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_NORMAL3_UG0);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamN3Un0                                                                     */
/* !Description : Read the Un0 field of RAM in Normal3 mode                                                           */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamN3Un0(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_NORMAL3_UN0);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamN3Ip3                                                                     */
/* !Description : Read the third value of Ip field of RAM in Normal3 mode                                             */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamN3Ip3(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_NORMAL3_IP3);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamN3Ip4                                                                     */
/* !Description : Read the fourth value of Ip field of RAM in Normal3 mode                                            */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamN3Ip4(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_NORMAL3_IP4);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamN3Ucal                                                                    */
/* !Description : Read the Ucal field of RAM in Normal3 mode                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamN3Ucal(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_NORMAL3_UCAL);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamN3Ip5                                                                     */
/* !Description : Read the fifth value of Ip field of RAM in Normal3 mode                                             */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamN3Ip5(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_NORMAL3_IP5);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamWUUrie                                                                    */
/* !Description : Read the Urie field of RAM in Normal3 mode                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamWUUrie(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_WARMUP_URIE);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamWUUn0                                                                     */
/* !Description : Read the Un0 field of RAM in Normal3 mode                                                           */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamWUUn0(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_WARMUP_UN0);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdReadRamWUUcal                                                                    */
/* !Description : Read the Ucal field of RAM in Normal3 mode                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdReadRamWUUcal(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_RD_RAM + CJ135_u8RAM_ADDR_WARMUP_UCAL);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}


/**********************************************************************************************************************/
/**********************************************************************************************************************/
/** 16 bits register write frames (high byte, low byte and adress)                                                   **/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRMode_HB                                                                        */
/* !Description : Send the config (HB) for Mode reg                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRMode_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegMode));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRMode_LB                                                                        */
/* !Description : Send the config (LB) for Mode reg                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRMode_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegMode));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRMode_Addr                                                                     */
/* !Description : Send the config (Addr) for Mode reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRMode_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_MODE);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUnset_HB                                                                       */
/* !Description : Send the config (HB) for Unset reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUnset_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegUnset));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUnset_LB                                                                       */
/* !Description : Send the config (LB) for Unset reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUnset_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegUnset));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUnset_Addr                                                                     */
/* !Description : Send the config (Addr) for Unset reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUnset_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_UNSET);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego0_HB                                                                       */
/* !Description : Send the config (HB) for Uego0 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego0_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegUego0));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego0_LB                                                                       */
/* !Description : Send the config (LB) for Uego0 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego0_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegUego0));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego0_Addr                                                                     */
/* !Description : Send the config (Addr) for Uego0 reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego0_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_UEGO0);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego1_HB                                                                       */
/* !Description : Send the config (HB) for Uego1 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego1_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegUego1));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego1_LB                                                                       */
/* !Description : Send the config (LB) for Uego1 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego1_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegUego1));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego1_Addr                                                                     */
/* !Description : Send the config (Addr) for Uego1 reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego1_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_UEGO1);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego2_HB                                                                       */
/* !Description : Send the config (HB) for Uego2 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego2_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegUego2));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego2_LB                                                                       */
/* !Description : Send the config (LB) for Uego2 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego2_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegUego2));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego2_Addr                                                                     */
/* !Description : Send the config (Addr) for Uego2 reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego2_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_UEGO2);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUp0lean_HB                                                                     */
/* !Description : Send the config (HB) for Up0lean reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUp0lean_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegUp0lean));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUp0lean_LB                                                                     */
/* !Description : Send the config (LB) for Up0lean reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUp0lean_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegUp0lean));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUp0lean_Addr                                                                   */
/* !Description : Send the config (Addr) for Up0lean reg                                                              */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUp0lean_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_UP0LEAN);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUp0rich_HB                                                                     */
/* !Description : Send the config (HB) for Up0rich reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUp0rich_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegUp0rich));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUp0rich_LB                                                                     */
/* !Description : Send the config (LB) for Up0rich reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUp0rich_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegUp0rich));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUp0rich_Addr                                                                   */
/* !Description : Send the config (Addr) for Up0rich reg                                                              */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUp0rich_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_UP0RICH);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego3_HB                                                                       */
/* !Description : Send the config (HB) for Uego3 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego3_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegUego3));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego3_LB                                                                       */
/* !Description : Send the config (LB) for Uego3 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego3_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegUego3));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego3_Addr                                                                     */
/* !Description : Send the config (Addr) for Uego3 reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego3_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_UEGO3);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego4_HB                                                                       */
/* !Description : Send the config (HB) for Uego4 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego4_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegUego4));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego4_LB                                                                       */
/* !Description : Send the config (LB) for Uego4 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego4_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegUego4));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego4_Addr                                                                     */
/* !Description : Send the config (Addr) for Uego4 reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego4_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_UEGO4);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego5_HB                                                                       */
/* !Description : Send the config (HB) for Uego5 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego5_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegUego5));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego5_LB                                                                       */
/* !Description : Send the config (LB) for Uego5 reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego5_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegUego5));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRUego5_Addr                                                                     */
/* !Description : Send the config (Addr) for Uego5 reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRUego5_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_UEGO5);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRIpoff_HB                                                                       */
/* !Description : Send the config (HB) for IPOFF reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRIpoff_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegIpOff));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRIpoff_LB                                                                       */
/* !Description : Send the config (LB) for IPOFF reg                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRIpoff_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegIpOff));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRIpoff_Addr                                                                     */
/* !Description : Send the config (Addr) for IPOFF reg                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRIpoff_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_IPOFF);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRSteerpat_HB                                                                    */
/* !Description : Send the config (HB) for Steerpat reg                                                               */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRSteerpat_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegSteerpat));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRSteerpat_LB                                                                    */
/* !Description : Send the config (LB) for Steerpat reg                                                               */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRSteerpat_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegSteerpat));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRSteerpat_Addr                                                                  */
/* !Description : Send the config (Addr) for Steerpat reg                                                             */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRSteerpat_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_STEERPAT);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRConfigDSP_HB                                                                   */
/* !Description : Send the config (HB) for ConfigDSP reg                                                              */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRConfigDSP_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegConfigDsp));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRConfigDSP_LB                                                                   */
/* !Description : Send the config (LB) for ConfigDSP reg                                                              */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRConfigDSP_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegConfigDsp));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRConfigDSP_Addr                                                                 */
/* !Description : Send the config (Addr) for ConfigDSP reg                                                            */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRConfigDSP_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_CONFIGDSP);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRTrim_HB                                                                    */
/* !Description : Send the config (HB) for Trim reg                                                               */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRTrim_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegTrim));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRTrim_LB                                                                    */
/* !Description : Send the config (LB) for Trim reg                                                               */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRTrim_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegTrim));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRTrim_Addr                                                                      */
/* !Description : Send the config (Addr) for Trim reg                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRTrim_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_TRIM);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRRefpat_HB                                                                        */
/* !Description : Send the config (HB) for Refpat reg                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRRefpat_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegRefpat));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRRefpat_LB                                                                        */
/* !Description : Send the config (LB) for Refpat reg                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRRefpat_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegRefpat));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRRefpat_Addr                                                                    */
/* !Description : Send the config (Addr) for Refpat reg                                                               */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRRefpat_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_REFPAT);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRFree_HB                                                                        */
/* !Description : Send the config (HB) for Free reg                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRFree_HB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_HIGHBYTE + CJ135_u16SelectHighByte(pstrData->u16ExpectedRegFree));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRFree_LB                                                                        */
/* !Description : Send the config (LB) for Free reg                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRFree_LB(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_LOWBYTE + CJ135_u16SelectLowByte(pstrData->u16ExpectedRegFree));

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiSendCmdWRFree_Addr                                                                      */
/* !Description : Send the config (Addr) for Free reg                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiSendCmdWRFree_Addr(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   uint16 u16LocFrameToSend;
   u16LocFrameToSend = (uint16)(CJ135_u16CMD_WR_ADDRESS + CJ135_u8REG_ADDR_FREE);

   CJ135_vidSpiTransmit(pkstrConfig, pstrData, u16LocFrameToSend);
}

/**********************************************************************************************************************/
/**********************************************************************************************************************/
/** Dummy frame                                                                                                      **/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiTransmitDummyFrame                                                                      */
/* !Description : Send the dummy fram : RD_IDENT frame                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidSpiTransmitDummyFrame(const CJ135_tstrConfig *pkstrConfig,
                                                     CJ135_strData          *pstrData)
{
   CJ135_vidSpiTransmit(pkstrConfig, pstrData, CJ135_u16DUMMY_FRAME_CMD);
}

#define CJ135_STOP_SEC_CODE
#include "CJ135_MemMap.h"

#endif /* CJ135_SPI_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

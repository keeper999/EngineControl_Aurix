/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9781                                                                                           */
/* !Description     : L9781 ASIC Abstraction Layer                                                                    */
/*                                                                                                                    */
/* !File            : L9781_I.h                                                                                       */
/* !Description     : Internal Functions / Macros of the L9781 Component                                              */
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
 * %PID: P2017_BSW:0A189052.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef L9781_I_H
#define L9781_I_H

#include "Std_Types.h"

#include "L9781.h"
#include "L9781_L.h"

#include "DGOHAL.h"
#include "Dio.h"
#include "Gpt.h"
#include "Spi.h"

#include "SchM_L9781.h"
#include "SWFAIL.h"

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

/*******************************************************************/
/* !Comment : L9781 Definition of the diagnosis fault detection    */
/*******************************************************************/
#define L9781_bDIAG_SC_VB_BANK_AX         L9781_bDiagScVbBankAx
#define L9781_bDIAG_SC_VB_BANK_AY         L9781_bDiagScVbBankAy
#define L9781_bDIAG_SC_VB_BANK_BX         L9781_bDiagScVbBankBx
#define L9781_bDIAG_SC_VB_BANK_BY         L9781_bDiagScVbBankBy
#define L9781_bDIAG_SC_VB_BANK_FP         L9781_bDiagScVbBankFp

#define L9781_bDIAG_SC_GND_BANK_AX        L9781_bDiagScGndBankAx
#define L9781_bDIAG_SC_GND_BANK_AY        L9781_bDiagScGndBankAy
#define L9781_bDIAG_SC_GND_BANK_BX        L9781_bDiagScGndBankBx
#define L9781_bDIAG_SC_GND_BANK_BY        L9781_bDiagScGndBankBy
#define L9781_bDIAG_SC_GND_BANK_FP        L9781_bDiagScGndBankFp

#define L9781_bDIAG_SC_VHS_VLS_BANK_AX    L9781_bDiagScVhsVlsBankAx
#define L9781_bDIAG_SC_VHS_VLS_BANK_AY    L9781_bDiagScVhsVlsBankAy
#define L9781_bDIAG_SC_VHS_VLS_BANK_BX    L9781_bDiagScVhsVlsBankBx
#define L9781_bDIAG_SC_VHS_VLS_BANK_BY    L9781_bDiagScVhsVlsBankBy
#define L9781_bDIAG_SC_VHS_VLS_BANK_FP    L9781_bDiagScVhsVlsBankFp

#define L9781_bDIAG_OL_BANK_AX            L9781_bDiagOlBankAx
#define L9781_bDIAG_OL_BANK_AY            L9781_bDiagOlBankAy
#define L9781_bDIAG_OL_BANK_BX            L9781_bDiagOlBankBx
#define L9781_bDIAG_OL_BANK_BY            L9781_bDiagOlBankBy
#define L9781_bDIAG_OL_BANK_FP            L9781_bDiagOlBankFp

#define L9781_bDIAG_OV_VBAT_ASIC          L9781_bDiagOvVbat
#define L9781_bDIAG_UV_VBAT_ASIC          L9781_bDiagUvVbat

/*******************************************************************/
/* !Comment : L9781 Defintion of bit field used for SPI request    */
/*******************************************************************/
#define L9781_bfLOAD_INJ_PROF_REQ         L9781_bfLoadInjProfReq
#define L9781_bfLOAD_PMP_PROF_REQ         L9781_bfLoadPmpProfReq
#define L9781_bfLOAD_DIAG_REQ             L9781_bfLoadDiagReq
#define L9781_bfLOAD_UNLOCK_REQ           L9781_bfLoadUnlockReq

/*******************************************************************/
/* !Comment : DGOHAL CFG Bit Field for diagnosis updating          */
/*******************************************************************/
#define L9781_bfVALID_DIAG ( DGOHAL_bfVALID_SUPPLY | DGOHAL_bfVALID_GROUND | DGOHAL_bfVALID_OPEN)
#define L9781_bfNO_FAULT   ( DGOHAL_bfNO_FAULT_SUPPLY | DGOHAL_bfNO_FAULT_GROUND | DGOHAL_bfNO_FAULT_OPEN)

/**********************************************************************************************************************/
/* MACRO FUNCTIONS                                                                                                    */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSPI_LOADING                                                                                */
/* !Description : Loads the MSW and LSW Tx buffer to transmit the current frame by SPI.                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_vidSPI_LOADING( \
\
   snComponent, \
   snLoadState \
\
) \
   M1_L9781_vidSPI_LOADING(snComponent, snLoadState)

   #define M1_L9781_vidSPI_LOADING(snComponent, snLoadState) \
      M2_L9781_vidSPI_LOADING_##snLoadState(snComponent)

   #define M2_L9781_vidSPI_LOADING_GEN_CONF(snComponent) \
      M3_L9781_vidSPI_LOADING_GEN_CONF(snComponent)

   #define M2_L9781_vidSPI_LOADING_INJ_PROF(snComponent) \
      M3_L9781_vidSPI_LOADING_INJ_PROF(snComponent, \
                                       L9781_pau32GET_BACKUP_BUFFER(snComponent, INJ_PROF))

   #define M2_L9781_vidSPI_LOADING_PMP_PROF(snComponent) \
      M3_L9781_vidSPI_LOADING_PMP_PROF(snComponent, \
                                       L9781_pau32GET_BACKUP_BUFFER(snComponent, PMP_PROF))

   #define M2_L9781_vidSPI_LOADING_UNLOCK(snComponent) \
      M3_L9781_vidSPI_LOADING_UNLOCK(snComponent)

   #define M3_L9781_vidSPI_LOADING_GEN_CONF(snComponent) \
   do \
   { \
      uint32  u32LocalCurrentBufferTx; \
      \
      \
      switch (L9781_u8SpiFrameIndex) \
      { \
         case L9781_u8ID_GEN_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(GEN_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_PDRV_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(PDRV_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_ISEN_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(ISEN_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA1_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA1_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA2_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA2_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA3_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA3_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_ZLC_OC_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_ZLC_OC_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_FP_FRA1_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA1_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_FP_FRA2_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA2_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_FP_ZLC_OC_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_ZLC_OC_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_DCDC_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(DCDC_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_DIAG_PROT_CTRL: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(DIAG_PROT_CTRL, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_PROT_FILT_CTRL: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(PROT_FILT_CTRL, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_PROT_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_PROT_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_FP_PROT_CONF: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_PROT_CONF, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_IDLE_DLY: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_IDLE_DLY, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_FP_IDLE_DLY: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_IDLE_DLY, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_PDRV_ENB: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(PDRV_ENB, snComponent); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            L9781_u8SpiFrameIndex   = L9781_u8ID_UNDEFINED; \
            u32LocalCurrentBufferTx = L9781_u32BUFFER_UNDEFINED; \
            L9781_bSpiTxRequest     = FALSE; \
            break; \
      } \
      \
      L9781_u16SpiBufferTxLsw = (uint16)(u32LocalCurrentBufferTx); \
      L9781_u16SpiBufferTxMsw = (uint16)(u32LocalCurrentBufferTx >> L9781_u8SHIFT_16_BITS); \
   } \
   while(0u)

   #define M3_L9781_vidSPI_LOADING_INJ_PROF(snComponent, pau32BkpBuff) \
   do \
   { \
      uint32  u32LocalCurrentBufferTx; \
      \
      \
      switch (L9781_u8SpiFrameIndex) \
      { \
         case L9781_u8ID_AB_FRA1_PARA1: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA1_PARA1, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA1_PARA2: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA1_PARA2,  snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA1_PARA3: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA1_PARA3,  snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA1_PARA4: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA1_PARA4, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA2_PARA1: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA2_PARA1, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA2_PARA2: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA2_PARA2, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA2_PARA3: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA2_PARA3, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA2_PARA4: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA2_PARA4, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA3_PARA1: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA3_PARA1, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA3_PARA2: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA3_PARA2, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_AB_FRA3_PARA3: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA3_PARA3, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            L9781_u8SpiFrameIndex   = L9781_u8ID_UNDEFINED; \
            u32LocalCurrentBufferTx = L9781_u32BUFFER_UNDEFINED; \
            L9781_bCheckBuffer      = FALSE; \
            L9781_bSpiTxRequest     = FALSE; \
            break; \
      } \
      \
      L9781_u16SpiBufferTxLsw = (uint16)(u32LocalCurrentBufferTx); \
      L9781_u16SpiBufferTxMsw = (uint16)(u32LocalCurrentBufferTx >> L9781_u8SHIFT_16_BITS); \
   } \
   while(0u)

   #define M3_L9781_vidSPI_LOADING_PMP_PROF(snComponent, pau32BkpBuff) \
   do \
   { \
      uint32  u32LocalCurrentBufferTx; \
      \
      \
      switch (L9781_u8SpiFrameIndex) \
      { \
         case L9781_u8ID_FP_FRA1_PARA1: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA1_PARA1, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_FP_FRA1_PARA2: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA1_PARA2, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_FP_FRA1_PARA3: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA1_PARA3, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_FP_FRA1_PARA4: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA1_PARA4, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_FP_FRA2_PARA1: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA2_PARA1, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_FP_FRA2_PARA2: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA2_PARA2, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         case L9781_u8ID_FP_FRA2_PARA3: \
            u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA2_PARA3, snComponent); \
            L9781_vidCHECK_BACKUP_BUFFER(pau32BkpBuff[L9781_u8SpiFrameIndex], u32LocalCurrentBufferTx); \
            L9781_u8SpiFrameIndex++; \
            break; \
         \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            L9781_u8SpiFrameIndex   = L9781_u8ID_UNDEFINED; \
            u32LocalCurrentBufferTx = L9781_u32BUFFER_UNDEFINED; \
            L9781_bCheckBuffer      = FALSE; \
            L9781_bSpiTxRequest     = FALSE; \
            break; \
      } \
      \
      L9781_u16SpiBufferTxLsw = (uint16)(u32LocalCurrentBufferTx); \
      L9781_u16SpiBufferTxMsw = (uint16)(u32LocalCurrentBufferTx >> L9781_u8SHIFT_16_BITS); \
   } \
   while(0u)

   #define M3_L9781_vidSPI_LOADING_UNLOCK(snComponent) \
   do \
   { \
      uint32  u32LocalCurrentBufferTx; \
      \
      \
      u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(UNLOCK_DIAG, snComponent); \
      \
      L9781_u16SpiBufferTxLsw = (uint16)(u32LocalCurrentBufferTx); \
      L9781_u16SpiBufferTxMsw = (uint16)(u32LocalCurrentBufferTx >> L9781_u8SHIFT_16_BITS); \
   } \
   while(0u)

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidCHECK_BACKUP_BUFFER                                                                        */
/* !Description : Compares the current buffer to the backup buffer in order to transmit or not the current buffer.    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_vidCHECK_BACKUP_BUFFER( \
\
   u32BackupBuffer, \
   u32CurrentBuffer \
\
) \
do \
{ \
   if (u32BackupBuffer != u32CurrentBuffer) \
   { \
      u32BackupBuffer    = u32CurrentBuffer; \
      L9781_bCheckBuffer = FALSE; \
   } \
} \
while(0u)

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSPI_TX                                                                                     */
/* !Description : Starts the SPI communication with the transmission of the Tx buffer                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_vidSPI_TX( \
\
   snSpiChannel, \
   snSpiSequence \
\
) \
do \
{ \
  \
   uint32 u32LocalSpiByfferTx; \
   \
   L9781_bSpiTxRequest = FALSE; \
   u32LocalSpiByfferTx = (uint32)((L9781_u16SpiBufferTxMsw << L9781_u8SHIFT_16_BITS) | L9781_u16SpiBufferTxLsw); \
   Spi_WriteIB(snSpiChannel, (const uint8 *)(&u32LocalSpiByfferTx)); \
   Spi_AsyncTransmit(snSpiSequence); \
} \
while(0u)

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSPI_RX                                                                                     */
/* !Description : Loads the MSW and LSW Rx buffer on the SPI reception                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_vidSPI_RX( \
\
   snComponent \
\
) \
do \
{ \
   uint32  u32LocalSpiBufferRx; \
   \
   L9781_bSpiMswFrameTransmit = FALSE; \
   Spi_ReadIB(snComponent, (uint8*)&u32LocalSpiBufferRx); \
   L9781_u16SpiBufferRxMsw = (uint16)(u32LocalSpiBufferRx >> L9781_u8SHIFT_16_BITS); \
   L9781_u16SpiBufferRxLsw = (uint16)(u32LocalSpiBufferRx); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSET_SPI_REQUEST                                                                            */
/* !Description : Sets the SPI request (using a bit field) of considered Set the SPI request (using a bit field) of   */
/*                considered                                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_vidSET_SPI_REQUEST( \
\
   u8Channel, \
   snRequestType \
\
) \
   M1_L9781_vidSET_SPI_REQUEST(u8Channel, \
                               L9781_bfGET_BIT_FIELD_REQ(snRequestType), \
                               L9781_u8GET_REQUEST_TYPE(snRequestType))

   #define M1_L9781_vidSET_SPI_REQUEST(u8Channel, bfSpiRequest, u8RequestType) \
      M2_L9781_vidSET_SPI_REQUEST(u8Channel, bfSpiRequest, u8RequestType)

   #define M2_L9781_vidSET_SPI_REQUEST(u8Channel, bfSpiRequest, u8RequestType) \
   do \
   { \
      if (((bfSpiRequest) & ((uint16)(0x0001U << (u8Channel)))) == L9781_bfNO_SPI_REQUEST) \
      { \
         bfSpiRequest |= ((uint16)(0x0001U << (u8Channel))); \
         L9781_au8FifoSpiReqCh[L9781_u8NbSpiRequest]  = (u8Channel); \
         L9781_au8FifoSpiReqTyp[L9781_u8NbSpiRequest] = (u8RequestType); \
         L9781_u8NbSpiRequest++; \
      } \
   }\
   while(0u)

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidCLEAR_SPI_REQUEST                                                                          */
/* !Description : Clears the SPI request (using a bite field) of considered channel according to the type of the      */
/*                request.                                                                                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_vidCLEAR_SPI_REQUEST( \
\
   u8Channel, \
   snRequestType \
\
) \
   M1_L9781_vidCLEAR_SPI_REQUEST(u8Channel, \
                                 L9781_bfGET_BIT_FIELD_REQ(snRequestType))

   #define M1_L9781_vidCLEAR_SPI_REQUEST(u8Channel, \
                                         bfSpiRequest) \
      M2_L9781_vidCLEAR_SPI_REQUEST(u8Channel, \
                                    bfSpiRequest)

   #define M2_L9781_vidCLEAR_SPI_REQUEST(u8Channel, \
                                         bfSpiRequest) \
   do \
   { \
      uint8 u8LocalIndex; \
      \
      \
      u8LocalIndex = 0u; \
      \
      SchM_Enter_L9781_vidCLR_SPI_REQ(); \
      \
      bfSpiRequest &= (uint16)(~(0x0001U << (u8Channel))); \
      L9781_u8NbSpiRequest--; \
      L9781_au8FifoSpiReqTyp[u8LocalIndex] = L9781_u8FIFO_UNDEFINED; \
      L9781_au8FifoSpiReqCh[u8LocalIndex]  = L9781_u8FIFO_UNDEFINED; \
      \
      while ((u8LocalIndex < L9781_u8NbSpiRequest) && (u8LocalIndex < L9781_u8NB_SPI_REQ_MAX)) \
      { \
         L9781_au8FifoSpiReqCh[u8LocalIndex]       = L9781_au8FifoSpiReqCh[u8LocalIndex + 1u]; \
         L9781_au8FifoSpiReqCh[u8LocalIndex + 1u]  = L9781_u8FIFO_UNDEFINED; \
         L9781_au8FifoSpiReqTyp[u8LocalIndex]      = L9781_au8FifoSpiReqTyp[u8LocalIndex + 1u]; \
         L9781_au8FifoSpiReqTyp[u8LocalIndex + 1u] = L9781_u8FIFO_UNDEFINED; \
         u8LocalIndex++; \
      } \
      SchM_Exit_L9781_vidCLR_SPI_REQ(); \
   } \
   while(0u)

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidDIAGNOSIS                                                                                  */
/* !Description : Updates the electrical diagnosis of DGOHAL channel linked to "snBank" of "snComponent".             */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_vidDIAGNOSIS( \
\
   snComponent, \
   snBank \
\
) \
   M1_L9781_vidDIAGNOSIS(snComponent,snBank)

   #define M1_L9781_vidDIAGNOSIS(snComponent,snBank) \
      M2_L9781_vidDIAGNOSIS_##snBank(snComponent,snBank)

   #define M2_L9781_vidDIAGNOSIS_BANK_AX(snComponent, snBank) \
      M3_L9781_vidDIAGNOSIS_BANK_AX_BX_FP(snComponent, snBank)

   #define M2_L9781_vidDIAGNOSIS_BANK_BX(snComponent, snBank) \
      M3_L9781_vidDIAGNOSIS_BANK_AX_BX_FP(snComponent, snBank)

   #define M2_L9781_vidDIAGNOSIS_BANK_FP(snComponent, snBank) \
      M3_L9781_vidDIAGNOSIS_BANK_AX_BX_FP(snComponent, snBank)

   #define M2_L9781_vidDIAGNOSIS_ASIC(snComponent, snBank) \
      M3_L9781_vidDIAGNOSIS_ASIC(snComponent, snBank)

   #define M3_L9781_vidDIAGNOSIS_BANK_AX_BX_FP(snComponent, snBank) \
      M4_L9781_vidDIAGNOSIS(L9781_udtGET_CFG_DGOHAL_CH(snComponent, snBank), \
                            L9781_bGET_DIAG_FAULT(snBank, SC_VB), \
                            L9781_bGET_DIAG_FAULT(snBank, SC_GND), \
                            L9781_bGET_DIAG_FAULT(snBank, SC_VHS_VLS), \
                            L9781_bGET_DIAG_FAULT(snBank, OL), \
                            L9781_bGET_IRQ_ACT(snBank), \
                            L9781_bGET_IRQ_IDLE(snBank), \
                            L9781_bGET_ACTUATION_STATUS(snBank), \
                            L9781_bGET_OVL_SPI_DIAG_MODE(snComponent))

   #define M4_L9781_vidDIAGNOSIS(udtDiagChannel, \
                                 bDiagScVb, \
                                 bDiagScGnd, \
                                 bDiagScVhsVls, \
                                 bDiagOl, \
                                 bIrqAct, \
                                 bIrqIdle, \
                                 bActStatus, \
                                 bOnlyOvlDiagMode) \
      M5_L9781_vidDIAGNOSIS(udtDiagChannel, \
                            bDiagScVb, \
                            bDiagScGnd, \
                            bDiagScVhsVls, \
                            bDiagOl, \
                            bIrqAct, \
                            bIrqIdle, \
                            bActStatus, \
                            bOnlyOvlDiagMode)

   #define M5_L9781_vidDIAGNOSIS(udtDiagChannel, \
                                 bDiagScVb, \
                                 bDiagScGnd, \
                                 bDiagScVhsVls, \
                                 bDiagOl, \
                                 bIrqAct, \
                                 bIrqIdle, \
                                 bActStatus, \
                                 bOnlyOvlDiagMode) \
   do \
   { \
      DGOHAL_tbfStatus bfLocalStatus; \
      DGOHAL_tbfStatus bfLocalValid; \
      \
      \
      bfLocalStatus = 0x00000000u; \
      bfLocalValid  = 0x00000000u; \
      \
      if (bOnlyOvlDiagMode == FALSE)  \
      {\
         bfLocalValid  = ( DGOHAL_bfVALID_SUPPLY \
                         | DGOHAL_bfVALID_GROUND \
                         | DGOHAL_bfVALID_OPEN); \
         \
         if (bDiagScVb != FALSE) \
         { \
            bfLocalStatus |= DGOHAL_bfFAULT_SUPPLY; \
         } \
         else \
         { \
            bfLocalStatus |= DGOHAL_bfNO_FAULT_SUPPLY; \
         } \
         \
         if (bDiagScGnd != FALSE) \
         { \
            bfLocalStatus |= DGOHAL_bfFAULT_GROUND; \
         } \
         else \
         { \
            bfLocalStatus |= DGOHAL_bfNO_FAULT_GROUND; \
         } \
         \
         if (bDiagOl != FALSE) \
         { \
            bfLocalStatus |= DGOHAL_bfFAULT_OPEN; \
         } \
         else \
         { \
            bfLocalStatus |= DGOHAL_bfNO_FAULT_OPEN; \
         } \
         \
      }\
      \
      if (bActStatus != FALSE) \
      { \
         if ((bDiagScVhsVls != FALSE) && (bIrqAct != FALSE))\
         { \
            bfLocalStatus |= DGOHAL_bfFAULT_OVERLOAD; \
         } \
         else \
         { \
            bfLocalStatus |= DGOHAL_bfNO_FAULT_OVERLOAD; \
         } \
         \
         bfLocalValid |= DGOHAL_bfVALID_OVERLOAD; \
      } \
      \
      DGOHAL_vidWrite(udtDiagChannel, bfLocalValid, bfLocalStatus); \
   } \
   while(0u)

   #define M3_L9781_vidDIAGNOSIS_ASIC(snComponent, snBank) \
      M4_L9781_vidDIAGNOSIS_ASIC(L9781_udtGET_CFG_DGOHAL_CH(snComponent, snBank), \
                                 L9781_bGET_DIAG_FAULT(snBank, OV_VBAT), \
                                 L9781_bGET_DIAG_FAULT(snBank, UV_VBAT), \
                                 L9781_bGET_OVL_SPI_DIAG_MODE(snComponent))

   #define M4_L9781_vidDIAGNOSIS_ASIC(udtDiagChannel, \
                                      bDiagOvVbat, \
                                      bDiagUvVbat, \
                                      bOnlyOvlDiagMode) \
      M5_L9781_vidDIAGNOSIS_ASIC(udtDiagChannel, \
                                 bDiagOvVbat, \
                                 bDiagUvVbat, \
                                 bOnlyOvlDiagMode)

   #define M5_L9781_vidDIAGNOSIS_ASIC(udtDiagChannel, \
                                      bDiagOvVbat, \
                                      bDiagUvVbat, \
                                      bOnlyOvlDiagMode) \
   do \
   { \
      DGOHAL_tbfStatus bfLocalStatus; \
      DGOHAL_tbfStatus bfLocalValid; \
      \
      \
      if (bOnlyOvlDiagMode == FALSE) \
      { \
         bfLocalStatus = 0x00000000u; \
         bfLocalValid  = ( DGOHAL_bfVALID_VBAT_OVER_VOLTAGE \
                         | DGOHAL_bfVALID_VBAT_UNDER_VOLTAGE \
                         | DGOHAL_bfVALID_SPI_FAILURE); \
         \
         if (bDiagOvVbat != FALSE) \
         { \
            bfLocalStatus |= DGOHAL_bfFAULT_VBAT_OVER_VOLTAGE; \
         } \
         else \
         { \
            bfLocalStatus |= DGOHAL_bfNO_FAULT_VBAT_OVER_VOLTAGE; \
         } \
         \
         if (bDiagUvVbat != FALSE) \
         { \
            bfLocalStatus |= DGOHAL_bfFAULT_VBAT_UNDER_VOLTAGE; \
         } \
         else \
         { \
            bfLocalStatus |= DGOHAL_bfNO_FAULT_VBAT_UNDER_VOLTAGE; \
         } \
         bfLocalStatus |= DGOHAL_bfNO_FAULT_SPI_FAILURE; \
         DGOHAL_vidWrite(udtDiagChannel, bfLocalValid, bfLocalStatus); \
      } \
   } \
   while(0u)

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidCLEAR_DIAG                                                                                 */
/* !Description : Clears the fault on the DGOHAL channel linked to "snBank" of"snComponent".                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_vidCLEAR_DIAG( \
\
   snComponent, \
   snBank \
\
) \
   M1_L9781_vidCLEAR_DIAG(snComponent, snBank)

   #define M1_L9781_vidCLEAR_DIAG(snComponent, snBank) \
      M2_L9781_vidCLEAR_DIAG(L9781_udtGET_CFG_DGOHAL_CH(snComponent, snBank))

   #define M2_L9781_vidCLEAR_DIAG(udtDiagChannel) \
      M3_L9781_vidCLEAR_DIAG(udtDiagChannel)

   #define M3_L9781_vidCLEAR_DIAG(udtDiagChannel) \
   do \
   { \
      DGOHAL_vidWrite(udtDiagChannel, L9781_bfVALID_DIAG, L9781_bfNO_FAULT); \
   } \
   while(0u)

/**********************************************************************************************************************/
/* !FuncName    : L9781_u32GET_FRAME_CFG                                                                              */
/* !Description : Gets the SPI frame configuration linked to "snFrame" of "snComponent" with the odd parity (bits 2n).*/
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_u32GET_FRAME_CFG( \
\
   snFrame, \
   snComponent \
\
) \
   M1_L9781_u32GET_FRAME_CFG(L9781_u32GET_WHOLE_DATA_CFG(snFrame, snComponent))

   #define M1_L9781_u32GET_FRAME_CFG(u32FrameData) \
      M2_L9781_u32GET_FRAME_CFG(u32FrameData)

   #define M2_L9781_u32GET_FRAME_CFG(u32FrameData) \
      ( ((uint32)(u32FrameData)) \
      | ( (  L9781_u32CalcOddParity(u32FrameData) \
          << L9781_u8SHIFT_TX_ODD_PARITY) \
        & L9781_u32MASK_TX_ODD_PARITY))

/**********************************************************************************************************************/
/* !FuncName    : L9781_u32GET_WHOLE_DATA_CFG                                                                         */
/* !Description : Gets the data configuration linked to "snFrame" of "snComponent" without the odd parity (bit 0 .. 32*/
/*                without bit 24).                                                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_u32GET_WHOLE_DATA_CFG( \
\
   snFrame, \
   snComponent \
\
) \
   M1_L9781_u32GET_WHOLE_DATA_CFG(L9781_udtGET_FRAME_ADDR(snFrame), \
                                  L9781_u32GET_INPUT_DATA_CFG(snFrame, snComponent))

   #define M1_L9781_u32GET_WHOLE_DATA_CFG(udtAddr, u32InputDataCfg) \
      M2_L9781_u32GET_WHOLE_DATA_CFG(udtAddr, u32InputDataCfg)

   #define M2_L9781_u32GET_WHOLE_DATA_CFG(udtAddr, u32InputDataCfg) \
      ( (((uint32)(udtAddr) << L9781_u8SHIFT_ADDR) & L9781_u32MASK_CMD_ADDR) \
      | ((uint32)(u32InputDataCfg) & L9781_u32MASK_INPUT_DATA))

/**********************************************************************************************************************/
/* !FuncName    : L9781_bREAD_IRQ_DIAG_STATE                                                                          */
/* !Description : Read the IRQ state (for electrical diagnosis) of the current ASIC component.                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_bREAD_IRQ_DIAG_STATE( \
\
   snComponent \
\
) \
   M1_L9781_vidREAD_IRQ_DIAG_STATE(L9781_snGET_CFG_DIO_IRQ_CH(snComponent))

   #define M1_L9781_vidREAD_IRQ_DIAG_STATE(snDioIrqCh) \
      M2_L9781_vidREAD_IRQ_DIAG_STATE(snDioIrqCh)

   #define M2_L9781_vidREAD_IRQ_DIAG_STATE(snDioIrqCh) \
      (boolean)(Dio_ReadChannel(snDioIrqCh))

/**********************************************************************************************************************/
/* !FuncName    : L9781_udtGET_FRAME_ADDR                                                                             */
/* !Description : Gets the SPI frame address.                                                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_udtGET_FRAME_ADDR( \
\
   snFrame \
\
) \
   L9781_udtADDR_##snFrame

/**********************************************************************************************************************/
/* !FuncName    : L9781_u32GET_INPUT_DATA_CFG                                                                         */
/* !Description : Gets the input data (bits 23 .. 2) of the SPI "snFrame" according to the configuration              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_u32GET_INPUT_DATA_CFG( \
\
   snFrame, \
   snComponent \
\
) \
   L9781_u32##snFrame##_##snComponent

/**********************************************************************************************************************/
/* !FuncName    : L9781_pau32GET_BACKUP_BUFFER                                                                        */
/* !Description : Gets the buffer used to save the SPI frames of the current PMP or INJ profile.                      */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_pau32GET_BACKUP_BUFFER( \
\
   snComponent, \
   snLoadState \
\
) \
   L9781_pau32##snLoadState##_BKP_BUFF_##snComponent

/**********************************************************************************************************************/
/* !FuncName    : L9781_snGET_CFG_DIO_IRQ_CH                                                                          */
/* !Description : Gets the DIO channel linked to the current ASIC component according the configuration.              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_snGET_CFG_DIO_IRQ_CH( \
\
   snComponent \
\
) \
   L9781_snDIO_IRQ_##snComponent##_CH

/**********************************************************************************************************************/
/* !FuncName    : L9781_bfGET_BIT_FIELD_REQ                                                                           */
/* !Description : Gets the bit field used to set a SPI request according to the type of the request.                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_bfGET_BIT_FIELD_REQ( \
\
   snRequestType \
\
) \
   L9781_bf##snRequestType##_REQ

/**********************************************************************************************************************/
/* !FuncName    : L9781_u8GET_REQUEST_TYPE                                                                            */
/* !Description : Gets the request type used for the SPI request.                                                     */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_u8GET_REQUEST_TYPE( \
\
   snRequestType \
\
) \
   L9781_u8##snRequestType##_REQ

/**********************************************************************************************************************/
/* !FuncName    : L9781_bGET_DIAG_FAULT                                                                               */
/* !Description : Returns the variable of diagnosis fault (SC_VB,  SC_GND, SC_VHS_VLS, OL) for a specified bank       */
/*                (BANK_A, BANK_B, BANK_FP).                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_bGET_DIAG_FAULT( \
\
   snBank, \
   snFaultType \
\
) \
   L9781_bDIAG_##snFaultType##_##snBank

/**********************************************************************************************************************/
/* !FuncName    : L9781_udtGET_CFG_DGOHAL_CH                                                                          */
/* !Description : Gets the DGOHAL channel linked to the current ASIC component according the configuration.           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_udtGET_CFG_DGOHAL_CH( \
\
   snComponent, \
   snBank \
\
) \
   L9781_udtDGOHAL_##snBank##_##snComponent##_CH

/**********************************************************************************************************************/
/* !FuncName    : L9781_bGET_IRQ_ACT                                                                                  */
/* !Description : Returns a boolean variable at TRUE if an Irq Act has occured for the considered bank otherwise FALSE*/
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_bGET_IRQ_ACT( \
\
   snBank \
\
) \
 \
   L9781_abIrqActStatus[L9781_u8##snBank]

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidPROG_CAPCOM_DELAY_STARTUP_SEQ                                                              */
/* !Description : Programs a CAPCOM unit at the time given in parameter.                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_vidPROG_CAPCOM_DELAY_STARTUP_SEQ( \
\
   u32Delay \
\
) \
do \
{ \
   SchM_Enter_L9781_DELAY_STARTUP(); \
   Gpt_StopTimer(L9781_snGPT_STARTUP_SEQ_CH); \
   Gpt_EnableNotification(L9781_snGPT_STARTUP_SEQ_CH); \
   Gpt_StartTimer(L9781_snGPT_STARTUP_SEQ_CH, u32Delay); \
   SchM_Exit_L9781_DELAY_STARTUP(); \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : L9781_bGET_BANK_LOCK                                                                                */
/* !Description : Returns a boolean variable at TRUE if a bank was locked otherwise FALSE.                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_bGET_BANK_LOCK( \
\
   snBank \
\
) \
 \
   L9781_abBankLock[L9781_u8##snBank]

/**********************************************************************************************************************/
/* !FuncName    : L9781_bGET_IRQ_IDLE                                                                                 */
/* !Description : Returns a boolean variable at TRUE if an Irq Idle has occured for the considered bank otherwise     */
/*                FALSE.                                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_bGET_IRQ_IDLE( \
\
   snBank \
\
) \
 \
   L9781_abIrqIdleStatus[L9781_u8##snBank]

/**********************************************************************************************************************/
/* !FuncName    : L9781_bIS_ADDRESS_CORRUPTIBLE                                                                       */
/* !Description : Returns a boolean variable at TRUE if the given input is a valid address that can be written        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_bIS_ADDRESS_CORRUPTIBLE( \
\
   Address \
\
) \
 \
   ( (  ((Address) == L9781_udtADDR_DIAG_PROT_CTRL) \
     || ((Address) == L9781_udtADDR_PROT_FILT_CTRL) \
     || (  ((Address) >= L9781_udtADDR_AB_IDLE_DLY) \
        && ((Address) <= L9781_udtADDR_FP_FRA2_PARA3))) ? (TRUE) : (FALSE) \
   )

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidPREP_SPI_SINGLE_FRAME                                                                      */
/* !Description : In case of reemission, needed, prepare and load the frame to reemit.                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_vidPREP_SPI_SINGLE_FRAME( \
\
   snComponent, \
   u32Address \
\
) \
\
do \
{ \
   uint32 u32LocalCurrentBufferTx; \
   \
   L9781_bSpiTxRequest = TRUE; \
   \
   switch (u32Address) \
   { \
      case L9781_udtADDR_AB_FRA1_PARA1: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA1_PARA1, snComponent); \
         break; \
      \
      case L9781_udtADDR_AB_FRA1_PARA2: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA1_PARA2, snComponent); \
         break; \
      \
      case L9781_udtADDR_AB_FRA1_PARA3: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA1_PARA3, snComponent); \
         break; \
      \
      case L9781_udtADDR_AB_FRA1_PARA4: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA1_PARA4, snComponent); \
         break; \
      \
      case L9781_udtADDR_AB_FRA2_PARA1: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA2_PARA1, snComponent); \
         break; \
      \
      case L9781_udtADDR_AB_FRA2_PARA2: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA2_PARA2, snComponent); \
         break; \
      \
      case L9781_udtADDR_AB_FRA2_PARA3: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA2_PARA3, snComponent); \
         break; \
      \
      case L9781_udtADDR_AB_FRA2_PARA4: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA2_PARA4, snComponent); \
         break; \
      \
      case L9781_udtADDR_AB_FRA3_PARA1: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA3_PARA1, snComponent); \
         break; \
      \
      case L9781_udtADDR_AB_FRA3_PARA2: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA3_PARA2, snComponent); \
         break; \
      \
      case L9781_udtADDR_AB_FRA3_PARA3: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_FRA3_PARA3, snComponent); \
         break; \
      \
      case L9781_udtADDR_FP_FRA1_PARA1: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA1_PARA1, snComponent); \
         break; \
      \
      case L9781_udtADDR_FP_FRA1_PARA2: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA1_PARA2, snComponent); \
         break; \
      \
      case L9781_udtADDR_FP_FRA1_PARA3: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA1_PARA3, snComponent); \
         break; \
      \
      case L9781_udtADDR_FP_FRA1_PARA4: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA1_PARA4, snComponent); \
         break; \
      \
      case L9781_udtADDR_FP_FRA2_PARA1: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA2_PARA1, snComponent); \
         break; \
      \
      case L9781_udtADDR_FP_FRA2_PARA2: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA2_PARA2, snComponent); \
         break; \
      \
      case L9781_udtADDR_FP_FRA2_PARA3: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_FRA2_PARA3, snComponent); \
         break; \
      \
      case L9781_udtADDR_DIAG_PROT_CTRL: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(DIAG_PROT_CTRL, snComponent); \
         break; \
      \
      case L9781_udtADDR_PROT_FILT_CTRL: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(PROT_FILT_CTRL, snComponent); \
         break; \
      \
      case L9781_udtADDR_AB_IDLE_DLY: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(AB_IDLE_DLY, snComponent); \
         break; \
      \
      case L9781_udtADDR_FP_IDLE_DLY: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(FP_IDLE_DLY, snComponent); \
         break; \
      \
      case L9781_udtADDR_UNLOCK_DIAG: \
         u32LocalCurrentBufferTx = L9781_u32GET_FRAME_CFG(UNLOCK_DIAG, snComponent); \
         break; \
      \
      default: \
         SWFAIL_vidSoftwareErrorHook(); \
         L9781_u8SpiFrameIndex   = L9781_u8ID_UNDEFINED; \
         u32LocalCurrentBufferTx = L9781_u32BUFFER_UNDEFINED; \
         L9781_bCheckBuffer      = FALSE; \
         L9781_bSpiTxRequest     = FALSE; \
         break; \
   } \
   \
   L9781_u16SpiBufferTxLsw = (uint16)(u32LocalCurrentBufferTx); \
   L9781_u16SpiBufferTxMsw = (uint16)(u32LocalCurrentBufferTx >> L9781_u8SHIFT_16_BITS); \
   \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidVBOOST_DIAGNOSIS                                                                           */
/* !Description : Compare current VBOOST voltage to upper and lower limits authorised.                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_vidVBOOST_DIAGNOSIS( \
\
   u16CurrentLevel, \
   u16LowLimit, \
   u16HighLimit \
\
) \
do \
{ \
   if ((u16CurrentLevel >= u16LowLimit) && (u16CurrentLevel <= u16HighLimit)) \
   { \
      DGOHAL_vidWrite(L9781_udtDGOHAL_VBOOST_DIAG_CH, \
                      DGOHAL_bfVALID_VBOOST_UNDER_VOLTAGE, \
                      DGOHAL_bfNO_FAULT_VBOOST_UNDER_VOLTAGE); \
      DGOHAL_vidWrite(L9781_udtDGOHAL_VBOOST_DIAG_CH, \
                      DGOHAL_bfVALID_VBOOST_OVER_VOLTAGE, \
                      DGOHAL_bfNO_FAULT_VBOOST_OVER_VOLTAGE);  \
   } \
   else \
   { \
      if (L9781_u16VboostVoltage > u16HighLimit) \
      { \
         DGOHAL_vidWrite(L9781_udtDGOHAL_VBOOST_DIAG_CH, \
                         DGOHAL_bfVALID_VBOOST_OVER_VOLTAGE, \
                         DGOHAL_bfFAULT_VBOOST_OVER_VOLTAGE); \
      } \
      else \
      { \
         DGOHAL_vidWrite(L9781_udtDGOHAL_VBOOST_DIAG_CH, \
                         DGOHAL_bfVALID_VBOOST_UNDER_VOLTAGE, \
                         DGOHAL_bfFAULT_VBOOST_UNDER_VOLTAGE); \
      } \
   } \
} \
while (0u)

/**********************************************************************************************************************/
/* !FuncName    : L9781_bGET_ACTUATION_STATUS                                                                         */
/* !Description : Returns a boolean variable at TRUE if an actuation has occured for the considered bank otherwise    */
/*                FALSE.                                                                                              */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_bGET_ACTUATION_STATUS( \
\
   snBank \
\
) \
 \
   L9781_abActStatus[L9781_u8##snBank]

/**********************************************************************************************************************/
/* !FuncName    : L9781_bGET_OVL_SPI_DIAG_MODE                                                                        */
/* !Description : Returns a boolean variable at TRUE if only OVL diagnosis shall be performed and FALSE if all        */
/*                diagnosis shall be performed.                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define L9781_bGET_OVL_SPI_DIAG_MODE( \
\
   snAsic \
\
) \
 \
   L9781_abOnlyOvlSpiDiagMode[L9781_u8##snAsic##_CHANNEL]


/**********************************************************************************************************************/
/* FUNCTIONS                                                                                                          */
/**********************************************************************************************************************/

#define L9781_START_SEC_CODE
#include "L9781_MemMap.h"

extern void L9781_vidAnalyzeDiag(uint8 u8Channel);
extern void L9781_vidEnterStopMode(void);
extern void L9781_vidInternalInit(void);
extern void L9781_vidLoadFrameDiag(void);
extern void L9781_vidReadFrameDiag(uint8 u8Channel);
extern void L9781_vidReInit(void);
extern void L9781_vidSpiCheckFrameEcho(void);
extern void L9781_vidSpiFifoRequest(void);
extern void L9781_vidSpiManager(uint8 u8Channel);
extern void L9781_vidSpiStartInit(uint8 u8Channel);
extern void L9781_vidUnlockSequence(uint8 u8Channel);
extern uint32 L9781_u32CalcOddParity(uint32 u32Data);

#define L9781_STOP_SEC_CODE
#include "L9781_MemMap.h"

#endif /* L9781_I_H */

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/

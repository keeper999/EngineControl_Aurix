/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9781                                                                                           */
/* !Description     : L9781 ASIC Abstraction Layer                                                                    */
/*                                                                                                                    */
/* !File            : L9781_I.c                                                                                       */
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
 * %PID: P2017_BSW:0A189049.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"

#include "L9781.h"
#include "L9781_CFG_E.h"
#include "L9781_CFG_I.h"
#include "L9781_I.h"
#include "L9781_L.h"

#include "DGOHAL.h"
#include "Dio.h"
#include "Gpt.h"
#include "Pwm.h"
#include "SchM_L9781.h"
#include "SWFAIL.h"

#define L9781_START_SEC_CODE
#include "L9781_MemMap.h"


/**********************************************************************************************************************/
/* !FuncName    : L9781_vidStartupSequence                                                                            */
/* !Description : Manages the Startup Sequence with appropriate Time between CLK_Ext --> RST and RST --> SPI.         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidStartupSequence(void)
{
   switch (L9781_enuStartupState)
   {
      case L9781_enuSTART_RST_ACTIVE_LVL:
         Dio_WriteChannel(L9781_snDIO_ENABLE_CH, STD_LOW);
         Dio_WriteChannel(L9781_snDIO_RST_CH, STD_LOW);
         if ((L9781_bFirstInitDone != FALSE) ||(L9781_u8SpiFailureNbAtInit < L9781_ku8MaxSpiFailureNbAtInit))
         {
            L9781_enuStartupState = L9781_enuSTART_CLK_EXT;
            L9781_vidPROG_CAPCOM_DELAY_STARTUP_SEQ(L9781_ku16RstActiveTime);
         }
         else
         {
            L9781_enuStartupState = L9781_enuSTART_END;
         }
         break;

      case L9781_enuSTART_CLK_EXT:
         Pwm_17_Gtm_SetPeriodAndDuty(L9781_snPWM_EXT_CLK_CH, L9781_udtPERIOD_EXT_CLK, L9781_u16DUTY_EXT_CLK);
         L9781_enuStartupState = L9781_enuSTART_RST_INACTIVE_LVL;

         L9781_vidPROG_CAPCOM_DELAY_STARTUP_SEQ(L9781_ku16ClkToRstTime);
         break;

      case L9781_enuSTART_RST_INACTIVE_LVL:
         Dio_WriteChannel(L9781_snDIO_RST_CH, STD_HIGH);
         L9781_enuStartupState = L9781_enuSTART_SPI_COM;

         L9781_vidPROG_CAPCOM_DELAY_STARTUP_SEQ(L9781_ku16RstToSpiTime);
         break;

      case L9781_enuSTART_SPI_COM:
         Gpt_StopTimer(L9781_snGPT_STARTUP_SEQ_CH);
         Gpt_DisableNotification(L9781_snGPT_STARTUP_SEQ_CH);
         L9781_enuStartupState = L9781_enuSTART_W_CBT_CHARGE;

         L9781_bStopModeActive = FALSE;
         L9781_vidSpiStartInit(L9781_u8FIRST_CHANNEL);
         break;

      case L9781_enuSTART_W_CBT_CHARGE:
         L9781_enuStartupState = L9781_enuSTART_ENABLE;
         L9781_vidPROG_CAPCOM_DELAY_STARTUP_SEQ(L9781_ku16WCbtChargeTime);
         break;

      case L9781_enuSTART_ENABLE:
         Gpt_StopTimer(L9781_snGPT_STARTUP_SEQ_CH);
         Gpt_DisableNotification(L9781_snGPT_STARTUP_SEQ_CH);
         L9781_enuStartupState = L9781_enuSTART_END;

         L9781_bStartupComplete = TRUE;
         if (L9781_bEnableRequest != FALSE)
         {
            Dio_WriteChannel(L9781_snDIO_ENABLE_CH, STD_HIGH);
            L9781_bEnableRequest = FALSE;
            L9781_bEnabled       = TRUE;
         }
         break;

      case L9781_enuSTART_END:
      default:
         SWFAIL_vidSoftwareErrorHook();
         L9781_enuStartupState = L9781_enuSTART_END;
         Gpt_StopTimer(L9781_snGPT_STARTUP_SEQ_CH);
         Gpt_DisableNotification(L9781_snGPT_STARTUP_SEQ_CH);
         break;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSpiStartInit                                                                               */
/* !Description : Initializes and starts the SPI communication on the current component index                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidSpiStartInit
(
   uint8 u8Channel
)
{
   L9781_u16SpiBufferTxMsw    = 0x0000u;
   L9781_u16SpiBufferTxLsw    = 0x0000u;
   L9781_u16SpiBufferRxMsw    = 0x0000u;
   L9781_u16SpiBufferRxLsw    = 0x0000u;
   L9781_bSpiMswFrameTransmit = FALSE;
   L9781_bSpiTxRequest        = FALSE;
   L9781_bSpiStartRequest     = FALSE;
   L9781_bSpiFifoRequest      = FALSE;
   L9781_u8SpiFrameIndex      = L9781_u8ID_FIRST_SPI_FRAME;
   L9781_u8ComponentIndex     = u8Channel;
   L9781_vidSpiManager(u8Channel);
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_u32CalcOddParity                                                                              */
/* !Description : Calculates the odd parity of u32Data                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
uint32 L9781_u32CalcOddParity
(
   uint32 u32Data
)
{
   uint8  u8NbOfOnes;
   uint32 u32LocalData;

   u8NbOfOnes   = 0u;
   u32LocalData = u32Data;

   while (u32LocalData != 0u)
   {
      u8NbOfOnes++;
      u32LocalData &= (u32LocalData - 1u);
   }

   return (uint32)(~(u8NbOfOnes & L9781_u32BIT_0_MASK));
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSpiCheckFrameEcho                                                                          */
/* !Description : Checks the SPI frame echo to update the SPI error counter                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidSpiCheckFrameEcho(void)
{
   uint32  u32LocalTxFrame;
   uint32  u32LocalRxFrame;
   uint32  u32LocalTxFrameAddress;
   uint32  u32LocalTxFrameEchoAddress;
   uint32  u32LocalCorruptedEchoAddress;
   uint32  u32LocalTxFrameData;
   uint32  u32LocalTxFrameEchoData;
   uint32  u32LocalTxFrameCommand;
   uint32  u32LocalTxFrameEchoCommand;
   boolean bLocalSpiAddressCorrupted;
   boolean bLocalSpiDataCorrupted;
   boolean bLocalSpiCommandCorrupted;

   u32LocalTxFrame = (uint32)( ((uint32)(((uint32)L9781_u16SpiBufferTxMsw) << L9781_u8SHIFT_16_BITS))
                             | ((uint32)L9781_u16SpiBufferTxLsw));

   u32LocalRxFrame = (uint32)( ((uint32)(((uint32)L9781_u16SpiBufferRxMsw) << L9781_u8SHIFT_16_BITS))
                             | ((uint32)L9781_u16SpiBufferRxLsw));

   u32LocalTxFrameAddress = u32LocalTxFrame & L9781_u32MASK_ADDR;

   u32LocalTxFrameEchoAddress = (((uint32)(u32LocalRxFrame << 1u)) & L9781_u32MASK_ADDR);

   if (u32LocalTxFrameAddress != u32LocalTxFrameEchoAddress)
   {
      bLocalSpiAddressCorrupted = TRUE;
   }
   else
   {
      bLocalSpiAddressCorrupted = FALSE;
   }

   if (L9781_enuLoadingState == L9781_enuLOAD_DIAG)
   {
      bLocalSpiDataCorrupted = FALSE;
   }
   else
   {
      u32LocalTxFrameData =  u32LocalTxFrame & L9781_u32MASK_INPUT_DATA;

      u32LocalTxFrameEchoData = ((uint32)(u32LocalRxFrame << 1u)) & L9781_u32MASK_INPUT_DATA;

      if (u32LocalTxFrameData != u32LocalTxFrameEchoData)
      {
         bLocalSpiDataCorrupted = TRUE;
      }
      else
      {
         bLocalSpiDataCorrupted = FALSE;
      }
   }

   u32LocalTxFrameCommand = u32LocalTxFrame & L9781_u32MASK_CMD;

   u32LocalTxFrameEchoCommand = (((uint32)(u32LocalRxFrame << 1u)) & L9781_u32MASK_CMD);

   if (u32LocalTxFrameCommand != u32LocalTxFrameEchoCommand)
   {
      bLocalSpiCommandCorrupted = TRUE;
   }
   else
   {
      bLocalSpiCommandCorrupted = FALSE;
   }

   if (  (bLocalSpiAddressCorrupted == FALSE)
      && (bLocalSpiDataCorrupted    == FALSE)
      && (bLocalSpiCommandCorrupted == FALSE))
   {
      if (L9781_bSpiAddressFail != FALSE)
      {
         L9781_bSpiAddressFail = FALSE;
      }
      else
      {
         if (L9781_bSpiDataFail != FALSE)
         {
            L9781_bSpiDataFail = FALSE;
         }
      }
   }
   else
   {

      if (L9781_u8SpiErrorCnt < UINT8_MAX)
      {
         L9781_u8SpiErrorCnt++;
      }

      if (  (L9781_bStartupComplete == FALSE)
         || (L9781_bSpiAddressFail  != FALSE)
         || (L9781_bSpiDataFail     != FALSE)
         || (  (u32LocalTxFrameEchoCommand == L9781_u32SPI_WRITE_CMD)
            && (u32LocalTxFrameEchoAddress == (uint32)(L9781_udtADDR_PDRV_ENB << L9781_u8SHIFT_ADDR))))
      {
         DGOHAL_vidWrite(DGOHAL_udtL9781_ASIC_GDI, DGOHAL_bfVALID_SPI_FAILURE, DGOHAL_bfFAULT_SPI_FAILURE);
         if (L9781_bFirstInitDone == FALSE)
         {
            L9781_u8SpiFailureNbAtInit = L9781_u8SpiFailureNbAtInit + 1u;
         }
         L9781_bSpiComFailure = TRUE;
      }
      else
      {
         L9781_bSpiDataFail           = TRUE;
         L9781_u16SpiPrevFrameTxLsw   = L9781_u16SpiBufferTxLsw;
         L9781_u16SpiPrevFrameTxMsw   = L9781_u16SpiBufferTxMsw;
         u32LocalCorruptedEchoAddress = u32LocalTxFrameEchoAddress >> L9781_u8SHIFT_ADDR;
         if (  (bLocalSpiAddressCorrupted  != FALSE)
            && (u32LocalTxFrameEchoCommand == L9781_u32SPI_WRITE_CMD)
            && L9781_bIS_ADDRESS_CORRUPTIBLE(u32LocalCorruptedEchoAddress))
         {
            L9781_bSpiAddressFail = TRUE;
            L9781_u32SpiCorruptedAddress = u32LocalCorruptedEchoAddress;
         }
      }
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSpiManager                                                                                 */
/* !Description : Manages the SPI communication.                                                                      */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidSpiManager
(
   uint8 u8Channel
)
{
   uint8 u8LocalChannelToStart;

   u8LocalChannelToStart = L9781_u8CHANNEL_UNDEFINED;

   switch (L9781_enuLoadingState)
   {
      case L9781_enuLOAD_GEN_CONF:
         if (L9781_bStartupComplete == FALSE)
         {
            L9781_bSpiTxRequest = TRUE;
            L9781_vidSpiLoadGenConf(u8Channel);
            if (L9781_u8SpiFrameIndex == L9781_u8NB_FRAME_GEN_CONF)
            {
               L9781_u8SpiFrameIndex = L9781_u8ID_FIRST_SPI_FRAME;
               L9781_enuLoadingState = L9781_enuLOAD_INJ_PROF;
            }
         }
         else
         {
            SWFAIL_vidSoftwareErrorHook();
         }
         break;

      case L9781_enuLOAD_INJ_PROF:
         if (L9781_bStartupComplete == FALSE)
         {
            L9781_bSpiTxRequest = TRUE;
            L9781_vidSpiLoadInjProf(u8Channel);
            if (L9781_u8SpiFrameIndex == L9781_u8NB_FRAME_INJ_PROF)
            {
               L9781_bfInjProfUpdated |= (uint16)(0x0001U << (u8Channel));
               L9781_u8SpiFrameIndex   = L9781_u8ID_FIRST_SPI_FRAME;
               L9781_enuLoadingState   = L9781_enuLOAD_PMP_PROF;
            }
         }
         else
         {
            do
            {
               if (L9781_u8SpiFrameIndex < L9781_u8NB_FRAME_INJ_PROF)
               {
                  L9781_bCheckBuffer  = TRUE;
                  L9781_bSpiTxRequest = TRUE;
                  L9781_vidSpiLoadInjProf(u8Channel);
               }
               else
               {
                  L9781_bCheckBuffer      = FALSE;
                  L9781_bSpiTxRequest     = FALSE;
                  L9781_bfInjProfUpdated |= (uint16)(0x0001U << (u8Channel));
               }
            }
            while(L9781_bCheckBuffer != FALSE);

            if (L9781_bSpiTxRequest != FALSE)
            {
               L9781_u8InjFrameUpdtCnt++;
            }
         }
         break;

      case L9781_enuLOAD_PMP_PROF:
         if (L9781_bStartupComplete == FALSE)
         {
            L9781_bSpiTxRequest = TRUE;
            L9781_vidSpiLoadPmpProf(u8Channel);
            if (L9781_u8SpiFrameIndex == L9781_u8NB_FRAME_PMP_PROF)
            {
               L9781_bfPmpProfUpdated |= (uint16)(0x0001U << (u8Channel));
               L9781_u8SpiFrameIndex   = L9781_u8ID_FIRST_SPI_FRAME;
               L9781_enuLoadingState   = L9781_enuLOAD_PDRV_ENB;
            }
         }
         else
         {
            do
            {
               if (L9781_u8SpiFrameIndex < L9781_u8NB_FRAME_PMP_PROF)
               {
                  L9781_bCheckBuffer  = TRUE;
                  L9781_bSpiTxRequest = TRUE;
                  L9781_vidSpiLoadPmpProf(u8Channel);
               }
               else
               {
                  L9781_bCheckBuffer      = FALSE;
                  L9781_bSpiTxRequest     = FALSE;
                  L9781_bfPmpProfUpdated |= (uint16)(0x0001U << (u8Channel));
               }
            }
            while(L9781_bCheckBuffer != FALSE);

            if (L9781_bSpiTxRequest != FALSE)
            {
               L9781_u8PmpFrameUpdtCnt++;
            }
         }
         break;


      case L9781_enuLOAD_PDRV_ENB:
         if (L9781_bStartupComplete == FALSE)
         {
            L9781_enuLoadingState = L9781_enuLOAD_STARTUP_COMPLETE;
            L9781_u8SpiFrameIndex = L9781_u8ID_PDRV_ENB;
            L9781_bSpiTxRequest   = TRUE;
            L9781_vidSpiLoadGenConf(u8Channel);
         }
         else
         {
            SWFAIL_vidSoftwareErrorHook();
         }
         break;

      case L9781_enuLOAD_STARTUP_COMPLETE:
            if ( u8Channel < (uint8)(L9781_u8NB_ASIC - 1u))
            {
               L9781_enuLoadingState  = L9781_enuLOAD_GEN_CONF;
               L9781_u8SpiFrameIndex  = L9781_u8ID_UNDEFINED;
               L9781_bSpiStartRequest = TRUE;
               u8LocalChannelToStart  = (uint8)(u8Channel + 1u);
            }
            else
            {
               L9781_bSpiStartRequest = FALSE;
               if (L9781_bFirstInitDone == FALSE)
               {
                  L9781_bFirstInitDone = TRUE;
               }
               L9781_vidStartupSequence();
            }
         break;

      case L9781_enuLOAD_DIAG:
         if (L9781_bStartupComplete != FALSE)
         {
            if (L9781_bReadDiagValid == TRUE)
            {
               L9781_vidReadFrameDiag(u8Channel);
            }

            if (L9781_u8SpiFrameIndex < L9781_u8NB_FRAME_DIAG)
            {
               L9781_bSpiTxRequest  = TRUE;
               L9781_bReadDiagValid = TRUE;
               L9781_vidLoadFrameDiag();
            }
            else
            {
               L9781_u8SpiFrameIndex = L9781_u8ID_FIRST_SPI_FRAME;
               L9781_bReadDiagValid  = FALSE;
               L9781_bSpiTxRequest   = FALSE;

               if (L9781_abFirstDiagRead[u8Channel] != FALSE)
               {
                  L9781_abFirstDiagRead[u8Channel] = FALSE;
                  L9781_vidAnalyzeDiag(u8Channel);
                  L9781_vidUpdateDiag(u8Channel);
               }
               else
               {
                  L9781_abFirstDiagRead[u8Channel] = TRUE;
               }

               L9781_bfDiagComplete |= (uint16)(0x0001U << u8Channel);
            }
         }
         else
         {
            SWFAIL_vidSoftwareErrorHook();
         }
         break;

      case L9781_enuLOAD_UNLOCK:
         if (L9781_bStartupComplete != FALSE)
         {
            if (L9781_au32BankToUnlock[u8Channel] != L9781_u32NO_BANK_TO_UNLOCK)
            {
               L9781_bSpiTxRequest = TRUE;
               L9781_vidSpiLoadUnlock(u8Channel);
               L9781_au32BankToUnlock[u8Channel] = L9781_u32NO_BANK_TO_UNLOCK;
            }
            else
            {
               L9781_bSpiTxRequest = FALSE;
            }
         }
         else
         {
            SWFAIL_vidSoftwareErrorHook();
         }
         break;

      case L9781_enuLOAD_IDLE:
         L9781_u8SpiFrameIndex  = L9781_u8ID_UNDEFINED;
         L9781_bSpiStartRequest = FALSE;
         L9781_bSpiTxRequest    = FALSE;
         SWFAIL_vidSoftwareErrorHook();
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         L9781_bSpiStartRequest = FALSE;
         L9781_bSpiTxRequest    = FALSE;
         break;
   }

   if (L9781_bSpiTxRequest != FALSE)
   {
      L9781_vidSpiRequest(u8Channel);
   }
   else
   {
      if (L9781_bSpiStartRequest != FALSE)
      {
         L9781_vidSpiStartInit(u8LocalChannelToStart);
      }
      else
      {
         if (L9781_u8NbSpiRequest != 0u)
         {
            L9781_vidSpiFifoRequest();
         }
         else
         {
            L9781_enuLoadingState = L9781_enuLOAD_IDLE;
         }
      }
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSpiFifoRequest                                                                             */
/* !Description : Manage the SPI request for Injection and Pump profile switching.                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidSpiFifoRequest(void)
{
   uint8 u8LocalChannel;
   uint8 u8LocalRequestType;


   u8LocalChannel     = L9781_au8FifoSpiReqCh[0u];
   u8LocalRequestType = L9781_au8FifoSpiReqTyp[0u];

   if ((u8LocalChannel <  L9781_u8NB_ASIC) && (L9781_u8NbSpiRequest <= L9781_u8NB_SPI_REQ_MAX))
   {
      L9781_bSpiFifoRequest = TRUE;

      switch (u8LocalRequestType)
      {
         case L9781_u8LOAD_INJ_PROF_REQ:
            L9781_enuLoadingState   = L9781_enuLOAD_INJ_PROF;
            L9781_u8InjProfileIndex = L9781_au8InjProfile[u8LocalChannel];
            L9781_vidCLEAR_SPI_REQUEST(u8LocalChannel, LOAD_INJ_PROF);
            break;

         case L9781_u8LOAD_PMP_PROF_REQ:
            L9781_enuLoadingState   = L9781_enuLOAD_PMP_PROF;
            L9781_u8PmpProfileIndex = L9781_au8PmpProfile[u8LocalChannel];
            L9781_vidCLEAR_SPI_REQUEST(u8LocalChannel, LOAD_PMP_PROF);
            break;

         case L9781_u8LOAD_DIAG_REQ:
            L9781_enuLoadingState   = L9781_enuLOAD_DIAG;
            L9781_vidCLEAR_SPI_REQUEST(u8LocalChannel, LOAD_DIAG);
            break;

         case L9781_u8LOAD_UNLOCK_REQ:
            L9781_enuLoadingState   = L9781_enuLOAD_UNLOCK;
            L9781_vidCLEAR_SPI_REQUEST(u8LocalChannel, LOAD_UNLOCK);
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            L9781_enuLoadingState   = L9781_enuLOAD_IDLE;
            L9781_bSpiFifoRequest   = FALSE;
            break;
      }

   }
   else
   {
      L9781_bSpiFifoRequest = FALSE;
      SWFAIL_vidSoftwareErrorHook();
   }

   if (L9781_bSpiFifoRequest != FALSE)
   {
      L9781_vidSpiStartInit(u8LocalChannel);
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidUnlockSequence                                                                             */
/* !Description : Manages the Unlock Sequence and send an Unlock SPI Frame to unlock all failed banks.                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidUnlockSequence
(
   uint8 u8Channel
)
{
   SchM_Enter_L9781_vidUnlockSeq();
   if ((L9781_enuLoadingState == L9781_enuLOAD_IDLE) && (L9781_u8NbSpiRequest == 0u))
   {
      L9781_enuLoadingState = L9781_enuLOAD_UNLOCK;
      L9781_vidSpiStartInit(u8Channel);
   }
   else
   {
      L9781_vidSET_SPI_REQUEST(u8Channel, LOAD_UNLOCK);
   }
   SchM_Exit_L9781_vidUnlockSeq();
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidInternalInit                                                                               */
/* !Description : Initializes all the internal data of component, regardless if it is a startup initialization or a   */
/*                run-time re-initialization.                                                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidInternalInit(void)
{
   uint8 u8LocalAsicIndex;
   uint8 u8LocalBankIndex;

/* !Comment: Init component STATUS */
   L9781_bEnabled               = FALSE;
   L9781_bStartupComplete       = FALSE;

/* !Comment: Init SPI */
   L9781_enuLoadingState        = L9781_enuLOAD_GEN_CONF;
   L9781_u8ComponentIndex       = L9781_u8CHANNEL_UNDEFINED;
   L9781_u8InjProfileIndex      = L9781_u8IDX_INJ_PROF_DEF;
   L9781_u8PmpProfileIndex      = L9781_u8IDX_PMP_PROF_DEF;
   L9781_u8SpiFrameIndex        = L9781_u8ID_UNDEFINED;
   L9781_bfLoadDiagReq          = L9781_bfNO_SPI_REQUEST;
   L9781_bfLoadInjProfReq       = L9781_bfNO_SPI_REQUEST;
   L9781_bfLoadPmpProfReq       = L9781_bfNO_SPI_REQUEST;
   L9781_bfLoadUnlockReq        = L9781_bfNO_SPI_REQUEST;
   L9781_bfInjProfUpdated       = L9781_bfPROFILE_NOT_UPDATED;
   L9781_bfPmpProfUpdated       = L9781_bfPROFILE_NOT_UPDATED;
   L9781_u16SpiBufferTxMsw      = L9781_u16BUFFER_UNDEFINED;
   L9781_u16SpiBufferTxLsw      = L9781_u16BUFFER_UNDEFINED;
   L9781_u16SpiPrevFrameTxMsw   = L9781_u16BUFFER_UNDEFINED;
   L9781_u16SpiPrevFrameTxLsw   = L9781_u16BUFFER_UNDEFINED;
   L9781_u16SpiBufferRxMsw      = L9781_u16BUFFER_UNDEFINED;
   L9781_u16SpiBufferRxLsw      = L9781_u16BUFFER_UNDEFINED;
   L9781_u8InjFrameUpdtCnt      = 0u;
   L9781_u8PmpFrameUpdtCnt      = 0u;
   L9781_u8NbSpiRequest         = 0u;
   L9781_bCheckBuffer           = FALSE;
   L9781_bSpiTxRequest          = FALSE;
   L9781_bSpiMswFrameTransmit   = FALSE;
   L9781_bSpiComFailure         = FALSE;
   L9781_bSpiStartRequest       = FALSE;
   L9781_bSpiFifoRequest        = FALSE;
   L9781_bSpiAddressFail        = FALSE;
   L9781_bSpiDataFail           = FALSE;
   L9781_u32SpiCorruptedAddress = L9781_udtADDR_GEN_CONF;

/* !Comment: Init DIAG */
   L9781_bfDiagComplete         = L9781_bfIRQ_DIAG_INIT;
   L9781_bReadDiagValid         = FALSE;

   for(u8LocalAsicIndex = L9781_u8FIRST_CHANNEL; u8LocalAsicIndex < L9781_u8NB_ASIC; u8LocalAsicIndex++)
   {
      L9781_au32BankToUnlock[u8LocalAsicIndex]     = L9781_u32NO_BANK_TO_UNLOCK;
      L9781_abFirstDiagRead[u8LocalAsicIndex]      = FALSE;
      L9781_abOnlyOvlSpiDiagMode[u8LocalAsicIndex] = FALSE;

      for (u8LocalBankIndex = L9781_u8FIRST_CHANNEL; u8LocalBankIndex < L9781_u8NB_BANK; u8LocalBankIndex++)
      {
         L9781_au8UnlockTimeOut[u8LocalBankIndex][u8LocalAsicIndex]   = 0u;
         L9781_au16FailureCounter[u8LocalBankIndex][u8LocalAsicIndex] = 0u;
      }
   }

   L9781_vidStartupSequence();

   /* !Comment : Reload authorisation delay at each re-initisialisation. */
   L9781_u8VboostAuthDiagDcntr = L9781_ku8VboostAuthDiagDly;
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidReInit                                                                                     */
/* !Description : Launches the re-initialization of the component in run-time.                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidReInit(void)
{
   L9781_enuStartupState = L9781_enuSTART_RST_ACTIVE_LVL;
   L9781_bEnableRequest  |= L9781_bEnabled;
   L9781_vidInternalInit();
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidEnterStopMode                                                                              */
/* !Description : Forces the L9781 to enter in stop mode (permament RESET).                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidEnterStopMode(void)
{
   SchM_Enter_L9781_vidEnterStopMod();

   /* !Comment: Clear Transmission Request Flags */
   L9781_bSpiTxRequest   = FALSE;
   L9781_bStopModeActive = TRUE;

   /* !Comment: Force RESET pin to its active state */
   Dio_WriteChannel(L9781_snDIO_RST_CH, STD_LOW);

   L9781_bEnableRequest |= L9781_bEnabled;

   /* !Comment: Force to Enable Pin of the ASIC GDI to LOW. Set also */
   /*           the L9781_bEnabled to FALSE in order to be coherent  */
   /*           with Enable pin state.                               */
   Dio_WriteChannel(L9781_snDIO_ENABLE_CH, STD_LOW);
   L9781_bEnabled = FALSE;

   SchM_Exit_L9781_vidEnterStopMod();
}


#define L9781_STOP_SEC_CODE
#include "L9781_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/


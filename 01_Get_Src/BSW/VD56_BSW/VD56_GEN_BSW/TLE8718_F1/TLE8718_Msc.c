/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver To Manage TLE8718 Device                                                                 */
/*                                                                                                                    */
/* !File            : TLE8718_Msc.c                                                                                   */
/* !Description     : Low Level MSC Protocol                                                                          */
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
 * %PID: P2017_BSW:0A133944.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "HOD.h"
#include "Msc.h"
#include "Msc_Add_On.h"
#include "TLE8718_co_Cfg.h"
#include "TLE8718_L.h"
#include "TLE8718_Msc.h"
#include "TLE8718_MscM.h"
#include "TLE8718_Typ.h"

#ifndef TLE8718_coDMA_USE_FOR_FRAME_RX
   #error The macro-constant TLE8718_coDMA_USE_FOR_FRAME_RX shall be defined
#endif
#ifndef TLE8718_coDISABLED
   #error The macro-constant TLE8718_coDISABLED shall be defined
#endif

/**********************************************************************************************************************/
/* FUNCTION DEFINITION                                                                                                */
/**********************************************************************************************************************/
#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

LOCAL_INLINE uint8 TLE8718_u8MscGetRxData(uint32 u32RxFrame);
LOCAL_INLINE uint8 TLE8718_u8MscGetRxStatus(uint32 u32RxFrame);

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscInit                                                                                  */
/* !Description : Init Function of Msc Layer                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscInit(void)
{
   HOD_tudtInstance udtLocalInstance;
   uint8_least u8LocalCnt;

   for (udtLocalInstance = 0u; udtLocalInstance < TLE8718_udtINSTANCE_NB; udtLocalInstance++)
   {
      TLE8718_au8MscErrorFrameCnt[udtLocalInstance] = UINT8_MIN;
      for (u8LocalCnt = 0u; u8LocalCnt < 8u; u8LocalCnt++)
      {
         TLE8718_au32MscRxFrame[udtLocalInstance][u8LocalCnt] = UINT32_MIN;
         TLE8718_au8MscRxData[udtLocalInstance][u8LocalCnt]   = UINT8_MIN;
      }
      TLE8718_vidMSC_DISA_TX_CMD_IT(udtLocalInstance);
      TLE8718_vidMSC_DISA_RX_FRAME_IT(udtLocalInstance);
      TLE8718_vidMSC_STOP_TIMEOUT_IT(udtLocalInstance);
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscStartCommand                                                                          */
/* !Description : Start Msc Command                                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscStartCommand
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier. */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
   uint8 u8CmdIdentifier,
   uint8 u8CmdData,
   uint8 u8ExpectedRxFrameNb
)
{
   uint16 u16LocalCmdFrameData;

   TLE8718_au8MscCmdId[udtInstance]             = u8CmdIdentifier;
   TLE8718_au8MscCmdData[udtInstance]           = u8CmdData;
   TLE8718_au8MscExpectedRxFrameNb[udtInstance] = u8ExpectedRxFrameNb;

   #if (TLE8718_coDMA_USE_FOR_FRAME_RX == TLE8718_coDISABLED)
   TLE8718_au8MscRxFrameId[udtInstance] = 0u;
   #endif /* if (TLE8718_coDMA_USE_FOR_FRAME_RX == TLE8718_coDISABLED) */

   u16LocalCmdFrameData = (uint16)(TLE8718_au8MscCmdId[udtInstance] | (TLE8718_au8MscCmdData[udtInstance] << 5u));
   TLE8718_vidMSC_ENA_TX_CMD_IT(udtInstance);
   TLE8718_vidMSC_START_TIMEOUT_IT(udtInstance);
   Msc_TxCmdFrame(TLE8718_kau8Module[udtInstance], TLE8718_kaudtTxDevice[udtInstance], u16LocalCmdFrameData);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscRxFrameNotif                                                                          */
/* !Description : MSC Rx Frame Notification Callback                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscRxFrameNotif
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   uint8_least u8LocalRxBufferIdx;
   uint8       u8LocalRxStatus = TLE8718_u8MSC_COM_OK;
   uint32      u32LocalRxFrame;

   #if (TLE8718_coDMA_USE_FOR_FRAME_RX == TLE8718_coDISABLED)
   uint32 u32LocalRxDataRegAddress;

   if (TLE8718_au8MscRxFrameId[udtInstance] < TLE8718_au8MscExpectedRxFrameNb[udtInstance])
   {
      Msc_vidGetRxDataRegAddress(TLE8718_kau8Module[udtInstance], &u32LocalRxDataRegAddress);
      TLE8718_au32MscRxFrame[udtInstance][TLE8718_au8MscRxFrameId[udtInstance]] = *((uint32*)u32LocalRxDataRegAddress);
      TLE8718_au8MscRxFrameId[udtInstance]++;
   }
   if (TLE8718_au8MscRxFrameId[udtInstance] == TLE8718_au8MscExpectedRxFrameNb[udtInstance])
   {
   #endif /* if (TLE8718_coDMA_USE_FOR_FRAME_RX == TLE8718_coDISABLED) */

   TLE8718_vidMSC_STOP_TIMEOUT_IT(udtInstance);
   TLE8718_vidMSC_DISA_RX_FRAME_IT(udtInstance);

   for (u8LocalRxBufferIdx = 0u;
        (  (u8LocalRxBufferIdx < TLE8718_au8MscExpectedRxFrameNb[udtInstance])
        && (u8LocalRxStatus == TLE8718_u8MSC_COM_OK));
        u8LocalRxBufferIdx++)
   {
      u32LocalRxFrame = TLE8718_au32MscRxFrame[udtInstance][u8LocalRxBufferIdx];
      u8LocalRxStatus = TLE8718_u8MscGetRxStatus(u32LocalRxFrame);
      TLE8718_au8MscRxData[udtInstance][u8LocalRxBufferIdx] = TLE8718_u8MscGetRxData(u32LocalRxFrame);
   }
   if (u8LocalRxStatus != TLE8718_u8MSC_COM_OK)
   {
      TLE8718_au8MscErrorFrameCnt[udtInstance]++;
      if (TLE8718_au8MscErrorFrameCnt[udtInstance] > TLE8718_u8MSC_ERROR_FRAME_MAX)
      {
         TLE8718_au8MscErrorFrameCnt[udtInstance] = UINT8_MIN;
         TLE8718_vidMscM_ManagerTxConf(udtInstance, &TLE8718_au8MscRxData[0u][0u], u8LocalRxStatus);
      }
      else
      {
         /* Send Again the Request */
         TLE8718_vidMscStartCommand(udtInstance,
                                    TLE8718_au8MscCmdId[udtInstance],
                                    TLE8718_au8MscCmdData[udtInstance],
                                    TLE8718_au8MscExpectedRxFrameNb[udtInstance]);
      }
   }
   else
   {
      TLE8718_au8MscErrorFrameCnt[udtInstance] = UINT8_MIN;
      TLE8718_vidMscM_ManagerTxConf(udtInstance, &TLE8718_au8MscRxData[0u][0u], u8LocalRxStatus);
   }
   #if (TLE8718_coDMA_USE_FOR_FRAME_RX == TLE8718_coDISABLED)
   }
   #endif /* if (TLE8718_coDMA_USE_FOR_FRAME_RX == TLE8718_coDISABLED) */
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscTxFrameNotif                                                                          */
/* !Description : MSC Tx Frame Notification Callback                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscTxFrameNotif
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   uint8 u8LocalMscExpectedRxFrameNb;

   TLE8718_vidMSC_DISA_TX_CMD_IT(udtInstance);

   u8LocalMscExpectedRxFrameNb = TLE8718_au8MscExpectedRxFrameNb[udtInstance];

   if (u8LocalMscExpectedRxFrameNb != 0u)
   {
      TLE8718_vidMSC_ENA_RX_FRAME_IT(udtInstance, u8LocalMscExpectedRxFrameNb);
   }
   else
   {
      TLE8718_vidMSC_STOP_TIMEOUT_IT(udtInstance);
      TLE8718_au8MscErrorFrameCnt[udtInstance] = UINT8_MIN;
      TLE8718_vidMscM_ManagerTxConf(udtInstance, &TLE8718_au8MscRxData[0u][0u], TLE8718_u8MSC_COM_OK);
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscTimeoutNotif                                                                          */
/* !Description : MSC  Timeout for Rx&Tx Frame                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscTimeoutNotif
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   uint8 u8LocalRxStatus = TLE8718_u8MSC_TIMEOUT;

   TLE8718_vidMSC_DISA_RX_FRAME_IT(udtInstance);
   TLE8718_vidMSC_DISA_TX_CMD_IT(udtInstance);
   TLE8718_vidMSC_STOP_TIMEOUT_IT(udtInstance);

   TLE8718_au8MscErrorFrameCnt[udtInstance]++;
   if (TLE8718_au8MscErrorFrameCnt[udtInstance] > TLE8718_u8MSC_ERROR_FRAME_MAX)
   {
      TLE8718_au8MscErrorFrameCnt[udtInstance] = UINT8_MIN;
      TLE8718_vidMscM_ManagerTxConf(udtInstance, &TLE8718_au8MscRxData[0u][0u], u8LocalRxStatus);
   }
   else
   {
      /* Send Again the Request */
      TLE8718_vidMscStartCommand(udtInstance,
                                 TLE8718_au8MscCmdId[udtInstance],
                                 TLE8718_au8MscCmdData[udtInstance],
                                 TLE8718_au8MscExpectedRxFrameNb[udtInstance]);
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscGetRxStatus                                                                           */
/* !Description : To Get Status of Received Frame                                                                     */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE uint8 TLE8718_u8MscGetRxStatus(uint32 u32RxFrame)
{
   uint8 u8LocalStatus;

/* dbg: To improve */
   if ((u32RxFrame & 0x00400000u) == 0x00400000u) /* Check Parity Bit */
   {
     u8LocalStatus = TLE8718_u8MSC_FAILURE;
   }
   /* Valid data frame is received */
   else
   {
      if((u32RxFrame & 0x00010000u) == 0x00010000u)  /* Check Validity Bit */
      {
         u8LocalStatus = TLE8718_u8MSC_COM_OK;
      }
      /* No response, data frame not received */
      else
      {
         u8LocalStatus = TLE8718_u8MSC_FAILURE;
      }
   }
   return (u8LocalStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscGetRxStatus                                                                           */
/* !Description : To Get Data of Received Frame                                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE uint8 TLE8718_u8MscGetRxData(uint32 u32RxFrame)
{
   uint8 u8LocalData;

/* dbg: To improve */
   u8LocalData = (uint8)(u32RxFrame);
   return (u8LocalData);
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

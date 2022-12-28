/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9781                                                                                           */
/* !Description     : L9781 ASIC Abstraction Layer                                                                    */
/*                                                                                                                    */
/* !File            : L9781_CFG_E.c                                                                                   */
/* !Description     : Configuration of the L9781 Component                                                            */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* 1 / L9781_vidSpiTx_ST1                                                     */
/* 2 / L9781_vidSpiTx_ST2                                                     */
/* 3 / L9781_vidSpiRx_ST1                                                     */
/* 4 / L9781_vidSpiRx_ST2                                                     */

#include "Std_Types.h"

#include "L9781.h"
#include "L9781_CFG_E.h"
#include "L9781_CFG_I.h"
#include "L9781_I.h"
#include "L9781_L.h"

#include "Spi.h"

#define L9781_START_SEC_CODE
#include "L9781_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSpiRxST1 */
/* !Description : Callback of SPI Rx to transmit the current frame on ST1 channel */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidSpiRx_ST1(void)
{
   if (L9781_bStopModeActive == FALSE)
   {
      L9781_vidSPI_RX(L9781_snSPI_ST1_CH);
      L9781_vidSpiCheckFrameEcho();
      if ((L9781_bSpiDataFail == FALSE) && (L9781_bSpiAddressFail == FALSE) && (L9781_bSpiComFailure == FALSE))
      {
         L9781_vidSpiManager(L9781_u8ST1_CHANNEL);
      }
      else
      {
         if (L9781_bSpiComFailure != FALSE)
         {
            L9781_vidReInit();
         }
         else
         {
            if (L9781_bSpiAddressFail != FALSE)
            {
               L9781_vidPREP_SPI_SINGLE_FRAME(ST1, L9781_u32SpiCorruptedAddress);
               if (L9781_bSpiTxRequest != FALSE)
               {
                  L9781_vidSpiRequest(L9781_u8ST1_CHANNEL);
               }
               else
               {
/* !MComment : This case only occurs when the default case of the        */
/*             L9781_vidPREP_SPI_SINGLE_FRAME function has been reached. */
                  L9781_vidReInit();
               }
            }
            else
            {
               L9781_u16SpiBufferTxLsw = L9781_u16SpiPrevFrameTxLsw;
               L9781_u16SpiBufferTxMsw = L9781_u16SpiPrevFrameTxMsw;
               L9781_vidSpiRequest(L9781_u8ST1_CHANNEL);
            }
         }
      }
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSpiRxST2 */
/* !Description : Callback of SPI Rx to transmit the current frame on ST2 channel */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidSpiRx_ST2(void)
{
   if (L9781_bStopModeActive == FALSE)
   {
      L9781_vidSPI_RX(L9781_snSPI_ST2_CH);
      L9781_vidSpiCheckFrameEcho();
      if ((L9781_bSpiDataFail == FALSE) && (L9781_bSpiAddressFail == FALSE) && (L9781_bSpiComFailure == FALSE))
      {
         L9781_vidSpiManager(L9781_u8ST2_CHANNEL);
      }
      else
      {
         if (L9781_bSpiComFailure != FALSE)
         {
            L9781_vidReInit();
         }
         else
         {
            if (L9781_bSpiAddressFail != FALSE)
            {
               L9781_vidPREP_SPI_SINGLE_FRAME(ST2, L9781_u32SpiCorruptedAddress);
               if (L9781_bSpiTxRequest != FALSE)
               {
                  L9781_vidSpiRequest(L9781_u8ST2_CHANNEL);
               }
               else
               {
/* !MComment : This case only occurs when the default case of the        */
/*             L9781_vidPREP_SPI_SINGLE_FRAME function has been reached. */
                  L9781_vidReInit();
               }
            }
            else
            {
               L9781_u16SpiBufferTxLsw = L9781_u16SpiPrevFrameTxLsw;
               L9781_u16SpiBufferTxMsw = L9781_u16SpiPrevFrameTxMsw;
               L9781_vidSpiRequest(L9781_u8ST2_CHANNEL);
            }
         }
      }
   }
}


#define L9781_STOP_SEC_CODE
#include "L9781_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/

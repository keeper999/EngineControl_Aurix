/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TLF35584                                                */
/* !Description     : TLF35584 safe supply device management                  */
/*                                                                            */
/* !File            : TLF35584.c                                              */
/* !Description     : Send the init frames for TLF35584 configuration         */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  :  C                                                      */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A53915.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "OS.h"
#include "SPI.h"
#include "TLF35584.h"


#define TLF35584_START_SEC_CODE
#include "TLF35584_MemMap.h"

/******************************************************************************/
/* !FuncName    : TLF35584_vidInit                                            */
/* !Description : Init of TLF35584 variables and initiation of SPI sequence   */
/*                                                                            */
/* !LastAuthor  : K. Choletais                                                */
/******************************************************************************/
void TLF35584_vidInit(void)
{
   uint8 u8LocalIndex;


   TLF35584_u8IndexFrame = UINT8_MIN;

   for (u8LocalIndex = UINT8_MIN; u8LocalIndex < TLF35584_u8NB_FRAME_SEQ_INIT; u8LocalIndex++)
   {
      TLF35584_au16SpiFrameReceived[u8LocalIndex] = UINT16_MIN;
   }

   /* !Comment: initiates SPI sequence                                        */
   (void)Spi_WriteIB(SpiConf_SpiChannel_TLF35584_CH,
                     (const uint8 *)&TLF35584_kau16SpiFramesInit[UINT8_MIN]);
   (void)Spi_AsyncTransmit(SpiConf_SpiSequence_TLF35584_SEQ);
}

/******************************************************************************/
/* !FuncName    : TLF35584_vidSpiEndNotification                              */
/* !Description : End of SEQUENCE notification used to end the remaining      */
/*                configuration frames.                                       */
/*                                                                            */
/* !LastAuthor  : K. Choletais                                                */
/******************************************************************************/
void TLF35584_vidSpiEndNotification(void)
{
   if (TLF35584_u8IndexFrame < TLF35584_u8NB_FRAME_SEQ_INIT)
   {
      (void)Spi_ReadIB(SpiConf_SpiChannel_TLF35584_CH,
                       (uint8 *)&TLF35584_au16SpiFrameReceived[TLF35584_u8IndexFrame]);
   }

   TLF35584_u8IndexFrame++;

   if (TLF35584_u8IndexFrame < TLF35584_u8NB_FRAME_SEQ_INIT)
   {
      (void)Spi_WriteIB(SpiConf_SpiChannel_TLF35584_CH,
                        (const uint8 *)&TLF35584_kau16SpiFramesInit[TLF35584_u8IndexFrame]);
      (void)Spi_AsyncTransmit(SpiConf_SpiSequence_TLF35584_SEQ);
   }
}


#define TLF35584_STOP_SEC_CODE
#include "TLF35584_MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_Spi.c                                                                                     */
/* !Description     : Low level SPI protocol                                                                          */
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
 * %PID: LIBEMB:A6035.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Spi.h"
#include "L9960.h"
#include "L9960_Private.h"
#include "L9960_Spi.h"
#include "L9960_SpiM.h"
#include "L9960_Types.h"
#include "SchM_L9960.h"


/**********************************************************************************************************************/
/* FUNCTION DEFINITION                                                                                                */
/**********************************************************************************************************************/
#define L9960_START_SEC_CODE
#include "L9960_MemMap.h"


/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiInit                                                                                    */
/* !Description : Init function of Spi layer                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiInit(const L9960_tstrConfig *pkstrConfig,
                      L9960_strData          *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   
   pstrData->u16SpiLastSentCommand     = 0;   /* done but don't care, will be write before used */
   pstrData->u8SpiDiagnostic           = L9960_u8SPI_OK;
   pstrData->u8SpiTransmitErrorCounter = 0;

   pstrData->bSpiDummyFrameSent = FALSE;   /* done but don't care, will be write before used */
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiTxConfirmation                                                                          */
/* !Description : This function is called by all SPI handler end of seqeunce notification                             */
/*                The L9960_Cfg.c provide on confirmation by instance, which call this function with good parameters  */
/*                For efficency, the CFG compute, in pre-build, most of needed parameters.                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiTxConfirmation(const L9960_tstrConfig *pkstrConfig,
                                L9960_strData          *pstrData,
                                uint16                  u16ReceiveData)
{
   uint8 u8LocSpiResult = L9960_u8SPI_OK;

   if(pstrData->bSpiDummyFrameSent == FALSE)
   {
      if( ( (L9960_u16DUMMY_FRAME_CMD & 0xF000u) != (u16ReceiveData & 0xF000u) )
            && (u16ReceiveData != 0x0000u))
      {
         /* The address field of the answer must be the same as the one of the request.                */
         /* Otherwise, that means that L9960 understood another request and done an unexpected command */
         /* which can result to a register corruption.                                                 */
         L9960_vidSpiM_ManagerTxConf(pkstrConfig, pstrData, u16ReceiveData, L9960_u8SPI_SEND_WRONG_CMD);
      }
      else
      {
         /* If the u16ReceiveData = 0, that means previous dummy cmd has not been understood           */
         /* This case has no impact (and arrive for the first frame after Power On reset), so it is    */
         /* not to treat as an error.                                                                  */

         /* We have to send the Dummy Frame / This is the answer of the previous dummy frame */
         L9960_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);
      }
   }
   else
   {
      /* This is the answer of the previous command */
      
      
      /**********************************************************************************************/
      /* Check errors                                                                               */
      /**********************************************************************************************/
      /* This section set the u8LocSpiResult                                                        */
      /*                                                                                            */
      /* u8LocSpiResult = L9960_u8SPI_OK :                                                          */
      /*    notification of upper layer with no error                                               */
      /*                                                                                            */
      /* u8LocSpiResult = L9960_u8SPI_FAILURE :                                                     */
      /*    notification of upper layer with an error                                               */
      /*                                                                                            */
      /* u8LocSpiResult = L9960_u8SPI_RESEND :                                                      */
      /*    no notification, we try to resend the SPI command                                       */
      /*                                                                                            */
      /* u8LocSpiResult = L9960_u8SPI_SEND_WRONG_CMD :                                              */
      /*    notification of upper layer with an error                                               */
      /*                                                                                            */
      /**********************************************************************************************/
      if (u16ReceiveData == 0)
      {
         /* The device return 0 in case of receiving an invalid command                                    */
         /* in this case, we know that the Chip doesn't execute anything. We can try to resend the command */
         if (pstrData->u8SpiTransmitErrorCounter != 0)
         {
            pstrData->u8SpiTransmitErrorCounter--;
            u8LocSpiResult = L9960_u8SPI_RESEND;
            L9960_vidSpiTransmit(pkstrConfig, pstrData, pstrData->u16SpiLastSentCommand);
         }
         else
         {
            u8LocSpiResult = L9960_u8SPI_FAILURE;
         }
      }
      else
      {
         if( (pstrData->u16SpiLastSentCommand & 0xF000u) != (u16ReceiveData & 0xF000u) )
         {
            /* The address field of the answer must be the same as the one of the request.                */
            /* Otherwise, that means that L9960 understood another request and done an unexpected command */
            /* which can result to a register corruption.                                                 */
            u8LocSpiResult = L9960_u8SPI_SEND_WRONG_CMD;
         }
         else
         {
            /* No error: nothing to do except to notify upper layer */
         }
      }
      /**********************************************************************************************/
      /* End of Check erros                                                                         */
      /**********************************************************************************************/

      /* No notification if we try to re send the SPI command                                       */
      /* We send the received data (12 Low significant bits) to upper layer                         */
      if (u8LocSpiResult != L9960_u8SPI_RESEND)
      {
         L9960_vidSpiM_ManagerTxConf(pkstrConfig, pstrData, u16ReceiveData, u8LocSpiResult);
      }
   }

}

/**********************************************************************************************************************/
/* !FuncName    : L9960_SpiConstructWordToSend                                                                        */
/* !Description : It generates the 16 bits to send by SPI, from the register default value, the data                  */
/*                and add the parity bit.                                                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
uint16 L9960_SpiConstructWordToSend(uint16 u16SpiDefaultValue, uint16 u16SpiMask, uint16 u16SpiData)
{
   uint16_least u16LocData;
   uint16       u16LocSpiInstruction;
   
   /* &0xFFFE to clear the parity bit */
   u16LocSpiInstruction = ( (u16SpiDefaultValue & (u16SpiMask ^ 0xFFFFu))| (uint16)(u16SpiData & u16SpiMask)) & 0xFFFEu;

   /* Parity Computation */
   u16LocData = u16LocSpiInstruction;

   u16LocData ^= (u16LocData >> 1);
   u16LocData ^= (u16LocData >> 2);
   u16LocData ^= (u16LocData >> 4);
   u16LocData ^= (u16LocData >> 8);
   /* If bit0 of u16LocData is equal to 1, then u16LocSpiInstruction has an odd number of bit equal to 1 */
   
   /* Add parity bit */
   if ( (u16LocData & 0x01u) == FALSE)
   {
      /* even parity, so add 1 at parity bit to have an odd parity */
      u16LocSpiInstruction = u16LocSpiInstruction | 0x01u;
   }

   return(u16LocSpiInstruction);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiResetErrorCounter                                                                       */
/* !Description : Set the transmission error counter to its default value.                                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiResetErrorCounter(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   pstrData->u8SpiTransmitErrorCounter = L9960_u8SPI_NB_SENT_MAX;
}


#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

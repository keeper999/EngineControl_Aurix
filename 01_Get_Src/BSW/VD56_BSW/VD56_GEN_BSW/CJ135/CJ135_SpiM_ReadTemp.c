/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_SpiM_ReadTemp                                                                             */
/* !Description     : handle the SPi protocol                                                                         */
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
 * %PID: P2017_BSW:0A188666.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Spi.h"
#include "CJ135.h"
#include "CJ135_Private.h"
#include "CJ135_Spi.h"
#include "CJ135_SpiM.h"
#include "CJ135_Types.h"
#include "SchM_CJ135.h"


#define CJ135_START_SEC_CODE
#include "CJ135_MemMap.h"


/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* SpiM SEQUENCE : Read the temperature from CJ135 RAM (only in WARMUP mode)                                          */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_ReadTempStart                                                                         */
/* !Description : This function starts the reading of the temperature from CJ135 RAM                                  */
/*                It launches a SPI communcation, and the sequence continues on SPI Interrupt                         */
/*                in the CJ135_vidSpiM_ReadTempTxConf function.                                                       */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_ReadTempStart(const CJ135_tstrConfig *pkstrConfig,
                                CJ135_strData          *pstrData)
{
   /* Next state */
   pstrData->udtSpiM_StateMachine.ReadTemp = CJ135_SPIM_SEQ_READ_TEMP_RAM_URIE;

   /* Send the first one */
   CJ135_vidSpiSendCmdReadRamWUUrie(pkstrConfig, pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_ReadTempTxConf                                                                        */
/* !Description : Called on SPI interrupt. This function handle the state machine to read the temperature             */
/*                This sequence has been started by a call to CJ135_vidSpiM_ReadTempStart function.                   */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_ReadTempTxConf(const CJ135_tstrConfig *pkstrConfig,
                                 CJ135_strData          *pstrData,
                                 uint16                  u16ReceiveData,
                                 uint8                   u8SpiError)
{

   if(u8SpiError == CJ135_u8SPI_OK)
   {
      switch (pstrData->udtSpiM_StateMachine.ReadTemp)
      {

         case CJ135_SPIM_SEQ_READ_TEMP_RAM_URIE:
            /*first frame received is answer to dummy frame of previous sequence. It is not used*/
            CJ135_vidSpiSendCmdReadRamWUUn0(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadTemp = CJ135_SPIM_SEQ_READ_TEMP_RAM_UN0;
            break;

         case CJ135_SPIM_SEQ_READ_TEMP_RAM_UN0:
            pstrData->s16RamUrie = (sint16)(u16ReceiveData & CJ135_u16MASK_MEASURING_WORD);
            CJ135_vidSpiSendCmdReadRamWUUcal(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadTemp = CJ135_SPIM_SEQ_READ_TEMP_RAM_UCAL;
            break;

         case CJ135_SPIM_SEQ_READ_TEMP_RAM_UCAL:
            pstrData->s16RamUn0 = (sint16)(u16ReceiveData & CJ135_u16MASK_MEASURING_WORD);
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadTemp = CJ135_SPIM_SEQ_READ_TEMP_RAM_DUMMY;
            break;

         case CJ135_SPIM_SEQ_READ_TEMP_RAM_DUMMY:
            pstrData->s16RamUcal = (sint16)(u16ReceiveData & CJ135_u16MASK_MEASURING_WORD);
            /* Stop the present sequence, and launch the next one */
            CJ135_vidSpiM_EndOfSequence(pkstrConfig, pstrData);
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            CJ135_vidSpiM_EndOfSequence(pkstrConfig, pstrData);
            break;
      }
   }
   else
   {
      CJ135_vidSpiM_EndOfSequence(pkstrConfig, pstrData);
   }
}


#define CJ135_STOP_SEC_CODE
#include "CJ135_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_SpiM_ReadModes.c                                                                          */
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
 * %PID: P2017_BSW:0A192783.A-SRC;1 %
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
/* SpiM SEQUENCE : Read the modes (ACTUAL mode and the mode written in RAM)                                           */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_ReadModesStart                                                                        */
/* !Description : This function starts the reading of actual mode register                                            */
/*                It launches a SPI communcation, and the sequence continues on SPI Interrupt                         */
/*                in the CJ135_vidSpiM_ReadModesTxConf function.                                                      */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_ReadModesStart(const CJ135_tstrConfig *pkstrConfig,
                                CJ135_strData          *pstrData)
{
   /* Next state */
   pstrData->udtSpiM_StateMachine.ReadModes = CJ135_SPIM_SEQ_READ_MODES_ACTUAL_MODE;

   /* Send the first one */
   CJ135_vidSpiSendCmdReadActualMode(pkstrConfig, pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_ReadModesTxConf                                                                       */
/* !Description : Called on SPI interrupt. This function handle the state machine to read the actual mode register    */
/*                This sequence has been started by a call to CJ135_vidSpiM_ReadModesStart function.                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_ReadModesTxConf(const CJ135_tstrConfig *pkstrConfig,
                                 CJ135_strData          *pstrData,
                                 uint16                  u16ReceiveData,
                                 uint8                   u8SpiError)
{

   if(u8SpiError == CJ135_u8SPI_OK)
   {
      switch (pstrData->udtSpiM_StateMachine.ReadModes)
      {
         case CJ135_SPIM_SEQ_READ_MODES_ACTUAL_MODE:
            /*first frame received is answer to dummy frame of previous sequence. It is not used*/
            CJ135_vidSpiSendCmdReadRamMode(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadModes = CJ135_SPIM_SEQ_READ_MODES_RAM_MODE;
            break;

         case CJ135_SPIM_SEQ_READ_MODES_RAM_MODE:
            pstrData->u16SpiMChipRegActualMode = u16ReceiveData;
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadModes = CJ135_SPIM_SEQ_READ_MODES_RAM_MODE_DUMMY;
            break;

         case CJ135_SPIM_SEQ_READ_MODES_RAM_MODE_DUMMY:
            pstrData->u16RamDataMode = u16ReceiveData;
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

/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_SpiM_ReadRichnessTemp                                                                     */
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
 * %PID: P2017_BSW:0A188670.A-SRC;2 %
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
/* SpiM SEQUENCE : Read the richness and temperature from CJ135 RAM                                                   */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_ReadRichnessTempStart                                                                 */
/* !Description : This function starts the reading of the richness and temperature from CJ135 RAM                     */
/*                It launches a SPI communcation, and the sequence continues on SPI Interrupt                         */
/*                in the CJ135_vidSpiM_ReadRichnessTempTxConf function.                                               */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_ReadRichnessTempStart(const CJ135_tstrConfig *pkstrConfig,
                                CJ135_strData          *pstrData)
{
   /* Next state */
   pstrData->udtSpiM_StateMachine.ReadRichTemp = CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP1;

   /* Send the first one */
   CJ135_vidSpiSendCmdReadRamN3Ip1(pkstrConfig, pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_ReadRichnessTempTxConf                                                                */
/* !Description : Called on SPI interrupt. This function handle the state machine to read the mode register           */
/*                This sequence has been started by a call to CJ135_vidSpiM_ReadRichnessTempStart function.           */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_ReadRichnessTempTxConf(const CJ135_tstrConfig *pkstrConfig,
                                 CJ135_strData          *pstrData,
                                 uint16                  u16ReceiveData,
                                 uint8                   u8SpiError)
{

   if(u8SpiError == CJ135_u8SPI_OK)
   {
      switch (pstrData->udtSpiM_StateMachine.ReadRichTemp)
      {

         case CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP1:
            /*first frame received is answer to dummy frame of previous sequence. It is not used*/
            CJ135_vidSpiSendCmdReadRamN3Urie(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadRichTemp = CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_URIE;
            break;

         case CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_URIE:
            pstrData->s16RamIP1 = (sint16)(u16ReceiveData & CJ135_u16MASK_IP_WORD);
            CJ135_vidSpiSendCmdReadRamN3Ip2(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadRichTemp = CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP2;
            break;

         case CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP2:
            pstrData->s16RamUrie = (sint16)(u16ReceiveData & CJ135_u16MASK_MEASURING_WORD);
            CJ135_vidSpiSendCmdReadRamN3Ug0(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadRichTemp = CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_UGO;
            break;

         case CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_UGO:
            pstrData->s16RamIP2 = (sint16)(u16ReceiveData & CJ135_u16MASK_IP_WORD);
            CJ135_vidSpiSendCmdReadRamN3Un0(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadRichTemp = CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_UN0;
            break;

         case CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_UN0:
            pstrData->s16RamUg0 = (sint16)(u16ReceiveData & CJ135_u16MASK_MEASURING_WORD);
            CJ135_vidSpiSendCmdReadRamN3Ip3(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadRichTemp = CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP3;
            break;

         case CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP3:
            pstrData->s16RamUn0 = (sint16)(u16ReceiveData & CJ135_u16MASK_MEASURING_WORD);
            CJ135_vidSpiSendCmdReadRamN3Ip4(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadRichTemp = CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP4;
            break;

         case CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP4:
            pstrData->s16RamIP3 = (sint16)(u16ReceiveData & CJ135_u16MASK_IP_WORD);
            CJ135_vidSpiSendCmdReadRamN3Ucal(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadRichTemp = CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_UCAL;
            break;

         case CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_UCAL:
            pstrData->s16RamIP4 = (sint16)(u16ReceiveData & CJ135_u16MASK_IP_WORD);
            CJ135_vidSpiSendCmdReadRamN3Ip5(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadRichTemp = CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP5;
            break;

         case CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP5:
            pstrData->s16RamUcal = (sint16)(u16ReceiveData & CJ135_u16MASK_MEASURING_WORD);
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadRichTemp = CJ135_SPIM_SEQ_READ_RICH_TEMP_DUMMY;
            break;

         case CJ135_SPIM_SEQ_READ_RICH_TEMP_DUMMY:
            pstrData->s16RamIP5 = (sint16)(u16ReceiveData & CJ135_u16MASK_IP_WORD);
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

/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_SpiM_ReadConf.c                                                                           */
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
 * %PID: P2017_BSW:0A188672.A-SRC;1 %
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
/* SpiM SEQUENCE : Read the all the CJ135 configuration registers                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_ReadConfRegisterStart                                                                 */
/* !Description : This function starts the reading of all the CJ135 configuration registers                           */
/*                It launches a SPI communcation, and the sequence continues on SPI Interrupt                         */
/*                in the CJ135_vidSpiM_ReadConfRegisterTxConf function.                                               */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_ReadConfRegisterStart(const CJ135_tstrConfig *pkstrConfig,
                                CJ135_strData          *pstrData)
{
   /* Next state */
   pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_CONFIGDSP;

   /* Send the first one */
   CJ135_vidSpiSendCmdReadConfigDSP(pkstrConfig, pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_ReadConfRegisterTxConf                                                                */
/* !Description : Called on SPI interrupt. This function handle the state machine to read the configuration registers */
/*                This sequence has been started by a call to CJ135_vidSpiM_ReadConfRegisterStart function.           */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_ReadConfRegisterTxConf(const CJ135_tstrConfig *pkstrConfig,
                                 CJ135_strData          *pstrData,
                                 uint16                  u16ReceiveData,
                                 uint8                   u8SpiError)
{

   if(u8SpiError == CJ135_u8SPI_OK)
   {
      switch (pstrData->udtSpiM_StateMachine.ReadConfReg)
      {

         case CJ135_SPIM_SEQ_READ_CONF_REG_CONFIGDSP:
            /*first frame received is answer to dummy frame of previous sequence. It is not used*/
            CJ135_vidSpiSendCmdReadIpoff(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_IPOFF;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_IPOFF:
            pstrData->u16SpiMChipRegConfigDsp = u16ReceiveData;
            CJ135_vidSpiSendCmdReadMode(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_MODE;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_MODE:
            pstrData->u16SpiMChipRegIpOff = u16ReceiveData;
            CJ135_vidSpiSendCmdReadRefpat(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_REFPAT;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_REFPAT:
            pstrData->u16SpiMChipRegMode = u16ReceiveData;
            CJ135_vidSpiSendCmdReadSteerpat(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_STEERPAT;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_STEERPAT:
            pstrData->u16SpiMChipRegRefpat = u16ReceiveData;
            CJ135_vidSpiSendCmdReadTrim(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_TRIM;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_TRIM:
            pstrData->u16SpiMChipRegSteerpat = u16ReceiveData;
            CJ135_vidSpiSendCmdReadUnset(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_UNSET;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_UNSET:
            pstrData->u16SpiMChipRegTrim = u16ReceiveData;
            CJ135_vidSpiSendCmdReadUego0(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_UEGO0;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_UEGO0:
            pstrData->u16SpiMChipRegUnset = u16ReceiveData;
            CJ135_vidSpiSendCmdReadUego1(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_UEGO1;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_UEGO1:
            pstrData->u16SpiMChipRegUego0 = u16ReceiveData;
            CJ135_vidSpiSendCmdReadUego2(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_UEGO2;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_UEGO2:
            pstrData->u16SpiMChipRegUego1 = u16ReceiveData;
            CJ135_vidSpiSendCmdReadUego3(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_UEGO3;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_UEGO3:
            pstrData->u16SpiMChipRegUego2 = u16ReceiveData;
            CJ135_vidSpiSendCmdReadUego4(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_UEGO4;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_UEGO4:
            pstrData->u16SpiMChipRegUego3 = u16ReceiveData;
            CJ135_vidSpiSendCmdReadUego5(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_UEGO5;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_UEGO5:
            pstrData->u16SpiMChipRegUego4 = u16ReceiveData;
            CJ135_vidSpiSendCmdReadUp0lean(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_UP0LEAN;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_UP0LEAN:
            pstrData->u16SpiMChipRegUego5 = u16ReceiveData;
            CJ135_vidSpiSendCmdReadUp0rich(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_UP0RICH;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_UP0RICH:
            pstrData->u16SpiMChipRegUp0lean = u16ReceiveData;
            CJ135_vidSpiSendCmdReadFree(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_FREE;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_FREE:
            pstrData->u16SpiMChipRegUp0rich = u16ReceiveData;
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadConfReg = CJ135_SPIM_SEQ_READ_CONF_REG_DUMMY;
            break;

         case CJ135_SPIM_SEQ_READ_CONF_REG_DUMMY:
            pstrData->u16SpiMChipRegFree = u16ReceiveData;
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

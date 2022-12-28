/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_SpiM_RegCheck.c                                                                           */
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
 * %PID: LIBEMB:A6021.A-SRC;1 %
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


#define L9960_START_SEC_CODE
#include "L9960_MemMap.h"


/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* SpiM SEQUENCE : Check configuration of L9960 Registers                                                             */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_RegCheckStart                                                                         */
/* !Description : This function starts the Check of all L9960 registers                                               */
/*                It launches a SPI communcation, and the sequence continues on SPI Interrupt                         */
/*                in the L9960_vidSpiM_RegCheckTxConf function.                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_RegCheckStart(const L9960_tstrConfig *pkstrConfig,
                                 L9960_strData          *pstrData)
{
   /* Reset the check status */
   pstrData->enuSpiMRegisterRead = L9960_REGISTER_READ_RUNNING;

   /* Send the first one */
   L9960_vidSpiSendCmdConfigReq1(pkstrConfig, pstrData);

   /* Next state */
   pstrData->udtSpiM_StateMachine.CheckAllReg = L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_1;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_RegCheckTxConf                                                                        */
/* !Description : Called on SPI interrupt. This function handle the state machine to Initialize all L9960 registers   */
/*                This sequence has been started by a call to L9960_vidSpiM_RegInitStart function.                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_RegCheckTxConf(const L9960_tstrConfig *pkstrConfig,
                                  L9960_strData          *pstrData,
                                  uint16                  u16ReceiveData,
                                  uint8                   u8SpiError)
{
   if(u8SpiError == L9960_u8SPI_OK)
   {
      u16ReceiveData = u16ReceiveData & 0x0FFFu; /* remove the address field */
      switch (pstrData->udtSpiM_StateMachine.CheckAllReg)
      {
         case L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_1:
            /* Store the result */
            pstrData->u16SpiMChipRegConfig1 = u16ReceiveData;

            /* Send the requestfor the Config 2 */
            L9960_vidSpiSendCmdConfigReq2(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.CheckAllReg = L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_2;
            break;
            
         case L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_2:
            /* Store the result */
            pstrData->u16SpiMChipRegConfig2 = u16ReceiveData;

            /* Send the requestfor the Config 3 */
            L9960_vidSpiSendCmdConfigReq3(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.CheckAllReg = L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_3;
            break;
            
         case L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_3:
            /* Store the result */
            pstrData->u16SpiMChipRegConfig3 = u16ReceiveData;

            /* Send the request for the Config 5 */
            L9960_vidSpiSendCmdConfigReq5(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.CheckAllReg = L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_5;
            break;
            
         case L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_5:
            /* Store the result */
            L9960_vidSpiM_UpdateRegConfig5(pkstrConfig, pstrData, u16ReceiveData);

            pstrData->enuSpiMRegisterRead = L9960_REGISTER_READ_DONE;

            /* End of sequence */
            L9960_vidSpiM_EndOfSequence(pkstrConfig, pstrData);
            break;
   
         default:
            pstrData->enuSpiMRegisterRead = L9960_REGISTER_READ_FAIL;
            SWFAIL_vidSoftwareErrorHook();
            L9960_vidSpiM_EndOfSequence(pkstrConfig, pstrData);
            break;
      }
   }
   else
   {
      /* TODO: which action to do ??? */
      /* TODO: replace L9960_REGISTER_READ_DONE by L9960_REGISTER_READ_FAIL in next line of code */
      /*       it is to be able to start some test even if L9960 is not connected on the ECU */
      pstrData->enuSpiMRegisterRead = L9960_REGISTER_READ_FAIL;
      L9960_vidSpiM_EndOfSequence(pkstrConfig, pstrData);
   }
}


#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

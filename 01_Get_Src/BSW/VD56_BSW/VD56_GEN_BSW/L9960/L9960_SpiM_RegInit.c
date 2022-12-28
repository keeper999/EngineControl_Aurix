/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_SpiM_RegInit.c                                                                            */
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
 * %PID: LIBEMB:A6012.A-SRC;1 %
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
/* SpiM SEQUENCE : Initialize all L9960 Registers                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_RegInitStart                                                                          */
/* !Description : This function starts the Initialization of all L9960 registers                                      */
/*                It launches a SPI communcation, and the sequence continues on SPI Interrupt                         */
/*                in the L9960_vidSpiM_RegInitTxConf function.                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_RegInitStart(const L9960_tstrConfig *pkstrConfig,
                                L9960_strData          *pstrData)
{
   /* Reset the status */
   pstrData->enuSpiMRegisterInitialized = L9960_REGISTER_INIT_RUNNING;

   /* Send the first one */
   L9960_vidSpiSendCmdRestartTrigger(pkstrConfig, pstrData, L9960_u16SPI_POR_VALUE_RESTART_TRIGGER);

   /* Next state */
   pstrData->udtSpiM_StateMachine.InitAllReg = L9960_SPIM_SEQ_INIT_ALL_REG_RESTART_TRIGGER;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_RegInitTxConf                                                                         */
/* !Description : Called on SPI interrupt. This function handle the state machine to Initialize all L9960 registers   */
/*                This sequence has been started by a call to L9960_vidSpiM_RegInitStart function.                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_RegInitTxConf(const L9960_tstrConfig *pkstrConfig,
                                 L9960_strData          *pstrData,
                                 uint16                  u16ReceiveData,
                                 uint8                   u8SpiError)
{
   COMPILER_UNUSED_PARAMETER(u16ReceiveData);

   if(u8SpiError == L9960_u8SPI_OK)
   {
      switch (pstrData->udtSpiM_StateMachine.InitAllReg)
      {
         case L9960_SPIM_SEQ_INIT_ALL_REG_RESTART_TRIGGER:
            L9960_vidSpiSendCmdConfig1(pkstrConfig, pstrData, pstrData->u16SpiMChipRegConfiguration1);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitAllReg = L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_1;
            break;
   
         case L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_1:
            L9960_vidSpiSendCmdConfig2(pkstrConfig, pstrData, pstrData->u16SpiMChipRegConfiguration2);

            /* Next state */
            pstrData->udtSpiM_StateMachine.InitAllReg = L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_2;
            break;
   
         case L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_2:
            L9960_vidSpiSendCmdConfig3(pkstrConfig, pstrData, pstrData->u16SpiMChipRegConfiguration3);

            /* Next state */
            pstrData->udtSpiM_StateMachine.InitAllReg = L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_3;
   
            /* TODO: implement read back after all write */
            break;
   
         case L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_3:
            L9960_vidSpiSendCmdConfig4(pkstrConfig, pstrData, pstrData->u16SpiMChipRegConfiguration4);

            /* Next state */
            pstrData->udtSpiM_StateMachine.InitAllReg = L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_4;
            break;
   
         case L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_4:
            pstrData->enuSpiMRegisterInitialized = L9960_REGISTER_INIT_DONE;
            /* End of sequence */
            L9960_vidSpiM_EndOfSequence(pkstrConfig, pstrData);

            break;
   
         default:
            pstrData->enuSpiMRegisterInitialized = L9960_REGISTER_INIT_FAIL;
            SWFAIL_vidSoftwareErrorHook();
            L9960_vidSpiM_EndOfSequence(pkstrConfig, pstrData);
            break;
   
      }
   }
   else
   {
      pstrData->enuSpiMRegisterInitialized = L9960_REGISTER_INIT_FAIL;
      L9960_vidSpiM_EndOfSequence(pkstrConfig, pstrData);
   }
}


#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

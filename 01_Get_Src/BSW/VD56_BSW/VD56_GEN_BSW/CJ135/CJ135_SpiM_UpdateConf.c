/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_SpiM_UpdateConf.c                                                                         */
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
 * %PID: P2017_BSW:0A188669.A-SRC;2 %
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
/* SpiM SEQUENCE : Update the CJ135 configuration registers in case of reference or pumping current change            */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_UpdateConfRegisterStart                                                               */
/* !Description : This function starts the update CJ135 registers                                                     */
/*                It launches a SPI communcation, and the sequence continues on SPI Interrupt                         */
/*                in the CJ135_vidSpiM_UpdateConfRegisterTxConf function.                                             */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_UpdateConfRegisterStart(const CJ135_tstrConfig *pkstrConfig,
                                CJ135_strData          *pstrData)
{
   /* Next state */
   pstrData->udtSpiM_StateMachine.UpdateConfReg = CJ135_SPIM_SEQ_UPDATE_CONF_REG_REFPAT_HB;

   /* Send the first one */
   CJ135_vidSpiSendCmdWRRefpat_HB(pkstrConfig, pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_UpdateConfRegisterTxConf                                                              */
/* !Description : Called on SPI interrupt. This function handle the state machine to Update CJ135 registers           */
/*                This sequence has been started by a call to CJ135_vidSpiM_UpdateConfRegisterStart function.         */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_UpdateConfRegisterTxConf(const CJ135_tstrConfig *pkstrConfig,
                                 CJ135_strData          *pstrData,
                                 uint16                  u16ReceiveData,
                                 uint8                   u8SpiError)
{
   COMPILER_UNUSED_PARAMETER(u16ReceiveData);

   if(u8SpiError == CJ135_u8SPI_OK)
   {
      switch (pstrData->udtSpiM_StateMachine.UpdateConfReg)
      {

         case CJ135_SPIM_SEQ_UPDATE_CONF_REG_REFPAT_HB:
            CJ135_vidSpiSendCmdWRRefpat_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.UpdateConfReg = CJ135_SPIM_SEQ_UPDATE_CONF_REG_REFPAT_LB;
            break;

         case CJ135_SPIM_SEQ_UPDATE_CONF_REG_REFPAT_LB:
            CJ135_vidSpiSendCmdWRRefpat_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.UpdateConfReg = CJ135_SPIM_SEQ_UPDATE_CONF_REG_REFPAT_ADDR;
            break;

         case CJ135_SPIM_SEQ_UPDATE_CONF_REG_REFPAT_ADDR:
            CJ135_vidSpiSendCmdWRTrim_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.UpdateConfReg = CJ135_SPIM_SEQ_UPDATE_CONF_REG_TRIM_HB;
            break;

         case CJ135_SPIM_SEQ_UPDATE_CONF_REG_TRIM_HB:
            CJ135_vidSpiSendCmdWRTrim_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.UpdateConfReg = CJ135_SPIM_SEQ_UPDATE_CONF_REG_TRIM_LB;
            break;

         case CJ135_SPIM_SEQ_UPDATE_CONF_REG_TRIM_LB:
            CJ135_vidSpiSendCmdWRTrim_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.UpdateConfReg = CJ135_SPIM_SEQ_UPDATE_CONF_REG_TRIM_ADDR;
            break;

         case CJ135_SPIM_SEQ_UPDATE_CONF_REG_TRIM_ADDR:
            CJ135_vidSpiSendCmdWRConfigDSP_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.UpdateConfReg = CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_HB;
            break;

         case CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_HB:
            CJ135_vidSpiSendCmdWRConfigDSP_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.UpdateConfReg = CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_LB;
            break;

         case CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_LB:
            CJ135_vidSpiSendCmdWRConfigDSP_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.UpdateConfReg = CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_ADDR;
            break;

         case CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.UpdateConfReg = CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_DUMMY;
            break;

         case CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_DUMMY:
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

/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_SpiM_InitConf.c                                                                           */
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
 * %PID: P2017_BSW:0A188676.A-SRC;1 %
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
/* SpiM SEQUENCE : Initialize all the CJ135 configuration registers                                                   */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_InitConfRegisterStart                                                                 */
/* !Description : This function starts the Initialization of all CJ135 registers                                      */
/*                It launches a SPI communcation, and the sequence continues on SPI Interrupt                         */
/*                in the CJ135_vidSpiM_InitConfRegisterTxConf function.                                               */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_InitConfRegisterStart(const CJ135_tstrConfig *pkstrConfig,
                                CJ135_strData          *pstrData)
{
   /* Next state */
   pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_HB;

   /* Send the first one */
   CJ135_vidSpiSendCmdWRIpoff_HB(pkstrConfig, pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_InitConfRegisterTxConf                                                                */
/* !Description : Called on SPI interrupt. This function handle the state machine to Initialize all CJ135 registers   */
/*                This sequence has been started by a call to CJ135_vidSpiM_InitConfRegisterStart function.           */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_InitConfRegisterTxConf(const CJ135_tstrConfig *pkstrConfig,
                                 CJ135_strData          *pstrData,
                                 uint16                  u16ReceiveData,
                                 uint8                   u8SpiError)
{
   COMPILER_UNUSED_PARAMETER(u16ReceiveData);

   if(u8SpiError == CJ135_u8SPI_OK)
   {
      switch (pstrData->udtSpiM_StateMachine.InitConfReg)
      {

         case CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_HB:
            CJ135_vidSpiSendCmdWRIpoff_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_LB:
            CJ135_vidSpiSendCmdWRIpoff_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_DUMMY:
            CJ135_vidSpiSendCmdWRRefpat_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_HB:
            CJ135_vidSpiSendCmdWRRefpat_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_LB:
            CJ135_vidSpiSendCmdWRRefpat_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_DUMMY:
            CJ135_vidSpiSendCmdWRSteerpat_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_HB:
            CJ135_vidSpiSendCmdWRSteerpat_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_LB:
            CJ135_vidSpiSendCmdWRSteerpat_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_DUMMY:
            CJ135_vidSpiSendCmdWRTrim_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_HB:
            CJ135_vidSpiSendCmdWRTrim_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_LB:
            CJ135_vidSpiSendCmdWRTrim_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_DUMMY:
            CJ135_vidSpiSendCmdWRUnset_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_HB:
            CJ135_vidSpiSendCmdWRUnset_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_LB:
            CJ135_vidSpiSendCmdWRUnset_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_DUMMY:
            CJ135_vidSpiSendCmdWRUego0_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_HB:
            CJ135_vidSpiSendCmdWRUego0_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_LB:
            CJ135_vidSpiSendCmdWRUego0_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_DUMMY:
            CJ135_vidSpiSendCmdWRUego1_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_HB:
            CJ135_vidSpiSendCmdWRUego1_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_LB:
            CJ135_vidSpiSendCmdWRUego1_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_DUMMY:
            CJ135_vidSpiSendCmdWRUego2_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_HB:
            CJ135_vidSpiSendCmdWRUego2_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_LB:
            CJ135_vidSpiSendCmdWRUego2_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_DUMMY:
            CJ135_vidSpiSendCmdWRUego3_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_HB:
            CJ135_vidSpiSendCmdWRUego3_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_LB:
            CJ135_vidSpiSendCmdWRUego3_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_DUMMY:
            CJ135_vidSpiSendCmdWRUego4_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_HB:
            CJ135_vidSpiSendCmdWRUego4_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_LB:
            CJ135_vidSpiSendCmdWRUego4_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_DUMMY:
            CJ135_vidSpiSendCmdWRUego5_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_HB:
            CJ135_vidSpiSendCmdWRUego5_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_LB:
            CJ135_vidSpiSendCmdWRUego5_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_DUMMY:
            CJ135_vidSpiSendCmdWRUp0lean_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_HB:
            CJ135_vidSpiSendCmdWRUp0lean_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_LB:
            CJ135_vidSpiSendCmdWRUp0lean_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_DUMMY:
            CJ135_vidSpiSendCmdWRUp0rich_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_HB:
            CJ135_vidSpiSendCmdWRUp0rich_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_LB:
            CJ135_vidSpiSendCmdWRUp0rich_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_DUMMY:
            CJ135_vidSpiSendCmdWRFree_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_HB:
            CJ135_vidSpiSendCmdWRFree_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_LB:
            CJ135_vidSpiSendCmdWRFree_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_DUMMY:
            CJ135_vidSpiSendCmdWRConfigDSP_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_HB:
            CJ135_vidSpiSendCmdWRConfigDSP_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_LB:
            CJ135_vidSpiSendCmdWRConfigDSP_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_DUMMY:
            CJ135_vidSpiSendCmdWRMode_HB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_HB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_HB:
            CJ135_vidSpiSendCmdWRMode_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_LB;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_LB:
            CJ135_vidSpiSendCmdWRMode_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_ADDR;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.InitConfReg = CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_DUMMY;
            break;

         case CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_DUMMY:
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

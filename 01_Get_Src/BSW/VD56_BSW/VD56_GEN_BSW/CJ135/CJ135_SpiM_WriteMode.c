/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_SpiM_WriteMode.c                                                                          */
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
 * %PID: P2017_BSW:0A188664.A-SRC;1 %
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
/* SpiM SEQUENCE : write the mode register                                                                            */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_WriteModeStart                                                                        */
/* !Description : This function starts the writing of mode register                                                   */
/*                It launches a SPI communcation, and the sequence continues on SPI Interrupt                         */
/*                in the CJ135_vidSpiM_WriteModeTxConf function.                                                      */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_WriteModeStart(const CJ135_tstrConfig *pkstrConfig,
                                CJ135_strData          *pstrData)
{
   /* Next state */
   pstrData->udtSpiM_StateMachine.WriteMode = CJ135_SPIM_SEQ_WRITE_MODE_MODE_HB;

   /* Send the first one */
   CJ135_vidSpiSendCmdWRMode_HB(pkstrConfig, pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_WriteModeTxConf                                                                       */
/* !Description : Called on SPI interrupt. This function handle the state machine to write the mode register          */
/*                This sequence has been started by a call to CJ135_vidSpiM_WriteModeStart function.                  */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_WriteModeTxConf(const CJ135_tstrConfig *pkstrConfig,
                                 CJ135_strData          *pstrData,
                                 uint16                  u16ReceiveData,
                                 uint8                   u8SpiError)
{
   COMPILER_UNUSED_PARAMETER(u16ReceiveData);

   if(u8SpiError == CJ135_u8SPI_OK)
   {
      switch (pstrData->udtSpiM_StateMachine.WriteMode)
      {
         case CJ135_SPIM_SEQ_WRITE_MODE_MODE_HB:
            CJ135_vidSpiSendCmdWRMode_LB(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.WriteMode = CJ135_SPIM_SEQ_WRITE_MODE_MODE_LB;
            break;

         case CJ135_SPIM_SEQ_WRITE_MODE_MODE_LB:
            CJ135_vidSpiSendCmdWRMode_Addr(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.WriteMode = CJ135_SPIM_SEQ_WRITE_MODE_MODE_ADDR;
            break;

         case CJ135_SPIM_SEQ_WRITE_MODE_MODE_ADDR:
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.WriteMode = CJ135_SPIM_SEQ_WRITE_MODE_MODE_DUMMY;
            break;

         case CJ135_SPIM_SEQ_WRITE_MODE_MODE_DUMMY:
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

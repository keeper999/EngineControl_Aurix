/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_SpiM_ReadDiag.c                                                                           */
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
 * %PID: P2017_BSW:0A188665.A-SRC;1 %
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
/* SpiM SEQUENCE : Read the diagnoses registers                                                                       */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_ReadDiagnosticStart                                                                   */
/* !Description : This function starts the reading of diagnoses registers                                             */
/*                It launches a SPI communcation, and the sequence continues on SPI Interrupt                         */
/*                in the CJ135_vidSpiM_ReadDiagnosticTxConf function.                                                 */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_ReadDiagnosticStart(const CJ135_tstrConfig *pkstrConfig,
                                CJ135_strData          *pstrData)
{
   /* Next state */
   pstrData->udtSpiM_StateMachine.ReadDiagnostic = CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DIAG0;

   /* Send the first one */
   CJ135_vidSpiSendCmdReadDiag0(pkstrConfig, pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiM_ReadDiagnosticTxConf                                                                  */
/* !Description : Called on SPI interrupt. This function handle the state machine to read the diagnoses registers     */
/*                This sequence has been started by a call to CJ135_vidSpiM_ReadDiagnosticStart function.             */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiM_ReadDiagnosticTxConf(const CJ135_tstrConfig *pkstrConfig,
                                 CJ135_strData          *pstrData,
                                 uint16                  u16ReceiveData,
                                 uint8                   u8SpiError)
{


   if(u8SpiError == CJ135_u8SPI_OK)
   {
      switch (pstrData->udtSpiM_StateMachine.ReadDiagnostic)
      {
         case CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DIAG0:
            /*first frame received is answer to dummy frame of previous sequence. It is not used*/
            CJ135_vidSpiSendCmdReadDiag1(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadDiagnostic = CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DIAG1;
            break;

         case CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DIAG1:
            pstrData->u16SpiMChipRegDiag0 = u16ReceiveData;
            CJ135_vidSpiSendCmdReadDSPStat(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadDiagnostic = CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DSPSTAT;
            break;

         case CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DSPSTAT:
            pstrData->u16SpiMChipRegDiag1 = u16ReceiveData;
            CJ135_vidSpiSendCmdReadChipstat(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadDiagnostic = CJ135_SPIM_SEQ_READ_DIAGNOSTIC_CHIPSTAT;
            break;

         case CJ135_SPIM_SEQ_READ_DIAGNOSTIC_CHIPSTAT:
            pstrData->u16SpiMChipRegDspStat = u16ReceiveData;
            CJ135_vidSpiTransmitDummyFrame(pkstrConfig, pstrData);

            /* Update current state */
            pstrData->udtSpiM_StateMachine.ReadDiagnostic = CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DUMMY;
            break;

         case CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DUMMY:
            pstrData->u16SpiMChipRegChipStat = u16ReceiveData;
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

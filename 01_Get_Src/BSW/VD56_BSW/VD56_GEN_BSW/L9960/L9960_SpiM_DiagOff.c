/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_SpiM_DiagOff.c                                                                            */
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
 * %PID: LIBEMB:A6009.A-SRC;1 %
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
/* SpiM SEQUENCE : Read Diagnostics When Bridge is ON                                                                 */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_DiagOffSeqStart                                                                       */
/* !Description : This function start the diagnostic sequence when L9960 is not in tristate                           */
/*                It launch a SPI communcation, and the sequence continue on SPI Interrupt                            */
/*                in the L9960_vidSpiM_DiagTxConf function.                                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_DiagOffSeqStart(const L9960_tstrConfig *pkstrConfig,
                                   L9960_strData          *pstrData)
{
   /* Read State Register 1 (contain NGFAIL) */
   L9960_vidSpiSendCmdStateReq1(pkstrConfig, pstrData);

   /* Present state */
   pstrData->udtSpiM_StateMachine.OffDiagnostic = L9960_SPIM_SEQ_DIAG_OFF_READ_STATE_1;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_DiagOffSeqTxConf                                                                      */
/* !Description : Called on SPI interrupt. This function handle the state machine to read L9960 diagnostics           */
/*                This sequence has been started by a call to L9960_vidSpiM_DiagStart function.                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_DiagOffSeqTxConf(const L9960_tstrConfig *pkstrConfig,
                                          L9960_strData    *pstrData,
                                          uint16            u16ReceiveData,
                                          uint8             u8SpiError)
{

   if(u8SpiError == L9960_u8SPI_OK)
   {
      u16ReceiveData = u16ReceiveData & 0x0FFFu; /* remove the address field */
      switch (pstrData->udtSpiM_StateMachine.OffDiagnostic)
      {
   
         case L9960_SPIM_SEQ_DIAG_OFF_READ_STATE_1:
            /* Store State1 register received values */
            pstrData->u16SpiMChipRegState1 = u16ReceiveData;
            
            L9960_vidSpiSendCmdStateReq2(pkstrConfig, pstrData);
            pstrData->udtSpiM_StateMachine.OffDiagnostic = L9960_SPIM_SEQ_DIAG_OFF_READ_STATE_2;
            break;
   
         case L9960_SPIM_SEQ_DIAG_OFF_READ_STATE_2:
            /* Store State2 register received values */
            L9960_vidSpiM_UpdateRegState2(pkstrConfig, pstrData, u16ReceiveData);
   
            /* Launch command request to start the Off State Diagnostic */
            /* In addition to this request, the answer contain the previous Off state diag result */
            L9960_vidSpi_StartOffStateDiag(pkstrConfig, pstrData);
   
            /* Update current state */
            pstrData->udtSpiM_StateMachine.OffDiagnostic = L9960_SPIM_SEQ_DIAG_OFF_READ_OFF_STATE;
            break;
   
         case L9960_SPIM_SEQ_DIAG_OFF_READ_OFF_STATE:
            /* Store Over Current received values */
            pstrData->u16SpiMChipRegOffDiag = u16ReceiveData;
   
            /* Sequence finished, treat results  */
            pstrData->bOffDiagnosticIsAvailable = TRUE;
   
            /* Stop the present sequence, and launch the next one */
            L9960_vidSpiM_EndOfSequence(pkstrConfig, pstrData);
            break;
   
         default:
            SWFAIL_vidSoftwareErrorHook();
            L9960_vidSpiM_EndOfSequence(pkstrConfig, pstrData);
            break;
      }
   }
   else
   {
      /* TODO: which action to do ??? */
      /* The L9960 is badly configured... but for testing, as we have no chip, spi is of ourse in error */
      /* so we do like initialization was done to be able to perform other test */ 
      L9960_vidSpiM_EndOfSequence(pkstrConfig, pstrData);
   }
}


#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_SpiM_DiagOn.c                                                                             */
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
 * %PID: LIBEMB:A6049.A-SRC;1 %
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
/* !FuncName    : L9960_vidSpiM_DiagOnSeq1Start                                                                       */
/* !Description : This function start the diagnostic sequence when L9960 is not in tristate                           */
/*                It launch a SPI communcation, and the sequence continue on SPI Interrupt                            */
/*                in the L9960_vidSpiM_DiagTxConf function.                                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_DiagOnSeq1Start(const L9960_tstrConfig *pkstrConfig,
                                          L9960_strData          *pstrData)
{
   /* Read State Register 1 (contain NGFAIL) */
   L9960_vidSpiSendCmdStateReq1(pkstrConfig, pstrData);

   /* Present state */
   pstrData->udtSpiM_StateMachine.OnDiagnostic = L9960_SPIM_SEQ_DIAG_ON_READ_STATE_1;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_DiagOnSeq1TxConf                                                                      */
/* !Description : Called on SPI interrupt. This function handle the state machine to read L9960 diagnostics           */
/*                This sequence has been started by a call to L9960_vidSpiM_DiagStart function.                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_DiagOnSeq1TxConf(const L9960_tstrConfig *pkstrConfig,
                                          L9960_strData    *pstrData,
                                          uint16            u16ReceiveData,
                                          uint8             u8SpiError)
{

   if(u8SpiError == L9960_u8SPI_OK)
   {
      u16ReceiveData = u16ReceiveData & 0x0FFFu; /* remove the address field */
      switch (pstrData->udtSpiM_StateMachine.OnDiagnostic)
      {
   
         case L9960_SPIM_SEQ_DIAG_ON_READ_STATE_1:
            /* Store State1 register received values */
            pstrData->u16SpiMChipRegState1 = u16ReceiveData;
            
            /* If NGFAIL = 0, then launch full sequence otherwise request open load diag only */
            if( (u16ReceiveData & L9960_bfSTATE_1_NGFAIL_BIT) != 0)
            {
               /* Case NGFAIL == 1 */
               /* Launch command request to start the Open Load Diagnostic when L9960 is not in tristate */
               L9960_vidSpi_StartOpenLoadOnDiag(pkstrConfig, pstrData);
   
               /* Update current state */
               pstrData->udtSpiM_StateMachine.OnDiagnostic = L9960_SPIM_SEQ_DIAG_ON_REQUEST_OPEN_LOAD;
            }
            else
            {
               /* Case NGFAIL == 0 */
               /* Launch read of State Register 2 */
               L9960_vidSpiSendCmdStateReq2(pkstrConfig, pstrData);
               /* Update current state */
               pstrData->udtSpiM_StateMachine.OnDiagnostic = L9960_SPIM_SEQ_DIAG_ON_READ_STATE_2;
            }
            break;
   
         case L9960_SPIM_SEQ_DIAG_ON_READ_STATE_2:
            /* Store State2 register received values */
            L9960_vidSpiM_UpdateRegState2(pkstrConfig, pstrData, u16ReceiveData);
   
            /* Launch read of Over Current Diagnostic */
            L9960_vidSpiSendCmdOvercurrent(pkstrConfig, pstrData);
   
            /* Update current state */
            pstrData->udtSpiM_StateMachine.OnDiagnostic = L9960_SPIM_SEQ_DIAG_ON_READ_OVER_CURRENT;
            break;
   
         case L9960_SPIM_SEQ_DIAG_ON_READ_OVER_CURRENT:
            /* Store Over Current received values */
            L9960_vidSpiM_UpdateOverCurrent(pkstrConfig, pstrData, u16ReceiveData);
   
            /* Launch command request to start the Open Load Diagnostic when L9960 is not in tristate */
            L9960_vidSpi_StartOpenLoadOnDiag(pkstrConfig, pstrData);
   
            /* Update current state */
            pstrData->udtSpiM_StateMachine.OnDiagnostic = L9960_SPIM_SEQ_DIAG_ON_REQUEST_OPEN_LOAD;
            break;
   
         case L9960_SPIM_SEQ_DIAG_ON_REQUEST_OPEN_LOAD:
            /* No data read on this last request */
            
            /* Sequence finished, treat results  */
            pstrData->bOnDiagnosticIsAvailable = TRUE;
   
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

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_DiagOnSeq1Start                                                                       */
/* !Description : This function start the diagnostic sequence when L9960 is not in tristate                           */
/*                It launch a SPI communcation, and the sequence continue on SPI Interrupt                            */
/*                in the L9960_vidSpiM_DiagTxConf function.                                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_DiagOnSeq2Start(const L9960_tstrConfig *pkstrConfig,
                                          L9960_strData          *pstrData)
{
   /* Read State Register 1 (contain NGFAIL) */
   L9960_vidSpiSendCmdStateReq1(pkstrConfig, pstrData);

   /* Present state */
   pstrData->udtSpiM_StateMachine.OnDiagnostic = L9960_SPIM_SEQ_DIAG_ON_READ_STATE_1;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidSpiM_DiagOnSeq1TxConf                                                                      */
/* !Description : Called on SPI interrupt. This function handle the state machine to read L9960 diagnostics           */
/*                This sequence has been started by a call to L9960_vidSpiM_DiagStart function.                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidSpiM_DiagOnSeq2TxConf(const L9960_tstrConfig *pkstrConfig,
                                          L9960_strData    *pstrData,
                                          uint16            u16ReceiveData,
                                          uint8             u8SpiError)
{

   if(u8SpiError == L9960_u8SPI_OK)
   {
      u16ReceiveData = u16ReceiveData & 0x0FFFu; /* remove the address field */
      switch (pstrData->udtSpiM_StateMachine.OnDiagnostic)
      {
   
         case L9960_SPIM_SEQ_DIAG_ON_READ_STATE_1:
            /* Store State1 register received values */
            pstrData->u16SpiMChipRegState1 = u16ReceiveData;
            
            /* Launch read of State Register 2 */
            L9960_vidSpiSendCmdStateReq2(pkstrConfig, pstrData);
            /* Update current state */
            pstrData->udtSpiM_StateMachine.OnDiagnostic = L9960_SPIM_SEQ_DIAG_ON_READ_STATE_2;

            break;
   
         case L9960_SPIM_SEQ_DIAG_ON_READ_STATE_2:
            /* Store State2 register received values */
            L9960_vidSpiM_UpdateRegState2(pkstrConfig, pstrData, u16ReceiveData);

            /* Launch read of Over Current Diagnostic */
            L9960_vidSpiSendCmdOvercurrent(pkstrConfig, pstrData);
   
            /* Update current state */
            pstrData->udtSpiM_StateMachine.OnDiagnostic = L9960_SPIM_SEQ_DIAG_ON_READ_OVER_CURRENT;
            break;
   
         case L9960_SPIM_SEQ_DIAG_ON_READ_OVER_CURRENT:
            /* Store Over Current received values */
            L9960_vidSpiM_UpdateOverCurrent(pkstrConfig, pstrData, u16ReceiveData);
   
            /* Launch command request to start the Open Load Diagnostic when L9960 is not in tristate */
            L9960_vidSpi_StartOpenLoadOnDiag(pkstrConfig, pstrData);
   
            /* Update current state */
            pstrData->udtSpiM_StateMachine.OnDiagnostic = L9960_SPIM_SEQ_DIAG_ON_REQUEST_OPEN_LOAD;
            break;
   
         case L9960_SPIM_SEQ_DIAG_ON_REQUEST_OPEN_LOAD:
            /* No data read on this last request */
            
            /* Sequence finished, treat results  */
            pstrData->bOnDiagnosticIsAvailable = TRUE;
   
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

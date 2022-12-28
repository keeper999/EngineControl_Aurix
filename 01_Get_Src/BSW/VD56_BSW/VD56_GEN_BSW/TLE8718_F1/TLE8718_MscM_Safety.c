/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_MscM_Safety.c                                                                           */
/* !Description     : State Machine to perform the Safety Sequence                                                    */
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
 * %PID: P2017_BSW:0A133937.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"

#include "HOD.h"
#include "TLE8718_L.h"
#include "TLE8718_Msc.h"
#include "TLE8718_MscM.h"
#include "TLE8718_Typ.h"

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_SafetyStart                                                                         */
/* !Description : This function starts the SAFETY Sequence.                                                           */
/*                It launches a MSC communication, and the sequence continues on MSC Interrupts                       */
/*                in the TLE8718_vidMscM_SafetyTxConf function.                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_SafetyStart
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Init the Msc Frame Fields */
   TLE8718_au8MscM_CmdId[udtInstance]            = TLE8718_u8MSCM_RD_CONFIG_ID;
   TLE8718_au8MscM_CmdData[udtInstance]          = TLE8718_u8MSCM_RD_ALL_CONFIG_REG; /* Get CONREG1..4 and OUT1516 Registers */
   TLE8718_au8MscM_ExpectedRxFramNb[udtInstance] = 5u; /* 5 Upstream Frames Expected */

   /* Send the Request */
   TLE8718_vidMscStartCommand(udtInstance,
                              TLE8718_au8MscM_CmdId[udtInstance],
                              TLE8718_au8MscM_CmdData[udtInstance],
                              TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_SafetyTxConf                                                                        */
/* !Description : Called on MSC interrupt. This function handles the state machine of Safety.                         */
/*                This sequence has been started by a call to TLE8718_vidMscM_SafetyStart function.                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_SafetyTxConf
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier. */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
   uint8* pu8ReceiveData,
   uint8  u8MscResult
)
{
   TLE8718_au8MscM_ErrorStatus[udtInstance] = u8MscResult;
   if (u8MscResult == TLE8718_u8MSC_COM_OK)
   {
      if (  (TLE8718_au8MscM_CmdId[udtInstance]   == TLE8718_u8MSCM_RD_CONFIG_ID)
         && (TLE8718_au8MscM_CmdData[udtInstance] == TLE8718_u8MSCM_RD_ALL_CONFIG_REG))
      {
         /* Warning: TLE8718_au8ConRegx are shared with TLE8718 Main Layer */
         /* But protected because TLE8718 Main Functions will not access to these variables if the sequence is not */
         /* ended and Diag Sequence cannot be started if TLE8718 Main Functions have not already dealt them        */
         TLE8718_au8ConReg1[udtInstance]    = pu8ReceiveData[0u];
         TLE8718_au8ConReg2[udtInstance]    = pu8ReceiveData[1u];
         TLE8718_au8ConReg3[udtInstance]    = pu8ReceiveData[2u];
         TLE8718_au8ConReg4[udtInstance]    = pu8ReceiveData[3u];
         TLE8718_au8Out1516Reg[udtInstance] = pu8ReceiveData[4u];
         TLE8718_vidMscM_EndOfSequence(udtInstance, TLE8718_udtSEQ_SENT_OK);
      }
      else
      { 
         SWFAIL_vidSoftwareErrorHook();
         TLE8718_vidMscM_EndOfSequence(udtInstance, TLE8718_udtSEQ_SENT_NOK);
      }
   }
   else
   {
      TLE8718_vidMscM_EndOfSequence(udtInstance, TLE8718_udtSEQ_SENT_NOK);
   }
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

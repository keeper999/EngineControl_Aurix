/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_MscM_WrOut1516.c                                                                        */
/* !Description     : State Machine to perform the WR_OUT1516 Sequence                                                */
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
 * %PID: P2017_BSW:0A133936.A-SRC;1 %
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
/* !FuncName    : TLE8718_vidMscM_WrOut1516Start                                                                      */
/* !Description : This function starts the WR_OUT516 Sequence.                                                        */
/*                It launches a MSC communication, and the sequence continues on MSC Interrupts                       */
/*                in the TLE8718_vidMscM_WrOut1516TxConf function.                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_WrOut1516Start
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Init the Msc Frame Fields */
   TLE8718_au8MscM_CmdId[udtInstance]            = TLE8718_u8MSCM_WR_OUT1516_ID;
   TLE8718_au8MscM_CmdData[udtInstance]          = (uint8)(TLE8718_u8OUT15OUT16
                                                 | (!TLE8718_abDioAppliedState[udtInstance][TLE8718_udtOUT_15])
                                                 | (!TLE8718_abDioAppliedState[udtInstance][TLE8718_udtOUT_16] << 4u));

   TLE8718_au8MscM_ExpectedRxFramNb[udtInstance] = 0u; /* No Upstream Frame Expected */

   /* Send the Request */
   TLE8718_vidMscStartCommand(udtInstance,
                              TLE8718_au8MscM_CmdId[udtInstance],
                              TLE8718_au8MscM_CmdData[udtInstance],
                              TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_WrOut1516TxConf                                                                     */
/* !Description : Called on MSC interrupt. This function handles the state machine of WR_OUT1516.                     */
/*                This sequence has been started by a call to TLE8718_vidMscM_WrOut1516Start function.                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_WrOut1516TxConf
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier. */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
   uint8* pu8ReceiveData,
   uint8  u8MscResult
)
{
   COMPILER_UNUSED_PARAMETER(pu8ReceiveData);

   TLE8718_au8MscM_ErrorStatus[udtInstance] = u8MscResult;
   if (u8MscResult == TLE8718_u8MSC_COM_OK)
   {
      switch (TLE8718_au8MscM_CmdId[udtInstance])
      {
         case TLE8718_u8MSCM_WR_OUT1516_ID:
            TLE8718_vidMscM_EndOfSequence(udtInstance, TLE8718_udtSEQ_SENT_OK);
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            TLE8718_vidMscM_EndOfSequence(udtInstance, TLE8718_udtSEQ_SENT_NOK);
            break;
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

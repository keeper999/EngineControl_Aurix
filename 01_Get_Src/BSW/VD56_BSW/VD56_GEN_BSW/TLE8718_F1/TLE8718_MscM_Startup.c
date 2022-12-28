/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_MscM_Startup.c                                                                          */
/* !Description     : State Machine to perform the Startup Sequence                                                   */
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
 * %PID: P2017_BSW:0A133945.A-SRC;1 %
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
/* !FuncName    : TLE8718_vidMscM_ConRegInitStart                                                                     */
/* !Description : This function starts the CONREG_INIT Sequence.                                                      */
/*                It launches a MSC communication, and the sequence continues on MSC Interrupts                       */
/*                in the TLE8718_vidMscM_ConRegInitTxConf function.                                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_ConRegInitStart
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Init the Msc Frame Fields */
   TLE8718_au8MscM_CmdId[udtInstance]            = TLE8718_u8MSCM_WR_CONREG1_ID;
   TLE8718_au8MscM_CmdData[udtInstance]          = TLE8718_u8CONREG1;
   TLE8718_au8MscM_ExpectedRxFramNb[udtInstance] = 0u; /* No Upstream Frame Expected */

   /* Send the Request */
   TLE8718_vidMscStartCommand(udtInstance,
                              TLE8718_au8MscM_CmdId[udtInstance],
                              TLE8718_au8MscM_CmdData[udtInstance],
                              TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_ConRegInitTxConf                                                                    */
/* !Description : Called on MSC interrupt. This function handles the state machine of CONREG_INIT.                    */
/*                This sequence has been started by a call to TLE8718_vidMscM_ConRegInitStart function.               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_ConRegInitTxConf
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
      switch (TLE8718_au8MscM_CmdId[udtInstance])
      {
         case TLE8718_u8MSCM_WR_CONREG1_ID:
            /* Init the Msc Frame Fields */
            TLE8718_au8MscM_CmdId[udtInstance]            = TLE8718_u8MSCM_WR_CONREG2_ID;
            TLE8718_au8MscM_CmdData[udtInstance]          = TLE8718_u8CONREG2;
            TLE8718_au8MscM_ExpectedRxFramNb[udtInstance] = 0u; /* No Upstream Frame Expected */
            /* Send the Request */
            TLE8718_vidMscStartCommand(udtInstance,
                                       TLE8718_au8MscM_CmdId[udtInstance],
                                       TLE8718_au8MscM_CmdData[udtInstance],
                                       TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]);
            break;

         case TLE8718_u8MSCM_WR_CONREG2_ID:
            /* Init the Msc Frame Fields */
            TLE8718_au8MscM_CmdId[udtInstance]           = TLE8718_u8MSCM_WR_CONREG3_ID;
            TLE8718_au8MscM_CmdData[udtInstance]          = TLE8718_u8CONREG3;
            TLE8718_au8MscM_ExpectedRxFramNb[udtInstance] = 0u; /* No Upstream Frame Expected */
            /* Send the Request */
            TLE8718_vidMscStartCommand(udtInstance,
                                       TLE8718_au8MscM_CmdId[udtInstance],
                                       TLE8718_au8MscM_CmdData[udtInstance],
                                       TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]);
            break;

         case TLE8718_u8MSCM_WR_CONREG3_ID:
            /* Init the Msc Frame Fields */
            TLE8718_au8MscM_CmdId[udtInstance]            = TLE8718_u8MSCM_WR_CONREG4_ID;
            TLE8718_au8MscM_CmdData[udtInstance]          = TLE8718_u8CONREG4;
            TLE8718_au8MscM_ExpectedRxFramNb[udtInstance] = 0u; /* No Upstream Frame Expected */
            /* Send the Request */
            TLE8718_vidMscStartCommand(udtInstance,
                                       TLE8718_au8MscM_CmdId[udtInstance],
                                       TLE8718_au8MscM_CmdData[udtInstance],
                                       TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]);
            break;

         case TLE8718_u8MSCM_WR_CONREG4_ID:
            /* Init the Msc Frame Fields */
            TLE8718_au8MscM_CmdId[udtInstance]            = TLE8718_u8MSCM_RD_CONFIG_ID;
            TLE8718_au8MscM_CmdData[udtInstance]          = TLE8718_u8MSCM_RD_CFG_REG_1_TO_4;
            TLE8718_au8MscM_ExpectedRxFramNb[udtInstance] = 4u; /* 4 Upstream Frame Expected */
            /* Send the Request */
            TLE8718_vidMscStartCommand(udtInstance,
                                       TLE8718_au8MscM_CmdId[udtInstance],
                                       TLE8718_au8MscM_CmdData[udtInstance],
                                       TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]);
            break;

         case TLE8718_u8MSCM_RD_CONFIG_ID:
            /* Saving Receive Data of TLE8718 Registers */
            /* Warning: TLE8718_au8ConRegx are shared with TLE8718 Main Layer */
            /* But protected because TLE8718 Main Functions will not access to these variables if the sequence is not */
            /* ended and Diag Sequence cannot be started if TLE8718 Main Functions have not already dealt them        */
            TLE8718_au8ConReg1[udtInstance] = pu8ReceiveData[0u];
            TLE8718_au8ConReg2[udtInstance] = pu8ReceiveData[1u];
            TLE8718_au8ConReg3[udtInstance] = pu8ReceiveData[2u];
            TLE8718_au8ConReg4[udtInstance] = pu8ReceiveData[3u];

            /* Init the Msc Frame Fields */
            TLE8718_au8MscM_CmdId[udtInstance]              = TLE8718_u8MSCM_RD_DATA_ID;
            TLE8718_au8MscM_CmdData[udtInstance]            = TLE8718_u8MSCM_RD_DIAREG6;
            TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]   = 1u; /* 1 Upstream Frame Expected */
            TLE8718_au8MscM_RdDiagReg6Cnt[udtInstance]      = 0u;
            /* Send the Request */
            TLE8718_vidMscStartCommand(udtInstance,
                                       TLE8718_au8MscM_CmdId[udtInstance],
                                       TLE8718_au8MscM_CmdData[udtInstance],
                                       TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]);
            break;

         case TLE8718_u8MSCM_RD_DATA_ID:
            /* Saving Receive Data of TLE8718 Registers */
            /* Warning: TLE8718_au8ConRegx are shared with TLE8718 Main Layer */
            /* But protected because TLE8718 Main Functions will not access to these variables if the sequence is not */
            /* ended and Diag Sequence cannot be started if TLE8718 Main Functions have not already dealt them        */
            TLE8718_au8DiagReg6[udtInstance] = pu8ReceiveData[0u];

            if (TLE8718_au8MscM_RdDiagReg6Cnt[udtInstance] != 0u)
            {
               TLE8718_vidMscM_EndOfSequence(udtInstance, TLE8718_udtSEQ_SENT_OK);
            }
            else
            {
               TLE8718_au8MscM_RdDiagReg6Cnt[udtInstance] = 1u;
               /* Send again the Request */
               TLE8718_vidMscStartCommand(udtInstance,
                                       TLE8718_au8MscM_CmdId[udtInstance],
                                       TLE8718_au8MscM_CmdData[udtInstance],
                                       TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]);
            }
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

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_Out1516IniStart                                                                     */
/* !Description : This function starts the OUT1516_REG_INIT Sequence.                                                 */
/*                It launches a MSC communication, and the sequence continues on MSC Interrupts                       */
/*                in the TLE8718_vidMscM_Out1516IniTxConf function.                                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_Out1516IniStart
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
/* !FuncName    : TLE8718_vidMscM_Out1516IniTxConf                                                                    */
/* !Description : Called on MSC interrupt. This function handles the state machine of OUT1516_REG_INIT.               */
/*                This sequence has been started by a call to TLE8718_vidMscM_Out1516IniStart function.               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_Out1516IniTxConf
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
      switch (TLE8718_au8MscM_CmdId[udtInstance])
      {
         case TLE8718_u8MSCM_WR_OUT1516_ID:
            /* Init the Msc Frame Fields */
            TLE8718_au8MscM_CmdId[udtInstance]            = TLE8718_u8MSCM_RD_CONFIG_ID;
            TLE8718_au8MscM_CmdData[udtInstance]          = TLE8718_u8MSCM_RD_CFG_OUT1516REG;
            TLE8718_au8MscM_ExpectedRxFramNb[udtInstance] = 1u; /* 1 Upstream Frame Expected */
            /* Send the Request */
            TLE8718_vidMscStartCommand(udtInstance,
                                       TLE8718_au8MscM_CmdId[udtInstance],
                                       TLE8718_au8MscM_CmdData[udtInstance],
                                       TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]);
            break;

         case TLE8718_u8MSCM_RD_CONFIG_ID:
            /* Saving Receive Data of TLE8718 Registers */
            /* Warning: TLE8718_au8Out1516Reg is shared with TLE8718 Main Layer */
            /* But protected because TLE8718 Main Functions will not access to these variables if the sequence is not */
            /* ended and Diag Sequence cannot be started if TLE8718 Main Functions have not already dealt them        */
            TLE8718_au8Out1516Reg[udtInstance] = pu8ReceiveData[0u];
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

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_EnaDatFrOutStart                                                                    */
/* !Description : This function starts the ENA_DATA_FRAME_OUTPUTS Sequence.                                           */
/*                It launches a MSC communication, and the sequence continues on MSC Interrupts                       */
/*                in the TLE8718_vidMscM_EnaDaFrOutTxConf function.                                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_EnaDatFrOutStart
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Init the Msc Frame Fields */
   TLE8718_au8MscM_CmdId[udtInstance]            = TLE8718_u8MSCM_WR_START_ID;
   TLE8718_au8MscM_CmdData[udtInstance]          = 0u; /* Don't Care */
   TLE8718_au8MscM_ExpectedRxFramNb[udtInstance] = 0u; /* No Upstream Frame Expected */

   /* Send the Request */
   TLE8718_vidMscStartCommand(udtInstance,
                              TLE8718_au8MscM_CmdId[udtInstance],
                              TLE8718_au8MscM_CmdData[udtInstance],
                              TLE8718_au8MscM_ExpectedRxFramNb[udtInstance]);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_EnaDaFrOutTxConf                                                                    */
/* !Description : Called on MSC interrupt. This function handles the state machine of ENA_DATA_FRAME_OUTPUTS.         */
/*                This sequence has been started by a call to TLE8718_vidMscM_EnaDatFrOutStart function.              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_EnaDaFrOutTxConf
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
         case TLE8718_u8MSCM_WR_START_ID:
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

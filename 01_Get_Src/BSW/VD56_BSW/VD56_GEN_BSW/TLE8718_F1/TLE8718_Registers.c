/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Registers.c                                                                             */
/* !Description     : Functions managing TLE8718 Registers                                                            */
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
 * %PID: P2017_BSW:0A133949.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Limits.h"
#include "Std_Types.h"

#include "HOD.h"
#include "TLE8718.h"
#include "TLE8718_L.h"
#include "TLE8718_Typ.h"

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidCheckAllConfigReg                                                                        */
/* !Description : Check Values of All TLE8718 Configuration Registers                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType TLE8718_udtCheckAllConfigReg
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   Std_ReturnType udtLocalStatus;
   udtLocalStatus = TLE8718_udtCheckConfigReg1(udtInstance);
   if (udtLocalStatus == E_OK)
   {
      udtLocalStatus = TLE8718_udtCheckConfigReg2(udtInstance);
      if (udtLocalStatus == E_OK)
      {
         udtLocalStatus = TLE8718_udtCheckConfigReg3(udtInstance);
         if (udtLocalStatus == E_OK)
         {
            udtLocalStatus = TLE8718_udtCheckConfigReg4(udtInstance);
            if (udtLocalStatus == E_OK)
            {
               udtLocalStatus = TLE8718_udtCheckOut1516Reg(udtInstance);
            }
         }
      }
   }
   return(udtLocalStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_udtCheckConfigReg1To4                                                                       */
/* !Description : Check Values of  TLE8718 Configuration Registers 1 To 4                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType TLE8718_udtCheckConfigReg1To4
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   Std_ReturnType udtLocalStatus;
   udtLocalStatus = TLE8718_udtCheckConfigReg1(udtInstance);
   if (udtLocalStatus == E_OK)
   {
      udtLocalStatus = TLE8718_udtCheckConfigReg2(udtInstance);
      if (udtLocalStatus == E_OK)
      {
         udtLocalStatus = TLE8718_udtCheckConfigReg3(udtInstance);
         if (udtLocalStatus == E_OK)
         {
            udtLocalStatus = TLE8718_udtCheckConfigReg4(udtInstance);
         }
      }
   }
   return(udtLocalStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_udtCheckConfigReg1                                                                          */
/* !Description : Check Values of TLE8718 Configuration Register 1                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType TLE8718_udtCheckConfigReg1
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   Std_ReturnType udtLocalStatus;

   /* Warning: TLE8718_au8ConReg1 is shared with TLE8718 MscM Layer                                                   */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   if (TLE8718_au8ConReg1[udtInstance] != TLE8718_u8CONREG1)
   {
      udtLocalStatus = E_NOT_OK;
   }
   else
   {
      udtLocalStatus = E_OK;
   }

   return(udtLocalStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_udtCheckConfigReg2                                                                          */
/* !Description : Check Values of TLE8718 Configuration Register 2                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType TLE8718_udtCheckConfigReg2
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   Std_ReturnType udtLocalStatus;

   /* Warning: TLE8718_au8ConReg2 is shared with TLE8718 MscM Layer                                                   */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   if (TLE8718_au8ConReg2[udtInstance] != TLE8718_u8CONREG2)
   {
      udtLocalStatus = E_NOT_OK;
   }
   else
   {
      udtLocalStatus = E_OK;
   }

   return(udtLocalStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_udtCheckConfigReg3                                                                          */
/* !Description : Check Values of TLE8718 Configuration Register 3                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType TLE8718_udtCheckConfigReg3
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   Std_ReturnType udtLocalStatus;

   /* Warning: TLE8718_au8ConReg3 is shared with TLE8718 MscM Layer                                                   */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   if (TLE8718_au8ConReg3[udtInstance] != TLE8718_u8CONREG3)
   {
      udtLocalStatus = E_NOT_OK;
   }
   else
   {
      udtLocalStatus = E_OK;
   }

   return(udtLocalStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_udtCheckConfigReg4                                                                          */
/* !Description : Check Values of TLE8718 Configuration Register 4                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType TLE8718_udtCheckConfigReg4
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   Std_ReturnType udtLocalStatus;

   /* Warning: TLE8718_au8ConReg4 is shared with TLE8718 MscM Layer                                                   */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   if (TLE8718_au8ConReg4[udtInstance] != TLE8718_u8CONREG4)
   {
      udtLocalStatus = E_NOT_OK;
   }
   else
   {
      udtLocalStatus = E_OK;
   }

   return(udtLocalStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_udtCheckOut1516Reg                                                                          */
/* !Description : Check Values of TLE8718 Configuration Register OUT1516                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType TLE8718_udtCheckOut1516Reg
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   Std_ReturnType udtLocalStatus;

   /* !Comment: Check only the configuration fields of OUT1516 Register */
   /* Warning: TLE8718_au8Out1516Reg is shared with TLE8718 MscM Layer                                                */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   if ((TLE8718_au8Out1516Reg[udtInstance] & TLE8718_u8OUT15OUT16_CFG_MASK) != TLE8718_u8OUT15OUT16)
   {
      udtLocalStatus = E_NOT_OK;
   }
   else
   {
      udtLocalStatus = E_OK;
   }

   return(udtLocalStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDecodeAllDiagnosisReg                                                                    */
/* !Description : Decode Values of All TLE8718 Diagnosis Registers                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDecodeAllDiagnosisReg
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   TLE8718_vidDecodeDiagReg6(udtInstance);
   TLE8718_vidDecodeDiagReg7(udtInstance);

   if (TLE8718_abFailureDetected[udtInstance] != FALSE)
   {
      TLE8718_vidDecodeDiagReg1(udtInstance);
      TLE8718_vidDecodeDiagReg2(udtInstance);
      TLE8718_vidDecodeDiagReg3(udtInstance);
      TLE8718_vidDecodeDiagReg4(udtInstance);
      TLE8718_vidDecodeDiagReg5(udtInstance);
   }
   else
   {
      TLE8718_vidDiagNoFaultMng(udtInstance);
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDecodeDiagReg1                                                                           */
/* !Description : Decode Diagnosis Register 1                                                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDecodeDiagReg1
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_au8DiagReg1 is shared with TLE8718 MscM Layer                                                  */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   TLE8718_vidDiagRegMng(udtInstance, TLE8718_udtOUT_1, TLE8718_udtOUT_4, TLE8718_au8DiagReg1[udtInstance]);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDecodeDiagReg2                                                                           */
/* !Description : Decode Diagnosis Register 2                                                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDecodeDiagReg2
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_au8DiagReg2 is shared with TLE8718 MscM Layer                                                  */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   TLE8718_vidDiagRegMng(udtInstance, TLE8718_udtOUT_5, TLE8718_udtOUT_8, TLE8718_au8DiagReg2[udtInstance]);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDecodeDiagReg3                                                                           */
/* !Description : Decode Diagnosis Register 3                                                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDecodeDiagReg3
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_au8DiagReg3 is shared with TLE8718 MscM Layer                                                  */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   TLE8718_vidDiagRegMng(udtInstance, TLE8718_udtOUT_9, TLE8718_udtOUT_12, TLE8718_au8DiagReg3[udtInstance]);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDecodeDiagReg4                                                                           */
/* !Description : Decode Diagnosis Register 4                                                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDecodeDiagReg4
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_au8DiagReg4 is shared with TLE8718 MscM Layer                                                  */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   TLE8718_vidDiagRegMng(udtInstance, TLE8718_udtOUT_13, TLE8718_udtOUT_16, TLE8718_au8DiagReg4[udtInstance]);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDecodeDiagReg5                                                                           */
/* !Description : Decode Diagnosis Register 5                                                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDecodeDiagReg5
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_au8DiagReg5 is shared with TLE8718 MscM Layer                                                  */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   uint8 u8LocalDiagReg5 = TLE8718_au8DiagReg5[udtInstance];

   TLE8718_vidDiagRegMng(udtInstance, TLE8718_udtOUT_17, TLE8718_udtOUT_18, u8LocalDiagReg5);

   TLE8718_abReverseCurrentDetected[udtInstance] = (boolean)!((u8LocalDiagReg5 >> 4u) & 0x01u);
   TLE8718_abOut15LevelOnApplied[udtInstance]    = (boolean)!((u8LocalDiagReg5 >> 5u) & 0x01u);
   TLE8718_abOut16LevelOnApplied[udtInstance]    = (boolean)!((u8LocalDiagReg5 >> 6u) & 0x01u);
   TLE8718_abDisOutputs15_16_Active[udtInstance] = (boolean) ((u8LocalDiagReg5 >> 7u) & 0x01u);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDecodeDiagReg6                                                                           */
/* !Description : Decode and Check Diagnosis Register 6                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDecodeDiagReg6
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_au8DiagReg6 is shared with TLE8718 MscM Layer                                                  */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   uint8 u8LocalDiagReg6 = TLE8718_au8DiagReg6[udtInstance];

   TLE8718_abOutputStandByActive[udtInstance]     = (boolean)  (u8LocalDiagReg6        & 0x01u);
   TLE8718_abMscMonTimeoutDetected[udtInstance]   = (boolean)!((u8LocalDiagReg6 >> 1u) & 0x01u);
   TLE8718_abPowerOnResetDetected[udtInstance]    = (boolean) ((u8LocalDiagReg6 >> 2u) & 0x01u);
   TLE8718_abAbeInactive[udtInstance]             = (boolean) ((u8LocalDiagReg6 >> 3u) & 0x01u);
   TLE8718_abFailureDetected[udtInstance]         = (boolean)!((u8LocalDiagReg6 >> 4u) & 0x01u);
   TLE8718_abOverTempDetected[udtInstance]        = (boolean)!((u8LocalDiagReg6 >> 5u) & 0x01u);
   TLE8718_abDisOutputs5_10_Active[udtInstance]   = (boolean)!((u8LocalDiagReg6 >> 6u) & 0x01u);
   TLE8718_abDelayInActive[udtInstance]           = (boolean)!((u8LocalDiagReg6 >> 7u) & 0x01u);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDecodeDiagReg7                                                                           */
/* !Description : Decode Diagnosis Register 7                                                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDecodeDiagReg7
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_au8DiagReg7 is shared with TLE8718 MscM Layer                                                  */
   /* Protected because this variable is only written if TLE8718_audtMscM_SeqStatus takes a value different to        */
   /* TLE8718_udtSEQ_IDLE. But this case can happen only when the sequence is already ended so the MscM layer will    */
   /* not update again this variable.                                                                                 */
   uint8 u8LocalDiagReg7 = TLE8718_au8DiagReg7[udtInstance];

   TLE8718_abBattOverVoltDetected[udtInstance]       = (boolean)!((u8LocalDiagReg7 >> 3) & 0x01);
   TLE8718_abFactoryTestDisabled[udtInstance]        = (boolean) ((u8LocalDiagReg7 >> 4) & 0x01);
   TLE8718_abVDD_OverVoltDetected[udtInstance]       = (boolean)!((u8LocalDiagReg7 >> 5) & 0x01);
   TLE8718_abVDD_UnderVoltDetected[udtInstance]      = (boolean)!((u8LocalDiagReg7 >> 6) & 0x01);
   TLE8718_abVDD_MonitorTestActive[udtInstance]      = (boolean)!((u8LocalDiagReg7 >> 7) & 0x01);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDiagRegMng                                                                               */
/* !Description : Diagnosis of Outputs in Diag Registers                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDiagRegMng
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier. */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
   HOD_tudtChannel udtOutputChannelBeg,
   HOD_tudtChannel udtOutputChannelEnd,
   uint8 u8RxData
)
{
   HOD_tudtChannel udtLocalOutputChannel;

   uint8_least u8LocalCounter = UINT8_MIN;

   for (udtLocalOutputChannel =  udtOutputChannelBeg;
        udtLocalOutputChannel <= udtOutputChannelEnd;
        udtLocalOutputChannel ++)
   {
      TLE8718_au8DiagOutput[udtInstance][udtLocalOutputChannel] = (((u8RxData >> u8LocalCounter) & 0x03u));
      u8LocalCounter += 2u;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDiagNoFaultMng                                                                           */
/* !Description : No Fault Detected on TLE8718                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDiagNoFaultMng
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   HOD_tudtChannel udtLocalOutputChannel;

   for (udtLocalOutputChannel = 0u;
        udtLocalOutputChannel < TLE8718_udtCHANNEL_NB;
        udtLocalOutputChannel ++)
   {
      TLE8718_au8DiagOutput[udtInstance][udtLocalOutputChannel] = TLE8718_u8POWER_STAGE_OK;
   }
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/

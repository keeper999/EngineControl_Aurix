/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_MscM.c                                                                                  */
/* !Description     : To Handle the MSC Protocol                                                                      */
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
 * %PID: P2017_BSW:0A133943.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"

#include "HOD.h"
#include "SchM_TLE8718.h"
#include "TLE8718.h"
#include "TLE8718_L.h"
#include "TLE8718_Msc.h"
#include "TLE8718_MscM.h"
#include "TLE8718_Typ.h"

/**********************************************************************************************************************/
/* CONSTANTS                                                                                                          */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CONST_UNSPECIFIED
#include "TLE8718_MemMap.h"

/* the both below table order is same as TLE8718_tenuMscMSequences enums */
/* MscM: sequence start function */
void (* const TLE8718_kapfvidMscM_StartSeqFct[TLE8718_udtMSCM_SEQUENCE_NB])(HOD_tudtInstance udtInstance) =
{
   &TLE8718_vidMscM_WrOut1516Start,       /* TLE8718_MSCM_SEQ_WR_OUT1516      */
   &TLE8718_vidMscM_DiagStart,            /* TLE8718_MSCM_SEQ_DIAG            */
   &TLE8718_vidMscM_SafetyStart,          /* TLE8718_MSCM_SEQ_SAFETY          */
   &TLE8718_vidMscM_ConRegInitStart,      /* TLE8718_MSCM_SEQ_CONREG_INIT     */
   &TLE8718_vidMscM_Out1516IniStart,      /* TLE8718_MSCM_SEQ_OUT1516REG_INIT */
   &TLE8718_vidMscM_EnaDatFrOutStart,     /* TLE8718_MSCM_SEQ_ENA_DATA_FR_OUT */
};
/* MscM: function to call on MSC TxConfirmation */
void (* const TLE8718_kapfvidMscM_TxConfFct[TLE8718_udtMSCM_SEQUENCE_NB])(HOD_tudtInstance udtInstance,
                                                                     uint8* pu8ReceiveData,
                                                                     uint8 u8MscError) =
{
   &TLE8718_vidMscM_WrOut1516TxConf,      /* TLE8718_MSCM_SEQ_WR_OUT1516      */
   &TLE8718_vidMscM_DiagTxConf,           /* TLE8718_MSCM_SEQ_DIAG            */
   &TLE8718_vidMscM_SafetyTxConf,         /* TLE8718_MSCM_SEQ_SAFETY          */
   &TLE8718_vidMscM_ConRegInitTxConf,     /* TLE8718_MSCM_SEQ_CONREG_INIT     */
   &TLE8718_vidMscM_Out1516IniTxConf,     /* TLE8718_MSCM_SEQ_OUT1516REG_INIT */
   &TLE8718_vidMscM_EnaDaFrOutTxConf,     /* TLE8718_MSCM_SEQ_ENA_DATA_FR_OUT */
};

#define TLE8718_STOP_SEC_CONST_UNSPECIFIED
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* FUNCTIONS                                                                                                          */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_Init                                                                                */
/* !Description : Init of the MscM layer                                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_Init(void)
{
   HOD_tudtInstance udtLocalInstance;
   uint8_least      u8LocalSequenceIdx;

   for (udtLocalInstance = 0u; udtLocalInstance < TLE8718_udtINSTANCE_NB; udtLocalInstance++)
   {
      TLE8718_aenuMscM_SeqRunning[udtLocalInstance]      = TLE8718_MSCM_SEQ_WAITING_STATE;
      TLE8718_au8MscM_CmdData[udtLocalInstance]          = 0u;
      TLE8718_au8MscM_CmdId[udtLocalInstance]            = TLE8718_u8MSCM_UNKNOWN_ID;
      TLE8718_au8MscM_RdDiagReg6Cnt[udtLocalInstance]    = 0u;
      TLE8718_au8MscM_ExpectedRxFramNb[udtLocalInstance] = 0u;
      TLE8718_au8MscM_ErrorStatus[udtLocalInstance]      = 0u;

      for (u8LocalSequenceIdx = 0u; u8LocalSequenceIdx < TLE8718_udtMSCM_SEQUENCE_NB; u8LocalSequenceIdx++)
      {
         TLE8718_abMscM_SeqRequest[udtLocalInstance][u8LocalSequenceIdx]  = FALSE;
         TLE8718_audtMscM_SeqStatus[udtLocalInstance][u8LocalSequenceIdx] = TLE8718_udtSEQ_IDLE;
      }
   }
   TLE8718_vidMscInit();
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_Manager                                                                             */
/* !Description : This function is the entry point of the Sequence Manager                                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_Manager
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   uint8_least u8LocalSequenceIdx;
   boolean     bLocSequenceFound = FALSE;

   SchM_Enter_TLE8718_MscM_Manager();
   if (TLE8718_aenuMscM_SeqRunning[udtInstance] == TLE8718_MSCM_SEQ_WAITING_STATE)
   {
      for (u8LocalSequenceIdx = 0u;
          (u8LocalSequenceIdx < TLE8718_udtMSCM_SEQUENCE_NB) && (bLocSequenceFound == FALSE);
           u8LocalSequenceIdx ++)
      {
         /* We check, in priority order, which sequence to start */
         /* Warning: TLE8718_abMscM_SeqRequest and TLE8718_audtMscM_SeqStatus are shared with TLE8718 Main Layer */
         if (TLE8718_abMscM_SeqRequest[udtInstance][u8LocalSequenceIdx] != FALSE)
         {
            /* Stop the loop on first found sequence to run */
            bLocSequenceFound = TRUE;
            /* Set to the value of sequence which becomes running */
            TLE8718_aenuMscM_SeqRunning[udtInstance] = (TLE8718_tenuMscMSequences)u8LocalSequenceIdx;
            /* Clear the request */
            TLE8718_abMscM_SeqRequest[udtInstance][u8LocalSequenceIdx] = FALSE;
            /* Cahnge Status of sequence */
            TLE8718_audtMscM_SeqStatus[udtInstance][u8LocalSequenceIdx] = TLE8718_udtSEQ_RUNNING;
            SchM_Exit_TLE8718_MscM_Manager();
            /* Launch the found sequence */
            TLE8718_kapfvidMscM_StartSeqFct[u8LocalSequenceIdx](udtInstance);
         }
      }
   }
   if (bLocSequenceFound == FALSE)
   {
      SchM_Exit_TLE8718_MscM_Manager();
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_Task                                                                                */
/* !Description : Function to check if a sequence has to be launched and launches it.                                 */
/*                This function must be "trig" by SchM_Trigger_TLE8718_MscM                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_Task
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Call the Manager to start next pending sequence */
   TLE8718_vidMscM_Manager(udtInstance);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_EndOfSequence                                                                       */
/* !Description : Function to call to stop a sequence in progress                                                     */
/*                This function re-init the state machine                                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_EndOfSequence
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier. */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
   TLE8718_tenuReturnType udtReturnType
)
{
   uint8 u8LocalSequenceIdx = TLE8718_aenuMscM_SeqRunning[udtInstance];

   /* Update Status of Current Sequence */
   /* Warning: TLE8718_audtMscM_SeqStatus is shared with TLE8718 Main Layer */
   TLE8718_audtMscM_SeqStatus[udtInstance][u8LocalSequenceIdx] = udtReturnType;

   /* Reset the State Machine */
   TLE8718_aenuMscM_SeqRunning[udtInstance] = TLE8718_MSCM_SEQ_WAITING_STATE;

   SchM_Trigger_TLE8718_MscM(udtInstance);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMscM_ManagerTxConf                                                                       */
/* !Description : This function is the Notification Callback of Command Frame Tx                                      */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMscM_ManagerTxConf
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier. */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
   uint8* pu8ReceiveData,
   uint8  u8MscResult
)
{
   TLE8718_tenuMscMSequences enuLocSeqRunning;

   enuLocSeqRunning = TLE8718_aenuMscM_SeqRunning[udtInstance];
   if (enuLocSeqRunning < TLE8718_udtMSCM_SEQUENCE_NB)
   {
      /* Launches the Tx Confirmation Function of the Active Sequence */
      TLE8718_kapfvidMscM_TxConfFct[enuLocSeqRunning](udtInstance, pu8ReceiveData, u8MscResult);
   }
   else
   {
      /* We Sent a MSC Command, but no Sequence is Running */
      SWFAIL_vidSoftwareErrorHook();
   }
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/

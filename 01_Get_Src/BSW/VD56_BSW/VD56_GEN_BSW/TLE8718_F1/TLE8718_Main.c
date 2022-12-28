/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Main.c                                                                                  */
/* !Description     : Main Functions of TLE8718 Component                                                             */
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
 * %PID: P2017_BSW:0A133948.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "HOD.h"
#include "Msc.h"
#include "SchM_TLE8718.h"
#include "SWFAIL.h"
#include "TLE8718.h"
#include "TLE8718_L.h"
#include "TLE8718_MscM.h"
#include "TLE8718_Typ.h"

/**********************************************************************************************************************/
/* CONSTANTS                                                                                                          */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CONST_UNSPECIFIED
#include "TLE8718_MemMap.h"

/* the both below table order is same as TLE8718_tenuMscMSequences enums */
/* MscM: sequence start function */
void (* const TLE8718_kapfvidSeqReqNotifSeqFct[TLE8718_udtMSCM_SEQUENCE_NB])(HOD_tudtInstance udtInstance) =
{
   &TLE8718_vidWrOut1516ReqNotif,     /* TLE8718_MSCM_SEQ_WR_OUT1516      */
   &TLE8718_vidDiagReqNotif,          /* TLE8718_MSCM_SEQ_DIAG            */
   &TLE8718_vidSafetyReqNotif,        /* TLE8718_MSCM_SEQ_SAFETY          */
   &TLE8718_vidConRegInitReqNotif,    /* TLE8718_MSCM_SEQ_CONREG_INIT     */
   &TLE8718_vidOut1516RegIniReqNotif, /* TLE8718_MSCM_SEQ_OUT1516REG_INIT */
   &TLE8718_vidEnaDataFrOutReqNotif,  /* TLE8718_MSCM_SEQ_ENA_DATA_FR_OUT */
};

#define TLE8718_STOP_SEC_CONST_UNSPECIFIED
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* FUNCTIONS                                                                                                          */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

LOCAL_INLINE void TLE8718_vidHandleSeqNotif(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidStateMachineMain(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidState_UNINIT(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidState_INIT_READY(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidState_CONREG_INIT(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidState_OUT1516REG_INIT(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidState_ENA_DFRAME_OUT(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidState_RUNNING(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidState_EMERGENCY(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidEnterInConRegIniState (HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidEnterInOu1516IniState(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidEnterInEnaOutState(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidEnterInRunningState(HOD_tudtInstance udtInstance);
LOCAL_INLINE void TLE8718_vidEnterInEmercencyState(HOD_tudtInstance udtInstance);

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidMainFunction                                                                             */
/* !Description : Main Function to Manage TLE8718                                                                     */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidMainFunction
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Decode All Sequence Received and Make Diagnosis */
   TLE8718_vidHandleSeqNotif(udtInstance);
   /* Update the State Machine and Execute Linked Actions */
   TLE8718_vidStateMachineMain(udtInstance);
   /* Call the Manager to start next pending sequence */
   TLE8718_vidMscM_Manager(udtInstance);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidHandleSeqNotif                                                                           */
/* !Description : Function to Analyses Received Data From Msc Layer                                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidHandleSeqNotif
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   uint8_least u8LocalSequenceIdx;

   /* Update all informations returned by MscM Sequences */
   for (u8LocalSequenceIdx = 0u; u8LocalSequenceIdx < TLE8718_udtMSCM_SEQUENCE_NB; u8LocalSequenceIdx++)
   {
      /* Warning: TLE8718_audtMscM_SeqStatus is shared with TLE8718 Main Layer */
      /* Protected because this variable is only written if it takes a value different to TLE8718_udtSEQ_IDLE         */
      /* But this case can happen only when the sequence is already ended so the MscM layer will not update again     */
      /* this variable.                                                                                               */
      if (TLE8718_audtMscM_SeqStatus[udtInstance][u8LocalSequenceIdx] != TLE8718_udtSEQ_IDLE)
      {
         TLE8718_kapfvidSeqReqNotifSeqFct[u8LocalSequenceIdx](udtInstance);
      }
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidStateMachineMain                                                                         */
/* !Description : Function to Update State Machine                                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidStateMachineMain
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   switch (TLE8718_aenuState[udtInstance])
   {
      case TLE8718_STATE_RUNNING:
         TLE8718_vidState_RUNNING(udtInstance);
         break;

      case TLE8718_STATE_EMERGENCY:
         TLE8718_vidState_EMERGENCY(udtInstance);
         break;

      case TLE8718_STATE_CONREG_INIT:
         TLE8718_vidState_CONREG_INIT(udtInstance);
         break;

      case TLE8718_STATE_OUT1516REG_INIT:
         TLE8718_vidState_OUT1516REG_INIT(udtInstance);
         break;

      case TLE8718_STATE_ENA_DATA_FRAME_OUT:
         TLE8718_vidState_ENA_DFRAME_OUT(udtInstance);
         break;

      case TLE8718_STATE_INIT_READY:
         TLE8718_vidState_INIT_READY(udtInstance);
         break;

      case TLE8718_STATE_UNINIT:
         TLE8718_vidState_UNINIT(udtInstance);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidState_UNINIT                                                                             */
/* !Description : State machine of the TLE8718                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidState_UNINIT
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   COMPILER_UNUSED_PARAMETER(udtInstance);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidState_INIT_READY                                                                         */
/* !Description : State machine of the TLE8718                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidState_INIT_READY
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   TLE8718_vidEnterInConRegIniState(udtInstance);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidState_CONREG_INIT                                                                        */
/* !Description : State machine of the TLE8718                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidState_CONREG_INIT
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   if (  (TLE8718_abMscFailure[udtInstance]           != FALSE)
      || (TLE8718_abSafetyFailure[udtInstance]        != FALSE)
      || (TLE8718_abMajorFailureDetected[udtInstance] != FALSE))
   {
      TLE8718_vidEnterInEmercencyState(udtInstance);
   }
   else
   {
      TLE8718_vidEnterInOu1516IniState(udtInstance);
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidState_OUT1516REG_INIT                                                                    */
/* !Description : State machine of the TLE8718                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidState_OUT1516REG_INIT
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   if (  (TLE8718_abMscFailure[udtInstance]    != FALSE)
      || (TLE8718_abSafetyFailure[udtInstance] != FALSE))
   {
      TLE8718_vidEnterInEmercencyState(udtInstance);
   }
   else
   {
      TLE8718_vidEnterInEnaOutState(udtInstance);
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidState_ENA_DFRAME_OUT                                                                     */
/* !Description : State machine of the TLE8718                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidState_ENA_DFRAME_OUT
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   if (TLE8718_abMscFailure[udtInstance] != FALSE)
   {
      TLE8718_vidEnterInEmercencyState(udtInstance);
   }
   else
   {
      TLE8718_vidEnterInRunningState(udtInstance);
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidState_RUNNING                                                                            */
/* !Description : State machine of the TLE8718                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidState_RUNNING
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   if (  (TLE8718_abMscFailure[udtInstance]           != FALSE)
      || (TLE8718_abSafetyFailure[udtInstance]        != FALSE)
      || (TLE8718_abMajorFailureDetected[udtInstance] != FALSE))
   {
      TLE8718_vidEnterInEmercencyState(udtInstance);
   }
   else
   {
      if (TLE8718_abReactDelayMngEvent[udtInstance] != FALSE)
      {
         TLE8718_abReactDelayMngEvent[udtInstance]     = FALSE;
         TLE8718_vidReactivationDelayMng(udtInstance);
      }
      if (TLE8718_abWrOut1516ReqStartEvent[udtInstance] != FALSE)
      {
         TLE8718_abWrOut1516ReqStartEvent[udtInstance] = FALSE;
         TLE8718_vidWrOut1516ReqStart(udtInstance);
      }
      if (TLE8718_abDiagReqStartEvent[udtInstance] != FALSE)
      {
         TLE8718_abDiagReqStartEvent[udtInstance]      = FALSE;
         TLE8718_vidDiagReqStart(udtInstance);
      }
      if (TLE8718_abSafetyReqStartEvent[udtInstance] != FALSE)
      {
         TLE8718_abSafetyReqStartEvent[udtInstance]    = FALSE;
         TLE8718_vidSafetyReqStart(udtInstance);
      }
   }
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidState_EMERGENCY                                                                          */
/* !Description : State machine of the TLE8718                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidState_EMERGENCY
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   COMPILER_UNUSED_PARAMETER(udtInstance);
   /* To Do Next */
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEnterInInitReadyState                                                                    */
/* !Description : This Function is Called To allow initialization of TLE8718 component                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidEnterInInitReadyState
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   TLE8718_aenuState[udtInstance] = TLE8718_STATE_INIT_READY;
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEnterInConRegIniState                                                                    */
/* !Description : This Function is Called When Register Configuration Init State in Entered                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidEnterInConRegIniState
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   TLE8718_aenuState[udtInstance] = TLE8718_STATE_CONREG_INIT;
   TLE8718_vidConRegInitReqStart(udtInstance);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEnterInOu1516IniState                                                                    */
/* !Description : This Function is Called When Output1516 Init State in Entered                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidEnterInOu1516IniState
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   TLE8718_aenuState[udtInstance] = TLE8718_STATE_OUT1516REG_INIT;
   TLE8718_vidOut1516RegIniReqStart(udtInstance);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEnterInEnaOutState                                                                       */
/* !Description : This Function is Called When Enable Data Frame Outputs State in Entered                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidEnterInEnaOutState
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   TLE8718_aenuState[udtInstance] = TLE8718_STATE_ENA_DATA_FRAME_OUT;
   TLE8718_vidEnaDataFrOutReqStart(udtInstance);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEnterInRunningState                                                                      */
/* !Description : This Function is Called When Running State in Entered                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidEnterInRunningState
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   TLE8718_aenuState[udtInstance] = TLE8718_STATE_RUNNING;
   COMPILER_UNUSED_PARAMETER(udtInstance);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEnterInEmercencyState                                                                    */
/* !Description : This Function is Called When Emergency State in Entered                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void TLE8718_vidEnterInEmercencyState
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   TLE8718_aenuState[udtInstance] = TLE8718_STATE_EMERGENCY;
   COMPILER_UNUSED_PARAMETER(udtInstance);
   /* To Do Next */
   TLE8718_vidDISA_TLE8718(udtInstance);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidSetDataOutputState                                                                       */
/* !Description : Set the State of Data Frame Output                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidSetDataOutputState
(
   HOD_tudtInstance udtInstance, /* !Comment: TLE8718 instance identifier.                  */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1                    */
   HOD_tudtChannel udtChannel,   /* !Comment: TLE8718 channel identifier of the udtInstance */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1                     */
   boolean bState                /* !Comment: command to apply to the channel               */
                                 /* !Range  : STD_ON / STD_OFF                              */
)
{
   uint8  u8LocalBitPosition;
   uint32 u32LocalDataOutput;

   u8LocalBitPosition = TLE8718_kau8MscBitPosition[udtChannel];
   SchM_Enter_TLE8718_WriteDataReg();
   u32LocalDataOutput = TLE8718_au32DataOutput[udtInstance] & (~(1u << u8LocalBitPosition));
   TLE8718_au32DataOutput[udtInstance] = u32LocalDataOutput | ((!bState) << u8LocalBitPosition);
   SchM_Exit_TLE8718_WriteDataReg();
   /* If MSC API is called whereas MSC Tx is not initialized (in TLE8718_vidEnable API) then a Det error is raised */
   if (TLE8718_aenuState[udtInstance] != TLE8718_STATE_UNINIT)
   {
      Msc_TxDataFrame(TLE8718_kau8Module[udtInstance],
                      TLE8718_kaudtTxDevice[udtInstance],
                      TLE8718_kaudtTxDevice[udtInstance],
                      &TLE8718_au32DataOutput[udtInstance]);
   }
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/

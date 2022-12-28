/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_WrOut1516.c                                                                             */
/* !Description     : WR_OUT1516 Functions of TLE8718 Component                                                       */
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
 * %PID: P2017_BSW:0A133934.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"

#include "HOD.h"
#include "SchM_TLE8718.h"
#include "TLE8718.h"
#include "TLE8718_L.h"
#include "TLE8718_MscM.h"
#include "TLE8718_Typ.h"

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidWrOut1516ReqStart                                                                        */
/* !Description : Function to Manage a Tx Request of WR_OUT1516 Sequence                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidWrOut1516ReqStart
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_audtMscM_SeqStatus and TLE8718_abMscM_SeqRequest are shared with TLE8718 MscM Layer */
   SchM_Enter_TLE8718_StartWR_OUT1516();
   if (  (TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_WR_OUT1516] == TLE8718_udtSEQ_IDLE)
      && (TLE8718_abMscM_SeqRequest[udtInstance][TLE8718_MSCM_SEQ_WR_OUT1516]  == FALSE))
   {
      TLE8718_abMscM_SeqRequest[udtInstance][TLE8718_MSCM_SEQ_WR_OUT1516] = TRUE;
   }
   SchM_Exit_TLE8718_StartWR_OUT1516();
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidTxWrOut1516FrameNotif                                                                    */
/* !Description : Function Managing Tx Notification of WR_OUT1516 Sequence                                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidWrOut1516ReqNotif
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   if (TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_WR_OUT1516] != TLE8718_udtSEQ_SENT_OK)
   {
      TLE8718_abMscFailure[udtInstance] = TRUE;
   }
   /* Warning: TLE8718_audtMscM_SeqStatus is shared with TLE8718 MscM Layer                                           */
   /* Protected because this variable is only written if it takes a value different to TLE8718_udtSEQ_IDLE            */
   /* But this case can happen only when the sequence is already ended so the MscM layer will not update again        */
   /* this variable.                                                                                                  */
   TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_WR_OUT1516] = TLE8718_udtSEQ_IDLE;
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/

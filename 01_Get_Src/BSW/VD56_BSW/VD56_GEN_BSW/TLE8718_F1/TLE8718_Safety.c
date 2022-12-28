/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Safety.c                                                                                */
/* !Description     : Safety Functions of TLE8718 Component                                                           */
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
 * %PID: P2017_BSW:0A133935.A-SRC;1 %
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
/* !FuncName    : TLE8718_vidSafetyReqStart                                                                           */
/* !Description : Function to Manage a Tx Request of Safety Sequence                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidSafetyReqStart
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_audtMscM_SeqStatus and TLE8718_abMscM_SeqRequest are shared with TLE8718 MscM Layer */
   SchM_Enter_TLE8718_StartSAFETY();
   if (  (TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_SAFETY] == TLE8718_udtSEQ_IDLE)
      && (TLE8718_abMscM_SeqRequest[udtInstance][TLE8718_MSCM_SEQ_SAFETY]  == FALSE))
   {
      TLE8718_abMscM_SeqRequest[udtInstance][TLE8718_MSCM_SEQ_SAFETY] = TRUE;
   }
   SchM_Exit_TLE8718_StartSAFETY();
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidTxSafetyFrameNotif                                                                       */
/* !Description : Function Managing Tx Notification of Safety Sequence                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidSafetyReqNotif
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   Std_ReturnType udtLocalStatus;

   if (TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_SAFETY] == TLE8718_udtSEQ_SENT_OK)
   {
      /* Decode and Check Configuration Registers 1 to 5 */
      udtLocalStatus = TLE8718_udtCheckAllConfigReg(udtInstance);
      if (udtLocalStatus != E_OK)
      {
         TLE8718_abSafetyFailure[udtInstance] = TRUE;
      }
   }
   else
   {
      TLE8718_abMscFailure[udtInstance] = TRUE;
   }
   /* Warning: TLE8718_audtMscM_SeqStatus is shared with TLE8718 MscM Layer                                           */
   /* Protected because this variable is only written if it takes a value different to TLE8718_udtSEQ_IDLE            */
   /* But this case can happen only when the sequence is already ended so the MscM layer will not update again        */
   /* this variable.                                                                                                  */
   TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_SAFETY] = TLE8718_udtSEQ_IDLE;
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/

/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Startup.c                                                                               */
/* !Description     : Start-up Functions of TLE8718 Component                                                         */
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
 * %PID: P2017_BSW:0A133941.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "HOD.h"
#include "SchM_TLE8718.h"
#include "TLE8718.h"
#include "TLE8718_L.h"
#include "TLE8718_MscM.h"
#include "TLE8718_Typ.h"

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidConRegInitReqStart                                                                       */
/* !Description : Function to Manage a Tx Request of Configuration Register Init Sequence                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidConRegInitReqStart
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_abMscM_SeqRequest is shared with TLE8718 MscM Layer                                           */
   /* No need of Protection because low layer clear the boolean only when it is set to TRUE but it can be set only   */
   /* in this function and this function is called only once.                                                        */
   TLE8718_abMscM_SeqRequest[udtInstance][TLE8718_MSCM_SEQ_CONREG_INIT] = TRUE;
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidConRegInitReqNotif                                                                       */
/* !Description : Function Managing Notification of Configuration Register Init Sequence                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidConRegInitReqNotif
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   Std_ReturnType udtLocalStatus;

   if (TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_CONREG_INIT] == TLE8718_udtSEQ_SENT_OK)
   {
      /* Decode and Check Configuration Registers 1 to 4 */
      udtLocalStatus = TLE8718_udtCheckConfigReg1To4(udtInstance);
      if (udtLocalStatus != E_OK)
      {
         TLE8718_abSafetyFailure[udtInstance] = TRUE;
      }
      /* Decode and Check Diagnosis Register 6 */
      TLE8718_vidDecodeDiagReg6(udtInstance);
      
      /* TODO: Additions tests to do in next delivery for safety */
   }
   else
   {
      TLE8718_abMscFailure[udtInstance] = TRUE;
   }
   /* Warning: TLE8718_audtMscM_SeqStatus is shared with TLE8718 MscM Layer                                  */
   /* Protected because this variable is only written if it takes a value different to TLE8718_udtSEQ_IDLE   */
   /* But this case can happen only when the sequence is already ended so the MscM layer will not update     */
   /* again this variable.                                                                                   */
   TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_CONREG_INIT] = TLE8718_udtSEQ_IDLE;
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidOut1516RegIniReqStart                                                                    */
/* !Description : Function to Manage a Tx Request of OUT1516 Register Init Sequence                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidOut1516RegIniReqStart
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_abMscM_SeqRequest is shared with TLE8718 MscM Layer                                           */
   /* No need of Protection because low layer cleraer the boolean only when it is set to TRUE but it can be set only */
   /* in this function and this function is called only once.                                                        */
   TLE8718_abMscM_SeqRequest[udtInstance][TLE8718_MSCM_SEQ_OUT1516REG_INIT] = TRUE;
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidOut1516RegIniReqNotif                                                                    */
/* !Description : Function Managing Notification of Configuration Register Init Sequence                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidOut1516RegIniReqNotif
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   Std_ReturnType udtLocalStatus;

   if (TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_OUT1516REG_INIT] == TLE8718_udtSEQ_SENT_OK)
   {
      /* Decode and Check Configuration Register */
      udtLocalStatus = TLE8718_udtCheckOut1516Reg(udtInstance);
      if (udtLocalStatus != E_OK)
      {
         TLE8718_abSafetyFailure[udtInstance] = TRUE;
      }
   }
   else
   {
      TLE8718_abMscFailure[udtInstance] = TRUE;
   }
   /* Warning: TLE8718_audtMscM_SeqStatus is shared with TLE8718 MscM Layer                                  */
   /* Protected because this variable is only written if it takes a value different to TLE8718_udtSEQ_IDLE   */
   /* But this case can happen only when the sequence is already ended so the MscM layer will not update     */
   /* again this variable.                                                                                   */
   TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_OUT1516REG_INIT] = TLE8718_udtSEQ_IDLE;
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEnaDataFrOutReqStart                                                                     */
/* !Description : Function to Manage a Tx Request of Sequence to Start Outputs Commanded by Data Frames               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidEnaDataFrOutReqStart
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   /* Warning: TLE8718_abMscM_SeqRequest is shared with TLE8718 MscM Layer                                           */
   /* No need of Protection because low layer cleraer the boolean only when it is set to TRUE but it can be set only */
   /* in this function and this function is called only once.                                                        */
   TLE8718_abMscM_SeqRequest[udtInstance][TLE8718_MSCM_SEQ_ENA_DATA_FR_OUT] = TRUE;
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidEnaDataFrOutReqNotif                                                                     */
/* !Description : Function Managing Notification of Configuration Register Init Sequence                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidEnaDataFrOutReqNotif
(
   HOD_tudtInstance udtInstance /* !Comment: TLE8718 instance identifier. */
                                /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1   */
)
{
   if (TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_ENA_DATA_FR_OUT] == TLE8718_udtSEQ_SENT_OK)
   {
      /* No Action To Do */
   }
   else
   {
      TLE8718_abMscFailure[udtInstance] = TRUE;
   }
   /* Warning: TLE8718_audtMscM_SeqStatus is shared with TLE8718 MscM Layer                                  */
   /* Protected because this variable is only written if it takes a value different to TLE8718_udtSEQ_IDLE   */
   /* But this case can happen only when the sequence is already ended so the MscM layer will not update     */
   /* again this variable.                                                                                   */
   TLE8718_audtMscM_SeqStatus[udtInstance][TLE8718_MSCM_SEQ_ENA_DATA_FR_OUT] = TLE8718_udtSEQ_IDLE;
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/

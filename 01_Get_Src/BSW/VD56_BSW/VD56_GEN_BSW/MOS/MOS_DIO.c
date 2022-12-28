/************************************************* <AUTO_FILE_HEADER> *************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : MOS                                                                                             */
/* !Description     : Drive and Diag HW MOS component commanded through DIO                                           */
/*                                                                                                                    */
/* !File            : MOS_DIO.c                                                                                       */
/* !Description     : API for Diagnosis functions of the Component                                                    */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5012137 01                                                                              */
/* !Reference       : PTS_DOC_5199248 01                                                                              */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:MOS DIO C-99055675X1544X45.A-SRC;1.12 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/


#include "Std_Types.h"
#include "MOS_TYPES.h"
#include "MOS.h"
#include "MOS_Private.h"
#include "MOS_Cfg.h"
#include "Dio.h"
#include "Gpt.h"
#include "SchM_MOS.h"
#include "SWFAIL.h"


#define MOS_START_SEC_CODE
#include "MOS_MemMap.h"


/**********************************************************************************************************************/
/* !FuncName    : MOS_bDioRead                                                                                        */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEMS_R_07_01216_022.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  O. Roisin                                                                                          */
/**********************************************************************************************************************/

FUNC(boolean, MOS_CODE) MOS_bDioRead
(
   HOD_tudtInstance udtInstance, /* !Comment: MOS instance identifier.        */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1      */
   HOD_tudtChannel udtChannel    /* !Comment: MOS channel identifier of the   */
                                 /*           udtInstance                     */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1       */
                                 /* !Deviation: Violation of QAC_3206 rule.   */
                                 /*  Reason : udtChannel is always equal to 1 */
                                 /*  in MOS component.                        */
)
{
   Dio_LevelType bLocalCurrentCommand;


   if (udtInstance < MOS_udtINSTANCE_NB)
   {
      bLocalCurrentCommand =
         Dio_ReadChannel(MOS_akudtDioMcalChannel[udtInstance]);
      bLocalCurrentCommand =
         (bLocalCurrentCommand == STD_LOW) ? STD_OFF : STD_ON;
   }
   else
   {
      bLocalCurrentCommand = STD_OFF;
      SWFAIL_vidSoftwareErrorHook();
   }

   return(bLocalCurrentCommand);
}

/**********************************************************************************************************************/
/* !FuncName    : MOS_vidDioWrite                                                                                     */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEMS_R_07_01216_023.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  (O. Roisin                                                                                         */
/**********************************************************************************************************************/

FUNC(void, MOS_CODE) MOS_vidDioWrite
(
   HOD_tudtInstance udtInstance, /* !Comment: MOS instance identifier.        */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1      */
   HOD_tudtChannel udtChannel,   /* !Comment: MOS channel identifier of the   */
                                 /*           udtInstance                     */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1       */
                                 /* !Deviation: Violation of QAC_3206 rule.   */
                                 /*  Reason : udtChannel is always equal to 1 */
                                 /*  in MOS component.                        */
   boolean bState                /* !Comment: command to apply to the channel */
                                 /* !Range  : STD_ON / STD_OFF                */
)
{
   Dio_LevelType   bLocalLastCommand;
   Dio_LevelType   bLocalCommand;
   Dio_ChannelType udtLocalDioMcalChannel;
   Gpt_ValueType  *pudtLocalTransitionTime;
   uint8_least     u8LocalReactivationRemainDelay;


   if (udtInstance < MOS_udtINSTANCE_NB)
   {
      MOS_abDioLastCommand[udtInstance] = bState;
      udtLocalDioMcalChannel            = MOS_akudtDioMcalChannel[udtInstance];

      bLocalLastCommand              = Dio_ReadChannel(udtLocalDioMcalChannel);
      u8LocalReactivationRemainDelay =
         MOS_au8ReactivationRemainDelay[udtInstance];

      if (  (u8LocalReactivationRemainDelay == 0)
         && (MOS_au8CmdAuthorized[udtInstance] == MOS_u8CMD_ENABLED) )
      {
         bLocalCommand = ( (bState != STD_ON) ? STD_LOW : STD_HIGH);

         if (bLocalLastCommand != bLocalCommand)
         {
            if ( (MOS_abDiagnosisAuthorized[udtInstance]) != FALSE)
            {
               if (MOS_akbEdgeDiag[udtInstance] != FALSE)
               {
                  MOS_bDiagOnEdgeRunning = TRUE;
                  MOS_vidDioDiagByDigitalReadBack(udtInstance);
                  MOS_bDiagOnEdgeRunning = FALSE;
               }
            }

            pudtLocalTransitionTime = &MOS_audtTransitionTime[udtInstance];

            /* !Comment: This atomic section shall contain the update of the  */
            /* state of the DIO PIN, and the reading of the value of MOS_TIMER*/
            /* in order to have the exact time after the update of the state  */
            /* to be able to make the diagnosis at the right time.            */
            SchM_Enter_MOS_EdgeDiagPreemptDis();
            SchM_Enter_MOS_EdgeDiagPreemptEna();
            Dio_WriteChannel(udtLocalDioMcalChannel, bLocalCommand);
            *pudtLocalTransitionTime           = Gpt_GetTimeElapsed(MOS_udtTIMER);
            MOS_abDioCurrentState[udtInstance] = bLocalCommand;

            SchM_Exit_MOS_EdgeDiagPreemptDis();

            MOS_audtDownCounter[udtInstance] =
               MOS_akudtOvfProtectionValue[udtInstance];

            MOS_audtMaskTimeToApply[udtInstance] = (bLocalCommand == STD_LOW)
                                                   ? *(MOS_akpudtLowMaskTime[udtInstance])
                                                   : *(MOS_akpudtHighMaskTime[udtInstance]);

            MOS_abTransition[udtInstance] = TRUE;

            SchM_Exit_MOS_EdgeDiagPreemptEna();
         }
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

#define MOS_STOP_SEC_CODE
#include "MOS_MemMap.h"


/*-------------------------------- end of file -------------------------------*/

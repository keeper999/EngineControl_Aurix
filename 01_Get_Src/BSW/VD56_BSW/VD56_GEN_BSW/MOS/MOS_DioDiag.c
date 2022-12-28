/************************************************* <AUTO_FILE_HEADER> *************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : MOS                                                                                             */
/* !Description     : Drive and Diag HW MOS component commanded through DIO                                           */
/*                                                                                                                    */
/* !File            : MOS_DioDiag.c                                                                                   */
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
 * %PID: LIBEMB:MOS DIODIAG C-99055675X1544X49.A-SRC;1.12 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/


#include "Std_Types.h"
#include "MOS_TYPES.h"
#include "MOS.h"
#include "MOS_Private.h"
#include "MOS_Cfg.h"
#include "HOD.h"
#include "Dio.h"
#include "Gpt.h"
#include "DGOHAL.h"
#include "SchM_MOS.h"
#include "SWFAIL.h"


/* !MComment: Check of defines declaration                                    */
#ifndef HOD_coNOTIF_DURING_OVER_CURRENT
   #error The macro-constant HOD_coNOTIF_DURING_OVER_CURRENT shall be defined
#endif
#ifndef TRUE
   #error The macro-constant TRUE shall be defined
#endif


#define MOS_START_SEC_CODE
#include "MOS_MemMap.h"


/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/* !FuncName    : MOS_vidMainFunction                                                                                 */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEMS_R_07_01216_017.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  V. Bronner                                                                                         */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/

FUNC(void, MOS_CODE) MOS_vidMainFunction
(
   HOD_tudtInstance udtInstance  /* !Comment: MOS instance identifier.        */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1      */
)
{
   uint8_least     u8LocalReactivationRemainDelay;


   if (MOS_audtDownCounter[udtInstance] > 0)
   {
      SchM_Enter_MOS_SdlDiagPreemptEna();
      MOS_audtDownCounter[udtInstance]--;
      SchM_Exit_MOS_SdlDiagPreemptEna();
   }

   if (MOS_abDiagnosisAuthorized[udtInstance] != FALSE)
   {
      u8LocalReactivationRemainDelay = MOS_au8ReactivationRemainDelay[udtInstance];

      /* !Comment: Reactivation section                                       */
      if (u8LocalReactivationRemainDelay != 0)
      {
         if (u8LocalReactivationRemainDelay != 1)
         {
            u8LocalReactivationRemainDelay--;
            /* !Comment: The new value of the counter is saved                */
            MOS_au8ReactivationRemainDelay[udtInstance] = (uint8)u8LocalReactivationRemainDelay;

            #if (HOD_coNOTIF_DURING_OVER_CURRENT == TRUE)
            /* !TraceTo: VEMS_R_07_01216_041.01                               */
            DGOHAL_vidWrite(MOS_akudtDgohalChannel[udtInstance],
                            DGOHAL_bfVALID_SUPPLY, DGOHAL_bfFAULT_SUPPLY);
            #endif /* if (HOD_coNOTIF_DURING_OVER_CURRENT == TRUE) */
         }
         else
         {
            SchM_Enter_MOS_SdlDiagPreemptEna();

            if (  (MOS_abDioLastCommand[udtInstance] == STD_ON)
               && (MOS_au8CmdAuthorized[udtInstance] == MOS_u8CMD_ENABLED) )
            {
               SchM_Enter_MOS_SdlDiagPreemptDis();
               Dio_WriteChannel(MOS_akudtDioMcalChannel[udtInstance], STD_HIGH);
               MOS_audtTransitionTime[udtInstance] = Gpt_GetTimeElapsed(MOS_udtTIMER);
               MOS_abDioCurrentState[udtInstance] = STD_HIGH;

               SchM_Exit_MOS_SdlDiagPreemptDis();

               MOS_audtDownCounter[udtInstance] =
                  MOS_akudtOvfProtectionValue[udtInstance];

               MOS_audtMaskTimeToApply[udtInstance] =
                  *(MOS_akpudtHighMaskTime[udtInstance]);

               MOS_abTransition[udtInstance]  = TRUE;
               MOS_au8ReactivationRemainDelay[udtInstance] = 0;

               SchM_Exit_MOS_SdlDiagPreemptEna();
            }
            else
            {
               SchM_Exit_MOS_SdlDiagPreemptEna();
               /* !Comment: When the command is cut off from a destructive    */
               /*           fault, a SCW failure is raised whatever the last  */
               /*           command is                                        */
               if ( (MOS_au8CmdAuthorized[udtInstance] & MOS_u8CMD_DISABLED_DESTRUCT_FLT)
                    == MOS_u8CMD_DISABLED_DESTRUCT_FLT)
               {
                  DGOHAL_vidWrite(MOS_akudtDgohalChannel[udtInstance],
                                  DGOHAL_bfVALID_SUPPLY, DGOHAL_bfFAULT_SUPPLY);
                  /* !Comment: The counter is rearmed with MOS_aku8ReactivationDelay[udtInstance] + 1 */
                  /*           to raise the failure as if the signal is restarted                     */
                  MOS_au8ReactivationRemainDelay[udtInstance] = MOS_aku8ReactivationDelay[udtInstance] + 1;
               }
               else
               {
                  MOS_au8ReactivationRemainDelay[udtInstance] = 0;
               }
            }
         }
      }

      /* !Comment: Periodic call to the Diag function                         */
      if (MOS_akbSchedDiag[udtInstance] != FALSE)
      {
         MOS_vidDioDiagByDigitalReadBack(udtInstance);
      }
   }
}



/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/* !FuncName    : MOS_vidDioDiagByDigitalReadBack                                                                     */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEMS_R_07_01216_002.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  V. Bronner                                                                                         */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/

FUNC(void, MOS_CODE) MOS_vidDioDiagByDigitalReadBack
(
   HOD_tudtInstance udtInstance  /* !Comment: MOS instance identifier.        */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1      */
)
{
   Dio_ChannelType    udtLocalDioMcalChannel;
   Dio_ChannelType    udtLocalDioForDiagMcalChannel;
   Gpt_ValueType      udtLocalTime;
   Gpt_ValueType     *pudtLocalTransitionTime;
   Gpt_ValueType     *pudtLocalMaskTimeToApply;
   DGOHAL_tudtChannel udtLocalDgohalChannel;
   Dio_LevelType      udtLocalLastCommand;
   uint8_least        u8LocalIndex;
   boolean            bLocalDiagAuthorized;
   boolean           *pbLocalTransition;
   boolean            bLocalDiagInhibited;


   /* !Comment: Local pointer variables for optimisation of the access        */
   /*           time of the array during the atomic section                   */
   udtLocalDioMcalChannel        = MOS_akudtDioMcalChannel[udtInstance];
   udtLocalDioForDiagMcalChannel = MOS_akudtDioForDiagMcalChannel[udtInstance];
   u8LocalIndex                  = MOS_u8SAMPLES;
   bLocalDiagAuthorized          = TRUE;
   pbLocalTransition             = &MOS_abTransition[udtInstance];
   pudtLocalTransitionTime       = &MOS_audtTransitionTime[udtInstance];
   pudtLocalMaskTimeToApply      = &MOS_audtMaskTimeToApply[udtInstance];

   /* !Comment: This atomic section contains all the reading of the needed    */
   /*           variables of this function. Once they are read, we can do     */
   /*           the appropriate treatment of these variables. The while loop  */
   /*           which update u8LocalIndex is used to detect if an error is    */
   /*           present or not. A complete explanation is made below.         */
   /*           This section contains also the update of the local variable   */
   /*           penuLocalTransition because this variable is read and write   */
   /*           in this section.                                              */
   SchM_Enter_MOS_DiagPreemptEna();

   udtLocalTime        = Gpt_GetTimeElapsed(MOS_udtTIMER);
   udtLocalLastCommand = Dio_ReadChannel(udtLocalDioMcalChannel);

   /* !Comment: u8LocalIndex is tested first in order to optimize the number  */
   /*           of call to Dio_ReadChannel in case of faults detected. The    */
   /*           test will exit at the end of the evaluation of the first      */
   /*           expression, beginning by the left one (Norm C: ISO 9899:1990) */
   /* !Deviation: Violation of MISRA Rule 12.4. Reason : Dio_ReadChannel has  */
   /*             no side effects.                                            */
   while (  (u8LocalIndex > 0)
         && (Dio_ReadChannel(udtLocalDioForDiagMcalChannel) == udtLocalLastCommand) )
   {
      u8LocalIndex--;
   }

   /* !Comment: The following statements are the treatment of the data        */
   /*           previously read.                                              */
   if (*pbLocalTransition == TRUE)
   {
      /* !Comment: MOS_audtDownCounter is not used for HOD_INSTANCE with      */
      /*           scheduled diagnosis and is set by default to 0. So, in     */
      /*           order to manage mask time for these instances, a test of   */
      /*           MOS_akbSchedDiag is done in parallel of the one on         */
      /*           MOS_audtDownCounter value.                                 */
      if (  (MOS_audtDownCounter[udtInstance] > 0)
         || (MOS_akbSchedDiag[udtInstance] == TRUE) )
      {
         if ( (udtLocalTime - *pudtLocalTransitionTime)
              < *pudtLocalMaskTimeToApply)
         {
            bLocalDiagAuthorized = FALSE;
         }
         else
         {
            *pbLocalTransition = FALSE;
         }
      }
   }

   SchM_Exit_MOS_DiagPreemptEna();

   if (bLocalDiagAuthorized != FALSE)
   {
      /* !Comment: u8LocalIndex == 0 means that a fault is present: The while */
      /*           loop decrease the index u8LocalIndex only if the state of  */
      /*           Diag input indicates an error (which means that its state  */
      /*           is the same than the output state). So when u8LocalIndex   */
      /*           is equal to 0, 3 errors have been detected (for the HF     */
      /*           filter) so an error is present.                            */
      udtLocalDgohalChannel = MOS_akudtDgohalChannel[udtInstance];
      if (u8LocalIndex == 0)
      {
         if (udtLocalLastCommand == STD_LOW)
         {
            #if (MOS_coINHIB_SCG_DIAG_MNGT != MOS_coNULL)
               MOS_vidSCG_DIAG_INHIBITION(udtInstance, bLocalDiagInhibited);
            #else
               bLocalDiagInhibited = FALSE;
            #endif /* if (MOS_coINHIB_SCG_DIAG_MNGT != MOS_coNULL) */
            if (bLocalDiagInhibited == FALSE)
            {
               /* !TraceTo: VEMS_R_07_01216_003.01                            */
               DGOHAL_vidWrite(udtLocalDgohalChannel,
                               DGOHAL_bfVALID_OPEN | DGOHAL_bfVALID_GROUND,
                               DGOHAL_bfFAULT_OPEN | DGOHAL_bfFAULT_GROUND);
            }
         }
         else
         {
            MOS_vidShortCircuitProtection(udtInstance);
            DGOHAL_vidWrite(udtLocalDgohalChannel,
                            DGOHAL_bfVALID_SUPPLY, DGOHAL_bfFAULT_SUPPLY);
         }
      }
      else
      {
         if (udtLocalLastCommand == STD_LOW)
         {
            /* !TraceTo: VEMS_R_07_01216_003.01                               */
            DGOHAL_vidWrite(udtLocalDgohalChannel,
                            DGOHAL_bfVALID_OPEN | DGOHAL_bfVALID_GROUND,
                            DGOHAL_bfNO_FAULT_OPEN | DGOHAL_bfNO_FAULT_GROUND);
         }
         else
         {
            MOS_au8ShortCircuitCounter[udtInstance] = 0;

            DGOHAL_vidWrite(udtLocalDgohalChannel,
                            DGOHAL_bfVALID_SUPPLY, DGOHAL_bfNO_FAULT_SUPPLY);
         }
      }
   }
}



/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/* !FuncName    : MOS_vidShortCircuitProtection                                                                       */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEMS_R_07_01216_001.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  V. Bronner                                                                                         */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/

FUNC(void, MOS_CODE) MOS_vidShortCircuitProtection
(
   HOD_tudtInstance udtInstance  /* !Comment: MOS instance identifier.        */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1      */
)
{
   uint8_least u8LocalShortCircuitCounter;


   u8LocalShortCircuitCounter = MOS_au8ShortCircuitCounter[udtInstance];

   if (u8LocalShortCircuitCounter == 0)
   {
      u8LocalShortCircuitCounter =
         MOS_aku8ShortCircuitDetectionNb[udtInstance];
   }
   else
   {
      u8LocalShortCircuitCounter--;
   }

   if (u8LocalShortCircuitCounter == 0)
   {
      if (MOS_bDiagOnEdgeRunning == FALSE)
      {
         MOS_au8ReactivationRemainDelay[udtInstance] =
            MOS_aku8ReactivationDelay[udtInstance];
      }
      else
      {
         MOS_au8ReactivationRemainDelay[udtInstance] =
            (uint8)(MOS_aku8ReactivationDelay[udtInstance] + 1);
      }
      Dio_WriteChannel(MOS_akudtDioMcalChannel[udtInstance], STD_LOW);
      MOS_abDioCurrentState[udtInstance] = STD_LOW;
   }
   MOS_au8ShortCircuitCounter[udtInstance] = (uint8)u8LocalShortCircuitCounter;
}


#define MOS_STOP_SEC_CODE
#include "MOS_MemMap.h"


/*-------------------------------- end of file -------------------------------*/

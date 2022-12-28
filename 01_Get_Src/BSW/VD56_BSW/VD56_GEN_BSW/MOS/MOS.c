/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : MOS                                                                                             */
/* !Description     : Drive and Diag HW MOS component commanded through DIO                                           */
/*                                                                                                                    */
/* !File            : MOS.c                                                                                           */
/* !Description     : API for Diagnosis functions of the Component                                                    */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5012137 01                                                                              */
/* !Reference       : PTS_DOC_5199248 01                                                                              */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:MOS API C-99055673X1544X31.A-SRC;1.10 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/


#include "Std_Types.h"
#include "MOS_TYPES.h"
#include "MOS.h"
#include "MOS_Private.h"
#include "MOS_Cfg.h"
#include "Dio.h"
#include "Gpt.h"
#include "SWFAIL.h"


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define MOS_START_SEC_CODE
#include "MOS_MemMap.h"



/**********************************************************************************************************************/
/* !FuncName    : MOS_vidInit                                                                                         */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEMS_R_07_01216_006.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  M.ElShamaa                                                                                         */
/**********************************************************************************************************************/

FUNC(void, MOS_CODE) MOS_vidInit(void)
{
   HOD_tudtInstance udtLocalInstance;


   MOS_bDiagOnEdgeRunning = FALSE;


   for (udtLocalInstance = 0;
        udtLocalInstance < MOS_udtINSTANCE_NB;
        udtLocalInstance++)
   {
      /* !Trace_To: VEMS_R_07_01216_046.01                                    */
      MOS_au8ReactivationRemainDelay[udtLocalInstance] = 0;
      MOS_au8ShortCircuitCounter[udtLocalInstance]     = 0;
      MOS_abDiagnosisAuthorized[udtLocalInstance]      = FALSE;

      /* !Trace_To: VEMS_R_07_01216_009.01                                    */
      MOS_aenuCurrentMode[udtLocalInstance] =
         MOS_akenuDefaultMode[udtLocalInstance];

      /* !Trace_To: VEMS_R_07_01216_047.01                                    */
      MOS_au8CmdAuthorized[udtLocalInstance] = MOS_u8CMD_DISABLED_WITHOUT_FLT;

      /* !Trace_To: VEMS_R_07_01216_007.01                                    */
      Dio_WriteChannel(MOS_akudtDioMcalChannel[udtLocalInstance], STD_LOW);
      MOS_abDioCurrentState[udtLocalInstance] = STD_LOW;

      MOS_audtDownCounter[udtLocalInstance] =
         MOS_akudtOvfProtectionValue[udtLocalInstance];
      MOS_audtTransitionTime[udtLocalInstance] =
         Gpt_GetTimeElapsed(MOS_udtTIMER);
      MOS_audtMaskTimeToApply[udtLocalInstance] =
         *(MOS_akpudtLowMaskTime[udtLocalInstance]);
      MOS_abTransition[udtLocalInstance] = TRUE;
   }
}



/**********************************************************************************************************************/
/* !FuncName    : MOS_vidEnableDiag                                                                                   */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEMS_R_07_01216_011.02                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  O. Roisin                                                                                          */
/**********************************************************************************************************************/

FUNC(void, MOS_CODE) MOS_vidEnableDiag
(
   HOD_tudtInstance udtInstance  /* !Comment: MOS instance identifier.        */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1      */
)
{
   if (udtInstance < MOS_udtINSTANCE_NB)
   {
      MOS_abDiagnosisAuthorized[udtInstance] = TRUE;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}



/**********************************************************************************************************************/
/* !FuncName    : MOS_vidDisableDiag                                                                                  */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEMS_R_07_01216_013.02                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  O. Roisin                                                                                          */
/**********************************************************************************************************************/

FUNC(void, MOS_CODE) MOS_vidDisableDiag
(
   HOD_tudtInstance udtInstance  /* !Comment: MOS instance identifier.        */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1      */
)
{
   if (udtInstance < MOS_udtINSTANCE_NB)
   {
      MOS_au8ReactivationRemainDelay[udtInstance] = 0;
      MOS_au8ShortCircuitCounter[udtInstance]     = 0;
      MOS_abDiagnosisAuthorized[udtInstance]      = FALSE;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}



/**********************************************************************************************************************/
/* !FuncName    : MOS_vidSetMode                                                                                      */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEMS_R_07_01216_016.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  O. Roisin                                                                                          */
/**********************************************************************************************************************/

FUNC(void, MOS_CODE) MOS_vidSetMode
(
   HOD_tudtInstance udtInstance, /* !Comment: MOS instance identifier.        */
                                 /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1      */
   HOD_tudtChannel  udtChannel,  /* !Comment: MOS channel identifier of the   */
                                 /*           udtInstance                     */
                                 /* !Range  : 0 .. HOD_u8CHANNEL_NB - 1       */
                                 /* !Deviation: Violation of QAC_3206 rule.   */
                                 /*  Reason : udtChannel is always equal to 1 */
                                 /*  in MOS component.                        */
   HOD_tenuMode     enuMode      /* !Comment: Mode available                  */
                                 /* !Range  : List of the enum mode           */
)
{
   MOS_tbfMode bfLocalMode;


   if (udtInstance < MOS_udtINSTANCE_NB)
   {
      switch (enuMode)
      {
         case HOD_MODE_DIO:
            bfLocalMode = MOS_bfMODE_DIO;
            break;

         case HOD_MODE_PWM:
            bfLocalMode = MOS_bfMODE_PWM;
            break;

         case HOD_MODE_CDD:
            bfLocalMode = MOS_bfMODE_CDD;
            break;

         default:
            bfLocalMode = MOS_bfMODE_DIO;
            SWFAIL_vidSoftwareErrorHook();
            break;
      }

      if (  ( ( (MOS_akbfModeAvailable[udtInstance]) & bfLocalMode) != FALSE)
         && ( (MOS_akbSwitchModeAvailable[udtInstance]) != FALSE) )
      {
         MOS_aenuCurrentMode[udtInstance] = enuMode;
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}



/**********************************************************************************************************************/
/* !FuncName    : MOS_vidEnableCmd                                                                                    */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEMS_R_07_01216_043.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  O. Roisin                                                                                          */
/**********************************************************************************************************************/

FUNC(void, MOS_CODE) MOS_vidEnableCmd
(
   HOD_tudtInstance udtInstance,  /* !Comment: MOS instance identifier.        */
                                  /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1      */
   HOD_tenuCutMode  enuCutMode    /* !Comment: Mode available                  */
                                  /* !Range  : List of the enum mode           */
)
{
   if (udtInstance < MOS_udtINSTANCE_NB)
   {
      switch (enuCutMode)
      {
         case HOD_CUT_OFF_WITHOUT_FAULT:
            MOS_au8CmdAuthorized[udtInstance] = (uint8)( MOS_au8CmdAuthorized[udtInstance]
                                                       & (~MOS_u8CMD_DISABLED_WITHOUT_FLT) );
            break;

         case HOD_CUT_OFF_WITH_DESTRUCTIVE_FAULT:
            MOS_au8CmdAuthorized[udtInstance] = (uint8)( MOS_au8CmdAuthorized[udtInstance]
                                                       & (~MOS_u8CMD_DISABLED_DESTRUCT_FLT) );
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}



/**********************************************************************************************************************/
/* !FuncName    : MOS_vidDisableCmd                                                                                   */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/* !Trace_To    : VEMS_R_07_01216_044.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  V. Bronner                                                                                         */
/**********************************************************************************************************************/

FUNC(void, MOS_CODE) MOS_vidDisableCmd
(
   HOD_tudtInstance udtInstance,  /* !Comment: MOS instance identifier.        */
                                  /* !Range  : 0 .. HOD_u8INSTANCE_NB - 1      */
   HOD_tenuCutMode  enuCutMode    /* !Comment: Mode available                  */
                                  /* !Range  : List of the enum mode           */
)
{
   if (udtInstance < MOS_udtINSTANCE_NB)
   {
      switch (enuCutMode)
      {
         case HOD_CUT_OFF_WITHOUT_FAULT:
            MOS_au8CmdAuthorized[udtInstance] = (uint8)( MOS_au8CmdAuthorized[udtInstance]
                                                       | MOS_u8CMD_DISABLED_WITHOUT_FLT);
            break;

         case HOD_CUT_OFF_WITH_DESTRUCTIVE_FAULT:
            MOS_au8CmdAuthorized[udtInstance] = (uint8)( MOS_au8CmdAuthorized[udtInstance]
                                                       | MOS_u8CMD_DISABLED_DESTRUCT_FLT);
            if (MOS_au8ReactivationRemainDelay[udtInstance] == 0)
            {
               MOS_au8ReactivationRemainDelay[udtInstance] = (uint8)(MOS_aku8ReactivationDelay[udtInstance] + 1);
            }
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
      /* !Trace_To    : VEMS_R_07_01216_045.01                                                                        */
      Dio_WriteChannel(MOS_akudtDioMcalChannel[udtInstance], STD_LOW);
      MOS_abDioCurrentState[udtInstance] = STD_LOW;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}


#define MOS_STOP_SEC_CODE
#include "MOS_MemMap.h"


/*-------------------------------- end of file -------------------------------*/

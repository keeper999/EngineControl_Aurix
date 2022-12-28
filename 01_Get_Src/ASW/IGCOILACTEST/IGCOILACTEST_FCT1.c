/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCOILACTEST                                            */
/* !Description     : IGCOILACTEST Component                                  */
/*                                                                            */
/* !Module          : IGCOILACTEST                                            */
/* !Description     :  TESTS ACTIONNEURS DES BOBINES                          */
/*                                                                            */
/* !File            : IGCOILACTEST_FCT1.C                                     */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / IGCOILACTEST_vidInitOutput                                           */
/*   2 / IGCOILACTEST_vidIgnTime                                              */
/*   3 / IGCOILACTEST_vidEntryMode                                            */
/*   4 / IGCOILACTEST_vidTestMode                                             */
/*   5 / IGCOILACTEST_vidTestRealisation                                      */
/*   6 / IGCOILACTEST_vidTestEnd                                              */
/*   7 / IGCOILACTEST_vidCoilEntryMode                                        */
/*   8 / IGCOILACTEST_vidCoilTestMode                                         */
/*   9 / IGCOILACTEST_vidCoilTestEnd                                          */
/*                                                                            */
/* !Reference   : V02 NT 09 00741 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/IGCOILACTEST/IGCOILACTEST_FCT1.C_v$*/
/* $Revision::   1.4      $$Author::   vgarnier       $$Date::   01 Jun 2010 $*/
/* $Author::   vgarnier                               $$Date::   01 Jun 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IGCOILACTEST.h"
#include "IGCOILACTEST_L.h"
#include "IGCOILACTEST_IM.h"
#include "IGNHAL.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILACTEST_vidInitOutput                                 */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st84 IgCmd_stActrTst;                                              */
/*  output uint8 IGCOILACTEST_u8IgCmdActrTstPrev;                             */
/*  output boolean IgCmd_bCoilTstCmpl;                                        */
/*  output boolean IgCmd_bPwrRlyCmd;                                          */
/*  output uint16 ActrTstCoil_TempoIdle;                                      */
/*  output uint8 IGCOILACTEST_u8CodeTestActPrev;                              */
/*  output boolean IgCmd_bCoil1TstCmpl;                                       */
/*  output boolean IgCmd_bCoil2TstCmpl;                                       */
/*  output boolean IgCmd_bCoil3TstCmpl;                                       */
/*  output boolean IgCmd_bCoil4TstCmpl;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILACTEST_vidInitOutput(void)
{
   /* State machine initialization */
   IgCmd_stActrTst = IGCMD_ACTRTEST_IDLE;
   IGCOILACTEST_u8IgCmdActrTstPrev = IGCMD_ACTRTEST_IDLE;
   IgCmd_bCoilTstCmpl = 0;
   VEMS_vidSET(IgCmd_bPwrRlyCmd, 0);
   ActrTstCoil_TempoIdle = 0;
   IGCOILACTEST_u8CodeTestActPrev = CODE_TEST_BOBINE_1;
   /* Outputs initialization */
   VEMS_vidSET(IgCmd_bCoil1TstCmpl, 0);
   VEMS_vidSET(IgCmd_bCoil2TstCmpl, 0);
   VEMS_vidSET(IgCmd_bCoil3TstCmpl, 0);
   VEMS_vidSET(IgCmd_bCoil4TstCmpl, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILACTEST_vidIgnTime                                    */
/* !Description :  calcul le temps de commande de bobine à envoyer au LdB     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_09_00741_001.01                                     */
/*                 VEMS_R_09_00741_002.01                                     */
/*                 VEMS_R_09_00741_003.01                                     */
/*                 VEMS_R_09_00741_004.01                                     */
/*                 VEMS_R_09_00741_005.01                                     */
/*                 VEMS_R_09_00741_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input st84 IgCmd_stActrTst;                                               */
/*  input uint16 ActrTstCoil_TempoIdle;                                       */
/*  input uint16 ActrTstCoil_TotTime;                                         */
/*  input uint8 ActrTstCoil_OnTime;                                           */
/*  input uint8 IGCOILACTEST_u8CodeTestActPrev;                               */
/*  input uint16 ActrTstCoil_CumulTime;                                       */
/*  input uint8 ActrTstCoil_CmdTime;                                          */
/*  input uint16 ActrTstCoil_OffTime;                                         */
/*  input uint16 ActrTstCoil_IntTime;                                         */
/*  input uint16 ActrTstCoil_TempoIdle_C;                                     */
/*  input boolean IgCmd_bCoilTstCmpl;                                         */
/*  output st84 IgCmd_stActrTst;                                              */
/*  output boolean IgCmd_bPwrRlyCmd;                                          */
/*  output boolean IgCmd_bCoilTstCmpl;                                        */
/*  output uint16 ActrTstCoil_TempoIdle;                                      */
/*  output uint16 ActrTstCoil_CumulTime;                                      */
/*  output uint8 ActrTstCoil_CmdTime;                                         */
/*  output uint16 ActrTstCoil_IntTime;                                        */
/*  output boolean IgCmd_bCoil1TstCmpl;                                       */
/*  output boolean IgCmd_bCoil2TstCmpl;                                       */
/*  output boolean IgCmd_bCoil3TstCmpl;                                       */
/*  output boolean IgCmd_bCoil4TstCmpl;                                       */
/*  output uint8 IGCOILACTEST_u8CodeTestActPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILACTEST_vidIgnTime(void)
{
   boolean bLocalSrv_bActrTstEna;
   boolean bLocalTestEna;
   uint8   u8LocalCode_test_action;
   uint16  u16LocalCumulTime;
   uint16  u16LocalIntTime;
   uint16  u16LocalTempoIdle;
   sint32  s32LocalIntTime;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);

   if (  (bLocalSrv_bActrTstEna != 0)
      && (  (u8LocalCode_test_action == CODE_TEST_BOBINE_1)
         || (u8LocalCode_test_action == CODE_TEST_BOBINE_2)
         || (u8LocalCode_test_action == CODE_TEST_BOBINE_3)
         || (u8LocalCode_test_action == CODE_TEST_BOBINE_4)))
   {
      bLocalTestEna = 1;
   }
   else
   {
      bLocalTestEna = 0;
   }

   switch (IgCmd_stActrTst)
   {
      case IGCMD_ACTRTEST_IDLE:
         if (  (bLocalTestEna != 0)
            && (ActrTstCoil_TempoIdle == 0))
         {
            IgCmd_stActrTst = IGCMD_ACTRTEST_START;
            VEMS_vidSET(IgCmd_bPwrRlyCmd, 1);
            IgCmd_bCoilTstCmpl = 0;
         }
         else
         {
            /* during state IGCMD_ACTRTEST_IDLE */
            if (ActrTstCoil_TempoIdle > 0)
            {
               u16LocalTempoIdle = (uint16)(ActrTstCoil_TempoIdle - 1);
               ActrTstCoil_TempoIdle = (uint16)MATHSRV_udtMIN(u16LocalTempoIdle,
                                                              5000);
            }
         }
         break;

      case IGCMD_ACTRTEST_START:
         if (bLocalTestEna != 0)
         {
            ActrTstCoil_CumulTime = (uint16)MATHSRV_udtMIN(ActrTstCoil_TotTime,
                                                           5000);
            VEMS_vidSET(IgCmd_bPwrRlyCmd, 1);
            IgCmd_bCoilTstCmpl = 0;
            IgCmd_stActrTst = IGCMD_ACTRTEST_ON;
            ActrTstCoil_CmdTime = ActrTstCoil_OnTime;
         }
         break;

      case IGCMD_ACTRTEST_ON:
         if (  (bLocalTestEna == 0)
            || (u8LocalCode_test_action != IGCOILACTEST_u8CodeTestActPrev))
         {
            IgCmd_stActrTst = IGCMD_ACTRTEST_STOP;
            VEMS_vidSET(IgCmd_bPwrRlyCmd, 1);
            IgCmd_bCoilTstCmpl = 0;
            ActrTstCoil_CmdTime = 0;
         }
         else
         {
            if (ActrTstCoil_CumulTime <= 1)
            {
               IgCmd_stActrTst = IGCMD_ACTRTEST_LDB_RECONF;
               VEMS_vidSET(IgCmd_bPwrRlyCmd, 1);
               IgCmd_bCoilTstCmpl = 0;
            }
            else
            {
               if (ActrTstCoil_CmdTime <= IgCmd_SampleTiFast_SC)
               {
                  IgCmd_stActrTst = IGCMD_ACTRTEST_OFF;
                  s32LocalIntTime = ( ( (sint32)( ActrTstCoil_CmdTime
                                                + ActrTstCoil_OffTime)
                                      - (sint32)IgCmd_SampleTiFast_SC));
                  ActrTstCoil_IntTime =
                     (uint16)MATHSRV_udtCLAMP(s32LocalIntTime, 0, 50000);
                  ActrTstCoil_CmdTime = 0;
               }
               else
               {
                  ActrTstCoil_CmdTime = (uint8)( ActrTstCoil_CmdTime
                                               - IgCmd_SampleTiFast_SC);
               }
               u16LocalCumulTime = (uint16)(ActrTstCoil_CumulTime - 1);
               ActrTstCoil_CumulTime = (uint16)MATHSRV_udtMIN(u16LocalCumulTime,
                                                              5000);
            }
         }
         break;

      case IGCMD_ACTRTEST_OFF:
         if (  (bLocalTestEna == 0)
            || (u8LocalCode_test_action != IGCOILACTEST_u8CodeTestActPrev))
         {
            IgCmd_stActrTst = IGCMD_ACTRTEST_STOP;
            VEMS_vidSET(IgCmd_bPwrRlyCmd, 1);
            IgCmd_bCoilTstCmpl = 0;
            ActrTstCoil_CmdTime = 0;
         }
         else
         {
            if (ActrTstCoil_CumulTime <= 1)
            {
               IgCmd_stActrTst = IGCMD_ACTRTEST_LDB_RECONF;
               VEMS_vidSET(IgCmd_bPwrRlyCmd, 1);
               IgCmd_bCoilTstCmpl = 0;
            }
            else
            {
               if (ActrTstCoil_IntTime <= (uint16)IgCmd_SampleTiFast_SC)
               {
                  IgCmd_stActrTst = IGCMD_ACTRTEST_ON;
                  ActrTstCoil_CmdTime = ActrTstCoil_OnTime;
               }
               else
               {
                  u16LocalIntTime = (uint16)( ActrTstCoil_IntTime
                                            - (uint16)IgCmd_SampleTiFast_SC);
                  ActrTstCoil_IntTime = (uint16)MATHSRV_udtMIN(u16LocalIntTime,
                                                               50000);
               }
               u16LocalCumulTime = (uint16)(ActrTstCoil_CumulTime - 1);
               ActrTstCoil_CumulTime = (uint16)MATHSRV_udtMIN(u16LocalCumulTime,
                                                              5000);
            }
         }
         break;

      case IGCMD_ACTRTEST_STOP:
         ActrTstCoil_TempoIdle =
            (uint16)MATHSRV_udtMIN(ActrTstCoil_TempoIdle_C, 5000);
         IgCmd_stActrTst = IGCMD_ACTRTEST_IDLE;
         VEMS_vidSET(IgCmd_bPwrRlyCmd, 0);
         IgCmd_bCoilTstCmpl = 0;
         break;

      case IGCMD_ACTRTEST_END:
         if (bLocalTestEna != 0)
         {
            ActrTstCoil_TempoIdle =
               (uint16)MATHSRV_udtMIN(ActrTstCoil_TempoIdle_C, 5000);
            IgCmd_stActrTst = IGCMD_ACTRTEST_IDLE;
            VEMS_vidSET(IgCmd_bPwrRlyCmd, 0);
            IgCmd_bCoilTstCmpl = 0;
         }
         break;

      case IGCMD_ACTRTEST_LDB_RECONF:
         IgCmd_stActrTst = IGCMD_ACTRTEST_END;
         VEMS_vidSET(IgCmd_bPwrRlyCmd, 0);
         IgCmd_bCoilTstCmpl = 1;
         ActrTstCoil_CmdTime = 0;
         break;

      default:
         IgCmd_stActrTst = IGCMD_ACTRTEST_IDLE;
         VEMS_vidSET(IgCmd_bPwrRlyCmd, 0);
         IgCmd_bCoilTstCmpl = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   if (IgCmd_bCoilTstCmpl != 0)
   {
      if (u8LocalCode_test_action == CODE_TEST_BOBINE_1)
      {
         VEMS_vidSET(IgCmd_bCoil1TstCmpl, 1);
         VEMS_vidSET(IgCmd_bCoil2TstCmpl, 0);
         VEMS_vidSET(IgCmd_bCoil3TstCmpl, 0);
         VEMS_vidSET(IgCmd_bCoil4TstCmpl, 0);
      }
      else
      {
         if (u8LocalCode_test_action == CODE_TEST_BOBINE_2)
         {
            VEMS_vidSET(IgCmd_bCoil1TstCmpl, 0);
            VEMS_vidSET(IgCmd_bCoil2TstCmpl, 1);
            VEMS_vidSET(IgCmd_bCoil3TstCmpl, 0);
            VEMS_vidSET(IgCmd_bCoil4TstCmpl, 0);
         }
         else
         {
            if (u8LocalCode_test_action == CODE_TEST_BOBINE_3)
            {
               VEMS_vidSET(IgCmd_bCoil1TstCmpl, 0);
               VEMS_vidSET(IgCmd_bCoil2TstCmpl, 0);
               VEMS_vidSET(IgCmd_bCoil3TstCmpl, 1);
               VEMS_vidSET(IgCmd_bCoil4TstCmpl, 0);
            }
            else
            {
               if (u8LocalCode_test_action == CODE_TEST_BOBINE_4)
               {
                  VEMS_vidSET(IgCmd_bCoil1TstCmpl, 0);
                  VEMS_vidSET(IgCmd_bCoil2TstCmpl, 0);
                  VEMS_vidSET(IgCmd_bCoil3TstCmpl, 0);
                  VEMS_vidSET(IgCmd_bCoil4TstCmpl, 1);
               }
               else
               {
                  VEMS_vidSET(IgCmd_bCoil1TstCmpl, 0);
                  VEMS_vidSET(IgCmd_bCoil2TstCmpl, 0);
                  VEMS_vidSET(IgCmd_bCoil3TstCmpl, 0);
                  VEMS_vidSET(IgCmd_bCoil4TstCmpl, 0);
               }
            }
         }
      }
   }
   else
   {
      VEMS_vidSET(IgCmd_bCoil1TstCmpl, 0);
      VEMS_vidSET(IgCmd_bCoil2TstCmpl, 0);
      VEMS_vidSET(IgCmd_bCoil3TstCmpl, 0);
      VEMS_vidSET(IgCmd_bCoil4TstCmpl, 0);
   }

   IGCOILACTEST_u8CodeTestActPrev = u8LocalCode_test_action;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILACTEST_vidEntryMode                                  */
/* !Description :  informer le LdB qu’un test actionneur va s’exécuter        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGCOILACTEST_vidCoilEntryMode();                         */
/*  input uint8 Code_test_action;                                             */
/*  input st84 IgCmd_stActrTst;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILACTEST_vidEntryMode(void)
{
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);

   if (  (  (u8LocalCode_test_action == CODE_TEST_BOBINE_1)
         || (u8LocalCode_test_action == CODE_TEST_BOBINE_2)
         || (u8LocalCode_test_action == CODE_TEST_BOBINE_3)
         || (u8LocalCode_test_action == CODE_TEST_BOBINE_4))
      && (IgCmd_stActrTst == IGCMD_ACTRTEST_START))
   {
      IGCOILACTEST_vidCoilEntryMode();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILACTEST_vidTestMode                                   */
/* !Description :  fonction de test si l'envoi au LdB de temps du test        */
/*                 s'effectue ou pas.                                         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILACTEST_vidTestRealisation();                       */
/*  input uint8 ICD_current_mode;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILACTEST_vidTestMode(void)
{
   if (ICD_current_mode == IGN_HAL_MODE_TEST)
   {
      IGCOILACTEST_vidTestRealisation();
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILACTEST_vidTestRealisation                            */
/* !Description :  Envoi au LdB le temps du test                              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGCOILACTEST_vidCoilTestMode();                          */
/*  input uint8 Code_test_action;                                             */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input st84 IgCmd_stActrTst;                                               */
/*  input uint8 IGCOILACTEST_u8IgCmdActrTstPrev;                              */
/*  output uint8 IgCmd_CurTestCoil;                                           */
/*  output uint8 IGCOILACTEST_u8IgCmdActrTstPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILACTEST_vidTestRealisation(void)
{
   uint8   u8LocalCode_test_action;
   uint8   u8LocalExt_noCylEng;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);

   if (u8LocalCode_test_action == CODE_TEST_BOBINE_1)
   {
      IgCmd_CurTestCoil = IGN_COIL_CYLINDER_1;
   }
   else
   {
      if (u8LocalCode_test_action == CODE_TEST_BOBINE_2)
      {
         IgCmd_CurTestCoil = IGN_COIL_CYLINDER_2;
      }
      else
      {
         if (u8LocalCode_test_action == CODE_TEST_BOBINE_3)
         {
            IgCmd_CurTestCoil = IGN_COIL_CYLINDER_3;
         }
         else
         {
            IgCmd_CurTestCoil = IGN_COIL_CYLINDER_4;
         }
      }
   }

   if (  (u8LocalCode_test_action == CODE_TEST_BOBINE_1)
      || (u8LocalCode_test_action == CODE_TEST_BOBINE_2)
      || (u8LocalCode_test_action == CODE_TEST_BOBINE_3)
      || (  (u8LocalCode_test_action == CODE_TEST_BOBINE_4)
         && (u8LocalExt_noCylEng == 4)))
   {
      if (  (IgCmd_stActrTst == IGCMD_ACTRTEST_ON)
         && (IGCOILACTEST_u8IgCmdActrTstPrev != IGCMD_ACTRTEST_ON))
      {
         IGCOILACTEST_vidCoilTestMode();
      }
   }
   IGCOILACTEST_u8IgCmdActrTstPrev = IgCmd_stActrTst;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILACTEST_vidTestEnd                                    */
/* !Description :  Le LdB doit se remettre en configuration synchrone à la fin*/
/*                 du test.                                                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGCOILACTEST_vidCoilTestEnd();                           */
/*  input uint8 Code_test_action;                                             */
/*  input st84 IgCmd_stActrTst;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILACTEST_vidTestEnd(void)
{
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);

   if (  (  (u8LocalCode_test_action == CODE_TEST_BOBINE_1)
         || (u8LocalCode_test_action == CODE_TEST_BOBINE_2)
         || (u8LocalCode_test_action == CODE_TEST_BOBINE_3)
         || (u8LocalCode_test_action == CODE_TEST_BOBINE_4))
      && (  (IgCmd_stActrTst == IGCMD_ACTRTEST_STOP)
         || (IgCmd_stActrTst == IGCMD_ACTRTEST_LDB_RECONF)))
   {
      IGCOILACTEST_vidCoilTestEnd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILACTEST_vidCoilEntryMode                              */
/* !Description :  Exécution du test actionneur                               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IgnHALWriteMode(argin uint8 u8Mode)uint8;                */
/*  output uint8 ICD_current_mode;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILACTEST_vidCoilEntryMode(void)
{
   ICD_current_mode = IgnHALWriteMode(IGN_HAL_MODE_TEST);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILACTEST_vidCoilTestMode                               */
/* !Description :  Envoi de la consigne de temps d’activation des bobines au  */
/*                 LDB si un des tests actionneur bobine est demandé.         */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IgnHALWriteTestTime(argin uint8 u8Channel, argin uint32  */
/*  u32TestTime);                                                             */
/*  input uint8 ActrTstCoil_CmdTime;                                          */
/*  input uint8 IgCmd_CurTestCoil;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILACTEST_vidCoilTestMode(void)
{
   uint32 u32LocalCmdTime;


   u32LocalCmdTime = (uint32)((ActrTstCoil_CmdTime * 625) / 2);
   IgnHALWriteTestTime(IgCmd_CurTestCoil, u32LocalCmdTime);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILACTEST_vidCoilTestEnd                                */
/* !Description :  Fin du test actionneur                                     */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IgnHALWriteMode(argin uint8 u8Mode)uint8;                */
/*  output uint8 ICD_current_mode;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILACTEST_vidCoilTestEnd(void)
{
   ICD_current_mode = IgnHALWriteMode(IGN_HAL_MODE_FIXED);
}

/*------------------------------- end of file --------------------------------*/
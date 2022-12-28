/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRACTEST                                               */
/* !Description     : THRACTEST component.                                    */
/*                                                                            */
/* !Module          : THRACTEST                                               */
/* !Description     : TEST ACTIONNEUR PAPILLON MOTORISÉ.                      */
/*                                                                            */
/* !File            : THRACTEST_FCT1.C                                        */
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
/*   1 / THRACTEST_vidInitOutput                                              */
/*   2 / THRACTEST_vidThrTstSpChart                                           */
/*   3 / THRACTEST_vidDynTstSpeed                                             */
/*   4 / THRACTEST_vidDynTstEna                                               */
/*   5 / THRACTEST_vidDynTst                                                  */
/*   6 / THRACTEST_vidDynTstResInit                                           */
/*   7 / THRACTEST_vidInitDynTst                                              */
/*   8 / THRACTEST_vidDynTstResClcn                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 00783 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/REF/MODULES/THR/THRACTEST/THRACTEST_FCT1.C_v$*/
/* $Revision::   1.1      $$Author::   alaouni        $$Date::   06 Oct 2011 $*/
/* $Author::   alaouni                                $$Date::   06 Oct 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRACTEST.h"
#include "THRACTEST_L.h"
#include "THRACTEST_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidInitOutput                                    */
/* !Description :  Initialisation des sorties et des tests actionneurs.       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st87 Thr_stActrTst;                                                */
/*  output st88 Thr_stDynTst;                                                 */
/*  output st89 Thr_stGapTst;                                                 */
/*  output boolean Thr_bDynActrTst;                                           */
/*  output boolean Thr_bGapActrTst;                                           */
/*  output boolean Thr_bThrTstCmpl;                                           */
/*  output boolean Thr_bTstInProgs;                                           */
/*  output uint16 Thr_rSpPosActrTst;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidInitOutput(void)
{
   Thr_stActrTst = THR_ACTRTST_IDLE;
   Thr_stDynTst = THR_DYNTST_IDLE;
   Thr_stGapTst = THR_GAPTST_IDLE;
   VEMS_vidSET(Thr_bDynActrTst, 0);
   VEMS_vidSET(Thr_bGapActrTst, 0);
   VEMS_vidSET(Thr_bThrTstCmpl, 0);
   VEMS_vidSET(Thr_bTstInProgs, 0);
   VEMS_vidSET(Thr_rSpPosActrTst, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidThrTstSpChart                                 */
/* !Description :  Quand un test actionneur papillon est lancé, une consigne  */
/*                 spécifique à 5 paliers est appliquée au papillon pendant le*/
/*                 test actionneur. Si le test se déroule entièrement, le bit */
/*                 Thr_bTstCmpl passe à 1.                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.SARHAN                                                   */
/* !Trace_To    :  VEMS_R_09_00783_001.01                                     */
/*                 VEMS_R_09_00783_002.01                                     */
/*                 VEMS_R_09_00783_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input boolean Thr_bTstInProgs;                                            */
/*  input uint8 ActrTstThr_ChgtSp;                                            */
/*  input st87 Thr_stActrTst;                                                 */
/*  input uint16 ActrTstThr_Phase1Time;                                       */
/*  input uint16 ActrTstThr_TstTime;                                          */
/*  input uint16 ActrTstThr_Phase2Time;                                       */
/*  input uint8 ActrTstThr_LowPosn;                                           */
/*  input uint16 ActrTstThr_Phase3Time;                                       */
/*  input uint8 ActrTstThr_MidPosn;                                           */
/*  input uint16 ActrTstThr_Phase4Time;                                       */
/*  input uint8 ActrTstThr_HighPosn;                                          */
/*  input uint16 ActrTstThr_Phase5Time;                                       */
/*  input uint16 ActrTstThr_Phase6Time;                                       */
/*  input uint16 ActrTstThr_Phase7Time;                                       */
/*  input uint16 ActrTstThr_Tempo_C;                                          */
/*  input uint16 ActrTstThr_Tempo;                                            */
/*  output boolean THRACTEST_bTstInProgsPrev;                                 */
/*  output uint8 THRACTEST_u8ActrTstThrChgtSpPrev;                            */
/*  output boolean Thr_bTstInProgs;                                           */
/*  output uint8 ActrTstThr_ChgtSp;                                           */
/*  output st87 Thr_stActrTst;                                                */
/*  output uint16 ActrTstThr_TstTime;                                         */
/*  output uint16 Thr_rSpPosActrTst;                                          */
/*  output boolean Thr_bThrTstCmpl;                                           */
/*  output uint16 ActrTstThr_Tempo;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidThrTstSpChart(void)
{
   boolean bLocalThr_bTstInProgs;
   boolean bLocalSrv_bActrTstEna;
   uint8   u8LocalCode_test_action;
   uint16  u16LocalActrTstThr_TstTime;
   uint16  u16LocalThr_rSpPosActrTst;
   uint16  u16LocalActrTstThr_Tempo;

   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);
   VEMS_vidGET(Thr_bTstInProgs, bLocalThr_bTstInProgs);
   THRACTEST_bTstInProgsPrev = bLocalThr_bTstInProgs;
   THRACTEST_u8ActrTstThrChgtSpPrev =
      (uint8)MATHSRV_udtMIN(ActrTstThr_ChgtSp, 7);

   switch (Thr_stActrTst)
   {
      case THR_ACTRTST_IDLE:
         if (  (bLocalSrv_bActrTstEna != 0)
            && (u8LocalCode_test_action == CODE_TEST_PAP_MOT))
         {
            VEMS_vidSET(Thr_bTstInProgs, 1);
            ActrTstThr_ChgtSp = 0;
            Thr_stActrTst = THR_ACTRTST_PHASE1 ;
            ActrTstThr_TstTime = (uint16)MATHSRV_udtMIN(ActrTstThr_Phase1Time,
                                                        30000);
            VEMS_vidSET(Thr_rSpPosActrTst, 0);
         }
         break;

      case THR_ACTRTST_PHASE1:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_PAP_MOT))
         {
            Thr_stActrTst = THR_ACTRTST_IDLE;
            VEMS_vidSET(Thr_rSpPosActrTst, 0);
            ActrTstThr_ChgtSp = 0;
            VEMS_vidSET(Thr_bThrTstCmpl, 0);
            VEMS_vidSET(Thr_bTstInProgs, 0);
         }
         else
         {
            if (ActrTstThr_TstTime <= 1)
            {
               Thr_stActrTst = THR_ACTRTST_PHASE2;
               ActrTstThr_ChgtSp = 2;
               u16LocalActrTstThr_TstTime = ActrTstThr_Phase2Time;
               u16LocalThr_rSpPosActrTst = (uint16)(ActrTstThr_LowPosn * 4);
               VEMS_vidSET(Thr_rSpPosActrTst, u16LocalThr_rSpPosActrTst);
            }
            else
            {
               u16LocalActrTstThr_TstTime = (uint16)(ActrTstThr_TstTime - 1);
            }
            ActrTstThr_TstTime =
               (uint16)MATHSRV_udtMIN(u16LocalActrTstThr_TstTime, 30000);
         }
         break;

      case THR_ACTRTST_PHASE2:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_PAP_MOT))
         {
            Thr_stActrTst = THR_ACTRTST_IDLE;
            VEMS_vidSET(Thr_rSpPosActrTst, 0);
            ActrTstThr_ChgtSp = 0;
            VEMS_vidSET(Thr_bThrTstCmpl, 0);
            VEMS_vidSET(Thr_bTstInProgs, 0);
         }
         else
         {
            if (ActrTstThr_TstTime <= 1)
            {
               Thr_stActrTst = THR_ACTRTST_PHASE3;
               ActrTstThr_ChgtSp = 3;
               u16LocalActrTstThr_TstTime =
                  (uint16)MATHSRV_udtMIN(ActrTstThr_Phase3Time, 30000);
               u16LocalThr_rSpPosActrTst = (uint16)(ActrTstThr_MidPosn * 4);
               VEMS_vidSET(Thr_rSpPosActrTst, u16LocalThr_rSpPosActrTst);
            }
            else
            {
               u16LocalActrTstThr_TstTime = (uint16)(ActrTstThr_TstTime - 1);
            }
            ActrTstThr_TstTime =
               (uint16)MATHSRV_udtMIN(u16LocalActrTstThr_TstTime, 30000);
         }
         break;

      case THR_ACTRTST_PHASE3:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_PAP_MOT))
         {
            Thr_stActrTst = THR_ACTRTST_IDLE;
            VEMS_vidSET(Thr_rSpPosActrTst, 0);
            ActrTstThr_ChgtSp = 0;
            VEMS_vidSET(Thr_bThrTstCmpl, 0);
            VEMS_vidSET(Thr_bTstInProgs, 0);
         }
         else
         {
            if (ActrTstThr_TstTime <= 1)
            {
               Thr_stActrTst = THR_ACTRTST_PHASE4;
               ActrTstThr_ChgtSp = 4;
               u16LocalActrTstThr_TstTime = ActrTstThr_Phase4Time;
               u16LocalThr_rSpPosActrTst = (uint16)(ActrTstThr_HighPosn * 4);
               VEMS_vidSET(Thr_rSpPosActrTst, u16LocalThr_rSpPosActrTst);
            }
            else
            {
               u16LocalActrTstThr_TstTime = (uint16)(ActrTstThr_TstTime - 1);
            }
            ActrTstThr_TstTime =
               (uint16)MATHSRV_udtMIN(u16LocalActrTstThr_TstTime, 30000);
         }
         break;

      case THR_ACTRTST_PHASE4:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_PAP_MOT))
         {
            Thr_stActrTst = THR_ACTRTST_IDLE;
            VEMS_vidSET(Thr_rSpPosActrTst, 0);
            ActrTstThr_ChgtSp = 0;
            VEMS_vidSET(Thr_bThrTstCmpl, 0);
            VEMS_vidSET(Thr_bTstInProgs, 0);
         }
         else
         {
            if (ActrTstThr_TstTime <= 1)
            {
               Thr_stActrTst = THR_ACTRTST_PHASE5;
               ActrTstThr_ChgtSp = 5;
               u16LocalActrTstThr_TstTime = ActrTstThr_Phase5Time;
               u16LocalThr_rSpPosActrTst = (uint16)(ActrTstThr_MidPosn * 4);
               VEMS_vidSET(Thr_rSpPosActrTst, u16LocalThr_rSpPosActrTst);
            }
            else
            {
               u16LocalActrTstThr_TstTime = (uint16)(ActrTstThr_TstTime - 1);
            }
            ActrTstThr_TstTime =
               (uint16)MATHSRV_udtMIN(u16LocalActrTstThr_TstTime, 30000);
         }
         break;

      case THR_ACTRTST_PHASE5:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_PAP_MOT))
         {
            Thr_stActrTst = THR_ACTRTST_IDLE;
            VEMS_vidSET(Thr_rSpPosActrTst, 0);
            ActrTstThr_ChgtSp = 0;
            VEMS_vidSET(Thr_bThrTstCmpl, 0);
            VEMS_vidSET(Thr_bTstInProgs, 0);
         }
         else
         {
            if (ActrTstThr_TstTime <= 1)
            {
               Thr_stActrTst = THR_ACTRTST_PHASE6;
               ActrTstThr_ChgtSp = 6;
               u16LocalActrTstThr_TstTime = ActrTstThr_Phase6Time;
               u16LocalThr_rSpPosActrTst = (uint16)(ActrTstThr_LowPosn * 4);
               VEMS_vidSET(Thr_rSpPosActrTst, u16LocalThr_rSpPosActrTst);
            }
            else
            {
               u16LocalActrTstThr_TstTime = (uint16)(ActrTstThr_TstTime - 1);
            }
            ActrTstThr_TstTime =
               (uint16)MATHSRV_udtMIN(u16LocalActrTstThr_TstTime, 30000);
         }
         break;

      case THR_ACTRTST_PHASE6:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_PAP_MOT))
         {
            Thr_stActrTst = THR_ACTRTST_IDLE;
            VEMS_vidSET(Thr_rSpPosActrTst, 0);
            ActrTstThr_ChgtSp = 0;
            VEMS_vidSET(Thr_bThrTstCmpl, 0);
            VEMS_vidSET(Thr_bTstInProgs, 0);
         }
         else
         {
            if (ActrTstThr_TstTime <= 1)
            {
               Thr_stActrTst = THR_ACTRTST_PHASE7;
               ActrTstThr_ChgtSp = 0;
               u16LocalActrTstThr_TstTime = ActrTstThr_Phase7Time;
               VEMS_vidSET(Thr_rSpPosActrTst, 0);
            }
            else
            {
               u16LocalActrTstThr_TstTime = (uint16)(ActrTstThr_TstTime - 1);
            }
            ActrTstThr_TstTime =
               (uint16)MATHSRV_udtMIN(u16LocalActrTstThr_TstTime, 30000);
         }
         break;

      case THR_ACTRTST_PHASE7:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_PAP_MOT))
         {
            Thr_stActrTst = THR_ACTRTST_IDLE;
            VEMS_vidSET(Thr_rSpPosActrTst, 0);
            ActrTstThr_ChgtSp = 0;
            VEMS_vidSET(Thr_bThrTstCmpl, 0);
            VEMS_vidSET(Thr_bTstInProgs, 0);
         }
         else
         {
            if (ActrTstThr_TstTime <= 1)
            {
               Thr_stActrTst = THR_ACTRTST_END;
               ActrTstThr_ChgtSp = 0;
               VEMS_vidSET(Thr_rSpPosActrTst, 0);
               VEMS_vidSET(Thr_bThrTstCmpl, 1);
               VEMS_vidSET(Thr_bTstInProgs, 0);
               ActrTstThr_Tempo = (uint16)MATHSRV_udtMIN(ActrTstThr_Tempo_C,
                                                         30000);
            }
            else
            {
               u16LocalActrTstThr_TstTime = (uint16)(ActrTstThr_TstTime - 1);
               ActrTstThr_TstTime =
                  (uint16)MATHSRV_udtMIN(u16LocalActrTstThr_TstTime, 30000);
            }
         }
         break;

      case THR_ACTRTST_END:
         if (  (bLocalSrv_bActrTstEna != 0)
            && (u8LocalCode_test_action == CODE_TEST_PAP_MOT)
            && (ActrTstThr_Tempo == 0))
         {
            Thr_stActrTst = THR_ACTRTST_IDLE;
            VEMS_vidSET(Thr_rSpPosActrTst, 0);
            ActrTstThr_ChgtSp = 0;
            VEMS_vidSET(Thr_bThrTstCmpl, 0);
            VEMS_vidSET(Thr_bTstInProgs, 0);
         }
         else
         {
            /* during state THR_ACTRTST_END */
            if (ActrTstThr_Tempo > 0)
            {
               u16LocalActrTstThr_Tempo = (uint16)(ActrTstThr_Tempo - 1);
               ActrTstThr_Tempo =
                  (uint16)MATHSRV_udtMIN(u16LocalActrTstThr_Tempo, 30000);
            }
         }
         break;

      default:
         Thr_stActrTst = THR_ACTRTST_IDLE;
         VEMS_vidSET(Thr_rSpPosActrTst, 0);
         ActrTstThr_ChgtSp = 0;
         VEMS_vidSET(Thr_bThrTstCmpl, 0);
         VEMS_vidSET(Thr_bTstInProgs, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidDynTstSpeed                                   */
/* !Description :  Le test dynamique consiste à vérifier la vitesse de        */
/*                 réaction du papillon à un échelon de consigne pour détecter*/
/*                 un éventuel encrassement.                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.SARHAN                                                   */
/* !Trace_To    :  VEMS_R_09_00783_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRACTEST_vidDynTstEna();                                */
/*  extf argret void THRACTEST_vidDynTst();                                   */
/*  extf argret void THRACTEST_vidDynTstResInit();                            */
/*  extf argret void THRACTEST_vidDynTstResClcn();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidDynTstSpeed(void)
{
   THRACTEST_vidDynTstEna();
   THRACTEST_vidDynTst();
   THRACTEST_vidDynTstResInit();
   THRACTEST_vidDynTstResClcn();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidDynTstEna                                     */
/* !Description :  Fonction qui permet, à chaque changement de consigne, le   */
/*                 lancement du test dynamique (compteur). Lorsque la position*/
/*                 du papillon est suffisamment proche de sa consigne, on     */
/*                 arrête le test.                                            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tpac_corrected_throttle_position;                            */
/*  input uint16 Thr_rSpPosActrTst;                                           */
/*  input boolean Thr_bTstInProgs;                                            */
/*  input uint8 ActrTstThr_ChgtSp;                                            */
/*  input uint8 THRACTEST_u8ActrTstThrChgtSpPrev;                             */
/*  input uint8 ActrTstThr_DynTstMaxDiffPosn;                                 */
/*  output boolean ActrTstThr_RunDynTest;                                     */
/*  output boolean ActrTstThr_StopDynTest;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidDynTstEna(void)
{
   boolean bLocalThr_bTstInProgs;
   uint16  u16LocalGapTestDiffAbs;
   uint16  u16LocalDynTstMaxDiffPosn;
   uint16  u16Localthrottle_position;
   uint16  u16LocalThr_rSpPosActrTst;
   sint32  s32LocalGapTestDiff;


   VEMS_vidGET(Tpac_corrected_throttle_position, u16Localthrottle_position);
   VEMS_vidGET(Thr_rSpPosActrTst, u16LocalThr_rSpPosActrTst);
   VEMS_vidGET(Thr_bTstInProgs, bLocalThr_bTstInProgs);

   if (  (bLocalThr_bTstInProgs != 0)
      && (ActrTstThr_ChgtSp != THRACTEST_u8ActrTstThrChgtSpPrev)
      && (ActrTstThr_ChgtSp != 0))
   {
      ActrTstThr_RunDynTest = 1;
   }
   else
   {
      ActrTstThr_RunDynTest = 0;
   }

   s32LocalGapTestDiff = (sint32)( u16Localthrottle_position
                                 - u16LocalThr_rSpPosActrTst);
   u16LocalGapTestDiffAbs = (uint16)MATHSRV_udtABS(s32LocalGapTestDiff);
   u16LocalDynTstMaxDiffPosn = (uint16)(ActrTstThr_DynTstMaxDiffPosn * 4);

   if (  (bLocalThr_bTstInProgs == 0)
      || (u16LocalGapTestDiffAbs <= u16LocalDynTstMaxDiffPosn))
   {
      ActrTstThr_StopDynTest = 1;
   }
   else
   {
      ActrTstThr_StopDynTest = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidDynTst                                        */
/* !Description :  Fonction du test dynamique. Le test consiste à compter le  */
/*                 temps que met le papillon à rejoindre sa consigne.         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st88 Thr_stDynTst;                                                  */
/*  input boolean ActrTstThr_RunDynTest;                                      */
/*  input boolean ActrTstThr_StopDynTest;                                     */
/*  input uint16 ActrDynTstThr_TstTime;                                       */
/*  output st88 Thr_stDynTst;                                                 */
/*  output uint16 ActrDynTstThr_TstTime;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidDynTst(void)
{
   uint16 u16LocalTstTime;


   switch (Thr_stDynTst)
   {
      case THR_DYNTST_IDLE:
         if (ActrTstThr_RunDynTest != 0)
         {
            Thr_stDynTst = THR_DYNTST_RUN;
            ActrDynTstThr_TstTime = 0;
         }
         break;

      case THR_DYNTST_RUN:
         if (ActrTstThr_StopDynTest != 0)
         {
            Thr_stDynTst = THR_DYNTST_IDLE;
         }
         else
         {
            if (ActrDynTstThr_TstTime < 30000)
            {
               u16LocalTstTime = (uint16)(ActrDynTstThr_TstTime + 1);
            }
            else
            {
               u16LocalTstTime = 30000;
            }
            ActrDynTstThr_TstTime = u16LocalTstTime;
         }
         break;

      default:
         Thr_stDynTst = THR_DYNTST_IDLE;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidDynTstResInit                                 */
/* !Description :  Au début de chaque test actionneur, le bit de résultat     */
/*                 Thr_bDynActrTst est initialisé à 0.                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRACTEST_vidInitDynTst();                               */
/*  input boolean Thr_bTstInProgs;                                            */
/*  input boolean THRACTEST_bTstInProgsPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidDynTstResInit(void)
{
   boolean bLocalThr_bTstInProgs;


   VEMS_vidGET(Thr_bTstInProgs, bLocalThr_bTstInProgs);

   if (  (bLocalThr_bTstInProgs != 0)
      && (THRACTEST_bTstInProgsPrev == 0))
   {
      THRACTEST_vidInitDynTst();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidInitDynTst                                    */
/* !Description :  Fonction de mise à zéro du résultat du test                */
/*                 dynamique(Thr_bDynActrTst).                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Thr_bDynActrTst;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidInitDynTst(void)
{
   VEMS_vidSET(Thr_bDynActrTst, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidDynTstResClcn                                 */
/* !Description :  Pendant le test actionneur, si le temps que met le papillon*/
/*                 à atteindre sa consigne est supérieur à un seuil, alors le */
/*                 papillon est détecté encrassé, et le bit de résultat       */
/*                 Thr_bDynActrTst est alors maintenu à 1.                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 ActrTstThr_ChgtSp;                                            */
/*  input uint16 ActrTstThr_DynTstUpTime;                                     */
/*  input uint16 ActrTstThr_DynTstDwnTime;                                    */
/*  input uint16 ActrDynTstThr_TstTime;                                       */
/*  output boolean Thr_bDynActrTst;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidDynTstResClcn(void)
{
   uint16 u16LocalTime;


   if (ActrTstThr_ChgtSp <= 4)
   {
      u16LocalTime = ActrTstThr_DynTstUpTime;
   }
   else
   {
      u16LocalTime = ActrTstThr_DynTstDwnTime;
   }

   if (u16LocalTime <= ActrDynTstThr_TstTime)
   {
      VEMS_vidSET(Thr_bDynActrTst, 1);
   }
}
/*---------------------------- end of file -----------------------------------*/
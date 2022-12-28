/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINACTRTEST                                        */
/* !Description     : VLVACTINACTRTEST component                              */
/*                                                                            */
/* !Module          : VLVACTINACTRTEST                                        */
/* !Description     : TEST ACTIONNEUR DE LA VVT ADMISSION :GENERATION DE LA   */
/*                    CONSIGNE ET CALCUL DES CRITERES DE L’ASSERVISSEMENT     */
/*                                                                            */
/* !File            : VLVACTINACTRTEST_FCT2.C                                 */
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
/*   1 / VLVACTINACTRTEST_vidMeaCriTiComp                                     */
/*   2 / VLVACTINACTRTEST_vidSpeedErrorMe                                     */
/*   3 / VLVACTINACTRTEST_vidSpdErrInCalc                                     */
/*   4 / VLVACTINACTRTEST_vidSetpointComp                                     */
/*   5 / VLVACTINACTRTEST_vidIdleStTrans                                      */
/*   6 / VLVACTINACTRTEST_vidPhase1Trans                                      */
/*   7 / VLVACTINACTRTEST_vidPhase2Trans                                      */
/*   8 / VLVACTINACTRTEST_vidPhase3Trans                                      */
/*   9 / VLVACTINACTRTEST_vidPhase4Trans                                      */
/*   10 / VLVACTINACTRTEST_vidPhase5Trans                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 05822 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINACTRTEST/VLVACT$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   12 Sep 2012 $*/
/* $Author::   etsasson                               $$Date::   12 Sep 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINACTRTEST.h"
#include "VLVACTINACTRTEST_L.h"
#include "VLVACTINACTRTEST_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidMeaCriTiComp                           */
/* !Description :  calcule du temps nécessaire pour atteindre la valeur       */
/*                 final.(Pour la mesure)                                     */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 VlvAct_tiInActrTestSp;                                       */
/*  output uint16 VlvAct_tiInActrTestPosMesSpdErr;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidMeaCriTiComp(void)
{
   VlvAct_tiInActrTestPosMesSpdErr = VlvAct_tiInActrTestSp;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidSpeedErrorMe                           */
/* !Description :  Dans ce bloc sont calculées les différents coefficients    */
/*                 intervenant dans le calcul du seuil utilisé pour le calcul */
/*                 de  l’erreur de vitesse.                                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st114 VlvAct_stInActrTst;                                           */
/*  input uint8 VlvAct_InActrTestSpdErrSpThd1_C;                              */
/*  input uint8 VlvAct_InActrTestSpdErrSpThd2_C;                              */
/*  input uint8 VlvAct_InActrTestSpdErrSpThd3_C;                              */
/*  input uint8 VlvAct_InActrTestSpdErrSpThd4_C;                              */
/*  output sint8 VlvAct_InActrTestSpdErrorCompCoe;                            */
/*  output uint8 VlvAct_InActrTestSpdErrorTiThd;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidSpeedErrorMe(void)
{
   uint8 u8LocalVlvAct_stInActrTst;
   uint8 u8LocalTestSpdErrorTiThd;


   VEMS_vidGET(VlvAct_stInActrTst, u8LocalVlvAct_stInActrTst);

   switch (u8LocalVlvAct_stInActrTst)
   {
      case VLV_INACTRTST_PHASE2:
         VlvAct_InActrTestSpdErrorCompCoe = 1;
         u8LocalTestSpdErrorTiThd = VlvAct_InActrTestSpdErrSpThd1_C;
         break;

      case VLV_INACTRTST_PHASE4:
         VlvAct_InActrTestSpdErrorCompCoe = -1;
         u8LocalTestSpdErrorTiThd = VlvAct_InActrTestSpdErrSpThd2_C;
         break;

      case VLV_INACTRTST_PHASE7:
         VlvAct_InActrTestSpdErrorCompCoe = 1;
         u8LocalTestSpdErrorTiThd = VlvAct_InActrTestSpdErrSpThd3_C;
         break;

      case VLV_INACTRTST_PHASE9:
         VlvAct_InActrTestSpdErrorCompCoe = -1;
         u8LocalTestSpdErrorTiThd = VlvAct_InActrTestSpdErrSpThd4_C;
         break;

      default:
         VlvAct_InActrTestSpdErrorCompCoe = 0;
         u8LocalTestSpdErrorTiThd = 0;
         break;
   }

   VlvAct_InActrTestSpdErrorTiThd =
      (uint8)MATHSRV_udtMIN(u8LocalTestSpdErrorTiThd, 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidSpdErrInCalc                           */
/* !Description :  Dans ce bloc sont calculées les indicateurs d’erreurs de   */
/*                 vitesse sur les différentes rampes de  la consigne  envoyée*/
/*                 lors du test actionneur de la VVT admission.               */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input boolean VLVACTINACTRTEST_SrvbInVVTEnPrev;                           */
/*  input st114 VlvAct_stInActrTst;                                           */
/*  input uint16 VlvAct_tiInActrTstSpdErr;                                    */
/*  input uint16 VLVACTINACTRTEST_u16CalcPhase2;                              */
/*  input uint16 VlvAct_tiInActrSpdTest1RampThd_C;                            */
/*  input uint16 VLVACTINACTRTEST_u16CalcPhase4;                              */
/*  input uint16 VlvAct_tiInActrSpdTest2RampThd_C;                            */
/*  input uint16 VLVACTINACTRTEST_u16CalcPhase7;                              */
/*  input uint16 VlvAct_tiInActrSpdTest3RampThd_C;                            */
/*  input uint16 VLVACTINACTRTEST_u16CalcPhase9;                              */
/*  input uint16 VlvAct_tiInActrSpdTest4RampThd_C;                            */
/*  output uint16 VLVACTINACTRTEST_u16CalcPhase2;                             */
/*  output uint16 VLVACTINACTRTEST_u16CalcPhase4;                             */
/*  output uint16 VLVACTINACTRTEST_u16CalcPhase7;                             */
/*  output uint16 VLVACTINACTRTEST_u16CalcPhase9;                             */
/*  output boolean VlvAct_bInActrTest1RampSpdErrIdc;                          */
/*  output boolean VlvAct_bInActrTest2RampSpdErrIdc;                          */
/*  output boolean VlvAct_bInActrTest3RampSpdErrIdc;                          */
/*  output boolean VlvAct_bInActrTest4RampSpdErrIdc;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidSpdErrInCalc(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   uint8   u8LocalVlvAct_stInActrTst;


   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);
   if (  (bLocalSrv_bActrTstInVVTEna != 0)
      && (VLVACTINACTRTEST_SrvbInVVTEnPrev == 0))
   {
      VLVACTINACTRTEST_u16CalcPhase2 = 0;
      VLVACTINACTRTEST_u16CalcPhase4 = 0;
      VLVACTINACTRTEST_u16CalcPhase7 = 0;
      VLVACTINACTRTEST_u16CalcPhase9 = 0;
   }
   else
   {
      VEMS_vidGET(VlvAct_stInActrTst, u8LocalVlvAct_stInActrTst);
      switch (u8LocalVlvAct_stInActrTst)
      {
         case VLV_INACTRTST_PHASE2:
            VLVACTINACTRTEST_u16CalcPhase2 = VlvAct_tiInActrTstSpdErr;
            break;

         case VLV_INACTRTST_PHASE4:
            VLVACTINACTRTEST_u16CalcPhase4 = VlvAct_tiInActrTstSpdErr;
            break;

         case VLV_INACTRTST_PHASE7:
            VLVACTINACTRTEST_u16CalcPhase7 = VlvAct_tiInActrTstSpdErr;
            break;

         case VLV_INACTRTST_PHASE9:
            VLVACTINACTRTEST_u16CalcPhase9 = VlvAct_tiInActrTstSpdErr;
            break;

         default:
            /* do nothing*/
            break;
      }
   }

   if (VLVACTINACTRTEST_u16CalcPhase2 >= VlvAct_tiInActrSpdTest1RampThd_C)
   {
      VEMS_vidSET(VlvAct_bInActrTest1RampSpdErrIdc, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInActrTest1RampSpdErrIdc, 0);
   }

   if (VLVACTINACTRTEST_u16CalcPhase4 >= VlvAct_tiInActrSpdTest2RampThd_C)
   {
      VEMS_vidSET(VlvAct_bInActrTest2RampSpdErrIdc, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInActrTest2RampSpdErrIdc, 0);
   }

   if (VLVACTINACTRTEST_u16CalcPhase7 >= VlvAct_tiInActrSpdTest3RampThd_C)
   {
      VEMS_vidSET(VlvAct_bInActrTest3RampSpdErrIdc, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInActrTest3RampSpdErrIdc, 0);
   }

   if (VLVACTINACTRTEST_u16CalcPhase9 >= VlvAct_tiInActrSpdTest4RampThd_C)
   {
      VEMS_vidSET(VlvAct_bInActrTest4RampSpdErrIdc, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInActrTest4RampSpdErrIdc, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidSetpointComp                           */
/* !Description :  Ce bloc génère le profil de consigne envoyé lors du test   */
/*                 actionneur de la VVT admission.                            */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Z.HOSNI                                                    */
/* !Trace_To    :  VEMS_R_09_05822_001.01                                     */
/*                 VEMS_R_09_05822_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACTRTEST_vidIdleStTrans();                       */
/*  extf argret void VLVACTINACTRTEST_vidPhase1Trans();                       */
/*  extf argret void VLVACTINACTRTEST_vidPhase2Trans();                       */
/*  extf argret void VLVACTINACTRTEST_vidPhase3Trans();                       */
/*  extf argret void VLVACTINACTRTEST_vidPhase4Trans();                       */
/*  extf argret void VLVACTINACTRTEST_vidPhase5Trans();                       */
/*  extf argret void VLVACTINACTRTEST_vidPhase6Trans();                       */
/*  extf argret void VLVACTINACTRTEST_vidPhase7Trans();                       */
/*  extf argret void VLVACTINACTRTEST_vidPhase8Trans();                       */
/*  extf argret void VLVACTINACTRTEST_vidPhase9Trans();                       */
/*  extf argret void VLVACTINACTRTEST_vidPhase10Trans();                      */
/*  extf argret void VLVACTINACTRTEST_vidEndStTrans();                        */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st114 VlvAct_stInActrTst;                                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input uint8 VLVACTINACTRTEST_u8CdeTstActPrev;                             */
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*  output boolean VlvAct_bInActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*  output st117 VlvAct_stInActrTstLstSt;                                     */
/*  output uint8 VLVACTINACTRTEST_u8CdeTstActPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidSetpointComp(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   uint8   u8LocalVlvAct_stInActrTst;
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(VlvAct_stInActrTst, u8LocalVlvAct_stInActrTst);

   switch (u8LocalVlvAct_stInActrTst)
   {
      case VLV_INACTRTST_IDLE:
         VLVACTINACTRTEST_vidIdleStTrans();
         break;

      case VLV_INACTRTST_PHASE1:
         VLVACTINACTRTEST_vidPhase1Trans();
         break;

      case VLV_INACTRTST_PHASE2:
         VLVACTINACTRTEST_vidPhase2Trans();
         break;

      case VLV_INACTRTST_PHASE3:
         VLVACTINACTRTEST_vidPhase3Trans();
         break;

      case VLV_INACTRTST_PHASE4:
         VLVACTINACTRTEST_vidPhase4Trans();
         break;

      case VLV_INACTRTST_PHASE5:
         VLVACTINACTRTEST_vidPhase5Trans();
         break;

      case VLV_INACTRTST_PHASE6:
         VLVACTINACTRTEST_vidPhase6Trans();
         break;

      case VLV_INACTRTST_PHASE7:
         VLVACTINACTRTEST_vidPhase7Trans();
         break;

      case VLV_INACTRTST_PHASE8:
         VLVACTINACTRTEST_vidPhase8Trans();
         break;

      case VLV_INACTRTST_PHASE9:
         VLVACTINACTRTEST_vidPhase9Trans();
         break;

      case VLV_INACTRTST_PHASE10:
         VLVACTINACTRTEST_vidPhase10Trans();
         break;

      case VLV_INACTRTST_END:
         VLVACTINACTRTEST_vidEndStTrans();
         break;

      default:
         VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_IDLE);
         VEMS_vidSET(VlvAct_agInActrTestPosSp, 0);
         VEMS_vidSET(VlvAct_bInActrTestSpEndIdc, 0);
         VEMS_vidSET(VlvAct_bInActrTestNotRun, 1);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   VEMS_vidGET(VlvAct_stInActrTst, u8LocalVlvAct_stInActrTst);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);

   if (  (bLocalSrv_bActrTstInVVTEna != 0)
      && (u8LocalCode_test_action == VLVACTINACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stInActrTstLstSt, u8LocalVlvAct_stInActrTst);
   }

   VLVACTINACTRTEST_u8CdeTstActPrev = u8LocalCode_test_action;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidIdleStTrans                            */
/* !Description :  calcule de l'etat INVLVACT_ACTRTST_IDLE                    */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input uint16 VlvAct_tiInActrTest1SplSp_C;                                 */
/*  input uint16 VlvAct_agInActrTestMinPosSp_C;                               */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output uint16 VlvAct_tiInActrTestSp;                                      */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidIdleStTrans(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   uint16  u16LocalagInActrTestMinPos;


   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);

   if (bLocalSrv_bActrTstInVVTEna != 0)
   {
      VEMS_vidSET(VlvAct_bInActrTestNotRun, 0);
      VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_PHASE1);

      VlvAct_tiInActrTestSp = VlvAct_tiInActrTest1SplSp_C;

      u16LocalagInActrTestMinPos =
         (uint16)MATHSRV_udtMIN(VlvAct_agInActrTestMinPosSp_C, 1066);

      VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalagInActrTestMinPos);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidPhase1Trans                            */
/* !Description :  calcule de l'etat INVLVACT_ACTRTST_PHASE1                  */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input uint8 VLVACTINACTRTEST_u8CdeTstActPrev;                             */
/*  input uint16 VlvAct_tiInActrTestSp;                                       */
/*  input uint16 VlvAct_tiInActrTest2SplSp_C;                                 */
/*  input uint16 VlvAct_agInActrTestMinPosSp_C;                               */
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*  output boolean VlvAct_bInActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiInActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidPhase1Trans(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagInActrTestMinPos;
   sint32  s32LocalVar;


   VEMS_vidGET(Code_test_action, u8LocalCodeTestAction);
   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);

   if (  (bLocalSrv_bActrTstInVVTEna == 0)
      || (u8LocalCodeTestAction != VLVACTINACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agInActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bInActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bInActrTestNotRun, 1);
   }
   else
   {
      s32LocalVar = (sint32)(VlvAct_tiInActrTestSp - 1);
      VlvAct_tiInActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar, 0);

      if (VlvAct_tiInActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_PHASE2);
         VlvAct_tiInActrTestSp = VlvAct_tiInActrTest2SplSp_C;
         u16LocalagInActrTestMinPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agInActrTestMinPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalagInActrTestMinPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidPhase2Trans                            */
/* !Description :  calcule de l'etat INVLVACT_ACTRTST_PHASE2                  */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret uint32  MATHSRV_u32Div_u32_u16(argin uint32 u32FirstValue,    */
/* argin uint16 u16SecondValue);                                              */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input uint8 VLVACTINACTRTEST_u8CdeTstActPrev;                             */
/*  input uint16 VlvAct_tiInActrTestSp;                                       */
/*  input uint16 VlvAct_agInActrTestMaxPosSp_C;                               */
/*  input uint16 VlvAct_agInActrTestMinPosSp_C;                               */
/*  input uint16 VlvAct_tiInActrTest2SplSp_C;                                 */
/*  input uint16 VlvAct_tiInActrTest3SplSp_C;                                 */
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*  output boolean VlvAct_bInActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiInActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidPhase2Trans(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagInActrTestMaxPos;
   uint16  u16LocalInActrTestPosSp;
   uint32  u32LocalVar;
   sint32  s32LocalVar;


   VEMS_vidGET(Code_test_action, u8LocalCodeTestAction);
   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);

   if (  (bLocalSrv_bActrTstInVVTEna == 0)
      || (u8LocalCodeTestAction != VLVACTINACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agInActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bInActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bInActrTestNotRun, 1);
   }
   else
   {
      s32LocalVar = (sint32)(VlvAct_tiInActrTestSp - 1);
      VlvAct_tiInActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar,0);

      if (VlvAct_agInActrTestMaxPosSp_C >= VlvAct_agInActrTestMinPosSp_C)
      {
         u32LocalVar = (uint32)(( VlvAct_agInActrTestMaxPosSp_C
                                - VlvAct_agInActrTestMinPosSp_C)
                               * VlvAct_tiInActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiInActrTest2SplSp_C);

         if (VlvAct_agInActrTestMaxPosSp_C > u32LocalVar)
         {
            u32LocalVar = (VlvAct_agInActrTestMaxPosSp_C - u32LocalVar);
         }
         else
         {
            u32LocalVar = 0;
         }
      }
      else
      {
         u32LocalVar = (uint32)(( VlvAct_agInActrTestMinPosSp_C
                                - VlvAct_agInActrTestMaxPosSp_C)
                               * VlvAct_tiInActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiInActrTest2SplSp_C);
         u32LocalVar = (VlvAct_agInActrTestMaxPosSp_C + u32LocalVar);
      }

      u16LocalInActrTestPosSp = (uint16) MATHSRV_udtMIN(u32LocalVar, 1066);
      VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalInActrTestPosSp);

      if (VlvAct_tiInActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_PHASE3);
         VlvAct_tiInActrTestSp = VlvAct_tiInActrTest3SplSp_C;
         u16LocalagInActrTestMaxPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agInActrTestMaxPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalagInActrTestMaxPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidPhase3Trans                            */
/* !Description :  calcule de l'etat INVLVACT_ACTRTST_PHASE3                  */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input uint8 VLVACTINACTRTEST_u8CdeTstActPrev;                             */
/*  input uint16 VlvAct_tiInActrTestSp;                                       */
/*  input uint16 VlvAct_tiInActrTest4SplSp_C;                                 */
/*  input uint16 VlvAct_agInActrTestMaxPosSp_C;                               */
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*  output boolean VlvAct_bInActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiInActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidPhase3Trans(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagInActrTestMaxPos;
   sint32  s32LocalVar;


   VEMS_vidGET(Code_test_action, u8LocalCodeTestAction);
   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);

   if (  (bLocalSrv_bActrTstInVVTEna == 0)
      || (u8LocalCodeTestAction != VLVACTINACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agInActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bInActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bInActrTestNotRun, 1);
   }
   else
   {
      s32LocalVar = (sint32)(VlvAct_tiInActrTestSp - 1);
      VlvAct_tiInActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar,0);

      if (VlvAct_tiInActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_PHASE4);
         VlvAct_tiInActrTestSp = VlvAct_tiInActrTest4SplSp_C;
         u16LocalagInActrTestMaxPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agInActrTestMaxPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalagInActrTestMaxPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidPhase4Trans                            */
/* !Description :  calcule  de l'etat INVLVACT_ACTRTST_PHASE4                 */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret uint32  MATHSRV_u32Div_u32_u16(argin uint32 u32FirstValue,    */
/* argin uint16 u16SecondValue);                                              */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input uint8 VLVACTINACTRTEST_u8CdeTstActPrev;                             */
/*  input uint16 VlvAct_tiInActrTestSp;                                       */
/*  input uint16 VlvAct_agInActrTestMaxPosSp_C;                               */
/*  input uint16 VlvAct_agInActrTestMinPosSp_C;                               */
/*  input uint16 VlvAct_tiInActrTest4SplSp_C;                                 */
/*  input uint16 VlvAct_tiInActrTest5SplSp_C;                                 */
/*  input uint16 VlvAct_tiInActrTest6SplSp_C;                                 */
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*  output boolean VlvAct_bInActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiInActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidPhase4Trans(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagInActrTestMinPos;
   uint32  u32LocalVlvAct_tiInActrTestSp;
   uint32  u32LocalVar;
   sint32  s32LocalVar;


   VEMS_vidGET(Code_test_action, u8LocalCodeTestAction);
   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);

   if (  (bLocalSrv_bActrTstInVVTEna == 0)
      || (u8LocalCodeTestAction != VLVACTINACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agInActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bInActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bInActrTestNotRun, 1);
   }
   else
   {
      s32LocalVar = (sint32)(VlvAct_tiInActrTestSp - 1);
      VlvAct_tiInActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar, 0);

      if (VlvAct_agInActrTestMaxPosSp_C < VlvAct_agInActrTestMinPosSp_C)
      {
         u32LocalVar = (uint32)(( VlvAct_agInActrTestMinPosSp_C
                                - VlvAct_agInActrTestMaxPosSp_C)
                               * VlvAct_tiInActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiInActrTest4SplSp_C);

         if (VlvAct_agInActrTestMinPosSp_C > u32LocalVar)
         {
            u32LocalVar = (VlvAct_agInActrTestMinPosSp_C - u32LocalVar);
         }
         else
         {
            u32LocalVar = 0;
         }
      }
      else
      {
         u32LocalVar = (uint32)(( VlvAct_agInActrTestMaxPosSp_C
                                - VlvAct_agInActrTestMinPosSp_C)
                               * VlvAct_tiInActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiInActrTest4SplSp_C);
         u32LocalVar = (VlvAct_agInActrTestMinPosSp_C + u32LocalVar);
      }

      u16LocalagInActrTestMinPos = (uint16) MATHSRV_udtMIN(u32LocalVar, 1066);

      if (VlvAct_tiInActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_PHASE5);
         u32LocalVlvAct_tiInActrTestSp = ( VlvAct_tiInActrTest5SplSp_C
                                         + VlvAct_tiInActrTest6SplSp_C);
         VlvAct_tiInActrTestSp =
            (uint16)MATHSRV_udtMIN(u32LocalVlvAct_tiInActrTestSp, 65535);
         u16LocalagInActrTestMinPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agInActrTestMinPosSp_C, 1066);
      }
      VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalagInActrTestMinPos);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidPhase5Trans                            */
/* !Description :  calcule  de l'etat INVLVACT_ACTRTST_PHASE5                 */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input uint8 VLVACTINACTRTEST_u8CdeTstActPrev;                             */
/*  input uint16 VlvAct_tiInActrTestSp;                                       */
/*  input uint16 VlvAct_tiInActrTest5SplSp_C;                                 */
/*  input uint16 VlvAct_agInActrTestMinPosSp_C;                               */
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*  output boolean VlvAct_bInActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiInActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidPhase5Trans(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagInActrTestMinPos;
   sint32  s32LocalVar;

   VEMS_vidGET(Code_test_action, u8LocalCodeTestAction);
   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);

   if (  (bLocalSrv_bActrTstInVVTEna == 0)
      || (u8LocalCodeTestAction != VLVACTINACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agInActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bInActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bInActrTestNotRun, 1);
   }
   else
   {
      s32LocalVar = (sint32)(VlvAct_tiInActrTestSp - 1);
      VlvAct_tiInActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar,0);

      if (VlvAct_tiInActrTestSp <= VlvAct_tiInActrTest5SplSp_C)
      {
         VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_PHASE6);
         s32LocalVar = (sint32)(VlvAct_tiInActrTestSp - 1);
         VlvAct_tiInActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar,0);
         u16LocalagInActrTestMinPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agInActrTestMinPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalagInActrTestMinPos);
      }
   }
}
/*------------------------------- end of file --------------------------------*/
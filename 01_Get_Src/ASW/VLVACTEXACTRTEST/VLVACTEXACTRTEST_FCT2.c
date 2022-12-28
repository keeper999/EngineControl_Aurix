/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXACTRTEST                                        */
/* !Description     : VLVACTEXACTRTEST component                              */
/*                                                                            */
/* !Module          : VLVACTEXACTRTEST                                        */
/* !Description     : TEST ACTIONNEUR DE LA VVT ECHAPPEMENT :GENERATION DE LA */
/*                    CONSIGNE ET CALCUL DES CRITERES DE L’ASSERVISSEMENT     */
/*                                                                            */
/* !File            : VLVACTEXACTRTEST_FCT2.C                                 */
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
/*   1 / VLVACTEXACTRTEST_vidMeaCriTiComp                                     */
/*   2 / VLVACTEXACTRTEST_vidSpeedErrorMe                                     */
/*   3 / VLVACTEXACTRTEST_vidSpdErrExCalc                                     */
/*   4 / VLVACTEXACTRTEST_vidSetpointComp                                     */
/*   5 / VLVACTEXACTRTEST_vidIdleStTrans                                      */
/*   6 / VLVACTEXACTRTEST_vidPhase1Trans                                      */
/*   7 / VLVACTEXACTRTEST_vidPhase2Trans                                      */
/*   8 / VLVACTEXACTRTEST_vidPhase3Trans                                      */
/*   9 / VLVACTEXACTRTEST_vidPhase4Trans                                      */
/*   10 / VLVACTEXACTRTEST_vidPhase5Trans                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 05825 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXACTRTEST/VLVACT$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   12 Sep 2012 $*/
/* $Author::   etsasson                               $$Date::   12 Sep 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXACTRTEST.h"
#include "VLVACTEXACTRTEST_L.h"
#include "VLVACTEXACTRTEST_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidMeaCriTiComp                           */
/* !Description :  calcule du temps nécessaire pour atteindre la valeur       */
/*                 final.(Pour la mesure)                                     */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 VlvAct_tiExActrTestSp;                                       */
/*  output uint16 VlvAct_tiExActrTestPosMesSpdErr;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidMeaCriTiComp(void)
{
   VlvAct_tiExActrTestPosMesSpdErr = VlvAct_tiExActrTestSp;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidSpeedErrorMe                           */
/* !Description :  Dans ce bloc sont calculées les différents coefficients    */
/*                 intervenant dans le calcul du seuil utilisé pour le calcul */
/*                 de  l’erreur de vitesse.                                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st115 VlvAct_stExActrTst;                                           */
/*  input uint8 VlvAct_ExActrTestSpdErrSpThd1_C;                              */
/*  input uint8 VlvAct_ExActrTestSpdErrSpThd2_C;                              */
/*  input uint8 VlvAct_ExActrTestSpdErrSpThd3_C;                              */
/*  input uint8 VlvAct_ExActrTestSpdErrSpThd4_C;                              */
/*  output sint8 VlvAct_ExActrTestSpdErrorCompCoe;                            */
/*  output uint8 VlvAct_ExActrTestSpdErrorTiThd;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidSpeedErrorMe(void)
{
   uint8 u8LocalVlvAct_stExActrTst;
   uint8 u8LocalTestSpdErrorTiThd;


   VEMS_vidGET(VlvAct_stExActrTst, u8LocalVlvAct_stExActrTst);

   switch (u8LocalVlvAct_stExActrTst)
   {
      case VLV_EXACTRTST_PHASE2:
         VlvAct_ExActrTestSpdErrorCompCoe = 1;
         u8LocalTestSpdErrorTiThd = VlvAct_ExActrTestSpdErrSpThd1_C;
         break;

      case VLV_EXACTRTST_PHASE4:
         VlvAct_ExActrTestSpdErrorCompCoe = -1;
         u8LocalTestSpdErrorTiThd = VlvAct_ExActrTestSpdErrSpThd2_C;
         break;

      case VLV_EXACTRTST_PHASE7:
         VlvAct_ExActrTestSpdErrorCompCoe = 1;
         u8LocalTestSpdErrorTiThd = VlvAct_ExActrTestSpdErrSpThd3_C;
         break;

      case VLV_EXACTRTST_PHASE9:
         VlvAct_ExActrTestSpdErrorCompCoe = -1;
         u8LocalTestSpdErrorTiThd = VlvAct_ExActrTestSpdErrSpThd4_C;
         break;

      default:
         VlvAct_ExActrTestSpdErrorCompCoe = 0;
         u8LocalTestSpdErrorTiThd = 0;
         break;
   }

   VlvAct_ExActrTestSpdErrorTiThd =
      (uint8)MATHSRV_udtMIN(u8LocalTestSpdErrorTiThd, 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidSpdErrExCalc                           */
/* !Description :  Dans ce bloc sont calculées les indicateurs d’erreurs de   */
/*                 vitesse sur les différentes rampes de  la consigne  envoyée*/
/*                 lors du test actionneur de la VVT échappement.             */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input boolean VLVACTEXACTRTEST_SrvbExVVTEnPrev;                           */
/*  input st115 VlvAct_stExActrTst;                                           */
/*  input uint16 VlvAct_tiExActrTstSpdErr;                                    */
/*  input uint16 VLVACTEXACTRTEST_u16CalcPhase2;                              */
/*  input uint16 VlvAct_tiExActrSpdTest1RampThd_C;                            */
/*  input uint16 VLVACTEXACTRTEST_u16CalcPhase4;                              */
/*  input uint16 VlvAct_tiExActrSpdTest2RampThd_C;                            */
/*  input uint16 VLVACTEXACTRTEST_u16CalcPhase7;                              */
/*  input uint16 VlvAct_tiExActrSpdTest3RampThd_C;                            */
/*  input uint16 VLVACTEXACTRTEST_u16CalcPhase9;                              */
/*  input uint16 VlvAct_tiExActrSpdTest4RampThd_C;                            */
/*  output uint16 VLVACTEXACTRTEST_u16CalcPhase2;                             */
/*  output uint16 VLVACTEXACTRTEST_u16CalcPhase4;                             */
/*  output uint16 VLVACTEXACTRTEST_u16CalcPhase7;                             */
/*  output uint16 VLVACTEXACTRTEST_u16CalcPhase9;                             */
/*  output boolean VlvAct_bExActrTest1RampSpdErrIdc;                          */
/*  output boolean VlvAct_bExActrTest2RampSpdErrIdc;                          */
/*  output boolean VlvAct_bExActrTest3RampSpdErrIdc;                          */
/*  output boolean VlvAct_bExActrTest4RampSpdErrIdc;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidSpdErrExCalc(void)
{
   boolean bLocalSrvbActrTstExVVTEna;
   uint8   u8LocalVlvAct_stExActrTst;


   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrvbActrTstExVVTEna);
   if (  (bLocalSrvbActrTstExVVTEna != 0)
      && (VLVACTEXACTRTEST_SrvbExVVTEnPrev == 0))
   {
      VLVACTEXACTRTEST_u16CalcPhase2 = 0;
      VLVACTEXACTRTEST_u16CalcPhase4 = 0;
      VLVACTEXACTRTEST_u16CalcPhase7 = 0;
      VLVACTEXACTRTEST_u16CalcPhase9 = 0;
   }
   else
   {
      VEMS_vidGET(VlvAct_stExActrTst, u8LocalVlvAct_stExActrTst);
      switch (u8LocalVlvAct_stExActrTst)
      {
         case VLV_EXACTRTST_PHASE2:
            VLVACTEXACTRTEST_u16CalcPhase2 = VlvAct_tiExActrTstSpdErr;
            break;

         case VLV_EXACTRTST_PHASE4:
            VLVACTEXACTRTEST_u16CalcPhase4 = VlvAct_tiExActrTstSpdErr;
            break;

         case VLV_EXACTRTST_PHASE7:
            VLVACTEXACTRTEST_u16CalcPhase7 = VlvAct_tiExActrTstSpdErr;
            break;

         case VLV_EXACTRTST_PHASE9:
            VLVACTEXACTRTEST_u16CalcPhase9 = VlvAct_tiExActrTstSpdErr;
            break;

         default:
            /* do nothing*/
            break;
      }
   }

   if (VLVACTEXACTRTEST_u16CalcPhase2 >= VlvAct_tiExActrSpdTest1RampThd_C)
   {
      VEMS_vidSET(VlvAct_bExActrTest1RampSpdErrIdc, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExActrTest1RampSpdErrIdc, 0);
   }

   if (VLVACTEXACTRTEST_u16CalcPhase4 >= VlvAct_tiExActrSpdTest2RampThd_C)
   {
      VEMS_vidSET(VlvAct_bExActrTest2RampSpdErrIdc, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExActrTest2RampSpdErrIdc, 0);
   }

   if (VLVACTEXACTRTEST_u16CalcPhase7 >= VlvAct_tiExActrSpdTest3RampThd_C)
   {
      VEMS_vidSET(VlvAct_bExActrTest3RampSpdErrIdc, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExActrTest3RampSpdErrIdc, 0);
   }

   if (VLVACTEXACTRTEST_u16CalcPhase9 >= VlvAct_tiExActrSpdTest4RampThd_C)
   {
      VEMS_vidSET(VlvAct_bExActrTest4RampSpdErrIdc, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExActrTest4RampSpdErrIdc, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidSetpointComp                           */
/* !Description :  Ce bloc génère le profil de consigne envoyé lors du test   */
/*                 actionneur de la VVT échappement.                          */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Z.HOSNI                                                    */
/* !Trace_To    :  VEMS_R_09_05825_001.01                                     */
/*                 VEMS_R_09_05825_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACTRTEST_vidIdleStTrans();                       */
/*  extf argret void VLVACTEXACTRTEST_vidPhase1Trans();                       */
/*  extf argret void VLVACTEXACTRTEST_vidPhase2Trans();                       */
/*  extf argret void VLVACTEXACTRTEST_vidPhase3Trans();                       */
/*  extf argret void VLVACTEXACTRTEST_vidPhase4Trans();                       */
/*  extf argret void VLVACTEXACTRTEST_vidPhase5Trans();                       */
/*  extf argret void VLVACTEXACTRTEST_vidPhase6Trans();                       */
/*  extf argret void VLVACTEXACTRTEST_vidPhase7Trans();                       */
/*  extf argret void VLVACTEXACTRTEST_vidPhase8Trans();                       */
/*  extf argret void VLVACTEXACTRTEST_vidPhase9Trans();                       */
/*  extf argret void VLVACTEXACTRTEST_vidPhase10Trans();                      */
/*  extf argret void VLVACTEXACTRTEST_vidEndStTrans();                        */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st115 VlvAct_stExActrTst;                                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input uint8 VLVACTEXACTRTEST_u8CdeTstActPrev;                             */
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*  output boolean VlvAct_bExActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*  output st118 VlvAct_stExActrTstLstSt;                                     */
/*  output uint8 VLVACTEXACTRTEST_u8CdeTstActPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidSetpointComp(void)
{
   boolean bLocalSrv_bActrTstExVVTEna;
   uint8   u8LocalVlvAct_stExActrTst;
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(VlvAct_stExActrTst, u8LocalVlvAct_stExActrTst);

   switch (u8LocalVlvAct_stExActrTst)
   {
      case VLV_EXACTRTST_IDLE:
         VLVACTEXACTRTEST_vidIdleStTrans();
         break;

      case VLV_EXACTRTST_PHASE1:
         VLVACTEXACTRTEST_vidPhase1Trans();
         break;

      case VLV_EXACTRTST_PHASE2:
         VLVACTEXACTRTEST_vidPhase2Trans();
         break;

      case VLV_EXACTRTST_PHASE3:
         VLVACTEXACTRTEST_vidPhase3Trans();
         break;

      case VLV_EXACTRTST_PHASE4:
         VLVACTEXACTRTEST_vidPhase4Trans();
         break;

      case VLV_EXACTRTST_PHASE5:
         VLVACTEXACTRTEST_vidPhase5Trans();
         break;

      case VLV_EXACTRTST_PHASE6:
         VLVACTEXACTRTEST_vidPhase6Trans();
         break;

      case VLV_EXACTRTST_PHASE7:
         VLVACTEXACTRTEST_vidPhase7Trans();
         break;

      case VLV_EXACTRTST_PHASE8:
         VLVACTEXACTRTEST_vidPhase8Trans();
         break;

      case VLV_EXACTRTST_PHASE9:
         VLVACTEXACTRTEST_vidPhase9Trans();
         break;

      case VLV_EXACTRTST_PHASE10:
         VLVACTEXACTRTEST_vidPhase10Trans();
         break;

      case VLV_EXACTRTST_END:
         VLVACTEXACTRTEST_vidEndStTrans();
         break;

      default:
         VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_IDLE);
         VEMS_vidSET(VlvAct_agExActrTestPosSp, 0);
         VEMS_vidSET(VlvAct_bExActrTestSpEndIdc, 0);
         VEMS_vidSET(VlvAct_bExActrTestNotRun, 1);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   VEMS_vidGET(VlvAct_stExActrTst, u8LocalVlvAct_stExActrTst);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrv_bActrTstExVVTEna);

   if (  (bLocalSrv_bActrTstExVVTEna != 0)
      && (u8LocalCode_test_action == VLVACTEXACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stExActrTstLstSt, u8LocalVlvAct_stExActrTst);
   }

   VLVACTEXACTRTEST_u8CdeTstActPrev = u8LocalCode_test_action;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidIdleStTrans                            */
/* !Description :  calcule de l'etat EXVLVACT_ACTRTST_IDLE                    */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input uint16 VlvAct_tiExActrTest1SplSp_C;                                 */
/*  input uint16 VlvAct_agExActrTestMinPosSp_C;                               */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output uint16 VlvAct_tiExActrTestSp;                                      */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidIdleStTrans(void)
{
   boolean bLocalSrv_bActrTstExVVTEna;
   uint16  u16LocalagExActrTestMinPos;


   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrv_bActrTstExVVTEna);

   if (bLocalSrv_bActrTstExVVTEna != 0)
   {
      VEMS_vidSET(VlvAct_bExActrTestNotRun, 0);
      VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_PHASE1);

      VlvAct_tiExActrTestSp = VlvAct_tiExActrTest1SplSp_C;

      u16LocalagExActrTestMinPos =
         (uint16)MATHSRV_udtMIN(VlvAct_agExActrTestMinPosSp_C, 1066);

      VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalagExActrTestMinPos);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidPhase1Trans                            */
/* !Description :  calcule de l'etat EXVLVACT_ACTRTST_PHASE1                  */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input uint8 VLVACTEXACTRTEST_u8CdeTstActPrev;                             */
/*  input uint16 VlvAct_tiExActrTestSp;                                       */
/*  input uint16 VlvAct_tiExActrTest2SplSp_C;                                 */
/*  input uint16 VlvAct_agExActrTestMinPosSp_C;                               */
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*  output boolean VlvAct_bExActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiExActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidPhase1Trans(void)
{
   boolean bLocalSrv_bActrTstExVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagExActrTestMinPos;
   sint32  s32LocalVar;


   VEMS_vidGET(Code_test_action, u8LocalCodeTestAction);
   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrv_bActrTstExVVTEna);

   if (  (bLocalSrv_bActrTstExVVTEna == 0)
      || (u8LocalCodeTestAction != VLVACTEXACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agExActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bExActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bExActrTestNotRun, 1);
   }
   else
   {
      s32LocalVar = (sint32)(VlvAct_tiExActrTestSp - 1);
      VlvAct_tiExActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar, 0);

      if (VlvAct_tiExActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_PHASE2);
         VlvAct_tiExActrTestSp = VlvAct_tiExActrTest2SplSp_C;
         u16LocalagExActrTestMinPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agExActrTestMinPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalagExActrTestMinPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidPhase2Trans                            */
/* !Description :  calcule de l'etat EXVLVACT_ACTRTST_PHASE2                  */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input uint8 VLVACTEXACTRTEST_u8CdeTstActPrev;                             */
/*  input uint16 VlvAct_tiExActrTestSp;                                       */
/*  input uint16 VlvAct_agExActrTestMaxPosSp_C;                               */
/*  input uint16 VlvAct_agExActrTestMinPosSp_C;                               */
/*  input uint16 VlvAct_tiExActrTest2SplSp_C;                                 */
/*  input uint16 VlvAct_tiExActrTest3SplSp_C;                                 */
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*  output boolean VlvAct_bExActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiExActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidPhase2Trans(void)
{
   boolean bLocalSrv_bActrTstExVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagExActrTestMaxPos;
   uint16  u16LocalExActrTestPosSp;
   uint32  u32LocalVar;
   sint32  s32LocalVar;


   VEMS_vidGET(Code_test_action, u8LocalCodeTestAction);
   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrv_bActrTstExVVTEna);

   if (  (bLocalSrv_bActrTstExVVTEna == 0)
      || (u8LocalCodeTestAction != VLVACTEXACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agExActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bExActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bExActrTestNotRun, 1);
   }
   else
   {
      s32LocalVar = (sint32)(VlvAct_tiExActrTestSp - 1);
      VlvAct_tiExActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar, 0);
      if (VlvAct_agExActrTestMaxPosSp_C >= VlvAct_agExActrTestMinPosSp_C)
      {
         u32LocalVar = (uint32)(( VlvAct_agExActrTestMaxPosSp_C
                                - VlvAct_agExActrTestMinPosSp_C)
                               * VlvAct_tiExActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiExActrTest2SplSp_C);

         if (VlvAct_agExActrTestMaxPosSp_C > u32LocalVar)
         {
            u32LocalVar = (VlvAct_agExActrTestMaxPosSp_C - u32LocalVar);
         }
         else
         {
            u32LocalVar = 0;
         }
      }
      else
      {
         u32LocalVar = (uint32)(( VlvAct_agExActrTestMinPosSp_C
                                - VlvAct_agExActrTestMaxPosSp_C)
                               * VlvAct_tiExActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiExActrTest2SplSp_C);
         u32LocalVar = (VlvAct_agExActrTestMaxPosSp_C + u32LocalVar);
      }

      u16LocalExActrTestPosSp = (uint16) MATHSRV_udtMIN(u32LocalVar, 1066);
      VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalExActrTestPosSp);

      if (VlvAct_tiExActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_PHASE3);
         VlvAct_tiExActrTestSp = VlvAct_tiExActrTest3SplSp_C;
         u16LocalagExActrTestMaxPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agExActrTestMaxPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalagExActrTestMaxPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidPhase3Trans                            */
/* !Description :  calcule de l'etat EXVLVACT_ACTRTST_PHASE3                  */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input uint8 VLVACTEXACTRTEST_u8CdeTstActPrev;                             */
/*  input uint16 VlvAct_tiExActrTestSp;                                       */
/*  input uint16 VlvAct_tiExActrTest4SplSp_C;                                 */
/*  input uint16 VlvAct_agExActrTestMaxPosSp_C;                               */
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*  output boolean VlvAct_bExActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiExActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidPhase3Trans(void)
{
   boolean bLocalSrv_bActrTstExVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagExActrTestMaxPos;
   sint32  s32LocalVar;


   VEMS_vidGET(Code_test_action, u8LocalCodeTestAction);
   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrv_bActrTstExVVTEna);

   if (  (bLocalSrv_bActrTstExVVTEna == 0)
      || (u8LocalCodeTestAction != VLVACTEXACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agExActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bExActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bExActrTestNotRun, 1);
   }
   else
   {
      s32LocalVar = (sint32)(VlvAct_tiExActrTestSp - 1);
      VlvAct_tiExActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar, 0);

      if (VlvAct_tiExActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_PHASE4);
         VlvAct_tiExActrTestSp = VlvAct_tiExActrTest4SplSp_C;
         u16LocalagExActrTestMaxPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agExActrTestMaxPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalagExActrTestMaxPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidPhase4Trans                            */
/* !Description :  calcule  de l'etat EXVLVACT_ACTRTST_PHASE4                 */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input uint8 VLVACTEXACTRTEST_u8CdeTstActPrev;                             */
/*  input uint16 VlvAct_tiExActrTestSp;                                       */
/*  input uint16 VlvAct_agExActrTestMaxPosSp_C;                               */
/*  input uint16 VlvAct_agExActrTestMinPosSp_C;                               */
/*  input uint16 VlvAct_tiExActrTest4SplSp_C;                                 */
/*  input uint16 VlvAct_tiExActrTest5SplSp_C;                                 */
/*  input uint16 VlvAct_tiExActrTest6SplSp_C;                                 */
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*  output boolean VlvAct_bExActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiExActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidPhase4Trans(void)
{
   boolean bLocalSrv_bActrTstExVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagExActrTestMinPos;
   uint32  u32LocalVlvAct_tiExActrTestSp;
   uint32  u32LocalVar;
   sint32  s32LocalVar;


   VEMS_vidGET(Code_test_action, u8LocalCodeTestAction);
   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrv_bActrTstExVVTEna);

   if (  (bLocalSrv_bActrTstExVVTEna == 0)
      || (u8LocalCodeTestAction != VLVACTEXACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agExActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bExActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bExActrTestNotRun, 1);
   }
   else
   {
      s32LocalVar = (sint32)(VlvAct_tiExActrTestSp - 1);
      VlvAct_tiExActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar,0);

      if (VlvAct_agExActrTestMaxPosSp_C < VlvAct_agExActrTestMinPosSp_C)
      {
         u32LocalVar = (uint32)( ( VlvAct_agExActrTestMinPosSp_C
                                 - VlvAct_agExActrTestMaxPosSp_C)
                               * VlvAct_tiExActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiExActrTest4SplSp_C);

         if (VlvAct_agExActrTestMinPosSp_C > u32LocalVar)
         {
            u32LocalVar = (VlvAct_agExActrTestMinPosSp_C - u32LocalVar);
         }
         else
         {
            u32LocalVar = 0;
         }
      }
      else
      {
         u32LocalVar = (uint32)( ( VlvAct_agExActrTestMaxPosSp_C
                                 - VlvAct_agExActrTestMinPosSp_C)
                               * VlvAct_tiExActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiExActrTest4SplSp_C);
         u32LocalVar = (VlvAct_agExActrTestMinPosSp_C + u32LocalVar);
      }

      u16LocalagExActrTestMinPos = (uint16) MATHSRV_udtMIN(u32LocalVar, 1066);

      if (VlvAct_tiExActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_PHASE5);

         u32LocalVlvAct_tiExActrTestSp = ( VlvAct_tiExActrTest5SplSp_C
                                         + VlvAct_tiExActrTest6SplSp_C);
         VlvAct_tiExActrTestSp =
            (uint16)MATHSRV_udtMIN(u32LocalVlvAct_tiExActrTestSp, 65535);
         u16LocalagExActrTestMinPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agExActrTestMinPosSp_C, 1066);
      }
      VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalagExActrTestMinPos);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidPhase5Trans                            */
/* !Description :  calcule  de l'etat EXVLVACT_ACTRTST_PHASE5                 */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input uint8 VLVACTEXACTRTEST_u8CdeTstActPrev;                             */
/*  input uint16 VlvAct_tiExActrTestSp;                                       */
/*  input uint16 VlvAct_tiExActrTest5SplSp_C;                                 */
/*  input uint16 VlvAct_agExActrTestMinPosSp_C;                               */
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*  output boolean VlvAct_bExActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiExActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidPhase5Trans(void)
{
   boolean bLocalSrv_bActrTstExVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagExActrTestMinPos;
   sint32  s32LocalVar;


   VEMS_vidGET(Code_test_action, u8LocalCodeTestAction);
   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrv_bActrTstExVVTEna);

   if (  (bLocalSrv_bActrTstExVVTEna == 0)
      || (u8LocalCodeTestAction != VLVACTEXACTRTEST_u8CdeTstActPrev))
   {
      VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agExActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bExActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bExActrTestNotRun, 1);
   }
   else
   {
      s32LocalVar = (sint32)(VlvAct_tiExActrTestSp - 1);
      VlvAct_tiExActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar, 0);

      if (VlvAct_tiExActrTestSp <= VlvAct_tiExActrTest5SplSp_C)
      {
         VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_PHASE6);
         s32LocalVar = (sint32)(VlvAct_tiExActrTestSp - 1);
         VlvAct_tiExActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar, 0);
         u16LocalagExActrTestMinPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agExActrTestMinPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalagExActrTestMinPos);
      }
   }
}
/*------------------------------- end of file --------------------------------*/
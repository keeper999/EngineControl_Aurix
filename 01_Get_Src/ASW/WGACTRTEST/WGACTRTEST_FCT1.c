/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WGACTRTEST                                              */
/* !Description     : WGACTRTEST component.                                   */
/*                                                                            */
/* !Module          : WGACTRTEST                                              */
/* !Description     : WASTE GATE ACTUATOR TEST                                */
/*                                                                            */
/* !File            : WGACTRTEST_FCT1.C                                       */
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
/*   1 / WGACTRTEST_vidInitOutput                                             */
/*   2 / WGACTRTEST_vidWgActrTest                                             */
/*   3 / WGACTRTEST_vidTestTrbActMgr                                          */
/*   4 / WGACTRTEST_vidState_IDLE                                             */
/*   5 / WGACTRTEST_vidState_PHASE1                                           */
/*   6 / WGACTRTEST_vidState_PHASE2                                           */
/*   7 / WGACTRTEST_vidState_PHASE3                                           */
/*   8 / WGACTRTEST_vidState_PHASE4                                           */
/*   9 / WGACTRTEST_vidState_PHASE5                                           */
/*   10 / WGACTRTEST_vidState_END                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5621841 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/WG/WGACTRTEST/WGACTRTEST_FCT1.C_$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   14 Oct 2013 $*/
/* $Author::   etsasson                               $$Date::   14 Oct 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "WGACTRTEST.h"
#include "WGACTRTEST_L.h"
#include "WGACTRTEST_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidInitOutput                                   */
/* !Description :  Initialisation des variables appelées au reset.            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Wg_bGapActrTst;                                            */
/*  output boolean Wg_bDynActrTst;                                            */
/*  output uint16 Wg_rOpTrbActrTst;                                           */
/*  output st126 Wg_stActrTst;                                                */
/*  output boolean Wg_bActrTstInProgs;                                        */
/*  output boolean Wg_bTestTrbTstCmpl;                                        */
/*  output uint8 ActrTstWg_Tempo;                                             */
/*  output uint8 Wg_tiTrbActPhaDrn;                                           */
/*  output uint8 Wg_noTrbTestChgtSp;                                          */
/*  output uint8 Wg_tiDlyTestTrbPha;                                          */
/*  output uint16 TrbAct_rOpTrbActTmp;                                        */
/*  output uint8 WGACTRTEST_u8Timer;                                          */
/*  output boolean WGACTRTEST_bTimeout;                                       */
/*  output boolean WGACTRTEST_bTrbDrnDynCompPrev;                             */
/*  output boolean WGACTRTEST_bTrbDrnStabCompPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidInitOutput(void)
{
   VEMS_vidSET(Wg_bGapActrTst, 0);
   VEMS_vidSET(Wg_bDynActrTst, 0);
   VEMS_vidSET(Wg_rOpTrbActrTst, 0);
   VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_IDLE);
   VEMS_vidSET(Wg_bActrTstInProgs, 0);
   VEMS_vidSET(Wg_bTestTrbTstCmpl, 0);
   VEMS_vidSET(ActrTstWg_Tempo, 0);
   Wg_tiTrbActPhaDrn = 0;
   Wg_noTrbTestChgtSp = 0;
   Wg_tiDlyTestTrbPha = 0;
   TrbAct_rOpTrbActTmp = 0;
   WGACTRTEST_u8Timer = 0;
   WGACTRTEST_bTimeout = 0;
   WGACTRTEST_bTrbDrnDynCompPrev = 0;
   WGACTRTEST_bTrbDrnStabCompPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidWgActrTest                                   */
/* !Description :  Contient les blocs de génération de consigne, de           */
/*                 détermination du comportement statique et dynamique du     */
/*                 wastegate.                                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void WGACTRTEST_vidTestTrbActMgr();                           */
/*  extf argret void WGACTRTEST_vidTrbDynTest();                              */
/*  extf argret void WGACTRTEST_vidTrbStabTest();                             */
/*  input uint16 TrbAct_rOpTrbAct;                                            */
/*  output uint16 TrbAct_rOpTrbActTmp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidWgActrTest(void)
{
   uint16 u16LocalTrbAct_rOpTrbAct;


   VEMS_vidGET(TrbAct_rOpTrbAct, u16LocalTrbAct_rOpTrbAct);
   WGACTRTEST_vidTestTrbActMgr();
   TrbAct_rOpTrbActTmp = (uint16)(u16LocalTrbAct_rOpTrbAct / 2);
   WGACTRTEST_vidTrbDynTest();
   WGACTRTEST_vidTrbStabTest();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidTestTrbActMgr                                */
/* !Description :  Inclut un flux d'état pour contrôler le processus de test  */
/*                 et génère une série de signaux progressifs comme consignes.*/
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void WGACTRTEST_vidState_IDLE();                              */
/*  extf argret void WGACTRTEST_vidState_PHASE1();                            */
/*  extf argret void WGACTRTEST_vidState_PHASE2();                            */
/*  extf argret void WGACTRTEST_vidState_PHASE3();                            */
/*  extf argret void WGACTRTEST_vidState_PHASE4();                            */
/*  extf argret void WGACTRTEST_vidState_PHASE5();                            */
/*  extf argret void WGACTRTEST_vidState_END();                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input st126 Wg_stActrTst;                                                 */
/*  output boolean WGACTRTEST_bTestTrbEna;                                    */
/*  output st126 Wg_stActrTst;                                                */
/*  output boolean Wg_bActrTstInProgs;                                        */
/*  output boolean Wg_bTestTrbTstCmpl;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidTestTrbActMgr(void)
{
   uint8  u8LocalCode_test_action;
   uint8  u8LocalSrv_bActrTstEna;
   uint8  u8LocalWg_stActrTst;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_bActrTstEna, u8LocalSrv_bActrTstEna);

   if (  (u8LocalCode_test_action == CODE_TEST_TURBO)
      && (u8LocalSrv_bActrTstEna != 0))
   {
      WGACTRTEST_bTestTrbEna = 1;
   }
   else
   {
      WGACTRTEST_bTestTrbEna = 0;
   }

   VEMS_vidGET(Wg_stActrTst, u8LocalWg_stActrTst);

   switch (u8LocalWg_stActrTst)
   {
      case WG_ACTRTST_IDLE:
         WGACTRTEST_vidState_IDLE();
         break;


      case WG_ACTRTST_PHASE1:
         WGACTRTEST_vidState_PHASE1();
         break;


      case WG_ACTRTST_PHASE2:
         WGACTRTEST_vidState_PHASE2();
         break;


      case WG_ACTRTST_PHASE3:
         WGACTRTEST_vidState_PHASE3();
         break;


      case WG_ACTRTST_PHASE4:
         WGACTRTEST_vidState_PHASE4();
         break;


      case WG_ACTRTST_PHASE5:
         WGACTRTEST_vidState_PHASE5();
         break;


      case WG_ACTRTST_END:
         WGACTRTEST_vidState_END();
         break;


      default:
         VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_IDLE);
         VEMS_vidSET(Wg_bActrTstInProgs, 0);
         VEMS_vidSET(Wg_bTestTrbTstCmpl, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidState_IDLE                                   */
/* !Description :  Inclut le traitement relatif à l'état WG_ACTRTST_IDLE      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean WGACTRTEST_bTestTrbEna;                                     */
/*  input uint8 Wg_tiDlyTestTrbActSp1_C;                                      */
/*  input uint16 Wg_rOpTestTrbActSpLo_C;                                      */
/*  output boolean Wg_bActrTstInProgs;                                        */
/*  output uint8 Wg_tiTrbActPhaDrn;                                           */
/*  output boolean Wg_bDynActrTst;                                            */
/*  output boolean Wg_bGapActrTst;                                            */
/*  output boolean Wg_bTestTrbTstCmpl;                                        */
/*  output st126 Wg_stActrTst;                                                */
/*  output uint8 Wg_tiDlyTestTrbPha;                                          */
/*  output uint16 Wg_rOpTrbActrTst;                                           */
/*  output uint8 Wg_noTrbTestChgtSp;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidState_IDLE(void)
{
   uint16 u16LocalWg_rOpTrbActrTst;


   if (WGACTRTEST_bTestTrbEna != 0)
   {
      VEMS_vidSET(Wg_bActrTstInProgs, 1);
      Wg_tiTrbActPhaDrn = 0;
      VEMS_vidSET(Wg_bDynActrTst, 0);
      VEMS_vidSET(Wg_bGapActrTst, 0);
      VEMS_vidSET(Wg_bTestTrbTstCmpl, 0);
      VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_PHASE1);
      Wg_tiDlyTestTrbPha =
            (uint8)MATHSRV_udtMIN(Wg_tiDlyTestTrbActSp1_C, 250);
      u16LocalWg_rOpTrbActrTst =
            (uint16)MATHSRV_udtMIN(Wg_rOpTestTrbActSpLo_C, 32768);
      VEMS_vidSET(Wg_rOpTrbActrTst, u16LocalWg_rOpTrbActrTst);
      Wg_noTrbTestChgtSp = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidState_PHASE1                                 */
/* !Description :  Inclut le traitement relatif à l'état WG_ACTRTST_PHASE1    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean WGACTRTEST_bTestTrbEna;                                     */
/*  input uint8 Wg_tiDlyTestTrbPha;                                           */
/*  input uint8 Wg_tiDlyTestTrbActSp2_C;                                      */
/*  input uint16 Wg_rOpTestTrbActSpMid_C;                                     */
/*  output st126 Wg_stActrTst;                                                */
/*  output boolean Wg_bActrTstInProgs;                                        */
/*  output boolean Wg_bTestTrbTstCmpl;                                        */
/*  output uint8 Wg_tiDlyTestTrbPha;                                          */
/*  output uint16 Wg_rOpTrbActrTst;                                           */
/*  output uint8 Wg_noTrbTestChgtSp;                                          */
/*  output uint8 Wg_tiTrbActPhaDrn;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidState_PHASE1(void)
{
   uint8  u8LocalWg_tiDlyTestTrbPha;
   uint16 u16LocalWg_rOpTrbActrTst;


   if (WGACTRTEST_bTestTrbEna == 0)
   {
      VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_IDLE);
      VEMS_vidSET(Wg_bActrTstInProgs, 0);
      VEMS_vidSET(Wg_bTestTrbTstCmpl, 0);
   }
   else
   {
      if (Wg_tiDlyTestTrbPha <= 1)
      {
         VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_PHASE2);
         Wg_tiDlyTestTrbPha =
            (uint8)MATHSRV_udtMIN(Wg_tiDlyTestTrbActSp2_C, 250);
         u16LocalWg_rOpTrbActrTst =
            (uint16)MATHSRV_udtMIN(Wg_rOpTestTrbActSpMid_C, 32768);
         VEMS_vidSET(Wg_rOpTrbActrTst, u16LocalWg_rOpTrbActrTst);
         Wg_noTrbTestChgtSp = 1;
      }
      else
      {
         u8LocalWg_tiDlyTestTrbPha = (uint8)(Wg_tiDlyTestTrbPha - 1);
         Wg_tiDlyTestTrbPha =
            (uint8)MATHSRV_udtMIN(u8LocalWg_tiDlyTestTrbPha, 250);
         Wg_tiTrbActPhaDrn = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidState_PHASE2                                 */
/* !Description :  Inclut le traitement relatif à l'état WG_ACTRTST_PHASE2    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean WGACTRTEST_bTestTrbEna;                                     */
/*  input uint8 Wg_tiDlyTestTrbPha;                                           */
/*  input uint8 Wg_tiDlyTestTrbActSp3_C;                                      */
/*  input uint16 Wg_rOpTestTrbActSpHi_C;                                      */
/*  input uint8 Wg_tiTrbActPhaDrn;                                            */
/*  output st126 Wg_stActrTst;                                                */
/*  output boolean Wg_bActrTstInProgs;                                        */
/*  output boolean Wg_bTestTrbTstCmpl;                                        */
/*  output uint8 Wg_tiDlyTestTrbPha;                                          */
/*  output uint16 Wg_rOpTrbActrTst;                                           */
/*  output uint8 Wg_tiTrbActPhaDrn;                                           */
/*  output uint8 Wg_noTrbTestChgtSp;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidState_PHASE2(void)
{
   uint8  u8LocalWg_tiDlyTestTrbPha;
   uint16 u16LocalWg_tiTrbActPhaDrn;
   uint16 u16LocalWg_rOpTrbActrTst;


   if (WGACTRTEST_bTestTrbEna == 0)
   {
      VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_IDLE);
      VEMS_vidSET(Wg_bActrTstInProgs, 0);
      VEMS_vidSET(Wg_bTestTrbTstCmpl, 0);
   }
   else
   {
      if (Wg_tiDlyTestTrbPha <= 1)
      {
         VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_PHASE3);
         Wg_tiDlyTestTrbPha =
            (uint8)MATHSRV_udtMIN(Wg_tiDlyTestTrbActSp3_C, 250);
         u16LocalWg_rOpTrbActrTst =
            (uint16)MATHSRV_udtMIN(Wg_rOpTestTrbActSpHi_C, 32768);
         VEMS_vidSET(Wg_rOpTrbActrTst, u16LocalWg_rOpTrbActrTst);
         Wg_tiTrbActPhaDrn = 0;
         Wg_noTrbTestChgtSp = 1;
      }
      else
      {
         u8LocalWg_tiDlyTestTrbPha = (uint8)(Wg_tiDlyTestTrbPha - 1);
         Wg_tiDlyTestTrbPha =
            (uint8)MATHSRV_udtMIN(u8LocalWg_tiDlyTestTrbPha, 250);
         u16LocalWg_tiTrbActPhaDrn = (uint16)(Wg_tiTrbActPhaDrn + 1);
         Wg_tiTrbActPhaDrn =
            (uint8)MATHSRV_udtMIN(u16LocalWg_tiTrbActPhaDrn, 250);
      }
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidState_PHASE3                                 */
/* !Description :  Inclut le traitement relatif à l'état WG_ACTRTST_PHASE3    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean WGACTRTEST_bTestTrbEna;                                     */
/*  input uint8 Wg_tiDlyTestTrbPha;                                           */
/*  input uint8 Wg_tiDlyTestTrbActSp4_C;                                      */
/*  input uint16 Wg_rOpTestTrbActSpMid_C;                                     */
/*  input uint8 Wg_tiTrbActPhaDrn;                                            */
/*  output st126 Wg_stActrTst;                                                */
/*  output boolean Wg_bActrTstInProgs;                                        */
/*  output boolean Wg_bTestTrbTstCmpl;                                        */
/*  output uint8 Wg_tiDlyTestTrbPha;                                          */
/*  output uint16 Wg_rOpTrbActrTst;                                           */
/*  output uint8 Wg_tiTrbActPhaDrn;                                           */
/*  output uint8 Wg_noTrbTestChgtSp;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidState_PHASE3(void)
{
   uint8  u8LocalWg_tiDlyTestTrbPha;
   uint16 u16LocalWg_tiTrbActPhaDrn;
   uint16 u16LocalWg_rOpTrbActrTst;


   if (WGACTRTEST_bTestTrbEna == 0)
   {
      VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_IDLE);
      VEMS_vidSET(Wg_bActrTstInProgs, 0);
      VEMS_vidSET(Wg_bTestTrbTstCmpl, 0);
   }
   else
   {
      if (Wg_tiDlyTestTrbPha <= 1)
      {
         VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_PHASE4);
         Wg_tiDlyTestTrbPha =
            (uint8)MATHSRV_udtMIN(Wg_tiDlyTestTrbActSp4_C, 250);
         u16LocalWg_rOpTrbActrTst =
            (uint16)MATHSRV_udtMIN(Wg_rOpTestTrbActSpMid_C, 32768);
         VEMS_vidSET(Wg_rOpTrbActrTst, u16LocalWg_rOpTrbActrTst);
         Wg_tiTrbActPhaDrn = 0;
         Wg_noTrbTestChgtSp = 2;
      }
      else
      {
         u8LocalWg_tiDlyTestTrbPha = (uint8)(Wg_tiDlyTestTrbPha - 1);
         Wg_tiDlyTestTrbPha =
            (uint8)MATHSRV_udtMIN(u8LocalWg_tiDlyTestTrbPha, 250);
         u16LocalWg_tiTrbActPhaDrn = (uint16)(Wg_tiTrbActPhaDrn + 1);
         Wg_tiTrbActPhaDrn =
            (uint8)MATHSRV_udtMIN(u16LocalWg_tiTrbActPhaDrn, 250);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidState_PHASE4                                 */
/* !Description :  Inclut le traitement relatif à l'état WG_ACTRTST_PHASE4    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean WGACTRTEST_bTestTrbEna;                                     */
/*  input uint8 Wg_tiDlyTestTrbPha;                                           */
/*  input uint8 Wg_tiDlyTestTrbActSp5_C;                                      */
/*  input uint16 Wg_rOpTestTrbActSpLo_C;                                      */
/*  input uint8 Wg_tiTrbActPhaDrn;                                            */
/*  output st126 Wg_stActrTst;                                                */
/*  output boolean Wg_bActrTstInProgs;                                        */
/*  output boolean Wg_bTestTrbTstCmpl;                                        */
/*  output uint8 Wg_tiDlyTestTrbPha;                                          */
/*  output uint16 Wg_rOpTrbActrTst;                                           */
/*  output uint8 Wg_tiTrbActPhaDrn;                                           */
/*  output uint8 Wg_noTrbTestChgtSp;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidState_PHASE4(void)
{
   uint8  u8LocalWg_tiDlyTestTrbPha;
   uint16 u16LocalWg_tiTrbActPhaDrn;
   uint16 u16LocalWg_rOpTrbActrTst;


   if (WGACTRTEST_bTestTrbEna == 0)
   {
      VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_IDLE);
      VEMS_vidSET(Wg_bActrTstInProgs, 0);
      VEMS_vidSET(Wg_bTestTrbTstCmpl, 0);
   }
   else
   {
      if (Wg_tiDlyTestTrbPha <= 1)
      {
         VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_PHASE5);
         Wg_tiDlyTestTrbPha =
            (uint8)MATHSRV_udtMIN(Wg_tiDlyTestTrbActSp5_C, 250);
         u16LocalWg_rOpTrbActrTst =
            (uint16)MATHSRV_udtMIN(Wg_rOpTestTrbActSpLo_C, 32768);
         VEMS_vidSET(Wg_rOpTrbActrTst, u16LocalWg_rOpTrbActrTst);
         Wg_tiTrbActPhaDrn = 0;
         Wg_noTrbTestChgtSp = 2;
      }
      else
      {
         u8LocalWg_tiDlyTestTrbPha = (uint8)(Wg_tiDlyTestTrbPha - 1);
         Wg_tiDlyTestTrbPha =
            (uint8)MATHSRV_udtMIN(u8LocalWg_tiDlyTestTrbPha, 250);
         u16LocalWg_tiTrbActPhaDrn = (uint16)(Wg_tiTrbActPhaDrn + 1);
         Wg_tiTrbActPhaDrn =
            (uint8)MATHSRV_udtMIN(u16LocalWg_tiTrbActPhaDrn, 250);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidState_PHASE5                                 */
/* !Description :  Inclut le traitement relatif à l'état WG_ACTRTST_PHASE5    */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean WGACTRTEST_bTestTrbEna;                                     */
/*  input uint8 Wg_tiDlyTestTrbPha;                                           */
/*  input uint8 ActrTstWg_Tempo_C;                                            */
/*  input uint8 Wg_tiTrbActPhaDrn;                                            */
/*  output st126 Wg_stActrTst;                                                */
/*  output boolean Wg_bActrTstInProgs;                                        */
/*  output boolean Wg_bTestTrbTstCmpl;                                        */
/*  output uint8 ActrTstWg_Tempo;                                             */
/*  output uint8 Wg_tiTrbActPhaDrn;                                           */
/*  output uint8 Wg_noTrbTestChgtSp;                                          */
/*  output uint8 Wg_tiDlyTestTrbPha;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidState_PHASE5(void)
{
   uint8  u8LocalWg_tiDlyTestTrbPha;
   uint8  u8LocalActrTstWg_Tempo;
   uint16 u16LocalWg_tiTrbActPhaDrn;


   if (WGACTRTEST_bTestTrbEna == 0)
   {
      VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_IDLE);
      VEMS_vidSET(Wg_bActrTstInProgs, 0);
      VEMS_vidSET(Wg_bTestTrbTstCmpl, 0);
   }
   else
   {
      if (Wg_tiDlyTestTrbPha <= 1)
      {
         VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_END);
         u8LocalActrTstWg_Tempo = (uint8)MATHSRV_udtMIN(ActrTstWg_Tempo_C, 250);
         VEMS_vidSET(ActrTstWg_Tempo, u8LocalActrTstWg_Tempo);
         VEMS_vidSET(Wg_bActrTstInProgs, 0);
         VEMS_vidSET(Wg_bTestTrbTstCmpl, 1);
         Wg_tiTrbActPhaDrn = 0;
         Wg_noTrbTestChgtSp = 0;
      }
      else
      {
         u8LocalWg_tiDlyTestTrbPha = (uint8)(Wg_tiDlyTestTrbPha - 1);
         Wg_tiDlyTestTrbPha =
            (uint8)MATHSRV_udtMIN(u8LocalWg_tiDlyTestTrbPha, 250);
         u16LocalWg_tiTrbActPhaDrn = (uint16)(Wg_tiTrbActPhaDrn + 1);
         Wg_tiTrbActPhaDrn =
            (uint8)MATHSRV_udtMIN(u16LocalWg_tiTrbActPhaDrn, 250);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidState_END                                    */
/* !Description :  Inclut le traitement relatif à l'état WG_ACTRTST_END       */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 ActrTstWg_Tempo;                                              */
/*  output st126 Wg_stActrTst;                                                */
/*  output boolean Wg_bActrTstInProgs;                                        */
/*  output boolean Wg_bTestTrbTstCmpl;                                        */
/*  output uint8 ActrTstWg_Tempo;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidState_END(void)
{
   uint8 u8LocalActrTstWg_Tempo;


   VEMS_vidGET(ActrTstWg_Tempo, u8LocalActrTstWg_Tempo);

   if (u8LocalActrTstWg_Tempo <= 1)
   {
      VEMS_vidSET(Wg_stActrTst, WG_ACTRTST_IDLE);
      VEMS_vidSET(Wg_bActrTstInProgs, 0);
      VEMS_vidSET(Wg_bTestTrbTstCmpl, 0);
   }
   else
   {
      u8LocalActrTstWg_Tempo = (uint8)(u8LocalActrTstWg_Tempo - 1);
      u8LocalActrTstWg_Tempo =
         (uint8)MATHSRV_udtMIN(u8LocalActrTstWg_Tempo, 250);
      VEMS_vidSET(ActrTstWg_Tempo, u8LocalActrTstWg_Tempo);
   }
}

/*---------------------------- end of file -----------------------------------*/
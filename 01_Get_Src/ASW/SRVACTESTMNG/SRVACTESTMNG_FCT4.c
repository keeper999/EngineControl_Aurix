/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SRVACTESTMNG                                            */
/* !Description     : SRVACTESTMNG component.                                 */
/*                                                                            */
/* !Module          : SRVACTESTMNG                                            */
/* !Description     : MANAGEUR DES TESTS ACTIONNEURS.                         */
/*                                                                            */
/* !File            : SRVACTESTMNG_FCT4.C                                     */
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
/*   1 / SRVACTESTMNG_vidActrTst1Res                                          */
/*   2 / SRVACTESTMNG_vidActrTst2Res                                          */
/*   3 / SRVACTESTMNG_vidActrTst3Res                                          */
/*   4 / SRVACTESTMNG_vidActrTst4Res                                          */
/*   5 / SRVACTESTMNG_vidTestDftCdn                                           */
/*   6 / SRVACTESTMNG_vidActrTstCmpfollow                                     */
/*   7 / SRVACTESTMNG_ThMgtECTTst                                             */
/*   8 / SRVACTESTMNG_HPPmpTst                                                */
/*   9 / SRVACTESTMNG_vidFarSpTst                                             */
/*   10 / SRVACTESTMNG_vidCTPtst                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5074355 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SRVACTESTMNG/SRVACTESTMNG_FCT4.c$*/
/* $Revision::   1.6      $$Author::   pbakabad       $$Date::   Apr 11 2013 $*/
/* $Author::   pbakabad                               $$Date::   Apr 11 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SRVACTESTMNG.h"
#include "SRVACTESTMNG_L.h"
#include "SRVACTESTMNG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidActrTst1Res                                */
/* !Description :  Fonction qui permet la gestion des tests actionneurs.      */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_06188_002.02                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SRVACTESTMNG_vidInj1Tst();                               */
/*  extf argret void SRVACTESTMNG_vidInj2Tst();                               */
/*  extf argret void SRVACTESTMNG_vidInj3Tst();                               */
/*  extf argret void SRVACTESTMNG_vidInj4Tst();                               */
/*  extf argret void SRVACTESTMNG_vidCoil_1Tst();                             */
/*  extf argret void SRVACTESTMNG_vidCoil_2Tst();                             */
/*  extf argret void SRVACTESTMNG_vidCoil_3Tst();                             */
/*  extf argret void SRVACTESTMNG_vidCoil_4Tst();                             */
/*  input boolean Inj_bInj1TstCmpl;                                           */
/*  input boolean Inj_bInj2TstCmpl;                                           */
/*  input boolean Inj_bInj3TstCmpl;                                           */
/*  input boolean Inj_bInj4TstCmpl;                                           */
/*  input boolean IgCmd_bCoil1TstCmpl;                                        */
/*  input boolean IgCmd_bCoil2TstCmpl;                                        */
/*  input boolean IgCmd_bCoil3TstCmpl;                                        */
/*  input boolean IgCmd_bCoil4TstCmpl;                                        */
/*  input boolean SRVACTESTMNG_bInj1TstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bInj2TstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bInj3TstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bInj4TstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bCoil1TstCmplPrev;                             */
/*  input boolean SRVACTESTMNG_bCoil2TstCmplPrev;                             */
/*  input boolean SRVACTESTMNG_bCoil3TstCmplPrev;                             */
/*  input boolean SRVACTESTMNG_bCoil4TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bInj1TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bInj2TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bInj3TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bInj4TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bCoil1TstCmplPrev;                            */
/*  output boolean SRVACTESTMNG_bCoil2TstCmplPrev;                            */
/*  output boolean SRVACTESTMNG_bCoil3TstCmplPrev;                            */
/*  output boolean SRVACTESTMNG_bCoil4TstCmplPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidActrTst1Res(void)
{
   boolean bLocalInj_bInj1TstCmpl;
   boolean bLocalInj_bInj2TstCmpl;
   boolean bLocalInj_bInj3TstCmpl;
   boolean bLocalInj_bInj4TstCmpl;
   boolean bLocalIgCmd_bCoil_1TstCmpl;
   boolean bLocalIgCmd_bCoil2TstCmpl;
   boolean bLocalIgCmd_bCoil3TstCmpl;
   boolean bLocalIgCmd_bCoil4TstCmpl;


   VEMS_vidGET(Inj_bInj1TstCmpl, bLocalInj_bInj1TstCmpl);
   VEMS_vidGET(Inj_bInj2TstCmpl, bLocalInj_bInj2TstCmpl);
   VEMS_vidGET(Inj_bInj3TstCmpl, bLocalInj_bInj3TstCmpl);
   VEMS_vidGET(Inj_bInj4TstCmpl, bLocalInj_bInj4TstCmpl);
   VEMS_vidGET(IgCmd_bCoil1TstCmpl, bLocalIgCmd_bCoil_1TstCmpl);
   VEMS_vidGET(IgCmd_bCoil2TstCmpl, bLocalIgCmd_bCoil2TstCmpl);
   VEMS_vidGET(IgCmd_bCoil3TstCmpl, bLocalIgCmd_bCoil3TstCmpl);
   VEMS_vidGET(IgCmd_bCoil4TstCmpl, bLocalIgCmd_bCoil4TstCmpl);

   if (  (bLocalInj_bInj1TstCmpl != 0)
      && (SRVACTESTMNG_bInj1TstCmplPrev == 0))
   {
      SRVACTESTMNG_vidInj1Tst();
   }
   if (  (bLocalInj_bInj2TstCmpl != 0)
      && (SRVACTESTMNG_bInj2TstCmplPrev == 0))
   {
      SRVACTESTMNG_vidInj2Tst();
   }
   if (  (bLocalInj_bInj3TstCmpl != 0)
      && (SRVACTESTMNG_bInj3TstCmplPrev == 0))
   {
      SRVACTESTMNG_vidInj3Tst();
   }
   if (  (bLocalInj_bInj4TstCmpl != 0)
      && (SRVACTESTMNG_bInj4TstCmplPrev == 0))
   {
      SRVACTESTMNG_vidInj4Tst();
   }
   if (  (bLocalIgCmd_bCoil_1TstCmpl != 0)
      && (SRVACTESTMNG_bCoil1TstCmplPrev == 0))
   {
      SRVACTESTMNG_vidCoil_1Tst();
   }
   if (  (bLocalIgCmd_bCoil2TstCmpl != 0)
      && (SRVACTESTMNG_bCoil2TstCmplPrev == 0))
   {
      SRVACTESTMNG_vidCoil_2Tst();
   }
   if (  (bLocalIgCmd_bCoil3TstCmpl != 0)
      && (SRVACTESTMNG_bCoil3TstCmplPrev == 0))
   {
      SRVACTESTMNG_vidCoil_3Tst();
   }
   if (  (bLocalIgCmd_bCoil4TstCmpl != 0)
      && (SRVACTESTMNG_bCoil4TstCmplPrev == 0))
   {
      SRVACTESTMNG_vidCoil_4Tst();
   }

   SRVACTESTMNG_bInj1TstCmplPrev = bLocalInj_bInj1TstCmpl;
   SRVACTESTMNG_bInj2TstCmplPrev = bLocalInj_bInj2TstCmpl;
   SRVACTESTMNG_bInj3TstCmplPrev = bLocalInj_bInj3TstCmpl;
   SRVACTESTMNG_bInj4TstCmplPrev = bLocalInj_bInj4TstCmpl;
   SRVACTESTMNG_bCoil1TstCmplPrev = bLocalIgCmd_bCoil_1TstCmpl;
   SRVACTESTMNG_bCoil2TstCmplPrev = bLocalIgCmd_bCoil2TstCmpl;
   SRVACTESTMNG_bCoil3TstCmplPrev = bLocalIgCmd_bCoil3TstCmpl;
   SRVACTESTMNG_bCoil4TstCmplPrev = bLocalIgCmd_bCoil4TstCmpl;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidActrTst2Res                                */
/* !Description :  Fonction qui permet la gestion des tests actionneurs.      */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_06188_002.02                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SRVACTESTMNG_vidHeatSenO2DsTst();                        */
/*  extf argret void SRVACTESTMNG_vidHeatSenO2UsTst();                        */
/*  extf argret void SRVACTESTMNG_vidPwrRlyTst();                             */
/*  extf argret void SRVACTESTMNG_vidCstrTst();                               */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf argret void SRVACTESTMNG_vidThrTst();                                */
/*  input boolean HeatSenO2_bDsTstCmpl;                                       */
/*  input boolean SRVACTESTMNG_bDsTstCmplPrev;                                */
/*  input boolean HeatSenO2_bUsTstCmpl;                                       */
/*  input boolean SRVACTESTMNG_bUsTstCmplPrev;                                */
/*  input boolean Rly_bActrTstCmpl;                                           */
/*  input boolean SRVACTESTMNG_bActrTstCmplPrev;                              */
/*  input boolean Cstr_bPurgTstCmpl;                                          */
/*  input boolean SRVACTESTMNG_bPurgTstCmplPrev;                              */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Thr_bThrTstCmpl;                                            */
/*  input boolean SRVACTESTMNG_bThrTstCmplPrev;                               */
/*  output boolean SRVACTESTMNG_bDsTstCmplPrev;                               */
/*  output boolean SRVACTESTMNG_bUsTstCmplPrev;                               */
/*  output boolean SRVACTESTMNG_bActrTstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bPurgTstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bThrTstCmplPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidActrTst2Res(void)
{
   boolean bLocalHeatSenO2_bDsTstCmpl;
   boolean bLocalHeatSenO2_bUsTstCmpl;
   boolean bLocalRly_bActrTstCmpl;
   boolean bLocalCstr_bPurgTstCmpl;
   boolean bLocalThr_bThrTstCmpl;
   uint8   u8LocalCode_test_action;
   uint8   LocalstDgoOvld_ThrCmd;


   VEMS_vidGET(HeatSenO2_bDsTstCmpl, bLocalHeatSenO2_bDsTstCmpl);
   if (  (bLocalHeatSenO2_bDsTstCmpl != 0)
      && (SRVACTESTMNG_bDsTstCmplPrev == 0))
   {
      SRVACTESTMNG_vidHeatSenO2DsTst();
   }
   VEMS_vidGET(HeatSenO2_bUsTstCmpl, bLocalHeatSenO2_bUsTstCmpl);
   if (  (bLocalHeatSenO2_bUsTstCmpl != 0)
      && (SRVACTESTMNG_bUsTstCmplPrev == 0))
   {
      SRVACTESTMNG_vidHeatSenO2UsTst();
   }
   VEMS_vidGET(Rly_bActrTstCmpl, bLocalRly_bActrTstCmpl);
   if (  (bLocalRly_bActrTstCmpl != 0)
      && (SRVACTESTMNG_bActrTstCmplPrev == 0))
   {
      SRVACTESTMNG_vidPwrRlyTst();
   }
   VEMS_vidGET(Cstr_bPurgTstCmpl, bLocalCstr_bPurgTstCmpl);
   if (  (bLocalCstr_bPurgTstCmpl != 0)
      && (SRVACTESTMNG_bPurgTstCmplPrev == 0))
   {
      SRVACTESTMNG_vidCstrTst();
   }

   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Thr_bThrTstCmpl, bLocalThr_bThrTstCmpl);
   LocalstDgoOvld_ThrCmd = GDGAR_tenuGetStDgo(GD_DFT_OVLD_THRCMD);
   if (  (  (u8LocalCode_test_action == CODE_TEST_PAP_MOT)
         && (LocalstDgoOvld_ThrCmd == GDU_ETAT_PRESENT))
      || (  (bLocalThr_bThrTstCmpl != 0)
         && (SRVACTESTMNG_bThrTstCmplPrev == 0)))
   {
      SRVACTESTMNG_vidThrTst();
   }

   SRVACTESTMNG_bDsTstCmplPrev = bLocalHeatSenO2_bDsTstCmpl;
   SRVACTESTMNG_bUsTstCmplPrev = bLocalHeatSenO2_bUsTstCmpl;
   SRVACTESTMNG_bActrTstCmplPrev = bLocalRly_bActrTstCmpl;
   SRVACTESTMNG_bPurgTstCmplPrev = bLocalCstr_bPurgTstCmpl;
   SRVACTESTMNG_bThrTstCmplPrev = bLocalThr_bThrTstCmpl;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidActrTst3Res                                */
/* !Description :  Fonction qui permet la gestion des tests actionneurs.      */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_06188_002.02                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SRVACTESTMNG_vidB2FanHiSpdTst();                         */
/*  extf argret void SRVACTESTMNG_vidB2FanLoSpdTst();                         */
/*  extf argret void SRVACTESTMNG_vidCFanTst();                               */
/*  extf argret void SRVACTESTMNG_vidInVVTTst();                              */
/*  extf argret void SRVACTESTMNG_vidExVVTTst();                              */
/*  input boolean CoFan_bB2HiSpdTstCmpl;                                      */
/*  input boolean SRVACTESTMNG_bB2HiSpdTstCmplPrev;                           */
/*  input boolean CoFan_bB2LoSpdTstCmpl;                                      */
/*  input boolean SRVACTESTMNG_bB2loSpdTstCmplPrev;                           */
/*  input boolean CoFan_bCTstCmpl;                                            */
/*  input boolean SRVACTESTMNG_bCTstCmplPrev;                                 */
/*  input uint8 Code_test_action;                                             */
/*  output boolean SRVACTESTMNG_bB2HiSpdTstCmplPrev;                          */
/*  output boolean SRVACTESTMNG_bB2loSpdTstCmplPrev;                          */
/*  output boolean SRVACTESTMNG_bCTstCmplPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidActrTst3Res(void)
{
   boolean bLocalCoFan_bB2HiSpdTstCmpl;
   boolean bLocalCoFan_bB2LoSpdTstCmpl;
   boolean bLocalCoFan_bCTstCmpl;
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(CoFan_bB2HiSpdTstCmpl, bLocalCoFan_bB2HiSpdTstCmpl);
   if (  (bLocalCoFan_bB2HiSpdTstCmpl != 0)
      && (SRVACTESTMNG_bB2HiSpdTstCmplPrev == 0))
   {
      SRVACTESTMNG_vidB2FanHiSpdTst();
   }
   VEMS_vidGET(CoFan_bB2LoSpdTstCmpl, bLocalCoFan_bB2LoSpdTstCmpl);
   if (  (bLocalCoFan_bB2LoSpdTstCmpl != 0)
      && (SRVACTESTMNG_bB2loSpdTstCmplPrev == 0))
   {
      SRVACTESTMNG_vidB2FanLoSpdTst();
   }
   VEMS_vidGET(CoFan_bCTstCmpl, bLocalCoFan_bCTstCmpl);
   if (  (bLocalCoFan_bCTstCmpl != 0)
      && (SRVACTESTMNG_bCTstCmplPrev == 0))
   {
      SRVACTESTMNG_vidCFanTst();
   }

   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   if (u8LocalCode_test_action == CODE_TEST_VVT_ADM)
   {
      SRVACTESTMNG_vidInVVTTst();
   }
   else
   {
      if (u8LocalCode_test_action == CODE_TEST_VVT_ECH)
      {
         SRVACTESTMNG_vidExVVTTst();
      }
   }

   SRVACTESTMNG_bB2HiSpdTstCmplPrev = bLocalCoFan_bB2HiSpdTstCmpl;
   SRVACTESTMNG_bB2loSpdTstCmplPrev = bLocalCoFan_bB2LoSpdTstCmpl;
   SRVACTESTMNG_bCTstCmplPrev = bLocalCoFan_bCTstCmpl;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidActrTst4Res                                */
/* !Description :  Permet la détection des défauts lors du dernier test       */
/*                 actionneur.                                                */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_06188_002.02                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SRVACTESTMNG_vidBlowBy1();                               */
/*  extf argret void SRVACTESTMNG_vidBlowBy2();                               */
/*  extf argret void SRVACTESTMNG_PropFuPmp();                                */
/*  extf argret void SRVACTESTMNG_CtlPmpReq();                                */
/*  extf argret void SRVACTESTMNG_vidThMgt();                                 */
/*  extf argret void SRVACTESTMNG_WgcCmd();                                   */
/*  extf argret void SRVACTESTMNG_ThMgtECTTst();                              */
/*  extf argret void SRVACTESTMNG_HPPmpTst();                                 */
/*  extf argret void SRVACTESTMNG_vidDumpValveTst();                          */
/*  extf argret void SRVACTESTMNG_vidFarSpTst();                              */
/*  extf argret void SRVACTESTMNG_vidCTPtst();                                */
/*  extf argret void SRVACTESTMNG_vidMEAPtst();                               */
/*  input boolean Oil_bBlowByTstCmpl;                                         */
/*  input boolean FuPmp_bFuTnkPmpTstCmpl;                                     */
/*  input boolean IgCmd_bCtlPmpReqTstCmpl;                                    */
/*  input boolean ThMgt_bTrbWaPmpTstCmpl;                                     */
/*  input boolean Wg_bTestTrbTstCmpl;                                         */
/*  input boolean ThMgt_bECTTstCmpl;                                          */
/*  input boolean ActrTstHPPmp_bActrTstCmpl;                                  */
/*  input uint8 Code_test_action;                                             */
/*  input boolean DmpVlv_bActrTstCmpl;                                        */
/*  input boolean CTP_bActrTstCmpl;                                           */
/*  input boolean FarSp_bActrTstCmpl;                                         */
/*  input boolean Meap_bActrTstCmpl;                                          */
/*  input boolean SRVACTESTMNG_bOil_bBlowByPrev;                              */
/*  input boolean SRVACTESTMNG_bFuTnkPmpTstCmplPv;                            */
/*  input boolean SRVACTESTMNG_bCtlPmpReqTstCmplPv;                           */
/*  input boolean SRVACTESTMNG_bTrbWaPmpTstCmplPv;                            */
/*  input boolean SRVACTESTMNG_bTestTrbTstCmplPv;                             */
/*  input boolean SRVACTESTMNG_bECTTstCmplPrev;                               */
/*  input boolean SRVACTESTMNG_bActrTstCmplPrev1;                             */
/*  input boolean SRVACTESTMNG_bVlvTstCmplPrev;                               */
/*  input boolean SRVACTESTMNG_bSp_bActrTstPrev;                              */
/*  input boolean SRVACTESTMNG_bCTP_TstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bMeap_TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bOil_bBlowByPrev;                             */
/*  output boolean SRVACTESTMNG_bFuTnkPmpTstCmplPv;                           */
/*  output boolean SRVACTESTMNG_bCtlPmpReqTstCmplPv;                          */
/*  output boolean SRVACTESTMNG_bTrbWaPmpTstCmplPv;                           */
/*  output boolean SRVACTESTMNG_bTestTrbTstCmplPv;                            */
/*  output boolean SRVACTESTMNG_bECTTstCmplPrev;                              */
/*  output boolean SRVACTESTMNG_bActrTstCmplPrev1;                            */
/*  output boolean SRVACTESTMNG_bVlvTstCmplPrev;                              */
/*  output boolean SRVACTESTMNG_bSp_bActrTstPrev;                             */
/*  output boolean SRVACTESTMNG_bCTP_TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bMeap_TstCmplPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidActrTst4Res(void)
{
   boolean bLocalOil_bBlowByTstCmpl;
   boolean bLocalFuPmp_bFuTnkPmpTstCmpl;
   boolean bLocalIgCmd_bCtlPmpReqTstCmpl;
   boolean bLocalThMgt_bTrbWaPmpTstCmpl;
   boolean bLocalWg_bTestTrbTstCmpl;
   boolean bLocalThMgt_bECTTstCmpl;
   boolean bLocalActrTstHPPmp_bActrTstCmpl;
   boolean bLocalDmpVlv_bActrTstCmpl;
   boolean bLocalCTP_bActrTstCmpl;
   boolean bLocalFarSp_bActrTstCmpl;
   boolean bLocalMeap_bActrTstCmpl;
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(Oil_bBlowByTstCmpl, bLocalOil_bBlowByTstCmpl);
   VEMS_vidGET(FuPmp_bFuTnkPmpTstCmpl, bLocalFuPmp_bFuTnkPmpTstCmpl);
   VEMS_vidGET(IgCmd_bCtlPmpReqTstCmpl, bLocalIgCmd_bCtlPmpReqTstCmpl);
   VEMS_vidGET(ThMgt_bTrbWaPmpTstCmpl, bLocalThMgt_bTrbWaPmpTstCmpl);
   VEMS_vidGET(Wg_bTestTrbTstCmpl, bLocalWg_bTestTrbTstCmpl);
   VEMS_vidGET(ThMgt_bECTTstCmpl, bLocalThMgt_bECTTstCmpl);
   VEMS_vidGET(ActrTstHPPmp_bActrTstCmpl, bLocalActrTstHPPmp_bActrTstCmpl);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(DmpVlv_bActrTstCmpl, bLocalDmpVlv_bActrTstCmpl);
   VEMS_vidGET(CTP_bActrTstCmpl, bLocalCTP_bActrTstCmpl);
   VEMS_vidGET(FarSp_bActrTstCmpl, bLocalFarSp_bActrTstCmpl);
   VEMS_vidGET(Meap_bActrTstCmpl, bLocalMeap_bActrTstCmpl);

   if(  (bLocalOil_bBlowByTstCmpl !=0)
     && (SRVACTESTMNG_bOil_bBlowByPrev == 0))
   {
      if(u8LocalCode_test_action == CODE_TEST_BLOW_BY_1)
      {
         SRVACTESTMNG_vidBlowBy1();
      }
      if(u8LocalCode_test_action == CODE_TEST_BLOW_BY_2)
      {
         SRVACTESTMNG_vidBlowBy2();
      }
   }
   if(  (bLocalFuPmp_bFuTnkPmpTstCmpl !=0)
     && (SRVACTESTMNG_bFuTnkPmpTstCmplPv == 0))
   {
      SRVACTESTMNG_PropFuPmp();
   }
   if(  (bLocalIgCmd_bCtlPmpReqTstCmpl !=0)
     && (SRVACTESTMNG_bCtlPmpReqTstCmplPv == 0))
   {
      SRVACTESTMNG_CtlPmpReq();
   }
   if(  (bLocalThMgt_bTrbWaPmpTstCmpl !=0)
     && (SRVACTESTMNG_bTrbWaPmpTstCmplPv == 0))
   {
      SRVACTESTMNG_vidThMgt();
   }
   if(  (bLocalWg_bTestTrbTstCmpl !=0)
     && (SRVACTESTMNG_bTestTrbTstCmplPv == 0))
   {
      SRVACTESTMNG_WgcCmd();
   }
   if (  (bLocalThMgt_bECTTstCmpl != 0)
      && (SRVACTESTMNG_bECTTstCmplPrev == 0))
   {
      SRVACTESTMNG_ThMgtECTTst();
   }
   if (  (bLocalActrTstHPPmp_bActrTstCmpl != 0)
      && (SRVACTESTMNG_bActrTstCmplPrev1 == 0))
   {
      SRVACTESTMNG_HPPmpTst();
   }
   if (  (bLocalDmpVlv_bActrTstCmpl != 0)
      && (SRVACTESTMNG_bVlvTstCmplPrev == 0))
   {
      SRVACTESTMNG_vidDumpValveTst();
   }
   if (  (bLocalFarSp_bActrTstCmpl != 0)
      && (SRVACTESTMNG_bSp_bActrTstPrev == 0))
   {
      SRVACTESTMNG_vidFarSpTst();
   }
   if ( (bLocalCTP_bActrTstCmpl != 0)
      &&(SRVACTESTMNG_bCTP_TstCmplPrev == 0))
   {
      SRVACTESTMNG_vidCTPtst();
   }
   if ( (bLocalMeap_bActrTstCmpl != 0)
      && (SRVACTESTMNG_bMeap_TstCmplPrev == 0))
   {
      SRVACTESTMNG_vidMEAPtst();
   }
   SRVACTESTMNG_bOil_bBlowByPrev = bLocalOil_bBlowByTstCmpl;
   SRVACTESTMNG_bFuTnkPmpTstCmplPv = bLocalFuPmp_bFuTnkPmpTstCmpl;
   SRVACTESTMNG_bCtlPmpReqTstCmplPv = bLocalIgCmd_bCtlPmpReqTstCmpl;
   SRVACTESTMNG_bTrbWaPmpTstCmplPv = bLocalThMgt_bTrbWaPmpTstCmpl;
   SRVACTESTMNG_bTestTrbTstCmplPv = bLocalWg_bTestTrbTstCmpl;
   SRVACTESTMNG_bECTTstCmplPrev = bLocalThMgt_bECTTstCmpl;
   SRVACTESTMNG_bActrTstCmplPrev1 = bLocalActrTstHPPmp_bActrTstCmpl;
   SRVACTESTMNG_bVlvTstCmplPrev = bLocalDmpVlv_bActrTstCmpl;
   SRVACTESTMNG_bSp_bActrTstPrev = bLocalFarSp_bActrTstCmpl;
   SRVACTESTMNG_bCTP_TstCmplPrev = bLocalCTP_bActrTstCmpl;
   SRVACTESTMNG_bMeap_TstCmplPrev = bLocalMeap_bActrTstCmpl;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidTestDftCdn                                 */
/* !Description :  Production des motifs d'arrêt ou de non lancement du test  */
/*                 actionneur moteur non tournant et tournant.                */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_06188_001.02                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Srv_stActrTstCode;                                            */
/*  input boolean Srv_bTestCdn;                                               */
/*  input boolean Srv_bTestCdnRunning;                                        */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Ext_bCluPedPrss;                                            */
/*  input boolean Ext_bBrkPedPrss;                                            */
/*  input boolean SRVACTESTMNG_bDftpFu;                                       */
/*  input boolean SRVACTESTMNG_bDftInjDone;                                   */
/*  input boolean SRVACTESTMNG_bDftVehicle_speed;                             */
/*  input boolean SRVACTESTMNG_bDftUbat;                                      */
/*  input boolean SRVACTESTMNG_bDftGMVact;                                    */
/*  input boolean SRVACTESTMNG_bDftRegime_moteur;                             */
/*  input boolean SRVACTESTMNG_bDftReg_mot_Running;                           */
/*  input boolean SRVACTESTMNG_bDftacc_pedal;                                 */
/*  input boolean SRVACTESTMNG_bDftgear_box;                                  */
/*  input boolean SRVACTESTMNG_bDfttCoMes;                                    */
/*  input boolean SRVACTESTMNG_bDftTstHPPmp;                                  */
/*  input boolean SRVACTESTMNG_bDftPrailInc;                                  */
/*  input boolean SRVACTESTMNG_bDftPrailMax;                                  */
/*  input st93 ActrTstMng_stActrTst;                                          */
/*  input uint8 Srv_stTestDftCdn;                                             */
/*  output uint8 Srv_stTestDftCdn;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidTestDftCdn(void)
{
   boolean bLocalBitTest;
   boolean bLocalNS_bDftECU_WkuMain;
   boolean bLocalTestSrv_stActrTstCode;
   boolean bLocalSrv_bTestCdn;
   boolean bLocalSrv_bTestCdnRunning;
   boolean bLocalExt_bCluPedPrss;
   boolean bLocalExt_bBrkPedPrss;
   uint8   u8LocalSrv_stTestDftCdn;
   uint8   u8LocalSrv_stActrTstCode;
   uint8   u8Localoutput;


   bLocalBitTest = 0;

   VEMS_vidGET(Srv_stActrTstCode, u8LocalSrv_stActrTstCode);
   VEMS_vidGET(Srv_bTestCdn, bLocalSrv_bTestCdn);
   VEMS_vidGET(Srv_bTestCdnRunning, bLocalSrv_bTestCdnRunning);
   VEMS_vidGET(ECU_bWkuMain, bLocalNS_bDftECU_WkuMain);
   VEMS_vidGET(Ext_bCluPedPrss, bLocalExt_bCluPedPrss);
   VEMS_vidGET(Ext_bBrkPedPrss, bLocalExt_bBrkPedPrss);

   if (  (u8LocalSrv_stActrTstCode == CODE_TEST_VVT_ECH)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_VVT_ADM)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_TURBO)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_HPPMP)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_FARSP))
   {
      bLocalTestSrv_stActrTstCode = 1;
   }
   else
   {
      bLocalTestSrv_stActrTstCode = 0;
   }

   if (  (  (bLocalTestSrv_stActrTstCode != 0)
         && (bLocalSrv_bTestCdnRunning != 0))
      || (  (bLocalTestSrv_stActrTstCode == 0)
         && (bLocalSrv_bTestCdn != 0)))
   {
      u8Localoutput = TEST_CONDITION_OK;
   }
   else
   {
      if (bLocalNS_bDftECU_WkuMain == 0)
      {
         u8Localoutput = ECU_NOK;
      }
      else
      {
         if (SRVACTESTMNG_bDftpFu != 0)
         {
            u8Localoutput = PRES_FUEL_NOK;
         }
         else
         {
            if (SRVACTESTMNG_bDftInjDone != 0)
            {
               u8Localoutput = INJDONE_BOBINE_NOK;
            }
            else
            {
               if (SRVACTESTMNG_bDftVehicle_speed != 0)
               {
                  u8Localoutput = VEHICLE_SPEED_NOK;
               }
               else
               {
                  if (SRVACTESTMNG_bDftUbat != 0)
                  {
                     u8Localoutput = UBAT_NOK;
                  }
                  else
                  {
                     if (SRVACTESTMNG_bDftGMVact != 0)
                     {
                        u8Localoutput = GMV_ACT_TEST_CTP;
                     }
                     else
                     {
                        if (  (  (bLocalTestSrv_stActrTstCode != 0)
                              && (SRVACTESTMNG_bDftRegime_moteur != 0))
                           || (  (bLocalTestSrv_stActrTstCode == 0)
                              && (SRVACTESTMNG_bDftReg_mot_Running != 0)))
                        {
                           u8Localoutput = REGIME_MOTEUR_NOK;
                        }
                        else
                        {
                           if (  (bLocalExt_bCluPedPrss != 0)
                              && (bLocalTestSrv_stActrTstCode != 0))
                           {
                              u8Localoutput = CLUTCH_PED_NOK;
                           }
                           else
                           {
                              if (  (bLocalExt_bBrkPedPrss != 0)
                                 && (bLocalTestSrv_stActrTstCode != 0))
                              {
                                 u8Localoutput = BRAKE_PED_NOK;
                              }
                              else
                              {
                                 if (  (SRVACTESTMNG_bDftacc_pedal != 0)
                                    && (bLocalTestSrv_stActrTstCode != 0))
                                 {
                                    u8Localoutput = ACC_PED_NOK;
                                 }
                                 else
                                 {
                                    if (  (SRVACTESTMNG_bDftgear_box != 0)
                                       && (bLocalTestSrv_stActrTstCode != 0))
                                    {
                                       u8Localoutput = GEAR_BOX_NOK;
                                    }
                                    else
                                    {
                                       if (  (SRVACTESTMNG_bDfttCoMes != 0)
                                          && (bLocalTestSrv_stActrTstCode != 0))
                                       {
                                          u8Localoutput = TEMP_WATER_NOK;
                                       }
                                       else
                                       {
                                          u8Localoutput = 0;
                                          bLocalBitTest = 1;
                                       }
                                    }
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
   if (bLocalBitTest != 0)
   {
      if (  (SRVACTESTMNG_bDftTstHPPmp != 0)
      && (bLocalTestSrv_stActrTstCode != 0))
      {
         u8Localoutput = HPPMP_FRM_NOK;
      }
      else
      {
         if (  (SRVACTESTMNG_bDftPrailInc != 0)
            && (bLocalTestSrv_stActrTstCode != 0))
         {
            u8Localoutput = HPPMP_MONTEE_PRAIL_NOK;
         }
         else
         {
            if (  (SRVACTESTMNG_bDftPrailMax != 0)
               && (bLocalTestSrv_stActrTstCode != 0))
            {
               u8Localoutput = HPPMP_PRAIL_NOK;
            }
            else
            {
               u8Localoutput = VVT_DFT_NOK;
            }
         }
      }
   }

   if (ActrTstMng_stActrTst != ACTRTSTMNG_ACTRTST_PB)
   {
      u8LocalSrv_stTestDftCdn = u8Localoutput;
   }
   else
   {
      VEMS_vidGET(Srv_stTestDftCdn, u8LocalSrv_stTestDftCdn);
   }
   VEMS_vidSET(Srv_stTestDftCdn, u8LocalSrv_stTestDftCdn);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidActrTstCmpfollow                           */
/* !Description :  Suite de fonction qui permet en cas de front montant sur un*/
/*                 des bits  de confirmation de test, d'achever le test       */
/*                 actionneur.                                                */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Meap_bActrTstCmpl;                                          */
/*  input boolean DmpVlv_bActrTstCmpl;                                        */
/*  input boolean IgCmd_bCtlPmpReqTstCmpl;                                    */
/*  input boolean FuPmp_bFuTnkPmpTstCmpl;                                     */
/*  input boolean ThMgt_bTrbWaPmpTstCmpl;                                     */
/*  input boolean Wg_bTestTrbTstCmpl;                                         */
/*  input boolean ActrTstHPPmp_bActrTstCmpl;                                  */
/*  input boolean ThMgt_bECTTstCmpl;                                          */
/*  input boolean VlvAct_bInActrTestSpEndIdc;                                 */
/*  input boolean VlvAct_bExActrTestSpEndIdc;                                 */
/*  input boolean CTP_bActrTstCmpl;                                           */
/*  input boolean FarSp_bActrTstCmpl;                                         */
/*  input boolean Oil_bBlowByTstCmpl;                                         */
/*  input boolean SRVACTESTMNG_ActrTstMng_TstCmpl;                            */
/*  input boolean SRVACTESTMNG_bOil_bBlowByPrev;                              */
/*  input boolean SRVACTESTMNG_bMeap_TstCmplPrev;                             */
/*  input boolean SRVACTESTMNG_bVlvTstCmplPrev;                               */
/*  input boolean SRVACTESTMNG_bCTP_TstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bSp_bActrTstPrev;                              */
/*  input boolean SRVACTESTMNG_bFuTnkPmpTstCmplPv;                            */
/*  input boolean SRVACTESTMNG_bCtlPmpReqTstCmplPv;                           */
/*  input boolean SRVACTESTMNG_bTrbWaPmpTstCmplPv;                            */
/*  input boolean SRVACTESTMNG_bTestTrbTstCmplPv;                             */
/*  input boolean SRVACTESTMNG_bActrTstCmplPrev1;                             */
/*  input boolean SRVACTESTMNG_bECTTstCmplPrev;                               */
/*  input boolean SRVACTESTMNG_bInActrTstSpEndPrev;                           */
/*  input boolean SRVACTESTMNG_bExActrTstSpEndPrev;                           */
/*  output boolean ActrTstMng_TstCmpl;                                        */
/*  output boolean SRVACTESTMNG_bInActrTstSpEndPrev;                          */
/*  output boolean SRVACTESTMNG_bExActrTstSpEndPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidActrTstCmpfollow(void)
{
   boolean bLocalTestInterm;
   boolean bLocalMeap_bActrTstCmpl;
   boolean bLocalDmpVlv_bActrTstCmpl;
   boolean bLocalFuPmp_bFuTnkPmpTstCmpl;
   boolean bLocalThMgt_bTrbWaPmpTstCmpl;
   boolean bLocalWg_bTestTrbTstCmpl;
   boolean bLocalActrTstHPPmp_bActrTstCmpl;
   boolean bLocalThMgt_bECTTstCmpl;
   boolean bLocalVlvAct_bInActrTestSpEndIdc;
   boolean bLocalVlvAct_bExActrTestSpEndIdc;
   boolean bLocalIgCmd_bCtlPmpReqTstCmpl;
   boolean bLocalFarSp_bActrTstCmpl;
   boolean bLocalCTP_bActrTstCmpl;
   boolean bLocalOil_bBlowByTstCmpl;


   VEMS_vidGET(Meap_bActrTstCmpl,bLocalMeap_bActrTstCmpl);
   VEMS_vidGET(DmpVlv_bActrTstCmpl,bLocalDmpVlv_bActrTstCmpl);
   VEMS_vidGET(IgCmd_bCtlPmpReqTstCmpl,bLocalIgCmd_bCtlPmpReqTstCmpl);
   VEMS_vidGET(FuPmp_bFuTnkPmpTstCmpl,bLocalFuPmp_bFuTnkPmpTstCmpl);
   VEMS_vidGET(ThMgt_bTrbWaPmpTstCmpl,bLocalThMgt_bTrbWaPmpTstCmpl);
   VEMS_vidGET(Wg_bTestTrbTstCmpl,bLocalWg_bTestTrbTstCmpl);
   VEMS_vidGET(ActrTstHPPmp_bActrTstCmpl,bLocalActrTstHPPmp_bActrTstCmpl);
   VEMS_vidGET(ThMgt_bECTTstCmpl,bLocalThMgt_bECTTstCmpl);
   VEMS_vidGET(VlvAct_bInActrTestSpEndIdc, bLocalVlvAct_bInActrTestSpEndIdc);
   VEMS_vidGET(VlvAct_bExActrTestSpEndIdc, bLocalVlvAct_bExActrTestSpEndIdc);
   VEMS_vidGET(CTP_bActrTstCmpl, bLocalCTP_bActrTstCmpl);
   VEMS_vidGET(FarSp_bActrTstCmpl, bLocalFarSp_bActrTstCmpl);
   VEMS_vidGET(Oil_bBlowByTstCmpl, bLocalOil_bBlowByTstCmpl);

   /*New condition added with V02 NT 11 06188 V02*/
   if (  ( SRVACTESTMNG_ActrTstMng_TstCmpl != 0)
      || (  (SRVACTESTMNG_bOil_bBlowByPrev == 0)
         && (bLocalOil_bBlowByTstCmpl != 0))
      || (  (SRVACTESTMNG_bMeap_TstCmplPrev == 0)
         && (bLocalMeap_bActrTstCmpl != 0)))
   {
      bLocalTestInterm = 1;
   }
   else
   {
      bLocalTestInterm = 0;
   }
   if (  ( bLocalTestInterm != 0)
      || (  (SRVACTESTMNG_bVlvTstCmplPrev == 0)
         && (bLocalDmpVlv_bActrTstCmpl != 0))
      || (  (SRVACTESTMNG_bCTP_TstCmplPrev == 0)
         && (bLocalCTP_bActrTstCmpl != 0))
      || (  (SRVACTESTMNG_bSp_bActrTstPrev == 0)
         && (bLocalFarSp_bActrTstCmpl != 0))
      || (  (SRVACTESTMNG_bFuTnkPmpTstCmplPv == 0)
         && (bLocalFuPmp_bFuTnkPmpTstCmpl != 0)))
   {
      bLocalTestInterm = 1;
   }
   else
   {
      bLocalTestInterm = 0;
   }

   if (  (bLocalTestInterm != 0)
      || (  (SRVACTESTMNG_bCtlPmpReqTstCmplPv == 0)
         && (bLocalIgCmd_bCtlPmpReqTstCmpl != 0))
      || (  (SRVACTESTMNG_bTrbWaPmpTstCmplPv == 0)
         && (bLocalThMgt_bTrbWaPmpTstCmpl != 0))
      || (  (SRVACTESTMNG_bTestTrbTstCmplPv == 0)
         && (bLocalWg_bTestTrbTstCmpl != 0)))
   {
      bLocalTestInterm = 1;
   }
   else
   {
      bLocalTestInterm = 0;
   }

   if (  (bLocalTestInterm != 0)
      || (  (SRVACTESTMNG_bActrTstCmplPrev1 == 0)
         && (bLocalActrTstHPPmp_bActrTstCmpl != 0))
      || (  (SRVACTESTMNG_bECTTstCmplPrev == 0)
         && (bLocalThMgt_bECTTstCmpl != 0)))
   {
      bLocalTestInterm = 1;
   }
   else
   {
      bLocalTestInterm = 0;
   }

   if (  (bLocalTestInterm != 0)
      || (  (SRVACTESTMNG_bInActrTstSpEndPrev == 0)
         && (bLocalVlvAct_bInActrTestSpEndIdc != 0))
      || (  (SRVACTESTMNG_bExActrTstSpEndPrev == 0)
         && (bLocalVlvAct_bExActrTestSpEndIdc != 0)))
   {
      ActrTstMng_TstCmpl = 1;
   }
   else
   {
      ActrTstMng_TstCmpl = 0;
   }

   SRVACTESTMNG_bInActrTstSpEndPrev = bLocalVlvAct_bInActrTestSpEndIdc;
   SRVACTESTMNG_bExActrTstSpEndPrev = bLocalVlvAct_bExActrTestSpEndIdc;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_ThMgtECTTst                                   */
/* !Description :  fonction de test du  défaut court circuit à l'alimentation */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_ThMgtECTTst(void)
{
   GDFRM_tenuGDUState LocalStDgoOc_ECTReq;
   GDFRM_tenuGDUState LocalStDgoScp_ECTReq;
   GDFRM_tenuGDUState LocalStDgoScg_ECTReq;


   LocalStDgoOc_ECTReq = GDGAR_tenuGetStDgo(GD_DFT_OC_ECTREQ);
   LocalStDgoScp_ECTReq = GDGAR_tenuGetStDgo(GD_DFT_SCP_ECTREQ);
   LocalStDgoScg_ECTReq = GDGAR_tenuGetStDgo(GD_DFT_SCG_ECTREQ);

   if (LocalStDgoOc_ECTReq == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoScp_ECTReq == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalStDgoScg_ECTReq == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_HPPmpTst                                      */
/* !Description :  fonction de test du défaut court circuit à l'alimentation  */
/*                 HPPmpTst.                                                  */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean ActrTstHPPmp_bPrailLeak;                                    */
/*  input boolean ActrTstHPPmp_bInjrFlowFail;                                 */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_HPPmpTst(void)
{
   boolean bLocalActrTstHPPmp_bPrailLeak;
   boolean bLocalActrTstHPPmp_bInjrFlowFail;


   VEMS_vidGET(ActrTstHPPmp_bPrailLeak, bLocalActrTstHPPmp_bPrailLeak);
   VEMS_vidGET(ActrTstHPPmp_bInjrFlowFail, bLocalActrTstHPPmp_bInjrFlowFail);
   ActrTstMng_bDftPrailLeak = bLocalActrTstHPPmp_bPrailLeak;
   ActrTstMng_bDftInjrFlow = bLocalActrTstHPPmp_bInjrFlowFail;

   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bOc = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bScg = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScp = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidFarSpTst                                   */
/* !Description :  Fonction indiquant l'etat de  blocage  riche et pauvre lors*/
/*                 d'un TA FarSp.                                             */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  input boolean FarSp_bUsPlausFldActrTst;                                   */
/*  input boolean FarSp_bUsPlausFcoActrTst;                                   */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidFarSpTst(void)
{
   boolean            bLocalFarSp_bUsPlausFldActrTst;
   boolean            bLocalFarSp_bUsPlausFcoActrTst;
   GDFRM_tenuGDUState LocalStDgoOC_UUPLS;
   GDFRM_tenuGDUState LocalStDgoSCG_UUPLS;
   GDFRM_tenuGDUState LocalStDgoSCP_UUPLS;


   VEMS_vidGET(FarSp_bUsPlausFldActrTst, bLocalFarSp_bUsPlausFldActrTst);
   VEMS_vidGET(FarSp_bUsPlausFcoActrTst, bLocalFarSp_bUsPlausFcoActrTst);
   LocalStDgoOC_UUPLS = GDGAR_tenuGetStDgo(GD_DFT_OC_UUPLS);
   LocalStDgoSCP_UUPLS = GDGAR_tenuGetStDgo(GD_DFT_SCP_UUPLS);
   LocalStDgoSCG_UUPLS = GDGAR_tenuGetStDgo(GD_DFT_SCG_UUPLS);
   if (LocalStDgoOC_UUPLS == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoSCP_UUPLS == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalStDgoSCG_UUPLS == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }
   ActrTstMng_bUsPlausFld = bLocalFarSp_bUsPlausFldActrTst;
   ActrTstMng_bUsPlausFco = bLocalFarSp_bUsPlausFcoActrTst;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidCTPtst                                     */
/* !Description :  Fonction de detection d'un défaut circuit ouvert sur les   */
/*                 CTP 2 lors du  dernier test actionneur .                   */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  input boolean CTP_bDft1dActrTst;                                          */
/*  input boolean CTP_bDft2dActrTst;                                          */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidCTPtst(void)
{
   boolean            bLocalCTP_bDft1dActrTst;
   boolean            bLocalCTP_bDft2dActrTst;
   GDFRM_tenuGDUState LocalStDgoOc_CTP1;
   GDFRM_tenuGDUState LocalStDgoScp_CTP1;
   GDFRM_tenuGDUState LocalStDgoScg_CTP1;
   GDFRM_tenuGDUState LocalStDgoOc_CTP2;
   GDFRM_tenuGDUState LocalStDgoScp_CTP2;
   GDFRM_tenuGDUState LocalStDgoScg_CTP2;


   VEMS_vidGET(CTP_bDft1dActrTst, bLocalCTP_bDft1dActrTst);
   VEMS_vidGET(CTP_bDft2dActrTst, bLocalCTP_bDft2dActrTst);

   LocalStDgoOc_CTP1 = GDGAR_tenuGetStDgo(GD_DFT_OC_CTP1);
   LocalStDgoScp_CTP1 = GDGAR_tenuGetStDgo(GD_DFT_SCP_CTP1);
   LocalStDgoScg_CTP1 = GDGAR_tenuGetStDgo(GD_DFT_SCG_CTP1);
   LocalStDgoOc_CTP2 = GDGAR_tenuGetStDgo(GD_DFT_OC_CTP2);
   LocalStDgoScp_CTP2 = GDGAR_tenuGetStDgo(GD_DFT_SCP_CTP2);
   LocalStDgoScg_CTP2 = GDGAR_tenuGetStDgo(GD_DFT_SCG_CTP2);
   if (LocalStDgoOc_CTP1 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoScp_CTP1 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalStDgoScg_CTP1 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }
   if (LocalStDgoOc_CTP2 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOcCTP2 = 1;
   }
   else
   {
      ActrTstMng_bOcCTP2 = 0;
   }
   if (LocalStDgoScp_CTP2 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScpCTP2 = 1;
   }
   else
   {
      ActrTstMng_bScpCTP2 = 0;
   }
   if (LocalStDgoScg_CTP2 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScgCTP2 = 1;
   }
   else
   {
      ActrTstMng_bScgCTP2 = 0;
   }
   ActrTstMng_bDftCTP1 = bLocalCTP_bDft1dActrTst;
   ActrTstMng_bDftCTP2 = bLocalCTP_bDft2dActrTst;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bUsPlausFld = 0;

}
/*---------------------------- end of file -----------------------------------*/
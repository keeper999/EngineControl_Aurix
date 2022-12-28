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
/* !File            : SRVACTESTMNG_FCT1.C                                     */
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
/*   1 / SRVACTESTMNG_vidInitOutput                                           */
/*   2 / SRVACTESTMNG_vidActrTstCdn                                           */
/*   3 / SRVACTESTMNG_vidActrTstCmpl                                          */
/*   4 / SRVACTESTMNG_vidActrTstAcvChart                                      */
/*   5 / SRVACTESTMNG_vidActrTstRes                                           */
/*   6 / SRVACTESTMNG_vidInj1Tst                                              */
/*   7 / SRVACTESTMNG_vidInj2Tst                                              */
/*   8 / SRVACTESTMNG_vidInj3Tst                                              */
/*   9 / SRVACTESTMNG_vidCoil_1Tst                                            */
/*   10 / SRVACTESTMNG_vidCoil_2Tst                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5074355 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SRVACTESTMNG/SRVACTESTMNG_FCT1.C$*/
/* $Revision::   1.6      $$Author::   pbakabad       $$Date::   Apr 11 2013 $*/
/* $Author::   pbakabad                               $$Date::   Apr 11 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SRVACTESTMNG.h"
#include "SRVACTESTMNG_L.h"
#include "SRVACTESTMNG_IM.h"
#include "DCM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "RTE.h"
#include "RtE_TYPE.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidInitOutput                                 */
/* !Description :  Fonction d'initialisation des variables produites par le   */
/*                 module SRVACTESTMNG.                                       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input bool ACTRTSTMNG_ACTRTST_IDLE;                                       */
/*  input bool PILOTAGE_NON_LANCE;                                            */
/*  output st93 ActrTstMng_stActrTst;                                         */
/*  output st92 Srv_stActrTstStatus;                                          */
/*  output bool PILOTAGE_NON_LANCE;                                           */
/*  output uint8 Srv_stActrTstFeedback;                                       */
/*  output boolean Srv_bTestCdnRunning;                                       */
/*  output uint8 Code_test_action;                                            */
/*  output boolean Srv_bActrTstEna;                                           */
/*  output boolean Srv_bTestCdn;                                              */
/*  output uint8 Srv_stTestDftCdn;                                            */
/*  output boolean ActrTestMng_bInhFRM;                                       */
/*  output boolean Afts_bAcvVlvActTest_nTarIdl;                               */
/*  output uint16 Afts_nTarIdlVlvActTest;                                     */
/*  output boolean SRVACTESTMNG_bSrvbActrTstDmdPrev;                          */
/*  output uint8 SRVACTESTMNG_u8CodeTstActionPrev;                            */
/*  output boolean SRVACTESTMNG_bInj1TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bInj2TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bInj3TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bInj4TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bCoil1TstCmplPrev;                            */
/*  output boolean SRVACTESTMNG_bCoil2TstCmplPrev;                            */
/*  output boolean SRVACTESTMNG_bCoil3TstCmplPrev;                            */
/*  output boolean SRVACTESTMNG_bCoil4TstCmplPrev;                            */
/*  output boolean SRVACTESTMNG_bDsTstCmplPrev;                               */
/*  output boolean SRVACTESTMNG_bUsTstCmplPrev;                               */
/*  output boolean SRVACTESTMNG_bActrTstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bPurgTstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bThrTstCmplPrev;                              */
/*  output boolean SRVACTESTMNG_bB2HiSpdTstCmplPrev;                          */
/*  output boolean SRVACTESTMNG_bB2loSpdTstCmplPrev;                          */
/*  output boolean SRVACTESTMNG_bCTstCmplPrev;                                */
/*  output boolean SRVACTESTMNG_bFuTnkPmpTstCmplPv;                           */
/*  output boolean SRVACTESTMNG_bCtlPmpReqTstCmplPv;                          */
/*  output boolean SRVACTESTMNG_bTrbWaPmpTstCmplPv;                           */
/*  output boolean SRVACTESTMNG_bTestTrbTstCmplPv;                            */
/*  output boolean SRVACTESTMNG_bECTTstCmplPrev;                              */
/*  output boolean SRVACTESTMNG_bActrTstCmplPrev1;                            */
/*  output boolean SRVACTESTMNG_bInActrTstSpEndPrev;                          */
/*  output boolean SRVACTESTMNG_bExActrTstSpEndPrev;                          */
/*  output boolean SRVACTESTMNG_bVlvTstCmplPrev;                              */
/*  output boolean SRVACTESTMNG_bSp_bActrTstPrev;                             */
/*  output boolean SRVACTESTMNG_bCTP_TstCmplPrev;                             */
/*  output boolean SRVACTESTMNG_bMeap_TstCmplPrev;                            */
/*  output boolean SRVACTESTMNG_bOil_bBlowByPrev;                             */
/*  output uint16 SRVACTESTMNG_u16Timer;                                      */
/*  output boolean SRVACTESTMNG_bTimeOut;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidInitOutput(void)
{
   /* Initialisation des variables d'états */
   ActrTstMng_stActrTst = ACTRTSTMNG_ACTRTST_IDLE;
   VEMS_vidSET(Srv_stActrTstStatus, PILOTAGE_NON_LANCE);
   VEMS_vidSET(Srv_stActrTstFeedback, PAS_DE_DEFAUT);
   /* Initialisation des sorties */
   VEMS_vidSET(Srv_bTestCdnRunning, 0);
   VEMS_vidSET(Code_test_action, 0);
   VEMS_vidSET(Srv_bActrTstEna, 0);
   VEMS_vidSET(Srv_bTestCdn, 0);
   VEMS_vidSET(Srv_stTestDftCdn, 0);
   VEMS_vidSET(ActrTestMng_bInhFRM, 0);
   VEMS_vidSET(Afts_bAcvVlvActTest_nTarIdl, 0);
   VEMS_vidSET(Afts_nTarIdlVlvActTest, 0);

   /* Initialisation des variables indicateurs d'achèvement de test*/
   SRVACTESTMNG_bSrvbActrTstDmdPrev = 0;
   SRVACTESTMNG_u8CodeTstActionPrev = 0;
   SRVACTESTMNG_bInj1TstCmplPrev = 0;
   SRVACTESTMNG_bInj2TstCmplPrev = 0;
   SRVACTESTMNG_bInj3TstCmplPrev = 0;
   SRVACTESTMNG_bInj4TstCmplPrev = 0;
   SRVACTESTMNG_bCoil1TstCmplPrev = 0;
   SRVACTESTMNG_bCoil2TstCmplPrev = 0;
   SRVACTESTMNG_bCoil3TstCmplPrev = 0;
   SRVACTESTMNG_bCoil4TstCmplPrev = 0;
   SRVACTESTMNG_bDsTstCmplPrev = 0;
   SRVACTESTMNG_bUsTstCmplPrev = 0;
   SRVACTESTMNG_bActrTstCmplPrev = 0;
   SRVACTESTMNG_bPurgTstCmplPrev = 0;
   SRVACTESTMNG_bThrTstCmplPrev = 0;
   SRVACTESTMNG_bB2HiSpdTstCmplPrev = 0;
   SRVACTESTMNG_bB2loSpdTstCmplPrev = 0;
   SRVACTESTMNG_bCTstCmplPrev = 0;
   SRVACTESTMNG_bFuTnkPmpTstCmplPv = 0;
   SRVACTESTMNG_bCtlPmpReqTstCmplPv = 0;
   SRVACTESTMNG_bTrbWaPmpTstCmplPv = 0;
   SRVACTESTMNG_bTestTrbTstCmplPv = 0;
   SRVACTESTMNG_bECTTstCmplPrev = 0;
   SRVACTESTMNG_bActrTstCmplPrev1 = 0;
   SRVACTESTMNG_bInActrTstSpEndPrev = 0;
   SRVACTESTMNG_bExActrTstSpEndPrev = 0;
   SRVACTESTMNG_bVlvTstCmplPrev = 0;
   SRVACTESTMNG_bSp_bActrTstPrev = 0;
   SRVACTESTMNG_bCTP_TstCmplPrev = 0;
   SRVACTESTMNG_bMeap_TstCmplPrev = 0;
   SRVACTESTMNG_bOil_bBlowByPrev = 0;
   SRVACTESTMNG_u16Timer = 0;
   SRVACTESTMNG_bTimeOut = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidActrTstCdn                                 */
/* !Description :  Fonction qui décrit les conditions externes au test        */
/*                 actionneur nécessaires pour son lancement.                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_06188_001.02                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void Dcm_GetSesCtrlType(argout Dcm_SesCtrlType* SesCtrlType)  */
/* argout Std_ReturnType;                                                     */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf argret void SRVACTESTMNG_vidTestDftCdn();                            */
/*  input uint8 Srv_stActrTstCode;                                            */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Srv_bActrTstDmd;                                            */
/*  input st92 Srv_stActrTstStatus;                                           */
/*  input boolean Ext_bOilPres;                                               */
/*  input boolean Ext_bCluPedPrss;                                            */
/*  input boolean FlowMng_bCluSwtEna;                                         */
/*  input boolean Ext_bBrkPedPrss;                                            */
/*  input uint16 Ext_pFuMes;                                                  */
/*  input uint8 ThMgt_rSpdFanReq;                                             */
/*  input boolean SRVACTESTMNG_bSrvbActrTstDmdPrev;                           */
/*  input uint16 ActrTstMng_TiDlyNMot;                                        */
/*  input uint16 SRVACTESTMNG_u16Timer;                                       */
/*  input uint16 ActrTstMng_pFuMaxTestInj_C;                                  */
/*  input boolean Inj_bInjTestDone;                                           */
/*  input uint8 ActrTstMng_VVehiMax;                                          */
/*  input uint16 ActrTstMng_UBatMin;                                          */
/*  input uint16 ActrTstMng_UBatMax;                                          */
/*  input uint16 ActrTstMng_nEngStopMaxTest_C;                                */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input boolean SRVACTESTMNG_bTimeOut;                                      */
/*  input bool ACTION_EN_COURS;                                               */
/*  input uint16 ActrTstMng_nEngRunMaxTest_C;                                 */
/*  input uint16 ActrTstMng_nEngRunMinTest_C;                                 */
/*  input uint16 ActrTstMng_nEngRunMaxTestHpPmp_C;                            */
/*  input uint16 ActrTstMng_nEngRunMinTestHpPmp_C;                            */
/*  input uint16 ActrTstMng_nEngRunMaxTestFarSp_C;                            */
/*  input uint16 ActrTstMng_nEngRunMinTestFarSp_C;                            */
/*  input uint8 AccP_rDrvReq;                                                 */
/*  input boolean ActrTestMng_bInhCondAccPed;                                 */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input boolean Srv_bInhFailStpActrTstThr_C;                                */
/*  input boolean SRVACTESTMNG_bDftVehicle_speed;                             */
/*  input boolean SRVACTESTMNG_bDftUbat;                                      */
/*  input uint8 ActrTstMng_tCoMesMinTestHpPmp_C;                              */
/*  input uint8 ActrTstMng_tCoMesMinTestFarSp_C;                              */
/*  input uint8 ActrTstMng_tCoMesMinTest_C;                                   */
/*  input boolean ActrTstHPPmp_bPrailPresIncFail;                             */
/*  input uint16 ActrTstMng_pFuMaxHpPmp_C;                                    */
/*  input boolean SRVACTESTMNG_bDftTstHPPmp;                                  */
/*  input boolean SRVACTESTMNG_bDftPrailInc;                                  */
/*  input boolean SRVACTESTMNG_bDftPrailMax;                                  */
/*  input boolean SRVACTESTMNG_bDftReg_mot_Running;                           */
/*  input boolean SRVACTESTMNG_bDftGMVact;                                    */
/*  input boolean SRVACTESTMNG_bDftpFu;                                       */
/*  input boolean SRVACTESTMNG_bDftInjDone;                                   */
/*  input boolean SRVACTESTMNG_bDfttCoMes;                                    */
/*  input boolean SRVACTESTMNG_bDftRegime_moteur;                             */
/*  input boolean SRVACTESTMNG_bDftacc_pedal;                                 */
/*  input boolean SRVACTESTMNG_bDftgear_box;                                  */
/*  output uint8 Code_test_action;                                            */
/*  output uint16 SRVACTESTMNG_u16Timer;                                      */
/*  output boolean SRVACTESTMNG_bTimeOut;                                     */
/*  output boolean SRVACTESTMNG_bDftpFu;                                      */
/*  output boolean SRVACTESTMNG_bDftInjDone;                                  */
/*  output boolean SRVACTESTMNG_bDftVehicle_speed;                            */
/*  output boolean SRVACTESTMNG_bDftUbat;                                     */
/*  output boolean SRVACTESTMNG_bDftReg_mot_Running;                          */
/*  output boolean SRVACTESTMNG_bDftRegime_moteur;                            */
/*  output boolean SRVACTESTMNG_bDftacc_pedal;                                */
/*  output boolean SRVACTESTMNG_bDftgear_box;                                 */
/*  output boolean SRVACTESTMNG_bDftGMVact;                                   */
/*  output boolean SRVACTESTMNG_bDfttCoMes;                                   */
/*  output boolean SRVACTESTMNG_bDftPrailMax;                                 */
/*  output boolean SRVACTESTMNG_bDftTstHPPmp;                                 */
/*  output boolean SRVACTESTMNG_bDftPrailInc;                                 */
/*  output boolean Srv_bTestCdn;                                              */
/*  output boolean Srv_bTestCdnRunning;                                       */
/*  output boolean SRVACTESTMNG_bSrvbActrTstDmdPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidActrTstCdn(void)
{
   boolean            bLocalswitch1;
   boolean            bLocalswitch2;
   boolean            bLocalswitch4;
   boolean            bLocalswitch5;
   boolean            bLocalTestCdn;
   boolean            bLocalTestCdnRunning;
   boolean            bLocalInj_bInjTestDone;
   boolean            bLocalExt_bOilPres;
   boolean            bLocalExt_bCluPedPrss;
   boolean            bLocalInhActrTstHPPmp;
   boolean            bLocalPrailPresIncFail;
   boolean            bLocalExt_bBrkPedPrss;
   boolean            bLocalRawInhExVVTActrTst;
   boolean            bLocalRawInhInVVTActrTst;
   boolean            bLocalSrv_bActrTstDmd;
   boolean            bLocalFlowMng_bCluSwtEna;
   boolean            bLocalECU_bWkuMain;
   uint8              u8LocalSrv_stActrTstCode;
   uint8              u8LocalAccP_rDrvReq;
   uint8              u8LocalSrv_stActrTstStatus;
   uint8              u8LocalCoPt_noEgdGearCord;
   uint8              u8LocalSesCtrlType;
   uint8              u8LocalThMgt_rSpdFanReq;
   GDFRM_tenuGDUState LocalstDgoOvld_ThrCmd;
   uint16             u16LocalExt_nEng;
   uint16             u16LocalExt_pFuMes;
   uint16             u16LocalActrTstMng_VVehiMax;
   uint16             u16LocalVeh_spdVeh;
   sint16             s16LocalExt_uBattMes;
   sint16             s16LocalExt_tCoMes;
   sint16             s16LocalCoMesMinTest_C;
   sint16             s16LocaltCoMesMinTestHpPmp_C;
   sint16             s16LocalActrTstMngTestFarSp_C;
   Std_ReturnType     LocalDcm_GetSesCtrlType;
/* !QAC : Msg(3:3203) this warning is due to the use of DCM_API */
   sint32             s32LocalActrTstMng_UBatMin;
   sint32             s32LocalActrTstMng_UBatMax;


   u8LocalSesCtrlType = 0;
   /*get data from OS*/
   VEMS_vidGET(Srv_stActrTstCode, u8LocalSrv_stActrTstCode);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Srv_bActrTstDmd, bLocalSrv_bActrTstDmd);
   VEMS_vidGET(Srv_stActrTstStatus, u8LocalSrv_stActrTstStatus);
   VEMS_vidGET(Ext_bOilPres, bLocalExt_bOilPres);
   VEMS_vidGET(Ext_bCluPedPrss, bLocalExt_bCluPedPrss);
   VEMS_vidGET(FlowMng_bCluSwtEna, bLocalFlowMng_bCluSwtEna);
   VEMS_vidGET(Ext_bBrkPedPrss, bLocalExt_bBrkPedPrss);
   VEMS_vidGET(Ext_pFuMes, u16LocalExt_pFuMes);
   VEMS_vidGET(ThMgt_rSpdFanReq, u8LocalThMgt_rSpdFanReq);

   bLocalRawInhInVVTActrTst = GDGAR_bGetFRM(FRM_FRM_INHINVVTACTRTST);
   bLocalRawInhExVVTActrTst = GDGAR_bGetFRM(FRM_FRM_INHEXVVTACTRTST);
   bLocalInhActrTstHPPmp = GDGAR_bGetFRM(FRM_FRM_INHACTRTSTHPPMP);

   LocalDcm_GetSesCtrlType = Dcm_GetSesCtrlType(&u8LocalSesCtrlType);
/* !QAC : Msg(3:3199) this warning is due to the use of DCM_API */

   if (u8LocalSrv_stActrTstCode != 0)
   {
      VEMS_vidSET(Code_test_action, u8LocalSrv_stActrTstCode);
   }
   if (  (SRVACTESTMNG_bSrvbActrTstDmdPrev == 0)
      && (bLocalSrv_bActrTstDmd != 0))
   {
      SRVACTESTMNG_u16Timer =
         (uint16)MATHSRV_udtMIN(ActrTstMng_TiDlyNMot, 51000);
      if (SRVACTESTMNG_u16Timer == 0)
      {
         SRVACTESTMNG_bTimeOut = 1;
      }
      else
      {
         SRVACTESTMNG_bTimeOut = 0;
      }
   }
   else
   {
      if (SRVACTESTMNG_u16Timer > 0)
      {
         SRVACTESTMNG_u16Timer = (uint16)(SRVACTESTMNG_u16Timer - 1);
         if (SRVACTESTMNG_u16Timer == 0)
         {
            SRVACTESTMNG_bTimeOut = 1;
         }
         else
         {
            SRVACTESTMNG_bTimeOut = 0;
         }
      }
   }
   /*internal variable calculation*/
   if (  (u8LocalSrv_stActrTstCode == CODE_TEST_INJECTEUR_1)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_INJECTEUR_2)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_INJECTEUR_3)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_INJECTEUR_4))
   {
      if (u16LocalExt_pFuMes < ActrTstMng_pFuMaxTestInj_C)
      {
         SRVACTESTMNG_bDftpFu = 0;
      }
      else
      {
         SRVACTESTMNG_bDftpFu = 1;
      }
   }
   else
   {
      SRVACTESTMNG_bDftpFu = 0;
   }
   if (  (u8LocalSrv_stActrTstCode == CODE_TEST_BOBINE_4)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_BOBINE_3)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_BOBINE_2)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_BOBINE_1))
   {
      VEMS_vidGET(Inj_bInjTestDone, bLocalInj_bInjTestDone);
      SRVACTESTMNG_bDftInjDone = bLocalInj_bInjTestDone;
   }
   else
   {
      SRVACTESTMNG_bDftInjDone = 0;
   }

   u16LocalActrTstMng_VVehiMax = (uint16)(ActrTstMng_VVehiMax * 128);
   if(u16LocalVeh_spdVeh <= u16LocalActrTstMng_VVehiMax)
   {
      SRVACTESTMNG_bDftVehicle_speed = 0;
   }
   else
   {
      SRVACTESTMNG_bDftVehicle_speed = 1;
   }

   s32LocalActrTstMng_UBatMin = (sint32)((ActrTstMng_UBatMin * 59) / 25);
   s32LocalActrTstMng_UBatMax = (sint32)((ActrTstMng_UBatMax * 59) / 25);
   if(  (s16LocalExt_uBattMes >= s32LocalActrTstMng_UBatMin)
     && (s16LocalExt_uBattMes <= s32LocalActrTstMng_UBatMax))
   {
      SRVACTESTMNG_bDftUbat = 0;
   }
   else
   {
      SRVACTESTMNG_bDftUbat = 1;
   }

   if (u16LocalExt_nEng <= ActrTstMng_nEngStopMaxTest_C)
   {
      SRVACTESTMNG_bDftReg_mot_Running = 0;
   }
   else
   {
      SRVACTESTMNG_bDftReg_mot_Running = 1;
   }

   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
/* [NS_bDftRegime_moteur] */
   if (  (SRVACTESTMNG_bTimeOut != 0)
      && (u8LocalSrv_stActrTstStatus == ACTION_EN_COURS))
   {
      if (  (  (ActrTstMng_nEngRunMaxTest_C >= u16LocalExt_nEng)
            && (u16LocalExt_nEng >= ActrTstMng_nEngRunMinTest_C)
            && (  (u8LocalSrv_stActrTstCode == CODE_TEST_TURBO)
               || (u8LocalSrv_stActrTstCode == CODE_TEST_VVT_ADM)
               || (u8LocalSrv_stActrTstCode == CODE_TEST_VVT_ECH)))
         || (  (ActrTstMng_nEngRunMaxTestHpPmp_C >= u16LocalExt_nEng)
            && (u16LocalExt_nEng>= ActrTstMng_nEngRunMinTestHpPmp_C)
            && (u8LocalSrv_stActrTstCode == CODE_TEST_HPPMP))
         || (  (ActrTstMng_nEngRunMaxTestFarSp_C >= u16LocalExt_nEng)
            && (u16LocalExt_nEng>= ActrTstMng_nEngRunMinTestFarSp_C)
            && (u8LocalSrv_stActrTstCode == CODE_TEST_FARSP)))
      {
         SRVACTESTMNG_bDftRegime_moteur = 0;
      }
      else
      {
         SRVACTESTMNG_bDftRegime_moteur = 1;
      }
   }
   else
   {
      SRVACTESTMNG_bDftRegime_moteur = 0;
   }

   VEMS_vidGET(AccP_rDrvReq, u8LocalAccP_rDrvReq);
   if (  (ActrTestMng_bInhCondAccPed != 0)
      || (u8LocalAccP_rDrvReq == 0))
   {
      SRVACTESTMNG_bDftacc_pedal = 0;
   }
   else
   {
      SRVACTESTMNG_bDftacc_pedal = 1;
   }

   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   if (u8LocalCoPt_noEgdGearCord == 0)
   {
      SRVACTESTMNG_bDftgear_box = 0;
   }
   else
   {
      SRVACTESTMNG_bDftgear_box = 1;
   }
   if (bLocalFlowMng_bCluSwtEna == 0)
   {
      bLocalExt_bCluPedPrss = 0;
   }
   /* NS_bDftGMVact calculation */
   if (u8LocalSrv_stActrTstCode == CODE_TEST_CTP)
   {
      if (u8LocalThMgt_rSpdFanReq == 0)
      {
         SRVACTESTMNG_bDftGMVact = 0;
      }
      else
      {
         SRVACTESTMNG_bDftGMVact = 1;
      }
   }
   else
   {
      SRVACTESTMNG_bDftGMVact = 0;
   }
   /* Local variable calculation*/
   if (Srv_bInhFailStpActrTstThr_C != 0)
   {
      bLocalswitch1 = 1;
   }
   else
   {
      if (u8LocalSrv_stActrTstCode == CODE_TEST_PAP_MOT)
      {
         LocalstDgoOvld_ThrCmd =
            GDGAR_tenuGetStDgo(GD_DFT_OVLD_THRCMD);
         if (LocalstDgoOvld_ThrCmd != GDU_ETAT_PRESENT)
         {
            bLocalswitch1 = 1;
         }
         else
         {
            bLocalswitch1 = 0;
         }
      }
      else
      {
         bLocalswitch1 = 1;
      }
   }
   if (  (SRVACTESTMNG_bDftVehicle_speed == 0)
      && (SRVACTESTMNG_bDftUbat == 0)
      && (bLocalECU_bWkuMain != 0)
      && (u8LocalSesCtrlType == DCM_EXTENDED_DIAGNOSTIC_SESSION))
   {
      bLocalswitch2 = 1;
   }
   else
   {
      bLocalswitch2 = 0;
   }
/* [NS_bDfttCoMes] */
   s16LocaltCoMesMinTestHpPmp_C =
      (sint16)(ActrTstMng_tCoMesMinTestHpPmp_C - 40);
   s16LocalActrTstMngTestFarSp_C =
      (sint16)(ActrTstMng_tCoMesMinTestFarSp_C - 40);
   s16LocalCoMesMinTest_C = (sint16)(ActrTstMng_tCoMesMinTest_C - 40);
   if (  (u8LocalSrv_stActrTstCode == CODE_TEST_HPPMP)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_TURBO)
      || (u8LocalSrv_stActrTstCode == CODE_TEST_FARSP))
   {
      if (  (  (u8LocalSrv_stActrTstCode == CODE_TEST_HPPMP)
         && (s16LocalExt_tCoMes >= s16LocaltCoMesMinTestHpPmp_C))
      || (  (u8LocalSrv_stActrTstCode == CODE_TEST_TURBO)
         && (s16LocalExt_tCoMes >= s16LocalCoMesMinTest_C))
      || (  (u8LocalSrv_stActrTstCode == CODE_TEST_FARSP)
         && (s16LocalExt_tCoMes >= s16LocalActrTstMngTestFarSp_C)))
      {
         SRVACTESTMNG_bDfttCoMes = 0;
      }
      else
      {
         SRVACTESTMNG_bDfttCoMes = 1;
      }
   }
   else
   {
      SRVACTESTMNG_bDfttCoMes = 0;
   }
   if (u8LocalSrv_stActrTstCode == CODE_TEST_VVT_ADM)
   {
      if (u8LocalSrv_stActrTstStatus == ACTION_EN_COURS)
      {
         if (  (bLocalRawInhInVVTActrTst == 0)
            && (bLocalExt_bOilPres != 0))
         {
            bLocalswitch4 = 1;
         }
         else
         {
            bLocalswitch4 = 0;
         }
      }
      else
      {
         bLocalswitch4 = 1;
      }
   }
   else
   {
      if (u8LocalSrv_stActrTstCode == CODE_TEST_VVT_ECH)
      {
         if (u8LocalSrv_stActrTstStatus == ACTION_EN_COURS)
         {
            if (  (bLocalRawInhExVVTActrTst == 0)
               && (bLocalExt_bOilPres != 0))
            {
               bLocalswitch4 = 1;
            }
            else
            {
               bLocalswitch4 = 0;
            }
         }
         else
         {
            bLocalswitch4 = 1;
         }
      }
      else
      {
         bLocalswitch4 = 1;
      }
   }
   VEMS_vidGET(ActrTstHPPmp_bPrailPresIncFail, bLocalPrailPresIncFail);

   if (u8LocalSrv_stActrTstCode != CODE_TEST_HPPMP)
   {
      SRVACTESTMNG_bDftPrailMax = 0;
      SRVACTESTMNG_bDftTstHPPmp = 0;
      SRVACTESTMNG_bDftPrailInc = 0;
   }
   else
   {
      if (u16LocalExt_pFuMes < ActrTstMng_pFuMaxHpPmp_C)
      {
         SRVACTESTMNG_bDftPrailMax = 0;
      }
      else
      {
         SRVACTESTMNG_bDftPrailMax = 1;
      }

      SRVACTESTMNG_bDftPrailInc = bLocalPrailPresIncFail;
      SRVACTESTMNG_bDftTstHPPmp = bLocalInhActrTstHPPmp;
   }

   if (  (SRVACTESTMNG_bDftTstHPPmp == 0)
      && (SRVACTESTMNG_bDftPrailInc == 0)
      && (SRVACTESTMNG_bDftPrailMax == 0))
   {
      bLocalswitch5 = 1;
   }
   else
   {
      bLocalswitch5 = 0;
   }
   /*Calcul of Srv_bTestCdn value*/
   if (  (bLocalswitch2 != 0)
      && (SRVACTESTMNG_bDftReg_mot_Running == 0)
      && (SRVACTESTMNG_bDftGMVact == 0))
   {
      if(u8LocalSrv_stActrTstStatus == ACTION_EN_COURS)
      {
         if (  (SRVACTESTMNG_bDftpFu == 0)
            && (SRVACTESTMNG_bDftInjDone == 0)
            && (bLocalswitch1 != 0))
         {
            bLocalTestCdn = 1;
         }
         else
         {
            bLocalTestCdn = 0;
         }
      }
      else
      {
         bLocalTestCdn = 1;
      }
   }
   else
   {
      bLocalTestCdn = 0;
   }
   /*Srv_bTestCdnRunning value calculation*/
   if (  (bLocalswitch2 != 0)
      && (SRVACTESTMNG_bDfttCoMes == 0)
      && (bLocalswitch4 != 0)
      && (bLocalswitch5 != 0)
      && (SRVACTESTMNG_bDftRegime_moteur == 0)
      && (bLocalExt_bBrkPedPrss == 0)
      && (bLocalExt_bCluPedPrss == 0)
      && (SRVACTESTMNG_bDftacc_pedal == 0)
      && (SRVACTESTMNG_bDftgear_box == 0))
   {
      bLocalTestCdnRunning = 1;
   }
   else
   {
      bLocalTestCdnRunning = 0;
   }

   /*Setting global variable*/
   VEMS_vidSET(Srv_bTestCdn, bLocalTestCdn);
   VEMS_vidSET(Srv_bTestCdnRunning, bLocalTestCdnRunning);
   SRVACTESTMNG_bSrvbActrTstDmdPrev = bLocalSrv_bActrTstDmd;

   /*call of vidTestDftCdn FCT4*/
   SRVACTESTMNG_vidTestDftCdn();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidActrTstCmpl                                */
/* !Description :  Fonction qui permet en cas de front montant sur un des bits*/
/*                 de confirmation de test, d'achever le test actionneur.     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SRVACTESTMNG_vidActrTstCmpfollow();                      */
/*  input boolean Inj_bInj1TstCmpl;                                           */
/*  input boolean Inj_bInj2TstCmpl;                                           */
/*  input boolean Inj_bInj3TstCmpl;                                           */
/*  input boolean Inj_bInj4TstCmpl;                                           */
/*  input boolean IgCmd_bCoil1TstCmpl;                                        */
/*  input boolean IgCmd_bCoil2TstCmpl;                                        */
/*  input boolean IgCmd_bCoil3TstCmpl;                                        */
/*  input boolean IgCmd_bCoil4TstCmpl;                                        */
/*  input boolean HeatSenO2_bDsTstCmpl;                                       */
/*  input boolean HeatSenO2_bUsTstCmpl;                                       */
/*  input boolean Rly_bActrTstCmpl;                                           */
/*  input boolean Cstr_bPurgTstCmpl;                                          */
/*  input boolean Thr_bThrTstCmpl;                                            */
/*  input boolean CoFan_bB2HiSpdTstCmpl;                                      */
/*  input boolean CoFan_bB2LoSpdTstCmpl;                                      */
/*  input boolean CoFan_bCTstCmpl;                                            */
/*  input boolean SRVACTESTMNG_bInj1TstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bInj2TstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bInj3TstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bInj4TstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bCoil1TstCmplPrev;                             */
/*  input boolean SRVACTESTMNG_bCoil2TstCmplPrev;                             */
/*  input boolean SRVACTESTMNG_bCoil3TstCmplPrev;                             */
/*  input boolean SRVACTESTMNG_bCoil4TstCmplPrev;                             */
/*  input boolean SRVACTESTMNG_bActrTstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bPurgTstCmplPrev;                              */
/*  input boolean SRVACTESTMNG_bDsTstCmplPrev;                                */
/*  input boolean SRVACTESTMNG_bUsTstCmplPrev;                                */
/*  input boolean SRVACTESTMNG_bThrTstCmplPrev;                               */
/*  input boolean SRVACTESTMNG_bB2HiSpdTstCmplPrev;                           */
/*  input boolean SRVACTESTMNG_bB2loSpdTstCmplPrev;                           */
/*  input boolean SRVACTESTMNG_bCTstCmplPrev;                                 */
/*  output boolean SRVACTESTMNG_ActrTstMng_TstCmpl;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidActrTstCmpl(void)
{
   boolean bLocalInj_bInj1TstCmpl;
   boolean bLocalInj_bInj2TstCmpl;
   boolean bLocalInj_bInj3TstCmpl;
   boolean bLocalInj_bInj4TstCmpl;
   boolean bLocalIgCmd_bCoil_1TstCmpl;
   boolean bLocalIgCmd_bCoil2TstCmpl;
   boolean bLocalIgCmd_bCoil3TstCmpl;
   boolean bLocalIgCmd_bCoil4TstCmpl;
   boolean bLocalHeatSenO2_bDsTstCmpl;
   boolean bLocalHeatSenO2_bUsTstCmpl;
   boolean bLocalRly_bActrTstCmpl;
   boolean bLocalCstr_bPurgTstCmpl;
   boolean bLocalThr_bThrTstCmpl;
   boolean bLocalCoFan_bB2HiSpdTstCmpl;
   boolean bLocalCoFan_bB2LoSpdTstCmpl;
   boolean bLocalCoFan_bCTstCmpl;
   boolean bLocalTestInterm;


   VEMS_vidGET(Inj_bInj1TstCmpl, bLocalInj_bInj1TstCmpl);
   VEMS_vidGET(Inj_bInj2TstCmpl, bLocalInj_bInj2TstCmpl);
   VEMS_vidGET(Inj_bInj3TstCmpl, bLocalInj_bInj3TstCmpl);
   VEMS_vidGET(Inj_bInj4TstCmpl, bLocalInj_bInj4TstCmpl);
   VEMS_vidGET(IgCmd_bCoil1TstCmpl, bLocalIgCmd_bCoil_1TstCmpl);
   VEMS_vidGET(IgCmd_bCoil2TstCmpl, bLocalIgCmd_bCoil2TstCmpl);
   VEMS_vidGET(IgCmd_bCoil3TstCmpl, bLocalIgCmd_bCoil3TstCmpl);
   VEMS_vidGET(IgCmd_bCoil4TstCmpl, bLocalIgCmd_bCoil4TstCmpl);
   VEMS_vidGET(HeatSenO2_bDsTstCmpl, bLocalHeatSenO2_bDsTstCmpl);
   VEMS_vidGET(HeatSenO2_bUsTstCmpl, bLocalHeatSenO2_bUsTstCmpl);
   VEMS_vidGET(Rly_bActrTstCmpl, bLocalRly_bActrTstCmpl);
   VEMS_vidGET(Cstr_bPurgTstCmpl, bLocalCstr_bPurgTstCmpl);
   VEMS_vidGET(Thr_bThrTstCmpl, bLocalThr_bThrTstCmpl);
   VEMS_vidGET(CoFan_bB2HiSpdTstCmpl, bLocalCoFan_bB2HiSpdTstCmpl);
   VEMS_vidGET(CoFan_bB2LoSpdTstCmpl, bLocalCoFan_bB2LoSpdTstCmpl);
   VEMS_vidGET(CoFan_bCTstCmpl, bLocalCoFan_bCTstCmpl);

   if (  (  (SRVACTESTMNG_bInj1TstCmplPrev == 0)
         && (bLocalInj_bInj1TstCmpl != 0))
      || (  (SRVACTESTMNG_bInj2TstCmplPrev == 0)
         && (bLocalInj_bInj2TstCmpl != 0))
      || (  (SRVACTESTMNG_bInj3TstCmplPrev == 0)
         && (bLocalInj_bInj3TstCmpl != 0))
      || (  (SRVACTESTMNG_bInj4TstCmplPrev == 0)
         && (bLocalInj_bInj4TstCmpl != 0)))
   {
      bLocalTestInterm = 1;
   }
   else
   {
      bLocalTestInterm = 0;
   }

   if (  (bLocalTestInterm != 0)
      || (  (SRVACTESTMNG_bCoil1TstCmplPrev == 0)
         && (bLocalIgCmd_bCoil_1TstCmpl != 0))
      || (  (SRVACTESTMNG_bCoil2TstCmplPrev == 0)
         && (bLocalIgCmd_bCoil2TstCmpl != 0))
      || (  (SRVACTESTMNG_bCoil3TstCmplPrev == 0)
         && (bLocalIgCmd_bCoil3TstCmpl != 0))
      || (  (SRVACTESTMNG_bCoil4TstCmplPrev == 0)
         && (bLocalIgCmd_bCoil4TstCmpl != 0)))
   {
      bLocalTestInterm = 1;
   }
   else
   {
      bLocalTestInterm = 0;
   }
   if (  (bLocalTestInterm != 0)
      || (  (SRVACTESTMNG_bActrTstCmplPrev == 0)
         && (bLocalRly_bActrTstCmpl != 0))
      || (  (SRVACTESTMNG_bPurgTstCmplPrev == 0)
         && (bLocalCstr_bPurgTstCmpl != 0))
      || (  (SRVACTESTMNG_bDsTstCmplPrev == 0)
         && (bLocalHeatSenO2_bDsTstCmpl != 0)))
   {
      bLocalTestInterm = 1;
   }
   else
   {
      bLocalTestInterm = 0;
   }
   if (  ( bLocalTestInterm != 0)
      || (  (SRVACTESTMNG_bUsTstCmplPrev == 0)
         && (bLocalHeatSenO2_bUsTstCmpl != 0))
      || (  (SRVACTESTMNG_bThrTstCmplPrev == 0)
         && (bLocalThr_bThrTstCmpl != 0)))
   {
      bLocalTestInterm = 1;
   }
   else
   {
      bLocalTestInterm = 0;
   }
   if (  (bLocalTestInterm != 0)
      || (  (SRVACTESTMNG_bB2HiSpdTstCmplPrev == 0)
         && (bLocalCoFan_bB2HiSpdTstCmpl != 0))
      || (  (SRVACTESTMNG_bB2loSpdTstCmplPrev == 0)
         && (bLocalCoFan_bB2LoSpdTstCmpl != 0))
      || (  (SRVACTESTMNG_bCTstCmplPrev == 0)
         && (bLocalCoFan_bCTstCmpl != 0)))
   {
      SRVACTESTMNG_ActrTstMng_TstCmpl = 1;
   }
   else
   {
      SRVACTESTMNG_ActrTstMng_TstCmpl = 0;
   }

   SRVACTESTMNG_vidActrTstCmpfollow();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidActrTstAcvChart                            */
/* !Description :  Fonction decrivant le gestionnaire des tests actionneurs.  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SRVACTESTMNG_vidTstCdnClcn();                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Srv_EveAckActrTstDmd_ActrTstMng();                       */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Srv_bActrTstDmd;                                            */
/*  input uint8 Code_test_action;                                             */
/*  input st92 Srv_stActrTstStatus;                                           */
/*  input st93 ActrTstMng_stActrTst;                                          */
/*  input bool ACTRTSTMNG_ACTRTST_IDLE;                                       */
/*  input bool ACTRTSTMNG_ACTRTST_IMPO;                                       */
/*  input boolean Srv_bActrTstDmdWithCndVld;                                  */
/*  input bool ACTRTSTMNG_ACTRTST_PROGS;                                      */
/*  input bool ACTION_EN_COURS;                                               */
/*  input bool PILOTAGE_NON_LANCE;                                            */
/*  input boolean ActrTstMng_TstCmpl;                                         */
/*  input boolean Srv_bActrTstCndClcd;                                        */
/*  input bool PROBLEME;                                                      */
/*  input boolean Srv_bActrTstStop;                                           */
/*  input uint8 SRVACTESTMNG_u8CodeTstActionPrev;                             */
/*  input uint16 Afts_nTarIdlVlvActTest_C;                                    */
/*  output st93 ActrTstMng_stActrTst;                                         */
/*  output boolean Srv_bActrTstEna;                                           */
/*  output boolean ActrTestMng_bInhFRM;                                       */
/*  output boolean Afts_bAcvVlvActTest_nTarIdl;                               */
/*  output uint16 Afts_nTarIdlVlvActTest;                                     */
/*  output st92 Srv_stActrTstStatus;                                          */
/*  output uint8 SRVACTESTMNG_u8CodeTstActionPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidActrTstAcvChart(void)
{
   boolean bLocalSrv_bActrTstStop;
   boolean bLocalSrv_bActrTstDmd;
   boolean bLocalSrv_bActrTstDmdWithCndVld;
   uint8   u8LocalCode_test_action;
   uint8   u8LocalSrv_stActrTstStatus;
   uint16  u16LocalAfts_nTarIdlVlvActTest;


   SRVACTESTMNG_vidTstCdnClcn();

   VEMS_vidGET(Srv_bActrTstDmd, bLocalSrv_bActrTstDmd);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_stActrTstStatus, u8LocalSrv_stActrTstStatus);

   switch (ActrTstMng_stActrTst)
   {
      case ACTRTSTMNG_ACTRTST_IDLE:
      case ACTRTSTMNG_ACTRTST_IMPO:
      case ACTRTSTMNG_ACTRTST_DONE:
      case ACTRTSTMNG_ACTRTST_STOP:
      case ACTRTSTMNG_ACTRTST_PB:
      if (bLocalSrv_bActrTstDmd != 0)
      {
         VEMS_vidGET(Srv_bActrTstDmdWithCndVld,
                     bLocalSrv_bActrTstDmdWithCndVld);
         if (bLocalSrv_bActrTstDmdWithCndVld != 0)
         {
            ActrTstMng_stActrTst = ACTRTSTMNG_ACTRTST_PROGS;
            VEMS_vidSET(Srv_bActrTstEna, 1);
            VEMS_vidSET(ActrTestMng_bInhFRM, 1);
            u8LocalSrv_stActrTstStatus = ACTION_EN_COURS;
         }
         else
         {
            ActrTstMng_stActrTst = ACTRTSTMNG_ACTRTST_IMPO;
            VEMS_vidSET(Srv_bActrTstEna, 0);
            u8LocalSrv_stActrTstStatus = PILOTAGE_NON_LANCE;
         }
         Srv_EveAckActrTstDmd_ActrTstMng();
      }
      break;

      case ACTRTSTMNG_ACTRTST_PROGS:
      if (ActrTstMng_TstCmpl != 0)
      {
         VEMS_vidSET(ActrTestMng_bInhFRM, 0);
         ActrTstMng_stActrTst = ACTRTSTMNG_ACTRTST_DONE;
         VEMS_vidSET(Srv_bActrTstEna, 0);
         u8LocalSrv_stActrTstStatus = ACTION_TERMINEE_OK;
      }
      else
      {
         if (Srv_bActrTstCndClcd == 0)
         {
            VEMS_vidSET(ActrTestMng_bInhFRM, 0);
            ActrTstMng_stActrTst = ACTRTSTMNG_ACTRTST_PB;
            VEMS_vidSET(Srv_bActrTstEna, 0);
            u8LocalSrv_stActrTstStatus = PROBLEME;
         }
         else
         {
            VEMS_vidGET(Srv_bActrTstStop, bLocalSrv_bActrTstStop);
            if (  (bLocalSrv_bActrTstStop != 0)
               || (  u8LocalCode_test_action
                  != SRVACTESTMNG_u8CodeTstActionPrev))
            {
               VEMS_vidSET(ActrTestMng_bInhFRM, 0);
               ActrTstMng_stActrTst = ACTRTSTMNG_ACTRTST_STOP;
               VEMS_vidSET(Srv_bActrTstEna, 0);
               u8LocalSrv_stActrTstStatus = ARRET_DU_PILOTAGE;
            }
         }
      }
      break;

      default:
      ActrTstMng_stActrTst = ACTRTSTMNG_ACTRTST_IDLE;
      VEMS_vidSET(ActrTestMng_bInhFRM, 0);
      VEMS_vidSET(Srv_bActrTstEna, 0);
      u8LocalSrv_stActrTstStatus = PILOTAGE_NON_LANCE;
      SWFAIL_vidSoftwareErrorHook();
      break;
   }

   if (  (u8LocalSrv_stActrTstStatus == ACTION_EN_COURS)
      && (  (u8LocalCode_test_action == CODE_TEST_VVT_ADM)
         || (u8LocalCode_test_action == CODE_TEST_VVT_ECH)))
   {
      VEMS_vidSET(Afts_bAcvVlvActTest_nTarIdl, 1);
      u16LocalAfts_nTarIdlVlvActTest =
         (uint16)MATHSRV_udtMIN(Afts_nTarIdlVlvActTest_C, 8000);
      VEMS_vidSET(Afts_nTarIdlVlvActTest, u16LocalAfts_nTarIdlVlvActTest);
   }
   else
   {
      VEMS_vidSET(Afts_bAcvVlvActTest_nTarIdl, 0);
      VEMS_vidSET(Afts_nTarIdlVlvActTest, 0);
   }
   VEMS_vidSET(Srv_stActrTstStatus, u8LocalSrv_stActrTstStatus);
   SRVACTESTMNG_u8CodeTstActionPrev = u8LocalCode_test_action;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidActrTstRes                                 */
/* !Description :  Fonction qui permet la gestion des tests actionneurs.      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_06188_002.02                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SRVACTESTMNG_vidActrTst1Res();                           */
/*  extf argret void SRVACTESTMNG_vidActrTst2Res();                           */
/*  extf argret void SRVACTESTMNG_vidActrTst3Res();                           */
/*  extf argret void SRVACTESTMNG_vidActrTst4Res();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean ActrTstMng_bDftCmd;                                         */
/*  input boolean ActrTstMng_bScp;                                            */
/*  input boolean ActrTstMng_bScg;                                            */
/*  input boolean ActrTstMng_bOc;                                             */
/*  input boolean ActrTstMng_bMap;                                            */
/*  input boolean ActrTstMng_bGavScp;                                         */
/*  input boolean ActrTstMng_bFrq;                                            */
/*  input boolean ActrTstMng_bStuckVlv;                                       */
/*  input boolean ActrTstMng_bDftEE;                                          */
/*  input boolean ActrTstMng_VvtStatPb;                                       */
/*  input boolean ActrTstMng_VvtDynPb;                                        */
/*  input boolean ActrTstMng_bOcHiFan;                                        */
/*  input boolean ActrTstMng_bScgHiFan;                                       */
/*  input boolean ActrTstMng_bScpHiFan;                                       */
/*  input boolean ActrTstMng_bDurtyVlv;                                       */
/*  input boolean ActrTstMng_bDftPrailLeak;                                   */
/*  input boolean ActrTstMng_bDftInjrFlow;                                    */
/*  input boolean ActrTstMng_bUsPlausFco;                                     */
/*  input boolean ActrTstMng_bUsPlausFld;                                     */
/*  input boolean ActrTstMng_bOcCTP2;                                         */
/*  input boolean ActrTstMng_bScpCTP2;                                        */
/*  input boolean ActrTstMng_bScgCTP2;                                        */
/*  input boolean ActrTstMng_bDftCTP1;                                        */
/*  input boolean ActrTstMng_bDftCTP2;                                        */
/*  input boolean ActrTstMng_bFlapFaild;                                      */
/*  input boolean ActrTstMng_bFlapBlockOp;                                    */
/*  input boolean ActrTstMng_bFlapStayOp;                                     */
/*  output uint8 Srv_stActrTstFeedback;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidActrTstRes(void)
{
   boolean bLocalVlvTest;
   boolean bLocalVlvTest2;
   boolean bLocalVlvTest3;
   boolean bLocalVlvTest4;
   boolean bLocalVlvTest5;
   boolean bLocalVlvTest6;


   SRVACTESTMNG_vidActrTst1Res();
   SRVACTESTMNG_vidActrTst2Res();
   SRVACTESTMNG_vidActrTst3Res();
   SRVACTESTMNG_vidActrTst4Res();

   bLocalVlvTest = 0;
   bLocalVlvTest2 = 0;
   bLocalVlvTest3 = 0;
   bLocalVlvTest4 = 0;
   bLocalVlvTest5 = 0;
   bLocalVlvTest6 = 0;
   if (ActrTstMng_bDftCmd != 0)
   {
      VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_ELEC_CMDE);
   }
   else
   {
      if (ActrTstMng_bScp != 0)
      {
         VEMS_vidSET(Srv_stActrTstFeedback, COURT_CIRCUIT_PLUS);
      }
      else
      {
         if (ActrTstMng_bScg != 0)
         {
            VEMS_vidSET(Srv_stActrTstFeedback, COURT_CIRCUIT_MASSE);
         }
         else
         {
            if (ActrTstMng_bOc != 0)
            {
               VEMS_vidSET(Srv_stActrTstFeedback, CIRCUIT_OUVERT);
            }
            else
            {
               if (ActrTstMng_bMap != 0)
               {
                  VEMS_vidSET(Srv_stActrTstFeedback, HORS_PLAGE_SIGNAL);
               }
               else
               {
                  if (ActrTstMng_bGavScp != 0 )
                  {
                     VEMS_vidSET(Srv_stActrTstFeedback, COURT_CIRCUIT_AGGRAVE);
                  }
                  else
                  {
                     bLocalVlvTest = 1;
                  }
               }
            }
         }
      }
   }
   if(bLocalVlvTest != 0)
   {
      if (ActrTstMng_bFrq != 0)
      {
         VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_FREQUENCE);
      }
      else
      {
         if (ActrTstMng_bStuckVlv != 0)
         {
            VEMS_vidSET(Srv_stActrTstFeedback, VANNE_COLLEE);
         }
         else
         {
            if (ActrTstMng_bDftEE != 0)
            {
               VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_ELECTRIQUE);
            }
            else
            {
               if (ActrTstMng_VvtStatPb != 0)
               {
                  VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_VVT_STAT);
               }
               else
               {
                  bLocalVlvTest2 = 1;
               }
            }
         }
      }
   }

   if (  (bLocalVlvTest != 0)
      && (bLocalVlvTest2 != 0))
   {
      if (ActrTstMng_VvtDynPb != 0)
      {
         VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_VVT_DYN);
      }
      else
      {
         if (ActrTstMng_bOcHiFan != 0)
         {
            VEMS_vidSET(Srv_stActrTstFeedback, CIRCUIT_OUVERT_GV);
         }
         else
         {
            if (ActrTstMng_bScgHiFan != 0)
            {
               VEMS_vidSET(Srv_stActrTstFeedback, COURT_CIRCUIT_MASSE_GV);
            }
            else
            {
               if (ActrTstMng_bScpHiFan != 0)
               {
                  VEMS_vidSET(Srv_stActrTstFeedback, COURT_CIRCUIT_PLUS_GV);
               }
               else
               {
                  if (ActrTstMng_bDurtyVlv != 0)
                  {
                     VEMS_vidSET(Srv_stActrTstFeedback, VANNE_ENCRASSEE);
                  }
                  else
                  {
                     bLocalVlvTest3 = 1;
                  }
               }
            }
         }
      }
   }

   if (  (bLocalVlvTest != 0)
      && (bLocalVlvTest2 != 0)
      && (bLocalVlvTest3 != 0))
   {
      if (ActrTstMng_bDftPrailLeak != 0)
      {
         VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_FUITE_PRES_RAIL);
      }
      else
      {
         if (ActrTstMng_bDftInjrFlow != 0)
         {
            VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_DEBIT_INJECTEUR);
         }
         else
         {
            bLocalVlvTest4 = 1;
         }
      }
   }
   if (  (bLocalVlvTest != 0)
      && (bLocalVlvTest2 != 0)
      && (bLocalVlvTest3 != 0)
      && (bLocalVlvTest4 != 0))
   {
      if (ActrTstMng_bUsPlausFco != 0)
      {
         VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_RICHESSE_BLOQUE_RICHE);
      }
      else
      {
         if (ActrTstMng_bUsPlausFld != 0)
         {
            VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_RICHESSE_BLOQUE_PAUVRE);
         }
         else
         {
            if (ActrTstMng_bOcCTP2 != 0)
            {
               VEMS_vidSET(Srv_stActrTstFeedback, CIRCUIT_OUVERT_CTP2);
            }
            else
            {
               if (ActrTstMng_bScpCTP2 != 0)
               {
                  VEMS_vidSET(Srv_stActrTstFeedback, COURT_CIRCUIT_PLUS_CTP2);
               }
               else
               {
                  bLocalVlvTest5 = 1;
               }
            }
         }
      }
   }
   if (  (bLocalVlvTest != 0)
      && (bLocalVlvTest2 != 0)
      && (bLocalVlvTest3 != 0)
      && (bLocalVlvTest4 != 0)
      && (bLocalVlvTest5 != 0))
   {
      if(ActrTstMng_bScgCTP2 != 0)
      {
         VEMS_vidSET(Srv_stActrTstFeedback, COURT_CIRCUIT_MASSE_CTP2);
      }
      else
      {
         if (ActrTstMng_bDftCTP1 != 0)
         {
            VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_1_CTP);
         }
         else
         {
            if (ActrTstMng_bDftCTP2 != 0)
            {
               VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_2_CTP);
            }
            else
            {
               if(ActrTstMng_bFlapFaild != 0)
               {
                  VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_VOLET);
               }
               else
               {
                  if(ActrTstMng_bFlapBlockOp != 0)
                  {
                     VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_VOLET_BLOQUE);
                  }
                  else
                  {
                     bLocalVlvTest6 = 1;
                  }
               }
            }
         }
      }
   }
   if (  (bLocalVlvTest != 0)
      && (bLocalVlvTest2 != 0)
      && (bLocalVlvTest3 != 0)
      && (bLocalVlvTest4 != 0)
      && (bLocalVlvTest5 != 0)
      && (bLocalVlvTest6 != 0))
   {
      if(ActrTstMng_bFlapStayOp != 0)
      {
         VEMS_vidSET(Srv_stActrTstFeedback, DEFAUT_VOLET_RESTE_OUVERT);
      }
      else
      {
         VEMS_vidSET(Srv_stActrTstFeedback, PAS_DE_DEFAUT);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidInj1Tst                                    */
/* !Description :  Fonction qui permet le test de l'injecteur 1.              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
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
void SRVACTESTMNG_vidInj1Tst(void)
{
   GDFRM_tenuGDUState LocalstDgoOc_Inj1Cmd;
   GDFRM_tenuGDUState LocalstDgoScp_Inj1Cmd;


   LocalstDgoOc_Inj1Cmd = GDGAR_tenuGetStDgo(GD_DFT_OC_INJ1CMD);
   LocalstDgoScp_Inj1Cmd = GDGAR_tenuGetStDgo(GD_DFT_SCP_INJ1CMD);
   if (  (LocalstDgoOc_Inj1Cmd == GDU_ETAT_PRESENT)
      || (LocalstDgoScp_Inj1Cmd ==  GDU_ETAT_PRESENT))
   {
      ActrTstMng_bDftEE = 1;
   }
   else
   {
      ActrTstMng_bDftEE = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bOc = 0;
   ActrTstMng_bScp = 0;
   ActrTstMng_bScg = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bDftInjrFlow = 0;
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
/* !Function    :  SRVACTESTMNG_vidInj2Tst                                    */
/* !Description :  Fonction de test de l'injecteur 2.                         */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
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
void SRVACTESTMNG_vidInj2Tst(void)
{
   GDFRM_tenuGDUState LocalstDgoOc_Inj2Cmd;
   GDFRM_tenuGDUState LocalstDgoScp_Inj2Cmd;


   LocalstDgoOc_Inj2Cmd = GDGAR_tenuGetStDgo(GD_DFT_OC_INJ2CMD);
   LocalstDgoScp_Inj2Cmd = GDGAR_tenuGetStDgo(GD_DFT_SCP_INJ2CMD);
   if (  (LocalstDgoOc_Inj2Cmd == GDU_ETAT_PRESENT)
      || (LocalstDgoScp_Inj2Cmd ==  GDU_ETAT_PRESENT))
   {
      ActrTstMng_bDftEE = 1;
   }
   else
   {
      ActrTstMng_bDftEE = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bOc = 0;
   ActrTstMng_bScp = 0;
   ActrTstMng_bScg = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bDftInjrFlow = 0;
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
/* !Function    :  SRVACTESTMNG_vidInj3Tst                                    */
/* !Description :  Fonction de test de l'injecteur 3.                         */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
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
void SRVACTESTMNG_vidInj3Tst(void)
{
   GDFRM_tenuGDUState LocalstDgoOc_Inj3Cmd;
   GDFRM_tenuGDUState LocalstDgoScp_Inj3Cmd;


   LocalstDgoOc_Inj3Cmd = GDGAR_tenuGetStDgo(GD_DFT_OC_INJ3CMD);
   LocalstDgoScp_Inj3Cmd = GDGAR_tenuGetStDgo(GD_DFT_SCP_INJ3CMD);
   if (  (LocalstDgoOc_Inj3Cmd == GDU_ETAT_PRESENT)
      || (LocalstDgoScp_Inj3Cmd ==  GDU_ETAT_PRESENT))
   {
      ActrTstMng_bDftEE = 1;
   }
   else
   {
      ActrTstMng_bDftEE = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bOc = 0;
   ActrTstMng_bScp = 0;
   ActrTstMng_bScg = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bDftInjrFlow = 0;
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
/* !Function    :  SRVACTESTMNG_vidCoil_1Tst                                  */
/* !Description :  Fonction de test de la bobine 1.                           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
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
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
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
void SRVACTESTMNG_vidCoil_1Tst(void)
{
   GDFRM_tenuGDUState LocalStDgoOc_IgCoil_1Cmd;
   GDFRM_tenuGDUState LocalStDgoScp_IgCoil_1Cmd;

   LocalStDgoOc_IgCoil_1Cmd = GDGAR_tenuGetStDgo(GD_DFT_OC_IGCOIL1CMD);
   LocalStDgoScp_IgCoil_1Cmd = GDGAR_tenuGetStDgo(GD_DFT_SCP_IGCOIL1CMD);

   if (LocalStDgoOc_IgCoil_1Cmd == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoScp_IgCoil_1Cmd == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
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
   ActrTstMng_bScg = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bDftInjrFlow = 0;
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
/* !Function    :  SRVACTESTMNG_vidCoil_2Tst                                  */
/* !Description :  Fonction de test de la bobine 2.                           */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
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
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bScg;                                           */
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
void SRVACTESTMNG_vidCoil_2Tst(void)
{
   GDFRM_tenuGDUState LocalStDgoOc_IgCoil_2Cmd;
   GDFRM_tenuGDUState LocalStDgoScp_IgCoil_2Cmd;


   LocalStDgoOc_IgCoil_2Cmd = GDGAR_tenuGetStDgo(GD_DFT_OC_IGCOIL2CMD);
   LocalStDgoScp_IgCoil_2Cmd = GDGAR_tenuGetStDgo(GD_DFT_SCP_IGCOIL2CMD);

   if (LocalStDgoOc_IgCoil_2Cmd == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoScp_IgCoil_2Cmd == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
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
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bScg = 0;
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
/*---------------------------- end of file -----------------------------------*/
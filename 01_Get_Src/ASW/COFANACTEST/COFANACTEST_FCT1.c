/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COFANACTEST                                             */
/* !Description     : COFANACTEST Component                                   */
/*                                                                            */
/* !Module          : COFANACTEST                                             */
/* !Description     :  TESTS ACTIONNEURS DES GMV                              */
/*                                                                            */
/* !File            : COFANACTEST_FCT1.C                                      */
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
/*   1 / COFANACTEST_vidInitOutput                                            */
/*   2 / COFANACTEST_vidGMVTstRun                                             */
/*   3 / COFANACTEST_vidGMVTstB                                               */
/*   4 / COFANACTEST_vidGMVTstC                                               */
/*   5 / COFANACTEST_vidBAcTstTransToEnd                                      */
/*   6 / COFANACTEST_vidBAcTstTransToIdle                                     */
/*   7 / COFANACTEST_vidCAcTstTransToIdle                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 00774 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/COFAN/COFANACTEST/COFANACTEST_FC$*/
/* $Revision::   1.1      $$Author::   HHAMLAOU       $$Date::   20 Dec 2012 $*/
/* $Author::   HHAMLAOU                               $$Date::   20 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "COFANACTEST.h"
#include "COFANACTEST_L.h"
#include "COFANACTEST_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANACTEST_vidInitOutput                                  */
/* !Description :  Initialisations des sorties                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoFan_LoStFan1_C;                                             */
/*  output boolean CoFan_bActrTstFan2Cmd;                                     */
/*  output boolean CoFan_bActrTstInProgs;                                     */
/*  output st85 CoFan_stBActrTst;                                             */
/*  output boolean CoFan_bActrTstFan1BCmd;                                    */
/*  output boolean CoFan_bB1TstCmpl;                                          */
/*  output boolean CoFan_bB2LoSpdTstCmpl;                                     */
/*  output boolean CoFan_bB2HiSpdTstCmpl;                                     */
/*  output st86 CoFan_stCActrTst;                                             */
/*  output uint16 CoFan_rActrTstFan1CCmd;                                     */
/*  output boolean CoFan_bCTstCmpl;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANACTEST_vidInitOutput(void)
{
   uint16 u16LocalCoFan_rActrTstFan1CCmd;
   uint32 u32LocalCoFan_LoStFan1_C;


   VEMS_vidSET(CoFan_bActrTstFan2Cmd, 0);
   VEMS_vidSET(CoFan_bActrTstInProgs, 0);
   /* Outputs Initialization for Motor Fan Type B1/B2 */
   CoFan_stBActrTst = COFAN_BACTRTST_IDLE;
   VEMS_vidSET(CoFan_bActrTstFan1BCmd, 0);
   VEMS_vidSET(CoFan_bB1TstCmpl, 0);
   VEMS_vidSET(CoFan_bB2LoSpdTstCmpl, 0);
   VEMS_vidSET(CoFan_bB2HiSpdTstCmpl, 0);
   /* Outputs Initialization for Motor Fan Type C */
   CoFan_stCActrTst = COFAN_CACTRTST_IDLE;
   u32LocalCoFan_LoStFan1_C = (uint32)((CoFan_LoStFan1_C * 32768) / 100);
   u16LocalCoFan_rActrTstFan1CCmd =
      (uint16)MATHSRV_udtMIN(u32LocalCoFan_LoStFan1_C, 32768);
   VEMS_vidSET(CoFan_rActrTstFan1CCmd, u16LocalCoFan_rActrTstFan1CCmd);
   VEMS_vidSET(CoFan_bCTstCmpl, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANACTEST_vidGMVTstRun                                   */
/* !Description :  La stratégie se décompose en 2 sous-fonctions :  Procédure */
/*                 de test actionneur pour des GMV de type B1 ou B2 et        */
/*                 Procédure de test actionneur pour des GMV de type C        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_09_00774_001.01                                     */
/*                 VEMS_R_09_00774_002.01                                     */
/*                 VEMS_R_09_00774_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COFANACTEST_vidGMVTstC();                                */
/*  extf argret void COFANACTEST_vidGMVTstB();                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*  output boolean CoFan_bActrTstFan2Cmd;                                     */
/*  output boolean CoFan_bActrTstInProgs;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANACTEST_vidGMVTstRun(void)
{
   uint8 u8LocalCf_cooling_fan_equipment;


   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCf_cooling_fan_equipment);
   if (u8LocalCf_cooling_fan_equipment == EQUIPMENT_C)
   {
      COFANACTEST_vidGMVTstC();
   }
   else
   {
      if (  (u8LocalCf_cooling_fan_equipment == EQUIPMENT_B1)
         || (u8LocalCf_cooling_fan_equipment == EQUIPMENT_B2))
      {
         COFANACTEST_vidGMVTstB();
      }
      else
      {
         VEMS_vidSET(CoFan_bActrTstFan2Cmd, 0);
         VEMS_vidSET(CoFan_bActrTstInProgs, 0);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANACTEST_vidGMVTstB                                     */
/* !Description :  Pour les tests de GMV type B1 ou B2 (petite et grande      */
/*                 vitesse), l’état de repos est une commande des 2 GMV à 1   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_09_00774_003.01                                     */
/*                 VEMS_R_09_00774_004.01                                     */
/*                 VEMS_R_09_00774_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void COFANACTEST_vidBAcTstTransToEnd();                       */
/*  extf argret void COFANACTEST_vidBAcTstTransToIdle();                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input uint8 Code_test_action;                                             */
/*  input st85 CoFan_stBActrTst;                                              */
/*  input uint16 CoFan_TiTstB1_C;                                             */
/*  input uint16 CoFan_TiTstB2LoSpd_C;                                        */
/*  input uint8 CoFan_TiTstB2HiSpd1_C;                                        */
/*  input uint16 CoFan_TiTst;                                                 */
/*  input uint8 CoFan_TempoB1_C;                                              */
/*  input uint8 CoFan_TempoB2LOSPD_C;                                         */
/*  input uint16 CoFan_TiTstB2HiSpd2_C;                                       */
/*  input uint8 CoFan_TiTstB2HiSpd3_C;                                        */
/*  input uint8 CoFan_TempoB2HISPD_C;                                         */
/*  input uint8 CoFan_TempoB1;                                                */
/*  input uint8 CoFan_TempoB2LOSPD;                                           */
/*  input uint8 CoFan_TempoB2HISPD;                                           */
/*  output st85 CoFan_stBActrTst;                                             */
/*  output boolean CoFan_bActrTstFan1BCmd;                                    */
/*  output uint16 CoFan_TiTst;                                                */
/*  output boolean CoFan_bB1TstCmpl;                                          */
/*  output boolean CoFan_bActrTstInProgs;                                     */
/*  output boolean CoFan_bActrTstFan2Cmd;                                     */
/*  output boolean CoFan_bB2LoSpdTstCmpl;                                     */
/*  output boolean CoFan_bB2HiSpdTstCmpl;                                     */
/*  output uint8 CoFan_TempoB1;                                               */
/*  output uint8 CoFan_TempoB2LOSPD;                                          */
/*  output uint8 CoFan_TempoB2HISPD;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANACTEST_vidGMVTstB(void)
{
   boolean bLocalSrv_bActrTstEna;
   uint8   u8LocalCode_test_action;
   uint8   u8LocalCoFan_TempoB1;
   uint8   u8LocalCoFan_TempoB2HISPD;
   uint8   u8LocalCoFan_TempoB2LOSPD;
   uint16  u16LocalCoFan_TiTst;


   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);

   switch (CoFan_stBActrTst)
   {
      case COFAN_BACTRTST_IDLE:
         if (bLocalSrv_bActrTstEna != 0)
         {
            if (u8LocalCode_test_action == CODE_TEST_B1FAN)
            {
               CoFan_stBActrTst = COFAN_BACTRTST_B1PRGS;
               VEMS_vidSET(CoFan_bActrTstFan1BCmd, 1);
               CoFan_TiTst = (uint16)MATHSRV_udtMIN(CoFan_TiTstB1_C, 6000);
               VEMS_vidSET(CoFan_bB1TstCmpl, 0);
               VEMS_vidSET(CoFan_bActrTstInProgs, 1);
            }
            else
            {
               if (u8LocalCode_test_action == CODE_TEST_B2FANLOSPD)
               {
                  CoFan_stBActrTst = COFAN_BACTRTST_B2LOSPDPRGS;
                  VEMS_vidSET(CoFan_bActrTstFan2Cmd, 1);
                  CoFan_TiTst = (uint16)MATHSRV_udtMIN(CoFan_TiTstB2LoSpd_C,
                                                       6000);
                  VEMS_vidSET(CoFan_bB2LoSpdTstCmpl, 0);
                  VEMS_vidSET(CoFan_bActrTstInProgs, 1);
               }
               else
               {
                  if (u8LocalCode_test_action == CODE_TEST_B2FANHISPD)
                  {
                     CoFan_stBActrTst = COFAN_BACTRTST_B2HISPD1PRGS;
                     VEMS_vidSET(CoFan_bActrTstFan2Cmd, 1);
                     VEMS_vidSET(CoFan_bActrTstFan1BCmd, 0);
                     CoFan_TiTst = (uint16)(CoFan_TiTstB2HiSpd1_C + 30);
                     VEMS_vidSET(CoFan_bB2HiSpdTstCmpl, 0);
                     VEMS_vidSET(CoFan_bActrTstInProgs, 1);
                  }
               }
            }
         }
         break;

      case COFAN_BACTRTST_B1PRGS:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_B1FAN))
         {
            COFANACTEST_vidBAcTstTransToEnd();
         }
         else
         {
            if (CoFan_TiTst <= 1)
            {
               CoFan_stBActrTst = COFAN_BACTRTST_B1END;
               VEMS_vidSET(CoFan_bActrTstFan1BCmd, 0);
               VEMS_vidSET(CoFan_bB1TstCmpl, 1);
               CoFan_TempoB1 = (uint8)MATHSRV_udtMIN(CoFan_TempoB1_C, 250);
            }
            else
            {
               u16LocalCoFan_TiTst = (uint16)(CoFan_TiTst - 1);
               CoFan_TiTst = (uint16)MATHSRV_udtMIN(u16LocalCoFan_TiTst, 6000);
            }
         }
         break;

      case COFAN_BACTRTST_B2LOSPDPRGS:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_B2FANLOSPD))
         {
            COFANACTEST_vidBAcTstTransToEnd();
         }
         else
         {
            if (CoFan_TiTst <= 1)
            {
               CoFan_stBActrTst = COFAN_BACTRTST_B2LOSPDEND;
               VEMS_vidSET(CoFan_bActrTstFan2Cmd, 0);
               VEMS_vidSET(CoFan_bB2LoSpdTstCmpl, 1);
               CoFan_TempoB2LOSPD = (uint8)MATHSRV_udtMIN(CoFan_TempoB2LOSPD_C,
                                                          250);
            }
            else
            {
               u16LocalCoFan_TiTst = (uint16)(CoFan_TiTst - 1);
               CoFan_TiTst = (uint16)MATHSRV_udtMIN(u16LocalCoFan_TiTst, 6000);
            }
         }
         break;

      case COFAN_BACTRTST_B2HISPD1PRGS:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_B2FANHISPD))
         {
            COFANACTEST_vidBAcTstTransToEnd();
         }
         else
         {
            if (CoFan_TiTst <= 1)
            {
               CoFan_stBActrTst = COFAN_BACTRTST_B2HISPD2PRGS;
               VEMS_vidSET(CoFan_bActrTstFan2Cmd, 1);
               VEMS_vidSET(CoFan_bActrTstFan1BCmd, 1);
               u16LocalCoFan_TiTst = CoFan_TiTstB2HiSpd2_C;
            }
            else
            {
               u16LocalCoFan_TiTst = (uint16)(CoFan_TiTst - 1);
            }
            CoFan_TiTst = (uint16)MATHSRV_udtMIN(u16LocalCoFan_TiTst, 6000);
         }
         break;

      case COFAN_BACTRTST_B2HISPD2PRGS:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_B2FANHISPD))
         {
            COFANACTEST_vidBAcTstTransToEnd();
         }
         else
         {
            if (CoFan_TiTst <= 1)
            {
               CoFan_stBActrTst = COFAN_BACTRTST_B2HISPD3PRGS;
               VEMS_vidSET(CoFan_bActrTstFan2Cmd, 1);
               VEMS_vidSET(CoFan_bActrTstFan1BCmd, 0);
               CoFan_TiTst = (uint16)(CoFan_TiTstB2HiSpd3_C + 30);
            }
            else
            {
               u16LocalCoFan_TiTst = (uint16)(CoFan_TiTst - 1);
               CoFan_TiTst = (uint16)MATHSRV_udtMIN(u16LocalCoFan_TiTst, 6000);
            }
         }
         break;

      case COFAN_BACTRTST_B2HISPD3PRGS:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_B2FANHISPD))
         {
            COFANACTEST_vidBAcTstTransToEnd();
         }
         else
         {
            if (CoFan_TiTst <= 1)
            {
               CoFan_stBActrTst = COFAN_BACTRTST_B2HISPDEND;
               VEMS_vidSET(CoFan_bActrTstFan2Cmd, 0);
               VEMS_vidSET(CoFan_bActrTstFan1BCmd, 0);
               VEMS_vidSET(CoFan_bB2HiSpdTstCmpl, 1);
               CoFan_TempoB2HISPD = (uint8)MATHSRV_udtMIN(CoFan_TempoB2HISPD_C,
                                                          250);
            }
            else
            {
               u16LocalCoFan_TiTst = (uint16)(CoFan_TiTst - 1);
               CoFan_TiTst = (uint16)MATHSRV_udtMIN(u16LocalCoFan_TiTst, 6000);
            }
         }
         break;

      case COFAN_BACTRTST_B1END:
         if(CoFan_TempoB1 == 0)
         {
            COFANACTEST_vidBAcTstTransToEnd();
         }
         else
         {
            u8LocalCoFan_TempoB1 = (uint8)(CoFan_TempoB1 - 1);
            CoFan_TempoB1 = (uint8)MATHSRV_udtMIN(u8LocalCoFan_TempoB1, 250);
         }
         break;

      case COFAN_BACTRTST_B2LOSPDEND:
         if(CoFan_TempoB2LOSPD == 0)
         {
            COFANACTEST_vidBAcTstTransToEnd();
         }
         else
         {
            u8LocalCoFan_TempoB2LOSPD = (uint8)(CoFan_TempoB2LOSPD - 1);
            CoFan_TempoB2LOSPD =
               (uint8)MATHSRV_udtMIN(u8LocalCoFan_TempoB2LOSPD, 250);
         }
         break;

      case COFAN_BACTRTST_B2HISPDEND:
         if(CoFan_TempoB2HISPD == 0)
         {
            COFANACTEST_vidBAcTstTransToEnd();
         }
         else
         {
            u8LocalCoFan_TempoB2HISPD = (uint8)(CoFan_TempoB2HISPD - 1);
            CoFan_TempoB2HISPD =
               (uint8)MATHSRV_udtMIN(u8LocalCoFan_TempoB2HISPD, 250);
         }
         break;

      case COFAN_BACTRTST_END:
         if (  (bLocalSrv_bActrTstEna != 0)
            && (  (u8LocalCode_test_action == CODE_TEST_B1FAN)
               || (u8LocalCode_test_action == CODE_TEST_B2FANLOSPD)
               || (u8LocalCode_test_action == CODE_TEST_B2FANHISPD)))
         {
            COFANACTEST_vidBAcTstTransToIdle();
         }
         break;

      default:
         COFANACTEST_vidBAcTstTransToIdle();
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANACTEST_vidGMVTstC                                     */
/* !Description :  Pour le test de GMV type C, l’état de repos est une        */
/*                 commande GMV2 à 0 et GMV1 à 0.Pendant le test, on active le*/
/*                 GMV2 pendant tous le temps du test et on fait varier la    */
/*                 commande du GMV1.                                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_09_00774_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void COFANACTEST_vidCAcTstTransToIdle();                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input uint8 Code_test_action;                                             */
/*  input st86 CoFan_stCActrTst;                                              */
/*  input uint8 CoFan_LoStFan1_C;                                             */
/*  input boolean CoFan_bCFricFan2Step1_C;                                    */
/*  input uint8 CoFan_TiStep1_C;                                              */
/*  input uint16 CoFan_TiCTst;                                                */
/*  input uint8 CoFan_CFricMinSpd_C;                                          */
/*  input boolean CoFan_bCFricFan2Step2_C;                                    */
/*  input uint16 CoFan_TiStep2_C;                                             */
/*  input uint8 CoFan_CFricMaxSpd_C;                                          */
/*  input boolean CoFan_bCFricFan2Step3_C;                                    */
/*  input uint16 CoFan_TiStep3_C;                                             */
/*  input uint16 CoFan_rActrTstFan1CCmd;                                      */
/*  input boolean CoFan_bCFricFan2Step4_C;                                    */
/*  input uint16 CoFan_TiStep4_C;                                             */
/*  input uint8 CoFan_TempoCprime_C;                                          */
/*  input boolean CoFan_bCFricFan2End_C;                                      */
/*  input uint8 CoFan_TempoCprime;                                            */
/*  output st86 CoFan_stCActrTst;                                             */
/*  output boolean CoFan_bActrTstInProgs;                                     */
/*  output uint16 CoFan_rActrTstFan1CCmd;                                     */
/*  output boolean CoFan_bActrTstFan2Cmd;                                     */
/*  output uint16 CoFan_TiCTst;                                               */
/*  output uint8 CoFan_TempoCprime;                                           */
/*  output boolean CoFan_bCTstCmpl;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANACTEST_vidGMVTstC(void)
{
   boolean bLocalSrv_bActrTstEna;
   boolean bLocalCoFan_bActrTstFan2Cmd;
   uint8   u8LocalCode_test_action;
   uint16  u16LocalCoFan_rActrTstFan1CCmd;
   uint8   u8LocalCoFan_TempoCprime;
   uint16  u16LocalCoFan_TiCTst;
   uint16  u16LocalCoFan_rActrTstFan1CCm;
   sint32  s32LocalCoFan_rActrTstFan1CCmd;
   uint32  u32LocalCoFan_TiCTst;
   uint32  u32LocalCoFan_LoStFan1_C;
   uint32  u32LocalCoFan_CFricMaxSpd_C;
   uint32  u32LocalCoFan_CFricMinSpd_C;


   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);

   switch (CoFan_stCActrTst)
   {
      case COFAN_CACTRTST_IDLE:
         if (  (bLocalSrv_bActrTstEna != 0)
            && (u8LocalCode_test_action == CODE_TEST_CFAN))
         {
            CoFan_stCActrTst = COFAN_CACTRTST_STEP1;
            u32LocalCoFan_LoStFan1_C =(uint32)( (CoFan_LoStFan1_C * 32768)
                                              / 100);
            u16LocalCoFan_rActrTstFan1CCmd =
               (uint16)MATHSRV_udtMIN(u32LocalCoFan_LoStFan1_C, 32768);
            VEMS_vidSET(CoFan_bActrTstInProgs, 1);
            VEMS_vidSET(CoFan_rActrTstFan1CCmd, u16LocalCoFan_rActrTstFan1CCmd);
            bLocalCoFan_bActrTstFan2Cmd = CoFan_bCFricFan2Step1_C;
            VEMS_vidSET(CoFan_bActrTstFan2Cmd,bLocalCoFan_bActrTstFan2Cmd);
            CoFan_TiCTst = (uint16)CoFan_TiStep1_C;
         }
         break;

      case COFAN_CACTRTST_STEP1:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_CFAN))
         {
            COFANACTEST_vidCAcTstTransToIdle();
         }
         else
         {
            if (CoFan_TiCTst <= 1)
            {
               CoFan_stCActrTst = COFAN_CACTRTST_STEP2;
               u32LocalCoFan_CFricMinSpd_C = (uint32)( ( CoFan_CFricMinSpd_C
                                                       * 32768)
                                                     / 100);
               u16LocalCoFan_rActrTstFan1CCmd =
                  (uint16)MATHSRV_udtMIN(u32LocalCoFan_CFricMinSpd_C, 32768);
               VEMS_vidSET(CoFan_rActrTstFan1CCmd,
                           u16LocalCoFan_rActrTstFan1CCmd);
               bLocalCoFan_bActrTstFan2Cmd = CoFan_bCFricFan2Step2_C;
               VEMS_vidSET(CoFan_bActrTstFan2Cmd,bLocalCoFan_bActrTstFan2Cmd);
               u16LocalCoFan_TiCTst = CoFan_TiStep2_C;
            }
            else
            {
               u16LocalCoFan_TiCTst = (uint16)(CoFan_TiCTst - 1);
            }
            CoFan_TiCTst = (uint16)MATHSRV_udtMIN(u16LocalCoFan_TiCTst, 6000);
         }
         break;

      case COFAN_CACTRTST_STEP2:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_CFAN))
         {
            COFANACTEST_vidCAcTstTransToIdle();
         }
         else
         {
            if (CoFan_TiCTst <= 1)
            {
               CoFan_stCActrTst = COFAN_CACTRTST_STEP3;
               u32LocalCoFan_CFricMaxSpd_C = (uint32)( ( CoFan_CFricMaxSpd_C
                                                       * 32768)
                                                     / 100);
               u16LocalCoFan_rActrTstFan1CCmd =
                  (uint16)MATHSRV_udtMIN(u32LocalCoFan_CFricMaxSpd_C, 32768);
               VEMS_vidSET(CoFan_rActrTstFan1CCmd,
                           u16LocalCoFan_rActrTstFan1CCmd);
               bLocalCoFan_bActrTstFan2Cmd = CoFan_bCFricFan2Step3_C;
               VEMS_vidSET(CoFan_bActrTstFan2Cmd,bLocalCoFan_bActrTstFan2Cmd);
               u16LocalCoFan_TiCTst = CoFan_TiStep3_C;
            }
            else
            {
               u16LocalCoFan_TiCTst = (uint16)(CoFan_TiCTst - 1);
               s32LocalCoFan_rActrTstFan1CCmd = (sint32)( CoFan_CFricMaxSpd_C
                                                        - CoFan_CFricMinSpd_C);
               if (CoFan_TiStep2_C != 0)
               {
                  VEMS_vidGET(CoFan_rActrTstFan1CCmd,
                              u16LocalCoFan_rActrTstFan1CCm);
                  s32LocalCoFan_rActrTstFan1CCmd =
                     s32LocalCoFan_rActrTstFan1CCmd * 32768 ;
                  s32LocalCoFan_rActrTstFan1CCmd =
                     s32LocalCoFan_rActrTstFan1CCmd / (CoFan_TiStep2_C * 100);
                  s32LocalCoFan_rActrTstFan1CCmd =
                     u16LocalCoFan_rActrTstFan1CCm
                     + s32LocalCoFan_rActrTstFan1CCmd;
                  u16LocalCoFan_rActrTstFan1CCmd =
                     (uint16)MATHSRV_udtCLAMP(s32LocalCoFan_rActrTstFan1CCmd,
                                              0,
                                              32768);
                  VEMS_vidSET(CoFan_rActrTstFan1CCmd,
                              u16LocalCoFan_rActrTstFan1CCmd);
               }
               else
               {
                  if (s32LocalCoFan_rActrTstFan1CCmd > 0)
                  {
                     VEMS_vidSET(CoFan_rActrTstFan1CCmd, 32768);
                  }
               }
            }
            CoFan_TiCTst = (uint16)MATHSRV_udtMIN(u16LocalCoFan_TiCTst, 6000);
         }
         break;

      case COFAN_CACTRTST_STEP3:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_CFAN))
         {
            COFANACTEST_vidCAcTstTransToIdle();
         }
         else
         {
            if (CoFan_TiCTst <= 1)
            {
               CoFan_stCActrTst = COFAN_CACTRTST_STEP4;
               u32LocalCoFan_LoStFan1_C = (uint32)( (CoFan_LoStFan1_C * 32768)
                                                  / 100);
               u16LocalCoFan_rActrTstFan1CCmd =
                  (uint16)MATHSRV_udtMIN(u32LocalCoFan_LoStFan1_C, 32768);
               VEMS_vidSET(CoFan_rActrTstFan1CCmd,
                           u16LocalCoFan_rActrTstFan1CCmd);
               bLocalCoFan_bActrTstFan2Cmd = CoFan_bCFricFan2Step4_C;
               VEMS_vidSET(CoFan_bActrTstFan2Cmd,bLocalCoFan_bActrTstFan2Cmd);
               u32LocalCoFan_TiCTst = (uint32)(CoFan_TiStep4_C + 30);
               CoFan_TiCTst = (uint16)MATHSRV_udtMIN(u32LocalCoFan_TiCTst,
                                                     6000);
            }
            else
            {
               u16LocalCoFan_TiCTst = (uint16)(CoFan_TiCTst - 1);
               CoFan_TiCTst = (uint16)MATHSRV_udtMIN(u16LocalCoFan_TiCTst,
                                                     6000);
            }
         }
         break;

      case COFAN_CACTRTST_STEP4:
         if (  (bLocalSrv_bActrTstEna == 0)
            || (u8LocalCode_test_action != CODE_TEST_CFAN))
         {
            COFANACTEST_vidCAcTstTransToIdle();
         }
         else
         {
            if (CoFan_TiCTst <= 1)
            {
               CoFan_stCActrTst = COFAN_CACTRTST_END;
               CoFan_TempoCprime = (uint8)MATHSRV_udtMIN(CoFan_TempoCprime_C,
                                                         250);
               VEMS_vidSET(CoFan_bCTstCmpl, 1);
               u32LocalCoFan_LoStFan1_C = (uint32)( (CoFan_LoStFan1_C * 32768)
                                                  / 100);
               u16LocalCoFan_rActrTstFan1CCmd =
                  (uint16)MATHSRV_udtMIN(u32LocalCoFan_LoStFan1_C, 32768);
               VEMS_vidSET(CoFan_rActrTstFan1CCmd,
                           u16LocalCoFan_rActrTstFan1CCmd);
               bLocalCoFan_bActrTstFan2Cmd = CoFan_bCFricFan2End_C;
               VEMS_vidSET(CoFan_bActrTstFan2Cmd, bLocalCoFan_bActrTstFan2Cmd);
               VEMS_vidSET(CoFan_bActrTstInProgs, 0);
            }
            else
            {
               u16LocalCoFan_TiCTst = (uint16)(CoFan_TiCTst - 1);
               CoFan_TiCTst = (uint16)MATHSRV_udtMIN(u16LocalCoFan_TiCTst,
                                                     6000);
            }
         }
         break;

      case COFAN_CACTRTST_END:
         if (  (bLocalSrv_bActrTstEna != 0)
            && (u8LocalCode_test_action == CODE_TEST_CFAN)
            && (CoFan_TempoCprime == 0))
         {
            COFANACTEST_vidCAcTstTransToIdle();
         }
         else
         {
            u8LocalCoFan_TempoCprime = (uint8)(CoFan_TempoCprime - 1);
            CoFan_TempoCprime = (uint8)MATHSRV_udtMIN(u8LocalCoFan_TempoCprime,
                                                      250);
         }
         break;

      default:
         COFANACTEST_vidCAcTstTransToIdle();
         SWFAIL_vidSoftwareErrorHook();
      break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANACTEST_vidBAcTstTransToEnd                            */
/* !Description :  Execution de l'Entry lors de la transition à l'état        */
/*                 COFAN_BACTRTST_END                                         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st85 CoFan_stBActrTst;                                             */
/*  output boolean CoFan_bActrTstFan1BCmd;                                    */
/*  output boolean CoFan_bActrTstFan2Cmd;                                     */
/*  output boolean CoFan_bActrTstInProgs;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANACTEST_vidBAcTstTransToEnd(void)
{
   CoFan_stBActrTst = COFAN_BACTRTST_END;
   VEMS_vidSET(CoFan_bActrTstFan1BCmd, 0);
   VEMS_vidSET(CoFan_bActrTstFan2Cmd, 0);
   VEMS_vidSET(CoFan_bActrTstInProgs, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANACTEST_vidBAcTstTransToIdle                           */
/* !Description :  Execution de l'Entry lors de la transition à l'état        */
/*                 COFAN_BACTRTST_IDLE                                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st85 CoFan_stBActrTst;                                             */
/*  output boolean CoFan_bActrTstFan1BCmd;                                    */
/*  output boolean CoFan_bActrTstFan2Cmd;                                     */
/*  output boolean CoFan_bActrTstInProgs;                                     */
/*  output boolean CoFan_bB1TstCmpl;                                          */
/*  output boolean CoFan_bB2LoSpdTstCmpl;                                     */
/*  output boolean CoFan_bB2HiSpdTstCmpl;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANACTEST_vidBAcTstTransToIdle(void)
{
   CoFan_stBActrTst = COFAN_BACTRTST_IDLE;
   VEMS_vidSET(CoFan_bActrTstFan1BCmd, 0);
   VEMS_vidSET(CoFan_bActrTstFan2Cmd, 0);
   VEMS_vidSET(CoFan_bActrTstInProgs, 0);
   VEMS_vidSET(CoFan_bB1TstCmpl, 0);
   VEMS_vidSET(CoFan_bB2LoSpdTstCmpl, 0);
   VEMS_vidSET(CoFan_bB2HiSpdTstCmpl, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANACTEST_vidCAcTstTransToIdle                           */
/* !Description :  Execution de l'Entry lors de la transition à l'état        */
/*                 COFAN_CACTRTST_IDLE                                        */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoFan_LoStFan1_C;                                             */
/*  input boolean CoFan_bCFricFan2Idle_C;                                     */
/*  output st86 CoFan_stCActrTst;                                             */
/*  output uint16 CoFan_rActrTstFan1CCmd;                                     */
/*  output boolean CoFan_bActrTstFan2Cmd;                                     */
/*  output boolean CoFan_bActrTstInProgs;                                     */
/*  output boolean CoFan_bCTstCmpl;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANACTEST_vidCAcTstTransToIdle(void)
{
   boolean bLocalCoFan_bActrTstFan2Cmd;
   uint16  u16LocalCoFan_rActrTstFan1CCmd;
   uint32  u32LocalCoFan_LoStFan1_C;


   CoFan_stCActrTst = COFAN_CACTRTST_IDLE;
   u32LocalCoFan_LoStFan1_C = (uint32)((CoFan_LoStFan1_C * 32768) / 100);
   u16LocalCoFan_rActrTstFan1CCmd =
      (uint16)MATHSRV_udtMIN(u32LocalCoFan_LoStFan1_C, 32768);
   VEMS_vidSET(CoFan_rActrTstFan1CCmd, u16LocalCoFan_rActrTstFan1CCmd);
   bLocalCoFan_bActrTstFan2Cmd = CoFan_bCFricFan2Idle_C;
   VEMS_vidSET(CoFan_bActrTstFan2Cmd,bLocalCoFan_bActrTstFan2Cmd);
   VEMS_vidSET(CoFan_bActrTstInProgs, 0);
   VEMS_vidSET(CoFan_bCTstCmpl, 0);
}
/*------------------------------- end of file --------------------------------*/
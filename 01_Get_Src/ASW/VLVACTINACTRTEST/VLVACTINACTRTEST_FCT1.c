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
/* !File            : VLVACTINACTRTEST_FCT1.C                                 */
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
/*   1 / VLVACTINACTRTEST_vidInitializati                                     */
/*   2 / VLVACTINACTRTEST_vidCalcSdlFast                                      */
/*   3 / VLVACTINACTRTEST_vidCriteriaCalc                                     */
/*   4 / VLVACTINACTRTEST_vidStatErrorCom                                     */
/*   5 / VLVACTINACTRTEST_vidAgregatedErr                                     */
/*   6 / VLVACTINACTRTEST_vidStatErrorMea                                     */
/*   7 / VLVACTINACTRTEST_vidStErrCritClc                                     */
/*   8 / VLVACTINACTRTEST_vidSpeedErrorCo                                     */
/*   9 / VLVACTINACTRTEST_vidFstSpdErrClc                                     */
/*   10 / VLVACTINACTRTEST_vidSetpointCrit                                    */
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
/* !Function    :  VLVACTINACTRTEST_vidInitializati                           */
/* !Description :  initialisation des variables de sorties et de l'automate.  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean VlvAct_bInActrTestStatErrRef1;                             */
/*  output boolean VlvAct_bInActrTestStatErrRef2;                             */
/*  output boolean VlvAct_bInActrTestStatErrMax1;                             */
/*  output boolean VlvAct_bInActrTestStatErrMax2;                             */
/*  output boolean VlvAct_bInActrTestStatErrRef3;                             */
/*  output boolean VlvAct_bInActrTest2RampSpdErrIdc;                          */
/*  output boolean VlvAct_bInActrTest3RampSpdErrIdc;                          */
/*  output boolean VlvAct_bInActrTest4RampSpdErrIdc;                          */
/*  output boolean VlvAct_bInActrTest1RampSpdErrIdc;                          */
/*  output boolean Srv_bActrTstInVVTEna;                                      */
/*  output uint32 VlvAct_agInActrTstAddErrPrev;                               */
/*  output uint32 VLVACTINACTRTEST_u32CalcPhase1;                             */
/*  output uint32 VLVACTINACTRTEST_u32CalcPhase3;                             */
/*  output uint32 VLVACTINACTRTEST_u32CalcPhase5;                             */
/*  output uint32 VLVACTINACTRTEST_u32CalcPhase8;                             */
/*  output uint32 VLVACTINACTRTEST_u32CalcPhase10;                            */
/*  output boolean VLVACTINACTRTEST_bCompCalc2Prev;                           */
/*  output boolean VLVACTINACTRTEST_bCompCalc1Prev;                           */
/*  output uint16 VLVACTINACTRTEST_u16CalcPhase2;                             */
/*  output uint16 VLVACTINACTRTEST_u16CalcPhase4;                             */
/*  output uint16 VLVACTINACTRTEST_u16CalcPhase7;                             */
/*  output uint16 VLVACTINACTRTEST_u16CalcPhase9;                             */
/*  output uint8 VLVACTINACTRTEST_u8CdeTstActPrev;                            */
/*  output boolean VLVACTINACTRTEST_SrvbInVVTEnPrev;                          */
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output st117 VlvAct_stInActrTstLstSt;                                     */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*  output boolean VlvAct_bInActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidInitializati(void)
{
   VEMS_vidSET(VlvAct_bInActrTestStatErrRef1, 0);
   VEMS_vidSET(VlvAct_bInActrTestStatErrRef2, 0);
   VEMS_vidSET(VlvAct_bInActrTestStatErrMax1, 0);
   VEMS_vidSET(VlvAct_bInActrTestStatErrMax2, 0);
   VEMS_vidSET(VlvAct_bInActrTestStatErrRef3, 0);
   VEMS_vidSET(VlvAct_bInActrTest2RampSpdErrIdc, 0);
   VEMS_vidSET(VlvAct_bInActrTest3RampSpdErrIdc, 0);
   VEMS_vidSET(VlvAct_bInActrTest4RampSpdErrIdc, 0);
   VEMS_vidSET(VlvAct_bInActrTest1RampSpdErrIdc, 0);
   VEMS_vidSET(Srv_bActrTstInVVTEna, 0);
   VlvAct_agInActrTstAddErrPrev  = 0;
   VLVACTINACTRTEST_u32CalcPhase1 = 0;
   VLVACTINACTRTEST_u32CalcPhase3 = 0;
   VLVACTINACTRTEST_u32CalcPhase5 = 0;
   VLVACTINACTRTEST_u32CalcPhase8 = 0;
   VLVACTINACTRTEST_u32CalcPhase10 = 0;
   VLVACTINACTRTEST_bCompCalc2Prev = 0;
   VLVACTINACTRTEST_bCompCalc1Prev = 0;
   VLVACTINACTRTEST_u16CalcPhase2 = 0;
   VLVACTINACTRTEST_u16CalcPhase4 = 0;
   VLVACTINACTRTEST_u16CalcPhase7 = 0;
   VLVACTINACTRTEST_u16CalcPhase9 = 0;
   VLVACTINACTRTEST_u8CdeTstActPrev = 0;
   VLVACTINACTRTEST_SrvbInVVTEnPrev = 0;
   /*stateflow initialization*/
   VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_IDLE);
   VEMS_vidSET(VlvAct_stInActrTstLstSt, VLVACT_INACTRTST_IDLE);
   VEMS_vidSET(VlvAct_agInActrTestPosSp, 0);
   VEMS_vidSET(VlvAct_bInActrTestSpEndIdc, 0);
   VEMS_vidSET(VlvAct_bInActrTestNotRun, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidCalcSdlFast                            */
/* !Description :  calcule de l'evenement SdlFast.                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACTRTEST_vidSetpointComp();                      */
/*  extf argret void VLVACTINACTRTEST_vidCriteriaCalc();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input uint8 Code_test_action;                                             */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input boolean VLVACTINACTRTEST_SrvbInVVTEnPrev;                           */
/*  output boolean VLVACTINACTRTEST_SrvbInVVTEnPrev;                          */
/*  output boolean Srv_bActrTstInVVTEna;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidCalcSdlFast(void)
{
   boolean bLocalSrv_bActrTstEna;
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);

   if (VlvAct_bAcvVlvActInStr_C != 0)
   {
      VLVACTINACTRTEST_vidSetpointComp();
      VLVACTINACTRTEST_vidCriteriaCalc();
   }

   VEMS_vidGET(Srv_bActrTstInVVTEna, VLVACTINACTRTEST_SrvbInVVTEnPrev);

   if (  (bLocalSrv_bActrTstEna != 0)
      && (u8LocalCode_test_action == CODE_TEST_VVT_ADM))
   {
      VEMS_vidSET(Srv_bActrTstInVVTEna, 1);
   }
   else
   {
      VEMS_vidSET(Srv_bActrTstInVVTEna, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidCriteriaCalc                           */
/* !Description :  Ce bloc calcule deux types de critère :Pour les rampes ou  */
/*                 échelons on calcule le retard ( erreur de vitesse ) ET Pour*/
/*                 les phases stabilisées du profil, on calcule l’erreur      */
/*                 statique.                                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Z.HOSNI                                                    */
/* !Trace_To    :  VEMS_R_09_05822_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINACTRTEST_vidStatErrorCom();                      */
/*  extf argret void VLVACTINACTRTEST_vidSpeedErrorCo();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidCriteriaCalc(void)
{
   VLVACTINACTRTEST_vidStatErrorCom();
   VLVACTINACTRTEST_vidSpeedErrorCo();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidStatErrorCom                           */
/* !Description :  Dans ce bloc sont calculées les erreurs statiques.         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACTRTEST_vidAgregatedErr();                      */
/*  extf argret void VLVACTINACTRTEST_vidStatErrorMea();                      */
/*  extf argret void VLVACTINACTRTEST_vidStErrCritClc();                      */
/*  input st114 VlvAct_stInActrTst;                                           */
/*  input uint32 VlvAct_agInActrTestAddErrRefInt;                             */
/*  input uint32 VlvAct_agInActrTestAddErrRef;                                */
/*  output boolean VlvAct_bInActrTestSpStatErrEna;                            */
/*  output uint32 VlvAct_agInActrTestAddErrRef;                               */
/*  output uint32 VlvAct_agInActrTstAddErrPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidStatErrorCom(void)
{
   uint8 u8LocalVlvAct_stInActrTst;


   VEMS_vidGET(VlvAct_stInActrTst, u8LocalVlvAct_stInActrTst);

   if (  (u8LocalVlvAct_stInActrTst == VLV_INACTRTST_PHASE1)
      || (u8LocalVlvAct_stInActrTst == VLV_INACTRTST_PHASE3)
      || (u8LocalVlvAct_stInActrTst == VLV_INACTRTST_PHASE5)
      || (u8LocalVlvAct_stInActrTst == VLV_INACTRTST_PHASE6)
      || (u8LocalVlvAct_stInActrTst == VLV_INACTRTST_PHASE8)
      || (u8LocalVlvAct_stInActrTst == VLV_INACTRTST_PHASE10))
   {
      VlvAct_bInActrTestSpStatErrEna = 1;
      VLVACTINACTRTEST_vidAgregatedErr();
      VlvAct_agInActrTestAddErrRef =
         MATHSRV_udtMIN(VlvAct_agInActrTestAddErrRefInt, 1066666);
   }
   else
   {
      VlvAct_bInActrTestSpStatErrEna = 0;
      VlvAct_agInActrTestAddErrRef = 0;
   }

   VLVACTINACTRTEST_vidStatErrorMea();
   VLVACTINACTRTEST_vidStErrCritClc();
   VlvAct_agInActrTstAddErrPrev = VlvAct_agInActrTestAddErrRef;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidAgregatedErr                           */
/* !Description :  Dans ce bloc est calculée l’erreur statique cumulée pour   */
/*                 chaque phase stabilisée de la consigne envoyée lors  du    */
/*                 test actionneur de la VVT admission.                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret uint32  MATHSRV_u32Add_u32_u32(argin uint32 u32FirstValue,    */
/* argin uint32 u32SecondValue);                                              */
/*  input uint16 Vxx_vvtc_in_angl_sp;                                         */
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  input uint32 VlvAct_agInActrTstAddErrPrev;                                */
/*  output uint32 VlvAct_agInActrTestAddErrRefInt;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidAgregatedErr(void)
{
   uint16 u16LocalVxx_vvtc_in_angl_sp;
   uint16 u16LocalVlvAct_agCmInPosnEstim;
   uint32 u32LocalCalcSum;
   uint32 u32LocalVarAbs;
   sint32 s32LocalCalcDiff;


   VEMS_vidGET(Vxx_vvtc_in_angl_sp, u16LocalVxx_vvtc_in_angl_sp);
   VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);

   s32LocalCalcDiff = (sint32)( u16LocalVxx_vvtc_in_angl_sp
                              - u16LocalVlvAct_agCmInPosnEstim);

   u32LocalVarAbs = (uint32)MATHSRV_udtABS(s32LocalCalcDiff);

   u32LocalCalcSum = MATHSRV_u32Add_u32_u32(VlvAct_agInActrTstAddErrPrev,
                                            u32LocalVarAbs);

   VlvAct_agInActrTestAddErrRefInt = MATHSRV_udtMIN(u32LocalCalcSum, 1066666);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidStatErrorMea                           */
/* !Description :  Dans ce bloc sont calculées pour chaque phases stabilisées */
/*                 du profil de consigne envoyé lors du test  actionneur de la*/
/*                 VVT admission, les indices de temps utilisés dans le calcul*/
/*                 de l’erreur statique moyenne.                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st114 VlvAct_stInActrTst;                                           */
/*  input uint16 VlvAct_tiInActrTest1SplSp_C;                                 */
/*  input uint16 VlvAct_tiInActrTestSp;                                       */
/*  input uint16 VlvAct_tiInActrTest3SplSp_C;                                 */
/*  input uint16 VlvAct_tiInActrTest5SplSp_C;                                 */
/*  input uint16 VlvAct_tiInActrTest6SplSp_C;                                 */
/*  input uint16 VlvAct_tiInActrTest8SplSp_C;                                 */
/*  input uint16 VlvAct_tiInActrTest10SplSp_C;                                */
/*  output uint16 VlvAct_tiInActrTestAvgTiStatErr;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidStatErrorMea(void)
{
   uint8  u8LocalVlvAct_stInActrTst;
   sint32 s32LocalCalcDiff;


   VEMS_vidGET(VlvAct_stInActrTst, u8LocalVlvAct_stInActrTst);

   switch (u8LocalVlvAct_stInActrTst)
   {
      case VLV_INACTRTST_PHASE1:
         s32LocalCalcDiff = (sint32)( VlvAct_tiInActrTest1SplSp_C
                                    - VlvAct_tiInActrTestSp);
         break;

      case VLV_INACTRTST_PHASE3:
         s32LocalCalcDiff = (sint32)( VlvAct_tiInActrTest3SplSp_C
                                    - VlvAct_tiInActrTestSp);
         break;

      case VLV_INACTRTST_PHASE5:
      case VLV_INACTRTST_PHASE6:
         s32LocalCalcDiff = (sint32)(  ( VlvAct_tiInActrTest5SplSp_C
                                       + VlvAct_tiInActrTest6SplSp_C)
                                    - VlvAct_tiInActrTestSp);
         break;

      case VLV_INACTRTST_PHASE8:
         s32LocalCalcDiff = (sint32)( VlvAct_tiInActrTest8SplSp_C
                                    - VlvAct_tiInActrTestSp);
         break;

      case VLV_INACTRTST_PHASE10:
         s32LocalCalcDiff = (sint32)( VlvAct_tiInActrTest10SplSp_C
                                    - VlvAct_tiInActrTestSp);
         break;

      default:
         s32LocalCalcDiff = 0;
         break;
   }

   VlvAct_tiInActrTestAvgTiStatErr = (uint16)MATHSRV_udtMAX(s32LocalCalcDiff,
                                                            0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidStErrCritClc                           */
/* !Description :  Dans ce bloc sont calculées les indicateurs d’erreurs      */
/*                 statiques sur les différentes portions stabilisées de  la  */
/*                 consigne envoyée lors du test actionneur de la VVT         */
/*                 admission.                                                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret uint32  MATHSRV_u32Div_u32_u16(argin uint32 u32FirstValue,    */
/*  argin uint16 u16SecondValue);                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VlvAct_bInActrTestSpStatErrEna;                             */
/*  input uint16 VlvAct_tiInActrTestAvgTiStatErr;                             */
/*  input uint32 VlvAct_agInActrTestAddErrRef;                                */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input boolean VLVACTINACTRTEST_SrvbInVVTEnPrev;                           */
/*  input st114 VlvAct_stInActrTst;                                           */
/*  input uint32 VLVACTINACTRTEST_u32CalcPhase1;                              */
/*  input uint16 VlvAct_agInActrTestStaErrThd_C;                              */
/*  input uint32 VLVACTINACTRTEST_u32CalcPhase3;                              */
/*  input uint32 VLVACTINACTRTEST_u32CalcPhase5;                              */
/*  input uint32 VLVACTINACTRTEST_u32CalcPhase8;                              */
/*  input uint32 VLVACTINACTRTEST_u32CalcPhase10;                             */
/*  output uint32 VLVACTINACTRTEST_u32CalcPhase1;                             */
/*  output uint32 VLVACTINACTRTEST_u32CalcPhase3;                             */
/*  output uint32 VLVACTINACTRTEST_u32CalcPhase5;                             */
/*  output uint32 VLVACTINACTRTEST_u32CalcPhase8;                             */
/*  output uint32 VLVACTINACTRTEST_u32CalcPhase10;                            */
/*  output boolean VlvAct_bInActrTestStatErrRef1;                             */
/*  output boolean VlvAct_bInActrTestStatErrMax1;                             */
/*  output boolean VlvAct_bInActrTestStatErrRef2;                             */
/*  output boolean VlvAct_bInActrTestStatErrMax2;                             */
/*  output boolean VlvAct_bInActrTestStatErrRef3;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidStErrCritClc(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   uint8   u8LocalVlvAct_stInActrTst;
   uint32  u32LocalCalcVar1;


   if (VlvAct_bInActrTestSpStatErrEna != 0)
   {
      if (VlvAct_tiInActrTestAvgTiStatErr == 0)
      {
         u32LocalCalcVar1 = 0;
      }
      else
      {
         u32LocalCalcVar1 =
            MATHSRV_u32Div_u32_u16(VlvAct_agInActrTestAddErrRef,
                                   VlvAct_tiInActrTestAvgTiStatErr);
      }
   }
   else
   {
      u32LocalCalcVar1 = 0;
   }

   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);
   if (  (bLocalSrv_bActrTstInVVTEna != 0)
      && (VLVACTINACTRTEST_SrvbInVVTEnPrev == 0))
   {
      VLVACTINACTRTEST_u32CalcPhase1  = 0;
      VLVACTINACTRTEST_u32CalcPhase3  = 0;
      VLVACTINACTRTEST_u32CalcPhase5  = 0;
      VLVACTINACTRTEST_u32CalcPhase8  = 0;
      VLVACTINACTRTEST_u32CalcPhase10 = 0;
   }
   else
   {
      VEMS_vidGET(VlvAct_stInActrTst, u8LocalVlvAct_stInActrTst);
      switch (u8LocalVlvAct_stInActrTst)
      {
         case VLV_INACTRTST_PHASE1:
            VLVACTINACTRTEST_u32CalcPhase1 = u32LocalCalcVar1;
            break;

         case VLV_INACTRTST_PHASE3:
            VLVACTINACTRTEST_u32CalcPhase3 = u32LocalCalcVar1;
            break;

         case VLV_INACTRTST_PHASE5:
         case VLV_INACTRTST_PHASE6:
            VLVACTINACTRTEST_u32CalcPhase5 = u32LocalCalcVar1;
            break;

         case VLV_INACTRTST_PHASE8:
            VLVACTINACTRTEST_u32CalcPhase8 = u32LocalCalcVar1;
            break;

         case VLV_INACTRTST_PHASE10:
            VLVACTINACTRTEST_u32CalcPhase10 = u32LocalCalcVar1;
            break;

         default:
            /* do nothing*/
            break;
      }
   }

   if (VLVACTINACTRTEST_u32CalcPhase1 >= VlvAct_agInActrTestStaErrThd_C)
   {
      VEMS_vidSET(VlvAct_bInActrTestStatErrRef1, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInActrTestStatErrRef1, 0);
   }

   if (VLVACTINACTRTEST_u32CalcPhase3 >= VlvAct_agInActrTestStaErrThd_C)
   {
      VEMS_vidSET(VlvAct_bInActrTestStatErrMax1, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInActrTestStatErrMax1, 0);
   }

   if (VLVACTINACTRTEST_u32CalcPhase5 >= VlvAct_agInActrTestStaErrThd_C)
   {
      VEMS_vidSET(VlvAct_bInActrTestStatErrRef2, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInActrTestStatErrRef2, 0);
   }

   if (VLVACTINACTRTEST_u32CalcPhase8 >= VlvAct_agInActrTestStaErrThd_C)
   {
      VEMS_vidSET(VlvAct_bInActrTestStatErrMax2, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInActrTestStatErrMax2, 0);
   }

   if (VLVACTINACTRTEST_u32CalcPhase10 >= VlvAct_agInActrTestStaErrThd_C)
   {
      VEMS_vidSET(VlvAct_bInActrTestStatErrRef3, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInActrTestStatErrRef3, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidSpeedErrorCo                           */
/* !Description :  Pour les phases stabilisées du profil, on calcule l’erreur */
/*                 statique.                                                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINACTRTEST_vidSpeedErrorMe();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACTRTEST_vidFstSpdErrClc();                      */
/*  extf argret void VLVACTINACTRTEST_vidSpdErrInCalc();                      */
/*  input st114 VlvAct_stInActrTst;                                           */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input uint16 VlvAct_tiInActrTestSpSpdErr;                                 */
/*  input uint16 VlvAct_tiInActrTestPosMesSpdErr;                             */
/*  output uint16 VlvAct_tiInActrTstSpdErr;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidSpeedErrorCo(void)
{
   boolean bLocalSrvbActrTstInVVTEna;
   uint8   u8LocalVlvAct_stInActrTst;
   sint32  s32LocalCalcVar;


   VLVACTINACTRTEST_vidSpeedErrorMe();
   VEMS_vidGET(VlvAct_stInActrTst, u8LocalVlvAct_stInActrTst);

   if (  (u8LocalVlvAct_stInActrTst == VLV_INACTRTST_PHASE2)
      || (u8LocalVlvAct_stInActrTst == VLV_INACTRTST_PHASE4)
      || (u8LocalVlvAct_stInActrTst == VLV_INACTRTST_PHASE7)
      || (u8LocalVlvAct_stInActrTst == VLV_INACTRTST_PHASE9))
   {
      VLVACTINACTRTEST_vidFstSpdErrClc();
   }

   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrvbActrTstInVVTEna);

   if (bLocalSrvbActrTstInVVTEna != 0)
   {
      s32LocalCalcVar = (sint32)( VlvAct_tiInActrTestSpSpdErr
                                - VlvAct_tiInActrTestPosMesSpdErr);
      VlvAct_tiInActrTstSpdErr = (uint16)MATHSRV_udtABS(s32LocalCalcVar);
   }
   else
   {
      VlvAct_tiInActrTstSpdErr = 0;
   }

   VLVACTINACTRTEST_vidSpdErrInCalc();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidFstSpdErrClc                           */
/* !Description :  calcule du retard.                                         */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACTRTEST_vidSetpointCrit();                      */
/*  extf argret void VLVACTINACTRTEST_vidMeaCriTiComp();                      */
/*  input uint16 Vxx_vvtc_in_angl_sp;                                         */
/*  input sint8 VlvAct_InActrTestSpdErrorCompCoe;                             */
/*  input uint8 VlvAct_InActrTestSpdErrorTiThd;                               */
/*  input uint16 VlvAct_agInActrTestMaxPosSp_C;                               */
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  input boolean VLVACTINACTRTEST_bCompCalc1Prev;                            */
/*  input boolean VLVACTINACTRTEST_bCompCalc2Prev;                            */
/*  output boolean VLVACTINACTRTEST_bCompCalc1Prev;                           */
/*  output boolean VLVACTINACTRTEST_bCompCalc2Prev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidFstSpdErrClc(void)
{
   uint16 u16LocalVxxvvtcinanglsp;
   uint16 u16LocalVlvAct_agCmInPosnEstim;
   sint32 s32LocalCalcVar1;
   sint32 s32LocalCalcVar2;
   sint32 s32LocalCalcVar3;


   VEMS_vidGET(Vxx_vvtc_in_angl_sp, u16LocalVxxvvtcinanglsp);

   s32LocalCalcVar1 = (sint32)( VlvAct_InActrTestSpdErrorCompCoe
                              * u16LocalVxxvvtcinanglsp);

   if (VlvAct_InActrTestSpdErrorCompCoe < 0)
   {
      s32LocalCalcVar2 = (sint32)( ( ( VlvAct_InActrTestSpdErrorTiThd
                                     * VlvAct_agInActrTestMaxPosSp_C
                                     * VlvAct_InActrTestSpdErrorCompCoe)
                                   - 64)
                                 / 128);
   }
   else
   {
      s32LocalCalcVar2 = (sint32)( ( ( VlvAct_InActrTestSpdErrorTiThd
                                     * VlvAct_agInActrTestMaxPosSp_C
                                     * VlvAct_InActrTestSpdErrorCompCoe)
                                   + 64)
                                 / 128);
   }
   VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);

   s32LocalCalcVar3 = (sint32)( VlvAct_InActrTestSpdErrorCompCoe
                              * u16LocalVlvAct_agCmInPosnEstim);

   if (s32LocalCalcVar1 >= s32LocalCalcVar2)
   {
      if (VLVACTINACTRTEST_bCompCalc1Prev == 0)
      {
         VLVACTINACTRTEST_vidSetpointCrit();
      }
      VLVACTINACTRTEST_bCompCalc1Prev = 1;
   }
   else
   {
      VLVACTINACTRTEST_bCompCalc1Prev = 0;
   }

   if (s32LocalCalcVar3 >= s32LocalCalcVar2)
   {
      if(VLVACTINACTRTEST_bCompCalc2Prev == 0)
      {
         VLVACTINACTRTEST_vidMeaCriTiComp();
      }
      VLVACTINACTRTEST_bCompCalc2Prev = 1;
   }
   else
   {
      VLVACTINACTRTEST_bCompCalc2Prev = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidSetpointCrit                           */
/* !Description :  on calcule du temps nécessaire pour atteindre la valeur    */
/*                 finale .(Pour la consigne  )                               */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 VlvAct_tiInActrTestSp;                                       */
/*  output uint16 VlvAct_tiInActrTestSpSpdErr;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidSetpointCrit(void)
{
   VlvAct_tiInActrTestSpSpdErr = VlvAct_tiInActrTestSp;
}
/*------------------------------- end of file --------------------------------*/
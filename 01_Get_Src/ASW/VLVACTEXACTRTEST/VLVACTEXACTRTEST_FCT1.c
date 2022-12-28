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
/* !File            : VLVACTEXACTRTEST_FCT1.C                                 */
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
/*   1 / VLVACTEXACTRTEST_vidInitializati                                     */
/*   2 / VLVACTEXACTRTEST_vidCalcSdlFast                                      */
/*   3 / VLVACTEXACTRTEST_vidCriteriaCalc                                     */
/*   4 / VLVACTEXACTRTEST_vidStatErrorCom                                     */
/*   5 / VLVACTEXACTRTEST_vidAgregatedErr                                     */
/*   6 / VLVACTEXACTRTEST_vidStatErrorMea                                     */
/*   7 / VLVACTEXACTRTEST_vidStErrCritClc                                     */
/*   8 / VLVACTEXACTRTEST_vidSpeedErrorCo                                     */
/*   9 / VLVACTEXACTRTEST_vidFstSpdErrClc                                     */
/*   10 / VLVACTEXACTRTEST_vidSetpointCrit                                    */
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
/* !Function    :  VLVACTEXACTRTEST_vidInitializati                           */
/* !Description :  initialisation des variables de sorties et de l'automate.  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean VlvAct_bExActrTestStatErrRef1;                             */
/*  output boolean VlvAct_bExActrTestStatErrRef2;                             */
/*  output boolean VlvAct_bExActrTestStatErrMax1;                             */
/*  output boolean VlvAct_bExActrTestStatErrMax2;                             */
/*  output boolean VlvAct_bExActrTestStatErrRef3;                             */
/*  output boolean VlvAct_bExActrTest2RampSpdErrIdc;                          */
/*  output boolean VlvAct_bExActrTest3RampSpdErrIdc;                          */
/*  output boolean VlvAct_bExActrTest4RampSpdErrIdc;                          */
/*  output boolean VlvAct_bExActrTest1RampSpdErrIdc;                          */
/*  output boolean Srv_bActrTstExVVTEna;                                      */
/*  output uint32 VlvAct_agExActrTstAddErrPrev;                               */
/*  output uint32 VLVACTEXACTRTEST_u32CalcPhase1;                             */
/*  output uint32 VLVACTEXACTRTEST_u32CalcPhase3;                             */
/*  output uint32 VLVACTEXACTRTEST_u32CalcPhase5;                             */
/*  output uint32 VLVACTEXACTRTEST_u32CalcPhase8;                             */
/*  output uint32 VLVACTEXACTRTEST_u32CalcPhase10;                            */
/*  output boolean VLVACTEXACTRTEST_bCompCalc2Prev;                           */
/*  output boolean VLVACTEXACTRTEST_bCompCalc1Prev;                           */
/*  output uint16 VLVACTEXACTRTEST_u16CalcPhase2;                             */
/*  output uint16 VLVACTEXACTRTEST_u16CalcPhase4;                             */
/*  output uint16 VLVACTEXACTRTEST_u16CalcPhase7;                             */
/*  output uint16 VLVACTEXACTRTEST_u16CalcPhase9;                             */
/*  output uint8 VLVACTEXACTRTEST_u8CdeTstActPrev;                            */
/*  output boolean VLVACTEXACTRTEST_SrvbExVVTEnPrev;                          */
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output st118 VlvAct_stExActrTstLstSt;                                     */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*  output boolean VlvAct_bExActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidInitializati(void)
{
   VEMS_vidSET(VlvAct_bExActrTestStatErrRef1, 0);
   VEMS_vidSET(VlvAct_bExActrTestStatErrRef2, 0);
   VEMS_vidSET(VlvAct_bExActrTestStatErrMax1, 0);
   VEMS_vidSET(VlvAct_bExActrTestStatErrMax2, 0);
   VEMS_vidSET(VlvAct_bExActrTestStatErrRef3, 0);
   VEMS_vidSET(VlvAct_bExActrTest2RampSpdErrIdc, 0);
   VEMS_vidSET(VlvAct_bExActrTest3RampSpdErrIdc, 0);
   VEMS_vidSET(VlvAct_bExActrTest4RampSpdErrIdc, 0);
   VEMS_vidSET(VlvAct_bExActrTest1RampSpdErrIdc, 0);
   VEMS_vidSET(Srv_bActrTstExVVTEna, 0);
   VlvAct_agExActrTstAddErrPrev  = 0;
   VLVACTEXACTRTEST_u32CalcPhase1 = 0;
   VLVACTEXACTRTEST_u32CalcPhase3 = 0;
   VLVACTEXACTRTEST_u32CalcPhase5 = 0;
   VLVACTEXACTRTEST_u32CalcPhase8 = 0;
   VLVACTEXACTRTEST_u32CalcPhase10 = 0;
   VLVACTEXACTRTEST_bCompCalc2Prev = 0;
   VLVACTEXACTRTEST_bCompCalc1Prev = 0;
   VLVACTEXACTRTEST_u16CalcPhase2 = 0;
   VLVACTEXACTRTEST_u16CalcPhase4 = 0;
   VLVACTEXACTRTEST_u16CalcPhase7 = 0;
   VLVACTEXACTRTEST_u16CalcPhase9 = 0;
   VLVACTEXACTRTEST_u8CdeTstActPrev = 0;
   VLVACTEXACTRTEST_SrvbExVVTEnPrev = 0;
   /*stateflow initialization*/
   VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_IDLE);
   VEMS_vidSET(VlvAct_stExActrTstLstSt, VLVACT_EXACTRTST_IDLE);
   VEMS_vidSET(VlvAct_agExActrTestPosSp, 0);
   VEMS_vidSET(VlvAct_bExActrTestSpEndIdc, 0);
   VEMS_vidSET(VlvAct_bExActrTestNotRun, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidCalcSdlFast                            */
/* !Description :  calcule de l'evenement SdlFast.                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACTRTEST_vidSetpointComp();                      */
/*  extf argret void VLVACTEXACTRTEST_vidCriteriaCalc();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input uint8 Code_test_action;                                             */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input boolean VLVACTEXACTRTEST_SrvbExVVTEnPrev;                           */
/*  output boolean VLVACTEXACTRTEST_SrvbExVVTEnPrev;                          */
/*  output boolean Srv_bActrTstExVVTEna;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidCalcSdlFast(void)
{
   boolean bLocalSrv_bActrTstEna;
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);

   if (VlvAct_bAcvVlvActExStr_C != 0)
   {
      VLVACTEXACTRTEST_vidSetpointComp();
      VLVACTEXACTRTEST_vidCriteriaCalc();
   }

   VEMS_vidGET(Srv_bActrTstExVVTEna, VLVACTEXACTRTEST_SrvbExVVTEnPrev);

   if (  (bLocalSrv_bActrTstEna != 0)
      && (u8LocalCode_test_action == CODE_TEST_VVT_ECH))
   {
      VEMS_vidSET(Srv_bActrTstExVVTEna, 1);
   }
   else
   {
      VEMS_vidSET(Srv_bActrTstExVVTEna, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidCriteriaCalc                           */
/* !Description :  Ce bloc calcule deux types de critère :Pour les rampes ou  */
/*                 échelons on calcule le retard ( erreur de vitesse ) ET Pour*/
/*                 les phases stabilisées du profil, on calcule l’erreur      */
/*                 statique.                                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Z.HOSNI                                                    */
/* !Trace_To    :  VEMS_R_09_05825_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXACTRTEST_vidStatErrorCom();                      */
/*  extf argret void VLVACTEXACTRTEST_vidSpeedErrorCo();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidCriteriaCalc(void)
{
   VLVACTEXACTRTEST_vidStatErrorCom();
   VLVACTEXACTRTEST_vidSpeedErrorCo();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidStatErrorCom                           */
/* !Description :  Dans ce bloc sont calculées les erreurs statiques.         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACTRTEST_vidAgregatedErr();                      */
/*  extf argret void VLVACTEXACTRTEST_vidStatErrorMea();                      */
/*  extf argret void VLVACTEXACTRTEST_vidStErrCritClc();                      */
/*  input st115 VlvAct_stExActrTst;                                           */
/*  input uint32 VlvAct_agExActrTestAddErrRefInt;                             */
/*  input uint32 VlvAct_agExActrTestAddErrRef;                                */
/*  output boolean VlvAct_bExActrTestSpStatErrEna;                            */
/*  output uint32 VlvAct_agExActrTestAddErrRef;                               */
/*  output uint32 VlvAct_agExActrTstAddErrPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidStatErrorCom(void)
{
   uint8 u8LocalVlvAct_stExActrTst;


   VEMS_vidGET(VlvAct_stExActrTst, u8LocalVlvAct_stExActrTst);

   if (  (u8LocalVlvAct_stExActrTst == VLV_EXACTRTST_PHASE1)
      || (u8LocalVlvAct_stExActrTst == VLV_EXACTRTST_PHASE3)
      || (u8LocalVlvAct_stExActrTst == VLV_EXACTRTST_PHASE5)
      || (u8LocalVlvAct_stExActrTst == VLV_EXACTRTST_PHASE6)
      || (u8LocalVlvAct_stExActrTst == VLV_EXACTRTST_PHASE8)
      || (u8LocalVlvAct_stExActrTst == VLV_EXACTRTST_PHASE10))
   {
      VlvAct_bExActrTestSpStatErrEna = 1;
      VLVACTEXACTRTEST_vidAgregatedErr();
      VlvAct_agExActrTestAddErrRef =
         MATHSRV_udtMIN(VlvAct_agExActrTestAddErrRefInt, 1066666);
   }
   else
   {
      VlvAct_bExActrTestSpStatErrEna = 0;
      VlvAct_agExActrTestAddErrRef = 0;
   }

   VLVACTEXACTRTEST_vidStatErrorMea();
   VLVACTEXACTRTEST_vidStErrCritClc();
   VlvAct_agExActrTstAddErrPrev = VlvAct_agExActrTestAddErrRef;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidAgregatedErr                           */
/* !Description :  Dans ce bloc est calculée l’erreur statique cumulée pour   */
/*                 chaque phase stabilisée de la consigne envoyée lors  du    */
/*                 test actionneur de la VVT échappement                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Vxx_vvtc_ex_angl_sp;                                         */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input uint32 VlvAct_agExActrTstAddErrPrev;                                */
/*  output uint32 VlvAct_agExActrTestAddErrRefInt;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidAgregatedErr(void)
{
   uint16 u16LocalVxx_vvtc_ex_angl_sp;
   uint16 u16LocalVlvAct_agCmExPosnEstim;
   uint32 u32LocalCalcSum;
   uint32 u32LocalVarAbs;
   sint32 s32LocalCalcDiff;


   VEMS_vidGET(Vxx_vvtc_ex_angl_sp, u16LocalVxx_vvtc_ex_angl_sp);
   VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);

   s32LocalCalcDiff = (sint32)( u16LocalVxx_vvtc_ex_angl_sp
                              - u16LocalVlvAct_agCmExPosnEstim);

   u32LocalVarAbs = (uint32)MATHSRV_udtABS(s32LocalCalcDiff);

   u32LocalCalcSum = MATHSRV_u32Add_u32_u32(VlvAct_agExActrTstAddErrPrev,
                                            u32LocalVarAbs);

   VlvAct_agExActrTestAddErrRefInt = MATHSRV_udtMIN(u32LocalCalcSum, 1066666);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidStatErrorMea                           */
/* !Description :  Dans ce bloc sont calculées pour chaque phases stabilisées */
/*                 du profil de consigne envoyé lors du test  actionneur de la*/
/*                 VVT échappement, les indices de temps utilisés dans le     */
/*                 calcul de l’erreur statique moyenne.                       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st115 VlvAct_stExActrTst;                                           */
/*  input uint16 VlvAct_tiExActrTest1SplSp_C;                                 */
/*  input uint16 VlvAct_tiExActrTestSp;                                       */
/*  input uint16 VlvAct_tiExActrTest3SplSp_C;                                 */
/*  input uint16 VlvAct_tiExActrTest5SplSp_C;                                 */
/*  input uint16 VlvAct_tiExActrTest6SplSp_C;                                 */
/*  input uint16 VlvAct_tiExActrTest8SplSp_C;                                 */
/*  input uint16 VlvAct_tiExActrTest10SplSp_C;                                */
/*  output uint16 VlvAct_tiExActrTestAvgTiStatErr;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidStatErrorMea(void)
{
   uint8  u8LocalVlvAct_stExActrTst;
   sint32 s32LocalCalcDiff;


   VEMS_vidGET(VlvAct_stExActrTst, u8LocalVlvAct_stExActrTst);

   switch (u8LocalVlvAct_stExActrTst)
   {
      case VLV_EXACTRTST_PHASE1:
         s32LocalCalcDiff = (sint32)( VlvAct_tiExActrTest1SplSp_C
                                    - VlvAct_tiExActrTestSp);
         break;

      case VLV_EXACTRTST_PHASE3:
         s32LocalCalcDiff = (sint32)( VlvAct_tiExActrTest3SplSp_C
                                    - VlvAct_tiExActrTestSp);
         break;

      case VLV_EXACTRTST_PHASE5:
      case VLV_EXACTRTST_PHASE6:
         s32LocalCalcDiff = (sint32)( ( VlvAct_tiExActrTest5SplSp_C
                                      + VlvAct_tiExActrTest6SplSp_C)
                                    - VlvAct_tiExActrTestSp);
         break;

      case VLV_EXACTRTST_PHASE8:
         s32LocalCalcDiff = (sint32)( VlvAct_tiExActrTest8SplSp_C
                                    - VlvAct_tiExActrTestSp);
         break;

      case VLV_EXACTRTST_PHASE10:
         s32LocalCalcDiff = (sint32)( VlvAct_tiExActrTest10SplSp_C
                                    - VlvAct_tiExActrTestSp);
         break;

      default:
         s32LocalCalcDiff = 0;
         break;
   }

   VlvAct_tiExActrTestAvgTiStatErr = (uint16)MATHSRV_udtMAX(s32LocalCalcDiff,
                                                            0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidStErrCritClc                           */
/* !Description :  Dans ce bloc sont calculées les indicateurs d’erreurs      */
/*                 statiques sur les différentes portions stabilisées de  la  */
/*                 consigne envoyée lors du test actionneur de la VVT         */
/*                 échappement.                                               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VlvAct_bExActrTestSpStatErrEna;                             */
/*  input uint16 VlvAct_tiExActrTestAvgTiStatErr;                             */
/*  input uint32 VlvAct_agExActrTestAddErrRef;                                */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input boolean VLVACTEXACTRTEST_SrvbExVVTEnPrev;                           */
/*  input st115 VlvAct_stExActrTst;                                           */
/*  input uint32 VLVACTEXACTRTEST_u32CalcPhase1;                              */
/*  input uint16 VlvAct_agExActrTestStaErrThd_C;                              */
/*  input uint32 VLVACTEXACTRTEST_u32CalcPhase3;                              */
/*  input uint32 VLVACTEXACTRTEST_u32CalcPhase5;                              */
/*  input uint32 VLVACTEXACTRTEST_u32CalcPhase8;                              */
/*  input uint32 VLVACTEXACTRTEST_u32CalcPhase10;                             */
/*  output uint32 VLVACTEXACTRTEST_u32CalcPhase1;                             */
/*  output uint32 VLVACTEXACTRTEST_u32CalcPhase3;                             */
/*  output uint32 VLVACTEXACTRTEST_u32CalcPhase5;                             */
/*  output uint32 VLVACTEXACTRTEST_u32CalcPhase8;                             */
/*  output uint32 VLVACTEXACTRTEST_u32CalcPhase10;                            */
/*  output boolean VlvAct_bExActrTestStatErrRef1;                             */
/*  output boolean VlvAct_bExActrTestStatErrMax1;                             */
/*  output boolean VlvAct_bExActrTestStatErrRef2;                             */
/*  output boolean VlvAct_bExActrTestStatErrMax2;                             */
/*  output boolean VlvAct_bExActrTestStatErrRef3;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidStErrCritClc(void)
{
   boolean bLocalSrvbActrTstExVVTEna;
   uint8   u8LocalVlvAct_stExActrTst;
   uint32  u32LocalCalcVar1;


   if (VlvAct_bExActrTestSpStatErrEna != 0)
   {
      if (VlvAct_tiExActrTestAvgTiStatErr == 0)
      {
         u32LocalCalcVar1 = 0;
      }
      else
      {
         u32LocalCalcVar1 =
            MATHSRV_u32Div_u32_u16(VlvAct_agExActrTestAddErrRef,
                                   VlvAct_tiExActrTestAvgTiStatErr);
      }
   }
   else
   {
      u32LocalCalcVar1 = 0;
   }

   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrvbActrTstExVVTEna);
   if (  (bLocalSrvbActrTstExVVTEna != 0)
      && (VLVACTEXACTRTEST_SrvbExVVTEnPrev == 0))
   {
      VLVACTEXACTRTEST_u32CalcPhase1  = 0;
      VLVACTEXACTRTEST_u32CalcPhase3  = 0;
      VLVACTEXACTRTEST_u32CalcPhase5  = 0;
      VLVACTEXACTRTEST_u32CalcPhase8  = 0;
      VLVACTEXACTRTEST_u32CalcPhase10 = 0;
   }
   else
   {
      VEMS_vidGET(VlvAct_stExActrTst, u8LocalVlvAct_stExActrTst);
      switch (u8LocalVlvAct_stExActrTst)
      {
         case VLV_EXACTRTST_PHASE1:
            VLVACTEXACTRTEST_u32CalcPhase1 = u32LocalCalcVar1;
            break;

         case VLV_EXACTRTST_PHASE3:
            VLVACTEXACTRTEST_u32CalcPhase3 = u32LocalCalcVar1;
            break;

         case VLV_EXACTRTST_PHASE5:
         case VLV_EXACTRTST_PHASE6:
            VLVACTEXACTRTEST_u32CalcPhase5 = u32LocalCalcVar1;
            break;

         case VLV_EXACTRTST_PHASE8:
            VLVACTEXACTRTEST_u32CalcPhase8 = u32LocalCalcVar1;
            break;

         case VLV_EXACTRTST_PHASE10:
            VLVACTEXACTRTEST_u32CalcPhase10 = u32LocalCalcVar1;
            break;

         default:
            /* do nothing*/
            break;
      }
   }

   if (VLVACTEXACTRTEST_u32CalcPhase1 >= VlvAct_agExActrTestStaErrThd_C)
   {
      VEMS_vidSET(VlvAct_bExActrTestStatErrRef1, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExActrTestStatErrRef1, 0);
   }

   if (VLVACTEXACTRTEST_u32CalcPhase3 >= VlvAct_agExActrTestStaErrThd_C)
   {
      VEMS_vidSET(VlvAct_bExActrTestStatErrMax1, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExActrTestStatErrMax1, 0);
   }

   if (VLVACTEXACTRTEST_u32CalcPhase5 >= VlvAct_agExActrTestStaErrThd_C)
   {
      VEMS_vidSET(VlvAct_bExActrTestStatErrRef2, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExActrTestStatErrRef2, 0);
   }

   if (VLVACTEXACTRTEST_u32CalcPhase8 >= VlvAct_agExActrTestStaErrThd_C)
   {
      VEMS_vidSET(VlvAct_bExActrTestStatErrMax2, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExActrTestStatErrMax2, 0);
   }

   if (VLVACTEXACTRTEST_u32CalcPhase10 >= VlvAct_agExActrTestStaErrThd_C)
   {
      VEMS_vidSET(VlvAct_bExActrTestStatErrRef3, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExActrTestStatErrRef3, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidSpeedErrorCo                           */
/* !Description :  Pour les phases stabilisées du profil, on calcule l’erreur */
/*                 statique.                                                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXACTRTEST_vidSpeedErrorMe();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACTRTEST_vidFstSpdErrClc();                      */
/*  extf argret void VLVACTEXACTRTEST_vidSpdErrExCalc();                      */
/*  input st115 VlvAct_stExActrTst;                                           */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input uint16 VlvAct_tiExActrTestSpSpdErr;                                 */
/*  input uint16 VlvAct_tiExActrTestPosMesSpdErr;                             */
/*  output uint16 VlvAct_tiExActrTstSpdErr;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidSpeedErrorCo(void)
{
   boolean bLocalSrvbActrTstExVVTEna;
   uint8   u8LocalVlvAct_stExActrTst;
   sint32  s32LocalCalcVar;


   VLVACTEXACTRTEST_vidSpeedErrorMe();
   VEMS_vidGET(VlvAct_stExActrTst, u8LocalVlvAct_stExActrTst);

   if (  (u8LocalVlvAct_stExActrTst == VLV_EXACTRTST_PHASE2)
      || (u8LocalVlvAct_stExActrTst == VLV_EXACTRTST_PHASE4)
      || (u8LocalVlvAct_stExActrTst == VLV_EXACTRTST_PHASE7)
      || (u8LocalVlvAct_stExActrTst == VLV_EXACTRTST_PHASE9))
   {
      VLVACTEXACTRTEST_vidFstSpdErrClc();
   }

   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrvbActrTstExVVTEna);

   if (bLocalSrvbActrTstExVVTEna != 0)
   {
      s32LocalCalcVar = (sint32)( VlvAct_tiExActrTestSpSpdErr
                                - VlvAct_tiExActrTestPosMesSpdErr);
      VlvAct_tiExActrTstSpdErr = (uint16)MATHSRV_udtABS(s32LocalCalcVar);
   }
   else
   {
      VlvAct_tiExActrTstSpdErr = 0;
   }

   VLVACTEXACTRTEST_vidSpdErrExCalc();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidFstSpdErrClc                           */
/* !Description :  calcule du retard.                                         */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACTRTEST_vidSetpointCrit();                      */
/*  extf argret void VLVACTEXACTRTEST_vidMeaCriTiComp();                      */
/*  input uint16 Vxx_vvtc_ex_angl_sp;                                         */
/*  input sint8 VlvAct_ExActrTestSpdErrorCompCoe;                             */
/*  input uint8 VlvAct_ExActrTestSpdErrorTiThd;                               */
/*  input uint16 VlvAct_agExActrTestMaxPosSp_C;                               */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input boolean VLVACTEXACTRTEST_bCompCalc1Prev;                            */
/*  input boolean VLVACTEXACTRTEST_bCompCalc2Prev;                            */
/*  output boolean VLVACTEXACTRTEST_bCompCalc1Prev;                           */
/*  output boolean VLVACTEXACTRTEST_bCompCalc2Prev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidFstSpdErrClc(void)
{
   uint16 u16LocalVlvAct_agCmExPosnEstim;
   uint16 u16LocalVxxvvtcexanglsp;
   sint32 s32LocalCalcVar1;
   sint32 s32LocalCalcVar2;
   sint32 s32LocalCalcVar3;


   VEMS_vidGET(Vxx_vvtc_ex_angl_sp, u16LocalVxxvvtcexanglsp);

   s32LocalCalcVar1 = (sint32)( VlvAct_ExActrTestSpdErrorCompCoe
                              * u16LocalVxxvvtcexanglsp);

   if (VlvAct_ExActrTestSpdErrorCompCoe < 0)
   {
      s32LocalCalcVar2 = (sint32)( ( ( VlvAct_ExActrTestSpdErrorTiThd
                                     * VlvAct_agExActrTestMaxPosSp_C
                                     * VlvAct_ExActrTestSpdErrorCompCoe)
                                   - 64)
                                 / 128);
   }
   else
   {
      s32LocalCalcVar2 = (sint32)( ( ( VlvAct_ExActrTestSpdErrorTiThd
                                     * VlvAct_agExActrTestMaxPosSp_C
                                     * VlvAct_ExActrTestSpdErrorCompCoe)
                                   + 64)
                                 / 128);
   }
   VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);

   s32LocalCalcVar3 = (sint32)( VlvAct_ExActrTestSpdErrorCompCoe
                              * u16LocalVlvAct_agCmExPosnEstim);

   if (s32LocalCalcVar1 >= s32LocalCalcVar2)
   {
      if (VLVACTEXACTRTEST_bCompCalc1Prev == 0)
      {
         VLVACTEXACTRTEST_vidSetpointCrit();
      }
      VLVACTEXACTRTEST_bCompCalc1Prev = 1;
   }
   else
   {
      VLVACTEXACTRTEST_bCompCalc1Prev = 0;
   }

   if (s32LocalCalcVar3 >= s32LocalCalcVar2)
   {
      if (VLVACTEXACTRTEST_bCompCalc2Prev == 0)
      {
         VLVACTEXACTRTEST_vidMeaCriTiComp();
      }
      VLVACTEXACTRTEST_bCompCalc2Prev = 1;
   }
   else
   {
      VLVACTEXACTRTEST_bCompCalc2Prev = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidSetpointCrit                           */
/* !Description :  on calcule du temps nécessaire pour atteindre la valeur    */
/*                 finale .(Pour la consigne  )                               */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 VlvAct_tiExActrTestSp;                                       */
/*  output uint16 VlvAct_tiExActrTestSpSpdErr;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidSetpointCrit(void)
{
   VlvAct_tiExActrTestSpSpdErr = VlvAct_tiExActrTestSp;
}
/*------------------------------- end of file --------------------------------*/
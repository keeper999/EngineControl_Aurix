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
/* !File            : VLVACTINACTRTEST_FCT3.C                                 */
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
/*   1 / VLVACTINACTRTEST_vidPhase6Trans                                      */
/*   2 / VLVACTINACTRTEST_vidPhase7Trans                                      */
/*   3 / VLVACTINACTRTEST_vidPhase8Trans                                      */
/*   4 / VLVACTINACTRTEST_vidPhase9Trans                                      */
/*   5 / VLVACTINACTRTEST_vidPhase10Trans                                     */
/*   6 / VLVACTINACTRTEST_vidEndStTrans                                       */
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
/* !Function    :  VLVACTINACTRTEST_vidPhase6Trans                            */
/* !Description :  calcule de l'etat INVLVACT_ACTRTST_PHASE6                  */
/* !Number      :  FCT3.1                                                     */
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
/*  input uint16 VlvAct_tiInActrTest7SplSp_C;                                 */
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
void VLVACTINACTRTEST_vidPhase6Trans(void)
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

      if (VlvAct_tiInActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_PHASE7);
         VlvAct_tiInActrTestSp = VlvAct_tiInActrTest7SplSp_C;
         u16LocalagInActrTestMinPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agInActrTestMinPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalagInActrTestMinPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidPhase7Trans                            */
/* !Description :  calcule de l'etat INVLVACT_ACTRTST_PHASE7                  */
/* !Number      :  FCT3.2                                                     */
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
/*  input uint16 VlvAct_tiInActrTest7SplSp_C;                                 */
/*  input uint16 VlvAct_tiInActrTest8SplSp_C;                                 */
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*  output boolean VlvAct_bInActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiInActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidPhase7Trans(void)
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
         u32LocalVar = (uint32)( ( VlvAct_agInActrTestMaxPosSp_C
                                 - VlvAct_agInActrTestMinPosSp_C)
                               * VlvAct_tiInActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiInActrTest7SplSp_C);

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
                                              VlvAct_tiInActrTest7SplSp_C);
         u32LocalVar = (VlvAct_agInActrTestMaxPosSp_C + u32LocalVar);
      }

      u16LocalInActrTestPosSp = (uint16) MATHSRV_udtMIN(u32LocalVar, 1066);
      VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalInActrTestPosSp);
      if (VlvAct_tiInActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_PHASE8);
         VlvAct_tiInActrTestSp = VlvAct_tiInActrTest8SplSp_C;
         u16LocalagInActrTestMaxPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agInActrTestMaxPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalagInActrTestMaxPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidPhase8Trans                            */
/* !Description :  calcule de l'etat INVLVACT_ACTRTST_PHASE8                  */
/* !Number      :  FCT3.3                                                     */
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
/*  input uint16 VlvAct_tiInActrTest9SplSp_C;                                 */
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
void VLVACTINACTRTEST_vidPhase8Trans(void)
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
      VlvAct_tiInActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar, 0);

      if (VlvAct_tiInActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_PHASE9);
         VlvAct_tiInActrTestSp = VlvAct_tiInActrTest9SplSp_C;
         u16LocalagInActrTestMaxPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agInActrTestMaxPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalagInActrTestMaxPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidPhase9Trans                            */
/* !Description :  calcule de l'etat INVLVACT_ACTRTST_PHASE9                  */
/* !Number      :  FCT3.4                                                     */
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
/*  input uint16 VlvAct_tiInActrTest9SplSp_C;                                 */
/*  input uint16 VlvAct_tiInActrTest10SplSp_C;                                */
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*  output boolean VlvAct_bInActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiInActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidPhase9Trans(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagInActrTestMinPos;
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
         u32LocalVar = (uint32)( ( VlvAct_agInActrTestMinPosSp_C
                                 - VlvAct_agInActrTestMaxPosSp_C)
                               * VlvAct_tiInActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiInActrTest9SplSp_C);

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
         u32LocalVar = (uint32)( ( VlvAct_agInActrTestMaxPosSp_C
                                 - VlvAct_agInActrTestMinPosSp_C)
                               * VlvAct_tiInActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiInActrTest9SplSp_C);
         u32LocalVar = (VlvAct_agInActrTestMinPosSp_C + u32LocalVar);
      }

      u16LocalagInActrTestMinPos = (uint16) MATHSRV_udtMIN(u32LocalVar, 1066);

      if (VlvAct_tiInActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_PHASE10);
         VlvAct_tiInActrTestSp = VlvAct_tiInActrTest10SplSp_C;
         u16LocalagInActrTestMinPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agInActrTestMinPosSp_C, 1066);
      }
      VEMS_vidSET(VlvAct_agInActrTestPosSp, u16LocalagInActrTestMinPos);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidPhase10Trans                           */
/* !Description :  calcule de l'etat INVLVACT_ACTRTST_PHASE10                 */
/* !Number      :  FCT3.5                                                     */
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
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*  output boolean VlvAct_bInActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiInActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidPhase10Trans(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;
   uint8   u8LocalCodeTestAction;
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
         VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_END);
         VEMS_vidSET(VlvAct_agInActrTestPosSp, 0);
         VEMS_vidSET(VlvAct_bInActrTestSpEndIdc, 1);
         VEMS_vidSET(VlvAct_bInActrTestNotRun, 1);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACTRTEST_vidEndStTrans                             */
/* !Description :  calcule de l'etat  INVLVACT_ACTRTST_END                    */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  output st114 VlvAct_stInActrTst;                                          */
/*  output uint16 VlvAct_agInActrTestPosSp;                                   */
/*  output boolean VlvAct_bInActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bInActrTestNotRun;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACTRTEST_vidEndStTrans(void)
{
   boolean bLocalSrv_bActrTstInVVTEna;


   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);

   if (bLocalSrv_bActrTstInVVTEna == 0)
   {
      VEMS_vidSET(VlvAct_stInActrTst, VLV_INACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agInActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bInActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bInActrTestNotRun, 1);
   }
}
/*------------------------------- end of file --------------------------------*/
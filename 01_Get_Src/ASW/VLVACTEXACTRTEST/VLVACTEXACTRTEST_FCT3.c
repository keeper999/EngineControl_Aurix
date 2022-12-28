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
/* !File            : VLVACTEXACTRTEST_FCT3.C                                 */
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
/*   1 / VLVACTEXACTRTEST_vidPhase6Trans                                      */
/*   2 / VLVACTEXACTRTEST_vidPhase7Trans                                      */
/*   3 / VLVACTEXACTRTEST_vidPhase8Trans                                      */
/*   4 / VLVACTEXACTRTEST_vidPhase9Trans                                      */
/*   5 / VLVACTEXACTRTEST_vidPhase10Trans                                     */
/*   6 / VLVACTEXACTRTEST_vidEndStTrans                                       */
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
/* !Function    :  VLVACTEXACTRTEST_vidPhase6Trans                            */
/* !Description :  calcule de l'etat EXVLVACT_ACTRTST_PHASE6                  */
/* !Number      :  FCT3.1                                                     */
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
/*  input uint16 VlvAct_tiExActrTest7SplSp_C;                                 */
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
void VLVACTEXACTRTEST_vidPhase6Trans(void)
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
         VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_PHASE7);
         VlvAct_tiExActrTestSp = VlvAct_tiExActrTest7SplSp_C;
         u16LocalagExActrTestMinPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agExActrTestMinPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalagExActrTestMinPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidPhase7Trans                            */
/* !Description :  calcule de l'etat EXVLVACT_ACTRTST_PHASE7                  */
/* !Number      :  FCT3.2                                                     */
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
/*  input uint16 VlvAct_tiExActrTest7SplSp_C;                                 */
/*  input uint16 VlvAct_tiExActrTest8SplSp_C;                                 */
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*  output boolean VlvAct_bExActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiExActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidPhase7Trans(void)
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
      VlvAct_tiExActrTestSp = (uint16)MATHSRV_udtMAX(s32LocalVar,0);
      if (VlvAct_agExActrTestMaxPosSp_C >= VlvAct_agExActrTestMinPosSp_C)
      {
         u32LocalVar = (uint32)( ( VlvAct_agExActrTestMaxPosSp_C
                                 - VlvAct_agExActrTestMinPosSp_C)
                               * VlvAct_tiExActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiExActrTest7SplSp_C);

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
         u32LocalVar = (uint32)( ( VlvAct_agExActrTestMinPosSp_C
                                 - VlvAct_agExActrTestMaxPosSp_C)
                               * VlvAct_tiExActrTestSp);
         u32LocalVar = MATHSRV_u32Div_u32_u16(u32LocalVar,
                                              VlvAct_tiExActrTest7SplSp_C);
         u32LocalVar = (VlvAct_agExActrTestMaxPosSp_C + u32LocalVar);
      }

      u16LocalExActrTestPosSp = (uint16) MATHSRV_udtMIN(u32LocalVar, 1066);
      VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalExActrTestPosSp);
      if (VlvAct_tiExActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_PHASE8);
         VlvAct_tiExActrTestSp = VlvAct_tiExActrTest8SplSp_C;
         u16LocalagExActrTestMaxPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agExActrTestMaxPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalagExActrTestMaxPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidPhase8Trans                            */
/* !Description :  calcule de l'etat EXVLVACT_ACTRTST_PHASE8                  */
/* !Number      :  FCT3.3                                                     */
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
/*  input uint16 VlvAct_tiExActrTest9SplSp_C;                                 */
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
void VLVACTEXACTRTEST_vidPhase8Trans(void)
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
         VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_PHASE9);
         VlvAct_tiExActrTestSp = VlvAct_tiExActrTest9SplSp_C;
         u16LocalagExActrTestMaxPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agExActrTestMaxPosSp_C, 1066);
         VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalagExActrTestMaxPos);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidPhase9Trans                            */
/* !Description :  calcule de l'etat EXVLVACT_ACTRTST_PHASE9                  */
/* !Number      :  FCT3.4                                                     */
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
/*  input uint16 VlvAct_tiExActrTest9SplSp_C;                                 */
/*  input uint16 VlvAct_tiExActrTest10SplSp_C;                                */
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*  output boolean VlvAct_bExActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiExActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidPhase9Trans(void)
{
   boolean bLocalSrv_bActrTstExVVTEna;
   uint8   u8LocalCodeTestAction;
   uint16  u16LocalagExActrTestMinPos;
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
                                              VlvAct_tiExActrTest9SplSp_C);

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
                                              VlvAct_tiExActrTest9SplSp_C);
         u32LocalVar = (VlvAct_agExActrTestMinPosSp_C + u32LocalVar);
      }

      u16LocalagExActrTestMinPos = (uint16) MATHSRV_udtMIN(u32LocalVar, 1066);

      if (VlvAct_tiExActrTestSp <= 1)
      {
         VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_PHASE10);
         VlvAct_tiExActrTestSp = VlvAct_tiExActrTest10SplSp_C;
         u16LocalagExActrTestMinPos =
            (uint16)MATHSRV_udtMIN(VlvAct_agExActrTestMinPosSp_C, 1066);
      }
      VEMS_vidSET(VlvAct_agExActrTestPosSp, u16LocalagExActrTestMinPos);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidPhase10Trans                           */
/* !Description :  calcule de l'etat INVLVACT_ACTRTST_PHASE10                 */
/* !Number      :  FCT3.5                                                     */
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
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*  output boolean VlvAct_bExActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*  output uint16 VlvAct_tiExActrTestSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidPhase10Trans(void)
{
   boolean bLocalSrv_bActrTstExVVTEna;
   uint8   u8LocalCodeTestAction;
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
         VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_END);
         VEMS_vidSET(VlvAct_agExActrTestPosSp, 0);
         VEMS_vidSET(VlvAct_bExActrTestSpEndIdc, 1);
         VEMS_vidSET(VlvAct_bExActrTestNotRun, 1);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACTRTEST_vidEndStTrans                             */
/* !Description :  calcule de l'etat  EXVLVACT_ACTRTST_END                    */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Z.HOSNI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  output st115 VlvAct_stExActrTst;                                          */
/*  output uint16 VlvAct_agExActrTestPosSp;                                   */
/*  output boolean VlvAct_bExActrTestSpEndIdc;                                */
/*  output boolean VlvAct_bExActrTestNotRun;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACTRTEST_vidEndStTrans(void)
{
   boolean bLocalSrv_bActrTstExVVTEna;


   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrv_bActrTstExVVTEna);

   if (bLocalSrv_bActrTstExVVTEna == 0)
   {
      VEMS_vidSET(VlvAct_stExActrTst, VLV_EXACTRTST_IDLE);
      VEMS_vidSET(VlvAct_agExActrTestPosSp, 0);
      VEMS_vidSET(VlvAct_bExActrTestSpEndIdc, 0);
      VEMS_vidSET(VlvAct_bExActrTestNotRun, 1);
   }
}
/*------------------------------- end of file --------------------------------*/
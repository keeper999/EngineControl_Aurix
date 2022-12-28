/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACTRTSTCTP                                              */
/* !Description     : ACTRTSTCTP Component                                    */
/*                                                                            */
/* !Module          : ACTRTSTCTP                                              */
/* !Description     : ACTUATOR TEST OF POSITIVE TEMPERATURE COEFFICIENT       */
/*                                                                            */
/* !File            : ACTRTSTCTP_FCT1.C                                       */
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
/*   1 / ACTRTSTCTP_vidRstDft                                                 */
/*   2 / ACTRTSTCTP_vidInitOutput                                             */
/*   3 / ACTRTSTCTP_vidCTPTst                                                 */
/*   4 / ACTRTSTCTP_vidCPTChart                                               */
/*   5 / ACTRTSTCTP_vidDft1dActrTst                                           */
/*   6 / ACTRTSTCTP_vidDft2dActrTst                                           */
/*                                                                            */
/* !Reference   : V02 NT 12 05323 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#064193                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ACTRTSTCTP/ACTRTSTCTP_FCT1.C_v  $*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   11 Dec 2012 $*/
/* $Author::   HHAMLAOU                               $$Date::   11 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACTRTSTCTP.h"
#include "ACTRTSTCTP_L.h"
#include "ACTRTSTCTP_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTCTP_vidRstDft                                       */
/* !Description :  At the reset, default boolean must be reseted              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean CTP_bDft1dActrTst;                                         */
/*  output boolean CTP_bDft2dActrTst;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTCTP_vidRstDft(void)
{
   /*  F01_RstDft   */
   VEMS_vidSET(CTP_bDft1dActrTst, 0);
   VEMS_vidSET(CTP_bDft2dActrTst, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTCTP_vidInitOutput                                   */
/* !Description :  Internal variables and outputs initialization.             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean ACTRTSTCTP_bAcvDft2dActrTstPrev;                           */
/*  output boolean ACTRTSTCTP_bAcvDft1dActrTstPrev;                           */
/*  output st130 CTP_stActrTst;                                               */
/*  output boolean CTP_bActrTstCmpl;                                          */
/*  output boolean CTP_bActrTstInProgs;                                       */
/*  output boolean CTP_bAcvDft1dActrTst;                                      */
/*  output boolean CTP_bAcvDft2dActrTst;                                      */
/*  output boolean CTP_bAcvCTP1ActrTstReq;                                    */
/*  output boolean CTP_bAcvCTP2ActrTstReq;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTCTP_vidInitOutput(void)
{
   ACTRTSTCTP_bAcvDft2dActrTstPrev = 0;
   ACTRTSTCTP_bAcvDft1dActrTstPrev = 0;
   CTP_stActrTst = CTP_ACTRTEST_IDLE;
   VEMS_vidSET(CTP_bActrTstCmpl, 0);
   VEMS_vidSET(CTP_bActrTstInProgs, 0);
   CTP_bAcvDft1dActrTst = 0;
   CTP_bAcvDft2dActrTst = 0;
   VEMS_vidSET(CTP_bAcvCTP1ActrTstReq, 0);
   VEMS_vidSET(CTP_bAcvCTP2ActrTstReq, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTCTP_vidCTPTst                                       */
/* !Description :  During a test request (conditions met and actuator code    */
/*                 matches), records of battery voltage are made at different */
/*                 time.                                                      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_12_05323_001.01                                     */
/*                 VEMS_R_12_05323_002.01                                     */
/*                 VEMS_R_12_05323_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTCTP_vidCPTChart();                                */
/*  extf argret void ACTRTSTCTP_vidDft1dActrTst();                            */
/*  extf argret void ACTRTSTCTP_vidDft2dActrTst();                            */
/*  input boolean ACTRTSTCTP_bAcvDft1dActrTstPrev;                            */
/*  input boolean CTP_bAcvDft1dActrTst;                                       */
/*  input boolean ACTRTSTCTP_bAcvDft2dActrTstPrev;                            */
/*  input boolean CTP_bAcvDft2dActrTst;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTCTP_vidCTPTst(void)
{
   /*   F02_CTPTst    */
   ACTRTSTCTP_vidCPTChart();
   if (  (ACTRTSTCTP_bAcvDft1dActrTstPrev == 0)
      && (CTP_bAcvDft1dActrTst != 0))
   {
      ACTRTSTCTP_vidDft1dActrTst();
   }

   if (  (ACTRTSTCTP_bAcvDft2dActrTstPrev == 0)
      && (CTP_bAcvDft2dActrTst != 0))
   {
      ACTRTSTCTP_vidDft2dActrTst();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTCTP_vidCPTChart                                     */
/* !Description :  During a test request (conditions met and actuator code    */
/*                 matches), records of battery voltage are made at different */
/*                 time.                                                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input uint8 Code_test_action;                                             */
/*  input sint16 Ext_uBattMes;                                                */
/*  input boolean CTP_bAcvDft1dActrTst;                                       */
/*  input boolean CTP_bAcvDft2dActrTst;                                       */
/*  input st130 CTP_stActrTst;                                                */
/*  input uint8 ActrTstCTP_tiDlyTestMem0_C;                                   */
/*  input uint8 ActrTstCTP_tiDlyTestMem1_C;                                   */
/*  input uint16 ActrTstCTP_Tempo_C;                                          */
/*  input uint8 ActrTstCTP_IntTime;                                           */
/*  input uint8 ActrTstCTP_tiDlyTestMem2_C;                                   */
/*  input uint16 ActrTstCTP_uBattMesMem1;                                     */
/*  input uint16 ActrTstCTP_uBattMesMem2;                                     */
/*  input uint16 ActrTstCTP_Tempo;                                            */
/*  output boolean ACTRTSTCTP_bAcvDft1dActrTstPrev;                           */
/*  output boolean ACTRTSTCTP_bAcvDft2dActrTstPrev;                           */
/*  output boolean CTP_bActrTstInProgs;                                       */
/*  output uint8 ActrTstCTP_IntTime;                                          */
/*  output st130 CTP_stActrTst;                                               */
/*  output boolean CTP_bActrTstCmpl;                                          */
/*  output boolean CTP_bAcvDft1dActrTst;                                      */
/*  output boolean CTP_bAcvDft2dActrTst;                                      */
/*  output uint16 ActrTstCTP_uBattMesMem0;                                    */
/*  output uint16 ActrTstCTP_Tempo;                                           */
/*  output boolean CTP_bAcvCTP1ActrTstReq;                                    */
/*  output uint16 ActrTstCTP_uBattMesMem1;                                    */
/*  output boolean CTP_bAcvCTP2ActrTstReq;                                    */
/*  output uint16 ActrTstCTP_uBattMesMem2;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTCTP_vidCPTChart(void)
{
   /*  F01_CPTChart  */
   boolean bLocalSrv_bActrTstEna;
   boolean bLocalTestEna;
   uint8   u8LocalRes;
   uint8   u8LocalCode_test_action;
   sint16  s16Local_uBattMesMem1;
   sint16  s16Local_uBattMesMem2;
   sint16  s16LocalExt_uBattMes;


   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   ACTRTSTCTP_bAcvDft1dActrTstPrev = CTP_bAcvDft1dActrTst;
   ACTRTSTCTP_bAcvDft2dActrTstPrev = CTP_bAcvDft2dActrTst;

   if (  (bLocalSrv_bActrTstEna != 0)
      && (u8LocalCode_test_action == CODE_TEST_CTP))
   {
      bLocalTestEna = 1;
   }
   else
   {
      bLocalTestEna = 0;
   }
   switch(CTP_stActrTst)
   {
      case CTP_ACTRTEST_IDLE:
         /*CTP_ACTRTEST_IDLE ===> CTP_ACTRTEST_MEM0*/
         if (bLocalTestEna != 0)
         {
            VEMS_vidSET(CTP_bActrTstInProgs, 1);
            ActrTstCTP_IntTime =
               (uint8)MATHSRV_udtMIN(ActrTstCTP_tiDlyTestMem0_C, 250);
            CTP_stActrTst = CTP_ACTRTEST_MEM0;
         }
         break;

      case CTP_ACTRTEST_MEM0:
         /*CTP_ACTRTEST_MEM0 ===> CTP_ACTRTEST_IDLE*/
         if (bLocalTestEna == 0)
         {
            CTP_stActrTst = CTP_ACTRTEST_IDLE;
            VEMS_vidSET(CTP_bActrTstCmpl, 0);
            VEMS_vidSET(CTP_bActrTstInProgs, 0);
            CTP_bAcvDft1dActrTst =  0;
            CTP_bAcvDft2dActrTst =  0;
         }
         else
         {
            /*CTP_ACTRTEST_MEM0 ===> CTP_ACTRTEST_END*/
            if (ActrTstCTP_tiDlyTestMem1_C  == 0)
            {
               ActrTstCTP_uBattMesMem0 =
                  (uint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
               CTP_stActrTst = CTP_ACTRTEST_END;
               VEMS_vidSET(CTP_bActrTstCmpl, 1);
               ActrTstCTP_Tempo =
                  (uint16)MATHSRV_udtMIN(ActrTstCTP_Tempo_C, 500);
               VEMS_vidSET(CTP_bActrTstInProgs, 0);
            }
            else
            {
               /*CTP_ACTRTEST_MEM0 ===> CTP_ACTRTEST_MEM1*/
               if (ActrTstCTP_IntTime <= 1)
               {
                  CTP_stActrTst = CTP_ACTRTEST_MEM1;
                  ActrTstCTP_uBattMesMem0 =
                     (uint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
                  VEMS_vidSET(CTP_bAcvCTP1ActrTstReq, 1);
                  ActrTstCTP_IntTime =
                     (uint8)MATHSRV_udtMIN(ActrTstCTP_tiDlyTestMem1_C,250);
                  ActrTstCTP_uBattMesMem1 =
                     (uint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
               }
               else
               {
                  /*during of CTP_ACTRTEST_MEM0*/
                  u8LocalRes = (uint8)(ActrTstCTP_IntTime - 1);
                  ActrTstCTP_IntTime = (uint8)MATHSRV_udtMIN(u8LocalRes, 250);
               }
            }
         }
         break;

      case CTP_ACTRTEST_MEM1:
         /*CTP_ACTRTEST_MEM1 ==> CTP_ACTRTEST_IDLE*/
         if (bLocalTestEna == 0)
         {
            CTP_stActrTst = CTP_ACTRTEST_IDLE;
            VEMS_vidSET(CTP_bActrTstCmpl, 0);
            VEMS_vidSET(CTP_bActrTstInProgs, 0);
            CTP_bAcvDft1dActrTst =  0;
            CTP_bAcvDft2dActrTst =  0;
         }
         else
         {
            /*CTP_ACTRTEST_MEM1 ==> CTP_ACTRTEST_END*/
            if (ActrTstCTP_tiDlyTestMem2_C == 0)
            {
               CTP_stActrTst = CTP_ACTRTEST_END;
               s16Local_uBattMesMem1 =
                  (sint16)MATHSRV_udtMIN(ActrTstCTP_uBattMesMem1,
                                         s16LocalExt_uBattMes);
               ActrTstCTP_uBattMesMem1 =
                  (uint16)MATHSRV_udtCLAMP(s16Local_uBattMesMem1, 0, 3200);
               VEMS_vidSET(CTP_bAcvCTP1ActrTstReq, 0);
               CTP_bAcvDft1dActrTst =  1;
               VEMS_vidSET(CTP_bActrTstCmpl, 1);
               ActrTstCTP_Tempo =
                  (uint16)MATHSRV_udtMIN(ActrTstCTP_Tempo_C, 500);
               VEMS_vidSET(CTP_bActrTstInProgs, 0);
            }
            else
            {
               /*CTP_ACTRTEST_MEM1 ==> CTP_ACTRTEST_MEM2*/
               if (ActrTstCTP_IntTime <= 1)
               {
                  CTP_stActrTst = CTP_ACTRTEST_MEM2;
                  s16Local_uBattMesMem1 =
                     (sint16)MATHSRV_udtMIN(ActrTstCTP_uBattMesMem1,
                                            s16LocalExt_uBattMes);
                  ActrTstCTP_uBattMesMem1 =
                     (uint16)MATHSRV_udtCLAMP(s16Local_uBattMesMem1, 0, 3200);
                  VEMS_vidSET(CTP_bAcvCTP1ActrTstReq, 0);
                  CTP_bAcvDft1dActrTst =  1;
                  ActrTstCTP_IntTime =
                     (uint8)MATHSRV_udtMIN(ActrTstCTP_tiDlyTestMem2_C, 250);
                  VEMS_vidSET(CTP_bAcvCTP2ActrTstReq, 1);
                  ActrTstCTP_uBattMesMem2 =
                     (uint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
               }
               else
               {
                  /*during of CTP_ACTRTEST_MEM1*/
                  u8LocalRes = (uint8)(ActrTstCTP_IntTime - 1);
                  ActrTstCTP_IntTime = (uint8)MATHSRV_udtMIN(u8LocalRes, 250);
                  s16Local_uBattMesMem1 =
                     (sint16)MATHSRV_udtMIN(ActrTstCTP_uBattMesMem1,
                                            s16LocalExt_uBattMes);
                  ActrTstCTP_uBattMesMem1 =
                     (uint16)MATHSRV_udtCLAMP(s16Local_uBattMesMem1, 0, 3200);
               }
            }
         }
         break;

      case CTP_ACTRTEST_MEM2:
         /*CTP_ACTRTEST_MEM2 ==> CTP_ACTRTEST_IDLE*/
         if (bLocalTestEna == 0)
         {
            CTP_stActrTst = CTP_ACTRTEST_IDLE;
            VEMS_vidSET(CTP_bActrTstCmpl, 0);
            VEMS_vidSET(CTP_bActrTstInProgs, 0);
            CTP_bAcvDft1dActrTst = 0;
            CTP_bAcvDft2dActrTst = 0;
         }
         else
         {
            /*CTP_ACTRTEST_MEM2 ==> CTP_ACTRTEST_END*/
            if (ActrTstCTP_IntTime <= 1)
            {
               CTP_stActrTst = CTP_ACTRTEST_END;
               s16Local_uBattMesMem2 =
                  (sint16)MATHSRV_udtMIN(ActrTstCTP_uBattMesMem2,
                                         s16LocalExt_uBattMes);
               ActrTstCTP_uBattMesMem2 =
                  (uint16)MATHSRV_udtCLAMP(s16Local_uBattMesMem2, 0, 3200);
               VEMS_vidSET(CTP_bAcvCTP2ActrTstReq, 0);
               CTP_bAcvDft2dActrTst =  1;
               VEMS_vidSET(CTP_bActrTstCmpl, 1);
               ActrTstCTP_Tempo =
                  (uint16)MATHSRV_udtMIN(ActrTstCTP_Tempo_C, 500);
               VEMS_vidSET(CTP_bActrTstInProgs, 0);
            }
            else
            {
               /*during of CTP_ACTRTEST_MEM2*/
               u8LocalRes = (uint8)(ActrTstCTP_IntTime - 1);
               ActrTstCTP_IntTime = (uint8)MATHSRV_udtMIN(u8LocalRes, 250);
               s16Local_uBattMesMem2 =
                  (sint16)MATHSRV_udtMIN(ActrTstCTP_uBattMesMem2,
                                         s16LocalExt_uBattMes);
               ActrTstCTP_uBattMesMem2 =
                  (uint16)MATHSRV_udtCLAMP(s16Local_uBattMesMem2, 0, 3200);
            }
         }
         break;

      case CTP_ACTRTEST_END:
         /*CTP_ACTRTEST_END ==> CTP_ACTRTEST_IDLE*/
         if (  (bLocalTestEna != 0)
            && (ActrTstCTP_Tempo <= 0))
         {
            CTP_stActrTst = CTP_ACTRTEST_IDLE;
            VEMS_vidSET(CTP_bActrTstCmpl, 0);
            VEMS_vidSET(CTP_bActrTstInProgs, 0);
            CTP_bAcvDft1dActrTst =  0;
            CTP_bAcvDft2dActrTst =  0;
         }
         else
         {
            /*during of CTP_ACTRTEST_END*/
            u8LocalRes = (uint8)(ActrTstCTP_Tempo - 1);
            ActrTstCTP_Tempo = u8LocalRes;
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         CTP_stActrTst = CTP_ACTRTEST_IDLE;
         VEMS_vidSET(CTP_bActrTstCmpl, 0);
         VEMS_vidSET(CTP_bActrTstInProgs, 0);
         CTP_bAcvDft1dActrTst =  0;
         CTP_bAcvDft2dActrTst =  0;
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTCTP_vidDft1dActrTst                                 */
/* !Description :  A default is declared (CTP_bDft1dActrTst = 1) if this      */
/*                 condition is false :ActrTstCTP_uMinBattMem1_C <            */
/*                 ActrTstCTP_uBattMesMem0 - ActrTstCTP_uBattMesMem1 <        */
/*                 ActrTstCTP_uMaxBattMem1_C.                                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ActrTstCTP_uBattMesMem0;                                     */
/*  input uint16 ActrTstCTP_uBattMesMem1;                                     */
/*  input uint16 ActrTstCTP_uMinBattMem1_C;                                   */
/*  input uint16 ActrTstCTP_uMaxBattMem1_C;                                   */
/*  input uint8 ActrTstCTP_tiDlyTestMem1_C;                                   */
/*  output boolean CTP_bDft1dActrTst;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTCTP_vidDft1dActrTst(void)
{
   /*  F02_Dft1dActrTst   */
   boolean bLocalResult;
   sint32  s32LocalResult;


   s32LocalResult = (sint32)(ActrTstCTP_uBattMesMem0 - ActrTstCTP_uBattMesMem1);
   if (  (ActrTstCTP_uMinBattMem1_C > s32LocalResult)
      || (s32LocalResult > ActrTstCTP_uMaxBattMem1_C))
   {
      bLocalResult = 1;
   }
   else
   {
      bLocalResult = 0;
   }
   if (ActrTstCTP_tiDlyTestMem1_C != 0)
   {
      VEMS_vidSET(CTP_bDft1dActrTst, bLocalResult);
   }
   else
   {
      VEMS_vidSET(CTP_bDft1dActrTst, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTCTP_vidDft2dActrTst                                 */
/* !Description :  A default is declared (CTP_bDft2dActrTst = 1) if this      */
/*                 condition is false :ActrTstCTP_uMinBattMem2_C <            */
/*                 ActrTstCTP_uBattMesMem0 - ActrTstCTP_uBattMesMem2 <        */
/*                 ActrTstCTP_uMaxBattMem2_C.                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ActrTstCTP_uBattMesMem0;                                     */
/*  input uint16 ActrTstCTP_uBattMesMem2;                                     */
/*  input uint16 ActrTstCTP_uMinBattMem2_C;                                   */
/*  input uint16 ActrTstCTP_uMaxBattMem2_C;                                   */
/*  input uint8 ActrTstCTP_tiDlyTestMem2_C;                                   */
/*  output boolean CTP_bDft2dActrTst;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTCTP_vidDft2dActrTst(void)
{
   /*  F02_Dft2dActrTst  */
   boolean bLocalResult;
   sint32  s32LocalResult;


   s32LocalResult = (sint32)(ActrTstCTP_uBattMesMem0 - ActrTstCTP_uBattMesMem2);
   if (  (ActrTstCTP_uMinBattMem2_C > s32LocalResult)
      || (s32LocalResult > ActrTstCTP_uMaxBattMem2_C))
   {
      bLocalResult = 1;
   }
   else
   {
      bLocalResult = 0;
   }
   if (ActrTstCTP_tiDlyTestMem2_C != 0)
   {
      VEMS_vidSET(CTP_bDft2dActrTst, bLocalResult);
   }
   else
   {
      VEMS_vidSET(CTP_bDft2dActrTst, 0);
   }
}
/*-------------------------------- End of file -------------------------------*/
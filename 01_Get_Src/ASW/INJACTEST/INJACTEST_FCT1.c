/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJACTEST                                               */
/* !Description     : INJACTEST Component                                     */
/*                                                                            */
/* !Module          : INJACTEST                                               */
/* !Description     : TESTS ACTIONNEURS DES INJECTEURS                        */
/*                                                                            */
/* !File            : INJACTEST_FCT1.C                                        */
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
/*   1 / INJACTEST_vidInitOutput                                              */
/*   2 / INJACTEST_vidTimeToInj                                               */
/*   3 / INJACTEST_vidTimeToInjCln                                            */
/*   4 / INJACTEST_vidEntryMode                                               */
/*   5 / INJACTEST_vidTestMode                                                */
/*   6 / INJACTEST_vidTestEnd                                                 */
/*   7 / INJACTEST_vidTestFrLstRun                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5135792 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065909                                         */
/* !OtherRefs   : VEMS V02 ECU#065504                                         */
/* !OtherRefs   : VEMS V02 ECU#065669                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJACTEST/INJACTEST_FCT1.C$*/
/* $Revision::   1.4      $$Author::   HHAMLAOU       $$Date::   06 Sep 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   06 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "INJACTEST.h"
#include "INJACTEST_L.h"
#include "INJACTEST_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidInitOutput                                    */
/* !Description :  Outputs initialization                                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st83 Inj_stActrTst;                                                */
/*  output uint16 ActrTstInj_TimeToInject;                                    */
/*  output boolean Inj_bPwrRlyCmd;                                            */
/*  output uint16 ActrTstInj_TempoIdle;                                       */
/*  output boolean Inj_bInjTstCmpl;                                           */
/*  output boolean Inj_bInj1TstCmpl;                                          */
/*  output boolean Inj_bInj2TstCmpl;                                          */
/*  output boolean Inj_bInj3TstCmpl;                                          */
/*  output boolean Inj_bInj4TstCmpl;                                          */
/*  output boolean INJACTEST_bMemFirstFillFuPrev;                             */
/*  output boolean INJACTEST_bMemFirstFillFuPrev2;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidInitOutput(void)
{
   /* State machine initialization */
   Inj_stActrTst = INJ_ACTRTST_IDLE;
   ActrTstInj_TimeToInject = 0;
   VEMS_vidSET(Inj_bPwrRlyCmd, 0);
   ActrTstInj_TempoIdle = 0;
   /* Outputs initialization */
   Inj_bInjTstCmpl = 0;
   VEMS_vidSET(Inj_bInj1TstCmpl, 0);
   VEMS_vidSET(Inj_bInj2TstCmpl, 0);
   VEMS_vidSET(Inj_bInj3TstCmpl, 0);
   VEMS_vidSET(Inj_bInj4TstCmpl, 0);
   INJACTEST_bMemFirstFillFuPrev = 0;
   INJACTEST_bMemFirstFillFuPrev2 = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidTimeToInj                                     */
/* !Description :  The manager determines if an actuator testor injector      */
/*                 opening first start factorymust be launched or not. In case*/
/*                 of an actuator test request, the power relay is closed and */
/*                 Inj_bInjTstCmpl is set at 0 (test uncompleted).            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJACTEST_vidTimeToInjCln();                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input boolean FTPCtl_bMemFirstFillFu;                                     */
/*  input boolean INJACTEST_bMemFirstFillFuPrev2;                             */
/*  input uint8 INJACTEST_u8CodeActrTestPrev;                                 */
/*  input boolean Inj_bInjTstCmpl;                                            */
/*  output boolean INJACTEST_bTestEna;                                        */
/*  output boolean ActrTest_bAcvInjFirstFillFu;                               */
/*  output boolean INJACTEST_bChgtActuator;                                   */
/*  output boolean Inj_bInj1TstCmpl;                                          */
/*  output boolean Inj_bInj2TstCmpl;                                          */
/*  output boolean Inj_bInj3TstCmpl;                                          */
/*  output boolean Inj_bInj4TstCmpl;                                          */
/*  output uint8 INJACTEST_u8CodeActrTestPrev;                                */
/*  output boolean INJACTEST_bMemFirstFillFuPrev2;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidTimeToInj(void)
{
   boolean bLocalSrv_bActrTstEna;
   boolean bLocalInj_bInj1TstCmpl;
   boolean bLocalInj_bInj2TstCmpl;
   boolean bLocalInj_bInj3TstCmpl;
   boolean bLocalInj_bInj4TstCmpl;
   boolean bLocalFTPCtl_bMemFirstFillFu;
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);

   if (  (  (u8LocalCode_test_action == CODE_TEST_INJECTEUR_1)
         || (u8LocalCode_test_action == CODE_TEST_INJECTEUR_2)
         || (u8LocalCode_test_action == CODE_TEST_INJECTEUR_3)
         || (u8LocalCode_test_action == CODE_TEST_INJECTEUR_4))
      && (bLocalSrv_bActrTstEna != 0) )
   {
      INJACTEST_bTestEna = 1;
   }
   else
   {
      INJACTEST_bTestEna = 0;
   }

   VEMS_vidGET(FTPCtl_bMemFirstFillFu, bLocalFTPCtl_bMemFirstFillFu);
   if (  (bLocalFTPCtl_bMemFirstFillFu == 0)
      && (INJACTEST_bMemFirstFillFuPrev2 != 0))
   {
      ActrTest_bAcvInjFirstFillFu = 1;
   }
   else
   {
      ActrTest_bAcvInjFirstFillFu = 0;
   }

   if (u8LocalCode_test_action != INJACTEST_u8CodeActrTestPrev)
   {
      INJACTEST_bChgtActuator = 1;
   }
   else
   {
      INJACTEST_bChgtActuator = 0;
   }

   INJACTEST_vidTimeToInjCln();

   bLocalInj_bInj1TstCmpl = 0;
   bLocalInj_bInj2TstCmpl = 0;
   bLocalInj_bInj3TstCmpl = 0;
   bLocalInj_bInj4TstCmpl = 0;

   if (Inj_bInjTstCmpl != 0)
   {
      if (u8LocalCode_test_action == CODE_TEST_INJECTEUR_1)
      {
         bLocalInj_bInj1TstCmpl = 1;
      }
      else
      {
         if (u8LocalCode_test_action == CODE_TEST_INJECTEUR_2)
         {
            bLocalInj_bInj2TstCmpl = 1;
         }
         else
         {
            if (u8LocalCode_test_action == CODE_TEST_INJECTEUR_3)
            {
               bLocalInj_bInj3TstCmpl = 1;
            }
            else
            {
               if (u8LocalCode_test_action == CODE_TEST_INJECTEUR_4)
               {
                  bLocalInj_bInj4TstCmpl = 1;
               }
            }
         }
      }
   }
   VEMS_vidSET(Inj_bInj1TstCmpl, bLocalInj_bInj1TstCmpl);
   VEMS_vidSET(Inj_bInj2TstCmpl, bLocalInj_bInj2TstCmpl);
   VEMS_vidSET(Inj_bInj3TstCmpl, bLocalInj_bInj3TstCmpl);
   VEMS_vidSET(Inj_bInj4TstCmpl, bLocalInj_bInj4TstCmpl);

   INJACTEST_u8CodeActrTestPrev = u8LocalCode_test_action;
   INJACTEST_bMemFirstFillFuPrev2 = bLocalFTPCtl_bMemFirstFillFu;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidTimeToInjCln                                  */
/* !Description :  La machine à états détermine si un test actionneur doit    */
/*                 être lancé ou non.                                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJACTEST_vidStateIdle();                                */
/*  extf argret void INJACTEST_vidStateStart();                               */
/*  extf argret void INJACTEST_vidStateOn();                                  */
/*  extf argret void INJACTEST_vidStateOff();                                 */
/*  extf argret void INJACTEST_vidStateStop();                                */
/*  extf argret void INJACTEST_vidStateEnd();                                 */
/*  extf argret void INJACTEST_vidStateLdbReconf();                           */
/*  extf argret void INJACTEST_vidStateFirstFull();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st83 Inj_stActrTst;                                                 */
/*  output uint8 Inj_stActrTst_prev;                                          */
/*  output st83 Inj_stActrTst;                                                */
/*  output uint16 ActrTstInj_TimeToInject;                                    */
/*  output boolean Inj_bPwrRlyCmd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidTimeToInjCln(void)
{
   Inj_stActrTst_prev = Inj_stActrTst;
   switch (Inj_stActrTst)
   {
      case INJ_ACTRTST_IDLE:
         INJACTEST_vidStateIdle();
         break;

      case INJ_ACTRTST_START:
         INJACTEST_vidStateStart();
         break;

      case INJ_ACTRTST_ON:
         INJACTEST_vidStateOn();
         break;

      case INJ_ACTRTST_OFF:
         INJACTEST_vidStateOff();
         break;

      case INJ_ACTRTST_STOP:
         INJACTEST_vidStateStop();
         break;

      case INJ_ACTRTST_END:
         INJACTEST_vidStateEnd();
         break;

      case INJ_ACTRTST_LDB_RECONF:
         INJACTEST_vidStateLdbReconf();
         break;

      case INJ_FIRSTFULL:
         INJACTEST_vidStateFirstFull();
         break;

      default:
         Inj_stActrTst = INJ_ACTRTST_IDLE;
         ActrTstInj_TimeToInject = 0;
         VEMS_vidSET(Inj_bPwrRlyCmd, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidEntryMode                                     */
/* !Description :  LDB is informed that an actuator test or an injector       */
/*                 opening first start factory will be executed.              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJHAL_vidTestModeEntry();                               */
/*  input uint8 Code_test_action;                                             */
/*  input boolean FTPCtl_bMemFirstFillFu;                                     */
/*  input st83 Inj_stActrTst;                                                 */
/*  input uint8 Inj_noInjFirstFull_C;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidEntryMode(void)
{
   boolean bLocalTestInj;
   boolean bLocalFirstFullInj;
   boolean bLocalFTPCtl_bMemFirstFillFu;
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(FTPCtl_bMemFirstFillFu, bLocalFTPCtl_bMemFirstFillFu);

   if (  (Inj_stActrTst == INJ_ACTRTST_START)
      && (  (u8LocalCode_test_action == CODE_TEST_INJECTEUR_1)
         || (u8LocalCode_test_action == CODE_TEST_INJECTEUR_3)
         || (u8LocalCode_test_action == CODE_TEST_INJECTEUR_2)
         || (  (u8LocalCode_test_action == CODE_TEST_INJECTEUR_4)
            && (Ext_noCylEng_SC != 3) )))
/*QAC Msg(3:3356) : Ext_noCylEng_SC is a constant */
   {
      bLocalTestInj = 1;
   }
   else
   {
      bLocalTestInj = 0;
   }

   if (  (Inj_stActrTst == INJ_FIRSTFULL)
      && (bLocalFTPCtl_bMemFirstFillFu == 0)
      && (  (Inj_noInjFirstFull_C == 1)
         || (Inj_noInjFirstFull_C == 3)
         || (Inj_noInjFirstFull_C == 2)
         || (  (Inj_noInjFirstFull_C == 4)
            && (Ext_noCylEng_SC != 3) )))
/*QAC Msg(3:3356) : Ext_noCylEng_SC is a constant */
   {
      bLocalFirstFullInj = 1;
   }
   else
   {
      bLocalFirstFullInj = 0;
   }
   if (  (bLocalTestInj != 0)
      || (bLocalFirstFullInj != 0))
   {
      INJHAL_vidTestModeEntry();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidTestMode                                      */
/* !Description :  An injection time is calculated for the actuator testor    */
/*                 injector opening first start factoryand sent to the LDB.   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJHAL_vidWriteTestTime(argin uint8 u8Channel, argin     */
/* uint32 u32InjTestTime);                                                    */
/*  input uint16 ActrTstInj_TimeToInject;                                     */
/*  input st83 Inj_stActrTst;                                                 */
/*  input uint8 Inj_stActrTst_prev;                                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean FTPCtl_bMemFirstFillFu;                                     */
/*  input uint8 Inj_noInjFirstFull_C;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidTestMode(void)
{
   boolean bLocalFTPCtl_bMemFirstFillFu;
   boolean bLocalInjstActrTstRisingEdge;
   uint8   u8LocalCode_test_action;
   uint32  u32LocalTimeToInject;


   u32LocalTimeToInject = (uint32)(ActrTstInj_TimeToInject * 10000);

   if (  (Inj_stActrTst == INJ_ACTRTST_ON)
      && (Inj_stActrTst_prev != INJ_ACTRTST_ON))
   {
      bLocalInjstActrTstRisingEdge = 1;
   }
   else
   {
      bLocalInjstActrTstRisingEdge = 0;
   }

   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(FTPCtl_bMemFirstFillFu, bLocalFTPCtl_bMemFirstFillFu);

   if (  (  (bLocalInjstActrTstRisingEdge != 0)
         && (u8LocalCode_test_action == CODE_TEST_INJECTEUR_1))
      || (  (bLocalFTPCtl_bMemFirstFillFu == 0)
         && (Inj_noInjFirstFull_C == 1)))
   {
      INJHAL_vidWriteTestTime(INJ_HAL_CYLINDER_A, u32LocalTimeToInject);
   }

   if (  (  (bLocalInjstActrTstRisingEdge != 0)
         && (u8LocalCode_test_action == CODE_TEST_INJECTEUR_3))
      || (  (bLocalFTPCtl_bMemFirstFillFu == 0)
         && (Inj_noInjFirstFull_C == 3)))
   {
      INJHAL_vidWriteTestTime(INJ_HAL_CYLINDER_B, u32LocalTimeToInject);
   }

   if (Ext_noCylEng_SC == 3)
/*QAC Msg(2:3346) : Ext_noCylEng_SC is a constant */
   {
      if (  (  (bLocalInjstActrTstRisingEdge != 0)
            && (u8LocalCode_test_action == CODE_TEST_INJECTEUR_2))
         || (  (bLocalFTPCtl_bMemFirstFillFu == 0)
            && (Inj_noInjFirstFull_C == 2)))
      {
         INJHAL_vidWriteTestTime(INJ_HAL_CYLINDER_C, u32LocalTimeToInject);
      }
   }
   else
   {
      if (  (  (bLocalInjstActrTstRisingEdge != 0)
            && (u8LocalCode_test_action == CODE_TEST_INJECTEUR_4))
         || (  (bLocalFTPCtl_bMemFirstFillFu == 0)
            && (Inj_noInjFirstFull_C == 4)))
      {
         INJHAL_vidWriteTestTime(INJ_HAL_CYLINDER_C, u32LocalTimeToInject);
      }
      else
      {
         if (  (  (bLocalInjstActrTstRisingEdge != 0)
            && (u8LocalCode_test_action == CODE_TEST_INJECTEUR_2))
         || (  (bLocalFTPCtl_bMemFirstFillFu == 0)
            && (Inj_noInjFirstFull_C == 2)))
         {
            INJHAL_vidWriteTestTime(INJ_HAL_CYLINDER_D,
                                    u32LocalTimeToInject);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidTestEnd                                       */
/* !Description :  When the actuator test or the injector opening first start */
/*                 factory has ended, the LDB must go back to a synchronous   */
/*                 configuration.                                             */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJHAL_vidTestModeExit();                                */
/*  input uint8 Code_test_action;                                             */
/*  input uint8 Inj_noInjFirstFull_C;                                         */
/*  input st83 Inj_stActrTst;                                                 */
/*  input boolean FTPCtl_bMemFirstFillFu;                                     */
/*  input boolean INJACTEST_bMemFirstFillFuPrev;                              */
/*  output boolean INJACTEST_bMemFirstFillFuPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidTestEnd(void)
{
   boolean bLocalTestInj_1;
   boolean bLocalFirstFullInj_1;
   boolean bLocalTestInj_2;
   boolean bLocalFirstFullInj_2;
   boolean bLocalFTPCtl_bMemFirstFillFu;
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);

   if (  (u8LocalCode_test_action == CODE_TEST_INJECTEUR_1)
      || (u8LocalCode_test_action == CODE_TEST_INJECTEUR_3)
      || (u8LocalCode_test_action == CODE_TEST_INJECTEUR_2)
      || (  (u8LocalCode_test_action == CODE_TEST_INJECTEUR_4)
         && (Ext_noCylEng_SC != 3) ))
/*QAC Msg(3:3356) : Ext_noCylEng_SC is a constant */
   {
      bLocalTestInj_1 = 1;
   }
   else
   {
      bLocalTestInj_1 = 0;
   }

   if (  (Inj_noInjFirstFull_C == 1)
      || (Inj_noInjFirstFull_C == 3)
      || (Inj_noInjFirstFull_C == 2)
      || (  (Inj_noInjFirstFull_C == 4)
         && (Ext_noCylEng_SC != 3) ))
/*QAC Msg(3:3356) : Ext_noCylEng_SC is a constant */
   {
      bLocalFirstFullInj_1 = 1;
   }
   else
   {
      bLocalFirstFullInj_1 = 0;
   }

   if (  (Inj_stActrTst == INJ_ACTRTST_END)
      || (Inj_stActrTst == INJ_ACTRTST_STOP))
   {
      bLocalTestInj_2 = 1;
   }
   else
   {
      bLocalTestInj_2 = 0;
   }

   VEMS_vidGET(FTPCtl_bMemFirstFillFu, bLocalFTPCtl_bMemFirstFillFu);

   if (  (Inj_stActrTst == INJ_ACTRTST_IDLE)
      && (bLocalFTPCtl_bMemFirstFillFu != 0)
      && (INJACTEST_bMemFirstFillFuPrev == 0))
   {
      bLocalFirstFullInj_2 = 1;
   }
   else
   {
      bLocalFirstFullInj_2 = 0;
   }

   if (  (bLocalFirstFullInj_2 != 0)
      || (  (bLocalFTPCtl_bMemFirstFillFu == 0)
         && (Inj_stActrTst != INJ_FIRSTFULL)
         && (Inj_stActrTst != INJ_ACTRTST_IDLE)
         && (  (u8LocalCode_test_action != CODE_TEST_INJECTEUR_1)
            || (Inj_noInjFirstFull_C != 1))
         && (  (u8LocalCode_test_action != CODE_TEST_INJECTEUR_2)
            || (Inj_noInjFirstFull_C != 2))
         && (  (u8LocalCode_test_action != CODE_TEST_INJECTEUR_3)
            || (Inj_noInjFirstFull_C != 3))
         && (  (u8LocalCode_test_action != CODE_TEST_INJECTEUR_4)
            || (Inj_noInjFirstFull_C != 4)
            || (Ext_noCylEng_SC == 3))))
/* QAC Msg(3:3355): The result of this logical operation is always 'true' */
   {
      bLocalFirstFullInj_2 = 1;
   }
   else
   {
      bLocalFirstFullInj_2 = 0;
   }

   if (  (  (bLocalTestInj_1 != 0)
         && (bLocalTestInj_2 != 0))
      || (  (bLocalFirstFullInj_1 != 0)
         && (bLocalFirstFullInj_2 != 0)))
   {
      INJHAL_vidTestModeExit();
   }

   if ( bLocalFTPCtl_bMemFirstFillFu != 0)
   {
      INJACTEST_bMemFirstFillFuPrev = 1;
   }
   else
   {
      INJACTEST_bMemFirstFillFuPrev = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidTestFrLstRun                                  */
/* !Description :  Il est nécessaire de savoir si un test actionneur injecteur*/
/*                 a été réalisé depuis le dernier démarrage moteur afin de ne*/
/*                 pas autoriser le test actionneur bobine.                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st83 Inj_stActrTst;                                                 */
/*  input st23 Vehicle_active_state;                                          */
/*  output boolean Inj_bInjTestDone;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidTestFrLstRun(void)
{
   uint8 u8LocalVehicle_active_state;


   if (Inj_stActrTst == INJ_ACTRTST_ON)
   {
      VEMS_vidSET(Inj_bInjTestDone, 1);
   }
   else
   {
      VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
      if (u8LocalVehicle_active_state == VS_RUNNING)
      {
         VEMS_vidSET(Inj_bInjTestDone, 0);
      }
   }
}
/*----------------------------- end of file ----------------------------------*/
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
/* !File            : INJACTEST_FCT2.C                                        */
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
/*   1 / INJACTEST_vidStateIdle                                               */
/*   2 / INJACTEST_vidStateStart                                              */
/*   3 / INJACTEST_vidStateOn                                                 */
/*   4 / INJACTEST_vidStateOff                                                */
/*   5 / INJACTEST_vidStateStop                                               */
/*   6 / INJACTEST_vidStateEnd                                                */
/*   7 / INJACTEST_vidStateLdbReconf                                          */
/*   8 / INJACTEST_vidStateFirstFull                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5135792 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065909                                         */
/* !OtherRefs   : VEMS V02 ECU#065504                                         */
/* !OtherRefs   : VEMS V02 ECU#065669                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJACTEST/INJACTEST_FCT2.C$*/
/* $Revision::   1.4      $$Author::   HHAMLAOU       $$Date::   06 Sep 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   06 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "INJACTEST.h"
#include "INJACTEST_L.h"
#include "INJACTEST_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidStateIdle                                     */
/* !Description :  Treatment executed on state INJ_ACTRTST_IDLE               */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean INJACTEST_bTestEna;                                         */
/*  input uint16 ActrTstInj_TempoIdle;                                        */
/*  input boolean ActrTest_bAcvInjFirstFillFu;                                */
/*  input uint16 Inj_tiDlyFirstFillFu_C;                                      */
/*  output st83 Inj_stActrTst;                                                */
/*  output uint16 ActrTstInj_TimeToInject;                                    */
/*  output boolean Inj_bPwrRlyCmd;                                            */
/*  output boolean Inj_bInjTstCmpl;                                           */
/*  output st133 Inj_stFirstFull;                                             */
/*  output uint16 Inj_tiCntFirstFull;                                         */
/*  output uint16 ActrTstInj_TempoIdle;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidStateIdle(void)
{
   uint16  u16LocalActrTstInj_TempoIdle;


   if (  (INJACTEST_bTestEna != 0)
      && (ActrTstInj_TempoIdle == 0))
   {
      Inj_stActrTst = INJ_ACTRTST_START;
      ActrTstInj_TimeToInject = 0;
      VEMS_vidSET(Inj_bPwrRlyCmd, 1);
      Inj_bInjTstCmpl = 0;
   }
   else
   {
      if (ActrTest_bAcvInjFirstFillFu != 0)
      {
         Inj_stActrTst = INJ_FIRSTFULL;
         Inj_stFirstFull = INJ_DELAY_FIRSFTFULL;
         if ( Inj_tiDlyFirstFillFu_C < 1500)
         {
            Inj_tiCntFirstFull =  (uint16)(Inj_tiDlyFirstFillFu_C + 1);
         }
         else
         {
            Inj_tiCntFirstFull = 1500;
         }
         VEMS_vidSET(Inj_bPwrRlyCmd, 0);
      }
      else
      {
         if (ActrTstInj_TempoIdle > 0)
         {
            u16LocalActrTstInj_TempoIdle = (uint16)(ActrTstInj_TempoIdle - 1);
            ActrTstInj_TempoIdle =
               (uint16)MATHSRV_udtMIN(u16LocalActrTstInj_TempoIdle, 3000);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidStateStart                                    */
/* !Description :  Treatment executed on state INJ_ACTRTST_START              */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean INJACTEST_bTestEna;                                         */
/*  input uint16 Afts_tiTestInj_C;                                            */
/*  input uint16 Afts_tiDlyTotTestInj_C;                                      */
/*  output st83 Inj_stActrTst;                                                */
/*  output uint16 ActrTstInj_TimeToInject;                                    */
/*  output boolean Inj_bPwrRlyCmd;                                            */
/*  output uint16 ActrTstInj_CumulTime;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidStateStart(void)
{
   if (INJACTEST_bTestEna != 0)
   {
      Inj_stActrTst = INJ_ACTRTST_ON;
      ActrTstInj_TimeToInject =  Afts_tiTestInj_C;
      VEMS_vidSET(Inj_bPwrRlyCmd, 1);
      ActrTstInj_CumulTime =
         (uint16)MATHSRV_udtMIN(Afts_tiDlyTotTestInj_C, 5000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidStateOn                                       */
/* !Description :  Treatment executed on state INJ_ACTRTST_ON                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean INJACTEST_bTestEna;                                         */
/*  input boolean INJACTEST_bChgtActuator;                                    */
/*  input uint16 ActrTstInj_CumulTime;                                        */
/*  input uint16 Afts_tiTestInj_C;                                            */
/*  input uint16 Afts_tiPerTestInj_C;                                         */
/*  input uint16 ActrTstInj_TimeToInject;                                     */
/*  output st83 Inj_stActrTst;                                                */
/*  output uint16 ActrTstInj_TimeToInject;                                    */
/*  output boolean Inj_bPwrRlyCmd;                                            */
/*  output boolean Inj_bInjTstCmpl;                                           */
/*  output uint16 ActrTstInj_IntTime;                                         */
/*  output uint16 ActrTstInj_CumulTime;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidStateOn(void)
{
   uint16 u16LocalCumulTime;
   uint16 u16LocalTimeToInject;
   uint32 u32LocalInjTime;
   sint32 s32LocalIntTime;


   if (  (INJACTEST_bTestEna == 0)
      || (INJACTEST_bChgtActuator != 0))
   {
      Inj_stActrTst = INJ_ACTRTST_STOP;
      ActrTstInj_TimeToInject = 0;
      VEMS_vidSET(Inj_bPwrRlyCmd, 1);
      Inj_bInjTstCmpl = 0;
   }
   else
   {
      if (ActrTstInj_CumulTime <= 1)
      {
         Inj_stActrTst = INJ_ACTRTST_LDB_RECONF;
         ActrTstInj_TimeToInject = 0;
         VEMS_vidSET(Inj_bPwrRlyCmd, 1);
         Inj_bInjTstCmpl = 1;
      }
      else
      {
         u32LocalInjTime = (uint32)(Afts_tiTestInj_C + Afts_tiPerTestInj_C);
         if (  (ActrTstInj_TimeToInject <= (uint16)Inj_SampleTiFast_SC)
            && (u32LocalInjTime > (uint32)Inj_SampleTiFast_SC))
         {
            Inj_stActrTst = INJ_ACTRTST_OFF;
            s32LocalIntTime = ( ( (sint32)( ActrTstInj_TimeToInject
                                          + Afts_tiPerTestInj_C)
                                - (sint32)Inj_SampleTiFast_SC));
            ActrTstInj_IntTime = (uint16)MATHSRV_udtCLAMP(s32LocalIntTime,
                                                          0,
                                                          50000);
            ActrTstInj_TimeToInject = 0;
         }
         else
         {
            /* during state INJ_ACTRTST_ON */
            if (ActrTstInj_TimeToInject > (uint16)Inj_SampleTiFast_SC)
            {
               u16LocalTimeToInject = (uint16)((ActrTstInj_TimeToInject
                                              - (uint16)Inj_SampleTiFast_SC));
               ActrTstInj_TimeToInject = u16LocalTimeToInject;
            }
         }
         u16LocalCumulTime = (uint16)(ActrTstInj_CumulTime - 1);
         ActrTstInj_CumulTime = (uint16)MATHSRV_udtMIN(u16LocalCumulTime, 5000);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidStateOff                                      */
/* !Description :  Treatment executed on state INJ_ACTRTST_OFF                */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean INJACTEST_bTestEna;                                         */
/*  input boolean INJACTEST_bChgtActuator;                                    */
/*  input uint16 ActrTstInj_CumulTime;                                        */
/*  input uint16 ActrTstInj_IntTime;                                          */
/*  input uint16 Afts_tiTestInj_C;                                            */
/*  output st83 Inj_stActrTst;                                                */
/*  output uint16 ActrTstInj_TimeToInject;                                    */
/*  output boolean Inj_bPwrRlyCmd;                                            */
/*  output boolean Inj_bInjTstCmpl;                                           */
/*  output uint16 ActrTstInj_IntTime;                                         */
/*  output uint16 ActrTstInj_CumulTime;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidStateOff(void)
{
   uint16 u16LocalCumulTime;
   uint16 u16LocalIntTime;


   if (  (INJACTEST_bTestEna == 0)
      || (INJACTEST_bChgtActuator != 0))
   {
      Inj_stActrTst = INJ_ACTRTST_STOP;
      ActrTstInj_TimeToInject = 0;
      VEMS_vidSET(Inj_bPwrRlyCmd, 1);
      Inj_bInjTstCmpl = 0;
   }
   else
   {
      if (ActrTstInj_CumulTime <= 1)
      {
         Inj_stActrTst = INJ_ACTRTST_LDB_RECONF;
         ActrTstInj_TimeToInject = 0;
         VEMS_vidSET(Inj_bPwrRlyCmd, 1);
         Inj_bInjTstCmpl = 1;
      }
      else
      {
         if (ActrTstInj_IntTime <= (uint16)Inj_SampleTiFast_SC)
         {

            Inj_stActrTst = INJ_ACTRTST_ON;
            ActrTstInj_TimeToInject = Afts_tiTestInj_C;
         }
         else
         {
            /* during state INJ_ACTRTST_OFF */
            u16LocalIntTime =
               (uint16)(ActrTstInj_IntTime - (uint16)Inj_SampleTiFast_SC);
            ActrTstInj_IntTime = (uint16)MATHSRV_udtMIN(u16LocalIntTime, 50000);
         }
         u16LocalCumulTime = (uint16)(ActrTstInj_CumulTime - 1);
         ActrTstInj_CumulTime = (uint16)MATHSRV_udtMIN(u16LocalCumulTime, 5000);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidStateStop                                     */
/* !Description :  Treatment executed on state INJ_ACTRTST_STOP               */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ActrTstInj_TempoIdle_C;                                      */
/*  output st83 Inj_stActrTst;                                                */
/*  output uint16 ActrTstInj_TimeToInject;                                    */
/*  output boolean Inj_bPwrRlyCmd;                                            */
/*  output boolean Inj_bInjTstCmpl;                                           */
/*  output uint16 ActrTstInj_TempoIdle;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidStateStop(void)
{
   Inj_stActrTst = INJ_ACTRTST_IDLE;
   ActrTstInj_TimeToInject = 0;
   VEMS_vidSET(Inj_bPwrRlyCmd, 0);
   Inj_bInjTstCmpl = 0;
   /* exit of state INJ_ACTRTST_STOP */
   ActrTstInj_TempoIdle = (uint16)MATHSRV_udtMIN(ActrTstInj_TempoIdle_C, 3000);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidStateEnd                                      */
/* !Description :  Treatment executed on state INJ_ACTRTST_END                */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean INJACTEST_bTestEna;                                         */
/*  input uint16 ActrTstInj_TempoIdle_C;                                      */
/*  output st83 Inj_stActrTst;                                                */
/*  output uint16 ActrTstInj_TimeToInject;                                    */
/*  output boolean Inj_bPwrRlyCmd;                                            */
/*  output boolean Inj_bInjTstCmpl;                                           */
/*  output uint16 ActrTstInj_TempoIdle;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidStateEnd(void)
{
   if (INJACTEST_bTestEna != 0)
   {
      Inj_stActrTst = INJ_ACTRTST_IDLE;
      ActrTstInj_TimeToInject = 0;
      VEMS_vidSET(Inj_bPwrRlyCmd, 0);
      Inj_bInjTstCmpl = 0;
      /* exit of state INJ_ACTRTST_END */
      ActrTstInj_TempoIdle = (uint16)MATHSRV_udtMIN(ActrTstInj_TempoIdle_C,
                                                    3000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidStateLdbReconf                                */
/* !Description :  Treatment executed on state INJ_ACTRTST_LDB_RECONF         */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st83 Inj_stActrTst;                                                */
/*  output boolean Inj_bPwrRlyCmd;                                            */
/*  output boolean Inj_bInjTstCmpl;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidStateLdbReconf(void)
{
   Inj_stActrTst = INJ_ACTRTST_END;
   VEMS_vidSET(Inj_bPwrRlyCmd, 0);
   Inj_bInjTstCmpl = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJACTEST_vidStateFirstFull                                */
/* !Description :  Treatment executed on state INJ_FIRSTFULL                  */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean INJACTEST_bTestEna;                                         */
/*  input uint16 ActrTstInj_TempoIdle;                                        */
/*  input boolean FTPCtl_bMemFirstFillFu;                                     */
/*  input uint16 Inj_tiCntFirstFull;                                          */
/*  input st133 Inj_stFirstFull;                                              */
/*  input uint16 Inj_tiInjFirstFillFu_C;                                      */
/*  input uint16 Inj_tiDlyFirstFillFu_C;                                      */
/*  output st83 Inj_stActrTst;                                                */
/*  output uint16 ActrTstInj_TimeToInject;                                    */
/*  output boolean Inj_bPwrRlyCmd;                                            */
/*  output boolean Inj_bInjTstCmpl;                                           */
/*  output st133 Inj_stFirstFull;                                             */
/*  output uint16 Inj_tiCntFirstFull;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJACTEST_vidStateFirstFull(void)
{
   boolean bLocalFTPCtl_bMemFirstFillFu;
   uint16  u16LocalCumulTime;


   if (  (INJACTEST_bTestEna != 0)
      && (ActrTstInj_TempoIdle == 0))
   {
      Inj_stActrTst = INJ_ACTRTST_START;
      ActrTstInj_TimeToInject = 0;
      VEMS_vidSET(Inj_bPwrRlyCmd, 1);
      Inj_bInjTstCmpl = 0;
   }
   else
   {
      VEMS_vidGET(FTPCtl_bMemFirstFillFu, bLocalFTPCtl_bMemFirstFillFu);
      if (  (bLocalFTPCtl_bMemFirstFillFu != 0)
         || (Inj_tiCntFirstFull < 1))
      {
         Inj_stActrTst = INJ_ACTRTST_IDLE;
         ActrTstInj_TimeToInject = 0;
         VEMS_vidSET(Inj_bPwrRlyCmd, 0);
         Inj_bInjTstCmpl = 0;
      }
      else
      {
         switch (Inj_stFirstFull)
         {
            case INJ_DELAY_FIRSFTFULL:
               if (Inj_tiCntFirstFull < 2)
               {
                  Inj_stFirstFull = INJ_APPLIED_FIRSTFULL;
                  VEMS_vidSET(Inj_bPwrRlyCmd, 1);
                  if ( Inj_tiInjFirstFillFu_C <= 6553)
                  {
                     ActrTstInj_TimeToInject =
                        (uint16)(Inj_tiInjFirstFillFu_C * 10);
                  }
                  else
                  {
                     ActrTstInj_TimeToInject = 65535;
                  }
                  u16LocalCumulTime = Inj_tiInjFirstFillFu_C;
               }
               else
               {
                  u16LocalCumulTime = (uint16)(Inj_tiCntFirstFull - 1);
               }
               break;

            case INJ_APPLIED_FIRSTFULL:
               u16LocalCumulTime = (uint16)(Inj_tiCntFirstFull - 1);
               break;

            default:
               Inj_stFirstFull = INJ_DELAY_FIRSFTFULL;
               if ( Inj_tiDlyFirstFillFu_C < 1500)
               {
                  u16LocalCumulTime =  (uint16)(Inj_tiDlyFirstFillFu_C + 1);
               }
               else
               {
                  u16LocalCumulTime = 1500;
               }
               VEMS_vidSET(Inj_bPwrRlyCmd, 0);
               SWFAIL_vidSoftwareErrorHook();
               break;
         }
         Inj_tiCntFirstFull = (uint16)MATHSRV_udtMIN(u16LocalCumulTime, 1500);
      }
   }
}

/*----------------------------- end of file ----------------------------------*/
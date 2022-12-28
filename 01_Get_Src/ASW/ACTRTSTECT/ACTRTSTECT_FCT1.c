/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACTRTSTECT                                              */
/* !Description     : ACTRTSTECT component.                                   */
/*                                                                            */
/* !Module          : ACTRTSTECT                                              */
/* !Description     : Actuator test of Electronically Controlled Thermostat   */
/*                                                                            */
/* !File            : ACTRTSTECT_FCT1.C                                       */
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
/*   1 / ACTRTSTECT_vidInitOutput                                             */
/*   2 / ACTRTSTECT_vidECTTst                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 06916 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#060124                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/COFAN/ACTRTSTECT/ACTRTSTECT_FCT1$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   27 Mar 2012 $*/
/* $Author::   HHAMLAOU                               $$Date::   27 Mar 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACTRTSTECT.h"
#include "ACTRTSTECT_L.h"
#include "ACTRTSTECT_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTECT_vidInitOutput                                   */
/* !Description :  Outputs initialization.                                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Maissa.ABCHA                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean ThMgt_bECTActrTstInProgs;                                  */
/*  output boolean ThMgt_bECTTstCmpl;                                         */
/*  output uint8 ThMgt_rSpECTReqPosnActrTst;                                  */
/*  output st127 ThMgt_stECTActrTst;                                          */
/*  output boolean ACTRTSTECT_bTestEna;                                       */
/*  output uint16 ActrTstECT_CumulTime;                                       */
/*  output uint8 ActrTstECT_IntTime;                                          */
/*  output uint16 ActrTstECT_Tempo;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTECT_vidInitOutput(void)
{
   VEMS_vidSET(ThMgt_bECTActrTstInProgs, 0);
   VEMS_vidSET(ThMgt_bECTTstCmpl, 0);
   VEMS_vidSET(ThMgt_rSpECTReqPosnActrTst, 0);
   ThMgt_stECTActrTst = CTRLTHER_ACTRTEST_IDLE;
   ACTRTSTECT_bTestEna = 0;
   ActrTstECT_CumulTime = 0;
   ActrTstECT_IntTime = 0;
   ActrTstECT_Tempo = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTECT_vidECTTst                                       */
/* !Description :  This stateflow describes the specific test command.        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Maissa.ABCHA                                               */
/* !Trace_To    :  VEMS_E_11_06916_001.01                                     */
/*                 VEMS_E_11_06916_002.01                                     */
/*                 VEMS_E_11_06916_003.01                                     */
/*                 VEMS_E_11_06916_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input st127 ThMgt_stECTActrTst;                                           */
/*  input boolean ACTRTSTECT_bTestEna;                                        */
/*  input uint8 ThMgt_rSpECTActrTstPos1_C;                                    */
/*  input uint8 ActrTstECT_OnTime_C;                                          */
/*  input uint16 ActrTstECT_TotTime_C;                                        */
/*  input uint16 ActrTstECT_CumulTime;                                        */
/*  input uint16 ActrTstECT_Tempo_C;                                          */
/*  input uint8 ActrTstECT_IntTime;                                           */
/*  input uint8 ThMgt_rSpECTActrTstPos2_C;                                    */
/*  input uint8 ActrTstECT_OffTime_C;                                         */
/*  input uint16 ActrTstECT_Tempo;                                            */
/*  output boolean ACTRTSTECT_bTestEna;                                       */
/*  output boolean ThMgt_bECTActrTstInProgs;                                  */
/*  output st127 ThMgt_stECTActrTst;                                          */
/*  output uint8 ThMgt_rSpECTReqPosnActrTst;                                  */
/*  output uint8 ActrTstECT_IntTime;                                          */
/*  output uint16 ActrTstECT_CumulTime;                                       */
/*  output boolean ThMgt_bECTTstCmpl;                                         */
/*  output uint16 ActrTstECT_Tempo;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTECT_vidECTTst(void)
{
   boolean bLocalSrv_bActrTstEna;
   uint8   u8LocalActrTstECT_IntTime;
   uint8   u8LocalThMgt_rSpECTPosnActrTst;
   uint8   u8LocalCode_test_action;
   uint16  u16LocalActrTstECT_CumulTime;
   sint32  s32LocalActrTstECT_Tempo;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);

   if (  (u8LocalCode_test_action == CODE_TEST_CTRLTHER)
      && (bLocalSrv_bActrTstEna != 0))
   {
      ACTRTSTECT_bTestEna = 1;
   }
   else
   {
      ACTRTSTECT_bTestEna = 0;
   }

   switch (ThMgt_stECTActrTst)
   {
      case CTRLTHER_ACTRTEST_IDLE:
         if (ACTRTSTECT_bTestEna != 0)
         {
            VEMS_vidSET(ThMgt_bECTActrTstInProgs, 1);
            ThMgt_stECTActrTst = CTRLTHER_ACTRTEST_MAX;
            u8LocalThMgt_rSpECTPosnActrTst =
               (uint8)MATHSRV_udtMIN(ThMgt_rSpECTActrTstPos1_C, 200);
            VEMS_vidSET(ThMgt_rSpECTReqPosnActrTst,
                        u8LocalThMgt_rSpECTPosnActrTst);
            ActrTstECT_IntTime =
               (uint8)MATHSRV_udtMIN(ActrTstECT_OnTime_C, 250);
            ActrTstECT_CumulTime =
               (uint16)MATHSRV_udtMIN(ActrTstECT_TotTime_C, 500);
         }
         break;

      case CTRLTHER_ACTRTEST_MAX:
         if (ACTRTSTECT_bTestEna == 0)
         {
            ThMgt_stECTActrTst = CTRLTHER_ACTRTEST_IDLE;
            VEMS_vidSET(ThMgt_bECTTstCmpl, 0);
            VEMS_vidSET(ThMgt_rSpECTReqPosnActrTst, 0);
            VEMS_vidSET(ThMgt_bECTActrTstInProgs, 0);
         }
         else
         {
            if (ActrTstECT_CumulTime <= 1)
            {
               ThMgt_stECTActrTst = CTRLTHER_ACTRTEST_END;
               VEMS_vidSET(ThMgt_bECTTstCmpl, 1);
               VEMS_vidSET(ThMgt_rSpECTReqPosnActrTst, 0);
               VEMS_vidSET(ThMgt_bECTActrTstInProgs, 0);
               ActrTstECT_Tempo =
                  (uint16)MATHSRV_udtMIN(ActrTstECT_Tempo_C, 500);
            }
            else
            {
               if (ActrTstECT_IntTime <= 1)
               {
                  ThMgt_stECTActrTst = CTRLTHER_ACTRTEST_MIN;
                  u8LocalThMgt_rSpECTPosnActrTst =
                     (uint8)MATHSRV_udtMIN(ThMgt_rSpECTActrTstPos2_C, 200);
                  VEMS_vidSET(ThMgt_rSpECTReqPosnActrTst,
                              u8LocalThMgt_rSpECTPosnActrTst);
                  ActrTstECT_IntTime =
                     (uint8)MATHSRV_udtMIN(ActrTstECT_OffTime_C, 250);
                  u16LocalActrTstECT_CumulTime =
                     (uint16)(ActrTstECT_CumulTime - 1);
                  ActrTstECT_CumulTime =
                     (uint16)MATHSRV_udtMIN(u16LocalActrTstECT_CumulTime, 500);
               }
               else
               {
                  u16LocalActrTstECT_CumulTime =
                   (uint16)(ActrTstECT_CumulTime - 1);
                  ActrTstECT_CumulTime =
                   (uint16)MATHSRV_udtMIN(u16LocalActrTstECT_CumulTime, 500);
                  u8LocalActrTstECT_IntTime = (uint8)(ActrTstECT_IntTime - 1);
                  ActrTstECT_IntTime =
                   (uint8)MATHSRV_udtMIN(u8LocalActrTstECT_IntTime, 250);
               }
            }
         }
         break;

      case CTRLTHER_ACTRTEST_MIN:
         if (ACTRTSTECT_bTestEna == 0)
         {
            ThMgt_stECTActrTst = CTRLTHER_ACTRTEST_IDLE;
            VEMS_vidSET(ThMgt_bECTTstCmpl, 0);
            VEMS_vidSET(ThMgt_rSpECTReqPosnActrTst, 0);
            VEMS_vidSET(ThMgt_bECTActrTstInProgs, 0);
         }
         else
         {
            if (ActrTstECT_CumulTime <= 1)
            {
               ThMgt_stECTActrTst = CTRLTHER_ACTRTEST_END;
               VEMS_vidSET(ThMgt_bECTTstCmpl, 1);
               VEMS_vidSET(ThMgt_rSpECTReqPosnActrTst, 0);
               VEMS_vidSET(ThMgt_bECTActrTstInProgs, 0);
               ActrTstECT_Tempo =
                   (uint16)MATHSRV_udtMIN(ActrTstECT_Tempo_C, 500);
            }
            else
            {
               if (ActrTstECT_IntTime <= 1)
               {
                  ThMgt_stECTActrTst = CTRLTHER_ACTRTEST_MAX;
                  u8LocalThMgt_rSpECTPosnActrTst =
                     (uint8)MATHSRV_udtMIN(ThMgt_rSpECTActrTstPos1_C, 200);
                  VEMS_vidSET(ThMgt_rSpECTReqPosnActrTst,
                              u8LocalThMgt_rSpECTPosnActrTst);
                  ActrTstECT_IntTime =
                     (uint8)MATHSRV_udtMIN(ActrTstECT_OnTime_C, 250);
                  u16LocalActrTstECT_CumulTime =
                     (uint16)(ActrTstECT_CumulTime - 1);
                  ActrTstECT_CumulTime =
                     (uint16)MATHSRV_udtMIN(u16LocalActrTstECT_CumulTime, 500);
               }
               else
               {
                  u16LocalActrTstECT_CumulTime =
                     (uint16)(ActrTstECT_CumulTime - 1);
                  ActrTstECT_CumulTime =
                     (uint16)MATHSRV_udtMIN(u16LocalActrTstECT_CumulTime, 500);
                  u8LocalActrTstECT_IntTime = (uint8)(ActrTstECT_IntTime - 1);
                  ActrTstECT_IntTime =
                     (uint8)MATHSRV_udtMIN(u8LocalActrTstECT_IntTime, 250);
               }
            }
         }
         break;

      case CTRLTHER_ACTRTEST_END:
         if (  (ACTRTSTECT_bTestEna != 0)
            && (ActrTstECT_Tempo <= 0))
         {
            ThMgt_stECTActrTst = CTRLTHER_ACTRTEST_IDLE;
            VEMS_vidSET(ThMgt_bECTTstCmpl, 0);
            VEMS_vidSET(ThMgt_rSpECTReqPosnActrTst, 0);
            VEMS_vidSET(ThMgt_bECTActrTstInProgs, 0);
         }
         else
         {
            s32LocalActrTstECT_Tempo = (sint32)(ActrTstECT_Tempo - 1);
            ActrTstECT_Tempo =
               (uint16)MATHSRV_udtCLAMP(s32LocalActrTstECT_Tempo, 0, 500);
         }
         break;

      default:
         ThMgt_stECTActrTst = CTRLTHER_ACTRTEST_IDLE;
         VEMS_vidSET(ThMgt_bECTTstCmpl, 0);
         VEMS_vidSET(ThMgt_rSpECTReqPosnActrTst, 0);
         VEMS_vidSET(ThMgt_bECTActrTstInProgs, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;

   }
}

/*---------------------------- end of file -----------------------------------*/
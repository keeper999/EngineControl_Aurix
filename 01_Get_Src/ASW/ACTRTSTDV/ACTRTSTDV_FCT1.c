/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACTRTSTDV                                               */
/* !Description     : ACTRTSTDV Component                                     */
/*                                                                            */
/* !Module          : ACTRTSTDV                                               */
/* !Description     : Dump Valve Actuator Test                                */
/*                                                                            */
/* !File            : ACTRTSTDV_FCT1.C                                        */
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
/*   1 / ACTRTSTDV_vidInitOutput                                              */
/*   2 / ACTRTSTDV_vidDVTST                                                   */
/*                                                                            */
/* !Reference   : V02 NT 11 02175 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACTRTSTDV.h"
#include "ACTRTSTDV_L.h"
#include "ACTRTSTDV_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTDV_vidInitOutput                                    */
/* !Description :  Fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean DmpVlv_bActrTstCmpl;                                       */
/*  output boolean DmpVlv_bActrTstInProgs;                                    */
/*  output uint16 DmpVlv_rSpReqPosnActrTst;                                   */
/*  output st131 DmpVlv_stActrTst;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTDV_vidInitOutput(void)
{
   VEMS_vidSET(DmpVlv_bActrTstCmpl, 0);
   VEMS_vidSET(DmpVlv_bActrTstInProgs, 0);
   VEMS_vidSET(DmpVlv_rSpReqPosnActrTst, 0);
   DmpVlv_stActrTst = DMPVLV_ACTRTEST_IDLE;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTDV_vidDVTST                                         */
/* !Description :  During a test request (conditions met and actuator code    */
/*                 matches), the actuator is commanded alternatively by       */
/*                 DmpVlv_rSpActrTstPos1_C for a time ActrTstDV_OnTime_C, and */
/*                 by DmpVlv_rSpActrTstPos2_C for ActrTstDV_OffTime_C.        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_E_11_02175_001.01                                     */
/*                 VEMS_E_11_02175_002.01                                     */
/*                 VEMS_E_11_02175_003.01                                     */
/*                 VEMS_E_11_02175_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input uint8 Code_test_action;                                             */
/*  input st131 DmpVlv_stActrTst;                                             */
/*  input uint16 DmpVlv_rSpActrTstPos1_C;                                     */
/*  input uint16 ActrTstDV_OnTime_C;                                          */
/*  input uint16 ActrTstDV_IntTime;                                           */
/*  input uint16 DmpVlv_rSpActrTstPos2_C;                                     */
/*  input uint16 ActrTstDV_OffTime_C;                                         */
/*  input uint16 ActrTstDV_Tempo_C;                                           */
/*  input uint16 ActrTstDV_Tempo;                                             */
/*  output st131 DmpVlv_stActrTst;                                            */
/*  output boolean DmpVlv_bActrTstInProgs;                                    */
/*  output uint16 DmpVlv_rSpReqPosnActrTst;                                   */
/*  output uint16 ActrTstDV_IntTime;                                          */
/*  output boolean DmpVlv_bActrTstCmpl;                                       */
/*  output uint16 ActrTstDV_Tempo;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTDV_vidDVTST(void)
{
   boolean bLocalSrv_bActrTstEna;
   boolean bLocalTestEna;
   uint8   u8LocalCode_test_action;
   uint16  u16LocalrSpReqPosnActrTst;
   sint32  s32LocalResult;


   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);

   if (  (bLocalSrv_bActrTstEna != 0)
      && (u8LocalCode_test_action == CODE_TEST_DUMPVALVE))
   {
      bLocalTestEna = 1;
   }
   else
   {
      bLocalTestEna = 0;
   }

   switch(DmpVlv_stActrTst)
   {
      case DMPVLV_ACTRTEST_IDLE:
         /*DMPVLV_ACTRTEST_IDLE ===> DMPVLV_ACTRTEST_P1*/
         if (bLocalTestEna != 0)
         {
            DmpVlv_stActrTst = DMPVLV_ACTRTEST_P1;
            VEMS_vidSET(DmpVlv_bActrTstInProgs, 1);
            u16LocalrSpReqPosnActrTst =
               (uint16)MATHSRV_udtMIN(DmpVlv_rSpActrTstPos1_C, 32768);
            VEMS_vidSET(DmpVlv_rSpReqPosnActrTst, u16LocalrSpReqPosnActrTst);
            ActrTstDV_IntTime =
               (uint16)MATHSRV_udtMIN(ActrTstDV_OnTime_C, 2500);
         }
         break;

      case DMPVLV_ACTRTEST_P1:
         /*DMPVLV_ACTRTEST_P1 ===> DMPVLV_ACTRTEST_IDLE*/
         if (bLocalTestEna == 0)
         {
            DmpVlv_stActrTst = DMPVLV_ACTRTEST_IDLE;
            VEMS_vidSET(DmpVlv_bActrTstCmpl, 0);
            VEMS_vidSET(DmpVlv_bActrTstInProgs, 0);
            VEMS_vidSET(DmpVlv_rSpReqPosnActrTst, 0);
         }
         else
         {
            /*DMPVLV_ACTRTEST_P1 ===> DMPVLV_ACTRTEST_P2*/
            if (ActrTstDV_IntTime <= 1)
            {
               DmpVlv_stActrTst = DMPVLV_ACTRTEST_P2;
               u16LocalrSpReqPosnActrTst =
                  (uint16)MATHSRV_udtMIN(DmpVlv_rSpActrTstPos2_C, 32768);
               VEMS_vidSET(DmpVlv_rSpReqPosnActrTst, u16LocalrSpReqPosnActrTst);
               ActrTstDV_IntTime =
                  (uint16)MATHSRV_udtMIN(ActrTstDV_OffTime_C, 2500);
            }
            else
            {
               /*during of DMPVLV_ACTRTEST_P1*/
               ActrTstDV_IntTime = (uint16)(ActrTstDV_IntTime - 1);
            }
         }
         break;

      case DMPVLV_ACTRTEST_P2:
         /*DMPVLV_ACTRTEST_P2 ===> DMPVLV_ACTRTEST_IDLE*/
         if (bLocalTestEna == 0)
         {
            DmpVlv_stActrTst = DMPVLV_ACTRTEST_IDLE;
            VEMS_vidSET(DmpVlv_bActrTstCmpl, 0);
            VEMS_vidSET(DmpVlv_bActrTstInProgs, 0);
            VEMS_vidSET(DmpVlv_rSpReqPosnActrTst, 0);
         }
         else
         {
            /*DMPVLV_ACTRTEST_P2 ===> DMPVLV_ACTRTEST_END*/
            if (ActrTstDV_IntTime <= 1)
            {
               DmpVlv_stActrTst = DMPVLV_ACTRTEST_END;
               VEMS_vidSET(DmpVlv_bActrTstCmpl, 1);
               VEMS_vidSET(DmpVlv_bActrTstInProgs, 0);
               VEMS_vidSET(DmpVlv_rSpReqPosnActrTst, 0);
               ActrTstDV_Tempo =
                  (uint16)MATHSRV_udtMIN(ActrTstDV_Tempo_C, 5000);
            }
            else
            {
               /*during of DMPVLV_ACTRTEST_P2*/
               ActrTstDV_IntTime = (uint16)(ActrTstDV_IntTime - 1);
            }
         }
         break;

      case DMPVLV_ACTRTEST_END:
         /*DMPVLV_ACTRTEST_END ===> DMPVLV_ACTRTEST_IDLE*/
         if (  (bLocalTestEna != 0)
            && (ActrTstDV_Tempo <= 0))
         {
            DmpVlv_stActrTst = DMPVLV_ACTRTEST_IDLE;
            VEMS_vidSET(DmpVlv_bActrTstCmpl, 0);
            VEMS_vidSET(DmpVlv_bActrTstInProgs, 0);
            VEMS_vidSET(DmpVlv_rSpReqPosnActrTst, 0);
         }
         else
         {
            /*during of DMPVLV_ACTRTEST_END*/
            s32LocalResult = (sint32)(ActrTstDV_Tempo - 1);
            ActrTstDV_Tempo = (uint16)MATHSRV_udtMAX(s32LocalResult, 0);
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         DmpVlv_stActrTst = DMPVLV_ACTRTEST_IDLE;
         VEMS_vidSET(DmpVlv_bActrTstCmpl, 0);
         VEMS_vidSET(DmpVlv_bActrTstInProgs, 0);
         VEMS_vidSET(DmpVlv_rSpReqPosnActrTst, 0);
         break;
   }
}
/*-------------------------------- End of file -------------------------------*/
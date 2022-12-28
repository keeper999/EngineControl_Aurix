/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RLYACTEST                                               */
/* !Description     : RLYACTEST component.                                    */
/*                                                                            */
/* !Module          : RLYACTEST                                               */
/* !Description     : TEST ACTIONNEUR DU RELAIS DE PUISSANCE.                 */
/*                                                                            */
/* !File            : RLYACTEST_FCT1.C                                        */
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
/*   1 / RLYACTEST_vidInitOutput                                              */
/*   2 / RLYACTEST_vidTimeCmdPwrRly                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 00872 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/RLY/RLYACTEST/RLYACTEST_FCT1.C_v$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   19 Oct 2011 $*/
/* $Author::   HHAMLAOU                               $$Date::   19 Oct 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "RLYACTEST.h"
#include "RLYACTEST_l.h"
#include "RLYACTEST_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYACTEST_vidInitOutput                                    */
/* !Description :  Initialisation des tests actionneurs  du relais de         */
/*                 puissance.                                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.SARHAN                                                   */
/* !Trace_To    :  VEMS_R_09_00872_002.01                                     */
/*                 VEMS_R_09_00872_003.01                                     */
/*                 VEMS_R_09_00872_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st52 Rly_stActrTst;                                                */
/*  output boolean Rly_bActrTstCmd;                                           */
/*  output boolean Rly_bActrTstCmpl;                                          */
/*  output boolean Rly_bTstInProgress;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYACTEST_vidInitOutput(void)
{
   Rly_stActrTst = RLY_ACTRTEST_IDLE;
   VEMS_vidSET(Rly_bActrTstCmd, 0);
   VEMS_vidSET(Rly_bActrTstCmpl, 0);
   VEMS_vidSET(Rly_bTstInProgress, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYACTEST_vidTimeCmdPwrRly                                 */
/* !Description :  Fonction decrivant le déroulement des tests actionneurs  du*/
/*                 relais de puissance.                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.SARHAN                                                   */
/* !Trace_To    :  VEMS_R_09_00872_002.01                                     */
/*                 VEMS_R_09_00872_003.01                                     */
/*                 VEMS_R_09_00872_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input uint8 Code_test_action;                                             */
/*  input st52 Rly_stActrTst;                                                 */
/*  input uint8 TpsOn_ActrTstPwrRly;                                          */
/*  input uint16 TpsTot_ActrTstPwrRly;                                        */
/*  input uint8 ActrTstRly_CumulTime;                                         */
/*  input uint8 ActrTstRly_Tempo_C;                                           */
/*  input uint8 ActrTstRly_IntTime;                                           */
/*  input uint8 TpsOff_ActrTstPwrRly;                                         */
/*  input uint8 ActrTstRly_Tempo;                                             */
/*  output st52 Rly_stActrTst;                                                */
/*  output boolean Rly_bActrTstCmd;                                           */
/*  output boolean Rly_bTstInProgress;                                        */
/*  output uint8 ActrTstRly_IntTime;                                          */
/*  output uint8 ActrTstRly_CumulTime;                                        */
/*  output boolean Rly_bActrTstCmpl;                                          */
/*  output uint8 ActrTstRly_Tempo;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYACTEST_vidTimeCmdPwrRly(void)
{
   boolean bLocalTestEna;
   boolean bLocalSrv_bActrTstEna;
   uint8   u8LocalCumulTimeDec;
   uint8   u8LocalIntTimeDec;
   uint8   u8LocalCode_test_action;
   uint8   u8LocalActrTstRly_Tempo;


   u8LocalIntTimeDec = 0;
   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   if (  (u8LocalCode_test_action == CODE_TEST_RELAIS_PUISSANCE)
      && (bLocalSrv_bActrTstEna != 0))
   {
      bLocalTestEna = 1;
   }
   else
   {
      bLocalTestEna = 0;
   }
   switch (Rly_stActrTst)
   {
      case RLY_ACTRTEST_IDLE:
         if (bLocalTestEna != 0)
         {
            Rly_stActrTst = RLY_ACTRTEST_ON ;
            VEMS_vidSET(Rly_bActrTstCmd, 1);
            VEMS_vidSET(Rly_bTstInProgress, 1);
            ActrTstRly_IntTime = (uint8)MATHSRV_udtMIN(TpsOn_ActrTstPwrRly,
                                                       250);
            ActrTstRly_CumulTime = (uint8)MATHSRV_udtMIN(TpsTot_ActrTstPwrRly,
                                                         250);
         }
         break;

      case RLY_ACTRTEST_ON:
         if (bLocalTestEna == 0)
         {
            Rly_stActrTst = RLY_ACTRTEST_IDLE;
            VEMS_vidSET(Rly_bActrTstCmd, 0);
            VEMS_vidSET(Rly_bTstInProgress, 0);
            VEMS_vidSET(Rly_bActrTstCmpl, 0);
         }
         else
         {
            if (ActrTstRly_CumulTime <= 1)
            {
               Rly_stActrTst = RLY_ACTRTEST_END ;
               VEMS_vidSET(Rly_bActrTstCmpl, 1);
               VEMS_vidSET(Rly_bTstInProgress, 0);
               VEMS_vidSET(Rly_bActrTstCmd, 0);
               ActrTstRly_Tempo = (uint8)MATHSRV_udtMIN(ActrTstRly_Tempo_C,
                                                        250);
            }
            else
            {
               if (ActrTstRly_IntTime <= 1)
               {
                  Rly_stActrTst = RLY_ACTRTEST_OFF;
                  VEMS_vidSET(Rly_bActrTstCmd, 0);
                  ActrTstRly_IntTime =
                     (uint8)MATHSRV_udtMIN(TpsOff_ActrTstPwrRly, 250);
               }
               else
               {
                  u8LocalIntTimeDec = (uint8)(ActrTstRly_IntTime - 1);
                  ActrTstRly_IntTime = (uint8)MATHSRV_udtMIN(u8LocalIntTimeDec,
                                                             250);
               }
               u8LocalCumulTimeDec = (uint8)(ActrTstRly_CumulTime - 1);
               ActrTstRly_CumulTime = (uint8)MATHSRV_udtMIN(u8LocalCumulTimeDec,
                                                            250);
            }
         }
         break;

      case RLY_ACTRTEST_OFF:
         if (bLocalTestEna == 0)
         {
            Rly_stActrTst = RLY_ACTRTEST_IDLE;
            VEMS_vidSET(Rly_bActrTstCmd, 0);
            VEMS_vidSET(Rly_bTstInProgress, 0);
            VEMS_vidSET(Rly_bActrTstCmpl, 0);
         }
         else
         {
            if (ActrTstRly_CumulTime <= 1)
            {
               Rly_stActrTst = RLY_ACTRTEST_END ;
               VEMS_vidSET(Rly_bActrTstCmpl, 1);
               VEMS_vidSET(Rly_bTstInProgress, 0);
               VEMS_vidSET(Rly_bActrTstCmd, 0);
               ActrTstRly_Tempo = (uint8)MATHSRV_udtMIN(ActrTstRly_Tempo_C,
                                                        250);
            }
            else
            {
               if (ActrTstRly_IntTime > 0)
               {
                  u8LocalIntTimeDec = (uint8)(ActrTstRly_IntTime - 1);
               }
               ActrTstRly_IntTime = (uint8)MATHSRV_udtMIN(u8LocalIntTimeDec,
                                                          250);
               u8LocalCumulTimeDec = (uint8)(ActrTstRly_CumulTime - 1);
               ActrTstRly_CumulTime = (uint8)MATHSRV_udtMIN(u8LocalCumulTimeDec,
                                                            250);
            }
         }
         break;

      case RLY_ACTRTEST_END:
         if (  (bLocalTestEna != 0)
            && (ActrTstRly_Tempo == 0))
         {
            Rly_stActrTst = RLY_ACTRTEST_IDLE;
            VEMS_vidSET(Rly_bActrTstCmd, 0);
            VEMS_vidSET(Rly_bTstInProgress, 0);
            VEMS_vidSET(Rly_bActrTstCmpl, 0);
         }
         else
         {
            if (ActrTstRly_Tempo > 0)
            {
               u8LocalActrTstRly_Tempo = (uint8)(ActrTstRly_Tempo - 1);
               ActrTstRly_Tempo = (uint8)MATHSRV_udtMIN(u8LocalActrTstRly_Tempo,
                                                        250);
            }
         }
         break;

      default:
         Rly_stActrTst = RLY_ACTRTEST_IDLE;
         VEMS_vidSET(Rly_bActrTstCmd, 0);
         VEMS_vidSET(Rly_bTstInProgress, 0);
         VEMS_vidSET(Rly_bActrTstCmpl, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;

   }
}

/*---------------------------- end of file -----------------------------------*/
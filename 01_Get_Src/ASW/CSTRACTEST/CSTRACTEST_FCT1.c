/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRACTEST                                              */
/* !Description     : CSTRACTEST component.                                   */
/*                                                                            */
/* !Module          : CSTRACTEST                                              */
/* !Description     : TEST ACTIONNEUR DE PURGE CANISTER.                      */
/*                                                                            */
/* !File            : CSTRACTEST_FCT1.C                                       */
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
/*   1 / CSTRACTEST_vidInitOutput                                             */
/*   2 / CSTRACTEST_vidCmdState                                               */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CSTR/CSTRACTEST/CSTRACTEST_FCT1.C_$*/
/* $Revision::   1.2      $$Author::   wbouach        $$Date::   15 Dec 2009 $*/
/* $Author::   wbouach                                $$Date::   15 Dec 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CSTRACTEST.h"
#include "CSTRACTEST_l.h"
#include "CSTRACTEST_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Initialisation des tests actionneurs  de purge canister     */
/* !Number      : FCT1.1                                                      */
/* !Reference   : V02 NT 09 00924 / 03                                        */
/* !Requirement : VEMS_R_09_00924_001.01                                      */
/*                VEMS_R_09_00924_002.01                                      */
/*                VEMS_R_09_00924_003.01                                      */
/*                VEMS_R_09_00924_004.01                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*                                                                            */
/*   input bool CSTR_ACTRTEST_IDLE;                                           */
/*                                                                            */
/*   output st54 Cstr_stActrTst;                                              */
/*   output boolean Cstr_bPwrRlyCmd;                                          */
/*   output boolean Cstr_bPurgTstCmpl;                                        */
/*   output uint8 Cstr_rSpPosnActrTst;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : M.BOUKADIDA                                                 */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRACTEST_vidInitOutput(void)
{
   Cstr_stActrTst = CSTR_ACTRTEST_IDLE;
   VEMS_vidSET(Cstr_bPwrRlyCmd, 0);
   VEMS_vidSET(Cstr_bPurgTstCmpl, 0);
   VEMS_vidSET(Cstr_rSpPosnActrTst, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Fonction decrivant le déroulement des tests actionneurs de  */
/*                purge canister.                                             */
/* !Number      : FCT1.2                                                      */
/* !Reference   : V02 NT 09 00924 / 03                                        */
/* !Requirement : VEMS_R_09_00924_001.01                                      */
/*                VEMS_R_09_00924_002.01                                      */
/*                VEMS_R_09_00924_003.01                                      */
/*                VEMS_R_09_00924_004.01                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   extf argret void SWFAIL_vidSoftwareErrorHook();                          */
/*                                                                            */
/*   input uint8 Code_test_action;                                            */
/*   input boolean Srv_bActrTstEna;                                           */
/*   input st54 Cstr_stActrTst;                                               */
/*   input bool CSTR_ACTRTEST_MAX;                                            */
/*   input uint8 ActrTstCstr_OnTime;                                          */
/*   input uint16 ActrTstCstr_TotTime;                                        */
/*   input bool CSTR_ACTRTEST_IDLE;                                           */
/*   input uint16 ActrTstCstr_CumulTime;                                      */
/*   input bool CSTR_ACTRTEST_END;                                            */
/*   input uint16 ActrTstCstr_Tempo_C;                                        */
/*   input uint8 ActrTstCstr_IntTime;                                         */
/*   input bool CSTR_ACTRTEST_MIN;                                            */
/*   input uint8 ActrTstCstr_OffTime;                                         */
/*   input uint16 ActrTstCstr_Tempo;                                          */
/*                                                                            */
/*   output st54 Cstr_stActrTst;                                              */
/*   output boolean Cstr_bPwrRlyCmd;                                          */
/*   output uint8 Cstr_rSpPosnActrTst;                                        */
/*   output uint8 ActrTstCstr_IntTime;                                        */
/*   output uint16 ActrTstCstr_CumulTime;                                     */
/*   output boolean Cstr_bPurgTstCmpl;                                        */
/*   output uint16 ActrTstCstr_Tempo;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : M.BOUKADIDA                                                 */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRACTEST_vidCmdState(void)
{
   boolean bLocalTestEna;
   boolean bLocalSrv_bActrTstEna;
   uint8   u8LocalIntTimeDec;
   uint8   u8LocalCode_test_action;
   uint16  u16LocalCumulTimeDec;
   uint16  u16LocalActrTstCstr_Tempo;

   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);
   if (  (u8LocalCode_test_action == CODE_TEST_PURGE)
      && (bLocalSrv_bActrTstEna != 0))
   {
      bLocalTestEna = 1;
   }
   else
   {
      bLocalTestEna = 0;
   }
   switch (Cstr_stActrTst)
   {
      case CSTR_ACTRTEST_IDLE:
         if (bLocalTestEna != 0)
         {
            Cstr_stActrTst = CSTR_ACTRTEST_MAX ;
            VEMS_vidSET(Cstr_bPwrRlyCmd, 1);
            VEMS_vidSET(Cstr_rSpPosnActrTst, 255);
            ActrTstCstr_IntTime =
               (uint8)MATHSRV_udtMIN(ActrTstCstr_OnTime, 250);
            ActrTstCstr_CumulTime = (uint16)MATHSRV_udtMIN(ActrTstCstr_TotTime,
                                                           500);
         }
         break;

      case CSTR_ACTRTEST_MIN:
         if (bLocalTestEna == 0)
         {
            Cstr_stActrTst = CSTR_ACTRTEST_IDLE;
            VEMS_vidSET(Cstr_bPwrRlyCmd, 0);
            VEMS_vidSET(Cstr_rSpPosnActrTst, 0);
            VEMS_vidSET(Cstr_bPurgTstCmpl, 0);
         }
         else
         {
            if (ActrTstCstr_CumulTime <= 1)
            {
               Cstr_stActrTst = CSTR_ACTRTEST_END ;
               VEMS_vidSET(Cstr_bPurgTstCmpl, 1);
               VEMS_vidSET(Cstr_rSpPosnActrTst, 0);
               VEMS_vidSET(Cstr_bPwrRlyCmd, 0);
               ActrTstCstr_Tempo = (uint16)MATHSRV_udtMIN(ActrTstCstr_Tempo_C,
                                                          500);
            }
            else
            {
               if (ActrTstCstr_IntTime <= 1)
               {
                  Cstr_stActrTst = CSTR_ACTRTEST_MAX;
                  VEMS_vidSET(Cstr_rSpPosnActrTst, 255);
                  ActrTstCstr_IntTime =
                     (uint8)MATHSRV_udtMIN(ActrTstCstr_OnTime, 250);
               }
               else
               {
                  u8LocalIntTimeDec = (uint8)(ActrTstCstr_IntTime - 1);
                  ActrTstCstr_IntTime =
                     (uint8)MATHSRV_udtMIN(u8LocalIntTimeDec, 250);
               }
               u16LocalCumulTimeDec = (uint16)(ActrTstCstr_CumulTime - 1);
               ActrTstCstr_CumulTime =
                  (uint16)MATHSRV_udtMIN(u16LocalCumulTimeDec, 500);
            }
         }
         break;

      case CSTR_ACTRTEST_MAX:
         if (bLocalTestEna == 0)
         {
            Cstr_stActrTst = CSTR_ACTRTEST_IDLE;
            VEMS_vidSET(Cstr_bPwrRlyCmd, 0);
            VEMS_vidSET(Cstr_rSpPosnActrTst, 0);
            VEMS_vidSET(Cstr_bPurgTstCmpl, 0);
         }
         else
         {
            if (ActrTstCstr_CumulTime <= 1)
            {
               Cstr_stActrTst = CSTR_ACTRTEST_END ;
               VEMS_vidSET(Cstr_bPurgTstCmpl, 1);
               VEMS_vidSET(Cstr_rSpPosnActrTst, 0);
               VEMS_vidSET(Cstr_bPwrRlyCmd, 0);
               ActrTstCstr_Tempo = (uint16)MATHSRV_udtMIN(ActrTstCstr_Tempo_C,
                                                          500);
            }
            else
            {
               if (ActrTstCstr_IntTime <= 1)
               {
                  Cstr_stActrTst = CSTR_ACTRTEST_MIN ;
                  VEMS_vidSET(Cstr_rSpPosnActrTst, 0);
                  ActrTstCstr_IntTime =
                     (uint8)MATHSRV_udtMIN(ActrTstCstr_OffTime, 250);
               }
               else
               {
                  u8LocalIntTimeDec = (uint8)(ActrTstCstr_IntTime - 1);
                  ActrTstCstr_IntTime = (uint8)MATHSRV_udtMIN(u8LocalIntTimeDec,
                                                              250);
               }
               u16LocalCumulTimeDec = (uint16)(ActrTstCstr_CumulTime - 1);
               ActrTstCstr_CumulTime =
                  (uint16)MATHSRV_udtMIN(u16LocalCumulTimeDec, 500);
            }
         }
         break;

      case CSTR_ACTRTEST_END:
         if (  (bLocalTestEna != 0)
            && (ActrTstCstr_Tempo == 0))
         {
            Cstr_stActrTst = CSTR_ACTRTEST_IDLE;
            VEMS_vidSET(Cstr_bPwrRlyCmd, 0);
            VEMS_vidSET(Cstr_rSpPosnActrTst, 0);
            VEMS_vidSET(Cstr_bPurgTstCmpl, 0);
         }
         else
         {
            if (ActrTstCstr_Tempo > 0)
            {
               u16LocalActrTstCstr_Tempo = (uint16)(ActrTstCstr_Tempo - 1);
               ActrTstCstr_Tempo =
                  (uint16)MATHSRV_udtMIN(u16LocalActrTstCstr_Tempo, 500);
            }
         }
         break;

      default:
         Cstr_stActrTst = CSTR_ACTRTEST_IDLE;
         VEMS_vidSET(Cstr_bPwrRlyCmd, 0);
         VEMS_vidSET(Cstr_rSpPosnActrTst, 0);
         VEMS_vidSET(Cstr_bPurgTstCmpl, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;

   }
}

/*---------------------------- end of file -----------------------------------*/


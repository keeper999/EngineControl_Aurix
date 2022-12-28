/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACTRTSTMEAP                                             */
/* !Description     : ACTRTSTMEAP Component                                   */
/*                                                                            */
/* !Module          : ACTRTSTMEAP                                             */
/* !Description     : ACTUATOR TEST OF DRIVEN FLAP                            */
/*                                                                            */
/* !File            : ACTRTSTMEAP_FCT1.C                                      */
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
/*   1 / ACTRTSTMEAP_vidInitOutput                                            */
/*   2 / ACTRTSTMEAP_vidRstDft                                                */
/*   3 / ACTRTSTMEAP_vidMEAPTst                                               */
/*   4 / ACTRTSTMEAP_vidEntryIdleState                                        */
/*                                                                            */
/* !Reference   : V02 NT 12 05332 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ACTRTSTMEAP/ACTRTSTMEAP_FCT1.C_v$*/
/* $Revision::   1.1      $$Author::   mbenfrad       $$Date::   21 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   21 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACTRTSTMEAP.h"
#include "ACTRTSTMEAP_L.h"
#include "ACTRTSTMEAP_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTMEAP_vidInitOutput                                  */
/* !Description :  Initialization module outputs                              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ThMgt_stPosnFSFReq;                                           */
/*  output st129 Meap_stActrTst;                                              */
/*  output boolean Afts_bAcvFSF;                                              */
/*  output boolean Meap_bActrTstCmpl;                                         */
/*  output boolean Meap_bActrTstInProgs;                                      */
/*  output uint8 ThMgt_stPosnFSF;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTMEAP_vidInitOutput(void)
{
   uint8 u8LocalThMgt_stPosnFSFReq;
   uint8 u8LocalThMgt_stPosnFSF;


   Meap_stActrTst = MEAP_ACTRTEST_IDLE;
   VEMS_vidSET(Afts_bAcvFSF, 0);
   VEMS_vidSET(Meap_bActrTstCmpl, 0);
   VEMS_vidSET(Meap_bActrTstInProgs, 0);
   VEMS_vidGET(ThMgt_stPosnFSFReq, u8LocalThMgt_stPosnFSFReq);
   u8LocalThMgt_stPosnFSF =
      (uint8)MATHSRV_udtMIN(u8LocalThMgt_stPosnFSFReq, 3);
   VEMS_vidSET(ThMgt_stPosnFSF, u8LocalThMgt_stPosnFSF);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTMEAP_vidRstDft                                      */
/* !Description :  At the reset, default booleans must be reseted.            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Meap_bFlapStayOp;                                          */
/*  output boolean Meap_bFlapFaild;                                           */
/*  output boolean Meap_bFlapBlockOp;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTMEAP_vidRstDft(void)
{
   VEMS_vidSET(Meap_bFlapStayOp, 0);
   VEMS_vidSET(Meap_bFlapFaild, 0);
   VEMS_vidSET(Meap_bFlapBlockOp, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTMEAP_vidMEAPTst                                     */
/* !Description :  During a test request (conditions met and actuator code    */
/*                 matches), several tests are made                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_12_05332_001.01                                     */
/*                 VEMS_R_12_05332_002.01                                     */
/*                 VEMS_R_12_05332_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACTRTSTMEAP_vidEntryIdleState();                         */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input uint8 Code_test_action;                                             */
/*  input uint8 ShdFlap_stPosn;                                               */
/*  input st129 Meap_stActrTst;                                               */
/*  input uint8 ActrTstMeap_tiDlyOpen_C;                                      */
/*  input uint8 ThMgt_stPosnFSFReq;                                           */
/*  input uint8 ActrTstMeap_tiDlyClos_C;                                      */
/*  input uint8 ActrTstMeap_OpenTime;                                         */
/*  input uint8 ActrTstMeap_Tempo_C;                                          */
/*  input uint8 ActrTstMeap_ClosTime;                                         */
/*  input uint8 ActrTstMeap_Tempo;                                            */
/*  output boolean Meap_bActrTstInProgs;                                      */
/*  output boolean Afts_bAcvFSF;                                              */
/*  output boolean Meap_bFlapBlockOp;                                         */
/*  output boolean Meap_bFlapFaild;                                           */
/*  output boolean Meap_bFlapStayOp;                                          */
/*  output st129 Meap_stActrTst;                                              */
/*  output uint8 ThMgt_stPosnFSF;                                             */
/*  output uint8 ActrTstMeap_OpenTime;                                        */
/*  output uint8 ActrTstMeap_ClosTime;                                        */
/*  output uint8 ActrTstMeap_Tempo;                                           */
/*  output boolean Meap_bActrTstCmpl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTMEAP_vidMEAPTst(void)
{
   boolean bLocalSrv_bActrTstEna;
   boolean bLocalTestEna;
   uint8   u8LocalCode_test_action;
   uint8   u8LocalShdFlap_stPosn;
   uint8   u8LocalThMgt_stPosnFSFReq;
   uint8   u8LocalThMgt_stPosnFSF;
   uint8   u8LocalMeapTempo;
   uint8   u8LocalClosTime;
   uint8   u8LocalOpenTime;


   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);

   if (  (bLocalSrv_bActrTstEna != 0)
      && (u8LocalCode_test_action == CODE_TEST_MEAP))
   {
      bLocalTestEna = 1;
   }
   else
   {
      bLocalTestEna = 0;
   }
   VEMS_vidGET(ShdFlap_stPosn, u8LocalShdFlap_stPosn);
   switch (Meap_stActrTst)
   {
      case MEAP_ACTRTEST_IDLE:
         if (bLocalTestEna != 0)
         {
            VEMS_vidSET(Meap_bActrTstInProgs, 1);
            VEMS_vidSET(Afts_bAcvFSF, 1);
            VEMS_vidSET(Meap_bFlapBlockOp, 0);
            VEMS_vidSET(Meap_bFlapFaild, 0);
            VEMS_vidSET(Meap_bFlapStayOp, 0);
            Meap_stActrTst = MEAP_ACTRTEST_OPEN;
            VEMS_vidSET(ThMgt_stPosnFSF, 3);
            ActrTstMeap_OpenTime =
               (uint8)MATHSRV_udtMIN(ActrTstMeap_tiDlyOpen_C, 100);
         }
         else
         {
            /* during state MEAP_ACTRTEST_IDLE */
            VEMS_vidGET(ThMgt_stPosnFSFReq, u8LocalThMgt_stPosnFSFReq);
            u8LocalThMgt_stPosnFSF =
               (uint8)MATHSRV_udtMIN(u8LocalThMgt_stPosnFSFReq, 3);
            VEMS_vidSET(ThMgt_stPosnFSF, u8LocalThMgt_stPosnFSF);
         }
         break;

      case MEAP_ACTRTEST_OPEN:
         if (bLocalTestEna == 0)
         {
            ACTRTSTMEAP_vidEntryIdleState();
         }
         else
         {
            if (u8LocalShdFlap_stPosn == 1)
            {
               Meap_stActrTst = MEAP_ACTRTEST_CLOS;
               VEMS_vidSET(ThMgt_stPosnFSF, 2);
               ActrTstMeap_ClosTime =
                  (uint8)MATHSRV_udtMIN(ActrTstMeap_tiDlyClos_C, 50);
            }
            else
            {
               if (ActrTstMeap_OpenTime <= 1)
               {
                  if (  (u8LocalShdFlap_stPosn == 0)
                     || (u8LocalShdFlap_stPosn == 2)
                     || (u8LocalShdFlap_stPosn == 3))
                  {
                     ActrTstMeap_Tempo =
                        (uint8)MATHSRV_udtMIN(ActrTstMeap_Tempo_C, 50);
                     Meap_stActrTst = MEAP_ACTRTEST_END;
                     VEMS_vidSET(Meap_bActrTstCmpl, 1);
                     VEMS_vidSET(Afts_bAcvFSF, 0);
                     VEMS_vidGET(ThMgt_stPosnFSFReq, u8LocalThMgt_stPosnFSFReq);
                     u8LocalThMgt_stPosnFSF =
                        (uint8)MATHSRV_udtMIN(u8LocalThMgt_stPosnFSFReq, 3);
                     VEMS_vidSET(ThMgt_stPosnFSF, u8LocalThMgt_stPosnFSF);

                     if (u8LocalShdFlap_stPosn == 2)
                     {
                        VEMS_vidSET(Meap_bFlapBlockOp, 1);
                     }
                     else
                     {
                        VEMS_vidSET(Meap_bFlapFaild, 1);
                     }
                  }
               }
               else
               {
                  /* during state MEAP_ACTRTST_OPEN */
                  u8LocalOpenTime = (uint8)(ActrTstMeap_OpenTime - 1);
                  ActrTstMeap_OpenTime =
                     (uint8)MATHSRV_udtMIN(u8LocalOpenTime, 100);
               }
            }
         }
         break;

      case MEAP_ACTRTEST_CLOS:
         if (bLocalTestEna == 0)
         {
            ACTRTSTMEAP_vidEntryIdleState();
         }
         else
         {
            if (ActrTstMeap_ClosTime <= 1)
            {
               if (u8LocalShdFlap_stPosn != 0)
               {
                  VEMS_vidSET(Meap_bFlapStayOp, 1);
               }
               ActrTstMeap_Tempo =
                  (uint8)MATHSRV_udtMIN(ActrTstMeap_Tempo_C, 50);
               Meap_stActrTst = MEAP_ACTRTEST_END;
               VEMS_vidSET(Meap_bActrTstCmpl, 1);
               VEMS_vidSET(Afts_bAcvFSF, 0);
               VEMS_vidGET(ThMgt_stPosnFSFReq, u8LocalThMgt_stPosnFSFReq);
               u8LocalThMgt_stPosnFSF =
                  (uint8)MATHSRV_udtMIN(u8LocalThMgt_stPosnFSFReq, 3);
               VEMS_vidSET(ThMgt_stPosnFSF, u8LocalThMgt_stPosnFSF);
            }
            else
            {
               /* during state MEAP_ACTRTEST_CLOS */
               u8LocalClosTime = (uint8)(ActrTstMeap_ClosTime - 1);
               ActrTstMeap_ClosTime =
                  (uint8)MATHSRV_udtMIN(u8LocalClosTime, 50);
            }
         }
         break;

      case MEAP_ACTRTEST_END:
         if (  (bLocalTestEna != 0)
            && (ActrTstMeap_Tempo == 0))
         {
            ACTRTSTMEAP_vidEntryIdleState();
         }
         else
         {
            /* during state MEAP_ACTRTEST_END */
            if (ActrTstMeap_Tempo > 0)
            {
               u8LocalMeapTempo = (uint8)(ActrTstMeap_Tempo - 1);
               ActrTstMeap_Tempo =
                  (uint8)MATHSRV_udtMIN(u8LocalMeapTempo, 50);
            }
            VEMS_vidGET(ThMgt_stPosnFSFReq, u8LocalThMgt_stPosnFSFReq);
            u8LocalThMgt_stPosnFSF =
               (uint8)MATHSRV_udtMIN(u8LocalThMgt_stPosnFSFReq, 3);
            VEMS_vidSET(ThMgt_stPosnFSF, u8LocalThMgt_stPosnFSF);
         }
         break;

      default:
         ACTRTSTMEAP_vidEntryIdleState();
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTMEAP_vidEntryIdleState                              */
/* !Description :  Description of the state MEAP_ACTRTEST_IDLE                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ThMgt_stPosnFSFReq;                                           */
/*  output st129 Meap_stActrTst;                                              */
/*  output boolean Afts_bAcvFSF;                                              */
/*  output boolean Meap_bActrTstCmpl;                                         */
/*  output boolean Meap_bActrTstInProgs;                                      */
/*  output uint8 ThMgt_stPosnFSF;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTMEAP_vidEntryIdleState(void)
{
   uint8 u8LocalThMgt_stPosnFSFReq;
   uint8 u8LocalThMgt_stPosnFSF;


   Meap_stActrTst = MEAP_ACTRTEST_IDLE;
   VEMS_vidSET(Afts_bAcvFSF, 0);
   VEMS_vidSET(Meap_bActrTstCmpl, 0);
   VEMS_vidSET(Meap_bActrTstInProgs, 0);
   VEMS_vidGET(ThMgt_stPosnFSFReq, u8LocalThMgt_stPosnFSFReq);
   u8LocalThMgt_stPosnFSF =
      (uint8)MATHSRV_udtMIN(u8LocalThMgt_stPosnFSFReq, 3);
   VEMS_vidSET(ThMgt_stPosnFSF, u8LocalThMgt_stPosnFSF);
}
/*------------------------------- end of file --------------------------------*/
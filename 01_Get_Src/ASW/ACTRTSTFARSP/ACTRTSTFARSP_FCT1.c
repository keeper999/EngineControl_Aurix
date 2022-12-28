/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACTRTSTFARSP                                            */
/* !Description     : ACTRTSTFARSP Component                                  */
/*                                                                            */
/* !Module          : ACTRTSTFARSP                                            */
/* !Description     : Test actionneur consigne de richesse                    */
/*                                                                            */
/* !File            : ACTRTSTFARSP_FCT1.C                                     */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / ACTRTSTFARSP_vidInitOutput                                           */
/*   2 / ACTRTSTFARSP_vidFarSpUsActrTst                                       */
/*   3 / ACTRTSTFARSP_vidFarSpUsMainTst                                       */
/*   4 / ACTRTSTFARSP_vidFarSpUsLeanTst                                       */
/*   5 / ACTRTSTFARSP_vidFarSpUsRichTst                                       */
/*   6 / ACTRTSTFARSP_vidTransition_IDLE                                      */
/*   7 / ACTRTSTFARSP_vidTransition_END                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5066987 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FAR/ACTRTSTFARSP/ACTRTSTFARSP_FC$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   20 Feb 2013 $*/
/* $Author::   etsasson                               $$Date::   20 Feb 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACTRTSTFARSP.h"
#include "ACTRTSTFARSP_l.h"
#include "ACTRTSTFARSP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTFARSP_vidInitOutput                                 */
/* !Description :  initialisation des sorties.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Afts_bAcvRlamSpTest;                                       */
/*  output uint16 Afts_rMixtReqRlamSpTest;                                    */
/*  output boolean FarSp_bUsPlausFcoActrTst;                                  */
/*  output boolean FarSp_bUsPlausFldActrTst;                                  */
/*  output st128 FarSp_stActrTst;                                             */
/*  output uint16 ActrTstFarSp_Tempo;                                         */
/*  output uint16 ActrTstFarSp_TstTime;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTFARSP_vidInitOutput(void)
{
   VEMS_vidSET(Afts_bAcvRlamSpTest, 0);
   VEMS_vidSET(Afts_rMixtReqRlamSpTest, 0);
   VEMS_vidSET(FarSp_bUsPlausFcoActrTst, 0);
   VEMS_vidSET(FarSp_bUsPlausFldActrTst, 0);
   VEMS_vidSET(FarSp_stActrTst, FARSP_ACTRTST_IDLE);
   ActrTstFarSp_Tempo = 0;
   ActrTstFarSp_TstTime = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTFARSP_vidFarSpUsActrTst                             */
/* !Description :  Ce test est activé par les outils de diagnostic            */
/*                 constructeur en fin de chaîne, en après-vente ou pour des  */
/*                 besoins de formation. Le test s’interrompt si au moins une */
/*                 des conditions d’activation du test n’est pas vérifiée.    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_E_12_004362_001.01                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACTRTSTFARSP_vidFarSpUsMainTst();                        */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACTRTSTFARSP_vidFarSpUsLeanTst();                        */
/*  extf argret void ACTRTSTFARSP_vidFarSpUsRichTst();                        */
/*  input st128 FarSp_stActrTst;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTFARSP_vidFarSpUsActrTst(void)
{
   uint8  u8LocalFarSp_stActrTst;


   ACTRTSTFARSP_vidFarSpUsMainTst();
   VEMS_vidGET(FarSp_stActrTst, u8LocalFarSp_stActrTst);
   if (u8LocalFarSp_stActrTst == FARSP_ACTRTST_PHASE1)
   {
      ACTRTSTFARSP_vidFarSpUsLeanTst();
   }
   else
   {
      if (u8LocalFarSp_stActrTst == FARSP_ACTRTST_PHASE2)
      {
         ACTRTSTFARSP_vidFarSpUsRichTst();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTFARSP_vidFarSpUsMainTst                             */
/* !Description :  Automate de la stratégie d'apprentissage des défauts.      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_E_12_004362_002.01                                    */
/*                 VEMS_E_12_004362_003.02                                    */
/*                 VEMS_E_12_004362_004.02                                    */
/*                 VEMS_E_12_004362_005.01                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACTRTSTFARSP_vidTransition_IDLE();                       */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void ACTRTSTFARSP_vidTransition_END();                        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input st128 FarSp_stActrTst;                                              */
/*  input uint16 ActrTstFarSp_Tempo;                                          */
/*  input boolean FarSp_bInhSenO2UsEEDiag_C;                                  */
/*  input uint16 Afts_rMixtReqAfrRlamSpTest_C;                                */
/*  input uint16 Afts_tiDlyPha1RlamSpTest_C;                                  */
/*  input uint16 ActrTstFarSp_TstTime;                                        */
/*  input uint8 Ext_uLsUsMes;                                                 */
/*  input uint8 Afts_uAfrRlamSpTest_C;                                        */
/*  input uint16 Afts_rMixtReqAflRlamSpTest_C;                                */
/*  input uint16 Afts_tiDlyPha2RlamSpTest_C;                                  */
/*  output st128 FarSp_stActrTst;                                             */
/*  output boolean FarSp_bTstInProgs;                                         */
/*  output boolean FarSp_bActrTstCmpl;                                        */
/*  output uint16 ActrTstFarSp_Tempo;                                         */
/*  output boolean Afts_bAcvRlamSpTest;                                       */
/*  output uint16 Afts_rMixtReqRlamSpTest;                                    */
/*  output uint16 ActrTstFarSp_TstTime;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTFARSP_vidFarSpUsMainTst(void)
{
   boolean bLocalCfmSenO2Us_ElecDftDiag;
   boolean bLocalTestEna;
   boolean bLocalSrv_bActrTstEna;
   uint8   u8LocalFarSp_stActrTst;
   uint8   u8LocalCode_test_action;
   uint8   u8LocalExt_uLsUsMes;
   uint16  u16LocalAfts_tiDlyPha1RlamSpTest;
   uint16  u16LocalAfts_tiDlyPha2RlamSpTest;
   uint16  u16LocalAfts_rMixtReqRlamSpTest;
   sint32  s32LocalActrTstFarSp_Tempo;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);
   if (  (u8LocalCode_test_action == CODE_TEST_FARSP)
      && (bLocalSrv_bActrTstEna != 0))
   {
      bLocalTestEna = 1;
   }
   else
   {
      bLocalTestEna = 0;
   }

   VEMS_vidGET(FarSp_stActrTst, u8LocalFarSp_stActrTst);
   switch( u8LocalFarSp_stActrTst )
   {
      case FARSP_ACTRTST_IDLE:
         {
            if (bLocalTestEna !=0)
            {
               VEMS_vidSET(FarSp_stActrTst, FARSP_ACTRTST_EE);
               VEMS_vidSET(FarSp_bTstInProgs, 1);
               VEMS_vidSET(FarSp_bActrTstCmpl, 0);
            }
         }
         break;

      case FARSP_ACTRTST_END:
         {
            if (  (bLocalTestEna !=0)
               && (ActrTstFarSp_Tempo == 0))
            {
               ACTRTSTFARSP_vidTransition_IDLE();
            }
            else
            {
               s32LocalActrTstFarSp_Tempo = ActrTstFarSp_Tempo - 1;
               ActrTstFarSp_Tempo =
                 (uint16)MATHSRV_udtCLAMP(s32LocalActrTstFarSp_Tempo,0 , 30000);
            }
         }
         break;

      case FARSP_ACTRTST_EE:
         {
            if (bLocalTestEna == 0)
            {
               ACTRTSTFARSP_vidTransition_IDLE();
            }
            else
            {
               bLocalCfmSenO2Us_ElecDftDiag =
                  GDGAR_bGetFRM(FRM_FRM_CFMSENO2US_ELECDFTDIAG);
               if (  (bLocalCfmSenO2Us_ElecDftDiag == 0)
                  || (FarSp_bInhSenO2UsEEDiag_C != 0))
               {
                  VEMS_vidSET(FarSp_stActrTst, FARSP_ACTRTST_PHASE1);
                  VEMS_vidSET(FarSp_bTstInProgs, 1);
                  VEMS_vidSET(FarSp_bActrTstCmpl, 0);
                  VEMS_vidSET(Afts_bAcvRlamSpTest, 1);
                  u16LocalAfts_rMixtReqRlamSpTest =
                    (uint16)MATHSRV_udtMIN(Afts_rMixtReqAfrRlamSpTest_C, 61440);
                  VEMS_vidSET(Afts_rMixtReqRlamSpTest,
                              u16LocalAfts_rMixtReqRlamSpTest);
                  ActrTstFarSp_TstTime = 0;
               }
               else
               {
                  ACTRTSTFARSP_vidTransition_END();
               }
            }
         }
         break;

      case FARSP_ACTRTST_PHASE1:
         {
            if (bLocalTestEna == 0)
            {
               ACTRTSTFARSP_vidTransition_IDLE();
            }
            else
            {
               u16LocalAfts_tiDlyPha1RlamSpTest =
                  (uint16)(Afts_tiDlyPha1RlamSpTest_C * 10);
               if (ActrTstFarSp_TstTime > u16LocalAfts_tiDlyPha1RlamSpTest)
               {
                  VEMS_vidGET(Ext_uLsUsMes, u8LocalExt_uLsUsMes);
                  if (u8LocalExt_uLsUsMes >= Afts_uAfrRlamSpTest_C)
                  {
                     VEMS_vidSET(FarSp_stActrTst, FARSP_ACTRTST_PHASE2);
                     VEMS_vidSET(Afts_bAcvRlamSpTest, 1);
                     VEMS_vidSET(FarSp_bActrTstCmpl, 0);
                     VEMS_vidSET(FarSp_bTstInProgs, 1);
                     u16LocalAfts_rMixtReqRlamSpTest =
                        (uint16)MATHSRV_udtMIN( Afts_rMixtReqAflRlamSpTest_C,
                                                61440);
                     VEMS_vidSET(Afts_rMixtReqRlamSpTest,
                                 u16LocalAfts_rMixtReqRlamSpTest);
                     ActrTstFarSp_TstTime = 0;
                  }
                  else
                  {
                     ACTRTSTFARSP_vidTransition_END();
                  }
               }
               else
               {
                  if (ActrTstFarSp_TstTime < 30000)
                  {
                     ActrTstFarSp_TstTime = (uint16)(ActrTstFarSp_TstTime + 1);
                  }
               }
            }
         }
         break;

      case FARSP_ACTRTST_PHASE2:
         {

            if (bLocalTestEna == 0)
            {
               ACTRTSTFARSP_vidTransition_IDLE();
            }
            else
            {
               u16LocalAfts_tiDlyPha2RlamSpTest =
                  (uint16)(Afts_tiDlyPha2RlamSpTest_C * 10);
               if ( ActrTstFarSp_TstTime > u16LocalAfts_tiDlyPha2RlamSpTest)
               {
                  ACTRTSTFARSP_vidTransition_END();
               }
               else
               {
                  if (ActrTstFarSp_TstTime < 30000)
                  {
                     ActrTstFarSp_TstTime = (uint16)(ActrTstFarSp_TstTime + 1);
                  }
               }
            }
         }
         break;

      default:
         ACTRTSTFARSP_vidTransition_IDLE();
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTFARSP_vidFarSpUsLeanTst                             */
/* !Description :  Cette fonction permet la détection de la sonde bloquée     */
/*                 pauvre.                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_E_12_004362_006.01                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_uLsUsMes;                                                 */
/*  input uint8 Afts_uAfrRlamSpTest_C;                                        */
/*  output boolean FarSp_bUsPlausFldActrTst;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTFARSP_vidFarSpUsLeanTst(void)
{
   uint8 u8LocalExt_uLsUsMes;


   VEMS_vidGET(Ext_uLsUsMes, u8LocalExt_uLsUsMes);
   if (u8LocalExt_uLsUsMes < Afts_uAfrRlamSpTest_C)
   {
      VEMS_vidSET(FarSp_bUsPlausFldActrTst, 1);
   }
   else
   {
      VEMS_vidSET(FarSp_bUsPlausFldActrTst, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTFARSP_vidFarSpUsRichTst                             */
/* !Description :  Cette fonction permet la détection de la sonde bloquée     */
/*                 riche                                                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_E_12_004362_007.01                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_uLsUsMes;                                                 */
/*  input uint8 Afts_uAflRlamSpTest_C;                                        */
/*  output boolean FarSp_bUsPlausFcoActrTst;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTFARSP_vidFarSpUsRichTst(void)
{
   uint8 u8LocalExt_uLsUsMes;


   VEMS_vidGET(Ext_uLsUsMes, u8LocalExt_uLsUsMes);
   if (u8LocalExt_uLsUsMes > Afts_uAflRlamSpTest_C)
   {
      VEMS_vidSET(FarSp_bUsPlausFcoActrTst, 1);
   }
   else
   {
      VEMS_vidSET(FarSp_bUsPlausFcoActrTst, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTFARSP_vidTransition_IDLE                            */
/* !Description :  cette fonction decrit le comportement du systeme lors de   */
/*                 l'entrée à la transition FARSP_ACTRTST_IDLE                */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st128 FarSp_stActrTst;                                             */
/*  output boolean Afts_bAcvRlamSpTest;                                       */
/*  output uint16 Afts_rMixtReqRlamSpTest;                                    */
/*  output boolean FarSp_bActrTstCmpl;                                        */
/*  output boolean FarSp_bTstInProgs;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTFARSP_vidTransition_IDLE(void)
{
   VEMS_vidSET(FarSp_stActrTst, FARSP_ACTRTST_IDLE);
   VEMS_vidSET(Afts_bAcvRlamSpTest, 0);
   VEMS_vidSET(Afts_rMixtReqRlamSpTest, 0);
   VEMS_vidSET(FarSp_bActrTstCmpl, 0);
   VEMS_vidSET(FarSp_bTstInProgs, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACTRTSTFARSP_vidTransition_END                             */
/* !Description :  cette fonction decrit le comportement du systeme lors de   */
/*                 l'entrée à la transition FARSP_ACTRTST_END                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ActrTstFarSp_Tempo_C;                                        */
/*  output st128 FarSp_stActrTst;                                             */
/*  output boolean Afts_bAcvRlamSpTest;                                       */
/*  output uint16 Afts_rMixtReqRlamSpTest;                                    */
/*  output boolean FarSp_bActrTstCmpl;                                        */
/*  output boolean FarSp_bTstInProgs;                                         */
/*  output uint16 ActrTstFarSp_Tempo;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACTRTSTFARSP_vidTransition_END(void)
{
   VEMS_vidSET(FarSp_stActrTst, FARSP_ACTRTST_END);
   VEMS_vidSET(Afts_bAcvRlamSpTest, 0);
   VEMS_vidSET(Afts_rMixtReqRlamSpTest, 0);
   VEMS_vidSET(FarSp_bActrTstCmpl, 1);
   VEMS_vidSET(FarSp_bTstInProgs, 0);
   ActrTstFarSp_Tempo =
      (uint16)MATHSRV_udtMIN(ActrTstFarSp_Tempo_C, 30000);
}
/*---------------------------------End Of File--------------------------------*/
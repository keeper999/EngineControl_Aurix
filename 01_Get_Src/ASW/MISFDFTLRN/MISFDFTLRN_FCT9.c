/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDFTLRN                                              */
/* !Description     : MISFDFTLRN component.                                   */
/*                                                                            */
/* !Module          : MISFDFTLRN                                              */
/* !Description     : Apprentissage des défauts Misfire.                      */
/*                                                                            */
/* !File            : MISFDFTLRN_FCT9.C                                       */
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
/*   1 / MISFDFTLRN_vidIniSaveLrn                                             */
/*   2 / MISFDFTLRN_vidUpdateWinAdap                                          */
/*   3 / MISFDFTLRN_vidSampleWin                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5069555 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#068760                                         */
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
#include "MISFDFTLRN.h"
#include "MISFDFTLRN_L.h"
#include "MISFDFTLRN_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidIniSaveLrn                                   */
/* !Description :  Cette fonction permet d’initialiser la moyenne des         */
/*                 échantillons qui est calculée dans le StateFlow            */
/*                 Misf_stLrnWin. Cette initialisation est réalisée sur tous  */
/*                 les cylindres et sur toutes les fenêtres lorsque les       */
/*                 conditions de stabilité sont remplies.                     */
/* !Number      :  FCT9.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint32 Mf_adap_lw_err_filt_uavn1[4];                                */
/*  input sint16 Mf_adap_Exp_err_filt_uavn1[4];                               */
/*  input sint16 Mf_adap_TDC_err_filt_uavn1[4];                               */
/*  input sint16 Mf_adap_Bdc_err_filt_uavn1[4];                               */
/*  output sint16 Mf_adap_lw_err_mv_i_uavn1[4];                               */
/*  output sint16 Mf_adap_Exp_err_mv_i_uavn1[4];                              */
/*  output sint16 Mf_adap_TDC_err_mv_i_uavn1[4];                              */
/*  output sint16 Mf_adap_Bdc_err_mv_i_uavn1[4];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidIniSaveLrn(void)
{
   /* MisfDftLrn/MisfDftLrn/10_ini_save_lrn */
   uint8   u8LocalIndex;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      Mf_adap_lw_err_mv_i_uavn1[u8LocalIndex] =
         (sint16)MATHSRV_udtCLAMP(Mf_adap_lw_err_filt_uavn1[u8LocalIndex],
                                  -32768,
                                  32767);
      Mf_adap_Exp_err_mv_i_uavn1[u8LocalIndex] =
         Mf_adap_Exp_err_filt_uavn1[u8LocalIndex];
      Mf_adap_TDC_err_mv_i_uavn1[u8LocalIndex] =
         Mf_adap_TDC_err_filt_uavn1[u8LocalIndex];
      Mf_adap_Bdc_err_mv_i_uavn1[u8LocalIndex] =
         Mf_adap_Bdc_err_filt_uavn1[u8LocalIndex];
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidUpdateWinAdap                                */
/* !Description :  Ce module est exécuté à la récurrence de la tâche          */
/*                 Misf_EveMisf. Il permet de mettre a jour les calcule des   */
/*                 adaptations Misf_prm_tiDlyXXXWinLrnCylX qui ont été        */
/*                 calculées.                                                 */
/* !Number      :  FCT9.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input sint16 Misf_prm_tiDlyExpWinLrn[4][9];                               */
/*  input sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                               */
/*  input sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                               */
/*  input sint16 Misf_prm_tiDlyLongWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyExpWinLrnCyl2[9];                             */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyTDCWinLrnCyl2[9];                             */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrnCyl2[9];                             */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyLongWinLrnCyl2[9];                            */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*  output sint16 Misf_prm_tiDlyExpWinLrnCyl3[9];                             */
/*  output sint16 Misf_prm_tiDlyTDCWinLrnCyl3[9];                             */
/*  output sint16 Misf_prm_tiDlyBdcWinLrnCyl3[9];                             */
/*  output sint16 Misf_prm_tiDlyLongWinLrnCyl3[9];                            */
/*  output sint16 Misf_prm_tiDlyExpWinLrnCyl4[9];                             */
/*  output sint16 Misf_prm_tiDlyTDCWinLrnCyl4[9];                             */
/*  output sint16 Misf_prm_tiDlyBdcWinLrnCyl4[9];                             */
/*  output sint16 Misf_prm_tiDlyLongWinLrnCyl4[9];                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidUpdateWinAdap(void)
{
   sint32 s32LocalIndx1;


   for (s32LocalIndx1 = 0; s32LocalIndx1 < 9; s32LocalIndx1++)
   {
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyExpWinLrnCyl2,
                                s32LocalIndx1,
                                Misf_prm_tiDlyExpWinLrn[1][s32LocalIndx1]);
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyTDCWinLrnCyl2,
                                s32LocalIndx1,
                                Misf_prm_tiDlyTDCWinLrn[1][s32LocalIndx1]);
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyBdcWinLrnCyl2,
                                s32LocalIndx1,
                                Misf_prm_tiDlyBdcWinLrn[1][s32LocalIndx1]);
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyLongWinLrnCyl2,
                                s32LocalIndx1,
                                Misf_prm_tiDlyLongWinLrn[1][s32LocalIndx1]);
   }

   for (s32LocalIndx1 = 0; s32LocalIndx1 < 9; s32LocalIndx1++)
   {
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyExpWinLrnCyl3,
                                s32LocalIndx1,
                                Misf_prm_tiDlyExpWinLrn[2][s32LocalIndx1]);
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyTDCWinLrnCyl3,
                                s32LocalIndx1,
                                Misf_prm_tiDlyTDCWinLrn[2][s32LocalIndx1]);
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyBdcWinLrnCyl3,
                                s32LocalIndx1,
                                Misf_prm_tiDlyBdcWinLrn[2][s32LocalIndx1]);
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyLongWinLrnCyl3,
                                s32LocalIndx1,
                                Misf_prm_tiDlyLongWinLrn[2][s32LocalIndx1]);
   }

   for (s32LocalIndx1 = 0; s32LocalIndx1 < 9; s32LocalIndx1++)
   {
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyExpWinLrnCyl4,
                                s32LocalIndx1,
                                Misf_prm_tiDlyExpWinLrn[3][s32LocalIndx1]);
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyTDCWinLrnCyl4,
                                s32LocalIndx1,
                                Misf_prm_tiDlyTDCWinLrn[3][s32LocalIndx1]);
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyBdcWinLrnCyl4,
                                s32LocalIndx1,
                                Misf_prm_tiDlyBdcWinLrn[3][s32LocalIndx1]);
      VEMS_vidSET1DArrayElement(Misf_prm_tiDlyLongWinLrnCyl4,
                                s32LocalIndx1,
                                Misf_prm_tiDlyLongWinLrn[3][s32LocalIndx1]);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidSampleWin                                    */
/* !Description :  Ce bloc permet d’utiliser la table «                       */
/*                 Misf_noWinSamplePlaMod_T » ou « Misf_noWinSample_T » selon */
/*                 l’activation du Mode UT.                                   */
/* !Number      :  FCT9.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  input uint8 Misf_noWinSample_Ut_T[4];                                     */
/*  input uint8 Misf_noWinSample_Nom_T[4];                                    */
/*  output uint8 Misf_noWinSample_T[4];                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidSampleWin(void)
{
   boolean bLocalSrv_bAcvPlaMod;
   sint32  s32LocalIndx1;

   VEMS_vidGET(Srv_bAcvPlaMod, bLocalSrv_bAcvPlaMod);

   if (bLocalSrv_bAcvPlaMod != 0)
   {
      for (s32LocalIndx1 = 0; s32LocalIndx1 < 4; s32LocalIndx1++)
      {
         Misf_noWinSample_T[s32LocalIndx1] =
               Misf_noWinSample_Ut_T[s32LocalIndx1];
      }
   }
   else
   {
      for (s32LocalIndx1 = 0; s32LocalIndx1 < 4; s32LocalIndx1++)
      {
         Misf_noWinSample_T[s32LocalIndx1] =
               Misf_noWinSample_Nom_T[s32LocalIndx1];
      }
   }
}
/*-------------------------------- end of file -------------------------------*/
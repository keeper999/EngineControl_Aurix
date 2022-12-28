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
/* !File            : MISFDFTLRN_FCT7.C                                       */
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
/*   1 / MISFDFTLRN_vidCorrBkptLw2                                            */
/*   2 / MISFDFTLRN_vidCorrBkptLw3                                            */
/*   3 / MISFDFTLRN_vidCorrBkptLw4                                            */
/*   4 / MISFDFTLRN_vidCorrBkptLw5                                            */
/*   5 / MISFDFTLRN_vidCorrBkptLw6                                            */
/*   6 / MISFDFTLRN_vidCorrBkptLw7                                            */
/*   7 / MISFDFTLRN_vidCorrBkptLw8                                            */
/*   8 / MISFDFTLRN_vidCorrBkptLw9                                            */
/*   9 / MISFDFTLRN_vidApplyDeltaShrt                                         */
/*   10 / MISFDFTLRN_vidAdapShrtNoRlzd                                        */
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
/* !Function    :  MISFDFTLRN_vidCorrBkptLw2                                  */
/* !Description :  cette fonction permet la Correction de la fenêtre longue   */
/*                 (appliqué au demi-tour 2)  dépendant du régime moteur.     */
/* !Number      :  FCT7.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_lw_corr_precal_uacn2[4][9];                          */
/*  input sint16 Mf_adap_lw_delta_applied_uavn1[4];                           */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptLw2(void)
{
   /* 01_apply_corr_bkpt_lw_2 */
   uint8  u8LocalIndex;
   sint16 s16Locallwcorrprecaluacn2;
   sint32 s32LocaltiDlyLongWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s16Locallwcorrprecaluacn2 =
         (sint16)(Mf_adap_lw_corr_precal_uacn2[u8LocalIndex][1] - 32768);
      s32LocaltiDlyLongWinLrn =
         ( s16Locallwcorrprecaluacn2
         - Mf_adap_lw_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyLongWinLrn[u8LocalIndex][1] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyLongWinLrn,
                                  -32768,
                                  32767);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptLw3                                  */
/* !Description :  Cette fonction permet la Correction de la fenêtre longue   */
/*                 (appliqué au demi-tour 2) dépendant du régime moteur .     */
/* !Number      :  FCT7.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_lw_corr_precal_uacn2[4][9];                          */
/*  input sint16 Mf_adap_lw_delta_applied_uavn1[4];                           */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptLw3(void)
{
   /* 01_apply_corr_bkpt_lw_3 */
   uint8  u8LocalIndex;
   sint16 s16Locallwcorrprecaluacn2;
   sint32 s32LocaltiDlyLongWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s16Locallwcorrprecaluacn2 =
         (sint16)(Mf_adap_lw_corr_precal_uacn2[u8LocalIndex][2] - 32768);
      s32LocaltiDlyLongWinLrn =
         ( s16Locallwcorrprecaluacn2
         - Mf_adap_lw_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyLongWinLrn[u8LocalIndex][2] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyLongWinLrn,
                                  -32768,
                                  32767);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptLw4                                  */
/* !Description :  Cette fonction permet la Correction de la fenêtre longue   */
/*                 (appliqué au demi-tour 2)  dépendant du régime moteur.     */
/* !Number      :  FCT7.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_lw_corr_precal_uacn2[4][9];                          */
/*  input sint16 Mf_adap_lw_delta_applied_uavn1[4];                           */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptLw4(void)
{
   /* 01_apply_corr_bkpt_lw_4 */
   uint8  u8LocalIndex;
   sint16 s16Locallwcorrprecaluacn2;
   sint32 s32LocaltiDlyLongWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s16Locallwcorrprecaluacn2 =
         (sint16)(Mf_adap_lw_corr_precal_uacn2[u8LocalIndex][3] - 32768);
      s32LocaltiDlyLongWinLrn =
         ( s16Locallwcorrprecaluacn2
         - Mf_adap_lw_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyLongWinLrn[u8LocalIndex][3] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyLongWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptLw5                                  */
/* !Description :  Cette fonction permet la Correction de la fenêtre longue   */
/*                 (appliqué au demi-tour 2)  dépendant du régime moteur.     */
/* !Number      :  FCT7.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_lw_corr_precal_uacn2[4][9];                          */
/*  input sint16 Mf_adap_lw_delta_applied_uavn1[4];                           */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptLw5(void)
{
   /* 01_apply_corr_bkpt_lw_5 */
   uint8  u8LocalIndex;
   sint16 s16Locallwcorrprecaluacn2;
   sint32 s32LocaltiDlyLongWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s16Locallwcorrprecaluacn2 =
         (sint16)(Mf_adap_lw_corr_precal_uacn2[u8LocalIndex][4] - 32768);
      s32LocaltiDlyLongWinLrn =
         ( s16Locallwcorrprecaluacn2
         - Mf_adap_lw_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyLongWinLrn[u8LocalIndex][4] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyLongWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptLw6                                  */
/* !Description :  Cette fonction permet la Correction de la fenêtre longue   */
/*                 (appliqué au demi-tour 2)  dépendant du régime moteur.     */
/* !Number      :  FCT7.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_lw_corr_precal_uacn2[4][9];                          */
/*  input sint16 Mf_adap_lw_delta_applied_uavn1[4];                           */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptLw6(void)
{
   /* 01_apply_corr_bkpt_lw_6 */
   uint8  u8LocalIndex;
   sint16 s16Locallwcorrprecaluacn2;
   sint32 s32LocaltiDlyLongWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s16Locallwcorrprecaluacn2 =
         (sint16)(Mf_adap_lw_corr_precal_uacn2[u8LocalIndex][5] - 32768);
      s32LocaltiDlyLongWinLrn =
         ( s16Locallwcorrprecaluacn2
         - Mf_adap_lw_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyLongWinLrn[u8LocalIndex][5] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyLongWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptLw7                                  */
/* !Description :  Cette fonction permet la Correction de la fenêtre longue   */
/*                 (appliqué au demi-tour 2)  dépendant du régime moteur.     */
/* !Number      :  FCT7.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_lw_corr_precal_uacn2[4][9];                          */
/*  input sint16 Mf_adap_lw_delta_applied_uavn1[4];                           */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptLw7(void)
{
   /* 01_apply_corr_bkpt_lw_7 */
   uint8  u8LocalIndex;
   sint16 s16Locallwcorrprecaluacn2;
   sint32 s32LocaltiDlyLongWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s16Locallwcorrprecaluacn2 =
         (sint16)(Mf_adap_lw_corr_precal_uacn2[u8LocalIndex][6] - 32768);
      s32LocaltiDlyLongWinLrn =
         ( s16Locallwcorrprecaluacn2
         - Mf_adap_lw_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyLongWinLrn[u8LocalIndex][6] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyLongWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptLw8                                  */
/* !Description :  Cette fonction permet la Correction de la fenêtre longue   */
/*                 (appliqué au demi-tour 2)  dépendant du régime moteur.     */
/* !Number      :  FCT7.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_lw_corr_precal_uacn2[4][9];                          */
/*  input sint16 Mf_adap_lw_delta_applied_uavn1[4];                           */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptLw8(void)
{
   /* 01_apply_corr_bkpt_lw_8 */
   uint8  u8LocalIndex;
   sint16 s16Locallwcorrprecaluacn2;
   sint32 s32LocaltiDlyLongWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s16Locallwcorrprecaluacn2 =
         (sint16)(Mf_adap_lw_corr_precal_uacn2[u8LocalIndex][7] - 32768);
      s32LocaltiDlyLongWinLrn =
         ( s16Locallwcorrprecaluacn2
         - Mf_adap_lw_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyLongWinLrn[u8LocalIndex][7] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyLongWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptLw9                                  */
/* !Description :  Cette fonction permet la Correction de la fenêtre longue   */
/*                 (appliqué au demi-tour 2)  dépendant du régime moteur.     */
/* !Number      :  FCT7.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_lw_corr_precal_uacn2[4][9];                          */
/*  input sint16 Mf_adap_lw_delta_applied_uavn1[4];                           */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptLw9(void)
{
   /* 01_apply_corr_bkpt_lw_9 */
   uint8  u8LocalIndex;
   sint16 s16Locallwcorrprecaluacn2;
   sint32 s32LocaltiDlyLongWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s16Locallwcorrprecaluacn2 =
         (sint16)(Mf_adap_lw_corr_precal_uacn2[u8LocalIndex][8] - 32768);
      s32LocaltiDlyLongWinLrn =
         ( s16Locallwcorrprecaluacn2
         - Mf_adap_lw_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyLongWinLrn[u8LocalIndex][8] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyLongWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidApplyDeltaShrt                               */
/* !Description :  Cette fonction permet de donner l'Indicateur de non        */
/*                 apprentissage (fenêtres courtes).                          */
/* !Number      :  FCT7.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidAdapShrtNoRlzd();                          */
/*  extf argret void MISFDFTLRN_vidCorrBkptShrt1();                           */
/*  extf argret void MISFDFTLRN_vidCorrBkptShrt2();                           */
/*  extf argret void MISFDFTLRN_vidCorrBkptShrt3();                           */
/*  extf argret void MISFDFTLRN_vidCorrBkptShrt4();                           */
/*  extf argret void MISFDFTLRN_vidCorrBkptShrt5();                           */
/*  extf argret void MISFDFTLRN_vidCorrBkptShrt6();                           */
/*  extf argret void MISFDFTLRN_vidCorrBkptShrt7();                           */
/*  extf argret void MISFDFTLRN_vidCorrBkptShrt8();                           */
/*  extf argret void MISFDFTLRN_vidCorrBkptShrt9();                           */
/*  input boolean Mf_adap_inh_no_rlzd_uacn0;                                  */
/*  input sint16 Mf_adap_Exp_delta_applied_uavn1[4];                          */
/*  input sint16 Mf_adap_Exp_delta_uavn1[4];                                  */
/*  input uint8 Mf_adap_corr_gain_uacn0;                                      */
/*  input sint16 Mf_adap_TDC_delta_applied_uavn1[4];                          */
/*  input sint16 Mf_adap_TDC_delta_uavn1[4];                                  */
/*  input sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                          */
/*  input sint16 Mf_adap_Bdc_delta_uavn1[4];                                  */
/*  input uint8 Mf_adap_shrt_corr_count_uavn1[9];                             */
/*  output sint16 Mf_adap_Exp_delta_applied_uavn1[4];                         */
/*  output sint16 Mf_adap_TDC_delta_applied_uavn1[4];                         */
/*  output sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidApplyDeltaShrt(void)
{
   /* MisfDftLrn/MisfDftLrn/09_apply_delta_precal/02_apply_delta_shrt   */
   uint8  u8LocalIndex;

   if (Mf_adap_inh_no_rlzd_uacn0 == 0)
   {
      MISFDFTLRN_vidAdapShrtNoRlzd();
   }

   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      if (Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex] != 0)
      {
         Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex] =
            (sint16)( ( ( Mf_adap_Exp_delta_uavn1[u8LocalIndex]
                        * Mf_adap_corr_gain_uacn0)
                      + ( Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex]
                        * (256 - Mf_adap_corr_gain_uacn0)))
                    / 256);
      }
      else
      {
         Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex] =
            Mf_adap_Exp_delta_uavn1[u8LocalIndex];
      }
   }

   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      if (Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex] != 0)
      {
         Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex] =
            (sint16)( ( ( Mf_adap_TDC_delta_uavn1[u8LocalIndex]
                        * Mf_adap_corr_gain_uacn0)
                      + ( Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex]
                        * (256 - Mf_adap_corr_gain_uacn0)))
                    / 256);
      }
      else
      {
         Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex] =
            Mf_adap_TDC_delta_uavn1[u8LocalIndex];
      }
   }

   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      if (Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex] != 0)
      {
         Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex] =
            (sint16)( ( ( Mf_adap_Bdc_delta_uavn1[u8LocalIndex]
                        * Mf_adap_corr_gain_uacn0)
                      + ( Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex]
                        * (256 - Mf_adap_corr_gain_uacn0)))
                    / 256);
      }
      else
      {
         Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex] =
            Mf_adap_Bdc_delta_uavn1[u8LocalIndex];
      }
   }

   if (Mf_adap_shrt_corr_count_uavn1[0] == 0)
   {
      MISFDFTLRN_vidCorrBkptShrt1();
   }

   if (Mf_adap_shrt_corr_count_uavn1[1] == 0)
   {
      MISFDFTLRN_vidCorrBkptShrt2();
   }

   if (Mf_adap_shrt_corr_count_uavn1[2] == 0)
   {
      MISFDFTLRN_vidCorrBkptShrt3();
   }

   if (Mf_adap_shrt_corr_count_uavn1[3] == 0)
   {
      MISFDFTLRN_vidCorrBkptShrt4();
   }

   if (Mf_adap_shrt_corr_count_uavn1[4] == 0)
   {
      MISFDFTLRN_vidCorrBkptShrt5();
   }

   if (Mf_adap_shrt_corr_count_uavn1[5] == 0)
   {
      MISFDFTLRN_vidCorrBkptShrt6();
   }

   if (Mf_adap_shrt_corr_count_uavn1[6] == 0)
   {
      MISFDFTLRN_vidCorrBkptShrt7();
   }

   if (Mf_adap_shrt_corr_count_uavn1[7] == 0)
   {
      MISFDFTLRN_vidCorrBkptShrt8();
   }

   if (Mf_adap_shrt_corr_count_uavn1[8] == 0)
   {
      MISFDFTLRN_vidCorrBkptShrt9();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapShrtNoRlzd                               */
/* !Description :  Initialiser l'Indicateur de non apprentissage (fenêtres    */
/*                 courtes).                                                  */
/* !Number      :  FCT7.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_adap_shrt_no_rlzd_uavb0;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapShrtNoRlzd(void)
{
   VEMS_vidSET(Mf_adap_shrt_no_rlzd_uavb0, 0);
}
/*-------------------------------- end of file -------------------------------*/
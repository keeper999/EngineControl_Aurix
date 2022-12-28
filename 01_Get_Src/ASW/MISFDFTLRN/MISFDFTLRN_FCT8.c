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
/* !File            : MISFDFTLRN_FCT8.C                                       */
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
/*   1 / MISFDFTLRN_vidCorrBkptShrt1                                          */
/*   2 / MISFDFTLRN_vidCorrBkptShrt2                                          */
/*   3 / MISFDFTLRN_vidCorrBkptShrt3                                          */
/*   4 / MISFDFTLRN_vidCorrBkptShrt4                                          */
/*   5 / MISFDFTLRN_vidCorrBkptShrt5                                          */
/*   6 / MISFDFTLRN_vidCorrBkptShrt6                                          */
/*   7 / MISFDFTLRN_vidCorrBkptShrt7                                          */
/*   8 / MISFDFTLRN_vidCorrBkptShrt8                                          */
/*   9 / MISFDFTLRN_vidCorrBkptShrt9                                          */
/*   10 / MISFDFTLRN_vidRstCorrDelta                                          */
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

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptShrt1                                */
/* !Description :  Cette fonction permet la Correction de la fenêtre courte   */
/*                 PMB, courte détente et courte PMH dépendant du régime      */
/*                 moteur.                                                    */
/* !Number      :  FCT8.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_TDC_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_TDC_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Exp_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Exp_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Bdc_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                          */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptShrt1(void)
{
   /* 01_apply_corr_bkpt_shrt_1 */
   uint8  u8LocalIndex;
   sint32 s32LocaltiDlyTDCWinLrn;
   sint32 s32LocaltiDlyExpWinLrn;
   sint32 s32LocaltiDlyBdcWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s32LocaltiDlyTDCWinLrn =
         ( (Mf_adap_TDC_corr_precal_uacn2[u8LocalIndex][0] - 32768)
         - Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyTDCWinLrn[u8LocalIndex][0] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyTDCWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyExpWinLrn =
         ( (Mf_adap_Exp_corr_precal_uacn2[u8LocalIndex][0] - 32768)
         - Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyExpWinLrn[u8LocalIndex][0] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyExpWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyBdcWinLrn =
         ( (Mf_adap_Bdc_corr_precal_uacn2[u8LocalIndex][0] - 32768)
         - Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyBdcWinLrn[u8LocalIndex][0] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyBdcWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptShrt2                                */
/* !Description :  Cette fonction permet la Correction de la fenêtre courte   */
/*                 PMB, courte détente et courte PMH dépendant du régime      */
/*                 moteur.                                                    */
/* !Number      :  FCT8.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_TDC_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_TDC_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Exp_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Exp_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Bdc_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                          */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptShrt2(void)
{
   /* 01_apply_corr_bkpt_shrt_2 */
   uint8  u8LocalIndex;
   sint32 s32LocaltiDlyTDCWinLrn;
   sint32 s32LocaltiDlyExpWinLrn;
   sint32 s32LocaltiDlyBdcWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s32LocaltiDlyTDCWinLrn =
         ( (Mf_adap_TDC_corr_precal_uacn2[u8LocalIndex][1] - 32768)
         - Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyTDCWinLrn[u8LocalIndex][1] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyTDCWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyExpWinLrn =
         ( (Mf_adap_Exp_corr_precal_uacn2[u8LocalIndex][1] - 32768)
         - Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyExpWinLrn[u8LocalIndex][1] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyExpWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyBdcWinLrn =
         ( (Mf_adap_Bdc_corr_precal_uacn2[u8LocalIndex][1] - 32768)
         -  Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyBdcWinLrn[u8LocalIndex][1] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyBdcWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptShrt3                                */
/* !Description :  Cette fonction permet la Correction de la fenêtre courte   */
/*                 PMB, courte détente et courte PMH dépendant du régime      */
/*                 moteur.                                                    */
/* !Number      :  FCT8.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_TDC_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_TDC_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Exp_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Exp_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Bdc_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                          */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptShrt3(void)
{
   /* 01_apply_corr_bkpt_shrt_3 */
   uint8  u8LocalIndex;
   sint32 s32LocaltiDlyTDCWinLrn;
   sint32 s32LocaltiDlyExpWinLrn;
   sint32 s32LocaltiDlyBdcWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {

      s32LocaltiDlyTDCWinLrn =
         ( (Mf_adap_TDC_corr_precal_uacn2[u8LocalIndex][2] - 32768)
         - Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyTDCWinLrn[u8LocalIndex][2] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyTDCWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyExpWinLrn =
         ( (Mf_adap_Exp_corr_precal_uacn2[u8LocalIndex][2] - 32768)
         - Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyExpWinLrn[u8LocalIndex][2] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyExpWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyBdcWinLrn =
         ( (Mf_adap_Bdc_corr_precal_uacn2[u8LocalIndex][2] - 32768)
         - Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyBdcWinLrn[u8LocalIndex][2] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyBdcWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptShrt4                                */
/* !Description :  Cette fonction permet la Correction de la fenêtre courte   */
/*                 PMB, courte détente et courte PMH dépendant du régime      */
/*                 moteur.                                                    */
/* !Number      :  FCT8.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_TDC_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_TDC_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Exp_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Exp_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Bdc_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                          */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptShrt4(void)
{
   /* 01_apply_corr_bkpt_shrt_4 */
   uint8  u8LocalIndex;
   sint32 s32LocaltiDlyTDCWinLrn;
   sint32 s32LocaltiDlyExpWinLrn;
   sint32 s32LocaltiDlyBdcWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s32LocaltiDlyTDCWinLrn =
         ( (Mf_adap_TDC_corr_precal_uacn2[u8LocalIndex][3] - 32768)
         - Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyTDCWinLrn[u8LocalIndex][3] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyTDCWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyExpWinLrn =
         ( (Mf_adap_Exp_corr_precal_uacn2[u8LocalIndex][3] - 32768)
         - Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyExpWinLrn[u8LocalIndex][3] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyExpWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyBdcWinLrn =
         ( (Mf_adap_Bdc_corr_precal_uacn2[u8LocalIndex][3] - 32768)
         - Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyBdcWinLrn[u8LocalIndex][3] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyBdcWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptShrt5                                */
/* !Description :  Cette fonction permet la Correction de la fenêtre courte   */
/*                 PMB, courte détente et courte PMH dépendant du régime      */
/*                 moteur.                                                    */
/* !Number      :  FCT8.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_TDC_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_TDC_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Exp_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Exp_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Bdc_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                          */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptShrt5(void)
{
   /* 01_apply_corr_bkpt_shrt_5 */
   uint8  u8LocalIndex;
   sint32 s32LocaltiDlyTDCWinLrn;
   sint32 s32LocaltiDlyExpWinLrn;
   sint32 s32LocaltiDlyBdcWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {

      s32LocaltiDlyTDCWinLrn =
         ( (Mf_adap_TDC_corr_precal_uacn2[u8LocalIndex][4] - 32768)
         - Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyTDCWinLrn[u8LocalIndex][4] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyTDCWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyExpWinLrn =
         ( (Mf_adap_Exp_corr_precal_uacn2[u8LocalIndex][4] - 32768)
         - Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyExpWinLrn[u8LocalIndex][4] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyExpWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyBdcWinLrn =
         ( (Mf_adap_Bdc_corr_precal_uacn2[u8LocalIndex][4] - 32768)
         - Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyBdcWinLrn[u8LocalIndex][4] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyBdcWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptShrt6                                */
/* !Description :  Cette fonction permet la Correction de la fenêtre courte   */
/*                 PMB, courte détente et courte PMH dépendant du régime      */
/*                 moteur.                                                    */
/* !Number      :  FCT8.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_TDC_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_TDC_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Exp_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Exp_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Bdc_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                          */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptShrt6(void)
{
   /* 01_apply_corr_bkpt_shrt_6 */
   uint8  u8LocalIndex;
   sint32 s32LocaltiDlyTDCWinLrn;
   sint32 s32LocaltiDlyExpWinLrn;
   sint32 s32LocaltiDlyBdcWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s32LocaltiDlyTDCWinLrn =
         ( (Mf_adap_TDC_corr_precal_uacn2[u8LocalIndex][5] - 32768)
         -  Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyTDCWinLrn[u8LocalIndex][5] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyTDCWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyExpWinLrn =
         ( (Mf_adap_Exp_corr_precal_uacn2[u8LocalIndex][5] - 32768)
         - Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyExpWinLrn[u8LocalIndex][5] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyExpWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyBdcWinLrn =
         ( (Mf_adap_Bdc_corr_precal_uacn2[u8LocalIndex][5] - 32768)
         - Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyBdcWinLrn[u8LocalIndex][5] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyBdcWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptShrt7                                */
/* !Description :  Cette fonction permet la Correction de la fenêtre courte   */
/*                 PMB, courte détente et courte PMH dépendant du régime      */
/*                 moteur.                                                    */
/* !Number      :  FCT8.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_TDC_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_TDC_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Exp_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Exp_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Bdc_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                          */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptShrt7(void)
{
   /* 01_apply_corr_bkpt_shrt_7 */
   uint8  u8LocalIndex;
   sint32 s32LocaltiDlyTDCWinLrn;
   sint32 s32LocaltiDlyExpWinLrn;
   sint32 s32LocaltiDlyBdcWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s32LocaltiDlyTDCWinLrn =
         ( (Mf_adap_TDC_corr_precal_uacn2[u8LocalIndex][6] - 32768)
         - Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyTDCWinLrn[u8LocalIndex][6] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyTDCWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyExpWinLrn =
         ( (Mf_adap_Exp_corr_precal_uacn2[u8LocalIndex][6] - 32768)
         - Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyExpWinLrn[u8LocalIndex][6] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyExpWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyBdcWinLrn =
         ( (Mf_adap_Bdc_corr_precal_uacn2[u8LocalIndex][6] - 32768)
         - Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyBdcWinLrn[u8LocalIndex][6] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyBdcWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptShrt8                                */
/* !Description :  Cette fonction permet la Correction de la fenêtre courte   */
/*                 PMB, courte détente et courte PMH dépendant du régime      */
/*                 moteur.                                                    */
/* !Number      :  FCT8.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_TDC_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_TDC_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Exp_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Exp_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Bdc_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                          */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptShrt8(void)
{
   /* 01_apply_corr_bkpt_shrt_8 */
   uint8  u8LocalIndex;
   sint32 s32LocaltiDlyTDCWinLrn;
   sint32 s32LocaltiDlyExpWinLrn;
   sint32 s32LocaltiDlyBdcWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {

      s32LocaltiDlyTDCWinLrn =
         ( (Mf_adap_TDC_corr_precal_uacn2[u8LocalIndex][7] - 32768)
         - Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyTDCWinLrn[u8LocalIndex][7] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyTDCWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyExpWinLrn =
         ( (Mf_adap_Exp_corr_precal_uacn2[u8LocalIndex][7] - 32768)
         - Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyExpWinLrn[u8LocalIndex][7] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyExpWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyBdcWinLrn =
         ( (Mf_adap_Bdc_corr_precal_uacn2[u8LocalIndex][7] - 32768)
         - Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyBdcWinLrn[u8LocalIndex][7] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyBdcWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptShrt9                                */
/* !Description :  Cette fonction permet la Correction de la fenêtre courte   */
/*                 PMB, courte détente et courte PMH dépendant du régime      */
/*                 moteur.                                                    */
/* !Number      :  FCT8.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_TDC_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_TDC_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Exp_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Exp_delta_applied_uavn1[4];                          */
/*  input uint16 Mf_adap_Bdc_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                          */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCorrBkptShrt9(void)
{
   /* 01_apply_corr_bkpt_shrt_9 */
   uint8  u8LocalIndex;
   sint32 s32LocaltiDlyTDCWinLrn;
   sint32 s32LocaltiDlyExpWinLrn;
   sint32 s32LocaltiDlyBdcWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {

      s32LocaltiDlyTDCWinLrn =
         ( (Mf_adap_TDC_corr_precal_uacn2[u8LocalIndex][8] - 32768)
         - Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyTDCWinLrn[u8LocalIndex][8] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyTDCWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyExpWinLrn =
         ( (Mf_adap_Exp_corr_precal_uacn2[u8LocalIndex][8] - 32768)
         - Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyExpWinLrn[u8LocalIndex][8] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyExpWinLrn,
                                  -32768,
                                  32767);

      s32LocaltiDlyBdcWinLrn =
         ( (Mf_adap_Bdc_corr_precal_uacn2[u8LocalIndex][8] - 32768)
         - Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyBdcWinLrn[u8LocalIndex][8] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyBdcWinLrn,
                                  -32768,
                                  32767);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidRstCorrDelta                                 */
/* !Description :  Cette fonction permet d'initialiser le nombre              */
/*                 d'échantillons pour le calcul de la correction des         */
/*                 précalibrations.                                           */
/* !Number      :  FCT8.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 Mf_adap_delta_count_uavn1[4];                                */
/*  output sint16 Mf_adap_lw_delta_uavn1[4];                                  */
/*  output sint16 Mf_adap_TDC_delta_uavn1[4];                                 */
/*  output sint16 Mf_adap_Exp_delta_uavn1[4];                                 */
/*  output sint16 Mf_adap_Bdc_delta_uavn1[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidRstCorrDelta(void)
{
   /* MisfDftLrn/MisfDftLrn/09_apply_delta_precal/05_rst_corr_delta */
   uint8  u8LocalIndex;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      Mf_adap_delta_count_uavn1[u8LocalIndex] = 0;
      Mf_adap_lw_delta_uavn1[u8LocalIndex] = 0;
      Mf_adap_TDC_delta_uavn1[u8LocalIndex] = 0;
      Mf_adap_Exp_delta_uavn1[u8LocalIndex] = 0;
      Mf_adap_Bdc_delta_uavn1[u8LocalIndex] = 0;
   }
}
/*-------------------------------- end of file -------------------------------*/
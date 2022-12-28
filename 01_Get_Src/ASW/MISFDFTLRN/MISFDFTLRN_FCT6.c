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
/* !File            : MISFDFTLRN_FCT6.C                                       */
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
/*   1 / MISFDFTLRN_vidRangeControl                                           */
/*   2 / MISFDFTLRN_vidShrtAdapWrite                                          */
/*   3 / MISFDFTLRN_vidShrtAdapRaz                                            */
/*   4 / MISFDFTLRN_vidAdapRstUt                                              */
/*   5 / MISFDFTLRN_vidAdapRstNoUt                                            */
/*   6 / MISFDFTLRN_vidAdapRlzdCalc                                           */
/*   7 / MISFDFTLRN_vidApplyDeltaPrecal                                       */
/*   8 / MISFDFTLRN_vidApplyDeltaLw                                           */
/*   9 / MISFDFTLRN_vidAdapLwNoRlzd                                           */
/*   10 / MISFDFTLRN_vidCorrBkptLw1                                           */
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
/* !Function    :  MISFDFTLRN_vidRangeControl                                 */
/* !Description :  Ce module vérifie que les valeurs apprises des fenêtres    */
/*                 courtes  ne dépassent pas un seuil max calibrable, sinon un*/
/*                 défaut est levée et l’apprentissages des défauts Misfire   */
/*                 est inhibé.                                                */
/* !Number      :  FCT6.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input sint16 Misf_prm_tiDlyExpWinLrn[4][9];                               */
/*  input uint16 Mf_adap_Exp_range_max[4][9];                                 */
/*  input sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                               */
/*  input uint16 Mf_adap_Tdc_range_max[4][9];                                 */
/*  input sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                               */
/*  input uint16 Mf_adap_Bdc_range_max[4][9];                                 */
/*  output boolean Misf_bMonRunORng_ShrtWinLrnMax;                            */
/*  output boolean Misf_bDgoORng_ShrtWinLrnMax;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidRangeControl(void)
{
   uint8   u8LocalMisf_noCyl;
   uint8   u8LocalMfAdapBkptIndPrevUavn0;
   uint16  u16LocaltiDlyExpWinLrn;
   uint16  u16LocalMf_adap_Exp_range_max;
   uint16  u16LocaltiDlyTDCWinLrn;
   uint16  u16LocalMf_adap_Tdc_range_max;
   uint16  u16LocaltiDlyBdcWinLrn;
   uint16  u16LocalMf_adap_Bdc_range_max;
   sint16  s16LocalMfAdapBkptIndPrevUavn0;
   sint16  s16LocaltiDlyExpWinLrn;
   sint16  s16LocaltiDlyTDCWinLrn;
   sint16  s16LocaltiDlyBdcWinLrn;
   uint32  u32LocaltiDlyExpWinLrn;
   uint32  u32LocaltiDlyTDCWinLrn;
   uint32  u32LocaltiDlyBdcWinLrn;


   Misf_bMonRunORng_ShrtWinLrnMax = 1;

   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);

   switch(u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         s16LocalMfAdapBkptIndPrevUavn0 =
            (sint16)(Mf_adap_bkpt_ind_prev_uavn0 - 1);
         u8LocalMfAdapBkptIndPrevUavn0 =
            (uint8)MATHSRV_udtCLAMP(s16LocalMfAdapBkptIndPrevUavn0, 0, 8);
         s16LocaltiDlyExpWinLrn =
            Misf_prm_tiDlyExpWinLrn[u8LocalMisf_noCyl]
                                   [u8LocalMfAdapBkptIndPrevUavn0];
         u16LocaltiDlyExpWinLrn =
            (uint16)MATHSRV_udtABS(s16LocaltiDlyExpWinLrn);
         u32LocaltiDlyExpWinLrn = (uint32)(u16LocaltiDlyExpWinLrn * 2);
         u16LocalMf_adap_Exp_range_max =
            Mf_adap_Exp_range_max[u8LocalMisf_noCyl]
                                 [u8LocalMfAdapBkptIndPrevUavn0];
         s16LocaltiDlyTDCWinLrn =
            Misf_prm_tiDlyTDCWinLrn[u8LocalMisf_noCyl]
                                   [u8LocalMfAdapBkptIndPrevUavn0];
         u16LocaltiDlyTDCWinLrn =
            (uint16)MATHSRV_udtABS(s16LocaltiDlyTDCWinLrn);
         u32LocaltiDlyTDCWinLrn = (uint32)(u16LocaltiDlyTDCWinLrn * 2);
         u16LocalMf_adap_Tdc_range_max =
            Mf_adap_Tdc_range_max[u8LocalMisf_noCyl]
                                 [u8LocalMfAdapBkptIndPrevUavn0];
         s16LocaltiDlyBdcWinLrn =
            Misf_prm_tiDlyBdcWinLrn[u8LocalMisf_noCyl]
                                   [u8LocalMfAdapBkptIndPrevUavn0];
         u16LocaltiDlyBdcWinLrn =
            (uint16)MATHSRV_udtABS(s16LocaltiDlyBdcWinLrn);
         u32LocaltiDlyBdcWinLrn = (uint32)(u16LocaltiDlyBdcWinLrn * 2);
         u16LocalMf_adap_Bdc_range_max =
            Mf_adap_Bdc_range_max[u8LocalMisf_noCyl]
                                 [u8LocalMfAdapBkptIndPrevUavn0];
         if (  (u32LocaltiDlyExpWinLrn <= u16LocalMf_adap_Exp_range_max)
            && (u32LocaltiDlyTDCWinLrn <= u16LocalMf_adap_Tdc_range_max)
            && (u32LocaltiDlyBdcWinLrn <= u16LocalMf_adap_Bdc_range_max))
         {
            Misf_bDgoORng_ShrtWinLrnMax = 0;
         }
         else
         {
            Misf_bDgoORng_ShrtWinLrnMax = 1;
         }
         break;

      case 4:
      case 5:
         break;

         default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidShrtAdapWrite                                */
/* !Description :  Ce module écrit le nombre d’apprentissages dans la         */
/*                 cartographie de comptage, et enregistre la valeur apprise  */
/*                 dans la cartographie de correction en passant par un       */
/*                 filtre.                                                    */
/* !Number      :  FCT6.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input uint8 Mf_adap_shrt_corr_nxt_cnt_i;                                  */
/*  input uint8 Mf_adap_shrt_nb_mv_calc_uacn0;                                */
/*  input sint16 Mf_adap_Exp_err_mv_i_uavn1[4];                               */
/*  input sint16 Mf_adap_TDC_err_mv_i_uavn1[4];                               */
/*  input sint16 Mf_adap_Bdc_err_mv_i_uavn1[4];                               */
/*  input sint16 Misf_prm_tiDlyExpWinLrn[4][9];                               */
/*  input sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                               */
/*  input sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                               */
/*  input uint8 Mf_adap_Exp_corr_bkup_gain[9];                                */
/*  input uint8 Mf_adap_TDC_corr_bkup_gain[9];                                */
/*  input uint8 Mf_adap_Bdc_corr_bkup_gain[9];                                */
/*  output uint8 Mf_adap_shrt_corr_count_uavn1[9];                            */
/*  output uint8 Mf_adap_shrt_corr_nxt_cnt_i;                                 */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidShrtAdapWrite(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalExpGain;
   uint8  u8LocalTDCGain;
   uint8  u8LocalBdcGain;
   uint8  u8LocalMfAdapBkptIndPrevUavn0;
   sint16 s16LocalArrayExp[MISFDFTLRN_u8ARRAY_LEN];
   sint16 s16LocalArrayTDC[MISFDFTLRN_u8ARRAY_LEN];
   sint16 s16LocalArrayBdc[MISFDFTLRN_u8ARRAY_LEN];
   sint16 s16LocalMfAdapBkptIndPrevUavn0;
   sint16 s16LocalExpWinLrn;
   sint16 s16LocalTDCWinLrn;
   sint16 s16LocalBdcWinLrn;
   sint16 s16LocalExpErrMv;
   sint16 s16LocalTDCErrMv;
   sint16 s16LocalBdcErrMv;
   sint32 s32LocalExpnxtcnt;
   sint32 s32LocalTDCnxtcnt;
   sint32 s32LocalBdcnxtcnt;


   s16LocalMfAdapBkptIndPrevUavn0 = (sint16)(Mf_adap_bkpt_ind_prev_uavn0 - 1);
   u8LocalMfAdapBkptIndPrevUavn0 =
      (uint8)MATHSRV_udtCLAMP(s16LocalMfAdapBkptIndPrevUavn0, 0, 8);

   VEMS_vidSET1DArrayElement(Mf_adap_shrt_corr_count_uavn1,
                             u8LocalMfAdapBkptIndPrevUavn0,
                             Mf_adap_shrt_corr_nxt_cnt_i);

   if (Mf_adap_shrt_corr_nxt_cnt_i <= Mf_adap_shrt_nb_mv_calc_uacn0)
   {
      if (Mf_adap_shrt_corr_nxt_cnt_i <= 0)
      {
         for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
         {
            /* Fenêtre courte détente */
            s32LocalExpnxtcnt =
               (sint32)(-Mf_adap_Exp_err_mv_i_uavn1[u8LocalIndex]);
            s16LocalArrayExp[u8LocalIndex] =
               (sint16)MATHSRV_udtMIN(s32LocalExpnxtcnt, 32767);

            /* Fenêtre courte PMH */
            s32LocalTDCnxtcnt =
               (sint32)(-Mf_adap_TDC_err_mv_i_uavn1[u8LocalIndex]);
            s16LocalArrayTDC[u8LocalIndex] =
               (sint16)MATHSRV_udtMIN(s32LocalTDCnxtcnt, 32767);

            /* Fenêtre courte PMB */
            s32LocalBdcnxtcnt =
               (sint32)(-Mf_adap_Bdc_err_mv_i_uavn1[u8LocalIndex]);
            s16LocalArrayBdc[u8LocalIndex] =
               (sint16)MATHSRV_udtMIN(s32LocalBdcnxtcnt, 32767);
         }
      }
      else
      {
         for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
         {
            /* Fenêtre courte détente */
            s16LocalExpWinLrn =
               Misf_prm_tiDlyExpWinLrn[u8LocalIndex]
                                      [u8LocalMfAdapBkptIndPrevUavn0];
            s16LocalExpErrMv = Mf_adap_Exp_err_mv_i_uavn1[u8LocalIndex];
            s32LocalExpnxtcnt = (sint32)( ( ( s16LocalExpWinLrn
                                          * ( Mf_adap_shrt_corr_nxt_cnt_i
                                            - 1))
                                        - s16LocalExpErrMv)
                                      / Mf_adap_shrt_corr_nxt_cnt_i);

            s16LocalArrayExp[u8LocalIndex] = (sint16)s32LocalExpnxtcnt;

            /* Fenêtre courte PMH */
            s16LocalTDCWinLrn =
               Misf_prm_tiDlyTDCWinLrn[u8LocalIndex]
                                      [u8LocalMfAdapBkptIndPrevUavn0];
            s16LocalTDCErrMv = Mf_adap_TDC_err_mv_i_uavn1[u8LocalIndex];
            s32LocalTDCnxtcnt = (sint32)( ( ( s16LocalTDCWinLrn
                                          * ( Mf_adap_shrt_corr_nxt_cnt_i
                                            - 1))
                                        - s16LocalTDCErrMv)
                                      / Mf_adap_shrt_corr_nxt_cnt_i);

            s16LocalArrayTDC[u8LocalIndex] = (sint16)s32LocalTDCnxtcnt;

            /* Fenêtre courte PMB */
            s16LocalBdcWinLrn =
               Misf_prm_tiDlyBdcWinLrn[u8LocalIndex]
                                      [u8LocalMfAdapBkptIndPrevUavn0];
            s16LocalBdcErrMv = Mf_adap_Bdc_err_mv_i_uavn1[u8LocalIndex];
            s32LocalBdcnxtcnt = (sint32)( ( ( s16LocalBdcWinLrn
                                          * ( Mf_adap_shrt_corr_nxt_cnt_i
                                            - 1))
                                        - s16LocalBdcErrMv)
                                      / Mf_adap_shrt_corr_nxt_cnt_i);

            s16LocalArrayBdc[u8LocalIndex] = (sint16)s32LocalBdcnxtcnt;
         }
      }
   }
   else
   {
      for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
      {
         /* Fenêtre courte détente */
         s16LocalExpWinLrn =
            Misf_prm_tiDlyExpWinLrn[u8LocalIndex]
                                   [u8LocalMfAdapBkptIndPrevUavn0];
         s16LocalExpErrMv = Mf_adap_Exp_err_mv_i_uavn1[u8LocalIndex];
         u8LocalExpGain =
            Mf_adap_Exp_corr_bkup_gain[u8LocalMfAdapBkptIndPrevUavn0];
         s32LocalExpnxtcnt = (sint32)( ( ( s16LocalExpWinLrn
                                         * ( 256
                                           - u8LocalExpGain))
                                       - ( s16LocalExpErrMv
                                         * u8LocalExpGain))
                                     / 256);

         s16LocalArrayExp[u8LocalIndex] = (sint16)s32LocalExpnxtcnt;

         /* Fenêtre courte PMH */
         s16LocalTDCWinLrn =
            Misf_prm_tiDlyTDCWinLrn[u8LocalIndex]
                                   [u8LocalMfAdapBkptIndPrevUavn0];
         s16LocalTDCErrMv = Mf_adap_TDC_err_mv_i_uavn1[u8LocalIndex];
         u8LocalTDCGain =
            Mf_adap_TDC_corr_bkup_gain[u8LocalMfAdapBkptIndPrevUavn0];
         s32LocalTDCnxtcnt = (sint32)( ( ( s16LocalTDCWinLrn
                                         * ( 256
                                           - u8LocalTDCGain))
                                       - ( s16LocalTDCErrMv
                                         * u8LocalTDCGain))
                                     / 256);

         s16LocalArrayTDC[u8LocalIndex] = (sint16)s32LocalTDCnxtcnt;

         /* Fenêtre courte PMB */
         s16LocalBdcWinLrn =
            Misf_prm_tiDlyBdcWinLrn[u8LocalIndex]
                                   [u8LocalMfAdapBkptIndPrevUavn0];
         s16LocalBdcErrMv = Mf_adap_Bdc_err_mv_i_uavn1[u8LocalIndex];
         u8LocalBdcGain =
            Mf_adap_Bdc_corr_bkup_gain[u8LocalMfAdapBkptIndPrevUavn0];
         s32LocalBdcnxtcnt = (sint32)( ( ( s16LocalBdcWinLrn
                                         * ( 256
                                           - u8LocalBdcGain))
                                       - ( s16LocalBdcErrMv
                                         * u8LocalBdcGain))
                                     / 256);

         s16LocalArrayBdc[u8LocalIndex] = (sint16)s32LocalBdcnxtcnt;
      }
   }

   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      /* Fenêtre courte détente */
      Misf_prm_tiDlyExpWinLrn[u8LocalIndex][u8LocalMfAdapBkptIndPrevUavn0] =
         s16LocalArrayExp[u8LocalIndex];

      /* Fenêtre courte PMH */
      Misf_prm_tiDlyTDCWinLrn[u8LocalIndex][u8LocalMfAdapBkptIndPrevUavn0] =
         s16LocalArrayTDC[u8LocalIndex];

      /* Fenêtre courte PMB */
      Misf_prm_tiDlyBdcWinLrn[u8LocalIndex][u8LocalMfAdapBkptIndPrevUavn0] =
         s16LocalArrayBdc[u8LocalIndex];
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidShrtAdapRaz                                  */
/* !Description :  En cas de panne mémorisée, l’apprentissage des défauts     */
/*                 misfire est reseté. Toutes les variables d’apprentissage   */
/*                 prennent les valeurs par défaut.                           */
/* !Number      :  FCT6.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDFTLRN_vidAdapRstUt();                               */
/*  extf argret void MISFDFTLRN_vidAdapRstNoUt();                             */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*  output uint8 Mf_adap_shrt_corr_count_uavn1[9];                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidShrtAdapRaz(void)
{
   boolean bLocalSrv_bAcvPlaMod;
   uint8   u8LocalArrayShrtCorrCountUavn1[MISFDFTLRN_u8ARRAY_LENGTH];
   sint32  s32LocalIndex1;
   sint32  s32LocalIndex2;


   VEMS_vidGET(Srv_bAcvPlaMod, bLocalSrv_bAcvPlaMod);
   if (bLocalSrv_bAcvPlaMod != 0)
   {
      MISFDFTLRN_vidAdapRstUt();
   }
   else
   {
      MISFDFTLRN_vidAdapRstNoUt();
   }

   for (s32LocalIndex1 = 0; s32LocalIndex1 < 4; s32LocalIndex1++)
   {
      for (s32LocalIndex2 = 0; s32LocalIndex2 < 9; s32LocalIndex2++)
      {
         Misf_prm_tiDlyExpWinLrn[s32LocalIndex1][s32LocalIndex2] = 0;
         Misf_prm_tiDlyTDCWinLrn[s32LocalIndex1][s32LocalIndex2] = 0;
         Misf_prm_tiDlyBdcWinLrn[s32LocalIndex1][s32LocalIndex2] = 0;
      }
   }

   for (s32LocalIndex1 = 0; s32LocalIndex1 < 9; s32LocalIndex1++)
   {
      u8LocalArrayShrtCorrCountUavn1[s32LocalIndex1] = 0;
   }
   VEMS_vidSET1DArray(Mf_adap_shrt_corr_count_uavn1,
                      9,
                      u8LocalArrayShrtCorrCountUavn1);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapRstUt                                    */
/* !Description :  remise à 1 de Mf_adap_shrt_no_rlzd_UT_uavb0                */
/* !Number      :  FCT6.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_adap_shrt_no_rlzd_UT_uavb0;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapRstUt(void)
{
   VEMS_vidSET(Mf_adap_shrt_no_rlzd_UT_uavb0, 1);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapRstNoUt                                  */
/* !Description :  Remise à 1 de Mf_adap_shrt_no_rlzd_uavb0                   */
/* !Number      :  FCT6.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_adap_shrt_no_rlzd_uavb0;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapRstNoUt(void)
{
   VEMS_vidSET(Mf_adap_shrt_no_rlzd_uavb0, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapRlzdCalc                                 */
/* !Description :  Suite à la création du mode UT, un indicateur              */
/*                 d’apprentissage est créé. Celui-ci tient compte des        */
/*                 compteurs d’apprentissage des fenêtres longues et courtes. */
/* !Number      :  FCT6.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint8 Mf_adap_lw_corr_count_uavn1[9];                               */
/*  input uint8 Mf_adap_shrt_corr_count_uavn1[9];                             */
/*  input uint8 Mf_adap_win_count_thresh_uavn0;                               */
/*  output boolean Mf_adap_rlzd_uavb1[9];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapRlzdCalc(void)
{
   uint8  u8Locallw_corr_count_uavn1;
   uint8  u8Localshrt_corr_count_uavn1;
   sint32 s32LocalIndx;


   for (s32LocalIndx = 0; s32LocalIndx < 9; s32LocalIndx++)
   {
      VEMS_vidGET1DArrayElement(Mf_adap_lw_corr_count_uavn1,
                                s32LocalIndx,
                                u8Locallw_corr_count_uavn1);
      VEMS_vidGET1DArrayElement(Mf_adap_shrt_corr_count_uavn1,
                                s32LocalIndx,
                                u8Localshrt_corr_count_uavn1);
      if (  (u8Locallw_corr_count_uavn1 > Mf_adap_win_count_thresh_uavn0)
         || (u8Localshrt_corr_count_uavn1 > Mf_adap_win_count_thresh_uavn0))
      {
         VEMS_vidSET1DArrayElement(Mf_adap_rlzd_uavb1, s32LocalIndx, 1);
      }
      else
      {
         VEMS_vidSET1DArrayElement(Mf_adap_rlzd_uavb1, s32LocalIndx, 0);
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidApplyDeltaPrecal                             */
/* !Description :  Lorsque les conditions d’apprentissage ne sont plus        */
/*                 remplies, la moyenne de l’offset entre l’erreur filtrée et */
/*                 la précalibration est appliquée sur les adaptatifs dont le */
/*                 point de régime n’a jamais eu d’apprentissage.             */
/* !Number      :  FCT6.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidApplyDeltaLw();                            */
/*  extf argret void MISFDFTLRN_vidApplyDeltaShrt();                          */
/*  extf argret void MISFDFTLRN_vidRstCorrDelta();                            */
/*  input uint8 Mf_adap_lw_corr_count_uavn1[9];                               */
/*  input uint8 Mf_adap_shrt_corr_count_uavn1[9];                             */
/*  input uint8 Mf_adap_delta_count_uavn1[4];                                 */
/*  input uint8 Mf_adap_delta_count_min_uacn1[4];                             */
/*  input boolean Mf_adap_inh_corr_precal_uacb0;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidApplyDeltaPrecal(void)
{
   boolean bLocalResultlw;
   boolean bLocalResultshrt;
   boolean bLocalResultAnd;

   if (  (Mf_adap_lw_corr_count_uavn1[0] == 0)
      || (Mf_adap_lw_corr_count_uavn1[1] == 0)
      || (Mf_adap_lw_corr_count_uavn1[2] == 0)
      || (Mf_adap_lw_corr_count_uavn1[3] == 0)
      || (Mf_adap_lw_corr_count_uavn1[4] == 0)
      || (Mf_adap_lw_corr_count_uavn1[5] == 0)
      || (Mf_adap_lw_corr_count_uavn1[6] == 0)
      || (Mf_adap_lw_corr_count_uavn1[7] == 0)
      || (Mf_adap_lw_corr_count_uavn1[8] == 0))
   {
      bLocalResultlw = 1;
   }
   else
   {
      bLocalResultlw = 0;
   }

   if (  (Mf_adap_shrt_corr_count_uavn1[0] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[1] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[2] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[3] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[4] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[5] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[6] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[7] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[8] == 0))
   {
      bLocalResultshrt = 1;
   }
   else
   {
      bLocalResultshrt = 0;
   }

   if (  (  (Mf_adap_delta_count_uavn1[0] >= Mf_adap_delta_count_min_uacn1[0])
         || (Mf_adap_delta_count_uavn1[1] >= Mf_adap_delta_count_min_uacn1[1])
         || (Mf_adap_delta_count_uavn1[2] >= Mf_adap_delta_count_min_uacn1[2])
         || (Mf_adap_delta_count_uavn1[3] >= Mf_adap_delta_count_min_uacn1[3]))
      && (Mf_adap_inh_corr_precal_uacb0 == 0))
   {
      bLocalResultAnd = 1;

   }
   else
   {
      bLocalResultAnd = 0;
   }
   if ( (bLocalResultlw != 0)
      &&(bLocalResultAnd != 0))
   {
      MISFDFTLRN_vidApplyDeltaLw();
   }

   if ( (bLocalResultshrt != 0)
      &&(bLocalResultAnd != 0))
   {
      MISFDFTLRN_vidApplyDeltaShrt();
   }

   if ( (bLocalResultlw != 0)
      &&(bLocalResultshrt != 0))
   {
      MISFDFTLRN_vidRstCorrDelta ();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidApplyDeltaLw                                 */
/* !Description :  Cette fonction permet de donner l'Indicateur de non        */
/*                 apprentissage (en eeprom, fenêtres longues).               */
/* !Number      :  FCT6.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidAdapLwNoRlzd();                            */
/*  extf argret void MISFDFTLRN_vidCorrBkptLw1();                             */
/*  extf argret void MISFDFTLRN_vidCorrBkptLw2();                             */
/*  extf argret void MISFDFTLRN_vidCorrBkptLw3();                             */
/*  extf argret void MISFDFTLRN_vidCorrBkptLw4();                             */
/*  extf argret void MISFDFTLRN_vidCorrBkptLw5();                             */
/*  extf argret void MISFDFTLRN_vidCorrBkptLw6();                             */
/*  extf argret void MISFDFTLRN_vidCorrBkptLw7();                             */
/*  extf argret void MISFDFTLRN_vidCorrBkptLw8();                             */
/*  extf argret void MISFDFTLRN_vidCorrBkptLw9();                             */
/*  input boolean Mf_adap_inh_no_rlzd_uacn0;                                  */
/*  input sint16 Mf_adap_lw_delta_applied_uavn1[4];                           */
/*  input sint16 Mf_adap_lw_delta_uavn1[4];                                   */
/*  input uint8 Mf_adap_corr_gain_uacn0;                                      */
/*  input uint8 Mf_adap_lw_corr_count_uavn1[9];                               */
/*  output sint16 Mf_adap_lw_delta_applied_uavn1[4];                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidApplyDeltaLw(void)
{
   /* MisfDftLrn/MisfDftLrn/09_apply_delta_precal/01_apply_delta_lw  */
   uint8  u8LocalIndex;

   if (Mf_adap_inh_no_rlzd_uacn0 == 0)
   {
      MISFDFTLRN_vidAdapLwNoRlzd();
   }
   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      if (Mf_adap_lw_delta_applied_uavn1[u8LocalIndex] != 0)
      {
         Mf_adap_lw_delta_applied_uavn1[u8LocalIndex] =
            (sint16)( ( ( Mf_adap_lw_delta_uavn1[u8LocalIndex]
                        * Mf_adap_corr_gain_uacn0)
                      + ( Mf_adap_lw_delta_applied_uavn1[u8LocalIndex]
                        * (256 - Mf_adap_corr_gain_uacn0)))
                    / 256);
      }
      else
      {
         Mf_adap_lw_delta_applied_uavn1[u8LocalIndex] =
            Mf_adap_lw_delta_uavn1[u8LocalIndex];
      }
   }

   if (Mf_adap_lw_corr_count_uavn1[0] == 0)
   {
      MISFDFTLRN_vidCorrBkptLw1();
   }

   if (Mf_adap_lw_corr_count_uavn1[1] == 0)
   {
      MISFDFTLRN_vidCorrBkptLw2();
   }

   if (Mf_adap_lw_corr_count_uavn1[2] == 0)
   {
      MISFDFTLRN_vidCorrBkptLw3();
   }

   if (Mf_adap_lw_corr_count_uavn1[3] == 0)
   {
      MISFDFTLRN_vidCorrBkptLw4();
   }

   if (Mf_adap_lw_corr_count_uavn1[4] == 0)
   {
      MISFDFTLRN_vidCorrBkptLw5();
   }

   if (Mf_adap_lw_corr_count_uavn1[5] == 0)
   {
      MISFDFTLRN_vidCorrBkptLw6();
   }

   if (Mf_adap_lw_corr_count_uavn1[6] == 0)
   {
      MISFDFTLRN_vidCorrBkptLw7();
   }

   if (Mf_adap_lw_corr_count_uavn1[7] == 0)
   {
      MISFDFTLRN_vidCorrBkptLw8();
   }

   if (Mf_adap_lw_corr_count_uavn1[8] == 0)
   {
      MISFDFTLRN_vidCorrBkptLw9();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapLwNoRlzd                                 */
/* !Description :  Initialiser l'Indicateur de non apprentissage (en eeprom,  */
/*                 fenêtres longues) .                                        */
/* !Number      :  FCT6.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_adap_lw_no_rlzd_uavb0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapLwNoRlzd(void)
{
   VEMS_vidSET(Mf_adap_lw_no_rlzd_uavb0, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCorrBkptLw1                                  */
/* !Description :  cette fonction permet la Correction de la fenêtre longue   */
/*                 (appliqué au demi-tour 2)  dépendant du régime moteur      */
/* !Number      :  FCT6.10                                                    */
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
void MISFDFTLRN_vidCorrBkptLw1(void)
{
   /* 01_apply_corr_bkpt_lw_1 */
   uint8  u8LocalIndex;
   sint16 s16Locallwcorrprecaluacn2;
   sint32 s32LocaltiDlyLongWinLrn;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s16Locallwcorrprecaluacn2 =
         (sint16)(Mf_adap_lw_corr_precal_uacn2[u8LocalIndex][0] - 32768);
      s32LocaltiDlyLongWinLrn =
         ( s16Locallwcorrprecaluacn2
         - Mf_adap_lw_delta_applied_uavn1[u8LocalIndex]);
      Misf_prm_tiDlyLongWinLrn[u8LocalIndex][0] =
         (sint16)MATHSRV_udtCLAMP(s32LocaltiDlyLongWinLrn,
                                  -32768,
                                  32767);
   }
}
/*-------------------------------- end of file -------------------------------*/
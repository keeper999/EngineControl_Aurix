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
/* !File            : MISFDFTLRN_FCT1.C                                       */
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
/*   1 / MISFDFTLRN_vidInitOutput                                             */
/*   2 / MISFDFTLRN_vidEcuRst                                                 */
/*   3 / MISFDFTLRN_vidManuRst                                                */
/*   4 / MISFDFTLRN_vidMfAdap                                                 */
/*   5 / MISFDFTLRN_vidSynchroMfWindow                                        */
/*   6 / MISFDFTLRN_vidCondAdap                                               */
/*   7 / MISFDFTLRN_vidInitBkptInd                                            */
/*   8 / MISFDFTLRN_vidInitSortieModeUT                                       */
/*   9 / MISFDFTLRN_vidAutomateMisfLrn                                        */
/*   10 / MISFDFTLRN_vidCalcWinDelta                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5069555 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#068760                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDFTLRN/MISFDFTLRN_FCT1.C_$*/
/* $Revision::   1.20     $$Author::   achebino       $$Date::   06 Jul 2012 $*/
/* $Author::   achebino                               $$Date::   06 Jul 2012 $*/
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
#include "GDGAR.h"
#include "VEMS.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidInitOutput                                   */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  output boolean Mf_adap_ena_uavb0;                                         */
/*  output st98 Misf_stDftLrn;                                                */
/*  output boolean Mf_adap_calc_init_uavb0;                                   */
/*  output boolean Mf_adap_filt_calc_init_uavb0;                              */
/*  output st96 Misf_stLrnWin;                                                */
/*  output uint8 Mf_adap_bkpt_ind_uavn0;                                      */
/*  output uint32 MISFDFTLRN_u32tiDlyLongWinPrev;                             */
/*  output uint32 MISFDFTLRN_u32tiDlyExpWinPrev;                              */
/*  output uint32 MISFDFTLRN_u32tiDlyBdcWinPrev;                              */
/*  output uint32 MISFDFTLRN_u32tiDlyTDCWinPrev;                              */
/*  output uint8 Mf_adap_bkpt_ind_prev_uavn0;                                 */
/*  output boolean MISFDFTLRN_blwnorlzduavb0Prev;                             */
/*  output boolean MISFDFTLRN_bshrtnorlzduavb0Prev;                           */
/*  output boolean MISFDFTLRN_blwnorlzdUTuavb0Prev;                           */
/*  output boolean MISFDFTLRN_bshrtnorlzdUTuavb0Prv;                          */
/*  output boolean Misf_bDgoORng_ShrtWinLrn;                                  */
/*  output boolean Misf_bMonRunORng_ShrtWinLrn;                               */
/*  output boolean Misf_bDgoORng_LongWinLrn;                                  */
/*  output boolean Misf_bMonRunORng_LongWinLrn;                               */
/*  output boolean Misf_bDgoORng_LongWinLrnMax;                               */
/*  output boolean Misf_bDgoORng_ShrtWinLrnMax;                               */
/*  output boolean Misf_bMonRunORng_LongWinLrnMax;                            */
/*  output boolean Misf_bMonRunORng_ShrtWinLrnMax;                            */
/*  output uint8 Mf_adap_lw_sample_count_uavn1[4];                            */
/*  output uint8 Mf_adap_shrt_sample_count_uavn1[4];                          */
/*  output boolean MISFDFTLRN_bLwHystOut;                                     */
/*  output boolean MISFDFTLRN_bExpHystOut;                                    */
/*  output boolean MISFDFTLRN_bTDCHystOut;                                    */
/*  output boolean MISFDFTLRN_bBdcHystOut;                                    */
/*  output sint32 Mf_adap_lw_err_filt_uavn1[4];                               */
/*  output sint16 Mf_adap_lw_err_dif_raw_uavn1[4];                            */
/*  output sint16 Mf_adap_lw_err_dif_pos_uavn1[4];                            */
/*  output sint16 Mf_adap_lw_err_dif_neg_uavn1[4];                            */
/*  output uint16 Mf_adap_lw_err_dif_filt_uavn1[4];                           */
/*  output sint16 Mf_adap_lw_err_mv_i_uavn1[4];                               */
/*  output sint16 Mf_adap_TDC_err_filt_uavn1[4];                              */
/*  output sint16 Mf_adap_TDC_err_dif_raw_uavn1[4];                           */
/*  output sint16 Mf_adap_TDC_err_dif_pos_uavn1[4];                           */
/*  output sint16 Mf_adap_TDC_err_dif_neg_uavn1[4];                           */
/*  output uint16 Mf_adap_TDC_err_dif_filt_uavn1[4];                          */
/*  output sint16 Mf_adap_TDC_err_mv_i_uavn1[4];                              */
/*  output sint16 Mf_adap_Exp_err_filt_uavn1[4];                              */
/*  output sint16 Mf_adap_Exp_err_dif_raw_uavn1[4];                           */
/*  output sint16 Mf_adap_Exp_err_dif_pos_uavn1[4];                           */
/*  output sint16 Mf_adap_Exp_err_dif_neg_uavn1[4];                           */
/*  output uint16 Mf_adap_Exp_err_dif_filt_uavn1[4];                          */
/*  output sint16 Mf_adap_Exp_err_mv_i_uavn1[4];                              */
/*  output sint16 Mf_adap_Bdc_err_filt_uavn1[4];                              */
/*  output sint16 Mf_adap_Bdc_err_dif_raw_uavn1[4];                           */
/*  output sint16 Mf_adap_Bdc_err_dif_pos_uavn1[4];                           */
/*  output sint16 Mf_adap_Bdc_err_dif_neg_uavn1[4];                           */
/*  output uint16 Mf_adap_Bdc_err_dif_filt_uavn1[4];                          */
/*  output sint16 Mf_adap_Bdc_err_mv_i_uavn1[4];                              */
/*  output sint32 Misf_LongWinErrRaw[4];                                      */
/*  output sint16 Misf_TDCWinErrRaw[4];                                       */
/*  output sint16 Misf_ExpWinErrRaw[4];                                       */
/*  output sint16 Misf_BdcWinErrRaw[4];                                       */
/*  output boolean Mf_adap_lw_cond_ok_uavb0;                                  */
/*  output boolean Mf_adap_TDC_cond_ok_uavb0;                                 */
/*  output boolean Mf_adap_Exp_cond_ok_uavb0;                                 */
/*  output boolean Mf_adap_Bdc_cond_ok_uavb0;                                 */
/*  output sint16 Mf_adap_lw_corr_precal_uavn0;                               */
/*  output sint16 Misf_prm_tiDlyExpWinLrnCyl1[9];                             */
/*  output sint16 Misf_prm_tiDlyExpWinLrnCyl2[9];                             */
/*  output sint16 Misf_prm_tiDlyExpWinLrnCyl3[9];                             */
/*  output sint16 Misf_prm_tiDlyExpWinLrnCyl4[9];                             */
/*  output sint16 Misf_prm_tiDlyTDCWinLrnCyl1[9];                             */
/*  output sint16 Misf_prm_tiDlyTDCWinLrnCyl2[9];                             */
/*  output sint16 Misf_prm_tiDlyTDCWinLrnCyl3[9];                             */
/*  output sint16 Misf_prm_tiDlyTDCWinLrnCyl4[9];                             */
/*  output sint16 Misf_prm_tiDlyBdcWinLrnCyl1[9];                             */
/*  output sint16 Misf_prm_tiDlyBdcWinLrnCyl2[9];                             */
/*  output sint16 Misf_prm_tiDlyBdcWinLrnCyl3[9];                             */
/*  output sint16 Misf_prm_tiDlyBdcWinLrnCyl4[9];                             */
/*  output sint16 Misf_prm_tiDlyLongWinLrnCyl1[9];                            */
/*  output sint16 Misf_prm_tiDlyLongWinLrnCyl2[9];                            */
/*  output sint16 Misf_prm_tiDlyLongWinLrnCyl3[9];                            */
/*  output sint16 Misf_prm_tiDlyLongWinLrnCyl4[9];                            */
/*  output boolean Mf_adap_lw_cond_ok_uavb1[4];                               */
/*  output boolean Mf_adap_Exp_cond_ok_uavb1[4];                              */
/*  output boolean Mf_adap_Bdc_cond_ok_uavb1[4];                              */
/*  output boolean Mf_adap_TDC_cond_ok_uavb1[4];                              */
/*  output boolean MISFDFTLRN_bSrvAcvPlaModPrev;                              */
/*  output boolean MISFDFTLRN_bFRMInhWinLrnORngPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidInitOutput(void)
{
   uint8  u8LocalIndex;
   sint16 s16LocalWinLrnCylTab[9];
   sint32 s32LocalIndx;

   /* State machine initialisation */
   Mf_adap_ena_uavb0 = 0;
   Misf_stDftLrn = CALC_INIT;
   Mf_adap_calc_init_uavb0 = 1;
   Mf_adap_filt_calc_init_uavb0 = 1;

   /* State machine initialisation */
   Misf_stLrnWin = LRN_CALC_INIT;

   /* Output intialisation */
   VEMS_vidSET(Mf_adap_bkpt_ind_uavn0, 0);

   /* Previous intialisation */
   MISFDFTLRN_u32tiDlyLongWinPrev = 0;
   MISFDFTLRN_u32tiDlyExpWinPrev = 0;
   MISFDFTLRN_u32tiDlyBdcWinPrev = 0;
   MISFDFTLRN_u32tiDlyTDCWinPrev = 0;
   Mf_adap_bkpt_ind_prev_uavn0 = 0;
   MISFDFTLRN_blwnorlzduavb0Prev = 1;
   MISFDFTLRN_bshrtnorlzduavb0Prev = 1;
   MISFDFTLRN_blwnorlzdUTuavb0Prev = 1;
   MISFDFTLRN_bshrtnorlzdUTuavb0Prv = 1;

   /* Intialisation of GDU variable*/
   Misf_bDgoORng_ShrtWinLrn = 0;
   Misf_bMonRunORng_ShrtWinLrn = 0;
   Misf_bDgoORng_LongWinLrn = 0;
   Misf_bMonRunORng_LongWinLrn = 0;
   Misf_bDgoORng_LongWinLrnMax = 0;
   Misf_bDgoORng_ShrtWinLrnMax = 0;
   Misf_bMonRunORng_LongWinLrnMax = 0;
   Misf_bMonRunORng_ShrtWinLrnMax = 0;

   /* Counter initialisation */
   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      Mf_adap_lw_sample_count_uavn1[u8LocalIndex] = 0;
      Mf_adap_shrt_sample_count_uavn1[u8LocalIndex] = 0;
   }

   /* output hysterisis initialisation */
   MISFDFTLRN_bLwHystOut = 0;
   MISFDFTLRN_bExpHystOut = 0;
   MISFDFTLRN_bTDCHystOut = 0;
   MISFDFTLRN_bBdcHystOut = 0;

   /* Internal variables initialisation*/
   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      Mf_adap_lw_err_filt_uavn1[u8LocalIndex] = 0;
      Mf_adap_lw_err_dif_raw_uavn1[u8LocalIndex] = 0;
      Mf_adap_lw_err_dif_pos_uavn1[u8LocalIndex] = 0;
      Mf_adap_lw_err_dif_neg_uavn1[u8LocalIndex] = 0;
      Mf_adap_lw_err_dif_filt_uavn1[u8LocalIndex] = 0;
      Mf_adap_lw_err_mv_i_uavn1[u8LocalIndex] = 0;

      Mf_adap_TDC_err_filt_uavn1[u8LocalIndex] = 0;
      Mf_adap_TDC_err_dif_raw_uavn1[u8LocalIndex] = 0;
      Mf_adap_TDC_err_dif_pos_uavn1[u8LocalIndex] = 0;
      Mf_adap_TDC_err_dif_neg_uavn1[u8LocalIndex] = 0;
      Mf_adap_TDC_err_dif_filt_uavn1[u8LocalIndex] = 0;
      Mf_adap_TDC_err_mv_i_uavn1[u8LocalIndex] = 0;

      Mf_adap_Exp_err_filt_uavn1[u8LocalIndex] = 0;
      Mf_adap_Exp_err_dif_raw_uavn1[u8LocalIndex] = 0;
      Mf_adap_Exp_err_dif_pos_uavn1[u8LocalIndex] = 0;
      Mf_adap_Exp_err_dif_neg_uavn1[u8LocalIndex] = 0;
      Mf_adap_Exp_err_dif_filt_uavn1[u8LocalIndex] = 0;
      Mf_adap_Exp_err_mv_i_uavn1[u8LocalIndex] = 0;

      Mf_adap_Bdc_err_filt_uavn1[u8LocalIndex] = 0;
      Mf_adap_Bdc_err_dif_raw_uavn1[u8LocalIndex] = 0;
      Mf_adap_Bdc_err_dif_pos_uavn1[u8LocalIndex] = 0;
      Mf_adap_Bdc_err_dif_neg_uavn1[u8LocalIndex] = 0;
      Mf_adap_Bdc_err_dif_filt_uavn1[u8LocalIndex] = 0;
      Mf_adap_Bdc_err_mv_i_uavn1[u8LocalIndex] = 0;
   }

   /* initialisation of internal variables */
   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      Misf_LongWinErrRaw[u8LocalIndex] = 0;
      Misf_TDCWinErrRaw[u8LocalIndex] = 0;
      Misf_ExpWinErrRaw[u8LocalIndex] = 0;
      Misf_BdcWinErrRaw[u8LocalIndex] = 0;
   }

   Mf_adap_lw_cond_ok_uavb0 = 0;
   Mf_adap_TDC_cond_ok_uavb0 = 0;
   Mf_adap_Exp_cond_ok_uavb0 = 0;
   Mf_adap_Bdc_cond_ok_uavb0 = 0;
   Mf_adap_lw_corr_precal_uavn0 = 0;

   for (s32LocalIndx = 0; s32LocalIndx < 9; s32LocalIndx++)
   {
      s16LocalWinLrnCylTab[s32LocalIndx] = 0;
   }

   /* Fenêtre courte détente */
   VEMS_vidSET1DArray(Misf_prm_tiDlyExpWinLrnCyl1, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyExpWinLrnCyl2, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyExpWinLrnCyl3, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyExpWinLrnCyl4, 9, s16LocalWinLrnCylTab);

   /* Fenêtre courte PMH */
   VEMS_vidSET1DArray(Misf_prm_tiDlyTDCWinLrnCyl1, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyTDCWinLrnCyl2, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyTDCWinLrnCyl3, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyTDCWinLrnCyl4, 9, s16LocalWinLrnCylTab);

   /* Fenêtre courte PMB */
   VEMS_vidSET1DArray(Misf_prm_tiDlyBdcWinLrnCyl1, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyBdcWinLrnCyl2, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyBdcWinLrnCyl3, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyBdcWinLrnCyl4, 9, s16LocalWinLrnCylTab);

   /* Fenêtre longue (appliqué au demi-tour 2) */
   VEMS_vidSET1DArray(Misf_prm_tiDlyLongWinLrnCyl1, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyLongWinLrnCyl2, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyLongWinLrnCyl3, 9, s16LocalWinLrnCylTab);
   VEMS_vidSET1DArray(Misf_prm_tiDlyLongWinLrnCyl4, 9, s16LocalWinLrnCylTab);

   for (u8LocalIndex = 1; u8LocalIndex < 4; u8LocalIndex++)
   {
      Mf_adap_lw_cond_ok_uavb1[u8LocalIndex] = 0;
      Mf_adap_Exp_cond_ok_uavb1[u8LocalIndex] = 0;
      Mf_adap_Bdc_cond_ok_uavb1[u8LocalIndex] = 0;
      Mf_adap_TDC_cond_ok_uavb1[u8LocalIndex] = 0;
   }

   MISFDFTLRN_bSrvAcvPlaModPrev = 0;
   MISFDFTLRN_bFRMInhWinLrnORngPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidEcuRst                                       */
/* !Description :  Initialisation des conditions remplies pour apprentissage  */
/*                 MISFIRE.                                                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Mf_adap_lw_corr_count_uavn1[9];                               */
/*  input uint8 Mf_adap_shrt_corr_count_uavn1[9];                             */
/*  input uint8 Mf_adap_win_count_thresh_uavn0;                               */
/*  input boolean Mf_adap_lw_no_rlzd_UT_uavb0;                                */
/*  input boolean Mf_adap_shrt_no_rlzd_UT_uavb0;                              */
/*  input uint8 Ext_noCylEng;                                                 */
/*  output boolean Mf_adap_rlzd_uavb1[9];                                     */
/*  output boolean Mf_adap_no_rlzd_UT_uavb0;                                  */
/*  output boolean Mf_adap_lw_cond_ok_uavb1[4];                               */
/*  output boolean Mf_adap_Exp_cond_ok_uavb1[4];                              */
/*  output boolean Mf_adap_Bdc_cond_ok_uavb1[4];                              */
/*  output boolean Mf_adap_TDC_cond_ok_uavb1[4];                              */
/*  output uint8 Mf_adap_delta_count_uavn1[4];                                */
/*  output sint16 Mf_adap_lw_delta_uavn1[4];                                  */
/*  output sint16 Mf_adap_TDC_delta_uavn1[4];                                 */
/*  output sint16 Mf_adap_Exp_delta_uavn1[4];                                 */
/*  output sint16 Mf_adap_Bdc_delta_uavn1[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidEcuRst(void)
{
   boolean bLocallw_no_rlzd_UT_uavb0;
   boolean bLocalshrt_no_rlzd_UT_uavb0;
   uint8   u8LocalExt_noCylEng;
   uint8   u8LocalIndex;
   uint8   u8LocalArraylw_corr_count_uavn1[9];
   uint8   u8LocalArrayshrt_corrcount_uavn1[9];


   VEMS_vidGET1DArray(Mf_adap_lw_corr_count_uavn1,
                      9,
                      u8LocalArraylw_corr_count_uavn1);
   VEMS_vidGET1DArray(Mf_adap_shrt_corr_count_uavn1,
                      9,
                      u8LocalArrayshrt_corrcount_uavn1);
   for(u8LocalIndex = 0; u8LocalIndex < 9; u8LocalIndex++)
   {
      if (  ( u8LocalArraylw_corr_count_uavn1[u8LocalIndex]
            > Mf_adap_win_count_thresh_uavn0)
         || ( u8LocalArrayshrt_corrcount_uavn1[u8LocalIndex]
            > Mf_adap_win_count_thresh_uavn0))
      {
         VEMS_vidSET1DArrayElement(Mf_adap_rlzd_uavb1, u8LocalIndex, 1);
      }
      else
      {
         VEMS_vidSET1DArrayElement(Mf_adap_rlzd_uavb1, u8LocalIndex, 0);
      }
   }

   VEMS_vidGET(Mf_adap_lw_no_rlzd_UT_uavb0, bLocallw_no_rlzd_UT_uavb0);
   VEMS_vidGET(Mf_adap_shrt_no_rlzd_UT_uavb0, bLocalshrt_no_rlzd_UT_uavb0);
   if (  (bLocallw_no_rlzd_UT_uavb0 != 0)
      && (bLocalshrt_no_rlzd_UT_uavb0 != 0))
   {
      VEMS_vidSET(Mf_adap_no_rlzd_UT_uavb0, 1);
   }
   else
   {
      VEMS_vidSET(Mf_adap_no_rlzd_UT_uavb0, 0);
   }

   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   Mf_adap_lw_cond_ok_uavb1[0] = 1;
   Mf_adap_Exp_cond_ok_uavb1[0] = 1;
   Mf_adap_Bdc_cond_ok_uavb1[0] = 1;
   Mf_adap_TDC_cond_ok_uavb1[0] = 1;

   if  (u8LocalExt_noCylEng < 4)
   {
      Mf_adap_lw_cond_ok_uavb1[3] = 1;
      Mf_adap_Exp_cond_ok_uavb1[3] = 1;
      Mf_adap_Bdc_cond_ok_uavb1[3] = 1;
      Mf_adap_TDC_cond_ok_uavb1[3] = 1;

      if (u8LocalExt_noCylEng < 3)
      {
         Mf_adap_lw_cond_ok_uavb1[2] = 1;
         Mf_adap_Exp_cond_ok_uavb1[2] = 1;
         Mf_adap_Bdc_cond_ok_uavb1[2] = 1;
         Mf_adap_TDC_cond_ok_uavb1[2] = 1;
      }

      if (u8LocalExt_noCylEng < 2)
      {
         Mf_adap_lw_cond_ok_uavb1[1] = 1;
         Mf_adap_Exp_cond_ok_uavb1[1] = 1;
         Mf_adap_Bdc_cond_ok_uavb1[1] = 1;
         Mf_adap_TDC_cond_ok_uavb1[1] = 1;
      }
   }
   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      Mf_adap_delta_count_uavn1[u8LocalIndex] = 0;
      Mf_adap_lw_delta_uavn1[u8LocalIndex] = 0;
      Mf_adap_TDC_delta_uavn1[u8LocalIndex] = 0;
      Mf_adap_Exp_delta_uavn1[u8LocalIndex] = 0;
      Mf_adap_Bdc_delta_uavn1[u8LocalIndex] = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidManuRst                                      */
/* !Description :  Ce bloc permet de réaliser une mise à zéro des adaptatifs, */
/*                 des compteurs d’apprentissages et des booléens indiquant un*/
/*                 apprentissage effectué.                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  output boolean Mf_adap_lw_no_rlzd_uavb0;                                  */
/*  output boolean Mf_adap_shrt_no_rlzd_uavb0;                                */
/*  output boolean Mf_adap_no_rlzd_UT_uavb0;                                  */
/*  output boolean Mf_adap_shrt_no_rlzd_UT_uavb0;                             */
/*  output boolean Mf_adap_lw_no_rlzd_UT_uavb0;                               */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*  output sint16 Mf_adap_lw_delta_applied_uavn1[4];                          */
/*  output sint16 Mf_adap_Exp_delta_applied_uavn1[4];                         */
/*  output sint16 Mf_adap_TDC_delta_applied_uavn1[4];                         */
/*  output sint16 Mf_adap_Bdc_delta_applied_uavn1[4];                         */
/*  output uint8 Mf_adap_lw_corr_count_uavn1[9];                              */
/*  output uint8 Mf_adap_shrt_corr_count_uavn1[9];                            */
/*  output boolean Mf_adap_rlzd_uavb1[9];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidManuRst(void)
{
   uint8   u8LocalIndex;
   uint8   u8LocalIndexRow;
   uint8   u8LocalIndexCol;
   uint8   u8LocalArrayLwCorrCountUavn1[MISFDFTLRN_u8ARRAY_LENGTH];


   VEMS_vidSET(Mf_adap_lw_no_rlzd_uavb0, 1);
   VEMS_vidSET(Mf_adap_shrt_no_rlzd_uavb0, 1);
   VEMS_vidSET(Mf_adap_no_rlzd_UT_uavb0, 1);
   VEMS_vidSET(Mf_adap_shrt_no_rlzd_UT_uavb0, 1);
   VEMS_vidSET(Mf_adap_lw_no_rlzd_UT_uavb0, 1);

   for (u8LocalIndexRow = 0; u8LocalIndexRow < 4; u8LocalIndexRow++)
   {
      for (u8LocalIndexCol = 0; u8LocalIndexCol < 9; u8LocalIndexCol++)
      {
         Misf_prm_tiDlyExpWinLrn[u8LocalIndexRow][u8LocalIndexCol] = 0;
         Misf_prm_tiDlyTDCWinLrn[u8LocalIndexRow][u8LocalIndexCol] = 0;
         Misf_prm_tiDlyBdcWinLrn[u8LocalIndexRow][u8LocalIndexCol] = 0;
         Misf_prm_tiDlyLongWinLrn[u8LocalIndexRow][u8LocalIndexCol] = 0;
      }
   }

   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      Mf_adap_lw_delta_applied_uavn1[u8LocalIndex] = 0;
      Mf_adap_Exp_delta_applied_uavn1[u8LocalIndex] = 0;
      Mf_adap_TDC_delta_applied_uavn1[u8LocalIndex] = 0;
      Mf_adap_Bdc_delta_applied_uavn1[u8LocalIndex] = 0;
   }
   for (u8LocalIndex = 0; u8LocalIndex < 9; u8LocalIndex++)
   {
      u8LocalArrayLwCorrCountUavn1[u8LocalIndex] = 0;
   }
   VEMS_vidSET1DArray(Mf_adap_lw_corr_count_uavn1,
                      9,
                      u8LocalArrayLwCorrCountUavn1);
   VEMS_vidSET1DArray(Mf_adap_shrt_corr_count_uavn1,
                      9,
                      u8LocalArrayLwCorrCountUavn1);
   VEMS_vidSET1DArray(Mf_adap_rlzd_uavb1, 9, u8LocalArrayLwCorrCountUavn1);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidMfAdap                                       */
/* !Description :  appel des modules de la fenêtre sur laquelle le calcul va  */
/*                 être réalisé, les conditions de stabilité moteur de        */
/*                 l’apprentissage et l'automate de la stratégie              */
/*                 d'apprentissage des défauts.                               */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidSynchroMfWindow();                         */
/*  extf argret void MISFDFTLRN_vidCondAdap();                                */
/*  extf argret void MISFDFTLRN_vidInitBkptInd();                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDFTLRN_vidInitSortieModeUT();                        */
/*  input boolean Mf_adap_ena_uavb0;                                          */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  input boolean MISFDFTLRN_bSrvAcvPlaModPrev;                               */
/*  output boolean MISFDFTLRN_bSrvAcvPlaModPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidMfAdap(void)
{

   boolean bLocalSrv_bAcvPlaMod;


   MISFDFTLRN_vidSynchroMfWindow();
   MISFDFTLRN_vidCondAdap();
   if (Mf_adap_ena_uavb0 == 0)
   {
      MISFDFTLRN_vidInitBkptInd();
   }
   VEMS_vidGET(Srv_bAcvPlaMod, bLocalSrv_bAcvPlaMod);
   if (  (bLocalSrv_bAcvPlaMod == 0)
      && (MISFDFTLRN_bSrvAcvPlaModPrev != 0))
   {
      MISFDFTLRN_vidInitSortieModeUT();
   }
   MISFDFTLRN_bSrvAcvPlaModPrev = bLocalSrv_bAcvPlaMod;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidSynchroMfWindow                              */
/* !Description :  Calcul du numéro physique du cylindre en cours de          */
/*                 diagnostic Misfire.                                        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_ctTDC;                                                    */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint8 Table_cyl_phys_ordre_allumage[6];                             */
/*  output uint8 Misf_noCylIg;                                                */
/*  output uint8 Misf_noCyl;                                                  */
/*  output boolean Mf_win_1_uavb0;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidSynchroMfWindow(void)
{
   uint8  u8LocalExtctTDC;
   uint8  u8LocalExt_noCylEng;
   uint8  u8LocalExtnoCylEng;
   uint8  u8LocalMisf_noCylIg;
   uint8  u8LocalCylPhyOrdAll;
   uint8  u8LocalMisf_noCyl;
   uint16 u16LocalExtCyl;


   VEMS_vidGET(Ext_ctTDC, u8LocalExtctTDC);
   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   u8LocalExtnoCylEng = (uint8)MATHSRV_udtCLAMP(u8LocalExt_noCylEng, 1, 12);

   u16LocalExtCyl = (uint16)((u8LocalExtctTDC + u8LocalExtnoCylEng) - 1);
   u8LocalMisf_noCylIg = (uint8)(u16LocalExtCyl % u8LocalExtnoCylEng);

   u8LocalMisf_noCylIg = (uint8)MATHSRV_udtMIN(u8LocalMisf_noCylIg, 5);

   VEMS_vidSET(Misf_noCylIg, u8LocalMisf_noCylIg);

   u8LocalCylPhyOrdAll = Table_cyl_phys_ordre_allumage[u8LocalMisf_noCylIg];

   u8LocalMisf_noCyl = (uint8)MATHSRV_udtMIN(u8LocalCylPhyOrdAll, 5);
   VEMS_vidSET(Misf_noCyl, u8LocalMisf_noCyl);

   if (u8LocalMisf_noCyl == 0)
   {
      VEMS_vidSET(Mf_win_1_uavb0, 1);
   }
   else
   {
      VEMS_vidSET(Mf_win_1_uavb0, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCondAdap                                     */
/* !Description :  Conditions moteur pour permettre l’apprentissage des       */
/*                 défauts misfire                                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Regime_moteur_32;                                             */
/*  input sint8 Engine_speed_derivate;                                        */
/*  input boolean Gear_engaged_mf_not_stable;                                 */
/*  input boolean Misf_bAcqWinOK;                                             */
/*  input boolean Presence_bva;                                               */
/*  input uint8 Gear_engaged;                                                 */
/*  input boolean CoPt_bSIP;                                                  */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  input sint16 Mf_adap_tco_min_ut_uacn0;                                    */
/*  input sint16 Mf_adap_tco_min_uacn0;                                       */
/*  input boolean Table_boite_vitesse_Misf_UT_inh[7];                         */
/*  input boolean Table_boite_vitesse_Misf_inh[7];                            */
/*  input uint8 Mf_adap_n_min_uacn0;                                          */
/*  input uint8 Mf_adap_n_max_uacn0;                                          */
/*  input sint8 Mf_adap_n_derv_min_uacn0;                                     */
/*  input sint8 Mf_adap_n_derv_max_uacn0;                                     */
/*  input boolean Mf_adap_manu_inh_uacb0;                                     */
/*  input boolean MISFDFTLRN_bFRMInhWinLrnORngPrev;                           */
/*  output boolean Mf_adap_ena_uavb0;                                         */
/*  output boolean MISFDFTLRN_bFRMInhWinLrnORngPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCondAdap(void)
{
   boolean bLocalGear_engaged_mf_not_stable;
   boolean bLocalMisf_bAcqWinOK;
   boolean bLocalCoPt_bSIP;
   boolean bLocalPresence_bva;
   boolean bLocalSrv_bAcvPlaMod;
   boolean bLocalFRM_bInhWinLrnORng;
   boolean bLocalMisf_UT_inh;
   boolean bLocalMisf_inh;
   boolean bLocalboite_vitesse_Misf;
   uint8   u8LocalEngineRunningState;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalGear_engaged;
   sint8   s8LocalEngine_speed_derivate;
   sint16  s16Localn_min_uacn0;
   sint32  s32Localn_min_uacn0;


   VEMS_vidGET(Engine_running_state, u8LocalEngineRunningState);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Engine_speed_derivate, s8LocalEngine_speed_derivate);
   VEMS_vidGET(Gear_engaged_mf_not_stable, bLocalGear_engaged_mf_not_stable);
   VEMS_vidGET(Misf_bAcqWinOK, bLocalMisf_bAcqWinOK);
   VEMS_vidGET(Presence_bva, bLocalPresence_bva);
   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);
   VEMS_vidGET(CoPt_bSIP, bLocalCoPt_bSIP);
   VEMS_vidGET(Srv_bAcvPlaMod, bLocalSrv_bAcvPlaMod);

   if (  (bLocalPresence_bva == 0)
      || (bLocalCoPt_bSIP == 0))
   {
      bLocalCoPt_bSIP = 1;
   }
   else
   {
      bLocalCoPt_bSIP = 0;
   }

   if (bLocalSrv_bAcvPlaMod != 0)
   {
      s16Localn_min_uacn0 = Mf_adap_tco_min_ut_uacn0;
   }
   else
   {
      s16Localn_min_uacn0 = Mf_adap_tco_min_uacn0;
   }
   s32Localn_min_uacn0 = (sint32)(s16Localn_min_uacn0 + 64);

   bLocalFRM_bInhWinLrnORng = GDGAR_bGetFRM(FRM_FRM_INHWINLRNORNG);
   u8LocalGear_engaged = (uint8)MATHSRV_udtMIN(u8LocalGear_engaged, 6);

   bLocalMisf_UT_inh = Table_boite_vitesse_Misf_UT_inh[u8LocalGear_engaged];
   bLocalMisf_inh = Table_boite_vitesse_Misf_inh[u8LocalGear_engaged];
   if (bLocalSrv_bAcvPlaMod != 0)
   {
      bLocalboite_vitesse_Misf = bLocalMisf_UT_inh;
   }
   else
   {
      bLocalboite_vitesse_Misf = bLocalMisf_inh;
   }

   if (  (u8LocalEngineRunningState == ERUN_ENGINE_OVERRUN_FCO)
      && (u8LocalTemperature_eau >= s32Localn_min_uacn0)
      && (u8LocalRegime_moteur_32 >= Mf_adap_n_min_uacn0)
      && (u8LocalRegime_moteur_32 <= Mf_adap_n_max_uacn0)
      && (s8LocalEngine_speed_derivate >= Mf_adap_n_derv_min_uacn0)
      && (s8LocalEngine_speed_derivate <= Mf_adap_n_derv_max_uacn0)
      && (bLocalCoPt_bSIP != 0)
      && (bLocalGear_engaged_mf_not_stable == 0)
      && (Mf_adap_manu_inh_uacb0 == 0)
      && (bLocalMisf_bAcqWinOK != 0)
      && (MISFDFTLRN_bFRMInhWinLrnORngPrev == 0)
      && (bLocalboite_vitesse_Misf != 0))
   {
      Mf_adap_ena_uavb0 = 1;
   }
   else
   {
      Mf_adap_ena_uavb0 = 0;
   }

   MISFDFTLRN_bFRMInhWinLrnORngPrev = bLocalFRM_bInhWinLrnORng;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidInitBkptInd                                  */
/* !Description :  initialisation de Mf_adap_bkpt_ind_uavn0                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Mf_adap_bkpt_ind_uavn0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidInitBkptInd(void)
{
   VEMS_vidSET(Mf_adap_bkpt_ind_uavn0, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidInitSortieModeUT                             */
/* !Description :  Les compteurs d’apprentissage sont réinitialisés à la      */
/*                 sortie du mode UT                                          */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output uint8 Mf_adap_lw_corr_count_uavn1[9];                              */
/*  output uint8 Mf_adap_shrt_corr_count_uavn1[9];                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidInitSortieModeUT(void)
{
   sint32 s32LocalIndex;


   for (s32LocalIndex = 0; s32LocalIndex < 9; s32LocalIndex++)
   {
      VEMS_vidSET1DArrayElement(Mf_adap_lw_corr_count_uavn1, s32LocalIndex, 0);
      VEMS_vidSET1DArrayElement(Mf_adap_shrt_corr_count_uavn1,
                                s32LocalIndex,
                                0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAutomateMisfLrn                              */
/* !Description :  Automate de la stratégie d'apprentissage des défauts.      */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDFTLRN_vidCalcWinDelta();                            */
/*  extf argret void MISFDFTLRN_vidApplyDeltaPrecal();                        */
/*  extf argret void MISFDFTLRN_vidCalcWinApp();                              */
/*  extf argret void MISFDFTLRN_vidCalcLrn();                                 */
/*  extf argret void MISFDFTLRN_vidCalcLrnInit();                             */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Mf_win_1_uavb0;                                             */
/*  input st98 Misf_stDftLrn;                                                 */
/*  input boolean Mf_adap_ena_uavb0;                                          */
/*  input boolean Mf_adap_calc_init_uavb0;                                    */
/*  input boolean Mf_adap_filt_calc_init_uavb0;                               */
/*  output st98 Misf_stDftLrn;                                                */
/*  output boolean Mf_adap_calc_init_uavb0;                                   */
/*  output boolean Mf_adap_filt_calc_init_uavb0;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAutomateMisfLrn(void)
{
   boolean bLocalMf_win_1_uavb0;


   VEMS_vidGET(Mf_win_1_uavb0, bLocalMf_win_1_uavb0);
   switch(Misf_stDftLrn)
   {
      case CALC_INIT:
         if (  (Mf_adap_ena_uavb0 != 0)
            && (bLocalMf_win_1_uavb0 != 0))
         {
            Misf_stDftLrn = CALC_CYL1;
            MISFDFTLRN_vidCalcWinDelta();
         }
         break;

      case CALC_CYL1:
         if (Mf_adap_ena_uavb0 == 0)
         {
            MISFDFTLRN_vidApplyDeltaPrecal();
            Misf_stDftLrn = CALC_INIT;
            Mf_adap_calc_init_uavb0 = 1;
            Mf_adap_filt_calc_init_uavb0 = 1;
         }
         else
         {
            if (bLocalMf_win_1_uavb0 == 0)
            {
               if (Mf_adap_calc_init_uavb0 != 0)
               {
                  Misf_stDftLrn =  WAIT_CYL1;
               }
               else
               {
                  if (Mf_adap_filt_calc_init_uavb0 != 0)
                  {
                     Misf_stDftLrn = INIT_LRN;
                     MISFDFTLRN_vidCalcWinApp();
                  }
                  else
                  {
                     Misf_stDftLrn = LRN_COND;
                     MISFDFTLRN_vidCalcWinApp();
                     MISFDFTLRN_vidCalcLrn();
                  }
               }
            }
            else
            {
               MISFDFTLRN_vidCalcWinDelta();
            }
         }
         break;

      case INIT_LRN:
         if (Mf_adap_ena_uavb0 == 0)
         {
            MISFDFTLRN_vidApplyDeltaPrecal();
            Misf_stDftLrn = CALC_INIT;
            Mf_adap_calc_init_uavb0 = 1;
            Mf_adap_filt_calc_init_uavb0 = 1;
         }
         else
         {
            if (bLocalMf_win_1_uavb0 != 0)
            {
               Misf_stDftLrn = CALC_CYL1;
               Mf_adap_filt_calc_init_uavb0 = 0;
               MISFDFTLRN_vidCalcLrnInit();
               MISFDFTLRN_vidCalcWinDelta();
            }
            else
            {
               MISFDFTLRN_vidCalcWinApp();
            }
         }
         break;

      case WAIT_CYL1:
         if (Mf_adap_ena_uavb0 == 0)
         {
            MISFDFTLRN_vidApplyDeltaPrecal();
            Misf_stDftLrn = CALC_INIT;
            Mf_adap_calc_init_uavb0 = 1;
            Mf_adap_filt_calc_init_uavb0 = 1;
         }
         else
         {
            if (bLocalMf_win_1_uavb0 != 0)
            {
               Misf_stDftLrn = CALC_CYL1;
               Mf_adap_calc_init_uavb0 = 0;
               MISFDFTLRN_vidCalcWinDelta();
            }
         }
         break;

      case LRN_COND:
         if (Mf_adap_ena_uavb0 == 0)
         {
            MISFDFTLRN_vidApplyDeltaPrecal();
            Misf_stDftLrn = CALC_INIT;
            Mf_adap_calc_init_uavb0 = 1;
            Mf_adap_filt_calc_init_uavb0 = 1;
         }
         else
         {
            if (bLocalMf_win_1_uavb0 != 0)
            {
               Misf_stDftLrn = CALC_CYL1;
               MISFDFTLRN_vidCalcWinDelta();
            }
            else
            {
               MISFDFTLRN_vidCalcWinApp();
               MISFDFTLRN_vidCalcLrn();
            }
         }
         break;

      default:
         /* state CALC_INIT */
         if (Mf_adap_ena_uavb0 == 0)
         {
            Misf_stDftLrn = CALC_INIT;
            Mf_adap_calc_init_uavb0 = 1;
            Mf_adap_filt_calc_init_uavb0 = 1;
         }
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCalcWinDelta                                 */
/* !Description :  Ce module extrait les valeurs des durées des fenêtres      */
/*                 longues et des fenêtres courtes du cylindre 1 afin d'en    */
/*                 calculer les variations par rapport au cycle précédent.    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Misf_tiDlyLongWin;                                           */
/*  input uint32 MISFDFTLRN_u32tiDlyLongWinPrev;                              */
/*  input uint32 Misf_tiDlyExpWin;                                            */
/*  input uint32 MISFDFTLRN_u32tiDlyExpWinPrev;                               */
/*  input uint32 Misf_tiDlyTDCWin;                                            */
/*  input uint32 MISFDFTLRN_u32tiDlyTDCWinPrev;                               */
/*  input uint32 Misf_tiDlyBdcWin;                                            */
/*  input uint32 MISFDFTLRN_u32tiDlyBdcWinPrev;                               */
/*  output uint32 Misf_tiDlyLongWin1;                                         */
/*  output sint16 Misf_LongWin1Delta;                                         */
/*  output uint32 Misf_tiDlyExpWin1;                                          */
/*  output sint16 Misf_ExpWin1Delta;                                          */
/*  output uint32 Misf_tiDlyTDCWin1;                                          */
/*  output sint16 Misf_TDCWin1Delta;                                          */
/*  output uint32 Misf_tiDlyBdcWin1;                                          */
/*  output sint16 Misf_BdcWin1Delta;                                          */
/*  output uint32 MISFDFTLRN_u32tiDlyLongWinPrev;                             */
/*  output uint32 MISFDFTLRN_u32tiDlyExpWinPrev;                              */
/*  output uint32 MISFDFTLRN_u32tiDlyTDCWinPrev;                              */
/*  output uint32 MISFDFTLRN_u32tiDlyBdcWinPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcWinDelta(void)
{
   uint32 u32LocalMisf_tiDlyLongWin;
   uint32 u32LocalMisf_tiDlyExpWin;
   uint32 u32LocalMisf_tiDlyTDCWin;
   uint32 u32LocalMisf_tiDlyBdcWin;
   uint32 u32LocalDiff;
   sint32 s32LocalDiff;


   VEMS_vidGET(Misf_tiDlyLongWin, u32LocalMisf_tiDlyLongWin);
   Misf_tiDlyLongWin1 = MATHSRV_udtMIN(u32LocalMisf_tiDlyLongWin, 199999);
   if (u32LocalMisf_tiDlyLongWin > MISFDFTLRN_u32tiDlyLongWinPrev)
   {
      u32LocalDiff = u32LocalMisf_tiDlyLongWin - MISFDFTLRN_u32tiDlyLongWinPrev;
      Misf_LongWin1Delta = (sint16)MATHSRV_udtMIN(u32LocalDiff, 32767);
   }
   else
   {
      u32LocalDiff = MISFDFTLRN_u32tiDlyLongWinPrev - u32LocalMisf_tiDlyLongWin;
      u32LocalDiff = MATHSRV_udtMIN(u32LocalDiff, (uint32)32768);
      s32LocalDiff = (sint32)u32LocalDiff;
      Misf_LongWin1Delta = (sint16)(-s32LocalDiff);
   }

   VEMS_vidGET(Misf_tiDlyExpWin, u32LocalMisf_tiDlyExpWin);
   Misf_tiDlyExpWin1 = MATHSRV_udtMIN(u32LocalMisf_tiDlyExpWin, 99999);
   if (u32LocalMisf_tiDlyExpWin > MISFDFTLRN_u32tiDlyExpWinPrev)
   {
      u32LocalDiff = u32LocalMisf_tiDlyExpWin - MISFDFTLRN_u32tiDlyExpWinPrev;
      Misf_ExpWin1Delta = (sint16)MATHSRV_udtMIN(u32LocalDiff, 32767);
   }
   else
   {
      u32LocalDiff = MISFDFTLRN_u32tiDlyExpWinPrev - u32LocalMisf_tiDlyExpWin;
      u32LocalDiff = MATHSRV_udtMIN(u32LocalDiff, (uint32)32768);
      s32LocalDiff = (sint32)u32LocalDiff;
      Misf_ExpWin1Delta = (sint16)(-s32LocalDiff);
   }

   VEMS_vidGET(Misf_tiDlyTDCWin, u32LocalMisf_tiDlyTDCWin);
   Misf_tiDlyTDCWin1 = MATHSRV_udtMIN(u32LocalMisf_tiDlyTDCWin, 99999);
   if (u32LocalMisf_tiDlyTDCWin > MISFDFTLRN_u32tiDlyTDCWinPrev)
   {
      u32LocalDiff = u32LocalMisf_tiDlyTDCWin - MISFDFTLRN_u32tiDlyTDCWinPrev;
      Misf_TDCWin1Delta = (sint16)MATHSRV_udtMIN(u32LocalDiff, 32767);
   }
   else
   {
      u32LocalDiff = MISFDFTLRN_u32tiDlyTDCWinPrev - u32LocalMisf_tiDlyTDCWin;
      u32LocalDiff = MATHSRV_udtMIN(u32LocalDiff, (uint32)32768);
      s32LocalDiff = (sint32)u32LocalDiff;
      Misf_TDCWin1Delta = (sint16)(-s32LocalDiff);
   }

   VEMS_vidGET(Misf_tiDlyBdcWin, u32LocalMisf_tiDlyBdcWin);
   Misf_tiDlyBdcWin1 = MATHSRV_udtMIN(u32LocalMisf_tiDlyBdcWin, 99999);
   if (u32LocalMisf_tiDlyBdcWin > MISFDFTLRN_u32tiDlyBdcWinPrev)
   {
      u32LocalDiff = u32LocalMisf_tiDlyBdcWin - MISFDFTLRN_u32tiDlyBdcWinPrev;
      Misf_BdcWin1Delta = (sint16)MATHSRV_udtMIN(u32LocalDiff, 32767);
   }
   else
   {
      u32LocalDiff = MISFDFTLRN_u32tiDlyBdcWinPrev - u32LocalMisf_tiDlyBdcWin;
      u32LocalDiff = MATHSRV_udtMIN(u32LocalDiff, (uint32)32768);
      s32LocalDiff = (sint32)u32LocalDiff;
      Misf_BdcWin1Delta = (sint16)(-s32LocalDiff);
   }

   MISFDFTLRN_u32tiDlyLongWinPrev = MATHSRV_udtMIN(u32LocalMisf_tiDlyLongWin,
                                                   199999);
   MISFDFTLRN_u32tiDlyExpWinPrev = MATHSRV_udtMIN(u32LocalMisf_tiDlyExpWin,
                                                  99999);
   MISFDFTLRN_u32tiDlyTDCWinPrev = MATHSRV_udtMIN(u32LocalMisf_tiDlyTDCWin,
                                                  99999);
   MISFDFTLRN_u32tiDlyBdcWinPrev = MATHSRV_udtMIN(u32LocalMisf_tiDlyBdcWin,
                                                  99999);
}
/******************************* end of file **********************************/
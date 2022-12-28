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
/* !File            : MISFDFTLRN_FCT4.C                                       */
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
/*   1 / MISFDFTLRN_vid1stLwAdapOnBkpt                                        */
/*   2 / MISFDFTLRN_vidAdapPrecalLong                                         */
/*   3 / MISFDFTLRN_vidAdapMesLong                                            */
/*   4 / MISFDFTLRN_vidAdapLwRlzdNoUt                                         */
/*   5 / MISFDFTLRN_vidAdapLwRlzdUt                                           */
/*   6 / MISFDFTLRN_vidNextLwAdapOnBkpt                                       */
/*   7 / MISFDFTLRN_vidLwAdapWrite                                            */
/*   8 / MISFDFTLRN_vidLwAdapRaz                                              */
/*   9 / MISFDFTLRN_vidAdapLwRstNoUt                                          */
/*   10 / MISFDFTLRN_vidAdapLwRstUt                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5069555 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#068760                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDFTLRN/MISFDFTLRN_FCT4.C_$*/
/* $Revision::   1.17     $$Author::   achebino       $$Date::   10 Jul 2012 $*/
/* $Author::   achebino                               $$Date::   10 Jul 2012 $*/
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
#include "SWFAIL.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vid1stLwAdapOnBkpt                              */
/* !Description :  Ce module écrit le nombre d’apprentissages réalisés sur ce */
/*                 point d’appui .                                            */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void MISFDFTLRN_vidAdapLwRlzdUt();                            */
/*  extf argret void MISFDFTLRN_vidAdapLwRlzdNoUt();                          */
/*  extf argret void MISFDFTLRN_vidAdapPrecalLong();                          */
/*  extf argret void MISFDFTLRN_vidAdapMesLong();                             */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input uint8 Mf_adap_lw_corr_nxt_cnt_i_uavn0;                              */
/*  input boolean MISFDFTLRN_blwnorlzdUTuavb0Prev;                            */
/*  input boolean MISFDFTLRN_blwnorlzduavb0Prev;                              */
/*  input uint8 Mf_adap_delta_count_uavn1[4];                                 */
/*  input uint8 Mf_adap_delta_count_min_uacn1[4];                             */
/*  input boolean Mf_adap_inh_corr_precal_uacb0;                              */
/*  output uint8 Mf_adap_lw_corr_count_uavn1[9];                              */
/*  output uint8 Mf_adap_lw_corr_nxt_cnt_i_uavn0;                             */
/*  output boolean Misf_bMonRunORng_LongWinLrn;                               */
/*  output boolean Misf_bDgoORng_LongWinLrn;                                  */
/*  output boolean Misf_bMonRunORng_LongWinLrnMax;                            */
/*  output boolean Misf_bDgoORng_LongWinLrnMax;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vid1stLwAdapOnBkpt(void)
{
   boolean bLocalSrv_bAcvPlaMod;
   boolean bLocalFrstAndOprnd;
   boolean bLocalTabOR;
   uint8   u8LocalMfAdapBkptIndPrevUavn0;
   sint16  s16LocalMfAdapBkptIndPrevUavn0;


   VEMS_vidGET(Srv_bAcvPlaMod, bLocalSrv_bAcvPlaMod);
   s16LocalMfAdapBkptIndPrevUavn0 = (sint16)(Mf_adap_bkpt_ind_prev_uavn0 - 1);

   u8LocalMfAdapBkptIndPrevUavn0 =
      (uint8)MATHSRV_udtCLAMP(s16LocalMfAdapBkptIndPrevUavn0, 0, 8);
   VEMS_vidSET1DArrayElement(Mf_adap_lw_corr_count_uavn1,
                             u8LocalMfAdapBkptIndPrevUavn0,
                             Mf_adap_lw_corr_nxt_cnt_i_uavn0);

   if (bLocalSrv_bAcvPlaMod != 0)
   {
      bLocalFrstAndOprnd = MISFDFTLRN_blwnorlzdUTuavb0Prev;
      MISFDFTLRN_vidAdapLwRlzdUt();
   }
   else
   {
      bLocalFrstAndOprnd = MISFDFTLRN_blwnorlzduavb0Prev;
      MISFDFTLRN_vidAdapLwRlzdNoUt();
   }

   if (  (Mf_adap_delta_count_uavn1[0] < Mf_adap_delta_count_min_uacn1[0])
      || (Mf_adap_delta_count_uavn1[1] < Mf_adap_delta_count_min_uacn1[1])
      || (Mf_adap_delta_count_uavn1[2] < Mf_adap_delta_count_min_uacn1[2])
      || (Mf_adap_delta_count_uavn1[3] < Mf_adap_delta_count_min_uacn1[3]))
   {
      bLocalTabOR = 1;
   }
   else
   {
      bLocalTabOR = 0;
   }
   if (  (bLocalFrstAndOprnd != 0)
      && (  (Mf_adap_inh_corr_precal_uacb0 != 0)
         || (bLocalTabOR != 0)))
   {
      MISFDFTLRN_vidAdapPrecalLong();
   }
   else
   {
      MISFDFTLRN_vidAdapMesLong();
   }

   Misf_bMonRunORng_LongWinLrn = 0;
   Misf_bDgoORng_LongWinLrn = 0;
   Misf_bMonRunORng_LongWinLrnMax = 0;
   Misf_bDgoORng_LongWinLrnMax = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapPrecalLong                               */
/* !Description :  Le premier apprentissage sur la fenêtre est commun à tous  */
/*                 les points d'appui du cylindre observé : les valeurs de la */
/*                 cartographie de correction de la fenêtre longue            */
/*                 Misf_tiDlyLongWinLrn résultent de la cartographie de       */
/*                 précalibration.                                            */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input uint16 Mf_adap_lw_corr_precal_uacn2[4][9];                          */
/*  input sint16 Mf_adap_lw_err_mv_i_uavn1[4];                                */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapPrecalLong(void)
{
   uint8  u8LocalIdxR;
   uint8  u8LocalIdxC;
   uint8  u8LocalIdxPrev2;
   sint16 s16LocalLongWin;
   sint32 s32LocalLwCorPrecal;



   if (Mf_adap_bkpt_ind_prev_uavn0 > 0)
   {
      for (u8LocalIdxC = 0; u8LocalIdxC < 9; u8LocalIdxC ++)
      {
         s32LocalLwCorPrecal = ( Mf_adap_lw_corr_precal_uacn2[0][u8LocalIdxC]
                               - Mf_adap_lw_err_mv_i_uavn1[0]
                               - 32768);
         s16LocalLongWin = (sint16)MATHSRV_udtCLAMP(s32LocalLwCorPrecal,
                                                    -32768,
                                                    32767);
         Misf_prm_tiDlyLongWinLrn[0][u8LocalIdxC] = s16LocalLongWin;
      }

      u8LocalIdxPrev2 = (uint8)(Mf_adap_bkpt_ind_prev_uavn0 - 1);
      u8LocalIdxPrev2 = (uint8)MATHSRV_udtMIN(u8LocalIdxPrev2, 8);
      for (u8LocalIdxR = 1; u8LocalIdxR < 4; u8LocalIdxR ++)
      {
         for (u8LocalIdxC = 0; u8LocalIdxC < 9; u8LocalIdxC ++)
         {
            s32LocalLwCorPrecal =
               ( Mf_adap_lw_corr_precal_uacn2[u8LocalIdxR][u8LocalIdxC]
               - ( Mf_adap_lw_err_mv_i_uavn1[u8LocalIdxR]
                 + Mf_adap_lw_corr_precal_uacn2[u8LocalIdxR][u8LocalIdxPrev2]));
            s16LocalLongWin = (sint16)MATHSRV_udtCLAMP(s32LocalLwCorPrecal,
                                                       -32768,
                                                       32767);
            Misf_prm_tiDlyLongWinLrn[u8LocalIdxR][u8LocalIdxC] =
               s16LocalLongWin;
         }
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapMesLong                                  */
/* !Description :  Ce module écrit le nombre d’apprentissages réalisés sur ce */
/*                 point d’appui (la valeur est 1 puisque c’est le premier    */
/*                 apprentissage, condition d’entrée dans ce module).         */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input sint16 Mf_adap_lw_err_mv_i_uavn1[4];                                */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapMesLong(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalMfAdapBkptIndPrevUavn0;
   sint16 s16LocalMfAdapBkptIndPrevUavn0;
   sint16 s16LocalAdapLwErrMvIUavn0;
   sint32 s32LocalAdapLwErrMvIUavn0;


   s16LocalMfAdapBkptIndPrevUavn0 = (sint16)(Mf_adap_bkpt_ind_prev_uavn0 - 1);
   u8LocalMfAdapBkptIndPrevUavn0 =
      (uint8)MATHSRV_udtCLAMP(s16LocalMfAdapBkptIndPrevUavn0, 0, 8);

   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex ++)
   {
      s32LocalAdapLwErrMvIUavn0 = -Mf_adap_lw_err_mv_i_uavn1[u8LocalIndex];
      s16LocalAdapLwErrMvIUavn0 =
         (sint16)MATHSRV_udtMIN(s32LocalAdapLwErrMvIUavn0, 32767);
      Misf_prm_tiDlyLongWinLrn[u8LocalIndex][u8LocalMfAdapBkptIndPrevUavn0] =
         s16LocalAdapLwErrMvIUavn0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapLwRlzdNoUt                               */
/* !Description :  Remise à zero de Mf_adap_lw_no_rlzd_uavb0                  */
/* !Number      :  FCT4.4                                                     */
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
void MISFDFTLRN_vidAdapLwRlzdNoUt(void)
{
   VEMS_vidSET(Mf_adap_lw_no_rlzd_uavb0, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapLwRlzdUt                                 */
/* !Description :  Remise à zero de Mf_adap_lw_no_rlzd_UT_uavb0               */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_adap_lw_no_rlzd_UT_uavb0;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapLwRlzdUt(void)
{
   VEMS_vidSET(Mf_adap_lw_no_rlzd_UT_uavb0, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidNextLwAdapOnBkpt                             */
/* !Description :  Contrôle de la valeur d'apprentissage et déclanchement du  */
/*                 panne.                                                     */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDFTLRN_vidLwAdapWrite();                             */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void MISFDFTLRN_vidLwAdapRaz();                               */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input sint16 Misf_prm_tiDlyLongWinLrn[4][9];                              */
/*  input sint16 Mf_adap_lw_err_mv_i_uavn1[4];                                */
/*  input uint16 Mf_adap_lw_corr_dlta_max_uacn1[4][9];                        */
/*  input uint16 Mf_adap_lw_range_max[4][9];                                  */
/*  input boolean Misf_bDgoORng_LongWinLrn;                                   */
/*  input boolean Misf_bDgoORng_LongWinLrnMax;                                */
/*  output boolean Misf_bMonRunORng_LongWinLrnMax;                            */
/*  output boolean Misf_bMonRunORng_LongWinLrn;                               */
/*  output boolean Misf_bDgoORng_LongWinLrn;                                  */
/*  output boolean Misf_bDgoORng_LongWinLrnMax;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidNextLwAdapOnBkpt(void)
{
   boolean bLocalAcvLongWinLrnRst;
   uint8   u8LocalMisf_noCyl;
   uint8   u8LocalMfAdapBkptIndPrevUavn0;
   uint16  u16LocalLwCorrDeltaMaxUacn1;
   uint16  u16Locallw_range_max;
   uint16  u16LocaltiDlyLongWinLrn;
   sint16  s16LocalLwErrMvIUavn0;
   sint16  s16LocaltiDlyLongWinLrn;
   sint16  s16LocalMfAdapBkptIndPrevUavn0;
   uint32  u32LocalLong;
   uint32  u32LocaltiDlyLongWinLrn;
   sint32  s32LocalLong;


   Misf_bMonRunORng_LongWinLrnMax = 1;
   Misf_bMonRunORng_LongWinLrn = 1;
   bLocalAcvLongWinLrnRst = GDGAR_bGetFRM(FRM_FRM_ACVLONGWINLRNRST);
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
         s16LocaltiDlyLongWinLrn =
            Misf_prm_tiDlyLongWinLrn[u8LocalMisf_noCyl]
                                    [u8LocalMfAdapBkptIndPrevUavn0];
         s16LocalLwErrMvIUavn0 =
            Mf_adap_lw_err_mv_i_uavn1[u8LocalMisf_noCyl];
         s32LocalLong = s16LocaltiDlyLongWinLrn + s16LocalLwErrMvIUavn0;
         u32LocalLong = (uint32)MATHSRV_udtABS(s32LocalLong);
         u32LocalLong = (u32LocalLong * 2);

         u16LocalLwCorrDeltaMaxUacn1 =
            Mf_adap_lw_corr_dlta_max_uacn1[u8LocalMisf_noCyl]
                                          [u8LocalMfAdapBkptIndPrevUavn0];
         u16Locallw_range_max =
            Mf_adap_lw_range_max[u8LocalMisf_noCyl]
                                [u8LocalMfAdapBkptIndPrevUavn0];
         u16LocaltiDlyLongWinLrn =
            (uint16)MATHSRV_udtABS(s16LocaltiDlyLongWinLrn);
         u32LocaltiDlyLongWinLrn =(uint32)(u16LocaltiDlyLongWinLrn * 2);

         if (u32LocalLong <= u16LocalLwCorrDeltaMaxUacn1)
         {
            Misf_bDgoORng_LongWinLrn = 0;
         }
         else
         {
            Misf_bDgoORng_LongWinLrn = 1;
         }
         if (u32LocaltiDlyLongWinLrn <= u16Locallw_range_max)
         {
            Misf_bDgoORng_LongWinLrnMax = 0;
         }
         else
         {
            Misf_bDgoORng_LongWinLrnMax = 1;
         }
         if (  (Misf_bDgoORng_LongWinLrn == 0)
            && (Misf_bDgoORng_LongWinLrnMax == 0))
         {
            MISFDFTLRN_vidLwAdapWrite();
         }
         break;

      case 4:
      case 5:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   if (bLocalAcvLongWinLrnRst != 0)
   {
      MISFDFTLRN_vidLwAdapRaz();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidLwAdapWrite                                  */
/* !Description :  Ce module écrit le nombre d’apprentissages dans la         */
/*                 cartographie de comptage, et enregistre la valeur apprise  */
/*                 dans la cartographie de correction en passant par un       */
/*                 filtre.                                                    */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input uint8 Mf_adap_lw_corr_nxt_cnt_i_uavn0;                              */
/*  input uint8 Mf_adap_lw_nb_mv_calc_uacn0;                                  */
/*  input sint16 Mf_adap_lw_err_mv_i_uavn1[4];                                */
/*  input sint16 Misf_prm_tiDlyLongWinLrn[4][9];                              */
/*  input uint8 Mf_adap_lw_corr_bkup_gain_uacn1[9];                           */
/*  output uint8 Mf_adap_lw_corr_count_uavn1[9];                              */
/*  output uint8 Mf_adap_lw_corr_nxt_cnt_i_uavn0;                             */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidLwAdapWrite(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalGain;
   uint8  u8LocalMfAdapBkptIndPrevUavn0;
   sint16 s16LocalArray[MISFDFTLRN_u8ARRAY_LEN];
   sint16 s16LocalLongWinLrn;
   sint16 s16LocalLwErrMv;
   sint16 s16LocalMfAdapBkptIndPrevUavn0;
   sint32 s32Localnxtcnt;


   s16LocalMfAdapBkptIndPrevUavn0 = (sint16)(Mf_adap_bkpt_ind_prev_uavn0 - 1);
   u8LocalMfAdapBkptIndPrevUavn0 =
      (uint8)MATHSRV_udtCLAMP(s16LocalMfAdapBkptIndPrevUavn0, 0, 8);

   VEMS_vidSET1DArrayElement(Mf_adap_lw_corr_count_uavn1,
                             u8LocalMfAdapBkptIndPrevUavn0,
                             Mf_adap_lw_corr_nxt_cnt_i_uavn0);

   if (Mf_adap_lw_corr_nxt_cnt_i_uavn0 <= Mf_adap_lw_nb_mv_calc_uacn0)
   {
      if (Mf_adap_lw_corr_nxt_cnt_i_uavn0 <= 1)
      {
         for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
         {
            s32Localnxtcnt = (sint32)(-Mf_adap_lw_err_mv_i_uavn1[u8LocalIndex]);
            s16LocalArray[u8LocalIndex] =
               (sint16)MATHSRV_udtMIN(s32Localnxtcnt, 32767);
         }
      }
      else
      {
         for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
         {
            s16LocalLongWinLrn =
               Misf_prm_tiDlyLongWinLrn[u8LocalIndex]
                                       [u8LocalMfAdapBkptIndPrevUavn0];
            s16LocalLwErrMv = Mf_adap_lw_err_mv_i_uavn1[u8LocalIndex];
            s32Localnxtcnt = (sint32)( ( ( s16LocalLongWinLrn
                                         * ( Mf_adap_lw_corr_nxt_cnt_i_uavn0
                                           - 1))
                                       - s16LocalLwErrMv)
                                     / Mf_adap_lw_corr_nxt_cnt_i_uavn0);
            s16LocalArray[u8LocalIndex] = (sint16)s32Localnxtcnt;
         }
      }
   }
   else
   {
      for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
      {
         s16LocalLongWinLrn =
            Misf_prm_tiDlyLongWinLrn[u8LocalIndex]
                                    [u8LocalMfAdapBkptIndPrevUavn0];
         s16LocalLwErrMv = Mf_adap_lw_err_mv_i_uavn1[u8LocalIndex];
         u8LocalGain =
            Mf_adap_lw_corr_bkup_gain_uacn1[u8LocalMfAdapBkptIndPrevUavn0];
         s32Localnxtcnt = (sint32)( ( ( s16LocalLongWinLrn
                                      * ( 256
                                        - u8LocalGain))
                                    - ( s16LocalLwErrMv
                                      * u8LocalGain))
                                  / 256);
         s16LocalArray[u8LocalIndex] = (sint16)s32Localnxtcnt;
      }
   }

   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      Misf_prm_tiDlyLongWinLrn[u8LocalIndex][u8LocalMfAdapBkptIndPrevUavn0] =
         s16LocalArray[u8LocalIndex];
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidLwAdapRaz                                    */
/* !Description :  En cas de panne mémorisée, l’apprentissage des défauts     */
/*                 misfire est reseté. Toutes les variables  d’apprentissage  */
/*                 prennent les valeurs par défaut.                           */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void MISFDFTLRN_vidAdapLwRstUt();                             */
/*  extf argret void MISFDFTLRN_vidAdapLwRstNoUt();                           */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  output uint8 Mf_adap_lw_corr_count_uavn1[9];                              */
/*  output sint16 Misf_prm_tiDlyLongWinLrn[4][9];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidLwAdapRaz(void)
{
   boolean bLocalSrv_bAcvPlaMod;
   sint32  s32LocalIndx1;
   sint32  s32LocalIndx2;


   VEMS_vidGET(Srv_bAcvPlaMod, bLocalSrv_bAcvPlaMod);

   for (s32LocalIndx1 = 0; s32LocalIndx1 < 9; s32LocalIndx1++)
   {
      VEMS_vidSET1DArrayElement(Mf_adap_lw_corr_count_uavn1,
                                s32LocalIndx1,
                                0);
      for (s32LocalIndx2 = 0; s32LocalIndx2 < 4; s32LocalIndx2++)
      {
         Misf_prm_tiDlyLongWinLrn[s32LocalIndx2][s32LocalIndx1] = 0;
      }
   }

   if (bLocalSrv_bAcvPlaMod != 0)
   {
      MISFDFTLRN_vidAdapLwRstUt();
   }
   else
   {
      MISFDFTLRN_vidAdapLwRstNoUt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapLwRstNoUt                                */
/* !Description :  Remise à 1 de Mf_adap_lw_no_rlzd_uavb0                     */
/* !Number      :  FCT4.9                                                     */
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
void MISFDFTLRN_vidAdapLwRstNoUt(void)
{
   VEMS_vidSET(Mf_adap_lw_no_rlzd_uavb0, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapLwRstUt                                  */
/* !Description :  Remise à 1 de Mf_adap_lw_no_rlzd_UT_uavb0                  */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_adap_lw_no_rlzd_UT_uavb0;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapLwRstUt(void)
{
   VEMS_vidSET(Mf_adap_lw_no_rlzd_UT_uavb0, 1);
}
/*-------------------------------- end of file -------------------------------*/
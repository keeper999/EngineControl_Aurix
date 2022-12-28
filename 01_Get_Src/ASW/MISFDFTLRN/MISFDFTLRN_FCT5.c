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
/* !File            : MISFDFTLRN_FCT5.C                                       */
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
/*   1 / MISFDFTLRN_vid1stShrtAdapOnBkpt                                      */
/*   2 / MISFDFTLRN_vidAdapPrecalShrt                                         */
/*   3 / MISFDFTLRN_vidAdapPrecalShrtExp                                      */
/*   4 / MISFDFTLRN_vidAdapPrecalShrtTDC                                      */
/*   5 / MISFDFTLRN_vidAdapPrecalShrtBdc                                      */
/*   6 / MISFDFTLRN_vidAdapMesShrt                                            */
/*   7 / MISFDFTLRN_vidAdapRlzdNoUt                                           */
/*   8 / MISFDFTLRN_vidAdapRlzdUt                                             */
/*   9 / MISFDFTLRN_vidNextShrtAdapOnBkpt                                     */
/*   10 / MISFDFTLRN_vidCalcDelta                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5069555 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#068760                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDFTLRN/MISFDFTLRN_FCT5.C_$*/
/* $Revision::   1.16     $$Author::   achebino       $$Date::   06 Jul 2012 $*/
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
#include "VEMS.h"
#include "SWFAIL.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vid1stShrtAdapOnBkpt                            */
/* !Description :  Ce module écrit le nombre d’apprentissages réalisés sur ce */
/*                 point d’appui.                                             */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void MISFDFTLRN_vidAdapRlzdUt();                              */
/*  extf argret void MISFDFTLRN_vidAdapRlzdNoUt();                            */
/*  extf argret void MISFDFTLRN_vidAdapPrecalShrt();                          */
/*  extf argret void MISFDFTLRN_vidAdapMesShrt();                             */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input uint8 Mf_adap_shrt_corr_nxt_cnt_i;                                  */
/*  input boolean MISFDFTLRN_bshrtnorlzdUTuavb0Prv;                           */
/*  input boolean MISFDFTLRN_bshrtnorlzduavb0Prev;                            */
/*  input uint8 Mf_adap_delta_count_uavn1[4];                                 */
/*  input uint8 Mf_adap_delta_count_min_uacn1[4];                             */
/*  input boolean Mf_adap_inh_corr_precal_uacb0;                              */
/*  output uint8 Mf_adap_shrt_corr_count_uavn1[9];                            */
/*  output uint8 Mf_adap_shrt_corr_nxt_cnt_i;                                 */
/*  output boolean Misf_bDgoORng_ShrtWinLrn;                                  */
/*  output boolean Misf_bMonRunORng_ShrtWinLrn;                               */
/*  output boolean Misf_bDgoORng_ShrtWinLrnMax;                               */
/*  output boolean Misf_bMonRunORng_ShrtWinLrnMax;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vid1stShrtAdapOnBkpt(void)
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

   VEMS_vidSET1DArrayElement(Mf_adap_shrt_corr_count_uavn1,
                             u8LocalMfAdapBkptIndPrevUavn0,
                             Mf_adap_shrt_corr_nxt_cnt_i);

   if (bLocalSrv_bAcvPlaMod != 0)
   {
      bLocalFrstAndOprnd = MISFDFTLRN_bshrtnorlzdUTuavb0Prv;
      MISFDFTLRN_vidAdapRlzdUt();
   }
   else
   {
      bLocalFrstAndOprnd = MISFDFTLRN_bshrtnorlzduavb0Prev;
      MISFDFTLRN_vidAdapRlzdNoUt();
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
      MISFDFTLRN_vidAdapPrecalShrt();
   }
   else
   {
      MISFDFTLRN_vidAdapMesShrt();
   }

   Misf_bDgoORng_ShrtWinLrn = 0;
   Misf_bMonRunORng_ShrtWinLrn = 0;
   Misf_bDgoORng_ShrtWinLrnMax = 0;
   Misf_bMonRunORng_ShrtWinLrnMax = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapPrecalShrt                               */
/* !Description :  Apprentissage sur les fenêtres courte détente, courte PMH  */
/*                 et courte PMB.                                             */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidAdapPrecalShrtExp();                       */
/*  extf argret void MISFDFTLRN_vidAdapPrecalShrtTDC();                       */
/*  extf argret void MISFDFTLRN_vidAdapPrecalShrtBdc();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapPrecalShrt(void)
{

   /* Fenêtre courte détente*/
   MISFDFTLRN_vidAdapPrecalShrtExp();

   /* Fenêtre courte PMH*/
   MISFDFTLRN_vidAdapPrecalShrtTDC();

   /* Fenêtre courte PMB*/
   MISFDFTLRN_vidAdapPrecalShrtBdc();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapPrecalShrtExp                            */
/* !Description :  Apprentisssage sur la fenêtre courte détente.              */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input sint16 Mf_adap_Exp_err_mv_i_uavn1[4];                               */
/*  input uint16 Mf_adap_Exp_corr_precal_uacn2[4][9];                         */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapPrecalShrtExp(void)
{
   uint8  u8LocalIdxR;
   uint8  u8LocalIdxC;
   uint8  u8LocalIdxPrev2;
   sint16 s16LocalExpWin;
   sint32 s32LocalExpCorrPrecal;
   sint32 s32LocalExpErrMv1Uavn0;


   if (Mf_adap_bkpt_ind_prev_uavn0 > 0)
   {
      for (u8LocalIdxC = 0; u8LocalIdxC < 9; u8LocalIdxC ++)
      {
         s32LocalExpErrMv1Uavn0 = (sint32)Mf_adap_Exp_err_mv_i_uavn1[0];
         s32LocalExpCorrPrecal = ( Mf_adap_Exp_corr_precal_uacn2[0][u8LocalIdxC]
                                 - s32LocalExpErrMv1Uavn0
                                 - 32768);
         s16LocalExpWin = (sint16)MATHSRV_udtCLAMP(s32LocalExpCorrPrecal,
                                                   -32768,
                                                    32767);
         Misf_prm_tiDlyExpWinLrn[0][u8LocalIdxC] = s16LocalExpWin;
      }

      u8LocalIdxPrev2 = (uint8)(Mf_adap_bkpt_ind_prev_uavn0 - 1);
      u8LocalIdxPrev2 = (uint8)MATHSRV_udtMIN(u8LocalIdxPrev2, 8);
      for (u8LocalIdxR = 1; u8LocalIdxR < 4; u8LocalIdxR ++)
      {
         for (u8LocalIdxC = 0; u8LocalIdxC < 9; u8LocalIdxC ++)
         {
            s32LocalExpErrMv1Uavn0 =
               ( Mf_adap_Exp_err_mv_i_uavn1[u8LocalIdxR]
               + Mf_adap_Exp_corr_precal_uacn2[u8LocalIdxR][u8LocalIdxPrev2]);
            s32LocalExpCorrPrecal =
                   ( Mf_adap_Exp_corr_precal_uacn2[u8LocalIdxR][u8LocalIdxC]
                   - s32LocalExpErrMv1Uavn0);
            s16LocalExpWin = (sint16)MATHSRV_udtCLAMP(s32LocalExpCorrPrecal,
                                                      -32768,
                                                       32767);
            Misf_prm_tiDlyExpWinLrn[u8LocalIdxR][u8LocalIdxC] = s16LocalExpWin;
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
/* !Function    :  MISFDFTLRN_vidAdapPrecalShrtTDC                            */
/* !Description :  Apprentissage sur la fenêtre courte PMH                    */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input sint16 Mf_adap_TDC_err_mv_i_uavn1[4];                               */
/*  input uint16 Mf_adap_TDC_corr_precal_uacn2[4][9];                         */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapPrecalShrtTDC(void)
{
   uint8  u8LocalIdxR;
   uint8  u8LocalIdxC;
   uint8  u8LocalIdxPrev2;
   sint16 s16LocalTDCWin;
   sint32 s32LocalTDCCorrPrecal;
   sint32 s32LocalTDCErrMv1Uavn0;


   if (Mf_adap_bkpt_ind_prev_uavn0 > 0)
   {
      for (u8LocalIdxC = 0; u8LocalIdxC < 9; u8LocalIdxC ++)
      {
         s32LocalTDCErrMv1Uavn0 = (sint32)Mf_adap_TDC_err_mv_i_uavn1[0];
         s32LocalTDCCorrPrecal = ( Mf_adap_TDC_corr_precal_uacn2[0][u8LocalIdxC]
                                - s32LocalTDCErrMv1Uavn0
                                - 32768);
         s16LocalTDCWin = (sint16)MATHSRV_udtCLAMP(s32LocalTDCCorrPrecal,
                                                   -32768,
                                                    32767);
         Misf_prm_tiDlyTDCWinLrn[0][u8LocalIdxC] = s16LocalTDCWin;
      }

      u8LocalIdxPrev2 = (uint8)(Mf_adap_bkpt_ind_prev_uavn0 - 1);
      u8LocalIdxPrev2 = (uint8)MATHSRV_udtMIN(u8LocalIdxPrev2, 8);
      for (u8LocalIdxR = 1; u8LocalIdxR < 4; u8LocalIdxR ++)
      {
         for (u8LocalIdxC = 0; u8LocalIdxC < 9; u8LocalIdxC ++)
         {
            s32LocalTDCErrMv1Uavn0 =
               ( Mf_adap_TDC_err_mv_i_uavn1[u8LocalIdxR]
               + Mf_adap_TDC_corr_precal_uacn2[u8LocalIdxR][u8LocalIdxPrev2]);
            s32LocalTDCCorrPrecal =
                   ( Mf_adap_TDC_corr_precal_uacn2[u8LocalIdxR][u8LocalIdxC]
                   - s32LocalTDCErrMv1Uavn0);
            s16LocalTDCWin = (sint16)MATHSRV_udtCLAMP(s32LocalTDCCorrPrecal,
                                                      -32768,
                                                       32767);
            Misf_prm_tiDlyTDCWinLrn[u8LocalIdxR][u8LocalIdxC] = s16LocalTDCWin;
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
/* !Function    :  MISFDFTLRN_vidAdapPrecalShrtBdc                            */
/* !Description :  Apprentissage sur la fenêtre courte PMB                    */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input sint16 Mf_adap_Bdc_err_mv_i_uavn1[4];                               */
/*  input uint16 Mf_adap_Bdc_corr_precal_uacn2[4][9];                         */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapPrecalShrtBdc(void)
{
   uint8  u8LocalIdxR;
   uint8  u8LocalIdxC;
   uint8  u8LocalIdxPrev2;
   sint16 s16LocalBdcWin;
   sint32 s32LocalBdcCorrPrecal;
   sint32 s32LocalBdcErrMv1Uavn0;


   if (Mf_adap_bkpt_ind_prev_uavn0 > 0)
   {
      for (u8LocalIdxC = 0; u8LocalIdxC < 9; u8LocalIdxC ++)
      {
         s32LocalBdcErrMv1Uavn0 = (sint32)Mf_adap_Bdc_err_mv_i_uavn1[0];
         s32LocalBdcCorrPrecal = ( Mf_adap_Bdc_corr_precal_uacn2[0][u8LocalIdxC]
                                - s32LocalBdcErrMv1Uavn0
                                - 32768);
         s16LocalBdcWin = (sint16)MATHSRV_udtCLAMP(s32LocalBdcCorrPrecal,
                                                   -32768,
                                                    32767);
         Misf_prm_tiDlyBdcWinLrn[0][u8LocalIdxC] = s16LocalBdcWin;
      }

      u8LocalIdxPrev2 = (uint8)(Mf_adap_bkpt_ind_prev_uavn0 - 1);
      u8LocalIdxPrev2 = (uint8)MATHSRV_udtMIN(u8LocalIdxPrev2, 8);
      for (u8LocalIdxR = 1; u8LocalIdxR < 4; u8LocalIdxR ++)
      {
         for (u8LocalIdxC = 0; u8LocalIdxC < 9; u8LocalIdxC ++)
         {
            s32LocalBdcErrMv1Uavn0 =
               ( Mf_adap_Bdc_err_mv_i_uavn1[u8LocalIdxR]
               + Mf_adap_Bdc_corr_precal_uacn2[u8LocalIdxR][u8LocalIdxPrev2]);
            s32LocalBdcCorrPrecal =
                   ( Mf_adap_Bdc_corr_precal_uacn2[u8LocalIdxR][u8LocalIdxC]
                   - s32LocalBdcErrMv1Uavn0);
            s16LocalBdcWin = (sint16)MATHSRV_udtCLAMP(s32LocalBdcCorrPrecal,
                                                      -32768,
                                                       32767);
            Misf_prm_tiDlyBdcWinLrn[u8LocalIdxR][u8LocalIdxC] = s16LocalBdcWin;
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
/* !Function    :  MISFDFTLRN_vidAdapMesShrt                                  */
/* !Description :  Ce module écrit le nombre d’apprentissages réalisés sur ce */
/*                 point d’appui (la valeur est 1 puisque c’est le premier    */
/*                 apprentissage, condition d’entrée dans ce module).         */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input sint16 Mf_adap_Exp_err_mv_i_uavn1[4];                               */
/*  input sint16 Mf_adap_TDC_err_mv_i_uavn1[4];                               */
/*  input sint16 Mf_adap_Bdc_err_mv_i_uavn1[4];                               */
/*  output sint16 Misf_prm_tiDlyExpWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                              */
/*  output sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidAdapMesShrt(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalMfAdapBkptIndPrevUavn0;
   sint16 s16LocalMfAdapBkptIndPrevUavn0;
   sint16 s16LocalAdapError;
   sint32 s32LocalAdapError;


   s16LocalMfAdapBkptIndPrevUavn0 = (sint16)(Mf_adap_bkpt_ind_prev_uavn0 - 1);
   u8LocalMfAdapBkptIndPrevUavn0 =
      (uint8)MATHSRV_udtCLAMP(s16LocalMfAdapBkptIndPrevUavn0, 0, 8);

   for( u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      s32LocalAdapError = -Mf_adap_Exp_err_mv_i_uavn1[u8LocalIndex];
      s16LocalAdapError = (sint16)MATHSRV_udtMIN(s32LocalAdapError, 32767);
      Misf_prm_tiDlyExpWinLrn[u8LocalIndex][u8LocalMfAdapBkptIndPrevUavn0] =
         s16LocalAdapError;
      s32LocalAdapError = -Mf_adap_TDC_err_mv_i_uavn1[u8LocalIndex];
      s16LocalAdapError = (sint16)MATHSRV_udtMIN(s32LocalAdapError, 32767);
      Misf_prm_tiDlyTDCWinLrn[u8LocalIndex][u8LocalMfAdapBkptIndPrevUavn0] =
         s16LocalAdapError;
      s32LocalAdapError = -Mf_adap_Bdc_err_mv_i_uavn1[u8LocalIndex];
      s16LocalAdapError = (sint16)MATHSRV_udtMIN(s32LocalAdapError, 32767);
      Misf_prm_tiDlyBdcWinLrn[u8LocalIndex][u8LocalMfAdapBkptIndPrevUavn0] =
         s16LocalAdapError;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapRlzdNoUt                                 */
/* !Description :  Remise à 0 de Mf_adap_shrt_no_rlzd_uavb0                   */
/* !Number      :  FCT5.7                                                     */
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
void MISFDFTLRN_vidAdapRlzdNoUt(void)
{
   VEMS_vidSET(Mf_adap_shrt_no_rlzd_uavb0, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidAdapRlzdUt                                   */
/* !Description :  remise à 0 de Mf_adap_shrt_no_rlzd_UT_uavb0                */
/* !Number      :  FCT5.8                                                     */
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
void MISFDFTLRN_vidAdapRlzdUt(void)
{
   VEMS_vidSET(Mf_adap_shrt_no_rlzd_UT_uavb0, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidNextShrtAdapOnBkpt                           */
/* !Description :  Ce module contrôle tout d’abord la nouvelle valeur de      */
/*                 correction dans le bloc 01_calc_delta.Si l’écart entre la  */
/*                 nouvelle valeur et celle déjà apprise est supérieure à un  */
/*                 seuil en fonction du régime alors une panne d’apprentissage*/
/*                 est relevée.                                               */
/* !Number      :  FCT5.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidCalcDelta();                               */
/*  extf argret void MISFDFTLRN_vidRangeControl();                            */
/*  extf argret void MISFDFTLRN_vidShrtAdapWrite();                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void MISFDFTLRN_vidShrtAdapRaz();                             */
/*  input boolean Misf_bDgoORng_ShrtWinLrn;                                   */
/*  input boolean Misf_bDgoORng_ShrtWinLrnMax;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidNextShrtAdapOnBkpt(void)
{
   boolean bLocalAcvShrtWinLrnRst;

   MISFDFTLRN_vidCalcDelta();
   MISFDFTLRN_vidRangeControl();
   if (  (Misf_bDgoORng_ShrtWinLrn == 0)
      && (Misf_bDgoORng_ShrtWinLrnMax == 0))
   {
      MISFDFTLRN_vidShrtAdapWrite();
   }

   bLocalAcvShrtWinLrnRst = GDGAR_bGetFRM(FRM_FRM_ACVSHRTWINLRNRST);
   if (bLocalAcvShrtWinLrnRst != 0)
   {
      MISFDFTLRN_vidShrtAdapRaz();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCalcDelta                                    */
/* !Description :  Ce module calcule la validité des valeurs à apprendre.     */
/* !Number      :  FCT5.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input sint16 Misf_prm_tiDlyExpWinLrn[4][9];                               */
/*  input sint16 Mf_adap_Exp_err_mv_i_uavn1[4];                               */
/*  input uint16 Mf_adap_Exp_corr_dlta_max[4][9];                             */
/*  input sint16 Misf_prm_tiDlyTDCWinLrn[4][9];                               */
/*  input sint16 Mf_adap_TDC_err_mv_i_uavn1[4];                               */
/*  input uint16 Mf_adap_TDC_corr_dlta_max[4][9];                             */
/*  input sint16 Misf_prm_tiDlyBdcWinLrn[4][9];                               */
/*  input sint16 Mf_adap_Bdc_err_mv_i_uavn1[4];                               */
/*  input uint16 Mf_adap_Bdc_corr_dlta_max[4][9];                             */
/*  output boolean Misf_bMonRunORng_ShrtWinLrn;                               */
/*  output boolean Misf_bDgoORng_ShrtWinLrn;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcDelta(void)
{
   boolean bLocalExpWinLrn;
   boolean bLocalTDCWinLrn;
   boolean bLocalBdcWinLrn;
   uint8   u8LocalMisf_noCyl;
   uint8   u8LocalMfAdapBkptIndPrevUavn0;
   uint16  u16LocalExpCorrDeltaMax;
   uint16  u16LocalTDCCorrDeltaMax;
   uint16  u16LocalBdcCorrDeltaMax;
   sint16  s16LocalExpErrMvIUavn0;
   sint16  s16LocaltiDlyExpWinLrn;
   sint16  s16LocalTDCErrMvIUavn0;
   sint16  s16LocaltiDlyTDCWinLrn;
   sint16  s16LocalBdcErrMvIUavn0;
   sint16  s16LocaltiDlyBdcWinLrn;
   sint16  s16LocalMfAdapBkptIndPrevUavn0;
   uint32  u32LocalExp;
   uint32  u32LocalTDC;
   uint32  u32LocalBdc;
   sint32  s32LocalExp;
   sint32  s32LocalTDC;
   sint32  s32LocalBdc;


   Misf_bMonRunORng_ShrtWinLrn = 1;
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

         /* Fenêtre courte détente*/
         s16LocaltiDlyExpWinLrn =
            Misf_prm_tiDlyExpWinLrn[u8LocalMisf_noCyl]
                                   [u8LocalMfAdapBkptIndPrevUavn0];
         s16LocalExpErrMvIUavn0 =
            Mf_adap_Exp_err_mv_i_uavn1[u8LocalMisf_noCyl];
         s32LocalExp = s16LocaltiDlyExpWinLrn + s16LocalExpErrMvIUavn0;
         u32LocalExp = (uint32)MATHSRV_udtABS(s32LocalExp);
         u32LocalExp = u32LocalExp * 2;

         u16LocalExpCorrDeltaMax =
            Mf_adap_Exp_corr_dlta_max[u8LocalMisf_noCyl]
                                     [u8LocalMfAdapBkptIndPrevUavn0];


         if (u32LocalExp <= u16LocalExpCorrDeltaMax)
         {
            bLocalExpWinLrn = 1;
         }
         else
         {
            bLocalExpWinLrn = 0;
         }

         /* Fenêtre courte PMH*/

         s16LocaltiDlyTDCWinLrn =
            Misf_prm_tiDlyTDCWinLrn[u8LocalMisf_noCyl]
                                   [u8LocalMfAdapBkptIndPrevUavn0];
         s16LocalTDCErrMvIUavn0 =
            Mf_adap_TDC_err_mv_i_uavn1[u8LocalMisf_noCyl];
         s32LocalTDC = s16LocaltiDlyTDCWinLrn + s16LocalTDCErrMvIUavn0;
         u32LocalTDC = (uint32)MATHSRV_udtABS(s32LocalTDC);
         u32LocalTDC = u32LocalTDC * 2;

         u16LocalTDCCorrDeltaMax =
            Mf_adap_TDC_corr_dlta_max[u8LocalMisf_noCyl]
                                     [u8LocalMfAdapBkptIndPrevUavn0];


         if (u32LocalTDC <= u16LocalTDCCorrDeltaMax)
         {
            bLocalTDCWinLrn = 1;
         }
         else
         {
            bLocalTDCWinLrn = 0;
         }

         /* Fenêtre courte détente*/

         s16LocaltiDlyBdcWinLrn =
            Misf_prm_tiDlyBdcWinLrn[u8LocalMisf_noCyl]
                                   [u8LocalMfAdapBkptIndPrevUavn0];
         s16LocalBdcErrMvIUavn0 =
            Mf_adap_Bdc_err_mv_i_uavn1[u8LocalMisf_noCyl];
         s32LocalBdc = s16LocaltiDlyBdcWinLrn + s16LocalBdcErrMvIUavn0;
         u32LocalBdc = (uint32)MATHSRV_udtABS(s32LocalBdc);
         u32LocalBdc = u32LocalBdc * 2;

         u16LocalBdcCorrDeltaMax =
            Mf_adap_Bdc_corr_dlta_max[u8LocalMisf_noCyl]
                                     [u8LocalMfAdapBkptIndPrevUavn0];


         if (u32LocalBdc <= u16LocalBdcCorrDeltaMax)
         {
            bLocalBdcWinLrn = 1;
         }
         else
         {
            bLocalBdcWinLrn = 0;
         }

         if (  (bLocalExpWinLrn != 0)
            && (bLocalTDCWinLrn != 0)
            && (bLocalBdcWinLrn != 0))
         {
            Misf_bDgoORng_ShrtWinLrn = 0;
         }
         else
         {
            Misf_bDgoORng_ShrtWinLrn = 1;
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
/****************************** end of file ***********************************/
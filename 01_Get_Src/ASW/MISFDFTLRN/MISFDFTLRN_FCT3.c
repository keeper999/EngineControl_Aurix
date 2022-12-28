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
/* !File            : MISFDFTLRN_FCT3.C                                       */
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
/*   1 / MISFDFTLRN_vidTDCWinVar                                              */
/*   2 / MISFDFTLRN_vidExpWinVar                                              */
/*   3 / MISFDFTLRN_vidBdcWinVar                                              */
/*   4 / MISFDFTLRN_vidCalcSumDeltaPrecal                                     */
/*   5 / MISFDFTLRN_vidCalcDeltaLw                                            */
/*   6 / MISFDFTLRN_vidCalcDeltaExp                                           */
/*   7 / MISFDFTLRN_vidCalcDeltaTdc                                           */
/*   8 / MISFDFTLRN_vidCalcDeltaBdc                                           */
/*   9 / MISFDFTLRN_vidWinAdap                                                */
/*   10 / MISFDFTLRN_vidWinAdapSave                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5069555 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#068760                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDFTLRN/MISFDFTLRN_FCT3.C_$*/
/* $Revision::   1.16     $$Author::   achebino       $$Date::   06 Jul 2012 $*/
/* $Author::   achebino                               $$Date::   06 Jul 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "MISFDFTLRN.h"
#include "MISFDFTLRN_L.h"
#include "MISFDFTLRN_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidTDCWinVar                                    */
/* !Description :  Ce module filtre l’erreur brute et calcule l’écart entre   */
/*                 les erreurs brute et filtrée des fenêtres courtes PMH      */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  input uint8 Mf_adap_n_bkpt_uacn1[9];                                      */
/*  input uint8 Mf_adap_TDC_err_gain_ut_uacn0;                                */
/*  input uint8 Mf_adap_TDC_er_dif_gain_ut_uacn0;                             */
/*  input uint16 Mf_adap_TDC_err_dif_lth_ut_uacn0;                            */
/*  input uint16 Mf_adap_TDC_err_dif_hth_ut_uacn1[9];                         */
/*  input uint8 Mf_adap_TDC_err_gain_uacn0;                                   */
/*  input uint8 Mf_adap_TDC_err_dif_gain_uacn0;                               */
/*  input uint16 Mf_adap_TDC_err_dif_lth_uacn0;                               */
/*  input uint16 Mf_adap_TDC_err_dif_hth_uacn1[9];                            */
/*  input sint16 Mf_adap_TDC_err_filt_uavn1[4];                               */
/*  input sint16 Misf_TDCWinErrRaw[4];                                        */
/*  input sint16 Mf_adap_TDC_err_dif_pos_uavn1[4];                            */
/*  input sint16 Mf_adap_TDC_err_dif_neg_uavn1[4];                            */
/*  input boolean MISFDFTLRN_bTDCHystOut;                                     */
/*  input boolean Mf_adap_TDC_cond_ok_uavb1[4];                               */
/*  output sint16 Mf_adap_TDC_err_filt_uavn1[4];                              */
/*  output sint16 Mf_adap_TDC_err_dif_raw_uavn1[4];                           */
/*  output sint16 Mf_adap_TDC_err_dif_pos_uavn1[4];                           */
/*  output sint16 Mf_adap_TDC_err_dif_neg_uavn1[4];                           */
/*  output uint16 Mf_adap_TDC_err_dif_filt_uavn1[4];                          */
/*  output boolean Mf_adap_TDC_cond_ok_uavb1[4];                              */
/*  output boolean Mf_adap_TDC_cond_ok_uavb0;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidTDCWinVar(void)
{
   boolean bLocalSrv_bAcvPlaMod;
   uint8   u8LocalMisf_noCyl;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalMf_adap_TDC_err_gain;
   uint8   u8LocalMf_adap_TDC_err_dif_gain;
   uint16  u16LocalTDCErrDifFilt;
   uint16  u16LocalMf_adap_Threshold_1;
   uint16  u16LocalMf_adap_Threshold_2;
   uint16  u16LocalCalcPara;
   sint16  s16LocalTDCErrFiltUavn0;
   sint16  s16LocalTDCWinErrRaw;
   sint16  s16LocalTDCErrFilt;
   sint16  s16LocalTDCErrDifRawUavn0;
   sint16  s16LocalTDCErrDifPosUavn0;
   sint16  s16LocalTDCErrDifPos;
   sint16  s16LocalTDCErrDifNegUavn0;
   sint16  s16LocalTDCErrDifNeg;
   uint32  u32LocalTDCErrDifPosUavn0;
   uint32  u32LocalTDCErrDifNegUavn0;
   uint32  u32LocalTDCErrDifFiltMax;
   uint32  u32LocalTDCErrDifFilt;
   sint32  s32LocalTDCErrDifRawUavn0;
   sint32  s32LocalTDCErrDifPosUavn0;
   sint32  s32LocalTDCErrDifNegUavn0;


   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Srv_bAcvPlaMod, bLocalSrv_bAcvPlaMod);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(Mf_adap_n_bkpt_uacn1,
                                                  u8LocalRegime_moteur_32,
                                                  9);
   if (bLocalSrv_bAcvPlaMod != 0)
   {
      u8LocalMf_adap_TDC_err_gain = Mf_adap_TDC_err_gain_ut_uacn0;
      u8LocalMf_adap_TDC_err_dif_gain = Mf_adap_TDC_er_dif_gain_ut_uacn0;
      u16LocalMf_adap_Threshold_1 = Mf_adap_TDC_err_dif_lth_ut_uacn0;
      u16LocalMf_adap_Threshold_2 =
         MATHSRV_u16Interp1d(Mf_adap_TDC_err_dif_hth_ut_uacn1,
                             u16LocalCalcPara);
   }
   else
   {
      u8LocalMf_adap_TDC_err_gain = Mf_adap_TDC_err_gain_uacn0;
      u8LocalMf_adap_TDC_err_dif_gain = Mf_adap_TDC_err_dif_gain_uacn0;
      u16LocalMf_adap_Threshold_1 = Mf_adap_TDC_err_dif_lth_uacn0;
      u16LocalMf_adap_Threshold_2 =
         MATHSRV_u16Interp1d(Mf_adap_TDC_err_dif_hth_uacn1, u16LocalCalcPara);
   }
   switch(u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         /* Calcul de Mf_adap_TDC_err_filt_uavn1 */
         s16LocalTDCErrFiltUavn0 =
            Mf_adap_TDC_err_filt_uavn1[u8LocalMisf_noCyl];
         s16LocalTDCWinErrRaw = Misf_TDCWinErrRaw[u8LocalMisf_noCyl];
         s16LocalTDCErrFilt =
            (sint16)( ( ( ( (sint32)( s16LocalTDCWinErrRaw
                                    - s16LocalTDCErrFiltUavn0))
                        * u8LocalMf_adap_TDC_err_gain)
                      / 256)
                    + s16LocalTDCErrFiltUavn0);
         Mf_adap_TDC_err_filt_uavn1[u8LocalMisf_noCyl] = s16LocalTDCErrFilt;

         /* Calcul de Mf_adap_TDC_err_dif_raw_uavn1 */
         s32LocalTDCErrDifRawUavn0 =
            (s16LocalTDCWinErrRaw - s16LocalTDCErrFilt);
         s16LocalTDCErrDifRawUavn0 =
            (sint16)MATHSRV_udtCLAMP(s32LocalTDCErrDifRawUavn0, -32768, 32767);
         Mf_adap_TDC_err_dif_raw_uavn1[u8LocalMisf_noCyl] =
            s16LocalTDCErrDifRawUavn0;

          /* Calcul de Mf_adap_TDC_err_dif_pos_uavn1 */
         s16LocalTDCErrDifPosUavn0 =
            Mf_adap_TDC_err_dif_pos_uavn1[u8LocalMisf_noCyl];
         s32LocalTDCErrDifPosUavn0 = ( ( ( ( s32LocalTDCErrDifRawUavn0
                                           - s16LocalTDCErrDifPosUavn0))
                                         * u8LocalMf_adap_TDC_err_dif_gain)
                                       / 256)
                                     + s16LocalTDCErrDifPosUavn0;
         s16LocalTDCErrDifPos =
            (sint16)MATHSRV_udtCLAMP(s32LocalTDCErrDifPosUavn0, -32768, 32767);
         Mf_adap_TDC_err_dif_pos_uavn1[u8LocalMisf_noCyl] =
            s16LocalTDCErrDifPos;

         /* Calcul de Mf_adap_TDC_err_dif_neg_uavn1 */
         s16LocalTDCErrDifNegUavn0 =
            Mf_adap_TDC_err_dif_neg_uavn1[u8LocalMisf_noCyl];
         s32LocalTDCErrDifNegUavn0 = ( ( ( ( s32LocalTDCErrDifRawUavn0
                                           - s16LocalTDCErrDifNegUavn0))
                                         * u8LocalMf_adap_TDC_err_dif_gain)
                                       / 256)
                                     + s16LocalTDCErrDifNegUavn0;
         s16LocalTDCErrDifNeg =
            (sint16)MATHSRV_udtCLAMP(s32LocalTDCErrDifNegUavn0, -32768, 32767);
         Mf_adap_TDC_err_dif_neg_uavn1[u8LocalMisf_noCyl] =
            s16LocalTDCErrDifNeg;

         /* Calcul de Mf_adap_TDC_err_dif_filt_uavn1 */
         u32LocalTDCErrDifPosUavn0 =
            (uint32)MATHSRV_udtABS(s32LocalTDCErrDifPosUavn0);
         u32LocalTDCErrDifNegUavn0 =
            (uint32)MATHSRV_udtABS(s32LocalTDCErrDifNegUavn0);
         u32LocalTDCErrDifFiltMax = MATHSRV_udtMAX(u32LocalTDCErrDifPosUavn0,
                                                   u32LocalTDCErrDifNegUavn0);
         u32LocalTDCErrDifFilt = u32LocalTDCErrDifFiltMax * 2;

         u16LocalTDCErrDifFilt =
            (uint16)MATHSRV_udtMIN(u32LocalTDCErrDifFilt, 65535);
         Mf_adap_TDC_err_dif_filt_uavn1[u8LocalMisf_noCyl] =
            u16LocalTDCErrDifFilt;

         MATHSRV_vidSchmittTriggerU16(u16LocalTDCErrDifFilt,
                                      u16LocalMf_adap_Threshold_1,
                                      u16LocalMf_adap_Threshold_2,
                                      MATHSRV_FALLING_SCHMITT_TRIGGER,
                                      &MISFDFTLRN_bTDCHystOut);
         if (MISFDFTLRN_bTDCHystOut != 0)
         {
            Mf_adap_TDC_cond_ok_uavb1[u8LocalMisf_noCyl] = 1;
         }
         else
         {
            Mf_adap_TDC_cond_ok_uavb1[u8LocalMisf_noCyl] = 0;
         }

         if (  (Mf_adap_TDC_cond_ok_uavb1[0] != 0)
            && (Mf_adap_TDC_cond_ok_uavb1[1] != 0)
            && (Mf_adap_TDC_cond_ok_uavb1[2] != 0)
            && (Mf_adap_TDC_cond_ok_uavb1[3] != 0))
         {
            Mf_adap_TDC_cond_ok_uavb0 = 1;
         }
         else
         {
            Mf_adap_TDC_cond_ok_uavb0 = 0;
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
/* !Function    :  MISFDFTLRN_vidExpWinVar                                    */
/* !Description :  Ce module filtre l’erreur brute et calcule l’écart entre   */
/*                 les erreurs brute et filtrée des fenêtres courtes détentes.*/
/* !Number      :  FCT3.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  input uint8 Mf_adap_n_bkpt_uacn1[9];                                      */
/*  input uint8 Mf_adap_Exp_err_gain_ut_uacn0;                                */
/*  input uint8 Mf_adap_Exp_er_dif_gain_ut_uacn0;                             */
/*  input uint16 Mf_adap_Exp_err_dif_lth_ut_uacn0;                            */
/*  input uint16 Mf_adap_Exp_err_dif_hth_ut_uacn1[9];                         */
/*  input uint8 Mf_adap_Exp_err_gain_uacn0;                                   */
/*  input uint8 Mf_adap_Exp_err_dif_gain_uacn0;                               */
/*  input uint16 Mf_adap_Exp_err_dif_lth_uacn0;                               */
/*  input uint16 Mf_adap_Exp_err_dif_hth_uacn1[9];                            */
/*  input sint16 Mf_adap_Exp_err_filt_uavn1[4];                               */
/*  input sint16 Misf_ExpWinErrRaw[4];                                        */
/*  input sint16 Mf_adap_Exp_err_dif_pos_uavn1[4];                            */
/*  input sint16 Mf_adap_Exp_err_dif_neg_uavn1[4];                            */
/*  input boolean MISFDFTLRN_bExpHystOut;                                     */
/*  input boolean Mf_adap_Exp_cond_ok_uavb1[4];                               */
/*  output sint16 Mf_adap_Exp_err_filt_uavn1[4];                              */
/*  output sint16 Mf_adap_Exp_err_dif_raw_uavn1[4];                           */
/*  output sint16 Mf_adap_Exp_err_dif_pos_uavn1[4];                           */
/*  output sint16 Mf_adap_Exp_err_dif_neg_uavn1[4];                           */
/*  output uint16 Mf_adap_Exp_err_dif_filt_uavn1[4];                          */
/*  output boolean Mf_adap_Exp_cond_ok_uavb1[4];                              */
/*  output boolean Mf_adap_Exp_cond_ok_uavb0;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidExpWinVar(void)
{
   boolean bLocalSrv_bAcvPlaMod;
   uint8   u8LocalMisf_noCyl;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalMf_adap_Exp_err_gain;
   uint8   u8LocalMf_adap_Exp_err_dif_gain;
   uint16  u16LocalExpErrDifFilt;
   uint16  u16LocalMf_adap_Threshold_1;
   uint16  u16LocalMf_adap_Threshold_2;
   uint16  u16LocalCalcPara;
   sint16  s16LocalExpErrFiltUavn0;
   sint16  s16LocalExpWinErrRaw;
   sint16  s16LocalExpErrFilt;
   sint16  s16LocalExpErrDifRawUavn0;
   sint16  s16LocalExpErrDifPosUavn0;
   sint16  s16LocalExpErrDifPos;
   sint16  s16LocalExpErrDifNegUavn0;
   sint16  s16LocalExpErrDifNeg;
   uint32  u32LocalExpErrDifPosUavn0;
   uint32  u32LocalExpErrDifNegUavn0;
   uint32  u32LocalExpErrDifFiltMax;
   uint32  u32LocalExpErrDifFilt;
   sint32  s32LocalExpErrDifRawUavn0;
   sint32  s32LocalExpErrDifPosUavn0;
   sint32  s32LocalExpErrDifNegUavn0;


   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Srv_bAcvPlaMod, bLocalSrv_bAcvPlaMod);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(Mf_adap_n_bkpt_uacn1,
                                                  u8LocalRegime_moteur_32,
                                                  9);
   if (bLocalSrv_bAcvPlaMod != 0)
   {
      u8LocalMf_adap_Exp_err_gain = Mf_adap_Exp_err_gain_ut_uacn0;
      u8LocalMf_adap_Exp_err_dif_gain = Mf_adap_Exp_er_dif_gain_ut_uacn0;
      u16LocalMf_adap_Threshold_1 = Mf_adap_Exp_err_dif_lth_ut_uacn0;
      u16LocalMf_adap_Threshold_2 =
         MATHSRV_u16Interp1d(Mf_adap_Exp_err_dif_hth_ut_uacn1,
                             u16LocalCalcPara);
   }
   else
   {
      u8LocalMf_adap_Exp_err_gain = Mf_adap_Exp_err_gain_uacn0;
      u8LocalMf_adap_Exp_err_dif_gain = Mf_adap_Exp_err_dif_gain_uacn0;
      u16LocalMf_adap_Threshold_1 = Mf_adap_Exp_err_dif_lth_uacn0;
      u16LocalMf_adap_Threshold_2 =
         MATHSRV_u16Interp1d(Mf_adap_Exp_err_dif_hth_uacn1, u16LocalCalcPara);
   }

   switch(u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         /* Calcul de Mf_adap_Exp_err_filt_uavn1 */
         s16LocalExpErrFiltUavn0 =
            Mf_adap_Exp_err_filt_uavn1[u8LocalMisf_noCyl];
         s16LocalExpWinErrRaw = Misf_ExpWinErrRaw[u8LocalMisf_noCyl];

         s16LocalExpErrFilt =
            (sint16)( ( ( ( (sint32)( s16LocalExpWinErrRaw
                                    - s16LocalExpErrFiltUavn0))
                          * u8LocalMf_adap_Exp_err_gain)
                        / 256)
                    + s16LocalExpErrFiltUavn0);
         Mf_adap_Exp_err_filt_uavn1[u8LocalMisf_noCyl] = s16LocalExpErrFilt;

         /* Calcul de Mf_adap_Exp_err_dif_raw_uavn1 */
         s32LocalExpErrDifRawUavn0 = ( s16LocalExpWinErrRaw
                                     - s16LocalExpErrFilt);
         s16LocalExpErrDifRawUavn0 =
            (sint16)MATHSRV_udtCLAMP(s32LocalExpErrDifRawUavn0, -32768, 32767);
         Mf_adap_Exp_err_dif_raw_uavn1[u8LocalMisf_noCyl] =
            s16LocalExpErrDifRawUavn0;


          /* Calcul de Mf_adap_Exp_err_dif_pos_uavn1 */
         s16LocalExpErrDifPosUavn0 =
            Mf_adap_Exp_err_dif_pos_uavn1[u8LocalMisf_noCyl];
         s32LocalExpErrDifPosUavn0 = ( ( ( ( s32LocalExpErrDifRawUavn0
                                           - s16LocalExpErrDifPosUavn0))
                                         * u8LocalMf_adap_Exp_err_dif_gain)
                                       / 256)
                                     + s16LocalExpErrDifPosUavn0;
         s16LocalExpErrDifPos =
            (sint16)MATHSRV_udtCLAMP(s32LocalExpErrDifPosUavn0, -32768, 32767);
         Mf_adap_Exp_err_dif_pos_uavn1[u8LocalMisf_noCyl] =
            s16LocalExpErrDifPos;

         /* Calcul de Mf_adap_Exp_err_dif_neg_uavn1 */
         s16LocalExpErrDifNegUavn0 =
            Mf_adap_Exp_err_dif_neg_uavn1[u8LocalMisf_noCyl];
         s32LocalExpErrDifNegUavn0 = ( ( ( ( s32LocalExpErrDifRawUavn0
                                           - s16LocalExpErrDifNegUavn0))
                                         * u8LocalMf_adap_Exp_err_dif_gain)
                                       / 256)
                                     + s16LocalExpErrDifNegUavn0;
         s16LocalExpErrDifNeg =
            (sint16)MATHSRV_udtCLAMP(s32LocalExpErrDifNegUavn0, -32768, 32767);
         Mf_adap_Exp_err_dif_neg_uavn1[u8LocalMisf_noCyl] =
            s16LocalExpErrDifNeg;

         /* Calcul de Mf_adap_Exp_err_dif_filt_uavn1 */
         u32LocalExpErrDifPosUavn0 =
            (uint32)MATHSRV_udtABS(s32LocalExpErrDifPosUavn0);
         u32LocalExpErrDifNegUavn0 =
            (uint32)MATHSRV_udtABS(s32LocalExpErrDifNegUavn0);
         u32LocalExpErrDifFiltMax = MATHSRV_udtMAX(u32LocalExpErrDifPosUavn0,
                                                   u32LocalExpErrDifNegUavn0);
         u32LocalExpErrDifFilt = u32LocalExpErrDifFiltMax * 2;

         u16LocalExpErrDifFilt = (uint16)MATHSRV_udtMIN(u32LocalExpErrDifFilt,
                                                        65535);
         Mf_adap_Exp_err_dif_filt_uavn1[u8LocalMisf_noCyl] =
            u16LocalExpErrDifFilt;

         MATHSRV_vidSchmittTriggerU16(u16LocalExpErrDifFilt,
                                      u16LocalMf_adap_Threshold_1,
                                      u16LocalMf_adap_Threshold_2,
                                      MATHSRV_FALLING_SCHMITT_TRIGGER,
                                      &MISFDFTLRN_bExpHystOut);
         if (MISFDFTLRN_bExpHystOut != 0)
         {
            Mf_adap_Exp_cond_ok_uavb1[u8LocalMisf_noCyl] = 1;
         }
         else
         {
            Mf_adap_Exp_cond_ok_uavb1[u8LocalMisf_noCyl] = 0;
         }

         if (  (Mf_adap_Exp_cond_ok_uavb1[0] != 0)
            && (Mf_adap_Exp_cond_ok_uavb1[1] != 0)
            && (Mf_adap_Exp_cond_ok_uavb1[2] != 0)
            && (Mf_adap_Exp_cond_ok_uavb1[3] != 0))
         {
            Mf_adap_Exp_cond_ok_uavb0 = 1;
         }
         else
         {
            Mf_adap_Exp_cond_ok_uavb0 = 0;
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
/* !Function    :  MISFDFTLRN_vidBdcWinVar                                    */
/* !Description :  Ce module filtre l’erreur brute et calcule l’écart entre   */
/*                 les erreurs brute et filtrée des fenêtres courtes PMB      */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  input uint8 Mf_adap_n_bkpt_uacn1[9];                                      */
/*  input uint8 Mf_adap_Bdc_err_gain_ut_uacn0;                                */
/*  input uint8 Mf_adap_Bdc_er_dif_gain_ut_uacn;                              */
/*  input uint16 Mf_adap_Bdc_err_dif_lth_ut_uacn0;                            */
/*  input uint16 Mf_adap_Bdc_err_dif_hth_ut_uacn1[9];                         */
/*  input uint8 Mf_adap_Bdc_err_gain_uacn0;                                   */
/*  input uint8 Mf_adap_Bdc_err_dif_gain_uacn0;                               */
/*  input uint16 Mf_adap_Bdc_err_dif_lth_uacn0;                               */
/*  input uint16 Mf_adap_Bdc_err_dif_hth_uacn1[9];                            */
/*  input sint16 Mf_adap_Bdc_err_filt_uavn1[4];                               */
/*  input sint16 Misf_BdcWinErrRaw[4];                                        */
/*  input sint16 Mf_adap_Bdc_err_dif_pos_uavn1[4];                            */
/*  input sint16 Mf_adap_Bdc_err_dif_neg_uavn1[4];                            */
/*  input boolean MISFDFTLRN_bBdcHystOut;                                     */
/*  input boolean Mf_adap_Bdc_cond_ok_uavb1[4];                               */
/*  output sint16 Mf_adap_Bdc_err_filt_uavn1[4];                              */
/*  output sint16 Mf_adap_Bdc_err_dif_raw_uavn1[4];                           */
/*  output sint16 Mf_adap_Bdc_err_dif_pos_uavn1[4];                           */
/*  output sint16 Mf_adap_Bdc_err_dif_neg_uavn1[4];                           */
/*  output uint16 Mf_adap_Bdc_err_dif_filt_uavn1[4];                          */
/*  output boolean Mf_adap_Bdc_cond_ok_uavb1[4];                              */
/*  output boolean Mf_adap_Bdc_cond_ok_uavb0;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidBdcWinVar(void)
{
   boolean bLocalSrv_bAcvPlaMod;
   uint8   u8LocalMisf_noCyl;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalMf_adap_Bdc_err_gain;
   uint8   u8LocalMf_adap_Bdc_err_dif_gain;
   uint16  u16LocalBdcErrDifFilt;
   uint16  u16LocalMf_adap_Threshold_1;
   uint16  u16LocalMf_adap_Threshold_2;
   uint16  u16LocalCalcPara;
   sint16  s16LocalBdcErrFiltUavn0;
   sint16  s16LocalBdcWinErrRaw;
   sint16  s16LocalBdcErrFilt;
   sint16  s16LocalBdcErrDifRawUavn0;
   sint16  s16LocalBdcErrDifPosUavn0;
   sint16  s16LocalBdcErrDifPos;
   sint16  s16LocalBdcErrDifNegUavn0;
   sint16  s16LocalBdcErrDifNeg;
   uint32  u32LocalBdcErrDifPosUavn0;
   uint32  u32LocalBdcErrDifNegUavn0;
   uint32  u32LocalBdcErrDifFiltMax;
   uint32  u32LocalBdcErrDifFilt;
   sint32  s32LocalBdcErrDifRawUavn0;
   sint32  s32LocalBdcErrDifPosUavn0;
   sint32  s32LocalBdcErrDifNegUavn0;


   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Srv_bAcvPlaMod, bLocalSrv_bAcvPlaMod);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(Mf_adap_n_bkpt_uacn1,
                                                  u8LocalRegime_moteur_32,
                                                  9);
   if (bLocalSrv_bAcvPlaMod != 0)
   {
      u8LocalMf_adap_Bdc_err_gain = Mf_adap_Bdc_err_gain_ut_uacn0;
      u8LocalMf_adap_Bdc_err_dif_gain = Mf_adap_Bdc_er_dif_gain_ut_uacn;
      u16LocalMf_adap_Threshold_1 = Mf_adap_Bdc_err_dif_lth_ut_uacn0;
      u16LocalMf_adap_Threshold_2 =
         MATHSRV_u16Interp1d(Mf_adap_Bdc_err_dif_hth_ut_uacn1,
                             u16LocalCalcPara);
   }
   else
   {
      u8LocalMf_adap_Bdc_err_gain = Mf_adap_Bdc_err_gain_uacn0;
      u8LocalMf_adap_Bdc_err_dif_gain = Mf_adap_Bdc_err_dif_gain_uacn0;
      u16LocalMf_adap_Threshold_1 = Mf_adap_Bdc_err_dif_lth_uacn0;
      u16LocalMf_adap_Threshold_2 =
         MATHSRV_u16Interp1d(Mf_adap_Bdc_err_dif_hth_uacn1, u16LocalCalcPara);
   }

   switch(u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         /* Calcul de Mf_adap_Bdc_err_filt_uavn1 */
         s16LocalBdcErrFiltUavn0 =
            Mf_adap_Bdc_err_filt_uavn1[u8LocalMisf_noCyl];
         s16LocalBdcWinErrRaw = Misf_BdcWinErrRaw[u8LocalMisf_noCyl];

         s16LocalBdcErrFilt =
            (sint16)( ( ( ( (sint32)( s16LocalBdcWinErrRaw
                                    - s16LocalBdcErrFiltUavn0))
                          * u8LocalMf_adap_Bdc_err_gain)
                       / 256)
                    + s16LocalBdcErrFiltUavn0);
         Mf_adap_Bdc_err_filt_uavn1[u8LocalMisf_noCyl] = s16LocalBdcErrFilt;

         /* Calcul de Mf_adap_Bdc_err_dif_raw_uavn1 */
         s32LocalBdcErrDifRawUavn0 = ( s16LocalBdcWinErrRaw
                                     - s16LocalBdcErrFilt);
         s16LocalBdcErrDifRawUavn0 =
            (sint16)MATHSRV_udtCLAMP(s32LocalBdcErrDifRawUavn0, -32768, 32767);
         Mf_adap_Bdc_err_dif_raw_uavn1[u8LocalMisf_noCyl] =
            s16LocalBdcErrDifRawUavn0;

          /* Calcul de Mf_adap_Bdc_err_dif_pos_uavn1 */
         s16LocalBdcErrDifPosUavn0 =
            Mf_adap_Bdc_err_dif_pos_uavn1[u8LocalMisf_noCyl];
         s32LocalBdcErrDifPosUavn0 = ( ( ( ( s32LocalBdcErrDifRawUavn0
                                           - s16LocalBdcErrDifPosUavn0))
                                         * u8LocalMf_adap_Bdc_err_dif_gain)
                                       / 256)
                                     + s16LocalBdcErrDifPosUavn0;
         s16LocalBdcErrDifPos =
            (sint16)MATHSRV_udtCLAMP(s32LocalBdcErrDifPosUavn0, -32768, 32767);
         Mf_adap_Bdc_err_dif_pos_uavn1[u8LocalMisf_noCyl] =
            s16LocalBdcErrDifPos;

         /* Calcul de Mf_adap_Bdc_err_dif_neg_uavn1 */
         s16LocalBdcErrDifNegUavn0 =
            Mf_adap_Bdc_err_dif_neg_uavn1[u8LocalMisf_noCyl];
         s32LocalBdcErrDifNegUavn0 = ( ( ( ( s32LocalBdcErrDifRawUavn0
                                           - s16LocalBdcErrDifNegUavn0))
                                         * u8LocalMf_adap_Bdc_err_dif_gain)
                                       / 256)
                                     + s16LocalBdcErrDifNegUavn0;
         s16LocalBdcErrDifNeg =
            (sint16)MATHSRV_udtCLAMP(s32LocalBdcErrDifNegUavn0, -32768, 32767);
         Mf_adap_Bdc_err_dif_neg_uavn1[u8LocalMisf_noCyl] =
            s16LocalBdcErrDifNeg;

         /* Calcul de Mf_adap_Bdc_err_dif_filt_uavn1 */
         u32LocalBdcErrDifPosUavn0 =
            (uint32)MATHSRV_udtABS(s32LocalBdcErrDifPosUavn0);
         u32LocalBdcErrDifNegUavn0 =
            (uint32)MATHSRV_udtABS(s32LocalBdcErrDifNegUavn0);
         u32LocalBdcErrDifFiltMax = MATHSRV_udtMAX(u32LocalBdcErrDifPosUavn0,
                                                   u32LocalBdcErrDifNegUavn0);
         u32LocalBdcErrDifFilt = u32LocalBdcErrDifFiltMax * 2;

         u16LocalBdcErrDifFilt = (uint16)MATHSRV_udtMIN(u32LocalBdcErrDifFilt,
                                                        65535);
         Mf_adap_Bdc_err_dif_filt_uavn1[u8LocalMisf_noCyl] =
            u16LocalBdcErrDifFilt;

         MATHSRV_vidSchmittTriggerU16(u16LocalBdcErrDifFilt,
                                      u16LocalMf_adap_Threshold_1,
                                      u16LocalMf_adap_Threshold_2,
                                      MATHSRV_FALLING_SCHMITT_TRIGGER,
                                      &MISFDFTLRN_bBdcHystOut);
         if (MISFDFTLRN_bBdcHystOut != 0)
         {
            Mf_adap_Bdc_cond_ok_uavb1[u8LocalMisf_noCyl] = 1;
         }
         else
         {
            Mf_adap_Bdc_cond_ok_uavb1[u8LocalMisf_noCyl] = 0;
         }

         if (  (Mf_adap_Bdc_cond_ok_uavb1[0] != 0)
            && (Mf_adap_Bdc_cond_ok_uavb1[1] != 0)
            && (Mf_adap_Bdc_cond_ok_uavb1[2] != 0)
            && (Mf_adap_Bdc_cond_ok_uavb1[3] != 0))
         {
            Mf_adap_Bdc_cond_ok_uavb0 = 1;
         }
         else
         {
            Mf_adap_Bdc_cond_ok_uavb0 = 0;
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
/* !Function    :  MISFDFTLRN_vidCalcSumDeltaPrecal                           */
/* !Description :  Ce bloc permet de calculer une moyenne de l’erreur filtrée */
/*                 sur tous les cylindres sur toute la plage de régime, et pas*/
/*                 uniquement à l’approche d’un point d’appui.                */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void MISFDFTLRN_vidCalcDeltaLw();                             */
/*  extf argret void MISFDFTLRN_vidCalcDeltaExp();                            */
/*  extf argret void MISFDFTLRN_vidCalcDeltaTdc();                            */
/*  extf argret void MISFDFTLRN_vidCalcDeltaBdc();                            */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Mf_adap_delta_count_uavn1[4];                                 */
/*  output uint8 Mf_adap_delta_count_uavn1[4];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcSumDeltaPrecal(void)
{
   uint8  u8LocalMfadapdeltacountuavn1;
   uint8  u8LocalMisf_noCyl;
   uint16 u16LocalMfadapdeltacountuavn1;


   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);

   switch(u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         /* Calcul de Mf_adap_Exp_err_filt_uavn1 */
         u8LocalMfadapdeltacountuavn1 =
            Mf_adap_delta_count_uavn1[u8LocalMisf_noCyl];
         u16LocalMfadapdeltacountuavn1 =
            (uint16)(u8LocalMfadapdeltacountuavn1 + 1);
         Mf_adap_delta_count_uavn1[u8LocalMisf_noCyl] =
            (uint8)MATHSRV_udtMIN(u16LocalMfadapdeltacountuavn1, 255);

         break;

      case 4:
      case 5:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   MISFDFTLRN_vidCalcDeltaLw();
   MISFDFTLRN_vidCalcDeltaExp();
   MISFDFTLRN_vidCalcDeltaTdc();
   MISFDFTLRN_vidCalcDeltaBdc();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCalcDeltaLw                                  */
/* !Description :  ce bloc permet de calculer l'offset moyen appliqué entre   */
/*                 l'erreur filtrée et la précalibration (fenêtre Lw).        */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Mf_adap_n_bkpt_uacn1[9];                                      */
/*  input uint16 Mf_adap_lw_corr_precal_uacn2[4][9];                          */
/*  input sint32 Mf_adap_lw_err_filt_uavn1[4];                                */
/*  input sint16 Mf_adap_lw_corr_precal_uavn0;                                */
/*  input uint8 Mf_adap_delta_count_uavn1[4];                                 */
/*  input sint16 Mf_adap_lw_delta_uavn1[4];                                   */
/*  output sint16 Mf_adap_lw_corr_precal_uavn0;                               */
/*  output sint16 Mf_adap_lw_delta_uavn1[4];                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcDeltaLw(void)
{
   /* 01_calc_delta_lw */
   uint8  u8LocalMfadapdeltacountuavn1;
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalMisf_noCyl;
   uint8  u8LocalMisf_noCylind;
   uint8  u8LocalMfadapdeltacountuavn;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalCalcInterp_2d;
   uint16 u16LocalAbs;
   uint32 u32LocalMfadaplwcorrprecalSomm;
   uint32 u32LocalMfadaplwerrfiltuavn1;
   uint32 u32LocalSomm;
   sint16 s16LocalMfadapdeltacountuavn1;
   sint32 s32LocalMfadaplwcorrprecalSomm;
   sint32 s32LocalMfadaplwcorrprecalMul;
   sint32 s32LocalMfadaplwcorrprecalAdd;
   sint32 s32LocalMfadaplwerrfiltuavn1;
   sint32 s32LocalTemp;


   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   u8LocalMisf_noCylind = (uint8)MATHSRV_udtMIN(u8LocalMisf_noCyl, 3);

   u16LocalCalcParaX = (uint16)(u8LocalMisf_noCylind * 256);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU8(Mf_adap_n_bkpt_uacn1,
                                                   u8LocalRegime_moteur_32,
                                                   9);
   u16LocalCalcInterp_2d =
      MATHSRV_u16Interp2d(&Mf_adap_lw_corr_precal_uacn2[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   Mf_adap_lw_corr_precal_uavn0 = (sint16)(u16LocalCalcInterp_2d - 32768);

   switch (u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
      /* Mf_adap_lw_err_filt_uavn1[Misf_noCyl] + Mf_adap_lw_corr_precal_uavn0*/
         s32LocalMfadaplwerrfiltuavn1 =
            Mf_adap_lw_err_filt_uavn1[u8LocalMisf_noCyl];
         if (  (s32LocalMfadaplwerrfiltuavn1 < 0)
            && (Mf_adap_lw_corr_precal_uavn0 < 0))
         {
            u32LocalMfadaplwerrfiltuavn1 =
               (uint32)((-1) * (s32LocalMfadaplwerrfiltuavn1));
            u16LocalAbs = (uint16)((-1) * (Mf_adap_lw_corr_precal_uavn0));
            u32LocalSomm = u32LocalMfadaplwerrfiltuavn1 + u16LocalAbs;
            if (u32LocalSomm > 2147483648uL)
            {
               s32LocalMfadaplwcorrprecalSomm  = SINT32_MIN;
            }
            else
            {
               s32LocalMfadaplwcorrprecalSomm = s32LocalMfadaplwerrfiltuavn1
                                                 + Mf_adap_lw_corr_precal_uavn0;
            }
         }
         else
         {
            if (  (s32LocalMfadaplwerrfiltuavn1 >= 0)
               && (Mf_adap_lw_corr_precal_uavn0 >= 0))
            {
               u32LocalMfadaplwcorrprecalSomm =
                  (uint32)(s32LocalMfadaplwerrfiltuavn1
                        + Mf_adap_lw_corr_precal_uavn0);
               s32LocalMfadaplwcorrprecalSomm =
                  (sint32)MATHSRV_udtMIN(u32LocalMfadaplwcorrprecalSomm,
                                         2147483647uL);
            /*QAC Msg(3:3356): All cases are covered in the unit test*/
            }
            else
            {
               s32LocalMfadaplwcorrprecalSomm = s32LocalMfadaplwerrfiltuavn1
                                              + Mf_adap_lw_corr_precal_uavn0;
            }
         }
         /* calcul de Mf_adap_lw_delta_uavn1 */
         u8LocalMfadapdeltacountuavn1 =
            Mf_adap_delta_count_uavn1[u8LocalMisf_noCyl];
         s16LocalMfadapdeltacountuavn1 =
            Mf_adap_lw_delta_uavn1[u8LocalMisf_noCyl];

         u8LocalMfadapdeltacountuavn =
            (uint8)(u8LocalMfadapdeltacountuavn1 - 1);
         s32LocalMfadaplwcorrprecalMul =
            (sint32)( u8LocalMfadapdeltacountuavn
                    * s16LocalMfadapdeltacountuavn1);

         if (s32LocalMfadaplwcorrprecalSomm < 0)
         {
            if (s32LocalMfadaplwcorrprecalMul < 0)
            {
               s32LocalTemp = SINT32_MIN - s32LocalMfadaplwcorrprecalMul;
               if (s32LocalMfadaplwcorrprecalSomm <= s32LocalTemp)
               {
                  s32LocalMfadaplwcorrprecalAdd = SINT32_MIN;
               }
               else
               {
                  s32LocalMfadaplwcorrprecalAdd =
                     s32LocalMfadaplwcorrprecalMul
                     + s32LocalMfadaplwcorrprecalSomm;
               /* !Deviation: Violation of QAC_0279 rule.                     */
               /* !Reason : The result of this sum could never ovorload sint32*/
               }
            }
            else
            {
               s32LocalMfadaplwcorrprecalAdd = s32LocalMfadaplwcorrprecalMul
                                             + s32LocalMfadaplwcorrprecalSomm;
            }
         }
         else
         {
            if (s32LocalMfadaplwcorrprecalMul > 0)
            {
               s32LocalTemp = SINT32_MAX - s32LocalMfadaplwcorrprecalMul;
               if (s32LocalMfadaplwcorrprecalSomm >= s32LocalTemp)
               {
                  s32LocalMfadaplwcorrprecalAdd = SINT32_MAX;
               }
               else
               {
                  s32LocalMfadaplwcorrprecalAdd =
                     s32LocalMfadaplwcorrprecalMul
                     + s32LocalMfadaplwcorrprecalSomm;
               }
            }
            else
            {
               s32LocalMfadaplwcorrprecalAdd = s32LocalMfadaplwcorrprecalMul
                                             + s32LocalMfadaplwcorrprecalSomm;
            }
         }

         s32LocalMfadaplwcorrprecalAdd = ( s32LocalMfadaplwcorrprecalAdd
                                         / u8LocalMfadapdeltacountuavn1);

         Mf_adap_lw_delta_uavn1[u8LocalMisf_noCyl] =
            (sint16)MATHSRV_udtCLAMP(s32LocalMfadaplwcorrprecalAdd,
                                     -32768,
                                     32767);
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
/* !Function    :  MISFDFTLRN_vidCalcDeltaExp                                 */
/* !Description :  ce bloc permet de calculer l'Offset moyen entre l'erreur   */
/*                 filtrée et la précalibration (fenêtre Exp).                */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Mf_adap_n_bkpt_uacn1[9];                                      */
/*  input uint16 Mf_adap_Exp_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Exp_err_filt_uavn1[4];                               */
/*  input sint16 Mf_adap_Exp_corr_precal_uavn0;                               */
/*  input uint8 Mf_adap_delta_count_uavn1[4];                                 */
/*  input sint16 Mf_adap_Exp_delta_uavn1[4];                                  */
/*  output sint16 Mf_adap_Exp_corr_precal_uavn0;                              */
/*  output sint16 Mf_adap_Exp_delta_uavn1[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcDeltaExp(void)
{
   /* 02_calc_delta_Exp */
   uint8  u8LocalMfadapdeltacountuavn1;
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalMisf_noCyl;
   uint8  u8LocalMisf_noCylind;
   uint8  u8LocalMfadapdeltacountuavn;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalCalcInterp_2d;
   sint16 s16LocalMfadapExperrfiltuavn1;
   sint16 s16LocalMfadapdeltacountuavn1;
   sint32 s32LocalMfadapExpcorrprecalSomm;
   sint32 s32LocalMfadapExpcorrprecalMul;
   sint32 s32LocalMfadapExpcorrprecalAdd;


   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   u8LocalMisf_noCylind = (uint8)MATHSRV_udtMIN(u8LocalMisf_noCyl, 3);
   u16LocalCalcParaX = (uint16)(u8LocalMisf_noCylind * 256);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU8(Mf_adap_n_bkpt_uacn1,
                                                   u8LocalRegime_moteur_32,
                                                   9);
   u16LocalCalcInterp_2d =
      MATHSRV_u16Interp2d(&Mf_adap_Exp_corr_precal_uacn2[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   Mf_adap_Exp_corr_precal_uavn0 = (sint16)(u16LocalCalcInterp_2d - 32768);

   switch (u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         /* Mf_adap_Exp_err_filt_uavn1[Misf_noCyl] */
         /* + Mf_adap_Exp_corr_precal_uavn0        */
         s16LocalMfadapExperrfiltuavn1 =
            Mf_adap_Exp_err_filt_uavn1[u8LocalMisf_noCyl];
         s32LocalMfadapExpcorrprecalSomm = ( s16LocalMfadapExperrfiltuavn1
                                           + Mf_adap_Exp_corr_precal_uavn0);
         /* calcul de Mf_adap_Exp_delta_uavn1 */
         u8LocalMfadapdeltacountuavn1 =
            Mf_adap_delta_count_uavn1[u8LocalMisf_noCyl];
         s16LocalMfadapdeltacountuavn1 =
            Mf_adap_Exp_delta_uavn1[u8LocalMisf_noCyl];

         u8LocalMfadapdeltacountuavn =
            (uint8)(u8LocalMfadapdeltacountuavn1 - 1);
         s32LocalMfadapExpcorrprecalMul =
            (sint32)( u8LocalMfadapdeltacountuavn
                    * s16LocalMfadapdeltacountuavn1);

         s32LocalMfadapExpcorrprecalAdd =
                              (  ( ( s32LocalMfadapExpcorrprecalMul
                                   + s32LocalMfadapExpcorrprecalSomm)
                                 + (u8LocalMfadapdeltacountuavn1 / 2))
                              / u8LocalMfadapdeltacountuavn1);
         /* !Deviation: Violation of QAC_0585 rule.                       */
         /* !Reason : according to the global fuctionnality of the module,*/
         /* the case 0 of the denominator is urealisable as it's protected*/
         /* by the calling function MISFDFTLRN_vidCalcSumDeltaPrecal      */
         Mf_adap_Exp_delta_uavn1[u8LocalMisf_noCyl] =
            (sint16)MATHSRV_udtCLAMP(s32LocalMfadapExpcorrprecalAdd,
                                     -32768,
                                     32767);
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
/* !Function    :  MISFDFTLRN_vidCalcDeltaTdc                                 */
/* !Description :  ce bloc permet de calculer l'Offset moyen entre l'erreur   */
/*                 filtrée et la précalibration (fenêtre TDC).                */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Mf_adap_n_bkpt_uacn1[9];                                      */
/*  input uint16 Mf_adap_TDC_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_TDC_err_filt_uavn1[4];                               */
/*  input sint16 Mf_adap_TDC_corr_precal_uavn0;                               */
/*  input uint8 Mf_adap_delta_count_uavn1[4];                                 */
/*  input sint16 Mf_adap_TDC_delta_uavn1[4];                                  */
/*  output sint16 Mf_adap_TDC_corr_precal_uavn0;                              */
/*  output sint16 Mf_adap_TDC_delta_uavn1[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcDeltaTdc(void)
{
   /* 03_calc_delta_Tdc */
   uint8  u8LocalMfadapdeltacountuavn1;
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalMisf_noCyl;
   uint8  u8LocalMisf_noCylind;
   uint8  u8LocalMfadapdeltacountuavn;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalCalcInterp_2d;
   sint16 s16LocalMfadapTDCerrfiltuavn1;
   sint16 s16LocalMfadapdeltacountuavn1;
   sint32 s32LocalMfadapTDCcorrprecalSomm;
   sint32 s32LocalMfadapTDCcorrprecalMul;
   sint32 s32LocalMfadapTDCcorrprecalAdd;


   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   u8LocalMisf_noCylind = (uint8)MATHSRV_udtMIN(u8LocalMisf_noCyl, 3);
   u16LocalCalcParaX = (uint16)(u8LocalMisf_noCylind * 256);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU8(Mf_adap_n_bkpt_uacn1,
                                                   u8LocalRegime_moteur_32,
                                                   9);
   u16LocalCalcInterp_2d =
      MATHSRV_u16Interp2d(&Mf_adap_TDC_corr_precal_uacn2[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   Mf_adap_TDC_corr_precal_uavn0 = (sint16)(u16LocalCalcInterp_2d - 32768);

   switch (u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         /* Mf_adap_TDC_err_filt_uavn1[Misf_noCyl] */
         /* + Mf_adap_TDC_corr_precal_uavn0        */
         s16LocalMfadapTDCerrfiltuavn1 =
            Mf_adap_TDC_err_filt_uavn1[u8LocalMisf_noCyl];
         s32LocalMfadapTDCcorrprecalSomm = ( s16LocalMfadapTDCerrfiltuavn1
                                           + Mf_adap_TDC_corr_precal_uavn0);
         /* calcul de Mf_adap_TDC_delta_uavn1 */
         u8LocalMfadapdeltacountuavn1 =
            Mf_adap_delta_count_uavn1[u8LocalMisf_noCyl];
         s16LocalMfadapdeltacountuavn1 =
            Mf_adap_TDC_delta_uavn1[u8LocalMisf_noCyl];

         u8LocalMfadapdeltacountuavn =
            (uint8)(u8LocalMfadapdeltacountuavn1 - 1);
         s32LocalMfadapTDCcorrprecalMul =
            (sint32)( u8LocalMfadapdeltacountuavn
                    * s16LocalMfadapdeltacountuavn1);

         s32LocalMfadapTDCcorrprecalAdd =
                              (  ( ( s32LocalMfadapTDCcorrprecalMul
                                   + s32LocalMfadapTDCcorrprecalSomm)
                                 + (u8LocalMfadapdeltacountuavn1 / 2))
                              / u8LocalMfadapdeltacountuavn1);
         /* !Deviation: Violation of QAC_0585 rule.                       */
         /* !Reason : according to the global fuctionnality of the module,*/
         /* the case 0 of the denominator is urealisable as it's protected*/
         /* by the calling function MISFDFTLRN_vidCalcSumDeltaPrecal      */
         Mf_adap_TDC_delta_uavn1[u8LocalMisf_noCyl] =
            (sint16)MATHSRV_udtCLAMP(s32LocalMfadapTDCcorrprecalAdd,
                                     -32768,
                                     32767);
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
/* !Function    :  MISFDFTLRN_vidCalcDeltaBdc                                 */
/* !Description :  Ce bloc permet de calculer l' Offset moyen entre l'erreur  */
/*                 filtrée et la précalibration (fenêtre BDC).                */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Mf_adap_n_bkpt_uacn1[9];                                      */
/*  input uint16 Mf_adap_Bdc_corr_precal_uacn2[4][9];                         */
/*  input sint16 Mf_adap_Bdc_err_filt_uavn1[4];                               */
/*  input sint16 Mf_adap_Bdc_corr_precal_uavn0;                               */
/*  input uint8 Mf_adap_delta_count_uavn1[4];                                 */
/*  input sint16 Mf_adap_Bdc_delta_uavn1[4];                                  */
/*  output sint16 Mf_adap_Bdc_corr_precal_uavn0;                              */
/*  output sint16 Mf_adap_Bdc_delta_uavn1[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcDeltaBdc(void)
{
   /* 04_calc_delta_Bdc */
   uint8  u8LocalMfadapdeltacountuavn1;
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalMisf_noCyl;
   uint8  u8LocalMisf_noCylind;
   uint8  u8LocalMfadapdeltacountuavn;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalCalcInterp_2d;
   sint16 s16LocalMfadapBdcerrfiltuavn1;
   sint16 s16LocalMfadapdeltacountuavn1;
   sint32 s32LocalMfadapBdccorrprecalSomm;
   sint32 s32LocalMfadapBdccorrprecalMul;
   sint32 s32LocalMfadapBdccorrprecalAdd;


   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   u8LocalMisf_noCylind = (uint8)MATHSRV_udtMIN(u8LocalMisf_noCyl, 3);
   u16LocalCalcParaX = (uint16)(u8LocalMisf_noCylind * 256);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU8(Mf_adap_n_bkpt_uacn1,
                                                   u8LocalRegime_moteur_32,
                                                   9);
   u16LocalCalcInterp_2d =
      MATHSRV_u16Interp2d(&Mf_adap_Bdc_corr_precal_uacn2[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          9);
   Mf_adap_Bdc_corr_precal_uavn0 = (sint16)(u16LocalCalcInterp_2d - 32768);

   switch (u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         /* Mf_adap_BDC_err_filt_uavn1[Misf_noCyl] */
         /* + Mf_adap_Bdc_corr_precal_uavn0        */
         s16LocalMfadapBdcerrfiltuavn1 =
            Mf_adap_Bdc_err_filt_uavn1[u8LocalMisf_noCyl];
         s32LocalMfadapBdccorrprecalSomm = ( s16LocalMfadapBdcerrfiltuavn1
                                           + Mf_adap_Bdc_corr_precal_uavn0);
         /* calcul de Mf_adap_Bdc_delta_uavn1 */
         u8LocalMfadapdeltacountuavn1 =
            Mf_adap_delta_count_uavn1[u8LocalMisf_noCyl];
         s16LocalMfadapdeltacountuavn1 =
            Mf_adap_Bdc_delta_uavn1[u8LocalMisf_noCyl];

         u8LocalMfadapdeltacountuavn =
            (uint8)(u8LocalMfadapdeltacountuavn1 - 1);
         s32LocalMfadapBdccorrprecalMul =
            (sint32)( u8LocalMfadapdeltacountuavn
                    * s16LocalMfadapdeltacountuavn1);

         s32LocalMfadapBdccorrprecalAdd =
                              (  ( ( s32LocalMfadapBdccorrprecalMul
                                   + s32LocalMfadapBdccorrprecalSomm)
                                 + (u8LocalMfadapdeltacountuavn1 / 2))
                              / u8LocalMfadapdeltacountuavn1);
         /* !Deviation: Violation of QAC_0585 rule.                       */
         /* !Reason : according to the global fuctionnality of the module,*/
         /* the case 0 of the denominator is urealisable as it's protected*/
         /* by the calling function MISFDFTLRN_vidCalcSumDeltaPrecal      */

         Mf_adap_Bdc_delta_uavn1[u8LocalMisf_noCyl] =
            (sint16)MATHSRV_udtCLAMP(s32LocalMfadapBdccorrprecalAdd,
                                     -32768,
                                     32767);
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
/* !Function    :  MISFDFTLRN_vidWinAdap                                      */
/* !Description :  Ce module réalise la moyenne des erreurs sur la durée de la*/
/*                 fenêtre des cylindres 2 et 3 par rapport à la durée de la  */
/*                 fenêtre du cylindre 1 lorsque les conditions de stabilité  */
/*                 sont remplies et que le régime moteur est proche d’un point*/
/*                 d’appui.                                                   */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Mf_adap_lw_sample_count_uavn1[4];                             */
/*  input sint32 Mf_adap_lw_err_filt_uavn1[4];                                */
/*  input sint16 Mf_adap_lw_err_mv_i_uavn1[4];                                */
/*  input uint8 Mf_adap_shrt_sample_count_uavn1[4];                           */
/*  input sint16 Mf_adap_Exp_err_filt_uavn1[4];                               */
/*  input sint16 Mf_adap_TDC_err_filt_uavn1[4];                               */
/*  input sint16 Mf_adap_Bdc_err_filt_uavn1[4];                               */
/*  input sint16 Mf_adap_Exp_err_mv_i_uavn1[4];                               */
/*  input sint16 Mf_adap_TDC_err_mv_i_uavn1[4];                               */
/*  input sint16 Mf_adap_Bdc_err_mv_i_uavn1[4];                               */
/*  output uint8 Mf_adap_lw_sample_count_uavn1[4];                            */
/*  output sint16 Mf_adap_lw_err_mv_i_uavn1[4];                               */
/*  output uint8 Mf_adap_shrt_sample_count_uavn1[4];                          */
/*  output sint16 Mf_adap_Exp_err_mv_i_uavn1[4];                              */
/*  output sint16 Mf_adap_TDC_err_mv_i_uavn1[4];                              */
/*  output sint16 Mf_adap_Bdc_err_mv_i_uavn1[4];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidWinAdap(void)
{
   uint8  u8LocalNoCyl;
   uint8  u8LocalLwSampleCount;
   uint8  u8LocalShrtSampleCount;
   uint16 u16LocalLwSampleCount;
   uint16 u16LocalShrtSampleCount;
   sint32 s32LocalDif;
   sint32 s32LocalLwErrMvIuavb0;
   sint32 s32LocalExpErrMvIuavb0;
   sint32 s32LocalTdcErrMvIuavb0;
   sint32 s32LocalBdcErrMvIuavb0;
   sint32 s32LocalMfAdapLw;


   VEMS_vidGET(Misf_noCyl, u8LocalNoCyl);
   switch (u8LocalNoCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         /* Calculus of Mf_adap_lw_sample_count_uavn1*/
         u8LocalLwSampleCount = Mf_adap_lw_sample_count_uavn1[u8LocalNoCyl];
         u16LocalLwSampleCount = (uint16)(u8LocalLwSampleCount + 1);
         u8LocalLwSampleCount = (uint8)MATHSRV_udtMIN(u16LocalLwSampleCount,
                                                      255);
         Mf_adap_lw_sample_count_uavn1[u8LocalNoCyl] = u8LocalLwSampleCount;

         /* Fenêtre Longue */
         if (u8LocalLwSampleCount == 1)
         {
            Mf_adap_lw_err_mv_i_uavn1[u8LocalNoCyl] =
               (sint16)MATHSRV_udtCLAMP(Mf_adap_lw_err_filt_uavn1[u8LocalNoCyl],
                                        -32768,
                                        32767);
         }
         else
         {
            s32LocalMfAdapLw = (sint32)Mf_adap_lw_err_mv_i_uavn1[u8LocalNoCyl];

            s32LocalDif =
               MATHSRV_s32Sub_s32_s32(Mf_adap_lw_err_filt_uavn1[u8LocalNoCyl],
                                      s32LocalMfAdapLw);

            s32LocalLwErrMvIuavb0 = ( Mf_adap_lw_err_mv_i_uavn1[u8LocalNoCyl]
                                    + ( s32LocalDif / u8LocalLwSampleCount));

            Mf_adap_lw_err_mv_i_uavn1[u8LocalNoCyl] =
               (sint16)MATHSRV_udtCLAMP(s32LocalLwErrMvIuavb0, -32768, 32767);
         }

         /* Calculus of Mf_adap_shrt_sample_count_uavn1*/
         u8LocalShrtSampleCount = Mf_adap_shrt_sample_count_uavn1[u8LocalNoCyl];
         u16LocalShrtSampleCount = (uint16)(u8LocalShrtSampleCount + 1);
         u8LocalShrtSampleCount = (uint8)MATHSRV_udtMIN(u16LocalShrtSampleCount,
                                                        255);
         Mf_adap_shrt_sample_count_uavn1[u8LocalNoCyl] = u8LocalShrtSampleCount;

         if (u8LocalShrtSampleCount == 1)
         {
            /* Fenêtre courte détente*/
            Mf_adap_Exp_err_mv_i_uavn1[u8LocalNoCyl] =
               Mf_adap_Exp_err_filt_uavn1[u8LocalNoCyl];

            /* Fenêtre courte PMH */
            Mf_adap_TDC_err_mv_i_uavn1[u8LocalNoCyl] =
               Mf_adap_TDC_err_filt_uavn1[u8LocalNoCyl];

            /* Fenêtre courte PMB */
            Mf_adap_Bdc_err_mv_i_uavn1[u8LocalNoCyl] =
               Mf_adap_Bdc_err_filt_uavn1[u8LocalNoCyl];
         }
         else
         {
            /* Fenêtre courte détente*/
            s32LocalExpErrMvIuavb0 =
               ( Mf_adap_Exp_err_mv_i_uavn1[u8LocalNoCyl]
               + (sint32)( ( Mf_adap_Exp_err_filt_uavn1[u8LocalNoCyl]
                           - Mf_adap_Exp_err_mv_i_uavn1[u8LocalNoCyl])
                         / u8LocalShrtSampleCount));
            Mf_adap_Exp_err_mv_i_uavn1[u8LocalNoCyl] =
               (sint16)s32LocalExpErrMvIuavb0;

            /* Fenêtre courte PMH */
            s32LocalTdcErrMvIuavb0 =
               ( Mf_adap_TDC_err_mv_i_uavn1[u8LocalNoCyl]
               + (sint32)( ( Mf_adap_TDC_err_filt_uavn1[u8LocalNoCyl]
                           - Mf_adap_TDC_err_mv_i_uavn1[u8LocalNoCyl])
                         / u8LocalShrtSampleCount));
            Mf_adap_TDC_err_mv_i_uavn1[u8LocalNoCyl] =
               (sint16)s32LocalTdcErrMvIuavb0;

            /* Fenêtre courte PMB */
            s32LocalBdcErrMvIuavb0 =
               ( Mf_adap_Bdc_err_mv_i_uavn1[u8LocalNoCyl]
               + (sint32)( ( Mf_adap_Bdc_err_filt_uavn1[u8LocalNoCyl]
                           - Mf_adap_Bdc_err_mv_i_uavn1[u8LocalNoCyl])
                         / u8LocalShrtSampleCount));
            Mf_adap_Bdc_err_mv_i_uavn1[u8LocalNoCyl] =
               (sint16)s32LocalBdcErrMvIuavb0;
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
/* !Function    :  MISFDFTLRN_vidWinAdapSave                                  */
/* !Description :  Extraction du nombre d'apprentissage du point d'appui.     */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDFTLRN_vid1stLwAdapOnBkpt();                         */
/*  extf argret void MISFDFTLRN_vidNextLwAdapOnBkpt();                        */
/*  extf argret void MISFDFTLRN_vid1stShrtAdapOnBkpt();                       */
/*  extf argret void MISFDFTLRN_vidNextShrtAdapOnBkpt();                      */
/*  extf argret void MISFDFTLRN_vidAdapRlzdCalc();                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input uint8 Mf_adap_lw_corr_count_uavn1[9];                               */
/*  input uint8 Mf_adap_shrt_corr_count_uavn1[9];                             */
/*  input boolean Mf_adap_lw_no_rlzd_uavb0;                                   */
/*  input boolean MISFDFTLRN_blwnorlzduavb0Prev;                              */
/*  input boolean Mf_adap_lw_no_rlzd_UT_uavb0;                                */
/*  input boolean MISFDFTLRN_blwnorlzdUTuavb0Prev;                            */
/*  input boolean Mf_adap_shrt_no_rlzd_uavb0;                                 */
/*  input boolean MISFDFTLRN_bshrtnorlzduavb0Prev;                            */
/*  input boolean Mf_adap_shrt_no_rlzd_UT_uavb0;                              */
/*  input boolean MISFDFTLRN_bshrtnorlzdUTuavb0Prv;                           */
/*  output uint8 Mf_adap_lw_corr_nxt_cnt_i_uavn0;                             */
/*  output uint8 Mf_adap_shrt_corr_nxt_cnt_i;                                 */
/*  output boolean MISFDFTLRN_blwnorlzduavb0Prev;                             */
/*  output boolean MISFDFTLRN_blwnorlzdUTuavb0Prev;                           */
/*  output boolean MISFDFTLRN_bshrtnorlzduavb0Prev;                           */
/*  output boolean MISFDFTLRN_bshrtnorlzdUTuavb0Prv;                          */
/*  output boolean Mf_adap_no_rlzd_UT_uavb0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidWinAdapSave(void)
{

   boolean bLocalMf_lw_no_rlzd_UT_uavb0;
   boolean bLocalMf_shrt_no_rlzd_UT_uavb0;
   uint8   u8LocalLwCorrCountUavn1;
   uint8   u8LocalShrtCorrCountUavn1;
   uint8   u8LocalMfAdapBkptIndPrevUavn0;
   uint16  u16LocalLwCorrCountUavn1;
   uint16  u16LocalShrtCorrCountUavn1;
   sint16  s16LocalMfAdapBkptIndPrevUavn0;


   s16LocalMfAdapBkptIndPrevUavn0 = (sint16)(Mf_adap_bkpt_ind_prev_uavn0 - 1);
   u8LocalMfAdapBkptIndPrevUavn0 =
      (uint8)MATHSRV_udtCLAMP(s16LocalMfAdapBkptIndPrevUavn0, 0, 8);
   VEMS_vidGET1DArrayElement(Mf_adap_lw_corr_count_uavn1,
                             u8LocalMfAdapBkptIndPrevUavn0,
                             u8LocalLwCorrCountUavn1);
   u16LocalLwCorrCountUavn1 = (uint16)(u8LocalLwCorrCountUavn1 + 1);
   Mf_adap_lw_corr_nxt_cnt_i_uavn0 =
      (uint8)MATHSRV_udtMIN(u16LocalLwCorrCountUavn1, 255);

   VEMS_vidGET1DArrayElement(Mf_adap_shrt_corr_count_uavn1,
                             u8LocalMfAdapBkptIndPrevUavn0,
                             u8LocalShrtCorrCountUavn1);
   u16LocalShrtCorrCountUavn1 = (uint16)(u8LocalShrtCorrCountUavn1 + 1);
   Mf_adap_shrt_corr_nxt_cnt_i =
      (uint8)MATHSRV_udtMIN(u16LocalShrtCorrCountUavn1, 255);

   VEMS_vidGET(Mf_adap_lw_no_rlzd_uavb0, MISFDFTLRN_blwnorlzduavb0Prev);
   VEMS_vidGET(Mf_adap_lw_no_rlzd_UT_uavb0, MISFDFTLRN_blwnorlzdUTuavb0Prev);
   VEMS_vidGET(Mf_adap_shrt_no_rlzd_uavb0, MISFDFTLRN_bshrtnorlzduavb0Prev);
   VEMS_vidGET(Mf_adap_shrt_no_rlzd_UT_uavb0, MISFDFTLRN_bshrtnorlzdUTuavb0Prv);

   if (u8LocalLwCorrCountUavn1 == 0)
   {
      MISFDFTLRN_vid1stLwAdapOnBkpt();
   }
   else
   {
      MISFDFTLRN_vidNextLwAdapOnBkpt();
   }
   if (u8LocalShrtCorrCountUavn1 == 0)
   {
      MISFDFTLRN_vid1stShrtAdapOnBkpt();
   }
   else
   {
      MISFDFTLRN_vidNextShrtAdapOnBkpt();
   }

   MISFDFTLRN_vidAdapRlzdCalc();

   VEMS_vidGET(Mf_adap_lw_no_rlzd_UT_uavb0, bLocalMf_lw_no_rlzd_UT_uavb0);
   VEMS_vidGET(Mf_adap_shrt_no_rlzd_UT_uavb0, bLocalMf_shrt_no_rlzd_UT_uavb0);
   if (  (bLocalMf_lw_no_rlzd_UT_uavb0 != 0)
      && (bLocalMf_shrt_no_rlzd_UT_uavb0 != 0))
   {
      VEMS_vidSET(Mf_adap_no_rlzd_UT_uavb0, 1);
   }
   else
   {
      VEMS_vidSET(Mf_adap_no_rlzd_UT_uavb0, 0);
   }
}
/*-------------------------------- end of file -------------------------------*/
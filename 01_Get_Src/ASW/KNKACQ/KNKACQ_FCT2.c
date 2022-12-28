/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKACQ                                                  */
/* !Description     : KNKACQ component                                        */
/*                                                                            */
/* !Module          : KNKACQ                                                  */
/* !Description     : Knock signal acquisition parameter configuration        */
/*                                                                            */
/* !File            : KNKACQ_FCT2.C                                           */
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
/*   1 / KNKACQ_vidTConfigParameters                                          */
/*   2 / KNKACQ_vidTCalcParameters                                            */
/*   3 / KNKACQ_vidTObservationWindow                                         */
/*   4 / KNKACQ_vidTBandPassFilterParam                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5066621 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKACQ/KNKACQ_FCT$*/
/* $Revision::   1.4      $$Author::   etsasson       $$Date::   15 Feb 2013 $*/
/* $Author::   etsasson                               $$Date::   15 Feb 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "KNKACQ.h"
#include "KNKACQ_L.h"
#include "KNKACQ_IM.h"
#include "CRKHAL.h"
#include "KNWHAL.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQ_vidTConfigParameters                                */
/* !Description :  Le diagnostic du capteur cliquetis doit être réinitialisé  */
/*                 si il a été interrompu.                                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void KNKACQ_vidTCalcParameters();                             */
/*  output boolean Knk_sens_diag_act_uavb0;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQ_vidTConfigParameters(void)
{
   VEMS_vidSET(Knk_sens_diag_act_uavb0, 0);
   KNKACQ_vidTCalcParameters();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQ_vidTCalcParameters                                  */
/* !Description :  Focntion qui permet de calculer Knk_sen_dyn_filt_det_uavb1 */
/*                 et Regime_chgt_freq_cliq .                                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQ_vidTObservationWindow();                          */
/*  extf argret void KNKACQ_vidTBandPassFilterParam();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQ_vidTCalcParameters(void)
{
   KNKACQ_vidTObservationWindow();
   KNKACQ_vidTBandPassFilterParam();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQ_vidTObservationWindow                               */
/* !Description :  Foncton qui premet de calculer Debut_fenetre_cliquetis     */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint8 Eng_noCmbNxtCyl;                                              */
/*  input sint8 Av_bmax_corr_appliquee_cyl[4];                                */
/*  input uint8 IgSys_prm_agIgMaxWiPrevAdpCy[6];                              */
/*  input uint8 IgSys_agIgOptm;                                               */
/*  input boolean KnkAcq_bAvbmaxWinDec_ManuInh;                               */
/*  input uint8 IgSys_agIgKnkPrevOfs;                                         */
/*  input boolean KnkAcq_bAvDerWinDec_ManuInh;                                */
/*  input uint8 Cliq_av_corr_filt_gain;                                       */
/*  input uint32 KNKACQ_u32CliqAvCorAdptKFiltMem;                             */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Cliq_eal[17];                                                */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Cliq_n[20];                                                  */
/*  input uint8 Cliq_av_corr_bkpt_map[10];                                    */
/*  input uint8 Cliq_av_corr_prev_adpt_k;                                     */
/*  input uint8 Table_debut_fenetre_cliquetis[17][20];                        */
/*  input uint8 Table_dec_clq_num_av_corr[10][20];                            */
/*  input sint16 Vcpi_cam_position_error;                                     */
/*  input uint8 Cliq_intk_vvt_err_bkpt_map[10];                               */
/*  input uint8 Table_deb_clq_offset_transitoire[17][10];                     */
/*  input uint8 Offset_debut_fenetre_defaut_VVT;                              */
/*  input uint8 Debut_fenetre_limite;                                         */
/*  input uint8 Table_duree_fenetre_cliquetis[20];                            */
/*  output uint8 Cliq_av_corr_prev_adpt_k;                                    */
/*  output uint8 Debut_fenetre_cliquetis;                                     */
/*  output uint8 Duree_fenetre_cliquetis;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQ_vidTObservationWindow(void)
{
   /* 01T_Knk_Cfg_Observation_Window */
   boolean bLocalAcvDftModStrtKnkWin;
   sint8   s8LocalAvBmaxCorrAppCyl;
   sint8   s8LocalFilterInput1;
   uint8   u8LocalEng_noCmbNxtCyl;
   uint8   u8LocalDebfencliquetis;
   uint8   u8LocalIgSysAgIgKnkPrevOfs;
   uint8   u8LocalDecClqNumAvCor;
   uint8   u8LocalKnkWindow;
   uint8   u8LocalStartWnd;
   uint8   u8LocalStartKnkOffset;
   uint8   u8LocalFilterInput;
   uint8   u8LocalVcpi_cam_position_error;
   uint8   u8LocalIgSysAgIgMaxWiPrevAdpCyl;
   uint8   u8LocalIgSys_agIgOptm;
   uint8   u8LocalFilterInput2;
   uint8   u8LocalDuree_fenetre_cliquetis;
   sint16  s16LocalFilterInput;
   sint16  s16LocalStartWndLimit;
   sint16  s16LocalVcpi_cam_position_error;
   sint16  s16LocalFilterInput3;
   uint16  u16LocalParaCliqAvCor;
   uint16  u16LocalParaExtLd;
   uint16  u16LocalParaEngSpd;
   uint16  u16LocalExt_rAirLd;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalParaVcpiCamPosErr;
   sint32  s32LocalVcpiCamPosErr;


   /* Compute of Cliq_av_corr_prev_adpt_k */
   VEMS_vidGET(Eng_noCmbNxtCyl, u8LocalEng_noCmbNxtCyl);
   switch(u8LocalEng_noCmbNxtCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmbNxtCyl = (uint8)(u8LocalEng_noCmbNxtCyl - 1);
         VEMS_vidGET1DArrayElement(Av_bmax_corr_appliquee_cyl,
                                   u8LocalEng_noCmbNxtCyl,
                                   s8LocalAvBmaxCorrAppCyl);
         VEMS_vidGET1DArrayElement(IgSys_prm_agIgMaxWiPrevAdpCy,
                                   u8LocalEng_noCmbNxtCyl,
                                   u8LocalIgSysAgIgMaxWiPrevAdpCyl);
         break;

      case 5:
      case 6:
         s8LocalAvBmaxCorrAppCyl = 0;
         u8LocalEng_noCmbNxtCyl = (uint8)(u8LocalEng_noCmbNxtCyl - 1);
         VEMS_vidGET1DArrayElement(IgSys_prm_agIgMaxWiPrevAdpCy,
                                   u8LocalEng_noCmbNxtCyl,
                                   u8LocalIgSysAgIgMaxWiPrevAdpCyl);
         break;

      default :
         s8LocalAvBmaxCorrAppCyl = 0;
         u8LocalIgSysAgIgMaxWiPrevAdpCyl = 96;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   VEMS_vidGET(IgSys_agIgOptm, u8LocalIgSys_agIgOptm);
   if (u8LocalIgSysAgIgMaxWiPrevAdpCyl > u8LocalIgSys_agIgOptm)
   {
      Cliq_av_corr_prev_adpt_k = 96;
   }
   else
   {
      if (KnkAcq_bAvbmaxWinDec_ManuInh != 0)
      {
         s8LocalFilterInput1 = 0;
      }
      else
      {
         s8LocalFilterInput1 = s8LocalAvBmaxCorrAppCyl;
      }
      VEMS_vidGET(IgSys_agIgKnkPrevOfs, u8LocalIgSysAgIgKnkPrevOfs);
      if (KnkAcq_bAvDerWinDec_ManuInh != 0)
      {
         u8LocalFilterInput2 = 96;
      }
      else
      {
         u8LocalFilterInput2 = u8LocalIgSysAgIgKnkPrevOfs;
      }
      /* résol: 0.375  | offset = 0 °Vil */
      s16LocalFilterInput3 = (sint16)( ( ( u8LocalIgSysAgIgMaxWiPrevAdpCyl
                                         + s8LocalAvBmaxCorrAppCyl)
                                       - ( u8LocalIgSysAgIgKnkPrevOfs
                                         + u8LocalIgSys_agIgOptm))
                                     + 96);
      s16LocalFilterInput3 = (sint16)MATHSRV_udtMAX(s16LocalFilterInput3, 0);

      s16LocalFilterInput = (sint16)( ( s8LocalFilterInput1
                                      - ( u8LocalFilterInput2
                                        + s16LocalFilterInput3))
                                    + 192);
      u8LocalFilterInput = (uint8)MATHSRV_udtCLAMP(s16LocalFilterInput, 0, 255);
      Cliq_av_corr_prev_adpt_k =
         (uint8)MATHSRV_u16FirstOrderFilterGu8(Cliq_av_corr_filt_gain,
                                               &KNKACQ_u32CliqAvCorAdptKFiltMem,
                                               (uint16)u8LocalFilterInput);
   }
   /* Compute of the site para */
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
   u16LocalParaExtLd = MATHSRV_u16CalcParaIncAryU16(Cliq_eal,
                                                    u16LocalExt_rAirLd,
                                                    17);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalParaEngSpd = MATHSRV_u16CalcParaIncAryU16(Cliq_n,
                                                     u16LocalRegime_moteur,
                                                     20);
   u16LocalParaCliqAvCor =
      MATHSRV_u16CalcParaIncAryU8(Cliq_av_corr_bkpt_map,
                                  Cliq_av_corr_prev_adpt_k,
                                  10);

   /* Compute of Debut_fenetre_cliquetis & Duree_fenetre_cliquetis */
   u8LocalStartWnd = MATHSRV_u8Interp2d(&Table_debut_fenetre_cliquetis[0][0],
                                        u16LocalParaExtLd,
                                        u16LocalParaEngSpd,
                                        20);
   u8LocalDecClqNumAvCor = MATHSRV_u8Interp2d(&Table_dec_clq_num_av_corr[0][0],
                                              u16LocalParaCliqAvCor,
                                              u16LocalParaEngSpd,
                                              20);

   bLocalAcvDftModStrtKnkWin = GDGAR_bGetFRM(FRM_FRM_ACVDFTMODSTRTKNKWIN);
   if (bLocalAcvDftModStrtKnkWin == 0)
   {
      VEMS_vidGET(Vcpi_cam_position_error, s16LocalVcpi_cam_position_error);
      s32LocalVcpiCamPosErr = (sint32)( (s16LocalVcpi_cam_position_error * 3)
                                      + 1600);
      s16LocalVcpi_cam_position_error = (sint16)(s32LocalVcpiCamPosErr / 24);
      u8LocalVcpi_cam_position_error =
         (uint8)MATHSRV_udtCLAMP(s16LocalVcpi_cam_position_error, 0, 255);
      u16LocalParaVcpiCamPosErr =
         MATHSRV_u16CalcParaIncAryU8(Cliq_intk_vvt_err_bkpt_map,
                                     u8LocalVcpi_cam_position_error,
                                     10);
      u8LocalStartKnkOffset =
         MATHSRV_u8Interp2d(&Table_deb_clq_offset_transitoire[0][0],
                            u16LocalParaExtLd,
                            u16LocalParaVcpiCamPosErr,
                            10);
   }
   else
   {
      u8LocalStartKnkOffset = Offset_debut_fenetre_defaut_VVT;
   }

   s16LocalStartWndLimit = (sint16) ( ( (4 * u8LocalStartKnkOffset)
                                      + (4 * u8LocalStartWnd))
                                    + ( (3 * u8LocalDecClqNumAvCor)
                                       - 688));
   s16LocalStartWndLimit = (sint16)(s16LocalStartWndLimit / 4);
   u8LocalKnkWindow = (uint8)MATHSRV_udtCLAMP(s16LocalStartWndLimit, 0, 255);

   u8LocalDebfencliquetis = (uint8)MATHSRV_udtMAX(u8LocalKnkWindow,
                                                   Debut_fenetre_limite);
   VEMS_vidSET(Debut_fenetre_cliquetis, u8LocalDebfencliquetis);

   u8LocalDuree_fenetre_cliquetis =
      MATHSRV_u8Interp1d(Table_duree_fenetre_cliquetis,
                         u16LocalParaEngSpd);
   VEMS_vidSET(Duree_fenetre_cliquetis, u8LocalDuree_fenetre_cliquetis);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKACQ_vidTBandPassFilterParam                             */
/* !Description :  Fonction qui calcule la Frequence_centrale_passe_bande.    */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Regime_chgt_freq_cliq;                                       */
/*  input uint8 KnkAcq_EngSpdThd_C;                                           */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Charge_chgt_freq_cliq;                                       */
/*  input uint8 KnkAcq_rAirLdThd_C;                                           */
/*  input uint16 Cliq_eal[17];                                                */
/*  input uint16 Cliq_n[20];                                                  */
/*  input uint8 Eng_noCmbNxtCyl;                                              */
/*  input uint8 Frequence_centrale_passe_bande;                               */
/*  input uint8 Table_freq_centrale_clq_cyl1[17][20];                         */
/*  input uint8 Table_freq_centrale_cyl1_sdl;                                 */
/*  input uint8 Table_freq_centrale_clq_cyl2[17][20];                         */
/*  input uint8 Table_freq_centrale_cyl2_sdl;                                 */
/*  input uint8 Table_freq_centrale_clq_cyl3[17][20];                         */
/*  input uint8 Table_freq_centrale_cyl3_sdl;                                 */
/*  input uint8 Table_freq_centrale_clq_cyl4[17][20];                         */
/*  input uint8 Table_freq_centrale_cyl4_sdl;                                 */
/*  output uint16 Regime_chgt_freq_cliq;                                      */
/*  output uint16 Charge_chgt_freq_cliq;                                      */
/*  output uint8 Table_freq_centrale_cyl1_sdl;                                */
/*  output uint8 Table_freq_centrale_cyl2_sdl;                                */
/*  output uint8 Table_freq_centrale_cyl3_sdl;                                */
/*  output uint8 Table_freq_centrale_cyl4_sdl;                                */
/*  output uint8 Frequence_centrale_passe_bande;                              */
/*  output boolean Knk_sen_dyn_filt_det_uavb1[4];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKACQ_vidTBandPassFilterParam(void)
{
   /* 02T_Knk_Cfg_Band_Pass_Filter_Parameters */
   boolean bLocalKnk_sen_dyn_filt_det_uavb1[KNKACQ_u32ARRAY_LENGTH];
   uint8   u8LocalIndex;
   uint8   u8LocalEng_noCmbNxtCyl;
   uint8   u8LocalFreqcentpassbande;
   uint16  u16LocalEngSpdChangeKnkFreq;
   uint16  u16LocalParaEngSpd;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalExt_rAirLd;
   uint16  u16LocalParaExtLd;
   uint16  u16LocalChrChangeKnkFreq;
   uint16  u16LocalrAirLdThd_C;
   uint16  u16LocalEngSpdThd;
   uint16  u16LocalSiteX;
   uint16  u16LocalIndexX;
   uint16  u16LocalSiteY;
   uint16  u16LocalIndexY;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalEngSpdChangeKnkFreq =
      (uint16)MATHSRV_udtABS( (sint32)(u16LocalRegime_moteur
                            - Regime_chgt_freq_cliq));
   u16LocalEngSpdThd = (uint16)(KnkAcq_EngSpdThd_C * 2);
   if (u16LocalEngSpdChangeKnkFreq > u16LocalEngSpdThd)
   {
      Regime_chgt_freq_cliq = u16LocalRegime_moteur;
   }

   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
   u16LocalChrChangeKnkFreq =
      (uint16)MATHSRV_udtABS((sint32)( u16LocalExt_rAirLd
                                     - Charge_chgt_freq_cliq));
   u16LocalrAirLdThd_C = (uint16)((uint32)(KnkAcq_rAirLdThd_C * 8192) / 75);
   if (u16LocalChrChangeKnkFreq > u16LocalrAirLdThd_C)
   {
      Charge_chgt_freq_cliq = u16LocalExt_rAirLd;
   }

   u16LocalParaExtLd = MATHSRV_u16CalcParaIncAryU16(Cliq_eal,
                                                    Charge_chgt_freq_cliq,
                                                    17);
   u16LocalParaEngSpd = MATHSRV_u16CalcParaIncAryU16(Cliq_n,
                                                     Regime_chgt_freq_cliq,
                                                     20);
   u16LocalIndexX = (uint16)(u16LocalParaExtLd >> 8);
   u16LocalIndexX = (uint16)(u16LocalIndexX & 0xFF);
   u16LocalSiteX = (uint16)(u16LocalParaExtLd & 0xFF);
   if (u16LocalSiteX >= 0x80)
   {
      u16LocalIndexX = (uint16)(u16LocalIndexX + 1);
   }

   u16LocalIndexY = (uint16)(u16LocalParaEngSpd >> 8);
   u16LocalIndexY = (uint16)(u16LocalIndexY & 0xFF);
   u16LocalSiteY = (uint16)(u16LocalParaEngSpd & 0xFF);
   if (u16LocalSiteY >= 0x80)
   {
      u16LocalIndexY = (uint16)(u16LocalIndexY + 1);
   }

   VEMS_vidGET(Eng_noCmbNxtCyl, u8LocalEng_noCmbNxtCyl);
   VEMS_vidGET(Frequence_centrale_passe_bande, u8LocalFreqcentpassbande);
   switch (u8LocalEng_noCmbNxtCyl)
   {
      case 1:
         Table_freq_centrale_cyl1_sdl =
            Table_freq_centrale_clq_cyl1[u16LocalIndexX][u16LocalIndexY];

         u8LocalFreqcentpassbande = Table_freq_centrale_cyl1_sdl;
         break;

      case 2:
         Table_freq_centrale_cyl2_sdl =
            Table_freq_centrale_clq_cyl2[u16LocalIndexX][u16LocalIndexY];

         u8LocalFreqcentpassbande = Table_freq_centrale_cyl2_sdl;
         break;

      case 3:
         Table_freq_centrale_cyl3_sdl =
            Table_freq_centrale_clq_cyl3[u16LocalIndexX][u16LocalIndexY];

         u8LocalFreqcentpassbande = Table_freq_centrale_cyl3_sdl;
         break;

      case 4:
         Table_freq_centrale_cyl4_sdl =
            Table_freq_centrale_clq_cyl4[u16LocalIndexX][u16LocalIndexY];

         u8LocalFreqcentpassbande = Table_freq_centrale_cyl4_sdl;
         break;
      case 5:
      case 6:
         break;

     default :
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   VEMS_vidSET(Frequence_centrale_passe_bande, u8LocalFreqcentpassbande);

   for (u8LocalIndex = 0; u8LocalIndex < KNKACQ_u32ARRAY_LENGTH; u8LocalIndex++)
   {
      bLocalKnk_sen_dyn_filt_det_uavb1[u8LocalIndex] = 1;
   }
   VEMS_vidSET1DArray(Knk_sen_dyn_filt_det_uavb1,
                      KNKACQ_u32ARRAY_LENGTH,
                      bLocalKnk_sen_dyn_filt_det_uavb1);
}

/*------------------------------- end of file --------------------------------*/
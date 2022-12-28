/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKADPCOR                                               */
/* !Description     : KNKADPCOR component.                                    */
/*                                                                            */
/* !Module          : KNKADPCOR                                               */
/* !Description     : CORRECTION AUTO-ADAPTATIVE DU CLIQUETIS.                */
/*                                                                            */
/* !File            : KNKADPCOR_FCT2.C                                        */
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
/*   1 / KNKADPCOR_vidFuelDetection                                           */
/*   2 / KNKADPCOR_vidInitRFuelDetection                                      */
/*   3 / KNKADPCOR_vidAdaptativeCompute                                       */
/*   4 / KNKADPCOR_vidAdapComputeStrategy                                     */
/*   5 / KNKADPCOR_vidIncrementation                                          */
/*   6 / KNKADPCOR_vidDecrementation                                          */
/*   7 / KNKADPCOR_vidAdaptDec                                                */
/*   8 / KNKADPCOR_vidAdaptSlewRate                                           */
/*   9 / KNKADPCOR_vidAdaptativeReading                                       */
/*   10 / KNKADPCOR_vidZoneDetermination                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5154831 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKADPCOR/KNKADPCOR_FCT2.C_v$*/
/* $Revision::   1.15     $$Author::   wbouach        $$Date::   09 May 2012 $*/
/* $Author::   wbouach                                $$Date::   09 May 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "KNKADPCOR.h"
#include "KNKADPCOR_L.h"
#include "KNKADPCOR_IM.h"
#include "SWFAIL.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidFuelDetection                                 */
/* !Description :  Cette fonction permet l'appel de la fonction de remise à 0 */
/*                 des correctifs d'avance.                                   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKADPCOR_vidInitRFuelDetection();                       */
/*  input boolean RFuDet_bRstAdp;                                             */
/*  input boolean KNKADPCOR_bRFuDetRstAdpPrev;                                */
/*  output boolean KNKADPCOR_bRFuDetRstAdpPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidFuelDetection(void)
{
   /* 3bis_detection_plein */
   boolean bLocalRFuDet_bRstAdp;


   VEMS_vidGET(RFuDet_bRstAdp, bLocalRFuDet_bRstAdp);

   if (  (bLocalRFuDet_bRstAdp == 0)
      && (KNKADPCOR_bRFuDetRstAdpPrev != 0) )
   {
      KNKADPCOR_vidInitRFuelDetection();
   }
   KNKADPCOR_bRFuDetRstAdpPrev = bLocalRFuDet_bRstAdp;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidInitRFuelDetection                            */
/* !Description :  Lorsqu’un plein est détecté et que la carburant situé entre*/
/*                 le réservoir et les injecteur est consommé (RFuDet_bRstAdp */
/*                 passe de 1 à 0), les av_bmax doivent être remis à 0 comme  */
/*                 pour un reset logiciel.                                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input sint16 Av_bmax_adapt_anti_k_cyl1[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl2[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl3[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl4[15];                               */
/*  input uint8 Av_bmax_adapt_anti_k_cyl1_C[15];                              */
/*  input uint8 Av_bmax_adapt_anti_k_cyl2_C[15];                              */
/*  input uint8 Av_bmax_adapt_anti_k_cyl3_C[15];                              */
/*  input uint8 Av_bmax_adapt_anti_k_cyl4_C[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl1[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl2[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl3[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl4[15];                              */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl1[15];                          */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl2[15];                          */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl3[15];                          */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl4[15];                          */
/*  output sint8 Av_bmax_cor_adpt_anti_k_raw_cyl[4];                          */
/*  output sint16 Av_bmax_adapt_avant_moy_cyl[4];                             */
/*  output sint16 Av_bmax_adap_avt_slew_rate_cyl[4];                          */
/*  output sint8 Av_bmax_corr_appliquee_cyl[4];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidInitRFuelDetection(void)
{
   /* 0_init_RFuDet */
   uint8   u8LocalIndex;
   sint16  s16LocalAv_bmax_anti_k_cyl_1;
   sint16  s16LocalAv_bmax_anti_k_cyl_2;
   sint16  s16LocalAv_bmax_anti_k_cyl_3;
   sint16  s16LocalAv_bmax_anti_k_cyl_4;
   sint32  s32LocalCalc1;
   sint32  s32LocalCalc2;
   sint32  s32LocalCalc3;
   sint32  s32LocalCalc4;


   for (u8LocalIndex = 0; u8LocalIndex < 15; u8LocalIndex ++)
   {
      VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl1,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_1);
      VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl2,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_2);
      VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl3,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_3);
      VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl4,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_4);

      s32LocalCalc1 = (sint32)( s16LocalAv_bmax_anti_k_cyl_1
                              * Av_bmax_adapt_anti_k_cyl1_C[u8LocalIndex]);
      s32LocalCalc2 = (sint32)( s16LocalAv_bmax_anti_k_cyl_2
                              * Av_bmax_adapt_anti_k_cyl2_C[u8LocalIndex]);
      s32LocalCalc3 = (sint32)( s16LocalAv_bmax_anti_k_cyl_3
                              * Av_bmax_adapt_anti_k_cyl3_C[u8LocalIndex]);
      s32LocalCalc4 = (sint32)( s16LocalAv_bmax_anti_k_cyl_4
                              * Av_bmax_adapt_anti_k_cyl4_C[u8LocalIndex]);

      if (s32LocalCalc1 >= 0)
      {
         s32LocalCalc1 = (s32LocalCalc1 + 50) / 100;
      }
      else
      {
         s32LocalCalc1 = (s32LocalCalc1 - 50) / 100;
      }
      if (s32LocalCalc2 >= 0)
      {
         s32LocalCalc2 = (s32LocalCalc2 + 50) / 100;
      }
      else
      {
         s32LocalCalc2 = (s32LocalCalc2 - 50) / 100;
      }
      if (s32LocalCalc3 >= 0)
      {
         s32LocalCalc3 = (s32LocalCalc3 + 50) / 100;
      }
      else
      {
         s32LocalCalc3 = (s32LocalCalc3 - 50) / 100;
      }
      if (s32LocalCalc4 >= 0)
      {
         s32LocalCalc4 = (s32LocalCalc4 + 50) / 100;
      }
      else
      {
         s32LocalCalc4 = (s32LocalCalc4 - 50) / 100;
      }

      s16LocalAv_bmax_anti_k_cyl_1 = (sint16)MATHSRV_udtCLAMP(s32LocalCalc1,
                                                              -32768,
                                                              32767);
      s16LocalAv_bmax_anti_k_cyl_2 = (sint16)MATHSRV_udtCLAMP(s32LocalCalc2,
                                                              -32768,
                                                              32767);
      s16LocalAv_bmax_anti_k_cyl_3 = (sint16)MATHSRV_udtCLAMP(s32LocalCalc3,
                                                              -32768,
                                                              32767);
      s16LocalAv_bmax_anti_k_cyl_4 = (sint16)MATHSRV_udtCLAMP(s32LocalCalc4,
                                                              -32768,
                                                              32767);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl1,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_1);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl2,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_2);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl3,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_3);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl4,
                                u8LocalIndex,
                                s16LocalAv_bmax_anti_k_cyl_4);

      Av_bmax_corr_adapt_anti_k_cyl1[u8LocalIndex] = 0;
      Av_bmax_corr_adapt_anti_k_cyl2[u8LocalIndex] = 0;
      Av_bmax_corr_adapt_anti_k_cyl3[u8LocalIndex] = 0;
      Av_bmax_corr_adapt_anti_k_cyl4[u8LocalIndex] = 0;

      if (u8LocalIndex < 4)
      {
         Av_bmax_cor_adpt_anti_k_raw_cyl[u8LocalIndex] = 0;
         Av_bmax_adapt_avant_moy_cyl[u8LocalIndex] = 0;
         Av_bmax_adap_avt_slew_rate_cyl[u8LocalIndex] = 0;
         VEMS_vidSET1DArrayElement(Av_bmax_corr_appliquee_cyl, u8LocalIndex, 0);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidAdaptativeCompute                             */
/* !Description :  Ce bloc calcule la correction d'avance à appliquer par     */
/*                 rapport au bornage maximum pour le cylindre en cours.      */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void KNKADPCOR_vidAdapComputeStrategy();                      */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input uint8 Knk_adapt_zone_fct_cyl[4];                                    */
/*  input sint16 Av_bmax_adapt_anti_k_cyl1[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl2[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl3[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl4[15];                               */
/*  input boolean Av_bmax_autorise_adaptation;                                */
/*  input boolean Manu_inh_avance_adapt;                                      */
/*  output sint16 Av_bmax_adapt_anti_k_cyl_prev[4];                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidAdaptativeCompute(void)
{
   /* 4_calcul_adaptatif */
   boolean bLocalFRM_bInhAvAdp;
   uint8   u8LocalZoneFunc;
   uint8   u8LocalEng_noCmprNxtCyl;
   sint16  s16LocalAv_bmax_anti_k_cyl_1;
   sint16  s16LocalAv_bmax_anti_k_cyl_2;
   sint16  s16LocalAv_bmax_anti_k_cyl_3;
   sint16  s16LocalAv_bmax_anti_k_cyl_4;


   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalZoneFunc = Knk_adapt_zone_fct_cyl[u8LocalEng_noCmprNxtCyl - 1];
         if (u8LocalZoneFunc == 0)
         {
            Av_bmax_adapt_anti_k_cyl_prev[0] = 0;
            Av_bmax_adapt_anti_k_cyl_prev[1] = 0;
            Av_bmax_adapt_anti_k_cyl_prev[2] = 0;
            Av_bmax_adapt_anti_k_cyl_prev[3] = 0;
         }
         else
         {
            if (u8LocalZoneFunc < 16)
            {
               u8LocalZoneFunc = (uint8)(u8LocalZoneFunc - 1);
               VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl1,
                                         u8LocalZoneFunc,
                                         s16LocalAv_bmax_anti_k_cyl_1);
               VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl2,
                                         u8LocalZoneFunc,
                                         s16LocalAv_bmax_anti_k_cyl_2);
               VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl3,
                                         u8LocalZoneFunc,
                                         s16LocalAv_bmax_anti_k_cyl_3);
               VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl4,
                                         u8LocalZoneFunc,
                                         s16LocalAv_bmax_anti_k_cyl_4);
               Av_bmax_adapt_anti_k_cyl_prev[0] = s16LocalAv_bmax_anti_k_cyl_1;
               Av_bmax_adapt_anti_k_cyl_prev[1] = s16LocalAv_bmax_anti_k_cyl_2;
               Av_bmax_adapt_anti_k_cyl_prev[2] = s16LocalAv_bmax_anti_k_cyl_3;
               Av_bmax_adapt_anti_k_cyl_prev[3] = s16LocalAv_bmax_anti_k_cyl_4;
            }
         }
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   bLocalFRM_bInhAvAdp = GDGAR_bGetFRM(FRM_FRM_INHAVADP);
   if (  (Av_bmax_autorise_adaptation != 0)
      && (Manu_inh_avance_adapt == 0)
      && (bLocalFRM_bInhAvAdp == 0))
   {
      KNKADPCOR_vidAdapComputeStrategy();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidAdapComputeStrategy                           */
/* !Description :  L’adaptatif est incrémenté à chaque détection de cliquetis */
/*                 que ce soit par la stratégie de détection classique ou par */
/*                 la détection palliative. S’il n’y a pas de cliquetis, la   */
/*                 décrémentation n’est autorisée que si l’avance optimale est*/
/*                 sup à l’avance maxi.                                       */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void KNKADPCOR_vidIncrementation();                           */
/*  extf argret void KNKADPCOR_vidAdaptSlewRate();                            */
/*  extf argret void KNKADPCOR_vidDecrementation();                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input boolean Detection_cliquetis[4];                                     */
/*  input boolean Knk_deg_det_cur_uavb1[4];                                   */
/*  input sint16 Av_bmax_adapt_avant_moy_cyl[4];                              */
/*  input uint16 Av_bmax_retard_cptr_cyl[4];                                  */
/*  input uint8 IgSys_agIgOptm;                                               */
/*  input uint8 IgSys_prm_agIgMaxWiPrevAdpCy[6];                              */
/*  input uint8 Knk_adapt_dec_delta_min;                                      */
/*  output sint16 Av_bmax_adapt_avant_moy_cyl_prev[4];                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidAdapComputeStrategy(void)
{
   /* 1_calc_adaptation */
   boolean bLocalDetection_cliquetis;
   boolean bLocalKnk_deg_det_cur_uavb1;
   uint8   u8LocalEng_noCmprNxtCyl;
   uint8   u8LocalNoCyl;
   uint8   u8LocalPrm_agIgMaxWiPrevAdpCy;
   uint8   u8LocalIgSys_agIgOptm;
   uint8   u8LocalIndex;
   sint16  s16LocalDiff;


   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalNoCyl = (uint8)(u8LocalEng_noCmprNxtCyl - 1);
         VEMS_vidGET1DArrayElement(Detection_cliquetis,
                                   u8LocalNoCyl,
                                   bLocalDetection_cliquetis);
         VEMS_vidGET1DArrayElement(Knk_deg_det_cur_uavb1,
                                   u8LocalNoCyl,
                                   bLocalKnk_deg_det_cur_uavb1);

         for (u8LocalIndex = 0 ; u8LocalIndex < 4 ; u8LocalIndex++)
         {
            Av_bmax_adapt_avant_moy_cyl_prev[u8LocalIndex] =
               Av_bmax_adapt_avant_moy_cyl[u8LocalIndex];
         }
         if (  (bLocalDetection_cliquetis != 0)
            || (bLocalKnk_deg_det_cur_uavb1 != 0) )
         {
            /* 0_incrementation */
            KNKADPCOR_vidIncrementation();
            if (Av_bmax_retard_cptr_cyl[u8LocalNoCyl] > 0)
            {
               /* 2_slew_rate_sur_adapt */
               KNKADPCOR_vidAdaptSlewRate();
            }
         }
         else
         {
            VEMS_vidGET(IgSys_agIgOptm, u8LocalIgSys_agIgOptm);
            VEMS_vidGET1DArrayElement(IgSys_prm_agIgMaxWiPrevAdpCy,
                                      u8LocalNoCyl,
                                      u8LocalPrm_agIgMaxWiPrevAdpCy);

            s16LocalDiff = (sint16)( ( u8LocalIgSys_agIgOptm
                                     - u8LocalPrm_agIgMaxWiPrevAdpCy)
                                   * 4);
            if (s16LocalDiff >= (sint16)Knk_adapt_dec_delta_min)
            {
               /* 1_decrementation */
               KNKADPCOR_vidDecrementation();
            }
         }

         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidIncrementation                                */
/* !Description :  L’adaptatif est incrémenté à chaque détection de cliquetis */
/*                 que ce soit par la stratégie de détection classique        */
/*                 (Detection_cliquetis =1) ou par la détection palliative    */
/*                 (Knk_deg_det_cur_uavb1 = 1).                               */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input uint16 Knk_engine_air_load_cyl[4];                                  */
/*  input uint16 Knk_regime_moteur_cyl[4];                                    */
/*  input uint16 Engine_load_5_bkpt_map[4];                                   */
/*  input uint16 Knk_engine_air_load;                                         */
/*  input uint16 Knk_regime_moteur;                                           */
/*  input uint8 Regime_moteur_6_bkpt_map[6];                                  */
/*  input uint8 Knk_adapt_filt_gain_map[4][6];                                */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Av_bmax_retard_delai_map[16];                                */
/*  input uint8 Correction_boucle_rapide[4];                                  */
/*  input uint8 Knk_adapt_inc_delta_min;                                      */
/*  input uint8 Knk_adapt_filt_gain;                                          */
/*  input sint16 Av_bmax_adapt_anti_k_cyl_prev[4];                            */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 IgLim_agIgMaxAdpThresh_M[4][6];                              */
/*  input uint16 IgLim_agIgMinAdpThresh_M[4][6];                              */
/*  output uint16 Knk_engine_air_load;                                        */
/*  output uint16 Knk_regime_moteur;                                          */
/*  output uint8 Knk_adapt_filt_gain;                                         */
/*  output uint16 Av_bmax_retard_cptr_cyl[4];                                 */
/*  output sint16 Av_bmax_adap_avt_slew_rate_cyl[4];                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidIncrementation(void)
{
   /* 0_incrementation */
   uint8  u8LocalCorrection_boucle_rapide;
   uint8  u8LocalIndex;
   uint8  u8LocalNoCyl;
   uint8  u8LocalEng_noCmprNxtCyl;
   uint8  u8LocalKnk_regime_moteur;
   uint8  u8LocalRegime_moteur;
   uint16 u16LocalKnk_regime_moteur;
   uint16 u16LocalCalcParaSpd;
   uint16 u16LocalCalcParaLoad;
   uint16 u16LocalExt_rAirLd;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalIgLim_agIgMaxAdpThresh;
   uint16 u16LocalIgLim_agIgMinAdpThresh;
   sint16 s16LocalPrev;
   sint16 s16LocalIgLim_agIgMaxAdpThresh;
   sint16 s16LocalIgLim_agIgMinAdpThresh;
   sint32 s32LocalAdvance;


   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalNoCyl = (uint8)(u8LocalEng_noCmprNxtCyl - 1);
         Knk_engine_air_load = Knk_engine_air_load_cyl[u8LocalNoCyl];
         u16LocalKnk_regime_moteur = Knk_regime_moteur_cyl[u8LocalNoCyl];
         Knk_regime_moteur = (uint16)MATHSRV_udtMIN(u16LocalKnk_regime_moteur,
                                                    8191);
         u16LocalCalcParaLoad =
            MATHSRV_u16CalcParaIncAryU16(Engine_load_5_bkpt_map,
                                         Knk_engine_air_load,
                                         4);
         u8LocalKnk_regime_moteur = (uint8)(Knk_regime_moteur / 32);
         u16LocalCalcParaSpd =
            MATHSRV_u16CalcParaIncAryU8(Regime_moteur_6_bkpt_map,
                                        u8LocalKnk_regime_moteur,
                                        6);
         Knk_adapt_filt_gain =
            MATHSRV_u8Interp2d(&Knk_adapt_filt_gain_map[0][0],
                               u16LocalCalcParaLoad,
                               u16LocalCalcParaSpd,
                               6);
         u16LocalKnk_regime_moteur = (uint16)(Knk_regime_moteur * 8);
         u16LocalCalcParaSpd =
            MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                         u16LocalKnk_regime_moteur,
                                         16);

         Av_bmax_retard_cptr_cyl[u8LocalNoCyl] =
            MATHSRV_u16Interp1d(Av_bmax_retard_delai_map, u16LocalCalcParaSpd);

         VEMS_vidGET1DArrayElement(Correction_boucle_rapide,
                                   u8LocalNoCyl,
                                   u8LocalCorrection_boucle_rapide);

         s32LocalAdvance = (sint32)MATHSRV_udtMAX((
                                 (u8LocalCorrection_boucle_rapide * 4)
                                   - Knk_adapt_inc_delta_min), 0);
         s32LocalAdvance = (s32LocalAdvance * Knk_adapt_filt_gain) / 2;
         s32LocalAdvance = s32LocalAdvance
                         + Av_bmax_adapt_anti_k_cyl_prev[u8LocalNoCyl];

         VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
         VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
         u16LocalCalcParaLoad =
            MATHSRV_u16CalcParaIncAryU16(Engine_load_5_bkpt_map,
                                         u16LocalExt_rAirLd,
                                         4);
         u16LocalRegime_moteur = (uint16)(u16LocalRegime_moteur / 32);
         u8LocalRegime_moteur =
            (uint8)MATHSRV_udtMIN(u16LocalRegime_moteur, 255);
         u16LocalCalcParaSpd =
            MATHSRV_u16CalcParaIncAryU8(Regime_moteur_6_bkpt_map,
                                        u8LocalRegime_moteur,
                                        6);
         u16LocalIgLim_agIgMaxAdpThresh =
            MATHSRV_u16Interp2d(&IgLim_agIgMaxAdpThresh_M[0][0],
                               u16LocalCalcParaLoad,
                               u16LocalCalcParaSpd,
                               6);
         u16LocalIgLim_agIgMinAdpThresh =
            MATHSRV_u16Interp2d(&IgLim_agIgMinAdpThresh_M[0][0],
                               u16LocalCalcParaLoad,
                               u16LocalCalcParaSpd,
                               6);
         s16LocalIgLim_agIgMaxAdpThresh =
            (sint16)(u16LocalIgLim_agIgMaxAdpThresh - 32768);
         s16LocalIgLim_agIgMinAdpThresh =
            (sint16)(u16LocalIgLim_agIgMinAdpThresh - 32768);
         for (u8LocalIndex = 0 ; u8LocalIndex < 4 ; u8LocalIndex++)
         {
            if (u8LocalIndex != u8LocalNoCyl)
            {
               s16LocalPrev = Av_bmax_adapt_anti_k_cyl_prev[u8LocalIndex];
               Av_bmax_adap_avt_slew_rate_cyl[u8LocalIndex] =
                  (sint16)MATHSRV_udtCLAMP(s16LocalPrev,
                                           s16LocalIgLim_agIgMinAdpThresh,
                                           s16LocalIgLim_agIgMaxAdpThresh);
            }
            else
            {
               Av_bmax_adap_avt_slew_rate_cyl[u8LocalIndex] =
                  (sint16)MATHSRV_udtCLAMP(s32LocalAdvance,
                                           s16LocalIgLim_agIgMinAdpThresh,
                                           s16LocalIgLim_agIgMaxAdpThresh);
            }
         }
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidDecrementation                                */
/* !Description :  S’il n’y a pas de cliquetis, la décrémentation n’est       */
/*                 autorisée que si l’avance optimale est supérieure à        */
/*                 l’avance maxi d’au moins Knk_adapt_dec_delta_min.          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKADPCOR_vidAdaptDec();                                 */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input uint16 Av_bmax_retard_cptr_cyl[4];                                  */
/*  input uint16 Knk_regime_moteur_cyl[4];                                    */
/*  input uint16 Knk_regime_moteur;                                           */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Av_bmax_decrem_delai_map[16];                                */
/*  input uint16 Av_bmax_decrem_cptr_cyl[4];                                  */
/*  output uint16 Knk_regime_moteur;                                          */
/*  output uint16 Av_bmax_retard_cptr_cyl[4];                                 */
/*  output uint16 Av_bmax_decrem_cptr_cyl[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidDecrementation(void)
{
   /* 1_decrementation */
   uint8  u8LocalEng_noCmprNxtCyl;
   uint8  u8LocalNoCyl;
   uint16 u16LocalCalcPara;
   uint16 u16LocalAv_bmax_retard_cptr_cyl;
   uint16 u16LocalAv_bmax_decrem_cptr_cyl;
   uint16 u16LocalKnk_regime_moteur;
   uint16 u16LocalAv_bmax_decrem_delai_map;


   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalNoCyl = (uint8)(u8LocalEng_noCmprNxtCyl - 1);
         if (Av_bmax_retard_cptr_cyl[u8LocalNoCyl] > 1)
         {
            u16LocalAv_bmax_retard_cptr_cyl =
               (uint16)(Av_bmax_retard_cptr_cyl[u8LocalNoCyl] - 1);
         }
         else
         {
            u16LocalAv_bmax_retard_cptr_cyl = 0;
         }

         u16LocalKnk_regime_moteur = Knk_regime_moteur_cyl[u8LocalNoCyl];
         Knk_regime_moteur = (uint16)MATHSRV_udtMIN(u16LocalKnk_regime_moteur,
                                                    8191);
         u16LocalKnk_regime_moteur = (uint16)(Knk_regime_moteur * 8);
         u16LocalCalcPara =
            MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                         u16LocalKnk_regime_moteur,
                                         16);
         u16LocalAv_bmax_decrem_delai_map =
            MATHSRV_u16Interp1d(Av_bmax_decrem_delai_map, u16LocalCalcPara);

         Av_bmax_retard_cptr_cyl[u8LocalNoCyl] =
            u16LocalAv_bmax_retard_cptr_cyl;
         if (u16LocalAv_bmax_retard_cptr_cyl == 0)
         {
            if (Av_bmax_decrem_cptr_cyl[u8LocalNoCyl] > 1)
            {
               u16LocalAv_bmax_decrem_cptr_cyl =
                  (uint16)( Av_bmax_decrem_cptr_cyl[u8LocalNoCyl]
                          - 1);
            }
            else
            {
               u16LocalAv_bmax_decrem_cptr_cyl = 0;
            }
         }
         else
         {
               u16LocalAv_bmax_decrem_cptr_cyl =
                  u16LocalAv_bmax_decrem_delai_map;
         }

         if ( ( u16LocalAv_bmax_decrem_cptr_cyl == 0)
            &&( Av_bmax_decrem_cptr_cyl[u8LocalNoCyl] != 0) )
         {
            /* 0_dec_adpt */
            KNKADPCOR_vidAdaptDec();
            Av_bmax_decrem_cptr_cyl[u8LocalNoCyl] =
               u16LocalAv_bmax_decrem_delai_map;
         }
         else
         {
            Av_bmax_decrem_cptr_cyl[u8LocalNoCyl] =
               u16LocalAv_bmax_decrem_cptr_cyl;
         }
         break;

      case 5:
      case 6:
         break;

      default :
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidAdaptDec                                      */
/* !Description :  La borne minimale des adaptatifs est différente de zéro par*/
/*                 rapport à la stratégie précédente; Les adaptatifs peuvent  */
/*                 prendre des valeurs négatives afin de faire un             */
/*                 apprentissage de carburant ayant un indice d’octane        */
/*                 supérieur à celui des avances de base.                     */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input sint16 Av_bmax_adapt_anti_k_cyl_prev[4];                            */
/*  input uint16 Knk_regime_moteur_cyl[4];                                    */
/*  input uint16 Knk_regime_moteur;                                           */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Av_bmax_pas_dec_adapt_map[16];                               */
/*  input sint16 Av_bmax_adapt_anti_k_min;                                    */
/*  output sint16 Av_bmax_adapt_avant_moy_cyl[4];                             */
/*  output uint16 Knk_regime_moteur;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidAdaptDec(void)
{
   /* 0_dec_adpt */
   uint8  u8LocalEng_noCmprNxtCyl;
   uint8  u8LocalNoCyl;
   uint8  u8LocalIndex;
   uint16 u16LocalCalcPara;
   uint16 u16LocalStepAdv;
   uint16 u16LocalEngSpd;
   sint32 s32LocalAdvanceMin;
   sint32 s32LocalAdvance;


   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalNoCyl = (uint8)(u8LocalEng_noCmprNxtCyl - 1);
         for (u8LocalIndex = 0 ; u8LocalIndex < 4 ; u8LocalIndex++)
         {
            if (u8LocalIndex != u8LocalNoCyl)
            {
               Av_bmax_adapt_avant_moy_cyl[u8LocalIndex] =
                  Av_bmax_adapt_anti_k_cyl_prev[u8LocalIndex];
            }
            else
            {
               u16LocalEngSpd = Knk_regime_moteur_cyl[u8LocalNoCyl];
               Knk_regime_moteur = (uint16)MATHSRV_udtMIN(u16LocalEngSpd, 8191);
               u16LocalEngSpd = (uint16)(Knk_regime_moteur * 8);
               u16LocalCalcPara =
                  MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                               u16LocalEngSpd,
                                               16);
               u16LocalStepAdv = MATHSRV_u16Interp1d(Av_bmax_pas_dec_adapt_map,
                                                     u16LocalCalcPara);
               s32LocalAdvance =
                  ( ( (sint32)(2 * Av_bmax_adapt_anti_k_cyl_prev[u8LocalNoCyl])
                    - (sint32)u16LocalStepAdv)
                  / 2);
               s32LocalAdvanceMin = (sint32)(Av_bmax_adapt_anti_k_min * 128);
               s32LocalAdvance = MATHSRV_udtMAX(s32LocalAdvanceMin,
                                                s32LocalAdvance);
               Av_bmax_adapt_avant_moy_cyl[u8LocalIndex] =
                  (sint16)MATHSRV_udtCLAMP(s32LocalAdvance,
                                           -32768,
                                           32767);
            }
         }
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidAdaptSlewRate                                 */
/* !Description :  Lorsqu'une incrémentation est appliquée, elle est soumise à*/
/*                 un slew rate afin d'éviter les à-coups dans le ressenti. Le*/
/*                 slew rate est cartographié en fonction du régime (table    */
/*                 Av_bmax_max_slew_rate_map).                                */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input uint16 Knk_regime_moteur_cyl[4];                                    */
/*  input uint16 Knk_regime_moteur;                                           */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Av_bmax_max_slew_rate_map[16];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl_prev[4];                            */
/*  input sint16 Av_bmax_adap_avt_slew_rate_cyl[4];                           */
/*  output uint16 Knk_regime_moteur;                                          */
/*  output sint16 Av_bmax_adapt_avant_moy_cyl[4];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidAdaptSlewRate(void)
{
   /* 2_slew_rate_sur_adapt */
   uint8  u8LocalEng_noCmprNxtCyl;
   uint8  u8LocalNoCyl;
   uint16 u16LocalCalcPara;
   uint16 u16LocalSlewRateAdv;
   uint16 u16LocalEngSpd;
   sint32 s32LocalAdvance;


   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalNoCyl = (uint8)(u8LocalEng_noCmprNxtCyl - 1);
         u16LocalEngSpd = Knk_regime_moteur_cyl[u8LocalNoCyl];
         Knk_regime_moteur = (uint16)MATHSRV_udtMIN(u16LocalEngSpd, 8191);
         u16LocalEngSpd = (uint16)(Knk_regime_moteur * 8);
         u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                         u16LocalEngSpd,
                                                         16);
         u16LocalSlewRateAdv = MATHSRV_u16Interp1d(Av_bmax_max_slew_rate_map,
                                                   u16LocalCalcPara);
         s32LocalAdvance =
            (sint32)( ( (2 * Av_bmax_adapt_anti_k_cyl_prev[u8LocalNoCyl])
                      + u16LocalSlewRateAdv)
                    / 2);
         Av_bmax_adapt_avant_moy_cyl[u8LocalNoCyl] =
            (sint16)MATHSRV_udtMIN(
               Av_bmax_adap_avt_slew_rate_cyl[u8LocalNoCyl],
               s32LocalAdvance);
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidAdaptativeReading                             */
/* !Description :  La zone de fonctionnement courante est déterminée          */
/*                 préalablement à la lecture des adaptatifs qui vont être    */
/*                 appliqués au prochain allumage. Elle est fixée à 0, si le  */
/*                 régime et la charge moteur sont en dehors des bornes min et*/
/*                 max des points d’appui.                                    */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKADPCOR_vidZoneDetermination();                        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input boolean Zone_critique;                                              */
/*  input uint8 Knk_adapt_zone_fct;                                           */
/*  input uint8 Knk_adapt_n_hysteresis_zone0;                                 */
/*  input uint16 Knk_adapt_n_min;                                             */
/*  input uint16 Knk_adapt_n_max;                                             */
/*  input uint16 Knk_adapt_load_min;                                          */
/*  input uint8 Knk_adapt_load_hysteresis_zone0;                              */
/*  input uint16 Knk_adapt_load_max;                                          */
/*  input boolean KNKADPCOR_boutputHysteresis1;                               */
/*  input boolean KNKADPCOR_boutputHysteresis2;                               */
/*  input boolean KNKADPCOR_boutputHysteresis3;                               */
/*  input boolean KNKADPCOR_boutputHysteresis4;                               */
/*  input uint8 Knk_adapt_zone_fct_cyl[4];                                    */
/*  input uint8 KNKADPCOR_u8KnkAdaptZoneCylPrev[4];                           */
/*  input sint16 Av_bmax_adapt_anti_k_cyl1[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl2[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl3[15];                               */
/*  input sint16 Av_bmax_adapt_anti_k_cyl4[15];                               */
/*  input boolean KNKADPCOR_bZone_critiquePrev;                               */
/*  input boolean Av_bmax_inh_reset_zone_crit;                                */
/*  input sint16 Av_bmax_adapt_anti_k_zone_cyl[4];                            */
/*  output uint8 KNKADPCOR_u8adapt_zone_fctPrev;                              */
/*  output boolean KNKADPCOR_boutputHysteresis1;                              */
/*  output boolean KNKADPCOR_boutputHysteresis2;                              */
/*  output boolean KNKADPCOR_boutputHysteresis3;                              */
/*  output boolean KNKADPCOR_boutputHysteresis4;                              */
/*  output uint8 Knk_adapt_zone_fct;                                          */
/*  output uint8 KNKADPCOR_u8KnkAdaptZoneCylPrev[4];                          */
/*  output uint8 Knk_adapt_zone_fct_cyl[4];                                   */
/*  output sint16 Av_bmax_adapt_anti_k_zone_cyl[4];                           */
/*  output boolean Av_bmax_conditions_raz_cptr;                               */
/*  output sint16 Av_bmax_adapt_anti_k_zone_cyl1;                             */
/*  output sint16 Av_bmax_adapt_anti_k_zone_cyl2;                             */
/*  output sint16 Av_bmax_adapt_anti_k_zone_cyl3;                             */
/*  output sint16 Av_bmax_adapt_anti_k_zone_cyl4;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidAdaptativeReading(void)
{
   /* 5_lecture_adaptatifs  */
   boolean bLocalZone_critique;
   boolean bLocalResultLogicalOR;
   boolean bLocalAvMaxChgtZone;
   uint8   u8LocalIndex;
   uint8   u8LocalIndex1;
   uint8   u8LocalIndex2;
   uint8   u8LocalIndex3;
   uint8   u8LocalIndex4;
   uint8   u8LocalEng_noCmprNxtCyl;
   uint16  u16LocalExt_rAirLd;
   uint16  u16LocalRegime_moteur;
   sint16  s16LocalAv_bmax_anti_k_cyl_1;
   sint16  s16LocalAv_bmax_anti_k_cyl_2;
   sint16  s16LocalAv_bmax_anti_k_cyl_3;
   sint16  s16LocalAv_bmax_anti_k_cyl_4;
   sint16  s16LocalIndex1;
   sint16  s16LocalIndex2;
   sint16  s16LocalIndex3;
   sint16  s16LocalIndex4;
   uint32  u32LocalAdaptMinThHigh;
   uint32  u32LocalAdaptLoadMinThHigh;
   uint32  u32LocalAdaptMaxThHigh;
   uint32  u32LocalAdaptLoadMaxThHigh;
   uint32  u32LocalExt_rAirLd;
   sint32  s32LocalAdaptMinThLow;
   sint32  s32LocalAdaptMaxThLow;
   sint32  s32LocalAdaptLoadMinThLow;
   sint32  s32LocalAdaptLoadMaxThLow;


   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);
   VEMS_vidGET(Zone_critique, bLocalZone_critique);

   KNKADPCOR_u8adapt_zone_fctPrev = Knk_adapt_zone_fct;

   s32LocalAdaptMinThLow =
      (sint32)(Knk_adapt_n_min - (Knk_adapt_n_hysteresis_zone0 * 5));
   u32LocalAdaptMinThHigh =
      (Knk_adapt_n_min + (Knk_adapt_n_hysteresis_zone0 * 5));

   s32LocalAdaptMaxThLow =
      (sint32)(Knk_adapt_n_max - (Knk_adapt_n_hysteresis_zone0 * 5));
   u32LocalAdaptMaxThHigh =
      (Knk_adapt_n_max + (Knk_adapt_n_hysteresis_zone0 * 5));

   s32LocalAdaptLoadMinThLow =
      (( 75 * Knk_adapt_load_min) - ( 8192 * Knk_adapt_load_hysteresis_zone0));
   u32LocalAdaptLoadMinThHigh =
      ((75 * Knk_adapt_load_min) + (8192 * Knk_adapt_load_hysteresis_zone0));

   s32LocalAdaptLoadMaxThLow =
      ((75 * Knk_adapt_load_max) - (8192 * Knk_adapt_load_hysteresis_zone0));
   u32LocalAdaptLoadMaxThHigh =
      ((75 * Knk_adapt_load_max) + (8192 * Knk_adapt_load_hysteresis_zone0));
   u32LocalExt_rAirLd = (u16LocalExt_rAirLd * 75);

   if (KNKADPCOR_boutputHysteresis1 == 1)
   {
      if (u16LocalRegime_moteur >= u32LocalAdaptMinThHigh)
      {
         KNKADPCOR_boutputHysteresis1 = 0;
      }
      else
      {
         KNKADPCOR_boutputHysteresis1 = 1;
      }
   }
   else
   {
      if (u16LocalRegime_moteur <= s32LocalAdaptMinThLow)
      {
         KNKADPCOR_boutputHysteresis1 = 1;
      }
      else
      {
         KNKADPCOR_boutputHysteresis1 = 0;
      }
   }

   if (KNKADPCOR_boutputHysteresis2 == 0)
   {
      if (u16LocalRegime_moteur >= u32LocalAdaptMaxThHigh)
      {
         KNKADPCOR_boutputHysteresis2 = 1;
      }
      else
      {
         KNKADPCOR_boutputHysteresis2 = 0;
      }
   }
   else
   {
      if (u16LocalRegime_moteur <= s32LocalAdaptMaxThLow)
      {
         KNKADPCOR_boutputHysteresis2 = 0;
      }
      else
      {
         KNKADPCOR_boutputHysteresis2 = 1;
      }
   }

   if (KNKADPCOR_boutputHysteresis3 == 1)
   {
      if (u32LocalExt_rAirLd >= u32LocalAdaptLoadMinThHigh)
      {
         KNKADPCOR_boutputHysteresis3 = 0;
      }
      else
      {
         KNKADPCOR_boutputHysteresis3 = 1;
      }
   }
   else
   {
      if ((sint32)u32LocalExt_rAirLd <= s32LocalAdaptLoadMinThLow)
      {
         KNKADPCOR_boutputHysteresis3 = 1;
      }
      else
      {
         KNKADPCOR_boutputHysteresis3 = 0;
      }
   }

   if (KNKADPCOR_boutputHysteresis4 == 0)
   {
      if (u32LocalExt_rAirLd >= u32LocalAdaptLoadMaxThHigh)
      {
         KNKADPCOR_boutputHysteresis4 = 1;
      }
      else
      {
         KNKADPCOR_boutputHysteresis4 = 0;
      }
   }
   else
   {
      if ((sint32)u32LocalExt_rAirLd <= s32LocalAdaptLoadMaxThLow)
      {
         KNKADPCOR_boutputHysteresis4 = 0;
      }
      else
      {
         KNKADPCOR_boutputHysteresis4 = 1;
      }
   }

   if (  (KNKADPCOR_boutputHysteresis1 != 0)
      || (KNKADPCOR_boutputHysteresis2 != 0)
      || (KNKADPCOR_boutputHysteresis3 != 0)
      || (KNKADPCOR_boutputHysteresis4 != 0))
   {
      bLocalResultLogicalOR = 1;
   }
   else
   {
      bLocalResultLogicalOR = 0;
   }
   /*Production of Knk_adapt_zone_fct */
   if (bLocalResultLogicalOR != 0)
   {
      Knk_adapt_zone_fct = 0;
   }
   else
   {
      KNKADPCOR_vidZoneDetermination();
   }
   /*Production of Knk_adapt_zone_fct_cyl*/
   bLocalAvMaxChgtZone = 0;
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         KNKADPCOR_u8KnkAdaptZoneCylPrev[u8LocalEng_noCmprNxtCyl - 1] =
            Knk_adapt_zone_fct_cyl[u8LocalEng_noCmprNxtCyl - 1];
         Knk_adapt_zone_fct_cyl[u8LocalEng_noCmprNxtCyl - 1] =
            Knk_adapt_zone_fct;
         if (KNKADPCOR_u8KnkAdaptZoneCylPrev[u8LocalEng_noCmprNxtCyl - 1] !=
            Knk_adapt_zone_fct_cyl[u8LocalEng_noCmprNxtCyl - 1])
         {
            bLocalAvMaxChgtZone = 1;
         }
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   /*Production of Av_bmax_adapt_anti_k_zone_cyl*/
   if (bLocalResultLogicalOR != 0)
   {
      for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
      {
         VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl,
                                   u8LocalIndex,
                                   0);
      }
   }
   else
   {
      if ( Knk_adapt_zone_fct_cyl[0] == 0)
      {
         s16LocalAv_bmax_anti_k_cyl_1 = 0;
      }
      else
      {
         s16LocalIndex1 = (sint16)(Knk_adapt_zone_fct_cyl[0] - 1);
         u8LocalIndex1 = (uint8)MATHSRV_udtMIN(s16LocalIndex1, 14);
         VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl1,
                                   u8LocalIndex1,
                                   s16LocalAv_bmax_anti_k_cyl_1);
      }

      if (Knk_adapt_zone_fct_cyl[1] == 0)
      {
         s16LocalAv_bmax_anti_k_cyl_2 = 0;
      }
      else
      {
         s16LocalIndex2 = (sint16)(Knk_adapt_zone_fct_cyl[1] - 1);
         u8LocalIndex2 = (uint8)MATHSRV_udtMIN(s16LocalIndex2, 14);
         VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl2,
                                   u8LocalIndex2,
                                   s16LocalAv_bmax_anti_k_cyl_2);
      }

      if ( Knk_adapt_zone_fct_cyl[2] == 0)
      {
         s16LocalAv_bmax_anti_k_cyl_3 = 0;
      }
      else
      {
         s16LocalIndex3 = (sint16)(Knk_adapt_zone_fct_cyl[2] - 1);
         u8LocalIndex3 = (uint8)MATHSRV_udtMIN(s16LocalIndex3, 14);
         VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl3,
                                   u8LocalIndex3,
                                   s16LocalAv_bmax_anti_k_cyl_3);
      }

      if ( Knk_adapt_zone_fct_cyl[3] == 0)
      {
         s16LocalAv_bmax_anti_k_cyl_4 = 0;
      }
      else
      {
         s16LocalIndex4 = (sint16)(Knk_adapt_zone_fct_cyl[3] - 1);
         u8LocalIndex4 = (uint8)MATHSRV_udtMIN(s16LocalIndex4, 14);
         VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_cyl4,
                                   u8LocalIndex4,
                                   s16LocalAv_bmax_anti_k_cyl_4);
      }

      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl,
                                0,
                                s16LocalAv_bmax_anti_k_cyl_1);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl,
                                1,
                                s16LocalAv_bmax_anti_k_cyl_2);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl,
                                2,
                                s16LocalAv_bmax_anti_k_cyl_3);
      VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl,
                                3,
                                s16LocalAv_bmax_anti_k_cyl_4);
   }

   /*Production of Av_bmax_conditions_raz_cptr*/

   if (  (bLocalAvMaxChgtZone != 0)
      || (  (bLocalZone_critique == 0)
         && (KNKADPCOR_bZone_critiquePrev != 0)
         && (Av_bmax_inh_reset_zone_crit == 0)))
   {
      Av_bmax_conditions_raz_cptr = 1;
   }
   else
   {
      Av_bmax_conditions_raz_cptr = 0;
   }
   VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl,
                             0,
                             s16LocalAv_bmax_anti_k_cyl_1);
   VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl,
                             1,
                             s16LocalAv_bmax_anti_k_cyl_2);
   VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl,
                             2,
                             s16LocalAv_bmax_anti_k_cyl_3);
   VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl,
                             3,
                             s16LocalAv_bmax_anti_k_cyl_4);
   Av_bmax_adapt_anti_k_zone_cyl1 = s16LocalAv_bmax_anti_k_cyl_1;
   Av_bmax_adapt_anti_k_zone_cyl2 = s16LocalAv_bmax_anti_k_cyl_2;
   Av_bmax_adapt_anti_k_zone_cyl3 = s16LocalAv_bmax_anti_k_cyl_3;
   Av_bmax_adapt_anti_k_zone_cyl4 = s16LocalAv_bmax_anti_k_cyl_4;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidZoneDetermination                             */
/* !Description :  Une hystérésis sur le régime moteur et la charge est       */
/*                 appliquée pour chaque transition de zone de fonctionnement.*/
/* !Number      :  FCT2.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Knk_adapt_n_zone;                                             */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Knk_adapt_n_hysteresis;                                       */
/*  input uint8 Regime_moteur_6_bkpt_map[6];                                  */
/*  input uint8 Knk_adapt_load_zone;                                          */
/*  input uint8 Knk_adapt_load_hysteresis;                                    */
/*  input uint16 Engine_load_5_bkpt_map[4];                                   */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint8 Knk_adapt_nb_n_zone;                                          */
/*  output uint8 Knk_adapt_n_zone;                                            */
/*  output uint8 Knk_adapt_load_zone;                                         */
/*  output uint8 Knk_adapt_zone_fct;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidZoneDetermination(void)
{
   /* 0_determination_zone */
   uint8  u8LocalZone;
   uint8  u8LocalRegime_moteur;
   uint16 u16LocalCalcPara;
   uint16 u16LocalExt_rAirLd;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalAddBkptHys;
   uint16 u16LocalCalcAdaptZone;
   uint16 u16LocalCalcHys;
   uint32 u32LocalAddBkptHys;
   uint32 u32LocalCalcHys;
   sint32 s32LocalDiffBkptHys;


   /* Knk_adapt_n_zone Calculation*/
   u8LocalZone = (uint8)MATHSRV_udtMIN(Knk_adapt_n_zone, 4);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalCalcHys = (uint16)(Knk_adapt_n_hysteresis * 5);
   u16LocalAddBkptHys = (uint16)( ( Regime_moteur_6_bkpt_map[u8LocalZone + 1]
                                  * 32)
                                + u16LocalCalcHys);
   s32LocalDiffBkptHys = (sint32)( ( Regime_moteur_6_bkpt_map[u8LocalZone]
                                   * 32)
                                 - u16LocalCalcHys);
   if (  (u16LocalRegime_moteur > u16LocalAddBkptHys)
      || ((sint32)u16LocalRegime_moteur < s32LocalDiffBkptHys))
   {
      if (u16LocalRegime_moteur >= 8160)
      {
         u8LocalRegime_moteur = 255;
      }
      else
      {
         u8LocalRegime_moteur = (uint8)(u16LocalRegime_moteur / 32);
      }
      u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_6_bkpt_map,
                                                     u8LocalRegime_moteur,
                                                     6);
      u8LocalZone = (uint8)(u16LocalCalcPara >> 8);
      Knk_adapt_n_zone = (uint8)MATHSRV_udtMIN(u8LocalZone, 4);
   }

   /* Knk_adapt_load_zone Calculation*/
   u8LocalZone = (uint8)MATHSRV_udtMIN(Knk_adapt_load_zone, 2);
   u32LocalCalcHys = (uint32)(Knk_adapt_load_hysteresis * 8192);

   u32LocalAddBkptHys = ( (uint32)(Engine_load_5_bkpt_map[u8LocalZone + 1] * 75)
                        + u32LocalCalcHys) / 75;
   s32LocalDiffBkptHys = (sint32)( Engine_load_5_bkpt_map[u8LocalZone]
                                 - u16LocalCalcHys);
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
   if (  (u16LocalExt_rAirLd > u32LocalAddBkptHys)
      || ((sint32)u16LocalExt_rAirLd < s32LocalDiffBkptHys))
   {
      u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Engine_load_5_bkpt_map,
                                                      u16LocalExt_rAirLd,
                                                      4);
      u8LocalZone = (uint8)(u16LocalCalcPara >> 8);
      Knk_adapt_load_zone = (uint8)MATHSRV_udtMIN(u8LocalZone, 2);
   }

   /* Knk_adapt_zone_fct Calculation*/
   u16LocalCalcAdaptZone = (uint16)( Knk_adapt_nb_n_zone
                                   * Knk_adapt_load_zone);
   u16LocalCalcAdaptZone = (uint16)( ( Knk_adapt_n_zone + 1)
                                   + u16LocalCalcAdaptZone);
   Knk_adapt_zone_fct = (uint8)MATHSRV_udtMIN(u16LocalCalcAdaptZone, 15);
}
/*---------------------------- end of file -----------------------------------*/
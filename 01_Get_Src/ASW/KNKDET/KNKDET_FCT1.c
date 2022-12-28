/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKDET                                                  */
/* !Description     : KNKDET Component                                        */
/*                                                                            */
/* !Module          : KNKDET                                                  */
/* !Description     : DÉTECTION DE CLIQUETIS                                  */
/*                                                                            */
/* !File            : KNKDET_FCT1.C                                           */
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
/*   1 / KNKDET_vidInitOutput                                                 */
/*   2 / KNKDET_vidInitStrategy                                               */
/*   3 / KNKDET_vidFactorFilterCalcN                                          */
/*   4 / KNKDET_vidFactorFilterCalcLoad                                       */
/*   5 / KNKDET_vidInitDynFilterCounter                                       */
/*   6 / KNKDET_vidDecrDynFilterCounter                                       */
/*   7 / KNKDET_vidFactorFilterCalcFreq                                       */
/*   8 / KNKDET_vidFactorFilterCalcFinal                                      */
/*   9 / KNKDET_vidInhibitionCorrection                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5068282 / 05                                        */
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
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "KNKDET.h"
#include "KNKDET_L.h"
#include "KNKDET_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidInitOutput                                       */
/* !Description :  Reset du compteur de temps avant sortie du transitoire     */
/*                 régime ou charge pour le facteur de filtrage (par          */
/*                 cylindre).                                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 Knk_det_dyn_filt_counter[4];                                 */
/*  output uint16 Regime_moteur_prev;                                         */
/*  output uint16 Ext_rTotLd_cliq_prev;                                       */
/*  output uint16 KNKDET_u16InhDetKnkAfterCounter;                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidInitOutput(void)
{
   /*00_init*/
   Knk_det_dyn_filt_counter[0] = 0;
   Knk_det_dyn_filt_counter[1] = 0;
   Knk_det_dyn_filt_counter[2] = 0;
   Knk_det_dyn_filt_counter[3] = 0;
   Regime_moteur_prev = 0;
   Ext_rTotLd_cliq_prev = 0;

   /*02_Inhibition_corrections*/
   KNKDET_u16InhDetKnkAfterCounter = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidInitStrategy                                     */
/* !Description :  Initialisation de stratégies à l'activation des            */
/*                 combustions.                                               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Detection_cliquetis[4];                                    */
/*  output boolean Detection_fort_cliquetis[4];                               */
/*  output uint16 Bruit_moyen_cyl[4];                                         */
/*  output boolean Knk_det_ris_knk_cyl_uavb1[4];                              */
/*  output boolean Bvmp_inh_cliq_acquisition;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidInitStrategy(void)
{
   /*00_init1*/
   boolean bLocalDetection_cliquetis[KNKDET_u32ARRAY_LENGTH];
   boolean bLocalDetection_fort_cliquetis[KNKDET_u32ARRAY_LENGTH];
   boolean bLocalKnk_det_ris_knk_cyl_uavb1[KNKDET_u32ARRAY_LENGTH];
   uint8   u8LocalIndex;
   uint16  u16LocalBruit_moyen_cyl[KNKDET_u32ARRAY_LENGTH];


   for (u8LocalIndex = 0; u8LocalIndex < KNKDET_u32ARRAY_LENGTH; u8LocalIndex++)
   {
      bLocalDetection_cliquetis[u8LocalIndex] = 0;
      bLocalDetection_fort_cliquetis[u8LocalIndex] = 0;
      u16LocalBruit_moyen_cyl[u8LocalIndex] = 1024;
      bLocalKnk_det_ris_knk_cyl_uavb1[u8LocalIndex] = 0;
   }
   VEMS_vidSET1DArray(Detection_cliquetis,
                      KNKDET_u32ARRAY_LENGTH,
                      bLocalDetection_cliquetis);
   VEMS_vidSET1DArray(Detection_fort_cliquetis,
                      KNKDET_u32ARRAY_LENGTH,
                      bLocalDetection_fort_cliquetis);
   VEMS_vidSET1DArray(Bruit_moyen_cyl,
                      KNKDET_u32ARRAY_LENGTH,
                      u16LocalBruit_moyen_cyl);
   VEMS_vidSET1DArray(Knk_det_ris_knk_cyl_uavb1,
                      KNKDET_u32ARRAY_LENGTH,
                      bLocalKnk_det_ris_knk_cyl_uavb1);

   VEMS_vidSET(Bvmp_inh_cliq_acquisition, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidFactorFilterCalcN                                */
/* !Description :  En  prévision  du  changement  de  filtrage  lors  des     */
/*                 transitoires,  les  transitoires  de  régime  sont  évalués*/
/*                  en observant  la variation de  régime sur  l’échantillon  */
/*                 temporel SdlSlow.                                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Regime_moteur_prev;                                          */
/*  input uint16 Knk_n_dyn_filt_thresh_uacn0;                                 */
/*  output boolean Knk_n_dyn_filt_det_uavb0;                                  */
/*  output uint16 Regime_moteur_prev;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidFactorFilterCalcN(void)
{
  /*01_Calc_facteur_filtrage_n*/
   uint32 u32LocalDynFiltThresh;
   uint16 u16LocalEngSpdDeltaAbs;
   uint16 u16LocalRegime_moteur;


   /*scaling:                                                                 */
   /*(Regime_moteur - Regime_moteur_prev) [rpm] >=                            */
   /*   (100) * Knk_n_dyn_filt_thresh_uacn0 [rpm/s]                           */
   /*         * KnkTreat_SampleTiSlow_SC    [ms]                              */
   /*                                                                         */
   /*(Regime_moteur - Regime_moteur_prev) [rpm] >=                            */
   /*   (0.1) * Knk_n_dyn_filt_thresh_uacn0 [rpm/ms]                          */
   /*         * KnkTreat_SampleTiSlow_SC    [ms]                              */
   /*                                                                         */
   /*Regime_moteur - Regime_moteur_prev >= (0.1) * Knk_n_dyn_filt_thresh_uacn0*/
   /*                                           * KnkTreat_SampleTiSlow_SC    */
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalEngSpdDeltaAbs =
      (uint16)MATHSRV_udtABS((sint32)( u16LocalRegime_moteur
                                     - Regime_moteur_prev));
   u32LocalDynFiltThresh = (uint32)( ( Knk_n_dyn_filt_thresh_uacn0
                                     * (uint16)(KnkTreat_SampleTiSlow_SC))
                                   / 10 );
   if ((uint32)u16LocalEngSpdDeltaAbs >= u32LocalDynFiltThresh)
   {
      Knk_n_dyn_filt_det_uavb0 = 1;
   }
   else
   {
      Knk_n_dyn_filt_det_uavb0 = 0;
   }

   Regime_moteur_prev = u16LocalRegime_moteur;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidFactorFilterCalcLoad                             */
/* !Description :  La détection des transitoires de charge est calculée à     */
/*                 fréquence SdlMid: en effet une Détection moins fréquente   */
/*                 induit un retard trop important dans l'application du gain */
/*                 de filtrage dynamique,avec comme conséquence des fausses   */
/*                 détections.                                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKDET_vidInitDynFilterCounter();                        */
/*  extf argret void KNKDET_vidDecrDynFilterCounter();                        */
/*  input uint16 Ext_rTotLd;                                                  */
/*  input uint16 Ext_rTotLd_cliq_prev;                                        */
/*  input uint16 Engine_load_cliq_seuil;                                      */
/*  input boolean Knk_eal_dyn_filt_det_uavb0;                                 */
/*  input boolean Knk_n_dyn_filt_det_uavb0;                                   */
/*  output boolean Knk_eal_dyn_filt_det_uavb0;                                */
/*  output uint16 Ext_rTotLd_cliq_prev;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidFactorFilterCalcLoad(void)
{
   /*02_Calc_facteur_filtrage_load*/
   uint16 u16LocalEngLdDeltaAbs;
   uint16 u16LocalExt_rTotLd;
   uint32 u32LocalEngLoad;
   uint32 u32LocalEngLdThresh;


   /*scaling:                                                                 */
   /*(300 / 65536) * (Ext_rTotLd - Ext_rTotLd_cliq_prev) [%] >=               */
   /*   (0.1) * Engine_load_cliq_seuil [%/s] * KnkTreat_SampleTiMid_SC [ms]   */
   /*                                                                         */
   /*(300 / 65536) * (Ext_rTotLd - Ext_rTotLd_cliq_prev) [%] >=               */
   /*   (0.1 / 1000) * Engine_load_cliq_seuil [%] * KnkTreat_SampleTiMid_SC   */
   /*                                                                         */
   /*(60000 / 256) * (Ext_rTotLd - Ext_rTotLd_cliq_prev) >=                   */
   /*  (256 / 50) * Engine_load_cliq_seuil * KnkTreat_SampleTiMid_SC         */
   VEMS_vidGET(Ext_rTotLd, u16LocalExt_rTotLd);
   u16LocalEngLdDeltaAbs =
      (uint16)MATHSRV_udtABS((sint32)( u16LocalExt_rTotLd
                                     - Ext_rTotLd_cliq_prev));
   u32LocalEngLoad = (uint32)((u16LocalEngLdDeltaAbs * 60000) / 256);

   u32LocalEngLdThresh = (uint32)( Engine_load_cliq_seuil
                                 * (uint16)(KnkTreat_SampleTiMid_SC));
   u32LocalEngLdThresh = (u32LocalEngLdThresh * 256) / 50;

   if (u32LocalEngLoad >= u32LocalEngLdThresh)
   {
      Knk_eal_dyn_filt_det_uavb0 = 1;
   }
   else
   {
      Knk_eal_dyn_filt_det_uavb0 = 0;
   }
   if (  (Knk_eal_dyn_filt_det_uavb0 != 0)
      || (Knk_n_dyn_filt_det_uavb0 != 0) )
   {
      KNKDET_vidInitDynFilterCounter();
   }
   else
   {
      KNKDET_vidDecrDynFilterCounter();
   }

   Ext_rTotLd_cliq_prev = u16LocalExt_rTotLd;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidInitDynFilterCounter                             */
/* !Description :  Initialisation du compteur de filtrage dynamique.          */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Knk_det_dyn_filt_delay;                                       */
/*  output uint8 Knk_det_dyn_filt_counter[4];                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidInitDynFilterCounter(void)
{
   /*01_init_dyn_filt_counter_*/
   Knk_det_dyn_filt_counter[0] = Knk_det_dyn_filt_delay;
   Knk_det_dyn_filt_counter[1] = Knk_det_dyn_filt_delay;
   Knk_det_dyn_filt_counter[2] = Knk_det_dyn_filt_delay;
   Knk_det_dyn_filt_counter[3] = Knk_det_dyn_filt_delay;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidDecrDynFilterCounter                             */
/* !Description :  Décrémentation du compteur de filtrage dynamique.          */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Knk_det_dyn_filt_counter[4];                                  */
/*  output uint8 Knk_det_dyn_filt_counter[4];                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidDecrDynFilterCounter(void)
{
   uint8  u8LocalIndex;
   sint16 s16LocalKnkCnt;


   /*02_decr_dyn_filt_counter_*/
   for (u8LocalIndex = 0; u8LocalIndex < KNKDET_u32ARRAY_LENGTH; u8LocalIndex++)
   {
      s16LocalKnkCnt = (sint16)(Knk_det_dyn_filt_counter[u8LocalIndex] - 1);
      Knk_det_dyn_filt_counter[u8LocalIndex] =
         (uint8)MATHSRV_udtMAX(s16LocalKnkCnt, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidFactorFilterCalcFreq                             */
/* !Description :  Le changement de la fréquence du filtre-passe bande peut   */
/*                 entraîner une variation brutale du bruit instantané qui    */
/*                 peut être interprété à tord comme du cliquetis.            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Knk_noCyl;                                                    */
/*  input boolean Knk_sen_dyn_filt_det_uavb1[4];                              */
/*  input uint8 Knk_det_dyn_filt_delay;                                       */
/*  output uint8 Knk_det_dyn_filt_counter[4];                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidFactorFilterCalcFreq(void)
{
   /*03_Calc_facteur_filtrage_freq*/
   boolean bLocalKnk_sen_dyn_filt_det_uavb1;
   uint8   u8LocalKnk_noCyl;


   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   switch(u8LocalKnk_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
      VEMS_vidGET1DArrayElement(Knk_sen_dyn_filt_det_uavb1,
                                u8LocalKnk_noCyl,
                                bLocalKnk_sen_dyn_filt_det_uavb1);
      if (bLocalKnk_sen_dyn_filt_det_uavb1 != 0)
      {
         Knk_det_dyn_filt_counter[u8LocalKnk_noCyl] = Knk_det_dyn_filt_delay;
      }
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidFactorFilterCalcFinal                            */
/* !Description :  Lors d'une transition de charge ou de régime ou si un      */
/*                 changement de la fréquence du filtre passe-bande a été     */
/*                 détecté, un filtrage différent (dynamique) est appliqué    */
/*                 durant un délai calibrable..                               */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Knk_noCyl;                                                    */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint8 Knk_det_dyn_filt_counter[4];                                  */
/*  input uint8 Facteur_filtrage_cliquetis_dyn;                               */
/*  input uint8 Knk_det_ris_dyn_n_map_uacn1[16];                              */
/*  input uint16 Knk_det_fort_dyn_n_map_uacn1[16];                            */
/*  input uint8 Facteur_filtrage_cliquetis_stat;                              */
/*  input uint8 Knk_det_ris_stat_n_map_uacn1[16];                             */
/*  input uint16 Knk_det_fort_stat_n_map_uacn1[16];                           */
/*  output uint8 Facteur_filtrage_cliquetis[4];                               */
/*  output uint8 Knk_det_ris_knk_thrsh_gain[4];                               */
/*  output uint16 Knk_det_fort_knk_thrsh_gain[4];                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidFactorFilterCalcFinal(void)
{
   /*04_Calc_facteur_filtrage_final*/
   uint8  u8LocalKnk_noCyl;
   uint16 u16LocalPara;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalRegMot;
   uint16 u16Localknk_thrsh_gain;


   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);

   u16LocalRegMot = (uint16)(u16LocalRegime_moteur * 8);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                               u16LocalRegMot,
                                               16);
   switch(u8LocalKnk_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
      if (Knk_det_dyn_filt_counter[u8LocalKnk_noCyl] != 0)
      {
         Facteur_filtrage_cliquetis[u8LocalKnk_noCyl] =
            Facteur_filtrage_cliquetis_dyn;
         Knk_det_ris_knk_thrsh_gain[u8LocalKnk_noCyl] =
            MATHSRV_u8Interp1d(Knk_det_ris_dyn_n_map_uacn1,
                               u16LocalPara);
         u16Localknk_thrsh_gain =
            MATHSRV_u16Interp1d(Knk_det_fort_dyn_n_map_uacn1,
                               u16LocalPara);
      }
      else
      {
         Facteur_filtrage_cliquetis[u8LocalKnk_noCyl] =
            Facteur_filtrage_cliquetis_stat;
         Knk_det_ris_knk_thrsh_gain[u8LocalKnk_noCyl] =
         MATHSRV_u8Interp1d(Knk_det_ris_stat_n_map_uacn1,
                            u16LocalPara);
         u16Localknk_thrsh_gain =
            MATHSRV_u16Interp1d(Knk_det_fort_stat_n_map_uacn1,
                              u16LocalPara);
      }
      u16Localknk_thrsh_gain = (uint16)MATHSRV_udtCLAMP(u16Localknk_thrsh_gain,
                               32, 287);
      Knk_det_fort_knk_thrsh_gain[u8LocalKnk_noCyl]= u16Localknk_thrsh_gain;
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidInhibitionCorrection                             */
/* !Description :  Afin d’éviter  les  fausses détections cliquetis en cas de */
/*                 fortes dégradations d’avance  lors des changements de      */
/*                 rapport,  la  détection  est  inhibée  lorsque  les        */
/*                 retraits  d’avance  dépassent  un seuil  calibrable.       */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 IgSys_agIgOptm;                                               */
/*  input uint8 IgSys_agIgMax;                                                */
/*  input uint8 IgSys_agIgSp;                                                 */
/*  input boolean CoPt_bSIPCord;                                              */
/*  input uint8 KnkDet_agDeltaAdvInhDetKnk_C;                                 */
/*  input uint16 KnkDet_tiInhDetKnkAfterGc_C;                                 */
/*  input uint16 KNKDET_u16InhDetKnkAfterCounter;                             */
/*  output uint16 KNKDET_u16InhDetKnkAfterCounter;                            */
/*  output boolean Bvmp_inh_cliq_acquisition;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidInhibitionCorrection(void)
{
   /*02_Inhibition_corrections*/
   boolean bLocalCoPt_bSIPCord;
   uint8   u8LocalAdvance;
   uint8   u8LocalIgSys_agIgOptm;
   uint8   u8LocalIgSys_agIgMax;
   uint8   u8LocalIgSys_agIgSp;
   uint16  u16Localcounter;
   sint16  s16LocalAdvanceSub;
   sint16  s16Localcompare;


   VEMS_vidGET(IgSys_agIgOptm, u8LocalIgSys_agIgOptm);
   VEMS_vidGET(IgSys_agIgMax, u8LocalIgSys_agIgMax);
   VEMS_vidGET(IgSys_agIgSp, u8LocalIgSys_agIgSp);
   VEMS_vidGET(CoPt_bSIPCord, bLocalCoPt_bSIPCord);

   u8LocalAdvance = (uint8)MATHSRV_udtMIN(u8LocalIgSys_agIgOptm,
                                          u8LocalIgSys_agIgMax);
   s16LocalAdvanceSub = (sint16)(u8LocalAdvance - u8LocalIgSys_agIgSp);
   s16Localcompare = (sint16)KnkDet_agDeltaAdvInhDetKnk_C;
   if (  (bLocalCoPt_bSIPCord != 0)
      && (s16LocalAdvanceSub >= s16Localcompare))
   {
      u16Localcounter = KnkDet_tiInhDetKnkAfterGc_C;
   }
   else
   {
      if (KNKDET_u16InhDetKnkAfterCounter > 0)
      {
         u16Localcounter = (uint16)(KNKDET_u16InhDetKnkAfterCounter - 1);
      }
      else
      {
         u16Localcounter = 0;
      }
   }
   KNKDET_u16InhDetKnkAfterCounter =
      (uint16)MATHSRV_udtMIN(u16Localcounter, 2550);

   if (KNKDET_u16InhDetKnkAfterCounter != 0)
   {
      VEMS_vidSET(Bvmp_inh_cliq_acquisition, 1);
   }
   else
   {
      VEMS_vidSET(Bvmp_inh_cliq_acquisition, 0);
   }
}
/*------------------------------- end of file --------------------------------*/
/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KnkDetRbl                                               */
/* !Description     : KnkDetRbl component.                                    */
/*                                                                            */
/* !Module          : KnkDetRbl                                               */
/* !Description     : RUMBLE DETECTION                                        */
/*                                                                            */
/* !File            : KNKDETRBL_FCT1.c                                        */
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
/*   1 / KNKDETRBL_vidInit                                                    */
/*   2 / KNKDETRBL_vidReinitTacheSynchRbl                                     */
/*   3 / KnkDetRbl_vidInitOutput                                              */
/*   4 / KnkDetRbl_vidCalcFactFiltrageN                                       */
/*   5 / KnkDetRbl_vidCalcFactFiltrLoad                                       */
/*   6 / KnkDetRbl_vidTache_rumble                                            */
/*   7 / KnkDetRbl_vidAutoriseDetectRbl                                       */
/*   8 / KnkDetRbl_vidKnkDetRblGainRegime                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5068340 / 09                                        */
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
#include "KnkDetRbl.h"
#include "KnkDetRbl_L.h"
#include "KnkDetRbl_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDETRBL_vidInit                                          */
/* !Description :  At the initialization, the counter Knk_rbl_dyn_filt_counter*/
/*                 is initialized at zero                                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Knk_Bruit_moyen_rbl_init_c;                                  */
/*  output uint8 Knk_rbl_dyn_filt_counter;                                    */
/*  output uint16 Bruit_moyen_rbl_cyl_prev[4];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDETRBL_vidInit(void)
{
   uint8 u8LocalIndex;


   Knk_rbl_dyn_filt_counter = 0;
   for(u8LocalIndex = 0; u8LocalIndex < KNKTREAT_u8ARRAY_LENGTH; u8LocalIndex++)
   {
      Bruit_moyen_rbl_cyl_prev[u8LocalIndex] = Knk_Bruit_moyen_rbl_init_c;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDETRBL_vidReinitTacheSynchRbl                           */
/* !Description :  The variable Bruit_moyen_rbl is initialized in its maximal */
/*                 value on event TOURNANT_SYNCHRO. The variables             */
/*                 Detection_rbl and Degradation_etat_rblA are initialized at */
/*                 0.                                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint16 Knk_Bruit_moyen_rbl_init_c;                                  */
/*  output uint16 Knk_det_rbl_thresh_uavn0_cyl[4];                            */
/*  output uint16 Bruit_moyen_rbl_cyl_prev[4];                                */
/*  output uint8 Knk_rbl_index_prev[4];                                       */
/*  output boolean Detection_rbl_prev[4];                                     */
/*  output uint16 Knk_det_rbl_thr_uavn0_cyl_prev[4];                          */
/*  output boolean Detection_rbl[4];                                          */
/*  output uint8 Knk_rbl_index[4];                                            */
/*  output uint16 Bruit_moyen_rbl_cyl[4];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDETRBL_vidReinitTacheSynchRbl(void)
{
   boolean bLocalDetection_rbl[KNKTREAT_u8ARRAY_LENGTH];
   uint8   u8LocalIndex;
   uint8   u8LocalKnk_rbl_index[KNKTREAT_u8ARRAY_LENGTH];
   uint16  u16LocalBruit_moyen_rbl_cyl[KNKTREAT_u8ARRAY_LENGTH];


   for (u8LocalIndex = 0;
        u8LocalIndex < KNKTREAT_u8ARRAY_LENGTH;
        u8LocalIndex++)
   {
      bLocalDetection_rbl[u8LocalIndex] = 0;
      u8LocalKnk_rbl_index[u8LocalIndex] = 16;
      u16LocalBruit_moyen_rbl_cyl[u8LocalIndex] = Knk_Bruit_moyen_rbl_init_c;
      Knk_det_rbl_thresh_uavn0_cyl[u8LocalIndex] = 0;
      Bruit_moyen_rbl_cyl_prev[u8LocalIndex] = Knk_Bruit_moyen_rbl_init_c;
      Knk_rbl_index_prev[u8LocalIndex] = 16;
      Detection_rbl_prev[u8LocalIndex] = 0;
      Knk_det_rbl_thr_uavn0_cyl_prev[u8LocalIndex] = 0;
   }

   VEMS_vidSET1DArray(Detection_rbl,
                      KNKTREAT_u8ARRAY_LENGTH,
                      bLocalDetection_rbl);
   VEMS_vidSET1DArray(Knk_rbl_index,
                      KNKTREAT_u8ARRAY_LENGTH,
                      u8LocalKnk_rbl_index);
   VEMS_vidSET1DArray(Bruit_moyen_rbl_cyl,
                      KNKTREAT_u8ARRAY_LENGTH,
                      u16LocalBruit_moyen_rbl_cyl);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidInitOutput                                    */
/* !Description :  At the initialization, the counter Knk_rbl_dyn_filt_counter*/
/*                 is initialized at zero                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output uint16 Ext_rTotLd_rbl_prev;                                        */
/*  output uint16 Regime_moteur_rbl_prev;                                     */
/*  output boolean Detection_rbl_cyl_wo_diag;                                 */
/*  output uint8 Knk_rbl_dyn_filt_counter_prev;                               */
/*  output uint8 Knk_rbl_index[4];                                            */
/*  output uint16 Bruit_moyen_rbl_cyl[4];                                     */
/*  output boolean Detection_rbl[4];                                          */
/*  output uint16 Knk_det_rbl_thresh_uavn0_cyl[4];                            */
/*  output uint8 Knk_rbl_index_prev[4];                                       */
/*  output boolean Detection_rbl_prev[4];                                     */
/*  output uint16 Knk_det_rbl_thr_uavn0_cyl_prev[4];                          */
/*  output uint8 Compteur_cyl_inh_rbl_det;                                    */
/*  output boolean Detection_rbl_cyl;                                         */
/*  output boolean KNKDETRBL_bCompteur_cyl_prev;                              */
/*  output boolean KNKDETRBL_bDetect_cylPrev;                                 */
/*  output uint16 KnkMgt_ctInjCutOffRbl_cyl;                                  */
/*  output boolean KnkMgt_bInjCutOffCyl;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidInitOutput(void)
{
   uint8 u8LocalIndex;


   Ext_rTotLd_rbl_prev = 0;
   Regime_moteur_rbl_prev = 0;
   Detection_rbl_cyl_wo_diag = 0;
   Knk_rbl_dyn_filt_counter_prev = 0;
   for(u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      VEMS_vidSET1DArrayElement(Knk_rbl_index, u8LocalIndex, 16);
      VEMS_vidSET1DArrayElement(Bruit_moyen_rbl_cyl, u8LocalIndex, 0);
      VEMS_vidSET1DArrayElement(Detection_rbl, u8LocalIndex, 0);
      Knk_det_rbl_thresh_uavn0_cyl[u8LocalIndex] = 0;
      Knk_rbl_index_prev[u8LocalIndex] = 16;
      Detection_rbl_prev[u8LocalIndex] = 0;
      Knk_det_rbl_thr_uavn0_cyl_prev[u8LocalIndex] = 0;
   }
   Compteur_cyl_inh_rbl_det = 0;
   Detection_rbl_cyl = 0;
   KNKDETRBL_bCompteur_cyl_prev = 0;
   KNKDETRBL_bDetect_cylPrev = 0;
   KnkMgt_ctInjCutOffRbl_cyl = 0;
   KnkMgt_bInjCutOffCyl = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidCalcFactFiltrageN                             */
/* !Description :  When the transient is detected, a boolean (                */
/*                 Knk_n_rbl_dyn_filt_det_uavb0) is raised so that the gain of*/
/*                 dynamic filtering are applied                              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Regime_moteur_rbl_prev;                                      */
/*  input uint16 Knk_n_rbl_dyn_filt_thresh_uacn0;                             */
/*  output boolean Knk_n_rbl_dyn_filt_uavb0;                                  */
/*  output uint16 Regime_moteur_rbl_prev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidCalcFactFiltrageN(void)
{
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalRegimeMotDelta;
   uint32 u32LocalCmpare;

   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);

   u16LocalRegimeMotDelta =
      (uint16)MATHSRV_udtABS(((sint32)u16LocalRegime_moteur
                                      - Regime_moteur_rbl_prev));
   u32LocalCmpare= (uint32)(u16LocalRegimeMotDelta * 8);
   if (u32LocalCmpare >= Knk_n_rbl_dyn_filt_thresh_uacn0)
   {
      Knk_n_rbl_dyn_filt_uavb0 = 1;
   }
   else
   {
      Knk_n_rbl_dyn_filt_uavb0 = 0;
   }
   Regime_moteur_rbl_prev =
      (uint16)MATHSRV_udtMIN(u16LocalRegime_moteur, 8191);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidCalcFactFiltrLoad                             */
/* !Description :  The detection of the transients of load is calculated on   */
/*                 sched Mid. If a transient of regime was before detected    */
/*                 (Knk_n_rbl_dyn_filt_det), the dynamic filtering is         */
/*                 automatically applied.                                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input uint16 Ext_rTotLd;                                                  */
/*  input boolean Knk_sen_dyn_filt_det_uavb1[4];                              */
/*  input uint16 Ext_rTotLd_rbl_prev;                                         */
/*  input uint16 Engine_load_rbl_seuil;                                       */
/*  input boolean Knk_n_rbl_dyn_filt_uavb0;                                   */
/*  input uint8 Knk_rbl_dyn_filt_delay;                                       */
/*  input uint8 Facteur_filtrage_rbl_dyn;                                     */
/*  input uint8 Knk_rbl_dyn_filt_counter_prev;                                */
/*  input uint8 Facteur_filtrage_rbl_stat;                                    */
/*  input uint8 Knk_rbl_dyn_filt_counter;                                     */
/*  output uint8 Knk_rbl_dyn_filt_counter;                                    */
/*  output uint8 Facteur_filtrage_rbl;                                        */
/*  output uint16 Ext_rTotLd_rbl_prev;                                        */
/*  output uint8 Knk_rbl_dyn_filt_counter_prev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidCalcFactFiltrLoad(void)
{
   boolean bLocalKnk_sen_dynFiltDetUavb1;
   uint8   u8LocalKnkRbl_noCyl;
   uint16  u16LocalExt_rTotLd;
   uint16  u16LocalExtrTotLdDeltaAbs;
   sint16  s16LocalKnkRblDynCounter;

   VEMS_vidGET(KnkRbl_noCyl , u8LocalKnkRbl_noCyl);
   switch (u8LocalKnkRbl_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
      VEMS_vidGET(Ext_rTotLd , u16LocalExt_rTotLd);
      VEMS_vidGET1DArrayElement(Knk_sen_dyn_filt_det_uavb1,
                                u8LocalKnkRbl_noCyl,
                                bLocalKnk_sen_dynFiltDetUavb1);
      u16LocalExtrTotLdDeltaAbs =
         (uint16)MATHSRV_udtABS((sint32)( u16LocalExt_rTotLd
                                        - Ext_rTotLd_rbl_prev));

      if (  (u16LocalExtrTotLdDeltaAbs >= Engine_load_rbl_seuil)
         || (Knk_n_rbl_dyn_filt_uavb0 != 0)
         || (bLocalKnk_sen_dynFiltDetUavb1 != 0))
      {
         Knk_rbl_dyn_filt_counter = Knk_rbl_dyn_filt_delay;
         Facteur_filtrage_rbl = Facteur_filtrage_rbl_dyn;
      }
      else
      {
         s16LocalKnkRblDynCounter = (sint16)(Knk_rbl_dyn_filt_counter_prev - 1);
         Knk_rbl_dyn_filt_counter =
            (uint8)MATHSRV_udtMAX(s16LocalKnkRblDynCounter, 0);
         if (Knk_rbl_dyn_filt_counter_prev > 0)
         {
            Facteur_filtrage_rbl = Facteur_filtrage_rbl_dyn;
         }
         else
         {
            Facteur_filtrage_rbl = Facteur_filtrage_rbl_stat;
         }
      }
      Ext_rTotLd_rbl_prev = u16LocalExt_rTotLd;
      Knk_rbl_dyn_filt_counter_prev = Knk_rbl_dyn_filt_counter;
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidTache_rumble                                  */
/* !Description :  The calculations are authorized only if the detection is   */
/*                 authorized and if KnkRbl_noCyl is lower or equal to 4      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KnkDetRbl_vidAutoriseDetectRbl();                        */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input boolean Autorise_detection_rbl;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidTache_rumble(void)
{
   boolean bLocalAutorise_detection_rbl;
   uint8   u8LocalKnkRbl_noCyl;

   VEMS_vidGET(KnkRbl_noCyl, u8LocalKnkRbl_noCyl);
   VEMS_vidGET(Autorise_detection_rbl, bLocalAutorise_detection_rbl);

   if (  (u8LocalKnkRbl_noCyl <= 3)
      && (bLocalAutorise_detection_rbl != 0))
   {
      KnkDetRbl_vidAutoriseDetectRbl();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidAutoriseDetectRbl                             */
/* !Description :  The calculation done when KnkTreat_EveRbl_KnkDetRbl is     */
/*                 triggered and KnkRbl_noCyl is lower or equal to 4          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void KnkDetRbl_vidKnkDetRblGainRegime();                      */
/*  extf argret void KnkDetRbl_vidTraitmntsDetectRrbl();                      */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input uint16 Bruit_instantane_rbl[16][4];                                 */
/*  input uint8 KnkMgt_prm_agIgKnkAdpOfsCyl[6];                               */
/*  input uint8 KnkMgt_agIgKnkAdpOfs;                                         */
/*  input uint16 Bruit_moyen_rbl_cyl_prev[4];                                 */
/*  input uint16 Bruit_moyen_rbl_max_thresh[4];                               */
/*  input boolean Detection_fort_cliquetis[4];                                */
/*  input boolean Detection_fort_cliquetis_cyl;                               */
/*  input uint16 KnkMgt_ctInjCutOffRbl[4];                                    */
/*  input uint16 KnkMgt_ctInjCutOffRbl_cyl;                                   */
/*  input boolean InjSys_prm_bCylCutOff[6];                                   */
/*  input boolean KnkMgt_bInjCutOffCyl;                                       */
/*  input uint8 Knk_rbl_index_prev[4];                                        */
/*  input boolean Detection_rbl_prev[4];                                      */
/*  input uint16 Knk_det_rbl_thr_uavn0_cyl_prev[4];                           */
/*  input uint8 Knk_rbl_index_det_cyl;                                        */
/*  input uint16 Bruit_moyen_rbl;                                             */
/*  input boolean Detection_rbl_cyl;                                          */
/*  input uint16 Knk_det_rbl_thresh_uavn0;                                    */
/*  input uint16 Bruit_moyen_rbl_cyl[4];                                      */
/*  input uint8 Knk_rbl_index[4];                                             */
/*  output uint16 Bruit_instantane_rbl_cyl[16];                               */
/*  output uint8 KnkMgt_agIgKnkAdpOfs;                                        */
/*  output uint16 Bruit_moyen_rbl_prev;                                       */
/*  output uint16 Bruit_moyen_rbl_cyl_max_thresh;                             */
/*  output boolean Detection_fort_cliquetis_cyl;                              */
/*  output uint16 KnkMgt_ctInjCutOffRbl_cyl;                                  */
/*  output boolean KnkMgt_bInjCutOffCyl;                                      */
/*  output uint16 Knk_det_rbl_thresh_uavn0_cyl[4];                            */
/*  output uint8 Knk_rbl_index[4];                                            */
/*  output uint16 Bruit_moyen_rbl_cyl[4];                                     */
/*  output boolean Detection_rbl[4];                                          */
/*  output uint16 Bruit_moyen_rbl_cyl_prev[4];                                */
/*  output uint8 Knk_rbl_index_prev[4];                                       */
/*  output boolean Detection_rbl_prev[4];                                     */
/*  output uint16 Knk_det_rbl_thr_uavn0_cyl_prev[4];                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidAutoriseDetectRbl(void)
{
   boolean bLocalDetection_rbl[KNKTREAT_u8ARRAY_LENGTH];
   uint8   u8LocalKnkRbl_noCyl;
   uint8   u8LocalIndex;
   uint8   u8LocalKnk_rbl_index[KNK_RBL_INDEX_COLS];
   uint16  u16LocalBruit_moyen_rbl_cyl[BRUIT_MOYEN_RBL_CYL_COLS];

   VEMS_vidGET(KnkRbl_noCyl, u8LocalKnkRbl_noCyl);

   switch (u8LocalKnkRbl_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:

      for (u8LocalIndex=0;u8LocalIndex<KNKDETRBL_u8ARRAY_LENGTH;u8LocalIndex++)
      {
         Bruit_instantane_rbl_cyl[u8LocalIndex] =
            Bruit_instantane_rbl[u8LocalIndex][u8LocalKnkRbl_noCyl];
      }
      VEMS_vidGET1DArrayElement(KnkMgt_prm_agIgKnkAdpOfsCyl,
                                u8LocalKnkRbl_noCyl,
                                KnkMgt_agIgKnkAdpOfs);
      KnkDetRbl_vidKnkDetRblGainRegime();
      Bruit_moyen_rbl_prev = Bruit_moyen_rbl_cyl_prev[u8LocalKnkRbl_noCyl];
      Bruit_moyen_rbl_cyl_max_thresh =
         Bruit_moyen_rbl_max_thresh[u8LocalKnkRbl_noCyl];
      VEMS_vidGET1DArrayElement(Detection_fort_cliquetis,
                                u8LocalKnkRbl_noCyl,
                                Detection_fort_cliquetis_cyl);
      VEMS_vidGET1DArrayElement(KnkMgt_ctInjCutOffRbl,
                                u8LocalKnkRbl_noCyl,
                                KnkMgt_ctInjCutOffRbl_cyl);
      VEMS_vidGET1DArrayElement(InjSys_prm_bCylCutOff,
                                u8LocalKnkRbl_noCyl,
                                KnkMgt_bInjCutOffCyl);

      KnkDetRbl_vidTraitmntsDetectRrbl();

      /*clamping the unchanged elements of output tables*/
      for (u8LocalIndex = 0;
           u8LocalIndex < BRUIT_MOYEN_RBL_CYL_COLS;
           u8LocalIndex++)
      {
         u8LocalKnk_rbl_index[u8LocalIndex] =
            (uint8)MATHSRV_udtMIN(Knk_rbl_index_prev[u8LocalIndex], 16);
         u16LocalBruit_moyen_rbl_cyl[u8LocalIndex] =
            Bruit_moyen_rbl_cyl_prev[u8LocalIndex];
         bLocalDetection_rbl[u8LocalIndex] = Detection_rbl_prev[u8LocalIndex];
         Knk_det_rbl_thresh_uavn0_cyl[u8LocalIndex] =
            Knk_det_rbl_thr_uavn0_cyl_prev[u8LocalIndex];
      }
      u8LocalKnk_rbl_index[u8LocalKnkRbl_noCyl] =
         (uint8)MATHSRV_udtMIN(Knk_rbl_index_det_cyl, 16);
      u16LocalBruit_moyen_rbl_cyl[u8LocalKnkRbl_noCyl] = Bruit_moyen_rbl;
      bLocalDetection_rbl[u8LocalKnkRbl_noCyl] = Detection_rbl_cyl ;
      Knk_det_rbl_thresh_uavn0_cyl[u8LocalKnkRbl_noCyl] =
         Knk_det_rbl_thresh_uavn0;
      VEMS_vidSET1DArray(Knk_rbl_index,
                         KNK_RBL_INDEX_COLS,
                         u8LocalKnk_rbl_index);
      VEMS_vidSET1DArray(Bruit_moyen_rbl_cyl,
                         BRUIT_MOYEN_RBL_CYL_COLS,
                         u16LocalBruit_moyen_rbl_cyl);
      VEMS_vidSET1DArray(Detection_rbl,
                         KNKTREAT_u8ARRAY_LENGTH,
                         bLocalDetection_rbl);
      VEMS_vidGET1DArray(Bruit_moyen_rbl_cyl,
                         BRUIT_MOYEN_RBL_CYL_COLS,
                         Bruit_moyen_rbl_cyl_prev);
      VEMS_vidGET1DArray(Knk_rbl_index,
                         KNK_RBL_INDEX_COLS,
                         Knk_rbl_index_prev);
      Detection_rbl_prev[u8LocalKnkRbl_noCyl] = Detection_rbl_cyl;
      Knk_det_rbl_thr_uavn0_cyl_prev[u8LocalKnkRbl_noCyl] =
         Knk_det_rbl_thresh_uavn0;
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidKnkDetRblGainRegime                           */
/* !Description :  According to KnkRbl_noCyl, only the mapping of the         */
/*                 concerned cylinder is estimated. The case " default " of   */
/*                 the switch is treated upstream to the block by a test on   */
/*                 the border max of KnkRbl_noCyl.                            */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_10_02581_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KnkDetRbl_vidCyl1_rbl();                                 */
/*  extf argret void KnkDetRbl_vidCyl2_rbl();                                 */
/*  extf argret void KnkDetRbl_vidCyl3_rbl();                                 */
/*  extf argret void KnkDetRbl_vidCyl4_rbl();                                 */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input uint8 Knk_det_rbl_gain_cyl1_regime;                                 */
/*  input uint8 Knk_det_rbl_gain_cyl2_regime;                                 */
/*  input uint8 Knk_det_rbl_gain_cyl3_regime;                                 */
/*  input uint8 Knk_det_rbl_gain_cyl4_regime;                                 */
/*  output uint8 Knk_det_rbl_gain_regime;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidKnkDetRblGainRegime(void)
{
   uint8 u8LocalKnkRbl_noCyl;

   VEMS_vidGET(KnkRbl_noCyl, u8LocalKnkRbl_noCyl);

   switch (u8LocalKnkRbl_noCyl)
   {
      case 0:
      KnkDetRbl_vidCyl1_rbl();
      Knk_det_rbl_gain_regime = Knk_det_rbl_gain_cyl1_regime;
      break;

      case 1:
      KnkDetRbl_vidCyl2_rbl();
      Knk_det_rbl_gain_regime = Knk_det_rbl_gain_cyl2_regime;
      break;

      case 2:
      KnkDetRbl_vidCyl3_rbl();
      Knk_det_rbl_gain_regime = Knk_det_rbl_gain_cyl3_regime;
      break;

      case 3:
      KnkDetRbl_vidCyl4_rbl();
      Knk_det_rbl_gain_regime = Knk_det_rbl_gain_cyl4_regime;
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
}
/*------------------------------- end of file --------------------------------*/
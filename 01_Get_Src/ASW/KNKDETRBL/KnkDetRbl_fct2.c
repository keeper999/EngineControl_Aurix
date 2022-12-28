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
/* !File            : KNKDETRBL_FCT2.c                                        */
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
/*   1 / KnkDetRbl_vidCyl1_rbl                                                */
/*   2 / KnkDetRbl_vidCyl3_rbl                                                */
/*   3 / KnkDetRbl_vidCyl4_rbl                                                */
/*   4 / KnkDetRbl_vidCyl2_rbl                                                */
/*   5 / KnkDetRbl_vidTraitmntsDetectRrbl                                     */
/*   6 / KnkDetRbl_vidDetection_rumble                                        */
/*   7 / KnkDetRbl_vidDetection_index                                         */
/*   8 / KnkDetRbl_vidCalcBruitMoyenRbl                                       */
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
#include "VEMS.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidCyl1_rbl                                      */
/* !Description :  calculate the value of Knk_det_rbl_gain_cyl1_regime from   */
/*                 the map Knk_det_rbl_gain_cyl1_n_map                        */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur_0_125;                                         */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint8 Knk_det_rbl_gain_cyl1_n_map[16];                              */
/*  input uint16 Cliq_eal[17];                                                */
/*  input uint8 Knk_det_rbl_gain_cyl1_eal_map[17];                            */
/*  input uint8 KnkRbl_agIgDetRblGainCyl_A[16];                               */
/*  input uint8 KnkMgt_agIgKnkAdpOfs;                                         */
/*  input uint8 Knk_det_rbl_gain_cyl1_agig_map[16];                           */
/*  output uint8 Knk_det_rbl_gain_cyl1_regime;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidCyl1_rbl(void)
{
/*QAC Warning(2:4152): name imposed by specification*/
   uint8   u8Localinterp1dn;
   uint8   u8Localinterp1deal;
   uint8   u8Localinterp1dagig;
   uint16  u16LocalRegime_moteur_0_125;
   uint16  u16LocalExt_rAirLd;
   uint16  u16LocalParan;
   uint16  u16LocalParaeal;
   uint16  u16LocalParagig;
   uint16  u16Localgain_cyl_regime;


   VEMS_vidGET(Regime_moteur_0_125, u16LocalRegime_moteur_0_125);
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);

   u16LocalParan = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                u16LocalRegime_moteur_0_125,
                                                16);
   u8Localinterp1dn = MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl1_n_map,
                                         u16LocalParan);

   u16LocalParaeal = MATHSRV_u16CalcParaIncAryU16(Cliq_eal,
                                                  u16LocalExt_rAirLd,
                                                  17);
   u8Localinterp1deal = MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl1_eal_map,
                                           u16LocalParaeal);

   u16LocalParagig =
      MATHSRV_u16CalcParaIncAryU8(KnkRbl_agIgDetRblGainCyl_A,
                                  KnkMgt_agIgKnkAdpOfs,
                                  16);
   u8Localinterp1dagig = MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl1_agig_map,
                                            u16LocalParagig);

   u16Localgain_cyl_regime =(uint16)( ( (u8Localinterp1dn * u8Localinterp1deal)
                                      * u8Localinterp1dagig)
                                    / 1024);
   Knk_det_rbl_gain_cyl1_regime = (uint8)MATHSRV_udtMIN(u16Localgain_cyl_regime,
                                                        255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidCyl3_rbl                                      */
/* !Description :  calculate the value of Knk_det_rbl_gain_cyl3_regime from   */
/*                 the map Knk_det_rbl_gain_cyl3_n_map                        */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur_0_125;                                         */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint8 Knk_det_rbl_gain_cyl3_n_map[16];                              */
/*  input uint16 Cliq_eal[17];                                                */
/*  input uint8 Knk_det_rbl_gain_cyl3_eal_map[17];                            */
/*  input uint8 KnkRbl_agIgDetRblGainCyl_A[16];                               */
/*  input uint8 KnkMgt_agIgKnkAdpOfs;                                         */
/*  input uint8 Knk_det_rbl_gain_cyl3_agig_map[16];                           */
/*  output uint8 Knk_det_rbl_gain_cyl3_regime;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidCyl3_rbl(void)
{
   uint8   u8Localinterp1dn;
   uint8   u8Localinterp1deal;
   uint8   u8Localinterp1dagig;
   uint16  u16LocalRegime_moteur_0_125;
   uint16  u16LocalParan;
   uint16  u16LocalParaeal;
   uint16  u16LocalParagig;
   uint16  u16LocalExt_rAirLd;
   uint16  u16Localgain_cyl3_regime;

   VEMS_vidGET(Regime_moteur_0_125, u16LocalRegime_moteur_0_125);
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);

   u16LocalParan = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                u16LocalRegime_moteur_0_125,
                                                16);
   u8Localinterp1dn = MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl3_n_map,
                                         u16LocalParan);

   u16LocalParaeal = MATHSRV_u16CalcParaIncAryU16(Cliq_eal,
                                                  u16LocalExt_rAirLd,
                                                  17);
   u8Localinterp1deal =
      MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl3_eal_map,u16LocalParaeal);

   u16LocalParagig =
      MATHSRV_u16CalcParaIncAryU8(KnkRbl_agIgDetRblGainCyl_A,
                                  KnkMgt_agIgKnkAdpOfs,
                                  16);
   u8Localinterp1dagig = MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl3_agig_map,
                                            u16LocalParagig);

   u16Localgain_cyl3_regime =(uint16)( ( (u8Localinterp1dn * u8Localinterp1deal)
                                       * u8Localinterp1dagig)
                                     / 1024);
   Knk_det_rbl_gain_cyl3_regime =
      (uint8)MATHSRV_udtMIN(u16Localgain_cyl3_regime,255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidCyl4_rbl                                      */
/* !Description :  calculate the value of Knk_det_rbl_gain_cyl4_regime from   */
/*                 the map Knk_det_rbl_gain_cyl4_n_map                        */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur_0_125;                                         */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint8 Knk_det_rbl_gain_cyl4_n_map[16];                              */
/*  input uint16 Cliq_eal[17];                                                */
/*  input uint8 Knk_det_rbl_gain_cyl4_eal_map[17];                            */
/*  input uint8 KnkRbl_agIgDetRblGainCyl_A[16];                               */
/*  input uint8 KnkMgt_agIgKnkAdpOfs;                                         */
/*  input uint8 Knk_det_rbl_gain_cyl4_agig_map[16];                           */
/*  output uint8 Knk_det_rbl_gain_cyl4_regime;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidCyl4_rbl(void)
{
   uint8   u8Localinterp1dn;
   uint8   u8Localinterp1deal;
   uint8   u8Localinterp1dagig;
   uint16  u16LocalRegime_moteur_0_125;
   uint16  u16LocalParan;
   uint16  u16LocalParaeal;
   uint16  u16LocalParagig;
   uint16  u16Localgain_cyl4_regime;
   uint16  u16LocalExt_rAirLd;


   VEMS_vidGET(Regime_moteur_0_125, u16LocalRegime_moteur_0_125);
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);

   u16LocalParan = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                u16LocalRegime_moteur_0_125,
                                                16);
   u8Localinterp1dn = MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl4_n_map,
                                         u16LocalParan);

   u16LocalParaeal = MATHSRV_u16CalcParaIncAryU16(Cliq_eal,
                                                  u16LocalExt_rAirLd,
                                                  17);
   u8Localinterp1deal = MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl4_eal_map,
                                           u16LocalParaeal);

   u16LocalParagig =
      MATHSRV_u16CalcParaIncAryU8(KnkRbl_agIgDetRblGainCyl_A,
                                  KnkMgt_agIgKnkAdpOfs,
                                  16);
   u8Localinterp1dagig = MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl4_agig_map,
                                            u16LocalParagig);

   u16Localgain_cyl4_regime =(uint16)( ( (u8Localinterp1dn * u8Localinterp1deal)
                                       * u8Localinterp1dagig)
                                     / 1024);
   Knk_det_rbl_gain_cyl4_regime =
      (uint8)MATHSRV_udtMIN(u16Localgain_cyl4_regime,255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidCyl2_rbl                                      */
/* !Description :  calculate the value of Knk_det_rbl_gain_cyl2_regime from   */
/*                 the map Knk_det_rbl_gain_cyl2_n_map                        */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur_0_125;                                         */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint8 Knk_det_rbl_gain_cyl2_n_map[16];                              */
/*  input uint16 Cliq_eal[17];                                                */
/*  input uint8 Knk_det_rbl_gain_cyl2_eal_map[17];                            */
/*  input uint8 KnkRbl_agIgDetRblGainCyl_A[16];                               */
/*  input uint8 KnkMgt_agIgKnkAdpOfs;                                         */
/*  input uint8 Knk_det_rbl_gain_cyl2_agig_map[16];                           */
/*  output uint8 Knk_det_rbl_gain_cyl2_regime;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidCyl2_rbl(void)
{
   uint8   u8LocalInterp1dn;
   uint8   u8Localinterp1deal;
   uint8   u8Localinterp1dagig;
   uint16  u16LocalRegime_moteur_0_125;
   uint16  u16LocalExt_rAirLd;
   uint16  u16LocalPara;
   uint16  u16LocalParaeal;
   uint16  u16LocalParagig;
   uint16  u16Localgain_cyl2_regime;


   VEMS_vidGET(Regime_moteur_0_125, u16LocalRegime_moteur_0_125);
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                               u16LocalRegime_moteur_0_125,
                                               16);
   u8LocalInterp1dn = MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl2_n_map,
                                         u16LocalPara);

   u16LocalParaeal = MATHSRV_u16CalcParaIncAryU16(Cliq_eal,
                                                  u16LocalExt_rAirLd,
                                                  17);
   u8Localinterp1deal = MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl2_eal_map,
                                           u16LocalParaeal);

   u16LocalParagig =
      MATHSRV_u16CalcParaIncAryU8(KnkRbl_agIgDetRblGainCyl_A,
                                  KnkMgt_agIgKnkAdpOfs,
                                  16);
   u8Localinterp1dagig = MATHSRV_u8Interp1d(Knk_det_rbl_gain_cyl2_agig_map,
                                            u16LocalParagig);

   u16Localgain_cyl2_regime =(uint16)( ( (u8LocalInterp1dn * u8Localinterp1deal)
                                       * u8Localinterp1dagig)
                                     / 1024);
   Knk_det_rbl_gain_cyl2_regime =
      (uint8)MATHSRV_udtMIN(u16Localgain_cyl2_regime,255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidTraitmntsDetectRrbl                           */
/* !Description :  The calculation of the average noise will be executed after*/
/*                 the detection of the rumble. You should not adapt the      */
/*                 average noise in the same way in case of presence of rumble*/
/*                 or presence of strong clanking.                            */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KnkDetRbl_vidDetection_rumble();                         */
/*  extf argret void KnkDetRbl_vidCalcBruitMoyenRbl();                        */
/*  input boolean Knk_sens_diag_act_uavb0;                                    */
/*  input boolean Auth_rbl_bruit_moy;                                         */
/*  output boolean Etat_capteur;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidTraitmntsDetectRrbl(void)
{
   boolean bLocalKnk_sens_diag_act_uavb0;
   boolean bLocalInhKnkRblDet;


   bLocalInhKnkRblDet = GDGAR_bGetFRM(FRM_FRM_INHKNKRBLDET);
   VEMS_vidGET(Knk_sens_diag_act_uavb0, bLocalKnk_sens_diag_act_uavb0);

   if (  (bLocalInhKnkRblDet == 0)
      && (bLocalKnk_sens_diag_act_uavb0 == 0))
   {
      Etat_capteur = 1;
   }
   else
   {
      Etat_capteur = 0;
   }
   KnkDetRbl_vidDetection_rumble();
   if(   (bLocalKnk_sens_diag_act_uavb0 == 0)
     &&  (Auth_rbl_bruit_moy != 0))
   {
      KnkDetRbl_vidCalcBruitMoyenRbl();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidDetection_rumble                              */
/* !Description :  The threshold of maximal immediate noise is defined by a   */
/*                 gain and an offset on the average noise calculated         */
/*                 previously                                                 */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KnkDetRbl_vidDetection_index();                          */
/*  input boolean Zone_critique_Rbl;                                          */
/*  input uint16 Bruit_moyen_rbl_prev;                                        */
/*  input uint8 Knk_det_rbl_gain_regime;                                      */
/*  input uint16 Bruit_moyen_rbl_cyl_max_thresh;                              */
/*  input boolean Knk_bInhKnkBvmp;                                            */
/*  input boolean Presence_bvmp;                                              */
/*  input boolean Bv_changement_rapport;                                      */
/*  input uint8 Knk_rbl_index_cyl_temp;                                       */
/*  input boolean Detection_rbl_cyl_wo_diag;                                  */
/*  input boolean Etat_capteur;                                               */
/*  input boolean KnkMgt_bInjCutOffCyl;                                       */
/*  input boolean Detection_rbl_cyl_raw;                                      */
/*  input boolean KNKDETRBL_bCompteur_cyl_prev;                               */
/*  input boolean KNKDETRBL_bDetect_cylPrev;                                  */
/*  input boolean Detection_rbl_cyl;                                          */
/*  input uint8 Knk_ctCylInhRblDet_C;                                         */
/*  input uint8 Compteur_cyl_inh_rbl_det;                                     */
/*  output uint16 Knk_det_rbl_thresh_uavn0;                                   */
/*  output uint8 Knk_rbl_index_det_cyl;                                       */
/*  output boolean Detection_rbl_cyl_raw;                                     */
/*  output boolean Detection_rbl_cyl;                                         */
/*  output uint8 Compteur_cyl_inh_rbl_det;                                    */
/*  output boolean Auth_rbl_bruit_moy;                                        */
/*  output boolean KNKDETRBL_bDetect_cylPrev;                                 */
/*  output boolean KNKDETRBL_bCompteur_cyl_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidDetection_rumble(void)
{
   boolean bLocalPresence_bvmp;
   boolean bLocalBv_changement_rapport;
   boolean bLocalVar;
   boolean bLocalZone_critique_Rbl;
   boolean bLocal_Compteur_cyl;
   uint16  u16LocalBruitMoyenPrevGain;
   sint16  s16LocalCompteur;

   VEMS_vidGET(Zone_critique_Rbl, bLocalZone_critique_Rbl);
   u16LocalBruitMoyenPrevGain =
      (uint16)(((uint32)Bruit_moyen_rbl_prev * Knk_det_rbl_gain_regime)>>5);
   Knk_det_rbl_thresh_uavn0 =
      (uint16)MATHSRV_udtMIN( ( (uint32)u16LocalBruitMoyenPrevGain
                              + Bruit_moyen_rbl_cyl_max_thresh),
                            65535);
   KnkDetRbl_vidDetection_index();
   if (Knk_bInhKnkBvmp != 0)
   {
      VEMS_vidGET(Presence_bvmp, bLocalPresence_bvmp);
      VEMS_vidGET(Bv_changement_rapport, bLocalBv_changement_rapport);
      if (  (bLocalPresence_bvmp != 0)
         && (bLocalBv_changement_rapport != 0))
      {
         bLocalVar = 1;
      }
      else
      {
         bLocalVar = 0;
      }
   }
   else
   {
      bLocalVar = 0;
   }
   if (bLocalVar != 0)
   {
      Knk_rbl_index_det_cyl = 16;
      Detection_rbl_cyl_raw = 0;
   }
   else
   {
      Knk_rbl_index_det_cyl = (uint8)MATHSRV_udtMIN(Knk_rbl_index_cyl_temp, 16);
      if (  (Detection_rbl_cyl_wo_diag != 0)
         && (Etat_capteur != 0)
         && (bLocalZone_critique_Rbl != 0)
         && (KnkMgt_bInjCutOffCyl == 0))
      {
         Detection_rbl_cyl_raw = 1;
      }
      else
      {
         Detection_rbl_cyl_raw = 0;
      }
   }
   /* Calcul of Detection_rbl_cyl*/
   if (  (Detection_rbl_cyl_raw != 0)
      && (KNKDETRBL_bCompteur_cyl_prev != 0))
   {
      Detection_rbl_cyl = 1;
   }
   else
   {
      Detection_rbl_cyl = 0;
   }

   if (  (KNKDETRBL_bDetect_cylPrev == 0)
      && (Detection_rbl_cyl!= 0))
   {
      Compteur_cyl_inh_rbl_det =
            (uint8)MATHSRV_udtMIN(Knk_ctCylInhRblDet_C, 20);
   }
   else
   {
      s16LocalCompteur = (sint16)(Compteur_cyl_inh_rbl_det - 1);
      Compteur_cyl_inh_rbl_det =
            (uint8)MATHSRV_udtCLAMP(s16LocalCompteur, 0, 20);
   }
   if (Compteur_cyl_inh_rbl_det == 0)
   {
      bLocal_Compteur_cyl = 1;
   }
   else
   {
      bLocal_Compteur_cyl = 0;
   }
   /* Calcul of Auth_rbl_bruit_moy */
   if (Detection_rbl_cyl_raw == Detection_rbl_cyl)
   {
      Auth_rbl_bruit_moy = 1;
   }
   else
   {
      Auth_rbl_bruit_moy = 0;
   }
   KNKDETRBL_bDetect_cylPrev = Detection_rbl_cyl;
   KNKDETRBL_bCompteur_cyl_prev = bLocal_Compteur_cyl;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidDetection_index                               */
/* !Description :  allows to find the index of the value of the table which is*/
/*                 superior at the threshold of detection of the rumble. If   */
/*                 none of the elements of the table is upper at the threshold*/
/*                 of detection, the rumble detection is put in zero, the     */
/*                 index at 16                                                */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Bruit_instantane_rbl_cyl[16];                                */
/*  input uint16 Knk_det_rbl_thresh_uavn0;                                    */
/*  input boolean Detection_rbl_cyl_wo_diag;                                  */
/*  output boolean Detection_rbl_cyl_wo_diag;                                 */
/*  output uint8 Knk_rbl_index_cyl_temp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidDetection_index(void)
{
   uint8 u8LocalIndex;

   u8LocalIndex = 0;
   do
   {
      if (Bruit_instantane_rbl_cyl[u8LocalIndex] >= Knk_det_rbl_thresh_uavn0)
      {
         Detection_rbl_cyl_wo_diag = 1;
         Knk_rbl_index_cyl_temp = u8LocalIndex;
      }
      else
      {
         Detection_rbl_cyl_wo_diag = 0;
         Knk_rbl_index_cyl_temp = 16;
      }
      u8LocalIndex++;
   }
   while ((u8LocalIndex < 16) && (Detection_rbl_cyl_wo_diag == 0));
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkDetRbl_vidCalcBruitMoyenRbl                             */
/* !Description :  In every PMH, this process must be executed after the      */
/*                 treatment of detection of the rumble so that the value     */
/*                 Bruit_moyen_rbl_cyl is not perturbed.                      */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_10_02581_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 KnkMgt_ctInjCutOffRbl_cyl;                                   */
/*  input uint16 Bruit_moyen_rbl_prev;                                        */
/*  input boolean Zone_critique_Rbl;                                          */
/*  input boolean Detection_rbl_cyl;                                          */
/*  input boolean Detection_fort_cliquetis_cyl;                               */
/*  input uint16 Knk_rbl_noi_inc_step_uacn0;                                  */
/*  input uint8 Longueur_table_sortie_rbl;                                    */
/*  input uint16 Bruit_instantane_rbl_cyl[16];                                */
/*  input boolean KnkMgt_bAcvInstNoiNormWiWind_C;                             */
/*  input uint8 Duree_fenetre_rumble;                                         */
/*  input uint8 KnkMgt_agIgRblWinLengthRef_C;                                 */
/*  input uint8 Facteur_filtrage_rbl;                                         */
/*  output uint16 Bruit_moyen_rbl;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkDetRbl_vidCalcBruitMoyenRbl(void)
{
   boolean bLocalZone_critique_Rbl;
   boolean bLocalInhKnkRblDet;
   uint8   u8LocalIndex16;
   uint8   u8LocalDuree_fenetre_rumble;
   uint16  u16LocalBruit_instantane_rbl_cyl;
   uint32  u32LocalProduct;
   uint32  u32LocalBruitMoyenRbl;
   uint32  u32LocalProd;
   sint32  s32LocalDiff;


   bLocalInhKnkRblDet = GDGAR_bGetFRM(FRM_FRM_INHKNKRBLDET);

   if (bLocalInhKnkRblDet != 0)
   {
      Bruit_moyen_rbl = 65535;
   }
   else
   {
      if (KnkMgt_ctInjCutOffRbl_cyl > 0)
      {
         Bruit_moyen_rbl = Bruit_moyen_rbl_prev;
      }
      else
      {
         VEMS_vidGET(Zone_critique_Rbl, bLocalZone_critique_Rbl);

         if (  (bLocalZone_critique_Rbl != 0)
            && (  (Detection_rbl_cyl != 0)
               || (Detection_fort_cliquetis_cyl != 0)))
         {
            u32LocalBruitMoyenRbl = (uint32) ( Bruit_moyen_rbl_prev
                                             + Knk_rbl_noi_inc_step_uacn0);
            Bruit_moyen_rbl =
               (uint16)MATHSRV_udtMIN(u32LocalBruitMoyenRbl, 65535);
         }
         else
         {
            u8LocalIndex16 = (uint8)MATHSRV_udtCLAMP(Longueur_table_sortie_rbl,
                                                     1,
                                                     16);
            u8LocalIndex16 = (uint8)(u8LocalIndex16 - 1);
            u16LocalBruit_instantane_rbl_cyl =
               Bruit_instantane_rbl_cyl[u8LocalIndex16];
            if (KnkMgt_bAcvInstNoiNormWiWind_C != 0)
            {
               VEMS_vidGET(Duree_fenetre_rumble, u8LocalDuree_fenetre_rumble);
               if (u8LocalDuree_fenetre_rumble != 0)
               {
                  u32LocalProduct =
                     (uint32)( ( KnkMgt_agIgRblWinLengthRef_C
                               * u16LocalBruit_instantane_rbl_cyl)
                             / u8LocalDuree_fenetre_rumble) ;
               }
               else
               {
                  u32LocalProduct = u16LocalBruit_instantane_rbl_cyl ;
               }
            }
            else
            {
               u32LocalProduct = u16LocalBruit_instantane_rbl_cyl ;
            }
            s32LocalDiff = (sint32)(u32LocalProduct - Bruit_moyen_rbl_prev);
            u32LocalProd =
               (uint32)((s32LocalDiff * Facteur_filtrage_rbl) / 255);
            u32LocalBruitMoyenRbl =  Bruit_moyen_rbl_prev + u32LocalProd;
            Bruit_moyen_rbl =
               (uint16)MATHSRV_udtMIN(u32LocalBruitMoyenRbl, 65535);
         }
      }
   }
}
/*-------------------------------- end of file -------------------------------*/
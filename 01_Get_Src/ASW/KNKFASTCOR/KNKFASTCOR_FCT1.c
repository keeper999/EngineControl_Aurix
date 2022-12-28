/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKFASTCOR                                              */
/* !Description     : KNKFASTCOR Component                                    */
/*                                                                            */
/* !Module          : KNKFASTCOR                                              */
/* !Description     : Correction rapide d’avance anti-cliquetis               */
/*                                                                            */
/* !File            : KNKFASTCOR_FCT1.C                                       */
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
/*   1 / KNKFASTCOR_vidInitOutput                                             */
/*   2 / KNKFASTCOR_vidFastCorrectionCalc                                     */
/*   3 / KNKFASTCOR_vidFastCorrOnCritZone                                     */
/*   4 / KNKFASTCOR_vidFastCorrection                                         */
/*   5 / KNKFASTCOR_vidCorNotInGearChange                                     */
/*   6 / KNKFASTCOR_vidCorrInGearChange                                       */
/*   7 / KNKFASTCOR_vidUncertainPhase                                         */
/*   8 / KNKFASTCOR_vidFastCorrOutCritZon                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5059533 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKFASTCOR/KNKFASTCOR_FCT1.C$*/
/* $Revision::   1.4      $$Author::   wbouach        $$Date::   25 Mar 2011 $*/
/* $Author::   wbouach                                $$Date::   25 Mar 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "KNKFASTCOR.h"
#include "KNKFASTCOR_L.h"
#include "KNKFASTCOR_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKFASTCOR_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation des sorties du module            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output uint8 Tempo_boucle_rapide[4];                                      */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_1;                               */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_2;                               */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_3;                               */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_4;                               */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_5;                               */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_6;                               */
/*  output uint8 Correction_boucle_rapide[4];                                 */
/*  output uint8 Cliquetis_cor_avance[4];                                     */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl[6];                              */
/*  output uint8 Cliquetis_cor_avance_count;                                  */
/*  output uint8 Correction_boucle_rapide_Cyl1;                               */
/*  output uint8 Correction_boucle_rapide_Cyl2;                               */
/*  output uint8 Correction_boucle_rapide_Cyl3;                               */
/*  output uint8 Correction_boucle_rapide_Cyl4;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKFASTCOR_vidInitOutput(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalArray[KNKFASTCOR_u32ARRAY_LENGTH];


   for (u8LocalIndex = 0;
        u8LocalIndex < KNKFASTCOR_u32ARRAY_LENGTH;
        u8LocalIndex++)
   {
      u8LocalArray[u8LocalIndex] = 0;
      Tempo_boucle_rapide[u8LocalIndex] = 0;
   }

   KnkMgt_prm_agIgKnkDetOfsCyl_1 = 96;
   KnkMgt_prm_agIgKnkDetOfsCyl_2 = 96;
   KnkMgt_prm_agIgKnkDetOfsCyl_3 = 96;
   KnkMgt_prm_agIgKnkDetOfsCyl_4 = 96;
   KnkMgt_prm_agIgKnkDetOfsCyl_5 = 96;
   KnkMgt_prm_agIgKnkDetOfsCyl_6 = 96;

   VEMS_vidSET1DArray(Correction_boucle_rapide,
                      KNKFASTCOR_u32ARRAY_LENGTH,
                      u8LocalArray);

   VEMS_vidSET1DArray(Cliquetis_cor_avance,
                      KNKFASTCOR_u32ARRAY_LENGTH,
                      u8LocalArray);

   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             0,
                             KnkMgt_prm_agIgKnkDetOfsCyl_1);
   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             1,
                             KnkMgt_prm_agIgKnkDetOfsCyl_2);
   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             2,
                             KnkMgt_prm_agIgKnkDetOfsCyl_3);
   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             3,
                             KnkMgt_prm_agIgKnkDetOfsCyl_4);
   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             4,
                             KnkMgt_prm_agIgKnkDetOfsCyl_5);
   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             5,
                             KnkMgt_prm_agIgKnkDetOfsCyl_6);

   Cliquetis_cor_avance_count = 0;
   Correction_boucle_rapide_Cyl1 = 0;
   Correction_boucle_rapide_Cyl2 = 0;
   Correction_boucle_rapide_Cyl3 = 0;
   Correction_boucle_rapide_Cyl4 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKFASTCOR_vidFastCorrectionCalc                           */
/* !Description :  On ne peut appliquer de correction rapide d’avance qu’en   */
/*                 cas de zone critique et si les acquisitions du capteur     */
/*                 cliquetis sont autorisées                                  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKFASTCOR_vidFastCorrOnCritZone();                      */
/*  extf argret void KNKFASTCOR_vidFastCorrOutCritZon();                      */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input boolean Zone_critique;                                              */
/*  input boolean Autorise_detection_clq;                                     */
/*  input uint8 Cliquetis_cor_avance[4];                                      */
/*  input uint8 Correction_boucle_rapide[4];                                  */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_1;                               */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_2;                               */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_3;                               */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_4;                               */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_5;                               */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl_6;                               */
/*  output uint8 KnkMgt_prm_agIgKnkDetOfsCyl[6];                              */
/*  output uint8 Correction_boucle_rapide_Cyl1;                               */
/*  output uint8 Correction_boucle_rapide_Cyl2;                               */
/*  output uint8 Correction_boucle_rapide_Cyl3;                               */
/*  output uint8 Correction_boucle_rapide_Cyl4;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKFASTCOR_vidFastCorrectionCalc(void)
{
   boolean bLocalZone_critique;
   boolean bLocalAutorise_detection_clq;
   uint8   u8LocalArray[KNKFASTCOR_u32ARRAY_LENGTH];
   uint8   u8LocalKnkMgtprmCyl;
   uint8   u8LocalKnkMgtprmCyl2;
   uint8   u8LocalKnkMgtprmCyl3;
   uint8   u8LocalKnkMgtprmCyl4;
   uint16  u16LocalScaling;


   VEMS_vidGET(Zone_critique, bLocalZone_critique);
   VEMS_vidGET(Autorise_detection_clq, bLocalAutorise_detection_clq);

   if (  (bLocalZone_critique != 0)
      && (bLocalAutorise_detection_clq != 0) )
   {
      KNKFASTCOR_vidFastCorrOnCritZone();
   }
   else
   {
      KNKFASTCOR_vidFastCorrOutCritZon();
   }

   VEMS_vidGET1DArray(Cliquetis_cor_avance,
                      KNKFASTCOR_u32ARRAY_LENGTH,
                      u8LocalArray);

   VEMS_vidGET1DArrayElement(Cliquetis_cor_avance,
                             0,
                             u8LocalKnkMgtprmCyl);
   u16LocalScaling = (uint16)(u8LocalKnkMgtprmCyl + 96);
   KnkMgt_prm_agIgKnkDetOfsCyl_1 = (uint8)MATHSRV_udtMIN(u16LocalScaling, 255);

   VEMS_vidGET1DArrayElement(Cliquetis_cor_avance,
                             1,
                             u8LocalKnkMgtprmCyl2);
   u16LocalScaling = (uint16)(u8LocalKnkMgtprmCyl2 + 96);
   KnkMgt_prm_agIgKnkDetOfsCyl_2 = (uint8)MATHSRV_udtMIN(u16LocalScaling, 255);

   VEMS_vidGET1DArrayElement(Cliquetis_cor_avance,
                             2,
                             u8LocalKnkMgtprmCyl3);
   u16LocalScaling = (uint16)(u8LocalKnkMgtprmCyl3 + 96);
   KnkMgt_prm_agIgKnkDetOfsCyl_3 = (uint8)MATHSRV_udtMIN(u16LocalScaling, 255);

   VEMS_vidGET1DArrayElement(Cliquetis_cor_avance,
                             3,
                             u8LocalKnkMgtprmCyl4);
   u16LocalScaling = (uint16)(u8LocalKnkMgtprmCyl4 + 96);
   KnkMgt_prm_agIgKnkDetOfsCyl_4 = (uint8)MATHSRV_udtMIN(u16LocalScaling, 255);

   KnkMgt_prm_agIgKnkDetOfsCyl_5 = 96;
   KnkMgt_prm_agIgKnkDetOfsCyl_6 = 96;

   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             0,
                             KnkMgt_prm_agIgKnkDetOfsCyl_1);
   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             1,
                             KnkMgt_prm_agIgKnkDetOfsCyl_2);
   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             2,
                             KnkMgt_prm_agIgKnkDetOfsCyl_3);
   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             3,
                             KnkMgt_prm_agIgKnkDetOfsCyl_4);
   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             4,
                             KnkMgt_prm_agIgKnkDetOfsCyl_5);
   VEMS_vidSET1DArrayElement(KnkMgt_prm_agIgKnkDetOfsCyl,
                             5,
                             KnkMgt_prm_agIgKnkDetOfsCyl_6);

   VEMS_vidGET1DArray(Correction_boucle_rapide, 4, u8LocalArray);
   Correction_boucle_rapide_Cyl1 = u8LocalArray[0];
   Correction_boucle_rapide_Cyl2 = u8LocalArray[1];
   Correction_boucle_rapide_Cyl3 = u8LocalArray[2];
   Correction_boucle_rapide_Cyl4 = u8LocalArray[3];
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKFASTCOR_vidFastCorrOnCritZone                           */
/* !Description :  Hors changement de rapport BVA ou BVMP, la correction      */
/*                 rapide appliquée a l'allure suivante (elle est calculée    */
/*                 positivement puis retranchée par la suite)                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void KNKFASTCOR_vidFastCorrection();                          */
/*  extf argret void KNKFASTCOR_vidCorrInGearChange();                        */
/*  extf argret void KNKFASTCOR_vidCorNotInGearChange();                      */
/*  extf argret void KNKFASTCOR_vidUncertainPhase();                          */
/*  input boolean Cipd_phase_calculated_uncertain;                            */
/*  input boolean Bvmp_inh_cliq_acquisition;                                  */
/*  input boolean Bv_changement_rapport;                                      */
/*  input boolean Presence_bva;                                               */
/*  input boolean Cipd_det_knk_2cyl_manu_inh;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKFASTCOR_vidFastCorrOnCritZone(void)
{
   boolean bLocalInhFastCor;
   boolean bLocalCipdPhaseCalcUncertain;
   boolean bLocalBvmp_inh_cliq_acquisition;
   boolean bLocalBv_changement_rapport;
   boolean bLocalPresence_bva;


   VEMS_vidGET(Cipd_phase_calculated_uncertain, bLocalCipdPhaseCalcUncertain);
   VEMS_vidGET(Bvmp_inh_cliq_acquisition, bLocalBvmp_inh_cliq_acquisition);
   VEMS_vidGET(Bv_changement_rapport, bLocalBv_changement_rapport);
   VEMS_vidGET(Presence_bva, bLocalPresence_bva);

   bLocalInhFastCor = GDGAR_bGetFRM(FRM_FRM_INHFASTCOR);

   if (  (  (Cipd_det_knk_2cyl_manu_inh == 0)
         || (bLocalCipdPhaseCalcUncertain == 0) )
      && (  (bLocalInhFastCor == 0)
         && (bLocalBvmp_inh_cliq_acquisition == 0) ) )
   {
      /* 0_correction_rapide */
      KNKFASTCOR_vidFastCorrection();
   }

   if (  (bLocalBvmp_inh_cliq_acquisition != 0)
      || (  (bLocalBv_changement_rapport != 0)
         && (bLocalPresence_bva != 0) ) )
   {
      /* 2_corr_en_chgt_rapport */
      KNKFASTCOR_vidCorrInGearChange();
   }
   else
   {
      /* 1_corr_hors_chgt_rapport */
      KNKFASTCOR_vidCorNotInGearChange();
   }

   if (  (Cipd_det_knk_2cyl_manu_inh != 0)
      && (bLocalCipdPhaseCalcUncertain != 0) )
   {
      /* 3_phase_uncertain */
      KNKFASTCOR_vidUncertainPhase();
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKFASTCOR_vidFastCorrection                               */
/* !Description :  En cas de détection ou de détection palliative de          */
/*                 cliquetis, ou de détection de super cliquetis, une         */
/*                 correction rapide sur le cylindre concerné est appliquée.  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void KNKFASTCOR_vidFastCorrIncre();                           */
/*  extf argret void KNKFASTCOR_vidFastCorrDecre();                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input boolean Detection_cliquetis[4];                                     */
/*  input boolean Knk_deg_det_cur_uavb1[4];                                   */
/*  input boolean KnkMgt_bSuperKnkDet[4];                                     */
/*  input boolean KnkMgt_bSuperKnkCurCyl;                                     */
/*  output boolean KnkMgt_bSuperKnkCurCyl;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKFASTCOR_vidFastCorrection(void)
{
   boolean bLocalDetection_cliquetis;
   boolean bLocalKnk_deg_det_cur_uavb1;
   uint8   u8LocalEng_noCmprCyl;


   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch(u8LocalEng_noCmprCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmprCyl = (uint8)(u8LocalEng_noCmprCyl - 1);

         VEMS_vidGET1DArrayElement(Detection_cliquetis,
                                   u8LocalEng_noCmprCyl,
                                   bLocalDetection_cliquetis);
         VEMS_vidGET1DArrayElement(Knk_deg_det_cur_uavb1,
                                   u8LocalEng_noCmprCyl,
                                   bLocalKnk_deg_det_cur_uavb1);
         VEMS_vidGET1DArrayElement(KnkMgt_bSuperKnkDet,
                                   u8LocalEng_noCmprCyl,
                                   KnkMgt_bSuperKnkCurCyl);
         if (  (bLocalDetection_cliquetis != 0)
            || (bLocalKnk_deg_det_cur_uavb1 != 0)
            || (KnkMgt_bSuperKnkCurCyl != 0))
         {
            /* 0_increm_cor_rapide */
            KNKFASTCOR_vidFastCorrIncre();
         }
         else
         {
            /* 1_decrem_cor_rapide */
            KNKFASTCOR_vidFastCorrDecre();
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
/* !Function    :  KNKFASTCOR_vidCorNotInGearChange                           */
/* !Description :  Après un changement de rapport BVA ou BVMP, hors panne     */
/*                 cliquetis, la correction finale d’avance                   */
/*                 Cliquetis_cor_avance est ramenée à la correction  courante */
/*                 Correction_boucle_rapide par un filtre pendant le délai    */
/*                 Cliquetis_cor_avance_delay.                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint8 Cliquetis_cor_avance_count;                                   */
/*  input boolean Cipd_phase_calculated_uncertain;                            */
/*  input boolean Cipd_det_knk_2cyl_manu_inh;                                 */
/*  input uint8 Cliquetis_cor_avance_defaut;                                  */
/*  input uint8 Correction_boucle_rapide[4];                                  */
/*  input uint8 Cliquetis_cor_avance[4];                                      */
/*  input uint8 Gain_filtre_cor_avance;                                       */
/*  output uint8 Cliquetis_cor_avance_count;                                  */
/*  output uint8 Cliquetis_cor_avance[4];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKFASTCOR_vidCorNotInGearChange(void)
{
   boolean bLocalAcvDftCor;
   boolean bLocalCipdPhaseCalcUncertain;
   uint8   u8LocalIndex;
   uint8   u8LocalArrayCliqCorrAvance[KNKFASTCOR_u32ARRAY_LENGTH];
   uint8   u8LocalArrayCorrBclRapide[KNKFASTCOR_u32ARRAY_LENGTH];
   sint16  s16LocalSoustrCorrBclRpd;
   sint32  s32LocalSoustrCorrBclRpd;


   if (Cliquetis_cor_avance_count <= 1)
   {
      Cliquetis_cor_avance_count = 0;
   }
   else
   {
      Cliquetis_cor_avance_count = (uint8)(Cliquetis_cor_avance_count - 1);
   }

   bLocalAcvDftCor = GDGAR_bGetFRM(FRM_FRM_ACVDFTCOR);
   VEMS_vidGET(Cipd_phase_calculated_uncertain, bLocalCipdPhaseCalcUncertain);

   if (  (bLocalAcvDftCor != 0)
      || (  (bLocalCipdPhaseCalcUncertain != 0)
         && (Cipd_det_knk_2cyl_manu_inh != 0) ) )
   {
      for (u8LocalIndex = 0;
           u8LocalIndex < KNKFASTCOR_u32ARRAY_LENGTH;
           u8LocalIndex++)
      {
         u8LocalArrayCliqCorrAvance[u8LocalIndex] = Cliquetis_cor_avance_defaut;
      }
   }
   else
   {
      if (Cliquetis_cor_avance_count == 0)
      {
         VEMS_vidGET1DArray(Correction_boucle_rapide,
                            KNKFASTCOR_u32ARRAY_LENGTH,
                            u8LocalArrayCorrBclRapide);
         for (u8LocalIndex = 0;
              u8LocalIndex < KNKFASTCOR_u32ARRAY_LENGTH;
              u8LocalIndex++)
         {
            u8LocalArrayCliqCorrAvance[u8LocalIndex] =
                  u8LocalArrayCorrBclRapide[u8LocalIndex];
         }
      }
      else
      {
         VEMS_vidGET1DArray(Cliquetis_cor_avance,
                            KNKFASTCOR_u32ARRAY_LENGTH,
                            u8LocalArrayCliqCorrAvance);

         VEMS_vidGET1DArray(Correction_boucle_rapide,
                            KNKFASTCOR_u32ARRAY_LENGTH,
                            u8LocalArrayCorrBclRapide);

         for (u8LocalIndex = 0;
              u8LocalIndex < KNKFASTCOR_u32ARRAY_LENGTH;
              u8LocalIndex++)
         {
            s16LocalSoustrCorrBclRpd =
            (sint16)( u8LocalArrayCorrBclRapide[u8LocalIndex]
                    - u8LocalArrayCliqCorrAvance[u8LocalIndex]);

            s32LocalSoustrCorrBclRpd = s16LocalSoustrCorrBclRpd
                                     * Gain_filtre_cor_avance;
            s16LocalSoustrCorrBclRpd =
                  (sint16)((s32LocalSoustrCorrBclRpd + 128) / 256);

            s16LocalSoustrCorrBclRpd =
                  (sint16)(s16LocalSoustrCorrBclRpd
                          + u8LocalArrayCliqCorrAvance[u8LocalIndex]);

            u8LocalArrayCliqCorrAvance[u8LocalIndex] =
                  (uint8)s16LocalSoustrCorrBclRpd;
         }
      }
   }
   VEMS_vidSET1DArray(Cliquetis_cor_avance,
                      KNKFASTCOR_u32ARRAY_LENGTH,
                      u8LocalArrayCliqCorrAvance);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKFASTCOR_vidCorrInGearChange                             */
/* !Description :  En changement de rapport BVA ou BVMP (accompagné d’un fort */
/*                 retrait d’avance dans le cas de la BVMP), la correction est*/
/*                 filtrée vers 0 par un filtre du premier ordre.             */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint8 Cliquetis_cor_avance[4];                                      */
/*  input uint8 Gain_filtre_cor_avance;                                       */
/*  input uint8 Cliquetis_cor_avance_delay;                                   */
/*  input uint8 Correction_boucle_rapide[4];                                  */
/*  input uint8 Gain_filtre_cor_boucle_rapide;                                */
/*  output uint8 Cliquetis_cor_avance[4];                                     */
/*  output uint8 Cliquetis_cor_avance_count;                                  */
/*  output uint8 Correction_boucle_rapide[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKFASTCOR_vidCorrInGearChange(void)
{
   uint8  u8LocalArrayCliqCorrAvance[KNKFASTCOR_u32ARRAY_LENGTH];
   uint8  u8LocalArrayCorrBcleRapide[KNKFASTCOR_u32ARRAY_LENGTH];
   uint8  u8LocalProdCorrBcleRapideGain;
   uint8  u8LocalDiv;
   uint16 u16LocalProdCorrBcleRapideGain;
   uint32 u32LocalProdCliqCorAvanceGain;
   uint32 u32LocalIndex;


   VEMS_vidGET1DArray(Cliquetis_cor_avance,
                      KNKFASTCOR_u32ARRAY_LENGTH,
                      u8LocalArrayCliqCorrAvance);

   for (u32LocalIndex = 0;
        u32LocalIndex < KNKFASTCOR_u32ARRAY_LENGTH;
        u32LocalIndex++)
   {
      u32LocalProdCliqCorAvanceGain =
         u8LocalArrayCliqCorrAvance[u32LocalIndex] * Gain_filtre_cor_avance;
      u32LocalProdCliqCorAvanceGain =
         (u32LocalProdCliqCorAvanceGain + 128) / 256;
      u32LocalProdCliqCorAvanceGain =
           u8LocalArrayCliqCorrAvance[u32LocalIndex]
         - u32LocalProdCliqCorAvanceGain;
      u8LocalArrayCliqCorrAvance[u32LocalIndex] =
            (uint8)u32LocalProdCliqCorAvanceGain;
   }

   VEMS_vidSET1DArray(Cliquetis_cor_avance,
                      KNKFASTCOR_u32ARRAY_LENGTH,
                      u8LocalArrayCliqCorrAvance);

   Cliquetis_cor_avance_count = Cliquetis_cor_avance_delay;

   VEMS_vidGET1DArray(Correction_boucle_rapide,
                      KNKFASTCOR_u32ARRAY_LENGTH,
                      u8LocalArrayCorrBcleRapide);

   for (u32LocalIndex = 0;
        u32LocalIndex < KNKFASTCOR_u32ARRAY_LENGTH;
        u32LocalIndex++)
   {
      u16LocalProdCorrBcleRapideGain =
         (uint16)( u8LocalArrayCorrBcleRapide[u32LocalIndex]
                 * Gain_filtre_cor_boucle_rapide);
      u8LocalDiv = (uint8)((u16LocalProdCorrBcleRapideGain + 128) / 256);
      u8LocalProdCorrBcleRapideGain =
           (uint8)(u8LocalArrayCorrBcleRapide[u32LocalIndex] - u8LocalDiv);
      u8LocalArrayCorrBcleRapide[u32LocalIndex] = u8LocalProdCorrBcleRapideGain;
   }
   VEMS_vidSET1DArray(Correction_boucle_rapide,
                      KNKFASTCOR_u32ARRAY_LENGTH,
                      u8LocalArrayCorrBcleRapide);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKFASTCOR_vidUncertainPhase                               */
/* !Description :  En cas de phase incertaine (Cipd_phase_calculated_uncertain*/
/*                 = 1), la Correction_boucle_rapide est forcée à 0 afin que  */
/*                 la correction auto-adaptative, qui est basée sur la        */
/*                 Correction_boucle_rapide n’apprenne pas de retrait         */
/*                 adaptatif (Av_bmax <> 0).                                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  output uint8 Tempo_boucle_rapide[4];                                      */
/*  output uint8 Correction_boucle_rapide[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKFASTCOR_vidUncertainPhase(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalArrayCorrBoucleRapide[KNKFASTCOR_u32ARRAY_LENGTH];


   for (u8LocalIndex = 0;
        u8LocalIndex < KNKFASTCOR_u32ARRAY_LENGTH;
        u8LocalIndex++)
   {
      u8LocalArrayCorrBoucleRapide[u8LocalIndex] = 0;
      Tempo_boucle_rapide[u8LocalIndex] = 0;
   }
   VEMS_vidSET1DArray(Correction_boucle_rapide,
                      KNKFASTCOR_u32ARRAY_LENGTH,
                      u8LocalArrayCorrBoucleRapide);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKFASTCOR_vidFastCorrOutCritZon                           */
/* !Description :  La correction rapide d’avance n'est pas appliquée lorsque  */
/*                 la zone n'est pas critique ou lorsque les acquisitions du  */
/*                 capteur cliquetis ne sont pas autorisées.                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  output uint8 Tempo_boucle_rapide[4];                                      */
/*  output uint8 Correction_boucle_rapide[4];                                 */
/*  output uint8 Cliquetis_cor_avance[4];                                     */
/*  output uint8 Cliquetis_cor_avance_count;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKFASTCOR_vidFastCorrOutCritZon(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalArrayCliqCorrAvance[KNKFASTCOR_u32ARRAY_LENGTH];


   for (u8LocalIndex = 0;
        u8LocalIndex < KNKFASTCOR_u32ARRAY_LENGTH;
        u8LocalIndex++)
   {
      Tempo_boucle_rapide[u8LocalIndex] = 0;
      u8LocalArrayCliqCorrAvance[u8LocalIndex] = 0;
   }
   VEMS_vidSET1DArray(Correction_boucle_rapide,
                      KNKFASTCOR_u32ARRAY_LENGTH,
                      u8LocalArrayCliqCorrAvance);

   VEMS_vidSET1DArray(Cliquetis_cor_avance,
                      KNKFASTCOR_u32ARRAY_LENGTH,
                      u8LocalArrayCliqCorrAvance);

   Cliquetis_cor_avance_count = 0;
}
/*--------------------------------- end of file ------------------------------*/
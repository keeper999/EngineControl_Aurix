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
/* !File            : KNKDET_FCT2.C                                           */
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
/*   1 / KNKDET_vidCylTreatment                                               */
/*   2 / KNKDET_vidCyclDetection                                              */
/*   3 / KNKDET_vidPairCylTreatment                                           */
/*   4 / KNKDET_vidCylUncertainTreatment                                      */
/*   5 / KNKDET_vidCy23Detection                                              */
/*   6 / KNKDET_vidCy14Detection                                              */
/*   7 / KNKDET_vidCylAverageNoiseCalc                                        */
/*   8 / KNKDET_vidAverageNoiseCalc                                           */
/*   9 / KNKDET_vidAverageNoiseReset                                          */
/*   10 / KNKDET_vidReset                                                     */
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
#include "VEMS.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidCylTreatment                                     */
/* !Description :  La détection est réalisée avant la mise à jour du bruit    */
/*                 moyen car celle-ci tient compte de la présence ou non de   */
/*                 cliquetis dans  le cylindre en cours.                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKDET_vidCyclDetection();                               */
/*  input boolean Autorise_detection_clq;                                     */
/*  input boolean Cipd_phase_calculated_uncertain;                            */
/*  input boolean Cipd_det_knk_2cyl_manu_inh;                                 */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidCylTreatment(void)
{
   /*05_Traitement_cyl*/
   boolean bLocalAutorise_detection_clq;
   boolean bLocalCipd_phase_calc_uncertain;


   VEMS_vidGET(Autorise_detection_clq, bLocalAutorise_detection_clq);
   VEMS_vidGET(Cipd_phase_calculated_uncertain,
               bLocalCipd_phase_calc_uncertain);
   if (  (  (bLocalCipd_phase_calc_uncertain == 0)
         || (Cipd_det_knk_2cyl_manu_inh != 0))
      && (bLocalAutorise_detection_clq != 0) )
   {
      KNKDET_vidCyclDetection();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidCyclDetection                                    */
/* !Description :  Le bruit instantané du dernier cylindre sur lequel on a    */
/*                 fait la mesure est comparé avec un seuil représentatif du  */
/*                 bruit de ce cylindre sans cliquetis pour décider de la     */
/*                 présence de cliquetis.                                     */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_08_06426_001.02                                     */
/*                 VEMS_E_08_06426_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Cliq_eal[17];                                                */
/*  input uint8 Knk_noCyl;                                                    */
/*  input uint8 Knk_det_gain_cyl1_n_map_uacn2[17][16];                        */
/*  input uint8 Knk_det_gain_cyl2_n_map_uacn2[17][16];                        */
/*  input uint8 Knk_det_gain_cyl3_n_map_uacn2[17][16];                        */
/*  input uint8 Knk_det_gain_cyl4_n_map_uacn2[17][16];                        */
/*  input uint16 Bruit_moyen_cyl[4];                                          */
/*  input uint16 Bruit_moyen_cyl_min_thresh[4];                               */
/*  input boolean Detection_rbl[4];                                           */
/*  input boolean Knk_sens_diag_act_uavb0;                                    */
/*  input boolean InjSys_prm_bCylCutOff[6];                                   */
/*  input boolean Knk_sen_dyn_filt_det_uavb1[4];                              */
/*  input uint16 Bruit_instantane[4];                                         */
/*  input uint16 Knk_det_thresh_cyl[4];                                       */
/*  input uint16 Knk_det_fort_knk_thrsh_gain[4];                              */
/*  input boolean active_conditions_clq;                                      */
/*  input boolean Knk_det_fort_knk_inh_uacb0;                                 */
/*  input boolean Detection_fort_cliquetis[4];                                */
/*  input boolean Knk_det_ris_knk_inh_uacb0;                                  */
/*  input uint8 Knk_det_ris_knk_thrsh_gain[4];                                */
/*  output uint16 Knk_det_thresh_cyl[4];                                      */
/*  output boolean active_conditions_clq;                                     */
/*  output boolean Detection_fort_cliquetis[4];                               */
/*  output boolean Detection_cliquetis[4];                                    */
/*  output boolean Knk_det_ris_knk_cyl_uavb1[4];                              */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidCyclDetection(void)
{
   /*01_detection_cyl*/
   boolean bLocalInhKnkDet;
   boolean bLocalKnk_sen_dyn_filt_det_uavb1;
   boolean bLocalKnk_sens_diag_act_uavb0;
   /*boolean bLocalDetection_cliquetis;*/
   boolean bLocalDetection_rbl;
   boolean bLocalInjSys_prm_bCylCutOff;
   boolean bLocalDetection_fort_cliquetis;
   uint8   u8LocalKnk_noCyl;
   uint8   u8LocalKnkDetGain;
   uint16  u16LocalEngSpdPara;
   uint16  u16LocalEngSpdPara1;
   uint16  u16LocalEngSpd;
   uint16  u16LocalExt_rAirLd;
   uint16  u16LocalKnkDetRis;
   uint16  u16LocalKnkDetFort;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalBruit_instantane;
   uint16  u16LocalBruit_moyen_cyl;
   uint32  u32LocalKnkDetCyl;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
   u16LocalEngSpd = (uint16)(u16LocalRegime_moteur * 8);
   u16LocalEngSpdPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                     u16LocalEngSpd,
                                                     16);
   u16LocalEngSpdPara1 = MATHSRV_u16CalcParaIncAryU16(Cliq_eal,
                                                      u16LocalExt_rAirLd,
                                                     17);
   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   switch (u8LocalKnk_noCyl)
   {
      case 0:
      u8LocalKnkDetGain =
         MATHSRV_u8Interp2d(&Knk_det_gain_cyl1_n_map_uacn2[0][0],
                            u16LocalEngSpdPara1,
                            u16LocalEngSpdPara,
                            16);
      break;

      case 1:
      u8LocalKnkDetGain =
         MATHSRV_u8Interp2d(&Knk_det_gain_cyl2_n_map_uacn2[0][0],
                            u16LocalEngSpdPara1,
                            u16LocalEngSpdPara,
                            16);
      break;

      case 2:
      u8LocalKnkDetGain =
         MATHSRV_u8Interp2d(&Knk_det_gain_cyl3_n_map_uacn2[0][0],
                            u16LocalEngSpdPara1,
                            u16LocalEngSpdPara,
                            16);
      break;

      case 3:
      u8LocalKnkDetGain =
         MATHSRV_u8Interp2d(&Knk_det_gain_cyl4_n_map_uacn2[0][0],
                            u16LocalEngSpdPara1,
                            u16LocalEngSpdPara,
                            16);
      break;

      default:
      u8LocalKnkDetGain = 0;
      SWFAIL_vidSoftwareErrorHook();
      break;
   }

   if(u8LocalKnk_noCyl <= 3)
   {
      VEMS_vidGET1DArrayElement(Bruit_moyen_cyl,
                                u8LocalKnk_noCyl,
                                u16LocalBruit_moyen_cyl);
      u32LocalKnkDetCyl = (uint32)( ( u16LocalBruit_moyen_cyl
                                    * u8LocalKnkDetGain)
                                  / 32);
      u32LocalKnkDetCyl =
         ( u32LocalKnkDetCyl
         + (uint32)Bruit_moyen_cyl_min_thresh[u8LocalKnk_noCyl]);
      Knk_det_thresh_cyl[u8LocalKnk_noCyl] =
         (uint16)MATHSRV_udtMIN(u32LocalKnkDetCyl, 65535);

      VEMS_vidGET1DArrayElement(Detection_rbl,
                                u8LocalKnk_noCyl,
                                bLocalDetection_rbl);
      bLocalInhKnkDet = GDGAR_bGetFRM(FRM_FRM_INHKNKDET);
      VEMS_vidGET(Knk_sens_diag_act_uavb0, bLocalKnk_sens_diag_act_uavb0);
      VEMS_vidGET1DArrayElement(InjSys_prm_bCylCutOff,
                                u8LocalKnk_noCyl,
                                bLocalInjSys_prm_bCylCutOff);
      VEMS_vidGET1DArrayElement(Knk_sen_dyn_filt_det_uavb1,
                                u8LocalKnk_noCyl,
                                bLocalKnk_sen_dyn_filt_det_uavb1);
      VEMS_vidGET1DArrayElement(Bruit_instantane,
                                u8LocalKnk_noCyl,
                                u16LocalBruit_instantane);
      if (  (bLocalDetection_rbl != 0)
         || (bLocalInhKnkDet != 0)
         || (bLocalKnk_sens_diag_act_uavb0 != 0)
         || (bLocalKnk_sen_dyn_filt_det_uavb1 != 0)
         || (bLocalInjSys_prm_bCylCutOff != 0))
      {
         active_conditions_clq = 1;
      }
      else
      {
         active_conditions_clq = 0;
      }
      u16LocalKnkDetFort =
         (uint16)(MATHSRV_udtMIN((
                  ( Knk_det_thresh_cyl[u8LocalKnk_noCyl]
                  * Knk_det_fort_knk_thrsh_gain[u8LocalKnk_noCyl])
                   / 32), 65535));
      if ( (active_conditions_clq != 0)
         ||(Knk_det_fort_knk_inh_uacb0 !=0))
      {
         VEMS_vidSET1DArrayElement(Detection_fort_cliquetis,
                                   u8LocalKnk_noCyl,
                                   0);
      }
      else
      {
         if (u16LocalBruit_instantane >= u16LocalKnkDetFort)
         {
            VEMS_vidSET1DArrayElement(Detection_fort_cliquetis,
                                      u8LocalKnk_noCyl,
                                      1);
         }
         else
         {
            VEMS_vidSET1DArrayElement(Detection_fort_cliquetis,
                                      u8LocalKnk_noCyl,
                                      0);
         }
      }

      VEMS_vidGET1DArrayElement(Detection_fort_cliquetis,
                             u8LocalKnk_noCyl,
                             bLocalDetection_fort_cliquetis);
      if (active_conditions_clq != 0)
      {
         VEMS_vidSET1DArrayElement(Detection_cliquetis, u8LocalKnk_noCyl, 0);
      }
      else
      {
         if (  (  u16LocalBruit_instantane
               >= Knk_det_thresh_cyl[u8LocalKnk_noCyl])
            && (bLocalDetection_fort_cliquetis == 0))
         {
            VEMS_vidSET1DArrayElement(Detection_cliquetis, u8LocalKnk_noCyl, 1);
         }
         else
         {
            VEMS_vidSET1DArrayElement(Detection_cliquetis, u8LocalKnk_noCyl, 0);
         }
      }
      if ( (active_conditions_clq != 0)
         ||(Knk_det_ris_knk_inh_uacb0 != 0))
      {
         VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1,
                                   u8LocalKnk_noCyl,
                                   0);
      }
      else
      {
         u16LocalKnkDetRis =
            (uint16)(  ( Knk_det_thresh_cyl[u8LocalKnk_noCyl]
                       * Knk_det_ris_knk_thrsh_gain[u8LocalKnk_noCyl])
                    / 256);
         if (  (u16LocalBruit_instantane >= u16LocalKnkDetRis)
            && (u16LocalBruit_instantane < Knk_det_thresh_cyl[u8LocalKnk_noCyl])
            && (bLocalDetection_fort_cliquetis == 0)  )
         {
            VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1,
                                      u8LocalKnk_noCyl,
                                      1);
         }
         else
         {
            VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1,
                                      u8LocalKnk_noCyl,
                                      0);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidPairCylTreatment                                 */
/* !Description :  Traitement par paire de cylindre.                          */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKDET_vidCylUncertainTreatment();                       */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input boolean Autorise_detection_clq;                                     */
/*  input boolean Cipd_phase_calculated_uncertain;                            */
/*  input boolean Cipd_det_knk_2cyl_manu_inh;                                 */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidPairCylTreatment(void)
{
   /*06_Traitement_cyl_paire*/
   boolean bLocalAutorise_detection_clq;
   boolean bLocalCipd_phase_calc_uncertain;
   uint8   u8LocalExtNoCylEng;


   VEMS_vidGET(Ext_noCylEng, u8LocalExtNoCylEng);
   VEMS_vidGET(Autorise_detection_clq, bLocalAutorise_detection_clq);
   VEMS_vidGET(Cipd_phase_calculated_uncertain,
               bLocalCipd_phase_calc_uncertain);
   if (  (bLocalCipd_phase_calc_uncertain != 0)
      && (bLocalAutorise_detection_clq != 0)
      && (Cipd_det_knk_2cyl_manu_inh == 0)
      && (u8LocalExtNoCylEng == 4))
   {
      KNKDET_vidCylUncertainTreatment();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidCylUncertainTreatment                            */
/* !Description :  Traitement en cas d'incertitude de detection.              */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKDET_vidCy23Detection();                               */
/*  extf argret void KNKDET_vidCy14Detection();                               */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Knk_noCyl;                                                    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidCylUncertainTreatment(void)
{
   /*01_Traitement_cyl_uncertain*/
   uint8 u8LocalKnk_noCyl;


   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   switch (u8LocalKnk_noCyl)
   {
      case 1:
      case 2:
      KNKDET_vidCy23Detection();
      break;

      case 0:
      case 3:
      KNKDET_vidCy14Detection();
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidCy23Detection                                    */
/* !Description :  Détection des cylindres 2 et 3 simultanément.              */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint8 Knk_noCyl;                                                    */
/*  input boolean Detection_rbl[4];                                           */
/*  input boolean Knk_sens_diag_act_uavb0;                                    */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Cliq_eal[17];                                                */
/*  input uint8 Knk_det_gain_cyl2_n_map_uacn2[17][16];                        */
/*  input uint8 Knk_det_gain_cyl3_n_map_uacn2[17][16];                        */
/*  input uint16 Bruit_moyen_cyl[4];                                          */
/*  input uint16 Bruit_moyen_cyl_min_thresh[4];                               */
/*  input uint16 Bruit_instantane[4];                                         */
/*  input boolean active_conditions_clq_23;                                   */
/*  input boolean Knk_det_fort_knk_inh_uacb0;                                 */
/*  input uint16 Knk_det_thresh_cyl[4];                                       */
/*  input uint16 Knk_det_fort_knk_thrsh_gain[4];                              */
/*  input boolean Detection_fort_cliquetis[4];                                */
/*  input boolean Knk_det_ris_knk_inh_uacb0;                                  */
/*  input uint8 Knk_det_ris_knk_thrsh_gain[4];                                */
/*  output boolean active_conditions_clq_23;                                  */
/*  output uint16 Knk_det_thresh_cyl[4];                                      */
/*  output boolean Detection_fort_cliquetis[4];                               */
/*  output boolean Detection_cliquetis[4];                                    */
/*  output boolean Knk_det_ris_knk_cyl_uavb1[4];                              */
/*                                                                            */

/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidCy23Detection(void)
{
   /*01_detection_cyl23*/
   boolean bLocalInhKnkDet;
   boolean bLocalKnkDetection;
   boolean bLocalKnk_sens_diag_act_uavb0;
   boolean bLocalDetection_rbl;
   boolean bLocalDetection_fort_cliquetis;
   uint8   u8LocalKnkDetGainCy2;
   uint8   u8LocalKnkDetGainCy3;
   uint8   u8LocalKnk_noCyl;
   uint16  u16LocalKnkDetRisKnkMin;
   uint16  u16LocalKnkDetRisKnk2;
   uint16  u16LocalKnkDetRisKnk3;
   uint16  u16LocalInstanNoiseMax;
   uint16  u16LocalKnkDetThreshCylMin;
   uint16  u16LocalEngSpd;
   uint16  u16LocalExt_rAirLd;
   uint16  u16LocalEngSpdPara;
   uint16  u16LocalEngSpdPara1;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalBruit_moyen_cyl[KNKDET_u32ARRAY_LENGTH];
   uint16  u16LocalBruit_instantane[KNKDET_u32ARRAY_LENGTH];
   uint16  u16LocalKnkDetFortKnk2;
   uint16  u16LocalKnkDetFortKnk3;
   uint16  u16LocalKnkDetFortKnkMin;
   uint32  u32LocalAvgNoiseCy2;
   uint32  u32LocalAvgNoiseCy3;

   /* Initialization used in order to avoid QAC warning 3204 */
   u16LocalBruit_moyen_cyl[0] = 0;
   u16LocalBruit_instantane[0] = 0;

   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   u8LocalKnk_noCyl = (uint8)MATHSRV_udtMIN(u8LocalKnk_noCyl, 3);
   VEMS_vidGET1DArrayElement(Detection_rbl,
                             u8LocalKnk_noCyl,
                             bLocalDetection_rbl);
   bLocalInhKnkDet = GDGAR_bGetFRM(FRM_FRM_INHKNKDET);
   VEMS_vidGET(Knk_sens_diag_act_uavb0, bLocalKnk_sens_diag_act_uavb0);
   if (  (bLocalDetection_rbl != 0)
      || (bLocalInhKnkDet != 0)
      || (bLocalKnk_sens_diag_act_uavb0 != 0))
   {
      active_conditions_clq_23 = 1;
   }
   else
   {
      active_conditions_clq_23 = 0;
   }
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
   u16LocalEngSpd = (uint16)MATHSRV_udtMIN((uint32)(u16LocalRegime_moteur * 8),
                                           65535);
   u16LocalEngSpdPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                     u16LocalEngSpd,
                                                     16);
   u16LocalEngSpdPara1 = MATHSRV_u16CalcParaIncAryU16(Cliq_eal,
                                                     u16LocalExt_rAirLd,
                                                     17);
   u8LocalKnkDetGainCy2 =
      MATHSRV_u8Interp2d(&Knk_det_gain_cyl2_n_map_uacn2[0][0],
                         u16LocalEngSpdPara1,
                         u16LocalEngSpdPara,
                         16);
   u8LocalKnkDetGainCy3 =
      MATHSRV_u8Interp2d(&Knk_det_gain_cyl3_n_map_uacn2[0][0],
                         u16LocalEngSpdPara1,
                         u16LocalEngSpdPara,
                         16);
   VEMS_vidGET1DArray(Bruit_moyen_cyl,
                      KNKDET_u32ARRAY_LENGTH,
                      u16LocalBruit_moyen_cyl);
   u32LocalAvgNoiseCy2 = (uint32)( ( ( u16LocalBruit_moyen_cyl[1]
                                     * u8LocalKnkDetGainCy2)
                                   / 32)
                                 + Bruit_moyen_cyl_min_thresh[1]);
   u32LocalAvgNoiseCy3 = (uint32)( ( ( u16LocalBruit_moyen_cyl[2]
                                     * u8LocalKnkDetGainCy3)
                                   / 32)
                                 + Bruit_moyen_cyl_min_thresh[2]);
   Knk_det_thresh_cyl[1] = (uint16)MATHSRV_udtMIN(u32LocalAvgNoiseCy2, 65535);
   Knk_det_thresh_cyl[2] = (uint16)MATHSRV_udtMIN(u32LocalAvgNoiseCy3, 65535);
   VEMS_vidGET1DArray(Bruit_instantane,
                      KNKDET_u32ARRAY_LENGTH,
                      u16LocalBruit_instantane);
   u16LocalInstanNoiseMax =
      (uint16)MATHSRV_udtMAX(u16LocalBruit_instantane[1],
                             u16LocalBruit_instantane[2]);

   if ( (active_conditions_clq_23 != 0)
      ||(Knk_det_fort_knk_inh_uacb0 !=0))
   {
      VEMS_vidSET1DArrayElement(Detection_fort_cliquetis, u8LocalKnk_noCyl, 0);
   }
   else
   {
      u16LocalKnkDetFortKnk2 =
         (uint16)(MATHSRV_udtMIN(((Knk_det_thresh_cyl[1]
                                   * Knk_det_fort_knk_thrsh_gain[1])
                                 / 32), 65535));
      u16LocalKnkDetFortKnk3 =
         (uint16)(MATHSRV_udtMIN(((Knk_det_thresh_cyl[2]
                                   * Knk_det_fort_knk_thrsh_gain[2])
                                  / 32), 65535));
      u16LocalKnkDetFortKnkMin = (uint16)MATHSRV_udtMIN(u16LocalKnkDetFortKnk2,
                                                        u16LocalKnkDetFortKnk3);
      if (u16LocalInstanNoiseMax >= u16LocalKnkDetFortKnkMin)
      {
         VEMS_vidSET1DArrayElement(Detection_fort_cliquetis,
                                   u8LocalKnk_noCyl, 1);
      }
      else
      {
         VEMS_vidSET1DArrayElement(Detection_fort_cliquetis,
                                   u8LocalKnk_noCyl, 0);
      }
   }

   VEMS_vidGET1DArrayElement(Detection_fort_cliquetis,
                             u8LocalKnk_noCyl,
                             bLocalDetection_fort_cliquetis);
   if (  (active_conditions_clq_23 != 0)
      || (bLocalDetection_fort_cliquetis != 0))
   {
      VEMS_vidSET1DArrayElement(Detection_cliquetis, 1, 0);
      VEMS_vidSET1DArrayElement(Detection_cliquetis, 2, 0);
      bLocalKnkDetection = 0;
   }
   else
   {
      u16LocalKnkDetThreshCylMin =
         (uint16)MATHSRV_udtMIN(Knk_det_thresh_cyl[1], Knk_det_thresh_cyl[2]);
      if (u16LocalInstanNoiseMax >= u16LocalKnkDetThreshCylMin)
      {
         VEMS_vidSET1DArrayElement(Detection_cliquetis, 1, 1);
         VEMS_vidSET1DArrayElement(Detection_cliquetis, 2, 1);
         bLocalKnkDetection = 1;
      }
      else
      {
         VEMS_vidSET1DArrayElement(Detection_cliquetis, 1, 0);
         VEMS_vidSET1DArrayElement(Detection_cliquetis, 2, 0);
         bLocalKnkDetection = 0;
      }
   }

   if (  (bLocalKnkDetection != 0)
      || (active_conditions_clq_23 != 0)
      || (Knk_det_ris_knk_inh_uacb0 != 0)
      || (bLocalDetection_fort_cliquetis != 0))
   {
      VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 1, 0);
      VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 2, 0);
   }
   else
   {
      u16LocalKnkDetRisKnk2 = (uint16)( ( Knk_det_thresh_cyl[1]
                                        * Knk_det_ris_knk_thrsh_gain[1])
                                      / 256);
      u16LocalKnkDetRisKnk3 = (uint16)( ( Knk_det_thresh_cyl[2]
                                        * Knk_det_ris_knk_thrsh_gain[2])
                                      / 256);
      u16LocalKnkDetRisKnkMin = (uint16)MATHSRV_udtMIN(u16LocalKnkDetRisKnk2,
                                                       u16LocalKnkDetRisKnk3);
      if (u16LocalInstanNoiseMax >= u16LocalKnkDetRisKnkMin)
      {
         VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 1, 1);
         VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 2, 1);
      }
      else
      {
         VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 1, 0);
         VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 2, 0);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidCy14Detection                                    */
/* !Description :  Détection des cylindres 1 et 4 simultanément.              */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint8 Knk_noCyl;                                                    */
/*  input boolean Detection_rbl[4];                                           */
/*  input boolean Knk_sens_diag_act_uavb0;                                    */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Cliq_eal[17];                                                */
/*  input uint8 Knk_det_gain_cyl1_n_map_uacn2[17][16];                        */
/*  input uint8 Knk_det_gain_cyl4_n_map_uacn2[17][16];                        */
/*  input uint16 Bruit_moyen_cyl[4];                                          */
/*  input uint16 Bruit_moyen_cyl_min_thresh[4];                               */
/*  input uint16 Bruit_instantane[4];                                         */
/*  input boolean Detection_fort_cliquetis[4];                                */
/*  input boolean active_conditions_clq_14;                                   */
/*  input boolean Knk_det_fort_knk_inh_uacb0;                                 */
/*  input uint16 Knk_det_thresh_cyl[4];                                       */
/*  input uint16 Knk_det_fort_knk_thrsh_gain[4];                              */
/*  input boolean Knk_det_ris_knk_inh_uacb0;                                  */
/*  input uint8 Knk_det_ris_knk_thrsh_gain[4];                                */
/*  output boolean active_conditions_clq_14;                                  */
/*  output uint16 Knk_det_thresh_cyl[4];                                      */
/*  output boolean Detection_fort_cliquetis[4];                               */
/*  output boolean Detection_cliquetis[4];                                    */
/*  output boolean Knk_det_ris_knk_cyl_uavb1[4];                              */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidCy14Detection(void)
{
   /*02_detection_cyl14*/
   boolean bLocalInhKnkDet;
   boolean bLocalKnkDetection;
   boolean bLocalKnk_sens_diag_act_uavb0;
   boolean bLocalDetection_rbl;
   boolean bLocalDetection_fort_cliquetis;
   uint8   u8LocalKnkDetGainCy1;
   uint8   u8LocalKnkDetGainCy4;
   uint8   u8LocalKnk_noCyl;
   uint16  u16LocalKnkDetRisKnk1;
   uint16  u16LocalKnkDetRisKnk4;
   uint16  u16LocalKnkDetRisKnkMin;
   uint16  u16LocalInstanNoiseMax;
   uint16  u16LocalKnkDetThreshCylMin;
   uint16  u16LocalEngSpd;
   uint16  u16LocalExt_rAirLd;
   uint16  u16LocalEngSpdPara;
   uint16  u16LocalEngSpdPara1;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalBruit_moyen_cyl[KNKDET_u32ARRAY_LENGTH];
   uint16  u16LocalBruit_instantane[KNKDET_u32ARRAY_LENGTH];
   uint16  u16LocalKnkDetFortKnkMin;
   uint16  u16LocalKnkDetFortKnk1;
   uint16  u16LocalKnkDetFortKnk4;
   uint32  u32LocalAvgNoiseCy1;
   uint32  u32LocalAvgNoiseCy4;

   /* Initialization used in order to avoid QAC warning 3204 */
   u16LocalBruit_moyen_cyl[0] = 0;
   u16LocalBruit_instantane[0] = 0;

   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   u8LocalKnk_noCyl = (uint8)MATHSRV_udtMIN(u8LocalKnk_noCyl, 3);
   VEMS_vidGET1DArrayElement(Detection_rbl,
                             u8LocalKnk_noCyl,
                             bLocalDetection_rbl);
   bLocalInhKnkDet = GDGAR_bGetFRM(FRM_FRM_INHKNKDET);
   VEMS_vidGET(Knk_sens_diag_act_uavb0, bLocalKnk_sens_diag_act_uavb0);
   if (  (bLocalDetection_rbl != 0)
      || (bLocalInhKnkDet != 0)
      || (bLocalKnk_sens_diag_act_uavb0 != 0))
   {
      active_conditions_clq_14 = 1;
   }
   else
   {
      active_conditions_clq_14 = 0;
   }
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);
   u16LocalEngSpd = (uint16)MATHSRV_udtMIN((uint32)(u16LocalRegime_moteur * 8),
                                           65535);
   u16LocalEngSpdPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                     u16LocalEngSpd,
                                                     16);
   u16LocalEngSpdPara1 = MATHSRV_u16CalcParaIncAryU16(Cliq_eal,
                                                     u16LocalExt_rAirLd,
                                                     17);
   u8LocalKnkDetGainCy1 =
      MATHSRV_u8Interp2d(&Knk_det_gain_cyl1_n_map_uacn2[0][0],
                         u16LocalEngSpdPara1,
                         u16LocalEngSpdPara,
                         16);
   u8LocalKnkDetGainCy4 =
      MATHSRV_u8Interp2d(&Knk_det_gain_cyl4_n_map_uacn2[0][0],
                         u16LocalEngSpdPara1,
                         u16LocalEngSpdPara,
                         16);
   VEMS_vidGET1DArray(Bruit_moyen_cyl,
                      KNKDET_u32ARRAY_LENGTH,
                      u16LocalBruit_moyen_cyl);
   u32LocalAvgNoiseCy1 = (uint32)( ( ( u16LocalBruit_moyen_cyl[0]
                                     * u8LocalKnkDetGainCy1)
                                   / 32)
                                 + Bruit_moyen_cyl_min_thresh[0]);
   u32LocalAvgNoiseCy4 = (uint32)( ( ( u16LocalBruit_moyen_cyl[3]
                                     * u8LocalKnkDetGainCy4)
                                   / 32)
                                 + Bruit_moyen_cyl_min_thresh[3]);
   Knk_det_thresh_cyl[0] = (uint16)MATHSRV_udtMIN(u32LocalAvgNoiseCy1, 65535);
   Knk_det_thresh_cyl[3] = (uint16)MATHSRV_udtMIN(u32LocalAvgNoiseCy4, 65535);
   VEMS_vidGET1DArray(Bruit_instantane,
                      KNKDET_u32ARRAY_LENGTH,
                      u16LocalBruit_instantane);
   u16LocalInstanNoiseMax = (uint16)MATHSRV_udtMAX(u16LocalBruit_instantane[0],
                                                   u16LocalBruit_instantane[3]);
   VEMS_vidGET1DArrayElement(Detection_fort_cliquetis,
                             u8LocalKnk_noCyl,
                             bLocalDetection_fort_cliquetis);
   if ( (active_conditions_clq_14 != 0)
      ||(Knk_det_fort_knk_inh_uacb0 !=0))
   {
      VEMS_vidSET1DArrayElement(Detection_fort_cliquetis, u8LocalKnk_noCyl, 0);
   }
   else
   {
      u16LocalKnkDetFortKnk1 =
         (uint16)(MATHSRV_udtMIN(((Knk_det_thresh_cyl[0]
                                  * Knk_det_fort_knk_thrsh_gain[0])
                                 / 32), 65535));
      u16LocalKnkDetFortKnk4 =
         (uint16)(MATHSRV_udtMIN(((Knk_det_thresh_cyl[3]
                                  * Knk_det_fort_knk_thrsh_gain[3])
                                 / 32), 65535));
      u16LocalKnkDetFortKnkMin = (uint16)MATHSRV_udtMIN(u16LocalKnkDetFortKnk1,
                                                        u16LocalKnkDetFortKnk4);
      if (u16LocalInstanNoiseMax >= u16LocalKnkDetFortKnkMin)
      {
         VEMS_vidSET1DArrayElement(Detection_fort_cliquetis,
                                   u8LocalKnk_noCyl,
                                   1);
      }
      else
      {
         VEMS_vidSET1DArrayElement(Detection_fort_cliquetis,
                                   u8LocalKnk_noCyl,
                                   0);
      }
   }
   if (  (active_conditions_clq_14 != 0)
      || (bLocalDetection_fort_cliquetis != 0))
   {
      VEMS_vidSET1DArrayElement(Detection_cliquetis, 0, 0);
      VEMS_vidSET1DArrayElement(Detection_cliquetis, 3, 0);
      bLocalKnkDetection = 0;
   }
   else
   {
      u16LocalKnkDetThreshCylMin =
         (uint16)MATHSRV_udtMIN(Knk_det_thresh_cyl[0], Knk_det_thresh_cyl[3]);
      if (u16LocalInstanNoiseMax >= u16LocalKnkDetThreshCylMin)
      {
         VEMS_vidSET1DArrayElement(Detection_cliquetis, 0, 1);
         VEMS_vidSET1DArrayElement(Detection_cliquetis, 3, 1);
         bLocalKnkDetection = 1;
      }
      else
      {
         VEMS_vidSET1DArrayElement(Detection_cliquetis, 0, 0);
         VEMS_vidSET1DArrayElement(Detection_cliquetis, 3, 0);
         bLocalKnkDetection = 0;
      }
   }
   if (  (bLocalKnkDetection != 0)
      || (active_conditions_clq_14 != 0)
      || (Knk_det_ris_knk_inh_uacb0 != 0)
      || (bLocalDetection_fort_cliquetis != 0))
   {
      VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 0, 0);
      VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 3, 0);
   }
   else
   {
      u16LocalKnkDetRisKnk1 = (uint16)( ( Knk_det_thresh_cyl[0]
                                        * Knk_det_ris_knk_thrsh_gain[0])
                                      / 256);
      u16LocalKnkDetRisKnk4 = (uint16)( ( Knk_det_thresh_cyl[3]
                                        * Knk_det_ris_knk_thrsh_gain[3])
                                      / 256);
      u16LocalKnkDetRisKnkMin = (uint16)MATHSRV_udtMIN(u16LocalKnkDetRisKnk1,
                                                       u16LocalKnkDetRisKnk4);
      if (u16LocalInstanNoiseMax >= u16LocalKnkDetRisKnkMin)
      {
         VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 0, 1);
         VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 3, 1);
      }
      else
      {
         VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 0, 0);
         VEMS_vidSET1DArrayElement(Knk_det_ris_knk_cyl_uavb1, 3, 0);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidCylAverageNoiseCalc                              */
/* !Description :  Calcul de bruit moyen d'un cylindre.                       */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKDET_vidAverageNoiseCalc();                            */
/*  input boolean Knk_sens_diag_act_uavb0;                                    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidCylAverageNoiseCalc(void)
{
   /*07_calc_bruit_moyen_cyl*/
   boolean bLocalKnk_sens_diag_act_uavb0;


   VEMS_vidGET(Knk_sens_diag_act_uavb0, bLocalKnk_sens_diag_act_uavb0);
   if (bLocalKnk_sens_diag_act_uavb0 == 0)
   {
      KNKDET_vidAverageNoiseCalc();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidAverageNoiseCalc                                 */
/* !Description :  Calcul du bruit moyen.                                     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Knk_noCyl;                                                    */
/*  input boolean Zone_critique;                                              */
/*  input uint16 KnkMgt_ctInjCutOffRbl[4];                                    */
/*  input uint16 Bruit_moyen_cyl[4];                                          */
/*  input boolean Detection_rbl[4];                                           */
/*  input boolean Detection_fort_cliquetis[4];                                */
/*  input boolean Detection_cliquetis[4];                                     */
/*  input boolean Knk_det_ris_knk_cyl_uavb1[4];                               */
/*  input uint16 Knk_det_noi_inc_step_uacn0;                                  */
/*  input uint16 Bruit_instantane[4];                                         */
/*  input uint8 Facteur_filtrage_cliquetis[4];                                */
/*  output uint16 Bruit_moyen_cyl[4];                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidAverageNoiseCalc(void)
{
   /*01_calcul_bm*/
   boolean bLocalZone_critique;
   boolean bLocalDetection_cliquetis;
   boolean bLocalKnk_det_ris_knk_cyl_uavb1;
   boolean bLocalDetection_rbl;
   boolean bLocalDetection_fort_cliquetis;
   uint8   u8LocalKnk_noCyl;
   uint16  u16LocalBruit_instantane;
   uint16  u16LocalBruit_moyen_cyl;
   uint16  u16LocalKnkMgt_ctInjCutOffRbl;
   sint32  s32LocalNoiseDelta;
   sint32  s32LocalAvgNoiseCyl;


   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   switch (u8LocalKnk_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
      VEMS_vidGET(Zone_critique, bLocalZone_critique);
      VEMS_vidGET1DArrayElement(KnkMgt_ctInjCutOffRbl,
                                u8LocalKnk_noCyl,
                                u16LocalKnkMgt_ctInjCutOffRbl);

      if (u16LocalKnkMgt_ctInjCutOffRbl == 0)
      {
         VEMS_vidGET1DArrayElement(Bruit_moyen_cyl,
                                   u8LocalKnk_noCyl,
                                   u16LocalBruit_moyen_cyl);
         VEMS_vidGET1DArrayElement(Detection_rbl,
                                   u8LocalKnk_noCyl,
                                   bLocalDetection_rbl);
         VEMS_vidGET1DArrayElement(Detection_fort_cliquetis,
                                   u8LocalKnk_noCyl,
                                   bLocalDetection_fort_cliquetis);
         VEMS_vidGET1DArrayElement(Detection_cliquetis,
                                   u8LocalKnk_noCyl,
                                   bLocalDetection_cliquetis);
         VEMS_vidGET1DArrayElement(Knk_det_ris_knk_cyl_uavb1,
                                   u8LocalKnk_noCyl,
                                   bLocalKnk_det_ris_knk_cyl_uavb1);
         if (  (  (bLocalDetection_rbl != 0)
               || (bLocalDetection_fort_cliquetis != 0)
               || (bLocalDetection_cliquetis != 0)
               || (bLocalKnk_det_ris_knk_cyl_uavb1 != 0) )
            && (bLocalZone_critique != 0) )
         {
            u16LocalBruit_moyen_cyl =
               (uint16)MATHSRV_udtMIN((uint32)( u16LocalBruit_moyen_cyl
                                              + Knk_det_noi_inc_step_uacn0),
                                      65535);
            VEMS_vidSET1DArrayElement(Bruit_moyen_cyl,
                                      u8LocalKnk_noCyl,
                                      u16LocalBruit_moyen_cyl);
         }
         else
         {
            VEMS_vidGET1DArrayElement(Bruit_instantane,
                                      u8LocalKnk_noCyl,
                                      u16LocalBruit_instantane);
            s32LocalNoiseDelta = (sint32)( u16LocalBruit_instantane
                                         - u16LocalBruit_moyen_cyl);
            s32LocalAvgNoiseCyl =
                 ( ( (sint32)Facteur_filtrage_cliquetis[u8LocalKnk_noCyl]
                   * s32LocalNoiseDelta)
                 / 256)
               + (sint32)u16LocalBruit_moyen_cyl;
            u16LocalBruit_moyen_cyl = (uint16)s32LocalAvgNoiseCyl;
            VEMS_vidSET1DArrayElement(Bruit_moyen_cyl,
                                      u8LocalKnk_noCyl,
                                      u16LocalBruit_moyen_cyl);
         }
      }
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidAverageNoiseReset                                */
/* !Description :  Réinitialisation du bruit moyen.                           */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void KNKDET_vidReset();                                       */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidAverageNoiseReset(void)
{
   /*08_reinit_bruit_moy*/
   boolean bLocalIniMeanNoise;


   bLocalIniMeanNoise = GDGAR_bGetFRM(FRM_FRM_INIMEANNOISE);
   if (bLocalIniMeanNoise != 0)
   {
      KNKDET_vidReset();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKDET_vidReset                                            */
/* !Description :  En cas de panne du capteur cliquetis, le bruit moyen est   */
/*                 réinitialisé à sa valeur maximale en raison de             */
/*                 l'incertitude sur la pertinence des mesures précédentes.   */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  output uint16 Bruit_moyen_cyl[4];                                         */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKDET_vidReset(void)
{
   /*01_Reinit*/
   uint8   u8LocalIndex;
   uint16  u16LocalBruit_moyen_cyl[KNKDET_u32ARRAY_LENGTH];


   for (u8LocalIndex = 0; u8LocalIndex < KNKDET_u32ARRAY_LENGTH; u8LocalIndex++)
   {
      u16LocalBruit_moyen_cyl[u8LocalIndex] = 1024;
   }
   VEMS_vidSET1DArray(Bruit_moyen_cyl,
                      KNKDET_u32ARRAY_LENGTH,
                      u16LocalBruit_moyen_cyl);
}
/*------------------------------- end of file --------------------------------*/
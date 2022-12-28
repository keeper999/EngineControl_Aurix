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
/* !File            : KNKADPCOR_FCT3.C                                        */
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
/*   1 / KNKADPCOR_vidCounterReset                                            */
/*   2 / KNKADPCOR_vidTreatment                                               */
/*   3 / KNKADPCOR_vidConditionalVarReset                                     */
/*   4 / KNKADPCOR_vidCylAdaptation                                           */
/*   5 / KNKADPCOR_vidMajAvBmax                                               */
/*   6 / KNKADPCOR_vidAntiKnockPrevention                                     */
/*   7 / KNKADPCOR_vidCalcAvBmaxMoyen                                         */
/*   8 / KNKADPCOR_vidFiltering                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5154831 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKADPCOR/KNKADPCOR_FCT3.C_v$*/
/* $Revision::   1.13     $$Author::   wbouach        $$Date::   09 May 2012 $*/
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
/* !Function    :  KNKADPCOR_vidCounterReset                                  */
/* !Description :  A chaque changement de zone, les adaptatifs correspondant à*/
/*                 la nouvelle zone sont appliqués.                           */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKADPCOR_vidTreatment();                                */
/*  extf argret void KNKADPCOR_vidConditionalVarReset();                      */
/*  input boolean Av_bmax_conditions_raz_cptr;                                */
/*  input uint8 Knk_adapt_zone_fct;                                           */
/*  input boolean Av_bmax_inh_reset_chgt_zone;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidCounterReset(void)
{
   /* 7_raz_compteurs */
   if (  (Av_bmax_conditions_raz_cptr != 0)
      && (Knk_adapt_zone_fct !=0))
   {
      /* 0_traitements */
      KNKADPCOR_vidTreatment();
      if (Av_bmax_inh_reset_chgt_zone == 0)
      {
         /* 1_reset_conditionnnel_variables */
         KNKADPCOR_vidConditionalVarReset();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidTreatment                                     */
/* !Description :  A chaque changement de zone, les adaptatifs correspondant à*/
/*                 la nouvelle zone sont appliqués.                           */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input sint16 Av_bmax_adapt_anti_k_zone_cyl[4];                            */
/*  output sint16 Av_bmax_adapt_avant_moy_cyl[4];                             */
/*  output sint16 Av_bmax_adap_avt_slew_rate_cyl[4];                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidTreatment(void)
{
   /* 0_traitements */
   uint8  u8LocalIndex;
   sint16 s16LocalAv_adapt_anti_k_zone_cyl;


   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl,
                                u8LocalIndex,
                                s16LocalAv_adapt_anti_k_zone_cyl);

      Av_bmax_adapt_avant_moy_cyl[u8LocalIndex] =
         s16LocalAv_adapt_anti_k_zone_cyl;
      Av_bmax_adap_avt_slew_rate_cyl[u8LocalIndex] =
         s16LocalAv_adapt_anti_k_zone_cyl;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidConditionalVarReset                           */
/* !Description :  A chaque changement de zone, les compteurs de retard et de */
/*                 décrémentation sont réinitialisés.                         */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Knk_regime_moteur;                                           */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Av_bmax_retard_delai_map[16];                                */
/*  input uint16 Av_bmax_decrem_delai_map[16];                                */
/*  output uint16 Av_bmax_retard_cptr_cyl[4];                                 */
/*  output uint16 Av_bmax_decrem_cptr_cyl[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidConditionalVarReset(void)
{
   /* 1_reset_conditionnnel_variables */
   uint8  u8LocalIdx;
   uint16 u16LocalCalcPara;
   uint16 u16LocalEngSpd;
   uint16 u16LocalDly;
   uint16 u16LocalDecDly;


   u16LocalEngSpd = (uint16)(Knk_regime_moteur * 8);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                   u16LocalEngSpd,
                                                   16);
   u16LocalDly = MATHSRV_u16Interp1d(Av_bmax_retard_delai_map,
                                     u16LocalCalcPara);
   u16LocalDecDly = MATHSRV_u16Interp1d(Av_bmax_decrem_delai_map,
                                        u16LocalCalcPara);
   for (u8LocalIdx = 0; u8LocalIdx < 4; u8LocalIdx++)
   {
      Av_bmax_retard_cptr_cyl[u8LocalIdx] = u16LocalDly;
      Av_bmax_decrem_cptr_cyl[u8LocalIdx] = u16LocalDecDly;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidCylAdaptation                                 */
/* !Description :  Le calcul des adaptatifs est lissé afin d'éviter une trop  */
/*                 grande dispersion entre cylindres. On autorise les         */
/*                 adaptations à varier dans une plage de largeur             */
/*                 Av_bmax_ecart_max.                                         */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKADPCOR_vidMajAvBmax();                                */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Regime_moteur_6_bkpt_map[6];                                  */
/*  input uint8 Av_bmax_ecart_max_T[6];                                       */
/*  input uint8 Av_bmax_ecart_max;                                            */
/*  input sint16 Av_bmax_adapt_avant_moy_cyl[4];                              */
/*  input sint16 Av_bmax_adapt_anti_k_cyl_prev[4];                            */
/*  input sint16 Av_bmax_adapt_avant_moy_k;                                   */
/*  input uint8 Knk_adapt_zone_fct_cyl[4];                                    */
/*  output uint8 Av_bmax_ecart_max;                                           */
/*  output sint16 Av_bmax_adapt_avant_moy_k;                                  */
/*  output sint16 Av_bmax_adapt_moyennee_cyl[4];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidCylAdaptation(void)
{
   /* 5_adaptation_cyl */
   uint8  u8LocalZone;
   uint8  u8LocalEng_noCmprNxtCyl;
   uint8  u8LocalRegime_moteur;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalCalcPara;
   uint16 u16LocalAvBmaxEcartMax;
   sint16 s16LocalAdapt_anti_k_cyl_prevMax;
   sint32 s32LocalDiff;
   sint32 s32LocalCorrAdvance;


   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalRegime_moteur = (uint16)(u16LocalRegime_moteur / 32);
   u8LocalRegime_moteur = (uint8)MATHSRV_udtMIN(u16LocalRegime_moteur, 255);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_6_bkpt_map,
                                                 u8LocalRegime_moteur,
                                                 6);
   Av_bmax_ecart_max = MATHSRV_u8Interp1d(Av_bmax_ecart_max_T,
                                           u16LocalCalcPara);
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmprNxtCyl = (uint8)(u8LocalEng_noCmprNxtCyl - 1);
         u16LocalAvBmaxEcartMax = (uint16)(Av_bmax_ecart_max * 128);
         /* Adaptatif calculé du cylindre en cours */
         Av_bmax_adapt_avant_moy_k =
            Av_bmax_adapt_avant_moy_cyl[u8LocalEng_noCmprNxtCyl];
         /* Calcul du plus grand des autres adaptatifs */
         s16LocalAdapt_anti_k_cyl_prevMax = -32768;
         for (u8LocalZone = 0; u8LocalZone < 4; u8LocalZone++)
         {
            if (u8LocalZone != u8LocalEng_noCmprNxtCyl)
            {
               s16LocalAdapt_anti_k_cyl_prevMax =
                  (sint16)MATHSRV_udtMAX(s16LocalAdapt_anti_k_cyl_prevMax,
                     Av_bmax_adapt_anti_k_cyl_prev[u8LocalZone]);
            }
         }
         /* Si l'adaptatif calculé est très inférieur au plus grand des autres
         adaptatifs: on ramène l'adaptation du cylindre en cours dans la plage
         de variation, quitte à dégrader l'avance plus que nécessaire.*/
         s32LocalDiff = s16LocalAdapt_anti_k_cyl_prevMax
                      - Av_bmax_adapt_avant_moy_k;
         if (s32LocalDiff > (sint32)u16LocalAvBmaxEcartMax)
         {
            for (u8LocalZone = 0 ; u8LocalZone < 4; u8LocalZone++)
            {
               if (u8LocalZone != u8LocalEng_noCmprNxtCyl)
               {
                  Av_bmax_adapt_moyennee_cyl[u8LocalZone] =
                     Av_bmax_adapt_anti_k_cyl_prev[u8LocalZone];
               }
               else
               {
                  s32LocalCorrAdvance =
                     (sint32)( s16LocalAdapt_anti_k_cyl_prevMax
                             - u16LocalAvBmaxEcartMax);
                  Av_bmax_adapt_moyennee_cyl[u8LocalZone] =
                     (sint16)s32LocalCorrAdvance;
               }
            }
         }
         else
         {
            /* Si l'adaptatif calculé est beaucoup plus grand (de plus de
            Av_bmax_ecart_max) que les autres adaptatifs: on ramène les autres
            adaptatifs dans la plage de variation. */
            for (u8LocalZone = 0 ; u8LocalZone < 4; u8LocalZone++)
            {
               if (u8LocalZone != u8LocalEng_noCmprNxtCyl)
               {
                  s32LocalDiff = Av_bmax_adapt_avant_moy_k
                               - Av_bmax_adapt_anti_k_cyl_prev[u8LocalZone];
                  if (s32LocalDiff > (sint32)u16LocalAvBmaxEcartMax)
                  {
                     s32LocalCorrAdvance = (sint32)( Av_bmax_adapt_avant_moy_k
                                                   - u16LocalAvBmaxEcartMax);
                     Av_bmax_adapt_moyennee_cyl[u8LocalZone] =
                        (sint16)s32LocalCorrAdvance;
                  }
                  else
                  {
                     /* Si l'adaptatif calculé se situe dans la plage de
                     variation autorisée: L'adaptatif n'est dans ce cas pas
                     modifié. */
                     Av_bmax_adapt_moyennee_cyl[u8LocalZone] =
                        Av_bmax_adapt_anti_k_cyl_prev[u8LocalZone];
                  }
               }
               else
               {
                  /* Il est préférable d'augmenter les autres adaptatifs (plutôt
                  que de diminuer l'adaptatif calculé) car cela peut anticiper
                  du cliquetis sur ces cylindres. */
                  Av_bmax_adapt_moyennee_cyl[u8LocalZone] =
                     Av_bmax_adapt_avant_moy_k;
               }
            }
         }

         if (Knk_adapt_zone_fct_cyl[u8LocalEng_noCmprNxtCyl] != 0)
         {
            /* 0_maj_av_bmax */
            KNKADPCOR_vidMajAvBmax();
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
/* !Function    :  KNKADPCOR_vidMajAvBmax                                     */
/* !Description :  Mise à jour du vecteur Av_bmax_adapt_anti_k_cylx           */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input uint8 Knk_adapt_zone_fct_cyl[4];                                    */
/*  input sint16 Av_bmax_adapt_moyennee_cyl[4];                               */
/*  input uint8 Ext_noCylEng;                                                 */
/*  output sint16 Av_bmax_adapt_anti_k_cyl1[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl2[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl3[15];                              */
/*  output sint16 Av_bmax_adapt_anti_k_cyl4[15];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidMajAvBmax(void)
{
   /* 0_maj_av_bmax */
   uint8  u8LocalZoneFunc;
   uint8  u8LocalIdx;
   uint8  u8LocalEng_noCmprNxtCyl;
   uint8  u8LocalExt_noCylEng;
   sint16 s16LocalMinAdvance;
   sint16 s16LocalAv_bmax_anti_k_cyl_1;
   sint16 s16LocalAv_bmax_anti_k_cyl_2;
   sint16 s16LocalAv_bmax_anti_k_cyl_3;
   sint16 s16LocalAv_bmax_anti_k_cyl_4;


   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalZoneFunc =
            Knk_adapt_zone_fct_cyl[u8LocalEng_noCmprNxtCyl - 1];
         if (  (u8LocalZoneFunc > 0)
            && (u8LocalZoneFunc <= 15))
         {
            u8LocalZoneFunc = (uint8)(u8LocalZoneFunc - 1);

            s16LocalAv_bmax_anti_k_cyl_1 = Av_bmax_adapt_moyennee_cyl[0];
            s16LocalAv_bmax_anti_k_cyl_2 = Av_bmax_adapt_moyennee_cyl[1];
            s16LocalAv_bmax_anti_k_cyl_3 = Av_bmax_adapt_moyennee_cyl[2];
            VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl1,
                                      u8LocalZoneFunc,
                                      s16LocalAv_bmax_anti_k_cyl_1);
            VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl2,
                                      u8LocalZoneFunc,
                                      s16LocalAv_bmax_anti_k_cyl_2);
            VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl3,
                                      u8LocalZoneFunc,
                                      s16LocalAv_bmax_anti_k_cyl_3);
            VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
            if (u8LocalExt_noCylEng != 4)
            {
               s16LocalMinAdvance = Av_bmax_adapt_moyennee_cyl[0];
               for (u8LocalIdx = 1 ; u8LocalIdx < 3 ; u8LocalIdx ++)
               {
                  s16LocalMinAdvance =
                     (sint16)MATHSRV_udtMIN(s16LocalMinAdvance,
                        Av_bmax_adapt_moyennee_cyl[u8LocalIdx]);
               }
               s16LocalAv_bmax_anti_k_cyl_4 = s16LocalMinAdvance;
            }
            else
            {
               s16LocalAv_bmax_anti_k_cyl_4 = Av_bmax_adapt_moyennee_cyl[3];
            }
            VEMS_vidSET1DArrayElement(Av_bmax_adapt_anti_k_cyl4,
                                      u8LocalZoneFunc,
                                      s16LocalAv_bmax_anti_k_cyl_4);
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
/* !Function    :  KNKADPCOR_vidAntiKnockPrevention                           */
/* !Description :  La correction de limite max n'est appliquée que dans la    */
/*                 zone critique, où un risque de cliquetis existe. En cas de */
/*                 panne de la fonction anti-cliquetis, on applique une       */
/*                 correction préventive                                      */
/*                 forfaitaire(Av_bmax_corr_adapt_defaut_anti_k).             */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void KNKADPCOR_vidCalcAvBmaxMoyen();                          */
/*  input boolean Bv_changement_rapport;                                      */
/*  input boolean Bvmp_inh_cliq_acquisition;                                  */
/*  input boolean Presence_bva;                                               */
/*  input boolean Zone_critique;                                              */
/*  input uint8 Av_bmax_corr_adapt_defaut_anti_k;                             */
/*  input sint16 Av_bmax_adapt_anti_k_zone_cyl[4];                            */
/*  input uint8 Knk_adapt_zone_fct;                                           */
/*  output sint8 Av_bmax_cor_adpt_anti_k_raw_cyl[4];                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidAntiKnockPrevention(void)
{
   /* 8_calc_av_bmax_adapt_anti_k_raw */
   boolean bLocalBv_changement_rapport;
   boolean bLocalBvmp_inh_cliq_acquisition;
   boolean bLocalPresence_bva;
   boolean bLocalZone_critique;
   boolean bLocalFRM_bAcvAdpDftCor;
   uint8   u8LocalIdx;
   sint16  s16LocalAv_adapt_anti_k_zone_cyl;


   VEMS_vidGET(Bv_changement_rapport, bLocalBv_changement_rapport);
   VEMS_vidGET(Bvmp_inh_cliq_acquisition, bLocalBvmp_inh_cliq_acquisition);
   VEMS_vidGET(Presence_bva, bLocalPresence_bva);
   if (  (bLocalBvmp_inh_cliq_acquisition == 0)
      && (  (bLocalBv_changement_rapport == 0)
         || (bLocalPresence_bva == 0)))
   {
      VEMS_vidGET(Zone_critique, bLocalZone_critique);
      if (bLocalZone_critique != 0)
      {
         bLocalFRM_bAcvAdpDftCor = GDGAR_bGetFRM(FRM_FRM_ACVADPDFTCOR);
         if (bLocalFRM_bAcvAdpDftCor != 0)
         {
            for (u8LocalIdx = 0; u8LocalIdx < 4; u8LocalIdx++)
            {
               Av_bmax_cor_adpt_anti_k_raw_cyl[u8LocalIdx] =
                  (sint8)(Av_bmax_corr_adapt_defaut_anti_k / 4);
            }
         }
         else
         {
            for (u8LocalIdx = 0; u8LocalIdx < 4; u8LocalIdx++)
            {
               VEMS_vidGET1DArrayElement(Av_bmax_adapt_anti_k_zone_cyl,
                                         u8LocalIdx,
                                         s16LocalAv_adapt_anti_k_zone_cyl);
               Av_bmax_cor_adpt_anti_k_raw_cyl[u8LocalIdx] =
                  (sint8)(s16LocalAv_adapt_anti_k_zone_cyl / 512);
            }
         }
      }
      else
      {
         for (u8LocalIdx = 0; u8LocalIdx < 4; u8LocalIdx++)
         {
            Av_bmax_cor_adpt_anti_k_raw_cyl[u8LocalIdx] = 0;
         }
      }
   }

   if (Knk_adapt_zone_fct != 0)
   {
      /* 0_calcul_av_bmax_moyen */
      KNKADPCOR_vidCalcAvBmaxMoyen();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidCalcAvBmaxMoyen                               */
/* !Description :  Calcul av bmax moyen.                                      */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Knk_adapt_zone_fct;                                           */
/*  input sint8 Av_bmax_cor_adpt_anti_k_raw_cyl[4];                           */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input sint8 Av_bmax_corr_adapt_anti_k_cyl4[15];                           */
/*  input sint8 Av_bmax_corr_adapt_anti_k_cyl1[15];                           */
/*  input sint8 Av_bmax_corr_adapt_anti_k_cyl2[15];                           */
/*  input sint8 Av_bmax_corr_adapt_anti_k_cyl3[15];                           */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl1[15];                          */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl2[15];                          */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl3[15];                          */
/*  output sint8 Av_bmax_corr_adapt_anti_k_cyl4[15];                          */
/*  output sint8 Av_bmax_corr_adapt_anti_k[15];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidCalcAvBmaxMoyen(void)
{
   /* 0_calcul_av_bmax_moyen */
   uint8  u8LocalExt_noCylEng;
   uint8  u8LocalZoneFunc;
   sint8  s8LocalAdvCyl4;
   sint8  s8LocalAv_bmax_corr_adapt_anti_k;
   sint16 s16LocalAdvance;


   if (  (Knk_adapt_zone_fct > 0)
      && (Knk_adapt_zone_fct <= 15))
   {
      u8LocalZoneFunc = (uint8)(Knk_adapt_zone_fct - 1);
      Av_bmax_corr_adapt_anti_k_cyl1[u8LocalZoneFunc] =
         (sint8)MATHSRV_udtCLAMP(Av_bmax_cor_adpt_anti_k_raw_cyl[0], -64, 63);
      Av_bmax_corr_adapt_anti_k_cyl2[u8LocalZoneFunc] =
         (sint8)MATHSRV_udtCLAMP(Av_bmax_cor_adpt_anti_k_raw_cyl[1], -64, 63);
      Av_bmax_corr_adapt_anti_k_cyl3[u8LocalZoneFunc] =
         (sint8)MATHSRV_udtCLAMP(Av_bmax_cor_adpt_anti_k_raw_cyl[2], -64, 63);
      Av_bmax_corr_adapt_anti_k_cyl4[u8LocalZoneFunc] =
         (sint8)MATHSRV_udtCLAMP(Av_bmax_cor_adpt_anti_k_raw_cyl[3], -64, 63);

      VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);

      if (  (u8LocalExt_noCylEng != 0)
         && (u8LocalExt_noCylEng <= 12))
      {
         if (u8LocalExt_noCylEng != 4)
         {
            s8LocalAdvCyl4 = 0;
         }
         else
         {
            s8LocalAdvCyl4 = Av_bmax_corr_adapt_anti_k_cyl4[u8LocalZoneFunc];
         }

         s16LocalAdvance =
            (sint16)( Av_bmax_corr_adapt_anti_k_cyl1[u8LocalZoneFunc]
                    + Av_bmax_corr_adapt_anti_k_cyl2[u8LocalZoneFunc]
                    + Av_bmax_corr_adapt_anti_k_cyl3[u8LocalZoneFunc]
                    + s8LocalAdvCyl4);
         s16LocalAdvance = (sint16)(s16LocalAdvance / u8LocalExt_noCylEng);
         s8LocalAv_bmax_corr_adapt_anti_k =
            (sint8)MATHSRV_udtCLAMP(s16LocalAdvance, -64, 63);
         VEMS_vidSET1DArrayElement(Av_bmax_corr_adapt_anti_k,
                                   u8LocalZoneFunc,
                                   s8LocalAv_bmax_corr_adapt_anti_k);
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKADPCOR_vidFiltering                                     */
/* !Description :  Cette fonction permet de prendre en compte les transitions */
/*                 sur la zone de fonctionnement et la zone critique pour     */
/*                 lesquelles de nouveaux adaptatifs sont appliqués. Cette    */
/*                 fonction effectue un filtrage sur la sortie lors de ces    */
/*                 transitions.                                               */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input boolean Zone_critique;                                              */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input boolean Bvmp_inh_cliq_acquisition;                                  */
/*  input sint8 Av_bmax_corr_appliquee_cyl[4];                                */
/*  input sint8 Av_bmax_cor_adpt_anti_k_raw_cyl[4];                           */
/*  input sint16 KnkAdpCor_agActAvmaxFineResl;                                */
/*  input sint16 KnkAdpCor_agRawAvmaxFineResl;                                */
/*  input boolean KNKADPCOR_bZone_critiquePrev;                               */
/*  input boolean KNKADPCOR_bBvmp_inh_cliqacqPrev;                            */
/*  input uint8 KNKADPCOR_u8KnkAdaptZoneCylPrev[4];                           */
/*  input uint8 Knk_adapt_zone_fct_cyl[4];                                    */
/*  input uint8 KnkAdpCor_agActRawDeltaThd_C;                                 */
/*  input boolean KnkAdpCor_bTreatZoneTran[4];                                */
/*  input sint16 KnkMgt_agIgKnkAdpOfsCylFineRsl[4];                           */
/*  input uint8 Av_bmax_corr_decal_pas_inc;                                   */
/*  input uint8 Av_bmax_corr_decal_pas_dec;                                   */
/*  output sint16 KnkAdpCor_agActAvmaxFineResl;                               */
/*  output sint16 KnkAdpCor_agRawAvmaxFineResl;                               */
/*  output boolean KnkAdpCor_bTreatZoneTran[4];                               */
/*  output sint8 Av_bmax_corr_appliquee_cyl[4];                               */
/*  output sint16 KnkMgt_agIgKnkAdpOfsCylFineRsl[4];                          */
/*  output uint8 KnkMgt_prm_agIgKnkAdpOfsCyl[6];                              */
/*  output boolean KNKADPCOR_bZone_critiquePrev;                              */
/*  output boolean KNKADPCOR_bBvmp_inh_cliqacqPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKADPCOR_vidFiltering(void)
{
   /* 9_filtrage */
   boolean bLocalZone_critique;
   boolean bLocalBvmp_inh_cliq_acquisition;
   uint8   u8LocalEng_noCmprNxtCyl;
   uint8   u8LocalIdx;
   uint8   au8LocalAgIgKnkAdpOfsCyl[KNKADPCOR_u32ADP_ARRAY_LENGTH];
   sint8   as8LocalAv_bmax_corr_appl_cyl[KNKADPCOR_u32ADV_ARRAY_LENGTH];
   sint8   s8LocalCalc;
   uint16  u16LocaldiffAbs;
   sint16  s16LocalCalc;
   sint16  s16Localdiff;
   sint16  s16LocalOUPUT_MEM;
   sint16  s16LocalSwitchOut;
   sint16  s16LocalKnkAdpCormaxFineResl;


   VEMS_vidGET(Zone_critique, bLocalZone_critique);
   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);
   VEMS_vidGET(Bvmp_inh_cliq_acquisition, bLocalBvmp_inh_cliq_acquisition);
   VEMS_vidGET1DArray(Av_bmax_corr_appliquee_cyl,
                      KNKADPCOR_u32ADV_ARRAY_LENGTH,
                      as8LocalAv_bmax_corr_appl_cyl);
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         s16LocalKnkAdpCormaxFineResl = (sint16)(4 *
            as8LocalAv_bmax_corr_appl_cyl[u8LocalEng_noCmprNxtCyl - 1]);
         KnkAdpCor_agActAvmaxFineResl =
            (sint16)MATHSRV_udtCLAMP(s16LocalKnkAdpCormaxFineResl, -256, 255);
         s16LocalKnkAdpCormaxFineResl = (sint16)(4 *
            Av_bmax_cor_adpt_anti_k_raw_cyl[u8LocalEng_noCmprNxtCyl - 1]);
         KnkAdpCor_agRawAvmaxFineResl =
            (sint16)MATHSRV_udtCLAMP(s16LocalKnkAdpCormaxFineResl, -256, 255);
         s16Localdiff = (sint16)(KnkAdpCor_agActAvmaxFineResl -
            KnkAdpCor_agRawAvmaxFineResl);
         u16LocaldiffAbs = (uint16)MATHSRV_udtABS(s16Localdiff);

         if (  (bLocalZone_critique != KNKADPCOR_bZone_critiquePrev)
            || (  (KNKADPCOR_bBvmp_inh_cliqacqPrev != 0)
               && (bLocalBvmp_inh_cliq_acquisition == 0)))
         {
            for (u8LocalIdx = 0; u8LocalIdx < 4; u8LocalIdx++)
            {
               KnkAdpCor_bTreatZoneTran[u8LocalIdx] = 0;
            }
         }
         else
         {
            if (KNKADPCOR_u8KnkAdaptZoneCylPrev[u8LocalEng_noCmprNxtCyl - 1] !=
                Knk_adapt_zone_fct_cyl[u8LocalEng_noCmprNxtCyl - 1])
            {
               KnkAdpCor_bTreatZoneTran[u8LocalEng_noCmprNxtCyl - 1] = 0;
            }
            else
            {
               if (u16LocaldiffAbs <= KnkAdpCor_agActRawDeltaThd_C)
               {
                  KnkAdpCor_bTreatZoneTran[u8LocalEng_noCmprNxtCyl - 1]  = 1;
               }
            }
         }
         if (KnkAdpCor_bTreatZoneTran[u8LocalEng_noCmprNxtCyl - 1] != 0)
         {
            s16LocalSwitchOut = KnkAdpCor_agRawAvmaxFineResl;
         }
         else
         {
            s16LocalOUPUT_MEM =
               KnkMgt_agIgKnkAdpOfsCylFineRsl[u8LocalEng_noCmprNxtCyl - 1];
            s16LocalSwitchOut =
               MATHSRV_s16SlewFilter(s16LocalOUPUT_MEM,
                                     KnkAdpCor_agRawAvmaxFineResl,
                                    (uint16)Av_bmax_corr_decal_pas_inc,
                                    (uint16)Av_bmax_corr_decal_pas_dec);
         }
         if (s16LocalSwitchOut < 0)
         {
            s16LocalCalc = (sint16)((s16LocalSwitchOut - 2) / 4);
         }
         else
         {
            s16LocalCalc = (sint16)((s16LocalSwitchOut + 2) / 4);
         }
         s8LocalCalc = (sint8)MATHSRV_udtCLAMP(s16LocalCalc, -64, 63);
         VEMS_vidSET1DArrayElement(Av_bmax_corr_appliquee_cyl,
                                   u8LocalEng_noCmprNxtCyl - 1,
                                   s8LocalCalc);
         KnkMgt_agIgKnkAdpOfsCylFineRsl[u8LocalEng_noCmprNxtCyl - 1] =
            (sint16)MATHSRV_udtCLAMP(s16LocalSwitchOut, -256, 255);
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   VEMS_vidGET1DArray(Av_bmax_corr_appliquee_cyl,
                      KNKADPCOR_u32ADV_ARRAY_LENGTH,
                      as8LocalAv_bmax_corr_appl_cyl);
   for (u8LocalIdx = 0; u8LocalIdx < 4; u8LocalIdx++)
   {
      au8LocalAgIgKnkAdpOfsCyl[u8LocalIdx] =
         (uint8)(as8LocalAv_bmax_corr_appl_cyl[u8LocalIdx] + 96);
   }
   au8LocalAgIgKnkAdpOfsCyl[4] = 96;
   au8LocalAgIgKnkAdpOfsCyl[5] = 96;

   VEMS_vidSET1DArray(KnkMgt_prm_agIgKnkAdpOfsCyl,
                      KNKADPCOR_u32ADP_ARRAY_LENGTH,
                      au8LocalAgIgKnkAdpOfsCyl);

   KNKADPCOR_bZone_critiquePrev = bLocalZone_critique;
   KNKADPCOR_bBvmp_inh_cliqacqPrev = bLocalBvmp_inh_cliq_acquisition;

}
/*---------------------------- end of file -----------------------------------*/
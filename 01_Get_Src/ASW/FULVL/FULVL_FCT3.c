/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FULVL                                                   */
/* !Description     : FULVL component.                                        */
/*                                                                            */
/* !Module          : FULVL                                                   */
/* !Description     : GESTION DU NIVEAU CARBURANT                             */
/*                                                                            */
/* !File            : FULVL_FCT3.C                                            */
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
/*   1 / FULVL_vidNoFaultMeasure                                              */
/*   2 / FULVL_vidFailureInv                                                  */
/*   3 / FULVL_vidFailureScg                                                  */
/*   4 / FULVL_vidFailureOc                                                   */
/*   5 / FULVL_vidFuelLevelIncCpteDem                                         */
/*   6 / FULVL_vidLvlIncCaleRunning                                           */
/*   7 / FULVL_vidFuelIncComputeRunning                                       */
/*   8 / FULVL_vidDetectionRunningEngine                                      */
/*   9 / FULVL_vidFuelLevelCaleOrOff                                          */
/*   10 / FULVL_vidFuelLevelSt                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5462804 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#049911                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/FULVL/FULVL_FCT3.C_v         $*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   20 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   20 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "FULVL.h"
#include "FULVL_L.h"
#include "FULVL_IM.h"
#include "GDGAR.h"
#include "VEMS.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidNoFaultMeasure                                    */
/* !Description :  Fonction qui met tous les indicateurs d'état jauge à 0.    */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Fu_bDgoOc_FuGauge;                                         */
/*  output boolean Fu_bDgoScg_FuGauge;                                        */
/*  output boolean Fu_bDgoORng_FuGauge;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidNoFaultMeasure(void)
{
   /*FuLvl/FuLvl/2_Fuel_gauge_state/1_Fuel_gauge_state/1_Aucun_defaut_jauge*/
   Fu_bDgoOc_FuGauge = 0;
   Fu_bDgoScg_FuGauge = 0;
   Fu_bDgoORng_FuGauge = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFailureInv                                        */
/* !Description :  Fonction qui met Fu_bDgoORng_FuGauge à 1.                  */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Fu_bDgoOc_FuGauge;                                         */
/*  output boolean Fu_bDgoScg_FuGauge;                                        */
/*  output boolean Fu_bDgoORng_FuGauge;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFailureInv(void)
{
   /*FuLvl/FuLvl/2_Fuel_gauge_state/1_Fuel_gauge_state/2_panne_inv*/
   Fu_bDgoOc_FuGauge = 0;
   Fu_bDgoScg_FuGauge = 0;
   Fu_bDgoORng_FuGauge = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFailureScg                                        */
/* !Description :  Fonction qui met Fu_bDgoScg_FuGauge à 1.                   */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Fu_bDgoOc_FuGauge;                                         */
/*  output boolean Fu_bDgoScg_FuGauge;                                        */
/*  output boolean Fu_bDgoORng_FuGauge;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFailureScg(void)
{
   /*FuLvl/FuLvl/2_Fuel_gauge_state/1_Fuel_gauge_state/3_panne_Scg*/
   Fu_bDgoOc_FuGauge = 0;
   Fu_bDgoScg_FuGauge = 1;
   Fu_bDgoORng_FuGauge = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFailureOc                                         */
/* !Description :  Fonction qui met Fu_bDgoOc_FuGauge à 1.                    */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Fu_bDgoOc_FuGauge;                                         */
/*  output boolean Fu_bDgoScg_FuGauge;                                        */
/*  output boolean Fu_bDgoORng_FuGauge;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFailureOc(void)
{
   /*FuLvl/FuLvl/2_Fuel_gauge_state/1_Fuel_gauge_state/4_panne_Oc*/
   Fu_bDgoOc_FuGauge = 1;
   Fu_bDgoScg_FuGauge = 0;
   Fu_bDgoORng_FuGauge = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFuelLevelIncCpteDem                               */
/* !Description :  Lorsque l’information niveau carburant est disponible      */
/*                 (Flev_fuel_level_count = 0), on calcule le remplissage du  */
/*                 réservoir par rapport au dernier réveil.                   */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Flev_fuel_level_mux;                                          */
/*  input uint8 Flev_fuel_level_in_eep;                                       */
/*  input uint8 Flev_fuel_level_delta;                                        */
/*  input uint8 Flev_fuel_level_inc_thresh;                                   */
/*  input boolean Moteur_tournant;                                            */
/*  input boolean Flev_fuel_level_increase;                                   */
/*  output uint8 Flev_fuel_level_filtered_ref;                                */
/*  output uint8 Flev_fuel_level_delta;                                       */
/*  output boolean Flev_fuel_level_increase;                                  */
/*  output boolean Flev_fuel_level_inc_next;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelLevelIncCpteDem(void)
{
   boolean bLocalInhFuLvlIncDet;
   boolean bLocalMoteur_tournant;
   boolean bLocalFlevFuelLevelIncrease;
   uint8   u8LocalFlevFuelLevCalc;
   uint8   u8LocalFlev_fuel_level_mux;
   sint16  s16LocalFlevFuelLevCalc;

   /*FuLvl/FuLvl/4_Fuel_level/3_Fuel_level_inc_compute_dem/
                                                  1_Fuel_level_inc_compute_dem*/
   VEMS_vidGET(Flev_fuel_level_mux, u8LocalFlev_fuel_level_mux);
   Flev_fuel_level_filtered_ref = u8LocalFlev_fuel_level_mux;

   bLocalInhFuLvlIncDet = GDGAR_bGetFRM(FRM_FRM_INHFULVLINCDET);
   if (Flev_fuel_level_in_eep != 0)
   {
      u8LocalFlevFuelLevCalc =
            (uint8)MATHSRV_udtMIN(u8LocalFlev_fuel_level_mux, 253);
      /* Scaling */
      s16LocalFlevFuelLevCalc =
            (sint16)(u8LocalFlevFuelLevCalc - Flev_fuel_level_in_eep);
      s16LocalFlevFuelLevCalc =
            (sint16)(s16LocalFlevFuelLevCalc * 128);
      s16LocalFlevFuelLevCalc =
         (sint16)(s16LocalFlevFuelLevCalc / Flev_fuel_level_in_eep);
      /* affichage en 200% */
      Flev_fuel_level_delta =
            (uint8)MATHSRV_udtCLAMP(s16LocalFlevFuelLevCalc, 0, 255);
   }
   else
   {
      Flev_fuel_level_delta = 255;
   }

   if (  (bLocalInhFuLvlIncDet == 0)
      && (Flev_fuel_level_in_eep <= 253) )
   {
      if (Flev_fuel_level_delta > Flev_fuel_level_inc_thresh)
      {
         VEMS_vidSET(Flev_fuel_level_increase, 1);
      }
      else
      {
         VEMS_vidSET(Flev_fuel_level_increase, 0);
      }
   }
   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   VEMS_vidGET(Flev_fuel_level_increase, bLocalFlevFuelLevelIncrease);
   if (  (bLocalFlevFuelLevelIncrease != 0)
      && (bLocalMoteur_tournant != 0)
      && (Flev_fuel_level_in_eep <= 253) )
   {
      Flev_fuel_level_inc_next = 1;
   }else
   {
      Flev_fuel_level_inc_next = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidLvlIncCaleRunning                                 */
/* !Description :  Fonction dui permet le calcul du niveau carburant après    */
/*                 calage ou clé à OFF (Flev_last_stall_or_key_off = 1).      */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Flev_fuel_level;                                              */
/*  input uint16 Flev_fuel_level_ref;                                         */
/*  input uint8 Flev_fuel_level_delta;                                        */
/*  input uint8 Flev_fuel_level_inc_thresh;                                   */
/*  input boolean Flev_fuel_level_inc_next;                                   */
/*  input boolean Moteur_tournant;                                            */
/*  input boolean Flev_fuel_level_increase;                                   */
/*  input uint8 Flev_fuel_level_in_eep;                                       */
/*  output uint8 Flev_fuel_level_filtered_ref;                                */
/*  output uint8 Flev_fuel_level_delta;                                       */
/*  output boolean Flev_fuel_level_increase;                                  */
/*  output boolean Flev_fuel_level_inc_next;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidLvlIncCaleRunning(void)
{
   boolean bLocalInhFuLvlIncDet;
   boolean bLocalMoteur_tournant;
   boolean bLocalFlev_fuel_level_increase;
   uint8   u8LocalFlev_fuel_level;
   sint32  s32LocalFlevFuelLevCalc;


   /*FuLvl/FuLvl/4_Fuel_level/4_Fuel_level_inc_compute_cale_tournant/
                                        1_Fuel_level_inc_compute_cale_tournant*/
   VEMS_vidGET(Flev_fuel_level, u8LocalFlev_fuel_level);
   Flev_fuel_level_filtered_ref = u8LocalFlev_fuel_level;

   bLocalInhFuLvlIncDet = GDGAR_bGetFRM(FRM_FRM_INHFULVLINCDET);
   if (Flev_fuel_level_ref != 0)
   {
      u8LocalFlev_fuel_level =
         (uint8)MATHSRV_udtMIN(u8LocalFlev_fuel_level, 253);

      s32LocalFlevFuelLevCalc = (sint32)(u8LocalFlev_fuel_level * 256);
      s32LocalFlevFuelLevCalc =
         s32LocalFlevFuelLevCalc - Flev_fuel_level_ref;
      s32LocalFlevFuelLevCalc = s32LocalFlevFuelLevCalc * 128;
      s32LocalFlevFuelLevCalc =
         s32LocalFlevFuelLevCalc / Flev_fuel_level_ref;
      /* affichage en 200% */
      Flev_fuel_level_delta =
            (uint8)MATHSRV_udtCLAMP(s32LocalFlevFuelLevCalc, 0, 255);
   }
   else
   {
      Flev_fuel_level_delta = 255;
   }

   if (  (bLocalInhFuLvlIncDet == 0)
      && (Flev_fuel_level_ref <= 64768) )
   {
      if (Flev_fuel_level_delta > Flev_fuel_level_inc_thresh)
      {
         VEMS_vidSET(Flev_fuel_level_increase, 1);
      }
      else
      {
         VEMS_vidSET(Flev_fuel_level_increase, 0);
      }
   }
   if (Flev_fuel_level_inc_next == 0)
   {
      VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
      VEMS_vidGET(Flev_fuel_level_increase, bLocalFlev_fuel_level_increase);
      if (  (bLocalFlev_fuel_level_increase != 0)
         && (bLocalMoteur_tournant != 0)
         && (Flev_fuel_level_in_eep <= 253) )
      {
         Flev_fuel_level_inc_next = 1;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFuelIncComputeRunning                             */
/* !Description :  Lorsque l’information niveau carburant est disponible      */
/*                 (Flev_fuel_level_count = 0), on détermine la détection de  */
/*                 remplissage du réservoir par rapport au niveau de carburant*/
/*                 mémorisé à l’initialisation du compteur de temps précédent.*/
/* !Number      :  FCT3.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FULVL_vidDetectionRunningEngine();                       */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean FULVL_bFlevFuelLevelThrshPrev;                              */
/*  input uint8 Flev_fuel_level;                                              */
/*  input uint8 Flev_fuel_level_last;                                         */
/*  input uint8 Flev_fuel_level_inc_run_thresh;                               */
/*  input boolean Flev_fuel_level_increase;                                   */
/*  input boolean Flev_fuel_level_inc_next;                                   */
/*  output uint8 Flev_fuel_level_last;                                        */
/*  output boolean FULVL_bFlevFuelLevelThrshPrev;                             */
/*  output boolean Flev_fuel_level_increase;                                  */
/*  output boolean Flev_fuel_level_inc_next;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelIncComputeRunning(void)
{
   boolean bLocalFlevFuelLevelThrshPrev;
   boolean bLocalInhFuLvlIncDet;
   boolean bLocalFlev_fuel_level_increase;
   uint8   u8LocalFlevFuelLevCalc;
   uint8   u8LocalFlev_fuel_level;
   sint32  s32LocalFlevFuelLevCalc;

   /*FuLvl/FuLvl/4_Fuel_level/6_Fuel_level_inc_compute_tournant/
                                             1_Fuel_level_inc_compute_tournant*/
   bLocalFlevFuelLevelThrshPrev = FULVL_bFlevFuelLevelThrshPrev;
   VEMS_vidGET(Flev_fuel_level, u8LocalFlev_fuel_level);
   u8LocalFlevFuelLevCalc = (uint8)MATHSRV_udtMIN(u8LocalFlev_fuel_level, 253);
   s32LocalFlevFuelLevCalc = u8LocalFlevFuelLevCalc - Flev_fuel_level_last;
   Flev_fuel_level_last = u8LocalFlev_fuel_level;

   if (s32LocalFlevFuelLevCalc > Flev_fuel_level_inc_run_thresh)
   {
      FULVL_bFlevFuelLevelThrshPrev = 1;
   }
   else
   {
      FULVL_bFlevFuelLevelThrshPrev = 0;
   }
   if (  (bLocalFlevFuelLevelThrshPrev == 0)
      && (FULVL_bFlevFuelLevelThrshPrev != 0) )
   {
      FULVL_vidDetectionRunningEngine();
   }
   bLocalInhFuLvlIncDet = GDGAR_bGetFRM(FRM_FRM_INHFULVLINCDET);
   VEMS_vidGET(Flev_fuel_level_increase, bLocalFlev_fuel_level_increase);
   if (  (bLocalInhFuLvlIncDet == 0)
      && (u8LocalFlev_fuel_level <= 253) )
   {
      bLocalFlev_fuel_level_increase = FULVL_bFlevFuelLevelThrshPrev;
   }
   VEMS_vidSET(Flev_fuel_level_increase, bLocalFlev_fuel_level_increase);
   if (Flev_fuel_level_inc_next == 0)
   {
      Flev_fuel_level_inc_next = bLocalFlev_fuel_level_increase;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidDetectionRunningEngine                            */
/* !Description :  Fonction qui permet de détecter moteur tournant.           */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Flev_fuel_level_inc_running;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidDetectionRunningEngine(void)
{
   /*FuLvl/FuLvl/4_Fuel_level/6_Fuel_level_inc_compute_tournant/
                 1_Fuel_level_inc_compute_tournant/1_Detection_moteur_tournant*/
   Flev_fuel_level_inc_running = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFuelLevelCaleOrOff                                */
/* !Description :  Fonction de calcul du niveau de carburant de référence sur */
/*                 événement cale tournant ou clé à OFF.                      */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Flev_fuel_level;                                              */
/*  output uint16 Flev_fuel_level_ref;                                        */
/*  output boolean Flev_last_stall_or_key_off;                                */
/*  output boolean Flev_fuel_level_increase;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelLevelCaleOrOff(void)
{
   uint8 u8LocalFlev_fuel_level;


   /*FuLvl/FuLvl/6_Fuel_level_compute_cale_or_off/
                                              1_Fuel_level_compute_cale_or_off*/
   VEMS_vidGET(Flev_fuel_level, u8LocalFlev_fuel_level);
   Flev_fuel_level_ref = (uint16)(u8LocalFlev_fuel_level * 256);
   Flev_last_stall_or_key_off = 1;
   VEMS_vidSET(Flev_fuel_level_increase, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFuelLevelSt                                       */
/* !Description :  Un diagnostic fonctionnel du niveau de carburant est       */
/*                 effectué par rapport à la consommation carburant. Ce       */
/*                 diagnostic est inhibé si un remplissage moteur tournant a  */
/*                 été détecté.                                               */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Consommation_carburant_totale;                               */
/*  input uint32 Conso_carbu_totale_ref;                                      */
/*  input uint8 Flev_fuel_level;                                              */
/*  input uint8 Flev_fuel_level_filtered_ref;                                 */
/*  input uint8 Fuel_level_state_max;                                         */
/*  input uint8 Fuel_level_state_min;                                         */
/*  output boolean Fu_bDgoORng_FuGaugeLvl;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelLevelSt(void)
{
   uint8  u8LocalFlev_fuel_level;
   sint16 s16LocalCompValue;
   uint32 u32LocalDeltaCons;
   uint32 u32LocalConsommationCarburantTot;
   uint32 u32LocalFuelLevelStateMax;
   uint32 u32LocalFuelLevelStateMin;
   sint32 s32LocalCompValue;

   /*FuLvl/FuLvl/5_Fuel_level_state/1_Fuel_level_state*/
   VEMS_vidGET(Consommation_carburant_totale, u32LocalConsommationCarburantTot);
   if (u32LocalConsommationCarburantTot > Conso_carbu_totale_ref)
   {
      u32LocalDeltaCons = u32LocalConsommationCarburantTot
                        - Conso_carbu_totale_ref;
      VEMS_vidGET(Flev_fuel_level, u8LocalFlev_fuel_level);
      s16LocalCompValue = (sint16)( Flev_fuel_level_filtered_ref
                                  - u8LocalFlev_fuel_level);
      s32LocalCompValue = (sint32)(s16LocalCompValue * 16000);
      u32LocalDeltaCons = u32LocalDeltaCons / 10000000;
   }
   else
   {
      s32LocalCompValue = 10;
      u32LocalDeltaCons = 256;
   }
   u32LocalFuelLevelStateMax = u32LocalDeltaCons * Fuel_level_state_max;
   u32LocalFuelLevelStateMin = u32LocalDeltaCons * Fuel_level_state_min;

   if (s32LocalCompValue < 0)
   {
      Fu_bDgoORng_FuGaugeLvl = 1;
   }
   else
   {
      if (  ((uint32)s32LocalCompValue < u32LocalFuelLevelStateMax)
         && ((uint32)s32LocalCompValue > u32LocalFuelLevelStateMin))
      {
         Fu_bDgoORng_FuGaugeLvl = 0;
      }
      else
      {
         Fu_bDgoORng_FuGaugeLvl = 1;
      }
   }
}
/*------------------------------- end of file --------------------------------*/
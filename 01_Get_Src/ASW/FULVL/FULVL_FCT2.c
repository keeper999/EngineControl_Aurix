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
/* !File            : FULVL_FCT2.C                                            */
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
/*   1 / FULVL_vidFuelGaugeSt                                                 */
/*   2 / FULVL_vidTemporisation                                               */
/*   3 / FULVL_vidFuelLevel                                                   */
/*   4 / FULVL_vidFilteringInfoMux                                            */
/*   5 / FULVL_vidFuelLevelCompute                                            */
/*   6 / FULVL_vidFuelLevelIncComputeDem                                      */
/*   7 / FULVL_vidLvlIncCpeCaleRunning                                        */
/*   8 / FULVL_vidRunningCounter                                              */
/*   9 / FULVL_vidFuelLevelIncRunning                                         */
/*   10 / FULVL_vidInitEngineRunning                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5462804 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#049911                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/FULVL/FULVL_FCT2.C_v         $*/
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
/* !Function    :  FULVL_vidFuelGaugeSt                                       */
/* !Description :  Fonction qui permet de donner l'Etat de la jauge à         */
/*                 carburant(CC, CO, donnée invalide).                        */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FULVL_vidFailureInv();                                   */
/*  extf argret void FULVL_vidFailureScg();                                   */
/*  extf argret void FULVL_vidFailureOc();                                    */
/*  extf argret void FULVL_vidNoFaultMeasure();                               */
/*  input uint8 Fuel_gauge_diag_mux;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelGaugeSt(void)
{
   uint8 u8LocalMaskedFuelGaugeDiagMux;
   uint8 u8LocalFuel_gauge_diag_mux;


   /*FuLvl/FuLvl/2_Fuel_gauge_state/1_Fuel_gauge_state*/

   VEMS_vidGET(Fuel_gauge_diag_mux, u8LocalFuel_gauge_diag_mux);
   u8LocalMaskedFuelGaugeDiagMux = (uint8)(u8LocalFuel_gauge_diag_mux & 0x03);
   switch (u8LocalMaskedFuelGaugeDiagMux)
   {
      case 1:
         FULVL_vidFailureInv();
      break;
      case 2:
         FULVL_vidFailureScg();
      break;
      case 3:
         FULVL_vidFailureOc();
      break;
      default:
         FULVL_vidNoFaultMeasure();
      break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidTemporisation                                     */
/* !Description :  Fonction qui gère une temporisation                        */
/*                 (Flev_low_fuel_level_sw_tempo) correspondant au temps      */
/*                 maximum observé sur véhicule entre l’apparition d’un défaut*/
/*                 du système d’alimentation en carburant ou un manque de     */
/*                 carburant dans le réservoir et le calage du moteur         */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Afa_panne_presente_adapt_inj;                               */
/*  input uint16 Flev_low_level_sw_inj_counter;                               */
/*  input boolean FULVL_bFlevLowFuelInjInitPrev;                              */
/*  input boolean FULVL_bFlevLowFuelInjInit;                                  */
/*  input uint16 Flev_low_fuel_level_sw_tempo;                                */
/*  input boolean Lfbk_on_enrich_clamp;                                       */
/*  input uint16 Flev_low_level_sw_lfbk_counter;                              */
/*  input boolean FULVL_bFlevLowFuelLfbkInitPrev;                             */
/*  input boolean FULVL_bFlevLowFuelLfbkInit;                                 */
/*  input boolean Mf_cat_dam_det_uavb0;                                       */
/*  input boolean FULVL_bMfCatDamDetUavb0Prev;                                */
/*  input uint16 Flev_low_level_sw_mf_counter;                                */
/*  output boolean FULVL_bFlevLowFuelInjInit;                                 */
/*  output uint16 Flev_low_level_sw_inj_counter;                              */
/*  output boolean Flev_low_fuel_level_sw_inj;                                */
/*  output boolean FULVL_bFlevLowFuelInjInitPrev;                             */
/*  output boolean FULVL_bFlevLowFuelLfbkInit;                                */
/*  output uint16 Flev_low_level_sw_lfbk_counter;                             */
/*  output boolean Flev_low_fuel_level_sw_lfbk;                               */
/*  output boolean FULVL_bFlevLowFuelLfbkInitPrev;                            */
/*  output uint16 Flev_low_level_sw_mf_counter;                               */
/*  output boolean Flev_low_fuel_level_sw_mf;                                 */
/*  output boolean FULVL_bMfCatDamDetUavb0Prev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidTemporisation(void)
{
   boolean bLocalAfaPannePresente_adapt_inj;
   boolean bLocalLfbk_on_enrich_clamp;
   boolean bLocalMf_cat_dam_det_uavb0;


   /* FuLvl/FuLvl/3_Fuel_low_level/2_low_fuel_level_Software/1_temporisation */
   VEMS_vidGET(Afa_panne_presente_adapt_inj, bLocalAfaPannePresente_adapt_inj);

   if (  (bLocalAfaPannePresente_adapt_inj != 0)
      && (Flev_low_level_sw_inj_counter == 0) )
   {
      FULVL_bFlevLowFuelInjInit = 1;
   }
   else
   {
      FULVL_bFlevLowFuelInjInit = 0;
   }
   /*Timer*/
   if (  (FULVL_bFlevLowFuelInjInitPrev == 0)
      && (FULVL_bFlevLowFuelInjInit != 0))
   {
      Flev_low_level_sw_inj_counter =
         (uint16)MATHSRV_udtMIN(Flev_low_fuel_level_sw_tempo, 3000);

      if (Flev_low_level_sw_inj_counter == 0)
      {
         VEMS_vidSET(Flev_low_fuel_level_sw_inj, 0);
      }
      else
      {
         VEMS_vidSET(Flev_low_fuel_level_sw_inj, 1);
      }
   }
   else
   {
      if (Flev_low_level_sw_inj_counter > 0)
      {
         Flev_low_level_sw_inj_counter = (uint16)( Flev_low_level_sw_inj_counter
                                                - 1);
         Flev_low_level_sw_inj_counter =
            (uint16)MATHSRV_udtMIN(Flev_low_level_sw_inj_counter, 3000);
         if (Flev_low_level_sw_inj_counter == 0)
         {
            VEMS_vidSET(Flev_low_fuel_level_sw_inj, 0);
         }
         else
         {
            VEMS_vidSET(Flev_low_fuel_level_sw_inj, 1);
         }
      }
   }
   FULVL_bFlevLowFuelInjInitPrev = FULVL_bFlevLowFuelInjInit;
   VEMS_vidGET(Lfbk_on_enrich_clamp, bLocalLfbk_on_enrich_clamp);
   if (  (bLocalLfbk_on_enrich_clamp != 0)
      && (Flev_low_level_sw_lfbk_counter == 0))
   {
      FULVL_bFlevLowFuelLfbkInit = 1;
   }
   else
   {
      FULVL_bFlevLowFuelLfbkInit = 0;
   }
   /*Timer1*/
   if (  (FULVL_bFlevLowFuelLfbkInitPrev == 0)
      && (FULVL_bFlevLowFuelLfbkInit != 0))
   {
      Flev_low_level_sw_lfbk_counter =
         (uint16)MATHSRV_udtMIN(Flev_low_fuel_level_sw_tempo, 3000);
      if (Flev_low_level_sw_lfbk_counter == 0)
      {
         VEMS_vidSET(Flev_low_fuel_level_sw_lfbk, 0);
      }
      else
      {
         VEMS_vidSET(Flev_low_fuel_level_sw_lfbk, 1);
      }
   }
   else
   {
      if (Flev_low_level_sw_lfbk_counter > 0)
      {
         Flev_low_level_sw_lfbk_counter =
            (uint16)( Flev_low_level_sw_lfbk_counter - 1);
         Flev_low_level_sw_lfbk_counter =
            (uint16)MATHSRV_udtMIN(Flev_low_level_sw_lfbk_counter, 3000);
         if (Flev_low_level_sw_lfbk_counter == 0)
         {
            VEMS_vidSET(Flev_low_fuel_level_sw_lfbk, 0);
         }
         else
         {
            VEMS_vidSET(Flev_low_fuel_level_sw_lfbk, 1);
         }
      }
   }
   FULVL_bFlevLowFuelLfbkInitPrev = FULVL_bFlevLowFuelLfbkInit;

   VEMS_vidGET(Mf_cat_dam_det_uavb0, bLocalMf_cat_dam_det_uavb0);
   /*Timer2*/
   if (  (FULVL_bMfCatDamDetUavb0Prev == 0)
      && (bLocalMf_cat_dam_det_uavb0 != 0))
   {
      Flev_low_level_sw_mf_counter =
         (uint16)MATHSRV_udtMIN(Flev_low_fuel_level_sw_tempo, 3000);
      if (Flev_low_level_sw_mf_counter == 0)
      {
         VEMS_vidSET(Flev_low_fuel_level_sw_mf, 0);
      }
      else
      {
         VEMS_vidSET(Flev_low_fuel_level_sw_mf, 1);
      }
   }
   else
   {
      if (Flev_low_level_sw_mf_counter > 0)
      {
         Flev_low_level_sw_mf_counter =
            (uint16)( Flev_low_level_sw_mf_counter - 1);
         Flev_low_level_sw_mf_counter =
            (uint16)MATHSRV_udtMIN(Flev_low_level_sw_mf_counter, 3000);
         if (Flev_low_level_sw_mf_counter == 0)
         {
            VEMS_vidSET(Flev_low_fuel_level_sw_mf, 0);
         }
         else
         {
            VEMS_vidSET(Flev_low_fuel_level_sw_mf, 1);
         }
      }
   }
   FULVL_bMfCatDamDetUavb0Prev = bLocalMf_cat_dam_det_uavb0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFuelLevel                                         */
/* !Description :  Cette fonction permet de filter l’information de niveau de */
/*                 carburant provenant du CAN et la détection d’ajout de      */
/*                 carburant(au démarrage après un reset ou après un calage   */
/*                 moteur ou un key on -off sans qu’il n’y ait eu reset ou    */
/*                 moteur tournant).                                          */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidFilteringInfoMux();                             */
/*  extf argret void FULVL_vidFuelLevelCompute();                             */
/*  extf argret void FULVL_vidFuelLevelIncComputeDem();                       */
/*  extf argret void FULVL_vidLvlIncCpeCaleRunning();                         */
/*  extf argret void FULVL_vidRunningCounter();                               */
/*  extf argret void FULVL_vidFuelLevelIncRunning();                          */
/*  input uint8 Flev_fuel_level_count;                                        */
/*  input boolean FULVL_bFlevFuelLevelCountPrev;                              */
/*  input uint16 FULVL_u16FlevFuelLvlLastCntPrev;                             */
/*  input uint16 Flev_fuel_level_last_delay;                                  */
/*  input uint16 Flev_fuel_level_last_count;                                  */
/*  input uint8 FULVL_u8FlevFuelLevelCountPrev;                               */
/*  output boolean FULVL_bFlevFuelLevelCountPrev;                             */
/*  output uint16 FULVL_u16FlevFuelLvlLastCntPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelLevel(void)
{
   FULVL_vidFilteringInfoMux();
   if (Flev_fuel_level_count == 0)
   {
      FULVL_vidFuelLevelCompute();
      if (FULVL_bFlevFuelLevelCountPrev != 0)
      {
         FULVL_vidFuelLevelIncComputeDem();
         FULVL_vidLvlIncCpeCaleRunning();
      }
   }
   FULVL_vidRunningCounter();
   if (  (FULVL_u16FlevFuelLvlLastCntPrev != Flev_fuel_level_last_delay)
      && (Flev_fuel_level_last_count == Flev_fuel_level_last_delay) )
   {
      FULVL_vidFuelLevelIncRunning();
   }

   if (FULVL_u8FlevFuelLevelCountPrev == 0)
   {
      FULVL_bFlevFuelLevelCountPrev = 0;
   }
   else
   {
      FULVL_bFlevFuelLevelCountPrev = 1;
   }
   FULVL_u16FlevFuelLvlLastCntPrev = Flev_fuel_level_last_count;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFilteringInfoMux                                  */
/* !Description :  L’information de niveau de carburant provenant du CAN est  */
/*                 filtrée.                                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Flev_fuel_level_mux;                                          */
/*  input uint8 Flev_fuel_level_count;                                        */
/*  input uint8 Flev_fuel_level_filtered_gain;                                */
/*  input uint32 FULVL_u32FiltredFlevFuelLevelMux;                            */
/*  output uint16 Flev_fuel_level_filtered;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFilteringInfoMux(void)
{
   uint8  u8LocalFlev_fuel_level_mux;
   uint16 u16LocalFiltredValue;
   uint16 u16LocalFlevFuelLevelMux;


   /*FuLvl/FuLvl/4_Fuel_level/1_Filtrage_info_mux*/
   VEMS_vidGET(Flev_fuel_level_mux, u8LocalFlev_fuel_level_mux);
   u16LocalFlevFuelLevelMux = (uint16)(u8LocalFlev_fuel_level_mux * 256);
   if (Flev_fuel_level_count == 0)
   {
      u16LocalFiltredValue =
         MATHSRV_u16FirstOrderFilterGu8(Flev_fuel_level_filtered_gain,
                                        &FULVL_u32FiltredFlevFuelLevelMux,
                                        u16LocalFlevFuelLevelMux);
      Flev_fuel_level_filtered = u16LocalFiltredValue;
   }
   else
   {
      Flev_fuel_level_filtered = u16LocalFlevFuelLevelMux;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFuelLevelCompute                                  */
/* !Description :  Si on a un défaut confirmé sur la jauge à carburant ou sur */
/*                 le niveau fonctionnel du carburant (FRM_bInhFuLvlClcn à 1),*/
/*                 la valeur du niveau carburant est mise à FFh.              */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Flev_fuel_level_filtered;                                    */
/*  output uint8 Flev_fuel_level;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelLevelCompute(void)
{
   boolean bLocalInhFuLvlClcn;
   uint8   u8LocalScaling;
   uint8   u8LocalFlev_fuel_level;

   /*FuLvl/FuLvl/4_Fuel_level/2_Fuel_level_compute*/
   bLocalInhFuLvlClcn = GDGAR_bGetFRM(FRM_FRM_INHFULVLCLCN);
   if (bLocalInhFuLvlClcn != 0)
   {
      u8LocalFlev_fuel_level = 0xFF;
   }else
   {
      u8LocalScaling = (uint8)(Flev_fuel_level_filtered / 256);
      u8LocalFlev_fuel_level = (uint8)MATHSRV_udtMIN(u8LocalScaling, 253);
   }
   VEMS_vidSET(Flev_fuel_level, u8LocalFlev_fuel_level);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFuelLevelIncComputeDem                            */
/* !Description :  Fonction dui permet le calcul du niveau carburant lorsqu'on*/
/*                 n'est pas en calage ou clé à OFF                           */
/*                 (Flev_last_stall_or_key_off != 1).                         */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidFuelLevelIncCpteDem();                          */
/*  input boolean Flev_last_stall_or_key_off;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelLevelIncComputeDem(void)
{
   /*FuLvl/FuLvl/4_Fuel_level/3_Fuel_level_inc_compute_dem*/
   if (Flev_last_stall_or_key_off == 0)
   {
      FULVL_vidFuelLevelIncCpteDem();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidLvlIncCpeCaleRunning                              */
/* !Description :  Fonction dui permet le calcul du niveau carburant s'il y a */
/*                 eu calage ou clé à OFF.                                    */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidLvlIncCaleRunning();                            */
/*  input boolean Flev_last_stall_or_key_off;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidLvlIncCpeCaleRunning(void)
{
   /*FuLvl/FuLvl/4_Fuel_level/4_Fuel_level_inc_compute_cale_tournant*/
   if (Flev_last_stall_or_key_off != 0)
   {
      FULVL_vidLvlIncCaleRunning();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidRunningCounter                                    */
/* !Description :  Fonction de calcul du compteur tournant                    */
/*                 Flev_fuel_level_last_count.                                */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Flev_fuel_level_last_count;                                  */
/*  input uint16 Flev_fuel_level_last_delay;                                  */
/*  output uint16 Flev_fuel_level_last_count;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidRunningCounter(void)
{
   uint16 u16LocalFlevFuelLevelLastCount;


   /*FuLvl/FuLvl/4_Fuel_level/5_Tournant_counter*/
   if (Flev_fuel_level_last_count == Flev_fuel_level_last_delay)
   {
      u16LocalFlevFuelLevelLastCount = 0;
   }
   else
   {
      if (Flev_fuel_level_last_count < 65535)
      {
         u16LocalFlevFuelLevelLastCount = (uint16)( Flev_fuel_level_last_count
                                                  + 1);
      }
      else
      {
         u16LocalFlevFuelLevelLastCount = 65535;
      }
   }
   Flev_fuel_level_last_count =
      (uint16)MATHSRV_udtMIN(u16LocalFlevFuelLevelLastCount,
                             Flev_fuel_level_last_delay);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFuelLevelIncRunning                               */
/* !Description :  Fonction dui permet le calcul du niveau carburant sur      */
/*                 événement RUNNING.                                         */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FULVL_vidFuelIncComputeRunning();                        */
/*  input boolean Moteur_tournant;                                            */
/*  input boolean Vehicule_roulant;                                           */
/*  input boolean Flev_fuel_inc_run_manu_inh;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelLevelIncRunning(void)
{
   boolean bLocalMoteur_tournant;
   boolean bLocalVehicule_roulant;


   /*FuLvl/FuLvl/4_Fuel_level/6_Fuel_level_inc_compute_tournant*/

   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   VEMS_vidGET(Vehicule_roulant, bLocalVehicule_roulant);
   if (  (bLocalMoteur_tournant != 0)
      && (bLocalVehicule_roulant == 0)
      && (Flev_fuel_inc_run_manu_inh == 0) )
   {
      FULVL_vidFuelIncComputeRunning();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidInitEngineRunning                                 */
/* !Description :  Fonction d'initialisation du niveau carburant sur événement*/
/*                 RUNNING.                                                   */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Flev_fuel_level;                                              */
/*  output uint8 Flev_fuel_level_last;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidInitEngineRunning(void)
{
   uint8 u8LocalFlev_fuel_level;


   /* FuLvl/FuLvl/8_Init_moteur_tournant */
   VEMS_vidGET(Flev_fuel_level, u8LocalFlev_fuel_level);
   Flev_fuel_level_last = u8LocalFlev_fuel_level;
}
/*------------------------------- end of file --------------------------------*/
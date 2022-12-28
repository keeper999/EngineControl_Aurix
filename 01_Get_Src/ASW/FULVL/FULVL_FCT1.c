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
/* !File            : FULVL_FCT1.C                                            */
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
/*   1 / FULVL_vidInitOutputs                                                 */
/*   2 / FULVL_vidInitReset                                                   */
/*   3 / FULVL_vidInitKeyOffOn                                                */
/*   4 / FULVL_vidCounterDec                                                  */
/*   5 / FULVL_vidFuelGaugeState                                              */
/*   6 / FULVL_vidLowFuelLevelHardware                                        */
/*   7 / FULVL_vidLowFuelLevelSoftware                                        */
/*   8 / FULVL_vidFuelLevelState                                              */
/*   9 / FULVL_vidFuelLevelCpteCaleOrOff                                      */
/*   10 / FULVL_vidEepromWrite                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5462804 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#049911                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/FULVL/FULVL_FCT1.C_v         $*/
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
/* !Function    :  FULVL_vidInitOutputs                                       */
/* !Description :  Fonction d'initialisation des variables de sorties.        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean FULVL_bFlevFuelLevelCountPrev;                             */
/*  output boolean FULVL_bFlevFuelLevelThrshPrev;                             */
/*  output uint16 FULVL_u16FlevFuelLvlLastCntPrev;                            */
/*  output uint32 FULVL_u32FiltredFlevFuelLevelMux;                           */
/*  output boolean FULVL_bFlevLowFuelInjInit;                                 */
/*  output boolean FULVL_bFlevLowFuelInjInitPrev;                             */
/*  output boolean FULVL_bFlevLowFuelLfbkInit;                                */
/*  output boolean FULVL_bFlevLowFuelLfbkInitPrev;                            */
/*  output boolean FULVL_bMfCatDamDetUavb0Prev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidInitOutputs(void)
{
   FULVL_bFlevFuelLevelCountPrev = 0;
   FULVL_bFlevFuelLevelThrshPrev = 0;
   FULVL_u16FlevFuelLvlLastCntPrev = 0;
   FULVL_u32FiltredFlevFuelLevelMux = 0;
   FULVL_bFlevLowFuelInjInit = 0;
   FULVL_bFlevLowFuelInjInitPrev = 0;
   FULVL_bFlevLowFuelLfbkInit = 0;
   FULVL_bFlevLowFuelLfbkInitPrev = 0;
   FULVL_bMfCatDamDetUavb0Prev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidInitReset                                         */
/* !Description :  Fonction qui initialise le délai avant validité de         */
/*                 l’information niveau carburant disponible sur CAN (trame   */
/*                 612h), Les compteurs de décrémentation, les indicateurs de */
/*                 niveau bas du réservoir estimé par le soft et qui détecte  */
/*                 le remplissage du réservoir.                               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Flev_fuel_level_delay;                                       */
/*  input uint8 Flev_fuel_level_in_eep;                                       */
/*  output uint8 Flev_fuel_level_count;                                       */
/*  output boolean Flev_fuel_level_increase;                                  */
/*  output boolean Flev_low_fuel_level_sw_inj;                                */
/*  output boolean Flev_low_fuel_level_sw_mf;                                 */
/*  output boolean Flev_low_fuel_level_sw_lfbk;                               */
/*  output uint16 Flev_low_level_sw_inj_counter;                              */
/*  output uint16 Flev_low_level_sw_mf_counter;                               */
/*  output uint16 Flev_low_level_sw_lfbk_counter;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidInitReset(void)
{
   /*FuLvl/FuLvl/0_Init/0_Init_reset*/
   Flev_fuel_level_count = (uint8)MATHSRV_udtMIN(Flev_fuel_level_delay, 29);
   if (Flev_fuel_level_in_eep == 254)
   {
      VEMS_vidSET(Flev_fuel_level_increase, 1);
   }
   else
   {
      VEMS_vidSET(Flev_fuel_level_increase, 0);
   }
   VEMS_vidSET(Flev_low_fuel_level_sw_inj, 1);
   VEMS_vidSET(Flev_low_fuel_level_sw_mf, 1);
   VEMS_vidSET(Flev_low_fuel_level_sw_lfbk, 1);
   Flev_low_level_sw_inj_counter = 0;
   Flev_low_level_sw_mf_counter = 0;
   Flev_low_level_sw_lfbk_counter = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidInitKeyOffOn                                      */
/* !Description :  Sur cle off_on : le délai avant validité de l’information  */
/*                 niveau carburant disponible sur le CAN (trame 612h) est    */
/*                 initialisé et la consommation carburant totale est         */
/*                 mémorisée.                                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Consommation_carburant_totale;                               */
/*  input uint8 Flev_fuel_level_count;                                        */
/*  input uint16 Flev_fuel_level_delay;                                       */
/*  output uint8 FULVL_u8FlevFuelLevelCountPrev;                              */
/*  output uint8 Flev_fuel_level_count;                                       */
/*  output uint32 Conso_carbu_totale_ref;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidInitKeyOffOn(void)
{
   uint32 u32LocalConsommationCarburantTot;


   /*FuLvl/FuLvl/0_Init/1_Init_cle_off_on*/
   VEMS_vidGET(Consommation_carburant_totale, u32LocalConsommationCarburantTot);
   FULVL_u8FlevFuelLevelCountPrev = (uint8)MATHSRV_udtMIN(Flev_fuel_level_count,
                                                          29);
   Flev_fuel_level_count = (uint8)MATHSRV_udtMIN(Flev_fuel_level_delay, 29);
   Conso_carbu_totale_ref = u32LocalConsommationCarburantTot;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidCounterDec                                        */
/* !Description :  Fonction de décrémentation du compteur                     */
/*                 Flev_fuel_level_count.                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Flev_fuel_level_count;                                        */
/*  output uint8 FULVL_u8FlevFuelLevelCountPrev;                              */
/*  output uint8 Flev_fuel_level_count;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidCounterDec(void)
{
   uint8 u8LocalFlevFuelLevelCount;


   /*FuLvl/FuLvl/1_Counter_dec*/
   FULVL_u8FlevFuelLevelCountPrev = (uint8)MATHSRV_udtMIN(Flev_fuel_level_count,
                                                          29);
   if (Flev_fuel_level_count > 0)
   {
      u8LocalFlevFuelLevelCount = (uint8)(Flev_fuel_level_count - 1);
      Flev_fuel_level_count =
            (uint8)MATHSRV_udtMIN(u8LocalFlevFuelLevelCount, 29);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFuelGaugeState                                    */
/* !Description :  Fonction qui permet de donner l'Etat de la jauge à         */
/*                 carburant(CC, CO, donnée invalide).                        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FULVL_vidFuelGaugeSt();                                  */
/*  input boolean Diag_on;                                                    */
/*  output boolean Fu_bMonRunOc_FuGauge;                                      */
/*  output boolean Fu_bMonRunScg_FuGauge;                                     */
/*  output boolean Fu_bMonRunORng_FuGauge;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelGaugeState(void)
{
   boolean bLocalDiag_on;


   /*FuLvl/FuLvl/2_Fuel_gauge_state*/
   VEMS_vidGET(Diag_on, bLocalDiag_on);
   if (bLocalDiag_on != 0)
   {
      Fu_bMonRunOc_FuGauge = 1;
      Fu_bMonRunScg_FuGauge = 1;
      Fu_bMonRunORng_FuGauge = 1;
      FULVL_vidFuelGaugeSt();

   }else
   {
      Fu_bMonRunOc_FuGauge = 0;
      Fu_bMonRunScg_FuGauge = 0;
      Fu_bMonRunORng_FuGauge = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidLowFuelLevelHardware                              */
/* !Description :  Fonction représentant  le calcul nominal de l’information  */
/*                 niveau bas carburant.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Flev_low_fuel_level_mux;                                    */
/*  input boolean Flev_etat_haut_en_reserve;                                  */
/*  output boolean Flev_low_fuel_level_can;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidLowFuelLevelHardware(void)
{
   boolean bLocalFlev_low_fuel_level_mux;


   /*FuLvl/FuLvl/3_Fuel_low_level/1_low_fuel_level_hardware*/
   VEMS_vidGET(Flev_low_fuel_level_mux, bLocalFlev_low_fuel_level_mux);
   if (Flev_etat_haut_en_reserve != 0)
   {
      Flev_low_fuel_level_can = bLocalFlev_low_fuel_level_mux;
   }
   else
   {
      Flev_low_fuel_level_can = !bLocalFlev_low_fuel_level_mux;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidLowFuelLevelSoftware                              */
/* !Description :  Cette fonction .choisit le signal niveau carburant mini en */
/*                 fonction de la configuration véhicule, et lance une        */
/*                 solution software si le capteur est défaillant.            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_09_04362_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FULVL_vidTemporisation();                                */
/*  input boolean Moteur_tournant;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidLowFuelLevelSoftware(void)
{
   boolean bLocalInhFuLowLvlHw;
   boolean bLocalMoteur_tournant;


   /*FuLvl/FuLvl/3_Fuel_low_level/2_low_fuel_level_Software*/
   bLocalInhFuLowLvlHw = GDGAR_bGetFRM(FRM_FRM_INHFULOWLVLHW);
   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   if (  (bLocalInhFuLowLvlHw != 0)
      && (bLocalMoteur_tournant != 0))
   {
      FULVL_vidTemporisation();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFuelLevelState                                    */
/* !Description :  Fonction de gestion du défaut lié au niveau de carburant.  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FULVL_vidFuelLevelSt();                                  */
/*  input boolean Diag_on;                                                    */
/*  input uint8 Flev_fuel_level;                                              */
/*  input boolean Flev_fuel_level_inc_running;                                */
/*  input uint8 Flev_fuel_level_count;                                        */
/*  input uint8 Flev_fuel_level_filtered_ref;                                 */
/*  output boolean Fu_bMonRunORng_FuGaugeLvl;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelLevelState(void)
{
   boolean bLocalDiag_on;
   uint8   u8LocalFlev_fuel_level;


   /*FuLvl/FuLvl/5_Fuel_level_state*/
   VEMS_vidGET(Diag_on, bLocalDiag_on);
   VEMS_vidGET(Flev_fuel_level, u8LocalFlev_fuel_level);
   if (  (Flev_fuel_level_inc_running == 0)
      && (Flev_fuel_level_count == 0)
      && (bLocalDiag_on != 0)
      && (Flev_fuel_level_filtered_ref > u8LocalFlev_fuel_level) )
   {
      Fu_bMonRunORng_FuGaugeLvl = 1;
      /*1_Fuel_level_state*/
      FULVL_vidFuelLevelSt();
   }else
   {
      Fu_bMonRunORng_FuGaugeLvl = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidFuelLevelCpteCaleOrOff                            */
/* !Description :  Détection d’un cle on-off ou d’un calage.                  */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidFuelLevelCaleOrOff();                           */
/*  input uint8 Flev_fuel_level_count;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidFuelLevelCpteCaleOrOff(void)
{
   /* FuLvl/FuLvl/6_Fuel_level_compute_cale_or_off */
   if (Flev_fuel_level_count == 0)
   {
      FULVL_vidFuelLevelCaleOrOff();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vidEepromWrite                                       */
/* !Description :  Ecriture en EEPROM du niveau carburant.                    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Flev_fuel_level;                                              */
/*  input boolean Flev_fuel_level_inc_next;                                   */
/*  output uint8 Flev_fuel_level_in_eep;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vidEepromWrite(void)
{
   uint8 u8LocalFlev_fuel_level;


   /*FuLvl/FuLvl/7_Eeprom_write*/
   VEMS_vidGET(Flev_fuel_level, u8LocalFlev_fuel_level);
   if (Flev_fuel_level_inc_next != 0)
   {
      Flev_fuel_level_in_eep = 254;
   }else
   {
      Flev_fuel_level_in_eep = u8LocalFlev_fuel_level;
   }
}
/*------------------------------- end of file --------------------------------*/
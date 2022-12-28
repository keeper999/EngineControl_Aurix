/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJTICOR                                                */
/* !Description     : INJTICOR component                                      */
/*                                                                            */
/* !Module          : INJTICOR                                                */
/* !Description     : CORRECTION DE LA RÉGULATION DE RICHESSE EN BUTÉE        */
/*                                                                            */
/* !File            : INJTICOR_FCT5.C                                         */
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
/*   1 / INJTICOR_vidReinitFarStraMon                                         */
/*   2 / INJTICOR_vidAcvDiagEngineRunning                                     */
/*   3 / INJTICOR_vidDiagEngineRunning                                        */
/*   4 / INJTICOR_vidInitGslMod                                               */
/*   5 / INJTICOR_vidInitGasMod                                               */
/*   6 / INJTICOR_vidInitLfbkSwitchGslGas                                     */
/*   7 / INJTICOR_vidLfbkInitGas                                              */
/*   8 / INJTICOR_vidLfbkInitGsl                                              */
/*   9 / INJTICOR_vidDiagnostic                                               */
/*   10 / INJTICOR_vidbDgoAlimLeanFuel                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5147608 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065914                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJTICOR/INJTICOR_FCT5.C_v        $*/
/* $Revision::   1.10     $$Author::   achebino       $$Date::   20 Dec 2012 $*/
/* $Author::   achebino                               $$Date::   20 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "INJTICOR.h"
#include "INJTICOR_L.h"
#include "INJTICOR_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidReinitFarStraMon                               */
/* !Description :  Lorsque le Gestionnaire des Stratégies n’autorise pas le   */
/*                 diagnostics de régulation de richesse en butée, les        */
/*                 booléens de diagnostics de butées sont réinitialisés à 0.  */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint32 Lfbk_settling_delay_gas_c;                                   */
/*  input uint32 Lfbk_settling_delay_c;                                       */
/*  output boolean Lfbk_rich_fuel;                                            */
/*  output boolean Lfbk_lean_fuel;                                            */
/*  output uint32 Lfbk_settling_delay_count;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidReinitFarStraMon(void)
{
   uint8   u8LocalExt_stSysGas;
   uint32  u32LocalLfbk;


   /* 03_Reinit_FarStraMon */
   Lfbk_rich_fuel = 0;
   Lfbk_lean_fuel = 0;

   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u32LocalLfbk = Lfbk_settling_delay_gas_c;
   }
   else
   {
      u32LocalLfbk = Lfbk_settling_delay_c;
   }
   Lfbk_settling_delay_count = MATHSRV_udtMIN(u32LocalLfbk, 327679);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidAcvDiagEngineRunning                           */
/* !Description :  Ce bloc ne doit être vérifié que si le moteur est tournant.*/
/* !Number      :  FCT5.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJTICOR_vidDiagEngineRunning();                         */
/*  input boolean Moteur_tournant;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidAcvDiagEngineRunning(void)
{
   boolean bLocalMoteur_tournant;


   /*04_Acv_diag_engine_running*/
   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);

   if (bLocalMoteur_tournant != 0)
   {
      INJTICOR_vidDiagEngineRunning();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidDiagEngineRunning                              */
/* !Description :  Lorsque le moteur est tournant, la stratégie regarde le    */
/*                 résultat des 6 diagnostics. Pour que les défauts soient    */
/*                 pris en compte dans le GDGAR, il faut la présence d’un     */
/*                 défaut de butée et la présence d’un défaut incriminant les */
/*                 sondes ou les injecteurs.                                  */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lfbk_lean_fuel;                                             */
/*  input boolean Lfbk_rich_fuel;                                             */
/*  input boolean Lfbk_desired_conditions;                                    */
/*  input boolean Lfbk_switch_lean;                                           */
/*  input boolean Lfbk_switch_rich;                                           */
/*  input boolean Lfbk_stuck_lean;                                            */
/*  input boolean Lfbk_stuck_rich;                                            */
/*  input uint16 Lfbk_diag_aborted_count;                                     */
/*  input boolean Lfbk_diag_no_failure_completed;                             */
/*  output boolean Lfbk_diag_enable;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidDiagEngineRunning(void)
{
   boolean  bLocalLfbkDiagNofailure;


   /*01_Acv_diag_engine_running*/
   if (  (Lfbk_lean_fuel != 0)
      || (Lfbk_rich_fuel != 0))
   {
      if (  (Lfbk_desired_conditions != 0)
         && (  (  (Lfbk_switch_lean != 0)
               || (Lfbk_switch_rich != 0)
               || (Lfbk_stuck_lean != 0)
               || (Lfbk_stuck_rich != 0))
            || (Lfbk_diag_aborted_count == 0)))
      {
         Lfbk_diag_enable = 1;
      }
      else
      {
         Lfbk_diag_enable = 0;
      }
   }
   else
   {
      if (Lfbk_desired_conditions != 0)
      {
         VEMS_vidGET(Lfbk_diag_no_failure_completed, bLocalLfbkDiagNofailure);
         Lfbk_diag_enable = bLocalLfbkDiagNofailure;
      }
      else
      {
         Lfbk_diag_enable = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidInitGslMod                                     */
/* !Description :  Initialiser le compteur du temps d'établissement à la      */
/*                 calibration du temps d'établissement.                      */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 Lfbk_settling_delay_c;                                       */
/*  output uint32 Lfbk_settling_delay_count;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidInitGslMod(void)
{
   /* 01_Init_GslMod */
   Lfbk_settling_delay_count = MATHSRV_udtMIN(Lfbk_settling_delay_c, 327679);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidInitGasMod                                     */
/* !Description :  Initialiser le compteur du temps d'établissement à la      */
/*                 calibration du temps d'établissement (pour application     */
/*                 gaz).                                                      */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 Lfbk_settling_delay_gas_c;                                   */
/*  output uint32 Lfbk_settling_delay_count;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidInitGasMod(void)
{
   /* 02_Init_GasMod */
   Lfbk_settling_delay_count =
      MATHSRV_udtMIN(Lfbk_settling_delay_gas_c, 327679);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidInitLfbkSwitchGslGas                           */
/* !Description :  Cette fonction permet d’initialiser correctement les       */
/*                 variables dépendantes de la présence d’une application Gaz */
/*                 et le cas échéant, du mode carburant utilisé au moment de  */
/*                 la réception de la première trame Gaz.                     */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJTICOR_vidLfbkInitGas();                               */
/*  extf argret void INJTICOR_vidLfbkInitGsl();                               */
/*  input boolean Ext_bPresGaz;                                               */
/*  input uint8 ISCAN_u8Compteur_RX_26C;                                      */
/*  input boolean Lfbk_init_fait;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidInitLfbkSwitchGslGas(void)
{
   boolean bLocalExt_bPresGaz;
   uint8   u8LocalISCAN_u8Compteur_RX_26C;


   /* 0010_initialise_lfbk_monitoring_switch_gsl_gas */
   VEMS_vidGET(Ext_bPresGaz, bLocalExt_bPresGaz);
   VEMS_vidGET(ISCAN_u8Compteur_RX_26C, u8LocalISCAN_u8Compteur_RX_26C);

   if (Lfbk_init_fait == 0)
   {
      if (bLocalExt_bPresGaz != 0)
      {
         if (u8LocalISCAN_u8Compteur_RX_26C >= 1)
         {
            INJTICOR_vidLfbkInitGas();
         }
      }
      else
      {
         INJTICOR_vidLfbkInitGsl();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidLfbkInitGas                                    */
/* !Description :  Cette fonction permet d’initialiser correctement les       */
/*                 variables dépendantes de la présence d’une application Gaz */
/* !Number      :  FCT5.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint32 Lfbk_settling_delay_gas_c;                                   */
/*  input uint16 Lfbk_no_failure_delay_gas_c;                                 */
/*  input uint16 Lfbk_diag_aborted_delay_gas_c;                               */
/*  input uint32 Lfbk_settling_delay_c;                                       */
/*  input uint16 Lfbk_no_failure_delay_c;                                     */
/*  input uint16 Lfbk_diag_aborted_delay_c;                                   */
/*  output uint32 Lfbk_settling_delay_count;                                  */
/*  output uint16 Lfbk_tempo_no_failure;                                      */
/*  output uint16 Lfbk_diag_aborted_count;                                    */
/*  output boolean Lfbk_init_fait;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidLfbkInitGas(void)
{
   uint8  u8LocalExt_stSysGas;


   /* 01_lfbk_init_gas */
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Lfbk_settling_delay_count =
         MATHSRV_udtMIN(Lfbk_settling_delay_gas_c, 327679);
      Lfbk_tempo_no_failure =
         (uint16)MATHSRV_udtMIN(Lfbk_no_failure_delay_gas_c, 49999);
      Lfbk_diag_aborted_count =
         (uint16)MATHSRV_udtMIN(Lfbk_diag_aborted_delay_gas_c, 2500);
   }
   else
   {
      Lfbk_settling_delay_count = MATHSRV_udtMIN(Lfbk_settling_delay_c, 327679);
      Lfbk_tempo_no_failure = (uint16)MATHSRV_udtMIN(Lfbk_no_failure_delay_c,
                                                     49999);
      Lfbk_diag_aborted_count =
         (uint16)MATHSRV_udtMIN(Lfbk_diag_aborted_delay_c, 2500);
   }
   Lfbk_init_fait = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidLfbkInitGsl                                    */
/* !Description :  Cette fonction permet d’initialiser correctement les       */
/*                 variables dépendantes de la présence d’une application Gsl */
/* !Number      :  FCT5.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 Lfbk_settling_delay_c;                                       */
/*  input uint16 Lfbk_no_failure_delay_c;                                     */
/*  input uint16 Lfbk_diag_aborted_delay_c;                                   */
/*  output boolean Lfbk_init_fait;                                            */
/*  output uint32 Lfbk_settling_delay_count;                                  */
/*  output uint16 Lfbk_tempo_no_failure;                                      */
/*  output uint16 Lfbk_diag_aborted_count;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidLfbkInitGsl(void)
{
   /* 02_lfbk_init_gsl */
   Lfbk_init_fait = 1;
   Lfbk_settling_delay_count = MATHSRV_udtMIN(Lfbk_settling_delay_c, 327679);
   Lfbk_tempo_no_failure = (uint16)MATHSRV_udtMIN(Lfbk_no_failure_delay_c,
                                                  49999);
   Lfbk_diag_aborted_count =(uint16)MATHSRV_udtMIN(Lfbk_diag_aborted_delay_c,
                                                   2500);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidDiagnostic                                     */
/* !Description :  Cette partie de la surveillance du FuelSystem utilise la   */
/*                 cohérence entre le signal de la sonde  aval et l’état de la*/
/*                 régulation de richesse, sans utiliser une modification de  */
/*                 l’injection via le « Diag_trim ».                          */
/* !Number      :  FCT5.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJTICOR_vidbDgoAlimLeanFuel();                          */
/*  extf argret void INJTICOR_vidbDgoSen02AmLeanBlo();                        */
/*  extf argret void INJTICOR_vidbDgoSen02AmRichBlo();                        */
/*  extf argret void INJTICOR_vidbDgoAlimRichFuel();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidDiagnostic(void)
{
   /* 021_Diagnostic */
   INJTICOR_vidbDgoAlimLeanFuel();
   INJTICOR_vidbDgoSen02AmLeanBlo();
   INJTICOR_vidbDgoSen02AmRichBlo();
   INJTICOR_vidbDgoAlimRichFuel();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidbDgoAlimLeanFuel                               */
/* !Description :  Cette fonction traite le cas d'un Défaut injecteur pauvre :*/
/*                 Lfbk_on_enrich_clamp est à l'état ON et Sonde_riche_aval   */
/*                 est à l'état OFF.                                          */
/* !Number      :  FCT5.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lfbk_on_enrich_clamp;                                       */
/*  input boolean Sonde_riche_aval;                                           */
/*  input uint8 Lfbk_stuck_lean_delay_count;                                  */
/*  input uint8 Lfbk_stuck_lean_delay;                                        */
/*  output uint8 Lfbk_stuck_lean_delay_count;                                 */
/*  output boolean Lfbk_stuck_lean;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidbDgoAlimLeanFuel(void)
{
   /* 1_bDgo_Alim_Carb_pauvre */
   boolean bLocalLfbkOnEnrichClamp;
   boolean bLocalSondeRicheAval;


   VEMS_vidGET(Lfbk_on_enrich_clamp, bLocalLfbkOnEnrichClamp);
   VEMS_vidGET(Sonde_riche_aval, bLocalSondeRicheAval);

   if (  (bLocalLfbkOnEnrichClamp != 0)
      && (bLocalSondeRicheAval == 0))
   {
      if (Lfbk_stuck_lean_delay_count > 0)
      {
         Lfbk_stuck_lean_delay_count = (uint8)(Lfbk_stuck_lean_delay_count - 1);
      }
      else
      {
         Lfbk_stuck_lean_delay_count = 0;
      }
   }
   else
   {
      Lfbk_stuck_lean_delay_count = Lfbk_stuck_lean_delay;
   }
   if (Lfbk_stuck_lean_delay_count == 0)
   {
      Lfbk_stuck_lean = 1;
   }
   else
   {
      Lfbk_stuck_lean = 0;
   }
}
/*------------------------------- end of file --------------------------------*/
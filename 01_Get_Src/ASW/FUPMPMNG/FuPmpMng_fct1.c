/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FUPMPMNG                                                */
/* !Description     : FUPMPMNG Component                                      */
/*                                                                            */
/* !Module          : FUPMPMNG                                                */
/* !Description     : STRATEGIE GESTION DE LA POMPE A ESSENCE                 */
/*                                                                            */
/* !File            : FUPMPMNG_FCT1.C                                         */
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
/*   1 / FUPMPMNG_vidInitOutput                                               */
/*   2 / FUPMPMNG_vidInit                                                     */
/*   3 / FUPMPMNG_vidInitEveKOnMng                                            */
/*   4 / FUPMPMNG_vidInitEveRxnIdDaRcdDml                                     */
/*   5 / FUPMPMNG_vidInitCallMng                                              */
/*   6 / FUPMPMNG_vidInitFuPmpPctl                                            */
/*   7 / FUPMPMNG_vidInitPumpCrankStall                                       */
/*   8 / FUPMPMNG_vidInitPumpStallCrank                                       */
/*                                                                            */
/* !Reference   : V02 NT 07 01322 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/FUPMP/FUPMPMNG/FUPMPMNG_FCT1.c_v  $*/
/* $Revision::   1.10                                                        $*/
/* $Author::   hmelloul                               $$Date::   26 Sep 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "FUPMPMNG.h"
#include "FUPMPMNG_L.h"
#include "FUPMPMNG_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidInitOutput                                     */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Fuel_pump_after_reset_delay;                                  */
/*  output boolean Commande_pompe_ess;                                        */
/*  output st02 FuPmp_stInitCallMng;                                          */
/*  output uint8 Fuel_pump_counter;                                           */
/*  output st79 FuPmp_stCtl;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUPMPMNG_vidInitOutput(void)
{
   VEMS_vidSET(Commande_pompe_ess, 0);
   FuPmp_stInitCallMng = FUPMP_WAIT;
   Fuel_pump_counter = (uint8)MATHSRV_udtMIN(Fuel_pump_after_reset_delay, 250);
   FuPmp_stCtl = FUPMP_NOM_WAIT;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidInit                                           */
/* !Description :  Fonction d'initialisation des paramètres produits          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean FuPmp_bafter_stall_ena;                                    */
/*  output boolean Fuel_pump_pre_control_ok;                                  */
/*  output boolean Fuel_pump_init_delay_ok;                                   */
/*  output boolean Fuel_pump_pre_control_active;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUPMPMNG_vidInit(void)
{
   FuPmp_bafter_stall_ena = 0;
   Fuel_pump_pre_control_ok = 1;
   Fuel_pump_init_delay_ok = 1;
   Fuel_pump_pre_control_active = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidInitEveKOnMng                                  */
/* !Description :  Fonction d'initialisation de la variable                   */
/*                 Fuel_pump_bEveKOn_Mng                                      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Fuel_pump_bEveKOn_Mng;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUPMPMNG_vidInitEveKOnMng(void)
{
   Fuel_pump_bEveKOn_Mng = 1;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidInitEveRxnIdDaRcdDml                           */
/* !Description :  Fonction d'initialisation de la variable                   */
/*                 Fuel_pump_bEveRxnIdDaRcdDml                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Fuel_pump_bEveRxnIdDaRcdDml;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUPMPMNG_vidInitEveRxnIdDaRcdDml(void)
{
   Fuel_pump_bEveRxnIdDaRcdDml = 1;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidInitCallMng                                    */
/* !Description :  Fonction qui gère la pré-commande pompe                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_07_01322_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FUPMPMNG_vidInitFuPmpPctl();                             */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st02 FuPmp_stInitCallMng;                                           */
/*  input boolean Rcd_preparation_moteur;                                     */
/*  input st09 Rcd_power_state;                                               */
/*  input boolean Fuel_pump_pre_control_ok;                                   */
/*  input boolean Fuel_pump_init_delay_ok;                                    */
/*  input boolean Fuel_pump_bEveRxnIdDaRcdDml;                                */
/*  input boolean Fuel_pump_bEveKOn_Mng;                                      */
/*  input boolean Rcd_mode_active;                                            */
/*  input uint8 Fuel_pump_counter;                                            */
/*  input uint8 Fuel_pump_after_reset_delay;                                  */
/*  output st02 FuPmp_stInitCallMng;                                          */
/*  output uint8 Fuel_pump_counter;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUPMPMNG_vidInitCallMng(void)
{
   boolean bLocalRcd_preparation_moteur;
   uint8   u8LocalRcd_power_state;
   uint8   u8LocalFuelPumpCounter;


   switch (FuPmp_stInitCallMng)
   {
      case FUPMP_WAIT:
         VEMS_vidGET(Rcd_preparation_moteur, bLocalRcd_preparation_moteur);
         VEMS_vidGET(Rcd_power_state, u8LocalRcd_power_state);
         if (  (Fuel_pump_pre_control_ok != 0)
            && (Fuel_pump_init_delay_ok != 0)
            && (  (  (Fuel_pump_bEveRxnIdDaRcdDml != 0)
                  && (u8LocalRcd_power_state == RCD_ANTICIPATION)
                  && (bLocalRcd_preparation_moteur != 0))
               || (Fuel_pump_bEveKOn_Mng != 0)
               || (Rcd_mode_active == 0)))
         {
            FuPmp_stInitCallMng = FUPMP_PRECOM_WAIT;
         }
         break;

      case FUPMP_PRECOM_WAIT:
         if (Fuel_pump_counter == 0)
         {
            FuPmp_stInitCallMng = FUPMP_AUTO_PRECOM;
            FUPMPMNG_vidInitFuPmpPctl();
         }
         else
         {
            u8LocalFuelPumpCounter = (uint8)(Fuel_pump_counter - 1);
            Fuel_pump_counter =
               (uint8)MATHSRV_udtMIN(u8LocalFuelPumpCounter, 250);
         }
         break;

      case FUPMP_AUTO_PRECOM:
         break;

      default:
         FuPmp_stInitCallMng = FUPMP_WAIT;
         Fuel_pump_counter =
            (uint8)MATHSRV_udtMIN(Fuel_pump_after_reset_delay, 250);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidInitFuPmpPctl                                  */
/* !Description :  controller la pompe d'essence                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_07_01322_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Date_emf_available_mux;                                     */
/*  input uint32 Time_since_stall;                                            */
/*  input uint32 Fuel_pump_long_stop_delay;                                   */
/*  input uint16 Fuel_pump_short_delay;                                       */
/*  input uint16 Fuel_pump_long_delay;                                        */
/*  output st03 FuPmp_stInitFuPmpPctl;                                        */
/*  output uint16 Fuel_pump_delay;                                            */
/*  output boolean Commande_pompe_ess;                                        */
/*  output boolean Fuel_pump_pre_control_active;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUPMPMNG_vidInitFuPmpPctl(void)
{
   boolean            bLocalDate_emf_available_mux;
   uint32             u32LocalTime_since_stall;
   GDFRM_tenuGDUState LocalGDU_stDgoF552bisP325Invld;
   GDFRM_tenuGDUState LocalGDU_stDgoF552P255Invld;
   GDFRM_tenuGDUState LocalGDU_stDgoF552P256Invld;
   GDFRM_tenuGDUState LocalGDU_stDgoF552P257Invld;


   LocalGDU_stDgoF552bisP325Invld = GDGAR_tenuGetStDgo(GD_DFT_F552BISP325INVLD);
   LocalGDU_stDgoF552P255Invld = GDGAR_tenuGetStDgo(GD_DFT_F552P255INVLD);
   LocalGDU_stDgoF552P256Invld = GDGAR_tenuGetStDgo(GD_DFT_F552P256INVLD);
   LocalGDU_stDgoF552P257Invld = GDGAR_tenuGetStDgo(GD_DFT_F552P257INVLD);
   VEMS_vidGET(Date_emf_available_mux, bLocalDate_emf_available_mux);
   VEMS_vidGET(Time_since_stall, u32LocalTime_since_stall);
   if (  (bLocalDate_emf_available_mux != 0)
      && (  (LocalGDU_stDgoF552bisP325Invld == GDU_ETAT_ABSENT)
         || (LocalGDU_stDgoF552bisP325Invld == GDU_ETAT_FUGITIF)
         || (LocalGDU_stDgoF552P255Invld == GDU_ETAT_ABSENT)
         || (LocalGDU_stDgoF552P255Invld == GDU_ETAT_FUGITIF)
         || (LocalGDU_stDgoF552P256Invld == GDU_ETAT_ABSENT)
         || (LocalGDU_stDgoF552P256Invld == GDU_ETAT_FUGITIF)
         || (LocalGDU_stDgoF552P257Invld == GDU_ETAT_ABSENT)
         || (LocalGDU_stDgoF552P257Invld == GDU_ETAT_FUGITIF))
      && (u32LocalTime_since_stall < Fuel_pump_long_stop_delay))
   {
      /* PRECOMMANDE_COURTE*/
      FuPmp_stInitFuPmpPctl = FUPMP_PREC_COURTE;
      Fuel_pump_delay = (uint16)MATHSRV_udtMIN(Fuel_pump_short_delay, 65000);
   }
   else
   {
      /* PRECOMMANDE_LONGUE*/
      FuPmp_stInitFuPmpPctl = FUPMP_PREC_LONGUE;
      Fuel_pump_delay = (uint16)MATHSRV_udtMIN(Fuel_pump_long_delay, 65000);
   }
   VEMS_vidSET(Commande_pompe_ess, 1);
   Fuel_pump_pre_control_active = 1;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidInitPumpCrankStall                             */
/* !Description :  Lorsque le moteur cale, le système initialise le délai de  */
/*                 commande de la pompe et réactive l’autorisation de la      */
/*                 précommande                                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Fuel_pump_after_stall_delay;                                 */
/*  output uint16 Fuel_pump_delay;                                            */
/*  output boolean FuPmp_bafter_stall_ena;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUPMPMNG_vidInitPumpCrankStall(void)
{
   Fuel_pump_delay = (uint16)MATHSRV_udtMIN(Fuel_pump_after_stall_delay, 65000);
   FuPmp_bafter_stall_ena = 1;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidInitPumpStallCrank                             */
/* !Description :  Lorsque le moteur se met à tourner (i.e. sur une transition*/
/*                 STALL -> CRANKING), le système commande le relais.         */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Commande_pompe_ess;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUPMPMNG_vidInitPumpStallCrank(void)
{
   VEMS_vidSET(Commande_pompe_ess, 1);
}

/*------------------------------- end of file --------------------------------*/
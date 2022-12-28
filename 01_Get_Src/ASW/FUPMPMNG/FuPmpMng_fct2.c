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
/* !File            : FUPMPMNG_FCT2.C                                         */
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
/*   1 / FUPMPMNG_vidControlPump                                              */
/*   2 / FUPMPMNG_vidCondAcv                                                  */
/*   3 / FUPMPMNG_vidCtl                                                      */
/*   4 / FUPMPMNG_vidEngineRunning                                            */
/*   5 / FUPMPMNG_vidStopEngReqOrKeyOff                                       */
/*                                                                            */
/* !Reference   : V02 NT 07 01322 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/FUPMP/FUPMPMNG/FUPMPMNG_FCT2.c_v  $*/
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
/* !Function    :  FUPMPMNG_vidControlPump                                    */
/* !Description :  Controller la pompe d'essence                              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FUPMPMNG_vidCondAcv();                                   */
/*  extf argret void FUPMPMNG_vidCtl();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUPMPMNG_vidControlPump(void)
{
   FUPMPMNG_vidCondAcv();
   FUPMPMNG_vidCtl();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidCondAcv                                        */
/* !Description :  Le choix de l'activation d'un mode de commande (précommande*/
/*                 nominale, périodique ou moteur en rotation) se fait        */
/*                 suivants les phases de vie du CMM et du moteur.            */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_07_01322_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FUPMPMNG_vidEngineRunning();                             */
/*  extf argret void FUPMPMNG_vidStopEngReqOrKeyOff();                        */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Temperature_eau_bkpt_map[16];                                 */
/*  input uint8 Fuel_pump_engine_speed_map[16];                               */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Fuel_pump_engine_speed_thresh;                                */
/*  input uint8 Fuel_pump_eng_speed_cmd;                                      */
/*  input st09 Rcd_power_state;                                               */
/*  input boolean Rcd_preparation_moteur;                                     */
/*  input boolean Clef_de_contact;                                            */
/*  output uint8 Fuel_pump_engine_speed_thresh;                               */
/*  output boolean Fuel_pump_pre_control_ok;                                  */
/*  output boolean FuPmp_bPerdPctl_Ena;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUPMPMNG_vidCondAcv(void)
{
   boolean bLocalRcdEng;
   boolean bLocalFuPmp;
   boolean bLocalClef_de_contact;
   boolean bLocalRcd_preparation_moteur;
   uint8   u8LocalRcd_power_state;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalRegime_moteur_32;
   uint16  u16LocalCalcPara;


   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU8(Temperature_eau_bkpt_map,
                                  u8LocalTemperature_eau,
                                  16);
   Fuel_pump_engine_speed_thresh =
      MATHSRV_u8Interp1d(Fuel_pump_engine_speed_map, u16LocalCalcPara);

   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   if (u8LocalRegime_moteur_32 > Fuel_pump_engine_speed_thresh)
   {
      Fuel_pump_pre_control_ok = 1;
   }

   if (Fuel_pump_eng_speed_cmd < u8LocalRegime_moteur_32)
   {
      FUPMPMNG_vidEngineRunning();
      bLocalFuPmp = 1;
   }
   else
   {
      bLocalFuPmp = 0;
   }

   VEMS_vidGET(Rcd_power_state, u8LocalRcd_power_state);
   VEMS_vidGET(Rcd_preparation_moteur, bLocalRcd_preparation_moteur);
   if (  (u8LocalRcd_power_state == RCD_ANTICIPATION)
      && (bLocalRcd_preparation_moteur != 0))
   {
      bLocalRcdEng = 1;
   }
   else
   {
      bLocalRcdEng = 0;
   }

   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   if (  (bLocalFuPmp == 0)
      && (  (bLocalRcdEng != 0)
         || (bLocalClef_de_contact != 0)))
   {
      FuPmp_bPerdPctl_Ena = 1;
   }
   else
   {
      FuPmp_bPerdPctl_Ena = 0;
   }

   if (  (bLocalRcdEng == 0)
      && (bLocalClef_de_contact == 0))
   {
      FUPMPMNG_vidStopEngReqOrKeyOff();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidCtl                                            */
/* !Description :  Application de la précommande nominale suivi de la         */
/*                 périodique                                                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_07_01322_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st79 FuPmp_stCtl;                                                   */
/*  input boolean FuPmp_bPerdPctl_Ena;                                        */
/*  input uint8 Fuel_pump_counter;                                            */
/*  input boolean Fuel_pump_pre_control_active;                               */
/*  input boolean FuPmp_bafter_stall_ena;                                     */
/*  input uint16 Fuel_pump_delay;                                             */
/*  input boolean Fuel_pump_init_delay_ok;                                    */
/*  input uint16 Fuel_pump_short_delay;                                       */
/*  input uint16 Fuel_pump_off_delay;                                         */
/*  output st79 FuPmp_stCtl;                                                  */
/*  output uint16 Fuel_pump_delay;                                            */
/*  output boolean Commande_pompe_ess;                                        */
/*  output boolean FuPmp_bafter_stall_ena;                                    */
/*  output boolean Fuel_pump_pre_control_ok;                                  */
/*  output boolean Fuel_pump_init_delay_ok;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUPMPMNG_vidCtl(void)
{
   uint16 u16LocalFuelPumpDelay;
   sint32 s32LocalPumpDelay;


   switch (FuPmp_stCtl)
   {
      case FUPMP_NOM_WAIT:
         if (  (FuPmp_bPerdPctl_Ena != 0)
            && (Fuel_pump_counter == 0)
            && (Fuel_pump_pre_control_active != 0))
         {
            if (FuPmp_bafter_stall_ena != 0)
            {
               FuPmp_stCtl = FUPMP_STALL_PCTL;
               s32LocalPumpDelay = (sint32)(Fuel_pump_delay - 1);
               Fuel_pump_delay =
                  (uint16)MATHSRV_udtCLAMP(s32LocalPumpDelay, 0, 65000);
            }
            else
            {
               if (Fuel_pump_init_delay_ok != 0)
               {
                  FuPmp_stCtl = FUPMP_NOM_PCTL;
                  s32LocalPumpDelay = (sint32)(Fuel_pump_delay - 1);
                  Fuel_pump_delay =
                     (uint16)MATHSRV_udtCLAMP(s32LocalPumpDelay, 0, 65000);
               }
               else
               {
                  FuPmp_stCtl = FUPMP_KEY_ON_PCTL;
                  VEMS_vidSET(Commande_pompe_ess, 1);
                  u16LocalFuelPumpDelay =
                     (uint16)MATHSRV_udtCLAMP(Fuel_pump_short_delay, 1, 65000);
                  Fuel_pump_delay = (uint16)(u16LocalFuelPumpDelay - 1);
               }
            }
         }
         break;

      case FUPMP_STALL_PCTL:
         if (FuPmp_bPerdPctl_Ena == 0)
         {
            FuPmp_bafter_stall_ena = 0;
            Fuel_pump_delay = 0;
            FuPmp_stCtl = FUPMP_NOM_WAIT;
         }
         else
         {
            if (Fuel_pump_delay == 0)
            {
               FuPmp_bafter_stall_ena = 0;
               VEMS_vidSET(Commande_pompe_ess, 0);
               FuPmp_stCtl = FUPMP_REPOS;
               u16LocalFuelPumpDelay =
                  (uint16)MATHSRV_udtCLAMP(Fuel_pump_off_delay, 1, 65000);
               Fuel_pump_delay = (uint16)(u16LocalFuelPumpDelay - 1);
            }
            else
            {
               s32LocalPumpDelay = (sint32)(Fuel_pump_delay - 1);
               Fuel_pump_delay =
                  (uint16)MATHSRV_udtMIN(s32LocalPumpDelay, 65000);
            }
         }
         break;

      case FUPMP_NOM_PCTL:
         if (FuPmp_bPerdPctl_Ena == 0)
         {
            Fuel_pump_pre_control_ok = 0;
            Fuel_pump_init_delay_ok = 0;
            Fuel_pump_delay = 0;
            FuPmp_stCtl = FUPMP_NOM_WAIT;
         }
         else
         {
            if (Fuel_pump_delay == 0)
            {
               Fuel_pump_pre_control_ok = 0;
               Fuel_pump_init_delay_ok = 0;
               VEMS_vidSET(Commande_pompe_ess, 0);
               FuPmp_stCtl = FUPMP_REPOS;
               u16LocalFuelPumpDelay =
                  (uint16)MATHSRV_udtCLAMP(Fuel_pump_off_delay, 1, 65000);
               Fuel_pump_delay = (uint16)(u16LocalFuelPumpDelay - 1);
            }
            else
            {
               s32LocalPumpDelay = (sint32)(Fuel_pump_delay - 1);
               Fuel_pump_delay =
                  (uint16)MATHSRV_udtMIN(s32LocalPumpDelay, 65000);
            }
         }
         break;

      case FUPMP_REPOS:
         if (FuPmp_bPerdPctl_Ena == 0)
         {
            Fuel_pump_delay = 0;
            FuPmp_stCtl = FUPMP_NOM_WAIT;
         }
         else
         {
            if (Fuel_pump_delay == 0)
            {
               VEMS_vidSET(Commande_pompe_ess, 1);
               FuPmp_stCtl = FUPMP_COMMANDE;
               u16LocalFuelPumpDelay =
                  (uint16)MATHSRV_udtCLAMP(Fuel_pump_short_delay, 1, 65000);
               Fuel_pump_delay = (uint16)(u16LocalFuelPumpDelay - 1);
            }
            else
            {
               s32LocalPumpDelay = (sint32)(Fuel_pump_delay - 1);
               Fuel_pump_delay =
                  (uint16)MATHSRV_udtMIN(s32LocalPumpDelay, 65000);
            }
         }
         break;

      case FUPMP_COMMANDE:
         if (FuPmp_bPerdPctl_Ena == 0)
         {
            Fuel_pump_delay = 0;
            FuPmp_stCtl = FUPMP_NOM_WAIT;
         }
         else
         {
            if (Fuel_pump_delay == 0)
            {
               VEMS_vidSET(Commande_pompe_ess, 0);
               FuPmp_stCtl = FUPMP_REPOS;
               u16LocalFuelPumpDelay =
                  (uint16)MATHSRV_udtCLAMP(Fuel_pump_off_delay, 1, 65000);
               Fuel_pump_delay = (uint16)(u16LocalFuelPumpDelay - 1);
            }
            else
            {
               s32LocalPumpDelay = (sint32)(Fuel_pump_delay - 1);
               Fuel_pump_delay =
                  (uint16)MATHSRV_udtMIN(s32LocalPumpDelay, 65000);
            }
         }
         break;

      case FUPMP_KEY_ON_PCTL:
         if (FuPmp_bPerdPctl_Ena == 0)
         {
            Fuel_pump_delay = 0;
            FuPmp_stCtl = FUPMP_NOM_WAIT;
         }
         else
         {
            if (Fuel_pump_delay == 0)
            {
               VEMS_vidSET(Commande_pompe_ess, 0);
               FuPmp_stCtl = FUPMP_REPOS;
               u16LocalFuelPumpDelay =
                  (uint16)MATHSRV_udtCLAMP(Fuel_pump_off_delay, 1, 65000);
               Fuel_pump_delay = (uint16)(u16LocalFuelPumpDelay - 1);
            }
            else
            {
               s32LocalPumpDelay = (sint32)(Fuel_pump_delay - 1);
               Fuel_pump_delay =
                  (uint16)MATHSRV_udtMIN(s32LocalPumpDelay, 65000);
            }
         }
         break;
      default:
         FuPmp_stCtl = FUPMP_NOM_WAIT;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidEngineRunning                                  */
/* !Description :  La commande de la pompe est active en continue si le Régime*/
/*                   > Régime_seuil_1                                         */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_07_01322_005.01                                     */
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
void FUPMPMNG_vidEngineRunning(void)
{
   VEMS_vidSET(Commande_pompe_ess, 1);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUPMPMNG_vidStopEngReqOrKeyOff                             */
/* !Description :  Desactivation continue de la commande                      */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_07_01322_006.01                                     */
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
void FUPMPMNG_vidStopEngReqOrKeyOff(void)
{
   VEMS_vidSET(Commande_pompe_ess, 0);
}

/*------------------------------- end of file --------------------------------*/
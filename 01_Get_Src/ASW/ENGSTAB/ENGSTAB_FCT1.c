/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGSTAB                                                 */
/* !Description     : ENGSTAB component.                                      */
/*                                                                            */
/* !Module          : ENGSTAB                                                 */
/* !Description     : Engine Stabilised                                       */
/*                                                                            */
/* !File            : ENGSTAB_FCT1.C                                          */
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
/*   1 / ENGSTAB_vidInitEngineStabilised                                      */
/*   2 / ENGSTAB_vidCalcEngineStabilised                                      */
/*   3 / ENGSTAB_vidVehicleRunningCond                                        */
/*   4 / ENGSTAB_vidVehicleRunning                                            */
/*   5 / ENGSTAB_vidCheckEngineLoadStable                                     */
/*   6 / ENGSTAB_vidEngLoadTimer                                              */
/*   7 / ENGSTAB_vidEngLoadTimerOut                                           */
/*   8 / ENGSTAB_vidCheckGearEngagedStab                                      */
/*   9 / ENGSTAB_vidGearEngagedTimer                                          */
/*   10 / ENGSTAB_vidGearEngagedTimerOut                                      */
/*                                                                            */
/* !Reference   : V02 NT 09 03216 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ENGSTAB/ENGSTAB_FCT1.C_v          $*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   02 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   02 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ENGSTAB.h"
#include "ENGSTAB_L.h"
#include "ENGSTAB_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidInitEngineStabilised                            */
/* !Description :  Fonction qui permet la réinitialisation des variables      */
/*                 internes la à chaque reset du calculateur.                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Engine_stable_delay_c;                                        */
/*  input uint8 Gear_engaged_e_s_window_c;                                    */
/*  input uint8 Engine_load_e_s_window_c;                                     */
/*  output uint8 Engine_stable_t_d_c;                                         */
/*  output uint8 Gear_engaged_t_d_c;                                          */
/*  output uint8 Engine_load_t_d_c;                                           */
/*  output boolean Engine_stabilised;                                         */
/*  output boolean Engine_stabilised_eng_running;                             */
/*  output boolean Engine_load_not_stable;                                    */
/*  output boolean Gear_engaged_not_stable;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidInitEngineStabilised(void)
{
   Engine_stable_t_d_c = (uint8)MATHSRV_udtMIN(Engine_stable_delay_c, 100);
   Gear_engaged_t_d_c = (uint8)MATHSRV_udtMIN(Gear_engaged_e_s_window_c, 100);
   Engine_load_t_d_c = (uint8)MATHSRV_udtMIN(Engine_load_e_s_window_c, 100);
   VEMS_vidSET(Engine_stabilised, 0);
   Engine_stabilised_eng_running = 0;
   Engine_load_not_stable = 1;
   Gear_engaged_not_stable = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidCalcEngineStabilised                            */
/* !Description :  Fonction qui gère l’ensemble de la stratégie en fonction   */
/*                 des conditions véhicule.                                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTAB_vidVehicleRunningCond();                         */
/*  extf argret void ENGSTAB_vidVehicleRunning();                             */
/*  extf argret void ENGSTAB_vidVehicleNotRunning();                          */
/*  input boolean ENGSTAB_bVehicleRunning;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidCalcEngineStabilised(void)
{
   ENGSTAB_vidVehicleRunningCond();
   if (ENGSTAB_bVehicleRunning != 0)
   {
      ENGSTAB_vidVehicleRunning();
   }
   else
   {
      ENGSTAB_vidVehicleNotRunning();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidVehicleRunningCond                              */
/* !Description :  Fonction qui détermine l'état RUNNING du véhicule          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Engine_stabilised_eng_running;                              */
/*  output boolean ENGSTAB_bVehicleRunning;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidVehicleRunningCond(void)
{
   uint8 u8LocalVehicle_active_state;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   if (  (u8LocalVehicle_active_state == VS_RUNNING)
      || (Engine_stabilised_eng_running != 0))
   {
      ENGSTAB_bVehicleRunning = 1;
   }
   else
   {
      ENGSTAB_bVehicleRunning = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidVehicleRunning                                  */
/* !Description :  Les conditions de traitement de la variable                */
/*                 Engine_stabilised sont remplies, les sous systèmes         */
/*                 Check_gear_engaged_stable et Check_engine_load_stable      */
/*                 traitent les informations issues des variables Gear_engaged*/
/*                 et Engine_load.                                            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTAB_vidCheckEngineLoadStable();                      */
/*  extf argret void ENGSTAB_vidCheckGearEngagedStab();                       */
/*  extf argret void ENGSTAB_vidEngineConditions();                           */
/*  extf argret void ENGSTAB_vidEngineCondNotStable();                        */
/*  extf argret void ENGSTAB_vidEngineCondStable();                           */
/*  input boolean Engine_conditions;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidVehicleRunning(void)
{
   ENGSTAB_vidCheckEngineLoadStable();
   ENGSTAB_vidCheckGearEngagedStab();
   ENGSTAB_vidEngineConditions();
   if (Engine_conditions != 0)
   {
      ENGSTAB_vidEngineCondNotStable();
   }
   else
   {
      ENGSTAB_vidEngineCondStable();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidCheckEngineLoadStable                           */
/* !Description :  La variable Engine_load_not_stable passe à 0 si au bout du */
/*                 temps Engine_load_e_s_window_c la variable Engine_load n’a */
/*                 pas dépassé la valeur précédente +-                        */
/*                 Engine_load_e_s_limit_c.                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTAB_vidEngLoadTimerOut();                            */
/*  extf argret void ENGSTAB_vidEngLoadTimer();                               */
/*  input uint8 Engine_load_t_d_c;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidCheckEngineLoadStable(void)
{
   sint16 s16LocalEngineLoad;


   s16LocalEngineLoad = (sint16)(Engine_load_t_d_c - 1);
   if (s16LocalEngineLoad <= 0)
   {
      ENGSTAB_vidEngLoadTimerOut();
   }
   else
   {
      ENGSTAB_vidEngLoadTimer();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidEngLoadTimer                                    */
/* !Description :  Cette fonction représente un compteur décroissant.         */
/*                 EngStab_SampleTiMid_SC représente la période d’appel de la */
/*                 tache.                                                     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Engine_load_t_d_c;                                            */
/*  output uint8 Engine_load_t_d_c;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidEngLoadTimer(void)
{
   uint8 u8LocalEngineLoadTDC;


   if (Engine_load_t_d_c > 1)
   {
      u8LocalEngineLoadTDC = (uint8)(Engine_load_t_d_c - 1);
   }
   else
   {
      u8LocalEngineLoadTDC = 0;
   }
   Engine_load_t_d_c = (uint8)MATHSRV_udtMIN(u8LocalEngineLoadTDC, 100);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidEngLoadTimerOut                                 */
/* !Description :  Fonction qui permet la mise à 0 de la variable             */
/*                 Engine_load_not_stable dans le cas où le compteur est nul  */
/*                 et la variable Engine_load est comprise dans l’intervalle  */
/*                 Engine_load_last +- Engine_load_e_s_limit_c.               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Engine_load;                                                 */
/*  input uint8 Engine_load_e_s_window_c;                                     */
/*  input uint8 Engine_load_last;                                             */
/*  input uint8 Engine_load_e_s_limit_c;                                      */
/*  output uint8 Engine_load_t_d_c;                                           */
/*  output boolean Engine_load_not_stable;                                    */
/*  output uint8 Engine_load_last;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidEngLoadTimerOut(void)
{
   uint8  u8LocalEngineLoad;
   uint16 u16LocalEngineLoadDiff;
   uint16 u16LocalEngine_load;
   sint16 s16LocalEngineLoadDiff;


   VEMS_vidGET(Engine_load, u16LocalEngine_load);
   Engine_load_t_d_c = (uint8)MATHSRV_udtMIN(Engine_load_e_s_window_c, 100);
   u8LocalEngineLoad = (uint8)( ( u16LocalEngine_load * 200) / 65536);
   s16LocalEngineLoadDiff = (sint16)(u8LocalEngineLoad - Engine_load_last);
   u16LocalEngineLoadDiff = (uint16)MATHSRV_udtABS(s16LocalEngineLoadDiff);
   if (u16LocalEngineLoadDiff >= Engine_load_e_s_limit_c)
   {
      Engine_load_not_stable = 1;
   }
   else
   {
      Engine_load_not_stable = 0;
   }
   Engine_load_last = u8LocalEngineLoad;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidCheckGearEngagedStab                            */
/* !Description :  Fonction permettant la mise de la variable                 */
/*                 Gear_engaged_not_stable à 0 si au bout du temps            */
/*                 Gear_engaged_e_s_window_c, la variable Gear_engaged n’a pas*/
/*                 évolué.                                                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTAB_vidGearEngagedTimerOut();                        */
/*  extf argret void ENGSTAB_vidGearEngagedTimer();                           */
/*  input uint8 Gear_engaged_t_d_c;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidCheckGearEngagedStab(void)
{
   sint16 s16LocalGear_engaged_t_d_c;


   s16LocalGear_engaged_t_d_c = (sint16)(Gear_engaged_t_d_c - 1);
   if (s16LocalGear_engaged_t_d_c <= 0)
   {
      ENGSTAB_vidGearEngagedTimerOut();
   }
   else
   {
      ENGSTAB_vidGearEngagedTimer();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidGearEngagedTimer                                */
/* !Description :  Fonction représentant un compteur décroissant.             */
/*                 EngStab_SampleTiMid_SC représente la période d’appel de la */
/*                 tache.                                                     */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Gear_engaged_t_d_c;                                           */
/*  output uint8 Gear_engaged_t_d_c;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidGearEngagedTimer(void)
{
   uint8 u8LocalGearEngagedTDC;


   if (Gear_engaged_t_d_c > 1)
   {
      u8LocalGearEngagedTDC = (uint8)(Gear_engaged_t_d_c - 1);
   }
   else
   {
      u8LocalGearEngagedTDC = 0;
   }
   Gear_engaged_t_d_c = (uint8)MATHSRV_udtMIN(u8LocalGearEngagedTDC, 100);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTAB_vidGearEngagedTimerOut                             */
/* !Description :  Fonction permettant la mise de booléen                     */
/*                 gear_engaged_not_stable à 0, si au bout du temps           */
/*                 Gear_engaged_e_s_window_c la variable Gear_engaged n’a pas */
/*                 évolué.                                                    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Gear_engaged;                                                 */
/*  input uint8 Gear_engaged_e_s_window_c;                                    */
/*  input uint8 Gear_engaged_last;                                            */
/*  output uint8 Gear_engaged_t_d_c;                                          */
/*  output boolean Gear_engaged_not_stable;                                   */
/*  output uint8 Gear_engaged_last;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTAB_vidGearEngagedTimerOut(void)
{
   uint8 u8LocalGear_engaged;


   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);
   Gear_engaged_t_d_c = (uint8)MATHSRV_udtMIN(Gear_engaged_e_s_window_c, 100);
   if (u8LocalGear_engaged != Gear_engaged_last)
   {
      Gear_engaged_not_stable = 1;
   }
   else
   {
      Gear_engaged_not_stable = 0;
   }
   Gear_engaged_last = (uint8)MATHSRV_udtMIN(u8LocalGear_engaged, 5);
}

/*------------------------------- end of file --------------------------------*/
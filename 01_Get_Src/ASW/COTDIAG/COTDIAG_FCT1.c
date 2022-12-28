/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COTDIAG                                                 */
/* !Description     : COTDIAG Component.                                      */
/*                                                                            */
/* !Module          : COTDIAG                                                 */
/* !Description     : Diagnostic fonctionnel de la température d’eau.         */
/*                                                                            */
/* !File            : COTDIAG_FCT1.C                                          */
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
/*   1 / COTDIAG_vidInitOutput                                                */
/*   2 / COTDIAG_vidFunctDiagCoTempInit                                       */
/*   3 / COTDIAG_vidFunctDiagCoTemp                                           */
/*   4 / COTDIAG_vidInjCutoffTimeCalc                                         */
/*   5 / COTDIAG_vidTrackerCoTempCalc                                         */
/*   6 / COTDIAG_vidWarmUpTestEnd                                             */
/*   7 / COTDIAG_vidCalcMonRunIndicator                                       */
/*   8 / COTDIAG_vidCalcDgoIndicator                                          */
/*                                                                            */
/* !Reference   : V02 NT 09 00859 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/COTDIAG/COTDIAG_FCT1.C_v          $*/
/* $Revision::   1.4      $$Author::   croche2        $$Date::   15 Oct 2012 $*/
/* $Author::   croche2                                $$Date::   15 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "COTDIAG.h"
#include "COTDIAG_L.h"
#include "COTDIAG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COTDIAG_vidInitOutput                                      */
/* !Description :  Fonction d'initialisation des variables produites dans le  */
/*                 module.                                                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean CoT_bMonWaitWup_tCoMes;                                    */
/*  output boolean CoT_bDgoWup_tCoMes;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COTDIAG_vidInitOutput(void)
{
   /*F02_FctDiagCoT_Diag*/
   CoT_bMonWaitWup_tCoMes = 0;
   CoT_bDgoWup_tCoMes = 0;

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COTDIAG_vidFunctDiagCoTempInit                             */
/* !Description :  Cette fonction permet d’initialiser les variables au reset */
/*                 de l’ECU (CoT_EveRst_FctDiagCoT) et sur événement démarrage*/
/*                 moteur (CoT_EveCrTR_FctDiagCoT).                           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 Temperature_eau_a_stall;                                      */
/*  input uint8 CoT_tCoStallCoh_A[5];                                         */
/*  input uint8 CoT_tCoStallCohMinWup_T[5];                                   */
/*  input uint8 CoT_tCoStallCohThd;                                           */
/*  input uint8 Min_warmup_water_temp_hyst;                                   */
/*  output uint8 Injector_cut_off_counter;                                    */
/*  output uint8 Temperature_eau_tracker_value;                               */
/*  output uint8 CoT_tCoStallCohThd;                                          */
/*  output boolean Warmup_test_complete;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COTDIAG_vidFunctDiagCoTempInit(void)
{
   uint8  u8LocalTemperatureaustall;
   uint16 u16LocalCalcPara;
   sint16 s16LocalSum;
   sint16 s16LocalExt_tCoMes;

   Injector_cut_off_counter = 0;
   VEMS_vidSET(Temperature_eau_tracker_value, 0);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Temperature_eau_a_stall, u8LocalTemperatureaustall);
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU8(CoT_tCoStallCoh_A,
                                  u8LocalTemperatureaustall,
                                  5);
   CoT_tCoStallCohThd =
      MATHSRV_u8Interp1d(CoT_tCoStallCohMinWup_T, u16LocalCalcPara);
   s16LocalSum = (sint16)( (  (((CoT_tCoStallCohThd * 5) + 4) / 8)
                           +  Min_warmup_water_temp_hyst)
                         - 40);
   if (s16LocalExt_tCoMes > s16LocalSum)
   {
      Warmup_test_complete = 1;
   }
   else
   {
      Warmup_test_complete = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COTDIAG_vidFunctDiagCoTemp                                 */
/* !Description :  Cette fonction spécifie les diagnostics fonctionnels de la */
/*                 température d’eau moteur. Les calculs sont réalisés à      */
/*                 récurrence temporelle lente.                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COTDIAG_vidInjCutoffTimeCalc();                          */
/*  extf argret void COTDIAG_vidTrackerCoTempCalc();                          */
/*  extf argret void COTDIAG_vidCalcMonRunIndicator();                        */
/*  extf argret void COTDIAG_vidCalcDgoIndicator();                           */
/*  input boolean Warmup_test_complete;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COTDIAG_vidFunctDiagCoTemp(void)
{
   /*F01_FctDiagCoT_CutOffTmr*/
   COTDIAG_vidInjCutoffTimeCalc();

   if (Warmup_test_complete != 0)
   {
      /*F02_FctDiagCoT_TrckVal*/
      COTDIAG_vidTrackerCoTempCalc();
   }

   /*CoT_bMonRunWup_tCoMes and CoT_bMonRunTrck_tCoMes calculation*/
   COTDIAG_vidCalcMonRunIndicator();

   /*CoT_bDgoRunWup_tCoMes and CoT_bDgoTrck_tCoMes calculation*/
   COTDIAG_vidCalcDgoIndicator();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COTDIAG_vidInjCutoffTimeCalc                               */
/* !Description :  Cette fonction calcule le temps cumulé de fonctionnement en*/
/*                 mode coupure d’injection (Injector_cut_off_counter) et     */
/*                 active un booléen (Flag_delay_injection) lorsque le        */
/*                 compteur dépasse un seuil.                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Auto_injection;                                             */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 Wat_func_diag_max_vehicle_speed;                              */
/*  input uint8 Injector_cut_off_counter;                                     */
/*  input uint8 Wat_func_diag_cut_off_delay_min;                              */
/*  input uint8 Wat_func_diag_cut_off_delay_max;                              */
/*  input boolean Flag_delay_injection;                                       */
/*  output uint8 Injector_cut_off_counter;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COTDIAG_vidInjCutoffTimeCalc(void)
{
   boolean bLocalAuto_injection;
   uint8   u8LocalVitesse_vehicule;


   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);

   if (  (bLocalAuto_injection ==0)
      && (u8LocalVitesse_vehicule >= Wat_func_diag_max_vehicle_speed))
   {
      if (Injector_cut_off_counter < 255)
      {
         Injector_cut_off_counter = (uint8)(Injector_cut_off_counter + 1);
      }
   }
   else
   {
      if (Injector_cut_off_counter > 0)
      {
         Injector_cut_off_counter = (uint8)(Injector_cut_off_counter - 1);
      }
   }

   MATHSRV_vidSchmittTriggerU16((uint16)Injector_cut_off_counter,
                                (uint16)Wat_func_diag_cut_off_delay_min,
                                (uint16)Wat_func_diag_cut_off_delay_max,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &Flag_delay_injection);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COTDIAG_vidTrackerCoTempCalc                               */
/* !Description :  Cette fonction calcule  la  variable  suiveur  de          */
/*                 température  d’eau (Temperature_eau_tracker_value).        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 Wt_tracker_offset;                                            */
/*  input uint8 Wt_max_tracker_value;                                         */
/*  input uint8 Temperature_eau_tracker_value;                                */
/*  output uint8 Temperature_eau_tracker_value;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COTDIAG_vidTrackerCoTempCalc(void)
{
   uint8  u8LocalTempEauTrackval;
   sint16 s16LocalExt_tCoMes;
   sint32 s32LocalDifference;
   sint16 s16LocalMaxTrckVal;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   s32LocalDifference = (sint32)(s16LocalExt_tCoMes - Wt_tracker_offset);
   s16LocalMaxTrckVal = (sint16)(Wt_max_tracker_value - 40);
   s32LocalDifference = MATHSRV_udtMIN(s32LocalDifference,
                                               s16LocalMaxTrckVal);
   VEMS_vidGET(Temperature_eau_tracker_value, u8LocalTempEauTrackval);
   s16LocalMaxTrckVal = (sint16)(u8LocalTempEauTrackval - 40);
   s32LocalDifference = MATHSRV_udtMAX(s32LocalDifference,
                                               s16LocalMaxTrckVal);
   s32LocalDifference = (s32LocalDifference + 40);
   u8LocalTempEauTrackval = (uint8)MATHSRV_udtMIN(s32LocalDifference,
                                                  254);
   VEMS_vidSET(Temperature_eau_tracker_value, u8LocalTempEauTrackval);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COTDIAG_vidWarmUpTestEnd                                   */
/* !Description :  Cette fonction Active le booléen (Warmup_test_complete)    */
/*                 indiquant que  le Diagnostic  de la cohérence température  */
/*                 d’eau au démarrage est terminé.                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Warmup_test_complete;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COTDIAG_vidWarmUpTestEnd(void)
{
   Warmup_test_complete = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COTDIAG_vidCalcMonRunIndicator                             */
/* !Description :  Fonction qui calcule CoT_bMonRunWup_tCoMes et              */
/*                 CoT_bMonRunTrck_tCoMes.                                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Warmup_test_complete;                                       */
/*  output boolean CoT_bMonRunTrck_tCoMes;                                    */
/*  output boolean CoT_bMonRunWup_tCoMes;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COTDIAG_vidCalcMonRunIndicator(void)
{
   boolean bLocalInhFctDiagCoT;
   uint8   u8LocalVehicle_active_state;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   bLocalInhFctDiagCoT = GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGCOT);

   if (  (bLocalInhFctDiagCoT == 0)
      && (u8LocalVehicle_active_state == VS_RUNNING))
   {
      if (Warmup_test_complete != 0)
      {
         CoT_bMonRunTrck_tCoMes = 1;
         CoT_bMonRunWup_tCoMes = 0;
      }
      else
      {
         CoT_bMonRunTrck_tCoMes = 0;
         CoT_bMonRunWup_tCoMes = 1;
      }
   }
   else
   {
      CoT_bMonRunTrck_tCoMes = 0;
      CoT_bMonRunWup_tCoMes = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COTDIAG_vidCalcDgoIndicator                                */
/* !Description :  Fonction qui calcule CoT_bDgoWup_tCoMes et                 */
/*                 CoT_bDgoTrck_tCoMes.                                       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COTDIAG_vidWarmUpTestEnd();                              */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 Compteur_de_pmh;                                             */
/*  input uint8 Temperature_eau_tracker_value;                                */
/*  input boolean CoT_bMonRunTrck_tCoMes;                                     */
/*  input boolean Flag_delay_injection;                                       */
/*  input uint8 CoT_tCoStallCohThd;                                           */
/*  input uint8 Min_warmup_water_temp_hyst;                                   */
/*  input boolean CoT_bMonWaitWup_tCoMes;                                     */
/*  input boolean CoT_bMonRunWup_tCoMes;                                      */
/*  input uint16 Water_temp_warmup_delay;                                     */
/*  output boolean CoT_bDgoTrck_tCoMes;                                       */
/*  output boolean CoT_bMonWaitWup_tCoMes;                                    */
/*  output boolean CoT_bDgoWup_tCoMes;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COTDIAG_vidCalcDgoIndicator(void)
{
   boolean bLocalMonWaitWuptCoMesPrev;
   uint8   u8LocalTempEauTrackval;
   uint16  u16LocalCompteur_de_pmh;
   sint16  s16LocalSum;
   sint16  s16LocalComp;
   sint16  s16LocalExt_tCoMes;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Compteur_de_pmh, u16LocalCompteur_de_pmh);
   VEMS_vidGET(Temperature_eau_tracker_value, u8LocalTempEauTrackval);

   s16LocalComp = (sint16)(u8LocalTempEauTrackval - 40);
   if (  (CoT_bMonRunTrck_tCoMes != 0)
      && (s16LocalExt_tCoMes < s16LocalComp)
      && (Flag_delay_injection != 0))
   {
      CoT_bDgoTrck_tCoMes = 1;
   }
   else
   {
      CoT_bDgoTrck_tCoMes = 0;
   }

   /*((CoT_tCoStallCohThd * 625) / 1000) - 40 + Min_warmup_water_temp_hyst)*/
   s16LocalSum = (sint16)( ( (CoT_tCoStallCohThd * 5) - 316) / 8);
   s16LocalComp = (sint16)(s16LocalSum + Min_warmup_water_temp_hyst);

   bLocalMonWaitWuptCoMesPrev = CoT_bMonWaitWup_tCoMes;
   if (  (CoT_bMonRunWup_tCoMes != 0)
      && (s16LocalExt_tCoMes <= s16LocalComp)
      && (u16LocalCompteur_de_pmh <= Water_temp_warmup_delay))
   {
      CoT_bMonWaitWup_tCoMes = 1;
   }
   else
   {
      CoT_bMonWaitWup_tCoMes = 0;
   }

   if (  (CoT_bMonWaitWup_tCoMes == 0)
      && (bLocalMonWaitWuptCoMesPrev != 0))
   {
      /*F03_FctDiagCoT_EndWup*/
      COTDIAG_vidWarmUpTestEnd();
   }

   if (CoT_bMonRunWup_tCoMes == 0)
   {
      CoT_bDgoWup_tCoMes = 0;
   }
   else
   {
      if (CoT_bMonWaitWup_tCoMes == 0)
      {
         if (  (Flag_delay_injection != 0)
            && (s16LocalExt_tCoMes < s16LocalSum))
         {
            CoT_bDgoWup_tCoMes = 1;
         }
         else
         {
            CoT_bDgoWup_tCoMes = 0;
         }
      }
   }
}
/************************************* end of file ****************************/
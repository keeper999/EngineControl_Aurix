/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQAIRT                                                 */
/* !Description     : ACQAIRT component                                       */
/*                                                                            */
/* !Module          : ACQAIRT                                                 */
/* !Description     : MESURE DE LA TEMPERATURE D’AIR                          */
/*                                                                            */
/* !File            : ACQAIRT_FCT1.C                                          */
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
/*   1 / ACQAIRT_vidInitOutput                                                */
/*   2 / ACQAIRT_vidAirTemperatureAcqui                                       */
/*   3 / ACQAIRT_vidElectricFailDetection                                     */
/*   4 / ACQAIRT_vidResetAirIntakeTemp                                        */
/*   5 / ACQAIRT_vidAirTemperatureMeas                                        */
/*   6 / ACQAIRT_vidFunctionalDiagnosis                                       */
/*   7 / ACQAIRT_vidGradientTestParams                                        */
/*   8 / ACQAIRT_vidGradientTest                                              */
/*   9 / ACQAIRT_vidThrMesTempAir                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6535285 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACQAIRT/ACQAIRT_FCT1.c_v          $*/
/* $Revision::   1.9                                                         $*/
/* $Author::   achebino                               $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACQAIRT.h"
#include "ACQAIRT_L.h"
#include "ACQAIRT_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQAIRT_vidInitOutput                                      */
/* !Description :  initialisation des sorties.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 Temperature_air_mesuree_prev;                                */
/*  output boolean Ext_bDgoScp_tAirMes;                                       */
/*  output boolean Ext_bDgoOc_tAirMes;                                        */
/*  output boolean Ext_bDgoScg_tAirMes;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQAIRT_vidInitOutput(void)
{
   Temperature_air_mesuree_prev = 0;
   Ext_bDgoScp_tAirMes = 0;
   Ext_bDgoOc_tAirMes = 0;
   Ext_bDgoScg_tAirMes = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQAIRT_vidAirTemperatureAcqui                             */
/* !Description :  Temperature_air_mesuree qui correspond à la conversion du  */
/*                 signal électrique en une température d’air en °C. Ceci se  */
/*                 fait par le biais d’une cartographie avec points d’appui   */
/*                 calibrables.                                               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_03872_003.01                                     */
/*                 VEMS_R_08_03872_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACQAIRT_vidElectricFailDetection();                      */
/*  input uint16 Acq_tension_capt_temp_air;                                   */
/*  input uint16 Temp_air_result_ad_conv_bkpt_map[33];                        */
/*  input uint16 Table_temperature_air_linearisee[33];                        */
/*  input uint16 Tair_raw_range_voltage;                                      */
/*  output uint16 Temperature_air_result_ad_conv;                             */
/*  output boolean Ext_bMonRunScp_tAirMes;                                    */
/*  output boolean Ext_bMonRunOc_tAirMes;                                     */
/*  output boolean Ext_bMonRunScg_tAirMes;                                    */
/*  output uint16 Tair_raw_range_voltage;                                     */
/*  output uint8 Temperature_air_mesuree;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQAIRT_vidAirTemperatureAcqui(void)
{
   boolean bLocalInhAcqAirTElDiag;
   uint8   u8LocalTemperature_air_mesuree;
   uint16  u16LocalPara;
   uint16  u16LocalData;
   uint16  u16LocalAcq_tension_cap_temp_air;
   uint16  u16LocalTemp_air_result_ad_conv;


   bLocalInhAcqAirTElDiag = GDGAR_bGetFRM(FRM_FRM_INHACQAIRTELDIAG);

   VEMS_vidGET(Acq_tension_capt_temp_air, u16LocalAcq_tension_cap_temp_air);
   u16LocalData = (uint16)((uint32)(u16LocalAcq_tension_cap_temp_air + 2) / 4);
   u16LocalTemp_air_result_ad_conv = (uint16)MATHSRV_udtMIN(u16LocalData, 1024);
   VEMS_vidSET(Temperature_air_result_ad_conv, u16LocalTemp_air_result_ad_conv);

   if (bLocalInhAcqAirTElDiag == 0)
   {
      Ext_bMonRunScp_tAirMes = 1;
      Ext_bMonRunOc_tAirMes  = 1;
      Ext_bMonRunScg_tAirMes = 1;
      ACQAIRT_vidElectricFailDetection();
   }
   else
   {
      Ext_bMonRunScp_tAirMes = 0;
      Ext_bMonRunOc_tAirMes  = 0;
      Ext_bMonRunScg_tAirMes = 0;
   }

   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Temp_air_result_ad_conv_bkpt_map,
                                               u16LocalTemp_air_result_ad_conv,
                                               33);
   u16LocalData = MATHSRV_u16Interp1d(Table_temperature_air_linearisee,
                                      u16LocalPara);
   Tair_raw_range_voltage = (uint16)MATHSRV_udtMIN(u16LocalData, 65384);
   u16LocalData = (uint16)((Tair_raw_range_voltage * 13) / 3125 );
   u8LocalTemperature_air_mesuree = (uint8)MATHSRV_udtMIN(u16LocalData, 255);
   VEMS_vidSET(Temperature_air_mesuree, u8LocalTemperature_air_mesuree);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQAIRT_vidElectricFailDetection                           */
/* !Description :  detection des defauts electriques.                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_03872_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bDgoScp_tAirMes;                                        */
/*  input boolean Ext_bDgoOc_tAirMes;                                         */
/*  input boolean Ext_bDgoScg_tAirMes;                                        */
/*  input uint16 Temperature_air_result_ad_conv;                              */
/*  input uint16 Tension_air_seuil_cc1;                                       */
/*  input uint16 Tension_air_seuil_co;                                        */
/*  input uint16 Tension_air_seuil_cc0;                                       */
/*  output boolean ACQAIRT_bExtbDgoScptAirMesPrev;                            */
/*  output boolean ACQAIRT_bExtbDgoOctAirMesPrev;                             */
/*  output boolean ACQAIRT_bExtbDgoScgtAirMesPrev;                            */
/*  output boolean Ext_bDgoScp_tAirMes;                                       */
/*  output boolean Ext_bDgoOc_tAirMes;                                        */
/*  output boolean Ext_bDgoScg_tAirMes;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQAIRT_vidElectricFailDetection(void)
{
   uint16 u16LocalTemp_air_result_ad_conv;


   ACQAIRT_bExtbDgoScptAirMesPrev = Ext_bDgoScp_tAirMes;
   ACQAIRT_bExtbDgoOctAirMesPrev = Ext_bDgoOc_tAirMes;
   ACQAIRT_bExtbDgoScgtAirMesPrev = Ext_bDgoScg_tAirMes;
   VEMS_vidGET(Temperature_air_result_ad_conv, u16LocalTemp_air_result_ad_conv);
   if (u16LocalTemp_air_result_ad_conv > Tension_air_seuil_cc1)
   {
      Ext_bDgoScp_tAirMes = 1;
      Ext_bDgoOc_tAirMes = 0;
   }
   else
   {
      Ext_bDgoScp_tAirMes = 0;
      if (u16LocalTemp_air_result_ad_conv > Tension_air_seuil_co)
      {
         Ext_bDgoOc_tAirMes = 1;
      }
      else
      {
         Ext_bDgoOc_tAirMes = 0;
      }
   }
   if (u16LocalTemp_air_result_ad_conv < Tension_air_seuil_cc0)
   {
      Ext_bDgoScg_tAirMes = 1;
   }
   else
   {
      Ext_bDgoScg_tAirMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQAIRT_vidResetAirIntakeTemp                              */
/* !Description :  Cette initialisation est réalisée à la mise sous tension du*/
/*                 calculateur (RESET).                                       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_03872_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Temp_air_diag_grad_delay;                                     */
/*  input boolean Ext_bDgoScp_tAirMes;                                        */
/*  input boolean Ext_bDgoOc_tAirMes;                                         */
/*  input boolean Ext_bDgoScg_tAirMes;                                        */
/*  input uint8 Temperature_air_mesuree;                                      */
/*  input uint8 Temp_air_par_defaut;                                          */
/*  output uint8 Temp_air_diag_grad_count;                                    */
/*  output uint8 Temperature_air;                                             */
/*  output uint8 Temp_air_par_defaut;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQAIRT_vidResetAirIntakeTemp(void)
{
   boolean bLocalAcvMod_tAirMes;
   uint8   u8LocalTemperature_air_mesuree;


   bLocalAcvMod_tAirMes = GDGAR_bGetFRM(FRM_FRM_ACVMOD_TAIRMES);
   Temp_air_diag_grad_count = (uint8)MATHSRV_udtMIN(Temp_air_diag_grad_delay,
                                                    160);
   if (  (Ext_bDgoScp_tAirMes == 0)
      && (Ext_bDgoOc_tAirMes == 0)
      && (Ext_bDgoScg_tAirMes == 0)
      && (bLocalAcvMod_tAirMes == 0))
   {
      VEMS_vidGET(Temperature_air_mesuree,u8LocalTemperature_air_mesuree);
      VEMS_vidSET(Temperature_air,u8LocalTemperature_air_mesuree);
   }
   else
   {
      VEMS_vidSET(Temperature_air,Temp_air_par_defaut);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQAIRT_vidAirTemperatureMeas                              */
/* !Description :  Si le diagnostic électrique est correct, on effectue un    */
/*                 slew rate sur la température d’air, sinon on passe dans la */
/*                 gestion d’un mode défaut.                                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_03872_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bDgoScp_tAirMes;                                        */
/*  input boolean Ext_bDgoOc_tAirMes;                                         */
/*  input boolean Ext_bDgoScg_tAirMes;                                        */
/*  input boolean Ext_bDgoGrd_tAirMes;                                        */
/*  input uint8 Temperature_air;                                              */
/*  input uint8 Temperature_air_mesuree;                                      */
/*  input uint8 Temperature_air_slew_rate;                                    */
/*  input uint8 Temp_air_par_defaut;                                          */
/*  input uint8 Temperature_eau;                                              */
/*  output uint8 Temperature_air;                                             */
/*  output uint8 Temp_air_par_defaut;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQAIRT_vidAirTemperatureMeas(void)
{
   boolean FRM_bLocalAcvMod_tAirMes;
   boolean FRM_bLocalAcvMod_tCoMes;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalTemperature_air;
   uint8   u8LocalTemperature_air_mesuree;


   FRM_bLocalAcvMod_tAirMes = GDGAR_bGetFRM(FRM_FRM_ACVMOD_TAIRMES);
   if (  (Ext_bDgoScp_tAirMes == 0)
      && (Ext_bDgoOc_tAirMes == 0)
      && (Ext_bDgoScg_tAirMes == 0)
      && (FRM_bLocalAcvMod_tAirMes == 0)
      && (Ext_bDgoGrd_tAirMes == 0))
   {
      VEMS_vidGET(Temperature_air,u8LocalTemperature_air);
      VEMS_vidGET(Temperature_air_mesuree,u8LocalTemperature_air_mesuree);
      u8LocalTemperature_air = MATHSRV_u8SlewFilter(u8LocalTemperature_air,
                                                 u8LocalTemperature_air_mesuree,
                                                    Temperature_air_slew_rate,
                                                    Temperature_air_slew_rate);
      VEMS_vidSET(Temperature_air,u8LocalTemperature_air);
   }
   else
   {
      if (FRM_bLocalAcvMod_tAirMes != 0)
      {
         FRM_bLocalAcvMod_tCoMes = GDGAR_bGetFRM(FRM_FRM_ACVMOD_TCOMES);
         if (FRM_bLocalAcvMod_tCoMes != 0)
         {
            VEMS_vidSET(Temperature_air,Temp_air_par_defaut);
         }
         else
         {
            VEMS_vidGET(Temperature_eau,u8LocalTemperature_eau);
            u8LocalTemperature_air =
              (uint8)MATHSRV_udtMIN(u8LocalTemperature_eau,Temp_air_par_defaut);
            VEMS_vidSET(Temperature_air,u8LocalTemperature_air);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQAIRT_vidFunctionalDiagnosis                             */
/* !Description :  Le diagnostic fonctionnel est inhibé sur la demande de     */
/*                 reconfiguration issue du GAR.                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_03872_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQAIRT_vidGradientTestParams();                         */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void ACQAIRT_vidGradientTest();                               */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input boolean Ext_bDgoScp_tAirMes;                                        */
/*  input boolean Ext_bDgoOc_tAirMes;                                         */
/*  input boolean Ext_bDgoScg_tAirMes;                                        */
/*  input boolean ACQAIRT_bExtbDgoScptAirMesPrev;                             */
/*  input boolean ACQAIRT_bExtbDgoOctAirMesPrev;                              */
/*  input boolean ACQAIRT_bExtbDgoScgtAirMesPrev;                             */
/*  input boolean Autorise_diag_grad_air;                                     */
/*  output boolean Ext_bMonRunGrd_tAirMes;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQAIRT_vidFunctionalDiagnosis(void)
{
   boolean bLocalInhGrdMod_tAirMes;
   boolean bLocalIdlSys_bAcvIdlCtl;


   VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalIdlSys_bAcvIdlCtl);

   ACQAIRT_vidGradientTestParams();

   bLocalInhGrdMod_tAirMes = GDGAR_bGetFRM(FRM_FRM_INHGRDMOD_TAIRMES);
   if (  (bLocalIdlSys_bAcvIdlCtl != 0)
      && (Ext_bDgoScp_tAirMes == 0)
      && (Ext_bDgoOc_tAirMes == 0)
      && (Ext_bDgoScg_tAirMes == 0)
      && (ACQAIRT_bExtbDgoScptAirMesPrev == 0)
      && (ACQAIRT_bExtbDgoOctAirMesPrev == 0)
      && (ACQAIRT_bExtbDgoScgtAirMesPrev == 0)
      && (bLocalInhGrdMod_tAirMes == 0)
      && (Autorise_diag_grad_air != 0))
   {
      ACQAIRT_vidGradientTest();
      Ext_bMonRunGrd_tAirMes = 1;
   }
   else
   {
      Ext_bMonRunGrd_tAirMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQAIRT_vidGradientTestParams                              */
/* !Description :  Temperature_air_mesuree_prev doit être initialisée à la    */
/*                 valeur deTemperature_air_mesuree.                          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Temp_air_diag_grad_count;                                     */
/*  input uint8 Temperature_air_mesuree;                                      */
/*  input uint8 Temperature_air_mesuree_prev;                                 */
/*  output uint8 Temp_air_diag_grad_count;                                    */
/*  output boolean Autorise_diag_grad_air;                                    */
/*  output uint8 Temperature_air_mesuree_delta;                               */
/*  output uint8 Temperature_air_mesuree_prev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQAIRT_vidGradientTestParams(void)
{
   uint8  u8LocalTemperature_air_mesuree;
   sint16 s16LocalCalc;


   s16LocalCalc = (sint16)(Temp_air_diag_grad_count - 1);
   Temp_air_diag_grad_count = (uint8)MATHSRV_udtMAX(s16LocalCalc ,0);

   if (Temp_air_diag_grad_count == 0)
   {
      Autorise_diag_grad_air = 1;
   }
   else
   {
      Autorise_diag_grad_air = 0;
   }
   VEMS_vidGET(Temperature_air_mesuree, u8LocalTemperature_air_mesuree);
   s16LocalCalc = (sint16)( u8LocalTemperature_air_mesuree
                          - Temperature_air_mesuree_prev);
   Temperature_air_mesuree_delta = (uint8)MATHSRV_udtABS(s16LocalCalc);

   Temperature_air_mesuree_prev  = u8LocalTemperature_air_mesuree;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQAIRT_vidGradientTest                                    */
/* !Description :  Le test sur le gradient est effectué sur le signal         */
/*                 échantillonné. L'accroissement de la température d'air ne  */
/*                 doit pas être supérieur à une calibration (en °C/s).       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Temp_air_grad_thresh;                                         */
/*  input uint8 Temperature_air_mesuree_delta;                                */
/*  output boolean Ext_bDgoGrd_tAirMes;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQAIRT_vidGradientTest(void)
{
   uint16 u16LocalThresh;


   u16LocalThresh = (uint16)((Temp_air_grad_thresh * AirT_SampleTiMid_SC) / 64);
   if (Temperature_air_mesuree_delta > u16LocalThresh)
   {
      Ext_bDgoGrd_tAirMes = 1;
   }
   else
   {
      Ext_bDgoGrd_tAirMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQAIRT_vidThrMesTempAir                                   */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Température d’air mesurée après papillon au démarrage      */
/*                 (Ext_tDsThrstrtMes).                                       */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Temperature_air;                                              */
/*  output sint16 Ext_tDsThrStrtMes;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQAIRT_vidThrMesTempAir(void)
{
   uint8  u8LocalTemperature_air;
   sint16 s16LocalExtTDsThrStrtMes;


   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
   s16LocalExtTDsThrStrtMes = (sint16)( ( ( u8LocalTemperature_air
                                          * 5)
                                        - 320)
                                      / 8);
   VEMS_vidSET(Ext_tDsThrStrtMes, s16LocalExtTDsThrStrtMes);
}
/*-------------------------------- end of file -------------------------------*/
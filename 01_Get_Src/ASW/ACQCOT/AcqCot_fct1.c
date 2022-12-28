/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQCOT                                                  */
/* !Description     : ACQCOT Component                                        */
/*                                                                            */
/* !Module          : ACQCOT                                                  */
/* !Description     : ACQUISITION DE LA TEMPERATURE D’EAU                     */
/*                                                                            */
/* !File            : ACQCOT_FCT1.C                                           */
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
/*   1 / ACQCOT_vidInitialization                                             */
/*   2 / ACQCOT_vidWaterTempTreatment                                         */
/*   3 / ACQCOT_vidGradientTestParameters                                     */
/*   4 / ACQCOT_vidGradientTest                                               */
/*   5 / ACQCOT_vidTreatment                                                  */
/*   6 / ACQCOT_vidWaterFailure                                               */
/*   7 / ACQCOT_vidWaterTempAcquisition                                       */
/*   8 / ACQCOT_vidElecFailureDetection                                       */
/*   9 / ACQCOT_vidInitTemperature                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6529851 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACQCOT/ACQCOT_FCT1.c_v            $*/
/* $Revision::   1.11                                                        $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACQCOT.h"
#include "ACQCOT_L.h"
#include "ACQCOT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidInitialization                                   */
/* !Description :  Phases de vie et initialisation.                           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 index)boolean;                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Cts_raw_range_temp;                                          */
/*  input boolean Ext_bDgoScp_tCoMes;                                         */
/*  input boolean Ext_bDgoScg_tCoMes;                                         */
/*  input boolean Ext_bDgoOc_tCoMes;                                          */
/*  input boolean Ext_bDgoGrd_tCoMes;                                         */
/*  input uint8 Temperature_eau_mesuree;                                      */
/*  input uint8 Temperature_air;                                              */
/*  input uint8 Cts_global_failure_default_temp;                              */
/*  input uint16 Temp_eau_diag_grad_delay;                                    */
/*  input uint16 Temperature_eau_precise;                                     */
/*  output uint16 Temperature_eau_precise;                                    */
/*  output uint16 Temp_eau_diag_grad_count;                                   */
/*  output uint8 Temperature_eau;                                             */
/*  output uint8 Temperature_eau_a_stall;                                     */
/*  output uint16 Temperature_eau_mode_defaut;                                */
/*  output sint16 Ext_tCoMesFineResl;                                         */
/*  output sint16 Ext_tCoMesFineResl2;                                        */
/*  output sint16 Ext_tCoMes;                                                 */
/*  output sint16 Ext_tCoStrtMes;                                             */
/*  output uint8 Crank_to_run_water_temp;                                     */
/*  output uint16 Temperature_eau_precise_prev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidInitialization(void)
{
   boolean bLocalAcvMod_TAirMes;
   boolean bLocalAcvMod_TCoMes;
   uint8   u8LocalCrank_to_run_water_temp;
   uint8   u8LocalTemperature_air;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalTemperature_eau_a_stall;
   uint8   u8LocalTemperature_eau_mesuree;
   uint16  u16LocalCalc;
   uint16  u16LocalCrank_to_run_water_temp;
   uint16  u16LocalCts_raw_range_temp;
   uint16  u16LocalTemperature_eau_mode_def;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocalExt_tCoMesFineResl;
   sint16  s16LocalExt_tCoMesFineResl2;
   sint16  s16LocalExt_tCoStrtMes;


   VEMS_vidGET(Cts_raw_range_temp, u16LocalCts_raw_range_temp);
   bLocalAcvMod_TCoMes = GDGAR_bGetFRM(FRM_FRM_ACVMOD_TCOMES);
   if (  (Ext_bDgoScp_tCoMes == 0)
      && (Ext_bDgoScg_tCoMes == 0)
      && (Ext_bDgoOc_tCoMes == 0)
      && (bLocalAcvMod_TCoMes == 0)
      && (Ext_bDgoGrd_tCoMes == 0))
   {
      VEMS_vidGET(Temperature_eau_mesuree, u8LocalTemperature_eau_mesuree);
      u8LocalTemperature_eau = u8LocalTemperature_eau_mesuree;
      u8LocalTemperature_eau_a_stall = u8LocalTemperature_eau_mesuree;
      u16LocalTemperature_eau_mode_def =
         (uint16)(u8LocalTemperature_eau_mesuree * 256);
      s16LocalExt_tCoMesFineResl = (sint16)( ( u16LocalCts_raw_range_temp
                                             - 32768)
                                           / 32);
      s16LocalExt_tCoMes = (sint16)((u16LocalCts_raw_range_temp / 128) - 256);
      if (u16LocalCts_raw_range_temp > 27648)
      {
         u16LocalCrank_to_run_water_temp =
            (uint16)((u16LocalCts_raw_range_temp - 27648) / 80);
         u8LocalCrank_to_run_water_temp =
            (uint8)MATHSRV_udtMIN(u16LocalCrank_to_run_water_temp, 255);
      }
      else
      {
         u8LocalCrank_to_run_water_temp = 0;
      }
      Temperature_eau_precise = u16LocalCts_raw_range_temp;
   }
   else
   {
      bLocalAcvMod_TAirMes = GDGAR_bGetFRM(FRM_FRM_ACVMOD_TAIRMES);
      if (bLocalAcvMod_TAirMes == 0)
      {
         VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
         u8LocalTemperature_eau = u8LocalTemperature_air;
         u8LocalTemperature_eau_a_stall = u8LocalTemperature_air;
         u16LocalTemperature_eau_mode_def = (uint16)( u8LocalTemperature_air
                                                    * 256);
         s16LocalExt_tCoMesFineResl = (sint16)( ( (u8LocalTemperature_air * 5)
                                                - 320)
                                              / 2);
         s16LocalExt_tCoMes = (sint16)( ((5 * u8LocalTemperature_air) - 320)
                                      / 8);
         u8LocalCrank_to_run_water_temp = u8LocalTemperature_air;
         Temperature_eau_precise = (uint16)( (u8LocalTemperature_air * 80)
                                           + 27648);
      }
      else
      {
         u8LocalTemperature_eau = Cts_global_failure_default_temp;
         u8LocalTemperature_eau_a_stall = Cts_global_failure_default_temp;
         u16LocalTemperature_eau_mode_def =
           (uint16)(Cts_global_failure_default_temp * 256);
         s16LocalExt_tCoMesFineResl =
           (sint16)(((Cts_global_failure_default_temp * 5) - 320) / 2);
         s16LocalExt_tCoMes = (sint16)( ( (Cts_global_failure_default_temp * 5)
                                        - 320)
                                      / 8);
         u8LocalCrank_to_run_water_temp = Cts_global_failure_default_temp;
         Temperature_eau_precise = (uint16)( ( Cts_global_failure_default_temp
                                             * 80)
                                           + 27648);
      }
   }
   s16LocalExt_tCoMes = (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoMes, -40, 214);
   s16LocalExt_tCoStrtMes = s16LocalExt_tCoMes;
   if (s16LocalExt_tCoMesFineResl > 0)
   {
      s16LocalExt_tCoMesFineResl2 =
         (sint16)(((s16LocalExt_tCoMesFineResl * 5) + 1) / 2);
   }
   else
   {
      s16LocalExt_tCoMesFineResl2 =
         (sint16)(((s16LocalExt_tCoMesFineResl * 5) - 1) / 2);
   }
   s16LocalExt_tCoMesFineResl2 =
      (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoMesFineResl2, -500, 2000);
   s16LocalExt_tCoMesFineResl =
      (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoMesFineResl, -200, 800);
   u16LocalCalc = (uint16)(65000 / CoT_SampleTiMid_SC);
   Temp_eau_diag_grad_count = (uint16)MATHSRV_udtMIN( Temp_eau_diag_grad_delay,
                                                      u16LocalCalc);
   VEMS_vidSET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidSET(Temperature_eau_a_stall, u8LocalTemperature_eau_a_stall);
   VEMS_vidSET(Temperature_eau_mode_defaut, u16LocalTemperature_eau_mode_def);
   VEMS_vidSET(Ext_tCoMesFineResl, s16LocalExt_tCoMesFineResl);
   VEMS_vidSET(Ext_tCoMesFineResl2, s16LocalExt_tCoMesFineResl2);
   VEMS_vidSET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidSET(Ext_tCoStrtMes, s16LocalExt_tCoStrtMes);
   VEMS_vidSET(Crank_to_run_water_temp, u8LocalCrank_to_run_water_temp);
   Temperature_eau_precise_prev = Temperature_eau_precise;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidWaterTempTreatment                               */
/* !Description :  Traitement température d'eau.                              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 index)boolean;                      */
/*  extf argret void ACQCOT_vidTreatment();                                   */
/*  extf argret void ACQCOT_vidWaterFailure();                                */
/*  extf argret void ACQCOT_vidGradientTestParameters();                      */
/*  extf argret void ACQCOT_vidGradientTest();                                */
/*  input boolean Ext_bDgoScp_tCoMes;                                         */
/*  input boolean Ext_bDgoScg_tCoMes;                                         */
/*  input boolean Ext_bDgoOc_tCoMes;                                          */
/*  input boolean Ext_bDgoGrd_tCoMes;                                         */
/*  input boolean ACQCOT_bExtbDgoOctCoMesPrev;                                */
/*  input boolean ACQCOT_bExtbDgoScgtCoMesPrev;                               */
/*  input boolean ACQCOT_bExtbDgoScptCoMesPrev;                               */
/*  input boolean Autorise_diag_grad;                                         */
/*  output boolean Ext_bMonRunGrd_tCoMes;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidWaterTempTreatment(void)
{
   boolean FRM_bLocalAcvMod_TCoMes;
   boolean FRM_bLocalInjGrdMod_TCoMes;


   FRM_bLocalAcvMod_TCoMes = GDGAR_bGetFRM (FRM_FRM_ACVMOD_TCOMES);
   if (FRM_bLocalAcvMod_TCoMes != 0)
   {
      ACQCOT_vidTreatment();
   }
   else
   {
      if (  (Ext_bDgoScp_tCoMes == 0)
         && (Ext_bDgoScg_tCoMes == 0)
         && (Ext_bDgoOc_tCoMes == 0)
         && (Ext_bDgoGrd_tCoMes == 0))
      {
         ACQCOT_vidWaterFailure();
      }
   }
   ACQCOT_vidGradientTestParameters();
   FRM_bLocalInjGrdMod_TCoMes = GDGAR_bGetFRM (FRM_FRM_INHGRDMOD_TCOMES);
   if (  (Ext_bDgoScp_tCoMes == 0)
      && (Ext_bDgoScg_tCoMes == 0)
      && (Ext_bDgoOc_tCoMes == 0)
      && (ACQCOT_bExtbDgoOctCoMesPrev == 0)
      && (ACQCOT_bExtbDgoScgtCoMesPrev == 0)
      && (ACQCOT_bExtbDgoScptCoMesPrev == 0)
      && (FRM_bLocalInjGrdMod_TCoMes == 0)
      && (Autorise_diag_grad != 0))
   {
      ACQCOT_vidGradientTest();
      Ext_bMonRunGrd_tCoMes = 1;
   }
   else
   {
      Ext_bMonRunGrd_tCoMes = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidGradientTestParameters                           */
/* !Description :  Tester les parametres gradient                             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Temperature_eau_mesuree;                                      */
/*  input uint16 Temp_eau_diag_grad_count;                                    */
/*  input uint8 ACQCOT_u8TempEauMesureePrev;                                  */
/*  output uint16 Temp_eau_diag_grad_count;                                   */
/*  output boolean Autorise_diag_grad;                                        */
/*  output uint8 Temperature_eau_mesuree_delta;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidGradientTestParameters(void)
{
   uint8  u8LocalTemperature_eau_mesuree;
   uint16 u16LocalDiagGradCount;
   sint16 s16LocalTemp;


   VEMS_vidGET(Temperature_eau_mesuree, u8LocalTemperature_eau_mesuree);
   if (Temp_eau_diag_grad_count > 0)
   {
      u16LocalDiagGradCount = (uint16)(Temp_eau_diag_grad_count - 1);
      Temp_eau_diag_grad_count = (uint16)MATHSRV_udtMIN( u16LocalDiagGradCount,
                                                         325);
   }
   if (Temp_eau_diag_grad_count == 0)
   {
      Autorise_diag_grad = 1;
   }
   else
   {
      Autorise_diag_grad = 0;
   }
   s16LocalTemp = (sint16)( u8LocalTemperature_eau_mesuree
                          - ACQCOT_u8TempEauMesureePrev);
   Temperature_eau_mesuree_delta = (uint8)MATHSRV_udtABS(s16LocalTemp);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidGradientTest                                     */
/* !Description :  Le défaut unitaire est détecté si le delta de température  */
/*                 d'eau est supérieur à un seuil.                            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Temperature_eau_mesuree_delta;                                */
/*  input uint8 Temp_eau_grad_thresh;                                         */
/*  output boolean Ext_bDgoGrd_tCoMes;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidGradientTest(void)
{
   if (Temperature_eau_mesuree_delta > Temp_eau_grad_thresh)
   {
      Ext_bDgoGrd_tCoMes = 1;
   }
   else
   {
      Ext_bDgoGrd_tCoMes = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidTreatment                                        */
/* !Description :  traitement des données.                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 index)boolean;                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint16 Temperature_eau_mode_defaut;                                 */
/*  input uint8 Cts_default_coolant_temp;                                     */
/*  input uint16 Temperature_eau_mode_defaut_step;                            */
/*  input boolean Cranking_retry;                                             */
/*  input uint8 Temperature_air;                                              */
/*  input uint8 Cts_global_failure_default_temp;                              */
/*  output sint16 Ext_tCoMesFineResl;                                         */
/*  output sint16 Ext_tCoMesFineResl2;                                        */
/*  output sint16 Ext_tCoMes;                                                 */
/*  output uint16 Temperature_eau_mode_defaut;                                */
/*  output uint8 Temperature_eau;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidTreatment(void)
{
   boolean FRM_bLocalAcvMod_TAirMes;
   boolean bLocalCranking_retry;
   uint8   u8LocalTemperature_air;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalTemperature_eau_mode_def;
   uint16  u16LocalCts_defaultCoolantTemp;
   sint16  s16LocalExt_tCoMesFineResl;
   sint16  s16LocalExt_tCoMesFineResl2;
   sint16  s16LocalExt_tCoMes;
   sint32  s32Local;
   sint32  s32LocalScal;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   if (u8LocalVehicle_active_state == VS_RUNNING)
   {
      VEMS_vidGET( Temperature_eau_mode_defaut,
                   u16LocalTemperature_eau_mode_def);
      u16LocalCts_defaultCoolantTemp = (uint16)(Cts_default_coolant_temp * 256);
      if (u16LocalTemperature_eau_mode_def == u16LocalCts_defaultCoolantTemp)
      {
         s32Local = (sint32)u16LocalTemperature_eau_mode_def;
      }
      else
      {
         VEMS_vidGET(Temperature_eau_mode_defaut,
                     u16LocalTemperature_eau_mode_def);
         if ( u16LocalTemperature_eau_mode_def > u16LocalCts_defaultCoolantTemp)
         {
            s32Local = (sint32)( u16LocalTemperature_eau_mode_def
                               - Temperature_eau_mode_defaut_step);
         }
         else
         {
            s32Local = (sint32)( u16LocalTemperature_eau_mode_def
                               + Temperature_eau_mode_defaut_step);
         }
      }
   }
   else
   {
      VEMS_vidGET(Cranking_retry, bLocalCranking_retry);
      VEMS_vidGET(Temperature_eau_mode_defaut,
                  u16LocalTemperature_eau_mode_def);
      if (bLocalCranking_retry != 0)
      {
         s32Local = (sint32)u16LocalTemperature_eau_mode_def;
      }
      else
      {
         FRM_bLocalAcvMod_TAirMes = GDGAR_bGetFRM(FRM_FRM_ACVMOD_TAIRMES);
         if (FRM_bLocalAcvMod_TAirMes == 0)
         {
            VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
            s32Local = (sint32)(u8LocalTemperature_air * 256);
         }
         else
         {
            s32Local = (sint32)(Cts_global_failure_default_temp * 256);
         }
      }
   }
   s32LocalScal = ((s32Local * 5) - 81920) / 512;
   s16LocalExt_tCoMesFineResl = (sint16)MATHSRV_udtCLAMP(s32LocalScal,
                                                         -200,
                                                         800);
   VEMS_vidSET(Ext_tCoMesFineResl, s16LocalExt_tCoMesFineResl);
   s32LocalScal = (s32LocalScal * 5) / 2;
   s16LocalExt_tCoMesFineResl2 = (sint16)MATHSRV_udtCLAMP(s32LocalScal,
                                                          -500,
                                                          2000);
   VEMS_vidSET(Ext_tCoMesFineResl2, s16LocalExt_tCoMesFineResl2);
   s32LocalScal = ((s32Local * 5) - 81920) / 2048;
   s16LocalExt_tCoMes = (sint16)MATHSRV_udtCLAMP(s32LocalScal, -40, 214);
   VEMS_vidSET(Ext_tCoMes, s16LocalExt_tCoMes);

   u16LocalTemperature_eau_mode_def = (uint16)MATHSRV_udtCLAMP(s32Local,
                                                               0,
                                                               65535);
   VEMS_vidSET(Temperature_eau_mode_defaut, u16LocalTemperature_eau_mode_def);
   s32LocalScal = s32Local / 256;
   u8LocalTemperature_eau = (uint8)MATHSRV_udtCLAMP(s32LocalScal, 0, 255);
   VEMS_vidSET(Temperature_eau, u8LocalTemperature_eau);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidWaterFailure                                     */
/* !Description :  La temperature d'eau Ext_tCoMes est limitée par un slew    */
/*                 rate configuré à 1 C.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Cts_raw_range_temp;                                          */
/*  input uint16 Temperature_eau_precise;                                     */
/*  input uint16 Temperature_eau_precise_prev;                                */
/*  output uint16 Temperature_eau_precise_prev;                               */
/*  output uint16 Temperature_eau_precise;                                    */
/*  output sint16 Ext_tCoMes;                                                 */
/*  output uint8 Temperature_eau;                                             */
/*  output uint16 Temperature_eau_mode_defaut;                                */
/*  output sint16 Ext_tCoMesFineResl;                                         */
/*  output sint16 Ext_tCoMesFineResl2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidWaterFailure(void)
{
   uint8  u8LocalTemperature_eau;
   uint16 u16LocalCts_raw_range_temp;
   uint16 u16LocalTemperature_eau_mode_def;
   sint16 s16LocalExt_tCoMes;
   sint16 s16LocalTemperature_eau1;
   sint16 s16LocalExt_tCoMesFineResl;
   sint16 s16LocalExt_tCoMesFineResl2;
   sint16 s16LocalExt_tCoMes1;
   sint32 s32LocalTemperature_eau_modeDef;


   VEMS_vidGET(Cts_raw_range_temp, u16LocalCts_raw_range_temp);
   Temperature_eau_precise_prev = Temperature_eau_precise;
   Temperature_eau_precise = MATHSRV_u16SlewFilter(Temperature_eau_precise_prev,
                                                   u16LocalCts_raw_range_temp,
                                                   (uint16)CTS_RAW_RESOL,
                                                   (uint16)CTS_RAW_RESOL);
   s16LocalExt_tCoMes1 = (sint16)( ( ( Temperature_eau_precise
                                     - 32768)
                                   + 64)
                                 / 128);
   s16LocalExt_tCoMes = (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoMes1, -40, 214);
   VEMS_vidSET(Ext_tCoMes, s16LocalExt_tCoMes);
   s16LocalTemperature_eau1 = (sint16)( ( ( Temperature_eau_precise
                                          - 27648)
                                        + 40)
                                      / 80);
   u8LocalTemperature_eau = (uint8)MATHSRV_udtCLAMP(s16LocalTemperature_eau1,
                                                    0,
                                                    255);
   VEMS_vidSET(Temperature_eau, u8LocalTemperature_eau);

   s32LocalTemperature_eau_modeDef =
      (sint32)(((Temperature_eau_precise * 16) - 442368) / 5);

   u16LocalTemperature_eau_mode_def =
      (uint16)MATHSRV_udtCLAMP(s32LocalTemperature_eau_modeDef, 0, 65535);
   VEMS_vidSET(Temperature_eau_mode_defaut, u16LocalTemperature_eau_mode_def);
   s16LocalExt_tCoMesFineResl = (sint16)( ( ( Temperature_eau_precise
                                            - 32768)
                                          + 16)
                                        / 32);
   s16LocalExt_tCoMesFineResl2 =
      (sint16)((s16LocalExt_tCoMesFineResl * 5) / 2);
   s16LocalExt_tCoMesFineResl =
      (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoMesFineResl, -200, 800);
   VEMS_vidSET(Ext_tCoMesFineResl, s16LocalExt_tCoMesFineResl);
   s16LocalExt_tCoMesFineResl2 =
      (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoMesFineResl2, -500, 2000);
   VEMS_vidSET(Ext_tCoMesFineResl2, s16LocalExt_tCoMesFineResl2);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidWaterTempAcquisition                             */
/* !Description :  Acquisition température d'eau.                             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_007.01                                     */
/*                 VEMS_R_08_03873_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 index)boolean;                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACQCOT_vidElecFailureDetection();                        */
/*  input uint8 Temperature_eau_mesuree;                                      */
/*  input uint16 Acq_tension_capt_temp_eau;                                   */
/*  input uint16 Cts_range_conv_bkpt_map[33];                                 */
/*  input uint16 Cts_range_conv_map[33];                                      */
/*  output uint8 ACQCOT_u8TempEauMesureePrev;                                 */
/*  output uint16 Cts_range_voltage;                                          */
/*  output boolean Ext_bMonRunScp_tCoMes;                                     */
/*  output boolean Ext_bMonRunOc_tCoMes;                                      */
/*  output boolean Ext_bMonRunScg_tCoMes;                                     */
/*  output uint8 Temperature_eau_mesuree;                                     */
/*  output uint16 Cts_raw_range_temp;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidWaterTempAcquisition(void)
{
   boolean bLocalInhAcqCoTElDiag;
   uint8   u8LocalTemperature_eau_mesuree;
   uint16  u16Local;
   uint16  u16LocalCalcPara;
   uint16  u16LocalCalcInterp;
   uint16  u16LocalCts_raw_range_temp;
   uint16  u16LocalCts_range_voltage;
   uint16  u16LocalAcqtensioncapt_temp_eau;
   uint16  u16LocalData;


   VEMS_vidGET(Temperature_eau_mesuree, u8LocalTemperature_eau_mesuree);
   VEMS_vidGET(Acq_tension_capt_temp_eau, u16LocalAcqtensioncapt_temp_eau);

   ACQCOT_u8TempEauMesureePrev = u8LocalTemperature_eau_mesuree;
   bLocalInhAcqCoTElDiag = GDGAR_bGetFRM(FRM_FRM_INHACQCOTELDIAG);
   u16LocalData = (uint16)((uint32)(u16LocalAcqtensioncapt_temp_eau + 2) / 4);
   u16LocalCts_range_voltage = (uint16)MATHSRV_udtMIN(u16LocalData, 1024);
   VEMS_vidSET(Cts_range_voltage, u16LocalCts_range_voltage);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Cts_range_conv_bkpt_map,
                                                   u16LocalCts_range_voltage,
                                                   33);
   u16LocalCalcInterp = MATHSRV_u16Interp1d(Cts_range_conv_map,
                                            u16LocalCalcPara);
   u16LocalCts_raw_range_temp = u16LocalCalcInterp;
   if (u16LocalCts_raw_range_temp > 27648)
   {
      u16Local = (uint16)((u16LocalCts_raw_range_temp - 27648) / 80);
      u8LocalTemperature_eau_mesuree = (uint8)MATHSRV_udtMIN(u16Local, 255);
   }
   else
   {
      u8LocalTemperature_eau_mesuree = 0;
   }

   if (bLocalInhAcqCoTElDiag == 0)
   {
      Ext_bMonRunScp_tCoMes = 1;
      Ext_bMonRunOc_tCoMes = 1;
      Ext_bMonRunScg_tCoMes = 1;
      ACQCOT_vidElecFailureDetection();
   }
   else
   {
      Ext_bMonRunScp_tCoMes = 0;
      Ext_bMonRunOc_tCoMes = 0;
      Ext_bMonRunScg_tCoMes = 0;
   }

   VEMS_vidSET(Temperature_eau_mesuree, u8LocalTemperature_eau_mesuree);
   VEMS_vidSET(Cts_raw_range_temp, u16LocalCts_raw_range_temp);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidElecFailureDetection                             */
/* !Description :  Inhibtion des diagnostics électriques.                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Cts_range_voltage;                                           */
/*  input boolean Ext_bDgoScg_tCoMes;                                         */
/*  input uint16 Cts_sc0_failure_thresh;                                      */
/*  input boolean Ext_bDgoScp_tCoMes;                                         */
/*  input uint16 Cts_sc1_failure_thresh;                                      */
/*  input boolean Ext_bDgoOc_tCoMes;                                          */
/*  input uint16 Cts_oc_failure_thresh;                                       */
/*  output boolean ACQCOT_bExtbDgoScgtCoMesPrev;                              */
/*  output boolean Ext_bDgoScg_tCoMes;                                        */
/*  output boolean ACQCOT_bExtbDgoScptCoMesPrev;                              */
/*  output boolean Ext_bDgoScp_tCoMes;                                        */
/*  output boolean ACQCOT_bExtbDgoOctCoMesPrev;                               */
/*  output boolean Ext_bDgoOc_tCoMes;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidElecFailureDetection(void)
{
   uint16 u16LocalCts_range_voltage;


   VEMS_vidGET(Cts_range_voltage, u16LocalCts_range_voltage);

   ACQCOT_bExtbDgoScgtCoMesPrev = Ext_bDgoScg_tCoMes;
   if (u16LocalCts_range_voltage <= Cts_sc0_failure_thresh)
   {
      Ext_bDgoScg_tCoMes = 1;
   }
   else
   {
      Ext_bDgoScg_tCoMes = 0;
   }
   ACQCOT_bExtbDgoScptCoMesPrev = Ext_bDgoScp_tCoMes;
   if (u16LocalCts_range_voltage >= Cts_sc1_failure_thresh)
   {
      Ext_bDgoScp_tCoMes = 1;
   }
   else
   {
      Ext_bDgoScp_tCoMes = 0;
   }
   ACQCOT_bExtbDgoOctCoMesPrev = Ext_bDgoOc_tCoMes;
   if (  (Ext_bDgoScp_tCoMes == 0)
      && (u16LocalCts_range_voltage >= Cts_oc_failure_thresh))
   {
      Ext_bDgoOc_tCoMes = 1;
   }
   else
   {
      Ext_bDgoOc_tCoMes = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCOT_vidInitTemperature                                  */
/* !Description :  Init function.                                             */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_bDgoGrd_tCoMes;                                        */
/*  output uint8 Temperature_eau_mesuree;                                     */
/*  output uint8 ACQCOT_u8TempEauMesureePrev;                                 */
/*  output boolean ACQCOT_bExtbDgoOctCoMesPrev;                               */
/*  output boolean ACQCOT_bExtbDgoScgtCoMesPrev;                              */
/*  output boolean ACQCOT_bExtbDgoScptCoMesPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCOT_vidInitTemperature(void)
{
   Ext_bDgoGrd_tCoMes = 0;
   VEMS_vidSET(Temperature_eau_mesuree, 0);
   ACQCOT_u8TempEauMesureePrev = 0;
   ACQCOT_bExtbDgoOctCoMesPrev = 0;
   ACQCOT_bExtbDgoScgtCoMesPrev = 0;
   ACQCOT_bExtbDgoScptCoMesPrev = 0;
}
/*------------------------------- end of file --------------------------------*/
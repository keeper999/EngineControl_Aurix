/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRPOSMES                                               */
/* !Description     : THRPOSMES component.                                    */
/*                                                                            */
/* !Module          : THRPOSMES                                               */
/* !Description     : Mesure de la position Papillon.                         */
/*                                                                            */
/* !File            : THRPOSMES_FCT1.c                                        */
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
/*   1 / THRPOSMES_vidInitOutput                                              */
/*   2 / THRPOSMES_vidVoltageFilter                                           */
/*   3 / THRPOSMES_vidAcqPosition1                                            */
/*   4 / THRPOSMES_vidAcqPosition2                                            */
/*   5 / THRPOSMES_vidTpsPosTolerance                                         */
/*   6 / THRPOSMES_vidDiagElecCohPosSnsr                                      */
/*   7 / THRPOSMES_vidDiagElec                                                */
/*   8 / THRPOSMES_vidDiagDisable                                             */
/*   9 / THRPOSMES_vidDiagElecPosRange                                        */
/*   10 / THRPOSMES_vidDiagOcPosSnsr2                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6658623 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#068658                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRPOSMES/THRPOSMES_FCT1.c_v  $*/
/* $Revision::   1.12                                                        $*/
/* $Author::   wbouach                                $$Date::   02 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRPOSMES.h"
#include "THRPOSMES_L.h"
#include "THRPOSMES_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidInitOutput                                    */
/* !Description :  Module initialization                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input uint16 Tps_tension_alim_thr_init;                                   */
/*  output boolean Enable_diag_panne_tps_2_basse;                             */
/*  output uint16 Tps_1_ratio_meas_position;                                  */
/*  output uint16 Tps_2_ratio_meas_position;                                  */
/*  output boolean Thr_bDftSftyCohPosnSnsr;                                   */
/*  output boolean Thr_bDftSftyScgPosnSnsr1;                                  */
/*  output boolean Thr_bDftSftyScgPosnSnsr2;                                  */
/*  output boolean Thr_bDftSftyScpPosnSnsr1;                                  */
/*  output boolean Thr_bDftSftyScpPosnSnsr2;                                  */
/*  output boolean Thr_bAuthDiagInhThr_CpuSfty;                               */
/*  output uint16 Tension_alimentation_thr_filtree;                           */
/*  output uint32 THRPOSMES_u32VoltFilterMem;                                 */
/*  output uint16 Tps_coh_filt_abs_error;                                     */
/*  output uint32 THRPOSMES_u32AccuFilterMem;                                 */
/*  output boolean THRPOSMES_bTpsSensDefDiagEnaPrev;                          */
/*  output boolean Thr_bMonRunCohPosnSnsr;                                    */
/*  output boolean Thr_bMonRunScpPosnSnsr1;                                   */
/*  output boolean Thr_bMonRunScgPosnSnsr1;                                   */
/*  output boolean Thr_bMonRunScpPosnSnsr2;                                   */
/*  output boolean Thr_bMonRunScgPosnSnsr2;                                   */
/*  output uint8 THRPOSMES_u8CntFilt_1;                                       */
/*  output uint8 THRPOSMES_u8CountNiv2_1;                                     */
/*  output uint8 THRPOSMES_u8CntFilt_2;                                       */
/*  output uint8 THRPOSMES_u8CountNiv2_2;                                     */
/*  output uint8 THRPOSMES_u8CntFilt_3;                                       */
/*  output uint8 THRPOSMES_u8CountNiv2_3;                                     */
/*  output uint8 THRPOSMES_u8CntFilt_4;                                       */
/*  output uint8 THRPOSMES_u8CountNiv2_4;                                     */
/*  output uint8 THRPOSMES_u8CntFilt_5;                                       */
/*  output uint8 THRPOSMES_u8CountNiv2_5;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidInitOutput(void)
{
   boolean bLocalInhThrPosnMesElDiag;
   uint32  u32LocalVoltage;


   /* !Comment: Module outputs initialization                                 */
   VEMS_vidSET(Enable_diag_panne_tps_2_basse, 0);
   VEMS_vidSET(Tps_1_ratio_meas_position, 0);
   VEMS_vidSET(Tps_2_ratio_meas_position, 0);
   VEMS_vidSET(Thr_bDftSftyCohPosnSnsr, 0);
   VEMS_vidSET(Thr_bDftSftyScgPosnSnsr1, 0);
   VEMS_vidSET(Thr_bDftSftyScgPosnSnsr2, 0);
   VEMS_vidSET(Thr_bDftSftyScpPosnSnsr1, 0);
   VEMS_vidSET(Thr_bDftSftyScpPosnSnsr2, 0);
   VEMS_vidSET(Thr_bAuthDiagInhThr_CpuSfty, 0);
   /* !Comment: Block 0_filtrage_tension                                      */
   /* !Comment: Filred voltage initialization                                 */
   u32LocalVoltage = (uint32)(4 * Tps_tension_alim_thr_init);
   Tension_alimentation_thr_filtree =
      (uint16)MATHSRV_udtMIN(u32LocalVoltage, 65535);

   /* !Comment: the pu32AccuracyFilterValue is:                               */
   /*           the previous u16MesuredValue * 256 of the filter.             */
   THRPOSMES_u32VoltFilterMem = 262140 * 256;

   /* !Comment: Block Comptage_panne_TPS_COH                                  */
   /* !Comment: First order filter initialization of absolute error           */
   Tps_coh_filt_abs_error = 0;
   THRPOSMES_u32AccuFilterMem = 0;

   /* !Comment: Block 4_Comptage_pannes_mesures_Tps                           */
   /* !Comment: Previous value initialization                                 */
   THRPOSMES_bTpsSensDefDiagEnaPrev = 0;

   /* !Comment: Block Comptage_panne_TPS_COH & 4_Comptage_pannes_mesures_Tps  */
   /* !Comment: Diagnosis flags initialization if inhibition flag             */
   /*           FRM_bInhThrPosnMesElDiag is set to TRUE                       */
   bLocalInhThrPosnMesElDiag = GDGAR_bGetFRM(FRM_FRM_INHTHRPOSNMESELDIAG);
   if (bLocalInhThrPosnMesElDiag != 0)
   {
      Thr_bMonRunCohPosnSnsr = 0;
      Thr_bMonRunScpPosnSnsr1 = 0;
      Thr_bMonRunScgPosnSnsr1 = 0;
      Thr_bMonRunScpPosnSnsr2 = 0;
      Thr_bMonRunScgPosnSnsr2 = 0;
   }
   /*counters initialization */

   THRPOSMES_u8CntFilt_1 = 0;
   THRPOSMES_u8CountNiv2_1 = 0;
   THRPOSMES_u8CntFilt_2 = 0;
   THRPOSMES_u8CountNiv2_2 = 0;
   THRPOSMES_u8CntFilt_3 = 0;
   THRPOSMES_u8CountNiv2_3 = 0;
   THRPOSMES_u8CntFilt_4 = 0;
   THRPOSMES_u8CountNiv2_4 = 0;
   THRPOSMES_u8CntFilt_5 = 0;
   THRPOSMES_u8CountNiv2_5 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidVoltageFilter                                 */
/* !Description :  Ce bloc effectue le filtrage de la tension d'alimentation  */
/*                 des capteurs de position papillon, afin d'éliminer les     */
/*                 oscillations de position liées aux petites oscillations à  */
/*                 hautes fréquences de cette tension.                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRPOSMES_vidFilterU32(argin uint8 u8FilterGain,argout   */
/* uint32 *pu32AccuracyFilterValue,argin uint32 u32MeasuredValue);            */
/*  input uint16 Tension_alimentation_thr;                                    */
/*  input uint16 Tps_tension_alim_thr_init;                                   */
/*  input uint8 Tps_tension_alimentation_gain;                                */
/*  input uint32 THRPOSMES_u32VoltFilterMem;                                  */
/*  input uint32 THRPOSMES_u32DeltaVoltageFilt;                               */
/*  output uint32 THRPOSMES_u32DeltaVoltageFilt;                              */
/*  output uint16 Tension_alimentation_thr_filtree;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidVoltageFilter(void)
{
   /* 0_filtrage_tension */
   uint16 u16LocalTension_alimentation_thr;
   sint32 s32LocalVoltage;
   uint32 u32LocalDeltaVoltageMeas;
   uint32 u32LocalNewFilterValue;


   VEMS_vidGET(Tension_alimentation_thr, u16LocalTension_alimentation_thr);
   s32LocalVoltage = (sint32)u16LocalTension_alimentation_thr
                   - (sint32)(4 * Tps_tension_alim_thr_init);
   /* !Comment: MinDec(s32LocalVoltage) = 0 - 4 * 65535 = -262140             */
   u32LocalDeltaVoltageMeas = (uint32)(s32LocalVoltage + 262140);
   THRPOSMES_vidFilterU32(Tps_tension_alimentation_gain,
                          &THRPOSMES_u32VoltFilterMem,
                          u32LocalDeltaVoltageMeas);

   u32LocalNewFilterValue = THRPOSMES_u32VoltFilterMem + 127;

   /* !Comment: Filter output: [-319.9951171875..79.998779296875] V           */
   THRPOSMES_u32DeltaVoltageFilt = u32LocalNewFilterValue / 256;

   s32LocalVoltage = (sint32)(THRPOSMES_u32DeltaVoltageFilt - 262140)
                   + (sint32)(4 * Tps_tension_alim_thr_init);
   /* !Deviation: violation of MISRA-C:2004 Rule 13.7                         */
   /* Msg(3:3356) The result of this logical operation is always 'false'.     */
   /* !justification: The result of the addition overflows the size of the    */
   /* uint16. therefore the result must be clamped                            */
   Tension_alimentation_thr_filtree = (uint16)MATHSRV_udtCLAMP(s32LocalVoltage,
                                                               0,
                                                               65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidAcqPosition1                                  */
/* !Description :  Valeur de l'angle d'ouverture du papillon donnée par la    */
/*                 voie 1 du/des capteurs. La position papillon 1 est obtenue */
/*                 par une conversion ratiométrique avec la tension           */
/*                 d'alimentation du capteur.                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_04913_002.01                                     */
/*                 VEMS_R_08_04913_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Acquisition_position_bpm_cpt1;                               */
/*  input uint16 Tension_alimentation_thr_filtree;                            */
/*  output uint16 Pos_papillon_1_result_ad_conv;                              */
/*  output uint16 Tps_1_ratio_meas_position;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidAcqPosition1(void)
{
   /* 1_Acquisition_position_1 */
   uint16 u16LocalTps_1_ratio_meas_pos;
   uint16 u16LocalPos_papilon_1_res_ad_cov;
   uint32 u32LocalFiltPosition;


   VEMS_vidGET(Acquisition_position_bpm_cpt1, u16LocalPos_papilon_1_res_ad_cov);
   u16LocalPos_papilon_1_res_ad_cov =
      (uint16)(u16LocalPos_papilon_1_res_ad_cov / 4);
   VEMS_vidSET(Pos_papillon_1_result_ad_conv, u16LocalPos_papilon_1_res_ad_cov);
   if (Tension_alimentation_thr_filtree != 0)
   {
      u32LocalFiltPosition = (uint32)( (u16LocalPos_papilon_1_res_ad_cov * 4096)
                                     / (Tension_alimentation_thr_filtree));
      u16LocalTps_1_ratio_meas_pos =
         (uint16)MATHSRV_udtMIN(u32LocalFiltPosition, 1024);
   }
   else
   {
      u16LocalTps_1_ratio_meas_pos = 1024;
   }
   VEMS_vidSET(Tps_1_ratio_meas_position, u16LocalTps_1_ratio_meas_pos);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidAcqPosition2                                  */
/* !Description :  Valeur de l'angle d'ouverture du papillon donnée par la    */
/*                 voie 2 du/des capteurs. La position papillon 2 est obtenue */
/*                 par une conversion ratiométrique avec la tension           */
/*                 d'alimentation du capteur puis redressée.                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_04913_004.01                                     */
/*                 VEMS_R_08_04913_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Acquisition_position_bpm_cpt2;                               */
/*  input uint16 Tension_alimentation_thr_filtree;                            */
/*  output uint16 Pos_papillon_2_result_ad_conv;                              */
/*  output uint16 Tps_2_ratio_meas_position;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidAcqPosition2(void)
{
   /* 2_Acquisition_position_2 */
   uint16 u16LocalTps_2_ratio_meas_pos;
   uint16 u16LocalPos_papilon_2_res_ad_cov;
   uint32 u32LocalFiltPosition;


   VEMS_vidGET(Acquisition_position_bpm_cpt2, u16LocalPos_papilon_2_res_ad_cov);
   u16LocalPos_papilon_2_res_ad_cov =
      (uint16)(u16LocalPos_papilon_2_res_ad_cov / 4);
   VEMS_vidSET(Pos_papillon_2_result_ad_conv, u16LocalPos_papilon_2_res_ad_cov);
   if (Tension_alimentation_thr_filtree != 0)
   {
      u32LocalFiltPosition = (uint32)( (u16LocalPos_papilon_2_res_ad_cov * 4096)
                                     / Tension_alimentation_thr_filtree);

      if (u32LocalFiltPosition > 1024)
      {
         u16LocalTps_2_ratio_meas_pos = 0;
      }
      else
      {
         u16LocalTps_2_ratio_meas_pos = (uint16)(1024 - u32LocalFiltPosition);
      }
   }
   else
   {
      u16LocalTps_2_ratio_meas_pos = 0;
   }
   VEMS_vidSET(Tps_2_ratio_meas_position, u16LocalTps_2_ratio_meas_pos);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidTpsPosTolerance                               */
/* !Description :  La tolérance de la panne de cohérence est fonction du      */
/*                 régime moteur par le biais de la cartographie              */
/*                 Tps_position_tolerance_map.                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Regime_moteur_8_bkpt_map[9];                                  */
/*  input uint16 Tps_position_tolerance_map[9];                               */
/*  output uint16 Tps_position_tolerance;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidTpsPosTolerance(void)
{
   /* Calcul_tps_position_tolerance */
   boolean bLocalInhThrPosnMesElDiag;
   uint8   u8LocalRegime_moteur_32;
   uint16  u16LocalEngSpdpara8;


   bLocalInhThrPosnMesElDiag = GDGAR_bGetFRM(FRM_FRM_INHTHRPOSNMESELDIAG);
   if (bLocalInhThrPosnMesElDiag == 0)
   {
      VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

      u16LocalEngSpdpara8 =
         MATHSRV_u16CalcParaIncAryU8Loc(Regime_moteur_8_bkpt_map,
                                        u8LocalRegime_moteur_32,
                                        8);
      Tps_position_tolerance = MATHSRV_u16Interp1d(Tps_position_tolerance_map,
                                                   u16LocalEngSpdpara8);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidDiagElecCohPosSnsr                            */
/* !Description :  L'erreur entre les deux mesures papillon est filtrée avant */
/*                 le test de cohérence pour s'affranchir des dispersions de  */
/*                 constantes de temps de filtrage des acquisitions.          */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_04913_006.01                                     */
/*                 VEMS_R_08_04913_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tps_1_ratio_meas_position;                                   */
/*  input uint16 Tps_2_ratio_meas_position;                                   */
/*  input uint8 Tps_coh_filter_gain;                                          */
/*  input uint32 THRPOSMES_u32AccuFilterMem;                                  */
/*  input uint16 Tps_coh_abs_error;                                           */
/*  input uint16 Tps_coh_filt_abs_error;                                      */
/*  input uint16 Tps_position_tolerance;                                      */
/*  output uint16 Tps_coh_abs_error;                                          */
/*  output uint16 Tps_coh_filt_abs_error;                                     */
/*  output boolean Thr_bDgoCohPosnSnsr;                                       */
/*  output boolean Thr_bMonRunCohPosnSnsr;                                    */
/*  output boolean Thr_bMonWaitCohPosnSnsr;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidDiagElecCohPosSnsr(void)
{
   /* Comptage_panne_TPS_COH */
   boolean bLocalInhDiagThrSenPosnMes;
   boolean bLocalInhThrPosnMesElDiag;
   uint16  u16LocalDeltaPosMeas;
   uint16  u16LocalTps_1_ratio_meas_pos;
   uint16  u16LocalTps_2_ratio_meas_pos;
   uint16  u16LocalTpsCohFiltAbsError;
   sint32  s32LocalDeltaPosMeas;


   bLocalInhThrPosnMesElDiag = GDGAR_bGetFRM(FRM_FRM_INHTHRPOSNMESELDIAG);
   if (bLocalInhThrPosnMesElDiag == 0)
   {
      VEMS_vidGET(Tps_1_ratio_meas_position, u16LocalTps_1_ratio_meas_pos);
      VEMS_vidGET(Tps_2_ratio_meas_position, u16LocalTps_2_ratio_meas_pos);
      s32LocalDeltaPosMeas = (sint32)u16LocalTps_1_ratio_meas_pos
                           - (sint32)u16LocalTps_2_ratio_meas_pos;
      u16LocalDeltaPosMeas = (uint16)MATHSRV_udtABS(s32LocalDeltaPosMeas);

      Tps_coh_abs_error = (uint16)MATHSRV_udtMIN(u16LocalDeltaPosMeas, 1023);
      u16LocalTpsCohFiltAbsError =
         MATHSRV_u16FirstOrderFilterGu8(Tps_coh_filter_gain,
                                        &THRPOSMES_u32AccuFilterMem,
                                        Tps_coh_abs_error);
      Tps_coh_filt_abs_error =
         (uint16)MATHSRV_udtMIN(u16LocalTpsCohFiltAbsError, 1023);

      bLocalInhDiagThrSenPosnMes = GDGAR_bGetFRM(FRM_FRM_INHDIAGTHRSENPOSNMES);
      if (Tps_coh_filt_abs_error >= Tps_position_tolerance)
      {
         Thr_bDgoCohPosnSnsr = 1;
      }
      else
      {
         Thr_bDgoCohPosnSnsr = 0;
      }
      if (bLocalInhDiagThrSenPosnMes != 0)
      {
         Thr_bMonRunCohPosnSnsr = 0;
      }
      else
      {
         Thr_bMonRunCohPosnSnsr = 1;
      }
      Thr_bMonWaitCohPosnSnsr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidDiagElec                                      */
/* !Description :  Détection des défauts de plage de mesure, Test de la       */
/*                 cohérence électrique                                       */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void THRPOSMES_vidDiagElecPosRange();                         */
/*  extf argret void THRPOSMES_vidDbleDefaillanceThr();                       */
/*  extf argret void THRPOSMES_vidDiagDisable();                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Tps_sensing_default_diag_enable;                            */
/*  input boolean THRPOSMES_bTpsSensDefDiagEnaPrev;                           */
/*  input boolean Thr_bDgoCohPosnSnsr;                                        */
/*  input boolean Thr_bDgoScpPosnSnsr1;                                       */
/*  input boolean Thr_bDgoScgPosnSnsr1;                                       */
/*  input boolean Thr_bDgoScpPosnSnsr2;                                       */
/*  input boolean Thr_bDgoScgPosnSnsr2;                                       */
/*  output boolean Tps_sensing_default_diag_enable;                           */
/*  output boolean Ext_bMonRunDftSenr_Thr;                                    */
/*  output boolean Thr_bAuthDiagInhThr_CpuSfty;                               */
/*  output boolean THRPOSMES_bTpsSensDefDiagEnaPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidDiagElec(void)
{
   /* 1_Comptage_pannes_mesures_Tps */
   boolean bLocalInhThrPosnMesElDiag;


   bLocalInhThrPosnMesElDiag = GDGAR_bGetFRM(FRM_FRM_INHTHRPOSNMESELDIAG);
   if (bLocalInhThrPosnMesElDiag != 0)
   {
      Tps_sensing_default_diag_enable = 0;
      Ext_bMonRunDftSenr_Thr = 0;
   }
   else
   {
      Tps_sensing_default_diag_enable = 1;
      Ext_bMonRunDftSenr_Thr = 1;
   }

   if (Tps_sensing_default_diag_enable != 0)
   {
      THRPOSMES_vidDiagElecPosRange();
      THRPOSMES_vidDbleDefaillanceThr();
   }
   else
   {
      if (THRPOSMES_bTpsSensDefDiagEnaPrev != 0)
      {
         THRPOSMES_vidDiagDisable();
      }
   }

   if (  (Thr_bDgoCohPosnSnsr != 0)
      || (Thr_bDgoScpPosnSnsr1 != 0)
      || (Thr_bDgoScgPosnSnsr1 != 0)
      || (Thr_bDgoScpPosnSnsr2 != 0)
      || (Thr_bDgoScgPosnSnsr2 != 0))
   {
      VEMS_vidSET(Thr_bAuthDiagInhThr_CpuSfty, 0);
   }
   else
   {
      VEMS_vidSET(Thr_bAuthDiagInhThr_CpuSfty, 1);
   }

   THRPOSMES_bTpsSensDefDiagEnaPrev = Tps_sensing_default_diag_enable;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidDiagDisable                                   */
/* !Description :  Lorsque le diagnostique doit être desactiver du fait d’un  */
/*                 defaut en amont, on positionne Thr_bMonRunXXX à 0 de       */
/*                 manière à ce que le GD n’incrémente pas les compteurs de   */
/*                 pannes                                                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Thr_bMonRunScpPosnSnsr1;                                   */
/*  output boolean Thr_bMonRunScgPosnSnsr1;                                   */
/*  output boolean Thr_bMonRunScpPosnSnsr2;                                   */
/*  output boolean Thr_bMonRunScgPosnSnsr2;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidDiagDisable(void)
{
   /* 1_diag_desactive */
   Thr_bMonRunScpPosnSnsr1 = 0;
   Thr_bMonRunScgPosnSnsr1 = 0;
   Thr_bMonRunScpPosnSnsr2 = 0;
   Thr_bMonRunScgPosnSnsr2 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidDiagElecPosRange                              */
/* !Description :  Le test est effectué si le booléen d’inhibition est        */
/*                 positionné à 0. Le capteur 1 est déclaré en c-c à la Tbat  */
/*                 si la mesure ratiométrique est supérieure à un seuil; en   */
/*                 c-o ou en c-c à la masse si cette mesure est inférieure à  */
/*                 un second seuil                                            */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_04913_008.01                                     */
/*                 VEMS_R_08_04913_009.01                                     */
/*                 VEMS_R_08_04913_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRPOSMES_vidDiagOcPosSnsr2();                           */
/*  input uint16 Tps_1_ratio_meas_position;                                   */
/*  input uint16 Tps_1_default_cc_thresh;                                     */
/*  input uint16 Tps_1_default_co_thresh;                                     */
/*  input uint16 Tps_2_ratio_meas_position;                                   */
/*  input uint16 Tps_2_default_cc_thresh;                                     */
/*  input boolean Dtc_throttle_test_bed_mode_act;                             */
/*  input st1 Tpac_throttle_control_state;                                    */
/*  input boolean Tpac_open_thrust_search_inh;                                */
/*  output boolean Thr_bDgoScpPosnSnsr1;                                      */
/*  output boolean Thr_bMonRunScpPosnSnsr1;                                   */
/*  output boolean Thr_bMonWaitScpPosnSnsr1;                                  */
/*  output boolean Thr_bDgoScgPosnSnsr1;                                      */
/*  output boolean Thr_bMonRunScgPosnSnsr1;                                   */
/*  output boolean Thr_bMonWaitScgPosnSnsr1;                                  */
/*  output boolean Thr_bDgoScpPosnSnsr2;                                      */
/*  output boolean Thr_bMonRunScpPosnSnsr2;                                   */
/*  output boolean Thr_bMonWaitScpPosnSnsr2;                                  */
/*  output boolean Enable_diag_panne_tps_2_basse;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidDiagElecPosRange(void)
{
   /* 0_Comptage_pannes_mesures_Tps */
   boolean bLocalDtc_throttle_test_bed_mode;
   uint8   u8LocalTpac_throttle_control_st;
   uint16  u16LocalTps_1_ratio_meas_pos;
   uint16  u16LocalTps_2_ratio_meas_pos;


   VEMS_vidGET(Tps_1_ratio_meas_position, u16LocalTps_1_ratio_meas_pos);
   if (u16LocalTps_1_ratio_meas_pos > Tps_1_default_cc_thresh)
   {
      Thr_bDgoScpPosnSnsr1 = 1;
   }
   else
   {
      Thr_bDgoScpPosnSnsr1 = 0;
   }
   Thr_bMonRunScpPosnSnsr1  = 1;
   Thr_bMonWaitScpPosnSnsr1 = 0;

   if (u16LocalTps_1_ratio_meas_pos < Tps_1_default_co_thresh)
   {
      Thr_bDgoScgPosnSnsr1 = 1;
   }
   else
   {
      Thr_bDgoScgPosnSnsr1 = 0;
   }
   Thr_bMonRunScgPosnSnsr1  = 1;
   Thr_bMonWaitScgPosnSnsr1 = 0;

   VEMS_vidGET(Tps_2_ratio_meas_position, u16LocalTps_2_ratio_meas_pos);
   if (u16LocalTps_2_ratio_meas_pos < Tps_2_default_cc_thresh)
   {
      Thr_bDgoScpPosnSnsr2 = 1;
   }
   else
   {
      Thr_bDgoScpPosnSnsr2 = 0;
   }
   Thr_bMonRunScpPosnSnsr2  = 1;
   Thr_bMonWaitScpPosnSnsr2 = 0;

   VEMS_vidGET(Dtc_throttle_test_bed_mode_act,
               bLocalDtc_throttle_test_bed_mode);
   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_throttle_control_st);
   if (  (bLocalDtc_throttle_test_bed_mode != 0)
      || (  (Tpac_open_thrust_search_inh == 0)
         && (  (u8LocalTpac_throttle_control_st == TPAC_CLOSING_RAMP)
            || (u8LocalTpac_throttle_control_st == TPAC_HIGH_THRUST_SEARCH))) )
   {
      VEMS_vidSET(Enable_diag_panne_tps_2_basse, 0);
   }
   else
   {
      VEMS_vidSET(Enable_diag_panne_tps_2_basse, 1);

      /* !Comment : Panne_mesure_CO_piste_2                                */
      THRPOSMES_vidDiagOcPosSnsr2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidDiagOcPosSnsr2                                */
/* !Description :  De plus, le fait d’être lié à deux microcontrôleurs        */
/*                 interdit les diagnostics de court-circuit à la masse et de */
/*                 circuit ouvert à cause des courants de fuite dans la       */
/*                 résistance de polarisation en entrée des microcontrôleurs. */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tps_2_ratio_meas_position;                                   */
/*  input uint16 Tps_2_default_co_thresh;                                     */
/*  output boolean Thr_bDgoScgPosnSnsr2;                                      */
/*  output boolean Thr_bMonRunScgPosnSnsr2;                                   */
/*  output boolean Thr_bMonWaitScgPosnSnsr2;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidDiagOcPosSnsr2(void)
{
   /* Panne_mesure_CO_piste_2 */
   uint16  u16LocalTps_2_ratio_meas_pos;


   VEMS_vidGET(Tps_2_ratio_meas_position, u16LocalTps_2_ratio_meas_pos);

   if (u16LocalTps_2_ratio_meas_pos > Tps_2_default_co_thresh)
   {
      Thr_bDgoScgPosnSnsr2 = 1;
   }
   else
   {
      Thr_bDgoScgPosnSnsr2 = 0;
   }
   Thr_bMonRunScgPosnSnsr2  = 1;
   Thr_bMonWaitScgPosnSnsr2 = 0;
}

/*------------------------------- end of file --------------------------------*/
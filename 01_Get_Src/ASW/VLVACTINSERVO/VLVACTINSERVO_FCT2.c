/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINSERVO                                           */
/* !Description     : VLVACTINSERVO Component                                 */
/*                                                                            */
/* !Module          : VLVACTINSERVO                                           */
/* !Description     : Asservissement du decalage VVT admission                */
/*                                                                            */
/* !File            : VLVACTINSERVO_FCT2.C                                    */
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
/*   1 / VLVACTINSERVO_vidControlAlgo                                         */
/*   2 / VLVACTINSERVO_vidServoError                                          */
/*   3 / VLVACTINSERVO_vidDetPIDTerms                                         */
/*   4 / VLVACTINSERVO_vidEvalIntegVal                                        */
/*   5 / VLVACTINSERVO_vidEvalPropTerm                                        */
/*   6 / VLVACTINSERVO_vidEvalDerivTerm                                       */
/*   7 / VLVACTINSERVO_vidEvalPIDDutCycle                                     */
/*   8 / VLVACTINSERVO_vidServoError_2                                        */
/*   9 / VLVACTINSERVO_vidVcpiDiagnosis                                       */
/*   10 / VLVACTINSERVO_vidDiagnosis                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5060915 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#068046                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINSERVO/VLVACTINS$*/
/* $Revision::   1.8      $$Author::   etsasson       $$Date::   22 Jan 2014 $*/
/* $Author::   etsasson                               $$Date::   22 Jan 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "VLVACTINSERVO.h"
#include "VLVACTINSERVO_L.h"
#include "VLVACTINSERVO_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidControlAlgo                               */
/* !Description :  L'algorithme de commande se décompose en deux              */
/*                 parties:1_Determine_PID_Terms qui calcule des actions du   */
/*                 PID; 2_Evaluate_PID_Duty_Cycle qui calcule la Somme des    */
/*                 actions du correcteur,                                     */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTINSERVO_vidServoError();                           */
/*  extf argret void VLVACTINSERVO_vidDetPIDTerms();                          */
/*  extf argret void VLVACTINSERVO_vidEvalPIDDutCycle();                      */
/*  extf argret void VLVACTINSERVO_vidServoError_2();                         */
/*  input boolean VlvAct_bInServoEna;                                         */
/*  input boolean VlvAct_bInActrTestNotRun;                                   */
/*  input boolean VlvAct_bInVlvSpBenchModEna;                                 */
/*  input boolean Vcpi_learning_finished;                                     */
/*  input boolean VlvAct_bInSpFuncIntlHiOutIdc;                               */
/*  input boolean VlvAct_bInSpFuncIntlLoOutIdc;                               */
/*  input sint16 Vcpi_cam_posn_error_Raw;                                     */
/*  output boolean VlvAct_bAcvInServoWithActrTest;                            */
/*  output boolean VlvAct_bAcvInServo;                                        */
/*  output boolean Vcpi_bAcvClosedloop;                                       */
/*  output sint16 Vcpi_cam_posn_error_control;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidControlAlgo(void)
{
   boolean bLocalVlvAct_bInServoEna;
   boolean bLocalVlvAct_bInActrTestNotRun;
   boolean bLocalVlvAct_bInVlvSpBenchModEna;
   boolean bLocalVlvAct_bInSpFuncIntlHiIc;
   boolean bLocalVlvAct_bInSpFuncIntlLoIc;
   boolean bLocalVcpi_learning_finished;


   VEMS_vidGET(VlvAct_bInServoEna, bLocalVlvAct_bInServoEna);
   VEMS_vidGET(VlvAct_bInActrTestNotRun, bLocalVlvAct_bInActrTestNotRun);
   VEMS_vidGET(VlvAct_bInVlvSpBenchModEna, bLocalVlvAct_bInVlvSpBenchModEna);
   VEMS_vidGET(Vcpi_learning_finished, bLocalVcpi_learning_finished);
   if (  (bLocalVcpi_learning_finished != 0)
      && (bLocalVlvAct_bInServoEna != 0))
   {
      VEMS_vidSET(VlvAct_bAcvInServoWithActrTest, 1);
      if (  (bLocalVlvAct_bInActrTestNotRun != 0)
         && (bLocalVlvAct_bInVlvSpBenchModEna == 0))
      {
         VEMS_vidSET(VlvAct_bAcvInServo, 1);
      }
      else
      {
         VEMS_vidSET(VlvAct_bAcvInServo, 0);
      }
      VLVACTINSERVO_vidServoError();
      VEMS_vidGET(VlvAct_bInSpFuncIntlHiOutIdc, bLocalVlvAct_bInSpFuncIntlHiIc);
      VEMS_vidGET(VlvAct_bInSpFuncIntlLoOutIdc, bLocalVlvAct_bInSpFuncIntlLoIc);
      if (  (bLocalVlvAct_bInSpFuncIntlHiIc == 0)
         && (bLocalVlvAct_bInSpFuncIntlLoIc == 0))
      {
         Vcpi_bAcvClosedloop = 1;
         Vcpi_cam_posn_error_control =
            (sint16)MATHSRV_udtCLAMP(Vcpi_cam_posn_error_Raw, -533, 533);
      }
      else
      {
         Vcpi_bAcvClosedloop = 0;
         Vcpi_cam_posn_error_control = 0;
      }
      VLVACTINSERVO_vidDetPIDTerms();
      VLVACTINSERVO_vidEvalPIDDutCycle();
   }
   else
   {
      VEMS_vidSET(VlvAct_bAcvInServo, 0);
      VEMS_vidSET(VlvAct_bAcvInServoWithActrTest, 0);
   }
   VLVACTINSERVO_vidServoError_2();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidServoError                                */
/* !Description :  Afin de pouvoir maîtriser les dépassement lors des fortes  */
/*                 variation de consignes (échelons), un degré de liberté est */
/*                 ajouté sur la consigne de position VVT                     */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  input uint16 Vxx_vvtc_in_angl_sp;                                         */
/*  input uint16 Vta_intake_SpFiltGain_C;                                     */
/*  input uint32 VLVACTINSERVO_u32FilterKMem;                                 */
/*  input uint16 VLVACTINSERVO_u16OutputFilter;                               */
/*  input boolean Vta_intake_Sp_Type_C;                                       */
/*  input uint16 Vta_intake_band_relSp_C;                                     */
/*  input uint16 Vta_intake_FacSpW_C;                                         */
/*  output uint16 Vcpi_cam_rel_posn_error;                                    */
/*  output uint16 VLVACTINSERVO_u16OutputFilter;                              */
/*  output uint32 VLVACTINSERVO_u32FilterKMem;                                */
/*  output sint16 Vcpi_cam_posn_error_Raw;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidServoError(void)
{
   uint16  u16LocalVlvAct_agCmInPosnEstim;
   uint16  u16LocalVxx_vvtc_in_angl_sp;
   uint16  u16LocalAbs;
   uint16  u16LocalFilterGain;
   uint16  u16LocalOutputFilter;
   uint32  u32LocalDivision;
   sint32  s32LocalDiff1;
   sint32  s32LocalProd;
   sint32  s32LocalSum;
   sint32  s32LocalVcpi_cam_posn_error_Raw;


   VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);
   VEMS_vidGET(Vxx_vvtc_in_angl_sp, u16LocalVxx_vvtc_in_angl_sp);
   s32LocalDiff1 =
      (sint32)(u16LocalVxx_vvtc_in_angl_sp - u16LocalVlvAct_agCmInPosnEstim);
   u16LocalAbs = (uint16)(MATHSRV_udtABS(s32LocalDiff1));

   if (u16LocalVxx_vvtc_in_angl_sp != 0)
   {
      u32LocalDivision =
         (uint32)((1000 * u16LocalAbs) / u16LocalVxx_vvtc_in_angl_sp);
      Vcpi_cam_rel_posn_error = (uint16)MATHSRV_udtMIN(u32LocalDivision, 999);
   }
   else
   {
      Vcpi_cam_rel_posn_error = 0;
   }
   /*First-Order Filter*/
   if (Vta_intake_SpFiltGain_C <= 999)
   {
      u16LocalFilterGain = (uint16)((Vta_intake_SpFiltGain_C * 8192) / 125);
      u16LocalOutputFilter =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalFilterGain,
                                         &VLVACTINSERVO_u32FilterKMem,
                                         u16LocalVxx_vvtc_in_angl_sp);
      VLVACTINSERVO_u16OutputFilter =
         (uint16)MATHSRV_udtMIN(u16LocalOutputFilter, 1066);
   }
   else
   {
      VLVACTINSERVO_u16OutputFilter =
         (uint16)MATHSRV_udtMIN(u16LocalVxx_vvtc_in_angl_sp, 1066);
      VLVACTINSERVO_u32FilterKMem =
         (uint32)(VLVACTINSERVO_u16OutputFilter * 65536);
   }

   /* Calcul Vcpi_cam_posn_error_Raw*/
   if (Vta_intake_Sp_Type_C == 0)
   {
      s32LocalVcpi_cam_posn_error_Raw = s32LocalDiff1;
   }
   else
   {
      if (u16LocalAbs <= Vta_intake_band_relSp_C)
      {
         s32LocalVcpi_cam_posn_error_Raw =
            (sint32)( VLVACTINSERVO_u16OutputFilter
                    - u16LocalVlvAct_agCmInPosnEstim);
      }
      else
      {
         s32LocalDiff1 = MATHSRV_udtCLAMP(s32LocalDiff1, -746, 746);
         s32LocalSum = (sint32)Vta_intake_FacSpW_C + 1000;
         s32LocalProd = s32LocalDiff1 * s32LocalSum;
         s32LocalVcpi_cam_posn_error_Raw = s32LocalProd / 1000;
      }
   }
   Vcpi_cam_posn_error_Raw =
      (sint16)MATHSRV_udtCLAMP(s32LocalVcpi_cam_posn_error_Raw, -746, 746);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidDetPIDTerms                               */
/* !Description :  Le correcteur PID est logiquement partagé en trois, un bloc*/
/*                 pour le calcul de chacune de ces actions.                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINSERVO_vidEvalIntegVal();                         */
/*  extf argret void VLVACTINSERVO_vidEvalPropTerm();                         */
/*  extf argret void VLVACTINSERVO_vidEvalDerivTerm();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidDetPIDTerms(void)
{
   VLVACTINSERVO_vidEvalIntegVal();
   VLVACTINSERVO_vidEvalPropTerm();
   VLVACTINSERVO_vidEvalDerivTerm();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidEvalIntegVal                              */
/* !Description :  L'action intégrale est active à l'intérieur d'une bande    */
/*                 (Vta_intake_band), à l'interieur de laquelle  on actualise */
/*                 la valeur intégrale                                        */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 Vta_intake_n_gain_bkpt[6];                                   */
/*  input uint16 Vta_intake_toil_gain_bkpt[5];                                */
/*  input uint16 Vta_intake_int_gain_map[6][5];                               */
/*  input sint16 Vcpi_cam_posn_error_control;                                 */
/*  input uint16 Vta_intake_band;                                             */
/*  input uint16 Vcpi_integral_gain;                                          */
/*  input uint16 Vta_intake_rstInit_toil_bkpt[9];                             */
/*  input uint16 Vta_intake_rstInt_map[9];                                    */
/*  input boolean Vcpi_bInhReinitIntVal_C;                                    */
/*  input boolean Vcpi_bAcvClosedloop;                                        */
/*  input uint16 Vcpi_integral_value;                                         */
/*  input sint16 Vcpi_integral_term;                                          */
/*  input uint16 Vcpi_integral_val_initMem;                                   */
/*  output uint16 Vcpi_integral_gain;                                         */
/*  output sint16 Vcpi_integral_term;                                         */
/*  output uint16 Vcpi_integral_val_initMem;                                  */
/*  output uint16 Vcpi_integral_value;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidEvalIntegVal(void)
{
   uint16 u16LocalSitInterpX;
   uint16 u16LocalSitInterpY;
   uint16 u16LocalVcpiCamPosError;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalTempEng_tOilEstim;
   uint16 u16LocalVcpi_integral_value;
   uint16 u16LocalVcpi_integral_gain;
   uint16 u16LocalPara;
   sint16 s16LocalEng_tOilEstim;
   sint16 s16LocalMod;
   sint32 s32LocalEng_tOilEstim;
   sint32 s32LocalIntegTerm;
   sint32 s32LocalMaxIntegTerm;
   sint32 s32LocalMinIntegTerm;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   s32LocalEng_tOilEstim = (sint32)(s16LocalEng_tOilEstim + 200);
   u16LocalTempEng_tOilEstim = (uint16)MATHSRV_udtCLAMP(s32LocalEng_tOilEstim,
                                                        0,
                                                        1000);
   u16LocalSitInterpX =
      MATHSRV_u16CalcParaIncAryU16(Vta_intake_n_gain_bkpt,
                                   u16LocalExt_nEng,
                                   6);
   u16LocalSitInterpY =
      MATHSRV_u16CalcParaIncAryU16(Vta_intake_toil_gain_bkpt,
                                   u16LocalTempEng_tOilEstim,
                                   5);
   u16LocalVcpi_integral_gain =
      MATHSRV_u16Interp2d(&Vta_intake_int_gain_map[0][0],
                          u16LocalSitInterpX,
                          u16LocalSitInterpY,
                          5);
   Vcpi_integral_gain =
      (uint16)MATHSRV_udtMIN(u16LocalVcpi_integral_gain, 24575);
   u16LocalVcpiCamPosError =
      (uint16)MATHSRV_udtABS(Vcpi_cam_posn_error_control);

   if (u16LocalVcpiCamPosError <= Vta_intake_band)
   {
      s32LocalIntegTerm = Vcpi_integral_gain * Vcpi_cam_posn_error_control;
      s32LocalMaxIntegTerm = SINT32_MAX / (sint32)VlvAct_SampleTiFast_SC;
      s32LocalMinIntegTerm = SINT32_MIN / (sint32)VlvAct_SampleTiFast_SC;
      if (  (s32LocalIntegTerm <= s32LocalMaxIntegTerm)
         && (s32LocalIntegTerm >= s32LocalMinIntegTerm))
      {
         s32LocalIntegTerm = ( s32LocalIntegTerm
                             * (sint32)VlvAct_SampleTiFast_SC)
                           / 4000;
      }
      else
      {
         s16LocalMod = (sint16)(s32LocalIntegTerm % 4000);
         s16LocalMod = (sint16)( (sint32)(s16LocalMod * VlvAct_SampleTiFast_SC)
                               / 4000);
         s32LocalIntegTerm = s32LocalIntegTerm / 4000;
         s32LocalIntegTerm = (s32LocalIntegTerm * VlvAct_SampleTiFast_SC)
                           + s16LocalMod;
      }
   }
   else
   {
      s32LocalIntegTerm = 0;
   }
   Vcpi_integral_term =
      (sint16)MATHSRV_udtCLAMP(s32LocalIntegTerm, -32767, 32767);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Vta_intake_rstInit_toil_bkpt,
                                               u16LocalTempEng_tOilEstim,
                                               9);
   Vcpi_integral_val_initMem = MATHSRV_u16Interp1d(Vta_intake_rstInt_map,
                                                   u16LocalPara);

   if (  (Vcpi_bInhReinitIntVal_C != 0)
      || (Vcpi_bAcvClosedloop != 0))
   {
      VEMS_vidGET(Vcpi_integral_value, u16LocalVcpi_integral_value);
      s32LocalIntegTerm = u16LocalVcpi_integral_value + Vcpi_integral_term;
      u16LocalVcpi_integral_value = (uint16)MATHSRV_udtCLAMP(s32LocalIntegTerm,
                                                            0,
                                                            65535);
   }
   else
   {
      u16LocalVcpi_integral_value = Vcpi_integral_val_initMem;
   }
   VEMS_vidSET(Vcpi_integral_value, u16LocalVcpi_integral_value);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidEvalPropTerm                              */
/* !Description :  L'action proportionnelle à l'intérieur de la bande         */
/*                 (Vta_intake_band) est calculée de manière classique.       */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 Vxx_vvtc_in_angl_sp;                                         */
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  input uint16 Vta_intake_n_gain_bkpt[6];                                   */
/*  input uint16 Vta_intake_toil_gain_bkpt[5];                                */
/*  input uint16 Vta_intake_prop_gain_Down_map[6][5];                         */
/*  input uint16 Vta_intake_prop_gain_map[6][5];                              */
/*  input boolean VLVACTINSERVO_bHysteresisOutput;                            */
/*  input sint16 Vcpi_cam_posn_error_control;                                 */
/*  input sint16 VlvAct_gainInPropErrPosThd_C;                                */
/*  input sint16 VlvAct_gainInPropErrNegThd_C;                                */
/*  input boolean VlvAct_bInInhNegErrPGainClcn_C;                             */
/*  input uint16 Vta_intake_prop_gain_Down;                                   */
/*  input uint16 Vta_intake_prop_gain_Up;                                     */
/*  input boolean Vta_intake_band_Type;                                       */
/*  input uint8 Vta_intake_band_relative_C;                                   */
/*  input uint16 Vcpi_cam_rel_posn_error;                                     */
/*  input uint16 Vta_intake_PropBand;                                         */
/*  input uint16 Vta_intake_gain_hb;                                          */
/*  input boolean Vta_intake_Servo_Type;                                      */
/*  input uint16 Vcpi_proportional_gain;                                      */
/*  output uint16 Vta_intake_prop_gain_Down;                                  */
/*  output uint16 Vta_intake_prop_gain_Up;                                    */
/*  output boolean VLVACTINSERVO_bHysteresisOutput;                           */
/*  output uint16 Vcpi_proportional_gain;                                     */
/*  output sint16 Vcpi_proportional_term;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidEvalPropTerm(void)
{
   boolean bLocalSwitchIntakeBand;
   uint16  u16LocalVcpiCamPosError;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalSitInterpX;
   uint16  u16LocalSitInterpY;
   uint16  u16LocalTempEng_tOilEstim;
   uint16  u16LocalVxx_vvtc_in_angl_sp;
   uint16  u16LocalVtaIntakeBandRelative;
   uint16  u16LocalVtaIntakePropGainUp;
   uint16  u16LocalVtaIntakePropGainDown;
   uint16  u16LocalVtaIntakePropGain;
   uint16  u16LocalVlvAct_agCmInPosnEstim;
   uint32  u32LocalVtaIntakeProd;
   uint32  u32LocalVtaIntakeDiff;
   uint32  u32LocalMaxVtaIntake;
   uint32  u32LocalProd;
   uint32  u32LocalVcpiCamPosError;
   sint16  s16LocalEng_tOilEstim;
   sint32  s32LocalVtaIntakeDiff;
   sint32  s32LocalEng_tOilEstim;
   sint32  s32LocalVcpi_proportional_term;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidGET(Vxx_vvtc_in_angl_sp, u16LocalVxx_vvtc_in_angl_sp);
   VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);

   s32LocalEng_tOilEstim = (sint32)(s16LocalEng_tOilEstim + 200);
   u16LocalTempEng_tOilEstim =
      (uint16)MATHSRV_udtCLAMP(s32LocalEng_tOilEstim, 0, 1000);

   u16LocalSitInterpX =
      MATHSRV_u16CalcParaIncAryU16(Vta_intake_n_gain_bkpt,
                                   u16LocalExt_nEng,
                                   6);
   u16LocalSitInterpY =
      MATHSRV_u16CalcParaIncAryU16(Vta_intake_toil_gain_bkpt,
                                   u16LocalTempEng_tOilEstim,
                                   5);
   u16LocalVtaIntakePropGainDown =
      MATHSRV_u16Interp2d(&Vta_intake_prop_gain_Down_map[0][0],
                          u16LocalSitInterpX,
                          u16LocalSitInterpY,
                          5);
   Vta_intake_prop_gain_Down =
      (uint16)MATHSRV_udtMIN(u16LocalVtaIntakePropGainDown, 24575);

   u16LocalVtaIntakePropGainUp =
      MATHSRV_u16Interp2d(&Vta_intake_prop_gain_map[0][0],
                          u16LocalSitInterpX,
                          u16LocalSitInterpY,
                          5);
   Vta_intake_prop_gain_Up =
      (uint16)MATHSRV_udtMIN(u16LocalVtaIntakePropGainUp, 24575);

   /*** Begin Bloc Hysteresis ***/
   if (VLVACTINSERVO_bHysteresisOutput == 0)
   {
      if (Vcpi_cam_posn_error_control >= VlvAct_gainInPropErrPosThd_C)
      {
         VLVACTINSERVO_bHysteresisOutput = 1;
      }
      else
      {
         VLVACTINSERVO_bHysteresisOutput = 0;
      }
   }
   else
   {
      if (Vcpi_cam_posn_error_control <= VlvAct_gainInPropErrNegThd_C)
      {
         VLVACTINSERVO_bHysteresisOutput = 0;
      }
      else
      {
         VLVACTINSERVO_bHysteresisOutput = 1;
      }
   }
   /*** End Bloc Hysteresis ***/

   if (  (VLVACTINSERVO_bHysteresisOutput != 0)
      && (VlvAct_bInInhNegErrPGainClcn_C == 0))
   {
      u16LocalVtaIntakePropGain = Vta_intake_prop_gain_Down;
   }
   else
   {
      u16LocalVtaIntakePropGain = Vta_intake_prop_gain_Up;
   }

   /* Calcul Vcpi_proportional_gain */
   u16LocalVcpiCamPosError =
      (uint16)MATHSRV_udtABS(Vcpi_cam_posn_error_control);

   if (Vta_intake_band_Type != 0)
   {
      u16LocalVtaIntakeBandRelative =
         (uint16)(Vta_intake_band_relative_C * 10);
      if (Vcpi_cam_rel_posn_error <= u16LocalVtaIntakeBandRelative)
      {
         bLocalSwitchIntakeBand = 1;
      }
      else
      {
         bLocalSwitchIntakeBand = 0;
      }
   }
   else
   {
      if (u16LocalVcpiCamPosError <= Vta_intake_PropBand)
      {
         bLocalSwitchIntakeBand = 1;
      }
      else
      {
         bLocalSwitchIntakeBand = 0;
      }
   }

   if (bLocalSwitchIntakeBand == 0)
   {
      if (Vta_intake_band_Type != 0)
      {
         u32LocalProd =
            (uint32)(Vta_intake_band_relative_C * u16LocalVxx_vvtc_in_angl_sp);
         u32LocalVcpiCamPosError = (uint32)(100 * u16LocalVcpiCamPosError);
         s32LocalVtaIntakeDiff =
            (sint32)(u32LocalVcpiCamPosError - u32LocalProd);
      }
      else
      {
         s32LocalVtaIntakeDiff =
            (sint32)(u16LocalVcpiCamPosError - Vta_intake_PropBand);
         s32LocalVtaIntakeDiff = s32LocalVtaIntakeDiff * 100;
      }
      if ((Vta_intake_gain_hb != 0) && (s32LocalVtaIntakeDiff != 0))
      {
         u32LocalVtaIntakeDiff =
            (uint32)MATHSRV_udtABS(s32LocalVtaIntakeDiff);
         if (u32LocalVtaIntakeDiff <= 65535)
         {
            u32LocalVtaIntakeProd = u32LocalVtaIntakeDiff
                                  * u32LocalVtaIntakeDiff;

            u32LocalMaxVtaIntake = UINT32_MAX / (uint32)Vta_intake_gain_hb;
            if (u32LocalVtaIntakeProd <= u32LocalMaxVtaIntake)
            {
               u32LocalVtaIntakeProd = ( u32LocalVtaIntakeProd
                                       * Vta_intake_gain_hb)
                                     / 40000;
               u32LocalVtaIntakeProd =
                  u16LocalVtaIntakePropGain  + u32LocalVtaIntakeProd;
            }
            else
            {
               u32LocalVtaIntakeProd = 24575;
            }
         }
         else
         {
            u32LocalVtaIntakeProd = 24575;
         }
      }
      else
      {
         u32LocalVtaIntakeProd = u16LocalVtaIntakePropGain;
      }
   }
   else
   {
      u32LocalVtaIntakeProd = u16LocalVtaIntakePropGain;
   }
   Vcpi_proportional_gain =
      (uint16)MATHSRV_udtMIN(u32LocalVtaIntakeProd, 24575);

   /* Calcul Vcpi_proportional_term */
   if (Vta_intake_Servo_Type != 0)
   {
      s32LocalVcpi_proportional_term =
         (sint32)( ( ( u16LocalVtaIntakePropGain
                     * u16LocalVlvAct_agCmInPosnEstim)
                   * (-1))
                 / 16);
   }
   else
   {
      s32LocalVcpi_proportional_term =
         (sint32)( (Vcpi_proportional_gain * Vcpi_cam_posn_error_control)
                 / 16);
   }
   Vcpi_proportional_term =
      (sint16)MATHSRV_udtCLAMP(s32LocalVcpi_proportional_term, -16383, 16383);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidEvalDerivTerm                             */
/* !Description :  Suivant la valeur du booléen Vta_intake_der_mod l'action   */
/*                 dérivée est faite sur l'erreur de vitesse ou sur la        */
/*                 vitesse.                                                   */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 Vta_intake_n_gain_bkpt[6];                                   */
/*  input uint16 Vta_intake_toil_gain_bkpt[5];                                */
/*  input uint16 Vta_intake_der_gain_down_map[6][5];                          */
/*  input uint16 Vta_intake_der_gain_map[6][5];                               */
/*  input boolean VLVACTINSERVO_bHystOutput;                                  */
/*  input sint16 Vcpi_cam_posn_error_control;                                 */
/*  input sint16 VlvAct_gainInDerErrPosThd_C;                                 */
/*  input sint16 VlvAct_gainInDerErrNegThd_C;                                 */
/*  input boolean VlvAct_bInInhNegErrDerGainClcn_C;                           */
/*  input uint16 Vcpi_derivative_gain_down;                                   */
/*  input uint16 Vcpi_derivative_gain;                                        */
/*  input boolean Vta_intake_der_mod;                                         */
/*  input boolean Vta_intake_Servo_Type;                                      */
/*  input sint16 Vta_intake_speed_sp;                                         */
/*  input uint16 Vcpi_derivative_gain_gl;                                     */
/*  input sint16 VlvAct_agCmInSpdEstim;                                       */
/*  output uint16 Vcpi_derivative_gain_down;                                  */
/*  output uint16 Vcpi_derivative_gain;                                       */
/*  output boolean VLVACTINSERVO_bHystOutput;                                 */
/*  output uint16 Vcpi_derivative_gain_gl;                                    */
/*  output sint16 Vcpi_derivative_term;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidEvalDerivTerm(void)
{
   uint16 u16LocalSitInterpX;
   uint16 u16LocalSitInterpY;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalTempEng_tOilEstim;
   uint16 u16LocalVcpiDerivativeGain;
   uint16 u16LocalVcpiDerivativeGainDown;
   sint16 s16LocalEng_tOilEstim;
   sint16 s16LocalVlvAct_agCmInSpdEstim;
   sint32 s32LocalEng_tOilEstim;
   sint32 s32LocalVtaIntSp;
   sint32 s32LocalFiltVelo;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   s32LocalEng_tOilEstim = (sint32)(s16LocalEng_tOilEstim + 200);
   u16LocalTempEng_tOilEstim = (uint16)MATHSRV_udtCLAMP(s32LocalEng_tOilEstim,
                                                        0,
                                                        1000);
   /* Begin Interp2d */
   u16LocalSitInterpX =
      MATHSRV_u16CalcParaIncAryU16(Vta_intake_n_gain_bkpt,
                                   u16LocalExt_nEng,
                                   6);
   u16LocalSitInterpY =
      MATHSRV_u16CalcParaIncAryU16(Vta_intake_toil_gain_bkpt,
                                   u16LocalTempEng_tOilEstim,
                                   5);
   u16LocalVcpiDerivativeGainDown =
      MATHSRV_u16Interp2d(&Vta_intake_der_gain_down_map[0][0],
                          u16LocalSitInterpX,
                          u16LocalSitInterpY,
                          5);
   Vcpi_derivative_gain_down =
      (uint16)MATHSRV_udtMIN(u16LocalVcpiDerivativeGainDown, 24575);

   u16LocalVcpiDerivativeGain =
      MATHSRV_u16Interp2d(&Vta_intake_der_gain_map[0][0],
                          u16LocalSitInterpX,
                          u16LocalSitInterpY,
                          5);
   Vcpi_derivative_gain =
      (uint16)MATHSRV_udtMIN(u16LocalVcpiDerivativeGain, 24575);
   /* End Interp2d */

   /*** Begin Bloc Hysteresis ***/
   if (VLVACTINSERVO_bHystOutput == 0)
   {
      if (Vcpi_cam_posn_error_control >= VlvAct_gainInDerErrPosThd_C)
      {
         VLVACTINSERVO_bHystOutput = 1;
      }
      else
      {
         VLVACTINSERVO_bHystOutput = 0;
      }
   }
   else
   {
      if (Vcpi_cam_posn_error_control <= VlvAct_gainInDerErrNegThd_C)
      {
         VLVACTINSERVO_bHystOutput = 0;
      }
      else
      {
         VLVACTINSERVO_bHystOutput = 1;
      }
   }
   /*** End Bloc Hysteresis ***/

   /* Calcul Vcpi_derivative_gain_gl */
   if (  (VLVACTINSERVO_bHystOutput != 0)
      && (VlvAct_bInInhNegErrDerGainClcn_C == 0))
   {
      Vcpi_derivative_gain_gl = Vcpi_derivative_gain_down;
   }
   else
   {
      Vcpi_derivative_gain_gl = Vcpi_derivative_gain;
   }

   /* Calcul Vcpi_derivative_term */
   if ((Vta_intake_der_mod != 0) && (Vta_intake_Servo_Type == 0))
   {
      s32LocalVtaIntSp = Vta_intake_speed_sp * Vcpi_derivative_gain_gl;
   }
   else
   {
      s32LocalVtaIntSp = 0;
   }
   VEMS_vidGET(VlvAct_agCmInSpdEstim, s16LocalVlvAct_agCmInSpdEstim);
   s32LocalFiltVelo = s16LocalVlvAct_agCmInSpdEstim * Vcpi_derivative_gain_gl;
   s32LocalVtaIntSp = (s32LocalVtaIntSp - s32LocalFiltVelo);
   s32LocalVtaIntSp = s32LocalVtaIntSp / 16;

   Vcpi_derivative_term = (sint16)(MATHSRV_udtCLAMP(s32LocalVtaIntSp,
                                                    -16383,
                                                    16383));
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidEvalPIDDutCycle                           */
/* !Description :  Pour le calcul du RCO PID on ajoute les actions            */
/*                 proportionnelle et dérivée à la valeur intégrale. De meme, */
/*                 on impose la commande en boucle ouverte pour des consignes */
/*                 très proches des butées, afin d'éviter les contacts répétés*/
/*                 avec les butées physiques.                                 */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_06254_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bInSpFuncIntlLoOutIdc;                               */
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  input uint16 VlvAct_agCmInPosnEstimLoLim_C;                               */
/*  input uint16 Vta_intake_low_setpoint_thrust;                              */
/*  input uint16 VlvAct_InLoEndStopHld_C;                                     */
/*  input boolean VlvAct_bInSpFuncIntlHiOutIdc;                               */
/*  input uint16 VlvAct_agCmInPosnEstimHiLim_C;                               */
/*  input uint16 Vta_intake_high_setpoint_thrust;                             */
/*  input uint16 VlvAct_InHiEndStopHld_C;                                     */
/*  input uint16 Vcpi_integral_value;                                         */
/*  input sint16 Vcpi_proportional_term;                                      */
/*  input sint16 Vcpi_derivative_term;                                        */
/*  output uint16 Vcpi_pid_duty_cycle;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidEvalPIDDutCycle(void)
{
   boolean bLocalVlvAct_bInSpFuncIntlHiIc;
   boolean bLocalVlvAct_bInSpFuncIntlLoIc;
   uint16  u16LocalVcpi_integral_value;
   uint16  u16LocalVlvAct_agCmInPosnEstim;
   sint32  s32LocalDutyCycle;


   VEMS_vidGET(VlvAct_bInSpFuncIntlLoOutIdc, bLocalVlvAct_bInSpFuncIntlLoIc);
   if (bLocalVlvAct_bInSpFuncIntlLoIc != 0)
   {
      VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);
      if (u16LocalVlvAct_agCmInPosnEstim > VlvAct_agCmInPosnEstimLoLim_C)
      {
         s32LocalDutyCycle = (sint32)(Vta_intake_low_setpoint_thrust);
      }
      else
      {
         s32LocalDutyCycle = (sint32)(VlvAct_InLoEndStopHld_C);
      }
   }
   else
   {
      VEMS_vidGET(VlvAct_bInSpFuncIntlHiOutIdc, bLocalVlvAct_bInSpFuncIntlHiIc);
      if (bLocalVlvAct_bInSpFuncIntlHiIc != 0)
      {
         VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);
         if (u16LocalVlvAct_agCmInPosnEstim < VlvAct_agCmInPosnEstimHiLim_C)
         {
            s32LocalDutyCycle = (sint32)(Vta_intake_high_setpoint_thrust);
         }
         else
         {
            s32LocalDutyCycle = (sint32)(VlvAct_InHiEndStopHld_C);
         }
      }
      else
      {
         VEMS_vidGET(Vcpi_integral_value, u16LocalVcpi_integral_value);
         s32LocalDutyCycle = (sint32)(  ( ( (Vcpi_proportional_term * 4)
                                          + (Vcpi_derivative_term * 4)
                                          + u16LocalVcpi_integral_value)
                                        + 32)
                                     / 64);
      }
   }
   Vcpi_pid_duty_cycle = (uint16)MATHSRV_udtCLAMP(s32LocalDutyCycle, 0, 1023);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidServoError_2                              */
/* !Description :  calcul de l'erreur d'asservissement lors des passage       */
/*                 BF-->BO près des butées                                    */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Vcpi_cam_position_error;                                     */
/*  input uint16 Vxx_vvtc_in_angl_sp;                                         */
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  output sint16 Vcpi_cam_position_error_prev;                               */
/*  output sint16 Vcpi_cam_position_error;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidServoError_2(void)
{
   uint16 u16LocalVxx_vvtc_in_angl_sp;
   uint16 u16LocalVlvAct_agCmInPosnEstim;
   sint16 s16LocalVcpi_cam_position_error;
   sint32 s32LocalDiff;


   VEMS_vidGET(Vcpi_cam_position_error, s16LocalVcpi_cam_position_error);
   Vcpi_cam_position_error_prev =
      (sint16)MATHSRV_udtCLAMP(s16LocalVcpi_cam_position_error, -533, 533);
   VEMS_vidGET(Vxx_vvtc_in_angl_sp, u16LocalVxx_vvtc_in_angl_sp);
   VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);
   s32LocalDiff = (sint32)( u16LocalVxx_vvtc_in_angl_sp
                          - u16LocalVlvAct_agCmInPosnEstim);
   s16LocalVcpi_cam_position_error = (sint16)MATHSRV_udtCLAMP(s32LocalDiff,
                                                              -533,
                                                              533);
   VEMS_vidSET(Vcpi_cam_position_error, s16LocalVcpi_cam_position_error);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidVcpiDiagnosis                             */
/* !Description :  Le diagnostic est inhibé lorsque: le mode banc pwm est     */
/*                 actif, le régime est en dessous du seuil minimum, les      */
/*                 offsets ne sont pas encore appris, une panne fonction vient*/
/*                 d'être détectée.                                           */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINSERVO_vidDiagnosis();                            */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean VlvAct_bInServoEna;                                         */
/*  input boolean Vcpi_learning_finished;                                     */
/*  input uint16 Vta_intake_min_reg_inh;                                      */
/*  input boolean Cbx_vvtc_pwm_bch;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidVcpiDiagnosis(void)
{
   boolean bLocalVlvAct_bInServoEna;
   boolean bLocalVcpi_learning_finished;
   uint16  u16LocalExt_nEng;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(VlvAct_bInServoEna, bLocalVlvAct_bInServoEna);
   VEMS_vidGET(Vcpi_learning_finished, bLocalVcpi_learning_finished);
   if (  (bLocalVcpi_learning_finished != 0)
      && (u16LocalExt_nEng > Vta_intake_min_reg_inh)
      && (Cbx_vvtc_pwm_bch == 0)
      && (bLocalVlvAct_bInServoEna != 0))
   {
      VLVACTINSERVO_vidDiagnosis();
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINSERVO_vidDiagnosis                                 */
/* !Description :  La surveillance de l'erreur de position du décaleur n'est  */
/*                 active que lorsque le système est en asservissement sur la */
/*                 position de consigne de l'applicatif.                      */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Vcpi_cam_position_error;                                     */
/*  input sint16 Vcpi_cam_position_error_prev;                                */
/*  input uint8 Vta_intake_block_failure_delay;                               */
/*  input uint16 Vta_intake_threshold_error;                                  */
/*  input uint8 Vta_intake_block_failure_tempo;                               */
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  input uint16 Vxx_vvtc_in_angl_sp;                                         */
/*  input uint16 Vcpi_integral_value;                                         */
/*  input uint16 Vta_intake_int_inh_band;                                     */
/*  input uint16 Kfvcpi_phi_maximum_cam_advance;                              */
/*  input uint16 Vta_intake_threshold_int_max;                                */
/*  input uint16 Vta_intake_threshold_int_min;                                */
/*  input uint8 Vta_intake_int_failure_tempo;                                 */
/*  input uint8 Vta_intake_int_failure_delay;                                 */
/*  output uint8 Vta_intake_block_failure_tempo;                              */
/*  output boolean Vbx_pf_vvt_intake_blk;                                     */
/*  output uint8 Vta_intake_int_failure_tempo;                                */
/*  output boolean Vbx_pf_vvt_intake_int;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINSERVO_vidDiagnosis(void)
{
   uint16 u16LocalVcpiCamPosError;
   uint16 u16LocalVlvAct_agCmInPosnEstim;
   uint16 u16LocalVxx_vvtc_in_angl_sp;
   uint16 u16LocalVcpi_integral_value;
   uint16 u16LocalIntake_failure_tempo;
   sint16 s16LocalTempo;
   sint16 s16LocalVcpi_cam_position_error;


   VEMS_vidGET(Vcpi_cam_position_error, s16LocalVcpi_cam_position_error);
   u16LocalVcpiCamPosError =
      (uint16)(MATHSRV_udtABS(s16LocalVcpi_cam_position_error));

   if ((s16LocalVcpi_cam_position_error * Vcpi_cam_position_error_prev) < 0)
   {
      u16LocalIntake_failure_tempo =
         (uint16)(Vta_intake_block_failure_delay * 10);
      Vta_intake_block_failure_tempo =
         (uint8)MATHSRV_udtMIN(u16LocalIntake_failure_tempo, 255);
   }

   if (u16LocalVcpiCamPosError >= Vta_intake_threshold_error)
   {
      s16LocalTempo = (sint16)(Vta_intake_block_failure_tempo - 1);
      Vta_intake_block_failure_tempo = (uint8)(MATHSRV_udtMAX(s16LocalTempo,
                                                               0));
   }
   else
   {
      u16LocalIntake_failure_tempo =
         (uint16)(Vta_intake_block_failure_delay * 10);
      Vta_intake_block_failure_tempo =
         (uint8)MATHSRV_udtMIN(u16LocalIntake_failure_tempo, 255);
   }
   if (Vta_intake_block_failure_tempo == 0)
   {
      Vbx_pf_vvt_intake_blk = 1;
   }
   else
   {
      Vbx_pf_vvt_intake_blk = 0;
   }

   VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);
   VEMS_vidGET(Vxx_vvtc_in_angl_sp, u16LocalVxx_vvtc_in_angl_sp);
   VEMS_vidGET(Vcpi_integral_value, u16LocalVcpi_integral_value);
   if ( ( (u16LocalVlvAct_agCmInPosnEstim >= Vta_intake_int_inh_band)
        ||(u16LocalVlvAct_agCmInPosnEstim < u16LocalVxx_vvtc_in_angl_sp))
      &&( (u16LocalVlvAct_agCmInPosnEstim > u16LocalVxx_vvtc_in_angl_sp)
        ||(u16LocalVlvAct_agCmInPosnEstim <= ( Kfvcpi_phi_maximum_cam_advance
                                              - Vta_intake_int_inh_band)))
      &&( (u16LocalVcpi_integral_value > Vta_intake_threshold_int_max)
        ||(u16LocalVcpi_integral_value < Vta_intake_threshold_int_min)))
   {
      s16LocalTempo = (sint16)(Vta_intake_int_failure_tempo - 1);
      Vta_intake_int_failure_tempo = (uint8)(MATHSRV_udtMAX(s16LocalTempo,0));
   }
   else
   {
      Vta_intake_int_failure_tempo = Vta_intake_int_failure_delay;
   }

   if (Vta_intake_int_failure_tempo == 0)
   {
      Vbx_pf_vvt_intake_int = 1;
   }
   else
   {
      Vbx_pf_vvt_intake_int = 0;
   }
}
/*------------------------------- end of file --------------------------------*/
/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXSERVO                                           */
/* !Description     : VLVACTEXSERVO Component                                 */
/*                                                                            */
/* !Module          : VLVACTEXSERVO                                           */
/* !Description     : Asservissement du decalage VVT echappement              */
/*                                                                            */
/* !File            : VLVACTEXSERVO_FCT2.C                                    */
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
/*   1 / VLVACTEXSERVO_vidControlAlgo                                         */
/*   2 / VLVACTEXSERVO_vidServoError                                          */
/*   3 / VLVACTEXSERVO_vidDetPIDTerms                                         */
/*   4 / VLVACTEXSERVO_vidEvalIntegVal                                        */
/*   5 / VLVACTEXSERVO_vidEvalPropTerm                                        */
/*   6 / VLVACTEXSERVO_vidEvalDerivTerm                                       */
/*   7 / VLVACTEXSERVO_vidEvalPIDDutCycle                                     */
/*   8 / VLVACTEXSERVO_vidServoError_2                                        */
/*   9 / VLVACTEXSERVO_vidVcpeDiagnosis                                       */
/*   10 / VLVACTEXSERVO_vidDiagnosis                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5060920 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#068045                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXSERVO/VLVACTEXS$*/
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
#include "VLVACTEXSERVO.h"
#include "VLVACTEXSERVO_L.h"
#include "VLVACTEXSERVO_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidControlAlgo                               */
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
/*  extf argret void VLVACTEXSERVO_vidServoError();                           */
/*  extf argret void VLVACTEXSERVO_vidDetPIDTerms();                          */
/*  extf argret void VLVACTEXSERVO_vidEvalPIDDutCycle();                      */
/*  extf argret void VLVACTEXSERVO_vidServoError_2();                         */
/*  input boolean VlvAct_bExServoEna;                                         */
/*  input boolean VlvAct_bExActrTestNotRun;                                   */
/*  input boolean VlvAct_bExVlvSpBenchModEna;                                 */
/*  input boolean Vcpe_learning_finished;                                     */
/*  input boolean VlvAct_bExSpFuncIntlHiOutIdc;                               */
/*  input boolean VlvAct_bExSpFuncIntlLoOutIdc;                               */
/*  input sint16 Vcpe_cam_posn_error_Raw;                                     */
/*  output boolean VlvAct_bAcvExServoWithActrTest;                            */
/*  output boolean VlvAct_bAcvExServo;                                        */
/*  output sint16 Vcpe_cam_posn_error_control;                                */
/*  output boolean Vcpe_bAcvClosedloop;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidControlAlgo(void)
{
   boolean bLocalVlvAct_bExServoEna;
   boolean bLocalVlvAct_bExActrTestNotRun;
   boolean bLocalVlvAct_bExVlvSpBenchModEna;
   boolean bLocalVlvAct_bExSpFuncIntlHiIc;
   boolean bLocalVlvAct_bExSpFuncIntlLoIc;
   boolean bLocalVcpe_learning_finished;


   VEMS_vidGET(VlvAct_bExServoEna, bLocalVlvAct_bExServoEna);
   VEMS_vidGET(VlvAct_bExActrTestNotRun, bLocalVlvAct_bExActrTestNotRun);
   VEMS_vidGET(VlvAct_bExVlvSpBenchModEna, bLocalVlvAct_bExVlvSpBenchModEna);
   VEMS_vidGET(Vcpe_learning_finished, bLocalVcpe_learning_finished);

   if (  (bLocalVcpe_learning_finished != 0)
      && (bLocalVlvAct_bExServoEna != 0))
   {
      VEMS_vidSET(VlvAct_bAcvExServoWithActrTest, 1);
      if (  (bLocalVlvAct_bExActrTestNotRun != 0)
         && (bLocalVlvAct_bExVlvSpBenchModEna == 0))
      {
         VEMS_vidSET(VlvAct_bAcvExServo, 1);
      }
      else
      {
         VEMS_vidSET(VlvAct_bAcvExServo, 0);
      }
      VLVACTEXSERVO_vidServoError();
      VEMS_vidGET(VlvAct_bExSpFuncIntlHiOutIdc, bLocalVlvAct_bExSpFuncIntlHiIc);
      VEMS_vidGET(VlvAct_bExSpFuncIntlLoOutIdc, bLocalVlvAct_bExSpFuncIntlLoIc);
      if (  (bLocalVlvAct_bExSpFuncIntlHiIc == 0)
         && (bLocalVlvAct_bExSpFuncIntlLoIc == 0))
      {
         Vcpe_cam_posn_error_control =
            (sint16)MATHSRV_udtCLAMP(Vcpe_cam_posn_error_Raw, -533, 533);
         Vcpe_bAcvClosedloop = 1;
      }
      else
      {
         Vcpe_cam_posn_error_control = 0;
         Vcpe_bAcvClosedloop = 0;
      }
      VLVACTEXSERVO_vidDetPIDTerms();
      VLVACTEXSERVO_vidEvalPIDDutCycle();
   }
   else
   {
      VEMS_vidSET(VlvAct_bAcvExServo, 0);
      VEMS_vidSET(VlvAct_bAcvExServoWithActrTest, 0);
   }
   VLVACTEXSERVO_vidServoError_2();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidServoError                                */
/* !Description :  Afin de pouvoir maîtriser les dépassements lors des fortes */
/*                 variations de consignes (échelons), un degré de liberté est*/
/*                 ajouté sur la consigne de position VVT.                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input uint16 Vxx_vvtc_ex_angl_sp;                                         */
/*  input uint16 Vta_exhaust_SpFiltGain_C;                                    */
/*  input uint32 VLVACTEXSERVO_u32FilterKMem;                                 */
/*  input uint16 VLVACTEXSERVO_u16OutputFilter;                               */
/*  input boolean Vta_exhaust_Sp_Type_C;                                      */
/*  input uint16 Vta_exhaust_band_relSp_C;                                    */
/*  input uint16 Vta_exhaust_FacSpW_C;                                        */
/*  output uint16 Vcpe_cam_rel_posn_error;                                    */
/*  output uint16 VLVACTEXSERVO_u16OutputFilter;                              */
/*  output uint32 VLVACTEXSERVO_u32FilterKMem;                                */
/*  output sint16 Vcpe_cam_posn_error_Raw;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidServoError(void)
{
   uint16  u16LocalVlvAct_agCmExPosnEstim;
   uint16  u16LocalVxx_vvtc_ex_angl_sp;
   uint16  u16LocalAbs;
   uint16  u16LocalFilterGain;
   uint16  u16LocalOutputFilter;
   uint32  u32LocalDivision;
   sint32  s32LocalDiff1;
   sint32  s32LocalProd;
   sint32  s32LocalSum;
   sint32  s32LocalVcpe_cam_posn_error_Raw;

   VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);
   VEMS_vidGET(Vxx_vvtc_ex_angl_sp, u16LocalVxx_vvtc_ex_angl_sp);
   s32LocalDiff1 =
      (sint32)(u16LocalVxx_vvtc_ex_angl_sp - u16LocalVlvAct_agCmExPosnEstim);
   u16LocalAbs = (uint16)(MATHSRV_udtABS(s32LocalDiff1));

   if (u16LocalVxx_vvtc_ex_angl_sp != 0)
   {
      u32LocalDivision =
         (uint32)((1000 * u16LocalAbs) / u16LocalVxx_vvtc_ex_angl_sp);
      Vcpe_cam_rel_posn_error = (uint16)MATHSRV_udtMIN(u32LocalDivision, 999);
   }
   else
   {
      Vcpe_cam_rel_posn_error = 0;
   }
   /*First-Order Filter*/
   if (Vta_exhaust_SpFiltGain_C <= 999)
   {
      u16LocalFilterGain = (uint16)((Vta_exhaust_SpFiltGain_C * 8192) / 125);
      u16LocalOutputFilter =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalFilterGain,
                                         &VLVACTEXSERVO_u32FilterKMem,
                                         u16LocalVxx_vvtc_ex_angl_sp);
      VLVACTEXSERVO_u16OutputFilter =
         (uint16)MATHSRV_udtMIN(u16LocalOutputFilter, 1066);
   }
   else
   {
      VLVACTEXSERVO_u16OutputFilter =
         (uint16)MATHSRV_udtMIN(u16LocalVxx_vvtc_ex_angl_sp, 1066);
      VLVACTEXSERVO_u32FilterKMem =
         (uint32)(VLVACTEXSERVO_u16OutputFilter * 65536);
   }

   /* Calcul Vcpe_cam_posn_error_Raw*/
   if (Vta_exhaust_Sp_Type_C == 0)
   {
      s32LocalVcpe_cam_posn_error_Raw = s32LocalDiff1;
   }
   else
   {
      if (u16LocalAbs <= Vta_exhaust_band_relSp_C)
      {
         s32LocalVcpe_cam_posn_error_Raw =
            (sint32)( VLVACTEXSERVO_u16OutputFilter
                    - u16LocalVlvAct_agCmExPosnEstim);
      }
      else
      {
         s32LocalDiff1 = MATHSRV_udtCLAMP(s32LocalDiff1, -533, 533);
         s32LocalSum = (sint32)Vta_exhaust_FacSpW_C + 1000;
         s32LocalProd = s32LocalDiff1 * s32LocalSum;
         s32LocalVcpe_cam_posn_error_Raw = s32LocalProd / 1000;
      }
   }
   Vcpe_cam_posn_error_Raw =
      (sint16)MATHSRV_udtCLAMP(s32LocalVcpe_cam_posn_error_Raw, -533, 533);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidDetPIDTerms                               */
/* !Description :  Le correcteur PID est logiquement partagé en trois, un bloc*/
/*                 pour le calcul de chacune de ces actions.                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXSERVO_vidEvalIntegVal();                         */
/*  extf argret void VLVACTEXSERVO_vidEvalPropTerm();                         */
/*  extf argret void VLVACTEXSERVO_vidEvalDerivTerm();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidDetPIDTerms(void)
{
   VLVACTEXSERVO_vidEvalIntegVal();
   VLVACTEXSERVO_vidEvalPropTerm();
   VLVACTEXSERVO_vidEvalDerivTerm();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidEvalIntegVal                              */
/* !Description :  L'action intégrale est active à l'intérieur d'une bande    */
/*                 (Vta_exhaust_band), à l'interieur de laquelle, on actualise*/
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
/*  input uint16 Vta_exhaust_rstInit_toil_bkpt[9];                            */
/*  input uint16 Vta_exhaust_rstInt_map[9];                                   */
/*  input uint16 Vta_exhaust_n_gain_bkpt[6];                                  */
/*  input uint16 Vta_exhaust_toil_gain_bkpt[5];                               */
/*  input uint16 Vta_exhaust_int_gain_map[6][5];                              */
/*  input sint16 Vcpe_cam_posn_error_control;                                 */
/*  input uint16 Vta_exhaust_band;                                            */
/*  input uint16 Vcpe_integral_gain;                                          */
/*  input boolean Vcpe_bInhReinitIntVal_C;                                    */
/*  input boolean Vcpe_bAcvClosedloop;                                        */
/*  input uint16 Vcpe_integral_value;                                         */
/*  input sint16 Vcpe_integral_term;                                          */
/*  input uint16 Vcpe_integral_val_initMem;                                   */
/*  output uint16 Vcpe_integral_val_initMem;                                  */
/*  output uint16 Vcpe_integral_gain;                                         */
/*  output sint16 Vcpe_integral_term;                                         */
/*  output uint16 Vcpe_integral_value;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidEvalIntegVal(void)
{
   uint16 u16LocalSitInterpX;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalSitInterpY;
   uint16 u16LocalVcpeCamPosError;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalTempEng_tOilEstim;
   uint16 u16LocalVcpe_integral_value;
   uint16 u16LocalVcpe_integral_gain;
   sint16 s16LocalEng_tOilEstim;
   sint16 s16LocalMod;
   sint32 s32LocalEng_tOilEstim;
   sint32 s32LocalIntegTerm;
   sint32 s32LocalMaxIntegTerm;
   sint32 s32LocalMinIntegTerm;
   sint32 s32LocalIntegralSum;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   s32LocalEng_tOilEstim = (sint32)(s16LocalEng_tOilEstim + 200);
   u16LocalTempEng_tOilEstim = (uint16)MATHSRV_udtCLAMP(s32LocalEng_tOilEstim,
                                                        0,
                                                        1000);
   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(Vta_exhaust_rstInit_toil_bkpt,
                                   u16LocalTempEng_tOilEstim,
                                   9);
   Vcpe_integral_val_initMem = MATHSRV_u16Interp1d(Vta_exhaust_rstInt_map,
                                                   u16LocalCalcParaX);
   u16LocalSitInterpX =
      MATHSRV_u16CalcParaIncAryU16(Vta_exhaust_n_gain_bkpt,
                                   u16LocalExt_nEng,
                                   6);
   u16LocalSitInterpY =
      MATHSRV_u16CalcParaIncAryU16(Vta_exhaust_toil_gain_bkpt,
                                   u16LocalTempEng_tOilEstim,
                                   5);
   u16LocalVcpe_integral_gain = MATHSRV_u16Interp2d(
                                            &Vta_exhaust_int_gain_map[0][0],
                                            u16LocalSitInterpX,
                                            u16LocalSitInterpY,
                                            5);
   Vcpe_integral_gain = (uint16)MATHSRV_udtMIN(u16LocalVcpe_integral_gain,
                                               24575);
   u16LocalVcpeCamPosError =
      (uint16)MATHSRV_udtABS(Vcpe_cam_posn_error_control);

   if (u16LocalVcpeCamPosError <= Vta_exhaust_band)
   {
      s32LocalIntegTerm = Vcpe_integral_gain * Vcpe_cam_posn_error_control;
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
   Vcpe_integral_term =
      (sint16)MATHSRV_udtCLAMP(s32LocalIntegTerm, -32767, 32767);

   if (  (Vcpe_bInhReinitIntVal_C != 0)
      || (Vcpe_bAcvClosedloop != 0))
   {
      VEMS_vidGET(Vcpe_integral_value, u16LocalVcpe_integral_value);
      s32LocalIntegralSum = u16LocalVcpe_integral_value + Vcpe_integral_term;
      u16LocalVcpe_integral_value =
         (uint16)MATHSRV_udtCLAMP(s32LocalIntegralSum, 0, 65535);
   }
   else
   {
      u16LocalVcpe_integral_value = Vcpe_integral_val_initMem;
   }
   VEMS_vidSET(Vcpe_integral_value, u16LocalVcpe_integral_value);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidEvalPropTerm                              */
/* !Description :  L'action proportionnelle à l'intérieur de la bande         */
/*                 (Vta_exhaust_band) est calculée de manière classique .     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 Vxx_vvtc_ex_angl_sp;                                         */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input uint16 Vta_exhaust_n_gain_bkpt[6];                                  */
/*  input uint16 Vta_exhaust_toil_gain_bkpt[5];                               */
/*  input uint16 Vta_exhaust_prop_gain_Down_map[6][5];                        */
/*  input uint16 Vta_exhaust_prop_gain_map[6][5];                             */
/*  input boolean VLVACTEXSERVO_bHysteresisOutput;                            */
/*  input sint16 Vcpe_cam_posn_error_control;                                 */
/*  input sint16 VlvAct_gainExPropErrPosThd_C;                                */
/*  input sint16 VlvAct_gainExPropErrNegThd_C;                                */
/*  input boolean VlvAct_bExInhNegErrPGainClcn_C;                             */
/*  input uint16 Vta_exhaust_prop_gain_Down;                                  */
/*  input uint16 Vta_exhaust_prop_gain_Up;                                    */
/*  input boolean Vta_exhaust_band_Type;                                      */
/*  input uint8 Vta_exhaust_band_relative_C;                                  */
/*  input uint16 Vcpe_cam_rel_posn_error;                                     */
/*  input uint16 Vta_exhaust_PropBand;                                        */
/*  input uint16 Vta_exhaust_gain_hb;                                         */
/*  input boolean Vta_exhaust_Servo_Type;                                     */
/*  input uint16 Vcpe_proportional_gain;                                      */
/*  output uint16 Vta_exhaust_prop_gain_Down;                                 */
/*  output uint16 Vta_exhaust_prop_gain_Up;                                   */
/*  output boolean VLVACTEXSERVO_bHysteresisOutput;                           */
/*  output uint16 Vcpe_proportional_gain;                                     */
/*  output sint16 Vcpe_proportional_term;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidEvalPropTerm(void)
{
   boolean bLocalSwitchExhaustBand;
   uint16  u16LocalVcpeCamPosError;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalSitInterpX;
   uint16  u16LocalSitInterpY;
   uint16  u16LocalTempEng_tOilEstim;
   uint16  u16LocalVxx_vvtc_ex_angl_sp;
   uint16  u16LocalVtaExhaustBandRelative;
   uint16  u16LocalVtaExhaustPropGainUp;
   uint16  u16LocalVtaExhaustPropGainDown;
   uint16  u16LocalVtaExhaustPropGain;
   uint16  u16LocalVlvAct_agCmExPosnEstim;
   uint32  u32LocalVtaExhaustProd;
   uint32  u32LocalVtaExhaustDiff;
   uint32  u32LocalMaxVtaExhaust;
   uint32  u32LocalProd;
   uint32  u32LocalVcpeCamPosError;
   sint16  s16LocalEng_tOilEstim;
   sint32  s32LocalVtaExhaustDiff;
   sint32  s32LocalEng_tOilEstim;
   sint32  s32LocalVcpe_proportional_term;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidGET(Vxx_vvtc_ex_angl_sp, u16LocalVxx_vvtc_ex_angl_sp);
   VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);

   s32LocalEng_tOilEstim = (sint32)(s16LocalEng_tOilEstim + 200);
   u16LocalTempEng_tOilEstim =
      (uint16)MATHSRV_udtCLAMP(s32LocalEng_tOilEstim, 0, 1000);
   u16LocalSitInterpX =
      MATHSRV_u16CalcParaIncAryU16(Vta_exhaust_n_gain_bkpt,
                                   u16LocalExt_nEng,
                                   6);
   u16LocalSitInterpY =
      MATHSRV_u16CalcParaIncAryU16(Vta_exhaust_toil_gain_bkpt,
                                   u16LocalTempEng_tOilEstim,
                                   5);
   u16LocalVtaExhaustPropGainDown =
      MATHSRV_u16Interp2d(&Vta_exhaust_prop_gain_Down_map[0][0],
                          u16LocalSitInterpX,
                          u16LocalSitInterpY,
                          5);
   Vta_exhaust_prop_gain_Down =
      (uint16)MATHSRV_udtMIN(u16LocalVtaExhaustPropGainDown, 24575);

   u16LocalVtaExhaustPropGainUp =
      MATHSRV_u16Interp2d(&Vta_exhaust_prop_gain_map[0][0],
                          u16LocalSitInterpX,
                          u16LocalSitInterpY,
                          5);
   Vta_exhaust_prop_gain_Up =
      (uint16)MATHSRV_udtMIN(u16LocalVtaExhaustPropGainUp, 24575);

   /*** Begin Bloc Hysteresis ***/
   if (VLVACTEXSERVO_bHysteresisOutput == 0)
   {
      if (Vcpe_cam_posn_error_control >= VlvAct_gainExPropErrPosThd_C)
      {
         VLVACTEXSERVO_bHysteresisOutput = 1;
      }
      else
      {
         VLVACTEXSERVO_bHysteresisOutput = 0;
      }
   }
   else
   {
      if (Vcpe_cam_posn_error_control <= VlvAct_gainExPropErrNegThd_C)
      {
         VLVACTEXSERVO_bHysteresisOutput = 0;
      }
      else
      {
         VLVACTEXSERVO_bHysteresisOutput = 1;
      }
   }
   /*** End Bloc Hysteresis ***/

   if (  (VLVACTEXSERVO_bHysteresisOutput != 0)
      && (VlvAct_bExInhNegErrPGainClcn_C == 0))
   {
      u16LocalVtaExhaustPropGain = Vta_exhaust_prop_gain_Down;
   }
   else
   {
      u16LocalVtaExhaustPropGain = Vta_exhaust_prop_gain_Up;
   }

   /* Calcul Vcpi_proportional_gain */
   u16LocalVcpeCamPosError =
      (uint16)MATHSRV_udtABS(Vcpe_cam_posn_error_control);

   if (Vta_exhaust_band_Type != 0)
   {
      u16LocalVtaExhaustBandRelative =
         (uint16)(Vta_exhaust_band_relative_C * 10);
      if (Vcpe_cam_rel_posn_error <= u16LocalVtaExhaustBandRelative)
      {
         bLocalSwitchExhaustBand = 1;
      }
      else
      {
         bLocalSwitchExhaustBand = 0;
      }
   }
   else
   {
      if (u16LocalVcpeCamPosError <= Vta_exhaust_PropBand)
      {
         bLocalSwitchExhaustBand = 1;
      }
      else
      {
         bLocalSwitchExhaustBand = 0;
      }
   }

   if (bLocalSwitchExhaustBand == 0)
   {
      if (Vta_exhaust_band_Type != 0)
      {
         u32LocalProd =
            (uint32)(Vta_exhaust_band_relative_C * u16LocalVxx_vvtc_ex_angl_sp);
         u32LocalVcpeCamPosError = 100 * u16LocalVcpeCamPosError;
         s32LocalVtaExhaustDiff =
            (sint32)(u32LocalVcpeCamPosError - u32LocalProd);
      }
      else
      {
         s32LocalVtaExhaustDiff =
            (sint32)(u16LocalVcpeCamPosError - Vta_exhaust_PropBand);
         s32LocalVtaExhaustDiff = s32LocalVtaExhaustDiff * 100;
      }

      if ((Vta_exhaust_gain_hb != 0) && (s32LocalVtaExhaustDiff != 0))
      {
         u32LocalVtaExhaustDiff =
            (uint32)MATHSRV_udtABS(s32LocalVtaExhaustDiff);
         if (u32LocalVtaExhaustDiff <= 65535)
         {
            u32LocalVtaExhaustProd = u32LocalVtaExhaustDiff
                                   * u32LocalVtaExhaustDiff;
            u32LocalMaxVtaExhaust = UINT32_MAX / (uint32)Vta_exhaust_gain_hb;
            if (u32LocalVtaExhaustProd <= u32LocalMaxVtaExhaust)
            {
               u32LocalVtaExhaustProd = ( u32LocalVtaExhaustProd
                                        * Vta_exhaust_gain_hb)
                                      / 40000;
               u32LocalVtaExhaustProd =
                  u16LocalVtaExhaustPropGain  + u32LocalVtaExhaustProd;
            }
            else
            {
               u32LocalVtaExhaustProd = 24575;
            }
         }
         else
         {
            u32LocalVtaExhaustProd = 24575;
         }
      }
      else
      {
         u32LocalVtaExhaustProd = u16LocalVtaExhaustPropGain;
      }
   }
   else
   {
      u32LocalVtaExhaustProd = u16LocalVtaExhaustPropGain;
   }
   Vcpe_proportional_gain =
      (uint16)MATHSRV_udtMIN(u32LocalVtaExhaustProd, 24575);

   /* Calcul Vcpi_proportional_term */
   if (Vta_exhaust_Servo_Type != 0)
   {
      s32LocalVcpe_proportional_term =
         (sint32)( ( ( u16LocalVtaExhaustPropGain
                     * u16LocalVlvAct_agCmExPosnEstim)
                   * (-1))
                 / 16);
   }
   else
   {
      s32LocalVcpe_proportional_term =
         (sint32)( ( Vcpe_proportional_gain
                   * Vcpe_cam_posn_error_control)
                 / 16);
   }
   Vcpe_proportional_term =
      (sint16)MATHSRV_udtCLAMP(s32LocalVcpe_proportional_term, -16383, 16383);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidEvalDerivTerm                             */
/* !Description :  Suivant la valeur du booléen Vta_exhaust_der_mod l'action  */
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
/*  input uint16 Vta_exhaust_n_gain_bkpt[6];                                  */
/*  input uint16 Vta_exhaust_toil_gain_bkpt[5];                               */
/*  input uint16 Vta_exhaust_der_gain_down_map[6][5];                         */
/*  input uint16 Vta_exhaust_der_gain_map[6][5];                              */
/*  input boolean VLVACTEXSERVO_bHystOutput;                                  */
/*  input sint16 Vcpe_cam_posn_error_control;                                 */
/*  input sint16 VlvAct_gainExDerErrPosThd_C;                                 */
/*  input sint16 VlvAct_gainExDerErrNegThd_C;                                 */
/*  input boolean VlvAct_bExInhNegErrDerGainClcn_C;                           */
/*  input uint16 Vcpe_derivative_gain_down;                                   */
/*  input uint16 Vcpe_derivative_gain;                                        */
/*  input boolean Vta_exhaust_der_mod;                                        */
/*  input boolean Vta_exhaust_Servo_Type;                                     */
/*  input sint16 Vta_exhaust_speed_sp;                                        */
/*  input uint16 Vcpe_derivative_gain_gl;                                     */
/*  input sint16 VlvAct_agCmExSpdEstim;                                       */
/*  output uint16 Vcpe_derivative_gain_down;                                  */
/*  output uint16 Vcpe_derivative_gain;                                       */
/*  output boolean VLVACTEXSERVO_bHystOutput;                                 */
/*  output uint16 Vcpe_derivative_gain_gl;                                    */
/*  output sint16 Vcpe_derivative_term;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidEvalDerivTerm(void)
{
   uint16 u16LocalSitInterpX;
   uint16 u16LocalSitInterpY;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalTempEng_tOilEstim;
   uint16 u16LocalVcpeDerivativeGain;
   uint16 u16LocalVcpeDerivativeGainDown;
   sint16 s16LocalEng_tOilEstim;
   sint16 s16LocalVlvAct_agCmExSpdEstim;
   sint32 s32LocalEng_tOilEstim;
   sint32 s32LocalVtaExhSp;
   sint32 s32LocalFiltVelo;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   s32LocalEng_tOilEstim = (sint32)(s16LocalEng_tOilEstim + 200);
   u16LocalTempEng_tOilEstim = (uint16)MATHSRV_udtCLAMP(s32LocalEng_tOilEstim,
                                                        0,
                                                        1000);
   /* Begin Interp2d */
   u16LocalSitInterpX =
      MATHSRV_u16CalcParaIncAryU16(Vta_exhaust_n_gain_bkpt,
                                   u16LocalExt_nEng,
                                   6);
   u16LocalSitInterpY =
      MATHSRV_u16CalcParaIncAryU16(Vta_exhaust_toil_gain_bkpt,
                                   u16LocalTempEng_tOilEstim,
                                   5);
   u16LocalVcpeDerivativeGainDown =
      MATHSRV_u16Interp2d(&Vta_exhaust_der_gain_down_map[0][0],
                          u16LocalSitInterpX,
                          u16LocalSitInterpY,
                          5);
   Vcpe_derivative_gain_down =
      (uint16)MATHSRV_udtMIN(u16LocalVcpeDerivativeGainDown, 24575);

   u16LocalVcpeDerivativeGain =
      MATHSRV_u16Interp2d(&Vta_exhaust_der_gain_map[0][0],
                          u16LocalSitInterpX,
                          u16LocalSitInterpY,
                          5);
   Vcpe_derivative_gain =
      (uint16)MATHSRV_udtMIN(u16LocalVcpeDerivativeGain, 24575);
   /* End Interp2d */

   /*** Begin Bloc Hysteresis ***/
   if (VLVACTEXSERVO_bHystOutput == 0)
   {
      if (Vcpe_cam_posn_error_control >= VlvAct_gainExDerErrPosThd_C)
      {
         VLVACTEXSERVO_bHystOutput = 1;
      }
      else
      {
         VLVACTEXSERVO_bHystOutput = 0;
      }
   }
   else
   {
      if (Vcpe_cam_posn_error_control <= VlvAct_gainExDerErrNegThd_C)
      {
         VLVACTEXSERVO_bHystOutput = 0;
      }
      else
      {
         VLVACTEXSERVO_bHystOutput = 1;
      }
   }
   /*** End Bloc Hysteresis ***/

   /* Calcul Vcpe_derivative_gain_gl */
   if (  (VLVACTEXSERVO_bHystOutput != 0)
      && (VlvAct_bExInhNegErrDerGainClcn_C == 0))
   {
      Vcpe_derivative_gain_gl = Vcpe_derivative_gain_down;
   }
   else
   {
      Vcpe_derivative_gain_gl = Vcpe_derivative_gain;
   }

   /* Calcul Vcpe_derivative_term */
   if ((Vta_exhaust_der_mod != 0) && (Vta_exhaust_Servo_Type == 0))
   {
      s32LocalVtaExhSp = Vta_exhaust_speed_sp * Vcpe_derivative_gain_gl;
   }
   else
   {
      s32LocalVtaExhSp = 0;
   }
   VEMS_vidGET(VlvAct_agCmExSpdEstim, s16LocalVlvAct_agCmExSpdEstim);
   s32LocalFiltVelo = s16LocalVlvAct_agCmExSpdEstim * Vcpe_derivative_gain_gl;
   s32LocalVtaExhSp = (s32LocalVtaExhSp - s32LocalFiltVelo);
   s32LocalVtaExhSp = s32LocalVtaExhSp / 16;

   Vcpe_derivative_term = (sint16)(MATHSRV_udtCLAMP(s32LocalVtaExhSp,
                                                    -16383,
                                                    16383));
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidEvalPIDDutCycle                           */
/* !Description :  Pour le calcul du RCO PID on ajoute les actions            */
/*                 proportionnelle et dérivée à la valeur intégrale. De meme, */
/*                 on impose la commande en boucle ouverte pour des consignes */
/*                 très proches des butées, afin d'éviter les contacts répétés*/
/*                 avec les butées physiques.                                 */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_06281_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bExSpFuncIntlLoOutIdc;                               */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input uint16 VlvAct_agCmExPosnEstimLoLim_C;                               */
/*  input uint16 Vta_exhaust_low_setpoint_thrust;                             */
/*  input uint16 VlvAct_ExLoEndStopHld_C;                                     */
/*  input boolean VlvAct_bExSpFuncIntlHiOutIdc;                               */
/*  input uint16 VlvAct_agCmExPosnEstimHiLim_C;                               */
/*  input uint16 Vta_exhaust_high_setpoint_thrust;                            */
/*  input uint16 VlvAct_ExHiEndStopHld_C;                                     */
/*  input uint16 Vcpe_integral_value;                                         */
/*  input sint16 Vcpe_proportional_term;                                      */
/*  input sint16 Vcpe_derivative_term;                                        */
/*  output uint16 Vcpe_pid_duty_cycle;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidEvalPIDDutCycle(void)
{
   boolean bLocalVlvAct_bExSpFuncIntlHiIc;
   boolean bLocalVlvAct_bExSpFuncIntlLoIc;
   uint16  u16LocalVcpe_integral_value;
   uint16  u16LocalVlvAct_agCmExPosnEstim;
   sint32  s32LocalDutyCycle;


   VEMS_vidGET(VlvAct_bExSpFuncIntlLoOutIdc, bLocalVlvAct_bExSpFuncIntlLoIc);

   if (bLocalVlvAct_bExSpFuncIntlLoIc != 0)
   {
      VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);
      if (u16LocalVlvAct_agCmExPosnEstim > VlvAct_agCmExPosnEstimLoLim_C)
      {
         s32LocalDutyCycle = (sint32)(Vta_exhaust_low_setpoint_thrust);
      }
      else
      {
         s32LocalDutyCycle = (sint32)(VlvAct_ExLoEndStopHld_C);
      }
   }
   else
   {
      VEMS_vidGET(VlvAct_bExSpFuncIntlHiOutIdc, bLocalVlvAct_bExSpFuncIntlHiIc);

      if (bLocalVlvAct_bExSpFuncIntlHiIc != 0)
      {
         VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);

         if (u16LocalVlvAct_agCmExPosnEstim < VlvAct_agCmExPosnEstimHiLim_C)
         {
            s32LocalDutyCycle = (sint32)(Vta_exhaust_high_setpoint_thrust);
         }
         else
         {
            s32LocalDutyCycle = (sint32)(VlvAct_ExHiEndStopHld_C);
         }
      }
      else
      {
         VEMS_vidGET(Vcpe_integral_value, u16LocalVcpe_integral_value);
         s32LocalDutyCycle = (sint32)( ( ( (Vcpe_proportional_term * 4)
                                         + (Vcpe_derivative_term * 4)
                                         + u16LocalVcpe_integral_value)
                                       + 32)
                                     / 64);
      }
   }
   Vcpe_pid_duty_cycle = (uint16)MATHSRV_udtCLAMP(s32LocalDutyCycle, 0, 1023);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidServoError_2                              */
/* !Description :  Correction du mauvais calcul de l'erreur d'asservissement  */
/*                 lors des passage BF-->BO près des butées.                  */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input uint16 Vxx_vvtc_ex_angl_sp;                                         */
/*  input sint16 Vcpe_cam_position_error;                                     */
/*  output sint16 Vcpe_cam_position_error_prev;                               */
/*  output sint16 Vcpe_cam_position_error;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidServoError_2(void)
{
   uint16 u16LocalVlvAct_agCmExPosnEstim;
   uint16 u16LocalVxx_vvtc_ex_angl_sp;
   sint16 s16LocalVcpe_cam_position_error;
   sint32 s32LocalVcpe_cam_position_error;


   VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);
   VEMS_vidGET(Vxx_vvtc_ex_angl_sp, u16LocalVxx_vvtc_ex_angl_sp);
   VEMS_vidGET(Vcpe_cam_position_error, s16LocalVcpe_cam_position_error);
   Vcpe_cam_position_error_prev =
      (sint16)MATHSRV_udtCLAMP(s16LocalVcpe_cam_position_error,-533,533);
   s32LocalVcpe_cam_position_error =
      u16LocalVxx_vvtc_ex_angl_sp - u16LocalVlvAct_agCmExPosnEstim;
   s16LocalVcpe_cam_position_error =
      (sint16)MATHSRV_udtCLAMP(s32LocalVcpe_cam_position_error,-533,533);
   VEMS_vidSET(Vcpe_cam_position_error, s16LocalVcpe_cam_position_error);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidVcpeDiagnosis                             */
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
/*  extf argret void VLVACTEXSERVO_vidDiagnosis();                            */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean VlvAct_bExServoEna;                                         */
/*  input boolean Vcpe_learning_finished;                                     */
/*  input uint16 Vta_exhaust_min_reg_inh;                                     */
/*  input boolean Cbx_vvtc_pwm_bch2;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidVcpeDiagnosis(void)
{
   boolean bLocalVlvAct_bExServoEna;
   boolean bLocalVcpe_learning_finished;
   uint16  u16LocalExt_nEng;


   VEMS_vidGET(Ext_nEng,u16LocalExt_nEng);
   VEMS_vidGET(VlvAct_bExServoEna, bLocalVlvAct_bExServoEna);
   VEMS_vidGET(Vcpe_learning_finished, bLocalVcpe_learning_finished);
   if (  (bLocalVcpe_learning_finished != 0)
      && (u16LocalExt_nEng > Vta_exhaust_min_reg_inh)
      && (Cbx_vvtc_pwm_bch2 == 0)
      && (bLocalVlvAct_bExServoEna != 0))
   {
      VLVACTEXSERVO_vidDiagnosis();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXSERVO_vidDiagnosis                                 */
/* !Description :  La surveillance de l'erreur de position du décaleur n'est  */
/*                 active que lorsque le système est en asservissement sur la */
/*                 position de consigne de l'applicatif.                      */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Vcpe_cam_position_error;                                     */
/*  input sint16 Vcpe_cam_position_error_prev;                                */
/*  input uint8 Vta_exhaust_block_failure_delay;                              */
/*  input uint16 Vta_exhaust_threshold_error;                                 */
/*  input uint8 Vta_exhaust_block_failure_tempo;                              */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input uint16 Vxx_vvtc_ex_angl_sp;                                         */
/*  input uint16 Vcpe_integral_value;                                         */
/*  input uint16 Vta_exhaust_int_inh_band;                                    */
/*  input uint16 Kfvcpe_phi_maximum_cam_advance;                              */
/*  input uint16 Vta_exhaust_threshold_int_max;                               */
/*  input uint16 Vta_exhaust_threshold_int_min;                               */
/*  input uint8 Vta_exhaust_int_failure_tempo;                                */
/*  input uint8 Vta_exhaust_int_failure_delay;                                */
/*  output uint8 Vta_exhaust_block_failure_tempo;                             */
/*  output boolean Vbx_pf_vvt_exhaust_blk;                                    */
/*  output uint8 Vta_exhaust_int_failure_tempo;                               */
/*  output boolean Vbx_pf_vvt_exhaust_int;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXSERVO_vidDiagnosis(void)
{
   uint16 u16LocalVcpeCamPosError;
   uint16 u16LocalVlvAct_agCmExPosnEstim;
   uint16 u16LocalVxx_vvtc_ex_angl_sp;
   uint16 u16LocalVcpe_integral_value;
   uint16 u16LocalExhaust_failure_tempo;
   sint16 s16LocalTempo;
   sint16 s16LocalVcpe_cam_position_error;


   VEMS_vidGET(Vcpe_cam_position_error, s16LocalVcpe_cam_position_error);
   u16LocalVcpeCamPosError =
      (uint16)(MATHSRV_udtABS(s16LocalVcpe_cam_position_error));

   if ((s16LocalVcpe_cam_position_error * Vcpe_cam_position_error_prev) < 0)
   {
      u16LocalExhaust_failure_tempo =
         (uint16)(Vta_exhaust_block_failure_delay * 10);
      Vta_exhaust_block_failure_tempo =
         (uint8)MATHSRV_udtMIN(u16LocalExhaust_failure_tempo, 255);
   }

   if (u16LocalVcpeCamPosError >= Vta_exhaust_threshold_error)
   {
      s16LocalTempo = (sint16)(Vta_exhaust_block_failure_tempo - 1);
      Vta_exhaust_block_failure_tempo = (uint8)(MATHSRV_udtMAX(s16LocalTempo,
                                                               0));
   }
   else
   {
      u16LocalExhaust_failure_tempo =
         (uint16)(Vta_exhaust_block_failure_delay * 10);
      Vta_exhaust_block_failure_tempo =
         (uint8)MATHSRV_udtMIN(u16LocalExhaust_failure_tempo, 255);
   }

   if (Vta_exhaust_block_failure_tempo == 0)
   {
      Vbx_pf_vvt_exhaust_blk = 1;
   }
   else
   {
      Vbx_pf_vvt_exhaust_blk = 0;
   }

   VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);
   VEMS_vidGET(Vxx_vvtc_ex_angl_sp, u16LocalVxx_vvtc_ex_angl_sp);
   VEMS_vidGET(Vcpe_integral_value, u16LocalVcpe_integral_value);

   if ( ( (u16LocalVlvAct_agCmExPosnEstim >= Vta_exhaust_int_inh_band)
        ||(u16LocalVlvAct_agCmExPosnEstim < u16LocalVxx_vvtc_ex_angl_sp))
      &&( (u16LocalVlvAct_agCmExPosnEstim > u16LocalVxx_vvtc_ex_angl_sp)
        ||(u16LocalVlvAct_agCmExPosnEstim <= ( Kfvcpe_phi_maximum_cam_advance
                                              - Vta_exhaust_int_inh_band)))
      &&( (u16LocalVcpe_integral_value > Vta_exhaust_threshold_int_max)
        ||(u16LocalVcpe_integral_value < Vta_exhaust_threshold_int_min)))
   {
      s16LocalTempo = (sint16)(Vta_exhaust_int_failure_tempo - 1);
      Vta_exhaust_int_failure_tempo = (uint8)(MATHSRV_udtMAX(s16LocalTempo,0));
   }
   else
   {
      Vta_exhaust_int_failure_tempo = Vta_exhaust_int_failure_delay;
   }

   if (Vta_exhaust_int_failure_tempo == 0)
   {
      Vbx_pf_vvt_exhaust_int = 1;
   }
   else
   {
      Vbx_pf_vvt_exhaust_int = 0;
   }
}
/*------------------------------- end of file --------------------------------*/
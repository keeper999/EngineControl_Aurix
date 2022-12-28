/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SPGPRESACQ                                              */
/* !Description     : SPGPRESACQ component.                                   */
/*                                                                            */
/* !Module          : SPGPRESACQ                                              */
/* !Description     : ACQUISITION DE LA PRESSION DE SURALIMENTATION           */
/*                                                                            */
/* !File            : SPGPRESACQ_FCT1.C                                       */
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
/*   1 / SpgPresAcq_vidInitOutput                                             */
/*   2 / SpgPresAcq_vidBoost_Pressure_Acq                                     */
/*   3 / SpgPresAcq_vidBoostPressureDiag                                      */
/*   4 / SpgPresAcq_vidPressElectDiag                                         */
/*   5 / SpgPresAcq_vidBoostPressureForm                                      */
/*   6 / SpgPresAcq_vidBoost_Pressure_Arb                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_6851381 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "SPGPRESACQ.H"
#include "SPGPRESACQ_L.H"
#include "SPGPRESACQ_IM.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SpgPresAcq_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AirPres_uSpgPresSenVoltFilt;                                 */
/*  input uint16 Ext_pUsThrIni_C;                                             */
/*  input uint16 AirPres_uSpgPresSenVoltAvr;                                  */
/*  input uint16 AirPres_uSpgPresSenVoltAvrPrev1;                             */
/*  input uint16 AirPres_uSpgPresSenVoltAvrPrev2;                             */
/*  output uint32 SPGPRESACQ_AcqSpgPressureMem;                               */
/*  output uint16 Acq_spg_pressure;                                           */
/*  output uint16 Acq_spg_pres_measured;                                      */
/*  output uint16 Ext_pUsThrIni_C;                                            */
/*  output uint16 Acq_spg_prs_uavn0;                                          */
/*  output uint16 AirPres_uSpgPresSenVoltAvrPrev1;                            */
/*  output uint16 AirPres_uSpgPresSenVoltAvrPrev2;                            */
/*  output uint16 AirPres_uSpgPresSenVoltAvrPrev3;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SpgPresAcq_vidInitOutput(void)
{
   /* Previous values initialization */
   SPGPRESACQ_AcqSpgPressureMem = (uint32)(AirPres_uSpgPresSenVoltFilt * 256);
   Acq_spg_pressure = Ext_pUsThrIni_C;
   VEMS_vidSET(Acq_spg_pres_measured, Ext_pUsThrIni_C);
   VEMS_vidSET(Acq_spg_prs_uavn0, Ext_pUsThrIni_C);
   AirPres_uSpgPresSenVoltAvrPrev1 =
      (uint16)MATHSRV_udtMIN(AirPres_uSpgPresSenVoltAvr, 4095);
   AirPres_uSpgPresSenVoltAvrPrev2 = AirPres_uSpgPresSenVoltAvrPrev1;
   AirPres_uSpgPresSenVoltAvrPrev3 = AirPres_uSpgPresSenVoltAvrPrev2;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SpgPresAcq_vidBoost_Pressure_Acq                           */
/* !Description :  La tension brute renvoyée par le capteur est normalisée en */
/*                 fonction de la tension d’alimentation du capteur, avant    */
/*                 d’être envoyée au LdA.                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_10_01081_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_upBoostSenPwr;                                           */
/*  input uint16 Ext_uSpgPresSenVolt;                                         */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input uint16 AirPres_uSpgPresSenVoltAvrPrev1;                             */
/*  input uint16 AirPres_uSpgPresSenVoltAvrPrev2;                             */
/*  input uint16 AirPres_uSpgPresSenVoltAvrPrev3;                             */
/*  input uint16 AirPres_uSpgPresSenVoltAvr;                                  */
/*  output uint16 AirPres_uSpgPresSenVoltAvr;                                 */
/*  output uint16 AirPres_uSpgPresSenVolt;                                    */
/*  output uint16 AirPres_uSpgPresSenVoltAvrPrev3;                            */
/*  output uint16 AirPres_uSpgPresSenVoltAvrPrev2;                            */
/*  output uint16 AirPres_uSpgPresSenVoltAvrPrev1;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SpgPresAcq_vidBoost_Pressure_Acq(void)
{
   boolean bLocalCoPTSt_bEngRun;
   uint16  u16LocalExt_upBoostSenPwr;
   uint16  u16LocalAirPres_uSpgPresSenVolt;
   uint16  u16LocalExt_uSpgPresSenVolt;
   uint32  u32LocalAirPres_uSpgPresSenVolt;


   VEMS_vidGET(Ext_upBoostSenPwr, u16LocalExt_upBoostSenPwr);
   VEMS_vidGET(Ext_uSpgPresSenVolt, u16LocalExt_uSpgPresSenVolt);

   if (u16LocalExt_upBoostSenPwr != 0)
   {
   /*  Scaling is S = (A * 4096)/B  */
      u32LocalAirPres_uSpgPresSenVolt =
         (uint32)(u16LocalExt_uSpgPresSenVolt << 12) /
                  u16LocalExt_upBoostSenPwr;
      AirPres_uSpgPresSenVoltAvr =
         (uint16)MATHSRV_udtMIN(u32LocalAirPres_uSpgPresSenVolt, 4095);
   }
   else
   {
      AirPres_uSpgPresSenVoltAvr = 4095;
   }

   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
   if (bLocalCoPTSt_bEngRun != 0)
   {
      u16LocalAirPres_uSpgPresSenVolt
         = (uint16)( ( AirPres_uSpgPresSenVoltAvrPrev1
                     + AirPres_uSpgPresSenVoltAvrPrev2
                     + AirPres_uSpgPresSenVoltAvrPrev3
                     + AirPres_uSpgPresSenVoltAvr
                     + 2)
                   / 4);
      AirPres_uSpgPresSenVolt =
         (uint16)MATHSRV_udtMIN(u16LocalAirPres_uSpgPresSenVolt, 4095);
   }
   else
   {
      AirPres_uSpgPresSenVolt = AirPres_uSpgPresSenVoltAvr;
   }
   AirPres_uSpgPresSenVoltAvrPrev3 =
      (uint16)MATHSRV_udtMIN(AirPres_uSpgPresSenVoltAvrPrev2, 4095);
   AirPres_uSpgPresSenVoltAvrPrev2 =
      (uint16)MATHSRV_udtMIN(AirPres_uSpgPresSenVoltAvrPrev1, 4095);
   AirPres_uSpgPresSenVoltAvrPrev1 = AirPres_uSpgPresSenVoltAvr;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SpgPresAcq_vidBoostPressureDiag                            */
/* !Description :  Les diagnostics éléctriques pour les valeurs haute et basse*/
/*                 sur signal de pression de suralimentation sont  ctivés     */
/*                 lorsque la chaîne d’acquisition est activée et si aucun    */
/*                 défaut n’est confirmé.                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_10_01081_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void SpgPresAcq_vidPressElectDiag();                          */
/*  output boolean Ext_bMonRunScp_pSpgPres;                                   */
/*  output boolean Ext_bMonRunScg_pSpgPres;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SpgPresAcq_vidBoostPressureDiag(void)
{
   boolean bLocalInhDiag_pUsThrMes;


   bLocalInhDiag_pUsThrMes = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PUSTHRMES);
   if (bLocalInhDiag_pUsThrMes != 0)
   {
      Ext_bMonRunScp_pSpgPres = 0;
      Ext_bMonRunScg_pSpgPres = 0;
   }
   else
   {
      Ext_bMonRunScp_pSpgPres = 1;
      Ext_bMonRunScg_pSpgPres = 1;
      SpgPresAcq_vidPressElectDiag();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SpgPresAcq_vidPressElectDiag                               */
/* !Description :  A chaque acquisition de la tension de suralimentation, un  */
/*                 diagnostic est effectué sur la validité de la nouvelle     */
/*                 mesure, à l’aide de seuils calibrables, permettant         */
/*                 l’actualisation des indicateurs de défauts.                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_10_01081_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ext_uSpgPresSenVolt;                                         */
/*  input uint16 AirPres_uDgoScp_pSpgPres_C;                                  */
/*  input uint16 AirPres_uDgoScg_pSpgPres_C;                                  */
/*  output boolean Ext_bDgoScp_pSpgPres;                                      */
/*  output boolean Ext_bDgoScg_pSpgPres;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SpgPresAcq_vidPressElectDiag(void)
{
   uint16 u16LocalExt_uSpgPresSenVolt;


   VEMS_vidGET(Ext_uSpgPresSenVolt, u16LocalExt_uSpgPresSenVolt);
   if (u16LocalExt_uSpgPresSenVolt > AirPres_uDgoScp_pSpgPres_C)
   {
      Ext_bDgoScp_pSpgPres = 1;
   }
   else
   {
      Ext_bDgoScp_pSpgPres = 0;
   }
   if (u16LocalExt_uSpgPresSenVolt < AirPres_uDgoScg_pSpgPres_C)
   {
      Ext_bDgoScg_pSpgPres = 1;
   }
   else
   {
      Ext_bDgoScg_pSpgPres = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SpgPresAcq_vidBoostPressureForm                            */
/* !Description :  La tension renvoyée par le capteur est convertie en        */
/*                 pression de suralimentation. Cette  pression est ensuite   */
/*                 filtrée.                                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_10_01081_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirPres_pUsThrMes_nEng_A[10];                                */
/*  input uint8 AirPres_rFilGainSpgPres_nEng_T[10];                           */
/*  input uint32 SPGPRESACQ_AcqSpgPressureMem;                                */
/*  input uint16 AirPres_uSpgPresSenVolt;                                     */
/*  input uint16 AirPres_uSpgPresSenVoltFilt;                                 */
/*  input uint16 AirPres_uSpgPresSenVolt_A[2];                                */
/*  input uint16 AirPres_pSpgPresSenVolt_T[2];                                */
/*  output uint16 AirPres_uSpgPresSenVoltFilt;                                */
/*  output uint32 SPGPRESACQ_AcqSpgPressureMem;                               */
/*  output uint16 Acq_spg_pressure;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SpgPresAcq_vidBoostPressureForm(void)
{
   uint8   u8LocalCalc;
   uint8   u8LocalFilterGain;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalPara;
   uint16  u16LocalFilter;
   uint16  u16LocalInterp;
   uint16  u16LocalBKPTSup;
   uint16  u16LocalBKPTInf;
   uint16  u16LocalMapSup;
   uint16  u16LocalMapInf;
   uint16  u16Local;
   uint16  u16LocalInterpolation;
   uint16  u16LocalSiteInterpolation;
   uint16  u16LocalAcq_spg_pressure;
   uint32  u32LocalDeltaValue;
   uint32  u32LocalInterpolation;
   uint32  u32LocalResultValue;
   uint32  u32LocalAcq_spg_pressure;
   sint32  s32LocalInterpolation;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(AirPres_pUsThrMes_nEng_A,
                                               u16LocalExt_nEng,
                                               10);
   u8LocalCalc = MATHSRV_u8Interp1d(AirPres_rFilGainSpgPres_nEng_T,
                                    u16LocalPara);
   u16LocalInterp = (uint16)(u8LocalCalc + 1);
   if (u16LocalInterp < 100)
   {
      u8LocalFilterGain = (uint8)(((u16LocalInterp * 64) + 13) / 25);
      u16LocalFilter =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalFilterGain,
                                        &SPGPRESACQ_AcqSpgPressureMem,
                                        AirPres_uSpgPresSenVolt);
      AirPres_uSpgPresSenVoltFilt =
         (uint16)MATHSRV_udtMIN(u16LocalFilter, 4095);
   }
   else
   {
      AirPres_uSpgPresSenVoltFilt =
         (uint16)MATHSRV_udtMIN(AirPres_uSpgPresSenVolt, 4095);
      SPGPRESACQ_AcqSpgPressureMem =
         (uint32)(AirPres_uSpgPresSenVoltFilt * 256);
   }

   u16LocalAcq_spg_pressure = 0;
   if (AirPres_uSpgPresSenVolt_A[1] >= AirPres_uSpgPresSenVolt_A[0])
   {
      u16LocalBKPTSup = AirPres_uSpgPresSenVolt_A[1];
      u16LocalBKPTInf = AirPres_uSpgPresSenVolt_A[0];
      u16LocalMapSup  = AirPres_pSpgPresSenVolt_T[1];
      u16LocalMapInf  = AirPres_pSpgPresSenVolt_T[0];
   }
   else
   {
      u16LocalBKPTSup = AirPres_uSpgPresSenVolt_A[0];
      u16LocalBKPTInf = AirPres_uSpgPresSenVolt_A[1];
      u16LocalMapSup  = AirPres_pSpgPresSenVolt_T[0];
      u16LocalMapInf  = AirPres_pSpgPresSenVolt_T[1];
   }
   if (AirPres_uSpgPresSenVolt_A[1] != AirPres_uSpgPresSenVolt_A[0])
   {
      if (AirPres_uSpgPresSenVoltFilt >= u16LocalBKPTSup)
      {
         u16LocalAcq_spg_pressure = u16LocalMapSup;
      }
      if (AirPres_uSpgPresSenVoltFilt < u16LocalBKPTInf)
      {
         u16LocalAcq_spg_pressure = u16LocalMapInf;
      }
      if (  (AirPres_uSpgPresSenVoltFilt < u16LocalBKPTSup)
         && (AirPres_uSpgPresSenVoltFilt >= u16LocalBKPTInf))
      {
         /* Calculate the "Para" value of AirPres_uSpgPresSenVoltFilt with
            AirPres_uSpgPresSenVolt_A */

         u32LocalDeltaValue =
            (uint32)MATHSRV_udtABS( AirPres_uSpgPresSenVoltFilt
                                  - AirPres_uSpgPresSenVolt_A[0]);
         u32LocalDeltaValue = u32LocalDeltaValue << 16;
         u16LocalInterpolation = (uint16)(u16LocalBKPTSup - u16LocalBKPTInf);
         u16LocalSiteInterpolation =
            (uint16)(u32LocalDeltaValue / u16LocalInterpolation);
         /* Calculate the interpolation value on AirPres_pSpgPresSenVolt_T */

         s32LocalInterpolation = (sint32)AirPres_pSpgPresSenVolt_T[1]
                               - (sint32)AirPres_pSpgPresSenVolt_T[0];
         u16Local = (uint16)MATHSRV_udtABS(s32LocalInterpolation);
         if (s32LocalInterpolation > 0)
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation =
               (sint32)((u32LocalInterpolation + 32768) / 65536);
         }
         else
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation =
               (sint32)((u32LocalInterpolation + 32768) / 65536);
            s32LocalInterpolation = ((-1) * s32LocalInterpolation);
         }

         u32LocalResultValue =
            (uint32)( (sint32)AirPres_pSpgPresSenVolt_T[0]
                    + s32LocalInterpolation);
         u16LocalAcq_spg_pressure = (uint16)u32LocalResultValue;
      }
   }
   else
   {
      u16LocalAcq_spg_pressure = AirPres_pSpgPresSenVolt_T[0];
   }
   u32LocalAcq_spg_pressure = (uint32)(u16LocalAcq_spg_pressure + 1);
   Acq_spg_pressure = (uint16)MATHSRV_udtMIN(u32LocalAcq_spg_pressure, 65535);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SpgPresAcq_vidBoost_Pressure_Arb                           */
/* !Description :  En présence de défauts, la valeur de la pression de        */
/*                 suralimentation n’est plus acquise mais figée à sa dernière*/
/*                 valeur valide. Si le défaut est confirmée la pression est  */
/*                 égale à  une valeur de repli dépendant de la               */
/*                 synchronisation du moteur.                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_10_01081_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirPres_pSpgPresAcq_nEng_A[9];                               */
/*  input uint16 AirPres_pSpgDftv_nEng_T[9];                                  */
/*  input boolean Moteur_synchronise;                                         */
/*  input uint16 Acq_pSpgPresDftv_SyncEng;                                    */
/*  input uint16 Ext_pAirExtMesSI;                                            */
/*  input boolean Ext_bDgoScg_pSpgPres;                                       */
/*  input boolean Ext_bDgoScp_pSpgPres;                                       */
/*  input uint16 Acq_spg_pres_measured;                                       */
/*  input uint16 Acq_spg_pressure;                                            */
/*  output uint16 Acq_pSpgPresDftv_SyncEng;                                   */
/*  output uint16 Acq_spg_pres_measured;                                      */
/*  output uint16 Acq_spg_prs_uavn0;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SpgPresAcq_vidBoost_Pressure_Arb(void)
{
   boolean bLocalInhInSpgPresAcq;
   boolean bLocalMoteur_synchronise;
   boolean bLocalInhDiag_pUsThrMes;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalAcq_spg_pres_measured;
   uint16  u16LocalPara;
   uint16  u16LocalExt_pAirExtMesSI;
   uint16  u16LocalAcq_spg_prs_uavn0;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(AirPres_pSpgPresAcq_nEng_A,
                                               u16LocalExt_nEng,
                                               9);
   Acq_pSpgPresDftv_SyncEng = MATHSRV_u16Interp1d(AirPres_pSpgDftv_nEng_T,
                                                  u16LocalPara);
   bLocalInhInSpgPresAcq = GDGAR_bGetFRM(FRM_FRM_INHINSPGPRESACQ);
   if (bLocalInhInSpgPresAcq != 0)
   {
      VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
      if (bLocalMoteur_synchronise != 0)
      {
         u16LocalAcq_spg_pres_measured = Acq_pSpgPresDftv_SyncEng;
      }
      else
      {
         VEMS_vidGET(Ext_pAirExtMesSI, u16LocalExt_pAirExtMesSI);
         u16LocalAcq_spg_pres_measured = u16LocalExt_pAirExtMesSI;
      }
   }
   else
   {
      bLocalInhDiag_pUsThrMes = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PUSTHRMES);
      if (  (Ext_bDgoScg_pSpgPres != 0)
         || (Ext_bDgoScp_pSpgPres != 0)
         || (bLocalInhDiag_pUsThrMes != 0))
      {
         VEMS_vidGET(Acq_spg_pres_measured, u16LocalAcq_spg_pres_measured);
      }
      else
      {
         u16LocalAcq_spg_pres_measured = Acq_spg_pressure;
      }
   }
   VEMS_vidSET(Acq_spg_pres_measured, u16LocalAcq_spg_pres_measured);
   u16LocalAcq_spg_prs_uavn0 = u16LocalAcq_spg_pres_measured;
   VEMS_vidSET(Acq_spg_prs_uavn0, u16LocalAcq_spg_prs_uavn0);
}
/*-------------------------------- end of file -------------------------------*/
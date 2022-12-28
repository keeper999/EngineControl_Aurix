/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2UPPERDDIAG                                     */
/* !Description     : HEATSENO2UPPERDDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2UPPERDDIAG                                     */
/* !Description     : DIAGNOSTIC DE LA SONDE A OXYGENE AMONT                  */
/*                                                                            */
/* !File            : HEATSENO2UPPERDDIAG_FCT4.C                              */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / HEATSENO2UPPERDDIAG_vidTgInitTrn                                     */
/*   2 / HEATSENO2UPPERDDIAG_vidInitCbTrn                                     */
/*   3 / HEATSENO2UPPERDDIAG_vidIniTimers                                     */
/*   4 / HEATSENO2UPPERDDIAG_vidSensPerEf                                     */
/*   5 / HEATSENO2UPPERDDIAG_vidEfLeanCal                                     */
/*   6 / HEATSENO2UPPERDDIAG_vidEfRichCal                                     */
/*   7 / HEATSENO2UPPERDDIAG_vidPerDgSens                                     */
/*   8 / HEATSENO2UPPERDDIAG_vidPerDgApv                                      */
/*   9 / HEATSENO2UPPERDDIAG_vidcallGDU                                       */
/*   10 / HEATSENO2UPPERDDIAG_vidCrPrdLean                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5012863 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2US/HEATSENO2UPPERDDIA$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   17 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   17 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2UPPERDDIAG.h"
#include "HEATSENO2UPPERDDIAG_L.h"
#include "HEATSENO2UPPERDDIAG_IM.h"
#include "VEMS.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidTgInitTrn                           */
/* !Description :  Cette fonction permet la réinitialisation du diagnostic    */
/*                 lors des transitions essence ver gaz, ou gaz vers essence  */
/*                 (lorsque l’application gaz est applicable)                 */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPPERDDIAG_vidInitCbTrn();                      */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 HEATSENO2UPPERDDIAG_u8SysGasPrev;                             */
/*  output uint8 HEATSENO2UPPERDDIAG_u8SysGasPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidTgInitTrn(void)
{
   uint8 u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (  (  (u8LocalExt_stSysGas == Ext_stTranGslGas_SC)
         && (HEATSENO2UPPERDDIAG_u8SysGasPrev == Ext_stGslMod_SC))
      || (  (u8LocalExt_stSysGas == Ext_stTranGasGsl_SC)
         && (HEATSENO2UPPERDDIAG_u8SysGasPrev == Ext_stGasMod_SC)))
   {
      HEATSENO2UPPERDDIAG_vidInitCbTrn();
   }
   HEATSENO2UPPERDDIAG_u8SysGasPrev = u8LocalExt_stSysGas;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidInitCbTrn                           */
/* !Description :  Initialisation du diagnostic lors des transitions essence  */
/*                 vers gaz, ou gaz vers essence                              */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Oxy_sens_diag_test_completed;                              */
/*  output uint8 Oxy_period_tests;                                            */
/*  output uint8 Os_period_tests_done;                                        */
/*  output boolean Oxy_sens_diag_test_finished;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidInitCbTrn(void)
{
   VEMS_vidSET(Oxy_sens_diag_test_completed, 0);
   Oxy_period_tests = 0;
   Os_period_tests_done = 0;
   VEMS_vidSET(Oxy_sens_diag_test_finished, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidIniTimers                           */
/* !Description :  Fonction d'initialisation des timers                       */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean HEATSENO2UPPERDDIAG_bTimeout1;                             */
/*  output boolean HEATSENO2UPPERDDIAG_bTimeout2;                             */
/*  output boolean HEATSENO2UPPERDDIAG_bEnleanPrev;                           */
/*  output boolean HEATSENO2UPPERDDIAG_bEnrichPrev;                           */
/*  output uint16 Lfbk_on_enlean_clamp_delay;                                 */
/*  output uint16 Lfbk_on_enrich_clamp_delay;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidIniTimers(void)
{
   HEATSENO2UPPERDDIAG_bTimeout1 = 0;
   HEATSENO2UPPERDDIAG_bTimeout2 = 0;
   HEATSENO2UPPERDDIAG_bEnleanPrev = 0;
   HEATSENO2UPPERDDIAG_bEnrichPrev = 0;
   Lfbk_on_enlean_clamp_delay = 0;
   Lfbk_on_enrich_clamp_delay = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidSensPerEf                           */
/* !Description :  Production du rapport d’efficacité de la période sonde     */
/*                 amont                                                      */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPPERDDIAG_vidEfLeanCal();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidEfRichCal();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Engine_load;                                                 */
/*  input boolean Enable_period_lean;                                         */
/*  input boolean Enable_period_rich;                                         */
/*  input uint8 Regime_moteur_2_bkpt_map[9];                                  */
/*  input uint16 Engine_load_2_bkpt_map[9];                                   */
/*  input uint16 LsMon_tiPerUsNew_M[9][9];                                    */
/*  input uint16 LsMon_tiPerUs;                                               */
/*  output uint16 LsMon_noRatEfcLsUsPer;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidSensPerEf(void)
{
   uint8  u8LocalRegime_moteur_32;
   uint16 u16LocalEngine_load;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalTiPerUsNew;
   uint32 u32LocalTiPerUs;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Engine_load, u16LocalEngine_load);
   if (Enable_period_lean != 0)
   {
      HEATSENO2UPPERDDIAG_vidEfLeanCal();
   }
   if (Enable_period_rich != 0)
   {
      HEATSENO2UPPERDDIAG_vidEfRichCal();
   }
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_2_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               9);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(Engine_load_2_bkpt_map,
                                                u16LocalEngine_load,
                                                9);
   u16LocalTiPerUsNew = MATHSRV_u16Interp2d(&LsMon_tiPerUsNew_M[0][0],
                                            u16LocalParaX,
                                            u16LocalParaY,
                                            9);
   if (u16LocalTiPerUsNew != 0)
   {
      u32LocalTiPerUs = (uint32)((100 * LsMon_tiPerUs) / u16LocalTiPerUsNew);
      u16LocalTiPerUsNew = (uint16)MATHSRV_udtMIN(u32LocalTiPerUs, 2560);
      VEMS_vidSET(LsMon_noRatEfcLsUsPer, u16LocalTiPerUsNew);
   }
   else
   {
      VEMS_vidSET(LsMon_noRatEfcLsUsPer, 2559);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidEfLeanCal                           */
/* !Description :  Calcul du période instantanée                              */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Oxy_ups_period_lean;                                         */
/*  output uint16 LsMon_tiPerUs;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidEfLeanCal(void)
{
   LsMon_tiPerUs = (uint16)MATHSRV_udtMIN(Oxy_ups_period_lean, 26214);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidEfRichCal                           */
/* !Description :  Calcul du période instantannée                             */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Oxy_ups_period_rich;                                         */
/*  output uint16 LsMon_tiPerUs;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidEfRichCal(void)
{
   LsMon_tiPerUs = (uint16)MATHSRV_udtMIN(Oxy_ups_period_rich, 26214);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidPerDgSens                           */
/* !Description :  Les variables finales envoyées au Mode06 (FacMes, FacMax)  */
/*                 sont gelées lorsque la panne est présente mais non encore  */
/*                 confirmée par le GD/GAR.                                   */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_08083_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SenO2Us_PerDiag_FacMesRaw;                                   */
/*  input uint16 SenO2Us_PerDiag_FacMaxRaw;                                   */
/*  input boolean SenO2Us_bDgoORng_OxySensPerd;                               */
/*  input uint16 SenO2Us_PerDiag_FacMes_Obd6Mod;                              */
/*  input uint16 SenO2Us_PerDiag_FacMax_Obd6Mod;                              */
/*  input boolean SenO2Us_bInhMonWait_PerDiag_C;                              */
/*  input boolean SenO2Us_bMonRunRaw_OxySensPerd;                             */
/*  input boolean SenO2Us_bMonWaitRaw_OxySensPerd;                            */
/*  output uint16 SenO2Us_PerDiag_FacMes_Obd6Mod;                             */
/*  output uint16 SenO2Us_PerDiag_FacMax_Obd6Mod;                             */
/*  output boolean SenO2Us_bMonWaitORng_OxySensPerd;                          */
/*  output boolean SenO2Us_bMonRunORng_OxySensPerd;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidPerDgSens(void)
{
   /* 11_PerDiag_Sens */
   boolean bLocalCfmSenO2UsPerDiag;
   uint16  u16LocalSnO2Us_PrDg_FcMs_Obd6Md;
   uint16  u16LocalSnO2Us_PrDg_FcMx_Obd6Md;

   bLocalCfmSenO2UsPerDiag = GDGAR_bGetFRM(FRM_FRM_CFMSENO2USPERDIAG);
   if (bLocalCfmSenO2UsPerDiag != 0)
   {
      u16LocalSnO2Us_PrDg_FcMs_Obd6Md = SenO2Us_PerDiag_FacMesRaw;
      u16LocalSnO2Us_PrDg_FcMx_Obd6Md = SenO2Us_PerDiag_FacMaxRaw;
   }
   else
   {
      if (SenO2Us_bDgoORng_OxySensPerd != 0)
      {
         VEMS_vidGET(SenO2Us_PerDiag_FacMes_Obd6Mod,
                     u16LocalSnO2Us_PrDg_FcMs_Obd6Md);
         VEMS_vidGET(SenO2Us_PerDiag_FacMax_Obd6Mod,
                     u16LocalSnO2Us_PrDg_FcMx_Obd6Md);
      }
      else
      {
         u16LocalSnO2Us_PrDg_FcMs_Obd6Md = SenO2Us_PerDiag_FacMesRaw;
         u16LocalSnO2Us_PrDg_FcMx_Obd6Md = SenO2Us_PerDiag_FacMaxRaw;
      }
   }
   VEMS_vidSET(SenO2Us_PerDiag_FacMes_Obd6Mod, u16LocalSnO2Us_PrDg_FcMs_Obd6Md);
   VEMS_vidSET(SenO2Us_PerDiag_FacMax_Obd6Mod, u16LocalSnO2Us_PrDg_FcMx_Obd6Md);

   if (SenO2Us_bInhMonWait_PerDiag_C != 0)
   {
      SenO2Us_bMonWaitORng_OxySensPerd = DIAG_DISPO;
      if (  (SenO2Us_bMonRunRaw_OxySensPerd != 0)
         && (SenO2Us_bMonWaitRaw_OxySensPerd == 0))
      {
         SenO2Us_bMonRunORng_OxySensPerd = 1;
      }
      else
      {
         SenO2Us_bMonRunORng_OxySensPerd = 0;
      }
   }
   else
   {
      SenO2Us_bMonWaitORng_OxySensPerd = SenO2Us_bMonWaitRaw_OxySensPerd;
      SenO2Us_bMonRunORng_OxySensPerd = SenO2Us_bMonRunRaw_OxySensPerd;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidPerDgApv                            */
/* !Description :  Les variables accompagnant l’information panne (bMonRun,   */
/*                 bMonWait) sont redéfinies afin d’intégrér l’ensemble de la */
/*                 fonctionnalité dans le seul flux                           */
/*                 SenO2Us_bMonRunORng_OxyApvPerd.                            */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SenO2Us_bInhMonWait_PerDiag_C;                              */
/*  input boolean SenO2Us_bMonRunRaw_OxyApvPerd;                              */
/*  input boolean SenO2Us_bMonWaitRaw_OxyApvPerd;                             */
/*  output boolean SenO2Us_bMonWaitORng_OxyApvPerd;                           */
/*  output boolean SenO2Us_bMonRunORng_OxyApvPerd;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidPerDgApv(void)
{
   /* 12_PerDiag_Apv */
   if (SenO2Us_bInhMonWait_PerDiag_C != 0)
   {
      SenO2Us_bMonWaitORng_OxyApvPerd = DIAG_DISPO;
      if (  (SenO2Us_bMonRunRaw_OxyApvPerd != 0)
         && (SenO2Us_bMonWaitRaw_OxyApvPerd == 0))
      {
         SenO2Us_bMonRunORng_OxyApvPerd = 1;
      }
      else
      {
         SenO2Us_bMonRunORng_OxyApvPerd = 0;
      }
   }
   else
   {
      SenO2Us_bMonWaitORng_OxyApvPerd = SenO2Us_bMonWaitRaw_OxyApvPerd;
      SenO2Us_bMonRunORng_OxyApvPerd = SenO2Us_bMonRunRaw_OxyApvPerd;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidcallGDU                             */
/* !Description :  Les appels au GDU se font sur front montant des bMonRun.   */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/*  argin boolean bMonRun, argin boolean Ns_bMonWait);                        */
/*  input boolean SenO2Us_bMonRunORng_OxySensPerd;                            */
/*  input boolean HEATSENO2UPPERDDIAG_bOxySensPrev;                           */
/*  input boolean SenO2Us_bDgoORng_OxySensPerd;                               */
/*  input boolean SenO2Us_bMonWaitORng_OxySensPerd;                           */
/*  input boolean SenO2Us_bMonRunORng_OxyApvPerd;                             */
/*  input boolean HEATSENO2UPPERDDIAG_bOxyApvPrev;                            */
/*  input boolean SenO2Us_bDgoORng_OxyApvPerd;                                */
/*  input boolean SenO2Us_bMonWaitORng_OxyApvPerd;                            */
/*  output boolean HEATSENO2UPPERDDIAG_bOxySensPrev;                          */
/*  output boolean HEATSENO2UPPERDDIAG_bOxyApvPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidcallGDU(void)
{
   /* 13_OxyPerd_diag_Call_Mng */
   if (  (SenO2Us_bMonRunORng_OxySensPerd != 0)
      && (HEATSENO2UPPERDDIAG_bOxySensPrev == 0))
   {
      GDGAR_vidGdu(GD_DFT_ORNG_OXYSENSPERD,
                   SenO2Us_bDgoORng_OxySensPerd,
                   SenO2Us_bMonRunORng_OxySensPerd,
                   SenO2Us_bMonWaitORng_OxySensPerd);
   }

   if (  (SenO2Us_bMonRunORng_OxyApvPerd != 0)
      && (HEATSENO2UPPERDDIAG_bOxyApvPrev == 0))
   {
      GDGAR_vidGdu(GD_DFT_ORNG_OXYAPVPERD,
                   SenO2Us_bDgoORng_OxyApvPerd,
                   SenO2Us_bMonRunORng_OxyApvPerd,
                   SenO2Us_bMonWaitORng_OxyApvPerd);
   }

   HEATSENO2UPPERDDIAG_bOxySensPrev = SenO2Us_bMonRunORng_OxySensPerd;
   HEATSENO2UPPERDDIAG_bOxyApvPrev = SenO2Us_bMonRunORng_OxyApvPerd;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCrPrdLean                           */
/* !Description :  Cette fonction fait le bilan des pannes  présentes         */
/*                 concernant la période pauvre                               */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lambda_slow_mode;                                           */
/*  input uint16 Dnstr_modifier_time_scale;                                   */
/*  input boolean Manu_inh_correction_perdiag;                                */
/*  input uint16 Oxy_ups_tempo_lean;                                          */
/*  input uint16 Dnstr_modifier_temp;                                         */
/*  output uint16 Oxy_ups_period_lean;                                        */
/*  output uint16 Oxy_ups_tempo_lean;                                         */
/*  output uint16 Dnstr_modifier_temp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCrPrdLean(void)
{
   boolean bLocalLambda_slow_mode;
   uint16  u16LocalDnstrmodifiertime_scale;
   sint32  s32Localsubstractresult;


   VEMS_vidGET(Lambda_slow_mode , bLocalLambda_slow_mode );
   VEMS_vidGET(Dnstr_modifier_time_scale , u16LocalDnstrmodifiertime_scale);

   if (Manu_inh_correction_perdiag != 0)
   {
      Oxy_ups_period_lean = (uint16)MATHSRV_udtMIN(Oxy_ups_tempo_lean, 26214);
   }
   else
   {
      s32Localsubstractresult = (sint32)( Oxy_ups_tempo_lean
                                        - Dnstr_modifier_temp);
      Oxy_ups_period_lean = (uint16)MATHSRV_udtCLAMP(s32Localsubstractresult,
                                                     0,
                                                     26214);
   }
   Oxy_ups_tempo_lean = 0;

   if (bLocalLambda_slow_mode != 0)
   {
      Dnstr_modifier_temp = u16LocalDnstrmodifiertime_scale;
   }
   else
   {
      Dnstr_modifier_temp = 0;
   }
}
/*------------------------------- end of file --------------------------------*/
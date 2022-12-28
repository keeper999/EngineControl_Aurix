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
/* !File            : HEATSENO2UPPERDDIAG_FCT2.C                              */
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
/*   1 / HEATSENO2UPPERDDIAG_vidCalcPerdL                                     */
/*   2 / HEATSENO2UPPERDDIAG_vidCompPerL                                      */
/*   3 / HEATSENO2UPPERDDIAG_vidCtThdsnsL                                     */
/*   4 / HEATSENO2UPPERDDIAG_vidCtThdApvL                                     */
/*   5 / HEATSENO2UPPERDDIAG_vidOsPFaultL                                     */
/*   6 / HEATSENO2UPPERDDIAG_vidRepOsPFlL                                     */
/*   7 / HEATSENO2UPPERDDIAG_vidsnsPTest                                      */
/*   8 / HEATSENO2UPPERDDIAG_vidReIntPer                                      */
/*   9 / HEATSENO2UPPERDDIAG_vidPerdRich                                      */
/*   10 / HEATSENO2UPPERDDIAG_vidCalcPerdR                                    */
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

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCalcPerdL                           */
/* !Description :  Afin d’anticiper l’allumage de la MIL sur défaut de période*/
/*                 du signal de la sonde à oxygène amont, un seuil            */
/*                 intermédiaire " agrément " a été ajouté                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCompPerL();                       */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCtThdsnsL();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCtThdApvL();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidOsPFaultL();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCalcPerdL(void)
{
   /* 01_calc_diag_lean_period */
   HEATSENO2UPPERDDIAG_vidCompPerL();
   HEATSENO2UPPERDDIAG_vidCtThdsnsL();
   HEATSENO2UPPERDDIAG_vidCtThdApvL();
   HEATSENO2UPPERDDIAG_vidOsPFaultL();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCompPerL                            */
/* !Description :  calcul de Oxy_ups_period                                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Oxy_ups_period;                                              */
/*  input uint8 Oxy_period_tests;                                             */
/*  input uint16 Oxy_ups_period_lean;                                         */
/*  output uint16 Oxy_ups_period;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCompPerL(void)
{
   /* 01_Compute_period */
   uint32 u32Localoutput1;
   uint32 u32Localoutput2;


   u32Localoutput1 = (uint32)( (Oxy_ups_period * Oxy_period_tests)
                             + Oxy_ups_period_lean);
   u32Localoutput2 = u32Localoutput1 / (Oxy_period_tests + 1);
   Oxy_ups_period = (uint16)MATHSRV_udtMIN(u32Localoutput2, 26214);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCtThdsnsL                           */
/* !Description :  Ici le seuil max est calculé et moyenné. De plus, si       */
/*                 l’application GPL/GNV est active, les seuils utilisés sont */
/*                 spécifiques à cette application.                           */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Engine_load;                                                 */
/*  input uint8 Cat_old_gain_obd;                                             */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Regime_moteur_2_bkpt_map[9];                                  */
/*  input uint16 Engine_load_2_bkpt_map[9];                                   */
/*  input uint16 Max_oxy_sens_period_gas_map[9][9];                           */
/*  input uint16 Max_oxy_sens_period_emis_gas_map[9][9];                      */
/*  input uint16 Max_oxy_sens_period_map[9][9];                               */
/*  input uint16 Max_oxy_sens_period_emis_map[9][9];                          */
/*  input uint16 Oxy_sens_period_map_max;                                     */
/*  input uint8 Oxy_period_tests;                                             */
/*  input uint16 Max_oxy_sens_period_l;                                       */
/*  output uint16 Max_oxy_sens_period_l;                                      */
/*  output uint16 Oxy_sens_period_map_max;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCtThdsnsL(void)
{
   /* 02a_Compute_Thd_sens */
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalExt_stSysGas;
   uint8  u8LocalCat_old_gain_obd;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalEngine_load;
   uint16 u16LocalMaxSensPerLMap1;
   uint16 u16LocalMaxSensPerLMap2;
   uint16 u16LocalMaxOxySensPeriodl;
   uint32 u32Localoutput1;
   uint32 u32Localoutput2;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Engine_load, u16LocalEngine_load);
   VEMS_vidGET(Cat_old_gain_obd, u8LocalCat_old_gain_obd);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_2_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               9);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(Engine_load_2_bkpt_map,
                                                u16LocalEngine_load,
                                                9);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalMaxSensPerLMap1 =
         MATHSRV_u16Interp2d(&Max_oxy_sens_period_gas_map[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             9);
      u16LocalMaxSensPerLMap2 =
         MATHSRV_u16Interp2d(&Max_oxy_sens_period_emis_gas_map[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             9);
   }
   else
   {
      u16LocalMaxSensPerLMap1 =
         MATHSRV_u16Interp2d(&Max_oxy_sens_period_map[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             9);
      u16LocalMaxSensPerLMap2 =
         MATHSRV_u16Interp2d(&Max_oxy_sens_period_emis_map[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             9);
   }

   u16LocalMaxOxySensPeriodl = (uint16)( ( ( u16LocalMaxSensPerLMap1
                                           * u8LocalCat_old_gain_obd)
                                         + ( (256 - u8LocalCat_old_gain_obd)
                                           * u16LocalMaxSensPerLMap2)) / 256);

   Max_oxy_sens_period_l = (uint16)MATHSRV_udtMIN(u16LocalMaxOxySensPeriodl,
                                                  26214);

   u32Localoutput1 = (uint32)(Oxy_sens_period_map_max * Oxy_period_tests)
                     + Max_oxy_sens_period_l;
   u32Localoutput2 = u32Localoutput1 / (Oxy_period_tests + 1);
   Oxy_sens_period_map_max = (uint16)MATHSRV_udtMIN(u32Localoutput2, 26214);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCtThdApvL                           */
/* !Description :  Ici le seuil max apv est calculé et moyenné. De plus, si   */
/*                 l’application GPL/GNV est active, les seuils utilisés sont */
/*                 spécifiques à cette application.                           */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Engine_load;                                                 */
/*  input uint8 Regime_moteur_2_bkpt_map[9];                                  */
/*  input uint16 Engine_load_2_bkpt_map[9];                                   */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Max_oxy_apv_period_gas_map[9][9];                            */
/*  input uint16 Max_oxy_apv_period_map[9][9];                                */
/*  input uint16 Oxy_apv_period_map_max;                                      */
/*  input uint8 Oxy_period_tests;                                             */
/*  input uint16 Max_oxy_apv_period_l;                                        */
/*  output uint16 Max_oxy_apv_period_l;                                       */
/*  output uint16 Oxy_apv_period_map_max;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCtThdApvL(void)
{
   /* 02b_Compute_Thd_Apv_ */
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalEngine_load;
   uint16 u16LocalMaxApvPerL;
   uint32 u32Localoutput1;
   uint32 u32Localoutput2;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Engine_load, u16LocalEngine_load);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_2_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               9);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(Engine_load_2_bkpt_map,
                                                u16LocalEngine_load,
                                                9);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalMaxApvPerL =
         MATHSRV_u16Interp2d(&Max_oxy_apv_period_gas_map[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             9);
   }
   else
   {
      u16LocalMaxApvPerL = MATHSRV_u16Interp2d(&Max_oxy_apv_period_map[0][0],
                                               u16LocalParaX,
                                               u16LocalParaY,
                                               9);
   }

   Max_oxy_apv_period_l = (uint16)MATHSRV_udtMIN(u16LocalMaxApvPerL, 26214);

   u32Localoutput1 = (uint32)(Oxy_apv_period_map_max * Oxy_period_tests)
                     + Max_oxy_apv_period_l;
   u32Localoutput2 = u32Localoutput1 / (Oxy_period_tests + 1);
   Oxy_apv_period_map_max = (uint16)MATHSRV_udtMIN(u32Localoutput2, 26214);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidOsPFaultL                           */
/* !Description :  Reporter la période fausse de la sonde pauvre à l'OS       */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPPERDDIAG_vidRepOsPFlL();                      */
/*  input uint8 Oxy_period_tests;                                             */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Oxy_sens_diag_sample_size_gas_c;                              */
/*  input uint8 Oxy_sens_diag_sample_size_c;                                  */
/*  output uint8 Oxy_period_tests;                                            */
/*  output boolean SenO2Us_bMonRunRaw_OxySensPerd;                            */
/*  output boolean SenO2Us_bMonRunRaw_OxyApvPerd;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidOsPFaultL(void)
{
   /* 03_Report_os_period_fault_l */
   uint8  u8LocalExt_stSysGas;
   uint8  u8LocalOxySensDiagSampleSize;


   if (Oxy_period_tests < 255)
   {
      Oxy_period_tests = (uint8)(Oxy_period_tests + 1);
   }
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u8LocalOxySensDiagSampleSize = Oxy_sens_diag_sample_size_gas_c;
   }
   else
   {
      u8LocalOxySensDiagSampleSize = Oxy_sens_diag_sample_size_c;
   }

   if (Oxy_period_tests >= u8LocalOxySensDiagSampleSize)
   {
      SenO2Us_bMonRunRaw_OxySensPerd = 1;
      SenO2Us_bMonRunRaw_OxyApvPerd = 1;
      HEATSENO2UPPERDDIAG_vidRepOsPFlL();
   }
   else
   {
      SenO2Us_bMonRunRaw_OxySensPerd = 0;
      SenO2Us_bMonRunRaw_OxyApvPerd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidRepOsPFlL                           */
/* !Description :  Calculer la période fausse de la sonde pauvre              */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2UPPERDDIAG_vidsnsPTest();                       */
/*  extf argret void HEATSENO2UPPERDDIAG_vidReIntPer();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidRepOsPFlL(void)
{
   /* 01_Report_os_period_fault_l */
   HEATSENO2UPPERDDIAG_vidsnsPTest();
   HEATSENO2UPPERDDIAG_vidReIntPer();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidsnsPTest                            */
/* !Description :  Une fois le nombre d’échantillon souhaité atteint, on      */
/*                 effectue la comparaison entre la moyenne des périodes et la*/
/*                 moyenne des seuils.                                        */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Oxy_ups_period;                                              */
/*  input uint16 Oxy_sens_period_map_max;                                     */
/*  input uint16 Oxy_apv_period_map_max;                                      */
/*  output boolean Oxy_sens_period_failure;                                   */
/*  output boolean Oxy_sens_period_apv_failure;                               */
/*  output uint16 SenO2Us_PerDiag_FacMesRaw;                                  */
/*  output uint16 SenO2Us_PerDiag_FacMaxRaw;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidsnsPTest(void)
{
   /* 01_sens_Period_Test */
   if (Oxy_ups_period >= Oxy_sens_period_map_max)
   {
      Oxy_sens_period_failure = 1;
   }
   else
   {
      Oxy_sens_period_failure = 0;
   }

   if (Oxy_ups_period >= Oxy_apv_period_map_max)
   {
      Oxy_sens_period_apv_failure = 1;
   }
   else
   {
      Oxy_sens_period_apv_failure = 0;
   }

   SenO2Us_PerDiag_FacMesRaw = (uint16)MATHSRV_udtMIN(Oxy_ups_period, 26214);
   SenO2Us_PerDiag_FacMaxRaw = (uint16)MATHSRV_udtMIN(Oxy_sens_period_map_max,
                                                      26214);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidReIntPer                            */
/* !Description :  calcul de Os_period_tests_done. Initialisation du          */
/*                 Oxy_period_tests.                                          */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Os_period_tests_done;                                         */
/*  output uint8 Os_period_tests_done;                                        */
/*  output uint8 Oxy_period_tests;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidReIntPer(void)
{
   /* 02_ReInit_period */
   if (Os_period_tests_done < 255)
   {
      Os_period_tests_done = (uint8)(Os_period_tests_done + 1);
   }
   Oxy_period_tests = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidPerdRich                            */
/* !Description :  Cette fonction fait le bilan des pannes présentes          */
/*                 concernant la période, les temps de réponse et le mark     */
/*                 space ratio                                                */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCorRich();                        */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCalcPerdR();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCorLean();                        */
/*  input uint16 EngM_mfTotExCor;                                             */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Enable_period_rich;                                         */
/*  input uint16 Min_oxy_sens_amfr_gas_c;                                     */
/*  input uint16 Min_oxy_sens_amfr_c;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidPerdRich(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalEngM_mfTotExCor;


   VEMS_vidGET(EngM_mfTotExCor, u16LocalEngM_mfTotExCor);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (Enable_period_rich != 0)
   {
      HEATSENO2UPPERDDIAG_vidCorRich();
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         if (u16LocalEngM_mfTotExCor >= Min_oxy_sens_amfr_gas_c)
         {
            HEATSENO2UPPERDDIAG_vidCalcPerdR();
         }
      }
      else
      {
         if (u16LocalEngM_mfTotExCor >= Min_oxy_sens_amfr_c)
         {
            HEATSENO2UPPERDDIAG_vidCalcPerdR();
         }
      }
   }
   else
   {
      HEATSENO2UPPERDDIAG_vidCorLean();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCalcPerdR                           */
/* !Description :  Afin d’anticiper l’allumage de la MIL sur défaut de période*/
/*                 du signal de la sonde à oxygène amont, un seuil            */
/*                 intermédiaire " agrément " a été ajouté                    */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCompPerR();                       */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCpThdSnsR();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCpThdApvR();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidOsPFaultR();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCalcPerdR(void)
{
   /* 01_calc_diag_rich_period */
   HEATSENO2UPPERDDIAG_vidCompPerR();
   HEATSENO2UPPERDDIAG_vidCpThdSnsR();
   HEATSENO2UPPERDDIAG_vidCpThdApvR();
   HEATSENO2UPPERDDIAG_vidOsPFaultR();
}
/*------------------------------- end of file --------------------------------*/